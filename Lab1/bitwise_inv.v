`timescale 1ns / 1ps

module bitwise_inv(
	input [15:0] a,
	output wire [15:0] out
);

assign out = ~a;

endmodule