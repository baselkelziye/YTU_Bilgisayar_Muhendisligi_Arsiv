# Ders 4 Genişletilmiş Notu: Lab 1 Oturumu; Süper Düğüm, Çevre (Mesh) Analizi ve Süper Çevre, Doğrusallık ve Süperpozisyon

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Lab 1 Oturumu: Ohm Kanunu ve Seri-Paralel DC Devreler
- 2. Düğüm ve Çevre Analizine Genel Bakış
- 3. Düğüm Analizinin Tekrarı
- 4. Süper Düğüm
- 5. Çevre (Mesh) Analizi
- 6. Çevre Analizi Örnekleri
- 7. Süper Çevre (Supermesh)
- 8. Düğüm mü, Çevre mi? Düzlemsel Devreler ve Karşılaştırma Örneği
- 9. Devre Teoremlerine Giriş
- 10. Doğrusallık
- 11. Kaynakları Sıfırlamak
- 12. Süperpozisyon Teoremi
- 13. Bağımlı Kaynaklı Süperpozisyon ve Matrisle Çözüm

## 1. Lab 1 Oturumu: Ohm Kanunu ve Seri-Paralel DC Devreler

Kaydın ilk bölümü bir laboratuvar oturumudur ve araştırma görevlisi tarafından yürütülür. Oturumun amacı zor bir devre çözmek değil, simülasyon programını tanımaktır: bir devre kurmak, toprağı bağlamak, ampermetre ve voltmetreyi yerine koymak. Bu yüzden konu Ohm kanunu ($V = I \cdot R$) ile seri ve paralel bağlamayla sınırlıdır. Devrelerde yalnızca DC gerilim vardır, AC kullanılmaz.

### 1.1 Deneyin içeriği

İki soru vardır. Birincisinde 10 V DC kaynaklı seri bir devre, ikincisinde 20 V DC kaynaklı paralel bir devre incelenir. Her soruda üç durum tabloya işlenir. Seri devrede durumlar şunlardır:

- Birinci durum: $R_4$ devreden çıkarılır, $R_1$, $R_2$, $R_3$ kalır.
- İkinci durum: $R_2$ ve $R_4$ devreden çıkarılır, $R_1$ ve $R_3$ kalır.
- Üçüncü durum: $R_1$, $R_2$, $R_3$, $R_4$ hepsi devrededir.

Tabloda $V_1$, $V_2$, $V_3$ gerilimleri, ölçülen ve hesaplanan akım, eşdeğer direnç ve devrenin gücü yer alır. Tabloda "ölç" yazan değerler simülasyondaki voltmetre ve ampermetreden okunur. "Hesap" yazan değerler elle, Ohm kanunuyla bulunur. Böylece ölçülen akım ile hesaplanan akım yan yana karşılaştırılabilir. Hoca dirençleri bilerek düşük değerlerde tuttuğunu, amacının akım değerlerinin yüksek çıkması olduğunu söyledi.

<!-- BELİRSİZ: Altyazıda "RH değerleri" geçiyor. Kısa nota göre bu, eşdeğer direnç R_eş'tir. -->

**Soru:** Pilin gücünü hesaplarken her eleman için ayrı mı hesaplayacağız? **Cevap:** Hayır. Güç tabloda tek değerdir ve o durumdaki devrenin tamamı içindir. Dirençlerin güçlerini tek tek bulup toplamak da, sistemin genel gücünü hesaplamak da kabul edilir.

### 1.2 Proteus'ta devre kurma

Oturumda şu pratik bilgiler gösterildi:

- Eleman seçimi: "P" düğmesine ya da klavyeden P tuşuna basılır, arama kutusuna yazılır. Direnç için "res", kaynak için "DC source" aratılır. Birkaç farklı DC kaynak listelenir.
- Toprak: Soldaki Terminals Mode menüsünden "ground" alınır.
- Ölçü aletleri: DC voltmetre ve DC ampermetre kullanılır. AC aletler ileride kullanılacaktır. Bir eleman yana dönükse döndürme seçeneğiyle saat yönünde ya da tersine çevrilebilir.
- Pilin iç direnci: Sıfırlanması önerilir, böylece net değerler çıkar. Sıfırlanmasa da çok yüksek bir değer tutulmamalıdır.
- Kütüphane hatası: "Kütüphane bulunamadı" uyarısı alındığında programı yönetici olarak başlatmak sorunu çözdü.

Toprak konusunda hocanın uyarısı şudur: Bu devreler basit pil devresi olduğundan simülasyon toprak bağlanmadan da çalışabilir, ama toprak her zaman bağlanmalıdır. Multisim kullananlar da toprağı ve kaynağı arayarak bulabilir, ölçüm değerleri orada sağ köşede görünür.

<!-- BELİRSİZ: Altyazıda "Alt isim kullanan arkadaşlar" geçiyor. Bağlam ve bir önceki cümle nedeniyle Multisim olarak okundu. -->

Ampermetre sıfır gösterdiğinde kontrol edilecek noktalar, hocanın kendi kullanımındaki deneyimine göre şunlardır:

- Ampermetre gerçekten bağlı mı? Tutulup çekildiğinde kablo gelmiyorsa bağlantı kopuktur ve alet ölçmez.
- Ampermetre yatay konumda ve bir direncin önünde mi? Hoca, dikey konumda değerin genelde görünmediğini, sıfır görülürse aletin yatay konuma alınmasını söyledi. Bir başka olasılık aletin akım geçmeyen bir yere konmuş olmasıdır.
- DC ve AC aletler karışmış mı? DC devreye AC ampermetre konursa çalışmayabilir.

**Soru:** Ana akımda hesap ile ölçüm tutmuyor, 33.1 ve 44.4 değerleri çıkıyor. Ne yapmalı? **Cevap:** Hoca bunun iç dirençle ilgili olabileceğini söyledi ve iç dirençlerin sıfırlanmasını önerdi. Sıfırlanmasına rağmen fark kalırsa bunun nedeni açıklanmalıdır.

**Soru:** Voltmetre yerine başka bir yolla gerilim değeri okunabilir mi? **Cevap:** Hoca bu laboratuvarda voltmetre istedi. Aynı değer bulunur, ama voltmetre ile ölçülmesi beklenir.

<!-- BELİRSİZ: Soruda "ROG'la" diye bir kelime geçiyor (00:32:05). Hangi araç olduğu altyazıdan anlaşılmıyor; "probe" olabilir. -->

### 1.3 Simülasyon ile gerçek devre farkı

Hoca simülasyonun gerçeği yaklaşık yüzde 90 oranında yansıttığını, tamamen aynı olmadığını anlattı. Az önceki örnekte devre toprak olmadan çalışmıştı, ama yüz yüze laboratuvarda toprak bağlanmadan devre kesinlikle çalışmıyor. Benzer şekilde gerçek laboratuvarda ampermetrenin sigortası atabiliyor; hoca, geçmiş yıllarda bunun sık yaşandığını, öğrencilerin de bunu videolara bakarak onardığını anlattı. Simülasyonda ise böyle bir durum yoktur.

## 2. Düğüm ve Çevre Analizine Genel Bakış

Asıl ders, geçen haftanın toparlanmasıyla başlar. Düğüm analizi (node analysis) ve çevre analizi (mesh analysis) yöntemlerinin temelinde Kirchhoff'un akımlar ve gerilimler yasaları vardır. Bu yöntemler öncelikle şu soruyu yanıtlar: Bir devreyi çözmek için kaç denkleme ihtiyacımız var?

Devrede $n$ adet ayrık düğüm varsa, bunlardan biri referans seçilir ve $n-1$ düğüm denklemi yazmak gerekir. Çevre analizinde ise denklem sayısı alt çevrim (göz) sayısı kadardır. Hocanın gösterdiği devrede referans hariç beş düğüm ama yalnızca iki çevre vardır. Bu devreyi çevre analiziyle çözmek daha pratik olacaktır. İki yöntem arasındaki seçim kabaca bu sayımla yapılır.

## 3. Düğüm Analizinin Tekrarı

Düğüm analizi, bir düğüme giren ve çıkan akımların yönlü toplamının sıfır olduğunu söyleyen Kirchhoff'un akımlar yasasına dayanır. Her akım, düğüm gerilimleri cinsinden yazılır. Burada iki kavram karıştırılmamalıdır:

- Bir elemanın gerilim düşümü, elemanın iki ucu arasındaki farktır.
- Düğüm gerilimi, o noktanın referansa göre potansiyelidir.

Örneğin $R_1$ elemanının uçları arasındaki gerilim $V_2$ değil, $V_2 - V_1$'dir. Hoca 3 numaralı düğüm için önce akım yönlerini belirledi, sonra bu yönlerle uyumlu gerilim referanslarıyla akımları yazdı:

