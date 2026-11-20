# Ders 5 Genişletilmiş Notu: Dot Plot ve Dinamik Programlama ile İkili Dizi Hizalama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Hizalamaları Skorla Karşılaştırmak
- 2. Hizalama Yöntemlerine Genel Bakış
- 3. Dot Plot (Nokta Matrisi)
- 4. Dot Plot'ta Gürültü ve Kayan Pencere
- 5. Dot Plot'un Kullanımı ve Sınırları
- 6. Dot Plot'tan Global Hizalama Çıkarma Örneği
- 7. Nicel Ölçüler ve Skorlama Soruları
- 8. Kaba Kuvvet ve Dinamik Programlama
- 9. Global Hizalama: Needleman-Wunsch
- 10. Lokal Hizalama: Smith-Waterman
- 11. Örtüşme (Overlap) Hizalaması
- 12. Üç Hizalama Türünün Özeti
- 13. BLOSUM62 ile Kaba Kuvvet Örneği
- 14. Tamamlanmış Matristen Geriye Çalışma
- Örnek Sorular
- Dersin Toparlaması

## 1. Hizalamaları Skorla Karşılaştırmak

Ders, bir önceki derste başlanan ikili dizi hizalaması (pairwise sequence alignment) konusunun devamıyla açıldı. Anlatım büyük ölçüde İngilizce yapıldı. Hoca, önceki derste sorduğu iki nükleik asit (DNA) dizisini yeniden ele aldı: `ACGGACT` ve `ATCGGATCT` (ekrandan, 00:10:00).

Hizalama, iki dizinin kalıntı kalıntı (residue by residue) eşlenmesidir: A ile A, C ile C, G ile G eşlenir; bazı yerlerde ise bir dizideki karakterin karşısına tire konur. Tireler boşluk (gap) adını alır ve ekleme ya da silme (indel) olaylarını temsil eder. Slaytta bu iki dizi için iki geçerli hizalama gösterildi (ekrandan, 00:10:00):

```text
Hizalama 1:
A - C - G G - A C T
A T C G G A T - C T

Hizalama 2:
A T C G G A T C T
A - C G G - A C T
```

Birinci hizalamada birinci dizide birkaç boşluk vardır. Hoca, önceki derste bazı öğrencilerin ikinci hizalamanın daha iyi olduğunu söylediğini hatırlattı. Ama "hangisi daha iyi" sorusunu cevaplamak için nesnel bir ölçüt gerekir. Bu ölçüt bir **skorlama şeması**dır (scoring scheme).

### 1.1 Basit bir skorlama şeması

Hoca şu şemayı önerdi: her eşleşme (match) için $+1$, her uyuşmazlık (mismatch) için $-1$, her boşluk (indel) için $-1$. Bu en azından nesnel bir şemadır. Hizalamanın her sütunu bu kurala göre puanlanır ve puanlar toplanır. Daha yüksek skor daha iyi hizalama demektir.

Birinci hizalama için hoca 5 eşleşme, 1 uyuşmazlık ve 4 boşluk saydı. Sütun sütun bakınca: A/A eşleşme, -/T boşluk, C/C eşleşme, -/G boşluk, G/G eşleşme, G/A uyuşmazlık, -/T boşluk, A/- boşluk, C/C eşleşme, T/T eşleşme. Skor:

$$5 \cdot (+1) + 1 \cdot (-1) + 4 \cdot (-1) = 0$$

İkinci hizalamada A/A, C/C, G/G, G/G, C/C, T/T olmak üzere 6 eşleşme; T/- ve A/- olmak üzere 2 boşluk; T/A olmak üzere 1 uyuşmazlık vardır:

$$6 \cdot (+1) + 1 \cdot (-1) + 2 \cdot (-1) = 3$$

Buna göre ikinci hizalama daha iyidir. Artık hizalamanın kalitesini değerlendirmek için bir ölçütümüz vardır.

> **Ders sonrası not:** Altyazıya göre hoca birinci hizalamanın skorunu $1$, ikincisininkini $7$ olarak söyledi. Ekrandaki hizalamalar bu şemayla python ile hesaplanınca skorlar $0$ ve $3$ çıkıyor; hocanın saydığı 5 eşleşme, 1 uyuşmazlık ve 4 boşluk da $0$ verir. Söylenen değerler büyük olasılıkla Whisper hatası ya da farklı bir slayt sürümüdür. İkinci hizalamanın daha iyi olduğu sonucu değişmez.

## 2. Hizalama Yöntemlerine Genel Bakış

Hoca pratikte kullanılan hizalama yöntemlerini sıraladı (ekrandan, 00:15:00):

- **Görsel hizalama (visual alignment):** Hizalamayı bir grafiğe ya da resme bakarak değerlendirir. Nitel (qualitative) bir değerlendirme verir. Literatürdeki diğer adı dot plot'tur.
- **Kaba kuvvet (brute force):** Bütün olası hizalamaları dener; nicel bir sonuç verir ama çok maliyetlidir.
- **Dinamik programlama:** Verilen skorlama şemasına göre en iyi hizalamayı garanti eder.
- **Kelime tabanlı (word-based) yöntemler:** Hoca bunların var olduğunu, ama bir tür "ad hoc" yöntemler olduğunu söyledi; ileride bunlardan da söz edilecek.

## 3. Dot Plot (Nokta Matrisi)

### 3.1 Tanım ve kuruluş

Dot matrix yöntemi 1970'te A. J. Gibbs ve G. A. McIntyre tarafından önerilmiştir. İki amino asit ya da nükleotit dizisini karşılaştırmak için kullanılır (ekrandan, 00:20:00). Adından da anlaşıldığı gibi hizalama görseldir: bir resme bakarak iki dizinin ilişkisi değerlendirilir.

DNA ve amino asit dizileri bilgisayar açısından tek boyutlu karakter dizileridir. Bir matris kurulur; her dizi ızgaranın bir eksenini oluşturur. Satırlara birinci dizinin karakterleri, sütunlara ikinci dizinin karakterleri yazılır. Slayttaki örnekte sütunlarda `AGCTAGGA`, satırlarda `GACTAGGC` dizisi vardı (ekrandan, 00:20:00). Sonra her satır ve her sütun gezilir; satırdaki karakter sütundaki karakterle aynıysa o hücreye nokta konur. Bütün hücreler incelenene kadar devam edilir.

### 3.2 Algoritma

Hoca sınıfa algoritmanın ne olduğunu sordu. Cevap basittir: elimizde doldurulacak bir matris vardır ve bunun için iç içe iki `for` döngüsü yeterlidir. Dış döngü satırları, iç döngü sütunları gezer. Dot plot'un temel algoritması budur. Hoca slaytta matrisin hücre hücre dolduğu bir animasyon da gösterdi.

