module three_input_xnor(a,b,c,out);
    input a, b,c;
    output out;
    wire sum1,sum2;

    xor x1(sum1,a,b);
    xor x2(sum2,sum1,c);
    
    not n1(out,sum2);

endmodule


