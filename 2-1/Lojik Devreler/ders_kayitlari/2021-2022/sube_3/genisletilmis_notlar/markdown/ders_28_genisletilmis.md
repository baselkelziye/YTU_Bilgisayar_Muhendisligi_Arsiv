# Ders 28 Genişletilmiş Notu: Saklayıcılar, Sayıcılar ve Bellek Birimleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin amacı: lojik devrelerden mikroişlemcilere geçiş
- 2. Saklayıcılar (register)
- 3. Saklayıcı üzerindeki işlemler: set, reset, öteleme ve döndürme
- 4. Öteleme ile bölme ve çarpma
- 5. Sayıcılar ve sınıflandırılması
- 6. Ardışık bağlı (kaskat) aşağı sayıcılar
- 7. Özel durum sayıcıları: BCD, Gray, modülo 12, 3 fazlalık
- 8. İkili sayıcı ile BCD sayıcının karşılaştırılması
- 9. Hafıza birimleri ve adresleme
- 10. Kod çözücü ile hafıza satırı seçimi
- 11. Veri yolu ve adres yolu
- 12. Statik ve dinamik RAM, ROM türleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin amacı: lojik devrelerden mikroişlemcilere geçiş

Bu ders dönemin son konusunu işler: saklayıcılar, sayıcılar ve bellek (hafıza) elemanları (ekrandan, 00:15:00). Hoca konuyu hazır slayt yerine Zoom beyaz tahtasında çizerek anlatır.

Konunun amacı bir sonraki dönemlerde alınacak mikroişlemci dersine hazırlıktır. O derste flip-flopun nasıl çalıştığı ya da bir bitin nasıl tutulduğu yeniden anlatılmaz. Flip-flopların bir araya gelerek oluşturduğu saklayıcılar, blok hafıza hücreleri ve bellek yapıları doğrudan kullanılır. Bu ders, lojik devrelerden mikroişlemci birimlerine geçişin nasıl olduğunu gösteren bağlantı olarak düşünülür.

> **Hocanın vurgusu:** Bu haftanın konusunda ayrıntılı devre diyagramlarından çok temel kavramlar ve tanımlar önemlidir.

## 2. Saklayıcılar (register)

### 2.1 Saklayıcının tanımı

Şimdiye kadar durum diyagramlarında "durumu tutan" yapı olarak kullanılan elemanlar flip-floplardı. $n$ bitlik bir saklayıcı, $n$ tane flip-flopun yan yana getirilip birleştirilmesiyle oluşan yapıdır (ekrandan, 00:15:00).

Saklayıcıların dört temel türü vardır (ekrandan, 00:20:00):

- PIPO: paralel giriş, paralel çıkış (parallel in, parallel out)
- SIPO: seri giriş, paralel çıkış
- PISO: paralel giriş, seri çıkış
- SISO: seri giriş, seri çıkış

Seri giriş/çıkış, akan bir bit dizisinin (bit stream) sırayla işlenip çıkışa aktarılması demektir. Paralel yapıda ise bütün bitler aynı anda, MSB'den LSB'ye kadar ayrı hatlardan taşınır.

### 2.2 4 bitlik PIPO saklayıcı

Tahtada 4 bitlik, paralel giriş-paralel çıkışlı bir saklayıcı çizilir (ekrandan, 00:20:00). Dört flip-flopun ortak bir saat girişi (CLK) vardır. Girişler $G_3, G_2, G_1, G_0$, çıkışlar $\text{Ç}_3, \text{Ç}_2, \text{Ç}_1, \text{Ç}_0$ diye adlandırılır.

Amaç, girişlerdeki 4 bitlik değeri tek bir saat darbesiyle flip-floplara aktarmaktır. Örneğin $G_3G_2G_1G_0 = 1001$ verilip bir saat darbesi beklendiğinde değer $\text{Ç}_3\text{Ç}_2\text{Ç}_1\text{Ç}_0$'a geçer (ekrandan, 00:20:00). Bir sonraki saat darbesine kadar güncelleme olmadığı, yani girişteki değişim çıkışa yansımadığı için 4 bitlik veri saklanmış olur.

**Soru:** Bu saklama işlemi için ne tip bir flip-flop kullanılmalıdır? **Cevap:** D (data) tipi flip-flop. Amaç veriyi olduğu gibi tutmak olduğu için D flip-flop ile 4 bitlik veri bir sonraki saat darbesine kadar çıkışta tutulur.

Tahtadaki çizimde flip-flopların ayrıca "sıfırla" ve "set" hatları da gösterilmiştir. Hoca kitaptaki bazı saklayıcılarda D flip-floplara bu pinlerin bağlandığını belirtir.

### 2.3 Seri girişli yapılar: SISO ve SIPO

Seri girişli yapıda flip-floplar zincir halinde bağlanır: seri giriş ilk flip-flopun D girişine gider, her flip-flopun çıkışı bir sonrakinin girişine bağlanır. Hepsinin saati ortaktır. Tahtada soldaki flip-flop MSB, sağdaki LSB olarak işaretlenmiş, son flip-flopun çıkışı "seri out" diye adlandırılmıştır (ekrandan, 00:25:00).

Seri girişten bir bit gönderildiğinde bu bit her saat darbesinde bir sonraki flip-floba geçer. 4 bitlik bir paket ancak dört saat darbesinden sonra flip-flopların hepsine yerleşir.

- Ara flip-flopların çıkışlarından da ($\text{Ç}_3, \text{Ç}_2, \text{Ç}_1, \text{Ç}_0$) hat alınırsa seri gelen bit dizisi paralel olarak okunabilir; bu SIPO yapısıdır.
- Ara çıkışlar alınmaz, yalnız son flip-floptan okunursa yapı SISO olur. Bu durumda bitler karşı tarafta sırayla okunarak bit dizisi yeniden oluşturulur.

