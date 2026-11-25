# Ders 17 Genişletilmiş Notu: Algoritmaya Giriş ve Akış Diyagramları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Neden algoritma?
- 2. Bilgisayar için bilgi: tanımlayıcı ve buyurucu bilgi
- 3. Algoritmanın tanımı
- 4. Algoritma kelimesinin kökeni
- 5. Tanımdan direktife: Newton'ın karekök algoritması
- 6. Algoritmanın özellikleri
- 7. Algoritma tasarımı: Polya'nın dört adımı
- 8. Sonucu değerlendirmek: algoritma analizi
- 9. Algoritmayı ifade etmenin yolları
- 10. Akış diyagramı bileşenleri
- 11. Sözde kod ve yapısal programlama
- 12. Akış diyagramı örnekleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Neden algoritma?

Dersin ilk haftalarında bilgisayar mühendisliğinin temelleri, sayı sistemleri, bilgisayar mimarisi, bellek organizasyonu ve işlemcinin çalışması işlenmişti. Bu dersle birlikte asıl konulara geçiliyor: önce algoritma kavramı, sonra algoritmaların akış diyagramlarıyla nasıl ifade edileceği (ekrandan, 00:10:00).

Hoca, algoritma kavramının hem eğitim hem iş hayatında yapılacak bütün çalışmaların "kalbinde" yer alacağını söyleyerek başlıyor. Algoritmik düşünme, slayttan ya da kitaptan okuyarak öğretilebilecek bir şey değildir. Önemli olan çok alıştırma yapmak, problemlere algoritmik çözümler üretmek ve aynı probleme farklı yaklaşımlarla çözüm geliştirmeye çalışmaktır. Bu yapıldıkça zamanla daha iyi algoritmalar ve daha iyi tasarımlar ortaya çıkar.

> **Hocanın vurgusu:** Algoritmik düşünme ancak bol alıştırmayla, farklı problemlere farklı çözümler üreterek gelişir.

## 2. Bilgisayar için bilgi: tanımlayıcı ve buyurucu bilgi

### 2.1 Tanımlayıcı bilgi

İnsanlar beyinleriyle, düşünerek ya da gözlem yaparak gerçeklere ve doğrulara ulaşabilir, bunları dille, resimle ya da başka yollarla ifade edebilir. Anlayabildiğimiz, algılayabildiğimiz ve çıkarımla elde edebildiğimiz bu tür bilgilere **tanımlayıcı bilgi** (declarative knowledge) denir (ekrandan, 00:15:00). "Su belirli sıcaklıklar arasında sıvıdır" ya da "şu kişi bu kişiden kısadır" gibi "bu böyledir" biçimindeki ifadeler tanımlayıcı bilgidir.

### 2.2 Bilgisayar bunları bilemez

Bilgisayar, mimarisi ve çalışma yapısı gereği bu gerçekleri bilemez. Bir sınıfta tahtayı silmek isteyen insan bunun nasıl yapılacağını bilir ve adım adım anlatmaya ihtiyaç duymaz; bilgisayar için böyle bir şey söz konusu değildir. Bilgisayarın özünde bir işlemci ve onun tanımlı bir komut kümesi vardır. İşlemci bu komut kümesindeki eylemleri çok yüksek hızda ve hatasız çalıştırabilir. Öyleyse tanımladığımız bilgileri, belirli bir sonucu elde etmek üzere, kesin, değişmez ve yanlış anlaşılamaz tanımlar halinde ifade etmemiz gerekir.

### 2.3 Buyurucu bilgi

Bilgiyi komutlar ya da buyruklar halinde tanımladığımızda buna **buyurucu bilgi** (imperative knowledge) denir. Komutlardan oluşan bir eylem kümesini bilgisayarda işletebilir ve sonucunu alabiliriz.

Hoca bunu sınıfa yumurta pişirmeyi sorarak somutlaştırdı. Bir öğrenci şöyle anlattı: önce tavayı alıp içine yağ koyuyoruz, altını açıp yağın kızmasını bekliyoruz; sonra yumurtaları bir kaba kırıp istersek tuz ekleyerek karıştırıyoruz; yağ kızınca yumurtayı döküp pişmesini bekliyoruz. Hocanın değerlendirmesi:

- "Birinci adım" denilen yerde aslında dört-beş ayrı iş sayıldı (tavayı al, yağı koy, altını aç, kızmasını bekle). Bunlar ayrı adımlardır.
- Yumurtanın nasıl kırılacağı söylenmedi; kabuklarıyla mı tavaya atılacak?
- Tavanın nasıl olacağı, ateşin ne kadar açılacağı, yağ miktarı belirsiz kaldı.
- "Pişene kadar" denildi, ama pişmenin nasıl anlaşılacağı, yani durma noktası tanımlanmadı: kapkara olana kadar mı, sıvı kalacak mı?

Yemek tarifleri birer buyurucu bilgidir, hatta birer algoritmadır; ama herkesin aynı şeyi anlaması için adımların çok düzgün ve kesin tanımlanması, durma noktasının da belirlenmesi gerekir. Özetle bir yanda deklarasyonlar, bir yanda buyruklar vardır; bilgisayarlı hesaplamanın özünde deklarasyonları buyruklara dönüştürmek yatar.

## 3. Algoritmanın tanımı

Bu dönüşümün ifadesine **algoritma** denir. Hoca aynı kavramı üç farklı cümleyle tanımladı (ekrandan, 00:20:00):

1. Algoritma, bir **problemi** çözmek için takip edilecek, **sonlu sayıda adımdan** oluşan çözüm akışının ifadesidir. Burada iki anahtar nokta vardır: mutlaka bir problem olmalıdır ve adımlar sonlu olmalıdır; sonsuza kadar beklemek ya da çalışmak tanımlı olmamalıdır (yumurta sonsuza kadar pişirilmez).
2. Algoritma, bir problemin mantıksal çözümünün adım adım nasıl gerçekleştirileceğinin tanımlanmasıdır. "Mantıksal" denmesinin nedeni bunun teorik bir çözüm olmasıdır; pratik çözüm, algoritma bir programa dönüştürülüp çalıştırıldığında ortaya çıkar. Algoritmalar sözle ifade edilebilir ("tavayı al, ocağa koy, ateşi aç..."), ya da herkesin aynı anlamı çıkarması için tanımlı sembollerden oluşan akış diyagramlarıyla gösterilebilir.
3. Algoritma, belirli bir problemi çözmek için art arda uygulanacak **kesin** direktiflerden oluşan **sonlu** bir kümedir. Mantıklı ve doğru tüm girdiler için doğrudur ve doğru çıktıyı sonlu bir zamanda üretir. Bunun dışındaki durumlar algoritma değildir.

Sonluluk, doğru girdide doğru çalışmak ve doğru çıktıyı üretmek algoritmanın temel özellikleridir.

### 3.1 Doğal dilin belirsizliği

Sözle ifadenin sorunu, eş anlamlı ya da çok anlamlı kelimeler yüzünden herkesin aynı cümleden aynı anlamı çıkaramamasıdır. Hoca ekrana İngilizce bir cümle yazdı: "Flying planes can be dangerous." Öğrencilerden iki farklı okuma geldi: "uçan uçaklar tehlikeli olabilir" ve "uçak uçurmak tehlikeli olabilir". Birinde tehlikeli olan uçan nesne, ötekinde insanın eylemidir. Türkçede de virgülün yeri anlamı değiştirebilir ("oku baban gibi" türü cümleler).

Bu yüzden her bakanın aynı anlamı çıkaracağı bir gösterime ihtiyaç vardır: önceden tanımlı, anlamı belli bir sembol kümesiyle oluşturulan görsel bir dil. Buna **akış diyagramı** denir.

## 4. Algoritma kelimesinin kökeni

"Algoritma" kelimesinin kökeni bir kişiye dayanır (ekrandan, 00:25:00):

