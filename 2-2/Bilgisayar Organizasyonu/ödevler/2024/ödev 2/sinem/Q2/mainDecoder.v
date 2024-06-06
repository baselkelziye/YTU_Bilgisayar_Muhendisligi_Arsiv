

module mainDecoder (op,zero,resultScr,memWrite,aluScr,immSrc,regWrite,aluOp,pcSrc);
    input [6:0] op;
    input zero;
    output reg memWrite,aluScr,regWrite;
    output pcSrc;
    output reg [1:0] immSrc,aluOp,resultScr;

    reg branch,jump,temp;

    always @(*) begin
        case(op)
            7'b0000_011: begin
                regWrite = 1'b1;
                immSrc = 2'b00;
                aluScr = 1'b1;
                memWrite = 1'b0;
                resultScr = 2'b01;
                branch = 1'b0;
                aluOp = 2'b00;
                jump = 1'b0;

            end     
            7'b0100_011:begin
                regWrite = 1'b0;
                immSrc = 2'b01;
                aluScr = 1'b1;
                memWrite = 1'b1;
                resultScr = 2'bxx;
                branch = 1'b0;
                aluOp = 2'b00;
                jump = 1'b0;
            end     
            7'b0110_011:begin
                regWrite = 1'b1;
                immSrc = 2'bxx;
                aluScr = 1'b0;
                memWrite = 1'b0;
                resultScr = 2'b00;
                branch = 1'b0;
                aluOp = 2'b10;
                jump = 1'b0;
            end   //R
            7'b1100_011: begin
                regWrite = 1'b0;
                immSrc = 2'b10;
                aluScr = 1'b0;
                memWrite = 1'b0;
                resultScr = 2'bxx;
                branch = 1'b1;
                aluOp = 2'b01;
                jump = 1'b0;
            end//beq
            7'b0010_011:begin
                regWrite = 1'b1;
                immSrc = 2'b00;
                aluScr = 1'b1;
                memWrite = 1'b0;
                resultScr = 2'b00;
                branch = 1'b0;
                aluOp = 2'b10;
                jump = 1'b0;
            end // i type
            7'b1101_111:begin
                regWrite = 1'b1;
                immSrc = 2'b11;
                aluScr = 1'bx;
                memWrite = 1'b0;
                resultScr = 2'b10;
                branch = 1'b0;
                aluOp = 2'bxx;
                jump = 1'b1;
            end  //jal


            default: begin
                regWrite = 1'bx;
                immSrc = 2'bxx;
                aluScr = 1'bx;
                memWrite = 1'bx;
                resultScr = 2'bxx;
                branch = 1'bx;
                aluOp = 2'bxx;
                jump = 1'bx; //assigned x for invalid values
            end 
        endcase
    end
    assign pcSrc = jump | (branch & zero);
endmodule