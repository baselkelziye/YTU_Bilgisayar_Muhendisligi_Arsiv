@echo off
cls

:: Klasöre git
cd %~dp0\google_forum_islemleri
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8
CHCP 65001
:: Python script'lerini çalıştır
echo Hoca icerikleri guncelleniyor...
python3 hoca_icerikleri_guncelle.py

echo Ders icerikleri guncelleniyor...
python3 ders_icerikleri_guncelle.py

echo Islem tamamlandi.
exit /b 0
