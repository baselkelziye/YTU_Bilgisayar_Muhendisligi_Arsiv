# Ders 1 Genişletilmiş Notu: Elektronik Sistemlere Giriş: Analog ve Sayısal İşaretler, Bozunum, Gürültü ve Sistem Tasarımı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı: Devre Teorisinden Elektronik Devrelere
- 2. Kaynak Kitaplar
- 3. Elektronik Sistem Nedir?
- 4. Sürekli ve Ayrık Büyüklükler: Analog, Sayısal ve İkili İşaretler
- 5. Örnek Elektronik Sistemler: Plak Çalar ve CD Çalar
- 6. Sensörler ve Eyleyiciler
- 7. Bozunum ve Gürültü
- 8. Sistem Tasarımı ve Elektronik Tasarım Araçları

## 1. Dersin Kapsamı: Devre Teorisinden Elektronik Devrelere

Hoca derse, Elektronik Devreler'in genel çerçevesini çizerek başladı. Bu ilk hafta ayrıntılı bir konu anlatımından çok, elektronik sistemlerin ne olduğuna ve dersin kapsamına "genel kültür seviyesinde" bir giriş yapıldı.

Elektronik Devreler ile birinci sınıftaki Devre Teorisi dersi arasında bir bağlantı vardır, ama Devre Teorisi bu ders için ön koşul değildir. Hoca bunu şöyle özetledi: $V = I \cdot R$ bağıntısını yeniden anlatmayacağız ama sürekli kullanacağız; kullandıkça zaten öğrenmiş olacaksınız.

İki dersin farkı şudur:

- **Devre Teorisi** daha basit elektriksel devrelere bakar. Kirchhoff'un akım ve gerilim kanunları, Ohm kanunu, Norton ve Thevenin eşdeğerleri gibi daha teorik araçlar öğretilir. Kullanılan elemanlar pasif devre elemanlarıdır: direnç, bobin ve kondansatör.
- **Elektronik Devreler** ise elektronik devrelerin analizine ve bir devrenin belirli bir amaca yönelik nasıl kurgulanacağına odaklanır. Pasif elemanlara ek olarak yarı iletken (semiconductor) devre elemanlarına giriş yapılır: diyot, transistör, MOSFET ve işlemsel yükselteç (op-amp).

Ekrandaki ders planına göre dersin konuları üç büyük başlık altında toplanır (ekrandan, 00:15:00):

- **Elektrik devreleri ve bileşenleri:** temel elektrik devreleri ve bileşenleri, gerilim ve akım ölçümü, direnç ve DC devreler, kapasitans ve elektrik alanı, endüktans ve manyetik alan, alternatif gerilim ve akımlar, AC devrelerde güç, AC devrelerin frekans karakteristikleri, geçici (transient) davranış.
- **Elektronik sistemler:** elektronik sistemler, sensörler, eyleyiciler (actuators), yükseltme (amplification), kontrol ve geri besleme, işlemsel yükselteçler.
- **Yarı iletken elemanlar ve devreler:** yarı iletkenler ve diyotlar, diyot uygulamaları, bipolar jonksiyonlu transistörler (BJT), alan etkili transistörler (FET), güç elektroniği, işlemsel yükselteçler, sayısal sistemler.

## 2. Kaynak Kitaplar

Hoca birkaç kaynak kitap gösterdi. Sunumların çoğunluğu, pek çok üniversitede ders kitabı olarak okutulan bir ana kitaptan düzenlenmiştir ve bu kitap ders için yeterlidir. <!-- BELİRSİZ: ana kitabın yazarı altyazıda "Olşıtat" diye bozulmuş; kitap kapağı kare aralığına düşmedi -->

> Ek bilgi (derste anlatılmadı): Ekrandaki ders planı ve giriş slaytlarının yapısı (algılama, işleme, kontrol; analog, çok değerli sayısal ve ikili işaret çizimleri; bozunum türleri) büyük olasılıkla Neil Storey'nin *Electronics: A Systems Approach* kitabının ilk bölümlerine dayanır.

Bunun dışında çok sayıda soru içeren Schaum serisinden bir kitap (hocaya göre Türkçesi de var) ve Devre Teorisi'ni de içine alan *Electronic Devices and Circuit Theory* tarzı kitaplar önerildi. Türkçe kaynakların da çok olduğu belirtildi.

