`include "controller.v"
`include "datapath.v"


module riscv(clk, reset,PC,Instr,MemWrite, ALUResult, WriteData,ReadData);

    input clk, reset;
    input [31:0] Instr,ReadData;
    inout[31:0] PC;
    output MemWrite;
    output[31:0] ALUResult, WriteData;

    wire ALUSrc, RegWrite, Zero;
    wire [1:0] ResultSrc, ImmSrc;
    wire [2:0] ALUControl;

    controller c1(Instr[6:0], Instr[14:12], Instr[30], Zero, ResultSrc, MemWrite, PCSrc, ALUSrc,RegWrite, ImmSrc,ALUControl);

    datapath d1(clk, reset,ResultSrc, PCSrc, ALUSrc,RegWrite,ImmSrc,ALUControl,Zero,PC, Instr,ALUResult, WriteData, ReadData);

endmodule