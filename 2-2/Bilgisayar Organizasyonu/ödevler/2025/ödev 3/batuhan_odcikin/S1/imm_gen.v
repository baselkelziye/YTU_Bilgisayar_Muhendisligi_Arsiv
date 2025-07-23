module ImmGen (
    input  [31:0] instr,
    input  [2:0]  ImmSrc,   // artık 3 bit
    output reg [31:0] immExt
);
    always @(*) begin
        case (ImmSrc) // 2 bit yeterli olmadığından 3 bite yükseltildi
          3'b000: // I-type 
            immExt = {{20{instr[31]}}, instr[31:20]};
          3'b001: // S-type
            immExt = {{20{instr[31]}}, instr[31:25], instr[11:7]};
          3'b010: // B-type
            immExt = {{19{instr[31]}}, instr[31], instr[7],
                      instr[30:25], instr[11:8], 1'b0};
          3'b011: // J-type (JAL)
            immExt = {{11{instr[31]}}, instr[31], instr[19:12],
                      instr[20], instr[30:21], 1'b0};
          3'b100: // U-type (LUI)
            immExt = {instr[31:12], 12'b0};
          default:
            immExt = 32'd0;
        endcase
    end
endmodule
