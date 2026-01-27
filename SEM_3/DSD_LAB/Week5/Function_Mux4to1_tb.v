//Test bench
`timescale 1ns/1ns
`include "Function_Mux4to1.v"
module Function_Mux4to1_tb ();
reg A, B, C, D;
wire f;
Function_Mux4to1 mu(A, B, C, D, f);
initial
begin
 $dumpfile("Function_Mux4to1_tb.vcd");
 $dumpvars(0, Function_Mux4to1_tb);
 for (integer i=0; i<16; i++)
 begin
   {A, B, C, D} = i;
   #10;
 end
 $display("Done");
end
endmodule