- Ebû Ca'fer Muhammed bin Mûsâ el-Hârizmî. Hoca adın baş kısmının farklı versiyonları olduğunu, kesin olan kısmın "el-Hârizmî" olduğunu belirtti.
- 780 yılında Harezm'de doğmuş (slayta göre Horasan, bugün Özbekistan toprakları), 850 yılında Bağdat'ta ölmüş.
- Pers gökbilimci ve matematikçi; hayatını büyük ölçüde Bağdat'ta geçirmiş. O dönemde fizik, kimya, bilgisayar bilimi gibi ayrımlar yoktu; gök cisimlerinin hareketlerini ve konumlarını matematikle hesaplamaya çalışanlar, matematiğin o güne kadar bilinmeyen özelliklerini de keşfediyordu. Bu yüzden bu tür çalışmalar yapan herkes "gökbilimci ve matematikçi" diye anılır.
- 825 yılında (826 diyenler de var) Arapça bir kitap yazdı: «Hisab al-jabr w'al-muqabala», slayttaki karşılığıyla "Hint rakamları ile hesap". Slayttaki görsel, hocanın Arapça bilen birine doğrulattığına göre kitabın ilk sayfasıdır.
- Bilimin merkezi Batı'ya kayınca kitap 1300'lerde Latinceye çevrildi: "Algoritmi de numero Indorum" (Hint rakamlarıyla hesaplama). "Algoritmi" kelimesi el-Hârizmî'nin adından, "algebra" (cebir) da "al-jabr"dan gelir.

Hoca, bazı kaynaklarda kelimenin antik Yunancadan geldiğinin iddia edildiğini, bunun yanlış olduğunu söyledi. Kökenleri bilmek ve tarihçeye hakim olmak bir erdemdir.

> **Ders sonrası not:** Hoca ve slayt cebir kitabı ("Hisab al-jabr w'al-muqabala") ile Hint rakamlarıyla hesap kitabını tek eser gibi anlattı. Büyük olasılıkla bunlar el-Hârizmî'nin iki ayrı eseridir: cebir kitabı "algebra" kelimesinin, Hint rakamlarıyla hesap üzerine olan eserin Latince çevirisi "Algoritmi de numero Indorum" ise "algoritma" kelimesinin kaynağıdır. Bu çevirinin tarihi de büyük olasılıkla 1300'lerden daha eskidir (12. yüzyıl).

## 5. Tanımdan direktife: Newton'ın karekök algoritması

### 5.1 Deklarasyon

Deklaratif bilgiyi imperatif bilgiye çevirme sürecine algoritma oluşturma denir. Örnek olarak karekök alma kullanılır (ekrandan, 00:35:00). Karekökün en basit deklarasyonu:

$$y \cdot y = x$$

Burada $x$ girdi, $y$ çıktıdır: çıktının karesi girdiye eşittir. Bu, resmi bir tanımdır. Ama bilgisayara "bana öyle bir $y$ bul ki $y \cdot y = x$ olsun" diyemeyiz; bilgisayar bunu anlamaz. Elinde yalnız toplama, çıkarma, belleğe yazma, bellekten okuma, büyüktür/küçüktür gibi temel işlemler vardır. Yumurta kırmayı adım adım anlatmak gerektiği gibi, karekökü de adım adım tanımlamak gerekir.

### 5.2 Algoritma

Slayttaki Newton kök alma algoritması (yakınsama yöntemi) şöyledir (ekrandan, 00:35:00):

```text
0. BAŞLA.
1. x'i oku.
2. Eşik değeri e'yi oku.
3. Rasgele bir r pozitif tamsayısı oluştur.
4. ( r*r - x ) > e olduğu sürece:
   4.1. r değerini, r ve x/r değerlerinin ortalaması ile güncelle.
5. r değerini yazdır.
6. DUR.
```

Algoritma 0'dan 6'ya yedi adımdan ve bir alt adımdan oluşur; belli bir başlangıcı vardır ve sonlu bir yerde durur.

- **Adım 1:** Kullanıcıdan $x$ alınır. Örnekte $x = 16$.
- **Adım 2:** Eşik değeri (epsilon) okunur. Örnekte $e = 0.001$. Eşik "bu kadar yaklaşsam benim için yeterli" demektir. Eşik tam sıfır verilirse, özellikle irrasyonel köklerde algoritma hiç sonlanmayabilir. Eşik sabit de tanımlanabilirdi; burada kullanıcıdan alınmıştır.
- **Adım 3:** Rastgele bir pozitif tam sayı $r$ üretilir. Bu da aslında ayrı bir algoritmayla çalışan hazır bir fonksiyondur. Örnekte $r = 3$.
- **Adım 4:** $r \cdot r$ ile $x$ arasındaki fark eşikten büyük olduğu sürece 4.1 tekrar tekrar yapılır.
- **Adım 4.1:** $r \leftarrow \dfrac{r + x/r}{2}$. $x/r$ bir orandır; $r$ ile $x/r$'nin ortalaması köke bir adım daha yaklaşan yeni tahmindir.
- **Adım 5-6:** Koşul bozulunca döngüden çıkılır, $r$ yazdırılır ve durulur.

Hoca, 4. adımdaki farkın mutlak değer olması gerektiğini sözlü olarak belirtti; çünkü $r$'nin hangi taraftan seçildiğine göre fark negatif çıkabilir.

### 5.3 Örneğin işletilmesi

Slayttaki tablo (ekrandan, 00:35:00):

| $r$ | $r \cdot r$ | $x/r$ | $(r + x/r)/2$ |
|---|---|---|---|
| 3 | 9 | 16/3 | 4.17 |
| 4.17 | 17.36 | 3.837 | 4.0035 |
| 4.0035 | 16.0277 | 3.997 | 4.000002 |

- **Verilen:** $x = 16$, $e = 0.001$, $r = 3$.
- **1. tur:** $r^2 = 9$; fark $|9 - 16| = 7 > e$. $r \leftarrow (3 + 16/3)/2 \approx 4.17$.
- **2. tur:** $r^2 \approx 17.36$; fark $\approx 1.36 > e$. $r \leftarrow (4.17 + 3.837)/2 \approx 4.0035$.
- **3. tur:** $r^2 \approx 16.02$; fark hâlâ eşikten büyük. $r \leftarrow \approx 4.000002$.
- **Kontrol:** Artık $|r^2 - 16|$ eşikten küçük; 4.1'e girilmez, 5. adıma geçilir.
- **Sonuç:** Ekrana yaklaşık 4.000002 yazdırılır.

Sonuç gerçek kök olan 4 değildir, ama istenen hassasiyetten daha yakındır. Eşik küçültülürse 4.1 daha çok kez çalışır, sonuca ulaşmak uzar ve 4'e daha da yaklaşılır. Bunun da bir sınırı vardır: bellekte 8, 16, 32 bitlik gösterimler ve taşma (overflow) konusunda görüldüğü gibi bilgisayarda erişilebilecek hassasiyet sınırlıdır. Sonuç istenirse virgülden sonra dört basamağa yuvarlanarak 4.0 elde edilebilir.

> **Ders sonrası not:** Slayttaki ara değerler yuvarlanmıştır. Python ile kesin hesaplandığında ikinci güncelleme yaklaşık 4.00333, üçüncü güncelleme yaklaşık 4.0000014 çıkar ($r^2 \approx 16.0267$, $x/r \approx 3.9967$). Algoritmanın sonucu ve tur sayısı değişmez.

> **Ders sonrası not:** Slayttaki koşul $(r \cdot r - x) > e$ biçimindedir. Mutlak değer olmadan $r = 3$ için $9 - 16 = -7$ eşikten küçük olduğundan döngüye hiç girilmez ve 3 yazdırılırdı. Hocanın sözlü belirttiği gibi doğru koşul $|r \cdot r - x| > e$'dir.

