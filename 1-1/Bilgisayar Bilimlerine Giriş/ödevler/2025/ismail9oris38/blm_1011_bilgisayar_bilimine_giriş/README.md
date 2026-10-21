# 🎲 Triversi Oyunu - Reversi'nin Üç Kişilik Versiyonu

Bu depo, Reversi oyununun üç kişilik versiyonu olan Triversi'nin C programlama dilinde geliştirilmiş bir uygulamasını içermektedir. Proje, kullanıcıdan alınan NxN boyutunda dinamik bir oyun tahtası üzerinde oynanır ve "Kırmızı", "Sarı" ve "Mavi" renkli taşlarla stratejik hamleler yapma imkanı sunar.

## 🎯 Proje Amacı

Bu projenin temel amacı, temel programlama prensipleri, matris işlemleri ve oyun mantığı geliştirme becerilerini kullanarak Reversi gibi karmaşık bir strateji oyununu yeniden tasarlamak ve uygulamaktır. Özellikle, üç farklı oyuncu için dinamik tahta boyutu ve özel taş çevirme mekaniği üzerinde durulmuştur.

## ✨ Temel Özellikler

* **Üç Kişilik Oyun:** Kırmızı (K), Sarı (S) ve Mavi (M) olmak üzere üç farklı oyuncu ile oynanır.
* **Dinamik Tahta Boyutu:** Oyun tahtası boyutu (NxN) kullanıcıdan alınır (maksimum 23x23 boyut önerilir).
* **Stratejik Taş Yerleştirme:** Oyuncular, yatay, dikey veya çapraz olarak kendi renklerinden başka bir taşı "sıkıştırarak" aradaki rakip taşlarını kendi renklerine çevirir.
* **Oyun Sonu ve Puanlama:** Tüm tahta dolduğunda oyun sona erer ve her renkten kaçar taş olduğu sayılarak kazanan oyuncu veya beraberlik durumu belirlenir.
* **C Programlama Dili:** Proje tamamen C dilinde geliştirilmiştir.

## 💻 Geliştirme Dili

Proje, tamamıyla **C programlama dili** kullanılarak geliştirilmiştir.

---


## 🚀 Kullanım Talimatları

1.  `src` klasöründeki `Triversi_Oyunu.c` dosyasını bir C derleyicisi (örn. GCC) ile derleyin:
    ```bash
    gcc src/Triversi_Oyunu.c -o triversi_game
    ```
2.  Derlenen çalıştırılabilir dosyayı çalıştırın:
    ```bash
    ./triversi_game
    ```
3.  Program, oyun tahtasının boyutunu girmenizi isteyecek ve ardından oyuncuların sırasıyla hamle yapmasını bekleyecektir.

---

## 🎓 Akademik Bilgiler

* **Ders Projesi:** BLM1011 Bilgisayar Bilimine Giriş (Yıldız Teknik Üniversitesi) 🎓

---

## 📹 Video Açıklaması

Projenin detaylı video açıklaması ve uygulamalı gösterimi için aşağıdaki linki ziyaret edebilirsiniz:

[Proje Video Anlatımı](https://drive.google.com/file/d/13vtdwHTJiP3Suw3eUBOXKi_i1mX2I48w/view?usp=sharing) 🎬

---

## 📄 Dönem Projesi Raporu

Projenin detaylı raporuna ve teknik açıklamalarına aşağıdaki PDF dosyasından ulaşabilirsiniz:

[Dönem Projesi Raporu (PDF)](docs/Triversi_Game_Raport.pdf)

---

## 🧑‍🎓 Geliştirici Bilgileri

* **Adı Soyadı:** İsmail Orhan
* **Öğrenci Numarası:** 23011081
* **E-posta:** ismail.orhan@std.yildiz.edu.tr 📧
* **Kurum:** Yıldız Teknik Üniversitesi, Bilgisayar Mühendisliği Bölümü 🏢
