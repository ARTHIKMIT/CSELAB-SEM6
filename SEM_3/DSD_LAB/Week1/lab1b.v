// Q1 (b)
module lab1b(A, B, C, D, F);
input A, B, C, D;
output F;
assign F = (~A&~D)|(B&~D)|(C&~D)|(~A&B&C);
endmodule
