`timescale 1ns/1ps

module testbench;

reg clk;
reg reset;

wire [31:0] WriteData;
wire [31:0] DataAdr;
wire MemWrite;

top dut (
    clk,
    reset,
    WriteData,
    DataAdr,
    MemWrite
);


wire [31:0] ARRAY [0:19];
wire [31:0] COUNT [0:19];

genvar i;
generate
    for (i = 0; i < 20; i = i + 1) begin : assign_loop
        assign ARRAY[i] = dut.u_dmem.RAM[i];       // 0-19 arasi ARRAY
        assign COUNT[i] = dut.u_dmem.RAM[i + 20];  // 20-39 arasi COUNT
    end
endgenerate

integer k;
initial begin
    $dumpfile("24011949.vcd");
    $dumpvars(0, testbench);
    
    for (k = 0; k < 20; k = k + 1) begin
        $dumpvars(0, ARRAY[k]);
        $dumpvars(0, COUNT[k]);
    end
end

always begin
    #5 clk = ~clk;
end

initial begin
    clk = 0;
    reset = 1;

    #22;
    reset = 0;

    #40000;

    $display("=======================================");
    $display("Sira | ARRAY Değeri | COUNT Değeri");
    $display("=======================================");
    for (k = 0; k < 20; k = k + 1) begin
        $display("%2d   | %08x   | %0d", k + 1, ARRAY[k], COUNT[k]);
    end
    $display("=======================================");

    $finish;
end

endmodule

/*
iverilog -o sim.vvp 24011949_*.v
vvp sim.vvp
gtkwave 24011949.vcd  */