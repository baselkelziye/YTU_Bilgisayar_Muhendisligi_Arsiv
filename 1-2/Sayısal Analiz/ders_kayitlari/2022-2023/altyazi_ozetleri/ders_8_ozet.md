# Ders 8 Çalışma Özeti

## Genel Konular

- Sınav ve takvim duyuruları
  - Birinci vize gelecek hafta, pazartesi saat 17:00'de (hoca "26 Nisan" dedi, ama pazartesi gününe alındığını da söyledi). Çakışan dersleri alan öğrenciler nedeniyle bu güne konulmuş.
  - Vize çoktan seçmeli test. Süre 1 saat veya 1 saat 15 dakika, 15 ya da 20 soru. Kimi soru yarım dakika, kimi iki dakika sürer, 5 dakikalık soru olmaz. Kağıt kalem yine gerekecek ama satırlarca işlem yok. Bazı sorular derste "buna dikkat edin" denen noktalardan gelir.
  - Önceki sorulara geri dönülebilecek (hoca, Ahmet Hoca'yı buna ikna etti). Bir sorunun birden fazla doğru cevabı olup olmayacağı sınav başında söylenecek.
  - Vize konuları sonlu farklara kadardır. Sonlu farklar tek başına sorulmaz. Enterpolasyon vizeye dahil değil.
  - Bölümdeki sınav programlarında süre yazmaz. Kural: süre 2 saati aşmaz, hoca soruların zorluğuna göre belirler. Online sistemde süre bitince sınav kapanır.
  - Takvim: 3 Mayıs ve 10 Mayıs ders. 17 Mayıs: bitirenlerin projelerine bakılmaya başlanır, ikinci vize de bu hafta (ders saatinde mi akşam mı, Yapısal Programlama'nın planına göre belli olacak). 24 ve 31 Mayıs: proje gösterimleri.
  - İkinci vizede ağırlık farklar, enterpolasyon ve regresyonda olacak. Final klasik olacağı için vizelerde de soruları kendi gayretinizle çözün. İki vizeye iyi çalışan finalde sadece hızlıca tekrar eder.
  - Bu hafta Ramazan Bayramı. Vize haftası ders yok. Vizeden sonra ders yine online/hibrit ve slayt üzerinden devam edecek.
  - "Ben sizlere güveniyorum, siz de benim güvenimi boşa çıkarmayın."
- Sonlu farklar tekrarı
  - İleri fark $\Delta f_i = f_{i+1} - f_i$. $\Delta^2 f_i = f_{i+2} - 2f_{i+1} + f_i$, $\Delta^3 f_i = f_{i+3} - 3f_{i+2} + 3f_{i+1} - f_i$. Katsayılar binom, işaretler artı-eksi. İleri farkta büyük indis başta, $f_i$ sonda.
  - Geri fark $\nabla f_i = f_i - f_{i-1}$. Burada $f_i$ başta, indis azalarak gider. "Büyük olan solda" diye hatırlanabilir.
  - Genel formül: $\Delta^k f_i = \sum_{j=0}^{k} (-1)^j \binom{k}{j} f_{i+k-j}$. Örnek $\Delta^5 f_0$: katsayılar 1, 5, 10, 10, 5, 1.
  - Fark tablosu bir sütun sabitlenene (veya sıfırlanana) kadar devam eder. Sonraki sütunlar sıfır olur ve çarpan olarak etkisizdir.
  - Bir ölçümdeki $\varepsilon$ hatası tabloda binom katsayılarıyla büyür. Son sütun sıfıra gitmiyorsa ölçümleri ve işlemleri kontrol edin. 0.01 gibi küçük değerler yuvarlamadan gelebilir, önemsenmez.
  - Enterpolasyonda $x$ değerleri her zaman eşit aralıklı olmayabilir ve $x_0$ sıfırdan başlamayabilir. Bu durumlar için değişken dönüşümü görülecek.
- Enterpolasyon
  - Tanım: tablo hâlinde değerleri verilen bir değişkenin tabloda olmayan bir değerini bulmak. Ölçümü yapılmamış bir girdi için çıktıyı tahmin etmek.
  - $x_0, \ldots, x_n$ noktalarında $f_0, \ldots, f_n$ değerleri bilinen gerçek fonksiyon $f(x)$, daha basit ve bilinen bir $F(x)$ enterpolasyon fonksiyonuyla ifade edilir. Amaç $|F(x) - f(x)| \le \varepsilon$.
  - $F(x)$ bir polinom, üstel veya trigonometrik fonksiyon olabilir. Hangisinin uygun olduğu baştan bilinmez. Verinin dağılımına bakılır, birkaç fonksiyon denenir, en az hatayı veren seçilir. Alanında deneyimli biri hangi fonksiyonun iyi çalıştığını bilir. Sınavda ve ödevde hangi fonksiyonun geçirileceği söylenecek.
  - $f$, $[a, b]$ kapalı aralığında sürekliyse enterpolasyon fonksiyonu olarak polinom kullanılır.
  - $f$ periyodu $2\pi$ olan sürekli bir fonksiyonsa trigonometrik bir fonksiyon kullanılır: $F(x) = \sum_{k=0}^{n} a_k \cos kx + \sum_{k=1}^{n} b_k \sin kx$.
- Doğrusal enterpolasyon (eğim ile)
  - İki noktadan geçen doğru üzerindeki bütün nokta çiftlerinin eğimi eşittir. Bilinen iki noktanın eğimi, bilinmeyen nokta ile bilinen noktalardan birinin eğimine eşitlenir:
    - $\frac{f(x_2) - f(x_1)}{x_2 - x_1} = \frac{f(x_3) - f(x_1)}{x_3 - x_1}$
  - Örnek: tablo $x$: −2, −1, 0, 1, 3, 4, 6, $f$: −0.909297, −0.841471, 0, 0.841471, 0.141120, −0.756802, −0.279415.
    - a) $f(2)$, $x = 1$ ve $x = 3$ ile: $\frac{0.141120 - 0.841471}{2} = \frac{f(2) - 0.841471}{1}$, $f(2) = 0.4912955$.
    - b) $f(2)$, $x = -2$ ve $x = 6$ ile: $\frac{f(6) - f(-2)}{6 - (-2)} = \frac{f(2) - f(6)}{2 - 6}$.
  - Bu yöntem bir fonksiyon bulmaz. Yalnızca istenen noktadaki değeri tahmin eder. "Bu noktalardan geçen fonksiyon nedir?" sorusu için kullanılamaz.
