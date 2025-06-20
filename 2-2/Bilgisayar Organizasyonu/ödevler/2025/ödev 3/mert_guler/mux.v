module mux_2x1 (a, b, select, out); 
    input [31:0] a, b; 
    input select;
    output [31:0] out; 
    assign out = select ? a : b; 
endmodule

module mux_4x1 (a, b, c, d, select, out); 
    input [31:0] a, b, c, d; 
    input [1:0] select;
    output [31:0] out; 
    assign out = select[1] ? (select[0] ? a : b) : (select[0] ? c : d);
endmodule