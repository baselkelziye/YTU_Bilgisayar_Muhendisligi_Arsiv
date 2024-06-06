`include "four_bit_zeroExtender.v"
module thirty_two_bit_zeroExtender(out,a);
    input a;
    output[31:0] out;
    wire zero = 4'b0000;

    four_bit_zeroExtender n1(out[3:0], a);
    four_bit_zeroExtender n2(out[7:4], zero);
    four_bit_zeroExtender n3(out[11:8], zero);
    four_bit_zeroExtender n4(out[15:12], zero);
    four_bit_zeroExtender n5(out[19:16], zero);
    four_bit_zeroExtender n6(out[23:20], zero);
    four_bit_zeroExtender n7(out[27:24], zero);
    four_bit_zeroExtender n8(out[31:28], zero);

endmodule


