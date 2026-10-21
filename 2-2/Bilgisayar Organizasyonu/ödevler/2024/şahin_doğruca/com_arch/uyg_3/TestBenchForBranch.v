
`timescale 1ns / 1ps

module TestBenchForBranch;
reg clk = 0;
reg reset = 1;
reg [31:0] instruction;
reg [31:0] read_data;
reg expected_pc_branch;
reg expected_pc_no_branch;
wire [31:0] pc;
wire [31:0] alu_result;
wire [31:0] write_data;

RiscV_SingleCycle uut(
.clk(clk),
.reset(reset),
.pc(pc),
.instruction(instruction),
.alu_result(alu_result),
.write_data(write_data),
.read_data(read_data)
);

// Clock generation
always #10 clk = ~clk;

initial begin
    // Initialize and assert reset
    clk = 0;
    reset = 1; // Assert reset
    #20; // Maintain reset for a few clock cycles
    reset = 0; // De-assert reset
    
    // Initialize register values for a scenario where the branch should be taken
    uut.registers[4] = 10; // Set R4 = 10
    uut.registers[5] = 10; // Set R5 = 10 (equal to R4)
    
    // Setup BEQ test for branch taken
    // BEQ R4, R5, offset (branch taken because R4 == R5)
    // Constructing the instruction with the appropriate offset for branching
    // Example: Offset of 16 bytes (4 instructions ahead if each instruction is 4 bytes)
    // opcode = 1100011 (BEQ), funct3 = 000 (equality), rs1 = R4, rs2 = R5
    // Offset binary: {imm[12], imm[10:5]} = 7'b0001000, {imm[4:1], imm[11]} = 5'b10000 (represents 16 in two's complement)
    // 31     25 24    20 19    15 14  12 11     8 7      0
// imm[12] imm[10:5] rs2     rs1   funct3 imm[4:1] imm[11] opcode
instruction = 32'b0_000000_00101_00100_000_0100_0_1100011;
  // imm[12]=0, imm[10:5]=000000, rs2=00010, rs1=00001, funct3=000, imm[4:1]=0010, imm[11]=0, opcode=1100011

    #40;
    // Run the simulation for some time to process the instruction
    
    // Check the PC to verify if BEQ was correctly taken
    if (uut.pc !== 16) // Since BEQ should be taken, the PC should jump to the current PC + 16
        $display("Error: BEQ failed to branch as expected, PC: %d", uut.pc);
    else
        $display("BEQ operation successful: branched as expected to PC: %d", uut.pc);
    
   
    $finish;
end

initial begin
    $dumpfile("processor_sim.vcd");
    $dumpvars(0, TestBenchForBranch);
end

endmodule