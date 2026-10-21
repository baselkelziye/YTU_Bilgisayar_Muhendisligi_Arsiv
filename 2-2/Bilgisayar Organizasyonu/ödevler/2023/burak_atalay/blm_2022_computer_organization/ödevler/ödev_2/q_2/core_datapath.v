`include "PC.v"
`include "extend.v"
`include "result_mux.v"
`include "register_file.v"
`include "alu_mux.v"
`include "alu.v"

module Core_Datapath(input clk, reset, RegWrite, PCSrc, ALUSrc,
    input [1:0] ResultSrc,
    input [1:0] ImmSrc,
    input [2:0] ALUControl,
    input [31:0] Instr,
    input [31:0] ReadData,
    output Zero,
    output [31:0] PC,
    output [31:0] ALUResult, WriteData);

    wire [31:0] PCnext, PCplus4, PCtarget;
    wire [31:0]	ImmExt;
    wire [31:0] srcA, srcB;
    wire [31:0]	Result;


    PC PC_1(
        .clk(clk),
        .reset(reset),
        .PCNext(PCnext),
        .PC(PC)
        );

    PC_Plus_4 PC_Plus_4_1(
        .PC(PC),
        .PCPlus4(PCplus4)
        );

    PC_Target PC_Target_1(
        .PC(PC),
        .ImmExt(ImmExt),	
        .PCTarget(PCtarget)
        );

    PC_Mux PC_Mux_1(
        .PC_Plus_4(PCplus4),
        .PC_Target(PCtarget),
        .PCSrc(PCSrc),
        .PC_Next(PCnext)
        );

    Register_File Register_1(
        .clk(clk),
        .WE3(RegWrite),
        .RA1(Instr[19:15]),
        .RA2(Instr[24:20]),
        .WA3((Instr[11:7])),
        .WD3(Result),
        .RD1(srcA),
        .RD2(WriteData)
        );

    Extend Extend_1(
        .Instr(Instr[31:7]),
        .ImmSrc(ImmSrc),
        .ImmExt(ImmExt)
        ); 

    ALU_Mux ALU_Mux_1(
        .WriteData(WriteData), 
        .ImmExt(ImmExt), 
        .ALUSrc(ALUSrc),
        .srcB(srcB)
        );

    ALU ALU_1(
        .srcA(srcA),
        .srcB(srcB),
        .ALUControl(ALUControl),
        .zero(Zero),
        .result(ALUResult)
        );

    Result_Mux Result_Mux_1(
        .ALUResult(ALUResult),
        .ReadData (ReadData),
        .PC_Plus_4(PCplus4),
        .ResultSrc(ResultSrc),
        .Result(Result)
        );
endmodule

