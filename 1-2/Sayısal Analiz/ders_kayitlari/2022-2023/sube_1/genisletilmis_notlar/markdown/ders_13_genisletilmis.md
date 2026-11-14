# Ders 13 Genişletilmiş Notu: Proje Gösterimleri (2. Hafta)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bu Kayıttan Ne Öğrenilir?
- 2. Gregory-Newton Enterpolasyonu ile Sınama
- 3. Gauss Eliminasyonu ve Gauss-Seidel
- 4. Regula Falsi ve Newton-Raphson: Dördüncü Dereceden Polinom
- 5. Matrisin Tersi ve Sıfır Pivot
- 6. Sayısal Türev
- 7. Üstel Terimli Fonksiyonda Kök Bulma
- 8. Sayısal İntegral
- 9. Uç Nokta Kök Olursa: $x^2 - 4x - 5$
- 10. Üç Kökü Olan Polinom: $x^3 - 20x + 16$
- 11. Fonksiyon Girişi ve Matematik Fonksiyonları

## 1. Bu Kayıttan Ne Öğrenilir?

Bu derste yeni konu işlenmedi. Kayıt, dönem projesi gösterimlerinden oluşuyor. Bu notta yalnız hocanın gösterim sırasında verdiği sınama örnekleri, düzeltmeler ve açıklamalar yer alıyor. Kayıtta aynı yöntemlere dönüp dönüldüğü için konular, ilk geçtikleri sıraya göre tek yerde toplandı.

Bütün gösterimlerin arkasındaki fikir basit: Bir programın çalışması, doğru sonuç verdiğini göstermez. Hoca sonuçlarını bilmek için örnekleri önceden çözdüğünü söyledi. Karmaşık bir fonksiyon girildiğinde de "nasıl test edeceğim ben bunun doğru olup olmadığını?" diye sordu. Hocanın ifadesiyle programın döngüye düşmemesi ya da hata vermemesi tek başına yetmez, gözle görülebilen bir kontrol de gerekir. Gerçek fonksiyon alınıp çıkan değer yerine konursa kök kontrol edilmiş olur.

Hoca ekrana girilen fonksiyonun, fark tablosunun ve iterasyonların yazdırılmasını da beğendi. Çünkü girişi herkes farklı alıyordu ve hoca neyin girildiğini ancak yazdırılan fonksiyondan anlayabiliyordu. Sayıların `3.000` gibi uzun biçimde yazılmasının ise okumayı zorlaştırdığını söyledi.

## 2. Gregory-Newton Enterpolasyonu ile Sınama

### 2.1 Birinci Tablo: $x = 2.2$

Hocanın en sık kullandığı tablo, $x = 0, 1, \dots, 5$ noktalarında şu değerleri veriyor: $16, -3, -16, -17, 0, 41$. İstenen değer $x = 2.2$ noktasındadır. Fark tablosu (ara adım eklendi):

| $x$ | $f$ | $\Delta f$ | $\Delta^2 f$ | $\Delta^3 f$ | $\Delta^4 f$ |
|---:|---:|---:|---:|---:|---:|
| 0 | 16 | -19 | 6 | 6 | 0 |
| 1 | -3 | -13 | 12 | 6 | 0 |
| 2 | -16 | -1 | 18 | 6 | |
| 3 | -17 | 17 | 24 | | |
| 4 | 0 | 41 | | | |
| 5 | 41 | | | | |

Üçüncü farklar sabit, dördüncü farklar sıfırdır. Aralık $h = 1$ ve $x_0 = 0$ olduğu için $s = 2.2$ alınır:

$$f(2.2) \approx 16 + 2.2(-19) + \frac{2.2 \cdot 1.2}{2}(6) + \frac{2.2 \cdot 1.2 \cdot 0.2}{6}(6) = -17.352$$

Sonuç python ile hesaplandı ve hocanın doğru kabul ettiği $-17.35$ ile uyuşuyor.

### 2.2 İkinci Tablo: Yedi Nokta

Hoca aynı tabloları tekrar vermekten sıkıldığını söyleyip yeni bir tablo verdi: $x = 0, 1, \dots, 6$ için $-4, -2, 14, 62, 160, 326, 578$. İstenen değer $x = 4$ içindi ve beklenen sonuç $160$ idi.

> **Ders sonrası not:** $x = 4$ tablonun kendi noktasıdır, $160$ değeri tabloda zaten yazıyor. Python ile hesaplandı: Formül bu noktada gerçekten $160$ veriyor, üçüncü farklar sabit ($18$). Tablo dışı bir ara değerle de denemek programı daha iyi sınar.

### 2.3 Üçüncü Tablo: $x_0 \neq 0$ ve $h \neq 1$

