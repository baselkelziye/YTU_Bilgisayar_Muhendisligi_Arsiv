# Ders 12 Genişletilmiş Notu: Rastgele Sayı Üreteçleri: Çember Desenleri, Seed, Kart Karıştırma, Gauss Dağılımı, Rastgele Yürüyüş ve Monte Carlo ile Pi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Matematik ve Sanat: Çember Üzerinde Desenler
- 2. Desen Algoritması
- 3. Tekrar, Döngü ve Bütün Noktaları Gezmek
- 4. Uniform Sayı Üreteci
- 5. Rastgele Sayı Üreteçleri ve Sözde Rastgelelik
- 6. Seed (Tohum) Değeri
- 7. Zar Üretmek ve Hile Kontrolü
- 8. Bir Aralıkta Rastgele Tam Sayı Üretmek
- 9. 52 Kartı Karıştırmak
- 10. Gauss (Normal) Dağılım
- 11. Rastgele Yürüyen Robot
- 12. Monte Carlo ile Pi
- 13. Ders Sonunda Sorulan Sorular
- Örnek Sorular
- Dersin Toparlaması

## 1. Matematik ve Sanat: Çember Üzerinde Desenler

Ders, ekranda paylaşılan bir belgedeki çizgi desenleriyle başladı. Her desenin tepesinde iki sayı yazıyordu (örneğin 337 ve 10, 53 ve 51). Hoca bütün desenlerin aynı kodla çizildiğini, yalnız bu iki sayının değiştiğini söyledi; iki sayı kodun parametreleri gibi düşünülebilir (ekrandan, 00:10:00). Her sayı ikilisi güzel desen üretmez; ekrana yalnız güzel bulunanların bir kısmı konmuştu.

Daha az kalabalık olan 53-51 deseni büyütülerek incelendi. Çizim çember üzerindeki bir noktadan başlar, çember üzerindeki başka bir noktaya gider, oradan yine çember üzerindeki başka bir noktaya gider ve böyle sürer. Desen el kaldırılmadan çizilebilir. İçeride hiç nokta yoktur; bütün çizgiler çember üzerindeki noktaları birleştirir.

**Soru:** Çember üzerindeki bu noktalar birbirlerine göre nasıl? **Cevap:** Eşit uzaklıktadırlar. Sanki bütün çember belli sayıda noktaya bölünmüş ve bu noktalar bir kurala göre birleştirilmiştir. 53-51 deseninde boşta kalan nokta da yok gibi görünür; bütün noktalara gidilip gidilmemesi verilen iki sayıya bağlıdır.

## 2. Desen Algoritması

Hoca algoritmayı beyaz tahtada "kestirme" bir akış diyagramıyla çizdi (ekrandan, 00:20:00). İki değer algoritmanın kendisi tarafından bulunmaz, kullanıcıdan alınır.

### 2.1 Girdiler ve nokta matrisi

- $m$: çember üzerindeki nokta sayısı. Noktalar eşit uzaklıktadır.
- $s$: yeni indisi üretmekte kullanılan çarpan.

Önce `P = noktaUret(m)` biçiminde bir fonksiyon çağrılır. Fonksiyona nokta sayısı gönderilir, çıkış olarak $P$ matrisi döner. $P$, $2 \times m$ boyutlu bir matristir: her sütun bir noktadır, sütunun iki elemanı o noktanın $x_1$ ve $x_2$ koordinatlarıdır (iki boyutlu bir uzay). Tahtadaki örnekte bir sütunda $3{,}6$ ve $4{,}2$ gibi değerler vardı (ekrandan, 00:20:00).

**Soru:** Matriste ikinci noktanın koordinatları ikinci satırda mı, ikinci sütunda mı? **Cevap:** Sütunda. Her sütun bir noktadır; o sütunun iki satırı noktanın $x_1$ ve $x_2$ değerleridir. (Öğrenci "x ve y" dedi; hoca $x_1$ ve $x_2$ dediğini belirtti.)

Hoca bunu bir kez daha, $m = 8$ noktalı bir çember çizerek renkli noktalarla anlattı (ekrandan, 00:30:00): birinci nokta $(2, 1)$, ikinci $(3{,}5,\ 0{,}5)$, üçüncü $(4,\ 1{,}5)$, dördüncü $(4{,}1,\ 2{,}5)$ gibi. Bunlar uydurulmuş örnek koordinatlardır; önemli olan $P$'nin $i$. sütununun $i$. noktanın koordinatlarını tutmasıdır.

### 2.2 Döngü

Akış diyagramı şöyledir (ekrandan, 00:20:00):

```text
start
oku m, s
P = noktaUret(m)
i = 1
j = 1'den m'ye kadar, birer birer:
    yi = i * s mod m
    birlestir(P, yi, i)
    i = yi
stop
```

`birlestir` bir çizim fonksiyonudur, dışarıya bir değer döndürmez. $P$ matrisinin $y_i$. sütunuyla $i$. sütunundaki noktalar arasına bir çizgi çeker. Ardından $i = y_i$ yapılır: varılan nokta yeni başlangıç noktası olur, ondan yeni bir $y_i$ hesaplanır, yeni bir çizgi çekilir. Bu, $m$ kez tekrarlanır.

### 2.3 mod m ve indisler

**Soru:** Bir şeyin $\bmod\ m$'i hangi değerleri alabilir? **Cevap:** $0$ ile $m-1$ arasında; $m$ olamaz. Bu yüzden hoca indislerin $0$'dan $m-1$'e kadar gittiğini varsaydı ve tahtadaki matrisin sütunlarını buna göre numaralandırdı. İndislerin nereden başlayacağı uygulamaya göre değişebilir.

> **Hocanın vurgusu:** Buradaki $i$ ve $y_i$ yalnız birer sayıdır, $P$ matrisinin sütun indisleridir. Koordinatlar üzerinde hiçbir işlem yapılmaz.

**Soru:** $s$ ile çarparken bir sütunun $x_1$'ini ve $x_2$'sini de mi $s$ ile çarpıyoruz? **Cevap:** Hayır. $s$ yalnız yeni indisi üretmek için kullanılır: $y_i = (s \cdot i) \bmod m$. $P$ başta bir kez oluşturulur ve sonra değişmez; her sütunun koordinatları bellidir.

## 3. Tekrar, Döngü ve Bütün Noktaları Gezmek

### 3.1 Bir değer tekrar ederse

Hoca ekrana yazdırılan indisleri düşünmeyi önerdi. $m = 53$, $s = 5$ için "diyelim ki" diyerek şu varsayımsal diziyi yazdı: $1, 42, 4, 5, 6, 33, 4$ (ekrandan, 00:30:00).

**Soru:** Bundan sonra ne gelir? **Cevap:** $5, 6, 33, 4, 5, 6, \ldots$ Çünkü her değer yalnız bir önceki değere bağlıdır. Bir önceki değer bilinirse bir sonraki de bilinir. Bu yüzden daha önce geçilmiş bir yerden yeniden geçildiği anda devamı kesin olarak bellidir ve aynı döngü sonsuza kadar tekrar eder.

