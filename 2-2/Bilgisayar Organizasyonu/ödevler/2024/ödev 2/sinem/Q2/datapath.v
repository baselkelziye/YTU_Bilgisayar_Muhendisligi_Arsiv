`include "pcCounter.v"
`include "pcAdder.v"
`include "mux3.v"
`include "mux2.v"
`include "registerFile.v"
`include "Alu.v"
`include "extender.v"

module datapath(clk, reset,ResultSrc, PCSrc, ALUSrc,RegWrite,ImmSrc,ALUControl,Zero,PC, Instr,ALUResult, WriteData, ReadData);

    input clk, reset;
    input[1:0] ResultSrc,ImmSrc;
    input PCSrc, ALUSrc,RegWrite;
    input [2:0]  ALUControl;
    input  [31:0] Instr,ReadData;
    output Zero;
    output [31:0] ALUResult, WriteData;
    inout [31:0] PC;
    wire [31:0] PCNext, PCPlus4, PCTarget;
    wire [31:0] ImmExt;
    wire [31:0] SrcA, SrcB;
    wire [31:0] Result;


  // next PC
    pcCounter pc1(clk, reset, PC, PCNext);
    pcAdder pa1(PC,32'b0000_0000_0000_0000_0000_0000_0000_0100, PCPlus4);
    pcAdder pa2(PC,ImmExt, PCTarget);
    mux2 m21(PCSrc,PCTarget,PCPlus4,PCNext);

     // register file
    registerFile rf(Instr[19:15], Instr[24:20], Instr[11:7], SrcA, WriteData, Result, clk, RegWrite, reset);
    extender e1(Instr[31:7], ImmSrc, ImmExt);


    //ALU
    Alu a1(ALUResult,SrcA,SrcB,ALUControl,Zero);
    mux3 mux31(ResultSrc,ALUResult,ReadData,PCPlus4,Result);

endmodule

