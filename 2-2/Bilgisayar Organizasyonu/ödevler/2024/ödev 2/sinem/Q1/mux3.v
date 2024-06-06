module mux3 (resultScr,aluResult,readData,pcPlus4,out);

    input[1:0] resultScr;
    input [31:0] aluResult,readData,pcPlus4;
    output reg[31:0] out;
    
    always @* begin
        case (resultScr)
            2'b00: out = aluResult;
            2'b01: out = readData;
            2'b10: out = pcPlus4;
            default: out = 32'bx;
        endcase
    end

endmodule