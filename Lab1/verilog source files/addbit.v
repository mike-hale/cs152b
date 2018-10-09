`timescale 1ns / 1ps

module addbit (
	input a,
	input b,
	input ci,
	output sum,
	output co
);

wire p = a | b;
wire g = a & b;

assign co = g | (ci & p);
assign sum = ci ^ a ^ b;

endmodule 
