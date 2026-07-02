# 2. Gereksinimler

## 2.1 İşlevsel Gereksinimler (Functional Requirements)

### 2.1.1 Kullanıcı Yönetimi Gereksinimleri

**FR-1.1: Kullanıcı Kayıt**
- Sistem, yeni kullanıcıların kayıt olmasına izin vermelidir
- Kayıt sırasında e-posta, kullanıcı adı ve şifre bilgileri toplanmalıdır
- E-posta adresinin benzersizliği kontrol edilmelidir
- Şifre en az 8 karakter olmalı ve güçlü şifre kurallarına uymalıdır
- Kayıt sonrası kullanıcıya doğrulama e-postası gönderilmelidir

**FR-1.2: Kullanıcı Doğrulama ve Giriş**
- Sistem, kullanıcıların e-posta ve şifre ile giriş yapmasına izin vermelidir
- Giriş başarılı olduğunda JWT token oluşturulmalıdır
- Token'ın geçerlilik süresi belirlenmelidir (örn: 24 saat)
- Giriş başarısız olduğunda uygun hata mesajı döndürülmelidir

**FR-1.3: Profil Yönetimi**
- Kullanıcılar profil bilgilerini (ad, soyad, profil resmi, durum mesajı) görüntüleyebilmelidir
- Kullanıcılar profil bilgilerini güncelleyebilmelidir
- Profil resmi yükleme ve güncelleme desteklenmelidir

### 2.1.2 Sohbet Yönetimi Gereksinimleri

**FR-2.1: Birebir Sohbet**
- Kullanıcılar, diğer kullanıcılarla birebir sohbet başlatabilmelidir
- Sistem, aynı iki kullanıcı arasında mevcut sohbet varsa yeni sohbet oluşturmamalıdır
- Birebir sohbetlerde sadece 2 kullanıcı bulunmalıdır

**FR-2.2: Grup Sohbeti**
- Kullanıcılar, birden fazla kullanıcı ile grup sohbeti oluşturabilmelidir
- Grup sohbetine grup adı verilebilmelidir
- Grup sohbetine katılımcı eklenebilmelidir
- Grup sohbetinden katılımcı çıkarılabilmelidir
- Grup sohbetinin oluşturucusu belirlenmelidir

**FR-2.3: Sohbet Listesi**
- Kullanıcılar, katıldıkları tüm sohbetleri görebilmelidir
- Sohbet listesi, son mesaj zamanına göre sıralanmalıdır
- Her sohbet için son mesaj önizlemesi gösterilmelidir
- Okunmamış mesaj sayısı gösterilmelidir

### 2.1.3 Mesajlaşma Gereksinimleri

**FR-3.1: Mesaj Gönderme**
- Kullanıcılar, sohbete metin mesajı gönderebilmelidir
- Mesajlar maksimum 5000 karakter olabilmelidir
- Mesajlar gerçek zamanlı olarak alıcılara iletilebilmelidir
- Mesaj gönderildi/iletildi/okundu durumları takip edilmelidir

**FR-3.2: Mesaj Geçmişi**
- Kullanıcılar, sohbetin mesaj geçmişini görüntüleyebilmelidir
- Mesaj geçmişi sayfalama (pagination) ile yüklenebilmelidir
- Sayfa başına varsayılan 50 mesaj gösterilmelidir
- Mesajlar kronolojik sırada gösterilmelidir

**FR-3.3: Mesaj Silme**
- Kullanıcılar, gönderdikleri mesajları silebilmelidir
- Silinen mesaj, diğer kullanıcılara "bu mesaj silindi" olarak görünmelidir
- Mesaj veritabanından fiziksel olarak silinmemelidir, silindi olarak işaretlenmelidir

**FR-3.4: Mesaj Durumu**
- Mesaj durumları: gönderildi (sent), iletildi (delivered), okundu (read) olmalıdır
- Mesaj gönderildiğinde durumu "sent" olmalıdır
- Mesaj alıcıya ulaştığında durumu "delivered" olmalıdır
- Mesaj okunduğunda durumu "read" olmalıdır

### 2.1.4 Dosya Paylaşımı Gereksinimleri

**FR-4.1: Dosya Yükleme**
- Kullanıcılar, sohbete dosya yükleyebilmelidir
- Desteklenen dosya türleri: resim (JPEG, PNG, GIF), video (MP4, AVI), doküman (PDF, DOC, DOCX)
- Maksimum dosya boyutu 50 MB olmalıdır
- Dosya yüklendikten sonra bir URL oluşturulmalıdır

**FR-4.2: Dosya İndirme**
- Kullanıcılar, paylaşılan dosyaları indirebilmelidir
- Dosya URL'leri güvenli olmalı ve zaman sınırlı erişim sağlamalıdır
- Dosya URL'leri 24 saat geçerli olmalıdır

**FR-4.3: Dosya Önizleme**
- Resim dosyaları sohbet içinde önizlenebilmelidir
- Video dosyaları için oynatıcı entegrasyonu sağlanmalıdır

### 2.1.5 Bildirim Gereksinimleri

**FR-5.1: Gerçek Zamanlı Bildirimler**
- Yeni mesaj alındığında çevrimiçi kullanıcılara anında bildirim gönderilmelidir
- Bildirimler WebSocket üzerinden iletilmelidir
- Bildirimler, kullanıcı mesajı okuduğunda durdurulmalıdır

