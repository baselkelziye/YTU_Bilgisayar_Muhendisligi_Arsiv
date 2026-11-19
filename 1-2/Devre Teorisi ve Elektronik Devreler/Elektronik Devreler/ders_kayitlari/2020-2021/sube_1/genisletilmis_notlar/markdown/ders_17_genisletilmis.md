# Ders 17 Genişletilmiş Notu: Laboratuvar 2: BJT Anahtarlama Devreleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvarın Kapsamı ve Malzemeler
- 2. Soru 1: Anahtar ve BC238 ile Lamba Sürme
- 3. Soru 1 Tasarım Kısmı: Gecikmeli Kapanan Koridor Lambası
- 4. Soru 2: Zener Diyotlu Aşırı Gerilim Kesme Devresi
- 5. Laboratuvar Soruları Üzerine
- Örnek Sorular
- Dersin Toparlaması

## 1. Laboratuvarın Kapsamı ve Malzemeler

Bu kayıt, dersin BJT (bipolar jonksiyonlu transistör) laboratuvarıdır. Öğrenciler soru dosyasındaki iki devreyi Proteus'ta kurar, ölçer ve yorumlar. Kaydın başında (00:12:43 sonrası) soruların ne istediği anlatılır. Ortadaki uzun bölüm öğrencilerin çalışmasıyla geçer. Sonda (02:58 sonrası) çözümler gösterilir.

Soru dosyasında kullanılacak malzemeler şöyle listelenmiştir (ekrandan, 00:10:00):

- BC238 transistör
- 2N3703 transistör
- 1N4733A zener diyot
- Direnç
- DC ampermetre ve DC voltmetre
- DC batarya
- Anahtar (switch)
- Bir veya daha fazla bilinmeyen eleman

Bilinmeyen eleman, sorunun gidişine göre öğrencinin kendisinin seçip devreye yerleştireceği elemandır. Hoca, laboratuvardan önce verdiği hazırlık sorularına bakanların bu kısımda kolaylık yaşayacağını söyledi. Hazırlıkta transistörlerin ne amaçla kullanıldığı ve iki örnek bulunması istenmişti; hocaya göre bu iki örnek laboratuvarın iki sorusudur: birinde transistör anahtarlama yapar, ötekinde yine anahtarlama yapar ama gerilim koruması da sağlar.

Proteus'ta lamba elemanı bileşen aramasında "lamp" yazılarak bulunur (00:21:07).

## 2. Soru 1: Anahtar ve BC238 ile Lamba Sürme

### 2.1 Devre

Devrede 12 V'luk bir batarya, bir anahtar, anahtardan transistörün base'ine giden $R_1$ direnci, 12 V'luk bir lamba ve BC238 transistörü vardır (ekrandan, 01:20:00 ve 03:05:00). Lamba, bataryanın artı ucu ile transistörün collector'ü arasındadır; emitter toprağa bağlıdır. Lambanın iç direnci önce 1 kΩ yapılır, $R_1$'e başlangıçta rastgele bir değer verilir.

### 2.2 Anahtarın ve transistörün görevi

Hoca devrenin mantığını şöyle anlattı. Batarya akımının lambadan geçebilmesi için transistörün iletimde olması gerekir; yoksa devre açık kalır. Transistörün iletime geçmesi için base'den küçük bir akım geçmelidir. Anahtar kapatılınca bu akım base'e ulaşır, transistör iletime geçer ve lamba devresi tamamlanır. Anahtar açılınca base akımı kesilir ve lamba söner. Kısacası anahtarın görevi base'den akım geçirerek transistörü aktif etmek, transistörün görevi de lamba devresini açıp kapayan bir anahtar gibi çalışmaktır.

İlk şıkta istenen ölçümler $I_C$, $I_B$, $V_{lamba}$, $V_{BE}$ ve $V_{CE}$'dir. Bunun için devreye üç voltmetre ve iki ampermetre bağlanır.

### 2.3 Base direncinin hesabı

