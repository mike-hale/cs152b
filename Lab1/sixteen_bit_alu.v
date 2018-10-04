`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:58:45 10/03/2018 
// Design Name: 
// Module Name:    sixteen_bit_alu 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module sixteen_bit_alu(
	input [15:0] a,
	input [15:0] b,
	input [3:0] op,
	output [15:0] out,
	output [15:0] debug
);

wire [15:0] inv_val, and_val, or_val, add_val, sub_val, dec_val, inc_val, asl_val, asr_val, lsl_val, lsr_val, slt_val;
wire sub_ovf, add_ovf, inc_ovf, dec_ovf;

//OP 0000
sixteen_bit_subtract sub_mod(a, b, sub_val, sub_ovf);

//OP 0001
sixteen_bit_adder_signed add_mod(a, b, 1'b0, add_val, add_ovf);

//OP 0010
bitwise_or bwo_mod(a, b, or_val);

//OP 0011
bitwise_and bwa_mod(a, b, and_val);

//OP 0100
sixteen_bit_subtract dec_mod(a, 16'b01, dec_val, dec_ovf);

//OP 0101
sixteen_bit_adder_signed inc_mod(a, 16'b01, 1'b0, inc_val, inc_ovf);

//OP 0110
bitwise_inv bwi_mod(a, inv_val);

//OP 1000
logical_shift_left lsl_mod(a, b, lsl_val);

//OP 1010
logical_shift_right lsr_mod(a, b, lsr_val);

//OP 1100
arithmetic_shift_left asl_mod(a, b, asl_val);

//OP 1110
arithmetic_shift_right asr_mod(a, b, asr_val);

//First layer:
wire [15:0] inter1[7:0];

_2to1_mux mux1a[15:0](sub_val, add_val, op[0], inter1[0]);
_2to1_mux mux1b[15:0](or_val , and_val, op[0], inter1[1]);
_2to1_mux mux1c[15:0](dec_val, inc_val, op[0], inter1[2]);
_2to1_mux mux1d[15:0](lsl_val, slt_val, op[0], inter1[4]);
assign inter1[3] = inv_val;
assign inter1[5] = lsr_val;
assign inter1[6] = asl_val;
assign inter1[7] = asr_val;

// Second layer:
wire [15:0] inter2[3:0];
_2to1_mux mux2a[15:0](inter1[0], inter1[1], op[1], inter2[0]);
_2to1_mux mux2b[15:0](inter1[2], inter1[3], op[1], inter2[1]);
_2to1_mux mux2c[15:0](inter1[4], inter1[5], op[1], inter2[2]);
_2to1_mux mux2d[15:0](inter1[6], inter1[7], op[1], inter2[3]);

// Third layer:
wire [15:0] inter3[1:0];
_2to1_mux mux3a[15:0](inter2[0], inter2[1], op[2], inter3[0]);
_2to1_mux mux3b[15:0](inter2[2], inter2[3], op[2], inter3[1]);
assign debug = inter3[0];

// Fourth layer:
_2to1_mux mux4[15:0](inter3[0], inter3[1], op[3], out);

endmodule
