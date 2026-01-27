/*Q1 - Implement the expression F(A,B,C,D)=∑m (0,1,2,4,6,9,12,14) using 4:1 multiplexer and
write the Verilog code for the same.*/
module Function_Mux4to1 (A, B, C, D, f);
input A, B, C, D;
output f;
wire [3:0] i;
assign i[0] = ~(C&D);
assign i[1] = ~D;
assign i[2] = ~C&D;
assign i[3] = ~D;

assign f = (A == 0)?((B == 0)?i[0]:i[1]):((B==0)?i[2]:i[3]);

endmodule