- Doğrusal enterpolasyon (doğru denklemi ile)
  - $F(x) = Ax + B$. Aralığın uçlarında gerçek değerlere eşitlenir: $Aa + B = f(a)$, $Ab + B = f(b)$.
  - İki denklem, iki bilinmeyen: $A = \frac{f(a) - f(b)}{a - b}$, $B$ denklemlerden birine yerine konarak bulunur.
  - Bu kez elimde bir fonksiyon vardır, istenen her $x$ yerine konabilir.
  - Örnek: $(2, 5)$ ve $(6, 13)$ noktaları. $A = \frac{5 - 13}{2 - 6} = 2$, $B = \frac{6 \cdot 5 - 2 \cdot 13}{6 - 2} = 1$. $F(x) = 2x + 1$. Gerçek fonksiyon da $2x + 1$ olduğu için hata sıfırdır. $F(10) = 21$, $F(-5) = -9$.
- Eğrisel (kuadratik) enterpolasyon
  - İkinci dereceden polinom $y = ax^2 + bx + c$ için üç nokta gerekir.
  - 1. yol: üç noktayı yerine koyup üç denklem, üç bilinmeyen çözülür. Derece arttıkça (ör. 10. derece) 10 denklem, 10 bilinmeyen çözmek gerekir. Pratik değildir.
  - 2. yol: $f(x) = b_0 + b_1(x - x_0) + b_2(x - x_0)(x - x_1)$.
    - $b_0 = f(x_0)$.
    - $b_1 = \frac{f(x_1) - f(x_0)}{x_1 - x_0}$ ($x_0$ ile $x_1$ arasındaki eğim).
    - $b_2 = \frac{\frac{f(x_2) - f(x_1)}{x_2 - x_1} - \frac{f(x_1) - f(x_0)}{x_1 - x_0}}{x_2 - x_0}$.
    - Derece arttıkça yeni terimler ($b_3$, $b_4$…) eklenir ve iş çok karışır.
  - Örnek: $(1, -2)$, $(2, -1)$, $(3, 4)$, $x = 2.5$.
    - $b_0 = -2$, $b_1 = \frac{-1 - (-2)}{2 - 1} = 1$, $b_2 = \frac{\frac{4 - (-1)}{3 - 2} - \frac{-1 - (-2)}{2 - 1}}{3 - 1} = 2$.
    - $f(x) = -2 + (x - 1) + 2(x - 1)(x - 2) = 2x^2 - 5x + 1$. $f(2.5) = 1$.
  - Bu zahmetten kurtulmak için Gregory-Newton enterpolasyonu geliştirilmiştir.
