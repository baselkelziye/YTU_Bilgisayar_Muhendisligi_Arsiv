#!/bin/bash

# `spec_dosyalari` klasörünün yolunu tanımlayın
SPEC_DIR="spec_dosyalari"

# `spec_dosyalari` klasörü içindeki her .spec dosyası için PyInstaller çalıştır
for spec_file in "$SPEC_DIR"/*.spec; do
    echo "PyInstaller ile çalıştırılıyor: $spec_file"
    pyinstaller "$spec_file"
done
