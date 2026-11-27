# Ders 1 Genişletilmiş Notu: Algoritma, Veri ve Veri Yapısı Kavramları; Sözde Kod, Akış Diyagramları ve C Hatırlatması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Konu Akışı ve Kaynaklar
- 2. Algoritma Nedir?
- 3. Algoritmanın Özellikleri
- 4. Veri ve Verinin Bilgisayarda Tutulması
- 5. Veri Yapısı ve Neden Gerekli Olduğu
- 6. Algoritma Hazırlama Süreci
- 7. Algoritmayı Sözde Kod ile İfade Etmek
- 8. Algoritmayı Akış Diyagramı ile İfade Etmek
- 9. C Dilinin Temelleri (Hatırlatma)
- 10. C'de Operatörler ve İşlem Öncelikleri
- 11. C'de Kontrol Yapıları
- Örnek Sorular

## 1. Dersin Konu Akışı ve Kaynaklar

Dönemin ilk dersinde önce dersin işleyişi anlatıldı, sonra konulara girildi. Bu ilk derste, önceki yıllarda öğrenilen konuların bu derste nasıl kullanılacağını göstermek için küçük hatırlatmalar yapıldı.

Dersin konu akışı şöyle anlatıldı:

- Giriş: algoritma, veri, veri yapısı kavramları ve algoritmik problem çözmenin temelleri; akış diyagramları ve C kodlamayla ilgili hatırlatma.
- Algoritma nasıl tasarlanır, algoritmik problem çözmek ne demektir (örneklerle).
- Algoritma analizi: aynı işi yapan farklı algoritmalar nasıl karşılaştırılır, bir algoritmanın performansı nasıl ölçülür.
- Liste yapıları, özellikle linkli listeler: nasıl oluşturulur, nasıl kullanılır.
- Stack ve queue: ne işe yararlar, hangi uygulama alanları vardır.
- Ağaçlar, ikili ağaçlar ve ikili arama ağacı ile arama problemi.
- Heap veri yapısı ve heap ile sıralama; geleneksel sıralama algoritmalarına göre ne kadar iyileştirme sağladığı.
- Heap temelli öncelikli kuyruk.
- Graflar ve graf uygulamaları; minimum yayılımlı ağaç.
- Böl ve yönet algoritmaları: neyin nasıl bölüneceği ve nasıl birleştirileceği.
- Arama algoritmaları, özellikle uzun metinlerde (string) arama.
- Sıralama algoritmalarının karşılaştırılması ve algoritmaların hangi ölçütlere göre değerlendirileceği.

Hoca stack, queue ve heap için İngilizce adları kullanacağını söyledi. Bunun nedeni Türkçede "yığın" ve "yığıt" kelimelerinin hem stack hem heap için kullanılması ve karışıklık yaratmasıdır.

Ders içeriği hazırlanırken üç kitaptan yararlanıldığı söylendi: Levitin'in algoritma tasarımı ve analizi kitabı (ikinci baskı), Sedgewick'in "Algorithms" kitabı (dördüncü baskı) ve Cormen ve arkadaşlarının "Introduction to Algorithms" kitabı (üçüncü baskı). Hocaya göre Sedgewick ve Cormen veri yapıları ve algoritmalar alanının temel kaynaklarıdır. Levitin ise algoritma tasarımı konusunda değerlidir.

<!-- BELİRSİZ: 00:26:04 civarında Levitin kitabının adı altyazıda "Design and Analysis of Algorithms" diye geçiyor; kitap kapağı karelerde görülmedi. -->

## 2. Algoritma Nedir?

### 2.1 Kelimenin kökeni

Algoritma kelimesi bir kişinin adından doğmuştur: Ebu Cafer Muhammed bin Musa el-Harezmi. Bu adın en önemli kısmı "el-Harezmi"dir. Kelime zaman içinde "algoritma"ya dönüşmüştür. Hocanın anlattığına göre El-Harezmi 780 yılında Harezm'de doğmuş, Bağdat'ta yaşamış bir matematikçidir. O dönemde bilgisayar bilimi ya da astronomi gibi ayrı bilim dalları yoktu, bilim insanları matematikçi ya da gökbilimci olarak anılırdı.

El-Harezmi, Hint rakamlarıyla hesap yapma yöntemlerini anlatan bir eser yazmıştır. Bu eser bir problemi çözmek için hesapların nasıl yapılacağını ve sayıların nasıl kullanılacağını anlatır. Hocanın anlatımına göre eser 825 yılında yazılmış, daha sonra Avrupa'da bilimin ortak dili olan Latinceye çevrilmiştir. Latince çevirinin adı "Algoritmi de numero Indorum" yani "Hint rakamlarıyla hesap yapma"dır. "Algoritma" kelimesi buradan gelir.

<!-- BELİRSİZ: 00:37:37-00:37:51 arasında altyazıda boşluk var; eserin adı ve hocanın "Algebrick kitabı" dediği yer net değil. -->

> **Ders sonrası not:** Hoca Latince çevirinin 1300'lerde yapıldığını söyledi. Bu çeviri büyük olasılıkla 12. yüzyılda (1100'ler) yapılmıştır.

### 2.2 Tanım

Kelimenin kökeni "hesap yapma"ya dayandığına göre, algoritmadan söz etmek için işlem yaparak çözülen bir problem olmalıdır. Her şey için algoritma olmaz. Hocanın tanımı şudur: Bir problemin işlemlerle çözümünde izlenecek yol teorik olarak oluşturulduğunda bir algoritma tasarlanmış olur.

Slayttaki tanım (ekrandan, 00:45:00):

- Algoritma, belirli bir problemi çözmek için art arda uygulanacak **kesin** direktiflerden oluşan **sonlu** bir kümedir.
- Algoritma, mantıklı ve doğru tüm girdiler için **doğrudur** ve doğru çıktıyı sonlu bir zamanda üretir.
- Bunun dışındaki durumlar algoritma değildir.

### 2.3 Örnekler

- **Sıralama:** Elde bir dersin 64 öğrencisinin notları vardır. Notların dağılımını, düşük ve yüksek notları, kırılma noktalarını görmek için önce küçükten büyüğe ya da büyükten küçüğe sıralamak gerekir. Aralarında eşit değerler de olabilir. Bu işi adım adım işlemler tanımlayarak teorik olarak çözmek bir sıralama algoritması tasarlamaktır.
- **En kısa yol:** Davutpaşa'daki üniversite ile Beşiktaş'taki ev arasında sahil yolu, E5 ve bunları bağlayan birkaç bağlantı yolu olsun. Trafik ve bekleme sürelerini de hesaba katarak iki nokta arasındaki en kısa yolu bulan bir yöntem geliştirmek, bir en kısa yol algoritması tasarlamaktır. Bunun için önce problemin ve işlenecek verinin uygun yapılarla tanımlanması gerekir.
- **Ödev planlama:** Birden fazla ödevi tamamlamak için "önce şunu yapmalıyım, sonra şunu kodlamalıyım" diye işlemlerin sırasını oluşturmak bir ödev çözme algoritmasıdır.
- **Web araması:** Arama motoruna "algoritmanın kökeni" gibi anahtar kelimeler gelir. Hangi sayfaların bununla en ilişkili olduğu, hangisinin birinci sıraya, hangisinin altıncı sayfaya konacağı bir sıralama (ranking) problemidir.

Teorik çözüm bir programlama dili kullanılarak gerçeklenirse buna algoritmanın **programı** denir.

### 2.4 Algoritmanın sınırları

Direktifler kesin olmalıdır. "Bunu topla", "bunu şuraya ata" gibi kesin ifadeler gerekir; muğlak ifadelerle algoritma tasarlanamaz. Direktif kümesi sonlu olmalıdır: sonsuza kadar dönen bir yöntem algoritma değildir. Algoritma doğru girdiler için doğru çıktıyı sonlu bir zamanda üretmelidir. "Sonsuz zaman beklerseniz sonuç çıkacak" diyen bir çözüm algoritma sayılmaz.