$$I_2 = \frac{V_2 - V_3}{R_2}, \qquad I_3 = \frac{V_3 - V_5}{R_3}, \qquad I_4 = I_5 = \frac{V_3 - V_5}{R_4 + R_5}$$

$R_4$ ve $R_5$ aynı koldadır, bu yüzden akımları eşittir ve tek denklemle yazılabilir. İstenirse kol ikiye bölünebilir, o zaman $I_4 = (V_3 - V_4)/R_4$, $I_5 = (V_4 - V_5)/R_5$ ve $I_4 = I_5$ olmak üzere tek denklem yerine üç denklem yazılır.

Kurulan $n-1$ denklemli sistem eleme yöntemiyle, determinantla ya da katsayı matrisinin tersini alarak çözülür ve düğüm gerilimleri bulunur. "Devreyi çözmek" ise devredeki her elemanın akımını ve gerilimini bulmak demektir. Düğüm gerilimleri bilindiğinde her elemanın gerilim düşümü farktan bulunur ($R_2$ için $V_2 - V_3$), direnç de bilindiğinden akım hesaplanır.

## 4. Süper Düğüm

### 4.1 Tanım

Düğüm analizinin özel bir durumu süper düğümdür (supernode). Referans düğüm sıfır kabul edilip bütün düğümler buna göre yazıldığında bir değişkenden kurtulunur. Hoca kuralı şöyle verdi: Eksi ucu seçilen referansa bağlı olmayan her gerilim kaynağı bir süper düğümdür.

> **Ders sonrası not:** Hoca "eksi ucu referansa bağlı olmayan gerilim kaynağı süper düğümdür" dedi. Bu kural, artı ucu referansta olan kaynakları da kapsar. Standart tanım büyük olasılıkla "iki ucu da referansa bağlı olmayan gerilim kaynağı"dır. Artı ucu referansta olan kaynak, dersin kendi örneklerinde de görüldüğü gibi ($V_C = -4$ V, $v_1 = -12$ V) o düğümün gerilimini doğrudan verir ve bir kısıt denklemi getirir, ancak düğümleri birleştirmeyi gerektirmez.

Gerilim kaynağının kullanılacak iki özelliği vardır:

- Uçları arasındaki gerilim farkını başka bir eleman değil, kaynağın kendisi belirler.
- Üzerinden geçen akımı ise komşu elemanlar belirler.

Bu nedenle süper düğüm olduğunda denklem sistemine, kaynağın uç gerilimlerini bağlayan bir denklem daha eklenir.

### 4.2 Geçen haftanın örneği

$B$ ve $C$ düğümleri arasında artı ucu $C$ tarafında olan $V_2$ gerilim kaynağı bulunsun. $A$ ile $B$ arasında $R_2$, $B$ ile referans arasında $R_3$, $A$ ile $C$ arasında $R_1$ vardır. $B$ düğümü için akımlar yazılır: $R_2$'den giren akım artı, $R_3$'ten çıkan akım eksi, bir de kaynaktan gelen $I_{V_2}$:

$$\frac{V_A - V_B}{R_2} - \frac{V_B - 0}{R_3} + I_{V_2} = 0$$

$I_{V_2}$ değerini kaynak belirlemez, komşu elemanlar belirler. Ama $C$ düğümünün gerilimi $B$'den $V_2$ kadar yüksektir: $V_C = V_B + V_2$. Kaynağın bulunduğu kol tek kol olduğundan kaynaktan geçen akım $R_1$'den geçen akımla aynıdır:

$$I_{V_2} = \frac{V_A - V_C}{R_1} = \frac{V_A - (V_B + V_2)}{R_1}$$

Bu ifadeyi yerine koymak bir denklemi azaltır. Alternatif olarak $V_C = V_B + V_2$ ayrı bir denklem olarak sisteme eklenip denklemler eş anlı çözülebilir.

> **Ders sonrası not:** Altyazıda hoca $V_C$ yerine "$V_1$ artı $V_2$" yazılacağını söylüyor. Aynı anlatımda az önce kurulan bağıntı $V_C = V_B + V_2$ olduğundan doğrusu $V_B + V_2$'dir.

<!-- BELİRSİZ: Bu örneğin devre şeması altyazıda görünmüyor. Eleman yerleşimi yazılan denklemlerden kuruldu. -->

### 4.3 Referansa göre süper düğümleri belirlemek

Hoca iki gerilim ve bir akım kaynağı içeren bir devreyle aynı işlemi gösterdi. İlk adım referans düğümü seçmektir. Referansın 0 V kabul edilmesi genelliği bozmaz. Sonra kaynaklara bakılır. Akım kaynağı bu açıdan söz konusu değildir, yalnız gerilim kaynaklarına bakılır:

- 8 V'luk kaynağın eksi ucu referansa doğrudan bağlı değildir, başka elemanlardan geçerek gider. $V_A$ ile $V_B$ arasındaki fark 8 V'tur: $V_B = V_A + 8$.
- 4 V'luk kaynağın artı ucu referanstadır. Bu yüzden öbür ucundaki gerilim $V_C = -4$ V olur.

Bu iki denklem düğüm denklemlerine eklenir. Seçilen referans değişirse bu durumlar da değişebilir.

**Soru:** Referansı aşağıda toprak yazan yer olarak seçtik, değil mi? **Cevap:** Evet, oradaki düğüm seçildi. Yol, seçilen referansa göre değişir.

### 4.4 Örnek 03: Bağımlı kaynaklı süper düğüm

Devrenin yerleşimi şöyledir (altyazıda şema okunamadığından eleman değerleri denklemler ve kısa notla kuruldu):

- $v_1$ ile referans arasında 12 V kaynak, artı ucu referansta.
- $v_1$ ile $v_2$ arasında 0.5 Ω. $v_x$ bu direncin gerilimidir, artı ucu $v_2$ tarafındadır.
- Referanstan $v_2$'ye doğru 14 A akım kaynağı. $v_2$ ile $v_3$ arasında 2 Ω.
- Referanstan $v_3$'e doğru $0.5\,v_x$ bağımlı akım kaynağı.
- $v_1$ ile $v_4$ arasında 2.5 Ω. $v_y$ bu direncin gerilimidir, artı ucu $v_4$ tarafındadır. $v_4$ ile referans arasında 1 Ω.
- $v_3$ ile $v_4$ arasında $0.2\,v_y$ bağımlı gerilim kaynağı.

**Kısıt denklemleri.** 12 V'luk kaynağın artı ucu referansa bağlı olduğundan $v_1 = -12$ V yazılır. İkinci kaynak bağımlı olsa bile uçları arasındaki gerilimi kendisi belirler, bu yüzden onun için de bir denklem gerekir.

Hoca bu denklemin arkasındaki mantığı şöyle gösterdi: $v_3$ ve $v_4$ gerilimleri aynı toprağa göre tanımlıdır. Bunları referansla düğüm arasında duran sanal birer kaynak gibi düşünün. Kapalı bir çevre oluşur, çünkü iki gerilimin eksi ucu da topraktadır. Bu çevrede dolaşıp eksisinden girilen kaynağı eksi, artısından girilen kaynağı artı yazarsak:

$$-v_3 + 0.2\,v_y + v_4 = 0 \quad \Rightarrow \quad v_3 = v_4 + 0.2\,v_y$$

Sonuç gözle de görülür, ama karmaşık devrelerde bu mantığı kullanmak hata riskini azaltır.

**$v_2$ düğümü.** Kirchhoff'un akımlar yasasıyla çıkan akımlar giren 14 A'ya eşitlenir:

$$\frac{v_2 - v_1}{0.5} + \frac{v_2 - v_3}{2} = 14$$

**Süper düğüm denklemi.** Bağımlı gerilim kaynağının bulunduğu koldaki akımı kaynak belirlemez. Bu yüzden o akım yerine, koldan dağılan iki kolun toplamı yazılır. Yani $v_3$ ve $v_4$ tek bir düğüm noktası gibi alınır. Girişler artı, çıkışlar eksi alınıp düzenlenince:

$$0.5\,v_x + \frac{v_2 - v_3}{2} - \frac{v_4}{1} - \frac{v_4 - v_1}{2.5} = 0 \quad \Rightarrow \quad 0.5\,v_x = \frac{v_3 - v_2}{2} + \frac{v_4}{1} + \frac{v_4 - v_1}{2.5}$$

> **Ders sonrası not:** Altyazının bir yerinde bu terim "0.45Vx" diye geçiyor. Kaynağın değeri ve aynı anlatımın devamı nedeniyle doğrusu $0.5\,v_x$'tir.

