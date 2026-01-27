module Mux8to1 (s, w, f);
  input [2:0] s;
  input [0:7] w;
  output f;
  reg f; //reg for output inside the always block

  always @(*) begin
    case(s)
      3'b000: f = w[0];
      3'b001: f = w[1];
      3'b010: f = w[2];
      3'b011: f = w[3];
      3'b100: f = w[4];
      3'b101: f = w[5];
      3'b110: f = w[6];
      3'b111: f = w[7];
      default: f = 1'b0; // Default case to handle undefined states
    endcase
  end
endmodule

// Gray code to Binary conversion using 8:1 Muxes
module GrayToBin_Mux8to1 (G, B);
  input [3:0] G;
  output [3:0] B;
  wire [7:0] w1, w2, w3;

  assign B[3] = G[3];

  assign w1 = { {4{G[2]}}, {4{~G[2]}} };
  Mux8to1 m1 (G[3:1], w1, B[2]);

  assign w2 = { 2{ {2{G[1]}}, {2{~G[1]}} } };
  Mux8to1 m2 (G[3:1], w2, B[1]);

  assign w3 = {4{G[0], ~G[0]}};
  Mux8to1 m3 (G[3:1], w3, B[0]);

endmodule
