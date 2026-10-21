`timescale 1ps / 1ps

// =========================================================================
// YTU - RISC-V ALU Tasarımı Temel Kapı Kütüphanesi
// Format: #(T_CD : T_T : T_PD) -> (Minimum : Tipik : Maksimum)
// T_CD : Contamination Delay (Hold Time analizi için)
// T_T  : Typical Delay (Normal çalışma şartları)
// T_PD : Propagation Delay (Setup/Maksimum frekans analizi için)
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

// 2x1 Multiplexer (Optimizasyon yarışında çok kullanılacak)
// s=0 ise y=d0, s=1 ise y=d1
module GATE_MUX2 (input d0, input d1, input s, output y);
    parameter T_CD = 15;
    parameter T_T  = 22;
    parameter T_PD = 30; 
    assign #(T_CD:T_T:T_PD) y = s ? d1 : d0;
endmodule