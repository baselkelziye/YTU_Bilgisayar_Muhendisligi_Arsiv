import numpy as np
import matplotlib.pyplot as plt

class DTFTAnalyzer:
    """DTFT hesaplama ve görselleştirme sınıfı"""
    
    def __init__(self, num_points=1024):
        """
        Args:
            num_points: Frekans eksenindeki nokta sayısı
        """
        self.num_points = num_points
        self.omega = np.linspace(-np.pi, np.pi, num_points)
    
    def compute_dtft(self, signal, n):
        """
        DTFT hesapla
        
        Args:
            signal: Zaman domenindeki sinyal
            n: Zaman indeksleri
            
        Returns:
            X: DTFT (kompleks değerler)
        """
        X = np.zeros(len(self.omega), dtype=complex)
        
        for i, w in enumerate(self.omega):
            X[i] = np.sum(signal * np.exp(-1j * w * n))
        
        return X
    
    def get_magnitude_phase(self, X):
        """
        Genlik ve faz spektrumlarını hesapla
        
        Args:
            X: DTFT çıktısı
            
        Returns:
            magnitude: Genlik spektrumu
            phase: Faz spektrumu (radyan)
        """
        magnitude = np.abs(X)
        phase = np.angle(X)
        
        return magnitude, phase
    
    def plot_dtft_spectrum(self, signal, n, title="DTFT Analizi"):
        """
        DTFT genlik ve faz spektrumlarını çiz
        
        Args:
            signal: Zaman domenindeki sinyal
            n: Zaman indeksleri
            title: Grafik başlığı
            
        Returns:
            fig: Matplotlib figure nesnesi
        """
        # DTFT hesapla
        X = self.compute_dtft(signal, n)
        magnitude, phase = self.get_magnitude_phase(X)
        
        # Grafik oluştur
        fig, axes = plt.subplots(3, 1, figsize=(12, 10))
        fig.suptitle(title, fontsize=14, fontweight='bold')
        
        # Orijinal sinyal
        # Matplotlib 3.8+ removed the 'use_line_collection' argument from stem
        axes[0].stem(n, np.real(signal), basefmt=' ')
        axes[0].set_xlabel('n (örnek)')
        axes[0].set_ylabel('x[n]')
        axes[0].set_title('Zaman Domeninde Sinyal')
        axes[0].grid(True, alpha=0.3)
        
        # Genlik spektrumu
        axes[1].plot(self.omega, magnitude, 'b', linewidth=2)
        axes[1].set_xlabel('ω (radyan)')
        axes[1].set_ylabel('|X(e^jω)|')
        axes[1].set_title('Genlik Spektrumu')
        axes[1].grid(True, alpha=0.3)
        axes[1].set_xlim([-np.pi, np.pi])
        axes[1].set_xticks([-np.pi, -np.pi/2, 0, np.pi/2, np.pi])
        axes[1].set_xticklabels(['-π', '-π/2', '0', 'π/2', 'π'])
        
        # Faz spektrumu
        axes[2].plot(self.omega, phase, 'r', linewidth=2)
        axes[2].set_xlabel('ω (radyan)')
        axes[2].set_ylabel('∠X(e^jω) (radyan)')
        axes[2].set_title('Faz Spektrumu')
        axes[2].grid(True, alpha=0.3)
        axes[2].set_xlim([-np.pi, np.pi])
        axes[2].set_xticks([-np.pi, -np.pi/2, 0, np.pi/2, np.pi])
        axes[2].set_xticklabels(['-π', '-π/2', '0', 'π/2', 'π'])
        axes[2].set_ylim([-np.pi, np.pi])
        axes[2].set_yticks([-np.pi, -np.pi/2, 0, np.pi/2, np.pi])
        axes[2].set_yticklabels(['-π', '-π/2', '0', 'π/2', 'π'])
        
        plt.tight_layout()
        return fig
