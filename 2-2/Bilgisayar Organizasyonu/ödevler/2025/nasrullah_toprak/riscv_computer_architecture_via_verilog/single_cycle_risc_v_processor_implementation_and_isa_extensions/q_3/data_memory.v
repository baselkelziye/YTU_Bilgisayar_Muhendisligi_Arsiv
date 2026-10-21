`timescale 1ps / 1ps

module DataMemory (
    input clk,
    input we,
    input [2:0] funct3,// ADDED: load type selector. 010=lw, 001=lh
    input [31:0] A,
    input [31:0] WD,
    output reg [31:0] RD // REVISED: reg because read data is selected in always block
);

    reg [31:0] memory [0:63];
    wire [31:0] word_data;

    assign word_data = memory[A[7:2]];

    initial begin
        memory[0] = 32'hFFFF1234;
    end

    always @(*) begin
        case (funct3)

            3'b001: begin // lh
                if (A[1] == 1'b0)
                    RD = {{16{word_data[15]}}, word_data[15:0]};
                else
                    RD = {{16{word_data[31]}}, word_data[31:16]};
            end

            3'b010: begin // lw
                RD = word_data;
            end

            default: begin
                RD = word_data;
            end

        endcase
    end

    always @(posedge clk) begin
        if (we) begin
            memory[A[7:2]] <= WD;
        end
    end

endmodule
