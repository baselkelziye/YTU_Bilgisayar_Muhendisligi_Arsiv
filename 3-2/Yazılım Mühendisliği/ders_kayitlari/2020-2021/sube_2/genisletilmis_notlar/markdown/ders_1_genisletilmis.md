# Ders 1 Genişletilmiş Notu: Yazılım Mühendisliğine Giriş, Yazılım Türleri, Eğilimler ve Yanılgılar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı, Kaynak Kitaplar ve Yazılım Yaşam Döngüsüyle İlişkisi
- 2. Yazılımın Tanımı, Belgelendirmenin Önemi ve Yaşam Döngüsü
- 3. Yazılım Neden Eskir? Aşınma ve Yetersizleşme Farkı
- 4. Yazılım Türleri ve Mühendislik Gereksinimleri
- 5. Eski Yazılım (Legacy Software): Sorunlar ve Yenilenme Zorunluluğu
- 6. Yazılımı ve Yazılım Mühendisliğini Etkileyen Eğilimler
- 7. Yazılım Hakkındaki Yanılgılar: Müşteri Açısından
- 8. Yazılım Hakkındaki Yanılgılar: Programcı Açısından ve Proje Başarı Oranları
- 9. Yazılım Hakkındaki Yanılgılar: İdari Açıdan
- 10. Soru-Cevap: Tasarım Kalıpları, Kötü Kod Kokuları ve Yeniden Düzenleme
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Kapsamı, Kaynak Kitaplar ve Yazılım Yaşam Döngüsüyle İlişkisi

Yazılım Mühendisliği dersi, bir yazılım ürününün fikir aşamasından başlayarak geliştirilmesi, sınanması ve yönetilmesi sürecindeki temel mühendislik etkinliklerini ele alır. Yazılım mühendisliği yalnızca kuramsal bir çalışma alanı değil, sektörde çok hızlı gelişen ve pratik uygulamaları sürekli güncellenen bir disiplindir. Örneğin geçmişte çevik (*agile*) yazılım geliştirme süreçleri çok az bilinirken, günümüzde geleneksel şelale (*waterfall*) modeliyle birlikte sektörde en yaygın kullanılan iki ana süreç ailesinden biri hâline gelmiştir.

Hoca, ders sunumlarını ve içeriğini oluştururken hem kuramsal temelleri hem de uygulamalı modelleme/tasarım çalışmalarını kapsayan dört ana kaynak kitaptan yararlandığını belirtmiştir (ekrandan, 00:10:00):

- **Roger S. Pressman**, *Software Engineering: A Practitioner's Approach*, McGraw-Hill, 2014, 8. baskı (dersin kuramsal ve süreç odaklı bölümleri için ana kaynak).
- **Craig Larman**, *Applying UML and Patterns: Intro. OOAD & Iterative Development*, Prentice-Hall, 2004, 3. baskı (nesneye yönelik çözümleme, tasarım, modelleme ve kodlama örnekleri için ana kaynak).
- **Ian Sommerville**, *Software Engineering*, Pearson, 2015, 10. baskı (kuramsal bölümler için tamamlayıcı kaynak).
- **Martin Fowler**, *UML Distilled*, Addison-Wesley, 2003, 3. baskı (UML şemalarının kurallarını ve iyi tasarım ilkelerini öz biçimde anlatan yardımcı kaynak).

Özellikle teknik belgelendirme ve modelleme aşamalarında **UML (*Unified Modeling Language*)** ailesindeki şema türleri yoğun olarak kullanılır. Nesneye yönelik programlama dersinde görülen sınıf şemaları (*class diagrams*) ve sıralama şemaları (*sequence diagrams*) bu derste hızlıca hatırlatıldıktan sonra, kullanım senaryosu (*use case*) şemaları ve diğer UML diyagramları ayrıntılı biçimde işlenecektir. Hoca, pek çok UML kitabının yalnızca şema çizim kurallarını verip "nasıl doğru nesneye yönelik tasarım yapılacağını" veya "bir *use case* metninin nasıl yazılması gerektiğini" kapsam dışı (*out of scope*) bıraktığını, buna karşılık Martin Fowler'ın *UML Distilled* kitabının hem şema kurallarını hem de doğru tasarım ilkelerini özlü biçimde bir arada sunduğunu vurgulamıştır.

Dersin konu akışı, **yazılım geliştirme yaşam döngüsü (*software development life cycle*)** adımlarına paralel olarak yapılandırılmıştır (ekrandan, 00:20:00):

1. **Yazılım Mühendisliğine Giriş** (Pressman)
2. **Yazılım Geliştirmede Süreç Modelleri** — klasik şelale modeli, çevik süreçler ve diğer süreç modelleri (Pressman)
3. **Gereksinim Mühendisliği** (Pressman)
4. **Nesneye Yönelik Çözümleme (Analiz)** (Larman)
5. **Nesneye Yönelik Tasarım** (Larman)
6. **Yazılım Ölçütleri** (Pressman)
7. **Yazılım Sınama Teknikleri** (Pressman)
8. **Yazılım Proje Yönetimine Giriş** — tüm yaşam döngüsünü kapsayan şemsiye etkinlik (Pressman)

## 2. Yazılımın Tanımı, Belgelendirmenin Önemi ve Yaşam Döngüsü

Dersin ve yazılım mühendisliği disiplininin odağında **yazılım** yer alır. Slaytta yazılımın tanımı şu şekilde verilmiştir (ekrandan, 00:30:00):

- **Yazılım:** Herhangi bir boyuttaki, herhangi bir tür donanımda çalışan bilgisayar programını **VE** basılı veya elektronik ortamdaki her tür dokümanı içeren üründür (ekrandan, 00:30:00).

> **Hocanın vurgusu:** Yazılım tek başına program kodu değildir. Tanımdaki **"VE"** bağlacı özellikle büyük harflerle yazılmıştır; çünkü basılı ya da elektronik ortamdaki **dokümantasyon (belgelendirme)** yazılımın ayrılmaz bir bileşenidir.

Yazılım belgelendirmesi iki farklı hedef kitleye yönelik olabilir (ekrandan, 00:30:00):

1. **Son kullanıcıya yönelik dokümanlar:** Kullanım kılavuzları, yardım ekranları ve eğitim belgeleri.
2. **Yazılım geliştirme ve bakım ekibine (teknik ekibe) yönelik dokümanlar:** Gereksinim belirtimleri, mimari ve nesneye yönelik tasarım şemaları, teknik belgeler. Yazılım yaşam döngüsü boyunca teknik ekibin yürüttüğü çalışmalar çok ciddi bir maliyet oluşturur; teknik belgelendirme bu maliyetlerin kontrolden çıkmasını önlemek ve gelecekteki değişikliklerin/bakımın kolayca yapılabilmesini sağlamak için vazgeçilmezdir.

