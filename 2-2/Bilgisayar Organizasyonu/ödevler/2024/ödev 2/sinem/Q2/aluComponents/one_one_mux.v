module one_one_mux(out,a,b,s);
    input a,b,s;
    output out;
    wire s_not, temp1,temp2;
    
    not(s_not,s);
    and a1(temp1,s_not,a);
    and a2(temp2,s,b);
    or(out,temp1,temp2);

endmodule