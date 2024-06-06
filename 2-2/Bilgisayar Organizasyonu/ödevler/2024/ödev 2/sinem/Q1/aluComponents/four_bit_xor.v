`include "aluComponents/one_bit_xor.v"
module four_bit_xor(out,a,b);
    input[3:0] a, b;
    output[3:0] out;

    one_bit_xor a1(out[0],a[0],b[0]);
    one_bit_xor a2(out[1],a[1],b[1]);
    one_bit_xor a3(out[2],a[2],b[2]);
    one_bit_xor a4(out[3],a[3],b[3]);
endmodule


