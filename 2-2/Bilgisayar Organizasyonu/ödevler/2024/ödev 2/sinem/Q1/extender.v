module extender (input [24:0] instr, input [1:0] immSrc, output reg [31:0] immExt);

    always @(*) begin
        case(immSrc)
            2'b00: immExt = {{20{instr[24]}}, instr[24:13]};
            2'b01, 2'b10: immExt = {{25{instr[24]}}, instr[24:18]};
            2'b11: immExt = {{12{instr[24]}}, instr[24:5]};
            default: immExt = 32'h0;
        endcase
    end

endmodule
