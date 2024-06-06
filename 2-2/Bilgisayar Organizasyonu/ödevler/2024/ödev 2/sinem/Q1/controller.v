`include "mainDecoder.v"
`include "aluDecoder.v"


module controller(op,funct3, funct7b5, Zero,ResultSrc, MemWrite, PCSrc, ALUSrc,RegWrite, ImmSrc,ALUControl);

    input[6:0] op;
    input[2:0] funct3;
    input funct7b5,Zero;
    output [1:0] ResultSrc;
    output MemWrite,PCSrc, ALUSrc,RegWrite;
    output [1:0] ImmSrc;
    output [2:0] ALUControl;

    wire [1:0] ALUOp;

    mainDecoder md1(op,Zero,ResultSrc,MemWrite,ALUSrc,ImmSrc,RegWrite,ALUOp,PCSrc);
    aluDecoder ad1(funct3,funct7b5,ALUOp,op[5],ALUControl);

endmodule
