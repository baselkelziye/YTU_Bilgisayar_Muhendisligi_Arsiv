"""Experiment configuration defaults."""

from dataclasses import asdict, dataclass, field
from typing import Any

from src.evaluation.metrics import DEFAULT_DATASET_NAME, DEFAULT_HITS_KS


SUPPORTED_METHODS = ("common_neighbors", "mlp", "gcn")
SUPPORTED_SCALES = (0.1, 0.5, 1.0)


@dataclass(slots=True)
class ExperimentConfig:
    """Serializable configuration for one experiment run."""

    method_name: str = "common_neighbors"
    dataset_name: str = DEFAULT_DATASET_NAME
    dataset_scale: float = 0.1
    seed: int = 42
    device: str = "cpu"
    ks: tuple[int, ...] = DEFAULT_HITS_KS
    save_result: bool = True
    hyperparameters: dict[str, Any] = field(default_factory=dict)

    def to_dict(self) -> dict[str, Any]:
        """Return a JSON-serializable dictionary representation."""
        config_dict = asdict(self)
        config_dict["ks"] = list(self.ks)
        return config_dict


def validate_config(config: ExperimentConfig) -> None:
    """Validate common experiment settings before execution."""
    if config.method_name not in SUPPORTED_METHODS:
        raise ValueError(f"Unsupported method_name: {config.method_name}")

    if not 0 < config.dataset_scale <= 1:
        raise ValueError("dataset_scale must be in the range (0, 1].")


def get_method_config(method_name: str) -> dict[str, Any]:
    """Return method-specific default hyperparameters."""
    if method_name == "common_neighbors":
        return {
            "make_undirected": True,
            "add_tie_breaker": True,
        }

    if method_name == "mlp":
        return {
            "hidden_channels": 256,
            "num_layers": 3,
            "dropout": 0.0,
            "learning_rate": 0.01,
            "batch_size": 64 * 1024,
            "epochs": 200,
        }

    if method_name == "gcn":
        return {
            "hidden_channels": 256,
            "num_layers": 3,
            "dropout": 0.2,
            "learning_rate": 0.005,
            "batch_size": 64 * 1024,
            "epochs": 400,
        }

    raise ValueError(f"Unsupported method_name: {method_name}")


def get_default_config(
    method_name: str = "common_neighbors",
    dataset_scale: float = 0.1,
    seed: int = 42,
    device: str = "cpu",
) -> ExperimentConfig:
    """Build a default config for one method and dataset scale."""
    return ExperimentConfig(
        method_name=method_name,
        dataset_scale=dataset_scale,
        seed=seed,
        device=device,
        hyperparameters=get_method_config(method_name),
    )
