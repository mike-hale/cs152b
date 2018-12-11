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


    parameter NUM_TERMS = 5;
    reg [31:0] latch_x;

    initial latch_x = 0;
    wire ovf_int;

    genvar i; 
    integer j;

    
    /*int_part */
    reg [31:0] e_int;
    wire [15:0] latch_int;
    assign latch_int = latch_x[30:15];
    reg [31:0] int_count;
    wire [31:0] exp_temp;
    wire [31:0] y_temp;
    reg int_done;
    initial int_done = 1;

 
    /* Fractional calculation */
    wire [14:0] latch_frac;
    assign latch_frac = latch_x[14:0];
    reg [31:0] frac_exp;
    reg polynomial_done;

    reg  [31:0] numerator [NUM_TERMS - 1:0];
   // reg [31:0] sum_items[NUM_TERMS - 1:0]; 
    reg [31:0] compute_out;

    parameter e = 32'h00015bf0;
    parameter [(32*NUM_TERMS)-1: 0] denominator = {32'h003c0000, 32'h00c0000, 32'h00030000, 32'h00010000, 32'h000008000};
    reg [31:0] num_a, num_b, div_a,  div_b,  add_a, add_b,  sum;
    wire [31:0] num_out, div_out, add_out;
    wire complete_frac, ovf_frac, ovf_mult;
    reg start_frac, ready;
    reg [2:0] polynomial_ctr, numerator_ctr; 
    reg start_latches,latch_to_int, latch_sum, latch_combine, latch_mult;
    generate
    fmult calc_num(num_a, num_b, num_out, ovf_mult);
    qdiv calc_frac(div_a, div_b, start_frac, clk, div_out, complete_frac, ovf_frac);
    fadd sum_terms(add_a, add_b, add_out);
    endgenerate


    //State machine
    reg [1:0] state; 
    parameter IDLE = 0;
    // Checks if x = 0 or x > 11 (latches y respectively based off of sign. if neg, returns 0x0 )
    // Also determines whether there's a calculation needed for both fraction and integer portion. 
    parameter LATCH = 1;
    // Does integer calculation and also checks if fraction portion is done. Returns to idle or neg
    parameter CALC = 2; 
    parameter COMBINE = 3; //Combine taylor polynomial and integer calculations

    initial state = IDLE;
    assign done = (state == IDLE);

    //assign dbg = int_done;
    //assign dbg2 = latch_int;
    //assign dbg3 = int_count;
    reg no_taylor_compute;
    initial no_taylor_compute = 0;
    always @(posedge clk)begin
        case(state)
        IDLE: begin
            if(start == 1) begin
                latch_x <= x; // fractional part extracts latch_x via wire
                state <= LATCH;
            end
        end

   
        LATCH: begin
            if (latch_int > 11) begin
                y <= 32'h7FFFFFFF; 
                state <= IDLE; 
            end else begin // Go to calc stage cus no underflow/overflow
                if ( |latch_int ) begin //Check if integer calculations needed. (if any bits are 1)
                    int_done <= 0;
                    e_int <= 32'h00008000; // reset product register to 1
                    int_count <= 0;
                end else begin
                    e_int <= 32'h0008000;
                    int_done <= 1;
                end
                if (|latch_frac) begin //Check for fractional calculations needed. (if any bits are 1)
                   //Reduce for(j = 0; j < NUM_TERMS; j = j + 1)
                   //         start_div[j] <= 1; //start taylor polynomial
                    polynomial_done <= 0;
                end else
                    polynomial_done <= 1;
                start_latches <= 0;
                state <= ( (|latch_int) | (|numerator[0])) ? CALC : IDLE; 
            end
        end
    
    
        CALC: begin 
          if (start_latches == 1) begin
            if (ready) begin // input values latched. Start division
                start_frac <= 1;
                ready<= 0;
            end else if (complete_frac == 1 && numerator_ctr >= polynomial_ctr & ~start_frac) begin //Handle latch of division
              //sum = div_out + sum
              add_a <= sum;
              add_b <= div_out;
              latch_sum <= 1;
              if (polynomial_ctr == NUM_TERMS) // Already did last polynomial.
                polynomial_done <= 1; //
              else if (~ready) begin
                div_a <= numerator[polynomial_ctr];
                div_b <= denominator[32 * polynomial_ctr +: 32]; 
                ready <= 1;
                polynomial_ctr <= polynomial_ctr + 1;
              end
            end else
              start_frac <= 0; //Don't want to redo another division!
              //Handle multiplication. Give priority to taylor polynomials first
              if(~latch_to_int) begin //Latch multiplier result to fractional part
                if (latch_mult) begin
                  numerator[numerator_ctr] <= num_out;
                  latch_mult <= 0;
                end else if (numerator_ctr < NUM_TERMS) begin 
                  num_a <= latch_frac;
                  num_b <= numerator[numerator_ctr];
                  numerator_ctr <= numerator_ctr + 1;
                  latch_mult <= 1;
                end else begin
                  latch_to_int <= 1;
                  latch_mult <= 0;
                end
              end else begin // Give this to integer portion
                if (latch_mult) begin
                  e_int <= num_out;
                  int_count <= int_count+1;
                  latch_mult <= 0;
                end else if(int_count < latch_int) begin
                  num_a <= e_int;
                  num_b <= e;
                  latch_mult <= 1;
                //again what to do with product?
                end else
                  int_done <= 1;
              end
          end else begin//Initialize division, multiplier, and summation
            //For multiplier 
            numerator[0] <= latch_frac; // give multiplier to frac part.
            num_a <= latch_frac; // Do frac^2. 
            num_b <= latch_frac;
            latch_to_int <= 0;
            numerator_ctr <= 1;
            latch_mult <= 1;
            int_count <= 0;
            
            //For division
            div_a <= latch_frac;
            div_b <= denominator[31:0]; 
            start_frac <= 1;
            polynomial_ctr <= 1;
            ready <= 0;
            
            //For summation of polynomial terms
            sum <= 32'h00008000;
            add_a<= 0;
            add_b <= 0;
            latch_sum <= 0;
            
            start_latches <= 1; //Init done
          end
          
          if (latch_sum)
            sum <= add_out;
          if (int_done & polynomial_done)begin
                  state <= COMBINE;
                  latch_combine <= 0;
          end
        end
        COMBINE: begin // Multiple the two together
          num_a <=  e_int;
          num_b <= sum;
          latch_combine <= 1;
          if(latch_combine)
            y <= num_out;
            state <= IDLE;
        end
        endcase
    end
endmodule