//Test bench
`timescale 1ns/1ns
`include "Function_Decoder4to16.v"
module Function_Decoder4to16_tb();
reg A, B, C, D;
wire f;
//wire [15:0] Y;
Function_Decoder4to16 mu(A, B, C, D, f);
initial
begin
 $dumpfile("Function_Decoder4to16_tb.vcd");
 $dumpvars(0, Function_Decoder4to16_tb);
 for (integer i=0; i<16; i++)
 begin
   {A, B, C, D} = i;
   #10;
 end
 $display("Done");
end
endmodule
