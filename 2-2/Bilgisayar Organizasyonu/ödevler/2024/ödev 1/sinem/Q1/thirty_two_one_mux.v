`include "four_one_mux.v"

module thirty_two_one_mux(out,a,b,s);
    input [31:0] a,b;
    input s;
    output [31:0]out;

    four_one_mux m1(out[3:0],a[3:0],b[3:0],s);
    four_one_mux m2(out[7:4],a[7:4],b[7:4],s);
    four_one_mux m3(out[11:8],a[11:8],b[11:8],s);
    four_one_mux m4(out[15:12],a[15:12],b[15:12],s);
    four_one_mux m5(out[19:16],a[19:16],b[19:16],s);
    four_one_mux m6(out[23:20],a[23:20],b[23:20],s);
    four_one_mux m7(out[27:24],a[27:24],b[27:24],s);
    four_one_mux m8(out[31:28],a[31:28],b[31:28],s);


endmodule