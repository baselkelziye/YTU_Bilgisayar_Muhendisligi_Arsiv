# Ders 6 Genişletilmiş Notu: Yazmaç Transferleri ve RTL: Mikro İşlemler, Datapath ve Bus Yapıları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı: Yazmaç Seviyesinde İşlemler ve Register File
- 2. Paralel Yüklemeli Yazmaç
- 3. Yükleme (Load) Kontrolü
- 4. Kontrol Birimi ve Datapath
- 5. Yazmaçlara Erişim Biçimleri
- 6. Basit Bir Yazmaç Transferi: K1: R2 ← R1
- 7. RTL Gösterimi ve Eş Anlı Atama
- 8. Aritmetik Mikro İşlemler ve Toplayıcı-Çıkarıcı Datapath'i
- 9. Carry ve Overflow Bayrakları
- 10. Lojik Mikro İşlemler
- 11. Öteleme Mikro İşlemleri
- 12. MUX ile Kaynak Seçimi ve Genelleştirme
- 13. Dolaylı Adresleme ve Donanım Karmaşıklığı
- 14. Ötelemeli Yazmaçlar
- 15. Sayıcıların Hatırlatılması
- 16. Yazmaçlar Arası Transfer Yapıları: Adanmış MUX, Tek Bus, Üç Durumlu Bus
- 17. Örnek Sorular

## 1. Dersin Amacı: Yazmaç Seviyesinde İşlemler ve Register File

Bu dersin konusu yazmaç (register) seviyesindeki işlemlerdir. Bu işlemler temel olarak yazmaçlar arası transfer (register transfer) işlemleri olarak tanımlanır. Hedef, ilerleyen haftalarda tasarlanacak tek çevrimli (single cycle) CPU'nun temel bloklarından biri olan **register file** yapısına ulaşmaktır. Register file, içinde adreslenebilir yazmaçlar bulunan, hem kaynak hem hedef yönünde belirli yazmaçların seçilebildiği, okuma ve yazma kontrolleri olan bir yapıdır.

Hoca, CPU içindeki blokların iki türlü çalıştığını hatırlattı. Bazı bloklar senkrondur: saat işaretini bekler ve değeri saatin yükselen kenarında içeri alır. Bazı bloklar kombinasyonel mantıkla çalışır: girişi değiştiği anda çıkışı da değişir. Kombinasyonel blokların ürettiği değerler senkron elemanların girişine kadar gelir ve orada bekler. Saatin yükselen kenarıyla bu değerler senkron elemanların içine kopyalanır. Register file senkron bloklardan biridir.

Daha önce flip-flop'larla yazmaçlar tanımlanmıştı, ama o çalışmalar ardışıl devre tasarımı kapsamındaydı. Bu derste yazmaçlar arası transfer ve bu transferi tanımlayan **RTL (Register Transfer Language)** ile bir kontrol akışı görülür.

## 2. Paralel Yüklemeli Yazmaç

### 2.1 Yapı

$n$ bitlik paralel yüklemeli yazmacın $n$ girişi ve $n$ çıkışı vardır. Senkron olduğu için bir saat ucu vardır ve durum değişimi saatin yükselen kenarında olur. Ayrıca bir $\overline{Clear}$ ucu vardır; içerideki flip-flop'ları sıfırlamak için kullanılır (ekrandan, 00:15:00).

Şekildeki 4 bitlik yazmaçta dört D flip-flop vardır. Saat uçları ortaklanıp dışarıya tek bir Clock ucu olarak verilmiştir. D uçları $D_0$-$D_3$ olarak dışarı çıkarılmıştır. Her flip-flop'un aktif sıfır asenkron reset ucu (R) ortaklanıp $\overline{Clear}$ olarak dışarı verilmiştir. Sembolde REG kutusu, saat girişi, $\overline{Clear}$, $D_0$-$D_3$ ve $Q_0$-$Q_3$ görünür.

Flip-flop'larda standart giriş, saat ve çıkış uçları dışında iki asenkron uç (set ve reset) bulunur. Bu şekilde yalnız reset ucu dışarı verilmiştir. İstenirse aktif sıfır set uçları da ortaklanıp dışarı çıkarılabilir; set değerleri birlemek, clear sıfırlamak için kullanılır. Ama paralel yüklemeli bir yazmaçta clear tek başına yeterlidir, çünkü istenen her değer zaten paralel yükleme uçlarından verilebilir.

### 2.2 D flip-flop'ta paralel yükleme neden ek lojik istemez

Hoca bunu ters tanım bağıntısıyla gösterdi. D flip-flop'ta saatin yükselen kenarında D'deki değer Q'ya geçer. $q \to Q$ geçişleri için gereken D değerleri:

| $q$ | $Q$ | $D$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

Yani D, istenen $Q$ ile aynıdır. Dışarıdan bir $D_i$ girişi eklenip $Q = D_i$ istendiğinde tablo $D_i, q$ için D = 0, 0, 1, 1 olur. Buradan $D = D_i\,\overline{q} + D_i\,q = D_i$ çıkar. Dışarıdan verilen değer olduğu gibi D ucuna bağlanır.

Hoca bunu kısa sınavdaki T flip-flop'lu soruyla karşılaştırdı. T flip-flop'ta paralel yükleme için girişe, dışarıdan gelen değer ile mevcut durumun XOR'u bağlanmalıdır: $T = D_i \oplus q$. T flip-flop'u D flip-flop gibi düşünüp $D_i$'yi doğrudan T'ye bağlamak en sık yapılan hataydı.

> **Hocanın vurgusu:** T flip-flop ile paralel yüklemede $T$ girişine doğrudan $D_i$ bağlanmaz; $T = D_i \oplus q$ olmalıdır.

### 2.3 Asenkron ve senkron reset

Reset ucunda oluşturulan sıfır, asenkron reset ise saat beklemeden (kombinasyonel olarak) $Q$'yu sıfıra çeker. Bu yazmaçta $\overline{Clear}$'a 0 verildiğinde bütün $Q$'lar saat gelmeden 0 olur. Senkron reset ise ancak saatin yükselen kenarında etkili olur. Reset işaretinin kenar gelene kadar 0 tutulması gerekir. Dalga şeklinde $\overline{Clear}$ 0 iken yükselen kenar geldiğinde $Q$'ların sıfıra döndüğü görülür.

## 3. Yükleme (Load) Kontrolü

Yukarıdaki yazmaçta D'lere değer verildiği anda her yükselen kenarda yükleme olur. Yüklemeyi bir kontrol ucuyla yönetmek için bir **load** ucu eklenir.

### 3.1 Saat işaretini kapılamak

İlk çözüm ekstra uç çıkarmak yerine saat ile load'u birleştirmektir (ekrandan, 00:20:00):

$$C = \overline{Load} + Clock$$

$Load = 0$ ise OR kapısının bir girişi 1 olur, çıkış sürekli 1 kalır. Saat ne kadar değişirse değişsin flip-flop'lar kenar görmez, yükleme olmaz. $Load = 1$ ise OR çıkışında saat işaretinin kendisi görülür ve yükleme olur. Zamanlama diyagramında Load 1 iken C girişlerinde saat darbeleri görülür (ekrandan, 00:25:00).

Bu yöntemin sakıncası şudur: Load 1 olarak bırakıldığı sürece birden çok yükselen kenar gelebilir. Bu sırada girişlerde değişim olursa yanlış değer yüklenebilir. Ayrıca saat işaretini manipüle etmek, bu yazmaç özelinde senkron yapıya müdahale etmek demektir.

### 3.2 D girişini değiştirmek

Daha doğru yaklaşım saate dokunmadan D uçlarına bağlanacak değeri değiştirmektir. Ayrı bir $L$ (load) ucu olur. $L = 1$ iken yükselen kenarda $D_i$ içeri kopyalanır, $L = 0$ iken yazmaç önceki durumunu korur.

Girişler $L$, $D_i$ ve mevcut durum $q$'dur. Sekiz durum için istenen sonraki durum ve D değeri (ekrandan, 00:25:00):

