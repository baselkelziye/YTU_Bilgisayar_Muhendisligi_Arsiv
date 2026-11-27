# Ders 23 Genişletilmiş Notu: Maliyet ve Karmaşıklık, Ardışıl Devre Temelleri ve Sonlu Durum Makineleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Maliyet faktörü ve karmaşıklık hesabı
- 2. Programlanabilir kombinezonsal devreler
- 3. Ardışıl devrelerin genel yapısı
- 4. Mealy ve Moore makineleri
- 5. Asenkron ve senkron ardışıl devreler
- 6. Durumlar, durum diyagramı ve durum tablosu
- 7. Örnek: 1110 şifre devresi
- 8. Sonlu durum makineleri ve 011010 dizisi örneği
- 9. Standart tasarım birimleri
- 10. Saat işaretinin parametreleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Maliyet faktörü ve karmaşıklık hesabı

Ders bu kayıtta da tablet üzerinde dijital beyaz tahtaya elle yazılarak anlatılır. İlk kısım ders kitabının maliyet faktörü ve karmaşıklık hesabı bölümünün kısa bir özetidir (ekrandan, 00:05:00).

Lojik devrelerde sayısal bir sistem tasarlanırken iki önemli unsur vardır: **maliyet** ve **karmaşıklık**. Maliyet derken devreyi fiziksel olarak gerçekleştirmenin mali yükü kastedilir. Karmaşıklıkta ise daha çok çalışma hızı hesaba katılır. Bunların yanında devrede harcanan güç, tasarım süresi, uyumluluk, transistör sayısı ve gerçeklenebilirlik gibi etkenler de tasarımda göz önünde bulundurulur.

### 1.1 Maliyet

Maliyet iki temel kaleme ayrılır: tasarım maliyeti ve üretim maliyeti.

$$M_{\text{maliyet}} = M_{\text{tasarım}} + M_{\text{üretim}}$$

Tasarım maliyeti, devrenin kurgulanmasını ve devreyi çizmek ya da simüle etmek için kullanılan yardımcı araçların maliyetini içerir. Üretim maliyeti ise devrenin fiziksel olarak gerçekleştirilmesi için harcanan miktardır ve tahtada şöyle yazılır (ekrandan, 00:10:00):

$$M_{\text{üretim}} = M_{\text{makine}} + M_{\text{giderler}}$$

Giderlere elektrik, ortamın havalandırılması ve soğutulması gibi yan masraflar girer.

### 1.2 Karmaşıklık

Karmaşıklık hesabında iki temel kavram vardır (ekrandan, 00:10:00):

- **Eleman karmaşıklığı** (component complexity)
- **Zaman (hız) karmaşıklığı** (time complexity)

Eleman karmaşıklığında şu sayılar dikkate alınır:

- Tüm devre sayısı.
- Farklı tüm devre sayısı. Önceki derslerde konuşulduğu gibi, devre ne kadar benzer tüm devrelerle kurulursa maliyet o kadar düşer.
- Tüm devre uç sayısı. İki girişli ve dört girişli elemanlar karşılaştırılırsa, uç sayısı yüksek olan devre daha çok transistör içerdiği için daha pahalıdır.

Farklı tüm devre kullanmak, her birine ayrı ayrı besleme (VCC) ve toprak hattı çekmeyi de gerektirir; bu da maliyete yansır.

Zaman karmaşıklığında tüm devrenin çalışma hızı ve gecikmeler hesaba katılır.

### 1.3 Katmanlı devrede gecikme

Hoca gecikmeyi iki katmanlı bir devre üzerinde gösterir (ekrandan, 00:10:00). Birinci katmanda iki tane iki girişli VE-DEĞİL kapısı (1 ve 2) vardır; ikinci katmandaki VE-DEĞİL kapısı bu ikisinin çıkışlarını alır.

- Verilen: 1. kapının gecikmesi 15, 2. kapınınki 20 birim.
- İkinci katmanın girişlerinin ikisi de oluşmadan çıkış doğru olmaz. Bu yüzden birinci katman için en büyük gecikme alınır: $\max(15, 20) = 20$.
- Sonuç: toplam gecikme $= 20 + t_{\text{2. katman}}$, yani birinci katmanın en büyük gecikmesine ikinci katmandaki kapının gecikmesi eklenir.

