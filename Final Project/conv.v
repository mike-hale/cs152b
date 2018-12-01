module conv #(
    parameter INPUT_DEPTH = 1,
    parameter INPUT_SIZE = 13,
    parameter IDX_WIDTH = 3,
    parameter COORD_WIDTH = 5,
    parameter KERNEL_SIZE = 5,
    parameter STRIDE = 2,
    parameter MAXPOOL = 1,
    parameter OUTPUT_DEPTH = 8,
    parameter OUTPUT_SIZE = (INPUT_SIZE - KERNEL_SIZE) / STRIDE + 1
)
(
    input clk,
    input out_rdy,
    input forward,
    input load_weights,
    input [31:0] conv_input,
    input [IDX_WIDTH - 1:0] conv_input_idx,
    input [IDX_WIDTH - 1:0] conv_input_idx2, // Only used to load weights, might not keep it tbh
    input [COORD_WIDTH - 1:0] conv_input_x,
    input [COORD_WIDTH - 1:0] conv_input_y,
    output reg in_rdy,
    output reg [31:0] conv_output,
    output reg [IDX_WIDTH - 1:0] conv_output_idx,
    output reg [COORD_WIDTH - 1:0] conv_output_x,
    output reg [COORD_WIDTH - 1:0] conv_output_y
);