İkinci şıkta BC238 datasheet'ine bakılarak $V_{BE}$'yi satüre eden, test edilmiş en yüksek $I_B$ akımının base kolundan geçmesi için gereken $R_1$ hesaplanır. Soruda $V_{BE(sat)} = 0{,}7$ V kabul edilir; lamba ve batarya değerlerine dokunulmaz (ekrandan, 00:15:00).

Bir öğrenci datasheet'te iki değer gördüğünü sordu; hoca en yüksek olanın alınacağını söyledi (01:08:42). Datasheet'te test edilmiş en yüksek base akımı 5 mA'dır (03:00:03). Hesap (ekrandan, 03:05:00):

$$R_1 = \frac{V_{CC} - V_{BE}}{I_B} = \frac{12 - 0{,}7}{5\,\text{mA}} = \frac{11{,}3\,\text{V}}{5\,\text{mA}} = 2260\,\Omega \approx 2{,}2\,\text{k}\Omega$$

Cevap olarak 2,2 kΩ yazılır.

### 2.4 Base direncinin amacı

Bu direnç, base akımını istenen değerde (burada 5 mA) tutmak için kullanılır; akım bunu geçmez. Daha küçük bir akım, örneğin 3 mA istenseydi direnç ona göre seçilirdi. Bir öğrencinin cevabı gibi direnç akımı sınırlar. Literatürdeki adı akım sınırlayıcı direnç (current limiting resistor) olur.

### 2.5 Lamba direnci 24 Ω olunca

Sonraki şıkta devre durdurulur, lambanın iç direnci 24 Ω yapılır ve ölçüm tekrarlanır. Lambanın parlaklığı azalır. Hoca bunun ilk bakışta mantıksız göründüğünü söyledi: transistör olmasaydı $V = IR$'den $12 = 24 \cdot I$, yani $I = 0{,}5$ A akardı ve lamba daha parlak yanardı.

Sebep transistördür. Collector'den geçebilecek akımın bir üst sınırı vardır; datasheet'te bu $I_{C,max}$ diye verilir. Ayrıca transistör base akımını ancak kazancı ($\beta$) kadar yükseltebilir. Bu yüzden collector akımı yükün istediği seviyeye çıkamaz, lamba 12 V'a ulaşamaz ve daha sönük yanar.

> **Ek bilgi (derste anlatılmadı):** Satürasyondaki bir anahtar transistörde collector akımı yaklaşık $V_{CC}/R_{\text{yük}}$ olur, ama bunun için $\beta I_B$ bu değerden büyük olmalıdır. Yük direnci çok küçülünce $\beta I_B$ yetmez; transistör satürasyondan çıkıp aktif bölgeye geçer ve $V_{CE}$ artar. Bu durumda gerilimin bir kısmı transistörün üzerinde kalır, yüke daha az gerilim düşer.

## 3. Soru 1 Tasarım Kısmı: Gecikmeli Kapanan Koridor Lambası

### 3.1 İstenen

Lamba iç direnci yeniden 1 kΩ yapılır. Bir bina koridorunda kullanılacak aydınlatma sistemi tasarlanmak istenir: anahtar kapalıyken lamba yanar; anahtar açıldıktan sonra lamba belirli bir süre daha yanmaya devam etmelidir. Süre 5 ile 10 saniye arasında, hesaplanabiliyorsa tam 6 saniye olmalıdır (00:16:01). Yalnız direnç, bobin, diyot, kondansatör, transistör gibi basit elemanlar kullanılır ve en az elemanla tasarım yapılır (ekrandan, 03:05:00). Ardından eklenen elemanın değeri belirlenir (çevrim içi hesaplayıcılar kullanılabilir) ve son devrenin literatürdeki adı tahmin edilir.

> **Hocanın vurgusu:** Burada çok temel ve çok basit düşünmek gerekir; karmaşık bir şey düşünülmemelidir.

### 3.2 Hocanın ipucu

Öğrencilerin çoğu bu şıkta takılınca hoca bir ipucu verdi (01:17:03). Transistörün iletimde kalması için base'den az bir akım geçmelidir. Anahtar açılınca bu koldan akım akmaz. O hâlde devreye öyle bir şey eklenmelidir ki anahtar kesilse bile bir süre base'e enerji sağlasın. Pil dışında devreye belirli bir süre enerji verebilen eleman bilinen bir elemandır; önemli olan onu doğru yere bağlamaktır ki işe yarasın.

