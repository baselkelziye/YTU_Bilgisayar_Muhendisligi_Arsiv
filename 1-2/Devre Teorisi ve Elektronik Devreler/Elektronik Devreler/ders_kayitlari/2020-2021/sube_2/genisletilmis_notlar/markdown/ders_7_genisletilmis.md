# Ders 7 Genişletilmiş Notu: Diyot Uygulamaları: Seri ve Paralel Diyot Devreleri, Doğrultucular, Kırpıcılar ve Kenetleyiciler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Devre teorisi bilgisi ve bu dersin yaklaşımı
- 2. Diyotun tekrarı ve seri diyot devreleri
- 3. Paralel diyot devreleri
- 4. Alternatif akım ve doğrultma ihtiyacı
- 5. Yarım dalga doğrultucu ve tepe ters gerilimi
- 6. Tam dalga doğrultucular
- 7. Kırpıcı devreler
- 8. Kenetleyici devreler
- Örnek Sorular
- Dersin Toparlaması

## 1. Devre teorisi bilgisi ve bu dersin yaklaşımı

Derse başlamadan önce bir öğrenci, devre teorisini almış olmanın bu ders için gerekip gerekmediğini sordu. Hoca, bilgisayar mühendisliği programında elektronik devreler dersinin ön koşulunun devre teorisi olmadığını, oysa elektronik bölümlerinde devre teorisinin elektroniğin ön koşulu olduğunu belirtti. Bu yüzden derste gerekli kısımlar yeniden anlatılır. Örneğin op-amp konusu, ilgili konuya gelindiğinde ve AC analize geçmeden önce derste tekrar işlenir.

Hoca, Ohm kanunu ($V = I \cdot R$) ve Kirchhoff kanunları gibi temel yasaların elektronik derslerinde ayrıca anlatılmadığını, ama örnek çözümlerde her adımın bu yasalara dayandırılarak yazıldığını söyledi. Bir direnç üzerindeki gerilimi ölçmek için voltmetrenin dirence paralel bağlanması gibi temel bilgilerin öğrencinin kendi çalışmasıyla tamamlanması beklenir. Devre teorisinin ileri konuları (AC analiz, faz kayması, Laplace dönüşümü, kondansatörün dolma-boşalma eğrisinin ayrıntısı) bu derste çok az kullanılır. Kondansatör, diyotla birlikte kullanıldığı devrelerde (kenetleyiciler) yalnız çalışma mantığıyla anlatılacaktır.

## 2. Diyotun tekrarı ve seri diyot devreleri

### 2.1 Diyotun tek cümlelik tanımı

Önceki derste diyota giriş yapılmıştı. Hoca diyotu tek cümleyle şöyle tanımladı: doğru polarmada akımı tek yönde ileten devre elemanı. Doğru polarizasyonda kısa devre gibi davranır; ters polarizasyonda açık devre (open circuit) olur, yani içinde sonsuz direnç gösterir. Bu derste diyotun elektronik devrelerdeki kullanım alanlarına bakılacaktır.

> **Hocanın vurgusu:** Bu sunumun konusu çok iyi çalışılmalıdır. Diyotun elektronikte ve endüstride kullanımı çok yaygın olduğu için ara sınavda da finalde de bu konudan mutlaka soru gelir.

Hoca diyotun önemini anlatırken onun tarihsel atası olarak vakum tüplerini andı ve ilk bilgisayarlardan ENIAC'ın tüplerle tasarlandığını hatırlattı (slayta "ENIAC" yazdı, ekrandan, 00:15:00).

> **Ek bilgi (derste anlatılmadı):** Vakum tüplü diyot (termiyonik diyot), ısıtılan katottan çıkan elektronların yalnız anoda doğru akabilmesi sayesinde tek yönlü iletim sağlar. ENIAC binlerce vakum tüpü kullanan ilk genel amaçlı elektronik bilgisayarlardan biridir. Yarı iletken diyotlar ve transistörler, tüplerin yaptığı işi çok daha küçük boyutta ve düşük güçle yapar.

### 2.2 Doğru polarma ve eşik gerilimi

Anot artı, katot eksi olacak şekilde gerilim uygulanınca diyot ileri yönde polarlanır (forward bias). Teoride, aksi belirtilmedikçe, anot-katot arasındaki potansiyel farkı sıfırın üstüne çıktığı anda diyot iletime geçer. Sorularda diyotun altına yazılan Si, Ge gibi kısaltmalar diyotun malzemesini gösterir. Silisyum diyot için gerçekçi modelde diyotun yerine 0,7 V'luk bir eşik gerilimi düşünülür: giriş gerilimi bu eşiği aşmadıkça diyot iletime geçmez. Eşik gerilimleri silisyumda 0,7 V, germanyumda 0,3 V, galyum arsenürde 1,2 V'tur.

> **Ders sonrası not:** Hoca 0,7 V'u silisyumdan kaynaklanan "iç direnç" ile açıkladı. Bu eşik gerilimi büyük olasılıkla p-n eklemindeki potansiyel bariyerden (tükenme bölgesi) kaynaklanır; diyotun ayrıca küçük bir iç direnci vardır ve önceki derste eşdeğer devrede ayrı bir eleman olarak gösterilmişti.

### 2.3 Seri diyot devresinin analizi

Slayttaki devrede bir $E$ kaynağı, silisyum diyot ve $R$ direnci seri bağlıdır (ekrandan, 00:15:00). Doğru polarma için slayttaki analiz şöyledir:

- $V_D = 0{,}7$ V (eğer $E < 0{,}7$ V ise $V_D = E$)
- $V_R = E - V_D$
- $I_D = I_R = I_T = V_R / R$

Diyot iletimdeyken üzerine paralel bir voltmetre bağlanırsa yalnız diyotun eşik gerilimi, yani 0,7 V okunur.

Ters polarmada (kaynak ters bağlanınca) diyot ideal olarak açık devre gibi davranır (ekrandan, 00:20:00):

- $V_D = E$
- $V_R = 0$ V
- $I_D = 0$ A

Hoca bunu KVL ile açıkladı. Kirchhoff'un gerilimler kanununa göre kaynağın ürettiği gerilim devredeki elemanlar üzerinde harcanır. Diyot akım geçirmediği için direnç üzerinde gerilim oluşmaz; bu yüzden kaynağın bütün gerilimi diyot üzerinde görülür.

