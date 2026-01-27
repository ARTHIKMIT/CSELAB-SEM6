/*Q3 - Write behavioral Verilog code for a 4 to 2 priority encoder using casex statement. */
module PEncoder4to2 (D, B, Z);
input wire [3:0] D;
output reg [1:0] B;
output reg Z;
always@(*)
begin
  Z = 1'b1;
  casex(D)
    4'b1xxx:B=2'b11;
    4'b01xx:B=2'b10;
    4'b001x:B=2'b01;
    4'b0001:B=2'b00;
    4'b0000:begin B=2'bxx; Z=1'b0; end
  endcase
end
endmodule
