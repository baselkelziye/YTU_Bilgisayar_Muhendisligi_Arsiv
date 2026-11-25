# Ders 12 Genişletilmiş Notu: Makale Tartışması: Zipf, Güç Yasası ve Pareto, Google Dosya Sistemi, MapReduce ve RAID

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Biçimi
- 2. Zipf Yasası, Güç Yasası ve Pareto Dağılımı
- 3. Google File System (GFS)
- 4. MapReduce
- 5. RAID: Ucuz Disklerden Yedekli Diziler
- 6. Örnek Sorular

## 1. Dersin Biçimi

Bu ders de önceki haftalardaki gibi bir makale tartışmasıydı. Öğrenciler haftanın makalelerini önceden okumuştu. Hoca her makale için sorular sordu, söz isteyenlere el kaldırma sırasıyla söz verdi, cevapları değerlendirdi ve çoğu zaman makaledeki asıl cümleyi sesli okuyarak doğru cevabı kendisi tamamladı. Tartışma Türkçe ve İngilizce karışık yürüdü; hoca İngilizce konuşan öğrencilere soruyu İngilizce tekrarladı.

Bu derste dört makale konuşuldu:

- Zipf yasası, güç yasası (power law) dağılımı ve Pareto dağılımını karşılaştıran kısa bir sıralama makalesi
- Google File System (GFS)
- MapReduce (listede 29 numara)
- RAID, "Redundant Arrays of Inexpensive Disks" (listede 30 numara)

Kayıtta ekran paylaşımı yoktu; görüntüde yalnız o anda konuşan kişinin adı görünüyordu. Bu yüzden not altyazıdan hazırlandı. Hocanın makalelerden okuduğu cümleler İngilizce korunmuştur.

> **Ek bilgi (derste anlatılmadı):** Derste makalelerin tam başlıkları okunmadı. İlk makale büyük olasılıkla Lada Adamic'in "Zipf, Power-laws, and Pareto – a ranking tutorial" adlı yazısıdır. GFS makalesi büyük olasılıkla Ghemawat, Gobioff ve Leung'un 2003 tarihli "The Google File System", MapReduce makalesi Dean ve Ghemawat'ın 2004 tarihli "MapReduce: Simplified Data Processing on Large Clusters", RAID makalesi ise Patterson, Gibson ve Katz'ın 1988 tarihli "A Case for Redundant Arrays of Inexpensive Disks (RAID)" makalesidir.

## 2. Zipf Yasası, Güç Yasası ve Pareto Dağılımı

Hoca ilk makalenin "aslında çok basit" olduğunu ve birkaç tanım içerdiğini söyleyerek başladı.

### 2.1 Zipf yasası

İlk soru Zipf yasasının ne olduğuydu. Bir öğrenci önce yasayı "büyük olayların sık tekrar etmediği, sık karşılaşılan şeylerin ise büyük oranda sık olduğu" diye anlatmaya çalıştı, sonra makaledeki kelime örneğine geçti: büyük bir İngilizce metinde en sık görülen kelimeler "and", "or" gibi bağlaçlardır ve sıradaki kelimelere geçildikçe sıklık hızla düşer. Öğrencinin özetiyle, birinci sıradaki kelime ikinciden yaklaşık iki kat daha sık görülür.

Hoca bunu şöyle toparladı: karşımıza belli bir büyüklükle çıkan bir olayın bu büyüklüğü, büyüklük sıralamasındaki yeriyle ters orantılıdır. Ardından makaledeki tanımı okudu:

> "Zipf's law states that the size of the r'th largest occurrence of the event is inversely proportional to its rank."

Yani $r$. en sık görülen olayın sıklığı yaklaşık olarak $1/r$ ile orantılıdır. Hoca "the size of the r'th largest occurrence" ifadesini "the frequency of the r'th largest occurrence" diye açtı: $r$. en sık karşılaştığımız olayın sıklığı, sırasıyla ters orantılıdır. <!-- BELİRSİZ: 00:03:35'te bir öğrencinin "birinci sırada 1-10 oranında azalıyor" diye söylediği cümle altyazıda anlaşılmıyor. -->

