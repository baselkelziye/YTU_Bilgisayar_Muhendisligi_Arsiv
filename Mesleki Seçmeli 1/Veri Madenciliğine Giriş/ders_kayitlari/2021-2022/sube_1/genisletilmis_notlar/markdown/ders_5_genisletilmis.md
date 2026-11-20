# Ders 5 Genişletilmiş Notu: Veri Bütünleştirme, Korelasyon Analizi, Normalizasyon ve Ayrıklaştırma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bir Süreç Olarak Veri Temizleme
- 2. Veri Bütünleştirme
- 3. Gereksiz Öznitelikler ve Korelasyon Analizi
- 4. Sayısal Öznitelikler: Korelasyon Katsayısı ve Kovaryans
- 5. Nominal Öznitelikler: Ki-Kare Testi
- 6. Veri Dönüştürme ve Normalizasyon
- 7. Ayrıklaştırma
- 8. Ön İşlemede Çalışma Düzeni

## 1. Bir Süreç Olarak Veri Temizleme

Hoca derse, bir önceki derste görülen düzleştirme (smoothing) konusunu hatırlatarak başladı. Gürültülü veriyi düzleştirmek için değerler kutulara (bin) ayrılabiliyordu ve bu teknikler veri indirgeme (data reduction) için de kullanılabiliyordu. Eksik (null) değerlerden de daha önce bahsedilmişti. Bu derste veri temizlemeye bir süreç olarak bakıldı.

Eksik değerlerin yanında, verinin içinde uyumsuzluk (discrepancy) da olabilir. Hocanın örnekleri şunlardı: kullanıcı bir yerde doğum tarihini, başka bir yerde yaşını girmiştir ve ikisi birbiriyle uyumlu değildir; ya da adresteki şehir ile girilen posta kodu birbirini tutmaz. Bu tür durumlarda veriden çıkarım yapılarak hata bulunabilir.

Bunu yaparken elde metadata varsa kullanılır. Metadata, verinin kendisi hakkındaki bilgidir. Hoca bunu fotoğraf örneğiyle açıkladı: bir fotoğrafın içinde gizli veri vardır; nerede çekildiği, hangi tarihte çekildiği gibi. Web sitelerinin sayfalarında ya da loglarda da metadata bulunabilir. Bu bilgiler, verinin bütünlüğünü bozan ya da hataya sebep olan kayıtları bulmakta kullanılabilir.

Slaytta uyumsuzluk bulma (data discrepancy detection) için şu maddeler yer alıyordu (ekrandan, 00:05:00):

- Metadata kullanmak: alan (domain), aralık (range), bağımlılık (dependency), dağılım (distribution).
- Teklik (uniqueness), ardışıklık (consecutive) ve boş değer (null) kurallarını denetlemek.
- Örneğin bir öznitelikte ortalamadan iki standart sapmadan daha uzak olan değerleri olası aykırı değer (outlier) olarak işaretlemek.
- Ticari araçlar kullanmak:
  - Data scrubbing: posta kodu, yazım denetimi (spell-check) gibi basit alan bilgisiyle hataları bulup düzeltmek.
  - Data auditing: veriyi analiz edip kurallar ve ilişkiler çıkarmak, bunlara uymayanları bulmak (örneğin korelasyon ve kümeleme ile aykırı değer bulmak).

Hoca ticari araçlara örnek olarak, bir posta kodunun gerçekten o bölgeye ait olup olmadığını denetleyen (Amerika için kullanılan) ya da yazım yanlışı arayan programlardan bahsetti. Slaytta ayrıca veri taşıma ve bütünleştirme araçları (ETL: Extraction/Transformation/Loading) ve bu iki sürecin yinelemeli, etkileşimli olarak birleştirilmesi de yer alıyordu.

## 2. Veri Bütünleştirme

Veri bütünleştirme (data integration), farklı yerlerden gelen veriyi bir araya getirmektir. Bunun birçok nedeni olabilir: bir firmanın farklı şubeleri (branch) farklı yerlerde veri tutuyor olabilir; ya da bir şeyi tahmin etmek için ek veri gerekebilir. Örneğin bir yerden hava durumu verisi alınabilir, ya da bir crawler yazılıp başka bir web sitesinden veri çekilebilir. Veri farklı veri tabanlarından da çekilebilir.

Bu verileri birleştirirken genellikle ön işlem yapmak zorunda kalınır, çünkü kaynakların formatları ve verinin tutuluş biçimleri birbirinden farklıdır. Veri çekildikten sonra en basitinden şunlara bakmak gerekir:

- Tekrarlayan kayıt (duplicate record) var mı? Aynı kişi iki yerde de var mı?
- Birimler uyumlu mu? Örneğin üç yıllık sıcaklık verisi bir yerden, daha önceki yıllar ve nem, rüzgâr hızı gibi bilgiler başka bir yerden alındıysa birimleri çevirmek gerekebilir.

