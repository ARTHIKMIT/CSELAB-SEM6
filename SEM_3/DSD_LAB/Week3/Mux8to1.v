/*Q2 - Write behavioral Verilog code for an 8 to 1 multiplexer using case statement. Use this along with a 2 to 1 multiplexer to write the hierarchical code for a 
16 to 1 multiplexer. */

module Mux8to1 (s, w, f);
input [0:2] s;
input [0:7] w;
output f;
reg g;
always@(*)
begin
case(s)
  3'b000:g=w[0];
  3'b001:g=w[1];
  3'b010:g=w[2];
  3'b011:g=w[3];
  3'b100:g=w[4];
  3'b101:g=w[5];
  3'b110:g=w[6];
  3'b111:g=w[7];
endcase
end
assign f = g;
endmodule