Hoca, "x'i sıfırdan başlatmadan Gregory-Newton verebilir miyim?" diye sorarak şu tabloyu verdi: $x_0 = 1891$, $h = 10$, değerler $46, 66, 81, 93, 101$. İstenen değer $x = 1895$ içindir.

Değişken dönüşümü $s = \dfrac{1895 - 1891}{10} = 0.4$ olur. Farklar (ara adım eklendi): $\Delta f_0 = 20$, $\Delta^2 f_0 = -5$, $\Delta^3 f_0 = 2$, $\Delta^4 f_0 = -3$.

$$f(1895) \approx 46 + 0.4(20) + \frac{0.4(-0.6)}{2}(-5) + \frac{0.4(-0.6)(-1.6)}{6}(2) + \frac{0.4(-0.6)(-1.6)(-2.6)}{24}(-3)$$

$$= 46 + 8 + 0.6 + 0.128 + 0.1248 = 54.8528$$

Python ile hesaplandı. Derste doğru kabul edilen $54.85$ ile uyuşuyor.

Bu tabloda takılan bir programı gören hoca hemen şu soruyu sordu: Program hep $x_0 = 0$ ile mi denendi? Tablo $x_0 = 0$ ile verilince de sonuç çıkmadı. Sorun daha sonra döngüde yanlış yazılmış bir yerden kaynaklandı. Yine de hocanın soruşturma biçimi akılda tutulmalı: Bir programı yalnız $x_0 = 0$ ve $h = 1$ ile sınamak yetmez.

## 3. Gauss Eliminasyonu ve Gauss-Seidel

### 3.1 Sistem ve Eliminasyonla Çözüm

Hocanın kullandığı üç bilinmeyenli sistem:

$$
\begin{aligned}
2x - 3y + 2z &= -11 \\
x + y - 2z &= 8 \\
3x - 2y - z &= -1
\end{aligned}
$$

Eliminasyon adımları (ara adım eklendi): İkinci denklemden birincinin yarısı, üçüncüden birincinin $3/2$ katı çıkarılır:

$$2.5y - 3z = 13.5, \qquad 2.5y - 4z = 15.5$$

Bu ikisinin farkından $-z = 2$, yani $z = -2$ çıkar. Geriye doğru yerine koyunca $y = \dfrac{13.5 + 3(-2)}{2.5} = 3$ ve $x = \dfrac{-11 + 3(3) - 2(-2)}{2} = 1$ bulunur. Sonuç $x = 1$, $y = 3$, $z = -2$, hocanın beklediği değerdir.

> **Ders sonrası not:** Hoca gösterimin başında bir ara "$-2, 3$ ve $1$ çıkacak" dedi; doğrusu $x = 1$, $y = 3$, $z = -2$'dir (python ile hesaplandı). $(-2, 3, 1)$ değerleri ikinci denklemi sağlamaz: $-2 + 3 - 2 = -1 \neq 8$. Ekrandaki sonuç büyük olasılıkla ters sırada yazdırılmıştı.

**Soru:** Gauss eliminasyonunda başlangıç değeri girmek gerekir mi? **Cevap:** Hoca bir programda başlangıç değerlerini sordu. Program bunları istemeden doğru sonucu verince sonuç kabul edildi. Başlangıç değeri Gauss-Seidel için gerekir; eliminasyon bunlarsız sonuç verdi.

Bir öğrenci, eliminasyonda matrisi üst üçgen hale getirip orada bıraktığını söyledi. Hoca "ondan sonrası çok kolay" dedi ve en kolay kısmın boş bırakıldığını belirtti. Yöntem, geriye doğru yerine koymayla çözüm bulununca tamamlanır.

> **Hocanın vurgusu:** Matris yöntemleri aslında kolaydır. Yapılamayan Gauss-Seidel ve eliminasyon mutlaka denenmelidir, "algoritmamız için bu çok önemli". Yapılamayan bir şey, henüz kendimizi geliştirmediğimiz bir nokta demektir.

### 3.2 Gauss-Seidel: Üç Bilinmeyenli Yakınsayan Örnek

Hocanın kullandığı başlıca örnek, köşegeni büyük verilmiş şu sistemdir:

$$
\begin{aligned}
5x - 2y + 3z &= -1 \\
-3x + 9y + z &= 2 \\
2x - y - 7z &= 3
\end{aligned}
$$

Başlangıç $(0, 0, 0)$ iken ilk adım şöyledir (ara adım eklendi):

$$x = \frac{-1}{5} = -0.2, \qquad y = \frac{2 + 3(-0.2)}{9} = 0.1556, \qquad z = \frac{3 - 2(-0.2) + 0.1556}{-7} = -0.5079$$

