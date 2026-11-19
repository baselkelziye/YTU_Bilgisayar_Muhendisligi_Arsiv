# Ders 10 Genişletilmiş Notu: Laboratuvar 1: Doğrultucular, Kondansatör Filtresi ve Zener Regülatör

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvarın Kapsamı ve Ön Hazırlık
- 2. Proteus'ta Kaynak, Prob ve Grafik Kullanımı
- 3. Soru 1: Zener Diyotlu Gerilim Regülatörü
- 4. Soru 2: Tam Dalga Köprü Doğrultucu
- 5. Soru 2'nin Devamı: Çıkışı DC'ye Yaklaştırmak
- 6. Bonus: Açılış Anındaki Ani Akım
- 7. Soru 3: Gerçek Bir Adaptör Kartı
- 8. Analiz ve Sentez Üzerine
- Örnek Sorular
- Dersin Toparlaması

## 1. Laboratuvarın Kapsamı ve Ön Hazırlık

Bu kayıt dersin ilk diyot laboratuvarıdır. Öğrenciler soru dosyasındaki devreleri Proteus'ta kurar, ölçer ve yorumlar. Kaydın büyük kısmı öğrencilerin çalışması ve sorularıyla geçer; son yarım saatte (02:20:27 sonrası) soruların çözümü anlatılır. Laboratuvarın ana konusu doğrultucu devreler, özellikle tam dalga (full wave) doğrultuculardır.

Laboratuvardan önce bir hazırlık dokümanı verilmişti. Hoca, bu dokümandaki her sorunun laboratuvarın bir adımına ipucu olduğunu söyledi; hazırlığı çözen öğrenci laboratuvar sorularında yeni bir şeyle karşılaşmaz.

### 1.1 Hazırlıktaki iki yarım dalga doğrultucu

Hazırlığın ilk sorusunda iki devre yan yana verilir (ekrandan, 02:25:00). İkisi de aynı yarım dalga doğrultucudur: bir sinüs kaynağı (VSINE), seri bir diyot, çıkışa paralel $C_1 = 1\,\text{mF}$ kondansatör ve yük direnci $R_1$. Tek fark yük direncidir: soldakinde $R_1 = 220\,\Omega$, sağdakinde $R_1 = 10\,\Omega$. Soru, iki devre arasındaki farkın devre davranışını nasıl etkilediğini, diyot ve direncin akım-gerilimini Proteus grafik moduyla inceleyerek bulmayı ister.

Hocanın anlattığı beklenen gözlem şudur: $R_1$ küçükse kondansatörde depolanan enerji yük üzerinden hızlı boşalır. Gerilim her periyotta belirgin şekilde düşüp tekrar yükselir; bu dalgalanmaya ripple (dalgalılık) gerilimi denir. $R_1$ artınca kondansatör daha yavaş boşalır ve ripple azalır. Hoca buradan çıkarılması gereken ilk ipucunu "ripple gerilimini azaltmanın bir yolu yük direncini yükseltmektir" diye özetledi.

> **Ek bilgi (derste anlatılmadı):** Kondansatörün yük üzerinden boşalması $\tau = R C$ zaman sabitiyle belirlenir. Hazırlıktaki iki devrede $\tau$ sırasıyla $220 \cdot 10^{-3} = 0{,}22$ s ve $10 \cdot 10^{-3} = 0{,}01$ s'dir. Zaman sabiti sinyal periyoduna göre ne kadar büyükse kondansatör iki tepe arasında o kadar az boşalır.

### 1.2 Hazırlığın diğer soruları

Hazırlık dokümanında şu sorular da vardı (ekrandan, 02:25:00):

- Transformatör nedir, nasıl çalışır?
- Giriş filtresi (input filter) nedir?
- Yarım köprü doğrultucu (half bridge rectifier) nedir, iyileştirilebilir mi?
- Ripple gerilimi nedir?
- 12 V AC'yi 12 V DC'ye çevirmek gerekse yaklaşımınız ne olurdu?
- Zener diyot gerilim regülatörü olarak kullanılabilir mi? Kullanılabiliyorsa bunu gösteren bir devreyi simüle edin.

