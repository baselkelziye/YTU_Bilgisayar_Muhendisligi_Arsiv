# Setup Guide (Phase 0)

## 1) Python environment

```bash
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements-dev.txt
```

## 2) Verify environment

```bash
python scripts/check_env.py
```

Successful runs generate:

- `artifacts/phase0/env_check_report.json`

## 3) Phase 0 expected artifacts

Data manifests:
- `data/raw/manifest_raw.csv`
- `data/processed/manifest_clean.csv`
- `data/processed/book_splits.csv`

Reports:
- `artifacts/phase0/data_quality_report.json`
- `artifacts/phase0/split_summary.json`
- `artifacts/phase0/env_check_report.json`

## 4) Run tests

```bash
pytest tests/test_data_pipeline.py
```
