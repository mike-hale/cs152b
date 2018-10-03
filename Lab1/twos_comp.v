'timescale 1ns / 1ps

module twos_comp(
  input wire[15:0] a,
  output wire[15:0] out_a,
  output wire overflow
  );
  wire [15:0] flipped;
  assign flipped = !a;
  add_bit first_bit(
    .a(flipped),
    .b(1),
    .ci(0),
    .sum(out_a),
    .co(overflow)
    )
