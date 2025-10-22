import argparse
import csv
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Dict, Iterable, List, Optional
from collections import defaultdict

"""
Bu modül, CSV içeriğini yıllara göre klasörlenmiş Markdown dosyalarına dönüştürür.

SOLID prensiplerine uygun bir mimari ile aşağıdaki bileşenlere ayrılmıştır:
- CSVInterviewSource: CSV'den satırları okur ve tekrar eden başlıkları yönetir. (SRP)
- YearExtractor: Tarihten yılı çıkarmayı kapsüller. (SRP)
- FilenameSanitizer: Güvenli dosya adı oluşturur. (SRP)
- OutputPathBuilder: Çıktı yolunu (yıl klasörleri + dosya adı) üretir. (OCP)
- MarkdownGenerator: Bir satırdan Markdown içerik üretir. (SRP, OCP)
- FileWriter: İçeriği dosyaya yazar. (SRP)
- CSVToMarkdownConverter: Bileşenleri enjekte ederek orkestrasyon yapar. (DIP)
"""


# ---------------------------- Veri Kaynağı ---------------------------- #
class CSVInterviewSource:
    """CSV'den satırları sözlük olarak okur ve tekrarlayan başlıkları _n ile isimlendirir."""

    def __init__(self, csv_path: Path) -> None:
        self.csv_path = csv_path

    def exists(self) -> bool:
        return self.csv_path.exists()

    def rows(self) -> Iterable[Dict[str, str]]:
        with self.csv_path.open('r', encoding='utf-8') as file:
            reader = csv.reader(file)
            headers = next(reader)

            # Tekrarlanan sütunları yönet
            header_counts: Dict[str, int] = defaultdict(int)
            new_headers: List[str] = []
            for header in headers:
                count = header_counts[header]
                new_headers.append(header if count == 0 else f"{header}_{count}")
                header_counts[header] += 1

            for row_data in reader:
                # Satır uzunluğu başlıklardan kısa/uzun ise zip otomatik kırpar
                yield dict(zip(new_headers, row_data))


# ---------------------------- Yardımcılar ---------------------------- #
class YearExtractor:
    """Tarih stringinden yıl çıkarımı yapar."""

    SUPPORTED_FORMATS = ('%d.%m.%Y', '%m.%Y', '%Y')

    @staticmethod
    def extract(year_like: str) -> Optional[int]:
        if not year_like:
            return None

        try:
            for fmt in YearExtractor.SUPPORTED_FORMATS:
                try:
                    return datetime.strptime(year_like, fmt).year
                except ValueError:
                    continue

            if year_like.isdigit() and len(year_like) == 4:
                return int(year_like)
        except Exception:
            pass
        return None


class FilenameSanitizer:
    """Dosya adlarını güvenli hale getirir."""

    @staticmethod
    def sanitize(name: str) -> str:
        if not name:
            return 'bilinmeyen'
        safe = name.strip().replace(' ', '_')
        # Dosya sistemi için uygunsuz karakterleri temizle
        for ch in ['/', '\\', ':', '*', '?', '"', '<', '>', '|']:
            safe = safe.replace(ch, '_')
        return safe or 'bilinmeyen'


class OutputPathBuilder:
    """Satıra göre çıktı dizin ve dosya yolunu üretir (yıla göre klasörleme)."""

    def __init__(self, base_dir: Path) -> None:
        self.base_dir = base_dir
        self.base_dir.mkdir(parents=True, exist_ok=True)
        # Her yıl klasörü için şirket bazında sayaç tut
        self.company_counters: Dict[str, Dict[str, int]] = defaultdict(lambda: defaultdict(int))

    def build(self, row: Dict[str, str], index: int) -> Path:
        mulakat_tarihi = (row.get('Mülakat Tarihi') or '').strip()
        year = YearExtractor.extract(mulakat_tarihi)
        year_folder = str(year) if year else 'Tarihsiz'

        company = FilenameSanitizer.sanitize(row.get('Mülakatı Yapan Şirket Adı', 'bilinmeyen'))
        
        # Bu yıl klasöründeki bu şirket için sayacı artır
        self.company_counters[year_folder][company] += 1
        count = self.company_counters[year_folder][company]
        
        # Eğer aynı şirketten birden fazla varsa sayı ekle
        if count == 1:
            filename = f"{company}.md"
        else:
            filename = f"{company}_{count}.md"

        target_dir = self.base_dir / year_folder
        target_dir.mkdir(parents=True, exist_ok=True)
        return target_dir / filename


