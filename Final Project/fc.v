module fc #(
    parameter INPUT_WIDTH = 1024,
    parameter IDX_WIDTH = 10,
    parameter OUTPUT_WIDTH = 10,
    parameter IN_ADDR_WIDTH = 10,
    parameter O_ADDR_WIDTH = 4
)
(
    input clk,
    input out_rdy,
    input in_valid,
    input forward,
    input load_weights,
    input [31:0] fc_input,
    input [IDX_WIDTH - 1:0] fc_input_idx,
    input [IDX_WIDTH - 1:0] fc_input_idx2, // Only used for weights
    output reg in_rdy,
    output reg out_valid,
    output reg [31:0] fc_output,
    output reg [IDX_WIDTH - 1:0] fc_output_idx,
    // Weights
    output reg wt_we,
    output reg [IN_ADDR_WIDTH + O_ADDR_WIDTH - 1:0] wt_addr,
    output reg [31:0] wt_idata,
    input [31:0] wt_odata,
    //Outputs
    output reg o_val_rst, 
    output reg o_val_we,
    output reg [O_ADDR_WIDTH - 1:0] o_val_addr,
    output reg [31:0] o_val_idata,
    input [31:0] o_val_odata,
    //Lastin
    output reg lastin_rst, 
    output reg lastin_we,
    output reg [IN_ADDR_WIDTH - 1:0] lastin_addr,
    output reg [31:0] lastin_idata,
    input  [31:0] lastin_odata,
    //Error
    output reg error_rst, 
    output reg error_we,
    output reg [IN_ADDR_WIDTH - 1:0] error_addr,
    output reg [31:0] error_idata,
    input [31:0] error_odata
);

//parameter RATE = {1'b0,16'b0,15'd1638}; // Approx 0.05

//reg [31:0] weights [OUTPUT_WIDTH - 1:0] [INPUT_WIDTH - 1:0];
/* Weight addressing scheme:
   0x0000: w_0_0 w_1_0 w_2_0 ... w_9_0 0 0 0 0 0 0 <-- weights corresponding to input 0
   0x0010: w_1_0 w_1_1 w_2_1 ... w_9_1 0 0 0 0 0 0
   ...
   0x3FF0: w_1023_0 ...      w_1023_10 0 0 0 0 0 0
   Weights corresponding to the same input value are adjacent (fill the rest of the block with zeros)
*/

reg [31:0] fc_in_val;
reg [63:0] temp;
reg [IDX_WIDTH - 1:0] last_input_idx;
reg computing;

initial begin
    fc_output_idx = 0;
    last_input_idx = INPUT_WIDTH - 1;
    fc_output = 32'b0;
    in_rdy = 1;
end

