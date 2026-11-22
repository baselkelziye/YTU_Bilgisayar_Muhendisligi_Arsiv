# Ders 3 Genişletilmiş Notu: Sensörler ve Eyleyiciler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Analogdan dijitale: sensör ve eyleyicilerin yeri
- 2. Dönüştürücüler
- 3. Sensör performansının tanımlanması
- 4. Sensör türleri
- 5. Sensörlerin devreye bağlanması
- 6. Eyleyiciler
- 7. Laboratuvar ölçü aletleri
- 8. Veri sayfası okuma: LM35 örneği
- Örnek Sorular
- Dersin Toparlaması

## 1. Analogdan dijitale: sensör ve eyleyicilerin yeri

Önceki derste analog sinyal kavramı ele alınmıştı: gündelik hayattaki fiziksel ölçümler sürekli (continuous) değişen analog büyüklüklerdir. Elektronik sistemlerde bu sinyalleri işlemek için onları dijitalleştirmek gerekir. Hoca bunu bir klima termostatı örneğiyle hatırlattı: ortam soğuyunca ısıtmayı, ısınınca soğutmayı açan bir kontrol kartı sürekli ve ani değişebilen bir analog sinyal üzerinden doğrudan karar vermeye çalışırsa, sinyaldeki ani (abrupt) değişimler kontrol mekanizmasında anlamsız açma kapamalara yol açabilir.

Bu derste, fiziksel ölçümleri elektriksel ve dijital forma getiren devre elemanlarına, yani **sensörlere**, ve tersine, elektriksel/dijital bir komutu fiziksel dünyada bir etkiye çeviren **eyleyicilere** (actuator) bakılır. Dersin ana başlıkları ekranda şöyle verildi (ekrandan, 00:05:00): giriş, sensör performansının tanımlanması, sensörler, eyleyiciler ve laboratuvar ölçü aletleri. Hoca, bu iki haftalık girişin dönem projesinde kullanılacak sensörleri anlamaya yönelik olduğunu, yarı iletkenlerin ise dersin asıl konusu olarak sonraki haftalarda başlayacağını belirtti.

## 2. Dönüştürücüler

Sensörler ve eyleyiciler daha genel bir sınıfın, **dönüştürücülerin** (transducer) örnekleridir. Ekrandaki tanım şöyledir (ekrandan, 00:20:00):

> *A transducer is a device that converts one physical quantity into another.* (Dönüştürücü, bir fiziksel niceliği başka bir niceliğe çeviren aygıttır.)

Hoca iki örnek verdi:

- **Cıvalı cam termometre:** Sıcaklık arttıkça cıva genleşir ve sütun yükselir. Böylece sıcaklık, cıva sütununun yer değiştirmesine çevrilir; bir birim başka bir birime dönüştürülmüş olur.
- **Mikrofon:** Sesi elektriksel sinyale çevirir ve bilgisayara aktarılmasını sağlar.

Bu derste dönüştürücülerin iki alt sınıfı incelenir: fiziksel büyüklüğü elektriksel forma çeviren sensörler (algılayıcılar) ve elektriksel sinyali fiziksel bir niceliğe (hareket, ısı, ışık) çeviren eyleyiciler, örneğin motorlar.

## 3. Sensör performansının tanımlanması

Piyasada aynı büyüklüğü ölçen çok sayıda sensör vardır: sıcaklık, basınç, yağmur sensörleri gibi ana başlıkların her birinin altında birçok farklı model bulunur. Hangi modelin seçileceği, uygulamanın ihtiyacına ve sensörün performans ölçütlerine bağlıdır. Hoca örnek olarak, 0-15 derece arası ölçüm yeterliyse bir markanın, çok yüksek sıcaklıklarda (örneğin 270 °C civarında) ölçüm gerekiyorsa başka bir sensörün seçilmesi gerektiğini söyledi.

### 3.1 Aralık (range)

Aralık, sensörün ölçebildiği en küçük ve en büyük değer arasındaki bölgedir ve sensörün kullanım yerini belirler. 20 °C'de bozulan bir sensörle 300 °C'deki sıcaklık değişimleri gözlenemez. Hocaya göre aralık genişledikçe hassasiyet genellikle düşer.

### 3.2 Çözünürlük (resolution)

Çözünürlük, sensörün ayırt edebildiği en küçük değişimdir. Hoca tartı örneğini verdi: evlerdeki mutfak tartıları gram düzeyinde ölçer, yani çözünürlükleri yüksektir. Kargo şirketlerindeki büyük kantarların çözünürlüğü düşüktür; orada amaç büyük yükleri ölçebilmek, yani aralığın geniş olmasıdır.

