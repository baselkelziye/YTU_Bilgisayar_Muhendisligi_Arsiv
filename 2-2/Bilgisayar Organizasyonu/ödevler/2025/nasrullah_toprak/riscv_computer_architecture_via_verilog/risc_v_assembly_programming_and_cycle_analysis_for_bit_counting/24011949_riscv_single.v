// File: riscv_single.v
module riscv_single(
    input         clk,
    input         reset,
    output [31:0] PC,
    input  [31:0] Instr,
    output        MemWrite,
    output [31:0] ALUResult,
    output [31:0] WriteData,
    input  [31:0] ReadData
);
  wire        ALUSrc, RegWrite, Jump, Zero;
  wire [1:0]  ResultSrc, ImmSrc;
  wire        PCSrc;          // <-- changed from [1:0] to 1 bit
  wire [2:0]  ALUControl;

  // controller: op, funct3, funct7b5, Zero,
  //             ResultSrc, MemWrite, PCSrc, ALUSrc,
  //             RegWrite, Jump, ImmSrc, ALUControl
  controller u_ctrl (
    Instr[6:0],
    Instr[14:12],
    Instr[30],
    Zero,
    ResultSrc,
    MemWrite,
    PCSrc,
    ALUSrc,
    RegWrite,
    Jump,
    ImmSrc,
    ALUControl
  );

  // datapath: clk, reset,
  //           ResultSrc, PCSrc, ALUSrc, RegWrite,
  //           ImmSrc, ALUControl,
  //           Zero, PC, Instr,
  //           ALUResult, WriteData, ReadData
  datapath u_dp (
    clk,
    reset,
    ResultSrc,
    PCSrc,
    ALUSrc,
    RegWrite,
    ImmSrc,
    ALUControl,
    Zero,
    PC,
    Instr,
    ALUResult,
    WriteData,
    ReadData
  );
endmodule
