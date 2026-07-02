import argparse
from pathlib import Path
import numpy as np

from plotting.plot_results import plot_trajectory, plot_values


def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(description="Plot optimizer results from saved numpy files")
    p.add_argument("--indir", type=str, default="outputs", help="Directory containing trajectory.npy and values.npy")
    p.add_argument("--traj", type=str, default="trajectory.npy", help="Trajectory filename inside indir")
    p.add_argument("--vals", type=str, default="values.npy", help="Values filename inside indir")
    p.add_argument("--algo", type=str, default=None, help="Algorithm label for titles (defaults to reading config.json if present)")
    p.add_argument("--traj-out", type=str, default="trajectory.png", help="Output image name for path plot")
    p.add_argument("--vals-out", type=str, default="values.png", help="Output image name for values plot")
    return p.parse_args()


def main():
    args = parse_args()
    indir = Path(args.indir)
    xs = np.load(indir / args.traj)
    fs = np.load(indir / args.vals)

    algo_label = args.algo
    if algo_label is None:
        cfg_path = indir / "config.json"
        if cfg_path.exists():
            try:
                import json
                with open(cfg_path, "r", encoding="utf-8") as f:
                    cfg = json.load(f)
                algo_label = cfg.get("algo", "Adam")
            except Exception:
                algo_label = "Adam"
        else:
            algo_label = "Adam"

    plot_trajectory(xs, fs, algo_label=algo_label, outpath=str(indir / args.traj_out))
    plot_values(fs, outpath=str(indir / args.vals_out))


if __name__ == "__main__":
    main()


