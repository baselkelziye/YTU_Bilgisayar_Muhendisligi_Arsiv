# FAZ 3 - Hafif MLP Profil Siniflandirici Egitimi

Bu fazin amaci, Faz 1'de uretilen guvenilir profil etiketlerini hizli inference feature'lariyla ogrenebilen kucuk bir MLP modeli egitmek ve Faz 4'e deploy edilmeye hazir model artefaktlarini uretmektir.

## Faz Kapsami

- Fast feature dataset hazirlama
- 2-layer MLP model tanimi ve egitimi
- Validasyon ve hata analizi
- Model + scaler + label mapping paketleme

## Yapilacaklar

- Faz 1 `filtered_dataset.parquet` verisini yukle.
- Set B feature'larini egitim formatina donustur.
- Train/val/test ayirimi (%80/%10/%10) yap.
- Feature standardization'i yalnizca training split'te ogren.
- MLP mimarisini kur:
  - `Linear(input_dim -> 32) + ReLU + Dropout(0.1) + Linear(32 -> num_profiles)`
- Loss ve optimizer ayarla:
  - CrossEntropyLoss + AdamW (`lr=1e-3`, `weight_decay=1e-4`)
- Early stopping (patience=7) ile egitimi tamamla.
- Accuracy, macro F1, top-3 accuracy, inference time metriklerini olc.
- Sinif bazli hata analizi ve confusion matrix uret.

## Olusturulmasi Gereken Dosyalar

- `src/models/profile_mlp.py`
  - 2-layer MLP model tanimi.
- `src/models/train_profile_mlp.py`
  - Egitim dongusu, validasyon ve checkpoint mekanizmasi.
- `src/models/evaluate_profile_mlp.py`
  - Test metrikleri ve detayli performans analizi.
- `src/models/model_io.py`
  - Model/scaler/label_map kaydetme-yukleme yardimcilari.
- `src/features/fast_feature_dataset.py`
  - Set B feature tablosundan model-ready dataset uretimi.
- `tests/test_model_forward.py`
  - MLP input-output sekil ve forward testleri.
- `tests/test_model_io.py`
  - Model artefakti kaydet/yukle tutarlilik testleri.
- `artifacts/phase3/model.pt`
  - Egitilmis MLP agirliklari.
- `artifacts/phase3/scaler.pkl`
  - Feature standardization parametreleri.
- `artifacts/phase3/label_map.json`
  - `class_index <-> profile_id` eslesmesi.
- `artifacts/phase3/train_history.csv`
  - Epoch bazli train/val loss ve metrikler.
- `artifacts/phase3/metrics.json`
  - Nihai model metrik ozetleri.
- `artifacts/phase3/confusion_matrix.csv`
  - Profil bazli hata dagilimi.
- `artifacts/phase3/training_report.md`
  - Egitim sureci, hedeflere gore sonuc degerlendirmesi.

## Dosyalarin Amaclari

- `profile_mlp.py`: Faz 4'te runtime'da cagrilacak nihai siniflandirici yapisini tanimlar.
- `model.pt` + `scaler.pkl` + `label_map.json`: Inference icin zorunlu deploy paketidir.
- `metrics.json` ve `confusion_matrix.csv`: Model kalite kontrolu ve iyilestirme kararlarini besler.
- `training_report.md`: Akademik/final rapora direkt tasinabilir egitim kanitlarini toplar.

## Faz Giris/Kabul Kriterleri

- Hedef metriklere ulasilmali:
  - Accuracy > %85
  - Macro F1 > %82
  - Top-3 Accuracy > %95
  - Inference < 2ms/blok (feature + model)
- Model artefaktlari tekrar yuklenebilir ve deterministic sekilde calisabilir olmali.
- Faz 4 pipeline'i model dosyalarini dogrudan tuketebilmeli.

## Faz Ciktilari

- Egitilmis hafif profil siniflandirici
- Inference icin deploy edilebilir model paketleri
- Egitim ve performans dokumantasyonu
