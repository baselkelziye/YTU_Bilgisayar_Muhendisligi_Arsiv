# 3. Analiz Modeli

## 3.1 Genel Bakış

Analiz modeli, sistemin iş mantığını ve kullanıcı etkileşimlerini anlamak için oluşturulmuştur. Bu model, sistem gereksinimlerini görselleştirmek ve sistemin davranışını tanımlamak için UML diyagramları kullanmaktadır.

## 3.2 Use Case Diagram

Use Case diyagramı, sistemin aktörleri (kullanıcılar) ve sistemle olan etkileşimlerini (use case'ler) gösterir. Diyagram aşağıdaki ana use case'leri içermektedir:

**Aktörler:**
- Authenticated User (Kimlik Doğrulanmış Kullanıcı)

**Ana Use Case'ler:**
1. Kayıt Ol
2. Giriş Yap
3. Profil Yönetimi
4. Birebir Sohbet Oluştur
5. Grup Sohbeti Oluştur
6. Sohbet Listesi Görüntüle
7. Mesaj Gönder
8. Mesaj Geçmişi Görüntüle
9. Mesaj Sil
10. Dosya Yükle
11. Dosya İndir
12. Bildirim Al

Detaylı Use Case Diagram için `tasarim/analiz-diagramlari/use-case-diagram.puml` dosyasına bakınız.

## 3.3 Domain Model (Etki Alanı Modeli)

Domain model, sistemin temel iş varlıklarını (entities) ve aralarındaki ilişkileri gösterir. Sistemin ana varlıkları şunlardır:

**Ana Varlıklar:**

1. **User (Kullanıcı)**
   - id: String
   - email: String
   - username: String
   - passwordHash: String
   - firstName: String
   - lastName: String
   - profilePicture: String
   - statusMessage: String
   - createdAt: DateTime
   - updatedAt: DateTime

2. **Chat (Sohbet)**
   - id: String
   - type: Enum (DIRECT, GROUP)
   - name: String (grup sohbetleri için)
   - createdBy: String (User ID)
   - createdAt: DateTime
   - updatedAt: DateTime

3. **ChatParticipant (Sohbet Katılımcısı)**
   - id: String
   - chatId: String
   - userId: String
   - role: Enum (MEMBER, ADMIN)
   - joinedAt: DateTime

4. **Message (Mesaj)**
   - id: String
   - chatId: String
   - senderId: String (User ID)
   - content: String
   - messageType: Enum (TEXT, FILE, IMAGE, VIDEO)
   - fileUrl: String (dosya mesajları için)
   - status: Enum (SENT, DELIVERED, READ, DELETED)
   - createdAt: DateTime
   - updatedAt: DateTime

5. **File (Dosya)**
   - id: String
   - originalName: String
   - storedName: String
   - mimeType: String
   - size: Long
   - url: String
   - uploadedBy: String (User ID)
   - createdAt: DateTime

6. **Notification (Bildirim)**
   - id: String
   - userId: String
   - type: Enum (MESSAGE, FILE, CHAT_INVITE)
   - title: String
   - body: String
   - data: JSON
   - read: Boolean
   - createdAt: DateTime

**Varlık İlişkileri:**

- User 1..* ChatParticipant: Bir kullanıcı birden fazla sohbete katılabilir
- Chat 1..* ChatParticipant: Bir sohbet birden fazla katılımcıya sahip olabilir
- Chat 1..* Message: Bir sohbet birden fazla mesaja sahip olabilir
- User 1..* Message: Bir kullanıcı birden fazla mesaj gönderebilir
- User 1..* File: Bir kullanıcı birden fazla dosya yükleyebilir
- User 1..* Notification: Bir kullanıcı birden fazla bildirim alabilir
- Message 0..1 File: Bir mesaj sıfır veya bir dosyaya referans verebilir

Detaylı Domain Model Diagram için `tasarim/analiz-diagramlari/domain-model.puml` dosyasına bakınız.

## 3.4 Activity Diagram

Activity diagram, sistem içindeki iş akışlarını gösterir. Aşağıdaki ana akışlar modellenmiştir:

1. **Kullanıcı Kayıt Akışı**: Kullanıcı kayıt sürecini gösterir
2. **Mesaj Gönderme Akışı**: Mesaj gönderme sürecini gösterir
3. **Dosya Paylaşımı Akışı**: Dosya yükleme ve paylaşma sürecini gösterir
4. **Grup Sohbeti Oluşturma Akışı**: Grup sohbeti oluşturma sürecini gösterir

Her activity diagram, sürecin adımlarını, karar noktalarını ve paralel aktiviteleri gösterir.

Detaylı Activity Diagram için `tasarim/analiz-diagramlari/activity-diagram.puml` dosyasına bakınız.

## 3.5 Analiz Modeli Değerlendirmesi

Analiz modeli, sistemin iş mantığını ve kullanıcı gereksinimlerini kapsamlı bir şekilde modeller. Use Case diagram, sistemin tüm işlevlerini görselleştirirken, Domain Model temel varlıkları ve ilişkilerini tanımlar. Activity Diagram ise kritik iş akışlarının detaylı açıklamasını sağlar.

Bu model, sistemin tasarım aşamasında referans alınacak temel dokümantasyonu oluşturur ve geliştirme sürecinde gereksinimlerin karşılandığını doğrulamak için kullanılabilir.

