#!/bin/bash
repo_path="/path/to/your/repo"
remote_name="origin"
branch_name="master"

cd $repo_path
git fetch $remote_name
git reset --hard $remote_name/$branch_name
git clean -f -d
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8

export LANG=en_US.UTF-8
echo "Repo güncellendi."