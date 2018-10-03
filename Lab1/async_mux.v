`timescale 1ns / 1ps

module _2to1_mux(in0, in1, sel, out);

input sel;

output out;
input in0;
input in1;

assign out = (in0 & !sel) | (in1 &sel);

endmodule