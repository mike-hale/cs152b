`timescale 1ns / 1ps

module register_file(
	input [4:0] ra,
	input [4:0] rb,
	input [4:0] rw,
	input wren,
	input clk,
	input rst,
	input [15:0] write_bus,
	output reg [15:0] bus_a,
	output reg [15:0] bus_b
);

reg [15:0] registers[31:0];

integer idx;

initial begin
	for (idx=0; idx < 32; idx=idx+1) begin
		registers[idx] = 16'b0;
	end
end

always @(posedge clk) begin
	if (rst == 1) begin
		for (idx=0; idx < 32; idx=idx+1) begin
			registers[idx] <= 16'b0;
		end
	end else begin
		// Write to register rw
		if (wren == 1) begin
			registers[rw] <= write_bus;
		end 

		// Read from register ra
		if (wren == 1 && ra == rw) begin
			bus_a <= write_bus;
		end else begin
			bus_a <= registers[ra]
		end

		// Read from register rb
		if (wren == 1 && rb == rw) begin
			bus_b <= write_bus;
		end else
			bus_b <= registers[rb];
		end
	end
end

endmodule