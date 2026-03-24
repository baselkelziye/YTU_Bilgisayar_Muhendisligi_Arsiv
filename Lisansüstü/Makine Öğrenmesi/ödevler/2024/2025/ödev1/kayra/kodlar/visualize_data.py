import os
import numpy as np
import matplotlib.pyplot as plt
import argparse


def detect_header(filename: str, delimiter: str = ',') -> bool:
    """Bir dosyanın ilk boş olmayan satırının başlık olup olmadığını tespit eder.

    İlk boş olmayan satırdaki değerleri float'a çevirmeyi dener.
    Herhangi bir değer float'a çevrilemiyorsa bu satır başlık kabul edilir.
    CSV benzeri dosyalar için uygundur.
    """
    with open(filename, 'r', encoding='utf-8') as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            parts = line.split(delimiter)
            # Try converting each part to float; if any fail -> header
            for p in parts:
                try:
                    float(p)
                except ValueError:
                    return True
            return False
    return False


def load_data(filename: str, delimiter: str = ',') -> np.ndarray:
    """Dosyadan sayısal veriyi yükler; CSV dosyalarında varsa başlığı atlar.

    (n_örnek, n_özellik) biçiminde bir numpy dizisi döndürür.
    """
    if not os.path.exists(filename):
        raise FileNotFoundError(filename)

    # CSV benzeri dosyalar için başlık tespiti
    skiprows = 0
    try:
        if filename.lower().endswith('.csv') or filename.lower().endswith('.txt'):
            if detect_header(filename, delimiter=delimiter):
                skiprows = 1
    except Exception:
        # Tespit herhangi bir nedenle başarısız olursa başlık atlama
        skiprows = 0

    # Eksik değerler ve başlık atlama için genfromtxt uygundur
    data = np.genfromtxt(filename, delimiter=delimiter, skip_header=skiprows)

    # Veri 1D ise (tek satır) 2D'ye yeniden şekillendir
    if data.ndim == 1:
        data = data.reshape(1, -1)

    return data


def plot_data(exam_1: np.ndarray, exam_2: np.ndarray, labels: np.ndarray, out_fname: str) -> None:
    """İki sınav notunun etiketlere göre renklendirildiği saçılım grafiğini çizer ve kaydeder.
    """
    hired = labels == 1
    not_hired = labels == 0

    plt.figure(figsize=(10, 6))
    plt.scatter(exam_1[not_hired], exam_2[not_hired],
                c='red', marker='x', s=100, linewidths=2,
                label='İşe Alınmadı (0)', alpha=0.7)
    plt.scatter(exam_1[hired], exam_2[hired],
                c='green', marker='o', s=100,
                label='İşe Alındı (1)', alpha=0.7)

    plt.xlabel('1. Sınav Notu', fontsize=12)
    plt.ylabel('2. Sınav Notu', fontsize=12)
    plt.title('Sınav Notlarına Göre İşe Alım Durumu', fontsize=14, fontweight='bold')
    plt.legend(loc='best', fontsize=10)
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    # Çıktı dizininin varlığını sağla
    out_dir = os.path.dirname(out_fname)
    if out_dir and not os.path.exists(out_dir):
        os.makedirs(out_dir, exist_ok=True)

    plt.savefig(out_fname)
    plt.show()


def summarize_and_print(labels: np.ndarray, total: int) -> None:
    hired = np.sum(labels == 1)
    not_hired = np.sum(labels == 0)
    print(f"Toplam örnek sayısı: {total}")
    print(f"İşe alınanlar: {hired} (%{hired/total*100:.1f})")
    print(f"İşe alınmayanlar: {not_hired} (%{not_hired/total*100:.1f})")


def main() -> None:
    parser = argparse.ArgumentParser(description="Veriyi oku ve sınıflara göre saçılım grafiği çizer")
    parser.add_argument('filename', nargs='?', default='dataset/hw1Data.txt',
                        help="Okunacak veri dosyasının adı (varsayılan: dataset/hw1Data.txt)")
    args = parser.parse_args()

    try:
        data = load_data(args.filename, delimiter=',')

        if data.size == 0:
            print(f"Hata: '{args.filename}' dosyası boş veya okunamadı.")
            return

        # Expect at least 3 columns: exam1, exam2, label
        if data.shape[1] < 3:
            print(f"Hata: '{args.filename}' dosyasında en az 3 sütun olmalı (exam1, exam2, label).")
            return

        exam_1 = data[:, 0]
        exam_2 = data[:, 1]
        labels = data[:, 2].astype(int)

        summarize_and_print(labels, len(data))

        # Prepare output directory 'gorseller' next to the data file (or in CWD if no path)
        input_path = args.filename
        base = os.path.basename(input_path)
        name_without_ext = os.path.splitext(base)[0]
        out_dir = os.path.join(os.path.dirname(input_path) or os.getcwd(), 'gorseller')
        out_fname = os.path.join(out_dir, f"{name_without_ext}_plot.png")

        plot_data(exam_1, exam_2, labels, out_fname)

    except FileNotFoundError:
        print(f"Hata: '{args.filename}' dosyası bulunamadı!")
    except ValueError as e:
        print(f"Dosya okunurken hata oluştu (değer hatası): {e}")
    except Exception as e:
        print(f"Hata oluştu: {e}")


if __name__ == "__main__":
    main()
