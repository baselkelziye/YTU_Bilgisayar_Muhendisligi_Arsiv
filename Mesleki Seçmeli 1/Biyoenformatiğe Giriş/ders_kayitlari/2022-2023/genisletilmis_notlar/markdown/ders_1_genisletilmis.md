# Ders 1 Genişletilmiş Notu: Biyoenformatiğe Giriş ve Bilgi Sistemlerinin Temelleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yaklaşımı ve Kaynaklar
- 2. "Bio" ile Başlayan Alanlar
- 3. Biyomühendislik Şemsiyesi
- 4. Biyoenformatik Nedir?
- 5. Biyoenformatiğe Üç Bakış Açısı
- 6. Biyoenformatiğin Teknikleri ve Kuramsal Temelleri
- 7. DNA ve Turing Makinesi
- 8. İyi Bir Biyoenformatikçi Olmak
- 9. Biyoenformatiğin Uygulama Alanları
- 10. Hesaplamalı Biyolojinin Kapsamı
- 11. Biyoenformatik Neden Hâlâ Sıcak Bir Alan?
- 12. İlaç Geliştirme Yaşam Döngüsü
- 13. Killer Application: Kişiselleştirilmiş Tıp
- 14. Biyoenformatik Araçları
- 15. Programlama Öğrenme ve Tekrarlanabilir Araştırma
- 16. Bilgi Sistemlerinin Temelleri
- Örnek Sorular

## 1. Dersin Yaklaşımı ve Kaynaklar

Ders İngilizce anlatılan, lisans düzeyinde üç kredilik bir seçmeli derstir. Hoca, anlaşılmayan bir yer olursa ders sırasında sorulabileceğini söyledi. İlk birkaç hafta "temellerin temeli" sayılan konular ele alınacak, ardından biyoenformatiğin temel konularına geçilecektir. Hoca her şeyden bahsetmenin mümkün olmadığını, çok temel bazı konulara odaklanılacağını belirtti.

Hocanın vurguladığı bir nokta, bu derste programlama öğretilmeyeceğidir. Bir programlama dili kullanılacaktır, ama anlatılan konular dilden bağımsızdır: Hangi dili biliyorsanız onunla, hocanın deyişiyle Assembler ile bile uygulayabilirsiniz. Önemli olan sahip olduğunuz bilgi ve becerilerle algoritmaları kurabilmektir.

Kaynak olarak birkaç kitap gösterildi: daha biyolojik bir bakış açısı sunan bir kitap, biyolojik dizi analizi (biological sequence analysis) kitabı, dizgiler, ağaçlar ve diziler üzerine algoritmalar kitabı (Algorithms on Strings, Trees and Sequences), Perl tabanlı bir biyoenformatik girişi, "Bioinformatics Computer Skills", biyoenformatik genetikle çok ilişkili olduğu için genlerin ne olduğunu anlatan bir genetik kitabı ve çok temel bir okuma kitabı olarak "Bioinformatics for Dummies". <!-- BELİRSİZ: Kitap slaytları karelerde görünmüyor; kitapların tam adları ve yazarları yalnız altyazıdaki kırık ifadelerden çıkarıldı. -->

## 2. "Bio" ile Başlayan Alanlar

Biyoenformatik kavramını netleştirmek için hoca önce "bio" ile başlayan ve birbirine karışan terimleri tanımladı: biyomedikal mühendisliği, biyomühendislik, biyoteknoloji, klinik ya da tıp mühendisliği, tıbbi teknoloji, sağlık teknolojisi, sağlık bilişimi, biyoenformatik, hesaplamalı biyoloji, sistem biyolojisi ve benzerleri.

### 2.1 Tıp Mühendisliği (Medical Engineering)

Tıp mühendisliği, mühendislik kavramlarını ve teknolojiyi şunların geliştirilmesinde kullanır (ekrandan, 00:25:00):

- enstrümantasyon,
- tanı ve tedavi cihazları,
- yapay organlar,
- sağlık hizmetinde ve hastanelerde gereken diğer tıbbi cihazlar.

Tıp mühendisinin rolü, biyoloji ve tıbbın hangi kısımlarında ileri teknolojinin avantaj sağlayabileceğini belirlemek ve buna göre geliştirme yapmaktır.

### 2.2 Biyomedikal Mühendisliği

Biyomedikal mühendisliği, büyüyen ve genişleyen bir meslektir. Hocanın altını çizdiği özelliği disiplinlerarası olmasıdır. Mühendislik, matematik, hesaplama ve bilim yöntemlerini biyolojik ve fizyolojik problemlerin analizine uygular.

### 2.3 Klinik Mühendislik

Klinik mühendislik, mühendisliğe ek olarak yönetim kavramlarını da kullanır. Amacı hastanelerde sağlık hizmetini iyileştirmek, teknolojinin uygulanmasıyla daha iyi hasta bakımını en düşük maliyetle sağlamaktır. Klinik mühendisler, hasta bakımıyla doğrudan ilgili hizmetleri diğer sağlık profesyonelleriyle birlikte verir ve klinik ortamdaki sorunlarla ilgilenir. Hastane yönetimi, hasta yönetimi ve sağlık yönetimi bu şemsiyenin altına girer. Cihazların etkinliği, tıbbi enstrümantasyonun elektrik güvenliği, sistemler ve güç kaynakları da klinik mühendisin sorumluluğundadır.

### 2.4 Biyomühendislik (Bioengineering)

Biyomühendislik temel araştırma odaklı bir etkinliktir ve şunlarla yakından ilişkilidir (ekrandan, 00:30:00):

- biyoteknoloji,
- genetik mühendisliği: bitkileri ya da hayvanları iyileştirmek veya yeni mikroorganizmalar geliştirmek için hayvan ya da bitki hücrelerinin değiştirilmesi.

Biyomühendisliğin birçok alt alanı vardır. Biyolojik malzemeler, süreçler, implantlar, cihazlar ve enformatik yaklaşımlar; hastalıkların önlenmesi, tanısı ve tedavisi, hasta rehabilitasyonu ve sağlığın iyileştirilmesi için kullanılır.

## 3. Biyomühendislik Şemsiyesi

Hoca, biyomühendisliği bir şemsiye olarak düşünüp altındaki alanları tek tek ekleyen bir slayt gösterdi (ekrandan, 00:35:00 ve 00:45:00). Slaydın son hali şu grupları içerir:

