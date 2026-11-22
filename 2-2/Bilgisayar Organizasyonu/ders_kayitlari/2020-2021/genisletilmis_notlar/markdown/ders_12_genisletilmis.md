# Ders 12 Genişletilmiş Notu: Önbellek Adres Bölümleme, Ortalama Erişim Süresi, Associative Önbellekler ve Yazma Politikaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Kısa Tekrarı
- 2. Direct Mapped Önbellekte Adres Bölümleme
- 3. Blok Genişliği ve Miss Rate
- 4. Örnek: 16 KB Direct Mapped Önbellekte Alan Genişlikleri
- 5. Örnek: Direct Mapped Önbellekte Erişim Dizisi
- 6. Önbellek Erişiminin Dört Durumu
- 7. Vektör Çarpımı Örneği: İyi Durum ve Thrashing
- 8. Ortalama Erişim Süresi
- 9. İki Seviyeli Önbellekte Ortalama Erişim Süresi
- 10. Direct Mapped Önbellekte Değiştirme
- 11. Fully Associative Önbellek
- 12. Set Associative Önbellek
- 13. Değiştirme Politikaları
- 14. Yazma Politikaları: Write-Through ve Write-Back
- 15. Örnek: Write-Through ve Write-Back Adım Adım
- Örnek Sorular

## 1. Önceki Dersin Kısa Tekrarı

Önceki derste önbellek (cache) yapısına geçilmişti: bellek hiyerarşisinde önbelleğin yeri, veri erişimini hızlandırmaya katkısı ve üç önbellek tipi (direct mapped, fully associative, set associative) tanıtılmıştı. Direct mapped önbellekte her adres doğrudan tek bir önbellek satırına eşlenir. Bu yapıda iki şeye dikkat edilir: önbelleğin blok genişliği (bir satırın kaç byte tuttuğu) ve adresin hangi bölgesinin satırı belirlediği. Blok genişliği 1 byte ve 2 byte olan örnekler önceki derste görülmüştü. Bu derste bu noktadan devam edildi.

## 2. Direct Mapped Önbellekte Adres Bölümleme

Bir bellek adresinin önbellekteki karşılığını bulmak için adres alt alanlara bölünür (address partitioning). Bunun için önce mimarinin word genişliği bilinmelidir. Örneğin 8086 mikroişlemcisinin veri yolu 16 bittir, dolayısıyla word genişliği 16 bit, yani 2 byte'tır.

Bir satırın 4 word tuttuğunu düşünelim. 8086'da bu $4 \times 2 = 8$ byte eder. Önbellekte bulunamayan bir veri bellekten getirilirken önbelleğe bir seferde bu 8 byte aktarılır: peş peşe adreslerdeki dört word, her biri de kendi düşük ve yüksek anlamlı byte'ıyla birlikte yerleşir.

Bu yüzden adreste bir **offset** kavramı vardır: önbellek bloğu içinde erişilmek istenen byte'ın, bloğun en düşük adresinden itibaren kaçıncı sırada olduğunu verir. Offset ikiye bölünebilir:

- **Byte offset:** adresin en düşük anlamlı kısmıdır; word içindeki byte'ı seçer.
- **Word offset:** bir üst kısımdır; blok içindeki word'ü seçer.

Arama sırası anlam sırasıyla aynıdır: önce hangi satırda olunduğu (index, daha anlamlı bitler), sonra o satırda kaçıncı word'de olunduğu (word offset), en son o word'ün kaçıncı byte'ında olunduğu (byte offset) bulunur.

Yalnız offset ve index yetmez. Direct mapped yapıda index ve offset'i içeren düşük anlamlı kısmı aynı olan birden fazla adres vardır; yani farklı adresler aynı satıra düşer. Satır 0'a gidildiğinde aranan verinin orada olduğu kesin değildir. Bu nedenle offset ve index dışındaki adres bitleri, yani **tag**, veriyle birlikte önbellekte saklanır. Bir satırdaki word'ler ardışık adreslerden geldiği için yüksek anlamlı adres kısımları ortaktır; her satır için tek bir tag alanı yeterlidir.

İkinci bir sorun daha vardır. Önbellek henüz boşken içinde rastgele değerler bulunur. Aranan index'teki tag şans eseri aranan tag ile aynı olabilir, ama oradaki veri geçerli değildir. Bu yüzden her satırda bir **valid biti** de tutulur. Arama şöyle yapılır: önce satırın valid biti kontrol edilir; 1 ise tag'ler karşılaştırılır; tag'ler örtüşüyorsa aranan veri önbellektedir.

Slayttaki terim tanımları da aynı şeyi söyler (ekrandan, 00:05:00): bütün alanlar işaretsiz tam sayı olarak okunur; index önbelleğin hangi "satırına" bakılacağını, offset doğru blok bulunduktan sonra blok içindeki byte'ı belirtir; tag, offset ve index belirlendikten sonra kalan bitlerdir ve aynı konuma eşlenen bütün bellek adreslerini birbirinden ayırt etmeye yarar.

Özetle direct mapped önbellekte adres, düşük anlamlıdan yükseğe doğru byte offset, word offset, index ve tag olarak bölünür. Diğer önbellek yapılarında doğrudan bir index eşlemesi olmadığı için tag genişlikleri farklı olacaktır.

Direct mapped yapının bir sorunu da önceki dersten hatırlatıldı: erişilen adresler hep aynı index'e düşebilir. Örneğin bütün erişimler satır 0'a gidiyorsa önbelleğin geri kalanı hiç kullanılmaz.

## 3. Blok Genişliği ve Miss Rate

Slaytta miss rate'in blok genişliğine göre değişimini gösteren bir eğri vardı (ekrandan, 00:10:00). Eğri önce düşer, düz bir dip bölgesinden geçer, sonra yeniden yükselir. Sol taraf "uzamsal yerellikten yararlanır" (exploits spatial locality), sağ taraf "daha az blok: zamansal yerelliği bozar" (fewer blocks: compromises temporal locality) diye etiketlenmişti.

