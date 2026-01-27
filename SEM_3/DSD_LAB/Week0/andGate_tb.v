//Test Bench
`timescale 1ns/1ns	//incl time 
`include "andGate.v"	//Name of the Design
module andGate_tb();	//Name of test bench
reg x1, x2; //input
wire f; //output
andGate aG1(x1, x2, f);	//lb -> name of the gate, can make more instances
initial
begin
$dumpfile("andGate_tb.vcd");
$dumpvars(0, andGate_tb);
x1 = 1'b0; x2 = 1'b0;   //b ->1 bit of binary data is stored (logic 0)
#20
x1 = 1'b0; x2 = 1'b1;
#30
x1 = 1'b1; x2 = 1'b0;
#10
x1 = 1'b1; x2 = 1'b1;
#20
$display("Done");
end
endmodule
