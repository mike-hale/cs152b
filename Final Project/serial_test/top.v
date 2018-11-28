
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
reg has_sent;
reg [7:0] out_data;
reg [4:0] img_x;
reg [4:0] img_y;
reg [1:0] byte_idx;
reg [3:0] label;

reg [31:0] img [27:0][27:0];

wire in_ready;
wire [7:0] in_data;

uart_rx rx_inst(sys_clk, rst, rx, in_ready, in_data);
uart_tx tx_inst(sys_clk, rst, start, out_data, tx, out_ready);

initial begin
  label = 'hF;
  has_sent = 0;
  byte_idx = 0;
  img_x = 0;
  img_y = 0;
  rst = 1;
  start = 0;
  out_data = "7";
end

always @(out_ready) begin
  if (out_ready == 1 && has_sent == 0) begin
    has_sent = 1;
    start = 1;
  end else if (out_ready == 1 && has_sent == 1)
    start = 0;
end
    
always @(in_ready) begin
  if (in_ready == 1) begin
    if (label == 'hF)
      label = in_data;
    else begin
      img[img_x][img_y] = (in_data << (8*byte_idx)) | img[img_x][img_y];
      if (byte_idx == 3) begin
        if (img_x == 27) begin
          img_y = img_y + 1;
          img_x = 0;
          byte_idx = 0;
        end else begin
          img_x = img_x + 1;
          byte_idx = 0;
        end
      end else
        byte_idx = byte_idx + 1;
    end
  end
end

assign Led[7:1] = in_data[7:1];

assign Led[0] = byte_idx == 3 && img_x == 27 && img_y == 27;

endmodule
