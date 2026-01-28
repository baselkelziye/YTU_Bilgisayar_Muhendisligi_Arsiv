"""Ders klasörü README yazıcısı."""
from writers.base import SectionWriter
from writers.yardimci import (
    puanlari_yildiza_cevir, gorustenTarihGetir, detay_etiketleri_olustur
)
from typing import TYPE_CHECKING
import unicodedata

import sys
import os
current_directory = os.path.dirname(os.path.abspath(__file__))
parent_directory = os.path.dirname(current_directory)
python_ui_path = os.path.join(parent_directory, "readme_guncelleme_arayuzu_python")
sys.path.insert(0, python_ui_path)

from degiskenler import (
    AD, YIL, DONEM, TIP, OY_SAYISI,
    OGRENCI_GORUSLERI, KISI, YORUM, DERS_YORUMLAMA_LINKI, DERS_OYLAMA_LINKI,
    KOLAYLIK_PUANI, GEREKLILIK_PUANI, YILLARA_GORE_YILDIZ_SAYILARI,
    GUNCEL_MI, DERSE_DAIR_ONERILER, ONERILER, ONERI_SAHIBI,
    FAYDALI_OLABILECEK_KAYNAKLAR, DERSI_VEREN_HOCALAR, KISALTMA,
    GENEL_CIKMIS_SORULAR_METNI, FAYDALI_OLABILECEK_KAYNAKLAR_UYARI_MESAJI,
    MESLEKI_SECMELI, NFKD
)

if TYPE_CHECKING:
    from buffered_writer import BufferedReadmeWriter


class DersKlasorWriter(SectionWriter):
    """Ders klasörü README yazıcısı."""
    
    def __init__(self, dersler_data: dict):
        """
        Args:
            dersler_data: Ders verileri dict'i
        """
        self.dersler_data = dersler_data
    
    @property
    def section_name(self) -> str:
        return "Ders Klasör README"
    
    def _write_ogrenci_gorusu(self, writer: "BufferedReadmeWriter", ders: dict) -> None:
        """Öğrenci görüşlerini yaz - sadece görüş varsa."""
        gorusler = ders.get(OGRENCI_GORUSLERI, [])
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
    
    def write_ders_readme(
        self, writer: "BufferedReadmeWriter", ders: dict,
        klasor_sonradan_olustu: bool = False
    ) -> None:
        """
        Ders klasörü README'sini yaz.
        
        Args:
            writer: BufferedReadmeWriter instance
            ders: Ders dict'i
            klasor_sonradan_olustu: Klasör sonradan mı oluştu
        """
        ders_adi = ders.get(AD, "")
        
        # Ders başlığı
        writer.writeline(f"# 📚 {ders_adi}\n")
        
        # Ders bilgileri
        writer.writeline("## ℹ️ Ders Bilgileri\n")
        
        if ders.get(TIP, MESLEKI_SECMELI) != MESLEKI_SECMELI:
            writer.writeline(f"- 📅 **Yıl:** {ders.get(YIL, '')}")
            writer.writeline(f"- 📆 **Dönem:** {ders.get(DONEM, '')}")
        
        writer.writeline(f"- 🏫 **Ders Tipi:** {ders.get(TIP, '')}")
        
        self._write_ogrenci_gorusu(writer, ders)
        self._write_yildiz_bolumu(writer, ders)
        
        # Derse dair öneriler
        if DERSE_DAIR_ONERILER in ders:
            writer.writeline("## 📝 Derse Dair Öneriler\n")
            for oneriler in ders[DERSE_DAIR_ONERILER]:
                if len(oneriler.get(ONERILER, [])) > 0:
                    writer.writeline(f"### 💡 Öneri sahibi: {oneriler.get(ONERI_SAHIBI, '')}")
                    for oneri in oneriler[ONERILER]:
                        writer.writeline(f"- {oneri}")
        
        # Faydalı kaynaklar
        writer.writeline("\n## 📖 Faydalı Olabilecek Kaynaklar\n")
        
        if FAYDALI_OLABILECEK_KAYNAKLAR in ders:
            sirali_kaynaklar = sorted(
                ders[FAYDALI_OLABILECEK_KAYNAKLAR],
                key=lambda x: unicodedata.normalize(NFKD, x).lower()
            )
            for kaynak in sirali_kaynaklar:
                writer.writeline(f"- 📄 {kaynak} ✨")
        
        writer.write(GENEL_CIKMIS_SORULAR_METNI)
        writer.writeline(f"  - ℹ️ {FAYDALI_OLABILECEK_KAYNAKLAR_UYARI_MESAJI}")
        
        # Dersi veren hocalar
        dersi_veren_hocalar = ders.get(DERSI_VEREN_HOCALAR, [])
        if dersi_veren_hocalar:
            writer.writeline("\n## 👨‍🏫 👩‍🏫 Dersi Yürüten Akademisyenler:")
            for hoca in dersi_veren_hocalar:
                writer.writeline(f"- {hoca.get(KISALTMA, '')}")
        
        # Klasör sonradan oluştu uyarısı
        if klasor_sonradan_olustu:
            writer.writeline("\n## 😔 İçerik yok")
            ders_klasoru_mesaj = self.dersler_data.get("ders_klasoru_bulunamadi_mesaji", "")
            writer.writeline(f"- {ders_klasoru_mesaj}")
        
        # Güncel değil uyarısı
        if not ders.get(GUNCEL_MI, True):
            writer.writeline("\n## ℹ️ Dersin içeriği güncel değil")
            guncel_olmayan_aciklama = self.dersler_data.get("guncel_olmayan_ders_aciklamasi", "")
            writer.writeline(f"- {guncel_olmayan_aciklama}")
    
    def write(self, writer: "BufferedReadmeWriter", data: dict) -> None:
        """Bu metod ders klasörleri için farklı çalışır - ayrı dosyalara yazar."""
        pass
