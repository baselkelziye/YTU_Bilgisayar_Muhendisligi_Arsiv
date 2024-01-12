#!/bin/bash
# Bu script, bir Git reposunda çalıştırıldığında değişiklikleri senkronize eder.
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8

export LANG=en_US.UTF-8

if [ -z "$1" ]; then
    REPO_PATH=".."
else
    REPO_PATH="$1"
fi

if [ -z "$2" ]; then
    COMMIT_MESSAGE="değişiklikler senkronize edildi (bat dosyasıyla)"
else
    COMMIT_MESSAGE="$2"
fi

# Mevcut dizinin bir Git reposu olup olmadığını kontrol eder.
cd "$(dirname "$0")/$REPO_PATH"
git rev-parse --is-inside-work-tree > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Bu dizin bir Git reposu değil."
    exit 1
fi
# Değişiklikleri ekler, commit yapar ve push yapar.
git add --all
git commit -m "$COMMIT_MESSAGE"
git push
exit 0