**Bağımlı kaynak değişkenleri.** Bağımlı kaynakların değişkenleri de düğüm gerilimleri cinsinden yazılır:

$$v_y = v_4 - v_1, \qquad v_x = v_2 - v_1$$

**Çözüm.** Hoca sistemin çözülerek değişkenlerin bulunacağını söyledi, sonuçları altyazıda okunmuyor. Bu denklemler python ile çözüldüğünde kısa nottaki değerler elde edildi: $v_1 = -12$ V, $v_2 = -4$ V, $v_3 = 0$ V, $v_4 = -2$ V; ayrıca $v_x = 8$ V ve $v_y = 10$ V (python ile hesaplandı).

### 4.5 Süper düğümün sınırı

**Soru:** $v_3$ ile $v_4$ arasındaki denklemi atladık mı? **Cevap:** Hayır, o denklem ayrı yazılır. Atlanan şey, kaynak kolundaki akımdır. Kaynak kendi akımını belirlemediği için, o koldan gelen akım dağıldığı iki kolun toplamı olarak yazıldı.

Hoca bu yöntem kafa karıştırıcı gelirse bir denklem daha eklenebileceğini de söyledi: Önce kaynak kolunun akımı cinsinden yazılır, sonra bu akımın iki kolun toplamına eşit olduğu ayrıca yazılır.

**Soru:** $v_3$ ile $v_4$ arasına bir direnç de konsaydı onu da atlayacak mıydık? **Cevap:** Hayır. O zaman koldaki akımı direnç de etkiler ve yeni bir düğüm oluşur. Süper düğüm kaynağın uçlarına kadar sürer, direnç onun dışında kalır ve sisteme dahil edilmelidir. Süper düğümün sınırı bir sonraki elemana kadardır.

> **Hocanın vurgusu:** Akılda tutulacak üç şey: Düğüm analizinde kaç denklem gerektiği, süper düğüm durumunun nasıl tespit edildiği ve süper düğüm için sisteme hangi denklemlerin eklendiği.

## 5. Çevre (Mesh) Analizi

### 5.1 Sanal çevre akımı fikri

Düğüm analizinde her düğümün kendi gerilimi vardı. Çevre analizinde de her çevrenin kendine ait bir çevre akımı olduğu düşünülür. Bu akım sanal bir değer gibidir. İki gözlü devrede ($R_1$, $R_2$, $R_6$ birinci gözde, $R_4$, $R_5$ ikinci gözde, $R_3$ ortak kolda) durum şöyledir:

- $R_1$, $R_2$ ve $R_6$'ya yalnız $i_1$ etki eder. $i_1$ bulununca bu dirençlerin akımı da bulunmuş olur.
- $R_4$ ve $R_5$'e yalnız $i_2$ etki eder.
- $R_3$'e ikisi birden etki eder. Net akım, çevre akımlarının yönlü toplamıdır: $R_3$ için tanımlanan yönde $i_1 - i_2$.

Yöntemin temel çıkış noktası Ohm kanunu ve Kirchhoff'un gerilimler yasasıdır: Bir çevredeki gerilimlerin toplamı sıfırdır. Bu yasayla çevre denklemleri yazılır, çevre akımları bulunur, çevre akımlarından eleman akımlarına ve Ohm kanunuyla eleman gerilimlerine geçilir.

> **Ders sonrası not:** Hoca bu toplamı yer yer "vektörel toplam" diye adlandırdı. DC devrede söz konusu olan, işaretli (yönlü) toplamdır.

### 5.2 Çevreleri seçmek

Çevreler gözle görülen gözler olmak zorunda değildir. Bağımsız çevre sayısı kadar denklem gerekir; iki gözlü bir devrede en az iki çevre denklemi lazımdır. Hoca aynı devre için üç seçenek gösterdi:

- İki alt gözü ayrı ayrı almak. İlk akla gelen budur.
- Bir gözü ve dıştan dolaşan çevreyi almak.
- Dış çevreyi ve öbür gözü almak.

Üçü de geçerlidir. Çevreler ne kadar ayrı alınırsa denklem sistemlerindeki karmaşıklık o kadar azalır.

> **Hocanın vurgusu:** Bazı elemanlar iki çevreye birden dahil olabilir. Bu durumda elemanın net akımı çevre akımlarının yönlü toplamıdır. Dikkat edilecek en önemli nokta budur.

### 5.3 Denklemleri kurmak

Sıra şöyledir: Önce elemanlar için gerilim referans yönleri belirlenir, sonra her çevre için bir akım yönü seçilir. Pratik olan, her elemanın eksi ucunu referans düğüme yakın olan uç seçmektir. Bu, işlem karmaşıklığını azaltan bir alışkanlıktır, zorunluluk değildir.

Kirchhoff'un gerilimler yasası iki çevre için şöyle yazılır:

$$-V + V_1 + V_2 + V_3 + V_6 = 0, \qquad -V_3 + V_4 + V_5 = 0$$

Direnç gerilimleri Ohm kanunundan gelir:

$$V_1 = i_1 R_1, \quad V_2 = i_1 R_2, \quad V_6 = i_1 R_6, \quad V_4 = i_2 R_4, \quad V_5 = i_2 R_5$$

Kritik olan $V_3$'tür. İki çevre akımı da $R_3$'e etki eder ve doğrusal bir eleman olduğu için etkileri toplanır. $i_1$, $V_3$'ün referansında artıdan eksiye gider ve gerilimi artırıcı yönde katkı yapar. $i_2$ ise eksiden artıya gider ve azaltıcı yönde katkı yapar. Bu yüzden:

$$V_3 = (i_1 - i_2) R_3$$

**Soru:** $i_1$'den $i_2$'yi neden çıkardık? **Cevap:** Referans yönüyle uyum nedeniyle. Elemanın gerilim yönü önce belirlendi, sonra çevre akımları seçildi. Bu elemana $i_1$ artısından girer, $i_2$ ise eksisinden girer. Birincisi $V_3$'ü artırır, ikincisi azaltır.

### 5.4 Çevre akımı yönü başka seçilirse

Referans yönleri seçmekte serbestlik vardır, sistem kendini buna göre toparlar. Hoca, ikinci çevre akımının ters yönde seçildiği durumu gösterdi. Elemanların gerilim yönleri korununca $V_1 = i_1 R_1$ aynı kalır, $V_3 = (i_1 + i_2) R_3$ olur. Ama bu kez $V_4 = -i_2 R_4$ ve $V_5 = -i_2 R_5$ yazılır, çünkü çevre akımı bu elemanlara eksi ucundan girer. Bir yerden kurtulan eksi işareti başka yere geçer.

### 5.5 Çevre akımı ve eleman akımı

Küçük harfli $i_1$, $i_2$ sanal çevre akımlarıdır. Büyük harfli $I_1$, $I_3$ gibi akımlar ise elemanlardan gerçekten geçen akımlardır. İlişkileri:

$$I_1 = I_2 = I_6 = i_1, \qquad I_4 = I_5 = i_2, \qquad I_3 = i_1 - i_2$$

Sistem çözülüp $i_1$, $i_2$ bulunur. Bunlardan büyük harfli eleman akımlarına, onlardan da Ohm kanunuyla eleman gerilimlerine geçilir.

### 5.6 Örnek 04: Sayısal çözüm

**Verilen.** Aynı devre: 12 V kaynak, $R_1 = 4$ kΩ, $R_2 = 8$ kΩ, $R_3 = 5$ kΩ, $R_4 = 6$ kΩ, $R_5 = 3$ kΩ, $R_6 = 1$ kΩ. Referans, 12 V kaynağın eksi ucudur.

<!-- BELİRSİZ: Direnç değerleri altyazıda tek tek okunmuyor, kısa nottan alındı. Altyazıdaki 740 µA, 264 µA ve R6 = 1 kΩ ile tutarlıdır. -->

**Denklemler** (ara adım eklendi):

$$-12 + (4k + 8k + 5k + 1k)\,i_1 - 5k\,i_2 = 0 \quad \Rightarrow \quad 18k\,i_1 - 5k\,i_2 = 12$$

$$-5k\,(i_1 - i_2) + (6k + 3k)\,i_2 = 0 \quad \Rightarrow \quad -5k\,i_1 + 14k\,i_2 = 0$$

**Çevre akımları.** Çözüm $i_1 = 740$ µA, $i_2 = 264$ µA'dir (python ile hesaplandı: $i_1 = 168/227$ mA, $i_2 = 60/227$ mA).

**Eleman akımları.** $R_1$'den 740 µA, $R_3$'ten $740 - 264 = 476$ µA geçer.

**Eleman gerilimleri** (python ile hesaplandı):

