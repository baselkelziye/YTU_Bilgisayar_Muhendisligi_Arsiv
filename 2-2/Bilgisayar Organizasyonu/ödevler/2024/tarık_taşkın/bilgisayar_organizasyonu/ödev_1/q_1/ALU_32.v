
module ALU_32(result, a, b, alucontrol);
    input [31:0] a, b;
    input [2:0] alucontrol;
    output [31:0] result;

    wire [31:0] out_adder, out_and, out_xor, out_slt;
    wire cout;

    add add1(out_adder, a, b, alucontrol[0], cout);
    and_32 and1(out_and, a, b);
    xor_32 xor1(out_xor, a, b);
    slt slt1(out_slt, a[31], b[31], out_adder[31], alucontrol[1:0]);

    mux_8x1 mux1(result, out_adder, out_adder, out_and, out_xor, 32'b0, out_slt, 32'b0, 32'b0, alucontrol);

endmodule

module mux_2x1_1bit(out, a, b, select);
    input a, b;
    input select;
    output out;

    assign out = (a & ~select) | (b & select);
endmodule

module mux_2x1_4bit(out, a, b, select);
    input [3:0] a, b;
    input select;
    output [3:0] out;

    mux_2x1_1bit mux0(out[0], a[0], b[0], select);
    mux_2x1_1bit mux1(out[1], a[1], b[1], select);
    mux_2x1_1bit mux2(out[2], a[2], b[2], select);
    mux_2x1_1bit mux3(out[3], a[3], b[3], select);
endmodule

module mux_2x1(out, a, b, select);
    input [31:0] a, b; //32 bit
    input select; //1 bit
    output [31:0] out;

    mux_2x1_4bit mux0(out[3:0], a[3:0], b[3:0], select);
    mux_2x1_4bit mux1(out[7:4], a[7:4], b[7:4], select);
    mux_2x1_4bit mux2(out[11:8], a[11:8], b[11:8], select);
    mux_2x1_4bit mux3(out[15:12], a[15:12], b[15:12], select);
    mux_2x1_4bit mux4(out[19:16], a[19:16], b[19:16], select);
    mux_2x1_4bit mux5(out[23:20], a[23:20], b[23:20], select);
    mux_2x1_4bit mux6(out[27:24], a[27:24], b[27:24], select);
    mux_2x1_4bit mux7(out[31:28], a[31:28], b[31:28], select);
endmodule

module mux_4x1(out, a, b, c, d, select);
    input [31:0] a, b, c, d;
    input [1:0] select;
    output [31:0] out;

    wire [31:0] out1, out2;

    mux_2x1 mux1(
        .out(out1),
        .a(a),
        .b(b),
        .select(select[0])
    );

    mux_2x1 mux2(
        .out(out2),
        .a(c),
        .b(d),
        .select(select[0])
    );

    mux_2x1 mux3(
        .out(out),
        .a(out1),
        .b(out2),
        .select(select[1])
    );
endmodule

module mux_8x1(out, a, b, c, d, e, f, g, h, select);
    input [31:0] a, b, c, d, e, f, g, h;
    input [2:0] select;
    output [31:0] out;

    wire [31:0] out1, out2;

    mux_4x1 mux1(
        .out(out1),
        .a(a),
        .b(b),
        .c(c),
        .d(d),
        .select(select[1:0])
    );

    mux_4x1 mux2(
        .out(out2),
        .a(e),
        .b(f),
        .c(g),
        .d(h),
        .select(select[1:0])
    );

    mux_2x1 mux3(
        .out(out),
        .a(out1),
        .b(out2),
        .select(select[2])
    );
endmodule

module add(sum, a, b, cin, cout);
    input [31:0] a, b;
    input cin;
    output [31:0] sum;
    output cout;

    wire [31:0] carries;
    wire [31:0] b_new;

    genvar i;
    for (i = 0; i < 32; i = i + 1) begin
       assign b_new[i] = (~cin & b[i]) | (cin & ~b[i]);
    end

    full_adder fa1(sum[0], a[0], b_new[0], cin, carries[0]);
    for (i = 1; i < 31; i = i + 1) begin
        full_adder fa2(sum[i], a[i], b_new[i], carries[i-1], carries[i]);
    end
    full_adder fa3(sum[31], a[31], b_new[31], carries[30], cout);

endmodule

module half_adder(sum, a, b, cout);
    input a, b;
    output sum, cout;
    xor x1(sum, a, b);
    and a1(cout, a, b);
endmodule

module full_adder(sum, a, b, cin, cout);
    input a, b, cin;
    output sum, cout;
    wire sum_half, cout_half, cout_half_2;

    half_adder ha1(sum_half, a, b, cout_half);
    half_adder ha2(sum, sum_half, cin, cout_half_2);
    or o1(cout, cout_half, cout_half_2);
endmodule

module and_32(out, a, b);
    input [31:0] a, b;
    output [31:0] out;

    genvar i;
    for (i = 0; i < 32; i = i + 1) begin
       assign out[i] = a[i] & b[i];
    end
endmodule

module xor_32(out, a, b);
    input [31:0] a, b;
    output [31:0] out;

    genvar i;
    for (i = 0; i < 32; i = i + 1) begin
       assign out[i] = (a[i] & ~b[i]) | (~a[i] & b[i]);
    end
endmodule

module slt(out, a, b, sum, alucontrol);
    input a, b, sum;
    input [1:0] alucontrol;
    output [31:0] out;

    wire firstbit;

    assign firstbit = (~(a ^ b ^ alucontrol[0]) & (a ^ sum) & ~alucontrol[1]) ^ sum;
    zero_extender z_ex(out, firstbit);
endmodule

module zero_extender(out, firstbit);
    input firstbit;
    output [31:0] out;

    assign out = {31'b0, firstbit};
endmodule