- **Biyomalzemeler (Biomaterials):** ajanlar, nanoparçacıklar, biyouyumluluk (biocompatible), kimyasal kompozitler. Örneğin yeni ortopedik cihazlar ya da implantlar oluşturmak için kullanılır. Hoca bunların çok etkin araştırma alanları olduğunu söyledi.
- **Görüntüleme (Imaging):** ultrason, BT/X ışını, MR, empedans. Hoca bu alanın bilgisayar mühendisliğiyle doğrudan ilişkisinin daha az olduğunu, ama görüntüleme modelleri ve algoritmaları üzerinde çalışılabileceğini belirtti.
- **İşaret işleme (Signal Processing):** EEG, ECG, EMG, ultrason.
- **Biyomekanik (Biomechanic):** implantlar, yapay organlar.
- **Mikro ve nano sistemler:** MEMS, sensörler, SoC, kablosuz iletişim.
- **Rehabilitasyon ve tanı (Rehabilitation & Diagnosis):** simülasyon, modelleme, enstrümantasyon.
- **Tespit ve kestirim (Detection & Estimation):** yapay zekâ, bulanık mantık, sinir ağları.
- **Biyoenformatik (Bioinformatics):** e-sağlık, teletıp, DNA dizi analizi.

### 3.1 Biyomekanik

Biyomekanik temelde implantlar ve yapay organlarla ilgilenir. Rehabilitasyon mühendisliğiyle yakından ilişkilidir; rehabilitasyon mühendisliği hastanın yaşamını iyileştirmeye yönelik mühendislik uygulamalarıdır. Yapay kol, bacak gibi organlar ya da yapay kemik oluşturmak için kullanılan bazı kimyasallar bu alana örnektir.

### 3.2 İşaret İşleme

Biyomedikal mühendisliğinde işaret işleme, fizyolojik işaretleri elde etmek ve işlemek için kullanılan her türlü teknik, algoritma, elektronik ya da sensör anlamına gelir. Amaç, işaretin geldiği doku ya da vücut bölümü hakkında bilgi çıkarmaktır. Hoca örnek olarak ECG'yi sordu; bir öğrenci elektrokardiyogram diye yanıtladı. ECG, kalbin elektriksel etkinliğini incelemek için kullanılan işarettir.

### 3.3 Mikro ve Nano Sistemler

Bu grupta vücuda yerleştirilebilen mikro ve nano sistemler, daha fazla biyolojik ya da fizyolojik işareti algılayacak yeni sensörler ve SoC yer alır. Hoca SoC'nin ne olduğunu sordu ve kendisi açıkladı: SoC (system-on-chip), sensörler ve işlemciler dahil her şeyi tek bir yonga üzerine toplamaya çalışan bir hesaplama sistemidir. Lab-on-chip ve platform-on-chip gibi ilgili kavramlar da vardır. Sistem vücuda yerleştirildikten sonra onunla iletişim kurmak ve veri alışverişi yapmak gerekir; bunun kablosuz yapılması gerekir. Hoca bu konunun aslında düşük güçlü yonga tasarımı olduğunu ve bilgisayar mühendisleri için önemli olduğunu söyledi.

### 3.4 Biyoenformatik Grubu

Hoca e-finans, e-devlet, e-ticaret gibi kavramlardan sonra e-sağlığı (e-health) sordu: elektronik sağlık. Türkiye'deki e-Nabız uygulaması örnek olarak anıldı. Bu grubun diğer öğeleri teletıp ve DNA dizi analizidir. Hoca, ders boyunca DNA ya da amino asit dizi analizi etrafındaki hesaplama kavramlarının biyoenformatik başlığı altında ele alınacağını söyledi.

## 4. Biyoenformatik Nedir?

Hoca iki görsel gösterip ne olduklarını sordu. Öğrenciler birini graf, ötekini uzaydaki yıldızlar ya da veri noktaları gibi gördüklerini söyledi. İlki Wikipedia'dan alınmış internetin bağlantı haritası, ikincisi insan protein etkileşimlerinin haritasıydı. Proteinler ve aralarındaki ilişkiler büyük bir ağ oluşturur. Biyoenformatikte bu tür verileri işlemek için kullanılan araçlar çoğunlukla hesaplama araçlarıdır. Kimya ya da başka alanlar da işin içindedir, ama bu derste işleri çok daha hızlı ve kolay yapmayı sağlayan hesaplama araçlarıyla ilgilenilecektir. <!-- BELİRSİZ: 00:50:30 civarında bir slaytta "259 milyon" ve "0.48" gibi sayılar sözlü geçiyor; slayt karesi boş (00:50:00) ve altyazı bozuk olduğu için bağlam çıkarılamadı. -->

### 4.1 Bilgisayarsız Biyoenformatik

İlk tanım (ekrandan, 00:55:00): Biyoenformatik, bilginin biyolojik sistemlerde, moleküler düzeyden başlayarak nasıl temsil edildiğini ve iletildiğini inceleyen alandır. Hoca anahtar sözcüğün "bilgi" olduğunu söyledi. Slayttaki ek cümle şudur: Bu, bilgisayar gerektirmeyen bir disiplindir.

Hoca bu cümle hakkında ne düşünüldüğünü sordu. Bir öğrenci, eskiden araştırmacıların kâğıtlara çizdiğini, sonra elle "bu A, bu T, bu C, bu G" diye yazdıklarını gördüğünü anlattı. Hoca bunun tam olarak kastedilen şey olduğunu söyledi: Bu iş özünde bilgisayar gerektirmez. Ama günümüzde elde edilen veri miktarı düşünüldüğünde, bilgisayar kullanılmazsa bilgi çıkarmak çok uzun sürer. Bilgisayar, bilgiyi olabildiğince hızlı, ideal olarak anında çıkarmak için kullanılır.

> **Hocanın vurgusu:** Biyoenformatiğin özü bilgidir; bilgisayar bir amaç değil, bilgiyi hızlı çıkarmanın aracıdır.

### 4.2 NIH Tanımı

ABD Ulusal Sağlık Enstitüleri'ne (NIH) göre biyoenformatik (ekrandan, 01:05:00):

> "research, development, or application of computational tools and approaches for expanding the use of biological, medical, behavioral, or health data, including those to acquire, store, organize, analyze, or visualize such data."

Hoca bu tanımdaki kavramları bilgisayar mühendisliğiyle tek tek eşleştirdi. Hesaplama araçları ve yaklaşımları, bilgisayar mühendislerinin ya da bilgisayar bilimcilerinin geliştirdiği algoritmalardır. Biyolojik, tıbbi, davranışsal ya da sağlık verisi, algoritmaların ve programların üzerinde çalıştığı veridir. Edinme (acquire), ham veriyi elde edip sayısala çeviren sistemleri kapsar. Analiz, bilgi çıkarmak için algoritma geliştirmektir. Görselleştirme zaten bilgisayar biliminin bir alanıdır; ham veriyi görsel bilgiye dönüştürür. Bu yüzden biyoenformatiğin birçok yönü doğrudan bilgisayar mühendisliğiyle ilgilidir.

