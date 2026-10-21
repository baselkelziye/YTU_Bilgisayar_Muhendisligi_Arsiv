// File: 24011949_dmem.v
// Data memory containing ARRAY and COUNT regions.
// ARRAY starts at byte address 0. COUNT starts at byte address 80.

module dmem(
    input         clk,
    input         we,
    input  [31:0] a,
    input  [31:0] wd,
    output [31:0] rd
);

  reg [31:0] RAM [0:63];

  initial begin
    // ARRAY[0..19]
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

    // COUNT[0..19], written by the processor
    RAM[20] = 32'd0; RAM[21] = 32'd0; RAM[22] = 32'd0; RAM[23] = 32'd0;
    RAM[24] = 32'd0; RAM[25] = 32'd0; RAM[26] = 32'd0; RAM[27] = 32'd0;
    RAM[28] = 32'd0; RAM[29] = 32'd0; RAM[30] = 32'd0; RAM[31] = 32'd0;
    RAM[32] = 32'd0; RAM[33] = 32'd0; RAM[34] = 32'd0; RAM[35] = 32'd0;
    RAM[36] = 32'd0; RAM[37] = 32'd0; RAM[38] = 32'd0; RAM[39] = 32'd0;
  end

  assign rd = RAM[a[31:2]];

  always @(posedge clk) begin
    if (we)
      RAM[a[31:2]] <= wd;
  end

endmodule
