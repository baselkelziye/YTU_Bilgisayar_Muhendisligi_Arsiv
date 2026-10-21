`timescale 1ns/1ps

module testbench;
    reg         clk;
    reg         reset;
    wire [31:0] WriteData;
    wire [31:0] DataAdr;
    wire        MemWrite;

    // Instantiate top
    top dut(
        .clk(clk),
        .reset(reset),
        .WriteData(WriteData),
        .DataAdr(DataAdr),
        .MemWrite(MemWrite)
    );

    // Dump waveforms for GTKWave
    initial begin
        $dumpfile("waveform.vcd");
        $dumpvars(0, testbench);
    end

    // Clock generation
    initial clk = 0;
    always #5 clk = ~clk;

    // Reset pulse
    initial begin
        reset = 1;
        #20 reset = 0;
    end

    integer i;
    initial begin
        #800;
        $display("COUNT dizisi (dmem[20] - dmem[39]):");
        for (i = 20; i < 40; i = i + 1) begin
            $display("COUNT[%0d] = %0d", i-20, dut.mem.RAM[i]);
        end
        $finish;
    end
endmodule
