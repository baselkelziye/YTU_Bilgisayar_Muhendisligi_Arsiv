#!/bin/bash

# CUB veriseti için model training script
# models/20260110_173031 klasöründeki INAT modellerinin aynı kombinasyonlarını CUB ile train eder

# Sanal ortamı aktif et
source .venv/bin/activate

# Logs klasörünü oluştur
mkdir -p logs/cub

# Batch için timestamp oluştur
TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
echo "CUB Batch training starting with timestamp: $TIMESTAMP"

# CUB embeddings klasörü
CUB_EMB_DIR="embeddings/cub_200"

# Failed models listesi
FAILED_MODELS=()

# 1. convnext'i 1024'e indir (sum_dinov3_convnext1024 için gerekli)
echo "[$(date)] Checking if convnext reduced embeddings exist..."
CONVNEXT_REDUCED_DIR="${CUB_EMB_DIR}/convnext_reduced_1024"

if [ ! -f "${CONVNEXT_REDUCED_DIR}/train.pt" ] || [ ! -f "${CONVNEXT_REDUCED_DIR}/test.pt" ]; then
    echo "[$(date)] Reducing convnext embeddings to 1024 dimensions..."
    LOG_FILE="logs/cub/reduce_convnext_1024_${TIMESTAMP}.log"
    echo "=== ConvNext dimension reduction started at $(date) ===" > "${LOG_FILE}"
    echo "Command: python -u src/reduce_embedding_dimensions.py --embedding_dir ${CUB_EMB_DIR}/convnext --target_dim 1024 --method pca" >> "${LOG_FILE}"
    echo "" >> "${LOG_FILE}"
    
    nohup python -u src/reduce_embedding_dimensions.py \
        --embedding_dir "${CUB_EMB_DIR}/convnext" \
        --target_dim 1024 \
        --method pca \
        --output_dir "${CONVNEXT_REDUCED_DIR}" \
        >> "${LOG_FILE}" 2>&1
    
    EXIT_CODE=$?
    echo "" >> "${LOG_FILE}"
    echo "=== Dimension reduction finished at $(date) with exit code: $EXIT_CODE ===" >> "${LOG_FILE}"
    
    if [ $EXIT_CODE -eq 0 ]; then
        echo "[$(date)] Successfully reduced ConvNext to 1024 dimensions"
    else
        echo "[$(date)] Failed to reduce ConvNext dimensions. Check log: ${LOG_FILE}"
        exit 1
    fi
else
    echo "[$(date)] ConvNext reduced embeddings already exist at ${CONVNEXT_REDUCED_DIR}, skipping reduction"
fi

# 2. Tek model: dinov3
echo "[$(date)] Starting training for dinov3 (single model)..."
LOG_FILE="logs/cub/mlp_dinov3_${TIMESTAMP}.log"
echo "=== Training started for dinov3 at $(date) ===" > "${LOG_FILE}"
echo "Command: python -u src/train_mlp.py --embedding_dirs ${CUB_EMB_DIR}/dinov3 --batch_timestamp ${TIMESTAMP}" >> "${LOG_FILE}"
echo "" >> "${LOG_FILE}"

nohup python -u src/train_mlp.py \
    --embedding_dirs "${CUB_EMB_DIR}/dinov3" \
    --batch_timestamp "${TIMESTAMP}" \
    >> "${LOG_FILE}" 2>&1

DINOV3_EXIT=$?
echo "" >> "${LOG_FILE}"
echo "=== Training finished at $(date) with exit code: $DINOV3_EXIT ===" >> "${LOG_FILE}"

if [ $DINOV3_EXIT -eq 0 ]; then
    echo "[$(date)] ✓ dinov3 training completed successfully"
else
    echo "[$(date)] ✗ dinov3 training failed (exit code: $DINOV3_EXIT)"
    FAILED_MODELS+=("dinov3")
fi

