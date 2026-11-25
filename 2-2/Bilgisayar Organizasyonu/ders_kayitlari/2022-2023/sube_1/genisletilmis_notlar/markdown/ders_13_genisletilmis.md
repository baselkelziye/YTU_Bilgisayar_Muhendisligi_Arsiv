# Ders 13 Genişletilmiş Notu: Önbellek Tasarımı: Eşleme Yöntemleri, Adres Bölümleme, Doğrudan Eşlemeli Erişim, Ortalama Erişim Süresi ve Yer Değiştirme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bellek hiyerarşisi ve yerellik
- 2. Önbellek tasarımının soruları
- 3. Üç eşleme yöntemi
- 4. Küçük bir doğrudan eşlemeli önbellek
- 5. Doğrudan eşlemenin sorunu ve blok genişliğinin etkisi
- 6. 16 KB'lık doğrudan eşlemeli önbellekte adres bölümleme
- 7. Doğrudan eşlemeli önbellekte dört adrese erişim
- 8. Erişim durumları: ıska, blok değiştirme ve isabet
- 9. Önbellek çakışması (thrashing) örneği
- 10. Ortalama erişim süresi
- 11. İki seviyeli önbellekte ortalama erişim süresi
- 12. Yer değiştirme algoritmaları
- 13. Üç eşleme için adres bölümleme örneği
- Örnek Sorular

Bu derste önceki haftalarda başlanan önbellek (cache) konusu tamamlanır. Önce bellek hiyerarşisi ve yerellik kavramları hatırlatılır, ardından önbellek tasarımının çözmesi gereken sorular ve üç eşleme yöntemi (doğrudan eşlemeli, tam ilişkili, küme ilişkili) işlenir. Doğrudan eşlemeli bir önbellek için adres alanlarının genişlikleri hesaplanır ve dört adrese erişim adım adım izlenir. Aradan sonra bir kod örneği üzerinden önbellek çakışması, ortalama erişim süresi (tek ve iki seviyeli), yer değiştirme algoritmaları ve üç eşleme yöntemi için adres bölümleme örneği görülür. Anlatım İngilizce slaytlar üzerinde, çizim tahtası notlarıyla yürür.

## 1. Bellek hiyerarşisi ve yerellik

Bellek hiyerarşisinde yazmaçlar, önbellek, ana bellek ve ikincil birimler vardır. Yazmaçlar ve önbellek işlemcinin içinde, diğerleri dışındadır.

> **Ders sonrası not:** Hoca hiyerarşiyi anlatırken dışa doğru gidildikçe maliyetin ve erişim maliyetinin arttığını, erişim süresinin hızlandığını söyledi. Doğrusu büyük olasılıkla şudur: dışa doğru gidildikçe kapasite artar, bit başına maliyet düşer ve erişim süresi uzar.

Önbelleği faydalı kılan iki özellik vardır:

- **Zamansal yerellik (temporal locality):** Yazılan kodların istatistiği incelendiğinde aynı değişkenlere tekrar tekrar erişildiği ya da yeni değer atandığı görülür. Bu erişimleri her seferinde ana bellekten yapmak yerine arada duran ve erişimi daha hızlı olan önbellekten yapmak daha yüksek verim (throughput) sağlar. Bu, aynı verinin tekrar tekrar erişilmesidir.
- **Uzamsal yerellik (spatial locality):** Dizi ve matris işlemleri çok yaygındır. Bir dizinin örneğin ilk elemanına erişilirken o elemanın belirli bir çevresi de önbelleğe alınırsa, ilk erişimden sonra ikinci erişim de önbellekten yapılır. Ne kadar elemanın önbellekten alınabileceği blok genişliğine bağlıdır.

## 2. Önbellek tasarımının soruları

Slaytta (ekrandan, 00:10:00) CPU, önbellek ve ana bellek sırası çizilir; CPU veriyi **fiziksel adresle** önbellekte arar. Buradan üç problem çıkar:

1. Elimde bir fiziksel adres varken önbelleğin hangi gözünde arama yapmalıyım?
2. Aranan veri önbellekte yoksa ana bellekten getirilmelidir. Getirilen veri önbellekte nereye yerleşecek?
3. Önbellek en yüksek verimi verecek biçimde nasıl kurgulanmalı?

Slayttaki sorular da aynı çerçevededir: önbellek nasıl düzenlenir; her bellek adresi nereye eşlenir (önbellek belleğin bir alt kümesi olduğundan birden çok bellek adresi aynı önbellek yerine eşlenir); hangi elemanların önbellekte olduğu nasıl bilinir; bunlar hızlıca nasıl bulunur. Bu sorulara önbellek tasarımı (cache design) başlığı altında cevap verilir.

## 3. Üç eşleme yöntemi

Slayttaki sınıflandırma (ekrandan, 00:15:00) ana bellek adresleriyle önbellek adresleri arasındaki eşleme yöntemleridir: tam ilişkili (fully associative), doğrudan eşlemeli (direct mapped) ve küme ilişkili (set associative). Bu sınıflandırma, bir fiziksel adresin önbellekte nereye denk geleceğini belirleyen yaklaşımlardır.

### 3.1 Doğrudan eşlemeli önbellek

Fiziksel adresin en düşük anlamlı kısmı **word offset** ve **byte offset** alanlarıdır. Önbelleğe konan bir blok belirli sayıda word'den, her word de belirli sayıda byte'tan oluşur; önbellekte bir satıra blok denir. Bu iki alan, blok içinde kaç word olduğuna ve her word'de kaç byte olduğuna göre belirlenir.

Bunun üstündeki alan **index** alanıdır. Index, doğrudan doğruya önbelleğin hangi numaralı satırına erişileceğini belirler. Ancak index alanı aynı olan birden fazla fiziksel adres vardır. Bunların karışmaması için önbellekte ayrı bir alan açılır: **tag** alanı. Yanında da veri (data) alanı bulunur.

