# Ders 5 Çalışma Özeti

## Genel Konular

- Dersin tarihi 14 Ağustos 2021 Cumartesi (sabah oturumu). Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:03'te başlar. Kaydın başında quiz ve vize düzeni konuşulur.
- Önceki derslerin tekrarı (Bölüm 4)
  - Sistemlerin özellikleri: doğrusallık, belleklilik, zamanla değişmezlik, kararlılık (BIBO), tersinirlik.
  - Sistem bağlantıları: seri (kaskad), paralel ve geri beslemeli (feedback) bağlantı.
  - Sistemlerin diferansiyel denklemlerle (sürekli zaman) ve fark denklemleriyle (ayrık zaman) gösterilmesi.
- Birim dürtü cevabı (impulse response) $h(t)$
  - Doğrusal ve zamanla değişmeyen (LTI) bir sisteme birim dürtü verilince çıkan işarettir.
  - Hoca $h(t)$'yi "sistemin röntgeni" diye tanıttı.
- Konvolüsyon integrali (sürekli zaman)
  - Süperpozisyon integralinden konvolüsyona geçiş.
  - Adımlar: değişken dönüşümü ($t \to \tau$), ters çevirme (flip), kenarları bulma, kaydırma (shift) ve bölge bölge integral.
  - İki dikdörtgen işaretin grafiksel konvolüsyonu örneği.
- Konvolüsyon toplamı (ayrık zaman)
  - Ters çevir, kaydır, çarp ve topla yöntemi.
  - Sonucun hangi indislerde sıfırdan farklı olduğunu bulma.
- Konvolüsyonun uygulamaları
  - Konvolüsyonel sinir ağları (CNN), kenar bulma filtreleri (Laplace, Prewitt, Sobel).
  - Konvolüsyonun algoritmik maliyeti ve dönüşüm düzleminde çarpmanın avantajı.
- Sistem modelleme ve diferansiyel denklemler (Bölüm 6)
  - RLC devresi, araç süspansiyonu ve iletim kablosu modelleri.
  - Diferansiyel denklemlerin mertebe (order), derece (degree), doğrusallık ve homojenlik özellikleri.
  - Sıfır giriş cevabı (zero-input response) ve karakteristik denklem örnekleri.
- Ödev 1 duyurusu: ayrık zamanlı konvolüsyon fonksiyonu yazma.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınavda bir ayrık zaman ve bir sürekli zaman konvolüsyon sorusu gelecek.
  - Biri vizede, biri finalde sorulabilir. Hoca integrali zorlaştırmayacağını söyledi.
  - Amaç, konvolüsyonu doğru uygulayıp sonuca gitmek.
- Sürekli zaman konvolüsyonunun zor tarafı integral sınırlarını doğru belirlemektir.
  - Örtüşmenin başladığı, sabit kaldığı ve azaldığı bölgeleri ayrı ayrı yazın.
- Ters çevirmede kısa olan işareti çevirmek daha kolaydır.
  - Hangisini çevirdiğiniz sonucu değiştirmez (değişme özelliği).
- Konvolüsyon yalnız LTI sistemlerde uygulanır.
  - Sistem doğrusal ve zamanla değişmez değilse bu kabulü yapamayız.
- Ayrık konvolüsyonda başlangıç indisine dikkat edin.
  - Ödevde indisler yanlışsa sonuç kabul edilmeyecek.
- Diferansiyel denklemleri bu derste klasik yöntemle çözmeyeceğiz.
  - Laplace ve Fourier dönüşümleriyle cebirsel denkleme çevirip çözeceğiz.
- Diferansiyel denklemlerin özellikleri (mertebe, derece, homojenlik, ODE) quizlerde doğru-yanlış sorusu olarak gelebilir.
- Quizler o günün konusundan değil, bir önceki Çarşamba ve Cumartesi konularından yapılır.
  - Quiz ders saatinde yapılır. Pazar günü quiz isteği kabul edilmedi.

## Kısa Tekrar Notları

