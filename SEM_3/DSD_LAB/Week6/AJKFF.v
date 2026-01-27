/*Q3 - Write behavioral Verilog code for a positive edge-triggered JK FF with asynchronous active high reset.*/
module AJKFF (J, K, Clock , Reset, Q);
  input J, K, Clock, Reset;
  output reg Q;
  
  always @ (posedge Clock) begin
    case({J, K})
      2'b00:Q <= Q;
      2'b01:Q <= 1'b0;
      2'b10:Q <= 1'b1;
      2'b11:Q <= ~Q;
    endcase
  end
  
  always @ (posedge Clock or negedge Clock) begin
    if (Reset)
      Q <= 0;
  end
endmodule
