//Test bench
`timescale 1ns/1ns
`include "lab1.v"
module lab1_tb ();
reg a, b, c, d;
wire f;
lab1 l (a, b, c, d, f);
initial
begin
 $dumpfile("lab1_tb.vcd");
 $dumpvars(0, lab1_tb);
 for (integer i = 0; i<16; i++)
 begin
  {a, b, c, d} = i;
  #20;
 end
 $display("Done");
end
endmodule
