# Chat Service

Sohbet odaları, birebir ve grup sohbet yönetimi servisi.

## Özellikler

- Birebir sohbet oluşturma
- Grup sohbeti oluşturma
- Sohbet listesi görüntüleme
- Katılımcı ekleme/çıkarma
- Redis cache desteği
- RabbitMQ event publishing

## Teknolojiler

- Node.js (Express)
- MongoDB (Mongoose)
- Redis
- RabbitMQ (amqplib)
- Axios (User Service ile iletişim)

## API Endpoints

- `POST /api/chats/direct` - Birebir sohbet oluştur
- `POST /api/chats/group` - Grup sohbeti oluştur
- `GET /api/chats/user/:userId` - Kullanıcının sohbetlerini listele
- `GET /api/chats/:chatId` - Sohbet detayları
- `POST /api/chats/:chatId/participants` - Katılımcı ekle
- `DELETE /api/chats/:chatId/participants/:userId` - Katılımcı çıkar
- `GET /health` - Health check

## Çalıştırma

```bash
npm install
npm start
```

## Docker

```bash
docker build -t chat-service .
docker run -p 3002:3002 chat-service
```

