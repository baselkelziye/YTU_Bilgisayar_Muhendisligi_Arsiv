# 🌿 RecycleShare

Sürdürülebilir bir gelecek için **atık paylaşım ve toplama platformu**. Node.js, PostgreSQL, ve React ile geliştirilmiş tam kapsamlı bir web uygulaması.

## 🌐 Canlı Demo

- **🌍 Frontend**: https://recycle-share.vercel.app
- **🔗 API**: https://recycleshare.onrender.com
- **📚 API Docs**: https://recycleshare.onrender.com/api/docs/
- **🗄️ Database**: Neon PostgreSQL (Frankfurt)

---

## 🎯 Özellikler

### 🔐 Kimlik Doğrulama
- **Standart Kayıt**: Email + Şifre ile OTP doğrulama
- **Google OAuth**: Google ile giriş (yeni kullanıcılar için telefon zorunlu)
- **JWT Tabanlı Oturum**: Güvenli token yönetimi
- Şifre hashleme (bcrypt, 12 salt rounds)
- 6 haneli OTP email doğrulama (10 dakika geçerlilik)

### ♻️ Atık Yönetimi
- **Atık Paylaşma**: Kullanıcılar geri dönüştürülebilir atıklarını paylaşabilir
- **Atık Listeleme**: Bölgedeki mevcut atıkları görüntüleme
- **Atık Türleri**: Plastik, cam, kağıt, metal, elektronik vb.
- **Durum Takibi**: Beklemede, Rezerve, Toplandı

### 📅 Rezervasyon Sistemi
- **Atık Rezervasyonu**: Başkalarının paylaştığı atıkları rezerve etme
- **Rezervasyon Takibi**: Aktif ve geçmiş rezervasyonlar
- **Toplama Onayı**: Atık toplandığında durum güncelleme
- **Otomatik Trigger'lar**: Environmental score hesaplama

### 👥 Topluluk & İstatistikler
- **Çevresel Puan**: Kullanıcıların geri dönüşüm skorları
- **Topluluk Sıralaması**: En aktif katılımcılar
- **Aylık İlerleme**: Impact tracking ve raporlar
- **Admin Dashboard**: Tüm verilerin yönetimi

### 🗄️ Admin Panel
- **Kullanıcı Yönetimi**: CRUD işlemleri, rol değiştirme
- **Atık Türü Yönetimi**: Yeni tür ekleme, düzenleme
- **Trigger Logları**: Veritabanı olaylarını izleme
- **Veritabanı Gezgini**: Tablolar ve ER diyagramı
- **Raporlar**: UNION/INTERSECT/EXCEPT sorguları

### 🎨 Tasarım
- 🌿 **Eco-Minimalist** UI/UX
- 📱 Tam duyarlı (Mobile-first)
- 🎨 Modern glassmorphism & gradients
- ✨ Mikro animasyonlar

---

## 🚀 Hızlı Başlangıç (Yerel Geliştirme)

### Gereksinimler
- Node.js 18+
- npm veya yarn
- Git

### 1. Repoyu Klonla

```bash
git clone git@github.com:aysesude/RecycleShare.git
cd RecycleShare
```

### 2. Backend Kurulumu

```bash
cd backend
npm install
```

`.env` dosyası oluştur:

```env
PORT=5001
NODE_ENV=development

# Database (Neon) - Ekip liderinden al
DATABASE_URL=postgresql://neondb_owner:PASSWORD@ep-xxx.eu-central-1.aws.neon.tech/neondb?sslmode=require

# JWT
JWT_SECRET=recycleshare-super-secret-jwt-key-2024
JWT_EXPIRES_IN=7d

# Google OAuth - Ekip liderinden al
GOOGLE_CLIENT_ID=your-google-client-id.apps.googleusercontent.com

# Email (Gmail SMTP) - Ekip liderinden al
SMTP_HOST=smtp.gmail.com
SMTP_PORT=587
SMTP_USER=recycleshareco@gmail.com
SMTP_PASSWORD=get-from-team-lead

# Frontend URL
FRONTEND_URL=http://localhost:5173
```

> ⚠️ **Not**: `DATABASE_URL`, `GOOGLE_CLIENT_ID`, ve `SMTP_PASSWORD` için ekip liderine danışın

