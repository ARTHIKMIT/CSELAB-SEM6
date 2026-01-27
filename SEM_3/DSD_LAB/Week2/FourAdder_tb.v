//Test bench
`timescale 1ns/1ns
`include "FourAdder.v"
module FourAdder_tb ();
reg cin, x3, x2, x1, x0, y3, y2, y1, y0;
wire s3, s2, s1, s0, cout;
FourAdder l(cin, x3, x2, x1, x0, y3, y2, y1, y0, s3, s2, s1, s0, cout);
initial
begin
 $dumpfile("FourAdder_tb.vcd");
 $dumpvars(0, FourAdder_tb);
 cin = 1'b0;
 x0 = 1'b1; x1 = 1'b1; x2 = 1'b1; x3 = 1'b1; //x0 is LSB
 y0 = 1'b1; y1 = 1'b1; y2 = 1'b1; y3 = 1'b1;
 #20;
 cin = 1'b1;
 x0 = 1'b1; x1 = 1'b1; x2 = 1'b1; x3 = 1'b1;
 y0 = 1'b1; y1 = 1'b1; y2 = 1'b1; y3 = 1'b1;
 #20;
 cin = 1'b0;
 x0 = 1'b1; x1 = 1'b0; x2 = 1'b0; x3 = 1'b1;
 y0 = 1'b0; y1 = 1'b1; y2 = 1'b1; y3 = 1'b0;
 #20;
 cin = 1'b1;
 x0 = 1'b1; x1 = 1'b0; x2 = 1'b0; x3 = 1'b1;
 y0 = 1'b0; y1 = 1'b1; y2 = 1'b1; y3 = 1'b0;
 #20;
 $display("Done");
end
endmodule
