`timescale 1ns / 1ps

module TestBench;
reg clk = 0;
reg reset = 1;
reg [31:0] instruction;
reg [31:0] read_data;

wire [31:0] pc;
wire [31:0] alu_result;
wire [31:0] write_data;
integer expected_pc_branch;
integer expected_pc_no_branch;
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
clk = 0;
reset = 1; // Assert reset
instruction = 32'b0;
read_data = 32'b0;

// Assert reset for a sufficient period
#100;
reset = 0;

// Wait a cycle after reset
#20;

// Setup and execute ADD instruction
uut.registers[2] = 5; // R2 = 5
uut.registers[3] = 3; // R3 = 3
instruction = 32'b0000000_00011_00010_000_00001_0110011; // ADD R1, R2, R3
#40; // Allow time for ADD operation to complete

// Setup and execute SUB instruction
uut.registers[4] = 10; // R4 = 10
uut.registers[5] = 4; // R5 = 4
instruction = {7'b0100000, 5'b00101, 5'b00100, 3'b000, 5'b00110, 7'b0110011}; // SUB R6, R4, R5
#40; // Allow time for SUB operation to complete

// Setup and execute AND instruction
uut.registers[7] = 6; // R7 = 6
uut.registers[8] = 9; // R8 = 9
instruction = {7'b0000000, 5'b01000, 5'b00111, 3'b111, 5'b01001, 7'b0110011}; // AND R9, R7, R8
#40; // Allow time for AND operation to complete

// Setup and execute OR instruction
uut.registers[10] = 7; // R10 = 7
uut.registers[11] = 8; // R11 = 8
instruction = {7'b0000000, 5'b01011, 5'b01010, 3'b110, 5'b01100, 7'b0110011}; // OR R12, R10, R11
#40; // Allow time for OR operation to complete

// Test memory operations
// Setup and execute SW instruction
uut.registers[15] = 4; // Base address for store
uut.registers[16] = 321; // Data to store
uut.memory[4] = 0; // Initial memory content at index 4
instruction = 32'b000000000100_01111_010_10000_0100011; // SW R16, 4(R15)
#40; // Allow time for SW operation to complete

// Check if memory was updated correctly

// Wait a cycle after reset
#100;
uut.registers[1] = 0; // Clear register 1 for use as a base address
uut.registers[2] = 123; // Data to be stored into memory


// Initialize memory address
instruction = 0; // Clear any previous instruction
uut.memory[10] = 0; // Clear memory at index 10

// Store Word operation
// SW R2, 4(R1) --> Store the value in R2 to the address (R1 + 4)
uut.registers[1] = 6; // Set base address in R1 to 6
instruction = {7'b0000000, 5'b00010, 5'b00001, 3'b010, 5'b0_0100, 7'b0100011}; // SW opcode, rs2=2, rs1=1, imm=4
#20; // Execute the SW instruction

// Check if the data was stored correctly
if (uut.memory[10] !== 123) begin
$display("Error: Memory store failed at index 10. Expected 123, found %d", uut.memory[10]);
end else begin
$display("Store operation successful: Memory[10] = %d", uut.memory[10]);
end

// Load Word operation
// LW R4, 4(R1) --> Load the value from memory address (R1 + 4) into R4
instruction = {7'b0000000, 5'b00100, 5'b00001, 3'b010, 5'b0_0100, 7'b0000011}; // LW opcode, rd=4, rs1=1, imm=4
#20; // Execute the LW instruction

// Check if the loaded data is correct
if (uut.registers[4] !== 123) begin
$display("Error: Memory load failed for R4. Expected 123, found %d", uut.registers[4]);
end else begin
$display("Load operation successful: R4 = %d", uut.registers[4]);
end
// Reset and setup phase
#100;
// Initialize registers and values for BEQ test

// Continue simulation
#100;

$finish;
end





initial begin
$dumpfile("processor_sim.vcd"); // Specify the VCD file name
$dumpvars(0, TestBench); // Dump all variables of the TestBench and submodules
end

endmodule
