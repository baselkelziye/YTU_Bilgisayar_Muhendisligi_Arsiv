`timescale 1ps / 1ps

module InstructionMemory (
    input  [31:0] A,
    output [31:0] Instr
);
    reg [31:0] memory [0:63];

    initial begin
        memory[0] = 32'hff000093;
        memory[1] = 32'h4020d113;
        memory[2] = 32'h00500193;
        memory[3] = 32'h4011d213;
        memory[4] = 32'h0020f2b3;
        memory[5] = 32'h0020e333;
        memory[6] = 32'h00000063;
    end

    assign Instr = memory[A[31:2]];

endmodule