Katman (layer) sayısı arttıkça eklenen gecikmeler de artar. Hocanın ikinci örneğinde bir $A$ girişi doğrudan son kapıya gelirken $B$ ve $C$ önce bir kapıda işlenir, sonra bir $D$ girişiyle birlikte başka bir kapıya girer. $A$ için birinci katmanda bir gecikme yoktur ama $B$ ile $C$'nin geçtiği kapıların elektriksel gecikmeleri hesaba katılmalıdır; çıkış en uzun yola göre oluşur.

<!-- BELİRSİZ: İkinci gecikme örneğinin kapı bağlantıları karede görünmüyor; altyazıdan kuruldu. -->

> **Ders sonrası not:** Hoca gecikmeleri bir yerde milisaniye, bir yerde mikrosaniye olarak söyledi. Gerçek lojik kapıların yayılma gecikmeleri büyük olasılıkla nanosaniye mertebesindedir; sayılar yalnız yöntemi göstermek için verilmiştir.

## 2. Programlanabilir kombinezonsal devreler

Kitapta bundan sonra programlanabilir kombinezonsal devreler bölümü gelir. Bu devrelerde fiziksel olarak tek bir tüm devrenin içinde çok sayıda VE ve VEYA (ya da VE-DEĞİL) kapısı bulunur. Kapılar arasındaki bağlantılar uygun biçimde programlanarak karmaşık bir lojik ifade tek bir tüm devreyle gerçekleştirilir.

Hoca bunu önceki haftalarda yapılan özel amaçlı kombinezonsal devrelerle karşılaştırır: madem her lojik ifade kapılarla kurulabiliyor, hazır kapılar bir yongaya konur ve gerekli uçlar programlama mantığıyla bağlanırsa genel kullanıma yönelik devreler elde edilir. Üç tipi anılır:

- Programlanabilir yalnız okunur bellek (PROM, programmable read-only memory)
- Programlanabilir diziler (programmable arrays)
- Programlanabilir lojik diziler (programmable logic arrays)

Bu bölüm derste ayrıntılı anlatılmadı; öğrencilerin kitaptan okuyup temel mantığını kavraması istendi.

> **Ek bilgi (derste anlatılmadı):** PROM'da VE düzlemi sabit (tam kod çözücü), VEYA düzlemi programlanabilir; PLA'da her iki düzlem de programlanabilir; PAL'da ise VE düzlemi programlanabilir, VEYA düzlemi sabittir. Bu yüzden PLA en esnek, PAL ise daha hızlı ve ucuz bir ara çözümdür.

## 3. Ardışıl devrelerin genel yapısı

Lojik devreler daha önce ikiye ayrılmıştı: **kombinezonsal devreler** (combinational circuits) ve **ardışıl devreler** (sequential circuits). Ardışıl devreler hafızanın devreye girdiği devrelerdir. Ders kitabının ilgili bölümü "Ardışıl Devre Temelleri" başlığını taşır ve genel yapı, Mealy ve Moore makineleri, asenkron ve senkron devreler, durum tablosu ve diyagramı, sonlu durum makineleri, standart tasarım birimleri, kenar ve düzey tetikleme, flip-floplar ve tutucular gibi alt başlıklardan oluşur (ekrandan, 00:15:00).

Kombinezonsal devrede kutuya $t$ anında giren bilgi işlenir ve $t$ anında çıkar. Ardışıl devrede ise $t$ anındaki girişlerin yanında kutunun içindeki bir hafıza biriminden durum bilgileri de girer; çıkış $y(t)$ ya da $z(t)$ bu ikisinden oluşturulur.

Genel yapı şöyledir:

- Bir **kombinezonsal kısım** vardır. İçinde VE, VEYA, XOR, XNOR gibi herhangi kapılar bulunabilir.
- Kombinezonsal kısma girişler $x(t)$ ve mevcut durumlar $d(t)$ girer.
- Kombinezonsal kısım çıkışları ve **bir sonraki durumları** $d(t+1)$ üretir.
- $d(t+1)$, durum bilgilerinin saklandığı **hafıza** kısmına yazılır. Bir sonraki adımda bu bilgi $d(t)$ olarak, $t+1$ anındaki girişle birlikte işlenir.

Burada dikkat edilecek nokta, hafızaya giden bilginin "o anki" değil "bir sonraki" durum olmasıdır: $t$ anında işlenen bilgi, $t+1$ anında girişle birlikte kullanılacak durumu belirler.

