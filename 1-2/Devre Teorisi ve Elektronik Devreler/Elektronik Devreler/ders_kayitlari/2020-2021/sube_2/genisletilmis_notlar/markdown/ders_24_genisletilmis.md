# Ders 24 Genişletilmiş Notu: Laboratuvar: CMOS Evirici ve MOSFET Lojik Kapı Analizi (Proteus)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun yapısı
- 2. CMOS lojik ve MOSFET'in anahtar modeli
- 3. Birinci soru: CMOS eviricinin sentezi
- 4. Kare dalga kaynağı ve analog analiz grafiği
- 5. Gerilim transfer karakteristiği, VOL ve VOH
- 6. İkinci soru: bilinmeyen iki girişli kapının analizi
- 7. Oturumda çıkan sorunlar ve çözümleri
- 8. PMOS ve NMOS sembollerini ayırt etme
- Örnek Sorular

## 1. Oturumun yapısı

Bu kayıt, haftalık teori dersinden ayrı yapılan bir laboratuvar uygulama oturumudur ve konusu MOSFET'tir. Oturumu laboratuvardan sorumlu asistan yürütür. Laboratuvar çevrim içi olduğu için devreler Proteus simülasyon programında kurulur ve sonuçlar ekran görüntüleriyle bir belgeye yerleştirilir. Asistan soru belgesini ekranda paylaşmaz; öğrencilerin kendi kopyalarına bakmasını isteyerek soruları sayfa sayfa sözlü olarak açıklar. Bu yüzden soru metinleri ve şekiller kareden okunamamıştır; aşağıdaki soru içerikleri asistanın sözlü anlatımından kurulmuştur.

Asistanın belirttiğine göre sorular, MOSFET konusunda en az hesap gerektiren alt başlıklardan seçilmiştir. Laboratuvarın amacı MOSFET'in ayrıntılı modeliyle hesap yapmak değil, CMOS lojik kapıların çalışma mantığını simülasyonla göstermektir.

## 2. CMOS lojik ve MOSFET'in anahtar modeli

MOSFET'ler CMOS teknolojisi adı altında birlikte kullanılarak lojik kapılar tasarlanabilir. CMOS'ta aynı devrede hem PMOS hem NMOS transistörler bulunur; buna tamamlayıcı lojik (complementary logic) denir. Asistan, CMOS'un bir transistör tipi değil bu konfigürasyona verilen ad olduğunu özellikle belirtir.

CMOS teknolojisinde iki tip transistör ayrı ayrı elemanlar olarak değil, tek bir yapı üzerinde birlikte üretilir. Asistana göre bugün telefonların içindeki işlemciler gibi sistemlerin bu kadar küçük olabilmesinin en büyük sebebi, iki tipin tek bir teknolojiyle bir arada gerçeklenebilmesidir.

Bu laboratuvarda MOSFET'in derste anlatılan en basit kullanımı esas alınır: transistör bir anahtardır, ya açık (on) ya kapalıdır (off). $V_{GS}$, eşik gerilimi ($V_T$), body etkisi gibi ayrıntılarla hiç hesap yaptırılmaz. Devrede transistörlerin görevi, çıkışa bir durumda bir yerden, diğer durumda başka bir yerden değer vermektir.

> **Ek bilgi (derste anlatılmadı):** Bir CMOS kapıda PMOS'lar çıkışı beslemeye (pull-up), NMOS'lar çıkışı toprağa (pull-down) bağlayan ağı oluşturur. Kararlı durumda iki ağdan yalnız biri iletimdedir; bu yüzden beslemeden toprağa sürekli bir akım yolu oluşmaz ve statik güç tüketimi çok düşüktür. CMOS'un yaygınlaşmasının başlıca nedenlerinden biri büyük olasılıkla budur.

## 3. Birinci soru: CMOS eviricinin sentezi

Birinci soru bir sentez sorusudur. Sentez, bir devreyi tasarlamak demektir; ama burada sıfırdan transistör kombinasyonu icat etmek değil, CMOS ile bilinen bir lojik kapıyı, eviriciyi (NOT kapısı, inverter) kurmak istenir. Asistan, internette "inverter logic gate using MOSFET" gibi bir aramayla devrenin bulunabileceğini, kullanılacak elemanların hangi Proteus kütüphanesinden seçileceğinin soruda yazdığını söyler.

