// File: top.v
module top(
    input        clk,
    input        reset,
    output reg [31:0] WriteData,
    output reg [31:0] DataAdr,
    output reg MemWrite
);
    reg [5:0] idx;
    reg [31:0] temp;
    wire [31:0] rd;
    reg [1:0] state;

    dmem mem(
        .clk(clk),
        .we(MemWrite),
        .a(DataAdr),
        .wd(WriteData),
        .rd(rd)
    );

    function [31:0] popcount;
        input [31:0] x;
        integer i;
        begin
            popcount = 0;
            for (i = 0; i < 32; i = i + 1)
                popcount = popcount + x[i];
        end
    endfunction

    always @(posedge clk) begin
        if (reset) begin
            idx <= 0;
            state <= 0;
            MemWrite <= 0;
        end else begin
            case (state)
                0: begin
                    DataAdr <= idx << 2;
                    MemWrite <= 0;
                    state <= 1;
                end
                1: begin
                    temp <= rd;
                    DataAdr <= (idx + 20) << 2;
                    WriteData <= popcount(rd);
                    MemWrite <= 1;
                    state <= 2;
                end
                2: begin
                    MemWrite <= 0;
                    idx <= idx + 1;
                    if (idx == 19)
                        state <= 3;
                    else
                        state <= 0;
                end
                3: begin
                    MemWrite <= 0;
                end
            endcase
        end
    end
endmodule
