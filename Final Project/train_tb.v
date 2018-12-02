`timescale 1ns / 1ps

module train_tb();

reg clk;
reg conv1_valid, conv2_valid, fc_valid;
reg fw;
reg load_weights;
reg conv1_done, conv2_done;
reg [2:0] state;

wire conv1_rdy, conv2_rdy, fc_rdy;

parameter CONV1_FW = 0;
parameter CONV1_BP = 1;
parameter CONV2_FW = 2;
parameter CONV2_BP = 3;
parameter FC_FW = 4;
parameter FC_BP = 5;
parameter ERROR = 6;
parameter WEIGHT_INIT = 7;

wire [15:0] rand;
reg [31:0] output_value[9:0];
reg [31:0] input_image[27:0][27:0];
reg [31:0] conv1_in;
reg [4:0] conv1_x_in, conv1_y_in;
reg [2:0] conv1_i_in, conv1_i2_in;
reg [31:0] conv2_in;
reg [3:0] conv2_x_in, conv2_y_in;
reg [3:0] conv2_i_in, conv2_i2_in;
reg [31:0] fc_in;
reg [9:0] fc_i_in, fc_i2_in;

wire [31:0] conv1_out;
wire [4:0] conv1_x_out, conv1_y_out;
wire [3:0] conv1_i_out;
wire [31:0] conv2_out;
wire [3:0] conv2_x_out, conv2_y_out;
wire [3:0] conv2_i_out;
wire [31:0] fc_out;
wire [9:0] fc_i_out;

integer i,j;
reg [31:0] temp;

conv #(1,28,3,5,5,1,2,8) conv1(clk,1'b1,conv1_valid,fw,load_weights,conv1_in,conv1_i_in,conv1_i2_in,conv1_x_in,conv1_y_in,
                               conv1_rdy,conv1_out,conv1_i_out,conv1_x_out,conv1_y_out);

conv #(8,12,4,4,5,1,1,16) conv2(clk,1'b1,conv2_valid,fw,load_weights,conv2_in,conv2_i_in,conv2_i2_in,conv2_x_in,conv2_y_in,
                                conv2_rdy,conv2_out,conv2_i_out,conv2_x_out,conv2_y_out);

fc #(1024,10,10) fc_inst(clk,1'b1,fc_valid,fw,load_weights,fc_in,fc_i_in,fc_i2_in,fc_rdy,fc_out,fc_i_out);

lfsr_rng lsfr(clk, rand);

initial begin
    for (i=0;i<28;i=i+1)
        for (j=0;j<28;j=j+1)
            input_image[i][j] = 0;
    clk = 0;
    fw = 0;
    load_weights = 1;
    conv1_done = 0;
    conv2_done = 0;
    conv1_valid = 1;
    conv2_valid = 0;
    fc_valid = 0;
    conv1_in = input_image[0][0];
    conv1_i_in = 0;
    conv1_i2_in = 0;
    conv1_x_in = 0;
    conv1_y_in = 0;
    state = WEIGHT_INIT;
end

always begin
    #5 clk <= ~clk;
end

always @(posedge clk) begin
    case(state)
    WEIGHT_INIT: begin
        if (conv1_valid == 1)
            $display("Initializing CONV1 weights: (%d,%d,%d,%d) %d", conv1_i_in, conv1_i2_in, conv1_x_in, conv1_y_in, rand);
        else if (conv2_valid == 1)
            $display("Initializing CONV2 weights: (%d,%d,%d,%d) %d", conv2_i_in, conv2_i2_in, conv2_x_in, conv2_y_in, rand);
        else if (fc_valid == 1)
            $display("Initializing FC weights: (%d,%d) %d", fc_i_in, fc_i2_in, rand);
        if (conv1_i2_in == 7) begin
            if (conv1_x_in == 4) begin
                if (conv1_y_in == 4) begin
                    if (conv1_valid == 1) begin
                        conv1_valid <= 0;
                        conv2_valid <= 1;
                        conv2_i_in <= 0;
                        conv2_i2_in <= 0;
                        conv2_x_in <= 0;
                        conv2_y_in <= 0;
                        conv2_in <= {rand[15],16'b0,rand[14:0]};
                    end else if (conv2_i_in == 7) begin
                        if (conv2_i2_in == 15) begin
                            if (conv2_x_in == 4) begin
                                if (conv2_y_in == 4) begin
                                    if (conv2_valid == 1) begin
                                        conv2_valid <= 0;
                                        fc_valid <= 1;
                                        fc_i_in <= 0;
                                        fc_i2_in <= 0;
                                        fc_in <= {rand[15],16'b0,rand[14:0]};
                                    end else if (fc_i_in == 1023) begin
                                        if (fc_i2_in == 9) begin
                                            fw <= 1;
                                            load_weights <= 0;
                                            conv1_valid <= 1;
                                            fc_valid <= 0;
                                            conv1_x_in <= 0;
                                            conv1_y_in <= 0;
                                            state <= CONV1_FW;
                                        end else begin
                                            fc_i_in <= 0;
                                            fc_i2_in <= fc_i2_in + 1;
                                            fc_in <= {rand[15],16'b0,rand[14:0]};
                                        end
                                    end else begin
                                        fc_i_in <= fc_i_in + 1;
                                        fc_in <= {rand[15],16'b0,rand[14:0]};
                                    end 
                                end else begin
                                    conv2_y_in <= conv2_y_in + 1;
                                    conv2_i_in <= 0;
                                    conv2_i2_in <= 0;
                                    conv2_x_in <= 0;
                                    conv2_in <= {rand[15],16'b0,rand[14:0]};
                                end
                            end else begin
                                conv2_x_in <= conv2_x_in + 1;
                                conv2_i_in <= 0;
                                conv2_i2_in <= 0;
                                conv2_in <= {rand[15],16'b0,rand[14:0]};
                            end
                        end else begin
                            conv2_i2_in <= conv2_i2_in + 1;
                            conv2_i_in <= 0;
                            conv2_in <= {rand[15],16'b0,rand[14:0]};
                        end
                    end else begin
                        conv2_i_in <= conv2_i_in + 1;
                        conv2_in <= {rand[15],16'b0,rand[14:0]};
                    end 
                end else begin
                    conv1_y_in <= conv1_y_in + 1;
                    conv1_x_in <= 0;
                    conv1_i2_in <= 0;
                    conv1_in <= {rand[15],16'b0,rand[14:0]};
                end
            end else begin
                conv1_x_in <= conv1_x_in + 1;
                conv1_i2_in <= 0;
                conv1_in <= {rand[15],16'b0,rand[14:0]};
            end
        end else begin
            conv1_i2_in <= conv1_i2_in + 1;
            conv1_in <= {rand[15],16'b0,rand[14:0]};
        end
    end
    CONV1_FW: begin
        if (conv1_x_in == 27) begin
            if (conv1_y_in == 27) begin
                conv1_valid <= 0;
            end else begin
                conv1_x_in <= 0;
                conv1_y_in <= conv1_y_in + 1;
            end
        end else 
            conv1_x_in <= conv1_x_in + 1;
        if (conv1_rdy == 0) begin
            conv2_valid <= 1;
            conv2_in <= conv1_out;
            conv2_i_in <= 0;
            conv2_x_in <= 0;
            conv2_y_in <= 0;
            state <= CONV2_FW;
        end
    end
    CONV2_FW: begin
        conv2_in <= conv1_out;
        if (conv2_i_in == 7 && conv2_x_in == 11 && conv2_y_in == 11)
            conv2_valid <= 0;
        else begin
            conv2_i_in <= conv1_i_out;
            conv2_x_in <= conv1_x_out;
            conv2_y_in <= conv1_y_out;
        end
        if (conv2_rdy == 0) begin
            fc_valid <= 1;
            fc_in <= conv2_out;
            fc_i_in <= 0;
            state <= FC_FW;
        end
    end
    FC_FW: begin
        fc_in <= conv2_out;
        if (fc_i_in == 1023)
            fc_valid <= 0;
        else
            fc_i_in <= conv2_i_out*64 + conv2_x_out*8 + conv2_y_out;
        if (fc_rdy == 0) begin
            output_value[0] <= fc_out;
            state <= ERROR;
        end
    end
    ERROR: begin
        output_value[fc_i_out] <= fc_out;
        if (fc_i_out == 9) begin
            state <= FC_BP;
            fc_in <= output_value[0] - {17'b1,15'b0};
            fc_i_in <= 0;
            fw <= 0;
            fc_valid <= 1;
        end
        if (fc_i_out == 9) begin
            temp = (fc_out- {17'b1,15'b0})*(fc_out- {17'b1,15'b0}) >> 15;
            for (i=0;i<9;i=i+1)
                temp = temp + (output_value[i] - {17'b1,15'b0})*(output_value[i]- {17'b1,15'b0}) >> 15;
            $display("Error: %d.%d", temp[30:15], temp[14:0]);
        end
    end
    FC_BP: begin
        if (fc_i_in == 9)
            fc_valid <= 0;
        else begin
            temp = output_value[fc_i_in + 1] - {17'b1,15'b0};
            fc_in <= temp;
            fc_i_in <= fc_i_in + 1;
        end
        if (fc_rdy == 0) begin
            state <= CONV2_BP;
            conv2_in <= fc_out;
            conv2_i_in <= 0;
            conv2_x_in <= 0;
            conv2_y_in <= 0;
            conv2_valid <= 1;
        end
    end
    CONV2_BP: begin
        if (conv2_i_in == 15 && conv2_x_in == 7 && conv2_y_in == 7)
            conv2_valid <= 0;
        else begin
            conv2_i_in <= (fc_i_out & 'h3C0) >> 6;
            conv2_x_in <= (fc_i_out & 'h38) >> 3;
            conv2_y_in <= fc_i_out & 'h7;
            conv2_in <= fc_out;
        end
        if (conv2_rdy == 0) begin
            state <= CONV1_BP;
            conv1_in <= conv2_out;
            conv1_i_in <= 0;
            conv1_x_in <= 0;
            conv1_y_in <= 0;
            conv1_valid <= 1;
        end
    end
    CONV1_BP: begin
        if (conv1_i_in == 7 && conv1_x_in == 11 && conv1_y_in == 11)
            conv1_valid <= 0;
        else begin 
            conv1_i_in <= conv2_i_out;
            conv1_x_in <= conv2_x_out;
            conv1_y_in <= conv2_y_out;
            conv1_in <= conv2_out;
        end
        if (conv1_valid == 0 && conv1_rdy == 1) begin
            state <= CONV1_FW;
            fw <= 1;
            conv1_i_in <= 0;
            conv1_x_in <= 0;
            conv1_y_in <= 0;
            conv1_in <= 0;
            conv1_valid <= 1;
        end
    end
    endcase
end

always @(state)
    case(state)
    CONV1_FW: $display("CONV1 Forward stage");
    CONV2_FW: $display("CONV2 Forward stage");
    FC_FW: $display("FC Forward stage");
    CONV1_BP: $display("CONV1 Backprop stage");
    CONV2_BP: $display("CONV2 Backprop stage");
    FC_BP: $display("FC Backprop stage");
    ERROR: $display("Computing Error");
    endcase

endmodule