**Soru:** Devre Teorisi dersinde kullanılan elektrik devreleri kitabı bu ders için de uygun mu?
**Cevap:** Hoca kitabın içindekilere baktı. İlk bölümler Devre Teorisi'nin konularıyla birebir örtüşüyor. Yükselteç ve işlemsel yükselteç bölümü bu dersin op-amp kısmına (dönemin ortalarına doğru işlenecek) yeterli olabilir. Yüksek mertebeden devreler ve karmaşık frekans analizi gibi bölümler Devre Teorisi'ne aittir. Kitapta diyot ve transistör analizi bulunmadığı için bu derse çok uygun değildir; ama Devre Teorisi için çözümlü problemleriyle tavsiye edilen iyi bir kitaptır.

## 3. Elektronik Sistem Nedir?

Hoca konuya bir benzetmeyle girdi: içinde yaşadığımız dünya sürekli değişir ve hayatta kalmak için bu değişimlere tepki vermemiz gerekir. Tepki vermek için değişen bir büyüklüğü algılarız (bu **giriştir**) ve başka bir büyüklüğü değiştiririz (bu da **çıkıştır**). Çoğu zaman bu tepkiyi bizim yerimize makineler verir. Bu makinelerin doğası şudur: bir giriş büyüklüğünü **algılar** (sense), bilgiyi **işler** (process) ve bir çıkış büyüklüğünü **kontrol eder** (control) (ekrandan, 00:35:00).

Buna göre elektronik sistem, dışarıdan bir veriyi algılayan, bu bilgiyi işleyen ve bir kontrol çıktısı üreten sistemdir. Bir tasarımın elektronik sistem sayılabilmesi için üç birimi de içermesi gerekir:

- **Algılama:** Çevredeki ölçülebilir büyüklüklerin sensörler aracılığıyla elektronik ortamda anlamlandırılması.
- **İşleme:** Bu anlamlı verinin işlenmesi.
- **Çıkış üretme:** İşlenen veriye göre dışa dönük bir çıktı. Bu bir şeyi kontrol etmek, bir ekrana bilgi yazmak ya da bir sinyal tetiklemek olabilir; hocaya göre bunların hepsi sonuçta kontrol üretmektir.

Dış dünyadan ölçülen değerler fiziksel büyüklüklerdir: sıcaklık, basınç, nem gibi. Elektronik sistemin bu bilgiyi işleyip bir çıktı üretebilmesi için önce bu büyüklükleri algılaması gerekir. Bunu, maddenin içindeki bir değişimi kullanarak bir elektriksel değer üreten elemanlar, yani **sensörler** yapar.

Hoca elektronik sistemi girişleri ve çıkışları bilinen kapalı bir yapı olarak da tarif etti. Otomobillerdeki otomotiv sistemleri ve iletişim sistemleri bu tür sistemlere örnektir.

## 4. Sürekli ve Ayrık Büyüklükler: Analog, Sayısal ve İkili İşaretler

### 4.1 Sürekli büyüklükler

Fiziksel büyüklükleri elektriksel işaretlerle göstermek çoğu zaman kullanışlıdır. Bu işaretler de sürekli ya da ayrık olabilir. Sürekli işaretlere **analog** işaret denir (ekrandan, 00:40:00). Ekrandaki örnekte gerilim zamanla düzensiz ama kesintisiz biçimde dalgalanır.

Hocanın günlük hayattan örneği sıcaklıktı. "Hava sıcaklığı 9 derece" deriz, ama sıcaklık hiçbir an tam 9 derecede durmaz: bir an 9,135... iken bir sonraki an biraz farklıdır. Yani gerçek dünyada sürekli bir değişim vardır. Biz bunu yuvarlayarak düzgün bir değer söyleriz; başka bir deyişle **ayrıklaştırırız**.

Bu sürekliliği birebir izlemek normal elektronik sistemlerde çok zordur. Hocanın ifadesiyle sürekli işaretin doğrudan işlenmesi neredeyse imkânsızdır; bu yüzden işaretin ayrık moda getirilmesi gerekir.

### 4.2 Ayrık büyüklükler ve sayısal işaretler

Ayrık işaretlere genellikle **sayısal (dijital) işaret** denir. Ekranda basamaklı bir dalga biçimi "çok değerli sayısal işaret" olarak gösterildi. Pek çok sayısal işaret yalnız iki değer alır; bunlara **ikili (binary) işaret** denir (ekrandan, 00:45:00). Hoca ikili işaretin üst seviyesini 1, alt seviyesini 0 olarak gösterdi.

