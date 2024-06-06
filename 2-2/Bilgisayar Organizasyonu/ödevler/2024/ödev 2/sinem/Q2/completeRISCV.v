`include "instructionMemory.v"
`include "dataMemory.v"
`include "riscv.v"

module completeRiscv(clk, reset, WriteData, DataAdr,MemWrite);

    input clk, reset;
    output [31:0] WriteData, DataAdr; 
    output MemWrite;

    wire [31:0] PC, Instr, ReadData;
  
    riscv r(clk, reset,PC,Instr,MemWrite, DataAdr, WriteData,ReadData);
    instructionMemory i( PC, Instr);
    dataMemory d(DataAdr, WriteData,MemWrite,ReadData,clk);

endmodule