`include "aluComponents/four_three_mux.v"

module thirty_two_three_mux(out,a,b,c,d,e,f,g,h,s);
    input[31:0] a,b,c,d,e,f,g,h;
    input[2:0] s;
    output[31:0] out;

    four_three_mux m1(out[3:0], a[3:0], b[3:0], c[3:0], d[3:0], e[3:0], f[3:0], g[3:0], h[3:0], s[2:0]);
    four_three_mux m2(out[7:4], a[7:4], b[7:4], c[7:4], d[7:4], e[7:4], f[7:4], g[7:4], h[7:4], s[2:0]);
    four_three_mux m3(out[11:8], a[11:8], b[11:8], c[11:8], d[11:8], e[11:8], f[11:8], g[11:8], h[11:8], s[2:0]);
    four_three_mux m4(out[15:12], a[15:12], b[15:12], c[15:12], d[15:12], e[15:12], f[15:12], g[15:12], h[15:12], s[2:0]);
    four_three_mux m5(out[19:16], a[19:16], b[19:16], c[19:16], d[19:16], e[19:16], f[19:16], g[19:16], h[19:16], s[2:0]);
    four_three_mux m6(out[23:20], a[23:20], b[23:20], c[23:20], d[23:20], e[23:20], f[23:20], g[23:20], h[23:20], s[2:0]);
    four_three_mux m7(out[27:24], a[27:24], b[27:24], c[27:24], d[27:24], e[27:24], f[27:24], g[27:24], h[27:24], s[2:0]);
    four_three_mux m8(out[31:28], a[31:28], b[31:28], c[31:28], d[31:28], e[31:28], f[31:28], g[31:28], h[31:28], s[2:0]);


endmodule

