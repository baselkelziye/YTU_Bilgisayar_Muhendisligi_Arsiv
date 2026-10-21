// File: datapath.v
module datapath(
    input         clk,
    input         reset,
    input  [1:0]  ResultSrc,
    input         PCSrc,
    input         ALUSrc,
    input         RegWrite,
    input  [1:0]  ImmSrc,
    input  [2:0]  ALUControl,
    output        Zero,
    output [31:0] PC,
    input  [31:0] Instr,
    output [31:0] ALUResult,
    output [31:0] WriteData,
    input  [31:0] ReadData
);
  wire [31:0] PCNext, PCPlus4, PCTarget;
  wire [31:0] ImmExt;
  wire [31:0] SrcA, SrcB;
  wire [31:0] Result;

  // PC register
  flopr #(.WIDTH(32)) pcreg (
    .clk   (clk),
    .reset (reset),
    .d     (PCNext),
    .q     (PC)
  );

  // PC+4
  adder pcadd4 (
    PC,
    32'd4,
    PCPlus4
  );

  // Branch target = PC + imm
  adder pcaddbranch (
    PC,
    ImmExt,
    PCTarget
  );

  // choose next PC
  mux2 #(.WIDTH(32)) pcmux (
    PCPlus4,
    PCTarget,
    PCSrc,
    PCNext
  );

  // register file: rs1, rs2, rd, data in, data out
  regfile rf (
    clk,
    RegWrite,
    Instr[19:15],
    Instr[24:20],
    Instr[11:7],
    Result,
    SrcA,
    WriteData
  );

  // sign‐extend immediates
  extend ext (
    Instr,
    ImmSrc,
    ImmExt
  );

  // ALU operand B mux
  mux2 #(.WIDTH(32)) srcbmux (
    WriteData,
    ImmExt,
    ALUSrc,
    SrcB
  );

  // ALU
  alu alu_inst (
    SrcA,
    SrcB,
    ALUControl,
    ALUResult,
    Zero
  );

  // write‐back mux: ALU, Mem, PC+4
  mux3 #(.WIDTH(32)) resultmux (
    ALUResult,
    ReadData,
    PCPlus4,
    ResultSrc,
    Result
  );
endmodule
