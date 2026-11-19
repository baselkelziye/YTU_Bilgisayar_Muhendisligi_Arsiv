# Ders 6 Genişletilmiş Notu: Laboratuvar 0: Proteus ile Devre Simülasyonu, Ölçüm Araçları ve Breadboard

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvarın Amacı ve Konuları
- 2. Proteus Kurulumu ve Çalışma Ortamı
- 3. Eleman Seçme, Değer Girme ve Bağlantı
- 4. Kaynaklar ve Simülasyonu Başlatma
- 5. Ölçüm Araçları: Voltmetre, Ampermetre ve Problar
- 6. Toprak Bağlantısı
- 7. Dört Dirençli Devre Örneği
- 8. Zamana Bağlı Grafik Çizdirme
- 9. Gerilim İzleyici ve Osiloskop
- 10. Breadboard ve Fritzing
- Örnek Sorular
- Dersin Toparlaması

## 1. Laboratuvarın Amacı ve Konuları

Bu kayıt, Elektronik Devreler dersinin laboratuvar tanıtımıdır; ekrandaki ilk slaytın başlığı "Elektronik Devreler 2021 Bahar – LAB 0"dır (ekrandan, 00:25:00). Laboratuvarların konu sırası dersin teorik akışını izler: diyot, opamp, BJT (bipolar junction transistor) ve CMOS. İlgili konu derste bittikçe onun laboratuvarı yapılır; örneğin diyot konusu bitince diyot laboratuvarı gelir.

Laboratuvarda istenen iş, verilen bir devreyi simülasyon programında kurmak, simüle etmek, sonuçları elle hesaplayarak doğrulamak ve yorumlamaktır. Dönemin sonunda breadboard üzerine fiziksel olarak kurulacak küçük bir devre projesi de vardır; lehim gerektirmez.

## 2. Proteus Kurulumu ve Çalışma Ortamı

Laboratuvarlarda Proteus kullanılır. Ekranda gösterilen sürüm Proteus Design Suite 8.12'dir ve "Demonstration Version" yazar (ekrandan, 00:35:00). Bu öğrenci (değerlendirme) sürümü yalnız akademik ve eğitim amaçlı kullanılır ve projeyi kaydetmeye izin vermez. Bu yüzden laboratuvarda her devre sıfırdan çizilir: soruda bir devre çizilir ya da sözel olarak tarif edilir, öğrenci onu kendisi kurar.

Kurulumda hiçbir ayar değiştirilmez, varsayılan seçenekler kabul edilir. Yeni proje sihirbazında da her adımda varsayılan bırakılıp "Finish" denir; çünkü bu derste mikrodenetleyici, mikroişlemci, firmware ya da PCB layout işi yoktur. Sonunda arkası ızgaralı bir çalışma alanı (workspace) açılır.

Mac kullananlar için Multisim gibi başka bir simülatör de kullanılabilir. Hocanın ifadesiyle önemli olan devrenin kurulması, simüle edilmesi, grafiklerin çıkması ve sonuçların gösterilmesidir; Proteus anlatım kolaylığı için seçilmiştir.

Hoca elektrik kesintisi ya da bilgisayarın kapanması riskine karşı ekran çıktılarını ve verileri adım adım kaydetmeyi önerdi; demo sürümde program kapanırsa çizilen devre kaybolur.

## 3. Eleman Seçme, Değer Girme ve Bağlantı

### 3.1 Eleman seçme

Proteus'ta bir işin genelde birden fazla yolu vardır. Eleman seçmek için araç çubuğundaki P harfine tıklanabilir ya da klavyede P tuşuna basılabilir. Açılan pencerede anahtar kelime yazılınca liste filtrelenir; "diode" yazınca diyotla ilgili her şey çıkar.

Diyot listesinde Schottky diyot, zener diyot ve eşik gerilimi yaklaşık 0,7 V olan sıradan silisyum diyot gibi farklı modeller vardır. Soruda hangi diyotun kullanılacağı söylenirse o kullanılır. Söylenmemişse bunun bir sebebi vardır ve uygun eleman seçilmelidir; örneğin istenmediği halde zener diyot seçmek hata sayılır.

**Soru:** Kullanılacak devre elemanları verilecek mi? **Cevap:** En azından devrenin şekli verilir; direnç, kapasite, opamp gibi elemanların ne olduğu şekilden anlaşılır. Değerler ya yazılır ya da öğrenci hesaplayarak bulur. Örneğin üçgen sembolün opamp olduğunu bilip listeden opamp seçmek gerekir.

### 3.2 Yerleştirme ve değer girme