// Updates output_val based on incoming inputs.
always @(posedge clk) begin
    if (load_weights == 1) begin
        if (in_valid == 1) begin
                wt_we <= 1;
                wt_addr <= {fc_input_idx2[IN_ADDR_WIDTH - 1:0],fc_input_idx[O_ADDR_WIDTH - 1:0]};
                wt_idata <= fc_input;
            //weights[fc_input_idx][fc_input_idx2] <= fc_input;
          end
    end

    
    else begin
        wt_we <= 0; // If we were writing weights, stop that now
        if (forward == 1) begin
            o_val_rst <= 0;
            error_rst <= 0;
            if (in_valid == 1 && in_rdy == 1 && fc_input_idx != last_input_idx) begin
                // Record the input, then shut off the flow while we perform computation
                last_input_idx <= fc_input_idx;
                in_rdy <= 0;
                computing <= 1;
                wt_addr <= fc_input_idx << O_ADDR_WIDTH; // Retrieve the first weight for this input
                o_val_addr <= 0;
                lastin_we <= 1;
                lastin_addr <= fc_input_idx;
                lastin_idata <= fc_input;
                /*
            last_input[fc_input_idx] <= fc_input;
            for (i=0; i<OUTPUT_WIDTH; i=i+1) begin
                temp = ((weights[i][fc_input_idx]*fc_input) >> 16);
                output_val[i] <= output_val[i] + temp;
            end
            if (fc_input_idx == INPUT_WIDTH - 1) begin
                in_rdy <= 0;
                fc_output <= output_val[0] + ((weights[0][INPUT_WIDTH - 1]*fc_input) >> 16);
                fc_output_idx <= 0;
            end
                */
            end else if (computing == 1) begin // Computing stage takes place between receiving each input
                if (o_val_we == 0) begin // First we must read the stored value in o_val
                    temp = ((wt_odata*lastin_idata) >> 16);
                    o_val_idata <= o_val_odata + temp;
                    o_val_we <= 1;
                end else begin // Then we update
                    if (o_val_addr == OUTPUT_WIDTH - 1) begin // Last output value is updated
                        computing <= 0;
                        if (lastin_addr != INPUT_WIDTH - 1) // We reset in_rdy if we need more inputs
                            in_rdy <= 1;
                        else //Prepare to start sending data
                            o_val_addr <= 0;
                    end else 
                        o_val_addr <= o_val_addr + 1;
                    o_val_we <= 0;
                    wt_addr <= wt_addr + 1;
                end
            end 
                
            // Sending stage of forward computation
            if (computing == 0 && in_rdy == 0) begin
                if (out_valid == 0) begin
                    if (o_val_odata[31] == 1)
                        fc_output <= 0;
                    else
                        fc_output <= o_val_odata;
                    fc_output_idx <= 0;
                    o_val_addr <= o_val_addr + 1;
                    out_valid <= 1;
                end else if (out_rdy == 1) begin
                    if (fc_output_idx == OUTPUT_WIDTH - 1) begin
                        in_rdy <= 1;
                        o_val_addr <= 0;
                        out_valid <= 0;
                    end else begin
                        // Implement ReLu layer as we're sending data
                        if (o_val_odata[31] == 1) // Negative value
                            fc_output <= 0;
                        else
                            fc_output <= o_val_odata;
                        fc_output_idx <= fc_output_idx + 1;
                        o_val_addr <= o_val_addr + 1;
                    end
                end
            end
        end else begin // Backprop stage
            if (in_valid == 1 && in_rdy == 1 && fc_input_idx != last_input_idx) begin
                last_input_idx <= fc_input_idx;
                o_val_addr <= o_val_addr + 1;
                // Again we must only update if the output was positive
                if (o_val_odata[31] == 0) begin // Positive value
                    in_rdy <= 0;
                    computing <= 1;
                    wt_addr <= {'b0,fc_input_idx[O_ADDR_WIDTH - 1:0]};
                    lastin_addr <= 0;
                    fc_in_val <= fc_input;
                    /*for (i=0;i<INPUT_WIDTH;i=i+1) begin
                        // Update input error values
                        temp = ((weights[fc_input_idx][i]*fc_input) >> 16);
                        error_val[i] <= error_val[i] + temp;
                        // Update weights
                        temp = ((last_input[i]*fc_input) >> 16);
                        temp = (RATE*temp) >> 16;
                        weights[fc_input_idx][i] <= weights[fc_input_idx][i] - temp;
                    end
                if (fc_input_idx == OUTPUT_WIDTH - 1) begin
                    in_rdy <= 0;
                    fc_output <= error_val[0] + ((weights[OUTPUT_WIDTH - 1][0]*fc_input) >> 16);
                    fc_output_idx <= 0;*/
                end
            end else if (computing == 1) begin
                if (error_we == 0) begin
                    temp = ((wt_odata*fc_in_val) >> 8);
                    error_idata <= error_odata + temp;
                    temp = ((lastin_odata*fc_in_val) >> 20); // +4 bits to account for the learning rate
                    wt_idata <= wt_odata - temp;
                    wt_we <= 1;
                    error_we <= 1;
                end else begin
                    if (error_addr == INPUT_WIDTH - 1) begin
                        computing <= 0;
                        if (wt_addr[O_ADDR_WIDTH - 1:0] != OUTPUT_WIDTH - 1) // We reset in_rdy if we need more inputs
                            in_rdy <= 1;
                        else //Prepare to start sending data
                            error_addr <= 0;
                    end else begin
                        wt_addr[IN_ADDR_WIDTH + O_ADDR_WIDTH - 1:O_ADDR_WIDTH] <= wt_addr[IN_ADDR_WIDTH + O_ADDR_WIDTH - 1:O_ADDR_WIDTH] + 1;
                        error_addr <= error_addr + 1;
                    end
                    wt_we <= 0;
                    error_we <= 0;
                end
            end 

            if (computing == 0 && in_rdy == 0) begin
                if (out_valid == 0) begin
                    fc_output <= error_odata;
                    fc_output_idx <= 0;
                    out_valid <= 1;
                    error_addr <= error_addr + 1;
                end else if (out_rdy == 1) begin
                    if (fc_output_idx == INPUT_WIDTH - 1) begin
                        in_rdy <= 1;
                        error_rst <= 1;
                        o_val_rst <= 1;
                        out_valid <= 0;
                    end else begin
                        fc_output <= error_odata;
                        fc_output_idx <= fc_output_idx + 1;
                        error_addr <= error_addr + 1;
                    end
                end
            end
        end
    end
end 

endmodule