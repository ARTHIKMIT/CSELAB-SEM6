module PEncoder16to4 (D, B, Z);
  input wire [15:0] D;
  output reg [3:0] B;
  output reg Z;
  always@(*)
  begin
    Z = 1'b0;
    for (integer i = 15; i>=0; i-=1) begin
      if (D[i]==1) begin
        B = i;
        Z = 1'b1;
      	break;
      end
    end
  end
endmodule