Böylece bir deklarasyon (karekökün tanımı), başlangıcı ve sonu belli, her adımı tanımlı bir akışa, yani buyurucu bilgiye dönüştürülmüş olur. Bu akış Newton'un kök alma algoritması olarak bilinir.

## 6. Algoritmanın özellikleri

Hoca, algoritmanın özelliklerini slayt üzerinden tekrar ele aldı:

- **Anlaşılır olmak:** Adımlar, girdiler ve çıktılar net olmalı, her biri tek bir anlam taşımalıdır. Hoca, Newton algoritmasında 4.1 adımını Türkçe cümleyle yazdığını, bunun bazı okuyucular tarafından farklı anlaşılabileceğini, matematiksel ifadeyle ($r \leftarrow (r + x/r)/2$) yazılsaydı herkesin aynı şeyi anlayacağını belirtti.
- **Girdi:** Sıfır ya da daha fazla, iyi tanımlanmış girdi. Rastgele sayı üretme algoritması girdi almak zorunda değildir, ama genellikle girdi olur. "İyi tanımlanmış" demek tanım kümesinin belli olması demektir: örneğin negatif sayının karekökü (imajiner kısım) tanımlı değilse "bu algoritma yalnız pozitif tam sayılarla çalışır, negatifleri garanti etmem" denebilir.
- **Çıktı:** En az bir, iyi tanımlanmış çıktı. Çıktı yoksa yapılan işin sonucu, dolayısıyla anlamı yoktur.
- **Sonlanma:** Belirli bir adımdan sonra durmalı, çalışmasını tamamlamalıdır.
- **Yapılabilirlik:** Mevcut imkanlarla gerçekleştirilebilir olmalıdır. 80 işlemci gerektiren bir algoritma elde 2 işlemci varsa işletilemez; 16 GB RAM varken değişkenleri 18 GB'a sığmayan bir algoritma çalıştırılamaz. Bu durumda başka bir algoritmik çözüm gerekir.
- **Bağımsızlık:** Algoritma programlama ortamından, dilinden ve kodundan bağımsız tanımlanır. Bir algoritma C, Java, Pascal, Python, Ruby, C#, Go gibi bir dilde gerçeklendiğinde buna **program** denir; artık çalışan, somut çıktı üreten haldir. Algoritma teorik bir çözümdür, ama pratikte uygulanabilir olmasını sağlamak tasarımcının sorumluluğudur.

## 7. Algoritma tasarımı: Polya'nın dört adımı

### 7.1 Dört adım

George Polya'ya göre problem çözmenin dört adımı vardır (ekrandan, 00:45:00):

1. **Problemi anlamak:** Çözülmeye çalışılan problem doğru anlaşılmalı ve makul, yani anlaşılır ve açıklanabilir biçimde tanımlanmalıdır. Algoritma tasarımında ilk iş budur.
2. **Çözüm planı oluşturmak:** Düşünerek, önceki deneyimlerden, benzer problemlerin çözümlerinden yararlanarak ya da onları değiştirerek bir çözüm planı ortaya konur. Bu, algoritmayı tasarlamaktır. Bir problem birden fazla yolla çözülebilir.
3. **Planı uygulamak:** Algoritma tanımlı girdi kümesi üzerinde çalıştırılır, yani test edilir. Örneğin pozitif tam sayılarla çalışıyorsa alt ve üst sınırlar dahil farklı değerlerle denenir; doğru ve kararlı çıktı üretip üretmediğine bakılır.
4. **Sonucu değerlendirmek:** Doğru çalışan çözümün ne kadar iyi olduğu değerlendirilir: beklentiyi karşılıyor mu? Ölçüt çalışma hızı, harcanan bellek ya da hızlı geliştirilebilirlik olabilir. Çözüm iyileştirilebilir mi, hedefi daha iyi karşılayan başka bir yol var mı, bunlar araştırılıp karşılaştırılır.

### 7.2 Örnek problem: ön sıradaki en yaşlı öğrenci

Problem tanımı (ekrandan, 00:45:00):

- **Ön koşul:** Ön sırada oturan öğrenciler olmalı.
- **Hedef:** En yaşlı öğrenciyi bulmak.
  - Herkes gerçek doğum gününü verecek.
  - Aynı gün doğanlar aynı yaştadır.
  - Birden fazla en yaşlı varsa herhangi birini bildirmek yeterlidir.

Çevrim içi derste fiziksel bir ön sıra olmadığı için hoca, katılımcı listesinde aynı harfle başlayan yedi öğrenciyi "sanal ön sıra" kabul etti.

### 7.3 Çözüm 1: sırayla sormak

Slayttaki adımlar (ekrandan, 00:50:00):

```text
1. Sol baştan başla.
2. İlk öğrenciye adını ve yaşını sor, tahtaya yaz.
3. Sırada öğrenci olduğu sürece yap:
   3.1. Öğrenciye adını ve yaşını sor.
   3.2. Yaş tahtadakinden büyükse, sil ve yeni bilgiyi yaz.
4. Tahtadaki ismi ve yaşını oku.
```

Hoca bunu canlandırdı: ilk öğrenci 2000 doğumlu, tahtaya yazılır. İkinci öğrenci 2001 doğumlu; daha genç olduğu için geçilir. Üçüncü öğrenci 1999 doğumlu; tahtadaki silinir, yerine bu yazılır. Kalan öğrencilerin hiçbiri 1999'dan önce doğmamışsa sona gelindiğinde tahtada kalan kayıt en yaşlı öğrencidir.

### 7.4 Çözüm 2: eleme turu

Bir öğrencinin önerisi ("herkes yanındakine sorsun") ikinci çözüme götürdü. Slayttaki adımlar (ekrandan, 00:55:00):

```text
0. Başla.
1. Ön sırada birden fazla öğrenci olduğu sürece yap:
   1.1. Öğrencileri soldan sağa ikişerli olacak şekilde grupla.
   1.2. Sonda tek öğrenci kalırsa, onu tut.
   1.3. Her öğrenci çiftinin yaşlarını karşılaştır.
   1.4. Genç olanı ön sıradan kaldır.
2. Kalan öğrencinin adını ve yaşını sor, tahtaya yaz.
```

Slayttaki şekilde 1. turda çiftler karşılaştırılır ve gençler elenir; 2. turda kalanlar yeniden eşleşir; 3. turda son iki kişi karşılaştırılır ve en yaşlı bulunur. Tek kalan öğrenci karşılaştırma yapılmadan bir sonraki tura geçer.

Hoca karşılaştırmaları tek tek saydı: 1. turda 4, 2. turda 2, 3. turda 1 karşılaştırma, toplam 7. Çözüm 1'de de 7 sorgu yapılmıştı. "Ne değişti?" sorusunun cevabı: Çözüm 2'de bir turdaki karşılaştırmalar **aynı anda** (paralel) yapılabilir. Yeterli işlem kapasitesi olduğu kabul edilirse 1. turun 4 karşılaştırması bir sorgu zamanında, 2. turun 2 karşılaştırması bir sorgu zamanında, 3. tur bir sorgu zamanında biter; toplam 3 sorgu zamanı.

> **Ders sonrası not:** Slayttaki şekilde 8 öğrenci vardır ve 4 + 2 + 1 = 7 karşılaştırma bu şekle uyar. Tam 7 öğrenci olsaydı turlar 3 + 2 + 1 = 6 karşılaştırma olurdu; sıralı çözümde de ilk öğrenci karşılaştırmasız yazıldığından $n - 1$ karşılaştırma yeterlidir. Tur sayısı her iki durumda 3'tür.

## 8. Sonucu değerlendirmek: algoritma analizi

### 8.1 "Daha iyi" neye göre?

Hangi çözümün daha "iyi" olduğunu belirlemek her zaman kolay değildir (ekrandan, 01:00:00):

