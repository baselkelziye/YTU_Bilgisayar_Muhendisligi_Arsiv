# Craft-Mart

Bu proje, kullanıcıların el yapımı ürünleri listeleyip satın alabileceği bir Flask tabanlı web uygulamasıdır. PostgreSQL kullanarak ürün, kullanıcı ve sipariş verilerini yönetir.

## Özellikler
- Ürün ekleme, düzenleme, silme (sadece satıcıya izin)
- Ürünlere yorum ve puan ekleme
- Sepete ekleme, sepeti görüntüleme, siparişe dönüştürme
- Satış istatistikleri ve temel analiz ekranları
- Kullanıcı ve kategori yönetimi

## Kurulum
1. Python 3 ve PostgreSQL kurulu olduğundan emin olun.  
2. Depoyu klonlayın veya ZIP olarak indirin.
    ```bash
   git clone https://github.com/ahmetsefacetin/Craft-Mart
3. Sanal ortam oluşturup etkinleştirin:
   ```bash
   python -m venv venv
   venv\Scripts\activate  # Windows
4. config.py içindeki veritabanı bilgilerini güncelleyin.
5. database/first.sql ve diğer sql dosyalarındaki tabloları ve verileri PostgreSQL'e aktarın

## Kullanım
1. Uygulamayı başlatmak için:
    ```bash
   python app.py
2. Tarayıcıdan http://localhost:5000 adresine gidin.
3. Üye olun veya giriş yaparak ürünleri inceleyin.