> **Ders sonrası not:** Tahtadaki bu dizi gerçek bir hesap değil, döngüyü göstermek için seçilmiş bir örnektir. Gerçekte $m = 53$, $s = 5$, $i = 1$ için ilk değer $5$'tir.

### 3.2 Bütün noktaları gezmek

Bazı $m$, $s$ çiftleri çemberin bütün noktalarını $m$ adımda gezer. Bu durumda süreç aslında $m$ uzunluğunda bir dizi üretir; dizide $1$'den $m$'ye kadar sayılar karışık sırada ve tekrarsız bulunur. Hoca örnek olarak $m = 337$, $s = 20$ için dizinin "1, belki 302, 4, 6, ..., en sonda belki 48" diye gittiğini, 337 elemanın hiçbirinin tekrar etmediğini söyledi (sayılar yine varsayımsaldır).

Herhangi bir yerde tekrar olursa süreç o döngüde takılır. Döngünün uzunluğu örneğin 5 ise aynı 5 sayı sürekli tekrar eder, çemberin bütün noktalarına gidilemez ve güzel desen oluşmaz. Güzel desenler işin yan ürünüdür; asıl ilgilenilen şey bu sürecin bir **sayı üreteci** olarak kullanılabilmesidir. Bu sayılar koordinat değil, indislerdir. Örneğin $m = 10.000$ için iyi bir $s$, $1$'den $10.000$'e kadar sayıların karıştırılmış ve tekrarsız bir dizisini verir.

> **Ders sonrası not:** $y_i = (i \cdot s) \bmod m$ kuralı $i = 1$'den başlatılırsa ve $s$ ile $m$ aralarında asalsa $0$ değeri hiç çıkmaz; en fazla $m-1$ farklı nokta gezilir. Ekrandaki 53-51, 337-10 ve 337-20 çiftleri için döngü uzunlukları sırasıyla 52, 336 ve 336'dır (python ile hesaplandı). Yani bu çiftler $0$ dışındaki bütün noktaları gezer.

### 3.3 Gezilen noktaları saymak

**Soru:** Üretecin çemberin kaç noktasından geçtiğini nasıl sayarız? (Ne kadar çok noktadan geçerse o kadar iyi bir üreteç sayılsın.)

Bir öğrenci $P$ matrisine üçüncü bir satır ekleyip her gelişte onu artırmayı önerdi. Hoca bunun da olabileceğini, ama ayrı bir $T$ dizisi (uzunluğu $m$) açmanın da mümkün olduğunu söyledi. $T$ başta bir `for` döngüsüyle sıfırlanır, döngünün içinde $T[i] = T[i] + 1$ yapılır. Sonunda:

- $T[i] = 0$: o noktaya hiç gelinmemiştir.
- $T[i] = 1$: bir kez geçilmiştir; $T[i] = 2$: iki kez geçilmiştir.

Özel $m$, $s$ değerleri $T$'nin bütün elemanlarını 1 yapar, hiç 0 bırakmaz ve bunu $m$ adımda yapar. Daha az adımda bütün noktalar gezilemez. Daha çok adımda mutlaka fazlalık oluşur: $m$ farklı değerden $m+1$ kez geçilirse en az bir değerden iki kez geçilmiş olur.

## 4. Uniform Sayı Üreteci

$T$ dizisinin bütün elemanları 1 ise bu sayı üreteci **uniform** (tekdüze) bir üreteçtir: her değerin gelme olasılığı eşittir. Hoca bunu her değerin gelme olasılığını gösteren eşit yükseklikli çubuklarla çizdi; her birinin olasılığı $1/m$'dir.

Karşı örnek olarak $1$ ile $5$ arasında sayı üreten bir üreteç çizildi; 5'in çubuğu ötekilerden çok daha yüksekti (ekrandan, 00:40:00).

**Soru:** Bu üretecin üreteceği sayıyı tahmin etmeniz istense ne dersiniz? **Cevap:** 5 denir, çünkü büyük olasılıkla 5 üretecektir; tutturma şansı yüzde elli gibi yüksek bir değer olabilir. Oysa olasılıklar eşit olsaydı beş sayıdan birini tutturmak çok daha zor olurdu.

Asıl istenen, dışarıdan bakan birinin üretilecek sayıyı tahmin edememesidir. Süreç aslında bellidir: $i$, $m$ ve $s$ bilinirse bir sonraki sayı bilinir. Ama önceki değer söylenmezse ve üreteç uniformsa tahmin etmek çok zordur.

**Soru:** $1$ ile $100.000$ arasında her değerin olasılığı eşit olsa tutturma şansınız nedir? **Cevap:** $1/M$, yani $1/100.000$. Beş sayı arasından tutturmak görece kolaydır, $100.000$ sayı arasından tutturmak çok zordur.

## 5. Rastgele Sayı Üreteçleri ve Sözde Rastgelelik

### 5.1 Gerçek rastgelelik yoktur

Bu süreç bilgisayarlarda **rastgele sayı üreteci** olarak kullanılır (ekrandan, 00:45:00). Hoca "böyle bir sürece rastgele sayı üreteci diyorum" deyip sınıftan itiraz bekledi.

**Soru (hocadan):** Burada rastgele olan ne? Her nokta bir önceki noktaya bağlı değil mi? **Cevap (sınıftan):** Evet; aslında rastgele değil.

> **Hocanın vurgusu:** "Önemli bir cümle": Bilgisayarlarda gerçek rastgelelik (true randomness) yoktur (ekrandan, 00:45:00).

Bir öğrenci programlama dillerinde `random` fonksiyonları olduğunu sordu; hoca onların hepsinin bu mekanizmaya dayandığını söyledi. Başka bir öğrenci de "sonuçta kod hep aynı" diyerek nedenini açıkladı: üretilecek her değer kesin olarak bir öncekine bağlıdır.

Bilgisayarlar **deterministik** sistemlerdir: mekanizma ve mevcut durum bir sonraki durumu belirler; beklenmedik bir şey olmaz. Eski analog yapılarda gürültü gibi etkiler olabilirdi, ama günümüz bilgisayarları için bu geçerli değildir. Bu yüzden kütüphanelerde ve dillerde "random" denen her şey **sözde rastgele** (pseudo random) sayı üretecidir.

### 5.2 Gerçekte kullanılan bir üreteç

Hoca gerçekte kullanılan bir üreteç örneği verdi:

$$R_n = (A \cdot R_{n-1} + C) \bmod M$$

Önceki formülden tek farkı $+C$ teriminin eklenmesidir. $R_n$, $R_{n-1}$'e tamamen bağlıdır; $A$, $C$, $M$ zaten bilindiği için $R_{n-1}$ bilinirse bir sonraki değer bilinir. Bu üreteç için verilen değerler:

- $R_0 = 0$ (başka bir yerden de başlayabilir, çok önemli değil)
- $A = 1366$
- $C = 150889$
- $M = 714025$

<!-- BELİRSİZ: Formülün ve değerlerin yazıldığı anın (yaklaşık 00:45:30-00:47:30) karesi yok; formülün sol kısmı altyazıda eksik, değerler altyazıdan alındı. -->

**Soru:** $A$, $C$ ve $M$ nasıl seçilmeli? **Cevap:** Özenle. Üreteç $0$'dan $M-1$'e kadar bütün değerleri üretmeli ve bunları eşit olasılıkla üretmelidir. $M$ adımda hepsini üretiyorsa zaten eşit olasılıkla üretiyordur. Yukarıdaki üreteç bu yüzden iyi bir üreteçtir: çemberi 714.025 parçaya bölüp bütün noktaları tek tek gezer gibidir. Rastgele sayı üreteçlerinin mekanizmaları birbirine çok benzer; onları farklı yapan $A$, $C$, $M$ gibi değerlerdir.

> **Ders sonrası not:** Bu değerlerle $R_0 = 0$'dan başlayan dizinin 714.025 adımda bütün değerleri tam bir kez ürettiği python ile denendi.

> **Ek bilgi (derste anlatılmadı):** Bu biçimdeki üreteçlere doğrusal eşlik üreteci (linear congruential generator, LCG) denir. $C \neq 0$ iken tam çevrim için bilinen koşullar şunlardır: $C$ ile $M$ aralarında asal olmalı, $A-1$ $M$'nin bütün asal çarpanlarına bölünmeli, $M$ 4'e bölünüyorsa $A-1$ de 4'e bölünmeli. Burada $M = 5^2 \cdot 13^4$ ve $A - 1 = 1365 = 3 \cdot 5 \cdot 7 \cdot 13$ olduğu için koşullar sağlanır.

## 6. Seed (Tohum) Değeri

### 6.1 Sorun: başlangıç bilinirse her şey bilinir

Bilgisayar bir sayı üretip örneğin 45 verdiyse ve mekanizma biliniyorsa sonraki sayı da bilinir. $A$, $C$, $M$ ve başlangıç noktası bilinirse bütün süreç bilinir.

Hoca üreteci bir çevrim olarak çizdi: $R_0 \to R_1 \to R_2 \to \cdots \to R_6 \to R_0$ (ekrandan, 01:05:00). Yedi farklı sayı üretilir; sekizinci istenirse başa döner ve aynı sıra sürer.

**Soru:** Kodda $i = 1$ yerine $i = 2$'den başlasaydık ne değişirdi? **Cevap (bir öğrenci):** Neredeyse hiçbir şey; yalnız sıralama değişir. Hoca bunu tahtada gösterdi (ekrandan, 01:05:00):

- 1'den başlanırsa: $1, 2, 3, 4, 5, 6, 7$
- 2'den başlanırsa: $2, 3, 4, 5, 6, 7, 1$
- 5'ten başlanırsa: $5, 6, 7, 1, 2, 3, 4$

Başlangıç değeri değişince süreç değişmez, ama görülen sayılar değişir. Bilgisayarlarda bu başlangıç değerine **seed** denir.

### 6.2 Neden her seferinde değişmeli?

`random` fonksiyonunun $A$, $C$, $M$ değerleri kullanıcıdan alınmaz; içeride sabit (hard-coded) olarak durur. Seed hep aynı olursa her çalıştırmada aynı dizi gelir. Bu, kullanıcıya sürecin rastgele olmadığına dair ipucu verir. Hoca tavla örneğini verdi: program her açıldığında önce 3-1, sonra 4-2, sonra 5-1 atarsa kullanıcı bunu fark eder. Amaç, rastgelelik illüzyonunu korumaktır.

**Soru (bir öğrenci):** Yazdığım program her çalıştığında aynı diziyi veriyordu. **Cevap:** Programda seed büyük olasılıkla hep aynı değere ayarlanmıştı; aynı seed'den başlayan üreteç hep aynı sırayı üretir.

Seed'i 3 ya da 5 gibi sabit bir değer yapmak çözüm değildir; program her çalıştırıldığında farklı bir seed oluşmalıdır. Çevrimin büyük olması da önemlidir: yaklaşık 700.000'lik bir çevrimi kullanıcının fark etmesi pek mümkün değildir; her seferinde başka bir yerden başlanırsa fark etmek daha da zorlaşır.

### 6.3 C'de seed: srand(time(NULL))

Hoca C'deki klasik yolu tahtaya yazdı (ekrandan, 01:05:00):

```c
#include <stdlib.h>
#include <time.h>
...
srand(time(NULL));
...
```

`srand`, rastgele sayı fonksiyonunun seed'ine değer atar. Parantez içine 3 yazılırsa 3, 5 yazılırsa 5 atanır. `time(NULL)` ise 1.1.1970'ten programın çalıştığı ana kadar geçen saniye sayısını döndürür (ekrandan, 01:05:00); hoca örnek olarak "sallıyorum" diyerek $19.248.765$ gibi bir değer yazdı. Program bir daha çalıştırıldığında bu değer biraz daha büyük ama farklı olur. Aynı saniye içinde iki kez çalıştırılırsa aynı seed alınır.

Seed için sistem saati iyi bir kaynaktır. "Bilgisayar en son ne zaman kapatıldı" gibi bir değer iyi değildir, çünkü bilgisayarlar artık sık kapatılmaz. Saniye yetmezse salise gibi daha yüksek çözünürlüklü zaman kullanılabilir.

**Soru:** Seed'i değiştirmek çemberdeki değerlerin olasılıklarını değiştirir mi? **Cevap:** Hayır. 1'den, 2'den ya da 5'ten başlamak yalnız başlangıç noktasını değiştirir; olasılıklar aynı kalır.

**Soru:** Oyunlardaki sandık açma gibi şeylerde de bu mu kullanılıyor? **Cevap:** Evet; rastgele görünen her süreçte rastgele sayı üreteci kullanılır ve hiçbiri gerçekten rastgele değildir.

> **Hocanın vurgusu:** Rastgeleliğe yeterince yaklaşmanın iki mekanizması vardır: $M$'nin büyük olması ve her yeri gezen $A$, $C$ sabitleri; ve her çalıştırmada farklı bir seed. Seed bilerek sabit bir değere de verilebilir; o zaman her çalıştırmada aynı sayılar üretilir ve bu bazen gerçekten istenir.

## 7. Zar Üretmek ve Hile Kontrolü

Aradan sonra rastgele sayıların nerelerde kullanılacağı konuşuldu: simülasyonlar, oyunlar ve algoritma testleri. Örneğin 100 ya da 1000 elemanlı bir diziyi sıralayan bir algoritmanın performansını ölçmek için sayıları kullanıcıdan almak ya da elle yazmak çok maliyetlidir; rastgele sayı üreteci kullanılabilir.