Hoca her birinin cevabını laboratuvarla bağladı. Transformatörün resmine bakan öğrenci Soru 3'teki transformatörü tanır. Giriş filtresi, AC'yi DC'ye çevirirken kullanılan devredir; LC filtre, yalnız kondansatör, yalnız bobin ya da bunların karışımı olabilir. Yarım dalga doğrultucunun iyileştirilmiş hali tam dalga köprü doğrultucudur. 12 V AC'yi DC'ye çevirmek için önce sinyali doğrultmak gerekir; bunun devresi zaten ilk sorudadır. Zener ve gerilim regülatörü birlikte arandığında karşılaşılan devre de Soru 1'deki devredir.

## 2. Proteus'ta Kaynak, Prob ve Grafik Kullanımı

Laboratuvar sırasında öğrencilerin sorularına cevap olarak birkaç Proteus işlemi gösterildi.

- **DC kaynak:** Generator bölümünden DC seçilir, değeri eleman özelliklerinden ayarlanır. Soru 1'deki devrede yukarıda bir DC gerilim kaynağı, aşağıda toprak vardır (01:05:00 civarı ekranda devre görünüyor).
- **Sinüs kaynağı:** VSINE elemanına genlik volt olarak, frekans hertz olarak yazılır; hoca örnek olarak 60 Hz'lik bir sinüs kurdu ve osiloskopta sinüsü gösterdi (01:22:48 civarı).
- **Osiloskop:** Simülasyon çalışırken osiloskop penceresi kapanmışsa Debug menüsünden tekrar açılır. Alt kısımda hata mesajı yoksa devre doğru çalışıyor demektir.
- **Grafik ile gösterim:** Ölçülecek noktalara gerilim probu konur. Graph bölümünden "Analogue" grafik seçilip çalışma alanına çizilir. Problar grafiğin içine sürüklenir. Simülasyon birkaç saniye çalıştırılıp durdurulur, grafiğe sağ tıklanıp "Simulate" denir; grafik çizilir. Hem girişe hem çıkışa prob konup ikisi aynı grafiğe atılırsa birbirine göre çizilir. Hoca, ripple'ın bu grafikte osiloskoptan daha net göründüğünü söyledi.

**Soru:** Osiloskopta 25 V görünmesi gereken yerde 24,75 gibi küsuratlı bir değer görünüyor; sorun olur mu? **Cevap:** Bunun bir sebebi var: diyot ideal diyot değil, malzemenin içindeki model ideal değil. <!-- BELİRSİZ: Bu sorunun hangi devre ve hangi ölçüm için sorulduğu altyazıdan net değil. -->

**Soru:** Proteus ölçümde hata veriyor mu? **Cevap:** Devrede yanlışlık yoksa vermez. Ancak bir elemanın modelinin sınırı aşılırsa hata verir; örneğin modelde bir diyottan geçebilecek maksimum akım 50 A ise ondan 100 A geçirmeye çalışmak hata verir. Hocanın gözlemine göre deneme sürümünde bobin (indüktör) dışındaki elemanlar doğru çalışıyor.

**Soru:** Soru 2'deki devrede toprak yok; eklemek gerekir mi? **Cevap:** Bu devrede gerekmez, sinüs kaynağı modeli bunu kendi içinde karşılar. Ancak devreyi geliştirirken eklenecek bazı elemanlar için ayrıca toprak vermek gerekebilir; bu, eklenen elemanın tipine bağlıdır.

## 3. Soru 1: Zener Diyotlu Gerilim Regülatörü

### 3.1 Devre ve istenenler

Devrede bir $V_s$ kaynağı, ona seri $R_1 = 100\,\Omega$ direnç, bu direncin altında toprağa ters bağlı zener diyot D1 (1N4739A) ve zenere paralel $1\,\text{k}\Omega$'luk yük (LOAD) vardır (ekrandan, 02:40:00). İstenenler:

- Devreyi simülasyon ortamında çizmek.
- $V_s$ = 5 V, 8 V, 9 V, 10 V, 15 V için $V_{load}$, $I_{load}$, $I_{zener}$, $I_{main}$ değerlerini ölçüp tabloya yazmak.
- Tabloya bakarak D1'in amacını yorumlamak.

Bir öğrenci ölçüm aletlerinin çizimde görünmesi gerekip gerekmediğini sordu. Cevap: voltmetre ve ampermetrelerin nereye konduğu görünmelidir, ama değerler zaten tabloya yazıldığı için çizimde okunması gerekmez.

### 3.2 Beklenen sonuç

