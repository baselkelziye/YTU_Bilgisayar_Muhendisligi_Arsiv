from src.data.clean_text import clean_text, reject_reason_for_text, strip_gutenberg_boilerplate
from src.data.split_books import assert_no_leakage, split_book_ids


def test_strip_gutenberg_boilerplate_removes_markers():
    text = (
        "*** START OF THE PROJECT GUTENBERG EBOOK SAMPLE ***\n"
        "Actual body text.\n"
        "*** END OF THE PROJECT GUTENBERG EBOOK SAMPLE ***"
    )
    cleaned = strip_gutenberg_boilerplate(text)
    assert "START OF THE PROJECT GUTENBERG" not in cleaned
    assert "END OF THE PROJECT GUTENBERG" not in cleaned
    assert "Actual body text." in cleaned


def test_clean_text_normalizes_line_endings():
    raw = "line1\r\nline2\rline3"
    cleaned = clean_text(raw)
    assert "\r" not in cleaned
    assert cleaned.endswith("\n")


def test_reject_reason_for_short_text():
    assert reject_reason_for_text("abc", min_chars=10) == "too_short"
    assert reject_reason_for_text("hello world" * 10, min_chars=10) is None


def test_split_book_ids_is_deterministic_and_non_overlapping():
    book_ids = [str(i) for i in range(100)]
    split_a = split_book_ids(book_ids, seed=123)
    split_b = split_book_ids(book_ids, seed=123)
    assert split_a == split_b
    assert_no_leakage(split_a)
