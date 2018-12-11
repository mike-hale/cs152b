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
    output in_rdy,
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
parameter FW_REC = 0;
parameter FW_COMP = 1;
parameter FW_SEND = 2;
parameter BP_REC = 3;
parameter BP_COMP = 4;
parameter BP_SEND = 5;

reg [2:0] state;
reg [31:0] fc_in_val;
reg [63:0] temp;
reg mem_valid;
reg [IDX_WIDTH - 1:0] last_input_idx;

assign in_rdy = state == FW_REC || state == BP_REC;

initial begin
    state <= FW_REC;
    fc_output_idx = 0;
    last_input_idx = INPUT_WIDTH - 1;
    fc_output = 32'b0;
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
        case(state)
        FW_REC: begin
            o_val_rst <= 0;
            error_rst <= 0;
            if (in_valid == 1 && in_rdy == 1 && fc_input_idx != last_input_idx) begin
                // Record the input, then shut off the flow while we perform computation
                last_input_idx <= fc_input_idx;
                wt_addr <= fc_input_idx << O_ADDR_WIDTH; // Retrieve the first weight for this input
                o_val_addr <= 0;
                mem_valid <= 0;
                lastin_we <= 1;
                lastin_addr <= fc_input_idx;
                lastin_idata <= fc_input;
                state <= FW_COMP;
            end
        end

        FW_COMP: begin
            lastin_we <= 0;
            if (o_val_we == 0) begin // First we must read the stored value in o_val
                if (mem_valid == 1) begin
                    o_val_idata <= qadd(o_val_odata, qmult(wt_odata, lastin_idata));
                    o_val_we <= 1;
                end else begin // Then we update
                    mem_valid <= 1;     
            end else begin
                o_val_we <= 0;
                mem_valid <= 0;
                wt_addr <= wt_addr + 1;
                if (o_val_addr == OUTPUT_WIDTH - 1) begin // Last output value is updated
                    if (lastin_addr != INPUT_WIDTH - 1) // We reset in_rdy if we need more inputs
                        state <= FW_REC;
                    else begin //Prepare to start sending data
                        o_val_addr <= 0;
                        state <= FW_SEND;
                    end
                end else 
                    o_val_addr <= o_val_addr + 1;
            end 
        end

        FW_SEND: begin      
            o_val_addr <= o_val_addr + 1;
            // Sending stage of forward computation
            if (mem_valid == 0)
                mem_valid <= 1;
            else if (out_valid == 0) begin // Sending first data value
                if (o_val_odata[31] == 1)
                    fc_output <= 0;
                else
                    fc_output <= o_val_odata;
                fc_output_idx <= 0;
                out_valid <= 1;
            end else begin // Sending rest of data value
                if (fc_output_idx == OUTPUT_WIDTH - 1) begin
                    o_val_addr <= 0;
                    state <= BP_REC;
                    mem_valid <= 0;
                    out_valid <= 0;
                end else begin
                    // Implement ReLu layer as we're sending data
                    if (o_val_odata[31] == 1) // Negative value
                        fc_output <= 0;
                    else
                        fc_output <= o_val_odata;
                    fc_output_idx <= fc_output_idx + 1;
                end
            end
        end 
        
        BP_REC: begin // Backprop stage
            if (in_valid == 1 && fc_input_idx != last_input_idx) begin
                last_input_idx <= fc_input_idx;
                lastin_idata <= fc_input;
                state <= BP_COMP;
                o_val_addr <= o_val_addr + 1;
                // Again we must only update if the output was positive
                if (o_val_odata[31] == 0) begin // Positive value
                    in_rdy <= 0;
                    computing <= 1;
                    wt_addr <= {'b0,fc_input_idx[O_ADDR_WIDTH - 1:0]};
                    lastin_addr <= 0;
                    fc_in_val <= fc_input;
                end
        
        BP_COMP: begin
            if (mem_valid == 0)
                mem_valid <= 1;
            else if (error_we == 0) begin
                temp = ((wt_odata*fc_in_val) >> 8);
                if (o_val_odata[31] == 0) begin
                    error_idata <= qadd(error_odata, qmult(wt_odata, lastin_idata));
                    wt_idata <= qadd(wt_odata, qmult(~lastin_odata, lastin_idata)); 
                else begin
                    error_idata <= error_odata;
                    wt_idata <= wt_odata;
                end
                wt_we <= 1;
                error_we <= 1;
            end else begin
                if (error_addr == INPUT_WIDTH - 1) begin
                    if (wt_addr[O_ADDR_WIDTH - 1:0] != OUTPUT_WIDTH - 1) // We reset in_rdy if we need more inputs
                        state <= BP_REC;
                    else //Prepare to start sending data
                        state <= BP_SEND;
                end else begin
                    wt_addr[IN_ADDR_WIDTH + O_ADDR_WIDTH - 1:O_ADDR_WIDTH] <= wt_addr[IN_ADDR_WIDTH + O_ADDR_WIDTH - 1:O_ADDR_WIDTH] + 1;
                    error_addr <= error_addr + 1;
                end
                wt_we <= 0;
                error_we <= 0;
                mem_valid <= 0;
            end
        end 

        BP_SEND: begin
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