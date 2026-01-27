`include "Mux8to1.v"
`include "Mux2to1.v"
module Mux16to1 (s, w, f);
input [3:0] s;
input [15:0] w;
output f;
wire g, h, i;
Mux8to1 m1(s[2:0], w[7:0], g);
Mux8to1 m2(s[2:0], w[15:8], h);
Mux2to1 m3(g, h, s[3], f);
//assign f=i;
endmodule
