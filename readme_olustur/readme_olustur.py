"""
README oluşturma ana scripti.

SOLID ve KISS prensiplerine uygun, performans optimize edilmiş versiyon.
"""
import json
import os
import sys
import time

# Path setup
current_directory = os.path.dirname(os.path.abspath(__file__))
python_ui_path = os.path.join(current_directory, "readme_guncelleme_arayuzu_python")
sys.path.insert(0, python_ui_path)

from degiskenler import (
    ANA_README_YOLU, DOKUMANLAR_REPO_YOLU, README_MD,
    DERSLER_JSON_NAME, HOCALAR_JSON_NAME, GIRIS_JSON_NAME,
    REPO_KULLANIMI_JSON_NAME, YAZARIN_NOTLARI_JSON_NAME,
    KATKIDA_BULUNANLAR_JSON_NAME, DONEMLER_JSON_NAME,
    KONFIGURASYON_JSON_NAME, MAAS_ISTATISTIKLERI_TXT_NAME,
    YIL, DONEM, AD, DERSLER, DONEMLER, DONEM_ADI, TIP,
    HOCALAR, YILDIZ_GECMISI, GUNCEL_OLMAYAN_DERS_ACIKLAMASI
)
from metin_islemleri import donem_dosya_yolu_getir
from hoca_kisaltma_olustur import hoca_kisaltma_olustur
from konfigurasyon_json_kontrol import konfigurasyon_json_guncelle
from cikti_yazdirma import custom_write, custom_write_error

from folder_cache import FolderCache
from buffered_writer import BufferedReadmeWriter
from writers import (
    GirisWriter, DerslerWriter, HocalarWriter,
    RepoKullanimiWriter, YazarNotlariWriter, KatkidaBulunanlarWriter,
    DonemWriter, DersKlasorWriter
)


class DataLoader:
    """Veri yükleme sınıfı - JSON ve TXT dosyalarını okur."""
    
    @staticmethod
    def json_oku(json_dosyasi: str) -> dict | None:
        """JSON dosyasını oku."""
        try:
            with open(json_dosyasi, "r", encoding="utf-8") as f:
                return json.load(f)
        except FileNotFoundError:
            return None
    
    @staticmethod
    def txt_oku(txt_dosyasi: str) -> str | None:
        """TXT dosyasını oku."""
        try:
            with open(txt_dosyasi, "r", encoding="utf-8") as f:
                return f.read()
        except FileNotFoundError:
            return None


class HocaKisaltmalarWriter:
    """Hoca kısaltmaları yazıcısı."""
    
    def write(self, writer: BufferedReadmeWriter, hocalar_data: dict) -> None:
        """Hoca kısaltmalarını yaz."""
        if hocalar_data is None or HOCALAR not in hocalar_data:
            return
        
        kisaltmalar = {}
        for hoca in hocalar_data[HOCALAR]:
            ad = hoca.get(AD, "")
            if ad:
                kisaltma = hoca_kisaltma_olustur(ad)
                kisaltmalar[kisaltma] = ad
        
        writer.writeline("<details>")
        writer.writeline("<summary><b>🆎 Hoca Kısaltmaları</b></summary>\n")
        writer.writeline("<h2 align='center'>🆎 Hoca Kısaltmaları</h2>\n")
        
        for kisaltma in sorted(kisaltmalar.keys()):
            ad = kisaltmalar[kisaltma]
            writer.writeline(f"<p align='center'>🔹 <b>{kisaltma}</b> &emsp; {ad} 🔹</p>")
        
        writer.writeline("</details>\n")


class YildizGecmisiWriter:
    """Yıldız geçmişi yazıcısı."""
    
    def write(self, writer: BufferedReadmeWriter) -> None:
        """Yıldız geçmişini yaz."""
        writer.write(YILDIZ_GECMISI)


class MaasIstatistikleriWriter:
    """Maaş istatistikleri yazıcısı."""
    
    def write(self, writer: BufferedReadmeWriter, veri: str) -> None:
        """Maaş istatistiklerini yaz."""
        if veri is None:
            return
        
        baslik = "Bölüm Mezunları Maaş İstatistikleri"
        writer.writeline("<details>")
        writer.writeline(f"<summary><b>💰 {baslik}</b></summary>\n")
        writer.writeline(f"<h2 align='center'>💰 {baslik}</h2>\n")
        writer.write(veri)
        writer.writeline("\n</details>\n")