- Birim dürtü cevabı: $\delta(t) \rightarrow \boxed{\text{LTI}} \rightarrow h(t)$.
  - Zamanla değişmezlik: $\delta(t-t_0) \rightarrow h(t-t_0)$.
- Konvolüsyon integrali: $y(t) = x(t) * h(t) = \int_{-\infty}^{\infty} x(\tau)\,h(t-\tau)\,d\tau$.
  - Nedensel sistem ve nedensel giriş için: $y(t) = \int_{0}^{t} x(\tau)\,h(t-\tau)\,d\tau$.
- Konvolüsyon toplamı: $y[n] = x[n] * h[n] = \sum_{k=-\infty}^{\infty} x[k]\,h[n-k]$.
  - Nedensel sistem ve nedensel giriş için: $y[n] = \sum_{k=0}^{n} x[k]\,h[n-k]$.
- Konvolüsyonun özellikleri:
  - Değişme: $x * h = h * x$.
  - Birleşme: $(x * h_1) * h_2 = x * (h_1 * h_2)$ (seri bağlı sistemler).
  - Dağılma: $x * (h_1 + h_2) = x * h_1 + x * h_2$ (paralel bağlı sistemler).
  - Türev: $\frac{d}{dt}(x * h) = \frac{dx}{dt} * h = x * \frac{dh}{dt}$.
- Basamak cevabı (step response): $s(t) = u(t) * h(t)$. $h(t) = \frac{ds(t)}{dt}$.
- Dönüşüm düzleminde konvolüsyon çarpmaya dönüşür:
  - $Y(\omega) = X(\omega)\,H(\omega)$ (Fourier), $Y(s) = X(s)\,H(s)$ (Laplace), $Y(z) = X(z)\,H(z)$ (z dönüşümü).
- Ayrık konvolüsyonda sonuç uzunluğu: $L_x + L_h - 1$.
  - $x[n]$, $n_1..n_2$ ve $h[n]$, $m_1..m_2$ aralığında ise $y[n]$, $n_1+m_1 .. n_2+m_2$ aralığındadır.
- Homojen (sıfır giriş) çözüm adımları:
  - Sağ tarafı sıfır yap. Karakteristik denklemi yaz. Kökleri bul.
  - Farklı reel kökler: $y(t) = c_1 e^{\lambda_1 t} + c_2 e^{\lambda_2 t}$.
  - Çakışık kök: $y(t) = (c_1 + c_2 t)\,e^{\lambda t}$.
  - Karmaşık kökler: üstel çarpı kosinüs ve sinüs terimleri.
  - Katsayıları başlangıç koşullarından bul.

## Detaylı Açıklamalar

### Birim dürtü cevabı ve süperpozisyon integrali

- Bir sistemin girişini ve çıkışını biliyorsak sistemin iç davranışını bulmak isteriz. Böylece başka girişler için çıkışı önceden hesaplayabiliriz.
- Bunun bir yolu birim dürtü cevabıdır.
  - Sistemin doğrusal olduğunu kabul ederiz.
  - Sisteme birim dürtü verilir. Çıkan işaret $h(t)$'dir.
- Her giriş işareti, ötelenmiş ve ağırlıklandırılmış dürtülerin toplamı olarak yazılabilir:
  - $x(t) = \int_{-\infty}^{\infty} x(\tau)\,\delta(t-\tau)\,d\tau$.
- Sistem doğrusal ise her dürtünün cevabı ayrı ayrı toplanır (genişletilmiş doğrusallık, extended linearity).
- Sistem zamanla değişmez ise $\tau$ kadar gecikmiş dürtünün cevabı $h(t-\tau)$'dur.
- İkisi birlikte süperpozisyon integralini, yani konvolüsyonu verir.
- $h(t)$ biliniyorsa diğer düzlemlerdeki karşılıkları da bulunur:
  - Fourier dönüşümü $H(\omega)$: frekans cevabı (frequency response).
  - Laplace dönüşümü $H(s)$: transfer fonksiyonu (transfer function).
  - Kararlılık gibi özellikler bu düzlemlerde daha kolay incelenir.

### Sürekli zaman konvolüsyonu: grafiksel yöntem

