# Ders 6 Genişletilmiş Notu: Laboratuvar 0: Proteus ile Devre Simülasyonu, Ölçüm ve Osiloskop

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvar oturumu ve konular
- 2. Proteus 8 demo sürümü ve kurulum
- 3. Yeni proje, eleman seçimi ve bağlantı
- 4. Simülasyonu çalıştırma ve hata mesajları
- 5. Voltmetre ve ampermetre
- 6. Toprak, gerilim ve akım probları
- 7. Örnek DC devre analizi
- 8. Zamana bağlı grafik (analog graph)
- 9. Sinüs kaynak, gerilim izleyici ve osiloskop
- 10. Breadboard ve Fritzing
- 11. Projelerde entegre devreler
- 12. Ders kapsamı üzerine soru
- Örnek Sorular

## 1. Laboratuvar oturumu ve konular

Bu kayıt, haftalık teori dersinden ayrı yapılan laboratuvar tanıtım oturumudur. Slayt kapağında "Elektronik Devreler 2021 Bahar – LAB 0" yazar (ekrandan, 00:10:00). Oturumu laboratuvardan sorumlu asistan yürütür. Laboratuvarlar çevrim içi yapıldığı için devreler fiziksel olarak değil, Proteus simülasyon programında kurulur.

Normal bir laboratuvarda devre kurulur, kaynak sinyali fonksiyon üretecinden (function generator) verilir, devrenin tepkisi çıkıştan osiloskopla gözlenir ve akım-gerilim değerleri dijital multimetreyle (DMM) ölçülür. Çoğu zaman kaynağı adım adım değiştirip akım ve gerilimi bir tabloya kaydetmek, sonra bunun grafiğini çizmek istenir. Çevrim içi laboratuvarda aynı işler tamamen sanal ortamda yapılır.

Laboratuvar konuları sırasıyla şöyledir:

- Diyot
- Op-amp (işlemsel yükselteç)
- BJT (bipolar jonksiyonlu transistör)
- CMOS transistör; son laboratuvarın lojik kapılarla ilgili olacağı tahmin edilmektedir.

Her konunun teorisi önce derste işlenir, laboratuvarı ondan sonraki hafta ya da haftalarda yapılır.

## 2. Proteus 8 demo sürümü ve kurulum

Proteus'un üreticisinin sitesinden ücretsiz demo sürümü indirilir. Ekranda sürümün sınırlamaları şöyle listelenir (ekrandan, 00:20:00):

- Süre sınırı yoktur.
- Yazılımın her yönünü denemek için kapsamlı örnek tasarımlar vardır.
- Örnek tasarımlarda değerlendirme amacıyla kendi yazılımınızı çalıştırabilirsiniz.
- Şema ve baskı devre çizimleri yalnız örnek tasarımlardan yazdırılabilir.
- Çalışma kaydedilemez.
- Kendi mikrodenetleyici tasarımlarınız simüle edilemez.

Asistan, mikrodenetleyici kısıtının elektronik laboratuvarını etkilemediğini, asıl önemli kısıtın kayıt yapılamaması olduğunu vurgular. Proje açılıp devre kurulur, ama kaydedilemez; program kapatılınca proje kaybolur. Bu yüzden elektrik ya da bağlantı kesilmesine karşı dikkatli olmak, mümkünse dizüstü bilgisayarda çalışmak önerilir. Kurulum sıradandır: kurulum dosyası çalıştırılır, lisans kabul edilir, "Typical" kurulum seçilir.

**Soru:** Mac kullananlar Proteus yerine başka bir program kullanabilir mi? **Cevap:** Açık kaynaklı programlar ve Multisim gibi seçenekler vardır; kullanılabilir. Ancak sorular Proteus'a göre hazırlanacağı için Proteus kullanmak daha kolay olur. Önemli olan devrenin simüle edilmesi ve sonucun doğru çıkmasıdır.

**Soru:** Daha önce başka bir derste kullanılan eski Proteus 8 sürümü kullanılabilir mi? **Cevap:** Evet, sürüm önemli değildir.

## 3. Yeni proje, eleman seçimi ve bağlantı

### 3.1 Yeni proje

