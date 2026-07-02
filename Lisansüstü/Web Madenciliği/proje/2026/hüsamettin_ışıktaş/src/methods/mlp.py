"""Feature-only MLP baseline for link prediction."""

import logging
from typing import Any

from src.evaluation.metrics import DEFAULT_DATASET_NAME, DEFAULT_HITS_KS
from src.evaluation.metrics import evaluate_link_prediction
from src.evaluation.runtime import get_memory_usage_mb, track_resources
from src.experiments.progress import progress_bar


logger = logging.getLogger(__name__)


def _require_torch() -> Any:
    import torch

    return torch


class MlpLinkPredictor(_require_torch().nn.Module):
    """MLP link predictor that combines endpoint features by multiplication."""

    def __init__(
        self,
        in_channels: int,
        hidden_channels: int,
        out_channels: int = 1,
        num_layers: int = 3,
        dropout: float = 0.0,
    ) -> None:
        super().__init__()
        torch = _require_torch()

        if num_layers < 2:
            raise ValueError("num_layers must be at least 2.")

        self.layers = torch.nn.ModuleList()
        self.layers.append(torch.nn.Linear(in_channels, hidden_channels))
        for _ in range(num_layers - 2):
            self.layers.append(torch.nn.Linear(hidden_channels, hidden_channels))
        self.layers.append(torch.nn.Linear(hidden_channels, out_channels))
        self.dropout = dropout

    def reset_parameters(self) -> None:
        """Reset all linear layer parameters."""
        for layer in self.layers:
            layer.reset_parameters()

    def forward(self, x_i: Any, x_j: Any) -> Any:
        """Predict link probabilities for paired endpoint embeddings."""
        torch = _require_torch()
        x = x_i * x_j

        for layer in self.layers[:-1]:
            x = layer(x)
            x = torch.nn.functional.relu(x)
            x = torch.nn.functional.dropout(x, p=self.dropout, training=self.training)

        return torch.sigmoid(self.layers[-1](x))


def _select_device(device: str) -> Any:
    torch = _require_torch()
    if device.startswith("cuda") and not torch.cuda.is_available():
        return torch.device("cpu")
    return torch.device(device)


def _edge_tensor(edges: Any, device: Any) -> Any:
    torch = _require_torch()

    if hasattr(edges, "detach"):
        edge_tensor = edges.detach().clone().to(device=device, dtype=torch.long)
    else:
        edge_tensor = torch.tensor(edges, dtype=torch.long, device=device)

    if edge_tensor.ndim != 2:
        raise ValueError("edges must be a 2D edge collection.")

    if edge_tensor.size(0) == 2 and edge_tensor.size(1) != 2:
        edge_tensor = edge_tensor.t()

    if edge_tensor.size(1) != 2:
        raise ValueError("edges must have shape [num_edges, 2] or [2, num_edges].")

    return edge_tensor


def train_mlp_epoch(
    predictor: MlpLinkPredictor,
    x: Any,
    train_edges: Any,
    optimizer: Any,
    batch_size: int,
    epoch: int | None = None,
    total_epochs: int | None = None,
) -> float:
    """Train the MLP link predictor for one epoch."""
    torch = _require_torch()
    from torch.utils.data import DataLoader

    predictor.train()
    total_loss = 0.0
    total_examples = 0

    batches = DataLoader(range(train_edges.size(0)), batch_size=batch_size, shuffle=True)
    description = "MLP batches"
    if epoch is not None and total_epochs is not None:
        description = f"MLP epoch {epoch}/{total_epochs}"

    for perm in progress_bar(batches, desc=description, leave=False):
        optimizer.zero_grad()
        edge = train_edges[perm]

        pos_out = predictor(x[edge[:, 0]], x[edge[:, 1]]).view(-1)
        pos_loss = -torch.log(pos_out + 1e-15).mean()

        neg_edge = torch.randint(0, x.size(0), edge.shape, dtype=torch.long, device=x.device)
        neg_out = predictor(x[neg_edge[:, 0]], x[neg_edge[:, 1]]).view(-1)
        neg_loss = -torch.log(1 - neg_out + 1e-15).mean()

        loss = pos_loss + neg_loss
        loss.backward()
        optimizer.step()

        total_loss += float(loss.item()) * edge.size(0)
        total_examples += int(edge.size(0))

    return total_loss / max(total_examples, 1)


