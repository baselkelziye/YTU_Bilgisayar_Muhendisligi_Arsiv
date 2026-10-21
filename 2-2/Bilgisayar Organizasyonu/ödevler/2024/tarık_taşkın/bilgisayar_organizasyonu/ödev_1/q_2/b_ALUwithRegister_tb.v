`include "../Q1/ALU_32.v"
`include "regfile.v"

module b_ALUwithRegister_tb;
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

        // Ciktilarda bir onceki adimlardaki register degerleri kullanilmistir.    

        // R1 <- 0 / R1 <- R1 ^ R1 or R1 <- R1 - R1
        // 9ABCDEF0 - 9ADCDEF0 = 0 (5. saniye)
        wr = 0; rst = 0;
        addr1 = 2'b01; addr2 = 2'b01; addr3 = 2'b01;
        a = data1; b = data2; alucontrol = 3'b001; #5;
        data3 = result; wr = 1;
        #10;


        // R0 <- -1 ==> R0 <- 1 then R0 <- R1 - R0 (R1 bir onceki adimda 0 olmustu.)
        wr = 0; rst = 0;
        //R0 <- 1
        addr3 = 2'b00; data3 = 1; wr = 1;
        #5;
        wr = 0; rst = 0;
        //R0 <- R1 - R0 
        // 0 - 1 = -1 (25. saniye)
        addr1 = 2'b01; addr2 = 2'b00; addr3 = 2'b00;
        a = data1; b = data2; alucontrol = 3'b001; #5;
        data3 = result; wr = 1;
        #10;


        // R2 <- R1 - 1 ==> R2 <- R1 + R0 (R0 bir onceki adimda -1 olmustu.) 
        // 0 + (-1) = -1 (40. saniye)
        wr = 0; rst = 0;
        addr1 = 2'b01; addr2 = 2'b00; addr3 = 2'b10;
        a = data1; b = data2; alucontrol = 3'b000; #5;
        data3 = result; wr = 1;
        #10;
        

        // R3 <- R0 + 1 ==> R3 <- R0 - R0 (R0 onceki adimda -1 olmustu.)
        // -1 - (-1) = 0 (55. saniye)
        wr = 0; rst = 0;
        addr1 = 2'b00; addr2 = 2'b00; addr3 = 2'b11;
        a = data1; b = data2; alucontrol = 3'b001; #5;
        data3 = result; wr = 1;
        #10;

        $finish;
    end


    initial begin
            $dumpfile("b_ALUwithRegister_tb.vcd");
            $dumpvars(0, b_ALUwithRegister_tb);
        end

endmodule


//iverilog -o b_ALUwithRegister_tb.vvp b_ALUwithRegister_tb.v
//vvp b_ALUwithRegister_tb.vvp