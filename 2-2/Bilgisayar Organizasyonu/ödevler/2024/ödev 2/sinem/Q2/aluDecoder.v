module aluDecoder (funct3, funct7_5, aluOp, op_5, aluControl);
    input [2:0] funct3;
    input funct7_5, op_5;
    input [1:0] aluOp;

    output reg [2:0] aluControl;

    always @(*) begin
        case (aluOp)
            2'b00: aluControl = 3'b000;
            2'b01: aluControl = 3'b001;
            2'b10: begin
                case (funct3)
                    3'b000: begin
                        if (op_5 && funct7_5) begin
                            aluControl = 3'b001;
                        end else begin
                            aluControl = 3'b000;
                        end
                    end
                    3'b010: aluControl = 3'b101;
                    3'b110: aluControl = 3'b011;
                    3'b111: aluControl = 3'b010;
                    3'b101: aluControl = 3'b100; //for sra
                    default: aluControl = 3'bxxx;   // assigned xxx for invalid aluop values
                endcase
            end
        endcase
    end
endmodule
