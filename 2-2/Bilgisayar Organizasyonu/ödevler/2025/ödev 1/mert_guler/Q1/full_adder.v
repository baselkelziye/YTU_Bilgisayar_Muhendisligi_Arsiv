`include "../01/half_adder.v"

module full_adder(a, b, cin, sum, cout);
    input a, b, cin;
    output sum, cout;
    wire sum_half, carry_half, carry_half_2;

    half_adder ha1(a, b, sum_half, carry_half); 
    half_adder ha2(sum_half, cin, sum, carry_half_2);
    or(cout, carry_half, carry_half_2); 
endmodule