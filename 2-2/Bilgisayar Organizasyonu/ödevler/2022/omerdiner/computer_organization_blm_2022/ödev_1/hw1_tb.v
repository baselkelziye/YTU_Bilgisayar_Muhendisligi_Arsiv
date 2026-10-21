`include "hw1.v"

`timescale 1ns/1ns


module test_hw1_modules;

    reg [31:0] a;
    reg b;
    wire [31:0] out;

    //zero_extend zero1(a,out);
    twos_complement twos1(a,out);

    initial begin
        $dumpfile("test_hw1_modules_zero.vcd");
        $dumpvars(0, test_hw1_modules);
        a = 32'b00000000000000000000000000000001;
        #1;
        $display("a=%b, out=%b",a,out);
        a=32'b00000000000000000000000000000111;
        #1;
        $display("a=%b, out=%b",a,out);
        a=32'b11111111111111111111111111111111;
        #1;
        $display("a=%b, out=%b",a,out);
        a=32'b11111111111111100000000000000000;
    end

    

   /* initial begin
        $dumpfile("test_hw1_modules_complement.vcd");
        $dumpvars(0, test_hw1_modules);
        b=1'b0;
        #1;
        b=1'b1;
        #1;
        
    end
    */

endmodule



