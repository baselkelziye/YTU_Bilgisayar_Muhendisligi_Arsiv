@echo off
:: Mevcut konumu kaydet
set "original_dir=%cd%"
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8
CHCP 65001 >nul

:: Headless mod kontrolü
set "HEADLESS="
if "%~1"=="--headless" set "HEADLESS=1"
if "%~1"=="-q" set "HEADLESS=1"

if not defined HEADLESS (
    cls
    echo README Duzenleyici Arayuzu
    echo ========================================
)

:: Proje dizinini belirleyin
set "PROJECT_DIR=%~dp0"
set "EXECUTABLE=%PROJECT_DIR%dist\main.exe"

:: Executable var mı kontrol et, yoksa build al
if not exist "%EXECUTABLE%" (
    if not defined HEADLESS echo Executable bulunamadi, build aliniyor...
    
    if defined HEADLESS (
        call "%PROJECT_DIR%build.bat" >nul 2>&1
    ) else (
        call "%PROJECT_DIR%build.bat"
    )
    
    if %errorlevel% neq 0 (
        if not defined HEADLESS (
            echo Build basarisiz!
            pause
        )
        exit /b 1
    )
    
    if not exist "%EXECUTABLE%" (
        if not defined HEADLESS (
            echo Build sonrasi executable bulunamadi!
            pause
        )
        exit /b 1
    )
)

:: Arayüzü çalıştır
if not defined HEADLESS echo Arayuz baslatiliyor...

if defined HEADLESS (
    :: Headless mod: pencere olmadan arka planda çalıştır
    start "" "%EXECUTABLE%"
) else (
    :: Normal mod
    start "" "%EXECUTABLE%"
)

:: Orijinal konuma geri dön
cd /d %original_dir%
if not defined HEADLESS (
    echo Islem tamamlandi.
    pause
)
exit /b 0
