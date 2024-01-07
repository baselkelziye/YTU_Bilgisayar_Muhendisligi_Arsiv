@echo off
SET repo_path=C:\path\to\your\repo
SET remote_name=origin
SET branch_name=master

cd %repo_path%
git fetch %remote_name%
git reset --hard %remote_name%/%branch_name%
git clean -f -d
echo Arayüz güncellendi.
