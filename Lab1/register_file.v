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

always @(posedge clk) begin
	if (rst == 1) begin
		for (idx=0; idx < 32; idx=idx+1) begin
			registers[idx] <= 16'b0;
		end
	end else begin
		bus_a <= registers[ra];
		bus_b <= registers[rb];
		if (wren == 1) begin
			registers[rw] <= write_bus;
		end
	end
end

endmodule