# 3. Concat modelleri train et
echo "[$(date)] Starting training for concat_dinov3_convnext..."
LOG_FILE="logs/cub/mlp_concat_dinov3_convnext_${TIMESTAMP}.log"
echo "=== Training started for concat_dinov3_convnext at $(date) ===" > "${LOG_FILE}"
echo "Command: python -u src/train_mlp.py --embedding_dirs ${CUB_EMB_DIR}/dinov3 ${CUB_EMB_DIR}/convnext --batch_timestamp ${TIMESTAMP}" >> "${LOG_FILE}"
echo "" >> "${LOG_FILE}"

nohup python -u src/train_mlp.py \
    --embedding_dirs "${CUB_EMB_DIR}/dinov3" "${CUB_EMB_DIR}/convnext" \
    --batch_timestamp "${TIMESTAMP}" \
    >> "${LOG_FILE}" 2>&1

CONCAT_DINOV3_CONVNEXT_EXIT=$?
echo "" >> "${LOG_FILE}"
echo "=== Training finished at $(date) with exit code: $CONCAT_DINOV3_CONVNEXT_EXIT ===" >> "${LOG_FILE}"

if [ $CONCAT_DINOV3_CONVNEXT_EXIT -eq 0 ]; then
    echo "[$(date)] ✓ concat_dinov3_convnext training completed successfully"
else
    echo "[$(date)] ✗ concat_dinov3_convnext training failed (exit code: $CONCAT_DINOV3_CONVNEXT_EXIT)"
    FAILED_MODELS+=("concat_dinov3_convnext")
fi

echo "[$(date)] Starting training for concat_dinov3_dinov2..."
LOG_FILE="logs/cub/mlp_concat_dinov3_dinov2_${TIMESTAMP}.log"
echo "=== Training started for concat_dinov3_dinov2 at $(date) ===" > "${LOG_FILE}"
echo "Command: python -u src/train_mlp.py --embedding_dirs ${CUB_EMB_DIR}/dinov3 ${CUB_EMB_DIR}/dinov2 --batch_timestamp ${TIMESTAMP}" >> "${LOG_FILE}"
echo "" >> "${LOG_FILE}"

nohup python -u src/train_mlp.py \
    --embedding_dirs "${CUB_EMB_DIR}/dinov3" "${CUB_EMB_DIR}/dinov2" \
    --batch_timestamp "${TIMESTAMP}" \
    >> "${LOG_FILE}" 2>&1

CONCAT_DINOV3_DINOV2_EXIT=$?
echo "" >> "${LOG_FILE}"
echo "=== Training finished at $(date) with exit code: $CONCAT_DINOV3_DINOV2_EXIT ===" >> "${LOG_FILE}"

if [ $CONCAT_DINOV3_DINOV2_EXIT -eq 0 ]; then
    echo "[$(date)] ✓ concat_dinov3_dinov2 training completed successfully"
else
    echo "[$(date)] ✗ concat_dinov3_dinov2 training failed (exit code: $CONCAT_DINOV3_DINOV2_EXIT)"
    FAILED_MODELS+=("concat_dinov3_dinov2")
fi

# 4. Sum modelleri train et
echo "[$(date)] Starting training for sum_dinov3_dinov2..."
LOG_FILE="logs/cub/mlp_sum_dinov3_dinov2_${TIMESTAMP}.log"
echo "=== Training started for sum_dinov3_dinov2 at $(date) ===" > "${LOG_FILE}"
echo "Command: python -u src/train_mlp_sum.py --embedding_dirs ${CUB_EMB_DIR}/dinov3 ${CUB_EMB_DIR}/dinov2 --batch_timestamp ${TIMESTAMP}" >> "${LOG_FILE}"
echo "" >> "${LOG_FILE}"

nohup python -u src/train_mlp_sum.py \
    --embedding_dirs "${CUB_EMB_DIR}/dinov3" "${CUB_EMB_DIR}/dinov2" \
    --batch_timestamp "${TIMESTAMP}" \
    >> "${LOG_FILE}" 2>&1