Seçim penceresinde OK'a basınca pencere kapanır ve fareyle birlikte hareket eden, pembe gölgeli bir eleman belirir; çalışma alanında istenen yere tıklanınca bırakılır. Eleman parametrikse (yani bir değeri yoksa) değeri elle girilmelidir. Bunun için elemana çift tıklanır ya da sağ tuş "Edit Component" seçilir. Direnç için burada elemanın adı ve direnç değeri (ohm cinsinden) girilir; PCB paketi gibi diğer alanlarla işimiz yoktur. Ampermetrenin iç direnci gibi özel bir değer gerekirse bu soruda ayrıca açıklanır.

Ekrandaki örnek dirençte üstte ad olarak "R1", altta değer olarak "0R1" görünür (ekrandan, 00:40:00). Uygulamada hoca bir direncin değerini çift tıklayıp 7 ve 0,5 gibi değerlere değiştirerek gösterdi.

Bir elemanı silmek için seçim modunda elemanı seçip Delete tuşuna basılır. Ctrl-C/Ctrl-V çalışmaz; sağ tuş ile blok kopyalama yapılır. Bunlar programa elle alışarak öğrenilecek ayrıntılardır.

### 3.3 Bağlantı

Elemanlar, fareyle bir elemanın ucuna dokunup tutarak başka bir elemanın ucuna sürüklenerek bağlanır. Yalnız elemanları bağlamak bir devre oluşturmaz; devreyi "hayata döndürmek" için bir kaynak gerekir.

## 4. Kaynaklar ve Simülasyonu Başlatma

### 4.1 İki portlu kaynak

Bir öğrenci kaynağın eleman ekleme kısmından "voltage source" olarak eklendiğini söyledi. Hoca bunun tek yol olmadığını belirtti: derslerde çizilen yuvarlak içinde artı-eksi sembollü gerilim kaynağı da, lisedeki uzun çizgi-kısa çizgi sembollü batarya da kullanılabilir. Bunlar iki portludur: bir üst, bir alt ucu vardır. Örnekte klavyeye "DC voltage" yazılarak VSOURCE listesinden DC gerilim kaynağı alınıp devreye bağlandı.

**Soru:** Bu devrede bir sorun var mı? **Cevap:** Toprak eklenmemiştir, ama devre yine de çalışır ve alttaki mesaj alanı yeşildir. Proteus'taki iki portlu eleman devreyi bir biçimde kendisi topraklar. Yine de hoca bunun yalnız bir örnek olduğunu, devrelerin kesinlikle topraksız kullanılmaması gerektiğini kural olarak koydu.

### 4.2 Simülasyonu başlatma ve hata mesajları

Simülasyon alttaki play tuşuyla ya da üstteki yatay araç çubuğunda "Run Simulation" ile başlatılır. Hata varsa alttaki i simgeli mesaj alanı bir hata gösterir. Bu mesaj yazılımdaki adım adım hata ayıklama kadar net değildir, ama nereye odaklanmak gerektiğini söyler: örneğin kaynakla ilgili bir sorun, ampermetreyle ilgili bir sorun ya da bağlantıları eksik bir "floating" devre. Mesaja tıklanınca, hata yoksa her şeyin doğru çalıştığını söyleyen bir mesaj görülür. Hoca bu bilgilerin ileride mikroişlemciler dersinde de işe yarayacağını söyledi.

### 4.3 Tek portlu kaynaklar

Kaynak olarak tek portlu, iğne biçimli elemanlar da kullanılabilir. GENERATORS listesinde DC, SINE, PULSE, EXP, SFFM, PWLIN, FILE, AUDIO, DSTATE, DEDGE, DPULSE, DCLOCK, DPATTERN ve SCRIPTABLE seçenekleri vardır (ekrandan, 01:00:00). Tek portlu kaynak, bağlandığı noktayı besler; diğer ucu arka planda gizlice toprağa bağlıdır. Yani ekranda kablonun bir ucu havada duruyormuş gibi görünse de aslında altı toprağa bağlı, üstü 5 V olan bir gerilim kaynağı varmış gibi çalışır.

**Soru:** Sağ tarafta devre tamamlanmamıştı; Proteus onu kendisi mi tamamlıyor? **Cevap:** Evet. Bu eleman ucundan gerilim (ya da ne verildiyse, akım kaynağı da olabilir) sağlar ve arkadan toprağa bağlıdır. Proteus bunu kullanıcı yerine yapmıştır; kablonun havada durması bir zarar getirmez.

