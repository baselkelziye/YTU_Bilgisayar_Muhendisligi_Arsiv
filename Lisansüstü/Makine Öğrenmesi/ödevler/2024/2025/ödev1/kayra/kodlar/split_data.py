import argparse
import numpy as np
import os
from collections import defaultdict
from collections import Counter

# Modül genelinde kullanılan veri kümesi dizini
DATASET_DIR = 'dataset'

def load_and_split_data(filename='dataset/hw1Data.txt', train_frac=0.6, test_frac=0.2, val_frac=0.2, seed=42):
    """
    Veriyi okur ve etiket oranlarını koruyarak (tabakalı/stratified) eğitim/test/doğrulama olarak böler.

    Argümanlar:
        filename: Girdi dosyası (CSV benzeri, ayırıcı=",")
        train_frac: Eğitim oranı (ör. 0.6)
        test_frac: Test oranı (ör. 0.2)
        val_frac: Doğrulama oranı (ör. 0.2)
        seed: Rastgelelik için tohum (varsayılan 42)

    Döndürür:
        (X_train, y_train), (X_test, y_test), (X_validation, y_validation)
    """
    if abs(train_frac + test_frac + val_frac - 1.0) > 1e-8:
        raise ValueError('train/test/val oranları toplamı 1 olmalı')

    # Veriyi oku ve yapılandır
    data = _read_data(filename)
    total_samples = len(data)

    # Etiketleri çıkar
    y = data[:, 2].astype(int)

    # Rastgele sayı üreteci
    rng = np.random.RandomState(seed)

    # Sınıfa göre indeks gruplama
    class_indices = _get_class_indices(y)

    # Her sınıf için indeksleri bölen yardımcı fonksiyonu kullan
    train_idx, test_idx, val_idx = _process_class_splits(class_indices, train_frac, test_frac, val_frac, rng)

    # Son indeksleri isteğe göre karıştır
    rng.shuffle(train_idx)
    rng.shuffle(test_idx)
    rng.shuffle(val_idx)

    train_data = data[train_idx]
    test_data = data[test_idx]
    validation_data = data[val_idx]

    X_train = train_data[:, :2]
    y_train = train_data[:, 2]
    X_test = test_data[:, :2]
    y_test = test_data[:, 2]
    X_validation = validation_data[:, :2]
    y_validation = validation_data[:, 2]

    # Bilgilendirici çıktı
    print(f"Toplam veri sayısı: {total_samples}")
    print(f"\nTrain seti: {len(train_data)} örnek (%{len(train_data)/total_samples*100:.1f})")
    print(f"Test seti: {len(test_data)} örnek (%{len(test_data)/total_samples*100:.1f})")
    print(f"Validation seti: {len(validation_data)} örnek (%{len(validation_data)/total_samples*100:.1f})")

    # Sınıf bazlı oranları göster
    print('\nSınıf dağılımları (eğitim/test/doğrulama):')
    print('etiket\teğitim\ttest\tdoğrulama')
    labels = sorted(class_indices.keys())
    train_counts = Counter(y_train.astype(int))
    test_counts = Counter(y_test.astype(int))
    val_counts = Counter(y_validation.astype(int))
    for lbl in labels:
        print(f"{lbl}\t{train_counts.get(lbl,0)}\t{test_counts.get(lbl,0)}\t{val_counts.get(lbl,0)}")

    return (X_train, y_train), (X_test, y_test), (X_validation, y_validation)


def _read_data(filename):
    """Dosyadan veriyi numpy.loadtxt ile okuyup diziyi döndürür."""
    return np.loadtxt(filename, delimiter=',')


def _get_class_indices(y):
    """Etiketten örnek indekslerine sözlük döndürür (label -> indeks listesi)."""
    class_indices = defaultdict(list)
    for idx, label in enumerate(y):
        class_indices[int(label)].append(idx)
    return class_indices


def _split_indices_for_class(indices, train_frac, test_frac):
    """Bir sınıfa ait indeks dizisi verildiğinde (eğitim, test, doğrulama) indekslerini döndürür."""
    n = len(indices)
    n_train = int(np.floor(train_frac * n))
    n_test = int(np.floor(test_frac * n))
    n_val = n - n_train - n_test

    # Yuvarlama kaynaklı negatif n_val olursa düzelt
    if n_val < 0:
        diff = -n_val
        reduce_test = min(diff, n_test)
        n_test -= reduce_test
        diff -= reduce_test
        reduce_train = min(diff, n_train)
        n_train -= reduce_train
        n_val = n - n_train - n_test

    start = 0
    train_slice = indices[start:start + n_train].tolist()
    start += n_train
    test_slice = indices[start:start + n_test].tolist()
    start += n_test
    val_slice = indices[start:start + n_val].tolist()

    return train_slice, test_slice, val_slice


