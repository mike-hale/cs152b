module conv #(
    parameter INPUT_DEPTH = 1,
    parameter INPUT_SIZE = 13,
    parameter IDX_WIDTH = 3,
    parameter COORD_WIDTH = 5,
    parameter KERNEL_SIZE = 5,
    parameter STRIDE = 2,
    parameter OUTPUT_DEPTH = 8,
    parameter OUTPUT_SIZE = (INPUT_SIZE - KERNEL_SIZE) / STRIDE + 1
)
(
    input clk,
    input out_rdy,
    input forward,
    input [31:0] conv_input,
    input [IDX_WIDTH - 1:0] conv_input_idx,
    input [COORD_WIDTH - 1:0] conv_input_x,
    input [COORD_WIDTH - 1:0] conv_input_y,
    output in_rdy,
    output reg [31:0] conv_output,
    output reg [IDX_WIDTH - 1:0] conv_output_idx,
    output reg [COORD_WIDTH - 1:0] conv_output_x,
    output reg [COORD_WIDTH - 1:0] conv_output_y
);

parameter RATE = {'16b0,'16d3277}; // Approx 0.05

reg [31:0] weights [KERNEL_SIZE - 1:0][KERNEL_SIZE - 1:0][OUTPUT_DEPTH - 1:0][INPUT_DEPTH - 1:0];
reg [31:0] last_input [INPUT_SIZE - 1:0][INPUT_SIZE - 1:0][INPUT_DEPTH - 1:0];
reg [31:0] last_output [OUTPUT_SIZE - 1:0][OUTPUT_SIZE - 1:0][OUTPUT_DEPTH - 1:0];
reg [31:0] temp_output [OUTPUT_SIZE - 1:0][OUTPUT_SIZE - 1:0][OUTPUT_DEPTH - 1:0];
reg [31:0] temp_error [INPUT_SIZE - 1:0][INPUT_SIZE - 1:0][INPUT_DEPTH - 1:0];
reg [INPUT_IDX_WIDTH - 1:0] last_input_idx;
reg [INPUT_COORD_WIDTH - 1:0] last_input_x;
reg [INPUT_COORD_WIDTH - 1:0] last_input_y;
reg [47:0] temp;
reg sending;
wire last_in_idx, last_out_idx;
wire last_in_idxbp, last_out_idxbp;
integer i,j,k,l;

assign last_in_idx = conv_input_idx == INPUT_DEPTH - 1 && conv_input_x == INPUT_SIZE - 1 && conv_input_y == INPUT_SIZE - 1;
assign last_out_idx = conv_output_idx == OUTPUT_DEPTH - 1 && conv_output_x == OUTPUT_SIZE - 1 && conv_output_y == OUTPUT_SIZE - 1;
assign last_in_idxbp = conv_input_idx == OUTPUT_DEPTH - 1 && conv_input_x == OUTPUT_SIZE - 1 && conv_input_y == OUTPUT_SIZE - 1;
assign last_out_idxbp = conv_output_idx == INPUT_DEPTH - 1 && conv_output_x == INPUT_SIZE - 1 && conv_output_y == INPUT_SIZE - 1;
assign in_rdy = (sending == 0) || !last_in_idx;

initial begin
    sending = 0;
    conv_output_idx = OUTPUT_DEPTH - 1;
    conv_output_x = OUTPUT_SIZE - 1;
    conv_output_y = OUTPUT_SIZE - 1;
    last_input_idx = INPUT_DEPTH - 1;
    last_input_x = INPUT_SIZE - 1;
    last_input_y = INPUT_SIZE - 1;
    conv_output = 32'b0;
    for (i=0;i<KERNEL_SIZE;i=i+1) begin
        for (j=0;j<KERNEL_SIZE;j=j+1) begin
            for (k=0;k<OUTPUT_DEPTH;k=k+1) begin
                for (l=0;l<INPUT_DEPTH;l=l+1) begin
                    weights[i][j][k][l] = i*j*k*l;
                end
            end
        end
    end
    for (i=0;i<OUTPUT_DEPTH;i=i+1)
        for (j=0;j<OUTPUT_SIZE;j=j+1)
            for (k=0;k<OUTPUT_SIZE;k=k+1)
                temp_output[j][k][i] = 0;
    for (i=0;i<INPUT_DEPTH;i=i+1)
        for (j=0;j<INPUT_SIZE;j=j+1)
            for (k=0;k<INPUT_SIZE;k=k+1)
                temp_error[j][k][i] = 0;
end

