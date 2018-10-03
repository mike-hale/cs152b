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
	output [15:0] out
);

wire [15:0] inv_val, and_val, or_val, add_val, sub_val, dec_val, inc_val, asl_val, asr_val, lsl_val, lsr_val, slt_val;

arithmetic_shift_left asl_mod(a, b, asl_val);

arithmetic_shift_right asr_mod(a, b, asr_val);

logical_shift_left lsl_mod(a, b, lsl_val);

logical_shift_right lsr_mod(a, b, lsr_val);

bitwise_or bwo_mod(a, b, or_val);

bitwise_and bwa_mod(a, b, and_val);

bitwise_inv bwi_mod(a, inv_val);

//First layer:
wire [15:0] inter1[7:0];

_2to1_mux mux1a[15:0](add_val, sub_val, op[0], inter1[0])
_2to1_mux mux1a[15:0](or_val, and_val, op[0], inter1[1])
_2to1_mux mux1a[15:0](dec_val, inc_val, op[0], inter[2])
_2to1_mux mux1a[15:0](lsl_val, slt_val, op[0], inter[4])
assign inter[3] = inv_val;
assign inter[5] = lsr_val;
assign inter[6] = asl_val;
assign inter[7] = asr_val;

// Second layer:
wire [15:0] inter2[3:0];
_2to1_mux mux1a[15:0](inter1[0], inter1[1], op[1], inter2[0])
_2to1_mux mux1a[15:0](inter1[2], inter1[3], op[1], inter2[0])
_2to1_mux mux1a[15:0](inter1[4], inter1[5], op[1], inter2[0])
_2to1_mux mux1a[15:0](inter1[6], inter1[7], op[1], inter2[0])

// Third layer:
wire [15:0] inter3[1:0];
_2to1_mux mux1a[15:0](inter2[0], inter2[1], op[2], inter3[0])
_2to1_mux mux1a[15:0](inter2[2], inter2[3], op[2], inter3[1])

// Fourth layer:
_2to1_mux mux1a[15:0](inter3[0], inter3[1], op[3], out)

endmodule
