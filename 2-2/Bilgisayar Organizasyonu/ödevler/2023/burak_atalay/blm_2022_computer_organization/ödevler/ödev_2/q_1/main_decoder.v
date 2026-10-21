module Main_Decoder(
        input wire [6:0] op,
        output wire [1:0] ResultSrc,
        output wire MemWrite, Branch, ALUSrc, RegWrite, Jump,
        output wire [1:0] ImmSrc, ALUop
        );

   reg [10:0] outputs;
   
   always@(*)
    case(op)
    7'b0000011: outputs = 11'b1_00_1_0_01_0_00_0;
    7'b0100011: outputs = 11'b0_01_1_1_00_0_00_0;
    7'b0110011: outputs = 11'b1_xx_0_0_00_0_10_0;
    7'b0010011: outputs = 11'b1_00_1_0_00_0_10_0;
    7'b1100011: outputs = 11'b0_10_0_0_00_1_01_0;
    7'b1101111: outputs = 11'b1_11_0_0_10_0_00_1;
    7'b0000000: outputs = 11'b0_00_0_0_00_0_00_0;
    default: outputs = 11'bx_xx_x_x_xx_x_xx_x;
    endcase

   assign {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUop, Jump} = outputs;	
   
endmodule