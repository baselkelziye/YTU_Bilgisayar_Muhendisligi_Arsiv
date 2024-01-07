@echo off
cls
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8
CHCP 65001
echo Readme icerikleri guncelleniyor...
python3 readme_olustur.py

echo Islem tamamlandi.
exit /b 0
