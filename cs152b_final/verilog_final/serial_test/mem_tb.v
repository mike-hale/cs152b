`timescale 1ns / 1ps

module mem_tb();

reg clk;

fc_weights fc_weights_core (
  .clka(clka), // input clka
  .ena(ena), // input ena
  .wea(wea), // input [0 : 0] wea
  .addra(addra), // input [13 : 0] addra
  .dina(dina), // input [15 : 0] dina
  .douta(douta) // output [15 : 0] douta
);

endmodule