Eşiğin altındaki bir gerilim de aynı sonucu verir. Örneğin $E = 0{,}3$ V uygulanırsa silisyum diyot 0,7 V'u aşamadığı için iletime geçmez ve diyot üzerindeki gerilim $V_D = 0{,}3$ V olur. Buradan şu kural çıkar:

- Diyot kesimdeyken üzerindeki gerilim her zaman besleme gerilimine eşittir.
- Diyot iletimdeyken üzerindeki gerilim yalnız eşik gerilimi kadardır (Si için 0,7 V).

Soruda diyotun ideal olduğu söylenirse malzeme önemsizdir; diyot sıfırın üstündeki her gerilimde iletir ve üzerinde gerilim birikmez. Aynı 0,3 V'luk kaynakla ideal diyot üzerinde 0 V okunur.

## 3. Paralel diyot devreleri

### 3.1 Örnek: iki paralel silisyum diyot

Diyotların yerleşimi farklı devre tasarımlarına imkân verir. İlk örnekte 10 V'luk kaynağa $0{,}33\ \text{k}\Omega$'luk direnç ve onun ardından paralel iki silisyum diyot ($D_1$, $D_2$) bağlıdır; çıkış $V_O$ diyotların üzerinden alınır (ekrandan, 00:25:00).

Diyotlar aynı malzemeden ve aynı yapıda olduğu için akımlar eşit bölünür: $I_{D1} = I_{D2}$. Ayrıca düğüm analizine (KCL) göre düğüme giren akım çıkan akımların toplamına eşittir: $I_1 = I_{D1} + I_{D2}$.

Gerilim hesabına geçmeden şunu görmek gerekir: diyotlar doğru polarmadadır, yani iletimdedir. Silisyum oldukları için her birinin üzerinde 0,7 V düşer. Paralel oldukları için ikisinin gerilimi aynıdır ve çıkış da bu gerilimi ölçer. Çözüm adım adım:

- $V_{D1} = V_{D2} = V_O = 0{,}7$ V
- $V_R = 10 - 0{,}7 = 9{,}3$ V
- $I_R = \dfrac{E - V_D}{R} = \dfrac{9{,}3\ \text{V}}{0{,}33\ \text{k}\Omega} \approx 28$ mA
- $I_{D1} = I_{D2} = \dfrac{28\ \text{mA}}{2} = 14$ mA

Python ile kontrol: $9{,}3/0{,}33 = 28{,}18$ mA, yarısı $14{,}09$ mA.

### 3.2 Kollarda direnç olursa

Hoca kollardan birine direnç konursa $I_1 = I_{D1} + I_{D2}$ eşitliğinin hâlâ geçerli olup olmadığını sordu.

**Soru:** Kollardan birinde direnç olursa akımların toplamı yine ana kol akımına eşit olur mu? **Cevap:** Olur. Akım kaçağı yoktur, akım iki yoldan da devresini tamamlamak zorundadır. Direnç, kollar arasındaki akım paylaşımını değiştirir ama toplamı değiştirmez. Seri bir kolda akım her yerde aynıdır, bu yüzden direnç olsa bile iki kol akımının toplamı ana kol akımına eşittir.

### 3.3 Devrenin değiştirilmesi

Hoca ikinci kolu tamamen kaldırıp birinci kola ikinci bir diyotu seri eklediğini düşündürdü. Bu durumda kolda $0{,}7 + 0{,}7 = 1{,}4$ V düşer, direnç üzerinde $10 - 1{,}4$ V kalır ve ana kol akımı $I_1$ biraz azalır. Ancak artık akım iki kola bölünmediği için tek kalan koldaki diyot akımı öncekine göre artar.

Diyotlar ters bağlanırsa ikisi de kesimdedir, akım sıfır olur ve $V_O = 10$ V okunur.

Hoca diyotlu devrelerin genel mantığını şöyle özetledi: doğru polarmada diyot üzerine eşik gerilimi (Si 0,7 V, Ge 0,3 V, GaAs 1,2 V) düşer, geri kalan gerilim dirençlere dağıtılır; ters polarmada diyot açık devredir.

## 4. Alternatif akım ve doğrultma ihtiyacı

Diyotların en çok kullanıldığı yer doğrultucu devrelerdir. Doğrultmanın neden gerektiğini anlamak için önce AC sinyal hatırlatıldı. AC sinyal sinüs dalgasıyla gösterilir. $T$ periyotlu bir sinyalde $T/2$ anına kadar sinyal bir yönde, $T/2$'den $T$'ye kadar ters yöndedir.

Bir sinüs kaynağına bir direnç bağlanırsa akım yarı periyotta bir yönde, öbür yarı periyotta ters yönde akar. Ölçü aletinin probları direnç üzerinde sabit tutulursa ilk yarıda pozitif, ikinci yarıda negatif bir gerilim okunur. Hoca burada eksi gerilimin aslında "ters yönlü akımla verilen gerilim" anlamına geldiğini vurguladı: fiziksel bir multimetrede kırmızı (artı) prob ters akımla beslenince ekranda negatif değer görülür.

Hoca, doğru akımın Edison'la, alternatif akımın Tesla'yla anıldığını hatırlattı. Sabit bir gerilim (örneğin 5 V) DC'dir. Hocanın anlatımına göre DC'yi çok uzak mesafelere taşımak zordur, oysa AC gerilim düşük maliyetle uzaklara gönderilebilir; sanayide daha güçlü iletim için üç fazlı AC kullanılır. Şebekedeki gerilim AC'dir, ama bataryalar ve dizüstü bilgisayarlar gibi küçük cihazlar AC'yi doğrudan kullanamaz; gerilimin DC biçimine getirilmesi gerekir. Bu işi doğrultucular yapar.

> **Ders sonrası not:** Hoca DC'nin "kendi içinde yavaş yavaş sönümlendiğini" ve bu yüzden uzağa taşınamadığını söyledi. AC'nin enerji iletiminde tercih edilmesinin asıl nedeni büyük olasılıkla transformatörlerle gerilimin kolayca yükseltilip düşürülebilmesidir: yüksek gerilimde aynı güç daha küçük akımla taşınır ve hatlardaki $I^2R$ kaybı azalır. Günümüzde çok uzun hatlarda yüksek gerilim DC (HVDC) iletimi de kullanılmaktadır.

