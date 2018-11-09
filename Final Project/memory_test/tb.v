`timescale 1ns / 1ps

module tb();

reg clk;
reg [3:0] wea;
reg [31:0] data_in, addr;

wire [31:0] data_out;

integer i;

block_test my_memory(clk,wea,addr,data_in,data_out);

initial begin
  clk = 0;
  wea = 0;
  data_in = 0;
  addr = 0;
  #300
  data_in = 'h55AA;
  for (i=0; i >= 0; i=i+1) begin
    wea = 'h0;
    addr = i;
    #10
    if (data_out != 0) begin
      $display("%d",i);
    end
    wea = 'hF;
    #10;
  end
end

always begin
  #5 clk = ~clk;
end

endmodule
