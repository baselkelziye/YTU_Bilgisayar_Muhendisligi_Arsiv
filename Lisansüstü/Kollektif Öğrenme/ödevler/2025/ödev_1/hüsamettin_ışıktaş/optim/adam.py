import numpy as np
from dataclasses import dataclass


@dataclass
class AdamConfig:
    learning_rate: float = 0.01
    beta1: float = 0.9
    beta2: float = 0.999
    epsilon: float = 1e-8
    max_iters: int = 1000


class Adam:
    def __init__(self, dim: int, config: AdamConfig | None = None):
        self.config = config or AdamConfig()
        self.m = np.zeros(dim, dtype=float)
        self.v = np.zeros(dim, dtype=float)
        self.t = 0

    def step(self, x: np.ndarray, grad: np.ndarray) -> np.ndarray:
        self.t += 1
        b1, b2 = self.config.beta1, self.config.beta2

        self.m = b1 * self.m + (1.0 - b1) * grad
        self.v = b2 * self.v + (1.0 - b2) * (grad * grad)

        m_hat = self.m / (1.0 - b1 ** self.t)
        v_hat = self.v / (1.0 - b2 ** self.t)

        update = self.config.learning_rate * m_hat / (np.sqrt(v_hat) + self.config.epsilon)
        return x - update


