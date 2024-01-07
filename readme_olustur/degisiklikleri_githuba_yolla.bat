@echo off
REM Bu script, bir Git reposunda çalıştırıldığında değişiklikleri senkronize eder.

REM Mevcut dizinin bir Git reposu olup olmadığını kontrol eder.
git rev-parse --is-inside-work-tree >nul 2>&1
IF NOT %ERRORLEVEL% == 0 (
    echo Bu dizin bir Git reposu değil.
    exit /b 1
)

REM Değişiklikleri ekler, commit yapar ve push yapar.
git add --all
git commit -m "değişiklikler senkronize edildi"
git push