## 4. Mealy ve Moore makineleri

Ardışıl devreler iki türde olabilir: **Mealy makinesi** ve **Moore makinesi** (ekrandan, 00:20:00).

### 4.1 Mealy makinesi

Bir kombinezonsal devre (KD) bloğu vardır. Girişi $x(t)$, çıkışı $z(t)$'dir. KD'nin ürettiği bir sonraki durumlar $d(t+1)$ hafıza bloğuna ($d$) gider; hafızadaki durumlar $d(t)$ olarak KD'ye geri beslenir (ekrandan, 00:20:00). Hafızadaki bir durumu, devreye giriş olarak kullanılacak bir bilgi gibi düşünebilirsiniz.

Fonksiyon olarak:

$$z(t) = f\big(x(t),\, d(t)\big), \qquad d(t+1) = g\big(x(t),\, d(t)\big)$$

### 4.2 Moore makinesi

Moore makinesinde de bir kombinezonsal kısım çıkışı $z(t)$'yi üretir, ama bu kısım yalnız durumlarla beslenir. Giriş $x(t)$ ayrı bir kombinezonsal devrede mevcut durumla birlikte işlenir ve bir sonraki durumları $d(t+1)$ üretir; bunlar hafızada saklanır. Hafızadan çıkan durumlar hem çıkışı üreten kısmı hem de sonraki durumu üreten kısmı besler.

$$z(t) = f\big(d(t)\big), \qquad d(t+1) = g\big(x(t),\, d(t)\big)$$

Temel fark: Mealy makinesinde çıkış için hem $x(t)$ hem $d(t)$ etkilidir; Moore makinesinde çıkış için yalnız $d(t)$ etkilidir.

> **Ders sonrası not:** Hoca Moore makinesini anlatırken bir yerde "giriş sadece durumlara bağlı" dedi; kastedilen çıkıştır. Yine bir yerde Mealy'nin sonraki durum fonksiyonu için "aynı Moore makinesindeki gibi" dedi; kastedilen Mealy makinesidir. Doğru bağıntılar yukarıdaki formüllerdir.

## 5. Asenkron ve senkron ardışıl devreler

Ardışıl devreler, girişteki değişikliğin çıkışa ne zaman yansıdığına göre ikiye ayrılır: **asenkron** ve **senkron** (ekrandan, 00:25:00).

### 5.1 Asenkron devreler

Bir asenkron ardışıl devre kutusu düşünelim: giriş $x(t)$, çıkış $z(t)$. Asenkron davranış, girişteki bir değişikliğin herhangi bir bekleme olmaksızın, yalnız devrenin gecikmeleri kadar sonra çıkışa yansıması demektir.

Hocanın çizdiği zaman diyagramında giriş 1'den 0'a düşer; belli bir gecikmeden sonra çıkış değişmeye başlar. Sonra giriş tekrar değişir (0'dan 1'e çıkar); yine bir gecikmeden sonra çıkış tepki verir. Bu gecikmeler (gecikme 1, gecikme 2) birbirinden farklı uzunlukta olabilir. Hoca ayrıca hem girişin hem çıkışın değişirken anlık değil eğimli bir geçiş yaptığını, bunun da bir "oluşma gecikmesi" olduğunu belirtir. Bu gecikmeler devrede kullanılan elemanlardan, kombinezonsal kısmın gecikmelerinden kaynaklanır; devre ne kadar çok katman içeriyorsa gecikme süreleri o kadar uzar.

### 5.2 Senkron devreler ve saat işareti

Senkron devrelerde temelde bir **saat işareti** bulunur. Saat işareti lojik 0 ile 1 arasında gidip gelen bir kare dalga ya da dar bir darbe (impuls) dizisi olarak düşünülebilir (ekrandan, 00:30:00). İdeal olan anlık bir atımdır, yani darbenin oluşma süresi sıfıra gitmelidir; gerçekte ise belli genişlikte bir işaret oluşur.

Saat işareti devreye "şu anda girişlerinde ne varsa onları al" diye uyarı verir. Bunun hangi anda olduğu uygulamaya göre seçilir:

- **Yükselen kenar tetikleme:** işaretin 0'dan 1'e geçtiği anda çalışır.
- **Düşen kenar tetikleme:** işaretin 1'den 0'a geçtiği anda çalışır.
- **Seviye tetikleme:** işaret 1 iken (ya da ters saat işaretiyle 0 iken) çalışır. Bu durumda darbenin dar tutulması gerekir.

