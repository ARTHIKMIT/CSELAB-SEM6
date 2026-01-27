//Test bench
`timescale 1ns/1ns
`include "ShiftRegister4BitParallelLoad.v"
module ShiftRegister4BitParallelLoad_tb ();
  reg [3:0] I; 
  reg clk, S, L;
  wire [3:0] A;
  ShiftRegister4BitParallelLoad r1(I, clk, S, L, A);
  initial begin
    $dumpfile("ShiftRegister4BitParallelLoad_tb.vcd");
    $dumpvars(0, ShiftRegister4BitParallelLoad_tb);
    clk = 0;
    forever #10 clk = ~clk;
  end
  initial begin
    I = 4; S = 0; L = 1;  #20;
    L = 0; #20;
    S = 0; L = 0; #20;
    I = 1; S = 0; L = 1;  #20;
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
