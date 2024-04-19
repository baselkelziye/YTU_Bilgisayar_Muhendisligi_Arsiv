import re
import hashlib


def github_kullanici_adi_getir(url):
    # Regex pattern to extract the GitHub username from a URL
    pattern = r"https?://github\.com/([^/]+)/?.*"
    match = re.search(pattern, url)
    if match:
        return match.group(1)
    else:
        return "Invalid GitHub URL"


def hash_url_39(url):
    # URL'nin hash değerini SHA-256 kullanarak hesaplayın ve 39 karakter alın.
    sha_signature = hashlib.sha256(url.encode()).hexdigest()
    return sha_signature[:39]  # İlk 39 karakteri al
