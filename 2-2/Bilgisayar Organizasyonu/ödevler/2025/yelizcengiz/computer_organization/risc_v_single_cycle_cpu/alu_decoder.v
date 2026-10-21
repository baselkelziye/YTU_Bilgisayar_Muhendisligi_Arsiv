module alu_decoder (
    input  [1:0] alu_op,
    input  [2:0] funct3,
    input        funct7b5,
    output reg [2:0] alu_control
);
    always @(*) begin
        case (alu_op)
            2'b00: alu_control = 3'b000; // lw/sw
            2'b01: alu_control = 3'b001; // beq
            2'b10: begin
                case(funct3)
                    3'b000: alu_control = (funct7b5) ? 3'b001 : 3'b000; // sub/add
                    3'b001: alu_control = 3'b100; // sll
                    3'b010: alu_control = 3'b101; // slt
                    3'b110: alu_control = 3'b011; // or
                    3'b111: alu_control = 3'b010; // and
                    default: alu_control = 3'b000;
                endcase
            end
            default: alu_control = 3'b000;
        endcase
    end
endmodule