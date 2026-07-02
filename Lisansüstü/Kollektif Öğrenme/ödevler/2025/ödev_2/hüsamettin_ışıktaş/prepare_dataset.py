"""
Veriseti Hazırlama Scripti

Bu script:
1. Yerel turkish-academic-theses-dataset verisetini kullanır
2. 2000-2024 yılları arasındaki tezlerden her yıl için 500 tez seçer (rastgele)
3. Her yıldan 250 tez eğitim, 250 tez test için ayrılır
4. Sonuç verisetleri dataset/ klasörüne kaydedilir
"""

import os
import random
from datasets import Dataset, DatasetDict
import pandas as pd
from collections import Counter

# Sabit random seed - tekrarlanabilirlik için
RANDOM_SEED = 42
random.seed(RANDOM_SEED)

# Yıl aralığı
START_YEAR = 2000
END_YEAR = 2024

# Her yıl için seçilecek tez sayısı
THESES_PER_YEAR = 500
TRAIN_PER_YEAR = 250
TEST_PER_YEAR = 250

# Girdi/çıktı dizinleri
RAW_DATASET_PATH = os.path.join("datasets", "tezler.parquet")
OUTPUT_DIR = "dataset"


def load_thesis_dataset():
    """
    Yerel parquet dosyasından tez verisetini yükler.
    
    Returns:
        list[dict]: Yüklenen verisetinin kayıt listesi
    """
    print("Yerel tez veriseti yükleniyor...")
    
    if not os.path.exists(RAW_DATASET_PATH):
        raise FileNotFoundError(
            f"Beklenen veriseti bulunamadı: {RAW_DATASET_PATH}. "
            "Lütfen dosyayı datasets/ klasörüne yerleştirin."
        )
    
    df = pd.read_parquet(RAW_DATASET_PATH)
    print(f"Veriseti yüklendi. Toplam kayıt sayısı: {len(df)}")
    
    # Huggingface Dataset yapısına benzer kullanım için kayıt listesini döndür
    return df.to_dict(orient="records")


def filter_by_years(dataset, start_year, end_year):
    """
    Verisetini belirli yıl aralığına göre filtreler.
    
    Args:
        dataset: Filtrelenecek veriseti
        start_year: Başlangıç yılı (dahil)
        end_year: Bitiş yılı (dahil)
    
    Returns:
        dict: Yıllara göre gruplandırılmış tezler
    """
    print(f"\n{start_year}-{end_year} yılları arasındaki tezler filtreleniyor...")
    
    # Yıllara göre grupla
    theses_by_year = {year: [] for year in range(start_year, end_year + 1)}
    
    for idx, item in enumerate(dataset):
        year = item['year']
        if year and start_year <= year <= end_year:
            theses_by_year[year].append(idx)
    
    # Her yıl için istatistik göster
    print("\nYıllara göre mevcut tez sayıları:")
    for year in range(start_year, end_year + 1):
        count = len(theses_by_year[year])
        status = "✓" if count >= THESES_PER_YEAR else "⚠"
        print(f"  {year}: {count} tez {status}")
    
    return theses_by_year