Blok genişliği küçükken, hocanın anlatımına göre, daha fazla adres aynı satıra denk gelir ve aranan veriyi önbellekte bulma olasılığı düşer; miss rate yüksektir. Blok genişliği arttıkça veri erişimi iyileşir. Ancak blok genişliği belli bir optimumun üzerine çıkarsa, bir seferde daha büyük bir blok değiştirildiği için aynı index'e sahip başka bir erişimin önbellekteki veriyi bozma olasılığı artar ve miss rate tekrar yükselir. Küçük blok bölgesi uzamsal yerelliğin yeterince değerlendirilemediği, çok büyük blok bölgesi zamansal yerelliğin değerlendirilemediği durumdur.

Miss rate, aranan verinin önbellekte olmama olasılığıdır. Miss rate düştükçe ortalama erişim süresi de düşer. Hit olasılığı $x$ ise kabaca ortalama erişim süresi $x \cdot (\text{önbellekten getirme süresi}) + (1-x) \cdot (\text{bellekten getirme süresi})$ olarak düşünülebilir; bu ifade bölüm 8'de netleştirildi.

> **Ek bilgi (derste anlatılmadı):** Sabit kapasitede blok büyüdükçe satır sayısı azalır. Satır sayısı azalınca aynı satıra düşen adres sayısı artar ve çakışma kaynaklı miss'ler çoğalır. Eğrinin sağ tarafındaki yükselişin olağan açıklaması budur.

## 4. Örnek: 16 KB Direct Mapped Önbellekte Alan Genişlikleri

Slayttaki soru (ekrandan, 00:15:00): 4 word'lük bloklara sahip, 16 KB veri tutan direct mapped bir önbellek olsun. 32 bitlik bir mimari kullanılıyorsa tag, index ve offset alanlarının genişliği nedir?

**Word genişliği.** 32 bitlik mimariden kasıt 32 bit veri yolu ve 32 bit adres yoludur. Burada word genişliği için veri yolu önemlidir: word 32 bit, yani 4 byte'tır.

**Blok boyu.** Bir satırda 4 word, her word'de 4 byte vardır:

$$1 \text{ blok} = 4 \text{ word} \times 4 \text{ byte} = 16 \text{ byte}$$

**Satır sayısı.**

$$\#\text{satır} = \frac{16 \text{ KB}}{16 \text{ B}} = \frac{16 \cdot 2^{10}}{16} = 2^{10}$$

**Alan genişlikleri** (ekrandan, 00:20:00):

- Index bit sayısı $= \log_2 2^{10} = 10$ bit.
- Byte offset bit sayısı $= \log_2 4 = 2$ bit (word başına 4 byte).
- Word offset bit sayısı $= \log_2 4 = 2$ bit (blok başına 4 word).
- Tag $= 32 - 10 - 2 - 2 = 18$ bit.

Adres düzeni: `tag (18 bit) | index (10 bit) | word offset (2 bit) | byte offset (2 bit)`.

**Bir adresin bölümlenmesi.** Hoca örnek olarak 32 bitlik onaltılık `0000000AH` adresini aldı. İkilik yazıldığında:

- Tag: 18 tane 0.
- Index: 10 tane 0, yani satır 0.
- Word offset: `10`, yani 2 numaralı word (word'ler `00`, `01`, `10`, `11` diye sıralanır).
- Byte offset: `10`, yani o word içindeki 2 numaralı byte.

Önbellekte satır 0'a gidilir, satırın 2 numaralı word'ünün 2 numaralı byte'ına bakılır. Verinin gerçekten aranan veri olup olmadığını anlamak için önce valid bitinin 1 olup olmadığı, sonra tag'in örtüşüp örtüşmediği kontrol edilir. Satırda örneğin tag `01` yazılıysa aranan veri orada değildir.

> **Hocanın vurgusu:** Bu tür sorularda ilk iş verilen adresleri bölümlemektir. Çözümlerde offset alanının word offset ve byte offset olarak ayrı ayrı gösterilmesini istiyorum.

## 5. Örnek: Direct Mapped Önbellekte Erişim Dizisi

Aynı önbellek yapısında (2 bit byte offset, 2 bit word offset, 10 bit index, 18 bit tag) sırasıyla şu adreslere erişilsin (ekrandan, 00:25:00): `0x00000014`, `0x0000001C`, `0x00000034`, `0x00008014`. Slaytta adreslerin bölümlenmiş hâli şöyleydi (tag | index | offset):

```text
000000000000000000  0000000001  0100    0x00000014
000000000000000000  0000000001  1100    0x0000001C
000000000000000000  0000000011  0100    0x00000034
000000000000000010  0000000001  0100    0x00008014
```

Bellekte her satırın bir word olduğunu varsayalım: 10, 14, 18, 1C adreslerinde A, B, C, D; 30, 34, 38, 3C civarında E, F, G, H; 8010-801C civarında I, J, K, L word'leri olsun. Önbellekte bir seferde 4 word'lük bloklar tutulduğu için örneğin 10, 14, 18 ve 1C adreslerindeki dört word birlikte önbelleğe aktarılır.

Önbellek boş başlar: her satırda bir valid biti (hepsi 0), bir tag alanı ve dört word'lük veri alanı vardır; tag'lerde rastgele değerler bulunur (ekrandan, 00:30:00).

1. **`0x14`:** Index 1. Satır 1'in valid biti 0, aranan veri yok: **miss**. Bellekten 14 adresi ve çevresi getirilir. Getirilecek dört word, son 4 bit dışındaki adres bitleri `0x14` ile aynı olanlardır: A, B, C, D. Düşük adrese A gelecek şekilde satıra yazılır, valid biti 1 yapılır, tag alanına 0 yazılır. (Hoca önce tag'e yanlışlıkla 1 yazdı, sonra 0 olarak düzeltti.)
2. **`0x1C`:** Index 1, tag 0. Satır 1'de valid 1, tag 0 örtüşür. Word offset 3, byte offset 0: D word'ünün en düşük anlamlı byte'ı. **Hit**.
3. **`0x34`:** Index 3. Satır 3'ün valid biti 0: **miss**. Son 4 bit dışındaki adresi `0x34` ile aynı olan dört word, E, F, G, H, bellekten getirilir; valid 1, tag 0 yapılır.
4. **`0x8014`:** Index 1. Valid biti 1, ama satırdaki tag 0, aranan tag 2: **miss**. Satır 1'deki A, B, C, D kaldırılır, son 4 bit dışındaki adresi `0x8014` ile aynı olan I, J, K, L yazılır; tag 2 olarak güncellenir.

