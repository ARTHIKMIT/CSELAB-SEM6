//Write behavioral Verilog code to implement 4-bit adder/subtractor
`include "FullAdder.v"
module FourAdder (cin, x3, x2, x1, x0, y3, y2, y1, y0, s3, s2, s1, s0, cout);
input cin, x3, x2, x1, x0, y3, y2, y1, y0;
output s3, s2, s1, s0, cout;
FullAdder stage0 (cin, x0, y0, s0, c1);
FullAdder stage1 (c1, x1, y1, s1, c2);
FullAdder stage2 (c2, x2, y2, s2, c3);
FullAdder stage3 (c3, x3, y3, s3, cout);
endmodule
