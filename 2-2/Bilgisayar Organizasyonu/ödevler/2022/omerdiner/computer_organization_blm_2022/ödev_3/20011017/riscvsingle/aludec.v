module aludec(
    input opb5,
    input [2:0] funct3,
    input funct7b5,
    input [1:0] ALUOp,
    output reg [2:0] ALUControl
);
    wire RtypeSub;
    assign RtypeSub = funct7b5 & opb5; // TRUE for R–type subtract

    always @* begin
        case(ALUOp)
            2'b00: ALUControl = 3'b000; // addition
            2'b01: ALUControl = 3'b001; // subtraction
            default: case(funct3) // R–type or I–type ALU
                3'b000: ALUControl = (RtypeSub) ? 3'b001 : 3'b000; // sub or add, addi
                3'b010: ALUControl = 3'b010; // slt, slti
                3'b110: ALUControl = 3'b011; // or, ori
                3'b111: ALUControl = 3'b100; // and, andi
                default: ALUControl = 3'bxxx; // ???
            endcase
        endcase
    end
endmodule