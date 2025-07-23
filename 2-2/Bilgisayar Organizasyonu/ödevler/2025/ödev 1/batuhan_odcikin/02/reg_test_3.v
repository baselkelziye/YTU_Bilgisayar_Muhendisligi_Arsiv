`timescale 1ns / 1ps
`include "datapath.v"
`include "regfile.v"
`include "ALU32.v"

module TB_datapath;

    reg clk, rst, wr;
    reg [2:0] ALUControl;
    reg [1:0] addr1, addr2, addr3;
    wire [31:0] Result;
    wire Zero, Overflow;

    datapath uut (
        .clk(clk),
        .rst(rst),
        .wr(wr),
        .ALUControl(ALUControl),
        .addr1(addr1),
        .addr2(addr2),
        .addr3(addr3),
        .Result(Result),
        .Zero(Zero),
        .Overflow(Overflow)
    );

        wire [31:0] valA, valB;
    assign valA = uut.RF.register[addr1];
    assign valB = uut.RF.register[addr2];

    initial begin
        $dumpfile("reg_test_3_dmp.vcd");
        $dumpvars(0, TB_datapath);

      
        $display("Time\tALUControl\taddr1\taddr2\taddr3\tdata1\t\tdata2\t\tdata3\t\tZero\tOverflow");
        $monitor("%4dns\t%03b\t\t%0d\t%0d\t%0d\t%h\t%h\t%h\t%b\t%b",
        $time, ALUControl, addr1, addr2, addr3, valA, valB, Result, Zero, Overflow);


        // Reset
        clk = 0; rst = 0; wr = 0; #5;
        clk = 1; #5;
        clk = 0; #5;

        // Komut 3: R3 = R2 XOR R0
        ALUControl = 3'b011; wr = 1;
        addr1 = 2'b10; // R2
        addr2 = 2'b00; // R0
        addr3 = 2'b11; // R3
        clk = 1; #5; clk = 0; #5;

        $finish;
    end

endmodule
