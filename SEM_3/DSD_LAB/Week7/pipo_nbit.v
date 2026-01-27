// Code your design here
module dff (input d, input clk, output reg q);
  always @ (posedge clk) begin
    q <= d;
  end
endmodule

module pipo_nbit #(parameter N=5) (input clk, input [N-1:0] data, output [N-1:0] q);
  //genvar Enables loop control in generate blocks, used to create multiple instances of modules like dff, reducing manual duplication
  genvar i;
  //generate: Provides a way to conditionally or repetitively instantiate hardware structures based on parameters like N, facilitating modular and scalable designs.
  generate
    //Verilog requires you to name each block of logic when using a generate block. Each block within a generate loop must be uniquely identifiable
    for (i=0; i<N; i=i+1) begin : gen_block
      dff dff_gen (data[i], clk, q[i]);
    end
  endgenerate
endmodule
