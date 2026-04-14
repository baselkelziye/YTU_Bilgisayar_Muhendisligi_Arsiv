#!/usr/bin/env python3
"""Release helper script with pyproject.toml version bump and git tagging.

Flow:
1) Read current version from pyproject.toml and bump it.
2) Auto-commit release changes on source branch when needed.
3) Merge with main flow (or same-branch release on main).
4) Create annotated tag from the bumped version.
5) Push main and tag to remote.
"""

from __future__ import annotations

import argparse
import re
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path


SEMVER_RE = re.compile(r"^(?P<prefix>v?)(?P<major>\d+)\.(?P<minor>\d+)\.(?P<patch>\d+)$")
PYPROJECT_VERSION_RE = re.compile(r'(?m)^(version\s*=\s*")(?P<version>\d+\.\d+\.\d+)("\s*)$')


@dataclass(frozen=True)
class SemVer:
    major: int
    minor: int
    patch: int

    def bump(self, kind: str) -> "SemVer":
        if kind == "major":
            return SemVer(self.major + 1, 0, 0)
        if kind == "minor":
            return SemVer(self.major, self.minor + 1, 0)
        if kind == "patch":
            return SemVer(self.major, self.minor, self.patch + 1)
        raise ValueError(f"Unsupported bump kind: {kind}")

    def __str__(self) -> str:
        return f"{self.major}.{self.minor}.{self.patch}"


def run_git(cmd: list[str], check: bool = True, capture: bool = False, dry_run: bool = False) -> str:
    full_cmd = ["git", *cmd]
    print("$", " ".join(full_cmd))
    if dry_run:
        return ""
    completed = subprocess.run(
        full_cmd,
        check=check,
        text=True,
        capture_output=capture,
    )
    if capture:
        return completed.stdout.strip()
    return ""


def ensure_git_repo(dry_run: bool) -> None:
    try:
        run_git(["rev-parse", "--is-inside-work-tree"], capture=True, dry_run=dry_run)
    except subprocess.CalledProcessError as exc:
        raise RuntimeError("Current directory is not a git repository.") from exc


def get_worktree_status(dry_run: bool) -> str:
    if dry_run:
        return ""
    return run_git(["status", "--porcelain"], capture=True, dry_run=False)


def read_pyproject_version(pyproject_path: Path) -> SemVer:
    if not pyproject_path.exists():
        raise RuntimeError(f"pyproject.toml not found: {pyproject_path}")

    content = pyproject_path.read_text(encoding="utf-8")
    match = PYPROJECT_VERSION_RE.search(content)
    if not match:
        raise RuntimeError("Could not find 'version = \"X.Y.Z\"' in pyproject.toml")

    version_str = match.group("version")
    semver_match = SEMVER_RE.match(version_str)
    if not semver_match:
        raise RuntimeError(f"Invalid semantic version in pyproject.toml: {version_str}")

    return SemVer(
        major=int(semver_match.group("major")),
        minor=int(semver_match.group("minor")),
        patch=int(semver_match.group("patch")),
    )


def write_pyproject_version(pyproject_path: Path, new_version: SemVer, dry_run: bool) -> None:
    content = pyproject_path.read_text(encoding="utf-8")
    new_content, count = PYPROJECT_VERSION_RE.subn(
        rf'\g<1>{new_version}\g<3>',
        content,
        count=1,
    )
    if count != 1:
        raise RuntimeError("Could not update version in pyproject.toml")

    if dry_run:
        print(f"[dry-run] pyproject.toml version -> {new_version}")
        return

    pyproject_path.write_text(new_content, encoding="utf-8")


def maybe_create_release_commit(
    source_branch: str,
    auto_commit: bool,
    commit_message: str,
    dry_run: bool,
) -> None:
    run_git(["checkout", source_branch], dry_run=dry_run)
    status = get_worktree_status(dry_run=dry_run)

    if dry_run:
        return

    if not status:
        return

    if not auto_commit:
        raise RuntimeError("Worktree is not clean. Use --auto-commit flow or commit/stash manually.")

    print("\nDetected uncommitted changes. A release commit will be created on source branch.")
    print(f"- Source branch  : {source_branch}")
    print(f"- Commit message : {commit_message}")
    run_git(["add", "-A"], dry_run=False)
    run_git(["commit", "-m", commit_message], dry_run=False)


def current_branch(dry_run: bool) -> str:
    if dry_run:
        return "feature-branch"
    return run_git(["rev-parse", "--abbrev-ref", "HEAD"], capture=True, dry_run=False)


