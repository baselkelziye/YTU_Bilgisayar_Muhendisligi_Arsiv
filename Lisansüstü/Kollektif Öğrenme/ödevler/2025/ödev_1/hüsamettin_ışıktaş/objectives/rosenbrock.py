import numpy as np


def rosenbrock(x: np.ndarray, a: float = 1.0, b: float = 100.0) -> float:
    x = np.asarray(x, dtype=float)
    return (a - x[0]) ** 2 + b * (x[1] - x[0] ** 2) ** 2


def rosenbrock_grad(x: np.ndarray, a: float = 1.0, b: float = 100.0) -> np.ndarray:
    x = np.asarray(x, dtype=float)
    dx = -2 * (a - x[0]) - 4 * b * x[0] * (x[1] - x[0] ** 2)
    dy = 2 * b * (x[1] - x[0] ** 2)
    return np.array([dx, dy], dtype=float)


