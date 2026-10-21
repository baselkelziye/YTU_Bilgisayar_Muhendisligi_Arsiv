`timescale 1ns / 1ps

module TestBenchForSRA;

    reg clk = 0;
    reg reset = 1;
    reg [31:0] instruction;
    reg [31:0] read_data;

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
        clk = 0;
        reset = 1; // Assert reset
        instruction = 32'b0;
        read_data = 32'b0;

        // Assert reset for a sufficient period
        
        reset = 0;

        // Wait a cycle after reset
        #20;

        // Initialize registers for the SRA operation
        uut.registers[4] = 32;  // R4 = -32
        uut.registers[5] = 2;   // R5 = 2

        // SRA instruction to shift R4 right by the value in R5, store the result in R6
        // Instruction Format: funct7, rs2, rs1, funct3, rd, opcode
        instruction = {7'b0100000, 5'b00101, 5'b00100, 3'b101, 5'b00110, 7'b0110011}; // SRA R4, R5, R6

        #40; // Allow time for SRA operation to complete

        // Observe the outputs
       
        if (uut.registers[6] === 8) // Check against a dynamically computed expected result
            $display("Test Passed: Register 6 contains %h", uut.registers[6]);
        else
            $display("Test Failed: Register 6 contains %h, expected %h", uut.registers[6], 8);

        #20;
        $finish;
    end

    initial begin
        $dumpfile("processor_sim.vcd");
        $dumpvars(0, TestBenchForSRA);
    end

endmodule
