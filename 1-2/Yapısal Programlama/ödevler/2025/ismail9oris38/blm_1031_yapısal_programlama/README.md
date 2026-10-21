# 📚 Kütüphane Yönetim Sistemi (BLM1031 - Yapısal Programlama Dönem Projesi)

Bu proje, Yıldız Teknik Üniversitesi Bilgisayar Mühendisliği Bölümü'nde, BLM1031 Yapısal Programlama dersi kapsamında geliştirilmiştir. Temel kütüphane operasyonlarını (kitap ekleme, silme, ödünç verme, iade alma, üye yönetimi vb.) otomatikleştirmeyi amaçlayan, C dilinde geliştirilmiş bir yönetim sistemi uygulamasıdır. Proje, veri depolama için CSV dosyalarını kullanmaktadır.

## 🎯 Proje Amacı

Bu projenin temel amacı, Yapısal Programlama dersinde öğrenilen temel programlama prensiplerini ve veri yapılarını (linked listler, struct'lar) gerçek dünya problemine uygulayarak, etkili ve organize kod yazma becerilerini göstermektir. CSV dosyaları aracılığıyla kalıcı veri depolama yeteneği eklenmiştir.

## 🛠️ Temel Özellikler

* **Kitap Yönetimi:** Kitap ekleme, silme, güncelleme ve arama.
* **Üye Yönetimi:** Kütüphane üyelerini (öğrencileri) ekleme, silme, güncelleme ve arama.
* **Ödünç Alma/İade Etme:** Kitapların ödünç verilmesi ve iade alınması süreçlerinin yönetimi.
* **Veri Kalıcılığı:** Tüm veriler (kitaplar, üyeler, ödünç alma kayıtları) CSV formatında dosyalanır ve program kapatılıp açıldığında dahi korunur.
* **Basit Kullanıcı Arayüzü:** Komut satırı tabanlı, anlaşılır bir etkileşim sunar.

## 💻 Geliştirme Dili ve Teknolojiler

* **Programlama Dili:** C
* **Veri Depolama:** CSV Dosyaları (`Kitaplar.csv`, `KitapOdunc.csv`, `KitapOrnekleri.csv`, `KitapYazar.csv`, `Ogrenciler.csv`, `Yazarlar.csv`)

---

## 🚀 Kullanım Talimatları

1.  `src` klasöründeki `library_management_system.c` dosyasını bir C derleyicisi (örn. GCC) ile derleyin:
    ```bash
    gcc src/library_management_system.c -o library_system
    ```
2.  Derlenen çalıştırılabilir dosyayı çalıştırın:
    ```bash
    ./library_system
    ```
3.  Program, menü tabanlı bir arayüz sunacak ve kullanıcıdan kütüphane işlemlerini seçmesini isteyecektir. Verilerin `database/` klasöründe bulunması gerekmektedir.

---

## 📹 Video Açıklaması

Projenin detaylı video açıklaması ve uygulamalı gösterimi için aşağıdaki linki ziyaret edebilirsiniz:

[Proje Video Anlatımı](https://drive.google.com/file/d/1LQXMpWJ8rMWSVNnPU-To4HfVs5EX_c3b/view) 🎬

---

## 📄 Orijinal Dönem Projesi Raporu

Projenin orijinal dönem projesi raporuna ve metodların daha detaylı akademik açıklamalarına aşağıdaki PDF dosyasından ulaşabilirsiniz:

[Dönem Projesi Raporu (PDF)](docs/library_management_system_raport.pdf)

---

## 🧑‍🎓 Geliştirici Bilgileri

* **Adı Soyadı:** İsmail Orhan
* **Öğrenci Numarası:** 23011081
* **E-posta:** ismail.orhan@std.yildiz.edu.tr 📧
* **Kurum:** Yıldız Teknik Üniversitesi, Bilgisayar Mühendisliği Bölümü 🏢
