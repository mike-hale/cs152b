`timescale 1ns / 1ps

module tb();

reg clk, walk_btn, side_sensor;
wire [2:0] main_st_light, side_st_light;
wire one_hz_clk, walk_light;


top UUT(clk, walk_btn, {7'b0,side_sensor}, {one_hz_clk,walk_light,side_st_light,main_st_light});

initial begin
  clk = 0;
  walk_btn = 0;
  side_sensor = 0;
end

always begin
  #5 clk = ~clk;
end

integer time_cnt = 0;
always @(posedge one_hz_clk) begin
	$display("TIME %d: MAIN ST(%b %b %b) SIDE ST (%b %b %b) WALK (%b)", time_cnt,
             main_st_light[0], main_st_light[1], main_st_light[2],
             side_st_light[0], side_st_light[0], side_st_light[2],
             walk_light);
    time_cnt = time_cnt + 1;
end