| $L$ | $D_i$ | $q$ | $Q$ | $D$ |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 | 1 |
| 0 | 1 | 0 | 0 | 0 |
| 0 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 | 0 |
| 1 | 0 | 1 | 0 | 0 |
| 1 | 1 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 |

$L = 0$ satırlarında $Q = q$, $L = 1$ satırlarında $Q = D_i$'dir. Karnaugh haritasından:

$$D = \overline{L}\,q + L\,D_i$$

Kitaptaki şekilde (ekrandan, 00:30:00) bu kontrol ucu EN (enable) adıyla geçer; derste $L$ kullanıldı. Bu fonksiyon python ile doğruluk tablosu üzerinden kontrol edildi.

Böylece load istenen sürece aktif tutulabilir. Load 0 iken saat ne kadar değişirse değişsin içerik değişmez. Kısa sınavda yapıldığı gibi aynı iş MUX'larla da yapılabilir ve MUX'larla daha farklı fonksiyonlar da eklenebilir.

> **Hocanın vurgusu:** Sistem senkron olduğu için saat işaretine müdahale etmek yerine girişe bağlanacak değeri manipüle etmek daha doğrudur.

## 4. Kontrol Birimi ve Datapath

Bir CPU'da birden çok birim aynı anda çalışır ve her birinin farklı fonksiyonları vardır. Yürütülecek komuta göre ALU toplama yapabilir, ikiye tümleyen aritmetikte negatif değer hesaplayabilir ya da bir yazmaçtaki değer başka bir yazmaca aktarılabilir. Bu yüzden her modülün yapması gereken işe göre farklı kontrol işaretleri gerekir. Kontrol genişlikleri de farklıdır. Az önceki yazmaçta yalnız bir load ucu vardı. Register file'da ise yazma kontrolü, okuma kontrolü, adres giriş ve adres çıkış kontrolleri olacaktır.

Bu kontrol işaretlerini üreten yapı **kontrol birimidir** (ekrandan, 00:40:00). Kitaptaki blok şemada:

- Kontrol birimine dışarıdan **kontrol girişleri** (control inputs) gelir. Bunlar üst seviye, daha kompakt komutlardır.
- Kontrol birimi datapath'e bit seviyesinde **kontrol sinyalleri** gönderir. Load işareti buna örnektir.
- Datapath kontrol birimine **durum sinyalleri** (status signals) döndürür.
- Kontrol birimi dış dünyaya yapılan işle ilgili geri bildirim olarak **kontrol çıktıları** verir.
- Datapath'e **veri girişleri** gelir, datapath **veri çıktıları** üretir.

Kontrol biriminin formal görevi üst seviye kontrol girişlerini düşük seviye, bit bazındaki kontrol sinyallerine dönüştürmektir.

**Datapath**, bir transferin ya da aritmetik işlem sonucunun bir yerde saklanması veya girdilerin sisteme verilmesi gibi işlerde veri aktarımını sağlayan bağlantı yapısıdır. Hangi çıktının nereye bağlanacağını belirler ve modüle göre özel tasarlanabilir.

Durum sinyallerine örnek olarak tam toplayıcı ya da ALU'daki bayraklar verildi. Elde varsa bir sonraki adımda hesaba katılması gerekebilir. Overflow varsa üretilen değer anlamsızdır, bu bilgi kontrol birimine aktarılıp hata uyarısı verilebilir. Veri girişi olarak dışarıdan verilen bir değer ya da komutun içinde gelen sabit bir değer düşünülebilir.

## 5. Yazmaçlara Erişim Biçimleri

Yazmaçlar farklı biçimlerde erişime izin verebilir:

- Yazmaca adıyla doğrudan erişim. Derste yazmaçlar $R0$'dan $Rn$'e kadar adlandırılacaktır.
- Destekleniyorsa yazmacın tek tek bitlerine erişim.
- 16 bitlik mimaride yüksek ve düşük baytlara ayrı erişim.

8086 16 bitlik bir işlemcidir. AX 16 bitlik bir yazmaçtır; komutta AX yazıldığında 16 bitin tamamına bir word olarak erişilir. AL ve AH, AX'in düşük ve yüksek 8 bitlik kısımlarıdır ve ayrıca adreslenebilir. Bit bazında erişim donanımı çok karmaşıklaştırdığı için her yazmaçta pratik değildir. Bazı özel mikrodenetleyicilerde vardır. Hocaya göre 8086'da bit bazında erişim yalnız bayrak yazmacında, sınırlı olarak vardır.

## 6. Basit Bir Yazmaç Transferi: K1: R2 ← R1

Kitaptaki örnekte R1'in çıkışları R2'nin girişlerine bağlıdır. R2'nin load ucunu $K1$ kontrol işareti sürer, iki yazmacın saati ortaktır. Kontrol birimi burada yalnız $K1$'i üreten lojiktir.

İşlev: $K1 = 1$ iken saatin yükselen kenarında R1'in içeriği R2'ye kopyalanır. R1 üzerinde bir işlem yapılmaz. RTL karşılığı (ekrandan, 00:40:00):

$$K1:\ R2 \leftarrow R1$$

Kontrol koşulu iki noktadan önce, transfer sonra yazılır. Dalga şeklinde $K1$ 1'e çıkar, ardından gelen yükselen kenarda transfer olur. Bu örnekte load seviye tetiklemelidir. Hoca, $K1$ gereğinden uzun 1 bırakılırsa aynı işlemin gereksiz yere tekrarlanabileceğini ya da hatalı değer yüklenebileceğini, bu yüzden load'un kenar tetiklemeli bir senkron işaret olarak düşünülmesinin de uygun olabileceğini söyledi.

R1'in $Q_0$-$Q_{n-1}$ çıkışları R2'nin $D_0$-$D_{n-1}$ girişlerine sırayla bağlıdır. Çizimde kolaylık için bu $n$ tel kalın bir okla, üzerine eğik çizgi ve $n$ yazılarak gösterilir. Bu bir **bus** gösterimidir.

**Soru (hoca sordu):** Bu yapıda datapath nerededir? **Cevap:** Bir öğrenci birinci yazmacın çıkışlarını söyledi. Hoca doğruladı: R1'den R2'ye giden veri yolu bu örnekte datapath'tir. Datapath bir veri yolunu ve bu yolun giriş-çıkış yönlerini ifade eder. R2'den R1'e de transfer istenseydi, R2'nin çıkışından R1'in girişine bir kontrol üzerinden bağlantı gerekecek ve datapath bu bağlantıyı ve onu yöneten lojiği de içerecekti.

## 7. RTL Gösterimi ve Eş Anlı Atama

### 7.1 Temel semboller

Kitaptaki tablo (ekrandan, 00:45:00):

| Sembol | Açıklama | Örnek |
|---|---|---|
| Harfler (ve rakamlar) | Bir yazmacı gösterir | AR, R2, DR, IR |
| Parantez | Yazmacın bir parçasını gösterir | $R2(1)$, $R2(7{:}0)$, $AR(L)$ |
| Ok | Veri transferini gösterir | $R1 \leftarrow R2$ |
| Virgül | Eş anlı transferleri ayırır | $R1 \leftarrow R2,\ R2 \leftarrow R1$ |
| Köşeli parantez | Bellek adresini belirtir | $DR \leftarrow M[AR]$ |

Yazmaçlar büyük harfle adlandırılır. Derste genel gösterim olarak $R0, R1, \ldots, Rn$ kullanılacaktır. $R2(1)$, R2'nin 1 numaralı bitidir. $R2(7{:}0)$, 0 ile 7. bitler arasındaki aralıktır. Aralığın 8 bit olması gerekmez, herhangi bir bitten herhangi bir bite olabilir. 16 bitlik yazmaçta L ve H, düşük ve yüksek anlamlı 8 biti gösterir. $AR(L)$, $AR(7{:}0)$ ile aynıdır.

Ok sağdan sola atamadır. $R1 \leftarrow R2$ işleminde R2'nin içeriği R1'e aktarılır; yükselen kenardan sonra R1'in değeri R2'ye eşit olur, R2 değişmez.

