# Ders 7 Çalışma Özeti

## Genel Konular

- Sınav duyuruları (Ahmet Hoca ile birlikte alınan kararlar)
  - İki vize yapılacak. Birinci vize üniversitenin vize haftasında, bayramdan sonra. İki vize de online olacak.
  - Vizeler çoktan seçmeli (test) olacak. Bir sorunun birden fazla doğru cevabı olabilir (bir ya da iki). İki doğruyu da işaretleyenle birini işaretleyenin alacağı puan farklıdır.
  - Final yüz yüze ve klasik olacak. Mayıs itibarıyla derslere katılımın artması bekleniyor.
  - Vizeyi kısmen klasik yapma fikri vardı, bu yüzden bir deneme sınavı planlanmıştı. Vize tamamen test olunca denemeye gerek kalmadı. Yapısal Programlama dersinde de test usulü sınav ve onun denemesi yapılacağı için online sınav pratiği oradan kazanılacak.
  - Enterpolasyon vizeye dahil değildir.
- Proje soruları hakkında
  - "Her şey sorulmaz." Trigonometrik fonksiyon, üs, karekök gibi hazır fonksiyonlar elbette kullanılabilir. Yalnızca kodlamanız istenen yöntemin kendisini yapan hazır bir kütüphane kullanılamaz.
  - Ara adımları yazdırıp yazdırmamak size kalmış: `printf` koyup yorum satırı yaparak açıp kapatabilirsiniz. İnisiyatif alın, kendi kararlarınızı verin.
  - Her hafta kod yazarsanız gelişiminizi kendiniz görürsünüz. Dönem sonunda ilk yazdığınız kök bulma koduna bakıp güleceksiniz.
