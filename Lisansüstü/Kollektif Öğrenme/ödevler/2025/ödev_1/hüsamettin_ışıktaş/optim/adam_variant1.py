import numpy as np
from dataclasses import dataclass

"""
Bu varyant, Adam optimizasyon algoritmasinin başlangiçtaki bias düzeltmesini kaldirir. Normalde Adam, hareketli ortalamalarin (m ve v) başlangiçta 0 olmasindan kaynaklanan bias'i düzeltmek için m_hat ve v_hat hesaplar. Ancak bu varyantta, m ve v'nin başlangiç değerleri ilk gradyan ve gradyanin karesi ile doğrudan başlatilir, böylece bias düzeltme adimlarina gerek kalmaz.
"""

@dataclass
class AdamVariant1Config:
    learning_rate: float = 0.01
    beta1: float = 0.9
    beta2: float = 0.999
    epsilon: float = 1e-8
    max_iters: int = 1000

class AdamVariant1:
    def __init__(self, dim: int, config: AdamVariant1Config | None = None):
        self.config = config or AdamVariant1Config()
        self.m = np.zeros(dim, dtype=float)
        self.v = np.zeros(dim, dtype=float)
        self.t = 0

    def step(self, x: np.ndarray, grad: np.ndarray) -> np.ndarray:
        self.t += 1
        b1, b2 = self.config.beta1, self.config.beta2
        # değişikliği yapildiği kisim burasi, m0 ve v0 0 ile başlatilsa bile burada değişecek.
        if self.t == 1:
            # İlk adimda, geçmiş (beta*m) olmadiği için m ve v'yi doğrudan başlat.
            self.m = (1.0 - b1) * grad
            self.v = (1.0 - b2) * (grad * grad)
        else:
            # Sonraki adimlarda normal güncelleme
            self.m = b1 * self.m + (1.0 - b1) * grad
            self.v = b2 * self.v + (1.0 - b2) * (grad * grad)

        # Bias correction (m_hat, v_hat) adimlari kaldırıldı.Çünkü o adimlar m0 ve v0 0 olarak başlatilirsa anlamli oluyordu.
        update = self.config.learning_rate * self.m / (np.sqrt(self.v) + self.config.epsilon)
        
        return x - update


