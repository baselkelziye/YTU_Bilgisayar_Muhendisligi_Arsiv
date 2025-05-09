module alu_decoder(op5, funct3, funct7, ALUOp, ALUControl);
    input op5;
    input [2:0] funct3;
    input funct7;
    input [1:0] ALUOp;
    output reg [2:0] ALUControl;

    always @(*) begin
        case (ALUOp)
            2'b00: ALUControl <= 3'b000;
            2'b01: ALUControl <= 3'b001;
            2'b10: begin
                case(funct3)
                    3'b000: begin
                        case({op5, funct7})
                            2'b11: ALUControl <= 3'b001; // SUB
                            default: ALUControl <= 3'b000; // ADD
                        endcase
                    end
                    3'b010: ALUControl <= 3'b101; // SLT
                    3'b110: ALUControl <= 3'b011; // OR
                    3'b111: ALUControl <= 3'b010; // AND
                endcase
            end
        endcase
    end
endmodule

module main_decoder(op, ResultSrc, MemWrite, Branch, Jump, ALUOp, ALUSrc, 
                    ImmSrc, RegWrite);
    input [6:0] op;
    output reg [1:0] ResultSrc, ALUOp, ImmSrc;
    output reg MemWrite, Branch, Jump, ALUSrc, RegWrite;

    always @(*) begin
    	case (op)
            7'b0000011: begin // lw
                RegWrite <= 1;
                MemWrite <= 0;
                Branch <= 0;
                ALUSrc <= 1;
                ALUOp <= 2'b00;
                ImmSrc <= 2'b00;
                ResultSrc <= 2'b01;
                Jump <= 0;
            end
			7'b0010011: begin // I-type
    			RegWrite <= 1;
                MemWrite <= 0;
                Branch <= 0; 
                ALUSrc <= 1; 
                ImmSrc <= 2'b00; 
                ResultSrc <= 2'b00; 
				ALUOp <= 2'b10;
                Jump <= 0;
			end
            	7'b0100011: begin // sw
    			RegWrite <= 0;
                MemWrite <= 1;
                Branch <= 0;
                ALUSrc <= 1;
                ALUOp <= 2'b00;
                ImmSrc <= 2'b01;
                ResultSrc <= 2'bx;
                Jump <= 0;
			end	
                7'b0110011: begin // R-type
    			RegWrite <= 1;
                MemWrite <= 0;
                Branch <= 0; 
                ALUSrc <= 0; 
                ImmSrc <= 2'bx; 
                ResultSrc <= 2'b00; 
                ALUOp <= 2'b10;
                Jump <= 0;
			end		
			7'b1100011: begin	// beq
    			RegWrite <= 0;
                MemWrite <= 0;
                Branch <= 1;
                ALUSrc <= 0;
                ALUOp <= 2'b01;
                ImmSrc <= 2'b10;
                ResultSrc <= 2'bxx;
                Jump <= 0;
			end			
			7'b1101111: begin	// jal
                RegWrite <= 1;
                MemWrite <= 0;
                Branch <= 0;
                ALUSrc <= 1'bx;
                ALUOp <= 2'bxx;
                ImmSrc <= 2'b11;
                ResultSrc <= 2'b10;
                Jump <= 1;
    		end
		endcase
	end
endmodule

module controller(op, funct3, funct7, Zero, PCSrc, ResultSrc, MemWrite, ALUControl,
                ALUSrc, ImmSrc, RegWrite);
    input [6:0] op;
    input [2:0] funct3;
    input funct7, Zero;
    output [2:0] ALUControl;
    output [1:0] ImmSrc, ResultSrc;
    output PCSrc, MemWrite, ALUSrc, RegWrite;

    wire Branch, Jump, temp;
    wire [1:0] ALUOp;

    main_decoder main_decoder(op, ResultSrc, MemWrite, Branch, Jump, ALUOp, ALUSrc, ImmSrc, RegWrite);
    alu_decoder alu_decoder(op[5], funct3, funct7, ALUOp, ALUControl);
    assign PCSrc = (Branch & Zero) | Jump;
endmodule