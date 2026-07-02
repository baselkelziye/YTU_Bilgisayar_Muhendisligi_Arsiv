"""Environment checks for phase 0 setup."""

from __future__ import annotations

import importlib
import json
import platform
import sys
from pathlib import Path


REQUIRED_PACKAGES = ["yaml", "numpy", "pandas"]
REQUIRED_PATHS = ["src", "config", "data", "tests"]


def check_python_version(min_major: int = 3, min_minor: int = 10) -> tuple[bool, str]:
    version = sys.version_info
    ok = (version.major, version.minor) >= (min_major, min_minor)
    return ok, f"{version.major}.{version.minor}.{version.micro}"


def check_packages() -> dict[str, bool]:
    results: dict[str, bool] = {}
    for package in REQUIRED_PACKAGES:
        try:
            importlib.import_module(package)
            results[package] = True
        except Exception:
            results[package] = False
    return results


def check_paths(project_root: Path) -> dict[str, bool]:
    return {path_name: (project_root / path_name).exists() for path_name in REQUIRED_PATHS}


def generate_report(project_root: Path) -> dict:
    py_ok, py_version = check_python_version()
    package_results = check_packages()
    path_results = check_paths(project_root)

    success = py_ok and all(package_results.values()) and all(path_results.values())
    return {
        "success": success,
        "platform": platform.platform(),
        "python_version": py_version,
        "python_ok": py_ok,
        "packages": package_results,
        "paths": path_results,
    }


def main() -> int:
    project_root = Path(__file__).resolve().parents[1]
    report = generate_report(project_root)

    report_path = project_root / "artifacts" / "phase0" / "env_check_report.json"
    report_path.parent.mkdir(parents=True, exist_ok=True)
    report_path.write_text(json.dumps(report, indent=2), encoding="utf-8")

    print(json.dumps(report, indent=2))
    return 0 if report["success"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
