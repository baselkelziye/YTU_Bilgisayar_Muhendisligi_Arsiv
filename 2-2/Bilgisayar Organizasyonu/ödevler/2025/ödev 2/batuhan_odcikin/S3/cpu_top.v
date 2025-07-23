`timescale 1ns/1ps

`include "control_unit.v"
`include "imm_gen.v"
`include "reg_file.v"
`include "alu_control.v"
`include "alu.v"
`include "data_memory.v"

module cpu_top (
    input         clk,
    input         rst,
    output [31:0] pc,
    output [31:0] instr,
    output [31:0] aluOut,
    output [31:0] memReadData
);
    ,
    reg  [31:0] PC;
    wire [31:0] PCPlus4, PCBranch, PCNext;

    always @(posedge clk or posedge rst) begin
        if (rst) 
            PC <= 0; 
        else 
            PC <= PCNext;
    end
    assign pc       = PC;
    assign PCPlus4  = PC + 4;
,
    reg [31:0] imem [0:255];
    
    assign instr = imem[PC[9:2]];

    // Main Control
    wire        regWrite, memWrite, aluSrc;
    wire [2:0]  immSrc;
    wire [1:0]  resultSrc, pcSrc, aluOp;
    wire        zero;
    ControlUnit control_unit(
        .opcode(instr[6:0]),
        .zero(zero),
        .regWrite(regWrite),
        .memWrite(memWrite),
        .aluSrc(aluSrc),
        .immSrc(immSrc),
        .resultSrc(resultSrc),
        .pcSrc(pcSrc),
        .aluOp(aluOp)
    );

    // Immediate Generator
    wire [31:0] immExt;
    ImmGen imm_gen(
        .instr(instr),
        .ImmSrc(immSrc),
        .immExt(immExt)
    );

    // Register File
    wire [31:0] rd1, rd2;
    wire [31:0] wd3 = (resultSrc==2'b01) ? memReadData :
                      (resultSrc==2'b10) ? PCPlus4 :
                                            aluOut;
    RegFile reg_file(
        .clk(clk),
        .we3(regWrite),
        .ra1(instr[19:15]),
        .ra2(instr[24:20]),
        .wa3(instr[11:7]),
        .wd3(wd3),
        .rd1(rd1),
        .rd2(rd2)
    );

    // ALU Control + ALU
    wire [2:0] aluControl;
    ALUControl alu_control(
        .aluOp(aluOp),
        .funct3(instr[14:12]),
        .funct7_5(instr[30]),
        .ALUControl(aluControl)
    );
    wire [31:0] aluInB = aluSrc ? immExt : rd2;
    ALU alu(
        .srcA(rd1),
        .srcB(aluInB),
        .ALUControl(aluControl),
        .ALUResult(aluOut),
        .Zero(zero)
    );

    // Data Memory
    DataMemory data_memory(
        .clk(clk),
        .we(memWrite),
        .addr(aluOut),
        .wd(rd2),
        .rd(memReadData)
    );

    // PC Next Mux
    assign PCBranch = PCPlus4 + immExt;
    assign PCNext   = (pcSrc==2'b10) ? (PCPlus4 + immExt) :  // JAL
                      (pcSrc==2'b01) ? PCBranch :            // BEQ
                                         PCPlus4;           
endmodule