### 3.3 Çözüm

Çözümde hoca şu soruyu sordu: anahtar açıldıktan sonra $x$ saniye boyunca lamba çevriminin çalışması için gereken şart nedir? Bir öğrenci base akımı gelmesi gerektiğini söyledi; hoca bunu "transistörün aktif kalması lazım" diye sadeleştirdi. Transistör aktif olduğu sürece lamba çevrimi çalışır. Base'de 0,7 V'tan fazla gerilim olduğu sürece transistör aktif kalır.

Bu yüzden base koluna bir kondansatör eklenir. Kondansatörün bir ucu $R_1$ ile anahtar arasındaki koldan base'e gidecek şekilde bağlanır, öteki ucu toprağa gider (03:06:34). Anahtar kapalıyken kondansatör 12 V'a dolar. Anahtar açılınca 2,2 kΩ'luk $R_1$ ve base üzerinden boşalır ve base gerilimi 0,7 V'un altına inene kadar transistörü iletimde tutar.

<!-- BELİRSİZ: Kondansatörün bağlantı noktası çözüm karesinde görünmedi; "diğer ucunu da buraya bağlıyorum" anlatımından kuruldu. -->

### 3.4 Kondansatör değerinin hesabı

Süre, kondansatörün boşalma süresidir. Hoca boşalma süresini direnç ve kapasiteye bağlayan formülün hatırlanabileceğini, hatırlanmıyorsa çevrim içi bir hesaplayıcının kullanılabileceğini söyledi. Ekranda "Capacitor Safety Discharge" hesaplayıcısı açıktır (ekrandan, 03:10:00). Girilen değerler (03:07:35):

- Başlangıç gerilimi: kondansatör 12 V'a dolduğu için 12 V
- Güvenli gerilim (safety voltage): 0,7 V. Bu noktadan sonra transistör kesime gider; bundan aşağısı önemli değildir.
- Direnç: 2200 Ω
- Kapasite: 1000 µF

Hoca deneme yolunu da gösterdi: örneğin 500 µF'la başlanır, süre yetmezse değer iki katına çıkarılır. Hesaplayıcının ekran görüntüsünü rapora koymak da kabul edilir.

Formülle hesap (ara adım eklendi):

$$t = R C \ln\frac{V_0}{V_{son}} = 2200 \cdot C \cdot \ln\frac{12}{0{,}7}$$

| Kapasite | Süre |
|---|---|
| 500 µF | yaklaşık 3,13 s |
| 1000 µF | yaklaşık 6,25 s |

Tam 6 s için $C = 6 / (2200 \cdot \ln(12/0{,}7)) \approx 960$ µF bulunur; standart değer olarak 1000 µF uygundur. 5-10 s aralığı yaklaşık 800-1600 µF'a karşılık gelir; bu aralığı sağlayan bütün değerler kabul edilir.

> **Ders sonrası not:** Altyazıda tam 6 saniye için "bir mikrofarad" geçiyor (03:08:36). 1 µF ile süre yalnız yaklaşık 6 ms olur. Hoca hesaplayıcıya 1000 µF yazmıştı; doğru değer büyük olasılıkla 1000 µF'tır ve "bin" sözcüğü altyazıda "bir" olarak yazılmış olabilir.

> **Ek bilgi (derste anlatılmadı):** Bu hesap kondansatörün yalnız 2,2 kΩ üzerinden boşaldığını varsayan basit bir modeldir. Gerçekte boşalma akımı base-emitter jonksiyonundan geçer ve base gerilimi yaklaşık 0,7 V'ta tutulur; bu yüzden gerçek gecikme ve lambanın sönme biçimi büyük olasılıkla hesaptan farklıdır. Laboratuvarda istenen, mantığın kurulması ve süreyi yaklaşık sağlayan bir değerin seçilmesidir.

### 3.5 Devrenin adı