Yükselen ve düşen kenar tetiklemeye birlikte **kenar tetikleme** denir. Hangisinin seçileceği tamamen tasarım kararıdır.

Yükselen kenarda çalışan bir devrede yalnız o anlardaki bilgi devre için geçerlidir. Giriş işareti iki tetikleme anı arasında istediği kadar değişebilir; devre yalnız saat darbesinin vurduğu andaki girişe bakar. Çıkış, tetikleme anından belli bir gecikmeyle değişir; devrenin davranışına göre aynı da kalabilir.

> **Hocanın vurgusu:** Senkron devrede senkronlama anı çok önemlidir. Önemli olan, seçilen kenarda (ya da seviyede) girişlerde ne olduğudur.

## 6. Durumlar, durum diyagramı ve durum tablosu

Ardışıl devrede asıl soru, hafıza bloğunun nasıl kullanılacağı ve içinde neyin saklanacağıdır. Durumlar, graf teorisinden hatırlanacağı gibi **düğümlerle** (node) gösterilir.

### 6.1 Sayıcı örneği

0'dan 7'ye sayan bir devre düşünelim: 0, 1, 2, 3, ... diye ilerlenir; 7'den sonra 0'a dönülebilir ya da 7'de kalınabilir (ekrandan, 00:35:00). 2 durumuna geçmek için önce 1 durumundan geçmiş olmak gerekir; yani 2 çıkışının üretilebilmesi için 1 düğümünden oraya gelinmiş olmalıdır. Geçiş bir saat darbesiyle ya da belli bir girişle olur.

### 6.2 Diyagramın gösterimi

İki durum arasındaki geçiş, "giriş/çıkış" biçiminde, eğik çizgiyle ayrılmış bir etiketle gösterilir. Örneğin $D_n$ durumundayken 1 gelirse çıkış 0 olsun ve $D_{n+1}$'e geçilsin: ok üzerine "1/0" yazılır. Kendi üzerine dönen bir ok da "0/0" gibi etiketlenebilir.

Önemli kural: giriş kaç bitlikse, her düğümden girişin **bütün** olasılıkları için bir geçiş tanımlanmalıdır. 1 bitlik girişte hem 1 hem 0 için davranış belirlenir. İki girişli ($x_2 x_1$) bir devrede 00, 01, 10 ve 11 girişlerinin her biri için devrenin nasıl davranacağı bulunmalıdır.

Hocanın örneği: 0'dan 7'ye sayan ve tek sayılarda çıkışı 1 yapan devre. Ayrı bir giriş yoktur; her saat darbesi geldiğinde bir sonraki sayıya geçilir. 0'dan 1'e geçerken çıkış 1, 1'den 2'ye geçerken 0, ve böyle devam eder.

### 6.3 Durum tablosu

Graf yerine aynı bilgi **durum tablosu** ile de verilebilir. Tablonun üç kısmı vardır:

- Şimdiki durumlar $Q(t)$
- Sonraki durumlar $Q(t+1)$ (bazen $Y$ ya da $Q^+$ ile gösterilir)
- Çıkış $Z$

Durumların saklanması için kaç bit gerektiği durum sayısından bulunur. 0 ile 7 arasında 8 farklı durum vardır, bu yüzden 3 bit ($A$, $B$, $C$) gerekir; sonraki durumlar $A^+, B^+, C^+$ diye yazılabilir.

Tablo sözlü olarak şöyle kurulur:

| Şimdiki durum | Sonraki durum | Çıkış |
|---|---|---|
| 0 (000) | 1 (001) | 1 |
| 1 (001) | 2 (010) | 0 |
| 2 (010) | 3 (011) | 1 |
| 3 (011) | 4 (100) | 0 |
| ... | ... | ... |

Diyagram ile durum tablosu arasında iki yönde de geçiş yapılabilir.

## 7. Örnek: 1110 şifre devresi

**Problem:** Basit bir şifreleme devresi tasarlanacak. Devrenin bir girişi ve bir çıkışı var. Giriş bit akışında art arda üç tane 1 ve ardından bir 0 (1, 1, 1, 0) geldiğinde çıkış 1, aksi durumda 0 olmalı (ekrandan, 00:45:00).

