# Ders 2 Genişletilmiş Notu: Hata Türleri, Taylor Serileri ve Kapalı Kök Bulma Yöntemleri (Grafik, İkiye Bölme, Regula Falsi)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Geçen Dersin Hatırlatması ve Hatanın Önemi
- 2. Hata Kavramı
- 3. Taylor ve Maclaurin Seri Açılımları
- 4. Kesme Hatası
- 5. Bağıl Hata
- 6. Mutlak Hata
- 7. Yuvarlama Hatası
- 8. Doğru Denklemi Hatırlatması
- 9. Doğrusal Olmayan Denklemler
- 10. Kapalı ve Açık Yöntemler
- 11. Ortalama Değer ve Ara Değer Teoremleri
- 12. Durdurma Ölçütleri
- 13. Grafik Yöntemi
- 14. İkiye Bölme (Bisection) Yöntemi
- 15. Regula Falsi Yöntemi ve İnterpolasyon Araması
- Örnek Sorular

## 1. Geçen Dersin Hatırlatması ve Hatanın Önemi

Hoca derse önceki haftanın konularını hatırlatarak başladı: sayısal analizin ne olduğu, analitik ve nümerik çözüm farkı, sayı tabanları, anlamlı basamaklar, yuvarlama (rounding) ve kesme (truncation), doğruluk (accuracy) ve kesinlik (precision), kayan noktalı (floating point) işlemler. Yuvarlamanın kuralı da hatırlatıldı: atılacak basamak 5 ile 9 arasındaysa bir üst basamak bir artırılır, değilse olduğu gibi bırakılır.

Bu dersin amacı hata bölümünü bitirip doğrusal olmayan denklemlerin çözümüne geçmekti.

Sayısal analizde hatanın neden ayrı bir başlık olduğu şöyle açıklandı: algoritmalar yaklaşım yöntemleridir, yani çoğu `for` ya da `while` döngüsüyle çözüme adım adım yaklaşır. Bu döngüler sonsuza kadar dönemez; durdurmak için bir ölçüt gerekir ve bu ölçüt neredeyse her zaman hatadır.

Hoca bunu günlük hayatla bağladı. Yeni bir işe başlayan biri önce çok hata yapar, hatalar zamanla azalır ve belli bir düzeye oturur, belki hiç sıfır olmaz. Bu düzeye $\varepsilon$ (durdurma ölçütü) denir. Yapay zeka modellerinin eğitimi (training) de böyledir: model yüksek hatayla başlar, hata iterasyonlarla küçültülür. Örnek olarak çeviri sistemleri verildi. Eskiden çeviriler sözlük mantığıyla kelime kelime yapılıyordu ve anlam kayboluyordu. İnternetteki büyük metin kaynaklarıyla eğitilen sistemler, bir kelimenin geçtiği bağlamdan doğru karşılığı tahmin etmeyi öğrendi. Hocaya göre hata örtülecek bir şey değil, ders çıkarılacak bir şeydir.

## 2. Hata Kavramı

Hata, gerçek değer ile hesaplanan değer arasındaki farktır (ekrandan, 00:10:00):

$$\text{Hata} = \text{Gerçek değer} - \text{Hesaplanan değer}$$

Slayttaki örnekte $f(x) = x^2$ için $x=5$'te gerçek değer $f(5) = 25$'tir. Biri yanlışlıkla 10 bulursa hata $25 - 10 = 15$ olur.

Hoca terimlerin İngilizce karşılıklarını da yazdı (ekrandan, 00:15:00). Gerçek değer için "actual" ya da "real value", hesaplanan değer için "predicted", "estimated", "calculated" ya da "forecasted" denir. Bu terimler arasında küçük anlam farkları vardır. Farkın kendisi yerine mutlak değeri ya da karesi de kullanılabilir.

Hata yalnız matematiksel algoritmadan doğmaz, deneyde de ortaya çıkar. Hoca bir devre çizdi: 5 V'luk kaynak ve 2 Ω'luk direnç. Ohm kanununa göre

$$V = I\cdot R \;\Rightarrow\; 5 = 2\cdot I \;\Rightarrow\; I = 2{,}5\ \text{A}$$

(ekrandan, 00:15:00). Simülasyon programı da 2,5 A verir. Ama gerçek bir direncin değeri tam 2 Ω değildir, bir toleransı vardır. Ampermetre 2,49 ya da 2,51 A gösterebilir. Bu fark da üzerinde çalışılması gereken bir hatadır.

Bir sistemde (bir denklemde ya da $n$ kez dönen bir döngüde) önemli olan toplam hatadır:

$$\sum_{i=0}^{\infty} \varepsilon_i$$

Hoca bunu tecrübeye benzetti: bugüne kadar yapılan hataların birikimi, geleceğe dair tahminlerin dayanağıdır.

Derste hata dört türe ayrıldı: kesme hatası, bağıl hata, mutlak hata ve yuvarlama hatası.

## 3. Taylor ve Maclaurin Seri Açılımları

### 3.1 Neden seri açılımı?

Kesme hatasını anlamak için önce açılım fikri gerekir. Elimizde çok karmaşık bir $f(x)$ olsun. Bunu daha basit fonksiyonlar cinsinden yazmak isteriz. Hoca, temel fonksiyon gruplarını hatırlatmak için öğrencilere integralde kullanılan kısaltmayı sordu; bir öğrenci "LAPTÜ" cevabını verdi: logaritmik, ters trigonometrik (arktanjant gibi), polinom, trigonometrik, üstel (ekrandan, 00:20:00).

Bunlar içinde en "temiz" olanı polinomdur: türevi de integrali de kolaydır. Hangi fonksiyon olursa olsun, polinom cinsinden yazılabilirse diğer işlemler rahatça yapılır. Bu yazma işlemine açılım (decomposition) denir. Trigonometrik fonksiyonlar da önemlidir. Sinyal işlemede doğal sinyaller sinüs ve kosinüse benzer. Hoca mikrofonla hoparlör yaklaştırıldığında oluşan ciyaklama sesini örnek verdi: dalga formuna bakılırsa sinüse benzer bir şey görülür. Sinüs ve kosinüsün istenildiği kadar türevi alınabilir. Polinomun türevi ise bir yerde sabite, sonra sıfıra iner.

### 3.2 Göreli sonsuzluk

Slayttaki ilke şudur: $f(x)$ sonsuz defa türevlenebiliyorsa seri haline getirilebilir (ekrandan, 00:20:00). Buradaki "sonsuz" mutlak değil, fonksiyona göre görelidir. Örnek:

$$f(x) = x^3 + x^2 - x + 1,\quad f'(x) = 3x^2 + 2x - 1,\quad f''(x) = 6x + 2,\quad f'''(x) = 6,\quad f^{(4)}(x) = 0$$

Bu fonksiyonun "sonsuzu" üç türevdir. Öte yandan

$$f(x) = e^{2x},\quad f'(x) = 2e^{2x},\quad f''(x) = 4e^{2x},\ \dots$$

hiç bitmez. Hoca bunun nedenini $e^{jx} = \cos x + j\sin x$ ilişkisiyle açıkladı: sinüs ve kosinüsün sonsuz türevi olduğu için üstel fonksiyonun da sonsuz türevi vardır. Bu yüzden herhangi bir fonksiyon üstel, dolayısıyla bir anlamda sinüs ve kosinüs türünden açılabilir.

### 3.3 Genel formül

Taylor serisi bir $x_0$ noktası çevresinde yazılır:

$$f(x) = f(x_0) + f'(x_0)(x - x_0) + \frac{f''(x_0)}{2!}(x-x_0)^2 + \dots = \sum_{n=0}^{\infty} \frac{f^{(n)}(x_0)}{n!}(x - x_0)^n$$

$x_0 = 0$ alınırsa buna Maclaurin serisi denir (ekrandan, 00:30:00):

$$f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(0)}{n!}x^n = f(0) + f'(0)x + \frac{f''(0)}{2!}x^2 + \dots$$

