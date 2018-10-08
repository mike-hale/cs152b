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
	output ovf,
	output [15:0] debug
);

wire [16:0] inv_val, and_val, or_val, add_val, sub_val, dec_val, inc_val, asl_val, asr_val, lsl_val, lsr_val, slt_out, slt_val;
wire sub_ovf, add_ovf, inc_ovf, dec_ovf, slt_ovf, asl_ovf, asr_ovf;

// Condense ADD, SUB, INC, DEC into a single adder
wire [15:0] b_adder_inter, b_adder_input;

_2to1_mux adder_inter_mux[15:0](b, 16'b1, op[2], b_adder_inter);
_2to1_mux adder_input_mux[15:0](b_adder_inter, ~b_adder_inter, ~op[0], b_adder_input); //??: is this supposed to determine between an add and subtract?

sixteen_bit_adder_signed add_mod(a, b_adder_input, ~op[0], add_val);

//OP 0000
//sixteen_bit_subtract sub_mod(a, b, sub_val, sub_ovf);

//OP 0001
//sixteen_bit_adder_signed add_mod(a, b, 1'b0, add_val, add_ovf);

//OP 0010
bitwise_or bwo_mod(a, b, or_val);

//OP 0011
bitwise_and bwa_mod(a, b, and_val);

//OP 0100
//sixteen_bit_subtract dec_mod(a, 16'b01, dec_val, dec_ovf);

//OP 0101
//sixteen_bit_adder_signed inc_mod(a, 16'b01, 1'b0, inc_val, inc_ovf);

//OP 0110
bitwise_inv bwi_mod(a, inv_val);

//OP 1000
logical_shift_left lsl_mod(a, b, lsl_val);

//OP 1001
sixteen_bit_adder_signed slt_mod(a, ~b, 1'b0, slt_out);
assign slt_val = {15'b0, slt_out[15]};

//OP 1010
logical_shift_right lsr_mod(a, b, lsr_val);

//OP 1100
arithmetic_shift_left asl_mod(a, b, asl_val);

//OP 1110
arithmetic_shift_right asr_mod(a, b, asr_val);

//First layer:
wire [16:0] inter1[7:0];

assign inter1[0] = add_val;
_2to1_mux mux1b[16:0](or_val , and_val, op[0], inter1[1]);
assign inter1[2] = add_val;
_2to1_mux mux1d[16:0](lsl_val, slt_val, op[0], inter1[4]);
assign inter1[3] = inv_val;
assign inter1[5] = lsr_val;
assign inter1[6] = asl_val;
assign inter1[7] = asr_val;

// Second layer:
wire [16:0] inter2[3:0];
_2to1_mux mux2a[16:0](inter1[0], inter1[1], op[1], inter2[0]);
_2to1_mux mux2b[16:0](inter1[2], inter1[3], op[1], inter2[1]);
_2to1_mux mux2c[16:0](inter1[4], inter1[5], op[1], inter2[2]);
_2to1_mux mux2d[16:0](inter1[6], inter1[7], op[1], inter2[3]);

// Third layer:
wire [16:0] inter3[1:0];
_2to1_mux mux3a[16:0](inter2[0], inter2[1], op[2], inter3[0]);
_2to1_mux mux3b[16:0](inter2[2], inter2[3], op[2], inter3[1]);

// Fourth layer:
_2to1_mux mux4[16:0](inter3[0], inter3[1], op[3], {ovf,out});

endmodule