**Soru:** Evlerdeki ampuller de bu yüzden sürekli yanıp sönüyor mu? **Cevap:** Hoca, şebekedeki klasik ampullerin içindeki direncin ısınmasıyla çalıştığını, yapılarının farklı olduğunu ve sürekli yanıp söndükleri şeklinde düşünülmemesi gerektiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Akkor flamanlı ampulde ışık, flamanın ısınmasıyla oluşur. Şebeke 50 Hz olduğu için güç saniyede 100 kez sıfıra iner, ama flaman bu kadar kısa sürede soğuyamadığı (ısıl eylemsizlik) için parlaklıktaki dalgalanma çok küçüktür ve göz bunu fark etmez.

## 5. Yarım dalga doğrultucu ve tepe ters gerilimi

### 5.1 Çalışma ilkesi

Yarım dalga doğrultucuda (half-wave rectifier) sinüs kaynağı, seri bir diyot ve bir yük direnci $R$ vardır; çıkış $v_o$ direnç üzerinden alınır (ekrandan, 00:30:00).

- Pozitif yarı periyotta diyot doğru polarlanır ve iletime geçer. İdeal diyot kısa devre gibi olduğu için $v_o = v_i$ olur.
- Negatif yarı periyotta diyot ters polarlanır ve kesime gider. Akım oluşmadığı için direnç üzerindeki gerilim sıfırdır: $v_o = 0$ V.

Böylece sinüs sinyalin yalnız pozitif kısımları çıkışa geçer. Slaytın ifadesiyle: diyot yalnız doğru polarlandığında iletir, bu yüzden AC periyodun yalnız yarısı çıkışa geçer.

DC ile çalışan devreler bu tür sinyallerin ortalaması üzerinden iş görür. Sinüs dalgası hiç değiştirilmeseydi ortalaması sıfır olurdu ve bir işe yaramazdı. Negatif kısımlar silinince ortalama pozitif olur:

$$V_{DC} = 0{,}318\,V_m$$

Burada $V_m$ AC gerilimin tepe değeridir. Hocanın örneğinde tepe değeri 5 V olan bir sinyal için ortalama yaklaşık 1,6 V'tur ($0{,}318 \times 5 = 1{,}59$ V, python ile kontrol edildi).

> **Ek bilgi (derste anlatılmadı):** 0,318 katsayısı $1/\pi$'dir. Yarım dalga doğrultulmuş sinüsün bir periyottaki ortalaması $\frac{1}{2\pi}\int_0^{\pi} V_m \sin\theta\, d\theta = \frac{V_m}{\pi}$ olarak bulunur. Tam dalga doğrultmada iki yarı periyot da dolu olduğu için ortalama $2V_m/\pi \approx 0{,}636\,V_m$ olur.

### 5.2 Tepe ters gerilimi (PIV)

Yarım dalga doğrultucuda ters polarmada diyotun açık devre olduğu ve çıkışta bir şey görülmediği söylendi. Ancak bunun bir sınırı vardır. Ters gerilim diyotun dayanabileceği en büyük değeri aşarsa diyot bozulur, kısa devre gibi davranmaya başlar ve çıkışta negatif değerler de okunur. Diyotun ters polarmada dayanabileceği bu en büyük gerilime tepe ters gerilimi (peak inverse voltage, PIV) denir.

> **Hocanın vurgusu:** Devrenin yarım dalga doğrultucu olarak çalışabilmesi için diyotun PIV değeri, devreye verilen giriş geriliminin tepe değerinden büyük olmak zorundadır.

## 6. Tam dalga doğrultucular

### 6.1 Tam dalga doğrultmanın avantajı

Tam dalga doğrultucu (full-wave rectifier), sinüsün negatif yarısını da pozitife çevirir. Yarım dalgada her pozitif yarı periyodun ardından boş bir yarı periyot gelir ve ortalama $0{,}318\,V_m$ olur. Tam dalgada aradaki boşluklar da doldurulduğu için iki kat iş yapılır ve ortalama $0{,}636\,V_m$ olur. Derste iki tam dalga yaklaşımı ele alındı.

### 6.2 Köprü doğrultucu

Köprü doğrultucuda (bridge rectifier) dört diyot köprü biçiminde bağlanır ve yük direnci köprünün ortasındadır (ekrandan, 00:40:00). Hoca diyot yerleşimini akılda tutmak için bir benzetme verdi: bir taraftaki diyotlar "sırt sırta", öbür taraftakiler "yüz yüze" durur.

- Pozitif yarı periyotta bir diyot çifti doğru polarlanır ve kısa devre gibi davranır; akım bu çift üzerinden yük direncinden geçer, öbür çift kesimdedir.
- Negatif yarı periyotta kaynağın uçları yer değiştirir. Bu kez öbür çift iletime geçer ve akım yine yük direncinden aynı yönde geçer.

Hoca bunu multimetre problarıyla açıkladı: kırmızı prob direncin bir ucuna, siyah (COM) prob öbür ucuna konup hiç değiştirilmezse iki yarı periyotta da aynı işaretli gerilim okunur. Böylece negatif kısım pozitife çevrilmiş olur ve direnç üzerinde

$$V_{DC} = 0{,}636\,V_m$$

kadar bir DC gerilim elde edilir. Köprüde her yarı periyotta akım iki diyottan geçer.

### 6.3 Orta uçlu transformatörlü doğrultucu

İkinci yapı transformatör kullanır. Hoca transformatörlerin apartman zili gibi devrelerde de kullanıldığını örnek verdi. Derste kullanılan transformatör girişteki $v_i$ gerilimini iki kola birer $v_i$ olarak verir. Böylece iki ayrı yarım dalga devresi kurulmuş olur.

- Pozitif yarı periyotta üst koldaki diyot iletir, alttaki kesimdedir; çıkışı yalnız üst kol üretir.
- Negatif yarı periyotta alt koldaki diyot iletir, üstteki kesimdedir. Yük direnci üzerindeki polarite değişmediği için negatif yarı da pozitif olarak okunur.

