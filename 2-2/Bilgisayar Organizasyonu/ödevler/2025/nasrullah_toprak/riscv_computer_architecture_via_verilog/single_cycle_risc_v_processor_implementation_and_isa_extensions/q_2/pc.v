`timescale 1ps / 1ps

module PC (
    input clk,
    input rst,
    input [31:0] PCNext,
    output reg [31:0] PC
);

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            PC <= 32'b0;
        end else begin
            PC <= PCNext;
        end
    end

endmodule