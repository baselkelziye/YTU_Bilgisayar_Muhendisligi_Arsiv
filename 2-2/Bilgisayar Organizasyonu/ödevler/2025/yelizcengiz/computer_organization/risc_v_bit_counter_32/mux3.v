// File: mux3.v
module mux3 #(
    parameter WIDTH = 8
)(
    input  wire [WIDTH-1:0] d0,
    input  wire [WIDTH-1:0] d1,
    input  wire [WIDTH-1:0] d2,
    input  wire [1:0]       s,
    output wire [WIDTH-1:0] y
);
    assign y = s[1] ? d2 
             : (s[0] ? d1 
                     : d0);
endmodule
