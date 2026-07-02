import argparse
import json
from pathlib import Path
import numpy as np

from optim.adam import Adam, AdamConfig
from optim.adam_variant1 import AdamVariant1, AdamVariant1Config
from optim.adam_variant2 import AdamVariant2, AdamVariant2Config
from optim.sgd import SGD, SGDConfig
from optim.adagrad import Adagrad, AdagradConfig
from objectives.registry import get_objective, OBJECTIVES


def build_optimizer(algo: str, dim: int, lr: float, beta1: float, beta2: float, eps: float, iters: int, momentum: float = 0.0):
    algo = algo.lower()
    if algo == "adam":
        cfg = AdamConfig(learning_rate=lr, beta1=beta1, beta2=beta2, epsilon=eps, max_iters=iters)
        return Adam(dim=dim, config=cfg)
    if algo == "adamv1":
        cfg = AdamVariant1Config(learning_rate=lr, beta1=beta1, beta2=beta2, epsilon=eps, max_iters=iters)
        return AdamVariant1(dim=dim, config=cfg)
    if algo == "adamv2":
        cfg = AdamVariant2Config(learning_rate=lr, beta1=beta1, beta2=beta2, epsilon=eps, max_iters=iters)
        return AdamVariant2(dim=dim, config=cfg)
    if algo == "sgd":
        cfg = SGDConfig(learning_rate=lr, momentum=momentum, max_iters=iters)
        return SGD(dim=dim, config=cfg)
    if algo == "adagrad":
        cfg = AdagradConfig(learning_rate=lr, epsilon=eps, max_iters=iters)
        return Adagrad(dim=dim, config=cfg)
    raise ValueError(f"Unknown algo: {algo}")


def run(
    algo: str,
    start: np.ndarray,
    learning_rate: float = 0.005,
    beta1: float = 0.9,
    beta2: float = 0.999,
    epsilon: float = 1e-8,
    max_iters: int = 2000,
    objective: str = "rosenbrock",
):
    opt = build_optimizer(
        algo=algo,
        dim=start.size,
        lr=learning_rate,
        beta1=beta1,
        beta2=beta2,
        eps=epsilon,
        iters=max_iters,
    )

    obj_fn, obj_grad, _bounds, _start_default, global_mins = get_objective(objective)

    x = start.astype(float)
    xs, fs = [x.copy()], [obj_fn(x)]

    # Prepare early-stop targets (global minima)
    gm_points = None
    gm_values = None
    if global_mins:
        gm_points = np.array(global_mins, dtype=float)
        gm_values = np.array([obj_fn(p) for p in gm_points], dtype=float)
    tol_pos = 1e-3
    tol_val = 1e-6

    for _ in range(max_iters):
        g = obj_grad(x)
        # Gradient clipping to avoid numeric blow-ups
        g_norm = float(np.linalg.norm(g))
        if np.isfinite(g_norm) and g_norm > 1e6:
            g = g * (1e6 / g_norm)

        x = opt.step(x, g)
        xs.append(x.copy())
        f_val = obj_fn(x)
        fs.append(f_val)
        # Early stop if non-finite encountered
        if not (np.isfinite(f_val) and np.all(np.isfinite(x))):
            break
        # Early stop if we reached a global minimum vicinity
        if gm_points is not None:
            dists = np.linalg.norm(gm_points - x[None, :], axis=1)
            close_pos = np.any(dists <= tol_pos)
            close_val = np.any(np.abs(gm_values - f_val) <= tol_val)
            if close_pos or close_val:
                break

    return np.stack(xs), np.array(fs)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run selected optimizer on selected objective function")
    parser.add_argument("--algo", type=str, default="adam", choices=["adam", "adamv1", "adamv2", "adamv3", "sgd", "adagrad"], help="Optimizer to run")
    parser.add_argument("--start", type=float, nargs=2, default=[-1.5, 2.0], help="Initial point x0 y0")
    parser.add_argument("--lr", type=float, default=0.005, help="Learning rate")
    parser.add_argument("--beta1", type=float, default=0.9, help="beta1")
    parser.add_argument("--beta2", type=float, default=0.999, help="beta2")
    parser.add_argument("--eps", type=float, default=1e-8, help="epsilon")
    parser.add_argument("--momentum", type=float, default=0.0, help="SGD momentum (only used for sgd)")
    parser.add_argument("--iters", type=int, default=2000, help="Max iterations")
    parser.add_argument("--outdir", type=str, default="outputs", help="Output directory for results")
    parser.add_argument("--objective", type=str, default="rosenbrock", choices=list(OBJECTIVES.keys()), help="Objective function")
    return parser.parse_args()


def main():
    args = parse_args()
    start = np.array(args.start, dtype=float)
    xs, fs = run(
        algo=args.algo,
        start=start,
        learning_rate=args.lr,
        beta1=args.beta1,
        beta2=args.beta2,
        epsilon=args.eps,
        max_iters=args.iters,
        objective=args.objective,
    )

    outdir = Path(args.outdir)
    outdir.mkdir(parents=True, exist_ok=True)
    np.save(outdir / "trajectory.npy", xs)
    np.save(outdir / "values.npy", fs)
    with open(outdir / "config.json", "w", encoding="utf-8") as f:
        json.dump({
            "algo": args.algo,
            "objective": args.objective,
            "start": args.start,
            "lr": args.lr,
            "momentum": args.momentum,
            "beta1": args.beta1,
            "beta2": args.beta2,
            "eps": args.eps,
            "iters": args.iters,
        }, f, indent=2)


if __name__ == "__main__":
    main()


