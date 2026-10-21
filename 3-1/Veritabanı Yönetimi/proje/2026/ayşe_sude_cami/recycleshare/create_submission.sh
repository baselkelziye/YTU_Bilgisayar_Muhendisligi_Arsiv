#!/bin/bash

# ============================================
# RecycleShare - Ödev Teslim ZIP Oluşturucu
# Grup: 47
# ============================================

echo "🚀 Grup 47 - RecycleShare Teslim ZIP'i Hazırlanıyor..."
echo ""

# Proje dizini
PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
OUTPUT_DIR="$PROJECT_DIR"
ZIP_NAME="47.zip"
TEMP_DIR="$PROJECT_DIR/temp_zip_47"

# Önceki temp dizini varsa sil
rm -rf "$TEMP_DIR"
rm -f "$OUTPUT_DIR/$ZIP_NAME"

# Temp dizin oluştur
mkdir -p "$TEMP_DIR/47"

echo "📁 Dosyalar kopyalanıyor..."

# 1. Backend (node_modules HARİÇ, .env DAHİL)
echo "   → Backend..."
mkdir -p "$TEMP_DIR/47/backend"
rsync -av --exclude='node_modules' --exclude='.env.example' "$PROJECT_DIR/backend/" "$TEMP_DIR/47/backend/" > /dev/null 2>&1

# 2. Frontend (node_modules HARİÇ, .env DAHİL)
echo "   → Frontend..."
mkdir -p "$TEMP_DIR/47/frontend"
rsync -av --exclude='node_modules' --exclude='dist' --exclude='.env.example' "$PROJECT_DIR/frontend/" "$TEMP_DIR/47/frontend/" > /dev/null 2>&1

# 3. Database schema
echo "   → Database schema..."
mkdir -p "$TEMP_DIR/47/database"
cp "$PROJECT_DIR/database/schema.sql" "$TEMP_DIR/47/database/"

# 4. .env.example ve README.md çıkarıldı (İstek üzerine)

# 6. Rapor (eğer varsa)
if [ -f "$PROJECT_DIR/47.pdf" ]; then
    echo "   → Rapor PDF (47.pdf)..."
    cp "$PROJECT_DIR/47.pdf" "$TEMP_DIR/47/"
else
    echo "   ⚠️  47.pdf bulunamadı! Daha sonra ekleyin."
fi

# 7. ZIP oluştur
echo ""
echo "📦 ZIP oluşturuluyor..."
cd "$TEMP_DIR"
zip -r "$OUTPUT_DIR/$ZIP_NAME" 47 > /dev/null 2>&1

# Temp dizini temizle
rm -rf "$TEMP_DIR"

# Sonuç
echo ""
echo "✅ Teslim dosyası hazır!"
echo ""
echo "📍 Dosya: $OUTPUT_DIR/$ZIP_NAME"
echo ""

# ZIP içeriğini göster
echo "📋 ZIP İçeriği:"
unzip -l "$OUTPUT_DIR/$ZIP_NAME" | head -30

echo ""
echo "📊 Dosya Boyutu: $(du -h "$OUTPUT_DIR/$ZIP_NAME" | cut -f1)"
echo ""

# Eksik kontrolü
echo "⚠️  Kontrol Listesi:"
if [ -f "$PROJECT_DIR/47.pdf" ]; then
    echo "   ✅ 47.pdf mevcut"
else
    echo "   ❌ 47.pdf EKSİK - ZIP'e eklenmedi!"
fi

echo ""
echo "🎉 Tamamlandı! 47.zip dosyasını gönderebilirsiniz."
