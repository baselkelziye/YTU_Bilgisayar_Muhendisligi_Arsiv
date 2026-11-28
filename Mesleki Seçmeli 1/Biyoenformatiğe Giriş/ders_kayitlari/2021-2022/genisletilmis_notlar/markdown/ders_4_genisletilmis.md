# Ders 4 Genişletilmiş Notu: Filogenetik Kavramlar ve Filogenetik Ağaç Kurma Yöntemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Filogenetik nedir?
- 2. Moleküler filogenetiğin gelişimi ve moleküler verinin üstünlükleri
- 3. Bir filogeniyi yorumlama: dendrogram, kladogram, topoloji
- 4. Ağaç terimleri, köklü ve köksüz ağaçlar
- 5. Ağaç sayısı
- 6. Monofiletik ve parafiletik gruplar, gen ağacı ve tür ağacı
- 7. Karakter ve uzaklık verisi
- 8. Filogenetik ağaç kurma yöntemleri ve karşılaştırmaları
- 9. Uzaklık tabanlı yöntemler: UPGMA
- 10. Dal uzunluklarının kestirimi
- 11. Komşuluk ilişkisi yöntemi ve komşu birleştirme
- 12. Karakter tabanlı yöntemler: maksimum parsimoni
- 13. Maksimum olabilirlik
- 14. Ağaç güvenilirliği: bootstrap ve parametrik testler
- 15. Uygulamalar ve hata kaynakları
- Örnek Sorular

## 1. Filogenetik nedir?

Ders, önceki derslerde defalarca anılan filogenetik ağaçların ve onların nasıl kurulduğunun anlatılacağı bir giriş olarak başladı. Ders büyük ölçüde İngilizce anlatıldı; slaytlarda anahtar terimler mavi yazıyla vurgulandı.

Filogenetik (phylogenetics), organizmalar arasındaki evrimsel ilişkileri inceleyen bilimdir. Taksonomiyi de içine alan daha geniş sistematik (systematics) alanının bir parçasıdır. Slayta göre evrimsel biyolojinin bağlamı filogenidir (phylogeny) (ekrandan, 00:05:00): bütün organizma grupları arasındaki bağlantılar, ata-torun (ancestor-descendant) ilişkileri üzerinden anlaşılır. Türler aynı ortak atalardan evrimleştikleri için birbirleriyle akrabadır. Türlerin bu ilişkisine filogeni, grafik gösterimine filogenetik ağaç denir.

Hoca basit bir örnek ağaç gösterdi. Ağaçta kemirgenler, primatlar, keseliler, timsahlar, kuşlar, kertenkeleler ve yılanlar vardı. Ağaç şöyle okunur: timsahlar ile kuşlar yakın akrabadır; kertenkeleler ile yılanlar yakın akrabadır; kemirgenler ile primatlar yakın akrabadır ve bu grup keselilerle akrabadır. Dalların birleştiği her nokta, o grupların ortak bir atadan geldiğini gösterir.

### 1.1 Köken bilgisi

Terimlerin kökeni bir slaytta verildi (ekrandan, 00:10:00):

- *phyl-* (ya da *phylo-*): Latince, Yunanca *phylē* ve *phylon* sözcüklerinden gelir; anlamı kabileler, ırklar ya da şubelerdir (phyla).
- *phyla*: bir grup içindeki doğrudan soy hattı.
- *genetics* (genetic + -ics): Yunanca *genetikos*, o da *genesis* (köken, başlangıç noktası) sözcüğünden gelir; "köken yasaları" anlamında 1872'den, kalıtım çalışması anlamında 1891'den beri kullanılır.
- *phylogeny*: bir organizma türünün evrim tarihi; genetik olarak akraba bir organizma grubunun evrimi.
- *phylogenetics*: filogeniyle uğraşan bilim dalı.

## 2. Moleküler filogenetiğin gelişimi ve moleküler verinin üstünlükleri

Hoca kısa bir tarihçe verdi. 1960'lar ile 1970'ler arasında protein dizileme yöntemleri, elektroforez, DNA hibridizasyonu ve kısaca PCR denen polimeraz zincir tepkimesi, moleküler filogenetikte bir patlamaya katkıda bulundu. Hoca, PCR'ın günümüzde özellikle COVID-19 testlerinde yoğun kullanıldığını hatırlattı. 1970'lerin sonundan bugüne moleküler filogenetikle birçok keşif yapıldı; örnek olarak endosimbiyoz (1978) verildi. Birçok "yaşam ağacı" projesi tamamlanmış ya da sürmektedir.

<!-- BELİRSİZ: Altyazıda 1987 için anılan ikinci keşfin adı bozuk ("Divergence of Fireland Kingdom"), ilgili an karelerde yok. -->

Ardından moleküler veri ile morfoloji/fizyoloji karşılaştırıldı:

| Moleküler veri | Morfoloji / fizyoloji |
|---|---|
| Kesin olarak kalıtsal birimlerdir | Çevresel etkenlerden etkilenebilir |
| Belirsizlik içermez | Yoruma açıktır |
| Düzenli ve öngörülebilir evrim | Öngörülemez evrim |
| Nicel analiz esastır | Nitel tartışma öne çıkar |
| Homoloji kolay değerlendirilir | Homoloji zor değerlendirilir |
| Uzak akraba organizmaların ilişkisi bile çıkarılabilir | Yalnız yakın akrabalıklar güvenle çıkarılır |
| PCR ve dizilemeyle bol ve kolay üretilir | Mikroorganizmalarla ve görünür morfolojisi olmayan canlılarla çalışırken sorun çıkar |

Hoca morfolojinin biçimle (şekille) ilgili olduğunu hatırlattı.

## 3. Bir filogeniyi yorumlama: dendrogram, kladogram, topoloji

"Bir filogeniyi yorumlama" slaytında (başlık ekrandan, 00:15:00; şeklin kendisi karede henüz açılmamıştı, anlatım altyazıdan) A, B, C, D ve E olmak üzere beş diziden oluşan bir ağaç ve erken başlangıçtan bugüne uzanan bir zaman ekseni gösterildi. Ağaçta dizilerin fiziksel konumu çok anlamlı değildir: B başka bir yerde, C başka bir yerde çizilebilir. Ancak dalların yer değiştirmesi (swiveling; örneğin A ile B'nin ya da D ile E'nin yer değiştirmesi) yalnız düğümlerde yapılabilir. Düğüm (node), birden çok dalın birleştiği noktadır.

### 3.1 Dendrogram

