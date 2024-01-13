#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$DIR/google_forum_islemleri"
git config --global i18n.commitEncoding utf-8
git config --global i18n.logOutputEncoding utf-8

export LANG=en_US.UTF-8
python3 google_form_rutin_kontrol.py
read -p "Devam etmek için enter'a basın..."
exit 0