def _process_class_splits(class_indices, train_frac, test_frac, val_frac, rng):
    """Sınıflar üzerinde dolaş, her sınıf indekslerini karıştır ve orantılı böl.

    Birleşik eğitim, test, doğrulama indeks listelerini döndürür.
    """
    train_idx = []
    test_idx = []
    val_idx = []

    for label, indices in class_indices.items():
        indices = np.array(indices)
        rng.shuffle(indices)
        t_idx, te_idx, v_idx = _split_indices_for_class(indices, train_frac, test_frac)
        train_idx.extend(t_idx)
        test_idx.extend(te_idx)
        val_idx.extend(v_idx)

    return train_idx, test_idx, val_idx

def save_single_dataset(filename, X_data, y_data):
    """
    Tek bir veri setini dosyaya kaydeder
    
    Argümanlar:
        filename: Kaydedilecek dosya adı
        X_data: Özellik matrisi (exam_1, exam_2)
        y_data: Etiket vektörü (hired)
    """
    combined_data = np.column_stack((X_data, y_data.astype(int)))
    np.savetxt(filename, combined_data, delimiter=',', 
               fmt='%.8f,%.8f,%d',
               header='exam_1,exam_2,hired', comments='')

def save_data_to_files(train, test, validation, train_file, test_file, validation_file):
    """
    Bölünmüş veriyi verilen dosya yollarına kaydeder.

    Argümanlar:
        train: (X_train, y_train)
        test: (X_test, y_test)
        validation: (X_val, y_val)
        train_file: Tam yoluyla eğitim dosyası
        test_file: Tam yoluyla test dosyası
        validation_file: Tam yoluyla doğrulama dosyası
    """
    X_train, y_train = train
    X_test, y_test = test
    X_val, y_val = validation

    # Her veri setini verilen dosya yollarına kaydet
    save_single_dataset(train_file, X_train, y_train)
    save_single_dataset(test_file, X_test, y_test)
    save_single_dataset(validation_file, X_val, y_val)

    print("\n✓ Veriler dosyalara kaydedildi:")
    print(f"  - {train_file}")
    print(f"  - {test_file}")
    print(f"  - {validation_file}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='HW1 verisi için tabakalı veri bölme aracı')
    parser.add_argument('--input', '-i', default='dataset/hw1Data.txt', help='Girdi dosyası (varsayılan: dataset/hw1Data.txt)')
    parser.add_argument('--seed', '-s', type=int, default=42, help='Rastgelelik tohumu (varsayılan: 42)')
    parser.add_argument('--train-frac', type=float, default=0.6, help='Eğitim oranı (varsayılan: 0.6)')
    parser.add_argument('--test-frac', type=float, default=0.2, help='Test oranı (varsayılan: 0.2)')
    parser.add_argument('--val-frac', type=float, default=0.2, help='Doğrulama oranı (varsayılan: 0.2)')
    parser.add_argument('--train-out', default=os.path.join(DATASET_DIR, 'train_data.csv'), help='Eğitim çıktısı (varsayılan: dataset/train_data.csv)')
    parser.add_argument('--test-out', default=os.path.join(DATASET_DIR, 'test_data.csv'), help='Test çıktısı (varsayılan: dataset/test_data.csv)')
    parser.add_argument('--val-out', default=os.path.join(DATASET_DIR, 'validation_data.csv'), help='Doğrulama çıktısı (varsayılan: dataset/validation_data.csv)')


    args = parser.parse_args()

    try:
        train, test, validation = load_and_split_data(args.input, args.train_frac, args.test_frac, args.val_frac, args.seed)

        # Örnek kullanım - ilk 5 örnek göster
        X_train, y_train = train
        print("\nİlk 5 train örneği:")
        print("Exam 1\t\tExam 2\t\tİşe Alındı")
        for i in range(min(5, len(X_train))):
            print(f"{X_train[i][0]:.2f}\t\t{X_train[i][1]:.2f}\t\t{int(y_train[i])}")

        # Çıktı dizinlerinin varlığını sağla
        os.makedirs(os.path.dirname(args.train_out) or DATASET_DIR, exist_ok=True)
        os.makedirs(os.path.dirname(args.test_out) or DATASET_DIR, exist_ok=True)
        os.makedirs(os.path.dirname(args.val_out) or DATASET_DIR, exist_ok=True)

        # Verileri dosyalara kaydet (kullanıcının verdiği dosya yollarına)
        save_data_to_files(train, test, validation, args.train_out, args.test_out, args.val_out)

    except FileNotFoundError:
        print(f"Hata: '{args.input}' dosyası bulunamadı!")
    except Exception as e:
        print(f"Hata oluştu: {e}")