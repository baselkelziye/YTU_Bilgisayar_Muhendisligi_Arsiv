`include "one_bit_zeroExtender.v"
module four_bit_zeroExtender(out,a);
    input a;
    output[3:0] out;
    wire zero = 1'b0;

    one_bit_zeroExtender z1(out[0],a);
    one_bit_zeroExtender z2(out[1],zero);
    one_bit_zeroExtender z3(out[2],zero);
    one_bit_zeroExtender z4(out[3],zero);


endmodule


