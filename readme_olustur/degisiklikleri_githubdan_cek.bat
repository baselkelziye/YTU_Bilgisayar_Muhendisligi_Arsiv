@echo off
REM Bu script, uzak Git deposundaki değişiklikleri yerel depoya çeker ve birleştirir.

REM Mevcut dizinin bir Git reposu olup olmadığını kontrol eder.
IF "%~1"=="" (SET REPO_PATH=..) ELSE (SET REPO_PATH=%~1)
cd %~dp0\%REPO_PATH%
git rev-parse --is-inside-work-tree >nul 2>&1
IF NOT %ERRORLEVEL% == 0 (
    echo Bu dizin bir Git reposu değil.
    exit /b 1
)

REM Uzak depodaki değişiklikleri çeker ve yerel depoya birleştirir.
git fetch --all
git reset --hard origin/master
exit /b 0