Hoca, şifrenin kâğıtta soldan sağa "1110" diye yazıldığını ama akışın zamanda bir bit bir bit geldiğini vurgular: $t$ anında ilk 1, $t+1$'de ikinci 1, $t+2$'de üçüncü 1, $t+3$'te 0 gelir.

### 7.1 Durumların kurulması

- $d_0$: başlangıç; henüz hiçbir şey gelmemiş, ilk 1 bekleniyor. 1 gelirse çıkış 0, $d_1$'e geçilir. 0 gelirse (örneğin akışın başında 0'lar olabilir) çıkış 0, $d_0$'da kalınır.
- $d_1$: "1 gelmiş" durumu. Bir 1 daha gelirse çıkış 0, $d_2$'ye geçilir. 0 gelirse şifre bozulmuştur; çıkış 0, başa ($d_0$) dönülür.
- $d_2$: "11 gelmiş" durumu. 1 gelirse çıkış 0, $d_3$'e geçilir. 0 gelirse (110) şifre yine bozulur; çıkış 0, $d_0$'a dönülür.
- $d_3$: "111 gelmiş" durumu. Son 0 bekleniyor.

### 7.2 $d_3$'te 0 gelince: iki tasarım seçeneği

Burada iki yol vardır ve hangisinin seçileceği problem tanımına bağlıdır:

- **Başlangıca dönüş:** 0 gelince çıkış 1 olur ve $d_0$'a dönülür (turuncu yol).
- **Kilitleme:** 0 gelince çıkış 1 olur ve dördüncü bir duruma geçilir; bundan sonra ne gelirse gelsin çıkış 1'dir (yeşil yol, "–/1" kendi üzerine dönüş).

> **Hocanın vurgusu:** Turuncu yoldan mı yeşil yoldan mı gidileceği tamamen tasarıma bağlıdır; bunun için problemin iyi tanımlanması gerekir.

### 7.3 $d_3$'te 1 gelince

$d_3$'te 0 beklenirken 1 gelirse ne olur? Son gelen 1 ile birlikte en baştaki 1 boşa düşer, ama son üç bit yine 111'dir. Bu yüzden makine kendi üzerine döner: giriş 1, çıkış 0, durum $d_3$. Hafızada aslında en son gelen bitlerin aranan dizinin ne kadarını oluşturduğu tutulmaktadır.

Başlangıca dönüşlü tasarımın durum tablosu:

| Durum | $x=0$: sonraki / $z$ | $x=1$: sonraki / $z$ |
|---|---|---|
| $d_0$ | $d_0$ / 0 | $d_1$ / 0 |
| $d_1$ | $d_0$ / 0 | $d_2$ / 0 |
| $d_2$ | $d_0$ / 0 | $d_3$ / 0 |
| $d_3$ | $d_0$ / 1 | $d_3$ / 0 |

Bu tablo, 12 bite kadar bütün giriş dizileri üzerinde python ile denetlendi: çıkış, tam olarak son dört giriş 1, 1, 1, 0 olduğunda 1'dir.

<!-- BELİRSİZ: Karede kilit durumu da "d3" olarak etiketlenmiş; hoca sözlü olarak "dördüncü bir durum" dediği için ayrı bir durumdur (büyük olasılıkla d4). -->

## 8. Sonlu durum makineleri ve 011010 dizisi örneği

**Sonlu durum makinesi**, çıkışı elde etmek için belirli sayıda geçmiş bilgisine ihtiyaç duyan ardışıl devre uygulamasıdır. Şifre örneğinde de çıkışı üretmek için son birkaç girişin bilinmesi gerekiyordu.

### 8.1 Problem

Makineye bir bit akışı gelir; başında 1'ler ya da 0'lar olabilir. Aranan dizi tahtada "011010" diye yazılmıştır ve sırasıyla önce 0, sonra 1, 1, 0, 1 ve 0 gelecektir (ekrandan, 00:50:00). Dizi geldikten sonra makine **daima 1 üretmelidir** (kilitlenme). Problemi bu kez kendimiz açıkça tanımlıyoruz.

### 8.2 Durum diyagramının kurulması

Durum $k$, aranan dizinin ilk $k$ bitinin art arda gelmiş olduğunu gösterir (ekrandan, 00:50:00, 00:55:00 ve 01:05:00):