| Eleman | Akım (µA) | Gerilim (V) |
|---|---|---|
| $R_1$ | 740 | 2.96 |
| $R_2$ | 740 | 5.92 |
| $R_3$ | 476 | 2.38 |
| $R_4$ | 264 | 1.59 |
| $R_5$ | 264 | 0.79 |
| $R_6$ | 740 | 0.74 |

Hoca, bir elemanın gerilimini düğüm gerilimlerinin farkından da bulmayı gösterdi: $R_5$ için $V_4$ düğümü eksi $V_5$ düğümü, $R_6$ için ise o düğüm eksi referans. Sağlama olarak $R_6$ gerilimi çevre akımından da bulunabilir: 740 µA çarpı 1 kΩ, yani 0.74 V.

**Sağlama.** Her çevrede gerilimlerin toplamı sıfır olmalıdır. Birinci çevrede $2.96 + 5.92 + 2.38 + 0.74 = 12$ V, yani kaynak gerilimine eşittir. İkinci çevrede $-V_3 + V_4 + V_5 = 0$ çıkar.

> **Ders sonrası not:** Altyazıda sağlama $-2.39 + 1.59 + 0.804$ diye yapılıyor. Python ile hesaplandı: $V_3 = 2.379$ V, $V_5 = 0.793$ V. Bu değerlerle ikinci çevrenin toplamı tam olarak sıfırdır; altyazıdaki rakamlarla çıkan 0.004 V farkı rakamların kendisinden gelir.

### 5.7 Yöntemin adımları

1. Göz sayısına bakılır. Denklem sayısı ve tanımlanacak çevre akımı sayısı buna eşittir.
2. Her eleman için gerilim referans yönü belirlenir.
3. Çevre akımları ve yönleri tanımlanır.
4. Her çevre için Kirchhoff'un gerilimler yasası yazılır. Her elemanın gerilim düşümü akım çarpı dirençtir, elemanın net akımı ise çevre akımlarının yönlü toplamıdır.
5. Denklemlerden çevre akımları çözülür.
6. Çevre akımlarının bileşkesinden eleman akımları, Ohm kanunuyla da eleman gerilimleri bulunur.

## 6. Çevre Analizi Örnekleri

### 6.1 Örnek 05: Hızlı yazım ve referans yönü

**Verilen.** Solda 42 V kaynak, üstte 6 Ω, ortak kolda 3 Ω, üstte 4 Ω, sağda 10 V kaynak.

**Denklemler.** Birinci çevre:

$$-42 + 6 i_1 + 3(i_1 - i_2) = 0$$

İkinci çevrede ortak koldaki referansa eksi ucundan girildiği için gerilim eksi işaretle alınır. Net akım $i_1 - i_2$ olduğundan:

$$-3(i_1 - i_2) + 4 i_2 - 10 = 0 \quad \Rightarrow \quad 3(i_2 - i_1) + 4 i_2 - 10 = 0$$

**Hızlı yazım.** Buradan pratik bir kural çıkar. Direnç elemanları için yön tanımlamaya gerek kalmaz. Hangi çevre yazılıyorsa o çevrenin akımı pozitif alınır, komşu çevre akımı çıkarılır: birinci çevrede $3(i_1 - i_2)$, ikinci çevrede $3(i_2 - i_1)$. Tek kola yalnız bir çevre akımı etki ediyorsa doğrudan $6 i_1$ ya da $4 i_2$ yazılır. Kaynakta ise eksisinden giriliyorsa eksi işaretiyle denkleme katılır. Arkadaki mantık, elemanın eksi referansından girmektir. Hangisi kolay geliyorsa o kullanılabilir.

**Düzenleme ve sonuç** (ara adım eklendi):

$$9 i_1 - 3 i_2 = 42, \qquad -3 i_1 + 7 i_2 = 10$$

Çözüm $i_1 = 6$ A, $i_2 = 4$ A'dir (python ile hesaplandı). 3 Ω'dan geçen net akım, gerilim referansının artıdan eksiye yönünde $i_1 - i_2 = 2$ A'dir.

**Yönler ters seçilirse.** Hoca 6 Ω ve 4 Ω'luk elemanların gerilim yönlerini tersine çevirip aynı denklemin çıkacağını göstermek istedi. İlk yazdığı $-42 - 6 i_1 + \dots$ biçimi farklı bir sistem verdi ve "denklem sisteminin bozulmaması gerekiyordu" diyerek durup düzeltti. Doğru akıl yürütme şudur: Gerilim yönü ters seçilince elemanın akımı da onunla uyumlu tanımlanır, yani büyük $I$ akımı $i_1$'in tersidir: $I = -i_1$. Elemanın eksisinden girildiği için terim $-6 I$ olur, bu da $+6 i_1$ eder:

$$-42 - 6 I + 3(i_1 - i_2) = -42 + 6 i_1 + 3(i_1 - i_2) = 0$$

Böylece aynı denklem sistemine dönülür.

> **Hocanın vurgusu:** Temel kural, direnç elemanlarında gerilim yönü ile akım yönünü uyumlu seçmektir. Bu uyum sağlanınca yönler keyfi seçilse bile denklem sistemi aynı yapıya oturur.

### 6.2 Örnek 06: Ortak kolda kaynak ve güç

**Verilen.** Solda 5 V kaynak, üstte 4 Ω ve 5 Ω, ortak kolda 2 Ω ile seri 2 V kaynak, sağda 1 V kaynak. İki çevre de saat yönündedir. İstenen, 2 V'luk kaynağın sisteme verdiği güçtür.

**Birinci çevre.** 5 V kaynağın eksisinden girilir, 2 V kaynağın da eksisinden girilir:

$$-5 + 4 i_1 + 2(i_1 - i_2) - 2 = 0 \quad \Rightarrow \quad 6 i_1 - 2 i_2 = 7$$

**İkinci çevre.** 2 V kaynağın artısından girilir:

$$2 + 2(i_2 - i_1) + 5 i_2 + 1 = 0 \quad \Rightarrow \quad -2 i_1 + 7 i_2 = -3$$

**Sonuç.** $i_1 = 43/38 = 1.13$ A, $i_2 = -2/19 = -0.105$ A (python ile hesaplandı).

**Güç.** Önce kol akımının işareti yorumlanır. $i_1$ saat yönünde pozitif, $i_2$ saat yönünde negatif çıktı. Ortak koldaki net akım tanımlanan yönde pozitiftir ve kaynağa eksi ucundan girip artı ucundan çıkar. Kaynak sisteme güç vermektedir:

$$p = -2 (i_1 - i_2) = -2 (1.13 + 0.105) = -2.47 \text{ W}$$

Negatif çıkması, kaynağın sisteme enerji verdiğini gösterir. Tam değer $-47/19 = -2.474$ W'tır (python ile hesaplandı).

## 7. Süper Çevre (Supermesh)

Düğüm analizindeki süper düğüm gibi çevre analizinde de süper çevre tanımlanır. Bir akım kaynağı iki çevrenin ortak kolundaysa çevre akımlarının farkı kaynak tarafından sınırlanır:

$$i_1 - i_2 = I_S$$

Bu, sisteme gelen ek bir kısıt denklemidir. İki durum birbirinin karşılığıdır:

| | Süper düğüm | Süper çevre |
|---|---|---|
| Kaynak | Gerilim kaynağı | İki çevrede ortak akım kaynağı |
| Kaynağın belirlediği | Uçları arasındaki gerilim | Kolun akımı |
| Komşuların belirlediği | Kaynağın akımı | Kaynağın gerilimi |
| Yapılan işlem | İki ucun düğümleri birleştirilir | İki çevre birleştirilir |

Çevreleri birleştirmek, alınan çevrelerde ortak akım kaynağı bulunmaması demektir. İki alt gözü almak yerine bir alt göz ile genel çevre alınırsa ortak akım kaynağı giderilir. Böylece kaynağın bilinmeyen gerilimi denkleme girmez ve denklem sayısı bir azalır. Yine de üstteki yolla, yani ayrı çevrelerle de çözüm mümkündür. Süper çevre yalnızca denklemleri pratikleştirir.

Hoca bunu daha önceki bir benzetmeyle ilişkilendirdi: Bir kolda seri iki direnç olduğunda aradaki düğümü ayırıp ayrı denklem yazmak mümkündür, ama gerek yoktur; akım, düğümler arası gerilim farkının toplam dirence bölünmesiyle yazılır. Süper düğüm ve süper çevrenin katkısı da böyledir: Denklem sistemini basitleştirir.

### 7.1 Örnek 07

**Verilen.** Solda 7 V kaynak. Ortada üstte 1 Ω, altında 7 A akım kaynağı ve 2 Ω. Sağda üstte 2 Ω, altta 1 Ω. Orta düğüm ile sağ düğüm arasında 3 Ω.