Hoca seriyi $f(x) \cong \sum A_n x^n$ biçiminde yazdı: $\frac{f^{(n)}(x_0)}{n!}$ yalnızca bir katsayıdır. Fonksiyon zorsa türevi de zor olabilir; ama bu katsayılar da ileride sayısal yöntemlerle elde edilebilir. Sonuçta elimize türevi, integrali ve kökleri kolay bulunan bir polinom geçer. Seri bir yerde kesilirse (örneğin 8. dereceye kadar yazılıp gerisi bırakılırsa) aradaki fark kesme hatası olur.

### 3.4 Örnekler

**$e^x$'in $x=1$ çevresindeki açılımı.** İlk terimler $f(1) + f'(1)(x-1) + \frac{f''(1)}{2!}(x-1)^2 + \frac{f'''(1)}{3!}(x-1)^3$ biçimindedir; $e^x$'in bütün türevleri $e^x$ olduğundan katsayılar hep $e$ ile ilgilidir. Bulunan polinom ile $e^1$'in gerçek değeri arasındaki fark kesme hatasıdır.

**$\cos x$'in Maclaurin açılımı** (ekrandan, 00:25:00). Soru: $f(x) = \cos x$ fonksiyonunun Maclaurin açılımının sıfırdan farklı ilk 3 terimini bulunuz. Türevler:

$$f'(x) = -\sin x,\quad f''(x) = -\cos x,\quad f'''(x) = \sin x,\quad f^{(4)}(x) = \cos x$$

Terimler:

- 1. terim: $f(0) = 1$
- 2. terim: $f'(0)(x-0) = 0\cdot x = 0$
- 3. terim: $\dfrac{f''(0)(x-0)^2}{2!} = \dfrac{-1\cdot x^2}{2} = -\dfrac{x^2}{2}$
- 4. terim: $\dfrac{f'''(0)(x-0)^3}{3!} = \dfrac{0\cdot x^3}{6} = 0$
- 5. terim: $\dfrac{f^{(4)}(0)(x-0)^4}{4!} = \dfrac{x^4}{24}$

$$\cos x \approx 1 - \frac{x^2}{2} + \frac{x^4}{24}$$

Hoca burada çift fonksiyonu hatırlattı: $f(x) = f(-x)$ olan, $y$ eksenine göre simetrik fonksiyonlar. Birim çemberde $\cos 90^\circ$ ile $\cos(-90^\circ)$ aynıdır. Kosinüs çift fonksiyon olduğu için açılımında yalnız çift dereceli terimler ($x^0, x^2, x^4$) kalır; tek dereceli türevler $x=0$'da hep sıfırdır. Sinüs açılımında da yalnız tek dereceli terimler görülür. Açılım polinom bir fonksiyonda kendi derecesine kadar yapılabilir; dördüncü dereceden bir polinomu ikinci derecede keserseniz yine bir kesme hatası oluşur, ama kesme hatası genelde sonsuza uzayan açılımlar için konuşulur.

**$e^x$'in $x=4$ noktasındaki Taylor serisi** (ekrandan, 00:30:00). Bütün türevler $e^x$ olduğundan $f^{(n)}(4) = e^4$'tür:

$$e^x = \sum_{n=0}^{\infty} \frac{e^4 (x-4)^n}{n!}$$

İkinci dereceden Taylor polinomu $(x-4)^2$'li terime kadar gider:

$$e^x \approx e^4 + e^4(x-4) + \frac{e^4}{2}(x-4)^2$$

Bu polinom ile $e^x$'in gerçek değeri arasındaki fark kesme hatasıdır. Hoca, aynı yaklaşımın bir fonksiyonun integralini hatırlamadığımız durumda da işe yaradığını söyledi: örneğin $1/x$'in türevi $-1/x^2$, integrali $\ln x$'tir; integral akla gelmese bile fonksiyon Taylor serisiyle polinoma çevrilip polinomun integrali alınarak yaklaşık aynı sonuç bulunur.

**$1/x$'in $x=2$ noktasındaki Taylor serisi.** Türevler bir artı bir eksi işaretle gider. Altyazıya göre genel terim

$$\frac{1}{x} = \sum_{n=0}^{\infty} (-1)^n\, 2^{-(n+1)}\,(x-2)^n$$

olarak yazıldı. $(-1)^n$ çarpanı işaretlerin değişmesinden gelir. <!-- BELİRSİZ: Bu örneğin slaytı karede görülmedi; formül altyazıdaki anlatımdan kuruldu. -->

**$e^{2x}$'in Maclaurin serisi.** Türevler $2^n e^{2x}$ biçiminde genelleşir ve $x=0$'da $2^n$ olur:

$$e^{2x} = \sum_{n=0}^{\infty} \frac{2^n}{n!}x^n = 1 + 2x + 2x^2 + \frac{4}{3}x^3 + \dots$$

Hoca terimleri tek tek açtı: $n=0$'da 1, $n=1$'de $2x$, $n=2$'de $\frac{4}{2}x^2 = 2x^2$, $n=3$'te $\frac{8}{6}x^3 = \frac{4}{3}x^3$ (python ile doğrulandı). Hiç eksi işaret yoktur; elimizde üzerinde işlem yapması kolay bir polinom vardır, ama kesildiği yerde hata da vardır.

## 4. Kesme Hatası

Slayttaki tanım (ekrandan, 00:35:00): "Bir değerin hesaplanabilmesi için sonsuz sayıda terim alınması gerekirken sonlu sayıda terim alınıyorsa oluşan hataya kesme hatası denir. Eklenen her yeni terim sonucu değiştirir ama bu değişim çok az olduğu için göz ardı edilir." Aynı slayt devam eder: "Taylor serisi, bir fonksiyonun herhangi bir x noktasındaki değerini, fonksiyonun ve türevlerinin o x noktasındaki değerleri cinsinden tahmin edilmesine olanak sağlar."

Hoca "tahmin" kelimesinin altını çizdi: tahmin varsa kesme hatası da vardır. Belli bir hassasiyet yeterliyse bir yerde durulur, durulan yerden sonrası kesme hatasıdır.

### 4.1 $e^x$ ile yaklaşım

$e^x \approx 1 + x + \frac{x^2}{2} + \frac{x^3}{6} + \frac{x^4}{24}$ açılımıyla herhangi bir $e^x$ değeri yaklaşık hesaplanabilir. Derste $e^{1{,}5}$ değeri üçüncü dereceden açılımla tahmin edildi ve gerçek değerle farkı kesme hatası olarak hesaplandı. <!-- BELİRSİZ: Bu örneğin slayt değerleri karede görülmedi. -->

> **Ek bilgi (derste anlatılmadı):** Python ile kontrol: $1 + 1{,}5 + \frac{1{,}5^2}{2} + \frac{1{,}5^3}{6} = 4{,}1875$, $e^{1{,}5} \approx 4{,}4817$; kesme hatası büyük olasılıkla yaklaşık 0,294'tür.

### 4.2 Polinomun Taylor açılımı: kesme hatasının sıfırlanması

Örnekte bir $f(x)$ fonksiyonu ve başlangıç değerleri verildi. $x = 0$'dan başlanıp $h = 1$ adımla ($x_{i+1} = x_i + h$) $f(1)$ değeri dördüncü dereceye kadar Taylor serisiyle tahmin edildi. Ekrandaki türev değerleri ve açılım (ekrandan, 00:40:00):

$$f(1) \approx f(0) + f'(0)x + \frac{f''(0)x^2}{2!} + \frac{f'''(0)x^3}{3!} + \frac{f^{(4)}(0)x^4}{4!}$$

Üçüncü derece için $f'''(0) = -2{,}4x - 0{,}90 = -0{,}9$ ve terim $-0{,}9/6 = -0{,}15x^3$; dördüncü derece için $f^{(4)}(0) = -2{,}4$ ve terim $-2{,}4/24 = -0{,}1x^4$'tür. Adım adım tahminler:

| Derece | Açılım | $f(1)$ tahmini |
|---|---|---|
| 0 | $1{,}2$ | 1,2 |
| 1 | $1{,}2 - 0{,}25x$ | 0,95 |
| 2 | $1{,}2 - 0{,}25x - 0{,}5x^2$ | 0,45 |
| 3 | $1{,}2 - 0{,}25x - 0{,}5x^2 - 0{,}15x^3$ | 0,3 |
| 4 | $1{,}2 - 0{,}25x - 0{,}5x^2 - 0{,}15x^3 - 0{,}1x^4$ | 0,2 |

Gerçek değer $f(1) = 0{,}2$'dir. Dördüncü derecede tahmin birebir tuttu, çünkü fonksiyonun kendisi dördüncü dereceden bir polinomdur; bu fonksiyon için "sonsuz" dördüncü derecedir. Açılım aslında fonksiyonun kendisini geri verir. Önceki derecelerde kesme hatası dalgalanır, son adımda sıfırlanır.

> **Ek bilgi (derste anlatılmadı):** Tablodaki katsayılardan fonksiyon büyük olasılıkla $f(x) = -0{,}1x^4 - 0{,}15x^3 - 0{,}5x^2 - 0{,}25x + 1{,}2$'dir. Python ile her derecenin kesme hatası $f(1) - \text{tahmin}$ = −1; −0,75; −0,25; −0,1; 0 bulunur.

### 4.3 $\cos(\pi/5)$ örneği

$\cos(\pi/5)$, yani $\cos 36^\circ$, trigonometri cetvelinden ya da hesap makinesinden bulunabilir ama Maclaurin serisiyle de hesaplanabilir. Hoca açılımı adım adım kurdu: $f(0) = \cos 0 = 1$; birinci türev $-\sin x$, $x=0$'da 0; ikinci türev $-\cos x$, $x=0$'da $-1$, terim $-\frac{x^2}{2}$; üçüncü türev $\sin x$, $x=0$'da 0. Türevleri hatırlamak için bir döngü çizdi: sinüsten kosinüse, kosinüsten eksi sinüse türev yönündedir, ters yön integraldir. Yine kosinüs çift olduğu için tek dereceli terimler sıfır geldi. Sonra $x$ yerine radyan cinsinden $\pi/5$ yazılır; açılımın değeri ile cetveldeki değer arasındaki fark kesme hatasıdır.

> **Ek bilgi (derste anlatılmadı):** Python ile kontrol: $x = \pi/5 \approx 0{,}6283$ için $1 - \frac{x^2}{2} + \frac{x^4}{24} \approx 0{,}80910$, $\cos 36^\circ \approx 0{,}80902$; kesme hatası büyük olasılıkla yaklaşık $-8{,}5\times10^{-5}$'tir.

## 5. Bağıl Hata

Hata bazen pozitif bazen negatif çıkar. Gerçek değer beklenenden küçükse hata negatif, büyükse pozitiftir. İşaret yanıltıcı olabilir: hoca yapay sinir ağlarında hataların mutlak değer olarak toplandığını söyledi. Bir yerde $+2$, bir yerde $-2$ hata olsa toplam sıfır çıkar, sanki hiç kusur yokmuş gibi görünür; oysa 4 birimlik bir yanlış vardır.

Bağıl hata, farkın gerçek değere oranıdır (ekrandan, 00:45:00):

$$\text{Bağıl Hata} = \frac{\text{Gerçek değer} - \text{Hesaplanan değer}}{\text{Gerçek değer}}$$

Slaytta "Bağıl hatanın küçük olması hedeflenir" yazıyordu. Mutlak değeri alınıp 100 ile çarpılırsa yüzde sapma bulunur. Gerçek değer 50 iken 25 de bulunsa, 75 de bulunsa %50'lik bir sapma vardır.

**Örnek:** $f(x) = x^3$ için gerçek değer $2^3 = 8$, hesaplanan 6 olsun. Bağıl hata $\frac{8-6}{8} = \frac{2}{8} = \frac{1}{4}$, yani %25'tir. Hoca önce $\frac{6-8}{8} = -\frac{1}{4}$ yazdı, sonra formüle uygun olarak gerçek değerden hesaplananı çıkarmak gerektiğini söyleyip düzeltti. Gerçek değer hesaplanandan küçük olsaydı (gerçek 6, hesaplanan 8) sonuç negatif çıkardı.

Derste $e$ sayısının bir algoritmayla bulunan yaklaşık değerinin bağıl hatası da hesaplandı; sonuç $10^{-4}$ mertebesindeydi. <!-- BELİRSİZ: Bu örneğin sayıları altyazıda bozuk ("1.0.36x10x4"), kare yok. -->

### 5.1 Bağıl hata neden önemli?

Bir algoritma birden fazla hatayı izliyorsa, örneğin $f(x)$'in hatası 10.000, $g(x)$'in hatası 1.000 çıkmışsa, bu sayıları doğrudan karşılaştırmak her zaman doğru değildir. Hoca boy ve kilo örneğini verdi: boy metre cinsinden 1,6-1,8 arasında, hataları da küçük sayılardır; kilo hataları ise 5-6 kilo gibi çok daha büyük sayılardır. İkisi ancak yüzde cinsinden karşılaştırılabilir. Ekonomide de değişimler yüzde olarak değerlendirilir.

İkinci benzetme: tahta keserken 1 cm fazla kesmek pek fark etmez, zımparayla düzeltilir. Altın keserken 1 cm fark çok pahalıya mal olur; bu yüzden kumpas gibi hassas aletler kullanılır.

Slayttaki ilke (ekrandan, 00:50:00): "Bağıl hatada hesaplanan değerin mertebesi önemlidir. 1 cm'lik bir hata, 100 m için önemsiz iken 10 cm için önemlidir."

**Köprü ve perçin sorusu** (ekrandan, 00:50:00): Bir köprü ve perçinin uzunlukları sırasıyla 9.999 cm ve 9 cm ölçülüyor; gerçek değerler 10.000 cm ve 10 cm. Hoca, buradaki noktanın Türkçe gösterimde binlik ayırıcı olduğunu (dokuz bin dokuz yüz doksan dokuz) belirtti.

a) Gerçek hata:

- Köprü için $e_g = 10.000 - 9.999 = 1$ cm
- Perçin için $e_g = 10 - 9 = 1$ cm

b) Yüzde bağıl hata:

- Köprü için $e_b = \frac{10000 - 9999}{10000}\cdot 100 = \%0{,}01$
- Perçin için $e_b = \frac{10-9}{10}\cdot 100 = \%10$

İki durumda da 1 cm'lik sapma var, ama perçindeki sapma oransal olarak çok daha büyüktür. Hoca, köprünün yapısına aykırı küçük bir sapmanın bile sorun çıkarabileceğini söyledi.

## 6. Mutlak Hata

Bağıl hatanın mutlak değerce ifadesine derste mutlak hata denildi. Mutlak değer alınınca işaret sorunu ortadan kalkar. Hoca bu formülün literatürde daha çok kullanıldığını söyledi.

> **Hocanın vurgusu:** Sınavda "mutlak hata" sorulursa bölmeli formül (gerçek değere oranlanmış hali) beklenir. Bölmesiz farkın istendiği durumlarda bu soruda açıkça belirtilir.

İkinci formül "absolute error"dur: gerçek değerden (actual value) hesaplanan değer (predicted) hiç bölünmeden çıkarılır.

**Örnek** (ekrandan, 00:55:00): $f(x) = x^2 - 3x$ veriliyor. $x = 2$ değerini fonksiyona koyup hesaplayan biri sonucu 10 buluyor. Bu işlemdeki mutlak hata nedir?

- Gerçek değer: $f(2) = 4 - 6 = -2$
- Hesaplanan değer: $f(2) = 10$
- Mutlak hata $= \left|\dfrac{-2 - 10}{-2}\right| = \left|\dfrac{-12}{-2}\right| = 6$

> **Ders sonrası not:** Hoca sonucu yorumlarken önce "6 birimlik mutlak hata", "yüzde çarparsanız yüzde 6" dedi, sonra hesabı tekrar edip "yüzde 15 nokta küsur" dedi. Ekrandaki oran 6'dır; yüzdeye çevrilirse $6\times100 = \%600$ olur. Bölmesiz tanımla (absolute error) mutlak hata $|-2-10| = 12$'dir.

## 7. Yuvarlama Hatası

Yuvarlama işleminde yapılan hatadan doğan hataya yuvarlama hatası denir. Hoca bir sayıyı ikinci basamağa yuvarlarken kurala uyulmazsa (atılan basamak 5 ve üstüyken bir üst basamak artırılmazsa) bu hatanın oluştuğunu anlattı. <!-- BELİRSİZ: 27.35 ile anlatılan sayısal örneğin ayrıntıları altyazıda karışık, kare yok. -->

Program yazarken pratik sonucu şudur: gerçek değer ile tahmin edilen değerin eşitliğini doğrudan kontrol etmek yerine, farkın mutlak değerine bakılır:

$$|g - p| \le 0{,}0001$$

Eşik değer aslında hangi basamağa kadar yuvarlamanın kabul edildiğini gösterir (3 ya da 4 basamak gibi). Fark bu eşiğin altındaysa sonuç kabul edilebilir çözüm sayılır.

## 8. Doğru Denklemi Hatırlatması

Aradan sonra hoca, kök bulma yöntemlerinde türevi eğim üzerinden hesaplamak gerekeceği için doğru denklemini hatırlattı (ekrandan, 01:10:00).

- Doğrunun genel denklemi: $y = mx + n$. Buradaki $m$ eğimdir (slope, gradient).
- İki noktası bilinen doğru, $(x_1, y_1)$ ve $(x_2, y_2)$ için:

$$\frac{y - y_2}{y_2 - y_1} = \frac{x - x_2}{x_2 - x_1}$$

- Eğim: $m = \dfrac{y_2 - y_1}{x_2 - x_1}$.
- $m$ bilinince $n$, doğru üzerindeki bir noktadan bulunur: $y_1 = m x_1 + n \Rightarrow n = y_1 - m x_1$.
- Doğrunun türevi her yerde $m$'dir.
- Eksenleri $a$ ve $b$ noktalarında kesen doğru: $\dfrac{x}{a} + \dfrac{y}{b} = 1$.

## 9. Doğrusal Olmayan Denklemler

Doğrusal olmayan bir denklemin grafiği doğru değil eğridir. Amaç $y = f(x)$ fonksiyonunun gerçek köklerini (real roots), yani $f(x) = 0$ yapan $x$ değerlerini bulmaktır; sanal köklerle bu derste fazla uğraşılmaz. Kökler grafikte eğrinin $x$ eksenini kestiği noktalardır. Bu kökleri her zaman analitik yolla bulmak mümkün değildir; o zaman sayısal yöntemlere başvurulur.

Analitik çözümü olmayan problemler arasında diferansiyel denklemler (dersin son konusu), belirli integraller ve doğrusal olmayan denklemler sayıldı. Bilinmeyen sayısı arttıkça problem zorlaşır, ama algoritmalarla yaklaşık çözüm yapılabilir.

Ekrandaki örnekler (ekrandan, 01:15:00):

- $4x - 16 = 0$: doğrusal, bir bilinmeyenli denklem. Bilinenler bir tarafa, bilinmeyenler diğer tarafa atılır, katsayı bire indirilir: $x = 4$.
- $x^2 - 4x = 0$: doğrusal olmayan denklem, ama analitik olarak çözülür: $x(x-4) = 0$, $x = 0$ ve $x = 4$. İkinci dereceden olduğu için iki kökü vardır.

Çarpanlara ayırma, diskriminant ve üçüncü dereceden polinomlar için kısmen analitik yollar vardır. Ama logaritmik, polinom ve trigonometrik fonksiyonların iç içe geçtiği bir ifadede (örneğin $\log_2 x$ ile $x^3$'ün çarpımının sinüs üssü) ne bilinenleri ayırmak ne de bilinen başka bir yöntem işe yarar; çözüme yaklaşmak zorunludur. İki bilinmeyenli doğrusal olmayan denklem takımlarında ($f(x)$ ve $g(x)$ birlikte) iş daha da karışır.

Genel strateji: verilen denklemin ya da denklem takımının kaç kökü olduğu, köklerin gerçek mi sanal mı olduğu ve kökler için bir yaklaşık değer bilinip bilinmediğine göre yöntem seçilir. Bazı yöntemler tek denkleme, bazıları denklem takımlarına daha uygundur.

## 10. Kapalı ve Açık Yöntemler

Yöntemler iki ana gruba ayrılır (ekrandan, 01:20:00).

**Kapalı yöntemler (bracketing methods):**

- Grafik yöntemi
- İkiye bölme - aralık yarılama (bisection)
- Regula falsi (false position / yanlış nokta / lineer interpolasyon)

Slayttaki açıklama: "Kökler, bir alt ve üst sınırla belirlenen bir aralığın içerisinde yer alır. Bu yöntemlerin tekrarlanması ile her zaman kökün gerçek değerinin yaklaşık tahmini yapılır. İterasyon sayısı arttıkça gerçek değere daha fazla yaklaşıldığından bu yöntemlere aynı zamanda yakınsak yöntemler de denir."

Hoca, kökün iki sınır arasında "boğularak" kıskaca alındığını anlattı. Dikkat edilecek şey, $i$. iterasyondan $i+1$. iterasyona geçişte gerçek köke yaklaşılıp yaklaşılmadığıdır. Kötüye gidiş varsa ıraksama vardır.

**Açık yöntemler:**

- Newton-Raphson
- Secant (kiriş)
- Tekrarlama metodu (fixed point iteration method)

Slayttaki açıklama: "x'in sadece bir tek başlangıç değerine gerek duyulan veya kökü kıskaca almayan iki başlangıç değeri gerektiren formüllerden oluşurlar. Bu yöntemler hesaplama sürecinde bazen ıraksarlar ve gerçek değerden uzaklaşırlar. Ancak, açık yöntemler yakınsadıkları zaman kapalı yöntemlerden daha hızlı çalışırlar."

Kodlama açısından fark kullanıcıdan alınan girdidedir: Newton-Raphson kodlanırken bir başlangıç değeri, bisection kodlanırken iki sınır (ör. $x=3$ ile $x=10$ arası) alınır.

## 11. Ortalama Değer ve Ara Değer Teoremleri

### 11.1 Süreklilik ve sıfır geçişi

$f(x)$ fonksiyonu $[a,b]$ aralığında sürekli olsun: tanımsız nokta yoktur, sağdan ve soldan limitler eşittir, grafik elimizi kaldırmadan çizilebilir. Bu durumda $f(a)$ ile $f(b)$ zıt işaretliyse (literatürde "zero crossing", sıfır geçişi) aralıkta en az bir gerçek kök vardır. "En az bir" denmesinin nedeni, dalgalanan bir fonksiyonun aralıkta birden fazla kez $x$ eksenini kesebilmesidir.

Süreklilik şarttır. Fonksiyon $a$ ile $b$ arasında kopuyorsa (bir parça yukarıda biter, diğer parça aşağıdan başlar) işaret değişse bile arada kök olmayabilir. Hoca sınavda verilecek fonksiyonların aralıkta sürekli olacağını ya da sürekliliğin kolay test edilebileceğini söyledi.

### 11.2 Ortalama değer teoremi

$f(x)$, $[a,b]$ aralığında sürekli ise $a$ ile $b$ arasında bir $c$ noktası için

$$f'(c) = \frac{f(b) - f(a)}{b - a}$$

olur (ekrandan, 01:25:00). Sağ taraf $a$ ile $b$'yi birleştiren kirişin eğimi, sol taraf $c$'deki teğetin eğimidir. Hoca, bulunan $c$ değerlerinin sayısının fonksiyonun dalgalanması hakkında bilgi verdiğini anlattı. Ekrandaki notta "3 teğet noktası olduğu için 3 tane $c$ değeri bulunur; $c$ sayısı fonksiyondaki dalgalanma hakkında bize bilgi verir" yazıyordu. Tek $c$ çıkarsa tek tepe noktalı bir eğri, iki $c$ çıkarsa iki minimum/maksimumlu bir eğri düşünülür.

**Örnek** (ekrandan, 01:25:00): $f(x) = x^2 + 5$ fonksiyonunun $[1,5]$ aralığında ortalama değer teoremini sağlayan değerleri bulunuz.

- $f(1) = 1 + 5 = 6$, $f(5) = 25 + 5 = 30$
- $\dfrac{f(5) - f(1)}{5 - 1} = \dfrac{24}{4} = 6$
- $f'(x) = 2x \Rightarrow f'(c) = 2c = 6 \Rightarrow c = 3$

Tek bir $c$ bulunduğu için tek tepe noktalı bir eğri söz konusudur.

**İkinci örnek:** Uç noktalardaki değerlerden ortalama eğim 3 bulundu; türev $3x^2 + 2$ alınıp 3'e eşitlendi: $3c^2 + 2 = 3 \Rightarrow c = \pm\dfrac{1}{\sqrt{3}}$. İki $c$ değeri, iki minimum/maksimum noktası olduğunu gösterir. <!-- BELİRSİZ: Fonksiyonun tam ifadesi karede görülmedi; altyazıya göre uç noktalar -1 ve 1, türevi 3x²+2. -->

### 11.3 Ara değer teoremi

$f(x)$, $[a,b]$'de sürekli ve $f(a) \ne f(b)$ ise ya $f(a) < f(b)$ ya da $f(a) > f(b)$'dir. Aradaki her değer, $a$ ile $b$ arasındaki bir $c$ noktasında alınır. Kök arayışında bunun anlamı şudur: kök $[a,b]$'de aranıyorsa bir sonraki adımda ya $[a,c]$'de ya da $[c,b]$'de aranır. Fonksiyon artan değil azalansa eşitsizlikler ters döner. Kapalı yöntemler $a$ ve $b$'yi sürekli güncelleyerek kökü kıskaca alır.

Kökün varlığı şu şartla kontrol edilir:

$$f(a)\cdot f(b) < 0$$

Çarpım negatifse bir uç negatif, diğeri pozitiftir; arada en az bir kök vardır. Bazı yöntemler paralel aramayla birden fazla kök bulabilir, bazıları yalnız bir kök bulur.

Derste bir polinomun $[1,3]$'te en az bir kökü olduğu $f(1)\cdot f(3) < 0$ ile gösterildi: polinomda tanımsızlık noktası yoktur, uçlardan biri negatif diğeri pozitif (13) çıkmıştır. <!-- BELİRSİZ: Bu örneğin fonksiyonu ve f(1) değeri karede görülmedi. -->

### 11.4 Parçalı fonksiyonlar

Parçalı fonksiyonda kritik noktaya dikkat etmek gerekir (ekrandan, 01:30:00):

$$f(x) = \begin{cases} 2x + 1, & x > 3 \\ x^2 + 1, & x \le 3 \end{cases}$$

$f(0) = 0^2 + 1 = 1$, $f(4) = 2\cdot 4 + 1 = 9$. Hoca $[0,4]$ aralığında kritik nokta $x=3$'ün bulunduğunu, bu tür fonksiyonlarda ve tanımsızlık yaratan değerlerde süreklilik koşullarının (sağdan ve soldan limit) ayrıca incelenmesi gerektiğini söyledi. İki uç da pozitif olduğu için bu aralıkta sıfır geçişinden kök bulunamaz.

Bir başka örnek doğrusal bir fonksiyondu: $2x - 1$ her yerde süreklidir, $x=0$'da $-1$'den geçer ve $x = 1/2$'de sıfır olur; bu kök doğrudan sıfıra eşitlenerek de bulunur.

## 12. Durdurma Ölçütleri

Algoritmaların nasıl durdurulacağı da belirlenmelidir.

- **Gerçek kök biliniyorsa** (yalnız algoritmayı test etmek için): $n$. iterasyonda bulunan değer ile gerçek kök arasındaki fark verilen hata değerinin (ör. 0,001) altına düşene kadar devam edilir. Bağıl hata verilmişse aynı şey bağıl hata için yapılır.
- **Gerçek kök bilinmiyorsa** (asıl kullanılan durum): algoritma bir yerden sonra bir değere oturur; buna yakınsama (convergence) denir. Ölçüt örnekleri:
  - Üst ve alt sınır farkının $2^n$'e bölümü kabul edilebilir $\varepsilon$'un altına düşerse durulur.
  - Ardışık iki iterasyonun kök değerleri arasındaki fark: $|x_{n+1} - x_n| < \varepsilon$. Örneğin kök 2,8888 ve 2,898 civarında gidip geliyorsa artık ilerleme yoktur.

Bu ölçütler bir `while` döngüsünün koşuluna yazılır.

## 13. Grafik Yöntemi

### 13.1 Algoritma

Slayttaki adımlar (ekrandan, 01:35:00):

1. Fonksiyonun değişkenine başlangıç değeri verilir ($x_0$).
2. $x$ değerleri arasındaki artım miktarı belirlenir ($\Delta x$).
3. $x_0$ fonksiyonda yerine konularak $f(x_0)$ hesaplanır.
4. Bir sonraki $x$ değeri ($x + \Delta x$) alınarak $f(x+\Delta x)$ hesaplanır.
5. Bu işlem, hesaplanan son iki fonksiyon değeri ters işaretli olana kadar tekrarlanır.
6. Ters işaretli durum elde edildiğinde ilk iterasyon tamamlanmış olur.
7. Bir sonraki iterasyon, ters işaretli sonucu veren iki $x$ değişkeninin arasında aynı işlemlerle tekrarlanır.
8. Çünkü kök bu $x$ değerleri arasında yer almaktadır.
9. Her yeni iterasyonda $\Delta x$ değeri yarıya bölünerek kullanılır.
10. İterasyonların tekrarı, ters işaretli fonksiyon değerini veren $x$ değerleri arasındaki mutlak farkın verilen hata değerinden küçük eşit oluncaya kadar devam ettirilir.

Hoca sezgisini şöyle anlattı: $x_0$'dan $\Delta x$ kadar ileri gidilir; işaret değişmişse kök aradadır ve "biraz fazla kaçırmışım, biraz geri geleyim" diye $\Delta x$ yarıya bölünür. $x_0$ değişmez; durma ölçütü $\Delta x$'in değişimidir.

### 13.2 Sayısal örnek

$f(x) = x^2 - 6x + 5$, $x_0 = 1{,}5$, $\Delta x = 0{,}75$, $\varepsilon = 0{,}0235$ (ekrandan, 01:40:00 ve 01:50:00). Hoca örneği önce kendi tahtasında elle çözdü, sonra slayttaki çözümü gösterdi.

**1. iterasyon** ($\Delta x = 0{,}75$):

| $x$ | $f(x)$ | İşaret |
|---|---|---|
| 1,5 | −1,75 | − |
| 2,25 | −3,43 | − |
| 3 | −4 | − |
| 3,75 | −3,43 | − |
| 4,5 | −1,75 | − |
| 5,25 | 1,0625 | + |

Değerler önce azalıp sonra artıyor; 4,5'te negatif, 5,25'te pozitif. Hoca derste "kök hangi aralıkta?" diye sordu; bir öğrenci 4,5 ile 5,25 arası cevabını verdi.

**2. iterasyon** ($\Delta x = 0{,}75/2 = 0{,}375$): $f(4{,}5) = -1{,}75$, $f(4{,}875) = -0{,}4844$, $f(5{,}25) = 1{,}0625$. Kök 4,875 ile 5,25 arasındadır.

**3. iterasyon** ($\Delta x = 0{,}375/2 = 0{,}1875$): $f(4{,}875) = -0{,}4844$, $f(5{,}0625) = 0{,}2539$.

**4. iterasyon** ($\Delta x = 0{,}1875/2 \approx 0{,}094$): $f(4{,}875) = -0{,}4844$, $f(4{,}969) = -0{,}1230$, $f(5{,}063) = 0{,}2559$.

> **Ders sonrası not:** Slayttaki 0,2559 büyük olasılıkla yuvarlama kaynaklıdır; python ile $f(5{,}063) \approx 0{,}2546$, $f(5{,}0625) = 0{,}2539$ bulunur. Sonuç değişmez.

**5. iterasyon** ($\Delta x = 0{,}094/2 = 0{,}047$): $f(4{,}969) = -0{,}1230$, $f(5{,}016) = 0{,}064$.

**6. iterasyon** ($\Delta x = 0{,}047/2 = 0{,}0235$): $f(4{,}969) = -0{,}1230$, $f(4{,}9925) = -0{,}0299$, $f(5{,}016) = 0{,}0640$. Fark $\varepsilon$'a ulaştığı için durulur ve $x_{\text{kök}} \approx 5$ bulunur (tam sayıya yuvarlanırsa 5).

Python ile değerler doğrulandı (ör. $f(4{,}5) = -1{,}75$, $f(5{,}25) = 1{,}0625$, $f(5{,}0625) = 0{,}2539$). $x^2 - 6x + 5 = (x-1)(x-5)$ olduğundan gerçek kökler 1 ve 5'tir; algoritma 5'e yaklaşmıştır.

Hoca iki gözlemi tahtaya çizdi (ekrandan, 02:15:00): $\Delta x$ dizisi $0{,}75 \to 0{,}375 \to 0{,}1875 \to 0{,}094 \to 0{,}047 \to 0{,}0235$ diye azalan bir eğri çizer; kökün tahminleri $1{,}5 \to 4{,}5 \to 4{,}875 \to 4{,}969$ diye ilerler. Bu bulunan kök gerçek köktür; $x^2 + 2$ gibi gerçek kökü olmayan bir fonksiyonda hiç sıfır geçişi olmaz.

### 13.3 Hangi döngü?

**Soru:** Bu yöntemi kodlasaydınız `for` mu, `while` mı kullanırdınız? **Cevap:** Bir öğrenci `while` dedi. Hoca onayladı: ne zaman biteceği belli değildir ve $\Delta x$'in değişimine bağlı bitme koşulu en rahat `while` ile yazılır.

### 13.4 Yöntemin zayıflığı

Grafik yönteminde bazı noktalar tekrar tekrar hesaplanır (örneğin 4,5'e iki kez bakıldı), ileri-geri gidilir. Hoca, 0 ile 1 arasında bile sonsuz sayı olduğunu, böyle sabit adımlı ayarlamaların algoritmayı geciktirdiğini söyledi. Bu sorunu aşmak için iki kapalı yöntem daha önerilmiştir: bisection ve regula falsi.

## 14. İkiye Bölme (Bisection) Yöntemi

### 14.1 İkili arama ile bağlantı

Hoca bisection'ın çıkış noktasının ikili arama (binary search) olduğunu söyledi ve öğrencilere bu algoritmanın mantığını sordu. Bir öğrenci "alttan ve üstten değer seçip ortada istenen değeri arıyoruz, diziyi her seferinde yarıya bölüyoruz" diye cevap verdi.

Hoca açıkladı: ikili arama için dizinin sıralı (sorted) olması gerekir (alfabetik ya da sayısal). Doğrusal (sıralı, sequential) arama elemanlara tek tek bakar. Sıralı dizide ise ortadaki elemana bakılır; aranan eleman büyükse sağ yarıya, küçükse sol yarıya geçilir. Her adımda dizinin yarısı atılır; karmaşıklık $\log_2 n$'dir. Sonlu bir dizide buna ikili arama denir; aynı fikir sonsuz sayı doğrusunda uygulanınca adı bisection, ikiye bölme yöntemi olur.

İkili aramanın adımları:

```text
eğer x == dizi[m]  -> bulundu
eğer x > dizi[m]   -> l = m + 1
eğer x < dizi[m]   -> r = m - 1
m = (l + r) / 2
```

> **Hocanın vurgusu:** $\frac{l + r}{2}$ aslında $(l + r)\cdot\frac{1}{2}$'dir. Bunu unutmayın: birazdan gelecek yöntemde bu $\frac{1}{2}$ yerine başka bir oran yazılacak.

### 14.2 Başka durdurma ölçütleri

**Soru:** Grafik yönteminde $\Delta x$'in değişimine bakarak durduk. Başka neye bakarak durdurabiliriz? **Cevap:** Bir öğrenci bulunan değeri fonksiyonda denemeyi önerdi. Hoca kabul etti: bulunan değer kökse fonksiyonu sağlamalıdır, yani $f(x)$ sıfıra (ör. 0,001'den yakın) yaklaşmalıdır. Hoca bir ölçüt daha ekledi: ardışık iki iterasyonun kök tahminleri arasındaki farkın mutlak değeri, $|x_{i+1} - x_i| \le 0{,}0001$ gibi. Bu ölçüt denklemde yerine koymayı gerektirmez.

### 14.3 Yöntemin özellikleri

Bisection doğrusal olmayan, analitik çözümü olmayan denklemlerde kullanılan kapalı bir yöntemdir. Önce $[a,b]$'de en az bir kök olduğu $f(a)\cdot f(b) < 0$ ile gösterilir. Sonra orta nokta $c = \frac{a+b}{2}$ alınır. $f(a)\cdot f(c) < 0$ ise kök $[a,c]$'dedir ve $b = c$ yapılır; değilse kök $[c,b]$'dedir ve $a = c$ yapılır. İki uç birbirine yaklaşarak köke gider. Grafik yöntemindeki gibi "fazla ileri gittim, geri geleyim" durumu yoktur; algoritma kararlı biçimde daralır. Durma ölçütü olarak uçların ya da orta noktanın değişiminin $\varepsilon$'un altına düşmesi kullanılabilir.

### 14.4 Sayısal örnek

$f(x) = x^3 - 7x^2 + 14x - 6$, $[0,1]$, $\varepsilon = 0{,}01$ (ekrandan, 02:20:00). Hata her iterasyonda $\frac{b-a}{2^n}$ ile hesaplanır.

**1. iterasyon** $[0,1]$: $f(0) = -6$, $f(1) = 2$, $f(0)\cdot f(1) < 0$. $c = \frac{0+1}{2} = 0{,}5$, $f(0{,}5) = -0{,}625$. Hata $= \frac{1-0}{2^1} = 0{,}5 > 0{,}01$. $f(0{,}5)\cdot f(1) < 0$ olduğu için yeni aralık $[0{,}5;\ 1]$.

**2. iterasyon** $[0{,}5;\ 1]$: $c = \frac{1 + 0{,}5}{2} = 0{,}75$, $f(0{,}75) = 0{,}9844$. Hata $= \frac{1-0{,}5}{2^2} = 0{,}125$. $f(0{,}5)\cdot f(0{,}75) < 0$, yeni aralık $[0{,}5;\ 0{,}75]$.

**3. iterasyon** $[0{,}5;\ 0{,}75]$: $c = 0{,}625$, $f(0{,}625) = 0{,}2598$. Hata $= \frac{0{,}75 - 0{,}5}{2^3} = 0{,}03125$. $f(0{,}5)\cdot f(0{,}625) < 0$, yeni aralık $[0{,}5;\ 0{,}625]$.

**4. iterasyon** $[0{,}5;\ 0{,}625]$: $c = 0{,}5625$, $f(0{,}5625) = -0{,}1618$. Hata $= \frac{0{,}625 - 0{,}5}{2^4} \approx 0{,}0078 < 0{,}01$. Durulur.

$$x_{\text{kök}} \approx 0{,}5625$$

Değerler python ile doğrulandı.

> **Ders sonrası not:** Hoca anlatırken önce $f(0{,}5)$ için "0,5625" ve "0,625", $f(0{,}75)$ için "0,098", $f(0{,}625)$ için "0,025" dedi; ekrandaki ve doğru değerler $f(0{,}5) = -0{,}625$, $f(0{,}75) = 0{,}9844$, $f(0{,}625) = 0{,}2598$'dir. Son aralığı "0,5625 ile 0,60625" diye söyledi; doğrusu $[0{,}5625;\ 0{,}625]$'tir. Fonksiyonun bu aralıktaki gerçek kökü $2 - \sqrt{2} \approx 0{,}5858$'dir; 0,5625 durma ölçütünü sağlayan yaklaşık değerdir.

**Soru:** Diğer kökü nasıl buluruz? **Cevap:** Başlangıçta farklı bir aralık seçilir (ör. $[1,2]$ ya da $[1,10]$). O aralıkta bir kök varsa algoritma o köke yaklaşır.

Bisection'ın da bir sorunu vardır: iki nokta arasında sonsuz sayı olduğu için aralığı istenildiği kadar yarılasanız da çözüme geç ulaşılabilir.

## 15. Regula Falsi Yöntemi ve İnterpolasyon Araması

### 15.1 Fikir: orta nokta yerine daha akıllı bir nokta

Hoca 300 sayfalık bir kitapta 280. sayfayı aramayı örnek verdi. Doğrusal arama 1. sayfadan başlayıp tek tek bakar. İkili arama önce 150. sayfaya, sonra 225 civarına bakar. İnsan ise sayfa numaralarının sıralı ve her numaradan bir tane olduğunu bildiği için doğrudan sona yakın bir yeri açar, sonra biraz ileri biraz geri gider. Bu aslında bir interpolasyon işlemidir: araya değer uydurulur. Yani $(l+r)\cdot\frac{1}{2}$'deki $\frac{1}{2}$ yerine verinin dağılımına göre başka bir oran (ör. $\frac{3}{4}$) kullanılır.

Bu yönteme regula falsi, false position, yanlış nokta ya da doğrusal interpolasyon yöntemi denir. Yine doğrusal olmayan, analitik çözümü olmayan denklemler için kapalı bir yöntemdir ve önce $f(a)\cdot f(b) < 0$ gösterilir. Bisection'dan daha hızlı çalışır.

### 15.2 Formülün türetilmesi

$(a, f(a))$ ve $(b, f(b))$ noktalarından geçen bir doğru çizilir. Orta noktaya gitmek yerine bu doğrunun $x$ eksenini kestiği nokta yeni $c$ olarak alınır. Hoca bunu önce iki noktası bilinen doğru denkleminden kurdu:

$$\frac{y - f(b)}{x - b} = \frac{f(b) - f(a)}{b - a}$$

$x = c$ için $y = 0$ yazılınca $c$ elde edilir.

Slayt aynı sonucu $a\,f(a)\,c_1$ ve $b\,f(b)\,c_1$ üçgenlerinin benzerliğinden çıkarır (ekrandan, 02:45:00):

$$\frac{-f(a)}{c_1 - a} = \frac{f(b)}{b - c_1}$$

$$-f(a)(b - c_1) = f(b)(c_1 - a)$$

$$-f(a)\,b + f(a)\,c_1 = f(b)\,c_1 - f(b)\,a$$

$$f(a)\,c_1 - f(b)\,c_1 = f(a)\,b - f(b)\,a$$

$$c_1\big(f(a) - f(b)\big) = f(a)\,b - f(b)\,a$$

$$c_1 = \frac{b\,f(a) - a\,f(b)}{f(a) - f(b)}$$

Güncelleme kuralları (ekrandan, 02:30:00):

- $f(a)\cdot f(b) < 0$ ise $c = \dfrac{b\,f(a) - a\,f(b)}{f(a) - f(b)}$
- $f(a)\cdot f(c) < 0$ ise $b = c$
- $f(a)\cdot f(c) > 0$ ise $a = c$
- $f(a)\cdot f(b) = 0$ ise $a$ veya $b$'den biri ya da her ikisi de kök olabilir.

Her adımda yeni bir doğru çizilir, $c_1, c_2, \dots$ köke yaklaşır. Durdurma ölçütü olarak orta noktanın değişimi kullanılabilir (ekrandan, 02:35:00):

$$|c_i - c_{i+1}| < \varepsilon$$

### 15.3 Sayısal örnek

$x^3 - 2x^2 - 5 = 0$, $[2,3]$, hata 0,01 (ekrandan, 02:40:00). Hoca formülü $x = \dfrac{a\,f(b) - b\,f(a)}{f(b) - f(a)}$ biçiminde yazdı (pay ve paydanın ikisi de $-1$ ile çarpıldığı için slayttakiyle aynıdır).

- $f(2) = 8 - 8 - 5 = -5$, $f(3) = 27 - 18 - 5 = 4$; zıt işaretli, aralıkta kök var.
- $c_1 = \dfrac{2\cdot 4 - 3\cdot(-5)}{4 - (-5)} = \dfrac{8 + 15}{9} = \dfrac{23}{9} \approx 2{,}556$
- Orta nokta 2,5 olacakken regula falsi 2,556'ya bakar. $f(2{,}556) \approx -1{,}37$.
- $f(2) < 0$, $f(2{,}556) < 0$, $f(3) > 0$: kök $[2{,}556;\ 3]$'tedir; $a = 2{,}556$ olur.
- $c_2 \approx 2{,}669$, $f(2{,}669) \approx -0{,}23$. Kök $[2{,}669;\ 3]$'tedir.
- Sonraki adımda yaklaşık 2,69'a gidilir; değişim iyice küçülür ve algoritma durdurulabilir. Kök yaklaşık 2,69'dur.

Python ile doğrulandı: $c_1 = 2{,}5556$ ($f = -1{,}3717$), $c_2 = 2{,}6691$ ($f = -0{,}2338$), $c_3 = 2{,}6873$ ($f = -0{,}0363$); gerçek kök yaklaşık 2,6906'dır.

### 15.4 İnterpolasyon araması ve karmaşıklık

Regula falsi'nin dizilerdeki karşılığı interpolasyon aramasıdır (interpolation search). Karşılaştırma:

- Doğrusal arama: `for (i = 0; i < n; i++)` ile $n$ adım.
- İkili arama: genelde `while` ile, yaklaşık $\log_2 n + 1$ adım (+1 bulunamama durumu içindir).
- İnterpolasyon araması: $\log_2 \log_2 n$.

Hoca karmaşıklık sınıflarını hatırlattı: $O(1)$, $\log n$, $n\log n$, $n^2$, $n^3$. $2^{16}$ elemanlı bir dizide doğrusal arama 65.536 kontrol, ikili arama yaklaşık 17, interpolasyon araması $\log_2 \log_2 2^{16} = \log_2 16 = 4$ adım gerektirir. Bu kazanç, $\frac{1}{2}$ ile çarpmak yerine eldeki verilerden bir oran hesaplayan beş altı işlemlik küçük bir değişiklikle elde edilir.

> **Ek bilgi (derste anlatılmadı):** İnterpolasyon aramasının $\log\log n$ karmaşıklığı ortalama durum içindir ve verinin düzgün (uniform) dağıldığı varsayımına dayanır. Kötü dağılımlı verilerde en kötü durumda $n$ adıma kadar çıkabilir.

### 15.5 Kapalı yöntemlerin genel değerlendirmesi

Kapalı yöntemlerin amacı kökü iki sınır arasında kısıtlamak ve köke yaklaşmaktır. Kullanıcıdan $a$ ve $b$ alınır, $f(a)$ ve $f(b)$ hesaplanır, orta nokta $\frac{a+b}{2}$ ya da regula falsi formülüyle bulunur, orta noktanın değişimi izlenir. Yalnız toplama, çıkarma, çarpma ve bölme kullanılır. Bu yöntemler çoğu durumda yakınsar, ama zor bir fonksiyonda belli bir aralıkta takılıp çözüme çok geç ulaşabilirler. Hoca bu nedenle sonraki derste Newton-Raphson, sekant ve bunlardan türeyen açık yöntemlere geçileceğini söyledi: her yöntemin bir sıkıntısı vardır ve bir sonraki yöntem o sıkıntıyı çözmek için geliştirilmiştir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): $f(x) = \cos x$ fonksiyonunun Maclaurin açılımının sıfırdan farklı ilk 3 terimini bulunuz.

> **Çözüm (derste verildi):** $f'(x) = -\sin x$, $f''(x) = -\cos x$, $f'''(x) = \sin x$, $f^{(4)}(x) = \cos x$. $x=0$'da 2. ve 4. terimler sıfırdır. Sıfırdan farklı terimler $1$, $-\frac{x^2}{2}$, $\frac{x^4}{24}$; $\cos x \approx 1 - \frac{x^2}{2} + \frac{x^4}{24}$.

**Soru 2** (ekrandan, 00:30:00): $f(x) = e^x$ fonksiyonunun $x=4$ noktasında Taylor serisini bulunuz.

> **Çözüm (derste verildi):** $f^{(n)}(x) = e^x \Rightarrow f^{(n)}(4) = e^4$. $e^x = \sum_{n=0}^{\infty} \frac{e^4 (x-4)^n}{n!}$. İkinci dereceden polinom: $e^4\left[1 + (x-4) + \frac{(x-4)^2}{2}\right]$.

**Soru 3** (ekrandan, 00:50:00): Bir köprü ve perçinin uzunluklarını ölçmekle görevlendirildiğinizi ve bunları sırası ile 9.999 cm ve 9 cm olarak ölçtüğünüzü kabul edin. Gerçek değerler de sırası ile 10.000 cm ve 10 cm ise, her iki durum için a) gerçek hatayı ve b) bağıl hatayı yüzdesel olarak hesaplayınız.