Bu örnekteki diziler çok kısa olduğu için desenleri hemen görmek zordur. Dot matrisi elde edildikten sonra bazı desenler ortaya çıkar ve bu desenlere bakarak hizalama hakkında bilgi edinilir.

> **Ek bilgi (derste anlatılmadı):** Derste kod yazılmadı. Anlatılan iki döngülü yapı şöyle özetlenebilir: `for i in range(len(s1)): for j in range(len(s2)): if s1[i] == s2[j]: nokta(i, j)`. Bu bir sözde koddur, derlenmedi.

### 3.3 Başka alanlarda kullanım

Dot matrisi başka alanlarda da kullanılır. Örneğin iki metnin benzer olup olmadığını denetlemek için, yani intihal (plagiarism) tespitinde kullanılabilir. Yarı iletken endüstrisi gibi başka sektörlerde de uygulamaları vardır. Bu derste ise dizi hizalamasını değerlendirmek için kullanılacaktır.

### 3.4 Örnek dot plot ve kendi kendine hizalama

Hoca slaytta 20 karakterlik `ACCTGAGCTCACCTGAGTTA` dizisinin kendisiyle karşılaştırıldığı bir dot plot gösterdi ve sınıfa bir desen görüp görmediklerini sordu (ekrandan, 00:25:00). Bir öğrenci köşegenin koyu olduğunu söyledi. Hoca, sol üst köşeden sağ alt köşeye kesintisiz bir çizgi olduğunu gösterdi. Satır ve sütundaki diziler aynıdır; diziler tamamen aynıysa ana köşegen boyunca kesintisiz bir çizgi oluşur. Bu ilk desendir ve **kendine eşleşme (self-match)** adını alır: her karakter kendisiyle eşleşir.

Aynı slaytta ana köşegene paralel başka çizgiler de vardır. Bunlar dizinin içindeki tekrar eden bölgeleri gösterir: dizinin başındaki `ACCTGAG` parçası 11. konumda yeniden geçer. Ters yönde (sol alttan sağ üste) uzanan kısa bir çizgi de görülür. Hoca, bu desenlerin her birinin bir biyolojik olaya karşılık geldiğini söyledi: bazıları çoğalmaya (duplication), bazıları silme ya da eklemeye karşılık gelir. Bu bir tür görsel değerlendirmedir.

### 3.5 Biyoinformatik dışı bir örnek: yazılımın dot plot'u

Hoca, bir telekomünikasyon yazılım modülünün kendi kendine dot plot'unu gösterdi. Bu, yaklaşık 2 milyon satırlık C kodundan oluşan bir programdır. Koyu alanlar çok eşleşme, yani yüksek benzerlik içeren bölgeleri; açık alanlar az eşleşme, yani düşük benzerlik içeren bölgeleri gösterir. Ana köşegen boyunca uzanan koyu kareler alt modülleri gösterir. Ana köşegen dışındaki koyu alanlar alt modüller arasındaki benzerliği gösterir. En büyük koyu kareler; sinyallerin, tabloların ve sonlu durum makinelerinin başlatılmasındaki tekrarlardan oluşur. Mühendisler bu resme bakarak yazılımın yapısını anlayabilir.

Hoca dersin ilerleyen kısmında bu örneğe döndü ve şunu ekledi: bir programda aynı kod parçası çok kez tekrarlanıyorsa kendi kendine hizalama bunu gösterir. Bu tekrarlar bir fonksiyon olarak yazılabilir ve program daha az satırla ifade edilebilir.

## 4. Dot Plot'ta Gürültü ve Kayan Pencere

### 4.1 Gürültü nereden gelir?

Hoca ilk örnek dot plot'a geri döndü. Satır ve sütunda aynı dizi olduğu için ana köşegen boyunca bir çizgi vardı; ama köşegen dışında da eşleşen birçok hücre görülüyordu. Bu eşleşmelere dot plot'taki **gürültü** (noise) denir. DNA dizisinde yalnız 4 farklı kalıntı, protein dizisinde 20 amino asit vardır. Bu yüzden rastgele eşleşmeler kaçınılmazdır: nükleik asitlerde (DNA, RNA) 4 bazdan biri rastgele eşleşir (ekrandan, 00:40:00).

### 4.2 Kayan pencere

Rastgele eşleşmeleri süzmek için **kayan pencere** (sliding window ya da moving window) tekniği kullanılır. Pencere içinde eşleşen bazların yüzdesi bir eşik olarak belirlenir (ekrandan, 00:40:00). Yani kalıntılar tek tek karşılaştırılmaz; bir pencere boyunca karşılaştırma yapılır ve eşleşme oranı eşiği geçerse nokta konur. Seçilen ölçüte bağlı olarak gürültünün bir kısmı ya da tamamı kaldırılabilir.

### 4.3 Sinyal işlemedeki benzeri

Hoca kavramı istatistik ve sayısal sinyal işlemedeki kayan pencereyle ilişkilendirdi ve sınıfa kayan ortalama filtresinin (moving average filtering) ne olduğunu sordu. Cevap gelmeyince kendisi açıkladı. Kayan ortalama filtresi, zaman serisi verisinden gürültüyü süzmek için kullanılan en basit filtrelerden biridir. Bir sinyal üzerinde $n$ örnekten oluşan bir pencere alınır, bu örneklerin ortalaması hesaplanır ve pencere birer birer kaydırılır (ekranda sinyal ve pencere çizimi, 00:40:00).

- Bu işlem alçak geçiren (low-pass) filtreye karşılık gelir. Görüntü işlemede bulanıklaştırma (blurring) filtresi, finansal zaman serisi analizinde yumuşatma (smoothing) ya da eğilim (trending) filtresi olarak bilinir.
- Bunun tersi olan işlem ekonomik zaman serisi analizinde eğilim giderme (de-trending), görüntü işlemede keskinleştirme (sharpening) filtresi olarak bilinir.
- Kayan medyan filtresinde $n$ örnek alınır ve ortalama yerine medyan bulunur; bu değer filtre çıktısıdır ve pencere birer birer kaydırılır.

Dot plot'taki gürültüyü kaldırmak için de aynı kavram uygulanır. Hoca, aynı dizinin kendi kendine dot plot'unu gürültü azaltmadan ve gürültü azaltılarak gösterdi; ikincisinde gürültünün büyük kısmının kalktığı açıkça görülüyordu.

### 4.4 Hazır programlar

Hoca slaytta çevrimiçi dot plot programlarının bir listesini gösterdi; bunların hâlâ çalışıp çalışmadığını yakın zamanda denetlemediğini söyledi. Dotter adlı bir program da anıldı. <!-- BELİRSİZ: program adı altyazıda "DUTR" olarak geçiyor; büyük olasılıkla Dotter. Liste karelerde görünmüyor. --> Hoca, kendi dot plot programınızı da yazabileceğinizi, bunun zor olmadığını, temelde iki `for` döngüsü olduğunu vurguladı.

