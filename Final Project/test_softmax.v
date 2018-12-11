`timescale 1ns / 1ps

module softmax_tb();

    reg clk;
    reg backprop_ctrl, start;
    reg [31:0] in; 
    reg [2:0] in_idx, label;
    wire in_ready; 
    wire [31:0] out;
    wire max_ready;
    wire out_ready;
    reg [10:0] count;
    wire [31:0] dbg[3:0];
    reg rst;
    wire [2:0] max, out_idx;
    
    softmax #(4,3) uut 
    (   
        .clk(clk),
        .backprop_ctrl(backprop_ctrl),
        .sf_input(in),
        .sf_input_idx(in_idx),
        .in_ready(in_ready),
        .start(start),
        .rst(rst),
        .expected_label(label),
        .max(max),
        .max_ready(max_ready),
        .out_ready(out_ready),
        .out_idx(out_idx),
        .out_data(out),
        .dbg(dbg[0]),
        .dbg2(dbg[1]),
        .dbg3(dbg[2]),
        .dbg4(dbg[3])
    );

    reg init; 

    initial begin
        clk <= 0; 
        backprop_ctrl <= 0;
        in <= 32'h00008000;
        in_idx <= 0;
        count <= 0;
        start <=0;
        rst <= 1;
        init <= 0;
        label <= 0;
    end

    always begin
        #1 clk = ~clk;

    end
    reg sub;
    initial sub <= 0;
    always @(posedge clk) begin
        rst <= 0;
        count <= count + 1;
        if (count == 1000) 
            $finish;
        //Forward propagation
        if(in_ready && backprop_ctrl == 0) begin
            start<= 1;
            if(start) begin
                $display("FORWARD %d, 0x%h", in_idx, in);
                if (in_idx < 4) begin
                    in_idx <= in_idx + 1;
                    in <= in + 'h8f00;
                    if (sub)
                        in <= in - 'hf0;
                    start<= 0;
                end
            end
        end
        //Back Propagation
        if (out_ready == 1 && backprop_ctrl == 1) begin 
            //start <= 1;
            if(~start)
                start <= 1;
            else 
                $display("BACKPROP %d, error_out: 0x%h, latched: 0x%h, %d", out_idx, out, dbg[1],label);
            if(out_idx == 3)
                backprop_ctrl <= 0;
                sub <= ~sub;
                in_idx <= 0;
        end
    end

    always @ (posedge max_ready) begin
        $display("Max: %d", max);
        backprop_ctrl <= 1;
        start <= 0;
    end
endmodule