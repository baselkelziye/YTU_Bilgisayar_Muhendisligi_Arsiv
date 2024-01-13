#!/bin/bash
clear
cd "$(dirname "$0")"

# Python script'lerini çalıştır
echo "Readmeler guncelleniyor..."
python3 readme_olustur.py
if [ $? -ne 0 ]; then
    echo "Hata: Readme oluşturma script'i başarısız oldu."
    read -p "Devam etmek için enter'a basın..."
    exit 1
fi

git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8
export LANG=en_US.UTF-8

echo "Islem tamamlandi."
read -p "Devam etmek için enter'a basın..."
exit 0
