module SLT (
    input wire  A,
    input wire  B,
    input wire [2:0]ALUControl,
    input wire  Sum,
    output wire LT,
    output wire Overflow
);
        wire gate1, gate2, gate3;
        assign gate1 = ~(ALUControl[0] ^ B ^ A);
        assign gate2 = Sum ^A;
        assign gate3 = ~ ALUControl[1];

        assign Overflow = gate1 & gate2 & gate3;

        assign LT = Sum ^Overflow;

endmodule