### 3.1 Elle çizim

İlk adımda devre elle çizilir. Çizimde transistörler, giriş, çıkış ve toprak gösterilir; özellikle giriş gerilimi, çıkış gerilimi, DC besleme gerilimi (source voltage) ve toprak işaretlenir. Asistanın dikkat çektiği nokta, devrede iki kaynak bulunmasıdır: biri giriş işareti, diğeri besleme. Besleme ve toprağın çıkışta ne görüleceği açısından önemi vardır. Elle çizimin amacı, daha sonraki adımlarda hataların birikmemesi için PMOS'un, NMOS'un ve girişin nerede olduğunun baştan doğru belirlenmesidir.

### 3.2 Proteus'ta kurulum

İkinci adımda elle çizilen devre Proteus'a aktarılır. Besleme toprağa göre bağlanır ve giriş ile çıkışı gözleyebilmek için gerilim probları konur. Bir öğrencinin paylaştığı ekranda kurulan devre görülür: üstte kaynağı beslemeye ("Vsource") bağlı bir P kanallı MOSFET (2SJ56), altta kaynağı toprağa bağlı bir N kanallı MOSFET (2SK176); iki gate birleştirilip kare dalga girişine, iki drain birleştirilip çıkış probuna bağlanmıştır (ekrandan, 02:25:00).

```text
           Vsource (VDD)
               |
            [PMOS]  (2SJ56)
   giriş ──┬── gate        drain ──┬── çıkış
           └── gate        drain ──┘
            [NMOS]  (2SK176)
               |
             toprak
```

Bir öğrenci giriş ve çıkış için lojik durum (logic state) elemanı kullanıp kullanamayacağını sordu.

**Soru:** Giriş ve çıkış yerine lojik durum elemanı konabilir mi? **Cevap:** Hayır, yalnız analog çalışılacak. Girişe analog bir işaret (kare dalga ya da DC gerilim) verilir. Asistan oturumun ilerleyen bölümünde soruların hiçbirinde lojik giriş kullanılmayacağını tekrar duyurdu.

## 4. Kare dalga kaynağı ve analog analiz grafiği

### 4.1 Pulse kaynağının parametreleri

Üçüncü adımda devrenin girişine bir işaret verilir. Asistan, girişin mutlaka sürekli bir sinyal olmak zorunda olmadığını, ayrık (diskret) değerler de verilebileceğini söyler; ama burada amaç sürekli değişen bir işaretle kapının görevini yaptığını göstermektir. Bu yüzden girişe soruda sembolü verilen kare dalga üreteci (pulse generator) bağlanır ve özellikleri (Properties) güncellenir. Asistan parametrelerin anlamını şöyle açıklar:

- En düşük ve en yüksek gerilim: işaretin inip çıkabileceği seviyeler. Bu laboratuvarda yüksek seviye 5 V'tur.
- Başlama zamanı: işaretin gecikmeli başlayıp başlamadığını belirtir. Burada gecikme konmaz, kare dalga sıfır anından başlar.
- Yükselme zamanı (rise time): kare dalga dimdik de yükselebilir, eğimli de; bu parametre yükselişin süresini verir.
- Düşme zamanı (fall time): tepeden aşağı inişin süresi.
- Darbe genişliği (pulse width): işaretin tepede, yani lojik 1 seviyesinde kaldığı süre. Burada 1 saniyedir.
- Periyot: işaretin sıfırdan çıkıp tepede kalıp yeniden sıfıra inmesi ve bir süre sıfırda kalmasıyla oluşan tam çevrimin süresi.

Bu adımda devrenin kaynak bağlanmış hâlinin ve güncellenmiş pulse generator özellik penceresinin ekran görüntüsü istenir.

### 4.2 Simülasyon ve analog analiz