İlk adım bir çalışma alanı (workspace) açmaktır: File > New Project. Proje adı yazılır, varsayılan ayarlar korunur, şablon seçilmez. Mikroişlemci projelerinde bu aşamada bir donanım ailesi seçilirdi; burada boş proje gerekir, bu yüzden "No firmware project" seçilir ve Finish'e basılır. Arka planı ızgaralı boş bir sayfa açılır (ekrandan, 00:25:00).

### 3.2 Eleman seçimi

Elektronik bir devre kurmak için önce elemanlar (direnç, kondansatör, diyot, transistör, kaynak) alınır. Elemanlar "P" düğmesiyle ya da sol taraftaki Devices bölümünden açılan kütüphane penceresinden seçilir. Arama kutusuna anahtar kelime yazılır: kondansatör için CAP, direnç için RES, pil için BAT, diyot için diyotun adı. Listeden eleman seçilip OK'a basılır.

Laboratuvar sorularında ya hangi elemanın kullanılacağı (örneğin belirli kodlu bir diyot) açıkça söylenir ya da yalnız elemanın özellikleri verilir ve uygun eleman öğrenci tarafından seçilir.

Seçilen eleman pembe renkte fareyle birlikte hareket eder ve tıklanan yere bırakılır. Seçim modunda kalınırsa her tıklama yeni bir eleman ekler; bundan çıkmak için Escape'e basılır ve sol araç çubuğundan seçim (selection) moduna geçilir. Bir eleman seçilip Delete tuşuyla silinebilir.

### 3.3 Değer atama ve bağlantı

Elemanın adı kadar değeri de önemlidir. Değer elemanın üzerine çift tıklanarak girilir; örneğin direnç 5 Ω yapılır. Sorularda devre şekli değerleriyle birlikte verilebilir. Bağlantılar fareyle bir uçtan basılı tutup çekilerek yapılır; kablo bağlantı noktasına götürülünce orada bir kez daha tıklamak gerekir, yoksa bağlantı oluşmaz.

Kaynak için birkaç seçenek vardır: kütüphaneden DC gerilim kaynağı, AC gerilim kaynağı ya da pil (battery) seçilebilir. Pil uzun ve kısa çizgiyle gösterilen bir DC kaynaktır; varsayılan değeri 1 V'tur ve çift tıklanarak değiştirilir.

## 4. Simülasyonu çalıştırma ve hata mesajları

Simülasyon sol alttaki oynat (play) düğmesiyle ya da menüdeki "Run Simulation" komutuyla başlatılır; ikisi aynı işi yapar. Analizler genellikle sürekli zamanda yapılır; mikroişlemcilerdeki gibi kodu adım adım yürütmeye gerek yoktur.

Alttaki Messages alanı sürekli izlenmelidir. Bu alan yeşilse sorun yoktur; kırmızıysa hata vardır ve devre çalışmaz. Hata mesajları her zaman doğrudan değildir. Örneğin ampermetre yanlış bağlanınca program yalnızca kaynakla ilgili bir sorun olduğunu söyleyen bir "fatal error" verir; neyin ters bağlandığını yazmaz. Bağlantısı yapılmamış uçlar için devrenin "floating" (havada) olduğu uyarısı çıkabilir ve yeri belirtilmeyebilir.

Sol araç çubuğundaki etiket (label) gibi araçlar karmaşık devrelerde uzun kablolar yerine uçları etiketle bağlamaya yarar. Laboratuvardaki devreler küçük olduğu için bunlar anlatılmamıştır; en çok kaynaklar, ölçü aletleri, problar ve grafik araçları kullanılır.

## 5. Voltmetre ve ampermetre

Devre kurulduktan sonra herhangi bir koldaki akımı ya da gerilimi anlık ölçmek, ya da bir noktadaki akım veya gerilimin zamanla değişimini izlemek gerekir. Kaynak her zaman DC olmayabilir; sinüs kaynakla beslenen devrede sinyal grafiğe dökülebilir ya da osiloskopla incelenebilir.

Ölçü aletleri sol çubuktaki ölçü aleti simgesine tıklanınca açılan Instruments listesindedir: Oscilloscope, Logic Analyser, Counter Timer, Virtual Terminal, SPI Debugger, I2C Debugger, Signal Generator, Pattern Generator, DC Voltmeter, DC Ammeter, AC Voltmeter, AC Ammeter, Wattmeter (ekrandan, 00:30:00). Laboratuvarda en çok voltmetre, ampermetre ve osiloskop kullanılacaktır.

