module conv #(
    parameter INPUT_DEPTH = 1,
    parameter INPUT_SIZE = 13,
    parameter IDX_WIDTH = 3,
    parameter COORD_WIDTH = 5,
    parameter KERNEL_SIZE = 5,
    parameter STRIDE = 2,
    parameter MAXPOOL = 1,
    parameter OUTPUT_DEPTH = 8,
    parameter IN_ADDR_WIDTH = 5,
    parameter O_ADDR_WIDTH = 5,
    parameter OUTPUT_SIZE = (INPUT_SIZE - KERNEL_SIZE) / STRIDE + 1
)
(
    input clk,
    input out_rdy,
    input in_valid,
    input forward,
    input load_weights,
    input [31:0] conv_input,
    input [IDX_WIDTH - 1:0] conv_input_idx,
    input [IDX_WIDTH - 1:0] conv_input_idx2, // Only used to load weights, might not keep it tbh
    input [COORD_WIDTH - 1:0] conv_input_x,
    input [COORD_WIDTH - 1:0] conv_input_y,
    output reg in_rdy,
    output reg out_valid,
    output reg [31:0] conv_output,
    output reg [IDX_WIDTH - 1:0] conv_output_idx,
    output reg [COORD_WIDTH - 1:0] conv_output_x,
    output reg [COORD_WIDTH - 1:0] conv_output_y,
    // Weights
    output reg wt_we,
    output reg [O_ADDR_WIDTH + IN_ADDR_WIDTH + 5:0] wt_addr,
    output reg [31:0] wt_idata,
    input [31:0] wt_odata,
    //Outputs
    output reg o_val_rst, 
    output reg o_val_we,
    output reg [O_ADDR_WIDTH + 2*COORD_WIDTH - 1:0] o_val_addr,
    output reg [31:0] o_val_idata,
    input [31:0] o_val_odata,
    //Lastin
    output reg lastin_rst, 
    output reg lastin_we,
    output reg [IN_ADDR_WIDTH + 2*COORD_WIDTH - 1:0] lastin_addr,
    output reg [31:0] lastin_idata,
    input  [31:0] lastin_odata,
    //Error
    output reg error_rst, 
    output reg error_we,
    output reg [IN_ADDR_WIDTH + 2*COORD_WIDTH - 1:0] error_addr,
    output reg [31:0] error_idata,
    input [31:0] error_odata
);

/*parameter RATE = {1'b0,16'b0,15'd1638}; // Approx 0.05

reg [31:0] weights [KERNEL_SIZE*KERNEL_SIZE - 1:0][OUTPUT_DEPTH*INPUT_DEPTH - 1:0];
reg [31:0] last_input [INPUT_SIZE*INPUT_SIZE - 1:0][INPUT_DEPTH - 1:0];
reg [31:0] output_val [OUTPUT_SIZE*OUTPUT_SIZE - 1:0][OUTPUT_DEPTH - 1:0];
reg [31:0] error_val [INPUT_SIZE*INPUT_SIZE - 1:0][INPUT_DEPTH - 1:0];*/
reg [IDX_WIDTH - 1:0] last_input_idx;
reg [COORD_WIDTH - 1:0] last_input_x;
reg [COORD_WIDTH - 1:0] last_input_y;
reg [63:0] temp;
reg [31:0] max_val;
reg [31:0] conv_in_val;
reg offset_x, offset_y, computing;
wire last_in_idx, last_out_idx;
wire last_in_idxbp, last_out_idxbp;

assign last_in_idx = conv_input_idx == INPUT_DEPTH - 1 && conv_input_x == INPUT_SIZE - 1 && conv_input_y == INPUT_SIZE - 1;
assign last_out_idx = conv_output_idx == OUTPUT_DEPTH - 1 && conv_output_x == OUTPUT_SIZE / MAXPOOL - 1 && conv_output_y == OUTPUT_SIZE / MAXPOOL - 1;
assign last_in_idxbp = conv_input_idx == OUTPUT_DEPTH - 1 && conv_input_x == OUTPUT_SIZE / MAXPOOL - 1 && conv_input_y == OUTPUT_SIZE / MAXPOOL - 1;
assign last_out_idxbp = conv_output_idx == INPUT_DEPTH - 1 && conv_output_x == INPUT_SIZE - 1 && conv_output_y == INPUT_SIZE - 1;

initial begin
    in_rdy = 1;
    conv_output_idx = 0;
    conv_output_x = 0;
    conv_output_y = 0;
    last_input_idx = INPUT_DEPTH - 1;
    last_input_x = INPUT_SIZE - 1;
    last_input_y = INPUT_SIZE - 1;
    conv_output = 32'b0;