- Kolay uygulanabilir olması istenebilir (çok hızlı kodlanması gerekiyorsa).
- Yalnız belirli bir girdi ya da ortam koşulunda çalışması beklenebilir. Örneğin tek işlemci varsa paralel çalışma mümkün değildir; Çözüm 2 bir şey kazandırmaz, daha basit olan Çözüm 1 tercih edilir.
- Daha hızlı olan daha iyi olabilir: Çözüm 2 sonucu 3 sorgu zamanında, Çözüm 1 ise 7 sorgu zamanında bulur.
- Daha az yer harcayan tercih edilebilir: belleği çok kısıtlı gömülü sistemlerde ve küçük mikroişlemcili kartlarda biraz uzun çalışsa da az değişken tutan çözüm seçilebilir.

Biri daha hızlı, öbürü daha az yer kaplayan olabilir. Hangisinden ne kadar ödün verileceği (trade-off), hangi algoritmanın seçileceğini belirler.

### 8.2 İki çözümün karşılaştırılması

- **Algoritma 1:** Yapılması gereken iş ön sıradaki öğrenci sayısıyla doğru orantılıdır (slaytta 7 yazılı). 14 öğrenci olursa 14 birim zaman gerekir; öğrenci sayısı iki katına çıkınca iş de iki katına çıkar.
- **Algoritma 2:** Çiftlerin sorguları aynı anda yapılabiliyorsa iş, sorgulanan kişi sayısını kaç kez yarıya indirdiğimizle orantılıdır. Her adımda yarıya düşüldüğü için bu, öğrenci sayısının 2 tabanındaki logaritmasıdır (slaytta 3 yazılı): 7 ya da 8 öğrenci için $2^3 = 8$ olduğundan 3 tur. Öğrenci sayısı iki katına çıkarsa süre yalnız bir karşılaştırma turu artar; 16 öğrenci için Algoritma 1 16 iş yaparken Algoritma 2 4 tur yapar.

### 8.3 Sayısal karşılaştırma

Her karşılaştırmanın (yaşı sorup yazmanın) 5 saniye sürdüğü varsayılır:

| Öğrenci sayısı $n$ | Algoritma 1: $5n$ | Algoritma 2: $5\log_2 n$ |
|---|---|---|
| 100 | 500 s | yaklaşık 33 s |
| 200 | 1000 s | yaklaşık 38 s |
| 400 | 2000 s | yaklaşık 43 s |
| 1 000 000 | 5 000 000 s | yaklaşık 100 s |

Hoca 100 öğrenci için yuvarlayarak "yaklaşık 35 saniye", 200 ve 400 için "her seferinde yaklaşık 5 saniye daha" dedi; değerler Python ile kontrol edildi. Algoritma 1'in süresi düz bir çizgi gibi doğrusal artar; Algoritma 2'nin süresi logaritmik artar ve girdi büyüdükçe makas açılır. Hız hedefleniyorsa, özellikle iş sayısı büyüdükçe, ikinci yaklaşım daha performanslıdır ve seçilir.

## 9. Algoritmayı ifade etmenin yolları

Aradan sonra hoca ilk saati özetledi: algoritmanın tanımı, tarihçesi, algoritmik problem çözümünün adımları, deklaratif ve imperatif bilgi. Ardından algoritmaların herkesin aynı şekilde anlayacağı biçimde nasıl ifade edileceğine geçti (ekrandan, 01:20:00):

- **Düz yazı (etken ve buyuran cümleler):** Doğal dil yüzünden okuyanlar farklı anlayıp farklı yorumlayabilir. Yemek tariflerinde ölçülerin ya da işlem sırasının yanlış anlaşılması buna örnektir.
- **Sözde kod (pseudocode):** Günümüzde birçok kaynakta, özellikle ayrıntılardan kaçınarak algoritma ifade etmek için sıkça kullanılır.
- **Akış diyagramı:** Algoritmik akışı en temiz biçimde gösterir. Görsel bir dil olduğu ve evrensel semboller kullandığı için diyagrama bakan herkes aynı şeyi anlar ve aynı çıktıyı üretir.

## 10. Akış diyagramı bileşenleri

### 10.1 Genel bakış

Akış diyagramları iki eleman grubundan oluşur: geometrik şekillerden oluşan **akış diyagramı elemanları** ve elemanları birbirine bağlayan **bağlantılar** (oklar). Oklar karmaşıklaştığında takibi kolaylaştırmak için yönlendiriciler (bağlayıcılar) kullanılır.

Bileşen listesi (ekrandan, 01:25:00):

- Başla - Bitir (Start - Stop)
- Okuma (Read / Inputs) ve Çıktı / Yazma
- Bağlantılar (Connections): oklar, çemberler
- İfadeler / İşlemler (Statements / Process)
- Kararlar (Decisions): if, case/switch, ...
- Döngüler (Loops): for, while, do while, ...

Döngülerde adım sayısı belli olabilir, bir koşul doğru olduğu sürece blok tekrarlanabilir ya da blok önce bir kez çalıştırılıp kontrol sonda yapılabilir (önce yap, sonra kontrol et).

### 10.2 Başla ve bitir

Başlangıç noktası, üstü ve altı düz, kenarları yuvarlatılmış (parantez kenarlı) bir dörtgenle gösterilir; bitiş noktası da aynı sembolle gösterilir. Elle çizerken elips gibi çizilmesi sorun değildir. İçine "başla/bitir" ya da "start/stop" yazılabilir; ikisi de doğrudur.

- Her algoritmanın mutlaka **bir** başlangıcı olmalıdır. Başlangıcı olmayan algoritma olmaz; birden fazla başlangıç da yanlıştır.
- Algoritma mutlaka bir yerde sonlanmalıdır; sonu yoksa algoritma değildir.

### 10.3 Girdi

Girdi, kullanıcıdan okuma, yani belli değişkenlerin değerlerinin kullanıcıdan istenmesidir. Sembol, sol üst köşesi çentikli bir dikdörtgendir (ekrandan, 01:35:00).

Hoca sembolün neye benzediğini sordu; öğrencilerden "SIM kart" ve "delikli kart" cevapları geldi. Doğru cevap **delikli karttır** (punch card). Eski merkezi bilgisayarlarda veri delikli kartlarla girilirdi ve kartın sol üst köşesi, okuyucuya ters takılmaması için çentikliydi (SIM kartın ters takılmaması mantığı). Bu sembol, tarihe bir selamdır.

- Sembolün içine okunacak değişkenler virgülle ayrılarak yazılır (örneğin `N, M, A(N)`).
- Algoritma başladığında genellikle önce değerler okunur ve ilk değer atamaları yapılır, sonra işlemlere geçilir.
- Dizi okuma için iki seçenek vardır: for döngüsü içinde girdi kullanmak ya da `A(N)` gösterimini kullanmak. `A(N)`'den önce `N` okunmalıdır.

Hoca diziyi kısaca tanıttı: aynı türden bilgileri bir arada tutup aynı değişken adıyla yalnız indisleriyle eriştiğimiz veri yapısıdır. Genellikle diziler büyük harfle, tekil değişkenler küçük harfle yazılır (zorunlu değil). Beş gözlü bir `A` dizisinin indisleri 0'dan 4'e gider; içinde 7, 2, 5, 8, 9 gibi değerler olabilir ve `A[2]` ile 2 numaralı gözdeki değere erişilir.

<!-- BELİRSİZ: Hoca örnek dizide değerleri gözlere yazarken önce A2'nin 7 olduğunu, sonra "0, 1, 2, işte 7 değerine erişmiş oluyorum" dedi; çizimin karesi okunmadığı için değerlerin hangi gözlere yazıldığı kesin değil. -->

**Değer atamadan kullanmama kuralı:** Bir değişken, değeri atanmadan kullanılamaz. Bütün değişkenleri en başta tanımlamak gerekmez, ilk kullanıldıkları yerde de tanımlanabilirler; ama ilk değer ataması bir yerde mutlaka gösterilmelidir. Örneğin `N` ve `M` okunduktan sonra bir işlem kutusunda `K = N + M` yazmak doğrudur; çünkü bilinen iki değerin toplamı yeni değişkene atanmaktadır ve ayrıca `K = 0` demeye gerek yoktur. Değeri bilinmeyen bir değişken ise önce bir değer almalıdır.

