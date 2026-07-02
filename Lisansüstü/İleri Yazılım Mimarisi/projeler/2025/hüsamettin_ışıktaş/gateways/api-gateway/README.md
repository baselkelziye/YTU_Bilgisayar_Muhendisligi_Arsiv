# API Gateway

Tüm HTTP isteklerini yönlendiren ve kimlik doğrulama yapan API Gateway.

## Özellikler

- Request routing (servislere yönlendirme)
- Authentication middleware
- Rate limiting
- CORS desteği

## Teknolojiler

- Node.js (Express)
- http-proxy-middleware
- express-rate-limit
- JWT

## API Endpoints

Tüm istekler `/api/*` prefix'i ile başlar:

- `/api/users/*` → User Service
- `/api/chats/*` → Chat Service
- `/api/messages/*` → Message Service
- `/api/notifications/*` → Notification Service
- `/api/files/*` → File Service

## Çalıştırma

```bash
npm install
npm start
```

## Docker

```bash
docker build -t api-gateway .
docker run -p 3000:3000 api-gateway
```