- **Durum 0:** ilk 0 bekleniyor. 1 gelirse çıkış 0, durum 0'da kalınır. 0 gelirse çıkış 0, durum 1'e geçilir.
- **Durum 1** ("0" gelmiş): 0 gelirse hâlâ elde bir 0 vardır; çıkış 0, durum 1'de kalınır. 1 gelirse çıkış 0, durum 2'ye geçilir.
- **Durum 2** ("01" gelmiş): 1 gelirse çıkış 0, durum 3'e geçilir. 0 gelirse elde yine yeni bir 0 vardır; çıkış 0, durum 1'e dönülür.
- **Durum 3** ("011" gelmiş): 0 gelirse çıkış 0, durum 4'e geçilir. 1 gelirse (0111) bütün dizi bozulur; çıkış 0, durum 0'a (0 bekleme durumuna) dönülür.
- **Durum 4** ("0110" gelmiş): 1 gelirse çıkış 0, durum 5'e geçilir. 0 gelirse durum 1'e gidilir (bkz. 8.4).
- **Durum 5** ("01101" gelmiş): 0 gelirse dizi tamamlanır; çıkış 1, durum 6'ya geçilir. 1 gelirse bkz. 8.3.
- **Durum 6** (dizi tamamlandı, kilit): her girişte "–/1", yani ne gelirse gelsin çıkış 1 ve durum 6'da kalınır.

### 8.3 Durum 5'te 1 gelirse

Durum 5'te 0 beklenirken 1 gelirse dizi "011011" olur. Hoca bunun dizinin tamamen bozulması olmadığını gösterir: son üç bit (011) aranan dizinin başını zaten oluşturur. Bu yüzden başa değil, "011 gelmiş" durumuna, yani durum 3'e dönülür; çıkış 0'dır. Ardından yeniden 0, 1, 0 gelmesi beklenir.

### 8.4 Durum 4'te 0 gelirse (ders sonundaki sorudan)

Diyagramda bu geçiş başta unutulmuştu ve ders sonunda bir öğrencinin sorusuyla eklendi (bkz. Örnek Sorular). Durum 4'te ("0110") 1 beklenirken 0 gelirse dizi "01100" olur. Son gelen 0, yeni bir dizinin ilk 0'ı olarak kullanılabilir; zaten başta 0 bekleniyordu. Bu yüzden durum 1'e ("0 gelmiş") gidilir, çıkış 0'dır.

### 8.5 Durum tablosu ve durum kodlaması

Durum tablosu sütunları: durum etiketi, şimdiki durum $d_2 d_1 d_0$ ($Q$), giriş $X$, bir sonraki durum $d_2^+ d_1^+ d_0^+$ ($Q^+$) ve çıkış $Z$ (ekrandan, 01:05:00). Giriş $X$ 0 ve 1 değerlerini alabildiği için her durum tabloda iki satır kaplar.

Durum sayısı 7'dir (0'dan 6'ya). 2 bit 4 durumu, 3 bit 8 durumu kodlayabildiği için 3 bit gerekir: $\lceil \log_2 7 \rceil = 3$. Durum bilgisi bu bitlerle ($d_2, d_1, d_0$) saklanır; düğümlerin de ikilik olarak kodlanması gerekir.

Tablonun derste yazılan satırları: 000 iken 0 gelince 001'e gidilir, çıkış 0; 000 iken 1 gelince 000'da kalınır, çıkış 0; 001 iken 0 gelince 001'de kalınır, çıkış 0; 001 iken 1 gelince 010'a gidilir, çıkış 0. Hoca sözlü olarak 5. ve 6. durumların satırlarını da verip kalanını öğrencilere bıraktı. Diyagramdan tamamlanmış tablo:

| Durum | $d_2 d_1 d_0$ | $X$ | $d_2^+ d_1^+ d_0^+$ | $Z$ |
|---|---|---|---|---|
| 0 | 000 | 0 | 001 | 0 |
| 0 | 000 | 1 | 000 | 0 |
| 1 | 001 | 0 | 001 | 0 |
| 1 | 001 | 1 | 010 | 0 |
| 2 | 010 | 0 | 001 | 0 |
| 2 | 010 | 1 | 011 | 0 |
| 3 | 011 | 0 | 100 | 0 |
| 3 | 011 | 1 | 000 | 0 |
| 4 | 100 | 0 | 001 | 0 |
| 4 | 100 | 1 | 101 | 0 |
| 5 | 101 | 0 | 110 | 1 |
| 5 | 101 | 1 | 011 | 0 |
| 6 | 110 | 0 | 110 | 1 |
| 6 | 110 | 1 | 110 | 1 |

