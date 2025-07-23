// ======================= ControlUnit.v =======================
module ControlUnit (
    input  [6:0] opcode,
    input        zero,
    output reg   regWrite,
    output reg   memWrite,
    output reg   aluSrc,
    output reg [2:0] immSrc, // 3 biye yükseltildi
    output reg [1:0] resultSrc,
    output reg [1:0] pcSrc,
    output reg [1:0] aluOp
);
    reg branch;
    always @(*) begin
        // Default değerler
        regWrite  = 1'b0;
        memWrite  = 1'b0;
        aluSrc    = 1'b0;
        immSrc    = 3'b000;
        resultSrc = 2'b00;
        pcSrc     = 2'b00;
        aluOp     = 2'b00;
        branch    = 1'b0;

        case (opcode)
            7'b0000011: begin // LW
                regWrite  = 1; memWrite = 0; aluSrc = 1;
                immSrc    = 3'b000; resultSrc = 2'b01; aluOp = 2'b00;
            end
            7'b0100011: begin // SW
                regWrite  = 0; memWrite = 1; aluSrc = 1;
                immSrc    = 3'b001; aluOp = 2'b00;
            end
            7'b1100011: begin // BEQ
                regWrite  = 0; memWrite = 0; aluSrc = 0; branch = 1;
                immSrc    = 3'b010; aluOp = 2'b01;
            end
            7'b1101111: begin // JAL
                regWrite  = 1; memWrite = 0; aluSrc = 0;
                immSrc    = 3'b011; resultSrc = 2'b10; pcSrc = 2'b10;
            end
            7'b0010011: begin // I-type ALU (ADDI, SLTI, ANDI, ORI)
                regWrite  = 1; memWrite = 0; aluSrc = 1;
                immSrc    = 3'b000; resultSrc = 2'b00; aluOp = 2'b10;
            end
             7'b0110111: begin // LUI
            regWrite=1; memWrite=0; aluSrc=0;  // ALU’nın kullanılmadığı dal
            immSrc=3'b100; resultSrc=2'b11;     // wb ← immExt
            pcSrc=2'b00; aluOp=2'b00;
            end
            default: ;
        endcase

        // Branch doğru ve Zero=1 ise PCSrc=01
        if (branch & zero)
            pcSrc = 2'b01;
    end
endmodule