### 2.2 "Büyüklük" ne demek?

Hoca "buradaki büyüklükten ne kastediliyor?" diye sordu. Öğrenciler "gerçekleşme sıklığı", "bir şeyin aşırı olma miktarı" ve "kelimenin internette kullanım sıklığı" cevaplarını verdi. Hoca makaledeki cümleyi okudu:

> "Size here denotes the frequency of use of the word in English text, and not the length of the word itself."

Yani büyüklük, o kelimenin İngilizce metinlerde kullanılma sıklığıdır; kelimenin üç harf mi beş harf mi olduğu önemli değildir. Hoca ayrıca makalede "frekans" teriminin bu "size" kavramından türetildiğini, ikisinin birbirinin tanımı gibi kullanıldığını belirtti. Yasanın adı da onu ortaya atan George Kingsley Zipf'ten gelir.

### 2.3 Güç yasası dağılımı ve Pareto

Hoca güç yasası dağılımı hakkında yorum istedi. Bir öğrenci makalenin üç kavramı birbirine benzettiğini ve genel tanımın "etkilerin kabaca %80'inin nedenlerin %20'sinden kaynaklanması" olduğunu söyledi. En büyük sıklığı yaratan, sıralamanın başındaki çok küçük bir kısımdır. Hoca Pareto'yu sorunca aynı öğrenci bunun zaten 80/20 oranı olduğunu belirtti ve internetteki bir örneği aktardı: İtalya'daki arazilerin %80'i nüfusun %20'sine aittir. Makalede ise web sitelerine tıklanma oranları örnek veriliyordu.

Hoca makaleden şu cümleyi okudu:

> "What is usually called a power law distribution tells us not how many people had an income greater than x, but the number of people whose income is exactly x."

Buradan üç kavramın farkını şöyle açıkladı:

- **Zipf:** $r$. sıradaki en büyük değeri (örneğin $r$. en yüksek geliri) sorar. Sıralamadaki yer ile büyüklük arasındaki ilişkidir.
- **Pareto:** $r$. sıradaki kazancı sormaz; kaç kişinin geliri $x$ değerinden fazladır, onu sorar. "$x$'ten fazla olanlar" bir toplam olduğu için bu bir **birikimli dağılım fonksiyonudur** (cumulative distribution function). Toplumda $x$'ten fazla kazanan genelde birden fazla kişi vardır; $x$ büyüdükçe bu sayı bire doğru azalır.
- **Güç yasası dağılımı:** $x$'ten büyük olanları değil, tam olarak $x$'e eşit olanları sayar. Bu yüzden bir **olasılık dağılım fonksiyonudur**: bir kişinin tam olarak $x$ gelire sahip olma olasılığı nedir, bunun dağılımı nasıldır? Bu dağılım, Pareto'nun birikimli dağılımına bağlıdır.

Hoca 80/20 örneğine dönerek, büyük çoğunluğun düşük bir oran tarafından elde tutulmasının bu dağılımların ortak resmi olduğunu söyledi.

### 2.4 Bu makale neden önemli?

Hoca bu üç kavramın neden önemli olduğunu ve bu makaleyi okumanın onlar için neden gerekli olduğunu sordu. Bir öğrenci, en çok tıklanan sitenin aslında herkes tarafından en çok tıklanan site hâline gelmesi örneğiyle bu istatistiklerin dikkate alınması gerektiğini söyledi.

Hoca cevabı genişletti: burada farklı sıralama (ranking) teknikleri söz konusudur ve bunlar sistem performansının ölçümünde doğrudan karşılık bulur:

- Gelen bir işi en hızlı ne kadar sürede bitirebiliyoruz? Bu bir sıralama sorusudur.
- Gelen işlerin kaçını $T$ süresinde ya da $T$'den daha kısa sürede bitiriyoruz? Bu Pareto'ya benzer ve Pareto ile ifade edilir.
- Bir işlemin (transaction) tam $T$ sürede tamamlanma olasılığı nedir? Bu güç yasası dağılımıyla ifade edilir.

