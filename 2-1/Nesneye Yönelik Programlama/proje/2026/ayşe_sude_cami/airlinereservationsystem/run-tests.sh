#!/bin/bash

# Test çalıştırma scripti
cd "$(dirname "$0")"

echo "🧪 Testler derleniyor ve çalıştırılıyor..."

# Klasör yapısı
LIB_DIR="lib"
OUT_DIR="out"
TEST_OUT_DIR="out-test"
SRC_DIR="src"

# out-test klasörünü temizle
rm -rf $TEST_OUT_DIR
mkdir -p $TEST_OUT_DIR

# Classpath oluştur
CP="$OUT_DIR"
for jar in $LIB_DIR/*.jar; do
    CP="$CP:$jar"
done

# JUnit Console Launcher'ı kontrol et, yoksa indir
JUNIT_CONSOLE="$LIB_DIR/junit-platform-console-standalone-1.10.0.jar"
if [ ! -f "$JUNIT_CONSOLE" ]; then
    echo "📥 JUnit Console Launcher indiriliyor..."
    curl -L -o "$JUNIT_CONSOLE" \
        "https://repo1.maven.org/maven2/org/junit/platform/junit-platform-console-standalone/1.10.0/junit-platform-console-standalone-1.10.0.jar"
fi

# Önce ana kodları modül sistemsiz derle (testler için)
echo "📦 Ana kodlar derleniyor..."
find $SRC_DIR -name "*.java" ! -path "*/test/*" > sources.txt

# JavaFX modüllerini module-path olarak ekle ama projeyi modül olarak değil, classpath ile derle
javac --release 17 \
    --module-path "$LIB_DIR" \
    --add-modules javafx.controls,javafx.fxml \
    -d $TEST_OUT_DIR \
    @sources.txt 2>/dev/null
rm sources.txt

# Test dosyalarını derle (modül sistemi olmadan, classpath ile)
echo "📦 Test dosyaları derleniyor..."
TEST_CP="$TEST_OUT_DIR:$JUNIT_CONSOLE"
for jar in $LIB_DIR/javafx*.jar; do
    TEST_CP="$TEST_CP:$jar"
done

javac --release 17 \
    --module-path "$LIB_DIR" \
    --add-modules javafx.controls,javafx.fxml \
    -cp "$TEST_CP" \
    -d $TEST_OUT_DIR \
    $SRC_DIR/com/airline/test/*.java

if [ $? -ne 0 ]; then
    echo "❌ Test derleme hatası!"
    exit 1
fi

echo ""
echo "🚀 Testler çalıştırılıyor..."
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""

# Testleri çalıştır
RUN_CP="$TEST_OUT_DIR:$JUNIT_CONSOLE"
for jar in $LIB_DIR/javafx*.jar; do
    RUN_CP="$RUN_CP:$jar"
done

java --module-path "$LIB_DIR" \
    --add-modules javafx.controls,javafx.fxml \
    -jar "$JUNIT_CONSOLE" \
    --class-path "$RUN_CP" \
    --scan-class-path \
    --include-classname ".*Test" \
    --details=tree

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "✅ Test çalıştırması tamamlandı!"
