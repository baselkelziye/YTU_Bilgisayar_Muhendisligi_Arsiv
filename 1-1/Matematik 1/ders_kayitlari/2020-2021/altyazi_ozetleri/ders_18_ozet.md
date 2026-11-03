# Ders 18 Çalışma Özeti

## Genel Konular

- Yerine koyma yöntemi (substitution method, change of variable) tekrarı ve örnekleri.
- $\arctan$ veren integraller.
- Toplam sembolü (sigma notation) ve sonlu toplamların (finite sums) özellikleri.
- Sonlu toplamlarla alan tahmini (estimating areas by finite sums).
- Üst ve alt Riemann toplamı (upper / lower Riemann sum).
- Belirli integralin (definite integration) Riemann toplamının limiti olarak tanımı.
- Örnekler: $[0,1]$ üzerinde $x^2$, $[1,2]$ üzerinde $x^3$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yerine koyma yöntemi aslında 11-12. haftanın konusu. Hoca temel bir yöntem olduğu için önce bunu anlattı, karmaşık teknikler sonra gelecek.
- Formülleri ezberlemenize gerek yok. Uygun değişken değiştirmeyle her seferinde çıkarabilirsiniz.
- Belirli integralin mantığı çok eski: çiftçiler arazilerinin alanını dikdörtgenlere bölerek tahmin ederdi. Matematikçiler bu yöntemi sonradan matematiksel olarak ifade etti ve adı belirli integral oldu.
- Riemann toplamı **sonlu** bir toplamdır ve $n$'ye (parça sayısına) bağlıdır. Sadece bir tahmindir, hatalıdır.
- $n \to \infty$ limiti alınınca $n$'den bağımsız bir sabit bulunur: belirli integral. Bu bir **sonsuz** toplamdır, hata sıfırdır.
- Fonksiyonun sürekli olması ön koşuldur. Süreklilik yoksa bu integralden söz edilemez.
- İntegral her zaman alan vermez. Fonksiyon verilen aralıkta pozitifse alanı verir.
- Sınav: Hoca anlattığı her şeyin sınavda gelebileceğini söylüyor. Doğrudan Riemann toplamı sorulabilir. Bazı limit soruları yalnız Riemann toplamıyla çözülebilir.
- Thomas Calculus'tan soru çözmek mümkün ama hocaya göre gerekli değil; derste anlatılanı anlamak yeterli. Sınavdan önce alıştırma çözülecek.
- İkinci vizenin tarihi bölüm web sitesinden kontrol edilmeli. Genelde 12. haftada oluyor.

## Kısa Tekrar Notları

