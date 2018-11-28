
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:05:21 11/26/2018 
// Design Name: 
// Module Name:    top 
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
`include "baudgen.vh"

module top(
  input wire sys_clk,
  input wire rx,
  output wire tx,
  output [7:0] Led
);

reg rst;
wire out_ready;
reg start;
reg [7:0] out_data;

wire in_ready;
wire [7:0] in_data;

uart_rx rx_inst(sys_clk, rst, rx, in_ready, in_data);
uart_tx tx_inst(sys_clk, rst, start, out_data, tx, out_ready);

initial begin
  rst = 1;
  start = 1;
  out_data = 'h33;
end

endmodule
