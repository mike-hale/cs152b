`timescale 1ns / 1ps
 
////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:36:55 06/27/2013
// Design Name:   qmult
// Module Name:   I:/Projects/xilinx/FPInterface/Tester/Tran3005/Test_mult.v
// Project Name:  Trancendental
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: qmult
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////
module Test_mult;
 
	// Inputs
	reg [15:0] i_multiplicand;
	reg [15:0] i_multiplier;
 
	// Outputs
	wire [15:0] o_result;
	wire			ovr;
 
	integer i;

	// Instantiate the Unit Under Test (UUT)
	qmult #(7,16) uut (
		.i_multiplicand(i_multiplicand), 
		.i_multiplier(i_multiplier), 
		.o_result(o_result),
		.ovr(ovr)
	);

 
	initial begin
		$display("multiplicand,multiplier,result,ovr");
		$monitor ("%b,%b,%h,%h", i_multiplicand, i_multiplier, o_result, ovr);		//	Monitor the stuff we care about
 		/*
		// Initialize Inputs
 		i_multiplicand = 32'b00000000000110010010000111111011;	//pi = 3.141592
		i_multiplicand[31] = 0;												//	i_multiplicand sign
		i_multiplier[31] = 0;												//	i_multiplier sign
		i_multiplier[30:0] = 0;
		*/

		// Initialize Inputs
 		i_multiplicand = 16'b0000000110010010;	//pi = 3.140625
		i_multiplicand[15] = 0;												//	i_multiplicand sign
		i_multiplier[15] = 0;												//	i_multiplier sign
		i_multiplier[15:0] = 0;
		// Wait 100 ns for global reset to finish
		#100;
		#100 i_multiplier[0] = 1;		//	1.91E-6
		#1;
		for (i = 0; i < 15; i++) begin
			i_multiplier = #1 i_multiplier | (1 << i);
		end

		//Negative test
		i_multiplier = 16'b1000000010011110;
		#1;
		i_multiplicand = 16'b1000000110010010;
		#2;
		i_multiplicand = 16'b0000000110010010;

		i_multiplier = 16'h0100;
		i_multiplicand = 16'h0100;

  	end
 
endmodule
 