Hocanın anlattığına göre ölçümlerden sonra şu görülür: belli bir kaynak geriliminin üzerinde yük direnci üzerindeki gerilim 9 V civarına sabitlenir. Buradan çıkarılacak sonuç, zener diyotun yük üzerindeki gerilimi regüle ettiğidir: bir gerilimi regüle etmek istendiğinde zener diyot kullanılabilir. Hoca bu sorunun, sonraki laboratuvarlarda gelecek araştırma ve çıkarım tipindeki sorulara alıştırma olarak konduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** 1N4739A, katalog değerine göre 9,1 V'luk bir zener diyottur. Zener diyot ters yönde, kırılma (zener) gerilimine ulaşınca akım geçirmeye başlar ve uçlarındaki gerilimi yaklaşık sabit tutar. Seri direnç, kaynak ile zener gerilimi arasındaki farkı üzerine alır.

### 3.3 Değerlerin hesapla kontrolü

Derste tablo değerleri okunmadı. İdeal bir 9,1 V zener varsayımıyla değerler python ile hesaplandı (ara adım eklendi). Zener iletime geçmeden önce yük gerilimi gerilim bölücüyle bulunur:

$$V_L = V_s \cdot \frac{R_L}{R_1 + R_L} = V_s \cdot \frac{1000}{1100}$$

Bu değer 9,1 V'u geçmeye çalıştığında zener iletime geçer, $V_L = V_Z$ olur ve

$$I_{main} = \frac{V_s - V_Z}{R_1}, \qquad I_L = \frac{V_Z}{R_L}, \qquad I_Z = I_{main} - I_L.$$

| $V_s$ (V) | $V_L$ (V) | $I_L$ (mA) | $I_Z$ (mA) | $I_{main}$ (mA) |
|---|---|---|---|---|
| 5 | 4,55 | 4,55 | 0 | 4,55 |
| 8 | 7,27 | 7,27 | 0 | 7,27 |
| 9 | 8,18 | 8,18 | 0 | 8,18 |
| 10 | 9,09 | 9,09 | ≈ 0 | 9,09 |
| 15 | 9,10 | 9,10 | 49,9 | 59,0 |

Tablodaki eğilim D1'in amacını gösterir: $V_s$ arttıkça yük gerilimi ve yük akımı sabit kalır, artan kaynak akımının fazlası zener üzerinden toprağa akar.

> **Ders sonrası not:** Hoca "9 V ve yukarısı için yük gerilimi 9 V'a sabitlenir" dedi. İdeal hesapta $R_1$-$R_L$ bölücüsü yüzünden zenerin devreye girdiği kaynak gerilimi $V_s \approx 9{,}1 \cdot 1{,}1 \approx 10$ V'tur; 9 V kaynakta yük gerilimi yaklaşık 8,2 V'tur. Sabitlenme 10 V ve üzerinde belirgindir. Gerçek zenerin diz (knee) bölgesi yumuşak olduğundan simülasyonda değerler bu hesaptan biraz farklı çıkabilir.

## 4. Soru 2: Tam Dalga Köprü Doğrultucu

### 4.1 Devre

Soru 2'de dört 1N4001 diyotlu bir köprü, $R_1 = 100\,\Omega$ yük ve bir sinüs kaynağı verilir; soru metninde $V_1$ = 50 V, 60 Hz sinüs yazar (ekrandan, 00:35:00). Bir osiloskop giriş ve çıkışa bağlıdır. Önce devre kurulur, giriş ve çıkış osiloskopta karşılaştırılır, sonra devrenin nasıl çalıştığı anlatılır ve bilinen adı yazılır.

Ekrandaki çizimde bağlantılar şöyledir (ekrandan, 00:35:00): D1'in anodu kaynağın üst ucuna, katodu yükün üst ucuna bağlıdır. D2'nin anodu kaynağın alt ucuna, katodu yine yükün üst ucuna bağlıdır. D3 ve D4 yükün alt ucundan kaynağa doğru bağlıdır: D3'ün katodu kaynağın üst ucuna, D4'ün katodu kaynağın alt ucuna gider.

### 4.2 Pozitif ve negatif yarım periyot

Hoca çalışmayı akımın yolunu izleyerek anlattı. Sinyalin pozitif olduğu yarım periyotta kaynağın üst ucu pozitiftir. Akım D1 üzerinden yüke gider. Dönüşte D3 ile D4 arasında seçim vardır: D3'ün bağlı olduğu uç (kaynağın üst ucu) diğer uçtan daha yüksek potansiyeldedir, bu yüzden akım oradan dönemez; dönüş D4 üzerinden olur. Yani pozitif yarıda D1 ve D4 iletimdedir.

