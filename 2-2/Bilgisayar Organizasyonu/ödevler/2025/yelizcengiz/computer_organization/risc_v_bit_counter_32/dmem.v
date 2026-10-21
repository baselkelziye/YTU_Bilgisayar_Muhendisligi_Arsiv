// File: dmem.v
module dmem(
    input         clk,
    input         we,
    input  [31:0] a,
    input  [31:0] wd,
    output [31:0] rd
);

  // 64 words of 32-bit data memory
  reg [31:0] RAM [0:63];

 initial begin
    RAM[0]  = 32'h00000000;
    RAM[1]  = 32'h00000001;
    RAM[2]  = 32'h00000200;
    RAM[3]  = 32'h00400000;
    RAM[4]  = 32'h80000000;
    RAM[5]  = 32'h51C06460;
    RAM[6]  = 32'hDEC287D9;
    RAM[7]  = 32'h6C896594;
    RAM[8]  = 32'h99999999;
    RAM[9]  = 32'hFFFFFFFF;
    RAM[10] = 32'h7FFFFFFF;
    RAM[11] = 32'hFFFFFFFE;
    RAM[12] = 32'hC7B52169;
    RAM[13] = 32'h8CEFF731;
    RAM[14] = 32'hA550921E;
    RAM[15] = 32'h0DB01F33;
    RAM[16] = 32'h24BB7B48;
    RAM[17] = 32'h98513914;
    RAM[18] = 32'hCD76ED30;
    RAM[19] = 32'hC0000003;
  end
  // asynchronous read (word-aligned)
  assign rd = RAM[a[31:2]];

  // synchronous write
  always @(posedge clk) begin
    if (we)
      RAM[a[31:2]] <= wd;
  end

endmodule