Son devre, anahtar açılıp devre kapatıldıktan sonra lambayı birkaç saniye daha yanık tutar; yani devrenin kapanmasına bir gecikme (delay) ekler. Hoca bu yüzden cevabın zaman geciktirme (time delay) olduğunu söyledi; zamanla ilgili makul bir tahminin kabul edileceğini ekledi.

## 4. Soru 2: Zener Diyotlu Aşırı Gerilim Kesme Devresi

### 4.1 Devre ve ölçümler

İkinci devrede B1 bataryası, $R_3 = 2{,}2$ kΩ, $R_1 = 1$ kΩ, Q1 (2N3703), D1 (1N4733A zener), $R_4 = 6{,}8$ kΩ ve 5 V'luk L1 lambası görünür (ekrandan, 03:10:00). Hocanın anlatımına göre devrede ikinci bir transistör Q2 de vardır. <!-- BELİRSİZ: Karede devrenin üst kısmı kesik; Q2'nin tipi ve bağlantısı okunamadı. -->

İlk şıkta B1 sırasıyla 3 V, 5 V, 7 V ve 12 V yapılır; L1 üzerindeki gerilim ve lambanın durumu not edilir. Cevap tablosu (ekrandan, 03:10:00):

| B1 | Lamba gerilimi | Lamba durumu |
|---|---|---|
| 3 V | 3 V | Açık (sönük) |
| 5 V | 5 V | Açık (tam) |
| 7 V | 0 V | Kapalı |
| 12 V | 0 V | Kapalı |

Hoca bu tablonun sorunun devamı için çok iyi fikir verdiğini söyledi.

### 4.2 Transistör tipi

Sonraki şıkta transistörün tipi ve çalışma prensibi sorulur. Hoca çözümde iki devredeki transistörün de NPN olduğunu söyledi, ardından PNP'nin çalışma prensibinin anlatılmasını istediklerini ekledi (03:10:10). Soruların anlatıldığı bölümde ise NPN transistörün çalışma prensibinin özetlenmesi istenmişti (00:19:00). Çalışma prensibi için transistörün yapısını gösteren bir diyagram ve altına 2-3 cümle yeterlidir.

> **Ders sonrası not:** 2N3703 büyük olasılıkla PNP tipi genel amaçlı bir transistördür; BC238 ise NPN'dir. Bu yüzden "ikinci devre de NPN" ifadesi büyük olasılıkla bir sürçmedir; sorunun hangi tipin prensibini istediği kesin değildir.

<!-- BELİRSİZ: Altyazıda bu şıkta "buradaki transistörün XOR'daki transistörden farkı" geçiyor (00:18:55); "XOR'daki" büyük olasılıkla "birinci sorudaki" sözünün bozulmuş hâlidir. -->

### 4.3 Devre ne yapıyor?

Lamba burada bir yük (load) olarak düşünülmelidir; yerine LED, motor ya da başka bir yük konabilir. Ölçümler, belirli bir gerilime kadar yükün kaynağın gerilimini aldığını, bir eşik geçilince yükün kesildiğini gösterir. Hoca bu devreye yüksek gerilim kesme (High Voltage Cut-Off) dedi: bir eşik (threshold) vardır, gerilim onu geçince devre yükü keser. Bu bir koruma devresidir ve yüksek gerilimden korunması istenen her yerde kullanılabilir.

### 4.4 Çalışma durumları ve prensip

Devrenin iki çalışma durumu vardır: yükte gerilimin görüldüğü çalışma durumu ve kesim (cut-off) durumu. Soruda direnç değerleri önemsenmez; yalnız D1, Q1 ve Q2'nin görevleri anlatılır.

Hoca prensibi teorik olarak şöyle anlattı (03:12:04). 1N4733A'nın spesifikasyonunda yaklaşık 5,1 V'luk bir eşik vardır.

- Batarya 0-5 V arasındayken zener iletmez. Q1'in bir bacağı ötekine göre "high" kalır ve Q1 kapalıdır. Q1 çalışmadığı için Q2'nin base bacağı "low" olur ve Q2 iletimdedir. Q2'nin base'inden de biraz akım akar; bu akım olmasa Q2 iletime geçmezdi. Lamba yanar.
- Batarya örneğin 9 V yapılınca durum tersine döner. Zener iletir, Q1'in ilgili bacağı "low" olur ve Q1 iletime geçer. Q1 iletimdeyken Q2'nin base'i "high" olur ve Q2 kesime gider. Akım artık lambadan geçmez, lamba söner.

