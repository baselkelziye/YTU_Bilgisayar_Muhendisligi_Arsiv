# Ders 9 Genişletilmiş Notu: Kromatik Polinomlar ve Ağaçlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Graf Boyama ve Kromatik Sayı
- 2. Graf Boyamanın Kullanım Alanları
- 3. Kromatik Polinom ve Bilinen Graflar
- 4. Silme-Birleştirme Yöntemi
- 5. Ortak Parçadan Bölme Kuralı
- 6. Kromatik Polinomun Doğruluk Kuralları
- 7. Kromatik Polinom Örnekleri
- 8. Ağaçlara Giriş
- 9. Ağaç Terminolojisi ve Ağaçların Karakteristiği
- 10. İkili Ağaçlar
- 11. Tam İkili Ağaçlar
- 12. İkili Arama Ağaçları
- 13. Dengeli Ağaçlar
- 14. Sıralı Diziden İkili Arama Ağacı Oluşturma
- 15. Ağacın Diziye Yerleştirilmesi ve Dizide Arama
- Örnek Sorular
- Dersin Toparlaması

## 1. Graf Boyama ve Kromatik Sayı

Bu ders graflar konusunun devamıdır: graflarda görülen bazı graf türleri burada yeniden kullanılır. Hoca konunun ilk bakışta biraz garip görünebileceğini, ama örnekler çözüldükçe karmaşık olmadığının anlaşılacağını söyledi.

**Tanım.** Bir $G$ grafının her düğümüne, herhangi iki komşu düğüm aynı rengi almayacak biçimde bir renk atanmasına grafın **renklendirilmesi (boyanması)** denir.

Hoca bunu Türkiye haritasıyla anlattı. Siyasi haritada 81 ilin her biri bir renge boyanır ve komşu iller hiçbir zaman aynı renkte olmaz. Üşengeç biri 81 ili 81 farklı renge boyayabilir; kurala uyar, ama bu ideal çözüm değildir. Amaç **en az renkle** boyamaktır.

**Tanım.** Bir grafın **renk sayısı (kromatik sayısı)**, grafı renklendirmek için gereken en az renk sayısıdır ve $\chi(G)$ ile gösterilir. Kromatik polinom ise grafı bir polinoma dönüştürür; bu polinom üzerinde yapılan işlemle, komşu düğümler aynı renkte olmamak şartıyla grafın en az kaç renkle boyanacağı bulunur.

### 1.1 Elle boyama örnekleri

Slaytta iki graf vardı (ekrandan, 00:20:00):

- Bir kare ve köşegenlerinin kesiştiği yerde, dört köşeye de bağlı bir merkez düğüm (5 düğüm).
- Bir altıgen ve ortasında, altı köşeye de bağlı bir merkez düğüm (7 düğüm).

Hoca birinci grafı elle boyadı: sol üst köşe kırmızı; ona komşu olan sağ üst ve sol alt köşeler sarı (bu ikisi birbirine komşu değil). Merkez düğüm kırmızıyla ve sarıyla komşu olduğu için mavi. Sağ alt köşe hem maviye hem sarılara komşu olduğundan kırmızı olur. Böylece 3 renk yeter: $\chi(G) = 3$. Aynı grafı 4 renkle de boyamak mümkündür (örneğin bir köşeyi mor yapmak), ama soru en az renk sayısını sorduğu için "4" yanlış cevaptır.

Hoca bu graflara bakarken önce türlerini sordu: kare graf bir $K$ grafı değildir (her düğüm kendisi dışındaki bütün düğümlere komşu değildir), bir döngü (cycle) grafı da değildir. Dış kısmı bir döngü olan ve ortaya bütün düğümlere bağlı bir düğüm eklenen bu graflara tekerlek grafı denir. <!-- BELİRSİZ: altyazıda "Hil graf" yazıyor; büyük olasılıkla "wheel (tekerlek) graf" kastedildi. -->

Altıgen grafında dış döngünün düğümleri sırayla kırmızı ve sarı boyanır; merkez düğüm hepsine komşu olduğu için üçüncü bir renk (mavi) alır. Yine $\chi(G)=3$ olur. Hoca bu küçük grafları elle boyamanın kolay olduğunu, ama karmaşık graflarda bunun mantıklı olmadığını, daha hızlı bir yönteme ihtiyaç olduğunu söyledi.

## 2. Graf Boyamanın Kullanım Alanları

**Kurul toplantıları.** Bir üniversitede profesörlerden oluşan 10 öğrenci kulübü kurulu olsun. Her kurul haftada bir toplanacak; bir profesör birden fazla kurulda olabileceği için ortak üyesi olan kurulların toplantıları çakışmamalıdır. Bütün toplantılar ayrı günlere konursa iş 10 günde biter; ama ortak üyesi olmayan kurullar aynı zamana konarak süre kısaltılabilir. Hocanın verdiği sayılarla: 30 profesör, 10 kurul, her kurulda 5 profesör.

Bu problemde **kurullar düğüm**, ortak üyesi olan kurullar arasındaki bağlantılar **kenar** olur. Renkler farklı toplantı zamanlarını gösterir: aynı renkteki kurullar aynı gün ve saatte toplanabilir, kenarla bağlı kurullar farklı renk alır.

Slayttaki 10 düğümlü kurul grafı (ekrandan, 00:25:00) 4 renkle boyanmıştı ($\chi(G)=4$): aynı renkli düğümlerin toplantıları aynı oturumda yapılabilir; dört renk olduğu için bütün toplantılar dört oturumda tamamlanır.

**Ders programı.** Bir bölümün ders programında dersler, bir sınıfın dersleri birbiriyle çakışmayacak biçimde en az zaman dilimine yerleştirilmek istenir. Hoca bunun öğrenci bazında yapılmasının çok zor, sınıf bazında daha kolay olduğunu söyledi; bu da bir kromatik polinom problemidir.

## 3. Kromatik Polinom ve Bilinen Graflar

**Tanım.** $G$ grafının kromatik polinomu $P_G(x)$, $x$ renk varken $G$ grafının kaç farklı şekilde renklendirilebileceğini verir.

Kromatik polinomu yazmak için graf, bilinen en küçük graf parçalarına ayrılır, sonra bunlar üzerinde işlem yapılır. Elde edilen polinomda $x=0,1,2,\dots$ sırayla denenir. **Polinomu sıfırdan farklı yapan ilk $x$ değeri en az renk sayısıdır.** Bu değer polinomda yerine konduğunda çıkan sayı da o kadar renkle kaç farklı boyama yapılabileceğini gösterir.

Slayttaki "Kromatik polinomu bilinen graflar" (ekrandan, 00:30:00 ve 00:35:00):

### 3.1 Noktasal graf

