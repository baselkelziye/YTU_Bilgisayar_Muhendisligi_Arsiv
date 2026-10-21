module ALU_Decoder(
        input opb5,
        input [2:0] funct3,
        input wire funct7b5,
        input wire [1:0] ALUOp,
        output reg [2:0] ALUControl
        );

    wire RtypeSub;
    assign RtypeSub = funct7b5 & opb5;

    always@(*)
    begin
	case(ALUOp)
        2'b00:  ALUControl = 3'b000;
        2'b01:  ALUControl = 3'b001;
        2'b10:
        case(funct3)
            3'b000:
            if (RtypeSub) ALUControl = 3'b001; //sub
            else ALUControl = 3'b000; //add,addi
            3'b010: ALUControl = 3'b101; //slt 
            3'b110: ALUControl = 3'b011; //or,ori
            3'b111: ALUControl = 3'b010; //and,andi
            default: ALUControl = 3'b0;
        endcase  
        default: ALUControl = 3'b0;
	endcase
    end

endmodule