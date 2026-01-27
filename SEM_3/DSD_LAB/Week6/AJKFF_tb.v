//Test bench
`timescale 1ns/1ns
`include "AJKFF.v"
module AJKFF_tb ();
  reg J, K, Clock, Reset;
  wire Q;
  AJKFF f1(J, K, Clock, Reset, Q);
  initial begin
    $dumpfile("AJKFF_tb.vcd");
    $dumpvars(0, AJKFF_tb);
    Clock = 0;
    forever #10 Clock = ~Clock;
  end
  initial begin
    for (integer i=0; i<8; i++)
      begin
       {Reset, J, K} = i;
       #20;
      end
    $display("Done");    
    $finish;
  end
endmodule