> **Ders sonrası not:** Hoca bu örneği anlatırken bir yerde "R2'nin değeri değişiyor, R1'e eşit oluyor" dedi, hemen ardından doğrusunu söyledi: $R1 \leftarrow R2$ işleminde değişen R1'dir, R2 değişmez.

### 7.2 Eş anlı atama ile sıralı atama

$R1 \leftarrow R2,\ R2 \leftarrow R1$ matematiksel olarak anlamsız görünebilir: aynı anda birbirine atanırsa değerler eşitlenir gibi düşünülebilir. Oysa yapı senkrondur ve değişim saatin yükselen kenarında aynı anda olur.

Hoca bunu iki yazmaçla çizdi. R1'in çıkışları R2'nin data in uçlarına, R2'nin çıkışları R1'in data in uçlarına bağlıdır. İki yazmacın load ucu birlikte 1 yapılır, yükselen kenar verilir, kısa süre sonra load kaldırılır. Kenar anında her yazmacın girişinde diğerinin eski değeri vardır ve bu değer içeri kopyalanır. Kopyalanan yeni değer Q uçlarından çıkıp diğer yazmacın girişine yayılana (propagasyon) kadar load zaten kaldırılmıştır. Bu yüzden değerler birbirinin üzerine yazılmaz, **takas edilir**.

Sayısal örnek (derste verildi):

- Başlangıç: $R1 = FFH$, $R2 = 00H$.
- Eş anlı $R1 \leftarrow R2,\ R2 \leftarrow R1$: sonuç $R1 = 00H$, $R2 = FFH$.
- Sıralı (önce $R1 \leftarrow R2$, sonra $R2 \leftarrow R1$): ilk adımda $R1 = 00H$ olur, FFH kaybolur. İkinci adımda $R2 \leftarrow 00H$. Sonuç $R1 = 00H$, $R2 = 00H$.

Programlama dillerinde (Verilog ve FPGA tasarımı dışında) genelde sıralı atama görülür. Eş anlı (paralel) atama donanım tasarımına özgüdür.

> **Hocanın vurgusu:** Eş anlı yüklemenin sıralı yüklemeden bu farkına dikkat edin.

### 7.3 Bellek gösterimi

$DR \leftarrow M[AR]$ ifadesinde köşeli parantez bellekte hangi adrese erişileceğini gösterir: AR'nin gösterdiği bellek adresindeki değer okunup DR'ye aktarılır. Normal parantez yazmacın bitlerine erişim için, köşeli parantez bellek adresi içindir. Burada içeride sabit değil, bir yazmaçta saklı adres kullanılmıştır. Bu, **dolaylı adresleme** olarak adlandırılır. Adresleme modları komut kümesi mimarisi (ISA) konusunda ayrıntılı görülecektir.

### 7.4 Verilog karşılıkları

RTL varsayımsal bir dil, bir gösterimdir. Hoca kitaptaki tabloda RTL ile Verilog karşılıklarını gösterdi (sözlü anlatımdan):

- Kombinasyonel atama RTL'de eşittir ($=$) ile gösterilir; Verilog karşılığı `assign` ifadesidir.
- Yazmaç transferi non-blocking, yani sıralı değil eş anlı ise Verilog'da `<=` ile gösterilir. Bu yapı yazılım programlama dillerinde yoktur.
- Diğer işlemler: aritmetik toplama ve çıkarma, bit bazında AND, OR, XOR, NOT (bire tümleyen), sola ve sağa öteleme, bit vektörü tanımlama ve iki küçük yazmacı birleştirerek (concatenation) daha geniş bir değer oluşturma.

<!-- BELİRSİZ: RTL-Verilog karşılaştırma tablosu (kitapta Tablo 7-2) karede yakalanmadı; semboller altyazıdan yazıldı. -->

Bit bazında AND örneği: $R1 \leftarrow R2 \wedge R3$ işleminde R2'nin 1 numaralı biti ile R3'ün 1 numaralı biti AND'lenip R1'in 1 numaralı bitine yazılır. Aynı şey aynı sıradaki bütün bitler için yapılır.

## 8. Aritmetik Mikro İşlemler ve Toplayıcı-Çıkarıcı Datapath'i

### 8.1 İşlem tablosu

Kitaptaki aritmetik mikro işlemler (ekrandan, 01:10:00):

| Gösterim | Açıklama |
|---|---|
| $R0 \leftarrow R1 + R2$ | R1 ile R2'nin toplamı R0'a |
| $R2 \leftarrow \overline{R2}$ | R2'nin bire tümleyeni |
| $R2 \leftarrow \overline{R2} + 1$ | R2'nin ikiye tümleyeni |
| $R0 \leftarrow R1 + \overline{R2} + 1$ | R1 artı R2'nin ikiye tümleyeni R0'a (çıkarma) |
| $R1 \leftarrow R1 + 1$ | R1'i artırma (yukarı sayma) |
| $R1 \leftarrow R1 - 1$ | R1'i azaltma (aşağı sayma) |

Bire tümleyen alıp bir eklemek ikiye tümleyen almaktır. $R1 + \overline{R2} + 1$ de $R1 - R2$ demektir.

### 8.2 Hangi kombinasyonel blok gerekir

**Soru (hoca sordu):** Bu işlemlerin hepsini gerçeklemek için nasıl bir kombinasyonel blok gerekir? **Cevap:** Bir öğrenci ALU dedi. Hoca, ALU'nun RTL'den sonra gelecek, bu aşama için karmaşık bir yapı olduğunu söyledi. Sohbetten gelen MUX cevabını da kabul etmedi, çünkü amaç işlemlerin hepsini aynı anda üretmek değil, tek bir bloğun uygun kontrolle her birini yapabilmesidir. Bir öğrenci tam toplayıcıları söyledi. Hoca 4 bitlik toplayıcının tek başına yetmediğini, çıkarma için bir ucu XOR'larla kontrol edilen **toplayıcı-çıkarıcı** (adder-subtractor) devresinin aranan cevap olduğunu söyledi.

### 8.3 Toplayıcı-çıkarıcının hatırlanması

4 bitlik tam toplayıcının X ve Y girişleri, bir elde girişi ($C_{in}$), bir elde çıkışı ($C_{out}$) ve toplam çıkışı Z vardır. Yaptığı iş:

$$C_{out}Z \leftarrow X + Y + C_{in}$$

$C_{out}$ ile Z birlikte 5 bitlik bir sayıdır.

Çıkarma için Y girişlerinin her biti bir XOR kapısından geçirilir. XOR'ların diğer girişleri ve elde girişi ortak bir **AS** (add/subtract, seçim) ucuna bağlanır. Bu, sınıfta bir öğrencinin hatırlattığı gibi elde girişine 1 vermek ve Y'leri o uçla XOR'lamak demektir.

- $AS = 0$: $Y_i \oplus 0 = Y_i$, elde girişi 0. İşlem $X + Y$.
- $AS = 1$: $Y_i \oplus 1 = \overline{Y_i}$, elde girişi 1. İşlem $X + \overline{Y} + 1 = X - Y$.

Blok olarak bakıldığında elde girişi bloğun içinde kalır, dışarıdan ayrıca verilemez. Kitaptaki blok şemada (ekrandan, 01:20:00) iki $n$ bitlik giriş, bir seçim ucu (Select S), $n$ bitlik çıkış ve durum çıkışları $C_n$ ile $C_{n-1}$ vardır. Bu iki elde, carry (C) ve overflow (V) bayraklarını üretir.

### 8.4 R1, R2 kaynak, R0 hedef olan datapath

Hoca tahtada şu datapath'i çizdi (ekrandan, 01:20:00 ve 01:35:00): R1 toplayıcı-çıkarıcının X girişine, R2 Y girişine bağlıdır. Çıkış $n$ bitlik yolla R0'ın girişine gider. Üç yazmacın saati ortaktır, çünkü eş anlı atama yapılacaktır. AS ucu dışarı çıkarılmıştır. Önce yalnız R0'da load ucu vardı, sonra R1 ve R2'nin load uçları da (L1, L2) dışarı çıkarıldı ve R1, R2'ye dışarıdan değer yüklenebilir hâle geldi. Kontrol işaretleri AS, L0, L1, L2'dir. Yazmaçlardan toplayıcı-çıkarıcıya ve oradan R0'a giden yollar datapath'i oluşturur.

