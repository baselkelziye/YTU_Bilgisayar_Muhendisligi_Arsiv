#!/bin/bash

# Sanal ortamı aktif et
source .venv/bin/activate

# Logs klasörünü oluştur
mkdir -p logs/cub

# Embedding modellerinin listesi
MODELS=("convnext" "dinov2" "dinov3" "openclip" "siglip")

echo "Starting embedding extraction for all models..."

for model in "${MODELS[@]}"; do
    echo "[$(date)] Extracting embeddings for $model..."
    
    # Python scriptini çalıştır
    # Logları logs/ klasörüne kaydet
    python src/extract_embeddings.py --model "$model" --batch_size 32 > "logs/cub/extract_${model}.log" 2>&1
    
    if [ $? -eq 0 ]; then
        echo "[$(date)] Successfully finished $model"
    else
        echo "[$(date)] Failed extracting $model"
    fi
done

echo "[$(date)] All extractions completed."