Sonuçta yine ortalama $0{,}636\,V_m$ olan bir DC gerilim üretilir. Bu yapının avantajı, her yarı periyotta akımın tek bir diyottan geçmesidir; köprüde ise iki diyottan geçer.

**Soru:** Transformatör gerilimi iki katına çıkarıyorsa yalnız gerilim mi değişiyor? **Cevap:** Hoca burada kendi ifadesini düzeltti: transformatör 5 V'u 10 V yapmaz; aynı 5 V'u iki ayrı kanaldan 5'er volt olarak verir, yani iki kanal açar. Her kanaldaki sinyalin işareti de girişle aynıdır.

### 6.4 Gerçekçi değerler

Gerçek diyotlarda her iletimdeki diyot üzerinde 0,7 V düşer. Slayttaki özet tablo şöyledir (ekrandan, 00:45:00):

| Doğrultucu | İdeal $V_{DC}$ | Gerçekçi $V_{DC}$ |
|---|---|---|
| Yarım dalga | $0{,}318\,V_m$ | $0{,}318\,V_m - 0{,}7$ |
| Köprü | $0{,}636\,V_m$ | $0{,}636\,V_m - 2(0{,}7\ \text{V})$ |
| Orta uçlu transformatörlü | $0{,}636\,V_m$ | $0{,}636\,V_m - 0{,}7$ V |

Slayta göre $V_m$ AC gerilimin tepe değeridir; orta uçlu transformatörlü devrede tepe değeri, transformatör sekonderinin orta uca göre gerilimidir. Köprüde iki diyot, yarım dalga ve orta uçlu devrede tek diyot çıkarılır.

> **Hocanın vurgusu:** Bu formüllerde işlem sırası önemlidir. Önce $0{,}318\,V_m$ (ya da $0{,}636\,V_m$) hesaplanır, sonra diyot düşümü çıkarılır; $(V_m - 0{,}7)$ çarpılmaz.

> **Ders sonrası not:** Hoca ders içinde bir yerde $(V_m - 0{,}7)$'nin $0{,}636$ ile çarpılacağını söyledi, sonra bunu slayttaki biçime göre düzeltti. Diyot düşümü sinyalin tepesinden eksildiği için ortalama büyük olasılıkla $0{,}318\,(V_m - 0{,}7)$'ye daha yakındır. Ajan sayısal integralle kontrol etti: $V_m = 5$ V için gerçek ortalama 1,26 V, $0{,}318(V_m - 0{,}7) = 1{,}37$ V, slayttaki $0{,}318\,V_m - 0{,}7 = 0{,}89$ V çıkar. Sınavda hangi biçimin beklendiği için hocanın slaytına uymak gerekir.

## 7. Kırpıcı devreler

### 7.1 Kırpıcı nedir?

Doğrultuculardan sonra ikinci kullanım alanı kırpıcı (clipper) devrelerdir. Kırpıcı, sinyalin bir kısmını kesen devredir. Yarım dalga doğrultucu, sinyalin negatif yarısını zaman ekseninde kestiği için bir kırpıcıdır; ama tam dalga doğrultucu kırpıcı değildir. Bu yüzden her doğrultucuya kırpıcı denemez. Öte yandan bir sinüsün yalnız tepelerini kesen devre de kırpıcıdır. Yani kırpıcı, doğrultucudan daha genel bir kavramdır. Kırpıcıların çok farklı tasarımları olabileceği için konuyu mantığıyla anlamak esastır.

### 7.2 Beslemeli seri kırpıcı

Slayttaki devrede girişe tepe değeri $\pm 20$ V olan bir sinüs uygulanır. Girişle seri olarak $V = 5$ V'luk bir DC kaynak ve diyot, çıkışta da $R$ direnci vardır; kaynak diyotu doğru yönde polarlayacak biçimde bağlanmıştır (ekrandan, 00:50:00). Slaytın açıklamasına göre kırpma diyotuna seri bir DC kaynak eklemek, diyotun etkin doğru polarmasını değiştirir.

Analiz $t = 0$ anından başlar:

- $v_i = 0$ iken diyot iletimdedir, çünkü 5 V'luk kaynak onu doğru polarlar. Akım direnç üzerinden geçer ve çıkışta $v_o = 0 + 5 = 5$ V görülür.
- $v_i$ arttıkça diyot iletimde kalır ve çıkış $v_o = v_i + 5$ V olarak artar. Tepe değeri $20 + 5 = 25$ V'tur.
- $v_i$ sıfırın altına indikten sonra da $-5$ V'a kadar diyot iletimdedir, çünkü 5 V'luk kaynak onu hâlâ doğru polarmada tutar.
- $v_i = -5$ V olduğunda diyot üzerindeki net gerilim sıfırlanır ve diyot kesime gider: $v_o = -5 + 5 = 0$ V. Giriş $-5$ V'un altında kaldıkça çıkış 0'dır; bu bölge kırpılmıştır.
- Giriş yeniden $-5$ V'un üstüne çıkınca (örneğin $-4{,}9$ V'ta diyot üzerinde 0,1 V pozitif kalır) diyot tekrar iletime geçer ve çıkış yeniden 25 V'a doğru yükselir.

Slaytta $-5$ V seviyesi geçiş gerilimi (transition voltage) olarak işaretlenmiştir.

**Soru:** Diyot ideal olmasaydı bunu da hesaba katacak mıydık? **Cevap:** Evet. Diyotun içinde 0,7 V'luk ters yönlü bir kaynak varmış gibi düşünülür. Bu durumda 5 V'luk kaynak aslında 4,3 V gibi etki eder.

**Soru:** 5 V'luk kaynak yerine 20 V'luk kaynak bağlansaydı hiç negatif değer görmez miydik? **Cevap:** Hoca $t = 0$'da çıkışın 20 V olacağını, girişin tepesinde 40 V'a çıkacağını, giriş $-20$ V'a indiğinde çıkışın sıfıra düşüp yeniden yükseleceğini söyledi. Öğrencinin "tam doğrultucu gibi çalışıyor" yorumunu da onayladı.

> **Ders sonrası not:** Bu durumda çıkış büyük olasılıkla 0 ile 40 V arasında bir sinüs olur; yani girişin tamamı 20 V yukarı kaydırılmış olarak çıkışa geçer ve hiçbir kısım kırpılmaz. Çıkış tam dalga doğrultulmuş bir sinyal biçiminde değildir, yalnızca hiç negatife inmez.