Başka bir fiziksel adres geldiğinde index alanına bakılır ve ilgili satıra gidilir. Satırda kayıtlı tag ile adresin tag'i karşılaştırılır. Eşitse aranan veri oradadır; değilse önbellekte yoktur ve ana bellekten getirilmelidir. Doğrudan eşlemede getirilen veri yine aynı satıra konur, çünkü index'i o satıra karşılık gelir. Yerleştirirken data alanı ve tag alanı güncellenir.

### 3.2 Tam ilişkili önbellek

Burada herhangi bir eşleme yoktur; sıradaki boş yer kullanılır. Boş bir önbellekle başlanır. Fiziksel adresin düşük anlamlı bitleri word offset ve byte offset olarak ayrılır, geri kalanın tamamı ayırt edici adres alanı, yani tag'dir. **Index alanı yoktur**, çünkü birebir eşleme yoktur. Veri ana bellekten getirilirken önbellekte dolu satırlar geçilir ve ilk boş satıra tag ve veriyle birlikte yerleştirilir. Hoca burada önemli bir noktayı vurguladı: önbelleğe ana bellekteki o adresteki **veri** yerleşir, adres değeri yerleşmez.

CPU başka bir adrese erişmek istediğinde hangi satıra bakacağına dair ön bilgisi yoktur. Bu yüzden baştan itibaren bütün satırların tag alanlarını kendi tag'iyle karşılaştırır; eşit bir satır bulursa geri kalanı taramadan veriyi oradan okur, bulamazsa veri önbellekte yoktur ve bellekten getirilmelidir. Bu yapıda aramak zor, bellekten önbelleğe taşımak kolay görünür.

Bir sorun daha vardır: aranan verinin tag'i hiçbir satırla uyuşmuyor ve bütün satırlar doluysa hangi satır kaldırılacaktır? Bu noktada **yer değiştirme politikası** (replacement policy) devreye girer: first in first out (FIFO), least recently used (LRU), random gibi yaklaşımlar.

- Her veri önbelleğe **yerleştirildiğinde** ilgili satırın sayacı sıfırlanır ve her yeni erişimde bütün satırların sayaçları artırılırsa, en büyük sayaca sahip satır önbelleğe ilk giren satırdır. Bu FIFO mantığıdır.
- Sayaç satıra okuma ya da yazma için **erişildiğinde** sıfırlanırsa, en büyük sayaçlı satır en uzun süredir kullanılmayan (LRU) satırdır.
- Random'da rastgele bir değer üretilip o satır kaldırılır.

> **Hocanın vurgusu:** Önbellek boşken ilk konan satır büyük ihtimalle FIFO satırıdır; ama bu satıra her iki işlemde bir erişiliyorsa, ilk giren satırın LRU satırı olması gerekmez. Bu ikisi karıştırılmamalıdır.

### 3.3 Küme ilişkili önbellek

Bu yapıda doğrudan eşleme ile tam ilişkili yapı birlikte kullanılır. Hoca tahtada (ekrandan, 00:20:00) önbelleği üç kümeye (Set 1, Set 2, Set 3) bölünmüş bir tablo olarak çizdi. Artık her satırda bir değil üç blok vardır; örneğin her biri 10 word'lük üç blok. Her kümenin kendi tag alanı olmalıdır. Aynı satırdaki bütün verilerin index değeri aynıdır; farklı veriler oldukları için tag'leri farklıdır. Satırlar boyunca doğrudan eşleme, sütunlar (kümeler) boyunca tam ilişkili yapı vardır.

Bir veriye erişilirken fiziksel adres byte offset, word offset, index ve tag alanlarına ayrılır. Index ile $i$ numaralı satıra gidilir. Bu satırda üç küme vardır ve veri bunlardan herhangi birinde olabilir. Tag önce birinci kümenin tag'iyle, uymazsa ikincisiyle, uymazsa üçüncüsüyle karşılaştırılır; uyan kümedeki veri okunur.

Bütün kümelere bakıldığı hâlde veri bulunamazsa fiziksel adrese karşılık gelen veri ana bellekten okunur ve bu üç kümeden birine yerleştirilir. Tam ilişkili yapıda bütün önbellek satırlarında arama gerekirken burada arama ve yerleştirme alanı yalnız o satırdaki üç kümeyle sınırlanır. Hangi kümeye yerleşeceğine yine bir yer değiştirme politikası (FIFO, LRU ya da random) karar verir. Örneğin random ile bir küme seçilirse o kümenin tag'i ve verisi değişir; yeni verinin index'i kaldırılan veriyle aynıdır, çünkü aynı satıra denk gelmiştir.

> **Hocanın vurgusu:** Genel mantık anlaşıldıktan sonra asıl önemli olan, her mimari için fiziksel adresin tag, index, word offset ve byte offset genişliklerini belirleyebilmektir.

## 4. Küçük bir doğrudan eşlemeli önbellek

Önceki haftadan kalan slaytta (ekrandan, 00:25:00) 16 byte'lık bir bellek (adres 0-F) ve 4 byte'lık doğrudan eşlemeli bir önbellek (index 0-3) vardır; blok genişliği 1 byte'tır (tahtada "Block size ⇒ 1 byte").

- Satır sayısı: toplam kapasite / satır kapasitesi $= 4 / 1 = 4$ satır. Index genişliği $\log_2 4 = 2$ bit.
- Aksi belirtilmedikçe her bellek gözü 1 byte'tır. Bellek 16 byte olduğundan 16 göz vardır; fiziksel adres genişliği $\log_2 16 = 4$ bit.
- Byte offset ve word offset 0 bittir.
- 4 bitlik adresin düşük anlamlı 2 biti index, yüksek anlamlı 2 biti tag'dir.

