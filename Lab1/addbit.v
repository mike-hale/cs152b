`timescale 1ns / 1ps

module addbit (a, b, ci, sum, co);

input a;
input b;
input ci;
output sum;
output co;
//Port Data types
wire a;
wire b;
wire ci;
wire sum;
wire co;

assign wire prop = a ^ b;
assign wire gen = a & b;

assign co = (prop & ci) || gen;
assign sum = cin ^ a ^ b;

endmodule 
