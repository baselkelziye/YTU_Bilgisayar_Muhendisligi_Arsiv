module datapath(clk,rst, wr,addr1, addr2, addr3,ALUControl);
    input clk;
    input rst;
    input wr;
    input [1:0] addr1, addr2, addr3;
    input [2:0] ALUControl;
    wire [31:0] data1, data2, aluResult;

    regfile rf(
        .addr1(addr1),
        .addr2(addr2),
        .addr3(addr3),
        .data1(data1),
        .data2(data2),
        .data3(aluResult),
        .clk(clk),
        .wr(wr),
        .rst(rst)
    );

    alu alu(
        .A(data1),
        .B(data2),
        .ALUControl(ALUControl),
        .result(aluResult)
    );
endmodule