Tek bir düğümden oluşan graftır. Elimizde $x$ renk varsa tek düğüm bunlardan herhangi biriyle boyanabilir; polinomu $x$'tir. Örneğin 10 renk varsa 10 farklı şekilde boyanır.

> **Ders sonrası not:** Hoca tek düğüme "pendant düğüm diyorduk" dedi. Graf terminolojisinde derecesi 1 olan düğüme pendant (sarkık) düğüm, hiç kenarı olmayan düğüme ise yalıtılmış (isolated) düğüm denir; tek başına duran düğüm yalıtılmış düğümdür.

### 3.2 Çizgisel graf (U grafı)

Düğümleri arka arkaya bir kenarla bağlanmış grafa (yol) çizgisel graf denir. İki düğümlüde ilk düğüm $x$ renkle boyanır; komşusu aynı renkte olamayacağı için $x-1$ renk kalır. Örneğin 5 renk varsa ilk düğüme biri kullanılır, ikinci düğüm kalan 4 renkle boyanır.

Çizgisel grafta düğüm sayısının 2 olması gerekmez; önemli olan arka arkaya bağlı olmalarıdır. Her yeni düğümün yalnız bir boyanmış komşusu olduğu için hep $x-1$ seçenek kalır. Hoca bunu yalnız iki rengi (kırmızı-sarı) dönüşümlü kullanarak gösterdi: komşular hiçbir zaman aynı renk olmaz. Formül:

$$U_n = x(x-1)^{n-1}$$

- $U_2 = x(x-1)$: bir düğüm $x$, bir düğüm $x-1$.
- $U_3 = x(x-1)^2$: bir tane $x$, iki tane $x-1$.
- $U_7 = x(x-1)^6$: bir düğüm $x$, diğer altı düğümün her biri $x-1$.

### 3.3 Z grafı ya da K grafı (tam graf)

Her düğüm kendisi dışındaki bütün düğümlere komşudur. Üçgende ilk düğüm $x$; ikinci düğüm $x-1$; üçüncü düğümün iki boyanmış komşusu olduğu için $x-2$ renk kalır. Elle boyamada üç düğüm üç farklı renk (kırmızı, sarı, mavi) alır. Genel formül:

$$K_n = \prod_{k=0}^{n-1}(x-k) = x(x-1)(x-2)\cdots(x-n+1)$$

$K_3$ için $k=0,1,2$ konur: $x(x-1)(x-2)$. Üçgen grafa $Z$ grafı da denir.

Dört düğümlü $K$ grafında (ekrandan, 00:40:00) düğümler sırayla $x$, $x-1$, $x-2$, $x-3$ renkle boyanır: dördüncü düğümün üç komşusu olduğundan üç renk çıkar. Elle boyamada dört düğüm dört farklı renk (kırmızı, sarı, mavi, yeşil) alır. Bu yüzden $K$ graflarında en az renk sayısı düğüm sayısına eşittir.

## 4. Silme-Birleştirme Yöntemi

Karmaşık bir graf bilinen graflara indirgenir. Bunun için şu yöntem kullanılır (hoca İngilizce adını söyledi):

1. Graftan bir kenar seçilir ve silinir. Kenar, grafı bilinen bir grafa indirgeyecek biçimde seçilir.
2. Silinen kenarın iki ucundaki düğümler birleştirilerek yeni bir graf elde edilir.
3. İlk graftan ikinci graf çıkarılır (farkı alınır).
4. Parçalardan biri hâlâ bilinmiyorsa aynı işlem ona uygulanır; en altta bilinen graflar kalana kadar sürer.

$$P_G(x) = P_{G-e}(x) - P_{G/e}(x)$$

Birleştirme yapılırken **kenarlar kırılmaz**. Hoca grafları esnek gibi düşünmeyi önerdi: bir düğüm diğerinin üstüne kapatılır ve o düğüme bağlı kenarlar, karşı düğümün ilgili kenarlarının üstüne oturur; üst üste gelen iki kenar tek kenar olur.