Kaynağın değeri çift tıklanarak ya da sağ tuş "Edit Properties" ile girilir. DC kaynakta yalnız gerilim değeri girilir (örnekte 10 V girildi). Sinüs kaynağı seçilirse sinüzoidal dalganın oluşması için gereken parametreler girilir.

**Soru:** Sinüzoidal bir dalgayı oluşturmak için gereken parametreler nelerdir? **Cevap:** En temel ikisi frekans ve genliktir; bunlara faz farkı ve offset eklenir. Proteus'ta girilmesi gereken başka parametreler de vardır.

Pulse (kare dalga) kaynakta da benzer biçimde parametreler girilir. Hoca kare dalganın her zaman kusursuz dik yükselmediğini, biraz eğimli yükseldiği için genelde eğik kenarlı çizildiğini anlattı. Bu yükselme eğimi, yükseklik ve periyodu (dolayısıyla frekansı) belirleyen süre, pulse kaynağının parametreleridir. Soruda ya bu değerler verilir ya da öğrenciden belirleyip yorumlaması istenir.

> **Hocanın vurgusu:** Osiloskop kullanımı, temel devre teorisi kavramları ve bir sinyalin yapısı (hangi parametrelere sahip olduğu, nasıl analiz edildiği) mutlaka bilinmelidir; bunlar bilinmeden devre kurulamaz ve laboratuvar raporlarında yorum olarak sorulabilir.

## 5. Ölçüm Araçları: Voltmetre, Ampermetre ve Problar

### 5.1 Gözlem araçları

Bir devre kurulur, beslenir ve çıkışından izlenir; temel adımlar hep buna dayanır. İzlemek için DC ya da AC voltmetre ve ampermetre, gücü ölçen wattmetre, osiloskop, lojik işlemler için lojik analizör kullanılabilir. Proteus'ta INSTRUMENTS listesinde OSCILLOSCOPE, LOGIC ANALYSER, COUNTER TIMER, VIRTUAL TERMINAL, SPI DEBUGGER, I2C DEBUGGER, SIGNAL GENERATOR, PATTERN GENERATOR, DC VOLTMETER, DC AMMETER, AC VOLTMETER, AC AMMETER ve WATTMETER bulunur (ekrandan, 00:45:00). Fiziksel laboratuvardaki masalarda iki problu (siyah ve kırmızı kablolu) dijital multimetreler vardı; simülasyonda bunların sanal karşılıkları kullanılır.

> **Ders sonrası not:** Altyazıda gücü ölçen alet "voltmetre" diye geçiyor; gücü ölçen alet wattmetredir (listede WATTMETER olarak görünür). Burada büyük olasılıkla wattmetre kastedildi.

### 5.2 Voltmetre paralel bağlanır

**Soru:** Voltmetre devreye nasıl bağlanır? **Cevap:** Paralel. Çünkü paralel iki elemanın uçları arasındaki gerilim düşümleri birbirine eşittir. Paralel, iki elemanın iki ucunun da birbirine dokunması demektir.

Ekrandaki devrede 5 V'luk $V_1$ kaynağına 5 Ω'luk $R_1$ bağlıdır; sağda bir voltmetre, solda bir ampermetre vardır (ekrandan, 00:50:00). Hoca $R_1$ ile $V_1$'in nasıl bağlı olduğunu sordu; bir öğrenci "seri" dedi. Hoca bunun yanlış olduğunu gösterdi: direncin bir ucuyla kaynağın bir ucu, direncin diğer ucuyla kaynağın diğer ucu birbirine dokunur, yani ikisi paraleldir. Elemanın yatay ya da dikey çizilmesi hiçbir şey değiştirmez. Voltmetre de bunlara paralel olduğu için üçü birbirine paraleldir ve direnç uçlarına düşen gerilim kaynağınki gibi 5 V'tur.

> **Hocanın vurgusu:** Devre derslerinin notlarını mutlaka gözden geçirin. Bu derste seri-paralel bağlantı, kapasite, bobin ve RLC devreleri yeniden anlatılmaz; bunlar hatırlanmazsa transistör (BJT, CMOS, JFET) konularında kopulur.

### 5.3 Ampermetre seri bağlanır

**Soru:** Ampermetre bu devreye (elemana paralel olarak) bağlanabilir mi? **Cevap:** Hayır. Ampermetre ne kadar küçük olursa olsun içinde bir direnç barındıran bir elemandır; paralel konursa akım kolay yoldan, ampermetrenin içinden geçer ve dirençten hiç geçmez. Bir öğrencinin dediği gibi bu bir kısa devre durumudur. Simülasyon başlatılınca alttaki mesaj alanı DC ampermetreyle ilgili bir hata gösterir.

