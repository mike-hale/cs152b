`timescale 1ns / 1ps

module bitwise_or(
	input [15:0] a,
	input [15:0] b,
	output [16:0] out
);

assign out = {1'b0, a | b};

endmodule