Python ile hesaplanan iterasyonlar:

| İterasyon | $x$ | $y$ | $z$ |
|---:|---:|---:|---:|
| 1 | -0.2000 | 0.1556 | -0.5079 |
| 2 | 0.1670 | 0.3343 | -0.4286 |
| 3 | 0.1909 | 0.3335 | -0.4217 |
| 4 | 0.1864 | 0.3312 | -0.4226 |
| 5 | 0.1861 | 0.3312 | -0.4227 |

Hocanın beklediği sonuç $0.18$, $0.33$, $-0.42$ idi. Başlangıç $(1, 1, 1)$ alınınca da aynı değerlere gidildi: Derste $0.186$, $0.33$, $-0.42$ okundu.

### 3.3 Denklem Sırası Yakınsamayı Değiştirir

Hoca bu sistemi önce köşegen düzenine dikkat etmeden verdi:

$$
\begin{aligned}
x + y + z &= 25 \\
5x + 3y + 2z &= 0 \\
y - z &= 6
\end{aligned}
$$

Program ıraksayınca hoca nedenini sordu ve bu matrisi köşegen düzenine göre vermediğini fark etti: "Eliminasyon dedim diye vermedim." Ardından denklemleri yeniden sıraladı ve şunu ekledi: "Maksimum diyagonal vermeyince nasıl ıraksadığını gördük." Doğru çözüm $x = -26.2$, $y = 28.6$, $z = 22.6$'dır. Derste bu değerler doğru kabul edildi ve python ile de doğrulandı.

<!-- BELİRSİZ: Yeniden sıralanan sistemde altyazı ikinci satırı "0, 1, 1" diye veriyor; sağ taraf 0, 6, 25 olduğu için doğrusu 0, 1, -1 olmalı. Başlangıç değerleri de iki farklı biçimde duyuluyor: -22, 30, 21 ve -24, 30, 20. -->

> **Ders sonrası not:** Hocanın yeniden sıraladığı düzen altyazıya göre $5x + 3y + 2z = 0$, $y - z = 6$, $x + y + z = 25$ idi ve ardından gelen denemede sonuç alınamadı. Python ile hesaplandı: $(-24, 30, 20)$'den başlayınca bu sıra da ıraksıyor, iterasyon matrisinin spektral yarıçapı (bkz. Bölüm 3.5) $1.13$. Son iki denklem yer değiştirilip $5x + 3y + 2z = 0$, $x + y + z = 25$, $y - z = 6$ sırası alınırsa aynı başlangıçtan 4 iterasyonda $(-26.2, 28.6, 22.6)$ değerine varılıyor. Yani köşegene yalnız en büyük elemanın gelmesi, tek başına güvence değildir.

### 3.4 İki Bilinmeyenli Örnek

Hoca aynı sistemi iki biçimde verdi. Eliminasyon için:

$$2x + 5y = 16, \qquad 3x + y = 11$$

Gauss-Seidel için ise köşegen büyük olacak şekilde "maximum diagonal yaparak":

$$3x + y = 11, \qquad 2x + 5y = 16$$

Çözüm $x = 3$, $y = 2$'dir. Python ile hesaplanan iterasyonlar, başlangıç $(2, 1)$ ve $(0, 0)$ için:

| İterasyon | $(2, 1)$'den $x$ | $(2, 1)$'den $y$ | $(0, 0)$'dan $x$ | $(0, 0)$'dan $y$ |
|---:|---:|---:|---:|---:|
| 1 | 3.3333 | 1.8667 | 3.6667 | 1.7333 |
| 2 | 3.0444 | 1.9822 | 3.0889 | 1.9644 |
| 3 | 3.0059 | 1.9976 | 3.0119 | 1.9953 |
| 4 | 3.0008 | 1.9997 | 3.0016 | 1.9994 |

Derste ekranda okunan $3$ ve $1.99$ değerleri doğru kabul edildi. Tablo da değerlerin $3$ ve $2$'ye adım adım yaklaştığını gösteriyor. Hoca hata değerini öğrencilere bıraktı: "Hatayı kendiniz verin."

### 3.5 Maksimum Köşegeni Program Kendisi Bulabilir mi?

**Soru:** Bir öğrenci, satırları programın kendisinin sıralamasını istedi ama takıldı. **Cevap:** Hoca kuralı "sayısı en yüksek olanı birinci sıraya koyacaksın" diye özetledi. Öğrenci, birinci sıraya aldığı satırın ikinci sütununun da büyük çıkabildiğini, bu durumda kontrolün zorlaştığını söyledi.

