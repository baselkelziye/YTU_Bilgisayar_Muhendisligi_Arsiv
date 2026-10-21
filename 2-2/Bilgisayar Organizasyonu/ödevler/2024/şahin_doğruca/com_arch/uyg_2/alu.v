module alu(
    input [31:0] input1,
    input [31:0] input2,
    input [4:0] alu_control,
    output reg [31:0] result,
    output zero
);

// ALU control signals for different operations
localparam ALU_ADD  = 5'b00001;
localparam ALU_SUB  = 5'b00010;
localparam ALU_AND  = 5'b00011;
localparam ALU_OR   = 5'b00100;
localparam ALU_SLT  = 5'b00101;
localparam ALU_SLTI = 5'b00110;
localparam ALU_ADDI = 5'b00111;
localparam ALU_ANDI = 5'b01000;
localparam ALU_ORI  = 5'b01001;
localparam ALU_SLL  = 5'b01010;
localparam ALU_SRL  = 5'b01011;
localparam ALU_SRA  = 5'b01100;
localparam ALU_LUI  = 5'b01101;

always @(*) begin
    case(alu_control)
        ALU_ADD, ALU_ADDI:   // Addition and immediate addition
            result = input1 + input2;
        ALU_SUB:             // Subtraction
            result = input1 - input2;
        ALU_AND, ALU_ANDI:   // AND and immediate AND
            result = input1 & input2;
        ALU_OR, ALU_ORI:     // OR and immediate OR
            result = input1 | input2;
        ALU_SLT, ALU_SLTI:   // Set on less than and immediate set on less than
            result = ($signed(input1) < $signed(input2)) ? 32'b1 : 32'b0;
        ALU_SLL:             // Shift left logical
            result = input1 << input2[4:0];
        ALU_SRL:             // Shift right logical
            result = input1 >> input2[4:0];
        ALU_SRA:             // Shift right arithmetic
            result = ($signed(input1) >>> input2[4:0]);
        ALU_LUI:             // Load upper immediate
            result = input2 << 16;
        default: 
            result = 32'b0;
    endcase
end

assign zero = (result == 0); // Zero flag for BEQ and similar instructions

endmodule
