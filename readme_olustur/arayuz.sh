#!/bin/bash
clear

# Python'un yüklü olup olmadığını kontrol edin
if ! command -v python3 &> /dev/null
then
    echo "Python 3 bulunamadi. Lutfen https://www.python.org/downloads/ adresinden yukleyin."
    echo "Yukleme sirasinda 'Add Python to PATH' secenegini isaretlediginizden emin olun."
    exit 1
fi

# pip'in yüklü olup olmadığını kontrol edin
if ! command -v pip3 &> /dev/null
then
    echo "pip3 bulunamadi, Python'unuz ile birlikte otomatik olarak yuklenmesi gerekirdi."
    echo "Yukleme sirasinda bir sorun olmus olabilir. Python'u tekrar yuklemeyi deneyin."
    exit 1
fi

# Gerekli kütüphaneleri yükleyin
echo "Gerekli kutuphaneler kontrol ediliyor ve yukleniyor..."

while IFS= read -r package
do
    if ! pip3 show "$package" &> /dev/null; then
        echo "$package yukleniyor..."
        pip3 install "$package"
    fi
done < gereksinimler.txt

# readme_olusturma_arayuzu klasörüne çıkın ve main.py'yi çalıştırın
cd "$(dirname "$0")/readme_guncelleme_arayuzu_python"
python3 main.py &

echo "İşlem tamamlandı."
exit 0