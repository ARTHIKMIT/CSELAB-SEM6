/*Q1 (Solved Exercise) - Design and write Verilog code for a three-bit counter that counts in the sequence 0, 1, 2, 4, 5, 6, 0 using JK flip-flops.*/
module jkff (Q, J, K, Reset, Clock);
  input J, K, Clock, Reset;
  output reg Q;
  always @ (posedge Clock or negedge Reset) begin
    case({J, K})
      2'b00:Q <= Q;
      2'b01:Q <= 1'b0;
      2'b10:Q <= 1'b1;
      2'b11:Q <= ~Q;
    endcase
    if (Reset==0)
      Q <= 0;
  end
endmodule

module synchronous_counter (clear, clk, Q);
  input clear, clk;
  output [2:0] Q;
  jkff FF0 (Q[0],~Q[1], 1'b1, clear, clk);
  jkff FF1 (Q[1], Q[0], 1'b1, clear, clk);
  jkff FF2 (Q[2], Q[1],Q[1],clear, clk);
endmodule
