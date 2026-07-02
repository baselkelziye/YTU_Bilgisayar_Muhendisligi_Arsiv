import os
import argparse
from pathlib import Path
from datetime import datetime
import numpy as np
import matplotlib.pyplot as plt

from experiment.run_opt import run
from plotting.plot_results import plot_trajectory, plot_values
from objectives.registry import get_objective, OBJECTIVES


def ensure_dir(path: Path) -> None:
    path.mkdir(parents=True, exist_ok=True)


def save_numpy_and_config(outdir: Path, xs: np.ndarray, fs: np.ndarray, config: dict) -> None:
    ensure_dir(outdir)
    np.save(outdir / "trajectory.npy", xs)
    np.save(outdir / "values.npy", fs)
    import json
    with open(outdir / "config.json", "w", encoding="utf-8") as f:
        json.dump(config, f, indent=2)


def compose_grid(image_paths: list[list[Path]], save_path: Path, titles: list[list[str]] | None = None, figsize=(12, 2.4)) -> None:
    rows = len(image_paths)
    cols = len(image_paths[0]) if rows > 0 else 0
    
    # Images are square (1:1), so for 2 columns: width = 2 * row_height
    row_height = figsize[1]
    fig_width = cols * row_height  # 2 columns = 2:1, 3 columns = 3:1, etc.
    fig_height = row_height * rows
    
    fig, axes = plt.subplots(rows, cols, figsize=(fig_width, fig_height))
    if rows == 1 and cols == 1:
        axes = [[axes]]
    elif rows == 1:
        axes = [axes]
    elif cols == 1:
        axes = [[ax] for ax in axes]

    for i in range(rows):
        for j in range(cols):
            ax = axes[i][j]
            img = plt.imread(str(image_paths[i][j]))
            ax.imshow(img)
            ax.axis("off")
            ax.set_aspect('equal')  # Preserve square aspect ratio
            ax.margins(0)
            if titles is not None and i < len(titles) and j < len(titles[i]):
                ax.set_title(titles[i][j], fontsize=9, pad=2)

    ensure_dir(save_path.parent)
    top_margin = 0.92 if titles is not None else 1.0
    fig.subplots_adjust(
        wspace=0.0,
        hspace=0.1,
        left=0.0,
        right=1.0,
        top=top_margin,
        bottom=0.0
    )
    fig.savefig(save_path, dpi=300, bbox_inches="tight", pad_inches=0.0)
    plt.close(fig)


def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(description="Run multiple optimizers across multiple objectives and compose plots")
    p.add_argument("--objectives", type=str, nargs="+", default=["rosenbrock"], choices=list(OBJECTIVES.keys()), help="Objectives to run")
    p.add_argument("--algos", type=str, nargs="+", default=["adam", "adamv1", "adamv2", "sgd", "adagrad"], help="Optimizers to run")
    p.add_argument("--iters", type=int, default=1000, help="Max iterations")
    p.add_argument("--outroot", type=str, default="outputs", help="Root output dir")
    p.add_argument("--random-start", action="store_true", help="Sample start uniformly within objective bounds")
    p.add_argument("--seed", type=int, default=None, help="Random seed for start sampling")
    return p.parse_args()


def main():
    args = parse_args()

    # Defaults per algo
    lr_default = {
        "adam": 0.01,
        "adamv1": 0.01,
        "adamv2": 0.01,
        "sgd": 0.01,
        "adagrad": 0.1,
    }
    beta1 = 0.9
    beta2 = 0.999
    eps = 1e-8

    # Create directories: outputs for data, comp/<timestamp> for images
    timestamp = datetime.now().strftime("%Y%m%d-%H%M%S")
    comp_root = Path("comp") / timestamp
    ensure_dir(comp_root)
    root_outputs = Path(args.outroot)

    rng = np.random.default_rng(args.seed)

    # Main optimization loop
    for obj_name in args.objectives:
        obj_fn, obj_grad, bounds, start_default, global_mins = get_objective(obj_name)
        if args.random_start:
            (x_min, x_max), (y_min, y_max) = bounds
            start = np.array([rng.uniform(x_min, x_max), rng.uniform(y_min, y_max)], dtype=float)
            start_source = "random"
        else:
            start = np.array(start_default, dtype=float)
            start_source = "default"

        print(f"[START] objective={obj_name} run_ts={timestamp} start={start.tolist()} source={start_source}")

        grid_images: list[list[Path]] = []
        grid_titles: list[list[str]] = []

        for algo in args.algos:
            # Data files go to outputs/
            data_outdir = root_outputs / obj_name / algo
            # Image files go to comp/<timestamp>/
            img_outdir = comp_root / obj_name / algo
            ensure_dir(img_outdir)
            lr = lr_default.get(algo, 0.005)

            print(f"  [RUN] algo={algo} objective={obj_name} lr={lr} iters={args.iters}")

            xs, fs = run(
                algo=algo,
                start=start,
                learning_rate=lr,
                beta1=beta1,
                beta2=beta2,
                epsilon=eps,
                max_iters=args.iters,
                objective=obj_name,
            )

            print(f"  [OK ] algo={algo} objective={obj_name} run finished: steps={len(fs)-1}")

            save_numpy_and_config(
                data_outdir,
                xs,
                fs,
                {
                    "algo": algo,
                    "objective": obj_name,
                    "start": start.tolist(),
                    "start_source": start_source,
                    "lr": lr,
                    "beta1": beta1,
                    "beta2": beta2,
                    "eps": eps,
                    "iters": args.iters,
                    "timestamp": timestamp,
                },
            )

            traj_path = img_outdir / f"{obj_name}_trajectory.png"
            vals_path = img_outdir / f"{obj_name}_values.png"
            plot_trajectory(
                xs,
                fs,
                bounds=bounds,
                algo_label=algo.upper(),
                objective_fn=obj_fn,
                objective_label=obj_name,
                global_mins=global_mins,
                outpath=str(traj_path),
            )
            plot_values(fs, outpath=str(vals_path))

            print(f"  [SAVE] data -> {data_outdir}, images -> {img_outdir}")

            grid_images.append([traj_path, vals_path])
            grid_titles.append([f"{obj_name}: {algo.upper()} trajectory", f"{obj_name}: {algo.upper()} values"]) 

        comp_path = comp_root / f"{obj_name}.png"
        compose_grid(grid_images, comp_path, titles=grid_titles, figsize=(12, 2.4))

        print(f"[DONE] objective={obj_name} composed grid -> {comp_path}")


if __name__ == "__main__":
    main()


