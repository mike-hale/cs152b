module conv #(
    parameter INPUT_DEPTH = 1,
    parameter INPUT_SIZE = 28,
    parameter INPUT_IDX_WIDTH = 1,
    parameter INPUT_COORD_WIDTH = 5,
    parameter KERNEL_SIZE = 5,
    parameter STRIDE = 2,
    parameter OUTPUT_DEPTH = 8,
    parameter OUTPUT_SIZE = (INPUT_SIZE - KERNEL_SIZE) / STRIDE + 1,
    parameter OUTPUT_IDX_WIDTH = 3,
    parameter OUTPUT_COORD_WIDTH = 5
)
(
    input clk,
    input [31:0] conv_input,
    input [INPUT_IDX_WIDTH - 1:0] conv_input_idx,
    input [INPUT_COORD_WIDTH - 1:0] conv_input_x,
    input [INPUT_COORD_WIDTH - 1:0] conv_input_y,
    output reg [31:0] conv_output,
    output reg [OUTPUT_IDX_WIDTH - 1:0] conv_output_idx,
    output reg [OUTPUT_COORD_WIDTH - 1:0] conv_output_x,
    output reg [OUTPUT_COORD_WIDTH - 1:0] conv_output_y
);

reg [31:0] weights [KERNEL_SIZE - 1:0][KERNEL_SIZE - 1:0][OUTPUT_DEPTH - 1:0][INPUT_DEPTH - 1:0];
reg [31:0] last_output [OUTPUT_SIZE - 1:0][OUTPUT_SIZE - 1:0][OUTPUT_DEPTH - 1:0];
reg [31:0] temp_output [OUTPUT_SIZE - 1:0][OUTPUT_SIZE - 1:0][OUTPUT_DEPTH - 1:0];
reg [INPUT_IDX_WIDTH - 1:0] last_input_idx;
reg [INPUT_COORD_WIDTH - 1:0] last_input_x;
reg [INPUT_COORD_WIDTH - 1:0] last_input_y;
reg [47:0] temp;
reg done;
integer i,j,k,l;

initial begin
    done = 0;
    conv_output_idx = OUTPUT_DEPTH - 1;
    conv_output_x = 0;
    conv_output_y = 0;
    last_input_idx = 'hFFFF;
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
end

//Update the temporary computed value upon each input
always @(posedge clk) begin
    if (conv_input_idx != last_input_idx && conv_input_x != last_input_x && conv_input_y != last_input_y) begin
        // Update last input indices so we dont overcount inputs
        last_input_idx <= conv_input_idx;
        last_input_x <= conv_input_x;
        last_input_y <= conv_input_y;
        // On the first input move temp input to output stage and reset temp value to 0
        if (conv_input_idx == 0 && conv_input_x == 0 && conv_input_y == 0) begin
            for (i=0; i<OUTPUT_DEPTH; i=i+1) begin
                for (j=0; j<OUTPUT_SIZE; j=j+1) begin
                    for (k=0; k<OUTPUT_SIZE; k=k+1) begin
                        last_output[j][k][i] <= temp_output[j][k][i];
                        temp_output[j][k][i] = 0;
                    end
                end
            end
        end
        // Perform forward stage computation and update temp value
        for (i=0; i<OUTPUT_DEPTH; i=i+1) begin
            for (j=0; j<KERNEL_SIZE; j=j+1) begin
                for (k=0; k<KERNEL_SIZE; k=k+1) begin
                    if (conv_input_x < j || conv_input_x + j > OUTPUT_SIZE ||
                        conv_input_y < k || conv_input_y + k > OUTPUT_SIZE) begin
                        temp = ((weights[j][k][i][conv_input_idx]*conv_input) >> 16);
                        temp_output[conv_input_x + j][conv_input_y + k][i] <= temp_output[conv_input_x + j][conv_input_y + k][i] + temp;
                    end
                end
            end
        end
    end
end

//Iterate through the last computed value on the output port
always @(posedge clk) begin
    if (conv_input_idx == INPUT_DEPTH - 1 && conv_input_x == KERNEL_SIZE - 1 && conv_input_y == KERNEL_SIZE - 1)
        done = 1;
    if (conv_output_idx == OUTPUT_DEPTH - 1 && conv_output_x == OUTPUT_SIZE - 1 && conv_output_y == OUTPUT_SIZE - 1) begin
        if (done == 1) begin
            done = 0;
            conv_output  <= last_output[0][0][0];
            conv_output_idx <= 0;
            conv_output_x <= 0;
            conv_output_y <= 0;
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
end

endmodule