Hoca bu tür devrelerin sayısız varyasyonu olabileceğini, bu yüzden akla takılan her senaryoyu önce kâğıt üzerinde çözüp sonra bir simülasyon programında kurarak osiloskopta kontrol etmeyi önerdi.

### 7.3 Basit paralel kırpıcı

Diyot paralel bağlanarak da kırpıcı yapılabilir (ekrandan, 00:55:00). Bu devrede girişe seri bir $R$ direnci, çıkışa paralel bir diyot vardır ve çıkış diyot üzerinden alınır. Slaytın ifadesiyle paralel kırpıcıdaki diyot, kendisini doğru polarlayan her gerilimi "kırpar"; diyota seri bir DC kaynak eklenerek kırpma seviyesi değiştirilebilir.

- Pozitif yarı periyotta diyot iletimdedir. İdeal diyot üzerinde gerilim düşmez, bu yüzden çıkış 0'dır (silisyum diyotta 0,7 V).
- Negatif yarı periyotta diyot kesimdedir. Kesimdeki diyot üzerindeki gerilim giriş gerilimidir; çıkışta girişin negatif kısmı görülür.

Slaytta hem kare dalga hem üçgen dalga için çıkış gösterilmiştir: pozitif kısımlar sıfıra iner, negatif kısımlar aynen geçer.

**Soru:** Pozitif yarıda diyot doğru polarlandığı hâlde çıkış neden sıfır oldu? **Cevap:** Diyot iletimdeyse kısa devredir, yani ideal diyotta bir tel gibidir. Bir eleman üzerinde gerilim oluşması için hem akım hem direnç gerekir; tel üzerinde gerilim ölçülemez. Diyot ideal olmasaydı kendi eşik gerilimini gösterirdi ve çıkışta 0,7 V okunurdu.

> **Hocanın vurgusu:** Çıkışın polaritesine dikkat edilmelidir. Soruda $v_o$'nun artı-eksi uçları ters verilirse (bir öğrencinin cevapladığı gibi) grafik eksene göre simetrik olarak ters döner. Bu küçük ayrıntıyı kaçırmak yanlış sonuca götürür.

### 7.4 Basit ve beslemeli seri kırpıcıların özeti

Hoca kırpıcı özet slaytındaki devreleri tek tek inceledi (ekrandan, 01:00:00). Her devrede ideal diyot varsayılır.

**Basit seri kırpıcılar:** Diyot bir yöne bağlandığında yalnız negatif yarı periyot çıkışa geçer (pozitif yarıda diyot açık devredir, çıkış 0). Diyot ters çevrildiğinde yalnız pozitif yarı periyot geçer. İki devre birbirinin diyotu terslenmiş hâlidir.

**Beslemeli seri kırpıcılar:** Diyotla seri bir $V$ kaynağı (öngerilim, bias) vardır. Hoca bu sorularda analize her zaman $t = 0$ anından başlamayı önerdi, çünkü sıfır anındaki durum ipucu verir.

- Sol üst devre: $t = 0$'da kaynak diyotu doğru polarlar, diyot iletimdedir. Kaynak çıkışa ters yönde yansıdığı için çıkışta $-V$ okunur. Pozitif giriş kaynağın etkisini sıfırlayınca (girişin $V$'yi aştığı anda) diyot kesime gider ve çıkış 0 olur. Giriş yeniden $V$'nin altına inince diyot tekrar iletir ve çıkış negatife doğru $-(V_m + V)$'ye kadar iner. Hoca sayısal örnek olarak $V = 2$ V aldı: giriş 2,1 V olduğunda diyot üzerinde 0,1 V'luk ters gerilim kalır ve diyot kesime gider.
- Sağ üst devre: $t = 0$'da kaynak diyotu ters polarlar, diyot kesimdedir. Pozitif giriş kaynağın gerilimini aştığında (örneğin $V = 2$ V iken giriş 2,1 V olduğunda) diyot iletime geçer ve direnç üzerinde $V_m - V$ tepeli bir çıkış oluşur; geri kalan zamanda diyot kesimdedir.
- Sol alt devre: $t = 0$'da diyot kesimdedir. Diyotun iletmesi için ona negatif gerilim gelmesi, bunun için de girişin $-V$'nin altına inmesi gerekir. Bu anlardan sonra çıkışta yalnız $-(V_m - V)$ tepeli negatif bir kısım görülür.
- Sağ alt devre: $t = 0$'da kaynak diyotu doğrudan doğru polarlar, diyot iletimdedir. Pozitif giriş bunu destekler ve çıkış $V_m + V$'ye kadar çıkar. Negatif yarıda giriş $-V$'nin altına indiğinde diyot kesime gider ve çıkış sıfırlanır.

### 7.5 Beslemeli paralel kırpıcılar

Paralel kırpıcılarda çıkış direnç üzerinden değil, diyot ve ona seri kaynak üzerinden alınır (ekrandan, 01:05:00).

> **Hocanın vurgusu:** Paralel kırpıcıda ölçülen yer diyotun üstüdür. Diyot iletimdeyse ideal durumda 0 V (gerçek diyotta 0,7 V) ve varsa seri kaynağın gerilimi okunur; diyot kesimdeyse giriş gerilimi okunur. Bu kural her zaman geçerlidir.

Slayttaki dört beslemeli paralel kırpıcının çıkışları şöyledir:

- Sol üst (diyot aşağı yönlü, kaynağın artı ucu yukarıda): giriş $V$'nin altındayken diyot kesimdedir ve çıkış girişi izler; giriş $V$'yi aşınca diyot iletir ve çıkış $V$'de sabitlenir. Negatif yarı periyot $-V_m$'ye kadar aynen geçer.
- Sağ üst (diyot yukarı yönlü): $t = 0$'da diyot ters polarmadadır, kesimdedir; giriş pozitif yarıda $V_m$'ye kadar aynen okunur. Negatif yarıda giriş $-V$'yi aşınca diyot iletime geçer ve çıkış $-V$'de kırpılır.
- Sol alt (diyot aşağı yönlü, kaynak ters): $t = 0$'da kaynak diyotu iletimde tutar ve çıkışta $-V$ okunur; kaynağın eksi ucu çıkışın artı ucuna geldiği için değer negatiftir. Giriş $-V$'nin altına inince diyot kesime gider ve çıkış $-V_m$'ye kadar girişi izler.
- Sağ alt (diyot yukarı yönlü, kaynak ters): giriş $V$'nin altındayken kaynak diyotu iletimde tutar ve çıkış $V$'dir; giriş $V$'yi aşınca diyot kesime gider ve çıkış $V_m$'ye kadar girişi izler.

