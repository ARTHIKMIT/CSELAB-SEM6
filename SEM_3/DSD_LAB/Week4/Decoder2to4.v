/*Q1 - Write behavioral Verilog code for a 2 to 4 decoder with active-low enable input and active
high output using the if-else statement. */
module Decoder2to4 (W, E, Y);
input wire [1:0] W;
input wire E;
output reg [3:0] Y;
always@(*)
begin
  for (integer k = 0; k <= 3; k = k+1)
  if ((W == k) && (E == 0)) //&& (W != 0)
    Y[k] = 1;
   else
    Y[k] = 0;
end
endmodule
