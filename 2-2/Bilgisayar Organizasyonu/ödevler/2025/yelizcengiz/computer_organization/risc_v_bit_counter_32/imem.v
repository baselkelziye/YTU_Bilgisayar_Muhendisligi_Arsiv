// File: imem.v
module imem(
    input  [31:0] a,
    output [31:0] rd
);

  // 64 words of 32-bit instruction memory
  reg [31:0] RAM [0:20];

  // preload from hex file
  initial begin
    $readmemh("riscvtest.txt", RAM);
  end

  // word-aligned fetch
  assign rd = RAM[a[31:2]];

endmodule
