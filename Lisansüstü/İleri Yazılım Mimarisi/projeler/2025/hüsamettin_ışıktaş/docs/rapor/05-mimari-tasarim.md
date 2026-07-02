# 5. Mimari Tasarım

## 5.1 Genel Mimari Yaklaşım

Sistem, mikroservis mimarisine dayalı olarak tasarlanmıştır. Bu mimari, sistemin ölçeklenebilirliğini, dayanıklılığını ve bakım kolaylığını artırmak için tercih edilmiştir. Her mikroservis, bağımsız olarak geliştirilebilir, test edilebilir, dağıtılabilir ve ölçeklendirilebilir.

### 5.1.1 Mimari Prensipler

- **Bağımsız Dağıtılabilirlik**: Her servis bağımsız olarak dağıtılabilir
- **Tek Sorumluluk**: Her servis belirli bir iş alanından (domain) sorumludur
- **Veritabanı Ayrımı**: Her servis kendi veritabanına sahiptir (Database per Service)
- **API Tabanlı İletişim**: Servisler REST API ve message queue ile iletişim kurar
- **Hata Toleransı**: Bir servisin çökmesi tüm sistemi etkilemez

## 5.2 Mikroservisler ve Sorumlulukları

### 5.2.1 User Service

**Sorumluluklar:**
- Kullanıcı kaydı ve doğrulama
- Kullanıcı girişi ve kimlik doğrulama (JWT token oluşturma)
- Profil yönetimi (görüntüleme, güncelleme)
- Kullanıcı bilgilerini diğer servislere sağlama

**API Endpoints:**
- `POST /api/users/register` - Kullanıcı kaydı
- `POST /api/users/login` - Kullanıcı girişi
- `GET /api/users/{userId}` - Profil görüntüleme
- `PUT /api/users/{userId}` - Profil güncelleme

**Veritabanı:** PostgreSQL
- Kullanıcı bilgileri (email, username, password hash, profil bilgileri)

**Bağımlılıklar:**
- Redis (oturum yönetimi, cache)

### 5.2.2 Chat Service

**Sorumluluklar:**
- Birebir ve grup sohbeti oluşturma
- Sohbet listesi yönetimi
- Sohbet katılımcı yönetimi (ekleme, çıkarma)
- Sohbet metadata yönetimi

**API Endpoints:**
- `POST /api/chats/direct` - Birebir sohbet oluşturma
- `POST /api/chats/group` - Grup sohbeti oluşturma
- `GET /api/chats/user/{userId}` - Kullanıcının sohbetlerini listeleme
- `POST /api/chats/{chatId}/participants` - Katılımcı ekleme
- `DELETE /api/chats/{chatId}/participants/{userId}` - Katılımcı çıkarma

**Veritabanı:** MongoDB
- Sohbet bilgileri (id, type, name, createdBy, timestamps)
- Sohbet katılımcıları (chatId, userId, role, joinedAt)