### 4.3 Hesaplamalı Biyoloji ve Diğer Tanımlar

İlişkili disiplin olan hesaplamalı biyoloji; veri analitiği ve kuramsal yöntemlerin, matematiksel modellemenin ve hesaplamalı benzetim tekniklerinin biyolojik, davranışsal ve sosyal sistemlerin incelenmesinde geliştirilmesi ve uygulanmasıdır. Kısaca biyoenformatik; biyolojik araştırmayı kolaylaştırmak ve hızlandırmak için kavramlar, veri tabanları ve algoritmalar geliştirir.

ABD Ulusal İnsan Genomu Araştırma Enstitüsü'nün tanımına göre biyoenformatik, nükleik asit (DNA) ve protein (amino asit) dizi verilerinde bulunan bilginin elde edilmesi ve analiziyle ilgilenen biyoloji dalıdır. <!-- BELİRSİZ: Altyazıda bu tanım "Filogenetik is the branch of biology" diye başlıyor; bağlama göre büyük olasılıkla "Bioinformatics is the branch of biology" denmiştir. -->

### 4.4 Pratik Tanım ve Hesaplama Sistemi

Pratik anlamda biyoenformatik, büyük miktarda verinin şu işlemlerini içeren bir bilimdir (ekrandan, 01:15:00): toplama (collecting), işleme (manipulating), analiz etme (analyzing), iletme (transmitting).

Hoca burada bir hesaplama sisteminin nasıl tanımlandığını, bilgisayarın ne olduğunu ve işlevlerini sordu, ama yanıt gelmedi. Bu soruya sonra döneceğini, ancak toplama, işleme, analiz ve iletim eylemlerinin bir hesaplama sisteminin işlevleriyle çok yakından ilişkili olduğunu söyledi.

### 4.5 Disiplinlerarası Tanım ve "In Silico"

Bir başka tanıma göre biyoenformatik, biyolojik veriyi anlamak için yöntemler ve yazılım araçları geliştiren disiplinlerarası bir alandır. Biyolojik veriyi analiz etmek ve yorumlamak için bilgisayar bilimi, istatistik, matematik ve mühendisliği birleştirir. Hoca istatistiğin her yerde olduğu gibi biyoenformatikte de yoğun kullanıldığını ekledi.

"In silico" ifadesi Latince kökenlidir ve "bilgisayarda ya da bilgisayar benzetimiyle yapılan" anlamında kullanılır.

> **Ek bilgi (derste anlatılmadı):** "In silico" ifadesi, biyolojide yaygın olan "in vivo" (canlı organizmada) ve "in vitro" (cam içinde, yani laboratuvar kabında) ifadelerine benzetilerek türetilmiştir. Silikon, bilgisayar yongalarının temel malzemesi olduğu için bu ad seçilmiştir.

## 5. Biyoenformatiğe Üç Bakış Açısı

### 5.1 Merkezi Dogma

Birinci bakış açısı moleküler biyolojinin merkezi dogmasıdır (ekrandan, 01:10:00). DNA, RNA'ya yazılır (transkripsiyon), RNA'dan protein üretilir ve sonuçta hücresel fenotip ortaya çıkar. Slaytta bunun genomik karşılığı da gösterildi:

```text
Moleküler biyolojinin merkezi dogması:  DNA    -> RNA           -> protein  -> hücresel fenotip
Genomiğin merkezi dogması:              genom  -> transkriptom  -> proteom  -> hücresel fenotip
```

Hoca hücrenin biyolojik olarak ne olduğunun bilindiğini varsaydı. Slayttaki çizimde DNA çekirdeğin içinde, RNA ve protein çekirdeğin dışında gösteriliyordu.

### 5.2 Bireysel Organizma Düzeyi

İkinci bakış açısında genler, RNA transkriptleri ve protein ürünleri bireysel organizma düzeyinde ele alınır. Enformatik araçlar; zamanla gelişim sürecindeki değişimleri, vücut bölgeleri arasındaki değişimleri ve farklı fizyolojik ya da patolojik durumlardaki değişimleri betimlemek için kullanılabilir.

### 5.3 Yaşam Ağacı

Üçüncü bakış açısı yaşam ağacıyla temsil edilir. Biyoenformatiğin kapsamı yeryüzündeki bütün yaşamı, yani bakteriler, arkeler ve ökaryotlardan oluşan üç büyük dalı içerir. Hoca bu ağaçların nasıl elde edildiğinden ileride bahsedileceğini söyledi. <!-- BELİRSİZ: Altyazıda üçüncü dal "nükleotis/nuclear" diye geçiyor; büyük olasılıkla "eukaryota" (ökaryotlar) denmiştir. Slayt karesi yok. -->

## 6. Biyoenformatiğin Teknikleri ve Kuramsal Temelleri

Biyoenformatiğin birincil amacı biyolojik süreçlerin anlaşılmasını artırmaktır. Odak noktası bu amaca ulaşmak için hesaplama tekniklerini geliştirmek ve uygulamaktır. Kullanılan teknikler şunlardır: örüntü tanıma, veri madenciliği, makine öğrenmesi, algoritmalar ve görselleştirme.

Biyolojik veriyi analiz edip anlamlı bilgi üretmek, graf kuramı, yapay zekâ, yumuşak hesaplama, veri madenciliği, işaret işleme, görüntü işleme ve bilgisayar benzetimi algoritmalarını kullanan yazılımlar yazmayı gerektirir. Bu algoritmalar da ayrık matematik, kontrol kuramı, sistem kuramı, bilgi kuramı ve istatistik gibi kuramsal temellere dayanır. Hoca, ayrık matematik için ayrı bir dersin olduğunu, kontrol kuramı dersi olmasa da ne olduğunun bilindiğini, bilgi kuramı ve istatistikte de geniş birikim bulunduğunu hatırlattı.

Biyoenformatiğin kapsamındaki veri kaynakları arasında genetik kod, çeşitli kaynaklardan deney sonuçları, hasta istatistikleri (yaş, kilo, ateş gibi) ve bilimsel literatür vardır. Bilimsel literatürden bilgi çıkarmak, metin verisi üzerinde hesaplama teknikleri kullanmayı, yani doğal dil işlemeyi gerektirir. Biyoenformatik araştırması bu verilerin saklanması için yöntem geliştirmeyi de içerir.

## 7. DNA ve Turing Makinesi

