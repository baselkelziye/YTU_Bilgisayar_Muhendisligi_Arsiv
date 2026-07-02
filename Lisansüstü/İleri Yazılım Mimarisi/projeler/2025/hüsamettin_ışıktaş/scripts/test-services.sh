#!/bin/bash

# Mikroservis sağlık kontrolü ve test scripti

API_URL="http://localhost:3000"
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo "========================================="
echo "Mikroservis Sağlık Kontrolü ve Test"
echo "========================================="
echo ""

# Health Check Functions
check_health() {
    local service_name=$1
    local url=$2
    
    echo -n "Testing $service_name... "
    response=$(curl -s -o /dev/null -w "%{http_code}" "$url/health" 2>/dev/null)
    
    if [ "$response" = "200" ]; then
        echo -e "${GREEN}✓ OK${NC}"
        return 0
    else
        echo -e "${RED}✗ FAILED (HTTP $response)${NC}"
        return 1
    fi
}

# Test API Gateway
echo "=== API Gateway ==="
check_health "API Gateway" "$API_URL"
echo ""

# Test User Service (direct)
echo "=== User Service (Direct) ==="
check_health "User Service" "http://localhost:3001"
echo ""

# Test Chat Service (direct)
echo "=== Chat Service (Direct) ==="
check_health "Chat Service" "http://localhost:3002"
echo ""

# Test Message Service (direct)
echo "=== Message Service (Direct) ==="
check_health "Message Service" "http://localhost:3003"
echo ""

# Test Notification Service (direct)
echo "=== Notification Service (Direct) ==="
check_health "Notification Service" "http://localhost:3004"
echo ""

# Test File Service (direct)
echo "=== File Service (Direct) ==="
check_health "File Service" "http://localhost:3005"
echo ""

# Test WebSocket Gateway (direct)
echo "=== WebSocket Gateway (Direct) ==="
check_health "WebSocket Gateway" "http://localhost:3006"
echo ""

echo "========================================="
echo "Test Tamamlandı"
echo "========================================="