2, 3 ve 4. durumların satırları (ara adım eklendi) diyagramdaki oklardan yazıldı. Tablo, 12 bite kadar bütün giriş dizileri üzerinde python ile denetlendi: çıkış, 0, 1, 1, 0, 1, 0 dizisi ilk kez tamamlandığı adımdan itibaren hep 1, öncesinde hep 0'dır.

> **Ders sonrası not:** Hoca "0'dan 6'ya kadar 6 tane değişik durum var" dedi; 0'dan 6'ya 7 durum vardır. Sonuç değişmez, 3 bit yeterlidir.

> **Ders sonrası not:** Hoca 6. durum için sözlü olarak "çıkışlarım devamlı sıfır" dedi. Diyagramda bu durum "–/1" ile gösterilmiştir ve problem tanımı gereği dizi geldikten sonra çıkış daima 1'dir; doğrusu $Z = 1$'dir.

### 8.6 Durum indirgeme

Kitapta eşdeğerlik tablosu ile durum indirgeme konusu da vardır. Durum tablosu çok büyüdüğünde, bazı durumların birbirine eşdeğer olduğunu bulup durum sayısını azaltmak için kullanılır. Bu kısım derste anlatılmadı, öğrencilerin kendi çalışmasına bırakıldı.

## 9. Standart tasarım birimleri

Dersin başındaki genel yapıya dönülür: ardışıl devrede bir kombinezonsal kısım ve durum bilgilerinin tutulduğu hafıza birimleri vardır (ekrandan, 01:00:00). Hafıza birimleri olarak flip-floplar, tutucular, saklayıcılar, sayıcılar, RAM ve ROM kullanılır; ne kadar bit saklanacaksa ona göre seçilir.

- **Flip-flop (FF):** en çok kullanılan hafıza elemanıdır; 1 bitlik bilgi saklar. 011010 örneğinde 3 bit saklamak gerektiği için 3 flip-flop kullanılır.
- **Tutucu (latch):** yapısı farklıdır ama o da 1 bitlik bilgi saklar.
- **Saklayıcı (register):** flip-floplardan oluşur; 4 bitlik, 8 bitlik gibi belli uzunlukta bilgiyi tutar.
- **Sayıcı:** saklayıcı gibi $n$ bitlik bilgi tutar; ayrıca her saat darbesinde içeriğini 1 artırır. Durum makinesindeki gibi farklı durumlara geçmek yerine yalnız "+1" yapar.
- **Bellekler ve diziler:** RAM, ROM, PROM, EPROM, EEPROM, CAM ve programlanabilir ardışıl diziler.

Bu hafıza yapıları saat işaretiyle birlikte çalışır, çünkü $t$ anı ile $t+1$ anını ayıracak senkronlayıcı bir saat işaretine ihtiyaç vardır.

> **Ek bilgi (derste anlatılmadı):** CAM (content-addressable memory, içerik adreslemeli bellek), adres yerine içerikle arama yapan bir bellek türüdür. EEPROM ise elektrikle silinip yeniden yazılabilen programlanabilir ROM'dur; EPROM'dan farkı silmenin morötesi ışık yerine elektrikle yapılmasıdır.

## 10. Saat işaretinin parametreleri

Seçilen kenar (yükselen ya da düşen) belli bir periyotla tekrar eder. Periyot $T$ frekansın tersidir:

$$T = \frac{1}{f}$$

Bir periyodun işaretin 1 olduğu kısmına **darbe**, 0 olduğu kısmına **boşluk** denir. İdeal olan, darbenin sıfıra çok yakın olması ve boşluğun neredeyse periyodun tamamını kaplamasıdır. Hoca tahtada geniş çizse de pratikte kullanılan saat işaretleri dar darbelidir. Saat işaretleri için $T_{\text{darbe}}/T_{\text{boşluk}}$ ya da $T_{\text{darbe}}/T$ gibi oranlar da verilir; saatli lojik devrelerle karşılaşıldığında darbe ve boşluk kavramlarının bilinmesi gerekir.

> **Ek bilgi (derste anlatılmadı):** $T_{\text{darbe}}/T$ oranına görev çevrimi (duty cycle) denir ve genellikle yüzde olarak verilir; örneğin simetrik bir kare dalganın görev çevrimi %50'dir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:45:00): Bir girişi ve bir çıkışı olan bir şifre devresi tasarlayın. Giriş akışında art arda 1, 1, 1, 0 geldiğinde çıkış 1, aksi durumda 0 olsun. Durum diyagramını çizin.

