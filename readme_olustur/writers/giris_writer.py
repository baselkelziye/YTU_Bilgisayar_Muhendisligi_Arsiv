"""Giriş bölümü yazıcısı."""
from writers.base import SectionWriter
from typing import TYPE_CHECKING

import sys
import os
current_directory = os.path.dirname(os.path.abspath(__file__))
parent_directory = os.path.dirname(current_directory)
python_ui_path = os.path.join(parent_directory, "readme_guncelleme_arayuzu_python")
sys.path.insert(0, python_ui_path)

from degiskenler import (
    HOCA_YORULMALA_LINKI, HOCA_OYLAMA_LINKI, 
    DERS_YORUMLAMA_LINKI, DERS_OYLAMA_LINKI,
    TIKLANMA_SAYISI
)

if TYPE_CHECKING:
    from buffered_writer import BufferedReadmeWriter


GERI_BILDIRIM_KISMI = f""" ## 🗣️ Geri Bildirimde Bulunun

📬 Öğrenciler ve hocalar, derslerle ilgili hakaret içermeyen geri bildirimlerinizi aşağıdaki linkler aracılığıyla anonim olarak paylaşabilirsiniz.

- [✍️ **Hocalar için yorum linki**]({HOCA_YORULMALA_LINKI})
- [⭐ **Hocalar için yıldız linki**]({HOCA_OYLAMA_LINKI})
- [✍️ **Dersler için yorum linki**]({DERS_YORUMLAMA_LINKI})
- [⭐ **Dersler için yıldız linki**]({DERS_OYLAMA_LINKI})
"""


class GirisWriter(SectionWriter):
    """Giriş bölümü yazıcısı."""
    
    @property
    def section_name(self) -> str:
        return "Giriş"
    
    def write(self, writer: "BufferedReadmeWriter", data: dict) -> None:
        """
        Giriş bölümünü yaz.
        
        Args:
            writer: BufferedReadmeWriter instance
            data: Giriş bilgileri dict'i
        """
        if data is None:
            return
        
        # Başlık
        writer.writeline(f"# 📖 {data.get('baslik', '')}\n")
        
        # Açıklama
        writer.writeline(f"{data.get('aciklama', '')}\n")
        
        # Geri bildirim kısmı
        writer.write(GERI_BILDIRIM_KISMI)
        
        # Tıklanma sayısı
        writer.write(TIKLANMA_SAYISI)
        
        # İçindekiler
        writer.writeline("<details>")
        writer.writeline("<summary><b>🗂 İçindekiler</b></summary>\n")
        writer.writeline("## 🗂 İçindekiler\n")
        
        for item in data.get("icindekiler", []):
            writer.writeline(f"- 🔗 {item}")
        
        writer.writeline("</details>\n")
