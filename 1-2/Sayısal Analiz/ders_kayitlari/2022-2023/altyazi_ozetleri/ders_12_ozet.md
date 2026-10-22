# Ders 12 Çalışma Özeti

## Genel Konular

- Bu derste yeni konu işlenmedi. İkinci vizenin olduğu gün ders saati proje gösterimlerine ayrıldı. Kayıt yaklaşık 45 dakikadır.
- Sınav bilgisi: ikinci vize aynı gün saat 16:00'da, 75 dakika. Yanınızda hesap makinesi, kalem ve silgi olsun. Önceki sorulara geri dönülebilir.
- Proje gösterimi nasıl yapılıyor?
  - Öğrenci kaç yöntemi kodladığını söyler. Hoca bunlardan bir ya da ikisini seçer, koda kısaca bakar, kendi verdiği girdiyle çalıştırır ve sonucu kendi elindeki çözümle karşılaştırır.
  - Kamera ve mikrofon açık olmalı. Hoca öğrencinin kim olduğunu görmek istiyor. Sesi ve kamerası olmayan bir öğrencinin sunumu kabul edilmedi, bir sonraki haftaya kaldı ("Olmadı, bunlara sahip bir arkadaşınla birlikte projeni gösterirsin").
  - Sunum yapmak isteyenler önceden e-posta atmalı. Hoca planını buna göre yapıyor. Atmadan gelip bekleyenlere neden yazmadıklarını sordu.
  - Gelecek haftalarda sıra listesi yok. Hoca isim okuyacak, o an olmayan bir sonraki haftaya kalacak.
  - Ders kaydında bağlı görünüp ekran başında olmayan öğrencilere hoca sitem etti.
  - Dersi alttan alıp başka bir dersle çakışan öğrenci önceden yazarsa ilk sıraya alınabilir.
- Rapor
  - Online Yıldız'daki yükleme alanına aynı gün yüklenecek.
  - Raporda hangi yöntemlerin yazıldığını gösteren tablo, bütün kodlar ve derste çalıştırılan yöntemin ekran çıktısı olmalı. Hepsinin ekran çıktısı gerekmiyor.
- Gösterimlerde çalıştırılan örnekler (hocanın kontrol ettiği girdiler)
  - Newton-Raphson: $x^2 - 4x - 5$. $x_0 = 0$ ile kök $-1$, $x_0 = 6$ ile kök $5$ bulundu. Başka bir gösterimde $x^3 + x^2 - 9x - 9$ için kök $-1$ bulundu.
  - Matris tersi (Gauss-Jordan): $\begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \\ 7 & 2 & 9 \end{bmatrix}$.
  - Simpson: $\int_1^3 (x^2 + 2x)\,dx$, $n = 6$, sonuç 16.666.
  - Gauss eliminasyon: $2x_1 + 5x_2 = 16$, $3x_1 + x_2 = 11$. Sonuç $x_1 = 3$, $x_2 = 2$.
  - Gregory-Newton: $x$: 0…6, $f$: −4, −2, 14, 62, 160, 326, 578. $x = 4.5$ için 233.375.
  - Regula falsi: $x^2 - 4x - 5$, aralık $[-1, 5]$, kök $-1$.
- Hocanın kod hakkındaki yorumları
  - Newton-Raphson bir başlangıç değeriyle çalışır. Alt ve üst sınır istemek gereksiz.
  - Durma koşulu ardışık iki kökün mutlak farkının $\varepsilon$'dan küçük olmasıdır. Maksimum iterasyon sayısı ek bir güvenlik olabilir, ama asıl ölçüt bu farktır.
  - Üç farklı durma koşulunu ayrı ayrı kodlayan bir öğrenciye "hayatı kendinize zorlaştırmışsınız" dedi.
  - Öğrenci "şimdi yazsam daha okunur, daha optimize yazardım" dediğinde hoca: "İşte bu senin kendindeki gelişmeyi gösteriyor. Bizim istediğimiz bu." Vakit olursa yeniden yazıp başına ve sonuna zaman ölçümü koyarak hızını karşılaştırmanızı önerdi.
  - Gregory-Newton'da $x$ değerleri eşit aralıklı değilse $h$'yi sabit kabul etmek yanlıştır. Değişken dönüşümü gerekir.
  - Polinomların nasıl girileceğini (derece mi, terim sayısı mı, katsayı sırası) programınız açıkça söylemeli. Hoca birkaç gösterimde neyin sorulduğunu anlamakta zorlandı.
  - Ek olarak üstel, logaritmik veya trigonometrik fonksiyon girişi yapanlar bunu hocaya söylemeli.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sunumda kamera ve mikrofon açık olsun. Hazır değilseniz o hafta sunmayın.
- Raporu aynı gün yükleyin. Derste çalıştırılan yöntemin ekran çıktısını ekleyin.
- Newton-Raphson'da başlangıç değeri, durma koşulunda ardışık köklerin farkı kullanılır.
- Kodunuzdaki gelişimi görmeniz projenin asıl amacıdır.
- Vize saat 16:00'da, 75 dakika, hesap makinesi yanınızda olsun.

## Kısa Tekrar Notları

- Gösterim: yöntem sayısını söyle, hoca 1-2 yöntem seçer, kendi girdisiyle çalıştırır.
- Rapor: yöntem tablosu, kodlar, derste çalıştırılan yöntemin ekran çıktısı.
- Kamera ve ses zorunlu.

## Detaylı Açıklamalar

### Ders sonrası notlar

- **Gösterim örneklerinin kontrolü:** Örnekler ders sonrasında Python ile yeniden hesaplandı. $x^2 - 4x - 5 = (x - 5)(x + 1)$, kökler 5 ve −1. $x^3 + x^2 - 9x - 9 = (x + 1)(x - 3)(x + 3)$, kökler −1, 3, −3. $\int_1^3 (x^2 + 2x)\,dx = \left[\frac{x^3}{3} + x^2\right]_1^3 = 16.667$. Ders 8'deki Gregory-Newton polinomu $3x^3 - 2x^2 + x - 4$, $x = 4.5$ için 233.375 verir.
- **Gösterimdeki matrisin tersi:** $\begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \\ 7 & 2 & 9 \end{bmatrix}^{-1} = \begin{bmatrix} -0.9167 & 0.3333 & 0.0833 \\ -0.1667 & 0.3333 & -0.1667 \\ 0.75 & -0.3333 & 0.0833 \end{bmatrix}$. Kendi kodunuzu sınamak için kullanabilirsiniz.
- **Kendi kodunuzu sınamak için:** Hocanın yaptığı gibi kökleri bilinen polinomlar seçin (ör. $(x - a)(x - b)$ çarpımı) ve farklı başlangıç değerleriyle farklı köklerin bulunduğunu kontrol edin. Ders 5'te söylendiği gibi kök içermeyen bir aralık ve çok dar bir aralık da deneyin.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
