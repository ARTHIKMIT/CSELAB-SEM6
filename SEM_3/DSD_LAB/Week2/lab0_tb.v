//Test bench
`timescale 1ns/1ns
`include "lab0.v"
module lab0_tb ();
reg x1, x2, x3, x4;
wire f;
lab0 l (x1, x2, x3, x4, f);
initial
begin
$dumpfile("lab0_tb.vcd");
$dumpvars(0, lab0_tb);
for (integer i = 0; i<16; i++)
begin
{x1, x2, x3, x4} = i;
#20;
end
$display("Done");
end
endmodule
