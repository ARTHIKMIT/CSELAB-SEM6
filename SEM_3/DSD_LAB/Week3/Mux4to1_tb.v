//Test bench
`timescale 1ns/1ns
`include "Mux4to1.v"
module Mux4to1_tb ();
reg [0:1] s;
reg [0:3] w;
wire f;
Mux4to1 mux(s, w, f);
initial
begin
 $dumpfile("Mux4to1_tb.vcd");
 $dumpvars(0, Mux4to1_tb);
 s = 2'b00;
 w[0] = 2'b00; w[1] = 2'b01; w[2] = 2'b10; w[3] = 2'b11;
 #20;
 s = 2'b01;
 #20;
 s = 2'b10;
 #20;
 s = 2'b11;
 #20;
 $display("Done");
end
endmodule
