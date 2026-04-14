@echo off
:: Build Script for Windows
:: Script'in bulunduğu dizine geç
cd /d "%~dp0"

CHCP 65001 >nul
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8

echo PyInstaller Build Script
echo ========================================

:: Proje dizinini ve sanal ortam dizinini belirleyin
set "PROJECT_DIR=%~dp0"
set "VENV_DIR=%PROJECT_DIR%venv"

:: Python kontrolü
python --version >nul 2>&1
if %errorlevel% neq 0 (
    echo Python bulunamadi!
    if "%CI%"=="" pause
    exit /b 1
)

:: Sanal ortam oluştur
if not exist "%VENV_DIR%" (
    echo venv bulunamiyor, olusturuluyor...
    python -m venv "%VENV_DIR%"
    if %errorlevel% neq 0 (
        echo venv olusturulamadi!
        if "%CI%"=="" pause
        exit /b 1
    )
    echo venv olusturuldu.
)

:: Sanal ortamı aktifle
call "%VENV_DIR%\Scripts\activate"

:: pip güncelle
pip install --upgrade pip

:: Projeyi pyproject.toml ile kur (dev bağımlılıklarıyla)
echo pyproject.toml ile kurulum yapiliyor...
pip install -e ".[dev]"

if %errorlevel% neq 0 (
    echo Kurulum basarisiz!
    if "%CI%"=="" pause
    exit /b 1
)
echo Kurulum tamamlandi.

echo Build basliyor...

:: PyInstaller ile build al (pyproject.toml'daki konfigurasyona gore)
pyinstaller ^
    --name main ^
    --onefile ^
    --console ^
    --distpath "%PROJECT_DIR%dist" ^
    --workpath "%PROJECT_DIR%build" ^
    --noconfirm ^
    --add-data "readme_guncelleme_arayuzu_python;." ^
    --add-data "google_forum_islemleri;google_forum_islemleri" ^
    --add-data "writers;writers" ^
    --add-data "readme_olustur.py;." ^
    --add-data "buffered_writer.py;." ^
    --add-data "folder_cache.py;." ^
    --hidden-import pandas ^
    --hidden-import numpy ^
    --hidden-import requests ^
    --hidden-import google_forum_islemleri.ders_icerikleri_guncelle ^
    --hidden-import google_forum_islemleri.hoca_icerikleri_guncelle ^
    --hidden-import google_forum_islemleri.google_form_rutin_kontrol ^
    --hidden-import readme_olustur ^
    --hidden-import buffered_writer ^
    --hidden-import folder_cache ^
    readme_guncelleme_arayuzu_python/main.py

if %errorlevel% equ 0 (
    move /Y "%PROJECT_DIR%dist\main.exe" "%PROJECT_DIR%main.exe"
    echo ========================================
    echo Build basariyla tamamlandi!
    echo Executable: %PROJECT_DIR%main.exe
    echo ========================================
) else (
    echo Build basarisiz oldu!
    if "%CI%"=="" pause
    exit /b 1
)

call deactivate
if "%CI%"=="" pause
exit /b 0
