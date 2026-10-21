`timescale 1ps / 1ps

module DataMemory (
    input clk,
    input we,
    input [31:0] A,
    input [31:0] WD,
    output [31:0] RD
);

    reg [31:0] memory [0:63];

    assign RD = memory[A[7:2]];

    always @(posedge clk) begin
        if (we) begin
            memory[A[7:2]] <= WD;
        end
    end

endmodule