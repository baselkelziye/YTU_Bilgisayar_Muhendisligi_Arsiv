`include "SCPwithSra.v"

module SCPwithSra_tb();
    reg clk = 1'b1;
    reg rst = 1'b1;

    singleCycleProcessorWithSra scp(clk, rst);

    initial begin
        $dumpfile("SCPwithSra_tb.vcd");
        $dumpvars(0, SCPwithSra_tb);
    end

    always begin
        clk = ~clk; #5;
    end

    initial begin
        rst <= 1'b0; #175;
        rst <= 1'b1; #5;
        $finish;
    end
endmodule

//iverilog -o SCPwithSra_tb.vvp SCPwithSra_tb.v
//vvp SCPwithSra_tb.vvp