### 5.1 Voltmetre paralel bağlanır

**Soru:** Voltmetre ölçülen elemana nasıl bağlanır, neden? **Cevap (bir öğrenci):** Paralel bağlanır, çünkü iç direnci sonsuz kabul edilir; seri bağlanırsa üzerinden akım geçmez.

Asistan bu cevabı tamamlar: voltmetre iki nokta arasındaki gerilim farkını ölçer. Paralel elemanların gerilimleri birbirine eşittir; bu yüzden ölçü aleti hangi elemana paralel bağlanırsa onun gerilimini gösterir. Kaynağın gerilimi ölçülmek isteniyorsa voltmetre kaynağa paralel bağlanır; örnekte 5 V okunur.

### 5.2 Ampermetre seri bağlanır

**Soru:** Ampermetre nasıl bağlanır, neden? **Cevap (bir öğrenci):** Seri bağlanır, çünkü direnci yoktur; paralel bağlanırsa akım ampermetreden geçer, oysa ölçülmek istenen akım elemanın akımıdır.

Akım bir elemanın üzerinden akar; akımı ölçmek için akımın ölçü aletinin içinden geçmesi gerekir. Asistan ampermetreyi önce bir kolu kısa devre edecek biçimde koyunca Proteus hata verdi; mesajda yalnızca kaynakla ve ampermetreyle ilgili bir sorun olduğu yazıyordu. Ampermetre akımın döndüğü kola seri konunca devre çalıştı.

### 5.3 Ölçü aletinin yönü ve eksi işaret

İlk örnek devrede 5 V'luk kaynak ($V_1$), 5 Ω'luk direnç ($R_1$), seri bir ampermetre ve kaynağa paralel bir voltmetre vardır (ekrandan, 00:35:00). Voltmetre $+5{,}00$ V, ampermetre $-1{,}00$ A gösterir.

**Soru:** Ampermetre neden eksi gösteriyor? **Cevap:** Ölçü aletlerinin artı ve eksi işaretli uçları vardır. Akım kaynağın artı ucundan çıkar, devreyi dolaşır ve ampermetreye eksi ucundan girer. Akım eksi terminalden girdiği için değer eksi görünür. Ampermetre ters çevrilip akım artı ucundan girecek biçimde bağlanırsa $+1{,}00$ okunur; voltmetre ters bağlansaydı da $-5$ V okunurdu.

> **Hocanın vurgusu:** Ölçü aletlerinin ve probların yönü vardır. Eksi okunan değeri olduğu gibi rapora yazmak işaret hatasıdır; aletin yönü akımın yönüne göre düzeltilmelidir.

Asistan ayrıca devre teorisi konularının tekrar edilmesini ister: Thevenin ve Norton eşdeğerleri, düğüm (node) ve çevre (mesh) analizi, gerilim bölücü ve akım bölücü. Elektronik derslerinde bunlardan çok daha karışık devreler gelecektir.

## 6. Toprak, gerilim ve akım probları

### 6.1 Toprak

Proteus topraksız devreyi de çalıştırır; başka simülatörler (örneğin Cadence) bunu hata sayabilir. Yine de devreye her zaman toprak sembolü konur. Toprak, sol çubuktaki terminal araçlarından seçilir.

### 6.2 Tek uçlu problar

Voltmetre ve ampermetrenin iki ucu vardır; eksi ucu artıya göre görece düşük alındığı için toprak olmasa da doğru sonuç verirler. Gerilim ve akım probları ise tek uçludur: fiziksel osiloskobun kalem biçimli probu gibi, metal ucu devrenin bir noktasına değdirilince o noktanın sinyalini verir. Tek uçlu prob, ölçtüğü noktanın gerilimini toprağa göre verir; devrede toprak yoksa referansı bilemez ve yanlış değer gösterebilir. Bu yüzden prob kullanılan devrelerde toprak zorunludur.

