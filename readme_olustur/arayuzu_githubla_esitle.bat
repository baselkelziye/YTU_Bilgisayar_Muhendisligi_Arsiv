@echo off
SET remote_name=origin
SET branch_name=main

git config --global i18n.commitEncoding utf-8
IF %ERRORLEVEL% NEQ 0 (
    echo Hata: Commit encoding ayarı başarısız oldu.
    pause
    exit /b 1
)

git config --global i18n.logOutputEncoding utf-8
IF %ERRORLEVEL% NEQ 0 (
    echo Hata: Log output encoding ayarı başarısız oldu.
    pause
    exit /b 1
)

CHCP 65001
IF %ERRORLEVEL% NEQ 0 (
    echo Hata: Karakter kodlaması değiştirilemedi.
    pause
    exit /b 1
)

git fetch %remote_name%
IF %ERRORLEVEL% NEQ 0 (
    echo Hata: Remote repository fetch işlemi başarısız.
    pause
    exit /b 1
)

git reset --hard %remote_name%/%branch_name%
IF %ERRORLEVEL% NEQ 0 (
    echo Hata: Hard reset işlemi başarısız.
    pause
    exit /b 1
)

echo Arayüz güncellendi.
pause
exit /b 0
