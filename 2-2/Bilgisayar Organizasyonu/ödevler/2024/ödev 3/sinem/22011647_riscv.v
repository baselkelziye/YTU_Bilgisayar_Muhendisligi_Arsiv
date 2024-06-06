module adder(
    input [31:0] a, b,
    output [31:0] y
);
    assign y = a + b;
endmodule

module alu (
    input [31:0] a,
    input [31:0] b,
    input [2:0] sel,
    output reg [31:0] y,
    output zero
);
    always @* begin
        case (sel)
            3'b000: y = a + b;  // add, addi
            3'b001: y = a - b;  // sub
            3'b010: y = (a < b) ? 32'b1 : 32'b0;  // slt, slti
            3'b011: y = a | b;  // or, ori
            3'b100: y = a & b;  // and, andi
            default: y = 32'b0;
        endcase
    end

    assign zero = (y == 32'b0);
endmodule

module aludec(
    input opb5,
    input [2:0] funct3,
    input funct7b5,
    input [1:0] ALUOp,
    output reg [2:0] ALUControl
);
    wire RtypeSub;
    assign RtypeSub = funct7b5 & opb5; // TRUE for R–type subtract

    always @* begin
        case(ALUOp)
            2'b00: ALUControl = 3'b000; // addition
            2'b01: ALUControl = 3'b001; // subtraction
            default: case(funct3) // R–type or I–type ALU
                3'b000: ALUControl = (RtypeSub) ? 3'b001 : 3'b000; // sub or add, addi
                3'b010: ALUControl = 3'b010; // slt, slti
                3'b110: ALUControl = 3'b011; // or, ori
                3'b111: ALUControl = 3'b100; // and, andi
                default: ALUControl = 3'bxxx; // ???
            endcase
        endcase
    end
endmodule

module controller(
    input [6:0] op,
    input [2:0] funct3,
    input funct7b5,
    input Zero,
    output [1:0] ResultSrc,
    output MemWrite,
    output PCSrc, ALUSrc,
    output RegWrite, Jump,
    output [1:0] ImmSrc,
    output [2:0] ALUControl
);
    wire [1:0] ALUOp;
    wire Branch;

    maindec md(
        .op(op), .ResultSrc(ResultSrc), .MemWrite(MemWrite), .Branch(Branch),
        .ALUSrc(ALUSrc), .RegWrite(RegWrite), .Jump(Jump), .ImmSrc(ImmSrc), .ALUOp(ALUOp)
    );

    aludec ad(
        .opb5(op[5]), .funct3(funct3), .funct7b5(funct7b5), .ALUOp(ALUOp), .ALUControl(ALUControl)
    );

    assign PCSrc = Branch & Zero | Jump;
endmodule

module datapath(
    input clk, reset,
    input [1:0] ResultSrc,
    input PCSrc, ALUSrc,
    input RegWrite,
    input [1:0] ImmSrc,
    input [2:0] ALUControl,
    output Zero,
    output [31:0] PC,
    input [31:0] Instr,
    output [31:0] ALUResult, WriteData,
    input [31:0] ReadData
);
    wire [31:0] PCNext, PCPlus4, PCTarget;
    wire [31:0] ImmExt;
    wire [31:0] SrcA, SrcB;
    wire [31:0] Result;

    // next PC logic
    flopr #(32) pcreg(.clk(clk), .reset(reset), .d(PCNext), .q(PC));
    adder pcadd4(.a(PC), .b(32'd4), .y(PCPlus4));
    adder pcaddbranch(.a(PC), .b(ImmExt), .y(PCTarget));
    mux2 #(32) pcmux(.d0(PCPlus4), .d1(PCTarget), .s(PCSrc), .y(PCNext));

    // register file logic
    regfile rf(
        .clk(clk), .we3(RegWrite), 
        .a1(Instr[19:15]), .a2(Instr[24:20]), .a3(Instr[11:7]), 
        .wd3(Result), 
        .rd1(SrcA), .rd2(WriteData)
    );

    extend ext(.instr(Instr[31:7]), .immsrc(ImmSrc), .immext(ImmExt));

    // ALU logic
    mux2 #(32) srcbmux(.d0(WriteData), .d1(ImmExt), .s(ALUSrc), .y(SrcB));
    alu alu(.a(SrcA), .b(SrcB), .sel(ALUControl), .y(ALUResult), .zero(Zero));
    mux3 #(32) resultmux(.d0(ALUResult), .d1(ReadData), .d2(PCPlus4), .s(ResultSrc), .y(Result));
endmodule

module dmem(
    input clk, we,
    input [31:0] a, wd,
    output [31:0] rd
);
    reg [31:0] RAM[63:0];

    initial begin

         //initializing the ARR Array

        RAM[0] = 3;
        RAM[1] = 7;
        RAM[2] = 2;
        RAM[3] = 6;
        RAM[4] = 5;
        RAM[5] = 4;
        RAM[6] = 1;
        RAM[7] = 1000;
        RAM[8] = 999;
        RAM[9] = 25;
        RAM[10] = 90;
        RAM[11] = 100;
        RAM[12] = 30;
        RAM[13] = 20;
        RAM[14] = 10;
        RAM[15] = 200;
        RAM[16] = 3300;
        RAM[17] = 250;
        RAM[18] = 12;
        RAM[19] = 75;

    
         //initializing the COUNT Array

        RAM[20] = 17;
        RAM[21] = 13;
        RAM[22] = 18;
        RAM[23] = 14;
        RAM[24] = 15;
        RAM[25] = 16;
        RAM[26] = 19;
        RAM[27] = 1;
        RAM[28] = 2;
        RAM[29] = 9;
        RAM[30] = 6;
        RAM[31] = 5;
        RAM[32] = 8;
        RAM[33] = 10;
        RAM[34] = 12;
        RAM[35] = 4;
        RAM[36] = 0;
        RAM[37] = 3;
        RAM[38] = 11;
        RAM[39] = 7;

        //initializing the RESULT Array

        RAM[40] = 0;
        RAM[41] = 0;
        RAM[42] = 0;
        RAM[43] = 0;
        RAM[44] = 0;
        RAM[45] = 0;
        RAM[46] = 0;
        RAM[47] = 0;
        RAM[48] = 0;
        RAM[49] = 0;
        RAM[50] = 0;
        RAM[51] = 0;
        RAM[52] = 0;
        RAM[53] = 0;
        RAM[54] = 0;
        RAM[55] = 0;
        RAM[56] = 0;
        RAM[57] = 0;
        RAM[58] = 0;
        RAM[59] = 0;

    end


    assign rd = RAM[a[31:2]]; // word aligned

    always @(posedge clk) begin
        if (we) begin
            RAM[a[31:2]] <= wd;
        end
    end
endmodule


module extend(
    input [31:7] instr,
    input [1:0] immsrc,
    output [31:0] immext
);
    reg [31:0] immext;
    always @* begin
        case(immsrc)
            // I−type
            2'b00: immext = {{20{instr[31]}}, instr[31:20]};
            // S−type (stores)
            2'b01: immext = {{20{instr[31]}}, instr[31:25], instr[11:7]};
            // B−type (branches)
            2'b10: immext = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
            // J−type (jal)
            2'b11: immext = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};
            default: immext = 32'bx; // undefined
        endcase
    end
endmodule

module flopenr #(
    parameter WIDTH = 8
)(
    input clk, reset, en,
    input [WIDTH-1:0] d,
    output [WIDTH-1:0] q
);
    reg [WIDTH-1:0] q;
    always @(posedge clk or posedge reset) begin
        if (reset) q <= 0;
        else if (en) q <= d;
    end
endmodule

module flopr #(
    parameter WIDTH = 8
)(
    input clk, reset,
    input [WIDTH-1:0] d,
    output [WIDTH-1:0] q
);
    reg [WIDTH-1:0] q;
    always @(posedge clk or posedge reset) begin
        if (reset) q <= 0;
        else q <= d;
    end
endmodule

module imem(
    input [31:0] a,
    output [31:0] rd
);
    reg [31:0] RAM[63:0];

    initial begin
        $readmemh("22011647_hexcodes.txt", RAM);
    end

    assign rd = RAM[a[31:2]];
endmodule

module maindec(
    input [6:0] op,
    output reg [1:0] ResultSrc,
    output reg MemWrite,
    output reg Branch, ALUSrc,
    output reg RegWrite, Jump,
    output reg [1:0] ImmSrc,
    output reg [1:0] ALUOp
);
    always @* begin
        case(op)
            7'b0000011: {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = 11'b1_00_1_0_01_0_00_0; // lw 
            7'b0100011: {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = 11'b0_01_1_1_00_0_00_0; // sw
            7'b0110011: {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = 11'b1_xx_0_0_00_0_10_0; // R–type
            7'b1100011: {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = 11'b0_10_0_0_00_1_01_0; // beq
            7'b0010011: {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = 11'b1_00_1_0_00_0_10_0; // I–type ALU
            7'b1101111: {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = 11'b1_11_0_0_10_0_00_1; // jal
            default: {RegWrite, ImmSrc, ALUSrc, MemWrite, ResultSrc, Branch, ALUOp, Jump} = 11'bx_xx_x_x_xx_x_xx_x; // ???
        endcase
    end
endmodule

module mux2 #(
    parameter WIDTH = 8
)(
    input [WIDTH-1:0] d0, d1,
    input s,
    output [WIDTH-1:0] y
);
    assign y = s ? d1 : d0;
