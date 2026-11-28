# Ders 11 Genişletilmiş Notu: İndeksleme: Temel Kavramlar ve B+ Ağacı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: Disk Esaslı Veri Yapıları
- 2. İndekslemenin Temel Kavramları
- 3. Dense ve Sparse İndeks
- 4. Primary ve Secondary İndeks
- 5. İndeksle Erişimin Maliyeti
- 6. Çok Seviyeli İndeks
- 7. Kompozit Arama Anahtarı
- 8. B+ Ağacının Yapısı ve Kuralları
- 9. B+ Ağacının Yüksekliği
- 10. B+ Ağacında Sorgu
- 11. B+ Ağacına Ekleme
- 12. Silme ve Hash Yapıları
- Örnek Sorular
- Dersin Toparlaması

Ders Zoom üzerinden yapıldı ve dönemin son dersiydi. Hoca ekranda ders kitabının (Database System Concepts, 7. baskı, Silberschatz, Korth ve Sudarshan) 14. bölümünün (İndeksleme) PDF slaytlarını gösterdi. Ders, yaklaşık 18 dakikalık bir arayla iki bölüm halinde yapıldı.

## 1. Giriş: Disk Esaslı Veri Yapıları

Önceki derste dosya tipleri görülmüştü. Dosya, diskte saklanan, aynı şemaya sahip kayıtların bir araya gelmesiyle oluşan mantıksal bir yapıdır ve veritabanındaki tablolara karşılık gelir. Bir dosya tek bir tabloya karşılık geliyorsa homojen, birden çok tabloyu içeriyorsa homojen olmayan dosya denir. Homojen olmayan dosyaların amacı performansı artırmaktır, ama değişken uzunluklu kayıtlar ortaya çıktığı için gerçekleme karmaşıklığı artar. Dosya organizasyonu olarak heap file, sequential file ve clustered file görülmüştü.

Bunların ötesinde daha özel yapılar vardır: ağaç yapıları ve hash yapıları. Ağaç yapıları denince akla B+ ağacı gelir; hash yapıları denince statik hash, extendable hash ve linear hash. Bunlar disk esaslı veri yapılarıdır, yani diskin çalışma biçimi göz önüne alınarak tasarlanmışlardır.

Hoca bu yapıları sistemin "esas çarkları" olarak tanımladı. Dönemin başındaki kavramlar (view'lar, fonksiyonlar, trigger'lar, tablolar, şemalar) mantıksal organizasyona, yani kullanıcıya yakın yapılardı. Bir veritabanında view olmasa da sistem çalışır. İndeks yapıları ise sistemin fiziksel çekirdeğidir; veritabanının gerçek zamanlı ve hızlı çalışmasını sağlayan olmazsa olmaz yapılardır. B+ ağacının tasarımı 1970-80'lere dayanır ve bugün hâlâ birçok sistemde kullanılır.

## 2. İndekslemenin Temel Kavramları

### 2.1 Tanımlar

Ekrandaki "Basic Concepts" slaytına göre (ekrandan, 00:05:00):

- İndeksleme mekanizmaları istenen veriye erişimi hızlandırmak için kullanılır (örneğin kütüphanedeki yazar kataloğu).
- Arama anahtarı (search key): bir dosyada kayıt aramak için kullanılan nitelik ya da nitelik kümesi.
- İndeks dosyası, indeks kaydı (index entry) denen `(search-key, pointer)` biçimindeki kayıtlardan oluşur.
- İndeks dosyaları genelde asıl dosyadan çok daha küçüktür.
- İki temel indeks türü vardır: sıralı indeksler (ordered indices), arama anahtarları sıralı tutulur; hash indeksler, arama anahtarları bir hash fonksiyonuyla "bucket"lara düzgün dağıtılır.

### 2.2 Arama anahtarı ile istenen nitelik

Hoca şu sorguyu örnek verdi:

```sql
SELECT salary FROM instructor WHERE name = 'Califieri';
```

