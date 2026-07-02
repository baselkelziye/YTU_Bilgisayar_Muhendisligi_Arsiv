"""GCN-based link prediction method."""

import logging
from typing import Any

from src.evaluation.metrics import DEFAULT_DATASET_NAME, DEFAULT_HITS_KS
from src.evaluation.metrics import evaluate_link_prediction
from src.evaluation.runtime import get_memory_usage_mb, track_resources
from src.experiments.progress import progress_bar
from src.methods.mlp import _edge_tensor, _require_torch


logger = logging.getLogger(__name__)


class GcnEncoder(_require_torch().nn.Module):
    """GCN encoder that maps node features to node embeddings."""

    def __init__(
        self,
        in_channels: int,
        hidden_channels: int,
        out_channels: int,
        num_layers: int = 3,
        dropout: float = 0.0,
    ) -> None:
        super().__init__()
        torch = _require_torch()
        from torch_geometric.nn import GCNConv

        if num_layers < 2:
            raise ValueError("num_layers must be at least 2.")

        self.convs = torch.nn.ModuleList()
        self.convs.append(GCNConv(in_channels, hidden_channels))
        for _ in range(num_layers - 2):
            self.convs.append(GCNConv(hidden_channels, hidden_channels))
        self.convs.append(GCNConv(hidden_channels, out_channels))
        self.dropout = dropout

    def reset_parameters(self) -> None:
        """Reset all GCN convolution parameters."""
        for conv in self.convs:
            conv.reset_parameters()

    def forward(self, x: Any, edge_index: Any) -> Any:
        """Encode nodes with GCN message passing."""
        torch = _require_torch()

        for conv in self.convs[:-1]:
            x = conv(x, edge_index)
            x = torch.nn.functional.relu(x)
            x = torch.nn.functional.dropout(x, p=self.dropout, training=self.training)

        return self.convs[-1](x, edge_index)


class GcnLinkPredictor(_require_torch().nn.Module):
    """MLP link predictor used on top of GCN node embeddings."""

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

    def forward(self, h_i: Any, h_j: Any) -> Any:
        """Predict link probabilities from paired node embeddings."""
        torch = _require_torch()
        h = h_i * h_j

        for layer in self.layers[:-1]:
            h = layer(h)
            h = torch.nn.functional.relu(h)
            h = torch.nn.functional.dropout(h, p=self.dropout, training=self.training)

        return torch.sigmoid(self.layers[-1](h))


def _select_device(device: str) -> Any:
    torch = _require_torch()
    if device.startswith("cuda") and not torch.cuda.is_available():
        return torch.device("cpu")
    return torch.device(device)


def _make_message_passing_edge_index(train_edges: Any, device: Any) -> Any:
    torch = _require_torch()
    edge_tensor = _edge_tensor(train_edges, device)
    edge_index = edge_tensor.t().contiguous()
    reverse_edge_index = edge_index.flip(0)
    return torch.cat([edge_index, reverse_edge_index], dim=1)


def train_gcn_epoch(
    encoder: GcnEncoder,
    predictor: GcnLinkPredictor,
    x: Any,
    message_passing_edge_index: Any,
    train_edges: Any,
    optimizer: Any,
    batch_size: int,
    epoch: int | None = None,
    total_epochs: int | None = None,
) -> float:
    """Train the GCN encoder and link predictor for one epoch."""
    torch = _require_torch()
    from torch.utils.data import DataLoader

    encoder.train()
    predictor.train()
    total_loss = 0.0
    total_examples = 0

    batches = DataLoader(range(train_edges.size(0)), batch_size=batch_size, shuffle=True)
    description = "GCN batches"
    if epoch is not None and total_epochs is not None:
        description = f"GCN epoch {epoch}/{total_epochs}"

    for perm in progress_bar(batches, desc=description, leave=False):
        optimizer.zero_grad()

        h = encoder(x, message_passing_edge_index)
        edge = train_edges[perm]
        pos_out = predictor(h[edge[:, 0]], h[edge[:, 1]]).view(-1)
        pos_loss = -torch.log(pos_out + 1e-15).mean()

        neg_edge = torch.randint(0, x.size(0), edge.shape, dtype=torch.long, device=x.device)
        neg_out = predictor(h[neg_edge[:, 0]], h[neg_edge[:, 1]]).view(-1)
        neg_loss = -torch.log(1 - neg_out + 1e-15).mean()

        loss = pos_loss + neg_loss
        loss.backward()
        torch.nn.utils.clip_grad_norm_(encoder.parameters(), 1.0)
        torch.nn.utils.clip_grad_norm_(predictor.parameters(), 1.0)
        optimizer.step()

        total_loss += float(loss.item()) * edge.size(0)
        total_examples += int(edge.size(0))

    return total_loss / max(total_examples, 1)