## 5. Dot Plot'un Kullanımı ve Sınırları

### 5.1 Dot plot'tan elde edilen bilgi

Biyoinformatik bağlamında dot plot, iki dizi arasındaki hizalamayı belirlemek için birinci düzey bir süzgeç olarak yararlı bir araçtır. Gerçek uygulamalarda birkaç kalıntılık değil, binlerce kalıntılık dizilerle çalışılır.

- **Eklemeler ve silmeler:** Ekleme/silme içeren bölgeler kolayca belirlenir (ekrandan, 00:30:00). Diziler tamamen aynı olsaydı kesintisiz bir köşegen olurdu; köşegendeki kopukluklar boşlukları, yani ekleme ya da silmeleri temsil eder.
- **Ekzon sayısı:** Bir potansiyel uygulama, işlenmiş (processed) bir mRNA içindeki kodlayan bölgelerin, yani ekzonların sayısını belirlemektir (ekrandan, 00:30:00). Ekzonlar bir önceki derslerde anılmıştı.
- **Tekrarlar:** Bir dizi kendisiyle karşılaştırılınca bir alt dizinin tekrarının varlığı ortaya çıkar.
- **Ters tekrarlar (inverted repeats):** Ters tümleyen (reverse complement) bölgelerdir. Hoca, DNA'nın bir dizi ve onun ters tümleyeninden oluştuğunu hatırlattı.
- Kendi kendine karşılaştırmanın gösterebildiği diğer özellikler: kromozomlar arasındaki benzerlik, ardışık (tandem) genler, bir protein dizisindeki tekrarlanan domainler, düşük dizi karmaşıklığına sahip bölgeler.

### 5.2 Desen örnekleri

Hoca birkaç dot plot örneği üzerinde desenleri gösterdi:

- Birbirine çok benzeyen ama özdeş olmayan iki dizide köşegen üzerinde bir indel açıkça görülür.
- Ardışık çoğalma (tandem duplication): bir parça bittikten sonra çizgi geri dönüp yeniden başlar; aynı bölüm iki kez geçmiştir.
- Kendi kendine dot plot'ta düz ana köşegen dizinin aynı olduğunu gösterir; köşegenin dışında kalan rastgele çoğalmalar da görülebilir.
- Tekrarlar köşegene paralel çizgiler, ters tekrarlar ise ters yönde uzanan çizgiler olarak görülür. Hoca, normal yönde devam etmesi gereken bir bölümün ters dönmesini (inversion) bu şekilde gösterdi.

### 5.3 Birleştirmeleri (assembly) karşılaştırma

Uygulamada uzun diziler parça parça okunur ve birleştirilir. Dot plot, aynı dizinin iki farklı birleştirmesini karşılaştırmak için de kullanılabilir. Hoca çeşitli kromozomlardan üç dot plot gösterdi:

- Birincisi, insan kromozomu 5'in iki ayrı birleştirmesinin birbiriyle karşılaştırılmasıdır.
- İkincisi, kromozom 5'in bir birleştirmesinin kendisiyle karşılaştırılmasıdır; tekrar eden bölgelerin varlığını gösteren düz çizgiler görülür.
- Üçüncüsü, Y kromozomunun kendisiyle karşılaştırılmasıdır ve ters tekrarların varlığını gösterir.

### 5.4 Ne zaman kullanılır, sınırları nelerdir?

Slayta göre dot plot yöntemi, diziler birbirine çok benzediği bilinmedikçe (tek başına yeterli değildir) kullanılır. Dot matrisinin sınırları şunlardır (ekrandan, 00:45:00):

- Ekleme ya da silmelerle kesintiye uğrayan benzerliği kolayca çözemez.
- En iyi olası hizalamayı (optimal hizalama) bulmak zordur.

Hoca bir sonraki örnekte bir dot matrisinden hizalama bulmayı göstereceğini, ama bunun ancak çok az kalıntılı dizilerde yapılabildiğini söyledi.

## 6. Dot Plot'tan Global Hizalama Çıkarma Örneği

Hoca, örnek dosyasından bir soru açtı. İki amino asit dizisi verilir (DNA değil): sütunlarda `DILVDEQ`, satırlarda `IVQDEQ` (ekrandan, 00:50:00). İstenen, bu iki dizinin dot plot'unu çizmek ve iki dizi için olası bir global hizalama bulmaktır.

Önce matris kurulur; bir dizi satıra, diğeri sütuna yazılır ve aynı harflerin kesiştiği hücrelere nokta konur. Slayttaki noktalar: I/I, V/V, Q/Q, D satırında iki nokta (sütundaki iki D ile), E/E ve Q/Q (ekrandan, 00:50:00). Sağ alttaki D-E-Q noktaları köşegen boyunca art arda gelir; bu bir lokal eşleşmedir. Ama istenen global hizalamadır, yani dizilerin tamamının nasıl hizalanacağıdır. Matristeki bazı noktalar gürültüdür.

Geri izleme sağ alt köşeden başlar:

1. Q-Q eşleşir, köşegen boyunca yukarı çıkılır: E-E eşleşir, D-D eşleşir.
2. D-D hücresinden yukarı çıkılır. Okun gösterdiği dizide, yani üstteki dizide bir boşluk oluşur: satırdaki Q, sütun dizisinde bir boşlukla eşlenir.
3. Sonra V-V eşleşmesine gelinir.
4. Ok bu kez diğer diziyi gösterir: sütundaki L, satır dizisinde bir boşlukla eşlenir.
5. Bir yukarı gidilince I-I eşleşir.
6. En baştaki D için de diğer dizide bir boşluk vardır.

Sonuç global hizalama:

```text
D I L V - D E Q
- I - V Q D E Q
```

<!-- BELİRSİZ: Son hizalama karede tam görünmüyor; 00:50:00 karesinde yalnız sağ alttaki Q-D-E-Q (satır dizisi) ve boşluklu D-E-Q kısmı yazılı. Kalanı hocanın anlatımı ve karedeki noktalardan kuruldu. -->

Hoca bu uygulamada hiç gürültü azaltma kullanılmadığını, bunun düz bir dot plot ve global hizalamanın belirlenmesi olduğunu söyledi. Burada nesnel bir skorlama şeması yoktur; hizalama sezgiyle bulunur.

Bu bölümden sonra derse yaklaşık bir saatlik ara verildi.

## 7. Nicel Ölçüler ve Skorlama Soruları

### 7.1 Mesafe ölçüleri

Aradan sonra hoca, ikili hizalamanın nitel değerlendirmesinin görüldüğünü, ama dizi benzerliği ve farkı için nicel ölçüler gerektiğini söyledi. Önceki derste görülen iki ölçüyü hatırlattı:

- **Hamming mesafesi:** Uyuşmayan karakterlerin sayısıdır; dizi benzerliğinin en basit nicel ölçüsüdür.
- **Levenshtein mesafesi:** Bir düzenleme mesafesidir (edit distance); Hamming mesafesinin değiştirilmiş biçimidir. Bir dizgiyi diğerine çevirmek için gereken işlem sayısıdır ve silme, ekleme, yer değiştirme işlemlerini içerir. Slayttaki bir hizalamada 2 uyuşmazlık ve 1 boşluk olduğu için Levenshtein mesafesi 3'tür.

### 7.2 Skorlamada sorulacak sorular

Hoca skorlama kavramını yeniden ele aldı. Slayttaki sorular şunlardır (ekrandan, 02:05:00):

- Eşleşme için $+1$, uyuşmazlık için $-1$ mi verilmeli?
- Boşluklara izin verilmeli mi? Verilirse nasıl puanlanmalı?
- İki dizinin optimal hizalamasını bulmak için en iyi algoritma hangisidir?
- Üretilen hizalama anlamlı (significant) mı?

Önceki örneklerde boşluklar için de bir ceza kullanılmıştı. Hoca şimdilik benimsenen skorlama şemasının uygun olup olmadığını sormadığını, bunun ileride ele alınacak ayrı bir konu olduğunu söyledi. Bulunan hizalamanın anlamlı olup olmadığı da ayrıca değerlendirilmelidir: bir skorlama şemasıyla optimal bir hizalama bulunduğu söylendiğinde, bu hizalamanın anlamlı olup olmadığı sorgulanmalıdır. Önce optimal hizalamanın nasıl bulunacağı ele alındı.

## 8. Kaba Kuvvet ve Dinamik Programlama

### 8.1 Problem tanımı

$X$ ve $Y$ iki dizi olsun; DNA ya da protein dizisi olabilir. $X$'in uzunluğu $m$, $Y$'nin uzunluğu $n$ olsun. Boşluklara izin veriliyorsa dizilerin uzunlukları boşluklarla uzatılarak eşitlenir. Optimal hizalamayı bulmanın iki yolu vardır: kaba kuvvet ve dinamik programlama.

### 8.2 Kaba kuvvet

Kaba kuvvet aslında bir algoritma bile sayılmaz; bütün olası seçeneklerin denenmesidir. Hocanın anlatımına göre $X$ ve $Y$ boşluklarla $m+n$ uzunluğuna uzatılır; $X$ için $2^{m+n}$, $Y$ için $2^{m+n}$ alt dizi vardır ve bunların bütün eşleşmeleri denenir. Bu algoritmanın karmaşıklığı üstel olarak artar ve pratikte kullanılamaz hale gelir.

### 8.3 Dinamik programlama

Dinamik programlama bilgisayar biliminde optimizasyon problemlerini çözmek için yaygın kullanılan bir alandır. Problemi bağımsız alt problemlere bölerek çözer; hoca bunu böl ve yönet (divide and conquer) yaklaşımı olarak andı. Bu yaklaşımın sonuçları:

- Algoritmayı uygulamak için bellek gerekir; ara sonuçlar saklanır.
- Optimal skor, o noktaya kadar hesaplanmış optimal hizalamanın üzerine kurulur.
- Dinamik programlama iki diziyi uçlardan başlayarak hizalar ve bütün olası karakter çiftlerini hizalamaya çalışır.
- Eşleşme, uyuşmazlık ve boşluk için bir skorlama şeması kullanılır. Başta ve örneklerde basit şemalar kullanılacaktır; eşleşme skorları ileride DNA'da ya da amino asit mutasyon olasılıklarından türetilecektir.
- En yüksek skor kümesi diziler arasındaki optimal hizalamayı tanımlar.

İki dizi ve bir skorlama şeması verildiğinde dinamik programlama optimal bir hizalama verir.

### 8.4 Dinamik programlamanın adımları

1. **Başlatma (initialization):** Dot plot'a çok benzer bir matris kurulur ve başlatılır.
2. **Matris doldurma (matrix fill):** Skorlama şeması kullanılarak hücreler doldurulur.
3. **Geri izleme (traceback):** Asıl hizalamayı belirlemek için geriye doğru izlenir. Geri izleme gerektiği için matris değerleri bellekte tutulmalıdır.

## 9. Global Hizalama: Needleman-Wunsch

### 9.1 Örnek diziler ve matris

Kavramları netleştirmek için iki DNA dizisi alındı: `GAATTCAGTTA` (11 karakter) ve `GGATCGA` (7 karakter). Diziler $7 \times 11$'lik bir matris gerektirir, ama asıl matris $8 \times 12$'dir; çünkü bir satır ve bir sütun başlatma için ayrılır (ekrandan, 02:15:00). Genel olarak $M$ ve $N$ dizi uzunluklarıysa matris $M+1$ satır, $N+1$ sütundur. Slaytta satırlarda `GGATCGA`, sütunlarda `GAATTCAGTTA` yazılıdır; her ikisinin başında bir `-` satırı/sütunu vardır.

Skorlama şeması: eşleşme $5$, uyuşmazlık $-3$, boşluk cezası $w = -4$.

### 9.2 Hangi tür hizalama?

Başlatmadan önce hangi tür hizalama arandığı sorusu cevaplanmalıdır. Üç temel hizalama türü vardır. Birincisi, iki dizinin bütün kalıntılarını hizalamaya çalışan **global hizalama**dır. Bu durumda büyük olasılıkla kısa dizide, onu uzun diziye eşitlemek için bazı boşluklar olur. Global hizalama, bu algoritmayı dizi hizalaması için ilk önerenlere atfen Needleman-Wunsch algoritması olarak da bilinir.

### 9.3 Başlatma

Global hizalamada ilk satır ve ilk sütun boşluk cezasıyla doldurulur:

$$S_{i,0} = i \cdot w, \qquad S_{0,j} = j \cdot w$$

Burada $w$ boşluk cezası, $i$ ve $j$ satır ve sütun indeksleridir. Hoca önce boşluk cezasını $-3$ sandı, sonra $-4$ olduğunu düzeltti. Sol üst hücre $0$'dır (indeks 0). Sonra $1 \times (-4)$, $2 \times (-4)$, $3 \times (-4)$ diye gider. Bu örnekte ilk satır $0, -4, -8, \dots, -44$; ilk sütun $0, -4, \dots, -28$ olur (ekrandan, 02:25:00).

### 9.4 Matris doldurma

Kalan hücreler matris doldurma denklemiyle belirlenir (ekrandan, 02:20:00):

$$S_{i,j} = \max\left[S_{i-1,j-1} + s(a_i,b_j),\ S_{i,j-1} + w,\ S_{i-1,j} + w\right]$$

