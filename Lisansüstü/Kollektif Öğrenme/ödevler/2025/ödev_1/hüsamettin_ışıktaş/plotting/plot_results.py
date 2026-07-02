from pathlib import Path
import numpy as np
import matplotlib.pyplot as plt

from typing import Callable


def plot_trajectory(
    traj: np.ndarray,
    values: np.ndarray | None = None,
    bounds=(( -2.0, 2.0), (-1.0, 3.0)),
    levels: int = 40,
    figsize=(7, 6),
    algo_label: str = "Adam",
    objective_fn: Callable[[np.ndarray], float] | None = None,
    objective_label: str | None = None,
    global_mins: list[list[float]] | None = None,
    outpath: str | None = None,
):
    (x_min, x_max), (y_min, y_max) = bounds
    xs = np.linspace(x_min, x_max, 400)
    ys = np.linspace(y_min, y_max, 400)
    XX, YY = np.meshgrid(xs, ys)
    ZZ = np.zeros_like(XX)
    if objective_fn is not None:
        with np.errstate(over='ignore', invalid='ignore'):
            for i in range(XX.shape[0]):
                for j in range(XX.shape[1]):
                    val = objective_fn(np.array([XX[i, j], YY[i, j]]))
                    ZZ[i, j] = val
        # Mask non-finite values to keep contour stable
        import numpy.ma as ma
        ZZ = ma.array(ZZ, mask=~np.isfinite(ZZ))

    fig, ax = plt.subplots(figsize=figsize)
    cs = ax.contour(XX, YY, ZZ, levels=levels, cmap="viridis", linewidths=0.8)
    # Removed clabel to avoid number clutter - color and line spacing convey the information

    ax.plot(traj[:, 0], traj[:, 1], color="crimson", lw=2, label=f"{algo_label} path")
    ax.scatter(traj[0, 0], traj[0, 1], color="blue", s=60, label="start")
    if global_mins:
        gmins = np.array(global_mins, dtype=float)
        ax.scatter(gmins[:, 0], gmins[:, 1], color="green", s=60, label="global min(s)")
    title_obj = objective_label or "Objective"
    ax.set_title(f"{algo_label} on {title_obj}")
    ax.set_xlabel("x")
    ax.set_ylabel("y")
    ax.legend()
    ax.set_xlim(x_min, x_max)
    ax.set_ylim(y_min, y_max)

    if outpath is not None:
        Path(outpath).parent.mkdir(parents=True, exist_ok=True)
        fig.savefig(outpath, dpi=300, bbox_inches="tight", pad_inches=0.1)
    return fig, ax


def plot_values(values: np.ndarray, figsize=(7, 4), outpath: str | None = None):
    fig, ax = plt.subplots(figsize=figsize)
    ax.plot(values, color="black")
    ax.set_title("Objective value per iteration")
    ax.set_xlabel("iteration")
    ax.set_ylabel("f(x)")
    ax.grid(True, ls=":", alpha=0.5)
    if outpath is not None:
        Path(outpath).parent.mkdir(parents=True, exist_ok=True)
        fig.savefig(outpath, dpi=300, bbox_inches="tight", pad_inches=0.1)
    return fig, ax


def plot_objective(
    bounds=(( -2.0, 2.0), (-1.0, 3.0)),
    levels: int = 40,
    figsize=(7, 6),
    objective_fn: Callable[[np.ndarray], float] | None = None,
    objective_label: str | None = None,
    outpath: str | None = None,
):
    """Plot only the objective function contours without any trajectory or points."""
    (x_min, x_max), (y_min, y_max) = bounds
    xs = np.linspace(x_min, x_max, 400)
    ys = np.linspace(y_min, y_max, 400)
    XX, YY = np.meshgrid(xs, ys)
    ZZ = np.zeros_like(XX)
    if objective_fn is not None:
        with np.errstate(over='ignore', invalid='ignore'):
            for i in range(XX.shape[0]):
                for j in range(XX.shape[1]):
                    val = objective_fn(np.array([XX[i, j], YY[i, j]]))
                    ZZ[i, j] = val
        # Mask non-finite values to keep contour stable
        import numpy.ma as ma
        ZZ = ma.array(ZZ, mask=~np.isfinite(ZZ))

    fig, ax = plt.subplots(figsize=figsize)
    cs = ax.contour(XX, YY, ZZ, levels=levels, cmap="viridis", linewidths=0.8)
    
    title_obj = objective_label or "Objective"
    ax.set_title(title_obj)
    ax.set_xlabel("x")
    ax.set_ylabel("y")
    ax.set_xlim(x_min, x_max)
    ax.set_ylim(y_min, y_max)

    if outpath is not None:
        Path(outpath).parent.mkdir(parents=True, exist_ok=True)
        fig.savefig(outpath, dpi=300, bbox_inches="tight", pad_inches=0.1)
    return fig, ax