Sonuç: 3 miss, 1 hit. Hit, aranan verinin önbellekte bulunup hızlıca alınması; miss ise verinin bulunamayıp belleğe gidilmesi ve daha uzun süre harcanması demektir. Slaytta aynı süreç resimli olarak da gösterildi: offset düşük anlamlı 4 bittedir, son erişimde tag uyuşmazlığı nedeniyle blok değiştirilir (ara adım bölümlemeleri python ile doğrulandı).

## 6. Önbellek Erişiminin Dört Durumu

Önbellekte bir veri arandığında dört sonuç olabilir:

- **Cache loading:** Önbellek ilk durumda boşken, valid bitleri 0'dır; aranan veri önbellekte yoktur ve bellekten önbelleğe ilk kez veri getirilir.
- **Cache miss:** Aranan veri önbellekte yoktur, bellekten getirilmesi gerekir.
- **Cache hit:** Aranan blok önbellektedir, doğrudan okunur.
- **Değiştirme (replacement):** Tag uyuşmazlığından doğan miss sonucunda önbellekteki blok değiştirilir.

Cache loading valid bitine bakılarak yürütülür. Valid biti, önbellekteki verinin daha önce bellekten çekilmiş anlamlı ve güncel bir veri olup olmadığını gösterir. Önbellek boşken bu bit 0'dır ve valid biti 0 iken otomatik olarak miss oluşur. Bölüm 5'teki örnekte $2^{10}$ satır, 10 bitlik index, 1 bitlik valid biti ve satır başına dört word vardı; her satırdaki byte'lar düşük anlamlı 4 bitle (`0000`'dan `1111`'e) adreslenir.

## 7. Vektör Çarpımı Örneği: İyi Durum ve Thrashing

Önbellek yapısını bilen bir programcı programlarını daha hızlı çalışacak şekilde yazabilir. Slayttaki örnek (ekrandan, 00:35:00):

```c
float dot_prod(float x[1024], y[1024])
{
  float sum = 0.0;
  int i;
  for (i = 0; i < 1024; i++)
    sum += x[i]*y[i];
  return sum;
}
```

Makine DEC Station 5000'dir: 64 KB direct mapped önbellekli, satır boyu (line size, yani blok boyu) 16 byte olan bir MIPS işlemci. Slayttaki performans değerleri: iyi durumda eleman başına 24 çevrim, kötü durumda eleman başına 66 çevrim. Fonksiyon x ve y'nin aynı indisli elemanlarını çarpıp `sum` değişkeninde biriktirir. Kod parçası slayttan aktarılmıştır; tam program olmadığı için derlenmedi.

Bir satır 16 byte, bir `float` 4 byte'tır. Dolayısıyla x[0]'a erişildiğinde x[0], x[1], x[2], x[3] birlikte önbelleğe çekilir; y[0]'a erişildiğinde y[0..3] gelir. x[1], x[2], x[3] zaten önbellektedir, ama x[4] için tekrar belleğe gitmek gerekir. Diziler önbelleğe dörder eleman hâlinde gelir.

**İyi durum.** x ve y'nin index'leri çakışmasın. x[0] miss (x[0..3] yüklenir), y[0] miss (y[0..3] yüklenir). Sonraki üç iterasyonda x[1], y[1], x[2], y[2], x[3], y[3] önbellektedir. 8 float okumasının 2'si miss, 6'sı hit'tir:

$$\text{miss rate} = \frac{2}{8} = \frac{1}{4}$$

Yani her 4 iterasyonda bir miss durumu (x ve y için birer miss) oluşur.

**Kötü durum (thrashing).** x ve y bellekte aynı index'lere düşecek şekilde yerleşmiş olsun (ekrandan, 00:40:00). x[0] miss, x[0..3] çekilir. y[0] de miss; y[0..3] gelir ama aynı satıra düştüğü için x'lerin üzerine yazılır. x[1] istenince x[0..3] yeniden çekilir ve y'lerin üzerine yazılır; y[1] yine miss olur. Her erişim miss ile sonuçlanır: slayttaki ifadeyle 8 okumada 8 miss, iterasyon başına iki bellek erişimi, her iterasyonda iki miss.

$$\text{miss rate} = \%100$$

Bu durumda her veri için bellekten okuma süresi kadar beklemek gerekir; slayttaki 24 ve 66 çevrimlik fark bu durumdan kaynaklanır.

## 8. Ortalama Erişim Süresi

Ortalama erişim süresi (average access time) $t_a$ şöyle kurulur. $h$ hit oranı, $m$ miss oranıdır ve

$$m + h = 1$$

Veri alınırken önce önbelleğe bakılır. Varsa önbellekten okunur; yoksa bellekten önbelleğe getirilir, sonra önbellekten okunur. Önbellek erişim süresi $t_c$, bellek erişim süresi $t_m$ olsun (ekrandan, 00:45:00):

- Hit durumunda (olasılık $h$) süre $t_c$'dir.
- Miss durumunda (olasılık $m$) veri önce bellekten önbelleğe getirilir, sonra önbellekten işlemciye aktarılır; süre $t_m + t_c$'dir.

$$t_a = h\,t_c + m\,(t_m + t_c) = h\,t_c + m\,t_m + m\,t_c = t_c\,(h + m) + m\,t_m$$

$h + m = 1$ olduğundan:

$$t_a = t_c + m\,t_m = t_c + (1-h)\,t_m$$

> **Hocanın vurgusu:** Burası önemli. Veri bellekten önce önbelleğe, sonra önbellekten işlemciye aktarılır; formül bu süreçten çıkar.

Slaytta bunun yalnız okuma istekleri için geçerli olduğu ve ilk erişimin her zaman bellekten önce önbelleğe yapıldığı varsayımı belirtilir. $t_c$, önbelleğe erişip hit ise veriyi alma (ya da yazma) veya miss'i fark etme süresidir; slayta göre pratikte bu süreler farklı olabilir.