Teori yetersiz kalırsa uygun noktalara ampermetre ve voltmetre konup iki durumda ölçüm yapılarak aynı sonuca varılabilir. Rapora devrenin ekran görüntüsü alınıp üzerine çizim yapılarak da anlatılabilir.

> **Hocanın vurgusu:** Simülasyonda devrenin istediğiniz yerinde istediğiniz ölçümü yapabilirsiniz; bunu kendi avantajınıza kullanın. Deneylerin amacı ölçmektir.

> **Ek bilgi (derste anlatılmadı):** Zener diyot ters yönde, kendi kırılma geriliminin altında neredeyse akım geçirmez; gerilim bu eşiğe ulaşınca iletime geçer ve üzerindeki gerilimi yaklaşık sabit tutar. Bu devrede zener bir gerilim algılayıcı gibi kullanılır: eşik aşılınca akan akım Q1'i sürer, Q1 de Q2'yi keserek yükü ayırır.

## 5. Laboratuvar Soruları Üzerine

Çözümlerden sonra asistanlar ve öğrenciler laboratuvarın zorluğunu konuştu. Bir öğrenci, ikinci sorunun son şıkkının uzun yazıldığı için kafa karıştırdığını, çözümünün ise basit olduğunu söyledi. Asistanın cevabı, sorunun aslında Q1, Q2 ve zener diyotun devrede ne yaptığını ve nasıl çalıştığını sorduğuydu.

Bir asistan, lambalı soruların lamba yerine direnç koyup $V_{BE}$ ve $V_{CE}$'yi işaretleyerek sınavdaki gibi teorik bir hesap sorusu olarak da sorulabileceğini, ama amacın bu olmadığını belirtti. Laboratuvar soruları "şunu hesaplayın, tabloyu doldurup grafiğini çizin" biçiminde değil, "böyle bir problem var, çözmek için bu devreyi nasıl kullanabiliriz" biçimindedir. Öğrencilerin bu gözle çalışması önerildi. Hocalara göre bu laboratuvarda küçük sinyal analizi yoktur; sorular biraz düşünme ve yorum gerektirir, şıklar da birbirini tamamlayacak şekilde dizilmiştir.

> **Hocanın vurgusu:** Derste anlamaya çalışın; derste işlenen materyalden bile laboratuvarda bir şey çıkabilir.

Sonraki laboratuvarların CMOS ve işlemsel yükselteç (op-amp) konularıyla ilgili olacağı belirtildi; bir konu derste işlendikten sonra laboratuvarı yapılabilir.

## Örnek Sorular

### Soru 1 (ekrandan, 00:15:00)

BC238 datasheet'ine bakarak, $V_{BE}$'yi satüre eden test edilmiş maksimum $I_B$ akımının kurulan devrede de base kolundan geçmesi için gerekli $R_1$ direnç değerini hesaplayınız. ($V_{BE(sat)} = 0{,}7$ V kabul edin; lamba ve batarya değerlerine dokunmayın.) Devrede kaynak 12 V'tur.

> **Çözüm (derste, ekrandan 03:05:00):** Datasheet'te test edilmiş en yüksek base akımı 5 mA'dır. $R_1 = (12 - 0{,}7)/5\,\text{mA} = 2260\,\Omega \approx 2{,}2$ kΩ.

### Soru 2 (derste sözlü, 00:15:11)

Bu $R_1$ direncinin amacı nedir? Literatürdeki adı ne olabilir?

> **Çözüm (derste, 03:02:13):** Base akımını istenen değerde tutar, yani akımı sınırlar. Adı akım sınırlayıcı direnç (current limiting resistor).

### Soru 3 (derste sözlü, 00:15:19)

Lambanın iç direnci 24 Ω yapılıp ölçüm tekrarlanınca lambanın parlaklığı nasıl değişir? Neden?

