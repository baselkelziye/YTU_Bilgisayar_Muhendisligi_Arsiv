module three_input_and(a,b,c,out);
    input a, b,c;
    output out;
    wire sum1;

    and x1(sum1,a,b);
    and x2(out,sum1,c);


endmodule