- Adımlar:
  1. İki işareti de $\tau$ eksenine taşı. $x(t) \to x(\tau)$, $h(t) \to h(\tau)$.
  2. Birini ters çevir: $h(\tau) \to h(-\tau)$.
  3. Ters çevrilen işaretin kenarlarını (edge) bul. $h(t-\tau)$'nun sol ve sağ kenarı $t$'ye bağlıdır.
  4. $t$'yi $-\infty$'dan $+\infty$'a kaydır. Örtüşme durumuna göre bölgeleri ayır.
  5. Her bölgede belirli integrali hesapla. Sonuçları birleştir.
- Hoca konvolüsyonu bir benzerlik ölçüsüne benzetti.
  - Kayan işaret ile sabit işaret en çok örtüştüğünde sonuç en büyük değerini alır.
  - Yüz görüntüsünde göz aramayı örnek verdi.

### Örnek: iki dikdörtgen işaretin konvolüsyonu

- Slayttaki işaretler:
  - $x(t) = 2$, $0 \le t \le 2$; diğer yerlerde $0$.
  - $h(t) = 3$, $0 \le t \le 1$; diğer yerlerde $0$.
- Kısa olan $h$ ters çevrilir. $h(t-\tau)$'nun kenarları $t-1$ ve $t$'dir.
- Bölgeler:
  - $t < 0$: örtüşme yok. $y(t) = 0$.
  - $0 \le t \le 1$: kısmi örtüşme. $y(t) = \int_0^t 2 \cdot 3\,d\tau = 6t$.
  - $1 < t \le 2$: tam örtüşme. $y(t) = \int_{t-1}^{t} 6\,d\tau = 6$.
  - $2 < t \le 3$: örtüşme azalıyor. $y(t) = \int_{t-1}^{2} 6\,d\tau = 18 - 6t$.
  - $t > 3$: örtüşme yok. $y(t) = 0$.
- Sonuç bir yamuktur: $0$'dan $1$'e doğrusal artar, $1$ ile $2$ arasında $6$'da sabit kalır, $2$'den $3$'e doğrusal azalır.
  - Örnek: $y(1.5) = 6$.

### Ayrık zaman konvolüsyonu: ters çevir, kaydır, çarp, topla

- Adımlar:
  1. İşaretleri $k$ (veya $i$) indisine taşı.
  2. Birini ters çevir: $h[-k]$.
  3. Her $n$ için $h[n-k]$'yı kaydır. Örtüşen değerleri çarp ve topla.