Akım ölçerken akımın aletin bir ucundan girip diğer ucundan çıkması gerekir, yani alet seri bağlanır. Aynı koldaki elemanlardan geçen akım aynıdır; akım ancak kollara ayrıldığında bölünür.

### 5.4 Ters bağlantı ve eksi işaret

Ampermetre $R_1$ ile seri bağlandığında ekranda $-1$ görünür. Direnç uçları arasında 5 V vardır, bu yüzden akan akım $I = 5/5 = 1$ A olmalıdır.

**Soru:** Neden $-1$ yazıyor? **Cevap:** Bir öğrencinin dediği gibi ters bağlanmıştır. Aletin artı ucu göreli olarak topraktaki tarafa gelmiştir; akım aletin eksi ucundan girip artı ucundan çıktığı için değer eksi görünür. Ölçüm aleti bağlanırken akımın yönü doğru tespit edilmeli ve akım aletin artı ucundan girecek biçimde bağlanmalıdır; aksi halde işaret yanlış çıkar.

### 5.5 Gerilim ve akım probları

PROBES listesinde VOLTAGE, CURRENT ve TAPE seçenekleri vardır (ekrandan, 00:55:00). Prob, ekrandaki kaleme benzeyen, mavi, üçgen uçlu bir elemandır; iğneyi bir yere dokundurur gibi o noktanın değerini verir. Gerilim probunun referansı topraktır.

Hoca iki prob arasındaki bir farkı Proteus'un bir bug'ı olabileceğini söyleyerek anlattı: gerilim probu bir yere konup oradan devreye kablo çekilince sorun çıkmaz, ama akım probu bu şekilde hata verir. Akım probu ölçüm yapılacak tele doğrudan tıklanarak konmalıdır.

Akım probu örneğinde (ekrandan, 00:55:00) 5 V'luk $V_1$ ile 5 Ω'luk $R_1$ tek gözlü bir devre oluşturur; kaynağın eksi ucu toprağa bağlıdır. Akım kaynağın artı ucundan çıkıp $R_1$ üzerinden dolanır. Direnç uçlarında 5 V vardır ve $I = 5/5 = 1$ A olmalıdır, ama prob $I=-1$ gösterir.

**Soru:** Neden yine eksi bir? **Cevap:** Bir öğrencinin dediği gibi yön terstir. Akım probunun sembolündeki ok yön belirtir. Prob sağ tuş "Rotate 180" ile çevrilip yönü akımın yönüyle aynı yapılınca değer $+1$'e döner.

Hoca devreyi ampermetre, voltmetre ya da problarla analiz edip ekran çıktısı koymanın istendiği sorularda bu işaretlere dikkat edilmesini istedi.

## 6. Toprak Bağlantısı

Ampermetre, voltmetre ve osiloskop gibi iki portlu ölçüm aletleri eksi uçlarını toprakmış gibi referans alır; bu yüzden topraksız devrede de doğru gösterirler. Tek portlu gerilim probu ise referansı toprak olduğu için devrede toprak yoksa neye göre ölçeceğini bilemez ve yanlış değer verir. Örnekte topraksız devrede prob 5 V olması gereken noktada 3,3 V göstermiştir. Devre topraklanınca toprak tarafı 0 V, kaynağın üst ucu 5 V olur ve prob doğru olarak 5 V okur.

> **Hocanın vurgusu:** Devreler her zaman topraklanmalıdır. Bazı öğrenciler toprağı koymayıp yalnız prob koyuyor; bu yanlış değer verir.

Hoca karşılaştırma olarak Cadence'ta toprak konusunun bir sorun olduğunu, Proteus'ta ise iki portlu elemanlarda şimdilik sorun çıkmadığını söyledi.

## 7. Dört Dirençli Devre Örneği

### 7.1 Devrenin yapısı

Ekrandaki devrede (ekrandan, 01:00:00 ve 01:05:00) $R_1 = 5\ \Omega$ ve $R_2 = 5\ \Omega$ art arda bağlıdır, $R_3 = 10\ \Omega$ bunların bitiş düğümünden toprağa iner, $R_4 = 5\ \Omega$ aynı düğümden sağdaki kaynağa gider. Devre sağ uçtan tek portlu 10 V DC kaynakla beslenir; $R_1$'in sol ucu ve $R_3$'ün alt ucu toprağa bağlıdır. Problar şu değerleri gösterir: $R_1$'in sol ucunda $V=0$, $R_1$-$R_2$ arasında $I=-0{,}5$, ara düğümde $V=5$, $R_4$ üzerinde $I=-1$.

