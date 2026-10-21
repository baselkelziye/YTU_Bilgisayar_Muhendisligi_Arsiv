`timescale 1ps / 1ps

// =========================================================================
// YTU - RISC-V REGISTER FILE 
// Format: #(Minimum : Tipik : Maksimum)
// =========================================================================

module RegFile (
    input clk,
    input rst,
    input we3,              // Write Enable (Yazma İzni)
    input [4:0] ra1,        // Read Address 1 (rs1)
    input [4:0] ra2,        // Read Address 2 (rs2)
    input [4:0] wa3,        // Write Address (rd)
    input [31:0] wd3,       // Write Data
    output [31:0] rd1,      // Read Data 1
    output [31:0] rd2       // Read Data 2
);

    // ---------------------------------------------------------------------
    // ZAMANLAMA PARAMETRELERİ (Öğrencilerin analiz raporu için)
    // ---------------------------------------------------------------------
    parameter T_SETUP = 20; // Kurulum Zamanı kısıtı (ps)
    parameter T_HOLD  = 60; // Tutma Zamanı kısıtı (ps)

    // Okuma Gecikmesi (Read Delay - Adres değişiminden verinin çıkışa gelmesi)
    parameter T_RD_CD = 12; // Minimum okuma gecikmesi
    parameter T_RD_T  = 18; // Tipik okuma gecikmesi
    parameter T_RD_PD = 25; // Maksimum okuma gecikmesi

    // Clock-to-Q Gecikmesi (Saat vuruşundan sonra yazılan verinin oturması)
    parameter T_CQ_CD = 10; // Minimum C-to-Q gecikmesi (Hold analizi için)
    parameter T_CQ_T  = 15; // Tipik C-to-Q gecikmesi
    parameter T_CQ_PD = 22; // Maksimum C-to-Q gecikmesi (Setup analizi için)

    // ---------------------------------------------------------------------
    // DONANIM TANIMI
    // ---------------------------------------------------------------------
    // 32 adet 32-bitlik register array
    reg [31:0] registers [31:0];
    integer i;

    // Asenkron Okuma: ra1 veya ra2 0 ise (x0), çıkış her zaman 0'dır (RISC-V standardı).
    wire [31:0] temp_rd1 = (ra1 == 5'b00000) ? 32'b0 : registers[ra1];
    wire [31:0] temp_rd2 = (ra2 == 5'b00000) ? 32'b0 : registers[ra2];

    // Okuma gecikmesinin (min:typ:max) formatında atanması
    assign #(T_RD_CD:T_RD_T:T_RD_PD) rd1 = temp_rd1;
    assign #(T_RD_CD:T_RD_T:T_RD_PD) rd2 = temp_rd2;

    // Senkron Yazma
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            for (i = 0; i < 32; i = i + 1) begin
                registers[i] <= 32'b0;
            end
        end else if (we3) begin
            // x0 (Sıfırıncı register) RISC-V'de yazmaya karşı korumalıdır
            if (wa3 != 5'b00000) begin
                // Non-blocking assignment ile Clock-to-Q gecikmesi (min:typ:max)
                registers[wa3] <= #(T_CQ_CD:T_CQ_T:T_CQ_PD) wd3;
            end
        end
    end

endmodule