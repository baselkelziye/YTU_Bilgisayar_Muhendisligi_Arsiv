`timescale 1ns/1ps
`include "cpu_top.v"

module tb_cpu_top;
  // Clock & reset
  reg           clk = 0;
  reg           rst = 1;
  // Program memory için sayaç
  integer       i;

  // CPU top-level sinyalleri
  wire [31:0]   pc, instr, aluOut, memReadData;

  // cpu instantiate
  cpu_top cpu (
    .clk(clk), .rst(rst),
    .pc(pc), .instr(instr),
    .aluOut(aluOut), .memReadData(memReadData)
  );

  // 100 MHz clock
  always #5 clk = ~clk;

  initial begin
    // Dalga kaydı
    $dumpfile("tb_cpu_top.vcd");
    $dumpvars(0, tb_cpu_top);

    // --------- PROGRAM YÜKLEME -------------
    cpu.imem[0]  = 32'h00a00093;   // addi x1, x0, 10
    cpu.imem[1]  = 32'h00300113;   // addi x2, x0, 3
    cpu.imem[2]  = 32'h002081b3;   // add x3, x1, x2
    cpu.imem[3]  = 32'h40208233;   // sub x4, x1, x2
    cpu.imem[4]  = 32'h001122b3;   // slt x5, x2, x1
    cpu.imem[5]  = 32'h0020f333;   // and x6, x1, x2
    cpu.imem[6]  = 32'h0020e3b3;   // or  x7, x1, x2
    cpu.imem[7]  = 32'h00f0f413;   // andi x8, x1, 15
    cpu.imem[8]  = 32'h00816493;   // ori  x9, x2, 8
    cpu.imem[9]  = 32'h00302023;   // sw  x3, 0(x0)
    cpu.imem[10] = 32'h00002503;   // lw  x10,0(x0)
    cpu.imem[11] = 32'h00350463;   // beq x10,x3, +8
    cpu.imem[12] = 32'h00100593;   // addi x11,x0,1
    cpu.imem[13] = 32'h0080066f;   // jal x12, +8
    cpu.imem[14] = 32'h00200693;   // addi x13,x0,2
    // Geri kalanları NOP (0) yap
    for (i = 15; i < 70; i = i + 1) begin
      cpu.imem[i] = 32'h00000013;
    end
    // ---------------------------------------

    // Reset’i kaldır
    #20 rst = 0;

    // Bir süre çalışsın
    repeat (70) @(posedge clk);

    $finish;
  end
endmodule