Aynı konuda bir öğrenci şu gözlemi anlattı: Bölüm 3.1'deki sistemde iterasyon önce çözüme yaklaşıyor, sonra uzaklaşıyordu. Hata $0.2$ verilince kökleri yaklaşık buluyordu. Öğrencinin kullandığı denklem sırası altyazıda görülmüyor, büyük olasılıkla her sütunun en büyük elemanını köşegene alan sıradır: $3x - 2y - z = -1$, $2x - 3y + 2z = -11$, $x + y - 2z = 8$. Bu sırada aynı davranış python ile hesaplandı:

| İterasyon | $x$ | $y$ | $z$ | Önceki adıma en büyük fark |
|---:|---:|---:|---:|---:|
| 2 | 1.148 | 2.802 | -2.025 | 1.481 |
| 3 | 0.860 | 2.890 | -2.125 | 0.288 |
| 4 | 0.885 | 2.840 | -2.137 | 0.050 |
| 5 | 0.848 | 2.807 | -2.173 | 0.037 |
| 6 | 0.814 | 2.761 | -2.213 | 0.046 |
| 8 | 0.715 | 2.635 | -2.325 | 0.070 |

İterasyon $(1, 3, -2)$ yakınına gelip oradan uzaklaşıyor. Fark en az $0.037$'ye indiği için $\varepsilon = 0.01$ ile durmuyor, $\varepsilon = 0.2$ ile 4. adımda duruyor.

> **Ek bilgi (derste anlatılmadı):** Gauss-Seidel'in yakınsaması, iterasyon matrisinin spektral yarıçapının $1$'den küçük olmasına bağlıdır. Her satırda köşegen elemanı öteki elemanların mutlak toplamından büyükse (kesin köşegen baskınlık) yakınsama güvencelidir. Bölüm 3.1'deki sistem hiçbir sıralamada bu koşulu sağlamaz. Python ile hesaplandı: Sırası verildiği gibi olan düzende spektral yarıçap $11.30$, sütun en büyükleriyle kurulan düzende $1.24$, $2x - 3y + 2z$, $3x - 2y - z$, $x + y - 2z$ sırasında ise $0.61$'dir. Bu üç düzenden yalnız sonuncusunda iterasyon yakınsar.

## 4. Regula Falsi ve Newton-Raphson: Dördüncü Dereceden Polinom

### 4.1 Regula Falsi

Hocanın fonksiyonu $f(x) = x^4 - 9x^3 - 2x^2 + 120x - 130$, aralık $[1, 2]$, hata $0.001$. Uçlarda $f(1) = -20$ ve $f(2) = 46$ olduğu için işaret değişiyor. İlk adım (ara adım eklendi):

$$c = \frac{a f(b) - b f(a)}{f(b) - f(a)} = \frac{1(46) - 2(-20)}{46 - (-20)} = \frac{86}{66} = 1.3030$$

Python ile hesaplanan ardışık kökler: $1.3030$, $1.2336$, $1.2289$, $1.2286$. Derste ekranda $1.23$ okundu ve doğru kabul edildi.

> **Ders sonrası not:** Hoca kendi çözümündeki değeri bir yerde $1.218$, başka yerde $1.21$ olarak okudu; doğrusu $1.2286$'dır (python ile hesaplandı). Hocanın değerleri köke yakındır ama kökün kendisi değildir.

**Soru:** Herkes neden ikiye bölmeyi seçiyor? Hoca bu soruyu sordu. **Cevap:** Bir öğrenci en basit yöntem olduğu için olabileceğini, kod yazarken de iki yöntem arasında yalnız bir satırın değiştiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Söz edilen tek satır, yeni noktanın hesabıdır. İkiye bölmede $c = (a + b)/2$, regula falsi'de ise yukarıdaki doğrusal kesişim formülü kullanılır. Aralığı daraltan $f(a) f(c)$ işaret kontrolü iki yöntemde aynıdır.

### 4.2 Durma Koşulu

Hoca hatayı sıkça $0.01$ ya da $0.001$ olarak verdi. Mutlak fark mı yoksa başka bir ölçüt mü kullanılacağı sorulunca "neye bakarsan bak" dedi. Başka bir yerde de "durma koşulunu sen kendin ver, kiminiz iterasyon veriyorsunuz, kiminiz bir şey" dedi. Yani derste tek bir ölçüt dayatılmadı. Sabit sayıda döngüyle çalışan bir regula falsi de kabul edildi.

### 4.3 Eksi İşareti Nereye Gitti? Newton-Raphson

Hoca aynı polinomu Newton-Raphson için verdi, $x_0 = 1$, $\varepsilon = 0.01$ ile. Ekranda $-1.2$ çıktı, hocanın notlarında ise $1.21$ vardı. Başka bir öğrencinin programı da $-1.2$ verince hoca "o zaman ben bunu buraya koymadım demektir" dedi, yani kendi çözümünde eksiyi yazmayı unuttuğunu düşündü.