Dendrogramın sözlük anlamı "ağaç çizimi"dir. Dendrogram, hiyerarşik kümelemenin ürettiği kümelerin düzenini göstermek için sık kullanılan bir ağaç diyagramıdır; hiyerarşik kümeleme önceki derste işlenmişti. Hesaplamalı biyolojide genlerin ya da örneklerin kümelenmesini göstermek için, bazen ısı haritalarının (heatmap) üstünde kullanılır.

### 3.2 Kladogram ve topoloji

Kladogram, yalnız ağaç topolojisini gösteren bir filogenetik ağaç türüdür (ekrandan, 00:20:00); yani ağacın biçimi akrabalığı gösterir. Örneğin insanların gorillerden çok şempanzelerle yakın akraba olduğu görülür, ama türler arasında zaman ya da genetik uzaklık bilgisi yoktur. Sözcük Yunanca *klados* (dal) ve *gramma* sözcüklerinden gelir: "dal çizimi".

Topoloji, ağacın dallanma yapısıdır; dallanma örüntüsüne ağacın topolojisi denir. Ağaçlar birkaç biçimde gösterilebilir:

- **Dikdörtgen kladogram:** ağaç dikdörtgenlerle çizilir.
- **Eğik (slanted) kladogram:** yine ilişkiyi gösterir; çok sayıda tür varsa çizimi daha kolaydır.
- **Dairesel kladogram:** dallar bir daire etrafına yerleşir.

## 4. Ağaç terimleri, köklü ve köksüz ağaçlar

### 4.1 Terimler

Bir slaytta ağacın parçaları adlandırıldı (ekrandan, 00:25:00). Ağaçta kökten (root) çıkan dallar (branches), mavi iç düğümler (internal nodes) ve kırmızı uç düğümler (terminal nodes) vardı. Uçlardaki A, B, C, D, E ve F dizileri işlevsel taksonomik birimler (operational taxonomic units, OTU) ya da taksonlardır (taxa). Ağacın yapısı şöyledir:

```text
kök ──┬── (iç düğüm) ──┬── A
      │                └── (iç düğüm) ──┬── B
      │                                 └── C
      └── (iç düğüm) ──┬── (iç düğüm) ──┬── D
                       │                └── E
                       └── F
```

Aynı düğümden çıkan iki uç, örneğin D ile E ya da B ile C, kardeş (sisters) olarak adlandırılır. Bir düğümden ikiden fazla dal çıkıyorsa buna politomi (polytomy) denir. Hoca, örnekteki ağaçta bir düğüme bir dal daha eklenseydi politomi oluşacağını, mevcut durumda ise iki dalın kardeş oluşturduğunu belirtti.

### 4.2 Köklü ve köksüz ağaçlar

Köklü ağaçta (rooted tree) kök, ortak atayı gösterir. A, B, C, D, E ve F, bu ortak atadan gelen türleri ya da o türlerden alınan dizileri temsil eder. Bu diziler büyük olasılıkla mutasyon, değişiklik ya da ekleme gibi olaylarla kök diziden oluşmuştur. Köklü ağaçta kökten torunlara doğru bir zaman bileşeni vardır.

Köksüz ağaçta (unrooted tree) ortak atayı gösteren bir kök düğümü yoktur. Bu ağaç, torun türlerin ortak ataya ilişkisini değil, torun türlerin kendi aralarındaki ilişkiyi gösterir. Köksüz ağaç yalnız taksonlar arasındaki akrabalık derecesini belirtir, evrimsel yolu belirtmez.

## 5. Ağaç sayısı

$n$ tür için olası ağaç sayıları slaytta şöyle verildi (ekrandan, 00:30:00):

$$\text{Köklü ağaç sayısı} = \frac{(2n-3)!}{2^{n-2}(n-2)!} \qquad \text{Köksüz ağaç sayısı} = \frac{(2n-5)!}{2^{n-3}(n-3)!}$$

Hoca, 2, 3, 4, 5, 10, 15 ve 20 tür için köklü ve köksüz ağaç sayılarını veren bir tablo gösterdi ve köklü ağaç sayısının köksüz ağaç sayısından çok daha büyük olduğuna dikkat çekti. Örneğin beş türle 105 köklü ağaç elde edilir, ama yalnız 15 köksüz ağaç vardır. Formüllerle python'da yeniden hesaplanan değerler:

| $n$ | Köklü | Köksüz |
|---|---|---|
| 3 | 3 | 1 |
| 4 | 15 | 3 |
| 5 | 105 | 15 |
| 10 | 34.459.425 | 2.027.025 |

<!-- BELİRSİZ: Slayttaki tablonun kendisi karelerde yok; 10, 15 ve 20 tür için slayttaki değerler doğrudan okunamadı. Tablodaki 3, 4 ve 10 satırları formülden hesaplandı. -->

Ardından hoca dal uzunluklarının, örneğin nükleotit ya da amino asit değişimlerinin sayısıyla orantılı olabileceğini, bunun da uzaklık kavramıyla yakından ilişkili olduğunu söyledi.

## 6. Monofiletik ve parafiletik gruplar, gen ağacı ve tür ağacı

### 6.1 Monofiletik gruplar

Bir sınıflandırma türü de monofiletik gruplardır. Slayttaki kurgusal örnekte (ekrandan, 00:35:00) Satürn'den gelen "Saturnite 1, 2, 3" (mavi) ve Mars'tan gelen "Martian 1, 3, 2" (kırmızı) türleri vardı. Ağaçta Saturnite 1 tek başına, Saturnite 2 ile 3 birlikte bir dal oluşturur; Martian 1 ile 3 birlikte, Martian 2 ayrı bir dalda yer alır. Her renk grubu kendi ortak atasından gelir.

Monofiletik grupta gruptaki bütün taksonlar tek bir ortak atadan türemiştir ve üyeler doğal bir klad (clade) oluşturur. "Mono" tek demektir: hepsi aynı kaynaktan gelir.

### 6.2 Parafiletik gruplar

Hoca ikinci bir kurgusal örnekte farklı gezegenlerden türlerin karıştığı bir grubu gösterdi. Parafiletik grupta ortak ata gruptaki başka taksonlarla da paylaşılır ve üyeler doğal bir klad oluşturmaz.

### 6.3 Gen ağacı ve tür ağacı

Gen ağacı, tek bir homolog gen içinde gözlenen ayrışmaya (divergence) dayanan filogenetik ağaçtır. Böyle ağaçlar genin evrim tarihini gösterebilir, ama genin bulunduğu türlerin evrim tarihini göstermeyebilir. Ardından tür ağacı (species tree) tanıtıldı.

<!-- BELİRSİZ: Tür ağacının slayttaki tanımı altyazıda okunmuyor, ilgili an karelerde yok. -->

