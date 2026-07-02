import numpy as np

"""
Senaryo 2: Küçük Gradyan, Düşük Gürültü -> KÜÇÜK ADIM
Yavaş ve Emin: Yokuş düzleşti ve yönümüz hala tutarlı.
Bu, minimumun dibine yaklaştığımızı gösterir.
Aşırıya kaçmamak (overshoot) için yavaşlamalıyız.

Bu fonksiyon küçük katsayılı, düzgün bir quadratic fonksiyondur.
Minimuma yakın bölgede küçük gradyanlar ama yönü tutarlıdır.
"""


def small_grad_low_noise(x: np.ndarray) -> float:
    x = np.asarray(x, dtype=float)
    # Küçük katsayılı quadratic - küçük gradyanlar üretir
    return 0.1 * float(np.sum(x * x))


def small_grad_low_noise_grad(x: np.ndarray) -> np.ndarray:
    x = np.asarray(x, dtype=float)
    # Küçük ama tutarlı gradyanlar
    return 0.2 * x

