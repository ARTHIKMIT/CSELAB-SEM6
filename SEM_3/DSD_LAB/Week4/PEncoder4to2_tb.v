//Test bench
`timescale 1ns/1ns
`include "PEncoder4to2.v"
module PEncoder4to2_tb ();
reg [3:0] D;
wire [1:0] B;
wire Z;
PEncoder4to2 mu(D, B, Z);
initial
begin
 $dumpfile("PEncoder4to2_tb.vcd");
 $dumpvars(0, PEncoder4to2_tb);
 D =4'b0000; #10;
 D =4'b0001; #10;
 D =4'b0010; #10;
 D =4'b0100; #10;
 D =4'b1000; #10;
 $display("Done");
end
endmodule