<!-- BELİRSİZ: Devre şeması altyazıda okunmuyor, yerleşim kısa nottan alındı. Denklemler altyazıyla uyumludur. Süper çevreye ortadaki 2 Ω girmez. -->

Üç göz vardır ve 7 A kaynağı hem $i_1$ hem $i_3$ çevresinde ortaktır. Bu yüzden bunlar ayrı alınmaz. Üç bilinmeyen için üç denklem gerekir: Birinci çevre kaynağı atlayan geniş bir çevre (derste mavi işaretlenen çevre) olarak alınır, ikinci çevre küçük göz olarak kalır, üçüncü denklem de ortak akım kaynağından gelir.

**Süper çevre.** 7 V'un eksisinden girilir. 1 Ω'da $i_1$ ve $i_2$ etkilidir, net akım $i_1 - i_2$. 3 Ω'da $i_3$ ve $i_2$ etkilidir, referans yönünde net akım $i_3 - i_2$. Son 1 Ω'da yalnız $i_3$ etkilidir:

$$-7 + 1(i_1 - i_2) + 3(i_3 - i_2) + 1\,i_3 = 0$$

**İkinci çevre.** Hızlı yazımla:

$$1(i_2 - i_1) + 2 i_2 + 3(i_2 - i_3) = 0$$

Hoca 3 Ω'luk terimin nedenini bir kez daha açtı: Elemanın referans yönünde net akımı $I_3 = i_3 - i_2$'dir. İkinci çevrede elemanın eksi ucundan girildiği için terim $-3(i_3 - i_2)$ olur, bu da $3(i_2 - i_3)$ eder.

**Kısıt.** Akım kaynağının bulunduğu kola $i_1$ ve $i_3$ katkı yapar, $i_3$ negatif yönde. Koldaki net akımı kaynak belirlediğinden:

$$i_1 - i_3 = 7$$

Akım kaynağının üzerindeki gerilimi ise çevredeki elemanlar belirler, bu yüzden geniş çevre onu atlayarak yazılır.

**Sonuç.** $i_1 = 9$ A, $i_2 = 2.5$ A, $i_3 = 2$ A (python ile hesaplandı). Kısa nota göre istenen akım $i = i_3 - i_2 = -0.5$ A'dir.

## 8. Düğüm mü, Çevre mi? Düzlemsel Devreler ve Karşılaştırma Örneği

Hangi yöntemin pratik olduğu devreye bağlıdır. Örnek 07 çevre analiziyle üç denklem ister ve bunlardan biri çok basittir. Düğüm analiziyle ise dört düğüm üzerinden tanımlamak gerekir, bu yüzden çevre analizi daha pratiktir. Daha önce incelenen iki gözlü devrede de beş düğüme karşılık iki çevre vardı. Başka devrelerde düğüm analizi daha pratik olabilir.

### 8.1 Düzlemsel devre

Düzlemsel (planar) devre, hiçbir eleman ya da kablo başka bir kablonun üzerinden geçmeden çizilebilen devredir. Düzlemsellik, kaç denklem gerektiğini belirlemek açısından önemlidir. Düzlemsel devrelerde düğüm ve göz sayısı doğrudan sayılır. Düzlemsel olmayanlarda daha dikkatli saymak gerekir. Bu derste çözülen devreler genelde düzlemseldir.

Bazı devreler ilk bakışta düzlemsel görünmez. Bir düğüm ortaya taşınınca ya da dirençler dışarı alınınca düzlemsel olduğu ortaya çıkar. Düzlemsel olmayan devreler ise üç boyutlu bağlantı gerektiren, iki boyutlu düzlemde kablolar birbirinin üzerinden geçmeden çizilemeyen devrelerdir.

### 8.2 Karşılaştırma örneği: Düğüm analiziyle

**Verilen.** 100 V kaynak ile seri 8 Ω, sonra $v_1$ düğümü. $v_1$'den toprağa 4 Ω. $v_1$ ile $v_2$ arasında 2 Ω ($i_x$ sağa doğru). $v_2$'den toprağa 3 Ω. $v_2$ ile $v_3$ arasında 10 Ω. $v_3$'ten toprağa 5 Ω. 8 A akım kaynağı $v_3$'ten $v_2$'ye doğru. İstenen $i_x$.

**Sayım.** Referans dahil beş düğüm vardır, yani dört denklem gerekir. Ancak referans kaynağın eksi ucunda seçildiğinden kaynağın öbür ucu doğrudan 100 V'tur. Geriye $v_1$, $v_2$, $v_3$ kalır.

**$v_1$ düğümü:**

$$\frac{v_1 - 100}{8} + \frac{v_1}{4} + \frac{v_1 - v_2}{2} = 0$$

**Soru:** İlk terimi $\frac{v_1 - 100}{8}$ diye yazdık. 100 V daha büyük olduğu için tersi yazılmamalı mı? **Cevap:** Hoca kontrol etti. Girenler çıkanlara eşitlenirse $\frac{100 - v_1}{8} = \frac{v_1 - v_2}{2} + \frac{v_1}{4}$ yazılır. Terim karşıya atılınca işareti değişir ve aynı denklem çıkar.

**$v_2$ düğümü.** Girenler $i_x$ ve 8 A, çıkanlar 10 Ω ve 3 Ω kollarıdır:

$$\frac{v_1 - v_2}{2} + 8 = \frac{v_2 - v_3}{10} + \frac{v_2}{3} \quad \Rightarrow \quad \frac{v_2 - v_1}{2} + \frac{v_2}{3} + \frac{v_2 - v_3}{10} - 8 = 0$$

**$v_3$ düğümü:**

$$\frac{v_2 - v_3}{10} = 8 + \frac{v_3}{5} \quad \Rightarrow \quad \frac{v_3 - v_2}{10} + \frac{v_3}{5} + 8 = 0$$

**Sonuç.** $v_1 = 25.89$ V, $v_2 = 20.31$ V, $v_3 = -19.90$ V (python ile hesaplandı). İstenen akım:

$$i_x = \frac{v_1 - v_2}{2} = \frac{25.89 - 20.31}{2} = 2.79 \text{ A}$$

### 8.3 Aynı devre çevre analiziyle

Dört ayrık göz vardır. Hoca denklemleri hızlı yazımla, yazılan çevrenin akımını pozitif alarak kurdu:

$$-100 + 8 i_1 + 4(i_1 - i_2) = 0$$

$$4(i_2 - i_1) + 2 i_2 + 3(i_2 - i_3) = 0$$

$$3(i_3 - i_2) + 10(i_3 - i_4) + 5 i_3 = 0$$

Dördüncü denklem akım kaynağından gelir. Bu kolda akan akımı kaynak belirler ve kaynağın yönü çevre yönüne terstir:

$$i_4 = -8 \text{ A}$$

Değeri belli olduğundan yerine yazılıp üç denkleme düşülür (ara adım eklendi):

$$12 i_1 - 4 i_2 = 100, \qquad -4 i_1 + 9 i_2 - 3 i_3 = 0, \qquad -3 i_2 + 18 i_3 = -80$$

$i_x$ için ek işlem gerekmez, çünkü $i_2$'nin kendisidir. Çözüm $i_1 = 9.26$ A, $i_2 = i_x = 2.79$ A, $i_3 = -3.98$ A'dir (python ile hesaplandı). İki yöntem aynı sonucu verir.

## 9. Devre Teoremlerine Giriş

Kirchhoff yasalarıyla her devre çözülebilir, ama doğrudan kullanıldığında denklemler karmaşıklaşır. Düğüm gerilimleri ve sanal çevre akımları bu işi bir adım basitleştirdi. Yeni konudaki teoremlerin amacı da aynıdır: devre çözümlemeyi basitleştiren pratik yöntemler. Sıradaki konular şunlardır:

- Doğrusallık ve toplamsallık: Birden fazla kaynak varsa her seferinde bir kaynak bırakılıp diğerleri sıfırlanır. Tekil etkilerin net toplamı, bütün kaynaklar devredeyken elde edilen çözüme eşittir. Bu bizi süperpozisyon teoremine götürür.
- Kaynak dönüşümü: Bir akım kaynağı ve paralel direnç, bir gerilim kaynağı ve seri direnç olarak yazılabilir. Tersi de geçerlidir. Örneğin karmaşık bir devrede bir kaynak dönüşümüyle bütün elemanlar birbirine paralel hâle gelebilir.
- Thevenin ve Norton eşdeğerleri: Karmaşık bir devre, herhangi iki ucundan bakıldığında bir gerilim kaynağı ve seri direnç (Thevenin) ya da bir akım kaynağı ve paralel direnç (Norton) olarak gösterilebilir. Kaynak dönüşümünden bu eşdeğerlere geçilir.
- Maksimum güç: İdeal olmayan kaynaklarda en büyük gücü elde etmek için kullanılması gereken yük direnci hesaplanır.