> **Ders sonrası not:** Hoca sol üst devreyi anlatırken diyotun önce iletime geçip giriş $V$'yi aşınca kesime gittiğini söyledi; slayttaki çıkış grafiğine göre durum büyük olasılıkla tersidir: giriş $V$'nin altındayken diyot kesimde (çıkış girişi izler), $V$'nin üstünde iletimdedir (çıkış $V$'de kırpılır). Sağ alt devrede de hoca önce diyotun "hiç kesime gitmeyeceğini" söyledi, ardından verdiği 5 V ve 6 V örneğiyle doğru davranışı açıkladı (aşağıdaki soru-cevap).

Sağ alt devre üzerine iki soru soruldu.

**Soru:** Diyotun altındaki $V$ kaynağı grafiklere neden eklenmiyor; iletim durduğu için mi? **Cevap:** Kaynak hesaba katılır, ama girişin üstüne toplanmaz. Üstüne eklenebilmesi için kaynağın diyotu girişle aynı yönde desteklemesi gerekir. Burada diyot zaten iletimdedir ve kısa devre olmuştur, yani bir tel gibidir; çıkışta yalnız kaynağın gerilimi görülür. Kaynak seri bağlı olsaydı girişin üstüne eklenirdi; paralel bağlantıda eklenmez.

**Soru:** Girişe AC uygulandığı için mi DC kaynak sönümlenmiyor? **Cevap:** Hoca bunu düğüm gerilimiyle açıkladı. Kaynak $V = 5$ V olsun. Girişe 1 V verildiğinde diyot iletimdedir ve çıkıştaki ölçü aleti 5 V'luk kaynağın düğüm gerilimini, yani 5 V okur. Girişe 6 V verildiğinde giriş 5 V'luk kaynağın etkisini aşar, diyot ters polarlanır ve kesime gider. Artık diyottan akım geçmez ve düğüm gerilimi girişin gerilimidir; ölçü aleti 6 V okur (7, 8, 10 V da aynı biçimde). Giriş 5 V'un altındaki bütün değerlerde diyot iletimde olduğu için çıkış hiç 5 V'un altına inmez.

### 7.6 Çift yönlü kırpıcı

Son kırpıcıda iki diyot ve iki kaynak ($V_1$, $V_2$) zıt yönlerde paralel bağlıdır; slaytta $|V_1| > |V_2|$ olarak verilmiştir (ekrandan, 01:05:00). Hoca $V_1 = 5$ V örneğiyle anlattı (ekrandan, 01:20:00).

- $t = 0$'da giriş sıfırdır ve iki diyot da iletimde değildir; çıkış 0'dır.
- Giriş küçük pozitif değerler alırken (örneğin 0,1 V) $V_1$ kolundaki diyot hâlâ ters polarmadadır. Çıkış girişi izler; giriş değeri yavaş yavaş okunur.
- Giriş $V_1$'i (5 V) geçtiği anda bu koldaki diyot iletime geçer ve çıkış $V_1$'de sabitlenir.
- Negatif yarıda aynı durum öbür kolda olur: çıkış $-V_2$'de kırpılır.

Bu devreye çift yönlü kırpıcı (double-sided clipper) denir; önceki kırpıcılarda kırpma tek yönlüydü.

**Soru:** Giriş 5 V'u geçseydi çıkışta 6 V okur muyduk? **Cevap:** Hayır. Giriş 5 V'u geçince 5 V'luk kaynağın bulunduğu koldaki diyot iletime geçer ve çıkış 5 V'ta sabit kalır. Bu kol iletime geçmeden önce devre tamamlanmadığı için çıkışta yalnız giriş okunur; kol iletime geçip devreyi tamamladığı anda çıkışta yalnız kaynağın gerilimi okunur.

> **Hocanın vurgusu:** Bu konu ezberle çalışılmaz; mantığı oturtulmalıdır. Kırpıcılardan çok farklı ve kafa karıştırıcı sorular üretilebilir. Derste görülen bütün devreleri bir simülasyon programında kurup çıkışlarını gözlemlemek, hatta diyotun iç gerilimini temsil eden 0,7 V'luk bir kaynak ekleyerek grafiğin nasıl değiştiğine bakmak çok faydalıdır.

## 8. Kenetleyici devreler

### 8.1 Kondansatörün rolü

Son devre türü kenetleyicilerdir (clamper), yani sinyali üst üste bindirme devreleri. Bir öğrencinin seri kırpıcıda 20 V'luk kaynakla çıkışın 40 V'a çıkacağı yönündeki örneğine benzer bir yaklaşımdır, ama burada bir kondansatör kullanılır. Slaytın ifadesiyle bir diyot ve kondansatör birleştirilerek bir AC sinyal belirli bir DC seviyeye "kenetlenebilir" (ekrandan, 01:25:00).

Hoca kondansatörün çalışma ilkesini kutuplu bir kondansatörle anlattı. Akım bir yönde akarken kondansatör, uygulanan gerilime göre zıt kutuplu olarak dolar. Akım ters döndüğünde kondansatör biriktirdiği gerilimi boşaltır; bu sırada devreyi besleyen gerilim de olduğu için ikisi seri iki pil gibi toplanır ve iki katı gerilim ortaya çıkar.

### 8.2 Kare dalga ile basit kenetleyici

Slayttaki devrede seri bir kondansatör $C$, paralel bir diyot ve paralel bir $R$ direnci vardır; çıkış direnç üzerinden alınır. Giriş $+V$ ile $-V$ arasında bir kare dalgadır (ekrandan, 01:25:00).