Negatif yarım periyotta akım yön değiştirir; kaynağın alt ucu pozitif olur. Bu kez akım D2 üzerinden yüke gider ve D3 üzerinden döner. Hoca bunu "aslında operasyonun tam tersi" diye anlattı; bir öğrencinin "pozitif için D1 ile D4, negatif için D2 ile D3" özetini onayladı.

Önemli olan, iki yarım periyotta da yükten aynı yönde akım geçmesidir. Çıkışta negatif yarım periyot için de pozitif gerilim görülür; sinüsün alt kısmı yukarı doğru doğrultulmuş olur. Bu devre tam dalga doğrultucudur (full wave rectifier); köprü yapısı nedeniyle köprü doğrultucu da denir. Hoca açıklamanın yazıyla da, yarım periyotlar ayrı ayrı çizilerek de yapılabileceğini söyledi.

**Soru:** Bu devrenin adını açıklama olarak mı yazmak gerekir? **Cevap:** Hayır, açıklama değil; devrenin bilinen adı istenir.

## 5. Soru 2'nin Devamı: Çıkışı DC'ye Yaklaştırmak

Sorunun devamında amaç devreyi iyileştirmek, yani çıkışı DC karakteristiğe yaklaştırmaktır. Üç adım vardır; hangi elemanın kullanılacağına öğrenci karar verir.

### 5.1 Adım 1: Kondansatör (smoothing elemanı)

Çıkışa paralel bir kondansatör bağlanır. Sinyal tepeden düşerken kondansatör boşalarak yükü besler; gerilim düşer ama normal sinyal gibi sıfıra inmez. Hocanın çözümünde kondansatör $C_1 = 2{,}2\,\text{mF}$'tır (ekrandan, 02:30:00). Bu adımdan sonra çıkışta ripple gerilimi görülür; grafikte ve osiloskopta sinyalin tepesinde küçük dalgalanmalar vardır.

### 5.2 Adım 2: Ripple'ı azaltmak

İkinci adımda giriş gerilimi ve diyotlar dışındaki eleman değerleri ayarlanarak ripple olabildiğince azaltılır. Hazırlıktaki gözleme göre yük direnci artırılırsa kondansatör daha yavaş boşalır. Çözümde $R_1$ 10 kat artırılmıştır: $100\,\Omega$ → $1\,\text{k}\Omega$ (ekrandan, 02:30:00). Hoca iki grafiği alt alta gösterdi; yük direnci 10 kat artınca ripple belirgin şekilde azalır. Çözüm ekranındaki çıkış probu $R_1 = 100\,\Omega$ iken yaklaşık 23,5 V, $R_1 = 1\,\text{k}\Omega$ iken yaklaşık 24,09 V gösterir (ekrandan, 02:30:00).

<!-- BELİRSİZ: Soru metninde V1 = 50 V yazıyor; ama çözümdeki prob değerleri (~23,5 V ve ~24,09 V) ve 24 V regülasyon hedefi 25 V civarı bir tepe genliğe uyuyor. Proteus'ta girilen genlik değerinin (tepe mi tepeden tepeye mi) ne olduğu kayıttan net çıkmıyor. -->

**Soru:** Ripple'ı azaltmak için kondansatör değerini değiştirdim (µF yerine mF girdim); olur mu? **Cevap:** Hoca bunun kondansatörün kapasitesini artırmak olduğunu, kondansatöre daha fazla enerji depolandığını, ama yük direnci üzerinde harcanan güç değişmediği için ripple'ın çok net azalmayacağını söyledi. İstenen yol yük direncini değiştirmektir.

> **Ders sonrası not:** Hoca kondansatörü büyütmenin ripple'ı fazla etkilemeyeceğini söyledi; doğrusu bu değil. Tam dalga doğrultucuda tepeden tepeye ripple yaklaşık $V_{r(pp)} \approx \dfrac{V_m}{2 f R_L C}$'dir; $R_L$ ve $C$ formülde çarpım olarak bulunur. Kondansatörü 10 kat büyütmek, yük direncini 10 kat artırmak kadar ripple'ı azaltır. Örneğin tepe değer yaklaşık 23,6 V alınırsa, $C = 2{,}2$ mF ve $f = 60$ Hz için ripple $R_L = 100\,\Omega$'da yaklaşık 0,89 V, $R_L = 1\,\text{k}\Omega$'da yaklaşık 0,09 V olur (python ile hesaplandı).

