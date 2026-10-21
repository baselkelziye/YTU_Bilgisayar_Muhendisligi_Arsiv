// File: regfile.v
module regfile(
    input         clk,
    input         we,
    input  [4:0]  ra1,
    input  [4:0]  ra2,
    input  [4:0]  wa,
    input  [31:0] wd,
    output [31:0] rd1,
    output [31:0] rd2
);
  reg [31:0] regs [0:31];
  integer i;
  // x0 is hard‐wired to 0
  initial begin
    regs[0] = 32'b0;
    for (i = 1; i < 32; i = i + 1)
      regs[i] = 32'b0;
  end

  // write on rising clock
  always @(posedge clk) begin
    if (we && wa != 0)
      regs[wa] <= wd;
  end

  // asynchronous reads
  assign rd1 = (ra1 == 0) ? 32'b0 : regs[ra1];
  assign rd2 = (ra2 == 0) ? 32'b0 : regs[ra2];
endmodule