**Soru:** $R_1$ ile $R_2$ nasıl bağlıdır? **Cevap:** Bir öğrenci paralel dedi; doğrusu seridir. İki direncin yalnız bir ucu birbirine dokunur, diğer uçları farklı yerlere gider. $R_1$'in sol ucu toprağa bağlı olduğu için 0 V'tur, diğer uç ise başka bir gerilimdedir.

### 7.2 Eşdeğer direnç

Seri iki direnç toplanır:

$$R_1 + R_2 = 5 + 5 = 10\ \Omega$$

Hoca birimin unutulmamasını özellikle hatırlattı. Bu 10 Ω, $R_3 = 10\ \Omega$ ile paraleldir. Eşit iki paralel direncin eşdeğeri doğrudan yarısıdır; eşit değilse çarpımları toplamlarına bölünür:

$$(R_1+R_2) \parallel R_3 = \frac{10 \cdot 10}{10 + 10} = 5\ \Omega$$

Bir öğrenci "yukarıya çarpımlar, aşağıya toplamlar" diye formülü hatırlattı. Hoca $1/R_1 + 1/R_2 = 1/R_{\text{eş}}$ biçimiyle uğraşmak yerine bu kısa yolun kullanılmasını istedi. $R_4$'ün sol tarafından devreye bakınca görülen eşdeğer direnç 5 Ω'dur (hoca bunu Thévenin sorularındaki bakış açısına benzetti). Buna seri $R_4 = 5\ \Omega$ eklenince:

$$R_{\text{eş}} = 5 + 5 = 10\ \Omega$$

> **Hocanın vurgusu:** Laboratuvarda ve sınavlarda hız kazanmak için gerilim bölücü, akım bölücü, seri-paralel bağlantı ve direnç, kapasite, bobin için eşdeğer hesapları gözden geçirin.

### 7.3 Akımlar ve gerilimler

Ana koldaki akım Ohm yasasından:

$$I = \frac{V}{R_{\text{eş}}} = \frac{10}{10} = 1\ \text{A}$$

Bu akım ara düğümde iki kola ayrılır. İki koldaki dirençler eşit (her biri 10 Ω) olduğu için akım ikiye eşit bölünür: her kolda $0{,}5$ A. Ara düğümün gerilimi (ara adım eklendi): kaynak 10 V, $R_4$ üzerinde $1 \cdot 5 = 5$ V düşer, kalan $10 - 5 = 5$ V düğümde ölçülür; bu da probun gösterdiği $V=5$ ile uyumludur. Probların gösterdiği eksi işaretler yine probların yönünden gelir.

## 8. Zamana Bağlı Grafik Çizdirme

Soruda örneğin "0'dan 1 saniyeye kadar şu elemanın üzerindeki akımı zamana bağlı çizdiriniz" denirse grafik modundan analog grafik seçilir. Grafik elemanı da bir komponent gibi fareyle çalışma alanına konur. Sağ tuş menüsünde "Add Trace" ile izlenecek değer eklenir; her trace otomatik olarak farklı renkte gelir. Proba verilen ada göre (örneğin R1(2)) hangi değerin çizileceği seçilir, sonra "Simulate Graph" ile grafik çizilir.

Dört dirençli devrede kaynak DC olduğu için değerler zamanla değişmez. $R_1$ kolundaki akım 0–1 s boyunca sabit 0,5 A çıkar; prob yönü ters olduğu için grafikte $-0{,}5$ A görünür. Sinüzoidal kaynakta ise değer zamanla inip çıkardı. Hoca transient analiz ve parametrik analiz yapılabildiğini, analiz süresini (0–1 s, 0–2 s gibi) ayarlamanın araştırılmasını istedi.

## 9. Gerilim İzleyici ve Osiloskop

### 9.1 Devre

DC dışında, örneğin sinüzoidal besleme için hoca bir opamp devresi gösterdi (ekrandan, 01:10:00). Devrede opamp U1, 10 Ω'luk $R_5$ yük direnci (çıkıştan toprağa), tek portlu sinüs kaynağı ve osiloskop vardır. Opampın çıkışı osiloskobun A kanalına (sarı), giriş B kanalına (mavi) bağlanmıştır. Hoca bu devreye voltage follower (gerilim izleyici) dedi: girişte hangi sinyal verilirse çıkışta aynı genlik ve frekansta o görülür.