Kitaptaki tablo genel bir tablodur. Bu datapath'te hedef her zaman R0 olabildiği için hoca işlemleri R0'a yazılacak biçime dönüştürdü.

**İşlem 1: $R0 \leftarrow R1 + R2$**

$$L0 \cdot \overline{AS}:\ R0 \leftarrow R1 + R2$$

Hoca önce kontrolü $L \cdot AS$ diye yazdı, sonra toplamanın $AS = 0$ ile yapıldığını söyleyip $L0 \cdot \overline{AS}$ olarak düzeltti.

**İşlem 2: $R0 \leftarrow \overline{R2}$**

Tablodaki $R2 \leftarrow \overline{R2}$ bu datapath'te yapılamaz, çünkü R2 hedef değildir. $R0 \leftarrow \overline{R1}$ de yapılamaz, çünkü yalnız Y kanalı tümlenebilir. Yapılabilen $R0 \leftarrow \overline{R2}$'dir.

AS = 1 yapılınca $R1 + \overline{R2} + 1$ hesaplanır. $\overline{R2}$'yi yalnız bırakmak için hem $+1$'in hem R1'in etkisi yok edilmelidir. Bir öğrenci "1'e AND veririz" dedi; hoca bu datapath'te AND mantığı olmadığını hatırlattı. Bir öğrenci de R1'in load ucunu 0 yapmayı önerdi; hoca load'un yalnız dışarıdan veri almak için olduğunu, R1'in değerinin her durumda çıkışta bulunduğunu söyledi. Çözüm ikiye tümleyen aritmetiğindedir: $+1$'i yok etmek için R1'de $-1$ bulunmalıdır.

**Soru (hoca sordu):** 8 bitlik ikiye tümleyende $-1$ nasıl yazılır? Bir öğrenci 00000001'i tümleyip 1 eklemeyi düşündü; sonunda sınıf "hepsi 1" cevabında birleşti. $-1 = 11111111_2 = FFH$. Kontrol: en yüksek bit 1 olduğu için sayı negatiftir. Genliği bulmak için bütün bitler tümlenir (00000000) ve 1 eklenir: 00000001. Genlik 1, sayı $-1$'dir (ekrandan, 01:25:00).

Adımlar:

1. $L1:\ R1 \leftarrow FFH$
2. $L0 \cdot AS:\ R0 \leftarrow R1 + \overline{R2} + 1 = FFH + 1 + \overline{R2} = \overline{R2}$

$FFH + 1 = 0$ (8 bitte elde dışarı taşar) olduğundan geriye $\overline{R2}$ kalır.

**İşlem 3: $R0 \leftarrow \overline{R2} + 1$, yani $R0 \leftarrow -R2$**

Bir öğrenci R1'e 0 yükleyip AS'ye 1 vermeyi önerdi; hoca doğruladı.

1. $L1:\ R1 \leftarrow 0$
2. $L0 \cdot AS:\ R0 \leftarrow 0 + \overline{R2} + 1 = -R2$

**İşlem 4: $R0 \leftarrow R1 + \overline{R2} + 1$, yani $R0 \leftarrow R1 - R2$**

Bir öğrenci AS'ye 1 vermenin yeteceğini söyledi; hoca doğruladı. Tek adımdır:

$$L0 \cdot AS:\ R0 \leftarrow R1 + \overline{R2} + 1$$

**İşlem 5: $R0 \leftarrow R1 + 1$**

Burada sınıfta bir süre deneme yapıldı. Önce R2'ye 0 yükleyip çıkarma seçmek denendi: $\overline{0} + 1 = 11111111 + 1 = 0$ olur, sonuç $R1$ çıkar, artırma olmaz. R2'ye 1 yükleyip çıkarma seçmek de denendi: $\overline{00000001} + 1 = 11111110 + 1 = 11111111 = -1$ olur, sonuç $R1 - 1$ çıkar. Sonunda bir öğrencinin önerisi kabul edildi: R2'ye 1 yüklenir ve **toplama** seçilir.

1. $L2:\ R2 \leftarrow 1$
2. $L0 \cdot \overline{AS}:\ R0 \leftarrow R1 + 1$

**İşlem 6: $R0 \leftarrow R1 - 1$**

Az önceki denemenin gösterdiği gibi R2'ye 1 yüklenip çıkarma seçilir.

1. $L2:\ R2 \leftarrow 1$
2. $L0 \cdot AS:\ R0 \leftarrow R1 + \overline{1} + 1 = R1 - 1$

Bu altı işlemin sonuçları 8 bitlik bütün R1, R2 değerleri için python ile doğrulandı.

Hoca şunu vurguladı: basit bir datapath ve tek bir kombinasyonel blokla, ALU'ya ya da karmaşık bir kontrol birimine gerek kalmadan toplama, çıkarma, artırma, azaltma, bire ve ikiye tümleyen işlemleri yapılabilir. ALU'da da tam toplayıcı ve toplayıcı-çıkarıcı kullanılacaktır, ama orada kontrol daha karmaşıktır. Kombinasyonel kısım girişine değer uygulandığı anda çıktıyı üretir. Kontrol işaretlerinin propagasyon süresinden sonra uygulandığı varsayılır; bu varsayım genelliği bozmaz.

### 8.5 Datapath'in sınırları

**Soru (hoca sordu):** Aynı datapath ile şu işlemler yapılabilir mi?

- $R0 \leftarrow \overline{R1}$
- $R0 \leftarrow -R1$
- $R1 \leftarrow R0 - R2$
- $R0 \leftarrow R2 - R1$

**Cevap:** Hiçbiri yapılamaz. Bir öğrenci R1'i tersleyecek bir yol olmadığını söyledi; hoca doğruladı. Birinci kanalda (X) bire tümleyen imkânı yoktur. $-R1$ ve $R2 - R1$ de R1'in tümlenmesini gerektirir. $R1 \leftarrow R0 - R2$'de ise hedef ve kaynak uyumsuzdur: bu yapıda yalnız R1 ve R2 kaynak, yalnız R0 hedef olabilir.

Bu datapath ile R0 her zaman hedeftir, R1 işleme her zaman artı işaretle katılır, bire veya ikiye tümleme yalnız R2 tarafında yapılabilir. Yani gerçeklenebilecek komut çeşitlerini datapath belirler.

> **Hocanın vurgusu:** Oluşturulan datapath, hangi komut varyasyonlarının gerçeklenebileceğini net olarak belirler. Kaynak ve hedeflerin değişimli kullanılabilmesi için farklı bir lojik gerekir.

### 8.6 Kitaptaki R1'in hem kaynak hem hedef olduğu yapı

Kitaptaki şekilde (ekrandan, 01:40:00) R2 toplayıcı-çıkarıcının bir girişine, R1'in çıkışı geri besleme yoluyla diğer girişine bağlıdır. Çıkış yine R1'e yazılır; R1'in load ucunu $K1$ sürer, seçim ucunu X sürer. $C_n$ ve $C_{n-1}$ bir XOR kapısına girer ve V bayrağını, $C_n$ de C bayrağını üretir; bayraklar da $K1$ ile yüklenir. Burada R1 hem kaynak hem hedef olabilir, bu bir serbestliktir. Ama hedef yalnız R1'dir ve eksi alma ile bire tümleme yine yalnız bir kaynak (R2) üzerinden yapılabilir.

## 9. Carry ve Overflow Bayrakları

$n$ bitlik toplayıcıda en yüksek anlamlı bitin toplamından çıkan elde $C_n$, bir önceki bitin eldesi $C_{n-1}$ olarak adlandırılır.

- **Carry (C):** $C_n$'dir. İşaretsiz sayılarda sonucun $n$ bite sığmadığını gösterir.
- **Overflow (V):** İşaretli (ikiye tümleyen) sayılarda taşmayı gösterir. 8 bitte gösterilebilen aralık $-128$ ile $127$'dir. Sonuç bu aralığın dışına çıkarsa overflow 1 olur.

Overflow koşulu $C_{n-1}$ ile $C_n$'in birbirinden farklı olmasıdır:

$$V = C_n \oplus C_{n-1}$$

Bu kural 8 bitlik bütün toplama ve çıkarma durumları için python ile doğrulandı.

## 10. Lojik Mikro İşlemler

Kitaptaki tablo (ekrandan, 01:45:00):

| Gösterim | Açıklama |
|---|---|
| $R0 \leftarrow \overline{R1}$ | Bit bazında NOT (bire tümleyen) |
| $R0 \leftarrow R1 \wedge R2$ | Bit bazında AND (bit temizler) |
| $R0 \leftarrow R1 \vee R2$ | Bit bazında OR (bit kurar) |
| $R0 \leftarrow R1 \oplus R2$ | Bit bazında XOR (bit tümler) |

Hedef hep R0, kaynak R1 veya R2'dir. Dört işlemi aynı datapath'te yapabilmek için hoca tahtada şunu çizdi: R1 ve R2'nin $m$ bitlik çıkışları bir $m$ bitlik NOT dizisine (yalnız R1), bir $m$ bitlik AND, bir $m$ bitlik OR ve bir $m$ bitlik XOR dizisine verilir. Hoca bu dört çıkışı R0'a aktarmak için neye ihtiyaç olduğunu sordu; cevap 4 girişli $m$ bitlik bir **MUX**'tu. MUX'un iki seçim ucu ($S_1$, $S_0$) vardır. Girişler 0: NOT, 1: AND, 2: OR, 3: XOR sırasıyla bağlanır. Yazmaçların ayrı load uçları (L0, L1, L2) vardır.

Kombinasyonel kısım kapı dizileri ve MUX'tur. Yazmaçların kontrol uçları ayrıdır, MUX'un seçim uçları kontrol lojiğini oluşturur. Kalın çizilen $n$ bitlik yollar ve yazmaçlar datapath'i oluşturur.

Kontrol işaretleri (bir öğrenci ilkini $S_1S_0 = 00$ olarak doğru söyledi; her işlem tek adımda yapılır):

- $L0 \cdot \overline{S_1} \cdot \overline{S_0}:\ R0 \leftarrow \overline{R1}$
- $L0 \cdot \overline{S_1} \cdot S_0:\ R0 \leftarrow R1 \wedge R2$
- $L0 \cdot S_1 \cdot \overline{S_0}:\ R0 \leftarrow R1 \vee R2$
- $L0 \cdot S_1 \cdot S_0:\ R0 \leftarrow R1 \oplus R2$

## 11. Öteleme Mikro İşlemleri

Kitaptaki örnekler (ekrandan, 01:50:00):

| Tür | Gösterim | Kaynak R2 | Ötelemeden sonra hedef R1 |
|---|---|---|---|
| Sola öteleme | $R1 \leftarrow sl\ R2$ | 10011110 | 00111100 |
| Sağa öteleme | $R1 \leftarrow sr\ R2$ | 11100101 | 01110010 |

Değerler python ile kontrol edildi (boşalan bite 0 girer).

Öteleme için ötelemeli yazmaç gerekir. Hoca yazmaç sembolünü şöyle tanımladı: $m$ bitlik paralel yükleme girişleri ($D_i$), bir load ucu $L$, bir shift ucu $S$, saat girişi ve $m$ bitlik çıkışlar. İşlevi:

- $L = 1$: paralel yükleme.
- $L = 0$, $S = 0$: sağa öteleme.
- $L = 0$, $S = 1$: sola öteleme.

Kaynak R2, hedef R1'dir. İki yazmaç da bu yapıdadır, saatleri ortaktır. Hoca kontrol işaretlerini şöyle verdi:

- $R1 \leftarrow sl\ R2$: R2 sola ötelenir ($\overline{L2} \cdot S2$) ve R1'e yükleme yapılır ($L1$).
- $R1 \leftarrow sr\ R2$: R2 sağa ötelenir ($\overline{L2} \cdot \overline{S2}$) ve $L1$ ile R1'e yüklenir.

Bir öğrenci bu sırada kontrolün $L1$, $\overline{L2}$ ve $S2$ olması gerektiğini sordu; hoca bunun zaten yazılan şey olduğunu, $L1$'in R1'e yükleme olduğunu söyledi.

> **Ders sonrası not:** Derste anlatılan eş anlı atama kuralına göre, aynı saat kenarında R2 kendi içinde ötelenirken R1 R2'nin çıkışlarındaki **eski** (ötelenmemiş) değeri alır. Yani $L1$ ile $\overline{L2} \cdot S2$ aynı anda verilirse büyük olasılıkla $R1 \leftarrow R2,\ R2 \leftarrow sl\ R2$ gerçekleşir. $R1 \leftarrow sl\ R2$ için ya iki adım gerekir (önce R2 ötelenir, sonraki kenarda R1'e yüklenir), ya da R2'nin çıkışları R1'in girişlerine bir bit kaydırılarak bağlanmalıdır.

Hoca bu datapath'in de sınırlı olduğunu söyledi: R1'in ötelenmiş hâli R2'ye atanamaz, hedef ve kaynak sabittir. Bunu genelleştirmenin bir yolu MUX kullanmaktır.

## 12. MUX ile Kaynak Seçimi ve Genelleştirme

### 12.1 İki kaynaktan bir hedefe

Kitaptaki şekilde (ekrandan, 01:55:00) R2 4 bitlik yolla 2'ye 1 MUX'un 0 girişine, R1 1 girişine bağlıdır. MUX çıkışı R0'ın girişine gider. MUX'un seçim ucunu $K1$ sürer. R0'ın load ucuna $K1$ ile $K2$'nin OR'u bağlıdır. Saatler ortaktır.

- $K1 = 0$: R2 seçilir. $K1 = 1$: R1 seçilir.
- $K2 = 1$ olunca yükleme yapılır. $K1 = 1$ olması da OR üzerinden yüklemeyi tetikler.

Böylece R0'a R2 ya da R1 atanabilir: $K1: R0 \leftarrow R1$ ve $\overline{K1}K2: R0 \leftarrow R2$. Hoca bu kontrolün biraz gevşek bir kontrol olarak düşünülebileceğini söyledi.

**Soru (bir öğrenci sordu):** Bu MUX örneği yalnız bir yazmacın değerini doğrudan R0'a mı aktarıyor, başka bir işlem yapıyor mu? **Cevap:** Başka işlemi yoktur; kaynak seçimi MUX üzerinden yapılır.

### 12.2 Genelleştirilmiş MUX

Lojik datapath'te de MUX kullanılmıştı. Bu genelleştirilirse çok geniş bir MUX düşünülür. Bazı girişlerine yazmaçlar ($R0, \ldots, Rn$) doğrudan, bazılarına aritmetik işlemler ($R1 + R2$, $R1 - R2$), bazılarına lojik işlemler ($\overline{R2}$, $R1 \vee R2$, $R1 \oplus R2$) bağlanır. Aritmetik ve lojik girişlerin arkasında **adanmış kombinasyonel lojik** (dedicated combinational logic) vardır: toplayıcı-çıkarıcı, kapı dizileri, öteleyiciler. Böylece yazmaçları doğrudan aktarma, aritmetik ve lojik işlemden geçirip aktarma tek MUX üzerinden seçilir.

0'dan $K-1$'e kadar $K$ işlem varsa MUX seçim uçları bunları seçer, ayrı bir kontrol ($K2$ benzeri) hedefe yüklemeyi yönetir. Kontrol işaretleri bu mantıkla üretilir. Bu, MUX yapılı atamanın en genel hâlidir.

## 13. Dolaylı Adresleme ve Donanım Karmaşıklığı

**Soru (bir öğrenci sordu):** Dersin başında bellek adresine erişim için yazmacın köşeli parantez içinde yazıldığı gösterim vardı. Önceki derslerde yalnız bazı yazmaçların bu şekilde kullanılabildiği görülmüştü. Bu donanımdan mı, bağlantı biçiminden mi kaynaklanır; her tasarlanan yazmaç adres erişimi için kullanılabilir mi?

