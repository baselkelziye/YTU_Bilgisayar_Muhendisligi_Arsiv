`include "program_counter.v"
`include "adder.v"
`include "controller.v"
`include "extend.v"
`include "data_memory.v"
`include "instruction_memory.v"
`include "mux.v"
`include "register.v"
`include "alu.v"

module processor(
    input clk, reset,
    output Zero,
    output [31:0] PC,
    output [31:0] WriteData,
    output [31:0] ReadData,
    output [31:0] ALUResult
);

wire [31:0] PCNext, PCPlus4, ImmExt, PCTarget, Result, SrcA, SrcB;
wire [31:0] instruction;
wire PCSrc, ALUSrc, RegWrite, MemWrite;
wire [1:0] ResultSrc, ImmSrc;
wire [2:0] ALUControl;

program_counter pc(reset, clk, PCNext, PC);
instruction_memory im(PC, instruction);

controller controller(
    instruction[6:0], instruction[14:12], instruction[30], Zero,
    PCSrc, ResultSrc, MemWrite, ALUControl, ALUSrc, ImmSrc, RegWrite
    );

add4 add4(PC, PCPlus4);
adder adder(PC, ImmExt, PCTarget);
mux_2x1 mux1(PCTarget, PCPlus4, PCSrc, PCNext);

register register(RegWrite, clk, instruction[19:15], instruction[24:20], instruction[11:7], Result, SrcA, WriteData);
extend ext(instruction[31:7], ImmSrc, ImmExt);

mux_2x1 mux2(ImmExt, WriteData, ALUSrc, SrcB);
alu alu(SrcA, SrcB, ALUControl, Zero, ALUResult);
    
data_memory dm(MemWrite, clk, ALUResult, WriteData, ReadData);
    
mux_4x1 mux3(32'bx, PCPlus4, ReadData, ALUResult, ResultSrc, Result);

endmodule