//Test bench
`timescale 1ns/1ns
`include "Mux8to1.v"
module Mux8to1_tb ();
reg [0:2] s;
reg [0:7] w;
wire f;
Mux8to1 mu(s, w, f);
initial
begin
 $dumpfile("Mux8to1_tb.vcd");
 $dumpvars(0, Mux8to1_tb);
 s = 3'b000;
 w[0] = 3'b000; w[1] = 3'b001; w[2] = 3'b010; w[3] = 3'b011;
 w[4] = 3'b000; w[5] = 3'b001; w[6] = 3'b010; w[7] = 3'b011;
 #20;
 s = 3'b001;
 #20;
 s = 3'b010;
 #20;
 s = 3'b011;
 #20;
 $display("Done");
end
endmodule
