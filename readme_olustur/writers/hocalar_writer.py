"""Hocalar bölümü yazıcısı."""
from writers.base import SectionWriter
from writers.yardimci import (
    puanlari_yildiza_cevir, baslik_linki_olustur,
    gorustenTarihGetir, detay_etiketleri_olustur,
    hoca_siralama_anahtari
)
from typing import TYPE_CHECKING, Optional

import sys
import os
current_directory = os.path.dirname(os.path.abspath(__file__))
parent_directory = os.path.dirname(current_directory)
python_ui_path = os.path.join(parent_directory, "readme_guncelleme_arayuzu_python")
sys.path.insert(0, python_ui_path)

from degiskenler import (
    HOCALAR, AD, OFIS, LINK, ERKEK_MI, DERSLER, OY_SAYISI,
    BOLUM_ADI, BOLUM_ACIKLAMASI, EN_POPULER_HOCA, HOCA_ADI,
    OGRENCI_GORUSLERI, KISI, YORUM, HOCA_YORULMALA_LINKI, HOCA_OYLAMA_LINKI,
    HOCA_AKTIF_GOREVDE_MI, VARSAYILAN_HOCA_AKTIF_GOREVDE_DEGIL_MESAJI,
    ANLATIM_PUANI, KOLAYLIK_PUANI, OGRETME_PUNAI, EGLENCE_PUANI,
    YILLARA_GORE_YILDIZ_SAYILARI, YIL, PROF_DR, DOC_DR, DR, ARS_GRV
)

if TYPE_CHECKING:
    from buffered_writer import BufferedReadmeWriter

UNVANLAR = [PROF_DR, DOC_DR, DR, ARS_GRV]