> **Hocanın vurgusu:** Bu dağılımların bilişim dünyasında, özellikle performans ölçümünde ve sistemin cevap verme yeteneğinin değerlendirilmesinde çok önemli bir yeri vardır. Bunlardan birini kullanmak her zaman yeterli değildir; senaryoya ve değerlendirilecek kriterlere göre çoğu zaman birden fazlası birlikte kullanılır.

## 3. Google File System (GFS)

### 3.1 GFS nedir?

Bir öğrenci GFS'yi, Google'ın kendi iş yükleri ve büyük boyutlu dosyalarla yaptığı işlemler için geliştirdiği, normal dosya sistemleri bu ihtiyaçlara cevap vermediği için ortaya çıkan bir dosya sistemi olarak tanımladı.

### 3.2 Tasarım varsayımları

Hoca daha ayrıntılı bir soru sordu: Google bu dosya sistemini tasarlarken özellikle hangi özellikleri ön plana çıkardı, hangi varsayımlara dayandı? Bir öğrencinin cevabı şu maddeleri içeriyordu:

- Sistem çok sayıda kaynaktan ve bileşenden oluşur. Bunlardan birinin arızalanması doğal kabul edilir; bu yüzden arızaların izlenmesi ve yönetilmesi baştan tasarıma girer.
- Dosyalar (web nesnelerinden oluşan veriler) çok büyüktür; büyük alana ihtiyaç vardır.
- Dosyalar genelde ortasından değiştirilmez; sonuna ekleme (append) yapılır ya da okunur.
- Bu dosya sistemini kullanacak ortak bir API tasarlanması gerekir.

Başka bir öğrenci makalenin özetini (abstract) okudu. Hoca buna, makalenin özetini değil Google'ın böyle bir dosya sistemini tasarlarken kabul ettiği varsayımları sorduğunu söyleyerek cevap verdi.

### 3.3 Gecikme mi, bant genişliği mi?

Hoca, Google'ın bu tasarımda düşük gecikmeye (latency) mi yüksek bant genişliğine (bandwidth) mi önem verdiğini sordu. Cevap bant genişliğiydi, çünkü amaç büyük veriyi işlemektir. Hoca yüksek bant genişliğinin ne anlama geldiğini de sordurdu: veri topluca işlenebilir. Büyük veri ne kadar çok bir arada, bir bütün hâlinde ve yüksek hızda erişilip işlenebilirse Google o kadar fayda görür.

### 3.4 Neden tek master?

GFS'de tek bir master vardır. Hoca bunun nedenini sordu. İlk cevap "kontrolü kolay olduğu için" oldu. Hoca bunu yeterli bulmadı:

> **Hocanın vurgusu:** Her zaman her şey için tek bir şeyi kontrol etmek kolaydır; bunun arkasında başka bir gerekçe olması lazım, onu da söylemek gerekir.

Kabul edilen cevap şuydu: GFS'de bir master ve chunk'ların tutulduğu chunk sunucuları vardır. Chunk sunucuları arasındaki iletişim, chunk yerleşimi (chunk placement) ve kopyalar arasında seçim yapılması gibi kararlar için merkezi tek bir master olması işi ve tasarımı basitleştirir.

### 3.5 Okuma ve yazmada master araya giriyor mu?

Hoca, okuma ve yazma işlemlerinde masterın araya girip girmediğini sordu. Cevap: istemci hangi chunk sunucusuna gideceğini masterdan öğrenir, ama okuma ve yazmalar doğrudan chunk sunucusu üzerinden yapılır; master araya girmez. Bir öğrenci bunu makaledeki şu ifadeyle destekledi: istemci bu bilgiyi önbelleğe alır ve ardışık dosya işlemlerini masteri yeniden sormadan yürütür ("the client caches the information and executes consecutive file operations without requesting the master again").

