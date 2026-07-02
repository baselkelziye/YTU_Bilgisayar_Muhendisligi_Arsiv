import numpy as np


def rastrigin(x: np.ndarray, A: float = 10.0) -> float:
    x = np.asarray(x, dtype=float)
    n = x.size
    return A * n + float(np.sum(x * x - A * np.cos(2 * np.pi * x)))


def rastrigin_grad(x: np.ndarray, A: float = 10.0) -> np.ndarray:
    x = np.asarray(x, dtype=float)
    return 2.0 * x + 2.0 * np.pi * A * np.sin(2 * np.pi * x)