Algoritmalar yalnız bilgisayar dünyasında olmak zorunda değildir. Slayttaki görsel örnek diş fırçalamadır (ekrandan, 00:45:00): fırçayı al, macunu sür, dişleri fırçala, suyla çalkala, fırçayı yıka, fırçayı ve macunu kabına koy. Hoca bu adımların kesinleştirilmesi gerektiğini de vurguladı: macun kapağının açılması, dişlerin hangi sırayla ve kaç tekrar fırçalanacağı, kaç kez çalkalanacağı tanımlanmalıdır. Başlangıç ve girdiler bellidir, adımlar kesin ve sonludur ("sonsuza kadar fırçala" yoktur), doğru girdiye karşı doğru çıktı (temiz dişler) yaklaşık iki dakikalık sonlu bir sürede üretilir. Bu yüzden bir diş fırçalama algoritmasından söz edilebilir.

## 3. Algoritmanın Özellikleri

Bir yöntemin algoritma olarak adlandırılması için şu özellikleri taşıması gerekir:

- **Anlaşılırlık (unambiguous):** Adımlar, girdiler ve çıktılar net olmalı ve yalnız tek bir anlam taşımalıdır. "Kesin direktif" bunun anlamıdır.
- **Girdi:** Algoritmalar genellikle girdi, işlem, çıktı düzeninde çalışır. Sıfır ya da iyi tanımlanmış $n$ tane girdi kullanılır.
- **Çıktı:** En az bir tane, iyi tanımlanmış ve kesin çıktı üretilmelidir.
- **Sonlanma:** Belirli bir adımdan sonra algoritma durmalıdır, sonsuza kadar dönmemelidir.
- **Yapılabilirlik (feasibility):** Algoritma mevcut imkânlarla gerçekleştirilebilmeli ve makul sürede sonuç üretmelidir. Henüz icat edilmemiş bir bilgisayarda çalışabilecek bir yöntem algoritma sayılmaz.
- **Programlama dilinden bağımsızlık:** "Bu algoritmayı yalnız Python için tasarladım" ya da "yalnız Java'nın şu sürümünde çalışır" denemez. Algoritma, bütün programlama dillerinden bağımsız teorik bir çözüm yöntemidir.

Algoritmalarla çözülen başlıca problem aileleri sıralama, alt metin arama, graf problemleri (örneğin harita üzerinde en kısa yol), kombinatoryal problemler, geometrik problemler ve sayısal yöntemlerin adım adım ilerletildiği nümerik problemlerdir. Hoca bunlarla sınırlı olmadığını, bilgisayar mühendisliğindeki hemen her problem için algoritma tasarlamak gerektiğini söyledi.

## 4. Veri ve Verinin Bilgisayarda Tutulması

### 4.1 Veri

Algoritmaların "benzini" veridir. Algoritmalar tarafından işlenen en temel elemanlara veri denir:

- Sayısal (nümerik) bilgiler.
- Metin tabanlı bilgiler: karakterler ve karakter dizileri.
- Resimler: aslında iki boyutlu bir dizi ya da matris şeklinde sıralanmış sayılardır; görselleştirildiğinde resim olur.
- Sesler: bir ya da iki boyutlu sayısal verilere dönüştürülerek gösterilir.

Yani algoritmalar temelde sayılar ve metinlerle çalışır, ama bunlar belge, resim, ses ya da video gibi farklı biçimlerde karşımıza çıkar. Veri girdilerde, çıktılarda ve ara hesaplamalarda kullanılır. Algoritmanın işleyeceği verinin mutlaka düzenlenmiş olması gerekir.

### 4.2 Aynı verinin farklı gösterimleri

Hoca 32 bitlik işaretsiz bir tamsayının farklı gösterimlerini slaytla anlattı (ekrandan, 01:05:00):

| Gösterim | Değer |
|---|---|
| Uint (32 bit) | `1111573057` |
| Ham veri | `01000010010000010100001001000001` |
| BCD kodlama | `0100 0010 0100 0001 0100 0010 0100 0001` |
| HEX | `42 41 42 41` |
| ASCII | `B A B A` |

Bellekte ya da diskte veri sıfırlar ve birler olarak, yani voltaj karşılıkları olarak durur. Bunu okumak insan için zordur. Dörtlü gruplar hâlinde yazmak (slaytta BCD diye anılan gösterim) ve onaltılık tabana geçmek okumayı kolaylaştırır. ASCII tablosuyla `42` onaltılık değeri `B`, `41` ise `A` karakterine karşılık gelir. Böylece aynı veri ekranda dört harflik `BABA` kelimesi olarak görülebilir ve üzerinde algoritma çalıştırılabilir.

Ajan bu dönüşümü python ile doğruladı: `0x42414241 = 1111573057` ve baytlar ASCII'de `BABA` verir.

> **Ek bilgi (derste anlatılmadı):** BCD (binary coded decimal) normalde her ondalık rakamın dört bitle kodlanmasıdır. Slayttaki dörtlü gruplar ise ham bitlerin onaltılık rakamlara (nibble) bölünmüş hâlidir. Değer ondalık rakamlarla değil onaltılık rakamlarla eşleştiği için bu gösterim büyük olasılıkla tam anlamıyla BCD değildir.

### 4.3 Veri bellekte nerede durur?

İşlemcide (CPU) o saat çevriminde (clock cycle) çalışan değişkenlerin değerleri yazmaçlarda (register) tutulur. Von Neumann mimarisine göre bellekte hem veri hem program kodu aynı ortamda durur. Program kodu, üst düzey bir dilde yazılıp derlenmiş programın makine koduna dönüştürülmüş hâlidir. Programın kullandığı veriler de belirli adreslerdeki alanlarda tutulur. Örneğin 32 bitlik bir tamsayı 4 baytlık bir alanda saklanır.

## 5. Veri Yapısı ve Neden Gerekli Olduğu

### 5.1 Tanım

Verinin algoritmalar için kullanılabilir hâle gelmesi, yani algoritmaların etkin çözüm üretebilmesi için veri çeşitli biçimlere sokulur. Slayttaki tanım (ekrandan, 01:10:00): Algoritmaların erişme, değiştirme gibi çeşitli işlemlerinde kullanmak üzere bilginin saklandığı oluşumlara veri yapıları adı verilir.

Verinin hangi yapıda şekillendirileceği, erişim ve kullanım kurallarının ne olacağı, hangi elemanın hangisine nasıl bağlanacağı ve aralarındaki ilişki tanımlandığında bir veri yapısı tanımlanmış olur. Kısacası veri yapısı, verinin bellekte tutulma şekli ve düzenidir.

Slayttaki örnekler ve hocanın açıklamaları:

- **Listeler**
  - Diziler: Örneğin 10 elemanlı bir tamsayı dizisi. İndisle belirli bir elemana (örneğin 6. sıradakine) doğrudan erişim sağlar.
  - Linkli listeler: Teorik olarak yalnız bellekle sınırlı uzunlukta, dinamik diziler oluşturmayı ve üzerinde gezinmeyi sağlar.
- **Stack:** Raftaki üst üste duran tabaklar gibidir. Alttaki çekilip alınamaz, yalnız en üstteki alınabilir.
- **Queue.**
- **Hash tabloları:** Bu ders kapsamında işlenmeyecek.
- **Ağaçlar:** Veri depolama ve arama gibi işlerde algoritmaların hızlı çalışmasını sağlayan özel tasarımlı yapılar.
- **Heap ve öncelikli kuyruk:** Heap özel bir ağaçtır. Öncelikli kuyruk heap kullanılarak kurulan, ağaç temelli daha üst seviyeli bir yapıdır.
- **Küme ve sözlük:** Java ya da .NET gibi ortamlarda daha çok görülen, soyut ve üst seviyeli yapılar.

### 5.2 Neden veri yapısı gerekir?

"Veriyi düz kullansak, belleğe doğrudan erişsek ne olur?" sorusunun cevabı etkinliktir: hızlı çalışmak ya da belleği verimli kullanmak, az yer kaplamak. Slayttaki maddeler (ekrandan, 01:15:00):

- Veri yapıları, verinin etkin olarak saklanması ve işlenebilmesi için gereklidir.
- Doğru yerde kullanıldığında en basit veri yapısı dahi oldukça etkili olabilir.

**Seyrek matris örneği.** Bir nümerik problemde $n \times n$ boyutunda bir matris gerektiğini düşünelim. Bu bir görüntü ya da bir birliktelik matrisi olabilir. $n = 1000$ gibi küçük bir değer için bile matris bir milyon gözdür. Problemin doğası gereği matrisin çok az dolu olduğu biliniyor olsun. Slaytta örnek olarak 1. ve $n$. sütun ile diyagonal dışındaki değerlerin 0 olduğu durum verilmiştir. Hocanın sözlü örneğinde bir milyon gözün belki 950 bini sıfırdır ve yalnız 50 bin göz değer taşır.

