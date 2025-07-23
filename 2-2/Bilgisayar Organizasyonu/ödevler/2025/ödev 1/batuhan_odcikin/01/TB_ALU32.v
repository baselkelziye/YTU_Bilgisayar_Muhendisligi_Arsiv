`timescale 1ns / 1ps
`include "ALU32.v"


module TB_ALU32;

    // Girişler
    reg [31:0] A;
    reg [31:0] B;
    reg [2:0] ALUControl;

    // Çıkışlar
    wire [31:0] Result;
    wire Zero;
    wire Overflow;

    // ALU modülünü çağır
    ALU32 uut (
        .A(A),
        .B(B),
        .ALUControl(ALUControl),
        .Result(Result),
        .Zero(Zero),
        .Overflow(Overflow)
    );

    initial begin
        $dumpfile("alu_test_dmp.vcd");
        $dumpvars(0, TB_ALU32);

        $display("Time\tA\t\tB\t\tALUCtrl\tResult\t\tZero\tOverflow");
        $monitor("%4dns\t%h\t%h\t%03b\t%h\t%b\t%b", 
        $time, A, B, ALUControl, Result, Zero, Overflow);


       // Test 1: A + B
        A = 32'h00001234;  
        B = 32'h00004321;  
        ALUControl = 3'b000; // ADD
        #10;

        // Test 2: A - B
        A = 32'h0000F000;  
        B = 32'h00001234;
        ALUControl = 3'b001; // SUB
        #10;

        // Test 3: A & B
        A = 32'h0000AAAA;  
        B = 32'h0000CCCC;  
        ALUControl = 3'b010; // AND
        #10;

        // Test 4: A | B
        A = 32'h00001130;  
        B = 32'h00000204;  
        ALUControl = 3'b011; // OR
        #10;

        // Test 5: A - B, Zero olmalı
        A = 32'h00008000;  
        B = 32'h00008000;
        ALUControl = 3'b001; // SUB
        #10;

         // Test 6: SLT - A < B (pozitif)
        A = 32'd5;
        B = 32'd10;
        ALUControl = 3'b101; // SLT
        #10;

        // Test 7: SLT - A > B (pozitif)
        A = 32'd20;
        B = 32'd10;
        ALUControl = 3'b101; // SLT
        #10;

        // Test 8: SLT - A < B (negatif vs pozitif)
        A = -32'sd50;
        B = 32'd5;
        ALUControl = 3'b101; // SLT
        #10;

        // Test 9: SLT - A > B (pozitif vs negatif)
        A = 32'd5;
        B = -32'sd50;
        ALUControl = 3'b101; // SLT
        #10;

        // Test 10: Overflow - pozitif + pozitif = negatif
        A = 32'h7FFFFFFF; // Max positive
        B = 32'd1;
        ALUControl = 3'b000; // ADD
        #10;

        // Test 11: Overflow - negatif + negatif = pozitif
        A = 32'h80000000; // Min negative
        B = -32'sd1;
        ALUControl = 3'b000; // ADD
        #10;


        $finish;
    end

endmodule