## 7. Karakter ve uzaklık verisi

Filogenetik ağaç üretmek için kullanılan moleküler veri iki kategoriden birine girer (ekrandan, 00:40:00):

- **Karakterler:** sınırlı sayıda farklı durumda bulunabilen, iyi tanımlanmış bir özellik.
- **Uzaklıklar:** iki veri kümesi arasındaki genel, ikili (pairwise) farkın ölçüsü.

Genelde uzaklıklar kullanılır; bu ölçüt dersin çok başında tanımlanmıştı. Hoca burada öğrencilere benzerliğin neyle ölçüldüğünü sordu (bkz. Örnek Sorular). Bir öğrenci önce Öklid uzaklığını önerdi; hoca benzerlik ölçüsünü istediğini söyledi ve cevap korelasyon oldu. Hoca farkı şöyle özetledi: uzaklık bir benzemezlik ölçüsü, korelasyon bir benzerlik ölçüsüdür.

Sonra iki veri kümesi arasında uzaklığın 0 ve korelasyonun 0 olması durumunu sordu. Uzaklığın 0 olması iki veri kümesinin aynı olduğu, korelasyonun 0 olması ise aralarında ilişki bulunmadığı anlamına gelir; bu iki durum birbirinin tersi gibidir.

> **Hocanın vurgusu:** Uzaklık ile korelasyon arasındaki fark, hocanın deyişiyle "iyi bir sınav sorusu"dur.

<!-- BELİRSİZ: Hocanın bu soruya verdiği cevabın tam ifadesi altyazıda bozuk ("completely ... different"); yukarıdaki yorum altyazıdaki parçalardan ve uzaklık/korelasyon tanımlarından kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** Korelasyonun 0 olması yalnız doğrusal bir ilişki olmadığını gösterir; veriler arasında doğrusal olmayan bir ilişki yine de bulunabilir.

Kategorik veride aynı sayısal ölçüler kullanılamaz; kategorik verinin uzaklık ölçüsü olarak genelde Hamming ya da Levenshtein uzaklığı kullanılır. Hoca DNA ve protein dizilerinin hangi tür veri olduğunu sordu; cevap kategorik veridir. Slayt da bunu söyler: DNA ve protein dizileri, ayrık karakter durumlarından oluşan bir kümeyi tanımlayan verilere örnektir (ekrandan, 00:45:00).

## 8. Filogenetik ağaç kurma yöntemleri ve karşılaştırmaları

Aradan sonra filogenetik ağaç kurma yöntemlerine geçildi. Yöntemler üç ana gruba ayrılır:

- **Uzaklık tabanlı yöntemler:** diziler arasındaki ikili uzaklıkları hesaplar ve en benzer dizileri gruplar (ekrandan, 01:05:00). Önce ikili uzaklıklar belirlenir, sonra bu uzaklıklara göre en benzer diziler gruplanır.
- **Karakter tabanlı yöntemler (maksimum parsimoni):** "parsimony" tutumluluk, cimrilik demektir. Bu yöntemler, farklı varlıklardaki ortak karakterlerin ortak soydan geldiğini varsayar. Gruplar bu ortak karakterlere göre kurulur ve karakterlerin evrimi için en basit açıklama, yani en tutumlu olanı doğru kabul edilir.
- **Olasılıksal yöntemler (maksimum olabilirlik):** belirli bir dizi evrimi modeli altında, veri kümesinin o veri kümesinden türetilmiş bir ağaca uyma olasılığını hesaplar.

Üç yöntemin karşılaştırması bir tabloyla verildi (ekrandan, 01:10:00):

| | Uzaklık | Maksimum parsimoni | Maksimum olabilirlik |
|---|---|---|---|
| Veri | Yalnız ikili uzaklıkları kullanır | Yalnız paylaşılan türemiş karakterleri kullanır | Bütün veriyi kullanır |
| Ölçüt | En yakın komşular arası uzaklığı en aza indirir | Toplam uzaklığı en aza indirir | Belirli parametre değerleriyle ağaç olabilirliğini en büyütür |
| Hız | Çok hızlı | Yavaş | Çok yavaş |
| Zayıflık | Yerel optimuma kolay takılır | Evrim hızlıysa varsayımlar bozulur | Varsayılan evrim modeline çok bağlıdır |
| Uygun kullanım | Geçici (başlangıç) ağaç üretmek ya da çok sayıda ağaç arasından seçmek | İşlenebilir olduğunda en iyi seçenek (<30 takson, homoplazi nadir) | Çok küçük veri kümeleri ve başka yöntemlerle kurulmuş ağaçları test etmek |

Maksimum olabilirlik bütün veriyi kullandığı için çok yavaştır. Yerel optimuma takılma, uzaklık tabanlı yöntemlerin hızına karşılık ödenen bedeldir. Hoca, bir algoritmanın içinde bir ağaca ihtiyaç varsa hızlı olduğu ve bir başlangıç ağacı verdiği için uzaklık tabanlı yöntemin en iyi seçim olduğunu söyledi; ayrıca çok sayıda ağaç üretilip en iyisi seçilebilir.

## 9. Uzaklık tabanlı yöntemler: UPGMA

Uzaklık tabanlı yöntemler dizilerden bir uzaklık (benzemezlik) matrisi oluşturur; filogenetik ağaç bu matristen bir kümeleme algoritmasıyla hesaplanır. Bu sınıfta çok sayıda yöntem vardır; temel iki örnek UPGMA ile komşu birleştirmedir (neighbor joining).

### 9.1 Yöntemin tanımı

UPGMA (Unweighted Pair Group Method with Arithmetic Mean, aritmetik ortalamalı ağırlıksız çift grup yöntemi) en eski ve en basit uzaklık matrisi yöntemidir. 1960'ların başında morfolojik karakterlerin evrimsel analizine yardım için önerildi. Yöntem, ele alınan bütün takson çiftleri arasındaki genetik uzaklığa indirgenebilen veri gerektirir.

Dört türün (A, B, C, D) ikili uzaklıkları bir alt üçgen matriste verilir (ekrandan, 01:15:00):

| Tür | A | B | C |
|---|---|---|---|
| B | $d_{AB}$ | - | - |
| C | $d_{AC}$ | $d_{BC}$ | - |
| D | $d_{AD}$ | $d_{BD}$ | $d_{CD}$ |

Burada $d_{AB}$, A ile B (ya da B ile A) arasındaki uzaklıktır. Hoca bu noktada kaç uzaklık hesaplanması gerektiğini sordu. 4×4'lük bir matriste 16 hücre vardır, ama köşegen ve simetrik yarı gereksizdir. $k$ dizi için gerçekten hesaplanması gereken uzaklık sayısı

