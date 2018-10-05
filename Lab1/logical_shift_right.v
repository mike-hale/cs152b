`timescale 1ns / 1ps

module logical_shift_right (
input [15:0] a,
input [15:0] b, 
output [16:0] sum
);

assign sum = {1'b0, a >> b};

endmodule