def sample_theses(dataset, theses_by_year):
    """
    Her yıldan belirtilen sayıda rastgele tez seçer ve train/test olarak ayırır.
    
    Args:
        dataset: Ana veriseti
        theses_by_year: Yıllara göre gruplandırılmış tez indeksleri
    
    Returns:
        tuple: (train_data, test_data) - Seçilmiş tezlerin listesi
    """
    print(f"\nHer yıldan {THESES_PER_YEAR} tez seçiliyor...")
    
    train_data = []
    test_data = []
    
    for year in range(START_YEAR, END_YEAR + 1):
        available_indices = theses_by_year[year]
        
        if len(available_indices) < THESES_PER_YEAR:
            print(f"  ⚠ {year} yılı için yeterli tez yok ({len(available_indices)}/{THESES_PER_YEAR})")
            # Mevcut tüm tezleri kullan, yetersiz kalan kısmı atla
            selected_indices = available_indices.copy()
        else:
            # Rastgele seçim yap
            selected_indices = random.sample(available_indices, THESES_PER_YEAR)
        
        # Seçilen tezleri karıştır
        random.shuffle(selected_indices)
        
        # Train ve test olarak ayır (eşit olarak)
        # Eğer yeterli tez varsa TRAIN_PER_YEAR ve TEST_PER_YEAR kadar ayır
        # Eğer yetersizse, mevcut tezleri eşit olarak böl
        if len(selected_indices) >= THESES_PER_YEAR:
            train_count = TRAIN_PER_YEAR
            test_count = TEST_PER_YEAR
        else:
            # Yetersiz tez varsa eşit olarak böl
            train_count = len(selected_indices) // 2
            test_count = len(selected_indices) - train_count
        
        train_indices = selected_indices[:train_count]
        test_indices = selected_indices[train_count:train_count + test_count]
        
        # Veri ekle
        for idx in train_indices:
            item = dataset[idx]
            train_data.append({
                'tez_no': item['tez_no'],
                'title_tr': item['title_tr'] or "",
                'title_en': item['title_en'] or "",
                'abstract_tr': item['abstract_tr'] or "",
                'abstract_en': item['abstract_en'] or "",
                'author': item['author'] or "",
                'advisor': item['advisor'] or "",
                'location': item['location'] or "",
                'subject': item['subject'] or "",
                'degree': item['degree'] or "",
                'year': item['year']
            })
        
        for idx in test_indices:
            item = dataset[idx]
            test_data.append({
                'tez_no': item['tez_no'],
                'title_tr': item['title_tr'] or "",
                'title_en': item['title_en'] or "",
                'abstract_tr': item['abstract_tr'] or "",
                'abstract_en': item['abstract_en'] or "",
                'author': item['author'] or "",
                'advisor': item['advisor'] or "",
                'location': item['location'] or "",
                'subject': item['subject'] or "",
                'degree': item['degree'] or "",
                'year': item['year']
            })
        
        print(f"  {year}: {len(train_indices)} train, {len(test_indices)} test")
    
    return train_data, test_data


def save_datasets(train_data, test_data, output_dir):
    """
    Verisetlerini Huggingface Dataset formatında kaydeder.
    
    Args:
        train_data: Eğitim verisi
        test_data: Test verisi
        output_dir: Kayıt dizini
    """
    print(f"\nVerisetleri {output_dir}/ klasörüne kaydediliyor...")
    
    # Dizini oluştur
    os.makedirs(output_dir, exist_ok=True)
    
    # DataFrame'e dönüştür
    train_df = pd.DataFrame(train_data)
    test_df = pd.DataFrame(test_data)
    
    # Dataset'e dönüştür
    train_dataset = Dataset.from_pandas(train_df)
    test_dataset = Dataset.from_pandas(test_df)
    
    # DatasetDict oluştur
    dataset_dict = DatasetDict({
        'train': train_dataset,
        'test': test_dataset
    })
    
    # Kaydet
    dataset_dict.save_to_disk(os.path.join(output_dir, "thesis_dataset"))
    
    # CSV olarak da kaydet (inceleme kolaylığı için)
    train_df.to_csv(os.path.join(output_dir, "train.csv"), index=False)
    test_df.to_csv(os.path.join(output_dir, "test.csv"), index=False)
    
    print(f"  ✓ Huggingface Dataset: {output_dir}/thesis_dataset/")
    print(f"  ✓ CSV: {output_dir}/train.csv, {output_dir}/test.csv")