**Soru:** SISO yapısında ara flip-floplardan da çıkış alınabilir mi? **Cevap:** Hayır. Tahtada SIPO ve SISO birlikte gösterilmiştir. Ara çıkışlar yoksa yapı SISO'dur ve flip-floplar veriyi içeride saklasa da yalnız seri çıkıştan sırayla alınır. Her flip-floptan çıkış çekilirse yapı SIPO olur; ikisi farklı yapılardır.

**Soru:** Seri çıkışta bitleri sırayla mı görürüz? **Cevap:** Paket tamamlanana kadar geçen saat darbelerinde okunan değer anlamsızdır; paket ancak dördüncü darbeden sonra anlamlı hale gelir. Karşı tarafta bitler tek tek yazılarak 4 bitlik değer yeniden oluşturulur. <!-- BELİRSİZ: Hocanın ilk görünen bitin LSB olduğuna ve kaç çevrim beklendiğine dair anlatımı (3 ya da 4 çevrim) altyazıda karışık. -->

**Soru:** Bu dört flip-flop bir saklayıcının yapısını mı gösteriyor? **Cevap:** Evet. 4 bitlik bir saklayıcı içinde dört flip-flop bulunan yapıdır.

Tek bir flip-flopla da seri giriş/seri çıkış yapılabilir, ama o zaman öteleme yapılamaz. 4 bitlik bir paket içinde öteleme yapmak için dört flip-flop gerekir.

### 2.4 Mikroişlemci saklayıcısı örneği: 8086

8086'ya "16 bitlik mikroişlemci" denmesinin nedeni AX, BX, CX, DX diye adlandırılan saklayıcılarının 16 bitlik olmasıdır. Yani her saklayıcı 16 ikili basamağı yan yana anlamlı bir veri olarak tutabilir ve bunu içindeki 16 flip-flop sağlar. Tahtada 0'dan 15'e kadar numaralanmış bir AX saklayıcısı çizilmiştir (ekrandan, 00:30:00).

Girişler ve çıkışlar şu anlama gelir: saklayıcıya veri yazmak, girişlere değeri verip saat darbesini beklemek; okumak ise çıkışlardaki değeri almaktır. Mikroişlemcide saklayıcı bir saate değil, işlemcinin gönderdiği okuma (read) ve yazma (write) sinyallerine bağlıdır. Yazmada $G$'ler yeni yazılacak veriyi, okumada $\text{Ç}$'ler saklanan veriyi temsil eder.

### 2.5 Seri ve paralel aktarımın karşılaştırılması

Saklayıcılarda geçerli olan karşılaştırma iletişimde de geçerlidir:

- Paralel aktarım daha kısa sürede daha çok veri okumayı ve yazmayı sağlar, ama gürültüden etkilenme oranı yüksektir ve mimarisi daha maliyetlidir.
- Seri aktarımla daha uzak mesafelere veri gönderilebilir, gürültüden daha az etkilenir ve mimari ucuzdur; ama yavaştır, çünkü paket tamamlanana kadar beklenir.

Bu yüzden mikroişlemciler saklayıcılarında SIPO ya da SISO değil, genelde PIPO kullanır. Öteleme işlemleri için SIPO ve SISO yapıları kullanılır.

### 2.6 Evrensel saklayıcı

SISO, SIPO, PIPO ve PISO yapılarının hepsini içinde barındıran saklayıcılara evrensel (universal) saklayıcı denir. Hocaya göre çok kullanılmaz; adını bilmek yeterlidir.

> **Hocanın vurgusu:** Önemli olan, saklayıcıların flip-flop yapısında olduğunu, mikroişlemcide çoğunlukla paralel giriş-paralel çıkış biçiminde kullanıldığını ve saklayıcı kaç bitlikse içinde o kadar flip-flop bulunduğunu bilmektir. 8 bitlik saklayıcıda 8 flip-flop vardır, çünkü bir flip-flop tek bir biti (0 ya da 1) saklar.

## 3. Saklayıcı üzerindeki işlemler: set, reset, öteleme ve döndürme

Saklayıcıların içinde bir işlem birimi yoktur; aritmetik toplama ya da lojik işlemler saklayıcıda yapılmaz, bunlar CPU içindeki ALU'nun işidir. Saklayıcının kendi yapısıyla yapabildiği üç iş vardır (ekrandan, 00:25:00):

- Set (setleme): set pinine 1 verildiğinde, mikroişlemci verinin ne olduğuna bakmadan bütün çıkışlar 1 olur.
- Reset (resetleme, sıfırlama): bütün çıkışlar 0 olur.
- Öteleme ya da döndürme: ikisi farklı işlemlerdir, saklayıcının mimarisine göre biri yapılabilir.

Set ve reset, paralel de seri de olsa ayrı bir pinden 1 ya da 0 verilerek flip-flopların yapısından ötürü yapılır; CPU ile ilgisi yoktur. Öteleme ve döndürme ise seri girişli (SISO ve SIPO) yapılarla yapılır.

Seri girişli yapıda öteleme şöyle olur: sağa ötelemede dışarı çıkan bitin kaybolması isteniyorsa seri girişten bir 0 daha gönderilir. Seri girişten giren veri içerideki bitleri bir adım iterek götürdüğü için öteleme gerçekleşir.

**Soru:** İlk verilen $0001$ değerinden $0010$'u elde etmek için ne yapmak gerekir? **Cevap:** Hoca, bunun 3 kez sağa kaydırmayla elde edilip edilemeyeceğini sorar ve bir öğrenci onaylar (ekrandan, 00:30:00).

> **Ders sonrası not:** 4 bitlik bir sözcükte 3 kez sağa döndürme, 1 kez sola döndürmeyle aynı sonucu verir: $0001 \to 1000 \to 0100 \to 0010$. Ötelemede ise (boşalan uca 0 girdiği için) 3 kez sağa öteleme $0001$'i $0000$ yapar; $0010$ için 1 bit sola öteleme gerekir. Hoca burada büyük olasılıkla döndürmeyi kastetmiştir.