> **Ek bilgi (derste anlatılmadı):** Bu yöntem ders kitaplarında silme-büzme (deletion-contraction) diye geçer. $G-e$, $e$ kenarının silindiği graf; $G/e$ ise $e$'nin iki ucunun tek düğümde birleştirildiği ve oluşan katlı kenarların teke indirildiği graftır. Mantığı şudur: $G-e$'nin boyamaları, $e$'nin uçlarının farklı renk aldığı boyamalar ($G$'nin boyamaları) ile aynı renk aldığı boyamalar ($G/e$'nin boyamaları) toplamıdır.

### 4.1 $K_4$ grafına yöntemin uygulanması

Slaytta 1, 2, 3, 4 numaralı düğümleri olan bir $K_4$ vardı (ekrandan, 00:45:00 ve 00:50:00). Hoca, grafın $K$ grafı olduğunu görmediğimizi varsayarak yöntemi uyguladı. Hangi kenarın seçileceği kişiden kişiye değişebilir; burada 1-4 kenarı seçildi.

- **Birinci adım:** 1-4 kenarı silinince bir köşegenli kare (1-2, 1-3, 3-4, 2-4 ve 2-3 köşegeni) kalır. 1 ile 4 birleştirilince "1,4", 2 ve 3 düğümlerinden oluşan bir üçgen çıkar. Üçgeni tanıyoruz ($Z$ grafı), köşegenli kareyi tanımıyoruz.
- **İkinci adım:** Köşegenli kareden 2-3 kenarı silinir: kare (1-2, 2-4, 4-3, 3-1) kalır. 2 ile 3 birleştirilince 1 - "2,3" - 4 biçiminde üç düğümlü bir çizgisel graf çıkar.
- **Üçüncü adım:** Kareden 2-4 kenarı silinir: 2-1-3-4 biçiminde dört düğümlü çizgisel graf kalır. 2 ile 4 birleştirilince 1, 3 ve "2,4" düğümlerinden oluşan bir üçgen çıkar. Artık hepsi bilinen graflardır.

Hoca, istenirse noktasal grafa kadar bölünebileceğini, ama işin çok uzayacağını söyledi.

Çözüm sondan başa doğru yapılır:

**Kare (ekrandan, 00:50:00):**

$$P_{C_4} = x(x-1)^3 - x(x-1)(x-2) = x(x-1)\big[(x-1)^2-(x-2)\big] = x(x-1)(x^2-3x+3)$$

Köşeli parantezin içi: $x^2-2x+1-x+2 = x^2-3x+3$.

**Köşegenli kare:** Kareden üç düğümlü çizgisel graf çıkarılır:

$$x(x-1)(x^2-3x+3) - x(x-1)^2 = x(x-1)\big[x^2-3x+3-(x-1)\big] = x(x-1)(x^2-4x+4) = x(x-1)(x-2)^2$$

**$K_4$:** Köşegenli kareden üçgen çıkarılır:

$$x(x-1)(x-2)^2 - x(x-1)(x-2) = x(x-1)(x-2)(x-3)$$

Hoca, grafın $K_4$ olduğu baştan görülseydi doğrudan $x(x-1)(x-2)(x-3)$ yazılıp aynı sonucun bulunacağını söyledi.

### 4.2 Silinecek kenar nasıl seçilir?

**Soru:** Silinecek kenarı sezgisel olarak mı seçiyoruz, yoksa bunun bir algoritması var mı?

**Cevap:** Sezgiseldir, ama "kafadan atma" değildir. Kendinize "grafı tanıdığım bir grafa benzetmek için hangi kenarı koparmam gerekiyor?" diye sorarsınız. Başka bir kenar da koparılabilir, ama işlem adımları uzar. Çok karmaşık graflarda ilk kenarı tahmin etmek zor olabilir; rastgele bir kenarla başlanır. Ama ilerledikçe, örneğin ortadaki kenar koparılınca bir kare, sonra bir kenar daha koparılınca bir çizgisel graf kalacağı ya da bir üçgen bırakılacağı görülür.

## 5. Ortak Parçadan Bölme Kuralı

Slayttaki kural (ekrandan, 00:55:00): **Eğer iki graf birbirinden noktasal ya da çizgisel bir graf ile ayrılıyorsa,** grafın polinomu iki parçanın polinomlarının çarpımının, ortak parçanın polinomuna bölümüdür:

$$P_G = \frac{P_{G_1}\cdot P_{G_2}}{P_{\text{ortak}}}$$

**Örnek: köşegenli kare (ekrandan, 01:00:00).** Köşegenli kare bilinen bir graf değildir, ama içinde ortak bir kenarı paylaşan iki üçgen vardır. Ortak parça bir kenar (iki düğümlü çizgisel graf) olduğu için:

$$P_G = \frac{\big[x(x-1)(x-2)\big]^2}{x(x-1)} = x(x-1)(x-2)^2 = (x^2-x)(x^2-4x+4) = x^4-5x^3+8x^2-4x$$

$x=0$ için 0, $x=1$ için 0 (çarpanlarda $x-1$ var), $x=2$ için 0 (çarpanlarda $x-2$ var). $x=3$ için $3\cdot 2\cdot 1^2 = 6$. Ekrandaki sonuç: **3 renk ile boyanır, $3\cdot2\cdot1 = 6$ değişik şekilde.**

Hoca iki örnek daha çizdi:

- İki üçgen tek bir ortak noktada birleşiyorsa: iki üçgenin çarpımı, ortak noktasal grafa ($x$) bölünür.
- Bir üçgen ile bir çizgi bir noktada birleşiyorsa: üçgen ile çizgisel grafın çarpımı noktasal grafa bölünür.

> **Ek bilgi (derste anlatılmadı):** Bu kural, iki grafın kesişimi bir tam graf ($K_r$) olduğunda geçerlidir: $P_G = P_{G_1}P_{G_2}/P_{K_r}$. Nokta $K_1$, tek kenar $K_2$'dir. Kesişim tam graf değilse (örneğin iki ayrık düğüm), formül genel olarak doğru sonuç vermez.

### 5.1 Katsayılarla hızlı çarpma

Hoca polinom çarpımında hatayı azaltmak için şu yolu gösterdi (ekrandan, 00:40:00 ve 01:00:00): **işaretler dikkate alınmadan** yalnız katsayılar yazılır, ikinci çarpanın her katsayısıyla çarpılıp bir basamak kaydırılarak alt alta toplanır.

$(x^2-x)(x^2-5x+6)$ için: $1\,5\,6$ ile $1\,1$ çarpılır.

```text
    1 5 6
      1 1
  -------
    1 5 6
  1 5 6
  -------
  1 6 11 6
```

Kromatik polinomda **sabit terim olmadığı** için son katsayı $x$'in katsayısıdır; sola doğru $x^2$, $x^3$, $x^4$ gelir. İşaretler $+,-,+,-$ diye dağıtılır: $x^4-6x^3+11x^2-6x$.

$(x^2-x)(x^2-4x+4)$ için: $1\,4\,4$ ile $1\,1$ çarpılır, $1\,5\,8\,4$ çıkar ve sonuç $x^4-5x^3+8x^2-4x$ olur.

**Soru:** Son çarpma bir daha yapılabilir mi?

**Cevap:** Birinci çarpanın katsayıları $1\,4\,4$, ikincisinin $1\,1$'dir. Çarpanların sırasını değiştirmek bir şey değiştirmez. Kaydırarak toplayınca $1\,5\,8\,4$; sağdan sola $x$, $x^2$, $x^3$, $x^4$ ve işaretler dönüşümlü.

## 6. Kromatik Polinomun Doğruluk Kuralları

Bulunan polinomun doğru olup olmadığı şu kurallarla kontrol edilir (ekrandan, 01:15:00):

1. $a_1$ (baş katsayı) her zaman 1 olmalıdır. Başka bir sayı çıktıysa ya işlem yanlış yapılmış ya da graf yanlış bölünmüştür.
2. Polinomun derecesi grafın düğüm sayısını verir.
3. İkinci terimin katsayısı grafın kenar sayısını verir (işaretsiz olarak).
4. Terimlerin katsayılarının toplamı 0 olur.
5. Polinomun katsayılarının işaretleri $+,-,+,-,\dots$ diye gider.
6. Polinomda sabit terim olmaz.

**Köşegenli kare** ($x^4-5x^3+8x^2-4x$): baş katsayı 1; derece 4 = düğüm sayısı; 5 kenar; $1-5+8-4=0$; işaretler dönüşümlü; sabit terim yok.

**$K_4$** ($x^4-6x^3+11x^2-6x$): baş katsayı 1; 6 kenar; $1-6+11-6 = 0$; işaretler dönüşümlü; sabit terim yok.

> **Hocanın vurgusu:** Farklı biçimlerde kesersen farklı görünen ara sonuçlar bulabilirsin, ama derece, kenar sayısı, katsayı toplamı, işaretler ve sabit terimle ilgili kurallar hep aynı kalır. Bulacağın en az renk sayısı ve kaç farklı şekilde boyanacağı da aynı olur.

## 7. Kromatik Polinom Örnekleri

### 7.1 Ortasında düğüm olan üçgen ($K_4$)

Slaytta, üçgenin ortasındaki düğümün üç köşeye de bağlı olduğu bir graf vardı (ekrandan, 01:20:00). Bu aslında bir $K$ grafıdır (her düğüm diğer üçüne komşu), ama hoca bunun görülmediğini varsayarak çözdü.

- Dış kenarlardan biri ($\alpha$) silinir; kalan graftan, kenarın uçlarının birleştirildiği üçgen çıkarılır. Birleştirmede bir kenar diğerinin üstüne oturur.
- Kalan graf, ortak kenarı olan iki üçgendir. Ortak parçadan bölme kuralıyla:

$$\frac{x^2(x-1)^2(x-2)^2}{x(x-1)} = x(x-1)(x-2)^2$$

Sonuç (ekrandan, 01:20:00):

$$x(x-1)(x-2)^2 - x(x-1)(x-2) = x(x-1)(x-2)\big[(x-2)-1\big] = x(x-1)(x-2)(x-3) = x^4-6x^3+11x^2-6x$$

$x=0,1,2,3$ için değer 0; $x=4$ için $4\cdot3\cdot2\cdot1 = 24$. Graf **4 renkle, 24 farklı şekilde** boyanır.

### 7.2 Ortasında düğüm olan kare

Bir üst seviyedeki örnek (ekrandan, 01:25:00): köşeleri 1, 2, 3, 4 olan karenin kenarları 1-2, 2-4, 4-3, 3-1; ortadaki 5. düğüm dört köşeye de bağlı (5 düğüm, 8 kenar). Bu graf ne noktasal, ne çizgisel, ne de $K$ grafıdır: örneğin 1. düğüm 4. düğüme komşu değildir.

- **Birinci satır:** 2-4 kenarı silinir. 2 ile 4 birleştirilince "2,4" düğümü 1, 3 ve 5'e bağlanır; 1, 3, 5 de birbirine bağlı olduğundan çıkan graf $K_4$'tür ve polinomu bir önceki örnekte bulunmuştu: $x^4-6x^3+11x^2-6x$.
- **İkinci satır:** Kalan graftan (1-2, 1-3, 3-4 ve 5'in dört kenarı) 1-2 kenarı silinir. 1 ile 2 birleştirilince "1,2" - 3 - 5 ve 3 - 4 - 5 üçgenlerinden oluşan, ortak kenarı 3-5 olan bir graf çıkar. Hoca bu tanıdık parçaya kısaca **$A$** dedi.
- **Üçüncü satır:** Kalan grafta 2. düğüm yalnız 5'e bağlıdır. 2-5 kenarı silinince bir $A$ grafı ve yanında tek başına bir noktasal graf kalır: $A\cdot x$. 2 ile 5 birleştirilince yine $A$ çıkar. Burada farklı bir durum vardır: silme sonucunda graf iki parçaya ayrılır.

Hesap sondan başa (ekrandan, 01:25:00):

$$\text{3. satır} = A\cdot x - A = A(x-1)$$

$$\text{2. satır} = A(x-1) - A = Ax - A - A = Ax - 2A = A(x-2)$$

$$\text{1. satır} = A(x-2) - (x^4-6x^3+11x^2-6x)$$

$A$ köşegenli karenin polinomudur: $A = x(x-1)(x-2)^2$. Yerine konunca:

$$P_G = x^5-8x^4+24x^3-31x^2+14x$$

Kontrol (hocanın yaptığı gibi): 5 düğüm, 8 kenar; işaretler $+,-,+,-,+$; sabit terim yok. Pozitif katsayılar $1+24+14 = 39$, negatifler $-8-31 = -39$; toplam 0. Bu yüzden polinom doğrudur.

Hoca en az renk sayısını bulmak için $x=0,1,2,3,\dots$ sırayla denenmesi gerektiğini söyledi, ama bu grafın sonucunu söylemedi.

> **Çözüm (derste verilmedi):** Python ile: $P_G(0)=P_G(1)=P_G(2)=0$, $P_G(3) = 6$. Graf 3 renkle 6 farklı şekilde boyanır. Bu, bölüm 1.1'deki elle boyamayla ($\chi(G)=3$) uyumludur.

### 7.3 Daha büyük bir graf

Hoca 8 düğümlü, 12 kenarlı bir graf da gösterdi ve elle çözümünün iki A4 sayfası kadar uzun sürdüğünü söyledi. Farklı kesme sıralarıyla farklı görünen polinomlar bulunabilir, ama derece 8, ikinci katsayı 12, katsayılar toplamı 0, işaretler dönüşümlü ve sabit terim yok kuralları hep sağlanır. <!-- BELİRSİZ: bu grafın şekli ve polinomu kareden okunamadı. -->

## 8. Ağaçlara Giriş

Ağaçlar kapsamlı bir konudur (slayt kapağı: "Bölüm 4, Trees (Ağaçlar)", ekrandan, 01:30:00). Hoca ağaçların içindeki infix, postfix ve prefix gösterimlerinin bu dersin algoritmalar bölümüne alındığını söyledi.

Ağaçlar **grafların özel bir hâlidir**. Bir grafa, kapalı bir döngü (çevrim) oluşturacak bir kenar eklenirse ona artık ağaç denmez. Tersine, bir grafın içindeki bütün kapalı döngüler silinirse elde edilen yapı bir ağaçtır.

**Tanım.** Bir ağaç, düğümler ve kenarlardan oluşan, döngü içermeyen basit bir graftır. Döngü olmadığı için bir düğümden diğerine **yalnız tek bir yol** vardır.

**Köklü ağaç.** Kök bilgisi verilmemişse ağacın kökü yoktur; hiçbir düğüm kök değildir. Bir düğümün kök olduğu söylenirse ağaç köklü ağaç olur. Hoca bunu üzüm salkımıyla anlattı: salkımı sapından tutarsınız; sap kök (root), üzüm taneleri düğümlerdir.

**Seviye.** Köklü bir $T$ ağacında bir $v$ düğümünün seviyesi $L(v)$, o düğümden köke giden yolun uzunluğudur. Kökün seviyesi 0'dır; köke bir kenarla bağlı düğümün seviyesi 1; köke iki kenarla ulaşan düğümün seviyesi 2'dir.

**Yükseklik.** Ağacın yüksekliği, en büyük seviyeye sahip düğümün seviyesidir. Hocanın örneğinde seviyeler 0, 1, 2, 2, 3 olduğu için yükseklik 3'tür. Kısacası, en uzaktaki düğüm ile kök arasındaki mesafe ağacın yüksekliğidir.

**Soru:** Hangi düğümün kök olduğu bize söylenir mi?

**Cevap:** Söylenmesi gerekir. Kök bilgisi verilmezse ağacın yüksekliği söylenemez.

## 9. Ağaç Terminolojisi ve Ağaçların Karakteristiği

### 9.1 Terminoloji

Graflarda yalıtılmış düğüm, $K$ grafı, döngü grafı gibi bir terminoloji olduğu gibi ağaçların da kendi terminolojisi vardır (ekrandan, 01:35:00):

- **Parent (ana/baba, ebeveyn):** Bir düğümün hemen üstündeki düğüm. Kök de bir parent'tır.
- **Ancestor (ata):** Bir düğümden önce gelen bütün düğümler. Hoca bunu "babam, dedem, dedemin babası..." diye anlattı: parent da bir atadır.
- **Child (çocuk):** Bir parent'tan çıkan bütün düğümler.
- **Descendant (torun):** Çocuklar ve çocukların çocukları.
- **Siblings (kardeş düğüm):** Aynı parent'tan çıkan düğümler.
- **Terminal vertices (uç düğüm):** Kendisinden dal çıkmayan düğümler (yapraklar).
- **Internal vertices (ara düğüm):** Kendisinden dal çıkan düğümler. Kökten de dal çıktığı için kök de bir ara düğümdür. Yani bir düğüm yerine göre parent, yerine göre ata, yerine göre ara düğüm olabilir.
- **Subtrees (alt ağaçlar):** Ağacın içindeki küçük ağaçlar; her birinin kendi kökü ve yaprakları vardır. Alt ağacın düğümleri ve kenarları ana ağacın düğüm ve kenarlarının içindedir. Ağacın tamamı alt ağaç sayılmaz, ağacın kendisidir.

### 9.2 Ağaçların karakteristiği

**Teorem (ekrandan, 01:40:00).** $T$, $n$ düğümlü bir graf ise aşağıdakiler doğrudur (birbirine denktir):

- a) $T$ bir ağaçtır.
- b) $T$ bağlantılı (connected) ve acyclic'tir ("acyclic" = döngü mevcut değil; "cyclic" döngü demektir, başındaki "a" olumsuzluk ekidir).
- c) $T$ bağlantılıdır ve $n-1$ kenara sahiptir.
- d) $T$ acyclic'tir ve $n-1$ kenara sahiptir.