def generate_dataset_info(train_data, test_data, output_dir):
    """
    Veriseti hakkında bilgi dosyası oluşturur.
    
    Args:
        train_data: Eğitim verisi
        test_data: Test verisi
        output_dir: Kayıt dizini
    """
    print("\nVeriseti bilgi dosyası oluşturuluyor...")
    
    train_df = pd.DataFrame(train_data)
    test_df = pd.DataFrame(test_data)
    
    # Yıl dağılımı
    train_year_dist = Counter(train_df['year'])
    test_year_dist = Counter(test_df['year'])
    
    # Derece dağılımı
    train_degree_dist = Counter(train_df['degree'])
    test_degree_dist = Counter(test_df['degree'])
    
    info_text = f"""# Veriseti Bilgileri

## Genel Bilgiler

- **Kaynak**: [turkish-academic-theses-dataset](https://huggingface.co/datasets/umutertugrul/turkish-academic-theses-dataset)
- **Yıl Aralığı**: {START_YEAR}-{END_YEAR}
- **Toplam Kayıt Sayısı**: {len(train_data) + len(test_data)}
- **Eğitim Seti Boyutu**: {len(train_data)}
- **Test Seti Boyutu**: {len(test_data)}
- **Random Seed**: {RANDOM_SEED}

## Sütunlar

| Sütun | Açıklama |
|-------|----------|
| tez_no | Tez numarası (YÖK'teki benzersiz tanımlayıcı) |
| title_tr | Türkçe tez başlığı |
| title_en | İngilizce tez başlığı |
| abstract_tr | Türkçe özet |
| abstract_en | İngilizce özet |
| author | Yazar adı |
| advisor | Danışman adı |
| location | Kurum bilgisi (üniversite/enstitü/bölüm) |
| subject | Konu alanı |
| degree | Derece türü (Yüksek Lisans, Doktora vb.) |
| year | Yayın yılı (hedef değişken) |

## Yıllara Göre Dağılım

### Eğitim Seti
| Yıl | Sayı |
|-----|------|
"""
    
    for year in sorted(train_year_dist.keys()):
        info_text += f"| {year} | {train_year_dist[year]} |\n"
    
    info_text += f"""
### Test Seti
| Yıl | Sayı |
|-----|------|
"""
    
    for year in sorted(test_year_dist.keys()):
        info_text += f"| {year} | {test_year_dist[year]} |\n"
    
    info_text += f"""
## Derece Türlerine Göre Dağılım

### Eğitim Seti
| Derece | Sayı |
|--------|------|
"""
    
    for degree, count in sorted(train_degree_dist.items(), key=lambda x: -x[1]):
        info_text += f"| {degree} | {count} |\n"
    
    info_text += f"""
### Test Seti
| Derece | Sayı |
|--------|------|
"""
    
    for degree, count in sorted(test_degree_dist.items(), key=lambda x: -x[1]):
        info_text += f"| {degree} | {count} |\n"
    
    info_text += f"""
## Eksik Veri Analizi

### Eğitim Seti
"""
    for col in train_df.columns:
        empty_count = train_df[col].apply(lambda x: x == "" or pd.isna(x)).sum()
        info_text += f"- **{col}**: {empty_count} eksik ({100*empty_count/len(train_df):.2f}%)\n"
    
    info_text += f"""
### Test Seti
"""
    for col in test_df.columns:
        empty_count = test_df[col].apply(lambda x: x == "" or pd.isna(x)).sum()
        info_text += f"- **{col}**: {empty_count} eksik ({100*empty_count/len(test_df):.2f}%)\n"
    
    # Kaydet
    with open(os.path.join(output_dir, "DATASET_INFO.md"), "w", encoding="utf-8") as f:
        f.write(info_text)
    
    print(f"  ✓ {output_dir}/DATASET_INFO.md")


def main():
    """
    Ana fonksiyon - veriseti hazırlama sürecini yönetir.
    """
    print("=" * 60)
    print("TEZ VERİSETİ HAZIRLAMA")
    print("=" * 60)
    
    # 1. Verisetini yükle
    dataset = load_thesis_dataset()
    
    # 2. Yıllara göre filtrele
    theses_by_year = filter_by_years(dataset, START_YEAR, END_YEAR)
    
    # 3. Rastgele seçim yap ve train/test ayır
    train_data, test_data = sample_theses(dataset, theses_by_year)
    
    # 4. Verisetlerini kaydet
    save_datasets(train_data, test_data, OUTPUT_DIR)
    
    # 5. Bilgi dosyası oluştur
    generate_dataset_info(train_data, test_data, OUTPUT_DIR)
    
    print("\n" + "=" * 60)
    print("VERİSETİ HAZIRLAMA TAMAMLANDI")
    print("=" * 60)
    print(f"\nÖzet:")
    print(f"  - Eğitim seti: {len(train_data)} tez")
    print(f"  - Test seti: {len(test_data)} tez")
    print(f"  - Çıktı dizini: {OUTPUT_DIR}/")


if __name__ == "__main__":
    main()

