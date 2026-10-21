`timescale 1ns / 1ps

module TestBenchForJumpAndLink;

    // Inputs
    reg clk;
    reg reset;

    // Outputs
    wire [31:0] pc;
    wire [31:0] alu_result;
    wire [31:0] write_data;
    wire [31:0] read_data = 32'b0;  // Assume no data read from memory in this test

    // Instantiate the Unit Under Test (UUT)
    RiscV_SingleCycle uut (
        .clk(clk),
        .reset(reset),
        .pc(pc),
        .instruction(instruction),
        .alu_result(alu_result),
        .write_data(write_data),
        .read_data(read_data)
    );

    // Test instruction (JAL)
    reg [31:0] instruction;

    // Clock generation
    always #10 clk = ~clk;

    // Initialize and provide test stimuli
    initial begin
        clk = 0;
        reset = 1;
        instruction = 32'b0;
        #20 reset = 0; // End of reset

        // Set a JAL instruction
        // opcode: 1101111, rd: 00001, imm[20]:0, imm[10:1]:0000001000, imm[11]:0, imm[19:12]:00000000
        instruction = 32'b00000000_00000000_000_00001_1101111;  // Jumps forward by 16 bytes, links to x1

         // Run for a sufficient time to observe the operation
        $finish;  // End simulation
    end

    // Monitor changes and display results
    initial begin
        $monitor("Time = %t, PC = %d, Next PC = %d, Register[1] = %d",
                 $time, pc, uut.next_pc, uut.registers[1]);
    end
    initial begin
$dumpfile("processor_sim.vcd");
$dumpvars(0, TestBenchForJumpAndLink);
end

endmodule
