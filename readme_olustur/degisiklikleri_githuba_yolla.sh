#!/bin/bash
# Bu script, bir Git reposunda çalıştırıldığında değişiklikleri senkronize eder.

# Mevcut dizinin bir Git reposu olup olmadığını kontrol eder.
git rev-parse --is-inside-work-tree > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Bu dizin bir Git reposu değil."
    exit 1
fi

# Değişiklikleri ekler, commit yapar ve push yapar.
git add --all
git commit -m "değişiklikler senkronize edildi"
git push
