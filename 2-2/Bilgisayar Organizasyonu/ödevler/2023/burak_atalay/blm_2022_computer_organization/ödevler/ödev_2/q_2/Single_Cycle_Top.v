`include "Single_Cycle_Core.v"
`include "instruction_memory.v"
`include "data_memory.v"

module Single_Cycle_Top(
    input clk, reset,
    output [31:0] WriteData, DataAddress,
    output MemWrite);

    wire [31:0] PC, Instr, ReadData;

    Single_Cycle_Core Single_Cycle_Core_1(
        .clk(clk),
        .reset(reset),
        .Instr(Instr),
        .ReadData(ReadData),
        .PC(PC),
        .MemWrite(MemWrite),
        .ALUResult(DataAddress),
        .WriteData(WriteData));

    Instruction_Memory Instruction_Memory_1(
        .A(PC),
        .RD(Instr));

    Data_Memory Data_Memory_1 (
        .clk(clk), 
        .WE(MemWrite),
        .A(DataAddress), 
        .WD(WriteData),
        .RD(ReadData));
endmodule