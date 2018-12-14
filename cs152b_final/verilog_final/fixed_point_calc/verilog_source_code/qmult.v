`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:21:14 08/24/2011 
// Design Name: 
// Module Name:    q15_mult 
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
module qmult ();

parameter Q = 15;
parameter N = 32;

function qmult;
	 input			[N-1:0]	i_multiplicand;
	 input			[N-1:0]	i_multiplier;
	 reg			[N-1:0]	o_result;
   reg [N-2:0]		r_RetVal;
   reg [2*N-1:0]	r_result;
begin
  r_result = i_multiplicand[N-2:0] * i_multiplier[N-2:0];
  r_RetVal[N-2:0] = r_result[N-2+Q:Q];
	o_result[N-1] = (i_multiplier[N-1] ^ i_multiplicand[N-1]);
  o_result[N-2:0] = r_RetVal;
  qmult = o_result;
end
endfunction
//---------------------------------------------------------------------------------
/*	always @(i_multiplicand, i_multiplier)	begin						//	Do the multiply any time the inputs change
		r_result = i_multiplicand[N-2:0] * i_multiplier[N-2:0];	//	Removing the sign bits from the multiply - that 
																					//		would introduce *big* errors	
		ovr = 1'b0;															//	reset overflow flag to zero
		end
 
		//	This always block will throw a warning, as it uses a & b, but only acts on changes in result...
	always @(r_result) begin													//	Any time the result changes, we need to recompute the sign bit,
		r_RetVal[N-2:0] = r_result[N-2+Q:Q];								//	And we also need to push the proper N bits of result up to 
																						//		the calling entity...
		if (r_result[2*N-2:N-1+Q] > 0)										// And finally, we need to check for an overflow
			ovr = 1'b1;
		end
 */
endmodule