Opamp, P tuşuyla listeye "opamp" yazılarak alınır; direnç 10 değeriyle konur; osiloskop INSTRUMENTS listesinden seçilir. Proteus osiloskobunun A, B, C, D olmak üzere dört kanalı vardır, yani dört noktadaki sinyal aynı anda izlenebilir. Sinyal sinüs, kare ya da testere dişi gibi genliği ve frekansı olan bir sinyalse DC ölçüm yerine osiloskopla incelenir.

Sinüs kaynağına çift tıklanınca DC kaynaktaki tek kutu yerine offset, genlik, frekans gibi birçok parametre istenir. Soruda belirli bir sinyal istenirse bu parametreler kaynağın özelliklerinden güncellenir.

> **Ders sonrası not:** Ekrandaki çizimde çıkıştan dönen geri besleme opampın + girişine, sinüs girişi ise − girişine bağlı görünmektedir (ekrandan, 01:10:00); hoca da "eksi terminalinden bir giriş uygulanmış" dedi. Standart gerilim izleyicide çıkış − girişe geri beslenir, sinyal + girişe verilir. Çizimdeki bağlantı gerçek bir opampta pozitif geri besleme olurdu; simülasyonda giriş ve çıkışın aynı görünmesi büyük olasılıkla kullanılan opamp modelinden kaynaklanır.

<!-- BELİRSİZ: Hoca devrenin kullanımı için "aynı gerilimi almak ama bir delay koymak" ifadesini kullandı; gerilim izleyicinin olağan kullanımı tampon (empedans ayırma) olarak bilinir. Altyazıdan ne kastedildiği net değil. -->

### 9.2 Osiloskop ekranı

Proteus osiloskobu laboratuvardaki gerçek cihaza benzer: solda ekran, sağda düğmeler vardır. Ekranda sarı çıkış ve mavi giriş aynı genlik ve frekansta iki sinüs olarak görünür (ekrandan, 01:25:00). Hoca burada önemli olanın devrenin ne yaptığı değil, girişe sinüs verip çıkışta gözlem yapabilmek olduğunu söyledi.

> **Hocanın vurgusu:** Lojik devre, elektronik ve mikroişlemci derslerinden sonra dördüncü donanım dersinde bile öğrencilerin büyük kısmı (hocanın tahminiyle yaklaşık %80) osiloskop kullanmayı bilmiyor. Bunun bu elektronik laboratuvarında çözülmesi gerekir.

### 9.3 Izgara ve ölçek

Ekranın siyah zemininde kareli defter gibi yeşil bir ızgara vardır ve bu ızgara bir amaçla konmuştur: her karenin yatayda ve dikeyde bir değeri vardır. Hoca bunu kareli deftere çizilmiş bir sinüs örneğiyle anlattı: biri kareli deftere bir sinüs çizip, yataydaki kare uzunluklarının bir sayıyı, dikeydeki yüksekliklerin başka bir sayıyı temsil ettiğini söylerse, osiloskobun yaptığı iş tam olarak budur.

Osiloskop sinyalin değerini değiştirmez, yalnız göstermek için ölçekler. Düğmeler ne kadar kurcalanırsa kurcalansın sinyal değişmez. Girişteki sinyali değiştirmek için kaynağa, çıkıştakini değiştirmek için devredeki direnç, kapasite ve opamp gibi elemanlara müdahale etmek gerekir. Hoca bunun tersini düşünmenin yaygın bir yanlış algı olduğunu söyledi. Ölçek düğmesi büyütülüp küçültülünce bir tür zoom yapılır; çok yakından bakılırsa sinyalin küçük bir kısmı dümdüz bir çizgi gibi görünebilir.

Osiloskopta Channel A, B, C, D ve Horizontal bölümleri vardır (ekrandan, 01:15:00). Horizontal bütün kanallar için ortaktır ve birimi saniyedir; sinyalin yatay eksendeki periyoduyla, dolayısıyla frekansıyla ilgilidir. Örnekte bir karenin yatay uzunluğu 0,2 ms'dir. Dikey ayar her kanal için ayrıdır ve birimi volttur; örnekte A kanalı için bir kare yaklaşık 5 mV'tur.

<!-- BELİRSİZ: 01:25:00 karesinde A kanalının dikey ayar kutusunda "0.5" gibi bir değer görünüyor; hocanın söylediği 5 mV değeriyle karşılaştırılamadı. -->

Uygulamada hoca A kanalının dikey ayarını değiştirince sinyal kayboluyormuş gibi göründü. Hoca burada öğrencinin sinüs kaynağında hata olduğunu düşünebileceğini, oysa önce bu ölçek ayarlarına bakmak gerektiğini gösterdi.

