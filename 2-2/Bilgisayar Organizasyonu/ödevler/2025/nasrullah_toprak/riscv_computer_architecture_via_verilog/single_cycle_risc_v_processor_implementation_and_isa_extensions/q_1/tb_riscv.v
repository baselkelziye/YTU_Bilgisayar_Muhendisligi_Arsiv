`timescale 1ps / 1ps

module tb_riscv;

    reg clk;
    reg rst;

    wire [31:0] PC;
    wire [31:0] Instr;
    wire [31:0] ALUResult;
    wire [31:0] WriteData;
    wire [31:0] Result;
    wire Zero;
    wire Overflow;

    reg [31:0] x1;
    reg [31:0] x2;
    reg [31:0] x3;
    reg [31:0] x4;
    reg [31:0] x5;
    reg [31:0] x6;
    reg [31:0] x7;
    reg [31:0] x8;
    reg [31:0] x9;
    reg [31:0] x10;
    reg [31:0] x11;
    reg [31:0] x12;
    reg [31:0] x13;
    reg [31:0] x14;
    reg [31:0] x15;

    RiscVSingleCycle dut (
        .clk(clk),
        .rst(rst),
        .PC(PC),
        .Instr(Instr),
        .ALUResult(ALUResult),
        .WriteData(WriteData),
        .Result(Result),
        .Zero(Zero),
        .Overflow(Overflow)
    );

    always @(*) begin
        x1  = dut.u_datapath.u_regfile.registers[1];
        x2  = dut.u_datapath.u_regfile.registers[2];
        x3  = dut.u_datapath.u_regfile.registers[3];
        x4  = dut.u_datapath.u_regfile.registers[4];
        x5  = dut.u_datapath.u_regfile.registers[5];
        x6  = dut.u_datapath.u_regfile.registers[6];
        x7  = dut.u_datapath.u_regfile.registers[7];
        x8  = dut.u_datapath.u_regfile.registers[8];
        x9  = dut.u_datapath.u_regfile.registers[9];
        x10 = dut.u_datapath.u_regfile.registers[10];
        x11 = dut.u_datapath.u_regfile.registers[11];
        x12 = dut.u_datapath.u_regfile.registers[12];
        x13 = dut.u_datapath.u_regfile.registers[13];
        x14 = dut.u_datapath.u_regfile.registers[14];
        x15 = dut.u_datapath.u_regfile.registers[15];
    end

    initial begin
        clk = 1'b0;
        forever #500 clk = ~clk;
    end

    initial begin
        $dumpfile("riscv_single_cycle.vcd");
        $dumpvars(0, tb_riscv);

        rst = 1'b1;
        #1000;
        rst = 1'b0;

        #25000;

        $display("x1  = %d", x1);
        $display("x2  = %d", x2);
        $display("x3  = %d", x3);
        $display("x4  = %d", x4);
        $display("x5  = %d", x5);
        $display("x6  = %d", x6);
        $display("x7  = %d", x7);
        $display("x8  = %d", x8);
        $display("x9  = %d", x9);
        $display("x10 = %d", x10);
        $display("x11 = %d", x11);
        $display("x12 = %d", x12);
        $display("x13 = %d", x13);
        $display("x14 = %d", x14);
        $display("x15 = %d", x15);

        $finish;
    end

endmodule

/*
iverilog -o sim.out *.v
vvp sim.out
gtkwave riscv_single_cycle.vcd
*/