module maindec(
    input [6:0] op,
    output reg [1:0] ResultSrc,
    output reg MemWrite,
    output reg Branch, ALUSrc,
    output reg RegWrite, Jump,
    output reg [1:0] ImmSrc,
    output reg [1:0] ALUOp
);
    always @* begin
        case(op)
            7'b0000011: {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = 11'b1_00_1_0_01_0_00_0; // lw
            7'b0100011: {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = 11'b0_01_1_1_00_0_00_0; // sw
            7'b0110011: {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = 11'b1_xx_0_0_00_0_10_0; // R–type
            7'b1100011: {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = 11'b0_10_0_0_00_1_01_0; // beq
            7'b0010011: {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = 11'b1_00_1_0_00_0_10_0; // I–type ALU
            7'b1101111: {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = 11'b1_11_0_0_10_0_00_1; // jal
            default: {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = 11'bx_xx_x_x_xx_x_xx_x; // ???
        endcase
    end
endmodule