#!/bin/bash
# Bu script, bir Git reposunda çalıştırıldığında değişiklikleri senkronize eder.

# Mevcut dizinin bir Git reposu olup olmadığını kontrol eder.
cd ..
git rev-parse --is-inside-work-tree > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Bu dizin bir Git reposu değil."
    exit 1
fi
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8

export LANG=en_US.UTF-8
# Değişiklikleri ekler, commit yapar ve push yapar.
git add --all
git commit -m "değişiklikler senkronize edildi"
git push
