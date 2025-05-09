`include "mux_8x1_32bit.v"

module mux_8x1_32bit_tb;
    reg [31:0] a, b, c, d, e, f, g, h;
    reg [2:0] select;
    wire [31:0] result;

    mux_8x1_32bit mux(a, b, c, d, e, f, g, h, select, result);

    initial
    begin
        $dumpfile("mux_8x1_32bit.vcd");
        $dumpvars(0, mux_8x1_32bit_tb);

        a = 32'd1; b = 32'd2; c = 32'd3; d = 32'd4; e = 32'd5; f = 32'd6; g = 32'd7; h = 32'd8;
        select = 3'b000;
        #10

        a = 32'd1; b = 32'd2; c = 32'd3; d = 32'd4; e = 32'd5; f = 32'd6; g = 32'd7; h = 32'd8;
        select = 3'b001;
        #10

        a = 32'd1; b = 32'd2; c = 32'd3; d = 32'd4; e = 32'd5; f = 32'd6; g = 32'd7; h = 32'd8;
        select = 3'b010;
        #10

        a = 32'd1; b = 32'd2; c = 32'd3; d = 32'd4; e = 32'd5; f = 32'd6; g = 32'd7; h = 32'd8;
        select = 3'b011;
        #10

        a = 32'd1; b = 32'd2; c = 32'd3; d = 32'd4; e = 32'd5; f = 32'd6; g = 32'd7; h = 32'd8;
        select = 3'b100;
        #10

        a = 32'd1; b = 32'd2; c = 32'd3; d = 32'd4; e = 32'd5; f = 32'd6; g = 32'd7; h = 32'd8;
        select = 3'b101;
        #10

        a = 32'd1; b = 32'd2; c = 32'd3; d = 32'd4; e = 32'd5; f = 32'd6; g = 32'd7; h = 32'd8;
        select = 3'b110;
        #10

        a = 32'd1; b = 32'd2; c = 32'd3; d = 32'd4; e = 32'd5; f = 32'd6; g = 32'd7; h = 32'd8;
        select = 3'b111;
        #10

        $finish;
    end
endmodule