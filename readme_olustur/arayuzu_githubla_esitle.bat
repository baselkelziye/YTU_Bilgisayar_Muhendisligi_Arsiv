@echo off
SET remote_name=origin
SET branch_name=main
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8
CHCP 65001
git fetch %remote_name%
git reset --hard %remote_name%/%branch_name%
echo Arayüz güncellendi.
exit /b 0