### 3.3 Hata (error) ve doğruluk (accuracy)

Hata, gerçek değer ile ölçülen değer arasındaki farktır. Hoca kendi gündelik örneğini verdi: 10 kg olduğu bilinen bir paket kargo kantarına konduğunda 9,7 kg okunuyor. Bu fark kantarın hatasından kaynaklanabilir.

- Verilen: gerçek değer 10 kg, ölçülen değer 9,7 kg.
- Mutlak hata: $10 - 9{,}7 = 0{,}3$ kg (ara adım eklendi).
- Bağıl hata: $0{,}3 / 10 = \%3$ (ara adım eklendi).

Hiçbir sensör %100 başarılı, yani sıfır hatalı üretilemez. Bu yüzden **kabul edilebilir hata payı** devreye girer: "±%1'e kadar hata benim işimi görür" denebilir ve bu değer sensörün özelliklerinde bir performans ölçütü olarak verilir.

Doğruluk hatanın tersidir. Hoca bunu $\text{doğruluk} = 1 - \text{hata}$ diye ifade etti: %97 doğruluk, %3 hata demektir.

### 3.4 Kesinlik (precision)

Kesinlik, aynı büyüklük aynı sensörle tekrar tekrar ölçüldüğünde sonuçların birbirine ne kadar yakın olduğudur; yani sensörün tutarlılığıdır. Hoca ekrandaki hedef tahtası şeklini anlattı (ekrandan, 00:25:00 civarı slayt listesinde "Error, Accuracy, and Precision"):

- Ölçümler merkezden (gerçek değerden) uzak ve dağınıksa: doğruluk düşük, kesinlik düşük.
- Ölçümler merkezden uzak ama bir noktada kümelenmişse: doğruluk düşük (her ölçüm hatalı), kesinlik yüksek (kendi içinde tutarlı).

İstenen sensör hem doğruluğu hem kesinliği yüksek olandır: ölçtüğü değer gerçeğe yakın olmalı ve her ölçüm aynı sonucu vermelidir. Maliyet nedeniyle doğruluktan bir miktar ödün verilebilir (örneğin %1 hata kabul edilebilir), ama kesinlik de düşükse sensör her seferinde farklı bir hatalı değer okur.

> **Hocanın vurgusu:** Kesinliğin düşük olması, doğruluğun düşük olması kadar kötüdür. En çok istenen sistem yüksek kesinlik ve yüksek doğruluk sağlayan sistemdir.

Hoca bu bölümde ADC ve DAC'ye de değindi: ADC (analog-dijital dönüştürücü) analog sinyali dijital hale getirir. Sensörlerin çoğu iç yapısında bir ADC modülü barındırır; örneğin bir sıcaklık sensörü ölçtüğü sıcaklığı gerilim olarak verir.

### 3.5 Doğrusallık (linearity) ve duyarlılık (sensitivity)

Ekrandaki tanımlar şöyledir (ekrandan, 00:30:00):

- **Doğrusallık:** gerçek tepkinin bir doğru tepkisinden ("en iyi uyan doğru") en büyük sapması.
- **Duyarlılık:** ölçülen büyüklükteki belli bir değişim için çıkışta oluşan değişimin ölçüsü.

Hoca doğrusallığı bir basınç sensörü üzerinden anlattı. Sensörün çıkışı gerilimdir ve basınç arttıkça çıkış gerilimi artar. Doğrusal sistemleri kurmak daha kolaydır, çünkü çıkış basit bir kuralla girişe çevrilebilir. Tahtada iki nokta işaretlendi (birim seçimi sırasında bir öğrenci "bar" önerdi):

- Verilen: 2,2 bar'da çıkış 3 V, 5 bar'da çıkış 6,2 V (hoca önce 5,8 dedi, sonra 6,2 olarak düzeltti).
- Bu iki noktadan geçen doğrunun eğimi: $\dfrac{6{,}2 - 3}{5 - 2{,}2} = \dfrac{3{,}2}{2{,}8} \approx 1{,}14$ V/bar (ara adım eklendi).

Gerçek sensörde ise üretim malzemesinin kalitesi ya da iç yapıdaki yalıtımın yetersizliği nedeniyle basınç (ya da sıcaklık) arttıkça çıkış doğrunun altına düşme eğilimi gösterebilir; ekrandaki "Actual" eğrisi "Best Fit Line" doğrusunun altında kalır. Büyüklük çok artırılırsa çıkış neredeyse sabit bir değere yaklaşabilir. Bu sapma sensör performansını olumsuz etkiler.

