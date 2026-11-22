# Ders 9 Genişletilmiş Notu: Diyot Uygulamaları Tekrarı (Doğrultucu, Kırpıcı, Kenetleyici, Zener, Gerilim Katlayıcı) ve BJT'ye Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin akışı
- 2. Seri diyot devreleri: ideal ve gerçek diyot
- 3. Doğrultucular
- 4. Kırpıcılar
- 5. Kenetleyiciler
- 6. Zener diyot
- 7. Gerilim katlayıcılar ve diyot uygulamaları
- 8. Bipolar transistöre giriş
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin akışı

Bir öğrenci, önceki derste işlenen kondansatörlü devrelerde kondansatörün hangi yönde dolduğunu anlamadığını söyledi. Hoca bu dersin büyük kısmının tekrar olacağını, kenetleyicilerden (clamper) önce kırpıcılara (clipper) da yeniden değineceğini, sonunda da transistöre yalnız giriş yapıp hesaplara girmeden bitireceğini belirtti. Slaytlar önceki derste kullanılan diyot uygulamaları sunumudur; hoca slaytların üzerine kalemle çizerek anlattı.

## 2. Seri diyot devreleri: ideal ve gerçek diyot

### 2.1 Ne zaman ideal, ne zaman gerçek diyot

Diyotun doğru polarmada iletime, ters polarmada kesime gittiği önceki derslerde anlatılmıştı. Şimdiye kadar çizilen grafiklerin hepsinde diyot ideal kabul edildi; kırpıcı ve kenetleyicilerde de ideal kabul edilecek. Ancak sorularda diyot her zaman ideal olmayabilir. Slayttaki seri devrede diyotun yanında "Si" yazıyor (ekrandan, 00:15:00). Malzeme açıkça belirtildiği için bu diyot ideal değil, gerçek bir silisyum diyot gibi değerlendirilir.

Kural şudur: soruda "ideal" denmiş ya da hiçbir ibare yoksa diyot idealdir. Malzeme (Si, Ge) verilmiş ve "ideal" denmemişse diyot, içinde ters yönde bağlı küçük bir kaynak varmış gibi düşünülür: Si için 0,7 V, Ge için 0,3 V. Soruda hem "ideal" deyip hem "Si" yazmanın anlamı yoktur.

> **Hocanın vurgusu:** İdeal olmayan sorulardaki 0,7 V kaçırılırsa grafik farklı çıkar; buna dikkat edilmelidir.

Slayttaki sabitler ve analiz (ekrandan, 00:15:00):

- Silisyum diyot: $V_D = 0{,}7$ V; germanyum diyot: $V_D = 0{,}3$ V.
- Silisyum için: $V_D = 0{,}7$ V (ya da $E < 0{,}7$ V ise $V_D = E$).
- $V_R = E - V_D$.
- $I_D = I_R = I_T = V_R / R$.

### 2.2 Voltmetre nereyi ölçüyor

Devrede bir kaynak $E$, seri bir Si diyot ve bir $R$ direnci vardır. Diyotun uçlarına (paralel) bir voltmetre bağlanırsa:

- Diyot iletimdeyse (anoda artı ve 0,7 V'tan büyük bir gerilim verilmişse) voltmetre 0,7 V okur.
- Diyot kesimdeyse akım geçmez ve voltmetre kaynak gerilimi $E$'yi okur.

Voltmetre direncin uçlarına bağlanırsa durum değişir:

- Diyot iletimdeyse $V_R = E - 0{,}7$ V okunur.
- Diyot kesimdeyse dirençten akım geçmediği için 0 V okunur.

Bu yüzden her soruda önce çıkışın (voltmetrenin) nereden alındığına bakılmalıdır. Hoca bunu paralel devrelerle de örnekledi: çıkış direnç üzerinden alınıyorsa diyotun iletimde olduğu durumlar önemlidir; diyota paralel bir çıkışta ise girişin $V_o$'da görülebilmesi için diyotun kesimde olması gerekir.

### 2.3 Eş diyotların paralel bağlanması

İki eş silisyum diyot paralel bağlandığında aynı iç dirence sahip oldukları için teoride akım ikisine eşit paylaşılır; pratikte iki diyotun tam eş olması pek mümkün değildir. İletimdeyken diyotların uçlarında yine 0,7 V vardır. Diyotlar kesimdeyse çıkıştan, kaynaktan direnç üzerindeki düşüm çıkarıldıktan sonra kalan değer okunur.

## 3. Doğrultucular

### 3.1 Yarım dalga doğrultucu

Alternatif akım, akımın yönü zamanla değişen işarettir. Yarım dalga doğrultucu yalnız bir yöndeki akımı geçirir; istenirse pozitif, istenirse negatif yarı geçirilir, diğer yarı tamamen bastırılır. Bunun için tek bir diyot ve bir direnç yeter. Slayttaki devrede pozitif yarıda diyot iletir ve $v_o = v_i$ olur; negatif yarıda diyot kesimdedir ve $v_o = 0$ V olur (ekrandan, 00:20:00).

Doğrultulmuş işaret bir DC devreyi beslediğinde devrenin "hissettiği" gerilim işaretin ortalamasıdır. Negatif yarı silindiği için ortalama:

$$V_{DC} = 0{,}318\,V_m$$

olur; burada $V_m$ AC gerilimin tepe değeridir (ekrandan, 00:20:00).

### 3.2 Tam dalga doğrultucu ve köprü tipi

Tam dalga doğrultucunun avantajı, işaretin iki yarısını da geçirmesi, ikinci yarıyı birinci yarının geçtiği yönde geçirmesidir. Böylece ortalama iki katına çıkar:

$$V_{DC} = 0{,}636\,V_m$$

Hoca bunu $V_m = 10$ V ile örnekledi: yarım dalgada yaklaşık 3,1 V, tam dalgada yaklaşık 6,3 V ölçülür ($0{,}318 \cdot 10 = 3{,}18$ V, $0{,}636 \cdot 10 = 6{,}36$ V).

En çok kullanılan tam dalga doğrultucu köprü tipidir. Köprüde ölçüm uçları sabit kalırsa pozitif yarıda akım bir diyot çiftinden, negatif yarıda öbür diyot çiftinden geçer, ama direnç üzerinden her iki yarıda da aynı yönde akar; voltmetre her seferinde pozitif gerilim okur. Voltmetrenin artı ve eksi uçları yer değiştirirse aynı işaret ters (negatif) okunur. Yalnız negatif çıkış isteniyorsa genelde uçlar değil diyotların yönü ters çevrilir; iki yol da negatif gerilim seviyesinde bir çıkış verir.

### 3.3 Köprünün dezavantajı: iki diyot kaybı

Köprüde her yarı periyotta akım iki diyottan geçer. İdeal diyotta bu önemsizdir, ama gerçek diyotta iki kez 0,7 V, yani 1,4 V kaybedilir. Hoca bunu 2 V tepeli bir AC girişle örnekledi: idealde yaklaşık $0{,}636 \cdot 2 \approx 1{,}27$ V DC beklenir, ama 1,4 V diyotlarda kaybedildiği için bu kadar düşük bir girişte köprü pek işe yaramaz.

> **Ders sonrası not:** Hoca 2 V tepeli girişte ikinci diyotun hiç iletime geçemeyeceğini ve devrenin çalışmayacağını söyledi. Tepe değer (2 V) iki diyotun toplam eşiğinden (1,4 V) büyük olduğu için tepeler civarında çıkışta büyük olasılıkla yaklaşık 0,6 V tepeli küçük bir işaret yine oluşur; ortalaması yaklaşık 0,2 V'tur (python ile hesaplandı). Kayıp yine de çok büyüktür; hocanın asıl noktası budur.

Slayttaki özet tablo (ekrandan, 00:25:00):

| Doğrultucu | İdeal $V_{DC}$ | Gerçek $V_{DC}$ |
|---|---|---|
| Yarım dalga | $0{,}318V_m$ | $0{,}318V_m - 0{,}7$ |
| Köprü | $0{,}636V_m$ | $0{,}636V_m - 2(0{,}7\text{ V})$ |
| Orta uçlu transformatörlü | $0{,}636V_m$ | $0{,}636V_m - 0{,}7$ V |

Slaytın altındaki not: orta uçlu transformatörlü doğrultucuda tepe AC gerilim, transformatör sekonderinin orta uca kadar olan gerilimidir.

> **Ek bilgi (derste anlatılmadı):** Tablodaki "gerçek" formüller yaklaşıktır. Ortalamadan doğrudan 0,7 V çıkarmak yerine tam hesapta tepe değerden diyot düşümü çıkarılır ve iletim açısı daralır; $V_m$ diyot düşümüne göre büyük olduğunda iki yaklaşım birbirine yakındır.

### 3.4 Orta uçlu transformatörlü doğrultucu

Köprünün bu dezavantajı yüzünden ikinci bir yaklaşım kullanılır: orta uçlu transformatörlü doğrultucu (ekrandan, 00:30:00). Gereksinimleri iki diyot ve orta uçlu bir transformatördür. Hoca, transformatörün genliği iki katına çıkardığı yönünde bir yanlış anlamayı düzeltti: devre $2V_m$ üretmez. Transformatör aynı işareti iki kanala (iki yarı sargıya) çoğaltır, yönler aynı kalır. Pozitif yarıda üst diyot iletir, alt kol açık devre olduğu için akım oluşmaz ve direnç yalnız üst koldan gelen akımla artı polarlanır. Negatif yarıda üst diyot kesime, alt diyot iletime geçer ve direnç yine aynı yönde polarlanır. Böylece ikinci yarı da görülür ve ortalama yine $0{,}636V_m$'dir. Akım her yarıda tek diyottan geçtiği için gerçek durumda yalnız bir 0,7 V kaybedilir.

### 3.5 DC değer neden $V_m$'ye eşit olamaz

**Soru:** Tam dalgada oluşan DC gerilim $0{,}636V_m$; bunu bire bir, yani $V_m$'ye eşit yapmak için ne yapılabilir?

**Cevap:** Hoca bunun mümkün olmadığını söyledi. Elektronik devreler DC ile beslenir ve devre girişin DC bileşenini, yani ortalamasını görür. Şebekeden (prizden) gelen AC işaretin ortalaması sıfırdır; doğrultma işlemi bu ortalamayı sıfırdan ne kadar yukarı çekebileceğimizle ilgilidir. Doğrultulmuş işarette tepeler arasındaki boşluklar "olmayan kısımlar"dır ve bunları yoktan var etmek mümkün değildir. Bir kontrol mekanizmasıyla, doğrultucunun çıkışıyla bir transistörü tetikleyip ayrı bir DC kaynaktan beslenen bir hattı anahtarlamak düşünülebilir; ama zaten bir DC kaynak varsa onu doğrudan kullanmak daha mantıklıdır. Transistörler sonraki derste işlenecektir.

Hoca ayrıca piyasadaki pahalı güç kaynaklarının üzerinde %80, %90, %95 gibi değerler yazdığını, işaretin tepe aralıkları sıklaştırıldıkça (frekans arttırıldıkça) ortalamanın $V_m$'ye doğru yükseldiğini, ama bunun çok yüksek frekansta güç yönetimi gerektirdiği için tehlikeli ve maliyetli olduğunu söyledi. Şebeke frekansı 50 Hz'dir.

> **Ders sonrası not:** Doğrultulmuş sinüsün ortalaması ($0{,}318V_m$ ya da $0{,}636V_m$) frekansa bağlı değildir. Frekansı yükseltmenin yararı, çıkışa konan filtre kondansatörüyle dalgalanmanın (ripple) azalması ve çıkışın $V_m$'ye yaklaşmasıdır. Güç kaynaklarının üzerindeki %80-%95 gibi değerler büyük olasılıkla verimlilik (çıkış gücünün giriş gücüne oranı) sınıflarıdır, doğrultulmuş ortalamanın $V_m$'ye oranı değildir.

## 4. Kırpıcılar

### 4.1 Kırpıcı ve doğrultucu ilişkisi

Kırpıcı devreler girişin belli bir seviyenin üstünü ya da altını kırpar. Yarım dalga doğrultucu da bir kırpıcıdır; ama kırpıcılar farklı amaçlara yönlendirilebilir, her kırpıcı doğrultucu değildir. Kırpıcılara bir DC kaynak (bias gerilimi) eklenerek diyotun iletime geçtiği seviye kaydırılabilir.

Hoca önceki dersten bir örneği hatırlattı: diyotu iletime sokan 5 V'luk bir kaynak varsa giriş 0 V iken direnç üzerinde 5 V okunur, çünkü diyot zaten iletimdedir. Giriş 20 V'a çıktığında $20 + 5 = 25$ V ile diyot doğru polarlıdır. Çıkış ancak giriş $-5$ V'a indiğinde sıfırlanır, çünkü diyot ancak o zaman kesime gider.

### 4.2 Seri kırpıcılarda analiz

Slayttaki özet (ekrandan, 00:35:00): basit seri kırpıcılarda (ideal diyot) diyot yönüne göre çıkış yalnız negatif yarıyı ($-V_m$'ye kadar) ya da yalnız pozitif yarıyı ($V_m$'ye kadar) geçirir. Kutuplu seri kırpıcılarda çıkışın tepe değeri $-(V_m + V)$, $-(V_m - V)$, $(V_m - V)$ ya da $(V_m + V)$ olur.

> **Hocanın vurgusu:** Seri ve paralel kırpıcılar sınavlarda karıştırılıyor. Seri kırpıcıda diyot iletimdeyken çıkışta diyotun 0,7 V'u dışında seri kaynağın etkisi de görülür; diyot kesimdeyken ise başka bir değer (paralel kırpıcıda giriş) okunur. Bu fark iyi analiz edilmelidir.

Kutuplu seri kırpıcının analizi her zaman $t = 0$ anında, yani giriş sıfırken diyotun bu kaynakla nasıl davrandığına bakılarak başlar. Slayttaki ilk kutuplu devrede kaynak diyotu $t = 0$'da iletime sokar. Diyot iletimde olduğu için çıkışta $V$ gerilimi vardır, ama negatif işaretlidir. Bunun nedeni şudur: çıkış direncin üzerindeki $+/-$ referansıyla ölçülür ve akım bu referansın tersi yönde akar.

Hoca işaret kuralını iki düğümle açıkladı. Direncin bir ucu $V_1$, öbür ucu $V_2$ olsun. $V_1 > V_2$ ise akım $V_1$'den $V_2$'ye akar ve direnç $V_1$ tarafı artı olacak biçimde polarlanır. Referans $V_1$ tarafı artı diye seçilmişse ve akım ters yönde akıyorsa ölçü aleti negatif değer gösterir. Bu devrede de durum budur, bu yüzden $-V$ okunur.

Giriş pozitif yönde arttıkça kaynağın etkisini yavaş yavaş sönümler (örneğin 5 V'luk kaynak için 5, 4, 3, 2, 1 diye azalır). Giriş kaynağı dengeleyince diyot kesime gider; dirençten akım geçmediği için çıkış 0 V olur. Giriş tekrar kaynak değerinin altına düşünce diyot iletime girer ve çıkışta yine negatif değerler okunur. Diyot ve kaynak ters bağlanmışsa $t = 0$'da diyot kesimdedir, bütün pozitif yarıda çıkış sıfırdır; negatif yarıda giriş kaynak değerini aşınca diyot iletime geçer ve direnç üzerinde aşan kısım, tepe noktasına kadar okunur.

Hoca slayttaki $V$'lerin gerçek diyotta nasıl ele alınacağını da gösterdi: diyot ideal değilse, verilen kaynağa (örneğin 5 V) ek olarak diyotun içinde anotta eksi, katotta artı olacak biçimde ters bağlı bir 0,7 V kaynak varmış gibi analize devam edilir.

### 4.3 Paralel kırpıcılarda analiz

Paralel kırpıcıda kural şudur: diyot iletimdeyse çıkışta diyotun iç gerilimi ya da diyotla seri bağlı kaynağın gerilimi okunur; diyot kesimdeyse giriş gerilimi okunur (ekrandan, 00:40:00).

Basit paralel kırpıcının ilk örneğinde (ekrandan, 00:45:00) diyot $t = 0$'da kesimdedir ve çıkıştan 0 okunur. Hoca anlatımında, diyot iletime girdiğinde çıkışın diyotun iç gerilimine sabitlendiğini, diyot kesime gidince de girişin üzerinden okunduğunu söyledi; çıkış negatif yarıda $-V_m$'ye kadar iner.

Kutuplu paralel kırpıcıda giriş seri kaynağın değeri $V$'yi geçene kadar diyot tam iletime geçemez ve çıkışta artan giriş okunur. Giriş $V$'yi geçince diyot iletir, o kol kısa devre gibi olur ve çıkış $V$'ye sabitlenir; girişin daha da artmasının çıkışa etkisi yoktur. Negatif polarmada diyot kesime gidince yine giriş okunur ve negatif yarının tamamı çıkışta görülür.

**Soru:** Slayttaki $-V_m$ değeri giriş $v_i$'nin değerine mi eşittir?

**Cevap:** $v_i$, girişe verilen işaretin kendisidir. Tepe noktaları $+V_m$ ve $-V_m$'dir; çıkıştaki $-V_m$ bu tepe değerdir.

Negatif kutuplu paralel kırpıcıda (ekrandan, 00:45:00) giriş sıfırken kaynak diyotu iletime sokar, o kol kısa devre olur ve çıkışta $-V$ okunur (kaynağın eksi ucu çıkışın artı ucuna gelir). Giriş negatif yönde $-V$'yi geçince diyot kesime gider ve çıkışta yalnız $-V$'den daha negatif olan tepe kısmı görülür.

Çift diyotlu devre pozitif ve negatif paralel alt-üst kırpıcıdır. Birinci diyotu iletimde tutan gerilim $V_1$ ile, ikinci diyotu iletimde tutan gerilim $V_2$ ile sınırlanır; çıkış $V_1$ ile $-V_2$ arasında kalır (slaytta $|V_1| > |V_2|$ durumu çizilmiştir).

### 4.4 Kırpıcı kenetleyici değildir

> **Hocanın vurgusu:** Bu devreler kenetleyici (clamper) değildir. Kenetleyici olabilmek için gerilimi biriktirecek bir eleman, yani kondansatör gerekir. Kondansatör yoksa çıkış $\pm V_m$'nin üstüne çıkamaz, yalnız kırpabilir. Kırpıcı adı üstünde kırpar, kenetleyici işareti kaydırır.

Hoca, kondansatörsüz bir paralel kırpıcı için grafikte $-V_m - V$ gibi sınırı aşan bir değer yazılırsa bunun yanlış olduğunu belirtti.

## 5. Kenetleyiciler

### 5.1 Kondansatörün dolması ve boşalması

Kenetleyicilerin amacı bir enerji depolama elemanı kullanmaktır. Devre teorisinden hatırlanacağı gibi kondansatör enerjiyi gerilim biçiminde, bobin ise manyetik alan oluşturarak akım biçiminde tutar. Bu yüzden kondansatörün üzerinde gerilim birikir.

Slayttaki kondansatör kutupludur (elektrolitik); uzun bacak artı uçtur ve yatay çizilmiştir. Hocanın anlattığı davranış şudur: artı ucuna artı işaret geldiğinde kondansatör dolar; artı ucuna negatif işaret geldiğinde dolu kondansatör bir batarya gibi davranır ve girişle seri bağlanmış iki batarya gibi devreyi besler.

### 5.2 Kare dalga kenetleyici

Slayttaki devrede (ekrandan, 00:50:00) girişte $+V$ ve $-V$ arasında değişen bir kare dalga vardır. Slayttaki ifade: bir diyot ve bir kondansatör, bir AC işareti belirli bir DC seviyeye "kenetlemek" için birleştirilebilir.

- **Pozitif yarı:** Diyot iletir ve devre diyot üzerinden tamamlanır. Kondansatör akımın girdiği tarafı artı olacak biçimde $V$'ye dolar. Diyot iletimde ve çıkışa paralel olduğu için çıkış 0'dır.
- **Negatif yarı:** Giriş $V$ ve kondansatördeki $V$ seri toplanır; toplam $2V$'dir. Diyot kesimdedir, akım diyottan geçemez ve direnç üzerinden akar. Akım direncin $+/-$ referansının tersi yönde aktığı için çıkışta $-2V$ okunur.

Çıkış 0 ile $-2V$ arasında değişir; işaret kaydırılmış, yani kenetlenmiştir.

**Soru:** Bu durumda diyotun uçlarındaki gerilim de aynı mıdır? Diyot uçlarında ölçülse $2V$ mi, $V$ mi olur?

**Cevap:** Diyot kesimdedir, açık devredir. Diyotun uçlarında ölçülseydi kondansatör gerilimiyle birlikte $2V$ okunurdu.

### 5.3 Analiz ipucu: önce kondansatör gerilimi

Hoca, kırpıcı ve kenetleyicilerin farklı kaynak değerleriyle denenmesini istedi: "şuraya bir 5 V koysam ne olur, 1-2 V koysam ne olur?" diye düşünülüp devreler PSpice, Multisim ya da başka bir simülasyon ortamında kurulmalıdır. Ne kadar örnek anlatılırsa anlatılsın, kişi kendisi denemedikçe konu tam oturmaz.

Kondansatörlü devrelerin bir özelliği şudur: grafiklerdeki işaret sonsuzdan beri devam eden bir işaretin kesilmiş bir parçasıdır ve kondansatörün içinin başlangıçta boş olduğu varsayılmaz. Bu yüzden kondansatörlü yapılarda $t = 0$ anını analiz etmek çok anlamlı değildir. Önce kondansatörün kararlı durumda hangi gerilime dolduğu bulunur, grafik ondan sonra çizilir.

> **Hocanın vurgusu:** Kondansatörlü analizlerde ilk iş, kondansatörün neye dolduğunu çıkarmaktır.

### 5.4 Kutuplu kenetleyici: 20 V ve 10 V örneği

Slayttaki örnek (ekrandan, 00:55:00): giriş $\pm 20$ V tepeli sinüs, diyota seri 10 V'luk bir DC kaynak vardır. Slayttaki notlar: giriş sinüs, kare ya da üçgen gibi herhangi bir dalga biçimi olabilir; DC kaynak kenetleme seviyesini ayarlamaya yarar.

Adım adım çözüm:

1. **Kondansatörün dolduğu gerilim:** Negatif yarıda diyot iletime geçer, ama karşısında 10 V'luk kaynak vardır. Kondansatör ancak diyotun iletimde olduğu değere dolabileceği için $20 - 10 = 10$ V'a dolar.
2. **Diyot iletimdeyken çıkış:** Çıkış diyot-kaynak koluna paraleldir ve $-10$ V'tur.
3. **Diyot kesimdeyken çıkış:** Pozitif yarıda girişin 20 V'u ile kondansatörün 10 V'u seri toplanır ve çıkış $20 + 10 = 30$ V'a çıkar.

Sonuç: çıkış $+30$ V ile $-10$ V arasında salınır (slayttaki grafik de böyledir). Tepe-tepe değer girişteki gibi 40 V'tur, yalnız DC seviye kaymıştır.

> **Ders sonrası not:** Hoca anlatımda iletim ve kesim durumlarını ters adlandırdı (30 V için "diyot iletime geçtiğinde", $-10$ V için "kesime gittiğinde" dedi). Slayttaki devrede $-10$ V'luk bölüm diyotun iletimde, $+30$ V'luk bölüm kesimde olduğu durumdur; sayısal sonuç ($+30$ / $-10$ V) değişmez.

### 5.5 Kenetleyici özet slaytı

Slaytta altı kenetleyici çeşidi vardır (ekrandan, 01:00:00). Hepsinde giriş $\pm V$ kare dalga, çıkış genliği (tepe-tepe) $2V$'dir:

- Basit kenetleyici, diyot bir yönde: çıkış 0 ile $-2V$ arası.
- Basit kenetleyici, diyot ters yönde: çıkış 0 ile $+2V$ arası.
- Diyota seri $V_1$ kaynaklı çeşitler: çıkışın üst ya da alt seviyesi $V_1$ ya da $-V_1$'e kaydırılır.

Hoca slayttaki bir örneği çözdü. Pozitif yarıda diyot kesimdedir, kondansatör $R$ direnci üzerinden $+V$'ye dolar; ilk anda görülen değer girişteki $V$'dir. Negatif yarıda giriş $V_1$'i geçene kadar diyot iletime geçemez; geçince diyot iletir ve çıkış yalnız $V_1$ olur. Pozitif yarıda diyot kesime gidince kondansatördeki gerilim girişle toplanır ve çıkışta toplam $2V$'lik bir salınım görülür.

Bir başka örnekte (ekrandan, 01:00:00) pozitif gerilim geldiğinde diyot hemen iletmez; giriş $V_1$'i geçene kadar çıkışta giriş görülür. $V_1$ aşılınca diyot iletime geçer ve kondansatör dolar. Negatif yarıda diyot kesime gider, kondansatör $R$ üzerinden boşalır ve çıkışta $2V$'lik salınım görülür.

**Soru:** Diyot kesimdeyken direnç üzerinden akım akmıyor mu? O sırada kondansatör dolmuyor mu?

**Cevap:** Evet; çıkış zaten direnç üzerinden akan akım sayesinde ölçülür. Pozitif yarıda akım direnç üzerinden akarken kondansatör dolmaya başlar; giriş $V_1$'i geçip diyot iletime girince de dolmaya devam eder. Kondansatör $V$'ye dolar.

**Soru:** Akım kondansatörden geçip diyotu iletime soktuğunda (o kol kısa devre gibi olduğunda) gerilim farkı kalmayacağı için akım durmaz mı?

**Cevap:** Hoca sayısal bir örnekle açıkladı: girişte 10 V, diyota seri kaynak 5 V olsun. Diyot kolu iletime geçince o kolda 5 V kalır, öbür 5 V devrenin geri kalanında (kondansatörde) kalır. Ters polarmada bu 5 V, $-10$ V'a eklenerek direnç üzerinden görülür.

## 6. Zener diyot

### 6.1 Çalışma ilkesi

Normal diyot ters yönde (anoda eksi, katoda artı) gerilim geldiğinde teoride hiç akım geçirmez, sonsuz direnç gösterir ve açık devre gibi davranır. Zener diyotun üzerinde ise bir zener gerilimi $V_Z$ yazar. Ters polarmada bu gerilim aşılınca zener iletime geçer ve normal diyotun doğru polarmadaki gibi iletir.

Slayttaki ifade: zener, zener geriliminde ($V_Z$) ters polarmada çalıştırılan bir diyottur (ekrandan, 01:05:00). Hoca bunu, Si diyotun içinde 0,7 V'luk bir kaynak varmış gibi düşünülmesine benzetti: zenerin içinde de ters yönde bağlı bir $V_Z$ bataryası varmış gibi düşünülebilir. Uygulanan gerilim $V_Z$'den büyükse zener iletir, küçükse normal diyot gibi kesimde kalır.

Slayttaki kurallar (ekrandan, 01:05:00):

- $V_i \ge V_Z$ ise zener iletimdedir ("on"), uçlarındaki gerilim $V_Z$'dir.
- Zener akımı: $I_Z = I_R - I_{RL}$.
- Zener gücü: $P_Z = V_Z I_Z$.
- $V_i < V_Z$ ise zener kesimdedir ("off") ve açık devre gibi davranır ($V_Z > V > 0$ V).

Slayttaki devrede giriş $V_i$, seri direnç $R$, zener ve ona paralel yük direnci $R_L$ vardır. $I_R$ seri dirençten gelir; düğümde $I_Z$ zenere, $I_L$ yüke ayrılır. Zener akımı düğüm analiziyle (KCL) bulunur.

### 6.2 Zener gücü

Hoca slayta $V_Z = 50$ V ve giriş 70 V yazarak örnekledi (ekrandan, 01:05:00). Zener iletime geçince uçlarında 50 V vardır, tıpkı iletimdeki Si diyotun 0,7 V göstermesi gibi. Güç her zaman zener gerilimiyle hesaplanır:

$$P_Z = V_Z \cdot I_Z = 50 \cdot I_Z \quad (70 \cdot I_Z \text{ değil})$$

Giriş gerilimi $V_Z$'den küçükse zener açık devredir ve devrede yalnız ana kol akımı vardır.

> **Hocanın vurgusu:** Zener önemli bir konudur; zener gücünü giriş gerilimiyle hesaplamak karıştırılmamalıdır.

### 6.3 Yük direnciyle ilgili soru tipleri

Hoca bu konuda üretilebilecek soru tiplerini anlattı:

- $R_L$ üzerinde en küçük gerilim kalsın ya da $R_L$'den geçen akım en küçük olsun.
- Yük direncini öyle ayarlayın ki zenerden geçen $I_Z$ en küçük olsun.
- 70 V girişte $R_L$ öyle ayarlansın ki zenerde yalnız 50 V kalsın, zener iletimde olsun ve $I_Z$ en küçük olsun.

Bunların hepsi akımın dağılımı (düğüm analizi) ve paralel kollarda gerilimlerin eşitliği ilkesine dayanır. $R_L$ zenere paralel olduğu için $V_Z$ için gereken 50 V $R_L$'de de vardır. $R_L = V_Z / I_L$ olduğundan $I_L$ en küçük alınırsa $R_L$'nin en büyük değeri, en büyük alınırsa en küçük değeri bulunur. $R_L$'nin en küçük değeri için ana koldaki eşdeğer direnç üzerinden bir yaklaşım yapılır.

> **Ders sonrası not:** Altyazıda akım ilişkisi "$I_R + I_R = I_Z$" gibi bozuk geçti. Slayttaki ilişkiye göre doğrusu $I_R = I_Z + I_L$, yani $I_Z = I_R - I_L$'dir.

> **Ek bilgi (derste anlatılmadı):** Zener iletimdeyken seri dirençten geçen akım $I_R = (V_i - V_Z)/R$ ile bulunur ve yükten bağımsızdır. Bu yüzden yük akımı azaldıkça fark zenere geçer; $I_Z$'nin zenerin dayanabileceği en büyük akımı ($P_{ZM}$ / $V_Z$) aşmaması gerekir.

## 7. Gerilim katlayıcılar ve diyot uygulamaları

### 7.1 Gerilim ikileyici

Diyot-kondansatör birleşimi, yani kenetleyici yapısı, gerilimi katlamak için pek çok devrede kullanılır: iki, üç ve dört katına çıkaran gerilim katlayıcılar vardır. Gerilim ikileyici aslında bir yarım dalga doğrultucudur, ama gerilimi katlayarak doğrultur.

- İlk yarıda girişin uygun yönü geldiğinde ilk diyot iletime geçer, diğeri kesimdedir; $C_1$ kondansatörü $V_m$'ye dolar.
- Öbür yarıda giriş ile $C_1$'deki $V_m$ seri toplanır ($V_m + V_m$); ikinci kondansatör $2V_m$'ye dolar ve devreyi ikinci diyot tamamlar.
- Çıkış ikinci kondansatörün uçlarından alınır ve $2V_m$'dir.

### 7.2 Üçleyici ve dörtleyici

Slayttaki devrede (ekrandan, 01:10:00) transformatör sekonderinde $V_m$, dört diyot ($D_1$-$D_4$) ve dört kondansatör vardır: $C_1$ $V_m$'ye, $C_2$, $C_3$ ve $C_4$ $2V_m$'ye dolar. Uçlara göre ikileyici ($2V_m$), üçleyici ($3V_m$) ve dörtleyici ($4V_m$) çıkışları alınır.

Mantık aynıdır: artı yarıda $C_1$ $V_m$'ye dolar, eksi yarıda $C_2$ $2V_m$'ye dolar, sonraki artı yarıda $C_3$ $2V_m$'ye dolar. $C_1$ ($V_m$) ve $C_3$ ($2V_m$) üzerinden alınan çıkış $3V_m$'dir; $C_2$ ve $C_4$ (her biri $2V_m$) üzerinden alınan çıkış $4V_m$'dir.

Hoca, akımın neden düz gitmek yerine aşağıdaki kola döndüğü sorusuna şöyle cevap verdi: akım her zaman direnci en az olan yoldan ilerler; teoride iletimdeki kol kısa devre olduğu için devre kendini ilk yarıda o koldan tamamlar. Pratikte artış bu kadar net olmaz. Kenetleyicilerin art arda bağlanmasıyla elde edilen bu yapıda diyotların iletim-kesim, iletim-kesim sırasıyla dizilmesi gerekir.

### 7.3 Gerçek diyotla katlayıcı

Diyotlar gerçekse her dolma bir diyot üzerinden olduğu için kayıp oluşur. $C_1$ $V_m - 0{,}7$'ye dolar. Bir sonraki kondansatör $2V_m$'ye değil, $V_m + (V_m - 0{,}7) - 0{,}7 = 2V_m - 1{,}4$'e dolar.

### 7.4 Diyotun kullanım alanları

Doğrultucu devreler pek çok AC-DC devresinde kullanılır: batarya şarj cihazları ve telefon adaptörleri gibi. Diyotlar bazı devreleri alternatif akımdaki negatif akımlara karşı korumak için de kullanılır; bu devrelere koruma devresi (protective circuit) denir.

## 8. Bipolar transistöre giriş

### 8.1 Yapı ve tipler

Diyot, iki katkılı malzemeden (p ve n) oluşan iki terminalli bir elemandı ve p-n ekleminde tükenme bölgesinin (depletion region) daralıp genişlemesiyle doğru polarmada iletime, ters polarmada kesime gidiyordu. Transistör de aynı p-n eklemi mantığıyla tasarlanmış bir yarı iletkendir; tek farkı üç terminalli olmasıdır. Üç bölge ayrı ayrı katkılanmıştır: bazılarında p tipi, bazılarında n tipi taşıyıcı fazladır.

Slayttaki bilgiler (ekrandan, 01:20:00):

- İki transistör tipi vardır: pnp ve npn.
- Terminaller: E (emetör, emitter), B (baz, base), C (kollektör, collector).
- Yapı şeklinde toplam genişlik 0,150 inç, ortadaki baz bölgesi 0,001 inçtir.

İki tip arasındaki fark bazın nasıl katkılandığıdır. Baz n tipi malzemeyle (elektron fazlası) katkılanmışsa transistör pnp, p tipi malzemeyle katkılanmışsa npn olur. Elektronik devrelerde en çok kullanılan tip npn'dir.

### 8.2 Çalışma koşulu

Transistörün çalışma ilkesinde bir eklemde tükenme bölgesi diyottaki gibi küçültülürken öbür eklemde büyütülür:

- **Emetör-baz eklemi doğru polarlanır.** pnp'de emetör p, baz n tipidir; emetöre artı, baza eksi verilir. Diyottaki gibi p tarafındaki pozitif yükler içeri doğru itilir, n tarafındaki elektronlar karşıya geçer ve bu eklemin tükenme bölgesi daralır.
- **Baz-kollektör eklemi ters polarlanır.** pnp'de kollektör p tipidir; kollektöre eksi verilir. Bu eklemin tükenme bölgesi genişler.

npn'de bütün polariteler terstir: n tipi emetöre eksi, p tipi baza artı, n tipi kollektöre artı verilir. Hoca bunun ezberlenmemesi, mantığının kavranması gerektiğini söyledi.

Transistör anahtarlama elemanı ve güç kontrolü gibi birçok amaçla kullanılır; bunlar sonraki derslerde işlenecektir.

**Soru:** npn transistörde de iki tarafta tükenme bölgeleri var mı? Emetör tarafında dar, öbür tarafta geniş mi?

**Cevap:** Evet. npn'de de emetör-baz arasındaki tükenme bölgesi küçültülür, kollektör-baz arasındaki büyütülür. Tek fark, bu koşulu sağlayan dış gerilimlerin polaritesinin pnp'ye göre ters olmasıdır.

### 8.3 Transistör akımları

Slayttaki ifade (ekrandan, 01:25:00): emetör akımı kollektör ve baz akımlarının toplamıdır.

$$I_E = I_C + I_B$$

Bu, devre teorisindeki düğüm analizinin (KCL) sonucudur: bir düğüme giren akımlar çıkan akımlara eşittir. Emetör akımın çıktığı uç, baz ve kollektör akımın girdiği uçlardır (npn için). Slaytta ayrıca kollektör akımının iki bileşenden oluştuğu yazar:

$$I_C = I_{C,\text{çoğunluk}} + I_{CO,\text{azınlık}}$$

> **Hocanın vurgusu:** $I_E = I_C + I_B$ ilişkisi bütün problemlerde çok sık kullanılacaktır; hiçbir zaman unutulmamalıdır.

### 8.4 Transistör sembolü

> **Hocanın vurgusu:** Semboller çok karıştırılıyor. Okun bulunduğu uç her zaman emetördür ve okun ucu her zaman n tipi bölgeyi gösterir.

Ortak uç bazdır, kalan uç kollektördür. Ok bazı gösteriyorsa baz n tipidir; o zaman öbür iki bölge p olmak zorundadır ve transistör pnp'dir. Ok dışarıyı, yani emetörü gösteriyorsa emetör n tipidir ve transistör npn'dir (nnp gibi başka bir tip yoktur). Transistörün pnp mi npn mi olduğunu bilmek önemlidir, çünkü emetör-baz ve baz-kollektör arasının nasıl polarlanacağını bu belirler.

> **Ek bilgi (derste anlatılmadı):** Ok, emetör-baz ekleminin p tarafından n tarafına doğru, yani doğru polarmada akan geleneksel akım yönünde çizilir. Bu yüzden npn'de ok dışarı, pnp'de içeri bakar.

Transistör karakteristikleri ve kullanım grafikleri sonraki derse bırakıldı.

## Örnek Sorular

**Soru 1** (ekrandan, 00:55:00): Giriş $\pm 20$ V tepeli sinüs olan, diyota seri 10 V'luk DC kaynak bulunan kutuplu kenetleyicide (ideal diyot) çıkış hangi değerler arasında salınır?

> **Çözüm (derste verildi):** Negatif yarıda diyot iletir; kondansatör $20 - 10 = 10$ V'a dolar ve çıkış $-10$ V'tur. Pozitif yarıda diyot kesimdedir; çıkış $20 + 10 = 30$ V olur. Çıkış $+30$ V ile $-10$ V arasında salınır.

**Soru 2** (ekrandan, 00:50:00; derste sözlü, 00:50:31): $\pm V$ kare dalga girişli basit kenetleyicide negatif yarıda çıkış kaçtır? Bu sırada diyotun uçları ölçülse $V$ mi, $2V$ mi okunur?

> **Çözüm (derste verildi):** Kondansatör pozitif yarıda $V$'ye dolar. Negatif yarıda giriş ve kondansatör seri toplanır, diyot kesimdedir; çıkış $-2V$ olur ve diyotun uçlarında da $2V$ okunur.

**Soru 3** (derste sözlü, 00:21:06): Tepe değeri 10 V olan bir AC gerilim yarım dalga ve tam dalga doğrultulursa DC değerler kaç olur (ideal diyot)?

> **Çözüm (derste verildi):** Yarım dalga: $0{,}318 \cdot 10 = 3{,}18$ V (hoca yaklaşık 3,1 V dedi). Tam dalga: $0{,}636 \cdot 10 = 6{,}36$ V (hoca yaklaşık 6,3 V dedi).

**Soru 4** (derste sözlü, 00:25:05): Gerçek Si diyotlu köprü doğrultucuya 2 V tepeli AC verilirse ne olur?

> **Çözüm (derste kısmen verildi):** Her yarı periyotta iki diyot iletir ve toplam $2 \cdot 0{,}7 = 1{,}4$ V kaybedilir. İdeal durumda beklenen $0{,}636 \cdot 2 \approx 1{,}27$ V'luk DC değere göre bu kayıp çok büyüktür. Hoca devrenin çalışmayacağını söyledi; tepe değerde çıkışta büyük olasılıkla $2 - 1{,}4 = 0{,}6$ V kalır ve ortalama yaklaşık 0,2 V olur (python ile hesaplandı).

**Soru 5** (derste sözlü, 01:05:53; ekrandan, 01:05:00): $V_Z = 50$ V olan bir zener 70 V'luk girişle iletimdeyken zener gücü nasıl hesaplanır?

> **Çözüm (derste verildi):** Zener uçlarında $V_Z = 50$ V vardır. Güç $P_Z = V_Z I_Z = 50\,I_Z$'dir; $70\,I_Z$ değildir. $I_Z = I_R - I_L$ ile bulunur.

**Soru 6** (derste sözlü, 01:14:00; ekrandan, 01:15:00): Gerilim üçleyiciye 10 V tepeli giriş verilirse çıkış kaç olur? Gerçek diyotlu ikileyicide kondansatörler neye dolar?

> **Çözüm (derste verildi):** İdealde üçleyici çıkışı $3 \cdot 10 = 30$ V'tur. Hoca bunu yarım dalga gibi düşünüp $30 \cdot 0{,}318 \approx 9{,}5$ V (slaytta "≈9 V") hesapladı. Gerçek diyotla $C_1$ $V_m - 0{,}7$'ye, ikinci kondansatör $2V_m - 1{,}4$'e dolar; $V_m = 10$ V için 9,3 V ve 18,6 V.

> **Ders sonrası not:** İdeal katlayıcının çıkışı, yük hafifken büyük olasılıkla yaklaşık sabit bir DC ($3V_m$) gerilimdir; bu yüzden $0{,}318$ ile çarpmak katlayıcının kendi çıkışı için doğru bir ortalama hesabı olmayabilir.

**Soru 7** (derste sözlü, 01:27:40): npn transistörde de iki tarafta tükenme bölgesi var mıdır?

> **Çözüm (derste verildi):** Evet. Emetör-baz tükenme bölgesi doğru polarma ile küçültülür, kollektör-baz tükenme bölgesi ters polarma ile büyütülür; yalnız uygulanan gerilimlerin polaritesi pnp'nin tersidir.

## Dersin Toparlaması

Bu derste diyot uygulamaları baştan tekrar edildi. Gerçek diyotta 0,7 V'un ne zaman hesaba katılacağı ve çıkışın hangi uçtan alındığının sonucu nasıl değiştirdiği vurgulandı. Yarım dalga, köprü ve orta uçlu transformatörlü doğrultucuların ideal ve gerçek DC değerleri karşılaştırıldı. Seri ve paralel kırpıcılarda diyotun iletim ve kesim durumlarına göre çıkışın nasıl çizileceği, kenetleyicilerde ise önce kondansatörün dolduğu gerilimin bulunması gerektiği örneklerle gösterildi. Zener diyotta akım ve güç ilişkileri ile yük direnci soru tipleri, ardından kenetleyicilerin art arda bağlanmasıyla kurulan gerilim katlayıcılar anlatıldı.

Dersin sonunda bipolar transistöre giriş yapıldı: pnp ve npn yapısı, emetör-baz ekleminin doğru, baz-kollektör ekleminin ters polarlanması, $I_E = I_C + I_B$ ilişkisi ve sembolden tipin okunması. Transistör karakteristikleri, kullanım grafikleri ve anahtarlama gibi uygulamalar sonraki derse bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
