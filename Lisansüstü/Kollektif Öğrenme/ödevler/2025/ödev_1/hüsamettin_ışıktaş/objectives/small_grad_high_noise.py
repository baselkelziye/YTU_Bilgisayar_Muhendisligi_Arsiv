import numpy as np

"""
Senaryo 4: Küçük Gradyan, Yüksek Gürültü -> ÇOK KÜÇÜK ADIM
Yavaş ve Kararsız: Yokuş düz VE yönümüz belirsiz.
Bu, gürültülü bir düzlükte veya eyer noktasında (saddle point) olabileceğimizi gösterir.
Sinyal yok, bu yüzden hareket etmemeliyiz.

Bu fonksiyon küçük katsayılı ama yüksek frekanslı gürültü içerir.
Gradyanlar küçük ve yönü belirsizdir.
"""


def small_grad_high_noise(x: np.ndarray) -> float:
    x = np.asarray(x, dtype=float)
    # Küçük katsayılı quadratic + süreksiz yüksek frekanslı gürültü
    # Senaryo: Küçük gradyan ama yönü sürekli değişiyor (süreksiz gürültü)
    base = 0.1 * float(np.sum(x * x))
    # Daha süreksiz görünen gürültü: farklı frekanslarda sinüs/cosinüs kombinasyonu
    # x ile çarpılarak minimumda sıfır olması sağlanıyor, daha küçük amplitüd
    noise = 0.15 * float(
        np.sum(x * x * (np.sin(15.0 * x) * np.cos(13.0 * x) + np.sin(17.0 * x) * np.cos(11.0 * x)))
    )
    return base + noise


def small_grad_high_noise_grad(x: np.ndarray) -> np.ndarray:
    x = np.asarray(x, dtype=float)
    # Küçük gradyan + süreksiz yüksek frekanslı gürültülü gradyan
    base_grad = 0.2 * x
    # Gradyan: d/dx [x^2 * (sin(15x)*cos(13x) + sin(17x)*cos(11x))]
    # = 2x*(sin(15x)*cos(13x) + sin(17x)*cos(11x)) + x^2*(15*cos(15x)*cos(13x) - 13*sin(15x)*sin(13x) + 17*cos(17x)*cos(11x) - 11*sin(17x)*sin(11x))
    sin_cos_term = np.sin(15.0 * x) * np.cos(13.0 * x) + np.sin(17.0 * x) * np.cos(11.0 * x)
    cos_sin_term = (
        15.0 * np.cos(15.0 * x) * np.cos(13.0 * x) - 13.0 * np.sin(15.0 * x) * np.sin(13.0 * x) +
        17.0 * np.cos(17.0 * x) * np.cos(11.0 * x) - 11.0 * np.sin(17.0 * x) * np.sin(11.0 * x)
    )
    noise_grad = 0.15 * (2.0 * x * sin_cos_term + x * x * cos_sin_term)
    return base_grad + noise_grad

