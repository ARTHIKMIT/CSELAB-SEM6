// Q2 (a)
module lab2a(A, B, C, D, F);
input A, B, C, D;
output F;
assign F = (C|D)&(B|C)&(~A|~B|~C|~D);
endmodule
