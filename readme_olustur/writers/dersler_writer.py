"""Dersler bölümü yazıcısı."""
from writers.base import SectionWriter
from writers.yardimci import (
    puanlari_yildiza_cevir, baslik_linki_olustur,
    gorustenTarihGetir, detay_etiketleri_olustur,
    ders_siralama_anahtari, donem_siralamasi,
    yerel_yoldan_github_linkine, sirali_ekle
)
from typing import TYPE_CHECKING, Optional

import sys
import os
current_directory = os.path.dirname(os.path.abspath(__file__))
parent_directory = os.path.dirname(current_directory)
python_ui_path = os.path.join(parent_directory, "readme_guncelleme_arayuzu_python")
sys.path.insert(0, python_ui_path)

from degiskenler import (
    DERSLER, AD, TIP, YIL, DONEM, OY_SAYISI, BOLUM_ADI, BOLUM_ACIKLAMASI,
    EN_POPULER_DERS, DERS_ADI, OGRENCI_GORUSLERI, KISI, YORUM, DERS_YORUMLAMA_LINKI,
    DERS_OYLAMA_LINKI, KOLAYLIK_PUANI, GEREKLILIK_PUANI,
    YILLARA_GORE_YILDIZ_SAYILARI, GUNCEL_MI, GUNCEL_OLMAYAN_DERS_ACIKLAMASI,
    EN_POPULER_HOCA, HOCA_ADI, DERSI_VEREN_HOCALAR, KISALTMA,
    ARTIK_MUFREDATA_DAHIL_OLMAYAN_DERSLER
)

if TYPE_CHECKING:
    from buffered_writer import BufferedReadmeWriter
    from folder_cache import FolderCache


