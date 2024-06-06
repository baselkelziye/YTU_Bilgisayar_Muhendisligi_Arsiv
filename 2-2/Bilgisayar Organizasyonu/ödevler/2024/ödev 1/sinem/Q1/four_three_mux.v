`include "one_three_mux.v"

module four_three_mux(out,a,b,c,d,e,f,g,h,s);
    input[3:0] a,b,c,d,e,f,g,h;
    input[2:0] s;
    output[3:0] out;

    one_three_mux o1(out[0],a[0],b[0],c[0],d[0],e[0],f[0],g[0],h[0],s);
    one_three_mux o2(out[1],a[1],b[1],c[1],d[1],e[1],f[1],g[1],h[1],s);
    one_three_mux o3(out[2],a[2],b[2],c[2],d[2],e[2],f[2],g[2],h[2],s);
    one_three_mux o4(out[3],a[3],b[3],c[3],d[3],e[3],f[3],g[3],h[3],s);

endmodule