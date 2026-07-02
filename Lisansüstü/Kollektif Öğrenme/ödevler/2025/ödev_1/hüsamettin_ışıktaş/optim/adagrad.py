import numpy as np
from dataclasses import dataclass


@dataclass
class AdagradConfig:
    learning_rate: float = 0.01
    epsilon: float = 1e-8
    max_iters: int = 1000


class Adagrad:
    def __init__(self, dim: int, config: AdagradConfig | None = None):
        self.config = config or AdagradConfig()
        self.accumulated_square = np.zeros(dim, dtype=float)

    def step(self, x: np.ndarray, grad: np.ndarray) -> np.ndarray:
        self.accumulated_square += grad * grad
        adjusted_lr = self.config.learning_rate / (np.sqrt(self.accumulated_square) + self.config.epsilon)
        update = adjusted_lr * grad
        return x - update