class DerslerWriter(SectionWriter):
    """Dersler bölümü yazıcısı."""
    
    def __init__(self, folder_cache: Optional["FolderCache"] = None, hocalar_data: Optional[dict] = None):
        """
        Args:
            folder_cache: FolderCache instance (klasör arama için)
            hocalar_data: Hoca verileri (popüler hoca işaretlemesi için)
        """
        self.folder_cache = folder_cache
        self.hocalar_data = hocalar_data or {}
    
    @property
    def section_name(self) -> str:
        return "Dersler"
    
    def _write_ogrenci_gorusu(self, writer: "BufferedReadmeWriter", gorusler: list, girinti: str = "") -> None:
        """Öğrenci görüşlerini yaz."""
        if not gorusler:
            return
        
        writer.writeline(f"{girinti}- 💭 **Öğrenci Görüşleri:**")
        for gorus in gorusler:
            kisi = gorus.get(KISI, "").strip()
            yorum = gorus.get(YORUM, "")
            tarih = gorustenTarihGetir(gorus)
            writer.writeline(f"{girinti}  - 👤 **_{kisi}_**: {yorum} {tarih}")
        writer.writeline(f"{girinti}    - ℹ️ Siz de [linkten]({DERS_YORUMLAMA_LINKI}) anonim şekilde görüşlerinizi belirtebilirsiniz.")
    
    def _write_yildizlar(
        self, writer: "BufferedReadmeWriter",
        kolaylik: float, gereklilik: float,
        girinti: str, oy_sayisi: int, yil_prefix: str = ""
    ) -> None:
        """Ders yıldızlarını yaz."""
        writer.writeline(f"{girinti}  - ✅ {yil_prefix}Dersi Kolay Geçer Miyim: {puanlari_yildiza_cevir(kolaylik)}")
        writer.writeline(f"{girinti}  - 🎯 {yil_prefix}Ders Mesleki Açıdan Gerekli Mi: {puanlari_yildiza_cevir(gereklilik)}")
        writer.writeline(f"{girinti}    - ℹ️ Yıldızlar {oy_sayisi} oy üzerinden hesaplanmıştır. Siz de [linkten]({DERS_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.")
    
    def _write_yildiz_bolumu(self, writer: "BufferedReadmeWriter", ders: dict, girinti: str = "") -> None:
        """Yıldız bölümünü yaz."""
        writer.writeline(f"{girinti}- ⭐ **Yıldız Sayıları:**")
        
        if OY_SAYISI in ders:
            kolaylik = ders.get(KOLAYLIK_PUANI, 1)
            gereklilik = ders.get(GEREKLILIK_PUANI, 1)
            self._write_yildizlar(writer, kolaylik, gereklilik, girinti, ders.get(OY_SAYISI, 0))
        else:
            writer.writeline(f"{girinti}    - ℹ️ Henüz yıldız veren yok. Siz de [linkten]({DERS_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.")
            return
        
        # Yıllara göre yıldızlar
        ek_girinti = "  "
        yeni_girinti = girinti + ek_girinti
        
        if YILLARA_GORE_YILDIZ_SAYILARI in ders:
            acilis, kapanis = detay_etiketleri_olustur("📅 Yıllara Göre Yıldız Sayıları", yeni_girinti)
            writer.write(acilis)
            
            for yildiz_bilgileri in ders[YILLARA_GORE_YILDIZ_SAYILARI]:
                yil = yildiz_bilgileri.get(YIL, "bilinmiyor")
                writer.writeline(f"{yeni_girinti + ek_girinti}- 📅 *{yil} yılı için yıldız bilgileri*")
                self._write_yildizlar(
                    writer,
                    yildiz_bilgileri.get(KOLAYLIK_PUANI, 0),
                    yildiz_bilgileri.get(GEREKLILIK_PUANI, 0),
                    yeni_girinti + ek_girinti,
                    yildiz_bilgileri.get(OY_SAYISI, 0),
                    f"{yil} Yılında "
                )
            
            writer.write(kapanis)
    
    def _grupla_dersler(self, dersler: list) -> dict:
        """Dersleri yıl ve döneme göre grupla."""
        gruplanmis = {}
        
        for ders in dersler:
            if not ders.get(GUNCEL_MI, True):
                donem_key = ARTIK_MUFREDATA_DAHIL_OLMAYAN_DERSLER
            elif ders.get(YIL, 0) > 0:
                donem_key = f"{ders[YIL]}. Yıl - {ders.get(DONEM, '')}"
            elif ders.get(TIP):
                donem_key = ders[TIP]
            else:
                continue
            
            if donem_key not in gruplanmis:
                gruplanmis[donem_key] = []
            sirali_ekle(gruplanmis[donem_key], ders, ders_siralama_anahtari)
        
        return gruplanmis
    
    def write(self, writer: "BufferedReadmeWriter", data: dict) -> None:
        """
        Dersler bölümünü yaz.
        
        Args:
            writer: BufferedReadmeWriter instance
            data: Ders bilgileri dict'i
        """
        if data is None:
            return
        
        dersler = data.get(DERSLER, [])
        if not dersler:
            return
        
        # Popüler ders/hoca bilgileri
        en_populer_ders = data.get(EN_POPULER_DERS, {})
        en_populer_ders_adi = en_populer_ders.get(DERS_ADI, "")
        en_populer_ders_oy = en_populer_ders.get(OY_SAYISI, 0)
        
        en_populer_hoca = self.hocalar_data.get(EN_POPULER_HOCA, {})
        en_populer_hoca_adi = en_populer_hoca.get(HOCA_ADI, "")
        en_populer_hoca_oy = en_populer_hoca.get(OY_SAYISI, 0)
        
        # Bölüm başlığı
        bolum_adi = data.get(BOLUM_ADI, "Dersler")
        bolum_aciklamasi = data.get(BOLUM_ACIKLAMASI, "")
        
        writer.writeline(f"<details>")
        writer.writeline(f"<summary><b>📖 {bolum_adi}</b></summary>\n")
        writer.writeline(f"\n\n\n## 📖 {bolum_adi}")
        writer.writeline(f"📄 {bolum_aciklamasi}\n\n\n")
        
        # Dersleri grupla ve yaz
        gruplanmis_dersler = self._grupla_dersler(dersler)
        
        for donem in sorted(gruplanmis_dersler.keys(), key=donem_siralamasi):
            writer.writeline(f"\n### 🗓 {donem}")
            
            for ders in gruplanmis_dersler[donem]:
                writer.writeline("\n")
                
                ders_adi = ders.get(AD, "")
                populer_isaret = "👑" if ders_adi == en_populer_ders_adi else ""
                populer_bilgi = f" En popüler ders ({en_populer_ders_oy} oy)" if ders_adi == en_populer_ders_adi else ""
                
                writer.writeline(f"#### 📘 {ders_adi} {populer_isaret}{populer_bilgi}")
                writer.writeline(f"  - 🏷️ **Ders Tipi:** {ders.get(TIP, '')}")
                
                self._write_ogrenci_gorusu(writer, ders.get(OGRENCI_GORUSLERI, []), girinti="  ")
                self._write_yildiz_bolumu(writer, ders, girinti="  ")
                
                # Dersi veren hocalar
                dersi_veren_hocalar = ders.get(DERSI_VEREN_HOCALAR, [])
                if dersi_veren_hocalar:
                    writer.writeline("  - 👨‍🏫 👩‍🏫 **Dersi Yürüten Akademisyenler:**")
                    for hoca in dersi_veren_hocalar:
                        hoca_kisaltma = hoca.get(KISALTMA, "")
                        hoca_ad = hoca.get(AD, "")
                        
                        if hoca_ad != en_populer_hoca_adi:
                            writer.writeline(f"    - [{hoca_kisaltma}]{baslik_linki_olustur(hoca_ad)}")
                        else:
                            p_isaret = "👑"
                            p_bilgi = f" En popüler hoca ({en_populer_hoca_oy} oy)"
                            hoca_id = f"{hoca_ad} {p_isaret}{p_bilgi}"
                            writer.writeline(f"    - [{hoca_kisaltma}]{baslik_linki_olustur(hoca_id)}")
                
                # Ders klasörü linki
                if self.folder_cache:
                    ders_klasor_yolu = self.folder_cache.find_best_match(ders_adi)
                    if ders_klasor_yolu:
                        github_link = yerel_yoldan_github_linkine(ders_klasor_yolu)
                        if github_link:
                            writer.writeline(f"  - 📂 [Ders Klasörü]({github_link})")
                
                # Güncel değil uyarısı
                if not ders.get(GUNCEL_MI, True):
                    writer.writeline("  - ℹ️ Dersin içeriği güncel değil")
                    guncel_olmayan_aciklama = data.get(GUNCEL_OLMAYAN_DERS_ACIKLAMASI, "")
                    if guncel_olmayan_aciklama:
                        writer.writeline(f"    - {guncel_olmayan_aciklama}")
        
        writer.writeline("</details>\n")
