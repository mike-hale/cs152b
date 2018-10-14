module top(
  input clk,
  input btn,
  input [7:0] sw,
  output [7:0] led,
  output reg [2:0] state
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

//reg [2:0] state;

reg [3:0] second_cnt;
reg walk_request;
reg sensor_check;
reg [2:0] prev_state;
wire side_sensor = sw[0];

assign led[0] = (state == MAIN_GREEN) || (state == MAIN_GREEN_EXTRA);
assign led[1] = (state == MAIN_YELLOW);
assign led[2] = (state == SIDE_GREEN || state == SIDE_GREEN_EXTRA || state == SIDE_YELLOW || state == WALK);
assign led[3] = (state == SIDE_GREEN || state == SIDE_GREEN_EXTRA);
assign led[4] = (state == SIDE_YELLOW);
assign led[5] = (state == MAIN_GREEN || state == MAIN_GREEN_EXTRA || state == MAIN_YELLOW || state == WALK);
assign led[6] = (state == WALK);
assign led[7] = clk_1Hz;

// Start in the MAIN_GREEN state
initial begin
  state <= MAIN_GREEN;
  second_cnt <= 8;
  walk_request <= 0;
  sensor_check <= 0;
end

// Asynchronous walk request register
always @(btn_deb, state) begin
  // Want to detect the change from WALK to SIDE_GREEN
  prev_state <= state;
  if (btn_deb == 1) begin
    walk_request <= 1;
  end else if (prev_state == WALK && state == SIDE_GREEN) begin
    walk_request <= 0;
  end
end

always @(posedge clk_1Hz) begin

  /* Update state */
  if (second_cnt != 0) begin
    second_cnt <= second_cnt - 1;
  end
  
  case(state)
    MAIN_GREEN: begin
      if(second_cnt == 0) begin
		if (sensor_check == 1) begin
		    state <= MAIN_YELLOW;
			second_cnt <= 1;
		end else begin
			state <= MAIN_GREEN_EXTRA;
			second_cnt <= 2;
		end
      end else if (second_cnt == 2 && side_sensor == 1) begin
        sensor_check <= 1;
      end 
    end
    MAIN_GREEN_EXTRA: begin
      if(second_cnt == 0) begin
		state <= MAIN_YELLOW;
        second_cnt <= 1;
      end
    end
    MAIN_YELLOW: begin
      if(second_cnt == 0) begin
		if (walk_request == 1) begin
          second_cnt <= 2;
		  state <= WALK;
		end else begin
		  second_cnt <= 5;
		  state <= SIDE_GREEN;
		end
      end
    end
    SIDE_GREEN: begin
      if(second_cnt <= 0) begin 
        if (side_sensor == 1) begin
          second_cnt <= 2;
          state <= SIDE_GREEN_EXTRA;
        end else begin
          second_cnt <= 1;
          state <= SIDE_YELLOW;
        end
      end
    end
    SIDE_GREEN_EXTRA: begin
      if(second_cnt <= 0) begin
        second_cnt <= 1;
		state <= SIDE_YELLOW;
      end
    end
    SIDE_YELLOW: begin 
      if(second_cnt <= 0) begin
        second_cnt <= 8;
        state <= MAIN_GREEN;
      end
    end
    WALK: begin
      if(second_cnt == 0) begin 
        second_cnt <= 5;
        state <= SIDE_GREEN;
      end
    end
    endcase
end

endmodule
