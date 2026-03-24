import numpy as np
import matplotlib.pyplot as plt

def dtft_function(omega, N):
    """
    Verilen DTFT fonksiyonunu hesaplar
    H(e^jΩ) = (1 - e^(-jΩN)) / (1 - e^(-jΩ))
    """
    # Sıfıra bölme durumunu kontrol et
    epsilon = 1e-10
    numerator = 1 - np.exp(-1j * omega * N)
    denominator = 1 - np.exp(-1j * omega)
    
    # Omega = 0 veya 2π'nin katları için limit değerini kullan
    H = np.where(np.abs(denominator) < epsilon, N, numerator / denominator)
    
    return H

def plot_dtft_spectrum(N_values):
    """
    Farklı N değerleri için DTFT genlik ve faz spektrumlarını çizer
    """
    # Omega aralığı: -2π'den 2π'ye
    omega = np.arange(-2*np.pi, 2*np.pi, 0.1)
    
    for N in N_values:
        # DTFT hesapla
        H = dtft_function(omega, N)
        
        # Genlik ve faz spektrumları
        magnitude = np.abs(H)
        phase = np.angle(H)
        
        # Grafikleri oluştur
        fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(12, 8))
        
        # Genlik spektrumu
        ax1.plot(omega, magnitude, 'b-', linewidth=2)
        ax1.set_xlabel('Ω (rad)', fontsize=12)
        ax1.set_ylabel('|H(e^jΩ)|', fontsize=12)
        ax1.set_title(f'Genlik Spektrumu (N = {N})', fontsize=14, fontweight='bold')
        ax1.grid(True, alpha=0.3)
        ax1.set_xlim([-2*np.pi, 2*np.pi])
        
        # X ekseninde π işaretleri
        ax1.set_xticks([-2*np.pi, -np.pi, 0, np.pi, 2*np.pi])
        ax1.set_xticklabels(['-2π', '-π', '0', 'π', '2π'])
        
        # Faz spektrumu
        ax2.plot(omega, phase, 'r-', linewidth=2)
        ax2.set_xlabel('Ω (rad)', fontsize=12)
        ax2.set_ylabel('∠H(e^jΩ) (rad)', fontsize=12)
        ax2.set_title(f'Faz Spektrumu (N = {N})', fontsize=14, fontweight='bold')
        ax2.grid(True, alpha=0.3)
        ax2.set_xlim([-2*np.pi, 2*np.pi])
        
        # X ekseninde π işaretleri
        ax2.set_xticks([-2*np.pi, -np.pi, 0, np.pi, 2*np.pi])
        ax2.set_xticklabels(['-2π', '-π', '0', 'π', '2π'])
        
        plt.tight_layout()
        
        # Görseli kaydet
        filename = f'DTFT_Spektrum_N_{N}.png'
        plt.savefig(filename, dpi=300, bbox_inches='tight')
        print(f'Grafik kaydedildi: {filename}')
        
        plt.close()

# Ana program
if __name__ == "__main__":
    # N değerleri
    N_values = [3, 6, 9, 21]
    
    print("DTFT Genlik ve Faz Spektrumları Çiziliyor...")
    print("-" * 50)
    
    # Spektrumları çiz ve kaydet
    plot_dtft_spectrum(N_values)
    
    print("-" * 50)
    print("Tüm grafikler başarıyla kaydedildi!")