- Birinci terim köşegendeki eşleşme/uyuşmazlıktır: köşegendeki komşu hücrenin değeri artı iki karakterin eşleşme ya da uyuşmazlık skoru.
- İkinci terim soldaki hücrenin değeri artı boşluk cezasıdır (birinci dizide boşluk).
- Üçüncü terim üstteki hücrenin değeri artı boşluk cezasıdır (ikinci dizide boşluk).

Hoca ekranda bir hücre çizerek gösterdi: değeri bulunacak hücre için köşegendeki, soldaki ve üstteki hücrelerin değerleri zaten bilinir. Bilinen bu değerlerden yeni hücrenin değeri bulunur. Dinamik programlamanın özü budur: problem yerel problemlere indirgenir. Bu formül aslında bir denklem bile değildir, yalnız üç değerin en büyüğüdür; bununla bütün hücreler belirlenebilir.

İlk iç hücre (G satırı, G sütunu) için: köşegen $0 + 5 = 5$, sol $-4 + (-4) = -8$, üst $-4 + (-4) = -8$. En büyüğü $5$'tir. Bu değer köşegen hücreden geldiği için bu bilgi hatırlanmalıdır. Uygulamada hücre indekslerini tutan bir veri dizisi kullanılır; bu, geri izlemede asıl hizalamayı belirlemek için gerekir. Bazı durumlarda iki komşu aynı değeri verir; o zaman ikisi de saklanmalıdır.

Doldurulmuş global matris şöyledir (ekrandan, 02:25:00; python ile doğrulandı):

```text
       -    G    A    A    T    T    C    A    G    T    T    A
  -    0   -4   -8  -12  -16  -20  -24  -28  -32  -36  -40  -44
  G   -4    5    1   -3   -7  -11  -15  -19  -23  -27  -31  -35
  G   -8    1    2   -2   -6  -10  -14  -18  -14  -18  -22  -26
  A  -12   -3    6    7    3   -1   -5   -9  -13  -17  -21  -17
  T  -16   -7    2    3   12    8    4    0   -4   -8  -12  -16
  C  -20  -11   -2   -1    8    9   13    9    5    1   -3   -7
  G  -24  -15   -6   -5    4    5    9   10   14   10    6    2
  A  -28  -19  -10   -1    0    1    5   14   10   11    7   11
```

### 9.5 Geri izleme

Hoca, okların çok olduğu bu matriste geri izlemeye nereden başlanacağını sordu. Global hizalamada geri izleme **her zaman sağ alt köşedeki hücreden** başlar. Bu hücrenin değeri, yani $11$, en büyük global hizalama skorudur.

Sağ alt hücreden başlanır ve bu hücrenin değerini belirleyen hücreye gidilir. Her hücrede bellekte tutulan işaretçiye bakılır; işaretçi hangi yönü gösteriyorsa oraya gidilir, başka yöne gidilemez. Bilgi zaten bellekte olduğu için izleme sol üst köşeye kadar sürdürülür.

Bulunan hizalama (ekrandan, 02:30:00):

```text
G A A T T C A G T T A
| |   | | |   |     |
G G A - T C - G - - A
```

Hoca hizalamayı adım adım okudu: A ile A hizalanır; okun yönüne göre okun gösterdiği dizide boşluklar oluşur; G ile G hizalanır; T'ler boşluklarla hizalanır; geri kalan sütunlar da işaretçilere göre aynı şekilde okunur. Dot plot örneğinde global hizalama sezgiyle bulunmuştu; burada ise nesnel bir yöntemle optimal hizalama belirlenir.

Skor kontrolü (ara adım eklendi): sütun sütun G/G $+5$, A/G $-3$, A/A $+5$, T/- $-4$, T/T $+5$, C/C $+5$, A/- $-4$, G/G $+5$, T/- $-4$, T/- $-4$, A/A $+5$. Toplam: 6 eşleşme $30$, 1 uyuşmazlık $-3$, 4 boşluk $-16$; $30 - 3 - 16 = 11$. Sağ alt hücredeki değerle aynıdır, yani hizalama doğrudur.

### 9.6 Maksimum mu, minimum mu?

Hoca doldurma denklemine dönerek bazı algoritmaların en büyük yerine en küçük değeri, bazılarının başka fonksiyonları kullandığını söyledi. Burada skorlama şeması kullanıldığı için yüksek skor daha iyi hizalama demektir; bu yüzden en büyük değer alınır. Mesafe kullanılırsa büyük olasılıkla en küçük değer alınır. Bu fonksiyon konuya ya da alana göre değişebilir.

> **Hocanın vurgusu:** Algoritma aslında çok basittir; temel yapısı iki `for` döngüsüdür ve karmaşıklığını bulmak kolaydır.

## 10. Lokal Hizalama: Smith-Waterman

### 10.1 Amaç

İkinci hizalama türü lokal hizalamadır. Burada dizilerin bütün kalıntılarını (bilgisayar açısından bütün karakterlerini) hizalamaya çalışılmaz; bazı lokal desenlerin olup olmadığı görülmek istenir. Lokal hizalama Smith-Waterman algoritması olarak da bilinir.

### 10.2 Global hizalamadan iki farkı

Lokal hizalama global hizalamaya çok benzer, ama iki noktada ayrılır:

1. Uyuşmazlıklar için negatif skorlar kullanılır ve skor matrisindeki bir değer negatif olursa sıfıra çekilir. Hiçbir hücrenin negatif skoru olmasına izin verilmez; sıfıra çekmek hizalamayı yeniden başlatmak demektir.
2. Başlatma farklıdır: negatif değer istenmediği için ilk satır ve ilk sütun boşluk cezasıyla değil, sıfırla doldurulur. Bu açıdan global hizalamadan daha basittir.

Matris aynı şekilde kurulur: bir dizi satıra, diğeri sütuna yerleştirilir; hangisinin nereye gittiği önemli değildir.

Başlatma ve doldurma formülleri (ekrandan, 02:55:00):

$$S_{i,0} = 0, \qquad S_{0,j} = 0$$

$$S_{i,j} = \max\left[S_{i-1,j-1} + s(a_i,b_j),\ S_{i,j-1} + w,\ S_{i-1,j} + w,\ 0\right]$$

İlk üç terim global hizalamayla aynıdır; dördüncü terim olan $0$ sıfırlama değeridir. Üç değerin hepsi negatifse $0$ onlardan büyük olduğu için hücre otomatik olarak $0$ olur.

### 10.3 Aynı örnekte lokal matris

Aynı diziler ve aynı skorlarla lokal matris şöyledir (ekrandan, 02:40:00; python ile doğrulandı):

