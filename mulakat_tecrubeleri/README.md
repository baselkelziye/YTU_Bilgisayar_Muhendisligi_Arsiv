# 💼 Mülakat Tecrübeleri

YTU Bilgisayar Mühendisliği öğrencilerinin ve mezunlarının iş başvuruları ve mülakatlarındaki deneyimlerini paylaştığı bölüm.

## 📂 Klasör Yapısı

```
mulakat_tecrubeleri/
├── yıl/
│   ├── Sirket_Adi.md
│   └── Diger_Sirket.md
├── 2023/
│   ├── Turkcell.md
│   └── TUBİTAK.md
├── 2025/
│   ├── Kuveyt_Türk.md
│   ├── Kuveyt_Türk_2.md
│   └── Architecht.md
└── csv_to_md.py
```

- 📅 **Yıl klasörleri**: Her yıl için ayrı klasör (örn: `2023/`, `2025/`)
- 📄 **Dosya adlandırma**: 
  - Tek mülakat: `Sirket_Adi.md`
  - Aynı şirketten birden fazla mülakat: `Sirket_Adi_2.md`, `Sirket_Adi_3.md` şeklinde
  - Her yıl klasörü kendi içinde bağımsız sayaç kullanır
- 🔧 **csv_to_md.py**: CSV biçimindeki mülakat tecrübelerini otomatik olarak yıllara göre Markdown dosyalarına dönüştüren Python scripti

## 🛠️ csv_to_md.py Kullanımı

Script, CSV dosyasındaki mülakat verilerini okuyarak:
- Tarihe göre otomatik yıl klasörleri oluşturur
- Her mülakat için ayrı Markdown dosyası üretir
- Şirket adına göre dosya adı belirler
- Aynı şirketten birden fazla mülakat varsa otomatik sayı ekler (her yıl kendi içinde sayar)
- SOLID prensiplerine uygun, modüler yapıda geliştirilmiştir

```bash
python csv_to_md.py input.csv output_directory/
```
