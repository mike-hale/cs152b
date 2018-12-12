module softmax #(
    parameter WIDTH = 10,
    parameter IDX_WIDTH = 4,
    parameter BIT_WIDTH = 32//64
)
(
    input clk,
    input backprop_ctrl,
    input [BIT_WIDTH - 1:0] sf_input,
    input [IDX_WIDTH - 1:0] sf_input_idx,
    input start,
    input rst,
    input [IDX_WIDTH - 1:0] expected_label,
    output reg in_ready,
    output reg out_ready,
    output reg [IDX_WIDTH - 1:0] max,
    output reg max_ready,
    output reg [IDX_WIDTH - 1:0] out_idx, // USED FOR BACKPROP
    output wire [BIT_WIDTH - 1:0] out_data
    //input out_received,
);




//topmodule internal registers
reg [BIT_WIDTH - 1:0] latched_input [WIDTH-1:0];
reg [BIT_WIDTH - 1:0] latched_output [WIDTH - 1: 0];
reg done;


//State machinestuff
reg [2:0] state; // State machine to determine what computationto do
parameter IDLE  = 0; // Nothing is computationally happening. 
parameter EXP = 1; //All values for the nodes have been latched. Doing exponent calculation
parameter DIV = 2; //All values finished exponent, do division. Once done go to IDLE
parameter BACKPROP = 3; 


reg [BIT_WIDTH - 1:0] add_a, add_b, div_numerator, div_denominator, exp_x;
wire [BIT_WIDTH - 1:0] add_out, exp_out, div_out;
reg [BIT_WIDTH - 1 :0] current_summation;
reg [BIT_WIDTH + 4:0] denominator; // Maintaining the same fractional precision * 10 results in 4 additional bits for the highest case (0x7fffffff)
reg latch_add, latch_exp, start_exp, start_div, ready_exp, ready_div, latch_max;
wire done_exp, done_div, ovf_div;
reg [IDX_WIDTH - 1:0] calc_idx;
reg [BIT_WIDTH - 1:0] calc_array [WIDTH - 1:0];
reg [WIDTH - 1: 0] sec_idx;
reg latch_next_input;



assign out_data = ((out_idx) == expected_label) ? {1'b1, (31'h00008000 - latched_output[out_idx][30:0])} : latched_output[out_idx];


initial begin
     max <= 0;
     in_ready <= 1; 
     out_ready <= 0;
     state <= 0;
     calc_idx <= 0;
     sec_idx <= 0;
end



//genvar i, k;

/*
generate
    for (i = 0; i < WIDTH; i = i + 1) begin:fraction
      exp calc_numerator( latched_input[i], numerator[i], start_exp[i], done_exp[i], clk);//,dbg_inner[i]);
      // take the bottom 32 bits! Number between 0 and 1 anyway
      qdiv #(15,44) calc_out(numerator[i], denominator, start_div, clk,last_output[i],div_done[i],ovf_div[i]); 
    end

    for (i = 1; i < WIDTH; i = i + 1) begin: summation
        
    end
endgenerate 
*/


generate
  fadd #(15,BIT_WIDTH) summation_denominator(add_a, add_b,add_out);
  qdiv #(15,BIT_WIDTH + 4) calc_out(div_numerator, div_denominator, start_div, clk,div_out,done_div,ovf_div); 
  exp#(BIT_WIDTH) calc_numerator(exp_x, exp_out, start_exp, done_exp, clk);
endgenerate


always @(posedge clk) begin
    case(state)
        IDLE: begin
            in_ready <= 1;
            if (start == 1) begin
                if (backprop_ctrl == 0) begin
                  latched_input[sf_input_idx] <= sf_input; 
                  if (sf_input_idx == 0) begin // start the first exponential.
                    exp_x <= sf_input;
                    start_exp <= 1;
                  end
                  if(sf_input_idx == WIDTH-1) begin
                    state <= EXP;
                    in_ready <= 0;
                    max_ready <= 0;
                    calc_idx <= 0;
                    current_summation <= 0;
                    sec_idx <= 0;
                  end
                end else begin // Do backprop
                    state <= BACKPROP;
                    out_idx <= 0; 
                    out_ready <= 0;
                end
            end
        end
        EXP: begin // Does additions while waiting for exponents to come in
            if (ready_exp) begin
              start_exp <= 1;
              ready_exp <= 0;
            end else if(done_exp) begin
              calc_array[calc_idx] <= exp_out;
              calc_idx <= calc_idx + 1;
              exp_x <= latched_input[calc_idx];
              ready_exp <= 1;
            end else 
              start_exp <= 0;
              
            if (latch_add) begin
              latch_add <= 0;
              current_summation <= add_out;
              if (sec_idx == WIDTH - 1) begin
                state <= DIV;
                denominator <= add_out;
                calc_idx <= 0;
                sec_idx <= 0;
                max <= 0;
              end else 
                sec_idx <= sec_idx + 1;
            end else if (sec_idx != calc_idx) begin
              add_a <= current_summation; 
              add_b <= calc_array[sec_idx];
              latch_add <= 1;
            end
        end
        
        DIV: begin // do division for each term. Might as well check for max here as well
            if(ready_div) begin
              start_div <= 1; 
              ready_div <= 0;
            end else if(done_div) begin
              latched_output[calc_idx] <= div_out;
              calc_idx <= calc_idx + 1;
              div_numerator <= calc_array[calc_idx + 1];
              ready_div <= 1;
            end else 
              start_div <= 0;
              
            if (latch_max) begin
              max <= sec_idx;
              current_summation <= add_out;
              if (sec_idx == WIDTH - 1) begin
                state <= BACKPROP;
                in_ready <= 1;
              end else 
                sec_idx <= sec_idx + 1;
            end else if (sec_idx != calc_idx) begin
              if (latched_output[max] < latched_output[sec_idx]) begin
                latch_max <= 1;
              end
            end
        end


        BACKPROP: begin
            if(start == 1) begin
                if(out_idx == WIDTH-1) begin
                    state <= IDLE;
                    out_ready <= 0;
                    out_idx <= 0;
                end else begin
                    out_idx <= out_idx + 1;
       //             out_data <= ( (out_idx + 1) == expected_label) ? {1'b1, (31'h00008000 - latched_output[out_idx + 1][30:0])} : latched_output[out_idx + 1];
                    out_ready <= 1;
                end
            end else
              out_ready <= 1;
        end
    endcase

end

endmodule