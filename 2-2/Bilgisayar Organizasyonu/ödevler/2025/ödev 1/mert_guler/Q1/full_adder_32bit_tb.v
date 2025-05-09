`include "full_adder_32bit.v"

module full_adder_32bit_tb;
    reg [31:0] a, b;
    reg cin;
    wire [31:0] result;

    full_adder_32bit add(a, b, cin, result);

    initial
    begin
        $dumpfile("full_adder_32bit.vcd");
        $dumpvars(0, full_adder_32bit_tb);

        // Test 1 = 10 + 10  = 20
        a = 32'd10; b = 32'd10; cin = 1'b0; 
        #10

        // Test 2 = 200 + 100 = 300
        a = 32'd200; b = 32'd100; cin = 1'b0;
        #10

        // Test 3 = 0 + 0 = 0
        a = 32'd0; b = 32'd0; cin = 1'b0;
        #10

        // Test 4
        a = 32'hFFFFFFFF; b = 32'd10; cin = 1'b0; // Overflow by 10
        #10

        $finish;
    end
endmodule