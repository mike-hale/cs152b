`timescale 1ns / 1ps

module sixteen_bit_subtract(
    input wire [15:0] a,
    input wire [15:0] b,
    output wire [15:0] difference,
    output wire overflow
  );
  
  sixteen_bit_adder_signed adder_signed(
    .a(a),
    .b(~b),
    .ci(1'b1),
    .sum(difference),
    .overflow(overflow)
  );

endmodule
