"""Build a diverse text corpus for profile-based compression experiments.

Creates a multi-domain dataset mixing:
  - English prose (Gutenberg, sampled)
  - Source code (Python from system + project)
  - HTML (scraped pages)
  - JSON (structured data)
  - Markdown (documentation)
  - Turkish text (Wikipedia)
  - Chinese text (Wikipedia)

Output: data/diverse/manifest.csv + data/diverse/books/*.txt
"""

from __future__ import annotations

import csv
import hashlib
import json
import os
import random
import sys
import urllib.request
from pathlib import Path

try:
    import markdownify  # type: ignore
except ImportError:
    markdownify = None

PROJECT_ROOT = Path(__file__).resolve().parent.parent
DATA_DIR = PROJECT_ROOT / "data"
DIVERSE_DIR = DATA_DIR / "diverse"
BOOKS_DIR = DIVERSE_DIR / "books"

# --- Source definitions ---
# Each source is (domain, generator_fn, target_count)
SOURCES: list[tuple[str, callable, int]] = []


def _short_hash(text: str) -> str:
    return hashlib.md5(text.encode("utf-8")).hexdigest()[:8]


# ---------------------------------------------------------------------------
# 1. Gutenberg prose (English) — sample from existing processed books
# ---------------------------------------------------------------------------

def _gutenberg_books() -> list[tuple[str, str]]:
    processed = DATA_DIR / "processed" / "books"
    if not processed.exists():
        print("  ⚠ No processed Gutenberg books found, skipping")
        return []
    files = sorted(processed.glob("*.txt"))
    sample = random.sample(files, min(60, len(files)))
    results = []
    for f in sample:
        text = f.read_text(encoding="utf-8", errors="replace")[:50000]
        results.append((f"gutenberg_{f.stem}", text))
    return results


# ---------------------------------------------------------------------------
# 2. Python code — from system + local project
# ---------------------------------------------------------------------------

def _python_code() -> list[tuple[str, str]]:
    sources = [
        Path("/usr/lib/python3"),
        PROJECT_ROOT / "src",
        PROJECT_ROOT / "scripts",
        Path.home() / ".hermes",
    ]
    results = []
    for src_dir in sources:
        if not src_dir.exists():
            continue
        py_files = list(src_dir.rglob("*.py"))
        sample = random.sample(py_files, min(20, len(py_files)))
        for f in sample:
            try:
                text = f.read_text(encoding="utf-8", errors="replace")[:30000]
                if len(text.strip()) > 200:
                    results.append((f"code_{f.name}_{_short_hash(text)}", text))
            except Exception:
                continue
        if len(results) >= 40:
            break
    return results[:40]


# ---------------------------------------------------------------------------
# 3. HTML — scrape a few real pages
# ---------------------------------------------------------------------------

_HTML_URLS = [
    "https://en.wikipedia.org/wiki/Data_compression",
    "https://en.wikipedia.org/wiki/Huffman_coding",
    "https://en.wikipedia.org/wiki/Lempel-Ziv-Welch",
    "https://en.wikipedia.org/wiki/Machine_learning",
    "https://en.wikipedia.org/wiki/Information_theory",
    "https://en.wikipedia.org/wiki/Kolmogorov_complexity",
    "https://www.python.org/",
    "https://docs.python.org/3/library/zlib.html",
    "https://tr.wikipedia.org/wiki/Veri_s%C4%B1k%C4%B1%C5%9Ft%C4%B1rma",
    "https://tr.wikipedia.org/wiki/Bilgi_teorisi",
    "https://zh.wikipedia.org/wiki/%E6%95%B0%E6%8D%AE%E5%8E%8B%E7%BC%A9",
]