Hoca analog işaretin ayrıklaştırılmasını tablette çizerek anlattı. Analog işaret belirli pencerelere bölünür ve her pencerede işaret en yakın düzgün değere yuvarlanır; böylece daha az değişkenlik gösteren, ani basamaklarla ilerleyen bir dalga biçimi elde edilir. Hoca bu işleme "quantization" (kuantalama) dedi.

> Ek bilgi (derste anlatılmadı): Hoca kuantalama ile örneklemeyi aynı anlamda kullandı. İşaret işlemede bu iki adım genellikle ayrılır: örnekleme (sampling) zaman ekseninde belli aralıklarla değer almak, kuantalama (quantization) ise alınan değeri sonlu sayıdaki genlik seviyelerinden en yakınına yuvarlamaktır.

### 4.3 Neden ayrıklaştırıyoruz?

Hocanın ilk gerekçesi elemanların davranışıyla ilgiliydi. Transistör ve diyot konularında görüleceği gibi bu elemanlar iletime ya da kesime gider. Hocaya göre bu geçişler sürekli bir dalga biçimiyle beslendiğinde kararsız olabilir; eleman iletim-kesim arasında gidip gelebilir. Ayrık moda getirilmiş bir işaret ise elemanın iletimde kalacaksa iletimde kalmasını sağlayacak kadar bir süre sabit durur ve sistemi daha kararlı kılar.

İkinci gerekçe gürültüyle ilgilidir ve Bölüm 7'de anlatılmıştır: ayrık işarette ön işlem ve son işlem (pre-processing, post-processing) çok daha kolay uygulanır.

### 4.4 Çözünürlük ve bit sayısı

İkili gösterimde her basamak seviyesi bir bit dizisiyle kodlanır. Hoca tabletteki örnekte seviyeleri 3 bitle 000, 001, 010, ... diye numaralandırdı. Ardından aynı işaretin 4 bitle gösterildiğinde daha ince basamaklarla, analog dalga biçimine daha çok benzeyen bir şekle geldiğini çizdi.

Kural şudur: bit sayısı arttıkça çözünürlük artar ve analog işaret daha gerçekçi biçimde sayısallaştırılmış olur. Bu konu ileride Lojik Devreler ve İşaret İşleme derslerinde ayrıntılı görülür.

> Ek bilgi (derste anlatılmadı): $n$ bitle $2^n$ farklı seviye gösterilebilir. Hocanın karşılaştırdığı 3 bitlik gösterimde 8, 4 bitlik gösterimde 16 seviye vardır; her ek bit seviye sayısını iki katına çıkarır.

Hocanın özeti: dış dünyadaki fiziksel büyüklükler her zaman süreklidir ve değişkenlik gösterir; elektronik sistemler (bilgisayarlar da bunlardan biridir) bu büyüklükleri ayrık moda getirmek zorundadır ki sistemin cevabı daha uygun ve daha kararlı olsun.

> **Hocanın vurgusu:** Sinyaller konusu ileride ayrıca görülecek, ama elektronik ortamda işareti neden analog olarak işleyemediğimizi ve neden ayrıklaştırdığımızı anlamak önemlidir.

## 5. Örnek Elektronik Sistemler: Plak Çalar ve CD Çalar

Hoca slayttaki müzik çalar örneği üzerinden giriş, işleme ve çıkış birimlerini gösterdi.

**Plak çalar (analog).** Plağın yüzeyinde girintiler ve çıkıntılar vardır. İnce bir iğne bu girinti ve çıkıntıları izleyerek bir dalga biçimi, yani sürekli (analog) bir işaret üretir. Bu işaret bir yükselteçle (amplifier) yükseltilip hoparlöre verildiğinde ses çıkar. Bu sistemde:

- Giriş: iğneden alınan sensör verisi.
- İşleme: dalga biçiminin yükselteçle yükseltilmesi.
- Çıkış: ses.

Hoca plak çaların tamamen analog olduğunu ve teknolojide eskiye dönüşle yeniden popülerleştiğini belirtti. İyi bir yükselteç devresi ve gürültüye karşı bir gürültü azaltma (noise reduction) düzeni varsa plak çalardan çok kaliteli ses alınabilir.

