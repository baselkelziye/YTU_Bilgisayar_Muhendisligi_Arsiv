# Ders 2 Genişletilmiş Notu: Dağıtık Dosya Sistemleri ve MapReduce Programlama Modeli

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kaynağı ve Planı
- 2. Neden Büyük Veri İçin Tek Makine Yetmez?
- 3. Küme (Cluster) Mimarisi
- 4. Küme Hesaplamanın Zorlukları
- 5. MapReduce'un Çözdüğü Problemler
- 6. Dağıtık Dosya Sistemi
- 7. HDFS Mimarisi: NameNode ve DataNode'lar
- 8. Isınma Problemi: Kelime Sayma
- 9. MapReduce Programlama Modeli
- 10. Bir Başka Örnek: 5 Kelimelik Dizileri Saymak
- 11. Zamanlama ve Veri Akışı
- 12. Koordinasyon ve Arıza Yönetimi
- 13. Kaç Map, Kaç Reduce Görevi?
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Kaynağı ve Planı

Ders büyük ölçüde İngilizce anlatıldı; yer yer Türkçe tekrarlar yapıldı. Konu, dersin ders kitabı olan *Mining of Massive Datasets* kitabının 2. bölümüydü: "Map-Reduce and the New Software Stack" (ekrandan, 00:05:00). Kitabın web sitesinde her bölüm için PDF ve PowerPoint slaytları ile video dersler bulunur; hoca derste bu slaytları kullandı ve öğrencilere her dersten sonra bu materyallerin üzerinden geçmelerini önerdi.

Dersin planı üç parçadan oluşuyordu:

- Dağıtık dosya sistemi (distributed file system).
- Hesaplama modeli: MapReduce programlama modelinin büyük veride paralel işlemeyi nasıl sağladığı.
- Büyük veri platformlarının zamanlamayı (scheduling) ve veri akışını nasıl yaptığı.

## 2. Neden Büyük Veri İçin Tek Makine Yetmez?

Bu derste kastedilen büyük ölçekli veri, tek bir makinenin fiziksel belleğine sığmayacak kadar büyük, hatta tek bir makinenin diskine bile sığmayabilecek veridir. Veriden bilgi çıkarmak için kullandığımız makine öğrenmesi ve istatistik algoritmalarının çoğu, verinin bellekte olduğunu varsayar: veri diskte durur, algoritma onu diskten belleğe getirir ve CPU'da işler. Veri büyüdükçe bu yaklaşım çöker.

### 2.1 Google örneği

Hoca bunu bir web dizinleme (indexing) örneğiyle açıkladı; yani Google'ın yaptığı işi yapmak istediğimizi düşünelim (ekrandan, 00:10:00):

- Verilen: 10 milyar web sayfası, ortalama sayfa boyu 20 KB.
- Toplam veri: $10 \times 10^9 \times 20\,\text{KB} = 200\,\text{TB}$.
- Disk okuma bant genişliği: 50 MB/s.
- Okuma süresi: $\dfrac{200\,\text{TB}}{50\,\text{MB/s}} = \dfrac{200 \times 10^{12}}{50 \times 10^6}\,\text{s} = 4 \times 10^6\,\text{s}$.
- Gün olarak: $4 \times 10^6 / 86400 \approx 46{,}3$ gün; slaytta "46+ days" yazar.

Hoca, diskin 200 TB'ı tutacak kadar büyük, hatta belleğin de bu veriyi alacak kadar büyük olduğunu varsaysak bile sorunun bitmediğini vurguladı: veri diskten belleğe ancak belli bir hızla okunabilir. Basit bir sayma işi için bile yalnızca okumak 46 günden fazla sürer; veriyle yararlı bir şey yapmak daha da uzun sürer.

Büyük veri işleme tekniklerinin önerisi şudur: bu büyük veriyi küçük parçalar halinde birden çok düğümde saklamak, aynı fonksiyonu bu düğümlerde paralel uygulamak ve düğümlerden gelen sonuçları birleştirmek. Dağıtık dosya sistemlerine duyulan ihtiyacın motivasyonu budur.

## 3. Küme (Cluster) Mimarisi

Dağıtık dosya sistemleri genellikle aynı yerde duran ve yüksek hızlı bir yerel ağ (LAN) ile birbirine bağlı makinelerden oluşan kümeler üzerine kurulur (ekrandan, 00:15:00).

- **Sıradan donanım (commodity hardware):** Kümedeki hesaplama düğümleri özel makineler değildir; ucuz fiyata her yerden alınabilen, dizüstü bilgisayarımızdaki CPU'nun ve günlük kullandığımız makinedeki bellek boyutunun benzerine sahip makinelerdir.
- **Linux:** Bu kutulara genellikle Linux kurulur. Açık kaynaklı olduğu için veri merkezleri işletim sistemi lisansı ödemez.
- **Rack (raf kabini):** Veri merkezlerinde bu sunucular raf kabinlerine dizilir, kabinler de römorklara (trailer) yerleştirilir. Bir raf 16-64 sıradan Linux düğümü içerir.
- **Raf içi bağlantı:** Raftaki bilgisayarlar bir anahtara (switch) bağlıdır; slayta göre raf içindeki herhangi iki düğüm arasında 1 Gbps bant genişliği vardır.
- **Raflar arası bağlantı:** Raflar, daha pahalı ve daha yüksek bant genişlikli bir anahtar üzerinden bağlanır; slaytta raflar arası omurga 2-10 Gbps olarak verilir.
- **Ölçek:** Slayta göre 2011'de Google'ın yaklaşık 1 milyon makinesi olduğu tahmin ediliyordu. Hoca bu şeklin eski olduğunu ama veri merkezlerinin büyüklüğü hakkında fikir verdiğini söyledi.

Slayttaki diyagramın yapısı:

```text
                 [Switch]  (raflar arası omurga, 2-10 Gbps)
                /        \
          [Switch]      [Switch]   (raf anahtarı; raf içinde 1 Gbps)
          /     \        /     \
   [CPU|Mem|Disk] ... [CPU|Mem|Disk] ... [CPU|Mem|Disk]
```

> **Ders sonrası not:** Hoca raf içi bant genişliğini anlatırken "1 GB per second" dedi; slaytta yazan 1 Gbps'dir (gigabit/saniye, yaklaşık 125 MB/s).

