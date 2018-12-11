`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:56:56 12/11/2018
// Design Name:   softmax
// Module Name:   C:/Users/CS152B/Desktop/cs152b/Final Project/softmax_test/softmax_tb.v
// Project Name:  softmax_test
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: softmax
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module softmax_tb;

	// Inputs
	reg clk;
	reg backprop_ctrl;
	reg [31:0] sf_input;
	reg [3:0] sf_input_idx;
	reg start;
	reg rst;
	reg [3:0] expected_label;

	// Outputs
	wire in_ready;
	wire out_ready;
	wire [3:0] max;
	wire max_ready;
	wire [3:0] out_idx;
	wire [31:0] out_data;
	wire [31:0] dbg;
	wire [31:0] dbg2;
	wire [31:0] dbg3;
	wire [31:0] dbg4;
  reg [31:0] count;
  reg sub;

	// Instantiate the Unit Under Test (UUT)
	softmax uut (
		.clk(clk), 
		.backprop_ctrl(backprop_ctrl), 
		.sf_input(sf_input), 
		.sf_input_idx(sf_input_idx), 
		.start(start), 
		.rst(rst), 
		.expected_label(expected_label), 
		.in_ready(in_ready), 
		.out_ready(out_ready), 
		.max(max), 
		.max_ready(max_ready), 
		.out_idx(out_idx), 
		.out_data(out_data), 
		.dbg(dbg), 
		.dbg2(dbg2), 
		.dbg3(dbg3), 
		.dbg4(dbg4)
	);


endmodule


