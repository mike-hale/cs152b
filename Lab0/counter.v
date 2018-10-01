`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:36:36 10/01/2018 
// Design Name: 
// Module Name:    counter 
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
module counter (
clock , // Clock input of the design
reset , // active high, synchronous Reset input
enable , // Active high enable signal for counter
counter_out // 4 bit vector output of the counter
); // End of port list
//-------------IO Ports-----------------------------
input clock ;
input reset ;
input enable ;
output [3:0] counter_out ;
//-------------Input ports Data Type-------------------
// By rule all the input ports should be wires
wire clock ;
wire reset ;
wire enable ;
//-------------Output Ports Data Type------------------
// Output port can be a storage element (reg) or a wire
reg [3:0] counter_out ;
reg [25:0] divider ;
// We trigger the below block
// with respect to positive edge of the clock.
always @ (posedge clock)
begin
	divider = divider + 1;
end

always @ (posedge divider[25])
begin : COUNTER // Block Name
 // At every rising edge of clock we check if reset is active
 // If active, we load the counter output with 4'b0000
 if (reset == 1'b1) begin
 counter_out <= #1 4'b0000;
 end
 // If enable is active, then we increment the counter
 else if (enable == 1'b1) begin
 counter_out <= #1000000 counter_out + 1;
 end
end // End of Block COUNTER
endmodule // End of Module counter