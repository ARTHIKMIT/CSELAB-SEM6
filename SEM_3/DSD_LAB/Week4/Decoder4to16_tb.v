//Test bench
`timescale 1ns/1ns
`include "Decoder4to16.v"
module Decoder4to16_tb ();

reg [3:0] W;
reg E;
wire [15:0] Y;

Decoder4to16 mu(W, E, Y);

initial
begin
 $dumpfile("Decoder4to16_tb.vcd");
 $dumpvars(0, Decoder4to16_tb);
 E = 1'b1;
 for (integer i=0; i<16; i++)
 begin
   {W} = i;
   #10;
 end
 $display("Done");
end
endmodule
