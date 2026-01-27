/*Apply functional decomposition for the following function to obtain a simplified circuit and
simulate using Verilog.*/
module lab0 (x1, x2, x3, x4, f);
input x1, x2, x3, x4;
output f;
assign g = (x1 & ~x2) | (~x1 & x2);
assign f = (g & x3) | (~g & x4);
endmodule