Gerilim probu bir kabloyla istenen noktaya bağlanabilir. Akım probu ise ek bir bağlantı olmadan doğrudan devre hattının üzerine konmalıdır. Akım probu seçilince pembe renkte gelir, hattın üzerine tıklanınca maviye döner ve oraya yerleşir.

### 6.3 Problarla düğüm gerilimleri

İlk devreye toprak ve problar eklendiğinde kaynağın artı ucundaki prob $V = 5$, direncin diğer ucundaki prob $V = 0$ ve toprak probu $V = 0$ gösterir (ekrandan, 00:40:00). Kaynağın eksi ucuna bağlı kablo, ulaştığı bütün noktaları 0 V yapar. Böylece direncin uçları arasında $5 - 0 = 5$ V gerilim vardır. Direnç aslında kaynağa paraleldir; uzun kablolarla çizilmese de devre bir kaynak ve ona paralel bir dirençten oluşur.

Akım için Ohm yasası uygulanır:

$$I = \frac{V}{R} = \frac{5\ \text{V}}{5\ \Omega} = 1\ \text{A}$$

Asistan burada birimin amper olduğunu, yanlış söylenmemesi gerektiğini de belirtir. Akım probu $-1$ gösterirse neden prob üzerindeki okun yönüdür. **Soru:** Prob neden eksi gösteriyor? **Cevap (bir öğrenci):** Probun oku akımı ters yönde (sağa doğru) gösteriyor. Asistan bunu doğrular: probun okunun da anlamı vardır. Prob sağ tıkla 180° döndürülünce okun yönü akımın yönüyle aynı olur ve değer $+1$ okunur.

## 7. Örnek DC devre analizi

İkinci örnek devre ekranda şöyledir (ekrandan, 00:45:00): $R_1 = 5\ \Omega$ ve $R_2 = 5\ \Omega$ seri; bu seri kolun bir ucu toprakta, diğer ucu bir düğümde. Aynı düğümden toprağa $R_3 = 10\ \Omega$ bağlıdır. Düğüm $R_4 = 5\ \Omega$ üzerinden tek uçlu bir kaynağa gider. Devrede dört prob vardır: $R_1$ ucunda gerilim probu, $R_1$-$R_2$ arasında akım probu, düğümde gerilim probu ve $R_4$ ucunda akım probu.

**Soru:** Devredeki çizilmemiş, boşlukta duran sembol nedir? **Cevap (bir öğrenci):** Kaynaktır. Asistan bunu doğrular: tek uçlu bir kaynaktır, ikinci ucuna gerek yoktur; diğer ucu toprağa bağlıymış gibi davranır. Kaynağa çift tıklanarak 10 V girilmiştir.

Çözüm adım adım:

- Seri dirençler toplanır: $R_1 + R_2 = 5 + 5 = 10\ \Omega$.
- Bu kol $R_3$ ile paraleldir. İki paralel direnç "çarpımları bölü toplamları" ile bulunur:
  $$R_{p} = \frac{10 \cdot 10}{10 + 10} = \frac{100}{20} = 5\ \Omega$$
  Eşit iki direnç paralelse sonuç doğrudan yarısıdır.
- Kaynaktan bakınca $R_4$ ile $R_p$ seridir: $R_{\text{eş}} = 5 + 5 = 10\ \Omega$.
- Kaynak akımı: $I = 10\ \text{V} / 10\ \Omega = 1\ \text{A}$.
- Düğüm gerilimi (ara adım eklendi): $V_{\text{düğüm}} = 10 - 1 \cdot 5 = 5$ V. Ekrandaki düğüm probu da $V = 5$ gösterir.
- Kol akımları: iki kolun direnci eşit (10 Ω) olduğu için akım ikiye bölünür: $I_1 = I_2 = 0{,}5$ A. Ekrandaki akım probu $I = -0{,}5$ gösterir; eksi işaret yine probun okunun yönündendir, döndürülünce $+0{,}5$ olur.

**Soru:** İki paralel direnç için ne yapılır? **Cevap (bir öğrenci):** $\dfrac{1}{R_{\text{eş}}} = \dfrac{1}{10} + \dfrac{1}{10}$. Asistan formülün doğru olduğunu, ama iki direnç için kısa yolun "çarpımları bölü toplamları" olduğunu hatırlatır. Bir öğrencinin "toplamları bölü çarpımları" demesi üzerine doğrusu "çarpımları bölü toplamları" olarak düzeltilir.

