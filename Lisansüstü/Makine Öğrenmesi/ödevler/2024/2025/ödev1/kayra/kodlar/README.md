# ML Ödev 1 — Lojistik Regresyon

İki sınav notundan yola çıkarak ikili lojistik regresyon modeli eğiten ve değerlendiren bir uygulama.

## Ders Bilgileri
- Ders: Makine Öğrenmesi
- Öğretim Üyesi: Mine Elif Karslıgil
- Öğrenci: Muhammed Kayra Bulut — 25501805

## Gereksinimlerin Kurulumu
Python paketlerini `requirements.txt` ile kurun.

```bash
python3 -m pip install --upgrade pip
python3 -m pip install -r requirements.txt
```

Gereksinimler:
- numpy
- pandas
- matplotlib

İsteğe bağlı: Sanal ortam kullanmak isterseniz:
```bash
python3 -m venv .venv
source .venv/bin/activate
python3 -m pip install -r requirements.txt
```

## Çalıştırma

### 1) Veri Parçalama
Veriyi tabakalı olarak Eğitim/Test/Doğrulama parçalarına bölmek için:

```bash
python3 split_data.py
```

İsteğe bağlı argümanlar:
```bash
python3 split_data.py -h
# örnek:
python3 split_data.py --input dataset/hw1Data.txt --train-frac 0.6 --test-frac 0.2 --val-frac 0.2 \
  --train-out dataset/train_data.csv --test-out dataset/test_data.csv --val-out dataset/validation_data.csv
```

### 2) Veri Görselleştirme
Saçılım grafiği üretmek için her veri kümesi üzerinde `visualize_data.py`’yi çalıştırın. Çıktı görselleri aynı dizin altında `gorseller/` klasörüne kaydedilir.

- Ham veri için:
```bash
python3 visualize_data.py dataset/hw1Data.txt
```

- Bölünmüş veriler için:
```bash
python3 visualize_data.py dataset/train_data.csv
python3 visualize_data.py dataset/validation_data.csv
python3 visualize_data.py dataset/test_data.csv
```

### 3) Eğitimi Çalıştırma (train.ipynb)
Notebook’u açıp tüm hücreleri çalıştırın. Alternatif olarak komut satırından otomatik çalıştırabilirsiniz:

```bash
python3 -m pip install jupyter
jupyter nbconvert --to notebook --execute train.ipynb --output train.executed.ipynb
```

Eğitim sonunda model ve ölçekleme istatistikleri `model_weights.npz` dosyasına kaydedilir; kayıp/başarım eğrileri `dataset/gorseller/egitim_dogrulama_olcutler.png` dosyasına yazılır.

### 4) Değerlendirmeyi Çalıştırma (test.ipynb)
Notebook’u açıp tüm hücreleri çalıştırın veya komut satırından:

```bash
jupyter nbconvert --to notebook --execute test.ipynb --output test.executed.ipynb
```

Eğitim/Doğrulama/Test bölümleri için ölçüt (accuracy, precision, recall, F1) sonuçları hesaplanır; her bölümün görseli `dataset/gorseller/` altına `train_olcutler.png`, `validation_olcutler.png`, `test_olcutler.png` olarak kaydedilir.

## Dosya Düzeni
- `dataset/`
  - `hw1Data.txt`: Ham veri (exam_1, exam_2, hired)
  - `train_data.csv`, `validation_data.csv`, `test_data.csv`: Bölünmüş veri dosyaları
  - `gorseller/`: Görsellerin kaydedildiği klasör
- `split_data.py`: Veriyi eğitim/test/doğrulama olarak tabakalı biçimde böler ve CSV’lere yazar
- `visualize_data.py`: Veriyi okuyup sınıfa göre renkli saçılım grafiği üretir
- `train.ipynb`: Lojistik regresyonu eğitir; kayıp ve başarım (ölçüt) eğrilerini üretir
- `test.ipynb`: Eğitim/Doğrulama/Test üzerinde ölçütleri hesaplar ve görselleştirir
- `model_weights.npz`: Eğitilmiş model ağırlıkları ile özellik ölçekleme istatistikleri
- `requirements.txt`: Python bağımlılıkları
- `README.md`: Bu belge