Hoca, performans ölçütlerinin fiyata etkisini bir örnekle anlattı: avuç içi büyüklüğünde, endüstriyel ölçekte sıcaklık ölçen çok pahalı bir sensör ile tırnak büyüklüğünde, birkaç liralık LM35 entegresi aynı büyüklüğü ölçer; aradaki büyük fark iç yapıdan ve bu performans ölçütlerinden kaynaklanır.

## 4. Sensör türleri

### 4.1 Fiziksel ilkeye göre sınıflandırma

Hoca en çok kullanılan sensör türlerini şöyle sıraladı:

- **Dirençsel (resistive):** Fiziksel koşullara göre iç direnci artan ya da azalan, böylece gerilim değişimi üreten sensörler.
- **Endüktif:** Fiziksel etkiyle iç yapısında akım depolanması ya da akım yönünün değişmesi oluşan sensörler.
- **Kapasitif:** Fiziksel etkiyle içinde gerilim (yük) birikmesi oluşan sensörler.
- **Piezoelektrik:** Üzerine basınç uygulandığında iç yapısı nedeniyle basıncı elektriğe çeviren sensörler.
- **Fotorezistif:** Işık enerjisine göre direnci değişen sensörler.
- **Elastik (gerinim ölçer, strain gauge):** Basınç ya da gerilmeyle ilgili sensörler.
- **Termal:** Sıcaklıkla değişen sensörler.

### 4.2 Sıcaklık sensörleri

**Dirençli termometreler** (ekrandan, 00:35:00): Tipik olarak platin tel kullanılır; bu aygıtlara platin dirençli termometre (PRT) denir. Doğrusaldır ama duyarlılığı düşüktür. Ekranda ince film, tel sargılı ve bobin elemanlı PRT türleri görülür. Hoca, uzun ve ince, dayanıklı metal kılıflı bu sensörlerin daha çok fabrikalarda bir sıvının sıcaklığını ölçmek için kullanıldığını, endüstride doğrusallığın gündelik hayattan daha önemli olduğunu söyledi. Kılıfın içinde sıcaklıkla direnci değişen tel sargıları vardır.

Direncin nasıl değiştiğini açıklamak için hoca devre teorisinden bilinen bağıntıyı hatırlattı:

$$R = \rho \frac{L}{A}$$

Burada $\rho$ kullanılan metalin özdirenci (alüminyum, bakır gibi her metal için farklı), $L$ telin boyu, $A$ kesit alanıdır. Sıcaklıkla boyu uzayan bir malzemede direnç artar; sıcaklıkla kesit alanı hızla büyüyen bir malzemede direnç azalır.

> **Ders sonrası not:** Hoca, direnç artınca gerilimin "ters mantıkla" düşeceğini, direnç azalınca da sensör üzerine düşen gerilimin artacağını söyledi. Bu, sensörün devrede nasıl bağlandığına bağlıdır. Dersin ilerleyen kısmında gösterilen gerilim bölücüde (sensör alt kolda, bkz. Bölüm 5.1) sensör direnci arttıkça üzerindeki gerilim artar, azaldıkça düşer.

**Termistörler** de aynı mantıkla çalışır; daha küçüktür, sanayi yerine gündelik basit devrelerde sık kullanılır. Doğrusal değildir ve hocaya göre çabuk bozulabilen elemanlardır.

**pn eklem sensörleri** (ekrandan, 00:40:00): Diyot özelliği gösteren bir yarı iletken aygıttır (yarı iletkenler ve diyotlar ileride ele alınacak). Ucuz, doğrusal ve kullanımı kolaydır. Yarı iletken malzemenin doğası gereği sıcaklık aralığı sınırlıdır; ekranda "belki $-50$ °C ile $150$ °C" yazar. Hoca bu tür sensörlerin projelerde sık karşılaşılacak LM35 gibi elemanlar olduğunu, en büyük sınırlamalarının çok yüksek sıcaklıklara çıkamamak olduğunu söyledi.

### 4.3 Işık sensörleri

Işık sensörleri gündelik hayatta sık görülür: merdiven otomatiği (yeni tip otomatlarda) ya da akşam olunca sokak lambalarının kendiliğinden yanması bu tür sensörlerle yapılabilir. Ekrandaki ilk tür **fotovoltaik** sensördür (ekrandan, 00:45:00):