### 3.6 Master çökerse ne olur?

Hoca makalenin, master sunucunun çökmesi durumunda ne olacağına cevap verip vermediğini sordu. Bir öğrenci masterın diskte günlük (log) tuttuğunu, bu günlüklerden yeniden yüklenebileceğini okuduğunu ama master için ikinci bir kopya görmediğini söyledi. Hoca günlük mekanizması konusunda öğrencinin haklı olduğunu belirtti: bu, bütün metadata değişikliklerinin günlüğüdür. Bir başka öğrenci ise masterın metadatayı bellekte tuttuğunu, bu yüzden belleğin büyük tutulması gerektiğini ve master için ayrı bir alternatif düşünülmediğini söyledi.

Hoca soruyu kopyalama (replication) tarafına çevirdi. Öğrencilerden cevap gelmeyince makalenin ilgili bölümlerini hatırlattı: replica placement, creation, re-replication, re-balancing ve garbage collection; ayrıca "High Availability" başlığı altında chunk replication ve master replication. Hoca öğrencilerin makalenin bu kısımlarına gelmemiş göründüğünü söyledi ve master replication bölümünü okudu:

> "The master state is replicated for reliability. Its operation log and checkpoints are replicated on multiple machines. A mutation to the state is considered committed only after its log record has been flushed to disk locally and on all master replicas."

Yani master tek olsa da durumu kaybolmaz: işlem günlüğü ve checkpoint'ler birden fazla makineye kopyalanır ve bir değişiklik, günlüğü hem yerelde hem bütün master kopyalarında diske yazılmadan kesinleşmiş sayılmaz.

### 3.7 Dosya sistemi mutasyonları

Hoca makaledeki "file namespace mutations are atomic" ifadesini sordu. Bir öğrenci önce bunun dosyayı değiştirmek anlamına geldiğini söyledi. Hoca "dosyayı mı, dosya sistemini mi? Dikkat et" diye uyardı. Öğrenci bunun chunk metadatası, yani dosyanın metadata bilgisiyle ilgili olduğunu söyledi. Hoca bir dosya sistemi mutasyonu örneği istedi. "Ad alanı (namespace)" cevabını tek başına yeterli bulmadı, "dosya sistemi ağacının yeniden oluşturulması" cevabına ise "o kadar karmaşık şeylere gitmeye gerek yok" dedi.

> **Hocanın vurgusu:** Mutasyon zaten değişiklik demektir. Yeni bir dosyanın oluşturulması, bir dosyanın silinmesi, yeniden adlandırılması, yani dosya sisteminde ya da bir dosyanın metadatasında ya da içeriğinde değişikliğe yol açan her şey bir mutasyondur. Bu çok basit bir kavramdır.

Ardından hoca bu mutasyonları kimin yaptığını sordu: chunk sunucuları mı, istemci mi, başkası mı? Bir öğrenci istemci tarafından yapılması gerektiğini, ama masterın kopyaları tuttuğu için bir chunk sunucusundaki değişikliğin diğer kopyalara da yansıması amacıyla işin içine girdiğini tahmin etti. Hoca makaledeki ifadeyi okudu: ad alanı mutasyonları masterın işidir; master ad alanı kilitlemesiyle (namespace locking) atomikliği ve doğruluğu garanti eder (makale bunun için 4.1 bölümüne yönlendiriyor) ve

> "The master's operation log defines a global total order of these operations."

Hoca bunu az önce konuşulan günlük mekanizmasına bağladı: işlemler masterda yapılır ve günlük bu işlemlerin sırasını belirler; ancak master sunucu tektir.

Bir öğrenci de makaleden şu bilgiyi okudu: yazılacak veri bir kopyadan diğerine doğrusal olarak aktarılarak aktarım hızı (throughput) en yüksek düzeye çıkarılır ve master sürekli çöp toplama (garbage collection) yapar.

## 4. MapReduce

