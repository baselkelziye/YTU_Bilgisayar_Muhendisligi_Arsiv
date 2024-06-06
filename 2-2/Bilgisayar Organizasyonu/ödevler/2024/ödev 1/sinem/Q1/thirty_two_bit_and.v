`include "four_bit_and.v"

module thirty_two_bit_and(out,a,b);

    input [31:0] a, b;
    output [31:0] out;

    four_bit_and a1(out[3:0], a[3:0], b[3:0]);
    four_bit_and a2(out[7:4], a[7:4], b[7:4]);
    four_bit_and a3(out[11:8], a[11:8], b[11:8]);
    four_bit_and a4(out[15:12], a[15:12], b[15:12]);
    four_bit_and a5(out[19:16], a[19:16], b[19:16]);
    four_bit_and a6(out[23:20], a[23:20], b[23:20]);
    four_bit_and a7(out[27:24], a[27:24], b[27:24]);
    four_bit_and a8(out[31:28], a[31:28], b[31:28]);
endmodule