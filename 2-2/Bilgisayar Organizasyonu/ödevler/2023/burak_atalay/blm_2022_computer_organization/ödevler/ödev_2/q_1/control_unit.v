`include "alu_decoder.v"
`include "main_decoder.v"

module Control_Unit(
    input [6:0] op,
    input [2:0] funct3,
    input funct7b5, Zero,

    output wire [1:0] ResultSrc,
    output wire	MemWrite, PCSrc, ALUSrc, RegWrite,Jump,
    output wire [1:0] ImmSrc,
    output wire [2:0] ALUControl
    );

   wire [1:0] ALUop;
   wire	Branch;
   
    Main_Decoder Main_Decoder_1(
        .op(op),
        .ResultSrc(ResultSrc),
        .MemWrite(MemWrite),
        .Branch(Branch),
        .ALUSrc(ALUSrc),
        .RegWrite(RegWrite),
        .Jump(Jump),
        .ImmSrc(ImmSrc),
        .ALUop(ALUop) );
   
    ALU_Decoder ALU_Decoder_1(
        .opb5(op[5]),
        .funct3(funct3),
        .funct7b5(funct7b5),
        .ALUOp(ALUop),
        .ALUControl(ALUControl) );

    assign PCSrc = Branch & Zero | Jump;
   
endmodule