SUM_DINOV3_DINOV2_EXIT=$?
echo "" >> "${LOG_FILE}"
echo "=== Training finished at $(date) with exit code: $SUM_DINOV3_DINOV2_EXIT ===" >> "${LOG_FILE}"

if [ $SUM_DINOV3_DINOV2_EXIT -eq 0 ]; then
    echo "[$(date)] ✓ sum_dinov3_dinov2 training completed successfully"
else
    echo "[$(date)] ✗ sum_dinov3_dinov2 training failed (exit code: $SUM_DINOV3_DINOV2_EXIT)"
    FAILED_MODELS+=("sum_dinov3_dinov2")
fi

echo "[$(date)] Starting training for sum_dinov3_convnext1024..."
LOG_FILE="logs/cub/mlp_sum_dinov3_convnext1024_${TIMESTAMP}.log"
echo "=== Training started for sum_dinov3_convnext1024 at $(date) ===" > "${LOG_FILE}"
echo "Command: python -u src/train_mlp_sum.py --embedding_dirs ${CUB_EMB_DIR}/dinov3 ${CONVNEXT_REDUCED_DIR} --batch_timestamp ${TIMESTAMP}" >> "${LOG_FILE}"
echo "" >> "${LOG_FILE}"

nohup python -u src/train_mlp_sum.py \
    --embedding_dirs "${CUB_EMB_DIR}/dinov3" "${CONVNEXT_REDUCED_DIR}" \
    --batch_timestamp "${TIMESTAMP}" \
    >> "${LOG_FILE}" 2>&1

SUM_DINOV3_CONVNEXT1024_EXIT=$?
echo "" >> "${LOG_FILE}"
echo "=== Training finished at $(date) with exit code: $SUM_DINOV3_CONVNEXT1024_EXIT ===" >> "${LOG_FILE}"

if [ $SUM_DINOV3_CONVNEXT1024_EXIT -eq 0 ]; then
    echo "[$(date)] ✓ sum_dinov3_convnext1024 training completed successfully"
else
    echo "[$(date)] ✗ sum_dinov3_convnext1024 training failed (exit code: $SUM_DINOV3_CONVNEXT1024_EXIT)"
    FAILED_MODELS+=("sum_dinov3_convnext1024")
fi

# Training fazı tamamlandı
echo "[$(date)] Training phase completed."
MODELS_DIR="models/${TIMESTAMP}"

# 5. Ensemble modelleri oluştur (sadece başarılı modeller için)
echo "[$(date)] Starting ensemble model creation..."

# Ensemble 1: dinov3 + dinov2 (models/20260106_000359 klasöründen)
if [ -d "models/20260106_000359/dinov3" ] && [ -d "models/20260106_000359/dinov2" ]; then
    echo "[$(date)] Creating ensemble_dinov3_dinov2..."
    LOG_FILE="logs/cub/ensemble_dinov3_dinov2_${TIMESTAMP}.log"
    echo "=== Ensemble started for dinov3+dinov2 at $(date) ===" > "${LOG_FILE}"
    echo "Command: python -u src/ensemble_models.py --model_dirs models/20260106_000359/dinov3 models/20260106_000359/dinov2 --use_f1_weights" >> "${LOG_FILE}"
    echo "" >> "${LOG_FILE}"
    
    nohup python -u src/ensemble_models.py \
        --model_dirs "models/20260106_000359/dinov3" "models/20260106_000359/dinov2" \
        --use_f1_weights \
        --batch_size 128 \
        --split test \
        --output_dir "${MODELS_DIR}/ensemble_dinov3_dinov2" \
        >> "${LOG_FILE}" 2>&1
    
    ENSEMBLE_DINOV3_DINOV2_EXIT=$?
    echo "" >> "${LOG_FILE}"
    echo "=== Ensemble finished at $(date) with exit code: $ENSEMBLE_DINOV3_DINOV2_EXIT ===" >> "${LOG_FILE}"
    
    if [ $ENSEMBLE_DINOV3_DINOV2_EXIT -eq 0 ]; then
        echo "[$(date)] ✓ ensemble_dinov3_dinov2 completed"
    else
        echo "[$(date)] ✗ ensemble_dinov3_dinov2 failed"
    fi