def _scrape_html() -> list[tuple[str, str]]:
    results = []
    for url in _HTML_URLS:
        try:
            req = urllib.request.Request(url, headers={"User-Agent": "Hermes-Research/1.0"})
            with urllib.request.urlopen(req, timeout=15) as resp:
                html = resp.read().decode("utf-8", errors="replace")
            # Convert to markdown-like text (strips tags, keeps text)
            text = markdownify.markdownify(html, heading_style="ATX")[:20000]
            if len(text.strip()) > 500:
                domain = url.split("//")[1].split("/")[0].replace(".", "_")
                results.append((f"html_{domain}_{_short_hash(url)}", text))
        except Exception as e:
            print(f"  ⚠ Failed to scrape {url}: {e}")
            continue
    return results


# ---------------------------------------------------------------------------
# 4. JSON — structured data
# ---------------------------------------------------------------------------

def _json_data() -> list[tuple[str, str]]:
    results = []
    # Sample JSON from project artifacts
    artifact_dir = PROJECT_ROOT / "artifacts"
    if artifact_dir.exists():
        json_files = list(artifact_dir.rglob("*.json"))
        sample = random.sample(json_files, min(15, len(json_files)))
        for f in sample:
            try:
                text = f.read_text(encoding="utf-8")[:15000]
                results.append((f"json_{f.parent.name}_{f.name}", text))
            except Exception:
                continue

    # Generate synthetic JSON
    for i in range(5):
        data = {
            "records": [
                {
                    "id": j,
                    "name": f"item_{j}",
                    "values": [random.random() for _ in range(50)],
                    "metadata": {
                        "tags": random.sample(["alpha", "beta", "gamma", "delta", "epsilon"], 3),
                        "score": round(random.uniform(0, 100), 2),
                    },
                }
                for j in range(random.randint(50, 200))
            ]
        }
        text = json.dumps(data, indent=2)
        results.append((f"json_synthetic_{i}", text))
    return results


# ---------------------------------------------------------------------------
# 5. Markdown documentation
# ---------------------------------------------------------------------------

def _markdown_docs() -> list[tuple[str, str]]:
    results = []
    # From hermes skills
    skills_dir = Path.home() / ".hermes" / "skills"
    if skills_dir.exists():
        md_files = list(skills_dir.rglob("*.md"))
        sample = random.sample(md_files, min(10, len(md_files)))
        for f in sample:
            try:
                text = f.read_text(encoding="utf-8")[:10000]
                if len(text.strip()) > 200:
                    results.append((f"md_skill_{f.parent.name}", text))
            except Exception:
                continue

    # From project README/docs
    project_md = list(PROJECT_ROOT.rglob("*.md"))
    for f in project_md[:5]:
        try:
            text = f.read_text(encoding="utf-8")[:10000]
            if len(text.strip()) > 200:
                results.append((f"md_project_{f.name}", text))
        except Exception:
            continue
    return results


# ---------------------------------------------------------------------------
# 6. Turkish text (from Wikipedia scraping)
# ---------------------------------------------------------------------------

def _turkish_text() -> list[tuple[str, str]]:
    """Try to scrape Turkish Wikipedia articles for diverse Turkish text."""
    results = []
    urls = [
        "https://tr.wikipedia.org/wiki/T%C3%BCrkiye",
        "https://tr.wikipedia.org/wiki/%C4%B0stanbul",
        "https://tr.wikipedia.org/wiki/Yapay_zek%C3%A2",
        "https://tr.wikipedia.org/wiki/Alan_Turing",
        "https://tr.wikipedia.org/wiki/Python_(programlama_dili)",
    ]
    for url in urls:
        try:
            req = urllib.request.Request(url, headers={"User-Agent": "Hermes-Research/1.0"})
            with urllib.request.urlopen(req, timeout=15) as resp:
                html = resp.read().decode("utf-8", errors="replace")
            text = markdownify.markdownify(html, heading_style="ATX")[:15000]
            if len(text.strip()) > 500:
                results.append((f"tr_wiki_{_short_hash(url)}", text))
        except Exception as e:
            print(f"  ⚠ Failed to scrape {url}: {e}")
            continue
    return results


