module mux2 (src,b,a,out);

    input src;
    input [31:0] a,b;
    output[31:0] out;
    
    assign out = src ? b:a; 

endmodule