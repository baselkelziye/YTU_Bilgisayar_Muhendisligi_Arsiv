`timescale 1ps / 1ps

module ALUDecoder (
    input  [1:0] ALUOp,
    input  [2:0] funct3,
    input        op5,
    input        funct7_5,

    output reg [2:0] ALUControl
);

    always @(*) begin
        case (ALUOp)

            // lw, sw: ADD
            2'b00: begin
                ALUControl = 3'b010;
            end

            // beq: SUB
            2'b01: begin
                ALUControl = 3'b110;
            end

            // R + I-type
            2'b10: begin
                case (funct3)

                    // add, sub, addi
                    3'b000: begin
                        if ({op5, funct7_5} == 2'b11) begin
                            ALUControl = 3'b110; // sub
                        end else begin
                            ALUControl = 3'b010; // add/addi
                        end
                    end

                    // slt, slti
                    3'b010: begin
                        ALUControl = 3'b111;
                    end

                    // or, ori
                    3'b110: begin
                        ALUControl = 3'b001;
                    end

                    // and, andi
                    3'b111: begin
                        ALUControl = 3'b000;
                    end

                    default: begin
                        ALUControl = 3'b010;
                    end
                endcase
            end
            default: begin
                ALUControl = 3'b010;
            end
        endcase
    end
endmodule