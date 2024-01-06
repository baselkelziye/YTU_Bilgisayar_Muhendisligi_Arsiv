#!/bin/bash
clear

# Şu anki klasörü kaydet
CURRENT_DIR=$(pwd)

# Script'in bulunduğu klasöre tam yolu kullanarak git
cd "$(dirname "$0")/google_forum_islemleri"

# Python script'lerini çalıştır
echo "Hoca icerikleri guncelleniyor..."
python3 hoca_icerikleri_guncelle.py

echo "Ders icerikleri guncelleniyor..."
python3 ders_icerikleri_guncelle.py

# Eski klasörüne geri dön
cd "$CURRENT_DIR"

echo "Islem tamamlandi."
