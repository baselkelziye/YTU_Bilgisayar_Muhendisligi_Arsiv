"""Repo kullanımı bölümü yazıcısı."""
from writers.base import SectionWriter
from typing import TYPE_CHECKING
import unicodedata

import sys
import os
current_directory = os.path.dirname(os.path.abspath(__file__))
parent_directory = os.path.dirname(current_directory)
python_ui_path = os.path.join(parent_directory, "readme_guncelleme_arayuzu_python")
sys.path.insert(0, python_ui_path)

from degiskenler import (
    BASLIK, ACIKLAMA, ACIKLAMALAR, TALIMAT, TALIMATLAR,
    KAVRAM, KAVRAMLAR, NFKD
)

if TYPE_CHECKING:
    from buffered_writer import BufferedReadmeWriter


class RepoKullanimiWriter(SectionWriter):
    """Repo kullanımı bölümü yazıcısı."""
    
    @property
    def section_name(self) -> str:
        return "Repo Kullanımı"
    
    def write(self, writer: "BufferedReadmeWriter", data: dict) -> None:
        """
        Repo kullanımı bölümünü yaz.
        
        Args:
            writer: BufferedReadmeWriter instance
            data: Repo kullanımı bilgileri dict'i
        """
        if data is None:
            return
        
        baslik = data.get(BASLIK, "Repo Kullanımı")
        
        # Ana bölüm
        writer.writeline(f"<details>")
        writer.writeline(f"<summary><b>🛠 {baslik}</b></summary>\n")
        writer.writeline(f"\n\n\n## 🛠 {baslik}\n")
        
        # Açıklamalar
        writer.writeline(f"### ⚙️ {data.get(ACIKLAMA, '')}:")
        for aciklama in data.get(ACIKLAMALAR, []):
            writer.writeline(f"- 📋 {aciklama}")
        
        # Talimatlar
        writer.writeline(f"\n\n### 📝 {data.get(TALIMAT, '')}:")
        for talimat in data.get(TALIMATLAR, []):
            writer.writeline(f"- 👉 {talimat}")
        
        writer.writeline("</details>\n")
        
        # Kavramlar bölümü
        kavram_baslik = data.get(KAVRAM, "Kavramlar")
        kavramlar = data.get(KAVRAMLAR, [])
        
        if kavramlar:
            writer.writeline(f"<details>")
            writer.writeline(f"<summary><b>🔍 {kavram_baslik}</b></summary>\n")
            writer.writeline(f"\n\n## 🔍 {kavram_baslik}")
            
            # Kavramları alfabetik sırala
            sirali_kavramlar = sorted(
                kavramlar,
                key=lambda x: unicodedata.normalize(NFKD, x.get(KAVRAM, "").lower())
            )
            
            for kavram in sirali_kavramlar:
                writer.writeline(f"- 💡 **{kavram.get(KAVRAM, '')}**")
                for aciklama in kavram.get(ACIKLAMALAR, []):
                    writer.writeline(f"  - 📘 {aciklama}")
            
            writer.writeline("</details>\n")