## 4. Küme Hesaplamanın Zorlukları

Tek makineden kümeye geçmek okuma süresi sorununu çözer ama yeni sorunlar getirir.

### 4.1 Düğüm arızaları

Slayttaki rakamlar (ekrandan, 00:20:00):

- Tek bir sıradan sunucu yaklaşık 3 yıl (1000 gün) ayakta kalır.
- 1000 sunuculu kümede: $1000 / 1000 = 1$ arıza/gün. Hoca bunun yönetilebilir olduğunu söyledi.
- 1 milyon sunuculu kümede: $10^6 / 1000 = 1000$ arıza/gün. Bu büyük bir sayıdır: düşen sunucuları onarmak, üzerlerinde çalışan işleri yeniden başlatmak ve bu sunuculardaki verinin başka kopyalarını kullanmaya başlamak gerekir.

Buradan iki soru doğar:

- **Veriyi kalıcı (persistent) saklamak ve düğümler düşse bile erişilebilir (available) tutmak nasıl olur?** Cevap: aynı verinin birden çok kopyasını farklı sunucularda saklamak. Bir ya da iki kopya kaybolsa bile diğer kopyalar kullanıcıya sunulabilir.
- **Uzun süren bir hesaplama sırasında düğüm düşerse ne olur?** Hoca örnek olarak büyük veri üzerinde bir sayma işi başlattığımızı düşünmemizi istedi. Veri büyük olduğu için sayma bile uzun sürer. O işi yürüten düğümün izlenmesi, yarıda bir şey olursa işin başka düğümde yeniden çalıştırılması, iş bittiyse sonucunun da o düğüme değil, başka bir sunucuya yazılması gerekir.

### 4.2 Ağ bant genişliği

Düğümler arasındaki bant genişliği sınırlıdır; yeni anahtarlar daha hızlı olsa da yine sınırlıdır. Slayttaki örnek: 10 TB veriyi 1 Gbps ile bir Linux kutusundan diğerine taşımak yaklaşık 1 gün sürer.

- Doğrulama (ara adım eklendi): $10 \times 10^{12}\,\text{bayt} \times 8 = 8 \times 10^{13}$ bit; $8 \times 10^{13} / 10^9 = 80\,000$ s $\approx 22{,}2$ saat, yani yaklaşık 1 gün.

Sonuç: veriyi düğümden düğüme taşımak istemeyiz. **Hesaplamayı verinin yanına götüren** bir çözüm gerekir.

### 4.3 Dağıtık programlamanın zorluğu

Kümede dağıtık programlama yapmak zordur: kümede kaç düğüm olduğunu bilmek, işleri düğümlere dağıtacak paralel kodu yazmak, çalışırken izlemek, bitince sonuçları alıp birleştirmek gerekir. Ayrıntılar çoktur.

### 4.4 Özet: dört zorluk

Hoca bu bölümü şöyle toparladı:

- Verinin kalıcı ve erişilebilir saklanması.
- Çalışan bir iş yarıda kalırsa ne yapılacağı.
- Veriyi taşımadan programlama yapmak (veri taşımak çok zaman alır).
- Dağıtık programlamanın karmaşıklığından kaçınmak.

## 5. MapReduce'un Çözdüğü Problemler

Bu zorlukları çözmek için yıllar içinde MapReduce programlama modeli ortaya kondu. Model ilk olarak Google'da çalışan mühendisler tarafından tanıtıldı. Model şu üç şeyi sağlar:

- **Yedekli saklama:** Veriyi parçalar halinde birden çok düğümde saklar. Bir parçaya bir şey olursa aynı parçanın kopyaları başka düğümlerde bulunur; kalıcılık ve erişilebilirlik böyle sağlanır.
- **Yerel işleme:** Hesaplamayı verinin bulunduğu yere götürür. MapReduce veriyi taşımaz, kodu verinin olduğu yere getirir; böylece veri hareketi en aza iner.
- **Basit programlama modeli:** Dağıtık hesaplamanın bütün karmaşıklığını programcıdan gizler.

Ancak MapReduce'u uygulamak için önce bir dağıtık dosya sistemine ihtiyaç vardır; model bunun var olduğunu varsayar. Bu yüzden ders önce dağıtık dosya sistemiyle devam etti.

## 6. Dağıtık Dosya Sistemi

### 6.1 Parçalar ve kopyalar

Dağıtık dosya sisteminde her dosya parçalar (chunk) halinde birden çok sunucuda saklanır ve her parça farklı makinelerde kopyalanır (replicate). Bu, kalıcılık ve erişilebilirliği sağlar (ekrandan, 00:30:00).

Slayttaki örnekte sunucuların içeriği şöyledir:

| Sunucu | Tuttuğu parçalar |
|---|---|
| Chunk server 1 | C0, C1, C5, C2 |
| Chunk server 2 | D0, C1, C5, C3 |
| Chunk server 3 | C2, C4, D0, D1 |
| Chunk server N | C0, C4, D1, C3 |

- C dosyası C0, C1, C2, C3, C4, C5 olmak üzere altı parçaya bölünmüştür. (Hoca önce "beş parça" dedi, sonra altı olduğunu düzeltti.)
- D dosyası D0 ve D1 olmak üzere iki parçaya bölünmüştür.
- Her parça iki farklı sunucuda bulunur; yani bu örnekte kopya sayısı (replication) 2'dir. Yapılandırmaya göre 2 ya da 3 olabilir.
- Parçaları saklamakla sorumlu sunuculara **chunk server** (parça sunucusu) denir.

### 6.2 Parça sunucuları aynı zamanda hesaplama sunucusudur

Slayttaki iki vurgu: "Chunk servers also serve as compute servers" ve "Bring computation to data!" Parça sunucuları yalnız depolama yapmaz, üzerlerinde iş de çalıştırılabilir. Örneğin C dosyası üzerinde çalışması gereken bir iş, C'nin parçalarını tutan bütün parça sunucularında çalışır. Böylece veriyi işin çalıştığı yere taşımak yerine kodu verinin olduğu parça sunucusuna götürürüz.

### 6.3 URI ve şeffaflık

