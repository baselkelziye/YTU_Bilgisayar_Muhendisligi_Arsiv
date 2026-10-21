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

            2'b00: begin
                ALUControl = 3'b010; // lw, sw -> ADD
            end

            2'b01: begin
                ALUControl = 3'b110; // beq -> SUB
            end

            2'b10: begin
                case (funct3)

                    3'b000: begin
                        if (op5 == 1'b1 && funct7_5 == 1'b1)
                            ALUControl = 3'b110; // sub
                        else
                            ALUControl = 3'b010; // add, addi
                    end

                    3'b010: begin
                        ALUControl = 3'b111; // slt, slti
                    end

                    3'b110: begin
                        ALUControl = 3'b001; // or, ori
                    end

                    3'b111: begin
                        ALUControl = 3'b000; // and, andi
                    end

                    3'b101: begin
                        if (funct7_5 == 1'b1)
                            ALUControl = 3'b011; // srai
                        else
                            ALUControl = 3'b010; // srli desteklenmiyor
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