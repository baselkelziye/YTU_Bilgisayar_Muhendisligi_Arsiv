`include "instructionMemory.v"
`include "dataMemory.v"
`include "riscv.v"

module completeRiscv(clk, reset);

    input clk, reset;
    wire [31:0] WriteData, DataAdr; 
    wire MemWrite;

    wire [31:0] PC;

    wire [31:0] Instr, ReadData;

    riscv r(clk, reset, PC, Instr, MemWrite, DataAdr, WriteData,ReadData);
    instructionMemory i( PC, Instr);
    dataMemory d(DataAdr, WriteData,MemWrite,ReadData,clk);

endmodule