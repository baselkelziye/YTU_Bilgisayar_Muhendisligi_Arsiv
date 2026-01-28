#!/bin/bash
clear

# Python'un yüklü olup olmadığını kontrol edin
if ! command -v python3 &> /dev/null
then
    echo "Python 3 bulunamadi. Lutfen https://www.python.org/downloads/ adresinden yukleyin." [[3]]
    echo "Yukleme sirasinda 'Add Python to PATH' secenegini isaretlediginizden emin olun." [[5]]
    exit 1
fi

# venv modülünün yüklü olup olmadığını kontrol edin
if ! python3 -c "import venv" &> /dev/null
then
    echo "venv modulu bulunamadi. Python'unuz ile birlikte otomatik olarak yuklenmesi gerekirdi."
    echo "Yukleme sirasinda bir sorun olmus olabilir. Python'u tekrar yuklemeyi deneyin."
    exit 1
fi

# Proje dizinini belirleyin
PROJECT_DIR="$(dirname "$0")"
VENV_DIR="$PROJECT_DIR/venv"

# Sanal ortam oluşturun
if [ ! -d "$VENV_DIR" ]; then
    echo "Sanal ortam olusturuluyor..."
    python3 -m venv "$VENV_DIR"
fi

# Sanal ortamı etkinleştirin
source "$VENV_DIR/bin/activate"

# Gerekli kütüphaneleri yükleyin
echo "Gerekli kutuphaneler kontrol ediliyor ve yukleniyor..."

while IFS= read -r package
do
    if ! pip show "$package" &> /dev/null; then
        echo "$package yukleniyor..."
        pip install "$package"
    fi
done < "$PROJECT_DIR/gereksinimler.txt"

# readme_olusturma_arayuzu klasörüne çıkın ve main.py'yi çalıştırın
cd "$PROJECT_DIR/readme_guncelleme_arayuzu_python"
python3 main.py
deactivate

echo "İşlem tamamlandı."
exit 0
