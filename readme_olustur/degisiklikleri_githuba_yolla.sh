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
cd "$(dirname "$0")/$REPO_PATH" || { echo "Hata: Belirtilen yola gidilemedi."; read -p "Devam etmek için enter'a basın..."; exit 1; }
git rev-parse --is-inside-work-tree > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Bu dizin bir Git reposu değil."
if [ -z "$3" ]; then
    read -p "Devam etmek için enter'a basın..."
fi
    exit 1
fi

# Değişiklikleri ekler, commit yapar ve push yapar.
git add --all
if [ $? -ne 0 ]; then
    echo "Hata: Dosyalar eklenemedi."
if [ -z "$3" ]; then
    read -p "Devam etmek için enter'a basın..."
fi
    exit 1
fi

git commit -m "$COMMIT_MESSAGE"
if [ $? -ne 0 ]; then
    echo "Hata: Commit yapılamadı."
if [ -z "$3" ]; then
    read -p "Devam etmek için enter'a basın..."
fi
    exit 1
fi

git push
if [ $? -ne 0 ]; then
    echo "Hata: Değişiklikler push edilemedi."
if [ -z "$3" ]; then
    read -p "Devam etmek için enter'a basın..."
fi
    exit 1
fi

echo "Değişiklikler başarıyla senkronize edildi."
if [ -z "$3" ]; then
    read -p "Devam etmek için enter'a basın..."
fi
exit 0
