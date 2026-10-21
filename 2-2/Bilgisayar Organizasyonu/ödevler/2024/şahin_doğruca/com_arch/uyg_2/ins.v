module control_unit(
    input [6:0] opcode,
    input [2:0] funct3,
    input [6:0] funct7,
    output reg [4:0] alu_control
);

always @(opcode or funct3 or funct7) begin
    case (opcode)
        7'b0110011: begin  // Bu, genel R-type opcode
            case (funct3)
                3'b101: begin // Shift işlemleri
                    if (funct7 == 7'b0100000) alu_control <= 5'b01100; // SRA
                    else alu_control <= 5'b01011;  // SRL
                end
                // Diğer funct3 kodları
            endcase
        end
        // Diğer opcode işlemleri
    endcase
end

endmodule
