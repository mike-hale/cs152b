`timescale 1ns / 1ps

module arithmetic_shift_left (
input [15:0] a,
input [15:0] b, 
output [16:0] out
);

wire [15:0] sum;
assign sum = a <<< b;
assign overflow = sum[15] ^ a[15];

assign out = {overflow,sum};

endmodule