**Cevap:** Bu tamamen tasarıma bağlıdır. Örneğin 8086'da dolaylı adresleme için yalnız SI, DI, BP ve BX gibi yazmaçlar kullanılabiliyordu. Her yazmacın dolaylı adreslemede kullanılabilmesi donanım karmaşıklığını artırır. Adres değerini belirleyen ara yazmaca giden datapath'in tanımlanması gerekir. Tasarım ne kadar karmaşıklığa izin veriyorsa o kadar yazmaç kullanılır. Komuttan gelen sabit bir adres de ek karmaşıklıktır. 8086'da `MOV AX, [100H]` komutunda 100H komutla gelir; komuttan çözümleyip adres olarak kullanmak ekstra donanım ister. Daha basit bir tasarımda işlem ikiye bölünür: önce bir yazmaca 100H yüklenir, sonra o yazmaçla dolaylı adresleme yapılır. Karmaşıklık azalır ama işlem iki adımda yapılır.

## 14. Ötelemeli Yazmaçlar

### 14.1 Seri girişli ötelemeli yazmaç

Kaskat bağlı D flip-flop'lardan oluşur (ekrandan, 02:10:00). Seri giriş (SI) ilk flip-flop'un D'sine, her flip-flop'un çıkışı bir sonrakinin D'sine bağlıdır, son çıkış seri çıkıştır (SO). Saatler ortaktır. Sembol SRG 4'tür: Clock, SI ve SO uçları.

Yön, bitlerin nasıl adlandırıldığına bağlıdır:

- Bitler $Q_3Q_2Q_1Q_0$ olarak yazılıyken bir öteleme sonunda $S\,Q_3Q_2Q_1$ elde ediliyorsa bu **sağa öteleme**dir.
- Sonunda $Q_2Q_1Q_0\,S$ elde ediliyorsa bu **sola öteleme**dir; $Q_3$ kaybolur, $Q_0$'ın yerine dışarıdan gelen değer girer.

D flip-flop'ta her kenarda D'deki değer içeri kopyalanır. Her flip-flop'un girişinde bir öncekinin çıkışı hazır bekler ve kenarda hepsi eş anlı kopyalanır. Ötelemeli yazmacın mantığı budur.

### 14.2 Paralel yüklemeli ötelemeli yazmacın analizi

Kitaptaki devrede (ekrandan, 02:15:00) Shift, Load ve Serial input girişleri, $D_0$-$D_3$ paralel girişleri ve dört D flip-flop vardır. Her flip-flop'un önünde üç AND kapısı ve bir OR kapısı bulunur. SI, $Q_0$'ı besler; $Q_0$, $Q_1$'i; $Q_1$, $Q_2$'yi; $Q_2$ de $Q_3$'ü besler. Sembol SHR 4'tür.

Hoca devreyi analiz ederek fonksiyon tablosunu çıkardı:

- **Shift = 0, Load = 1:** Durumu koruyan AND kapılarına 0, paralel giriş kapılarına 1 gelir; öteleme kapıları Shift = 0 olduğu için kapalıdır. Her flip-flop'a kendi $D_i$'si gelir: **paralel yükleme**, $Q = D$.
- **Shift = 0, Load = 0:** Paralel giriş ve öteleme kapıları kapanır, durumu koruyan kapılar açılır. Her flip-flop kendi çıkışını geri alır: **durumu koru**, $Q = q$.
- **Shift = 1, Load = 0:** Yalnız öteleme kapıları açıktır. $Q_0 \leftarrow SI$, $Q_1 \leftarrow Q_0$, $Q_2 \leftarrow Q_1$, $Q_3 \leftarrow Q_2$: **öteleme**.
- **Shift = 1, Load = 1:** Shift 1 olduğu için diğer kapılar yine kapanır, aynı öteleme yapılır.

Fonksiyon tablosu:

| Shift | Load | İşlem |
|---|---|---|
| 0 | 0 | Durumu koru |
| 0 | 1 | Paralel yükleme |
| 1 | X | Öteleme ($Q_0 \leftarrow SI$, $Q_{i} \leftarrow Q_{i-1}$) |

Hoca, tahtaya $Q_3Q_2Q_1Q_0 \to Q_2Q_1Q_0S$ yazarak bir sola öteleme işlevi olduğunu söyledi. Fonksiyon tablosunu yazarken ise bu işlevi "sağ öteleme" olarak adlandırdı.

> **Ders sonrası not:** Bu devrede bilgi $SI \to Q_0 \to Q_1 \to Q_2 \to Q_3$ yönünde kayar. Hocanın 14.1'de verdiği adlandırmaya göre ($Q_3Q_2Q_1Q_0$ yazılışında sonuç $Q_2Q_1Q_0S$ ise sola öteleme) bu sola, yani yüksek anlamlı bite doğru ötelemedir. "Sağ öteleme" adı şekildeki sıraya ($Q_0$ üstte) göre verilmiş olmalıdır. Kitap bu işlemi büyük olasılıkla "shift down" (Q0'dan Q3'e doğru) diye adlandırır. Yönü adlandırırken hangi bit sırasının kullanıldığını belirtmek gerekir.

### 14.3 Tersten: tasarım sorusu

Aynı örnek tasarım sorusu olarak da sorulabilir: "Verilen fonksiyon tablosunu gerçekleyen 4 bitlik paralel yüklemeli, ötelemeli yazmacı D flip-flop ve lojik kapılarla tasarlayın." Bu durumda:

1. Girişler belirlenir: $D_0$-$D_3$, seri giriş SI, Shift, Load ve mevcut durumlar $Q_3$-$Q_0$.
2. Bütün olası satırlar yazılır, her satır için sonraki durum fonksiyon tablosundan hesaplanır.
3. D flip-flop kullanıldığı için her flip-flop'un D girişi sonraki durumun aynısıdır.
4. Her D girişi bütün girişler cinsinden fonksiyon olarak yazılır ve sadeleştirilir.

En sade hâl, analizi yapılan devrenin kendisidir.

### 14.4 MUX'lu bit dilimi ile sağa-sola ötelemeli, paralel yüklemeli yazmaç

Karmaşık lojik fonksiyonlar yerine her bit dilimi (bit slice) için bir 4'e 1 MUX kullanılarak işlev genişletilebilir (ekrandan, 02:25:00). $i$. dilimde MUX'un girişleri: 0'a $Q_i$, 1'e $Q_{i-1}$, 2'ye $Q_{i+1}$, 3'e $D_i$ bağlıdır. Bütün MUX'ların $S_1$ uçları ortaklanır, $S_0$ uçları ortaklanır; böylece her dilimde aynı işlem yapılır.

| $S_1$ | $S_0$ | İşlem |
|---|---|---|
| 0 | 0 | $Q_i \leftarrow Q_i$: durumu koru |
| 0 | 1 | $Q_i \leftarrow Q_{i-1}$: sola öteleme (hocanın adlandırması) |
| 1 | 0 | $Q_i \leftarrow Q_{i+1}$: sağa öteleme (hocanın adlandırması) |
| 1 | 1 | $Q_i \leftarrow D_i$: paralel yükleme |

Özel durumlar en düşük ve en yüksek anlamlı dilimlerdedir. $Q_0$'ın MUX'unda 1 numaralı girişe sola öteleme seri girişi (LSI), en yüksek anlamlı dilimde 2 numaralı girişe sağa öteleme seri girişi (RSI) bağlanır. Sembol SHR 4: Clock, Mode $S_1$, Mode $S_0$, LSI, $D_0$-$D_3$, RSI ve $Q_0$-$Q_3$. Hoca bunun kısa sınavda elde edilen çözüme benzediğini hatırlattı.

<!-- BELİRSİZ: Altyazıda en yüksek anlamlı dilim için de "iki numaralı girişinde write input" geçiyor; bu büyük olasılıkla "right input" (RSI) ve en yüksek anlamlı dilimin MUX'una aittir. -->

## 15. Sayıcıların Hatırlatılması

### 15.1 Ripple (asenkron) sayıcı

Kitaptaki şekilde (ekrandan, 02:30:00) her D flip-flop'un $\overline{Q}$ çıkışı kendi D girişine bağlıdır, bu yüzden her saat kenarında durum değiştirir (toggle). İlk flip-flop'un saatine yüksek frekanslı saat darbesi verilir. Sonraki her flip-flop'un saati bir öncekinin çıkışına bağlıdır. Reset uçları ortaktır.

