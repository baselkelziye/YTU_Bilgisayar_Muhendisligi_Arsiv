#!/bin/bash

# Docker container durumlarını kontrol et

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo "========================================="
echo "Docker Container Durumları"
echo "========================================="
echo ""

# Docker Compose ps çıktısını al
docker-compose ps

echo ""
echo "========================================="
echo "Container Log Örnekleri (Son 5 satır)"
echo "========================================="
echo ""

SERVICES=("user-service" "chat-service" "message-service" "notification-service" "file-service" "api-gateway" "websocket-gateway")

for service in "${SERVICES[@]}"; do
    echo -e "${YELLOW}=== $service ===${NC}"
    docker-compose logs --tail=5 $service 2>/dev/null | tail -5
    echo ""
done

