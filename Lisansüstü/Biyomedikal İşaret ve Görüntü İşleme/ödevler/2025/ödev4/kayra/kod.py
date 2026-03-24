import numpy as np
import os
from scipy import signal
from scipy.fft import fft, fftfreq

# DTMF frekans matrisi
DTMF_FREQS_LOW = [697, 770, 852, 941]  # Satır frekansları
DTMF_FREQS_HIGH = [1209, 1336, 1477, 1633]  # Sütun frekansları

# DTMF tuş matrisi
DTMF_KEYS = [
    ['1', '2', '3', 'A'],
    ['4', '5', '6', 'B'],
    ['7', '8', '9', 'C'],
    ['*', '0', '#', 'D']
]

def goertzel(samples, target_freq, sample_rate):
    """
    Goertzel algoritması ile belirli bir frekansın gücünü hesaplar
    """
    n = len(samples)
    k = int(0.5 + (n * target_freq) / sample_rate)
    omega = (2.0 * np.pi * k) / n
    coeff = 2.0 * np.cos(omega)
    
    q1 = 0.0
    q2 = 0.0
    
    for sample in samples:
        q0 = coeff * q1 - q2 + sample
        q2 = q1
        q1 = q0
    
    magnitude = np.sqrt(q1**2 + q2**2 - q1 * q2 * coeff)
    return magnitude

def detect_dtmf_fft(data, sample_rate=8000):
    """
    FFT kullanarak DTMF tonlarını algılar
    """
    # FFT hesapla
    N = len(data)
    yf = fft(data)
    xf = fftfreq(N, 1/sample_rate)
    
    # Sadece pozitif frekansları al
    positive_freqs = xf[:N//2]
    magnitudes = np.abs(yf[:N//2])
    
    # Her DTMF frekansı için güç hesapla
    low_powers = []
    for freq in DTMF_FREQS_LOW:
        idx = np.argmin(np.abs(positive_freqs - freq))
        # Frekans etrafında bir pencere al
        window = 10
        power = np.sum(magnitudes[max(0, idx-window):min(len(magnitudes), idx+window)])
        low_powers.append(power)
    
    high_powers = []
    for freq in DTMF_FREQS_HIGH:
        idx = np.argmin(np.abs(positive_freqs - freq))
        window = 10
        power = np.sum(magnitudes[max(0, idx-window):min(len(magnitudes), idx+window)])
        high_powers.append(power)
    
    # En güçlü frekansları bul
    low_idx = np.argmax(low_powers)
    high_idx = np.argmax(high_powers)
    
    return DTMF_KEYS[low_idx][high_idx], DTMF_FREQS_LOW[low_idx], DTMF_FREQS_HIGH[high_idx]

def detect_dtmf_goertzel(data, sample_rate=8000):
    """
    Goertzel algoritması ile DTMF tonlarını algılar
    """
    # Her DTMF frekansı için Goertzel algoritmasını uygula
    low_powers = [goertzel(data, freq, sample_rate) for freq in DTMF_FREQS_LOW]
    high_powers = [goertzel(data, freq, sample_rate) for freq in DTMF_FREQS_HIGH]
    
    # En güçlü frekansları bul
    low_idx = np.argmax(low_powers)
    high_idx = np.argmax(high_powers)
    
    return DTMF_KEYS[low_idx][high_idx], DTMF_FREQS_LOW[low_idx], DTMF_FREQS_HIGH[high_idx]

def read_data_file(filename):
    """
    Veri dosyasını okur
    """
    with open(filename, 'r') as f:
        content = f.read()
        data = [float(x) for x in content.split(',') if x.strip()]
    return np.array(data)

def main():
    """
    Ana program
    """
    veriler_path = './veriler'
    
    # Tüm .data dosyalarını bul
    data_files = sorted([f for f in os.listdir(veriler_path) if f.endswith('.data')])
    
    print("=" * 70)
    print("DTMF İŞARET ANALİZİ SONUÇLARI")
    print("=" * 70)
    print()
    
    results = []
    
    for filename in data_files:
        filepath = os.path.join(veriler_path, filename)
        
        # Veriyi oku
        data = read_data_file(filepath)
        
        # DTMF tonunu algıla (Goertzel metodu)
        key_goertzel, low_freq, high_freq = detect_dtmf_goertzel(data)
        
        # FFT metodu ile de kontrol
        key_fft, _, _ = detect_dtmf_fft(data)
        
        results.append({
            'file': filename,
            'key': key_goertzel,
            'low_freq': low_freq,
            'high_freq': high_freq,
            'samples': len(data)
        })
        
        print(f"Dosya: {filename}")
        print(f"  • Basılan Tuş: **{key_goertzel}**")
        print(f"  • Düşük Frekans: {low_freq} Hz (Satır)")
        print(f"  • Yüksek Frekans: {high_freq} Hz (Sütun)")
        print(f"  • Örnek Sayısı: {len(data)}")
        print(f"  • FFT ile Kontrol: {key_fft}")
        print("-" * 70)
    
    # Özet tablo
    print("\n" + "=" * 70)
    print("ÖZET TABLO")
    print("=" * 70)
    print(f"{'Dosya':<15} {'Tuş':<8} {'Düşük Frekans':<15} {'Yüksek Frekans':<15}")
    print("-" * 70)
    for result in results:
        print(f"{result['file']:<15} {result['key']:<8} {result['low_freq']:<15} {result['high_freq']:<15}")
    print("=" * 70)

if __name__ == "__main__":
    main()
