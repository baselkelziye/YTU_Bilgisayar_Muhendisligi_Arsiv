#!/bin/bash
repo_path="/path/to/your/repo"
remote_name="origin"
branch_name="master"

cd $repo_path
git fetch $remote_name
git reset --hard $remote_name/$branch_name
git clean -f -d
echo "Repo güncellendi."