Yazılım nihayetinde bir **üründür**; ancak yalnızca son kullanıcının doğrudan kullandığı bir nihai ürün olmak zorunda değildir. Derleyiciler, tümleşik geliştirme ortamları (IDE'ler) veya yazılım kütüphaneleri gibi **başka ürünler geliştirmeye veya elde etmeye yarayan bir araç** da olabilir (ekrandan, 00:30:00).

Bu noktada ders boyunca sıkça kullanılacak olan **yazılım yaşam döngüsü (*software life cycle*)** kavramının net tanımı şöyledir (ekrandan, 00:30:00):

- **Yaşam döngüsü (*software life cycle*):** Yazılımın bir fikir olarak doğmasından, kullanım dışı bırakılmasına (emekliye ayrılmasına) kadar geçen süreçtir.

Yazılım mühendisliğinin temel amacı, bu yaşam döngüsü kapsamındaki tüm etkinlikleri en verimli ve hatasız biçimde yürütmektir.

## 3. Yazılım Neden Eskir? Aşınma ve Yetersizleşme Farkı

Yazılım, bir kalem ya da bilgisayar faresi gibi fiziksel bir ürün değildir. Fiziksel ürünler zamanla mekanik etkilere maruz kalır: bilgisayar faresi bozulur, kalem kırılır, bir parçası kaybolur veya yay mekanizması işlevini yitirir; kısacası fiziksel ürünler zamanla **aşınır (*wear out*)**.

Yazılım fiziksel bir ürün olmadığı için mekanik olarak aşınmaz; fakat buna rağmen bir yazılımı sonsuza kadar kullanamayız, çünkü yazılım zamanla **yetersizleşir (*deteriorate*)** (ekrandan, 00:30:00). Yazılımın zamanla yetersizleşmesinin arkasında birbirini tetikleyen şu dinamikler yatar:

1. **Değişim kaçınılmazdır:** Yazılım, yaşam döngüsü süresince sürekli değişikliklere uğrar (ekrandan, 00:30:00). Bunun ilk nedeni başlangıçta bazı gereksinimlerin net anlaşılamamış olması veya kodlama gibi karmaşık bir etkinlik sırasında yapılan doğal hataların düzeltilmesi ihtiyacıdır. Daha sık karşılaşılan ikinci neden ise yazılımın çözdüğü gerçek dünya problem alanındaki değişimlerdir; iş kuralları veya ortam değiştikçe yazılımın gereksinimleri de mecburen değişir.
2. **Değişiklikler yazılımda yeni hatalar oluşturabilir:** Değişen gereksinimleri karşılamak veya mevcut hataları gidermek için yazılımın kodu ve dokümantasyonu üzerinde değişiklik yapılırken, farkında olmadan başka modülleri etkileyen yeni hatalar (*side effects*) üretilebilir (ekrandan, 00:30:00).
3. **Yeni hatalar tam olarak düzeltilmeden yeni değişiklikler gerekebilir:** İlk değişiklikten kaynaklanan hatalar henüz tam fark edilip giderilmeden yeni değişiklik talepleri gelir. Değişiklikler baştan topluca bilinseydi hepsi birden çok daha temiz ve bütünsel bir tasarımla çözülebilirdi; ancak talepler *peydarpey* (parça parça) geldiği için her seferinde ideal tasarımın biraz daha altında çözümler üretilir. Biriken bu yapısal bozulmalar sonunda yazılım yetersizleşir ve emekliye ayrılır (ekrandan, 00:30:00).

Bu süreci en az zararla yönetmek için önerilen temel çözüm, **yazılım mühendisliği ilkelerine uyularak daha iyi tasarlanmış ve yaşam döngüsü doğru yürütülmüş yazılım** üretmektir (ekrandan, 00:30:00).

## 4. Yazılım Türleri ve Mühendislik Gereksinimleri

Farklı yazılım türleri farklı içsel nitelikler (*attributes*) taşır. Yazılım geliştirme süreçlerinin, sınama (test) yaklaşımlarının ve kalite ölçütlerinin geliştirilen yazılımın doğasına göre uyarlanması gerekir. Tek bir sınıflandırma biçimi olmamakla birlikte, yazılımlar ana hatlarıyla beş temel grupta incelenir (ekrandan, 00:40:00; ekrandan, 00:46:20).

### 4.1 Sistem Yazılımı (System Software)

**Sistem yazılımları**, diğer programlara ve yazılımlara hizmet sunmak üzere hazırlanmış programlardır; en tipik örnekleri **derleyiciler (*compilers*)** ve **işletim sistemleridir (*operating systems*)** (ekrandan, 00:40:00).

- **Zorlukları:** Genellikle çok karmaşıktırlar ve yüksek başarımla (*high performance*) çalışmaları gerekir. Örneğin bir işletim sistemi eldeki donanım kaynaklarını en verimli biçimde yönetmek zorundadır. Bir derleyici ise kaynak kodu bileşenlerine ayırdıktan sonra ayrıştırma ağacına (*parse tree*) dağıtmak ve her bir durumu işlemek için karmaşık veri yapıları ve zor algoritmalar kullanır.
- **Avantajı:** Yazılım mühendisliğinde ekipleri en çok zorlayan konu gereksinimlerdeki hızlı değişimdir; sistem yazılımlarının en büyük avantajı ise **gereksinimlerinin çok değişken olmamasıdır**. Belirli bir programlama dili için derleyici yazılırken o dilin kuralları sürekli kökten değişmez; benzer şekilde altı ayda bir tamamen yeni bir işletim sistemi kuramı ortaya çıkmaz.

### 4.2 Mühendislik Yazılımı / Bilimsel Yazılım (Engineering / Scientific Software)

**Mühendislik yazılımları ve bilimsel yazılımlar**, mühendislik ve bilimsel hesaplamalarda kullanılmak üzere geliştirilen programlardır (ekrandan, 00:40:00). Hoca bu tür yazılımlara şu örnekleri vermiştir:

- Makine parçalarının üç boyutlu çizimlerini (CAD) yapan, bunlardan iki boyutlu perspektifleri otomatik çıkaran ve hareketli parçaların zaman içindeki mekanik sürtünmelerinden doğacak aşınma/ısınma oranlarını simüle ederek en çok aşınan bölgeleri kırmızıdan yeşile renk skalasıyla görselleştiren yazılımlar.
- Mimari tasarımların statik ve dinamik yapısal hesaplamalarını yapan yazılımlar.
- İklim modelleri veya uzay aracı yörünge hesaplamaları yapan bilimsel simülasyonlar.

Bu yazılımların ortak özelliği **büyük hacimli verilerle uğraşmaları** ve yoğun matematiksel işlemler yaparak sonuç üretmeleridir; bu işlem literatürde **"numara öğütmek / *number crunching*"** deyimiyle adlandırılır (ekrandan, 00:40:00). Örneğin etkileşimli bir üç boyutlu çizim programında kullanıcı fareyi oynattığında nesnenin 10 saniye gecikmeyle değil anında dönmesini bekler; bu da yüksek veri hacmini çok verimli işlemeyi gerektirir. Ayrıca iklim simülasyonları veya Ay'a/Mars'a gönderilecek bir roketin yörünge hesaplamaları gibi bilimsel yazılımlarda hesaplamanın birkaç saat sürmesi sorun değildir; asıl kritik olan ondalık sayılarda virgülden sonra 8., 9., 10. basamağa kadar **çok yüksek matematiksel hassasiyetle** hesaplama yapılmasıdır. Çünkü en ufak bir yuvarlama veya hassasiyet hatası çok pahalı bir uzay aracının yörüngeden çıkıp kaybolmasına yol açabilir.

### 4.3 Gömülü Yazılım (Embedded Software)

**Gömülü yazılımlar**, bir donanımı gütmek, denetlemek veya kontrol etmek amacıyla hazırlanan ve ilgili donanım ile çok sıkı ilişkide olan yazılımlardır (ekrandan, 00:40:00). Bir enerji santralinin yönetim yazılımı, bir çamaşır makinesinin parçalarını denetleyen program veya ısı güdümlü bir füzenin kontrol yazılımı bu gruba girer. Donanımla bağları o kadar sıkıdır ki, bir çamaşır makinesi için yazılan gömülü yazılım aynı markanın biraz farklı bir üst modeline bile doğrudan aktarılamaz; mutlaka donanıma göre değişiklik yapılması gerekir.

> **Hocanın vurgusu:** Mühendislik/bilimsel yazılımlar ile gömülü yazılımlar arasında temel bir zıtlık vardır. Mühendislik ve bilimsel yazılımlarda yüksek hesaplama hassasiyeti öncelikliyken, çoğunlukla **gerçek zamanlı (*real-time*)** olan gömülü yazılımlarda yüksek hassasiyetten ziyade **hızlı tepki süresi (anlık yanıt verme)** hayati önem taşır.

Hoca bu zıtlığı **ısı güdümlü havadan havaya füze** örneğiyle açıklamıştır: Füzenin fırlatıldığı hedef uçağın pilotu kurtulmak için sürekli sert kaçınma manevraları yapacak ve füzeyi yanıltmak amacıyla *flare* adı verilen çok sıcak, ışık saçan parçalar bırakacaktır. Füzenin kontrol yazılımı için önemli olan, uçağın anlık manevrasını virgülden sonra onuncu basamağa kadar kusursuz hesaplamak değildir; yanıltıcı *flare* parçalarını hızla ayırt edip uçağın ne tarafa yöneldiğini milisaniyeler içinde yaklaşık olarak algılamak ve füzenin burnunu o yöne çevirmektir. Füzenin kendini bir derece fazla ya da eksik yöneltmesi veya uçağı tam gövdesinden değil yakınında patlayarak imha etmesi yeterlidir; yeter ki hesaplama çok hızlı yapılsın.

### 4.4 Uygulama Yazılımı (Application Software) ve Yazılım Standartları

**Uygulama yazılımları**, farklı müşteriler tarafından kullanılabilecek genel amaçlı yazılımlardır; cari hesap uygulamaları, kütüphane/hastane/pastane otomasyon programları, kelime işlem ve hesap tablosu gibi ofis yazılımları bu gruba girer (ekrandan, 00:46:20). Literatürde ve sektörde şu adlarla da anılırlar (ekrandan, 00:46:20):

- ***Product-line software* (Ürün hattı yazılımı):** Temel işlemlere yönelik hazır modüllerin, tıpkı bir fabrikadaki montaj hattında olduğu gibi bir araya getirilip tümleştirilmesiyle üretilen yazılımlar.
- ***Shrink-wrapped software*:** İnternet üzerinden dağıtım yaygınlaşmadan önce yazılımların renkli karton kutular içinde (disket, CD veya DVD olarak) ve dışı jelatinle kaplı (*shrink-wrapped*) biçimde satılmasından gelen adlandırma.
- ***(Commercial) off-the-shelf* (COTS):** Teknoloji marketlerinin raflarından hazır olarak satın alınabilen ticari paket yazılımlar.

Günümüzde bu yazılımlar çoğunlukla bulut veya internet üzerinden hizmet olarak sunulsa da "farklı müşterilere hitap eden genel amaçlı uygulama olma" doğaları değişmemiştir. Hoca bu noktada yazılım mühendisliği alanında tanımlanmış uluslararası standartlara dikkat çekerek COTS yazılımlar için geliştirilen şu standardı örnek göstermiştir (ekrandan, 00:46:20):

- **`TS/BS ISO/IEC 25051` — COTS Yazılım Ürünleri Standardı**

Bu standart kodundaki kısaltmaların anlamları şunlardır:
- **`ISO` (*International Organization for Standardization*) ve `IEC`:** Standardı kabul eden uluslararası standart organizasyonları.
- **`BS` (*British Standards*):** Standardın İngiliz Standartları Enstitüsü (*British Standards Institution*) tarafından da kabul edildiğini gösterir.
- **`TS` (*Türk Standardı*):** Standardın Türk Standartları Enstitüsü (TSE) tarafından kabul edildiğini ve **Türkçeye çevrilmiş olduğunu** gösterir.
- **`25051`:** Ticari hazır yazılım ürünleri (*Commercial Off-The-Shelf*) kalite gereksinimleri ve test kurallarını tanımlayan standart numarası.

> **Ek bilgi (derste anlatılmadı):** Hoca konuşmasında `IEC` kısaltmasının tam açılımını o an hatırlayamadığını belirtmiştir. Büyük olasılıkla **Uluslararası Elektroteknik Komisyonu (*International Electrotechnical Commission*)** anlamına gelen `IEC`, bilişim teknolojileri standartlarını `ISO` ile ortak oluşturduğu `ISO/IEC JTC 1` komitesi üzerinden yayımlamaktadır. `ISO/IEC 25051` standardı da büyük olasılıkla yazılım ürün kalitesi ailesi olan SQuaRE (*Systems and software Quality Requirements and Evaluation*) serisi içinde yer almaktadır.

Bu standartlara uymak her zaman yasal bir zorunluluk olmasa da, içerdikleri en iyi uygulamaları (*best practices*) yazılım yaşam döngüsüne dahil etmek yazılım kalitesini doğrudan artırır. Standart metinlerine erişim genellikle ücretli aboneliklerle sağlanır; Türkiye'deki üniversitelerin 2000'li yıllarda kurduğu **ANKOS (Anadolu Üniversiteleri Konsorsiyumu)** sayesinde üniversite kütüphaneleri (kampüs ağından veya kütüphanenin VETİS uzaktan erişim sistemi üzerinden) geniş bir uluslararası standart ve elektronik yayın havuzuna erişim sunmaktadır.

### 4.5 Kurumsal Yazılım (Enterprise Software)

**Kurumsal yazılımlar (*enterprise software*)**, belirli ticari iş gereksinimlerine yönelik programlardır (ekrandan, 00:46:20). Büyük bir işletmede genel amaçlı uygulama yazılımları da kullanılabilir; ancak kurumsal yazılımları uygulama yazılımlarından ayıran temel fark, doğrudan kurumun iş süreçlerini yönetmek, izlemek, planlamak ve raporlamak üzere geliştirilmeleridir.

- **Özellikleri ve Örnekleri:** İş süreçleri ile ilgili derin bilgiye sahip olmalıdırlar ve genellikle müşteriye özel tasarlanırlar (veya genel bir kurumsal paketin müşteriye özel uyarlanmasıyla kurulurlar) (ekrandan, 00:46:20). En bilinen örnekleri **Kurumsal Kaynak Planlama (*Enterprise Resource Planning* - ERP)** yazılımları, bankaların kredi tanımlama/takip ve menkul kıymet alım-satım sistemleri ile sigorta şirketlerinin poliçe satış ve hasar tazmin süreçlerini yürüten yazılımlardır.
- **Gerçek Zamanlı İzleme ve Planlama Gereksinimi:** Kurumsal yazılımlar çoğunlukla veri dönüştürme ve değerlendirme/raporlama uygulamalarıdır; ancak kimi zaman iş süreçlerinin **gerçek zamanlı izlenmesini** de gerektirirler (ekrandan, 00:46:20). Örneğin bir üretim tesisinde kullanılan ERP yazılımında; stoktaki hammadde miktarı, yeni gelen malzemeler, hangi ürün parçasının hangi sırayla monte edileceği, montaj istasyonlarının durumu ve farklı yeteneklerdeki işçilerin hangi istasyonları kullanabileceği gibi kaynak ve kısıtların anlık (veya birkaç saatlik yakın zamanlı) olarak takip edilmesi gerekir. Günlük üretim planının bu kısıtlar altında eniyilenmesi (*optimizasyon*) algoritmik açıdan zor problemler barındırır.
- **Sonuç:** Kurumsal yazılımlar iş süreçlerinin çok kritik bir bileşeni oldukları ve kurumlara yüksek maliyetlerle mal oldukları için uzun yıllar kullanılırlar ve **zamanla "eski yazılım" (*legacy software*) hâline dönüşürler** (ekrandan, 00:46:20).

## 5. Eski Yazılım (Legacy Software): Sorunlar ve Yenilenme Zorunluluğu

**Eski yazılım (*legacy software*)**, bir kurumun iş sürecinin önemli bir parçası olan ve çok uzun süredir (örneğin 10–30 yıldır) kullanımda olan yazılımlardır (ekrandan, 01:10:00). Bir yazılımın yıllarca kullanılmasının nedeni, kurumun çok temel (çekirdek) bir iş gereksinimini karşılaması ve firma yönetiminin geçmişte yüksek bedeller ödeyerek kendisine özel yaptırdığı bu yazılımdan maksimum faydayı sağlamak için onu mümkün olduğunca uzun süre kullanımda tutmak istemesidir. Hatta yeni gereksinimler ortaya çıktığında bile eski yazılıma dokunulmadan, toplu dosya aktarımı veya araya konan "köprü" ara yazılımlarla yarı tümleşik bir otomasyon kurulmaya çalışılır. Hoca buna günlük hayattan bir örnek olarak bazı kurumlarda fatura veya ilk iş emirlerinin hâlâ eski sistemlere bağlı nokta vuruşlu yazıcılardan (*dot-matrix printer*) basılmasını göstermiştir.

Ancak uzun yıllar kullanılan eski yazılımlarda zamanla şu **beş temel olumsuzluk** ortaya çıkar (ekrandan, 01:10:00):

1. **Eksik veya hatalı dokümantasyon:** Kurumun bilgi işlem ekibi yıllar içinde yazılımda ufak tefek düzenlemeler yapar; ancak iş yoğunluğu nedeniyle bu değişiklikler ne son kullanıcı yardım ekranlarına ne de teknik belgelere işlenir. Sonuçta yeni başlayan kullanıcılara *"yardım ekranında yazana bakmayın, işi şöyle yapacaksınız"* diye ayrı eğitim vermek gerekir; teknik ekip ise yeni bir tümleştirme veya değişiklik gerektiğinde belgelerle kod uyuşmadığı için kaynak kodu baştan sona okuyup analiz etmek zorunda kalır.
2. **Zamanla karmaşıklaşmış kod:** Onlarca yıl boyunca gelen değişiklik ve hata düzeltme talepleri, çoğu zaman günü kurtarmaya yönelik hızlı ve özensiz yamalarla (***quick and dirty fix***) kodlanır. Özensiz yapılmasa bile, değişiklikler parça parça geldiği için yalnızca o anki sorunu çözen **yerel optimum (*local optimum*)** kararları alınır; bu yerel çözümler birike birike yazılımı **genel optimumdan (*global optimum*)** çok aşağı bir noktaya taşır ve gelecekteki her değişikliğin maliyetini katlar.
3. **Esnek olmayan yapı:** Örneğin tek işlemcili bir masaüstü ortamı için tasarlanmış eski bir yazılım, aynı anda birden fazla istemcinin (*client*) bağlanmasını veya birden fazla sisteme eşzamanlı veri aktarılmasını mimari olarak destekleyemez.
4. **Eski donanımla (veya eski alt yazılımlarla) çok sıkı ilişki:** Yazılım yalnızca eski bir *mainframe* bilgisayar üzerinde çalışacak şekilde yazılmış olabilir ve güncel sunuculara taşınamaz (hatta yıllar içinde fidye yazılımları, siber saldırılar veya yedekleme/felaketten kurtarma [*disaster recovery*] eksiklikleri yüzünden kaynak kodu tamamen kaybolmuş bile olabilir).
   - *Donanım bağımlılığı örneği:* Bir finans kurumunun BDDK raporlaması için zorunlu olan fon alım-satım kayıtlarını IBM `AS/400` gibi eski bir *mainframe* üzerinde tuttuğunu düşünelim. Bu makinenin yedekli disk birimlerinden biri bozulduğunda acilen yenisinin takılması gerekir; ancak parça artık üretilmemektedir. Hoca, İrlanda'da olduğu gibi bazı yurt dışı firmaların kurumların çöpe veya geri dönüşüme atacağı eski/bozuk donanımları satın alıp onararak (*refurbished*) bu tür parçaları yana yakıla arayan finans kurumlarına çok yüksek kârlarla sattığını örnek vermiştir.
   - *Yazılım bağımlılığı örneği:* Eski yazılımın veritabanı katmanında Microsoft'un yıllar önce çıkardığı `FoxPro` gibi bir ürün kullanılmış olabilir. Microsoft `FoxPro` desteğini yıllar önce kestiği için, veritabanı sunucusundaki bir hata (*bug*) yüzünden yeni bir gereksinim kodlanamadığında kurumun elinde `FoxPro`'nun kaynak kodu da olmadığından sorun çözülemez ve sistem tıkanır.
5. **Yazılım mühendisliğindeki gelişmelerden yoksunluk nedeniyle düşük kalite:** Yazılım ilk tasarlandığında çok iyi yazılmış olsa bile, 20-30 yıl önce çevik süreçler veya kod kalite metrikleri bilinmediği için güncel yazılım mühendisliği kazanımlarından yoksundur (ekrandan, 01:10:00).

Bu olumsuzlukların birikmesiyle ek maliyetler katlanılmaz hâle geldiğinde eski yazılımın yenilenmesi gerekir. Slaytta **eski yazılımın değiştirilmesini gerektiren üç ana neden** şöyle özetlenmiştir (ekrandan, 01:10:00):

- **İş alanındaki yeni gereksinimler.**
- **Güncel sistemlerle birlikte çalışabilmesi için uyumluluk kazandırılması:** Örneğin 25-30 yıl önce yazılmış temel bankacılık modüllerini barındıran bir `AS/400` sisteminin, günümüzdeki internet şubelerine ve cep telefonlarındaki mobil bankacılık istemcilerine yanıt verebilmesi gerekir; eski sistemde buna uygun kütüphane veya modül bulunmadığından işlevlerin güncel ortama taşınması zorunlu olur.
- **Donanımın ömrünün dolması nedeniyle daha güncel ortama taşınma gerekliliği.**

Eski yazılım bir yandan kesintisiz çalışmaya devam etmek zorunda olduğundan, yeni sistemin hazırlanması, eski özelliklerin hangi sırayla ve nasıl daha iyi bir tasarımla yeni sisteme aktarılacağı ve geçişin nasıl planlanacağı yazılım mühendisliğinde başlı başına geniş bir araştırma ve uygulama alanıdır.

## 6. Yazılımı ve Yazılım Mühendisliğini Etkileyen Eğilimler

Yazılımı ve dolayısıyla yazılım geliştirme yaşam döngüsünü etkileyen başlıca eğilimler slaytta altı başlık altında toplanmıştır (ekrandan, 01:30:00):

### 6.1 Yaygınlaşan Bilgi-İşlem

Hesaplama gücünün giderek küçülen alanlara sıkıştırılabilmesi, bilişimin günlük yaşantımızla ve iş süreçleriyle daha kolay bütünleşmesine olanak sağlamaktadır (ekrandan, 01:30:00). Intel çalışanı Gordon Moore'un ortaya koyduğu **Moore Yasası** uyarınca belirli periyotlarla işlem gücü katlanmakta veya aynı işlem gücü yarı alana sığdırılabilmektedir. Mikroişlemci üretim ölçeklerinin küçültülmesi, yarı iletken malzemelerin geliştirilmesi, iki boyutlu dizilimlerden üç boyutlu dizilimlere geçilmesi ve paralelinde yürütülen kuantum hesaplama araştırmaları bu ivmeyi sürdürmektedir. Bunun sonucunda 20-30 yıl öncesinin bilgisayarlarından çok daha güçlü işlemci ve belleğe sahip cep telefonları, akıllı gözlükler ve sanal gerçeklik (*VR*) kaskları hayatımıza girmiştir.

### 6.2 Yaygınlaşan Haberleşme Ağı ve Sinerji

Kablosuz ağların (5G çalışmaları vb.) yaygınlaşması, kapsama alanlarının ve bant genişliklerinin sürekli artması da bilişimin günlük yaşamla bütünleşmesini hızlandırmaktadır (ekrandan, 01:30:00). Yaygınlaşan bilgi-işlem ile yaygınlaşan haberleşme ağı bir araya geldiğinde **sinerji** oluşturur: iki bileşenin birlikte ortaya çıkardığı etki, tek tek oluşturdukları etkilerin toplamından çok daha büyüktür ve kullanıcıya fiziksel olarak her an eşlik eden yazılım çözümlerine olan talebi artırır.

### 6.3 Özgür / Açık Kaynak Yazılım

Slaytta üçüncü temel eğilim olarak **Özgür / Açık Kaynak Yazılım** yer alır: gevşek bir ekip tarafından geliştirilen yazılımın daha anlaşılır ve geliştirilebilir olması gerekir (ekrandan, 01:30:00). Hoca burada sıkça karıştırılan iki kavramın farkını özellikle vurgulamıştır:

- **Özgür yazılım (*free software*):** Kaynak kodu herkes tarafından görülebilen, istenildiği şekilde uyarlanıp değiştirilebilen ve hiçbir kısıtlama olmaksızın istenildiği şekilde dağıtılabilen yazılımdır.
- **Açık kaynak yazılım (*open source software*):** Kuruma özel kapalı kaynak (*proprietary*) yazılımlara kıyasla kaynak kodu açıktır, incelenebilir ve değiştirilebilir; ancak **açık kaynak yazılım her zaman özgür yazılım değildir**. Ortaya çıkan yeni ve değiştirilmiş kodun nasıl kullanılacağı ve dağıtılacağı çeşitli **açık kaynak lisanslarına** tabidir. Örneğin bazı lisanslar yapılan değişikliklerin de aynı lisansla ve açık kaynak olarak dağıtılmasını şart koşarken, bazıları kâr amaçlı dağıtımı veya ticari kurumlarda kullanımı kısıtlayabilir.

Açık kaynak yazılımlar yazılım mühendisliğinde yeni iş ve geliştirme modelleri doğurmuştur:
1. **Çekirdek sürüm + ücretli genişletilmiş sürüm modeli:** Bir yazılım evi ürününün temel çekirdek işlevlerini açık kaynak ve ücretsiz olarak sunar; ürünü kullanıp memnun kalan kişi ve kurumlar, daha geniş işlevselliğe sahip ücretli sürümlere veya ek hizmetlere müşteri olur (eski *demo* yazılımların gelişmiş bir üst kümesi gibi).
2. **Bileşen tabanlı yazılım geliştirme ve yeniden kullanım (*software reuse*):** Lisansı izin veren açık kaynak bileşenler bir araya getirilip belirli bir tümleştirme ve uyarlama çabasıyla çok daha düşük maliyetle yeni yazılımlar üretilebilir.
3. **Gevşek bağlı (*loosely coupled*) ve heterojen ekiplerin yönetimi:** Örneğin açık kaynaklı *Firefox* web tarayıcısını geliştiren *Mozilla Foundation* kod havuzuna Küba'dan, Kanada'dan, Hindistan'dan, Çin'den, Japonya'dan veya Kore'den farklı eğitim düzeylerinde, farklı deneyimlerde ve farklı zaman dilimlerinde yaşayan gönüllü yazılımcılar katılabilir. Bir geliştirici açık bir hatayı (*issue*) üstlenir, düzeltir ve başka bir katılımcının bağımsız testlerinden geçtikten sonra kod havuzuna dahil eder. Bu kadar gevşek bağlı ve dağıtık bir ekibin ortak bir amaç doğrultusunda çalışabilmesi; kodun son derece anlaşılır olmasını, sıkı kaynak kod yönetimini ve proje yönetimi süreçlerinde özel ayarlamalar yapılmasını zorunlu kılar.

### 6.4 Takım Çalışması Zorunluluğu, Küreselleşme ve Ekonomik Krizler

Slaytta "Ayrıca" başlığı altında üç önemli eğilim daha vurgulanmıştır (ekrandan, 01:30:00):

- **Takım çalışması zorunluluğu:** Yazılım geliştirmenin ilk dönemlerinde yetenekli tek bir kişinin oturup 3–6 ay içinde teknik dokümantasyonuyla birlikte değerli bir yazılımı tek başına üretmesi mümkündü; ancak o günler tamamen geride kalmıştır. Örneğin Linus Torvalds, bilgisayar mühendisliği öğrencisiyken bir ders projesi kapsamında Linux işletim sistemi çekirdeğini (*kernel*) tek başına başlatmıştır; fakat proje büyüdükten sonra tek başına yönetilmesi imkânsız hâle gelmiş ve geniş bir topluluk tarafından yürütülmeye başlanmıştır. Günümüzde bir yazılım ekibinde yalnızca bilgisayar mühendisleri yer almaz; problem alanına hâkim **konu uzmanı / çözümleyici (*analyst*)**, **bağımsız test ekibi uzmanları**, gömülü/mühendislik sistemlerinde **donanım ekibi temsilcileri**, teknik veya idari kökenli **proje yöneticisi**, optimizasyon gereken projelerde **matematikçiler** ve makine öğrenmesi projelerinde **veri bilimciler** birlikte çalışır. Dolayısıyla *"bilgisayar mühendisi içine kapanıktır, sosyal yeteneği yoktur"* önyargısı geçerliliğini yitirmiştir; iletişim ve takım çalışması becerileri mesleki bir zorunluluktur.
- **Küreselleşme:** Siyasi anlamıyla değil, ekonomik ve ticari anlamıyla yazılım dünyasını doğrudan etkiler. Yazılım evleri ayakta kalmak için yazılım ihracatına yönelmekte ve farklı ülkelerdeki müşterilere, kültürlere ve yasal mevzuatlara uygun ürünler geliştirmektedir. Ayrıca çok uluslu bir telekom şirketinin İstanbul ofisindeki Ar-Ge ekibiyle İspanya ofisindeki ekibinin küresel bir özellik için birlikte çalışması veya bir yazılım evinin rutin kodlama işlerini Hindistan ya da İrlanda'daki bir firmaya dış kaynak (*outsource* / fason) olarak yaptırması küresel ölçek ve koordinasyon sorunlarını beraberinde getirir.
- **Ekonomik krizler:** Ekonomik krizler genel olarak bir tehdittir ancak bazen fırsata dönüştürülebilir. Örneğin internetin yaygınlaşmasıyla kontrolsüz ve enflasyonist biçimde büyüyen elektronik ticaret ve internet şirketlerinin önemli bir kısmının 2000'lerin başında batmasıyla sonuçlanan ***Dot-com* krizi (*Dot-com burst / crisis*)** bilişim sektörünü doğrudan vurmuş, ancak ayakta kalan firmalar güçlenerek devam etmiştir (küresel salgın döneminde ise e-ticaret hacmi yeniden sıçrama yapmıştır). Araştırmalar, gerek sektörel gerekse küresel bir ekonomik krizde kurumların **ilk kısıntıya gittiği ve baltayı ilk vurduğu yerin bilgi işlem ve yazılım departmanları, altyapı alımları ve yazılım projeleri** olduğunu göstermektedir. Bununla birlikte, firmaların mevcut problemlerini daha verimli çözen ve kendini kısa vadede amorti eden çözümler sunan yazılım evleri, kriz dönemlerinde tercih edilerek bu tehdidi fırsata çevirebilir.

## 7. Yazılım Hakkındaki Yanılgılar: Müşteri Açısından

Yazılım geliştirme sürecindeki farklı paydaşların (müşteriler, programcılar ve yöneticiler) doğru sandığı ancak projeleri başarısızlığa sürükleyen yaygın yanılgılar vardır. Müşteri açısından iki temel yanılgı ve gerçekteki karşılıkları şunlardır (ekrandan, 01:44:30):

1. **Yanılgı 1:** *"Programın yazılmasına başlanması için amaçları genel olarak belirlemek yeter, ayrıntılar sonra kararlaştırılabilir. Nasıl olsa yazılım esnektir."* (İngilizcedeki *software* kelimesinin *soft* [yumuşak] kökünden gelmesi de bu algıyı besler.)
   - **Gerçek:** **Belirsiz gereksinimler, çürük atılmış temele benzer** (ekrandan, 01:44:30). Gereksinimlerde bırakılan en ufak bir belirsizlik veya problem alanındaki küçük bir değişim, çürük temelli bir bina gibi o ana kadar harcanan emeğin büyük kısmının çöpe gitmesine yol açar.
2. **Yanılgı 2:** *"Yazılım esnektir. Değişen gereksinimler kolayca sisteme uyarlanabilir."*
   - **Gerçek:** **Yazılım yaşam döngüsünde ilerledikçe, değişen gereksinimleri yazılıma uyarlamanın bedeli doğrusal değil, üstel olarak artar** (ekrandan, 01:44:30).

Hoca bu temel dinamiği slaytta yatay eksende zaman ($t$), düşey eksende maliyet ($\$$) olan bir grafik çizerek açıklamıştır (ekrandan, 01:44:30):

```text
Maliyet ($)
  ^
  |                                      /
$2| - - - - - - - - - - - - - - - - - - /
  |                                   /
  |                                 /
$1| - - - - - - - - - /           /
  |                 / |         |
  |               /   |         |
  +-------------------+---------+------------> Zaman (t)
  0                   t1        t2
```

Zaman ekseninde başlangıç anı ile $t_1$ arasındaki süre ve $t_1$ ile $t_2$ arasındaki süre birbirine yakın olsa bile, eğrinin üstel yapısı nedeniyle $t_1$ ile $t_2$ arasındaki küçük bir zaman farkı maliyet ekseninde $\$_1$ ile $\$_2$ arasında çok büyük bir maliyet sıçraması yaratır (ekrandan, 01:44:30).

> **Hocanın vurgusu (Kil ve Cam Benzetmesi):** Yazılım esnek bir **oyun hamurundan** çok **kil veya cam** gibidir (ekrandan, 01:44:30). Çanak çömlek yapılan ıslak kil veya fırından yeni çıkmış eriyik cam, başlangıçta gayet esnektir ve istenildiği gibi şekillendirilebilir. Ancak kil kuruduktan veya cam bardak soğuyup sertleştikten sonra *"bardağın sapını beğenmedim, daha köşeli veya uzun olsun"* derseniz onu esneterek değiştiremezsiniz; kırmanız, tekrar ısıtıp akışkan hâle getirmeniz ve tüm zorlu üretim sürecini baştan yapmanız gerekir. Yazılım da böyledir; çevik (*agile*) süreçlerle bu esnekliğin artırılması hedeflenmektedir (ekrandan, 01:44:30).

## 8. Yazılım Hakkındaki Yanılgılar: Programcı Açısından ve Proje Başarı Oranları

Yalnızca müşterilerin değil, yazılımı geliştiren teknik personelin (programcıların ve yazılım ekiplerinin) de düştüğü dört önemli yanılgı vardır (ekrandan, 02:02:30):

### 8.1 "Yazılımı Tamamlayıp Müşteriye Teslim Edince İşimiz Biter"

- **Gerçek:** **Yazılım üstünde harcanan çabanın yarısından fazlası, yazılımın müşteriye ilk teslimatından sonra harcanmaktadır** (ekrandan, 02:02:30).

Yazılımın müşteriye ilk kez teslim edilip kullanıma (canlıya / üretim ortamına) alınması akademik literatürde **bakım aşamasına (*maintenance*) geçilmesi** olarak adlandırılır. Yaşam döngüsü bu noktada bitmez, yazılım emekliye ayrılana kadar devam eder. Hoca, zaman-maliyet grafiğini yeniden çizerek yazılımın kullanıma alındığı bakım başlangıç anını ($t_b$) yatay eksenin ortasında göstermiş ve $t_b$ dikmesinin sağında (bakım döneminde) eğrinin altında kalan alanın, solunda (geliştirme döneminde) kalan alana eşit veya ondan çok daha büyük olduğunu vurgulamıştır (ekrandan, 02:02:30):

```text
Maliyet ($)
  ^
  |                                   / |
  |                             /       |
  |                       /             |
  |                 /   |               |
  |            /        |   Bakım       |
  |        /   Geliş.   |   Maliyeti    |
  |     /     Maliyeti  |  (Toplamın    |
  |   /                 |   >%50'si)    |
  +---------------------+---------------+----> Zaman (t)
  0                     tb            Emeklilik
                (İlk Teslimat / Bakım Başlangıcı)
```

Teslimat sonrasında hataların düzeltilmesi, yeni gereksinimlerin gerçeklenmesi, merkezi bulut ortamında sunulmayan yazılımlarda farklı müşteri sürümlerine güncellemelerin dağıtılması ve bir düzeltme yapıldıktan sonra müşteride *"eskiden çalışıyordu, şimdi çalışmıyor"* şeklinde ortaya çıkan yeni hataların canlı iş sürecini aksatmadan hızla giderilmesi toplam çabanın en az yarısını oluşturur. Dolayısıyla yazılım teslim edildiğinde iş bitmez; ancak yolun yarısına gelinmiş olur.

### 8.2 "Yazılımı Tamamlamadan Kalitesini Ölçemem"

- **Gerçek:** **Kalite güvence yöntemleri yazılım hayat döngüsünün her aşamasında uygulanabilir; çözümleme (analiz) sürecinde dahi kullanılabilecek kalite ölçütleri bulunmaktadır** (ekrandan, 02:02:30).

Bitmiş bir ürün üzerinde daha net kalite ölçümleri yapılabileceği doğru olsa da, değişiklik maliyeti zamanla üstel arttığı için kalite ölçümü ve yönetimi etkinliklerine daha gereksinim belirleme ve çözümleme aşamalarında başlanmalıdır. Sorunları henüz ortaya çıkmadan veya başlangıç aşamasındayken yakalamak projeyi ileride doğacak ağır maliyetlerden kurtarır.

### 8.3 "Yazılım Eşittir Program"

- **Gerçek:** **Gereksinim analizi başlı başına bir emektir; dokümantasyon ve sınama çalışmalarını da unutmamak gerekir; ayrıca bazı durumlarda entegrasyon (tümleştirme) çalışmaları da gerekmektedir** (ekrandan, 02:02:30).

Kodlama, yazılım geliştirme yaşam döngüsündeki maliyet kalemlerinden yalnızca biridir:
- **Gereksinim analizi:** İş süreçleri karmaşık olan büyük kurumlar, yeni bir yazılım geliştirtmeden önce yalnızca gereksinim analizinin yapılması için uzman bir yazılım eviyle ayrı bir sözleşme imzalayıp bunu bağımsız bir proje fazı olarak yürütebilmektedir; kodlama ihalesine ancak gereksinimler netleştikten sonra çıkılmaktadır.
- **Sınama (*testing*):** İlerleyen haftalarda görüleceği üzere yazılımın sınanması, çoğu zaman **yazılımın kodlanmasından bile daha maliyetli** bir etkinliktir.
- **Entegrasyon (tümleştirme):** Geliştirilen yazılımın kurum içindeki veya dışındaki diğer yazılım ve donanım sistemlerinden veri alması ya da onlara veri beslemesi (birlikte çalışabilirlik) başlı başına ayrı bir çaba ve maliyet kalemidir.

### 8.4 "Yazılım Mühendisliğinin Gereklerini Uygulayarak Boşuna Çaba Harcıyoruz"

*"Yazılım mühendisliği kurallarıyla uğraşana kadar yazılıma iki-üç yeni özellik daha ekleriz"* düşüncesi yaygın bir yanılgıdır. Slaytta bu yanılgıya üç temel yanıt verilmiştir (ekrandan, 02:02:30):
- **Haritası olmayan yolunu kaybeder.**
- **Kalite için harcanan çaba, karşılığını yazılım hayat döngüsünün ilerleyen aşamalarında fazlasıyla ödeyecektir.**
- **Küresel ölçekte yazılım projelerinin %50'si başarısızlığa uğramaktadır.**

#### Yazılım Krizi (Software Crisis) ve Tarihsel Arka Plan

1950'lerin sonu ve 1960'ların başında büyük hesaplamalar yapan donanımların yaygınlaşması ve savunma sanayiinde uçaklara, silahlara hesaplama yetenekleri kazandırılmasıyla birlikte büyük ölçekli yazılımlara ihtiyaç duyulmuştur. Ancak bu yazılımlar kodlanırken yapılan süre ve maliyet tahminleri ağır biçimde şaşmış; 6 ayda biter denilen projeler 2 yılda bitmez hâle gelmiştir. 1950'lerin sonu ile 1960'ların başında yaşanan bu duruma literatürde **Yazılım Krizi (*Software Crisis*)** adı verilmiştir. Başta ABD Savunma Bakanlığı olmak üzere büyük kurumlar bir araya gelerek yazılım geliştirmenin de disiplinli süreç adımlarıyla yürütülmesi gereken bir mühendislik alanı olduğu sonucuna varmış ve **yazılım mühendisliği** disiplini bu pratik zorunluluktan doğmuştur.

#### Küresel ve Ulusal Proje Başarı İstatistikleri

Derste bir öğrencinin *"Küresel ölçekte yazılım projelerinin %50'si başarısızlığa uğramaktadır"* maddesini sorması üzerine hoca, kendi yürüttüğü bir yüksek lisans çalışmasına ait Ulusal Yazılım Mühendisliği Sempozyumu (*UYMS 2015*) sunumundan iki istatistik grafiği açarak bu oranı ayrıntılı biçimde açıklamıştır (ekrandan, 02:18:00; ekrandan, 02:25:30).

Bir yazılım projesinin **başarılı** sayılabilmesi için üç temel hedefin (üç ayağın) üçüne birden aynı anda ulaşılması gerekir (ekrandan, 02:18:00):
1. **Bütçe:** Önceden planlanan bütçenin aşılmaması.
2. **Süre:** Önceden planlanan teslim süresinin aşılmaması.
3. **İşlev:** Planlanan gereksinimlerin ve işlevlerin hiçbirinden kesintiye gidilmeden eksiksiz gerçeklenmesi.

Eğer bu üç ayaktan en az birinde başarısızlık yaşanmışsa (örneğin 500.000 TL bütçeli proje 650.000 TL'ye mal olmuş, ancak 12 aylık sürede ve tüm gereksinimlerle canlıya alınmışsa) buna **zorlanılmış başarı (*challenged*)** denir (ekrandan, 02:18:00). Üç hedefe de ulaşılamamış veya proje iptal edilmişse proje **başarısız** kabul edilir.

1. **Küresel Araştırma (*Dr. Dobb's Journal 2013 IT Project Success Survey*):**
   Uluslararası ölçekte hem pratik hem de bilimsel geçerliliği gözeten *Dr. Dobb's Journal* dergisinin 2013 yılı araştırmasında farklı yazılım süreç modellerine göre başarı oranları şöyledir (ekrandan, 02:18:00):

| Süreç Modeli | Başarılı (Yeşil) | Zorlanılmış (Sarı) | Başarısız (Kırmızı) |
| :--- | :--- | :--- | :--- |
| **Geleneksel (Şelale vb.)** | ~%50 | ~%32 (toplam ~%80–82) | ~%18 |
| **Ad-Hoc ("Kervan yolda düzülür")** | ~%50 | ~%35 (toplam ~%85) | ~%15 |
| **Agile (Çevik)** | ~%64–65 | ~%30 (toplam ~%90–94) | ~%6 |
| **Iterative (Yinelemeli)** | ~%65 | ~%28 (toplam ~%93) | ~%7 |
| **Lean (Yalın)** | ~%70–72 | ~%21 (toplam ~%93) | ~%7 |

   Burada ***Ad-Hoc*** yaklaşım; herhangi bir akademik veya standart süreç modeline dayanmadan, yazılım evinin zaman içinde edindiği alışkanlıklarla (*"biz burada böyle çalışırız"*) yürüttüğü süreçtir (ekrandan, 02:18:00). Görüldüğü üzere geleneksel ve *ad-hoc* süreçlerde tam başarı oranı %50 düzeyindedir; çevik ve yalın süreçlerle bu oran %65–70 bandına çıkarılabilmektedir.

2. **Ulusal Araştırma (*UYMS 2014* — Türkiye'de Çevik Yazılım Geliştirme Üzerine Bir İnceleme):**
   Akademi ile sektörü %50-%50 oranında dengeli biçimde bir araya getiren Ulusal Yazılım Mühendisliği Sempozyumu'nda (E. Çetin, P. O. Durdu, *UYMS 2014*) Türkiye'deki yazılım evlerine ve BT departmanlarına *"Kurumunuzda gerçekleştirilen çevik projelerin başarı oranları nedir?"* sorusu yöneltilmiştir. Pasta grafiğindeki dağılım şöyledir (ekrandan, 02:25:30):
   - **`<%10` başarı oranı:** 2 katılımcı kurum (**%6**)
   - **`%10-%25` başarı oranı:** 4 katılımcı kurum (**%12**)
   - **`%26-%50` başarı oranı:** 5 katılımcı kurum (**%14**)
   - **`%50-%75` başarı oranı:** 13 katılımcı kurum (**%37**)
   - **`%76-%100` başarı oranı:** 11 katılımcı kurum (**%31**)

   Başarı ölçütü olarak projelerin en az %75'inin başarılı olması alındığında oran **%31** (turkuaz dilim); en az %50'sinin başarılı olması kabul edildiğinde ise turkuaz ve mor dilimlerin toplamıyla **%68** (%31 + %37) olmaktadır ki bu da uluslararası *Dr. Dobb's Journal* araştırmasındaki ~%65 çevik başarı oranıyla tutarlıdır (ekrandan, 02:25:30).

**Neden 60 Yıldır Yazılım Krizi Tam Aşılamadı?** 1960'lardan bugüne 60 yıl geçmesine rağmen başarı oranlarının hâlâ %50–68 bandında kalmasının nedeni hedef çıtanın yerinde durmamasıdır. Bilgi işlem gücü ve ağlar yaygınlaştıkça yazılımlarla çözmeye çalıştığımız problemlerin ölçeği, karmaşıklığı ve matematiksel/zihinsel zorluğu da sürekli büyümektedir. Hedef sürekli ileri gittiği için yazılım mühendisliği disiplininden vazgeçmek bir yana, bu yöntemleri çok daha sıkı uygulamak zorunludur.

## 9. Yazılım Hakkındaki Yanılgılar: İdari Açıdan

Yöneticilerin ve proje idarecilerinin yazılım projelerinde sıkça düştüğü üç temel yanılgı şunlardır (ekrandan, 02:30:00):

### 9.1 "İşler Yetişmiyorsa Takıma Yeni Programcılar Ekleriz"

- **Gerçek:** **Yazılım hayat döngüsü içerisinde ilerledikçe, yeni elemanların yazılıma hâkim olması üstel olarak zorlaşır. İşler daha da gecikir** (ekrandan, 02:30:00).

Hoca bu yanılgıyı **"duvar örme problemi" bakış açısı** olarak nitelendirmiştir: 10 metrelik bir duvarı 1 işçi 4 günde örüyorsa, 2 işçi 2 günde, 4 işçi 1 günde örer; ancak yazılım geliştirme duvar örmek gibi doğrusal bölünebilen bir iş değildir.

İster klasik ister yinelemeli (*iteratif*) süreç kullanılsın, projede aylar ilerledikçe ortada ciddi bir çözümleme, tasarım, kod havuzu ve kod dışındaki her türlü teknik belgeyi ifade eden **yapıt (*artifact*)** birikimi oluşur. Örneğin 6 aydır devam eden bir projeye dışarıdan yeni bir programcı dahil edildiğinde, bu kişinin (özellikle teknik dokümantasyon da zayıfsa) 6 aylık kod ve belge birikimini yalnızca okuması yetmez, iyice anlayıp özümsemesi gerekir. Bu süre boyunca yeni eleman **üretici değil, tüketicidir**; üstelik sistemi öğrenirken mevcut ekip üyelerine sorular sorarak onların da zamanını tüketir ve onları yavaşlatır. Dolayısıyla gecikmiş bir projeyi söz verilen tarihe yetiştirmek amacıyla sonradan takıma yeni yazılımcı eklemek projeyi hızlandırmaz, aksine daha da geciktirir.

> **Ek bilgi (derste anlatılmadı):** Gecikmiş bir yazılım projesine yeni insan gücü eklemenin projeyi daha da geciktireceği ilkesi, yazılım mühendisliği literatüründe büyük olasılıkla Fred Brooks'un 1975 tarihli *The Mythical Man-Month* (*Efsanevi Adam-Ay*) kitabında tanımladığı **Brooks Yasası (*Brooks's Law*)** olarak bilinmektedir.

Peki proje yetişmiyorsa veya yeni gereksinimler gelmişse ne yapılmalıdır?
1. Ekip genişletilecekse bu karar projenin çok başında (örneğin 18 aylık bir projenin 2. veya 3. ayında, henüz bilgi birikimi azken) alınmalıdır.
2. Projeye yeni gereksinimler dahil edilecekse bitiş tarihi yeni kapsam üzerinden yeniden hesaplanmalıdır.
3. Mevcut proje başlangıçta anlaşılan süre ve bütçeyle dar kapsamda bitirilmeli, yeni gereksinimler 2. faz / 3. faz veya `v2.0`'dan `v2.2`'ye geçiş gibi ayrı bir proje olarak planlanıp fiyatlandırılmalıdır.
4. Teslim tarihi kesinlikle esnetilemiyorsa bazı gereksinimler kapsamdan elenmelidir.

### 9.2 "Geliştirmesini Üstlendiğim Yazılımı Tamamen veya Kısmen Fason Yaptırırım"

- **Gerçek:** **Proje ilerlemesini kendi içinde denetleyemeyen bir firma, dışarıya verdiği işi izlemekte de zorlanacaktır** (ekrandan, 02:30:00).

Bir yazılım evi ihale aşamasında uzmanlığı olmayan bir modülü ikinci bir ortağa veya alt yükleniciye (*outsource* / fason) yaptırmak isteyebilir. Ortaklık kurmak yanlış değildir; ancak kendi iç yazılım geliştirme süreçlerini düzgün tanımlayıp izleyemeyen bir firma, dışarıdaki yüklenicinin yaptığı işi hiç denetleyemez ve proje ne istenen kalitede ne istenen sürede ne de istenen maliyette tamamlanabilir. Hem firmanın kendi süreçleri sağlam olmalı hem de seçilen alt yüklenici aynı mühendislik disiplinine sahip olmalıdır.

### 9.3 "Açık Kaynak Yazılım Üretirsem Kâr Edemem"

- **Gerçek:** **Danışmanlık hizmetleri ile kâr edilebilir; başka iş modelleri de vardır** (ekrandan, 02:30:00).

Daha önce değinilen "çekirdek işlevleri ücretsiz verip gelişmiş kurumsal özellikleri ücretli sunma" ve "müşteriye özel ek gereksinimleri ücret karşılığı kodlama" modellerinin yanı sıra en önemli gelir kalemi **danışmanlık ve teknik destek hizmetleridir**. Hoca buna örnek olarak **Red Hat Linux** modelini vermiştir: Linux açık kaynaklı ve ücretsiz bir işletim sistemidir; ancak kurumsal sunucularında Linux çalıştıran bir şirketin bilgi işlem departmanı, işletim sisteminin kritik paketlerindeki hızlı güncellemelerin kendi servislerinde yol açtığı sorunları çözmekte yetersiz kalabilir veya olası sorunlardan önceden haberdar olmak isteyebilir. Bu durumda kurum *Red Hat Linux* aboneliği satın alır ve bu temel ücret paketi kapsamında örneğin yılda 3 kez büyük ölçekli sorun çözme ve yapılandırma için ücretsiz uzman teknik destek hakkı elde eder. Aynı model uygulama yazılımları için de geçerlidir.

## 10. Soru-Cevap: Tasarım Kalıpları, Kötü Kod Kokuları ve Yeniden Düzenleme

Dersin son bölümünde öğrencilerden gelen sorular üzerine yazılım mühendisliği projelerinin yapısı ve nesneye yönelik tasarım kalıpları tartışılmıştır.

**Soru:** Proje için verilecek konulara örnek verebilir misiniz? Sistem Analizi dersindeki gibi otomasyon mu olacak?

**Cevap:** Sistem Analizi dersinde yapılan projelere benzer biçimde bilgi sistemleri ve otomasyon sistemleri üzerine konular verilir. Ancak Sistem Analizi dersinde ağırlık yapılabilirlik (*fizibilite*) çalışmaları, maddi fizibilite ve teknik fizibilite üzerindeyken; Yazılım Mühendisliği projesinde ağırlık bu derste öğrenilen gereksinim analizi, kullanım senaryoları (*use case*), nesneye yönelik tasarım, tüm UML şema türlerinin çizimi, kodlama ve sınama etkinliklerinin uçtan uca uygulanmasıdır.

**Soru:** Derste tasarım kalıplarını (*design patterns*) öğrenecek miyiz? Öğreneceksek hangilerini öğreneceğiz?

**Cevap:** Tasarım kalıpları bu lisans dersinin doğrudan kapsamında değildir (tasarım adımlarında farkındalık düzeyinde değinilir, ayrıntılı olarak lisansüstü *Nesneye Yönelik Tasarım ve Modelleme* dersinde *Interpreter* kalıbı hariç tüm kalıplar işlenmektedir). Ancak yazılım mühendisi olarak özellikle tasarım ve kodlama ağırlıklı çalışacak herkesin bu konuları öğrenmesi çok önemlidir:

- **Tasarım Kalıpları (*Design Patterns*):** Nesneye yönelik modellemede sık karşılaşılan genel problemlere etkili, verimli ve esnek çözümler sunar; *"nasıl düzgün ve esnek bir nesneye yönelik tasarım yapılır?"* sorusuna yanıt verir. Bu alandaki en temel kaynak, **Dörtlü Çete (*Gang of Four* - GoF)** olarak bilinen dört yazarın oluşturduğu klasik kitaptır. Ayrıca bir öğrenci bilgi sistemi gibi örnek bir problemi önce kötü bir tasarımla, ardından tasarım kalıbı kullanılmamış iyi bir nesneye yönelik tasarımla, son olarak da tasarım kalıpları uygulanmış esnek bir tasarımla çözüp yeni bir gereksinim değişikliği geldiğinde ilk iki tasarımın nasıl zorlandığını ve kalıplı tasarımın ne kadar kolay uyarlandığını karşılaştırmalı gösteren uygulamalı kitaplar (örneğin bir öğrencinin sohbet ekranından paylaştığı *Dive Into Design Patterns* kitabı) bulunmaktadır.
- **Kötü Kod Kokuları (*Code Smells*), Karşı-Kalıplar (*Anti-Patterns*) ve Yeniden Düzenleme (*Refactoring*):** Tasarım kalıpları işin nasıl doğru yapılacağını gösterirken, hatalardan öğrenmek de madalyonun diğer yüzüdür. Sık yapılan tasarım ve kodlama hatalarını tanımak için ***code smells* (kötü kod kokuları)** ve ***anti-patterns* (karşı-kalıplar)** kavramları, bu kusurları tespit ettikten sonra kodu bozmadan temiz ve esnek yapıya kavuşturmak için ise ***refactoring* (yeniden düzenleme)** yöntemleri kullanılır.

> **Ek bilgi (derste anlatılmadı):** Derste "Dörtlü Çete" (*Gang of Four*) olarak anılan klasik kitap, büyük olasılıkla Erich Gamma, Richard Helm, Ralph Johnson ve John Vlissides tarafından 1994 yılında yayımlanan *Design Patterns: Elements of Reusable Object-Oriented Software* adlı eserdir ve 23 temel tasarım kalıbını (yaratımsal, yapısal ve davranışsal) tanımlar. *Code smells* ve *refactoring* kavramları ise büyük olasılıkla Martin Fowler'ın 1999 tarihli *Refactoring: Improving the Design of Existing Code* kitabıyla standartlaşmıştır.

## Örnek Sorular

### Soru 1 (derste sözlü, 02:14:32)

**Soru:** Programcı yanılgıları slaydında *"Küresel ölçekte yazılım projelerinin %50'si başarısızlığa uğramaktadır"* deniyor. Yazılım krizi (*Software Crisis*) 1960'larda başladığına göre, aradan geçen yaklaşık 60 yılda bu %50 başarısızlık oranı neden hâlâ tam olarak çözülememiştir ve bir yazılım projesinin başarılı sayılmasının ölçütü nedir?

**Çözüm (derste verildi):**
Bir yazılım projesinin **tam başarılı** sayılabilmesi için üç temel hedefin (üç ayağın) tamamına aynı anda ulaşılması gerekir (ekrandan, 02:18:00):
1. **Bütçe:** Planlanan bütçenin aşılmaması.
2. **Süre:** Planlanan bitiş süresinin aşılmaması.
3. **İşlev:** Planlanan gereksinimlerden kesintiye gidilmeden hepsinin eksiksiz gerçeklenmesi.

Bu üç ayaktan en az birinde aksama yaşandığında proje ancak **zorlanılmış başarı (*challenged*)**, üçüne de ulaşılamadığında ise **başarısız** sayılır. *Dr. Dobb's Journal (2013)* araştırmasına göre tam başarı oranı geleneksel ve *ad-hoc* süreçlerde %50 düzeyindeyken çevik (*agile*) süreçlerde ~%65'e, yalın (*lean*) süreçlerde ~%70'e çıkmaktadır; Türkiye'deki *UYMS 2014* araştırmasında da çevik projelerde %50 ve üzeri başarı bildiren kurumların oranı %68'dir (ekrandan, 02:18:00; ekrandan, 02:25:30).

1960'lardan bu yana geçen 60 yılda bu sorunun tamamen ortadan kalkmamasının nedeni hedef çıtanın sabit durmamasıdır: bilgi işlem gücü ve haberleşme ağları yaygınlaştıkça yazılımlarla çözmeye çalıştığımız problemlerin ölçeği, karmaşıklığı ve matematiksel/zihinsel güçlüğü de sürekli büyümektedir. Çözülen problemler sürekli büyüdüğü için yazılım mühendisliği ilkelerini uygulamak her zamankinden daha zorunludur.

### Soru 2 (derste sözlü, 02:44:04)

**Soru:** Nesneye yönelik yazılım geliştirmede tasarım kalıpları (*design patterns*) ile kötü kod kokuları (*code smells*), karşı-kalıplar (*anti-patterns*) ve yeniden düzenleme (*refactoring*) kavramlarının yazılım tasarımındaki rolü ve birbirleriyle ilişkisi nedir?

**Çözüm (derste verildi):**
- **Tasarım kalıpları (*design patterns*):** Nesneye yönelik modelleme ve tasarımda sık karşılaşılan genel problemlere etkili, verimli ve esnek çözümler sunan şablonlardır; tasarımın baştan **nasıl doğru ve esnek yapılacağını** gösterir.
- **Kötü kod kokuları (*code smells*) ve karşı-kalıplar (*anti-patterns*):** Madalyonun diğer yüzü olarak, yazılımda sık yapılan tasarım ve kodlama hatalarını, esnekliği bozan kötü pratikleri tanımayı sağlar.
- **Yeniden düzenleme (*refactoring*):** Kodda veya tasarımda fark edilen *code smell* ve tasarım kusurlarını, yazılımın dış işlevselliğini değiştirmeden iç yapısını iyileştirerek düzeltme yöntemleridir.

## Dersin Toparlaması

Bu ilk derste yazılımın yalnızca kaynak koddan ibaret olmadığı, hem teknik ekibe hem de son kullanıcıya yönelik dokümantasyonu kapsayan bir ürün ve araç olduğu ortaya konmuştur. Yazılımın fiziksel ürünler gibi aşınmasa da yaşam döngüsü (*software life cycle*) boyunca uğradığı değişiklikler ve biriken yan etki hataları yüzünden zamanla yetersizleştiği; sistem, mühendislik/bilimsel, gömülü, uygulama (COTS) ve kurumsal yazılımların birbirinden farklı başarım, hassasiyet, tepki süresi ve standart (`TS/BS ISO/IEC 25051`) gereksinimlerine sahip olduğu incelenmiştir. Ardından kurumsal yazılımların zamanla nasıl eski yazılıma (*legacy software*) dönüştüğü, yaygınlaşan bilgi-işlem ve haberleşme ağlarının, açık kaynak/özgür yazılım modellerinin, disiplinlerarası takım çalışmasının, küreselleşmenin ve ekonomik krizlerin yazılım mühendisliğini nasıl şekillendirdiği ele alınmıştır.

Son bölümde ise tüm dersin en temel dinamiği olan **"yazılım yaşam döngüsünde ilerledikçe değişiklik maliyetinin üstel olarak artması"** kuralı üzerinden müşteri, programcı ve yönetim yanılgıları çürütülmüş; yazılımın oyun hamuru değil kil/cam gibi olduğu, toplam çabanın yarısından fazlasının ilk teslimat sonrası bakım aşamasında harcandığı ve geciken projeye yeni yazılımcı eklemenin projeyi daha da geciktirdiği gösterilmiştir. Bir sonraki derste yazılım geliştirme yaşam döngüsünün genel adımlarına ve yazılım süreç modellerine (şelale modeli, çevik süreçler vb.) geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
