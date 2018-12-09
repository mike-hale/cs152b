module softmax #(
    parameter WIDTH = 10,
    parameter IDX_WIDTH = 4
)
(
    input clk,
    input backprop_ctrl,
    input [31:0] sf_input,
    input [IDX_WIDTH - 1:0] sf_input_idx,
    input start,
    input rst,
    output reg in_ready,

    output reg [IDX_WIDTH - 1:0] max,
    output reg out_ready,
    input out_received,

    output [31:0] dbg, 
    output [31:0] dbg2,
    output [31:0] dbg3,
    output [31:0] dbg4
);

wire [31:0] dbg_inner[WIDTH-1:0];



//topmodule internal registers
reg [31:0] latch_input [WIDTH-1:0];
wire [31:0] last_output [WIDTH - 1:0]; 
reg [31:0] sf_output [WIDTH - 1: 0];
reg done;


//State machinestuff
reg [2:0] state; // State machine to determine what computationto do
parameter IDLE  = 0; // Nothing is computationally happening. 
parameter EXP = 1; //All values for the nodes have been latched. Doing exponent calculation
parameter SUM = 2; // Sum up values to make divisor
parameter DIV = 3; //All values finished exponent, do division. Once done go to IDLE
parameter MAX = 4; // Checks the maximum value. Could probably be absorved into the IDLE stage



//exp module I/O and control registers
reg [WIDTH-1:0] start_exp;
wire [WIDTH-1:0] done_exp;
wire [31:0] numerator[WIDTH - 1:0];

//summation I/O and control registers
wire [31:0] current_summation [WIDTH-1:0];
assign current_summation[0] = numerator[0];
reg [43:0] denominator; // SHOULD NOT OVERFLOW ANYMORE BIIIATCH. highest numerator number is 4 bytes. Maintaining the same fractional precision 


// division I/O and control registers
reg [31:0] exp_sum [WIDTH-1:0];
reg start_div;
wire [WIDTH-1:0] div_done;
wire ovf_div[WIDTH-1:0];
reg [WIDTH - 1:0] last_input_idx;
integer j;

//counter used in MAX Stage
reg[IDX_WIDTH-1:0] max_count;
reg[31:0] max_num;



initial begin
     max = 0;
     in_ready = 1;
end


genvar i;
generate
    for (i = 0; i < WIDTH; i = i + 1) begin
      exp calc_numerator( latch_input[i], numerator[i], start_exp[i], done_exp[i], clk,dbg_inner[i]);
      // take the bottom 32 bits! Number between 0 and 1 anyway
      qdiv #(15,44) calc_out(numerator[i], denominator, start_div, clk,last_output[i],div_done[i],ovf_div[i]); 
    end

    for (i = 1; i < WIDTH; i = i + 1)
        qadd summation_denominator(numerator[i], current_summation[i-1],current_summation[i]);
endgenerate 

reg test;
assign dbg = state;
assign dbg2 = latch_input[0];
assign dbg3 = numerator[0];
assign dbg4 = current_summation[0];

always @(posedge rst) begin
    max = 0; 
    in_ready = 0;
    state = IDLE;
end

always @(posedge clk) begin
    case(state)
        IDLE: begin
            in_ready <= 1;
            latch_input[sf_input_idx] <= sf_input; 
            start_exp[sf_input_idx] <= 1;
            if (&start_exp) begin // all inputs have started exp
                in_ready <= 0;
                state <= EXP;
            end
        end

        EXP: begin
            for (j = 0; j < WIDTH; j = j + 1) begin
                start_exp[j] <= 0;
            end
            if (&done_exp & ~&start_exp) begin
                state <= SUM;
            end
        end
        SUM: begin
            denominator <= current_summation[WIDTH - 1];
            state <= DIV;
            start_div <= 1;
        end
        DIV: begin
            start_div <= 0;
            if(&div_done & ~start_div) begin
                max <= 0;
                max_count <= 0;
                state <= MAX;    
            end
            
        end

        MAX: begin
            if(max_count == WIDTH)
                out_ready <= 1;
            else begin
                if (last_output[max] < last_output[max_count])
                    max <= max_count;
                else 
                    test <= 0;
                max_count <= max_count + 1;
            end
            if(out_received) begin
                state <= IDLE;
                in_ready <= 1;
                out_ready <= 0;
            end
        end
    endcase

end

endmodule