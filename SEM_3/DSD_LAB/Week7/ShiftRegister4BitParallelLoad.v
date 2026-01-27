/*Q3 - Design and simulate a 4 bit shift register with the parallel load that operates according to the following function table 
00 Shift left
01 Load parallel data
10 Complement
11 No change
*/
module ShiftRegister4BitParallelLoad (I, clk, S, L, A);
  input [3:0] I;
  input clk, S, L;
  output [3:0] A;
  wire [3:0] Temp = 4'd0;
  
  DFF s1(I[3],clk,Temp[3]);
  DFF s2(I[2],clk,Temp[2]);
  DFF s3(I[1],clk,Temp[1]);
  DFF s4(I[0],clk,Temp[0]);
  
  always@(*) begin
  case({S, L})
    2'b00:Temp <= {Temp[2:0], 1'b0};
    2'b01:Temp<= I;
    2'b10:Temp <= ~I;
    2'b11:Temp <= I;
  endcase
  end
  assign A = Temp;
endmodule


module DFF (D, clk, Q);
  input D, clk;
  output Q;
  reg Q;
  always @(posedge clk)
  Q<= D;
endmodule
