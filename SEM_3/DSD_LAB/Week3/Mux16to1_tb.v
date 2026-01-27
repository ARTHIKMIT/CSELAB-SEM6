//Test bench
`timescale 1ns/1ns
`include "Mux16to1.v"
module Mux16to1_tb ();
reg [3:0] s;
reg [15:0] w;
wire f;
Mux16to1 mu(s, w, f);
initial
begin
 $dumpfile("Mux16to1_tb.vcd");
 $dumpvars(0, Mux16to1_tb);
 w = 16'b1010101010101010;
 for (integer i=0; i<16; i++)
 begin
   {s} = i;
   #10;
 end
 $display("Done");
end
endmodule
