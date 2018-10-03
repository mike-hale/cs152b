`timescale 1ns / 1ps

module tb();

reg clock, rst, wren;
reg [4:0] ra, rb, rw; // Select register
reg [3:0] op;
wire [15:0] rf_a_out, rf_b_out, alu_out;
reg [15:0] rf_w_in, alu_a_in, alu_b_in;

sixteen_bit_alu uut_alu(
	alu_a_in, 
	alu_b_in, 
	op, 
	alu_out
);

register_file uut_rf(
	ra, 
	rb, 
	rw,
	wren,
	clock,
	rst,
	rf_w_in,
	rf_a_out,
	rf_b_out
);

initial begin

end

always begin
	#5 clock = ~clock
end

endmodule
