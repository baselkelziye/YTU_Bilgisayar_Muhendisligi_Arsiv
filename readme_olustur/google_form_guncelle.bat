@echo off
cls

:: Mevcut dizini kaydet
SET "ORIGINAL_DIR=%CD%"

:: Klasöre git
cd %~dp0\google_forum_islemleri
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8
CHCP 65001

:: Python script'lerini çalıştır
echo Hoca icerikleri guncelleniyor...
python3 hoca_icerikleri_guncelle.py
IF %ERRORLEVEL% NEQ 0 (
    echo Hata: Hoca icerikleri guncelleme script'i basarisiz oldu.
    pause
    cd "%ORIGINAL_DIR%"
    exit /b 1
)

echo Ders icerikleri guncelleniyor...
python3 ders_icerikleri_guncelle.py
IF %ERRORLEVEL% NEQ 0 (
    echo Hata: Ders icerikleri guncelleme script'i basarisiz oldu.
    pause
    cd "%ORIGINAL_DIR%"
    exit /b 1
)

:: İlk dizine geri dön
cd "%ORIGINAL_DIR%"

echo Islem tamamlandi.
pause
exit /b 0