Hocanın örneğinde 10 düğümlü bir ağaç vardı ve kenarlar sayıldığında 9 çıktı.

## 10. İkili Ağaçlar

Ağaçların en özel hâllerinden biri, hocanın deyişiyle bilgisayar bilimcilerin en çok sevdiği ağaç olan **ikili ağaçtır (binary tree)**: her düğümden en fazla iki kenar çıkar; ikiden fazla çıkamaz.

Hoca bir örnek ağaç üzerinde (A kök olarak seçildiğinde) kavramları sordu: kök söylenmelidir; G, D ya da I da kök seçilebilir. Hangi düğüm kök denirse o düğüm üzüm salkımının sapı gibi tutulup diğerleri aşağı bırakılır. A kök olunca çocukları B (sol çocuk, left child) ve C (sağ çocuk, right child) olur. Kardeş düğümler aynı parent'a bağlı olanlardır (B ve C gibi). Bir düğümün torunları, altında kalan bütün düğümlerdir. <!-- BELİRSİZ: bu örnek ağacın şekli kareden doğrulanamadı; uç ve ara düğüm listeleri nota alınmadı. -->

> **Ders sonrası not:** Hoca bir yerde "binary tree'de sıfır ya da iki çocuk olur" dedi. İkili ağaçta bir düğümün 0, 1 ya da 2 çocuğu olabilir (hocanın baştaki tanımı da "en fazla iki" idi). "Her düğümün ya 0 ya 2 çocuğu vardır" özelliği tam (full) ikili ağaca aittir.

