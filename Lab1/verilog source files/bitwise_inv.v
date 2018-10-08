`timescale 1ns / 1ps

module bitwise_inv(
	input [15:0] a,
	output wire [16:0] out
);

assign out = {1'b0,~a};

endmodule