- Gregory-Newton (ileri fark) enterpolasyonu
  - Eşit aralıklı noktalar için: $F(x) = f_0 + \sum_{i=1}^{n} \binom{k}{i} \Delta^i f_0$, $k = \frac{x - x_0}{h}$.
  - $\binom{k}{i} = \frac{k(k-1)\cdots(k-i+1)}{i!}$ olarak açılır.
  - $\Delta f_0, \Delta^2 f_0, \ldots$ fark tablosunun ilk satırından alınır.
  - $k$ yerine konup düzenlenince genel formül:
    - $F(x) = f_0 + \frac{x - x_0}{h}\Delta f_0 + \frac{(x - x_0)(x - x_1)}{2!\,h^2}\Delta^2 f_0 + \frac{(x - x_0)(x - x_1)(x - x_2)}{3!\,h^3}\Delta^3 f_0 + \ldots$
  - $x_0 = 0$ ve $h = 1$ ise formül en basit hâline gelir:
    - $F(x) = f_0 + x\,\Delta f_0 + \frac{x(x-1)}{2!}\Delta^2 f_0 + \frac{x(x-1)(x-2)}{3!}\Delta^3 f_0 + \ldots$
  - $x_0 \ne 0$ ise formüldeki $x_0$'lar kalır. $h \ne 1$ ise $h$'ler kalır ($h$, $h^2$, $h^3$…). Hoca bunun yerine tabloyu $x_0 = 0$, $h = 1$ olacak şekilde dönüştüren bir değişken dönüşümü kullanacak (vizeden sonra).
  - Örnek: $x$: 0, 1, 2, 3, 4, 5, 6, $f$: −4, −2, 14, 62, 160, 326, 578. $x_0 = 0$, $h = 1$.
    - $\Delta f$: 2, 16, 48, 98, 166, 252. $\Delta^2 f$: 14, 32, 50, 68, 86. $\Delta^3 f$: 18, 18, 18, 18. Üçüncü fark sabit.
    - $F(x) = -4 + 2x + \frac{x(x-1)}{2} \cdot 14 + \frac{x(x-1)(x-2)}{6} \cdot 18$.
    - Düzenlenince $F(x) = 3x^3 - 2x^2 + x - 4$. Kontrol: $F(0) = -4$, $F(1) = -2$, $F(6) = 578$.
    - 3. fark sabitlendiği için fonksiyon 3. dereceden olmak zorundadır.
    - $x = 3.5$ sorulursa formülde yerine koymak yeter.
- Ders planı: vizeden sonra Gregory-Newton'a bir örnekle devam edilecek, değişken dönüşümü ve özel durumlar anlatılacak. Ardından Lagrange enterpolasyonu ve regresyon.

## Hocanın Özellikle Vurguladığı Kısımlar

- Vize: test, 15-20 soru, 1 saat ile 1 saat 15 dakika arası. Konular sonlu farklara kadar, enterpolasyon dahil değil.
- Final klasik. Vizelerde soruları kendi gayretinizle çözün, yoksa finalde bocalarsınız.
- Eğimle yapılan doğrusal enterpolasyon fonksiyon vermez, yalnızca bir noktadaki değeri tahmin eder. Fonksiyon isteniyorsa doğru denklemi kurulur.
- Gregory-Newton formülünün nasıl çıkarıldığını bilin, ama asıl gereken son hâlidir. $x_0 = 0$ ve $h = 1$ ise en basit formül kullanılır.
- Fark tablosunda hangi sütun sabitlenirse polinomun derecesi odur.
- Projelere başlamayanlar acele etsin.

