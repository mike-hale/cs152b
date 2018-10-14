module debouncer(
input button,
input clk,
output reg deb
);

always @(posedge clk) begin
  deb <= button;
end

endmodule
