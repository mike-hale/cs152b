`timescale 1ns / 1ps
module sixteen_bit_adder_signed(
  input wire [15:0] a,
  input wire [15:0] b,
  input wire ci,
  output wire[16:0] out
);

  wire[15:0] sum;
  wire[16:0] carry;
  assign carry[0] = ci;
    //repetitive code
  generate 
    addbit aa(
          .a(a[0]),
          .b(b[0]),
          .ci(carry[0]),
          .sum(sum[0]),
          .co(carry[1])
          );
    addbit bb(
          .a(a[1]),
          .b(b[1]),
          .ci(carry[1]),
          .sum(sum[1]),
          .co(carry[2])
          );
    addbit c(
          .a(a[2]),
          .b(b[2]),
          .ci(carry[2]),
          .sum(sum[2]),
          .co(carry[3])
          );     
    addbit d(
          .a(a[3]),
          .b(b[3]),
          .ci(carry[3]),
          .sum(sum[3]),
          .co(carry[4])
          );  
    addbit e(
          .a(a[4]),
          .b(b[4]),
          .ci(carry[4]),
          .sum(sum[4]),
          .co(carry[5])
          );  
    addbit f(
          .a(a[5]),
          .b(b[5]),
          .ci(carry[5]),
          .sum(sum[5]),
          .co(carry[6])
          ); 
    addbit g(
          .a(a[6]),
          .b(b[6]),
          .ci(carry[6]),
          .sum(sum[6]),
          .co(carry[7])
          );  
    addbit h(
          .a(a[7]),
          .b(b[7]),
          .ci(carry[7]),
          .sum(sum[7]),
          .co(carry[8])
          );         
    addbit j(
          .a(a[8]),
          .b(b[8]),
          .ci(carry[8]),
          .sum(sum[8]),
          .co(carry[9])
          );          
    addbit k(
          .a(a[9]),
          .b(b[9]),
          .ci(carry[9]),
          .sum(sum[9]),
          .co(carry[10])
          );
    addbit l(
          .a(a[10]),
          .b(b[10]),
          .ci(carry[10]),
          .sum(sum[10]),
          .co(carry[11])
          );
    addbit m(
          .a(a[11]),
          .b(b[11]),
          .ci(carry[11]),
          .sum(sum[11]),
          .co(carry[12])
          );
    addbit n(
          .a(a[12]),
          .b(b[12]),
          .ci(carry[12]),
          .sum(sum[12]),
          .co(carry[13])
          );
    addbit o(
          .a(a[13]),
          .b(b[13]),
          .ci(carry[13]),
          .sum(sum[13]),
          .co(carry[14])
          );
    addbit p(
          .a(a[14]),
          .b(b[14]),
          .ci(carry[14]),
          .sum(sum[14]),
          .co(carry[15])
          );
    addbit q(
          .a(a[15]),
          .b(b[15]),
          .ci(carry[15]),
          .sum(sum[15]),
          .co(carry[16])
          );
  endgenerate

  assign overflow = carry[16] ^ sum[15] ^ a[15] ^ b[15];
  assign out = {overflow,sum};

endmodule