> **Hocanın vurgusu:** Öteleme ve döndürme aritmetik ya da lojik işlem değildir; bit düzeyinde işlemlerdir ve flip-flopların birleşiminden oluşan saklayıcıların kendi içinde yapılır.

## 4. Öteleme ile bölme ve çarpma

### 4.1 Sağa öteleme

Tahtadaki örnek (ekrandan, 00:35:00):

| İkili | Ondalık | İşlem |
|---|---|---|
| $0100$ | 4 | başlangıç |
| $0010$ | 2 | 1 bit sağa öteleme |
| $0001$ | 1 | 1 bit daha sağa öteleme |

Bir bit sağa öteleme sayıyı 2'ye bölmektir. İki bit ötelemeyi daha net görmek için $1000 = 8$ alınır: iki bit sağa ötelenince $0010 = 2$ olur, yani sayı 4'e bölünür. Genel kural (ekrandan, 00:40:00):

$$n \text{ bit sağa öteleme} \;\Longleftrightarrow\; 2^n \text{'e bölme}$$

Burada $n$ öteleme miktarıdır: 2 bit ötelemek 4'e, 3 bit ötelemek 8'e bölmektir.

### 4.2 Tek sayıda sağa öteleme: 197 örneği

8 bitlik $1100\,0101$ sayısı ele alınır (ekrandan, 00:40:00). Ondalık karşılığı:

$$1100\,0101_2 = 128 + 64 + 4 + 1 = 197$$

Derste önce yanlışlıkla 201 hesaplanmış, bir öğrencinin düzeltmesiyle 197 bulunmuştur.

Ötelemenin tanımı: kaydırıldığında soldan ya da sağdan giren yeni değer 0'dır ve öbür uçtan çıkan bit kaybolur. Bir bit sağa öteleme:

$$1100\,0101 \;\to\; 0110\,0010 = 64 + 32 + 2 = 98$$

$197 / 2 = 98{,}5$'tir; ötelemede en sağdaki 1 düştüğü için sonuç tam kısım olan 98'dir. Yani tam sayı düzeyinde $196/2$ bulunmuş olur; ondalıklı sonuç elde edilemez.

Mikroişlemci 2'ye, 4'e bölmeyi kısa yoldan bu yöntemle yapar. İşlem ALU'ya gitmeden saklayıcının kendi yapısıyla yapıldığı için çok daha hızlıdır.

### 4.3 Döndürme

Aynı sayı bir bit sağa döndürülünce sağdan çıkan bit kaybolmaz, en sola gelir (ekrandan, 00:40:00):

$$1100\,0101 \;\to\; 1110\,0010$$

Sonuç sayının yarısıyla hiçbir ilgisi olmayan bir değerdir.

> **Ders sonrası not:** Hoca tahtada $128 + 64 + 32 + 2 = 230$ yazdı; doğrusu $226$'dır (python ile kontrol edildi).

Öteleme ile döndürme arasındaki fark şudur: döndürmede veri kaybolmadan başa getirilir; ötelemede ise (sağa) bölme yapılmış olur. Sola döndürmede bit soldan çıkıp sağdan girer.

### 4.4 Sola öteleme

Sola öteleme bölmenin tersini, yani çarpmayı yapar (ekrandan, 00:40:00):

$$0001 = 1 \;\xrightarrow{\;2 \text{ bit sola}\;}\; 0100 = 4 \;\xrightarrow{\;2 \text{ bit sola}\;}\; 1\,0000 = 16$$

Son adımda dışarı taşan bitin bir yerde tutulduğu düşünülür. İki bit sola öteleme $2^2 = 4$ ile çarpmaktır.

> **Hocanın vurgusu:** Sağa ve sola öteleme saklayıcının kendi iç yapısında yapılabildiği için çok hızlı işlem yapılmasına olanak verir.

## 5. Sayıcılar ve sınıflandırılması

Sayıcılar, bir sayısal değerden sıfıra doğru ya da sıfırdan hedef değere doğru sayan devreler (entegreler) olarak tanımlanır. Saymayı saat darbesine ya da dışarıdan gelen bir tetikleme sinyaline bağlı olarak yaparlar. Sayıcılar şu ölçütlere göre sınıflandırılır (ekrandan, 00:45:00):

- **Bit sayısına göre:** 4 bitlik sayıcı $0000$'dan $1111$'e, 8 bitlik sayıcı 0'dan 255'e kadar sayar.
- **Sayma sırasına göre:** yukarı sayan ve aşağı sayan. 8 bitlik yukarı sayıcı 0'dan 255'e sayar ve sonra sıfırlanarak başa döner; aşağı sayıcı 255'ten geriye doğru sayar.
- **Çalışma moduna göre:** hem yukarı hem aşağı sayabilen iki modlu sayıcılar ve yalnız birini yapan tek modlu sayıcılar.
- **Durum sayısına göre:** genelde modülo sayıcılar. Örneğin mod 3 sayıcı 0, 1, 2 sayar ve sonra 0'a döner.
- **Geçiş fonksiyonuna göre:** senkron ve asenkron sayıcılar.

**Soru:** 8 bitlik sayıcı 0 ile kaç arasında sayar? **Cevap:** 255.

Tahtadaki sayıcı bloğunun girişleri, yüklenen $n$ bitlik başlangıç değeri ve CLK'dir. Çıkışları ise o anki değeri veren $n$ bitlik çıkış ve "sayma tamam" sinyalidir (ekrandan, 00:45:00). Örneğin $0000$ yüklenmiş bir yukarı sayıcı bir saat darbesi sonra $0001$ olur; sayma henüz bitmediği için "sayma tamam" çıkışından sinyal gelmez, ama anlık değer her an okunabilir.

> **Hocanın vurgusu:** Sayıcılarda en kritik parametre bit sayısıdır, çünkü sayıcının kapasitesini belirler. 4 bitlik ve 8 bitlik sayıcının alabileceği en büyük değeri bilmek gerekir.

## 6. Ardışık bağlı (kaskat) aşağı sayıcılar

Mikroişlemcilerde genelde aşağı sayıcılar kullanılır. Örneğin 1000 yüklenir, her saat darbesinde 999, 998, 997 diye geriye sayılır. Sayım sıfıra gelince "sayma tamam" çıkışından 1 gelir ve mikroişlemciyi "sayma bitti" diye tetikler.

"Sayma tamam" çıkışı başka bir sayıcıyı sürmek için de kullanılır. Tahtadaki örnekte iki tane 4 bitlik aşağı sayıcı vardır (ekrandan, 00:50:00):

- Üstteki sayıcının saat girişine CLK bağlıdır ve sayıcıya $1111$ yüklenir.
- Üstteki sayıcının "sayma tamam" çıkışı alttaki sayıcının saat girişine bağlanır.
- Alttaki sayıcıya $1000$ yüklenir.

**Soru:** 4 bitlik bir sayıcının sayabileceği en büyük değer nedir? **Cevap:** 0 ile 15 arasında sayar; aşağı sayıcıya en çok 15 ($1111$) yüklenebilir.

Çalışma adım adım şöyledir:

1. Üstteki sayıcı her saat darbesinde bir azalır: $1111, 1110, 1101, 1100, 1011, 1010, \dots, 0000$.
2. Üstteki sayıcı sıfıra gelince "sayma tamam" alttaki sayıcının saatini bir kez tetikler; alttaki sayıcı $1000$'dan $0111$'e düşer.
3. Üstteki sayıcı her 16 adımda bir alttaki sayıcıyı tetikler: $1000 \to 0111 \to 0110 \to 0101 \to 0100 \to \dots$
4. Alttaki sayıcının "sayma tamam" çıkışı $16 \times 8 = 128$ sayım sonunda 1 olur.

128 sayımı 4 bitlik tek bir entegreyle yapmak mümkün değildir. Kaskat bağlama, bir sayıcının kapasitesinin yetmediği yerde yeni bir sayıcıyı öncekiyle ilişkili biçimde kullanmayı sağlar.

Modülo sayıcıda yüklenebilecek değer sınırlıdır. Mod 7 sayıcı 0-6 arasında sayar; bu yüzden ona $1111$ yüklenemez, en çok $0110 = 6$ yüklenip 5, 4, ... diye aşağı sayılır.

**Soru:** Bu yapı koddaki iç içe döngüler gibi mi çalışıyor? **Cevap:** Mantığı kodlamadaki döngüye benzer, ama bu donanımsal bir işlemdir. Mikroişlemcide döngü sayacı olarak CX (counting register) saklayıcısına bir değer atanır ve CX sıfıra inene kadar döngü döner; böyle bir yapı kurulmuşsa sayıcılarla yapılır. Yalnız yazılım tarafında olan bir döngü ise başka bir şeydir. Öğrenci assembly'yi kastettiğini belirtince hoca bunun yapıya bağlı olduğunu, kesin bir şey söyleyemeyeceğini belirtir.

## 7. Özel durum sayıcıları: BCD, Gray, modülo 12, 3 fazlalık

Özel durumlar için üretilmiş sayıcılar vardır: BCD sayıcı, Gray kodu sayıcı, modülo sayıcılar ve 3 fazlalık sayıcı. Hoca bunları tahtada bir tabloyla karşılaştırır (ekrandan, 01:00:00):

| Ondalık | İkili | BCD | Gray | Modülo 12 |
|---|---|---|---|---|
| 0 | 0000 | 0000 | 0000 | 0000 |
| 1 | 0001 | 0001 | 0001 | 0001 |
| 2 | 0010 | 0010 | 0011 | 0010 |
| 3 | 0011 | 0011 | 0010 | 0011 |
| 4 | 0100 | 0100 | 0110 | 0100 |
| 5 | 0101 | 0101 | 0111 | 0101 |
| 6 | 0110 | 0110 | 0101 | 0110 |
| 7 | 0111 | 0111 | 0100 | 0111 |
| 8 | 1000 | 1000 | ... | 1000 |
| 9 | 1001 | 1001 | ... | 1001 |
| 10 | 1010 | — | ... | 1010 |
| 11 | 1011 | — | ... | 1011 |
| 12 | 1100 | — | ... | — |
| 13 | 1101 | — | ... | — |
| 14 | 1110 | — | ... | — |
| 15 | 1111 | — | ... | — |

Tabloda Gray sütunu tahtada 7'ye kadar yazılmış, sonrası noktalarla geçilmiştir. Modülo 12 sütununda da tahtada yalnız 11'e karşılık gelen $1011$ yazılmış, üstü "aynı" diye boş bırakılmıştır. İkili sütunun son satırları tahtada kaymış görünür; tabloda doğru değerler verilmiştir.

### 7.1 İkili (binary) sayıcı

Normal ikili sayıcı 4 bitle $0000$'dan $1111$'e kadar sayar.

### 7.2 BCD sayıcı

BCD sayıcı 0'dan 9'a kadar sayar. 9'dan ($1001$) sonra sayma yapmaz, tetiklendiyse başa dönüp saymaya devam eder.

### 7.3 Gray kodu sayıcı

Gray kodu sayıcıda ardışık iki değer arasındaki Hamming uzaklığı 1'dir; yani her adımda yalnız bir bit değişir. Örneğin BCD'de $0001$'den $0010$'a geçerken iki bit değişir (biri $0 \to 1$, öteki $1 \to 0$); Gray kodunda bu olmaz. Sıra $0000, 0001, 0011, 0010, 0110, 0111, 0101, 0100, \dots$ diye gider (ekrandan, 01:00:00).

### 7.4 Modülo 12 sayıcı

Modülo 12 sayıcı 0'dan 11'e kadar sayar, sonra 0 alıp yeniden başlar. 12 ve sonrası ($1100$ ve üstü) bu sayıcıda yoktur.

### 7.5 3 fazlalık sayıcı

Bir öğrencinin önerisiyle 3 fazlalık sayıcı da bu gruba eklenir. Hoca bunu, 0 yerine 3 fazlasından, yani 3'ten başlayan sayıcı diye tanımlar. <!-- BELİRSİZ: Hocanın 3 fazlalık sayıcının bitişine dair sözü ("1111'den sonra ...") altyazıda bozuk. -->

> **Ek bilgi (derste anlatılmadı):** 3 fazlalık (excess-3) kodda 0-9 rakamları $0011$'den $1100$'e kadar kodlanır; yani her rakamın kodu, rakamın 3 fazlasının ikili karşılığıdır.

## 8. İkili sayıcı ile BCD sayıcının karşılaştırılması

Hoca kitaptaki bir soruyu okur: "İkili sayıcı ile BCD sayıcı arasında ne fark vardır? Uygulamaya bağlı olarak hangisinin seçilmesi gerektiğine nasıl karar veririz?"

Bir öğrenci BCD'nin 9'a kadar, ikilinin 15'e kadar saydığını söyler. Hoca farkı bir örnekle açar: 99'dan geriye sayan (99, 98, 97, 96, ...) bir aşağı sayıcı tasarlanacaktır (ekrandan, 01:05:00). Sayıcının girişine hangi değer yüklenmelidir?

- **İkili sayıcı:** 99'un ikili karşılığı yüklenir. $99 = 64 + 32 + 2 + 1$ olduğundan $99 = 110\,0011_2$'dir. Bu 7 bittir; 7 bitlik ikili sayıcı 99'dan geriye sayabilir. (Derste önce bir öğrencinin önerdiği $0011\,0011$ değerinin tutmadığı görülmüş, sonra $0110\,0011$ bulunmuştur.)
- **BCD sayıcı:** Her ondalık basamağın ikili karşılığı ayrı ayrı yazılır: $9 \to 1001$, $9 \to 1001$; yani $99 = 1001\,1001_{\text{BCD}}$. Bu 8 bitlik bir sayıcı gerektirir.

Sonuç olarak:

- İkili sayıcı daha az bitle daha çok değer ifade ettiği için daha verimlidir.
- BCD sayıcıda bazı bit kombinasyonları ($1010$-$1111$) kullanılmadığı için bit israfı olur.
- Buna karşılık BCD'nin avantajı ondalık değerin dönüştürmeden yüklenebilmesidir. Örneğin "72'den geriye say" denirse BCD sayıcıya 7 ve 2'nin ikili karşılıkları doğrudan verilir.
- İkili sayıcıda ise önce dönüşüm gerekir. Hocanın gösterdiği yollardan biri: $72 - 64 = 8$ (yani $2^6$ biti 1), $8 - 8 = 0$ (yani $2^3$ biti 1), diğer bitler 0; böylece $72 = 100\,1000_2$ (ara adım eklendi: sonuç python ile kontrol edildi). Diğer yol 72'yi art arda 2'ye bölüp kalanları tersten yazmaktır. Ondalık girişi ikiliye çevirmek için bir dönüştürme devresi gerekir.
- Hoca ayrıca BCD'de 99'dan 199'a geçmek için yalnız başa bir basamak eklemenin yettiğini, ikilide ise 199'un baştan dönüştürülmesi gerektiğini belirtir; iki ikili değer birbirinden bağımsızdır.

> **Hocanın vurgusu:** BCD ile ikili arasındaki bu farkı mikroişlemciler dersinde de göreceksiniz.

## 9. Hafıza birimleri ve adresleme

### 9.1 Hafıza birimi türleri

Saklayıcılar ve sayıcılar mikroişlemcinin çevre birimleriyle iletişimde sıkça kullanılan yapılardır. Üçüncü başlık hafıza birimleridir (ekrandan, 01:25:00):

- RAM: Random Access Memory
- ROM: Read Only Memory; adından da anlaşıldığı gibi yalnız okunur, yazılamaz.
- PROM: programlanabilir ROM
- EPROM: silinebilir (erasable), programlanabilir ROM
- E²PROM: elektrikle silinebilir, programlanabilir ROM

Hoca bunları ayrıntılı işlemeyeceğini, önce hepsinde ortak olan hafıza yapısını anlatacağını söyler.

### 9.2 Hafıza hücresi ve hafıza birimi

Her hafıza biriminde birden fazla hafıza hücresi (bloğu) bulunur. Bunlar alt alta satırlar olarak çizilir; dış kılıf konduğunda bütünü hafıza birimi olur. RAM, ROM, PROM, EPROM hepsinde bu yapı vardır.

Her hafıza hücresinin tekil (unique) bir adresi vardır. Tahtadaki örnekte adresler $000, 001, 010, \dots, 111$'dir; yani 8 hafıza hücresi bulunan bir hafıza birimi çizilmiştir (ekrandan, 01:25:00).

Her hafıza hücresi tanımlı sayıda bit kabul eder. Örnekte her hücre 8 bittir: 8 bit yan yana gelerek bir sözcük (word) oluşturur ve bir hücreye konur. Bu, diğer bütün hücrelerin de aynı bit genişliğinde olduğu anlamına gelir; bir adrese yazılan her şey 8 bitlik olur.

### 9.3 Gösterim: satır × sözcük genişliği

Bu hafıza "$8 \times 8$ bit" diye gösterilir (ekrandan, 01:25:00):

- Soldaki sayı (8) hafıza bloğu adedini, yani satır sayısını gösterir.
- Sağdaki sayı (8 bit) her blokta tutulan veri sözcüğünün bit genişliğini gösterir.

Toplam kapasite $8 \times 8 = 64$ bittir. 8 bit 1 bayt olduğundan bu aynı zamanda 8 bayttır (ekrandan, 01:30:00).

### 9.4 1 MB'lık hafıza örneği

Soru: 1 MB'lık bir hafıza biriminde her blok 16 bit ($D_0$-$D_{15}$) ise kaç satır vardır; adresler $000\dots0$'dan başlıyorsa son satırın adresi nedir? (ekrandan, 01:30:00)

Öğrencilerden farklı cevaplar gelir (250, $2^{20}$ gibi). Hoca çözümü bayt üzerinden kurar:

1. 1 MB, bir milyon (mega) bayttır.
2. Her satır 16 bit, yani 2 bayttır.
3. Bu yüzden $1\ \text{MB} = 512\text{K} \times 2$ bayt $= 512\text{K} \times 16$ bit yazılabilir.
4. $1\text{K} = 2^{10}$ ve $512 = 2^9$ olduğundan satır sayısı $512\text{K} = 2^9 \times 2^{10} = 2^{19}$'dur (ekrandan, 01:35:00).
5. Yani hafıza $2^{19} \times 16$ bittir; $2^{20}$ değil.

Adres $0\dots0$'dan başlar ve en büyük adres bütün bitlerin 1 olduğu adrestir. $2^{19}$ satırı adreslemek için 19 adres biti gerekir: adres hatları $A_0$'dan $A_{18}$'e kadardır.

> **Ek bilgi (derste anlatılmadı):** Burada 1 MB $= 2^{20}$ bayt alınmıştır; $2^{19} \times 2$ bayt $= 2^{20}$ bayt olduğu python ile kontrol edildi.

Genelde günümüz işlemcileri 32 bit ve 64 bitlik sözcükleri destekler.

## 10. Kod çözücü ile hafıza satırı seçimi

### 10.1 Kod çözücünün rolü

Mikroişlemcinin bir adrese yazabilmesi ya da oradan okuyabilmesi için o adresin etkin (enable) yapılması gerekir. Bu adresleme kod çözücüyle (decoder) sağlanır (ekrandan, 01:35:00).

3x8 kod çözücü örneği: adres yolundan 3 bit girer. $000$ verildiğinde kod çözücünün yalnız ilgili çıkışı etkin olur ve yalnız o satır seçilir. Mikroişlemci read sinyali gönderdiğinde seçilen satırdaki veri, 8 hatlık veri yolundan (data bus) mikroişlemciye gider. Tahtada ayrıca read ve write hatları gösterilmiştir.

Aynı mantıkla 1 MB örneğinde 19 girişli bir kod çözücü $2^{19}$, yani yaklaşık 512 bin satırı tek tek etkin ya da etkisiz yapar. Kod çözücü her seferinde yalnız bir çıkışı etkin yaptığı için ilgili hücreye ulaşılır.

> **Hocanın vurgusu:** Kod çözücünün hafıza birimlerinde kullanılmasının nedeni adresi çözümlemektir. Ulaşılmak istenen adres, adres yolu (address bus) üzerinden daha az bitle gönderilir ve o adrese yazma ya da okuma yapılır.

### 10.2 Neden yalnız bir satır seçilmeli?

Hafıza hücrelerinin arka planında hepsi ortak bir kabloya (veri yoluna) bağlıdır. Seçilen satırdaki veri veri yoluna konmalı, diğer hücrelerdeki veriler veri yoluna girmemelidir. Bu yüzden yalnız bir satır etkin olmalıdır.

### 10.3 12 flip-floplu örnek hafıza birimi

Hoca bunu somutlaştırmak için flip-floplardan oluşan bir hafıza birimi çizer (ekrandan, 01:40:00): 4 satır ve her satırda 3 flip-flop, toplam 12 flip-flop. Satırlar bir 2x4 kod çözücünün çıkışlarına, sütunlar ortak veri hatlarına bağlıdır. Altta mikroişlemci ($\mu$P) vardır ve read/write sinyallerini bütün birimlere gönderir.

**Soru:** Bu hafıza birimi ne kadarlık bir hafızadır? **Cevap:** Bir öğrenci $4 \times 3$ der; hoca 12 bit olduğunu onaylar, çünkü bir flip-flop bir bit saklar (ekrandan, 01:40:00). Hoca böyle bir hafıza biriminin gerçekte olmadığını, gösterim için sembolik olduğunu belirtir.

Bu, daha önce blok olarak çizilen yapının iç yapısıdır: $00, 01, 10, 11$ adresli ve her biri 3 bit tutan 4 satır.

Okuma adım adım şöyle olur (ekrandan, 01:45:00):

1. Mikroişlemci bütün flip-floplara read sinyali gönderir.
2. Nereden okunacağını belirlemek için adres yoluna ($A_1, A_0$) $01$ verisini koyar.
3. 2x4 kod çözücü $A_1A_0 = 01$ girişinde yalnız 1 numaralı çıkışını etkin yapar; diğer çıkışlar çıktı üretmez.
4. Yalnız bu satırdaki 3 flip-flopun verisi ortak veri yoluna ($D_2, D_1, D_0$) aktarılır. Tahtadaki örnekte bu satırda $0, 1, 0$ değerleri vardır.
5. Veri yolu bu değeri mikroişlemciye gönderir.

Başka bir adres seçilseydi yalnız o satır etkin, diğerleri etkisiz olacağı için yalnız o satırın verisi veri yoluna geçerdi. $D_2$, $D_1$ ve $D_0$ hatları her biri bir sütundaki bütün flip-floplar için ortaktır; hangi satırın okunacağı adresle seçilir (indislenir).

## 11. Veri yolu ve adres yolu

Hoca mikroişlemcinin "iki gücü"nden söz eder:

**Saklayıcı boyutu ve veri yolu.** Örnekteki mikroişlemcinin 3 bitlik saklayıcısı vardır; hafıza birimi de bu yüzden 3 bitliktir, çünkü bir satır tek seferde bir saklayıcıya atanabilmelidir. 8086 16 bitlik saklayıcılara sahiptir (bazı durumlarda 8 bitle de çalışır; ayrıntısı mikroişlemci dersindedir). Hafıza bloğundaki flip-flop sayısı saklayıcının bit sayısıyla ilişkilidir ve veri yolunun genişliğini oluşturur. 16 bitlik saklayıcı varsa 16 veri hattı vardır; böylece hafızadan tek seferde 16 bit saklayıcıya yazılabilir.

> **Hocanın vurgusu:** Veri yolu, hafıza biriminin blok içinde tutabileceği en büyük genişliği belirtir (ekrandan, 01:45:00). 16 bitlik veri yoluna sahip bir mikroişlemci seçtiği adresten tek seferde 16 bit okuyabilir; bu, o hafıza biriminde 16 flip-flopun yan yana gelmesi demektir.

**Adres yolu.** Adres yolu, hafıza biriminin kaç satır olacağını belirtir ve mikroişlemcinin bir gücüdür. 8086'nın 20 bitlik adres yolu vardır.

> **Ders sonrası not:** Altyazıda 8086'nın 20 adres hattıyla indisleyebileceği satır sayısı "250" gibi bozuk geçiyor; 20 adres hattıyla $2^{20} = 1\,048\,576$ (yaklaşık 1 milyon) satır seçilebilir.

Hoca daha yeni işlemcilerin $2^{30}$ gibi adres aralıklarına ulaştığını, $2^{30}$ ile yaklaşık 1 milyar satırın seçilebildiğini söyler; hangi işlemci olduğundan emin olmadığını belirtir. <!-- BELİRSİZ: Hocanın andığı işlemci modeli ve adres genişliği altyazıda net değil. -->

Örnekteki mikroişlemcinin 2 bitlik adres yolu vardır, yani 4 satırı adresleyebilir. Bu mikroişlemciye 100 satırlık yeni bir hafıza birimi takılsa bile fazladan satırlar mikroişlemci tarafından görülmez.

Günlük bir örnek: eskiden 32 bitlik işletim sistemleri vardı, sonra 64 bitlikler çıktı. Hafıza birimlerinin satır sayısı arttı; 32 bit ile adreslenebilen alan 4 GB ile sınırlı olduğu için daha büyük hafızayı indisleyebilmek amacıyla 64 bit sistemlere geçildi. 32 bitlik işletim sistemine sahip bir bilgisayara 16 GB RAM takılsa bile kullanılabilecek alan yalnız 4 GB'dır; hoca bunun biraz da yazılım tarafıyla ilgili olduğunu belirtir.

> **Ek bilgi (derste anlatılmadı):** $2^{32}$ bayt $= 4 \cdot 2^{30}$ bayt $= 4$ GB'dır (python ile kontrol edildi).

Özetle:

- Hafıza biriminin satır sayısı, mikroişlemcinin adresleyebileceği adresleri, yani adres yolu genişliğini belirler.
- Sütun sayısı (blokların veri bit genişliği), veri yolu (data bus) genişliğini belirler.

## 12. Statik ve dinamik RAM, ROM türleri

### 12.1 Statik RAM

RAM kendi içinde ikiye ayrılır: statik ve dinamik mimaride tasarlananlar (ekrandan, 01:50:00).

Statik RAM doğrudan flip-flop mimarisidir: bir bitlik veri bir flip-flopta tutulur. Flip-flopun içinde kapılar vardır. Flip-flop anlatılırken söylendiği gibi, kapıların gecikmelerinin bir sonraki kapının girişi olması ve verinin bu döngü içinde sıkıştırılmasıyla bit saklanır.

### 12.2 Dinamik RAM

Dinamik RAM kondansatör ve transistör mimarisine dayanır (flip-flop da transistörlerden yapılır). Kondansatör, elektrik verildikçe şarj olan, elektrik kesilince üzerindeki yükü boşaltmaya eğilimli bir devre elemanıdır. Kondansatöre veri yüklemek şarjı tutmak, veriyi silmek deşarj etmek demektir; veri elektriksel yüklenmeye göre tutulur. Bu işlem daha yavaştır.

### 12.3 Karşılaştırma ve cache bellek

- Statik RAM'ler dinamik RAM'lerden çok daha hızlıdır.
- Ama statik RAM'de flip-flop adedi çok fazla olmalıdır; örneğin her 8 bitlik satır için 8 flip-flop gerekir. 1 GB gibi yüksek kapasiteler için bu mimariyi kurmak çok zordur.
- Kondansatörlü mimariler daha çok veriyi daha küçük alanda tutar; bu yüzden dinamik RAM'lerin maliyeti düşüktür, ama hızları statikten düşüktür.

Statik RAM'in en önemli örneği cache (önbellek) bellektir. Cache bellek CPU'nun, yani işlemcinin içinde yer alır. Ana RAM ise işlemcinin dışında, kasanın içinde ayrı modüllerdedir. Bu yüzden cache bellekler daha küçüktür (hoca 8 MB, 32 MB gibi değerler verir) ama çok daha hızlıdır.

İşlemci önce statik belleğe (cache) bakar; aradığı veriyi orada bulamazsa dinamik belleğe, yani ana belleğe (main memory) gider. Derste çizilen flip-floplu örnek de bir statik RAM mimarisidir.

### 12.4 ROM ve türevleri

ROM mimarileri silinemez; fabrikadan gömülü olarak gelir. Okunabilir, ama yazma sinyaliyle değiştirilemez. Sonradan bir kez ya da birkaç kez programlanabilen (PROM, EPROM) sürümler ve yüksek düzeyde programlanabilen flash ROM'lar çıkmıştır. Güncel BIOS'lar bu şekilde üretilir.

> **Hocanın vurgusu:** Burada önemli olan hafıza bloğu yapısını iyi kavramaktır; bu mimari mikroişlemcilerde çokça karşınıza çıkacak. Saklayıcıların içindeki verilerin nasıl tutulduğu bu şekilde anlatılmış olur.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:18:05; ekrandan, 00:20:00): 4 bitlik paralel giriş-paralel çıkışlı bir saklayıcıda $G_3G_2G_1G_0 = 1001$ verisi bir saat darbesiyle $\text{Ç}_3\text{Ç}_2\text{Ç}_1\text{Ç}_0$ çıkışlarına aktarılıp bir sonraki darbeye kadar saklanacaktır. Hangi tip flip-flop kullanılmalıdır?

