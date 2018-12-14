`timescale 1ns / 1ps

module tb();

reg rx, clk;
wire tx;
wire [7:0] led;

top uart_mod(clk, rx, tx, led);

initial begin
	rx = 1;
	clk = 0;
end

always begin
	#5 clk <= ~clk;
end

endmodule