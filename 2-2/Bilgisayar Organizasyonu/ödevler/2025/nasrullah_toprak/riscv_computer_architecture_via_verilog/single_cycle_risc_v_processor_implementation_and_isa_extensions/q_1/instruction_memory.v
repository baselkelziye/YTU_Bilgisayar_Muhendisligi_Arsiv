`timescale 1ps / 1ps

module InstructionMemory (
    input  [31:0] A,
    output [31:0] Instr
);
    reg [31:0] memory [0:63];

    initial begin
        memory[0]  = 32'h00500093;
        memory[1]  = 32'h00a00113;
        memory[2]  = 32'h002081b3;
        memory[3]  = 32'h40110233;
        memory[4]  = 32'h0020a2b3;
        memory[5]  = 32'h0020e333;
        memory[6]  = 32'h0020f3b3;
        memory[7]  = 32'h0060a413;
        memory[8]  = 32'h0080e493;
        memory[9]  = 32'h00617513;
        memory[10] = 32'h00302023;
        memory[11] = 32'h00002583;
        memory[12] = 32'h00358463;
        memory[13] = 32'h06300613;
        memory[14] = 32'h008006ef;
        memory[15] = 32'h05800713;
        memory[16] = 32'h07b00793;
        memory[17] = 32'h00000063;
    end

    assign Instr = memory[A[31:2]];

endmodule