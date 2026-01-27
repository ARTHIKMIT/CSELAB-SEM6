// Write behavioral Verilog code to implement full adder.
module FullAdder (x, y, cin, s, cout);
input wire x, y, cin;
output reg s, cout;
always@(x, y, cin)
begin
 {cout, s}=x+y+cin;
end
endmodule