> **Çözüm (derste verildi):** D (data) tipi flip-flop. Saat darbesinde girişteki değer çıkışa aynen geçer ve bir sonraki darbeye kadar korunur.

**Soru 2** (derste sözlü, 00:24:43; ekrandan, 00:30:00): 4 bitlik seri girişli saklayıcıda $0001$ değerinden $0010$ nasıl elde edilir?

> **Çözüm:** Derste 3 kez sağa kaydırma önerilmiş ve onaylanmıştır. Bu, döndürme için doğrudur: $0001 \to 1000 \to 0100 \to 0010$ (3 kez sağa döndürme = 1 kez sola döndürme). Öteleme kullanılırsa 1 bit sola öteleme gerekir; 3 kez sağa öteleme sonucu $0000$ yapar (ders sonrası kontrol edildi).

**Soru 3** (ekrandan, 00:40:00): $1100\,0101$ sayısının ondalık karşılığını bulun; sayıyı 1 bit sağa öteleyin ve 1 bit sağa döndürün.

> **Çözüm (derste verildi, düzeltmeli):** $1100\,0101 = 128 + 64 + 4 + 1 = 197$. 1 bit sağa öteleme: $0110\,0010 = 98$ ($= \lfloor 197/2 \rfloor$). 1 bit sağa döndürme: $1110\,0010 = 128 + 64 + 32 + 2 = 226$ (tahtada 230 yazıldı; doğrusu 226).