Hoca bütünleştirmenin neden önemli olduğunu bir yarışma örneğiyle anlattı. Bir havayolu şirketi veri madenciliği yarışması düzenlemiş; takımlara uçuş ve müşteri verisi verilmiş, rötar olup olmayacağını tahmin etmeleri istenmiş. Birinci olan takım, o günlerin hava şartlarıyla ilgili ek veri çekip gün gün kendi verisine eklemiş. Elinde daha çok öznitelik olduğu için daha iyi tahmin yapabilmiş. Hoca, tek bir kaynaktan veriyi alıp kullanmanın genellikle verimli olmadığını söyledi; öneri sistemlerinin (recommender systems) farklı uygulamalardan gelen verileri birleştirerek çalıştığını öğrencilerin de fark ettiğini belirtti. Yine de bunun amaca bağlı olduğunu ekledi.

## 3. Gereksiz Öznitelikler ve Korelasyon Analizi

**Soru:** Veride tekrarlayan (gereksiz) bilgi olup olmadığını nasıl anlarız? **Cevap:** Hoca önce daha basit bir duruma baktı: bazı öznitelikleri birlikte tutmanın anlamı yoktur. Hem posta kodunu hem ilçe ve mahalleyi tutmak, ya da hem yaşı hem doğum tarihini tutmak aynı bilgiyi iki kez tutmaktır.

Slayttaki tanıma göre (ekrandan, 00:10:00) gereksizlik (redundancy) bütünleştirmede önemli bir sorundur. Bir öznitelik başka bir öznitelikten ya da öznitelikler kümesinden türetilebiliyorsa (derived) gereksizdir. Gereksiz öznitelik veriyi büyütür, boşuna işlem yaptırır ve hesaplama gücünü harcar. Bu yüzden böyle özniteliklerden biri çıkarılabilir.

Birden çok veri tabanı birleştirildiğinde gereksiz veri sık ortaya çıkar:

- Nesne tanımlama (object identification): aynı öznitelik ya da nesne farklı veri tabanlarında farklı adlarla geçebilir. Hoca bunu, iki isimli bir kullanıcının bir yerde bir adını, başka yerde öteki adını vermesine benzetti; iki kaydın aynı kişiye ait olduğunu bilmeyebilirsiniz.
- Türetilebilir veri (derivable data): bir öznitelik başka bir tabloda türetilmiş bir öznitelik olabilir, örneğin yıllık gelir.

Bazen iki, üç ya da dört veri kaynağı bir araya getirilip tek bir veri gibi işlenir. Dikkatli bütünleştirme gereksizliği ve tutarsızlığı azaltır, madenciliğin hızını ve kalitesini artırır.

Gereksiz öznitelikler korelasyon analiziyle bulunabilir. Burada önemli olan, korelasyonun kullanıcılar (satırlar) arasında değil öznitelikler (sütunlar) arasında aranmasıdır. İki sütun aynı şeyi ifade ediyorsa aralarında güçlü bir pozitif korelasyon vardır ve yalnız birini kullanmak yeterlidir. Yöntem özniteliğin türüne bağlıdır:

- Sayısal öznitelikler için korelasyon katsayısı ve kovaryans.
- Nominal (kategorik) öznitelikler için $\chi^2$ (ki-kare) testi.

## 4. Sayısal Öznitelikler: Korelasyon Katsayısı ve Kovaryans

### 4.1 Korelasyon katsayısı

İki sayısal sütun $A$ ve $B$ olsun. Önce iki sütunun ortalamaları $\bar{A}$ ve $\bar{B}$ bulunur. Sonra her satırda $A$ değerinden $\bar{A}$, $B$ değerinden $\bar{B}$ çıkarılır, bu farklar çarpılıp toplanır ve eleman sayısı ile standart sapmalara bölünür. Elde edilen değer korelasyon katsayısı $r$'dir.

- $r$ $-1$'e yakınsa biri artarken öteki azalır; aralarında negatif korelasyon vardır.
- $r$ $1$'e yakınsa (hocaya göre $0.5$'in üstü bile iyi sayılabilir) biri artarken öteki de artar; pozitif korelasyon vardır.
- $r$ $0$ civarındaysa ikisi birbirinden bağımsızdır, aralarında korelasyon yoktur. Bu durumda ikisi de silinmez, çünkü iki sütun farklı şeyler söylemektedir.

Bu hesap pratikte tek tek döngüyle yazılmaz. Araçlardaki scatter plot (saçılım grafiği) komutu, örneğin 10 öznitelik varsa bütün öznitelik çiftlerinin ilişkisini bir tablo halinde görsel olarak verir. İkili ilişkiler bir matris olarak düşünülürse bu bir korelasyon matrisidir.

### 4.2 Kovaryans

Slaytta kovaryans şöyle tanımlanıyordu (ekrandan, 00:15:00). $A$ ve $B$'nin ortalamaları, onların beklenen değerleri (expected values) olarak da bilinir:

$$E(A)=\bar{A}=\frac{\sum_{i=1}^{n} a_i}{n}, \qquad E(B)=\bar{B}=\frac{\sum_{i=1}^{n} b_i}{n}$$

Varyans bir değerin ortalamadan ne kadar uzaklaştığını ölçer. "Ko" öneki birlikteliği gösterir; kovaryans iki özniteliğin birlikte nasıl değiştiğine bakar:

$$Cov(A,B)=E((A-\bar{A})(B-\bar{B}))=\frac{\sum_{i=1}^{n}(a_i-\bar{A})(b_i-\bar{B})}{n}$$

Kovaryans korelasyon katsayısına benzer; kovaryans standart sapmaların çarpımına bölünürse korelasyon katsayısı elde edilir:

$$r_{A,B}=\frac{Cov(A,B)}{\sigma_A\sigma_B}$$

> **Ders sonrası not:** Hoca 00:15:01 civarında "standart sapmalara böldüğümüz zaman kovaryansları buluyoruz" dedi; doğrusu, kovaryans standart sapmaların çarpımına bölününce korelasyon katsayısı $r_{A,B}$ bulunur (slayttaki formül de budur).

Slaytta ayrıca hesabı kolaylaştıran bir eşitlik vardı:

$$Cov(A,B)=E(A\cdot B)-\bar{A}\bar{B}$$

Hoca bu eşitliği şöyle yorumladı: her satırda $a_i$ ile $b_i$'yi çarpıp toplamak aslında iki vektörün iç çarpımıdır (dot product); birinci eleman birinci elemanla, ikinci eleman ikinci elemanla çarpılır. Yani farkları tek tek almak yerine önce iki sütunun iç çarpımının ortalaması alınır, sonra ortalamaların çarpımı çıkarılır. Görünüşü karışık olsa da tanımla aynı sonucu verir.

### 4.3 Hisse senedi örneği

Slaytta iki hisse senedi ($A$ ve $B$) için beş zamandaki değerler verilmişti; her satırın ilk değeri $A$'nın, ikincisi $B$'nin değeridir (derste sözlü, 00:16:04). Hoca, gerçekte beş satırlık veri olmayacağını, yalnız kolay göstermek için az değer verildiğini belirtti. Soru şudur: iki hisse aynı sektör eğiliminden etkileniyorsa, biri artarken öteki düşer mi, yoksa birlikte mi hareket ederler?

Önce beklenen değerler, yani ortalamalar hesaplanır. Sonra iki sütunun iç çarpımı alınıp eleman sayısına bölünür ve ortalamaların çarpımı çıkarılır. Altyazıda $B$'nin değerleri $5, 8, 10, 11, 14$; $A$'nın değerleri $2, 3, 5, 4$ ve bir beşinci değer olarak duyuluyor. Hoca sonucu $4.88$ olarak okudu.

<!-- BELİRSİZ: Kovaryans örneğinin slaytı karelerde yok. A'nın beşinci değeri altyazıdan net çıkmıyor. Python ile: beşinci değer 7 ise E(A)=4.2, E(B)=9.6, E(A·B)=45.2, Cov=45.2-40.32=4.88 olur, yani hocanın okuduğu sonuçla tam uyar; beşinci değer 6 ise E(A)=4, E(A·B)=42.4, Cov=42.4-38.4=4 olur. -->

Yorum: sonuç sıfır civarında değil, belirgin biçimde pozitiftir. Negatif çıksaydı biri azalırken ötekinin arttığı, sıfıra yakın çıksaydı aralarında ilişki olmadığı söylenecekti. Pozitif çıktığı için iki hisse arasında pozitif bir ilişki vardır: biri artarken öteki de artar.

Hoca bu tür hesapların istatistik derslerinde görüldüğünü, sınavda doğrudan bu tür bir istatistik sorusu sormayacağını söyledi ve asıl önemli olanın nominal öznitelikler için ne yapılacağı olduğunu belirtti.

## 5. Nominal Öznitelikler: Ki-Kare Testi

### 5.1 Problem

Öznitelikler nominal ise (küçük, orta, büyük; yaşlı, genç; siyah, beyaz, kırmızı gibi) iki öznitelik arasındaki ilişki nasıl hesaplanır? Değerlere sayı vermek işe yaramaz: üç değer varsa hangisine $0$, hangisine $1$, hangisine $2$ deneceği bilinmez; değerler ordinal de değildir.

**Soru:** Nominal iki öznitelik arasındaki ilişkiye nasıl bakarız? **Cevap:** Öğrencilerden gelen önerilerden biri değerleri saymaktı. Hoca bunun bir başlangıç olduğunu söyledi: sayılara bakınca en azından dengeli bir dağılım bekleriz. Örneğin $A$ sütununda değerlerin $\frac{1}{4}$'ü a, $\frac{1}{4}$'ü b, $\frac{2}{4}$'ü c ise, öteki sütunda da benzer oranlar bekleriz. Bu fikrin sistematik hali $\chi^2$ testidir.