//Update the temporary computed value upon each input
always @(posedge clk) if(forward == 1) begin
    if (conv_input_idx != last_input_idx || conv_input_x != last_input_x || conv_input_y != last_input_y) begin
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
                        temp_output[conv_input_x - j][conv_input_y - k][i] <= temp_output[conv_input_x - j][conv_input_y - k][i] + temp;
                    end
                end
            end
        end
    end

    if (last_in_idx == 1 && sending == 0 && out_rdy == 1) begin
        sending <= 1;
    end

    // If we are done outputting previous computation
    if (sending == 1) begin
        if (last_out_idx == 1 && out_rdy == 1) begin
            conv_output <= temp_output[0][0][0];
            conv_output_idx <= 0;
            conv_output_x <= 0;
            conv_output_y <= 0;
            for (i=0;i<OUTPUT_DEPTH;i=i+1) begin
                for (j=0;j<OUTPUT_SIZE;j=j+1) begin
                    for (k=0;k<OUTPUT_SIZE;k=k+1) begin
                        last_output[j][k][i] <= temp_output[j][k][i];
                        temp_output[j][k][i] <= 0;
                    end
                end
            end
        end else begin
            if (conv_output_y == OUTPUT_SIZE - 1) begin
                if (conv_output_x == OUTPUT_SIZE - 1) begin
                    conv_output <= last_output[0][0][conv_output_idx + 1];
                    conv_output_idx <= conv_output_idx + 1;
                    conv_output_x <= 0;
                    conv_output_y <= 0;
                end else begin
                    conv_output <= last_output[conv_output_x + 1][0][conv_output_idx];
                    conv_output_y <= 0;
                    conv_output_x <= conv_output_x + 1;
                end
            end else begin
                conv_output <= last_output[conv_output_x][conv_output_y + 1][conv_output_idx];
                conv_output_y <= conv_output_y + 1;
            end
        end
        // Second to last index we set sending to zero
        if (conv_output_idx == OUTPUT_DEPTH - 1 && conv_output_x == OUTPUT_SIZE - 1 && conv_output_y == OUTPUT_SIZE - 2)
            sending <= 0;
    end
end else begin // Backprop stage
    if (conv_input_idx != last_input_idx || conv_input_x != last_input_x || conv_input_y != last_input_y) begin
        // Update last input indices so we dont overcount inputs
        last_input_idx <= conv_input_idx;
        last_input_x <= conv_input_x;
        last_input_y <= conv_input_y;
        
        for (i=0; i<INPUT_DEPTH; i=i+1) begin 
            for (j=0; j<KERNEL_SIZE; j=j+1) begin
                for (k=0; k<KERNEL_SIZE; k=k+1) begin                                       
                    temp = ((weights[j][k][conv_input_idx][i]*conv_input) >> 16);
                    temp_error[conv_input_x + j][conv_input_y + k][i] <= temp_error[conv_input_x + j][conv_input_y + k][i] + temp;
                    temp = ((last_input[conv_input_x + j][conv_input_y + k][i]*conv_input) >> 16);
                    temp = (RATE*temp) >> 16;
                    weights[j][k][conv_input_idx][i] <= weights[j][k][conv_input_idx][i] - temp;
                end
            end
        end
    end

    if (last_in_idxbp == 1 && sending == 0 && out_rdy == 1) begin
        sending <= 1;
    end

    if (sending == 1) begin
        if (last_out_idxbp == 1 && out_rdy == 1) begin
            conv_output <= temp_error[0][0][0];
            conv_output_idx <= 0;
            conv_output_x <= 0;
            conv_output_y <= 0;
        end else begin
            if (conv_output_y == INPUT_SIZE - 1) begin
                if (conv_output_x == INPUT_SIZE - 1) begin
                    conv_output <= temp_error[0][0][conv_output_idx + 1];
                    conv_output_idx <= conv_output_idx + 1;
                    conv_output_x <= 0;
                    conv_output_y <= 0;
                end else begin
                    conv_output <= temp_error[conv_output_x + 1][0][conv_output_idx];
                    conv_output_y <= 0;
                    conv_output_x <= conv_output_x + 1;
                end
            end else begin
                conv_output <= temp_error[conv_output_x][conv_output_y + 1][conv_output_idx];
                conv_output_y <= conv_output_y + 1;
            end
        end
        // Second to last index we set sending to zero
        if (conv_output_idx == INPUT_DEPTH - 1 && conv_output_x == INPUT_SIZE - 1 && conv_output_y == INPUT_SIZE - 2) begin
            sending <= 0;
            for (i=0;i<INPUT_DEPTH;i=i+1)
                for (j=0;j<INPUT_SIZE;j=j+1)
                    for (k=0;k<INPUT_SIZE;k=k+1) 
                        temp_error[j][k][i] <= 0;
        end



endmodule