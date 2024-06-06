`include "one_one_mux.v"

module four_one_mux(out,a,b,s);
    input [3:0] a,b;
    input s;
    output [3:0]out;

    one_one_mux m1(out[0],a[0],b[0],s);
    one_one_mux m2(out[1],a[1],b[1],s);
    one_one_mux m3(out[2],a[2],b[2],s);
    one_one_mux m4(out[3],a[3],b[3],s);


endmodule