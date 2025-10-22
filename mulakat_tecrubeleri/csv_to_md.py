import argparse
import csv
import os
from datetime import datetime
from pathlib import Path
from collections import defaultdict

def csv_to_markdown(csv_file, output_dir=None):
    """
    CSV dosyasını okur ve her satır için Markdown dosyası oluşturur.
    Yıllara göre klasörler oluşturur ve dosyaları içine atar.
    """
    
    # CSV dosyasını oku
    csv_path = Path(csv_file)
    if not csv_path.exists():
        print(f"❌ Hata: '{csv_file}' dosyası bulunamadı!")
        return

    # Eğer output_dir verilmişse, orada yıl klasörleri oluşturulacak
    base_dir = Path(output_dir) if output_dir else Path.cwd()
    base_dir.mkdir(parents=True, exist_ok=True)

    with csv_path.open('r', encoding='utf-8') as file:
        # CSV'yi satır satır oku ve tekrarlanan sütunları işle
        reader = csv.reader(file)
        headers = next(reader)
        
        # Tekrarlanan sütun isimlerini say ve yeniden adlandır
        header_counts = defaultdict(int)
        new_headers = []
        for header in headers:
            if header_counts[header] > 0:
                new_headers.append(f"{header}_{header_counts[header]}")
            else:
                new_headers.append(header)
            header_counts[header] += 1
        
        for index, row_data in enumerate(reader, start=1):
            row = dict(zip(new_headers, row_data))
            
            # Mülakat tarihinden yılı al
            mulakat_tarihi = row.get('Mülakat Tarihi', '')
            yil = extract_year(mulakat_tarihi)
            
            # Yıl klasörünü oluştur
            if yil:
                klasor_adi = str(yil)
            else:
                klasor_adi = 'Tarihsiz'

            target_dir = base_dir / klasor_adi
            target_dir.mkdir(parents=True, exist_ok=True)
            
            # Markdown içeriğini oluştur
            markdown_content = create_markdown(row)
            
            # Dosya adını oluştur (şirket adı ve index kullanarak)
            sirket_adi = row.get('Mülakatı Yapan Şirket Adı', 'bilinmeyen').strip()
            dosya_adi = f"{sirket_adi.replace(' ', '_').replace('/', '_')}_{index}.md"
            dosya_yolu = target_dir / dosya_adi
            
            # Markdown dosyasını yaz
            with dosya_yolu.open('w', encoding='utf-8') as md_file:
                md_file.write(markdown_content)
            
            print(f"✓ Oluşturuldu: {dosya_yolu}")

def extract_year(tarih_str):
    """Tarih stringinden yılı çıkarır"""
    if not tarih_str:
        return None
    
    try:
        # Farklı tarih formatlarını dene
        for fmt in ['%d.%m.%Y', '%m.%Y', '%Y']:
            try:
                tarih = datetime.strptime(tarih_str, fmt)
                return tarih.year
            except ValueError:
                continue
        
        # Eğer sadece yıl yazılmışsa
        if tarih_str.isdigit() and len(tarih_str) == 4:
            return int(tarih_str)
            
    except:
        pass
    
    return None

