//Test bench
`timescale 1ns/1ns
`include "DFF.v"
module DFF_tb ();
  reg D, Clock, Reset;
  wire Q;
  DFF f1(D, Clock, Reset, Q);
  initial begin
    $dumpfile("DFF_tb.vcd");
    $dumpvars(0, DFF_tb);
    Clock = 0;
    forever #10 Clock = ~Clock;
  end
  initial begin
    for (integer i=0; i<4; i++)
      begin
       {Reset, D} = i;
       #20;
      end
    $display("Done");    
    $finish;
  end
endmodule