```text
       -    G    A    A    T    T    C    A    G    T    T    A
  -    0    0    0    0    0    0    0    0    0    0    0    0
  G    0    5    1    0    0    0    0    0    5    1    0    0
  G    0    5    2    0    0    0    0    0    5    2    0    0
  A    0    1   10    7    3    0    0    5    1    2    0    5
  T    0    0    6    7   12    8    4    1    2    6    7    3
  C    0    0    2    3    8    9   13    9    5    2    3    4
  G    0    5    1    0    4    5    9   10   14   10    6    2
  A    0    1   10    6    2    1    5   14   10   11    7   11
```

Matriste negatif değer yoktur; negatif olacak yerlerde sıfır vardır.

### 10.4 Geri izleme nereden başlar?

Hoca sınıfa lokal hizalamada geri izlemeye nereden başlanacağını sordu ve sağ alt köşeyi gösterip "buradan başlayabilir miyiz?" dedi. Cevap hayırdır.

> **Hocanın vurgusu:** Global hizalamada sağ alt köşeden başlamak gerekir; lokal hizalamada sağ alt köşeden başlanamaz. Bu bir sınav sorusu olsaydı bu cevap yanlış olurdu.

Algoritma her zaman en büyük skoru bulmaya çalışır. Lokal hizalamada geri izleme, matrisin herhangi bir yerindeki **en büyük değerden** başlar. Bu örnekte iki tane en büyük değer vardır: $14$ (G satırı/G sütunu ve A satırı/A sütunu hücreleri). Hoca alttaki $14$'ü seçti. Kural global hizalamadakiyle aynıdır: işaretçiler izlenerek geriye gidilir, ama bu kez **sıfıra ulaşınca durulur**.

Bazı hücrelerde iki seçenek vardır; çünkü doldurma denkleminde birden çok terim aynı en büyük değeri vermiştir. Bu iki farklı geri izleme yolu, aynı skora sahip iki farklı hizalama verir (ekrandan, 02:45:00):

```text
G A A T T C - A        G A A T T C - A
|   | |   |   |        |   |   | |   |
G G A T - C G A        G G A - T C G A
```

Her iki hizalamada 5 eşleşme, 1 uyuşmazlık ve 2 boşluk vardır: $25 - 3 - 8 = 14$ (python ile doğrulandı).

Diğer $14$'ten de başlanabilirdi; o zaman başka bir hizalama kümesi bulunurdu. Bu örnekte birden çok lokal hizalama vardır, derste yalnız ikisi bulundu. Nesnel değerlendirme ölçütü belirli bir skorlama şemasıdır ve bu şemaya göre bu iki hizalama da optimaldir, çünkü ikisinin skoru aynıdır.

## 11. Örtüşme (Overlap) Hizalaması

### 11.1 Neden gerekir?

Üçüncü tür, global ve lokal hizalamanın birleşimidir. Genellikle örtüşme hizalaması (overlap alignment) adını alır; bazı kaynaklarda yarı global (semi-global) ya da yarı lokal hizalama da denir. Derste "örtüşme hizalaması" adı kullanıldı.

Mantığını göstermek için hoca şu problemi verdi: verilen iki dizi arasındaki en anlamlı örtüşmeyi bulun. Uzun DNA dizileri bölümlere, alt bölümlere ayrılarak okunur. Elimizde tek bir DNA dizisinin ayrı diziler halinde bazı alt bölümleri vardır ve bunları tek bir dizi yapmak için uç uca dikmek (stitch), örtüştürmek gerekir. Bu tekniğin bir kullanımı budur. Burada iki dizinin uç noktaları önemlidir: aynı dizinin iki ayrı parçası birleştirilmek istenir. Bu lokal bir hizalama değildir.

### 11.2 Başlatma, doldurma ve skor

Örtüşme hizalamasında başlatma lokal hizalamadaki gibi, doldurma (recurrence) ise global hizalamadaki gibi yapılır. Bu yüzden melez (hybrid) bir tekniktir ve bu tür matrislerde negatif değerlere izin verilir (ekrandan, 02:50:00):

$$S_{i,0} = 0, \qquad S_{0,j} = 0$$

$$S_{i,j} = \max\left[S_{i-1,j-1} + s(a_i,b_j),\ S_{i,j-1} + w,\ S_{i-1,j} + w\right]$$

Skor, **en alt satır ya da en sağ sütundaki en büyük değerdir**. Matrisin içinde bir yerde olamaz, yalnız en alt satırda ya da en sağ sütunda olabilir. Geri izleme bu hücreden başlar.

### 11.3 Örnek

Hoca, eşleşme skoru $4$, uyuşmazlık skoru $-1$, boşluk cezası $-5$ olan bir örnek gösterdi. Başlatma $0$ ile, matris doldurma global hizalamadaki gibi yapıldı ve negatif değerlere izin verildi. Sonra en büyük değerin yeri en alt satır ve en sağ sütunda arandı ve bulunan hücreden geri izlenerek hizalama elde edildi. Hoca bu iki dizinin büyük olasılıkla aynı dizinin parçaları olduğunu, birinci dizinin sonundaki parçanın ikinci diziyle örtüştüğünü söyledi.

<!-- BELİRSİZ: Bu örneğin dizileri, doldurulmuş matrisi ve sonuç hizalaması karelerde görünmüyor (02:50:00 ve 02:55:00 kareleri formül slaytlarıdır). Altyazıda birinci dizinin sonu "h-e-a-e" diye geçiyor. Aynı parametreler Örnek Sorular'daki E1 sorusunda da kullanılmıştır. -->

## 12. Üç Hizalama Türünün Özeti

Hoca dizi hizalama türlerini bir slaytta özetledi (ekrandan, 02:55:00):

| Tür | Başlatma | Doldurma | Geri izleme başlangıcı |
|---|---|---|---|
| Global (Needleman-Wunsch) | $S_{i,0} = i w$, $S_{0,j} = j w$ | $\max[S_{i-1,j-1}+s(a_i,b_j),\ S_{i,j-1}+w,\ S_{i-1,j}+w]$ | Sağ alt köşe |
| Lokal (Smith-Waterman) | $S_{i,0} = 0$, $S_{0,j} = 0$ | $\max[S_{i-1,j-1}+s(a_i,b_j),\ S_{i,j-1}+w,\ S_{i-1,j}+w,\ 0]$ | Matristeki en büyük değer; sıfırda durulur |
| Örtüşme | $S_{i,0} = 0$, $S_{0,j} = 0$ | Global ile aynı | En alt satır/en sağ sütundaki en büyük değer |

## 13. BLOSUM62 ile Kaba Kuvvet Örneği

### 13.1 Soru ve yer değiştirme matrisi

Hoca kaba kuvvetin nasıl çalıştığını gösteren basit bir örnek açtı (ekrandan, 03:00:00). Soru: BLOSUM62 yer değiştirme (substitution) matrisi kullanılarak şu iki dizinin en iyi hizalaması nedir?

```text
FYGNYK
DGSFNW
```

