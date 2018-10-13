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
wire side_sensor; 
assign side_sensor = sw[0];

assign led[0] = (state == MAIN_GREEN) || (state == MAIN_GREEN_EXTRA);
assign led[1] = (state == MAIN_YELLOW);
assign led[2] = (state == SIDE_GREEN || state == SIDE_GREEN_EXTRA || state == SIDE_YELLOW || state == WALK);
assign led[3] = (state == SIDE_GREEN || state == SIDE_GREEN_EXTRA);
assign led[4] = (state == SIDE_YELLOW);
assign led[5] = (state == MAIN_GREEN || state == MAIN_GREEN_EXTRA || state == MAIN_YELLOW || state == WALK);
assign led[6] = (state == WALK);
assign led[7] = clk_1Hz;
initial begin
  state <= MAIN_GREEN;
  second_cnt <= 12;
  walk_btn <= 0;
end

always @(posedge clk_1Hz) begin
  /*

  /* Update state */
  if (second_cnt == 0) begin
    state <= next_state;
  end else begin
    second_cnt <= second_cnt - 1;
  end
  
  case(state)
    MAIN_GREEN: begin
      if(second_cnt == 0) begin
        second_cnt <= 12;
      end else if (second_cnt == 6 && side_sensor == 1) begin
        next_state <= MAIN_GREEN_EXTRA;
        second_cnt <= 0;
      end else begin
        next_state <= MAIN_YELLOW;
      end
    end
    MAIN_GREEN_EXTRA: begin
      if(second_cnt <= 0) begin
        second_cnt <= 3;
        next_state <= MAIN_YELLOW;
      end
    end
    MAIN_YELLOW: begin
      if(second_cnt <= 0) begin
        second_cnt <= 2;
      end else if(walk_btn == 1) begin 
        next_state <= WALK;
      end else begin
        next_state <= SIDE_GREEN;
      end
    end
    SIDE_GREEN: begin
      if(second_cnt <= 0) begin 
        second_cnt <= 6;
      end else if(side_sensor) begin
        next_state <= SIDE_GREEN_EXTRA;
      end else begin
        next_state <= SIDE_YELLOW;
      end
    end
    SIDE_GREEN_EXTRA: begin
      if(second_cnt <= 0) begin
        second_cnt <= 3;
      end
    end
    SIDE_YELLOW: begin 
      if(second_cnt <= 0) begin
        second_cnt <= 2;
        next_state <= MAIN_GREEN;
      end
    end
    WALK: begin
      if(second_cnt == 0) begin 
        second_cnt <= 3;
        next_state <= SIDE_GREEN;
        walk_btn <= 0;
      end
    end
    endcase
end

endmodule
