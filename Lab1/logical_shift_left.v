`timescale 1ns / 1ps

module logical_shift_left (
input [15:0] a,
input [15:0] b, 
output [15:0] sum,
output zero,
output overflow);

wire [15:0] a;
wire [15:0] b;
wire [15:0] sum;
wire zero;
wire overflow;

assign sum = a << b;
assign zero = sum & 16'b0;
assign overflow = a[15] & sum[15];

endmodule