`timescale 1ns / 1ps

module sixteen_bit_subtract(
    input wire [15:0] a,
    input wire [15:0] b,
    input wire ci,
    output wire [15:0] difference,
    output wire overflow
  );
  wire[15:0] flipped_b;
  wire overflow_twoscomp;
  twos_comp flip_b(
    .a(b),
    .out_a(flipped_b),
    .overflow(overflow_twoscomp)
  );
  wire overflow_add;
  sixteen_bit_adder_signed(
    .a(a),
    .b(flipped_b),
    .ci(ci),
    .sum(difference),
    .overflow(overflow_add)
  );

  assign overflow = overflow_add | overflow_twoscomp;
endmodule
