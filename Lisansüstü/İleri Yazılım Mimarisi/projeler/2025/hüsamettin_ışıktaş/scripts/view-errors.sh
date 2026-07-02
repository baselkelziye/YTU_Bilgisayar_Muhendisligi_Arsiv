#!/bin/bash

# Hata loglarını görüntüleme scripti

echo "=== Hata Logları ==="
echo ""
echo "Son 200 satır içinde hata mesajları aranıyor..."
echo ""

docker-compose logs --tail=200 | grep -i -E "(error|fail|exception|warn)" --color=always

