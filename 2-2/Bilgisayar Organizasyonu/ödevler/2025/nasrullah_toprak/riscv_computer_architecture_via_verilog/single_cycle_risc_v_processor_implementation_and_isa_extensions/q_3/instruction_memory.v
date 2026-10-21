`timescale 1ps / 1ps

module InstructionMemory (
    input  [31:0] A,
    output [31:0] Instr
);
    reg [31:0] memory [0:63];

    initial begin
        memory[0] = 32'h00000093; // addi x1, x0, 0 -> base address = 0
        memory[1] = 32'h0000A103; // lw x2, 0(x1)  -> x2 = FFFF1234
        memory[2] = 32'h00009183; // lh x3, 0(x1)  -> x3 = 00001234
        memory[3] = 32'h00209203; // lh  x4, 2(x1)  > x4 = FFFFFFFF
        memory[4] = 32'hFF000293; // addi x5, x0, -16 -> x5 = FFFFFFF0
        memory[5] = 32'h4022D313; // srai x6, x5, 2 -> x6 = FFFFFFFC
        memory[6] = 32'h00000063; // beq x0, x0, 0  -> stop/self loop
    end
    assign Instr = memory[A[31:2]];
endmodule