endmodule

module mux3 #(
    parameter WIDTH = 8
)(
    input [WIDTH-1:0] d0, d1, d2,
    input [1:0] s,
    output [WIDTH-1:0] y
);
    reg [WIDTH-1:0] y;
    always @* begin
        case(s)
            2'b00: y = d0;
            2'b01: y = d1;
            2'b10: y = d2;
            default: y = {WIDTH{1'bx}};
        endcase
    end
endmodule

module regfile(
    input clk,
    input we3,
    input [4:0] a1, a2, a3,
    input [31:0] wd3,
    output [31:0] rd1, rd2
);
    reg [31:0] rf[31:0];
    initial rf[0] = 0;

    always @(posedge clk) begin
        if (we3) begin
            rf[a3] <= wd3;
        end
    end

    assign rd1 = (a1 != 0) ? rf[a1] : 32'b0;
    assign rd2 = (a2 != 0) ? rf[a2] : 32'b0;
endmodule

module riscvsingle(
    input clk, reset,
    output [31:0] PC,
    input [31:0] Instr,
    output MemWrite,
    output [31:0] ALUResult, WriteData,
    input [31:0] ReadData
);
    wire ALUSrc, RegWrite, Jump, Zero;
    wire [1:0] ResultSrc, ImmSrc;
    wire [2:0] ALUControl;

    controller c(
        .op(Instr[6:0]), .funct3(Instr[14:12]), .funct7b5(Instr[30]), .Zero(Zero),
        .ResultSrc(ResultSrc), .MemWrite(MemWrite), .PCSrc(PCSrc),
        .ALUSrc(ALUSrc), .RegWrite(RegWrite), .Jump(Jump),
        .ImmSrc(ImmSrc), .ALUControl(ALUControl)
    );

    datapath dp(
        .clk(clk), .reset(reset), .ResultSrc(ResultSrc), .PCSrc(PCSrc),
        .ALUSrc(ALUSrc), .RegWrite(RegWrite),
        .ImmSrc(ImmSrc), .ALUControl(ALUControl),
        .Zero(Zero), .PC(PC), .Instr(Instr),
        .ALUResult(ALUResult), .WriteData(WriteData), .ReadData(ReadData)
    );
endmodule

module top(
    input clk, reset,
    output [31:0] WriteData, DataAdr,
    output MemWrite
);
    wire [31:0] PC, Instr, ReadData;

    riscvsingle rvsingle(
        .clk(clk), .reset(reset), .PC(PC), .Instr(Instr), .MemWrite(MemWrite),
        .ALUResult(DataAdr), .WriteData(WriteData), .ReadData(ReadData)
    );

    imem imem(
        .a(PC), .rd(Instr)
    );

    dmem dmem(
        .clk(clk), .we(MemWrite), .a(DataAdr), .wd(WriteData), .rd(ReadData)
    );
endmodule
