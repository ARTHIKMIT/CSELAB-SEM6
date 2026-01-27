//Test Bench
`timescale 1ns/1ns
`include "lab1a.v"
module lab1a_tb();
reg A, B, C, D;
wire F;
lab1a l1(A, B, C, D, F);
initial
begin
$dumpfile("lab1a_tb.vcd");
$dumpvars(0, lab1a_tb);
A = 1'b0; B = 1'b0; C = 1'b0; D = 1'b0;
#20
A = 1'b0; B = 1'b0; C = 1'b0; D = 1'b1;
#20
A = 1'b0; B = 1'b0; C = 1'b1; D = 1'b0;
#20
A = 1'b0; B = 1'b0; C = 1'b1; D = 1'b1;
#20
A = 1'b0; B = 1'b1; C = 1'b0; D = 1'b0;
#20
A = 1'b0; B = 1'b1; C = 1'b0; D = 1'b1;
#20
A = 1'b0; B = 1'b1; C = 1'b1; D = 1'b0;
#20
A = 1'b0; B = 1'b1; C = 1'b1; D = 1'b1;
#20
A = 1'b1; B = 1'b0; C = 1'b0; D = 1'b0;
#20
A = 1'b1; B = 1'b0; C = 1'b0; D = 1'b1;
#20
A = 1'b1; B = 1'b0; C = 1'b1; D = 1'b0;
#20
A = 1'b1; B = 1'b0; C = 1'b1; D = 1'b1;
#20
A = 1'b1; B = 1'b1; C = 1'b0; D = 1'b0;
#20
A = 1'b1; B = 1'b1; C = 1'b0; D = 1'b1;
#20
A = 1'b1; B = 1'b1; C = 1'b1; D = 1'b0;
#20
A = 1'b1; B = 1'b1; C = 1'b1; D = 1'b1;
#20
$display("Done");
end
endmodule
