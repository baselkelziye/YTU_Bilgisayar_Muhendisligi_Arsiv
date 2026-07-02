#!/bin/bash

# Sanal ortamı aktif et
source .venv/bin/activate

# Logs klasörünü oluştur
mkdir -p logs/cub

# Embedding klasörlerinin listesi
EMBEDDINGS=("convnext" "dinov2" "dinov3" "openclip" "siglip")

# Batch için timestamp oluştur
TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
echo "Batch training starting with timestamp: $TIMESTAMP"

# Individual trainings
for embedding in "${EMBEDDINGS[@]}"; do
    echo "[$(date)] Starting training for $embedding..."
    
    # Python scriptini çalıştır
    # Logları logs/ klasörüne kaydet
    python src/train_mlp.py \
        --embedding_dirs "embeddings/cub_200/$embedding" \
        --batch_timestamp "$TIMESTAMP" \
        > "logs/cub/mlp_${embedding}_${TIMESTAMP}.log" 2>&1
    
    if [ $? -eq 0 ]; then
        echo "[$(date)] Successfully finished $embedding"
    else
        echo "[$(date)] Failed training $embedding"
    fi
done

# Concatenated training
echo "[$(date)] Starting training for concatenated embeddings..."

# Construct the list of directories
EMBEDDING_DIRS=""
for embedding in "${EMBEDDINGS[@]}"; do
    EMBEDDING_DIRS="$EMBEDDING_DIRS embeddings/cub_200/$embedding"
done

python src/train_mlp.py \
    --embedding_dirs $EMBEDDING_DIRS \
    --batch_timestamp "$TIMESTAMP" \
    > "logs/cub/mlp_concatenated_${TIMESTAMP}.log" 2>&1

if [ $? -eq 0 ]; then
    echo "[$(date)] Successfully finished concatenated training"
else
    echo "[$(date)] Failed concatenated training"
fi

echo "[$(date)] All trainings completed."
