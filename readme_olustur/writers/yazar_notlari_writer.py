"""Yazar notları bölümü yazıcısı."""
from writers.base import SectionWriter
from typing import TYPE_CHECKING

import sys
import os
current_directory = os.path.dirname(os.path.abspath(__file__))
parent_directory = os.path.dirname(current_directory)
python_ui_path = os.path.join(parent_directory, "readme_guncelleme_arayuzu_python")
sys.path.insert(0, python_ui_path)

from degiskenler import ACIKLAMALAR

if TYPE_CHECKING:
    from buffered_writer import BufferedReadmeWriter


class YazarNotlariWriter(SectionWriter):
    """Yazar notları bölümü yazıcısı."""
    
    @property
    def section_name(self) -> str:
        return "Yazar Notları"
    
    def write(self, writer: "BufferedReadmeWriter", data: dict) -> None:
        """
        Yazar notları bölümünü yaz.
        
        Args:
            writer: BufferedReadmeWriter instance
            data: Yazar notları dict'i
        """
        if data is None:
            return
        
        baslik = data.get("baslik", "Yazar Notları")
        
        writer.writeline(f"<details>")
        writer.writeline(f"<summary><b>🖋 {baslik}</b></summary>\n")
        writer.writeline(f"\n## 🖋 {baslik}\n")
        
        for aciklama in data.get(ACIKLAMALAR, []):
            writer.writeline(f"- 📝 {aciklama}")
        
        writer.writeline("</details>\n")
