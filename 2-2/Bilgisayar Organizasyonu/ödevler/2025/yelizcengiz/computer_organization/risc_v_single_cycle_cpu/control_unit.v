module control_unit (
    input  [6:0] opcode,
    output       regwrite,
    output       alusrc,
    output       memwrite,
    output [1:0] resultsrc,
    output [1:0] imm_src,
    output       branch,
    output       jump,
    output [1:0] alu_op
);
    reg [10:0] controls;

    assign {regwrite, imm_src, alusrc, memwrite, resultsrc, branch, alu_op, jump} = controls;

    always @(*) begin
        case(opcode)
            7'b0000011: controls = 11'b1_00_1_0_01_0_00_0; // lw
            7'b0100011: controls = 11'b0_01_1_1_xx_0_00_0; // sw
            7'b0110011: controls = 11'b1_xx_0_0_00_0_10_0; // R-type
            7'b1100011: controls = 11'b0_10_0_0_xx_1_01_0; // beq
            7'b0010011: controls = 11'b1_00_1_0_00_0_10_0; // I-type
            7'b1101111: controls = 11'b1_11_x_0_10_0_xx_1; // jal
            7'b0110111: controls = 11'b1_11_x_0_11_0_00_0; // lui      ResultSrc=11, Imm=11
            default:     controls = 11'b0_00_0_0_00_0_00_0;
        endcase
    end
endmodule
