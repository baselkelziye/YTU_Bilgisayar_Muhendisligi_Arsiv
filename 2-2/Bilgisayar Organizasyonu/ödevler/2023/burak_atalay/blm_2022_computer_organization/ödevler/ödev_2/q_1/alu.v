module ALU(
    input signed [31:0] srcA, srcB,
	input signed [2:0] ALUControl,
	output signed zero,
	output reg signed [31:0] result);
    
    always@(*)
    case(ALUControl)
        3'b000: result = srcA + srcB; 
        3'b001: result = srcA - srcB; 
        3'b010: result = srcA & srcB;
        3'b011: result = srcA | srcB; 
        3'b100: result = (srcA < srcB) ? 32'b1 : 32'b0;
        default:  result <= 32'b0;
    endcase

    assign zero = (result == 32'b0);
endmodule