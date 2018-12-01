module fc_tb();

reg clk, forward, load_weights, out_rdy;
reg [31:0] fc_input;
reg [9:0] fc_in_idx;

wire in_rdy;
wire [31:0] fc_output;
wire [9:0] fc_out_idx;
integer bound;

fc #(1024,10,10) fc_layer(clk, out_rdy, forward, load_weights, fc_input, fc_in_idx,, in_rdy, fc_output, fc_out_idx);

initial begin
  clk = 0;
  out_rdy = 1;
  forward = 1;
  load_weights = 0;
  fc_input = {16'b01,16'b0};
  fc_in_idx = 0;
  bound = 1023;
end

always begin
  #5 clk <= ~clk;
end

always @(posedge clk) begin
  if (in_rdy == 1) begin
    if (fc_in_idx == bound)
      fc_in_idx <= 0;
    else
      fc_in_idx <= fc_in_idx + 1;
  end
  if (forward == 1 && fc_out_idx == 9) begin
    forward <= 0;
    bound = 9;
  end
  if (forward == 0 && fc_out_idx == 1023) begin
    forward <= 1;
    bound = 1023;
  end
  $display("in_idx (%d), o_idx (%d), o_val (%d.%d)", fc_in_idx, fc_out_idx, fc_output[31:16], fc_output[15:0]*(100000.0 / 65535));
end

endmodule