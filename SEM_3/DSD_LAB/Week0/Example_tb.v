//Test Bench
`timescale 1ns/1ns	//incl time 
`include "Example.v"	//Name of the Design
module Example_tb();	//Name of test bench
reg x1, x2, x3; //input
wire f; //output
Example ex1(x1, x2, x3, f);	//ex1 -> name of the gate, can make more instances
initial
begin
$dumpfile("Example_tb.vcd");
$dumpvars(0, Example_tb);
x1 = 1'b0; x2 = 1'b0; x3 = 1'b0;
#20
x1 = 1'b0; x2 = 1'b0; x3 = 1'b1;
#20
x1 = 1'b0; x2 = 1'b1; x3 = 1'b0;
#20
x1 = 1'b0; x2 = 1'b1; x3 = 1'b1;
#20
x1 = 1'b1; x2 = 1'b0; x3 = 1'b0;
#20
x1 = 1'b1; x2 = 1'b0; x3 = 1'b1;
#20
x1 = 1'b1; x2 = 1'b1; x3 = 1'b0;
#20
x1 = 1'b1; x2 = 1'b1; x3 = 1'b1;
#20
$display("Done");
end
endmodule
