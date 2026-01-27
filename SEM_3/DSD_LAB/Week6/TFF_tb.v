//Test bench
`timescale 1ns/1ns
`include "TFF.v"
module TFF_tb ();
  reg T, Clock, Reset;
  wire Q;
  TFF f1(T, Clock, Reset, Q);
  initial begin
    $dumpfile("TFF_tb.vcd");
    $dumpvars(0, TFF_tb);
    Clock = 0;
    forever #10 Clock = ~Clock;
  end
  initial begin
    for (integer i=0; i<4; i++)
    begin
     {Reset, T} = i;
     #20;
    end
    $display("Done");    
    $finish;
  end
endmodule


