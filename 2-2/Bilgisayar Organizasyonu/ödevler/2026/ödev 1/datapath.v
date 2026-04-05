`timescale 1ps / 1ps

// =========================================================================
// RISC-V DATAPATH ÜST MODÜLÜ (Öğrenciler İçini Dolduracak)
// =========================================================================

module datapath (
    input clk,
    input rst,
    input we3,                  // RegFile Yazma İzni
    input [4:0] ra1,            // Okunacak Register 1 Adresi (rs1)
    input [4:0] ra2,            // Okunacak Register 2 Adresi (rs2)
    input [4:0] wa3,            // Yazılacak Register Adresi (rd)
    input [2:0] ALUControl,     // ALU İşlem Seçici
    
    // Testbench üzerinden Register'lara değer atamak için gerekli portlar
    input wd_sel,               // 0: ALU Sonucunu yaz, 1: ext_data'yı yaz
    input [31:0] ext_data,      // Dışarıdan enjekte edilecek veri
    
    // Gözlem (Testbench) Çıkışları
    output [31:0] alu_result,   // ALU'nun hesapladığı sonuç
    output [31:0] rd1,          // RegFile'dan okunan 1. Veri
    output [31:0] rd2,          // RegFile'dan okunan 2. Veri
    output [31:0] wd3,          // RegFile'a giren NİHAİ yazma verisi (Hold Time takibi için)
    output zero,                // ALU Zero bayrağı
    output overflow             // ALU Overflow bayrağı
);

    // ---------------------------------------------------------------------
    // ÖĞRENCİLERİN YAPACAĞI TASARIM BURAYA GELECEK
    // ---------------------------------------------------------------------
    // 1. RegFile modülünü çağırın (instantiate).
    // 2. ALU modülünü çağırın (instantiate).
    // 3. wd_sel sinyaline göre RegFile'ın wd3 girişine ext_data veya 
    //    alu_result bağlayacak bir 32-bit MUX tasarlayın (veya atayın).
    // 4. Çıkış portlarını (output) ilgili iç sinyallere bağlayın.
    
endmodule