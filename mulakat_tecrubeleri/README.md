# 💼 Mülakat Tecrübeleri

YTU Bilgisayar Mühendisliği öğrencilerinin ve mezunlarının iş başvuruları ve mülakatlarındaki deneyimlerini paylaştığı bölüm.

## 📂 Klasör Yapısı

```
mulakat_tecrubeleri/
├── yıl/
│   ├── tecrube_1.md
│   └── tecrube_2.md
├── 2023/
│   ├── turkcell_genc_yetenek.md
│   └── TUBİTAK_BİLGEM_4.md
└── csv_to_md.py
```

- 📅 **Yıl klasörleri**: Her yıl için ayrı klasör (örn: `2023/`, `2025/`)
- 📄 **Dosya adlandırma**: `Sirket_Adi.md` veya `Sirket_Adi.md` biçiminde
- 🔧 **csv_to_md.py**: CSV biçimindeki mülakat tecrübelerini otomatik olarak yıllara göre Markdown dosyalarına dönüştüren Python scripti

## 🛠️ csv_to_md.py Kullanımı

Script, CSV dosyasındaki mülakat verilerini okuyarak:
- Tarihe göre otomatik yıl klasörleri oluşturur
- Her mülakat için ayrı Markdown dosyası üretir
- Şirket adına göre dosya adı belirler
- SOLID prensiplerine uygun, modüler yapıda geliştirilmiştir

```bash
python csv_to_md.py input.csv output_directory/
```
