// Q2 (a)
module lab2b(A, B, C, D, F);
input A, B, C, D;
output F;
assign F = (~C|D)&(~A|D)&(A|~B|C|~D);
endmodule