> **Ek bilgi (derste anlatılmadı):** Osiloskopta sinyalin periyodu, bir tam dalganın yatayda kapladığı kare sayısı ile time/div değerinin çarpımıdır; frekans bunun tersidir ($f = 1/T$). Tepe-tepe genlik de dikeyde kaplanan kare sayısı ile volt/div değerinin çarpımıdır.

### 9.4 Osiloskop penceresini yeniden açma

Simülasyon sırasında osiloskop penceresi bazen ekrana gelmez ya da çarpıdan kapatılmışsa kaybolur. Tekrar açmak için Debug menüsünden "Digital Oscilloscope" seçilir. Simülasyon dururken pencereye çift tıklamaya çalışılırsa "simulation must be paused" uyarısı gelir. Hoca bunu bir bug olarak gördüğünü ve öğrencilerin bunu ararken zaman kaybettiğini söyledi; bu bilgi mikroişlemciler dersinde de işe yarar.

## 10. Breadboard ve Fritzing

### 10.1 Breadboard

Fiziksel laboratuvarda devreler breadboard ("ekmek tahtası") üzerine kurulurdu. Breadboard delikli bir tabladır. Üstteki ve alttaki uzun güç satırlarında (kırmızı ve mavi çizgili) delikler kendi içinde yatay olarak birbirine bağlıdır; güç kaynağı buraya bağlanır, biri gerilim biri toprak satırı olur. Ortadaki bölümde her sütundaki delik grubu kendi içinde birbirine bağlıdır ve altında teller varmış gibi düşünülür. Ortadaki oluk iki yarıyı birbirinden ayırır; oluğun iki yanı arasında bağlantı yoktur.

### 10.2 Fritzing

Fritzing açık kaynaklı, isteyenin bağış yapabildiği bir platformdur. Bir simülasyon ortamı değildir; devrenin breadboard üzerinde fiziksel olarak nasıl kurulduğunu gösterir. Fiziksel laboratuvar yapılamadığı için bir çözüm olarak anlatıldı; projede ilk adım olarak devrenin Fritzing'de kurulup gösterilmesi istenebilir. Fritzing'in çekirdek kütüphanesinde direnç, kapasite, BJT gibi standart elemanlar vardır; örneğin üç bacaklı bir eleman alınıp bacakları ilgili yerlere bağlanarak bir transistör devresi kurulabilir.

**Soru:** Fritzing ile Proteus'un bağlantısı nedir? **Cevap:** Bir bağlantısı yoktur. Proteus teknik olarak ölçüp biçmek içindir; Fritzing ise fiziksel bağlantıyı gösterir, bir ölçüme yaramaz.

### 10.3 Breadboard'daki iki direnç

Fritzing ekranında bir güç girişine bağlı iki direnç vardır (ekrandan, 01:20:00).

**Soru:** Bu iki direnç birbirine nasıl bağlıdır? **Cevap:** Hoca önce "paralel değil mi" diye sordu; bir öğrenci doğru olarak "seri" dedi. Bir dikey sütun kendi içinde bağlı olduğu için direncin bir ucu ile diğer direncin bir ucu birbirine bağlıdır, ama diğer uçları başka başka yerlerdedir. Fritzing'de birbirine bağlı delikler hafif yeşil renkle gösterilir. Gerilim birinci dirençten geçip ikinci dirence aktarılır.

Daha sonra hoca dirençleri, her iki ucu da ortak bağlı noktalara gelecek biçimde yerleştirdi; bu durumda gerilim ikisini de etkileyerek topraklı bacaklardan toprağa gider ve iki direnç paralel olur.

### 10.4 Kısa devre örneği

**Soru:** Breadboard'a bir bobin, iki bacağı aynı bağlı grupta olacak biçimde takılırsa ne olur? **Cevap:** Bir öğrencinin dediği gibi çalışmaz; kısa devredir. O deliklerin hepsi alttan birbirine bağlı olduğu için akım bobinin üzerinden değil, kısa yoldan breadboard'un içinden geçer. Hoca bobin yerine direnç örneğinin daha uygun olacağını, ama durumun her eleman için kısa devre olduğunu söyledi.

**Soru:** Proteus'ta bir breadboard yok mu? **Cevap:** Hoca olabileceğini ama hiç kullanmadığını söyledi; olsa bile breadboard kadar görsel olduğunu düşünmüyor. Fritzing yalnız doğru bağlantıları gösterir, ölçüme yaramaz; ama şu an fiziksel bir laboratuvar ortamını canlandırmanın tek yolu budur.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:45:53): Voltmetre devreye nasıl bağlanır, neden?