### 5.3 Adım 3: 24 V'a regülasyon

Son adımda ripple'ı tamamen yok edecek bir eleman eklenip çıkış 24 V'a regüle edilir (soru ±0,7 V'u kabul ediyor) (ekrandan, 00:35:00). Hoca, hem hazırlıktan hem Soru 1'den bunun zener diyotla yapılacağının öğrenilmiş olması gerektiğini söyledi. Kondansatöre paralel 24 V'luk bir zener diyot bağlanır; Soru 1'deki devre aynen buraya konur. Sonuçta ripple tamamen kaybolur.

**Soru:** Zener diyotu bağladım ama çıkış bozuldu. **Cevap:** Zenerin ucu toprağa değil devreye geri bağlanırsa gariplik görülür. Çıkış 24 V'u geçtiği anda zener üzerinden akım akmalı ve fazla akım toprağa gitmelidir ki gerilim 24 V'ta kalsın. Bu akım tekrar devreye verilirse devrede kararsızlık görülür. Soru 1'deki devrede zenerin toprağa bağlanmasının sebebi budur.

## 6. Bonus: Açılış Anındaki Ani Akım

Bonus soru, son önerilen devrenin olası tehlikesini ve çözümünü sorar. Devre sıfır anında açıldığında kondansatör boştur. Kondansatör şarj olurken ilk anda kısa devre gibi davranır; formül yazılırsa $t_0$ ile $t_1$ arasındaki çok küçük aralıkta teorik olarak sonsuza giden bir akım çekebilir. Bu akım diyotların bulunduğu koldan geçer.

Diyot modelinin dayanabileceği bir maksimum akım vardır; bu aşılırsa diyot yanar ("patlar"). Bunu önlemek için diyotların önüne seri bir direnç ya da bobin konur. Hoca bobinle ilgili ipucu hazırlayamadığını, çünkü Proteus'un deneme sürümünde bobini simüle edemediğini söyledi; direnç cevabı da kabul edilir.

> **Ek bilgi (derste anlatılmadı):** Bu olaya İngilizce "inrush current" denir. Gerçekte akım sonsuz olmaz; kaynağın, transformatörün ve diyotların iç dirençleri akımı sınırlar, ama yine de normal çalışma akımının çok üzerine çıkabilir. Pratikte bunun için seri direnç, NTC termistör ya da yumuşak başlatma devreleri kullanılır.

## 7. Soru 3: Gerçek Bir Adaptör Kartı

### 7.1 Soru

Soru 3'te gerçek bir devre kartının fotoğrafı verilir; solda INPUT, sağda OUTPUT yazar. Kartta üç bölge renkli dikdörtgenle işaretlidir: mavi, kırmızı ve yeşil (ekrandan, 02:35:00). Sorular:

- Mavi, kırmızı ve yeşil dikdörtgenlerde hangi devre elemanlarını görüyorsunuz?
- Mavi bölge ne yapıyor olabilir?
- Giriş ve çıkış sinyal tiplerini (AC/DC) ve genliklerini birbirine göre tahmin edin.
- Önceki bulgularınıza göre bu devrenin tamamı ne yapıyor olabilir?

Laboratuvar sırasında bir öğrenci genlik tahmininde net bir değer istenip istenmediğini sordu. Cevap: sayısal değer değil, giriş ve çıkışın birbirine göre büyüklüğü istenir; devre sinyali büyütüyor mu küçültüyor mu, o tahmin edilir.

### 7.2 Çözüm

**Mavi bölge:** Dört diyot, bir direnç ve bir kondansatör vardır. Bu, Soru 2'de kurulan kondansatörlü köprü doğrultucunun aynısıdır. Bir öğrenci "clamper" önerdi; başka bir öğrenci "bridge rectifier" dedi, doğru cevap budur. Mavi bölge doğrultucudur.

**Giriş:** Bir şey doğrultuluyorsa giriş alternatif gerilimdir; giriş AC'dir.

**Kırmızı bölge:** Transformatördür. Hazırlıkta "transformatör nedir" diye arayan öğrenci bu şekli görmüştür.

**Yeşil bölge:** Bobin ve kondansatörler vardır. Hazırlıktaki "input filter" araması LC devrelerini gösteriyordu; yan yana bobin ve kondansatör görülünce burada filtre yapıldığı anlaşılır.

**Akış:** Transformatörün girişi ve çıkışı AC'dir. Demek ki doğrultulan sinyal bir yerde tekrar AC'ye çevrilmiş ve transformatöre verilmiştir. Transformatör gerilimi ya yükseltir ya düşürür; başka bir şey yapamaz. Sonra sinyal yeşil bölgede yeniden filtrelenir, yani çıkış DC'dir.

**Hangisi büyük:** Hocanın verdiği ipucu giriş kondansatörünün çalışma gerilimidir: üzerinde 400 V yazar (ekrandan, 02:35:00). Bu kadar yüksek gerilimli kondansatör, girişin büyük bir AC olduğunu, yani 220 V ya da üstü olması gerektiğini gösterir. Çıkıştaki küçük kondansatörlerle 220 V'tan daha yüksek bir gerilim doğrultulamayacağına göre transformatör gerilimi düşürmektedir. Giriş çıkıştan büyüktür.

**Devrenin tamamı:** 220 V AC'yi daha düşük bir DC gerilime çeviren bir adaptördür. Hoca bunun "12 volt trafo" diye de geçtiğini, ama cevap olarak "adaptör" yazmanın yeterli olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** 220 V'luk şebekenin tepe değeri $220 \sqrt{2} \approx 311$ V'tur; giriş kondansatörünün 400 V'luk olması bu yüzdendir. Bu tip adaptörlerde doğrultulan DC, transformatörün yanındaki küçük bir entegre ile yüksek frekansta anahtarlanarak tekrar AC'ye çevrilir (anahtarlamalı güç kaynağı); yüksek frekans sayesinde transformatör küçük olabilir.

## 8. Analiz ve Sentez Üzerine

Çözümden sonra öğrenciler laboratuvarı zor bulduklarını söyledi. Hoca zorluğun kaynağını şöyle açıkladı: bu laboratuvarda öğrencilerin görmediği tek eleman diyottu; direnç, kondansatör, AC ve DC devre teorisinden biliniyor. Öğrenciler çoğunlukla analiz tipi sorulara alışkındır: verilen devre ölçülür. Bu laboratuvarda ise "buraya bir eleman koy" diye sentez istendi; bunun üzerine düşünmemiş olan öğrenci şaşırabilir. Ayrıca gerçek bir devre kartında elemanları tanımak istendi.

Hoca bu tarzın daha öğretici olduğunu düşünüyor: öğrenci araştırır, çıkarım yapar, devre üzerine düşünür ve gerçek devrelerdeki elemanları yavaş yavaş tanır. Fiziksel laboratuvarda öğrenci elemanların gerçeğini elinde görürken, uzaktan laboratuvarda bu eksiği gidermek için gerçek kart fotoğrafları gibi sorular konuyor.

## Örnek Sorular

### Soru 1 (ekrandan, 02:40:00)

Aşağıdaki devreyi simülasyon ortamında çizin: $V_s$ kaynağı, seri $R_1 = 100\,\Omega$, toprağa ters bağlı zener D1 (1N4739A), zenere paralel $1\,\text{k}\Omega$ yük.

- a) Devreyi simülasyon ortamında çizin.
- b) $V_s$ = 5, 8, 9, 10, 15 V için $V_{load}$, $I_{load}$, $I_{zener}$, $I_{main}$ değerlerini ölçüp tabloya yazın.
- c) D1'in amacı nedir? Yorum yapmadan önce tablonuza dikkatle bakın.