$$\frac{k(k-1)}{2}$$

olur; 4 dizi için $4\cdot 3/2=6$, 5 dizi için $5\cdot 4/2=10$. Az sayıda dizide çiftler elle sayılabilir (AB, AC, AD, AE, BC, BD, BE, CD, CE, DE), ama 10-30'dan fazla dizide formül kullanılır.

Uzaklık burada basit bir Hamming ya da Levenshtein uzaklığı ya da başka bir uzaklık olabilir. Bazen matris skor matrisleriyle de oluşturulabilir. Bu durumda ölçüt değişir: skor matrisleri uzaklıktan farklı bir kavram olduğu için en küçük değer yerine büyük olasılıkla en büyük değer alınır. Hoca örneklerde çoğunlukla Hamming uzaklığını kullanacağını söyledi.

### 9.2 Algoritmanın adımları

```text
1. Uzaklık matrisinde en küçük uzaklığı bul (ör. d_AB).
2. Bu iki türü tek bir bileşik grupta birleştir (AB).
3. Yeni grubun diğer türlere uzaklığını aritmetik ortalamayla hesapla:
     d_(AB),C = (d_AC + d_BC) / 2
     d_(AB),D = (d_AD + d_BD) / 2
4. İndirgenmiş matrisle 1. adıma dön; bütün türler gruplanana kadar sürdür.
5. Ölçekli dal uzunlukları isteniyorsa dal noktasını, birleştirilen
   türler arasındaki uzaklığın yarısına koy (ilk adımda d_AB / 2).
```

### 9.3 Beş diziyle UPGMA örneği

Beş farklı DNA dizisi arasındaki hizalama verildi (ekrandan, 01:25:00):

```text
             10          20          30          40          50
A:  GTGCTGCACGG  CTCAGTATA  GCATTTACCC  TTCCATCTTC  AGATCCTGAA
B:  ACGCTGCACGG  CTCAGTGCG  GTGCTTACCC  TCCCATCTTC  AGATCCTGAA
C:  GTGCTGCACGG  CTCGGCGCA  GCATTTACCC  TCCCATCTTC  AGATCCTATC
D:  GTATCACACGA  CTCAGCGCA  GCATTTGCCC  TCCCGTCTTC  AGATCCTAAA
E:  GTATCACATAG  CTCAGCGCA  GCATTTGCCC  TCCCGTCTTC  AGATCTAAAA
```

Hizalamada boşluk (gap, indel) yoktur, bu yüzden basit Hamming uzaklığı yeterlidir. Hoca Hamming uzaklığı için neyin sayıldığını sordu: uyuşmazlıklar (mismatch). A ile B karşılaştırılırken G-A birinci, T-C ikinci uyuşmazlıktır ve sayım böyle sürer; A ile B arasında toplam 9 uyuşmazlık vardır. Bütün çiftlerin uzaklıkları (ekrandan, 01:30:00):

| Tür | A | B | C | D |
|---|---|---|---|---|
| B | 9 | - | - | - |
| C | 8 | 11 | - | - |
| D | 12 | 15 | 10 | - |
| E | 15 | 18 | 13 | 5 |

Bu on değer, yukarıdaki hizalamadan python ile yeniden sayıldı ve slayttaki tabloyla birebir aynı çıktı.

**1. adım.** En küçük uzaklık $d_{DE}=5$ olduğu için D ve E birleştirilir ve DE grubu oluşur. DE'nin diğer türlere uzaklıkları:

$$d_{DE,A}=\frac{d_{DA}+d_{EA}}{2}=\frac{12+15}{2}=13.5,\quad d_{DE,B}=\frac{15+18}{2}=16.5,\quad d_{DE,C}=\frac{10+13}{2}=11.5$$

İndirgenmiş matris (ekrandan, 01:30:00):

| Tür | A | B | C |
|---|---|---|---|
| B | 9 | - | - |
| C | 8 | 11 | - |
| DE | 13.5 | 16.5 | 11.5 |

**2. adım.** Bu matristeki en küçük değer $d_{AC}=8$ olduğundan A ve C birleştirilerek AC grubu oluşur. Yeni uzaklıklar yine ortalamayla bulunur:

$$d_{AC,B}=\frac{9+11}{2}=10,\qquad d_{AC,DE}=\frac{13.5+11.5}{2}=12.5,\qquad d_{B,DE}=16.5$$

| Tür | B | AC |
|---|---|---|
| AC | 10 | - |
| DE | 16.5 | 12.5 |

**3. adım.** Sonraki en küçük değer 10'dur; B, AC grubuna katılır ve ACB grubu oluşur. **4. adım:** Son olarak ACB grubu DE ile birleşir ve hiyerarşik kümeleme ağacı tamamlanır.

> **Çözüm (derste verilmedi):** Son adımın sayısal değeri karelerde görünmüyor. Slayttaki "iki değerin ortalaması" kuralı sürdürülürse $d_{ACB,DE}=(12.5+16.5)/2=14.5$ olur. Grup büyüklüklerine göre ağırlıklandırılan klasik UPGMA ise bütün çiftlerin ortalamasını alır: $d_{ACB,DE}=(13.5+11.5+16.5)/3\approx 13.83$. İlk iki adımda birleşen gruplar eşit büyüklükte olduğu için iki yol aynı sonucu verir; fark yalnız son adımda ortaya çıkar (python ile hesaplandı).

Sonuçta ortaya çıkan topoloji:

```text
        ┌── A
     ┌──┤
  ┌──┤  └── C
  │  └───── B
──┤
  │  ┌── D
  └──┤
     └── E
```

## 10. Dal uzunluklarının kestirimi

### 10.1 UPGMA'da dal uzunlukları

Bulunan ağaç yalnız dizilerin akrabalığını gösterir. Ağacın topolojisi, dizilerin ne kadar ayrıştığı hakkında da bilgi taşıyabilir; bu bilgiyi taşıyan ölçekli ağaçlar da sık sık kladogram diye anılır. Dalların uzunluğu, dizilerin bağımsız olarak değişim biriktirdiği tahmini süreye karşılık gelir. Her dalın göreli uzunluğu uzaklık matrisindeki bilgiyle hesaplanabilir.

Slayt 30'daki türlerden dördü için ölçekli ağaç gösterildi (ekrandan, 01:35:00): A ve C dalları 4'er, D ve E dalları 2.5'er, alttaki iki iç dal 6.25'er olarak etiketlenmişti; dikey eksen zamandı. A ile C arasındaki toplam uzaklık $4+4=8$, D ile E arasındaki $2.5+2.5=5$'tir. Dallar bütün türler arasındaki fark miktarını yansıtacak biçimde ölçekli çizilir. Slayta göre bu çok basit dal uzunluğu kestirimi, UPGMA'nın doğal olarak köklü filogenetik ağaçlar üretmesini sağlar.

