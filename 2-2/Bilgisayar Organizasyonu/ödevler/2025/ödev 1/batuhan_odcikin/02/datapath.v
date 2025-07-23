module datapath(
    input clk,
    input rst,
    input wr,
    input [2:0] ALUControl,
    input [1:0] addr1, addr2, addr3,
    output [31:0] Result,
    output Zero,
    output Overflow
);

    wire [31:0] data1, data2;

    // Register file instance
    regfile RF (
        .addr1(addr1),
        .addr2(addr2),
        .addr3(addr3),
        .data1(data1),
        .data2(data2),
        .data3(Result),
        .clk(clk),
        .wr(wr),
        .rst(rst)
    );

    // ALU instance
    ALU32 alu (
        .A(data1),
        .B(data2),
        .ALUControl(ALUControl),
        .Result(Result),
        .Zero(Zero),
        .Overflow(Overflow)
    );

endmodule
