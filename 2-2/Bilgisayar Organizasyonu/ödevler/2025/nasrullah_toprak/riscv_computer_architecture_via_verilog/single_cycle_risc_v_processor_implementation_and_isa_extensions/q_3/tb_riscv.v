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

    always begin
        clk = 1'b0;
        #500;
        clk = 1'b1;
        #500;
    end

    initial begin
        $dumpfile("riscv_single_cycle_q3_lh.vcd");
        $dumpvars(0, tb_riscv);

        rst = 1'b1;
        #1000;
        rst = 1'b0;

        #12000;

        $display("x1 = %h  expected = 00000000", x1);
        $display("x2 = %h  expected = ffff1234  // lw", x2);
        $display("x3 = %h  expected = 00001234  // lh lower halfword", x3);
        $display("x4 = %h  expected = ffffffff  // lh upper halfword + sign extension", x4);
        $display("x5 = %h  expected = fffffff0", x5);
        $display("x6 = %h  expected = fffffffc  // srai still works", x6);

        if (x1 == 32'h00000000 &&
            x2 == 32'hFFFF1234 &&
            x3 == 32'h00001234 &&
            x4 == 32'hFFFFFFFF &&
            x5 == 32'hFFFFFFF0 &&
            x6 == 32'hFFFFFFFC) begin
            $display("TEST PASSED: lw, lh and srai are working correctly.");
        end
        else begin
            $display("TEST FAILED: Check register values above.");
        end

        $finish;
    end
endmodule

/*
iverilog -o sim.out *.v
vvp sim.out
gtkwave riscv_single_cycle_q3_lh.vcd
*/
