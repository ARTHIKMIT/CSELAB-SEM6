//Verilog code to implement full adder.
module fullAdder (x, y, cin, s, cout);
input wire x, y, cin;
output reg s, cout;
always@(*)
begin
 s = x^y^cin;
 cout = (x&y)|(x&cin)|(y&cin);
 //{cout, s}=x+y+cin;
end
endmodule

//Verilog code to implement half adder.
module halfAdder (x, y, s, cout);
input wire x, y;
output reg s, cout;
always@(*)
begin
 s = x^y;
 cout = x&y;
 //{cout, s}=x+y;
end
endmodule
