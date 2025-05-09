`include "../01/mux_2x1_32bit.v"

module mux_8x1_32bit(a, b, c, d, e, f, g, h, select, result);
    input [31:0] a, b, c, d, e, f, g, h;
    input [2:0] select;
    output [31:0] result;

    wire [31:0] out1, out2, out3, out4, out5, out6;

    mux_2x1_32bit mux1(.a(a), .b(b), .select(select[0]), .out(out1));
    mux_2x1_32bit mux2(.a(c), .b(d), .select(select[0]), .out(out2));
    mux_2x1_32bit mux3(.a(e), .b(f), .select(select[0]), .out(out3));
    mux_2x1_32bit mux4(.a(g), .b(h), .select(select[0]), .out(out4));

    mux_2x1_32bit mux5(.a(out1), .b(out2), .select(select[1]), .out(out5));
    mux_2x1_32bit mux6(.a(out3), .b(out4), .select(select[1]), .out(out6));

    mux_2x1_32bit mux7(.a(out5), .b(out6), .select(select[2]), .out(result));
endmodule