Dördüncü adımda devre simüle edilir. Giriş ve çıkış gerilimlerini ölçmek için problar bağlanır, sonra analog analiz grafiği (Analogue Analysis) kullanılır. Asistan bu monitörü ilk laboratuvar tanıtımında anlattığını hatırlatır. Amaç giriş ve çıkış sinyallerini aynı grafikte üst üste görmek ve eviricinin işlemini izlemektir. Problar grafiğe iz (trace) olarak eklenir; asistan bunun için çift tıklama, sağ tıklama ya da sürükle-bırak yöntemlerinin denenebileceğini söyler.

Grafiğin ayarlarında simülasyonun yatay eksende ne kadar süreceği girilir: başlangıç 0, bitiş 50. Asistan, devre çalıştırıldıktan hemen sonra grafikte sonuç görünmeyebileceğini, sonucun grafiğe gelmesi için ayrıca bir adım yapılması gerektiğini söyler.

## 5. Gerilim transfer karakteristiği, VOL ve VOH

### 5.1 Grafiğin yorumu ve transistör durumları

Beşinci adım iki kısımdan oluşur. Birinci kısımda elde edilen grafik yorumlanır: grafikte görülen davranış nedeniyle devrenin evirici olduğu kısa bir gerekçeyle yazılır.

İkinci kısım, CMOS kapılar tasarlanırken kullanılan gerilim transfer karakteristiği (voltage transfer characteristic) kavramıyla ilgilidir. Burada girişe uygulanan minimum gerilimde çıkışta görülecek maksimum gerilim ve girişe uygulanan maksimum gerilimde çıkışta görülecek minimum gerilim, yani çıkışın en düşük ve en yüksek değerleri ele alınır.

> **Hocanın vurgusu:** Girişe verilen sinyal çıkışta doğrudan "terslenerek" görülmez. Transistörler açılıp kapandıkça çıkışa bir durumda bir değer, diğer durumda başka bir değer verilir; çıkışta görülen girişin tersidir ama girişten doğrudan gelen işaret değildir. Bu seçimi transistörler yapar.

Bu kısımda girişin en düşük olduğu durum için hangi transistörlerin off olduğu (çizimde noktalı gösterilebilir), off olan nedeniyle on olan transistörün çıkışa ne verdiği; girişin en yüksek olduğu (kare dalganın tepesi) durum için de hangi transistörün çıkışı etkilediği ve hangisinin etkilemediği çizilip açıklanır.

> **Ek bilgi (derste anlatılmadı):** Giriş düşükken ($V_{in} \approx 0$) NMOS'un $V_{GS}$'si eşiğin altında kalır ve NMOS kapalıdır; PMOS'un gate'i source'a göre negatif olduğundan PMOS iletimdedir ve çıkışı $V_{DD}$'ye bağlar. Giriş yüksekken ($V_{in} \approx V_{DD}$) NMOS iletime geçip çıkışı toprağa bağlar, PMOS kapanır. Bu yüzden çıkış her iki uçta da neredeyse tam olarak $V_{DD}$ ya da 0 olur.

### 5.2 DC girişle VOL ve VOH ölçümü

Altıncı adımda aynı teori uygulamaya geçirilir. Kare dalga kaldırılır, girişe DC olarak iki farklı ayrık değer verilir ve çıkış gözlenir. Çıkışta alınabilecek en düşük gerilim $V_{OL}$ (output low voltage), en yüksek gerilim $V_{OH}$ (output high voltage) olarak gösterilir; asistan literatürde de bu adların kullanıldığını söyler. Her iki durumda devre çalışır hâldeyken çıkıştaki voltmetrenin okunduğu ekran görüntüsü konur.

$$V_{OL} = V_{out}\big|_{V_{in}=V_{in,\max}}, \qquad V_{OH} = V_{out}\big|_{V_{in}=V_{in,\min}}$$

Çıkışın bu iki değer arasında gidip gelmesine "logic swing" denir. Asistan, bu salınımın bir miktar sınırlı olduğunu, çıkışın beklendiği gibi tam 0'a ve tam maksimum değere ulaşmayabileceğini, ölçümle bunun tespit edildiğini söyler.

> **Hocanın vurgusu:** Maksimum gerilimi ölçerken voltmetrenin aralığı volt olarak kalabilir; ama minimum gerilimi en hassas şekilde okumak gerekir. $V_{OL}$ ölçümünde voltmetrenin ölçme aralığı (display range) mikrovolta alınmalıdır.