Backend'i başlat:

```bash
npm run dev
```

Backend çalışacak: http://localhost:5001

### 3. Frontend Kurulumu

```bash
cd ../frontend
npm install
```

`.env` dosyası oluştur:

```env
VITE_API_URL=http://localhost:5001/api
VITE_GOOGLE_CLIENT_ID=your-google-client-id.apps.googleusercontent.com
```

Frontend'i başlat:

```bash
npm run dev
```

Frontend çalışacak: http://localhost:5173

---

## 🔌 API Endpoints

Base URL: `https://recycleshare.onrender.com/api`

### Auth Endpoints
| Method | Endpoint | Açıklama |
|--------|----------|----------|
| POST | `/auth/register` | Email/şifre ile kayıt |
| POST | `/auth/verify-otp` | OTP doğrulama |
| POST | `/auth/resend-otp` | OTP tekrar gönder |
| POST | `/auth/login` | Giriş yap |
| POST | `/auth/google` | Google OAuth |
| POST | `/auth/google/complete` | Google kayıt tamamla |
| GET | `/auth/me` | Mevcut kullanıcı bilgisi |

### Waste Endpoints
| Method | Endpoint | Açıklama |
|--------|----------|----------|
| GET | `/waste` | Tüm atıkları listele |
| GET | `/waste/my` | Kullanıcının atıkları |
| POST | `/waste` | Yeni atık ekle |
| PUT | `/waste/:id` | Atık güncelle |
| DELETE | `/waste/:id` | Atık sil |

### Reservation Endpoints
| Method | Endpoint | Açıklama |
|--------|----------|----------|
| GET | `/reservations` | Tüm rezervasyonlar |
| GET | `/reservations/my` | Kullanıcının rezervasyonları |
| POST | `/reservations` | Yeni rezervasyon |
| PUT | `/reservations/:id/collect` | Toplama onayla |
| DELETE | `/reservations/:id` | Rezervasyon iptal |

### Report Endpoints
| Method | Endpoint | Açıklama |
|--------|----------|----------|
| GET | `/reports/impact` | Çevresel etki raporu |
| GET | `/reports/community` | Topluluk istatistikleri |

### Admin Endpoints
| Method | Endpoint | Açıklama |
|--------|----------|----------|
| GET | `/admin/dashboard` | Admin dashboard |
| GET | `/admin/users` | Kullanıcı listesi |
| PUT | `/admin/users/:id/role` | Rol değiştir |
| GET | `/admin/waste-types` | Atık türleri |
| GET | `/admin/trigger-logs` | Trigger logları |
| GET | `/admin/database/tables` | Tablo listesi |
| GET | `/admin/database/schema` | ER şeması |

📚 Tam API dökümantasyonu: https://recycleshare.onrender.com/api/docs/

---

## 🗄️ Veritabanı Şeması

### Tablolar

```
┌─────────────────────────────────────────────────────────────────────┐
│                         RecycleShare DB                             │
├─────────────────────────────────────────────────────────────────────┤
│  users              - Kullanıcılar                                  │
│  waste              - Atık ilanları                                 │
│  waste_types        - Atık türleri (plastik, cam, vb.)              │
│  reservations       - Rezervasyonlar                                │
│  environmental_scores - Kullanıcı çevresel puanları                 │
│  trigger_logs       - Trigger aktivite logları                      │
└─────────────────────────────────────────────────────────────────────┘
```

### İlişkiler
- `waste.user_id` → `users.user_id` (CASCADE)
- `waste.type_id` → `waste_types.type_id` (RESTRICT)
- `reservations.waste_id` → `waste.waste_id` (CASCADE)
- `reservations.collector_id` → `users.user_id` (CASCADE)
- `environmental_scores.user_id` → `users.user_id` (CASCADE)

### Triggers
- **trg_update_waste_status**: Rezervasyon oluşturulduğunda atık durumunu günceller
- **trg_calculate_score**: Atık toplandığında çevresel puan hesaplar
- **trg_log_activities**: Tüm kritik işlemleri loglar

---

## 📁 Proje Yapısı

