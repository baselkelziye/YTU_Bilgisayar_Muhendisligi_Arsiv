`timescale 1ns/1ps
module DataMemory (
    input         clk,
    input         we,
    input  [31:0] addr,
    input  [31:0] wd,
    output [31:0] rd
);
    reg [31:0] mem[0:1023];
    always @(posedge clk)
        if (we)
            mem[addr[11:2]] <= wd;
    assign rd = mem[addr[11:2]];
endmodule
