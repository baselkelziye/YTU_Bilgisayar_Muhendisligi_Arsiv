`include "21011022.v"

module SCPwithSra_tb();
    reg clk = 1'b1;
    reg rst = 1'b1;

    singleCycleProcessorWithSra scp(clk, rst);

    initial begin
        $dumpfile("21011022.vcd");
        $dumpvars(0, SCPwithSra_tb);
    end

    always begin
        clk = ~clk; #5;
    end

    initial begin
        rst <= 1'b0; #3145;
        rst <= 1'b1; #5;
        $finish;
    end
endmodule

//iverilog -o 21011022_tb.vvp 21011022_tb.v
//vvp 21011022_tb.vvp