> **Çözüm (derste, 03:02:32):** Lamba daha sönük yanar. Transistörsüz devrede 0,5 A akardı; transistörlü devrede collector akımı $\beta I_B$ ve $I_{C,max}$ ile sınırlıdır, lamba 12 V'a ulaşamaz.

### Soru 4 (ekrandan, 03:05:00)

Bina koridoru için aydınlatma: anahtar açıldıktan sonra lamba 5-10 saniye (mümkünse tam 6 saniye) daha yansın. Yalnız basit elemanlarla (direnç, bobin, diyot, kondansatör, transistör) en az elemanla tasarım yapınız. Eklediğiniz elemanın değerini belirleyiniz. Bu devrenin literatürdeki adı nedir?

> **Çözüm (derste, 03:06:07):** Base koluna bir kondansatör eklenir. Kondansatör 12 V'tan 0,7 V'a 2,2 kΩ üzerinden boşalırken transistörü iletimde tutar. $t = RC\ln(12/0{,}7)$ ile 1000 µF yaklaşık 6,25 s verir (python ile doğrulandı). Devre zaman geciktirme (time delay) devresidir.

### Soru 5 (ekrandan, 03:10:00)

İkinci devrede B1 batarya değeri 3 V, 5 V, 7 V ve 12 V iken L1 lambasındaki gerilimi ve lambanın durumunu gözlemleyiniz.

> **Çözüm (derste, ekrandan 03:10:00):** 3 V: 3 V, açık (sönük); 5 V: 5 V, açık (tam); 7 V: 0 V, kapalı; 12 V: 0 V, kapalı.

### Soru 6 (ekrandan, 00:20:00)

Ölçümlerinize göre bu devre ne yapmaktadır? Literatürdeki adı ne olabilir ve nerelerde kullanılabilir?

> **Çözüm (derste, 03:10:37):** Gerilim eşiği geçince yükü keser. Adı yüksek gerilim kesme (High Voltage Cut-Off) ya da koruma devresi; yüksek gerilimden korunması gereken her yükte kullanılabilir.

### Soru 7 (ekrandan, 00:20:00)

Devrenin kaç çalışma durumu var? a, b ve c bölümlerinde öğrendiklerinizi kullanınız. Devrenin çalışma prensibini D1, Q1 ve Q2'nin görevleri ile birlikte anlatınız (direnç değerlerini önemsemeyin). Gerekli yerlere ampermetre ve voltmetre koyup ölçüm yaparak çalışma mantığını analiz ediniz, sonra teorik bilginizle pekiştiriniz.

> **Çözüm (derste, 03:11:36):** İki durum vardır: çalışma ve kesim. Gerilim zener eşiğinin (yaklaşık 5,1 V) altındayken zener iletmez, Q1 kapalı, Q2 iletimdedir ve lamba yanar. Eşiğin üstünde zener iletir, Q1 iletime geçer, Q2 kesime gider ve lamba söner.

## Dersin Toparlaması

Bu laboratuvarda BJT'nin anahtar olarak kullanımı iki uygulamayla görüldü. Birinci devrede anahtar, base direnci üzerinden BC238'i sürer ve transistör lambayı yakıp söndürür. Base direnci $(V_{CC} - V_{BE})/I_B$ ile hesaplanır ve akım sınırlayıcı olarak çalışır; yük direnci çok küçülünce collector akımı transistörün kazancı ve akım sınırıyla kısıtlanır. Base koluna eklenen bir kondansatör, anahtar açıldıktan sonra transistörü bir süre daha iletimde tutar ve devreyi bir zaman geciktirme devresine çevirir; süre kondansatörün 12 V'tan 0,7 V'a boşalma süresiyle ayarlanır.

İkinci devrede bir zener diyot gerilim eşiğini algılar ve iki transistör üzerinden yükü keser; ortaya bir yüksek gerilim kesme (koruma) devresi çıkar. Her iki soruda da vurgu, devrenin hangi problemi çözdüğünü ölçerek ve mantık yürüterek bulmaktır. Sonraki laboratuvarların CMOS ve op-amp konularında olması beklenmektedir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
