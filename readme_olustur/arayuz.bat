@echo off
:: Mevcut konumu kaydet
set "original_dir=%cd%"
cls
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8
CHCP 65001

:: Python'un yüklü olup olmadığını kontrol edin
python --version >nul 2>&1
if %errorlevel% neq 0 (
    echo Python bulunamadi. Lutfen https://www.python.org/downloads/ adresinden yukleyin. [[1]]
    echo Yukleme sirasinda "Add Python to PATH" secenegini isaretlediginizden emin olun.
    pause
    exit /b
)

:: venv modülünün yüklü olup olmadığını kontrol edin
python -c "import venv" >nul 2>&1
if %errorlevel% neq 0 (
    echo venv modulu bulunamadi. Python'unuz ile birlikte otomatik olarak yuklenmesi gerekirdi.
    echo Yukleme sirasinda bir sorun olmus olabilir. Python'u tekrar yuklemeyi deneyin.
    pause
    exit /b
)

:: Proje dizinini ve sanal ortam dizinini belirleyin
set "PROJECT_DIR=%~dp0"
set "VENV_DIR=%PROJECT_DIR%venv"

:: Sanal ortam oluşturun
if not exist "%VENV_DIR%" (
    echo Sanal ortam olusturuluyor...
    python -m venv "%VENV_DIR%"
)

:: Sanal ortamı etkinleştirin
call "%VENV_DIR%\Scripts\activate"

:: Gerekli kütüphaneleri yükleyin
echo Gerekli kutuphaneler kontrol ediliyor ve yukleniyor...

:: gereksinimler.txt dosyasındaki her paketi kontrol et ve yükle
for /F "tokens=*" %%i in (%PROJECT_DIR%gereksinimler.txt) do (
    pip show %%i >nul 2>&1
    if %errorlevel% neq 0 (
        echo %%i yukleniyor...
        pip install %%i
    )
)

:: readme_olusturma_arayuzu klasörüne çıkın ve main.py'yi çalıştırın
cd "%PROJECT_DIR%readme_guncelleme_arayuzu_python"
start python main.py

:: Sanal ortamı deaktive edin
call deactivate

:: Orijinal konuma geri dön
cd %original_dir%
echo İşlem tamamlandı.
pause
exit /b 0
