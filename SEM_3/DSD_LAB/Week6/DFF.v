/*Q1 - Write behavioral Verilog code for a positive edge-triggered D FF with synchronous active high reset.*/
module DFF (D, Clock , Reset, Q);
  input D, Clock, Reset;
  output reg Q;
  always @ (posedge Clock)
  if (Reset)
    Q <= 0;
  else
    Q<=D;
endmodule