BLOSUM62 gibi yer değiştirme matrisleri, kalıntıların birbirinin yerine geçme olasılıklarından hesaplanır ve bu değerlerle skor matrisi belirlenir. Başta kullanılan "eşleşme şu kadar, uyuşmazlık şu kadar" türünden basit skorlamanın gerçek biyolojiyle ilgisi yoktur; bu tür matrisler ise gerçek biyolojiyle ilişkilidir ve hizalama için çok daha anlamlıdır. Hoca matristen örnek değerler okudu: S'nin C'ye dönüşmesi $-1$, T ile S $1$, S ile S $4$ değerindedir. Uyuşmazlıkların değerleri birbirinden farklıdır.

### 13.2 Kaydırarak skorlama

Kaba kuvvet yaklaşımında diziler daha önce anlatıldığı gibi boşluklarla uzatılır, sonra hizalanıp skorları belirlenir. Boşluk cezası şimdilik $-1$ alınır; boşluk cezaları ileride ayrıca ele alınacak.

İlk konumda diziler hiç üst üste gelmez; 12 karakterin hepsi bir boşlukla eşlenir ve skor $12 \times (-1) = -12$ olur. Sonra ikinci dizi birer kaydırılarak bütün olası hizalamalar elde edilir ve her kaydırmanın skoru hesaplanır. Hoca skorları sırasıyla şöyle okudu (altyazıda eksi işaretleri düşmüş; değerler python ile yeniden hesaplandı ve hocanın okuduğu sırayla birebir uyuşuyor):

$$-12,\ -11,\ -13,\ -8,\ -10,\ 5,\ -14,\ -2,\ -7,\ -4,\ -9,\ -9,\ -12$$

En iyi skor $5$'tir ve şu hizalamaya karşılık gelir (ara adım eklendi):

```text
F Y G N Y K -
- D G S F N W
```

Skor: F/- $-1$, Y/D $-3$, G/G $6$, N/S $1$, Y/F $3$, K/N $0$, -/W $-1$; toplam $5$.

<!-- BELİRSİZ: Hocanın ekranda gösterdiği en iyi hizalama karelerde görünmüyor; yukarıdaki hizalama python hesabından ve hocanın okuduğu skor dizisinden kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** Bu örnekte kaba kuvvet yalnız dizilerin birbirine göre kaydırılmasıyla (iç boşluk koymadan) yapılmıştır. İç boşluklara da izin verilirse olası hizalama sayısı çok daha hızlı büyür; dinamik programlamanın üstünlüğü buradan gelir.

## 14. Tamamlanmış Matristen Geriye Çalışma

Dersin sonunda hoca örnek dosyasından birkaç soru açtı ve öğrencilerden cevabı sohbet penceresine yazmalarını istedi. Birinci soruda tamamlanmış bir dinamik programlama matrisi verilir ve hizalama türü, eşleşme skoru, uyuşmazlık skoru ve boşluk cezası sorulur (ekrandan, 03:10:00; soru metni ve çözüm için bkz. Örnek Sorular).

**Soru:** Bir öğrenci hizalamanın lokal olduğunu söyledi; nedeni ilk satır ve sütunun sıfırlarla başlatılmış olmasıydı. Öğrenci örtüşme hizalamasını tam anlamadığını, onun da sıfırla başlatıldığını sonradan fark ettiğini belirtti. **Cevap:** Hoca, lokal hizalamada başlatmanın sıfırla yapıldığını ve negatif değerlere izin verilmediğini hatırlattı. Bu matriste negatif değerler vardır; o halde hizalama örtüşme hizalamasıdır.

> **Hocanın vurgusu:** Bu kavramlar çok kolay karıştırılıyor; tam oturtulması gerekir.

Eşleşme ve uyuşmazlık skorları matristeki değerlerden doğrudan okunabilir: aynı harflerin kesiştiği bir hücreyi diğer hücrelerle karşılaştırmak yeterlidir. Boşluk cezası için doldurma bağıntısını hatırlamak gerekir; basit bir denklem yazılarak bulunur. Hoca boşluk cezasının $-5$ olduğunu söyledi ve geriye doğru çalışılabileceğini vurguladı.

İkinci soruda bir global hizalamanın tamamlanmış matrisi verilir ve dizilerin hizalaması istenir. Hoca bu soruda aynı skoru veren üç hizalama olduğunu söyledi. Bunlar hesaplanırsa hepsinin skoru $0$ çıkar, çünkü sağ alt köşedeki hücrenin değeri $0$'dır.

<!-- BELİRSİZ: İkinci sorunun matrisi ve üç hizalama karelerde görünmüyor. -->

Hoca, kendi web sayfasında geçmiş sınavlardan alınmış çok sayıda örnek olduğunu söyledi: dot plot çizme ve verilen bir matrisle lokal hizalama bulma gibi sorular. Örnekler arasında soru numaralarında ve cevaplarda biraz karışıklık olduğunu da belirtti.

## Örnek Sorular

### Soru 1: Hangi hizalama daha iyi?

(ekrandan, 00:10:00) `ACGGACT` ve `ATCGGATCT` dizileri için şu iki hizalama verilir. Eşleşme $+1$, uyuşmazlık $-1$, boşluk $-1$ ile hangisi daha iyidir?

```text
Hizalama 1:            Hizalama 2:
A - C - G G - A C T    A T C G G A T C T
A T C G G A T - C T    A - C G G - A C T
```

**Çözüm:** Hizalama 1: 5 eşleşme, 1 uyuşmazlık, 4 boşluk; $5 - 1 - 4 = 0$. Hizalama 2: 6 eşleşme, 1 uyuşmazlık, 2 boşluk; $6 - 1 - 2 = 3$. Yüksek skor daha iyi olduğundan ikinci hizalama daha iyidir. (Derste söylenen skorlar için 1. bölümdeki ders sonrası nota bakın; skorlar python ile hesaplandı.)

### Soru 2: Dot plot algoritması

(derste sözlü, 00:18:56) Dot plot matrisini dolduran algoritma nedir?

**Çözüm (derste verildi):** İç içe iki `for` döngüsü. Dış döngü satırları, iç döngü sütunları gezer; iki karakter aynıysa hücreye nokta konur.

### Soru 3: Dot plot'ta desen

(derste sözlü, 00:23:01; ekrandan, 00:25:00) `ACCTGAGCTCACCTGAGTTA` dizisinin kendisiyle dot plot'unda hangi desen görülür?

**Çözüm (derste verildi):** Sol üst köşeden sağ alt köşeye kesintisiz bir ana köşegen; satır ve sütundaki diziler aynıdır (kendine eşleşme). Köşegene paralel çizgiler tekrar eden bölgeleri, ters yöndeki çizgiler ters tekrarları gösterir.

### Soru 4: Dot plot'tan global hizalama

(ekrandan, 00:50:00) `DILVDEQ` ve `IVQDEQ` amino asit dizilerinin dot plot'unu çizin ve olası bir global hizalama bulun.