> **Çözüm:** Paralel bağlanır. Paralel elemanların uçları arasındaki gerilim eşit olduğu için voltmetre bağlandığı elemanın gerilimini gösterir.

**Soru 2** (ekrandan, 00:50:00; derste sözlü, 00:46:35 ve 00:48:00): 5 V'luk $V_1$ kaynağına 5 Ω'luk $R_1$ ve bir voltmetre bağlıdır. $R_1$ ile $V_1$ nasıl bağlıdır ve direnç uçlarında kaç volt düşer?

> **Çözüm:** İki elemanın iki ucu da birbirine dokunduğu için paraleldirler (seri değil). Voltmetre de paralel olduğu için üçü paraleldir; direnç uçlarındaki gerilim 5 V'tur.

**Soru 3** (ekrandan, 00:55:00; derste sözlü, 00:54:15): 5 V'luk kaynak ve 5 Ω'luk direnç tek gözlü bir devre oluşturuyor. Akım probu $I=-1$ gösteriyor. Akım kaç amperdir, neden eksi görünür?

> **Çözüm:** $I = 5/5 = 1$ A. Prob akım yönüne ters yerleştirildiği için eksi görünür; 180° döndürülünce $+1$ A okunur.

**Soru 4** (derste sözlü, 00:58:49): Sinüzoidal bir dalgayı oluşturmak için hangi parametreler gerekir?

> **Çözüm:** Frekans ve genlik (en temel ikisi), ayrıca faz farkı ve offset.

**Soru 5** (ekrandan, 01:00:00; derste sözlü, 01:00:28 – 01:04:29): $R_1 = R_2 = 5\ \Omega$ seri, bunlar $R_3 = 10\ \Omega$ ile paralel, buna seri $R_4 = 5\ \Omega$; devre 10 V DC ile besleniyor. $R_1$ ile $R_2$ nasıl bağlıdır? Eşdeğer direnç, ana kol akımı ve kol akımları nedir?

> **Çözüm:** $R_1$ ile $R_2$ seridir: $10\ \Omega$. $10 \parallel 10 = 5\ \Omega$. $R_{\text{eş}} = 5 + 5 = 10\ \Omega$. $I = 10/10 = 1$ A. Eşit iki kola bölünür: $0{,}5$ A ve $0{,}5$ A. Ara düğüm gerilimi $10 - 1\cdot 5 = 5$ V (sonuçlar python ile doğrulandı).

**Soru 6** (ekrandan, 01:20:00; derste sözlü, 01:20:22): Breadboard'da bir ucu aynı sütunda, diğer uçları farklı sütunlarda olan iki direnç nasıl bağlıdır?

> **Çözüm:** Seri bağlıdır; ortak olan yalnız bir uçtur.

**Soru 7** (derste sözlü, 01:26:52): Breadboard'da bir elemanın iki bacağı aynı bağlı delik grubuna takılırsa ne olur?

> **Çözüm:** Eleman kısa devre edilir; akım elemanın üzerinden değil, breadboard'un içindeki bağlantıdan geçer.

## Dersin Toparlaması

Bu laboratuvar tanıtımında dönem boyunca kullanılacak simülasyon ortamı tanıtıldı. Proteus'ta eleman seçme (P tuşu), değer girme, bağlantı yapma, iki portlu ve tek portlu kaynaklar, simülasyonu başlatma ve hata mesajlarını okuma gösterildi. Ölçüm tarafında voltmetrenin paralel, ampermetrenin seri bağlanması, ters bağlantının eksi değer vermesi, akım ve gerilim problarının kullanımı ve devrenin her zaman topraklanması gerektiği vurgulandı. Tek gözlü 5 V / 5 Ω devresi ve dört dirençli 10 V devresi üzerinden seri-paralel analiz, eşdeğer direnç ve akım bölünmesi hatırlatıldı; zamana bağlı grafik çizdirme anlatıldı.

Son bölümde bir opamp devresinde giriş ve çıkış sinyalleri osiloskopla izlendi; yatay eksenin bütün kanallar için ortak zaman ölçeği, dikey eksenin kanal başına gerilim ölçeği olduğu ve osiloskop ayarlarının sinyali değil yalnız gösterimi değiştirdiği anlatıldı. Breadboard'un iç bağlantıları ve Fritzing ile fiziksel bağlantının gösterilmesi tanıtıldı. Sonraki laboratuvarlar ders sırasına göre diyot, opamp, BJT ve CMOS konularında olacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
