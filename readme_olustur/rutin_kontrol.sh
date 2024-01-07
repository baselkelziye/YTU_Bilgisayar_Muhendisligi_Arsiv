#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$DIR/google_forum_islemleri"
python3 google_form_rutin_kontrol.py
