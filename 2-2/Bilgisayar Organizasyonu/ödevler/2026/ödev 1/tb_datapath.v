`timescale 1ps / 1ps

// =========================================================================
// DATAPATH TESTBENCH (Setup & Hold Time Analizi)
// =========================================================================

module tb_datapath();

    // ---------------------------------------------------------------------
    // SAAT FREKANSI AYARI (Öğrenciler F_max'ı bulmak için bunu değiştirecek)
    // ---------------------------------------------------------------------
    parameter T_CLK = 400; 

    // Zamanlama Kısıtları (regfile.v içindeki değerlerle aynı olmalı)
    parameter T_SETUP = 20; 
    parameter T_HOLD  = 60; 
    parameter T_RD_WAIT = 30; // rd1/rd2 okuma sonucu için bekleme süresi
    // Datapath Giriş Sinyalleri (Sürücüler)
    reg clk;
    reg rst;
    reg we3;
    reg [4:0] ra1, ra2, wa3;
    reg [2:0] ALUControl;
    reg wd_sel;
    reg [31:0] ext_data;

    // Datapath Çıkış Sinyalleri (Gözlemciler)
    wire [31:0] alu_result;
    wire [31:0] rd1, rd2;
    wire [31:0] wd3;
    wire zero, overflow;

    // ---------------------------------------------------------------------
    // DATAPATH MODÜLÜNÜN (DUT) BAĞLANMASI
    // ---------------------------------------------------------------------
    datapath dut (
        .clk(clk),
        .rst(rst),
        .we3(we3),
        .ra1(ra1),
        .ra2(ra2),
        .wa3(wa3),
        .ALUControl(ALUControl),
        .wd_sel(wd_sel),
        .ext_data(ext_data),
        .alu_result(alu_result),
        .rd1(rd1),
        .rd2(rd2),
        .wd3(wd3),
        .zero(zero),
        .overflow(overflow)
    );

    // ---------------------------------------------------------------------
    // SAAT ÜRETECİ (CLOCK GENERATOR)
    // ---------------------------------------------------------------------
    initial clk = 0;
    always #(T_CLK / 2.0) clk = ~clk;

    // ---------------------------------------------------------------------
    // ZAMANLAMA İHLALİ KONTROLCÜLERİ (TIMING MONITORS)
    // ---------------------------------------------------------------------
    time last_wd3_change = 0;
    time last_clk_edge = 0;

    // wd3 (RegFile'a yazılacak nihai veri) ne zaman değişti?
    always @(wd3) begin
        last_wd3_change = $time;
        
        // HOLD TIME KONTROLÜ: Veri, saat vuruşundan HEMEN SONRA mı değişti?
        // Sadece wd_sel == 0 (ALU sonucu yazılıyorsa) hold time kontrolü yap
        if (($time > 0) && (wd_sel == 0) && ($time - last_clk_edge) < T_HOLD) begin
            $display("[ZAMANLAMA HATASI - t=%0t] HOLD TIME İHLALİ! ALU'dan gelen wd3 sinyali saat vuruşundan sadece %0t ps sonra değişti (Kısıt: >%0t ps). Yarış durumu (Race Condition) var!", 
                     $time, ($time - last_clk_edge), T_HOLD);
        end
    end

    // Saat yükselen kenarında kayıt yap
    always @(posedge clk) begin
        last_clk_edge = $time;
        
        // SETUP TIME KONTROLÜ: Veri, saat vuruşundan HEMEN ÖNCE mi değişti?
        if (($time > 0) && we3 && wa3 != 0) begin
            if (($time - last_wd3_change) < T_SETUP) begin
                $display("[ZAMANLAMA HATASI - t=%0t] SETUP TIME İHLALİ! Veri (wd3) saat vuruşundan sadece %0t ps önce kararlı hale geldi (Kısıt: >%0t ps). T_CLK çok kısa (Frekans çok yüksek)!", 
                         $time, ($time - last_wd3_change), T_SETUP);
            end
        end
    end

    // ---------------------------------------------------------------------
    // TEST SENARYOSU
    // ---------------------------------------------------------------------
    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, tb_datapath);

        $display("=== Datapath Timing & Fonksiyonel Test Başlıyor ===");
        $display("Ayarlanan Saat Periyodu: %0d ps", T_CLK);
        $display("Testbench setup kisiti: %0d ps, hold kisiti: %0d ps", T_SETUP, T_HOLD);

        // 1. Reset ve Başlangıç Durumu
        rst = 1; we3 = 0; wd_sel = 0; ALUControl = 3'b010;
        ra1 = 0; ra2 = 0; wa3 = 0; ext_data = 32'b0;
        #(T_CLK * 2);
        rst = 0;

        // 2. Registerlara Başlangıç Değerlerini Yükle (wd_sel = 1 ile ext_data üzerinden)
        // r1 = 15, r2 = 10
        @(negedge clk);
        wd_sel = 1; we3 = 1; wa3 = 1; ext_data = 32'd15;
        @(negedge clk);
        wa3 = 2; ext_data = 32'd10;
        @(negedge clk);
        wd_sel = 0; we3 = 0; wa3 = 0; // Enjeksiyon bitti, ALU moduna geçildi

        $display("\n--- Maksimum Gecikme (Setup/Fmax) Stres Testi ---");
        // ADD işlemi ile uzun kritik yol testi (r3 = r1 + r2)
        @(negedge clk);
        ra1 = 1;             // rs1 = r1 (15)
        ra2 = 2;             // rs2 = r2 (10)
        wa3 = 3;             // rd = r3
        we3 = 1;             // Yazma aktif
        ALUControl = 3'b010; // ADD İşlemi
        
        @(negedge clk);
        we3 = 0; // Yazmayı kapat
        ra1 = 3; // Yazılan sonucu okumak için ra1'i r3'e ayarla
        #(T_RD_WAIT);      // Okuma gecikmesi için minik bir adım
        if (rd1 === 32'd25) $display("ADD Testi BAŞARILI. r3 = 25");
        else $display("FONKSİYONEL HATA! Beklenen: 25, Alınan: %0d. (T_CLK çok düşük olabilir!)", rd1);

        // SUB işlemi testi
        @(negedge clk);
        ra1 = 1;             // rs1 = r1 (15)
        ra2 = 2;             // rs2 = r2 (10)
        wa3 = 4;             // rd = r4
        we3 = 1;
        ALUControl = 3'b110; // SUB

        @(negedge clk);
        we3 = 0;
        ra1 = 4;
        #(T_RD_WAIT);
        if (rd1 === 32'd5) $display("SUB Testi BASARILI. r4 = 5");
        else $display("FONKSIYONEL HATA! SUB beklenen: 5, alinan: %0d", rd1);

        $display("\n--- Minimum Gecikme (Hold Time) Stres Testi ---");
        // Kısa yol testi: Kendisiyle işlem yapıp kendine yazma (r1 = r1 AND r2)
        @(negedge clk);
        ra1 = 1;             // rs1 = r1 (15)
        ra2 = 2;             // rs2 = r2 (10)
        wa3 = 1;             // rd = r1 (Aynı register'a yazıldığı için yarış riski çok yüksek!)
        we3 = 1;          
        ALUControl = 3'b000; // AND İşlemi (15 & 10 = 10)

        @(negedge clk);
        we3 = 0;
        ra1 = 1; // Sonucu oku
        #(T_RD_WAIT);
        if (rd1 === 32'd10) $display("AND Testi BAŞARILI. r1 = 10");
        else $display("FONKSİYONEL HATA! AND işlemi yanlış sonuç verdi.");

        #(T_CLK * 2);
        $display("\n=== Test Tamamlandı ===");
        $finish;
    end

endmodule