> **Çözüm (derste verildi):** a) Köprü $10.000 - 9.999 = 1$ cm, perçin $10 - 9 = 1$ cm. b) Köprü $\frac{10000-9999}{10000}\cdot 100 = \%0{,}01$, perçin $\frac{10-9}{10}\cdot100 = \%10$.

**Soru 4** (ekrandan, 00:55:00): $f(x) = x^2 - 3x$ denklemi veriliyor. $x = 2$ değerini bu fonksiyona koyup hesaplayan biri sonucu 10 buluyor. Bu işlemdeki mutlak hata nedir?

> **Çözüm (derste verildi):** Gerçek değer $f(2) = -2$, hesaplanan 10. Mutlak hata $\left|\frac{-2-10}{-2}\right| = 6$ (yüzde olarak %600). Bölmesiz tanımla $|-2-10| = 12$.

**Soru 5** (ekrandan, 01:25:00): $f(x) = x^2 + 5$ fonksiyonunun $[1,5]$ aralığında ortalama değer teoremini sağlayan değerlerini bulunuz.

> **Çözüm (derste verildi):** $\frac{f(5) - f(1)}{5-1} = \frac{30-6}{4} = 6$; $f'(c) = 2c = 6 \Rightarrow c = 3$.

**Soru 6** (ekrandan, 01:40:00): $f(x) = x^2 - 6x + 5$ fonksiyonunun kökünü grafik yöntemiyle $x_0 = 1{,}5$, $\Delta x = 0{,}75$, $\varepsilon = 0{,}0235$ için bulunuz.