Bu sonuçlar python ile kontrol edilmiştir: $R_{\text{eş}} = 10\ \Omega$, $I = 1$ A, $V_{\text{düğüm}} = 5$ V, kol akımları 0,5 A.

> **Ek bilgi (derste anlatılmadı):** İki eşit kola bölünen akım, akım bölücü kuralının özel bir durumudur: $I_1 = I \cdot \dfrac{R_2}{R_1 + R_2}$. Kol dirençleri eşitse her kola toplam akımın yarısı düşer.

## 8. Zamana bağlı grafik (analog graph)

Laboratuvarda bir büyüklüğün zamana göre grafiğinin çizilmesi de istenebilir; örneğin "$R_3$ direncinin akımının zamana bağlı değişimini gösteriniz". Bunun için grafik araçlarından "analog graph" seçilir ve çalışma alanında bir yere bırakılır. Grafiğe Add Trace ile devredeki problardan biri eklenir. Grafiğin üzerine çift tıklanarak zaman aralığı (X ekseni; örneğin 0-1 s ya da milisaniyeler) ayarlanır. Sağ tık > Simulate Graph ile seçilen probların zamana bağlı eğrisi çizilir.

Örnekte bir kol akımı grafiğe eklenmiş, sabit bir $-0{,}5$ A çizgisi görülmüştür. Kaynak DC olduğu için akım zamanla değişmez. Asistan, grafik ekranının bazen simülasyon çalışırken güncellenmediğini, simülasyon bir kez çalıştırılıp durdurulduktan sonra Simulate Graph denmesi gerektiğini de gösterir. Kaynağın kendi ucundaki prob seçilirse anlamlı bir eğri çıkmayabilir.

## 9. Sinüs kaynak, gerilim izleyici ve osiloskop

### 9.1 Sinüs kaynak

Laboratuvarda yalnız DC analiz yapılmaz; kare dalga ya da sinüs dalgayla beslenen devreler de olabilir. Sinyalin periyodu ve frekansı verilebilir ya da hesaplanması istenebilir. Sinüs kaynağı, sol çubuktaki tek uçlu kaynak listesinden (Generators: DC, SINE, PULSE, EXP, SFFM, PWLIN, FILE, AUDIO, ...) seçilir (ekrandan, 00:45:00). DC olarak konmuş bir kaynak da çift tıklanıp sinüse çevrilebilir. Sinüs seçilince genlik, tepeden tepeye değer, rms değer, ofset, frekans ve periyot girilir.

> **Hocanın vurgusu:** Bir sinüs dalgasının genliğinin, ofsetinin, frekansının ve periyodunun ne anlama geldiği bilinmelidir; osiloskopta ölçülen değerler bunlara karşılık gelir.

### 9.2 Gerilim izleyici (voltage follower)

Örnek devrede sinüs kaynak bir op-amp'a bağlanmış, çıkışa 10 Ω'luk bir direnç ($R_5$) ve osiloskop bağlanmıştır (ekrandan, 00:50:00). Asistan devreyi gerilim izleyici olarak tanıtır: girişe verilen gerilimi çıkışta aynen gösterir, yani sinyali tamponlar (buffer). Değerler rastgele seçilmiştir; amaç osiloskobun kullanımını göstermektir.

> **Ders sonrası not:** Ekrandaki şemada geri besleme hattı op-amp'ın çıkışından artı (evirmeyen) girişe gidiyor, sinüs kaynak ise eksi (eviren) girişe bağlı görünüyor (ekrandan, 00:50:00, 01:15:00). Gerilim izleyicide doğru bağlantı bunun tersidir: giriş artı uca verilir, çıkış eksi uca geri beslenir (negatif geri besleme). Ekrandaki bağlantı pozitif geri beslemedir; simülasyonda izleyici gibi görünmesi büyük olasılıkla ideal op-amp modelinden kaynaklanır.

> **Ek bilgi (derste anlatılmadı):** Gerilim izleyicide $V_{\text{çıkış}} = V_{\text{giriş}}$ olur, kazanç 1'dir. Faydası, giriş direncinin çok yüksek, çıkış direncinin çok düşük olmasıdır; böylece kaynağı yüklemeden yükü sürer.

