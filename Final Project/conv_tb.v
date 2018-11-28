module conv_tb();

reg clk, out_rdy;
reg [31:0] conv_input;
reg [2:0] conv_input_idx;
reg [3:0] conv_input_x, conv_input_y;

wire [31:0] conv_output;
wire [3:0] conv_output_idx;
wire [2:0] conv_output_x, conv_output_y;
wire in_rdy;

conv #(8,12,3,4,5,1,16,8,4,3) conv_inst(clk,out_rdy,conv_input,conv_input_idx,conv_input_x,conv_input_y,
                                        in_rdy,conv_output,conv_output_idx,conv_output_x,conv_output_y);

initial begin
  clk = 0;
  out_rdy = 1;
  conv_input = {16'b01,16'b0};
  conv_input_idx = 0;
  conv_input_x = 0;
  conv_input_y = 0;
end

always begin
    #5 clk <= ~clk;
end

always @(posedge clk) begin
    if (conv_input_x == 11) begin
        if (conv_input_y == 11) begin
            if (conv_input_idx == 7) begin
                if (in_rdy == 1) begin
                    conv_input_x <= 0;
                    conv_input_y <= 0;
                    conv_input_idx <= 0;
                end
            end else begin
                conv_input_idx <= conv_input_idx + 1;
                conv_input_x <= 0;
                conv_input_y <= 0;
            end
        end else begin
            conv_input_y <= conv_input_y + 1;
            conv_input_x <= 0;
        end
    end else begin
        conv_input_x <= conv_input_x + 1;
    end
    $display("Input (%d,%d,%d)--Output (%d,%d,%d) %d", conv_input_x, conv_input_y, conv_input_idx,
             conv_output_x, conv_output_y, conv_output_idx, conv_output);
end

endmodule