Önbellek 4 satırdan oluştuğu için eşleme her 4 adreste bir tekrarlanır: slayttaki renklerle 0, 4, 8, C adresleri önbelleğin 0. satırına; 1, 5, 9, D adresleri 1. satırına eşlenir. Yani her 4 adres ötedeki bellek bölgesi önbellekte aynı satıra adreslenir.

Önbellek satırı bir bellek gözünden genişse (çok byte'lık blok), adresin belirli bir kısmı blokta kaçıncı word olduğunu, belirli bir kısmı da o word'ün kaçıncı byte'ı olduğunu belirtmek için kullanılır.

## 5. Doğrudan eşlemenin sorunu ve blok genişliğinin etkisi

Slayt (ekrandan, 00:30:00) şunu sorar: birden çok bellek adresi aynı önbellek index'ine eşlendiğine göre içeride hangisinin olduğu nasıl anlaşılır; blok 1 byte'tan büyükse ne olur? Sonuç olarak bellek adresi üç alana bölünür: doğru bloğun olup olmadığını kontrol eden **tag**, bloğu seçen **index** ve blok içindeki **byte offset**.

### 5.1 En kötü durum

Hoca tahtada şu senaryoyu çizdi: yazılan kod hep 512 adres ötedeki veriyi alıyor, yani 0, 512, 1024, ... adreslerine sırayla erişiyor; önbellek de öyle bir yapıda ki 512 adreste bir hepsi aynı satıra eşleniyor. Boş önbellekle başlanır. 0. adrese erişilir, yoktur; 0. satıra getirilir. 512. adres de 0. satıra denk gelir, tag farklıdır, bellekten alınıp 0. satıra yazılır. 1024. adres yine 0. satıra denk gelir, tag farklıdır, yine getirilir. Bu en kötü durumda önbelleğin yalnız bir satırıyla sürekli işlem yapılır, geri kalanı boş ve kullanılmaz kalır. Hoca ilişkili (associative) önbellek mantığının faydasının burada ortaya çıktığını söyledi.

### 5.2 Blok genişliği ve ıska oranı

Önbellek kapasitesi sabit tutulup blok genişliği artırılırsa:

- Blok 1 byte iken ıska (miss) oranı yüksektir, çünkü uzamsal yerellik hiç kullanılmaz: bellekten her seferinde yalnız 1 byte gelir ve dizinin bir sonraki elemanı önbellekte yoktur.
- Blok 2 byte yapılınca bir dizi işleminde erişimlerin yaklaşık yarısı belleğe gitmeden bulunur; yarısı isabet, yarısı ıska olur ve oran düşer.
- Blok büyütülmeye devam edilirse, kapasite sabit olduğundan satır sayısı azalmaya başlar. Iska oranı bir süre daha düşer, ama satır sayısı kritik bir değere ulaşınca yeniden **artmaya** başlar.

Aynı yapının ortalama erişim süresine etkisi de benzerdir: ıska oranındaki bu artış, belirli bir noktadan sonra erişim süresini de bozar. Hoca bu iki grafiği (ıska oranı ve ortalama erişim süresi - blok genişliği) böyle yorumladı. <!-- BELİRSİZ: Hoca blok genişliği arttıkça bakılacak satır sayısının azalmasının erişim süresini iyileştirdiğini de söyledi; bu kısmın grafiği karelerde görünmüyor ve anlatım altyazıda dağınık. -->

## 6. 16 KB'lık doğrudan eşlemeli önbellekte adres bölümleme

Örnek (ekrandan, 00:35:00): toplam önbellek kapasitesi 16 KB, blok genişliği 4 word, 32 bitlik mimari (veri yolu ve fiziksel adres yolu 32 bit). Tag, index, word offset ve byte offset alanlarının genişlikleri bulunacaktır.

**Byte offset.** 32 bitlik mimaride bir seferde $32/8 = 4$ byte'lık veri çıkar; her word'de 4 byte vardır. Bir word içindeki byte'ı seçmek için

$$\text{byte offset} = \log_2 (4\ \text{byte/word}) = 2\ \text{bit}.$$

**Word offset.** Bir blokta 4 word vardır:

$$\text{word offset} = \log_2 (4\ \text{word/blok}) = 2\ \text{bit}.$$

**Index.** Slayttaki hesap: satır sayısı = önbellekteki blok sayısı (her satırda bir blok vardır) = önbellek byte'ı / satır byte'ı:

$$\frac{2^{14}\ \text{byte}}{2^{4}\ \text{byte/satır}} = 2^{10} = 1024\ \text{satır}, \qquad \text{index} = \log_2 1024 = 10\ \text{bit}.$$

Burada $2^4 = 16$ byte, 4 word × 4 byte'tan gelir.

**Tag.** Fiziksel adres 32 bittir; 10 bit index'e, 2 bit word offset'e, 2 bit byte offset'e gider:

$$\text{tag} = 32 - 10 - 2 - 2 = 18\ \text{bit}.$$

Sonuç: tag 18 | index 10 | word offset 2 | byte offset 2.

## 7. Doğrudan eşlemeli önbellekte dört adrese erişim

Aynı önbellekte (16 KB, doğrudan eşlemeli, 4 word'lük blok) şu dört adres sırayla okunur (ekrandan, 00:40:00): `0x00000014`, `0x0000001C`, `0x00000034`, `0x00008014`. Slayta göre yalnız önbellek ve bellek seviyeleri dikkate alınır.

### 7.1 Birinci erişim: 0x00000014

Hoca adresi 32 bit olarak tahtaya yazdı ve 18-10-2-2 bölümlemesine göre ayırdı (ekrandan, 00:45:00):

```text
tag (18 bit)        index (10 bit)   wo   bo
000000000000000000  0000000001       01   00
```

En düşük 2 bit byte offset, sonraki 2 bit word offset, sonraki 10 bit index, kalan 18 bit tag'dir. Index ondalık olarak 1'dir.

Bir öğrenci asıl verinin nerede tutulduğunu sordu.

**Soru:** Asıl veriyi burada nerede tutuyoruz? **Cevap:** Bu bir fiziksel adrestir. CPU'nun bir adres yolu ve bir veri yolu vardır; adres yoluna `0x14` çıkar ve bu adres ya önbelleğe ya da ana belleğe gider. Boş önbellekle başlandığı için önce önbelleğe bakılır, ilgili satırda veri yoktur. Ana belleğin `0x14` adresine gidilir; veri şu anda oradadır. Sonra veri, adresin bölümlemesine göre index satırına, yani önbelleğin 1 numaralı satırına getirilir (ana bellek ile önbellek aynı boyutta değildir, bu yüzden ana bellekteki satırla aynı satır gibi düşünülmemelidir). CPU veriyi önbelleğin bu satırından okur. Kısacası asıl veri ana bellekte ya da önbelleğin data alanındadır.

Doğrudan eşlemeli önbellekte bir satır şu alanlardan oluşur (tahtada, ekrandan, 00:45:00):

- **Tag:** fiziksel adresin tag değeri.
- **Valid biti (1 bit):** verinin geçerli olup olmadığını belirtir. Reset ile başlandığında tag alanlarında rastgele değerler vardır ve bunlar tesadüfen aranan tag'le örtüşebilir. İlk başlatmada bütün valid bitleri 0 yapılarak verinin anlamlı olmadığı belirtilir.
- **Data:** blok 4 word × 4 byte olduğundan 16 byte'lık verinin kendisi.

Önemli bir sonuç: bellekten tek bir byte okunmaz; bu adresi içeren **16 byte'lık blok** okunur ve önbelleğin data alanına konur. CPU erişirken index ile satır seçilir, valid bitinin 1 olup olmadığına ve tag'in örtüşüp örtüşmediğine bakılır; hepsi uygunsa son 4 bit, 16 byte içinden hangi byte'ın alınacağını belirler.

Birinci erişimde satır 1'in valid biti 0'dır; bu yüzden **ıska** olur. Index değeri 1 olan adresler, son 4 biti `0000`'dan `1111`'e kadar değişen adreslerdir; yani `0x00000010` ile `0x0000001F` arası. Bu 16 byte satır 1'in data alanına konur (tahtada, ekrandan, 00:50:00: d(10H), d(11H), ..., d(1FH)). Hoca byte'ların sırası için "byte 0, byte 1, ..., byte 15" diye işaretlemenin anlam sırasını korumak için daha uygun olduğunu söyledi. Ardından valid biti 1, tag 0 yapılır.

Slayt (ekrandan, 01:00:00) aynı durumu tablo olarak gösterir: adres `000000000000000000 0000000001 0100`; index 1 satırında valid 1, tag 0 ve dört word sütunu (0x0-3, 0x4-7, 0x8-b, 0xc-f) a, b, c, d değerleriyle dolmuştur; diğer satırların (0, 2, 3, ..., 1023) valid biti 0'dır. Okunacak veri 4-7 byte'larını içeren 1 numaralı word'dedir (b).

### 7.2 İkinci erişim: 0x0000001C

`C` = `1100` olduğundan adres `... 0000000001 11 00` olur. Index yine 1'dir. Satır 1'de valid biti 1, tag 0 ve adresin tag'i de 0'dır; aranan veri buradadır. Bu bir **isabet** (hit) olur.

Okunacak byte şöyle bulunur: data bloğundaki byte'lar dörder dörder word 0, word 1, word 2 ve word 3'ü oluşturur. Word offset `11` = 3 olduğundan 3 numaralı word'e, yani byte 12, 13, 14, 15'e gidilir; byte offset `00` olduğundan bunların 0. byte'ı, yani bloktaki **12 numaralı byte** veri yoluna çıkarılır (tahtada, ekrandan, 00:55:00). Slayttaki tabloda bu, d word'ü içindeki veridir.

### 7.3 Üçüncü erişim: 0x00000034

`0x34` = `0011 0100` olduğundan adres `... 0000000011 01 00` olur; index 3'tür. Satır 3'te valid biti 0'dır; tag ve veri rastgeledir. Bu bir **ıska**dır. Index'i 3 olan, peş peşe yerleşmiş adres aralığı `0x00000030` ile `0x0000003F` arasıdır; bu 16 byte bellekten bir seferde alınıp satır 3'e taşınır (d(30H), d(31H), ..., d(3FH)). Valid biti 1 yapılır, tag alanına 0 yazılır (hoca önce yanlışlıkla 3 dedi, sonra düzeltti).

Buradan bir sonuç çıkar: doğrudan eşlemeli yapıda farklı satırlarda aynı tag değerleri bulunabilir. Bu iki bloğu ayıran şey index alanlarıdır: birinin index'i 1, diğerininki 3'tür; bu yüzden ayrı satırlara karşılık gelirler.

### 7.4 Dördüncü erişim: 0x00008014

`0x8014` adresinde düşük 14 bit yine `0000000001 01 00`, yani index 1, word offset 1, byte offset 0'dır; bunun üstündeki tag ise `10` = **2**'dir. Satır 1'e gidilir; valid biti 1, yani anlamlı veri vardır. Satırdaki tag 0, adresin tag'i 2'dir; bu bir **ıska**dır ve bir değiştirme yapılmalıdır. Satırdaki `0x10`-`0x1F` içerikleri kaldırılır, yerine `0x8010`-`0x801F` aralığındaki 16 byte konur (tahtada "8010H", ekrandan, 00:55:00). Valid biti 1 kalır, tag 2 olarak güncellenir.

Sonuç: dört erişim 1 isabet ve 3 ıska ile tamamlanır.

```python
# 18-10-2-2 bölümlemesinin python ile kontrolü
for a in [0x14, 0x1C, 0x34, 0x8014]:
    print(hex(a), a >> 14, (a >> 4) & 0x3FF, (a >> 2) & 3, a & 3)
# 0x14 -> tag 0, index 1, wo 1, bo 0   (ıska)
# 0x1c -> tag 0, index 1, wo 3, bo 0   (isabet)
# 0x34 -> tag 0, index 3, wo 1, bo 0   (ıska)
# 0x8014 -> tag 2, index 1, wo 1, bo 0 (ıska, blok değiştirme)
```

Slaytların devamında aynı örnek tablolar üzerinde de gösterildi (01:00:00 civarı, altyazıya göre). Ana bellek a, b, c, d, e, f, g, h, i, j, k, l gibi 4 byte'lık word'ler hâlinde yazılmıştır; satır 1'e a, b, c, d word'leri gelir. `0x1C` erişiminde d word'ündeki veri okunur, `0x34` erişiminde satır 3 doldurulur ve yine 4 numaralı offset'ten (1 numaralı word) okunur, `0x8014` erişiminde satır 1'in verisi değiştirilir ve tag güncellenir. <!-- BELİRSİZ: 0x34 erişiminde okunan word'ün slayttaki harfi altyazıda "F satırı" diye geçiyor; slayt karesi yok. -->

## 8. Erişim durumları: ıska, blok değiştirme ve isabet

Hoca örnekte görülen işlem türlerini slayttaki listeye göre özetledi:

- **Valid biti:** Reset ile başlandığında önbellekte rastgele değerler vardır. Verinin anlamlı olup olmadığını göstermek için her satırda 1 bitlik valid biti bulunur.
- **Iska (valid 0):** Fiziksel adres tag, index, word offset ve byte offset'e ayrılır, index'e göre satıra gidilir. Valid biti 0 ise veri bellekten getirilip yazılır; burada var olan anlamlı bir veri ezilmez. Slayt bunu "cache miss" olarak adlandırır.
- **Iska ve blok değiştirme (valid 1, tag farklı):** Satırda anlamlı veri vardır ama tag'ler örtüşmez. Veri bellekten getirilir ve mevcut verinin üzerine yazılır (overwrite). Slayt bunu ayırt etmek için "cache miss, block replacement" diye ayrı satırda verir.
- **İsabet (valid 1, tag eşit):** Adresin index'iyle satıra gidilir, satırdaki tag ile adresin tag'i örtüşüyorsa veri bu satırdadır; verilen adrese göre word'lerden birinde ve o word'ün bir byte'ındadır. Buna cache hit denir.

## 9. Önbellek çakışması (thrashing) örneği

Aradan sonra bir kod örneğine geçildi. Mimari MIPS'tir; içinde 64 KB kapasiteli doğrudan eşlemeli bir önbellek vardır ve her blok (line) 16 byte'tır. Kod iki float dizi alır; bir toplam (sum) değişkeni biriktirici olarak kullanılır ve iki dizinin aynı sıradaki elemanları çarpılıp toplama eklenir. En iyi ve en kötü durumda isabet ve ıska oranları incelenir. <!-- BELİRSİZ: kodun kendisi ve döngü uzunluğu karelerde görünmüyor; altyazıya göre yapı "sum += x[i] * y[i]" biçiminde bir döngüdür. -->

Yalnız dizi erişimlerinden doğan isabet ve ıskalar incelenir; sum ve diğer değişkenler göz ardı edilir. Float tek duyarlıklı (single precision) bir veri tipidir ve 32 bit, yani 4 byte yer kaplar. Önbelleğin her satırı 16 byte olduğundan bir satıra 4 float sığar: örneğin x dizisinin ilk 4 elemanı bir satıra konabilir.

**İyi durum.** Önce x[0] okunur; bellekten x[0]-x[3] gelir. Sonra y[0] okunur; y[0]-y[3] gelir ve önbellekte bir yere konur. x ve y bellekte öyle adreslerdeyse ki index değerleri farklı satırlara düşüyor, x[0] okurken bir ıska olur ama x[1] sıradaki veriden (isabet) okunur; y[0] okurken bir ıska olur, y[1] isabettir. Böylece her 8 erişimde 2 ıska, yani **%25 ıska oranı** olur. Sonraki 4'lü bloklar (4, 5, 6, 7 numaralı elemanlar) için de aynı durum tekrarlanır, genel oran %25'tir.

**Kötü durum** (ekrandan, 01:20:00). x ve y'nin adresleri şanssız biçimde denk gelmişse, her x[i] için hesaplanan index aynı sıradaki y[i]'nin index'iyle aynıdır. Slayttaki erişim deseni:

- x[0] okunur: x[0], x[1], x[2], x[3] yüklenir.
- y[0] okunur: aynı satıra düştüğü için x bloğu atılır, y[0], y[1], y[2], y[3] yüklenir.
- x[1] okunur: x[0]-x[3] yeniden yüklenir.
- y[1] okunur: y[0]-y[3] yeniden yüklenir.
- 8 okuma / 8 ıska.

Slayttaki analiz: x[i] ve y[i] aynı önbellek satırlarına eşlenir; ıska oranı %100'dür; her yinelemede iki bellek erişimi ve her yinelemede iki ıska vardır.

> **Hocanın vurgusu:** Yazılan program kullanılan mimarideki önbellek yapısını dikkate almıyorsa, kod önbellek mimarisi yüzünden daha yavaş çalışabilir; buna dikkat etmek gerekir.

## 10. Ortalama erişim süresi

Bir veri arandığında önce önbelleğe bakılır; yoksa ana bellekten getirilir, sonra önbellekten okunur. Bu ikili hiyerarşidir. Günümüz mimarilerinde hiyerarşi genişler (tahtada, ekrandan, 01:25:00): CPU, L1 cache, L2 cache, L3 cache ve ana bellek. CPU önce L1'e bakar; bulamazsa L2'ye, orada yoksa L3'e, orada da yoksa ana belleğe gider. Ana bellekten L3'e büyük bir blok getirilir, bunun bir kısmı L2'ye, bir kısmı L1'e getirilir ve CPU L1'den okur.

Ortalama erişim süresinde üç maliyet vardır: veriyi önbellekte aramak, yoksa ana bellekten getirmek ve önbellekten okumak. Bunların hangi sıklıkta ödendiğini isabet oranı belirler. Bir mimari kurulduktan sonra genel geçer algoritmalar üzerinde çalıştırılarak ortalama isabet ve ıska oranları hesaplanabilir; bu yüzden her mimari ve her önbellek seviyesi için kabaca bir ortalama isabet oranından söz edilebilir.

İsabet oranı $h$, aranan verinin önbellekte bulunma olasılığıdır.

- $h$ olasılıkla veri önbellektedir; maliyet $t_c$ (önbellekten getirme süresi).
- $1-h$ olasılıkla veri önbellekte yoktur; veri önce ana bellekten önbelleğe getirilir ($t_m$), sonra önbellekten okunur ($t_c$).

$$t_a = h\,t_c + (1-h)(t_m + t_c) = h\,t_c + (1-h)\,t_c + (1-h)\,t_m = t_c + (1-h)\,t_m.$$

$t_c$ parantezine alındığında $h + (1-h)$ birbirini götürür. Slayttaki formül de budur (ekrandan, 01:25:00): $t_a = t_c + (1-h)\,t_m$; ilk erişimin ana bellekten önce önbelleğe yapılması gerektiği ve şimdilik yalnız okuma isteklerinin dikkate alındığı varsayılır. Slayta göre $t_c$, önbelleğe erişme, isabet varsa veriyi alma (ya da yazma) veya ıskayı tanıma süresidir; pratikte bu süreler farklı olabilir.

**Örnek** (ekrandan, 01:30:00). İsabet oranı 0.85 (tipik bir değer), ana bellek erişim süresi 50 ns, önbellek erişim süresi 5 ns. %85'in oluşmasında önbelleğin blok genişliği ve toplam kapasitesi gibi unsurlar etkilidir.

- Verilen: $h = 0.85$, $t_m = 50$ ns, $t_c = 5$ ns.
- Genel formül: $0.85 \times 5 + 0.15\,(50 + 5) = 4.25 + 8.25 = 12.5$ ns (ara adım eklendi).
- Özet formül: $5 + 0.15 \times 50 = 5 + 7.5 = 12.5$ ns.

Önbellek kullanılmasaydı her veri 50 ns'de getirilecekti. %85 isabetli bir önbellekle ortalama süre 12.5 ns'ye, yani dörtte birine iner.

> **Ders sonrası not:** Hoca sonuç için önbelleğin ortalama erişim süresini "oldukça arttırmış" olduğunu söyledi; kastedilen, süreyi azalttığı (performansı artırdığı) olmalıdır.

Sonraki slaytta aynı soru süreler yerine çevrim (cycle) cinsinden verilmiştir; hoca bunun aynı örnek olduğunu söyleyip geçti.

## 11. İki seviyeli önbellekte ortalama erişim süresi

Hocanın önemli dediği örnekte CPU, L1 cache, L2 cache ve bellek vardır (derste sözlü, 01:31:06):

- L1'den veri getirme süresi: 1 çevrim.
- L2'den veri getirme süresi: 5 çevrim.
- Bellekten L2'ye veri getirme: 100 çevrim.
- L1'de bulma olasılığı %95 (ıska oranı %5), L2'de bulma olasılığı %85.

Hesap dıştan içe doğru yapılır. Önce aranan verinin L1'e getirilebilme ortalama süresi bulunur. Veri L2'de varsa maliyet 5 çevrimdir; yoksa (%15) bellekten L2'ye 100 çevrimle getirilir:

$$t_{L1\ \text{ceza}} = 5 + 0.15 \times 100 = 20\ \text{çevrim}.$$

Genel formülle aynı sonuç: $0.85 \times 5 + 0.15\,(100 + 5) = 4.25 + 15.75 = 20$ çevrim (ara adım eklendi). Bu değer L1'in ıska cezasıdır (penalty).

Sonra CPU'ya getirme süresi: L1'den getirme süresi + L1'de bulamama olasılığı × L1'e getirme süresi:

$$t_a = 1 + 0.05 \times 20 = 2\ \text{çevrim}.$$

Bellekten doğrudan 100 çevrimde okunacak bir veri, iki seviyeli önbellekle ortalamada 2 çevrimde okunur; verim yaklaşık 50 kat artar.

## 12. Yer değiştirme algoritmaları

Yer değiştirme algoritmaları temelde **küme ilişkili ve tam ilişkili** önbellekler için geçerlidir. Doğrudan eşlemeli önbellekte hangi verinin kaldırılacağı index'e bağlıdır; eşleme birebir olduğu için bellidir. Tam ilişkilide bütün satırlar arasından, küme ilişkilide ilgili satırdaki kümeler arasından hangisinin kaldırılacağı belirlenir. Veri, tam ilişkilide önbelleğin tamamı, küme ilişkilide ilgili index'teki bütün kümeler doluyken kaldırılır.

Slayttaki soru (ekrandan, 01:35:00): bir blok getirildiğinde hedef kümedeki hangi blok değiştirilmelidir?

- **Optimal algoritma:** en uzun süre kullanılmayacak blok değiştirilir. Bunun için geleceği bilmek gerekir; kod henüz çalışmadığı için bu bilinemez. Yakalanabilse mükemmel olurdu.
- **Kullanıma dayalı algoritmalar:**
  - **LRU (least recently used):** en uzun süredir başvurulmamış blok değiştirilir. Geçmiş istatistiğe, belirli bir pencere içindeki kullanıma bakılır: uzun süredir kullanılmayan bir satır büyük olasılıkla gelecekte de kullanılmayacaktır. Gerçeklemesi: her satırda bir sayaç vardır ve satıra erişildiğinde sayacı sıfırlanır. Slayta göre gerçeklemesi zordur.
- **Kullanıma dayalı olmayan algoritmalar:**
  - **FIFO (first in first out):** küme dairesel bir kuyruk gibi ele alınır, kuyruğun başı değiştirilir; yani önbellektekiler içinde ilk konan veri atılır. Gerçeklemesi kolaydır: her satıra bir sayaç konur, satıra yeni veri yerleştirilince sayaç sıfırlanır; en büyük sayaçlı satır ilk giren satırdır. Hoca LRU'ya göre daha kötü sonuç vermesini beklediğini söyledi.
  - **Random (RAND):** kümedeki rastgele bir blok değiştirilir; gerçeklemesi daha da kolaydır.

## 13. Üç eşleme için adres bölümleme örneği

Tam ilişkili ve küme ilişkili mantığın oturması için hoca önceki yıllardan bir örneği tahtada çözdü (ekrandan, 01:45:00 ve 01:50:00). Önce hatırlatma: doğrudan eşlemede hangi bloğun nereye eşleneceği index alanıyla bellidir; tam ilişkilide index alanı yoktur ve byte offset'ten (ve word offset'ten) geriye kalan alanın tamamı tag olmak zorundadır; küme ilişkilide eşleme, tag ve index vardır ama aynı boyuttaki doğrudan eşlemeli önbellekten farklı bir yapı oluşur.

Mimari:

- Önbellek: toplam kapasite 16 byte, blok genişliği 2 byte.
- CPU veri yolu genişliği 16 bit.
- CPU adres yolu (fiziksel adres) genişliği 10 bit.

İstenen: a) doğrudan eşlemeli, b) tam ilişkili, c) 2 yollu (two-way) küme ilişkili önbellek için adres bölümlemesi. Hoca sonradan d) 4 yollu küme ilişkili durumunu da ekledi.