**Örnek** (ekrandan, 00:45:00). Hit oranı 0.85 (tipik bir değer), bellek erişim süresi 50 ns, önbellek erişim süresi 5 ns. Hit oranı önbellek tipine, blok genişliğine ve toplam boyuta bağlıdır; bu mimaride farklı programlar çalıştırılıp ortalama hit rate'e bakılarak bulunmuş bir değerdir. Her 100 adres erişiminin 85'i önbellekte bulunur.

$$t_a = 5 + (1 - 0.85) \times 50 = 5 + 0.15 \times 50 = 5 + 7.5 = 12.5 \text{ ns}$$

Önbellek olmasaydı her erişim 50 ns sürecekti. %85 hit oranlı, 5 ns'lik küçük bir önbellek ortalamayı 12.5 ns'ye indirir. Sonraki slayt aynı çözümü farklı bir gösterimle veriyordu; hoca üzerinde durmadı.

## 9. İki Seviyeli Önbellekte Ortalama Erişim Süresi

Günümüz mimarilerinde çok seviyeli önbellek kullanılır. Bu durumda her seviye için hit/miss oranları ve ortalama erişim süresi hesaplanır ve sonuç bir üst seviyeye aktarılır. Yapı CPU, L1, L2 ve bellek sırasındadır.

Slayttaki varsayımlar (ekrandan, 00:50:00):