Hoca DNA dizisi ile bir bilgisayar programı arasında güçlü bir benzerlik olduğunu söyledi. DNA aslında bir bilgi saklama sistemidir.

Turing makinesi (Alan Turing'in adıyla) herhangi bir hesaplama sistemini benzetebilen kuramsal bir modeldir. Temel öğeleri şunlardır:

- bir kontrol birimi,
- bir şerit,
- bir okuma-yazma kafası.

Okuma-yazma kafası şerit boyunca hareket eder ve kontrol birimine bilgi taşır, ondan bilgi alır.

Merkezi dogmada da benzer bir bilgi akışı vardır. DNA'daki kod (kodlayan iplik, coding strand) mesajcı RNA'ya (mRNA) aktarılır, mRNA'dan protein üretilir ve protein vücutta bir molekül ya da yapı olarak iş görür. Hoca bu bilgi akışının kavramsal olarak Turing makinesine çok benzediğini vurguladı. <!-- BELİRSİZ: Turing makinesi ve merkezi dogma karşılaştırma slaytının karesi yok; şeritle DNA'nın, kafayla hangi molekülün eşleştirildiği altyazıdan çıkmıyor. -->

## 8. İyi Bir Biyoenformatikçi Olmak

Hoca iyi bir biyoenformatikçi olmak için gerekenleri sıraladı:

- Önce biyolojiyle tanışmak, temel biyolojiyi öğrenmek gerekir. Lisede öğrenilen temel biyoloji iyi bir başlangıçtır.
- Biyoenformatikte iki tür insan vardır: araç kullanıcıları (tool users) ve araç geliştiriciler (tool generators). Bilgisayar mühendisleri büyük olasılıkla araç geliştirici olacaktır.
- Bir programlama dili öğrenmek gerekir: Perl, Python, Java, MATLAB ya da başka bir dil. Hoca öğrencilerin zaten birkaç dil bildiğini söyledi.
- Bilgisayarda deney yapmak ve farklı programlama tekniklerini öğrenmek gerekir.

Hoca, bilgisayar mühendislerinin biyoenformatiğin hesaplama tarafı düşünüldüğünde zaten "yarı biyoenformatikçi" olduklarını, becerilerin neredeyse yarısına sahip olduklarını söyledi.

## 9. Biyoenformatiğin Uygulama Alanları

Biyoenformatik şu alanlarda yoğun olarak kullanılır:

- **İlaç tasarımı:** İlaç tasarım yaşam döngüsünü kısaltmak için.
- **Toksikoloji:** Hoca Türkçesini "zehir bilim" diye verdi.
- **Moleküler evrim:** Özelliklerin tarihsel olarak nasıl evrildiğini anlamak için.
- **Biyosensörler** ve **biyomalzemeler** geliştirmek için.
- **Biyolojik hesaplama modelleri:** Örneğin DNA hesaplama (DNA computing) gibi, DNA'nın bir hesaplama sisteminde kullanıldığı modeller.
- **Genetik ve kalıtsal hastalıklar:** Örneğin diyabet.
- **Viral hastalıklar:** Virüsün yapısını anlayıp ona karşı ilaç geliştirmek. Hoca, yaşanan COVID-19 salgınında virüsü anlamak için biyoenformatiğin yoğun kullanıldığını hatırlattı.

## 10. Hesaplamalı Biyolojinin Kapsamı

Slayttaki iç içe kümeler şunu gösterir (ekrandan, 01:30:00): En dışta hesaplamalı biyoloji vardır, onun içinde biyoenformatik, biyoenformatiğin içinde birbiriyle kesişen genomik ve proteomik, proteomiğin içinde de yapısal biyoenformatik yer alır. Genomik ile proteomiğin kesişimi de ayrıca işaretlenmişti.

Hesaplamalı biyoloji ve biyoenformatik çoğu zaman birbirinin yerine kullanılır, ama hesaplamalı biyoloji daha geniş bir şemsiye kavramdır, çünkü enformatiği de kapsar. Hoca kesişim bölgesi için yapısal biyoenformatikten çok daha zor bir alan olan fonksiyonel genomikten bahsetti. Fonksiyonel genomik, biyolojik yapıların nasıl oluştuğundan çok nasıl işlediğiyle ilgilenir.

Hoca bu tanımların uzun ve sözel olduğunu bildiğini, ama derse başlamadan önce bunların gerçekten önemli olduğunu söyledi.

### 10.1 Genomik

Genomik, genomun incelenmesidir. Hoca "-ics" ekinin bir kavramın sonuna geldiğinde o kavramın incelenmesi anlamına geldiğini açıkladı. Genom, bir organizmadaki genetik malzemenin, yani DNA'nın tamamıdır. Biyoenformatik, genomik çalışmalar için birçok algoritmanın geliştirilmesinde yer alır.

### 10.2 Proteomik

Proteomik, proteomların büyük ölçekli incelenmesidir (ekrandan, 01:35:00). Proteom, bir organizma, sistem ya da biyolojik bağlamda üretilen proteinlerin bütünüdür. Örneğin bir türün (Homo sapiens) ya da bir organın (karaciğer) proteomundan söz edilebilir. Proteom sabit değildir: hücreden hücreye farklılık gösterir ve zamanla değişir.

Proteinler merkezi dogmanın gerçekleşmesiyle, yani transkripsiyon ve translasyon süreçleriyle (protein sentezi) üretilir. Proteom bir ölçüde altta yatan transkriptomu yansıtır. Ancak protein etkinliği, ilgili genin ifade düzeyine ek olarak başka birçok etkenle de düzenlenir. Bu etkenleri incelemek çok daha zordur.

Proteomik şunları incelemek için kullanılır:

- proteinlerin ne zaman ve nerede ifade edildiği,
- protein üretim ve yıkım hızları ile kararlı durum miktarları,
- proteinlerin nasıl değiştirildiği (modifikasyon),
- proteinlerin hücre içi bölmeler arasındaki hareketi,
- proteinlerin metabolik yolaklara katılımı,
- proteinlerin birbiriyle nasıl etkileştiği.

### 10.3 Yapısal Biyoenformatik

Yapısal biyoenformatik, biyoenformatiğin bir dalıdır. Proteinler, RNA ve DNA gibi biyolojik makromoleküllerin üç boyutlu yapısının analizi ve tahminiyle ilgilenir. Hoca bunu biyoenformatiğin "kolay kısmı" olarak niteledi. Biyoenformatik verisiyle çalışacak programlar yazmak için bu biyolojik yapılar hakkında temel bilgiye ihtiyaç vardır.

### 10.4 Fonksiyonel Genomik

Fonksiyonel genomik, moleküler biyolojinin bir alanıdır (ekrandan, 01:40:00). Genomik ve transkriptomik projelerinin (genom dizileme projeleri ve RNA dizileme gibi) sağladığı büyük veri birikimini, gen ve protein işlevlerini ve etkileşimlerini betimlemek için kullanmaya çalışır. Yapısal genomikten farklı olarak, DNA dizisi ya da yapılar gibi genomik bilginin statik yönleri yerine gen transkripsiyonu, translasyon, gen ifadesinin düzenlenmesi ve protein-protein etkileşimleri gibi dinamik yönlere odaklanır.

Hoca yapısal genomiğin oldukça gelişmiş bir alan olduğunu, fonksiyonel genomiğin ise hâlâ gelişmekte olduğunu söyledi. Protein-protein ya da gen-gen etkileşimleri biyoenformatikte hâlâ sıcak konulardır. Bu etkileşimleri anlamak, örneğin kanserin gelişimini anlamak açısından çok önemlidir.

## 11. Biyoenformatik Neden Hâlâ Sıcak Bir Alan?

Hocaya göre bunun nedeni arz ve taleptir. Hem biyolojide hem bilgisayar biliminde yeterince eğitimli çok az insan vardır. Buna karşılık genom dizileme, mikrodiziler ve benzeri teknolojiler analiz edilmesi gereken çok büyük miktarda veri üretmiştir. Bu veri büyük veri (big data) kavramının da kapsamına girer.

## 12. İlaç Geliştirme Yaşam Döngüsü

Hoca ilaç geliştirme sürecini bir zaman çizelgesi üzerinde anlattı (ekrandan, 01:45:00). Slayttaki zaman ekseni 0'dan 16 yıla kadar uzanır.

- **Keşif (Discovery):** 2-10 yıl.
- **Klinik öncesi test (Preclinical Testing):** laboratuvar ve hayvan deneyleri.
- **Faz I:** Güvenlik ve dozu denetlemek için 20-30 sağlıklı gönüllü kullanılır. Hoca bu aşamanın yaklaşık bir yıl sürdüğünü söyledi.
- **Faz II:** Etkinlik ve yan etkileri denetlemek için 100-300 hasta gönüllü kullanılır. Hoca sonraki iki yılın Faz II'ye ayrıldığını söyledi.
- **Faz III:** Sözlü anlatıma göre 1000-5000 hasta üzerinde, ilacı kullanan hastaların bütün tepkileri uzun süreli kullanım için izlenir. <!-- BELİRSİZ: Faz III satırı kareye girmedi (01:45:00 karesinde slayt Faz II'de); değerler altyazıdan alındı. -->
- **Onay:** Bu aşamada ilacın yetkili kurumlarca onaylanması gerekir. Hoca toplam sürenin 10-12 yıla ulaştığını söyledi.

> **Ders sonrası not:** Hoca ABD'deki onay kurumunu "Federal Drug Agency" diye andı (altyazıda "FASTA, Federal Drug Agency" olarak geçiyor). Kurumun adı Food and Drug Administration'dır (FDA). Türkiye'deki karşılığı için hoca Sağlık Bakanlığı olabileceğini, emin olmadığını söyledi.

Hoca ardından her fazı geçen ilaç adaylarının oranlarını gösterdi. <!-- BELİRSİZ: 01:49:11 civarında "Phase I, 30% past Phase II, 80% past Phase III" gibi bozuk bir ifade var; oranların hangi faza ait olduğu ve slayttaki tam değerler çıkarılamadı, kare yok. -->

Ayrıca bir ilacın piyasaya çıkış süresinin ortalama 12 yılın üzerinde olduğu belirtildi (ekrandan, 01:55:00). Biyoenformatik bu uzun döngüyü kısaltmak için kullanılır.

## 13. Killer Application: Kişiselleştirilmiş Tıp

Slayttaki tanıma göre (ekrandan, 01:50:00), biyoteknoloji endüstrisinde her araştırmacı ve girişimci bir sonraki "killer app"i geliştirmeyi ya da keşfetmeyi umar: dünyayı kapısına getirecek, Ar-Ge, pazarlama ve üretim için fon sağlayacak tek uygulama. Örneğin genel hesaplamada elektronik tablolama (spreadsheet) ve masaüstü lazer yazıcı dikkat çekici killer app'lerdi.

Hocaya göre biyoenformatiğin killer application'ı kişiselleştirilmiş tıptır. Bugün bir sağlık sorunuyla doktora gittiğinizde doktor size belirli bir ilaç yazar. Başka biri aynı şikâyetle gelebilir, ama farklı bir insan olduğu için sorununun nedeni farklı olabilir. İdeal olan, her kişiye kendi durumuna uygun ilacın verilmesidir. Hoca bunun modern tıp, yani kişiselleştirilmiş tıp olduğunu söyledi.

Bunun için büyük bir altyapı gerekir. Hastadan doku örneği alınır, mikrodizi ile bu kişinin gen ifadesi elde edilir. Bu bilgi; tıbbi önem, tedaviye ilişkin bilgiler ve kaynaklarla birlikte bir hesaplama sistemi olan örüntü tanıma sistemine verilir ve kişiye özel ilaç tasarlanır. Kişiselleştirilmiş ilacın makul bir sürede hazır olması gerekir.

Hoca bunun gerçekleştirilmesi için ne yapılabileceğini sordu (bkz. Örnek Sorular). Kendi yanıtına göre çok yüksek başarımlı bir hesaplama sistemi kullanmak gerekir. <!-- BELİRSİZ: 01:54-01:55 arası altyazı bozuk; hocanın önerdiği çözümün ayrıntısı çıkarılamadı. -->

## 14. Biyoenformatik Araçları

Biyoenformatik araçları iki tür arayüzle sunulur:

- **Web tabanlı grafik kullanıcı arayüzleri:** Genellikle araç kullanıcıları içindir. Biyoenformatik kavramlarını analizlerinde kullanması gereken ama hesaplama kavramlarına aşina olmayan kişiler bu araçları kullanır.
- **Komut satırı arayüzleri:** Genellikle Linux sistemlerinde çalışır ve araç geliştiriciler tarafından tercih edilir. Kolay bir insan-bilgisayar etkileşimi sunmadıkları için daha çok geliştiricilere uygundur.

Slaytta BioMart, genom tarayıcıları ve BLAST gibi araçlar gösterildi; bazılarına ileride değinilecektir. Komut satırı yazılımları mevcuttur, ama kendi yazılımınızı da geliştirebilirsiniz. <!-- BELİRSİZ: Araç adları altyazıda "Biomar, Genome, Wolfgang, BLAST" diye geçiyor; slayt karesi yok. -->

Araç kullanıcıları temelde halk sağlığı enformatiği, tıp enformatiği ve biyoenformatik becerileri olan kişilerdir. Araç geliştiriciler ise genellikle bilgisayar bilimciler ve bilgisayar mühendisleridir.

> **Ek bilgi (derste anlatılmadı):** BLAST (Basic Local Alignment Search Tool), bir DNA ya da protein dizisini veri tabanındaki dizilerle hızlıca karşılaştırıp benzer dizileri bulan, yaygın kullanılan bir dizi hizalama aracıdır. Hem web arayüzü hem komut satırı sürümü vardır.

## 15. Programlama Öğrenme ve Tekrarlanabilir Araştırma

### 15.1 Biyoenformatik İçin Programlama Öğrenmek

Hoca öğrencilerin programlamayı zaten bildiğini, ama genel kuralları yine de hatırlatmak istediğini söyledi. Mevcut kitap ve derslere ek olarak birçok web sitesi öğretici ya da kurs biçiminde çevrim içi eğitim sunar. Çevrim içi öğrenme kuralları şunlardır (ekrandan, 02:00:00):

- bir plan yap,
- seçici ol,
- öğrenme ortamını düzenle,
- okumaları yap,
- alıştırmaları yap,
- değerlendirmeleri yap,
- kolaylık gibi avantajlardan yararlan.

Hoca okumaların ve alıştırmaların özellikle önemli olduğunu vurguladı ve Konfüçyüs'e (belki de genel bir Çin atasözüne) atfedilen sözü aktardı: "Duydum, unuttum. Gördüm, hatırladım. Yaptım, öğrendim." Deney yapmak, kalıcı öğrenmenin en iyi yoludur.

Hoca belgelemenin önemini programlama sırasında yaşanan bir örnekle anlattı ve belgelemenin her zaman, her tür veri kaydı için önemli olduğunu söyledi. <!-- BELİRSİZ: 02:01-02:02 arasında belgeleme örneğinin ayrıntısı altyazıda bozuk. --> Son olarak, ne öğrenebileceğiniz konusunda beklentilerinizde gerçekçi olmanız gerektiğini ekledi.

### 15.2 Biyoenformatikte Tekrarlanabilir Araştırma

Tekrarlanabilir araştırma için kurallar (ekrandan, 02:15:00):

- Bir iş akışı iyi belgelenmelidir. Bu, karmaşık komutları, URL'leri ya da diğer veri biçimlerini kopyalayıp yapıştırabileceğiniz metin belgelerini bilgisayarınızda tutmayı içerebilir.
- İşinizi kolaylaştırmak için bilgisayarda saklanan bilgi iyi düzenlenmelidir. Hoca bunun veri tabanı demek olduğunu söyledi.
- Veri başkalarının kullanımına açılmalıdır. Hocaya göre veri, anlaşılır bir biçimde serbestçe erişilebilir olmalıdır.
- Üst veri (metadata) de önemlidir. Hoca metadatanın ne olduğunu sordu (bkz. Örnek Sorular).

### 15.3 Biyoenformatik Araştırma Alanları

Hoca araştırma alanlarını özetledi: genomik, transkriptomik, proteomik, epigenetik, interaktomik, protein analizi ve yapı tahmini, yeni nesil dizileme teknolojisi, karşılaştırmalı analiz, sistem biyolojisi, metin madenciliği ve bilgi çıkarımı. Bunlar araştırma yapılabilecek ya da çalışılabilecek alanlardır. İnternette daha fazla öğrenmek için birçok kaynak vardır.

Bu bölümün sonunda hoca biyoenformatiğin birçok dersin kavramlarını birleştiren bir konu olduğunu özetledi: veri madenciliği, yapay zekâ, istatistik, biyoloji, yeri geldiğinde kimya, doğal dil işleme ve dil bilimi bu işin içindedir.

## 16. Bilgi Sistemlerinin Temelleri

Hoca asıl konulara girmeden önce, her derste tekrar hatırlattığı bilgi teknolojisi kavramlarını anlattı.

### 16.1 Enformatik

Ders "biyoenformatiğe giriş" olduğu için önce enformatik kavramı tanıtıldı. Enformatik, bilgiyi oluşturma, saklama, bulma, işleme ve paylaşma pratiğini ve incelenmesini geniş biçimde tanımlar. Bu tanımda kendimizi bir hesaplama sistemiyle sınırlamayız, çünkü bu işler elle, kalem ve kâğıtla da yapılabilir. Yine de tanımlar büyük ölçüde bir hesaplama sistemine işaret eder.

Terimin kökeni (ekrandan, 02:25:00):

- 1956'da Alman bilgisayar bilimci Karl Steinbuch "Informatik" sözcüğünü türetti: *Informatik: Automatische Informationsverarbeitung*, yani "Enformatik: Otomatik Bilgi İşleme".
- Fransızca "informatique" terimi 1962'de Philippe Dreyfus tarafından türetildi (Dreyfus, Philippe. L'informatique. Gestion, Paris, Haziran 1962, s. 240-241).
- Terim, otomatik bilgi etkileşimlerinin bilimini tanımlamak için "information" ve "automatic" sözcüklerinin birleşimi olarak türetildi.

Hoca otomatik bilgi etkileşimleri bilimi ile programlama arasındaki paralelliği sordu ve yanıtladı: Elbette bunu programlama aracılığıyla yaparız. Bazı üniversitelerde bilgisayar bilimi ya da bilgisayar mühendisliği programları "School of Informatics" ya da "Department of Informatics" adını taşır. Morfolojik olarak informatics, "information" ve "-ics" ekinden oluşur.

### 16.2 Veri, Bilgi ve Bilgi Birikimi

**Veri (data):** Herhangi bir yorum ya da analiz eklenmemiş, işlenmemiş olgular ve sayılardır (ekrandan, 02:30:00). Hocanın örneği: Bir ECG sistemini hastaya bağlarsınız, sistemin kalpten topladığı işaretler sabit diske kaydedilir. Ham haliyle bu basit bir veridir.

Hoca bu ECG verisini neden kaydettiğimizi sordu. Yanıt şudur: Veriyi işlemek için kaydetmeyiz, bilgi çıkarmak için kaydederiz. Bilgi çıkarabilmek için işleriz. Yani amaç işlemek değil, bilgiyi çıkarmaktır.

> **Hocanın vurgusu:** Veriyi işlemek bir araçtır; asıl amaç veriden bilgi çıkarmaktır.

**Bilgi (information):** Veriden işleme yoluyla çıkarılan anlamdır. <!-- BELİRSİZ: Bilgi tanımının slayt metni ve 02:31:52 civarında verilen ham petrol fiyatı örneği altyazıda bozuk ("krued oil'a 80 TL'ye kadar"); örneğin tam içeriği çıkarılamadı. -->

**Bilgi birikimi (knowledge):** Bilgiden daha fazlasıdır. Daha önce çıkarılmış bilginin, geçmiş deneyimlerin ve iç görünün (insight) birleşimidir ve bireye ya da kuruma fayda sağlayabilir. İç görü, sözlük tanımıyla, birini ya da bir şeyi doğru ve derinlemesine anlama yetisidir.

Faydalı olabilmek için verinin bazı koşulları sağlaması gerekir:

- belirli amaçla ilgili (relevant) olmalı,
- eksiksiz (complete) olmalı,
- doğru (accurate) olmalı,
- zamanında (timely) olmalı.

Sonuçta önemli olan "doğru bilgiyi almak ve bilgiyi doğru almak"tır. Veri olmadan bütün işlemler anlamsızdır.

### 16.3 Sistem

Sistem kavramından sık söz edildiği için hoca bir hatırlatma yaptı. Sistem kavramı özellikle kontrol kuramında ve kontrol sistemleri kuramında çok kullanılır, ama genel olarak her yerde karşımıza çıkar. Farklı mühendislik dallarından insanların sisteme bakışları farklıdır:

- Yazılım mühendisleri birbiriyle bütünleşik bir bilgisayar programları kümesini sistem olarak görür.
- Elektrik mühendisleri karmaşık bir tümleşik devreyi ya da bütünleşik elektrik birimlerini sistem olarak görür.
- Bilgisayarın kendisine de sistem denir.

Bütün bu bakışlardan çıkan ortak tanım şudur: Sistem, tanımlı bir amacı gerçekleştiren bütünleşik öğeler kümesidir. Daha ayrıntılı tanıma göre sistem, parçaların ya da bileşenlerin düzenli bir biçimde birbirine bağlandığı bir bütündür. Parçalar sistemde bulunmaktan etkilenir ve sistemi de etkiler. Bu bütün bir iş yapar ve özel bir ilgi alanı olarak tanımlanmıştır. Her türlü kaynağın işlenmesini ya da yönetilmesini içeren düzenlemeler sistem olarak temsil edilebilir. Sınıf sistemi, okul sistemi, ekonomik sistem, siyasi sistem, trafik sistemi gibi birçok sistemden söz edilebilir, ama hepsinde birkaç bileşen vardır.

Kontrol kuramı açısından sistemlerin girdileri, süreçleri ve çıktıları ile bir geri beslemesi vardır (ekrandan, 02:45:00):

```text
Girdi -> Süreç -> Çıktı
  ^                  |
  +-- Geri besleme <-+
```

<!-- BELİRSİZ: 02:43-02:45 arasında hocanın geri beslemeli sisteme verdiği örnek (sensör, beyin, eyleyici geçen bir insan örneği) altyazıda bozuk. -->

### 16.4 Bilgi Sistemleri ve Bilgi Teknolojisi

Bilgi sistemleri, kurumların bilgiyi saklama, taşıma, düzenleme ve işleme yolları olarak tanımlanabilir. Hoca bunun temelde bir hesaplama sisteminin tanımı olduğunu söyledi.

Bilgi teknolojisi, bilgi sistemlerini gerçekleştiren bileşenlerdir:

- **Donanım:** Yalnız bilgisayar değil, kalem ve kâğıt gibi düşük teknolojili şeyler de donanımdır.
- **Yazılım:** Donanım için değiştirilebilir komutlardır.
- **İnsanlar:** Bilgi sisteminin bir parçasıdır.
- **Prosedürler.**

### 16.5 Sayısal Sistem

Sayısal sistem, ayrık bilgi girdilerini ve ayrık iç bilgiyi (sistem durumlarını) alıp ayrık bilgi çıktıları üreten bir sistem olarak tanımlanabilir. Girdileri, iç sistem durumları ve çıktıları vardır; ileri beslemeli ya da geri beslemeli olabilir. En önemli özelliği, sistemdeki bütün bilginin, yani verinin ayrık olmasıdır.

Hoca "ayrık nedir?" diye sordu. Bir öğrencinin yanıtı ve hocanın eklemeleri Örnek Sorular bölümündedir. Özetle: İnsan olarak sonsuz bir ömrümüz, sonsuz gücümüz ve sonsuz depolama yerimiz yoktur. Bu yüzden sonlu sayıda bilgiye sahip olmamız gerekir; veri ayrık olmalıdır. Ayrık bir işarette belirli anlarda karşılık gelen bir değer vardır, ama zamanın büyük kısmında değer yoktur. Hoca bir sonraki derste sonsuz bilgi içeren bir verinin sonlu bilgi içeren bir veriye nasıl dönüştürüleceğini anlatacağını söyledi.

Sayısal bilgisayar kullanan bir sistemde klavye, fare, modem, mikrofon gibi girdi-çıktı birimleri bulunur.

### 16.6 Tipik Ölçüm Sistemi

Hoca tipik bir ölçüm sisteminin blok şemasını gösterdi (ekrandan, 02:55:00):

```text
Fizyolojik ya da dış enerji
  -> Dönüştürücü (Transducer)
  -> Yükselteç / Algılayıcı (Amplifier / Detector)
  -> Analog işaret işleme
  -> [Bilgisayar]
       Analog-sayısal dönüştürücü
       -> İşaret saklama ya da tamponlama
       -> İşaret işleme
       -> Görüntüleme
```

Girişte sürekli bir değişken biçiminde fizyolojik ya da dış bir enerji vardır. Örneğin bir sıcaklık aralığını, müziği ya da konuşmayı bir hesaplama sisteminde saklamak istiyoruz. Sürekli bir büyüklüğü (sıcaklık, ısı, basınç, hava basıncı, ses ya da ışık) dönüştürmenin ilk adımı onu bir dönüştürücüden geçirmektir. Dönüştürücü, fiziksel büyüklüğü elektrik enerjisine çevirir; mikrofon buna bir örnektir. Dönüştürücünün çıkışı genellikle çok küçük olduğu için sonraki adım bu enerjiyi yükseltmektir. Ardından analog-sayısal dönüştürücü (ADC) adı verilen özel bir aygıtla sürekli işaret sayısal işarete çevrilir, saklanır ve işlenir.

Girdi dönüştürücülerine sensör (algılayıcı), çıktı dönüştürücülerine eyleyici (actuator) denir.

> **Ek bilgi (derste anlatılmadı):** Analog-sayısal dönüşüm iki adımda düşünülebilir: örnekleme (sürekli zamanın belirli anlarda değer alınarak ayrıklaştırılması) ve nicemleme (sürekli genliğin sonlu sayıda düzeye yuvarlanması). Hocanın bir sonraki derste anlatacağını söylediği "sonsuz bilgiden sonlu bilgiye dönüşüm" büyük olasılıkla bu iki adımdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:37:15): ECG nedir?