**Ortak hesaplar.** Veri yolu 16 bit olduğundan bir word 2 byte'tır. Blok 2 byte olduğundan bir blok 1 word'dür.

- Word offset $= \log_2 (1\ \text{word/blok}) = 0$ bit. Blokta tek word olduğundan "hangi word" sorusunun anlamı yoktur.
- Byte offset $= \log_2 (2\ \text{byte/word}) = 1$ bit.

**a) Doğrudan eşlemeli.** Index $= \log_2 (16 / 2) = \log_2 8 = 3$ bit. Tag $= 10 - 3 - 1 = 6$ bit. Bölümleme: tag 6 | index 3 | byte offset 1.

**b) Tam ilişkili.** Index alanı yoktur. Tag $= 10 - 1 = 9$ bit. Bölümleme: tag 9 | byte offset 1.

**c) 2 yollu küme ilişkili.** Her index'e karşılık iki küme vardır ve her küme bir blok içerir; bir satırın kapasitesi $2 \times 2 = 4$ byte'tır. Index $= \log_2 (16 / (2 \times 2)) = \log_2 4 = 2$ bit. Tag $= 10 - 2 - 1 = 7$ bit. Bölümleme: tag 7 | index 2 | byte offset 1.

**d) 4 yollu küme ilişkili.** Her satırda 4 küme, her küme 2 byte: index $= \log_2 (16 / (4 \times 2)) = \log_2 2 = 1$ bit. Tag $= 10 - 1 - 1 = 8$ bit. Bölümleme: tag 8 | index 1 | byte offset 1.

