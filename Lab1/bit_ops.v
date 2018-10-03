`timescale 1ns / 1ps

module bitwise_ops(
	input [15:0] a,
	input [15:0] b,
	input [1:0] op, //0 = AND, 1 = OR, 2 = invert (just a)
	output wire [15:0] out
);

wire [15:0] between_muxes;

wire or_value, and_value, inv_value;

assign or_value = a | b;
assign and_value = a & b;
assign inv_value = ~a;

_2to1_mux mux_array_a[15:0](and_value, or_value, op[0], between_muxes);

_2to1_mux mux_array_b[15:0](between_muxes, inv_value, op[1], out);

endmodule
