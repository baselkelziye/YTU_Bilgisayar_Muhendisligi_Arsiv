`include "../01/full_adder.v"

module full_adder_32bit(a, b, cin, result);
    input [31:0] a, b;
    input cin;
    output [31:0] result;
    wire [31:0] carry;
    genvar i;

    generate
        for (i = 0; i < 32; i = i + 1) begin
            if (i == 0)
                full_adder fa(a[i], b[i], cin, result[i], carry[i]);
            else 
                full_adder fa(a[i], b[i], carry[i - 1], result[i], carry[i]);
        end
    endgenerate
endmodule