> **Çözüm (derste verildi):** İlk iterasyonda işaret 4,5 ($-1{,}75$) ile 5,25 ($+1{,}0625$) arasında değişir. $\Delta x$ her iterasyonda yarıya bölünür: 0,375; 0,1875; 0,094; 0,047; 0,0235. Altıncı iterasyonda $f(4{,}9925) = -0{,}0299$, $f(5{,}016) = 0{,}0640$ ve $x_{\text{kök}} \approx 5$.

**Soru 7** (derste sözlü, 01:41:05): Grafik yönteminin ilk iterasyonundaki tabloya göre kök hangi $x$ aralığındadır?

> **Çözüm (derste verildi):** $f(4{,}5) < 0$ ve $f(5{,}25) > 0$ olduğu için kök $[4{,}5;\ 5{,}25]$ aralığındadır.

**Soru 8** (derste sözlü, 01:49:35): Grafik yöntemini kodlasaydınız `for` mu `while` mı kullanırdınız?

> **Çözüm (derste verildi):** `while`; iterasyon sayısı önceden belli değildir ve bitme koşulu $\Delta x$'in değişimine bağlıdır.

**Soru 9** (derste sözlü, 02:12:39): Kök bulma algoritmasını $\Delta x$'in değişimi dışında neye bakarak durdurabiliriz?

