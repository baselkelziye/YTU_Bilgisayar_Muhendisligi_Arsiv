// ======================= ImmGen.v =======================
module ImmGen (
    input  [31:0] instr,
    input  [1:0]  ImmSrc,   // 00=I, 01=S, 10=B, 11=J
    output reg [31:0] immExt
);
    always @(*) begin
        case (ImmSrc)
            2'b00: // I-type
                immExt = {{20{instr[31]}}, instr[31:20]};
            2'b01: // S-type
                immExt = {{20{instr[31]}}, instr[31:25], instr[11:7]};
            2'b10: // B-type (<<1)
                immExt = {{19{instr[31]}}, instr[31], instr[7],
                          instr[30:25], instr[11:8], 1'b0};
            2'b11: // J-type (<<1)
                immExt = {{11{instr[31]}}, instr[31], instr[19:12],
                          instr[20], instr[30:21], 1'b0};
            default:
                immExt = 32'd0;
        endcase
    end
endmodule
