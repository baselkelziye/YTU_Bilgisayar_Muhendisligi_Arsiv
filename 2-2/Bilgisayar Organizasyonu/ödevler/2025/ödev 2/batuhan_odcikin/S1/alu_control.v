`timescale 1ns/1ps
module ALUControl (
    input  [1:0] aluOp,
    input  [2:0] funct3,
    input        funct7_5,
    output reg [2:0] ALUControl
);
    always @(*) begin
        case(aluOp)
        2'b00: ALUControl=3'b000; // ADD
        2'b01: ALUControl=3'b001; // SUB
        2'b10: begin              // R-type / I-type
            case(funct3)
            3'b000: ALUControl = funct7_5 ? 3'b001 : 3'b000; // SUB/ADD
            3'b010: ALUControl = 3'b101;                    // SLT
            3'b110: ALUControl = 3'b011;                    // OR
            3'b111: ALUControl = 3'b010;                    // AND
            default: ALUControl = 3'b000;
            endcase
        end
        default: ALUControl=3'b000;
        endcase
    end
endmodule
