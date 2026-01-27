/*Q1 - Write behavioral Verilog code for a 4 to 1 multiplexer using the if-else // statement. */
module Mux4to1 (s, w, f);
input [0:1] s;
input [0:3] w;
output f;
reg g;
always@(s or w)
begin
case(s)
  2'b00:g=w[0];
  2'b01:g=w[1];
  2'b10:g=w[2];
  2'b11:g=w[3];
endcase
end
assign f = g;
endmodule

/*
if (s == 2'b00)
begin g=w[0]; end
if (s == 2'b01)
begin g=w[1]; end
if (s == 2'b10)
begin g=w[2]; end
if (s == 2'b11)
begin g=w[3]; end
*/
