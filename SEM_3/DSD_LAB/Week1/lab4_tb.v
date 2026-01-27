//Test Bench
`timescale 1ns/1ns
`include "lab4.v"
module lab4_tb();
reg x1, x2, x3, x4;
wire F;
lab4 l1(x1, x2, x3, x4, F);
initial begin
$dumpfile("lab4_tb.vcd");
$dumpvars(0, lab4_tb);
	for (integer i=0; i<16; i=i+1) begin
	{x1, x2, x3, x4} = i;
	#20;
	end
$display("Done");
end
endmodule
