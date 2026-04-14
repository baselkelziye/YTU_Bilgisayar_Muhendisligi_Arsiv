#!/bin/bash

# Script'in bulunduğu dizine geç
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

# Renk tanımları
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}PyInstaller Build Script${NC}"
echo "========================================"

# venv klasörünü kontrol et
VENV_DIR="$SCRIPT_DIR/venv"

if [ ! -d "$VENV_DIR" ]; then
    echo -e "${YELLOW}venv bulunamadı, oluşturuluyor...${NC}"
    python3 -m venv "$VENV_DIR"
    
    if [ $? -ne 0 ]; then
        echo -e "${RED}venv oluşturulamadı!${NC}"
        exit 1
    fi
    echo -e "${GREEN}venv oluşturuldu.${NC}"
fi

# venv'i aktifle
source "$VENV_DIR/bin/activate"

# pip'i güncelle
pip install --upgrade pip

# Projeyi pyproject.toml ile kur (dev bağımlılıklarıyla birlikte)
echo -e "${YELLOW}pyproject.toml ile kurulum yapılıyor...${NC}"
pip install -e ".[dev]"

if [ $? -ne 0 ]; then
    echo -e "${RED}Kurulum başarısız!${NC}"
    exit 1
fi
echo -e "${GREEN}Kurulum tamamlandı.${NC}"

echo -e "${YELLOW}Build başlıyor...${NC}"

# PyInstaller ile build al (pyproject.toml'daki konfigürasyona göre)
pyinstaller \
    --name main \
    --onefile \
    --console \
    --distpath "$SCRIPT_DIR/dist" \
    --workpath "$SCRIPT_DIR/build" \
    --noconfirm \
    --add-data "readme_guncelleme_arayuzu_python:." \
    --add-data "google_forum_islemleri:google_forum_islemleri" \
    --add-data "writers:writers" \
    --add-data "readme_olustur.py:." \
    --add-data "buffered_writer.py:." \
    --add-data "folder_cache.py:." \
    --hidden-import pandas \
    --hidden-import numpy \
    --hidden-import requests \
    --hidden-import google_forum_islemleri.ders_icerikleri_guncelle \
    --hidden-import google_forum_islemleri.hoca_icerikleri_guncelle \
    --hidden-import google_forum_islemleri.google_form_rutin_kontrol \
    --hidden-import readme_olustur \
    --hidden-import buffered_writer \
    --hidden-import folder_cache \
    readme_guncelleme_arayuzu_python/main.py

if [ $? -eq 0 ]; then
    # Dosyayı kök dizine taşı
    mv "$SCRIPT_DIR/dist/main" "$SCRIPT_DIR/main"
    
    echo -e "${GREEN}========================================"
    echo -e "Build başarıyla tamamlandı!"
    echo -e "Executable: $SCRIPT_DIR/main"
    echo -e "========================================${NC}"
else
    echo -e "${RED}Build başarısız oldu!${NC}"
    exit 1
fi