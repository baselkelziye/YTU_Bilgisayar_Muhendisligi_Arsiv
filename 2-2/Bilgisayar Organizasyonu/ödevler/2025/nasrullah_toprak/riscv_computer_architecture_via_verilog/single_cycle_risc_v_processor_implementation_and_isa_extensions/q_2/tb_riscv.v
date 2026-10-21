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
        x1 = dut.u_datapath.u_regfile.registers[1];
        x2 = dut.u_datapath.u_regfile.registers[2];
        x3 = dut.u_datapath.u_regfile.registers[3];
        x4 = dut.u_datapath.u_regfile.registers[4];
        x5 = dut.u_datapath.u_regfile.registers[5];
        x6 = dut.u_datapath.u_regfile.registers[6];
    end

    initial begin
        clk = 1'b0;
        forever #500 clk = ~clk;
    end

    initial begin
        $dumpfile("riscv_single_cycle_q2.vcd");
        $dumpvars(0, tb_riscv);

        rst = 1'b1;
        #1000;
        rst = 1'b0;

        #12000;

        $display("x1 = %h", x1);
        $display("x2 = %h", x2);
        $display("x3 = %h", x3);
        $display("x4 = %h", x4);
        $display("x5 = %h", x5);
        $display("x6 = %h", x6);

        $finish;
    end

endmodule

/*
iverilog -o sim.out *.v
vvp sim.out
gtkwave riscv_single_cycle_q2.vcd
*/