> **Ders sonrası not:** Hoca eksiyi kendi notunda unuttuğunu düşündü; doğrusu iki sonuç iki farklı polinoma aittir. Altyazıda sabit terim bu denemede "$130$" diye artı okunuyor. Python ile hesaplandı: $x^4 - 9x^3 - 2x^2 + 120x + 130$ için $x_0 = 1$'den başlayan iterasyon $-1.5806$, $-1.0492$, $-1.1994$, $-1.2094$ değerlerinden geçip $-1.2095$'e gidiyor. $x^4 - 9x^3 - 2x^2 + 120x - 130$ için ise $1.2151$, $1.2285$ üzerinden $1.2286$'ya gidiyor. Yani hocanın notundaki pozitif kök eksi $130$'lu polinoma, ekrandaki negatif kök artı $130$'lu polinoma aittir. Sabit terimin işareti büyük olasılıkla dikte sırasında değişti.

Hoca bu polinomun dört kökü olduğunu da hatırlattı. Python ile hesaplanan kökler eksi $130$'lu polinom için $-3.6001$, $1.2286$, $3.9721$, $7.3995$'tir.

## 5. Matrisin Tersi ve Sıfır Pivot

### 5.1 Sınama Matrisi

Hocanın en çok kullandığı matris:

$$A = \begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \\ 7 & 2 & 9 \end{bmatrix}$$

Python ile hesaplandı: $\det A = -36$ ve

$$A^{-1} = \frac{1}{-36}\begin{bmatrix} 33 & -12 & -3 \\ 6 & -12 & 6 \\ -27 & 12 & -3 \end{bmatrix} = \begin{bmatrix} -0.9167 & 0.3333 & 0.0833 \\ -0.1667 & 0.3333 & -0.1667 \\ 0.75 & -0.3333 & 0.0833 \end{bmatrix}$$

Hoca ekranı kontrol ederken elemanları sırayla okudu, küsuratlıları kesir olarak da denetledi: $3/4 = 0.75$ ve $1/6 \approx 0.17$.

### 5.2 Dört Boyutlu Matris: Determinant Sıfır Değilse Bile

Hoca dört boyutlu şu matrisin tersini istedi:

$$B = \begin{bmatrix} 1 & 3 & 5 & 9 \\ 1 & 3 & 1 & 7 \\ 4 & 3 & 9 & 7 \\ 5 & 2 & 0 & 9 \end{bmatrix}$$

Program "determinant sıfır" uyarısı verdi. Hoca kendi elinde sonuç olduğunu, yani tersin bulunduğunu söyledi, ardından determinantın sıfır olup olmadığı kontrol edilmesi gerektiğini belirtti. Determinant yazdırılınca sonuç `NaN` çıktı.

**Soru:** Determinant sıfır olmadığı halde neden `NaN` çıkıyor? **Cevap:** Bir öğrenci "determinant sıfır olmasa bile sıfıra bölünce `NaN` çıktığı için bazen öyle sonuç verebiliyor" dedi. Hoca "doğrudur" diye onayladı.

Python ile hesaplandı: $\det B = -376$, yani $B$ terslenebilir. İkinci satırdan birinci çıkarılınca $[0, 0, -4, -2]$ elde edilir. Yani ikinci pivot sıfır olur. Satır değiştirmeyen bir program burada sıfıra böler. Derste görülen `NaN` büyük olasılıkla buradan geliyordu.

> **Ek bilgi (derste anlatılmadı):** Sıfır pivot, determinantın sıfır olduğu anlamına gelmez. Pivot sıfırsa altındaki satırlardan sıfır olmayan bir satırla yer değiştirilir. Sütunun tamamı sıfırsa matris tekildir. Tekil matrisin tersi yoktur, çünkü $A^{-1} = \mathrm{adj}(A)/\det(A)$ formülünde paydada determinant bulunur.

Hocanın sonucu: Ters almadan önce determinantın sıfır olup olmadığı kontrol edilmelidir. Hoca bu matrisi ilk kez verdiğini de söyledi. Önceki örneklerde çalışan bir program, ilk kez gördüğü bir matriste hata verebilir.

## 6. Sayısal Türev

### 6.1 Kağıt Üzerinde Kontrol

Hoca bir türev programını sınamak için $f(x) = x^3 - x^2 - x - 1$ fonksiyonunu verdi: $x = 1$, $h = 0.25$. Ekrandaki sonuç ($7.56$) için "ne ilerisi ne gerisi, hiçbiriyle uyuşmuyor" diyen hoca, "matematik dersinde olduğunu düşün" diyerek analitik türevi aldırdı:

$$f'(x) = 3x^2 - 2x - 1, \qquad f'(1) = 0$$

Python ile hesaplanan fark değerleri (ara adım eklendi): $f(0.75) = -1.890625$, $f(1) = -2$, $f(1.25) = -1.859375$.

- İleri fark: $\dfrac{-1.859375 + 2}{0.25} = 0.5625$
- Geri fark: $\dfrac{-2 + 1.890625}{0.25} = -0.4375$
- Merkezi fark: $\dfrac{-1.859375 + 1.890625}{0.5} = 0.0625$

Ekrandaki $7.56$ bu değerlerin hiçbirine yakın değildir, analitik türev de $0$ çıkar.

### 6.2 Hocanın Ana Örneği

Fonksiyon $f(x) = -0.1x^4 - 0.15x^3 - 0.5x^2 - 0.25x + 1.2$, $x = 1$, $h = 0.25$. Hoca analitik türevi elle hesapladı:

$$f'(1) = -0.4 - 0.45 - 1 - 0.25 = -2.10$$

Python ile hesaplanan ara değerler: $f(0.75) = 0.636328$, $f(1) = 0.2$, $f(1.25) = -0.430859$.

| Yöntem | İşlem | Sonuç | Gerçek değerden fark |
|:---|:---|---:|---:|
| İleri | $(-0.430859 - 0.2)/0.25$ | $-2.5234$ | $0.4234$ |
| Geri | $(0.2 - 0.636328)/0.25$ | $-1.7453$ | $0.3547$ |
| Merkezi | $(-0.430859 - 0.636328)/0.5$ | $-2.1344$ | $0.0344$ |

İleri ve merkezi farkın farklı sonuç vermesi için hoca "bu normal" dedi. Derste okunan $-2.52$ ve $-2.134375$ değerleri tablodakilerle aynıdır.

### 6.3 Yanlış Fonksiyonla Sınama

Hoca bir ara $-0.4x^3 - 0.45x^2 - x - 0.25$ fonksiyonunu verdi. Çıkan değerler elindeki sonuçla uyuşmayınca nedenini kendisi buldu: "Ben demin türevi vermiştim." Yani $f(x)$ yerine türevini dikte etmişti.

> **Ders sonrası not:** Python ile hesaplandı: Bu fonksiyon için $x = 1$, $h = 0.25$'te ileri fark $-3.5375$, geri fark $-2.7125$, merkezi fark $-3.125$'tir. Derste okunan $-3.125$ ve $-3.5375$ değerleri bununla uyuşuyor. Programlar doğru çalışmış, uyuşmazlık fonksiyonun yanlış verilmesinden çıkmıştır.

## 7. Üstel Terimli Fonksiyonda Kök Bulma

Hoca polinom dışı fonksiyon sınamak için $f(x) = 4e^{-0.5x} - x$ fonksiyonunu verdi. Newton-Raphson için $x_0 = 2$, hata $0.001$. İkiye bölmeyle de aralık verilerek denendi. Newton adımı için (ara adım eklendi):

$$f'(x) = -2e^{-0.5x} - 1, \qquad x_1 = 2 - \frac{-0.5285}{-1.7358} = 1.6955$$

Python ile hesaplanan sonraki adımlar $1.70520$ ve $1.70521$'dir. İkiye bölme de $[0, 2]$ aralığında aynı değere gidiyor.

> **Ders sonrası not:** Hoca kendi sonucunun $1.68$ olduğunu, ekrandaki $1.7$'nin ise $e$ sayısının $2.718$ gibi alınmasından geldiğini söyledi; doğrusu kök $1.7052$'dir (python ile hesaplandı). $e = 2.718$ alınınca kök yalnız $1.70529$'a kayıyor, dolayısıyla fark buradan çıkmaz. $f(1.68) = 0.047$ iken $f(1.7052) \approx 0$ olduğu için ekrandaki sonuç doğrudur. Hocanın $1.68$ değeri büyük olasılıkla elle çözümde kalmış bir ara değerdir.

Bölüm 1'deki kontrol burada işe yarıyor: Bulunan değeri fonksiyona koymak hangi değerin kök olduğunu hemen gösterir.

Aralıkla çalışan yöntemler için derste şu da söylendi: Uygun aralık verilmezse program kökü bulamadığını söyler.

## 8. Sayısal İntegral

### 8.1 Birinci Örnek

Fonksiyon $f(x) = 400x^5 - 900x^4 + 675x^3 - 200x^2 + 25x + 0.2$, aralık $[0, 0.8]$. Simpson 1/3 için hoca aralık sayısını "çift bir sayı alalım" diyerek $n = 10$ seçti.

