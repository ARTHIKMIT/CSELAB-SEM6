//Test bench
`timescale 1ns/1ns
`include "ShiftRegister6BitPIPO.v"
module ShiftRegister6BitPIPO_tb ();
  reg [5:0] I; 
  reg clk;
  wire [5:0] A;
  ShiftRegister6BitPIPO r1(I, clk, A);
  initial begin
    $dumpfile("ShiftRegister6BitPIPO_tb.vcd");
    $dumpvars(0, ShiftRegister6BitPIPO_tb);
    clk = 0;
    forever #10 clk = ~clk;
  end
  initial begin
    I = 12; #20;
    I = 8; #20;
    $display("Done");    
    $finish;
  end
endmodule
/*
for (integer i=0; i<4; i++)
      begin
       {Reset, D} = i;
       #20;
      end
*/
