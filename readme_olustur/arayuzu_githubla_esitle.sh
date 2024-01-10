#!/bin/bash
remote_name="origin"
branch_name="main"

git fetch $remote_name
git reset --hard $remote_name/$branch_name
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8

export LANG=en_US.UTF-8
echo "Repo güncellendi."
exit 0