### 5.2 Ki-kare formülü

Slayttaki tanım şöyledir (ekrandan, 00:20:00). $A$'nın $c$ farklı değeri $a_1,\dots,a_c$; $B$'nin $r$ farklı değeri $b_1,\dots,b_r$ olsun. Bu iki sayının eşit olması gerekmez; $A$ beş değer alırken $B$ daha az ya da daha çok değer alabilir.

$$\chi^2=\sum_{i=1}^{c}\sum_{j=1}^{r}\frac{(o_{ij}-e_{ij})^2}{e_{ij}}$$

- $o_{ij}$ gözlenen frekanstır (observed frequency): $(A_i,B_j)$ ikilisinin veride gerçekten kaç kez geçtiği.
- $e_{ij}$ beklenen frekanstır (expected frequency):

$$e_{ij}=\frac{count(A=a_i)\times count(B=b_j)}{n}$$

Burada $n$ toplam kayıt sayısı, $count(A=a_i)$ $A$'sı $a_i$ olan kayıt sayısı, $count(B=b_j)$ $B$'si $b_j$ olan kayıt sayısıdır.

Hoca bunu bir örnekle somutlaştırdı: $A$'nın değerleri siyah, beyaz, kırmızı, mavi, sarı; $B$'nin değerleri küçük, orta, büyük olsun. Formül $A$'nın her değerini sırayla alır; önce siyah, ardından $B$'nin her değeri: siyah-küçük, siyah-orta, siyah-büyük. Siyah-küçük için veride gerçekten kaç tane olduğu ($o_{ij}$) ile beklenen sayı ($e_{ij}$, yani siyah sayısı çarpı küçük sayısı bölü toplam kayıt sayısı) karşılaştırılır; farkın karesi beklenen değere bölünür. Bu bütün ikililer için toplanır.

**Soru:** Formülde fark neden beklenen değere bölünüyor? **Cevap:** Normalize etmek için. Sayılar birbirinden çok farklı olduğunda ve veri büyük olduğunda farkın karesi çok büyük çıkabilir; $e_{ij}$'ye bölmek bu katkıları ölçeklendirir.

Yorum: $\chi^2$ değeri ne kadar büyükse değişkenlerin ilişkili olma olasılığı o kadar yüksektir. $\chi^2$'ye en çok katkı yapan hücreler, gerçek sayısı beklenen sayıdan çok farklı olan hücrelerdir. $\chi^2$, korelasyon katsayısı gibi negatif olamaz, çünkü karesi alınan farkların pozitif sayılara bölünmesiyle elde edilir.

> **Ders sonrası not:** Hoca anlatım sırasında önce (00:22:37 ve 00:28:33 civarı) ilişkili özniteliklerde $\chi^2$'nin sıfıra yakın çıkacağını, siyahların hep küçük, beyazların hep orta, kırmızıların hep büyük olduğu bir veride sonucun sıfıra yakın olacağını söyledi; sonra bir öğrencinin uyarısıyla düzeltti. Doğrusu: gözlenen sayılar beklenen sayılara yakınsa $\chi^2$ küçük çıkar ve bu ilişkisizlik (bağımsızlık) demektir. Hocanın verdiği "her renk tek bir boya karşılık geliyor" örneği tam bağımlılıktır ve $\chi^2$ büyük çıkar.

### 5.3 Bilim kurgu ve satranç örneği

Slayttaki örnekte (ekrandan, 00:25:00) iki öznitelik vardır: kişinin bilim kurgu sevip sevmediği (LikeScienceFiction, evet/hayır) ve satranç oynayıp oynamadığı (PlayChess, evet/hayır). Kolay hesaplansın diye her ikilinin sayısı doğrudan verilmiştir. Hücrelerdeki sayılar gözlenen, parantez içindekiler beklenen frekanslardır:

```text
                          Play chess   Not play chess   Sum (row)
Like science fiction      250 (90)     200 (360)        450
Not like science fiction  50 (210)     1000 (840)       1050
Sum (col.)                300          1200             1500
```

Toplam $250+200+50+1000=1500$ kayıt vardır. Bunların 250'si iki soruya da evet, 200'ü bilim kurgu evet ve satranç hayır, 50'si bilim kurgu hayır ve satranç evet, 1000'i iki soruya da hayır demiştir. Amaç, bu iki sütunun birbiriyle ilişkili olup olmadığını bulmaktır. Değerler nominal olduğu için $\chi^2$ kullanılır.

Beklenen değerler satır ve sütun toplamlarından hesaplanır:

- Bilim kurgu seven ve satranç oynayan: $e=\frac{450\times 300}{1500}=90$.
- Bilim kurgu seven ve satranç oynamayan: $e=\frac{450\times 1200}{1500}=360$.
- Bilim kurgu sevmeyen ve satranç oynayan: $e=\frac{1050\times 300}{1500}=210$.
- Bilim kurgu sevmeyen ve satranç oynamayan: $e=\frac{1050\times 1200}{1500}=840$.

Formülde yerine koyunca:

$$\chi^2=\frac{(250-90)^2}{90}+\frac{(50-210)^2}{210}+\frac{(200-360)^2}{360}+\frac{(1000-840)^2}{840}$$

$$\chi^2=284.44+121.90+71.11+30.48=507.93$$

(ara terimler eklendi; python ile doğrulandı.) Sonuç büyüktür; bilim kurgu sevmek ile satranç oynamak bu veride ilişkilidir.

> **Hocanın vurgusu:** $\chi^2$ ne kadar büyükse iki öznitelik arasında o kadar ilişki vardır. Hoca bu düzeltmeyi derste özellikle vurguladı.

## 6. Veri Dönüştürme ve Normalizasyon

### 6.1 Neden dönüştürürüz?

Buraya kadar verinin nasıl temizleneceği ve düzleştirileceği, sonra nasıl bütünleştirileceği görüldü. Sırada veri dönüştürme (data transformation) ve ayrıklaştırma (discretization) vardır.

Dönüştürme genellikle bütünleştirme sırasında gerekir. Örneğin bir firmanın farklı ülkelerdeki şubelerinden biri satışları dolar, öteki Türk lirası cinsinden tutmuştur; birleştirmek için dönüştürme yapmak gerekir. Dönüştürmenin bir türü normalizasyondur. Ayrıklaştırma ise sayısal bir değerin nominal (kategorik) bir değer olarak tutulmasıdır.

Normalizasyonun neden gerektiğini hoca bir ev fiyatı veri setiyle anlattı. Veride evin oda sayısı, yeri gibi bilgiler ve gerçek fiyatlar var. Bir noktadan sonra bazı evlerin fiyatı çok yükseliyor: çok sayıda ucuz ev, az sayıda çok pahalı ev var. Veri normalize edilmeden verilirse, aralık çok büyük olduğu için ileride görülecek regresyon gibi yöntemlerde büyük sayılar küçük sayıları anlamsız hale getirebilir. Bu kullanılan algoritmaya göre değişir. Ayrıca bazı yöntemler yalnız $0$-$1$ aralığında girdi alabilir. Hangi normalizasyonun daha iyi olduğu da yönteme göre değişir: yapay sinir ağlarında normalizasyon çok fark eder ve ağ daha hızlı öğrenebilir; Bayes ağlarında çok fark etmeyebilir.

Üç normalizasyon yöntemi anlatıldı: min-max, z-skor ve ondalık ölçekleme.

### 6.2 Min-max normalizasyonu

**Soru:** Bir özniteliğin değerlerini $0$-$1$ aralığına nasıl eşlersiniz? **Cevap:** En büyük ve en küçük değer bulunur. Her değerden minimum çıkarılırsa en küçük değer sıfıra gelir. Sonra minimum ile maksimum arasındaki farka bölünürse değerler $0$-$1$ aralığına ölçeklenir.

Slayttaki formül, istenen herhangi bir $[new\_min_A, new\_max_A]$ aralığı içindir (ekrandan, 00:35:00):

$$v_i'=\frac{v_i-min_A}{max_A-min_A}(new\_max_A-new\_min_A)+new\_min_A$$

Kesir kısmı değeri $0$-$1$ aralığına getirir; sonra yeni aralığın genişliğiyle çarpılıp yeni minimum eklenerek istenen aralığa kaydırılır. $new\_min=0$, $new\_max=1$ konursa ilk anlatılan basit hal elde edilir. Hedef her zaman $[0,1]$ olmak zorunda değildir; ne yapılacağına göre $[-1,1]$ de seçilebilir.

Min-max normalizasyonu doğrusal bir dönüşümdür: değerleri normal dağılıma falan çevirmez, değerler arasındaki ilişkiyi korur. En çok kullanılan yöntemdir. Hoca güzel bir yanını şöyle anlattı: iki farklı yerde, birimi ve aleti bilinmeyen basınç ölçümleri toplanmış olsun, coğrafi olarak çok fark da olmasın. İki kaynak ayrı ayrı $0$-$1$ aralığına eşlendikten sonra birleştirilebilir. Arada küçük hatalar olabilir, ama bu yolla birleştirmek mümkündür.

### 6.3 Z-skor normalizasyonu

Z-skor normalizasyonunda (zero-mean normalization da denir) değerler özniteliğin ortalamasına ve standart sapmasına göre normalize edilir (ekrandan, 00:40:00):

$$v_i'=\frac{v_i-\bar{A}}{\sigma_A}$$

