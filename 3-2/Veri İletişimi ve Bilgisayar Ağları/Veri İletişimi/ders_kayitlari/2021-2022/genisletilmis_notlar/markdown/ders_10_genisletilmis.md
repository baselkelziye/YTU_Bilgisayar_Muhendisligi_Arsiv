# Ders 10 Genişletilmiş Notu: Seri ve Paralel İletim, Eş Zamanlılık ve Yönlendirilmiş İletim Ortamları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Sayısal Veri İletiminde Önceden Belirlenmesi Gerekenler
- 3. Paralel İletim
- 4. Seri İletim ve RS-232
- 5. Eş Zamansız (Asenkron) İletim
- 6. Eş Zamanlı (Senkron) İletim
- 7. DTE, DCE ve Sıfır Modem
- 8. Kablolama Bir Altyapı Yatırımıdır
- 9. Yönlendirilmiş ve Yönlendirilmemiş Ortam
- 10. Eş Eksenli (Koaksiyel) Kablo
- 11. Burgulu Çift (Twisted Pair) Kablo
- 12. Fiber Optik Kablo
- 13. Bakır ve Fiber Karşılaştırması
- Örnek Sorular

## 1. Dersin Planı

Hoca derse, bir önceki bölümün bittiğini ve yeni bölüme başlanacağını söyleyerek girdi. Bugünün konusu iletim teknikleriydi. İletim teknikleri temel olarak ikiye ayrılır: paralel (parallel) ve seri (serial). Ders boyunca bu iki tekniğin birbirine göre artıları ve eksileri konuşulacak, seri iletimin alt kırılımlarına, yani eş zamanlılık kavramına (senkron ve asenkron) bakılacaktı. Bu tekniklerde kullanılan bağlantı noktaları da gözden geçirilecekti. Hoca bunların bir kısmının artık tarihsel (historical) olduğunu, ama geçmişten bugüne kullanılmış bağlantı tekniklerini bilmenin yararlı olduğunu söyledi.

Dersin ikinci yarısında iletim ortamına (transmission medium) geçilecekti. İletim ortamı haberleşmenin en temel unsurlarından biridir. En temel sınıflandırması yönlendirilmiş (guided) ve yönlendirilmemiş (unguided) ortam ayrımıdır.

- **Yönlendirilmiş ortam:** En güzel örneği kablodur. Kablo bakır olabilir, silikadan yapılmış fiber olabilir. Üzerinden illa elektrik akımı geçmesi gerekmez, ışık da taşınabilir. Sinyalin belli bir ortam içinde, izin verilen şekilde ilerlediği yapılardır.
- **Yönlendirilmemiş ortam:** Radyo, Wi-Fi (Wireless Ethernet) gibi günlük hayatta çokça kullandığımız teknolojiler. Haberleşme ortamı havadır ve farklı frekanslarda oluşturulan dalgalar üzerinden haberleşilir.

Hoca, bu grubun diğer gruplardan öne geçtiğini, bu yüzden bu hafta çok hızlı gitmeyeceğini ve yönlendirilmiş ortamlar bitince duracağını söyledi.

## 2. Sayısal Veri İletiminde Önceden Belirlenmesi Gerekenler

Paralel ve seri iletime geçmeden önce hoca, iletimin gerçekleşebilmesi için birkaç şeyin önceden netleştirilmiş olması gerektiğini anlattı:

- **Kullanılacak ortam:** Yönlendirilmiş bir yapıysa nasıl bir kablo olacak? Tek telli mi, çok telli mi? Hangi tel ne iş görecek? Örneğin bir tel gönderme (transmit), diğeri alma (receive) için kullanılabilir. Bunlardan birkaç çift oluşturulabilir. Saat (clock) sinyali için ayrı bir hat eklenecek mi?
- **Sinyalin nasıl oluşturulacağı:** Veri aktarmak için her zaman bir işaretimiz vardır ve o işaretin özellikleriyle oynarız. Bazen bir taşıyıcı (carrier) sinyal üzerinde değişiklik yaparız, bazen veriyi doğrudan bir sinyale çeviririz. Sayısaldan sayısala (digital-to-digital) kodlamada gördüğümüz NRZ (Non-Return to Zero) gibi yapılar buna örnektir.
- **Mekanik ve fiziksel bağlantı:** Alıcı ve vericinin ortama bağlanabilmesi gerekir. Bu bağlantıyı sağlayan yapıya konnektör (connector) denir.

Bu standartlara bağlı olarak haberleşme paralel ya da seri olabilir. İkisi arasındaki farkın özü, ortamda kullanılan bağlantı ve tel sayısıdır.

## 3. Paralel İletim

### 3.1 Tanım, Avantaj ve Dezavantaj

Karşıya göndereceğiniz bilgiyi tek tek bit olarak değil de bir grup bit halinde, her bit ayrı bir tel üzerinden gidecek şekilde gönderiyorsanız yaptığınız şey paralel iletimdir. Örneğin her seferinde 4 bit ya da 8 bit gönderiyor ve bu bitlerin her biri ayrı bir telden gidiyorsa paralel veri iletimi tarif edilmiş olur.

Hoca sınıfa paralel iletimin avantajını sordu. Cevap hızdı: Tek seferde bir değil $n$ tane bit aktarıldığı için birim zamanda aktarılan bit miktarı artar. Ardından kötü tarafını sordu. Cevap maliyetti. Hoca bunu bir bilgisayar ile yazıcı arasındaki bağlantı üzerinden açıkladı. Kablo bir buçuk metre bile olsa, 8 bitlik paralellik için kablonun içinde en az 8 ayrı tel gerekir. Bu da yetmez. Karşı tarafın gönderime uygun olup olmadığını sorgulamak, cevap almak, akış denetimi için iletimi durdurabilmek gibi kontrol noktaları varsa onlar için de birer tel gerekir. Sonuçta "devasa bir kablo yığını" ortaya çıkar.

**Soru:** Veri gönderilirken paketler mi hatlara bölünüyor, yoksa bir paket birinci hattan, diğeri ikinci hattan mı gidiyor? Öğrenci aslında verinin başının ve sonunun belli olmasını, yani çerçevelemeyi (framing) kastediyordu.

**Cevap:** Burada paket diye bir şey yoktur. Paket denince çoğu zaman ağ katmanı (network layer) akla gelir. Şu an en alt seviyede, fiziksel katmandayız. Konuşulan şey, bilginin iletim ortamı üzerinden karşıya aktarılması ve orada alınıp anlamlandırılmasıdır. Henüz çerçeveleme de, paketleme de yoktur. Çerçeve oluşturma veri bağı katmanının (data link layer) işidir. Burada sorulan tek şey şudur: Her bit ayrı bir sembolle tek bir damar üzerinden peş peşe mi aktarılıyor (seri), yoksa her bit ayrı bir tel üzerinden mi aktarılıyor (paralel)?

### 3.2 Paralel Port

Eskiden bilgisayarlarda paralel port bulunuyordu. Bugün bundan pek bir şey kalmadı, onun yerine USB'ye (Universal Serial Bus) geçildi. Hoca, slayttaki hız rakamlarının bugün komik gelebileceğini, ama o dönemi düşünmek gerektiğini söyledi. ECP ve EPP türündeki paralel portlarla elde edilen hızlar, o dönemde seri portla elde edilen hızların kat kat üstündeydi. Seri port megabaytları görmüyor, kilobaytlar düzeyinde kalıyordu.

PC tarafında DB25 konnektör kullanılır. DB25, 25 bağlantı noktasına sahip bir konnektördür. Hoca bunu, bugün gördüğümüz VGA konnektörünün daha geniş, üç sıra yerine iki sıra olan hali diye tarif etti. İçinde:

- 8 veri hattı vardır: veri bitleri 0'dan 7'ye kadar.
- Kontrol ve durum hatları vardır: Error, Paper Out, Busy, Acknowledge, Select gibi.

Bu kontrol işaretlerinin varlık sebebi haberleşmedeki asimetridir. Veri sürekli PC'den yazıcıya gider, yazıcıdan geri dönen çok az şey vardır. PC kapasite olarak çok daha güçlüdür, karşıda daha yavaş bir yapı vardır. Bu yüzden yazıcının o an bilgi kabul edemeyecek durumda olduğunu (meşgul) ya da bir hata durumunu (kâğıt bitti vb.) bildirebilmesi gerekir. Hocanın ifadesiyle toplamda 18 tel doğrudan kullanılır.

> **Ders sonrası not:** DB25 paralel portta büyük olasılıkla 17 sinyal hattı (8 veri, 4 kontrol, 5 durum) ve 8 toprak hattı vardır. Hocanın "18 tel" demesi bu sayıya yakın bir yaklaşık değerdir.

Yazıcı tarafında ise Centronics adı verilen, daha çok soket kıvamında, en az o kadar bağlantıyı destekleyen farklı bir konnektör vardır.

Paralel iletimin maliyet dışındaki ikinci sıkıntısı mesafe kısıtıdır. Slayta göre paralel port kablolarının uzunluğu 7,5 metre ile sınırlıdır.

### 3.3 Paralel Port ile PC'den PC'ye Bağlantı

