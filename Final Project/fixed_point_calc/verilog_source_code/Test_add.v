`timescale 1ns / 1ps
 
////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:35:03 06/30/2013
// Design Name:   qadd
// Module Name:   I:/Projects/xilinx/FPInterface/Tester/Tran3005/Tes_add.v
// Project Name:  Trancendental
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: qadd
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////
 
module Test_add;
 
	// Inputs
	reg [15:0] a;
	reg [15:0] b;
 
	// Outputs
	wire [15:0] c;
 
	// Instantiate the Unit Under Test (UUT)
	qadd #(7,16) uut (
		.a(a), 
		.b(b), 
		.c(c)
	);
 
	initial begin
		// Initialize Inputs
		a[30:0] = 0;
		a[31] = 0;
		b[31] = 1;
		b[30:0] = 0;
 
		// Wait 100 ns for global reset to finish
		#100;
		a[15:0] = 1;
		a[15] = 0;
		b[15] = 0;
		b[15:0] = 1;
		#1
		$display ("%b,%b,%b,", a,b,c);
		a = 16'b0000001101101011;
		b = 16'b0000001000111000;
		#1
		$display("%b", c);

		a = 16'b0000100010110000;
		b = 16'b0000000110001110;
		#1
		$display("%b",c);

		a = 16'b0000000110000000;
		b = 16'b1000000010000000;
		#1
		$display("%b",a);
		$display("%b",b);
		$display("%b",c);
		
		
	end
 
endmodule
 
 