module fc #(
    parameter INPUT_WIDTH = 1024,
    parameter IDX_WIDTH = 10,
    parameter OUTPUT_WIDTH = 10
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
    output reg [31:0] fc_output,
    output reg [IDX_WIDTH - 1:0] fc_output_idx
);

parameter RATE = {1'b0,16'b0,15'd1638}; // Approx 0.05

reg [31:0] weights [OUTPUT_WIDTH - 1:0] [INPUT_WIDTH - 1:0];
reg [31:0] output_val [OUTPUT_WIDTH - 1:0];
reg [31:0] last_input [INPUT_WIDTH - 1:0];
reg [31:0] error_val [INPUT_WIDTH - 1:0];
reg [IDX_WIDTH - 1:0] last_input_idx;
reg [47:0] temp;
integer i,j;

initial begin
    fc_output_idx = 0;
    last_input_idx = INPUT_WIDTH - 1;
    fc_output = 32'b0;
    in_rdy = 1;
    for (i=0;i<OUTPUT_WIDTH;i=i+1)
        output_val[i] = 0;
    for (i=0;i<INPUT_WIDTH;i=i+1)
        error_val[i] = 0;
    for (i=0;i<OUTPUT_WIDTH;i=i+1)
        for (j=0;j<INPUT_WIDTH;j=j+1)
            weights[i][j] = 0;
end

// Updates output_val based on incoming inputs.
always @(posedge clk) begin
    if (load_weights == 1) begin
        if (in_valid == 1)
            weights[fc_input_idx][fc_input_idx2] <= fc_input;
    end

    
    else if (forward == 1) begin
        if (in_valid == 1 && in_rdy == 1 && fc_input_idx != last_input_idx) begin
            last_input_idx <= fc_input_idx;
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
        end 

        if (in_rdy == 0 && out_rdy == 1) begin
            if (fc_output_idx == OUTPUT_WIDTH - 1) begin
                in_rdy <= 1;
                for (i=0;i<OUTPUT_WIDTH;i=i+1)
                    output_val[i] <= 0;
            end else begin
                // Implement ReLu layer as we're sending data
                if (output_val[fc_output_idx + 1][31] == 1) // Negative value
                    fc_output <= 0;
                else
                    fc_output <= output_val[fc_output_idx + 1];
                fc_output_idx <= fc_output_idx + 1;
            end
        end
    end else begin // Backprop stage
        if (in_valid == 1 && in_rdy == 1 && fc_input_idx != last_input_idx) begin
            last_input_idx <= fc_input_idx;
            // Again we must only update if the output was positive
            if (output_val[fc_input_idx][31] == 0) // Positive value
                for (i=0;i<INPUT_WIDTH;i=i+1) begin
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
                fc_output_idx <= 0;
            end
        end

        if (in_rdy == 0 && out_rdy == 1) begin
            if (fc_output_idx == INPUT_WIDTH - 1) begin
                in_rdy <= 1;
                for (i=0;i<INPUT_WIDTH;i=i+1)
                    error_val[i] <= 0;
            end else begin
                fc_output <= error_val[fc_output_idx + 1];
                fc_output_idx <= fc_output_idx + 1;
            end
        end
    end
end 

endmodule