- Bir pn eklemine düşen ışık, ışık enerjisinden elektrik üretmek için kullanılabilir (güneş pilinde olduğu gibi).
- Sensör olarak kullanılan küçük aygıtlara **fotodiyot** denir.
- Hızlı tepki verir, ama üretilen gerilim ışık şiddetiyle doğrusal ilişkili değildir.

Hoca ikinci türü de anlattı: düşen ışıkla iletkenliği, dolayısıyla direnci değişen bir yapı. Devreden geçen akım bu dirençten geçerken ışığa göre değişir.

### 4.4 Basınç (gerinim) sensörleri

Hoca bilinen bir örnek verdi: araçta emniyet kemeri takılmadığında uyarı sesi veren koltuğun altındaki eleman. Bu sensörler üzerinde bir baskı olup olmadığını tespit eder. Üzerine yük binince eleman gerilir ya da bükülür; içindeki iletken yolların birbirine yakınlığı değişir ve dirençsel etki değişir. Sonuçta fiziksel bir etki elektriksel bir sinyale dönüştürülmüş olur.

### 4.5 Anahtarlar ve opto-anahtarlar

Anahtarlar tam anlamıyla sensör sayılmasa da konum değişikliğini elektriksel olarak kullanılabilir hale getirdikleri için bu başlıkta ele alınır. **Opto-anahtarlar** (ekrandan, 01:10:00 civarında da aynı slayt görünüyor) bir ışık kaynağı ile bir ışık sensörünü tek gövdede birleştirir. İki yaygın türü vardır: yansımalı (reflective) ve yarıklı (slotted).

- Hoca asansör kapısını örnek verdi: bir tarafta ışık kaynağı (lazer gibi), karşıda alıcı vardır. Işın kesilmezse kapı birkaç saniye sonra kapatılır; araya bir şey girince devre kendini sıfırlar ve kapıyı kapatmama sinyali üretir. Böylece sıkışma önlenir.
- Yansımalı opto-anahtarda kaynaktan çıkan ışık karşıdaki yüzeyden yansıyıp sensöre döner; okuma buna göre yapılır.

### 4.6 Yer değiştirme sensörleri: kodlayıcılar

Kodlayıcıda (encoder) şeritli bir yüzey ve bu yüzeyin üzerinde sensörler vardır. Şeritler sensörün altından geçtikçe okunan dizi bir anlam taşır; barkod okumaya benzer. Ekrandaki **artımlı konum kodlayıcı** (incremental position encoder) şöyle tanımlanır (ekrandan, 00:50:00):

- Siyah/beyaz değişen tek bir şerit kullanır.
- Birbirine göre hafifçe kaydırılmış iki sensör, şekildeki gibi kare dalga çıkışlar üretir.
- Her iki yöndeki hareket algılanır; darbeler sayılarak mutlak konum bulunur (konum başlangıçta sıfırlanmalıdır).

Şekilde soldan sağa harekette Sensör 1 ile Sensör 2'nin dalgaları arasındaki faz ilişkisi, sağdan sola harekette tersine döner. Hoca bu yapının motor dönüşünü izlemek için kullanılabildiğini anlattı.

### 4.7 Hareket sensörleri

Hoca robotikte çok kullanılan IMU'dan ve GPS modüllerinden söz etti. <!-- BELİRSİZ: Hoca IMU'yu "yeryüzündeki manyetik etkiyi hareketle kestiğimizi tespit edip hız verisi veren" bir sensör olarak anlattı; altyazıdan ayrıntı net çıkmıyor. -->

> **Ek bilgi (derste anlatılmadı):** IMU (eylemsizlik ölçüm birimi) büyük olasılıkla ivmeölçer ve jiroskoptan, bazen de manyetometreden oluşur; ivme ve açısal hız ölçer, hız ve konum bu ölçümlerden hesapla elde edilir.

Hoca bu bölümde yüksek frekanslı sinyallerle ilgili bir uyarı yaptı: frekans yükseldikçe sinyal gürültüden daha kolay etkilenir. FM vericide yayın megahertz düzeyindedir (örneğin 88,8 MHz); havadan sinyale binen gürültü yüzünden ev ortamında müzik o kanaldan duyulamayabilir. Bu tür devrelerde iyi yalıtım gerekir, bu da ev ortamında, bilgisayar ve monitörün oluşturduğu alanların yanında zordur. Kızılötesi uzaktan kumanda daha az sorunludur, ama radyo frekanslı uzaktan kumanda gürültüden kolayca etkilenir.

> **Hocanın vurgusu:** Projede yüksek frekans içeren devrelerden (FM verici, RF uzaktan kumanda) kaçının.

