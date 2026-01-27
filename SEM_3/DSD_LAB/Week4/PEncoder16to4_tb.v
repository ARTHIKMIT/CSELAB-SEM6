`timescale 1ns/1ns
`include "PEncoder16to4.v"
module PEncoder16to4_tb ();
  reg [15:0] D;
  wire [3:0] B;
  wire Z;
  PEncoder16to4 mu(D, B, Z);
initial
begin
  $dumpfile("PEncoder16to4_tb.vcd");
  $dumpvars(0, PEncoder16to4_tb);
  D = 16'b0000000000000001; 
  #5;
  D = 16'b0000000000000011; 
  #5;
  D = 16'b0000000000000101; 
  #5;
  D = 16'b0000000000000000; 
  #5;
 $display("Done");
end
endmodule

// for (integer i = 0; i < 15; i +=1) begin
//   {D} = i; 
//   #5;
// end
