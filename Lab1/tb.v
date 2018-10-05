`timescale 1ns / 1ps

module tb();

reg clock, rst, wren;
reg [4:0] ra, rb, rw; // Select register
reg [3:0] op;
wire [15:0] rf_a_out, rf_b_out, alu_out, debug;
reg [15:0] rf_w_in, alu_a_in, alu_b_in;
wire ovf;

integer idx;

sixteen_bit_alu uut_alu(
	alu_a_in, 
	alu_b_in, 
	op, 
	alu_out,
	ovf,
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
	
	// Subtract tests
	alu_a_in = 16'd91;
	alu_b_in = 16'd47;
	op = 4'b0000;
	#10
	if (alu_out == 16'd44) begin
		$display("SUB Pass 1");
	end else begin
		$display("SUB Fail 1 (91 - 47 = %d)", alu_out);
	end
	
	// Adder tests
	alu_a_in = 16'd15;
	alu_b_in = 16'd19;
	op = 4'b0001;
	#10
	if (alu_out == 16'd34) begin
		$display("ADD Pass 1");
	end else begin
		$display("ADD Fail 1 (15 + 19 = %d)", alu_out);
	end
	
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
	
	// DEC tests
	op = 4'b0100;
	alu_a_in = 'h55AA;
	#10
	if (alu_out == 'h55A9) begin
		$display("DEC Pass 1");
	end else begin
		$display("DEC Fail 1 (0x55AA-- = 0x%x)", alu_out);
	end
	alu_a_in = 'h0000;
	#10
	if (alu_out == 'hFFFF) begin
		$display("DEC Pass 2");
	end else begin
		$display("DEC Fail 2 (0xFFFF-- = 0x%x)", alu_out);
	end
	
	// INC tests
	op = 4'b0101;
	alu_a_in = 'h55AA;
	#10
	if (alu_out == 'h55AB) begin
		$display("INC Pass 1");
	end else begin
		$display("INC Fail 1 (0x55AA++ = 0x%x)", alu_out);
	end
	alu_a_in = 'hFFFF;
	#10
	if (alu_out == 'h0000) begin
		$display("INC Pass 2");
	end else begin
		$display("INC Fail 2 (0xFFFF++ = 0x%x)", alu_out);
	end
	
	// Bitwise inverse tests
	op = 4'b0110;
	alu_a_in = 'h0000;
	#10
	if (alu_out == 'hFFFF) begin
		$display("INV Pass 1");
	end else begin
		$display("INV Fail 1 (~0x0000 = 0x%x)", alu_out);
	end
	alu_a_in = 'h55AA;
	#10
	if (alu_out == 'hAA55) begin
		$display("INV Pass 2");
	end else begin
		$display("INV Fail 2 (~0x55AA = 0x%x)", alu_out);
	end
	
	// Logical shift left tests
	op = 4'b1000;
	alu_b_in = 'h0001;
	#10
	if (alu_out == 'hAB54) begin
		$display("LSL Pass 1");
	end else begin
		$display("LSL Fail 1 (0x55AA << 1 = 0x%x)", alu_out);
	end	
	
	// Set on less than tests
	op = 4'b1001;
	alu_a_in = 16'd36;
	alu_b_in = 16'd45;
	#10
	if (alu_out == 'h0001) begin
		$display("SLT Pass 1");
	end else begin
		$display("SLT Fail 1 (36 < 45 = %b)", alu_out);
	end
	alu_b_in = 16'd15;
	#10
	if (alu_out == 'h0000) begin
		$display("SLT Pass 1");
	end else begin
		$display("SLT Fail 1 (36 < 15 = %b)", alu_out);
	end
	
	// Logical shift right tests
	op = 4'b1010;
	alu_a_in = 'h55AA;
	alu_b_in = 'h0001;
	#10
	if (alu_out == 'h2AD5) begin
		$display("LSR Pass 1");
	end else begin
		$display("LSR Fail 1 (0x55AA >> 1 = 0x%x)", alu_out);
	end	
	
	// Arithmetic shift left tests
	op = 4'b1100;
	#10
	if (alu_out == 'hAB54) begin
		$display("ASL Pass 1");
	end else begin
		$display("ASL Fail 1 (0x55AA <<< 1 = 0x%x)", alu_out);
	end	
	
	// Arithmetic shift right tests
	op = 4'b1110;
	alu_a_in = 'hAA55;
	#10
	if (alu_out == 'hD52A) begin
		$display("ASR Pass 1");
	end else begin
		$display("ASR Fail 1 (0xAA55 >>> 1 = 0x%x)", alu_out);
	end
	$finish;
end

always begin
	#5 clock = ~clock;
end

endmodule