Paralel iletim yalnız PC ile yazıcı arasında yapılmak zorunda değildi. Zamanında PC'den PC'ye bilgi aktarmak için de kullanılıyordu. Fakat paralel port tasarım olarak PC'den yazıcıya bilgi aktarmak için yapılmıştı, kontrol işaretleri de bu yüzden vardı. Dolayısıyla PC-PC bağlantısı işletim sistemi tarafından doğrudan desteklenmiyordu. Genellikle çapraz (cross) bir bağlantı yapılır ve üzerine üçüncü parti bir uygulama kurulurdu.

Çapraz bağlantıda veri pinleri karşı tarafın veri pinlerine bağlanmaz:

- Bir tarafın 2 numaralı pini diğer tarafın 15 numaralı pinine, 3 numaralı pini diğer tarafın 13 numaralı pinine bağlanır.
- Yani veri biti 0 ve 1 karşıda Error ve Select'e, veri biti 2 Paper Out'a, veri biti 3 Acknowledge'a, veri biti 4 Busy'ye bağlanır.
- Aynısı ters yönde de yapılır.

Hoca bunu bir tür sıfır modem (null modem) bağlantısı olarak adlandırdı.

> **Hocanın vurgusu:** Bacak (pin) bağlantı tablolarına çok takılmayın. Bunlar genel kültür olarak söylenen şeyler. Asıl bilmeniz gereken teori, mantık ve nasıl çalıştığıdır.

## 4. Seri İletim ve RS-232

Paralelin kötü tarafları maliyet ve mesafe kısıtıydı. Paralel portta 18 ayrı tel kullanılıyordu. İhtiyaç, daha az telin kullanıldığı ve daha uzağa gidebilen bir iletimdir. Seri iletimde bitler tek bir hat üzerinden peş peşe gönderilir.

Bunun için geliştirilmiş yapılardan biri RS-232C'dir. Hoca RS-232 ile 155 kbps hıza ve 15 metre mesafeye ulaşılabildiğini, RS-422 ile ise işin 300 metrelere vardığını söyledi. RS-232'nin bir diğer adı EIA-232'dir.

> **Ders sonrası not:** Hoca "155 kbps ve 15 m" dedi. RS-232 standardı büyük olasılıkla 15 m (50 ft) için yaklaşık 20 kbps tanımlar; uygulamada yaygın üst hız 115,2 kbps'tir. RS-422 de düşük hızlarda büyük olasılıkla yaklaşık 1200 m'ye kadar gidebilir; hoca 300 m dedi.

RS-232'de kodlama olarak NRZ-L (Non-Return to Zero Level) kullanılır. 1'i ifade etmek için $-15$ ile $-5$ V arası, 0'ı ifade etmek için $+5$ ile $+15$ V arası kullanılır. Sinyal seviyesi oldukça yüksektir. Hoca bunun sebebini şöyle açıkladı: Mesafe uzadıkça üzerinde yol alınan telin bir direnci oluşur ve sinyal bu direnç yüzünden yavaş yavaş sönümlenir. Geniş bir gerilim aralığı verildiği için zayıflamış sinyal de doğru okunabilir ve daha uzun mesafeye gidilebilir.

> **Ders sonrası not:** RS-232'de verici büyük olasılıkla $\pm 5$ ile $\pm 15$ V arası üretir, alıcı ise $\pm 3$ ile $\pm 15$ V arasını geçerli sayar. $-3$ ile $+3$ V arası tanımsız bölgedir.

## 5. Eş Zamansız (Asenkron) İletim

### 5.1 Temel Fikir

Seri iletim iki temel yaklaşımla yapılabilir: eş zamansız (asynchronous) ve eş zamanlı (synchronous). Hoca bu adların ilk duyuşta çok şey ifade etmeyebileceğini, birazdan oturacağını söyledi.

Eş zamansız yapıda gönderici ile alıcının ortak bir saate göre kendilerini senkronize etmesi beklenmez. Herhangi bir $t$ anında göndericinin elinde veri varsa, gönderici bu bilgiyi hatta basar. İki ucun eriştiği ya da birinin kontrol ettiği ortak bir zaman işareti yoktur. Bunun yerine bir anlaşma vardır: Hatta bilgi çıkmaya başladığı andan itibaren her işaret, yani 0 ya da 1'i ifade eden sinyal, belli bir süre hatta kalır. Örneğin her bit için hat 10 milisaniye boyunca o durumda tutulur. Gönderici de alıcı da bunu bilir ve hattaki sinyali buna göre anlamlandırır.

### 5.2 Sorun Ne? Bekleme Süresi Tartışması

Hoca bu yaklaşımın sorununun ne olduğunu sordu. Bir öğrenci, her bit için belli bir süre beklemenin hızı azaltabileceğini söyledi.

Hoca bunun asıl sorun olmadığını anlattı. Bir sinyalin hatta görünebilmesi için zaten belli bir süre durması gerekir. Geçen haftaki kodlamaları hatırlayın: NRZ-I ya da RZ yaparken de 1 için hattı belli bir süre bir seviyede, 0 için belli bir süre başka bir seviyede tutuyorduk. Asenkrondaki "belli süre tutma"nın bundan bir farkı yoktur. Hoca bunu osiloskopla örneklendirdi: Zaman eksenini çok geniş tutarsanız sinyali nokta gibi görürsünüz. Milisaniyelere indikçe sinyalin birkaç kareye oturduğunu görürsünüz. Sinyalin frekansı bellidir. Örneğin 10 Hz ise saniyede 10 kez değişir, yani her değişim 100 milisaniyede bir olur.

Bir öğrenci de sohbet penceresine "iletilen verinin senkronizasyon olmaması" ile ilgili bir cevap yazdı. Hoca cümleyi anlaşılmaz buldu ve oradaki terimin "bound rate" değil "baud rate" olması gerektiğini belirtti. Gürültünün veri sinyaliyle karışabileceği önerisine de, gürültünün zaten veri sinyalini bozan bir şey olduğunu, sorunun daha basit ve net olduğunu söyledi.

<!-- BELİRSİZ: Öğrencinin sohbet penceresine yazdığı cevabın tam metni altyazıdan çıkmıyor (00:37:12-00:37:39). -->

### 5.3 Asıl Sorun: Bağımsız Saatler

Hoca asıl sorunu bir benzetmeyle anlattı: "Yarın saat 17.34'te bölüm sekreterliğinin önünde buluşalım." Hepimizin saat kaynağı (clock source) aynı mı? Cevap hayırdır. Kolumuzdaki saate de baksak, bilgisayarımızdaki saate de baksak, birbirimizden bağımsız saatlere bakıyoruz. Sonuçta biriniz 17.30'da, biriniz 17.35'te, biriniz 17.40'ta gelir; ama hepinizin saati belki aynı şeyi gösteriyordur.

Cep telefonları saati GSM operatöründen günceller, bu bir ortak nokta sağlar. Fakat bu zaman senkronizasyonu da belli periyotlarla yapılır, saniye saniye yapılmaz. Saatinizin saniye kısmını açıp bakarsanız saniyeler düzeyinde farklar görürsünüz. Dağıtık sistemlerde zaman senkronizasyonu zaten bir problemdir.

Eş zamansız iletimde de durum budur: Slaytta yazdığı gibi iki taraf ortak bir zamanlama işaretine bağlı olarak hareket etmez. Hatta bir saat sinyali yoktur, iki tarafın saati ayrıdır. Bilinen tek şey çalışma hızıdır. Hoca hesap kolay olsun diye 10 Hz örneğini verdi: Saniyede 10 değişiklik yapılacaksa her sinyal 100 milisaniye kalır. Alıcı 100 milisaniyede bir hatta bakar ve sinyalin nerede başlayıp nerede bittiğini anlamaya çalışır.

Fakat sinyal her zaman 0-1-0-1 diye değişmez. DC bileşen konusunu ve bunu önlemek için Manchester ile diferansiyel Manchester kodlamayı konuşmuştuk. Diferansiyel Manchester'da 0 ile 1'i ayırt edebilmek için örnekler alınıp sürekliliğin olup olmadığına bakılır. Bunun için iki tarafın saatleri arasında fark olmaması ya da farkın en az olması gerekir.

Hoca saat kaymasını (clock drift) bir devre tasarımı örneğiyle somutlaştırdı. İki taraf 25 MHz'de çalışmak üzere anlaşır.

- Bir taraftaki tasarımcı 25 MHz'lik iyi bir osilatör koyar. Yanılma payı %1'dir: 100 tık yapması gerekirken bazen 99, bazen 101 yapar.
- Diğer tasarımcı osilatörü pahalı bulur, bir RC devresi kurup 25 MHz'e ayarlar. Onun yanılma payı %10 olur: Birim zamanda 100 değil, 90 ya da 110 geçiş yapar.

Böylece iki taraf arasında farklılıklar oluşur. Bir sinyal geçişiyle zamanlama yapılsa bile arada mutlaka kaymalar olabilir. Hoca bunun "hiçbir şey çalışmaz" anlamına gelmediğini, bu sorunu çözmeye yönelik mekanizmalar olduğunu söyledi.