- L1 hit süresi = 1 çevrim
- L1 miss rate = %5
- L2 hit süresi = 5 çevrim
- L2 miss rate = %15 (L1 miss'lerinin yüzde kaçının L2'de de miss olduğu)
- L2 miss penalty = 100 çevrim (bellekten L2'ye veri aktarma süresi)

**Adım 1: L2 ile bellek bir blok gibi.** Aranan veri L2'de varsa erişim 5 çevrimdir. Yoksa bellekten L2'ye getirmek 100 çevrim sürer ve buna 0.15 olasılıkla katlanılır:

$$t_{a,L2} = 5 + 0.15 \times 100 = 5 + 15 = 20 \text{ çevrim}$$

Bu değer L1 açısından miss penalty'dir.

**Adım 2: L1.** Artık sanki bir önbellek ve 20 çevrimlik bir "bellek" varmış gibi düşünülür. Veri L1'de ise 1 çevrim; yoksa (0.05 olasılıkla) 20 çevrimlik maliyete katlanılır:

$$t_a = 1 + 0.05 \times 20 = 2 \text{ çevrim}$$

Normalde 100 çevrim süren bir bellek erişimi, iki küçük önbellek seviyesiyle ortalama 2 çevrime iner.

> **Hocanın vurgusu:** Bu örnek önemli; iki seviyeli önbellekte ortalama erişim süresinin nasıl hesaplandığını gösteriyor.

## 10. Direct Mapped Önbellekte Değiştirme

Aradan sonra hoca kısa bir tekrar sorusu sordu: direct mapped önbellekte değiştirme politikası (replacement policy) nedir? Değiştirme, önbellekte geçerli ve anlamlı bir veri varken tag'i erişilen veriden farklı olduğu için o verinin kaldırılıp yerine yenisinin konmasıdır.

**Soru:** Direct mapped önbelleğin bir değiştirme politikası var mı? **Cevap (bir öğrenci):** Bir satıra erişildiğinde orada istenmeyen bir tag varsa satırın tamamı değiştirilir. **Hoca:** Evet. Adres bölümlemesinde index hangi satırı gösteriyorsa o satır değiştirilir; eşleme doğrudan kullanılır, ayrı bir seçim yoktur.

Bu, birazdan görülecek fully associative ve set associative yapılarda farklıdır. Onlarda her adres bloğunun hangi önbellek satırına düşeceğine dair sabit bir eşleme yoktur. Örneğin fully associative'de index (satır) alanı hiç yoktur ve satırlar birbirinin yerine geçebilir. Bu yapıların çıkış nedeni, önceki derste de dile getirilen sorundur: eşleme varsa bütün erişimler şans eseri aynı satıra düşebilir ve önbelleğin geri kalanı hiç kullanılmaz.

## 11. Fully Associative Önbellek

Hoca bu kısmı slaytlar yerine ekranda açtığı bir kitabın (Harris & Harris, *Digital Design and Computer Architecture*, Bölüm 8.3) şekilleri üzerinden, daha anlaşılır bulduğu için anlattı (ekrandan, 01:05:00 ve 01:10:00).

Fully associative önbellekte de bir toplam kapasite ve her satırın tuttuğu bir blok genişliği (line size, block size) vardır. Satır birden fazla word'den, word de birden fazla byte'tan oluşabilir; bu taraf direct mapped ile aynıdır. Fark yalnız index erişimindedir: bir bellek adresinin hangi önbellek satırına düşeceğine dair hiçbir atama, eşleme yoktur. Adreste index alanı bulunmaz ve satırlar arasında öncelik yoktur.

Kitaptaki tanım (ekrandan, 01:10:00): fully associative önbellek, $B$ blok sayısı olmak üzere $B$ way'li tek bir set içerir; bir adres bu way'lerden herhangi birindeki bloğa eşlenebilir. Yani $B$-way set associative'in tek setli hâlidir. Sekiz bloklu örnekte bir veri isteğinde sekiz tag karşılaştırması yapılmalıdır, çünkü veri herhangi bir blokta olabilir; hit olursa 8:1'lik bir çoklayıcı doğru veriyi seçer. Şekildeki her "way" hocanın anlattığı yapıdaki bir satıra karşılık gelir; her way'de V, Tag ve Data alanları vardır.

Hoca, kısmen dolu bir fully associative önbellekte verinin var olup olmadığının nasıl anlaşılacağını sordu.

**Soru:** Index alanı yoksa aranan verinin önbellekte olup olmadığını nasıl anlarız? **Cevap (bir öğrenci):** Offset dışındaki adresin tamamı tag olur; tek tek karşılaştırmak yerine donanımda bütün tag'leri aynı anda karşılaştırırız, tutan varsa veri vardır. **Hoca:** Tam olarak aranan cevap buydu. Bütün önbellek satırlarının tag'i referans edilen adresin tag'iyle karşılaştırılır. Herhangi birinde eşleşme varsa veri vardır; "yok" diyebilmek için bütün satırların tag'lerine bakılmış olmalıdır.

**Örnek: alan genişlikleri.** 16 KB, fully associative, blok 16 byte, 32 bit sistem.

- Satır sayısını bulmaya gerek yoktur, çünkü satır sayısı index'e karşılık geliyordu ve burada index yoktur.
- Offset $= \log_2 16 = 4$ bit. 32 bitlik sistemde word 4 byte olduğundan blokta 4 word, her word'de 4 byte vardır: 2 bit word offset, 2 bit byte offset.
- Kalan $32 - 4 = 28$ bit tag'dir.

> **Ders sonrası not:** Hoca bu örnekte ve set associative örneğinde word offset ve byte offset için "2 byte ayrılır" dedi; doğrusu 2 bit'tir.

Veri aranırken bu 28 bit, valid biti 1 olan her satırın tag'iyle karşılaştırılır.

**Önbellek doluyken miss.** Önbellek tamamen dolu ve aranan veri yoksa, bellekten getirilen blok nereye konacaktır? Burası direct mapped'ten farklı bir değiştirme politikası gerektirir:

- **First in, first out (FIFO):** Önbelleğe ilk yazılmış satır kaldırılır.
- **Least recently used (LRU):** En uzak geçmişte erişilmiş, yani uzun süredir kullanılmayan satır kaldırılır. Erişim zamanları tutulur. FIFO'da ilk konan veri, LRU olmak zorunda değildir: ilk konan veriye bir önceki adımda yeniden erişilmiş olabilir.
- **Random:** Rastgele bir satır çıkarılır.

Fully associative yapının bir güzelliği de sırada boş bir satır varsa yeni bloğun doğrudan oraya konabilmesidir. Bedeli ise aranan veriyi bulmak için bütün satırlara bakmaktır.

## 12. Set Associative Önbellek

Fully associative yapıda satırlar arasında öncelik yoktur ve boş yer serbestçe kullanılabilir, ama arama bütün satırları gerektirir. Direct mapped yapıda eşleme tanımlı olduğu için arama hızlıdır, ama indexler çakışırsa önbelleğin tek satırı kullanılıp geri kalanı boş kalabilir. Set associative önbellek bu ikisinin olumlu yönlerini birleştirir.

Bu yapıda bir satırda tek blok yerine birden fazla blok tanımlanır. Bir satırdaki bloklar kendi aralarında fully associative, satırlar birbirine göre direct mapped mantığıyla çalışır. Yani aynı index'e ama farklı tag'lere sahip bloklar aynı satıra konabilir. Örneğin two-way set associative'de her satırda iki küme (way) vardır ve ikisinin index'i aynıdır. Adres bölümlenip index alınınca belirli satıra gidilir; o satırda tag'i aranan adresle örtüşen bir blok olup olmadığına satır boyunca bakılır.

Hoca kitaptaki two-way set associative önbellek şeklini gösterdi (ekrandan, 01:20:00). Şekilde Way 1 ve Way 0 için ayrı V, Tag ve Data sütunları, Set 0-3 satırları vardır; Set 1'de iki way de doludur (tag `00...00` ile `mem[0x00...24]` ve tag `00...10` ile `mem[0x00...04]`).

**Örnek: alan genişlikleri** (ekrandan, 01:25:00). Soru: 16 KB büyüklüğe sahip 4-set associative (4-way) önbellek yapısında blok genişliği 16 byte, sistem 32 bit (4 byte) bir mimari ise adres bölümlenmesi nasıl olur?

- 32 bitlik mimaride word 4 byte. 16 byte'lık blokta 4 word, her word'de 4 byte vardır: byte offset 2 bit, word offset 2 bit (bölüm 4 ile aynı).
- Bir satırda 4 way, her way'de 16 byte vardır; bir satır $16 \times 4 = 64$ byte tutar.
- Satır sayısı:

$$\frac{16 \text{ KB}}{16 \text{ B} \cdot 4} = \frac{2^{10}}{2^2} = 2^8 = 256$$

- Satırlar 0'dan 255'e kadardır; index $= \log_2 2^8 = 8$ bit.
- Tag $= 32 - 8 - 2 - 2 = 20$ bit.

Adres düzeni: `tag (20 bit) | index (8 bit) | word offset (2 bit) | byte offset (2 bit)`.

One-way set associative, yani direct mapped yapıda index 10 bitti. Şimdi her satırda 4 küme olduğu için 2 bit buna harcanmış olur; index 8 bite iner, tag 20 bite çıkar.

**Arama.** Adres bölümlenir; index bitleri hangi satırı gösteriyorsa oraya gidilir (direct mapped'e benzerlik). Sonra o satırdaki 4 set'in tag'leri tek tek referans adresinin tag'iyle karşılaştırılır; bir yerde bulunursa veri vardır, "yok" demek için dördüne de bakmak gerekir (fully associative'den gelen özellik).

Fully associative'den farkı şudur: fully associative'de bütün önbellek bloklarının tag'i karşılaştırılmalıydı. Aynı kapasite ve blok boyunda bu $16 \text{ KB} / 16 \text{ B} = 1024$ bloktur. Set associative'de index ile verinin belirli bir kısmına odaklanılır ve yalnız index'i örtüşen 4 kümede karşılaştırma yapmak yeterlidir. Böylece fully associative bütün gözlerde arama zorunluluğundan, direct mapped de satır içi esneklik eksikliğinden kurtulmuş olur.

**Değiştirme.** Miss olduğunda bu index satırındaki (index'leri ortak olan) bloklardan biri kaldırılıp bellekten getirilen veri konur. Hangisinin kaldırılacağı FIFO, random ya da LRU olabilir; ama hesap yalnız bu satırın içinde yapılır, bütün önbellek üzerinde LRU hesabı gerekmez.

> **Hocanın vurgusu:** Direct mapped, fully associative ve set associative için adres bölümlemenin nasıl yapıldığını, referans edilen bir adres için verinin nasıl arandığını ve değiştirme politikasının nasıl işlediğini net anlamış olmak çok önemli. Sonraki konu olan sanal bellek de bu önbellek yapısına dayanacak; sayfa tablosunun kendi önbelleği, belleğe getirilen veri için de veri önbelleği olan bütün bir sistem ele alınacak.

## 13. Değiştirme Politikaları

Şimdiye kadarki işlemler okuma (read) içindi. Yazmaya geçmeden önce okuma tarafında verinin nasıl kaldırılacağı bir slaytla toparlandı (ekrandan, 01:30:00). Slaytın sorusu: bir blok getirildiğinde hedef setteki hangi blok değiştirilmelidir?

- **Optimal algoritma:** En uzun süre kullanılmayacak blok değiştirilir; geleceği bilmeyi gerektirir. Hoca bunu yürütülmeyi bekleyen komutlara bakarak ileriye yönelik bir projeksiyonla en az kullanılması beklenen satırın kaldırılması diye açıkladı.
- **Kullanıma dayalı algoritmalar:** LRU, en az yakın zamanda referans edilen bloğu değiştirir; gerçeklemesi zordur.
- **Kullanıma dayalı olmayan algoritmalar:**
  - FIFO: Set dairesel bir kuyruk gibi ele alınır, kuyruğun başı değiştirilir; gerçeklemesi kolaydır.
  - Random: Setteki rastgele bir blok değiştirilir; gerçeklemesi daha da kolaydır.

Bu politikalar associative mantık içeren önbelleklerde, yani set associative ve fully associative yapılarda geçerlidir. Direct mapped önbellekte bire bir eşleme olduğundan değiştirme doğrudan index'in gösterdiği satıra gitmektir.

Donanım karşılıkları da kısaca anıldı. FIFO için her önbellek gözü için bir sayaç tutulup her erişimde artırılabilir; sayacı en büyük olan, önbelleğe ilk konan veridir. Random'da rastgele bir blok numarası üretilir. LRU'da en az yakın zamanda kullanılan satırı gösteren bir bit tutmak gerekir (örnekteki iki satırlı önbellekte tek bir LRU göstergesi kullanılır).

> **Ek bilgi (derste anlatılmadı):** İki way'li bir sette LRU için tek bit yeter, çünkü bit yalnız iki bloktan hangisinin daha eski kullanıldığını gösterir. Way sayısı arttıkça tam LRU sırasını tutmak için gereken durum bilgisi hızla büyür; slayttaki "gerçeklemesi zor" ifadesi bundan kaynaklanır.

## 14. Yazma Politikaları: Write-Through ve Write-Back

İşlemci doğrudan önbellekle çalışır; bellek ikinci plandadır ve yalnız önbellekte bulunamayan veri için belleğe gidilir. Aynı durum yazma için de geçerlidir. Bir veri önbellekte güncellendiğinde bellekte henüz güncellenmemiş olabilir. Başka bir program bu veriyi bellekten okumak isterse tutarlılık (consistency) sağlanmalıdır. İki senaryo vardır:

**Birinci senaryo (write-back).** Veri yalnız önbellekte güncellenir ve işlemlere önbellekteki güncel hâliyle devam edilir. Bellek ancak bu veri önbellekten kaldırılması gerektiğinde güncellenir. Güncellenmiş olma bilgisi bir **dirty biti** olarak tutulur; dirty biti 1 olan bir satır değiştirilecekse veri önce bellekte güncellenir. Avantajı, maliyetli bellek erişiminin azalmasıdır; dezavantajı, önbellekteki güncel verinin değiştirilip değiştirilmeyeceğini izleyen ek bir kontrolün gerekmesidir.

**İkinci senaryo (write-through).** Önbellek güncellenirken bellek de aynı anda güncellenir. İşlem maliyeti yüksektir (her yazmada iki yere yazılır) ama izleme gerekmez.

Write-through slaytı (ekrandan, 01:35:00): işlemcinin store işlemi önbelleği **ve** belleği günceller; bellek her zaman önbellekle tutarlıdır; programlarda load sayısı store sayısının yaklaşık 2 katıdır; write-through, alt seviye belleği beklememek için her zaman yazma tamponlarıyla (write buffer) birlikte kullanılır. Şekilde işlemciden önbelleğe giden store yolu belleğe de uzanır; load önbellekten işlemciye, cache load bellekten önbelleğe doğrudur. Write-back'te ise veri yalnız önbellekte güncellenir; dirty biti 1 olan satır değiştirilirken önbellekten belleğe aktarım yapılır.

## 15. Örnek: Write-Through ve Write-Back Adım Adım

Slayttaki kurulum (ekrandan, 01:40:00): 16 gözlü (16 byte'lık) bir bellek, 2 bloklu fully associative önbellek, her blok 2 byte. Başlangıçta önbellek boş, valid bitleri 0; değiştirmede LRU kullanılır. Bellek içeriği:

| Adres | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Değer | 78 | 29 | 120 | 123 | 71 | 150 | 162 | 173 | 18 | 21 | 33 | 28 | 19 | 200 | 210 | 225 |

(Adres 0'ın başlangıç değeri 78'dir; write-back slaytında görünür, ekrandan, 01:45:00.)

Komutlar:

```text
Ld R1 <- M[1]
Ld R2 <- M[7]
St R2 -> M[0]
St R1 -> M[5]
Ld R2 <- M[10]
```

Blok 2 byte olduğu için offset 1 bittir; en düşük anlamlı bit dışında adresi aynı olan iki byte birlikte önbelleğe gelir. Tag, adresin 1 bit sağa kaydırılmış hâlidir: 0-1 adresleri tag 0, 2-3 tag 1, 4-5 tag 2, 6-7 tag 3, 10-11 tag 5. Komutlardaki adreslerin tag'leri sırasıyla 0, 3, 0, 2, 5'tir.

### 15.1 Write-Through

1. **`Ld R1 <- M[1]`:** Tag 0 önbellekte yok: miss. 0 ve 1 adreslerindeki 78 ve 29 önbelleğe çekilir, valid 1, tag 0. R1 = 29. LRU artık diğer (boş) satırı gösterir.
2. **`Ld R2 <- M[7]`:** Tag 3 yok: miss. 6 ve 7 adreslerindeki 162 ve 173 ikinci satıra çekilir, valid 1, tag 3. R2 = 173. LRU üstteki satırı (tag 0) gösterir.
3. **`St R2 -> M[0]`:** Adres 0'ın tag'i 0, offset 0. Tag 0 önbellekte var: hit. R2'deki 173 bu satırın 0 offsetine yazılır; write-through olduğu için bellekte adres 0 da aynı anda 173 yapılır (ekrandan, 01:40:00; slaytta bu adımda Misses: 2, Hits: 1). LRU alttaki satırı (tag 3) gösterir.
4. **`St R1 -> M[5]`:** Adres 5'in tag'i 2; önbellekte yok: miss. Önce veri önbelleğe çekilir: LRU olan alt satır (tag 3) kaldırılır, 4 ve 5 adreslerindeki 71 ve 150 getirilir, tag 2 olur. Sonra R1'deki 29 bu bloğun 1 offsetine yazılır; write-through gereği bellekte adres 5 de 29 yapılır. LRU üst satırı gösterir.
5. **`Ld R2 <- M[10]`:** Tag 5 yok: miss. LRU üst satırdır; tag 0'lı blok kaldırılır, 10 ve 11 adreslerindeki 33 ve 28 getirilir. R2 = 33.

Sonuç: miss, miss, hit, miss, miss; **4 miss, 1 hit**.

> **Ders sonrası not:** Hoca sonucu söylerken "dört tane hit ile" dedi ve dördüncü komutu "üçüncü işlem" diye andı. Doğrusu 4 miss ve 1 hit'tir. Adımlar python ile benzetilerek doğrulandı.

### 15.2 Write-Back

Write-back için önbellekte valid bitinin yanında bir de dirty biti (slaytta `d`) tutulur. Dirty biti 1, verinin önbellekte güncellendiğini gösterir; böyle bir satır değiştirilecekse önce bellekteki ilgili adresler güncellenir. Referans dizisi aynıdır. Başlangıçta valid ve dirty bitleri 0'dır.

1. **`Ld R1 <- M[1]`:** Miss. Tag 0'lı blok (78, 29) önbelleğe gelir. R1 = 29. Bu yapıda blok genişliği 2 byte, offset 1 bit olduğundan 0 ve 1'den biri referans edildiğinde ikisi birden aktarılır.
2. **`Ld R2 <- M[7]`:** Miss. LRU boş satırı gösterir; tag 3'lü blok (162, 173) oraya çekilir. R2 = 173.
3. **`St R2 -> M[0]`:** Tag 0'lı göz bulunur: hit. Valid 1, dirty 0'dır. R2 bu bloğun 0 offsetine yazılır (173) ve dirty biti 1 yapılır, ama bellek bu aşamada güncellenmez; bellekte adres 0 hâlâ 78'dir (ekrandan, 01:45:00; slaytta `V=1, d=1, tag=0` ve `V=1, d=0, tag=3`).
4. **`St R1 -> M[5]`:** Tag 2'li göz yok: miss. Veri önce bellekten önbelleğe getirilir. LRU alt satırdır (tag 3, dirty 0), doğrudan kaldırılır. 4 ve 5 adreslerindeki 71 ve 150 gelir; R1 (29) 1 offsetine yazılır, dirty biti 1, tag 2 olur. Bu veri artık bellekten farklıdır.
5. **`Ld R2 <- M[10]`:** Tag 5 yok: miss. LRU üst satırdır (tag 0). Kaldırılmadan önce dirty bitine bakılır: 1'dir, yani önbellekteki veri bellekten daha günceldir. Önce bellek güncellenir (adres 0 = 173, adres 1 = 29). Sonra 10 ve 11 adreslerindeki 33 ve 28 bu satıra getirilir, tag 5 olur. Satır artık bellekle uyumlu olduğu için dirty biti 0'a çekilir. R2 = 33.

Hit/miss sayısı write-through ile aynıdır: 4 miss, 1 hit. Fark bellek yazmalarının zamanlamasındadır: write-through her store'da belleğe yazar, write-back yalnız dirty bir satır değiştirilirken yazar.

Ders sonunda ekranda kalan son slayt "Kaç bellek başvurusu yapılır?" sorusunu soruyordu (ekrandan, 01:50:00); hoca bunu sözlü olarak işlemedi (bkz. Örnek Sorular).

### 15.3 Karşılaştırma

Direct mapped önbellekte adres index'i satırla bire bir eşleştiği için ayrı bir değiştirme politikasından söz edilemez, ya da çok basit bir politika vardır. Fully associative ve set associative yapılarda LRU, FIFO, random gibi politikalar kullanıldığından verinin önbellekte ve bellekte tutarlı tutulması için write-through ve write-back yöntemleri görüldü. Bu yöntemler arasında bir ödünleşim (trade-off) vardır: write-through her güncellemede belleğe de erişir; write-back ise önbellekteki güncel verinin değiştirileceğini anlamak için ek kontrollere ihtiyaç duyar. Hangisinin daha avantajlı olduğuna duruma göre karar verilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00). 4 word'lük bloklara sahip, 16 KB veri tutan direct mapped bir önbellek olsun. 32 bitlik bir mimari kullanılıyorsa tag, index ve offset alanlarının genişlikleri nedir?

> **Çözüm (derste verildi):** Word 4 byte, blok 16 byte, satır sayısı $2^{14}/2^4 = 2^{10}$. Index 10 bit, word offset 2 bit, byte offset 2 bit, tag $32 - 14 = 18$ bit. `0000000AH` adresi için tag 0, index 0, word offset `10`, byte offset `10`.

**Soru 2** (ekrandan, 00:25:00). Aynı önbellekte, boş başlayarak `0x00000014`, `0x0000001C`, `0x00000034`, `0x00008014` adreslerine sırayla erişiliyor. Her erişim hit mi miss mi?

> **Çözüm (derste verildi):** Index/tag sırasıyla 1/0, 1/0, 3/0, 1/2. Sonuçlar: miss, hit, miss, miss (tag uyuşmazlığıyla satır 1 değiştirilir). Toplam 3 miss, 1 hit.

**Soru 3** (ekrandan, 00:35:00 ve 00:40:00). 64 KB direct mapped, 16 byte satırlı önbellekte `dot_prod` fonksiyonu iki 1024 elemanlı `float` dizinin skaler çarpımını hesaplıyor. İyi ve kötü durumda miss rate nedir?

> **Çözüm (derste verildi):** Satıra 4 float sığar. İyi durumda (x ve y farklı satırlarda) 8 okumada 2 miss: $1/4$. Kötü durumda (x[i] ve y[i] aynı satırda) her okuma diğerinin bloğunu siler: 8 okumada 8 miss, %100.

**Soru 4** (ekrandan, 00:45:00). Hit oranı 0.85, bellek erişim süresi 50 ns, önbellek erişim süresi 5 ns ise ortalama erişim süresi nedir?

> **Çözüm (derste verildi):** $t_a = 5 + 0.15 \times 50 = 12.5$ ns.

**Soru 5** (ekrandan, 00:50:00). L1 hit süresi 1 çevrim, L1 miss rate %5, L2 hit süresi 5 çevrim, L2 miss rate %15, L2 miss penalty 100 çevrim. Ortalama bellek erişim süresi nedir?

> **Çözüm (derste verildi):** L1 miss penalty $= 5 + 0.15 \times 100 = 20$ çevrim; ortalama erişim süresi $= 1 + 0.05 \times 20 = 2$ çevrim.

**Soru 6** (derste sözlü, 01:02:44). Direct mapped önbellekte değiştirme politikası nedir?

> **Çözüm (derste verildi):** Ayrı bir seçim yoktur; adresin index alanı hangi satırı gösteriyorsa o satırdaki blok değiştirilir.

**Soru 7** (derste sözlü, 01:10:52). Kısmen dolu bir fully associative önbellekte, index alanı yokken aranan verinin önbellekte olup olmadığı nasıl anlaşılır?

> **Çözüm (derste verildi):** Offset dışındaki bütün adres bitleri tag'dir. Valid biti 1 olan bütün satırların tag'leri referans adresinin tag'iyle (donanımda paralel olarak) karşılaştırılır; eşleşme varsa hit, hiçbirinde yoksa miss.

**Soru 8** (derste sözlü, 01:12:36). 16 KB, blok 16 byte, fully associative önbellek, 32 bit sistem. Adres bölümlemesi nasıl olur?

> **Çözüm (derste verildi):** Offset 4 bit (2 bit word, 2 bit byte), tag 28 bit; index yoktur.

**Soru 9** (ekrandan, 01:25:00). 16 KB büyüklüğe sahip 4-way set associative önbellekte blok genişliği 16 byte, sistem 32 bit (4 byte) bir mimari ise adres bölümlemesi nasıl olur?

> **Çözüm (derste verildi):** Satır $= 4 \times 16 = 64$ byte, satır sayısı $2^{14}/2^6 = 256$. Index 8 bit, word offset 2 bit, byte offset 2 bit, tag 20 bit.

**Soru 10** (ekrandan, 01:40:00 ve 01:45:00). 16 byte'lık bellek, 2 bloklu, 2 byte bloklu, LRU'lu fully associative önbellekte `Ld R1 <- M[1]`, `Ld R2 <- M[7]`, `St R2 -> M[0]`, `St R1 -> M[5]`, `Ld R2 <- M[10]` komutları write-through ve write-back ile yürütülüyor. Hit/miss sayıları ve bellek güncellemeleri nedir?

> **Çözüm (derste verildi):** Her iki politikada miss, miss, hit, miss, miss: 4 miss, 1 hit. Write-through'da M[0] = 173 ve M[5] = 29 store anında yazılır. Write-back'te iki store yalnız önbelleği günceller ve dirty bitini 1 yapar; son load'da dirty olan tag 0'lı satır atılırken M[0] = 173, M[1] = 29 belleğe yazılır. Sonunda R2 = 33.

**Soru 11** (ekrandan, 01:50:00). Write-back örneğinde kaç bellek başvurusu yapılır? Write-back mi write-through mu seçilmeli?

> **Çözüm (derste verilmedi):** Slayta göre her miss bir blok (bu önbellekte 2 byte) okur, değiştirilen her dirty satır bir blok yazar. 4 miss olduğu için toplam okuma $4 \times 2 = 8$ byte; slayta göre yazma, son değiştirmeden sonra 4 byte'tır. Bu büyük olasılıkla son load'da atılan tag 0'lı blok (2 byte) ile önbellekte dirty kalan tag 2'li bloğun sonunda atılmasıyla (2 byte) yazılan toplamdır; python benzetimi bu sayıyı verir. Write-through'da ise her store 1 byte yazar: bu dizide 2 byte yazma, ama her store anında belleğe erişim. Seçim, store sıklığına ve bellek trafiğine bağlıdır; hoca derste bu ödünleşimi duruma göre değerlendirmek gerektiğini söyledi. <!-- BELİRSİZ: slayttaki "Choose write-back or write-through?" sorusu derste sözlü olarak tartışılmadı; slaytın asıl beklediği cevap bilinmiyor. -->

## Dersin Toparlaması

Bu derste önbellek konusu tamamlandı. Direct mapped önbellekte adresin byte offset, word offset, index ve tag alanlarına nasıl bölündüğü, valid bitinin ve tag'in rolü, blok genişliğinin miss rate üzerindeki etkisi örneklerle işlendi. Hit ve miss olasılıklarından ortalama erişim süresi formülü $t_a = t_c + (1-h)\,t_m$ türetildi ve iki seviyeli önbellekte bu hesabın seviyeden seviyeye nasıl aktarıldığı gösterildi. Ardından direct mapped yapının tek satıra yığılma sorununa karşı fully associative (index yok, tüm tag'ler karşılaştırılır) ve iki yapının iyi yönlerini birleştiren set associative önbellek anlatıldı; aynı 16 KB, 16 byte bloklu önbellek için üç yapının alan genişlikleri karşılaştırıldı (18/10/2/2, 28/–/2/2, 20/8/2/2). Son olarak FIFO, LRU, random ve optimal değiştirme politikaları ile write-through ve write-back yazma politikaları, iki satırlı bir fully associative önbellek üzerinde adım adım izlendi.

Bir sonraki konu sanal bellektir. Sanal bellek de burada görülen önbellek yapısına dayanır; verinin işlemciye ulaşana kadarki akışı sanal bellek ve önbellek birlikte, bütüncül bir sistem olarak ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
