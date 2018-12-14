`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:41:58 12/11/2018
// Design Name:   softmax
// Module Name:   C:/Users/CS152B/Desktop/cs152b/Final Project/softmax_test/sf_tb.v
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

module sf_tb;

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
	softmax uut(
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

		initial begin
		// Initialize Inputs
		clk = 0;
		backprop_ctrl = 0;
		sf_input = 32'h00008000;
		sf_input_idx = 0;
		start = 0;
		rst = 0;
		expected_label = 0;
    count =0;
    sub = 0;
		// Wait 100 ns for global reset to finish
		#100;
  end
        

  always begin
    #1 clk = ~clk;
  end
    always @(posedge clk) begin
      rst <= 0;
      count <= count + 1;
      if (count == 500) 
        $finish;
      //Forward propagation
      if(in_ready && backprop_ctrl == 0) begin
        start<= 1;
        if(start) begin
          $display("FORWARD %d, 0x%h", sf_input_idx, sf_input);
            if (sf_input_idx < 4) begin
              sf_input_idx <= sf_input_idx + 1;
              sf_input <= sf_input + 'h8f00;
              if (sub)
                sf_input <= sf_input - 'hf0;
              start<= 0;
            end
        end
      end
      //Back Propagation
      if (out_ready == 1 && backprop_ctrl == 1) begin 
        //start <= 1;
        if(~start)
          start <= 1;
        else 
          $display("BACKPROP %d, error_out: 0x%h, latched: 0x%h, %d", out_idx, out_data, dbg[1],expected_label);
        if(out_idx == 3)
            backprop_ctrl <= 0;
        sub <= ~sub;
        sf_input_idx <= 0;
       end
    end

    always @ (posedge max_ready) begin
      $display("Max: %d", max);
      backprop_ctrl <= 1;
      start <= 0;
    end
 endmodule

