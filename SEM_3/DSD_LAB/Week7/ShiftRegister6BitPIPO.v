/*Q1 - Write structural Verilog code for a 6-bit shift register 
Parallel in Parallel out */
module ShiftRegister6BitPIPO (I, clk, A);
  input [5:0] I;
  input clk;
  output [5:0] A;
  
  DFF s1(I[5],clk,A[5]);
  DFF s2(I[4],clk,A[4]);
  DFF s3(I[3],clk,A[3]);
  DFF s4(I[2],clk,A[2]);
  DFF s5(I[1],clk,A[1]);
  DFF s6(I[0],clk,A[0]);
  
endmodule

module DFF (D, clk, Q);
  input D, clk;
  output Q;
  reg Q;
  always @(posedge clk)
  Q<= D;
endmodule