Zar için tahtaya şu yazıldı (ekrandan, 01:25:00):

$$zar = 1 + ((a \cdot zar + c) \bmod 6)$$

**Soru:** $\bmod$'dan sonra ne yazılmalı? Bir öğrenci 7 dedi. **Cevap:** Sonda $+1$ olduğu için 6. $\bmod 6$ işlemi $0 \ldots 5$ verir, $+1$ ile zar $1 \ldots 6$ olur.

**Soru:** Bu zar üretecinin hileli olup olmadığını nasıl anlarız? **Cevap:** Hilesiz zarda 1'den 6'ya kadar bütün değerlerin olasılığı eşittir. Bazı $a$, $c$ değerleri için eşit olur, bazıları için olmaz. Bir öğrenci "$a$ ve $c$ çiftse hep tek sayılar gelir" gibi bir fikir söyledi; hoca $a$ ve $c$ verildiğinde bunun hesapla (deneyerek) anlaşılacağını vurguladı. Öğrencilerin "çok fazla zar atarım" önerisinden yola çıkılarak yöntem kuruldu:

- Altı elemanlı bir $T$ dizisi tutulur ve her atışta $T[zar] = T[zar] + 1$ yapılır (ekrandan, 01:25:00).
- Değerlerin tamamen eşit çıkması çok düşük bir olasılıktır. Örneğin 600.000 atışta her değerin tam 100.000 kez gelmesi beklenmez.
- Bir ortalama ve onun üstünde ve altında bir tolerans aralığı belirlenir (tahtada $100.000$ ve $\pm 1000$). Bütün değerler bu aralıktaysa bu $a$, $c$ için zar hilesizdir; aralığın dışında değer varsa hilelidir.

## 8. Bir Aralıkta Rastgele Tam Sayı Üretmek

Sınıfa şu soruldu: Hilesiz olduğu bilinen ve $[0, 1]$ aralığında (0 ve 1 dahil, aradaki $0{,}02$, $0{,}75$ gibi değerler de) sayı üreten bir `rand` fonksiyonu var. $[45, 54]$ kapalı aralığındaki 10 tam sayıyı hilesiz üretmek için ne yapılır?

Bir öğrenci $[0, 1]$ aralığını eşit parçalara bölüp çıkan değeri parça genişliğine bölmeyi ve sonucu 45'e eklemeyi önerdi. Hoca bunu genel biçimde yazdı: alt sınır $x$, üst sınır $y$ ise

$$t = rand, \qquad sonuc = x + \lfloor t \cdot (y - x + 1) \rfloor$$

Aşağıya yuvarlanır. $x = 45$, $y = 54$ için $y - x = 9$, $y - x + 1 = 10$; $t$ ile 10 çarpılıp aşağıya yuvarlanır ve 45'e eklenir. Hoca bunun öğrencinin önerisine karşılık geldiğini söyledi. <!-- BELİRSİZ: Bu formülün yazıldığı anın (yaklaşık 01:28-01:29) karesi yok; formül altyazıdan kuruldu. -->

> **Ders sonrası not:** Derste `rand`'ın 1'i de üretebildiği söylendi. $t = 1$ çıkarsa formül $45 + 10 = 55$ verir ve aralığın dışına çıkar. Formül $t \in [0, 1)$ için doğru çalışır; C'de `(double)rand() / RAND_MAX` 1'i de verebileceği için bu ayrıntıya dikkat etmek gerekir.

## 9. 52 Kartı Karıştırmak

Kart oyunlarında oyun her başladığında 52 kartın sırası değişmelidir. Yani her seferinde $1$'den $52$'ye kadar sayıların bir permütasyonu üretilmelidir; örneğin $3, 6, 50, 42, \ldots, 2$ (ekrandan, 01:35:00).

### 9.1 Birinci yol: tekrar edeni reddet

$1$ ile $52$ arasında art arda rastgele sayı üretilirse örneğin $3, 6, 12, 50, 2, 3$ gelebilir: 3 tekrar etmiştir (ekrandan, 01:35:00). Tekrarı engellemek için bir $B$ dizisi tutulur: 3 çıkınca $B[3] = 1$, 6 çıkınca $B[6] = 1$ yapılır. Üretilen sayı dışarı verilmeden önce $B$'ye bakılır; daha önce çıkmışsa yeniden üretilir, çıkmamışsa dışarı verilir ve işaretlenir.

İlk çizim bir `for` döngüsüydü (ekrandan, 01:35:00): $i = 1 \ldots 52$; $T = rand()$; $B[T] == 1$ mi?

**Soru:** Bu algoritmada sorun var mı? Bir öğrenci "yok gibi" dedi. **Cevap:** Var. Tekrar eden sayılar atlandığı için 52 sayı yazdırılmaz; tekrarsız ama eksik bir dizi çıkar. 52 sayı üretilene kadar dönmek gerekir, bu yüzden `for` yerine `while` kullanılmalıdır.

Düzeltilmiş akış diyagramı (ekrandan, 01:40:00):

```text
i = 0
i < 52 olduğu sürece:
    T = rand()                 (1-52 arası)
    B[T] == 1 ise:  hiçbir şey yapma (daha önce üretilmiş)
    değilse:
        A[i] = T
        B[T] = 1
        i = i + 1
```

Sonunda $A$ dizisi dışarı verilir. Bu, 52 farklı sayı üretmeyi garanti eder.

**Bu yolun zayıf yanı:** Başlarda yeni sayı hemen bulunur. Ama $B$ doldukça denemelerin çoğu daha önce çıkmış sayılara denk gelir. En sonda, örneğin yalnız 49 çıkmamışsa, onu tutturmak için kabaca ortalama 52 kez üretmek gerekir. $B$ ne kadar doluysa yeni bir sayı için `rand` o kadar çok çağrılır.

### 9.2 İkinci yol: rastgele yer değiştirme

$A$ dizisine önce $1, 2, \ldots, 51, 52$ yazılır. Sonra şu adım tekrarlanır (ekrandan, 01:45:00):

```text
T1 = rand()
T2 = rand()
Temp  = A[T1]
A[T1] = A[T2]
A[T2] = Temp
```

**Soru:** Burada ne yapılıyor? **Cevap (bir öğrenci):** Rastgele seçilen iki elemanın yeri değiştiriliyor. **Soru:** Bu işlem 52 kez değil de örneğin 30 kez tekrarlansa karışık bir dizi elde edilir mi? **Cevap (bir öğrenci):** Edilir.

Bu çözüm birinci yoldan kesinlikle daha iyidir: birinci yolda sonlara doğru çok sayıda deneme boşa gider, burada ise her işlem dizide bir değişiklik yapar. 52 yerine çok daha büyük sayılarda ikinci yolun üstünlüğü daha da artar.