# ---------------------------- Markdown Üretimi ---------------------------- #
class MarkdownGenerator:
    """Bir satırdan zengin Markdown içeriği üretir."""

    def __init__(self) -> None:
        # Kolay geçiş için alan adlarını sabit tutuyoruz
        self.info_fields = {
            'Şirket': 'Mülakatı Yapan Şirket Adı',
            'Şirket Konumu': 'Şirketin Merkez Konumu',
            'Mülakata Giren Kişi': 'Adınız - Soyadınız',
            'İş Türü': 'İş Türü',
            'Mülakat Tarihi': 'Mülakat Tarihi',
            'Mülakat Sürecinin Toplam Süresi': 'Toplam Mülakat Süreci Süresi',
            'Yapılan Mülakatların Toplam Süresi': 'Yapılan Mülakatların Toplam Süresi',
            'Mülakat Yeri': 'Mülakat Yeri',
            'Mülakatlar Bittikten Sonraki Dönüt Süresi': 'Mülakatlar Bittikten Sonraki Dönüt Süresi',
            'Mülakatçı': 'Mülakatı Yapan Kişi(ler)'
        }

        self.prep_fields = {
            'İş ilanına nasıl başvuruldu': 'İş ilanına nereden başvurdunuz?',
            'Başvurudan mülakata kadar geçen süre': 'Başvurudan ne kadar süre sonra mülakata çağırıldınız?',
            'Hazırlık için kullanılan kaynaklar': 'Mülakata hazırlık için neler yaptınız',
            'Hazırlık süresince üzerinde durulan konular': 'Hazırlık süresince hangi konular üzerinde çalıştınız?'
        }

    def _alt_mulakat_orders(self, row: Dict[str, str]) -> List[int]:
        """Satırdaki mevcut alt mülakat sıralarını (0, 1, 2, ...) bulur.

        0: suffix'siz ilk mülakat ("Alt Mülakat Tipi")
        n>=1: numaralı mülakatlar ("Alt Mülakat Tipi_n" veya "Alt Mülakat Tipi n")
        """
        base = 'Alt Mülakat Tipi'
        orders: List[int] = []
        # İlk (suffix'siz) var mı?
        if (row.get(base) or '').strip():
            orders.append(0)

        # Numaralı olanları tara (üst limit makul bir sayı; 10 yeterli)
        for i in range(1, 11):
            v_underscore = (row.get(f"{base}_{i}") or '').strip()
            v_space = (row.get(f"{base} {i}") or '').strip()
            if v_underscore or v_space:
                orders.append(i)

        return orders

    def _get_alt_value(self, row: Dict[str, str], base: str, order: int) -> str:
        """Alt mülakat alan değeri için uygun anahtarı sırayla dener ve döndürür."""
        candidates: List[str] = []
        if order == 0:
            candidates = [base]
        else:
            # Önce underscore, sonra space; bazı CSV'lerde ilk numara "1" yerine suffix'siz olabilir
            candidates = [f"{base}_{order}", f"{base} {order}"]
            if order == 1:
                candidates.append(base)

        for key in candidates:
            val = (row.get(key) or '').strip()
            if val:
                return val
        return ''

    def generate(self, row: Dict[str, str]) -> str:
        # Başlık
        company = row.get('Mülakatı Yapan Şirket Adı', 'Bilinmeyen Şirket')
        area = row.get('Mülakat Alanı', '')
        title = f"# {company} {area} Mülakat Süreci".strip()

        md: List[str] = [title, ""]

        # Mülakat Bilgileri
        md.append("## Mülakat Bilgileri")
        for label, key in self.info_fields.items():
            val = (row.get(key) or '').strip()
            if val:
                md.append(f"* {label}: {val}")
        md.append("")

        # Ön Hazırlık
        if any((row.get(k) or '').strip() for k in self.prep_fields.values()):
            md.append("## Ön Hazırlık")
            for label, key in self.prep_fields.items():
                val = (row.get(key) or '').strip()
                if val:
                    md.append(f"* {label}: {val}")
            md.append("")

        # Mülakat Süreci (Alt mülakatlar)
        alt_sayi = (row.get('Toplam Kaç Tane Alt Mülakata Girdiniz') or '').strip()
        orders = self._alt_mulakat_orders(row)
        if alt_sayi or orders:
            md.append("## Mülakat Süreci")
            md.append("")

            for idx, order in enumerate(orders, start=1):
                tip = self._get_alt_value(row, 'Alt Mülakat Tipi', order)
                if not tip:
                    continue

                sure = self._get_alt_value(row, 'Alt Mülakat Süresi', order)
                bicim = self._get_alt_value(row, 'Alt Mülakat Biçimi', order)
                kisi = self._get_alt_value(row, 'Alt Mülakatta Görüşülen Kişi Sayısı', order)
                yapan = self._get_alt_value(row, 'Mülakatı Yapan Kişi(ler)', order)
                sorular = self._get_alt_value(row, 'Alt Mülakat Sırasında Size Sorulan Sorular', order)

                md.append(f"### {idx}. {tip}")
                if sure:
                    md.append(f"* **Süre**: {sure}")
                if bicim:
                    md.append(f"* **Biçim**: {bicim}")
                if kisi:
                    md.append(f"* **Görüşülen kişi sayısı**: {kisi}")
                if yapan:
                    md.append(f"* **Mülakatı yapan**: {yapan}")
                if sorular:
                    md.append("")
                    md.append("#### Sorulan Sorular")
                    md.append(sorular)
                md.append("")

        # Genel değerlendirme
        md.append("## Genel Değerlendirme ve Öğrenilen Dersler")
        zorluk = (row.get('Mülakat Zorluk Derecesi') or '').strip()
        atmosfer = (row.get('Mülakat Atmosferi Nasıldı?') or '').strip()
        tavsiye = (row.get('Benzer şirkette benzer mülakata gireceklere ne tavsiye edersin? ') or '').strip()
        if zorluk:
            md.append(f"* **Mülakat Zorluk Derecesi**: {zorluk}")
        if atmosfer:
            md.append(f"* **Mülakat Atmosferi**: {atmosfer}")
        if tavsiye:
            md.append(f"* **Gelecek Mülakatlar İçin Tavsiyeler**: {tavsiye}")
        md.append("")

        # Ek Notlar
        ek_not = (row.get('Eklemek istediğin bir şeyler var mı?') or '').strip()
        if ek_not:
            md.append("## Ek Notlar")
            md.append(f"* {ek_not}")
            md.append("")

        return "\n".join(md)


