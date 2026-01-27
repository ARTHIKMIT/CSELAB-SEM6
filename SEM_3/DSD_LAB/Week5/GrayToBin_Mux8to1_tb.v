`timescale 1ns/1ns
module GrayToBin_Mux8to1_tb();
  reg [3:0] G;
  wire [3:0] B;

  GrayToBin_Mux8to1 mu(G, B);

  initial begin
    $dumpfile("GrayToBin_Mux8to1_tb.vcd");
    $dumpvars(0, GrayToBin_Mux8to1_tb);

    for (integer i = 0; i < 16; i = i + 1) begin
      G = i; // Assign G as a 4-bit vector
      #10;
    end
    
    $display("Done");
  end
endmodule
