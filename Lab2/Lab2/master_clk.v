`timescale 1ns / 1ps

module master_clk(
  input clk,
  output reg one_hz,
  output reg thirty_two_hz
);

reg [25:0] cnt_1;
reg [20:0] cnt_32;

initial begin
  cnt_1 <= 0;
  cnt_32 <= 0;
  one_hz <= 0;
  thirty_two_hz <= 0;
end

always @(posedge clk) begin
  cnt_1 <= cnt_1 + 1;
  cnt_32 <= cnt_32 + 1;
  if (cnt_1 == 50000000) begin
    one_hz <= ~one_hz;
    cnt_1 <= 0;
  end
  if (cnt_32 == 1562500) begin
    thirty_two_hz <= ~thirty_two_hz;
    cnt_32 <= 0;
  end
end

endmodule
