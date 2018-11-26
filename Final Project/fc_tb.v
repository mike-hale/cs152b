module fc_tb();

reg clk;
reg [31:0] fc_input;
reg [9:0] fc_in_idx;

wire [31:0] fc_output;
wire [3:0] fc_out_idx;

fc #(1024,10,10,4) fc_layer(clk, fc_input, fc_in_idx, fc_output, fc_out_idx);

initial begin
  clk = 0;
  fc_input = {16'b01,16'b0};
  fc_in_idx = 0;
end

always begin
  #5 clk <= ~clk;
end

always @(posedge clk) begin
    fc_in_idx <= fc_in_idx + 1;
    $display("in_idx (%d), o_idx (%d), o_val (%d.%d)", fc_in_idx, fc_out_idx, fc_output[31:16], fc_output[15:0]);
end

endmodule