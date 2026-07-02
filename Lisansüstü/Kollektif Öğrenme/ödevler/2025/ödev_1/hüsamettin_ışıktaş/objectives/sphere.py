import numpy as np


def sphere(x: np.ndarray) -> float:
    x = np.asarray(x, dtype=float)
    return float(np.sum(x * x))


def sphere_grad(x: np.ndarray) -> np.ndarray:
    x = np.asarray(x, dtype=float)
    return 2.0 * x