### 10.1 Matematiksel ifadelerin gösterimi

İkili ağaçlar matematiksel ifadeleri göstermekte kullanılır (ekrandan, 01:45:00). İşleç (operatör) işlenenlerin (operand) ortasında yazılıyorsa bu bir infix ifadesidir. Ağaçta işleç kökte, işlenenler çocuklardadır:

- (a) $a-b$: kök $-$, sol çocuk $a$, sağ çocuk $b$.
- (b) $a-b/c$: işlem önceliğine göre önce $b/c$ yapılır, sonra sonuç $a$'dan çıkarılır. Kök $-$, sol çocuk $a$, sağ çocuk $/$; $/$'nin çocukları $b$ ve $c$.
- (c) $(a-b)*c$: önce parantez içi yapılır, sonra $c$ ile çarpılır. Kök $*$, sol çocuk $-$ (çocukları $a$ ve $b$), sağ çocuk $c$.

Hoca derste sözlü bir örnek daha verdi: $a/b + (c-d)/a$ ifadesinin ağacı. <!-- BELİRSİZ: ifadenin yazılışı ekranda görülmedi; hocanın anlatımına göre ikinci terim (c-d)/a olarak kuruldu. -->

**Soru:** İfadede iki tane $a$ var; ağaçta bu bir çevrim oluşturmaz mı?

**Cevap:** İsterseniz ikincisine $g$ deyin; ama $a$ da olabilir. Önce $a/b$ yapılır (bir $/$ düğümü), sonra $c-d$ (bir $-$ düğümü) ve bu $a$'ya bölünür (ikinci $/$ düğümü). İki bölümün sonucu toplanacağı için kökte $+$ vardır.

Hoca ayrıca $a - b/c*d$ ifadesini sordu: soldan sağa öncelik olduğu için önce $b/c$, sonra sonuç $d$ ile çarpılır, en son $a$'dan çıkarılır. Kök $-$, sol çocuk $a$, sağ çocuk $*$; $*$'ın sol çocuğu $/$ ($b$, $c$), sağ çocuğu $d$.

### 10.2 Yükseklik örnekleri

Hoca birkaç ikili ağacın yüksekliğini sordu. Kök seviye 0, çocukları seviye 1, onların çocukları seviye 2 olan ağacın yüksekliği 2'dir. Kökten en dıştaki düğüme 4 kenarla gidilen ağacın yüksekliği 4, 6 kenarla gidilen ağacın yüksekliği 6'dır. Yükseklik ya en büyük seviye olarak ya da en dıştaki düğümden köke giden yol uzunluğu olarak bulunur.

Hoca bu ağaçlar arasında, kökün iki yanındaki eleman sayıları eşit olan ağaca terazi gibi düşünülerek "dengeli" denebileceğini, diğerlerinde dengenin olmadığını da söyledi (bölüm 13).

### 10.3 $n$ düğümle kaç ikili ağaç çizilir?

- 0 düğüm: hiçbir ağaç çizilemez (boş).
- 1 düğüm: 1 ağaç (tek düğüm, hiç kenar yok).
- 2 düğüm: 2 ağaç (köke sol çocuk ya da sağ çocuk eklenir).
- 3 düğüm: 5 ağaç (hepsi solda; hepsi sağda; sol sonra sağ; sağ sonra sol; kökün iki yanında birer çocuk).

## 11. Tam İkili Ağaçlar

