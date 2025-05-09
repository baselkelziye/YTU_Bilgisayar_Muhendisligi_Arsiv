`include "alu.v"

module alu_tb;
    reg [31:0] a, b;
    reg [2:0] ALUControl;
    wire [31:0] result;

    alu alu(a, b, ALUControl, result);

    initial
    begin
        $dumpfile("alu.vcd");
        $dumpvars(0, alu_tb);

        // Test 1 - ADD = 10 + 10  = 20
        a = 32'd20; b = 32'd10; ALUControl = 3'b000;
        #10

        // Test 2 - SUB = 20 - 10  = 10
        a = 32'd20; b = 32'd10; ALUControl = 3'b001;
        #10

        // Test 3 - SUB = 10 - 20 = -10
        a = 32'd10; b = 32'd20; ALUControl = 3'b001;
        #10

        // Test 4 - AND = 10 AND 10
        a = 32'd10; b = 32'd10; ALUControl = 3'b010;
        #10

        // Test 4 - XOR = 10 XOR 1
        a = 32'd10; b = 32'd1; ALUControl = 3'b011;
        #10

        // Test 4 - SLT = 10 SLT 1
        a = 32'd10; b = 32'd1; ALUControl = 3'b101;
        #10

        // Test 4 - SLT = 10 SLT 1
        a = 32'd1; b = 32'd10; ALUControl = 3'b101;
        #10

        $finish;
    end
endmodule