- Örnek: $x[n] = \{\underline{2}, 2, 1\}$, $h[n] = \{\underline{3}, 3, 3, 3, 3\}$ (alt çizgi $n=0$'ı gösterir).
  - Hoca önce $h$'yi $1$'lerden oluşuyor sandı, sonra slayta bakıp $3$ olarak düzeltti.
  - $h$ $1$'lerden oluşsaydı: $y[n] = \{2, 4, 5, 5, 5, 3, 1\}$.
  - Doğru sonuç ($h$ $3$'lerden oluşuyor): $y[n] = \{\underline{6}, 12, 15, 15, 15, 9, 3\}$, $n = 0..6$.
- Ödev açıklamasındaki örnek:
  - $x[n] = \{1, \underline{2}, 3\}$ ($n = -1..1$), $h[n] = \{\underline{1}, 2, 3\}$ ($n = 0..2$).
  - $y[n] = \{1, \underline{4}, 10, 12, 9\}$, $n = -1..3$.
  - Sonuç $-1$'den başlar. Çünkü ilk örtüşme $n=-1$'de olur.

### Konvolüsyonun uygulamaları ve maliyeti

- Görüntü işlemede 2 boyutlu konvolüsyon kullanılır. Örneğin $3 \times 3$'lük bir filtre görüntünün her pikselinde gezdirilir.
  - Laplace filtresi: $\begin{bmatrix} 0 & 1 & 0 \\ 1 & -4 & 1 \\ 0 & 1 & 0 \end{bmatrix}$.
  - Prewitt ve Sobel filtreleri dikey ve yatay kenarları bulur.
- Derin öğrenmedeki konvolüsyonel sinir ağları (CNN) özellik çıkarımını konvolüsyonla yapar.
- Ayrık konvolüsyon iç içe iki döngüyle hesaplanır. Bu yüzden maliyetlidir.
- Dönüşüm düzleminde konvolüsyon, eleman eleman çarpmaya dönüşür. Bu çarpmanın kendisi doğrusal maliyetlidir.
- Fourier ve Laplace dönüşümleri de bir integral dönüşümüdür. İşaret, karmaşık üstel bir işaretle çarpılıp integre edilir.

### Sistem modelleme ve diferansiyel denklemler

- Mühendislikte bir sistemi analiz etmek için önce modelini kurarız.
  - Model, sistemi belirleyen parametreler arasındaki ilişkiyi veren bir denklemdir.
  - Bu ilişkiyi yazmak alan bilgisi gerektirir (Kirchhoff kanunları, Newton kanunları vb.).
- Örnekler:
  - RLC devresi: ikinci mertebeden diferansiyel denklem.
  - Araç süspansiyon sistemi (yay ve sönümleyici): dördüncü mertebeden diferansiyel denklem.
  - İki bilgisayar arasındaki kablo: kaynak, kablo ve alıcı Thevenin eşdeğerleriyle modellenir. Birinci mertebeden denklem çıkar.
- Amaç $y(t)$ ile $x(t)$ arasında türev içermeyen bir ilişki bulmaktır. Bunun için diferansiyel denklem çözülür.
- Deterministik ve olasılıksal sistemler:
  - RLC devresi aynı parametrelerle hep aynı davranır (deterministik).
  - Hastalık teşhisi gibi veriye dayalı tahmin sistemleri %100 doğru çalışmaz (olasılıksal, stokastik). Yine de modelin olması hiç olmamasından iyidir.
- Diferansiyel denklemlerin özellikleri:
  - Mertebe (order): en yüksek türevin derecesi.
  - Derece (degree): en yüksek türevin kuvveti.
  - Doğrusal: katsayılar sabit ve doğrusal olmayan terim yok.
  - Homojen: sağ taraf (zorlama fonksiyonu, forcing function) sıfır.
  - Adi diferansiyel denklem (ODE): tek bir bağımsız değişken var.
- Genel çözüm, sıfır giriş cevabı ile sıfır durum cevabının (zero-state response) toplamıdır.

### Örnek: sıfır giriş cevabı (homojen çözüm)

- Slayttaki denklem: $\dfrac{d^2y}{dt^2} + 3\dfrac{dy}{dt} + 2y = \dfrac{df}{dt}$, başlangıç koşulları $y(0) = 0$, $y'(0) = -5$.
- Sağ taraf sıfır alınır. Karakteristik denklem: $\lambda^2 + 3\lambda + 2 = 0 \Rightarrow (\lambda+1)(\lambda+2) = 0$.
- Kökler $\lambda_1 = -1$, $\lambda_2 = -2$. Çözüm: $y(t) = c_1 e^{-t} + c_2 e^{-2t}$.
- Başlangıç koşulları:
  - $y(0) = c_1 + c_2 = 0$.
  - $y'(0) = -c_1 - 2c_2 = -5 \Rightarrow c_1 + 2c_2 = 5$.
  - $c_2 = 5$, $c_1 = -5$.
- Sonuç: $y(t) = -5e^{-t} + 5e^{-2t}$.
- Çakışık kök çıkarsa ikinci terim $t$ ile çarpılır. Karmaşık kök çıkarsa çözümde kosinüs ve sinüs terimleri oluşur.

### Ödev 1: ayrık zamanlı konvolüsyon

- Teslim: 20 Ağustos 2021 Cuma 23:59. Bu saatten sonra, e-postayla bile, teslim kabul edilmez.
- İstenenler:
  - Python, MATLAB veya R ile kendi konvolüsyon fonksiyonunuzu yazın (ör. `myConvolution(x, y)`). İndis bilgisini de kullanıcıdan alın. (60 puan)
  - Aynı dildeki hazır konvolüsyon fonksiyonunu uygulayın (ör. MATLAB `conv`). (10 puan)
  - Sonuçları grafikle karşılaştırın: $x[n]$, $y[n]$, kendi sonucunuz ve hazır fonksiyon sonucu. Dört grafik bir arada (subplot).
  - Sonuçları vektör olarak da ekrana yazdırın.
  - Üç farklı $x$ ve $y$ girişi için tekrarlayın.
- Rapor tek bir PDF dosyası olarak Online Yıldız'a yüklenecek.
  - Kaynak kod raporun sonunda kopyalanabilir metin olarak olacak. Ekran görüntüsü kabul edilmez.
- İndisler doğru değilse sonuç kabul edilmez, yalnızca kısmi puan verilir.

### Quiz ve vize duyuruları

- Quiz bugün öğleden sonra yapılacak. Bugünün konusu değil, bir önceki Çarşamba ve Cumartesi konuları sorulacak.
- Vize gelecek hafta Cumartesi (21 Ağustos 2021) öğleden sonra yapılacak.
  - Dört veya beş soru, 80-90 dakika civarı, klasik.

### Ders sonrası notlar

- Hoca dikdörtgen örneğinin ikinci bölgesinde önce integrali $\int 6\tau\,d\tau = 3\tau^2$ diye aldı. Doğrusu integrandın sabit olmasıdır: $\int_0^t 6\,d\tau = 6t$. Hoca bunu sonradan kendisi düzeltti.
- Hoca örneğin bir yerinde bölgeyi anlatırken doğrusal bir "$2t+1$" ifadesinden söz etti. Bu ifade doğru değildir. Tam örtüşme bölgesinde sonuç sabittir ($6$), azalma bölgesinde $18-6t$'dir.
- Hoca ayrık örneğin sonucunu bir kez "6, 12, 15, 15, 15, 15, 9, 3" diye okudu. Doğru sonuçta üç tane $15$ vardır: $\{6, 12, 15, 15, 15, 9, 3\}$ (Python `numpy.convolve` ile doğrulandı).
- Hoca sonucun son indisi için önce "üst sınırların toplamı eksi bir" dedi, sonra düzeltti. Doğrusu: son indis $= n_2 + m_2$ (iki üst sınırın toplamı). Uzunluk ise $L_x + L_h - 1$'dir.
- Derste "birim dürtü sıfır anında bir değerini üretir" dendi. Bu yalnız ayrık zamanda doğrudur: $\delta[0] = 1$. Sürekli zamanda $\delta(t)$'nin değeri tanımlı değildir. Tanımı alanının $1$ olmasıdır: $\int \delta(t)\,dt = 1$.
- Derste "konvolüsyon aslında bir korelasyondur" dendi. Bu benzetmedir. Çapraz korelasyonda işaret ters çevrilmez, konvolüsyonda ters çevrilir. Simetrik işaretlerde iki sonuç aynı çıkar.
- Dönüşüm düzleminde çarpma doğrusal maliyetlidir, ama dönüşümün kendisi de hesaplanmalıdır. Pratikte FFT ile konvolüsyon $O(N \log N)$ maliyetlidir. Doğrudan konvolüsyon $O(N \cdot M)$'dir.
- Hoca diferansiyel denklem örneklerinde bulunan çözüme "özel çözüm (particular)" dedi. Slayttaki çözüm sağ taraf sıfır alınarak bulunur. Bu, homojen çözümdür (sıfır giriş cevabı). Özel çözüm, sağ tarafın (girişin) etkisinden gelir.
- Diferansiyel denklem örneğinin katsayıları slayt karesinden alındı ($y'(0) = -5$). Çözüm $y(t) = -5e^{-t} + 5e^{-2t}$ başlangıç koşullarını sağlar (Python ile kontrol edildi).
- Dikdörtgen örneğinin sonucu sayısal konvolüsyonla doğrulandı: $y(0.5) = 3$, $y(1.5) = 6$, $y(2.5) = 3$, $y(3.5) = 0$.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
