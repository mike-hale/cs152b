`timescale 1ns / 1ps
module sixteen_bit_adder_signed(
  input wire [15:0] a,
  input wire [15:0] b,
  input wire ci,
  output wire[15:0] sum,
  output wire overflow);

  wire[15:0] carry;
  add_bit first_bit(
      .a(a[0]),
      .b(b[0]),
      .ci(ci),
      .sum(sum[0]),
      .co(carry[0])
    );
    //repetitive code
  generate
    for(i=1;i<16;i=i+1) begin
        addbit rest_bit(
          .a(a[i]),
          .b(b[i]),
          .ci(carry[i-1]),
          .sum(sum[i]),
          .ci(carry[i])
          );
      end
  endgenerate

  assign overflow = carry[15] & !sum[15];

endmodule
