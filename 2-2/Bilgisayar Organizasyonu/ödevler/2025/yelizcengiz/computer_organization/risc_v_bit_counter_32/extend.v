// File: extend.v
module extend(
    input  [31:0] instr,
    input  [1:0]  immsrc,
    output reg [31:0] immext
);

  // Combinational extraction of the various RISC-V immediates
  always @(*) begin
    case (immsrc)
      2'b00: // I-type
        immext = {{20{instr[31]}}, instr[31:20]};
      2'b01: // S-type (store)
        immext = {{20{instr[31]}}, instr[31:25], instr[11:7]};
      2'b10: // B-type (branch)
        immext = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
      2'b11: // J-type (JAL)
        immext = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};
      default:
        immext = 32'bx;
    endcase
  end

endmodule
