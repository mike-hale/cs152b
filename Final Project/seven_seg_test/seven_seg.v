`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:35:15 11/09/2018 
// Design Name: 
// Module Name:    seven_seg 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module seven_seg(
input clk,
input [3:0] digit,
output reg [6:0] led,
output reg cat
    );

reg [20:0] cnt_32;
reg thirty_two_hz;

initial begin
  cnt_32 <= 0;
  thirty_two_hz <= 0;
end

always @(posedge clk) begin
  cnt_32 <= cnt_32 + 1;
  if (cnt_32 == 156200) begin
    thirty_two_hz <= ~thirty_two_hz;
    cnt_32 <= 0;
  end
end

always @(thirty_two_hz) begin
  case (digit [3:0])
      0: led <= 7'b1111110;
      1: led <= 7'b0110000;
      2: led <= 7'b1101101;
      3: led <= 7'b1111001;
      4: led <= 7'b0110011;
      5: led <= 7'b1011011;
      6: led <= 7'b1011111;
      7: led <= 7'b1110000;
      8: led <= 7'b1111111;
      9: led <= 7'b1110011;
      default: led <= 7'b0000000;
  endcase
end

always @(thirty_two_hz) begin
  cat <= 0;
end

endmodule