Burada $\bar{A}$ ve $\sigma_A$ $A$ özniteliğinin ortalaması ve standart sapmasıdır. Ortalama çıkarılınca dağılım ortalaması sıfır olacak şekilde taşınır. Standart sapmaya bölünce ise dağılımın yayılımı ölçeklenir: standart sapma büyükse, yani dağılım daha yaygınsa, büyük bir sayıya bölündüğü için değerler daha küçük bir aralığa çekilir.

**Soru:** Z-skor normalizasyonunun min-max'tan farkı nedir, ne sağlar? **Cevap:** Öğrencilerden gelen cevap, normal dağılımın avantajını kullanabilmek ve minimum-maksimumdan emin olmak gerekmemesiydi. Hoca ikinci noktayı açtı: verideki en küçük değer gerçek minimum olmayabilir, çünkü test aşamasında daha küçük bir değer gelebilir. Örneğin veri yetişkinlerden toplanmış ve min-max ile 18 yaş $0$'a eşlenmişse, model çocuklara uygulandığında 18'in altındaki bütün yaşlar $0$ olarak alınır ve sorun çıkar. Test aşamasında gelecek minimum ve maksimumdan emin değilseniz ve elinizdeki dağılıma güveniyorsanız z-skor normalizasyonu yapılır.

Slayttaki örnek (ekrandan, 00:40:00): gelir (income) özniteliğinin ortalaması 54.000 dolar, standart sapması 16.000 dolardır. 73.600 dolarlık bir gelir z-skor ile şöyle normalize edilir:

$$v'=\frac{73600-54000}{16000}=\frac{19600}{16000}=1.225$$

(ara adım eklendi; python ile doğrulandı.)

### 6.4 Ondalık ölçekleme

En basit yöntem, değerleri 10'un bir kuvvetine bölmektir (decimal scaling). Hocanın okuduğu örnek şudur (derste sözlü, 00:40:47): $A$ sütunundaki değerler $-986$ ile $917$ arasındadır. En büyük mutlak değer $986$'dır. Her değer $1000$'e bölünürse değerler $-0.986$ ile $0.917$ arasına gelir.

Hoca bunun bir başka biçimini de anlattı: bazen sondaki sıfırlar doğrudan atılabilir. Ev fiyatları hep milyonlarca lira düzeyindeyse ve son üç basamak genelde sıfırsa, çok nadir görülen küsurat milyonun yanında önemsizdir; bütün değerler bine bölünüp küçültülebilir. Bunun yararı bellekten tasarruf etmek ve algoritmanın çok büyük sayılarla uğraşmamasıdır; örneğin long integer gibi büyük bir tür kullanmak zorunda kalınmaz.

> **Ek bilgi (derste anlatılmadı):** Ondalık ölçeklemenin genel formülü büyük olasılıkla $v_i'=\frac{v_i}{10^j}$ biçimindedir; $j$, $\max(|v_i'|)<1$ olmasını sağlayan en küçük tam sayıdır. Örnekte $j=3$'tür.

## 7. Ayrıklaştırma

### 7.1 Kavram

Ayrıklaştırmada (discretization) elde sürekli (continuous) bir öznitelik vardır; örneğin yaş (24.2 gibi) ya da insanların girdiği kilo (56.35 gibi). Bu değer kategorik bir değere çevrilmek istenebilir.

**Soru:** Aralıkları belirlerken neye bakmak mantıklıdır? **Cevap:** Bir öğrenci aralıkların eşit olmasını önerdi. Hoca bunun yanında verideki frekansa bakmanın da anlamlı olup olmadığını sordu: $0$-$10$, $10$-$20$ diye mi bölmeli, yoksa $0$-$10$ arasında 5, $10$-$20$ arasında 30, $20$-$30$ arasında 100 kişi olduğuna mı bakmalı? Cevap probleme göre değişir; dağılıma bakmak gerekebilir de, gerekmeyebilir de.

Aralıkları genellikle insanlar belirler. Örneğin kilo değerleri zayıf, normal ve obez diye üç gruba ayrılacaksa, vücut kitle indeksi hesaplanıp eşikler konur ve her değer düştüğü gruba otomatik olarak çevrilir.

### 7.2 Denetimli ve denetimsiz ayrıklaştırma

Hoca önce denetimli (supervised) ve denetimsiz (unsupervised) kavramlarını hatırlattı. Denetimli, "gözetimli" demektir; başında bir gözetmen (supervisor) varmış gibi düşünülebilir. Dersin başında yöntemler tahmin edici (predictive) ve tanımlayıcı (descriptive) diye ikiye ayrılmıştı. Verinin etiketi varsa tahmin edici yöntemler kullanılır; sınıflandırma gibi etiketli veriyle çalışan yöntemler denetimli, kümeleme gibi tanımlayıcı yöntemler denetimsiz olarak geçer.

Slayta göre (ekrandan, 00:45:00), sınıflandırma için ayrıklaştırma yöntemlerindeki temel ayrım sınıf bilgisinin kullanılıp kullanılmadığıdır:

- Denetimsiz ayrıklaştırma (sınıf bilgisi kullanılmaz; görece basit yaklaşımlar):
  - Binning (kutulara ayırma)
  - Kümeleme analizi (clustering analysis)
- Denetimli ayrıklaştırma:
  - Sınıflandırma (örneğin karar ağacı analizi)
  - Korelasyon (örneğin $\chi^2$) analizi

Hoca iki yaklaşımı şöyle örnekledi. Son amaç sınıflandırma olsun ve sürekli veri ayrık değerlere çevrilmek istensin. Denetimli ayrıklaştırmada örneğin bir karar ağacıyla hangi değerin hangi aralığa düştüğüne, sınıf etiketine bakılarak aralıklar belirlenebilir. Denetimsiz ayrıklaştırmada kümeleme yapılır: sürekli değerler örneğin 3 kümeye ayrılır; küme 1, küme 2, küme 3'ün değerlerinin minimum ve maksimumları aralıkları verir. Böylece eşik elle belirlenmeden ayırma yapılır. Hoca bu yolun pek kullanılmadığını söyledi: müdahale imkânı azdır ve veride hâlâ gürültü varsa saçma sonuçlar çıkabilir.

### 7.3 Binning: eşit frekans ve eşit genişlik

Bir önceki derste görülen kutulara ayırma (binning) da bir ayrıklaştırma yöntemidir. Öznitelik değerleri iki biçimde kutulara bölünebilir:

- Eşit frekans (equal frequency): değerler sıralanır ve her kutuya aynı sayıda eleman konur. 12 eleman 3 kutuya ayrılacaksa her kutuya 4 eleman düşer.
- Eşit genişlik (equal width): minimum ile maksimum arası eşit aralıklara bölünür. Değerler $0$ ile $30$ arasındaysa ve 3 kutu isteniyorsa $0$-$10$, $10$-$20$, $20$-$30$ birer kutu olur.

**Soru:** Yaşın $0$-$18$, $18$-$25$, $25$-$35$, $35$-$50$ diye bölünmesi hangisine örnektir? **Cevap:** Hocaya göre eşit genişliğe daha yakın bir örnektir. Aralıklar gerçekte eşit değildir (onar onar gitmez), ama sınırlar insan tarafından konmuştur ve veri tabanında her aralıkta kaç kişi olduğu sayılmamıştır; yani frekansa göre bölünmemiştir.

## 8. Ön İşlemede Çalışma Düzeni

**Soru:** Bu temizleme ve dönüştürme işlemleri nerede yapılır, doğrudan veri tabanının üstünde mi? **Cevap:** Hayır. Hoca bunun ön işlemenin en büyük sıkıntılarından biri olduğunu söyledi. Ön işlemede tek bir adım yoktur; bu yüzden veri çekildikten sonra orijinali mutlaka bir yerde saklanmalıdır.

Hoca yaşanmış bir sorunu anlattı: bir çalışmada eksik değerler ortalama değerle değiştirilmiş, sonra üzerinde bir sürü işlem yapılıp sonuçlar elde edilmiş. Fakat sonradan hangi değerlerin değiştirildiği ve ortalamanın kaç olduğu bilinmediği için, algoritmanın eksik değerlerden ne kadar etkilendiği de hesaplanamamış.

> **Hocanın vurgusu:** Ön işlemeler hiçbir zaman verinin aslı üzerinde doğrudan yapılmaz. Ön işlemede birden çok adım olduğu için adım adım ve kayıt tutarak çalışmak gerekir; projelerde buna dikkat edilmelidir.

Bölümün kapanışındaki özet slaytı (ekrandan, 00:50:00) ön işlemenin bütün başlıklarını bir arada veriyordu: veri kalitesi (doğruluk, tamlık, tutarlılık, güncellik, inanılırlık, yorumlanabilirlik); veri temizleme (eksik/gürültülü değerler, aykırı değerler); birden çok kaynaktan bütünleştirme (varlık tanımlama problemi, gereksizlikleri kaldırma, tutarsızlıkları bulma); dönüştürme ve ayrıklaştırma (normalizasyon, kavram hiyerarşisi oluşturma); veri indirgeme (boyut indirgeme, sayı indirgeme).

## Örnek Sorular

### Soru 1: Ki-kare hesabı

(ekrandan, 00:25:00) LikeScienceFiction ve PlayChess öznitelikleri için gözlenen frekanslar şöyledir: bilim kurgu seven ve satranç oynayan 250, bilim kurgu seven ve satranç oynamayan 200, bilim kurgu sevmeyen ve satranç oynayan 50, bilim kurgu sevmeyen ve satranç oynamayan 1000. Beklenen frekansları ve $\chi^2$ değerini hesaplayın; iki öznitelik ilişkili mi?

