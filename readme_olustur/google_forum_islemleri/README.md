# YTU Hocalar Puanlama Sistemi

Bu proje, Yıldız Teknik Üniversitesi'ndeki hocaları puanlamak ve bu puanları yönetmek için kullanılan bir dizi script içermektedir.

## Dosyalar

### hoca_adlari_olustur.py

- **Amaç:** Bu script, `hocalar.json` dosyasında bulunan hoca adlarını çeker ve bu adları Google Formlar'da kullanılmak üzere bir CSV dosyasına kaydeder.
- **Nasıl Çalışır:** `hocalar.json` dosyasını okur, hocaların adlarını alır ve bu adları `hocalar.csv` adlı bir dosyaya kaydeder.
- **Kullanımı:** Scripti çalıştırmak için, `hocalar.json` dosyasının aynı dizinde bulunması gerekmektedir.

### yildizlari_guncelle.py

- **Amaç:** Bu script, Google Formlar'dan alınan hoca puanlama sonuçlarına göre `hocalar.json` dosyasındaki hocaların yıldızlarını (puanlarını) günceller.
- **Nasıl Çalışır:** Google Formlar'dan alınan verileri işler ve hocaların yeni ortalamalarını hesaplar. Ardından, bu yeni ortalamaları `hocalar.json` dosyasında ilgili hocaların kayıtlarını güncelleyerek yansıtır.
- **Kullanımı:** Scripti çalıştırmak için, Google Formlar'dan alınan verilerin bir CSV dosyası olarak erişilebilir olması ve `hocalar.json` dosyasının script ile aynı dizinde bulunması gerekmektedir.

### README.md

- Bu dosya, projenin nasıl kullanılacağı ve her bir dosyanın amacı hakkında bilgi verir.

### hocalar.csv

- `hoca_adlari_olustur.py` scripti tarafından oluşturulan ve hocaların adlarını içeren CSV dosyasıdır. Bu dosya, Google Formlar'da hoca seçimi için kullanılır.

## Nasıl Kullanılır

Projeyi kullanmak için, öncelikle `hoca_adlari_olustur.py` scriptini çalıştırarak `hocalar.csv` dosyasını oluşturun. Ardından, bu CSV dosyasını Google Formlar'da hoca seçimi için kullanabilirsiniz. Puanlama sonuçları toplandıktan sonra, `yildizlari_guncelle.py` scriptini çalıştırarak `hocalar.json` dosyasındaki puanlamaları güncelleyin.