Hoca "tam" kavramını tam grafla ilişkilendirdi: tam grafta her düğüm diğer bütün düğümlere bağlıydı. **Tam ikili ağaçta (full binary tree)** her seviyede olması gereken bütün düğümler vardır: seviye $L$'de $2^L$ düğüm bulunur. Seviye 0'da $2^0=1$, seviye 1'de 2, seviye 2'de 4, seviye 3'te $2^3 = 8$ düğüm. Bunlardan biri eksikse ağaç yalnızca ikili ağaç adını alır.

Slayttaki özellikler (ekrandan, 01:55:00), tam ikili ağaçta:

- $t$ adet uç düğüm varsa ağacın yüksekliği için $\lg t \le h$.
- $i$ adet ara düğüm varsa $i+1$ adet uç düğüm vardır.
- $i$ adet ara düğüm varsa toplam düğüm sayısı $2i+1$'dir.
- Örnek: $k = 4$ ara düğüm (a, b, c ve f) ve 5 uç düğüm (d, e, g, h ve i), toplamda 9 düğüm.

**$\lg t \le h$ örneği.** Seviye 3'e kadar dolu bir ağaçta 8 uç düğüm vardır: $\log_2 8 = \log_2 2^3 = 3 \le h$, yükseklik 3. Son seviyedeki bazı düğümler olmasaydı ve 5 uç düğüm kalsaydı: $\log_2 5$, 2'den büyük, 3'ten küçüktür ($\approx 2{,}32$). Yükseklik tam sayı olduğundan yukarı yuvarlanır ve 3 bulunur.

> **Ders sonrası not:** Hoca yuvarlamayı "kendisinden büyük en büyük tam sayı" diye söyledi; doğrusu kendisinden büyük ya da eşit **en küçük** tam sayıdır (tavan, $\lceil \log_2 5 \rceil = 3$).

> **Ek bilgi (derste anlatılmadı):** Kaynaklarda terimler farklı kullanılır. Her düğümün 0 ya da 2 çocuğu olan ağaca genellikle "full (tam) binary tree", her seviyesi tamamen dolu ağaca "perfect (mükemmel) binary tree" denir. Slayttaki a...i ağacı her seviyesi dolu değildir, ama her ara düğümün iki çocuğu vardır; $i+1$ ve $2i+1$ formülleri bu özellikten gelir.

## 12. İkili Arama Ağaçları

**İkili arama ağaçları (binary search trees)** (ekrandan, 02:00:00):

- Veri düğümlere yerleştirilir.
- Veri alfabetik sırada ağaca yerleştirilir: bir düğümün sol tarafındaki veri o düğümdeki veriden küçüktür,
- sağ tarafındaki veri de o düğümdeki veriden büyüktür.

**Örnek:** "Computers are an important technological tool" cümlesi.

- İlk kelime COMPUTERS köke konur.
- ARE: ilk harfi A, C'den önce gelir; COMPUTERS'ın soluna.
- AN: C'den küçük, sola gidilir; ARE ile ilk harfler aynı, ikinci harflerde N, R'den önce gelir; ARE'nin soluna.
- IMPORTANT: I, C'den büyük; COMPUTERS'ın sağına.
- TECHNOLOGICAL: C'den büyük, I'dan büyük; IMPORTANT'ın sağına.
- TOOL: C'den ve I'dan büyük; TECHNOLOGICAL ile ilk harf aynı, ikinci harfte O, E'den sonra gelir; TECHNOLOGICAL'ın sağına.

