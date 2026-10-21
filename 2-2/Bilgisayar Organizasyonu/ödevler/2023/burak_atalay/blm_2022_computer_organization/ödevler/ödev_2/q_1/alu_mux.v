module ALU_Mux (
    input [31:0]  WriteData, ImmExt,
    input ALUSrc,
    output [31:0] srcB);

    assign srcB = ALUSrc ? ImmExt : WriteData;

endmodule