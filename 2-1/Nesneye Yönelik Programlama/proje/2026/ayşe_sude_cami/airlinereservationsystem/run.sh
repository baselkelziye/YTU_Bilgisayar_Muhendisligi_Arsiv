#!/bin/bash

# Proje dizini
PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
OUT_DIR="$PROJECT_DIR/out"
LIB_DIR="$PROJECT_DIR/lib"

# Derlenmiş dosyalar var mı kontrol et
if [ ! -d "$OUT_DIR" ]; then
    echo "❌ Önce compile.sh çalıştırın!"
    exit 1
fi

# CLI modu kontrolü
if [ "$1" == "--cli" ] || [ "$1" == "-c" ] || [ "$1" == "--no-gui" ]; then
    echo "Terminal modunda başlatılıyor..."
    java -cp "$OUT_DIR" com.airline.CliApp
else
    # JavaFX modül yolu (sadece Mac ARM64 JAR'ları - duplicate module hatasını önlemek için)
    JAVAFX_MODULES="$LIB_DIR/javafx-base-21-mac-aarch64.jar:$LIB_DIR/javafx-controls-21-mac-aarch64.jar:$LIB_DIR/javafx-fxml-21-mac-aarch64.jar:$LIB_DIR/javafx-graphics-21-mac-aarch64.jar"

    echo "GUI modunda başlatılıyor..."

    java --module-path "$JAVAFX_MODULES" \
         --add-modules javafx.controls,javafx.fxml,javafx.graphics,javafx.base \
         --enable-native-access=javafx.graphics \
         -cp "$OUT_DIR" \
         com.airline.Launcher 2>&1 | grep -v "^WARNING:"
fi