Bazı kaynaklarda girdi için paralelkenar kullanılır (klavyeye benzetenler vardır); bu derste kullanılmaz.

### 10.4 Çıktı

Çıktı için alt kenarı dalgalı bir dikdörtgen kullanılır (ekrandan, 01:35:00). Dalgalı kenar kağıdı temsil eder: monitörün olmadığı ana bilgisayar döneminde girdiler delikli kartlarla okunur, çıktılar yazıcıdan kağıda basılırdı. Bu da tarihe bir selamdır.

Bazı kaynaklarda ekrana çıktı için bir tarafı sivri, bir tarafı yuvarlak bir sembol görülür. Bu sembol tüplü (katot ışınlı) monitörün yandan görünüşüne benzer: arkada bir elektron tabancası, önde fosfor kaplı ekran ve huni biçimli gövde. Tabanca ekranı saniyede en az 25 kare tarayacak hızla matris gibi tarar ve görüntüyü oluşturur. Sembolün ön kısmı ekranı, uzatılmış kısmı içine yazı yazılabilsin diye televizyonun arkasını temsil eder. Bu derste bu sembol ve paralelkenar kullanılmaz; girdi ve çıktı için delikli kart ve kağıt sembolleri kullanılır.

### 10.5 Bağlantılar

- Oklar her zaman iki elemanı birbirine bağlar ve mutlaka **yönlü** olmalıdır.
- Oklar eğri büğrü değil, düz ve köşeli (L biçiminde) çizilmelidir; bu daha okunaklı ve temiz diyagram sağlar.
- **Çemberler (bağlayıcılar):** İç içe döngüler ya da karmaşık kontroller yüzünden yer kalmadığında veya okların takibi zorlaştığında, ok numaralı bir çembere bağlanır ve akış aynı numaralı çemberden devam eder.

Hocanın örneği: bir sayfada Start çizilip `x` okunduktan sonra yer kalmadı; ok "1" numaralı çembere bağlandı. Sonraki sayfada "1" numaralı çemberden başlanıp $x \cdot x$ ekrana yazdırıldı ve Stop ile bitirildi.

### 10.6 İşlem

Her türlü ifade, atama, aritmetik ya da lojik işlem dikdörtgen içinde gösterilir. Bir kutuda en az bir işlem olur; yer tasarrufu için mantıksal bir blok halinde birden çok işlem de yazılabilir (örneğin `a = a + 1` ve `x = a + 5` aynı kutuda). Her işleme ayrı kutu çizmek diyagramı gereksiz büyütür.

İşlemlerde hiçbir programlama diline özgü sözdizimi, operatör ya da değişken yapısı kullanılmaz; algoritma dilden bağımsız olmalıdır. `A = A + 1` doğrudur; C'deki gibi `A++` yazmak kabul edilmez.

> **Hocanın vurgusu:** Akış diyagramında dile bağımlı ifade kullanmayın; `x++` değil `x = x + 1` yazın.

### 10.7 Karar (if)

Koşula göre farklı davranış gerektiğinde karar mekanizması kullanılır (ekrandan, 01:40:00). Akış bir oktan gelir ve altıgen biçimli karar sembolüne ulaşır. İçindeki ifade bir lojik işlemdir ve sonucu 0 ya da 1 (yanlış ya da doğru) olmalıdır.

Örnek: `A = B` kararı. $A = 3$, $B = 8$ ise eşit değildir, sonuç 0 (yanlış) olur ve F kolundan devam edilir. $A = 3$, $B = 3$ ise sonuç 1 (doğru) olur ve T kolundan devam edilir (ekrandan, 02:00:00). Slaytta iki kolda da `A = A + 1` yazılıdır; hoca farklı işlem yapıldığını göstermek için birini `A = A + 2` yaptı. Kollarda birden fazla işlem, iç içe döngüler ya da başka kararlar da yer alabilir.

Kurallar:

- Her zaman T (doğru) ve F (yanlış) kolları işaretlenmelidir. D/Y de kullanılabilir, ama bu derste T/F tercih edilir.
- Mümkünse bir diyagramdaki bütün kararlarda T kolu hep aynı taraftan (örneğin hep sağdan) çıkmalıdır; bu daha okunaklı bir akış sağlar. Yer darlığında istisna olabilir.
- Her if ifadesinde mutlaka doğru (T) kolu olmalıdır; yanlış (F) kolu isteğe bağlıdır.

Örnek: `x < 0` kararı; doğruysa `x` $-1$ ile çarpılarak mutlak değeri alınır, yanlışsa hiçbir şey yapılmadan devam edilir. Bu doğrudur. Ama tersi, yani T kolu boşken yalnız F koluna işlem yazmak olmaması gereken bir durumdur. Böyle bir şey gerekiyorsa koşulun tersi alınır: `x < 0` yerine `x >= 0` yazılır; böylece işlem otomatik olarak T koluna geçer.

### 10.8 For döngüsü

Adım sayısı, yani bloğun kaç kez çalışacağı belliyse **for döngüsü** kullanılır (ekrandan, 01:45:00). Sembol üç parçalı bir dikdörtgendir:

- İlk koşul (başlangıç): örneğin $j \leftarrow 1$ (atama oku ya da `j = 1`, ikisi de olur).
- Son koşul (durma): örneğin $N$.
- Adım (+/-): örneğin 1.

Döngü gövdesindeki işlemler (tek olmak zorunda değil) yapılır, akış döngünün başına döner, döngü değişkeni adım kadar artırılır ve durma koşulu kontrol edilir. Bazı kaynaklarda for döngüsü bir karar sembolü içine "j = 1, N, 1" yazılarak gösterilir; bu, karar sembolünün anlamına aykırı düştüğü için bu derste üç bölmeli dikdörtgen tercih edilir.

**İşletme örneği ($N = 5$, $j = 1$'den 5'e adım 1):**

- $j = 1, 2, 3, 4, 5$ değerleri için blok çalışır (5 kez).
- Sonra $j$ 6 olur; 6 > 5 olduğu için döngüden çıkılır.
- Döngüden sonra $j$'nin değeri 6'dır. Değer artırıldıktan sonra koşul bozulup çıkıldığına dikkat edilmelidir.

Bu değişkene indis, indeks ya da döngü değişkeni denir; döngünün adımlarını sayar.

**Adım 2 ile:** $j = 1$ için çalışır, $j = 3$ için çalışır, $j = 5$ için çalışır (5 ≤ 5); $j = 7$ olunca 7 > 5 olduğu için çıkılır. Döngüden sonra $j = 7$'dir.

**Negatif adım:** $j = N$'den 1'e adım $-1$ ile ($N = 5$) $j$ sırasıyla 5, 4, 3, 2, 1 değerlerini alır; 0 olunca 1'den küçük olduğu için çıkılır. Blok yine 5 kez çalışır.

İndis 0'dan başlatılıyorsa son değer $N - 1$ olmalı ya da "küçüktür $N$" kontrolü yapılmalıdır.

### 10.9 While döngüsü

Bilinmeyen sayıda iterasyona sahip döngüler için **while döngüsü** kullanılır; bir şartın sağlandığı sürece işletilmesi esasına dayanır (ekrandan, 01:50:00). Altıgen içine koşul yazılır, koşul doğruysa gövdeye girilir, gövde bitince akış koşula geri döner.

**Sonsuz döngü örneği:** Önceden $j = 1$, $n = 3$ atanmış; koşul $j < n$, gövde `A = A + 1`. $1 < 3$ doğru, gövde çalışır; $j$ hiç değişmediği için koşul hep doğru kalır ve döngüden çıkılamaz. Çözüm, gövdeye koşulu değiştiren bir işlem eklemektir: `j = j + 1`. Böylece $j = 1$ ve $j = 2$ için gövde çalışır, $j = 3$ olunca $3 < 3$ yanlış olur ve döngüden çıkılır.