- Pozitif yarı periyotta diyot iletime geçer. İdeal diyot üzerinde gerilim birikmez; ayrıca akım her zaman dirençsiz yolu seçer. Diyot kısa devre olduğu için akım diyottan geçer, direnç üzerinden akım geçmez ve $v_o = 0$ olur. Bu sırada devre tamamlandığı için kondansatör $V$'ye dolar.
- Negatif yarı periyotta diyot kesime gider, yani sonsuz direnç gösterir. Kondansatördeki gerilim ile giriş gerilimi seri iki pil gibi toplanır ve bütün akım direnç üzerinden geçer. Akım $2V/R$ kadardır ve çıkışta $-2V$ okunur; eksi işareti, çıkışın artı ucuna bu kez eksinin gelmesindendir.

Sonuçta çıkış 0 ile $-2V$ arasında salınır; sinyalin biçimi ve genliği ($2V$) değişmez, yalnız DC seviyesi kayar.

### 8.3 Beslemeli kenetleyici

Beslemeli kenetleyicide diyota seri bir DC kaynak (örnekte 10 V) eklenmiştir; giriş $\pm 20$ V'luk bir sinüstür (ekrandan, 01:30:00). Slayta göre giriş sinüs, kare ya da üçgen gibi herhangi bir dalga biçiminde olabilir ve DC kaynak kenetleme seviyesini ayarlamayı sağlar. Slayttaki çıkış $-10$ V ile $+30$ V arasında salınan bir sinüstür.

Hoca analize önce $t = 0$ anından başladı, sonra yöntemini düzeltti:

> **Hocanın vurgusu:** Kenetleyici devrelerde analize diyotun iletime geçtiği yarı periyottan başlamak daha mantıklıdır, çünkü önce kondansatörün dolması gerekir ve kondansatör yalnız diyot iletimdeyken dolar.

Adım adım analiz:

- $t = 0$'da diyot doğru polarmada değildir.
- Negatif yarı periyotta giriş $-10$ V'u geçtiğinde ($-11$, $-12$, $-13$ V...) giriş 10 V'luk kaynağın etkisini aşar ve diyot iletime geçer. Bu sırada kondansatör girişe zıt kutupla dolmaya başlar: giriş $-11$ V iken 1 V'a, $-12$ V iken 2 V'a ve böyle devam ederek dolar.
- Giriş $-20$ V tepe değerine ulaştığında kondansatör $20 - 10 = 10$ V'a dolmuş olur.
- Pozitif yarıda diyot kesime gider. Bütün akım $R$ üzerinden geçer ve çıkışta giriş ile kondansatör gerilimi toplanır: tepe değerinde $20 + 10 = 30$ V okunur.

**Soru:** Grafikte $t = 0$'daki 10 V, diyotun altındaki 10 V'luk kaynaktan mı geliyor? **Cevap:** Hayır. Hoca sinyalin sonsuz bir döngü olduğunu, $t = 0$'ın yalnızca bir başlangıç noktası (kesme noktası) olarak seçildiğini söyledi. $t = 0$'da giriş sıfırken çıkışta 10 V görülmesinin nedeni, kondansatörün önceki periyotta 10 V'a dolmuş olmasıdır. Kondansatör kaynağın kendisi kadar değil, girişin tepe değeri ile kaynak gerilimi arasındaki fark kadar dolar.

Hoca farkı başka bir sayıyla gösterdi: kaynak 5 V olsaydı diyot giriş $-5$ V'u geçince iletime geçer ve kondansatör $-6$, $-7$, $-8$ V'ta dolmaya devam ederek $20 - 5 = 15$ V'a dolardı. Bu durumda çıkış $t = 0$'da 15 V'tan başlar, en çok $20 + 15 = 35$ V'a çıkar, en alt değeri $-20 + 15 = -5$ V olurdu.

> **Hocanın vurgusu:** Kenetleyici sorularında "kaynağın gerilimini girişin üstüne koy, kondansatörde iki fazı topla" gibi bir ezberle sonuç yazılmamalıdır; her devrede kondansatörün neye dolduğu ayrıca bulunmalıdır.

### 8.4 Kenetleyicilerin özeti

Ders sonunda kenetleyici özet slaytı gösterildi (ekrandan, 01:35:00). Slaytta $\pm V$ kare dalga girişi için altı devre vardır; hepsinde çıkış genliği $2V$'dir:

| Devre | Çıkış aralığı |
|---|---|
| Basit kenetleyici, diyot aşağı yönlü | 0 ile $-2V$ |
| Basit kenetleyici, diyot yukarı yönlü | 0 ile $+2V$ |
| Beslemeli, diyot aşağı yönlü, $V_1$ kaynağı | $V_1$ ile $V_1 - 2V$ |
| Beslemeli, diyot yukarı yönlü, $V_1$ kaynağı | $V_1$ ile $V_1 + 2V$ |
| Beslemeli, diyot aşağı yönlü, $V_1$ ters | $-V_1$ ile $-V_1 - 2V$ |
| Beslemeli, diyot yukarı yönlü, $V_1$ ters | $-V_1$ ile $-V_1 + 2V$ |

Hoca ikinci satırdaki beslemeli devreyi anlatmaya başladı: kaynak diyotu ters polarladığı için diyotun iletmesi için girişin $V_1$'e kadar bir gerilim vermesi gerekir; diyot iletime geçince kondansatör $V$ ile $V_1$ arasındaki fark kadar dolar ve yarı periyot dönünce bu gerilim girişin üstüne eklenerek çıkışta okunur. Kaynak diyotu iletimde tutacak yönde bağlandığında ise kondansatör baştan dolmaya başlar ve giriş sıfırken bile çıkış bir miktar aşağı kaymış olur. Özet slaytının ayrıntılı analizi bir sonraki derse kaldı.

<!-- BELİRSİZ: Hocanın özet slaytındaki beslemeli kenetleyicilerde kondansatörün dolduğu gerilimi ifade ettiği cümle ("V-I-V1'e kadar şarj olacak") altyazıda bozuk; tablo değerleri slayttaki grafiklerden alındı. -->

## Örnek Sorular

1. (derste sözlü, 00:21:04) Silisyum bir diyota seri bir dirençle 0,3 V uygulanıyor. Diyot üzerindeki gerilim nedir? Diyot ideal olsaydı ne okunurdu?

   > **Çözüm:** Silisyum diyot 0,7 V eşiğini aşamadığı için kesimdedir; kesimdeki diyot üzerindeki gerilim besleme gerilimine eşittir: $V_D = 0{,}3$ V. Diyot ideal olsaydı sıfırın üstündeki her gerilimde iletirdi ve üzerinde $V_D = 0$ V okunurdu.

