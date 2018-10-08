`timescale 1ns / 1ps

module tb();

reg clock, rst, wren;
reg [4:0] ra, rb, rw; // Select register
reg [3:0] op;
wire signed [15:0] rf_a_out, rf_b_out, alu_out, debug;
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
  
  // Test reading and writing at the same time:
  rw = 5'h0;
  ra = 5'h0;
  rb = 5'h1;
  rf_w_in = 'hAA55;
  wren = 1;
  #10
  if (rf_a_out == 'hAA55 && rf_b_out == 'h55AA) begin
    $display("RF Pass simultaneous read/write");
  end else begin
    $display("RF Fail simultaneous read/write");
  end
  wren = 0;

	// Reset the contents of the register file
	#10 rst = 1;
	#10 rst = 0;

	alu_a_in = 16'd91; //poss
	alu_b_in = 16'd47; // poss
	op = 4'b0000;
	#10
	if (alu_out == 16'd44) begin
		$display("SUB Pass 1");
	end else begin
		$display("SUB Fail 1 (91 - 47 = %d)", alu_out);
	end
	
	alu_a_in = -16'd91; //neg
	alu_b_in = 16'd47; //poss
	op = 4'b0000;

	#10
	if (alu_out == -16'd138) begin
		$display("SUB Pass 2");
	end else begin
		$display("SUB Fail 2 (-91 - 47 = %d)", alu_out);
	end

	alu_a_in = -16'd91; //neg
	alu_b_in = -16'd47; //neg
	op = 4'b0000;
	#10
	if (alu_out == -16'd44) begin
		$display("SUB Pass 3");
	end else begin
		$display("SUB Fail 3 (-91 - -47 = %d)", alu_out);
	end

	alu_a_in = 16'd32767; //32,677
	alu_b_in = -16'd1;
	op = 4'b0000;
	#10
	if ( ovf == 1 ) begin
		$display("SUB Pass 4");
	end else begin
		$display("SUB Fail 4 (Poss. ovf failed. ovf = %d)", ovf);
	end

	alu_a_in = -16'd32768; //32,677
	alu_b_in = 16'd1;
	op = 4'b0000;
	#10
	if ( ovf == 1 ) begin
		$display("SUB Pass 5");
	end else begin
		$display("SUB Fail 5 (Poss. ovf failed. ovf = %d)", ovf);
	end

	// Adder tests
	alu_a_in = 16'd15; //pos
	alu_b_in = 16'd19; //pos
	op = 4'b0001;
	#10
	if (alu_out == 16'd34) begin
		$display("ADD Pass 1");
	end else begin
		$display("ADD Fail 1 (15 + 19 = %d)", alu_out);
	end

	alu_a_in = 16'd15; //pos
	alu_b_in = -16'd19; //neg
	op = 4'b0001;
	#10
	if (alu_out == -16'd4) begin
		$display("ADD Pass 2");
	end else begin
		$display("ADD Fail 2 (15 + -19 = %d)", alu_out);
	end

	alu_a_in = -16'd15; //neg
	alu_b_in = -16'd19; //neg
	op = 4'b0001;
	#10
	if (alu_out == -16'd34) begin
		$display("ADD Pass 3");
	end else begin
		$display("ADD Fail 3 (-15 + -19 = %d)", alu_out);
	end

	alu_a_in = 16'd32767; // 32,677
	alu_b_in = 16'd1;
	op = 4'b0001;
	#10
	if (ovf == 1) begin
		$display("ADD Pass 4");
	end else begin
		$display("ADD Fail 4 (Poss overflow failed. ovf = %d)", ovf);
	end

	alu_a_in = -16'd32768;
	alu_b_in = -16'd1;
	op = 4'b0001;
	#10
	if (ovf == 1) begin
		$display("ADD Pass 5");
	end else begin
		$display("ADD Fail 5 (Negative overflow failed. ovf = %d)", ovf);
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

	alu_a_in = 'h00FF;
	#10
	if (alu_out == 'hAAFF) begin
		$display("OR Pass 2");
	end else begin
		$display("OR Fail 2 (0x00FF | 0xAA55 = 0x%x)", alu_out);
	end

	alu_b_in = 'h0FF0;
	#10
	if (alu_out == 'h0FFF) begin
		$display("OR Pass 3");
	end else begin
		$display("OR Fail 3 (0x00FF | 0x0FF0 = 0x%x)", alu_out);
	end

	// Bitwise AND tests
	alu_a_in = 'h55AA;
	alu_b_in = 'hAA55;
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
	alu_b_in = 'h55AA;
	#10
	if (alu_out == 'h55AA) begin
		$display("AND Pass 3");
	end else begin
		$display("AND Fail 3 (0x55AA & 0x55AA = 0x%x)", alu_out);
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
	
	alu_a_in = -'d32768; //min 16-bit int
	#10
	if (ovf == 'd1) begin
		$display("DEC Pass 3");
	end else begin
		$display("DEC Fail 3 (ovf = %d)", ovf);
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
	
	alu_a_in='h7FFF;
	#10
	if (ovf == 1) begin
		$display("INC Pass 3");
	end else begin
		$display("INC Fail 3 (ovf = %d)", ovf);
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
	alu_a_in = 'hFFFF;
	#10
	if (alu_out == 'h0000) begin
		$display("INV Pass 3");
	end else begin
		$display("INV Fail 3 (~0xFFFF = 0x%x)", alu_out);
	end

	// Logical shift left tests
	op = 4'b1000;
  alu_a_in = 'h55AA;
	alu_b_in = 'h0001;
	#10
	if (alu_out == 'hAB54) begin
		$display("LSL Pass 1");
	end else begin
		$display("LSL Fail 1 (0x55AA << 1 = 0x%x)", alu_out);
	end	

	alu_b_in = 'h0010;
	#10
	if (alu_out == 'h0000) begin
		$display("LSL Pass 2");
	end else begin
		$display("LSL Fail 2 (0x55AA << 16 = 0x%x", alu_out);
	end

	alu_b_in = 'h0000;
	#10
	if (alu_out == 'h55AA) begin
		$display("LSL Pass 3");
	end else begin
		$display("LSL Fail 3 (0x55AA << 0 = 0x%x", alu_out);
	end
	
	// Set on less than tests
	op = 4'b1001;
	alu_a_in = 16'd36;
	alu_b_in = 16'd45;
	#10
	if (alu_out == 'h0001) begin
		$display("SLT Pass 1");
	end else begin
		$display("SLT Fail 1 (36 <= 45 = %b)", alu_out);
	end
	alu_b_in = 16'd15;
	#10
	if (alu_out == 'h0000) begin
		$display("SLT Pass 2");
	end else begin
		$display("SLT Fail 2 (36 <= 15 = %b)", alu_out);
	end
	alu_a_in = 16'd32767;
	alu_b_in = -16'd2;
	#10
	if (alu_out == 'h0000) begin
		$display("SLT Pass 3");
	end else begin
		$display("SLT Fail 3 (32767 <= -2 = %b)", alu_out);
	end
	alu_a_in = -16'd10;
	alu_b_in = 16'd10;
	#10
	if (alu_out == 'h0001) begin
		$display("SLT Pass 4");
	end else begin
		$display("SLT Fail 4 (-10 <= 10 = %b)", alu_out);
	end
	alu_a_in = 16'd10;
	alu_b_in = -16'd10;
	#10
	if (alu_out == 'h0000) begin
		$display("SLT Pass 5");
	end else begin
		$display("SLT Fail 5 (10 <= -10 = %b)", alu_out);
	end
	alu_a_in = -16'd32768;
	alu_b_in = 16'd1;
	#10
	if (alu_out == 'h0001) begin
		$display("SLT Pass 6");
	end else begin
		$display("SLT Fail 6 (-32768 <= 1 = %b)", alu_out);
	end
	alu_a_in = 16'd10;
	alu_b_in = 16'd10;
	#10
	if (alu_out == 'h0001) begin
		$display("SLT Pass 7");
	end else begin
		$display("SLT Fail 7 (10 <= 10 = %b)", alu_out);
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

	alu_b_in = 'h0010;
	#10
	if (alu_out == 'h0000) begin
		$display("LSR Pass 2");
	end else begin
		$display("LSR Fail 2 (0x55AA >> 16 = 0x%x", alu_out);
	end

	alu_b_in = 'h0000;
	#10
	if (alu_out == 'h55AA) begin
		$display("LSL Pass 3");
	end else begin
		$display("LSL Fail 3 (0x55AA >> 0 = 0x%x)", alu_out);
	end
	
	// Arithmetic shift left tests
	op = 4'b1100;
	alu_b_in = 'h0001;
	#10
	if (alu_out == 'hAB54 && ovf == 1) begin
		$display("ASL Pass 1");
	end else begin
		$display("ASL Fail 1 (0x55AA <<< 1 = 0x%x)", alu_out);
	end	

  alu_a_in = 'hF000;
	alu_b_in = 'h0010;
	#10
	if (alu_out == 'h0000 && ovf == 1) begin
		$display("ASL Pass 2");
	end else begin
		$display("ASL Fail 2 (0xF000 <<< 16 = 0x%x, ovf = %x)", alu_out, ovf);
	end

  alu_a_in = 'hAA55;
	alu_b_in = 'h0000;
	#10
	if (alu_out == 'hAA55 && ovf == 0) begin
		$display("ASL Pass 3");
	end else begin
		$display("ASL Fail 3 (0x55AA <<< 0 = 0x%x", alu_out);
	end

	// Arithmetic shift right tests
	op = 4'b1110;
	alu_a_in = 'hAA55;
	alu_b_in = 'h0001;
	#10
	if (alu_out == 'hD52A && ovf == 0) begin
		$display("ASR Pass 1");
	end else begin
		$display("ASR Fail 1 (0xAA55 >>> 1 = 0x%x)", alu_out);
	end

	alu_b_in = 'h0010;
	#10
	if (alu_out == 'hFFFF && ovf == 0) begin
		$display("ASR Pass 2");
	end else begin
		$display("ASR Fail 2 (0xAA55 >>> 16 = 0x%x", alu_out);
	end

  alu_a_in = 'hAA55;
	alu_b_in = 'h0000;
	#10
	if (alu_out == 'hAA55 && ovf == 0) begin
		$display("ASR Pass 3");
	end else begin
		$display("ASR Fail 3 (0xAA55 >>> 0 = 0x%x", alu_out);
	end
	$finish;
end

always begin
	#5 clock = ~clock;
end

endmodule