# ---------------------------------------------------------------------------
# 7. Chinese text (from Wikipedia scraping)
# ---------------------------------------------------------------------------

def _chinese_text() -> list[tuple[str, str]]:
    """Scrape Chinese Wikipedia for CJK text."""
    results = []
    urls = [
        "https://zh.wikipedia.org/wiki/%E4%B8%AD%E5%9B%BD",
        "https://zh.wikipedia.org/wiki/%E4%BA%BA%E5%B7%A5%E6%99%BA%E8%83%BD",
        "https://zh.wikipedia.org/wiki/%E5%8C%97%E4%BA%AC",
    ]
    for url in urls:
        try:
            req = urllib.request.Request(url, headers={"User-Agent": "Hermes-Research/1.0"})
            with urllib.request.urlopen(req, timeout=15) as resp:
                html = resp.read().decode("utf-8", errors="replace")
            text = markdownify.markdownify(html, heading_style="ATX")[:15000]
            if len(text.strip()) > 500:
                results.append((f"zh_wiki_{_short_hash(url)}", text))
        except Exception as e:
            print(f"  ⚠ Failed to scrape {url}: {e}")
            continue
    return results


# ---------------------------------------------------------------------------
# Main build
# ---------------------------------------------------------------------------

def build_corpus():
    random.seed(42)

    print("=" * 60)
    print("Building diverse text corpus")
    print("=" * 60)

    BOOKS_DIR.mkdir(parents=True, exist_ok=True)

    manifest_rows: list[dict] = []
    book_id = 0

    sources = [
        ("Gutenberg English prose", _gutenberg_books, 60),
        ("Python source code", _python_code, 40),
        ("HTML pages", _scrape_html, 10),
        ("JSON structured data", _json_data, 20),
        ("Markdown docs", _markdown_docs, 15),
        ("Turkish Wikipedia", _turkish_text, 5),
        ("Chinese Wikipedia", _chinese_text, 3),
    ]

    for domain, gen_fn, target in sources:
        print(f"\n📁 {domain} (target: ~{target})...")
        try:
            items = gen_fn()
        except Exception as e:
            print(f"  ❌ Failed: {e}")
            continue

        for name, text in items:
            book_id += 1
            book_dir = BOOKS_DIR / f"book_{book_id:04d}"
            book_dir.mkdir(exist_ok=True)
            txt_path = book_dir / "full.txt"
            txt_path.write_text(text, encoding="utf-8")

            manifest_rows.append({
                "book_id": f"diverse_{book_id:04d}",
                "source": name,
                "domain": domain,
                "path": str(txt_path.relative_to(PROJECT_ROOT)),
                "n_chars": len(text),
                "n_lines": text.count("\n") + 1,
            })

        print(f"  ✓ {len(items)} items collected")

    # Save manifest
    manifest_path = DIVERSE_DIR / "manifest.csv"
    with open(manifest_path, "w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=manifest_rows[0].keys())
        writer.writeheader()
        writer.writerows(manifest_rows)

    print(f"\n{'=' * 60}")
    print(f"✅ Corpus built: {book_id} documents → {manifest_path}")
    print(f"   Books dir: {BOOKS_DIR}")
    total_chars = sum(r["n_chars"] for r in manifest_rows)
    print(f"   Total chars: {total_chars:,}")
    print(f"{'=' * 60}")

    # Domain breakdown
    from collections import Counter
    domain_counts = Counter(r["domain"] for r in manifest_rows)
    for domain, count in domain_counts.most_common():
        print(f"   {domain}: {count} docs")


if __name__ == "__main__":
    # Install markdownify if needed
    try:
        import markdownify  # noqa: F811
    except ImportError:
        print("Installing markdownify...")
        os.system(f"{sys.executable} -m pip install markdownify -q")

    build_corpus()