> **Cevap (derste verildi):** Bir öğrenci elektrokardiyogram diye yanıtladı. Hoca, ECG'nin kalbin elektriksel etkinliğini incelemek için kullanılan işaret olduğunu ekledi.

**Soru 2** (derste sözlü, 00:39:45): SoC nedir, duydunuz mu?

> **Cevap (derste verildi):** SoC, system-on-chip demektir. Bir hesaplama sisteminin sensörler ve işlemciler dahil her şeyini tek bir yonga üzerinde toplamaya çalışır. Lab-on-chip ve platform-on-chip benzer kavramlardır. Vücuda yerleştirilen bir SoC ile veri alışverişi kablosuz yapılmalıdır.

**Soru 3** (derste sözlü, 00:44:18): E-sağlık (e-health) denince ne anlıyorsunuz?

> **Cevap (derste verildi):** Elektronik sağlık. Hoca e-Nabız'ı örnek verdi.

**Soru 4** (ekrandan, 00:55:00): "Biyoenformatik, bilginin biyolojik sistemlerde moleküler düzeyden başlayarak nasıl temsil edildiğini ve iletildiğini inceler" tanımına göre biyoenformatik bilgisayar gerektiren bir disiplin midir?

> **Cevap (derste verildi):** Hayır, bu tanıma göre bilgisayar gerektirmez; eskiden dizi verisi kâğıt üzerinde elle okunuyordu. Ancak günümüzdeki veri miktarında bilgisayar olmadan bilgi çıkarmak çok uzun sürer. Bilgisayar, bilgiyi olabildiğince hızlı, ideal olarak anında çıkarmak için kullanılır.