# ---------------------------- Yazıcı ---------------------------- #
class FileWriter:
    """İçeriği belirtilen yola yazar."""

    def write(self, path: Path, content: str) -> None:
        path.parent.mkdir(parents=True, exist_ok=True)
        with path.open('w', encoding='utf-8') as f:
            f.write(content)


# ---------------------------- Orkestratör ---------------------------- #
class CSVToMarkdownConverter:
    """Bileşenleri kullanarak CSV satırlarını Markdown dosyalarına dönüştürür."""

    def __init__(
        self,
        source: CSVInterviewSource,
        generator: MarkdownGenerator,
        path_builder: OutputPathBuilder,
        writer: FileWriter,
    ) -> None:
        self.source = source
        self.generator = generator
        self.path_builder = path_builder
        self.writer = writer

    def run(self) -> None:
        for index, row in enumerate(self.source.rows(), start=1):
            content = self.generator.generate(row)
            target_path = self.path_builder.build(row, index)
            self.writer.write(target_path, content)
            print(f"✓ Oluşturuldu: {target_path}")


# ---------------------------- CLI ---------------------------- #
def parse_args():
    parser = argparse.ArgumentParser(
        description="CSV dosyasından yıllara göre klasörlenmiş Markdown mülakat notları oluşturur."
    )
    parser.add_argument(
        'csv',
        nargs='?',
        default="Mülakat Anketi (Yanıtlar) - Form Yanıtları 1.csv",
        help='Giriş CSV dosyası (varsayılan: "Mülakat Anketi (Yanıtlar) - Form Yanıtları 1.csv")',
    )
    parser.add_argument(
        '-o', '--output-dir',
        default=None,
        help='Çıktıların yazılacağı ana dizin (varsayılan: çalışma dizini)'
    )
    return parser.parse_args()


def main(csv_file: str, output_dir: Optional[str]) -> int:
    csv_path = Path(csv_file)
    source = CSVInterviewSource(csv_path)
    if not source.exists():
        print(f"❌ Hata: '{csv_file}' dosyası bulunamadı!")
        return 1

    base_dir = Path(output_dir) if output_dir else Path.cwd()
    converter = CSVToMarkdownConverter(
        source=source,
        generator=MarkdownGenerator(),
        path_builder=OutputPathBuilder(base_dir),
        writer=FileWriter(),
    )
    converter.run()
    print("\n✓ Tüm dosyalar başarıyla oluşturuldu!")
    return 0


if __name__ == "__main__":
    args = parse_args()
    raise SystemExit(main(args.csv, args.output_dir))