- İntegral tekrarı
  - Trapez: alan yamuklara bölünür. $I \approx h\left[\frac{f(a) + f(b)}{2} + \sum f_i\right]$, $h = \frac{b - a}{n}$.
  - Simpson 1/3: parabol (3 nokta). $I \approx \frac{h}{3}\left[f_0 + f_n + 4\sum_{\text{tek}} f_i + 2\sum_{\text{çift}} f_i\right]$, $n$ çift.
  - Simpson 3/8: kübik (4 nokta, 3 eşit parça). $I \approx (b - a)\frac{f(a) + 3f(x_1) + 3f(x_2) + f(b)}{8}$, $x_1 = a + \frac{b-a}{3}$, $x_2 = a + 2\frac{b-a}{3}$. Bu kuralda formül için $n$'e ihtiyaç yoktur.
  - Simpson 3/8'de $n = 2$ veya $n = 3$ ise $[a, b]$ eşit alt aralıklara bölünür, her birine formül ayrı uygulanır ve sonuçlar toplanır. Örnek $\int_0^6 \frac{dx}{1+x^4}$, $n = 2$: alt aralıklar $[0, 3]$ ve $[3, 6]$, iç noktalar 1, 2 ve 4, 5. Her alt aralıkta $x_1$ için alt aralık uzunluğu 3'e bölünür (hoca derste önce yanlışlıkla 2'ye bölüp düzeltti).
- Sınıf alıştırması: $y = x^2 - 5x + 4$ parabolü, $y = 4$, $x = 0$, $x = 4$ doğruları ve $Ox$ ekseni ile sınırlı bölgenin alanı (trapez ve Simpson 1/3, $n = 4$).
  - Önce şekil: parabolün kökleri 1 ve 4 (çarpımı 4, toplamı 5). $x = 0$'da $y = 4$.
  - İstenen bölge doğrudan bilinen bir şekil değildir. Ama $[0, 4] \times [0, 4]$ bir karedir, alanı 16. Karenin içinde istenmeyen kısım, parabolün $[0, 1]$ aralığında $Ox$ üstünde kalan parçasıdır.
  - Alan $= 16 - \int_0^1 (x^2 - 5x + 4)\,dx$. İntegral trapez veya Simpson ile hesaplanır. Sonuç yaklaşık 14.16 br².
  - Hocanın genel mesajı: önce şekli çizin, bölgeyi sınırlayın. Gerekirse bölgeyi bilinen alanlar (kare, dikdörtgen) ve integrallerle hesaplanacak parçalara bölün, ekleyip çıkarın. Eksenin altında kalan parçalar ayrı hesaplanır ve mutlak değerleri toplanır. Kökleri geçen bir aralıkta tek integral alınamaz, parçalara bölünür.
  - "$Ox$ ekseni ile sınırlı" ifadesi önemlidir. Bu belirtilmezse eğrinin altında kalan alan sonsuza gidebilir.
- İki katlı integral
  - Örnek: $I = \int_2^3 \int_x^{2x^3} (x^2 + y)\,dy\,dx$, $n = 4$.
  - İç integral bir $g(x)$ fonksiyonu gibi düşünülür (kapalı kutu): $I = \int_2^3 g(x)\,dx$.
  - Dış integral için $h = \frac{3 - 2}{4} = 0.25$, $x$: 2, 2.25, 2.5, 2.75, 3. Her $x_i$ için $g_i = g(x_i)$ ayrı bir tek katlı integral olarak hesaplanır.
    - $x_0 = 2$: $g_0 = \int_2^{16} (4 + y)\,dy$, $h = \frac{16 - 2}{4} = 3.5$, $y$: 2, 5.5, 9, 12.5, 16, $f$: 6, 9.5, 13, 16.5, 20. $g_0 = \frac{3.5}{3}[(6 + 20) + 2 \cdot 13 + 4(9.5 + 16.5)] = 182$.
    - $x_1 = 2.25$: sınırlar $2.25$ ile $2 \cdot 2.25^3$, yeni $h$. Slaytta $g_1 = 360.417$. Benzer şekilde $g_2 = 665.22$, $g_3 = 1154.7$, $g_4 = 1912.5$.
  - Dış integral (Simpson): $\frac{0.25}{3}[182 + 1912.5 + 4(360.417 + 1154.7) + 2 \cdot 665.22] = 790.451$.
  - Analitik sonuç 790.55, hata 0.099 (slayt).
  - Trapez ve Simpson'ı bir kez fonksiyon olarak yazdıysanız, iki katlı integralde aynı fonksiyonu önce iç, sonra dış integral için çağırırsınız. İki katlı integral sınavda sorulmayacak, tek katlı yeterli.
- Sonlu farklar
  - Bir fonksiyon bazen yalnızca ayrık noktalarda bilinir. Örnek: odanın sıcaklığı yalnızca saat 9, 12, 14, 16, 18'de ölçülmüş. Saat 10 veya 17'deki sıcaklığı tahmin etmek için bu noktalardan geçen bir fonksiyon uydurulur. Bu enterpolasyondur.
  - Gregory-Newton enterpolasyonu formülündeki katsayılar sonlu fark tablosundan alınır. Sonlu farklar bu yüzden önce öğrenilir.
  - Noktalar eşit aralıklıdır: $x_i = x_0 + ih$. $f_i = f(x_i)$ kısaltması kullanılır.
  - Fark operatörleri:
    - İleri fark: $\Delta f(x) = f(x + h) - f(x)$, $\Delta f_i = f_{i+1} - f_i$.
    - Geri fark: $\nabla f(x) = f(x) - f(x - h)$, $\nabla f_i = f_i - f_{i-1}$.
    - Merkezi fark: $\delta f(x) = f(x + \frac{h}{2}) - f(x - \frac{h}{2})$.
    - Ortalama operatörü: $\mu f(x) = \frac{1}{2}\left[f(x + \frac{h}{2}) + f(x - \frac{h}{2})\right]$.
    - Kaydırma operatörü: $Ef(x) = f(x + h) = f(x) + \Delta f(x)$, yani $E = 1 + \Delta$. $E^n f(x) = f(x + nh)$.
  - Uygulamalarda ve kitapların çoğunda ileri fark kullanılır. Merkezi fark daha karmaşıktır ve hataya açıktır, az kullanılır.
  - Yüksek dereceli ileri farklar:
    - $\Delta^2 f_i = \Delta f_{i+1} - \Delta f_i = f_{i+2} - 2f_{i+1} + f_i$.
    - $\Delta^3 f_i = f_{i+3} - 3f_{i+2} + 3f_{i+1} - f_i$.
    - Katsayılar binom katsayılarıdır (1-2-1, 1-3-3-1), işaretler artı-eksi sırayla gelir. İleri farkta en büyük indisten başlanır ve $f_i$ ile biter.
    - Genel formül: $\Delta^k f_i = \sum_{j=0}^{k} (-1)^j \binom{k}{j} f_{i+k-j}$, $\binom{k}{j} = \frac{k!}{j!(k-j)!}$.
    - Örnek ($k = 5$): $\Delta^5 f_0 = f_5 - 5f_4 + 10f_3 - 10f_2 + 5f_1 - f_0$.
  - Geri farklar: $\nabla^2 f_i = f_i - 2f_{i-1} + f_{i-2}$, $\nabla^3 f_i = f_i - 3f_{i-1} + 3f_{i-2} - f_{i-3}$. Geri farkta $f_i$ ile başlanır, indis azalarak gider.
  - Merkezi farklar: $\delta^2 f_i = f_{i+1} - 2f_i + f_{i-1}$. Yine binom katsayıları.
  - Operatörler arası ilişki: $\Delta^r f_i = \nabla^r f_{i+r} = \delta^r f_{i + r/2}$.
- İleri fark tablosu
  - Her sütun bir önceki sütunun ardışık farklarıdır: alttaki değerden üstteki çıkarılır. Sütun sabit bir sayıya ulaşınca (sonraki sütun sıfır olunca) durulur.
  - Örnek: $f(x) = x^3 - 3x$, $h = 1$, $[-3, 2]$.

    | $x_i$ | $f(x_i)$ | $\Delta f$ | $\Delta^2 f$ | $\Delta^3 f$ | $\Delta^4 f$ |
    |---|---|---|---|---|---|
    | −3 | −18 | 16 | −12 | 6 | 0 |
    | −2 | −2 | 4 | −6 | 6 | 0 |
    | −1 | 2 | −2 | 0 | 6 | |
    | 0 | 0 | −2 | 6 | | |
    | 1 | −2 | 4 | | | |
    | 2 | 2 | | | | |

  - Genel olarak $n$. dereceden bir polinomun $n$. farkı sabittir. $P_n(x) = a_0 x^n + \ldots$ için 3. dereceden polinomda $\Delta^3 P_3 = 6a_0h^3$. Burada $h = 1$, $a_0 = 1$, yani $\Delta^3 f = 6$.
  - Geri fark tablosu da aynı sayıları verir, yalnızca indisler farklı satırlara yazılır. Bu yüzden genellikle ileri fark kullanılır.
- Fark tablosunda hatanın yayılması
  - Bir ölçümde (ör. $f_3$'te) $\varepsilon$ kadar hata yapıldığını varsayalım. Hata tabloda sütun sütun büyüyerek yayılır. Hatanın katsayıları binom katsayılarıdır, işaretleri sırayla değişir:
    - $\Delta$: $+\varepsilon, -\varepsilon$.
    - $\Delta^2$: $+\varepsilon, -2\varepsilon, +\varepsilon$.
    - $\Delta^3$: $+\varepsilon, -3\varepsilon, +3\varepsilon, -\varepsilon$.
    - $\Delta^4$: $-4\varepsilon, +6\varepsilon, -4\varepsilon$. $\Delta^5$: $+10\varepsilon, -10\varepsilon$. $\Delta^6$: $-20\varepsilon$.
  - Sıfıra gitmesi gereken bir sütun sıfırlanmıyorsa, hiçbir yerde sabitlenmiyorsa, verilerin birinde ölçüm hatası vardır. 0.0001 gibi çok küçük değerler sıfır kabul edilebilir.
- Ders planı: gelecek hafta enterpolasyona başlanacak (vizeye dahil değil).

## Hocanın Özellikle Vurguladığı Kısımlar

- Vizeler online ve test. Bir soruda birden fazla doğru cevap olabilir. Testte de kağıt kalem oynatmanız gerekecek.
- Alan sorularında önce şekli çizin. Bilinen alanları (kare, dikdörtgen) kullanıp integralle hesaplanacak parçaları ekleyip çıkarın.
- "$Ox$ ekseni ile sınırlı" ifadesine dikkat edin.
- Simpson 1/3 ve trapezde $n$ gerekir, Simpson 1/3'te $n$ çift olmalıdır. Simpson 3/8'in temel formülünde $n$ kullanılmaz.
- İki katlı integralde iç integrali bir $g(x)$ "kapalı kutusu" olarak düşünün.
- Fark tablolarında katsayılar binom katsayılarıdır. Bu sayede herhangi bir dereceden farkı ezberlemeden yazabilirsiniz.
- Fark tablosu sıfırlanmıyorsa verilerde hata vardır.
- Projede inisiyatif alın, her ayrıntıyı sormayın.

## Kısa Tekrar Notları

- $\Delta f_i = f_{i+1} - f_i$, $\nabla f_i = f_i - f_{i-1}$, $\delta f_i = f_{i+1/2} - f_{i-1/2}$, $E = 1 + \Delta$.
- $\Delta^k f_i = \sum_{j=0}^{k} (-1)^j \binom{k}{j} f_{i+k-j}$.
- $n$. dereceden polinomun $n$. farkı sabit: $\Delta^n P_n = n!\,a_0 h^n$.
- Tek bir veride $\varepsilon$ hatası $k$. sütunda binom katsayılarıyla büyür.
- İki katlı integral: her dış nokta $x_i$ için iç integral $g_i$, sonra $g_i$'ler üzerinden dış integral.

## Detaylı Açıklamalar

### Fark ile türev arasındaki ilişki

- Ders sonunda hoca $\Delta^5 f_0$ için "ileri fark formülünden 5. türev" ifadesini kullandı. Burada hesaplanan şey 5. türevin kendisi değil, 5. ileri farktır. İkisi arasında $f^{(k)}(x_0) \approx \frac{\Delta^k f_0}{h^k}$ ilişkisi vardır. $h = 1$ alınırsa sayısal olarak yaklaşık aynı olurlar.
- $n$. dereceden polinomun $n$. farkının sabit olması da buradan gelir: $P_n^{(n)} = n!\,a_0$ sabittir, $\Delta^n P_n = n!\,a_0 h^n$. Örnekte $3! \cdot 1 \cdot 1^3 = 6$.

### Ders sonrası notlar

- **Örneklerin kontrolü:** Örnekler ders sonrasında Python ile yeniden hesaplandı. Fark tablosu ($x^3 - 3x$) ve alan alıştırması doğrudur.
- **Alan alıştırmasının cevabı:** $\int_0^1 (x^2 - 5x + 4)\,dx = \frac{1}{3} - \frac{5}{2} + 4 = 1.8333$. Alan $= 16 - 1.8333 = 14.1667$ br². $n = 4$ ile Simpson 1/3 tam sonucu (14.1667) verir, çünkü fonksiyon 2. derece polinomdur. Trapez 14.1563 verir. Hocanın söylediği 14.16 ile uyumludur.
- **İki katlı integral örneğinde ara değerler:** $g_0 = 182$ ve $g_4 = 1912.5$ doğrudur. Diğer ara değerler kesin hesapla $g_1 = 360.901$, $g_2 = 664.844$, $g_3 = 1154.995$'tir (slaytta 360.417, 665.22, 1154.7). Hoca $g_1$ için "sınırda biraz taşma oldu" dedi: iç integralin $h$ değerleri yuvarlanarak (ör. 5.13) kullanılmış, bu yüzden son nokta üst sınırı tam tutturmamış. Kesin değerlerle dış Simpson sonucu 790.647'dir. Analitik değer $\int_2^3 \left(2x^6 + 2x^5 - x^3 - \frac{x^2}{2}\right)dx = 790.536$'dır. Yani doğru hesapla hata yaklaşık 0.11'dir (slaytta 0.099). Ders: ara adımlarda $h$ ve sınırları yuvarlamayın.
- **Hata yayılması tablosunda indis:** Slaytta son sütundaki eleman $\Delta^6 f_1 - 20\varepsilon$ yazıyor. 7 nokta ($x_0, \ldots, x_6$) ile tek bir 6. fark vardır, o da $\Delta^6 f_0$'dır. Katsayı ve işaret ($-20\varepsilon$) doğrudur.
- **Vize tarihi:** Önceki derste vizenin 9. haftaya kayabileceği konuşulmuştu. Bu derste "bayramdan sonra, üniversitenin vize haftasında" dendi. Kesin tarih için duyuruları takip edin.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
