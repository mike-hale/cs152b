`timescale 1ns / 1ps

module memory_test(
   inout  [63:0]              ddr2_dq,
   output [12:0]             ddr2_a,
   output [1:0]            ddr2_ba,
   output                             ddr2_ras_n,
   output                             ddr2_cas_n,
   output                             ddr2_we_n,
   output [0:0]              ddr2_cs_n,
   output [0:0]             ddr2_odt,
   output [C0:0]             ddr2_cke,
   output [7:0]              ddr2_dm,
   input                              sys_clk,
   input                              idly_clk_200,
   input                              sys_rst_n,
   output                             phy_init_done,
   inout  [7:0]             ddr2_dqs,
   inout  [7:0]             ddr2_dqs_n,
   output [1:0]             ddr2_ck,
   output [1:0]             ddr2_ck_n,
   output [3:0] led
);
    
wire         rst0_tb;
wire         clk0_tb;
wire         app_wdf_afull;
wire         app_af_afull;
wire         rd_data_valid;
reg          app_wdf_wren;
reg          app_af_wren;
reg [30:0]   app_af_addr;
reg [2:0]    app_af_cmd;
wire [127:0] rd_data_fifo_out;
reg [127:0]  app_wdf_data;
reg [15:0]   app_wdf_mask_data;
reg has_written;

initial begin
  app_wdf_wren = 0;
  app_af_wren = 0;
  app_af_addr = 0;
  app_af_cmd = 0;
  app_wdf_data = 16'h55AA;
  app_wdf_mask_data = 1;
  has_written = 0;
end

always @(posedge sys_clk) begin
  if (app_af_afull == 0) begin
    app_wdf_wren = 1;
    app_af_wren = 1;

endmodule
