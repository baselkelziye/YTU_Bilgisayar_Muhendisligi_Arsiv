`include "SCP.v"

module SCP_tb();
    reg clk = 1'b1;
    reg rst = 1'b1;

    singleCycleProcessor scp(clk, rst);

    initial begin
        $dumpfile("SCP_tb.vcd");
        $dumpvars(0, SCP_tb);
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

//iverilog -o SCP_tb.vvp SCP_tb.v
//vvp SCP_tb.vvp