> **Ders sonrası not:** Hoca eşdeğer devreyi "pasif elemanlardan oluşan yapı" için anlattı ve ayrıca "ideal kaynaklar arasında dönüşüm" dedi. Yalnız pasif elemanlardan oluşan bir devrenin iki ucundan bakıldığında kaynak görülmez. Burada kastedilen büyük olasılıkla doğrusal elemanlardan oluşan devredir. Kaynak dönüşümü de büyük olasılıkla, hocanın aynı anlatımda söylediği gibi seri ya da paralel direnci olan kaynaklar için geçerlidir, direnci olmayan ideal kaynak için değil.

## 10. Doğrusallık

### 10.1 Doğrusal fonksiyon

Doğrusal sistemler, girdi ile çıktı arasındaki ilişkisi orijinden (sıfıra sıfır noktasından) geçen bir doğru olan sistemlerdir: $f(x) = c\,x$. Buradaki $c$ değeri, doğrunun yatayla yaptığı açıyla ilgili eğimdir. $f(x) = ax + b$ biçimindeki fonksiyon ise grafikte yine bir doğrudur, ama orijinden geçmediği için doğrusal sayılmaz. Hoca buna ötelenmiş doğrusal grafik diyor.

### 10.2 Birinci koşul: Çarpımla ölçekleme

Doğrusal bir $f$ fonksiyonu girdi bir sabitle çarpıldığında şu özelliği sağlar:

$$f(a x) = a\,f(x)$$

$f(x) = c x$ için bu sağlanır: $f(ax) = c \cdot a x = a \cdot (c x) = a f(x)$.

$f(x) = e x + f$ biçimindeki fonksiyon için (katsayılar karışmasın diye $e$ ve $f$ kullanıldı) sağlanmaz:

$$f(ax) = e a x + f, \qquad a\,f(x) = e a x + a f$$

Birinci terimler tutar, ikinci terimlerde $f$ ile $a f$ farklıdır.

### 10.3 İkinci koşul: Toplamsallık

Genişletilmiş hâli, girdinin doğrusal bir birleşimi için geçerlidir:

$$f(a x_1 + b x_2) = f(a x_1) + f(b x_2) = a\,f(x_1) + b\,f(x_2)$$

Devre teorisi açısından anlamı şudur: Sisteme iki kaynak bağlıysa önce yalnız birinci kaynak devrede bırakılıp çözülür ve sonuç not edilir. Sonra yalnız ikinci kaynak bırakılıp çözülür. İkisi toplanınca iki kaynak birlikte devredeyken elde edilecek sonuç bulunur.

### 10.4 Devre elemanlarının tanım bağıntıları

Bir elemanın tanım bağıntısı, gerilimine karşı akımının grafiğidir. Direnç için gerilim sıfırken akım da sıfırdır, gerilim arttıkça doğrusal bir ilişki elde edilir. Eğim $V/I = R$ değerinde ve sabittir. Bu yüzden direnç doğrusal bir elemandır.

Hoca aynı grafiği kaynaklar için sordu. Kaynakların tanımı yanıtı verir:

- İdeal akım kaynağı: Bağlı olduğu kola verdiği akım, uçları arasındaki gerilim ne kadar değişirse değişsin sabittir. Grafikte $I = I_S$ yatay bir çizgidir.
- İdeal gerilim kaynağı: Bağlı olduğu koldan geçen akım ne kadar değişirse değişsin uçları arasındaki gerilim sabittir.

Hoca karşılaştırma için, bu dersin konusu olmasa da, diyot bağıntısını da çizdi: Belirli bir noktaya kadar akım geçmez, o noktadan sonra gerilim arttıkça akım üstel olarak artar.

### 10.5 Çevre akımlarında toplamsallık

Doğrusallık aslında çevre analizinde zaten kullanıldı. Çevre akımlarının direnç üzerindeki net etkisi, her birinin tekil etkisinin net toplamına eşittir. $i_1$'in $V_3$'e tekil etkisi ile $i_2$'nin $V_3$'e tekil etkisinin toplamı, birlikte etkilerine eşittir.

### 10.6 Doğrusal olmayan örnek: Güç

Güç, akım ile gerilimin çarpımıdır. Akımın ya da gerilimin karesi cinsinden de yazılır:

$$p = v\,i = i^2 R = \frac{v^2}{R}$$

Girdiye göre karesel olduğundan sabit bir eğimden söz edilemez. Gücün akıma göre türevi, verilen akım değerine göre değişir. Direncin gerilim-akım bağıntısında ise eğim her noktada sabittir.

> **Ders sonrası not:** Altyazıda bu ifade "V kare R veya V kare bölü R" diye geçiyor. Doğrusu $i^2 R$ ve $v^2/R$'dir.

### 10.7 Doğrusal ve doğrusal olmayan bileşenler

Doğrusal bileşenler:

- Direnç, endüktans, kapasite.
- Bağımsız akım ve gerilim kaynakları.
- Doğrusal kontrol edilen bağımlı kaynaklar. Katsayı sabitse kaynak doğrusal kontrol edilir: $a\,i_x$, $b\,v_x$. Burada $i_x$ ve $v_x$, devrenin başka bir kolundaki akım ya da başka bir düğümündeki gerilimdir.

Doğrusal olmayan bileşenler:

- Diyot ve LED. LED de aslında bir diyot yapısıdır. Silisyum diyotta 0.7 V'a kadar akım geçmez (uygulamada kaçak akımlar olur, ama sıfır kabul edilebilir), bu değer aşıldıktan sonra akım üstel olarak artar.
- Transistör.
- Manyetik anahtar. Kapanabilmesi için akımın manyetik alan etkisi oluşturması gerekir.
- Doğrusal olmayan biçimde kontrol edilen bağımlı kaynaklar: $a\,i_x^2$ ya da $b\,v_x^2$ gibi.

Genel olarak tanım bağıntısı orijinden geçmeyen ve eğimi sabit olmayan bağıntılar doğrusal olmayan bileşenleri gösterir. $a$ ve $b$ sıfırdan farklı olmak üzere $f(x) = ax + b$ eğimi sabit olsa bile orijinden geçmediği ve $f(ax) = a f(x)$ koşulunu sağlamadığı için doğrusal değildir.

<!-- BELİRSİZ: Manyetik anahtar için altyazıda "zöleliği yapılar" geçiyor (04:23:42), kelime çözülemedi. Slayttaki listenin tamamı altyazıda okunmuyor. -->

> **Ders sonrası not:** Hoca transistörde baz akımına göre kolektör-emetör geriliminin üstel değiştiğini söyledi. Bilinen üstel ilişki büyük olasılıkla baz-emetör gerilimi ile kolektör akımı arasındadır. Hoca slayttaki "SCR" kısaltmasını hatırlayamadı. Bu listede büyük olasılıkla silisyum kontrollü doğrultucu (tristör) kastedilmektedir, yani o sırada anılan "selektif katalitik indirgeme" değildir.

> **Ek bilgi (derste anlatılmadı):** Bağımsız kaynakların tanım bağıntısı orijinden geçmeyen yatay bir çizgidir, yine de doğrusal bileşenler arasında sayıldılar. Bu, "orijinden geçme" ölçütüyle ilk bakışta çelişir. Devre teorisinde kaynaklar büyük olasılıkla girdi olarak görülür: Doğrusallık, devredeki akım ve gerilimlerin kaynak değerlerine doğrusal bağlı olması anlamına gelir. Süperpozisyonun kaynak değerleri üzerinden işlemesi de bu yüzdendir.

## 11. Kaynakları Sıfırlamak

> **Hocanın vurgusu:** Sıfırlamak burada anahtar kelimedir. Bir gerilim ya da akım kaynağının nasıl sıfırlandığı önemli bir konudur.

**Soru:** Bir gerilim kaynağını sıfırlamak için ne yaparız? Sohbetten gelen öneri, ters yönde bir kaynak daha bağlamaktı. **Cevap:** Hoca bunun soruyu karşılamadığını söyledi: Elimizde iki kaynak olmuş olur, oysa kaynağı sıfırlamak istiyorduk. Asıl soru, yol ya da yöntem değil, $V = 0$ olduğunda bu elemanın eşdeğerinin ne olduğudur.

**Gerilim kaynağı.** Sıfırlanan gerilim kaynağının eşdeğeri kısa devredir, yani yerine bir tel konur. Uçlar $A$ ve $B$ ise aynı tel üzerindeki bütün noktalar aynı gerilimdedir, $V_A = V_B$ ve $V_{AB} = 0$ olur.

