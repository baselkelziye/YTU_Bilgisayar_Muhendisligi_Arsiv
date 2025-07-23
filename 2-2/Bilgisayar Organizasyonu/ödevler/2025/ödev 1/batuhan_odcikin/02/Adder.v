module Adder (
    input [31:0] A,
    input [31:0] B,
    input Cin,
    output [31:0] Sum,
    output Cout
);
    assign {Cout, Sum} = A + B + Cin;
endmodule