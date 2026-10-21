`timescale 1ps / 1ps

// =========================================================================
// YTU - RISC-V Single Cycle Processor Temel Kapı Kütüphanesi
// Format: #(T_CD : T_T : T_PD)
// T_CD : Contamination Delay
// T_T  : Typical Delay
// T_PD : Propagation Delay
// =========================================================================

module GATE_NOT (input a, output y);
    parameter T_CD = 5;
    parameter T_T  = 8;
    parameter T_PD = 10;

    assign #(T_CD:T_T:T_PD) y = ~a;
endmodule


module GATE_NAND (input a, input b, output y);
    parameter T_CD = 8;
    parameter T_T  = 12;
    parameter T_PD = 15;

    assign #(T_CD:T_T:T_PD) y = ~(a & b);
endmodule


module GATE_NOR (input a, input b, output y);
    parameter T_CD = 8;
    parameter T_T  = 12;
    parameter T_PD = 15;

    assign #(T_CD:T_T:T_PD) y = ~(a | b);
endmodule


module GATE_AND (input a, input b, output y);
    parameter T_CD = 15;
    parameter T_T  = 20;
    parameter T_PD = 25;

    assign #(T_CD:T_T:T_PD) y = a & b;
endmodule


module GATE_OR (input a, input b, output y);
    parameter T_CD = 15;
    parameter T_T  = 20;
    parameter T_PD = 25;

    assign #(T_CD:T_T:T_PD) y = a | b;
endmodule


module GATE_XOR (input a, input b, output y);
    parameter T_CD = 25;
    parameter T_T  = 32;
    parameter T_PD = 40;

    assign #(T_CD:T_T:T_PD) y = a ^ b;
endmodule

module GATE_MUX2 (input d0, input d1, input s, output y);
    parameter T_CD = 15;
    parameter T_T  = 22;
    parameter T_PD = 30;

    assign #(T_CD:T_T:T_PD) y = s ? d1 : d0;
endmodule

module GATE_MUX4 (
    input d0,
    input d1,
    input d2,
    input d3,
    input [1:0] s,
    output y
);
    parameter T_CD = 20;
    parameter T_T  = 28;
    parameter T_PD = 35;

    assign #(T_CD:T_T:T_PD) y =
        (s == 2'b00) ? d0 :
        (s == 2'b01) ? d1 :
        (s == 2'b10) ? d2 :
                       d3;
endmodule