> **Hocanın vurgusu:** Koşullu döngülerde karşılaştırma ifadesindeki değişkenin döngü gövdesi içinde mutlaka güncellendiğinden ve döngünün sonlanacak biçimde değiştiğinden emin olun; yoksa sonsuz döngü oluşur.

Güncelleme her adımda birer artırma ya da azaltma olabileceği gibi koşula bağlı farklı artımlar da olabilir.

### 10.10 İç içe döngüler ve değişken adları

Döngüler iç içe kullanılabilir. Hocanın örneği: `i = 1`'den `N`'e bir for döngüsü, içinde `j = i` ataması ve "`j mod 2 = 0` olduğu sürece" (yani `j` çift olduğu sürece) çalışan bir while döngüsü. İçteki `j`'nin de bir şekilde güncellenmesi gerekir.

Döngü indis değişkenlerine (iteratör) genellikle `i` ile başlanır; ikinci döngü `j`, üçüncü `k`, dördüncü `l` olur. `m` ve `n` genellikle eleman sayıları için kullanılır. İç içe üç döngüden fazlası algoritmanın çok karmaşık hale gelmesine yol açar; `i, j, k, l` fazlasıyla yeterlidir. İç içe olmadığı sürece aynı değişken adı başka bir döngüde yeniden kullanılabilir.

## 11. Sözde kod ve yapısal programlama

### 11.1 Üç temel yapı

Hoca bu kısmı "bilginiz olsun diye" ekledi. Yapısal programlamayı öneren Edsger Dijkstra, her algoritmanın yalnız üç yapıyla ifade edilebileceğini söylemiştir:

- **Dizilim (sequence):** Adım adım yazılan bir ya da daha fazla ifade (topla, çarp, böl...).
- **Seçim (selection):** Koşullu dallanma; koşula göre sıfır ya da daha fazla alternatifi yürütür.
- **Döngü (loop):** Bir kod bloğunun tekrar tekrar çalışmasını sağlar.

> **Ders sonrası not:** Hoca bu sonucun ispatını Dijkstra'ya bağladı. Her algoritmanın dizilim, seçim ve döngüyle yazılabileceğini gösteren sonuç genellikle Böhm ve Jacopini'ye (1966) atfedilir; Dijkstra ise yapısal programlamanın savunucusu olarak bilinir.

### 11.2 Sözde kodun yapısı

Slayttaki örnek (ekrandan, 01:55:00):

```text
Algorithm sample (pageNumber)
This algorithm reads a file and prints a report.
  Pre    pageNumber passed by reference
  Post   Report Printed
         pageNumber contains number of pages in report
  Return Number of lines printed
1 loop (not end of file)
  1 read file
  2 if (full page)
    1 increment page number
    2 write page heading
  3 end if
  4 write report line
  5 increment line count
2 end loop
3 return line count
end sample
```

Sözde kodun bir başlık (kafa) kısmı vardır: algoritma başlığı, amacı, koşulları (pre-condition, post-condition) ve çıktısı (return value). Ardından gövde gelir. Gövdede girintili numaralandırma kullanılır (1, 1.1, 1.2, 1.2.1 ...). Bu örnekte 1 numaralı ifade bir döngüdür (dosya sonu gelmediği sürece), 1.2 bir karardır, 1.2.1 ve 1.2.2 kararın içindeki işlemlerdir; böylece dizilim, seçim ve döngünün üçü de görülür.

Sözde kod gösterimleri:

- Atama: `←` ya da `=`.
- Eşitlik kontrolü: tek `=`.
- Seçim: `if şart ... end if` ya da `if ... else ... end if`.
- Döngüler: `while ... do` (koşulu önce kontrol et, doğru olduğu sürece çalıştır), `do ... while` (bloğu çalıştır, koşul doğruysa başa dön), `repeat ... until` (koşul doğru olana kadar çalıştır) ve adım sayısı belli olan `for`. `do while` ile `repeat until` birbirine çok yakındır, biri koşul doğruyken öbürü yanlışken devam eder. Örneğin C'de `repeat until` yoktur; `do ... while` ile koşulun tersi yazılarak aynı iş yapılır.

### 11.3 Eşkenar dörtgen karar sembolünün tarihçesi

Bazı kaynaklarda karar için eşkenar dörtgen kullanılır. Bu derste altıgen tercih edilir: altıgen, içine yazı sığsın diye ortası uzatılmış bir eşkenar dörtgen gibi düşünülebilir.

Hoca "sorumlu değilsiniz" diyerek eşkenar dörtgenin kökenini anlattı. Eskiden bilimsel hesaplamalarda kullanılan FORTRAN dilindeki if yapısının üç sonucu vardı; aritmetik bir fark gibi düşünülebilir. Fark pozitifse bir çıkıştan, negatifse (örneğin $A = 3$, $B = 5$) başka bir çıkıştan, sıfırsa (tam eşitlik) üçüncü bir çıkıştan devam edilirdi. Bir giriş ve üç çıkış (artı, eksi, sıfır) gerektiği için eşkenar dörtgen kullanılmıştı. Günümüzde koşul ya doğru ya yanlış olan ikili dallanma (if-then-else) kullanıldığından bu derste altıgen kullanılır.

<!-- BELİRSİZ: Hoca FORTRAN'ın gerçel sayıları daha yüksek hassasiyetle adreslediğini ve "iki adresi bir araya getirip 8 bit yerine 16 bit" kullandığını söyledi; altyazıdaki bu teknik ayrıntı karışık olduğu için nota alınmadı. -->

## 12. Akış diyagramı örnekleri

Hoca slayta yedi örnek koyduğunu, derste üçünü yapabileceklerini söyledi ve Zoom beyaz tahtasında fareyle çizdi.

### 12.1 Örnek 1: $n$ sayının toplamı ve ortalaması

**Problem:** Kullanıcıdan $n$ adet sayı okunacak, toplamları ve ortalamaları yazdırılacak.

**Tasarım adımları:**

- Önce başlanır: Start. ("Başlamak bitirmenin yarısıdır.")
- Kaç sayı girileceği bilinmeli: `N` okunur.
- Toplam ve ortalama için değişkenler gerekir: `top = 0`, `ort = 0`. Toplam ileride kullanılacağı için ilk değeri atanmalıdır.
- Eleman sayısı belli olduğu için sınırları belli bir döngü kurulur: `i = 1`'den `N`'e adım 1.
- Döngü içinde sayı okunur (`S`, delikli kart sembolü) ve toplama eklenir: `top = top + S`.
- Ortalamanın döngü içinde güncellenmesi gerekmez; ortalama toplam bölü $n$ olduğundan döngü dışında bir kez hesaplanır: `ort = top / N`.
- `top, ort` yazdırılır ve Stop ile durulur.

Beyaz tahtadaki akış (ekrandan, 02:10:00):

```text
START
  |
[N oku]
  |
[top = 0, ort = 0]
  |
[for i = 1 .. N, adım 1] ---> [S oku] ---> [top = top + S] ---+
  |   ^                                                       |
  |   +-------------------------------------------------------+
  | (döngü bitince)
[ort = top / N]
  |
[top, ort yazdır]
  |
STOP
```

Hoca `ort = top/N` kutusunu çizerken şeklin biraz bozuk olduğunu, bunun bir işlem dikdörtgeni olduğunu belirtti. `ort` için baştaki sıfırlama aslında gerekmezdi, çünkü değer döngüden sonra hesaplanıyor; ama ilk değer atamasını unutmamak için garanti olsun diye yapmak iyi bir alışkanlıktır.

**Test ($N = 3$; girdiler 2, 3, 4)** (ekrandan, 02:10:00):

