#!/bin/bash

# Script'in bulunduğu dizini belirle
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Headless mod kontrolü
HEADLESS=false
if [[ "$1" == "--headless" ]] || [[ "$1" == "-q" ]]; then
    HEADLESS=true
fi

# Renk tanımları (headless modda devre dışı)
if [ "$HEADLESS" = true ]; then
    RED=''
    GREEN=''
    YELLOW=''
    NC=''
else
    RED='\033[0;31m'
    GREEN='\033[0;32m'
    YELLOW='\033[1;33m'
    NC='\033[0m'
    clear
    echo -e "${YELLOW}README Düzenleyici Arayüzü${NC}"
    echo "========================================"
fi

log() {
    if [ "$HEADLESS" = false ]; then
        echo -e "$1"
    fi
}

log_error() {
    if [ "$HEADLESS" = false ]; then
        echo -e "${RED}$1${NC}"
    fi
}

EXECUTABLE="$SCRIPT_DIR/dist/main"

# Executable var mı kontrol et, yoksa build al
if [ ! -f "$EXECUTABLE" ]; then
    log "${YELLOW}Executable bulunamadı, build alınıyor...${NC}"
    
    if [ "$HEADLESS" = true ]; then
        bash "$SCRIPT_DIR/build.sh" > /dev/null 2>&1
    else
        bash "$SCRIPT_DIR/build.sh"
    fi
    
    if [ $? -ne 0 ]; then
        log_error "Build başarısız!"
        exit 1
    fi
    
    if [ ! -f "$EXECUTABLE" ]; then
        log_error "Build sonrası executable bulunamadı!"
        exit 1
    fi
fi

# Arayüzü çalıştır
log "${YELLOW}Arayüz başlatılıyor...${NC}"

if [ "$HEADLESS" = true ]; then
    # Headless mod: arka planda çalıştır ve hemen çık
    nohup "$EXECUTABLE" > /dev/null 2>&1 &
else
    # Normal mod: uygulama kapanana kadar bekle
    "$EXECUTABLE"
fi

log "${GREEN}İşlem tamamlandı.${NC}"
exit 0