> **Ders sonrası not:** AC ile DE arasındaki uzaklık 12.5 olduğundan kök, uçlardan $12.5/2=6.25$ yüksekliktedir. Slayttaki 6.25 etiketleri büyük olasılıkla bu kök yüksekliğini gösterir. İç dalların kendi uzunlukları ise $6.25-4=2.25$ (AC kolu) ve $6.25-2.5=3.75$ (DE kolu) olur; yoksa A ile D arasındaki ağaç yolu 12 yerine 19 çıkardı.

<!-- BELİRSİZ: Hocanın bu ağaçla ilgili söylediği "A, C ve B arasında toplam 5.5" ifadesi altyazıda bozuk; hangi uzaklığı kastettiği anlaşılmıyor. -->

### 10.2 Üç dizide dal uzunlukları

Evrim hızlarının bütün soy hatlarında aynı olduğu varsayılamıyorsa ölçekli ağacın dal uzunluklarını bulmak biraz daha karmaşıktır. Anlamlı dal uzunluğu taşıyabilecek en basit ağaç, üç tür ve tek dal noktası olan köksüz ağaçtır. A, B ve C dizileri için dallara $a$, $b$ ve $c$ denir (ekrandan, 01:40:00). Üç dizide tek bir ağaç topolojisi vardır ve toplam uzaklık sayısı üçtür. Tanıma göre:

$$a+b=d_{AB},\qquad b+c=d_{BC},\qquad a+c=d_{AC}$$

Girdi $d_{AB}$, $d_{BC}$ ve $d_{AC}$ ikili uzaklıklarıdır; çıktı dal uzunluklarıdır:

$$a=\frac{d_{AB}+d_{AC}-d_{BC}}{2},\qquad b=\frac{d_{AB}+d_{BC}-d_{AC}}{2},\qquad c=\frac{d_{AC}+d_{BC}-d_{AB}}{2}$$

Hoca bunun ağaç üzerinden de türetilebildiğini gösterdi: $d_{AB}+d_{AC}=(a+b)+(a+c)$ toplamından $d_{BC}=b+c$ çıkarılınca $b$ ve $c$ birbirini götürür, geriye $2a$ kalır; ikiye bölünce $a$ bulunur. $b$ ve $c$ de aynı yolla elde edilir.

Ardından üç diziyle sayısal bir örnek gösterildi; bulunan değerler dalların üstüne yazılarak köksüz ağaç tamamlandı.

<!-- BELİRSİZ: Üç dizili sayısal örneğin uzaklıkları ve sonuçları karelerde yok; altyazıda yalnız "12", "a = 10", "c = 29" gibi parçalar seçiliyor, bunlar tutarlı bir çözüm oluşturmuyor. -->

## 11. Komşuluk ilişkisi yöntemi ve komşu birleştirme

### 11.1 Komşuluk ilişkisi ve dört nokta koşulu

