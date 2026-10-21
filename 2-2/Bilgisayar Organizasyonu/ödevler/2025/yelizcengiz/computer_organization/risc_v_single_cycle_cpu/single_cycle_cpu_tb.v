module single_cycle_cpu_tb;
    reg clk = 0;
    reg reset;

    single_cycle_cpu DUT(clk, reset);

    always #5 clk = ~clk;

    initial begin
        $dumpfile("Q3.vcd");
        $dumpvars(0, single_cycle_cpu_tb);

        reset = 1;
        #10;
        reset = 0;

        #10;
        $finish;
    end
endmodule
