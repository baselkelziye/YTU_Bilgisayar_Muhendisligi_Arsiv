@echo off
REM Bu script, bir Git reposunda çalıştırıldığında değişiklikleri senkronize eder.

REM Mevcut dizinin bir Git reposu olup olmadığını kontrol eder.
IF "%~1"=="" (SET REPO_PATH=..) ELSE (SET REPO_PATH=%~1)
cd %~dp0\%REPO_PATH%
git rev-parse --is-inside-work-tree >nul 2>&1
IF NOT %ERRORLEVEL% == 0 (
    echo Bu dizin bir Git reposu değil.
    exit /b 1
)
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8
CHCP 65001
REM Değişiklikleri ekler, commit yapar ve push yapar.
git add --all
git commit -m "değişiklikler senkronize edildi (bat dosyasıyla)"
git push
exit /b 0