**Soru 5** (derste sözlü, 01:14:53): Bir hesaplama sistemini nasıl tanımlarız? Bilgisayar nedir, işlevleri nelerdir?

> **Çözüm (derste verilmedi):** Hoca soruya sonra döneceğini söyledi; yalnız biyoenformatiğin pratik tanımındaki toplama, işleme, analiz ve iletim eylemlerinin bir hesaplama sisteminin işlevleriyle çok ilişkili olduğunu belirtti. Dersin sonundaki tanımlara göre bilgisayar, ayrık girdiler ve ayrık iç durumlarla ayrık çıktılar üreten bir sayısal sistemdir; bilgiyi alır (girdi), işler, saklar ve iletir ya da sunar (çıktı).

**Soru 6** (derste sözlü, 01:53:33): Kişiselleştirilmiş ilaç sistemini gerçekleştirmek isteseydiniz ne yapılabilirdi, ne önerirsiniz?

> **Cevap (derste kısmen verildi):** Öğrencilerden yanıt gelmedi. Hoca, kişiye özel ilacın makul sürede hazırlanabilmesi için çok yüksek başarımlı bir hesaplama sistemi kullanmak gerektiğini söyledi. <!-- BELİRSİZ: Hocanın yanıtının devamı altyazıda bozuk. -->