parameter RATE = {1'b0,16'b0,15'd1638}; // Approx 0.05

reg [31:0] weights [KERNEL_SIZE - 1:0][KERNEL_SIZE - 1:0][OUTPUT_DEPTH - 1:0][INPUT_DEPTH - 1:0];
reg [31:0] last_input [INPUT_SIZE - 1:0][INPUT_SIZE - 1:0][INPUT_DEPTH - 1:0];
reg [31:0] output_val [OUTPUT_SIZE - 1:0][OUTPUT_SIZE - 1:0][OUTPUT_DEPTH - 1:0];
reg [31:0] error_val [INPUT_SIZE - 1:0][INPUT_SIZE - 1:0][INPUT_DEPTH - 1:0];
reg [IDX_WIDTH - 1:0] last_input_idx;
reg [COORD_WIDTH - 1:0] last_input_x;
reg [COORD_WIDTH - 1:0] last_input_y;
reg [47:0] temp;
reg [31:0] rel_val;
reg offset_x, offset_y;
wire last_in_idx, last_out_idx;
wire last_in_idxbp, last_out_idxbp;
integer i,j,k,l,m;

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
    for (i=0;i<KERNEL_SIZE;i=i+1) 
        for (j=0;j<KERNEL_SIZE;j=j+1) 
            for (k=0;k<OUTPUT_DEPTH;k=k+1) 
                for (l=0;l<INPUT_DEPTH;l=l+1) 
                    weights[i][j][k][l] = 0;
    for (i=0;i<OUTPUT_DEPTH;i=i+1)
        for (j=0;j<OUTPUT_SIZE;j=j+1)
            for (k=0;k<OUTPUT_SIZE;k=k+1)
                output_val[j][k][i] = 0;
    for (i=0;i<INPUT_DEPTH;i=i+1)
        for (j=0;j<INPUT_SIZE;j=j+1)
            for (k=0;k<INPUT_SIZE;k=k+1)
                error_val[j][k][i] = 0;
end

//Update the temporary computed value upon each input
always @(posedge clk) begin
if (load_weights == 1)
    // We store the input in the weights if this pin is high and we are not sendig 
    weights[conv_input_x][conv_input_y][conv_input_idx][conv_input_idx2] <= conv_input;
if (forward == 1) begin
    if (in_rdy == 1 && (conv_input_idx != last_input_idx || conv_input_x != last_input_x || conv_input_y != last_input_y)) begin
        // Update last input indices so we dont overcount inputs
        last_input_idx <= conv_input_idx;
        last_input_x <= conv_input_x;
        last_input_y <= conv_input_y;
        last_input[conv_input_x][conv_input_y][conv_input_idx] <= conv_input;
        // Perform forward stage computation and update temp value
        for (i=0; i<OUTPUT_DEPTH; i=i+1) begin 
            for (j=0; j<KERNEL_SIZE; j=j+1) begin
                for (k=0; k<KERNEL_SIZE; k=k+1) begin                                       
                    if (conv_input_x >= j && conv_input_x - j < OUTPUT_SIZE &&
                        conv_input_y >= k && conv_input_y - k < OUTPUT_SIZE) begin
                        temp = ((weights[j][k][i][conv_input_idx]*conv_input) >> 16);
                        output_val[conv_input_x - j][conv_input_y - k][i] <= output_val[conv_input_x - j][conv_input_y - k][i] + temp;
                    end
                end
            end
        end
        if (last_in_idx == 1) begin
            in_rdy <= 0;
            conv_output_x <= 0;
            conv_output_y <= 0;
            conv_output_idx <= 0;
            conv_output <= output_val[0][0][0];
        end
    end

    // If we are done performing previous computation
    if (in_rdy == 0 && out_rdy == 1) begin
        if (conv_output_y == OUTPUT_SIZE / MAXPOOL - 1) begin
            if (conv_output_x == OUTPUT_SIZE / MAXPOOL - 1) begin
                // When we have finished output, we are ready for input
                if (conv_output_idx == OUTPUT_DEPTH - 1) begin
                    in_rdy <= 1;
                    for (i=0;i<OUTPUT_DEPTH;i=i+1)
                        for (j=0;j<OUTPUT_SIZE;j=j+1)
                            for (k=0;k<OUTPUT_SIZE;k=k+1)
                                output_val[j][k][i] <= 0;
                end else begin
                    // Increment idx but reset x,y
                    temp = 0;
                    for (i=0;i<MAXPOOL;i=i+1)
                        for (j=0;j<MAXPOOL;j=j+1)
                            if (output_val[i][j][conv_output_idx + 1][31] == 0 && 
                                output_val[i][j][conv_output_idx + 1] > temp)
                                temp = output_val[i][j][conv_output_idx + 1];
                    conv_output <= temp;
                    conv_output_idx <= conv_output_idx + 1;
                    conv_output_x <= 0;
                    conv_output_y <= 0;
                end
            end else begin
                // Increment x but reset y
                temp = 0;
                for (i=0;i<MAXPOOL;i=i+1)
                    for (j=0;j<MAXPOOL;j=j+1)
                        if (output_val[MAXPOOL*conv_output_x + 1 + i][j][conv_output_idx][31] == 0 && 
                            output_val[MAXPOOL*conv_output_x + 1 + i][j][conv_output_idx] > temp)
                            temp = output_val[MAXPOOL*conv_output_x + 1 + i][j][conv_output_idx];
                conv_output <= temp;
                conv_output_y <= 0;
                conv_output_x <= conv_output_x + 1;
            end
        end else begin
            // Increment y
            for (i=0;i<MAXPOOL;i=i+1)
                for (j=0;j<MAXPOOL;j=j+1)
                    if (output_val[MAXPOOL*conv_output_x + i][MAXPOOL*conv_output_y + 1 + j][conv_output_idx][31] == 0 && 
                        output_val[MAXPOOL*conv_output_x + i][MAXPOOL*conv_output_y + 1 + j][conv_output_idx] > temp)
                        temp = output_val[MAXPOOL*conv_output_x + i][MAXPOOL*conv_output_y + 1 + j][conv_output_idx];
            conv_output <= temp;
            conv_output_y <= conv_output_y + 1;
        end
    end
end else begin // Backprop stage
    if (in_rdy == 1 && conv_input_idx != last_input_idx || conv_input_x != last_input_x || conv_input_y != last_input_y) begin
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
                            if (output_val[MAXPOOL*conv_input_x + j + l][MAXPOOL*conv_input_y + j + m][i][31] == 0 && 
                                output_val[MAXPOOL*conv_input_x + j + l][MAXPOOL*conv_input_y + j + m][i][31] > rel_val) begin
                                rel_val = output_val[MAXPOOL*conv_input_x + j + l][MAXPOOL*conv_input_y + j + m][i];
                                offset_x = l;
                                offset_y = m;
                            end
                    // To reduce confusion:
                    // conv_input_x -> output coordinate we are examining (mult. by MAXPOOL to reverse downsampling)
                    // offset_x     -> offset value determined by max pooling stage
                    // j            -> index as we iterate over the weight filter
                    // Same rules apply to conv_input_y, offset_y, and k.
                    temp = ((weights[j][k][conv_input_idx][i]*conv_input) >> 16);
                    error_val[MAXPOOL*conv_input_x + offset_x + j][MAXPOOL*conv_input_y + offset_y + k][i] <= error_val[MAXPOOL*conv_input_x + offset_y + j][MAXPOOL*conv_input_y + offset_y + k][i] + temp;

                    // Only update the weights when we output a positive value:
                    if (rel_val != 0) begin
                        temp = ((last_input[MAXPOOL*conv_input_x  + offset_x + j][MAXPOOL*conv_input_y + offset_y + k][i]*conv_input) >> 16);
                        temp = (RATE*temp) >> 16;
                        weights[j][k][conv_input_idx][i] <= weights[j][k][conv_input_idx][i] - temp;
                    end
                end
            end
        end

        if (last_in_idxbp == 1) begin
            in_rdy <= 0;
            conv_output_x <= 0;
            conv_output_y <= 0;
            conv_output_idx <= 0;
            conv_output <= error_val[0][0][0];
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
                                error_val[j][k][i] <= 0;
                end else begin
                    // Increment idx but reset x,y
                    conv_output <= error_val[0][0][conv_output_idx + 1];
                    conv_output_idx <= conv_output_idx + 1;
                    conv_output_x <= 0;
                    conv_output_y <= 0;
                end
            end else begin
                // Increment x but reset y
                conv_output <= error_val[conv_output_x + 1][0][conv_output_idx];
                conv_output_y <= 0;
                conv_output_x <= conv_output_x + 1;
            end
        end else begin
            // Increment y
            conv_output <= error_val[conv_output_x][conv_output_y + 1][conv_output_idx];
            conv_output_y <= conv_output_y + 1;
        end
    end
end
end // always

endmodule