#!/bin/bash

# Servis loglarını görüntüleme scripti

echo "=== Mikroservis Logları ==="
echo ""
echo "Tüm servislerin loglarını görüntülemek için Ctrl+C ile çıkış yapın"
echo ""

# Docker Compose ile tüm logları görüntüle
docker-compose logs -f -t

