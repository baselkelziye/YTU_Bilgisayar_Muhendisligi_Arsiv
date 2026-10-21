# 🌿 RecycleShare API Kullanım Kılavuzu

## 📋 İçindekiler
1. [Genel Bilgi](#genel-bilgi)
2. [Kimlik Doğrulama](#kimlik-doğrulama)
3. [Atık API'leri](#atık-apileri)
4. [Rezervasyon API'leri](#rezervasyon-apileri)
5. [Rapor API'leri](#rapor-apileri)
6. [Admin API'leri](#admin-apileri)
7. [Ödev Gereksinimleri Eşleştirmesi](#ödev-gereksinimleri-eşleştirmesi)

---

## 🌐 Genel Bilgi

### Base URL'ler
- **Production:** `https://recycleshare.onrender.com/api`
- **Local:** `http://localhost:5001/api`

### Swagger UI
- **Production:** https://recycleshare.onrender.com/api/docs
- **Local:** http://localhost:5001/api/docs

### Header Formatı
```
Authorization: Bearer <JWT_TOKEN>
Content-Type: application/json
```

### Response Formatı
```json
{
  "success": true/false,
  "message": "İşlem açıklaması",
  "data": { ... },
  "triggerMessage": "TRIGGER mesajı (varsa)"
}
```

---

## 🔐 Kimlik Doğrulama

### 1. Kayıt Ol
```bash
POST /api/auth/register
```

**Body:**
```json
{
  "firstName": "Ahmet",
  "lastName": "Yılmaz",
  "email": "ahmet@test.com",
  "phone": "+905551234567",
  "password": "Test1234"
}
```

**Response:** OTP email'e gönderilir

---

### 2. OTP Doğrula
```bash
POST /api/auth/verify-otp
```

**Body:**
```json
{
  "email": "ahmet@test.com",
  "otp": "123456"
}
```

**Response:**
```json
{
  "success": true,
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...",
  "user": { "user_id": 1, "email": "ahmet@test.com", ... }
}
```

---

### 3. Giriş Yap
```bash
POST /api/auth/login
```

**Body:**
```json
{
  "email": "ahmet@test.com",
  "password": "Test1234"
}
```

**Response:**
```json
{
  "success": true,
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...",
  "user": { ... }
}
```

---

### 4. Mevcut Kullanıcı Bilgisi
```bash
GET /api/auth/me
Authorization: Bearer <token>
```

---

## ♻️ Atık API'leri

### 1. Atık Türlerini Listele (Public)
```bash
GET /api/waste/types
```

**Response:**
```json
{
  "success": true,
  "count": 10,
  "data": [
    { "type_id": 1, "type_name": "Karton", "official_unit": "kg", "recycle_score": 10 },
    { "type_id": 2, "type_name": "Cam", "official_unit": "kg", "recycle_score": 15 },
    ...
  ]
}
```

---

### 2. Aktif Atıkları Listele (VIEW kullanır) ✅
```bash
GET /api/waste
Authorization: Bearer <token>
```

**Query Parametreleri:**
| Parametre | Tip | Açıklama |
|-----------|-----|----------|
| city | string | Şehre göre filtrele |
| type_id | integer | Atık türüne göre filtrele |
| status | string | Duruma göre filtrele (waiting, reserved) |

**Örnek:**
```bash
GET /api/waste?city=İstanbul&status=waiting
```

**📌 SQL:** `SELECT * FROM v_active_waste_details` (VIEW)

---

### 3. Şehre Göre Ara (FUNCTION + INDEX kullanır) ✅
```bash
GET /api/waste/search?city=İstanbul
Authorization: Bearer <token>
```

**📌 SQL:** `SELECT * FROM fn_get_waste_by_city($1)` (FUNCTION)  
**📌 INDEX:** `idx_users_city` üzerinden arama

---

### 4. Yeni Atık Ekle (INSERT + CHECK Constraint) ✅
```bash
POST /api/waste
Authorization: Bearer <token>
```

**Body:**
```json
{
  "type_id": 1,
  "amount": 5.5,
  "description": "Temiz karton kutular"
}
```

**📌 CHECK Constraint:** `amount > 0 AND amount <= 1000`

**Hata Örneği (amount=0 veya amount>1000):**
```json
{
  "success": false,
  "message": "Geçersiz değer: Miktar 0-1000 arasında olmalı"
}
```

---

### 5. Atık Güncelle (UPDATE + TRIGGER) ✅
```bash
PUT /api/waste/:id
Authorization: Bearer <token>
```

**Body:**
```json
{
  "status": "collected"
}
```

**Response (TRIGGER mesajı ile):**
```json
{
  "success": true,
  "message": "Atık başarıyla güncellendi",
  "triggerMessage": "Tebrikler! 55 çevresel puan kazandınız!",
  "data": { ... }
}
```

**📌 TRIGGER:** `trg_update_environmental_score` - Status "collected" olunca çevresel puan hesaplar

---

### 6. Atık Sil (DELETE + CASCADE) ✅
```bash
DELETE /api/waste/:id
Authorization: Bearer <token>
```

**📌 CASCADE:** İlgili rezervasyonlar da silinir

---

### 7. Kendi Atıklarım
```bash
GET /api/waste/my
Authorization: Bearer <token>
```

---

## 📅 Rezervasyon API'leri

### 1. Rezervasyonları Listele
```bash
GET /api/reservations
Authorization: Bearer <token>
```

**Query Parametreleri:**
| Parametre | Tip | Açıklama |
|-----------|-----|----------|
| status | string | waiting, reserved, collected, cancelled |
| waste_id | integer | Belirli atığın rezervasyonları |

---

### 2. Rezervasyon Oluştur (SEQUENCE + TRIGGER) ✅
```bash
POST /api/reservations
Authorization: Bearer <token>
```

**Body:**
```json
{
  "waste_id": 1,
  "pickup_datetime": "2026-01-10T14:00:00"
}
```

**Response (SEQUENCE + TRIGGER mesajı ile):**
```json
{
  "success": true,
  "message": "Rezervasyon başarıyla oluşturuldu",
  "reservationNumber": 1005,
  "triggerMessage": "Atığınız için yeni rezervasyon! Toplayıcı: Ahmet Yılmaz, Tarih: 10.01.2026 14:00",
  "data": { ... }
}
```

**📌 SEQUENCE:** `reservation_number_seq` - Otomatik artan rezervasyon numarası  
**📌 TRIGGER:** `trg_reservation_status_change` - Atık durumunu "reserved" yapar

---

### 3. Rezervasyon Güncelle (TRIGGER) ✅
```bash
PUT /api/reservations/:id
Authorization: Bearer <token>
```

**Body (Toplama tamamlandı):**
```json
{
  "status": "collected"
}
```

**Response:**
```json
{
  "success": true,
  "triggerMessage": "Atık başarıyla toplandı! Reservation ID: 5",
  "data": { ... }
}
```

**Body (İptal):**
```json
{
  "status": "cancelled"
}
```

**Response:**
```json
{
  "success": true,
  "triggerMessage": "Rezervasyon iptal edildi. Atık tekrar listeye eklendi.",
  "data": { ... }
}
```

**📌 TRIGGER:** Status değişince atık durumu da güncellenir

---

### 4. Toplayıcı Olarak Rezervasyonlarım
```bash
GET /api/reservations/my/collector
Authorization: Bearer <token>
```

---

### 5. Atıklarıma Yapılan Rezervasyonlar
```bash
GET /api/reservations/my/owner
Authorization: Bearer <token>
```

---

## 📊 Rapor API'leri

### 1. Kişisel Raporum (FUNCTION + VIEW) ✅
```bash
GET /api/reports/my
Authorization: Bearer <token>
```

**Response:**
```json
{
  "success": true,
  "message": "Kişisel çevresel etki raporu",
  "data": {
    "statistics": { ... },
    "calculatedScore": 150,
    "currentMonthReport": [ ... ],
    "recentWaste": [ ... ]
  }
}
```

---

### 2. Kullanıcı Aylık Raporu (CURSOR + RECORD) ✅
```bash
GET /api/reports/user/:userId/monthly?year=2026&month=1
Authorization: Bearer <token>
```

**📌 FUNCTION:** `fn_get_user_monthly_report()` - CURSOR ve RECORD kullanır

**Response:**
```json
{
  "success": true,
  "data": [
    { "report_type": "WASTE_DETAIL", "type_name": "Karton", "item_count": 2, "total_amount": 10.5, "total_score": 105 },
    { "report_type": "WASTE_DETAIL", "type_name": "Cam", "item_count": 1, "total_amount": 3.0, "total_score": 45 },
    { "report_type": "SUMMARY", "type_name": "TOPLAM", "item_count": 3, "total_amount": 13.5, "total_score": 150 }
  ]
}
```

---

### 3. Kullanıcı Toplam Puanı (FUNCTION) ✅
```bash
GET /api/reports/user/:userId/score
Authorization: Bearer <token>
```

**📌 FUNCTION:** `fn_calculate_user_total_score()`

---

### 4. Aktif Kullanıcılar (UNION) ✅
```bash
GET /api/reports/active-users
Authorization: Bearer <token>
```

**📌 SQL:**
```sql
SELECT ... FROM users WHERE EXISTS (SELECT 1 FROM waste ...)
UNION
SELECT ... FROM users WHERE EXISTS (SELECT 1 FROM reservations ...)
```

**Response:**
```json
{
  "success": true,
  "sqlUsed": "UNION",
  "data": [
    { "user_id": 1, "first_name": "Ahmet", "activity_type": "Paylaşımcı" },
    { "user_id": 1, "first_name": "Ahmet", "activity_type": "Toplayıcı" },
    ...
  ]
}
```

---

### 5. Hiç Rezervasyon Yapmamışlar (EXCEPT) ✅
```bash
GET /api/reports/inactive-collectors
Authorization: Bearer <token>
```

**📌 SQL:**
```sql
SELECT user_id, first_name, last_name FROM users
EXCEPT
SELECT DISTINCT u.user_id, u.first_name, u.last_name FROM users u JOIN reservations r ON ...
```

---

### 6. En Çok Katkı Yapanlar (AGGREGATE + HAVING) ✅
```bash
GET /api/reports/top-contributors?minWasteCount=2
Authorization: Bearer <token>
```

**📌 SQL:**
```sql
SELECT ..., COUNT(w.waste_id) AS waste_count, SUM(w.amount), AVG(w.amount), MAX(w.record_date)
FROM users u JOIN waste w ON ...
GROUP BY ...
HAVING COUNT(w.waste_id) >= 2
```

**Response:**
```json
{
  "success": true,
  "sqlUsed": "COUNT, SUM, AVG, MAX + HAVING",
  "threshold": 2,
  "data": [
    { "user_id": 1, "full_name": "Ahmet Yılmaz", "waste_count": 5, "total_amount": 25.5, "avg_amount": 5.1 }
  ]
}
```

---

### 7. Atık İstatistikleri (AGGREGATE) ✅
```bash
GET /api/reports/waste-statistics
Authorization: Bearer <token>
```

**📌 SQL:** `COUNT, SUM, AVG, MIN, MAX, CASE WHEN`

---

### 8. Aylık Genel Bakış (VIEW) ✅
```bash
GET /api/reports/monthly-overview?year=2026
Authorization: Bearer <token>
```

**📌 VIEW:** `v_monthly_recycling_report`

---

### 9. Kullanıcı İstatistikleri (VIEW) ✅
```bash
GET /api/reports/user-statistics
Authorization: Bearer <token>
```

**📌 VIEW:** `v_user_statistics`

---

### 10. Şehir Sıralaması (AGGREGATE + HAVING) ✅
```bash
GET /api/reports/city-ranking?minUsers=1
Authorization: Bearer <token>
```

---

## 👑 Admin API'leri

> ⚠️ Bu API'ler sadece `role: "admin"` olan kullanıcılar tarafından kullanılabilir.

### 1. Dashboard
```bash
GET /api/admin/dashboard
Authorization: Bearer <admin_token>
```

---

### 2. Kullanıcıları Listele
```bash
GET /api/admin/users?role=user&city=İstanbul&is_active=true
Authorization: Bearer <admin_token>
```

---

### 3. Kullanıcı Rolü Değiştir
```bash
PUT /api/admin/users/:id/role
Authorization: Bearer <admin_token>
```

**Body:**
```json
{
  "role": "admin"
}
```

---

### 4. Kullanıcı Aktifliğini Değiştir
```bash
PUT /api/admin/users/:id/status
Authorization: Bearer <admin_token>
```

**Body:**
```json
{
  "is_active": false
}
```

---

### 5. Kullanıcı Sil (CASCADE) ✅
```bash
DELETE /api/admin/users/:id
Authorization: Bearer <admin_token>
```

**📌 CASCADE:** Kullanıcının atıkları ve rezervasyonları da silinir

---

### 6. Atık Türlerini Yönet

**Listele:**
```bash
GET /api/admin/waste-types
Authorization: Bearer <admin_token>
```

**Ekle:**
```bash
POST /api/admin/waste-types
Authorization: Bearer <admin_token>
```

**Body:**
```json
{
  "type_name": "Yeni Tür",
  "official_unit": "kg",
  "recycle_score": 15
}
```

**📌 CHECK Constraint:** `recycle_score >= 0 AND recycle_score <= 100`

**Güncelle:**
```bash
PUT /api/admin/waste-types/:id
Authorization: Bearer <admin_token>
```

**Sil (RESTRICT) ✅:**
```bash
DELETE /api/admin/waste-types/:id
Authorization: Bearer <admin_token>
```

**📌 RESTRICT:** Kullanımda olan tür silinemez

**Hata Response:**
```json
{
  "success": false,
  "message": "Bu atık türü 5 atıkta kullanılıyor. RESTRICT kısıtı nedeniyle silinemez.",
  "usageCount": 5
}
```

---

### 7. Trigger Logları
```bash
GET /api/admin/trigger-logs?limit=50
Authorization: Bearer <admin_token>
```

**Response:**
```json
{
  "success": true,
  "data": [
    {
      "log_id": 1,
      "trigger_name": "trg_update_environmental_score",
      "table_name": "waste",
      "action": "UPDATE",
      "message": "Tebrikler! 55 çevresel puan kazandınız!",
      "created_at": "2026-01-04T10:30:00"
    }
  ]
}
```

---

## 📋 Ödev Gereksinimleri Eşleştirmesi

| Gereksinim | API Endpoint | SQL Objesi |
|------------|--------------|------------|
| En az 4 tablo | - | users, waste_types, waste, reservations, environmental_scores |
| Primary/Foreign Key | - | Tüm tablolarda mevcut |
| Silme Kısıtı (CASCADE) | DELETE /api/waste/:id | waste → reservations |
| Silme Kısıtı (RESTRICT) | DELETE /api/admin/waste-types/:id | waste_types → waste |
| Sayı Kısıtı (CHECK) | POST /api/waste | amount > 0 AND <= 1000 |
| VIEW | GET /api/waste | v_active_waste_details |
| VIEW | GET /api/reports/user-statistics | v_user_statistics |
| VIEW | GET /api/reports/monthly-overview | v_monthly_recycling_report |
| INDEX | GET /api/waste/search | idx_users_city |
| SEQUENCE | POST /api/reservations | reservation_number_seq |
| FUNCTION 1 | GET /api/reports/user/:id/score | fn_calculate_user_total_score |
| FUNCTION 2 | GET /api/waste/search | fn_get_waste_by_city |
| FUNCTION 3 (CURSOR+RECORD) | GET /api/reports/user/:id/monthly | fn_get_user_monthly_report |
| TRIGGER 1 | PUT /api/waste/:id (status=collected) | trg_update_environmental_score |
| TRIGGER 2 | POST/PUT /api/reservations | trg_reservation_status_change |
| UNION | GET /api/reports/active-users | Paylaşımcı + Toplayıcı |
| EXCEPT | GET /api/reports/inactive-collectors | Hiç rezervasyon yapmamışlar |
| AGGREGATE + HAVING | GET /api/reports/top-contributors | COUNT, SUM, AVG, MAX + HAVING |
| 2 Farklı Rol | - | admin, user |

---

## 🧪 Test Senaryoları

### Senaryo 1: Yeni Atık Ekleme ve Toplama
```bash
# 1. Giriş yap
curl -X POST http://localhost:5001/api/auth/login \
  -H "Content-Type: application/json" \
  -d '{"email":"ahmet@test.com","password":"Test1234"}'

# 2. Atık ekle
curl -X POST http://localhost:5001/api/waste \
  -H "Authorization: Bearer <token>" \
  -H "Content-Type: application/json" \
  -d '{"type_id":1,"amount":5.5,"description":"Karton kutular"}'

# 3. Rezervasyon yap (başka kullanıcı)
curl -X POST http://localhost:5001/api/reservations \
  -H "Authorization: Bearer <other_user_token>" \
  -H "Content-Type: application/json" \
  -d '{"waste_id":1,"pickup_datetime":"2026-01-10T14:00:00"}'

# 4. Toplama tamamla (TRIGGER çalışır)
curl -X PUT http://localhost:5001/api/reservations/1 \
  -H "Authorization: Bearer <token>" \
  -H "Content-Type: application/json" \
  -d '{"status":"collected"}'
```

### Senaryo 2: CHECK Constraint Testi
```bash
# Hatalı miktar (0)
curl -X POST http://localhost:5001/api/waste \
  -H "Authorization: Bearer <token>" \
  -H "Content-Type: application/json" \
  -d '{"type_id":1,"amount":0,"description":"Test"}'

# Hatalı miktar (1001)
curl -X POST http://localhost:5001/api/waste \
  -H "Authorization: Bearer <token>" \
  -H "Content-Type: application/json" \
  -d '{"type_id":1,"amount":1001,"description":"Test"}'
```

### Senaryo 3: RESTRICT Constraint Testi
```bash
# Kullanımda olan atık türünü silmeye çalış
curl -X DELETE http://localhost:5001/api/admin/waste-types/1 \
  -H "Authorization: Bearer <admin_token>"
```

---

## 📞 İletişim

Sorularınız için: **Swagger UI** üzerinden API'leri test edebilirsiniz.

- Local: http://localhost:5001/api/docs
- Production: https://recycleshare.onrender.com/api/docs