Kaymanın etkisi aktarım hızıyla da ilgilidir. 100 kilobitle aktarırken bir şeydir, aynı hatta megabitlere çıkıldığında hassasiyet çok daha önemli hale gelir. Hız arttıkça bir bit için ayrılan süre daralır, süre daraldıkça kaymaların etkisi büyür. Arka arkaya altı, yedi ya da sekiz tane 1 (ya da 0) gönderildiğinde, iki taraf altıncı ya da yedinci 1'in nerede başlayıp nerede bittiğini karıştırabilir.

### 5.4 Başlangıç ve Bitiş Bitleri

RS-232'de hat boştayken bile sürekli negatif bir gerilim, yani 1 vardır. İlk derslerde konuştuğumuz gibi, sürekli aynı seviyede duran bir sinyalde verinin nerede başladığını bilemezsiniz. Hattan sürekli 1 basılıyorsa, bilginin başladığını gösterecek bir yapıya ihtiyaç vardır. Bu yapının mevcut durumdan farklı bir şey, yani bir değişim olması gerekir. Hat sürekli 1 olduğuna göre bu değişim 0 ile sağlanır. Bu 0, başlangıç bitidir (start bit).

Başlangıç bitinden sonra, iki tarafın önceden anlaştığı bit süresi devreye girer. RS-232 protokolü veriyi 8 bitlik parçalar halinde gönderir: Bir başlangıç biti, 8 veri biti ve sonda bir bitiş biti (stop bit). Yani 8 bit göndermek için 10 bit göndermek zorunda kalınır.

Hoca slayttaki çerçeve çizimini de anlattı: Elde gönderilecek bir veri var. Başlangıç için sinyal değiştirilir. Sonra her bit için işaret neyse o basılır (çizimde 1, 0, 0, 0, 1, 1, ... ve son bit 0), en sonda bitiş biti verilir. Eş zamansız olmaktan kastedilen, her bitin hatta kalış süresinin iki tarafça baud rate ve bit rate'e bağlı olarak önceden anlaşılmasıdır. Örneğin bu süre 2 milisaniye ise alıcı başlangıç bitini gördükten sonra her 2 milisaniyede bir hatta bakar ve o an 0 mı 1 mi olduğuna karar verir.

<!-- BELİRSİZ: Slayttaki örnek çerçevenin bit dizisinin tamamı altyazıda okunmuyor; yalnız "1, 0, 0, 0, 1, 1" ve son bitin 0 olduğu söyleniyor. -->

### 5.5 Eşlik Biti ve 8N1 Gösterimi

Saat kaymasının yanında elektromanyetik gürültü de bir etkendir. Sonuçta bir elektrik sinyali aktarılır ve çevredeki gürültü sinyali bozabilir. Bu bozulmayı yakalayabilmek için eşlik (parity) mekanizması eklenebilir. 8 bitin içindeki 1 sayısının tek (odd) ya da çift (even) olmasını denetleyen tek bir eşlik biti eklenir.

- **Çift eşlik (even parity):** Veride üç tane 1 varsa eşlik bitine bir 1 daha yazılır. Toplam 1 sayısı dört, yani çift olur.
- **Tek eşlik (odd parity):** Veride üç tane 1 varsa eşlik bitine 0 yazılır. 1 sayısı üç olarak, yani tek kalır.

Başlangıç-bitiş bitlerini ve eşliği ifade etmek için bir gösterim vardır. Slayttaki **8N1** bu gösterimdir:

- **8:** Veri biti sayısı. Başlangıç biti her seferinde zaten bir tanedir, gösterime girmez.
- **N:** Eşlik kullanılmayacağını gösterir. Çift eşlik için **E**, tek eşlik için **O** yazılır.
- **1:** Bitiş biti sayısı. Senkronizasyonu daha net sağlamak için bitiş biti zaman zaman 1, 1,5 ya da 2 bit uzunluğunda olabilir.

> **Ek bilgi (derste anlatılmadı):** Tek bir eşlik biti yalnızca tek sayıda bit hatasını yakalayabilir. İki bit birden bozulursa 1 sayısının tek/çift durumu değişmez ve hata fark edilmez. Bu yüzden eşlik en basit hata sezme yöntemidir; daha güçlü yöntemler hata denetimi konusunda görülür.

### 5.6 Eş Zamansız İletimin Ek Yükü

Hoca 8N1 için ek yükü iki şekilde hesapladı (Python ile doğrulandı):

- **Verilen:** 8 veri biti, 1 başlangıç biti, 1 bitiş biti. Toplam $8 + 2 = 10$ bit.
- **Toplam bite göre:** 10 bitin 2'si denetim bitidir: $\frac{2}{10} = \frac{1}{5} = \%20$.
- **Veriye göre:** 8 bitlik veriye 2 bit ek yük gelir: $\frac{2}{8} = \%25$.

Hoca, bitiş biti sayısı artırıldığında ya da eşlik kullanılmaya başlandığında bu ek yükün (overhead) daha da artacağını belirtti.

Eş zamansız iletimde gönderilen çerçeveler arasındaki boşluklar düzenli (uniform) değildir. Gönderici elinde ne zaman bilgi varsa o zaman gönderir. Hoca, öğrencinin baştaki sorusunda "paket" dediği şeyin burada artık bir veri çerçevesi (frame) diye adlandırılabileceğini söyledi. Her çerçevenin arasında farklı farklı boşluklar oluşur.

### 5.7 Kaymanın Birikmesi

Slayttaki örnek, kaymanın uzun bir dizi boyunca nasıl biriktiğini gösterir. Bu protokollerin ilk oluşturulduğu dönemde üretim kalitesi yüzünden sistemler arasındaki kayma ihtimali çok yüksekti. Alıcı ile gönderici arasında %5'lik bir kayma olduğunu düşünelim ve 8 bitlik bir bilgi gönderelim (Python ile doğrulandı):

- 1. bitte kayma %5'tir.
- 2. bitte %10, 3. bitte %15 olur. Her bitte %5 eklenir.
- Başlangıç biti de sayıldığında son veri biti aslında 9. bittir: $9 \times 5 = \%45$.

%45 neredeyse %50 demektir. Yani son biti kaçırma, yanlış algılama ya da hiç algılayamama ihtimali oldukça yüksektir.

> **Ders sonrası not:** Hoca önce "sekizinci bitte %45" dedi, sonra başlangıç biti de sayılınca bunun 9. bit olduğunu ekledi; $8 \times 5 = \%40$, $9 \times 5 = \%45$'tir. Alıcı her biti bit süresinin ortasında örneklerse, son veri bitinin orta noktası başlangıç kenarından 8,5 bit süresi sonradır ve birikmiş kayma $8{,}5 \times 5 = \%42{,}5$ olur. Her iki hesapta da sonuç yarım bit süresine yakındır.

Bu örneğin konuşulma sebebi şudur: Ek yükü (%20 ya da %25) azaltmak için 8 bit yerine 16, 32, 64 bitlik bloklar gönderilebilir. Fakat taraflar arasında %1, %5 gibi bir hız farkı varsa, blok uzadıkça bu fark olası hatalar olarak geri döner.

### 5.8 Eş Zamansız İletim Bugün Nerede?

Hoca, eş zamansız iletimin hâlâ bir yerlerde durduğunu, en azından eski sistem odalarında durduğunu anlattı. Çok standart ve temel bir yapı olduğu ve ayrı bir hat sağladığı için bir tür yedekleme (failover) özelliği sunar. Bazı merkezi sistemlerin (mainframe) ve disk birimlerinin hata bildirimi için ayrı dial-up modemleri vardı. Veri merkezinde bir sorun olduğunda ve normal bağlantı yokken, hata durumu normal hat yerine bu dial-up modem üzerinden dışarı bildirilebiliyordu. Teknoloji ilerledikçe bunu dial-up yerine 3G, 4G ya da başka bir yapı üzerinden yapmak daha makul hale geldi.

## 6. Eş Zamanlı (Senkron) İletim

### 6.1 Ortak Saat İşareti

Asenkron yapının alternatifi iletimi eş zamanlı yapmaktır. Hoca eş zamanlılığın nasıl sağlanabileceğini sordu. Bir öğrenci iki tarafı aynı saat döngüsüne (clock cycle) bağlamayı önerdi. Hoca bunu en temiz yollardan biri olarak kabul etti. Bir gönderici ve bir alıcı vardır, ikisinin ortak bir saat sinyaline ihtiyacı vardır. İkisinden biri (ikisi aynı anda değil) bir saat darbesi (clock pulse) üretir: örneğin her milisaniyede bir "pıt, pıt, pıt".

Eş zamanlı iletimde aktarılan verinin boyutu da büyütülür, daha büyük bit dizileri gönderilir. Asenkronda başlangıcı ve bitişi göstermek için her karakterin başına ve sonuna ek bitler konuyordu. Eş zamanlıda taraflar zaten senkron olduğu için her karaktere böyle ek bitler koymak gerekmez.

### 6.2 Saat Sinyalini Uzağa Taşımanın Sorunu

Hoca, saat sinyalini uzun bir mesafe boyunca taşımaya kalkınca karşılaşılacak temel problemin ne olduğunu sordu ve bunun önceki haftalarda konuşulduğunu hatırlattı. Sınıftan cevap gelmeyince kendisi açıkladı: Uzun mesafede ayrı bir saat sinyali büyük ihtimalle DC bileşen oluşturur. Ayrıca zayıflama (attenuation) yüzünden deformasyona uğrar. Sonuçta işe yaramaz hale gelebilir.

