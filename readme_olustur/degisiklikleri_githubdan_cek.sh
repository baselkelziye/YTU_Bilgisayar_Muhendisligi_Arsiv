#!/bin/bash
# Bu script, uzak Git deposundaki değişiklikleri yerel depoya çeker ve birleştirir.
if [ -z "$1" ]; then
    REPO_PATH=".."
else
    REPO_PATH="$1"
fi

# Mevcut dizinin bir Git reposu olup olmadığını kontrol eder.
cd "$(dirname "$0")/$REPO_PATH"
# Mevcut dizinin bir Git reposu olup olmadığını kontrol eder.
git rev-parse --is-inside-work-tree > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Bu dizin bir Git reposu değil."
    exit 1
fi

# Uzak depodaki değişiklikleri çeker ve yerel depoya birleştirir.
git fetch --all
git reset --hard origin/master
exit 0