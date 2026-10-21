`include "alu.v"
`include "ins.v"

`timescale 1ns / 1ps

module instruction_based_testbench();

reg [31:0] pc;  // Program Counter
reg [31:0] instruction;  // Instruction register
reg [31:0] read_data1, read_data2, write_data; // Register file simulation
reg [31:0] imm_data;  // Immediate data for immediate operations
reg [4:0] alu_control;  // Control signal for ALU
wire [31:0] alu_result;
wire alu_zero;
reg mem_write, mem_read;  // Memory control signals
wire [31:0] mem_data_out;  // Data from memory

// Assume a simple memory model for load/store
reg [31:0] memory [0:255];  // A small memory array

// Instantiate the ALU
alu DUT (
    .input1(read_data1),
    .input2(read_data2),
    .alu_control(alu_control),
    .result(alu_result),
    .zero(alu_zero)
);

initial begin
    $dumpfile("test.vcd");
    $dumpvars(0, instruction_based_testbench);

    // Initialize PC
    pc = 32'd0;
    mem_write = 0;
    mem_read = 0;

    // Test Scenario Start
    $display("Starting Instruction based tests on ALU and memory operations.");

    // ADD Test
    read_data1 = 32'd10;
    read_data2 = 32'd20;
    alu_control = 5'b00001;  // ALU_ADD
    #10;
    $display("ADD Test: 10 + 20 = %d", alu_result);

    // SUB Test
    read_data1 = 32'd30;
    read_data2 = 32'd15;
    alu_control = 5'b00010;  // ALU_SUB
    #10;
    $display("SUB Test: 30 - 15 = %d", alu_result);

    // AND Test
    read_data1 = 32'b10101010;
    read_data2 = 32'b11001100;
    alu_control = 5'b00011;  // ALU_AND
    #10;
    $display("AND Test: 0b10101010 & 0b11001100 = %b", alu_result);

    // OR Test
    read_data1 = 32'b10101010;
    read_data2 = 32'b11001100;
    alu_control = 5'b00100;  // ALU_OR
    #10;
    $display("OR Test: 0b10101010 | 0b11001100 = %b", alu_result);

    // SLT Test
    read_data1 = 32'd10;
    read_data2 = 32'd20;
    alu_control = 5'b00101;  // ALU_SLT
    #10;
    $display("SLT Test: 10 < 20 = %d", alu_result);

    // BEQ Test (branch if equal)
    read_data1 = 32'd100;
    read_data2 = 32'd100;
    alu_control = 5'b00110;  // ALU_SUB and check zero
    #10;
    if (alu_zero) $display("BEQ Test: Branch taken (100 == 100)");

    // End Test Scenario
    $display("All instruction based tests completed.");
    $finish;  // End simulation
end

endmodule
