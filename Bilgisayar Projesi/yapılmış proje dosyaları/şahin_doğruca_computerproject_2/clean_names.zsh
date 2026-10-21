#!/bin/zsh

# --- Kullanım ---
# ./clean_names.zsh <klasör_yolu>
# Ör: ./clean_names.zsh ./data

# Parametre kontrolü
if [ -z "$1" ]; then
    echo "Kullanım: $0 <klasör>"
    exit 1
fi

TARGET_DIR="$1"

if [ ! -d "$TARGET_DIR" ]; then
    echo "Hata: '$TARGET_DIR' bir klasör değil."
    exit 1
fi

echo "📦 İşlem yapılan klasör: $TARGET_DIR"
echo "🔧 Boşluklar temizleniyor..."

# --- 1) Dosya adlarındaki boşlukları '_' yap ---
find "$TARGET_DIR" -depth -name "* *" -exec bash -c '
    old="$0"
    new="${old// /_}"
    echo "→ $old  ==>  $new"
    mv "$old" "$new"
' {} \;

echo "🔧 Türkçe karakterler dönüştürülüyor..."

# --- 2) Türkçe karakterleri ASCII'ye çevir ---
find "$TARGET_DIR" -depth -type f -exec bash -c '
    old="$0"
    new=$(echo "$old" | iconv -f utf8 -t ascii//TRANSLIT)
    if [ "$old" != "$new" ]; then
        echo "→ $old  ==>  $new"
        mv "$old" "$new"
    fi
' {} \;

echo "✅ Tamamlandı!"
