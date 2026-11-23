# Ders 14 Çalışma Özeti

## Genel Konular

- Turing tezi ve algoritmanın biçimsel tanımı
  - Turing tezi: mekanik yollarla yapılabilen her hesaplama bir Turing makinesiyle yapılabilir. Yani bir bilgisayarın yapabildiği her hesaplamayı bir Turing makinesi de yapabilir.
  - Bunun tersinden algoritma tanımı çıkar: bir problem için algoritma olması, o problemi çözen bir Turing makinesi olması demektir. Sözde koddaki adımlar en alt düzeyde Turing makinesinin durum geçişlerine karşılık gelir.
  - Bir problemi çözen Turing makinesi yoksa problem bilgisayarla çözülemez. Çözülemezliği ispatlamak, boşuna çözüm aranmasını önlediği için önemlidir.
- Standart Turing makinesi ve "aynı güç" kavramı
  - Standart model: iki yönde sonsuz bir şerit (tape), okuma-yazma kafası (sağa ya da sola gider) ve deterministik bir kontrol birimi.
  - İki makine sınıfının aynı güçte (same power) olması, aynı dil kümesini kabul etmeleri demektir. Hız farklı olabilir, güç aynıdır.
  - İspat yöntemi simülasyondur: her sınıfın diğerinin her adımını (belki birkaç adımda) taklit edebildiği gösterilir. Bu, iki dil kümesinin karşılıklı alt küme olduğunu göstermeye denktir.
- Yerinde kalma seçenekli (stay-option) Turing makinesi (önceki dersin tekrarı)
  - Kafa L ve R dışında S (yerinde kal) hareketi de yapabilir.
  - Stay-option makine standart makineyi simüle eder (önemsiz: fazlası var, eksiği yok).
  - Standart makine, $a \to b, S$ geçişini iki adımla simüle eder: $a \to b, L$ ile yeni bir ara duruma, oradan her şerit sembolü $x$ için $x \to x, R$ ile hedef duruma.
- Çok izli şerit (multiple track tape)
  - Yeni bir makine değil, bir hiledir: aynı sütundaki semboller tek bir sembol, yani bir demet (ör. $(a,b)$) sayılır. Geçişler $(b,a) \to (c,d), L$ biçiminde yazılır.
