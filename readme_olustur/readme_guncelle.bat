@echo off
cls
cd %~dp0
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8
CHCP 65001

echo Readme icerikleri guncelleniyor...
python3 readme_olustur.py
IF %ERRORLEVEL% NEQ 0 (
    echo Hata: Readme icerikleri guncelleme script'i basarisiz oldu.
    pause
    exit /b 1
)

echo Islem tamamlandi.
pause
exit /b 0
