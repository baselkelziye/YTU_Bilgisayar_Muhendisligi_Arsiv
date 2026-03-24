import os
import numpy as np
import matplotlib.pyplot as plt
from dtft_analyzer import DTFTAnalyzer

def main():
    # DTFT Analiz nesnesi
    analyzer = DTFTAnalyzer(num_points=2048)

    # Örnek 1: X(e^{jΩ}) = 1 / (1 - a e^{-jΩ}) için a = 0.4 ve a = 0.8
    # Zaman domeni karşılığı: x[n] = a^n u[n]
    N = 80  # yeterli uzunlukta örnekleme penceresi
    n = np.arange(0, N)

    a_values = [0.4, 0.8]
    signals = []
    for a in a_values:
        x = (a ** n) * (n >= 0)
        title = f"X(e^jΩ) = 1/(1 - {a}e^-jΩ) için x[n] = {a}^n u[n]"
        signals.append((x, n, title))

    # Örnek 2: X(e^{jΩ}) = (0.2^4 e^{-j4Ω})/(1-0.2e^{-jΩ}) + 2.5/(1-0.4e^{-jΩ})
    # Zaman domeni karşılığı: x[n] = (0.2)^n u[n-4] + 2.5 (0.4)^n u[n]
    x_comp = (0.2 ** n) * (n >= 4) + 2.5 * (0.4 ** n) * (n >= 0)
    title_comp = "X(e^jΩ) = (0.2^4 e^-j4Ω)/(1-0.2e^-jΩ) + 2.5/(1-0.4e^-jΩ)"
    signals.append((x_comp, n, title_comp))

    # Örnek 3: H(e^{jΩ}) = (0.5 - 0.3e^{-jΩ} + 0.1e^{-j2Ω})/(1-0.2e^{-jΩ})
    # Zaman domeni karşılığı (dürtü yanıtı):
    # h[n] = 0.5(0.2)^n u[n] - 0.3(0.2)^{n-1} u[n-1] + 0.1(0.2)^{n-2} u[n-2]
    h = (
        0.5 * (0.2 ** n) * (n >= 0)
        - 0.3 * (0.2 ** (n - 1)) * (n >= 1)
        + 0.1 * (0.2 ** (n - 2)) * (n >= 2)
    )
    title_h = "H(e^jΩ) = (0.5 - 0.3e^-jΩ + 0.1e^-j2Ω)/(1-0.2e^-jΩ) (dürtü yanıtının DTFT'si)"
    signals.append((h, n, title_h))

    # Her örnek için analiz, çizim ve kaydetme
    for signal, nn, title in signals:
        fig = analyzer.plot_dtft_spectrum(signal, nn, title)
        safe_title = title.replace(os.sep, '_')
        plt.savefig(f"dtft_spektrum_analizi_{safe_title}.png", bbox_inches='tight')
        plt.close(fig)

if __name__ == "__main__":
    main()