```python
import math
for ad, yol in [("doğrudan", 1), ("2 yollu", 2), ("4 yollu", 4)]:
    idx = int(math.log2(16 / (2 * yol)))
    print(ad, "index", idx, "tag", 10 - 1 - idx)   # 3/6, 2/7, 1/8
print("tam ilişkili tag", 10 - 1)                  # 9
```

Yol sayısı arttıkça index biti azalır, tag biti artar; tam ilişkili durum, tek satırlı (index'siz) bir küme ilişkili önbellek gibi düşünülebilir.

> **Ek bilgi (derste anlatılmadı):** Genel olarak $k$ yollu küme ilişkili bir önbellekte küme (satır) sayısı kapasite / ($k$ × blok genişliği) olur; $k = 1$ doğrudan eşlemeye, $k$ = toplam blok sayısı tam ilişkili yapıya karşılık gelir.

Dersin sonunda hoca bir sonraki derste önbelleğe yazma işlemine kısaca bakılacağını, ardından sanal bellek (virtual memory) konusuna geçileceğini söyledi. Sanal bellekte çalıştırılacak her programın kendine ait sanal bir bellek uzayı olur: program belleğe sığmayacak kadar büyük olabilir ya da birkaç blok yüklemek gerekebilir; programcı bunlarla ve mimariden mimariye değişen ayrıntılarla uğraşmaz, mimari bunu kendi içinde çözer. Program çalışırken sanal adreslere karşılık gelen fiziksel adresler bulunur. Bir program "0 adresi" dediğinde aslında kendi sanal adres uzayının 0 adresini kasteder. Ana belleğe yerleştirilen veriler için önbelleğe taşımayla ilgili ikinci bir adres bölümlemesi de bu hafta görülen önbellek kısmıdır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): 16 KB kapasiteli, 4 word'lük bloklara sahip doğrudan eşlemeli bir önbellek 32 bitlik bir mimaride kullanılıyor. Fiziksel adresin tag, index, word offset ve byte offset alanları kaçar bittir?

