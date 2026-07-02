import numpy as np

"""
Senaryo 1: Büyük Gradyan, Düşük Gürültü -> BÜYÜK ADIM
Hızlı ve Emin: Yokuş dik ve yönümüzden eminiz (sinyal güçlü).
Minimuma hızla yaklaşmak için tam gaz ilerlemeliyiz.

Bu fonksiyon büyük katsayılı, düzgün bir quadratic fonksiyondur.
Gradyanlar büyük ama yönü tutarlıdır.
"""


def large_grad_low_noise(x: np.ndarray) -> float:
    x = np.asarray(x, dtype=float)
    # Büyük katsayılı quadratic - büyük gradyanlar üretir
    return 50.0 * float(np.sum(x * x))


def large_grad_low_noise_grad(x: np.ndarray) -> np.ndarray:
    x = np.asarray(x, dtype=float)
    # Büyük ve tutarlı gradyanlar
    return 100.0 * x