- Düz mantıkla $1000 \times 1000$ iki boyutlu dizi kullanılırsa bir milyon tamsayılık yer ayrılır.
- Matrisin seyrek (sparse) olduğu bilinerek yalnız sıfırdan farklı değerler (satır indisi, sütun indisi, değer) üçlüleri olarak ve birbirini gösterecek şekilde tutulursa, yalnız tutulan değer kadar yer ayrılır.

Matrisin %95'i sıfırsa bu yaklaşık %95 daha az yer demektir. Aynı problem aynı veriyle çözülür, ama bellekteki "ayak izi" çok küçülür. Biri basit bir bilgisayarda ya da cep telefonunda bile çalışabilirken, diğeri büyük bellekli bir sunucu gerektirebilir. Veri yapıları bu yüzden gerektiğinde zamandan, gerektiğinde yerden kazanmak için kullanılır.

> **Ek bilgi (derste anlatılmadı):** Her sıfırdan farklı eleman için üç değer (satır, sütun, değer) ve bağlı yapıda bir de bağlantı tutulduğundan, eleman başına harcanan yer artar. Bu yüzden seyrek gösterim, yalnız sıfırdan farklı elemanların oranı yeterince düşük olduğunda kazançlıdır.

## 6. Algoritma Hazırlama Süreci

Bütün algoritmaların şu beş adımdan geçmesi beklenir:

1. **Tasarım:** Önce düşünülür ve düşünülen çözüm adım adım bir işlem sırası olarak ifade edilir. Örneğin 64 not değerini sıralamak için hangi adımın uygulanacağı, neyin nerede tutulacağı, neyin neyle karşılaştırılacağı, küçükse ve büyükse ne yapılacağı. Hoca burada genelde bilinen "önce analiz, sonra tasarım" sırasının ters göründüğünü, bunun nedeninin aynı kelimelerin kullanılması olduğunu belirtti.
2. **Doğrulama (validasyon):** Algoritmanın taşıması gereken özelliklere uyup uymadığına bakılır. Girdi aldığında doğru işlemleri yapıp sonlu zamanda doğru sonucu ürettiği ispatlanır.
3. **Analiz:** Uç durumlar için veriyle denemek de olabilir. Ama asıl anlamı, tasarlanan çözümün muadillerine göre ne kadar hızlı olduğunu ya da ne kadar az bellek harcadığını, yani performansını ve karmaşıklığını ortaya koymaktır.
4. **Gerçekleme:** Algoritma kodlanır ve bir program hâline getirilir.
5. **Test:** Gerçek hayat verileriyle algoritmanın ne kadar etkin çalıştığı izlenir.

Önce her şey kafadadır: Problem nasıl çözülmeli, adımlar hangi sırayla olmalı, hangi veri yapıları işi kolaylaştırır?

## 7. Algoritmayı Sözde Kod ile İfade Etmek

Algoritmayı ifade etmenin iki temel yolu vardır: sözde kod (pseudo-code) ve akış diyagramı. Derste genellikle akış diyagramı kullanılacağı söylendi. Ama özellikle özyinelemeli (recursive) algoritmalarda sözde kod da faydalıdır.

### 7.1 Sözde kod nedir?

Sözde kod yarı programlama dili, yarı konuşma dili gibi bir yazım şeklidir. Akış, işlem sırası ve verinin nasıl işlendiği "kodumsu" bir notasyonla anlatılır.

Slayttaki basit örnek (ekrandan, 01:20:00):

```text
Toplam Hesapla (dizi, toplam,)
Girdi: n sayıdan oluşan dizi
Çıktı: dizi elemanlarının toplam sonucu
for i:=1 to n do
  toplam:= toplam + dizi[i]
end for
```

Hoca bu örneğin "muhteşem olmadığını, eksikleri olduğunu" söyleyerek açıkladı. Bir işlem adı vardır ("Toplam Hesapla"). Toplamı hesaplamak için $n$ sayıdan oluşan bir dizi gerekir; doğru girdi verilmezse doğru çıktı üretilemez. En az bir çıktı vardır: dizi elemanlarının toplamı. Döngü birden $n$'e kadar döner ve her adımda iki iş yapar: bir aritmetik toplama ve bir atama. Döngü `end for` ile biter. Başka işlem olmadığı için toplam hesaplanmış ve döndürülmüştür.

### 7.2 Sözde kod yazım kuralları

- Hata mesajları gibi o aşamada gereksiz olan ayrıntılar verilmez; ne yapılması gerektiği adım adım tanımlanır.
- Veri elemanlarını tanımlamaya gerek yoktur, ilk kullanıldıkları yerde tanımlandıkları varsayılır. Tiplerini belirtmeye de gerek yoktur.
- Ama bir veri yapısı (stack, ağaç vb.) kullanılıyorsa ne olduğu, ne içerdiği ve yapısı mutlaka tanımlanır.
- Algoritmanın adı, parametreleri, varsa ön ve son koşulları ve geri dönüş değeri belirtilir.
- İfadeler 1, 2, 2.1, 2.2 gibi alt numaralarla sıralanır.
- Değişkenler anlamlı adlandırılır. Döngü için `i, j, k` olabilir, ama `a, b, c, d, e` gibi adlar kullanılmaz. `toplam` gibi genel adlar da birden fazla dizinin toplamı hesaplanıyorsa yetersiz kalır; neyin toplamı olduğu adından anlaşılmalıdır.

### 7.3 Üç temel yapı

Slayttaki açıklama (ekrandan, 01:25:00): Yapısal programlama modelini ilk önerdiğinde Edsger Dijkstra, herhangi bir algoritmanın yalnız üç programlama yapısıyla yazılabileceğini belirtmiştir: **dizilim**, **seçim** ve **döngü**.

- **Dizilim:** Algoritma içindeki yürütme yolunu değiştirmeyen bir ya da daha fazla ifadedir. Toplama, atama, çıkarma gibi doğrusal işlemler.
- **Seçim:** Bir koşulu değerlendirir ve sıfır ya da daha fazla alternatifi yürütür. Değerlendirme sonucu hangi alternatifin işletileceğini belirler. Yani koşullu dallanmadır.
- **Döngü:** Bir kod bloğunu, belirli bir koşul sağlanana ya da belirli bir değere ulaşılana kadar tekrarlar.

Hoca Dijkstra'yı Hollandalı bir bilgisayar bilimcisi ve en kısa yol algoritmasıyla tanınan kişi olarak andı.

Derste gösterilen ikinci bir sözde kod örneğinde algoritma adı, amaç, ön ve son koşullar ve çıktı yazılmıştı. Adımlar 1, 1.1, 1.2, 1.2.1, 1.2.2 diye numaralanmıştı. Algoritma dosyanın sonuna kadar dönen bir ana döngü kuruyordu. Döngü içinde bir okuma (dizilim), ardından bir koşul (seçim) vardı; koşul doğruysa sayfa numarası bir artırılıyor ve bir şey yazdırılıyordu. Sonra başka dizilim adımları geliyordu. Üçüncü adımda satır sayısı döndürülüyordu.

<!-- BELİRSİZ: 01:26:49-01:28:42 arasındaki ikinci sözde kod örneğinin satırları karelerde görülmedi; yalnız hocanın anlatımından aktarıldı. -->

### 7.4 Sözde kod notasyonu

Slayttaki notasyon (ekrandan, 01:30:00):

- **Atama:** Genellikle Pascal'daki gibi `:=` ya da `←`. Örnek: `Max := 1000`, `Sum ← Sum + newItem`.
- **Eşitlik kontrolü:** `=`. Örnek: `a = b`.
- **Seçim:**
  - `if ( condition ) action1 end if`
  - `if ( condition ) action1 else action2 end if`
- **Döngü:**
  - `while (condition) do statements end while`
  - `do statements while (condition)`
  - `repeat statements until (condition)`
  - `for start to end step increment do statements end for`
- **İndis:** `arr[i]`, `avg[i+3]`.