### 6.3 Saati Veriye Gömmek

Bunun yerine kodlamalarda uzun uzun konuştuğumuz yol kullanılır: Saat sinyali verinin içine yerleştirilir. Slaytın en altında da yazdığı gibi, Manchester veya diferansiyel Manchester kodlama tekniklerinde olduğu gibi zamanlama bilgisinin veri içine yerleştirilmesi tercih edilir. Bir öğrenci bunun için "modülasyon" dedi. Hoca modülasyonun genel bir ad olduğunu, burada diferansiyel Manchester'ın kastedildiğini söyledi.

Hocanın en basit tabiriyle yapılan şey "verinizi bir saatle kiplemek"tir. 0 ya da 1'i üretmek için kullanılan sinyal saat sinyaliyle birleştirilir. Diferansiyel Manchester'da her bitte bir geçiş olur: Bir bakarsınız negatiften pozitife, bir bakarsınız pozitiften negatife geçer. Sinyal sürekli değiştiği için alıcı saati bu geçişlerden çıkarabilir.

Özetle fiziksel katmanda eş zamanlılık iki yolla sağlanır: ayrı bir saat hattıyla ya da saati verinin içine gömerek.

### 6.4 Mantıksal Eş Zamanlılık ve Önsöz

Hoca üçüncü bir durumu da anlattı. İletim ortamı her zaman kablo olmak zorunda değildir. Hava üzerinden, Wi-Fi, ZigBee, RF gibi ortamlarda haberleşiyorsanız ve iletimin eş zamanlı olmasını istiyorsanız, mantıksal seviyede bir eş zamanlılık oluşturmanız gerekir. Örneğin Wi-Fi'de çerçevenin önüne bir önsöz (preamble) konur. Önsöz anlamlı bir bilgi taşımaz, ama bilinen bir desendir (pattern). Alıcı bu deseni görünce bir çerçevenin başladığını anlar.

**Soru:** Önsöz saat sinyalinin içine mi dahil ediliyor, yoksa asenkrondaki gibi verinin başına eklenen bir şey mi?

**Cevap:** Önsöz daha çok yönlendirilmemiş ortamlar için söylendi. Wi-Fi'de ortak kullanılan bir saat sinyali yoktur, ortamda sürekli giden bir darbe sinyali yoktur. Bir taşıyıcı sinyal vardır ve veri onun üzerinde değişiklik yapılarak gönderilir. Karşı tarafta eş zamanlılık sağlamak için her veri paketinin önüne belli bir dizi (sekans) konur. Alıcı bu diziyi aldığında bir çerçevenin başladığını anlar. Dizinin başından, ortasından ya da kenarından yakalaması bile yeterlidir.

Slaytta denetim bilgisinin "100 biti geçmez" diye yazdığını gösteren hoca bu ifadeye katılmadı.

> **Hocanın vurgusu:** "100 biti geçer, geçtiği yer var. Öyle bir sayıyı ezberlemenize gerek yok. Bence bu hatalı bir bilgi olmuş."

### 6.5 Eş Zamanlı İletimde Ek Yük: HDLC Örneği

Hoca, ilerleyen haftalarda konuşulacak veri bağı protokollerinden HDLC'nin eş zamanlı bir haberleşme protokolü olduğunu söyledi. HDLC'de önsöz yapısı olduğunu, sonsöz (postamble) olup olmadığını tam hatırlamadığını, detayına oraya gelince bakılacağını belirtti. Hocaya göre HDLC'de en başa eklenen 48 bitlik bir denetim bilgisi vardır.

Slayttaki örnek (Python ile doğrulandı):

- **Verilen:** 1000 karakterlik bir veri bloğu. Bir karakter 8 bit. Denetim bilgisi 48 bit.
- **Veri biti:** $1000 \times 8 = 8000$ bit.
- **Toplam gönderilen:** $8000 + 48 = 8048$ bit.
- **Ek yük:** $\frac{48}{8048} \approx 0{,}00596 \approx \%0{,}6$, yani binde 6 civarı.

Bu oran eş zamansız iletimdeki %20 ile karşılaştırıldığında çok küçüktür. Eş zamanlı seri iletimde bilgi hep büyük bloklar halinde aktarılır, denetim bilgisi de bu büyük bloğa bir kez eklenir.

> **Ders sonrası not:** HDLC çerçevelerinde büyük olasılıkla ayrı bir önsöz yoktur. Çerçeve başı ve sonu bayrak (flag) baytıyla, yani 01111110 ile işaretlenir. Örnekteki 48 bit büyük olasılıkla bayraklar, adres, kontrol ve FCS alanlarının toplamıdır. Ayrı bir önsöz kullanan protokol örneği Ethernet'tir: büyük olasılıkla 7 baytlık önsöz ve 1 baytlık SFD (Start Frame Delimiter) vardır.

### 6.6 Eş Zamanlı ve Eş Zamansız İletimin Karşılaştırması

Slaytta iki sütun vardı. Hoca hangisinin eş zamanlı, hangisinin eş zamansız olduğunu sordu:

| Eş zamanlı (senkron) | Eş zamansız (asenkron) |
|---|---|
| Daha etkin kullanım | Basit |
| Daha iyi hata denetimi | Ucuz |
| Daha yüksek hız | Ek bir zamanlama çabası gerektirmez |
| | Eksi: sınırlı hata denetimi |
| | Eksi: başa ve sona eklenen bitler yüzünden daha yüksek bant genişliği kaybı |

Öğrencilerden doğru cevap geldi: Sağdaki sütun eş zamansızdır.

> **Hocanın vurgusu:** Sınavlarda karşılaştırma sorularında "biri şöyle, diğeri böyle" diye yazıyorsunuz ve bu "biri" ile "diğeri" hep öyle kalıyor, ne olduğu anlaşılmıyor. Hangi özelliğin hangi yönteme ait olduğunu açıkça yazın.

## 7. DTE, DCE ve Sıfır Modem

Seri ya da paralel iletişimde, hangisi olduğu fark etmeden, DTE ve DCE kavramları vardır.

- **DTE (Data Terminal Equipment):** Veriyi üreten ya da işleyen kısımdır. Bilgisayar ile yazıcı arasındaki bağlantıyı düşünürsek ikisi de DTE'dir.
- **DCE (Data Circuit-terminating Equipment):** Bilgisayardan modeme, modemden internete giden bir bağlantıda modem DCE'dir. Temel görevi aradaki modülasyonu sağlamaktır: verinin sayısaldan sayısala, sayısaldan örneksele ya da örnekselden sayısala neyse modülasyonunu ve sonra demodülasyonunu yapmak. "Modem" adı da modülasyon-demodülasyon kelimelerinin kısaltmasıdır. Hoca, derste bir öğrencinin daha önce "modülasyon" dediğini hatırlatıp "geldik modülasyona" dedi.

> **Ders sonrası not:** Hoca açılımı "Data Circle Terminated Equipment" diye söyledi. Doğru açılım *Data Circuit-terminating Equipment*'tır; bazı kaynaklarda *Data Communications Equipment* olarak da geçer.

Bilgisayar haberleşmesinde genel yapı çoğu zaman şöyledir: İki uçta DTE'ler, onlara bağlı DCE'ler (modülasyonu sağlayan yapılar) ve arada bir ağ vardır. Eskiden bilgisayara seri ya da paralel portla bağlı cihaz, öbür tarafta telefon hattı üzerinden sayısal-örneksel çevrim yaparak gönderiyordu. Bugün DCE diyebileceğimiz cihazlar bilgisayara çoğunlukla Wi-Fi ya da Ethernet ile bağlıdır. Öbür tarafta fiber, kablo ya da ADSL modem olmasına göre, gelen bilgiyi geniş alan ağının (Wide Area Network) modülasyonuna uygun şekilde kipleyip yukarı gönderir.

Fakat bazen bilgisayarları haberleştirmek için modeme gerek yoktur. Özellikle fiziksel olarak aynı mekândaki iki bilgisayar arasında bilgi paylaşılmak isteniyorsa, aradaki ağ ve modemler kaldırılır, DTE'ler doğrudan birbirine bağlanır. Buna sıfır modem (null modem) bağlantısı denir.

DTE-DCE bağlantısı için farklı standartlar vardır. Bir kısmı hâlâ, özellikle geniş alan ağı cihazlarının bağlantılarında kullanılır:

- **EIA:** RS-232 (EIA-232), RS-422, RS-449.
- **ITU:** V.24, V.32, V.34 ve X serisi. V.24, V.32, V.32bis gibi yapılar evde kullandığımız modemlerde bulunuyordu.

Bunların konnektör tipleri ve pin dağılımları farklıdır. RS-232 için iki tarafta DB25 olabilir ya da bir taraf DB9, diğer taraf DB25 olabilir. DB25'te 25 bağlantı görünür, ama çoğu aktarım sırasında kullanılmaz. Standartta tanımlanmışlardır, fakat standart bir modemle haberleşmek için 9 pin yeter. Hoca bu durumu "tanımlanmış ama hiç kullanılmamış" diye özetledi.

## 8. Kablolama Bir Altyapı Yatırımıdır