**Çözüm (derste anlatılan):** Kaynak gerilimi belli bir değeri geçince yük gerilimi zener gerilimine sabitlenir; D1 yük gerilimini regüle eder. Sayısal değerler için bölüm 3.3'teki tabloya bakın.

> **Çözüm (derste verilmedi):** İdeal 9,1 V zenerle (python ile): $V_L$ = 4,55 / 7,27 / 8,18 / 9,09 / 9,10 V; $V_s = 15$ V'ta $I_{main} = 59$ mA, $I_L = 9{,}1$ mA, $I_Z \approx 49{,}9$ mA. Zener yaklaşık $V_s = 10$ V'tan itibaren akım çekmeye başlar.

### Soru 2 (ekrandan, 00:35:00)

Dört 1N4001 diyotlu köprü, $R_1 = 100\,\Omega$, $V_1$ = 50 V, 60 Hz sinüs.

- a) Bu devre nasıl çalışıyor? Pozitif ve negatif kutup için akım yollarını açıklayın.
- b) Devreyi verilen değerlerle çizin, giriş ve çıkışı inceleyin.
- c) Bu devre nedir?
- d) Çıkışı yumuşatarak DC karakteristiğe yaklaştırmak istiyoruz.
  - Giriş genliğini dikkate alarak uygun yumuşatma (smoothing) elemanını ekleyin.
  - Ripple gerilimi görüyor musunuz? Grafikte gösterin; giriş gerilimi ve diyotlar dışındaki elemanların değerlerini ayarlayarak ripple'ı olabildiğince azaltın.
  - Ripple'ı tamamen yok edecek bir eleman ekleyin ve sinyali 24 V'a regüle edin (±0,7 V kabul).
