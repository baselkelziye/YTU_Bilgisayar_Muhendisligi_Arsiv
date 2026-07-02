#!/bin/bash

# Eksik deneyleri tamamlayan script
# CUB için: concat_dinov3_convnext, concat_all
# iNat için: concat_all
# Sonuçlar models/missing_experiments/ klasörüne kaydedilecek

# Sanal ortamı aktif et
source .venv/bin/activate

# Logs klasörünü oluştur
mkdir -p logs/missing_experiments

# Batch için base timestamp oluştur
BASE_TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
echo "Missing experiments batch starting with base timestamp: $BASE_TIMESTAMP"

# Output klasörü
OUTPUT_DIR="models/missing_experiments/${BASE_TIMESTAMP}"
mkdir -p "${OUTPUT_DIR}"

# Embedding klasörleri
CUB_EMB_DIR="embeddings/cub_200"
INAT_EMB_DIR="embeddings/inaturalist_2021"

# Embedding modellerinin listesi
MODELS=("convnext" "dinov2" "dinov3" "openclip" "siglip")

# Failed models listesi
FAILED_MODELS=()

echo "================================================================================"
echo "CUB Missing Experiments"
echo "================================================================================"

# 1. CUB: concat_dinov3_convnext
TIMESTAMP_1="${BASE_TIMESTAMP}_1"
echo "[$(date)] Starting CUB: concat_dinov3_convnext..."
LOG_FILE="logs/missing_experiments/cub_concat_dinov3_convnext_${BASE_TIMESTAMP}.log"
echo "=== Training started for CUB concat_dinov3_convnext at $(date) ===" > "${LOG_FILE}"
echo "Command: python -u src/train_mlp.py --embedding_dirs ${CUB_EMB_DIR}/dinov3 ${CUB_EMB_DIR}/convnext --batch_timestamp ${TIMESTAMP_1}" >> "${LOG_FILE}"
echo "" >> "${LOG_FILE}"

nohup python -u src/train_mlp.py \
    --embedding_dirs "${CUB_EMB_DIR}/dinov3" "${CUB_EMB_DIR}/convnext" \
    --batch_timestamp "${TIMESTAMP_1}" \
    >> "${LOG_FILE}" 2>&1

EXIT_CODE=$?
echo "" >> "${LOG_FILE}"
echo "=== Training finished at $(date) with exit code: $EXIT_CODE ===" >> "${LOG_FILE}"

if [ $EXIT_CODE -eq 0 ]; then
    echo "[$(date)] ✓ CUB concat_dinov3_convnext completed successfully"
    # Modeli output klasörüne taşı (train_mlp.py iki embedding için "concatenated_all" ismi kullanıyor)
    if [ -d "models/${TIMESTAMP_1}/concatenated_all" ]; then
        mv "models/${TIMESTAMP_1}/concatenated_all" "${OUTPUT_DIR}/concat_dinov3_convnext"
        echo "[$(date)] Model moved to ${OUTPUT_DIR}/concat_dinov3_convnext"
        # Boş timestamp klasörünü temizle
        rmdir "models/${TIMESTAMP_1}" 2>/dev/null || true
    fi
else
    echo "[$(date)] ✗ CUB concat_dinov3_convnext failed (exit code: $EXIT_CODE)"
    FAILED_MODELS+=("cub_concat_dinov3_convnext")
fi

# 2. CUB: concat_all (tüm embeddingleri birleştir)
TIMESTAMP_2="${BASE_TIMESTAMP}_2"
echo "[$(date)] Starting CUB: concat_all..."
LOG_FILE="logs/missing_experiments/cub_concat_all_${BASE_TIMESTAMP}.log"
echo "=== Training started for CUB concat_all at $(date) ===" > "${LOG_FILE}"

# Construct the list of directories
CUB_EMBEDDING_DIRS=""
for model in "${MODELS[@]}"; do
    CUB_EMBEDDING_DIRS="$CUB_EMBEDDING_DIRS ${CUB_EMB_DIR}/$model"
done

echo "Command: python -u src/train_mlp.py --embedding_dirs $CUB_EMBEDDING_DIRS --batch_timestamp ${TIMESTAMP_2}" >> "${LOG_FILE}"
echo "" >> "${LOG_FILE}"

