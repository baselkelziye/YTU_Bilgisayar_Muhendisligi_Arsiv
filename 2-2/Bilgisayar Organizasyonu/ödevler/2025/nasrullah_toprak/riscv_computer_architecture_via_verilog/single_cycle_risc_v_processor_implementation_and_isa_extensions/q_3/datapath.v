`timescale 1ps / 1ps

module Datapath (
    input clk,
    input rst,

    input RegWrite,
    input [1:0]  ImmSrc,
    input ALUSrc,
    input MemWrite,
    input [1:0]  ResultSrc,
    input PCSrc,
    input [2:0]  ALUControl,

    output [31:0] Instr,
    output Zero,
    output Overflow,

    output [31:0] PC,
    output [31:0] ALUResult,
    output [31:0] WriteData,
    output [31:0] Result
);

    wire [31:0] PCNext;
    wire [31:0] PCPlus4;
    wire [31:0] PCTarget;

    wire [31:0] RD1;
    wire [31:0] RD2;
    wire [31:0] SrcB;

    wire [31:0] ImmExt;
    wire [31:0] ReadData;

    // PC register
    PC u_pc (
        .clk(clk),
        .rst(rst),
        .PCNext(PCNext),
        .PC(PC)
    );

    // Instruction memory
    InstructionMemory u_instr_mem (
        .A(PC),
        .Instr(Instr)
    );

    // Register file
    RegFile u_regfile (
        .clk(clk),
        .rst(rst),
        .we3(RegWrite),
        .ra1(Instr[19:15]),
        .ra2(Instr[24:20]),
        .wa3(Instr[11:7]),
        .wd3(Result),
        .rd1(RD1),
        .rd2(RD2)
    );

    assign WriteData = RD2;

    // Immediate extend
    Extend u_extend (
        .Instr(Instr[31:7]),
        .ImmSrc(ImmSrc),
        .ImmExt(ImmExt)
    );

    // ALUSrc MUX
    assign SrcB = (ALUSrc == 1'b0) ? RD2 : ImmExt;

    // ALU
    ALU u_alu (
        .A(RD1),
        .B(SrcB),
        .ALUControl(ALUControl),
        .Result(ALUResult),
        .Zero(Zero),
        .Overflow(Overflow)
    );

    // Data memory
    DataMemory u_data_mem (
        .clk(clk),
        .we(MemWrite),
        .funct3(Instr[14:12]), // ADDED: 001 selects lh, 010 selects lw
        .A(ALUResult),
        .WD(WriteData),
        .RD(ReadData)
    );

    // PC  calculations
    assign PCPlus4  = PC + 32'd4;
    assign PCTarget = PC + ImmExt;

    // PCSrc MUX
    assign PCNext = (PCSrc == 1'b0) ? PCPlus4 : PCTarget;

    //ResultSrc MUX
    assign Result = (ResultSrc == 2'b00) ? ALUResult : (ResultSrc == 2'b01) ? ReadData : (ResultSrc == 2'b10) ? PCPlus4 : 32'b0;
endmodule
