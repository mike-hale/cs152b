module fc #(
    parameter INPUT_WIDTH = 1024,
    parameter INPUT_IDX_WIDTH = 10,
    parameter OUTPUT_WIDTH = 10,
    parameter OUTPUT_IDX_WIDTH = 4
)
(
    input clk,
    input out_rdy,
    input [31:0] fc_input,
    input [INPUT_IDX_WIDTH - 1:0] fc_input_idx,
    output in_rdy,
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
reg sending;
integer i,j;

assign in_rdy = (sending == 0) || (fc_input_idx != INPUT_WIDTH - 1);

initial begin
    sending = 0;
    fc_output_idx = OUTPUT_WIDTH - 1;
    last_input_idx = INPUT_WIDTH - 1;
    fc_output = 32'b0;
    for (i=0;i<OUTPUT_WIDTH;i=i+1)
        temp_output[i] = 0;
end

// Updates temp_output based on incoming inputs.
// Once the input index overflows to 0, update the last_output
// and reset temp_output
always @(posedge clk) begin
    if (fc_input_idx != last_input_idx) begin
        last_input_idx <= fc_input_idx;
        for (i=0; i<OUTPUT_WIDTH; i=i+1) begin
            temp = ((weights[i][fc_input_idx]*fc_input) >> 16);
            temp_output[i] <= temp_output[i] + temp;
            // Forward output when we can send immediately
            if (fc_input_idx == INPUT_WIDTH - 1 && sending == 0 && out_rdy == 1) begin
                if (i == 0)
                    fc_output <= temp_output[0] + temp;
                sending <= 1;
                fc_output_idx <= 0;
                last_output[i] <= temp_output[i] + temp;
                temp_output[i] <= 0;
            end
        end
    end else if (fc_input_idx == INPUT_WIDTH - 1 && fc_output_idx == OUTPUT_WIDTH - 1) begin
        fc_output_idx <= 0;
        fc_output <= temp_output[0];
        sending <= 1;
        for (i=0; i<OUTPUT_WIDTH; i=i+1) begin
            last_output[i] <= temp_output[i];
            temp_output[i] <= 0;
        end 
    end

    if (sending == 1) begin
        if (fc_output_idx == OUTPUT_WIDTH - 2) begin
            // If we are stalling the input
            sending <= 0;
            fc_output_idx <= OUTPUT_WIDTH - 1;
            fc_output <= last_output[OUTPUT_WIDTH - 1];
        end else if (fc_output_idx < OUTPUT_WIDTH - 2) begin
            fc_output_idx <= fc_output_idx + 1;
            fc_output <= last_output[fc_output_idx + 1];
        end
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