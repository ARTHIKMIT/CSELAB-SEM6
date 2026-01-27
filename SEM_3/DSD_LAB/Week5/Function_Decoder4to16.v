/*Q3 - Implement the function, F(a, b, c, d) = Σm (2,3,4,5,6,7,10,11,12,15) using a 4 to 16 binary decoder and an OR gate.*/
module Function_Decoder4to16 (A, B, C, D, f);
input A, B, C, D;
output f;

reg [15:0] Y;
always@(*) begin
   for (integer k = 0; k < 16; k += 1) begin
     if ({A, B, C, D} == k)
       Y[k] = 1;
     else
       Y[k] = 0;
   end
end

assign f = Y[2] | Y[3] | Y[4] | Y[5] | Y[6] | Y[7] | Y[10] | Y[11] | Y[12] | Y[15];

endmodule