### 9.3 Dijital osiloskop

Instruments listesinden seçilen osiloskop dört kanallıdır: A, B, C ve D; her kanalın bir rengi vardır (A sarı, B mavi, C pembe/kırmızı, D yeşil). Örnekte çıkış A kanalına (sarı), sinüs kaynağın sinyali B kanalına (mavi) bağlanmıştır. Simülasyon çalışınca laboratuvardaki cihaza benzeyen bir osiloskop penceresi açılır (ekrandan, 00:55:00). Ekranda iki sinüs aynı biçimde görünür; devre girişi izlediği için beklenen sonuç budur.

Osiloskop penceresinde Trigger, Horizontal ve her kanal için Position ile V/kare (V/div) ayarları vardır. Ekrandaki ayarlarda yatay ölçek 0,2 ms/kare, A ve B kanallarının dikey ölçeği 5 mV/kare olarak görünür (ekrandan, 00:55:00). Ölçek ayarı sinyalin değerini değiştirmez; sinyalin var olan değerini görülebilir bir ölçeğe getirir.

Osiloskop okuma yöntemi:

- Ekrandaki ızgara bir referanstır; kareli kâğıda çizilmiş bir grafik gibi düşünülür.
- Yatayda: bir periyotluk (tepeden tepeye) uzaklıktaki kare sayısı sayılır, kare başına süreyle (Horizontal ayarı) çarpılır; periyot bulunur, frekans onun tersidir.
- Dikeyde: sinyalin kapladığı kare sayısı sayılır, ilgili kanalın kare başına gerilimiyle çarpılır; genlik ya da tepeden tepeye değer bulunur.

$$T = n_{\text{yatay}} \times (\text{s/kare}), \qquad f = \frac{1}{T}, \qquad V_{pp} = n_{\text{dikey}} \times (\text{V/kare})$$

> **Hocanın vurgusu:** Her laboratuvarda osiloskopla ilgili soru gelir: çıkış sinyalinin ekran görüntüsünü koymak, frekansını ve genliğini söylemek. Okuma yatay ve dikey kareleri sayıp ölçekle çarpmaktan ibarettir.

<!-- BELİRSİZ: 00:53:47'de örnek okumada "5 volt" dendi; ekrandaki ölçek ve 00:55:06'daki anlatım kare başına 5 mV'tur. -->

**Soru:** Osiloskopta tek bir ızgara var, ama farklı renkte sinyaller var. Bir kanalın ölçeği 5 mV/kare, diğerininki 10 mV/kare yapılırsa karışıklık olmaz mı? **Cevap:** Her kanalın ölçek düğmesi yalnız o kanalı etkiler. Aynı ızgara üzerinde her sinyal kendi kanalının ölçeğiyle okunur; değerler kanal ayarına göre hesaplanır. (Asistan bunu uygulamalı göstermeden önce öğrenci anladığını söylemiştir, 01:14:45.)

Pratik bir uyarı: Simülasyon çarpıdan kapatılırsa osiloskop penceresi kaybolur; simülasyon yeniden çalıştırılınca da kendiliğinden açılmaz. Debug menüsünden dijital osiloskop yeniden seçilerek açılır.

## 10. Breadboard ve Fritzing

### 10.1 Fritzing

Laboratuvarda ya da projede devrenin gerçekte kuruluyormuş gibi breadboard üzerinde çizilmesi istenebilir. Bunun için Fritzing kullanılır. Fritzing bir simülasyon programı değildir; yalnız devrenin breadboard üzerindeki görünümünü çizer (ekrandan, 01:00:00, 01:10:00). Core Parts kütüphanesinde direnç, kondansatör, bobin, diyot, transistör, op-amp gibi hemen her temel eleman bulunur. Fritzing çiziminde devrenin çalışıp çalışmadığına değil, bağlantıların doğru yapılıp yapılmadığına bakılır.

### 10.2 Breadboard'un iç yapısı

Breadboard ucuz bir deney tahtasıdır ve projelerde kullanılacaktır. Yapısı şöyledir:

- Üstteki ve alttaki uzun kanallar (güç hatları) boylu boyunca birbirine bağlıdır; alttan tel geçtiği düşünülür. Güç kaynağının artı ucu ve toprak bu hatlara verilir.
- Ortadaki delikler kısa gruplar hâlinde alttan birbirine bağlıdır. Bir gruptaki herhangi bir deliğe takılan şey o gruptaki diğer deliklere takılanlarla bağlıdır.

Ekrandaki örnekte güç kaynağı üst hatta bağlanmış, bir direnç üzerinden akım geçmiş, ikinci bir direncin bir bacağı birincinin bacağıyla aynı gruba takılmıştır.

**Soru:** Bu iki direnç birbirine nasıl bağlı? **Cevap (bir öğrenci):** Seri. Asistan genel kuralı verir: iki eleman yalnızca bir uçtan birbirine değiyorsa seri, iki ucu birden birbirine bağlıysa paraleldir.

**Soru:** Bir dirence paralel başka bir direnç bağlamak için ne yapılır? **Cevap (bir öğrenci):** Aynı hizadan bağlanır. Yani ikinci direncin iki bacağı, ilk direncin iki ucunun bulunduğu bağlı gruplardan herhangi bir deliğe takılır; önemli olan uçların birbirine değmesidir. Sonra güç hattından ve toprak hattından herhangi bir delik kullanılarak devre beslenir.

### 10.3 Kısa devre hatası

Ekranda bir bobin ya da direnç iki bacağı da aynı bağlı gruba gelecek biçimde takılmıştır.

**Soru:** Bu bağlantı doğru mu? **Cevap (bir öğrenci):** Hayır, kısa devre olur. Asistan açıklar: o noktalar alttan birbirine bağlıdır; iki ucu birbirine değen bir direnç kısa devredir. Akım dirençten geçmek istemez, boş yoldan ilerler. Bu yüzden böyle bir kurulum yapılmaz.

## 11. Projelerde entegre devreler

**Soru:** Projede Arduino gibi bir şey kullanmak gerekecek mi? **Cevap:** Hayır, böyle bir beklenti yoktur. Arduino kartı doğrudan kullanılamaz; ama kartın üzerindeki ATmega işlemci çipi ya da başka bir entegre devre (IC) kullanılabilir. Çipi tek başına çalıştırmak için kristal ve kondansatörler gibi çevre elemanları bağlamak gerekir; Arduino kartı bu çevre birimlerini (güç ünitesi, USB üzerinden seri haberleşme devresi) hazır sunar. Çip breadboard'un ortasındaki oluğun iki yanında kalacak biçimde takılır, sensörden alınan veri dirençler üzerinden çıkıştaki LED'lere bağlanarak bir proje yapılabilir.

Örnek proje fikirlerinde (yağmur damlasını algılayınca öten sistem, vu-metre gibi) mikrodenetleyici gerekmez; işi gören entegreler vardır. LM555 gibi entegreler ya da op-amp yapısındaki özel IC'ler kullanılabilir. Vu-metre, gelen müzik sinyalini alıp seviyesine (örneğin basa) göre sırayla bir ile beş arasında LED yakan, eski müzik setlerindeki yükselen ışıklara benzeyen bir göstergedir.

Mikroişlemci ile mikrodenetleyici ayrımına da değinilir: mikroişlemcinin iç yapısı başka bir derste 8086 üzerinden anlatılır; mikrodenetleyici ise C/C++ gibi dillerle programlanan, çevre birimleri içeren kontrol birimidir. Bu laboratuvarın amacı bir mikrodenetleyici projesi yapmak değildir.

## 12. Ders kapsamı üzerine soru

**Soru:** Bugün anlatılanlar devre teorisinin özeti gibiydi. Thevenin, Norton, op-amp'ın AC analizi gibi konular bu dersin kapsamında mı, derste yeniden anlatılacak mı? **Cevap:** Devre teorisinde görülen her şey (op-amp'ın AC analizine kadar) bu dersin kapsamındadır ve bilindiği varsayılır; direnç, Thevenin gibi temel konular derste sıfırdan anlatılmaz. Bunların ötesinde diyot ve transistörler ayrıntılı işlenir. Op-amp dersin konularından biridir ve bir miktar AC analizi de içerir. Op-amp, BJT gibi laboratuvar konularının teorisi önce derste anlatılır, laboratuvar sonra yapılır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:32:00; devre ekrandan, 00:35:00): Voltmetre ve ampermetre devreye nasıl bağlanır, neden?

