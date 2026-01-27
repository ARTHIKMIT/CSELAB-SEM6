//Design 3*3 multiplier using adders and basic gates. 
//Write the Verilog code to verify the design
`include "adders.v"
module Multiplier (a, b, p);
input [2:0] a,b;
output [5:0] p;
assign p[0] = (a[0]&b[0]);

halfAdder ha1 ((b[1]&a[0]), (a[1]&b[0]), p[1], cout1);
halfAdder ha2 ((b[0]&a[2]), (a[1]&b[1]), x1, cout2);
fullAdder fa1 (x1, cout1, (b[2]&a[0]),p[2], count3);
halfAdder ha3 ((b[1]&a[2]), (a[1]&b[2]), x2, cout4);
fullAdder fa2 (x2, cout2, cout3,p[3], count5);
fullAdder fa3 ((b[2]&a[2]), cout4, cout5, p[4], p[5]);
endmodule
