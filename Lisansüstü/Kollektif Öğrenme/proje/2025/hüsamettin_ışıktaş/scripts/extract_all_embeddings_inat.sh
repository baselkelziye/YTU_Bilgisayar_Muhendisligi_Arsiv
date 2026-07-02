#!/bin/bash

# Sanal ortamı aktif et
source .venv/bin/activate

# Logs klasörünü oluştur
mkdir -p logs/inat

# Embedding modellerinin listesi
MODELS=("dinov3" "openclip" "siglip")

echo "Starting iNaturalist embedding extraction for all models..."

for model in "${MODELS[@]}"; do
    echo "[$(date)] Extracting embeddings for $model..."
    
    # Python scriptini çalıştır (iNaturalist için)
    # Logları logs/ klasörüne kaydet ve ekrana da bas (tee ile)
    # batch_size 32 olarak ayarlandı, gerekirse artırılabilir
    python -u src/extract_embeddings_inat.py --model "$model" --batch_size 128 2>&1 | tee "logs/inat/extract_${model}.log"
    
    # tee kullandığımız için exit code'u almak adına PIPESTATUS kullanmalıyız
    if [ ${PIPESTATUS[0]} -eq 0 ]; then
        echo "[$(date)] Successfully finished $model"
    else
        echo "[$(date)] Failed extracting $model. Check logs/inat/extract_${model}.log for details."
    fi
done

echo "[$(date)] All iNaturalist extractions completed."