**Soru 4** (derste sözlü, 00:41:29): 8 bitlik bir sayıcı 0 ile kaç arasında sayar?

> **Çözüm (derste verildi):** $2^8 - 1 = 255$.

**Soru 5** (derste sözlü, 00:48:01; ekrandan, 00:50:00): İki tane 4 bitlik aşağı sayıcı kaskat bağlanmıştır: üstteki sayıcıya $1111$, alttakine $1000$ yüklenmiştir ve üstteki sayıcının "sayma tamam" çıkışı alttakinin saatini sürmektedir. Alttaki sayıcının "sayma tamam" çıkışı kaç sayım sonra 1 olur?

> **Çözüm (derste verildi):** Üstteki sayıcı alttakini her 16 adımda bir tetikler; alttaki sayıcı 8'den 0'a 8 tetiklemede iner. Toplam $16 \times 8 = 128$ sayım.

**Soru 6** (derste sözlü, 00:57:43, kitaptan; ekrandan, 01:05:00): İkili sayıcı ile BCD sayıcı arasında ne fark vardır? Uygulamaya bağlı olarak hangisinin seçileceğine nasıl karar verilir? (Örnek: 99'dan geriye sayan sayıcı.)

> **Çözüm (derste verildi):** 99 ikili sayıcıda $110\,0011$ (7 bit), BCD sayıcıda $1001\,1001$ (8 bit) olarak yüklenir. İkili sayıcı daha az bit kullanır, daha verimlidir; BCD sayıcıda kullanılmayan kombinasyonlar yüzünden bit israfı olur. BCD sayıcının avantajı ondalık değerin dönüşümsüz yüklenebilmesidir; ikili sayıcıda ondalık giriş için dönüştürme (devresi) gerekir. Uygulama ondalık giriş/çıkışla çalışıyorsa BCD, bit verimliliği önemliyse ikili sayıcı seçilir.

**Soru 7** (derste sözlü, 01:25:04; ekrandan, 01:30:00 ve 01:35:00): 1 MB'lık bir hafıza biriminde her blok 16 bittir. Kaç satır vardır ve kaç adres hattı gerekir?

> **Çözüm (derste verildi):** $1\ \text{MB} = 512\text{K} \times 2$ bayt $= 512\text{K} \times 16$ bit. $512\text{K} = 2^9 \cdot 2^{10} = 2^{19}$ satır. Adresleme için 19 hat gerekir: $A_0$-$A_{18}$.

**Soru 8** (derste sözlü, 01:39:07; ekrandan, 01:40:00): 4 satır ve her satırda 3 flip-flop bulunan (toplam 12 flip-flop) hafıza birimi ne kadarlık bir hafızadır?

> **Çözüm (derste verildi):** Her flip-flop bir bit sakladığından $4 \times 3 = 12$ bit.

## Dersin Toparlaması

Bu derste flip-flopların bir araya gelerek oluşturduğu üç yapı incelendi. Saklayıcılar, ortak saate bağlı $n$ flip-floptan oluşur ve PIPO, SIPO, PISO, SISO türleri vardır. Mikroişlemci saklayıcıları genelde PIPO yapısındadır. Saklayıcı, ALU'ya gitmeden set, reset, öteleme ve döndürme işlemlerini yapabilir. $n$ bit sağa öteleme $2^n$'e bölmek, sola öteleme $2^n$ ile çarpmak demektir; döndürmede ise bit kaybolmaz. Sayıcılar bit sayısı, sayma yönü, çalışma modu, durum sayısı ve senkron/asenkron oluşlarına göre sınıflandırıldı. Kaskat bağlı aşağı sayıcılarla tek sayıcının yetmediği uzun sayımların yapılabileceği, BCD, Gray ve modülo sayıcıların ikili sayıcıdan farkları ve BCD ile ikili sayıcı arasındaki verimlilik-kolaylık dengesi gösterildi.

Son bölümde hafıza birimlerinin satır × sözcük genişliği yapısı, kod çözücüyle tek satırın seçilip ortak veri yoluna bağlanması, adres yolunun satır sayısını ve veri yolunun sözcük genişliğini belirlemesi anlatıldı. Statik RAM (flip-flop, hızlı, cache) ile dinamik RAM (kondansatör + transistör, yavaş, ucuz, ana bellek) karşılaştırıldı ve ROM türleri tanıtıldı. Hoca bu yapıların, özellikle hafıza bloğu ve adresleme mantığının, mikroişlemciler dersinde sıkça kullanılacağını belirterek dönemin anlatımını tamamladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