- Yerine koyma: $\displaystyle\int f(u(x))\,u'(x)\,dx = \int f(u)\,du$.
- $\displaystyle\int \frac{du}{1+u^2} = \arctan u + C$.
- Genelleme: $\displaystyle\int \frac{dx}{1+a x^2} = \frac{1}{\sqrt{a}}\arctan(\sqrt{a}\,x) + C$ ($a>0$).
- Toplam özellikleri:
  - $\sum (a_k \pm b_k) = \sum a_k \pm \sum b_k$.
  - $\sum c\,a_k = c \sum a_k$ ($c$, toplam değişkeni $k$'ya göre sabit).
- Önemli toplam formülleri:
  - $\displaystyle\sum_{k=1}^{n} k = \frac{n(n+1)}{2}$
  - $\displaystyle\sum_{k=1}^{n} k^2 = \frac{n(n+1)(2n+1)}{6}$
  - $\displaystyle\sum_{k=1}^{n} k^3 = \left(\frac{n(n+1)}{2}\right)^2$
  - $\displaystyle\sum_{k=1}^{n} c = n\,c$
- $[a,b]$ aralığı $n$ eşit parçaya bölünürse: $\Delta x = \dfrac{b-a}{n}$, $x_k = a + k\,\Delta x$.
- Üst Riemann toplamı: $U_n = \displaystyle\sum_{k=1}^{n} f(x_k)\,\Delta x$ (artan $f$ için, dikdörtgenler grafiğin üstünde).
- Alt Riemann toplamı: $L_n = \displaystyle\sum_{k=0}^{n-1} f(x_k)\,\Delta x$ (artan $f$ için, dikdörtgenler grafiğin altında).
- $L_n \le A \le U_n$. Sıkıştırma teoremiyle: $\displaystyle\int_a^b f(x)\,dx = \lim_{n\to\infty} L_n = \lim_{n\to\infty} U_n$.
- $\displaystyle\int_0^1 x^2\,dx = \frac{1}{3}$, $\displaystyle\int_1^2 x^3\,dx = \frac{15}{4}$.

## Detaylı Açıklamalar

### Yerine koyma yönteminin mantığı

- İntegrand bir bileşke fonksiyon içeriyorsa, iç fonksiyona $u$ denir.
- Diferansiyel ilişki yazılır: $du = u'(x)\,dx$.
- İntegral, yeni değişken $u$ cinsinden daha basit bir integrale dönüşür.
- Sonunda eski değişkene geri dönülür.

### Örnek 1: $\displaystyle\int \frac{dx}{1+4x^2}$

- $u = 2x$ seçilir. $du = 2\,dx$, yani $dx = \dfrac{1}{2}du$.
- $\displaystyle\int \frac{dx}{1+4x^2} = \frac{1}{2}\int \frac{du}{1+u^2} = \frac{1}{2}\arctan u + C$.
- Sonuç: $\dfrac{1}{2}\arctan(2x) + C$.
- Kontrol: Sonucun türevi alınırsa integrand bulunur.

### Örnek 2: $\displaystyle\int \frac{\ln x}{x(1+\ln^2 x)}\,dx$

- İki aday var: $u = \ln x$ veya $u = \ln^2 x$.
- $u = \ln x$ seçilirse integral sadeleşmez, daha karmaşık bir ifade çıkar. Hoca bunu tercih etmiyor.
- $u = \ln^2 x$ seçilir. $du = \dfrac{2\ln x}{x}\,dx$, yani $\dfrac{\ln x}{x}\,dx = \dfrac{1}{2}du$.
- $\displaystyle\int \frac{\ln x}{x(1+\ln^2 x)}\,dx = \frac{1}{2}\int \frac{du}{1+u} = \frac{1}{2}\ln|1+u| + C$.
- Sonuç: $\dfrac{1}{2}\ln(1+\ln^2 x) + C$.
- Bir öğrenci $u = 1+\ln^2 x$ seçilebileceğini söylüyor. Bu da aynı sonucu verir.

### Örnek 3: $\displaystyle\int \frac{dx}{x(1+4\ln^2 x)}$

- $u = \ln x$, $du = \dfrac{dx}{x}$.
- $\displaystyle\int \frac{du}{1+4u^2}$ olur.
- Formülü unuttuğumuzu varsayalım: $a = 2u$, $da = 2\,du$ ile $\displaystyle\frac{1}{2}\int \frac{da}{1+a^2} = \frac{1}{2}\arctan a + C$.
- Sonuç: $\dfrac{1}{2}\arctan(2\ln x) + C$.

### Toplam sembolü

- $\displaystyle\sum_{k=1}^{n} a_k = a_1 + a_2 + \dots + a_n$.
- $k$: toplam değişkeni (summation variable). Kesikli (discrete) bir değişkendir, tam sayı değerleri alır.
- $a_k$: toplamın genel terimi.
- $n$: son terimin indisi.
- Örnek: $\displaystyle\sum_{k=1}^{n} \frac{1}{k} = 1 + \frac{1}{2} + \frac{1}{3} + \dots + \frac{1}{n}$. Bu bir sonlu toplamdır.
- Bir öğrenci "w.r.t." kısaltmasını soruyor: "with respect to" (-e göre).

### Sonlu toplamlarla alan tahmini

- $y = f(x)$ grafiğinin altında ve $[a,b]$ aralığının üstündeki bölgenin alanı aranıyor.
- Bölge yeterince küçük dikdörtgenlere bölünür. Hesaplanabilmesi için parça sayısı sonlu olmalıdır.
- Dikdörtgenlerin alanları toplanır. Bu toplam gerçek alana yaklaşır.
- Örnek: $y = x^2$, $[0,1]$.
  - İki parça (orta noktalarla): $A \approx \dfrac{1}{2}f\left(\dfrac{1}{2}\right) + \dfrac{1}{2}f(1)$ gibi.
  - Üç parça: $A \approx \dfrac{1}{3}f\left(\dfrac{1}{3}\right) + \dfrac{1}{3}f\left(\dfrac{2}{3}\right) + \dfrac{1}{3}f(1)$.
  - Parça sayısı arttıkça hata azalır, sonuç daha hassas olur.
- Bu gözlem limit kavramını kullanabileceğimizi gösterir.

### Genel bölüntü

- $[a,b]$ aralığında $n+1$ nokta alınır: $a = x_0 < x_1 < \dots < x_n = b$.
- Her alt aralık aynı uzunlukta: $n\,\Delta x = b - a$, yani $\Delta x = \dfrac{b-a}{n}$.
- $x_0 = a$, $x_1 = a + \Delta x$, $x_2 = a + 2\Delta x$, …, $x_k = a + k\,\Delta x$.
- Bunu ezberlemeye gerek yok, kolayca çıkarılır.

### Üst ve alt Riemann toplamı

- **Üst Riemann toplamı:** Dikdörtgenlerin taşan kısımları (hatalar) her zaman grafiğin üstündedir. "Üst" adı buradan gelir.
- **Alt Riemann toplamı:** Hatalar her zaman grafiğin altındadır.
- Gerçek alan, alt toplamdan büyük veya eşit, üst toplamdan küçük veya eşittir.
- $n$ arttıkça her dikdörtgenin hatası küçülür. $f$ sürekli olduğu için hataların toplamı sıfıra gider.

### Notasyonun felsefesi

- $n \to \infty$ iken $\Delta x \to dx$.
- $x_k$, $a$ ile $b$ arasındaki herhangi bir $x$'e dönüşür.
- Bu yüzden $\displaystyle\lim_{n\to\infty}\sum_{k=1}^{n} f(x_k)\,\Delta x$ yerine $\displaystyle\int_a^b f(x)\,dx$ yazılır.
- Yüksekliği $f(x)$, kalınlığı $dx$ olan bir doğru parçasının (çubuğun) alanı: $dA = f(x)\,dx$.
- Sonsuz sayıda böyle ince çubuk yan yana dizilirse bölgenin alanı bulunur: $A = \displaystyle\int_a^b dA = \int_a^b f(x)\,dx$.
- Hoca bunu belirsiz integralle ilişkilendiriyor: $\displaystyle\int du = u$ gibi, küçük parçaların ($dA$) toplamı bütünü ($A$) verir.

### Tanım: Riemann toplamı ve belirli integral

- **Riemann toplamı:** $\displaystyle\sum_{k=1}^{n} f(x_k)\,\Delta x$. Sonlu bir toplamdır, $n$'ye bağlıdır.
- **Belirli integral:** $\displaystyle\int_a^b f(x)\,dx = \lim_{n\to\infty}\sum_{k=1}^{n} f(x_k)\,\Delta x$.
  - Limitten dolayı bu bir sonsuz toplamdır.
  - $n$'den bağımsız, sabit bir değerdir.

### Örnek 4: $f(x) = x^2$, $[0,1]$

- $\Delta x = \dfrac{1}{n}$, $x_k = \dfrac{k}{n}$.
- **a) Üst Riemann toplamı:**
  - $U_n = \displaystyle\sum_{k=1}^{n} \left(\frac{k}{n}\right)^2 \frac{1}{n} = \frac{1}{n^3}\sum_{k=1}^{n} k^2$.
  - $\dfrac{1}{n^3}$, toplam değişkeni $k$'ya göre sabittir, dışarı alınır.
  - $U_n = \dfrac{n(n+1)(2n+1)}{6n^3}$. $n$'ye bağlıdır.
