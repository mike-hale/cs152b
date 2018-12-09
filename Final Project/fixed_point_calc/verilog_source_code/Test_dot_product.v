module tb();

reg clk;
reg [31:0] weight;
reg [31:0] input_node;
reg [31:0] curr_out;
wire [31:0] new_out; 
wire [31:0] dbg;
partial_dot_prod uut (
    .weight(weight),
    .input_node(input_node),
    .l_output_node(curr_out),
    .output_node(new_out),
    .dbg(dbg)
);

always begin
    #1 clk = ~clk;
end

initial begin 
    $monitor ("%h,%h,%h,%h, %b, %h", weight, input_node, curr_out, new_out, clk, dbg);
    clk = 0;
    #5;
    weight = 32'h00018000;
    input_node = 32'h00010000;
    #2 curr_out = 32'h00020000;
    #2 ;
    $finish;
end

endmodule
