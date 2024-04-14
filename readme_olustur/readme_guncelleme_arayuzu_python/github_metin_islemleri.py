import re


def github_kullanici_adi_getir(url):
    # Regex pattern to extract the GitHub username from a URL
    pattern = r"https?://github\.com/([^/]+)/?.*"
    match = re.search(pattern, url)
    if match:
        return match.group(1)
    else:
        return "Invalid GitHub URL"
