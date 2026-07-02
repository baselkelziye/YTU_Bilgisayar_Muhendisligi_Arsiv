#!/bin/bash

# Servis loglarını filtreli görüntüleme scripti

SERVICE_NAME=${1:-""}

if [ -z "$SERVICE_NAME" ]; then
    echo "=== Tüm Servislerin Logları ==="
    echo "Belirli bir servisin loglarını görmek için: ./scripts/view-logs-filtered.sh <servis-adı>"
    echo "Örnek: ./scripts/view-logs-filtered.sh user-service"
    echo ""
    docker-compose logs -f -t
else
    echo "=== $SERVICE_NAME Logları ==="
    echo ""
    docker-compose logs -f -t $SERVICE_NAME
fi