**Bağımlılıklar:**
- User Service (kullanıcı doğrulama için REST API)
- RabbitMQ (sohbet oluşturma bildirimleri için)
- Redis (sık kullanılan sohbet bilgilerini cache'leme)

### 5.2.3 Message Service

**Sorumluluklar:**
- Mesaj gönderme ve depolama
- Mesaj geçmişi sorgulama (pagination)
- Mesaj silme (soft delete)
- Mesaj durumu yönetimi (sent, delivered, read, deleted)

**API Endpoints:**
- `POST /api/messages` - Mesaj gönderme
- `GET /api/messages/chat/{chatId}` - Sohbet mesajlarını listeleme
- `DELETE /api/messages/{messageId}` - Mesaj silme
- `PUT /api/messages/{messageId}/status` - Mesaj durumu güncelleme

**Veritabanı:** MongoDB
- Mesaj bilgileri (id, chatId, senderId, content, type, status, timestamps)

**Bağımlılıklar:**
- RabbitMQ (mesaj bildirimleri için event publish)
- Redis (sık sorgulanan mesajları cache'leme)
- Notification Service (bildirim gönderme için REST API)

### 5.2.4 Notification Service

**Sorumluluklar:**
- Gerçek zamanlı bildirim gönderme (WebSocket)
- Bildirim kuyruğu yönetimi (çevrimdışı kullanıcılar için)
- Bildirim geçmişi saklama
- Bildirim durumu yönetimi (okundu/okunmadı)

**API Endpoints:**
- `GET /api/notifications/user/{userId}` - Kullanıcı bildirimlerini listeleme
- `PUT /api/notifications/{notificationId}/read` - Bildirimi okundu olarak işaretleme
- WebSocket: `/ws/notifications/{userId}` - Gerçek zamanlı bildirim alımı

**Veritabanı:** MongoDB
- Bildirim bilgileri (id, userId, type, title, body, data, read, timestamps)

**Bağımlılıklar:**
- RabbitMQ (mesaj/sohbet eventlerini dinleme)
- WebSocket Gateway (gerçek zamanlı bildirim gönderme)
- Redis (kullanıcı bağlantı durumunu takip etme)

### 5.2.5 File Service

**Sorumluluklar:**
- Dosya yükleme ve depolama
- Dosya indirme ve URL oluşturma
- Dosya türü ve boyut kontrolü
- Güvenli dosya erişimi (zaman sınırlı URL'ler)

**API Endpoints:**
- `POST /api/files/upload` - Dosya yükleme
- `GET /api/files/{fileId}/download` - Dosya indirme
- `DELETE /api/files/{fileId}` - Dosya silme
- `GET /api/files/{fileId}/url` - Güvenli URL oluşturma

**Veritabanı:** PostgreSQL
- Dosya metadata (id, originalName, storedName, mimeType, size, url, uploadedBy, timestamps)

**Bağımlılıklar:**
- Storage Service (S3/MinIO - dosya depolama)
- Message Service (dosya paylaşımı için REST API)

## 5.3 Altyapı Bileşenleri

### 5.3.1 API Gateway

**Sorumluluklar:**
- Tüm dış HTTP isteklerini yönlendirme
- Kimlik doğrulama (authentication) ve yetkilendirme (authorization)
- Rate limiting
- Request/Response logging
- Load balancing

**Teknoloji:** Nginx veya Kong API Gateway

**Yönlendirme Kuralları:**
- `/api/users/*` → User Service
- `/api/chats/*` → Chat Service
- `/api/messages/*` → Message Service
- `/api/notifications/*` → Notification Service
- `/api/files/*` → File Service

### 5.3.2 WebSocket Gateway

**Sorumluluklar:**
- WebSocket bağlantı yönetimi
- Kullanıcı bağlantı durumu takibi
- Gerçek zamanlı mesaj iletimi
- Connection pooling

**Teknoloji:** Node.js (Socket.io) veya Go (Gorilla WebSocket)

**Bağlantı Yönetimi:**
- Kullanıcı başına WebSocket bağlantısı
- Bağlantı durumu Redis'te saklanır
- Notification Service'ten gelen bildirimleri ilgili kullanıcılara iletir

### 5.3.3 Message Queue (RabbitMQ)

**Sorumluluklar:**
- Servisler arası asenkron iletişim
- Event-driven architecture desteği
- Mesaj persistence
- Message routing (exchange ve queue yapısı)

**Exchange ve Queue Yapısı:**
- `chat.exchange` → `chat.created.queue` (sohbet oluşturma bildirimleri)
- `message.exchange` → `message.created.queue` (mesaj oluşturma bildirimleri)
- Notification Service bu queue'ları dinler

**Mesaj Formatı:**
```json
{
  "event": "message.created",
  "timestamp": "2025-01-15T10:30:00Z",
  "data": {
    "messageId": "msg123",
    "chatId": "chat456",
    "senderId": "user789",
    "content": "Merhaba"
  }
}
```

### 5.3.4 Cache (Redis)

**Sorumluluklar:**
- Oturum yönetimi (session storage)
- Sık kullanılan verilerin cache'lenmesi
- Kullanıcı bağlantı durumu takibi
- Rate limiting için sayaçlar

**Cache Stratejileri:**
- **User Service**: Kullanıcı profil bilgileri (TTL: 1 saat)
- **Chat Service**: Sohbet listesi (TTL: 30 dakika)
- **Message Service**: Son mesajlar (TTL: 15 dakika)
- **WebSocket Gateway**: Kullanıcı bağlantı durumları (TTL: 5 dakika)

**Cache Key Örnekleri:**
- `user:{userId}` - Kullanıcı bilgileri
- `chats:user:{userId}` - Kullanıcının sohbet listesi
- `connection:{userId}` - Kullanıcı bağlantı durumu

### 5.3.5 Veritabanları

**Database per Service Stratejisi:**

1. **User Service - PostgreSQL**
   - İlişkisel veriler için uygun
   - ACID garantileri gereklidir
   - Kullanıcı bilgileri, oturumlar

2. **Chat Service - MongoDB**
   - Esnek şema yapısı
   - Katılımcı listesi dinamik
   - Kolay ölçeklenebilirlik

3. **Message Service - MongoDB**
   - Yüksek yazma hızı gereksinimi
   - Mesajlar yapısal olarak benzer
   - Kolay sharding

4. **Notification Service - MongoDB**
   - Yüksek yazma hızı
   - Geçici veriler (bildirimler)
   - Kolay arşivleme

5. **File Service - PostgreSQL**
   - Dosya metadata için ilişkisel yapı uygun
   - Transaction desteği gerekli

## 5.4 Servisler Arası İletişim Desenleri

### 5.4.1 Senkron İletişim (REST API)

**Kullanım Senaryoları:**
- Anında yanıt gerektiren işlemler
- Request-Response pattern

**Örnekler:**
- Chat Service → User Service (kullanıcı doğrulama)
- Message Service → Notification Service (bildirim gönderme)
- File Service → Message Service (dosya paylaşımı)

**Güvenlik:**
- JWT token ile kimlik doğrulama
- Service-to-service authentication
- HTTPS kullanımı

### 5.4.2 Asenkron İletişim (Message Queue)

**Kullanım Senaryoları:**
- Event-driven işlemler
- Loose coupling gereksinimi
- Yüksek throughput

**Örnekler:**
- Message Service → RabbitMQ → Notification Service (mesaj bildirimi)
- Chat Service → RabbitMQ → Notification Service (sohbet bildirimi)

**Avantajlar:**
- Servisler birbirinden bağımsız
- Hata toleransı (mesajlar queue'da bekleyebilir)
- Ölçeklenebilirlik (birden fazla consumer)

### 5.4.3 Gerçek Zamanlı İletişim (WebSocket)

**Kullanım Senaryoları:**
- Anında bildirim gereksinimi
- Çift yönlü iletişim

**Örnekler:**
- Notification Service → WebSocket Gateway → Client (mesaj bildirimi)

**Mimari:**
- WebSocket Gateway, kullanıcı bağlantılarını yönetir
- Notification Service, bildirimleri WebSocket Gateway'e gönderir
- Gateway, bildirimleri ilgili kullanıcılara iletir

## 5.5 Veri Yönetimi Stratejisi

### 5.5.1 Database per Service

Her mikroservis kendi veritabanına sahiptir. Bu yaklaşımın avantajları:
- Servisler arası bağımsızlık
- Teknoloji seçiminde esneklik
- Ölçeklenebilirlik (her servis ayrı ölçeklenebilir)

### 5.5.2 Veri Tutarlılığı

**Eventual Consistency:**
- Servisler arası veri tutarlılığı eventual consistency ile sağlanır
- Mesaj gönderildiğinde, bildirim asenkron olarak gönderilir
- Bu yaklaşım yüksek performans sağlar

**Transaction Yönetimi:**
- Servis içi işlemler için transaction kullanılır
- Servisler arası transaction yoktur (distributed transaction yok)

### 5.5.3 Veri Replikasyonu

- Veritabanları master-slave replikasyon ile yapılandırılır
- Okuma işlemleri replica'lardan yapılabilir
- Yazma işlemleri master'dan yapılır

### 5.5.4 Veri Arşivleme

- Eski mesajlar ayrı bir arşiv veritabanına taşınabilir
- Bildirimler belirli bir süre sonra arşivlenebilir
- Arşivleme stratejisi performansı artırır

## 5.6 Güvenlik Mimarisi

### 5.6.1 Kimlik Doğrulama (Authentication)

- **JWT Token**: Kullanıcı girişinde JWT token oluşturulur
- **Token Yapısı**: User ID, email, exp (expiration time)
- **Token Saklama**: İstemci tarafında (localStorage/cookie)
- **Token Doğrulama**: API Gateway'de middleware ile yapılır

### 5.6.2 Yetkilendirme (Authorization)

- Token içindeki user bilgileri kullanılır
- Kullanıcı sadece kendi kaynaklarına erişebilir
- Servisler arası iletişimde service token kullanılır

### 5.6.3 Veri Güvenliği

- **Şifreleme**: Şifreler bcrypt ile hash'lenir
- **HTTPS**: Tüm iletişim HTTPS üzerinden yapılır
- **Dosya URL'leri**: Zaman sınırlı ve token tabanlı
- **Input Validation**: Tüm inputlar doğrulanır ve sanitize edilir

### 5.6.4 Güvenlik Kontrolleri

- **Rate Limiting**: API Gateway'de uygulanır (kullanıcı başına dakikada 60 istek)
- **SQL Injection**: Parameterized queries kullanılır
- **XSS**: Input sanitization yapılır
- **CSRF**: Token tabanlı koruma

## 5.7 Ölçeklenebilirlik Stratejisi

### 5.7.1 Yatay Ölçeklenebilirlik

- Her servis bağımsız olarak ölçeklendirilebilir
- Stateless servisler (session bilgisi Redis'te)
- Load balancer ile yük dağıtımı

### 5.7.2 Veritabanı Ölçeklenebilirliği

- **Read Replicas**: Okuma işlemleri için replica kullanımı
- **Sharding**: Yüksek veri hacmi için sharding stratejisi
- **Caching**: Redis ile sık kullanılan verilerin cache'lenmesi

### 5.7.3 Mesajlaşma Ölçeklenebilirliği

- RabbitMQ cluster yapısı
- Queue'lar birden fazla consumer ile tüketilebilir
- Message persistence ile veri kaybı önlenir

### 5.7.4 WebSocket Ölçeklenebilirliği

- WebSocket Gateway birden fazla instance olabilir
- Bağlantı durumları Redis'te saklanır (shared state)
- Sticky session veya message broadcasting kullanılabilir

## 5.8 Hata Yönetimi ve Dayanıklılık

### 5.8.1 Circuit Breaker Pattern

- Servisler arası çağrılarda circuit breaker kullanılır
- Bir servis çöktüğünde, çağrılar durdurulur
- Fallback mekanizmaları tanımlanabilir

### 5.8.2 Retry Mekanizması

- Geçici hatalar için retry mekanizması
- Exponential backoff stratejisi
- Maksimum retry sayısı sınırlandırılır

### 5.8.3 Hata Loglama

- Merkezi loglama sistemi (ELK Stack - Elasticsearch, Logstash, Kibana)
- Structured logging (JSON format)
- Log seviyeleri: DEBUG, INFO, WARN, ERROR

### 5.8.4 Health Checks

- Her servis health check endpoint'i sağlar (`/health`)
- API Gateway health check'leri düzenli olarak yapar
- Unhealthy servisler load balancer'dan çıkarılır

## 5.9 Teknoloji Stack Seçimleri

### 5.9.1 Backend Framework

**Seçenekler:**
- **Node.js (Express)**: JavaScript ekosistemi, WebSocket desteği
- **Python (FastAPI)**: Hızlı geliştirme, async desteği
- **Java (Spring Boot)**: Kurumsal uygulamalar, olgun ekosistem

**Seçim:** Node.js (Express) - WebSocket desteği ve JavaScript ekosistemi nedeniyle

### 5.9.2 Veritabanları

- **PostgreSQL**: User Service, File Service (ilişkisel veriler)
- **MongoDB**: Chat Service, Message Service, Notification Service (doküman tabanlı)

### 5.9.3 Message Queue

- **RabbitMQ**: Olgun, güvenilir, kolay yönetilebilir

### 5.9.4 Cache

- **Redis**: Hızlı, yaygın kullanılan, çoklu veri yapısı desteği

### 5.9.5 Containerization

- **Docker**: Servis containerization
- **Docker Compose**: Geliştirme ortamı için orchestration

### 5.9.6 API Gateway

- **Nginx**: Yüksek performans, yaygın kullanım
- Alternatif: Kong API Gateway (API yönetimi özellikleri)

### 5.9.7 Frontend

- Basit HTML/JavaScript veya React
- WebSocket istemcisi (Socket.io client)

## 5.10 Monitoring ve Observability

### 5.10.1 Logging

- Merkezi loglama: ELK Stack (Elasticsearch, Logstash, Kibana)
- Structured logging: JSON format
- Log correlation: Request ID ile log izleme

### 5.10.2 Metrics

- **Prometheus**: Metrik toplama
- **Grafana**: Metrik görselleştirme
- Metrikler: CPU, memory, request rate, error rate, response time

### 5.10.3 Distributed Tracing

- **Jaeger** veya **Zipkin**: Request tracing
- Servisler arası çağrıları izleme
- Performans analizi

### 5.10.4 Alerting

- Kritik hatalar için alerting
- Sistem sağlığı metrikleri için threshold'lar
- Email/Slack bildirimleri

## 5.11 Deployment Stratejisi

### 5.11.1 Containerization

- Her servis Docker container olarak paketlenir
- Dockerfile her servis için ayrı ayrı oluşturulur
- Multi-stage build ile optimizasyon

### 5.11.2 Orchestration

- **Geliştirme**: Docker Compose
- **Production**: Kubernetes (isteğe bağlı) veya Docker Swarm

### 5.11.3 CI/CD

- Git repository'den otomatik build
- Test otomasyonu
- Otomatik deployment (staging/production)

### 5.11.4 Environment Configuration

- Environment variables ile konfigürasyon
- Farklı environment'lar için farklı config dosyaları
- Secrets management (HashiCorp Vault veya benzeri)

## 5.12 Mimari Kararlar ve Gerekçeleri

### 5.12.1 Mikroservis Mimarisi Seçimi

**Gerekçe:**
- Ölçeklenebilirlik: Her servis bağımsız ölçeklenebilir
- Teknoloji çeşitliliği: Her servis için en uygun teknoloji seçilebilir
- Takım bağımsızlığı: Farklı takımlar farklı servisler üzerinde çalışabilir
- Hata izolasyonu: Bir servisin çökmesi diğerlerini etkilemez

### 5.12.2 Database per Service

**Gerekçe:**
- Servis bağımsızlığı
- Veritabanı teknolojisi seçiminde esneklik
- Ölçeklenebilirlik (her veritabanı ayrı ölçeklenebilir)

**Zorluklar:**
- Servisler arası veri tutarlılığı (eventual consistency kabul edilir)
- Distributed transaction yok (bu kabul edilir)

### 5.12.3 Event-Driven Architecture

**Gerekçe:**
- Loose coupling: Servisler birbirinden bağımsız
- Asenkron işlemler: Yüksek performans
- Ölçeklenebilirlik: Birden fazla consumer

### 5.12.4 API Gateway Pattern

**Gerekçe:**
- Merkezi yönetim: Tüm istekler tek noktadan yönetilir
- Kimlik doğrulama: Tek bir yerde yapılır
- Rate limiting: Merkezi olarak uygulanır
- Request routing: Basit ve merkezi

## 5.13 Sistem Mimarisi Özeti

Sistem, 5 mikroservis ve destekleyici altyapı bileşenlerinden oluşmaktadır. Her servis bağımsız olarak geliştirilir, test edilir ve dağıtılır. Servisler arası iletişim REST API ve message queue (RabbitMQ) üzerinden gerçekleşir. Gerçek zamanlı bildirimler WebSocket Gateway üzerinden sağlanır. Sistem, yatay ölçeklenebilirlik, hata toleransı ve yüksek performans için tasarlanmıştır.