> **Ders sonrası not:** Hoca GPS sinyali için 900 MHz ile 1800 MHz arası değerler söyledi. Bu değerler büyük olasılıkla GSM bantlarıdır; sivil GPS L1 sinyali büyük olasılıkla 1575,42 MHz'tir.

### 4.8 Mikrofon

Mikrofon bir ses sensörüdür. Ses dalgaları kulak zarına benzer bir zarı titretir; bu titreşim elektronik tasarımda elektriksel bir sinyal olarak yorumlanır.

## 5. Sensörlerin devreye bağlanması

### 5.1 Dirençsel sensörler: gerilim bölücü

Hoca, sensörlerin devrede aslında devrenin gerilimini (ya da akımını) değiştiren elemanlar olduğunu vurguladı. Ekrandaki devre şöyledir (ekrandan, 00:55:00): $V$ kaynağına bağlı üstte sabit bir $R_1$ direnci, altta $0$ V'a bağlı sensör $R_s$; çıkış $V_o$ iki direncin birleşim noktasından alınır.

Ekrandaki açıklamaya göre dirençsel aygıtlar çok basit kullanılabilir: potansiyometrede dış uçlara sabit gerilim uygulanırsa üçüncü uçtaki gerilim konumla doğrudan ilişkilidir. Direnci ölçülen büyüklükle değişen bir aygıtta bu değişim, gerilim bölücüyle bir gerilim sinyaline çevrilir. Bu düzenin çıkışı direnç değişimiyle doğrusal ilişkili değildir.

Gerilim bölücü bağıntısı (ara adım eklendi):

$$V_o = V \frac{R_s}{R_1 + R_s}$$

Hoca örnek olarak bir alkış devresini verdi: alkışla sensörün direnci değişir, $V_o$ değişir, bu değişim bir LED'i yakmak gibi bir işe dönüştürülür.

Hoca potansiyometreyi de hatırlattı: üç bacaklı, çevrilebilen bir elemandır. Örneğin üzerinde 10K yazıyorsa dış iki bacak arasında 10 kΩ vardır; orta bacak kullanıldığında çevirme miktarına göre bu değerin bir kısmı devreye girer. Sensörler de aynı mantıkla, ayarlı direnç (reosta) gibi kullanılır. Devrede kontrol edilen şey ya gerilim ya akımdır; ikisi de aynı değişimi ifade eder.

> **Hocanın vurgusu:** Sensörleri gerilim bölücü (potential divider) yapısında kullanacağız. Projede sensörün devrede ne yaptığını bu kavramlarla yorumlamanız beklenir.

### 5.2 Anahtarlar ve anahtar sıçraması

Ekrandaki ikinci devrede sensör bir anahtardır (ekrandan, 01:00:00): $V$ ile $0$ V arasında üstte bir direnç, altta anahtar vardır; çıkış aradan alınır. Ekrandaki notlara göre anahtar arayüzü de basittir, tek bir dirençle gerilim çıkışı elde edilir ve bütün mekanik anahtarlarda **anahtar sıçraması** (switch bounce) görülür.

- Anahtar açıkken dirençten akım geçmez, $V_o = V$ olur.
- Anahtar kapanınca akım kolay yoldan akar ve $V_o$ sıfıra iner.

**Soru:** Anahtar kapandıktan sonra gerilim neden salınarak düşüyor (sağdaki grafik)?
**Cevap:** Hoca buna sıçrama (debounce) etkisi dendiğini söyledi. Grafikteki zaman ekseni çok kısa bir aralığı gösterir; hoca tahtaya örnek olarak 5 ile 5,0001 gibi iki an yazdı. Anahtar kapandığı anda hemen sıfır dirençli bir kısa devre oluşmaz; hocaya göre iki hattı üst üste getiren fiziksel yapının bir direnci olduğu için kısa bir süre kaçak akımlar oluşur ve çıkış salınır. Fiziksel basma etkisi geçince çıkış sıfırda kalır. Bu salınımı yazılımsal ya da donanımsal olarak bastırma yöntemleri başka derslerde ele alınacaktır.

> **Ders sonrası not:** Anahtar sıçramasının nedeni büyük olasılıkla mekanik kontakların kapanırken fiziksel olarak birkaç kez sekmesidir; hocanın söylediği iç direnç ve kaçak akım açıklaması bu olgunun temel nedeni değildir.

### 5.3 Kapasitif ve endüktif sensörler

