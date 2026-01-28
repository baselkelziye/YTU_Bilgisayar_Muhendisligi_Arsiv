"""Katkıda bulunanlar bölümü yazıcısı."""
from writers.base import SectionWriter
from typing import TYPE_CHECKING

import sys
import os
current_directory = os.path.dirname(os.path.abspath(__file__))
parent_directory = os.path.dirname(current_directory)
python_ui_path = os.path.join(parent_directory, "readme_guncelleme_arayuzu_python")
sys.path.insert(0, python_ui_path)

from degiskenler import (
    KATKIDA_BULUNANLAR, BOLUM_ACIKLAMASI, AD, LINK, BASLIK,
    ILETISIM_BILGILERI, KATKIDA_BULUNMA_ORANI, KATKIDA_BULUNMA_ORANI_DIZI
)

if TYPE_CHECKING:
    from buffered_writer import BufferedReadmeWriter


# Katkı oranlarına göre emojiler
KATKIDA_EMOJILER = ["👑", "🌟", "💫", "✨", "🔹", ""]


class KatkidaBulunanlarWriter(SectionWriter):
    """Katkıda bulunanlar bölümü yazıcısı."""
    
    @property
    def section_name(self) -> str:
        return "Katkıda Bulunanlar"
    
    def write(self, writer: "BufferedReadmeWriter", data: dict) -> None:
        """
        Katkıda bulunanlar bölümünü yaz.
        
        Args:
            writer: BufferedReadmeWriter instance
            data: Katkıda bulunanlar dict'i
        """
        if data is None:
            return
        
        bolum_adi = data.get("bolum_adi", "Katkıda Bulunanlar")
        
        # Katkıda bulunanları sırala
        katkida_bulunanlar = sorted(
            data.get(KATKIDA_BULUNANLAR, []),
            key=lambda x: (
                KATKIDA_BULUNMA_ORANI_DIZI.index(
                    x.get(KATKIDA_BULUNMA_ORANI, KATKIDA_BULUNMA_ORANI_DIZI[-1])
                ),
                x.get("ad", "")
            )
        )
        
        writer.writeline(f"<details>")
        writer.writeline(f"<summary><b>🤝 {bolum_adi}</b></summary>\n")
        writer.writeline(f"<h2 align='center'>🤝 {bolum_adi}</h2>\n")
        
        bolum_aciklamasi = data.get(BOLUM_ACIKLAMASI, "")
        if bolum_aciklamasi:
            writer.writeline(f"{bolum_aciklamasi}\n")
        
        for katkida_bulunan in katkida_bulunanlar:
            oran = katkida_bulunan.get(KATKIDA_BULUNMA_ORANI, KATKIDA_BULUNMA_ORANI_DIZI[-1])
            oran_index = KATKIDA_BULUNMA_ORANI_DIZI.index(oran) if oran in KATKIDA_BULUNMA_ORANI_DIZI else len(KATKIDA_BULUNMA_ORANI_DIZI) - 1
            emoji = KATKIDA_EMOJILER[min(oran_index, len(KATKIDA_EMOJILER) - 1)]
            
            # Başlık seviyesi
            header_size = min(oran_index + 1, 6)
            header_tag = f"h{header_size}"
            
            ad = katkida_bulunan.get(AD, "")
            writer.writeline(f"<{header_tag} align='center'>{emoji} <b><i>{ad}</i></b> {emoji}</{header_tag}>")
            
            # İletişim bilgileri
            iletisim_bilgileri = katkida_bulunan.get(ILETISIM_BILGILERI, [])
            if iletisim_bilgileri:
                iletisim_html = " &nbsp".join([
                    f"<a href='{bilgi.get(LINK, '')}'><b>{bilgi.get(BASLIK, '')}</b></a>"
                    for bilgi in iletisim_bilgileri
                ])
                writer.writeline(f"<p align='center'>{iletisim_html}</p>")
            
            writer.writeline("")
        
        writer.writeline("</details>\n")