**FR-5.2: Çevrimdışı Bildirimler**
- Çevrimdışı kullanıcılar için bildirimler kuyrukta saklanmalıdır
- Kullanıcı çevrimiçi olduğunda bekleyen bildirimler gönderilmelidir

## 2.2 İşlevsel Olmayan Gereksinimler (Non-Functional Requirements)

### 2.2.1 Performans Gereksinimleri

**NFR-1.1: Yanıt Süresi**
- API isteklerinin %95'i 500 ms içinde yanıtlanmalıdır
- Mesaj gönderme işlemi 200 ms içinde tamamlanmalıdır
- Gerçek zamanlı mesaj iletimi 100 ms içinde yapılmalıdır

**NFR-1.2: İşlem Kapasitesi**
- Sistem, saniyede en az 1000 mesaj işleyebilmelidir
- Aynı anda 10,000 aktif kullanıcıyı destekleyebilmelidir
- Sistem, 100,000 kayıtlı kullanıcıyı destekleyebilmelidir

**NFR-1.3: Veritabanı Performansı**
- Mesaj sorguları 100 ms içinde sonuç döndürmelidir
- Kullanıcı listesi sorguları 200 ms içinde sonuç döndürmelidir

### 2.2.2 Ölçeklenebilirlik Gereksinimleri

**NFR-2.1: Yatay Ölçeklenebilirlik**
- Servisler bağımsız olarak ölçeklendirilebilmelidir
- Yüksek yük durumunda servis örnekleri otomatik olarak artırılabilmelidir
- Her servis en az 3 örnekle çalışabilmelidir

**NFR-2.2: Veri Ölçeklenebilirliği**
- Veritabanı şeması milyonlarca mesajı destekleyebilmelidir
- Mesaj geçmişi için arşivleme stratejisi uygulanmalıdır
- Eski mesajlar ayrı bir depolama sistemine taşınabilmelidir

### 2.2.3 Güvenlik Gereksinimleri

**NFR-3.1: Kimlik Doğrulama ve Yetkilendirme**
- Tüm API istekleri JWT token ile doğrulanmalıdır
- Token'lar şifrelenmiş (encrypted) olmalıdır
- Token yenileme (refresh token) mekanizması olmalıdır
- Şifreler hash'lenmiş (bcrypt) olarak saklanmalıdır

**NFR-3.2: Veri Güvenliği**
- Hassas veriler (şifreler, token'lar) veritabanında şifrelenmiş olarak saklanmalıdır
- API iletişimi HTTPS üzerinden yapılmalıdır
- Dosya erişim URL'leri zaman sınırlı ve token tabanlı olmalıdır

**NFR-3.3: Güvenlik Kontrolleri**
- SQL injection, XSS, CSRF saldırılarına karşı koruma sağlanmalıdır
- Rate limiting uygulanmalıdır (kullanıcı başına dakikada maksimum 60 istek)
- Input validation ve sanitization yapılmalıdır

### 2.2.4 Kullanılabilirlik (Usability) Gereksinimleri

**NFR-4.1: Kullanıcı Arayüzü**
- Basit ve sezgisel bir kullanıcı arayüzü sağlanmalıdır
- Mobil ve masaüstü tarayıcılar desteklenmelidir
- Responsive tasarım uygulanmalıdır

**NFR-4.2: Hata Yönetimi**
- Kullanıcı dostu hata mesajları gösterilmelidir
- Sistem hataları kullanıcıya teknik detaylar vermeden iletilmelidir

### 2.2.5 Dayanıklılık (Reliability) Gereksinimleri

**NFR-5.1: Sistem Uptime**
- Sistem %99.5 uptime sağlamalıdır
- Planlı bakım dışında sistem kesintisiz çalışmalıdır

**NFR-5.2: Hata Toleransı**
- Tek bir servisin çökmesi tüm sistemi etkilememelidir
- Circuit breaker pattern kullanılarak servis hataları yönetilmelidir
- Veritabanı replikasyonu ile veri kaybı önlenmelidir

**NFR-5.3: Veri Bütünlüğü**
- Mesajlar kesinlikle kaybolmamalıdır
- Transaction yönetimi ile veri tutarlılığı sağlanmalıdır
- Asenkron işlemler için idempotency garantisi verilmelidir

### 2.2.6 Bakım Gereksinimleri

**NFR-6.1: Loglama**
- Tüm servisler merkezi loglama sistemine log göndermelidir
- Hata logları, performans metrikleri ve iş mantığı logları tutulmalıdır
- Log seviyeleri (DEBUG, INFO, WARN, ERROR) kullanılmalıdır

**NFR-6.2: İzleme (Monitoring)**
- Sistem sağlığı metrikleri izlenmelidir (CPU, memory, disk kullanımı)
- API yanıt süreleri ve hata oranları izlenmelidir
- Servis bağımlılıkları ve durumları izlenmelidir

**NFR-6.3: Dokümantasyon**
- API dokümantasyonu (OpenAPI/Swagger) sağlanmalıdır
- Servis mimarisi ve veri akışı dokümante edilmelidir

### 2.2.7 Uyumluluk (Compatibility) Gereksinimleri

**NFR-7.1: Tarayıcı Desteği**
- Modern tarayıcılar desteklenmelidir (Chrome, Firefox, Safari, Edge)
- WebSocket desteği olan tarayıcılar gereklidir

**NFR-7.2: API Versiyonlama**
- API versiyonlama stratejisi uygulanmalıdır (örn: /api/v1/)
- Geriye dönük uyumluluk sağlanmalıdır