### 4.1 MapReduce nedir?

Bir öğrenci MapReduce'u şöyle anlattı: büyük veri işlemede kullanılan bir yöntemdir. Kullanıcının tanımladığı Map ve Reduce fonksiyonları sayesinde dağıtık sistem üzerinde önce Map fonksiyonuyla anahtar-değer (key-value) çiftleri oluşturulur; bu işlem paralel yürür. Ardından yine kullanıcının tanımladığı Reduce fonksiyonuyla birleştirme (merge) yapılır. Böylece dağıtık sistemde veri işlemek yazılımcı için kolay bir hâle gelir. Hoca, Reduce işleminin aynı anahtar değerine sahip olanlar üzerinden yapıldığını teyit ettirdi: Reduce anahtar üzerinden toplar.

Aynı öğrenci yaklaşımın bir yararı olarak, konuyla ilgili fazla bilgisi olmayan yazılımcıların bile üst katmanda çalıştıkları için kolayca dağıtık yazılım geliştirebildiğini söyledi.

### 4.2 Makaledeki gerçek hayat örnekleri

Hoca yaklaşımın büyük veri üzerinde etkili olduğunu makalenin hangi gerçek hayat örnekleriyle gösterdiğini sordu ve her örnekte anahtarın ve değerin ne olduğunu tartıştırdı.

**Distributed grep.** Bir öğrenci grep'i "dosya arama" diye tanımladı. Hoca düzeltti:

> **Hocanın vurgusu:** grep, bir dosyanın ya da bir grup dosyanın içinde geçen bir kelimeyi veya düzenli ifadeyi (regular expression) aramaktır. Dosya adı aramak değildir; dosya adlarını bulmak find'ın işidir. İkisi de Unix dünyasından gelir.

Hoca bu durumda anahtarın aranan kelime (ya da düzenli ifade), değerin ise kelimenin bulunduğu dosyanın adı olduğunu sordurarak buldurdu. Öğrencinin ilk "değer frekanstır" cevabını kabul etmedi. Map aşamasında anahtar kelime üzerinden eşleme yapılır; Reduce sonunda, bütün dosyaları içeren büyük kümeden yalnız bu kelimenin ya da düzenli ifadenin geçtiği dosyalar kalır.

> **Ek bilgi (derste anlatılmadı):** MapReduce makalesinde distributed grep büyük olasılıkla biraz farklı tanımlanır: Map fonksiyonu verilen kalıba uyan satırı çıktıya verir, Reduce ise ara veriyi olduğu gibi çıktıya kopyalayan bir özdeşlik (identity) fonksiyonudur. Hocanın anahtar-değer yorumu, sonucu dosya adlarına göre toplamak isteyen bir uygulamaya karşılık gelir.