Hoca iletim ortamına ara vermeden geçti. İletim ortamı haberleşmenin olmazsa olmaz parçalarından biridir. Fakat maliyet açısından genelde en düşük kalemdir. Bilgisayar teknolojisi, yazılım, araya konan aktif cihazlar ve onların yazılımı daha pahalıdır. Kablo kullanılıyorsa en düşük maliyet kablolama maliyetidir.

Fakat kablolama aynı zamanda bir altyapı yatırımıdır ve maliyet değil yatırım olarak görülmelidir. Yatırımın mümkün olduğunca uzun ömürlü olması, az sorun çıkarması ve sorun çıktığında telafi edilebilmesi istenir. İhtiyaç neyse o kadarlık kablo çekip işi kapatmak teknik olarak mantıklı değildir. Mantıklı olan, kablolamayı yedekli hazırlamaktır.

Hocanın örneği: A ve B noktaları arasında 100 Mbps hıza ihtiyaç var, CAT5 kablo çekilecek. Bunun için kazı yapmak, kabloyu döşemek ve kapatmak gerekir. Kabloda bir sorun çıkarsa bu işin hepsi baştan, aynı maliyetle tekrar yapılır. Oysa ilk seferde kazı yapılıp oraya iki kablo döşenirse maliyet çok artmaz, yalnız kabloya biraz daha para harcanır. Bir sorun anında hemen diğer kabloya geçilebilir.

### 8.1 Kampüs Örneği: Ayrı Güzergâh

Hoca bunun basitleştirilmiş bir hali olduğunu söyleyip Davutpaşa kampüsünden bir örnek verdi. Kampüse yaklaşık 47 kilometre fiber optik kablo döşenmişti. Kampüs ağında (campus network) bütün trafik bir omurgada (backbone) toplanır. Kampüste bu omurgadan gidilen 17 farklı nokta vardı.

Hoca bu 17 noktanın her birine tek bir hattan gidilirse ilk problemin ne olacağını sordu. Cevap: Hatlardan birinde sorun çıkabilir. Kimse kayda bakmadan, kimseye sormadan kazı yapabilir ve kablonuzu kesebilir. Hoca bunların espri değil yaşanmış olaylar olduğunu söyledi:

- Sulama borusu döşenirken veri hattının olduğu yer kazılıp parçalandı.
- Caminin elektriği bağlanırken veri hattı parçalandı.

Bu senaryolarda sorun şudur: Aynı yere bir yerine iki kablo koysanız da, orayı kazan kişi ikisini birden parçalar. Bu yüzden doğru yedekleme senaryosu şöyledir:

- A'dan B'ye en kısa yoldan bir kablo çekilir. Onu yedeklemek için aynı yoldan bir kablo daha çekilir.
- A'dan B'ye bir de dolanarak, ayrı bir güzergâhtan gidilir. Bu yoldan da iki kablo çekilir.
- Sonuçta A'dan B'ye dört kez gidilmiş olur.

Bir bağlantıda sorun olursa aynı yoldaki diğer kabloya, orada da sorun olursa öbür güzergâha, orada da sorun olursa oradaki diğer kabloya geçilir. Dayanıklılık artar, hata anında çökme (fail) ihtimali düşer.

### 8.2 Bağlantıları Birlikte Kullanmak

Hoca bunun boş bir yatırım olmadığını da gösterdi. Uçlarda yeterli arayüz (interface) varsa, A'daki omurga anahtarının (backbone switch) dört arayüzü ile B'deki dağıtım anahtarının dört arayüzü bu dört hatta bağlanabilir. Bugünkü cihazlar bu bağlantıların mantıksal olarak bir arada kullanılmasına izin verir (Python ile doğrulandı):

- Her bağlantı 10 Gbps ise toplam $4 \times 10 = 40$ Gbps kullanılabilir.
- Bağlantılardan biri koparsa $3 \times 10 = 30$ Gbps'e inilir ve çalışma devam eder.
- Başta o nokta için 10 Gbps yetiyorsa, performans düşüşü (degradation) hissedilmez bile.

Sorun olduğunda bunu önceden görürsünüz ve düzeltmek için zamanınız olur. Bir anda bütün sistemi elinize almak zorunda kalmazsınız. Hocaya göre altyapı yatırımında yalnız "neye ihtiyacım var" diye bakılmamalı; sistemin nasıl genişleyeceğine, nasıl yedekleneceğine ve sorun anında nasıl davranmasını istediğinize de bakılmalıdır.

> **Ek bilgi (derste anlatılmadı):** Birden çok fiziksel bağlantıyı tek bir mantıksal bağlantı gibi kullanmaya bağlantı birleştirme (link aggregation) denir. Bunun standart protokolü büyük olasılıkla IEEE 802.3ad (sonradan 802.1AX) ile tanımlanan LACP'dir (Link Aggregation Control Protocol).

## 9. Yönlendirilmiş ve Yönlendirilmemiş Ortam

İletim ortamı iki çeşittir:

- **Yönlendirilmiş ortam (guided media):** Elle tutulur, gözle görülür ortamdır.
- **Yönlendirilmemiş ortam (unguided media):** Pek göremediğimiz yapılardır. Kızılötesi (infrared), radyo frekansı (radio frequency), mikrodalga gibi sinyaller üzerinden haberleşilir. Hoca burada önce "RF ve radyo" dediğini, aslında "infrared" demek istediğini düzeltti.

Her iki tarafta da standartlara ihtiyaç vardır. Kablolama tarafında ISO'nun, EIA'nın, CENELEC'in ve başka kuruluşların standartları vardır. Hoca bunların hepsini ezbere bilmenin ya da takip etmenin mümkün olmadığını, kendisinin de hepsini takip edemediğini söyledi. Derste günlük hayatta kullanılan, bilinen net standartlar üzerinde durulacaktı.

## 10. Eş Eksenli (Koaksiyel) Kablo

Koaksiyel kabloyu bugün daha çok uydu alıcılarında görürsünüz. Çanak anten ile uydu alıcısı arasındaki kablo koaksiyeldir.

- **75 Ω:** Uydu alıcısında kullanılan.
- **50 Ω:** Sayısal haberleşmede kullanılan.

Koaksiyel kablonun güzelliklerinden biri, bağlantı sisteminin nispeten kolay olmasıdır, çünkü tek telli bir yapıdır. Hoca bu kolaylığın ortama göre değişebileceğini de ekledi. Sunduğu topoloji yol (bus) topolojisidir. Bu topolojide aynı anda birden fazla istasyon iletim yapamaz, ama herhangi bir istasyon herhangi bir anda iletim yapabilir. Fiziksel katmanın sunduğu bu özelliği kullanabilir ya da kullanmayabilirsiniz. Örneğin uydu alıcısında iletim yalnız antenden alıcıya doğrudur, tersi yoktur.

Koaksiyelin kullanıldığı diğer alan Ethernet'tir. Ethernet için RG-8 ve RG-58 olmak üzere iki tip vardır. Adları kablonun kalın ya da ince olmasından gelir.

### 10.1 Kalın Ethernet (Thick Ethernet)

İlk Ethernet yapısı kalın Ethernet üzerine kuruluydu. RG-8 kablonun standart adı 10BASE5'tir. Hoca bunun 10 MHz'lik bir aktarım sağladığını söyledi.

> **Ders sonrası not:** Hoca "10 MHz" dedi. 10BASE5'teki 10, saniyede 10 megabit (10 Mbps) veri hızını gösterir.

Yol topolojisinde her cihaz bir şekilde bu ana kabloya "daldırılır". Kalın Ethernet kablolarının genel rengi sarıdır; data için kullanıldığı ayırt edilsin, kablolama sırasında yanlış kabloya işlem yapılmasın diye böyle başlanmıştır. Sarı kablonun üzerine bakarsanız her yerde diş izleri görürsünüz. Bağlantı aparatı kablonun etrafına geçirilir, kablo sıkıştırılır ve aparatın dişleri kabloya batar. Bu yüzden bu aparata vampir uç (vampire tap) denir.

Aparatın diğer ucunda, DTE-DCE arasındakine benzer, iki ucu da 15 pinli konnektörlü bir kablo vardır. Bu bağlantı arayüzüne AUI (Attachment Unit Interface) denir. Kalın Ethernet'te:

- Bir segmente bağlanabilecek en fazla bilgisayar sayısı 100'dür.
- Segmentin uzayabileceği en fazla uzunluk 500 metredir.
- Omurganın iki ucuna 50 Ω'luk sonlandırma dirençleri bağlanır.

### 10.2 İnce Ethernet (Thin Ethernet)

Kalın Ethernet'ten sonra ince Ethernet gelir (RG-58, 10BASE2). Kablo daha incedir: Ortada tek bir bakır tel, etrafında plastik yalıtkan, onun etrafında kılıf (shield), en dışta plastik kaplama vardır. Yine yol topolojisi kullanılır, Ethernet'te bir değişiklik yoktur. Fakat kabloların ucuna BNC bağlantı noktaları konur. Ana kabloya bir PC bağlamak istediğinizde T konnektör kullanırsınız: Kablo devam eder, araya T konnektör yerleştirilir, T konnektörün içe bakan kalın tarafından bir kabloyla PC'ye gidilir.

