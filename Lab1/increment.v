'timescale 1ns / 1ps
module increment(
  input wire[15:0] a,
  output wire[15:0]sum,
  output wire overflow
);
sixteen_bit_adder_signed result(
  .a(a),
  .b(1),
  .ci(0),
  .sum(sum),
  .overflow(overflow)
);

endmodule