## 6. İkinci soru: bilinmeyen iki girişli kapının analizi

İkinci soru bir analiz sorusudur. Transistör kodlarıyla birlikte bir konfigürasyon verilir; bazı uçlar açıkta (yüzer durumda) bırakılmıştır ve her biri bir anlam taşır. Önce transistörlerin hangilerinin PMOS, hangilerinin NMOS olduğu kodlardan ve ok işaretlerinden belirlenir. Sonra açıkta kalan uçların giriş mi, toprak mı, çıkış mı, besleme mi olduğuna karar verilir. Devre iki girişlidir.

Devre Proteus'ta kurulur, besleme ve toprak bağlanır ve hangi ucun ne olduğu ekran görüntüsü üzerinde gösterilir. Amaç, ne olduğu bilinmeyen bir lojik kapının hangi lojik işlemi yaptığını ölçümle tespit etmektir. Asistan, birinci sorudaki eviricinin uç değerlerle test edilmesinin bu soru için bir ipucu olduğunu söyler: iki girişe verilecek gerilim değerleriyle dört durum oluşturulur, her durumda çıkış voltmetreyle okunur ve tablo doldurulur. Her durumda devre çalışır hâldeyken ekran görüntüsü alınır. Son olarak, elde edilen verilere dayanarak devrenin hangi lojik kapıyı gerçeklediği en fazla beş cümleyle gerekçelendirilir. Gerekçesiz yalnız kapı adını yazmak yeterli görülmez.

> **Ek bilgi (derste anlatılmadı):** İki girişli CMOS kapılarda NMOS'ların seri, PMOS'ların paralel bağlandığı yapı NAND; NMOS'ların paralel, PMOS'ların seri bağlandığı yapı NOR kapısını verir. Dört giriş kombinasyonu (00, 01, 10, 11) için ölçülen çıkışlar doğruluk tablosuyla karşılaştırılarak kapı belirlenir.

## 7. Oturumda çıkan sorunlar ve çözümleri

### 7.1 Çıkışta 4–5 V görülmesi

Birçok öğrenci girişi 0–5 V arasında değişirken çıkışın 4 ile 5 V arasında değiştiğini bildirdi.

**Soru:** Giriş 0 ile 5 V arasında değişiyor ama çıkış 4 ile 5 V arasında kalıyor; bu bir sorun mu? **Cevap:** Evet, sorun. Çıkışta görülebilecek minimum gerilim ($V_{OL}$) 4 V olamaz. Girişe maksimum değer verildiğinde çıkışta minimum değer görülmelidir; bu sırada transistörlerin durumuna problarla bakmak gerekir. Transistörlerin amacı çıkışı açıp kapayarak anahtarlamaktır; 4 V gibi yüksek bir değerin çıkışa nereden geldiği düşünülmelidir. NMOS yanlış seçilmiş olabilir.

Asistan sorunu yaşayan öğrencilerin ekranlarına baktıktan sonra hepsinde devrenin kesinlikle yanlış kurulduğunu, çıkışın düşük olması gereken durumda 4 V görülemeyeceğini söyledi. Hatanın kaynağı, internetteki referans devreden elemanlar alınırken PMOS ve NMOS'un yer değiştirmesiydi. Referans alınan devrede bağlanan noktalara dikkat edilmesi gerekir.

### 7.2 Çıkışta prob ya da voltmetre

**Soru:** Çıkışı okumak için prob mu voltmetre mi kullanılmalı? **Cevap:** Grafik çizdirmek için prob kullanılır. $V_{OL}$ ve $V_{OH}$ ölçümünde ise çıkışa voltmetre konur, çünkü en düşük ve en yüksek değer için aralık ayarı yapmak gerekir.

**Soru:** Düzeltilmiş devrede prob sıfır yerine $10^{-17}$ mertebesinde bir değer gösteriyor; kabul edilir mi? **Cevap:** Grafik adımında probun gösterdiği sayı önemli değildir, grafiğin doğru çıkması önemlidir. Hassas ölçüm gereken adımda voltmetre istenen aralıkta okunursa sorun olmaz.

### 7.3 Simülasyon süresi ve küçük değerler