def score_edges_gcn(
    encoder: GcnEncoder,
    predictor: GcnLinkPredictor,
    x: Any,
    message_passing_edge_index: Any,
    edges: Any,
    batch_size: int,
    description: str = "GCN score batches",
) -> list[float]:
    """Score candidate edges with a trained GCN model."""
    torch = _require_torch()
    from torch.utils.data import DataLoader

    encoder.eval()
    predictor.eval()
    edge_tensor = _edge_tensor(edges, x.device)
    scores = []

    with torch.no_grad():
        h = encoder(x, message_passing_edge_index)
        batches = DataLoader(range(edge_tensor.size(0)), batch_size=batch_size)
        for perm in progress_bar(batches, desc=description, leave=False):
            edge = edge_tensor[perm]
            batch_scores = predictor(h[edge[:, 0]], h[edge[:, 1]]).view(-1)
            scores.extend(float(value) for value in batch_scores.cpu())

    return scores


def run_gcn(
    data: Any,
    split_edge: dict[str, dict[str, Any]],
    config: Any,
    dataset_name: str = DEFAULT_DATASET_NAME,
    ks: tuple[int, ...] = DEFAULT_HITS_KS,
) -> dict[str, Any]:
    """Train and evaluate the GCN link prediction method."""
    torch = _require_torch()

    if data is None or not hasattr(data, "x") or data.x is None:
        raise ValueError("GCN requires node features in data.x.")

    hyperparameters = config.hyperparameters
    device = _select_device(config.device)
    torch.manual_seed(config.seed)
    logger.info(
        "Starting GCN: scale=%s epochs=%s batch_size=%s device=%s",
        config.dataset_scale,
        hyperparameters.get("epochs", 400),
        hyperparameters.get("batch_size", 64 * 1024),
        device,
    )

    start_memory_mb = get_memory_usage_mb()
    with track_resources() as usage:
        x = data.x.to(device=device, dtype=torch.float)
        train_edges = _edge_tensor(split_edge["train"]["edge"], device)
        message_passing_edge_index = _make_message_passing_edge_index(train_edges, device)

        encoder = GcnEncoder(
            in_channels=x.size(-1),
            hidden_channels=hyperparameters.get("hidden_channels", 256),
            out_channels=hyperparameters.get("hidden_channels", 256),
            num_layers=hyperparameters.get("num_layers", 3),
            dropout=hyperparameters.get("dropout", 0.2),
        ).to(device)
        predictor = GcnLinkPredictor(
            in_channels=hyperparameters.get("hidden_channels", 256),
            hidden_channels=hyperparameters.get("hidden_channels", 256),
            out_channels=1,
            num_layers=hyperparameters.get("num_layers", 3),
            dropout=hyperparameters.get("dropout", 0.0),
        ).to(device)
        optimizer = torch.optim.Adam(
            list(encoder.parameters()) + list(predictor.parameters()),
            lr=hyperparameters.get("learning_rate", 0.005),
        )

        losses = []
        epochs = hyperparameters.get("epochs", 400)
        for epoch in progress_bar(range(1, epochs + 1), desc="GCN epochs"):
            loss = train_gcn_epoch(
                encoder=encoder,
                predictor=predictor,
                x=x,
                message_passing_edge_index=message_passing_edge_index,
                train_edges=train_edges,
                optimizer=optimizer,
                batch_size=hyperparameters.get("batch_size", 64 * 1024),
                epoch=epoch,
                total_epochs=epochs,
            )
            losses.append(loss)
            logger.info("GCN epoch %s/%s loss=%.6f", epoch, epochs, loss)

        logger.info("Scoring GCN validation/test edges")
        positive_scores = {}
        negative_scores = {}
        for split in progress_bar(("valid", "test"), desc="GCN scoring"):
            if "edge" not in split_edge.get(split, {}) or "edge_neg" not in split_edge.get(split, {}):
                continue

            positive_scores[split] = score_edges_gcn(
                encoder=encoder,
                predictor=predictor,
                x=x,
                message_passing_edge_index=message_passing_edge_index,
                edges=split_edge[split]["edge"],
                batch_size=hyperparameters.get("batch_size", 64 * 1024),
                description=f"GCN {split} positive",
            )
            negative_scores[split] = score_edges_gcn(
                encoder=encoder,
                predictor=predictor,
                x=x,
                message_passing_edge_index=message_passing_edge_index,
                edges=split_edge[split]["edge_neg"],
                batch_size=hyperparameters.get("batch_size", 64 * 1024),
                description=f"GCN {split} negative",
            )

        metrics = evaluate_link_prediction(
            positive_scores=positive_scores,
            negative_scores=negative_scores,
            ks=ks,
            dataset_name=dataset_name,
        )
        logger.info("Completed GCN metrics=%s", metrics)

    return {
        "method_name": "gcn",
        "dataset_name": dataset_name,
        "metrics": metrics,
        "losses": losses,
        "runtime_seconds": usage.runtime_seconds,
        "memory_mb": usage.end_memory_mb,
        "memory_delta_mb": usage.end_memory_mb - start_memory_mb,
        "config": dict(hyperparameters),
        "status": "completed",
    }
