# 1. Konu Tanımı ve Senaryolar

## 1.1 Proje Amacı

Bu proje, gerçek zamanlı sohbet uygulaması için mikroservis mimarisine dayalı bir yazılım sistemi geliştirmeyi amaçlamaktadır. Sistem, birebir ve grup sohbet özelliklerini destekleyen, dosya paylaşımı yapabilen, gerçek zamanlı mesajlaşma sağlayan ölçeklenebilir bir mimari üzerine kurulmuştur.

## 1.2 Proje Kapsamı

Proje, aşağıdaki temel işlevleri kapsamaktadır:

- Kullanıcı yönetimi ve kimlik doğrulama
- Birebir ve grup sohbet oluşturma
- Gerçek zamanlı mesajlaşma
- Mesaj geçmişi saklama ve görüntüleme
- Dosya ve medya paylaşımı
- Gerçek zamanlı bildirimler

Sistem en az 5 mikroservis içermektedir ve bu servisler bağımsız olarak geliştirilebilir, dağıtılabilir ve ölçeklendirilebilir şekilde tasarlanmıştır.

## 1.3 Kullanıcı Senaryoları (User Stories)

### 1.3.1 Kullanıcı Yönetimi

**US-1: Kullanıcı Kaydı**
- Bir kullanıcı olarak, sisteme kayıt olabilmeliyim (e-posta, kullanıcı adı, şifre ile)
- Sistem, e-posta benzersizliğini kontrol etmeli
- Kayıt sonrası kullanıcı doğrulama e-postası gönderilmeli

**US-2: Kullanıcı Girişi**
- Bir kullanıcı olarak, kayıtlı hesabımla giriş yapabilmeliyim
- Sistem, kimlik bilgilerimi doğrulamalı ve oturum açmalı
- Oturum token'ı döndürülmeli

**US-3: Profil Yönetimi**
- Bir kullanıcı olarak, profil bilgilerimi görüntüleyebilmeliyim
- Profil bilgilerimi (ad, soyad, profil resmi, durum mesajı) güncelleyebilmeliyim

### 1.3.2 Sohbet Yönetimi

**US-4: Birebir Sohbet Oluşturma**
- Bir kullanıcı olarak, başka bir kullanıcı ile birebir sohbet başlatabilmeliyim
- Sistem, aynı kullanıcılarla mevcut sohbeti varsa yeniden oluşturmamalı

**US-5: Grup Sohbeti Oluşturma**
- Bir kullanıcı olarak, birden fazla kullanıcı ile grup sohbeti oluşturabilmeliyim
- Grup sohbetine katılımcı ekleyip çıkarabilmeliyim
- Grup sohbetine isim verebilmeliyim

**US-6: Sohbet Listesi Görüntüleme**
- Bir kullanıcı olarak, katıldığım tüm sohbetleri görebilmeliyim
- Sohbet listesi son mesaj ve zaman bilgisiyle sıralanmalı

### 1.3.3 Mesajlaşma

**US-7: Mesaj Gönderme**
- Bir kullanıcı olarak, sohbete metin mesajı gönderebilmeliyim
- Gönderilen mesaj, sohbetteki diğer kullanıcılara gerçek zamanlı olarak iletilebilmelidir
- Mesaj gönderildi/iletildi/okundu durumlarını görebilmeliyim

**US-8: Mesaj Geçmişi**
- Bir kullanıcı olarak, sohbetin mesaj geçmişini görüntüleyebilmeliyim
- Mesaj geçmişi sayfalama (pagination) ile yüklenebilmelidir

**US-9: Mesaj Silme**
- Bir kullanıcı olarak, gönderdiğim mesajları silebilmeliyim
- Silinen mesaj, sohbetteki diğer kullanıcılara "bu mesaj silindi" şeklinde görünmelidir

### 1.3.4 Dosya Paylaşımı

**US-10: Dosya Yükleme**
- Bir kullanıcı olarak, sohbete dosya (resim, video, doküman) yükleyebilmeliyim
- Sistem, dosya türünü ve boyutunu kontrol etmeli
- Yüklenen dosya için bir URL oluşturulmalı

**US-11: Dosya İndirme**
- Bir kullanıcı olarak, sohbette paylaşılan dosyaları indirebilmeliyim
- Dosya URL'leri güvenli ve zaman sınırlı olmalıdır

### 1.3.5 Bildirimler

**US-12: Gerçek Zamanlı Bildirimler**
- Bir kullanıcı olarak, yeni mesaj aldığımda gerçek zamanlı bildirim alabilmeliyim
- Bildirimler, çevrimiçi kullanıcılara anında ulaşabilmelidir
- Bildirimler, çevrimdışı kullanıcılar için kuyrukta saklanabilmelidir

## 1.4 Ana Kullanım Akışları

### 1.4.1 Kullanıcı Kayıt ve Giriş Akışı

```
1. Kullanıcı kayıt sayfasına girer
2. E-posta, kullanıcı adı ve şifre bilgilerini girer
3. Sistem kayıt bilgilerini doğrular ve kullanıcıyı oluşturur
4. Doğrulama e-postası gönderilir
5. Kullanıcı e-postasını doğrular
6. Kullanıcı giriş sayfasından e-posta ve şifre ile giriş yapar
7. Sistem kimlik bilgilerini doğrular
8. Oturum token'ı oluşturulur ve kullanıcıya döndürülür
9. Kullanıcı ana sayfaya yönlendirilir
```

### 1.4.2 Mesaj Gönderme Akışı

```
1. Kullanıcı bir sohbet seçer
2. Mesaj yazma alanına metin girer
3. Mesajı gönder butonuna tıklar
4. İstemci, mesajı Message Service'e gönderir
5. Message Service mesajı doğrular ve veritabanına kaydeder
6. Message Service, Notification Service'e bildirim gönderir
7. Notification Service, sohbetteki diğer kullanıcılara WebSocket üzerinden bildirim gönderir
8. Çevrimiçi kullanıcılar mesajı gerçek zamanlı olarak görür
9. Çevrimdışı kullanıcılar için bildirim kuyrukta saklanır
```

### 1.4.3 Dosya Paylaşımı Akışı

```
1. Kullanıcı sohbet içinde dosya ekle butonuna tıklar
2. Dosya seçer (resim, video, doküman)
3. İstemci, dosyayı File Service'e yükler
4. File Service dosyayı doğrular (tür, boyut kontrolü)
5. File Service dosyayı depolama sistemine kaydeder
6. File Service dosya URL'ini döndürür
7. İstemci, dosya URL'ini içeren bir mesaj oluşturur
8. Mesaj normal mesaj gönderme akışı ile gönderilir
9. Alıcılar dosyayı görüntüleyebilir veya indirebilir
```

### 1.4.4 Grup Sohbeti Oluşturma Akışı

```
1. Kullanıcı "Yeni Grup" butonuna tıklar
2. Grup adını girer ve katılımcıları seçer
3. Chat Service'e grup oluşturma isteği gönderilir
4. Chat Service grubu oluşturur ve veritabanına kaydeder
5. Chat Service, seçilen kullanıcılara grup davet bildirimi gönderir
6. Bildirimler Notification Service üzerinden gönderilir
7. Grup sohbeti oluşturulur ve kullanıcılar sohbet listesinde görür
```