def score_edges_mlp(
    predictor: MlpLinkPredictor,
    x: Any,
    edges: Any,
    batch_size: int,
    description: str = "MLP score batches",
) -> list[float]:
    """Score candidate edges with a trained MLP predictor."""
    torch = _require_torch()
    from torch.utils.data import DataLoader

    predictor.eval()
    edge_tensor = _edge_tensor(edges, x.device)
    scores = []

    with torch.no_grad():
        batches = DataLoader(range(edge_tensor.size(0)), batch_size=batch_size)
        for perm in progress_bar(batches, desc=description, leave=False):
            edge = edge_tensor[perm]
            batch_scores = predictor(x[edge[:, 0]], x[edge[:, 1]]).view(-1)
            scores.extend(float(value) for value in batch_scores.cpu())

    return scores


def run_mlp(
    data: Any,
    split_edge: dict[str, dict[str, Any]],
    config: Any,
    dataset_name: str = DEFAULT_DATASET_NAME,
    ks: tuple[int, ...] = DEFAULT_HITS_KS,
) -> dict[str, Any]:
    """Train and evaluate the feature-only MLP baseline."""
    torch = _require_torch()

    if data is None or not hasattr(data, "x") or data.x is None:
        raise ValueError("MLP requires node features in data.x.")

    hyperparameters = config.hyperparameters
    device = _select_device(config.device)
    torch.manual_seed(config.seed)
    logger.info(
        "Starting MLP: scale=%s epochs=%s batch_size=%s device=%s",
        config.dataset_scale,
        hyperparameters.get("epochs", 200),
        hyperparameters.get("batch_size", 64 * 1024),
        device,
    )

    start_memory_mb = get_memory_usage_mb()
    with track_resources() as usage:
        x = data.x.to(device=device, dtype=torch.float)
        train_edges = _edge_tensor(split_edge["train"]["edge"], device)

        predictor = MlpLinkPredictor(
            in_channels=x.size(-1),
            hidden_channels=hyperparameters.get("hidden_channels", 256),
            out_channels=1,
            num_layers=hyperparameters.get("num_layers", 3),
            dropout=hyperparameters.get("dropout", 0.0),
        ).to(device)
        optimizer = torch.optim.Adam(
            predictor.parameters(),
            lr=hyperparameters.get("learning_rate", 0.01),
        )

        losses = []
        epochs = hyperparameters.get("epochs", 200)
        for epoch in progress_bar(range(1, epochs + 1), desc="MLP epochs"):
            loss = train_mlp_epoch(
                predictor=predictor,
                x=x,
                train_edges=train_edges,
                optimizer=optimizer,
                batch_size=hyperparameters.get("batch_size", 64 * 1024),
                epoch=epoch,
                total_epochs=epochs,
            )
            losses.append(loss)
            logger.info("MLP epoch %s/%s loss=%.6f", epoch, epochs, loss)

        logger.info("Scoring MLP validation/test edges")
        positive_scores = {}
        negative_scores = {}
        for split in progress_bar(("valid", "test"), desc="MLP scoring"):
            if "edge" not in split_edge.get(split, {}) or "edge_neg" not in split_edge.get(split, {}):
                continue

            positive_scores[split] = score_edges_mlp(
                predictor=predictor,
                x=x,
                edges=split_edge[split]["edge"],
                batch_size=hyperparameters.get("batch_size", 64 * 1024),
                description=f"MLP {split} positive",
            )
            negative_scores[split] = score_edges_mlp(
                predictor=predictor,
                x=x,
                edges=split_edge[split]["edge_neg"],
                batch_size=hyperparameters.get("batch_size", 64 * 1024),
                description=f"MLP {split} negative",
            )

        metrics = evaluate_link_prediction(
            positive_scores=positive_scores,
            negative_scores=negative_scores,
            ks=ks,
            dataset_name=dataset_name,
        )
        logger.info("Completed MLP metrics=%s", metrics)

    return {
        "method_name": "mlp",
        "dataset_name": dataset_name,
        "metrics": metrics,
        "losses": losses,
        "runtime_seconds": usage.runtime_seconds,
        "memory_mb": usage.end_memory_mb,
        "memory_delta_mb": usage.end_memory_mb - start_memory_mb,
        "config": dict(hyperparameters),
        "status": "completed",
    }
