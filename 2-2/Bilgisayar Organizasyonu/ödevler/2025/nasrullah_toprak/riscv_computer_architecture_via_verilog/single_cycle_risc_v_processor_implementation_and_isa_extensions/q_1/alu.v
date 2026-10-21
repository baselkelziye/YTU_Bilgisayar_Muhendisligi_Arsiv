`timescale 1ps / 1ps

module CLA4 (
    input  [3:0] A,
    input  [3:0] B,
    input        Cin,
    output [3:0] Sum,
    output       Pblock,
    output       Gblock,
    output       Cout,
    output       C3_internal
);
    wire p0, p1, p2, p3;
    wire g0, g1, g2, g3;
    wire x0, x1, x2, x3;
    wire c1, c2, c3;

    supply0 GND;

    GATE_OR  u_p0 (.a(A[0]), .b(B[0]), .y(p0));
    GATE_OR  u_p1 (.a(A[1]), .b(B[1]), .y(p1));
    GATE_OR  u_p2 (.a(A[2]), .b(B[2]), .y(p2));
    GATE_OR  u_p3 (.a(A[3]), .b(B[3]), .y(p3));

    GATE_AND u_g0 (.a(A[0]), .b(B[0]), .y(g0));
    GATE_AND u_g1 (.a(A[1]), .b(B[1]), .y(g1));
    GATE_AND u_g2 (.a(A[2]), .b(B[2]), .y(g2));
    GATE_AND u_g3 (.a(A[3]), .b(B[3]), .y(g3));

    GATE_XOR u_x0 (.a(A[0]), .b(B[0]), .y(x0));
    GATE_XOR u_x1 (.a(A[1]), .b(B[1]), .y(x1));
    GATE_XOR u_x2 (.a(A[2]), .b(B[2]), .y(x2));
    GATE_XOR u_x3 (.a(A[3]), .b(B[3]), .y(x3));

    wire p0cin;
    GATE_AND u_p0cin (.a(p0), .b(Cin), .y(p0cin));
    GATE_OR  u_c1    (.a(g0), .b(p0cin), .y(c1));

    wire p1g0, p1p0, p1p0cin, c2_t0;
    GATE_AND u_p1g0    (.a(p1), .b(g0), .y(p1g0));
    GATE_AND u_p1p0    (.a(p1), .b(p0), .y(p1p0));
    GATE_AND u_p1p0cin (.a(p1p0), .b(Cin), .y(p1p0cin));
    GATE_OR  u_c2_t0   (.a(g1), .b(p1g0), .y(c2_t0));
    GATE_OR  u_c2      (.a(c2_t0), .b(p1p0cin), .y(c2));

    wire p2g1, p2p1, p2p1g0, p2p1p0, p2p1p0cin, c3_t0, c3_t1;
    GATE_AND u_p2g1      (.a(p2), .b(g1), .y(p2g1));
    GATE_AND u_p2p1      (.a(p2), .b(p1), .y(p2p1));
    GATE_AND u_p2p1g0    (.a(p2p1), .b(g0), .y(p2p1g0));
    GATE_AND u_p2p1p0    (.a(p2p1), .b(p0), .y(p2p1p0));
    GATE_AND u_p2p1p0cin (.a(p2p1p0), .b(Cin), .y(p2p1p0cin));
    GATE_OR  u_c3_t0     (.a(g2), .b(p2g1), .y(c3_t0));
    GATE_OR  u_c3_t1     (.a(c3_t0), .b(p2p1g0), .y(c3_t1));
    GATE_OR  u_c3        (.a(c3_t1), .b(p2p1p0cin), .y(c3));

    GATE_XOR u_s0 (.a(x0), .b(Cin), .y(Sum[0]));
    GATE_XOR u_s1 (.a(x1), .b(c1),  .y(Sum[1]));
    GATE_XOR u_s2 (.a(x2), .b(c2),  .y(Sum[2]));
    GATE_XOR u_s3 (.a(x3), .b(c3),  .y(Sum[3]));

    wire p3p2, p1p0_blk;
    GATE_AND u_p3p2   (.a(p3), .b(p2), .y(p3p2));
    GATE_AND u_p1p0_2 (.a(p1), .b(p0), .y(p1p0_blk));
    GATE_AND u_pb     (.a(p3p2), .b(p1p0_blk), .y(Pblock));

    wire g2p3, p2p3, g1p2p3, p1p2p3, g0p1p2p3, gb_t0, gb_t1;
    GATE_AND u_g2p3     (.a(g2), .b(p3), .y(g2p3));
    GATE_AND u_p2p3     (.a(p2), .b(p3), .y(p2p3));
    GATE_AND u_g1p2p3   (.a(g1), .b(p2p3), .y(g1p2p3));
    GATE_AND u_p1p2p3   (.a(p1), .b(p2p3), .y(p1p2p3));
    GATE_AND u_g0p1p2p3 (.a(g0), .b(p1p2p3), .y(g0p1p2p3));
    GATE_OR  u_gb_t0    (.a(g3), .b(g2p3), .y(gb_t0));
    GATE_OR  u_gb_t1    (.a(gb_t0), .b(g1p2p3), .y(gb_t1));
    GATE_OR  u_gb       (.a(gb_t1), .b(g0p1p2p3), .y(Gblock));

    wire pbcin;
    GATE_AND u_pbcin (.a(Pblock), .b(Cin), .y(pbcin));
    GATE_OR  u_cout  (.a(Gblock), .b(pbcin), .y(Cout));

    GATE_OR  u_c3_buf (.a(c3), .b(GND), .y(C3_internal));
endmodule


module CLA32 (
    input  [31:0] A,
    input  [31:0] B,
    input         Cin,
    output [31:0] Sum,
    output        Cout,
    output        C31
);
    wire c4, c8, c12, c16, c20, c24, c28, c32;
    wire pb0, pb1, pb2, pb3, pb4, pb5, pb6, pb7;
    wire gb0, gb1, gb2, gb3, gb4, gb5, gb6, gb7;
    wire c3_0, c3_1, c3_2, c3_3, c3_4, c3_5, c3_6, c3_7;

    CLA4 blk0 (.A(A[3:0]),    .B(B[3:0]),    .Cin(Cin), .Sum(Sum[3:0]),    .Pblock(pb0), .Gblock(gb0), .Cout(c4),  .C3_internal(c3_0));
    CLA4 blk1 (.A(A[7:4]),    .B(B[7:4]),    .Cin(c4),  .Sum(Sum[7:4]),    .Pblock(pb1), .Gblock(gb1), .Cout(c8),  .C3_internal(c3_1));
    CLA4 blk2 (.A(A[11:8]),   .B(B[11:8]),   .Cin(c8),  .Sum(Sum[11:8]),   .Pblock(pb2), .Gblock(gb2), .Cout(c12), .C3_internal(c3_2));
    CLA4 blk3 (.A(A[15:12]),  .B(B[15:12]),  .Cin(c12), .Sum(Sum[15:12]),  .Pblock(pb3), .Gblock(gb3), .Cout(c16), .C3_internal(c3_3));
    CLA4 blk4 (.A(A[19:16]),  .B(B[19:16]),  .Cin(c16), .Sum(Sum[19:16]),  .Pblock(pb4), .Gblock(gb4), .Cout(c20), .C3_internal(c3_4));
    CLA4 blk5 (.A(A[23:20]),  .B(B[23:20]),  .Cin(c20), .Sum(Sum[23:20]),  .Pblock(pb5), .Gblock(gb5), .Cout(c24), .C3_internal(c3_5));
    CLA4 blk6 (.A(A[27:24]),  .B(B[27:24]),  .Cin(c24), .Sum(Sum[27:24]),  .Pblock(pb6), .Gblock(gb6), .Cout(c28), .C3_internal(c3_6));
    CLA4 blk7 (.A(A[31:28]),  .B(B[31:28]),  .Cin(c28), .Sum(Sum[31:28]),  .Pblock(pb7), .Gblock(gb7), .Cout(c32), .C3_internal(c3_7));

    supply0 GND;

    GATE_OR u_cout_buf (.a(c32), .b(GND), .y(Cout));
    GATE_OR u_c31_buf  (.a(c3_7), .b(GND), .y(C31));
endmodule


module ALU (
    input  [31:0] A,
    input  [31:0] B,
    input  [2:0]  ALUControl,

    output [31:0] Result,
    output        Zero,
    output        Overflow
);
    supply0 GND;

    wire [31:0] and_out;
    wire [31:0] or_out;
    wire [31:0] b_arith;
    wire [31:0] sum_out;
    wire [31:0] slt_out;
    wire [31:0] low01;
    wire [31:0] low_group;
    wire [31:0] high_group;

    wire cout_arith;
    wire c31_arith;
    wire overflow_raw;
    wire set_less;

    genvar i;

    generate
        for (i = 0; i < 32; i = i + 1) begin : GEN_ALU_BITS
            GATE_AND u_and  (.a(A[i]), .b(B[i]), .y(and_out[i]));

            // Eski XOR yolu artık OR işlemi için kullanılıyor.
            // ALUControl = 001 olduğunda OR sonucu seçilecek.
            GATE_OR  u_or   (.a(A[i]), .b(B[i]), .y(or_out[i]));

            GATE_XOR u_bsel (.a(B[i]), .b(ALUControl[2]), .y(b_arith[i]));
        end
    endgenerate

    // ADD, SUB ve SLT aynı CLA32 aritmetik yolunu kullanır.
    // ADD için ALUControl[2] = 0
    // SUB ve SLT için ALUControl[2] = 1
    CLA32 u_cla32 (
        .A(A),
        .B(b_arith),
        .Cin(ALUControl[2]),
        .Sum(sum_out),
        .Cout(cout_arith),
        .C31(c31_arith)
    );

    // Overflow = C31 xor C32
    GATE_XOR u_ovf (.a(c31_arith), .b(cout_arith), .y(overflow_raw));

    // Signed SLT: set_less = sum_out[31] xor overflow
    GATE_XOR u_set (.a(sum_out[31]), .b(overflow_raw), .y(set_less));
    GATE_OR  u_slt0 (.a(set_less), .b(GND), .y(slt_out[0]));

    generate
        for (i = 1; i < 32; i = i + 1) begin : GEN_SLT_ZERO
            GATE_OR u_zero (.a(GND), .b(GND), .y(slt_out[i]));
        end
    endgenerate

    // Result selection:
    // 000 -> AND
    // 001 -> OR
    // 010 -> ADD
    // 110 -> SUB
    // 111 -> SLT
    generate
        for (i = 0; i < 32; i = i + 1) begin : GEN_RESULT_MUX
            GATE_MUX2 u_m0 (
                .d0(and_out[i]),
                .d1(or_out[i]),
                .s(ALUControl[0]),
                .y(low01[i])
            );

            GATE_MUX2 u_m1 (
                .d0(low01[i]),
                .d1(sum_out[i]),
                .s(ALUControl[1]),
                .y(low_group[i])
            );

            GATE_MUX2 u_m2 (
                .d0(sum_out[i]),
                .d1(slt_out[i]),
                .s(ALUControl[0]),
                .y(high_group[i])
            );

            GATE_MUX2 u_m3 (
                .d0(low_group[i]),
                .d1(high_group[i]),
                .s(ALUControl[2]),
                .y(Result[i])
            );
        end
    endgenerate

    // Overflow sadece aritmetik işlemler için anlamlıdır.
    // ADD 010, SUB 110, SLT 111 için ALUControl[1] = 1 olur.
    GATE_MUX2 u_ovf_out (
        .d0(GND),
        .d1(overflow_raw),
        .s(ALUControl[1]),
        .y(Overflow)
    );

    // Zero flag: Result tamamen 0 ise Zero = 1
    wire [15:0] z_l1;
    wire [7:0]  z_l2;
    wire [3:0]  z_l3;
    wire [1:0]  z_l4;
    wire        z_l5;

    generate
        for (i = 0; i < 16; i = i + 1) begin : GEN_ZERO_L1
            GATE_OR u_or1 (
                .a(Result[2*i]),
                .b(Result[2*i+1]),
                .y(z_l1[i])
            );
        end

        for (i = 0; i < 8; i = i + 1) begin : GEN_ZERO_L2
            GATE_OR u_or2 (
                .a(z_l1[2*i]),
                .b(z_l1[2*i+1]),
                .y(z_l2[i])
            );
        end

        for (i = 0; i < 4; i = i + 1) begin : GEN_ZERO_L3
            GATE_OR u_or3 (
                .a(z_l2[2*i]),
                .b(z_l2[2*i+1]),
                .y(z_l3[i])
            );
        end

        for (i = 0; i < 2; i = i + 1) begin : GEN_ZERO_L4
            GATE_OR u_or4 (
                .a(z_l3[2*i]),
                .b(z_l3[2*i+1]),
                .y(z_l4[i])
            );
        end
    endgenerate

    GATE_OR  u_or5  (.a(z_l4[0]), .b(z_l4[1]), .y(z_l5));
    GATE_NOT u_zero (.a(z_l5), .y(Zero));

endmodule