- **b) Alt Riemann toplamı:**
  - Son dikdörtgenin yüksekliği $f(x_{n-1})$.
  - $L_n = \displaystyle\sum_{k=0}^{n-1} \left(\frac{k}{n}\right)^2 \frac{1}{n} = \frac{1}{n^3}\left(1^2 + 2^2 + \dots + (n-1)^2\right)$.
  - Formülde $n$ yerine $n-1$ yazılır: $L_n = \dfrac{(n-1)\,n\,(2n-1)}{6n^3}$.
- **c) Belirli integral:**
  - $L_n \le A \le U_n$. İkisinin de limiti $\dfrac{2n^3}{6n^3} \to \dfrac{1}{3}$.
  - Sıkıştırma teoremiyle: $\displaystyle\int_0^1 x^2\,dx = \frac{1}{3}$.
  - Yorum: Yüksekliği $x^2$, kalınlığı $dx$ olan yeterince ince çubukları yan yana dizerseniz oluşan bölgenin alanı $\dfrac{1}{3}$'tür.
- Bir öğrenci, alt ve üst toplamların limitinin neden aynı $L$ olduğunu soruyor. Hoca: $f$ sürekli olduğu için üst ve alt hataların toplamı ($U_n - L_n$) $n\to\infty$ iken sıfıra gider.

