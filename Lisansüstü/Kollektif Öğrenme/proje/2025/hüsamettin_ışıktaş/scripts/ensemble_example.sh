#!/bin/bash

# Ensemble örneği - models/20260106_001352 klasöründeki modelleri birleştirme

# Sanal ortamı aktif et
source .venv/bin/activate

# Logs klasörünü oluştur
mkdir -p logs/ensemble

# Base model klasörü
BASE_DIR="models/20260106_001352"
TIMESTAMP=$(date +"%Y%m%d_%H%M%S")

echo "Ensemble training starting with timestamp: $TIMESTAMP"

# Örnek 1: En iyi 3 modeli F1 score'a göre ağırlıklandırarak birleştir
echo "[$(date)] Ensemble 1: Top 3 models with F1-based weights (dinov3, dinov2, convnext)..."
LOG_FILE="logs/ensemble/ensemble_top3_f1_${TIMESTAMP}.log"

{
    echo "=== Ensemble started at $(date) ==="
    echo "Command: python -u src/ensemble_models.py --model_dirs $BASE_DIR/dinov3 $BASE_DIR/dinov2 $BASE_DIR/convnext --use_f1_weights"
    echo ""
    
    python -u src/ensemble_models.py \
        --model_dirs "$BASE_DIR/dinov3" "$BASE_DIR/dinov2" "$BASE_DIR/convnext" \
        --use_f1_weights \
        --batch_size 128 \
        --split test \
        2>&1 | tee -a "$LOG_FILE"
} > "$LOG_FILE" 2>&1

EXIT_CODE=$?
echo "" >> "$LOG_FILE"
echo "=== Ensemble finished at $(date) with exit code: $EXIT_CODE ===" >> "$LOG_FILE"

if [ $EXIT_CODE -eq 0 ]; then
    echo "[$(date)] Successfully finished ensemble 1"
else
    echo "[$(date)] Failed ensemble 1 (exit code: $EXIT_CODE)"
fi

# Örnek 2: Tüm modelleri eşit ağırlıkla birleştir
echo "[$(date)] Ensemble 2: All models with equal weights..."
LOG_FILE="logs/ensemble/ensemble_all_equal_${TIMESTAMP}.log"

{
    echo "=== Ensemble started at $(date) ==="
    echo "Command: python -u src/ensemble_models.py --model_dirs $BASE_DIR/dinov3 $BASE_DIR/dinov2 $BASE_DIR/convnext $BASE_DIR/openclip $BASE_DIR/siglip"
    echo ""
    
    python -u src/ensemble_models.py \
        --model_dirs "$BASE_DIR/dinov3" "$BASE_DIR/dinov2" "$BASE_DIR/convnext" "$BASE_DIR/openclip" "$BASE_DIR/siglip" \
        --batch_size 128 \
        --split test \
        2>&1 | tee -a "$LOG_FILE"
} > "$LOG_FILE" 2>&1

EXIT_CODE=$?
echo "" >> "$LOG_FILE"
echo "=== Ensemble finished at $(date) with exit code: $EXIT_CODE ===" >> "$LOG_FILE"

if [ $EXIT_CODE -eq 0 ]; then
    echo "[$(date)] Successfully finished ensemble 2"
else
    echo "[$(date)] Failed ensemble 2 (exit code: $EXIT_CODE)"
fi

# Örnek 3: Manuel ağırlıklandırma
echo "[$(date)] Ensemble 3: Manual weights (dinov3: 0.4, dinov2: 0.3, convnext: 0.3)..."
LOG_FILE="logs/ensemble/ensemble_manual_weights_${TIMESTAMP}.log"

{
    echo "=== Ensemble started at $(date) ==="
    echo "Command: python -u src/ensemble_models.py --model_dirs $BASE_DIR/dinov3 $BASE_DIR/dinov2 $BASE_DIR/convnext --weights 0.4 0.3 0.3"
    echo ""
    
    python -u src/ensemble_models.py \
        --model_dirs "$BASE_DIR/dinov3" "$BASE_DIR/dinov2" "$BASE_DIR/convnext" \
        --weights 0.4 0.3 0.3 \
        --batch_size 128 \
        --split test \
        2>&1 | tee -a "$LOG_FILE"
} > "$LOG_FILE" 2>&1

EXIT_CODE=$?
echo "" >> "$LOG_FILE"
echo "=== Ensemble finished at $(date) with exit code: $EXIT_CODE ===" >> "$LOG_FILE"

if [ $EXIT_CODE -eq 0 ]; then
    echo "[$(date)] Successfully finished ensemble 3"
else
    echo "[$(date)] Failed ensemble 3 (exit code: $EXIT_CODE)"
fi

echo "[$(date)] All ensemble experiments completed."