def parse_tag(tag_name: str, expected_prefix: str) -> SemVer | None:
    match = SEMVER_RE.match(tag_name)
    if not match:
        return None
    prefix = match.group("prefix")
    if prefix != expected_prefix:
        return None
    return SemVer(
        major=int(match.group("major")),
        minor=int(match.group("minor")),
        patch=int(match.group("patch")),
    )


def create_release(
    bump_kind: str,
    release_note: str,
    remote: str,
    base_branch: str,
    source_branch: str,
    tag_prefix: str,
    auto_commit: bool,
    commit_message: str,
    dry_run: bool,
) -> None:
    ensure_git_repo(dry_run=dry_run)
    same_branch_release = source_branch == base_branch
    pyproject_path = Path("pyproject.toml")

    current_version = read_pyproject_version(pyproject_path)
    next_version = current_version.bump(bump_kind)
    write_pyproject_version(pyproject_path, next_version, dry_run=dry_run)

    final_commit_message = commit_message or f"chore: release {next_version}"

    maybe_create_release_commit(
        source_branch=source_branch,
        auto_commit=auto_commit,
        commit_message=final_commit_message,
        dry_run=dry_run,
    )

    # Always fetch latest refs before merging.
    run_git(["fetch", remote], dry_run=dry_run)

    if same_branch_release:
        # Source and base are the same branch: only sync with remote.
        run_git(["checkout", base_branch], dry_run=dry_run)
        run_git(["pull", "--ff-only", remote, base_branch], dry_run=dry_run)
    else:
        # Step 1: merge base into source branch.
        run_git(["merge", "--no-ff", "--no-edit", f"{remote}/{base_branch}"], dry_run=dry_run)

        # Step 2: move to base branch and merge source into base.
        run_git(["checkout", base_branch], dry_run=dry_run)
        run_git(["pull", "--ff-only", remote, base_branch], dry_run=dry_run)
        run_git(["merge", "--no-ff", "--no-edit", source_branch], dry_run=dry_run)

    tag_name = f"{tag_prefix}{next_version}"

    if not dry_run:
        existing = run_git(["tag", "--list", tag_name], capture=True, dry_run=False)
        if existing:
            raise RuntimeError(f"Tag already exists: {tag_name}")

    print("\nRelease summary")
    print(f"- Source branch : {source_branch}")
    print(f"- Base branch   : {base_branch}")
    print(f"- Release mode  : {'same-branch' if same_branch_release else 'merge-branch'}")
    print(f"- Old version   : {current_version}")
    print(f"- Bump kind     : {bump_kind}")
    print(f"- New tag       : {tag_name}")
    print(f"- Note          : {release_note}")

    run_git(["tag", "-a", tag_name, "-m", release_note], dry_run=dry_run)
    run_git(["push", remote, base_branch], dry_run=dry_run)
    run_git(["push", remote, tag_name], dry_run=dry_run)

    print("\nRelease completed successfully.")


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Create release tag after version bump and merge flow.")
    parser.add_argument("bump", choices=["major", "minor", "patch"], help="SemVer bump type")
    parser.add_argument("note", help="Release note for annotated tag")
    parser.add_argument("--remote", default="origin", help="Git remote name (default: origin)")
    parser.add_argument("--base", default="main", help="Base branch to release from (default: main)")
    parser.add_argument("--source", help="Source branch to merge into base (default: current branch)")
    parser.add_argument("--tag-prefix", default="v", help="Tag prefix (default: v)")
    parser.add_argument(
        "--no-auto-commit",
        action="store_true",
        help="Disable automatic release commit when worktree is dirty",
    )
    parser.add_argument(
        "--commit-message",
        default="",
        help="Commit message for automatic release commit (default: chore: release X.Y.Z)",
    )
    parser.add_argument("--dry-run", action="store_true", help="Print commands without executing")
    return parser


def main() -> int:
    parser = build_parser()
    args = parser.parse_args()

    try:
        source_branch = args.source or current_branch(dry_run=args.dry_run)
        create_release(
            bump_kind=args.bump,
            release_note=args.note,
            remote=args.remote,
            base_branch=args.base,
            source_branch=source_branch,
            tag_prefix=args.tag_prefix,
            auto_commit=not args.no_auto_commit,
            commit_message=args.commit_message,
            dry_run=args.dry_run,
        )
    except subprocess.CalledProcessError as exc:
        print(f"Git command failed with exit code {exc.returncode}.", file=sys.stderr)
        return exc.returncode
    except RuntimeError as exc:
        print(f"Error: {exc}", file=sys.stderr)
        return 1
    except KeyboardInterrupt:
        print("Interrupted.", file=sys.stderr)
        return 130

    return 0


if __name__ == "__main__":
    raise SystemExit(main())