class ReadmeGenerator:
    """
    Ana README oluşturucu.
    
    Tüm bölümleri orchestrate eder ve performans optimizasyonlarını uygular.
    """
    
    def __init__(self):
        self.loader = DataLoader()
        self._load_data()
        self._init_cache()
        self._init_writers()
    
    def _load_data(self) -> None:
        """Tüm verileri yükle."""
        custom_write("Veriler yukleniyor...\n")
        
        self.giris_bilgileri = self.loader.json_oku(GIRIS_JSON_NAME)
        self.repo_kullanimi = self.loader.json_oku(REPO_KULLANIMI_JSON_NAME)
        self.dersler = self.loader.json_oku(DERSLER_JSON_NAME)
        self.hocalar = self.loader.json_oku(HOCALAR_JSON_NAME)
        self.yazar_notlari = self.loader.json_oku(YAZARIN_NOTLARI_JSON_NAME)
        self.katkida_bulunanlar = self.loader.json_oku(KATKIDA_BULUNANLAR_JSON_NAME)
        self.donemler = self.loader.json_oku(DONEMLER_JSON_NAME)
        self.maas_istatistikleri = self.loader.txt_oku(MAAS_ISTATISTIKLERI_TXT_NAME)
        
        # Dersleri sırala
        if self.dersler:
            self.dersler[DERSLER] = sorted(
                self.dersler.get(DERSLER, []),
                key=self._ders_siralama
            )
    
    def _ders_siralama(self, ders: dict) -> tuple:
        """Ders sıralama anahtarı."""
        yil_sirasi = [1, 2, 3, 4, 0]
        donem_sirasi = ["Güz", "Bahar", ""]
        
        yil = ders.get(YIL, 0)
        yil_idx = yil_sirasi.index(yil) if yil in yil_sirasi else len(yil_sirasi)
        
        donem = ders.get(DONEM, "")
        donem_idx = donem_sirasi.index(donem) if donem in donem_sirasi else len(donem_sirasi)
        
        ad = ders.get(AD, "").lower()
        
        return (yil_idx, donem_idx, ad)
    
    def _init_cache(self) -> None:
        """Klasör cache'ini başlat."""
        custom_write("Klasor cache olusturuluyor...\n")
        self.folder_cache = FolderCache(DOKUMANLAR_REPO_YOLU, max_depth=4)
        custom_write(f"Cache'de {self.folder_cache.folder_count} klasor bulundu.\n")
    
    def _init_writers(self) -> None:
        """Writer'ları başlat."""
        self.giris_writer = GirisWriter()
        self.repo_kullanimi_writer = RepoKullanimiWriter()
        self.dersler_writer = DerslerWriter(self.folder_cache, self.hocalar)
        self.hocalar_writer = HocalarWriter(self.dersler)
        self.yazar_notlari_writer = YazarNotlariWriter()
        self.katkida_bulunanlar_writer = KatkidaBulunanlarWriter()
        self.hoca_kisaltmalar_writer = HocaKisaltmalarWriter()
        self.yildiz_gecmisi_writer = YildizGecmisiWriter()
        self.maas_istatistikleri_writer = MaasIstatistikleriWriter()
        self.donem_writer = DonemWriter(DOKUMANLAR_REPO_YOLU)
        self.ders_klasor_writer = DersKlasorWriter(self.dersler or {})
    
    def generate_ana_readme(self) -> None:
        """Ana README.md dosyasını oluştur."""
        custom_write("Ana README.md olusturuluyor...\n")
        
        # Mevcut README'yi sil
        if os.path.exists(ANA_README_YOLU):
            os.remove(ANA_README_YOLU)
        
        writer = BufferedReadmeWriter()
        
        # Bölümleri yaz
        if self.giris_bilgileri:
            custom_write("Giris bilgileri ekleniyor...\n")
            self.giris_writer.write(writer, self.giris_bilgileri)
        
        if self.repo_kullanimi:
            custom_write("Repo kullanimi ekleniyor...\n")
            self.repo_kullanimi_writer.write(writer, self.repo_kullanimi)
        
        if self.maas_istatistikleri:
            custom_write("Maas istatistikleri ekleniyor...\n")
            self.maas_istatistikleri_writer.write(writer, self.maas_istatistikleri)
        
        if self.dersler:
            custom_write("Ders bilgileri ekleniyor...\n")
            self.dersler_writer.write(writer, self.dersler)
        
        if self.hocalar:
            custom_write("Hoca bilgileri ekleniyor...\n")
            self.hocalar_writer.write(writer, self.hocalar)
        
        if self.yazar_notlari:
            custom_write("Yazar notlari ekleniyor...\n")
            self.yazar_notlari_writer.write(writer, self.yazar_notlari)
        
        if self.hocalar:
            custom_write("Hoca kisaltmalari ekleniyor...\n")
            self.hoca_kisaltmalar_writer.write(writer, self.hocalar)
        
        if self.katkida_bulunanlar:
            custom_write("Katkida bulunanlar ekleniyor...\n")
            self.katkida_bulunanlar_writer.write(writer, self.katkida_bulunanlar)
        
        custom_write("Yildiz gecmisi ekleniyor...\n")
        self.yildiz_gecmisi_writer.write(writer)
        
        # Dosyaya yaz
        writer.save(ANA_README_YOLU)
        custom_write("Ana README.md olusturuldu.\n")
    
    def generate_ders_readmes(self) -> None:
        """Ders klasörlerinin README dosyalarını oluştur."""
        if not self.dersler:
            custom_write_error("Ders bilgileri bulunamadi.\n")
            return
        
        custom_write("Ders README'leri olusturuluyor...\n")
        
        for ders in self.dersler.get(DERSLER, []):
            ders_adi = ders.get(AD, "")
            custom_write(f"{ders_adi} README.md olusturuluyor...\n")
            
            # Klasörü bul veya oluştur
            ders_klasoru = self.folder_cache.find_best_match(ders_adi)
            klasor_sonradan_olustu = False
            
            if ders_klasoru:
                # Klasörde başka dosya var mı kontrol et
                icerikler = [f for f in os.listdir(ders_klasoru) if f.lower() != "readme.md"]
                if not icerikler:
                    klasor_sonradan_olustu = True
            else:
                # Klasör yok, oluştur
                ders_klasoru = self._ders_klasoru_olustur(ders)
                klasor_sonradan_olustu = True
            
            # README yaz
            writer = BufferedReadmeWriter()
            self.ders_klasor_writer.write_ders_readme(writer, ders, klasor_sonradan_olustu)
            writer.save(os.path.join(ders_klasoru, README_MD))
            
            custom_write(f"{ders_adi} README.md olusturuldu.\n")
    
    def _ders_klasoru_olustur(self, ders: dict) -> str:
        """Ders klasörü oluştur."""
        donem = self._dersin_donemini_getir(ders)
        donem_yolu = donem_dosya_yolu_getir(donem, DOKUMANLAR_REPO_YOLU)
        ders_klasor_yolu = os.path.join(donem_yolu, ders.get(AD, ""))
        os.makedirs(ders_klasor_yolu, exist_ok=True)
        return ders_klasor_yolu
    
    def _dersin_donemini_getir(self, ders: dict) -> dict:
        """Dersin dönemini getir."""
        if ders.get(YIL, 0) != 0 and ders.get(DONEM, "") != "":
            return {YIL: ders.get(YIL, 0), DONEM: ders.get(DONEM, "")}
        if ders.get(TIP, "") != "":
            return {DONEM_ADI: ders.get(TIP, "")}
        return {}
    
    def generate_donem_readmes(self) -> None:
        """Dönem README dosyalarını oluştur."""
        if not self.donemler:
            custom_write_error("Donem bilgileri bulunamadi.\n")
            return
        
        custom_write("Donem README'leri olusturuluyor...\n")
        
        # Her dönem için README oluştur
        for donem in self.donemler.get(DONEMLER, []):
            donem_adi = donem.get(DONEM_ADI, "")
            custom_write(f"{donem_adi} README.md olusturuluyor...\n")
            
            donem_dosya_yolu = donem_dosya_yolu_getir(donem, DOKUMANLAR_REPO_YOLU)
            os.makedirs(donem_dosya_yolu, exist_ok=True)
            
            writer = BufferedReadmeWriter()
            self.donem_writer.write_donem_readme(writer, donem)
            writer.save(os.path.join(donem_dosya_yolu, README_MD))
            
            custom_write(f"{donem_adi} README.md olusturuldu.\n")
        
        # Dersleri dönem README'lerine ekle
        if self.dersler:
            custom_write("Dersler donem README'lerine ekleniyor...\n")
            self._birlestir_dersler_ile_donemler()
    
    def _birlestir_dersler_ile_donemler(self) -> None:
        """Dersleri dönem README'lerine ekle."""
        guncel_olmayan_aciklama = self.dersler.get(GUNCEL_OLMAYAN_DERS_ACIKLAMASI, "")
        
        for ders in self.dersler.get(DERSLER, []):
            ders_adi = ders.get(AD, "")
            custom_write(f"{ders_adi} donemine ekleniyor...\n")
            
            for donem in self.donemler.get(DONEMLER, []):
                # Ders bu döneme ait mi kontrol et
                if not self._ders_doneme_ait_mi(ders, donem):
                    continue
                
                dosya_yolu = os.path.join(
                    donem_dosya_yolu_getir(donem, DOKUMANLAR_REPO_YOLU),
                    README_MD
                )
                
                writer = BufferedReadmeWriter()
                self.donem_writer.write_ders_to_donem(writer, ders, guncel_olmayan_aciklama)
                writer.append_to_file(dosya_yolu)
                break
            
            custom_write(f"{ders_adi} donemine eklendi.\n")
    
    def _ders_doneme_ait_mi(self, ders: dict, donem: dict) -> bool:
        """Dersin döneme ait olup olmadığını kontrol et."""
        if ders.get(TIP) == donem.get(DONEM_ADI):
            return True
        
        if (ders.get(YIL) == donem.get(YIL) and 
            ders.get(DONEM) == donem.get(DONEM) and
            ders.get(YIL, 0) != 0 and ders.get(DONEM, "") != ""):
            return True
        
        return False
    
    def generate_all(self) -> None:
        """Tüm README dosyalarını oluştur."""
        start_time = time.time()
        
        # Konfigürasyon kontrolü
        konfigurasyon_json_guncelle(KONFIGURASYON_JSON_NAME)
        
        # README dosyalarını oluştur
        self.generate_ana_readme()
        self.generate_ders_readmes()
        self.generate_donem_readmes()
        
        elapsed = time.time() - start_time
        custom_write(f"\nTum README dosyalari {elapsed:.2f} saniyede olusturuldu.\n")


def main():
    """Ana fonksiyon."""
    generator = ReadmeGenerator()
    generator.generate_all()


if __name__ == "__main__":
    main()