Hoca atama için `:=` ya da ok kullanılmasını tavsiye etti, böylece atama ile eşitlik kontrolü karışmaz. Bu bir kural değil, tercih sebebidir. `if`ler iç içe yazılabilir. `do-while` bloğun en az bir kez çalışmasını garanti eder. `repeat-until` da benzerdir ve bazen daha okunaklı olabilir. Sözde kodda açılan her yapı kapatılır: `if ... end if`, `while ... end while`.

Bu kurallarla dizi toplamı daha biçimsel yazılabilir: adımlar 1, 2, 2.1, 3, 4 diye numaralanır; atamalar `:=` ile yapılır; `for` döngüsünde adım söylenmediyse artış birdir; döngü `end for` ile kapanır; `return toplam` ile sonuç çağırana döndürülür ve algoritma `end Toplam Hesapla` ile biter.

## 8. Algoritmayı Akış Diyagramı ile İfade Etmek

Akış diyagramı görsel olarak daha anlaşılır olduğu için tercih edilir. Elemanlar ve bunları bağlayan oklar vardır. Hoca bu konuyu, ödevlerde ve sınav kâğıtlarında sık görülen hatalar yüzünden ilk derste hatırlattığını söyledi: `if`ten çıkan bir kolun `while`ın içine saplanması, iç içe açılmış `for`ların ikincisi kapanmadan akışın başka yere gitmesi gibi.

### 8.1 Bileşenler

Slayttaki liste (ekrandan, 01:35:00):

- Başla - Bitir (Start - Stop)
- Okuma (Read / Inputs)
- Bağlantılar (Connections): oklar, çemberler
- İfadeler / İşlemler (Statements / Process)
- Kararlar (Decisions): `if`, `case/switch`, ...
- Döngüler (Loops): `for`, `while`, `do while`, ...

### 8.2 Başla ve bitir

Elips ya da üstü altı düz, kenarları yuvarlak bir şekil kullanılır. İçine Türkçe "başla, bitir" yazılabilir, ama genellikle Start ve Stop (ya da Begin ve End) yazılır. Start algoritmanın ilk giriş noktasını, Stop sonlandığı yeri gösterir. Her akış diyagramının bir başlangıcı ve bir sonu olmalıdır. Diyagram karmaşıklaşmasın diye birden fazla Stop kullanılabilir, ama mümkünse tek Stop tercih edilir.

### 8.3 Okuma

Okuma bileşeni delikli kart (punch card) biçimindedir. Veri nerede okunuyorsa oraya konur, genellikle Start'tan hemen sonra gelir. Her değişken ayrı bir kutuda okunabilir, ama yer tasarrufu için değişkenler virgülle ayrılarak tek kutuda yazılır. Farklı zamanlarda okunacak gruplar için ayrı bileşenler kullanılır.

Bir diziyi okumanın iki yolu vardır:

- Bir `for` döngüsü kurup her adımda bir eleman okumak.
- $A_N$ notasyonunu kullanmak: $A$, $N$ elemanlı bir dizidir ve $N$ değer okunacaktır.

> **Hocanın vurgusu:** Önce $A_N$, sonra $N$ okunursa bu bir tasarım hatasıdır. Kaç değer okunacağı bilinmeden değerler okunamaz. Önce $N$ okunmalı, sonra $A$ dizisine $N$ değer okunmalıdır.

Ayrıca algoritmada kullanılan ve başlangıçta girdi olarak gelmesi gereken her değer bir okuma bileşeninde gösterilmelidir. Okumayı unutmak da bir hatadır.

### 8.4 Bağlantılar: oklar ve çemberler

Slayttaki maddeler (ekrandan, 01:40:00):

- **Oklar:** Akıştaki iki elemanı birbirine bağlar ve akışın yönünü gösterir. Eğri büğrü değil, köşeli çizilir.
- **Çemberler:** Bağlantıları basitleştirmek ve okunabilir kılmak için kullanılır (iç içe döngüler, iç içe kontroller vb.). Numaralandırmalara dikkat edilmelidir.

Okların mutlaka yönlü olması, düz ya da 90 derece köşeli çizilmesi gerekir. Yer sınırlı olduğunda akışın yukarı mı aşağı mı gittiği karışabilir, buna dikkat edilmelidir.

Algoritma büyüdüğünde bir okun üç `for`un etrafından dolaşarak geri dönmesi gerekebilir. Bu çok uzun çizgiler oluşturur. Bunun yerine okun çıktığı yere numaralı bir çember konur, okun saplandığı yere de aynı numaralı çember konur. Hoca bunu bir "solucan deliğine" benzetti: "birden girdim, öbür birden çıktım".

Numaralandırmada hata yapılırsa, örneğin iç döngü 1, dış döngü 2 olması gerekirken 1'den çıkılıp 2'ye, 2'den çıkılıp 1'e girilirse, iç içe olmayan ve programlanamayan bir akış ortaya çıkar. Bu, yapılabilirlik özelliğini bozar ve tasarımın yanlış olduğunu gösterir. Çemberler doğru sırayla iç içe birleştirilmelidir.

### 8.5 İfadeler ve işlemler

Slayttaki maddeler (ekrandan, 01:45:00): İşlem kutusu aritmetik işlem, atama gibi ifadelerden en az birini içerir ve dikdörtgenle gösterilir. Algoritmalar programlama dillerinden bağımsız tasarlanmalıdır: dile özel operatör ve dile özel değişken kullanılmamalıdır.

Slayttaki örnekte doğru kutu `A = A + 1`, üzeri çizili yanlış kutu `A++` idi. `A++` C'de ve Java'da vardır, ama akış diyagramında doğru bir ifade değildir. `A = A + 1` bütün dillerde aynı anlama gelir. Bu kutuda iki işlem vardır (toplama ve atama); bir dikdörtgende birden fazla işlem olabilir, yeter ki net ve dilden bağımsız olsun.

### 8.6 Kararlar: if

Eşkenar dörtgen de kullanılabilir, ama derste altıgen tercih edilir, çünkü iki çıkışın sağa ve sola gittiği daha net görülür.

Hoca eşkenar dörtgenin kökenini tahtaya çizerek anlattı: Bu şekil Fortran'dan gelir. Fortran'daki aritmetik `if`in üç çıkışı vardı: karşılaştırmanın sonucu negatifse bir yöne, pozitifse başka bir yöne, sıfırsa (iki değer eşitse) üçüncü yöne gidilirdi. Günümüzde `if`lerin yalnız doğru ve yanlış çıkışları olduğu için altıgen daha mantıklıdır.

Slayttaki maddeler (ekrandan, 01:50:00):

- Her zaman doğru (T)rue ve yanlış (F)alse kollarını belirtin.
- Her `if` ifadesinde mutlaka doğru (T) dalı olmalıdır.
- Yanlış (F) dalı isteğe bağlıdır.
- Algoritmadaki tüm `if` ifadelerinde T/F dallanmalarını aynı tarafta kullanmak tercih sebebidir.

Slayttaki şekilde altıgenin içinde `A = B` koşulu, sol kolda F, sağ kolda T etiketi ve her iki kolda `A = A + 1` kutuları vardı; kollar aşağıda birleşiyordu. Etiketler için D/Y de kullanılabilir, ama T ve F tavsiye edilir.

> **Hocanın vurgusu:** Doğru kolu olmadan yanlış kolu olamaz. Yalnız yanlış kolunda işlem varsa koşul ters çevrilmelidir (örneğin "eşit" yerine "eşit değil"). Hangi kolun doğru, hangisinin yanlış olduğu etiketlerle açıkça gösterilmelidir.

Bütün T kollarını aynı tarafa toplamak ölümcül bir kural değildir, ama koşul baştan düzgün yazılarak kolayca sağlanabilir. Eşitlik kontrolünde `==` ya da `===` gibi dile özel gösterimler kullanılmaz, `=` yazılır.

### 8.7 Döngüler: for

`for` döngüsü üç bölmeli bir dikdörtgenle gösterilir: ilk koşullar (ilk atamalar), her adımda ne kadar ilerleneceği (artı mı eksi mi, birer mi, beşer mi) ve son koşullar (durma koşulları). İlk atamalarda da ok kullanmak daha şık olur.