- e) (Bonus) Önerdiğiniz son devrenin olası tehlikesi nedir, nasıl çözülür?

**Çözüm (derste anlatılan):**

- a) Pozitif yarıda akım D1 → yük → D4, negatif yarıda D2 → yük → D3 yolunu izler; yükten her iki yarıda aynı yönde akım geçer.
- c) Tam dalga (köprü) doğrultucu.
- d) Çıkışa paralel kondansatör (çözümde 2,2 mF); yük direncini 10 kat artırma ($1\,\text{k}\Omega$); kondansatöre paralel, ucu toprağa bağlı 24 V zener.
- e) Açılışta boş kondansatör kısa devre gibi davranır, diyotlardan çok büyük akım geçer ve diyot yanabilir. Diyotların önüne seri direnç ya da bobin konur.

### Soru 3 (ekrandan, 02:35:00)

Girişi solda, çıkışı sağda olan bir devre kartı fotoğrafında mavi, kırmızı ve yeşil bölgeler işaretli.

- a) Mavi, kırmızı ve yeşil dikdörtgenlerde hangi devre elemanlarını görüyorsunuz?
- b) Mavi bölge ne yapıyor olabilir?
- c) Giriş ve çıkış sinyal tiplerini ve genliklerini birbirine göre tahmin edin.
- d) Önceki bulgularınıza göre bu devrenin tamamı ne yapıyor olabilir?

**Çözüm (derste anlatılan):** a) Mavi: diyotlar, kondansatör, direnç; kırmızı: transformatör; yeşil: bobin ve kondansatörler (LC filtre). b) Doğrultucu (köprü doğrultucu). c) Giriş AC ve büyük (220 V civarı, 400 V'luk kondansatörden çıkarım), çıkış daha düşük DC. d) Adaptör.

### Hazırlık sorusu (ekrandan, 02:25:00)

İki yarım dalga doğrultucu ($C_1 = 1\,\text{mF}$; birinde $R_1 = 220\,\Omega$, diğerinde $R_1 = 10\,\Omega$) arasındaki fark nedir, devre davranışını nasıl etkiler? Diyot ve direncin akım-gerilimini Proteus grafik moduyla inceleyin.

**Çözüm (derste anlatılan):** Yük direnci küçük olan devrede kondansatör hızlı boşalır ve ripple büyüktür; yük direnci büyüdükçe kondansatör daha yavaş boşalır ve ripple azalır.

## Dersin Toparlaması

Bu laboratuvarda diyotun en temel uygulaması olan doğrultma adım adım bir güç kaynağına dönüştürüldü. Yarım dalga doğrultucudan tam dalga köprü doğrultucuya geçildi; köprüde iki yarım periyotta hangi diyot çiftinin iletimde olduğu akım yolu izlenerek bulundu. Çıkışa kondansatör eklenerek sinyal DC'ye yaklaştırıldı, kalan dalgalanmanın ripple olduğu ve yük direnci ile kondansatörün boşalma hızına bağlı olduğu görüldü. Son adımda zener diyotla çıkış sabit bir gerilime regüle edildi; zenerin fazla akımı toprağa akıtması gerektiği vurgulandı. Açılıştaki ani akım tehlikesi ve seri direnç ya da bobinle korunma da konuşuldu.

Gerçek bir adaptör kartında bu blokların (doğrultucu, transformatör, LC filtre) tanınmasıyla, laboratuvarda simüle edilen devrelerin günlük hayattaki karşılığı gösterildi. Bir sonraki laboratuvarın konusu opamp olacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