Bu sorguda Califieri adlı hocanın maaşı aranır. Instructor tablosunda milyonlarca kayıt olduğu düşünülürse, aranan şey `salary` değil `name` değeridir; arama anahtarı `name`'dir. Califieri'ye erişildikten sonra onun herhangi bir niteliği (maaşı, bölümü, ID'si) okunabilir. Bu yüzden indeksin anlamlı olduğu yer `name` niteliğidir. İndeks olmazsa dosyadaki bütün kayıtlar sırayla aranmak zorundadır ve bu son derece yavaştır; `name` üzerindeki bir indeksle kayıt binlerce kat daha hızlı bulunabilir.

### 2.3 İndeksin faydasını belirleyen etkenler

İlk etken dosyanın büyüklüğüdür. Dosya ne kadar büyükse indeksin katkısı o kadar artar. Dosya çok küçükse indeksin bir katkısı olmaz, hatta zararı olur; kayıt doğrudan daha hızlı bulunabilir.

İkinci etken, aranan değerin sütunda kaç kez geçtiğidir. Hoca bunun ölçütüne seçicilik (selectivity) dendiğini söyledi. Aranan değer çok sık geçiyorsa sıralı erişimle zaten birçok yerde yakalanır. İndeks üzerinden dolaylı olarak, dosyanın her yerine dağılmış kayıtlara gitmek ise daha pahalı olur. Bu durumda indeksin kullanılma ihtimali azalır.

### 2.4 İndeksin dezavantajları

> **Hocanın vurgusu:** İndeks hızlandırır ama "çok da masum bir şey değil"; mutlaka dezavantajları vardır.

Birinci ve daha hafif dezavantaj yer kaplamasıdır. İndeks yalnız bir nitelik ve bir pointer sakladığı için büyüklüğü dosyadaki nitelik sayısına bağlıdır: şema 10 nitelikliyse indeks yaklaşık dosyanın onda biri, 50 nitelikliyse ellide biri kadardır. İndeks de nihayetinde şeması (search key, pointer) olan küçük bir dosyadır.

İkinci önemli dezavantaj veri tekrarıdır. Arama anahtarı hem dosyada hem indekste bulunur. Dosyaya kayıt eklendiğinde, silindiğinde ya da bir kaydın `name` değeri değiştiğinde indeksin de değiştirilmesi gerekir; aksi halde indeks üzerinden yapılan erişimler hatalı olur. Aynı veri iki yere yazıldığı için güncellemelerde tutarlılık (consistency) sorunu ortaya çıkar.

Dosya işlemlerinde olduğu gibi indekslerin değerlendirilmesinde de performans ölçütleri vardır. Bu ölçütleri veritabanındaki sorgu planlayıcısı (optimizer) kullanır ve bir indeksin kullanılıp kullanılmayacağına bunlara göre karar verir.

## 3. Dense ve Sparse İndeks

### 3.1 Dense indeks

Dense indekste dosyadaki her arama anahtarı değeri için bir indeks kaydı bulunur (ekrandan, 00:10:00). Slayttaki örnek, instructor tablosunun ID niteliği üzerindeki indekstir:

| ID | name | dept_name | salary |
|---|---|---|---|
| 10101 | Srinivasan | Comp. Sci. | 65000 |
| 12121 | Wu | Finance | 90000 |
| 15151 | Mozart | Music | 40000 |
| 22222 | Einstein | Physics | 95000 |
| 32343 | El Said | History | 60000 |
| 33456 | Gold | Physics | 87000 |
| 45565 | Katz | Comp. Sci. | 75000 |
| 58583 | Califieri | History | 62000 |
| 76543 | Singh | Finance | 80000 |
| 76766 | Crick | Biology | 72000 |
| 83821 | Brandt | Comp. Sci. | 92000 |
| 98345 | Kim | Elec. Eng. | 80000 |

İndekste bu 12 ID değerinin her biri tekrar edilir ve her birinin yanında kaydı gösteren bir pointer vardır. İndeks bulunduğunda pointer ile doğrudan dosyadaki kayda "zıplanır". Ana fikir şudur: indeks dosyası küçüktür ve sıralıdır. Sıralı olduğu için üzerinde ikili arama yapılabilir ya da bir B+ ağacına yerleştirilebilir; bu da aramayı son derece hızlandırır.

### 3.2 Sparse indeks

Sparse indekste yalnız bazı arama anahtarı değerleri için indeks kaydı bulunur (ekrandan, 00:20:00). Slayttaki örnekte indekste yalnız 10101, 32343 ve 76766 değerleri vardır. Slayta göre:

- Sparse indeks, kayıtlar arama anahtarına göre sıralıyken uygulanabilir.
- K anahtarlı bir kaydı bulmak için K'dan küçük en büyük anahtarlı indeks kaydı bulunur ve dosya, o indeks kaydının gösterdiği kayıttan başlayarak sırayla taranır.

Hoca sparse indeksin tek şartının dosyanın bu niteliğe göre sıralı olması olduğunu vurguladı; aksi halde indekste olmayan kayıtlara erişilemez. Gerçeklemede çoğu zaman her disk sayfasının başındaki değer indekse konur. Dosyalar disk sayfalarından (page) oluşur; sayfalar ana belleğe getirilir, okuma ya da yazma orada yapılır ve yazma yapıldıysa sayfa diske geri yazılır. Ama bu şart değildir; tanım gereği bazı değerlerin indekse konması yeterlidir.

Örnek: ID'si 20000 olan kayıt aranıyor. 20000 indekste yoktur ama varsa 10101 ile 32343 arasında bir yerdedir. 10101'in pointer'ı izlenir ve dosya oradan taranır. Bu bölgede 20000'in olmadığı ancak dosyaya gidildikten sonra anlaşılır.

> **Ders sonrası not:** Slayttaki ifade "K'dan küçük en büyük değer" biçimindedir; K'nın kendisi indekste varsa doğrudan o kayıt kullanıldığı için kural "K'ya eşit ya da küçük en büyük değer" diye de okunabilir (büyük olasılıkla kitabın kastettiği budur).

### 3.3 Lookup sorguları ve farkın ortaya çıkışı

Dense ile sparse arasındaki önemli bir fark lookup sorgularında ortaya çıkar. Kullanıcı birincil anahtarı kendisi giriyorsa (otomatik artan değilse), sistem kayıt eklerken o anahtarın tabloda olup olmadığını otomatik olarak denetler. Birincil anahtar üzerinde varsayılan olarak bir indeks bulunur.

Dense indekste 20000 aranırsa indekste olmadığı görülür ve iş indeks içinde biter; buna index-only evaluation denir. Sparse indekste ise 20000'in bulunabileceği aralık tahmin edilip dosyaya gidilmesi ve orada aranması gerekir. Bu sparse indeksin dezavantajıdır. Avantajı ise daha az yer kaplamasıdır. Aynı dosya için farklı yoğunlukta indeksler kurulabilir; hangisinin seçileceği indeks saklamaya ayrılabilecek kaynağa bağlıdır. Sparse indeks daha az hizmet verir ama daha az yer kaplar.

## 4. Primary ve Secondary İndeks

Primary indeks (clustering indeks), dosyanın indeksin arama anahtarına göre sıralı olduğu indekstir. Bu özellikle aralık sorgularında önemli bir fayda sağlar. Dense ve sparse indeks şekillerindeki ID indeksleri primary indekstir: indeks sıralıdır, dosya da ID'ye göre sıralıdır, bu yüzden indeksten dosyaya giden oklar paraleldir.

> **Hocanın vurgusu:** İndeksten dosyaya giden oklar birbirine paralelse buna doğrudan primary indeks denebilir.

Secondary indekste ise dosya, indeksin arama anahtarına göre sıralı değildir (ekrandan, 00:25:00). Slayttaki örnek, instructor tablosunun salary niteliği üzerindeki secondary indekstir. İndeksteki maaş değerleri sıralıdır (40000, 60000, 62000, 65000, 72000, 75000, 80000, 87000, 90000, 92000, 95000), ama dosya maaşa göre sıralı değildir. Bu yüzden her maaş değerinin pointer'ı dosyanın farklı bir yerine gider ve oklar paralel olmaz. Slaytta indeks kaydı, o anahtar değerine sahip bütün kayıtların pointer'larını içeren bir bucket'a işaret eder (örneğin 80000 maaşlı iki kayıt vardır).

Secondary indeks dense olmak zorundadır ("have to be dense"). Çünkü dosyada bu anahtara göre bir sıralama yoktur ve bütün değerlerin indekse alınması gerekir. Primary indekste ise sıralılık sayesinde bazı değerlerden örnek alınıp aralık tahmini yapılabilir; 20000 örneğinde dosyanın diğer kısımlarına hiç bakılmamıştı.

Özetle:

- Primary indeks dense de olabilir, sparse de.
- Secondary indeks mutlaka dense olmalıdır.
- Sparse indeks ancak primary indeks olabilir.

## 5. İndeksle Erişimin Maliyeti

Hoca indeksin fiziksel olarak nasıl çalıştığını küçük bir örnekle gösterdi. Bir sorgu gelir; sorgudaki arama anahtarı üzerinde indeks varsa küçük indeks dosyasında ikili arama yapılır ve elde edilen pointer'la dosyada doğrudan hedefe ulaşılır.

Verilenler (salary üzerindeki secondary indeks, 00:25:00'deki şekil):

- İndekste 11 farklı maaş değeri vardır. Bir disk sayfası 6 indeks kaydı alsın; indeks 2 sayfaya yerleşir.
- Veri dosyasında 12 kayıt vardır. Veri kayıtlarında başka nitelikler de olduğu için bir sayfaya yalnız 2 kayıt sığsın; dosya 6 sayfaya yerleşir.

Hoca önce yanlışlıkla Crick'i aramaya başladı, sonra indeks salary üzerinde olduğu için aramayı maaş üzerinden düzeltti: maaşı 72000 olan hoca aranıyor.

- İndeks olmadan: 72000 maaşlı kayıt (Crick) dosyanın 10. kaydıdır. Sayfa başına 2 kayıtla 5. sayfadadır; sıralı aramada 5 disk erişimi gerekir.
- İndeksle: indekste ikili arama ile ortadaki değerden küçük olduğu görülür ve ilgili indeks sayfası okunur (1 erişim). Pointer ile veri sayfasına gidilir (1 erişim). Toplam 2 erişim.

Böylece erişim sayısı 5'ten 2'ye düşer. Hoca, 4 KB'lık gerçek sayfalarda bu kayıtların hepsinin tek sayfaya sığacağını, örneğin yalnız olayı yakınlaştırmak için temsili olduğunu belirtti. Gerçek boyutlarda, örneğin 5000 sayfalık bir dosyada sıralı arama ortalama 2500 sayfa okur; indeksle 5-10 disk erişimi yeterli olur.

İndeks ana belleğe sığıyorsa indeks tarafında hiç disk erişimi olmaz; yalnız indeksten gelen kayıt kimliği (RID) ile dosyaya erişilir.

## 6. Çok Seviyeli İndeks

Dosya çok büyükse indeks dosyası da büyür ve ana belleğe sığmayabilir. O zaman "dosyanın başına gelenler indeksin başına gelir": indeks dosyası üzerinde de bir indeks kurulabilir.

İndeks zaten sıralı bir nitelik üzerinde olduğu için, onun üzerine kurulacak indeks primary indeks olur ve sparse olabilir. Bu yapıya çok seviyeli indeks (multi-level index) denir:

- İç indeks (inner index): veri dosyasının ilk indeksidir. Dense ya da sparse olabilir. Çok sayıda indeks bloğundan oluşur.
- Dış indeks (outer index): iç indeksin üzerine kurulur. İç indeks sıralı olduğu için dış indeks mutlaka sparse olur, bu da indeksin küçülmesini sağlar.

B+ ağacı da esasında böyle bir çok seviyeli indekstir.

## 7. Kompozit Arama Anahtarı

Arama anahtarı tek bir nitelikten oluşmak zorunda değildir; birden çok nitelikten oluşursa kompozit (çok nitelikli) indeks denir (ekrandan, 00:35:00). Bir arama anahtarı üzerinde indeks kurmak, anahtarın sıralanabilir olmasını gerektirir. Integer, string ya da tarih değerleri sıralanabilir. İki nitelik birleştiğinde sıralama sözlük sırasıyla (lexicographic) yapılır: önce ilk niteliğe göre sıralanır, ilk niteliği aynı olanlar ikinci niteliğe göre sıralanır.

Slayttaki örnek: instructor üzerinde `(name, ID)` indeksi.

$$(John, 12121) < (John, 13514) \quad \text{ve} \quad (John, 13514) < (Peter, 11223)$$

İkinci karşılaştırmada 11223, 13514'ten küçük olsa bile ilk nitelikte John, Peter'dan küçük olduğu için $(John, 13514)$ daha küçüktür.

Bütün veriye bakıldığında sıralama yalnız `name`'e göredir. Kayıtların aynı anda ID'ye göre de sıralı olması ancak ID'nin ada bağlı olarak üretilmesi gibi bir durumda mümkündür; bu ihtimal düşünülmez. ID yalnız aynı adlar içinde sıralıdır.

Bu indeksin faydası aramaya göre değişir:

- `name` ve `ID` birlikte aranıyorsa (örneğin Peter, 11223) çok faydalıdır.
- Yalnız `name` aranıyorsa yine faydalıdır, çünkü indeks ada göre sıralıdır. Ama yalnız `name` üzerindeki tekli bir indekse göre biraz daha az faydalıdır, çünkü kompozit indeksin şeması daha büyük, indeks daha büyüktür.
- Yalnız `ID` aranıyorsa hiçbir fayda sağlamaz, çünkü kayıtlar bütünüyle ID'ye göre sıralı değildir.

Böylece indeks sınıflandırmasına bir kategori daha eklenmiş oldu: dense/sparse, primary (clustered)/secondary yanında tekli (singular) ve kompozit indeks.

## 8. B+ Ağacının Yapısı ve Kuralları

### 8.1 Genel yapı

B+ ağacı bir ağaç organizasyonudur: yukarıda bir kök, aşağıda yapraklar vardır ve ağacın içinde arama anahtarları bulunur. Ekrandaki örnek instructor dosyasının `name` niteliği üzerindeki B+ ağacıdır (ekrandan, 00:40:00):

```text
Kök:            [Mozart]
İç düğümler:    [Einstein | Gold]                  [Srinivasan]
Yapraklar:      [Brandt | Califieri | Crick] -> [Einstein | El Said] -> [Gold | Katz | Kim]
                -> [Mozart | Singh] -> [Srinivasan | Wu]
```

B+ ağacı sıralı bir indekstir; yapraklara bakıldığında anahtarların sıralı olduğu görülür. Bu bir çok seviyeli indekstir: yaprak seviyesi iç indeks, üstteki seviyeler dış indeks gibidir. Her seviyedeki düğümler de kendi içinde sıralıdır (Einstein, Gold, Srinivasan).

Bu örnekte dosya `name`'e göre sıralı değildir; bu yüzden yaprak seviyesi bir secondary indekstir ve dense olmak zorundadır. Yapraklardan dosyaya giden oklar şekilde paralel gibi görünse de dosyanın farklı yerlerine gider; biri dosyanın sonuna, diğeri başına gider.

> **Hocanın vurgusu:** Şekildeki paralellik aldatmasın; yaprak seviyesi secondary ve dense bir indekstir.

Yaprakların üzerindeki iç düğümler ve kök ise sparse indekstir. Yaprak seviyesi de bir dosya gibi düşünülürse arama anahtarına göre sıralıdır; bu yüzden üst seviyeler primary ve sparse indeks gibidir. Yani öğrenilen bütün indeks tanımları B+ ağacının her seviyesine uygulanabilir.

### 8.2 Kurallar

Ekrandaki slayta göre bir B+ ağacı şu özellikleri sağlayan köklü bir ağaçtır (ekrandan, 00:45:00):

- Kökten yaprağa giden bütün yollar aynı uzunluktadır.
- Kök ya da yaprak olmayan her düğümün $\lceil n/2 \rceil$ ile $n$ arasında çocuğu vardır.
- Bir yaprak düğümde $\lceil (n-1)/2 \rceil$ ile $n-1$ arasında değer vardır.
- Özel durumlar: kök yaprak değilse en az 2 çocuğu vardır; kök yapraksa (ağaçta başka düğüm yoksa) 0 ile $n-1$ arasında değeri olabilir.

Birinci kural ağacın dengeli olduğunu söyler: kökten dosyaya kadar her yoldan aynı sayıda adımda gidilir. İkili arama ağacı gibi bazı ağaç yapıları dengesiz olabilir. B+ ağacının en önemli özelliği dengeli olmasıdır; bu, en kötü durum analizini iyileştirir. Dengesiz bir ağaçta en iyi durum daha iyi olabilir ama en kötü durum daha kötüdür.

B+ ağacı disk esaslı bir veri yapısı olduğu için düğümlerinin her biri genellikle bir disk sayfasına karşılık gelir. Bu, B+ ağacının tanımında yoktur ama çoğu zaman böyledir. Bir düğüme kaç tane (anahtar, pointer) çifti yazılabileceği disk sayfasının sabit ve önceden bilinen büyüklüğüne göre belirlenir. Kısıtlar da buradan gelir.

İç düğümlerde kısıt pointer sayısına göredir: en az $\lceil n/2 \rceil$, en çok $n$ pointer. $n$ tek ise yukarı yuvarlanır; örneğin $n = 5$ ise en az 3, en çok 5 pointer olmalıdır. Yapraklarda ise kısıt değer sayısına göredir: en az $\lceil (n-1)/2 \rceil$, en çok $n-1$ değer.

Kökün özel durumu ağacın büyüme biçiminden gelir. İndeks yeniyken tek bir düğüm vardır ve bu düğümün çocuğu yoktur; bu durumda 0 ile $n-1$ arasında kayıt içerebilir. Ağaç genişlemeye başlayıp kök yaprak olmaktan çıkınca kökün en az 2 çocuğu olur. Çünkü ağaç aşağıdan yukarı büyür ve yeni bir seviye yalnız kökün ikiye bölünmesiyle, iki çocuklu yeni bir kök oluşmasıyla ortaya çıkar.

### 8.3 Düğüm yapısı

Tipik bir düğüm şöyledir (ekrandan, 00:50:00):

```text
| P1 | K1 | P2 | ... | Pn-1 | Kn-1 | Pn |
```

- $K_i$ arama anahtarı değerleridir.
- $P_i$, yaprak olmayan düğümlerde çocuklara, yaprak düğümlerde kayıtlara ya da kayıt bucket'larına pointer'dır.
- Bir düğümdeki anahtarlar sıralıdır: $K_1 < K_2 < K_3 < \ldots < K_{n-1}$.
- Başlangıçta tekrarlı anahtar olmadığı varsayılır.

Bu, basit indekste görülen (arama anahtarı, pointer) çiftlerinin aynısıdır. Bir düğümde $n-1$ anahtar ve $n$ pointer vardır. Son pointer için anahtar yazılmaz, çünkü gerek yoktur: $P_1$, $K_1$'den küçük değerleri içeren alt ağacı gösterir; $P_2$, $K_1$'e büyük eşit ve $K_2$'den küçük değerleri gösterir; bu böyle devam eder ve $P_n$, $K_{n-1}$'e büyük eşit değerleri gösterir.

Hoca tekrarlı değerlerin önemli olduğunu ama gerçeklemesinin karmaşık olduğunu söyledi. Secondary indekslerde ya da tekrarlı nitelikler üzerindeki indekslerde mutlaka tekrar olur, ama derste esaslara odaklanmak için bu konuya girilmedi.

Eşitliğin hangi tarafa konacağı gerçeklemeye göre değişebilir. Slayttaki düzenlemede küçükler sola, büyük eşitler sağa gider. Başka bir gerçeklemede eşitlik küçük tarafa konabilir; önemli olan anahtarın sol ya da sağ taraflardan birine dahil edilmesidir.

### 8.4 Yaprak düğümler

Slayta göre yaprak düğümün özellikleri (ekrandan, 00:55:00):

- $i = 1, 2, \ldots, n-1$ için $P_i$, arama anahtarı $K_i$ olan dosya kaydını gösterir.
- $L_i$ ve $L_j$ yaprak düğümler ve $i < j$ ise $L_i$'nin anahtarları $L_j$'nin anahtarlarına eşit ya da onlardan küçüktür.
- $P_n$, anahtar sırasındaki bir sonraki yaprağı gösterir.

Örnekte `Brandt | Califieri | Crick` yaprağındaki Brandt'ın pointer'ı Brandt kaydına, Crick'in pointer'ı Crick kaydına gider; son pointer bir sonraki yaprağa aktarır. Yapraklar bu pointer'larla birbirine bağlıdır. İç düğümler ise birbirine bağlı değildir; iç düğümlerdeki bütün pointer'lar çocuklara gitmek için kullanılır. Yapraklarda son pointer sonraki yaprak için kullanıldığından yaprak kısıtı değer sayısına, iç düğüm kısıtı pointer sayısına göre konmuştur.

### 8.5 $n = 6$ örneği

Ekrandaki örnek, instructor dosyası için $n = 6$ olan bir B+ ağacıdır (ekrandan, 01:00:00):

```text
Kök:        [El Said | Mozart]
Yapraklar:  [Brandt | Califieri | Crick | Einstein] -> [El Said | Gold | Katz | Kim]
            -> [Mozart | Singh | Srinivasan | Wu]
```

$n$'ye bazı kaynaklarda B+ ağacının derecesi (order) denir; bir düğüm 6 pointer içerebilir. Gerçek sistemlerde bu değer 200-300'e kadar çıkabilir; B+ ağacını bu kadar verimli ve yaygın yapan da budur.

Kurallar bu ağaçta şöyle denetlenir:

- Yapraklar: $n - 1 = 5$ anahtar olabilir. $\lceil 5/2 \rceil = 3$. Yapraklarda 3 ile 5 arasında değer olmalıdır; her yaprakta 4 değer vardır, kural sağlanır.
- Kök dışındaki iç düğümler: $\lceil 6/2 \rceil = 3$. 3 ile 6 arasında çocuk olmalıdır.
- Kök: 3 pointer'ı vardır. Kök yaprak olmadığı için en az 2 çocuğu olmalıdır; dosyaya henüz o kadar kayıt gelmemiş olsaydı 2 pointer da olabilirdi. Ama kökte hiçbir zaman tek pointer olmaz; aksi halde kökün bir anlamı kalmazdı.

Arada hoca ağacın yüksekliğinin 2 olduğunu, ağacın bir kök ve 3 yapraktan oluşan dengeli bir ağaç olduğunu söyledi. $n = 6$ değeri temsilidir; gerçekte bu kısıtı disk sayfasının büyüklüğü koyar. Bir anahtar ve pointer çifti 8-10 bayt olsa bu örnekteki düğüm 50 bayt civarında olurdu; 4 KB'lık gerçek sayfalarda $n$ yüzler mertebesine çıkar.

## 9. B+ Ağacının Yüksekliği

Ekrandaki "Observations about B+-trees" slaytına göre (ekrandan, 01:25:00):

- Düğümler arası bağlantılar pointer'larla yapıldığı için mantıksal olarak yakın bloklar fiziksel olarak yakın olmak zorunda değildir.
- B+ ağacının yaprak olmayan seviyeleri bir sparse indeks hiyerarşisi oluşturur.
- B+ ağacının seviye sayısı görece azdır:
  - Kökün altındaki seviyede en az $2 \lceil n/2 \rceil$ değer vardır.
  - Bir sonraki seviyede en az $2 \lceil n/2 \rceil \lceil n/2 \rceil$ değer vardır, ve böyle devam eder.
  - Dosyada K arama anahtarı değeri varsa ağacın yüksekliği en fazla $\lceil \log_{\lceil n/2 \rceil}(K) \rceil$ olur.
  - Bu yüzden aramalar verimli yapılabilir.
- Asıl dosyaya ekleme ve silmeler de verimli yapılabilir, çünkü indeks logaritmik zamanda yeniden yapılandırılabilir.

B+ ağacının ekleme, çıkarma ve erişimdeki bütün maliyeti ağacın yüksekliği kadardır. Ağaç hep dengeli olduğu için yükseklik her yerde aynıdır; bu düzenlilik B+ ağacını çok değerli kılar. Gerçek hayatta $n$ 100-300'e vardığı için yükseklik çok büyük dosyalarda bile 2, 3, 4 gibi küçük sayılardır.

Formülün sezgisi şöyledir: aramaya her zaman kökten başlanır, çünkü bütün ağaçla ilgili özet bilgiyi kök verir. Her adımda düğümdeki pointer'lardan birine gidilir. Bir düğümde en az $\lceil n/2 \rceil$ pointer olduğu için, her adımda en kötü durumda veri setinin $1/\lceil n/2 \rceil$'lik kısmına inilir. İkili aramada her seferinde liste yarıya bölündüğü için maliyet $\log_2 K$ idi; burada her adımda liste en az $\lceil n/2 \rceil$'ye bölünür ve arama adımı sayısı $\log_{\lceil n/2 \rceil} K$ olur.

> **Ders sonrası not:** Hoca bir yerde gerçek bir değer için "logaritma 100 tabanında K" dedi. Formüldeki taban $\lceil n/2 \rceil$ olduğu için $n = 100$ ise taban 50'dir; slaytta da $\log_{50}$ yazar.

## 10. B+ Ağacında Sorgu

### 10.1 `find(v)` algoritması

Ekrandaki sözde kod (ekrandan, 01:30:00):

```text
function find(v)
1. C = root
2. while (C is not a leaf node)
   1. Let i be least number s.t. V <= K_i
   2. if there is no such number i then
   3.     Set C = last non-null pointer in C
   4. else if (v = C.K_i) Set C = P_{i+1}
   5. else set C = C.P_i
3. if for some i, K_i = V then return C.P_i
4. else return null /* no record with search-key value v exists. */
```

Kökten başlanır ve hedefe doğru yol belirlenir. While döngüsü yaprağa ulaşılana kadar, yani ağacın yüksekliği kadar döner. C o anki düğümdür. Her adımda düğümde soldan sağa ilerlenip aranan $v$'ye eşit ya da ondan büyük olan en küçük anahtar bulunur; bu anahtar hangi alt ağaca gidileceğini belirler.

- Böyle bir anahtar yoksa $v$ düğümdeki bütün anahtarlardan büyüktür ve son pointer izlenir. Örneğin Z aranırsa kökte Mozart'tan büyük bir anahtar yoktur; Z varsa Mozart'ın sağındadır.
- Bulunan anahtar $v$'ye eşitse, büyük eşit değerler sağda olduğu için $P_{i+1}$'e gidilir.
- Eşit değilse $v$ bu anahtardan küçüktür ve $P_i$'ye gidilir.

Satır 4 eşitlik durumunu ele almak içindir. Yaprağa ulaşıldığında $K_i = v$ olan bir anahtar varsa onun pointer'ı döndürülür. Yoksa kayıt yoktur, çünkü kaydın yapıya göre bulunabileceği tek yer burasıdır.

### 10.2 Crick örneği

Aramalar 00:40:00'daki üç seviyeli ağaçta yapılır (kök Mozart; iç düğümler `Einstein | Gold` ve `Srinivasan`):

1. Kökte: Crick'e büyük eşit ilk anahtar Mozart'tır ve eşit değildir; sol pointer izlenir. Mozart'ın solundaki alt ağaç Mozart'tan küçük, sağındaki büyük eşit adları içerir. Böylece dosyanın yarısına hiç bakmaya gerek kalmaz.
2. İç düğümde (`Einstein | Gold`): Crick'e büyük eşit ilk anahtar Einstein'dır, eşit değildir; Einstein'ın solundaki pointer izlenir. Hoca dolu bir ağaçta bu budamanın daha da kuvvetli olacağını söyledi.
3. Yaprakta (`Brandt | Califieri | Crick`): anahtarlar sıralı olduğu için Crick bulunur. Crick'e büyük eşit ilk anahtar Crick'in kendisidir; onun yanındaki pointer, Crick'i içeren dosya kaydına götürür.

Her düğüm bir disk sayfası sayılırsa kök, iç düğüm, yaprak ve veri sayfası için 4 disk erişimiyle Crick bulunur; Crick dosyanın neresinde olursa olsun.

### 10.3 Nokta ve aralık sorguları

Tek bir değerin arandığı sorguya nokta sorgusu (point query) denir; örneğin `name = 'Crick'`. `name > 'Crick'` ya da "Crick ile Mozart arasındaki kayıtlar" gibi sorgular ise aralık sorgusudur (range query). `name` sıralanabilir bir nitelik olduğu için bu mümkündür.

Aralık sorgusunda önce aralığın alt ucunun bulunduğu yaprağa inilir. Sonra yaprak seviyesi dense bir indeks olduğu için, yapraklar arasındaki küçük pointer'larla sağa doğru ilerlenip aralıktaki her anahtara erişilir. İndeksin üst seviyelerine tekrar çıkmak gerekmez.

Örnek: Crick ile Mozart arasındaki hocaların maaşları.

- 3 adımda Crick'in yaprağına inilir, Crick'in maaşına erişilir.
- Sonraki yaprağa geçilir: Einstein ve El Said'in maaşlarına erişilir.
- Sonraki yaprağa geçilir: Gold, Katz ve Kim'in maaşlarına erişilir.
- Sonraki yaprağa geçilir: Mozart aralığın son sınırıdır, onun maaşına erişilir.

Hoca, `SELECT ... FROM ... WHERE name` Crick ile Mozart arasında gibi bir sorgunun arka planda fiziksel olarak bu adımlarla çalıştığını, bunun da bu ders kapsamındaki özet cevap olduğunu söyledi.

### 10.4 Sayısal performans örneği

Ekrandaki slayta göre (ekrandan, 01:40:00):

- Dosyada K arama anahtarı değeri varsa ağacın yüksekliği en fazla $\lceil \log_{\lceil n/2 \rceil}(K) \rceil$ olur.
- Bir düğüm genellikle bir disk bloğu büyüklüğündedir, tipik olarak 4 KB; indeks kaydı 40 bayt ise $n$ yaklaşık 100'dür.
- 1 milyon arama anahtarı ve $n = 100$ ile bir aramada kökten yaprağa en çok $\log_{50}(1\,000\,000) = 4$ düğüme erişilir.
- Buna karşılık 1 milyon anahtarlı dengeli bir ikili ağaçta bir aramada yaklaşık 20 düğüme erişilir.
- Bu fark önemlidir, çünkü her düğüm erişimi yaklaşık 20 milisaniyelik bir disk I/O'su gerektirebilir.

Hesap (python ile denetlendi): $4000 / 40 = 100$; $\lceil 100/2 \rceil = 50$; $\log_{50}(10^6) \approx 3{,}53$, yukarı yuvarlanınca 4. $\log_2(10^6) \approx 19{,}93$, yani yaklaşık 20.

Hoca $n = 100$'ün iyimser değil, aslında temkinli bir değer olduğunu açıkladı: indeks kayıtları veri sıkıştırma yöntemleriyle küçültülebilir ve veritabanlarında tipik sayfa boyutu 4 KB değil 8 KB'dır; bu yüzden $n$ 500'lere ulaşabilir. Yine de $n = 100$ kabul edilirse en kötü durumda yükseklik 4 olur. Kök ve köke yakın seviyeler çok erişildiği için genelde ana bellekte tutulur; bu yüzden 1 milyon kayıt içinde bir arama pratikte 1-2 disk erişimi gerektirir. Kayıt sayısı daha da artsa bu sayı 2-3 olur. Sıralı aramada ise bütün dosyanın taranması gerekirdi.

Dengeli bir ikili arama ağacı da kullanılabilirdi, ama disk ortamında bir ikili ağacı dengeli tutmak kolay değildir: önce veriyi sıralamak, sonra dengeli ağaç kurmak gerekir ve bu çok masraflıdır. İyimser bir varsayımla dengeli olduğu kabul edilse bile $\log_2(10^6) \approx 20$ disk erişimi gerekir. Hoca bu konuların daha ileri bir derste ayrıntılı işlendiğini söyledi.

## 11. B+ Ağacına Ekleme

### 11.1 Genel algoritma

Eklemede ağacın büyümesi yapraklardan köke doğru olur. Yeni bir kayıt geldiğinde:

1. Önce kaydın hangi yaprağa girmesi gerektiği bulunur. Bu bir aramadır ve `find` algoritmasıyla yapılır.
2. O yaprakta yer varsa ekleme yapılır ve iş biter.
3. Yer yoksa (yaprak en çok $n-1$ değer alabilir) düğüm bölünür (split). Düğüm ortadan ikiye bölünür; soldaki anahtarlar yerinde kalır, sağdakiler yeni bir disk sayfasına, yeni bir düğüme taşınır.
4. Bölünme, iki yeni düğümü birbirinden ayıracak yeni bir anahtarın ortaya çıkmasına yol açar. Bu anahtar sağ düğümün en küçük elemanının kopyasıdır ve üst seviyeye eklenir.
5. Üst seviyede de yer yoksa o düğüm de bölünür ve yeni anahtar bir üst seviyeye taşınır ("split and propagate the split further up"). Bu en sonunda köke kadar dayanabilir. Kökte de yer kalmazsa kök ikiye ayrılır ve iki çocuklu yeni bir kök oluşur.

Neden sağ düğümün en küçük elemanı? Çünkü iç düğümde bir anahtarın sağındaki pointer, o anahtara büyük eşit değerlerin bulunduğu alt ağacı gösterir. Örneğin ağaçta Mozart iki alt ağacı, Einstein başka iki alt ağacı, Srinivasan yine iki alt ağacı birbirinden ayırır.

Bu da kök için konan özel kuralı açıklar: kök yaprak değilse yeni seviyeler kökün bölünmesiyle ortaya çıkmıştır, bu yüzden en az iki çocuğu olması zorunludur.

### 11.2 Adams örneği

Ekrandaki slayt (ekrandan, 01:45:00): "Adams" eklenmeden önce ve sonra B+ ağacı. Bu ağaçta $n = 4$'tür; yapraklarda $\lceil 3/2 \rceil = 2$ ile 3 arasında değer olmalıdır.

Ekleme öncesi:

```text
Kök:            [Mozart]
İç düğümler:    [Einstein | Gold]                  [Srinivasan]
Yapraklar:      [Brandt | Califieri | Crick] -> [Einstein | El Said] -> [Gold | Katz | Kim]
                -> [Mozart | Singh] -> [Srinivasan | Wu]
```

Adımlar:

1. Adams'ın yeri aranır: kökte A, Mozart'tan küçük olduğu için sola; iç düğümde Einstein'dan küçük olduğu için Einstein'ın soluna inilir. Adams `Brandt | Califieri | Crick` yaprağına girmelidir.
2. Yaprak doludur (3 değer). Adams ile birlikte 4 değer olur ve ortadan ikiye bölünür: `Adams | Brandt` solda kalır, `Califieri | Crick` yeni bir düğüme taşınır. Yaprak sayısı 5'ten 6'ya çıkar.
3. İki yeni yaprağı ayırmak için sağ yaprağın en küçük elemanı Califieri üst düğüme eklenir. Üst düğümde (`Einstein | Gold`) yer vardır; Califieri eklenir ve iş biter.

Ekleme sonrası:

```text
Kök:            [Mozart]
İç düğümler:    [Califieri | Einstein | Gold]                  [Srinivasan]
Yapraklar:      [Adams | Brandt] -> [Califieri | Crick] -> [Einstein | El Said]
                -> [Gold | Katz | Kim] -> [Mozart | Singh] -> [Srinivasan | Wu]
```

Hoca burada üst düğümde yer olmasının şans olduğunu, yer olmasaydı o düğümün de ikiye bölüneceğini söyledi.

### 11.3 Lamport örneği

Ekrandaki slayt (ekrandan, 01:50:00): Adams eklenmiş ağaca "Lamport" eklenmeden önce ve sonra.

Adımlar:

1. Kökte L'den büyük eşit ilk anahtar Mozart'tır; sola inilir.
2. İç düğümde (`Califieri | Einstein | Gold`) L'den büyük bir anahtar bulunamaz; son pointer izlenir ve `Gold | Katz | Kim` yaprağına gelinir.
3. Lamport sırayı bozmadan eklenmelidir: Gold, Katz, Kim, Lamport. Ama yaprak doludur (kapasite 2-3 değer). Dört anahtar ikiye bölünür: `Gold | Katz` ve `Kim | Lamport`. İki düğümde de birer boşluk oluşur.
4. İki yaprağı ayıracak anahtar sağ yaprağın en küçük elemanı olan Kim'dir ve üst seviyeye yazılır. Böylece Kim'den büyük eşit olanlar sağda, küçük olanlar solda kalır.

> **Hocanın vurgusu:** Üst seviyeye Katz yazılamaz; sağ alt ağacın en küçük elemanı (Kim) yazılmalıdır.

Ekrandaki "sonra" şeklinde üst düğüm `Califieri | Einstein | Gold` zaten dolu olduğu için o da bölünmüştür ve Gold köke çıkmıştır (bu adım derste sözlü olarak ayrıntılandırılmadı, şekilden aktarıldı):

```text
Kök:            [Gold | Mozart]
İç düğümler:    [Califieri | Einstein]        [Kim]        [Srinivasan]
Yapraklar:      [Adams | Brandt] -> [Califieri | Crick] -> [Einstein | El Said]
                -> [Gold | Katz] -> [Kim | Lamport] -> [Mozart | Singh] -> [Srinivasan | Wu]
```

### 11.4 Eklemenin performansı

Şekillerde işaretlenen "etkilenen düğümler" ekleme yolunun üzerindeki düğümlerdir. Ekleme, ağaçta en fazla ağacın yüksekliği kadar bir yol boyunca etki eder; yatay bir etkisi yoktur. Ağacın ya da dosyanın diğer tarafındaki kayıtlar etkilenmez.

Sıralı bir dosyada ise ekleme yaparken sıralılığı korumak için çok sayıda kaydı kaydırmak (shift) gerekir. B+ ağacında asıl dosya sıralı olmak zorunda değildir; çoğu zaman hızlı ekleme ve çıkarmaya izin veren bir heap file olarak kalır. Sıralı erişim imkânını B+ ağacı sağlar; ekleme ve çıkarma da ağacın yüksekliği kadar, yani logaritmik maliyetlidir. Bu özellikler B+ ağacını çok önemli bir veri yapısı yapar.

## 12. Silme ve Hash Yapıları

### 12.1 Silme

Hoca silme işleminin ayrıntısına girmedi. Silmede ağaç yeniden yapılandırılır: bu sefer bölme (split) yerine birleştirme (merge) yapılır, bazı düğümler bir araya getirilir ve ağacın yüksekliği azalmaya başlar.

Gerçekleme karmaşıklığı ve maliyeti nedeniyle gerçek sistemlerde silme çoğu zaman bu biçimde gerçeklenmez. Örneğin bir tabloda `TRUNCATE` ya da kayıt silme yapıldığında indeks küçültülmez; mevcut yapı olduğu gibi bırakılır ve sonra gelen kayıtlar bu hazır yapıya eklenir. Bunun sebebi, ekleme ve çıkarmaların gerçek hayatta birbirini izlemesidir: bazı kayıtlar silinir ama birazdan yenileri eklenir. Yer verimliliği bir miktar azalır, ama silmenin masrafından kaçınılmış olur ve boş yerler yeni kayıtlarla dolar.

### 12.2 Hash yapıları

Hoca hash yapılarına girmedi, yalnız genel fikri verdi. Hash yapıları kayıtları sıralamak yerine belli bir fonksiyonla bucket'lara dağıtır. Statik versiyon yetersizdir, çünkü kaç kayıt olacağı önceden bilinmez. Bu yüzden B+ ağacı gibi uyarlamalı (adaptive) hash yapıları vardır: extendable hash (dynamic hashing) ve linear hash. Bunlar da karmaşık ama akıllıca tasarlanmış, günümüz veritabanlarında kullanılan disk esaslı veri yapılarıdır. Hoca, veri yapıları ve algoritmalar dersinde görülmediklerini düşündüğü bu yapıları merak edenlerin öğrenmesini tavsiye etti.

> **Ek bilgi (derste anlatılmadı):** Extendable hashing, bucket adreslerini tutan ve gerektiğinde ikiye katlanan bir dizin kullanır; bir bucket taşınca yalnız o bucket bölünür. Linear hashing ise dizin kullanmadan bucket'ları sırayla böler. İkisi de kayıt sayısı arttıkça yapının kademeli büyümesini sağlar.

## Örnek Sorular

1. (ekrandan, 00:10:00 ve 00:20:00) instructor tablosunda ID'si 20000 olan kayıt aranıyor. İndeks olarak ID üzerinde (a) dense, (b) yalnız 10101, 32343 ve 76766 değerlerini içeren sparse bir indeks var. İki durumda arama nasıl yürür ve kaydın olmadığı nerede anlaşılır?

> **Çözüm (derste sözlü verildi):** (a) Dense indekste bütün ID değerleri bulunduğu için 20000'in indekste olmadığı görülür ve kaydın olmadığı indeks içinde anlaşılır (index-only evaluation). (b) Sparse indekste 20000'den küçük en büyük değer 10101'dir; kayıt varsa 10101 ile 32343 arasındadır. 10101'in pointer'ı izlenip dosya sırayla taranır ve 20000'in olmadığı ancak dosyada anlaşılır.

2. (ekrandan, 00:25:00) salary üzerindeki secondary indekste 11 değer var, bir indeks sayfası 6 kayıt alıyor; veri dosyasında 12 kayıt var, bir veri sayfası 2 kayıt alıyor. Maaşı 72000 olan hocayı bulmak için indeks olmadan ve indeksle kaç disk erişimi gerekir?

> **Çözüm (derste verildi):** İndeks 2, dosya 6 sayfadır. 72000 maaşlı kayıt dosyanın 10. kaydıdır, yani 5. sayfadadır: sıralı aramada 5 erişim. İndeksle ikili arama sonucu 1 indeks sayfası ve pointer ile 1 veri sayfası: 2 erişim.

3. (ekrandan, 00:35:00) instructor üzerinde `(name, ID)` kompozit indeksi var. (John, 12121), (John, 13514) ve (Peter, 11223) değerleri nasıl sıralanır? Bu indeks yalnız `ID` ile yapılan bir aramada işe yarar mı?

> **Çözüm (derste verildi):** Sözlük sırasıyla $(John, 12121) < (John, 13514) < (Peter, 11223)$. 11223 daha küçük olsa da ilk nitelikte John < Peter olduğu için Peter'lı değer en büyüktür. Kayıtlar bütünüyle ID'ye göre sıralı olmadığından (ID yalnız aynı adlar içinde sıralıdır) indeks yalnız ID aramasında fayda sağlamaz.

4. (ekrandan, 01:00:00) $n = 6$ olan bir B+ ağacında yapraklarda ve kök dışındaki iç düğümlerde kaç değer/çocuk olabilir? Kök için kural nedir?

> **Çözüm (derste verildi):** Yapraklarda $\lceil (6-1)/2 \rceil = 3$ ile $6 - 1 = 5$ arasında değer; kök dışındaki iç düğümlerde $\lceil 6/2 \rceil = 3$ ile 6 arasında çocuk. Kök yaprak değilse en az 2 çocuğu olmalıdır.

5. (ekrandan, 01:40:00) 1 milyon arama anahtarı ve $n = 100$ olan bir B+ ağacında bir aramada en çok kaç düğüme erişilir? Dengeli bir ikili ağaçla karşılaştırın.

> **Çözüm (derste verildi):** $\lceil \log_{50}(10^6) \rceil = \lceil 3{,}53 \rceil = 4$ düğüm. Dengeli ikili ağaçta $\log_2(10^6) \approx 20$ düğüm. Her erişim bir disk I/O'su olabileceği için fark büyüktür; ayrıca üst seviyeler bellekte tutulduğundan B+ ağacında pratikte 1-2 disk erişimi yeterlidir.

6. (ekrandan, 01:45:00 ve 01:50:00) Örnek B+ ağacına ($n = 4$) önce "Adams", sonra "Lamport" ekleniyor. Hangi düğümler bölünür ve üst seviyeye hangi anahtarlar çıkar?

> **Çözüm (derste verildi, son adım ekrandaki şekilden):** Adams: `Brandt | Califieri | Crick` yaprağı `Adams | Brandt` ve `Califieri | Crick` olarak bölünür, Califieri iç düğüme eklenir (`Califieri | Einstein | Gold`). Lamport: `Gold | Katz | Kim` yaprağı `Gold | Katz` ve `Kim | Lamport` olarak bölünür, Kim yukarı çıkar. Dolu olan iç düğüm de bölünür (`Califieri | Einstein` ve `Kim`) ve Gold köke çıkar; kök `Gold | Mozart` olur.

## Dersin Toparlaması

Bu derste indekslemenin temel kavramları ve B+ ağacı işlendi. İndeks, (arama anahtarı, pointer) kayıtlarından oluşan küçük ve sıralı bir dosyadır; büyük dosyalarda aramayı çok hızlandırır ama yer kaplar ve güncellemelerde tutarlılık maliyeti getirir. Dense ve sparse, primary ve secondary, tekli ve kompozit indeks ayrımları görüldü; secondary indeksin dense olmak zorunda olduğu, sparse indeksin yalnız sıralı dosyada mümkün olduğu vurgulandı. Çok seviyeli indeks fikrinden B+ ağacına geçildi.

B+ ağacı, her yolun aynı uzunlukta olduğu dengeli bir çok seviyeli indekstir. Düğüm doluluk kuralları disk sayfası büyüklüğünden gelir ve gerçek sistemlerde $n$ yüzler mertebesinde olduğu için ağaç yüksekliği çok küçük kalır. Arama, aralık sorgusu ve ekleme işlemlerinin maliyeti ağacın yüksekliği kadardır; eklemede bölünmeler yukarı doğru yayılır ve ağaç kökten büyür. Silme ve hash yapılarının ayrıntısına girilmedi. Bu ders dönemin son dersiydi ve son dersler fiziksel tasarım konularına ayrılmıştı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