- $Q_0$ her saat darbesinde değişir: 0, 1, 0, 1, ...
- $Q_1$ iki darbede bir değişir: 0, 0, 1, 1, ...
- $Q_2$ dört darbede bir, $Q_3$ sekiz darbede bir değişir.

$Q_3Q_2Q_1Q_0$ okunduğunda 0, 1, 2, ..., 15 sayılır, 15'ten sonra 0'a dönülür. Bu dizi python ile kontrol edildi. Saatin nereden alındığına (Q ya da $\overline{Q}$) ve yükselen ya da düşen kenara göre yukarı ya da aşağı sayıcı elde edilir. T veya JK flip-flop kullanılırsa girişlerin nasıl ayarlanacağı önceki bir derste görülmüştü.

### 15.2 0-9 arası sayan yüklemeli sayıcı

Yüklemeli senkron sayıcıda Count = 1 iken sayma 0'dan başlar. $Q_3$ ile $Q_0$'ın ilk kez birlikte 1 olduğu an 1001, yani 9'dur. Bu anda load ucuna 1 gelir ve sonraki kenarda 0 yüklenir. Sayıcı 0 ile 9 arasında sayar. Dizi python ile kontrol edildi.

<!-- BELİRSİZ: Bu sayıcı şeklinin karesi yok; devre ayrıntısı (AND kapısının girişleri, D girişlerine 0 verilmesi) altyazıdan çıkarıldı. -->

Hoca keyfi değerler arasında sayan sayıcıyı ve kullanılmayan durumlardan sayma çevrimine geri dönüşü sordu. Sınıftan, 1-5 arası sayan senkron sayıcının önceki bir derste tasarlandığı cevabı geldi; hoca bu yüzden konunun üzerinde durmadı.

## 16. Yazmaçlar Arası Transfer Yapıları: Adanmış MUX, Tek Bus, Üç Durumlu Bus

Amaç herhangi bir yazmaçtan diğerlerine veri aktarabilmek, yazmaçları hem kaynak hem hedef olarak olabildiğince geniş biçimde kullanabilmektir. Kitapta üç yaklaşım vardır (ekrandan, 02:35:00).

### 16.1 Adanmış MUX'lar (dedicated multiplexers)

Her yazmacın önünde kendisine ait bir $n$ bitlik 2'ye 1 MUX vardır. R0'ın MUX'una R1 ve R2, R1'in MUX'una R0 ve R2, R2'nin MUX'una R0 ve R1 bağlıdır. Her MUX'un kendi seçim ucu ($S0$, $S1$, $S2$) ve her yazmacın kendi load ucu ($L0$, $L1$, $L2$) vardır. Derste kullanılan bağlantıya göre R0'ın MUX'unda R1 1 kanalında, R1'in MUX'unda R0 0 kanalında, R2'nin MUX'unda R0 0 kanalında ve R1 1 kanalındadır.

Örnekler:

- $R0 \leftarrow R1$: $S0 = 1$, $L0 = 1$; $L1 = L2 = 0$. MUX'lar kombinasyonel olduğu için R1 değeri R0'ın girişinde kenardan önce hazırdır; kenar gelince yüklenir.
- $R0 \leftarrow R1,\ R2 \leftarrow R1$: Bir öğrenci L2'yi ve S2'yi 1 yapmayı önerdi; hoca doğruladı. $S0 = 1$, $L0 = 1$, $S2 = 1$, $L2 = 1$, $L1 = 0$. Aynı kaynak eş anlı iki atamada kullanılabilir.
- $R0 \leftarrow R1,\ R1 \leftarrow R0$ (takas): $S0 = 1$, $L0 = 1$, $S1 = 0$, $L1 = 1$, $L2 = 0$. Eş anlı atama olduğu için değerler takas edilir.
- $R0 \leftarrow R0$ ya da $R0 \leftarrow f(R0)$: Yapılamaz. Her yazmacın MUX'unda yalnız diğer yazmaçlar vardır. MUX genişletilip örneğin bir girişe $\overline{R0}$ verilseydi yapılabilirdi.
- $R0 \leftarrow R1,\ R2 \leftarrow R0$ (farklı kaynaklardan farklı hedeflere): Yapılabilir. $S0 = 1$, $L0 = 1$, $S2 = 0$, $L2 = 1$, $L1 = 0$; $S1$'in değeri önemsizdir. Hoca önce $S2 = 1$ dedi, sonra R0'ın R2'nin MUX'unda 0 kanalında olduğunu görüp $S2 = 0$ olarak düzeltti.

### 16.2 Tek bus (single bus)

Adanmış MUX'lara üç girişli MUX verilip her birine R0, R1, R2 bağlansaydı bütün MUX'ların girişleri aynı olurdu. O zaman üç MUX tek bir MUX'ta birleştirilebilir. Bu tek bus yapısıdır: bir 3'e 1 MUX'un çıkışı ortak bus'ı sürer, bus bütün yazmaçların girişine gider. MUX'un 0 girişine R0, 1'e R1, 2'ye R2 bağlıdır. Seçim uçları artık yazmaç başına değil, ortaktır; her yazmacın load ucu ayrıca vardır.

> **Ders sonrası not:** Hoca seçim ucu sayısını "yazmaç sayısının $\log_2$'si, aşağı yuvarlanmış" diye söyledi. Doğrusu yukarı yuvarlamadır: $\lceil \log_2(\text{yazmaç sayısı}) \rceil$. Üç yazmaç için $\lceil \log_2 3 \rceil = 2$ seçim ucu gerekir; şekilde de $S_1$, $S_0$ vardır.

Örnekler (ekrandan, 02:45:00):

