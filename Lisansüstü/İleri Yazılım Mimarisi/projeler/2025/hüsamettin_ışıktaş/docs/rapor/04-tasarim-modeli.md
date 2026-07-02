# 4. Tasarım Modeli

## 4.1 Genel Bakış

Tasarım modeli, sistemin teknik mimarisini ve bileşenlerini detaylandırır. Bu model, mikroservis mimarisine dayalı sistemin yapısal tasarımını ve servisler arası etkileşimleri tanımlar.

## 4.2 Component Diagram (Bileşen Diyagramı)

Component diagram, sistemin yazılım bileşenlerini ve aralarındaki bağımlılıkları gösterir. Sistem aşağıdaki ana bileşenlerden oluşmaktadır:

**Mikroservisler:**
1. User Service
2. Chat Service
3. Message Service
4. Notification Service
5. File Service

**Altyapı Bileşenleri:**
- API Gateway
- WebSocket Gateway
- Message Queue (RabbitMQ)
- Cache (Redis)
- Databases (MongoDB/PostgreSQL)

Her servis bağımsız bir bileşen olarak modellenmiş ve kendi veritabanına sahiptir. Servisler arası iletişim REST API ve message queue üzerinden gerçekleşir.

Detaylı Component Diagram için `tasarim/tasarim-diagramlari/component-diagram.puml` dosyasına bakınız.

## 4.3 Sequence Diagram (Sıralama Diyagramı)

Sequence diagram, servisler arasındaki mesajlaşma akışını zaman sırasına göre gösterir. Aşağıdaki kritik senaryolar modellenmiştir:

1. **Mesaj Gönderme Senaryosu**: Client → API Gateway → Message Service → Notification Service → WebSocket Gateway → Client
2. **Dosya Yükleme Senaryosu**: Client → API Gateway → File Service → Message Service
3. **Kullanıcı Kayıt Senaryosu**: Client → API Gateway → User Service
4. **Grup Sohbeti Oluşturma Senaryosu**: Client → API Gateway → Chat Service → Notification Service

Her sequence diagram, sistemin farklı senaryolardaki davranışını ve servisler arası etkileşimi gösterir.

Detaylı Sequence Diagram için `tasarim/tasarim-diagramlari/sequence-diagram.puml` dosyasına bakınız.

## 4.4 Class Diagram (Sınıf Diyagramı)

Class diagram, her mikroservisin iç yapısını ve sınıf ilişkilerini gösterir. Her servis için ana sınıflar modellenmiştir:

**User Service Sınıfları:**
- UserController
- UserService
- User (Model/Entity)

**Chat Service Sınıfları:**
- ChatController
- ChatService
- Chat (Model/Entity)
- ChatParticipant (Embedded in Chat)

**Message Service Sınıfları:**
- MessageController
- MessageService
- Message (Model/Entity)

**Notification Service Sınıfları:**
- NotificationController
- NotificationService
- Notification (Model/Entity)
- WebSocketGatewayClient (HTTP Client)

**File Service Sınıfları:**
- FileController
- FileService
- File (Model/Entity)
- StorageService

**Not:** Her serviste veri erişimi için ayrı bir Repository katmanı yerine, Model sınıfları direkt olarak Service katmanından kullanılmaktadır. Bu yaklaşım, basitlik ve performans açısından tercih edilmiştir. Model sınıfları (Mongoose için Mongoose model, PostgreSQL için static metodlar içeren model sınıfları) veritabanı işlemlerini doğrudan yönetir.

Her sınıf diagramı, servis içi mimariyi ve sorumlulukların dağılımını gösterir.

Detaylı Class Diagram için `tasarim/tasarim-diagramlari/class-diagram.puml` dosyasına bakınız.

## 4.5 Deployment Diagram (Dağıtım Diyagramı)

Deployment diagram, sistemin fiziksel dağıtımını ve altyapı bileşenlerini gösterir. Sistem aşağıdaki düğümlerde (nodes) çalışır:

**Container Düğümleri:**
- API Gateway Container
- WebSocket Gateway Container
- User Service Container
- Chat Service Container
- Message Service Container
- Notification Service Container
- File Service Container

**Altyapı Düğümleri:**
- Message Queue Node (RabbitMQ)
- Cache Node (Redis)
- Database Nodes (MongoDB/PostgreSQL)
- Storage Node (File Storage)

Her düğüm, containerization (Docker) ile yönetilir ve orchestration (Docker Compose/Kubernetes) ile koordine edilir.

Detaylı Deployment Diagram için `tasarim/tasarim-diagramlari/deployment-diagram.puml` dosyasına bakınız.

## 4.6 Tasarım Prensipleri

### 4.6.1 Mikroservis Prensipleri

- **Bağımsız Dağıtılabilirlik**: Her servis bağımsız olarak dağıtılabilir
- **Tek Sorumluluk**: Her servis belirli bir iş alanından sorumludur
- **Veritabanı Ayrımı**: Her servis kendi veritabanına sahiptir
- **API Tabanlı İletişim**: Servisler REST API ve message queue ile iletişim kurar

### 4.6.2 Tasarım Desenleri

- **API Gateway Pattern**: Tüm dış istekler API Gateway üzerinden yönlendirilir
- **Service Discovery**: Servisler birbirlerini bulmak için service registry kullanır
- **Circuit Breaker**: Servis hatalarına karşı dayanıklılık sağlar
- **Event-Driven Architecture**: Asenkron işlemler için message queue kullanılır
- **CQRS (Command Query Responsibility Segregation)**: Okuma ve yazma işlemleri ayrılabilir

## 4.7 Tasarım Modeli Değerlendirmesi

Tasarım modeli, mikroservis mimarisinin temel prensiplerini yansıtır. Component diagram sistemin yapısal görünümünü, sequence diagram davranışsal görünümünü, class diagram servis içi yapıyı ve deployment diagram fiziksel görünümü sağlar. Bu modeller birlikte, sistemin kapsamlı bir teknik görünümünü sunar.