| $i$ | okunan $S$ | `top` | `ort` |
|---|---|---|---|
| 1 | 2 | 2 | 0 |
| 2 | 3 | 5 | 0 |
| 3 | 4 | 9 | 0 |
| 4 | (döngüden çıkılır) | 9 | 0 |

- $i = 4$ olunca $4 > 3$ olduğu için döngüden çıkılır.
- `ort = 9 / 3 = 3`.
- Ekrana 9 ve 3 yazdırılır.

**Uç değer testi ($N = 0$):**

- `top = 0`, `ort = 0` atanır.
- `i = 1`'den 0'a dönülmeye çalışılır; $1 > 0$ olduğundan durma şartı baştan sağlanmıştır, döngü gövdesi hiç çalışmaz.
- `ort = top / N = 0 / 0`: sıfıra bölme hatası.

Tanımlı girdi kümesindeki uç değerler kontrol edilmelidir; tam sayılarda 0 bir uç değerdir. Bir öğrencinin önerdiği gibi bir if eklenir: `N` okunduktan hemen sonra `N > 0` kararı konur. Doğru kolunda toplam ve ortalama hesaplanır; yanlış kolunda "hata" yazdırılır. İki kol birleşir ve akış if'ten çıkıp devam eder. Böylece algoritma $N = 0$ için de doğru davranır.

> **Hocanın vurgusu:** Bir çözüm önerisi oluşturduktan sonra mutlaka girdilerle, özellikle uç değerlerle test edin; bu örnekte $n = 0$ sıfıra bölmeye yol açtı.

### 12.2 Örnek 2: $f(x) = \sum_{x=1}^{n} \frac{1}{x^2}$

**Problem:** Okunan bir $n$ değeri için

$$f = \sum_{x=1}^{n} \frac{1}{x^2}$$

hesaplanıp ekrana yazdırılacak.

**Tasarım adımları:**

- Start, sonra `N` okunur.
- Toplamda $x$ değişkeni 1'den başladığı için `x = 1` atanır; çıktı değişkeni `f` için ilk değer `f = 0` verilir.
- $x$, 1'den $n$'e kadar gideceği için `x <= N` koşullu bir while döngüsü kurulur.
- Sigma toplama demektir: `f = f + 1/(x*x)`.
- Koşulu döngü içinde mutlaka değiştirmek gerekir: `x = x + 1`. İki işlem yer kazanmak için aynı kutuda yazılır. Bu yapılmazsa $x$ hep 1 kalır ve `f = f + 1` sonsuza kadar tekrarlanır. `x++` değil `x = x + 1` yazılır.
- Koşul yanlış olunca `f` yazdırılır ve Stop ile durulur.

Beyaz tahtadaki akış (ekrandan, 02:20:00):

```text
START
  |
[N oku]
  |
[x = 1, f = 0]
  |
<x <= N> --doğru--> [f = f + 1/(x*x), x = x + 1] --+
  |  ^                                              |
  |  +----------------------------------------------+
  | yanlış
[f yazdır]
  |
STOP
```

Bir öğrenci döngüde `x` artırılırken "n eksi bir eklemeli miyiz" diye sordu. **Cevap:** Hayır; $x$ zaten $n$'e kadar gitmeli, gerekli olan koşulu değiştiren `x = x + 1` işlemidir.

Gövde $n$ kez çalışır; koşul ise bir fazla kontrol edilir. Algoritmanın başlangıç ve bitiş noktaları belli, bütün değişkenleri atanmıştır ve sonlandığı görülebilir.

- **$N = 0$ için:** `x = 1`, $1 \le 0$ yanlış; döngüye girilmez ve 0 yazdırılır.
- Teorik çözümde tam sayının sınırları dikkate alınmaz; $n$ çok büyük verildiğinde $x^2$'nin taşması (overflow) bu aşamada düşünülmez.

**Alternatif çözüm:** Sarıyla işaretlenen while bölgesi, adım sayısı (1'den $n$'e) belli olduğu için bir for döngüsüyle de yazılabilir: `x = 1`'den `N`'e adım 1 ve gövdede yalnız `f = f + 1/(x*x)`. For döngüsü $x$'i her adımda kendisi artırdığı için `x = x + 1` ataması gerekmez ve döngü değişkeni doğrudan $x$ olarak kullanılır. Karmaşıklık açısından iki çözüm denktir.

Sonucun ilk birkaç değeri Python ile kontrol edildi: $n = 1$ için 1, $n = 2$ için 1.25, $n = 3$ için yaklaşık 1.3611.

### 12.3 Örnek 3: OBEB (Öklid algoritması)

**Problem:** Okunan iki sayının ($x$, $y$) en büyük ortak böleni (OBEB) bulunacak.

Ortaokulda öğretilen yöntem iki sayıyı asal çarpanlarına ayırıp ortak çarpanlardan sonucu bulmaktır; bu yöntem adım adım buyruklara dönüştürmeye pek uygun değildir. Öklid'in yöntemi ise şunu söyler: kalan sıfır olana kadar $x \bmod y$ işlemini yap ve değerleri kaydır, yani $\text{OBEB}(x, y) = \text{OBEB}(y, x \bmod y)$. Kalan sıfır olduğunda bir önceki değer, yani $y$, OBEB'dir.

**Tasarım adımları:**

- Start, sonra `x, y` okunur (çentikli sembol).
- Kalan için bir değişken: `k = x mod y`.
- Kalan sıfır olmadığı sürece (`k ≠ 0`) döngüde: ikinci sayı birinciye taşınır (`x = y`), kalan ikinciye taşınır (`y = k`) ve kalan yeniden hesaplanır (`k = x mod y`). Döngü koşulundaki `k` gövde içinde güncellenmektedir.
- Kalan 0 olunca döngüden çıkılır. Son kalan 0 olduğu için `k` yazdırılamaz; bir önceki değer `y`'de durduğu için `y` yazdırılır, sonra Stop.

`mod` yerine `%` operatörü de yazılabilir (çoğu ortamda mod alma operatörüdür), ama hoca daha açık olduğu için `x mod y` yazılmasını tercih ediyor. Sağ tarafta atamalar ok gösterimiyle de yazılmıştır: $x \leftarrow y$, $y \leftarrow k$, $k \leftarrow x \,\%\, y$.

Beyaz tahtadaki akış (ekrandan, 02:35:00):

```text
START
  |
[x, y oku]
  |
[k = x mod y]
  |
<k ≠ 0> --doğru--> [x = y, y = k, k = x mod y] --+
  |  ^                                            |
  |  +--------------------------------------------+
  | yanlış
[y yazdır]
  |
STOP
```

Hoca, stop noktasının algoritmanın ortasında, döngü kurulmadan önce belirlenebildiğine dikkat çekti.

**Test ($x = 36$, $y = 24$)** (ekrandan, 02:35:00):

| adım | $x$ | $y$ | $k$ |
|---|---|---|---|
| başlangıç | 36 | 24 | $36 \bmod 24 = 12$ |
| 1. tur | 24 | 12 | $24 \bmod 12 = 0$ |

