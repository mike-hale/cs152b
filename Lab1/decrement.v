'timescale 1ns / 1ps

module decrement(
  input wire[15:0] a,
  output wire[15:0] result,
  output wire overflow
);

sixteen_bit_subtract result(
    .a(a),
    .b(1),
    .ci(0),
    .difference(result),
    overflow(overflow)
  );
endmodule
