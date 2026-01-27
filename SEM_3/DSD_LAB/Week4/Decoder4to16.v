/*Q2 - Using the 2 to 4 decoders designed in Q1 above, design a 4 to 16 decoder with active-high
enable input and active high output and write the Verilog code for the same. */
`include "Decoder2to4.v"
module Decoder4to16 (W, E, Y);
  input wire [3:0] W;
  input wire E;
  output wire [15:0] Y;
  wire [3:0] T;
  Decoder2to4 d1 (W[3:2], ~E, T);
  Decoder2to4 d2 (W[1:0], ~T[0], Y[3:0]);
  Decoder2to4 d3 (W[1:0], ~T[1], Y[7:4]);
  Decoder2to4 d4 (W[1:0], ~T[2], Y[11:8]);
  Decoder2to4 d5 (W[1:0], ~T[3], Y[15:12]);
endmodule
