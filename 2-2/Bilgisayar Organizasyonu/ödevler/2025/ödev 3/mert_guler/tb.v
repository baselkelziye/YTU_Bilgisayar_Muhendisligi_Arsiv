`timescale 1ns / 1ps
`include "rocessor.v"

// iverilog -o tb.v
// vvp tb
// gtkwave tb.vcd 

module processor_tb;
  reg clk;
  reg reset;
  wire Zero;
  wire [31:0] PC;
  wire [31:0] WriteData;
  wire [31:0] ReadData;
  wire [31:0] ALUResult;
  wire MemWrite;

  processor processor (
    .clk(clk),
    .reset(reset),
    .Zero(Zero),
    .PC(PC),
    .WriteData(WriteData),
    .ReadData(ReadData),
    .ALUResult(ALUResult),
    .MemWrite(MemWrite)
  );

  integer i;
  integer j;
  integer CYCLE_COUNT[19:0];

  initial clk = 0;
  initial j = 0;
  always #5 clk = ~clk;

// J = anlik kontrol edilen elemanin indexi. 0-19 arasi degisir. N[0] icin hazirlik cyclelari de dahildir
  always @(posedge clk) begin
      CYCLE_COUNT[j] <= CYCLE_COUNT[j] + 1;
      if (MemWrite == 1) begin
        j <= j + 1;
      end
  end

  initial begin
    $dumpfile("tb.vcd");
    $dumpvars(0, processor);

    for (i = 20; i < 40; i = i + 1) begin
        $dumpvars(0, processor.dm.memory[i]);
    end

    reset = 1;
    #20
    reset = 0;

    for (i = 0; i < 20; i = i + 1 ) begin
      CYCLE_COUNT[i] = 0;
    end

    #20000; // Sonuclar tamamen yuklenmezse bu degeri arttirin

    for (i = 0; i < 20; i = i + 1) begin
    $display("DATA[%-2d] = %h", i + 1, processor.dm.memory[i]); 
    end
    $display("------------------------------");
    for (i = 20; i < 40; i = i + 1) begin
    $display("POP_COUNT[%-2d] = %h", i - 19, processor.dm.memory[i]); 
    end
    $display("------------------------------");
    for (i = 0; i < 20; i = i + 1) begin
    $display("CYCLE_COUNT[%-2d] = %h", i + 1, CYCLE_COUNT[i]); 
    end

    // J burada total cycle count olarak kullanildi (ekstra degisken eklememek icin)
    for (i = 0; i < 20; i = i + 1) begin
    j = CYCLE_COUNT[i] + j;
    end

    $display("Total Cycles = %-2d", j); 

    $finish;

  end


endmodule