**Çözüm (derste verildi):** Sağ alttaki Q-Q'dan başlanıp köşegen boyunca E-E ve D-D'ye çıkılır; ardından boşluklarla V-V ve I-I eşleşmelerine gidilir. Sonuç:

```text
D I L V - D E Q
- I - V Q D E Q
```

### Soru 5: Kayan ortalama filtresi

(derste sözlü, 00:37:41) Kayan ortalama filtresi nedir?

**Çözüm (derste verildi):** Sinyal üzerinde $n$ örnekten oluşan bir pencere alınır, ortalaması hesaplanır ve pencere birer kaydırılır. Alçak geçiren bir filtredir (bulanıklaştırma, yumuşatma). Dot plot'taki gürültü azaltma aynı kayan pencere fikrini kullanır.

### Soru 6: Global ve lokal hizalamada geri izlemenin başlangıcı

(derste sözlü, 02:24:22 ve 02:39:15) Global hizalamada ve lokal hizalamada geri izlemeye nereden başlanır?

**Çözüm (derste verildi):** Global hizalamada her zaman sağ alt köşedeki hücreden. Lokal hizalamada matrisin herhangi bir yerindeki en büyük değerden; geri izleme sıfıra ulaşınca durur. Örnekte en büyük değer $14$ iki hücrede geçer.

### Soru 7: Global hizalama matrisi

(ekrandan, 02:15:00 ve 02:25:00) `GAATTCAGTTA` ve `GGATCGA` dizilerini eşleşme $5$, uyuşmazlık $-3$, boşluk $-4$ ile global olarak hizalayın.

**Çözüm (derste verildi):** Matris 9.4'teki gibidir; sağ alt hücre $11$'dir. Hizalama:

```text
G A A T T C A G T T A
G G A - T C - G - - A
```

Kontrol: $6 \cdot 5 + 1 \cdot (-3) + 4 \cdot (-4) = 11$.

### Soru 8: BLOSUM62 ile en iyi hizalama

(ekrandan, 03:00:00) BLOSUM62 yer değiştirme matrisini kullanarak `FYGNYK` ve `DGSFNW` dizilerinin en iyi hizalaması nedir? (Derste boşluk cezası $-1$ alındı ve kaba kuvvetle kaydırmalı hizalama yapıldı.)

**Çözüm (derste kısmen verildi):** Kaydırmaların skorları $-12, -11, -13, -8, -10, 5, -14, -2, -7, -4, -9, -9, -12$'dir. En iyi skor $5$'tir:

```text
F Y G N Y K -
- D G S F N W
```

> **Çözüm (derste verilmedi):** En iyi hizalamanın kendisi derste ekranda gösterildi ama karelerde görünmüyor; yukarıdaki hizalama ve skorlar BLOSUM62 değerleriyle python ile hesaplandı: Y/D $-3$, G/G $6$, N/S $1$, Y/F $3$, K/N $0$, iki uç boşluk $-2$.

### Soru 9: Tamamlanmış matristen parametreleri bulma (E1)

(ekrandan, 03:10:00) Aşağıdaki tamamlanmış dinamik programlama hizalama matrisine göre soruları cevaplayın:

```text
       -    H    E    A    G
  -    0    0    0    0    0
  A    0   -1   -1    4   -1
  W    0   -1   -2   -1    3
  H    0    4   -1   -3   -2
  E    0   -1    8    3   -2
```

a. Bu bir Needleman-Wunsch (global), Smith-Waterman (lokal) ya da örtüşme hizalaması mıdır?
b. Eşleşme skoru parametresi neydi?
c. Uyuşmazlık skoru parametresi neydi?
d. Boşluk cezası parametresi neydi?

**Çözüm (derste kısmen verildi):** a. İlk satır ve sütun sıfırdır, ama matriste negatif değerler vardır; lokal hizalamada negatif değer olamayacağı için bu bir **örtüşme hizalamasıdır** (derste verildi). d. Hoca boşluk cezasını $-5$ olarak verdi.

> **Çözüm (derste verilmedi):** b. A satırı/A sütunu hücresi: köşegen $0$ + eşleşme $= 4$, diğer seçenekler $0 + w$ olduğundan eşleşme skoru $4$'tür. c. A satırı/H sütunu hücresi: köşegen $0$ + uyuşmazlık $= -1$, yani uyuşmazlık skoru $-1$'dir. d. W satırı/A sütunu hücresi $-1$'dir: köşegen $-1 + (-1) = -2$, sol $-2 + w$, üst $4 + w$; en büyüğün $-1$ olması için $4 + w = -1$, yani $w = -5$. Eşleşme $4$, uyuşmazlık $-1$, boşluk $-5$ ve örtüşme kurallarıyla matris python ile yeniden üretildi ve bütün hücreler slayttakiyle aynı çıktı.

### Soru 10: Global hizalama matrisinden hizalamaları bulma (E2)

(derste sözlü, 03:12:39) Bir global hizalamanın tamamlanmış matrisi verildiğinde dizilerin hizalamasını belirleyin.

**Çözüm (derste kısmen verildi):** Hoca aynı skoru veren üç hizalama olduğunu ve sağ alt köşedeki hücre $0$ olduğu için hepsinin skorunun $0$ olduğunu söyledi. <!-- BELİRSİZ: Matris ve diziler karelerde görünmüyor; hizalamalar yazılamadı. -->

## Dersin Toparlaması

Bu derste iki dizinin hizalamasının nasıl değerlendirileceği ve bulunacağı ele alındı. Önce bir skorlama şemasının hizalamaları nesnel olarak karşılaştırmayı sağladığı gösterildi. Ardından görsel bir yöntem olan dot plot anlatıldı: kuruluşu iki döngüden ibarettir; köşegenler, paralel çizgiler, ters çizgiler ve kopukluklar sırasıyla benzerliği, tekrarları, ters tekrarları ve indel'leri gösterir. Rastgele eşleşmelerden doğan gürültü kayan pencereyle azaltılır, ama dot plot optimal hizalamayı bulmakta yetersiz kalır.

Optimal hizalama için kaba kuvvetin üstel maliyeti ile dinamik programlama karşılaştırıldı. Dinamik programlamanın başlatma, doldurma ve geri izleme adımları; global (Needleman-Wunsch), lokal (Smith-Waterman) ve örtüşme hizalamaları üzerinden aynı örnekle gösterildi. Üç tür arasındaki fark başlatma, sıfırlama ve geri izlemenin başlangıç hücresindedir. Son olarak BLOSUM62 gibi biyolojik temelli yer değiştirme matrislerine giriş yapıldı. Hoca, skorlama şemasının uygunluğu, boşluk cezaları ve hizalamanın anlamlılığının sonraki derslerde ele alınacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
