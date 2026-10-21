`timescale 1ps / 1ps

module ControlUnit (
    input  [6:0] op,
    input  [2:0] funct3,
    input  funct7_5,
    input  Zero,

    output RegWrite,
    output [1:0] ImmSrc,
    output ALUSrc,
    output MemWrite,
    output [1:0] ResultSrc,
    output PCSrc,
    output [2:0] ALUControl
);

    wire Branch;
    wire Jump;
    wire [1:0] ALUOp;

    MainDecoder main_decoder (
        .op(op),
        .RegWrite(RegWrite),
        .ImmSrc(ImmSrc),
        .ALUSrc(ALUSrc),
        .MemWrite(MemWrite),
        .ResultSrc(ResultSrc),
        .Branch(Branch),
        .ALUOp(ALUOp),
        .Jump(Jump)
    );

    ALUDecoder alu_decoder (
        .ALUOp(ALUOp),
        .funct3(funct3),
        .op5(op[5]),
        .funct7_5(funct7_5),
        .ALUControl(ALUControl)
    );

    assign PCSrc = (Branch & Zero) | Jump;
endmodule