> **Çözüm (derste verildi):** Bulunan değeri fonksiyonda yerine koyup $|f(x)|$'in sıfıra yeterince yaklaşmasına (ör. 0,001) ya da ardışık iki kök tahmininin farkının $|x_{i+1} - x_i| \le \varepsilon$ olmasına bakılabilir.

**Soru 10** (ekrandan, 02:20:00): $f(x) = x^3 - 7x^2 + 14x - 6$ fonksiyonunun $[0,1]$ aralığındaki kökünü yarıya bölme yöntemiyle $\varepsilon = 0{,}01$ için bulunuz.

> **Çözüm (derste verildi):** $c$ değerleri 0,5 ($-0{,}625$), 0,75 ($0{,}9844$), 0,625 ($0{,}2598$), 0,5625 ($-0{,}1618$). Dördüncü iterasyonda $\frac{0{,}625-0{,}5}{2^4} \approx 0{,}0078 < 0{,}01$; $x_{\text{kök}} \approx 0{,}5625$.

**Soru 11** (ekrandan, 02:40:00): $x^3 - 2x^2 - 5 = 0$ denkleminin $[2,3]$ aralığındaki kökünü regula falsi yöntemiyle 0,01 hata için bulunuz.

> **Çözüm (derste kısmen verildi):** $f(2) = -5$, $f(3) = 4$; $c_1 = \frac{23}{9} \approx 2{,}556$ ($f \approx -1{,}37$), $c_2 \approx 2{,}669$ ($f \approx -0{,}23$), sonra yaklaşık 2,69. Python ile devam edildiğinde $c_3 \approx 2{,}6873$, $c_4 \approx 2{,}6901$ bulunur; ardışık fark 0,01'in altına $c_3$-$c_4$ arasında iner ve kök yaklaşık 2,69'dur.

