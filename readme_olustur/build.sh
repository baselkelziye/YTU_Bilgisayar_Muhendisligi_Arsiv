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
REQUIREMENTS_FILE="$SCRIPT_DIR/gereksinimler.txt"

if [ ! -d "$VENV_DIR" ]; then
    echo -e "${YELLOW}venv bulunamadı, oluşturuluyor...${NC}"
    python3 -m venv "$VENV_DIR"
    
    if [ $? -ne 0 ]; then
        echo -e "${RED}venv oluşturulamadı!${NC}"
        exit 1
    fi
    echo -e "${GREEN}venv oluşturuldu.${NC}"
    
    # venv'i aktifle
    source "$VENV_DIR/bin/activate"
    
    # requirements yükle
    if [ -f "$REQUIREMENTS_FILE" ]; then
        echo -e "${YELLOW}Gereksinimler yükleniyor...${NC}"
        pip install --upgrade pip
        pip install -r "$REQUIREMENTS_FILE"
        pip install pyinstaller
        
        if [ $? -ne 0 ]; then
            echo -e "${RED}Gereksinimler yüklenemedi!${NC}"
            exit 1
        fi
        echo -e "${GREEN}Gereksinimler yüklendi.${NC}"
    else
        echo -e "${RED}gereksinimler.txt bulunamadı!${NC}"
        exit 1
    fi
else
    echo -e "${GREEN}venv mevcut, aktifleştiriliyor...${NC}"
    source "$VENV_DIR/bin/activate"
fi

# spec_dosyalari dizinine geç
SPEC_DIR="$SCRIPT_DIR/spec_dosyalari"
cd "$SPEC_DIR"

if [ ! -f "main.spec" ]; then
    echo -e "${RED}main.spec bulunamadı!${NC}"
    exit 1
fi

echo -e "${YELLOW}Build başlıyor...${NC}"

# Build al
pyinstaller main.spec --distpath ../dist --workpath ../build --noconfirm

if [ $? -eq 0 ]; then
    echo -e "${GREEN}========================================"
    echo -e "Build başarıyla tamamlandı!"
    echo -e "Executable: $SCRIPT_DIR/dist/main"
    echo -e "========================================${NC}"
else
    echo -e "${RED}Build başarısız oldu!${NC}"
    exit 1
fi