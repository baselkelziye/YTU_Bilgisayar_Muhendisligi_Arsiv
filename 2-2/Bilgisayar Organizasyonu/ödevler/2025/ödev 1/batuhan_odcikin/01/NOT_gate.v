module NOT_gate(
    input [31:0] A,
    output [31:0] Result
);
    assign Result = ~A;
endmodule