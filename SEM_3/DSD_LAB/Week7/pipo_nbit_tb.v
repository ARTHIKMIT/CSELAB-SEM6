`timescale 1ns/1ns
module pipo_nbit_tb;
  parameter N = 5;
  reg clk;
  reg [N-1:0] data;
  wire [N-1:0] q;
  integer i;

  pipo_nbit #(N) pipo_nbit_inst (clk, data, q);

  initial begin
    $dumpfile ("pipo_nbit_tb.vcd");
    $dumpvars (0, pipo_nbit_tb);
  end

  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end

  initial begin
    for (i=0; i<N; i=i+1) begin
      data = 5'b10011;
      #10;
    end
    #10;
    $finish;
  end
endmodule
