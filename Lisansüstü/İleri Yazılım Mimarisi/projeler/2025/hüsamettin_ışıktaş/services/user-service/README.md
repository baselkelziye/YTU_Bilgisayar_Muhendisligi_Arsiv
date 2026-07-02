# User Service

Kullanıcı yönetimi, kimlik doğrulama ve profil yönetimi servisi.

## Özellikler

- Kullanıcı kaydı
- Kullanıcı girişi (JWT token)
- Profil görüntüleme ve güncelleme
- Redis cache desteği

## Teknolojiler

- Node.js (Express)
- PostgreSQL
- Redis
- JWT (jsonwebtoken)
- bcrypt (şifre hash'leme)

## API Endpoints

- `POST /api/users/register` - Kullanıcı kaydı
- `POST /api/users/login` - Kullanıcı girişi
- `GET /api/users/:userId` - Profil görüntüleme
- `PUT /api/users/:userId` - Profil güncelleme
- `GET /health` - Health check

## Çalıştırma

```bash
# Dependencies yükle
npm install

# .env dosyasını oluştur
cp .env.example .env

# Servisi başlat
npm start

# Development mode
npm run dev
```

## Docker

```bash
docker build -t user-service .
docker run -p 3001:3001 user-service
```