> **Çözüm (derste verildi):** Word 4 byte, byte offset 2 bit; blokta 4 word, word offset 2 bit; satır sayısı $2^{14}/2^4 = 2^{10}$, index 10 bit; tag $32 - 10 - 2 - 2 = 18$ bit.

**Soru 2** (ekrandan, 00:40:00): Aynı önbellekte boş başlangıçla `0x00000014`, `0x0000001C`, `0x00000034`, `0x00008014` adresleri sırayla okunuyor. Her erişim isabet mi ıska mı, önbellek nasıl değişir?

> **Çözüm (derste verildi):** `0x14`: index 1, valid 0, ıska; 0x10-0x1F satır 1'e, tag 0. `0x1C`: index 1, tag 0, isabet; word 3'ün 0. byte'ı (bloktaki 12. byte). `0x34`: index 3, valid 0, ıska; 0x30-0x3F satır 3'e, tag 0. `0x8014`: index 1, tag 2 ≠ 0, ıska ve blok değiştirme; 0x8010-0x801F satır 1'e, tag 2. Toplam 1 isabet, 3 ıska.

**Soru 3** (ekrandan, 01:20:00): 64 KB doğrudan eşlemeli, 16 byte'lık satırlı bir önbellekte iki float dizinin aynı sıradaki elemanları çarpılıp toplanıyor. Dizilerin yerleşimine göre en iyi ve en kötü ıska oranı nedir?

