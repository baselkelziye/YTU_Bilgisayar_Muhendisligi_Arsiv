"""Dataset loading helpers for the ogbl-collab link prediction task."""

from dataclasses import dataclass
import os
from pathlib import Path
from typing import Any
import warnings

from src.evaluation.metrics import DEFAULT_DATASET_NAME
from src.experiments.paths import DATASET_DIR


@dataclass(slots=True)
class CollabDataBundle:
    """Project-level container for OGB collab data and split information."""

    dataset_name: str
    dataset_root: Path
    data: Any
    split_edge: dict[str, dict[str, Any]]


def _configure_torch_dataset_loading() -> None:
    """Allow trusted OGB/PyG dataset pickle files to load on PyTorch 2.6+."""
    # OGB's current PyG dataset loader calls torch.load() without weights_only.
    # PyTorch 2.6+ treats that as weights_only=True, which rejects processed
    # dataset and split files containing PyG/NumPy objects.
    os.environ.setdefault("TORCH_FORCE_NO_WEIGHTS_ONLY_LOAD", "1")
    warnings.filterwarnings(
        "ignore",
        message=r"Environment variable TORCH_FORCE_NO_WEIGHTS_ONLY_LOAD detected.*",
        category=UserWarning,
    )
    warnings.filterwarnings(
        "ignore",
        message=r"pkg_resources is deprecated as an API.*",
        category=UserWarning,
    )
    warnings.filterwarnings(
        "ignore",
        message=r"dtype\(\): align should be passed as Python or NumPy boolean.*",
        category=Warning,
    )
    warnings.filterwarnings(
        "ignore",
        message=r"CUDA initialization: Unexpected error from cudaGetDeviceCount.*",
        category=UserWarning,
    )

    try:
        import torch

        if hasattr(torch, "serialization") and hasattr(torch.serialization, "add_safe_globals"):
            # Allowlist common PyG attribute containers used inside processed OGB datasets.
            # Newer PyG versions include these; older ones may not.
            safe: list[object] = []
            try:
                from torch_geometric.data.data import DataEdgeAttr  # type: ignore

                safe.append(DataEdgeAttr)
            except Exception:
                pass
            try:
                from torch_geometric.data.data import DataTensorAttr  # type: ignore

                safe.append(DataTensorAttr)
            except Exception:
                pass
            try:
                from torch_geometric.data.storage import BaseStorage  # type: ignore
                from torch_geometric.data.storage import EdgeStorage
                from torch_geometric.data.storage import GlobalStorage
                from torch_geometric.data.storage import NodeStorage

                safe.extend([BaseStorage, EdgeStorage, GlobalStorage, NodeStorage])
            except Exception:
                pass

            if safe:
                torch.serialization.add_safe_globals(safe)
    except Exception:
        # Best-effort compatibility; if this fails, OGB may still load in older stacks.
        pass


def load_collab_dataset(
    dataset_name: str = DEFAULT_DATASET_NAME,
    root: Path | str = DATASET_DIR,
) -> Any:
    """Load the OGB PyG link prediction dataset."""
    _configure_torch_dataset_loading()

    from ogb.linkproppred import PygLinkPropPredDataset

    return PygLinkPropPredDataset(name=dataset_name, root=str(root))


def load_edge_split(dataset: Any) -> dict[str, dict[str, Any]]:
    """Return the official train/validation/test edge split."""
    _configure_torch_dataset_loading()
    return dataset.get_edge_split()


def load_collab_data_bundle(
    dataset_name: str = DEFAULT_DATASET_NAME,
    root: Path | str = DATASET_DIR,
) -> CollabDataBundle:
    """Load dataset, graph data, and official edge splits together."""
    dataset_root = Path(root)
    dataset = load_collab_dataset(dataset_name=dataset_name, root=dataset_root)
    data = dataset[0]
    split_edge = load_edge_split(dataset)

    return CollabDataBundle(
        dataset_name=dataset_name,
        dataset_root=dataset_root,
        data=data,
        split_edge=split_edge,
    )