else
    echo "[$(date)] Warning: models/20260106_000359/dinov3 or dinov2 not found, skipping ensemble_dinov3_dinov2"
fi

# Ensemble 2: dinov3 + convnext
if [ -d "models/20260106_000359/dinov3" ] && [ -d "models/20260106_000359/convnext" ]; then
    echo "[$(date)] Creating ensemble_dinov3_convnext..."
    LOG_FILE="logs/cub/ensemble_dinov3_convnext_${TIMESTAMP}.log"
    echo "=== Ensemble started for dinov3+convnext at $(date) ===" > "${LOG_FILE}"
    echo "Command: python -u src/ensemble_models.py --model_dirs models/20260106_000359/dinov3 models/20260106_000359/convnext --use_f1_weights" >> "${LOG_FILE}"
    echo "" >> "${LOG_FILE}"
    
    nohup python -u src/ensemble_models.py \
        --model_dirs "models/20260106_000359/dinov3" "models/20260106_000359/convnext" \
        --use_f1_weights \
        --batch_size 128 \
        --split test \
        --output_dir "${MODELS_DIR}/ensemble_dinov3_convnext" \
        >> "${LOG_FILE}" 2>&1
    
    ENSEMBLE_DINOV3_CONVNEXT_EXIT=$?
    echo "" >> "${LOG_FILE}"
    echo "=== Ensemble finished at $(date) with exit code: $ENSEMBLE_DINOV3_CONVNEXT_EXIT ===" >> "${LOG_FILE}"
    
    if [ $ENSEMBLE_DINOV3_CONVNEXT_EXIT -eq 0 ]; then
        echo "[$(date)] ✓ ensemble_dinov3_convnext completed"
    else
        echo "[$(date)] ✗ ensemble_dinov3_convnext failed"
    fi
else
    echo "[$(date)] Warning: models/20260106_000359/dinov3 or convnext not found, skipping ensemble_dinov3_convnext"
fi

# Ensemble 3: dinov3 + dinov2 + convnext
if [ -d "models/20260106_000359/dinov3" ] && [ -d "models/20260106_000359/dinov2" ] && [ -d "models/20260106_000359/convnext" ]; then
    echo "[$(date)] Creating ensemble_dinov3_dinov2_convnext..."
    LOG_FILE="logs/cub/ensemble_dinov3_dinov2_convnext_${TIMESTAMP}.log"
    echo "=== Ensemble started for dinov3+dinov2+convnext at $(date) ===" > "${LOG_FILE}"
    echo "Command: python -u src/ensemble_models.py --model_dirs models/20260106_000359/dinov3 models/20260106_000359/dinov2 models/20260106_000359/convnext --use_f1_weights" >> "${LOG_FILE}"
    echo "" >> "${LOG_FILE}"
    
    nohup python -u src/ensemble_models.py \
        --model_dirs "models/20260106_000359/dinov3" "models/20260106_000359/dinov2" "models/20260106_000359/convnext" \
        --use_f1_weights \
        --batch_size 128 \
        --split test \
        --output_dir "${MODELS_DIR}/ensemble_dinov3_dinov2_convnext" \
        >> "${LOG_FILE}" 2>&1
    
    ENSEMBLE_DINOV3_DINOV2_CONVNEXT_EXIT=$?
    echo "" >> "${LOG_FILE}"
    echo "=== Ensemble finished at $(date) with exit code: $ENSEMBLE_DINOV3_DINOV2_CONVNEXT_EXIT ===" >> "${LOG_FILE}"
    
    if [ $ENSEMBLE_DINOV3_DINOV2_CONVNEXT_EXIT -eq 0 ]; then
        echo "[$(date)] ✓ ensemble_dinov3_dinov2_convnext completed"
    else
        echo "[$(date)] ✗ ensemble_dinov3_dinov2_convnext failed"
    fi
