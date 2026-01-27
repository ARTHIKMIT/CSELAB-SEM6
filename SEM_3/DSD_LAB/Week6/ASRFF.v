/*Q4 - Write behavioral Verilog code for a negative edge-triggered SR FF with asynchronous active low reset.*/
module ASRFF (S, R, Clock , Reset, Q);
  input S, R, Clock, Reset;
  output reg Q;
  always @ (negedge Clock) begin
    case({S, R})
      2'b00:Q <= Q;
      2'b01:Q <= 1'b0;
      2'b10:Q <= 1'b1;
      2'b11:Q <= 1'bx;
    endcase
  end
  always @ (posedge Clock or negedge Clock) begin
    if (!Reset)
      Q <= 0;
  end
endmodule