- Mümkünse her döngüde birer ilk koşul ve birer son koşul gösterilmelidir. C'de birden fazla atama yapılabilir, ama bu işi karmaşıklaştırır.
- Adım yazılmadıysa +1 anlamına gelir. Yine de adım boyutu gösterilmelidir.
- $N$'den 1'e doğru geriye tarama yapılıyorsa, ilk değer $N$ ve son koşul 1 olsa bile adım olarak $-1$ yazılması daha doğrudur.

Döngüye yukarıdan girilir. Tekrar edilecek blok döngünün içinde yer alır; bu blokta başka işlemler, kontroller ve döngüler olabilir. Blok bittiğinde adım kısmına dönülür. Koşul sağlanmaz hâle gelince akış döngünün altındaki oktan devam eder.

### 8.8 Döngüler: while

Slayttaki maddeler (ekrandan, 01:55:00): While döngüleri bilinmeyen sayıda iterasyona sahip döngüler için kullanılır ve bir şartın sağlandığı sürece işletilmesi esasına dayanır.

Şekilde yukarıdan gelen ok, içinde `J < N` yazan altıgene girer. Koşul doğruysa `A = A + 1` kutusuna gidilir, oradan dönen ok yeniden altıgene bağlanır. Koşul yanlış olduğunda `while`dan çıkılır ve akış aşağı doğru devam eder. Altıgen, `if` ile aynı şekildir.

> **Hocanın vurgusu:** While döngüsünde en önemli şey sonsuz döngüye girmemektir. Döngü bloğunun içinde koşulu etkileyen bir işlem olmalıdır. `J < N` koşulunda $N$ büyük olasılıkla sabit bir dizi boyutudur; $J$ bir şekilde artırılmalı ki bir noktada $J \geq N$ olsun ve akış devam edebilsin.

### 8.9 Örnek: dizinin toplamı (akış diyagramı)

Sözde kodla gösterilen dizi toplamı, akış diyagramıyla da gösterildi:

```text
Başla
  |
toplam = 0
  |
for i = 0 ; n'e kadar
  |    toplam = toplam + dizi[i]
  |
toplam'ı yazdır
  |
Bitir
```

<!-- BELİRSİZ: 01:57:13-01:58:20 arasındaki toplam akış diyagramı karelerde görülmedi; döngü sınırları ("sıfırdan n'e kadar") yalnız hocanın anlatımından alındı. -->

Algoritma belirli bir noktada başlar ve belirli bir noktada biter, içinde sınırları belli bir döngü vardır. Çıktı, yazdırma bileşeniyle gösterilir; bu ekrana ya da kâğıda yazdırma anlamına gelir. Hoca burada da atama için ok kullanmanın daha güzel olacağını belirtti.

## 9. C Dilinin Temelleri (Hatırlatma)

### 9.1 Fonksiyonlar

Slayttaki yapı (ekrandan, 02:10:00): fonksiyon tipi, fonksiyon adı, `(`, argümanlar, `)`, ardından `{`, tanımlamalar (declarations), ifadeler (statements) ve `}`.

- Bir C fonksiyonu, C dili işlemlerinden oluşan bir koleksiyondur.
  - C dilindeki temel işlemlerin hepsinden daha karmaşık bir işlem tanımı yapılmasını sağlar.
  - Anlaşılamayacak kadar karmaşık da olmamalıdır.
- Argümanlar, çağıran fonksiyondan çağrılan fonksiyona aktarılan verilerdir.

### 9.2 İfade, sabit ve değişken

- **İfade:** Yazılan kod satırlarıdır. Örneğin `j = 5 + 10;` bir aritmetik işlem yapar ve sonucu `j` değişkenine atar.
- **Sabit:** Hiç değişmeyen değerdir. `5` ya da `5 + 6 * 13 / 3.0` gibi bir ifade de sabittir.
- **Değişken:** Bellekteki belirli bir adresin gösterimidir. `int j, k;` ile iki tamsayı tanımlanır. Adresi derleyici ve bağlanmış (linked) program takip eder. Derste verilen örnekte bir adreste 4 bayt uzunluğunda `15` değeri tutuluyordu; bu, 32 bitlik bir mimariyi gösterir. Değişken adıyla kullanılır: `j / k * 5` gibi.
- Kesirli sayılar için `double` kullanılır. Ayrıca `int *p;` bir pointer tanımıdır ve bir adresi gösterir. Pointer üzerinde artırma ve azaltma yapılabilir. Karakter dizileri (string) de ilk gözünü gösteren bir pointer ile işaret edilebilir.

> **Hocanın vurgusu:** Pointer mantığı dönem boyunca neredeyse bütün algoritmalarda ve ödevlerde kullanılacak. Bu konuda eksik varsa hızla giderilmelidir.

### 9.3 İsimlendirme

Slayttaki kurallar ve örnekler (ekrandan, 02:15:00):

- C dilinde her şeye bir isim verilebilir: değişkenler, sabitler, fonksiyonlar, programdaki bir konum...
- İsimlerde harfler, rakamlar ve alt çizgi `_` bulunabilir. Harf ya da alt çizgi ile başlamalıdır.
- C dili büyük/küçük harf duyarlıdır.
- Ayrılmış anahtar kelimeler isim olarak kullanılamaz.

| Geçerli | Geçersiz |
|---|---|
| `j` | `5j` (rakamla başlıyor) |
| `j5` | `$name` (`$` kullanılamaz) |
| `__system_name` | `int` (ayrılmış kelime) |
| `sesquipedalial_name` | `bad%#*@name` (izin verilmeyen karakterler) |
| `UpPeR_aNd_LoWeR_cAsE_nAmE` | |

Hoca `$name` için PHP'de değişkenlerin dolarla başladığını, C'de bunun kullanılamayacağını hatırlattı. Ayrılmış kelimelere örnek olarak `auto`, `double`, `int`, `struct`, `break`, `else`, `long`, `switch` sayıldı.

Kod okunaklı yazılmalıdır: her blok bir öncekinden bir sekme (tab) içeride başlamalıdır. Bu bir kanun değildir, ama dikkat edilmesi gereken bir konudur.

### 9.4 main ve çıkış değeri

C programının giriş noktası `main` fonksiyonudur; `main` olmadan C programı olmaz. Genellikle bir geri dönüş değeri döndürmesi beklenir, böylece işletim sistemi sürecin nasıl bittiğini anlar. Bunun için `main` içinde `return` kullanılabilir ya da hazır kütüphane fonksiyonu `exit` çağrılabilir. `0` değeri hatasız ve normal sonlanmayı bildirir. Sıfır dışındaki değerler normal dışı sonlanmayı gösterir. Programı çağıran başka bir program bu hata koduna göre davranabilir (örneğin bellek yetersizliği ya da sıfıra bölme gibi farklı nedenler farklı kodlarla bildirilebilir).

### 9.5 Önişlemci

C derlenen bir dildir, yorumlanan bir dil değildir. Derleyici, kütüphanelerden çağrılan fonksiyonları ve ara dosyaları bağlayarak tek bir çalıştırılabilir dosya üretir. Slayttaki maddeler (ekrandan, 02:20:00):

- Ön işlemci program derlendiğinde otomatik çalışır.
- Tüm önişlemci tanımları `#` ile başlar; satırdaki ilk (boşluk hariç) karakter `#` olmalıdır.
  - Normal C ifadeleri `;` ile biter, ama önişlemci ifadeleri enter (yeni satır) ile sonlanır.
  - Ön işlemci ile başka yapılabilecekler: makro işleme, koşula dayalı derleme, makrolar ile hata ayıklama (debug).
- `#define` ile sabite isim atanabilir: `#define ZERO 0`. Bu isim artık değişken olarak kullanılamaz.
- `#include` ile derleme aşamasında başka bir kaynak dosyası okunarak eklenebilir.
  - `#include <filename>` ile işletim sisteminde belirli klasördeki kaynaklar okunur.
  - `#include "filename"` ile önce dosyanın klasörüne, orada yoksa işletim sistemindeki belirli klasöre bakılır.

Hoca önişlemci satırının sonuna `;` konursa hata alınacağını söyledi. Makroyu, derleme zamanında o yere bir kod parçası yazılması gibi düşünmek mümkündür. `ZERO` tanımlandıktan sonra büyük harfli `ZERO` değişken adı olarak kullanılamaz (büyük/küçük harf ayrımı unutulmamalıdır).

### 9.6 Veri tipleri

