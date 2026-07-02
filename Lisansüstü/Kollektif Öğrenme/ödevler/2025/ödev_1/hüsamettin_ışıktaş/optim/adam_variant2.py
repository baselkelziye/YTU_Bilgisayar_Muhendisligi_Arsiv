import numpy as np
from dataclasses import dataclass

"""
Adamvariant2: Gradient Clipping + Consistency Check

Bu varyant, gradyanlara çok güvenmemeyi ve gürültülü gradyanları filtrelemeyi hedefler.

Özellikler:
1. Gradient Clipping: Gradyan normu max_grad_norm'dan büyükse kırpılır
2. Consistency Check: Mevcut gradyan ile momentum (önceki gradyanların ortalaması) 
   arasındaki uyumu kontrol eder. Eğer uyum düşükse (cosine similarity < threshold),
   gradyan gürültülü olabilir ve daha az güvenilir.
3. Trust Factor: Tutarsız gradyanlarda, gradyana ne kadar güvenileceğini belirler.

"""

@dataclass
class AdamVariant2Config:
    learning_rate: float = 0.01
    beta1: float = 0.9
    beta2: float = 0.999
    epsilon: float = 1e-8
    max_iters: int = 1000
    max_grad_norm: float = 1.0  # Gradient clipping threshold
    consistency_threshold: float = 0.5  # Minimum cosine similarity to trust gradient
    trust_factor: float = 0.5  # How much to trust gradient when inconsistent (0=trust momentum, 1=trust gradient)


class AdamVariant2:
    def __init__(self, dim: int, config: AdamVariant2Config | None = None):
        self.config = config or AdamVariant2Config()
        self.m = np.zeros(dim, dtype=float)
        self.v = np.zeros(dim, dtype=float)
        self.t = 0

    def step(self, x: np.ndarray, grad: np.ndarray) -> np.ndarray:
        self.t += 1
        b1, b2 = self.config.beta1, self.config.beta2

        # 1. Gradient clipping: Gradyanı belirli bir norm'a göre kırp
        grad_norm = np.linalg.norm(grad)
        if grad_norm > self.config.max_grad_norm:
            grad = grad * (self.config.max_grad_norm / grad_norm)
            grad_norm = self.config.max_grad_norm  # Kırpılmış norm'u güncelle

        # 2. Gradient consistency check: Mevcut gradyan ile momentum arasındaki uyumu kontrol et
        if self.t > 1 and np.linalg.norm(self.m) > 1e-10:
            # Cosinus benzerliği hesapla (momentum ile gradyan arasındaki açı)
            m_norm = np.linalg.norm(self.m)
            
            if grad_norm > 1e-10:
                cosine_similarity = np.dot(self.m, grad) / (m_norm * grad_norm)
                cosine_similarity = np.clip(cosine_similarity, -1.0, 1.0)
                
                # Eğer gradyan momentum ile uyumlu değilse (gürültülü), gradyana daha az güven
                if cosine_similarity < self.config.consistency_threshold:
                    # Gradient'i azalt veya momentum'a daha fazla güven
                    # trust_factor: 0 = sadece momentum'a güven, 1 = gradyana tam güven
                    grad_weight = self.config.trust_factor
                    # Gradient'i ölçekle
                    grad = grad * grad_weight
        else:
            # İlk iterasyonda veya momentum çok küçükse, consistency check yapılmaz
            # Gradyan olduğu gibi kullanılır (tam güven)
            pass

        # 3. Standart Adam güncellemesi
        self.m = b1 * self.m + (1.0 - b1) * grad
        self.v = b2 * self.v + (1.0 - b2) * (grad * grad)

        m_hat = self.m / (1.0 - b1 ** self.t)
        v_hat = self.v / (1.0 - b2 ** self.t)

        # Adam update
        adam_update = m_hat / (np.sqrt(v_hat) + self.config.epsilon)
        
        final_update = self.config.learning_rate * adam_update

        return x - final_update




