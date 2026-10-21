module singleCycleProcessorWithSra(clk, rst);
    input clk, rst;

    wire PCSrc, regWrite, zero, memWrite, ALUSrc;
    wire [1:0] immSrc, resultSrc;
    wire [2:0] ALUControl;
    wire [31:0] PCNext, PCPlus4, PCTarget;
    wire [31:0] RD1, RD2, immExt, PC, instruction, result;
    wire [31:0] srcB, ALUResult, readData;
    
    PC pc(PC, PCNext, clk, rst);
    adder PCAdder(PCPlus4, PC, 32'd4);
    mux nextPC(PCNext, PCPlus4, PCTarget, PCSrc);
    adder jumpAdder(PCTarget, PC, immExt);

    instructionMemory instrMem(instruction, PC, rst);
    regFile regF(RD1, RD2, instruction[19:15], instruction[24:20], instruction[11:7], result, regWrite, clk, rst);
    signExtender signExt(immExt, instruction, immSrc);   
    mux muxRegtoALU(srcB, RD2, immExt, ALUSrc);
    ALU alu(ALUResult, zero, RD1, srcB, ALUControl);
    controlUnit control(PCSrc, resultSrc, memWrite, ALUControl, ALUSrc, immSrc, regWrite, instruction[6:0], instruction[14:12], instruction[31:25], zero);
    dataMemory dataMem(readData, ALUResult, RD2, memWrite, clk, rst);
    mux4 muxDatatoReg1(result, ALUResult, readData, PCPlus4, {32{1'bx}}, resultSrc);
endmodule

module ALU(result, zero, A, B, ALUControl);
    input [31:0] A, B;
    input [2:0] ALUControl;

    output [31:0] result;
    output zero;
    
    wire [31:0] sum, sra;
    wire msb;
    
    assign sum = ALUControl[0] ? (A + (~B + 1)) : (A + B);
    assign sra = $signed(A) >>> B; // sağa kaydırma işlemi A'nın MSB'i dikkate alınarak gerçekleştirilir.
    
    assign result = (ALUControl == 3'b000) ? sum :
                    (ALUControl == 3'b001) ? sum :
                    (ALUControl == 3'b010) ? A & B :
                    (ALUControl == 3'b011) ? A | B :
                    (ALUControl == 3'b100) ? sra : // sra işlemi 100 seçim bitiyle sonuç olarak çıkar.
                    (ALUControl == 3'b101) ? {{31{1'b0}}, sum[31]} :
                    {32{1'bx}};

    assign zero = (result == 32'b0);
endmodule

module adder(result, A, B);
    input [31:0] A, B;
    output [31:0] result;

    assign result = A + B;
endmodule

module PC(PC, PCNext, clk, rst);
    input [31:0] PCNext;
    input clk, rst;
    output reg [31:0] PC;

    always@(posedge clk)
        if(~rst) PC <= PCNext;
        else PC <= {32{1'b0}};
endmodule

module signExtender(immExt, instruction, immSrc);
    input [31:0] instruction;
    input [1:0] immSrc;
    output [31:0] immExt;

    assign immExt = (immSrc == 2'b00) ? {{20{instruction[31]}}, instruction[31:20]} : // I-Type
                    (immSrc == 2'b01) ? {{20{instruction[31]}}, instruction[31:25], instruction[11:7]} : // S-Type
                    (immSrc == 2'b10) ? {{19{instruction[31]}}, instruction[31], instruction[7], instruction[30:25], instruction[11:8], 1'b0} : // B-Type
                    {{12{instruction[31]}}, instruction[19:12], instruction[20], instruction[30:21], 1'b0} ; // J-Type
endmodule

module mux(result, A, B, select);
    input [31:0] A, B;
    input select;    
    output [31:0] result;

    assign result = select ? B : A;
endmodule

module mux4(result, A, B, C, D, select);
    input [31:0] A, B, C, D;
    input [1:0] select;    
    output [31:0] result;

    assign result = (select == 2'b00) ? A :
                    (select == 2'b01) ? B :
                    (select == 2'b10) ? C : D;
endmodule

module regFile(RD1, RD2, A1, A2, A3, WD3, WE3, clk, rst);
    input [4:0] A1, A2, A3;
    input clk, rst, WE3;
    input [31:0] WD3;
    output [31:0] RD1, RD2;

    reg [31:0] register[31:0];

    integer i;
    initial begin
        for (i=0; i<32; i=i+1) begin
            register[i] = 0;
        end
    end

    always@(posedge clk)
        if(WE3) register[A3] <= WD3;
    
    //aşağıda bi terslik var
    assign RD1 = (~rst) ? register[A1] : {32{1'b0}};
    assign RD2 = (~rst) ? register[A2] : {32{1'b0}};    
endmodule

module instructionMemory(RD, A, rst);
    input [31:0] A;
    input rst;
    output [31:0] RD;

    reg [31:0] memory[31:0];

    initial
        begin
            $readmemh("instructionMemory.dat", memory);
            /*
                addi x5, x5, 146    // x5 = 146
                addi x6, x6, 4      // x6 = 4
                sra  x5, x5, x6     // x5 = 146 / 2^4 = 9
                addi x7, zero, -146 // x7 = -146 (FFFFFF6E)
                sra  x7, x7, x6     // x7 = -146/ 2^4 = -10 (FFFFFFF6)
            */
        end

    assign RD = (rst) ? {32{1'b0}} : memory[A/4]; //sadece 4'ün katlarındaki verileri okumaması için

endmodule

module dataMemory(RD, A, WD, WE, clk, rst);
    input [31:0] A, WD;
    input WE, clk, rst;
    output [31:0] RD;

    reg [31:0] memory[63:0];

    always@(posedge clk)
        if(WE) memory[A] <= WD;

    assign RD = (rst) ? {32{1'b0}} : memory[A];
endmodule

module ALUDecoder(ALUControl, funct3, funct7, op, ALUOp);
    input [2:0] funct3;
    input [6:0] funct7, op;
    input [1:0] ALUOp;
    output [2:0] ALUControl;

    assign ALUControl = (ALUOp == 2'b00) ? 3'b000 : // lw, sw (add)
                        (ALUOp == 2'b01) ? 3'b001 : // beq (sub)
                        ((ALUOp == 2'b10) & (funct3 == 3'b000) & ({op[5], funct7[5]} == 2'b11)) ? 3'b001 : // sub
                        ((ALUOp == 2'b10) & (funct3 == 3'b000) & ({op[5], funct7[5]} != 2'b11)) ? 3'b000 : // add
                        ((ALUOp == 2'b10) & (funct3 == 3'b010)) ? 3'b101 : // slt
                        ((ALUOp == 2'b10) & (funct3 == 3'b101) & ({op[5], funct7[5]} == 2'b11)) ? 3'b100 : //sra
                        ((ALUOp == 2'b10) & (funct3 == 3'b110)) ? 3'b011 : // or
                        ((ALUOp == 2'b10) & (funct3 == 3'b111)) ? 3'b010 : // and
                                                                  3'bxxx ;
endmodule

module mainDecoder(regWrite, immSrc, ALUSrc, memWrite, resultSrc, branch, ALUOp, jump, op);
    input [6:0] op;
    output regWrite, ALUSrc, memWrite, branch, jump;
    output [1:0] ALUOp, immSrc, resultSrc;

    assign regWrite = (op == 7'b0000011 | op == 7'b0110011 | op == 7'b0010011 | op == 7'b1101111) ? 1'b1 : 1'b0;
    assign immSrc = (op == 7'b0000011 | op == 7'b0010011) ? 2'b00 :
                    (op == 7'b0100011) ? 2'b01 :
                    (op == 7'b1100011) ? 2'b10 :
                    (op == 7'b1101111) ? 2'b11 : 
                    2'bxx;
    assign ALUSrc = (op == 7'b0000011 | op == 7'b0100011 | op == 7'b0010011) ? 1'b1 :
                    (op == 7'b0110011 | op == 7'b1100011) ? 1'b0 :
                    1'bx;
    assign memWrite = (op == 7'b0100011) ? 1'b1 : 1'b0;
    assign resultSrc = (op == 7'b0110011 | op == 7'b0010011) ? 2'b00 :
                       (op == 7'b0000011) ? 2'b01 : 
                       (op == 7'b1101111) ? 2'b10 :
                       2'bxx;
    assign branch = (op == 7'b1100011) ? 1'b1 : 1'b0;
    assign ALUOp = (op == 7'b0000011 | op == 7'b0100011) ? 2'b00 :
                   (op == 7'b1100011) ? 2'b01 : 
                   (op == 7'b0110011 | op == 7'b0010011) ? 2'b10 :
                   2'bxx;
    assign jump = (op == 7'b1101111) ? 1'b1 : 1'b0;
endmodule

module controlUnit(PCSrc, resultSrc, memWrite, ALUControl, ALUSrc, immSrc, regWrite, op, funct3, funct7, zero);
    input [6:0] op, funct7;
    input [2:0] funct3;
    input zero;

    output PCSrc, memWrite, ALUSrc, regWrite;
    output [1:0] resultSrc, immSrc;
    output [2:0] ALUControl;

    wire [1:0] ALUOp;
    wire branch, jump;

    mainDecoder mainDecoder(regWrite, immSrc, ALUSrc, memWrite, resultSrc, branch, ALUOp, jump, op);
    ALUDecoder ALUDecoder(ALUControl, funct3, funct7, op, ALUOp);

    assign PCSrc = (zero & branch) | jump;
endmodule