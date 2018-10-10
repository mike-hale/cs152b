`timescale 1ns / 1ps

module top(
  input clk,
  input btn,
  input [7:0] sw,
  output [7:0] led
);

wire clk_1Hz, clk_32Hz;
master_clk master_clock(clk, clk_1Hz, clk_32Hz);

debouncer debouncer(btn, clk_32Hz, btn_deb);

parameter MAIN_GREEN = 0;
parameter MAIN_GREEN_EXTRA = 1;
parameter MAIN_YELLOW = 2;
parameter SIDE_GREEN = 3;
parameter SIDE_GREEN_EXTRA = 4;
parameter SIDE_YELLOW = 5;
parameter WALK = 6;

reg [2:0] state;
reg [2:0] next_state;
reg [3:0] second_cnt;
reg walk_btn;

initial begin
  state <= MAIN_GREEN;
  second_cnt <= 9;
  walk_btn <= 0;
end

always @(posedge clk_1Hz) begin
  /* Update state */
  if (second_cnt == 0) begin
    state <= next_state;
  end else begin
    second_cnt <= second_cnt - 1;
  end
  
  case(state)
    MAIN_GREEN:
      if (second_cnt == 3 && walk_btn == 1) begin
        next_state <= MAIN_GREEN_EXTRA;
      end else begin
        next_state <= MAIN_YELLOW;
      end
    SIDE_GREEN:
    
end

assign led[2] = led2;

assign led[7:3] = sw[7:3];

endmodule
