# Ders 13 Çalışma Özeti

## Genel Konular

- Dersin tarihi 8 Haziran 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı. Dönemin son dersidir.
  - Asıl anlatım yaklaşık 00:05:00'te başlar. Ders iki arayla üç bölümden oluşuyor.
- Tekrar: $x + y$ ve $2x$ fonksiyonlarını hesaplayan Turing makineleri
  - Bundan sonra makineler büyüdüğü için durum diyagramı yerine yalnız sözde kod (pseudocode) verilecek.
- Örnek: karşılaştırma fonksiyonu
  - $f(x, y) = 1$ eğer $x > y$; $f(x, y) = 0$ eğer $x \le y$.
- Turing makinelerini birleştirme (combining Turing machines) ve blok diyagramları
  - Örnek: $f(x, y) = x + y$ eğer $x > y$; $0$ eğer $x \le y$.
- Turing tezi (Turing's thesis, Church-Turing tezi)
- Algoritmanın Turing makinesiyle tanımı
- Turing makinesi çeşitleri (variations)
  - Standart Turing makinesi modeli
  - Kalma seçenekli (stay-option), yarı sonsuz şeritli (semi-infinite tape), çok şeritli (multi-tape), çok boyutlu (multi-dimensional), deterministik olmayan (nondeterministic) Turing makineleri
- Makine sınıflarının gücü (power) ve eşdeğerlik tanımı
- Benzetim (simulation) yöntemi
- İspat: kalma seçenekli Turing makineleri standart Turing makineleriyle aynı güçtedir
- İspat: yarı sonsuz şeritli Turing makineleri standart Turing makineleriyle aynı güçtedir
  - Çok izli şerit hilesi (multiple track tape trick)
- Çok şeritli ve çok boyutlu Turing makineleri (ispatsız)
- Deterministik olmayan Turing makinesi, hesaplama ağacı, P ve NP sınıflarına kısa giriş
- Final duyurusu ve dönem kapanışı

## Hocanın Özellikle Vurguladığı Kısımlar

- Turing tezi önemlidir.
  - Mekanik yollarla yapılabilen her hesaplama bir Turing makinesiyle yapılabilir.
- "Algoritma nedir?" diye sorulursa iki cevap verebilmelisiniz.
  - Problemi çözen adımlar dizisi.
  - Problemi çözen bir Turing makinesi. Bir problem için algoritmanın var olması, o problemi çözen bir Turing makinesinin var olması demektir.
- Bu derste "Turing makinesi" denince standart model kastedilir.
  - İki yönde sonsuz şerit, tek okuma-yazma kafası, her adımda L ya da R hareketi, deterministik kontrol birimi.
- Bu derste "güç", bir makine sınıfının tanıyabildiği diller kümesidir.
- Bütün Turing makinesi çeşitleri standart Turing makinesiyle aynı güçtedir.
  - Daha güçlü görünseler de yeni bir dil tanıyamazlar.
- Eşdeğerlik ispatı her zaman iki adımlıdır.
  - 1\. sınıf 2. sınıfı benzetebilir.
  - 2\. sınıf 1. sınıfı benzetebilir.
- Deterministik olmayan Turing makinesi önemlidir.
  - Gücü aynıdır ama karmaşıklık sınıflarının (P, NP) tanımında kullanılır.
- Final:
  - Bütün dönem konuları finalde sorulabilir.
  - Büyük ihtimalle her zamanki gibi test olacak, 20'den fazla soru bekleniyor.
  - Tarih ve saat için final programına bakın. Hoca "gelecek salı, muhtemelen saat 9" dedi ama emin değildi.

## Kısa Tekrar Notları

- Karşılaştırma makinesi: $x$ ve $y$'nin 1'leri tek tek eşleştirilir. $x$'ten eşleşmemiş 1 kalırsa şerit silinir, 1 yazılır; kalmazsa şerit silinir, 0 yazılır.
- Blok diyagramında her blok bir Turing makinesidir: giriş alır, çıkış verir.
- Turing tezi: mekanik yollarla yapılan her hesaplama Turing makinesiyle yapılabilir.
- Algoritma: problemi çözen bir Turing makinesi.
- Aynı güç: 1. sınıftaki her $M_1$ için 2. sınıfta $L(M_1) = L(M_2)$ olan bir $M_2$ vardır ve tersi de doğrudur.
- Benzetim: $M_2$, $M_1$'in her konfigürasyonuna karşılık gelen bir konfigürasyondan geçer ve aynı girişleri kabul eder.
- Kalma seçeneği (S hareketi): $a \to b, S$ yerine $a \to b, L$ ile ara durum $q_{12}$'ye, oradan her şerit sembolü $x$ için $x \to x, R$ ile $q_2$'ye.
- Yarı sonsuz şerit: sol uçta sola gitmek isteyen kafa yerinde kalır.
- Standart makine yarı sonsuzu benzetir: sol uca `#` konur, her duruma `# → #, R` döngüsü eklenir.
- Yarı sonsuz makine standart makineyi benzetir: iki izli şerit. Bir iz referans noktasının sağını, diğeri solunu ters sırada tutar.
- Çok şeritli: her şeridin bağımsız kafası var, hepsi aynı kontrol birimine bağlı. Gücü aynı.
- Çok boyutlu: kafa L, R, yukarı ve aşağı gidebilir. Gücü aynı.
- Deterministik olmayan Turing makinesi: aynı durum ve sembol için birden çok seçenek. Herhangi bir dal kabul ederse giriş kabul edilir.
- P: deterministik Turing makinesiyle polinom zamanda çözülen problemler. NP: deterministik olmayan Turing makinesiyle polinom zamanda çözülen problemler.

## Detaylı Açıklamalar

### Karşılaştırma fonksiyonu

- Fonksiyon: $f(x, y) = 1$ eğer $x > y$, $f(x, y) = 0$ eğer $x \le y$.
- Sayılar yine tekli gösterimle (unary) yazılır. Örnek: 3 = `111`.
- Giriş: `1^x 0 1^y`. Çıkış: tek sembollük `1` ya da `0`.
- Sözde kod (tahtadan):
  - Tekrarla: $x$'ten bir 1'i $y$'den bir 1 ile eşleştir.
  - Ta ki $x$'in ya da $y$'nin bütün 1'leri eşleşene kadar.
  - $x$'ten eşleşmemiş bir 1 kaldıysa: şeridi sil, 1 yaz.
  - Kalmadıysa: şeridi sil, 0 yaz.
- Eşleştirme, $a^n b^n$ makinesindeki $a$-$b$ eşleştirmesinin aynısıdır.
- Hoca bu makinenin durum diyagramını vermedi; yapılabileceğini göstermekle yetindi.

### Turing makinelerini birleştirme

Örnek fonksiyon:

$$f(x, y) = \begin{cases} x + y & x > y \\ 0 & x \le y \end{cases}$$

Blok diyagramı (tahtadan, kareden doğrulandı):

- $x, y$ önce karşılaştırıcıya (comparator) girer.
- $x > y$ ise toplayıcı (adder) çalışır. Toplayıcıya $x, y$ ayrı bir yoldan gelir. Çıkış $x + y$ olur.
- $x \le y$ ise silici (eraser) çalışır. Şeridi siler ve 0 yazar.
- Hangi blok çalıştıysa onun çıkışı makinenin çıkışıdır.
- Toplayıcı ($x + y$) ve karşılaştırma makineleri daha önce görüldüğü için bu fonksiyon da hesaplanabilir.

### Turing tezi ve algoritma

- Turing tezi: mekanik yollarla yapılan her hesaplama bir Turing makinesiyle yapılabilir.
  - Yani bilgisayarların yaptığı her hesaplamayı bir Turing makinesi de yapabilir.
- Algoritma tanımı: bir problem için algoritma, o problemi çözen bir Turing makinesidir.
  - Algoritmanın adımları (sözde kod) Turing makinesine çevrilebilir.
  - "Algoritma vardır" demek "o adımları yürüten bir Turing makinesi vardır" demektir.
  - Örnek: $2x$ fonksiyonu için verilen sözde kod bir algoritmadır, çünkü onu yürüten bir Turing makinesi yazıldı.

### Standart Turing makinesi

- Şerit iki yönde sonsuzdur. Girişin önünde ve arkasında boş semboller vardır.
- Tek okuma-yazma kafası vardır. Başta girişin ilk sembolünü gösterir.
- Kafa her adımda sola ya da sağa gider.
- Kontrol birimi bütün durumları tutar ve deterministiktir.

### Güç ve eşdeğerlik

- Güç, bir makine sınıfının tanıyabildiği diller kümesidir.
- Yığıtlı otomatlar (pushdown automata) sonlu otomatlardan güçlüdür.
  - Sonlu otomatlar düzenli dilleri, yığıtlı otomatlar bağlamdan bağımsız dilleri tanır. Düzenli diller bağlamdan bağımsız dillerin alt kümesidir.
- Turing makineleri yığıtlı otomatlardan güçlüdür.
  - Her bağlamdan bağımsız dil Turing ile tanınabilirdir. Ama $a^n b^n c^n$ gibi bağlamdan bağımsız olmayan dilleri de tanırlar.
- İki sınıfın aynı güçte olması:
  - 1\. sınıftaki her $M_1$ için 2. sınıfta $L(M_1) = L(M_2)$ olan bir $M_2$ vardır.
  - 2\. sınıftaki her makine için de 1. sınıfta aynı dili tanıyan bir makine vardır.

### Benzetim yöntemi

- $M_1$ birinci sınıftan özgün makinedir. $M_2$ ikinci sınıftan benzetim makinesidir.
- $M_1$'in hesaplaması $C_1 \vdash C_2 \vdash \dots \vdash C_n$ ise $M_2$ her $C_i$ için karşılık gelen bir $C_i^*$ konfigürasyonundan geçer.
- İki makine aynı girişle başlar. Aynı adımları yaptıkları için aynı dizgileri kabul ederler: $L(M_1) = L(M_2)$.

### Kalma seçenekli Turing makinesi (stay-option)

- Tek fark: kafa L ve R'nin yanında S ile yerinde kalabilir. Gerisi standart makineyle aynıdır.
- 1\. adım: kalma seçenekli makineler standart makineleri benzetir.
  - Bu açıktır. Her standart makine zaten bir kalma seçenekli makinedir; L ve R hareketleri her ikisinde de vardır.
- 2\. adım: standart makineler kalma seçenekli makineleri benzetir.
  - Yalnız S hareketini benzetmek gerekir. Diğer geçişler olduğu gibi kalır.
  - Kalma seçenekli geçiş: $\delta(q_1, a) = (q_2, b, S)$.
  - Standart makinede yeni bir ara durum $q_{12}$ eklenir:
    - $\delta(q_1, a) = (q_{12}, b, L)$
    - Her şerit sembolü $x$ için $\delta(q_{12}, x) = (q_2, x, R)$
  - Önce sola gidilir, sonra sağa geri dönülür. Soldaki sembol ne olursa olsun aynen geri yazılır; bu yüzden her $x$ için ayrı geçiş gerekir.
  - Örnek (kareden): `bab` şeridinde kafa `a`'da, $q_1$'deyken sonuç `bbb`, kafa ortada, $q_2$.

### Yarı sonsuz şeritli Turing makinesi

- Şerit yalnız sağa doğru sonsuzdur. Giriş şeridin başındadır, kafa ilk sembolde başlar.
- Kafa sol uçta sola gitmek isterse yerinde kalır. Gerisi standart makineyle aynıdır.
- 1\. adım: standart makineler yarı sonsuz makineleri benzetir.
  - Girişin soluna özel bir `#` sembolü konur.
  - Her duruma `#` $\to$ `#`, R döngüsü eklenir. Kafa `#`'ya gelince hemen sağa geri döner; sol taraf fiilen kesilmiş olur.
- 2\. adım: yarı sonsuz makineler standart makineleri benzetir.
  - Çok izli şerit hilesi kullanılır. İki izli bir şeritte her hücre bir sembol çiftidir: $\Gamma_2 = \{(a, c), (b, d), (a, a), \dots\}$.
  - Tek okuma-yazma kafası vardır. Bu yine standart bir makinedir, yalnız alfabesi genişletilmiştir.
  - Standart şeritte girişin ortasında bir referans noktası seçilir.
  - Yarı sonsuz şeridin ilk hücresine iki izde de `#` konur.
  - Üst iz, referans noktasının sağındaki hücreleri sırayla tutar.
  - Alt iz, referans noktasının solundaki hücreleri ters sırayla tutar.
  - Kareden örnek: standart şerit `a b c | d e`; iki izli şerit üst izde `# d e`, alt izde `# c b a`.
  - Kafa alt izdeyken standart makinedeki sağa hareket, iki izli şeritte sola hareket olur; sola hareket de sağa olur.
  - Kafa `#`'ya gelince iz değiştirilir.
- Hoca ikinci bir yol da anlattı: yarı sonsuz şeridin başına özel sembol koyup, sola taşma olduğunda bütün içeriği bir hücre sağa kaydırmak.

### Çok şeritli ve çok boyutlu Turing makineleri

- Çok şeritli: $n$ tane şerit vardır. Her şerit iki yönde sonsuzdur ve kendi bağımsız kafası vardır. Hepsi aynı kontrol birimine bağlıdır.
  - Geçiş örneği: $q_1$'de şeritlerden $(a, c, \dots, d)$ okunur; $(b, d, \dots, d)$ yazılır; hareketler $(R, L, \dots, L)$; $q_2$'ye geçilir.
  - Standart makineyle aynı güçtedir. Hoca ispatı öğrencilere bıraktı.
- Çok boyutlu: şerit iki ya da daha çok boyutludur ve her yönde sonsuzdur.
  - Kafa L ve R'nin yanında yukarı (U) ve aşağı (D) da gidebilir.
  - Standart makineyle aynı güçtedir. İspat yine öğrencilere bırakıldı.

### Deterministik olmayan Turing makinesi

- Aynı durumda aynı sembol okunduğunda birden çok seçenek olabilir.
  - Örnek: $q_1$'de $a$ okununca $b$ yazıp L ile $q_2$'ye ya da $c$ yazıp R ile $q_3$'e gidilebilir.
- Makine her seçimde kendini çoğaltıyormuş gibi düşünülebilir. Hesaplama bir liste değil, bir ağaçtır (computation tree).
- Herhangi bir dal kabul durumuna ulaşırsa makine durur ve girişi kabul eder. Diğer dalların reddetmesi ya da sonsuz döngüye girmesi önemli değildir.
- Standart Turing makinesiyle aynı güçtedir. Yeni bir dil tanıyamaz.
- Karmaşıklık sınıflarında kullanılır (bu derste ayrıntısına girilmedi):
  - P: deterministik bir Turing makinesiyle polinom zamanda çözülebilen problemler.
  - NP: deterministik olmayan bir Turing makinesiyle polinom zamanda çözülebilen problemler.
- Standart ve deterministik olmayan Turing makineleri hesaplama modelleridir, gerçek bilgisayarlar değildir.

### Final ve dönem kapanışı

- Quiz sonuçları dersin duvarına (course wall) kondu.
- Final:
  - Hoca "gelecek salı, muhtemelen saat 9" dedi ama emin olmadığını, final programına bakılmasını söyledi.
  - Dönem boyunca işlenen her konu finalde sorulabilir.
  - Ders sonunda, büyük ihtimalle her zamanki gibi test olacağını ve 20'den fazla soru bekleyeceğini söyledi.
- Sorular için hocaya e-postayla ulaşılabilir.

### Ders sonrası notlar

- Hoca güç karşılaştırmasında önce "bağlamdan bağımsız diller düzenli dillerden güçlüdür" dedi, sonra kendisi düzeltti. Güç makine sınıflarına aittir: yığıtlı otomatlar sonlu otomatlardan güçlüdür.
- Hoca "Turing makineleri standart Turing makinelerinden güçlüdür" dedi. Bu bir sürçmedir; kastedilen, Turing makinelerinin yığıtlı otomatlardan güçlü olmasıdır.
- Blok diyagramında karşılaştırıcı, önceki örnekteki gibi şeridi silip 0/1 yazarsa toplayıcı $x$ ve $y$'yi kaybeder. Bu yüzden tahtadaki diyagramda $x, y$ toplayıcıya ayrı bir yoldan gelir. Tek şeritli bir makinede bu, karşılaştırıcının girişi koruması ya da önce bir kopyasını alması demektir.
- Turing tezi bir tezdir, kanıtlanmış bir teorem değildir. "Mekanik hesaplama"nın biçimsel bir tanımı olmadığı için ispatlanamaz; ama aksi yönde bir örnek de bilinmemektedir.
- Algoritma tanımında önemli bir ayrıntı: algoritmanın her girişte durması beklenir. Bu yüzden algoritmaya karşılık gelen Turing makinesi, her girişte duran (halting) bir makinedir. Sonsuz döngüye girebilen bir tanıyıcı (recognizer) tam anlamıyla algoritma sayılmaz.
- Yarı sonsuz şerit ispatında hoca, ispatlanmakta olan sonucu kullanmaya başladı ("aynı güçte olduğunu zaten gösterdik"), sonra bunun kalma seçenekli makineler için gösterildiğini fark edip düzeltti.
- Aynı ispattaki kare örneğinde geçiş "$(\square, a) \to (\square, c), R$" diye yazılmış. Alt iz ters sırada tutulduğu için standart makinedeki sağa hareket iki izli şeritte sola harekete karşılık gelir. Karedeki ikinci şerit görüntüsünde de kafa sola (`b`'nin altına) gitmiştir. Doğru geçiş: $(\square, a) \to (\square, c), L$. Ayrıca standart şeritteki örnek geçiş "$a \to b, R$" yazılmış ama şeritlerde $a$'nın yerine $c$ yazılmış; örnek $a \to c, R$ olarak okunmalıdır.
- Hoca deterministik olmayan Turing makinesi için "çok daha hızlı" dedi. Bu bir sezgidir, fiziksel bir hız değildir: makine her dalı aynı anda izliyormuş gibi düşünülür. Deterministik bir makineyle benzetildiğinde, bilinen yöntemler en kötü durumda üstel zaman alır. P = NP sorusu bu yüzden açıktır.
- P ve NP, algoritma değil problem (dil) sınıflarıdır. Hocanın "P class algorithms" ifadesi "P sınıfındaki problemler" olarak anlaşılmalıdır.
- Hoca finali önce "midterm" diye andı, sonra düzeltti. Kastedilen finaldir.
- Bu dersteki çeşitler ve ispatlar (kalma seçeneği, yarı sonsuz şerit, çok izli şerit, benzetim) Linz'in *An Introduction to Formal Languages and Automata* kitabının 10. bölümündeki anlatımla aynı sıradadır.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz. Ders İngilizce anlatılmıştır; altyazı da büyük ölçüde İngilizcedir.