Bir öğrenci grafiğin 0–5 aralığında farklı, 0–10 aralığında beklenen biçimde çıktığını söyledi. Asistan grafiğin 0'dan 50'ye kadar çalıştırılması gerektiğini, girişte gecikme olmadığı için başlangıçta sorun çıkmaması gerektiğini açıkladı; öğrenci soruda 50'yi 5 olarak okuduğunu fark etti. Başka bir öğrencinin $V_{OL}$ için okuduğu değerlerin 0–5 gibi büyük değerler olduğu görüldü; asistan $V_{OL}$'nin mikro düzeyinde olması gerektiğini, voltmetrenin mikrovolt aralığına alınması gerektiğini hatırlattı.

### 7.4 Analog analiz grafiğinde dik çizgi ve eğimli kenarlar

Oturum sonunda bir öğrenci analog analiz grafiğinde yalnız dik bir çizgi gördüğünü söyleyip ekranını paylaştı. Grafiğin varsayılan yatay ekseni yaklaşık 0–1 aralığındaydı (ekrandan, 02:25:00). Asistan grafiğin ayarlarında bitiş süresinin (stop time) 50 yapılmasını, probların sağ tık ve "Add Trace" ile grafiğe tek tek eklenmesini, sonra devrenin yeniden çalıştırılmasını önerdi. Sonuç görüldükten sonra kenarların eğimli kalması pulse kaynağındaki yükselme ve düşme zamanından kaynaklanıyordu: soruda bu zamanlar 100m olarak verilmişti ve kenarın yana eğilmesinin sebebi buydu.

## 8. PMOS ve NMOS sembollerini ayırt etme

Asistan, hataların hepsinin transistör tiplerinin karıştırılmasından kaynaklandığını görünce sembol okumayı herkese anlattı.

> **Hocanın vurgusu:** Elektronik dersini bitiren biri, iki transistör sembolünü gördüğünde hangisinin PMOS, hangisinin NMOS olduğunu söyleyebilmelidir.

MOSFET sembollerinin iki türlü gösterimi vardır: dört bacaklı ve üç bacaklı. Bu laboratuvarda kullanılan elemanlar dört bacaklı gösterimin birleştirilmiş sürümüdür.

- Elle çizimde PMOS'un gate tarafına içi boş küçük bir daire (bubble) konur. NMOS'ta bu daire yoktur. Bu, lojik devrelerde eviricinin çıkışındaki daireye benzer.
- Simülasyon programları bu daireyi koymayabilir. O zaman ok işaretine bakılır.
- Dört bacaklı sembolde ortadaki bacağın okuna bakılır: ok içeri doğruysa NMOS, dışarı doğruysa PMOS'tur.
- Üç bacaklı sembolde alttaki bacağın okuna bakılır. <!-- BELİRSİZ: asistan üç bacaklı sembol için yalnız "aşağı yönlü bir akış olması lazım" diyor; hangi yönün hangi tipe karşılık geldiği altyazıda net değil -->

Asistan ayrıca MOSFET'in aslında dört ucu olduğunu, dördüncü ucun body (gövde) ucu olduğunu belirtir. Bazı simülasyon programlarında bu uç ayrı bulunur; bu laboratuvarda kolaylık olsun diye body ucu içeride bağlanmış, üç ucu kullanılan sürüm seçilmiştir.

> **Ek bilgi (derste anlatılmadı):** Üç uçlu standart sembolde ok source ucuna konur ve akımın yönünü gösterir: NMOS'ta ok dışarı doğrudur (akım drain'den source'a akar), PMOS'ta içeri doğrudur. Dört uçlu sembolde ok body ucundadır ve p-n ekleminin yönünü gösterir; bu yüzden NMOS'ta içeri, PMOS'ta dışarı doğrudur. Birleştirilmiş sembolde body ile source birbirine bağlı çizilir.

## Örnek Sorular

Soru belgesi ekranda paylaşılmadığı için aşağıdaki sorular asistanın sözlü anlatımından kurulmuştur.

