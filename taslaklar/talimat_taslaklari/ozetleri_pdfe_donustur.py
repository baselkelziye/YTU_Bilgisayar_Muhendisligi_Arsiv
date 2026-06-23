#!/usr/bin/env python3
"""Build PDF files from subtitle summary markdown files."""

from __future__ import annotations

import argparse
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path


DEFAULT_SUMMARY_DIR_NAME = "altyazi_ozetleri"


def natural_key(path: Path) -> list[object]:
    return [int(part) if part.isdigit() else part.lower() for part in re.split(r"(\d+)", path.name)]


def extract_title(markdown_path: Path) -> str | None:
    for line in markdown_path.read_text(encoding="utf-8").splitlines():
        stripped = line.strip()
        if stripped.startswith("# "):
            return stripped[2:].strip()
    return None


def normalized_pdf_input(markdown_path: Path, temp_dir: Path) -> Path:
    text = markdown_path.read_text(encoding="utf-8")
    normalized = "".join(char for char in text if ord(char) <= 0xFFFF)
    if normalized == text:
        return markdown_path

    normalized_path = temp_dir / markdown_path.name
    normalized_path.write_text(normalized, encoding="utf-8")
    return normalized_path


def build_command(markdown_path: Path, pdf_path: Path, resource_path: Path) -> list[str]:
    pandoc = shutil.which("pandoc")
    if not pandoc:
        raise RuntimeError("pandoc bulunamadi. PDF uretmek icin pandoc kurulu olmali.")

    command = [
        pandoc,
        str(markdown_path),
        "--from",
        "markdown",
        "--standalone",
        "--resource-path",
        str(resource_path),
        "-V",
        "papersize=a4",
        "-V",
        "geometry:margin=22mm",
        "-V",
        "lang=tr-TR",
        "-o",
        str(pdf_path),
    ]

    if shutil.which("xelatex"):
        command.extend(
            [
                "--pdf-engine=xelatex",
                "-V",
                "mainfont=DejaVu Serif",
                "-V",
                "sansfont=DejaVu Sans",
                "-V",
                "monofont=DejaVu Sans Mono",
            ]
        )

    title = extract_title(markdown_path)
    if title:
        command.extend(["--metadata", f"title={title}"])

    return command


def convert(markdown_path: Path, target_dir: Path, force: bool) -> str:
    pdf_path = target_dir / f"{markdown_path.stem}.pdf"
    if (
        pdf_path.exists()
        and pdf_path.stat().st_mtime >= markdown_path.stat().st_mtime
        and not force
    ):
        return f"atlandi: {pdf_path.name}"

    with tempfile.TemporaryDirectory() as temp_dir_name:
        pdf_input = normalized_pdf_input(markdown_path, Path(temp_dir_name))
        command = build_command(pdf_input, pdf_path, markdown_path.parent)
        subprocess.run(command, check=True)
    return f"olusturuldu: {pdf_path.name}"


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Ders kayitlari klasorundeki altyazi_ozetleri/*.md dosyalarini "
            "ayni klasorun kokune PDF olarak donusturur."
        )
    )
    parser.add_argument(
        "target_dir",
        type=Path,
        help=(
            "Ders kayitlari kok klasoru. Ornek: "
            "'3-2/Yapay Zeka/ders_kayitlari/2022-2023'"
        ),
    )
    parser.add_argument(
        "--summary-dir",
        type=Path,
        default=None,
        help=(
            "Markdown ozetlerinin bulundugu klasor. Verilmezse "
            "hedef_dizin/altyazi_ozetleri kullanilir."
        ),
    )
    parser.add_argument(
        "--force",
        action="store_true",
        help="PDF guncel olsa bile yeniden uret.",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    target_dir = args.target_dir.resolve()
    source_dir = (
        args.summary_dir.resolve()
        if args.summary_dir
        else target_dir / DEFAULT_SUMMARY_DIR_NAME
    )

    if not target_dir.is_dir():
        print(f"Hedef dizin bulunamadi: {target_dir}", file=sys.stderr)
        return 1

    if not source_dir.is_dir():
        print(f"Ozet klasoru bulunamadi: {source_dir}", file=sys.stderr)
        return 1

    markdown_files = sorted(source_dir.glob("*.md"), key=natural_key)
    if not markdown_files:
        print(f"Donusturulecek ozet Markdown dosyasi bulunamadi: {source_dir}", file=sys.stderr)
        return 1

    failures: list[tuple[Path, str]] = []
    for markdown_path in markdown_files:
        try:
            print(convert(markdown_path, target_dir, args.force))
        except (RuntimeError, subprocess.CalledProcessError) as exc:
            failures.append((markdown_path, str(exc)))

    if failures:
        for markdown_path, error in failures:
            print(f"hata: {markdown_path.name}: {error}", file=sys.stderr)
        return 1

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
