`include "four_bit_xor.v"

module thirty_two_bit_xor(out,x,b);

    input [31:0] x, b;
    output [31:0] out;

    four_bit_xor x1(out[3:0], x[3:0], b[3:0]);
    four_bit_xor x2(out[7:4], x[7:4], b[7:4]);
    four_bit_xor x3(out[11:8], x[11:8], b[11:8]);
    four_bit_xor x4(out[15:12], x[15:12], b[15:12]);
    four_bit_xor x5(out[19:16], x[19:16], b[19:16]);
    four_bit_xor x6(out[23:20], x[23:20], b[23:20]);
    four_bit_xor x7(out[27:24], x[27:24], b[27:24]);
    four_bit_xor x8(out[31:28], x[31:28], b[31:28]);
endmodule