`include "../Q1/ALU_32.v"
`include "regfile.v"

module a_ALUwithRegister_tb;
    reg [31:0] a, b;
    reg [2:0] alucontrol;
    wire [31:0] result;

    reg clk, wr, rst;
    reg [1:0] addr1, addr2, addr3;
    reg [31:0] data3;
    wire [31:0] data1, data2;

    ALU_32 uut (
        .result(result),
        .a(a),
        .b(b),
        .alucontrol(alucontrol)
    );

    regfile uut2(
        .addr1(addr1),
        .addr2(addr2),
        .addr3(addr3),
        .data1(data1),
        .data2(data2),
        .data3(data3),
        .clk(clk),
        .wr(wr),
        .rst(rst)
    );


    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        wr = 0; rst = 0;
        // R0 <- R1 + R2 / data3 <- data1 + data2
        // 9ABCDEF0 + FFFFFFFF = 9ABCDEEF (5. saniye)
        addr1 = 2'b01; addr2 = 2'b10; addr3 = 2'b00;
        a = data1; b = data2; alucontrol = 3'b000; #5;
        data3 = result; wr = 1;
        #10;

        wr = 0; rst = 0;
        // R1 <- R2 & R3 / data3 <- data1 & data2
        // FFFFFFFF & 00000001 = 00000001 (20. saniye)
        addr1 = 2'b10; addr2 = 2'b11; addr3 = 2'b01;
        a = data1; b = data2; alucontrol = 3'b010; #5;
        data3 = result; wr = 1;
        #10;

        wr = 0; rst = 0;
        // R3 <- R2 ^ R0 / data3 <- data1 ^ data2
        // FFFFFFFF ^ 9ABCDEEF = 65432110 (35. saniye)
        addr1 = 2'b10; addr2 = 2'b00; addr3 = 2'b11;
        a = data1; b = data2; alucontrol = 3'b011; #5;
        data3 = result; wr = 1;
        #10;

        wr = 0; rst = 0;
        // R2 <- R1 - R3 / data3 <- data1 - data2
        // 00000001 - 65432110 = 9ABCDEF1 (50. saniye)
        addr1 = 2'b01; addr2 = 2'b11; addr3 = 2'b10;
        a = data1; b = data2; alucontrol = 3'b001; #5;
        data3 = result; wr = 1;
        #10;

        $finish;
    end


    initial begin
            $dumpfile("a_ALUwithRegister_tb.vcd");
            $dumpvars(0, a_ALUwithRegister_tb);
        end

endmodule


//iverilog -o a_ALUwithRegister_tb.vvp a_ALUwithRegister_tb.v
//vvp a_ALUwithRegister_tb.vvp