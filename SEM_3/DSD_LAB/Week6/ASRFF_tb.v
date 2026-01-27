//Test bench
`timescale 1ns/1ns
`include "ASRFF.v"
module ASRFF_tb ();
  reg S, R, Clock, Reset;
  wire Q;
  ASRFF f1(S, R, Clock, Reset, Q);
  initial begin
    $dumpfile("ASRFF_tb.vcd");
    $dumpvars(0, ASRFF_tb);
    Clock = 0;
    forever #10 Clock = ~Clock;
  end
  initial begin
    for (integer i=0; i<8; i++)
      begin
       {Reset, S, R} = i;
       #20;
      end
    $display("Done");    
    $finish;
  end
endmodule