Komşuluk ilişkisi yöntemi (neighbor's relation) UPGMA'ya çok benzer, yaygın bir türevidir. Bir filogenetik ağacın topolojisi, üç dizide görüldüğü gibi komşular arasında yararlı cebirsel ilişkiler doğurur. Dört dizide (A, B, C, D) A ile B, C ile D komşu olsun ve iki iç düğüm arasındaki dal $e$ olsun. Altı ikili uzaklık vardır. Bu topolojide

$$d_{AC}+d_{BD}=d_{AD}+d_{BC}=a+b+c+d+2e=d_{AB}+d_{CD}+2e$$

olur ve bu denklemlerden $a$, $b$, $c$, $d$ ve $e$ dal uzunlukları türetilebilir. Bundan dört nokta koşulu (four-point condition) olarak bilinen şu eşitsizlikler çıkar (ekrandan, 02:00:00):

$$d_{AB}+d_{CD} < d_{AC}+d_{BD}\ ;\qquad d_{AB}+d_{CD} < d_{AD}+d_{BC}$$

Komşuluk yaklaşımı dört türün bütün olası ikili düzenlemelerini dener ve dört nokta koşulunu hangi düzenlemenin sağladığını belirler.

Dört nokta koşulunun önemli bir varsayımı, filogenetik ağaçtaki dal uzunluklarının toplanabilir (additive) olmasıdır. Yöntem bu varsayımdan sapmalara çok duyarlı değildir, ama toplanabilir olmayan veri kümeleri yöntemin yanlış topolojili bir ağaç üretmesine yol açabilir.

Hoca dört diziyle bir örnek gösterdi: diziler konum konum karşılaştırılarak uzaklık matrisi kuruldu (örneğin $d_{AC}=7$, $d_{AD}=8$), dal uzunlukları da bu uzaklıklardan bulundu.

<!-- BELİRSİZ: Dört dizili örneğin dizileri, uzaklık matrisinin tamamı ve dal uzunlukları karelerde yok; altyazıda dal uzunlukları için yalnız "2, 1, 4, 1, 2" parçası duyuluyor. -->

### 11.2 Komşu birleştirme

Komşu birleştirme yönteminin (neighbor joining) adımları (ekrandan, 02:05:00):

- Girdi $n\times n$'lik bir benzemezlik/uzaklık matrisi $d$'dir.
- İlk yinelemede $n$ yaprağın her biri kendi kümesindedir; her yaprak tek başına en basit kümeyi oluşturur.
- Sonraki yinelemelerde her küme bir yaprak kümesidir ve kümeler ayrıktır. Her yinelemenin başında taksonlar kümelere bölünmüştür; her küme için, kümedeki öğelerle etiketlenmiş yaprakları olan köklü bir ağaç vardır.
- Sonunda kök yok sayılır; bu yüzden komşu birleştirme aslında köksüz bir ağaç döndürür.

Hoca bir kaynaktan alınmış özet bir slayt da gösterdi.

## 12. Karakter tabanlı yöntemler: maksimum parsimoni

### 12.1 Parsimoni ilkesi

Parsimoni kavramı, karakter tabanlı bütün filogenetik yeniden kurma yöntemlerinin merkezindedir. "Parsimonious" sözcüğü parasını harcarken özellikle dikkatli olan, yani tutumlu, cimri kişi için kullanılır. Filogenetik ağaçlar, iki ya da daha fazla dizinin evrim tarihini betimleyen kuramsal modellerdir. Biyolojik parsimoninin iki basit öncülü vardır:

- Mutasyonlar son derece nadir olaylardır.
- Bir model ne kadar çok olası olmayan olay gerektirirse, doğru olma olasılığı o kadar azdır.

Sonuç olarak, dizilerin bugünkü durumunu açıklamak için en az mutasyon gerektiren ilişki, doğru olma olasılığı en yüksek ilişkidir.

### 12.2 Bilgi verici ve bilgi vermeyen konumlar

Dört dizili, altı konumlu kısa bir çoklu hizalama gösterildi (ekrandan, 02:10:00):

| Dizi | 1 | 2 | 3 | 4 | 5* | 6* |
|---|---|---|---|---|---|---|
| 1 | G | G | G | G | G | G |
| 2 | G | G | G | A | G | T |
| 3 | G | G | A | T | A | G |
| 4 | G | A | T | C | A | T |

Konumlar parsimoni analizi için bilgi içeriklerine göre iki kategoriye ayrılır: bilgi taşıyanlar (informative) ve taşımayanlar (uninformative). Dört dizi arasındaki ilişki yalnız üç farklı köksüz ağaçla betimlenebilir: (1,2)(3,4), (1,3)(2,4) ve (1,4)(2,3).

- **1. konum:** Değişmeyen (invariant) konumlar açıkça bilgi vermez, çünkü üç ağacın her biri aynı sayıda, yani sıfır mutasyon gerektirir.
- **2. konum:** Üç ağacın hepsinde tek bir mutasyon (A ile G arasında) gerektiği için bilgi vermez.
- **3. konum:** Bütün ağaçlar iki mutasyon gerektirdiği için bilgi vermez.
- **4. konum:** Bütün ağaçlar üç mutasyon gerektirdiği için bilgi vermez.
- **5. konum:** Bilgi vericidir; ağaçlardan biri yalnız bir mutasyon gerektirir, diğer iki alternatif ağaç ikişer mutasyon gerektirir.
- **6. konum:** Bilgi vericidir; yine ağaçlardan biri yalnız bir mutasyon, diğer ikisi ikişer mutasyon gerektirir.

Bu sayılar her konum ve her ağaç için python ile (Fitch sayımıyla) yeniden hesaplandı. 5. konumda en tutumlu ağaç (1,2)(3,4), 6. konumda (1,3)(2,4)'tür:

| Konum | (1,2)(3,4) | (1,3)(2,4) | (1,4)(2,3) |
|---|---|---|---|
| 1 | 0 | 0 | 0 |
| 2 | 1 | 1 | 1 |
| 3 | 2 | 2 | 2 |
| 4 | 3 | 3 | 3 |
| 5 | 1 | 2 | 2 |
| 6 | 2 | 1 | 2 |

Genel kural (ekrandan, 02:15:00): kaç dizi hizalanmış olursa olsun, bir konumun bilgi verici olması için en az iki farklı nükleotit bulunmalı ve bu nükleotitlerin her biri en az iki kez yer almalıdır. Bütün parsimoni programları işe bu basit kuralı veri kümesine uygulayarak başlar. Slayt 50'deki hizalamanın altı konumundan dördü bu yüzden atılır ve parsimoni analizinde bir daha ele alınmaz.

Oysa bu konumların hepsi, uzaklık tabanlı bir yaklaşımda kullanılan ikili benzerlik skorlarına katkıda bulunurdu. Bu fark tek başına iki yaklaşımın vardığı sonuçlar arasında önemli farklar doğurabilir.

### 12.3 Yöntemin uygulanması

Bilgi verici konumlar belirlenip bilgi vermeyenler atıldıktan sonra, parsimoni yaklaşımı en basit biçimiyle kolayca uygulanır. Her bilgi verici konum için her olası ağaç ayrı ayrı ele alınır. Her ağaç için, her konumda gereken en az değişim sayısını tutan bir sayaç işletilir. Bütün bilgi verici konumlar ele alındıktan sonra en az toplam değişim gerektiren ağaç ya da ağaçlar en tutumlu (most parsimonious) olarak etiketlenir.

Maksimum parsimoni yöntemleri, dizilerdeki gözlenen çeşitliliği üretmek için gereken adım sayısını en aza indiren evrim ağacını tahmin eder:

```text
1. Daha önce görülen yöntemlerden biriyle çoklu dizi hizalaması elde et.
2. Hizalanmış her konum için, gözlenen değişimi en az evrimsel
   değişiklikle üreten filogenetik ağaçları belirle.
3. Bunu hizalamadaki her konum için sürdür.
4. Bütün konumlar üzerinden en az toplam değişiklik üreten ağaçları seç.
```

Bu, açıkça zaman alan bir algoritmadır ve yalnız diziler arasında güçlü benzerlik varsa iyi çalışır. Dört dizide üç olası ağaç vardır; en iyi ağaç, her ağaç için bilgi verici konumlardaki değişiklik sayıları toplanarak ve en az toplam değişiklik gerektiren ağaç seçilerek bulunur. Çok sayıda dizide incelenecek ağaç sayısı o kadar büyür ki bütün ağaçları incelemek mümkün olmayabilir. Hoca, slaytlarda yöntemin tanımının bilerek birkaç kez tekrarlandığını, amacın kavramı netleştirmek olduğunu söyledi.

### 12.4 Dört diziyle parsimoni örneği

S1, S2, S3 ve S4 dizileriyle bir örnek çözüldü. Her olası ağaç için dallar boyunca gereken değişiklikler (C'den T'ye, C'den G'ye, T'den A'ya gibi) tek tek sayıldı. (S1,S3)(S2,S4) ağacı için toplam 7, (S1,S4)(S2,S3) ağacı için yine 7 değişiklik bulundu; kalan ağaç 6 değişiklik gerektirdiği için daha tutumlu olan bu ağaç seçildi.

<!-- BELİRSİZ: Örneğin dizileri karelerde yok (ilgili kare yalnız slayt başlığını gösteriyor); seçilen ağacın büyük olasılıkla (S1,S2)(S3,S4) olduğu, altyazıdaki "7, 7 ve 6" sayılarından çıkarıldı. -->

## 13. Maksimum olabilirlik

Maksimum olabilirlik yöntemi, maksimum parsimoni gibi bütün olası ağaçları oluşturur. Ancak en kısa evrimsel adımlı ağaçları tutmak yerine, farklı geçiş (transition) ve dönüşüm (transversion) oranlarının kullanılabildiği bir evrim modeli uygular. Üretilen her ağaç için, dizi verisinin her konumunu yansıtma olasılığı hesaplanır; hesaplama bütün nükleotit konumları için tekrarlanır. Sonunda en iyi olasılığa sahip ağaç maksimum olabilirlik ağacı olarak gösterilir. Bu sürecin sonunda genelde tek bir ağaç kalır.

Yöntem, bütün dallar için eşit geçiş/dönüşüm oranı varsaymadığı için daha gerçekçi bir ağaç kestirimidir.

> **Ek bilgi (derste anlatılmadı):** Geçiş, aynı sınıftan iki baz arasındaki değişimdir (pürinler arası A↔G ya da pirimidinler arası C↔T); dönüşüm ise bir pürin ile bir pirimidin arasındaki değişimdir. Doğada geçişler genelde dönüşümlerden daha sık görülür.

## 14. Ağaç güvenilirliği: bootstrap ve parametrik testler

Bütün filogenetik ağaçlar, bir veri kümesini oluşturan dizilerin evrim tarihine ilişkin hipotezlerdir (ekrandan, 02:25:00). Her iyi hipotez gibi, altta yatan veriyi ne kadar iyi betimlediği konusunda iki soru sormak yerindedir:

- Ağacın bütününe ve bileşenlerine (dallarına) ne kadar güvenilebilir?
- Bir ağacın doğru olma olasılığı, belirli ya da rastgele seçilmiş alternatif bir ağaca göre ne kadar fazladır?

Birinci soru için bootstrap denen güçlü bir yeniden örnekleme tekniği yaygın tercih hâline gelmiştir. İkinci soru için genelde iki ağacın basit bir parametrik karşılaştırması kullanılır.

### 14.1 Bootstrap

Bootstrap analizi, evrim ağacındaki belirli dalların güvenilirliğini test eden bir istatistiksel analizdir. İstatistikte yerine koyarak rastgele örneklemeye dayanan her test ya da ölçüye bootstrap denir; yeniden örnekleme (resampling) yöntemleri sınıfına girer. Kişinin kendi verisinden, yerine koyarak yeniden örnekleme yapılır ve özgün veriyle aynı büyüklükte bir dizi bootstrap örneği oluşturulur.

Bir örnekte 10 karakter uzunluğundaki, beş dizili bir veri kümesi için bootstrap testi gösterildi: konumlar bir rastgele sayı üretecinden gelen sayılarla seçilerek yeniden örneklenmiş veri kümeleri oluşturuldu. Üç yeniden örneklenmiş veri kümesinden elde edilen uzlaşı ağacında (consensus tree), daire içindeki değerler 1 ile 2 dizilerinin ve 4 ile 5 dizilerinin kümelenmesini destekleyen bootstrap ağaçlarının oranını gösteriyordu.

İkinci örnekte (ekrandan, 02:30:00) altı canlıdan 10 konumluk diziler (konumlar 0-9) kullanıldı:

```text
          0123456789
rat       GAGGCTTATC
human     GTGGCTTATC
turtle    GTGCCCTATG
fruitfly  CTCGCCTTTG
oak       ATCGCTCTTG
duckweed  ATCCCTCCGG
```

Bu örnekten çıkarılan ağaçta (inferred tree) sıçan ile insan, sonra bu ikisi ile kaplumbağa bir grup; meşe ile su mercimeği (duckweed) ayrı bir grup oluşturur, meyve sineği ayrı bir dalda kalır. Sözde örnekler (pseudo sample) konum indisleri yerine koyarak seçilerek oluşturulur. Slayttaki iki sözde örnek:

```text
Pseudo sample 1          Pseudo sample 2
          00112223455667           445556777888899
rat       GGAAGGGGCTTTTA  rat       CCTTTTAAATTTTCC
human     GGTTGGGGCTTTTA  human     CCTTTTAAATTTTCC
turtle    GGTTGGGCCCCTTA  turtle    CCCCCTAAATTTTGG
fruitfly  CCTTCCCGCCCTTT  fruitfly  CCCCCTTTTTTTTGG
oak       AATTCCCGCTTCCT  oak       CCTTTCTTTTTTTGG
duckweed  AATTCCCCCTTCCC  duckweed  CCTTTCCCCGGGGGG
```

Örneğin sözde örnek 1'in indis dizisi 0,0,1,1,2,2,2,3,4,5,5,6,6,7'dir; bu indisler sıçan dizisine uygulanınca GGAAGGGGCTTTTA elde edilir. İki sözde örneğin bütün satırları, indisler özgün dizilere uygulanarak python ile yeniden üretildi. Slayta göre pratikte çok daha fazla, 100 ile 1000 arasında kopya (replicate) üretilir. Değerler yüzde olarak verilir; yerleşik uygulamaya göre yalnız %60 ile %100 arasındaki değerler gösterilir.

> **Ders sonrası not:** Slayttaki sözde örnekler 14 ve 15 konum uzunluğunda; bootstrap tanımına göre sözde örnek özgün veriyle (10 konum) aynı büyüklükte olmalıdır. Slayttaki örnek büyük olasılıkla yalnız yeniden örnekleme fikrini göstermek için çizilmiştir.

### 14.2 Parametrik testler

Sık sorulan bir soru şudur: en tutumlu ağaç, daha önce öne sürülmüş belirli bir alternatif ağaçtan ne kadar daha olasıdır? Parsimoni analizinde bu tür sorulara cevap vermek için geliştirilen ilk parametrik testlerden biri Kishino ve Hasegawa'nınkidir. İki ağacın gerektirdiği değişiklik sayılarının farkı $D$ için varyans $V$, bilgi verici konumların her biri ayrı ayrı ele alınarak hesaplanır; burada $n$ bilgi verici konum sayısıdır. Ardından $n-1$ serbestlik dereceli eşleştirilmiş t testi ile "iki ağaç birbirinden farklı değildir" sıfır hipotezi test edilir. Hoca öğrencilerin t testi denklemini hatırlaması gerektiğini söyledi. Filogenetik ağaçlar için başka alternatif parametrik testler de vardır.

<!-- BELİRSİZ: Kishino-Hasegawa testinin slayttaki formülleri karelerde yok. -->

## 15. Uygulamalar ve hata kaynakları

Moleküler filogenetikle yapılan bazı keşifler:

- Evrensel yaşam ağacı.
- Endosimbiyoz, yani mitokondri ve kloroplastın kökeni: alfa-mor bakterilerden ve siyanobakterilerden türeyen mitokondri ve kloroplast, ayrı endosimbiyotik olaylarla oluşmuştur.
- Türler arası ilişkiler; örneğin HIV alt tipleri ya da COVID'in farklı varyantları arasındaki ilişkiler.

Her yöntemde olduğu gibi filogenetik ağaçlarda da sorunlar ve hatalar vardır:

- Farklı ağaç kurma yöntemlerinin kendine özgü zayıflıkları; bunlar yöntemler anlatılırken avantajlarıyla birlikte ele alındı.
- Küçük veri kümeleri ya da sınırlı örnekleme; bu yüzden veri kümesinin büyüklüğü yeterli olmalıdır.
- Mutasyonlar, duplikasyonlar, inversiyonlar, eklemeler ve silmeler yanlış sinyaller verebilir. Genomik sıcak noktalar (hotspot), yani hızlı evrimleşen küçük bölgeler kolayca fark edilmez.
- Homoplazi.
- Yöntemden kaynaklanan hata olarak örnek kirlenmesi ya da yanlış etiketleme; büyük veri kümeleriyle çalışırken toplanan örneğin bir şekilde kirlenmesi ya da yanlış etiketlenmesi her zaman olasıdır.

> **Ek bilgi (derste anlatılmadı):** Homoplazi, ortak atadan gelmeyen benzerliktir; örneğin aynı karakter durumunun iki soy hattında bağımsız olarak ortaya çıkması (yakınsak evrim) ya da bir değişimin geri dönmesi. Bu durum, iki taksonu gerçekte olduğundan daha yakın akraba gösterebilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:38:04): İki veri kümesi arasındaki benzerlik neyle ölçülür? Uzaklık ile korelasyon arasındaki fark nedir?

