//Test bench
`timescale 1ns/1ns
`include "Multiplier.v"
module Multiplier_tb ();
reg [2:0] a,b;
wire [5:0] p;
Multiplier mu(a, b, p);
initial
begin
 $dumpfile("Multiplier_tb.vcd");
 $dumpvars(0, Multiplier_tb);
 a[2] = 1'b1; a[1] = 1'b1; a[0] = 1'b0; //a[2] is LSB 110 = 6
 b[2] = 1'b1; b[1] = 1'b0; b[0] = 1'b1; //101 = 5
 #20;
 a[0] = 1'b1; //111
 b[1] = 1'b1; //111
 #20;
 $display("Done");
end
endmodule