## Dersin Toparlaması

Bu derste önce sayısal yöntemlerin döngüleri durdurmak için neden hataya ihtiyaç duyduğu görüldü. Hata gerçek ile hesaplanan değerin farkı olarak tanımlandı ve dört türe ayrıldı. Kesme hatası için Taylor ve Maclaurin serileri tekrar edildi: karmaşık bir fonksiyon polinom cinsinden yazılır, açılım bir yerde kesilince geri kalan kısım kesme hatasıdır. Polinom fonksiyonlarda açılım kendi derecesinde tam sonuç verir. Bağıl hatanın farklı ölçekleri karşılaştırmayı mümkün kıldığı köprü-perçin örneğiyle gösterildi. Mutlak hata ve yuvarlama hatası ile programda gerçel sayıların eşik değerle karşılaştırılması konuşuldu.

İkinci yarıda doğrusal olmayan denklemlerin köklerine geçildi. Ortalama değer ve ara değer teoremleriyle, sürekli bir fonksiyonda $f(a)\cdot f(b) < 0$ ise aralıkta kök bulunduğu gösterildi. Kapalı yöntemlerden grafik yöntemi, ikiye bölme ve regula falsi sayısal örneklerle çözüldü; bisection ikili aramaya, regula falsi interpolasyon aramasına bağlandı. Kapalı yöntemlerin hep yakınsadığı ama yavaş olabildiği vurgulandı. Sonraki derste bu sorunu aşmak için Newton-Raphson ve sekant gibi açık yöntemlere geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