> **Ders sonrası not:** İnce Ethernet'te (10BASE2) segment başına sınır büyük olasılıkla 185 m ve 30 cihazdır.

Hoca, bundan sonra anahtarlamalı Ethernet (Switched Ethernet) ve Fast Ethernet'in geleceğini, ama bunların farkının doğrudan fiziksel değil, üst katmanlarda (mantıksal bağ denetimi, Logical Link Control) da olduğunu söyledi. Şu an yalnız iletim ortamı, yani kablolar konuşuluyordu. Fakat üst teknolojide değişim olunca alt tarafa da yansır: Burgulu çift kablolar kullanılmaya başlanır.

## 11. Burgulu Çift (Twisted Pair) Kablo

### 11.1 Burgunun Amacı

Burgulu çift kabloda tek bir damar yoktur, birden fazla damar vardır ve bu damarlar kendi içinde burgu halinde ilerler. Burgu sayısı, çiftlerin nasıl seçildiği, çiftler arasındaki yalıtım gibi özelliklere göre kablolara farklı adlar verilir.

Hoca kabloları burmanın temel amacının ne olduğunu sordu ve şöyle açıkladı: İçinde iki tel olan bir kablo düşünün, biri gönderme biri alma için olsun. Teller düz bırakılırsa dış ortam gürültüsü (noise) hiçbir zaman düzgün dağılmaz. Gürültü kaynağının yeri, şiddeti ve kablodaki sinyale bağlı olarak etkisi tellere farklı biner. Bu yüzden iki derdimiz vardır:

- Gürültünün etkisini azaltmak.
- Gürültüyü mümkün olduğunca düzgün dağılmış (uniform) hale getirmek.

Bunu kabloları burarak sağlarız. Burgu, elektromanyetik etkinin iki tele benzer şekilde yansımasını sağlar. Burulmamış tellerde birine 2 birim, diğerine 3 ya da 5 birim etki gelebilecekken, burulmuş tellerde bu etki mümkün olduğunca eşit olur.

> **Ders sonrası not:** Burgunun asıl yararı şuradan gelir: Gürültü iki tele eşit bindiğinde alıcı iki tel arasındaki farkı ölçer (differential signaling). Böylece iki tele ortak gelen gürültü birbirini götürür.

### 11.2 Dört Çift ve Fast Ethernet

Ethernet'te kullanılan burgulu kablolarda dört çift, yani sekiz tel vardır. Hoca dört çift olmasının temel nedeninin tellerin bir kısmının alma, bir kısmının gönderme yönünde kullanılabilmesi olduğunu söyledi; ayrıntının Switched Ethernet ve Fast Ethernet konuşulurken verileceğini belirtti.

Fast Ethernet'e geçerken tasarımcılar sistemi hızlandırmak için iki seçenek düşünmüşlerdi: Ethernet fiziksel katmanını yeniden tasarlamak ya da mevcut yapının çalışma hızını artırmak. Uzun tartışmalardan sonra geriye doğru uyumluluk (backward compatibility) da olsun, yeni bir şey yaparsak çıkacak açıklarla uğraşmayalım diyerek doğrudan hızlandırmayı seçtiler. Bu yüzden hem CAT3 hem CAT5 seçeneği ortaya konmuş, hangisini istersen onu kullan denmiştir.

> **Ders sonrası not:** Hoca tarih için "1992 ya da 95" dedi. Fast Ethernet standardı (IEEE 802.3u) büyük olasılıkla 1995'te yayımlandı. Ayrıca 10BASE-T ve 100BASE-TX dört çiftten büyük olasılıkla yalnızca ikisini kullanır (bir gönderme, bir alma); 1000BASE-T ise dört çiftin hepsini aynı anda iki yönde kullanır.

### 11.3 Tellerin İç Yapısı ve Deri Etkisi

Kablonun içinde 8 ayrı tel vardır ve her biri plastik bir kılıfın içindedir. Teller iki türlü olabilir:

- Tek parça kalın bir tel (tek damar, solid).
- Birden fazla ince telin bir araya getirilmesiyle oluşan çok parçalı tel (çok damar, stranded).

Çok parçalı tel, kablonun esnekliği ve darbelere dayanımı açısından avantaj sağlar. Fakat hocaya göre çoğu zaman deri etkisi (skin effect) denen durum yüzünden sinyal zayıflaması daha fazla hissedilir. Hocanın açıklaması: Aktarılan veri dış yüzey ile kablonun merkezi arasında gider. Çok damarlı kabloda tek bir damarı oluşturan parçalar çok küçük olduğu için sinyal çok daha hızlı sönümlenebilir.

> **Ders sonrası not:** Deri etkisi, yüksek frekansta akımın iletkenin dış yüzeyine yakın akması demektir. Çok telli kablonun zayıflamasının daha yüksek olmasının sebebi büyük olasılıkla teller arası boşluklar ve yüzey düzensizlikleridir. Bu yüzden kabinlerdeki kısa ara kablolar (patch cord) çok telli, binadaki uzun yatay kablolar tek telli yapılır.

### 11.4 Renk Kodları

Dört çiftin her birine farklı bir renk verilir, ama çiftin iki teli birbiriyle ilişkili kalsın diye benzer renkler kullanılır:

- Mavi ve mavi-beyaz.
- Turuncu ve turuncu-beyaz.
- Yeşil ve yeşil-beyaz.
- Kahverengi ve kahverengi-beyaz.

Hoca, bilardo toplarında olduğu gibi beyazlı karışık renklere halk arasında "pijamalı" dendiğini söyledi.

### 11.5 UTP, STP ve FTP

Burgulu kablonun çok çeşidi vardır. Slaytta üç temel çeşit gösterildi:

- **UTP (Unshielded Twisted Pair):** Kılıfsız burgulu çift.
- **STP (Shielded Twisted Pair):** Kılıflı burgulu çift. Slayttaki resimde siyah dış yüzeyin içinde gri kalın bir katman görülür; bu, çiftlerin dışındaki kılıftır (shield). Ayrıca her çifte de ayrı bir kılıf konabilir. Kılıfın hedefi kablonun dayanımını artırmak, başına bir şey gelmesini engellemektir.
- **FTP / ScTP (Foiled / Screened Twisted Pair):** Elektromanyetik gürültüyü azaltmak için alüminyum folyo ile kaplanmış yapı.

Folyonun ve kılıfın nerede olduğuna göre (her çiftin içinde, çiftlerin dışında, ikisinde birden) bu kombinasyonları anlatan farklı kablo adları vardır.

Günlük hayatta ve çoğu ofis ortamında UTP kullanılır. Hoca, çalışma odalarında sandalyeyle kablonun üzerinden iki kez geçince orasının burasının kopmaya başladığını, kablonun çekmemeye başladığını ve yeni kablo istendiğini anlattı. Çünkü UTP hiçbir şeye karşı doğru düzgün korunmaz.

### 11.6 Konnektörler ve Dizilim Standartları

İnce Ethernet'te BNC vardı. Burgulu kabloyu bilgisayara bağlamak için de bir konnektör gerekir: RJ45. Telefonda kullanılan RJ11 dörtlü olur ve genelde ikisi kullanılır. RJ45 onun sekizli, biraz daha yassı ve geniş versiyonudur.

Bağlantının nasıl yapılacağına dair iki versiyon vardır: T568A ve T568B. Bunlar kablonun ucunda turuncunun, mavinin, mavi-beyazın, yeşilin, yeşil-beyazın hangi pine gideceğini belirler. Hoca iki tarafın aynı olması gerektiğini söyledi: Bir taraf T568A ile yapıldıysa diğeri de T568A ile yapılmalıdır, ki iki bilgisayar kendi arasında temiz temiz konuşabilsin. Eskiden çok nadiren, T568A ya da T568B ile yapılan kablolamayı bir cihaza taktığınızda çalışmaması gibi durumlar olabiliyordu; hoca bunu bizzat yaşadığını söyledi. Bugün o kadar ucuz sistemler kalmadığı için cihazlar uyumludur.

> **Ders sonrası not:** İki ucu aynı dizilimle yapılan kabloya düz kablo (straight-through) denir ve bilgisayar-anahtar (switch) bağlantısında kullanılır. İki bilgisayarı doğrudan bağlamak için klasik olarak bir uç T568A, diğer uç T568B yapılır; buna çapraz kablo (crossover) denir. Günümüz cihazlarının çoğunda Auto-MDIX olduğu için düz kablo da çalışır.

### 11.7 Kategoriler

Burgulu kablolar kategori (CAT) adlarıyla anılır. Kategori belirlenirken tek ölçüt kablo üzerinde taşınan sinyalin frekansı değildir. Kategori kablonun birden fazla özelliğini birlikte belirtir, örneğin en büyük uzunluğu.

Slayttaki kategori tablosuna göre:

- CAT1, CAT2, CAT3 ses ve veri için kullanılır; telefon, token ring gibi yerlerde kullanılmıştır.
- CAT3'ten CAT5'e geçerken MHz değerleri belirgin şekilde yükselir.
- Bugün bakır olarak genelde CAT5, CAT5e ve CAT6 kullanılır. Hoca CAT6A'nın bile ortada pek olmadığını söyledi.
- Hoca CAT5e için 100 değil 125 MHz konuşulduğunu söyledi.
- CAT5, CAT5e, CAT6, CAT6A'nın hepsi RJ45 kullanır. CAT7'den itibaren konnektör de değişir.

