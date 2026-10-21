`timescale 1ns / 1ps
`include "RiscV_SingleCycle.v"

module TestBench;
    reg clk = 0;
    reg reset = 1;

    wire [31:0] pc;
    wire [31:0] alu_result;
    wire [31:0] write_data;
    wire [31:0] read_data = 32'b0;  // Assume no external data reads for simplicity

    RiscV_SingleCycle uut(
        .clk(clk),
        .reset(reset),
        .pc(pc),
        .alu_result(alu_result),
        .write_data(write_data),
        .read_data(read_data)
    );

    // Clock generation
    always #10 clk = !clk;

    reg [31:0] ARR [0:19];
    reg [31:0] COUNT [0:19];
    reg [31:0] RESULT [0:19];
    integer i;

    initial begin
        $dumpfile("processor_sim.vcd");
        $dumpvars(0, TestBench);

        // Assert reset
        reset = 1;
        #20; // Hold reset for 100ns
        reset = 0;
        uut.registers[2] = 5; // R2 = 5
        uut.registers[3] = 3; // R3 = 3
        uut.registers[4] = 10; // R4 = 10
        uut.registers[5] = 4; // R5 = 4
        uut.registers[7] = 6; // R7 = 6
        uut.registers[8] = 9; // R8 = 9
        uut.registers[10] = 7; // R10 = 7
        uut.registers[11] = 8; // R11 = 8
       
        #200;
        // Let the processor run for a while

        ARR[0] = 3;    ARR[1] = 7;    ARR[2] = 2;    ARR[3] = 6;
        ARR[4] = 5;    ARR[5] = 4;    ARR[6] = 1;    ARR[7] = 1000;
        ARR[8] = 999;  ARR[9] = 25;   ARR[10] = 90;  ARR[11] = 100;
        ARR[12] = 30;  ARR[13] = 20;  ARR[14] = 10;  ARR[15] = 200;
        ARR[16] = 3300;ARR[17] = 250; ARR[18] = 12;  ARR[19] = 75;

        COUNT[0] = 17; COUNT[1] = 13; COUNT[2] = 18; COUNT[3] = 14;
        COUNT[4] = 15; COUNT[5] = 16; COUNT[6] = 19; COUNT[7] = 1;
        COUNT[8] = 2;  COUNT[9] = 9;  COUNT[10] = 6; COUNT[11] = 5;
        COUNT[12] = 8; COUNT[13] = 10;COUNT[14] = 12;COUNT[15] = 4;
        COUNT[16] = 0; COUNT[17] = 3; COUNT[18] = 11;COUNT[19] = 7;


        for(i = 0; i < 20; i++) begin
            RESULT[COUNT[i]] = ARR[i];
        end

        for(i = 0; i < 20; i++) begin
            #10;
            $display("Result %d : %d", i, RESULT[i]);

        end

        



        $finish;
    end
endmodule
