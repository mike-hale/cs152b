module fc #(
    parameter INPUT_WIDTH = 1024,
    parameter INPUT_IDX_WIDTH = 10,
    parameter OUTPUT_WIDTH = 10,
    parameter OUTPUT_IDX_WIDTH = 4
)
(
    input clk,
    input [31:0] fc_input,
    input [INPUT_IDX_WIDTH - 1:0] fc_input_idx,
    output reg [31:0] fc_output,
    output reg [OUTPUT_IDX_WIDTH - 1:0] fc_output_idx
//    input [9:0] in_dbg,
//    output [31:0] o_dbg
);

/* Assuming fixed point number has sixteen bits before
   and after the decimal place */

reg [31:0] weights [OUTPUT_WIDTH - 1:0] [INPUT_WIDTH - 1:0];
reg [31:0] last_output [OUTPUT_WIDTH - 1:0];
reg [31:0] temp_output [OUTPUT_WIDTH - 1:0];
reg [INPUT_IDX_WIDTH - 1:0] last_input_idx;
reg [47:0] temp;
reg done;
integer i,j;

//assign o_dbg = weights[in_dbg][1];

initial begin
    done = 0;
    fc_output_idx = OUTPUT_WIDTH - 1;
    last_input_idx = 'hFFFF;
    fc_output = 32'b0;
end

// Updates temp_output based on incoming inputs.
// Once the input index overflows to 0, update the last_output
// and reset temp_output
always @(posedge clk) begin
    if (fc_input_idx != last_input_idx) begin
        last_input_idx <= fc_input_idx;
        if (fc_input_idx == 0) begin
            for (i=0; i<OUTPUT_WIDTH; i=i+1) begin
                last_output[i] <= temp_output[i];
            end
            for (i=0; i<OUTPUT_WIDTH; i=i+1) begin
                temp = ((weights[i][fc_input_idx]*fc_input) >> 16);
                temp_output[i] <= temp;
            end
        end else begin
            for (i=0; i<OUTPUT_WIDTH; i=i+1) begin
                temp = ((weights[i][fc_input_idx]*fc_input) >> 16);
                temp_output[i] <= temp_output[i] + temp;
            end
        end
    end
end

// Iterates through the output indices
always @(posedge clk) begin
    if (fc_input_idx == INPUT_WIDTH - 1)
        done = 1;
    if (fc_output_idx == OUTPUT_WIDTH - 1) begin
        if (done == 1) begin
            done = 0;
            fc_output <= last_output[0];
            fc_output_idx <= 'b0;
        end
    end else begin
        fc_output <= last_output[fc_output_idx + 1];
        fc_output_idx <= fc_output_idx + 1;
    end
end

initial begin
    for (i=0; i<OUTPUT_WIDTH; i=i+1) begin
        last_output[i] = 32'b0;
        temp_output[i] = 32'b0;
        for (j=0; j<INPUT_WIDTH; j=j+1) begin
            weights[i][j] = i*j << 10;
        end
    end
end

endmodule