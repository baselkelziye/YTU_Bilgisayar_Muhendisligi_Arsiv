`include "aluComponents/one_bit_full_adder.v"

module four_bit_full_adder(a,b,carry_in,sum,carry_out);
    input [3:0] a, b;
    input carry_in;
    output [3:0] sum;
    output carry_out;
    wire carry1,carry2,carry3;

    one_bit_full_adder a1(a[0],b[0],carry_in,sum[0],carry1);
    one_bit_full_adder a2(a[1],b[1],carry1,sum[1],carry2);
    one_bit_full_adder a3(a[2],b[2],carry2,sum[2],carry3);
    one_bit_full_adder a4(a[3],b[3],carry3,sum[3],carry_out);

endmodule