> **Çözüm (derste verildi):** Bir satıra 4 float sığar. x ve y farklı satırlara eşlenirse her 4 elemanda x ve y için birer ıska: 8 okumada 2 ıska, %25. x[i] ve y[i] aynı satıra eşlenirse her okuma diğer dizinin bloğunu atar: 8 okumada 8 ıska, %100.

**Soru 4** (ekrandan, 01:30:00): İsabet oranı 0.85, ana bellek erişim süresi 50 ns, önbellek erişim süresi 5 ns ise ortalama erişim süresi nedir?

> **Çözüm (derste verildi):** $0.85 \times 5 + 0.15\,(50 + 5) = 5 + 0.15 \times 50 = 12.5$ ns.

**Soru 5** (derste sözlü, 01:31:06): L1'den getirme 1 çevrim, L2'den getirme 5 çevrim, bellekten L2'ye 100 çevrim; L1 isabet oranı %95, L2 isabet oranı %85. Ortalama erişim süresi nedir?

> **Çözüm (derste verildi):** L1 ıska cezası $5 + 0.15 \times 100 = 20$ çevrim; ortalama $1 + 0.05 \times 20 = 2$ çevrim.

**Soru 6** (ekrandan, 01:40:00): Önceki yıllardan çözümlü bir örnekte 64 KB'lık bir önbellek, 4 word'lük (32 byte'lık) bloklar ve 32 bitlik adres için a) byte offset, b) word offset, c) index ve d) tag bitlerinin sayısı soruluyor. <!-- BELİRSİZ: sorunun üst kısmı karede kesik; eşleme türü ve diğer veriler okunmuyor. Hoca örneği açıp çözmeden geçti. -->

> **Çözüm (ekranda gösterildi, derste anlatılmadı):** a) 4 word = 32 byte ⇒ 1 word = 8 byte, $\log_2 8 = 3$ bit byte offset. b) Blokta 4 word, $\log_2 4 = 2$ bit word offset. c) $\log_2 (64\ \text{KB} / 32\ \text{B}) = \log_2 (2^{16}/2^5) = 11$ bit index. d) $32 - (3 + 2 + 11) = 16$ bit tag.