**Soru 7** (derste sözlü, 02:15:09): Metadata (üst veri) nedir?

> **Çözüm (derste verilmedi):** Derste yanıt altyazıda net değil. Üst veri, "veri hakkındaki veri"dir: bir veri kümesinin ne olduğunu, nasıl, ne zaman ve kim tarafından üretildiğini, biçimini ve birimlerini açıklayan bilgidir. Tekrarlanabilir araştırmada verinin başkalarınca anlaşılabilmesi için gereklidir.

**Soru 8** (derste sözlü, 02:47:41): Ayrık (discrete) ne demektir?

> **Cevap (derste verildi):** Bir öğrenci, zaman ekseni sonsuz parçaya bölünebildiği için bilgisayara sonsuz bilgi giremeyeceğimizi, bu yüzden zamanı parçalara böldüğümüzü söyledi. Hoca bunu iyi bir yanıt olarak niteledi ve ekledi: Sonsuz ömrümüz, gücümüz ve depolama yerimiz olmadığı için sonlu sayıda bilgiye sahip olmalıyız, yani veri ayrık olmalıdır. Ayrık işarette belirli anlarda değer vardır, aradaki zamanların çoğunda değer yoktur.

**Soru 9** (derste sözlü, 02:53:12): Tipik ölçüm sisteminde dönüştürücünün (transducer) çıkışı ne türdendir? Örneğin girişte 30 derece gibi bir sıcaklık varsa çıkışta ne olur?

