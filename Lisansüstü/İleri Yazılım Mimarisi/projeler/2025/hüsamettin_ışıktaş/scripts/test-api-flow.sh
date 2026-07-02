#!/bin/bash

# API akış testi - Kullanıcı kaydı, giriş, sohbet oluşturma, mesaj gönderme

API_URL="http://localhost:3000"
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo "========================================="
echo "API Akış Testi"
echo "========================================="
echo ""

# Random email ve username oluştur
RANDOM_ID=$(date +%s)
TEST_EMAIL="test${RANDOM_ID}@test.com"
TEST_USERNAME="testuser${RANDOM_ID}"
TEST_PASSWORD="Test123456"
TEST_FIRST_NAME="Test"
TEST_LAST_NAME="User"

echo -e "${BLUE}Test Kullanıcı Bilgileri:${NC}"
echo "Email: $TEST_EMAIL"
echo "Username: $TEST_USERNAME"
echo ""

# 1. Kullanıcı Kaydı
echo -e "${YELLOW}1. Kullanıcı Kaydı Testi${NC}"
REGISTER_RESPONSE=$(curl -s -X POST "$API_URL/api/users/register" \
  -H "Content-Type: application/json" \
  -d "{
    \"email\": \"$TEST_EMAIL\",
    \"username\": \"$TEST_USERNAME\",
    \"password\": \"$TEST_PASSWORD\",
    \"firstName\": \"$TEST_FIRST_NAME\",
    \"lastName\": \"$TEST_LAST_NAME\"
  }")

echo "Response: $REGISTER_RESPONSE"
SUCCESS=$(echo $REGISTER_RESPONSE | grep -o '"success":true' || echo "")
if [ -n "$SUCCESS" ]; then
    echo -e "${GREEN}✓ Kayıt başarılı${NC}"
    # ID'yi alırken hem tırnaklı (string) hem tırnaksız (integer) formatı destekle
    USER_ID=$(echo $REGISTER_RESPONSE | grep -o '"id":[^,}]*' | tr -d '"id:' | tr -d ' ')
    echo "User ID: $USER_ID"
else
    echo -e "${RED}✗ Kayıt başarısız${NC}"
    echo "Test durduruldu."
    exit 1
fi
echo ""

# 2. Kullanıcı Girişi
echo -e "${YELLOW}2. Kullanıcı Girişi Testi${NC}"
LOGIN_RESPONSE=$(curl -s -X POST "$API_URL/api/users/login" \
  -H "Content-Type: application/json" \
  -d "{
    \"email\": \"$TEST_EMAIL\",
    \"password\": \"$TEST_PASSWORD\"
  }")

echo "Response: $LOGIN_RESPONSE"
TOKEN=$(echo $LOGIN_RESPONSE | grep -o '"token":"[^"]*' | cut -d'"' -f4)
if [ -n "$TOKEN" ]; then
    echo -e "${GREEN}✓ Giriş başarılı${NC}"
    echo "Token: ${TOKEN:0:50}..."
else
    echo -e "${RED}✗ Giriş başarısız${NC}"
    echo "Test durduruldu."
    exit 1
fi
echo ""

# 3. Profil Görüntüleme
echo -e "${YELLOW}3. Profil Görüntüleme Testi${NC}"
PROFILE_RESPONSE=$(curl -s -X GET "$API_URL/api/users/$USER_ID" \
  -H "Authorization: Bearer $TOKEN")

echo "Response: $PROFILE_RESPONSE"
if echo $PROFILE_RESPONSE | grep -q '"success":true'; then
    echo -e "${GREEN}✓ Profil görüntüleme başarılı${NC}"
else
    echo -e "${RED}✗ Profil görüntüleme başarısız${NC}"
fi
echo ""

# 4. Sohbet Listesi (boş olabilir)
echo -e "${YELLOW}4. Sohbet Listesi Testi${NC}"
CHATS_RESPONSE=$(curl -s -X GET "$API_URL/api/chats/user/me" \
  -H "Authorization: Bearer $TOKEN")

echo "Response: $CHATS_RESPONSE"
if echo $CHATS_RESPONSE | grep -q '"success":true'; then
    echo -e "${GREEN}✓ Sohbet listesi başarılı${NC}"
else
    echo -e "${RED}✗ Sohbet listesi başarısız${NC}"
fi
echo ""

# 5. Bildirim Listesi
echo -e "${YELLOW}5. Bildirim Listesi Testi${NC}"
NOTIFICATIONS_RESPONSE=$(curl -s -X GET "$API_URL/api/notifications" \
  -H "Authorization: Bearer $TOKEN")

echo "Response: $NOTIFICATIONS_RESPONSE"
if echo $NOTIFICATIONS_RESPONSE | grep -q '"success":true'; then
    echo -e "${GREEN}✓ Bildirim listesi başarılı${NC}"
else
    echo -e "${RED}✗ Bildirim listesi başarısız${NC}"
fi
echo ""

echo "========================================="
echo -e "${GREEN}Temel API Testleri Tamamlandı${NC}"
echo "========================================="
echo ""
echo "Test kullanıcısı: $TEST_EMAIL"
echo "Token: ${TOKEN:0:50}..."