> **Cevap (derste verildi):** Benzerlik korelasyonla ölçülür. Uzaklık bir benzemezlik ölçüsü, korelasyon bir benzerlik ölçüsüdür.

**Soru 2** (derste sözlü, 00:40:34): İki veri kümesi arasında uzaklık 0 ve korelasyon 0 bulunmuştur. Bu veri kümelerinin benzerliği hakkında ne söylenebilir?

> **Çözüm (derste verilmedi):** Hocanın cevabı altyazıda net değil. Uzaklığın 0 olması iki veri kümesinin özdeş olduğunu gösterir; korelasyonun 0 olması ise aralarında (doğrusal) bir ilişki bulunmadığını gösterir.

**Soru 3** (derste sözlü, 00:44:37): DNA ve protein dizileri kategorik mi, sayısal mı veridir? Kategorik veride uzaklık ölçüsü olarak ne kullanılır?

> **Cevap (derste verildi):** Kategorik veridir; ayrık karakter durumlarından oluşur. Kategorik veride genelde Hamming ya da Levenshtein uzaklığı kullanılır.

**Soru 4** (derste sözlü, 01:15:00): $n$ dizi verildiğinde kaç ikili uzaklık hesaplanmalıdır? Dört dizilik bir matriste kaç hücre vardır?