nohup python -u src/train_mlp.py \
    --embedding_dirs $CUB_EMBEDDING_DIRS \
    --batch_timestamp "${TIMESTAMP_2}" \
    >> "${LOG_FILE}" 2>&1

EXIT_CODE=$?
echo "" >> "${LOG_FILE}"
echo "=== Training finished at $(date) with exit code: $EXIT_CODE ===" >> "${LOG_FILE}"

if [ $EXIT_CODE -eq 0 ]; then
    echo "[$(date)] ✓ CUB concat_all completed successfully"
    # Modeli output klasörüne taşı
    if [ -d "models/${TIMESTAMP_2}/concatenated_all" ]; then
        mv "models/${TIMESTAMP_2}/concatenated_all" "${OUTPUT_DIR}/concat_all"
        echo "[$(date)] Model moved to ${OUTPUT_DIR}/concat_all"
        # Boş timestamp klasörünü temizle
        rmdir "models/${TIMESTAMP_2}" 2>/dev/null || true
    fi
else
    echo "[$(date)] ✗ CUB concat_all failed (exit code: $EXIT_CODE)"
    FAILED_MODELS+=("cub_concat_all")
fi

echo ""
echo "================================================================================"
echo "iNaturalist Missing Experiments"
echo "================================================================================"

# 3. iNat: concat_all (tüm embeddingleri birleştir)
TIMESTAMP_3="${BASE_TIMESTAMP}_3"
echo "[$(date)] Starting iNat: concat_all..."
LOG_FILE="logs/missing_experiments/inat_concat_all_${BASE_TIMESTAMP}.log"
echo "=== Training started for iNat concat_all at $(date) ===" > "${LOG_FILE}"

# Construct the list of directories
INAT_EMBEDDING_DIRS=""
for model in "${MODELS[@]}"; do
    INAT_EMBEDDING_DIRS="$INAT_EMBEDDING_DIRS ${INAT_EMB_DIR}/$model"
done

echo "Command: python -u src/train_mlp.py --embedding_dirs $INAT_EMBEDDING_DIRS --batch_timestamp ${TIMESTAMP_3}" >> "${LOG_FILE}"
echo "" >> "${LOG_FILE}"

nohup python -u src/train_mlp.py \
    --embedding_dirs $INAT_EMBEDDING_DIRS \
    --batch_timestamp "${TIMESTAMP_3}" \
    >> "${LOG_FILE}" 2>&1

EXIT_CODE=$?
echo "" >> "${LOG_FILE}"
echo "=== Training finished at $(date) with exit code: $EXIT_CODE ===" >> "${LOG_FILE}"

if [ $EXIT_CODE -eq 0 ]; then
    echo "[$(date)] ✓ iNat concat_all completed successfully"
    # Modeli output klasörüne taşı
    if [ -d "models/${TIMESTAMP_3}/concatenated_all" ]; then
        mv "models/${TIMESTAMP_3}/concatenated_all" "${OUTPUT_DIR}/inat_concat_all"
        echo "[$(date)] Model moved to ${OUTPUT_DIR}/inat_concat_all"
        # Boş timestamp klasörünü temizle
        rmdir "models/${TIMESTAMP_3}" 2>/dev/null || true
    fi
else
    echo "[$(date)] ✗ iNat concat_all failed (exit code: $EXIT_CODE)"
    FAILED_MODELS+=("inat_concat_all")
fi

# Özet
echo ""
echo "================================================================================"
echo "[$(date)] Missing Experiments Summary"
echo "================================================================================"
echo "Base timestamp: ${BASE_TIMESTAMP}"
echo "Output directory: ${OUTPUT_DIR}"
echo ""

if [ ${#FAILED_MODELS[@]} -eq 0 ]; then
    echo "✓ All missing experiments completed successfully!"
    echo ""
    echo "Results saved to: ${OUTPUT_DIR}"
    echo "  - CUB concat_dinov3_convnext: ${OUTPUT_DIR}/concat_dinov3_convnext"
    echo "  - CUB concat_all: ${OUTPUT_DIR}/concat_all"
    echo "  - iNat concat_all: ${OUTPUT_DIR}/inat_concat_all"
else
    echo "✗ Failed experiments: ${FAILED_MODELS[@]}"
    echo "  Check logs in logs/missing_experiments/ for details"
fi

echo ""
echo "Logs are saved to: logs/missing_experiments/"
echo "================================================================================"
echo "[$(date)] All missing experiments completed."
