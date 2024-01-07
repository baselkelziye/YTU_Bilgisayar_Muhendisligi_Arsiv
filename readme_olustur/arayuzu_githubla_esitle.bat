@echo off
SET repo_path=C:\path\to\your\repo
SET remote_name=origin
SET branch_name=master
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8
CHCP 65001
cd %repo_path%
git fetch %remote_name%
git reset --hard %remote_name%/%branch_name%
git clean -f -d
echo Arayüz güncellendi.