Kapasitif ve endüktif sensörler (ve selenoid gibi elemanlar) daha çok alternatif akım (AC) devrelerinde kullanılır. Hoca DC ile AC'yi hatırlattı: doğru akım zaman içinde hep aynı seviyededir; alternatif akımda gerilim her an farklıdır ve $+V$ ile $-V$ arasında salınır. Kapasitör ve bobin, akım ya da gerilimin yönüne göre şarj ve deşarj olur; bu yüzden bu sensörler genelde AC yapıda çalışır. AC devre analizi ileride görülecektir.

## 6. Eyleyiciler

Eyleyiciler sensörlerin tersidir: elektriksel sinyali fiziksel bir eyleme dönüştürür. Hocanın örnekleri:

- **Kapı açma:** Diyafonlu apartman kapısında düğmeye basınca elektriksel sinyal mekanik kilidi tetikler.
- **Isı:** Isıtıcılarda elektrik akımı yüksek dirençli bir elemandan geçerken ısı enerjisine dönüşür.
- **Işık:** Ampuller, LED'ler (içinde yarı iletken bulunan ışık yayan elemanlar), sıvı kristal ekranlar (sıvının elektriksel olarak tetiklenmesi). <!-- BELİRSİZ: Hoca floresan lambaların çalışmasının daha yavaş olduğunu ve "daha sağlıklı" olduğunu söyledi; altyazıda gerekçe net değil. -->
- **Fiber optik iletişim:** Uzun mesafede iletim kaybını azaltmak için elektriksel sinyal ışığa çevrilir, cam ya da polimer kablodan gönderilir, karşı tarafta bir sensör ışığı tekrar elektriksel sinyale çevirir. Ekrana göre polimer kablolar yaklaşık 20 m'ye kadar, cam kablolar yüzlerce kilometreye kadar kullanılabilir; cam kablolar daha pahalıdır.

### 6.1 Selenoidler

Ekrandaki tanım (ekrandan, 01:05:00):

- Temelde bir bobin ve ferromanyetik bir çekirdekten (slug) oluşur.
- Enerji verildiğinde çekirdek bobinin içine çekilir.
- Kuvvet akımla orantılıdır.
- Kuvvet, yer değiştirme ya da hareket üretebilir; doğrusal ya da açısal olabilir.
- Çoğu zaman açık/kapalı (ON/OFF) modunda kullanılır.

### 6.2 Motorlar

Hoca üç ana motor türünden söz etti: AC motorlar, DC motorlar ve adım (step) motorları. <!-- BELİRSİZ: Hocanın AC ve DC motor karşılaştırması altyazıda karışık (AC motorun faz bilgisi gerektirdiği ve yüksek güç için kullanıldığı, DC motorların küçük devrelerde kullanıldığı anlaşılıyor). -->

**Adım motorları** açısal konumu kontrol etmek için kullanılır. Sargılara elektrik verildiğinde ortadaki manyetik rotor o sargıya doğru çekilir. Tam bir dönüş için sargılara sırayla (A, B, C, A, B, C, ...) gerilim verilir; bu, Arduino gibi bir programlama kartında bir döngü içinde pinlere sırayla 5 V vererek yapılabilir. <!-- BELİRSİZ: Hoca adım açısı için "minimum 12 derecelik açılar" gibi bir değer söyledi; altyazıda net değil. -->

Hoca bir robot kolu örneği verdi: bir su ibriği aşağı dönüp çiçekleri sulayacak, sonra suyun akmaması için yukarı dönecek. Açısal konum bilgisi olmayan bir motorla ibriğin o an yukarı mı aşağı mı baktığı bilinemez. Hoca araç cam sileceklerini de örnek verdi: silecek her seferinde aynı noktalar arasında hareket eder, bu da açısal konumun kontrol edilmesiyle sağlanır.

> **Ders sonrası not:** Hoca bu örneklerde adım motoru ile servo motoru ("sistem motor" diye geçen) birlikte andı. Cam silecekleri büyük olasılıkla bir DC motor ve mekanik bağlantı/durma anahtarıyla çalışır; açısal konum kontrolü için adım ve servo motorlar kullanılır.

### 6.3 Ses eyleyicileri

En bilinen ses eyleyicisi hoparlördür. **Ultrasonik** dönüştürücüler robotikte ve araçların park sensörlerinde kullanılır: biri gönderici, biri alıcı olan iki yuvarlak elemanı vardır. Gönderilen ses dalgası karşıdaki duvara çarpıp yansır; yansıyan dalganın dönüşüne bakılarak mesafe hesaplanır. Bu, aynı gövdede bir hoparlör ve bir mikrofon varmış gibi düşünülebilir. Mesafe ölçümü için ışık yansımasını kullanan sistemler de vardır.

## 7. Laboratuvar ölçü aletleri

