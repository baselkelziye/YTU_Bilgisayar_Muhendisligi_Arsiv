`include "aluComponents/four_bit_full_adder.v"

module thirty_two_bit_full_adder(a,b,carry_in,carry_out,sum);
    input [31:0] a, b;
    input carry_in;
    output [31:0] sum;
    wire carry1,carry2,carry3,carry4,carry5,carry6,carry7,carry8;
    output carry_out;

    four_bit_full_adder a1(a[3:0],b[3:0],carry_in,sum[3:0],carry1);
    four_bit_full_adder a2(a[7:4],b[7:4],carry1,sum[7:4],carry2);
    four_bit_full_adder a3(a[11:8],b[11:8],carry2,sum[11:8],carry3);
    four_bit_full_adder a4(a[15:12],b[15:12],carry3,sum[15:12],carry4);
    four_bit_full_adder a5(a[19:16],b[19:16],carry4,sum[19:16],carry5);
    four_bit_full_adder a6(a[23:20],b[23:20],carry5,sum[23:20],carry6);
    four_bit_full_adder a7(a[27:24],b[27:24],carry6,sum[27:24],carry7);
    four_bit_full_adder a8(a[31:28],b[31:28],carry7,sum[31:28],carry_out);


endmodule