C'de 9 tane skaler veri tipi vardır. Temel tipler `char`, `int`, `float`, `double` ve `enum`'dır. Bunları niteleyen `long`, `short`, `signed` ve `unsigned` niteleyicileri vardır. Tanımlama örnekleri: `int i;`, `int i, j;`, `int i, j, k = 0;` (son örnekte `k`'ya ilk değer olarak 0 atanır). Veri tipleri hiyerarşik olarak `void`, skaler tipler ve birleşik (aggregate) tipler diye ayrılır; skaler tiplerin altında aritmetik tipler (tamsayı ve kayan noktalı), pointer'lar ve `enum`'lar vardır.

Tamsayıların boyutu mimariye ve ortama göre değişebilir. ANSI standardı yalnız şunu söyler:

- 1 bayt en az 8 bittir.
- `int` en az 16 bit olmalı ve bilgisayarın doğal boyutunu, yani CPU'nun tek komutta işleyebildiği bit uzunluğunu temsil etmelidir.

32 bitlik bir sistemde `int` 4 bayttır ($4 \times 8 = 32$ bit) ve değeri $-2^{31}$ ile $2^{31}-1$ arasındadır. Pozitif taraftaki bir eksiklik işaret biti yüzündendir. `short int` 2 bayta (16 bit) düşer, `long int` 32 bitlik mimaride yine 4 bayttır. `unsigned` niteleyicisi negatif değerleri atar ve aralığı sıfırdan başlatır.

> **Ders sonrası not:** Hoca `unsigned short` için aralığın "sıfırdan 2 üzeri 32'ye kadar" olabileceğini söyledi. 16 bitlik `unsigned short` için aralık $0$ ile $2^{16}-1 = 65535$ arasıdır. $0$ ile $2^{32}-1$ aralığı 32 bitlik `unsigned int` içindir.

Bunun pratikteki önemi, verilerin sınırlarını mimariye göre (32 bit ya da 64 bit) göz önünde bulundurmaktır: değişkenin birkaç bine mi yoksa milyarlara mı kadar gidebileceği önemlidir.

### 9.7 Tip dönüşümleri

Slayttaki maddeler (ekrandan, 02:25:00):

- Tamsayı-kesirli, işaretli-işaretsiz tipler arasında dönüşümler olasıdır.
- Implicit: `-3 / 4 + 2.5`. İşlem öncelik sırasını gözeterek derleyici terimleri birbiri ile uyumlu olacak şekilde dönüştürür.
- Explicit: `int j=2; k=3; float f;`, `f = k / j;`, `f = (float) k/j;`

Hoca slaytta `int j=2; k=3;` satırının hatalı yazıldığını belirtti; doğrusu `int j=2, k=3;` olmalıdır.

> **Ders sonrası not:** Hoca `f = k/j;` için derleyicinin "2 bölü 3'ü float olarak verdiğini" söyledi. Doğrusu şudur: `k/j` iki tamsayının bölmesidir ve `3/2 = 1` olarak hesaplanır, sonra `f = 1.0` olur. Kesirli sonuç `f = (float)k/j;` ile elde edilir ve `1.5` olur. Ajan bunu `gcc -Wall` ile derleyip çalıştırarak doğruladı. Implicit örnekte de `-3/4` önce tamsayı bölmesiyle `0` olur ve ifadenin sonucu `2.5` çıkar.

### 9.8 void, typedef ve sizeof

- **void:** Değer döndürmeyen bir tiptir. `void f(...)` geriye değer döndürmez. Ama algoritmanın bir çıktısı olması gerektiğine göre, böyle bir fonksiyon örneğin parametre olarak aldığı bir bellek adresinde değişiklik yaparak çıktı üretebilir. Bu, özellikle string işlemlerinde sık kullanılır. `void` ayrıca genel (generic) pointer tanımlamak için kullanılır.
- **typedef:** Bir tipe yeni isim atar. Örneğin `long int` yerine `int32` diye bir isim tanımlanırsa her seferinde uzun tip adı yazılmaz. Linkli listelerde ve ağaçlarda oluşturulacak dinamik yapılarda (`struct`) dönem boyunca sık kullanılacak; özellikle parametre aktarırken kodu kolaylaştırır.
- **sizeof:** Bir terimin kaç bayt kapladığını verir: `sizeof(3 + 5)`, `sizeof(int)`, `sizeof(short)` gibi. $n$ elemanlı bir dizi için dinamik yer ayrılırken `sizeof(int) * n` hesaplanır; böylece mimariden bağımsız kod yazılır.

### 9.9 ANSI C'de değişken tanımlama

Derste gösterilen bir slaytta ANSI C standardına uygun kodlama için şu örnek verildi (ekrandan, 00:20:00):

```c
for(int i=0;i<10;i++)..   // yanlış kodlama
int i; for(i=0; i<10; i++)..   // doğru kodlama
```

Hocanın açıklamasına göre ANSI C'de değişkenler bütün işlemlerden önce tanımlanmalıdır; döngü başlığında değişken tanımlamak bu standarda uygun değildir. Önce değişken tanımlanır, sonra döngü sayacı olarak kullanılır. Aynı slaytta, dosya yolunun mutlak yol yerine göreli yol (relative path) olarak verilmesi de örneklendi: `filePath="input.txt";`.

> **Ek bilgi (derste anlatılmadı):** Döngü başlığında değişken tanımlama C99 standardıyla gelmiştir. Ajan `gcc -std=c89 -pedantic` ile denedi: derleyici bu kullanım için "yalnız C99 ya da C11 kipinde izin verilir" hatası verdi.

## 10. C'de Operatörler ve İşlem Öncelikleri

### 10.1 Öncelik tablosu

Slayttaki tablo (ekrandan, 02:30:00), en yüksek öncelikten aşağı doğru:

| Operatör Sınıfı | Sınıftaki Operatörler | Birleşirlik |
|---|---|---|
| Öncül | `()` `[]` `->` `.` | Soldan sağa |
| Birli | cast operator, `sizeof`, `&` (address of), `*` (dereference), `-` `+`, `~` `++` `--` `!` | Sağdan sola |
| Çarpım | `*` `/` `%` | Soldan sağa |
| Toplama | `+` `-` | Soldan sağa |
| Kaydırma | `<<` `>>` | Soldan sağa |
| İlişkisel | `<` `<=` `>` `>=` | Soldan sağa |
| Eşitlik | `==` `!=` | Soldan sağa |

Aynı öncelikte birden fazla operatör varsa birleşirlik yönüne göre işlenir. Devam tablosunda, yine yüksek öncelikten düşüğe doğru, bit düzeyinde AND (`&`), XOR (`^`), OR (`|`), sonra mantıksal AND (`&&`) ve mantıksal OR (`||`), sonra koşullu ifade (`? :`), sonra atama operatörleri (`=`, `+=`, `-=` vb.) ve en son virgül operatörü gelir.

Hoca, tasarımın gerçeklemede beklendiği gibi çalışmadığı durumlarda bu öncelik sırasının göz önünde bulundurulması gerektiğini söyledi.

### 10.2 Kalan (modulo) operatörü

`%` yalnız tamsayı terimler kabul eder. Terimlerden biri negatifse kalan pozitif ya da negatif olabilir. ANSI standardına göre herhangi iki $a$ ve $b$ tamsayısı için kalan ve bölme arasında şu ilişki sağlanmalıdır:

$$a = (a \,\%\, b) + (a / b) \cdot b$$

> **Ek bilgi (derste anlatılmadı):** C99'dan itibaren tamsayı bölmesi sıfıra doğru keser. Bu yüzden kalanın işareti bölünenin işaretiyle aynıdır: `7 % -3 = 1`, `-7 % 3 = -1`. Ajan bu iki değeri `gcc` ile doğruladı.

### 10.3 Aritmetik atama operatörleri

Slayttaki örnek (ekrandan, 02:35:00): `int m = 3, n = 4;` ve `float x = 2.5, y = 1.0;`

| İfade | Parantezli karşılığı |
|---|---|
| `m += n + x - y` | `m = (m + ((n+x) - y))` |
| `m /= x * n + y` | `m = (m / ((x*n) + y))` |
| `n %= y + m` | `n = (n % (y + m))` |
| `x += y -= m` | `x = (x + (y = (y - m)))` |

Birinci satırda önce `n + x`, sonra `- y` yapılır; aritmetik bitince `+=` uygulanır ve `m = m + (...)` olur. İkinci satırda çarpmanın önceliği yüksek olduğu için önce `x * n`, sonra `+ y`, en son bölme ataması yapılır. Üçüncü satırda önce `y + m`, sonra `n` bu değere göre mod alınır. Dördüncü satırda atamalar sağdan sola birleşir: önce `y - m` hesaplanıp `y`'ye atanır, sonra bu değer `x` ile toplanıp `x`'e atanır. Hoca bu son ifadeyi "okunaklılığı çok zor, yazmamanız gereken kodlardan biri" diye nitelendirdi.

### 10.4 Artırma ve azaltma

Başlangıç değerleri `j = 0, m = 1, n = -1` olsun (derste sözlü, 02:35:39).

- `m++ - --j`: Önce `--j` yapılır, `j = -1` olur. Sonra `m - (-1) = 1 + 1 = 2` hesaplanır. İşlemden sonra `m++` uygulanır ve `m = 2` olur.
- `m += ++j * 2`: Önce `++j` yapılır, `j = 1` olur. `1 * 2 = 2`, `m = 1 + 2 = 3`.
- `m++ * m++`: Hoca bunun derleyiciye göre farklı sonuçlar verebileceğini, "çok tehlikeli" olduğunu söyledi.

> **Ders sonrası not:** Hoca `m++ * m++` için 2 ya da 3 gibi farklı sonuçlar olabileceğini söyledi. C standardına göre aynı değişkenin iki sıralama noktası arasında iki kez değiştirilmesi tanımsız davranıştır (undefined behavior). Yani sonuç hakkında hiçbir garanti yoktur ve bu ifade hiç yazılmamalıdır.

> **Hocanın vurgusu:** Burada C'yi "uçurmaya", her şeyi tek satırda yapmaya çalışmıyoruz. Amaç algoritmik tasarıma uygun bir akışı anlaşılır şekilde kodlamaktır.

### 10.5 Virgül operatörü

Virgül, tek bir ifadeye izin verilen yerde birden fazla ifadenin yazılmasını sağlar. Özellikle döngülerde kullanılır. Derste verilen örnekte `j = 0, k = 100` iki ilk değer ataması yapılıyor, bitiş şartı `k - j > 0`, her adımda `j` bir artırılıyor ve `k` bir azaltılıyordu. Virgüllü ifadenin değeri en sağdaki terimin değeridir.

### 10.6 İlişkisel operatörler

Slayttaki örnek (ekrandan, 02:40:00): `int j=0, m=1, n=-1;` ve `float x=2.5, y=0.0;`

| İfade | Parantezli karşılığı | Sonuç |
|---|---|---|
| `j > m` | `j > m` | 0 |
| `m/n < x` | `(m / n) < x` | 1 |
| `j <= m >= n` | `((j <= m) >= n)` | 1 |
| `++j == m != y * 2` | `((++j) == m) != (y * 2)` | 1 |

Çözümler hocanın anlatımına göre:

- `j > m`: $0 > 1$ yanlıştır, sonuç 0.
- `m/n < x`: `m/n = 1/(-1) = -1`; $-1 < 2.5$ doğrudur, sonuç 1.
- `j <= m >= n`: İki operatör aynı öncelikte olduğu için soldan sağa işlenir. `j <= m` yani $0 \leq 1$ doğrudur ve 1 verir. Sonra $1 \geq -1$ doğrudur, sonuç 1.
- `++j == m != y * 2`: Önce `++j` ile `j = 1`. `1 == m` doğrudur ve 1 verir. `y * 2 = 0.0`. `1 != 0` doğrudur, sonuç 1.

Ajan bu dört sonucu `gcc` ile doğruladı.

### 10.7 Mantıksal operatörler

Aynı değişkenlerle (derste sözlü, 02:41:06):

- `j && m`: $0$ ile $1$'in mantıksal VE'si $0$'dır.
- `j < m && n < m`: $0 < 1$ doğrudur (1), $-1 < 1$ doğrudur (1); $1 \,\&\&\, 1 = 1$.

Hoca daha karmaşık örneklerde önce `x * 5` gibi aritmetik işlemlerin, sonra karşılaştırmaların, en son `&&` ve `||` işlemlerinin yapıldığını anlattı. Değil (`!`) operatörü tekli olduğu için önce uygulanır.

<!-- BELİRSİZ: 02:41:18-02:42:17 arasındaki karmaşık mantıksal ifadelerin tam metni karelerde görülmedi ve altyazıda bozuk ("NAT x 0, ondan sonra NAT n 0, 0, 0..."); bu yüzden aktarılmadı. -->

### 10.8 Bit kaydırma operatörleri

Derste sözlü olarak anlatılan örnekler (02:42:33):

- `5 << 1`: $5$'in ikili gösterimi `101`'dir. Bir sola kaydırınca sağa bir sıfır eklenir: `1010` $= 10$. Yani $5$, $2$ ile çarpılmış olur.
- `255 >> 3`: `11111111` üç sağa kaydırılınca sağdaki üç bir kaybolur: `11111` $= 31$.
- `8 << 10`: $8 = 2^3$; on basamak sola kayınca $2^{13} = 8192$ olur.

Ajan bu üç sonucu python ile doğruladı.

Hoca negatif sayılarda da kaydırma yapılabileceğini, `-5`'in iki sağa kaydırılmasını örnek verdi.

<!-- BELİRSİZ: 02:43:10 civarında -5'in sağa kaydırılması örneğinin sonucu altyazıda "2 üzeri 13 eksi 1" olarak geçiyor; slayttaki bit genişliği ve sonuç karelerde görülmedi. -->

> **Ders sonrası not:** C standardında negatif bir sayının sağa kaydırılması derleyiciye bağlıdır (implementation-defined). Yaygın derleyicilerde aritmetik kaydırma yapılır ve `-5 >> 2` sonucu `-2` olur (ajan `gcc` ile denedi). Hocanın söylediği sonuç büyük olasılıkla belirli bir bit genişliğinde işaretsiz yorumla hesaplanmıştır.

### 10.9 Koşul operatörü

C'nin üç terimli tek operatörü `? :`'dır. `if-else` için kısa yazım sağlar:

```c
z = (x < y) ? x : y;
```

Bu, "koşul doğruysa `z = x`, yanlışsa `z = y`" anlamına gelir. Kodlarken kullanılabilir, ama akış diyagramında normal bir `if` olarak gösterilmelidir.

### 10.10 Bellek operatörleri

Slayttaki tablo (ekrandan, 02:45:00):

| Operatör | Sembol | Örnek | İşlem |
|---|---|---|---|
| Adresi | `&` | `&x` | x'in adresini al |
| Dereference | `*` | `*a` | a adresindeki varlığın değerini al |
| Dizi elemanı | `[]` | `x[5]` | Dizinin 5 elemanının değerini al |
| Nokta | `.` | `x.y` | X struct'ındaki y elemanının değerini al |
| Sağ-Ok | `->` | `p -> y` | p ile gösterilen adresteki struct'ın y elemanının değerini al |

Dereference, string'lerde ve pointer aritmetiğiyle gezilen bütün liste yapılarında çok kullanılacak. `x[5]` indisi 5 olan elemanı verir; indislerin sıfırdan başladığı unutulmamalıdır. `->` operatörü de dönem boyunca sık kullanılacak.

> **Ders sonrası not:** Hoca nokta ve ok operatörlerini anlatırken "stack" dedi. Slaytta da yazdığı gibi doğrusu `struct`'tır. Ayrıca `&x` ifadesi `x`'in adresini verir; o adresteki değeri okumak için `*` gerekir.

## 11. C'de Kontrol Yapıları

### 11.1 if ve sarkan else

`if` iki biçimdedir: yalnız doğru kolu olan ve hem doğru hem yanlış kolu olan. Şart doğruysa doğru kolu, yanlışsa yanlış kolu işletilir; akış diyagramlarındakiyle birebir aynıdır.

İç içe `if`lerde **sarkan else** (dangling else) sorunu oluşabilir: `else`in hangi `if`e ait olduğu belirsizleşir. Kural şudur: Bir `else` her zaman ona en yakın öncül `if` ile ilişkilendirilir.

Derste verilen örnek:

```c
if (a < b)
    if (a < c)
        return a;
    else
        return c;
else
    if (b < c)
        return b;
    else
        return c;
```

Buradaki ilk `else`, en yakın `if` olan `if (a < c)`'ye aittir. Yazan kişi girintiyle başka bir eşleşme kastetse bile derleyici en yakın `if`e bağlar ve doğru `return`'ler yakalanamayabilir. Bu yüzden iç içe `if`ler süslü parantezlerle düzgün gruplanmalıdır.

<!-- BELİRSİZ: 02:46:28-02:47:17 arasındaki sarkan else örneğinin slayttaki tam hâli karelerde görülmedi; kod hocanın sözlü anlatımından kuruldu. -->

### 11.2 switch

`switch` çoklu karşılaştırma yapar. Dikkat edilecekler:

- `break`'ler düzgün kullanılmalıdır; yoksa eşleşen durumdan sonra aşağıdaki bütün durumlar da çalışır.
- Aynı durum etiketi iki ayrı durumda kullanılamaz.
- Hiçbir durumla eşleşmeyen değerler için `default` yazılması beklenir. `default` sonda olmak zorunda değildir, ama sona konmadığında (ve `break` yoksa) hem bir durum hem `default` çalışabilir. Bu yüzden `default`'u en sona koymak iyi bir uygulamadır.

### 11.3 while ve do-while

`while` döngüsünde koşulun döngü içinde bir şekilde bozulması garanti edilmelidir. `do-while`'da ise önce blok bir kez işletilir, sonra şart kontrol edilir; şart doğruysa blok tekrar işletilir. Böylece koşul sonda kontrol edilerek bloğun en az bir kez çalışması garanti edilir.

### 11.4 for

Slayttaki şekil ve maddeler (ekrandan, 02:50:00): `for ( expression1 ; expression2 ; expression3 ) statement`.

- expression1 önce işletilir.
- Sonra expression2 işletilir.
  - İfadenin koşullu kısmıdır.
  - expression2 yanlış ise program `for` bloğunun dışına çıkar.
  - expression2 doğru ise statement işletilir.
- statement işletildikten sonra expression3 işletilir.
- Döngü bloğu expression2 testine geri döner.

expression1 ilk değer atamaları, expression2 bitiş koşulu, expression3 her adımda yapılacak artımlardır. Artımlar düzgün yapılmazsa sonsuz döngüye girilir.

### 11.5 break, continue ve goto

- **break:** `switch`'te her durumdan sonra kullanılır. Döngü içinde kullanılırsa döngüyü kırar ve program döngüden sonraki satırdan devam eder. Çok sevilen bir çıkış yöntemi değildir.
- **continue:** O iterasyonun geri kalanını atlayıp döngünün başına döner. Bu da sevilen bir akış tarzı değildir; tasarımda eksiklik olduğunu gösterir ve daha iyi bir tasarımla ifade edilebilir.
- **goto:** Fortran ya da Basic gibi eski dillerde zorunluydu. Hocanın ifadesiyle C'de `goto` kullanılıyorsa "diyecek bir şey yok".

> **Hocanın vurgusu:** Operatörler, öncelikler, pointer aritmetiği ve dinamik bellek ayırma konularında eksik varsa şimdiden çalışılmalıdır. Aksi hâlde hem dersin içeriğini anlamada hem verilen görevleri yerine getirmede zorlanılabilir.

## Örnek Sorular

**Soru 1** (ekrandan, 02:40:00): `int j=0, m=1, n=-1; float x=2.5, y=0.0;` için aşağıdaki ifadelerin değerlerini bulun: `j > m`, `m/n < x`, `j <= m >= n`, `++j == m != y * 2`.

> **Çözüm (derste verildi):** Sırasıyla 0, 1, 1, 1. `m/n` tamsayı bölmesiyle $-1$ olur ve $-1 < 2.5$ doğrudur. `j <= m >= n` soldan sağa işlenir: $(0 \leq 1) = 1$, $1 \geq -1$ doğru. Son ifadede `++j` ile `j = 1`, `1 == 1` doğru (1), `y * 2 = 0.0`, `1 != 0` doğru (1).

**Soru 2** (ekrandan, 02:35:00): `int m = 3, n = 4; float x = 2.5, y = 1.0;` için `m += n + x - y`, `m /= x * n + y`, `n %= y + m` ve `x += y -= m` ifadelerini işlem önceliğine göre parantezleyin.

> **Çözüm (derste verildi):** `m = (m + ((n+x) - y))`, `m = (m / ((x*n) + y))`, `n = (n % (y + m))`, `x = (x + (y = (y - m)))`.

> **Ders sonrası not:** Slayttaki `n %= y + m` ifadesinde `y` bir `float` olduğu için `y + m` de `float` olur. `%` yalnız tamsayı terim kabul ettiğinden bu satır C'de derleme hatası verir. Ajan bunu `gcc` ile denedi: derleyici `invalid operands to binary %` hatası verdi.

**Soru 3** (derste sözlü, 02:35:39): `j = 0, m = 1, n = -1` iken `m++ - --j` ve (aynı başlangıç değerleriyle) `m += ++j * 2` ifadelerinin sonucu nedir?

> **Çözüm (derste verildi):** `--j` ile `j = -1`; `1 - (-1) = 2`; işlemden sonra `m = 2`. İkinci ifadede `++j` ile `j = 1`; `1 * 2 = 2`; `m = 1 + 2 = 3`.

**Soru 4** (ekrandan, 02:25:00): `int j=2, k=3; float f;` için `f = k / j;` ve `f = (float) k/j;` sonrasında `f` kaç olur? `-3 / 4 + 2.5` ifadesinin değeri nedir?

> **Çözüm (derste verilmedi):** `f = k / j;` sonrasında `f = 1.0` (tamsayı bölmesi `3/2 = 1`). `f = (float) k/j;` sonrasında `f = 1.5`. `-3 / 4 + 2.5` ifadesinde `-3/4` tamsayı bölmesiyle `0` olur, sonuç `2.5`. Ajan `gcc -Wall` ile derleyip çalıştırarak doğruladı.

**Soru 5** (ekrandan, 02:15:00): Aşağıdakilerden hangileri geçerli C isimleridir? `j`, `j5`, `__system_name`, `sesquipedalial_name`, `UpPeR_aNd_LoWeR_cAsE_nAmE`, `5j`, `$name`, `int`, `bad%#*@name`

> **Çözüm (derste verildi):** İlk beşi geçerlidir. `5j` rakamla başladığı, `$name` `$` içerdiği, `int` ayrılmış kelime olduğu, `bad%#*@name` izin verilmeyen karakterler içerdiği için geçersizdir.

**Soru 6** (derste sözlü, 02:42:33): `5 << 1`, `255 >> 3` ve `8 << 10` ifadelerinin değerleri nedir?

> **Çözüm (derste verildi):** `10`, `31` ve $2^{13} = 8192$. Ajan python ile doğruladı.

## Dersin Toparlaması

Bu derste algoritmanın kökeni ve tanımı, bir yöntemin algoritma sayılması için gereken özellikler (kesinlik, sonluluk, doğruluk, girdi, çıktı, yapılabilirlik ve dilden bağımsızlık) ele alındı. Verinin bilgisayarda nasıl tutulduğu ve aynı bitlerin farklı gösterimleri hatırlatıldı. Veri yapısının, verinin bellekte tutulma şekli ve düzeni olduğu, doğru seçildiğinde zaman ya da bellek kazandırdığı seyrek matris örneğiyle gösterildi. Algoritma hazırlama süreci (tasarım, doğrulama, analiz, gerçekleme, test) ve algoritmayı ifade etmenin iki yolu, sözde kod ve akış diyagramı, ayrıntılı kurallarıyla anlatıldı. Akış diyagramında okuma sırası, T/F etiketleri, dilden bağımsız işlemler ve döngülerde sonsuz döngüden kaçınma özellikle vurgulandı.

Son bölümde dönem boyunca kullanılacak C bilgileri hatırlatıldı: isimlendirme, önişlemci, veri tipleri ve boyutları, tip dönüşümleri, `typedef` ve `sizeof`, operatör öncelikleri, artırma ve azaltma tuzakları, bellek operatörleri ve kontrol yapıları. Bir sonraki teorik derste algoritmik problem çözmenin temellerine örneklerle devam edileceği, algoritmanın nasıl tasarlanması ve nasıl gözden geçirilmesi gerektiğinin işleneceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
