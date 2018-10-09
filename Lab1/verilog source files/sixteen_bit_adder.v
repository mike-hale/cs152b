`timescale 1ns / 1ps
module sixteen_bit_adder_signed(
  input wire [15:0] a,
  input wire [15:0] b,
  input wire ci,
  output wire[16:0] out
);

  wire[15:0] sum;
  wire[16:0] carry;
  
  addbit one_bit_adders[15:0](a,b,carry[15:0],sum,carry[16:1]);

  assign carry[0] = ci;
  assign overflow = (~sum[15] & a[15] & b[15]) || (sum[15] & ~a[15] & ~b[15]);
  assign out = {overflow,sum};

endmodule
