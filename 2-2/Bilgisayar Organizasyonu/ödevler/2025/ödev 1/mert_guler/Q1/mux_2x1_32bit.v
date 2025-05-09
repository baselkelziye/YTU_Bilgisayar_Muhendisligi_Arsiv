module mux_2x1_32bit (a, b, select, out); 
    input [31:0] a, b; 
    input select; 
    output [31:0] out; 
    assign out = select ? b : a;
endmodule
