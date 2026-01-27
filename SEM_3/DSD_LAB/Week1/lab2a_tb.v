//Test Bench
`timescale 1ns/1ns
`include "lab2a.v"
module lab2a_tb();
reg A, B, C, D;
wire F;
lab2a l1(A, B, C, D, F);
initial begin
$dumpfile("lab2a_tb.vcd");
$dumpvars(0, lab2a_tb);
	for (integer i=0; i<16; i=i+1) begin
	{A, B, C, D} = i;
	#10;
	end
$display("Done");
end
endmodule
