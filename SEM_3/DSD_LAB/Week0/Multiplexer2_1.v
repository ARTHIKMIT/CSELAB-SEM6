// 2:1 Multiplexer Design
module Multiplexer2_1(s0, x1, x2, f);
input s0, x1, x2;
output f;
if s0 == 0:
assign (f, x1);
if s0 == 1:
assign (f, x2);
endmodule