**Count of URL access frequency.** Anahtar URL, yani web sitesinin adı; değer ise sayıdır (o URL'ye kaç kez erişildiği). Hoca bu örnekte sayının doğrudan değer olduğunu onayladı.

**Reverse web-link graph.** Web adreslerinin bir graf olarak tutulup bağlantıların takip edilmesiyle ilgilidir. Hoca bunun bir hedefe hangi yollardan gelinebildiğini gösterdiğini, kullanıcı hareketlerini inceleyip buna göre reklam verme ve satış gibi alanlarda önemli olduğunu söyledi.

**Term vector per host.** Bir öğrenci bunu dokümanlardaki kelime sayılarını bulmak için terim vektörü çıkarılması olarak tanımladı. Hoca TF-IDF'i sordu; öğrenci "term frequency" açılımını verdi ve hoca terimin başka dokümanlarda geçme olasılığıyla birlikte değerlendirildiğini, bunun da MapReduce ile yapılabileceğini söyledi.

> **Ders sonrası not:** Öğrenci TF-IDF'i "Term Frequency, Inverse Term Frequency" diye açtı ve hoca onayladı; doğrusu "Term Frequency – Inverse Document Frequency"dir. IDF kısmı, terimin kaç farklı dokümanda geçtiğine dayanır.

**Inverted index.** Hoca bunun yukarıdaki örneklerden hangisine benzediğini sordu. Öğrenci URL erişim sıklığına benzediğini söyledi. Hoca, "ters" (inverted) olduğu için reverse web-link graph'a daha çok benzeyebileceğini düşündüğünü, ama öğrencinin dediğinin de doğru olduğunu belirtti.

**Distributed sort.** Hoca listedeki son örnek olarak bunu da andı.

> **Ek bilgi (derste anlatılmadı):** Makalede reverse web-link graph için Map büyük olasılıkla her kaynak sayfadaki bağlantı için ⟨hedef, kaynak⟩ çiftini üretir, Reduce ise ⟨hedef, kaynak listesi⟩ çıkarır. Inverted index'te de Map ⟨kelime, doküman kimliği⟩ üretir, Reduce ⟨kelime, doküman kimliği listesi⟩ çıkarır. Bu yüzden iki örnek aynı biçimdedir.

### 4.3 Hata toleransı ve altta varsayılan yapı

Hoca MapReduce'ta hata toleransının (fault tolerance) nasıl sağlandığını sordu. İki cevap geldi:

- Hata alan işlem yeniden çalıştırılabilir; böylece hatalı kısım aşılır.
- Bilgisayar arızalarından ya da veri kaybından doğan sorunlar için hesaplamalar fazladan (redundant) bilgisayarlarda tekrarlanır; biri arızalanırsa diğerinin sonucuyla işlem tamamlanır.

Hoca sonra MapReduce çalışırken altta hangi yapının var olduğunun varsayıldığını sordu. Bir öğrenci "commodity (sıradan, ucuz) donanım ve yazılım" dedi. Hoca bunu kabul etti ve bir adım önce incelenen GFS'yi hatırlattı: MapReduce GFS üzerinde çalışır ve GFS'nin atomiklik, yedeklilik (redundancy), güvenilirlik, yüksek bant genişliği ve kopya oluşturma özelliklerinden yararlanır.

## 5. RAID: Ucuz Disklerden Yedekli Diziler

### 5.1 RAID neden ortaya çıktı?

Listede 30 numaradaki makale "Redundant Arrays of Inexpensive Disks", yani RAID'dir. Hoca bunun neden oluşturulduğunu sordu. Bir öğrencinin cevabı:

- CPU ve bellek teknolojisi hızla gelişti ve hızlandı, ama G/Ç performansı geride kaldı.
- G/Ç için geliştirilen tek büyük pahalı diskler (single large expensive disk, SLED) kapasite olarak yeterliydi ama hız bakımından yetersiz kaldı.
- Makale pahalı diskler yerine çok sayıda ucuz disk kullanarak bu performans açığını kapatmayı hedefler.
- Farklı performans ve maliyet değerlerine sahip beş seviye tanımlanır.

Bir başka öğrenci de pahalı disklerin maliyeti yüzünden tercih edilmediğini, ucuz disklerle daha iyi bir sistemin nasıl kurulabileceğinin araştırıldığını ekledi.

### 5.2 Seviye 1: yansıtma

Hoca birinci seviyenin neye karşılık geldiğini sordu. Cevap: RAID 1, bir verinin aynı anda iki farklı diske yazılmasıdır, yani yansıtma (mirroring). Bu yöntemde kullanılabilir disk kapasitesi %50 düşer, yani disklerin yalnız yarısı veri için kullanılır; buna karşılık her veri iki kopya hâlinde durduğu için güvenilirlik artar.

### 5.3 Seviye 2 ile seviye 3 farkı

Hoca 2. ve 3. seviyeler arasındaki farkı sordu. Bir öğrenci İngilizce olarak 2. seviyenin hata düzeltme kodu (ECC) için Hamming kodu kullandığını, 3. seviyenin ise tek bir kontrol diski (single check disk per group) kullandığını söyledi. Hoca farkı biraz açmasını istedi ama cevabın devamı altyazıda anlaşılmıyor. Başka bir öğrenci farkı şöyle açıkladı: 3. seviyede bir grupta yalnız bir kontrol diski vardır; kontrol disklerinin payı yaklaşık %4 ile %10 arasındadır. Makaleye göre 3. seviye RAID, 2. seviye gibi çalışır, ama daha az kontrol diski gerektiği için disk başına etkin performans 3. seviyede daha yüksektir.

> **Ek bilgi (derste anlatılmadı):** 2. seviyede hangi diskin bozulduğunu bulmak için birden fazla Hamming kontrol diski gerekir. 3. seviyede ise disk denetleyicisi bozuk diski zaten bildirdiği için tek bir eşlik (parity) diski kaybolan veriyi yeniden kurmaya yeter. Kontrol diski payı grup boyutuna bağlıdır; makalede büyük olasılıkla 10 ve 25 diskli gruplar incelenir, bu da yaklaşık %10 ve %4 paya karşılık gelir.

### 5.4 Seviye 2 hangi iş yüküne uygun?

Hoca, 2. seviye RAID'in işlem (transaction) yoğun sistemler için mi yoksa yüksek hızlı işlem yapan süper bilgisayarlar için mi uygun olduğunu sordu. Bir öğrenci 2. seviyede küçük boyutlu G/Ç işlemlerinde performansın çok düştüğünü, büyük boyutlu G/Ç işlemlerinde ise çok daha iyi olduğunu, bu yüzden transaction işleme için uygun olmadığını söyledi. Buradan 2. seviyenin büyük ve ardışık veri işleyen süper bilgisayarlara uygun olduğu sonucu çıkar. <!-- BELİRSİZ: Öğrencinin küçük ve büyük G/Ç için verdiği verim yüzdeleri altyazıda "%6" ve "%60" diye geçiyor; değerler kesin değil. -->

Hoca makalenin geri kalan seviyelerini (4 ve 5) öğrencilerin kendilerinin incelemesini söyleyerek tartışmayı bitirdi.

## 6. Örnek Sorular

Bu derste ekranda soru gösterilmedi. Aşağıdaki sorular hocanın derste sözlü olarak sorduğu sorulardır.

**Soru 1** (derste sözlü, 00:01:50): Zipf yasası nedir? Buradaki "büyüklük" neyi ifade eder?

> **Cevap:** $r$. en sık görülen olayın sıklığı sırasıyla ($r$) ters orantılıdır. Büyüklük, kelimenin İngilizce metinlerde kullanılma sıklığıdır; kelimenin uzunluğu değildir.

**Soru 2** (derste sözlü, 00:09:21): Pareto dağılımı ile güç yasası dağılımı arasındaki fark nedir?

> **Cevap:** Pareto, değeri $x$'ten büyük olanların sayısını sorar; birikimli dağılım fonksiyonudur. Güç yasası, değeri tam $x$ olanların sayısını sorar; olasılık dağılım fonksiyonudur. Zipf ise $r$. sıradaki değeri sorar.

**Soru 3** (derste sözlü, 00:16:32): GFS tasarlanırken hangi varsayımlar yapılmıştır?

> **Cevap:** Bileşen arızaları olağandır; dosyalar çok büyüktür; dosyalar çoğunlukla sona ekleme ve okuma ile kullanılır; uygulamalarla birlikte tasarlanan bir API gerekir; düşük gecikme yerine yüksek ve sürekli bant genişliği önceliklidir.

**Soru 4** (derste sözlü, 00:20:52): GFS neden tek master kullanır? Okuma ve yazmada master araya girer mi?

> **Cevap:** Tek master, chunk yerleşimi ve kopyalama kararlarını merkezi bilgiyle verdiği için tasarımı basitleştirir. Okuma ve yazmada master araya girmez; istemci chunk konumunu masterdan alıp önbelleğe alır ve veriyi doğrudan chunk sunucusuyla alışverişe sokar.

**Soru 5** (derste sözlü, 00:25:02): "File namespace mutations are atomic" ne demektir? Bir dosya sistemi mutasyonu örneği verin. Bu mutasyonları kim yapar?

> **Cevap:** Dosya oluşturma, silme, yeniden adlandırma gibi dosya sisteminde ya da metadatada değişikliğe yol açan işlemler mutasyondur. Bunları master yapar; ad alanı kilitlemesi atomikliği sağlar ve masterın işlem günlüğü işlemlerin global toplam sırasını belirler.

**Soru 6** (derste sözlü, 00:23:17): Master sunucu çökerse ne olur?

> **Cevap:** Masterın işlem günlüğü ve checkpoint'leri birden fazla makineye kopyalanır; bir değişiklik günlüğü yerelde ve bütün master kopyalarında diske yazıldıktan sonra kesinleşir. Böylece master durumu kaybolmaz.

**Soru 7** (derste sözlü, 00:39:03): Distributed grep'te ve URL erişim sıklığı sayımında anahtar ve değer nedir?

> **Cevap:** Hocanın anlatımıyla distributed grep'te anahtar aranan kelime ya da düzenli ifade, değer kelimenin geçtiği dosyanın adıdır. URL erişim sıklığında anahtar URL, değer erişim sayısıdır.

**Soru 8** (derste sözlü, 00:43:45): MapReduce'ta hata toleransı nasıl sağlanır? MapReduce altta neyin var olduğunu varsayar?

> **Cevap:** Hata alan işler yeniden çalıştırılır. MapReduce altta GFS'yi ve ucuz (commodity) donanımı varsayar; GFS'nin kopyalama, güvenilirlik ve yüksek bant genişliği özelliklerinden yararlanır.

**Soru 9** (derste sözlü, 00:48:39): RAID 1 neye karşılık gelir? RAID 2 ile RAID 3 arasındaki fark nedir?

> **Cevap:** RAID 1 yansıtmadır, kapasitenin yarısı kopyaya gider. RAID 2 hata düzeltme için Hamming kodu ve birden fazla kontrol diski kullanır; RAID 3 bir grup için tek kontrol (parity) diski kullanır, bu yüzden disk başına etkin performansı daha yüksektir.

**Soru 10** (derste sözlü, 00:50:44): RAID 2 işlem (transaction) yoğun sistemlere mi, süper bilgisayarlara mı uygundur?

> **Cevap:** Küçük G/Ç işlemlerinde verimi çok düştüğü için transaction işlemeye uygun değildir; büyük veri işleyen süper bilgisayarlara uygundur.

## Dersin Toparlaması

Bu derste dört makale üzerinden büyük ölçekli sistemlerin temel yapı taşları konuşuldu. Zipf, güç yasası ve Pareto makalesi, aynı olgunun üç farklı bakışını verdi: sıralamadaki yer, $x$'ten büyük olanların sayısı ve tam $x$ olanların olasılığı. Hoca bunları sistem performansının ölçülmesine bağladı ve doğru soruya göre doğru dağılımın, çoğu zaman birden fazlasının, seçilmesi gerektiğini vurguladı.

GFS, arızaların olağan olduğu, büyük dosyaların sona eklemeyle büyüdüğü ve bant genişliğinin gecikmeden önemli olduğu bir ortam için tasarlanmış tek masterlı bir dağıtık dosya sistemiydi; master veri yolunun dışında kalır, ad alanı mutasyonlarını sıraya koyar ve durumunu günlük ve checkpoint kopyalarıyla korur. MapReduce bu dosya sisteminin üzerinde, anahtar-değer çiftleriyle çalışan basit bir programlama modeliyle dağıtık hesaplamayı yazılımcıdan gizler. RAID ise G/Ç darboğazına ucuz disklerin yedekli dizileriyle cevap veren klasik çalışmadır; seviyeler arasındaki fark, yedekliliğin nasıl sağlandığı ve bunun hangi iş yüküne uygun olduğudur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