**CD çalar (sayısal).** CD'nin yüzeyinde de izler vardır, ama plaktan farklı olarak buradaki her çukurun kademeli bir yüksekliği yoktur; bilgi "çukur var ya da yok" biçimindedir, yani sayısaldır. Okunan sayısal bilgi önce analoğa çevrilir, sonra yükselteçle yükseltilip hoparlöre verilir.

İki sistem de bir elektronik sistemdir: ikisinde de bir giriş, bir işleme ve bir çıkış vardır.

> **Ders sonrası not:** Hoca örneğe önce "CD çalardan müzik çalan sistem" diyerek başladı ve iğneyle okunan analog yapıyı bu adla anlattı; birkaç cümle sonra bunun plak çalar olduğunu söyleyerek CD'yi ayrı bir sayısal örnek olarak ele aldı. Doğrusu: iğneyle analog okuma plak çalarda yapılır; CD'deki çukurlar büyük olasılıkla lazerle optik olarak okunur.

## 6. Sensörler ve Eyleyiciler

Elektronik sistemlerin dünyayla etkileşimini sağlayan bileşenler iki ana başlık altında toplanır:

- **Sensörler:** Dış dünyadan bilgi alıp bu bilgiyi elektronik anlamda anlamlandırmamızı sağlayan yapılardır. Dış dünyadaki büyüklükleri elektronik ortama yansıtırlar. Plak çalar örneğinde sensör, iğnenin bulunduğu okuma ucudur.
- **Eyleyiciler (aktüatörler):** Elektronik sistemin işlediği bilgiye göre dış dünyaya bir tepki (çıktı) üretmesini sağlayan yapılardır. Örneğin bir kontrol sinyaliyle döndürülen motor bir eyleyicidir; plak çalar örneğinde eyleyici hoparlördür.

Hoca anahtarların (switch), motorların, LED'lerin ve lambaların bu iki başlığın altına girdiğini söyledi. <!-- BELİRSİZ: dersin sonundaki toparlamada altyazıda "fizyoelektronikler" diye bozulmuş bir terim geçiyor (00:55:55 civarı) --> Sensör ve eyleyici türleri bir sonraki derste ayrıntılı ele alınacaktır.

## 7. Bozunum ve Gürültü

Hoca konuya bir gözlemle girdi: büyük bilgisayar donanımı firmalarının üretim ve servis ortamlarında masalarda üzerinizdeki statik elektriği atmanız için bir düğme ya da metal bir yüzey bulunur. Elektrik sistemlerinde sürekli bozunum ve gürültüden söz edilir ve bu etkiler en çok analog, yani sürekli dalga biçimlerinde sorun çıkarır.

### 7.1 Bozunum (distortion)

Bütün sistemler elektriksel işareti bir ölçüde bozar. Ekrandaki örnekler kırpılma (clipping), sıfır geçiş bozunumu (crossover distortion) ve harmonik bozunumdur (harmonic distortion) (ekrandan, 00:50:00). Slaytta bu üç durum, temiz bir sinüs dalgasıyla karşılaştırmalı olarak çizilmiştir:

- **Kırpılma:** Sinüsün tepeleri üstten ve alttan bastırılmış gibi düzleşir. Hoca bunu "yukarıdan baskı varsa aşağıda da baskı oluyor" diye anlattı; bu baskı her periyotta aynı yerde tekrar eder.
- **Sıfır geçiş bozunumu:** İşaret sıfır noktasından geçerken bir büzülme oluşur; bu da her geçişte tekrar eder.
- **Harmonik bozunum:** Dalga biçiminin üzerine ek tepecikler biner (slayttaki çizim).

Bozunumun özü, **sistematik** ve **tekrarlanabilir** olmasıdır (ekrandan, 00:50:00): bir şablonu vardır ve bu şablon tekrar eder. Bu yüzden bozunum giderilebilir. Şablon öğrenildikten sonra işaret bir ön işlemden ya da son işlemden geçirilerek düzeltilir ve orijinal işaret bulunabilir. Hoca bu konunun işaret işleme derslerinde çok ele alınacağını belirtti.

### 7.2 Gürültü (noise)

Gürültü ise tamamen rastgeledir ve dış dünyadaki ölçüm değerlerini tamamen bozabilir. Analog bir işarette, gürültülü dalga biçiminden asıl işareti çıkarmak çok zordur. Sayısal hale getirilmiş bir işarette ise bu çok daha basittir: işaretin hangi seviyelerde olabileceğini bildiğimiz için seviyenin dışındaki küçük sapmaları doğrudan sıfırlayabiliriz. Analog tarafta böyle bir şey yapılamaz.