Python ile hesaplandı: Simpson 1/3 sonucu $1.6401$, analitik değer $1.6405$'tir. Derste okunan "$1.64$" doğru kabul edildi.

### 8.2 İkinci Örnek

Fonksiyon $f(x) = x^2 + 2x$, aralık $[1, 3]$, $n = 6$. Analitik değer:

$$\int_1^3 (x^2 + 2x)\,dx = \left[\frac{x^3}{3} + x^2\right]_1^3 = 18 - \frac{4}{3} = 16.6667$$

Python ile hesaplanan sonuçlar: Trapez $16.7037$, Simpson 1/3 ve Simpson 3/8 ise $16.6667$. Derste Simpson'ın iki biçiminin aynı sonucu verdiği, ekranda $16.66$ göründüğü söylendi. Trapez için derste "on altı nokta" diye okunan değer de $16.7037$ ile çelişmiyor.

### 8.3 Üçüncü Örnek

Fonksiyon $f(x) = 2x^5 - 3x^2 + 3$, aralık $[1, 4]$, $n = 6$, dolayısıyla $h = 0.5$. Analitik değer:

$$\int_1^4 (2x^5 - 3x^2 + 3)\,dx = \left[\frac{x^6}{3} - x^3 + 3x\right]_1^4 = 1313.3333 - 2.3333 = 1311$$

Python ile hesaplanan sonuçlar:

| Yöntem | Sonuç | Hata |
|:---|---:|---:|
| Trapez | $1363.59$ | $52.59$ |
| Simpson 1/3 | $1311.63$ | $0.63$ |
| Simpson 3/8 | $1312.41$ | $1.41$ |

Derste trapez için $1363$, Simpson için $1311$ doğru kabul edildi.

> **Ders sonrası not:** Derste Simpson 3/8 ile $1311$ çıktığı söylendi; doğrusu bu kuralla $n = 6$ için $1312.41$'dir (python ile hesaplandı). $1311$, Simpson 1/3 sonucunun tam kısmıyla ve analitik değerle uyuşuyor. Ekrandaki değer büyük olasılıkla 1/3 kuralına aitti.

<!-- BELİRSİZ: 01:57 civarında Simpson 3/8 sonucu altyazıda yalnız "bin üç yüz on bir" diye okunuyor; ondalık kısım duyulmuyor. -->

## 9. Uç Nokta Kök Olursa: $x^2 - 4x - 5$

Hoca regula falsi için $f(x) = x^2 - 4x - 5$ fonksiyonunu verdi. Kökleri $x = -1$ ve $x = 5$'tir. Üç farklı aralıkla denendi.

**Aralık $[-1, 5]$:** Program "ikisi de pozitif" dedi. Hoca hesabı yaptı: $f(5) = 25 - 20 - 5 = 0$. Yani verilen uçlardan biri zaten köktür ("verdiklerimden bir tanesi kök"), öteki de öyle: $f(-1) = 0$. Program sıfırı kontrol etmediği için durumu yanlış adlandırdı.

Hoca bu yüzden sıfır durumunun da kontrol edilmesi gerektiğini söyledi.

**Aralık $[-5, 6]$:** Program yine hata verdi. Hoca önce programdan şüphelendi, ama öğrenciler uyardı: "İkisi de pozitif ya da ikisi de negatif olabilir." Hesap: $f(-5) = 40$, $f(6) = 7$. İki değer de pozitif, yani program haklıdır.

**Aralık $[-3, 0]$:** Bu kez $f(-3) = 16$, $f(0) = -5$ ve işaret değişiyor. Program $-1$ buldu. Python ile hesaplanan ardışık değerler ($\varepsilon = 0.01$): $-0.7143$, $-0.9259$, $-0.9813$, $-0.9953$, $-0.9988$.

> **Ek bilgi (derste anlatılmadı):** $[-5, 6]$ aralığında iki kök vardır, yine de uçlarda işaret aynıdır. Çünkü aralıkta katlılıklarıyla çift sayıda kök varsa uçlardaki işaret aynı kalır. Bu yüzden $f(a) f(b) > 0$ kontrolü "aralıkta kök yoktur" demeyi güvenceye almaz, yalnız "bu aralıkla kapalı yöntem başlatılamaz" demek doğrudur.

Aynı fonksiyon Newton-Raphson ile $x_0 = 0$, $\varepsilon = 0.001$ için de çözüldü, sonuç $-1$'dir. Python ile hesaplanan adımlar: $-1.25$, $-1.0096$, $-1.00002$, $-1.0000$.

## 10. Üç Kökü Olan Polinom: $x^3 - 20x + 16$

