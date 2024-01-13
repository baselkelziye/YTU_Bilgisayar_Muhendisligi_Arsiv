#!/bin/bash
remote_name="origin"
branch_name="main"

git fetch $remote_name
if [ $? -ne 0 ]; then
    echo "Hata: Remote repository fetch işlemi başarısız."
    read -p "Devam etmek için enter'a basın..."
    exit 1
fi

git reset --hard $remote_name/$branch_name
if [ $? -ne 0 ]; then
    echo "Hata: Hard reset işlemi başarısız."
    read -p "Devam etmek için enter'a basın..."
    exit 1
fi

git config --global i18n.commitEncoding utf-8
if [ $? -ne 0 ]; then
    echo "Hata: Commit encoding ayarı başarısız oldu."
    read -p "Devam etmek için enter'a basın..."
    exit 1
fi

git config --global i18n.logOutputEncoding utf-8
if [ $? -ne 0 ]; then
    echo "Hata: Log output encoding ayarı başarısız oldu."
    read -p "Devam etmek için enter'a basın..."
    exit 1
fi

export LANG=en_US.UTF-8
echo "Repo güncellendi."
read -p "Devam etmek için enter'a basın..."
exit 0