> **Çözüm:** Bölüm 7'de verildi. Durumlar $d_0$, $d_1$ ("1"), $d_2$ ("11"), $d_3$ ("111"). $d_0$: 0/0 → $d_0$, 1/0 → $d_1$; $d_1$: 0/0 → $d_0$, 1/0 → $d_2$; $d_2$: 0/0 → $d_0$, 1/0 → $d_3$; $d_3$: 1/0 → $d_3$, 0/1 → $d_0$ (ya da kilitleme tasarımında 0/1 ile hep "–/1" veren ek bir duruma).

**Soru 2** (ekrandan, 00:50:00): Giriş akışında sırasıyla 0, 1, 1, 0, 1, 0 geldiğinde çıkışı 1 yapan ve bundan sonra her zaman 1 üreten sonlu durum makinesinin durum diyagramını ve durum tablosunu oluşturun.

> **Çözüm:** Bölüm 8'de verildi. 7 durum (0-6), 3 bit ($d_2 d_1 d_0$); tamamlanmış durum tablosu 8.5'tedir. Derste tablonun yalnız ilk satırları yazıldı, kalanı diyagramdan tamamlandı.

**Soru 3** (derste sözlü, 01:03:46): Soru 2'deki diyagramda 4. durumdan 5. duruma geçerken 1 yerine 0 gelirse ne olur?

> **Cevap:** 4. durumda "0110" gelmiştir ve 1 beklenir. 0 gelirse dizi bozulur, ama son gelen 0 yeni dizinin ilk 0'ı olarak kullanılabilir. Bu yüzden başa (durum 0) değil, "0 gelmiş" durumuna (durum 1) gidilir; çıkış 0'dır.

**Soru 4** (derste sözlü, 00:36:43): 0'dan 7'ye sayan ve çıkışını tek sayılarda 1 yapan devrenin durum tablosunu kurun.

> **Çözüm:** Derste ilk dört satır sözlü verildi (bölüm 6.3). 8 durum için 3 bit gerekir. Hocanın kurgusuna göre çıkış, geçilen sonraki sayı tek olduğunda 1'dir: $0 \to 1$ / 1, $1 \to 2$ / 0, $2 \to 3$ / 1, $3 \to 4$ / 0, $4 \to 5$ / 1, $5 \to 6$ / 0, $6 \to 7$ / 1, $7 \to 0$ / 0 (7'den sonra 0'a dönülen tasarım).

<!-- BELİRSİZ: 4-7 arası satırlar derste yazılmadı; aynı kuralla tamamlandı. 7'den sonra 0'a dönme ya da 7'de kalma seçeneklerinden hangisinin seçildiği belirtilmedi. -->

## Dersin Toparlaması

Bu derste önce kitabın maliyet ve karmaşıklık bölümü kısaca özetlendi: maliyet tasarım ve üretim kalemlerinden, karmaşıklık ise eleman ve zaman karmaşıklığından oluşur; katmanlı devrelerde her katmanın en büyük gecikmesi toplanır. Programlanabilir kombinezonsal devreler (PROM, programlanabilir diziler ve lojik diziler) yalnızca tanıtıldı.

Dersin asıl konusu ardışıl devrelere giriştir. Ardışıl devre, bir kombinezonsal kısım ile durum bilgisini saklayan bir hafızadan oluşur. Çıkışın girişe de bağlı olduğu Mealy ve yalnız duruma bağlı olduğu Moore makineleri; değişikliği yalnız gecikmeyle yansıtan asenkron ve saat işaretinin tetikleme anlarında çalışan senkron devreler ayrıldı. Durum diyagramı ve durum tablosu, iki dizi tanıma (şifre) örneğiyle kuruldu; burada her düğümden girişin bütün değerleri için geçiş tanımlanması ve dizi bozulduğunda son bitlerin dizinin başıyla örtüşüp örtüşmediğine bakılması vurgulandı. Son olarak flip-flop, tutucu, saklayıcı, sayıcı ve bellek gibi standart birimler ile saat işaretinin periyot, darbe ve boşluk kavramları tanıtıldı. Sonraki derslerde flip-flopların nasıl çalıştığına ve bunlarla kurulan ardışıl devre yapılarına geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