**Akım kaynağı.** Sıfırlanan akım kaynağının eşdeğeri açık devredir, sonsuz direnç olarak da düşünülebilir. $A$ ile $B$ arasında sıfırdan farklı bir $V_{AB}$ olabilir, ama aralarında akan akım kesinlikle sıfırdır.

### 11.1 Süperpozisyon örneği 01

**Verilen.** 10 Ω direnç, 5 V gerilim kaynağı ve 2 A akım kaynağı birbirine paraleldir. İstenen, 10 Ω'dan geçen akım $I$'dır. Devredeki bütün bileşenler doğrusal olduğundan tekil katkılar toplanabilir.

**Yalnız 5 V.** Akım kaynağı açık devre olur:

$$I_1 = \frac{5}{10} = 0.5 \text{ A}$$

**Yalnız 2 A.** Gerilim kaynağı kısa devre olur. Direncin iki ucu aynı gerilime sahiptir, gerilim farkı sıfırdır, bu yüzden akım direnç üzerinden akmaz:

$$I_2 = 0$$

**Toplam.** $I = I_1 + I_2 = 0.5$ A.

**Doğrudan çözümle sağlama.** Bütün elemanlar paralel olduğundan her birinin gerilimini gerilim kaynağı belirler. 2 A'lik kaynağın bu gerilime etkisi yoktur. 10 Ω'daki gerilim doğrudan 5 V, akım da 0.5 A'dir. Aynı sonuç elde edilir.

**Soru:** İkinci durumda neden akım sıfır? **Cevap:** Direncin uçları arasındaki gerilim farkı sıfır olduğu için.

## 12. Süperpozisyon Teoremi

Hoca burada doğrusallıkla ilgili bazı örnekleri atlayıp doğrudan süperpozisyona geçti. Bu örneklerde bağımlı kaynaklar da olduğu için önce bunların nasıl ele alınacağını anlatmanın daha uygun olduğunu söyledi.

Süperpozisyon, bir elemanın akımının ya da geriliminin, o elemana etki eden bütün kaynakların tekil katkılarının yönlü toplamına eşit olduğunu söyler. Tek tek her kaynağın etkisini hesaplayıp toplamak, devreyi bütün hâliyle çözmeye eşdeğerdir. Teorem hem DC hem AC sistemler için geçerlidir. Şu aşamada DC analiz yapılıyor, AC analize geçildiğinde teorem yeniden kullanılacaktır.

Adımlar:

1. Yalnız bir bağımsız kaynak aktif bırakılır.
2. Diğer bağımsız kaynaklar sıfırlanır: Gerilim kaynağı kısa devre, akım kaynağı açık devre olur.
3. Bağımlı kaynaklar olduğu gibi bırakılır, kaldırılmaz.
4. Devre çözülür ve kaynağın ilgilenilen elemanın akımına ya da gerilimine katkısı not edilir.
5. Aynı işlem her bağımsız kaynak için tekrarlanır.
6. Tekil katkılar toplanır.

> **Hocanın vurgusu:** Referans yönüne özellikle dikkat edilmelidir. Bir eleman için belirlenen akım ve gerilim yönü, bütün tekil kaynak durumlarında aynı tutulmalıdır.

> **Ek bilgi (derste anlatılmadı):** Güç doğrusal olmadığından (bölüm 10.6) katkılar güce doğrudan uygulanmaz. Aşağıdaki Örnek 6'nın $R_2 = 30\ \Omega$ direnci için tekil güçlerin toplamı $0 + 120 + 30 = 150$ W ederken, net akımla bulunan güç $1^2 \cdot 30 = 30$ W'tır (python ile hesaplandı). Önce akım ya da gerilim süperpozisyonla bulunur, güç ondan sonra hesaplanır.

### 12.1 Süperpozisyon örneği 6

**Verilen.** 3 V kaynak ($V_1$, artı ucu üstte), seri $R_1 = 50\ \Omega$, sonra $A$ düğümü. $A$'dan toprağa $R_3 = 20\ \Omega$. $A$ ile $B$ arasında $R_2 = 30\ \Omega$ ve ona paralel 2 A kaynak ($A$'dan $B$'ye). $B$'den toprağa 1 A kaynak. Üç bağımsız kaynak olduğundan üç eşdeğer devre oluşturulur.

<!-- BELİRSİZ: Devre şeması altyazıda okunmuyor. Yerleşim kısa nottan alındı; altyazıdaki 3/70 A, -2 A ve 30 Ω ile tutarlıdır. Hoca 1 A durumunun sayılarını slaydı göstererek geçti, rakamları altyazıda yok. -->

**Yalnız $V_1$.** İki akım kaynağı da açık devre olur. $R_2$'nin bir ucu boşta kalır. Devre $V_1$, $R_1$, $R_3$'ten oluşan tek bir çevreye iner:

$$I_{R_1} = I_{R_3} = \frac{3}{50 + 20} = \frac{3}{70} \text{ A} = 42.9 \text{ mA}, \qquad I_{R_2} = 0$$

**Yalnız 2 A.** Gerilim kaynağı kısa devre, 1 A kaynağı açık devre olur. $A$ düğümü ile $R_1$, $R_3$'ün bağlandığı uçların hepsi aynı gerilimdedir ve bu dirençlerden akım akması mümkün değildir. 2 A kaynağı ile $R_2$ kendi kapalı çevresini oluşturur:

$$I_{R_1} = 0, \qquad I_{R_3} = 0, \qquad I_{R_2} = -2 \text{ A}$$

Eksi işareti, $R_2$ için seçilen yönün ($A$'dan $B$'ye) kaynağın oluşturduğu akımın tersi olmasından gelir.

**Yalnız 1 A.** Gerilim kaynağı kısa devre, 2 A kaynağı açık devre olur. Bu kez kısa devre durumu oluşmaz, üç dirençten de akım geçer. Kaynağa $R_2$ ile $R_1 \parallel R_3$ seri görünür (ara adım eklendi):

$$R_{\text{eş}} = 30 + \frac{50 \cdot 20}{50 + 20} = 44.3\ \Omega, \qquad V_A = -1 \cdot \frac{50 \cdot 20}{70} = -14.3 \text{ V}, \qquad I_{R_2} = 1 \text{ A}$$

**Toplam.** Yönlere dikkat edilerek katkılar toplanır (python ile hesaplandı):

| Durum | $V_A$ (V) | $V_B$ (V) | $I_{R_1}$, sağa (mA) | $I_{R_3}$, aşağı (mA) | $I_{R_2}$, $A \to B$ (A) |
|---|---|---|---|---|---|
| Yalnız 3 V | 0.857 | 0.857 | 42.86 | 42.86 | 0 |
| Yalnız 2 A | 0 | 60 | 0 | 0 | $-2$ |
| Yalnız 1 A | $-14.29$ | $-44.29$ | 285.71 | $-714.29$ | 1 |
| Toplam | $-13.43$ | 16.57 | 328.57 | $-671.43$ | $-1$ |

Kısa nota göre slayttaki simülasyon sonuçları da aynıdır: $A$ düğümü $-13.43$ V, $B$ düğümü $16.57$ V, $R_1$ akımı 328.57 mA, $R_3$ akımı topraktan $A$'ya 671.43 mA, $R_2$ akımı 1 A.

### 12.2 Proteus uyarıları

Bu örnekten sonra laboratuvar için hatırlatmalar yapıldı. Hoca, elemanları çalışma alanına almayı, bağlamayı, ampermetre ve voltmetreyi sürükleyip bırakmayı deneyden önce denemiş olmanızı beklediğini söyledi. Kısıtlı süreli yeni sürümde kurulan devreyi kaydetme sorunu yaşanabilir.

> **Hocanın vurgusu:** En sık yapılan hata, bir terminal ucunun boşta kalmasıdır. Arayüz (yakınlaştırma ve kaydırma) alışılandan farklı olduğu için kablo bağlandı sanılırken bir pin ucu bağlantısız kalabilir. Simülasyon başlatıldığında terminalde gri bir uç görülürse orada gerilim boşta salınıyor, yani bağlantı yok demektir.

Önce eleman konup sonra kablo bağlanmalıdır, kablo sürüklenirken de bir ucun boşta kalmamasına dikkat edilmelidir.

**Soru:** Kısa devre yapılan bir bağlantıda simülasyon hata verdi. **Cevap:** Fiziksel bir devrede kaynağın uçları kısa devre yapılırsa kaynak yanar. Simülasyonun buna izin vermemesi normaldir.

