module conv_tb();

reg clk, out_rdy, forward, load_weights;
reg [31:0] conv_input;
reg [3:0] conv_input_idx;
reg [3:0] conv_input_x, conv_input_y;

wire [31:0] conv_output;
wire [3:0] conv_output_idx;
wire [3:0] conv_output_x, conv_output_y;
wire in_rdy,out_valid;
integer x_bound, y_bound, idx_bound;
// Weights
wire wt_we;
wire [12:0] wt_addr;
wire [31:0] wt_idata;
wire [31:0] wt_odata;
//Outputs
wire o_val_rst;
wire o_val_we;
wire [11:0] o_val_addr;
wire [31:0] o_val_idata;
wire [31:0] o_val_odata;
//Lastin
wire lastin_rst;
wire lastin_we;
wire [10:0] lastin_addr;
wire [31:0] lastin_idata;
wire  [31:0] lastin_odata;
//Error
wire error_rst; 
wire error_we;
wire [10:0] error_addr;
wire [31:0] error_idata;
wire [31:0] error_odata;

conv #(8,12,4,4,5,1,2,16,3,4) conv_inst(clk,out_rdy,1,load_weights,conv_input,conv_input_idx,,conv_input_x,conv_input_y,
    in_rdy,out_valid,conv_output,conv_output_idx,conv_output_x,conv_output_y,
    wt_we,wt_addr,wt_idata,wt_odata,o_val_rst,o_val_we,o_val_addr,o_val_idata,o_val_odata,lastin_rst,lastin_we,lastin_addr,lastin_idata,lastin_odata,
    error_rst,error_we,error_addr,error_idata,error_odata);

conv_wt weights (
    .clka(clk), // input clka
    .wea(wt_we), // input [0 : 0] wea
    .addra(wt_addr), // input [12 : 0] addra
    .dina(wt_idata), // input [31 : 0] dina
    .douta(wt_odata) // output [31 : 0] douta
);

conv_error error (
  .clka(clk), // input clka
  .rsta(error_rst), // input rsta
  .wea(error_we), // input [0 : 0] wea
  .addra(error_addr), // input [10 : 0] addra
  .dina(error_idata), // input [15 : 0] dina
  .douta(error_odata) // output [15 : 0] douta
);

conv_lastin lastin (
  .clka(clk), // input clka
  .rsta(lastin_rst), // input rsta
  .wea(lastin_we), // input [0 : 0] wea
  .addra(lastin_addr), // input [10 : 0] addra
  .dina(lastin_idata), // input [31 : 0] dina
  .douta(lastin_odata) // output [31 : 0] douta
);

conv_o_val o_val (
  .clka(clk), // input clka
  .rsta(o_val_rst), // input rsta
  .wea(o_val_we), // input [0 : 0] wea
  .addra(o_val_addr), // input [11 : 0] addra
  .dina(o_val_idata), // input [31 : 0] dina
  .douta(o_val_odata) // output [31 : 0] douta
);

initial begin
  x_bound = 11;
  y_bound = 11;
  idx_bound = 7;
  clk = 0;
  out_rdy = 1;
  forward = 1;
  load_weights = 0;
  conv_input = {16'b01,16'b0};
  conv_input_idx = 0;
  conv_input_x = 0;
  conv_input_y = 0;
end

always begin
    #5 clk <= ~clk;
end

always @(out_valid)
	$stop;

always @(posedge clk) begin
    if (in_rdy == 1) begin
        if (conv_input_x == x_bound) begin
            if (conv_input_y == y_bound) begin
                if (conv_input_idx == idx_bound) begin
                    conv_input_x <= 0;
                    conv_input_y <= 0;
                    conv_input_idx <= 0;
                end else begin
                    conv_input_idx <= conv_input_idx + 1;
                    conv_input_x <= 0;
                    conv_input_y <= 0;
                end
            end else begin
                conv_input_y <= conv_input_y + 1;
                conv_input_x <= 0;
            end
        end else begin
            conv_input_x <= conv_input_x + 1;
        end 
    end
    if (forward == 1 && conv_output_idx == 15 && conv_output_x == 3 && conv_output_y == 3) begin
        forward <= 0;
        x_bound = 3;
        y_bound = 3;
        idx_bound = 15;
    end 
    if (forward == 0 && conv_output_idx == 7 && conv_output_x == 11 && conv_output_y == 11) begin
        forward <= 1;
        x_bound = 11;
        y_bound = 11;
        idx_bound = 7;
    end
    if (in_rdy == 1 || out_valid == 1)
        $display("Input (%d,%d,%d)--Output (%d,%d,%d) %d.%d F(%b)", conv_input_x, conv_input_y, conv_input_idx,
             conv_output_x, conv_output_y, conv_output_idx, conv_output[31:16], conv_output[15:0], forward);
end

endmodule