> **Cevap (derste verildi):** 4×4 matriste 16 hücre vardır, ama gerçekten hesaplanması gereken uzaklık sayısı $k(k-1)/2$'dir: 4 dizi için $4\cdot3/2=6$.

**Soru 5** (derste sözlü, 01:23:47): Beş tür için kaç uzaklık değeri hesaplanmalıdır?

> **Cevap (derste verildi):** $5\cdot4/2=10$: AB, AC, AD, AE, BC, BD, BE, CD, CE, DE.

**Soru 6** (derste sözlü, 01:25:27): İki dizi arasındaki Hamming uzaklığı bulunurken neyin sayısı sayılır?

> **Cevap (derste verildi):** Uyuşmazlıkların (mismatch) sayısı. Bölüm 9.3'teki hizalamada A ile B arasında 9 uyuşmazlık vardır.

**Soru 7** (ekrandan, 01:25:00 ve 01:30:00): Bölüm 9.3'teki beş DNA dizisi için Hamming uzaklık matrisini kurun ve UPGMA ile ağacı oluşturun.

> **Cevap (derste verildi):** Uzaklık matrisi Bölüm 9.3'teki tablodur. Birleştirme sırası: önce D ile E (5), sonra A ile C (8), sonra AC ile B (10), en son ACB ile DE. Ara matrisler: $d_{DE,A}=13.5$, $d_{DE,B}=16.5$, $d_{DE,C}=11.5$; $d_{AC,B}=10$, $d_{AC,DE}=12.5$.

**Soru 8** (ekrandan, 00:30:00): Beş tür için kaç köklü ve kaç köksüz ağaç vardır?

> **Cevap (derste verildi):** Köklü: $\dfrac{7!}{2^{3}\cdot 3!}=\dfrac{5040}{48}=105$. Köksüz: $\dfrac{5!}{2^{2}\cdot 2!}=\dfrac{120}{8}=15$.

**Soru 9** (ekrandan, 02:10:00): Bölüm 12.2'deki dört dizili, altı konumlu hizalamada hangi konumlar parsimoni açısından bilgi vericidir?

> **Cevap (derste verildi):** Yalnız 5. ve 6. konumlar. 1-4. konumlarda üç olası ağacın hepsi aynı sayıda mutasyon (sırasıyla 0, 1, 2, 3) gerektirir; 5. ve 6. konumlarda ise ağaçlardan biri 1, diğer ikisi 2 mutasyon gerektirir. Kural: en az iki farklı nükleotit ve her biri en az iki kez.

## Dersin Toparlaması

Bu derste filogenetiğin temel kavramları ve filogenetik ağaçların nasıl kurulduğu işlendi. Önce filogeni, kladogram, dendrogram, topoloji, köklü ve köksüz ağaç, kardeş, politomi, monofiletik ve parafiletik grup gibi terimler tanıtıldı ve olası ağaç sayısının tür sayısıyla nasıl hızla büyüdüğü görüldü. Moleküler verinin kategorik olduğu, bu yüzden Hamming ya da Levenshtein gibi uzaklıkların kullanıldığı vurgulandı.

Ardından üç yöntem ailesi karşılaştırıldı. Uzaklık tabanlı UPGMA beş DNA dizisiyle adım adım çözüldü, dal uzunluklarının kestirimi ve dört nokta koşuluna dayanan komşuluk yöntemi ile komşu birleştirme anlatıldı. Maksimum parsimonide bilgi verici konumlar ve en az değişiklik ilkesi, maksimum olabilirlikte evrim modeline dayalı seçim ele alındı. Son olarak ağaçların güvenilirliğini sınayan bootstrap ve parametrik testler ile moleküler filogenetiğin uygulamaları ve hata kaynakları özetlendi. Hoca kapanışta artık bu ağaçların nasıl hesaplandığının bilindiğini, pratikte hesaplama kolaylığı nedeniyle çoğunlukla UPGMA'nın kullanıldığını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
