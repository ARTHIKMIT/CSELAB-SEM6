//Test Bench
`timescale 1ns/1ns	//incl time 
`include "Multiplexer2_1.v"	//Name of the Design
module Multiplexer2_1_tb();	//Name of test bench
reg s0, x1, x2; //input
wire f; //output
Multiplexer2_1 mux(s0, x1, x2, f);
initial
begin
$dumpfile("Multiplexer2_1_tb.vcd");
$dumpvars(0, Multiplexer2_1_tb);
s0 = 0; x1 = 1'b0; x2 = 1'b0;
#20
s0 = 0; x1 = 1'b1; x2 = 1'b1;
#20
s0 = 1; x1 = 1'b0; x2 = 1'b0;
#20
s0 = 1; x1 = 1'b1; x2 = 1'b1;
#20
$display("Done");
end
endmodule
