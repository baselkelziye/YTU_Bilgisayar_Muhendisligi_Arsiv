import numpy as np

"""
Senaryo 3: Büyük Gradyan, Yüksek Gürültü -> KÜÇÜK ADIM
Hızlı ve Kararsız: Yokuş dik, AMA yönümüz sürekli değişiyor.
Bu, gürültülü bir yüzeyde (Rastrigin gibi) olduğumuzu gösterir.
Büyük bir adım atarsak, yanlış yöne "ziplayabiliriz".
Gürültünün ortalamasını almak için yavaşlamalıyız.

Bu fonksiyon büyük katsayılı ama yüksek frekanslı gürültü içerir.
Gradyanlar büyük ama yönü sürekli değişir.
"""


def large_grad_high_noise(x: np.ndarray) -> float:
    x = np.asarray(x, dtype=float)
    # Büyük katsayılı quadratic + yüksek frekanslı sinüs gürültüsü
    base = 50.0 * float(np.sum(x * x))
    noise = 12.0 * float(
        np.sum(np.sin(10.0 * x) * np.sin(10.0 * x))
    )  # Yüksek frekanslı gürültü (azaltıldı)
    return base + noise


def large_grad_high_noise_grad(x: np.ndarray) -> np.ndarray:
    x = np.asarray(x, dtype=float)
    # Büyük gradyan + yüksek frekanslı gürültülü gradyan
    base_grad = 100.0 * x
    noise_grad = 12.0 * 10.0 * np.cos(10.0 * x) * np.sin(10.0 * x) * 2.0
    return base_grad + noise_grad

