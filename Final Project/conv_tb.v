module conv_tb();

reg clk, out_rdy, forward, load_weights;
reg [31:0] conv_input;
reg [3:0] conv_input_idx;
reg [3:0] conv_input_x, conv_input_y;

wire [31:0] conv_output;
wire [3:0] conv_output_idx;
wire [3:0] conv_output_x, conv_output_y;
wire in_rdy;
integer x_bound, y_bound, idx_bound;

conv #(8,12,4,4,5,1,2,16) conv_inst(clk,out_rdy,forward,load_weights,conv_input,conv_input_idx,,conv_input_x,conv_input_y,
                                        in_rdy,conv_output,conv_output_idx,conv_output_x,conv_output_y);

initial begin
  x_bound = 11;
  y_bound = 11;
  idx_bound = 7;
  clk = 0;
  out_rdy = 1;
  forward = 1;
  load_weights = 0;
  conv_input = {16'b01,16'b0};
  conv_input_idx = 0;
  conv_input_x = 0;
  conv_input_y = 0;
end

always begin
    #5 clk <= ~clk;
end

always @(posedge clk) begin
    if (in_rdy == 1) begin
    if (conv_input_x == x_bound) begin
        if (conv_input_y == y_bound) begin
            if (conv_input_idx == idx_bound) begin
                conv_input_x <= 0;
                conv_input_y <= 0;
                conv_input_idx <= 0;
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
    end
    if (forward == 1 && conv_output_idx == 15 && conv_output_x == 3 && conv_output_y == 3) begin
        forward <= 0;
        x_bound = 3;
        y_bound = 3;
        idx_bound = 15;
    end 
    if (forward == 0 && conv_output_idx == 7 && conv_output_x == 11 && conv_output_y == 11) begin
        forward <= 1;
        x_bound = 11;
        y_bound = 11;
        idx_bound = 7;
    end
    $display("Input (%d,%d,%d)--Output (%d,%d,%d) %d.%d F(%b)", conv_input_x, conv_input_y, conv_input_idx,
             conv_output_x, conv_output_y, conv_output_idx, conv_output[31:16], conv_output[15:0], forward);
end

endmodule