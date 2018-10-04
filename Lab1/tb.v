`timescale 1ns / 1ps

module tb();

reg clock, rst, wren;
reg [4:0] ra, rb, rw; // Select register
reg [3:0] op;
wire [15:0] rf_a_out, rf_b_out, alu_out, debug;
reg [15:0] rf_w_in, alu_a_in, alu_b_in;

integer idx;

sixteen_bit_alu uut_alu(
	alu_a_in, 
	alu_b_in, 
	op, 
	alu_out,
	debug
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
	
	// Reset the contents of the register file
	#10 rst = 1;
	#10 rst = 0;
	
	// Adder Tests
	alu_a_in = 'd15;
	alu_b_in = 'd19;
	op = 4'b0001;
	#20
	if (alu_out == 'd34) begin
		$display("Adder Pass 1");
	end else begin
		$display("Adder Fail 1 (15 + 19 = %d)", alu_out);
	end
	#20
	
	// Bitwise OR tests
	alu_a_in = 'h55AA;
	alu_b_in = 'hAA55;
	op = 4'b0010;
	#10
	if (alu_out == 'hFFFF) begin
		$display("OR Pass 1");
	end else begin
		$display("OR Fail 1 (0x55AA | 0xAA55 = 0x%x)", alu_out);
	end

	// Bitwise AND tests
	op = 4'b0011;
	#10
	if (alu_out == 'h0000) begin
		$display("AND Pass 1");
	end else begin
		$display("AND Fail 1 (0x55AA & 0xAA55 = 0x%x)", alu_out);
	end
	alu_b_in = 'h00FF;
	#10
	if (alu_out == 'h00AA) begin
		$display("AND Pass 2");
	end else begin
		$display("AND Fail 2 (0x55AA & 0x00FF = 0x%x)", alu_out);
	end	
	
	// INC tests
	op = 4'b0100;
	#10
	if (alu_out == 'h55AB) begin
		$display("INC Pass 1");
	end else begin
		$display("INC Fail 1 (0x55AA++ = 0x%x)", alu_out);
	end
	alu_b_in = 4'hFFFF;
	#10
	if (alu_out == 'h0000) begin
		$display("INC Pass 2");
	end else begin
		$display("INC Fail 2 (0xFFFF++ = 0x%x)", alu_out);
	end
	
	$finish;
end

always begin
	#5 clock = ~clock;
end

endmodule