```
RecycleShare/
├── backend/
│   ├── config/
│   │   └── database.js          # PostgreSQL bağlantısı
│   ├── controllers/
│   │   ├── auth.controller.js   # Kimlik doğrulama
│   │   ├── waste.controller.js  # Atık yönetimi
│   │   ├── reservation.controller.js  # Rezervasyonlar
│   │   ├── report.controller.js # Raporlar
│   │   └── admin.controller.js  # Admin işlemleri
│   ├── middleware/
│   │   └── auth.middleware.js   # JWT doğrulama
│   ├── routes/
│   │   ├── auth.routes.js
│   │   ├── waste.routes.js
│   │   ├── reservation.routes.js
│   │   ├── report.routes.js
│   │   └── admin.routes.js
│   ├── utils/
│   │   ├── email.utils.js       # OTP email
│   │   └── jwt.utils.js         # Token oluşturma
│   ├── swagger.json             # API dökümantasyonu
│   ├── server.js                # Express giriş noktası
│   └── package.json
│
├── frontend/
│   ├── src/
│   │   ├── components/
│   │   │   ├── AuthLayout.jsx
│   │   │   ├── ERDiagram.jsx    # Veritabanı görselleştirme
│   │   │   └── FormElements.jsx
│   │   ├── context/
│   │   │   └── AuthContext.jsx
│   │   ├── pages/
│   │   │   ├── Login.jsx
│   │   │   ├── Register.jsx
│   │   │   ├── VerifyOTP.jsx
│   │   │   ├── GooglePhoneSetup.jsx
│   │   │   ├── Dashboard.jsx    # Ana panel
│   │   │   ├── Listings.jsx     # Atık ilanlarım
│   │   │   ├── BrowseListings.jsx  # Atık keşfet
│   │   │   ├── Community.jsx    # Topluluk
│   │   │   ├── Impact.jsx       # Çevresel etki
│   │   │   ├── AdminDashboard.jsx  # Admin panel
│   │   │   └── DatabaseExplorer.jsx  # DB gezgini
│   │   ├── services/
│   │   │   └── api.js           # API çağrıları
│   │   ├── App.jsx
│   │   └── main.jsx
│   └── package.json
│
├── database/
│   └── schema.sql               # Veritabanı şeması
│
└── README.md
```

---

## 🛠️ Teknoloji Stack

### Backend
- **Runtime**: Node.js 18+
- **Framework**: Express.js
- **Database**: PostgreSQL (Neon Cloud)
- **ORM**: pg (node-postgres)
- **Auth**: JWT, bcrypt, Google OAuth
- **Email**: Nodemailer (Gmail SMTP)
- **Docs**: Swagger UI

### Frontend
- **Framework**: React 18 + Vite
- **Styling**: Tailwind CSS + DaisyUI
- **HTTP Client**: Axios
- **Routing**: React Router v6
- **Auth**: @react-oauth/google
- **Charts**: Recharts
- **Diagrams**: React Flow

### Cloud Services
- **Database**: [Neon](https://neon.tech) - Serverless PostgreSQL
- **Backend**: [Render](https://render.com) - Node.js hosting
- **Frontend**: [Vercel](https://vercel.com) - React hosting

---

## 🔧 Yaygın Sorunlar

### Port 5000 çakışması (macOS)
macOS Control Center port 5000'i kullanır. Bunun yerine 5001 kullanın:
```env
PORT=5001
```

### Google OAuth "Wrong number of segments"
Frontend'in `access_token` değil `id_token` gönderdiğinden emin olun.

### Veritabanı bağlantı hatası
`DATABASE_URL`'in doğru olduğunu ve Neon projesinin aktif olduğunu kontrol edin.

### CORS hataları
Backend localhost:5173, localhost:3000 ve tüm *.onrender.com, *.vercel.app domainlerine izin verir.

---

## 📝 Lisans

MIT

---

## 🤝 Katkıda Bulunma

1. `main` branch'inden feature branch oluşturun
2. Değişikliklerinizi yapın
3. Yerel olarak test edin
4. Push yapıp PR oluşturun

```bash
git checkout main
git pull origin main
git checkout -b feature/your-feature
# ... değişiklikler ...
git push origin feature/your-feature
```

---

💚 **RecycleShare Ekibi** tarafından geliştirildi | v1.0 - 2026