**Çözüm (derste verildi):** Satır toplamları 450 ve 1050, sütun toplamları 300 ve 1200, $n=1500$. Beklenen değerler $e=\frac{\text{satır toplamı}\times\text{sütun toplamı}}{n}$ ile $90$, $360$, $210$, $840$ bulunur. $\chi^2=\frac{160^2}{90}+\frac{(-160)^2}{210}+\frac{(-160)^2}{360}+\frac{160^2}{840}=507.93$. Değer büyük olduğu için iki öznitelik ilişkilidir.

### Soru 2: Kovaryans ile ilişki yönü

(derste sözlü, 00:16:04) İki hisse senedinin beş zamandaki değerleri verilmiştir. $B$: $5, 8, 10, 11, 14$. Kovaryansı $Cov(A,B)=E(A\cdot B)-\bar{A}\bar{B}$ ile hesaplayın ve iki hissenin birlikte mi, ters yönde mi hareket ettiğini yorumlayın.

<!-- BELİRSİZ: A'nın değerleri altyazıda tam duyulmuyor (2, 3, 5, 4 ve beşinci değer). Slayt karelerde yok. -->

**Çözüm (derste verildi):** Hoca sonucu $4.88$ olarak okudu; sonuç pozitif ve sıfırdan belirgin biçimde uzak olduğu için iki hisse birlikte artma eğilimindedir. Python ile kontrol: $A=(2,3,5,4,7)$ alınırsa $\bar{A}=4.2$, $\bar{B}=9.6$, $E(A\cdot B)=\frac{226}{5}=45.2$, $Cov=45.2-40.32=4.88$ olur; $A$'nın beşinci değeri $6$ ise $Cov=42.4-38.4=4$ çıkar.

### Soru 3: Z-skor normalizasyonu

(ekrandan, 00:40:00) Gelir özniteliğinin ortalaması 54.000 dolar, standart sapması 16.000 dolardır. 73.600 dolarlık gelirin z-skor normalizasyonuyla yeni değeri nedir?

**Çözüm (slaytta verildi):** $v'=\frac{73600-54000}{16000}=1.225$.

### Soru 4: Ki-karede bölmenin anlamı

(derste sözlü, 00:27:42) $\chi^2$ formülünde $(o_{ij}-e_{ij})^2$ neden $e_{ij}$'ye bölünür?

**Çözüm (derste verildi):** Normalize etmek için. Sayılar birbirinden çok farklı olduğunda ve veri büyük olduğunda kare farklar çok büyük çıkabilir; beklenen değere bölmek her hücrenin katkısını ölçeklendirir.

### Soru 5: Z-skor ve min-max farkı

(derste sözlü, 00:38:20) Z-skor normalizasyonu min-max normalizasyonuna göre ne sağlar?

**Çözüm (derste verildi):** Gerçek minimum ve maksimum bilinmediğinde kullanılabilir. Test aşamasında eğitim verisindeki minimumdan küçük (ya da maksimumdan büyük) değer gelebilir; min-max bu değerleri sınırda keser (örneğin yetişkin verisinde 18 yaş $0$'a eşlendiyse daha küçük bütün yaşlar $0$ olur). Dağılıma güveniliyorsa z-skor tercih edilir.

### Soru 6: Yaş aralıkları

(derste sözlü, 00:48:57) Yaşın $0$-$18$, $18$-$25$, $25$-$35$, $35$-$50$ diye bölünmesi eşit frekanslı mı, eşit genişlikli binning'e mi daha yakındır?

**Çözüm (derste verildi):** Eşit genişliğe daha yakındır. Aralıklar insan tarafından belirlenmiştir ve kutulardaki kayıt sayısına bakılmamıştır; aralıklar tam eşit olmasa da frekansa göre bölme yapılmamıştır.

## Dersin Toparlaması

Bu derste veri ön işlemenin temizlemeden sonraki adımları işlendi. Temizleme bir süreç olarak ele alındı: uyumsuzlukların metadata, kurallar ve ticari araçlarla bulunması. Ardından farklı kaynaklardan gelen verinin bütünleştirilmesi ve bu sırada ortaya çıkan gereksiz özniteliklerin korelasyon analiziyle bulunması anlatıldı. Sayısal öznitelikler için kovaryans ve korelasyon katsayısı, nominal öznitelikler için $\chi^2$ testi görüldü; bilim kurgu ve satranç örneğinde $\chi^2=507.93$ bulunarak iki özniteliğin ilişkili olduğu gösterildi.

Dersin ikinci kısmında veri dönüştürme ele alındı: min-max, z-skor ve ondalık ölçekleme ile normalizasyon, ardından sürekli özniteliklerin ayrıklaştırılması (denetimli ve denetimsiz yöntemler, eşit frekanslı ve eşit genişlikli binning). Hoca, bütün bu adımların verinin bir kopyası üzerinde, adım adım yapılması gerektiğini vurguladı. Bölümün özet slaytına göre ön işlemenin kalan başlığı veri indirgemedir (boyut ve sayı indirgeme).

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
