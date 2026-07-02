import numpy as np


def himmelblau(x: np.ndarray) -> float:
    x = np.asarray(x, dtype=float)
    x1, x2 = x[0], x[1]
    return (x1 * x1 + x2 - 11) ** 2 + (x1 + x2 * x2 - 7) ** 2


def himmelblau_grad(x: np.ndarray) -> np.ndarray:
    x = np.asarray(x, dtype=float)
    x1, x2 = x[0], x[1]
    df_dx1 = 4 * x1 * (x1 * x1 + x2 - 11) + 2 * (x1 + x2 * x2 - 7)
    df_dx2 = 2 * (x1 * x1 + x2 - 11) + 4 * x2 * (x1 + x2 * x2 - 7)
    return np.array([df_dx1, df_dx2], dtype=float)