> **Çözüm (derste verildi):** Voltmetre ölçülen elemana paralel bağlanır; iki nokta arasındaki gerilim farkını ölçer ve paralel elemanların gerilimi eşittir, iç direnci sonsuz kabul edilir. Ampermetre seri bağlanır; ölçülen akımın aletin içinden geçmesi gerekir, iç direnci sıfır kabul edilir.

**Soru 2** (derste sözlü, 00:35:12; devre ekrandan, 00:35:00): 5 V'luk kaynak ve 5 Ω'luk dirençten oluşan devrede ampermetre neden $-1{,}00$ A gösteriyor?

> **Çözüm (derste verildi):** $I = 5/5 = 1$ A akar. Akım ampermetreye eksi işaretli ucundan girdiği için değer eksi okunur. Ampermetre ters çevrilirse $+1{,}00$ A okunur.

**Soru 3** (derste sözlü, 00:42:29 ve 00:44:24; devre ekrandan, 00:45:00): $R_1 = R_2 = 5\ \Omega$ seri, bu kola paralel $R_3 = 10\ \Omega$, bunlara seri $R_4 = 5\ \Omega$ ve 10 V'luk kaynaktan oluşan devrede $R_1$ ile $R_2$ nasıl bağlıdır, eşdeğer direnç, kaynak akımı ve kol akımları nedir?

> **Çözüm (derste verildi):** $R_1$ ve $R_2$ seridir: $10\ \Omega$. Bu kol $R_3$ ile paralel: $\frac{10\cdot 10}{20} = 5\ \Omega$. Toplam $5 + 5 = 10\ \Omega$, akım $10/10 = 1$ A. Kollar eşit olduğu için her kola 0,5 A düşer; düğüm gerilimi 5 V'tur (python ile kontrol edildi).

**Soru 4** (derste sözlü, 00:43:28; ekrandan, 00:45:00): Devrede ucu boşta görünen tek uçlu sembol nedir?

> **Çözüm (derste verildi):** Tek uçlu bir kaynaktır; diğer ucu toprağa bağlıymış gibi davranır.

**Soru 5** (derste sözlü, 00:58:58): Breadboard'da bir bacakları aynı bağlı gruba takılmış iki direnç nasıl bağlıdır? Bunlardan birine paralel bir direnç nasıl bağlanır?

> **Çözüm (derste verildi):** Yalnız bir uçları ortak olduğu için seridirler. Paralel bağlamak için yeni direncin iki bacağı, mevcut direncin iki ucunun bulunduğu bağlı gruplara takılır.

**Soru 6** (derste sözlü, 01:08:31; ekrandan, 01:10:00): Bir elemanın iki bacağı breadboard'da alttan birbirine bağlı aynı gruba takılırsa ne olur?

> **Çözüm (derste verildi):** Kısa devre olur; akım elemandan değil boş yoldan geçer.

## Dersin Toparlaması

Bu oturumda çevrim içi laboratuvarlar için kullanılacak araçlar tanıtıldı. Proteus'ta proje açma, eleman seçme, değer girme ve bağlantı yapma gösterildi. Voltmetrenin paralel, ampermetrenin seri bağlanmasının nedeni ve ölçü aletleriyle probların yönünden doğan eksi işaretler örnek devrelerle açıklandı. Toprağın tek uçlu problar için neden zorunlu olduğu anlatıldı. Seri-paralel direnç birleştirme ve akımın eşit kollara bölünmesi bir örnekte adım adım çözüldü ve simülasyon sonuçlarıyla karşılaştırıldı.

Ardından zamana bağlı grafik çizimi, sinüs kaynak ayarları, gerilim izleyici devresi ve dört kanallı osiloskopta periyot, frekans ve genliğin kareler sayılarak okunması gösterildi. Son olarak Fritzing ile breadboard üzerinde seri, paralel ve hatalı (kısa devre) bağlantılar ele alındı. Sonraki laboratuvarların konuları teori derslerindeki sırayı izler: diyot, op-amp, BJT ve CMOS.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
