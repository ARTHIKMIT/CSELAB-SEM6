//Test Bench
`timescale 1ns/1ns
`include "lab1b.v"
module lab1b_tb();
reg A, B, C, D;
wire F;
lab1b l1(A, B, C, D, F);
initial begin
$dumpfile("lab1b_tb.vcd");
$dumpvars(0, lab1b_tb);
	for (integer i=0; i<16; i=i+1) begin
	{A, B, C, D} = i;
	#10;
	end
$display("Done");
end
endmodule