> **Ders sonrası not:** CAT5 ve CAT5e büyük olasılıkla 100 MHz'e kadar tanımlıdır; hocanın CAT5e için verdiği 125 değeri büyük olasılıkla 1000BASE-T'nin her çiftteki sembol hızıdır (125 Mbaud). CAT6 büyük olasılıkla 250 MHz, CAT6A 500 MHz, CAT7 600 MHz'tir. Hocanın bir yerde andığı "CAT6E" resmi bir kategori değildir, bir pazarlama adıdır.

### 11.8 Çapraz Girişim

Kablo üzerinde burgulu çiftler vardır ve bunlar RJ45'e çakılıp bilgisayara bağlanır. Konnektörde pinler yan yana sıra sıra durur. Kablo boyunca ve bağlantı noktasında çiftler arasında çapraz girişim (crosstalk) oluşabilir. Farklı türleri vardır:

- **NEXT (yakın uç çapraz girişim, Near-End Crosstalk):** Yerel uçta, bir çiftin gönderme çifti ile diğer çiftler arasındaki girişim. Slayttaki renkli grafikte yeşille işaretliydi.
- **ELFEXT (eş düzey uzak uç çapraz girişim):** Uzaktaki çiftlerin bu çifte etkisi.
- **PSNEXT (güç toplamlı yakın uç çapraz girişim, Power Sum NEXT).**

Hocaya göre temelde üç problem vardır: yerel olarak çiftler arasındaki girişim, uzaktaki çiftlerin etkisi ve aktarılan sinyalin zayıflaması (attenuation). Bu durumların tespiti için kullanılan ölçüm değerleri de vardır. Hoca bunların çok karışık olduğunu ve standartlara bağlı bir ton veri içerdiğini söyleyerek ayrıntısına girmedi.

<!-- BELİRSİZ: Slayttaki çapraz girişim grafiği ve kategori tablosundaki değerlerin tamamı altyazıda okunmuyor. -->

## 12. Fiber Optik Kablo

### 12.1 Işık Taşımak

Kablo üzerinde illa elektrik sinyali taşımak zorunda değiliz. Bunun yerine ışık taşıyabiliriz. Işığı taşımak için camın maddesi olan silikadan yapılmış kablolar kullanılır.

Hoca, elektrik sinyali taşınmadığına göre neyden etkilenmeyeceğimizi sordu. Bir öğrenci "sinyal" dedi. Hoca bunu düzeltti: Doğru cevap elektromanyetik gürültüdür. Ortamdan aktarılan şey elektrik değil ışık olduğu için elektromanyetik gürültüden etkilenme söz konusu değildir.

### 12.2 Sonlandırma Zorluğu ve Güvenlik

Hoca fiberin bir artısının daha olduğunu, ama bunun aslında amaçlanmış değil, olayın doğası gereği ortaya çıkmış bir artı olduğunu söyledi. Bazen santralin önüne arka kapağı açılan küçük bir panel van yanaşır ve içindeki teknisyen bir demet kabloyu tek tek birbirine bağlamaya uğraşır. Fiber optik kablonun sonlandırılması (termination) kolay değildir; uçlar bir tür kaynakla birleştirilir. Bu yüzden biri bilgisayarınıza gelen fiber kabloyu makasla kesip araya bir konnektör takarak kendi bilgisayarına çekip ağı dinleyemez. Bu, iletim ortamında bir güvenlik sağlar.

Kalın Ethernet'i hatırlayın: Adı zaten vampir dişidir, ana kabloya doğrudan bir cihaz bağlanır. İnce Ethernet'te kabloyu kesip BNC konnektörlerle bilgisayarınızı bağlarsınız ve bir anda herkesin eriştiği ortama siz de erişirsiniz. Fiberin böyle bir zaafı yoktur.

> **Ders sonrası not:** Fiber bakıra göre dinlemeye çok daha dayanıklıdır, ama dinlemek imkânsız değildir. Kabloyu bükerek dışarı sızan ışıkla dinleme (bend tapping) yöntemleri vardır. Hassas veride şifreleme yine gerekir.

### 12.3 Karanlık Fiber

Hoca fiberle ilgili sık duyulan bir terimi açıkladı: karanlık fiber (dark fiber). Altyapı yatırımı yapanlar bunu geniş geniş yaparlar. İnternet servis sağlayıcıları (ISP) da öyle yapar: Bir mahalleye tek bir fiber damar çekmez, kapasite planına ve yedeklilik ihtiyacına göre 5, 10, 100 damar çeker. Fiberden ışık aktarıldığı için, bir şey aktarılmadığında orada ışık da olmaz, orası karanlıktır. Çekilmiş ama kullanılmayan fibere bu yüzden karanlık fiber denir.

### 12.4 Fiber Kablonun Yapısı

Tek bir fiber damarın yapısı içten dışa şöyledir:

- **Çekirdek (core):** Ortadaki ışığın taşındığı kısım.
- **Kılıf (cladding):** Çekirdeğin etrafındaki katman.
- **Birincil tampon (primary buffer).**
- **İkincil tampon (secondary buffer).**

Örneğin bir veri merkezinde cihazlar arası bağlantıda konnektörün ucunda bu ince kabloyu görürsünüz. Fakat iki cihazın haberleşebilmesi için biri gönderme, biri alma yönünde çalışan iki damar gerekir. Bu yüzden iki çekirdekli kablolar kullanılır.

Dış ortam fiberi çoğu zaman tek damarlı olmaz. A'dan B'ye iki çekirdekli 10 kablo çekmek yerine 8, 12, 16 ya da 24 çekirdekli tek bir kablo çekilir. İçinde, ikincil tamponu olmadan birincil tamponlu damarlar büyük bir kablonun içine dizilir; dıştan tek bir kablo gibi görünür. Dış ortam kablosunda kazma ya da kürek darbesine, kemirgen ısırmasına karşı bir metal zırh (armor) bulunur. Üstünde de dış etkilere ve korozyona karşı bir plastik kaplama daha olur.

### 12.5 Tek Modlu ve Çok Modlu Fiber

Fiber optik kablonun temelde iki çeşidi vardır: tek modlu (single-mode) ve çok modlu (multimode). Hoca neden iki çeşit olduğunu esprili bir dille "her zamanki gibi temel motivasyonumuz" diyerek maliyete bağladı: Biri daha pahalı, biri daha ucuzdur. Ucuz olandan en fazla fayda sağlanacak şekilde yararlanılır, pahalı olan kaçınılamayan yerde kullanılır.

- **Tek modlu fiber:** Kablonun içinde tek, düz bir hat şeklinde gidebilen bir ışın aktarılması hedeflenir. Bir uçtan verilen giriş darbesi (input pulse), çıkışta da düzgün ve tertemiz görünür.
- **Çok modlu fiber:** Giriş darbesi içeride farklı şekillerde kırılır ve bu bir bozulmaya yol açar. Kırılmanın nasıl ve ne sıklıkta olduğuna göre alt türleri vardır. En temel sınıflandırma basamaklı kırılma indisli (step-index) ve dereceli kırılma indisli (graded-index) fiberdir.

### 12.6 Step-Index ve Graded-Index

Step-index fiberde yansıma açıları keskindir. Graded-index fiberde ise ışık daha yumuşak açılarla kırılır. Bunun iki güzelliği vardır. Birincisi sinyal karşı tarafa daha kuvvetli ulaşır. İkincisi şudur:

- Merkezde ilerleyen ışın daha yoğun bir ortamda ilerler. Bu yüzden biraz daha yavaştır, ama daha kısa yol alır.
- Kenarlara doğru saçılıp kırılarak ilerleyen ışın daha az yoğun bir ortamda ilerler. Daha hızlıdır, ama daha uzun yol alır.
- Sonuçta ışınlar uç noktaya neredeyse aynı anda varır.

Böylece çıkışta elde edilen darbe daha anlaşılır olur. Bu yüzden graded-index, step-index'e göre bir adım öndedir ve çok modlu fiber denince çoğunlukla graded-index yapılar kullanılır.

### 12.7 Işık Kaynakları ve Alıcı

Fiberde iki tür ışık kaynağı kullanılır:

- **LED (Light Emitting Diode):** Hocanın deyişiyle "ucuz adamın çözümü". Odaklı bir ışık üretmez. Tek modlu değil, çok modlu fiber için kullanılır.
- **Lazer diyot (Injection Laser Diode, ILD):** Kırılmadan dümdüz gidebilen bir ışık üretir. Hoca önce "ışık hüzmesi" dedi, sonra "ışık üretiyorsunuz" diye düzeltti. Tek modlu fiberde çoğu zaman lazer kullanılır.

Karşı tarafta ışığı algılayıp elektriksel sinyale çevirecek bir şey gerekir. Buna fotodiyot (photodiode) denir. Üzerine ışık düştüğünde arka tarafta bir elektrik sinyali oluşturur.

## 13. Bakır ve Fiber Karşılaştırması

Hoca bakır ve fiberi karşılaştırırken önce fiberin avantajlarını saydı:

