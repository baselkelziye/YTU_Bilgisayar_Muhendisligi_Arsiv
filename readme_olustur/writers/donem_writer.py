"""Dönem README yazıcısı."""
from writers.base import SectionWriter
from writers.yardimci import (
    puanlari_yildiza_cevir, gorustenTarihGetir, detay_etiketleri_olustur,
    kaynak_linklerini_goreceli_yap
)
from typing import TYPE_CHECKING, Optional
import unicodedata

import sys
import os
current_directory = os.path.dirname(os.path.abspath(__file__))
parent_directory = os.path.dirname(current_directory)
python_ui_path = os.path.join(parent_directory, "readme_guncelleme_arayuzu_python")
sys.path.insert(0, python_ui_path)

from degiskenler import (
    DONEMLER, DONEM_ADI, YIL, DONEM, TIP, AD, OY_SAYISI,
    OGRENCI_GORUSLERI, KISI, YORUM, DERS_YORUMLAMA_LINKI, DERS_OYLAMA_LINKI,
    KOLAYLIK_PUANI, GEREKLILIK_PUANI, YILLARA_GORE_YILDIZ_SAYILARI,
    GUNCEL_MI, DERSE_DAIR_ONERILER, ONERILER, ONERI_SAHIBI,
    FAYDALI_OLABILECEK_KAYNAKLAR, DERSI_VEREN_HOCALAR, KISALTMA,
    GENEL_CIKMIS_SORULAR_METNI, FAYDALI_OLABILECEK_KAYNAKLAR_UYARI_MESAJI,
    NFKD, README_MD
)
from metin_islemleri import donem_dosya_yolu_getir

if TYPE_CHECKING:
    from buffered_writer import BufferedReadmeWriter