## Kısa Tekrar Notları

- Eğimle doğrusal enterpolasyon: $\frac{f_2 - f_1}{x_2 - x_1} = \frac{f(x) - f_1}{x - x_1}$.
- Doğru: $F(x) = Ax + B$, $A = \frac{f(a) - f(b)}{a - b}$.
- Kuadratik: $f(x) = b_0 + b_1(x - x_0) + b_2(x - x_0)(x - x_1)$.
- Gregory-Newton ($x_0 = 0$, $h = 1$): $F(x) = f_0 + x\Delta f_0 + \frac{x(x-1)}{2!}\Delta^2 f_0 + \frac{x(x-1)(x-2)}{3!}\Delta^3 f_0 + \ldots$
- Genel: $k = \frac{x - x_0}{h}$, $F(x) = \sum_i \binom{k}{i}\Delta^i f_0$.

## Detaylı Açıklamalar

### Enterpolasyon ile regresyon farkı

- Derste giriş slaytında çok sayıda noktadan "minimum hatayla geçen" bir fonksiyondan bahsedildi. Bu tarif aslında **regresyona** (eğri uydurma) aittir. Regresyonda fonksiyon noktaların hepsinden geçmek zorunda değildir, toplam hatayı en aza indirir.
- **Enterpolasyonda** ise fonksiyon verilen bütün noktalardan tam olarak geçer ($F(x_i) = f_i$). Derste yapılan bütün örnekler (doğru, kuadratik, Gregory-Newton) bu türdendir. $n + 1$ noktadan tam olarak geçen en fazla $n$. dereceden tek bir polinom vardır.

### Kuadratik yöntemdeki katsayıların adı

- Hocanın "2. yol" olarak anlattığı $b_0, b_1, b_2$ katsayıları **Newton'un bölünmüş farkları**dır. $b_1$ birinci bölünmüş fark, $b_2$ ikinci bölünmüş farktır. Bu yöntem noktalar eşit aralıklı olmasa da çalışır. Noktalar eşit aralıklıysa bölünmüş farklar $\frac{\Delta^i f_0}{i!\,h^i}$'ye eşit olur ve formül Gregory-Newton formülüne dönüşür.

### Ders sonrası notlar

- **Örneklerin kontrolü:** Örnekler ders sonrasında Python ile yeniden hesaplandı. Kuadratik örnek ($2x^2 - 5x + 1$, $f(2.5) = 1$) ve Gregory-Newton örneği doğrudur.
- **Gregory-Newton sonucunun açık hâli:** Derste sonuç "3x küp eksi 2x kare artı... eksi 4" diye okundu. Düzenlenmiş hâli $F(x) = 3x^3 - 2x^2 + x - 4$'tür. Tablodaki bütün değerleri sağlar. $F(3.5) = 103.625$.
- **Doğrusal enterpolasyon örneğinde iki farklı sonuç:** Tablodaki değerler $f(x) = \sin x$ fonksiyonuna aittir (radyan). Gerçek değer $\sin 2 = 0.909297$'dir. a) şıkkı ($x = 1, 3$) 0.4913, b) şıkkı ($x = -2, 6$) $-0.5944$ verir. Derste "farklı noktalar kullanınca farklı sonuç çıkacak diye bir şey yok" dendi. Bu örnekte iki sonuç birbirinden çok farklıdır ve ikisi de gerçek değerden uzaktır. Doğrusal enterpolasyon yalnızca noktalar birbirine yakın ve fonksiyon o aralıkta doğruya yakınsa iyi sonuç verir. Uzak noktalar (−2 ile 6 gibi) arasında salınan bir fonksiyon için anlamlı değildir. Her zaman istenen noktaya en yakın iki noktayı kullanın.
- **Doğru denklemi formülü:** $B$ için ayrıca $B = \frac{b\,f(a) - a\,f(b)}{b - a}$ yazılabilir. Örnekte $\frac{6 \cdot 5 - 2 \cdot 13}{4} = 1$.
- **Tarih:** Vize tarihi derste "26 Nisan, pazartesi" diye geçti. 2023'te 26 Nisan çarşambadır. Pazartesi 24 Nisan'dır. Kesin tarih için o dönemin duyurularına bakın.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
