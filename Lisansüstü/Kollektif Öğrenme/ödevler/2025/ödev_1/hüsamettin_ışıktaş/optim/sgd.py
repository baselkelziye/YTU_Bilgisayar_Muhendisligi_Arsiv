import numpy as np
from dataclasses import dataclass


@dataclass
class SGDConfig:
    learning_rate: float = 0.01
    momentum: float = 0.0
    max_iters: int = 1000


class SGD:
    def __init__(self, dim: int, config: SGDConfig | None = None):
        self.config = config or SGDConfig()
        self.velocity = np.zeros(dim, dtype=float)

    def step(self, x: np.ndarray, grad: np.ndarray) -> np.ndarray:
        if self.config.momentum > 0.0:
            self.velocity = self.config.momentum * self.velocity + grad
            update = self.config.learning_rate * self.velocity
        else:
            update = self.config.learning_rate * grad
        return x - update