> **Ders sonrası not:** Hoca TECHNOLOGICAL için "sol tarafına yerleştirdik" dedi. Ekrandaki ağaçta ve kurala göre (T, I'dan büyük) TECHNOLOGICAL, IMPORTANT'ın **sağ** çocuğudur.

**Arama.** Her düğümde aranan kelimenin o düğümdekinden sözlük sırasına göre küçük mü büyük mü olduğuna bakılır: küçükse sola, büyükse sağa gidilir. Hoca bunu cümleye bulunmayan bir kelime ("AI") arayarak gösterdi: C'den küçük, sola; ARE ile ikinci harflerde I, R'den önce, sola; AN ile ikinci harflerde I, N'den önce, sola. Sol taraf boş olduğu için kelime cümlede yoktur. İstenirse kelime tam bu boş yere, AN'nin soluna eklenir.

Hoca, bir ağaca eleman eklemenin, eleman silmenin ve bir metni ağaca yerleştirip kelime aramanın algoritmalar dersinde ayrıntılı görüleceğini söyledi.

## 13. Dengeli Ağaçlar

**Dengeli ağaç (balanced tree)** (ekrandan, 02:05:00): yüksekliği $h$ olan bir ağacın yapraklarının seviyesi $h$ ya da $h-1$ ise ağaç dengeli ağaç adını alır.

Hoca bunu bir terazi gibi anlattı: kökten tutulduğunda sol ve sağ taraftaki düğüm sayıları birbirine yakın olmalıdır. Pratik ölçüt: **köke en uzak uç düğüm ile köke en yakın uç düğüm arasındaki seviye farkı en fazla 1 ise ağaç dengelidir; 1'den büyükse dengesizdir.**

- Slayttaki "Dengeli ağaç": en uzak yaprak seviye 3, en yakın yaprak seviye 2; fark 1, dengeli.
- Slayttaki "Dengesiz ağaç": en uzak yaprak seviye 4, en yakın yaprak seviye 2; fark 2, dengesiz.

Hoca bir önceki slayttaki ağaçlar için de aynı ölçütü uyguladı: en uzak ve en yakın yaprak seviyeleri 2 ve 2 olan ağaç dengeli; 4 ve 1 olan ağaç dengesizdir. 4 ve 3 olacak biçimde değiştirilirse dengeli olur. En uzak yaprağı 6. seviyede olan, tek kollu ağaçta fark çok büyüktür; dengesizdir.

**Soru:** Dengeli ağaçta yalnız uç (yaprak) düğümlere mi bakıyoruz, yoksa herhangi bir bitiş noktasına mı?

**Cevap:** Uç düğümlere bakılır. Seviyesi en büyük olan uç düğüm ile köke en yakın uç düğüm karşılaştırılır; aradaki fark birden büyükse ağaç dengesizdir.

**Soru:** En sağdaki (tek kollu) ağaçta tek bir uç nokta var, değil mi?

**Cevap:** Evet, ama bu bir ikili ağaçtır ve kökün bir tarafında hiç çocuk yoktur. Bu, çok istisnai bir durumdur; ölçmeye bile gerek kalmadan dengesiz olduğu bellidir.

> **Hocanın vurgusu:** Çizim yanıltabilir. Bir ağaç, farklı seviyelerdeki yapraklar aynı hizada görünecek şekilde çizilebilir; aceleyle dengeli denebilir. Seviyeler mutlaka kenar sayılarak bulunmalıdır.

## 14. Sıralı Diziden İkili Arama Ağacı Oluşturma

Hoca, sıralı bir sayı dizisini arama yapılabilecek bir ikili ağaca yerleştirmeyi gösterdi (ekrandan, 02:35:00). Dizi: $1, 3, 4, 5, 6, 10, 16, 17, 19$ (hoca devamında 21 ve 25'i de ekledi). Ağaç okunurken önce sol dal, sonra kök, sonra sağ dal okunur ve sıra bozulmamalıdır.

Ekrandaki ilk adımlar:

- $1, 3, 4$: kök 3, sol çocuk 1, sağ çocuk 4.
- 5 eklenir: 3'ten büyük, 4'ten büyük, 4'ün sağına gelir. Ama hocanın kuralına göre önce sol dalın dolu olması gerekir; bu yüzden 5 yukarı (4'ün yerine) çıkar, 4 onun sol çocuğu olur. Ağaç: kök 3; sol 1; sağ 5, 5'in solu 4. Okuma sırası $1, 3, 4, 5$ bozulmaz. En uzak yaprak 2, en yakın yaprak 1 seviyede olduğu için ağaç dengelidir.
- 6 eklenir: 3'ten ve 5'ten büyük, 5'in sağına gelir. Ağaç yine dengelidir.

Hoca bundan sonra kökün iki yanındaki eleman sayılarını da eşitlemek istedi: ikili aramada dizi her adımda ikiye bölündüğü için kökün sol ve sağ tarafındaki eleman sayıları eşit ya da en fazla 1 farklı olmalıdır. Örneğin 6 eklendikten sonra 3'ün solunda 1, sağında 3 eleman vardır; sağdaki bir eleman sola aktarılır ve kök 4 olur (iki yanında ikişer eleman). Her yeni elemanda (10, 16, 17, 19, 21, 25) aynı kontrol yapılır; denge bozulursa sağ taraftaki en küçük eleman köke çıkar, kökteki eleman sola iner ve elemanlar buna göre kaydırılır. <!-- BELİRSİZ: 6'dan sonraki adımların ağaç şekilleri kareden doğrulanamadı; hocanın sözlü anlatımı karışık olduğu için ara ağaçlar nota alınmadı. -->

Hoca işlemi şöyle özetledi: üç elemanla başlanır (sol, kök, sağ); sonraki her eleman kontrol edilerek yerleştirilir; önce sol, sonra sağ dolar. Sağa eleman gelmişse sağdaki köke, kökteki sola alınarak döndürülür.

## 15. Ağacın Diziye Yerleştirilmesi ve Dizide Arama

Slayttaki problem (ekrandan, 02:45:00): ikili aramaya uygun biçimde verilmiş $23, 13, 19, 47, 11, 43, 7, 29, 52$ dizisini belli bir kurala göre bir ağaca yerleştirelim.

**Ağaca yerleştirme:** 23 kök. 13 < 23, sola. 19: 23'ten küçük, 13'ten büyük; 13'ün sağına. 47 > 23, sağa. 11: 23'ten ve 13'ten küçük; 13'ün soluna. 43: 23'ten büyük, 47'den küçük; 47'nin soluna. 7: 23, 13 ve 11'den küçük; 11'in soluna. 29: 23'ten büyük, 47'den ve 43'ten küçük; 43'ün soluna. 52: 23'ten ve 47'den büyük; 47'nin sağına.

**Ağaçta arama:** 43 aranırsa: 23'ten büyük, sağa; 47'den küçük, sola; 43 bulunur. 25 aranırsa: 23'ten büyük, 47'den küçük, 43'ten küçük, 29'dan küçük; 29'un altında dal olmadığı için 25 bu dizide yoktur.

**Diziye geçirme.** Bunu bir algoritma olarak yapmak için ağaç bir diziye yerleştirilir. Kök 1 numaralı gözdür; **bir düğümün sol çocuğu indisin 2 katı, sağ çocuğu 2 katının bir fazlası** olan gözdedir. Olmayan dalların indisleri de sayılır (9, 10, 11, 13, 14, 15 boştur).

| İndis | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Değer | 23 | 13 | 47 | 11 | 19 | 43 | 52 | 7 | 0 | 0 | 0 | 29 | 0 | 0 | 0 |

En büyük adres 12 olduğu için dizi en az 12 gözlü olmalıdır.

**Dizide 7'yi arama (derste yapıldı):** indis 1'de 23; $7 < 23$, sola: $2\cdot1 = 2$. İndis 2'de 13; $7 < 13$: $2\cdot2 = 4$. İndis 4'te 11; $7 < 11$: $2\cdot4 = 8$. İndis 8'de 7: bulundu.

**Dizide 25'i arama:** Hoca dizide 25'i aradı ama ilk adımda 25'i 23'ten küçük alıp indis 2'ye, oradan 5'e ve 11'e gitti; 11. göz boş (0) olduğu için "yoktur" dedi.

> **Ders sonrası not:** $25 > 23$ olduğu için ilk adımda sağa gidilmelidir. Doğru yol: indis 1 (23) → $2\cdot1+1 = 3$ (47); $25<47$ → $2\cdot3 = 6$ (43); $25 < 43$ → $2\cdot6 = 12$ (29); $25<29$ → $2\cdot12 = 24$, dizinin dışında (boş). Sonuç yine "25 yoktur"; bu yol hocanın ağaç üzerinde yaptığı aramayla da aynıdır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): Kare biçimli, ortasında dört köşeye bağlı bir düğüm olan grafın ve altıgen biçimli, ortasında altı köşeye bağlı bir düğüm olan grafın renk (kromatik) sayısı kaçtır? $\chi(G)=3$ mü, 4 mü?

> **Çözüm (derste verildi):** İki grafta da dış düğümler iki renkle dönüşümlü boyanır, merkez düğüm üçüncü rengi alır. Her ikisinde $\chi(G) = 3$. Dört renkle boyamak mümkündür ama en az renk sayısı sorulduğu için cevap 3'tür.

**Soru 2** (ekrandan, 00:40:00): Bütün düğümleri birbirine bağlı dört düğümlü $K$ grafının kromatik polinomunu bulunuz; en az kaç renkle ve kaç farklı şekilde boyanır?

> **Çözüm (derste verildi):** $K_4 = x(x-1)(x-2)(x-3) = (x^2-x)(x^2-5x+6) = x^4-6x^3+11x^2-6x$. $x=1,2,3$ için değer 0, $x=4$ için 24. 4 farklı renk ile 24 farklı şekilde boyanır.

**Soru 3** (ekrandan, 00:45:00 ve 00:50:00): Aynı $K_4$ grafının polinomunu, 1-4 kenarından başlayarak silme-birleştirme yöntemiyle bulunuz.

