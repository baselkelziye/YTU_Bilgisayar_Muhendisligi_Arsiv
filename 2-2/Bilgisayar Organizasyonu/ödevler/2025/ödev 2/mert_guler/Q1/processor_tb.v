`timescale 1ns / 1ps
`include "processor.v"

// iverilog -o processor processor_tb.v
// vvp processor  
// gtkwave processor_tb.vcd 

module processor_tb;
  reg clk;
  reg reset;
  wire Zero;
  wire [31:0] PC;
  wire [31:0] WriteData;
  wire [31:0] ReadData;
  wire [31:0] ALUResult;

  processor processor (
    .clk(clk),
    .reset(reset),
    .Zero(Zero),
    .PC(PC),
    .WriteData(WriteData),
    .ReadData(ReadData),
    .ALUResult(ALUResult)
  );

  initial clk = 0;
  always #5 clk = ~clk;

  initial begin
    $dumpfile("processor_tb.vcd");
    $dumpvars(0, processor);

    reset = 1;
    #20;
    reset = 0;

    #500;

    $display("x1 = %d", processor.register.registerFile[1]); // Beklenen: 1
    $display("x2 = %d", processor.register.registerFile[2]); // Beklenen: 2
    $display("x3 = %d", processor.register.registerFile[3]); // Beklenen: 3
    $display("x4 = %d", processor.register.registerFile[4]); // Beklenen: 1
    $display("x5 = %d", processor.register.registerFile[5]); // Beklenen: 0
    $display("x6 = %d", processor.register.registerFile[6]); // Beklenen: 3
    $display("x7 = %d", processor.register.registerFile[7]); // Beklenen: 3
    $display("x8 = %d", processor.register.registerFile[8]); // Beklenen: 1
    $display("x9 = %d", processor.register.registerFile[9]); // Beklenen: 1
    $display("x10 = %d", processor.register.registerFile[10]); // Beklenen: 2
    $display("x11 = %d", processor.register.registerFile[11]); // Beklenen: 0
    $display("x12 = %d", processor.register.registerFile[12]); // Beklenen: 3
    $display("x13 = %h", processor.register.registerFile[13]); // Beklenen: 00000038
    $display("memory[0] = %d", processor.dm.memory[0]); // Beklenen: 3

    if (processor.register.registerFile[1] !== 1) $display("HATA: x1 beklenen 1 degil!");
    if (processor.register.registerFile[2] !== 2) $display("HATA: x3 beklenen 2 degil!");
    if (processor.register.registerFile[3] !== 3) $display("HATA: x3 beklenen 3 degil!");
    if (processor.register.registerFile[4] !== 1) $display("HATA: x4 beklenen 1 degil!");
    if (processor.register.registerFile[5] !== 0) $display("HATA: x5 beklenen 0 degil!");
    if (processor.register.registerFile[6] !== 3) $display("HATA: x3 beklenen 3 degil!");
    if (processor.register.registerFile[7] !== 3) $display("HATA: x7 beklenen 3 degil!");
    if (processor.register.registerFile[8] !== 1) $display("HATA: x8 beklenen 1 degil!");
    if (processor.register.registerFile[9] !== 1) $display("HATA: x9 beklenen 1 degil!");
    if (processor.register.registerFile[10] !== 2) $display("HATA: x10 beklenen 2 degil!");
    if (processor.register.registerFile[11] !== 0) $display("HATA: x11 beklenen 0 degil!");
    if (processor.register.registerFile[12] !== 3) $display("HATA: x12 beklenen 3 degil!");
    if (processor.register.registerFile[13] !== 32'h00000038) $display("HATA: x13 beklenen 0x00000038 degil!");
    if (processor.dm.memory[0] !== 3) $display("HATA: memory[0] beklenen 3 degil!");

    #100;
    $finish;
  end


endmodule