Multimetre (avometre), ampermetre, voltmetre gibi aletler devreden geçen akım ya da gerilimi sayısal bir ekranda gösterir. Dalga biçimi vermez; en fazla akımın ya da gerilimin ters yönde olduğunu gösteren bir eksi işareti koyar. Analog ölçü aletlerinin içinde bakır tel ya da levhanın elektriksel olarak yüklenmesine dayalı bir yapı vardır.

**Osiloskop** devredeki sinyalleri ölçmeye yarayan, ama çok daha ayrıntılı ve hassas analiz yapılabilen bir ölçü aletidir. Ekranında bir koordinat düzlemi vardır; ayarlar değiştirilmediyse dikey eksen gerilimi, yatay eksen zamanı gösterir. Ekrandaki ölçek çizgilerine göre gerilim değerleri okunabilir. Osiloskopta sinyalin DC mi AC mi olduğu ve dalga biçimi rahatça görülür. Analog osiloskopta her şey elle ayarlanırken dijital osiloskopta dalga biçimi ve ölçüm değerleri ekranda sayısal olarak verilir; simülasyon ortamındaki osiloskop da dijital olanın bir benzeridir.

> **Hocanın vurgusu:** Osiloskop, elektronik dersinde mutlaka öğrenilmesi istenen ölçü aletidir; hocaya göre öğrencilerin en zor öğrendiği alettir.

## 8. Veri sayfası okuma: LM35 örneği

Dersin sonunda hoca, performans ölçütlerinin gerçek bir sensörde nasıl okunduğunu göstermek için LM35 sıcaklık sensörünün veri sayfasını (datasheet) açtı. Veri sayfası, elektronik ve lojik devre tasarımında ilk bakılacak belgedir: bozuk bir kartta bir entegrenin adı okunduğunda ilk iş onun veri sayfasını açmaktır. Hoca veri sayfasını sensörün "kimlik kartı" olarak niteledi.

Ekrandaki veri sayfasında (National Semiconductor, LM35 Precision Centigrade Temperature Sensors, 13 sayfa) "Features" bölümü şöyledir (ekrandan, 01:20:00 ve 01:25:00):

- Doğrudan Celsius (santigrat) cinsinden kalibre edilmiştir.
- Doğrusal, $+10{,}0$ mV/°C ölçek çarpanı.
- $+25$ °C'de $0{,}5$ °C doğruluk garanti edilebilir.
- $-55$ °C ile $+150$ °C arasının tamamı için derecelendirilmiştir.
- Uzaktan uygulamalara uygundur; düşük maliyet (pul düzeyinde kalibrasyon).
- 4 ile 30 V arasında çalışır.
- 60 µA'dan az akım çeker; durgun havada kendi kendini ısıtması $0{,}08$ °C'dir.
- Doğrusalsızlık tipik olarak $\pm 1/4$ °C'dir.
- Düşük çıkış empedansı: 1 mA yükte $0{,}1\ \Omega$.

Hocanın bu verilerden çıkardığı yorumlar:

- **Aralık:** $-55$ °C ile $+150$ °C. (Slaytta pn eklem sensörü için yazan yaklaşık değerle uyumlu.)
- **Doğrusallık:** 10 mV/°C; sıcaklık bir derece arttıkça çıkış 10 mV artar.
- **Besleme:** 4-30 V. Girişe 40 ya da 50 V verilen bir devrede bu sensör çalışmaz, dolayısıyla böyle bir devre için uygun değildir.
- **Doğruluk:** Oda sıcaklığında belli bir artı/eksi sapma verilmiştir. <!-- BELİRSİZ: Hoca doğruluk değerini "artı eksi %2", "%5'lere kadar" gibi okudu; altyazı net değil. Ekranda $+25$ °C'de $0{,}5$ °C garanti, tipik ±1/4 °C (oda sıcaklığı) ve ±3/4 °C (tam aralık) yazar. -->

> **Ders sonrası not:** Hoca doğrusallığı "0'da 10, 1'de 20" diye örnekledi. 10 mV/°C ölçek çarpanıyla çıkış 0 °C'de 0 mV, 1 °C'de 10 mV'tur.

Veri sayfasının tam aralık devresinde (Figure 2) çıkış değerleri ekranda şöyle verilir: $150$ °C'de $+1500$ mV, $25$ °C'de $+250$ mV, $-55$ °C'de $-550$ mV. Bu değerler $V_{out} = 10\ \text{mV/°C} \times T$ ile tutarlıdır (python ile doğrulandı):

