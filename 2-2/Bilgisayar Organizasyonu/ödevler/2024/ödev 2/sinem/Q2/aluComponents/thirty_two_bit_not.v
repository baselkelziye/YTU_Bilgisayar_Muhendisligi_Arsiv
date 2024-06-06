`include "aluComponents/four_bit_not.v"

module thirty_two_bit_not(out,a);

    input [31:0] a;
    output [31:0] out;

    four_bit_not n1(out[3:0], a[3:0]);
    four_bit_not n2(out[7:4], a[7:4]);
    four_bit_not n3(out[11:8], a[11:8]);
    four_bit_not n4(out[15:12], a[15:12]);
    four_bit_not n5(out[19:16], a[19:16]);
    four_bit_not n6(out[23:20], a[23:20]);
    four_bit_not n7(out[27:24], a[27:24]);
    four_bit_not n8(out[31:28], a[31:28]);

endmodule