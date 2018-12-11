//Combinational logic to product partil dot product using current index
module partial_dot_prod (
    input [31:0] weight,
    input [31:0] input_node,
    input [31:0] l_output_node,
    output [31:0] output_node,
    output [31:0] dbg
);

wire [31:0] prod_to_sum;
wire [31:0] poss_output_node;
wire ovf;
qmult#(15,32) prod(
    .i_multiplier(weight),
    .i_multiplicand(input_node),
    .o_result(prod_to_sum),
    .ovr(ovf)
);

qadd#(15,32) sum_of_prod(
    .a(prod_to_sum),
    .b(l_output_node),
    .c(poss_output_node)
);
assign dbg = prod_to_sum;
assign output_node = ovf ? 32'hFFFF :  poss_output_node;

endmodule