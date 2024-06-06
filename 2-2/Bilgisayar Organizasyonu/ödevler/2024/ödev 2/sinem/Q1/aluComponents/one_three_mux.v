module one_three_mux(out,a,b,c,d,e,f,g,h,s);
    input a,b,c,d,e,f,g,h;
    input[2:0] s;
    output out;
    wire s_not0,s_not1,s_not2;
    wire [15:0] temp;
    wire [7:0] result_temp;
    wire [7:0] or_temp;

    not n1(s_not0,s[0]);
    not n2(s_not1,s[1]);
    not n3(s_not2,s[2]);


    and a1(temp[0],s_not2,a);
    and a2(temp[1],temp[0],s_not1);
    and a3(result_temp[0],temp[1],s_not0);

    and a4(temp[2],s_not2,b);
    and a5(temp[3],temp[2],s_not1);
    and a6(result_temp[1],temp[3],s[0]);

    and a7(temp[4],s_not2,c);
    and a8(temp[5],temp[4],s[1]);
    and a9(result_temp[2],temp[5],s_not0);

    and a10(temp[6],s_not2,d);
    and a11(temp[7],temp[6],s[1]);
    and a12(result_temp[3],temp[7],s[0]);

    and a13(temp[8],s[2],e);
    and a14(temp[9],temp[8],s_not1);
    and a15(result_temp[4],temp[9],s_not0);

    and a16(temp[10],s[2],f);
    and a17(temp[11],temp[10],s_not1);
    and a18(result_temp[5],temp[11],s[0]);

    and a19(temp[12],s[2],g);
    and a20(temp[13],temp[12],s[1]);
    and a21(result_temp[6],temp[13],s_not0);

    and a22(temp[14],s[2],h);
    and a23(temp[15],temp[14],s[1]);
    and a24(result_temp[7],temp[15],s[0]);


    or o1(or_temp[0],result_temp[0],result_temp[1]);
    or o2(or_temp[1],or_temp[0],result_temp[2]);
    or o3(or_temp[2],or_temp[1],result_temp[3]);
    or o4(or_temp[3],or_temp[2],result_temp[4]);
    or o5(or_temp[4],or_temp[3],result_temp[5]);
    or o6(or_temp[5],or_temp[4],result_temp[6]);
    or o7(out,or_temp[5],result_temp[7]);


endmodule