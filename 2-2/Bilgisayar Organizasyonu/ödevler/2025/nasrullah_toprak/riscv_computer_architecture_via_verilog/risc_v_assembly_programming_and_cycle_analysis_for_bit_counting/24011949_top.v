// File: top.v
module top(
    input        clk,
    input        reset,
    output [31:0] WriteData,
    output [31:0] DataAdr,
    output        MemWrite
);
  wire [31:0] PC;
  wire [31:0] Instr;
  wire [31:0] ReadData;

  // CPU
  riscv_single u_rvsingle (
    clk,
    reset,
    PC,
    Instr,
    MemWrite,
    DataAdr,
    WriteData,
    ReadData
  );

  // instr mem
  imem u_imem (
    PC,
    Instr
  );

  // data mem
  dmem u_dmem (
    clk,
    MemWrite,
    DataAdr,
    WriteData,
    ReadData
  );
endmodule
