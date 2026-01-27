//Test Bench
`timescale 1ns/1ns
`include "lab3.v"
module lab3_tb();
reg A, B, C;
wire F1, F2;
lab3 l1(A, B, C, F1, F2);
initial begin
$dumpfile("lab3_tb.vcd");
$dumpvars(0, lab3_tb);
	for (integer i=0; i<8; i=i+1) begin
	{A, B, C} = i;
	#20;
	end
$display("Done");
end
endmodule