Hoca, sonraki basit örneği (gerilim ve akım kaynaklı devre) daha önce çözülenlere çok benzediği için atladı ve bağımlı kaynaklı örneğe geçti.

## 13. Bağımlı Kaynaklı Süperpozisyon ve Matrisle Çözüm

### 13.1 Örnek 9: Kurulum

4 A ve 20 V olmak üzere iki bağımsız kaynak ile bir bağımlı gerilim kaynağı ($5\,i_o$) vardır. İstenen, iki bağımsız kaynağın $i_o$ akımına katkılarıdır. Bağımlı kaynak devreden çıkarılmaz.

- Devre 1: Gerilim kaynağı sıfırlanır, yalnız 4 A kalır. Üç gözlü bir devre oluşur.
- Devre 2: Akım kaynağı sıfırlanır, yalnız 20 V kalır. Akım kaynağının kolu açık devre olduğundan iki göz kalır.

Gösterim: $i_o'$, yalnız 4 A kaynağının katkısıdır. $i_o''$, yalnız 20 V kaynağının katkısıdır. Birbirine karışmasın diye üst işaretlerle ayrılır.

> **Hocanın vurgusu:** Bağımlı kaynaklar sıfırlanmaz, her zaman devrede kalır. En önemli kural ve en çok dikkat edilecek nokta budur.

> **Ders sonrası not:** Altyazıda hoca bu açıklamada "bağımsız kaynak dolaylı olarak etkileniyorsa" diyor. Bağlamdan doğrusu "bağımlı kaynak"tır: Bağımlı kaynağın dolaylı etkisi zaten toplamsallık içinde yer alır.

> **Ek bilgi (derste anlatılmadı):** Bağımlı kaynağın değeri devredeki başka bir akım ya da gerilim tarafından belirlendiğinden büyük olasılıkla kendi başına bir uyarım sayılmaz. Her alt devrede bağımlı kaynak o alt devrenin $i_o'$ ya da $i_o''$ akımıyla birlikte hesaba girer.

### 13.2 Devre 1: Yalnız 4 A

**Birinci çevre.** Çevrede bir akım kaynağı vardır ve yönü çevreyle aynıdır, bu yüzden çevre akımını kaynak belirler: $i_1 = 4$ A.

**İkinci çevre.** Bağımlı kaynağın eksisinden girilir:

$$3(i_2 - i_1) + 2 i_2 - 5 i_o' + (i_2 - i_3) = 0 \quad \Rightarrow \quad -3 i_1 + 6 i_2 - i_3 - 5 i_o' = 0$$

**Üçüncü çevre.**

$$5(i_3 - i_1) + 1(i_3 - i_2) + 5 i_o' + 4 i_3 = 0 \quad \Rightarrow \quad -5 i_1 - i_2 + 10 i_3 + 5 i_o' = 0$$

**$i_o'$ akımı.** Bu kol akımına $i_1$ ve $i_3$ etki eder:

$$i_o' = i_1 - i_3$$

### 13.3 Denklem sistemini matrise geçirmek

Hoca bu geçişin çoğu zaman otomatik yapıldığı için gözden kaçabileceğini söyleyerek adım adım gösterdi. Bilinmeyenler sırayla $i_1$, $i_2$, $i_3$, $i_o'$ alınır. Her denklemde her bilinmeyenin katsayısı aynı sütuna yazılır. Son denklem önce $i_1 - i_3 - i_o' = 0$ biçimine getirilir:

$$
\begin{bmatrix}
1 & 0 & 0 & 0 \\
-3 & 6 & -1 & -5 \\
-5 & -1 & 10 & 5 \\
1 & 0 & -1 & -1
\end{bmatrix}
\begin{bmatrix} i_1 \\ i_2 \\ i_3 \\ i_o' \end{bmatrix}
=
\begin{bmatrix} 4 \\ 0 \\ 0 \\ 0 \end{bmatrix}
$$

Bu sistem Gauss eliminasyonu ya da determinant yöntemiyle veya matrisin tersini alarak çözülür. $A I = T$ denkleminin iki tarafı soldan $A^{-1}$ ile çarpılır. Bir matrisin tersiyle çarpımı birim matristir, birim matris de etkisiz elemandır:

$$I = A^{-1} T$$

Hoca bunu derste MATLAB'da yaptı:

```matlab
A = [1 0 0 0; -3 6 -1 -5; -5 -1 10 5; 1 0 -1 -1];
T = [4; 0; 0; 0];
inv(A) * T
```

Sonuç: $i_1 = 4$ A, $i_2 = 4.7059$ A, $i_3 = 0.9412$ A, $i_o' = 52/17 = 3.0588$ A (python ile hesaplandı, derste okunan 3.0588 ile aynıdır).

> **Ders sonrası not:** Son satır altyazıda "1, 0, 1, 1" diye okunuyor. Denklem $i_1 - i_3 - i_o' = 0$ olduğundan doğrusu $1, 0, -1, -1$'dir. Python ile hesaplandı: "1, 0, 1, 1" ile $i_o' = -10.82$ A çıkar, doğru katsayılarla derste okunan 3.0588 A çıkar. Ayrıca hoca 3.0588 değerini "$I_3$ için" dedi; bu değer dördüncü bilinmeyen olan $i_o'$'ye aittir. "A çarpı T" dediği işlem de $A^{-1} T$'dir.

### 13.4 Devre 2: Yalnız 20 V

Çevre akımlarına $i_4$ ve $i_5$ denir.

**Birinci çevre:**

$$3 i_4 + 2 i_4 - 5 i_o'' + (i_4 - i_5) = 0 \quad \Rightarrow \quad 6 i_4 - i_5 - 5 i_o'' = 0$$

**İkinci çevre.** 20 V ile başlanır:

$$-20 + 5 i_5 + (i_5 - i_4) + 5 i_o'' + 4 i_5 = 0 \quad \Rightarrow \quad -i_4 + 10 i_5 + 5 i_o'' = 20$$

**Üçüncü denklem.** $i_o''$ tanımlı olan kolda $i_5$ ters yönde akar, bu yüzden $i_5 = -i_o''$, yani $i_5 + i_o'' = 0$.

Hoca ilk denemede ikinci çevredeki 4 Ω'luk direnci atladı, $i_5$ katsayısını 6 yazdı ve sonuç tutmadı (python ile hesaplandı: bu hâliyle $i_o'' = -12$ A çıkar). Denklemi yeniden kontrol edip katsayıyı 10 yaparak düzeltti:

```matlab
B = [6 -1 -5; -1 10 5; 0 1 1];
Z = [0; 20; 0];
inv(B) * Z
```

Sonuç: $i_o'' = -60/17 = -3.5294$ A (python ile hesaplandı, derste okunan değerle aynıdır).

### 13.5 Toplam

Birinci alt devreden $3.0588$ A, ikinci alt devreden $-3.5294$ A geldi. Net etki bunların toplamıdır:

$$i_o = i_o' + i_o'' = \frac{52}{17} - \frac{60}{17} = -\frac{8}{17} = -0.4706 \text{ A}$$

Akım, tanımlanan aşağı yönün tersinde yaklaşık 0.47 A'dir.

> **Ders sonrası not:** Sonuç, aynı devrenin iki kaynak birlikte devredeyken doğrudan çözümüyle karşılaştırıldı: Dört bilinmeyenli sistemin sağ tarafı $(4, 0, 20, 0)$ alındığında yine $i_o = -8/17$ A çıkar (python ile hesaplandı).

## Dersin Toparlaması

Bu derste düğüm ve çevre analizi kavramsal olarak tamamlandı. Düğüm analizi Kirchhoff'un akımlar yasasına dayanır ve $n-1$ denklem ister; gerilim kaynağı denklem sistemine ek bir denklem getirir, süper düğümde kaynağın uçları tek düğüm gibi ele alınır. Çevre analizi Kirchhoff'un gerilimler yasasına dayanır ve göz sayısı kadar denklem ister; iki çevrede ortak bir akım kaynağı varsa süper çevre kullanılır ve akım kaynağı bir kısıt denklemi getirir. Hangi yöntemin seçileceğini denklem sayısı belirler.

İkinci kısımda doğrusal sistem tanımından yola çıkılarak süperpozisyon teoremine ulaşıldı. Bağımsız kaynaklar tek tek devrede bırakılır, diğerleri sıfırlanır, bağımlı kaynaklar ise devrede kalır. Tekil katkıların toplamı devrenin çözümünü verir. Denklem sistemlerinin matrisle nasıl çözüldüğü de uygulamalı olarak gösterildi. Göreceğimiz teoremlerden yalnız süperpozisyon bitirilebildi; kaynak dönüşümü, Norton ve Thevenin ile maksimum güç teoremleri sonraki derslere kaldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
