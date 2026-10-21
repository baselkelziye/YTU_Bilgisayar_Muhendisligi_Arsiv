# =========================================================================
# YTU - RISC-V ALU & Datapath Tasarımı
# Otomatik Simülasyon Makefile
# Kullanım:
# make all	  # Tüm simülasyonları çalıştırır (maksimum ve minimum gecikmeler)
# =========================================================================

# Kullanılacak Araçlar
IV = iverilog
VVP = vvp
WAVE_VIEWER = gtkwave

# Kaynak Dosyalar (Öğrencilerin yazacağı alu.v dosyası da buraya eklenmiştir)
SOURCES = lib_gates.v regfile.v alu.v datapath.v tb_datapath.v

# Çıktı Dosyaları
OUT_MAX = sim_max.out
OUT_MIN = sim_min.out
VCD_MAX = wave_max.vcd
VCD_MIN = wave_min.vcd

# Varsayılan Hedef
all: run_max run_min

# 1. SETUP / F_MAX ANALİZİ (Maksimum Gecikmeler)
run_max: $(SOURCES)
	@echo "========================================================"
	@echo "1. MAKSİMUM GECİKMELER (T_PD) İLE DERLENİYOR..."
	@echo "========================================================"
	$(IV) -Tmax -o $(OUT_MAX) $(SOURCES)
	@echo "Maksimum gecikme simülasyonu çalıştırılıyor..."
	$(VVP) $(OUT_MAX)
	@mv dump.vcd $(VCD_MAX) 2>/dev/null || true
	@echo "Dalga formu oluşturuldu: $(VCD_MAX)\n"

# 2. HOLD TIME / YARIŞ DURUMU ANALİZİ (Minimum Gecikmeler)
run_min: $(SOURCES)
	@echo "========================================================"
	@echo "2. MİNİMUM GECİKMELER (T_CD) İLE DERLENİYOR..."
	@echo "========================================================"
	$(IV) -Tmin -o $(OUT_MIN) $(SOURCES)
	@echo "Minimum gecikme simülasyonu çalıştırılıyor..."
	$(VVP) $(OUT_MIN)
	@mv dump.vcd $(VCD_MIN) 2>/dev/null || true
	@echo "Dalga formu oluşturuldu: $(VCD_MIN)\n"

# GTKWave Gösterici Kısayolları
view_max:
	$(WAVE_VIEWER) $(VCD_MAX) &

view_min:
	$(WAVE_VIEWER) $(VCD_MIN) &

# Temizlik
clean:
	@echo "Derleme dosyaları temizleniyor..."
	rm -f $(OUT_MAX) $(OUT_MIN) $(VCD_MAX) $(VCD_MIN) dump.vcd