def create_markdown(row):
    """CSV satırından Markdown içeriği oluşturur"""
    
    # Başlık
    sirket = row.get('Mülakatı Yapan Şirket Adı', 'Bilinmeyen Şirket')
    alan = row.get('Mülakat Alanı', '')
    
    if alan:
        baslik = f"# {sirket} {alan} Mülakat Süreci"
    else:
        baslik = f"# {sirket} Mülakat Süreci"
    
    markdown = [baslik, ""]
    
    # Mülakat Bilgileri bölümü
    markdown.append("## Mülakat Bilgileri")
    
    mulakat_bilgileri = {
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
    
    for label, key in mulakat_bilgileri.items():
        value = row.get(key, '').strip()
        if value:
            markdown.append(f"* {label}: {value}")
    
    markdown.append("")
    
    # Ön Hazırlık bölümü
    on_hazirlik = {
        'İş ilanına nasıl başvuruldu': 'İş ilanına nereden başvurdunuz?',
        'Başvurudan mülakata kadar geçen süre': 'Başvurudan ne kadar süre sonra mülakata çağırıldınız?',
        'Hazırlık için kullanılan kaynaklar': 'Mülakata hazırlık için neler yaptınız',
        'Hazırlık süresince üzerinde durulan konular': 'Hazırlık süresince hangi konular üzerinde çalıştınız?'
    }
    
    if any(row.get(key, '').strip() for key in on_hazirlik.values()):
        markdown.append("## Ön Hazırlık")
        for label, key in on_hazirlik.items():
            value = row.get(key, '').strip()
            if value:
                markdown.append(f"* {label}: {value}")
        markdown.append("")
    
    # Alt Mülakatlar - DÜZELTİLMİŞ BÖLÜM
    alt_mulakat_sayisi = row.get('Toplam Kaç Tane Alt Mülakata Girdiniz', '').strip()
    
    if alt_mulakat_sayisi:
        markdown.append("## Mülakat Süreci")
        markdown.append("")
        
        # Tüm alt mülakatları kontrol et
        mulakat_bulundu = False
        for i in range(10):  # Maksimum 10 alt mülakat varsayalım
            # İlk mülakat için suffix yok, diğerleri için _1, _2, _3...
            suffix = '' if i == 0 else f'_{i}'
            
            tip_key = f'Alt Mülakat Tipi{suffix}'
            tip = row.get(tip_key, '').strip()
            
            if tip:
                mulakat_bulundu = True
                markdown.append(f"### {i+1}. {tip}")
                
                sure_key = f'Alt Mülakat Süresi{suffix}'
                bicim_key = f'Alt Mülakat Biçimi{suffix}'
                kisi_key = f'Alt Mülakatta Görüşülen Kişi Sayısı{suffix}'
                yapan_key = f'Mülakatı Yapan Kişi(ler){suffix}'
                
                sure = row.get(sure_key, '').strip()
                bicim = row.get(bicim_key, '').strip()
                kisi = row.get(kisi_key, '').strip()
                yapan = row.get(yapan_key, '').strip()
                
                if sure:
                    markdown.append(f"* **Süre**: {sure}")
                if bicim:
                    markdown.append(f"* **Biçim**: {bicim}")
                if kisi:
                    markdown.append(f"* **Görüşülen kişi sayısı**: {kisi}")
                if yapan:
                    markdown.append(f"* **Mülakatı yapan**: {yapan}")
                
                sorular_key = f'Alt Mülakat Sırasında Size Sorulan Sorular{suffix}'
                sorular = row.get(sorular_key, '').strip()
                
                if sorular:
                    markdown.append("")
                    markdown.append("#### Sorulan Sorular")
                    markdown.append(sorular)
                
                markdown.append("")
            else:
                # Eğer bu indekste mülakat yoksa, döngüyü kır
                if mulakat_bulundu:
                    break
    
    # Genel Değerlendirme
    markdown.append("## Genel Değerlendirme ve Öğrenilen Dersler")
    
    zorluk = row.get('Mülakat Zorluk Derecesi', '').strip()
    atmosfer = row.get('Mülakat Atmosferi Nasıldı?', '').strip()
    tavsiye = row.get('Benzer şirkette benzer mülakata gireceklere ne tavsiye edersin? ', '').strip()
    
    if zorluk:
        markdown.append(f"* **Mülakat Zorluk Derecesi**: {zorluk}")
    if atmosfer:
        markdown.append(f"* **Mülakat Atmosferi**: {atmosfer}")
    if tavsiye:
        markdown.append(f"* **Gelecek Mülakatlar İçin Tavsiyeler**: {tavsiye}")
    
    markdown.append("")
    
    # Ek Notlar
    ek_not = row.get('Eklemek istediğin bir şeyler var mı?', '').strip()
    if ek_not:
        markdown.append("## Ek Notlar")
        markdown.append(f"* {ek_not}")
        markdown.append("")
    
    return '\n'.join(markdown)

def parse_args():
    parser = argparse.ArgumentParser(
        description="CSV dosyasından yıllara göre klasörlenmiş Markdown mülakat notları oluşturur."
    )
    parser.add_argument('csv', nargs='?', default="Mülakat Anketi (Yanıtlar) - Form Yanıtları 1.csv",
                        help='Giriş CSV dosyası (varsayılan: "Mülakat Anketi (Yanıtlar) - Form Yanıtları 1.csv")')
    parser.add_argument('-o', '--output-dir', default=None,
                        help='Çıktıların yazılacağı ana dizin (varsayılan: çalışma dizini)')
    return parser.parse_args()


if __name__ == "__main__":
    args = parse_args()
    csv_to_markdown(args.csv, args.output_dir)
    print("\n✓ Tüm dosyalar başarıyla oluşturuldu!")