Bu, ayrıklaştırmanın ikinci gerekçesidir: ayrık işaret üzerinde ön ve son işlemler çok daha kolay uygulanır.

> **Hocanın vurgusu:** Bozunum bir şablona sahiptir ve düzeltilebilir; gürültü rastgeledir. Ayrıklaştırma, gürültüyle başa çıkmayı kolaylaştırır.

## 8. Sistem Tasarımı ve Elektronik Tasarım Araçları

### 8.1 Yukarıdan aşağıya tasarım

Sistem tasarımı genellikle üst seviyeden ayrıntıya doğru ilerleyen (top-down) bir hiyerarşiyle yapılır. Hoca adımları bir akıllı ev örneğiyle anlattı: müşteri alkışlayınca ışıkların yanıp sönmesini istiyor.

```text
1. Gereksinimler   : Ne isteniyor? (alkışla yanan/sönen ışık)
2. Spesifikasyon   : Hangi LED, hangi alkış sensörü? Ne kadar güçlü bir alkış?
                     Yere düşen bir çatal ışığı yakmalı mı?
3. Teknoloji seçimi: Sensörün eşiği, ölçüm aralığı, hassasiyeti
4. Ayrıntılı tasarım: simülasyon, PCB tasarımı
5. Yapım ve test   : ürünün bir araya getirilmesi ve test edilmesi
```

Teknoloji seçimi önemlidir, çünkü her sensörün ya da teknolojinin kendi eşik değerleri, ölçüm aralıkları ve hassasiyeti vardır ve bunlar ürünü farklılaştırır. Hassas ölçüm yapılacak bir yerde kullanılan sensör, çok yüksek referans değerlerine sahip bir sistemde aynen kullanılamaz.

### 8.2 Elektronik tasarım araçları

Yukarıdan aşağıya katmanlara bakıldığında, elektronik tasarımda en büyük yardımcı simülasyon uygulamalarıdır. Ekrandaki elektronik tasarım araçları şunlardır (ekrandan, 00:55:00):

- şematik çizim (schematic capture),
- devre simülasyonu (circuit simulation),
- PCB ya da VLSI yerleşim (layout) paketleri.

Devre simülasyonu bir devrenin işleyişini anlamayı büyük ölçüde kolaylaştırır. Slaytta yaygın örnekler olarak PSpice ve Multisim verilmiştir; hoca bunlara LTspice'ı da ekledi. <!-- BELİRSİZ: altyazıda "KeySpice" diye geçen bir program adı var (00:55:01); hangi simülatör kastedildiği net değil --> Hocaya göre Multisim'in öğrenciler için belirli bir süre ücretsiz bir sürümü vardır ve Proteus da kullanılabilir; kurulum gerektirmeyen çevrim içi simülatörler de vardır, ama bunlarda kullanılabilecek eleman sayısı sınırlıdır. Bu programlarla devre önce bilgisayar ortamında kurulur ve simüle edilir, sonra gerçek ortama taşınır.

> **Hocanın vurgusu:** Bu derste devre simülasyonlarında analizler yapmanız ciddi anlamda istenecek; simülasyon kullanımı dersin önemli bir parçasıdır.

## Dersin Toparlaması

Bu ilk derste elektronik sistemin ne olduğu tanımlandı: dış dünyadaki bir fiziksel büyüklüğü sensörle algılayan, bu bilgiyi işleyen ve eyleyicilerle bir çıkış üreten (bir şeyi kontrol eden) sistem. Fiziksel büyüklüklerin sürekli (analog) olduğu, elektronik sistemlerin ise bunları ayrık (sayısal, çoğu zaman ikili) işaretlere çevirerek çalıştığı anlatıldı; bit sayısı arttıkça çözünürlüğün arttığı gösterildi. Plak çalar ve CD çalar örnekleriyle analog ve sayısal sistemler karşılaştırıldı. Bütün sistemlerin işareti bozduğu, bozunumun sistematik ve düzeltilebilir, gürültünün ise rastgele olduğu ve ayrık işaretlerde gürültünün daha kolay giderildiği vurgulandı. Son olarak yukarıdan aşağıya sistem tasarımı adımları ve simülasyon araçlarının tasarımdaki rolü ele alındı.

Bir sonraki derste sensörler ve eyleyiciler daha ayrıntılı işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