else
    echo "[$(date)] Warning: Required models for ensemble_dinov3_dinov2_convnext not found, skipping"
fi

# Ensemble 4: Tüm modeller (models/20260106_000359 klasöründen)
if [ -d "models/20260106_000359/dinov3" ] && [ -d "models/20260106_000359/dinov2" ] && [ -d "models/20260106_000359/convnext" ] && [ -d "models/20260106_000359/openclip" ] && [ -d "models/20260106_000359/siglip" ]; then
    echo "[$(date)] Creating ensemble_all..."
    LOG_FILE="logs/cub/ensemble_all_${TIMESTAMP}.log"
    echo "=== Ensemble started for all models at $(date) ===" > "${LOG_FILE}"
    echo "Command: python -u src/ensemble_models.py --model_dirs models/20260106_000359/dinov3 models/20260106_000359/dinov2 models/20260106_000359/convnext models/20260106_000359/openclip models/20260106_000359/siglip --use_f1_weights" >> "${LOG_FILE}"
    echo "" >> "${LOG_FILE}"
    
    nohup python -u src/ensemble_models.py \
        --model_dirs "models/20260106_000359/dinov3" "models/20260106_000359/dinov2" "models/20260106_000359/convnext" "models/20260106_000359/openclip" "models/20260106_000359/siglip" \
        --use_f1_weights \
        --batch_size 128 \
        --split test \
        --output_dir "${MODELS_DIR}/ensemble_all" \
        >> "${LOG_FILE}" 2>&1
    
    ENSEMBLE_ALL_EXIT=$?
    echo "" >> "${LOG_FILE}"
    echo "=== Ensemble finished at $(date) with exit code: $ENSEMBLE_ALL_EXIT ===" >> "${LOG_FILE}"
    
    if [ $ENSEMBLE_ALL_EXIT -eq 0 ]; then
        echo "[$(date)] ✓ ensemble_all completed"
    else
        echo "[$(date)] ✗ ensemble_all failed"
    fi
else
    echo "[$(date)] Warning: Not all models found in models/20260106_000359, skipping ensemble_all"
fi

# 6. Sonuçları karşılaştır
if [ -d "${MODELS_DIR}" ]; then
    echo "[$(date)] Generating comparison plots and summary..."
    LOG_FILE="logs/cub/compare_results_${TIMESTAMP}.log"
    echo "=== Comparison started at $(date) ===" > "${LOG_FILE}"
    echo "Command: python -u src/compare_results.py --models_dir ${MODELS_DIR}" >> "${LOG_FILE}"
    echo "" >> "${LOG_FILE}"
    
    python -u src/compare_results.py \
        --models_dir "${MODELS_DIR}" \
        >> "${LOG_FILE}" 2>&1
    
    EXIT_CODE=$?
    echo "" >> "${LOG_FILE}"
    echo "=== Comparison finished at $(date) with exit code: $EXIT_CODE ===" >> "${LOG_FILE}"
    
    if [ $EXIT_CODE -eq 0 ]; then
        echo "[$(date)] ✓ Comparison completed successfully"
    else
        echo "[$(date)] ✗ Comparison failed (exit code: $EXIT_CODE)"
    fi
fi

# Özet
echo ""
echo "================================================================================"
echo "[$(date)] CUB Model Training Summary"
echo "================================================================================"
echo "Timestamp: ${TIMESTAMP}"
echo "Models directory: ${MODELS_DIR}"
echo ""

if [ ${#FAILED_MODELS[@]} -eq 0 ]; then
    echo "✓ All training jobs completed successfully!"
else
    echo "✗ Failed models: ${FAILED_MODELS[@]}"
    echo "  Check logs in logs/cub/ for details"
fi

echo ""
echo "Results are saved to: ${MODELS_DIR}"
echo "Logs are saved to: logs/cub/"
echo "================================================================================"
echo "[$(date)] All CUB training experiments completed."