- Yarı sonsuz şeritli (semi-infinite tape) Turing makinesi
  - Şerit yalnız sağa doğru sonsuzdur. Kafa sol sınırdan sola gitmeye çalışırsa yerinde kalır.
  - Standart makine yarı sonsuzu simüle eder: girişin soluna özel $\#$ sembolü konur, her duruma $\# \to \#, R$ öz döngüsü eklenir.
  - Yarı sonsuz makine standardı simüle eder: iki izli şerit kullanılır. Bir referans noktasının sağındaki kısım üst ize, solundaki kısım ters sırayla alt ize yazılır. Her $q$ durumu için $q^R$ ve $q^L$ kopyaları açılır. Sınırda ($\#$) R ve L kopyaları arasında geçiş yapılır.
- Çok şeritli (multi-tape) Turing makinesi
  - Tek kontrol birimi, birden çok şerit; giriş 1. şerittedir. Geçişte her şerit için okunan, yazılan sembol ve hareket ayrı yazılır.
  - Standart makine bunu her şerit için iki iz (içerik + kafa konumu) kullanarak simüle eder.
  - Aynı güç aynı hız demek değildir: $\{a^n b^n\}$ standart makinede $O(n^2)$, iki şeritli makinede $O(n)$ zamanda tanınır.
- Çok boyutlu (multidimensional) Turing makinesi
  - İki boyutlu şeritte hareketler L, R, U, D; kafa konumu koordinatla verilir.
  - Standart makine bunu iki izle simüle eder: üst izde sembol, alt izde koordinatları.
- Deterministik olmayan (nondeterministic) Turing makinesi
  - Aynı durum ve aynı okunan sembol için birden çok geçiş olabilir. Herhangi bir hesaplama dalı kabul durumuna ulaşırsa giriş kabul edilir.
  - Deterministik makine, iki boyutlu şeritte bütün konfigürasyonları tutup hesaplama ağacını genişlik öncelikli (breadth-first) gezerek simüle eder. En kötü durumda üstel zaman alır.
- Evrensel Turing makinesi (universal Turing machine)
  - Yeniden programlanabilir makinedir; girişi, simüle edeceği makinenin tanımı ve o makinenin giriş dizisidir.
  - Üç şeritli yapı: makinenin tanımı, simüle edilen makinenin şerit içeriği, simüle edilen makinenin durumu.
  - Kodlama: semboller, durumlar ve hareketler birli (unary) sayılarla, alanlar tek $0$ ile, geçişler $00$ ile ayrılır. Böylece her Turing makinesi bir 0-1 dizisidir; Turing makineleri kümesi bir dildir.
- Sayılabilir ve sayılamaz kümeler
  - Sayılabilir küme: elemanları pozitif tam sayılarla birebir eşlenebilen küme. Çift sayılar ve rasyonel sayılar sayılabilir; reel sayılar sayılamaz.
  - Sayma yöntemi bir sayma yordamı (enumeration procedure) ya da sayıcıdır (enumerator): kümenin bütün dizilerini sırayla, her birini sonlu zamanda üreten Turing makinesi.
  - Bütün Turing makineleri kümesi sayılabilir. Bütün diller kümesi sayılamaz (ispatı derste atlandı). Sonuç: hiçbir Turing makinesinin kabul etmediği diller, yani çözülemeyen problemler vardır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Güç ile hız ayrı şeylerdir
  - Varyasyonların hiçbiri standart makineden daha güçlü değildir; yeni bir dil kabul edemezler. Ancak bazıları (çok şeritli, deterministik olmayan) daha hızlı olabilir.
  - Deterministik olmayan makine paralel programlamaya benzetildi: paralel programlamayla seri olarak çözülemeyen bir problem çözülmez, yalnız iş daha hızlı biter.
- Simülasyonda "her olası sembol için" geçiş eklenmelidir
  - Stay-option ve yarı sonsuz ispatlarında kafa bilinmeyen bir hücreye gittiği için ek geçiş bütün şerit sembolleri $x$ için yazılır.
- Deterministik olmayan makinenin simülasyonunda derinlik öncelikli arama (depth-first) kullanılamaz
  - Kabul eden yoldan önce sonsuz bir yol varsa derinlik öncelikli arama orada takılır; bu yüzden genişlik öncelikli arama gerekir. Bu cevap derste bir öğrenciden geldi.
- Dersin "üzücü sonucu"
  - Algoritmalar sayılabilir, problemler sayılamaz; problem kümesi daha büyüktür. Bu yüzden bilgisayarla çözülemeyen problemler vardır.

## Kısa Tekrar Notları

- Algoritma = o problemi çözen bir Turing makinesi.
- Aynı güç = aynı dil kümesini kabul etme. İspat: iki yönlü simülasyon.
- Stay-option: $a \to b, S$ yerine $a \to b, L$ ve her $x$ için $x \to x, R$.
- Çok izli şerit: her sütun tek bir demet sembolü; standart makinedir.
- Yarı sonsuz: $\#$ + öz döngü $\# \to \#, R$; ters yön için iki iz, $q^L$/$q^R$ durumları.
- Çok şeritli: her şerit iki iz (içerik + kafa konumu); $a^n b^n$ için $O(n^2)$ yerine $O(n)$.
- İki boyutlu: üst iz sembol, alt iz koordinat ($\#$ ile ayrılmış).
- Deterministik olmayan: konfigürasyon ağacında genişlik öncelikli arama; en kötü durumda üstel zaman.
- Evrensel TM: tanım + giriş; birli kodlama, alan ayırıcı $0$, geçiş ayırıcı $00$.
- Sayılabilir: pozitif tam sayılarla birebir eşleme. Rasyonel sayılar köşegen sırayla sayılır.
- $\{a,b,c\}^+$ uzunluk sırasıyla (canonical order) sayılır.
- TM'ler sayılabilir, diller sayılamaz, öyleyse Turing-kabul edilemez diller vardır.

## Detaylı Açıklamalar

- **Simülasyonla aynı gücü göstermek.** İki sınıfın dillerinin eşit olduğunu göstermek için iki alt küme ilişkisi gerekir. Derste bu, simülasyonla yapıldı: birinci sınıftaki her geçiş ikinci sınıfta bir ya da birkaç geçişle gerçekleştirilebiliyorsa, ikinci sınıf aynı konfigürasyonlara ve dolayısıyla aynı kabul konfigürasyonuna ulaşır. Varyasyonların çoğunda bir yön önemsizdir (trivial), çünkü yeni makine standart makinenin her şeyine sahiptir; asıl iş standart makinenin yeni özelliği nasıl taklit ettiğini göstermektir.

- **Stay-option makinenin simülasyonu** (ekrandan, 00:25:00). Fazla olan tek geçiş türü $q_1 \xrightarrow{a \to b,\, S} q_2$'dir. Standart makinede bu, iki geçişe bölünür:

  | Adım | Geçiş | Açıklama |
  |---|---|---|
  | 1 | $q_1 \xrightarrow{a \to b,\, L} q_{ara}$ | $a$ okunur, $b$ yazılır, kafa sola gider |
  | 2 | $q_{ara} \xrightarrow{x \to x,\, R} q_2$ | her şerit sembolü $x$ için: sembol değişmez, kafa sağa döner |

  Kafa sola gittiğinde orada hangi sembolün olduğu bilinmediği için ikinci geçiş bütün $x$ değerleri için eklenir. Bu bir yapıyla ispattır (proof by construction).

- **Yarı sonsuz şeritle standart makinenin simülasyonu** (ekrandan, 00:40:00 ve 00:45:00). Standart şerit bir referans noktasından ikiye bölünür. Sağ parça üst ize, sol parça referanstan uzaklaşacak biçimde ters sırayla alt ize yazılır; en solda iki izde de $\#$ vardır. Standart makinedeki $q_1 \xrightarrow{a \to g,\, R} q_2$ geçişi için şunlar eklenir (her şerit sembolü $x$ için):

  | Parça | Eklenen geçiş |
  |---|---|
  | Sağ parça (üst iz) | $q_1^R \xrightarrow{(a,x) \to (g,x),\, R} q_2^R$ |
  | Sol parça (alt iz) | $q_1^L \xrightarrow{(x,a) \to (x,g),\, L} q_2^L$ |

  Alt izde sola gitmek, gerçek şeritte sağa gitmek demektir. Sınırda $\#$ okunursa $(\#,\#) \to (\#,\#), R$ ile sağa geçilir ve durumun L/R kopyası değiştirilir: $q^L$ iken $q^R$'ye, $q^R$ iken $q^L$'ye. Ekrandaki örnekte (ekrandan, 00:50:00) kafa $q_1^L$ ile $\#$ üzerindeyken bir sonraki adımda $q_1^R$ ile ilk sütuna geçer; artık üst izdeki sembol işlenir.

- **Çok şeritli makinenin simülasyonu** (ekrandan, 01:15:00). Standart makinede her şerit için iki iz kullanılır: biri şeridin içeriği, diğeri kafa konumu (kafanın olduğu yerde 1, diğer yerlerde 0). Solda referans noktası olarak $\#$ vardır. Her çok şeritli geçiş için: (1) referans noktasına dön, (2) 1. şeritte geçerli sembolü bul ve güncelle, (3) referans noktasına dön, (4) 2. şeritte geçerli sembolü bul ve güncelle. $\{a^n b^n\}$ örneğinde standart makine $a$'larla $b$'leri eşlemek için $O(n^2)$ kez gidip gelir; iki şeritli makine önce $b^n$'yi 2. şeride kopyalar ($O(n)$), sonra iki kafayı birlikte ilerleterek karşılaştırır ($O(n)$).

- **İki boyutlu makinenin simülasyonu** (ekrandan, 01:20:00 ve 01:25:00). Ekrandaki örnekte kafa $(+2,-1)$ konumundaki $b$ hücresindedir. Standart makinenin üst izine $b$, alt izine $\#\,2\,\#\,-1\,\#$ biçiminde koordinatlar yazılır. Her geçişte: geçerli sembol güncellenir, bir sonraki konumun koordinatları hesaplanır, şeritte o konum bulunur.

- **Deterministik olmayan makinenin simülasyonu** (ekrandan, 01:30:00, 01:40:00, 01:45:00). Giriş $w$, $q_0 w \overset{*}{\succ} x\, q_f\, y$ olacak biçimde bir hesaplama varsa ($q_f$ herhangi bir kabul durumu) kabul edilir. Örnek: $q_1$'de $a$ okunduğunda iki seçenek vardır: $a \to b, L$ ile $q_2$'ye ya da $a \to c, R$ ile $q_3$'e gitmek. Deterministik makine bütün konfigürasyonları iki boyutlu şeritte satır satır tutar (durum, kafanın bulunduğu hücreye yazılır, sınırlar $\#$ ile çizilir). Her adımda her konfigürasyon için birden fazla seçenek varsa konfigürasyon çoğaltılır. Bu, hesaplama ağacında genişlik öncelikli aramadır. Deterministik olmayan makine kabul ederse deterministik makine de kabul edip durur; ama bu, kabul eden en kısa yolun uzunluğuna göre en kötü durumda üstel zaman alır. Kabul etmezse ya bütün yollar durarak reddeder ya da sonsuz bir yol varsa simülasyon hiç bitmez; iki durumda da giriş reddedilmiş olur.

- **Evrensel Turing makinesi ve kodlama** (ekrandan, 02:05:00 ve 02:10:00). Şu ana kadarki makineler tek bir program çalıştırır (hardwired). Evrensel makine başka herhangi bir Turing makinesini simüle eder; bir Turing makinesi bir algoritma olduğundan her programı çalıştırabilir. Kodlama tablosu:

  | Öğe | Kod |
  |---|---|
  | Semboller $a, b, c, d, \dots$ | $1, 11, 111, 1111, \dots$ |
  | Durumlar $q_1, q_2, q_3, q_4, \dots$ | $1, 11, 111, 1111, \dots$ |
  | Hareketler $L, R$ | $1, 11$ |

  Bir geçişin alanları tek $0$ ile, geçişler $00$ ile ayrılır. Örneğin $\delta(q_1,a) = (q_2,b,L)$ geçişi $10101101101$ olur (alanların birleştirilmesi python ile denetlendi). Böylece her Turing makinesi bir 0-1 dizisidir ve Turing makineleri bir dil oluşturur (ekrandan, 02:15:00).

- **Sayılabilirlik** (ekrandan, 02:20:00, 02:25:00, 02:30:00). Çift sayılar $2n \leftrightarrow n+1$ ile pozitif tam sayılara eşlenir. Rasyonel sayılarda payı 1'e sabitleyip paydayı artırmak işe yaramaz, çünkü payı 2 olan sayılara hiç gelinmez. Doğru sıra köşegen sıradır: $\frac11, \frac12, \frac21, \frac13, \frac22, \dots$ ve bunlar sırayla $1, 2, 3, 4, 5, \dots$ ile eşlenir. $\{a,b,c\}^+$ kümesinde de yalnız $a, aa, aaa, \dots$ diye saymak işe yaramaz; uzunluk sırası (canonical order) kullanılır: önce uzunluğu 1 olanlar, sonra 2, 3 ... Turing makinelerini saymak için bütün 0-1 dizileri sırayla üretilir, her birinin bir Turing makinesi tanımlayıp tanımlamadığına bakılır ve tanımlıyorsa çıktıya yazılır. Daha basit bir ispat: her makinenin ikili dizisi temsil ettiği sayıya eşlenir (ekrandan, 02:35:00).

- **Sonuç** (ekrandan, 02:40:00). Turing makineleri (algoritmalar) sayılabilir, bütün diller (problemler) kümesi sayılamaz. Öyleyse Turing-kabul edilebilir diller kümesinin dışında kalan bir $L$ dili vardır: bilgisayarla çözülemeyen problemler vardır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
