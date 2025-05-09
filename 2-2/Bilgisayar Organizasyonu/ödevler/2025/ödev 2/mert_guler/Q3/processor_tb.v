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
    $display("x3 = %d", processor.register.registerFile[3]); // Beklenen: 4
    $display("x4 = %h", processor.register.registerFile[4]); // Beklenen: 4

    if (processor.register.registerFile[1] !== 1) $display("HATA: x1 beklenen 1 degil!");
    if (processor.register.registerFile[2] !== 2) $display("HATA: x3 beklenen 2 degil!");
    if (processor.register.registerFile[3] !== 4) $display("HATA: x3 beklenen 4 degil!");
    if (processor.register.registerFile[4] !== 32'h22222000) $display("HATA: x4 beklenen 0x22222000 degil!");

    #100;
    $finish;
  end


endmodule
