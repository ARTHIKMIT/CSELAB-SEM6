// Q1 (a)
module lab1a(A, B, C, D, F);
input A, B, C, D;
output F;
assign F = (~A&~B)|(~B&~C)|(~C&~D);
endmodule
