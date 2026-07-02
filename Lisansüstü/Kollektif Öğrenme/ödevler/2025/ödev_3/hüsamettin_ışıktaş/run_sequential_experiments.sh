#!/bin/bash
# Ardışık GRPO Eğitim Scripti
# 4 farklı ödül fonksiyonunu sırayla çalıştırır

# Hata durumunda dur
set -e

# Tarih damgası (tüm deney serisi için)
TIMESTAMP_SERIES=$(date +"%Y%m%d_%H%M%S")
echo "=== ARDIŞIK EĞİTİM SERİSİ BAŞLIYOR (${TIMESTAMP_SERIES}) ==="

# Ödül fonksiyonları listesi
REWARD_FUNCTIONS=("short" "long" "turkish" "connectives" "simple")

for REWARD_FUNC in "${REWARD_FUNCTIONS[@]}"
do
    echo ""
    echo "=================================================================="
    echo " BAŞLATILIYOR: ${REWARD_FUNC} Reward Function"
    echo "=================================================================="
    
    # Log dosyası
    TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
    LOG_FILE="logs/training_output_${REWARD_FUNC}_${TIMESTAMP}.txt"
    
    echo "Log dosyası: ${LOG_FILE}"
    
    # Python script'ini çalıştır
    python -m src.main --reward_function "${REWARD_FUNC}" 2>&1 | tee "${LOG_FILE}"
    
    EXIT_CODE=$?
    
    if [ $EXIT_CODE -eq 0 ]; then
        echo ""
        echo "✓ ${REWARD_FUNC} eğitimi başarıyla tamamlandı."
    else
        echo ""
        echo "✗ ${REWARD_FUNC} eğitimi başarısız oldu (Exit Code: ${EXIT_CODE})."
        # Hata durumunda döngüden çıkmak isterseniz exit ekleyebilirsiniz
        # exit 1
    fi
    
    # GPU'nun soğuması ve temizlenmesi için kısa bekleme
    echo "Bir sonraki eğitim için bekleniyor (10sn)..."
    sleep 10
done

echo ""
echo "=== TÜM EĞİTİM SERİSİ TAMAMLANDI ==="

# Model Birleştirme
echo ""
echo "=== MODEL BİRLEŞTİRME VE DEĞERLENDİRME BAŞLIYOR ==="
python -m src.merge_and_evaluate 2>&1 | tee "logs/merge_and_evaluate_${TIMESTAMP_SERIES}.txt"

echo ""
echo "=== FİNAL RAPORU OLUŞTURULUYOR ==="
python -m src.create_summary_report

echo ""
echo "=== HER ŞEY TAMAMLANDI! ==="