class DonemWriter(SectionWriter):
    """Dönem README yazıcısı."""
    
    def __init__(self, dokumanlar_repo_yolu: str):
        """
        Args:
            dokumanlar_repo_yolu: Dökümanlar repo yolu
        """
        self.dokumanlar_repo_yolu = dokumanlar_repo_yolu
    
    @property
    def section_name(self) -> str:
        return "Dönem README"
    
    def _write_ogrenci_gorusu(self, writer: "BufferedReadmeWriter", gorusler: list) -> None:
        """Öğrenci görüşlerini yaz - sadece görüş varsa."""
        if gorusler:
            writer.writeline("- 💭 **Öğrenci Görüşleri:**")
            for gorus in gorusler:
                kisi = gorus.get(KISI, "").strip()
                yorum = gorus.get(YORUM, "")
                tarih = gorustenTarihGetir(gorus)
                writer.writeline(f"  - 👤 **_{kisi}_**: {yorum} {tarih}")
            writer.writeline(f"    - ℹ️ Siz de [linkten]({DERS_YORUMLAMA_LINKI}) anonim şekilde görüşlerinizi belirtebilirsiniz.")
    
    def _write_yildizlar(
        self, writer: "BufferedReadmeWriter",
        kolaylik: float, gereklilik: float,
        girinti: str, oy_sayisi: int, yil_prefix: str = ""
    ) -> None:
        """Ders yıldızlarını yaz."""
        writer.writeline(f"{girinti}- ✅ {yil_prefix}Dersi Kolay Geçer Miyim: {puanlari_yildiza_cevir(kolaylik)}")
        writer.writeline(f"{girinti}- 🎯 {yil_prefix}Ders Mesleki Açıdan Gerekli Mi: {puanlari_yildiza_cevir(gereklilik)}")
        writer.writeline(f"{girinti}  - ℹ️ Yıldızlar {oy_sayisi} oy üzerinden hesaplanmıştır. Siz de [linkten]({DERS_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.")
    
    def _write_yildiz_bolumu(self, writer: "BufferedReadmeWriter", ders: dict) -> None:
        """Yıldız bölümünü yaz."""
        writer.writeline("- ⭐ **Yıldız Sayıları:**")
        
        if OY_SAYISI in ders:
            kolaylik = ders.get(KOLAYLIK_PUANI, 1)
            gereklilik = ders.get(GEREKLILIK_PUANI, 1)
            self._write_yildizlar(writer, kolaylik, gereklilik, "  ", ders.get(OY_SAYISI, 0))
        else:
            writer.writeline(f"    - ℹ️ Henüz yıldız veren yok. Siz de [linkten]({DERS_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.")
            return
        
        # Yıllara göre yıldızlar
        if YILLARA_GORE_YILDIZ_SAYILARI in ders:
            acilis, kapanis = detay_etiketleri_olustur("📅 Yıllara Göre Yıldız Sayıları", "  ")
            writer.write(acilis)
            
            for yildiz_bilgileri in ders[YILLARA_GORE_YILDIZ_SAYILARI]:
                yil = yildiz_bilgileri.get(YIL, "bilinmiyor")
                writer.writeline(f"    - 📅 *{yil} yılı için yıldız bilgileri*")
                self._write_yildizlar(
                    writer,
                    yildiz_bilgileri.get(KOLAYLIK_PUANI, 0),
                    yildiz_bilgileri.get(GEREKLILIK_PUANI, 0),
                    "      ",
                    yildiz_bilgileri.get(OY_SAYISI, 0),
                    f"{yil} Yılında "
                )
            
            writer.write(kapanis)
    
    def write_donem_readme(self, writer: "BufferedReadmeWriter", donem: dict) -> None:
        """
        Dönem README'sini yaz.
        
        Args:
            writer: BufferedReadmeWriter instance
            donem: Dönem dict'i
        """
        donem_adi = donem.get(DONEM_ADI, "")
        
        writer.writeline(f"# 📅 {donem_adi}\n")
        writer.writeline("## 📝 Genel Tavsiyeler\n")
        
        for tavsiye in donem.get("genel_tavsiyeler", []):
            writer.writeline(f"- 💡 {tavsiye}")
        
        if donem.get(YIL, 0) != 0:
            writer.writeline("## 📚 Dönemin Zorunlu Dersleri\n")
    
    def write_ders_to_donem(
        self, writer: "BufferedReadmeWriter", ders: dict,
        guncel_olmayan_ders_aciklamasi: str, donem_klasoru: str = None,
        ders_klasoru: str = None
    ) -> None:
        """
        Dersi dönem README'sine yaz.

        Args:
            writer: BufferedReadmeWriter instance
            ders: Ders dict'i
            guncel_olmayan_ders_aciklamasi: Güncel olmayan ders açıklaması
            donem_klasoru: Dönem README'sinin bulunduğu klasör (link göreceliliği için)
            ders_klasoru: Dersin gerçekte bulunduğu klasör. Ders klasörüne göreceli
                linkleri (örn ./ders_kayitlari/) dönem klasörüne göre yeniden yazmak
                için kullanılır.
        """
        ders_adi = ders.get(AD, "")
        
        writer.writeline(f"\n### 📘 {ders_adi}\n")
        writer.writeline("#### 📄 Ders Bilgileri\n")
        writer.writeline(f"- 📅 **Yıl:** {ders.get(YIL, '')}")
        writer.writeline(f"- 📆 **Dönem:** {ders.get(DONEM, '')}")
        writer.writeline(f"- 🏫 **Ders Tipi:** {ders.get(TIP, '')}")
        
        self._write_ogrenci_gorusu(writer, ders.get(OGRENCI_GORUSLERI, []))
        self._write_yildiz_bolumu(writer, ders)
        
        # Derse dair öneriler
        if DERSE_DAIR_ONERILER in ders:
            writer.writeline("#### 💡 Derse Dair Öneriler\n")
            for oneriler in ders[DERSE_DAIR_ONERILER]:
                if len(oneriler.get(ONERILER, [])) > 0:
                    writer.writeline(f"##### 📌 Öneri sahibi: {oneriler.get(ONERI_SAHIBI, '')}")
                    for oneri in oneriler[ONERILER]:
                        oneri = kaynak_linklerini_goreceli_yap(oneri, donem_klasoru, ders_klasoru)
                        writer.writeline(f"- {oneri}")
        
        # Faydalı kaynaklar
        writer.writeline("\n#### 📚 Faydalı Olabilecek Kaynaklar\n")
        
        if FAYDALI_OLABILECEK_KAYNAKLAR in ders:
            sirali_kaynaklar = sorted(
                ders[FAYDALI_OLABILECEK_KAYNAKLAR],
                key=lambda x: unicodedata.normalize(NFKD, x).lower()
            )
            for kaynak in sirali_kaynaklar:
                kaynak = kaynak_linklerini_goreceli_yap(kaynak, donem_klasoru, ders_klasoru)
                writer.writeline(f"- 📄 {kaynak} ✨")
        
        writer.write(GENEL_CIKMIS_SORULAR_METNI)
        writer.writeline(f"  - ℹ️ {FAYDALI_OLABILECEK_KAYNAKLAR_UYARI_MESAJI}")
        
        # Dersi veren hocalar
        dersi_veren_hocalar = ders.get(DERSI_VEREN_HOCALAR, [])
        if dersi_veren_hocalar:
            writer.writeline("\n#### 👨‍🏫 👩‍🏫 Dersi Yürüten Akademisyenler:")
            for hoca in dersi_veren_hocalar:
                writer.writeline(f"- {hoca.get(KISALTMA, '')}")
        
        # Güncel değil uyarısı
        if not ders.get(GUNCEL_MI, True):
            writer.writeline("\n#### ℹ️ Dersin içeriği güncel değil")
            writer.writeline(f"- {guncel_olmayan_ders_aciklamasi}")
    
    def write(self, writer: "BufferedReadmeWriter", data: dict) -> None:
        """Bu metod dönemler için farklı çalışır - doğrudan dosyaya yazar."""
        pass
