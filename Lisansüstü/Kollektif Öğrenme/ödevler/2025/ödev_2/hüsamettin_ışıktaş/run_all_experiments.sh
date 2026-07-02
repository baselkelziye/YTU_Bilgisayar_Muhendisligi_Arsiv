#!/usr/bin/env bash
set -euo pipefail

# Projenin kök dizinine gidip sanal ortamı etkinleştir.
PROJECT_ROOT="/home/husam/Desktop/YTU-YL/Kolektif Öğrenme/kolektif-ogrenme-odev2"
cd "$PROJECT_ROOT"
source .venv/bin/activate

# Embed boyutuna karşılık gelen dataset yolları.
# Gerekirse yeni varyantlar için bu eşlemeyi güncelle.
declare -A DATASETS=(
  [128]="dataset/128"
  [256]="dataset/256"
  [1024]="dataset/1024"
)
EMBED_SIZES=(128 256 1024)

# Her embed boyutu için çalıştırılacak runner scriptleri.
RUNNERS=(
  "run_random_forest.py"
  "run_bagging.py"
  "run_random_subspace.py"
  "run_mlp.py"
)

MASTER_TIMESTAMP="$(date +%Y-%m-%d_%H%M%S)"
LOG_ROOT="$PROJECT_ROOT/batch_logs"
LOG_DIR="$LOG_ROOT/$MASTER_TIMESTAMP"
mkdir -p "$LOG_DIR"
ACCURACY_LOG="$LOG_DIR/accuracy_records.csv"
: > "$ACCURACY_LOG"

echo "Log dizini: $LOG_DIR"

collect_metrics () {
  local metrics_file="$1"
  local runner_name="$2"
  local embed_size="$3"
  local dataset_path="$4"
  python - "$metrics_file" "$ACCURACY_LOG" "$runner_name" "$embed_size" "$dataset_path" <<'PY'
import csv
import json
import os
import sys
from typing import Dict, Any

metrics_path, csv_path, runner_name, embed_size, dataset_path = sys.argv[1:6]
if not os.path.isfile(metrics_path):
    sys.exit(0)

with open(metrics_path, "r", encoding="utf-8") as f:
    data: Dict[str, Any] = json.load(f)

meta = data.get("_meta", {})
timestamp = str(meta.get("timestamp", "unknown"))
embed = meta.get("embed_size", embed_size)
dataset_dir = meta.get("dataset_dir", dataset_path)

rows = []
for key, value in data.items():
    if key == "_meta":
        continue
    accuracy = value.get("accuracy")
    if accuracy is None:
        continue
    rows.append([timestamp, runner_name, embed, key, accuracy, dataset_dir])

if not rows:
    sys.exit(0)

need_header = not os.path.exists(csv_path) or os.path.getsize(csv_path) == 0
with open(csv_path, "a", newline="", encoding="utf-8") as csv_file:
    writer = csv.writer(csv_file)
    if need_header:
        writer.writerow(["timestamp", "runner", "embed_size", "dataset_split", "accuracy", "dataset_dir"])
    writer.writerows(rows)
PY
}

for EMBED_SIZE in "${EMBED_SIZES[@]}"; do
  DATASET_PATH="${DATASETS[$EMBED_SIZE]}"
  SANITIZED_DATASET="$(basename "$DATASET_PATH")"
  echo "============================================================"
  echo "Embedding boyutu: ${EMBED_SIZE} | Dataset: ${DATASET_PATH}"
  echo "Log klasörü: $LOG_DIR"
  echo "============================================================"

  for RUNNER in "${RUNNERS[@]}"; do
    RUNNER_BASE="${RUNNER%.py}"
    LOG_FILE="$LOG_DIR/${MASTER_TIMESTAMP}_${RUNNER_BASE}_${SANITIZED_DATASET}.txt"
    echo ">>> Çalıştırılıyor: ${RUNNER} (embed=${EMBED_SIZE}) | log: ${LOG_FILE}"
    if [[ "$RUNNER" == "run_mlp.py" ]]; then
      python "$RUNNER" --dataset "$DATASET_PATH" --embed-size "$EMBED_SIZE" 2>&1 | tee -a "$LOG_FILE"
    else
      python "$RUNNER" --dataset "$DATASET_PATH" --embed-size "$EMBED_SIZE" 2>&1 | tee -a "$LOG_FILE"
    fi

    LATEST_DIR="$(find "$PROJECT_ROOT/artifacts" -maxdepth 1 -type d -name "*_${RUNNER_BASE}" -printf '%T@ %p\n' 2>/dev/null | sort -nr | head -n1 | cut -d' ' -f2-)"
    if [[ -z "$LATEST_DIR" ]]; then
      echo "Uyarı: ${RUNNER_BASE} için artifacts dizini bulunamadı." | tee -a "$LOG_FILE"
      continue
    fi

    METRICS_FILE="$LATEST_DIR/metrics_summary.json"
    if [[ ! -f "$METRICS_FILE" ]]; then
      echo "Uyarı: metrics_summary.json bulunamadı: $METRICS_FILE" | tee -a "$LOG_FILE"
      continue
    fi

    collect_metrics "$METRICS_FILE" "$RUNNER_BASE" "$EMBED_SIZE" "$DATASET_PATH"
  done
done

if [[ -s "$ACCURACY_LOG" ]]; then
  python - "$ACCURACY_LOG" "$LOG_DIR/accuracy_comparison.txt" <<'PY'
import csv
import sys
from collections import defaultdict
from pathlib import Path

csv_path, output_path = sys.argv[1:3]
rows = []
with open(csv_path, newline="", encoding="utf-8") as csv_file:
    reader = csv.DictReader(csv_file)
    rows = list(reader)

if not rows:
    sys.exit(0)

best_by_dataset = {}
for row in rows:
    dataset = row["dataset_split"]
    accuracy = float(row["accuracy"])
    if dataset not in best_by_dataset or accuracy > best_by_dataset[dataset]["accuracy"]:
        best_by_dataset[dataset] = {
            "accuracy": accuracy,
            "runner": row["runner"],
            "embed_size": row["embed_size"],
            "timestamp": row["timestamp"],
        }

lines = [
    "ACCURACY KARŞILAŞTIRMASI",
    "========================",
    f"Toplam kayıt: {len(rows)}",
    "",
    "Verisetine göre en iyi sonuçlar:",
]

for dataset in sorted(best_by_dataset.keys()):
    record = best_by_dataset[dataset]
    lines.append(
        f"- {dataset}: {record['accuracy']:.4f} "
        f"({record['runner']} | embed={record['embed_size']} | ts={record['timestamp']})"
    )

overall_best = max(rows, key=lambda r: float(r["accuracy"]))
lines += [
    "",
    "Genel en iyi accuracy:",
    f"- {overall_best['dataset_split']}: {float(overall_best['accuracy']):.4f} "
    f"({overall_best['runner']} | embed={overall_best['embed_size']} | ts={overall_best['timestamp']})",
]

summary = "\n".join(lines)
print(summary)
Path(output_path).write_text(summary + "\n", encoding="utf-8")
PY
else
  echo "Accuracy kayıtları bulunamadı; karşılaştırma atlandı."
fi

