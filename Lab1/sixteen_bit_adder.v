`timescale 1ns / 1ps
module sixteen_bit_adder_signed(
  input wire [15:0] a,
  input wire [15:0] b,
  input wire ci,
  output wire[15:0] sum,
  output wire overflow);

  wire[16:0] carry;
  assign carry[0] = ci;
    //repetitive code
  generate
    genvar i;
    for(i=0;i<16;i=i+1) begin
        addbit rest_bit(
          .a(a[i]),
          .b(b[i]),
          .ci(carry[i]),
          .sum(sum[i]),
          .co(carry[i+1])
          );
      end
  endgenerate

  assign overflow = carry[16] ^ sum[15];

endmodule
