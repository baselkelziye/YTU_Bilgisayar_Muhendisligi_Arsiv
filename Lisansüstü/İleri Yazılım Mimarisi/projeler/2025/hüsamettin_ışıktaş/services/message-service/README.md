# Message Service

Mesaj gönderimi, depolama ve mesaj geçmişi servisi.

## Özellikler

- Mesaj gönderme
- Mesaj geçmişi görüntüleme (pagination)
- Mesaj silme (soft delete)
- Mesaj durumu güncelleme
- Redis cache desteği
- RabbitMQ event publishing

## Teknolojiler

- Node.js (Express)
- MongoDB (Mongoose)
- Redis
- RabbitMQ (amqplib)

## API Endpoints

- `POST /api/messages` - Mesaj gönder
- `GET /api/messages/chat/:chatId` - Sohbet mesajlarını listele
- `DELETE /api/messages/:messageId` - Mesaj sil
- `PUT /api/messages/:messageId/status` - Mesaj durumu güncelle
- `GET /health` - Health check

## Çalıştırma

```bash
npm install
npm start
```

## Docker

```bash
docker build -t message-service .
docker run -p 3003:3003 message-service
```