**Soru 1 (derste sözlü, 00:13:54–00:24:48):** CMOS teknolojisiyle bir evirici (NOT kapısı) tasarlayın. (a) Devreyi elle çizip giriş gerilimini, çıkış gerilimini, DC beslemeyi ve toprağı gösterin. (b) Devreyi Proteus'ta kurun; besleme, toprak ve giriş/çıkış problarını bağlayın. (c) Girişe kare dalga kaynağı bağlayıp özelliklerini (düşük ve yüksek gerilim, başlama zamanı, yükselme ve düşme zamanı, darbe genişliği, periyot) verilen değerlere göre ayarlayın. (d) Analog analiz grafiğinde giriş ve çıkışı 0–50 aralığında üst üste çizdirin. (e) Grafiği yorumlayın; girişin en düşük ve en yüksek olduğu durumlarda hangi transistörün on, hangisinin off olduğunu çizip açıklayın. (f) Girişe DC değerler vererek $V_{OL}$ ve $V_{OH}$ değerlerini voltmetreyle ölçün. <!-- BELİRSİZ: kare dalganın düşük seviyesi, periyodu ve besleme geriliminin değeri altyazıda sayı olarak geçmiyor; yüksek seviye 5 V, darbe genişliği 1 s, yükselme/düşme zamanı 100m olarak geçiyor -->

> **Çözüm (derste verilmedi):** PMOS kaynağı beslemeye, NMOS kaynağı toprağa bağlanır; gate'ler birleşip giriş, drain'ler birleşip çıkış olur. Giriş düşükken NMOS off, PMOS on olur ve çıkış beslemeye bağlanır: $V_{out} \approx V_{DD}$, bu $V_{OH}$'dir. Giriş yüksekken PMOS off, NMOS on olur ve çıkış toprağa bağlanır: $V_{out} \approx 0$, bu $V_{OL}$'dir. Grafikte giriş yüksekken çıkış düşük, giriş düşükken çıkış yüksek olduğu için devre eviricidir. Doğru kurulmuş devrede $V_{OL}$ pratikte sıfırdır (oturumda bir öğrenci $10^{-17}$ mertebesinde bir değer okudu); bu yüzden mikrovolt aralığında okunur. Çıkışta 4 V gibi bir düşük seviye görülüyorsa PMOS ve NMOS yer değiştirmiştir.

**Soru 2 (derste sözlü, 00:24:51–00:28:09):** Uçları açıkta bırakılmış, iki girişli bir MOSFET devresi veriliyor. (a) Transistörlerin PMOS mu NMOS mu olduğunu ve açık uçların giriş, çıkış, besleme ya da toprak olduğunu belirleyip devreyi Proteus'ta kurun. (b) İki girişe dört farklı gerilim kombinasyonu uygulayıp çıkışı voltmetreyle okuyun ve tabloyu doldurun. (c) Devrenin hangi lojik kapıyı gerçeklediğini elde ettiğiniz verilere dayanarak en fazla beş cümleyle açıklayın. <!-- BELİRSİZ: devre şekli ekranda gösterilmediği için kapının bağlantıları ve cevabı bilinmiyor; çözüm yazılmadı -->

## Dersin Toparlaması

Bu laboratuvar, MOSFET'in anahtar olarak kullanıldığı en basit uygulamayı, CMOS lojik kapıları ele aldı. CMOS'un bir transistör tipi değil PMOS ve NMOS'un birlikte kullanıldığı bir konfigürasyon olduğu, eviricide girişe göre transistörlerden birinin açılıp diğerinin kapanarak çıkışı beslemeye ya da toprağa bağladığı vurgulandı. Gerilim transfer karakteristiğinden $V_{OL}$ ve $V_{OH}$ kavramları ve çıkışın uç değerlerinin ölçülmesi, kare dalga kaynağının parametreleri ve Proteus'ta analog analiz grafiğinin kullanımı uygulamalı olarak görüldü. İkinci soruda aynı mantık, bilinmeyen iki girişli bir kapının doğruluk tablosunu ölçerek belirlemeye uygulandı.

Oturumda en sık yapılan hata PMOS ile NMOS'un karıştırılmasıydı. Bu nedenle sembolleri ayırt etme kuralı (elle çizimde gate tarafındaki daire, simülasyonda body okunun yönü) ve MOSFET'in dört uçlu bir eleman olduğu ayrıca anlatıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
