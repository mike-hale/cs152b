`timescale 1ns / 1ps

module tb();

reg clock, rst, wren;
reg [4:0] ra, rb, rw; // Select register
reg [3:0] op;
wire [15:0] rf_a_out, rf_b_out, alu_out;
reg [15:0] rf_w_in, alu_a_in, alu_b_in;

integer idx;

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
	clock = 1;
	rst = 0;
	wren = 0;
	{ra,rb,rw} = 15'b0;
	{rf_w_in,alu_a_in,alu_b_in} = 48'b0;

	$display("Test cases for the register file:");
	rf_w_in = 'h55AA;
	for (idx=0; idx<32; idx=idx+1) begin
		// Write 0x55AA to register files
		#10 rw = idx;
		wren = 1;
		#10 wren = 0;
	end
	for (idx=0; idx<16; idx=idx+1) begin
		// Read from each register and verify its contents
		#10 ra = 2*idx;
		rb = 2*idx + 1;
		#10 
		$write("Reading register %d...", ra);
		if (rf_a_out == 'h55AA) begin
			$display("Success");
		end else begin
			$display("Fail (0x%x)", rf_a_out);
		end
		$write("Reading register %d...", rb);
		if (rf_b_out == 'h55AA) begin
			$display("Success");
		end else begin
			$display("Fail (0x%x)", rf_b_out);
		end
	end
end

always begin
	#5 clock = ~clock;
end

endmodule
