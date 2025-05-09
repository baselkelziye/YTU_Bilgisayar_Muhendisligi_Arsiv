module adder (A, B, PCTarget);
    input [31:0] A, B;
    output [31:0] PCTarget;
    assign PCTarget = A + B;
endmodule

module add4 (A, out);
    input [31:0] A;
    output [31:0] out;
    assign out = A + 4;
endmodule