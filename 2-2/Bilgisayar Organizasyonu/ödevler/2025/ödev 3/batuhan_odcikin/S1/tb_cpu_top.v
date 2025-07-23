
`timescale 1ns/1ps

module tb_cpu_top;
    // Clock & reset
    reg clk;
    reg rst;

    // CPU outputs
    wire [31:0] pc;
    wire [31:0] instr;
    wire [31:0] aluOut;
    wire [31:0] memReadData;

    // Instantiate DUT
    cpu_top UUT (
        .clk(clk),
        .rst(rst),
        .pc(pc),
        .instr(instr),
        .aluOut(aluOut),
        .memReadData(memReadData)
    );

    // Clock generation: 10 ns period
    initial clk = 0;
    always #5 clk = ~clk;

    // Load instruction memory
    initial begin
        // Hex dosyası, imem[0]…imem[N] adreslerine yüklenecek
        $readmemh("instr_mem_2.hex", UUT.imem);
    end
    // Reset sequencing
    initial begin
        rst = 1;
        #10;       // 2 clock cycle boyunca reset aktif
        rst = 0;
    end

    // Optional: monitor bazı sinyalleri
    initial begin
        $dumpfile("tb_cpu_top.vcd");
        $dumpvars(0, tb_cpu_top);
        $display("time\tpc\tinstr\taluOut\tmemRd");
        $monitor("time=%0t, pc=%h, instr=%h, x10=%h, x11=%h, x12=%h, x13=%h, x14=%h", $time, pc, instr, UUT.reg_file.regs[10], UUT.reg_file.regs[11], UUT.reg_file.regs[12], UUT.reg_file.regs[13], UUT.reg_file.regs[14]);
        end

    // Simulation stop
    initial begin
        #10000;     // 1000 ns sonra simülasyonu bitir
        $display("Final x9 = 0x%h", UUT.reg_file.regs[9]);
        $display("Final x10 = 0x%h", UUT.reg_file.regs[10]);
        $display("Final x11 = 0x%h", UUT.reg_file.regs[11]);
        $display("Final x12 = 0x%h", UUT.reg_file.regs[12]);
        $display("Final x13 = 0x%h", UUT.reg_file.regs[13]);
        $finish;
    end

endmodule
