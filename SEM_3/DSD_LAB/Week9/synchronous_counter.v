/*Q2 - Write Verilog code in structural style for a 3-bit synchronous counter using T flip-flops. */
module tff (Q, T, Reset, Clock);
  input T, Clock, Reset;
  output reg Q;
  always @ (posedge Clock or negedge Reset)
  if (Reset==0)
    Q <= 0;
  else if (T==1'b0)
    Q<=Q;
  else 
    Q<=~Q;
endmodule

module synchronous_counter (clear, clk, Q);
  input clear, clk;
  output [2:0] Q;
  wire w1, w2, w3;
  tff FF0 (Q[0], 1'b1, clear, clk);
  tff FF1 (Q[1], w1 , clear, clk);
  tff FF2 (Q[2], w3, clear, clk);
  nand G0 (w1,1'b1, Q[0]);
  nand G1 (w2,1'b1, Q[1]);
  and G2 (w3, w1, w2);
endmodule
