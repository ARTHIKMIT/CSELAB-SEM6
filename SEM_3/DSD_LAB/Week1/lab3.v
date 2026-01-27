// Q3 (Additional 1)
module lab3(A, B, C, F1, F2);
input A, B, C;
output F1, F2;
assign F1 = (A&~C)|(B&C)|(~B&~C);
assign F2 = (A|~B|C)&(A|B|~C)&(~A|B|~C);
endmodule
