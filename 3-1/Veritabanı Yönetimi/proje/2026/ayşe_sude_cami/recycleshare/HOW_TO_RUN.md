# RecycleShare (47.zip) Çalıştırma Talimatları

Bu proje `47.zip` arşivinden çıkarıldıktan sonra aşağıdaki adımlarla çalıştırılabilir.

## Gereksinimler
- **Node.js** (v18 veya üzeri)
- **PostgreSQL** (Yerel kurulum)

## Kurulum Adımları

### 1. Dosyaları Çıkartın
`47.zip` dosyasını bir klasöre çıkartın.
```bash
unzip 47.zip
cd 47
```

### 2. Backend Kurulumu ve Başlatma
Terminali açın ve `backend` klasörüne gidin:
```bash
cd backend
npm install
```

**Veritabanını Oluştur ve Sunucuyu Başlat:**
Lokal veritabanı ile hızlıca başlamak için şu komutu kullanın (PostgreSQL'in kurulu olması gerekir):
```bash
npm run dev:local
```
*Bu komut `recycleshare` adında bir veritabanı oluşturur, şemayı yükler ve sunucuyu 5001 portunda başlatır.*

*(Eğer `dev:local` hata verirse veya kendi bağlantı adresinizi kullanmak isterseniz `.env` dosyasını düzenleyip `npm run dev` komutunu kullanabilirsiniz.)*

### 3. Frontend Kurulumu ve Başlatma
Yeni bir terminal sekmesi açın ve `frontend` klasörüne gidin:
```bash
cd ../frontend
npm install
npm run dev
```
*Bu komut frontend uygulamasını genellikle `http://localhost:5173` adresinde başlatır.*

### 4. Uygulamayı Kullanma
Tarayıcınızı açın ve aşağıdaki adrese gidin:
**http://localhost:5173**

Kayıt olabilir veya veritabanında tanımlı test kullanıcıları ile giriş yapabilirsiniz.

---
**Not:** Backend terminalinde `✅ Full database schema initialized` mesajını gördüğünüzden emin olun.
