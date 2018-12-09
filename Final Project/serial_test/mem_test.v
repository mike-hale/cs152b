
module mem_test(
    input clk,
    input [7:0] sw,
    output [3:0] Led
);

blk_test ram_test (
  .clka(clk), // input clka
  .wea(sw[0]), // input [0 : 0] wea
  .addra(sw[7:5]), // input [2 : 0] addra
  .dina(sw[4:1]), // input [3 : 0] dina
  .douta(Led[3:0]) // output [3 : 0] douta
);

endmodule
