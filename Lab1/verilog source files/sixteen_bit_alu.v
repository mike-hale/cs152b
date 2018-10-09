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

// Condense ADD, SUB, INC, DEC into a single adder (SUB=0000,ADD=0001,DEC=0100,INC=0101)
wire [15:0] b_or_one, b_adder_input;

mux adder_inter_mux[15:0](b, 16'b1, op[2], b_or_one); //Mux determines whether to take input b or just constant 1
mux adder_input_mux[15:0](b_or_one, ~b_or_one, ~op[0], b_adder_input); //Mux determines whether to add or subtract (by inverting b)

// Shared adder module (note: carry in 1 if this is a subtract, hence '~op[0]')
sixteen_bit_adder_signed add_mod(a, b_adder_input, ~op[0], add_val);
	
//OP 0010
bitwise_or bwo_mod(a, b, or_val);

//OP 0011
bitwise_and bwa_mod(a, b, and_val);

//OP 0110
bitwise_inv bwi_mod(a, inv_val);

//OP 1000
logical_shift_left lsl_mod(a, b, lsl_val);

//OP 1001 set on less than or equal
// note: don't carry in 1 here since we essentially compare a - b - 1 < 0
sixteen_bit_adder_signed slt_mod(a, ~b, 1'b0, slt_out);
//SLT = overflow bit XOR sign bit
assign slt_val = {16'b0, slt_out[15] ^ slt_out[16]};

//OP 1010
logical_shift_right lsr_mod(a, b, lsr_val);

//OP 1100
arithmetic_shift_left asl_mod(a, b, asl_val);

//OP 1110
arithmetic_shift_right asr_mod(a, b, asr_val);

//First layer of output muxes:
wire [16:0] first_to_second[7:0];

assign first_to_second[0] = add_val;
mux mux1a[16:0](or_val , and_val, op[0], first_to_second[1]);
assign first_to_second[2] = add_val;
mux mux1b[16:0](lsl_val, slt_val, op[0], first_to_second[4]);
assign first_to_second[3] = inv_val;
assign first_to_second[5] = lsr_val;
assign first_to_second[6] = asl_val;
assign first_to_second[7] = asr_val;

// Second layer:
wire [16:0] second_to_third[3:0];

mux mux2a[16:0](first_to_second[0], first_to_second[1], op[1], second_to_third[0]);
mux mux2b[16:0](first_to_second[2], first_to_second[3], op[1], second_to_third[1]);
mux mux2c[16:0](first_to_second[4], first_to_second[5], op[1], second_to_third[2]);
mux mux2d[16:0](first_to_second[6], first_to_second[7], op[1], second_to_third[3]);

// Third layer:
wire [16:0] third_to_last[1:0];

mux mux3a[16:0](second_to_third[0], second_to_third[1], op[2], third_to_last[0]);
mux mux3b[16:0](second_to_third[2], second_to_third[3], op[2], third_to_last[1]);

// Fourth layer:
mux mux4[16:0](third_to_last[0], third_to_last[1], op[3], {ovf,out});

endmodule