Dağıtık dosya sistemi hangi parça sunucusunun bir dosyanın hangi bloklarını tuttuğunu izler. Google'ın kendi dağıtık dosya sistemi (GFS) vardır, Hadoop'un da kendi dağıtık dosya sistemi (HDFS) vardır; başka gerçekleştirimler de vardır, ama fikir aynıdır: dosyayı al, parçalara böl, bir URI ver. Dağıtık depolamayı kullanan istemci blokların nerede olduğunu bilmez, yalnız dosyanın URI'sini bilir. Dosyaya erişmek istediğinde URI'yi verir, dağıtık dosya sistemi veriyi getirir.

### 6.4 Tipik kullanım

Slayttaki "Redundant Storage Infrastructure" başlığı altında (ekrandan, 00:35:00):

- Dağıtık dosya sistemi global bir dosya ad alanı (namespace), yedeklilik ve erişilebilirlik sağlar. Örnekler: Google GFS, Hadoop HDFS.
- Dosyalar çok büyüktür: yüzlerce GB'tan TB'a (hoca petabayt düzeyini de ekledi).
- Veri yerinde nadiren güncellenir. Hoca bunu "salt okunur veri" diye niteledi: geri dönüp veriyi değiştirmeyiz.
- Okuma ve ekleme (append) işlemleri yaygındır.

Hoca bunu operasyonel veritabanlarıyla karşılaştırdı. MySQL, Oracle, MS SQL gibi operasyonel veritabanları, verinin değerini ya da tablo yapısını düşük gecikmeyle değiştirmek için tasarlanmıştır. Dağıtık dosya sistemleri ise salt okunur veriyi tutmak için tasarlanmıştır; güncelleme neredeyse hiç görülmez.

Örnek veri türü: uygulama sunucusu log dosyaları. IIS ya da Apache Tomcat gibi uygulama sunucuları web uygulamalarını çalıştırır ve her erişimde log dosyası üretir. Zamanla bu log dosyaları çok büyür. Ekleme işleminin anlamı da buradan anlaşılır: geçmiş aylara ait 100 log dosyası saklıyorsak, yeni gelen log dosyasını mevcut dosyaların sonuna ekleriz.

### 6.5 Bileşenler

Slaytta dağıtık dosya sisteminin üç bileşeni şöyle verilir (ekrandan, 00:40:00):

- **Parça sunucuları (chunk servers)**
  - Dosya bitişik parçalara bölünür (16-64 MB).
  - Her parça kopyalanır (genelde 2 ya da 3 kez).
  - Kopyalar farklı raflarda tutulmaya çalışılır.
- **Ana düğüm (master node)**
  - Hadoop HDFS'te adı NameNode'dur.
  - Dosyaların nerede saklandığına dair üst veriyi (metadata) tutar: her dosya ve ona ait blokların yerleri.
  - Kendisi de kopyalanabilir.
- **Dosya erişimi için istemci kütüphanesi (client library)**
  - Parça sunucularını bulmak için master ile konuşur.
  - Veriye erişmek için doğrudan parça sunucularına bağlanır.

Kopyaların neden farklı raflarda tutulduğunu hoca şöyle açıkladı: bir raf kabinindeki bütün Linux kutuları o rafın anahtarına bağlıdır ve ağa o anahtar üzerinden çıkar. Kopyalar aynı rafta olsaydı rafın anahtarındaki bir sorun bütün kopyaları aynı anda erişilemez kılardı.

### 6.6 İstemci kütüphanesinin çalışması

Her dağıtık dosya sisteminin bir istemci kütüphanesi vardır; HDFS kullanırken HDFS'in istemci kütüphanesini kullanırız. Bu kütüphane şeffaflık sağlar, yani verinin parça sunucularından nasıl getirildiğini gizler. Kullanıcı açısından iki temel yöntem vardır:

- **put:** Dosyayı parça sunucularına yerleştirir.
- **get:** Dosyayı dağıtık dosya sisteminden geri getirir.

Bir dosya okunurken adımlar şöyledir:

- İstemci kütüphanesine URI verilir.
- Kütüphane master ile konuşur: "Bu URI'ye ait blokların listesini ver."
- Master, blokların listesini ve bu blokları tutan parça sunucularının IP adreslerini döndürür.
- Kütüphane bu parça sunucularıyla ayrı ayrı konuşup blokları alır.
- Bütün bloklar gelince kütüphane onları birleştirir ve dosyayı kullanıcıya verir.

Master, bütün veri bloklarının nerede olduğunu bilmenin tek yoludur. Bu yüzden sistemin kalıcı olması için master'ın da genellikle kopyalanması gerekir.

## 7. HDFS Mimarisi: NameNode ve DataNode'lar

Aradan sonra hoca HDFS'e dair birkaç slayt daha gösterdi. Burada "client" HDFS'in istemci kütüphanesidir. İstemci bir dosyaya erişmek istediğinde önce NameNode'a sorar; NameNode bloğu almak için hangi parça sunucularına gitmesi gerektiğini söyler.

Slayttaki mimari şekil (ekrandan, 01:05:00): NameNode üst verisi `(Filename, numReplicas, block-ids, ...)` biçimindedir. Örnekte iki dosya vardır (yol önekleri slaytta bir kullanıcı dizini içerir, burada kısaltıldı):

| Dosya | Kopya sayısı | Blok kimlikleri |
|---|---|---|
| `.../data/part-0` | 2 | {1, 3} |
| `.../data/part-1` | 3 | {2, 4, 5} |