- $10 \times 150 = 1500$ mV
- $10 \times 25 = 250$ mV
- $10 \times (-55) = -550$ mV

**Soru:** Bu derste hangi sensörün hangi işi yaptığını mı bilmemiz gerekiyor, yoksa genel olarak sensörleri tanımak mı amaç?
**Cevap:** Sensörleri ezberlemeye gerek yok; bir sensörün veri sayfası okunduğunda ne işe yaradığı anlaşılmalı. Örneğin LM35'in sıcaklık sensörü olduğu, aralığı, doğruluğu ve diğer performans değerlerinin nasıl yorumlanacağı bilinmelidir.

**Soru:** Sensörler aralığın dışına çıktıklarında ölçüm mü yapmıyorlar, yoksa bozuluyorlar mı?
**Cevap:** Bozulurlar (breakdown). Bu her sensör için aynı değildir: pahalı sensörlerin içinde bir sigorta olur ve aşırı durumda sigorta atarak sensörü korur. LM35 gibi ucuz sensörler ise fazla akımda yanabilir; hoca projede kullanılacaksa birkaç yedek alınmasını önerdi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:59:08; devre ekrandan, 01:00:00): Bir anahtar, $V$ kaynağına bağlı bir direncin altına sensör olarak bağlanmıştır ve çıkış $V_o$ ikisinin birleşim noktasından alınmaktadır. Anahtar kapandığında $V_o$ neden hemen sıfıra inmeyip kısa bir süre salınır?

> **Cevap (derste verildi):** Anahtar açıkken $V_o = V$, kapandığında $V_o \to 0$ olur. Kapanma anında çıkış çok kısa bir süre (grafikte 5 ile 5,0001 gibi iki an arası) birkaç kez salınır; buna anahtar sıçraması (switch bounce) denir. Hoca bunu kapanma anında kontağın hemen sıfır dirençli olmamasına bağladı. Büyük olasılıkla asıl neden mekanik kontakların fiziksel olarak sekmesidir (bkz. Bölüm 5.2).

**Soru 2** (derste sözlü, 01:24:09): Bir sensör aralığının dışına çıktığında ne olur?

> **Cevap (derste verildi):** Sensör bozulabilir (breakdown). Pahalı sensörlerde koruma sigortası bulunur; ucuz sensörler fazla akımda yanabilir.

**Soru 3** (ekrandan, 01:20:00; hocanın derste gösterdiği veri sayfası okuma örneği): LM35 veri sayfasından aralık, ölçek çarpanı, doğruluk ve besleme gerilimi bilgilerini çıkarın; $25$ °C ve $150$ °C'de beklenen çıkış gerilimini hesaplayın.

> **Cevap (derste kısmen verildi, hesap eklendi):** Aralık $-55$ °C ile $+150$ °C; ölçek çarpanı $+10{,}0$ mV/°C; $+25$ °C'de $0{,}5$ °C garanti doğruluk; besleme 4-30 V. Çıkış: $25$ °C'de $10 \times 25 = 250$ mV, $150$ °C'de $10 \times 150 = 1500$ mV (veri sayfasındaki değerlerle aynı; python ile doğrulandı).

## Dersin Toparlaması

Bu derste fiziksel dünya ile elektronik sistemler arasındaki köprüyü kuran dönüştürücüler ele alındı. Sensörler fiziksel büyüklükleri elektriksel sinyale, eyleyiciler elektriksel sinyalleri fiziksel etkilere çevirir. Bir sensörü seçerken bakılacak performans ölçütleri aralık, çözünürlük, hata, doğruluk, kesinlik, doğrusallık ve duyarlılıktır; özellikle doğruluk ile kesinliğin farklı şeyler olduğu ve ikisinin birlikte yüksek olması gerektiği vurgulandı. Dirençsel, ışık, basınç, anahtar, kodlayıcı ve hareket sensörleri örneklerle tanıtıldı; sensörlerin devrede çoğunlukla gerilim bölücünün bir kolu olarak kullanıldığı ve mekanik anahtarlarda sıçrama etkisi görüldüğü gösterildi. Eyleyiciler arasında selenoidler, motorlar (özellikle açısal konum kontrolü sağlayan adım motorları) ve ultrasonik dönüştürücüler, ölçü aletleri arasında multimetre ve osiloskop anlatıldı.

Ders, LM35 veri sayfası üzerinde bu ölçütlerin gerçek bir sensörde nasıl okunduğunu göstererek kapandı. pn eklem sensörlerinde adı geçen yarı iletkenler ve diyotlar, dersin asıl konusu olarak sonraki haftalarda ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
