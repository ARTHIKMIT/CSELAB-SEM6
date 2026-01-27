//Test bench
`timescale 1ns/1ns
`include "FullAdder.v"
module FullAdder_tb ();
reg x, y, cin;
wire s, cout;
FullAdder l(x, y, cin, s, cout);
initial
begin
 $dumpfile("FullAdder_tb.vcd");
 $dumpvars(0, FullAdder_tb);
 for (integer i = 0; i<8; i++)
 begin
  {cin, x, y} = i;
  #20;
 end
 $display("Done");
end
endmodule
