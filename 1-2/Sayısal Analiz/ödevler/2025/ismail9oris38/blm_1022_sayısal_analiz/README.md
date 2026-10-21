# 📊 BLM1022 - Sayısal Analiz Dönem Projesi

Bu depo, Yıldız Teknik Üniversitesi Bilgisayar Mühendisliği Bölümü'nde, BLM1022 Sayısal Analiz dersi kapsamında geliştirilen dönem projesini içermektedir. Proje, çeşitli bilimsel ve mühendislik problemlerinin çözümünde yaygın olarak kullanılan sayısal metodların C programlama dilinde bir uygulamasını sunmaktadır.

## 🎯 Proje Amacı

Bu projenin temel amacı, Sayısal Analiz dersinde öğrenilen teorik bilgileri pratik uygulamalara dönüştürerek, sayısal metodların çalışma prensiplerini ve uygulama yeteneklerini göstermektir. Kullanıcı dostu bir arayüz ile farklı fonksiyon türlerinin (polinom, üstel, trigonometrik, logaritmik, ters trigonometrik) metodlar tarafından işlenebilmesi sağlanmıştır.

## 🔢 İçerilen Sayısal Metodlar

Proje, aşağıdaki 10 farklı sayısal metodu içermektedir:

1.  **Bisection Yöntemi:** Kök bulma algoritması.
2.  **Regula-Falsi Yöntemi:** Kök bulma algoritması.
3.  **Newton-Raphson Yöntemi:** Kök bulma algoritması.
4.  **NxN'lik Bir Matrisin Tersi:** Kare matrislerin tersini hesaplama.
5.  **Cholesky (ALU) Yöntemi:** Lineer denklem sistemlerini çözme.
6.  **Gauss-Seidel Yöntemi:** Lineer denklem sistemlerini çözme.
7.  **Sayısal Türev:** Merkezi, ileri ve geri farklar yöntemleriyle türev hesaplama.
8.  **Simpson Yöntemi (1/3 ve 3/8):** Sayısal integral hesaplama.
9.  **Trapez Yöntemi:** Sayısal integral hesaplama.
10. **Gregory-Newton Enterpolasyonu:** Verilen noktalar kümesinden enterpolasyon polinomu oluşturma.

## 💻 Geliştirme Dili

Proje, tamamıyla **C programlama dili** kullanılarak geliştirilmiştir.

---


## 🚀 Kullanım Talimatları

1.  `src` klasöründeki `my_numerical_analysis_project.c` dosyasını bir C derleyicisi (örn. GCC) ile derleyin:
    ```bash
    gcc src/my_numerical_analysis_project.c -o numerical_methods -lm
    ```
    (Not: `-lm` parametresi, `math.h` kütüphanesi için matematik fonksiyonlarını bağlamak içindir. Linux/macOS sistemlerinde genellikle gereklidir.)
2.  Derlenen çalıştırılabilir dosyayı çalıştırın:
    ```bash
    ./numerical_methods
    ```
3.  Program, kullanıcıya hangi metodu kullanmak istediğini soracak ve ilgili parametreleri isteyecektir.

---

## 📄 Orijinal Dönem Projesi Raporu

Projenin orijinal dönem projesi raporuna ve metodların daha detaylı akademik açıklamalarına aşağıdaki PDF dosyasından ulaşabilirsiniz:

[Dönem Projesi Raporu (PDF)](docs/numerical_analysis_raport.pdf)

---

## 🧑‍🎓 Geliştirici Bilgileri

* **Adı Soyadı:** İsmail Orhan
* **Öğrenci Numarası:** 23011081
* **E-posta:** ismail.orhan@std.yildiz.edu.tr 📧
* **Kurum:** Yıldız Teknik Üniversitesi, Bilgisayar Mühendisliği Bölümü 🏢
