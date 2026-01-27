/*Q2 - Write behavioral Verilog code for a negative edge triggered T FF with synchronous active low reset.*/
module TFF (T, Clock , Reset, Q);
  input T, Clock, Reset;
  output reg Q;
  always @ (negedge Clock)
  if (!Reset)
    Q <= 0;
  else if (T==1'b0)
    Q<=Q;
  else 
    Q<=~Q;
endmodule