Sekiz DataNode'un tuttuğu bloklar şekilde şöyledir: {1, 2}, {2}, {1, 4}, {2, 5}, {5, 3}, {4}, {3, 5}, {4}. Buna göre 1 ve 3 numaralı bloklar ikişer kez, 2, 4 ve 5 numaralı bloklar üçer kez farklı DataNode'larda bulunur; bu da üst verideki kopya sayılarıyla uyumludur (ara adım eklendi: blokların kaç DataNode'da geçtiği şekilden sayıldı).

Hoca ayrıca şunları anlattı:

- Üst veride blokların hangi parça sunucularında (IP adresleriyle) bulunduğu da tutulur.
- **Okuma:** İstemci önce NameNode'dan parça sunucularının yerini alır, sonra doğrudan ilgili parça sunucularıyla iletişim kurup veriyi okur.
- **Yazma (create/put):** İstemci URI'yi verir, NameNode hangi yerlere yazılacağını söyler ve yazmayı istemci yapar.
- **Kopyalama:** Bir bloğun kaç kez kopyalanması gerektiğini NameNode izler. Gerekirse bir parça sunucusuna bloğu başka bir sunucuya kopyalamasını söyler ve hedef sunucunun kimliğini ve IP adresini verir. Yani orkestrasyonu NameNode yapar.

## 8. Isınma Problemi: Kelime Sayma

MapReduce'un nasıl çalıştığını anlatmadan önce hoca somut bir problem koydu (ekrandan, 00:45:00):

- Elimizde dev bir metin belgesi var; boyutu, örneğin, 100 GB.
- Dosyadaki her farklı kelimenin kaç kez geçtiğini saymak istiyoruz. Örneğin dosyada 1000 farklı kelime varsa her biri için belgede kaç kez geçtiğini bulmalıyız.

Bu problem farklı uygulamalarda karşımıza çıkar:

- **Web sunucusu loglarından popüler URL'leri bulmak:** Log dosyası 100 GB düzeyindedir; her farklı URL'nin kaç kez geçtiğini saymak aynı kelime sayma problemidir.
- **Arama için terim istatistiği:** Bu kez arama uygulamasının log dosyasına bakılır ve arama kutusunda her farklı anahtar kelimenin kaç kez arandığı sayılır. Bu da aynı problemdir.

### 8.1 Durum 1: Dosya belleğe sığmaz, çiftler sığar

Slayt (ekrandan, 00:50:00): "File too large for memory, but all <word, count> pairs fit in memory." Dosya 100 GB düzeyinde olduğu için belleğe sığmaz, ama farklı kelime sayısı sınırlı olduğundan `<kelime, sayı>` çiftleri belleğe sığar.

Çözüm: bellekte bir hash tablosu tutulur. Diskteki veri sırayla okunur; her kelimeyle karşılaşıldığında kelime tabloda varsa sayacı bir artırılır, yoksa tabloya eklenir. Bütün log dosyası baştan sona taranınca tablo sonucu verir.

### 8.2 Durum 2: Çiftler bile belleğe sığmaz

Slayt (ekrandan, 01:10:00): "Even the <word,count> pairs don't fit in memory." Bu durumda veriyi birden çok düğüme bölüp işlemeyi paralel yapan bir çözüm gerekir.

Hoca önce bu problemin MapReduce olmadan Linux'ta nasıl çözülebileceğini gösterdi. Slayttaki boru hattı:

```text
words(doc.txt) | sort | uniq -c
```

- `words`: dosyayı alır ve içindeki kelimeleri her satıra bir kelime gelecek biçimde konsola döker.
- `|` (boru): bir komutun çıktısını sonraki komuta girdi olarak verir.
- `sort`: gelen kelimeleri sözlük sırasına (lexicographical order) dizer; böylece aynı kelimeler yan yana gelir, gruplanmış olur.
- `uniq -c`: her gruptan tek bir temsilci kelime alır; `-c` (count) seçeneğiyle her grubun eleman sayısını da yazar.

Hoca örnek verdi: "apple" kelimesi altı kez geçiyorsa `sort` altı "apple"ı yan yana getirir, `uniq -c` bunları tek bir "apple" satırına indirip yanına 6 yazar.

Slayta göre Durum 2 MapReduce'un özünü yakalar ve en güzel yanı doğal olarak paralelleştirilebilir olmasıdır. Boru hattının üç adımı MapReduce'un üç adımına karşılık gelir:

| Linux adımı | MapReduce karşılığı | Kim yapar? |
|---|---|---|
| `words` | Map: girdiden ilgilendiğimiz şeyi (kelimeleri) çıkarır | Programcı |
| `sort` | Group by key: aynı anahtarlı çiftleri bir araya getirir | Platform (Hadoop, Spark, Flink vb.) |
| `uniq -c` | Reduce: aynı şeylerin grubunu bir sonuca indirger (sayar, toplar, özetler) | Programcı |

> **Ders sonrası not:** Hoca gruplamayı yapan platformları sayarken bir yerde "Apache Spring" dedi. Spring bir Java uygulama çatısıdır, MapReduce platformu değildir; büyük olasılıkla Spark ya da Flink kastedildi.

## 9. MapReduce Programlama Modeli

### 9.1 Map adımı

Slayttaki şekil (ekrandan, 01:15:00) solda girdi anahtar-değer çiftlerini (input key-value pairs), sağda ara anahtar-değer çiftlerini (intermediate key-value pairs) gösterir; her girdi çiftine `map` uygulanır ve birden çok ara çift çıkar.

Girdi çiftinin anlamını hoca dağıtık dosya sistemi örneğine dönerek açıkladı: C dosyası C0-C5 parçalarına bölünür. Her parçanın, dağıtık dosya sisteminin izlediği tekil bir kimliği vardır; bu kimlik **anahtar** (key), parçanın içeriği **değer**dir (value). C dosyasının altı bloğu olduğuna göre C0'dan C5'e altı farklı anahtar ve bunlara karşılık gelen blok içerikleri vardır.

Map fonksiyonu bu anahtar-değer çiftini alır, değeri (içeriği) okur ve ilgilendiğimiz şeyi çıkarır; kelime saymada bu, kelimelerdir. Linux'taki `words` komutu gibi her kelimeyi tek tek çıkarır ve değer olarak 1 yazar: "Apple 1"; "Apple" yine görülürse yine "Apple 1". Map sayma yapmaz, yalnız çıkarır. Sonuçta her bloktan bir ara anahtar-değer çiftleri kümesi elde edilir.

### 9.2 Group by key ve Reduce adımı

Slayttaki şekil (ekrandan, 01:20:00): ara anahtar-değer çiftleri "Group by key" ile anahtar-değer gruplarına dönüşür; örneğin bir anahtarın üç değeri (v, v, v), bir başkasının iki değeri (v, v) olur. Her gruba `reduce` uygulanır ve çıktı anahtar-değer çiftleri (output key-value pairs) elde edilir.

- **Group by key:** Map bitince platform, Linux'taki `sort` gibi, aynı anahtara sahip çiftleri bir araya getirir. Bu adım sıralama ve karıştırma (sorting and shuffling) olarak da anılır.
- **Reduce:** Programcının yazdığı fonksiyondur. Ara çiftleri alır ve değerler üzerinde bir fonksiyon uygular. Kelime saymada fonksiyon toplamadır: üç tane 1 varsa sonuç 3, iki tane 1 varsa sonuç 2 olur.

Programcı yalnız iki şeyi yazar: map fonksiyonu ve reduce fonksiyonu. Aradaki group by key adımı MapReduce platformunun işidir.

### 9.3 Biçimsel tanım

Slayt "More formally..." (ekrandan, 01:25:00):

- **Girdi:** bir anahtar-değer çiftleri kümesi.
- Programcı iki yöntem tanımlar:
  - $\text{Map}(k, v) \rightarrow \langle k', v' \rangle^*$
    - Bir anahtar-değer çifti alır ve bir anahtar-değer çiftleri kümesi üretir.
    - Her $(k, v)$ çifti için bir Map çağrısı vardır.
  - $\text{Reduce}(k', \langle v' \rangle^*) \rightarrow \langle k', v'' \rangle^*$
    - Aynı $k'$ anahtarına sahip bütün $v'$ değerleri birlikte indirgenir.
    - Her tekil $k'$ anahtarı için bir Reduce çağrısı vardır.

Hoca gösterimi şöyle okudu: $k$ blok kimliği (ör. C0), $v$ blok içeriğidir. Yıldız (*), çıktıda birden çok $\langle k', v' \rangle$ çifti olduğunu gösterir; $k'$ içerikten çıkarmak istediğimiz şeydir (burada kelimeler). Platform ara çiftleri gruplayıp ilk elemanı $k'$, ikinci elemanı değerler listesi olan çiftler kurar ve bunları Reduce'a verir. Reduce, ilk elemanı $k'$, ikinci elemanı değerlere uygulanan fonksiyonun sonucu olan çiftler üretir. Saymada bu fonksiyon toplamadır; çarpma ya da ortalama da olabilir. Sonuçta farklı kelimelerin ve belgelerde kaç kez geçtiklerinin listesi elde edilir.

### 9.4 Kelime sayma örneği

Slayt "MapReduce: Word Counting" (ekrandan, 01:30:00). Büyük belge HDFS'te dört parça halinde saklanmıştır. Belgenin başı: "The crew of the space shuttle Endeavor recently returned to Earth as ambassadors, harbingers of a new era of space exploration. ..."

| Aşama | Kim sağlar? | Ne yapar? | Örnek çıktı |
|---|---|---|---|
| MAP | Programcı | Girdiyi okur, anahtar-değer çiftleri üretir | (The, 1), (crew, 1), (of, 1), (the, 1), (space, 1), (shuttle, 1), (Endeavor, 1), (recently, 1), ... |
| Group by key | Platform | Aynı anahtarlı bütün çiftleri toplar | (crew, 1), (crew, 1), (space, 1), (the, 1), (the, 1), (the, 1), (shuttle, 1), (recently, 1), ... |
| Reduce | Programcı | Anahtara ait bütün değerleri toplayıp çıktı verir | (crew, 2), (space, 1), (the, 3), (shuttle, 1), (recently, 1), ... |

Slaytın sağındaki okta "Only sequential reads" yazar: veriler yalnız sırayla okunur.

Hoca şekli şöyle anlattı: her parça ayrı bir parça sunucusundadır ve her parça sunucusu map sürecini çalıştırır. Map parçanın kimliğini anahtar, içeriğini değer olarak alır ve kelimeleri tek tek, değer olarak 1 yazarak çıkarır. Map bitince platform aynı kelimeleri yan yana gelecek biçimde gruplar ve sıralar. Sonra platform reducer'lara sinyal gönderir ve her birine girdisini nereden alacağını söyler; şekilde üç mapper ve üç reducer vardır. Reducer kendi girdisini gidip alır ve reduce fonksiyonunu uygular: "crew" iki değere sahiptir, toplam 2; "space" tek değere sahiptir, sonuç 1. Her reducer sonucunu yazar.

### 9.5 Kodun yapısı

Hoca, word count için map ve reduce fonksiyonlarının sözde kodunu gösteren bir slayt anlattı. Mapper'da belgedeki her kelime için bir döngüyle `(kelime, 1)` üretilir. Reduce kısmı girdi olarak bir anahtar (tek bir kelime) ve bir değerler dizisi alır; başta sonuç sıfırdır ve dizideki değerler toplanarak kelimenin kaç kez geçtiği bulunur.
<!-- BELİRSİZ: Sözde kod slaytının karesi yok ve altyazının bu kısmı (01:31-01:33) bozuk; kodun tam metni aktarılamadı. -->

Hocanın bu kısımdaki vurgusu: MapReduce geliştirici için programlamayı çok basitleştirir. Yapılması gereken yalnız map fonksiyonuna ve reduce fonksiyonuna ne yazılacağını bulmaktır. Bunu bulduktan sonra herhangi bir MapReduce platformu (Hadoop, Spark, Apache Flink ya da başka bir platform) kullanılarak uygulama dağıtık veri üzerinde çalıştırılabilir.

> **Hocanın vurgusu:** Programcı yalnız Map ve Reduce'u yazar; dağıtık programlamanın bütün karmaşıklığını platform gizler.

## 10. Bir Başka Örnek: 5 Kelimelik Dizileri Saymak

Slayt "Example: Language Model" (ekrandan, 01:35:00):

- Problem: Büyük bir belge derleminde (corpus) her 5 kelimelik dizinin kaç kez geçtiğini saymak.
- Map: Belgeden `(5 kelimelik dizi, sayı)` çiftlerini çıkarmak.
- Reduce: Sayıları birleştirmek.

Hoca beş farklı kelimeden oluşan bir dizi örneği verdi (ör. "Apple, School, Car, Object, Water") ve soruyu şöyle açtı: bu tekil dizi belgede kaç kez geçiyor? Bu kez map fonksiyonu her seferinde tek kelime yerine 5 kelimelik diziler çıkarır, değer yine 1'dir. Reduce ise kelime sayma örneğiyle aynıdır: değerler dizisindeki 1'ler toplanır.

## 11. Zamanlama ve Veri Akışı

### 11.1 Genel diyagram

Slayt "Map-Reduce: A diagram" (ekrandan, 01:40:00). Büyük belge HDFS'e konmuş ve parçalara bölünmüştür; şekilde parçaların boyları farklı görünse de hoca hepsinin aynı boyda olduğunu düşünmemizi istedi. Şekildeki akış:

```text
Input:        [Big document | . | . | . | . | . | . ]
                 M     M    M    M     M    M    M     (7 map)
Intermediate: [k1:v k1:v k2:v] [ ] [k1:v] [k3:v k4:v] [k4:v k5:v] [k4:v] [k1:v k3:v]
                              Group by Key
Grouped:      [k1:v,v,v,v] [k2:v] [k3:v,v] [k4:v,v,v] [k5:v]
                  R           R      R         R         R     (5 reduce)
Output:       [ ] [ ] [ ] [ ] [ ]
```

Slaytın sol tarafındaki açıklamalar:

- **MAP:** Girdiyi okur ve bir anahtar-değer çiftleri kümesi üretir.
- **Group by key:** Aynı anahtarlı bütün çiftleri toplar (hash merge, shuffle, sort, partition).
- **Reduce:** Anahtara ait bütün değerleri toplar ve çıktı verir.

Her parça farklı bir parça sunucusunda saklanır ve her parça sunucusunda bir map fonksiyonu çalışır. Map o parçadaki kelimeleri çıkarır, değer olarak 1 yazar. 5 kelimelik dizi örneğinde anahtar 5 kelimelik dizi, değer yine 1 olur.

### 11.2 Yerel depolama ile dağıtık depolama

Hoca burada Türkçe bir açıklama yaptı: her parça sunucusunda iki tür depolama vardır.

- **Yerel depolama:** Normal kullandığımız sabit disktir. Sunucuda bir Linux işletim sistemi vardır.
- **HDFS:** Bu işletim sistemi üzerine HDFS kurulur. Dosya sistemi tek düğümlü de olabilir, çok düğümlü dağıtık bir dosya sistemi de. Bir dosya HDFS'e yüklendiğinde HDFS onu parçalara ayırır ve parçaları çok sayıda düğüme kopyalar.

Yerel depolamaya konan bir şeyin ise başka yerlerde kopyası yaratılmaz; yalnız o anda mapper'ın çalıştığı düğümün yerel diskine yazılır.

Map süreci ara anahtar-değer çiftlerini **yerel depolamaya** yazar, dağıtık dosya sistemine değil. Ardından platform her parça sunucusu için aynı anahtarlı çiftleri bir araya getirir; bu gruplama mapper'ın çalıştığı parça sunucusunda yapılır. Gruplama bitince mapper master'a "bitirdim, reducer'ı çağırıp ara anahtar-değer çiftlerini alabilirsin" diye haber verir. Master ilgili reducer'ı bilgilendirir; reducer sorumlu olduğu anahtar-değer çiftlerini kendi çalıştığı parça sunucusuna kopyalar ve reduce fonksiyonunu (burada toplama) uygulayıp sonucu anahtar-değer çifti olarak üretir.

### 11.3 Paralel çalışma ve bölümleme fonksiyonu

Slayt "Map-Reduce: In Parallel" (ekrandan, 01:45:00 ve 01:55:00):

```text
Map Task 1: 3 map  -> [k1:v k1:v k2:v] [ ] [k1:v]   -> Partitioning Function
Map Task 2: 2 map  -> [k3:v k4:v] [k4:v k5:v]       -> Partitioning Function
Map Task 3: 2 map  -> [k4:v] [k1:v k3:v]            -> Partitioning Function

Reduce Task 1: Sort and Group -> [k2:v] [k4:v,v,v] [k5:v] -> 3 reduce
Reduce Task 2: Sort and Group -> [k1:v,v,v,v] [k3:v,v]    -> 2 reduce
```

Slaytın altında "All phases are distributed with many tasks doing the work" yazar: bütün aşamalar dağıtıktır ve işi birçok görev yapar.

Hocanın anlatımı:

- Her parça için bir mapper vardır. Mapper ara anahtar-değer çiftlerini üretir.
- **Bölümleme fonksiyonu (partitioning function)** bir hash fonksiyonudur. Anahtarı (ör. k1) girdi olarak alır ve bir reducer numarası üretir. Hoca beş reducer'lı bir örnekte bir anahtarın 4 numaralı reducer'a düştüğünü söyledi.
- Mapper master'a işini bitirdiğini bildirir. Master ilgili reducer'a, hangi parça sunucusuna gidip hangi anahtarın çiftlerini alacağını söyler. Örneğin 4 numaralı reducer'a "1 numaralı map parça sunucusuna git ve anahtarı k1 olan çiftleri al" denir.
- Hocanın Türkçe tekrarındaki örnek: k4'ün çiftlerinin bir kısmı bir parça sunucusunda, bir kısmı başka bir parça sunucusundadır. Reducer'a "k4 ile ilgili anahtar-değer çiftlerini ilgili parça sunucularından al" denir. Reducer bunları getirir, sonra **Sort and Group** işlemi yapılır; bunu da platform yapar.
- Ardından programcının yazdığı Reduce fonksiyonu, gruplanmış ve aynı anahtara sahip çiftleri alıp ne yazıldıysa onu yapar; toplama yazıldıysa toplar ve sonucu yazar.
- Her reducer'ın ürettiği sonuç **HDFS'e**, yani dağıtık dosya depolamasına yazılır, yerel depolamaya değil.

Neden böyle? Hoca şöyle gerekçelendirdi: girdi dosyaları ve elde edilen sonuçlar önemlidir, güvenilir (reliable) bir depolamada durmalıdır. Aradaki ara anahtar-değer çiftleri ise ileride kullanılmayacağı için dağıtık depolamaya yazılmalarının anlamı yoktur; dağıtık dosya sistemine yazılsalar gereksiz yere kopyalanırlar.

> **Hocanın vurgusu:** Girdi ve nihai çıktı dağıtık dosya sisteminde, ara sonuçlar yerel diskte durur.

Hoca bu bölümde, bir mapper'ın çalıştığı düğüm düşerse o mapper'ın başka bir parça sunucusunda yeniden çalıştırılması gerektiğini de söyledi. Master her mapper'ın boşta mı, çalışmakta mı, işini bitirmiş mi olduğunu izler ve duruma göre mapper'ı başka bir parça sunucusunda yeniden yaratır. Bunu mutlaka düşen parça sunucusundaki blokların kopyalarının bulunduğu parça sunucularında yapar; böylece hesaplama yine verinin yanına gider.

### 11.4 MapReduce ortamının üstlendikleri

Slayt "Map-Reduce: Environment" (ekrandan, 01:50:00). MapReduce ortamı şunları üstlenir:

- Girdi verisini bölümlemek (partitioning). Platform dağıtık dosya sistemiyle çalıştığı ve dosya sistemi veriyi zaten parçalara böldüğü için bu kendiliğinden olur.
- Programın birden çok makinede çalışmasını zamanlamak (scheduling). Platformda yalnız kaç mapper ve kaç reducer çalıştırmak istediğimizi tanımlarız; zamanlamayı ortam yapar.
- Group by key adımını gerçekleştirmek.
- Düğüm arızalarını ele almak: bir düğüm düşerse map ve reduce işlerini başka düğümlerde çalıştırmak. Geliştirici olarak arızaları ele almaktan biz sorumlu değiliz.
- Gerekli makineler arası iletişimi yönetmek. Örneğin map görevi bitince master'a sinyal gider, master da reducer'a hangi IP adresine gidip anahtar-değer çiftlerini alacağını söyler.

Hoca ayrıca gerçek problemlerde genellikle bir MapReduce boru hattı olduğunu ekledi: map, reduce, sonra yine map, reduce... Kelime sayma örneğinde tek bir map ve tek bir reduce aşaması vardı, ama genelde daha karmaşık problemlerle karşılaşırız ve birbirini izleyen birden fazla MapReduce aşaması görürüz.

## 12. Koordinasyon ve Arıza Yönetimi

### 12.1 Master'ın koordinasyon rolü

Her mapper ve reducer görevi için üç durum vardır:

- **idle** (boşta),
- **in-progress** (sürmekte),
- **completed** (tamamlandı).

Hoca bunu şöyle örnekledi: başta altı mapper olacağını söylersek altı mapper'ın hepsi boşta durumundadır. Master mapper'lara bakar; boşta olan ilk mapper'ı ilk parçayı işlemeye, boşta olan ikinci mapper'ı ikinci parçayı işlemeye atar ve böyle devam eder.

Bir map görevi bittiğinde master'a ara dosyaların yerini ve boyutlarını gönderir: "Bitirdim; ara anahtar-değer çiftlerimin adları bunlar, çalıştığım parça sunucusunun IP adresi bu." Master bu bilgiyi reducer'lara iletir.

Hocanın örneği: 4 numaralı map görevi tamamlanır ve master'a "k3 ve k4 anahtarlarım var, çalıştığım parça sunucusu (2 numara) burada" der. Master k3'ü hash fonksiyonuna koyar ve sonuç 5 numaralı reducer çıkar; 5 numaralı reducer'a "2 numaralı parça sunucusuna git, şu adlı dosyayı al" diye sinyal gönderir. Sonra k4'ü hash fonksiyonuna koyar; k4'ten 2 numaralı reducer sorumlu çıkar ve ona da k4 için oluşturulmuş dosyayı almasını söyler. Her mapper master'a bu şekilde haber verir, master da reducer'ları tetikler.

Master arızaları fark etmek için işçileri (worker) periyodik olarak yoklar (ping).

### 12.2 Arıza durumları

Slayt "Dealing with Failures" (ekrandan, 02:00:00):

- **Map işçisi arızası**
  - İşçideki tamamlanmış ya da sürmekte olan map görevleri boşta durumuna alınır.
  - Boştaki görevler sonunda başka işçilerde yeniden zamanlanır.
- **Reduce işçisi arızası**
  - Yalnız sürmekte olan görevler boşta durumuna alınır.
  - Boştaki Reduce görevleri başka işçilerde yeniden başlatılır.
- **Master arızası**
  - MapReduce işi iptal edilir ve istemciye bildirilir.

Hocanın anlatımı:

- Map işçisi düşerse: o işçide sürmekte ya da tamamlanmış durumdaki map görevleri master'da boşta durumuna çekilir ve başka bir parça sunucusunda başlatılır. Düşen işçide boştaki map görevleri varsa onlar da başka işçilere zamanlanır.
- Reduce işçisi düşerse: master o işçideki reduce görevlerinin durumuna bakar. Sürmekte olanlar boşta durumuna alınır; boştakiler başka işçilerde yeniden başlatılır. Tamamlanmış reduce görevleri ise yeniden zamanlanmaz: tamamlanmış bir reduce işinin sonucu dağıtık dosya depolamasına yazılmıştır, yalnız o düğümde değil, başka düğümlerde de kopyası vardır; dolayısıyla sonuç erişilebilirdir.
- Master (NameNode) düşerse: MapReduce işi iptal edilir ve istemci bilgilendirilir; master onarılınca istemcinin bütün MapReduce sürecini yeniden başlatması istenir.

> **Ek bilgi (derste anlatılmadı):** Tamamlanmış map görevlerinin de yeniden çalıştırılmasının nedeni büyük olasılıkla şudur: map çıktısı DFS'e değil, düşen işçinin yerel diskine yazılmıştır; işçi düşünce bu ara sonuçlara erişilemez. Reduce çıktısı ise DFS'te kopyalı olduğu için kaybolmaz.

> **Ders sonrası not:** Hoca derste master ile HDFS NameNode'u aynı bileşen gibi anlattı (mapper'ın bitince NameNode'a haber vermesi, NameNode'un reducer'ları tetiklemesi, master arızasının NameNode arızası olması gibi). Slaytlar yalnız "master" der. Klasik Hadoop'ta HDFS NameNode dosya sistemi üst verisini tutar; MapReduce görevlerinin zamanlanmasını ve izlenmesini ise büyük olasılıkla ayrı bir ana bileşen (Hadoop 1'de JobTracker, Hadoop 2 ve sonrasında YARN ResourceManager ve uygulama yöneticisi) yapar.

## 13. Kaç Map, Kaç Reduce Görevi?

Hocanın verdiği pratik kural:

- **Map görevi sayısı ($M$):** Genelde her parça (chunk) için bir map görevi seçilir. Bir dosyanın kaç parçası varsa MapReduce işi başlatılırken o kadar map görevi başlatılabilir.
- **Reduce görevi sayısı ($R$):** $M$'den çok daha küçüktür. Reducer'ların çıktısı HDFS'e yazıldığı için çok fazla reducer yaratmak istenmez.

<!-- BELİRSİZ: Hoca bu kısımda üç parça sunucusu ve yedi mapper'lı bir örnek üzerinden bir kural daha söyledi (map görevi sayısının düğüm sayısından çok daha büyük seçilmesiyle ilgili görünüyor), ancak altyazı bu aralıkta (02:00:12-02:00:43) bozuk ve slaytın karesi yok. -->

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): 10 milyar web sayfası, ortalama sayfa boyu 20 KB ve disk okuma bant genişliği 50 MB/s ise bütün veriyi tek bir diskten okumak ne kadar sürer?

> **Çözüm (derste verildi):** Toplam veri $10^{10} \times 20\,\text{KB} = 200\,\text{TB}$. Okuma süresi $200 \times 10^{12} / (50 \times 10^6) = 4 \times 10^6$ s $\approx 46{,}3$ gün; slaytta "46+ days".

**Soru 2** (ekrandan, 00:20:00): Tek bir sunucu ortalama 1000 gün ayakta kalıyorsa 1000 ve 1 milyon sunuculu kümelerde günde kaç arıza beklenir?

> **Çözüm (derste verildi):** $1000/1000 = 1$ arıza/gün ve $10^6/1000 = 1000$ arıza/gün.

**Soru 3** (ekrandan, 00:20:00): Düğümler düşebiliyorsa veri nasıl kalıcı ve erişilebilir saklanır? Uzun süren bir hesaplama sırasında düğüm düşerse ne yapılır?

> **Çözüm (derste verildi):** Veri parçalara bölünüp her parça farklı makinelerde (tercihen farklı raflarda) 2-3 kez kopyalanır. Hesaplama sırasında düğüm düşerse master görevin durumuna bakar ve görevi düşen düğümdeki blokların kopyalarını tutan başka bir düğümde yeniden çalıştırır; sonuçlar kopyalı depoya (DFS) yazılır.

**Soru 4** (ekrandan, 00:45:00 ve 01:10:00): Dev bir metin dosyasında her farklı kelimenin kaç kez geçtiği nasıl sayılır? (a) Dosya belleğe sığmıyor ama `<kelime, sayı>` çiftleri sığıyor; (b) çiftler de sığmıyor.

> **Çözüm (derste verildi):** (a) Dosya diskten sırayla okunur, bellekteki hash tablosunda her kelimenin sayacı artırılır. (b) `words(doc.txt) | sort | uniq -c` boru hattının dağıtık karşılığı olan MapReduce kullanılır: Map `(kelime, 1)` üretir, platform anahtara göre gruplar, Reduce değerleri toplar.

**Soru 5** (ekrandan, 01:35:00): Büyük bir belge derleminde her 5 kelimelik dizinin kaç kez geçtiğini MapReduce ile nasıl sayarsınız?

> **Çözüm (derste verildi):** Map belgeden her 5 kelimelik diziyi `(dizi, 1)` çifti olarak çıkarır; Reduce aynı diziye ait 1'leri toplar.

**Soru 6** (derste sözlü, 02:02:23): Bir öğrenci sohbetten sordu: Reduce görevi tamamlanmadan doğrudan boşta (idle) durumuna mı resetleniyor?

> **Cevap (derste verildi):** Master, reduce görevinin çalıştığı işçinin düştüğünü fark ettiğinde görevin durumuna bakar. Görev tamamlanmışsa sonucu dağıtık dosya depolamasına mutlaka yazılmıştır ve kopyaları farklı yerlerde bulunur; yeniden çalıştırılmaz. Görev boştaysa, başta belirlenen sayıda (ör. 5) reducer'ın korunması için başka bir düğümde yeniden çalıştırılır. Görev sürmekteyse, henüz girdisini alıp işleyip sonuç üretmemiş demektir; boşta durumuna alınır ve başka bir düğümde yeniden çalıştırılır. Yeni reducer'a hangi girdileri alacağı master tarafından söylenir; reducer kendisine atanmış parça sunucularına gidip anahtar-değer çiftlerini, düşen reducer'ın yapacağı gibi alır ve işler.

## Dersin Toparlaması

Bu derste büyük verinin neden tek makinede işlenemeyeceği (200 TB'ı 50 MB/s ile okumak 46 günden fazla sürer) ve kümeye geçince ortaya çıkan zorluklar görüldü: düğüm arızaları, sınırlı ağ bant genişliği ve dağıtık programlamanın karmaşıklığı. Bunlara cevap olarak önce dağıtık dosya sistemi (GFS, HDFS) incelendi: dosyalar 16-64 MB'lık parçalara bölünür, parçalar farklı raflardaki parça sunucularına 2-3 kez kopyalanır, master (HDFS'te NameNode) üst veriyi tutar ve istemci kütüphanesi master'dan yeri öğrenip veriyi doğrudan parça sunucularından alır. Ardından kelime sayma problemi üzerinden MapReduce modeli kuruldu: Map ilgilenilen anahtar-değer çiftlerini çıkarır, platform anahtara göre gruplar, Reduce her anahtarın değerlerini toplulaştırır. Son olarak bölümleme fonksiyonu, ara sonuçların yerel diske, girdi ve çıktının DFS'e yazılması, görev durumları (idle, in-progress, completed) ve map, reduce ve master arızalarında yapılanlar anlatıldı.

Hoca, bir sonraki derste MapReduce platformunda işlerin daha verimli yapılması için kullanılan iyileştirmelerden (refinements) bahsedip 2. bölümü tamamlayacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