### 10.1 Regula Falsi

Aralık $[3, 5]$, hata $0.001$. Uçlarda $f(3) = -17$, $f(5) = 41$. İlk adım (ara adım eklendi): $c = \dfrac{3(41) + 5(17)}{58} = 3.5862$. Python ile hesaplanan adımlar: $3.5862$, $3.8545$, $3.9522$, $3.9847$, $3.9951$, $3.9985$, $3.9995$, $3.9998$. Gerçek kök $x = 4$'tür, çünkü $64 - 80 + 16 = 0$. Derste okunan $3.99$ bu nedenle kabul edildi.

### 10.2 Newton-Raphson ve Aralık Sorusu

**Soru:** Newton-Raphson'da alt ve üst sınır nedir? **Cevap:** Hoca, "nereden nereye diye bir şey var mı Newton-Raphson'da?" diye sordu. Newton-Raphson'da aralık yoktur, yalnız başlangıç değeri verilir. Ortak bir fonksiyon verirken de şu ayrımı yaptı: Newton seçilirse aralığın arasından bir değer alınır, öteki yöntemlerde alt ve üst sınır verilir.

$x_0 = 2$ ile çözümde ekranda $0.8284$ göründü. Hocanın elinde bu kök yoktu, bu yüzden kontrolü yerine koyarak yaptı: $x = 1$ için $1 - 20 + 16 = -3$ eder. Sonucu da "üç taneden biri olabilir" diyerek kabul etti. Python ile hesaplandı: Kökler $-4.8284$, $0.8284$, $4$'tür. $x_0 = 2$'den başlayan iterasyon $0$, $0.8$, $0.8283$, $0.8284$ değerlerinden geçer.

$x_0 = 0$ ile denenince iki programda birden "ıraksadı" iletisi çıktı. Hoca "nasıl ıraksar ki?" diye sordu ve programda hata olabileceğini söyleyip kodun izlenmesini istedi: "Trace edersiniz."

> **Ders sonrası not:** Hocanın şüphesi doğrudur. Python ile hesaplandı: $x_0 = 0$'dan başlayan iterasyon $0.8$, $0.8283$, $0.8284$ değerleriyle 3 adımda yakınsar. "Iraksadı" iletisi yöntemden değil, programdan geliyordu. Nedeni altyazıda görülmüyor.

## 11. Fonksiyon Girişi ve Matematik Fonksiyonları

**Soru:** Polinom dışı fonksiyonların kodlanmasından ne kastedildi? **Cevap:** Hoca fonksiyonun içine yalnız polinom vermeyeceğini, örneğin $\sin x + 5x \cos x$ gibi bir ifade de verebileceğini söyledi.

**Soru:** Logaritma ve üstel gibi fonksiyonları `math.h` kullanmadan Taylor serisiyle yazmak gereksiz mi? **Cevap:** Hoca bunun "çok low seviye" olduğunu, ama uğraşan kişinin kendisinin kazandığını söyledi. Öğrenci aynı zamanda bir zorluk da anlattı: Hata çıktığında hatanın kendi matematik fonksiyonundan mı yoksa yöntemden mi geldiğini ayırt edemiyordu.

Polinomu metin olarak alıp ayrıştıran bir öğrenci, sabit terimin ifadenin ortasında olabilmesinin kodu çok karıştırdığını anlattı: $4 - 2x^2 + 5$ gibi. Hocanın cevabı netti: Böyle bir fonksiyon yazılmaz, $4$ ile $5$ toplanıp $9$ yazılır. Polinomun normal biçimi tek sabit terim içerir. Bu yüzden girdi biçimi için fazla kod yazmaya gerek yoktur.

## Dersin Toparlaması

Bu kayıt yöntemleri yeniden anlatmıyor, onları test etmeyi gösteriyor. Temel dersler şunlar: Bilinen bir sonuçla ya da bulunan değeri yerine koyarak sınamak, kapalı yöntemlerde uç noktanın kök olma durumunu ve aynı işaretli uçları ayrı ele almak, Gauss-Seidel'de denklem sırasına dikkat etmek, sıfır pivot ile sıfır determinantı karıştırmamak ve kodu yalnız $x_0 = 0$, $h = 1$ gibi kolay girdilerle denememek. Eliminasyon da geriye doğru yerine koyma yapılmadan bitmiş sayılmaz.

Notta geçen sınama girdileri kendi kodunuzu denemek için kullanılabilir. Sonuç farklı çıkarsa önce girilen işaretleri kontrol edin. Bu kayıtta birkaç uyuşmazlığın kaynağı kod değil, sabit terimin işareti ya da yanlış verilmiş fonksiyondu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