2. (ekrandan, 00:25:00) $E = 10$ V, $R = 0{,}33\ \text{k}\Omega$ ve paralel iki silisyum diyottan oluşan devrede $V_O$, $V_R$, $I_R$, $I_{D1}$ ve $I_{D2}$'yi bulun.

   > **Çözüm:** Diyotlar iletimdedir: $V_O = V_{D1} = V_{D2} = 0{,}7$ V. $V_R = 10 - 0{,}7 = 9{,}3$ V. $I_R = 9{,}3 / 0{,}33 \approx 28$ mA. Diyotlar aynı olduğu için $I_{D1} = I_{D2} = 28/2 = 14$ mA.

3. (derste sözlü, 00:26:26) Aynı devrede ikinci kol kaldırılır ve birinci kola ikinci bir silisyum diyot seri eklenirse ne değişir?

   > **Çözüm:** Hoca nitel cevabı verdi: kolda 1,4 V düşer, ana kol akımı azalır, ama tek kalan koldan geçen diyot akımı öncekine göre artar.
   >
   > **Çözüm (derste verilmedi, sayısal):** $I_1 = (10 - 1{,}4)/0{,}33 \approx 26{,}1$ mA (python ile kontrol edildi). Ana kol akımı 28,2 mA'dan 26,1 mA'ya düşer; diyot akımı ise 14,1 mA'dan 26,1 mA'ya çıkar. Çıkış iki diyotun üzerinden alınırsa $V_O = 1{,}4$ V olur.

4. (derste sözlü, 00:28:09) Aynı devrede diyotlar ters bağlanırsa $V_O$ ve $I_1$ ne olur?

   > **Çözüm:** Diyotlar ters polarmada, yani kesimdedir. Akım geçmez: $I_1 = 0$. Dirençte gerilim düşmediği için $V_O = 10$ V.

5. (derste sözlü, 00:34:49) AC sinüs sinyalin ortalaması nedir? Tepe değeri 5 V olan bir sinyal yarım dalga doğrultulursa ortalama ne olur?

   > **Çözüm:** Sinüsün ortalaması 0'dır. Yarım dalga doğrultulmuş sinyalin ortalaması $0{,}318\,V_m = 0{,}318 \times 5 \approx 1{,}6$ V'tur.

6. (ekrandan, 00:50:00) Tepe değeri $\pm 20$ V olan sinüs, 5 V'luk seri kaynaklı ideal diyotlu seri kırpıcıya uygulanıyor. Çıkışı çizin. Kaynak 20 V olsaydı ne olurdu?

   > **Çözüm:** $t = 0$'da diyot iletimdedir ve $v_o = 5$ V. Çıkış $v_o = v_i + 5$ V'tur ve en çok 25 V'a çıkar. $v_i < -5$ V iken diyot kesimdedir ve $v_o = 0$. Diyot silisyum ise kaynak etkin olarak 4,3 V gibi davranır. Kaynak 20 V olsaydı çıkış $t = 0$'da 20 V'tan başlar, 40 V'a çıkar ve giriş $-20$ V'ta sıfıra iner; negatif değer görülmez.

7. (derste sözlü, 00:54:56) Basit paralel kırpıcıda $v_o$'nun artı-eksi uçları ters yazılırsa çıkış grafiği nasıl değişir?

   > **Çözüm:** Bir öğrencinin cevapladığı gibi grafik eksene göre ters döner: girişin negatif yarısı çıkışta pozitif olarak görünür.

8. (ekrandan, 01:15:00) Diyotu yukarı yönlü ve 5 V'luk kaynağı ters bağlı beslemeli paralel kırpıcıya 1 V ve 6 V uygulanırsa çıkışta ne okunur?

   > **Çözüm:** 1 V'ta diyot iletimdedir ve çıkışta kaynağın düğüm gerilimi 5 V okunur. 6 V'ta giriş kaynağın etkisini aşar, diyot kesime gider ve çıkışta 6 V okunur.

9. (ekrandan, 01:30:00) 10 V'luk kaynaklı beslemeli kenetleyiciye $\pm 20$ V'luk sinüs uygulanıyor. Kondansatör kaç volta dolar ve çıkış hangi aralıkta salınır? Kaynak 5 V olsaydı ne olurdu?

   > **Çözüm:** Diyot giriş $-10$ V'un altına inince iletir; kondansatör $20 - 10 = 10$ V'a dolar. Çıkış $-20 + 10 = -10$ V ile $20 + 10 = 30$ V arasında salınır. Kaynak 5 V olsaydı kondansatör 15 V'a dolar ve çıkış $-5$ V ile $35$ V arasında salınırdı.

## Dersin Toparlaması

Bu derste diyotun temel davranışından yola çıkılarak diyotlu devrelerin analizi yapıldı. Önce seri ve paralel diyot devrelerinde diyot iletimdeyken üzerinde eşik gerilimi, kesimdeyken besleme geriliminin tamamı düştüğü kuralı yerleştirildi ve akımlar Ohm kanunu ile KCL'den hesaplandı. Ardından AC'nin DC'ye çevrilmesi ihtiyacından doğrultuculara geçildi: yarım dalga doğrultucu $0{,}318\,V_m$, köprü ve orta uçlu transformatörlü tam dalga doğrultucular $0{,}636\,V_m$ ortalama verir; gerçek diyotlarda iletimdeki diyot sayısı kadar 0,7 V kayıp olur ve diyotun tepe ters gerilimi giriş tepe değerinden büyük olmalıdır.

Dersin ikinci yarısında sinyalin bir kısmını kesen kırpıcılar (seri, paralel, beslemeli ve çift yönlü) ile sinyali bir kondansatör yardımıyla belirli bir DC seviyeye kaydıran kenetleyiciler incelendi. Bu devrelerde analiz için iki ipucu verildi: kırpıcılarda $t = 0$ anında diyotun durumuna bakmak, kenetleyicilerde kondansatörün dolduğu yarı periyottan başlamak. Kenetleyici özet slaytındaki beslemeli devrelerin ayrıntılı analizi bir sonraki derste, kenetleyicilerin başından yeniden ele alınarak sürdürülecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
