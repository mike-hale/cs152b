`timescale 1ns / 1ps

module addbit (
	input a,
	input b,
	input ci,
	output sum,
	output co
);

assign prop = a ^ b;
assign gen = a & b;

assign co = (prop & ci) || gen;
assign sum = ci ^ a ^ b;

endmodule 
