# Notification Service

Gerçek zamanlı bildirim servisi.

## Özellikler

- Gerçek zamanlı bildirim gönderme
- Bildirim geçmişi
- RabbitMQ event consumer
- WebSocket Gateway ile entegrasyon
- Redis ile kullanıcı çevrimiçi durumu kontrolü

## Teknolojiler

- Node.js (Express)
- MongoDB (Mongoose)
- Redis
- RabbitMQ (amqplib)
- Axios

## API Endpoints

- `GET /api/notifications` - Bildirimleri listele
- `PUT /api/notifications/:notificationId/read` - Bildirimi okundu olarak işaretle
- `PUT /api/notifications/read-all` - Tüm bildirimleri okundu olarak işaretle
- `GET /health` - Health check

## Çalıştırma

```bash
npm install
npm start
```

## Docker

```bash
docker build -t notification-service .
docker run -p 3004:3004 notification-service
```

