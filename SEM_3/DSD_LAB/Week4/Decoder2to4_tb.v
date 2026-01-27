//Test bench
`timescale 1ns/1ns
`include "Decoder2to4.v"
module Decoder2to4_tb ();
reg [1:0] W;
reg E;
wire [3:0] Y;
Decoder2to4 mu(W, E, Y);
initial
begin
 $dumpfile("Decoder2to4_tb.vcd");
 $dumpvars(0, Decoder2to4_tb);
 E = 1'b0;
 for (integer i=0; i<4; i++)
 begin
   {W} = i;
   #10;
 end
 
 $display("Done");
end
endmodule
