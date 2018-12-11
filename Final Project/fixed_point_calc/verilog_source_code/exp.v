//Implements e^x using taylor polynomial approximation
module exp(
    input [31:0] x,
    output reg [31:0] y,

    input start,
    output done,
    input clk
    
   // output [31:0] dbg,
    //output [31:0] dbg2,
    //output [31:0] dbg3  
);
    assign done = (state == IDLE);


    parameter NUM_TERMS = 6;
    reg [31:0] latch_x;

    wire [31:0] numerator [NUM_TERMS - 1:0];
    wire [31:0] next_factorial_num [NUM_TERMS-1:0];
    wire [31:0] denominator [NUM_TERMS-1:0];
    wire [31:0] sum_items[NUM_TERMS - 1:0]; 
    wire [31:0] compute_out[NUM_TERMS - 1:0];

    wire ovf_mult[NUM_TERMS - 1:0], ovf_div[NUM_TERMS - 1:0], ovf_add, ovf_den[NUM_TERMS - 1:0], ovf_exp_int; 
    wire [NUM_TERMS-1:0] complete; 
    reg [NUM_TERMS-1:0] start_div;
    initial latch_x = 0;
    wire ovf_int;

    genvar i; 
    integer j;

    
    /*int_part */
    reg [31:0] e_int;
    reg [15:0] latch_int;
    reg [31:0] int_count;
    wire [31:0] exp_temp;
    wire [31:0] y_temp;
    reg int_done;
    initial int_done = 1;

    /*For reciprocating qdiv from negative */
    wire ovf_neg, complete_neg;
    reg start_neg;
    wire [31:0] out_neg;
    wire sign; 
    assign sign = latch_x[31];

    /* Fractional calculation */
    reg [31:0] frac_exp;
    reg frac_done;
    assign numerator[0] = {16'h0000,latch_x[14:0]};
    assign denominator[0] = 32'h00008000;
    assign next_factorial_num[0] = 32'h00008000;
    assign compute_out[0] = 32'h00008000;
    
    wire [31:0] summed_taylor_polynomials = (|numerator[0]) ? compute_out[5] : 32'h00008000;  //conditional needed to see if division was used or not. 


    generate
    //build denominator and numerator and sum up
    fmult integer_calc(e_int, 32'h00015bf0, exp_temp, ovf_int);
    fmult frac_and_int(e_int, summed_taylor_polynomials, y_temp, ovf_exp_int);

    for (i = 1; i < NUM_TERMS; i = i + 1) begin: gen_polynomial_fractions
        fmult num(numerator[i-1], numerator[0], numerator[i], ovf_mult[i]);
        fadd fact(next_factorial_num[i-1], 32'h00008000, next_factorial_num[i]);
        fmult denom(denominator[i-1], next_factorial_num[i], denominator[i], ovf_den[i]);
        fadd sum_terms(compute_out[i-1], sum_items[i-1], compute_out[i]);
    end
    //divide to make taylor polynomials
    for(i = 0; i < NUM_TERMS; i = i + 1) begin: compute_fractions
        qdiv compute_fractions(numerator[i], denominator[i], start_div[i], clk, sum_items[i], complete[i], ovf_div[i]);
    end

    //if x is negative, must do 1/(e^x)
    qdiv reciprocate(32'h00008000, y_temp, start_neg, clk, out_neg, complete_neg, ovf_neg);
    endgenerate


    //State machine
    reg [1:0] state; 
    parameter IDLE = 0;
    // Checks if x = 0 or x > 11 (latches y respectively based off of sign. if neg, returns 0x0 )
    // Also determines whether there's a calculation needed for both fraction and integer portion. 
    parameter LATCH = 1;
    // Does integer calculation and also checks if fraction portion is done. Returns to idle or neg
    parameter CALC = 2; 
    parameter NEG = 3; //reciprocate.

    initial state = IDLE;

    assign dbg = int_done;
    assign dbg2 = latch_int;
    assign dbg3 = int_count;
    reg no_taylor_compute;
    initial no_taylor_compute = 0;
    always @(posedge clk)begin
        case(state)
        IDLE: begin
            if(start == 1) begin
                latch_x <= x; // fractional part extracts latch_x via wire
                latch_int <= x[30:15]; 
                state <= LATCH;
            end
        end

        LATCH: begin
            if (latch_int > 11) begin
                if (sign == 1) begin
                    y <= 0; 
                end else 
                    y <= 32'h7FFFFFFF; 
                state <= IDLE; 
            end else begin // Go to calc stage cus no underflow/overflow
                if ( |latch_int ) begin //Check if integer calculations needed. (if any bits are 1)
                    int_done <= 0;
                    e_int <= 32'h00008000; // reset product register
                    int_count <= 0;
                end else begin
                    e_int <= 32'h0008000;
                    int_done <= 1;
                end
                if (|numerator[0]) begin //Check for fractional calculations needed. (if any bits are 1)
                    for(j = 0; j < NUM_TERMS; j = j + 1)
                            start_div[j] <= 1; //start taylor polynomial
                    frac_done <= 0;
                end else
                    frac_done <= 1;
                state <= ( (|latch_int) | (|numerator[0])) ? CALC : IDLE; 
            end
        end

        CALC: begin
            for(j = 0; j < NUM_TERMS; j = j + 1) begin
                start_div[j] <= 0;
            end
            if (int_done == 0) begin
                if(int_count != latch_int) begin
                    e_int <= exp_temp;
                    int_count <= int_count + 1;
                end else if (int_count == latch_int)
                    int_done <= 1;
            end
            if (&complete & ~|start_div)
                frac_done <= 1;
            if (int_done & frac_done)begin
                if(sign == 1) begin 
                    state <= NEG;
                    start_neg <= 1;
                end else begin
                    y <= y_temp;
                    state <= IDLE;
                end
            end
        end

        NEG: begin
                start_neg <= 0;
                if (complete_neg & ~start_neg) begin
                    y <= out_neg;
                    state <= IDLE;
                end
        end
        endcase
    end
endmodule