> **Çözüm (derste verildi):** $K_4 = (\text{köşegenli kare}) - K_3$; köşegenli kare $= C_4 - U_3$; $C_4 = U_4 - K_3 = x(x-1)^3 - x(x-1)(x-2) = x(x-1)(x^2-3x+3)$. Geri yerine koyunca köşegenli kare $x(x-1)(x-2)^2$ ve $K_4 = x(x-1)(x-2)(x-3)$ bulunur (bölüm 4.1).

**Soru 4** (ekrandan, 01:00:00): Köşegenli karenin polinomunu, ortak kenarı olan iki üçgene ayırarak bulunuz. Kaç renkle, kaç farklı şekilde boyanır?

> **Çözüm (derste verildi):** $\dfrac{x^2(x-1)^2(x-2)^2}{x(x-1)} = (x^2-x)(x^2-4x+4) = x^4-5x^3+8x^2-4x$. 3 renk ile, $3\cdot2\cdot1 = 6$ değişik şekilde boyanır.

**Soru 5** (ekrandan, 01:20:00): Üçgen ve ortasında üç köşeye bağlı bir düğümden oluşan grafın kromatik polinomunu bulunuz; en az kaç renkle boyanır?

> **Çözüm (derste verildi):** Bir dış kenar silinir; kalan graf iki üçgenin ortak kenarda birleşmesidir: $x(x-1)(x-2)^2$. Bundan birleştirilmiş üçgen çıkarılır: $x(x-1)(x-2)^2 - x(x-1)(x-2) = x(x-1)(x-2)(x-3) = x^4-6x^3+11x^2-6x$. En az 4 renkle, $4\cdot3\cdot2\cdot1 = 24$ farklı şekilde boyanır.

**Soru 6** (ekrandan, 01:25:00): Kenarları 1-2, 2-4, 4-3, 3-1 olan ve 5. düğümü dört köşeye de bağlı olan grafın kromatik polinomunu bulunuz. Polinomun doğruluğunu kurallarla kontrol ediniz.

> **Çözüm (derste verildi):** $A$ = köşegenli kare olmak üzere 3. satır $A(x-1)$, 2. satır $A(x-2)$, 1. satır $A(x-2) - K_4 = x^5-8x^4+24x^3-31x^2+14x$. Kontrol: 5 düğüm, 8 kenar, işaretler dönüşümlü, sabit terim yok, katsayılar toplamı $39-39 = 0$.

> **Çözüm (derste verilmedi):** En az renk sayısı: $P(0)=P(1)=P(2)=0$, $P(3)=6$. Graf 3 renkle 6 farklı şekilde boyanır (python ile kontrol edildi).

**Soru 7** (derste sözlü, 01:45:12): $a/b + (c-d)/a$ ifadesinin ikili ağacını çiziniz. Ayrıca $a - b/c*d$ için ağaç nasıl olur?

> **Çözüm (derste verildi):** Birincide kök $+$; sol alt ağaç $/$ ($a$, $b$), sağ alt ağaç $/$ (sol çocuğu $-$ ($c$, $d$), sağ çocuğu $a$). İkincide kök $-$; sol çocuk $a$, sağ çocuk $*$; $*$'ın sol çocuğu $/$ ($b$, $c$), sağ çocuğu $d$. <!-- BELİRSİZ: birinci ifadenin ekrandaki yazılışı görülmedi. -->

**Soru 8** (derste sözlü, 01:50:25): 0, 1, 2 ve 3 düğümle kaç farklı ikili ağaç çizilebilir?

> **Çözüm (derste verildi):** 0 düğümle boş ağaç, 1 düğümle 1, 2 düğümle 2, 3 düğümle 5 ikili ağaç.

**Soru 9** (ekrandan, 02:00:00): "Computers are an important technological tool" cümlesini ikili arama ağacına yerleştiriniz. "AI" kelimesi cümlede var mı?

> **Çözüm (derste verildi):** Kök COMPUTERS; sol çocuğu ARE, ARE'nin sol çocuğu AN; sağ çocuğu IMPORTANT, onun sağ çocuğu TECHNOLOGICAL, onun sağ çocuğu TOOL. "AI": C'den küçük (sol), ARE'den küçük (sol), AN'den küçük (sol), boş dal; cümlede yoktur, eklenecekse AN'nin soluna eklenir.

**Soru 10** (ekrandan, 02:45:00): $23, 13, 19, 47, 11, 43, 7, 29, 52$ dizisini ikili arama ağacına yerleştirip ağacı diziye geçiriniz; dizide 7 ve 25'i arayınız.

> **Çözüm (derste verildi):** Dizi gösterimi: 1:23, 2:13, 3:47, 4:11, 5:19, 6:43, 7:52, 8:7, 12:29, diğer gözler 0. 7 için yol $1 \to 2 \to 4 \to 8$, bulundu. 25 için doğru yol $1 \to 3 \to 6 \to 12 \to 24$; 24. göz yoktur, 25 dizide yoktur (bölüm 15'teki ders sonrası nota bakınız).

## Dersin Toparlaması

Dersin ilk yarısında graf boyama ele alındı. Bir grafın kromatik sayısı, komşu düğümleri farklı renkte olacak şekilde gereken en az renk sayısıdır. Kromatik polinom, $x$ renkle kaç farklı boyama yapılabileceğini verir; polinomu sıfırdan farklı yapan ilk $x$ en az renk sayısını, o değerdeki polinom değeri de boyama sayısını gösterir. Noktasal graf ($x$), çizgisel graf ($x(x-1)^{n-1}$) ve tam graf ($\prod (x-k)$) bilinen graflardır. Bilinmeyen graflar silme-birleştirme yöntemiyle ve ortak parçadan bölme kuralıyla bunlara indirgenir. Bulunan polinom altı kuralla kontrol edilir: baş katsayı 1, derece = düğüm sayısı, ikinci katsayı = kenar sayısı, katsayılar toplamı 0, işaretler dönüşümlü, sabit terim yok.

İkinci yarıda ağaçlara geçildi: döngüsüz bağlantılı graflar, köklü ağaç, seviye, yükseklik ve ağaç terminolojisi; $n$ düğümlü ağacın $n-1$ kenarı olduğunu söyleyen teorem; ikili ağaçlar, ifade ağaçları, tam ikili ağaçların özellikleri, dengeli ağaçlar ve ikili arama ağaçları. Son olarak bir ağacın dizi üzerinde (sol çocuk $2i$, sağ çocuk $2i+1$) gösterilmesi ve dizide arama yapılması görüldü. Hoca bir sonraki derste ağaçların nasıl dolaşılacağı (okunacağı) konusuyla devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
