module softmax_tb();

    reg clk;
    reg backprop_ctrl, start;
    reg [31:0] in; 
    reg [2:0] in_idx;
    wire in_ready; 
    reg [31:0] out [1 : 0];
    wire out_ready;
    reg [10:0] count;
    wire [31:0] dbg[3:0];
    reg rst;
    wire [2:0] max;
    reg out_rcv;
    softmax #(5,3) uut 
    (   
        .clk(clk),
        .backprop_ctrl(backprop_ctrl),
        .sf_input(in),
        .sf_input_idx(in_idx),
        .in_ready(in_ready),
        .start(start),
        .rst(rst),
        //.sf_output(out),
        .max(max),
        .out_ready(out_ready),
        .out_received(out_rcv),
        .dbg(dbg[0]),
        .dbg2(dbg[1]),
        .dbg3(dbg[2]),
        .dbg4(dbg[3])
    );

    reg init; 

    initial begin
        clk <= 0; 
        backprop_ctrl <= 0;
        in <= 32'h00000000;
        in_idx <= 0;
        count <= 0;
        start <=0;
        rst <= 1;
        init <= 0;
    end

    always begin
        #1 clk = ~clk;

    end
    reg sub;
    always @(posedge clk) begin
        $display("arr[%d]=%h ---- %h %h, %h, %h, %d, %d", in_idx, in, dbg[0], dbg[1], dbg[2], dbg[3], out_ready, max);
        rst <= 0;
        count <= count + 1;
        if (count == 255) 
            $finish;
        if(in_ready == 1) begin
            out_rcv <= 0;
            start <= 1;
            if(in_idx <5) begin
                in_idx <= in_idx + 1;
                if(sub)
                    in<= in- 32'h0000000f;
                else
                    in <= in + 32'h000000f0;
            end
        end else begin
            start <= 0;
        end 
        if (out_ready == 1) begin
            out_rcv <= 1;
            in_idx <= 0;
            sub <= 1;
        end
    end
endmodule