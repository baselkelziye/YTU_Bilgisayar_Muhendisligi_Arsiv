#!/bin/bash
clear

# Şu anki klasörü kaydet
CURRENT_DIR=$(pwd)

# Script'in bulunduğu klasöre tam yolu kullanarak git
cd "$(dirname "$0")/google_forum_islemleri"
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8

export LANG=en_US.UTF-8
# Python script'lerini çalıştır
echo "Hoca icerikleri guncelleniyor..."
python3 hoca_icerikleri_guncelle.py

echo "Ders icerikleri guncelleniyor..."
python3 ders_icerikleri_guncelle.py

# Eski klasörüne geri dön
cd "$CURRENT_DIR"

echo "Islem tamamlandi."
exit 0
