`timescale 1ps / 1ps

module RiscVSingleCycle (
    input clk,
    input rst,

    output [31:0] PC,
    output [31:0] Instr,
    output [31:0] ALUResult,
    output [31:0] WriteData,
    output [31:0] Result,
    output Zero,
    output Overflow
);

    wire RegWrite;
    wire [1:0] ImmSrc;
    wire ALUSrc;
    wire MemWrite;
    wire [1:0] ResultSrc;
    wire PCSrc;
    wire [2:0] ALUControl;

    ControlUnit u_control_unit (
        .op(Instr[6:0]),
        .funct3(Instr[14:12]),
        .funct7_5(Instr[30]),
        .Zero(Zero),

        .RegWrite(RegWrite),
        .ImmSrc(ImmSrc),
        .ALUSrc(ALUSrc),
        .MemWrite(MemWrite),
        .ResultSrc(ResultSrc),
        .PCSrc(PCSrc),
        .ALUControl(ALUControl)
    );

    Datapath u_datapath (
        .clk(clk),
        .rst(rst),

        .RegWrite(RegWrite),
        .ImmSrc(ImmSrc),
        .ALUSrc(ALUSrc),
        .MemWrite(MemWrite),
        .ResultSrc(ResultSrc),
        .PCSrc(PCSrc),
        .ALUControl(ALUControl),

        .Instr(Instr),
        .Zero(Zero),
        .Overflow(Overflow),

        .PC(PC),
        .ALUResult(ALUResult),
        .WriteData(WriteData),
        .Result(Result)
    );

endmodule
