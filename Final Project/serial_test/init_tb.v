`timescale 1ns / 1ps

module init_tb();

reg clk, we;
reg [31:0] idata;
reg [3:0] addr;
wire [31:0] odata;

init_test UUT(
	.clka(clk),
	.wea(we),
	.addra(addr),
	.dina(idata),
	.douta(odata)
);

always begin
	#5 clk <= ~clk;
end

initial begin
	addr = 0;
	we = 0;
	clk = 0;
	idata = 0;
end

always @(posedge clk) begin
	$display("%04x",odata);
	addr <= addr + 1;
	if (addr == 9)
		$finish;
end

endmodule
