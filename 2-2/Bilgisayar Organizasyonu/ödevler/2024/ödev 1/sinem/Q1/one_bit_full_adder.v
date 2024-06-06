module one_bit_full_adder(a,b,carry_in,sum,carry_out);
    input a, b,carry_in;
    output sum, carry_out;
    wire temp1,temp2,temp3;

    xor x1(temp1, a,b);
    xor x2(sum,carry_in,temp1);

    and a1(temp2, a, b);
    and a2(temp3,temp1,carry_in);

    or(carry_out,temp2,temp3);

endmodule


