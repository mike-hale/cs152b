
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
reg [31:0] val;
reg [29:0] cnt;

wire in_ready;
wire [7:0] in_data;

uart_rx rx_inst(sys_clk, rst, rx, in_ready, in_data);
uart_tx tx_inst(sys_clk, rst, start, out_data, tx, out_ready);

initial begin
  label = 'hF;
  img_x = 0;
  img_y = 0;
  rst = 1;
  start = 0;
  out_data = "7";
  has_sent = 0;
  cnt = 0;
end

always @(posedge sys_clk) begin
  if (cnt < 100000000)
    cnt <= cnt + 1;
  else if (start == 1)
    cnt <= 0;
end

always @(out_ready, cnt) begin
  if (out_ready == 1 && cnt == 100000000) begin 
    start = 1;
  end else if (out_ready == 1) begin
    0 = 0;
  end
end
    
always @(in_ready) begin
  if (in_ready == 1) begin
    if (label == 'hF)
      label = in_data;
    else begin
      val[31] = ~in_data[7];
      val[30:15] = 16'b0;
      val[14:8] = (in_data[7] == 1) ? in_data[6:0] : ~in_data[6:0];
      val[7:0] = 8'b0;
      img[img_x][img_y] <= val; 
      if (img_y == 27) begin
        img_x = img_x + 1;
        img_y = 0;
      end else begin
        img_y = img_y + 1;
      end
    end
  end
end

assign Led[7:4] = in_data[7:4];

assign Led[3] = (cnt < 50000000);
assign Led[2] = out_ready;
assign Led[1] = in_ready;
assign Led[0] = img_x == 27 && img_y == 27;

endmodule