end

//Update the temporary computed value upon each input
always @(posedge clk) begin
    if (load_weights == 1) begin
        if (in_valid == 1) begin
            // We store the input in the weights if this pin is high and we are not sendig 
            wt_we <= 1;
            wt_addr <= {conv_input_idx[O_ADDR_WIDTH - 1:0],conv_input_idx2[IN_ADDR_WIDTH - 1:0],conv_input_x[2:0],conv_input_y[2:0]};
            wt_idata <= conv_input;
            //weights[conv_input_x*KERNEL_SIZE + conv_input_y][conv_input_idx*INPUT_DEPTH + conv_input_idx2] <= conv_input;
        end
    end

    else begin
      wt_we <= 0;
      if (forward == 1) begin
          error_rst <= 0;
          o_val_rst <= 0;
          if (in_valid == 1 && in_rdy == 1 && (conv_input_idx != last_input_idx || conv_input_x != last_input_x || conv_input_y != last_input_y)) begin
              // Update last input indices so we dont overcount inputs
              last_input_idx <= conv_input_idx;
              last_input_x <= conv_input_x;
              last_input_y <= conv_input_y;
              last_input[conv_input_x*INPUT_SIZE + conv_input_y][conv_input_idx] <= conv_input;
              // Get ready for computation stage
              in_rdy <= 0;
              computing <= 1;
              wt_addr <= {'b0,conv_input_idx[IN_ADDR_WIDTH - 1:0],3'b0,3'b0};
              o_val_addr <= {'b0,conv_input_x[COORD_WIDTH - 1:0],conv_input_y[COORD_WIDTH - 1:0]};
              lastin_we <= 1;
              lastin_idata <= conv_input;
              lastin_addr <= {conv_input_idx,conv_input_x[COORD_WIDTH - 1:0],conv_input_y[COORD_WIDTH - 1:0]};
              // Perform forward stage computation and update temp value
              /*for (i=0; i<OUTPUT_DEPTH; i=i+1) begin 
                  for (j=0; j<KERNEL_SIZE; j=j+1) begin
                      for (k=0; k<KERNEL_SIZE; k=k+1) begin                                       
                          if (conv_input_x >= j && conv_input_x - j < OUTPUT_SIZE &&
                              conv_input_y >= k && conv_input_y - k < OUTPUT_SIZE) begin
                              temp = ((weights[j*KERNEL_SIZE + k][i*INPUT_DEPTH + conv_input_idx]*conv_input) >> 16);
                              output_val[(conv_input_x - j)*OUTPUT_SIZE + conv_input_y - k][i] <= output_val[(conv_input_x - j)*OUTPUT_SIZE + conv_input_y - k][i] + temp;
                          end
                      end
                  end
              end*/
              /*if (last_in_idx == 1) begin
                  in_rdy <= 0;
                  conv_output_x <= 0;
                  conv_output_y <= 0;
                  conv_output_idx <= 0;
                  conv_output <= output_val[0][0];
              end*/
          end else if (computing == 1) begin
              if (o_val_we == 0) begin
                  if (last_input_x >= wt_addr[5:3] && last_input_x - wt_addr[5:3] < OUTPUT_SIZE &&
                      last_input_y >= wt_addr[2:0] && last_input_y - wt_addr[2:0] < OUTPUT_SIZE) 
                      temp = (wt_odata*lastin_idata) >> 16;
                  else
                      temp = 0;
                  o_val_idata <= o_val_odata + temp
                  o_val_we <= 1;
              end else begin
                  if (wt_addr[2:0] == KERNEL_SIZE - 1 && wt_addr[5:3] == KERNEL_SIZE - 1 && wt_addr[O_ADDR_WIDTH + IN_ADDR_WIDTH + 5:IN_ADDR_WIDTH + 5] == OUTPUT_DEPTH - 1) begin
                      computing <= 0;
                      if (lastin_addr[COORD_WIDTH - 1:0] != INPUT_SIZE - 1 && lastin_addr[2*COORD_WIDTH - 1:COORD_WIDTH] != INPUT_SIZE - 1 && lastin_addr[IN_ADDR_WIDTH + 2*COORD_WIDTH - 1:2*COORD_WIDTH] != INPUT_DEPTH - 1)
                          in_rdy <= 1;
                      else
                          o_val_addr <= 'b0;
                  end else begin
                      if (wt_addr[2:0] == KERNEL_SIZE - 1) begin
                          if (wt_addr[5:3] == KERNEL_SIZE - 1) begin
                              wt_addr[O_ADDR_WIDTH + IN_ADDR_WIDTH + 5:IN_ADDR_WIDTH + 5] <= wt_addr[O_ADDR_WIDTH + IN_ADDR_WIDTH + 5:IN_ADDR_WIDTH + 5] + 1;
                              wt_addr[5:0] <= 6'b0;
                              o_val_addr[O_ADDR_WIDTH + 2*COORD_WIDTH - 1:2*COORD_WIDTH] <= o_val_addr[O_ADDR_WIDTH + 2*COORD_WIDTH - 1:2*COORD_WIDTH] + 1;
                              o_val_addr[2*COORD_WIDTH - 1:COORD_WIDTH] <= conv_input_x;
                              o_val_addr[COORD_WITH - 1:0] <= conv_input_y;
                          end else begin
                              wt_addr[5:3] <= wt_addr[5:3] + 1;
                              wt_addr[2:0] <- 3'b0;
                              o_val_addr[2*COORD_WIDTH - 1:COORD_WIDTH] <= o_val_addr[2*COORD_WIDTH - 1:COORD_WIDTH] + 1;
                              o_val_addr[COORD_WIDTH - 1:0] <= conv_input_y;
                          end
                      end else begin
                          wt_addr[2:0] <= wt_addr[2:0] + 1;
                          o_val_addr[COORD_WIDTH - 1:0] <= o_val_addr[COORD_WIDTH - 1:0] + 1;
                      end
                      o_val_we <= 0;
                  end
              end
          end
          
          // If we are done performing previous computation, start sending
          if (in_rdy == 0 && computing == 0) begin
              // Must scan inputs over the pooling region before sending
              if (o_val_odata > max_val)
                  max_val = o_val_odata;
              if (last_out_idx == 1) begin
                  out_valid <= 0;
                  in_rdy <= 1;
                  o_val_addr <= 0;
              end
              // Incrementing address is complex since we must sweep the maxpool region
              if (o_val_addr[COORD_WIDTH - 1:0] % MAXPOOL == MAXPOOL - 1) begin
                  if (o_val_addr[2*COORD_WIDTH - 1:COORD_WIDTH] % MAXPOOL == MAXPOOL - 1) begin
                      if (o_val_addr[COORD_WIDTH - 1:0] == OUTPUT_SIZE - 1) begin
                          if (o_val_addr[2*COORD_WIDTH - 1:COORD_WIDTH] == OUTPUT_SIZE - 1) begin
                              o_val_addr[O_ADDR_WIDTH + 2*COORD_WIDTH - 1:2*COORD_WIDTH] <= o_val_addr[O_ADDR_WIDTH + 2*COORD_WIDTH - 1:2*COORD_WIDTH] + 1;
                              o_val_addr[2*COORD_WIDTH - 1:0] <= 'b0;
                          end else begin
                              o_val_addr[COORD_WIDTH - 1:0] <= 0;
                              o_val_addr[2*COORD_WIDTH - 1:COORD_WIDTH] <= o_val_addr[2*COORD_WIDTH - 1:COORD_WIDTH] + 1;
                          end
                      end else begin
                          o_val_addr[COORD_WIDTH - 1:0] <= o_val_addr[COORD_WIDTH - 1:0] + 1;
                          o_val_addr[2*COORD_WIDTH - 1:COORD_WIDTH] <= o_val_addr[2*COORD_WIDTH - 1:COORD_WIDTH] - MAXPOOL + 1;
                      end                          
                      conv_output <= max_val;
                      max_val = 0;
                      conv_output_idx <= o_val_addr[O_ADDR_WIDTH + 2*COORD_WIDTH - 1:2*COORD_WIDTH];
                      conv_output_x <= o_val_addr[2*COORD_WIDTH - 1:COORD_WIDTH] / MAXPOOL;
                      conv_output_y <= o_val_addr[COORD_WIDTH - 1:0] / MAXPOOL;
                      out_valid <= 1;
                  end else begin
                      o_val_addr[COORD_WIDTH - 1:0] <= o_val_addr[COORD_WIDTH - 1:0] - MAXPOOL + 1;
                      o_val_addr[2*COORD_WIDTH - 1:COORD_WIDTH] <= o_val_addr[2*COORD_WIDTH - 1:COORD_WIDTH] + 1;
                  end
              end else begin
                  out_valid <= 0;
                  o_val_addr[COORD_WIDTH - 1:0] <= o_val_addr[COORD_WIDTH - 1:0] + 1;
              end
        end
    end else begin // Backprop stage
        if (in_valid == 1 && in_rdy == 1 && conv_input_idx != last_input_idx || conv_input_x != last_input_x || conv_input_y != last_input_y) begin
            // Update last input indices so we dont overcount inputs
            last_input_idx <= conv_input_idx;
            last_input_x <= conv_input_x;
            last_input_y <= conv_input_y;
    
            for (i=0; i<INPUT_DEPTH; i=i+1) begin 
                for (j=0; j<KERNEL_SIZE; j=j+1) begin
                    for (k=0; k<KERNEL_SIZE; k=k+1) begin
                        offset_x = 0;
                        offset_y = 0;
                        rel_val = 0;
                        // Determine the offset of the input that actually contributed to output value.
                        // Recall that during MAXPOOL stage we only output the max value of the
                        // MAXPOOL x MAXPOOL region.
                        for (l=0;l<MAXPOOL;l=l+1)
                            for (m=0;m<MAXPOOL;m=m+1)
                                if (output_val[(MAXPOOL*conv_input_x + j + l)*OUTPUT_SIZE + MAXPOOL*conv_input_y + j + m][i][31] == 0 && 
                                    output_val[(MAXPOOL*conv_input_x + j + l)*OUTPUT_SIZE + MAXPOOL*conv_input_y + j + m][i][31] > rel_val) begin
                                    rel_val = output_val[(MAXPOOL*conv_input_x + j + l)*OUTPUT_SIZE + MAXPOOL*conv_input_y + j + m][i];
                                    offset_x = l;
                                    offset_y = m;
                                end
                        // To reduce confusion:
                        // conv_input_x -> output coordinate we are examining (mult. by MAXPOOL to reverse downsampling)
                        // offset_x     -> offset value determined by max pooling stage
                        // j            -> index as we iterate over the weight filter
                        // Same rules apply to conv_input_y, offset_y, and k.
                        temp = ((weights[j*KERNEL_SIZE + k][conv_input_idx*INPUT_DEPTH + i]*conv_input) >> 16);
                        error_val[(MAXPOOL*conv_input_x + offset_x + j)*INPUT_SIZE + MAXPOOL*conv_input_y + offset_y + k][i] <= error_val[(MAXPOOL*conv_input_x + offset_y + j)*INPUT_SIZE + MAXPOOL*conv_input_y + offset_y + k][i] + temp;
    
                        // Only update the weights when we output a positive value:
                        if (rel_val != 0) begin
                            temp = ((last_input[(MAXPOOL*conv_input_x  + offset_x + j)*INPUT_SIZE + MAXPOOL*conv_input_y + offset_y + k][i]*conv_input) >> 16);
                            temp = (RATE*temp) >> 16;
                            weights[j*KERNEL_SIZE + k][conv_input_idx*INPUT_DEPTH + i] <= weights[j*KERNEL_SIZE + k][conv_input_idx*INPUT_DEPTH + i] - temp;
                        end
                    end
                end
            end
    
            if (last_in_idxbp == 1) begin
                in_rdy <= 0;
                conv_output_x <= 0;
                conv_output_y <= 0;
                conv_output_idx <= 0;
                conv_output <= error_val[0][0];
            end
        end
    
        // If we are done performing previous backprop computation
        if (in_rdy == 0 && out_rdy == 1) begin
            if (conv_output_y == INPUT_SIZE - 1) begin
                if (conv_output_x == INPUT_SIZE - 1) begin
                    // When we have finished output, we are ready for input
                    if (conv_output_idx == INPUT_DEPTH - 1) begin
                        in_rdy <= 1;
                        for (i=0;i<INPUT_DEPTH;i=i+1)
                            for (j=0;j<INPUT_SIZE;j=j+1)
                                for (k=0;k<INPUT_SIZE;k=k+1)
                                    error_val[j*INPUT_SIZE + k][i] <= 0;
                    end else begin
                        // Increment idx but reset x,y
                        conv_output <= error_val[0][conv_output_idx + 1];
                        conv_output_idx <= conv_output_idx + 1;
                        conv_output_x <= 0;
                        conv_output_y <= 0;
                    end
                end else begin
                    // Increment x but reset y
                    conv_output <= error_val[(conv_output_x + 1)*INPUT_SIZE][conv_output_idx];
                    conv_output_y <= 0;
                    conv_output_x <= conv_output_x + 1;
                end
            end else begin
                // Increment y
                conv_output <= error_val[(conv_output_x)*OUTPUT_SIZE + conv_output_y + 1][conv_output_idx];
                conv_output_y <= conv_output_y + 1;
            end
        end
    end
end // always

endmodule