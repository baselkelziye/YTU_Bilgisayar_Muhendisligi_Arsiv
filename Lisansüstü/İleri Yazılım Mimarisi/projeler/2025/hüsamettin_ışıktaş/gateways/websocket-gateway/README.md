# WebSocket Gateway

Gerçek zamanlı bağlantı yönetimi ve bildirim servisi.

## Özellikler

- WebSocket bağlantı yönetimi
- Kullanıcı bağlantı durumu takibi
- Gerçek zamanlı bildirim gönderme
- Redis ile connection state yönetimi

## Teknolojiler

- Node.js (Express)
- Socket.io
- Redis

## API Endpoints

- `POST /api/notifications/send` - Bildirim gönder (Notification Service'den çağrılır)
- `GET /health` - Health check

## WebSocket Events

### Client → Server
- `ping` - Bağlantı kontrolü

### Server → Client
- `connected` - Bağlantı başarılı
- `notification` - Yeni bildirim
- `pong` - Ping yanıtı

## Bağlantı

WebSocket bağlantısı için token gereklidir:
```javascript
const socket = io('http://localhost:3006', {
  auth: {
    token: 'your-jwt-token'
  }
});
```

## Çalıştırma

```bash
npm install
npm start
```

## Docker

```bash
docker build -t websocket-gateway .
docker run -p 3006:3006 websocket-gateway
```

