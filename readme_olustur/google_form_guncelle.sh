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
if [ $? -ne 0 ]; then
    echo "Hata: Hoca icerikleri guncelleme script'i basarisiz oldu."
    if [ -z "$1" ]; then
    read -p "Devam etmek için enter'a basın..."
fi
    exit 1
fi

echo "Ders icerikleri guncelleniyor..."
python3 ders_icerikleri_guncelle.py
if [ $? -ne 0 ]; then
    echo "Hata: Ders icerikleri guncelleme script'i basarisiz oldu."
    if [ -z "$1" ]; then
    read -p "Devam etmek için enter'a basın..."
fi
    exit 1
fi

# Eski klasörüne geri dön
cd "$CURRENT_DIR"

echo "Islem tamamlandi."
if [ -z "$1" ]; then
    read -p "Devam etmek için enter'a basın..."
fi
exit 0