### Örnek 5: $f(x) = x^3$, $[1,2]$, üst Riemann toplamı

- $\Delta x = \dfrac{2-1}{n} = \dfrac{1}{n}$, $x_k = 1 + \dfrac{k}{n} = \dfrac{n+k}{n}$.
- $U_n = \displaystyle\sum_{k=1}^{n} \left(\frac{n+k}{n}\right)^3 \frac{1}{n} = \frac{1}{n^4}\sum_{k=1}^{n}(k+n)^3$.
- Açılım: $(k+n)^3 = k^3 + 3k^2 n + 3k n^2 + n^3$.
- Toplam dağıtılır, $n$ içeren çarpanlar $k$'ya göre sabittir:
  - $\displaystyle\frac{1}{n^4}\left[\left(\frac{n(n+1)}{2}\right)^2 + 3n\,\frac{n(n+1)(2n+1)}{6} + 3n^2\,\frac{n(n+1)}{2} + n \cdot n^3\right]$.
- Limitte yalnız $n^4$'lü terimler önemlidir: $\dfrac{1}{4} + 1 + \dfrac{3}{2} + 1 = \dfrac{15}{4}$.
- Sonuç: $\displaystyle\int_1^2 x^3\,dx = \frac{15}{4}$.
- Kontrol: $\left[\dfrac{x^4}{4}\right]_1^2 = \dfrac{16-1}{4} = \dfrac{15}{4}$. Doğru.

### Ders sonrası notlar

- 00:23:48'de hoca $\sum k^2$ formülünü önce $n(n+1)(n+2)$ diye yazıyor, sonra "burası $2n+1$ olacak" diye düzeltiyor. Doğrusu: $\dfrac{n(n+1)(2n+1)}{6}$.
- 00:25:05'te $\sum k^3$ için "küp" diyor, sonra düzeltiyor. Doğrusu: $\left(\dfrac{n(n+1)}{2}\right)^2$, yani kare.
- 01:47:00 civarında hoca $\sum k^3$ ile $\sum k^2$ formüllerini karıştırıyor, sonra kendisi düzeltiyor. Payda eşitlerken de bir süre karışıklık yaşıyor. Ara sonuçlarda "33, 55" gibi sayılar geçiyor, sonunda 45 ve $\dfrac{15}{4}$'e ulaşıyor. Sonuç doğru.
- Üst/alt toplamın $f(x_n)$ ve $f(x_{n-1})$ ile yazılması **artan** fonksiyonlar için geçerlidir. Azalan bir fonksiyonda roller yer değiştirir. Genel tanımda üst toplam her alt aralıktaki en büyük değerle, alt toplam en küçük değerle kurulur.
- $\int \frac{dx}{1+ax^2}$ genellemesi altyazıda yarım kalıyor. Doğru formül: $\dfrac{1}{\sqrt{a}}\arctan(\sqrt{a}\,x) + C$.
- 00:38:01, 00:51:33 ve 01:33:58 civarında altyazı döngüye giriyor. Bu kısımlar altyazıda anlaşılmıyor. Sonraki cümlelerden anlatılan yer kurulabildi.
- 00:58:44 ile 01:10:26 arası ara verilmiş.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