class HocalarWriter(SectionWriter):
    """Hocalar bölümü yazıcısı."""
    
    def __init__(self, dersler_data: Optional[dict] = None):
        """
        Args:
            dersler_data: Ders verileri (popüler ders işaretlemesi için)
        """
        self.dersler_data = dersler_data or {}
    
    @property
    def section_name(self) -> str:
        return "Hocalar"
    
    def _write_ogrenci_gorusu(self, writer: "BufferedReadmeWriter", gorusler: list, girinti: str = "") -> None:
        """Öğrenci görüşlerini yaz."""
        for gorus in gorusler:
            kisi = gorus.get(KISI, "").strip()
            yorum = gorus.get(YORUM, "")
            tarih = gorustenTarihGetir(gorus)
            writer.writeline(f"{girinti}  - 👤 **_{kisi}_**: {yorum} {tarih}")
        writer.writeline(f"{girinti}  - ℹ️ Siz de [linkten]({HOCA_YORULMALA_LINKI}) anonim şekilde görüşlerinizi belirtebilirsiniz.")
    
    def _write_yildizlar(
        self, writer: "BufferedReadmeWriter", 
        anlatim: float, kolaylik: float, ogretme: float, eglence: float,
        girinti: str, oy_sayisi: int, yil_prefix: str = ""
    ) -> None:
        """Hoca yıldızlarını yaz."""
        writer.writeline(f"{girinti}  - {yil_prefix}🎭 Dersi Zevkli Anlatır Mı:\t{puanlari_yildiza_cevir(anlatim)}")
        writer.writeline(f"{girinti}  - {yil_prefix}🛣️ Dersi Kolay Geçer Miyim:\t{puanlari_yildiza_cevir(kolaylik)}")
        writer.writeline(f"{girinti}  - {yil_prefix}🧠 Dersi Öğrenir Miyim:\t{puanlari_yildiza_cevir(ogretme)}")
        writer.writeline(f"{girinti}  - {yil_prefix}🎉 Derste Eğlenir Miyim:\t{puanlari_yildiza_cevir(eglence)}")
        writer.writeline(f"{girinti}    - ℹ️ Yıldızlar {oy_sayisi} oy üzerinden hesaplanmıştır. Siz de [linkten]({HOCA_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.")
    
    def _write_yildiz_bolumu(self, writer: "BufferedReadmeWriter", hoca: dict, girinti: str = "") -> None:
        """Yıldız bölümünü yaz."""
        writer.writeline(f"{girinti}- ⭐ **Yıldız Sayıları:**")
        
        oy_sayisi = hoca.get(OY_SAYISI)
        if oy_sayisi and isinstance(oy_sayisi, int) and oy_sayisi > 0:
            self._write_yildizlar(
                writer,
                hoca.get(ANLATIM_PUANI, 0),
                hoca.get(KOLAYLIK_PUANI, 0),
                hoca.get(OGRETME_PUNAI, 0),
                hoca.get(EGLENCE_PUANI, 0),
                girinti,
                oy_sayisi
            )
        else:
            writer.writeline(f"{girinti}    - ℹ️ Henüz yıldız veren yok. Siz de [linkten]({HOCA_OYLAMA_LINKI}) anonim şekilde oylamaya katılabilirsiniz.")
            return
        
        # Yıllara göre yıldızlar
        ek_girinti = "  "
        yeni_girinti = girinti + ek_girinti
        
        if hoca.get(YILLARA_GORE_YILDIZ_SAYILARI):
            acilis, kapanis = detay_etiketleri_olustur("📅 Yıllara Göre Yıldız Sayıları", yeni_girinti)
            writer.write(acilis)
            
            for yildiz_bilgileri in hoca[YILLARA_GORE_YILDIZ_SAYILARI]:
                yil = yildiz_bilgileri.get(YIL, "bilinmiyor")
                writer.writeline(f"{yeni_girinti + ek_girinti}- 📅 *{yil} yılı için yıldız bilgileri*")
                self._write_yildizlar(
                    writer,
                    yildiz_bilgileri.get(ANLATIM_PUANI, 0),
                    yildiz_bilgileri.get(KOLAYLIK_PUANI, 0),
                    yildiz_bilgileri.get(OGRETME_PUNAI, 0),
                    yildiz_bilgileri.get(EGLENCE_PUANI, 0),
                    yeni_girinti + ek_girinti,
                    yildiz_bilgileri.get(OY_SAYISI, 0),
                    f"{yil} Yılında "
                )
            
            writer.write(kapanis)
    
    def write(self, writer: "BufferedReadmeWriter", data: dict) -> None:
        """
        Hocalar bölümünü yaz.
        
        Args:
            writer: BufferedReadmeWriter instance
            data: Hoca bilgileri dict'i
        """
        if data is None:
            return
        
        hocalar = data.get(HOCALAR, [])
        hocalar = [h for h in hocalar if h.get(AD, "")]
        
        if not hocalar:
            return
        
        # Bölüm başlığı
        bolum_adi = data.get(BOLUM_ADI, "Hocalar")
        bolum_aciklamasi = data.get(BOLUM_ACIKLAMASI, "")
        
        writer.writeline(f"<details>")
        writer.writeline(f"<summary><b>🎓 {bolum_adi}</b></summary>\n")
        writer.writeline(f"\n\n\n## 🎓 {bolum_adi}")
        
        if bolum_aciklamasi:
            writer.writeline(f"📚 {bolum_aciklamasi}\n\n\n")
        
        # En popüler hoca bilgisi
        en_populer_hoca = data.get(EN_POPULER_HOCA, {})
        en_populer_hoca_adi = en_populer_hoca.get(HOCA_ADI, "")
        en_populer_hoca_oy = en_populer_hoca.get(OY_SAYISI, 1)
        
        # Popüler ders bilgisi (dersler_data'dan)
        from degiskenler import EN_POPULER_DERS, DERS_ADI
        en_populer_ders = self.dersler_data.get(EN_POPULER_DERS, {})
        en_populer_ders_adi = en_populer_ders.get(DERS_ADI, "")
        en_populer_ders_oy = en_populer_ders.get(OY_SAYISI, 0)
        
        unvan_sayaci = 0
        baslik_str = "\n### {}\n"
        
        for hoca in sorted(hocalar, key=hoca_siralama_anahtari):
            hoca_adi = hoca.get(AD, "")
            
            # Unvan başlığı
            if unvan_sayaci < len(UNVANLAR) and hoca_adi.startswith(UNVANLAR[unvan_sayaci]):
                unvan_basliklari = ["Profesörler", "Doçentler", "Doktor Öğretim Üyeleri", "Araştırma Görevlileri"]
                if unvan_sayaci < len(unvan_basliklari):
                    writer.write(baslik_str.format(unvan_basliklari[unvan_sayaci]))
                unvan_sayaci += 1
            elif unvan_sayaci == len(UNVANLAR) and not hoca.get(HOCA_AKTIF_GOREVDE_MI, True):
                unvan_sayaci += 1
                writer.write(baslik_str.format("Üniversitede Aktif Görevde Olmayan Hocalar"))
            
            # Hoca bilgileri
            hoca_emoji = "👨‍🏫" if hoca.get(ERKEK_MI, True) else "👩‍🏫"
            populer_isaret = "👑" if hoca_adi == en_populer_hoca_adi else ""
            populer_bilgi = f" En popüler hoca ({en_populer_hoca_oy} oy)" if hoca_adi == en_populer_hoca_adi else ""
            
            writer.writeline(f"\n\n\n#### {hoca_emoji} {hoca_adi.strip()} {populer_isaret}{populer_bilgi}")
            writer.writeline(f"- 🚪 **Ofis:** {hoca.get(OFIS, '')}")
            writer.writeline(f"- 🔗 **Araştırma Sayfası:** [{hoca.get(LINK, '')}]({hoca.get(LINK, '')})")
            writer.writeline(f"- 💬 **Öğrenci Görüşleri:**")
            
            self._write_ogrenci_gorusu(writer, hoca.get(OGRENCI_GORUSLERI, []))
            
            # Verdiği dersler
            writer.writeline("- 📚 **Verdiği Dersler:**")
            hoca_dersleri = hoca.get(DERSLER, [])
            
            if hoca_dersleri:
                for ders in hoca_dersleri:
                    if ders != en_populer_ders_adi:
                        writer.writeline(f"  - 📖 [{ders}]{baslik_linki_olustur(ders)}")
                    else:
                        p_isaret = "👑"
                        p_bilgi = f" En popüler ders ({en_populer_ders_oy} oy)"
                        ders_id = f"{ders} {p_isaret}{p_bilgi}"
                        writer.writeline(f"  - 📖 [{ders}]{baslik_linki_olustur(ders_id)}")
            else:
                writer.writeline("  - 📖 Ders bilgileri bulunamadı.")
            
            self._write_yildiz_bolumu(writer, hoca)
            
            if not hoca.get(HOCA_AKTIF_GOREVDE_MI, True):
                writer.writeline(f"- ℹ️ {VARSAYILAN_HOCA_AKTIF_GOREVDE_DEGIL_MESAJI}.")
        
        writer.writeline("</details>\n")
