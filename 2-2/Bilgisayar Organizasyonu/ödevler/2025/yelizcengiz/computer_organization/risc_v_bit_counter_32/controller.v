// File: controller.v
module controller(
    input  [6:0] op,
    input  [2:0] funct3,
    input        funct7b5,
    input        Zero,
    output [1:0] ResultSrc,
    output       MemWrite,
    output       PCSrc,
    output       ALUSrc,
    output       RegWrite,
    output       Jump,
    output [1:0] ImmSrc,
    output [2:0] ALUControl
);
  wire [1:0] ALUOp;
  wire       Branch;

  // maindec: op, ResultSrc, MemWrite, Branch,
  //         ALUSrc, RegWrite, Jump, ImmSrc, ALUOp
  maindec u_md (
    op,
    ResultSrc,
    MemWrite,
    Branch,
    ALUSrc,
    RegWrite,
    Jump,
    ImmSrc,
    ALUOp
  );

  // aludec: op[5], funct3, funct7b5, ALUOp, ALUControl
  aludec u_ad (
    op[5],
    funct3,
    funct7b5,
    ALUOp,
    ALUControl
  );

  assign PCSrc = (Branch & Zero) | Jump;
endmodule