**Soru 7** (ekrandan, 01:45:00 ve 01:50:00): Toplam kapasitesi 16 byte, blok genişliği 2 byte olan bir önbellek; CPU veri yolu 16 bit, adres yolu 10 bit. a) Doğrudan eşlemeli, b) tam ilişkili, c) 2 yollu küme ilişkili (ve derste eklenen d) 4 yollu küme ilişkili) önbellek için adres bölümlemesi nasıl olur?

> **Çözüm (derste verildi):** Word 2 byte, blok 1 word: byte offset 1 bit, word offset 0 bit. a) index $\log_2 8 = 3$, tag 6. b) index yok, tag 9. c) index $\log_2 (16/4) = 2$, tag 7. d) index $\log_2 (16/8) = 1$, tag 8.

## Dersin Toparlaması

Bu derste önbellek tasarımının temel soruları ve üç eşleme yöntemi işlendi. Doğrudan eşlemeli önbellekte index satırı belirler, tag aynı satıra düşen adresleri ayırır, valid biti satırın anlamlı olup olmadığını gösterir. Tam ilişkili önbellekte index yoktur ve arama bütün satırlarda yapılır; küme ilişkili önbellek aramayı index'in seçtiği satırdaki kümelerle sınırlar. 16 KB'lık doğrudan eşlemeli bir önbellek için 18-10-2-2 bölümlemesi bulundu ve dört adrese erişimle ıska, blok değiştirme ve isabet durumları adım adım izlendi. Bellekten tek byte değil adresi içeren bütün bloğun getirildiği vurgulandı.

İkinci kısımda dizilerin bellekteki yerleşimine göre aynı kodun %25 ya da %100 ıska oranı verebileceği thrashing örneğiyle gösterildi. Ortalama erişim süresi formülü $t_a = t_c + (1-h)\,t_m$ türetildi, tek ve iki seviyeli örneklerde uygulandı. Yer değiştirme algoritmaları (optimal, LRU, FIFO, random) karşılaştırıldı ve küçük bir mimari için doğrudan eşlemeli, tam ilişkili, 2 ve 4 yollu küme ilişkili adres bölümlemeleri hesaplandı. Hoca bir sonraki derste önbelleğe yazma işlemine ve ardından sanal belleğe geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