> **Cevap (derste verildi):** Elektrik enerjisi, yani dönüştürücü çıkışında bir gerilim ya da akım. Analog bir değişkeni dönüştürmenin ilk adımı onu dönüştürücüden geçirmektir; çıkış genellikle çok küçük olduğu için ardından yükseltilir.

## Dersin Toparlaması

Bu ilk derste biyoenformatiğin hangi geniş alanın parçası olduğu gösterildi. Tıp mühendisliği, biyomedikal mühendisliği, klinik mühendislik ve biyomühendislik tanımlandı; biyomühendislik şemsiyesinin altında biyomalzemeler, görüntüleme, işaret işleme, biyomekanik, mikro/nano sistemler, rehabilitasyon, tespit-kestirim ve biyoenformatik yer aldı. Biyoenformatik farklı kaynaklardan tanımlandı: özünde biyolojik sistemlerde bilginin temsil ve iletimini inceleyen, bilgisayarsız da yapılabilen ama büyük veri nedeniyle hesaplama araçlarına dayanan bir alan. Merkezi dogma, DNA ile Turing makinesi benzetmesi, hesaplamalı biyolojinin kapsamı (genomik, proteomik, yapısal biyoenformatik, fonksiyonel genomik), ilaç geliştirme döngüsü ve kişiselleştirilmiş tıp, biyoenformatik araçları ve tekrarlanabilir araştırma ilkeleri ele alındı.

Dersin son bölümünde bilgi sistemlerinin temelleri hatırlatıldı: enformatik teriminin kökeni, veri-bilgi-bilgi birikimi ayrımı, sistem ve sayısal sistem kavramları ile sürekli bir fiziksel büyüklüğü bilgisayara aktaran tipik ölçüm sistemi. Hoca, bir sonraki derste sonsuz bilgi içeren sürekli bir verinin sonlu bilgi içeren ayrık bir veriye nasıl dönüştürüleceğini ve diğer temel kavramları anlatacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
