`include "one_bit_not.v"
module four_bit_not(out,a);
    input[3:0] a;
    output[3:0] out;

    one_bit_not n1(out[0],a[0]);
    one_bit_not n2(out[1],a[1]);
    one_bit_not n3(out[2],a[2]);
    one_bit_not n4(out[3],a[3]);
endmodule


