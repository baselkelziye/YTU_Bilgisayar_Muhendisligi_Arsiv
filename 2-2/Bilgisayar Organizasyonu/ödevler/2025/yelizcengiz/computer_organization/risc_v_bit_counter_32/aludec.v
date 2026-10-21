// File: aludec.v
module aludec(
    input        opb5,
    input  [2:0] funct3,
    input        funct7b5,
    input  [1:0] ALUOp,
    output reg [2:0] ALUControl
);

  // TRUE for R–type subtract
  wire RtypeSub = funct7b5 & opb5;

  always @(*) begin
    case (ALUOp)
      2'b00: ALUControl = 3'b000;               // addition
      2'b01: ALUControl = 3'b001;               // subtraction
      default: begin                            // R–type or I–type ALU
        case (funct3)
          3'b000: ALUControl = RtypeSub 
                              ? 3'b001         // sub
                              : 3'b000;        // add, addi
          3'b010: ALUControl = 3'b101;          // slt, slti
          3'b110: ALUControl = 3'b011;          // or, ori
          3'b111: ALUControl = 3'b010;          // and, andi
          default: ALUControl = 3'bxxx;         // undefined
        endcase
      end
    endcase
  end

endmodule
