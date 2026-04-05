`timescale 1ps / 1ps

// =========================================================================
// YTU - RISC-V ALU TASARIMI (ÖĞRENCİ ŞABLONU)
// =========================================================================
// DİKKAT: Bu sadece bir başlangıç şablonudur. 
// Ödev tesliminizde davranışsal operatörler (+, -, <, ==, vs.) KULLANILAMAZ!
// Sadece 'lib_gates.v' içindeki temel kapıları alt modül olarak çağırarak 
// (instantiate) yapısal (structural) bir donanım tasarımı yapmalısınız.
// =========================================================================

module ALU (
    input [31:0] A,
    input [31:0] B,
    input [2:0] ALUControl,
    
    output [31:0] Result,
    output Zero,
    output Overflow
);

    // ---------------------------------------------------------------------
    // ÖĞRENCİLERİN YAPACAĞI TASARIM BURAYA GELECEK
    // ---------------------------------------------------------------------
    
    // Aşağıdaki atamalar (dummy), sadece testbench'in "Bilinmeyen Modül" 
    // hatası vermeden derlenebilmesi için konulmuştur.
    // Lütfen donanımınızı tasarlarken BURAYI SİLİN.
    
    assign Result   = 32'b0;
    assign Zero     = 1'b0;
    assign Overflow = 1'b0;

endmodule