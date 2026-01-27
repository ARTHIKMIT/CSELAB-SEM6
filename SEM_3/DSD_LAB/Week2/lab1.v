/* Q1 Find the minimum cost circuit for the function f(a,b,c,d) = ∑m(0,4,8,13,14,15) using
functional decomposition. Write the Verilog code to simulate the same. */
module lab1 (a, b, c, d, f);
input a, b, c, d;
output f;
assign g = c | d;
assign h = a&b;
assign f = (~g&~h)|(h&g);
endmodule
