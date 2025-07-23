// ALU: Aritmetik ve mantık işlemlerini yapan modül
module ALU (
    input  [31:0] srcA,
    input  [31:0] srcB,
    input  [2:0]  ALUControl,
    output reg [31:0] ALUResult,
    output        Zero
);
    always @(*) begin
        case (ALUControl)
            3'b000: ALUResult = srcA + srcB;               // ADD, ADDI
            3'b001: ALUResult = srcA - srcB;               // SUB, BEQ
            3'b010: ALUResult = srcA & srcB;               // AND, ANDI
            3'b011: ALUResult = srcA | srcB;               // OR, ORI
            3'b101: ALUResult = (srcA < srcB) ? 32'd1 : 32'd0; // SLT, SLTI
            3'b110: ALUResult = srcA << srcB;          // SLL added
            default: ALUResult = 32'd0;
        endcase
    end

    assign Zero = (ALUResult == 32'd0);
endmodule