- **Zayıflama:** Sinyal zayıflaması açısından fiberin çok daha avantajlı olduğu nettir.
- **Elektromanyetik girişim:** Aktarılan şey elektrik sinyali olmadığı için elektromanyetik girişime karşı dayanıklılığı yüksektir.
- **Geniş frekans bandı:** Işığın farklı dalga boyları kullanılabilir. Böylece birbirinden tamamen farklı kanallar üzerinden, çok kanallı iletim yapılabilir.
- **Elektriksel yalıtım:** Fibere bir elektrik kablosu değse, altından ya da yanından yüksek gerilim hattı bile geçse, çapraz girişim ya da iletkenlik gibi bir sorun olmaz.
- **Daha az yer kaplar (space saving):** Fiber kablo bir CAT5 kablodan çok daha incedir; hocanın deyişiyle daha hassas, daha ince, daha zariftir.
- **Güvenlik:** Daha önce anlatıldığı gibi kesip araya girerek dinlemek mümkün değildir, bağlantı oluşturmak zordur.

> **Ek bilgi (derste anlatılmadı):** Fiberde farklı dalga boylarını aynı anda ayrı kanallar olarak kullanmanın adı dalga boyu bölmeli çoğullamadır (Wavelength-Division Multiplexing, WDM). Bu, frekans bölmeli çoğullamanın ışıktaki karşılığıdır.

Fakat buradaki anahtar kelimelerden biri "hassas"tır. Fiberin dezavantajları da bundan gelir:

- **Fiziksel hassasiyet:** Ethernet kablosunun üzerinden sandalye tekerleğiyle geçince yamulur, temassızlık yapmaya başlar ama bir şekilde çalışmaya devam eder. Bunun yarısını fiber kabloya yaparsanız, örneğin üzerine basar ya da oturursanız, o kabloyu bir daha kullanamazsınız. Kırılma, yamulma ya da konnektörle arasındaki ufacık bir pürüz yeterlidir.
- **Hizalama:** Kablonun ucundaki konnektörler aktif cihazlara girer. Bir damar bir cihazın lazerine (ya da LED'ine) bağlanır, öbür uçta karşı cihazın fotodiyoduna gider. Diğer damarda bunun tersi yapılır. Gönderilen ışığın karşıda net algılanabilmesi için uçların çok iyi hizalanmış (align), merkezde tam oturuyor olması gerekir. Bu yüzden konnektör elde kolayca yapılamaz.
- **Temas sorunları:** Soket tam oturtulmazsa bağlantı kurulmayabilir.
- **Kirlenmeye hassasiyet:** Toz, çizik, yağ, kir ve pasa karşı hem kablonun ucundaki konnektör hem de cihaz tarafı hassastır. Ufacık bir toz tanesi yüzünden bağlantı kurulamayabilir ya da yüksek hata oranıyla çalışılabilir.

### 13.1 Lazer Güvenliği

Hoca dersi bir güvenlik uyarısıyla bitirdi. Özellikle lazer kullanan noktalarda, örneğin tek modlu fiberde, yapılan temel hatalardan biri şudur: Aktif cihaza bağlıyken ikili konnektörü elinize alıp hangisinden ışık geldiğini gözünüzle bakarak kontrol etmek.

> **Hocanın vurgusu:** Orada kullanılan lazer ışını doğrudan göze zararlıdır. Doğru yol ortamı karartmak, sonra kabloyu yere doğru tutup ışığın görünüp görünmediğine bakmaktır.

## Örnek Sorular

Bu derste ekran görüntüsü yoktur. Aşağıdaki sorular hocanın derste sözlü sorduğu sorulardır.

**1. (derste sözlü, 00:17:02)** Paralel iletimin avantajı nedir? Kötü tarafı nedir?

> **Çözüm (derste verildi):** Avantajı hızdır; tek seferde bir değil $n$ bit aktarıldığı için birim zamanda aktarılan bit miktarı artar. Kötü tarafı maliyettir; her bit için ayrı tel ve kontrol işaretleri için ek teller gerekir. Hoca sonra ikinci bir dezavantaj olarak mesafe kısıtını ekledi.

**2. (derste sözlü, 00:34:45)** Eş zamansız iletim yaklaşımının sıkıntısı nedir?

> **Çözüm (derste verildi):** Bekleme süresi değil; asıl sorun gönderici ve alıcının saatlerinin birbirinden bağımsız olmasıdır. Ortak bir zamanlama işareti yoktur, saatler arasında kayma (drift) oluşur. Hız arttıkça bit süresi kısalır ve kaymanın etkisi büyür.

**3. (derste sözlü, 00:46:18)** RS-232'de hat boştayken sürekli 1 basılıyorsa, verinin başladığını gösterecek değişim neyle sağlanır?

> **Çözüm (derste verildi):** 0 ile sağlanır. Bu 0, başlangıç bitidir (start bit).

**4. (derste sözlü, 00:57:15)** Eş zamanlılığı nasıl sağlayabiliriz?

> **Çözüm (derste verildi):** Bir yol, iki tarafı ikisinden birinin ürettiği ortak bir saat sinyaline bağlamaktır. Uzun mesafede bunun yerine saat bilgisi veriye gömülür (Manchester, diferansiyel Manchester). Kablosuz ortamlarda çerçevenin önüne bir önsöz (preamble) konarak mantıksal eş zamanlılık sağlanır.

**5. (derste sözlü, 00:58:38)** Saat sinyalini uzun mesafe taşımaya kalktığınızda başınıza gelecek temel problem nedir?

> **Çözüm (derste verildi):** Sınıftan cevap gelmedi, hoca sonra açıkladı: Saat sinyali DC bileşen oluşturur ve zayıflama yüzünden deformasyona uğrar.

**6. (derste sözlü, 01:09:31)** Slayttaki iki sütundan hangisi eş zamanlı, hangisi eş zamansız iletime aittir? Bir sütun: daha etkin kullanım, daha iyi hata denetimi, daha yüksek hız. Diğer sütun: basit, ucuz, ek zamanlama çabası yok; ama sınırlı hata denetimi ve başa/sona eklenen bitler yüzünden bant genişliği kaybı.

> **Çözüm (derste verildi):** İlk sütun eş zamanlı, ikinci (sağdaki) sütun eş zamansız iletimdir.

**7. (derste sözlü, 01:11:22)** DCE'nin temel görevi nedir?

> **Çözüm (derste verildi):** Aradaki modülasyonu ve demodülasyonu sağlamaktır. Modem adı da buradan gelir.

**8. (derste sözlü, 01:20:19)** Omurgadan 17 farklı noktanın her birine tek bir hattan gidilirse karşılaşılacak ilk problem nedir?

> **Çözüm (derste verildi):** Hatlardan birinde sorun çıkabilir; örneğin habersiz yapılan bir kazıda kablo kesilebilir. Yedek gerekir, ama yedek kablo aynı kanaldan değil ayrı bir güzergâhtan geçmelidir.

**9. (derste sözlü, 01:33:54)** Kabloları burmanın temel amacı nedir?

> **Çözüm (derste verildi):** Dış gürültünün etkisini azaltmak ve gürültünün iki tele benzer şekilde, düzgün dağılmış (uniform) olarak etki etmesini sağlamak.

**10. (derste sözlü, 01:49:26)** Fiberde elektrik sinyali taşınmadığına göre fiber neyden etkilenmez?

> **Çözüm (derste verildi):** Elektromanyetik gürültüden. Bir öğrencinin "sinyal" cevabı yanlıştı; ortamdan aktarılan şey ışıktır.

## Dersin Toparlaması

Bu derste sayısal verinin fiziksel katmanda nasıl iletildiği iki eksende incelendi. Birinci eksen paralel ve seri iletimdi: Paralel iletim hızlıdır ama çok tel gerektirdiği için pahalıdır ve mesafesi kısadır; seri iletim tek hat üzerinden bitleri peş peşe gönderir. İkinci eksen seri iletimin eş zamanlılık türüydü. Eş zamansız iletimde taraflar yalnız bit süresinde anlaşır, her karakter başlangıç ve bitiş bitleriyle çerçevelenir; bu basit ve ucuzdur ama 8N1'de %20 ek yük getirir ve bağımsız saatler arasındaki kayma uzun bloklarda hataya yol açar. Eş zamanlı iletimde saat ayrı bir hatla ya da veriye gömülerek taşınır, kablosuz ortamlarda önsözle sağlanır; büyük bloklar halinde gönderildiği için ek yük binde 6 düzeyine iner. DTE, DCE ve sıfır modem kavramları da bu bağlamda görüldü.

Dersin ikinci yarısında iletim ortamına geçildi. Kablolamanın bir altyapı yatırımı olduğu, ayrı güzergâhlı yedekli kablolamanın ve bağlantıların birlikte kullanılmasının önemi anlatıldı. Ardından yönlendirilmiş ortamlar sırayla incelendi: koaksiyel kablo ve ilk Ethernet türleri (kalın ve ince Ethernet), burgulu çift kablo (burgunun amacı, UTP/STP/FTP, RJ45, T568A/B, kategoriler, çapraz girişim) ve fiber optik kablo (yapısı, tek ve çok modlu fiber, step-index ve graded-index, ışık kaynakları, bakırla karşılaştırma). Hoca bir sonraki aşamada yönlendirilmemiş (kablosuz) ortamlara geçileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