> **Ders sonrası not:** 30 rastgele yer değiştirmede bir kartın hiç dokunulmadan kalma olasılığı $(51/52)^{60} \approx 0{,}31$'dir; 52 kartın ortalama yaklaşık 16'sı yerinde kalır (python ile hesaplandı ve benzetimle denendi). Yani 30 değiştirme büyük olasılıkla iyi bir karışım için yetmez; daha fazla tekrar ya da aşağıdaki yöntem gerekir.

> **Ek bilgi (derste anlatılmadı):** Standart yöntem Fisher-Yates karıştırmasıdır: $i = N$'den $2$'ye doğru, $1 \ldots i$ arasından rastgele bir $j$ seçilip $A[i]$ ile $A[j]$ yer değiştirilir. Tam $N-1$ yer değiştirmeyle bütün permütasyonları eşit olasılıkla üretir.

Aşağıdaki program iki yolu da gösterir. Derste C kodu yazılmadı; program tahtadaki akış diyagramlarına göre ajan tarafından yazıldı, `gcc -Wall` ile uyarısız derlendi ve çalıştırıldı (her çalıştırmada farklı bir permütasyon üretti).

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 52

int main() {
    int A[N + 1], B[N + 1];
    int i, t, t1, t2, temp, deneme = 0;
    srand(time(NULL));

    /* 1. yol: tekrar eden sayiyi B dizisiyle reddet */
    for (i = 1; i <= N; i++) {
        B[i] = 0;
    }
    i = 0;
    while (i < N) {
        t = 1 + rand() % N;          /* 1-52 arasi */
        deneme = deneme + 1;
        if (B[t] != 1) {
            A[i + 1] = t;
            B[t] = 1;
            i = i + 1;
        }
    }
    printf("1. yol (%d rand cagrisi):\n", deneme);
    for (i = 1; i <= N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    /* 2. yol: 1..52'yi yaz, rastgele iki elemanin yerini degistir */
    for (i = 1; i <= N; i++) {
        A[i] = i;
    }
    for (i = 1; i <= 30; i++) {
        t1 = 1 + rand() % N;
        t2 = 1 + rand() % N;
        temp = A[t1];
        A[t1] = A[t2];
        A[t2] = temp;
    }
    printf("2. yol (30 degistirme):\n");
    for (i = 1; i <= N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
```

## 10. Gauss (Normal) Dağılım

Hoca $0$ ile $1$ arasında düz bir çizgiyle uniform dağılımı çizdi, yanına da bir çan biçimli eğri çizdi (ekrandan, 01:45:00).

**Soru:** Bu dağılımın adı ne? Çan eğrisi diye bir şey duydunuz mu? **Cevap:** Çan eğrisi; asıl adı Gauss dağılımı (Gaussian) ya da normal dağılımdır (ekrandan, 01:50:00). İkisi aynı şeydir.

Bazı durumlarda üretilen sayıların gerçekten uniform olması istenir (zar, kart dağıtma). Bazı durumlarda ise sayıların normal dağılımdan gelmesi istenir: ortalamaya yakın değerlerin olasılığı yüksek, ortalamadan uzaklaştıkça düşük olmalıdır. Hoca eğriyi sürekli çizdi; ayrık düşünülürse $0{,}1$, $0{,}2$, $0{,}3$ gibi aralıklara karşılık gelen çubuklar olarak görülebilir.

**Soru:** Bir sınıftaki öğrencilerin bir sınavdan aldıkları notlar uniform mu dağılır, Gauss mu? **Cevap:** Gauss. Her notu alan eşit sayıda kişi olmaz; bir ortalama not vardır. Ortalama sınavın zorluğuna göre değişir: hoca bir sınavın ortalamasını 30, ötekinin 70 alarak iki ayrı çan eğrisi çizdi (ekrandan, 01:50:00). Sınıfın büyük kısmı ortalamanın çevresinde kümelenir; çok yüksek ve çok düşük not alanlar azdır. Bu kesin bir kural değildir, ama notlar uniform dağılımdan çok Gauss dağılımına benzer.

### 10.1 İki uniform sayının toplamı

Problem: Uniform üretmeyi biliyoruz; Gauss dağılımına sahip sayıları nasıl üretiriz? Hoca şunu yazdı (ekrandan, 01:50:00):

```text
A = rand()
B = rand()
C[i] = A + B
```

Önce $(A+B)/2$ yazmıştı, sonra 2'ye bölmeyi kaldırdı: dizideki her şeyi 2'ye bölmek ya da 5 ile çarpmak dağılımın biçimini değiştirmez. Analizi kolaylaştırmak için `rand` $1$ ile $99$ arasında uniform tam sayı üretsin.

$C$'nin hangi değerleri ne kadar olası? (ekrandan, 01:55:00)

- $C = 2$ için yalnız $(1, 1)$.
- $C = 3$ için $(2, 1)$ (sıra önemsenmeden tek bir durum yazıldı; $(1, 2)$ de olabilir).
- $C = 4$ için $(1, 3)$ ve $(2, 2)$.
- $C = 50$ için yaklaşık 50 durum (bir öğrenci "47 tane falan" dedi).
- $C = 100$ için yaklaşık 100 durum.
- $C = 198$ için yine yalnız $(99, 99)$.

Bu sayılar çizdirilirse ortada yüksek, kenarlarda alçak bir eğri oluşur. İki uniform sayının toplamı uniform değildir: ortalama çevresinde çok sayıda olasılık olduğu için o değerler çok gelir, kenarlardaki değerler az gelir. Hoca bunun "süper bir Gaussian" olmayacağını, ama ona oldukça benzeyeceğini söyledi.

> **Ders sonrası not:** Sıralı çiftler sayılırsa $C = 50$ için tam 49, $C = 100$ için tam 99 durum vardır (python ile sayıldı); tahtadaki "yaklaşık 50" ve "yaklaşık 100" değerleriyle uyumludur.

> **Ek bilgi (derste anlatılmadı):** İki uniform sayının toplamı aslında üçgen biçimli bir dağılım verir. Daha çok sayıda uniform sayı toplandıkça dağılım normal dağılıma giderek daha çok benzer; bu, merkezi limit teoreminin bir sonucudur.

## 11. Rastgele Yürüyen Robot

### 11.1 Problem

Boş bir matris (ızgara) üzerinde bir robot vardır. İsteğe bağlı engeller de konabilir, ama engelsiz de problem yoktur. Robot rastgele gezdirilmek isteniyor. Robot dört yöne gidebilir: 1 yukarı, 2 sağ, 3 aşağı, 4 sol (ekrandan, 02:15:00). Böylece $1, 2, 3, 4$ sayıları rastgele üretilir ve robot buna göre hareket ettirilir. Örneğin $1, 1, 2, 2, 3, 4, \ldots$ gelirse iki kez yukarı, iki kez sağa, bir kez aşağı, bir kez sola gider; aynı yerlerden yeniden geçebilir.

Robot $(x, y)$ konumundaysa ($x$ satırı, $y$ sütunu gösterir) komşu hücreler şöyledir (ekrandan, 02:15:00):

- Yön 1 (yukarı): $(x-1, y)$; $x$ bir azalır, $y$ değişmez.
- Yön 2 (sağ): $(x, y+1)$; $y$ bir artar.
- Yön 3 (aşağı): $(x+1, y)$; $x$ bir artar.
- Yön 4 (sol): $(x, y-1)$; $y$ bir azalır.

Bir öğrenci önce yön 1 için "$y$'yi bir artırmak lazım" dedi; hoca $x$ satırı gösterdiği için yukarı çıkmanın $x - 1$ olduğunu açıkladı.

### 11.2 if'li çözüm

Akış diyagramı (ekrandan, 02:15:00):

```text
start
oku N
Rx = 3, Ry = 3
i = 1'den N'ye kadar:
    y = rand()            (1-4 arası)
    y == 1 ise:  Rx = Rx - 1
    değilse y == 2 ise:  Ry = Ry + 1
    değilse y == 3 ise:  Rx = Rx + 1
    değilse:  Ry = Ry - 1
    A[Rx, Ry] = 1
stop
```

Dört dal sonunda birleşir. Gidilen yolu göstermek için her adımdan sonra $A$ matrisinin $(R_x, R_y)$ hücresine 1 yazılır; hangi sırayla gidildiğini görmek için 1 yerine $i$ de yazılabilir (üst üste binmeler olur, ama önemli değil).

Robot 8 yöne (çaprazlar dahil) gidebilseydi `rand` $1 \ldots 8$ üretirdi ve 3 yerine 7 `if` gerekirdi; başka bir değişiklik olmazdı.

### 11.3 if'lerden kurtulmak

**Soru:** Bu `if`'lerden tamamen nasıl kurtulabiliriz? (Sınıfa iki dakika düşünme süresi verildi.)

- Bir öğrenci her yönün kaç kez çıktığını tutan 8 elemanlı bir dizi önerdi. Hoca bunun adım adım hareketi göstermediğini ve `if`'leri kaldırmadığını belirtti.
- Başka bir öğrenci $x$ ve $y$ için iki ayrı `rand` önerdi: $A = rand()$, $B = rand()$, sonra kontrolsüz olarak $R_x = R_x + A$, $R_y = R_y + B$ (ekrandan, 02:25:00). Değerler yalnız $0$ ve $1$ olursa geri gidilemez; $-1$ ve $+1$ olursa koordinatlardan biri hiç sabit kalamaz. Bu yüzden değerler $-1, 0, 1$ olmalıdır. Ama 4 yönlü harekette bu, $(-1, -1)$ gibi çapraz hareketleri de üretir. Öğrencinin "tek bir `if` kullanırım" ve "$A + B$ toplamına bakarım" önerileri `if` gerektirdiği için kabul edilmedi.

Hoca ikinci öneriyi değiştirerek şu çözüme vardı: $2 \times 4$'lük bir $U$ matrisi tanımlanır. $U$'nun $y$. sütunu, $y$ yönünde $x$ ve $y$'nin ne kadar değişeceğini tutar (ekrandan, 02:25:00):

| | yön 1 | yön 2 | yön 3 | yön 4 |
|---|---|---|---|---|
| $x$ değişimi | $-1$ | $0$ | $+1$ | $0$ |
| $y$ değişimi | $0$ | $+1$ | $0$ | $-1$ |

Tahtada yalnız birinci sütun ($-1$, $0$) yazılı göründü; hoca öteki değerleri vakit kaybetmemek için hızlıca doldurduğunu ve doğru olmayabileceğini söyledi. Yukarıdaki tablo, derste sözlü verilen yön kurallarından kurulmuştur. Güncelleme:

$$R_x = R_x + U[1][y], \qquad R_y = R_y + U[2][y]$$

Burada hiç `if` yoktur. 8 yön için yalnız $U$'ya 5, 6, 7, 8. yönlerin sütunları eklenir; başka bir değişiklik gerekmez.

Aşağıdaki program bu fikri gösterir. Derste C kodu yazılmadı; program ajan tarafından yazıldı, `gcc -Wall` ile uyarısız derlendi ve 20 adımla çalıştırıldı. C'de indisler 0'dan başladığı için $U$'nun 0. sütunu boş bırakıldı. Robotun ızgaranın dışına çıkmaması için eklenen sınır kontrolü derste yoktu; dizi dışına yazmayı önlemek için ajan tarafından eklendi.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOYUT 7

int main() {
    /* U[0][y]: x degisimi, U[1][y]: y degisimi; yon y = 1..4 */
    int U[2][5] = { {0, -1, 0, 1, 0},
                    {0, 0, 1, 0, -1} };
    int A[BOYUT][BOYUT];
    int n, i, j, y, rx = 3, ry = 3, nx, ny;
    printf("Adim sayisi: ");
    scanf("%d", &n);
    srand(time(NULL));
    for (i = 0; i < BOYUT; i++) {
        for (j = 0; j < BOYUT; j++) {
            A[i][j] = 0;
        }
    }
    A[rx][ry] = 1;
    for (i = 1; i <= n; i++) {
        y = 1 + rand() % 4;
        nx = rx + U[0][y];
        ny = ry + U[1][y];
        if (nx >= 0 && nx < BOYUT && ny >= 0 && ny < BOYUT) {
            rx = nx;
            ry = ny;
            A[rx][ry] = 1;
        }
    }
    for (i = 0; i < BOYUT; i++) {
        for (j = 0; j < BOYUT; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

## 12. Monte Carlo ile Pi

### 12.1 Algoritma ve soru

Son problem olarak şu algoritma çizildi (ekrandan, 02:30:00):

```text
say = 0
oku N
i = 1'den N'ye kadar:
    x = rand()        ([0, 1] aralığında)
    y = rand()
    x*x + y*y < 1 ise:  say = say + 1
T = 4 * say / N
yaz T
stop
```

**Soru:** $N$ büyükken (örneğin 1000 ya da 1 milyon) $T$'nin değeri ne olur? Sınıfa düşünmesi için birkaç dakika verildi, tahminler sohbetten alındı.

**Soru (bir öğrenci):** $x$ ve $y$ sıfırla bir arasında mı, uçlar dahil mi? **Cevap:** Dahil; dahil olmasa da çok önemli değil.

Tahminler çoğunlukla 1 ve 2 oldu; 3 ve 8 diyenler de vardı.

### 12.2 Çözüm

$x$ ve $y$, kenarı 1 olan birim karenin içinde bir nokta belirtir. Toplam $N$ nokta üretilir. $x^2 + y^2 < 1$ koşulu, merkezi orijin ve yarıçapı 1 olan dairenin karenin içinde kalan çeyreğini tanımlar (ekrandan, 02:45:00). Hoca bu bölgeyi kırmızı, karenin geri kalanını yeşil boyadı:

- $say$ = kırmızı noktaların sayısı.
- $N$ = kırmızı + yeşil, yani bütün noktalar.

$N$ sonsuz düşünülürse kırmızı bölge boşluksuz tamamen dolar, yeşil bölge de öyle. Böylece $say$ kırmızı bölgenin **alanına**, $N$ karenin alanına karşılık gelir:

$$say \leftrightarrow \frac{\pi r^2}{4} = \frac{\pi}{4} \quad (r = 1), \qquad N \leftrightarrow 1$$

$$T = \frac{4 \cdot say}{N} = \frac{4 \cdot \pi / 4}{1} = \pi$$

$N$ büyüdükçe üretilen $T$ değeri $\pi$'ye yaklaşır. Bu, bilgisayarda $\pi$'yi istenen çözünürlükte hesaplamanın bir yoludur. Saymayla hesap yapan bu tür süreçlere **Monte Carlo** süreçleri denir.

Aşağıdaki program tahtadaki akış diyagramının C karşılığıdır. Derste C kodu yazılmadı; program ajan tarafından yazıldı, `gcc -Wall` ile uyarısız derlendi. $N = 1000$ için yaklaşık $3{,}20$, $N = 1.000.000$ için yaklaşık $3{,}138$ verdi (sonuç seed'e göre değişir).

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, say = 0;
    double x, y, t;
    printf("Nokta sayisi: ");
    scanf("%d", &n);
    srand(time(NULL));
    for (i = 1; i <= n; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (x * x + y * y < 1) {
            say = say + 1;
        }
    }
    t = 4.0 * say / n;
    printf("T = %f\n", t);
    return 0;
}
```

## 13. Ders Sonunda Sorulan Sorular

### 13.1 Çok yüksek çözünürlük ve büyük sayılar

**Soru:** Çözünürlük arttıkça C programım sayı yerine `-1.#INF` gibi bir çıktı veriyor; ne yapmalıyım? **Cevap:** C'de her değişken için bellekte bir alan ayrılır ve bu alanın büyüklüğü türle (`int`, `float`, `double`) belirlenir. Ayrılan alan, değişkenin alabileceği en küçük ve en büyük değeri de belirler. 100.000 basamaklı bir sayı hiçbir programlama dilinde tek bir değişken olarak tanımlanamaz.

**Soru (hocadan):** Peki iki tane 100.000 basamaklı sayı toplanabilir mi, nasıl? Bir öğrenci sayıyı en anlamlı ve en anlamsız kısımlar diye ikiye bölmeyi önerdi; hoca bunun yeterince hassas olmayacağını söyledi. **Cevap:** Sayı bir dizide tutulur. 100.000 elemanlı bir dizi tanımlanabilir ve basamaklar onun içine konur. Ama o zaman toplama, çıkarma, çarpma, bölme gibi işlemlerin hepsini sizin yazmanız gerekir: "$A$ dizisi ile $B$ dizisini topla" işlemi aslında "$A$ sayısı ile $B$ sayısını topla" anlamına gelecek şekilde yazılır. Mevcut kütüphanelerdeki işlemler kullanılamaz. Bu yolla çok yüksek çözünürlüklere ulaşılabilir.

### 13.2 Kayan noktalı sayılarda küçük hatalar

**Soru:** `float` ile 3'ü 10'a bölünce bazen $0{,}3000001$ gibi bir sonuç çıkıyor; neden? **Cevap:** Kayan noktalı sayılarla aritmetiğin arka planda nasıl yapıldığı bilgisayar mimarisi derslerinde görülecek. Yüksek çözünürlük gereken durumlarda bir yerde yuvarlama yapılmak zorunda kalınır ve bu istenmeyen sonuçlara yol açar. Bu dersin kapsamında değildir. Tam sayılarla çalışıldığı sürece bu sorun olmaz; kesin bir çözüm yoktur, ama etkisini azaltmanın yolları vardır.

### 13.3 Grafik çizmek

**Soru:** Desenleri çizmek için grafik kütüphanesi mi kullanılıyor? **Cevap:** Evet, harici bir grafik kütüphanesi gerekir. Ama komut isteminde bile metinle gösterim yapılabilir: örneğin iki uniform sayının toplamının dağılımını görmek için her değerin kaç kez tekrar ettiği sayılır ve her değer için bir satıra o kadar yıldız (`*`) basılır. Desenleri çizmek de karmaşık değildir: bir kütüphane bulunur ve bir noktadan bir noktaya çizgi çeken fonksiyonun nasıl çağrıldığı öğrenilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:19:05): Bir sayının $\bmod\ m$'i hangi değerleri alabilir?

> **Çözüm:** $0$ ile $m-1$ arasındaki değerleri; $m$'yi alamaz.

**Soru 2** (ekrandan, 00:30:00): $y_i = (s \cdot i) \bmod m$ ile üretilen indisler $1, 42, 4, 5, 6, 33, 4$ diye gelmiştir. Bundan sonra ne gelir? Neden?

> **Çözüm:** $5, 6, 33, 4, 5, 6, \ldots$ Her değer yalnız bir önceki değere bağlı olduğu için 4 ikinci kez geldiği anda aynı döngü tekrar eder.

**Soru 3** (derste sözlü, 00:33:22): Bu sayı üretecinin çemberin kaç noktasından geçtiğini nasıl sayarsınız?

> **Çözüm:** $m$ elemanlı bir $T$ dizisi sıfırlanır, döngüde $T[i] = T[i] + 1$ yapılır. Sonunda 0 olan elemanlar hiç gezilmemiş noktalardır. Bütün elemanlar 1 ise üreteç her değeri bir kez, yani eşit olasılıkla üretmiştir.

**Soru 4** (derste sözlü, 00:46:19): $R_n = (A \cdot R_{n-1} + C) \bmod M$ üretecinde $A$, $C$, $M$ nasıl seçilmeli?

> **Çözüm:** $0 \ldots M-1$ arasındaki bütün değerler $M$ adımda, tekrarsız üretilecek şekilde. Böyle bir üreteç bütün değerleri eşit olasılıkla üretir. Örnek: $A = 1366$, $C = 150889$, $M = 714025$.

**Soru 5** (ekrandan, 01:05:00): Üretecin başlangıç değeri $i = 1$ yerine $2$ ya da $5$ olsa ne değişir?

> **Çözüm:** Süreç ve olasılıklar değişmez, yalnız görülen sıra kayar: $1, 2, \ldots, 7$ yerine $2, 3, \ldots, 7, 1$ ya da $5, 6, 7, 1, 2, 3, 4$. Bu başlangıç değerine seed denir; C'de her çalıştırmada farklı olması için `srand(time(NULL));` kullanılır.

**Soru 6** (ekrandan, 01:25:00): $zar = 1 + ((a \cdot zar + c) \bmod k)$ formülünde $k$ kaç olmalı? Verilen $a$, $c$ için zarın hileli olup olmadığını nasıl anlarsınız?

> **Çözüm:** $k = 6$; $\bmod 6$ $0 \ldots 5$ verir, $+1$ ile $1 \ldots 6$ olur. Çok sayıda zar atılır, $T[zar] = T[zar] + 1$ ile sayılır. Bütün sayılar ortalamanın çevresindeki tolerans aralığındaysa (ör. 600.000 atışta $100.000 \pm 1000$) zar hilesiz, değilse hilelidir.

**Soru 7** (derste sözlü, 01:25:09): $[0, 1]$ aralığında hilesiz sayı üreten `rand` ile $[45, 54]$ kapalı aralığında hilesiz tam sayı nasıl üretilir?

> **Çözüm:** $45 + \lfloor rand \cdot 10 \rfloor$; genel olarak $x + \lfloor t \cdot (y - x + 1) \rfloor$. Not: $t = 1$ çıkabiliyorsa sonuç 55 olur, bu yüzden formül $t \in [0, 1)$ için doğrudur.

**Soru 8** (ekrandan, 01:35:00): 52 kartı karıştırmak için $i = 1 \ldots 52$ döngüsünde $T = rand()$ üretilip $B[T] = 1$ değilse $T$ yazdırılıyor ve $B[T] = 1$ yapılıyor. Bu algoritmada sorun var mı?

> **Çözüm:** Var. Tekrar eden sayılar atlandığı için 52 sayı yazdırılmaz. Döngü `while (i < 52)` olmalı ve $i$ yalnız yeni bir sayı kabul edildiğinde artırılmalıdır (ekrandan, 01:40:00). Bu düzeltilmiş hal bile sonlara doğru çok sayıda boş deneme yapar.

**Soru 9** (ekrandan, 01:45:00): $A$ dizisine $1 \ldots 52$ yazılıp iki rastgele indisin elemanları `Temp` ile yer değiştiriliyor ve bu 30 kez tekrarlanıyor. Bu yöntem birinci yoldan daha iyi mi?

> **Çözüm:** Evet, her işlem dizide bir değişiklik yaptığı için çok daha hızlıdır ve dizi büyüdükçe üstünlüğü artar. Ders sonrası not: 30 değiştirmede ortalama yaklaşık 16 kart yerinde kalır; iyi bir karışım için daha çok tekrar gerekir (python ile hesaplandı).

**Soru 10** (derste sözlü, 01:46:44): Bir sınıfın bir sınavdan aldığı notlar uniform mu dağılır, Gauss mu?

> **Çözüm:** Gauss. Notlar bir ortalama çevresinde kümelenir, çok yüksek ve çok düşük notlar azdır.

**Soru 11** (ekrandan, 01:55:00): `rand` $1 \ldots 99$ arasında uniform tam sayı üretiyor ve $C = A + B$. $C = 2, 3, 4, 50, 100, 198$ değerleri hangi $(A, B)$ çiftleriyle oluşur? $C$'nin dağılımı nasıldır?

> **Çözüm:** $C = 2$: $(1,1)$; $C = 3$: $(1,2)$, $(2,1)$; $C = 4$: $(1,3)$, $(2,2)$, $(3,1)$; $C = 50$: 49 sıralı çift; $C = 100$: 99 sıralı çift; $C = 198$: $(99,99)$. Ortadaki değerler çok, kenardakiler az oluştuğu için dağılım uniform değildir, çan eğrisine benzer. (Derste sıra önemsenmeden yazıldı; sıralı çift sayıları python ile sayıldı.)

**Soru 12** (ekrandan, 02:15:00): Izgarada $(x, y)$ konumundaki robot 1 (yukarı), 2 (sağ), 3 (aşağı), 4 (sol) yönlerine gidebiliyor; $x$ satırı, $y$ sütunu gösteriyor. Her yön için $x$ ve $y$ nasıl değişir? Rastgele yürüyüşü `if` kullanmadan nasıl yazarsınız?

> **Çözüm:** 1: $x-1$; 2: $y+1$; 3: $x+1$; 4: $y-1$. Bu değişimler $2 \times 4$'lük bir $U$ matrisinde tutulur ve $y = rand()$ ($1 \ldots 4$) için $R_x = R_x + U[1][y]$, $R_y = R_y + U[2][y]$ yapılır. 8 yön için $U$'ya dört sütun eklenir.

**Soru 13** (ekrandan, 02:30:00): $say = 0$; $N$ kez $x = rand()$, $y = rand()$ ($[0,1]$) üretilip $x \cdot x + y \cdot y < 1$ ise $say$ artırılıyor; sonunda $T = 4 \cdot say / N$ yazdırılıyor. $N$ büyükken $T$ ne olur?

> **Çözüm:** $T \to \pi$. Noktalar birim karede, koşul çeyrek daireyi tanımlar. Alanlar oranı $\frac{\pi/4}{1}$ olduğundan $say/N \to \pi/4$ ve $T = 4 \cdot say / N \to \pi$ (ekrandan, 02:45:00). C ile $N = 10^6$ için yaklaşık $3{,}14$ çıktı.

**Soru 14** (derste sözlü, 02:45:35): Hiçbir dilde tek değişkene sığmayan iki tane 100.000 basamaklı sayıyı nasıl toplarsınız?

> **Çözüm:** Basamakları dizilerde tutarak ve toplama işlemini basamak basamak kendiniz yazarak. Çıkarma, çarpma, bölme gibi işlemler de aynı şekilde yeniden yazılmalıdır.

## Dersin Toparlaması

Ders, çember üzerinde eşit aralıklı noktaları $y_i = (i \cdot s) \bmod m$ kuralıyla birleştiren bir desen algoritmasıyla başladı ve bu sürecin aslında bir sayı üreteci olduğunu gösterdi. Her değer yalnız bir öncekine bağlı olduğu için bir tekrar olduğunda süreç aynı döngüye girer. İyi seçilmiş parametreler bütün değerleri tekrarsız gezer ve uniform bir üreteç verir. Buradan bilgisayarlarda gerçek rastgeleliğin olmadığı, bütün `random` fonksiyonlarının $R_n = (A R_{n-1} + C) \bmod M$ gibi deterministik formüllere dayanan sözde rastgele üreteçler olduğu sonucuna varıldı. Rastgelelik illüzyonu büyük bir çevrim ve her çalıştırmada değişen bir seed (C'de `srand(time(NULL))`) ile sağlanır.

Dersin ikinci yarısı rastgele sayıların kullanımına ayrıldı: hilesiz zar ve hile kontrolü, bir aralıkta tam sayı üretmek, 52 kartı reddetme ya da rastgele yer değiştirmeyle karıştırmak, iki uniform sayının toplamıyla çan eğrisine benzeyen bir dağılım elde etmek, yön tablosu kullanarak `if`'siz rastgele yürüyüş ve Monte Carlo yöntemiyle $\pi$'yi hesaplamak. Ortak fikir şudur: rastgele sayılar dikkatli kullanılınca simülasyon, oyun, algoritma testi ve sayısal hesap için güçlü bir araçtır; ama hangi dağılımın gerektiği ve algoritmanın boşa deneme yapıp yapmadığı ayrıca düşünülmelidir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
