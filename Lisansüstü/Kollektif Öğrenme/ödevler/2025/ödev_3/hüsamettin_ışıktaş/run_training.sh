#!/bin/bash
# GRPO Training Script - Çıktıyı dosyaya yönlendirir

# Tarih ve saat ile dosya adı oluştur
TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
OUTPUT_FILE="logs/training_output_${TIMESTAMP}.txt"

echo "=========================================="
echo "GRPO Training Başlatılıyor"
echo "Çıktı dosyası: ${OUTPUT_FILE}"
echo "=========================================="
echo ""

# Python script'ini çalıştır ve çıktıyı dosyaya yönlendir
# 2>&1: hem stdout hem stderr'i dosyaya yönlendirir
# tee: hem dosyaya yazar hem ekranda gösterir (opsiyonel)
python -m src.main 2>&1 | tee "${OUTPUT_FILE}"

# Sadece dosyaya yazmak isterseniz (ekranda göstermeden):
# python -m src.main > "${OUTPUT_FILE}" 2>&1

echo ""
echo "=========================================="
echo "Eğitim tamamlandı!"
echo "Çıktı dosyası: ${OUTPUT_FILE}"
echo "=========================================="
