@echo off
cls

:: Klasöre git
cd google_forum_islemleri

:: Python script'lerini çalıştır
echo Hoca icerikleri guncelleniyor...
python3 hoca_icerikleri_guncelle.py

echo Ders icerikleri guncelleniyor...
python3 ders_icerikleri_guncelle.py

echo Islem tamamlandi.
pause
