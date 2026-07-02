#!/bin/bash

# Sanal ortamı aktif et
source .venv/bin/activate

# Logs klasörünü oluştur
mkdir -p logs/inat

# Embedding modellerinin listesi (extract_all_embeddings_inat.sh ile uyumlu)
MODELS=("convnext" "dinov2" "dinov3" "openclip" "siglip")

# Batch için timestamp oluştur
TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
echo "iNaturalist Batch training starting with timestamp: $TIMESTAMP"

# Individual trainings
for model in "${MODELS[@]}"; do
    echo "[$(date)] Starting training for $model (iNaturalist)..."
    
    LOG_FILE="logs/inat/mlp_${model}_${TIMESTAMP}.log"
    
    # Log dosyasına başlangıç mesajı yaz (process başlamadan önce)
    {
        echo "=== Training started for $model at $(date) ==="
        echo "Command: python -u src/train_mlp.py --embedding_dirs embeddings/inaturalist_2021/$model --batch_timestamp $TIMESTAMP"
        echo ""
        
        # Python scriptini unbuffered modda çalıştır (-u flag)
        python -u src/train_mlp.py \
            --embedding_dirs "embeddings/inaturalist_2021/$model" \
            --batch_timestamp "$TIMESTAMP"
    } > "$LOG_FILE" 2>&1
    
    EXIT_CODE=$?
    
    # Exit code'u log dosyasına ekle
    echo "" >> "$LOG_FILE"
    echo "=== Training finished for $model at $(date) with exit code: $EXIT_CODE ===" >> "$LOG_FILE"
    
    if [ $EXIT_CODE -eq 0 ]; then
        echo "[$(date)] Successfully finished $model"
    else
        echo "[$(date)] Failed training $model (exit code: $EXIT_CODE)"
    fi
done

# Concatenated training
echo "[$(date)] Starting training for concatenated embeddings (iNaturalist)..."

# Construct the list of directories
EMBEDDING_DIRS=""
for model in "${MODELS[@]}"; do
    EMBEDDING_DIRS="$EMBEDDING_DIRS embeddings/inaturalist_2021/$model"
done

LOG_FILE="logs/inat/mlp_concatenated_${TIMESTAMP}.log"

# Log dosyasına başlangıç mesajı yaz (process başlamadan önce)
{
    echo "=== Concatenated training started at $(date) ==="
    echo "Command: python -u src/train_mlp.py --embedding_dirs $EMBEDDING_DIRS --batch_timestamp $TIMESTAMP"
    echo ""
    
    python -u src/train_mlp.py \
        --embedding_dirs $EMBEDDING_DIRS \
        --batch_timestamp "$TIMESTAMP"
} > "$LOG_FILE" 2>&1

EXIT_CODE=$?

# Exit code'u log dosyasına ekle
echo "" >> "$LOG_FILE"
echo "=== Concatenated training finished at $(date) with exit code: $EXIT_CODE ===" >> "$LOG_FILE"

if [ $EXIT_CODE -eq 0 ]; then
    echo "[$(date)] Successfully finished concatenated training"
else
    echo "[$(date)] Failed concatenated training (exit code: $EXIT_CODE)"
fi

echo "[$(date)] All iNaturalist trainings completed."