- $k = 12 \ne 0$, döngüye girilir: $x = 24$, $y = 12$, $k = 0$.
- $k = 0$ olduğu için koşul yanlış olur, döngüden çıkılır.
- Ekrana $y = 12$ yazdırılır. (Python'daki `math.gcd(36, 24)` de 12 verir.)

Hoca bu örnekte Polya'nın adımlarını yeniden bağladı: ortaokuldaki çarpanlara ayırma bilgisi bir deklarasyondur; Öklid algoritması onu başı, sonu, durma noktası ve her adımı belli bir buyruğa dönüştürür. Akış diyagramı bu algoritmayı ifade eder. Üçüncü adımda testler yapılır (ortalama örneğinde olduğu gibi gerekirse diyagram değiştirilir), dördüncü adımda performans değerlendirilir. $x \bmod y$ sayesinde kalan sıfıra ulaşmak kesindir, bu yüzden algoritmanın sonlanması garantidir. Analiz tatmin ediciyse çözüm bir programlama dilinde gerçeklenir.

> **Ek bilgi (derste anlatılmadı):** Öklid algoritmasında kalan her adımda bölenden küçük olduğu için $y$ değerleri kesin olarak azalan negatif olmayan tam sayılardır; bu yüzden sonlu adımda sıfıra ulaşılır. Adım sayısı sayıların büyüklüğünün logaritmasıyla orantılıdır.

<!-- BELİRSİZ: Hoca performans için "aralarındaki çarpan sayısı kadar işlem yapmış olacağım" dedi; bu ifade altyazıda net olmadığı için kesin bilgi olarak yazılmadı. -->

## Örnek Sorular

**Soru 1** (derste sözlü, 00:15:19): Yumurta pişirmeyi buyurucu bilgi şeklinde, adım adım ifadelerle anlatın.

> **Çözüm (derste tartışıldı):** Bir öğrencinin tarifi (tavayı al, yağ koy, altını aç, yağın kızmasını bekle; yumurtaları bir kaba kır, karıştır, tuz ekle; yağ kızınca dök ve pişir) eksik bulundu: "birinci adım" içinde dört-beş ayrı iş var; yumurtanın nasıl kırılacağı, kabukların ne olacağı, tava, ateş ve yağ miktarı ile durma noktası (ne zaman pişmiş sayılacağı) tanımlanmamış. İyi bir buyurucu tanım her adımı ve durma noktasını kesin olarak verir.

**Soru 2** (derste sözlü, 00:21:02): "Flying planes can be dangerous" cümlesinden ne anlıyorsunuz?

> **Çözüm (derste verildi):** İki anlam çıkar: "uçan uçaklar tehlikeli olabilir" ve "uçak uçurmak tehlikeli olabilir". Doğal dil belirsiz olabildiği için algoritmaların tanımlı sembollerle (akış diyagramı) ifade edilmesi gerekir.

**Soru 3** (derste sözlü, 00:30:50): Bir $x$ sayısı verildiğinde $y \cdot y = x$ eşitliğini sağlayan $y$'yi hesaplama yöntemini bilgisayara nasıl anlatabiliriz?

> **Çözüm (derste verildi):** Tanımı olduğu gibi anlatamayız; bilgisayar yalnız temel komutları bilir. Newton'ın karekök algoritmasıyla adım adım yaklaşılır: $r \leftarrow (r + x/r)/2$ güncellemesi $|r^2 - x| \le e$ olana kadar tekrarlanır. $x = 16$, $e = 0.001$, $r = 3$ için $r$: 3 → 4.17 → 4.0035 → 4.000002 (ekrandan, 00:35:00).

**Soru 4** (ekrandan, 00:45:00): Ön sıradaki en yaşlı öğrenciyi bulan bir algoritma tasarlayın (herkes gerçek doğum gününü verir, aynı gün doğanlar aynı yaştadır, birden fazla en yaşlı varsa birini bildirmek yeterlidir).

> **Çözüm (derste verildi):** Çözüm 1: soldan başlayıp her öğrenciye sor, tahtadakinden yaşlıysa tahtadakini sil ve yenisini yaz; sonunda tahtadakini oku ($n$ ile orantılı iş). Çözüm 2: birden fazla öğrenci kaldıkça ikişerli grupla, tek kalanı tut, her çiftte genç olanı ele; kalanı yaz. Bir turdaki karşılaştırmalar paralel yapılabiliyorsa süre $\log_2 n$ turla orantılıdır (8 öğrenci için 3 tur).

**Soru 5** (derste sözlü, 01:27:12): Girdi sembolü (sol üst köşesi çentikli dikdörtgen) size neyi anımsatıyor?

> **Çözüm (derste verildi):** Delikli kartı. Eski bilgisayarlarda veri delikli kartlarla girilirdi ve kartlar okuyucuya ters takılmasın diye sol üst köşeleri çentikliydi.

**Soru 6** (ekrandan, 02:10:00): Verilen $n$ adet sayının toplamını ve ortalamasını yazdıran algoritmanın akış diyagramını çizin.

> **Çözüm (derste verildi):** Start → `N` oku → `top = 0`, `ort = 0` → for `i = 1..N`: `S` oku, `top = top + S` → `ort = top/N` → `top, ort` yazdır → Stop. $N = 3$ ve girdiler 2, 3, 4 için çıktı 9 ve 3. $N = 0$ için sıfıra bölme oluştuğundan `N` okunduktan sonra `N > 0` kararı eklenir; yanlış kolunda "hata" yazdırılır.

**Soru 7** (derste sözlü, 02:12:32): $N = 0$ girildiğinde sıfıra bölme hatası alınıyor. Ne yapmalıyız?

> **Çözüm (derste verildi):** Uç değeri kontrol eden bir if eklenir: `N > 0` ise hesaplama yapılır, değilse hata mesajı yazdırılır.

**Soru 8** (ekrandan, 02:20:00): Okunan bir $n$ için $f = \sum_{x=1}^{n} \frac{1}{x^2}$ değerini hesaplayıp yazdıran algoritmanın akış diyagramını çizin.

> **Çözüm (derste verildi):** Start → `N` oku → `x = 1`, `f = 0` → while `x <= N`: `f = f + 1/(x*x)`, `x = x + 1` → `f` yazdır → Stop. Alternatif olarak `x = 1..N` for döngüsü kullanılırsa `x = x + 1` gerekmez. $N = 0$ için çıktı 0'dır.

**Soru 9** (ekrandan, 02:35:00): Okunan iki sayının OBEB'ini bulan algoritmanın akış diyagramını çizin ve $x = 36$, $y = 24$ için işletin.

> **Çözüm (derste verildi):** Start → `x, y` oku → `k = x mod y` → while `k ≠ 0`: `x = y`, `y = k`, `k = x mod y` → `y` yazdır → Stop. $36 \bmod 24 = 12$; sonra $x = 24$, $y = 12$, $k = 0$; çıktı 12.

## Dersin Toparlaması

Bu derste algoritmanın ne olduğu, tanımlayıcı bilginin (bir şeyin ne olduğunun) bilgisayarın işletebileceği buyurucu bilgiye (adım adım ne yapılacağına) dönüştürülmesi olarak ele alındı. Algoritmanın sonlu, kesin, anlaşılır, girdisi ve çıktısı iyi tanımlanmış, yapılabilir ve dilden bağımsız olması gerektiği; kelimenin el-Hârizmî'nin adından geldiği; Newton'ın karekök algoritmasının bir deklarasyonu nasıl buyruklara çevirdiği görüldü. Polya'nın dört adımı (anla, planla, uygula, değerlendir) en yaşlı öğrenci problemiyle uygulandı; sıralı çözümün doğrusal, paralel eleme turunun logaritmik süre gerektirdiği karşılaştırıldı ve "daha iyi"nin hedefe (hız, bellek, kolaylık) göre değiştiği vurgulandı.

İkinci bölümde algoritmaları ifade etme yolları (düz yazı, sözde kod, akış diyagramı) ve akış diyagramı sembolleri işlendi: başla/bitir, delikli kart biçimli girdi, kağıt biçimli çıktı, işlem dikdörtgeni, T/F kollu altıgen karar, üç bölmeli for döngüsü, while döngüsü ve bağlayıcı çemberler. Toplam/ortalama, $\sum 1/x^2$ ve Öklid OBEB örnekleri çizilip test edildi; ortalama örneğinde $n = 0$ uç değerinin sıfıra bölmeye yol açtığı ve bir karar eklenerek düzeltildiği görüldü. Bir sonraki derste diğer örneklerle (tüm bölenler, toplama/çıkarma ile çarpma/bölme, Fibonacci sayıları, üç sayının ortancası) ve dizilerin akış diyagramlarında kullanımıyla devam edilecek, ardından bu algoritmaların C ile gerçeklenmesine geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