- $R0 \leftarrow R1$: $S_1S_0 = 01$ (R1 bus'a çıkar), $L0 = 1$, $L1 = 0$, $L2 = 0$.
- $R0 \leftarrow R1,\ R2 \leftarrow R1$: $S_1S_0 = 01$, $L0 = 1$, $L2 = 1$, $L1 = 0$. Tek kaynaktan birden çok hedefe atama yapılabilir.
- $R0 \leftarrow R0$: $S_1S_0 = 00$ (R0 bus'a çıkar), $L0 = 1$, $L1 = L2 = 0$. Kendi üzerine yükleme desteklenir.
- $R0 \leftarrow R1,\ R2 \leftarrow R0$: Yapılamaz. Eş anlı atamada bus'taki değer bütün yazmaçlara ortaktır, aynı anda iki farklı kaynak bus'a çıkamaz.

### 16.3 Karşılaştırma

| Özellik | Adanmış MUX | Tek bus |
|---|---|---|
| Bir kaynaktan birden çok hedefe eş anlı atama | Var | Var |
| Yazmacın kendi üzerine atanması | Yok (bu basit hâlde) | Var |
| Farklı kaynaklardan farklı hedeflere eş anlı atama | Var | Yok |
| Seçim uçları | Her yazmaca ayrı | Ortak |

### 16.4 Üç durumlu tamponlu bus

Adanmış MUX'lar yerine, her yazmacın Q çıkışı ve data in girişi üç durumlu tamponlarla (tri-state buffer) tek bir bus'a bağlanabilir. Tamponların enable uçları kontrol edilerek aynı bus hem giriş hem çıkış yönünde kullanılır. Bu, ortak bus'lı MUX yapısının bir ileri aşamasıdır.

## 17. Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): Load ucu $L$, paralel giriş $D_i$ ve mevcut durumu $q$ olan bir yazmaç dilimi için $L = 1$ iken $D_i$ yüklenen, $L = 0$ iken durum korunan D flip-flop girişini bulun.

> **Çözüm:** Sonraki durum $L = 0$ satırlarında $q$, $L = 1$ satırlarında $D_i$'dir. D sütunu ($L, D_i, q$ sırasıyla) 0, 1, 0, 1, 0, 0, 1, 1 olur. Karnaugh haritasından $D = \overline{L}\,q + L\,D_i$.

**Soru 2** (derste sözlü, 00:40:17): $K1: R2 \leftarrow R1$ yapısında datapath neresidir?

> **Çözüm:** R1'in çıkışlarını R2'nin girişlerine bağlayan $n$ bitlik veri yolu.

**Soru 3** (derste sözlü, 01:08:45): Tablo 7-3'teki aritmetik mikro işlemlerin hepsini tek bir blokla, uygun kontrolle gerçeklemek için hangi kombinasyonel blok gerekir?

> **Çözüm:** Y girişleri seçim ucuyla XOR'lanan ve aynı ucun elde girişine verildiği $n$ bitlik toplayıcı-çıkarıcı.

**Soru 4** (derste sözlü, 01:23:40): 8 bitlik ikiye tümleyen gösteriminde $-1$ nedir?

> **Çözüm:** $11111111_2 = FFH$.

**Soru 5** (ekrandan, 01:35:00): R1 X'e, R2 Y'ye bağlı, çıkışı R0'a giden toplayıcı-çıkarıcı datapath'inde (kontroller L0, L1, L2, AS) şu işlemler için kontrol adımlarını yazın: $R0 \leftarrow R1 + R2$, $R0 \leftarrow \overline{R2}$, $R0 \leftarrow -R2$, $R0 \leftarrow R1 - R2$, $R0 \leftarrow R1 + 1$, $R0 \leftarrow R1 - 1$.

> **Çözüm:**
>
> - $L0 \cdot \overline{AS}: R0 \leftarrow R1 + R2$
> - $L1: R1 \leftarrow FFH$; sonra $L0 \cdot AS: R0 \leftarrow \overline{R2}$
> - $L1: R1 \leftarrow 0$; sonra $L0 \cdot AS: R0 \leftarrow \overline{R2} + 1$
> - $L0 \cdot AS: R0 \leftarrow R1 + \overline{R2} + 1$
> - $L2: R2 \leftarrow 1$; sonra $L0 \cdot \overline{AS}: R0 \leftarrow R1 + 1$
> - $L2: R2 \leftarrow 1$; sonra $L0 \cdot AS: R0 \leftarrow R1 - 1$

**Soru 6** (derste sözlü, 01:37:32): Aynı datapath ile $R0 \leftarrow \overline{R1}$, $R0 \leftarrow -R1$, $R1 \leftarrow R0 - R2$, $R0 \leftarrow R2 - R1$ yapılabilir mi?

> **Çözüm:** Hiçbiri yapılamaz. X kanalında tümleme yoktur, R1 işleme hep artı işaretle girer. Ayrıca yalnız R0 hedef, yalnız R1 ve R2 kaynak olabilir.

**Soru 7** (ekrandan, 01:45:00): NOT, AND, OR, XOR işlemlerini R0'a yazan datapath'i kurun ve her işlemin kontrol işaretlerini yazın.

> **Çözüm:** R1 ve R2'den beslenen $m$ bitlik NOT (yalnız R1), AND, OR, XOR dizileri 4'e 1 MUX'un 0-3 girişlerine bağlanır. $L0\,\overline{S_1}\,\overline{S_0}: R0 \leftarrow \overline{R1}$; $L0\,\overline{S_1}\,S_0: R0 \leftarrow R1 \wedge R2$; $L0\,S_1\,\overline{S_0}: R0 \leftarrow R1 \vee R2$; $L0\,S_1\,S_0: R0 \leftarrow R1 \oplus R2$.

**Soru 8** (ekrandan, 01:50:00): Kaynağı R2 = 10011110 olan sola öteleme ve kaynağı R2 = 11100101 olan sağa ötelemenin sonucu nedir?

> **Çözüm:** $sl$: 00111100. $sr$: 01110010.

**Soru 9** (ekrandan, 02:15:00): Şekildeki 4 bitlik paralel yüklemeli ötelemeli yazmacı analiz edip fonksiyon tablosunu çıkarın.

> **Çözüm:** Shift = 0, Load = 0: durumu koru; Shift = 0, Load = 1: paralel yükleme; Shift = 1, Load = X: $Q_0 \leftarrow SI$, $Q_i \leftarrow Q_{i-1}$ ötelemesi (yön adlandırması için 14.2'deki nota bakın).

**Soru 10** (derste sözlü, 02:20:45): Bu fonksiyon tablosunu gerçekleyen 4 bitlik paralel yüklemeli ötelemeli yazmacı D flip-flop ve lojik kapılarla tasarlayın.

> **Çözüm (derste verilmedi):** Derste yalnız yöntem anlatıldı ve sonucun analiz edilen devre olduğu söylendi. Fonksiyon tablosundan her dilim için $D_i = \text{Shift}\cdot Q_{i-1} + \overline{\text{Shift}}\cdot \text{Load}\cdot D_i + \overline{\text{Shift}}\cdot\overline{\text{Load}}\cdot Q_i$ bulunur; $Q_{-1}$ yerine SI kullanılır. Bu, her flip-flop önündeki üç AND ve bir OR kapısına karşılık gelir. Denklemler bütün giriş ve durum kombinasyonları için python ile kaba kuvvetle doğrulandı.

**Soru 11** (ekrandan, 02:35:00): Adanmış MUX yapısında şu atamaların kontrol işaretlerini yazın: $R0 \leftarrow R1$; $R0 \leftarrow R1,\ R2 \leftarrow R1$; $R0 \leftarrow R1,\ R1 \leftarrow R0$; $R0 \leftarrow R0$; $R0 \leftarrow R1,\ R2 \leftarrow R0$.

> **Çözüm:** $S0 = 1, L0 = 1, L1 = L2 = 0$. $S0 = 1, L0 = 1, S2 = 1, L2 = 1, L1 = 0$. $S0 = 1, L0 = 1, S1 = 0, L1 = 1, L2 = 0$. $R0 \leftarrow R0$ yapılamaz. Son atama $S0 = 1, L0 = 1, S2 = 0, L2 = 1, L1 = 0$ ile yapılır.

**Soru 12** (ekrandan, 02:45:00): Aynı atamaları tek bus yapısında yapmaya çalışın.

> **Çözüm:** $R0 \leftarrow R1$: $S_1S_0 = 01$, $L0 = 1$, $L1 = L2 = 0$. $R0 \leftarrow R1,\ R2 \leftarrow R1$: $S_1S_0 = 01$, $L0 = L2 = 1$, $L1 = 0$. $R0 \leftarrow R0$: $S_1S_0 = 00$, $L0 = 1$, $L1 = L2 = 0$. $R0 \leftarrow R1,\ R2 \leftarrow R0$ yapılamaz, çünkü bus'a aynı anda tek kaynak çıkabilir.

**Soru 13** (derste sözlü, 02:31:23): $Q_3$ ve $Q_0$ birlikte 1 olduğunda 0 yükleyen 4 bitlik yüklemeli sayıcı hangi aralıkta sayar?

> **Çözüm:** 0'dan 9'a (1001'de yükleme etkinleşir, sonraki kenarda 0 yüklenir).

## Dersin Toparlaması

Bu derste paralel yüklemeli yazmaçtan başlanarak yazmaç seviyesinde işlemler formal olarak ele alındı. Yükleme kontrolünün saati kapılayarak değil D girişini değiştirerek yapılması gerektiği gösterildi. Kontrol birimi ile datapath ayrımı yapıldı ve RTL gösterimi tanıtıldı. RTL'de en önemli nokta eş anlı atamanın sıralı atamadan farklı olması, aynı saat kenarında yapılan atamaların değerleri takas edebilmesidir. Aritmetik, lojik ve öteleme mikro işlemleri için özel datapath'ler kuruldu. Bir datapath'in hangi işlemleri yapabileceğini bağlantı yapısının belirlediği görüldü. Kaynak ve hedef seçiminde esneklik için MUX kullanıldı. Adanmış MUX, tek bus ve üç durumlu tamponlu bus yapıları karşılaştırıldı.

Bu yapılar, ilerleyen derslerde tasarlanacak register file ve tek çevrimli CPU'nun temelini oluşturur. Kaynak ve hedef yazmaçların adresle seçildiği register file, burada görülen bus ve MUX mantığının genelleştirilmiş hâlidir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
