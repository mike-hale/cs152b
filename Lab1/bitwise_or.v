`timescale 1ns / 1ps

module bitwise_or(
	input [15:0] a,
	input [15:0] b,
	output wire [15:0] out
);

assign out = a | b;

endmodule