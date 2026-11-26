# Ders 5 Genişletilmiş Notu: Diyotlara Giriş, p-n Eklemi ve Diyot Karakteristikleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki derslerle bağlantı
- 2. Diyot: iki uçlu, tek yönde ileten eleman
- 3. Gerilim tanımı ve referans yönü
- 4. İdeal diyot karakteristiği
- 5. Yarı iletken malzemeler ve p-n eklemi
- 6. Doğru ve ters kutuplama
- 7. Gerçek diyot karakteristiği
- 8. Zener bölgesi ve zener diyot
- 9. Sıcaklık etkisi ve gerçek diyot modeli
- 10. Diyot kılıfları, test, LED ve diyot dizileri
- 11. Basit diyot devreleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki derslerle bağlantı

Ders, önceki iki slayt setinin kısa bir hatırlatmasıyla başlar. İlk sette analog dünyadan sayısal dünyaya geçerken hangi adımların izlendiği, ikinci sette ise bu geçişte kullanılan algılayıcılar (sensörler), eyleyiciler (actuator) ve algılayıcılarla ilgili temel kavramlar işlenmişti. Bu derste artık diyotlara giriş yapılır. Diyotlar, yarı iletken teknolojisiyle üretilen ilk yapılardır; dersin ilerleyen kısmında görülecek transistörler de aynı yarı iletken malzemelerden üretilir.

## 2. Diyot: iki uçlu, tek yönde ileten eleman

Diyot, tıpkı direnç gibi iki uçlu bir devre elemanıdır. Sembolü bir üçgen ve onun ucundaki bir çizgiden oluşur. Üçgenin bulunduğu taraf artı uç, çizginin bulunduğu taraf eksi uçtur (ekrandan, 00:05:00). Slaytta diyot üzerinde gerilim $V_D$ artı uçtan eksi uca doğru tanımlanmış, akım $I_D$ ise artı uçtan eksi uca doğru akan yönde gösterilmiştir.

Diyotun temel görevi akımın yalnız bir yönde akmasına izin vermektir. Slayttaki ifade: "A diode ideally conducts in only one direction." (ekrandan, 00:05:00). İdeal durumda:

- Artı uç eksi uçtan daha yüksek gerilimdeyse (örneğin uçlara 1 V, 2 V uygulanmışsa) diyot kısa devre gibi davranır. Akan akımı diyot değil, devrenin geri kalanı sınırlar ("$I_D$ limited by circuit").
- Artı uca eksi uçtan daha düşük gerilim uygulanmışsa (örneğin −1 V, −2 V) diyot açık devre gibi davranır; sanki orada iletim yapacak bir tel yokmuş gibidir ve $I_D = 0$ olur.

Hoca bunun ideal bir anlatım olduğunu, gerçek karakteristiklere adım adım geçileceğini belirtir.

## 3. Gerilim tanımı ve referans yönü

Diyotun ne zaman ilettiğini anlamak için iki nokta arasındaki gerilimin nasıl tanımlandığı netleştirilir. Adı ne olursa olsun bir X elemanı düşünülür; bir ucu a, diğer ucu b olsun (ekrandan, 00:15:00).

### 3.1 Tanım

Eleman üzerindeki gerilim $V_X$, artı ucu a tarafına, eksi ucu b tarafına gelecek biçimde tanımlanırsa:

$$V_X = V_A - V_B$$

Burada $V_A$, a noktasının toprağa göre gerilimi; $V_B$ ise b noktasının toprağa göre gerilimidir. Yani bir elemanın üzerindeki gerilim, artı olarak işaretlenen ucun gerilimi eksi olarak işaretlenen ucun geriliminden çıkarılarak bulunur.

Tanım ters yapılsaydı, yani artı uç b tarafına, eksi uç a tarafına konsaydı, $V_X = V_B - V_A$ olurdu. Bu durumda a noktası daha yüksek gerilimdeyse eleman üzerinde negatif bir gerilim okunur. Hoca, değerlendirmenin her zaman artıdan eksiye yapılan bu tanıma (referansa) göre yapılacağını vurgular.

### 3.2 Diyota uygulanması

Diyotta artı uç (a) anot, eksi uç (b) katot tarafıdır; dolayısıyla $V_D = V_A - V_B$. Diyotun iletmesi için önemli olan uçların toprağa göre değerleri değil, aralarındaki farktır:

- $V_B = 0$ iken $V_A = 0{,}1$ V ya da $0{,}01$ V olsa bile $V_D$ pozitiftir.
- $V_B = 5$ V, $V_A = 5{,}1$ V ise $V_D = 5{,}1 - 5 = 0{,}1$ V olur; bu da pozitif bir gerilimdir ve ideal diyot iletime geçer.
- İki uç da 5 V ise $V_D = 0$ olur; diyot üzerinde gerilim farkı olmadığı için akım akmaz.

## 4. İdeal diyot karakteristiği

İdeal diyotun iki durumu vardır: iletim ve kesim. Slaytta "Conduction Region" başlığı altında $V_D > 0$ durumu gösterilir (ekrandan, 00:15:00).

- $V_D > 0$ olduğu anda (sıfıra çok yakın küçük bir pozitif değerde bile) diyot üzerinden akım akmaya başlar. Slaytın alt kısmındaki ifadeler, iletimde diyot üzerindeki gerilimin 0 V olduğunu ve akımın (diyot açısından) sınırsız olduğunu belirtir.
- $V_D < 0$ bölgesinde (−1 V, −2 V, −3 V, −5 V…) $I_D$ her zaman sıfırdır.

Bu iki parça birleştirilince $I_D$–$V_D$ grafiği şöyle olur: negatif $V_D$ ekseni boyunca akım sıfırda kalır, $V_D = 0$ noktasında akım dikey olarak yükselir. Hoca bu ideal eğriyi kırmızıyla çizer; daha sonra gerçek eğriyi maviyle çizerek ikisini karşılaştırır (ekrandan, 00:30:00).

## 5. Yarı iletken malzemeler ve p-n eklemi

### 5.1 Yarı iletken malzemeler ve katkılama

Diyotlar ve transistörler yarı iletken malzemeden üretilir. Bu konunun temelleri yarı iletken fiziği dersinde görüldüğü için derste kabaca üzerinden geçilir. Yarı iletken malzeme temelde üç tiptir: silisyum (silikon), germanyum ve galyum arsenit bileşiği.

Saf hale getirilmiş bu malzemelere çeşitli atomlar eklenir; bu eklemeye katkılama (doping) denir. Katkılamayla iki tip malzeme üretilir:

- **n tipi malzeme:** iletim bandında elektronların fazla olduğu malzeme. Bu elektronlar hareketli negatif yükler olarak adlandırılır.
- **p tipi malzeme:** valans bandında deliklerin bulunduğu malzeme. Delikler aslında hareket etmez, ama elektron ayrıldıkça delik yer değiştiriyormuş gibi davrandığı için hareketli pozitif yük gibi değerlendirilir.

### 5.2 p-n eklemi

p tipi ve n tipi malzeme birleştirildiğinde p-n eklemi (p-n jonksiyonu) elde edilir. Bu en basit diyot yapısıdır. p tarafı diyotun artı ucuna, n tarafı eksi ucuna karşılık gelir. Transistörler ise daha çok katmanlı ve daha karmaşık yapılardır.

Eklemde ne olur? Slayttaki açıklamaya göre n tipi taraftaki fazla iletim bandı elektronları p tipi taraftaki valans bandı deliklerine çekilir ve eklemi geçerek p tipi malzemeye göç eder (elektron akışı) (ekrandan, 00:20:00). Bunun sonucunda eklemin çevresinde bir geçiş bölgesi oluşur: p tarafında eklemin yanında negatif yükler, n tarafında pozitif yükler birikir. Bu bölgeye tükenme bölgesi (depletion region) denir; uzay yükü katmanı (space charge layer) olarak da adlandırılır.

Tükenme bölgesinde yüklerin ayrışması bir potansiyel farkı oluşturur. Potansiyel negatif taraftan başlayıp eklem boyunca toplanarak artar ve bölgenin sonunda en büyük değerine ulaşır. Buna potansiyel bariyeri denir.

Daha önce ideal diyot için "$V_D > 0$ ise iletir" denmişti; bu anlatım kolaylığı içindir. Gerçekte diyotun iletmesi için bu bariyerin aşılması gerekir. Örneğin silisyum diyot yaklaşık 0,7 V'luk bir gerilimden sonra iletime geçer.

## 6. Doğru ve ters kutuplama

Diyot üzerine $V_D$ gerilimi uygulandığında iki durum ayrılır:

- $V_D$, 0,7 V'tan büyükse (ideal durumda 0'dan büyükse) buna doğru kutuplama (forward bias) denir: diyotu iletime geçirecek yönde gerilim uygulanmıştır.
- Diyotu iletime geçirmeyen, açık devre gibi davranmasını sağlayan ters yöndeki gerilim uygulamasına ters kutuplama (reverse bias) denir.

> **Ders sonrası not:** Hoca, $V_D$'nin 0,7 V'tan küçük olduğu örnekler arasında −1 V, −2 V ile birlikte 0,3 V'u da sayıp bunları ters besleme olarak anar. Doğrusu büyük olasılıkla şudur: ters kutuplama $V_D < 0$ durumudur; $0 < V_D < 0{,}7$ V aralığı doğru kutuplamanın eşik altı kısmıdır ve silisyum diyotta burada akım çok küçük kaldığı için diyot pratikte iletmiyormuş gibi görünür.

### 6.1 Akımlar ve potansiyel (slayt)

Slaytta p-n eklemindeki akımlar üç durumda gösterilir (ekrandan, 00:25:00):

| Durum | Bariyer potansiyeli | Akımlar |
| :--- | :--- | :--- |
| (a) Yalıtılmış eklem | $V_b$ | p'den n'ye ve n'den p'ye akımlar dengede |
| (b) Doğru kutuplama | $V_b - V$ (bariyer düşer) | p'den n'ye akım büyür, ters akım aynı kalır |
| (c) Ters kutuplama | $V_b + V$ (bariyer yükselir) | p'den n'ye akım küçülür, yalnız küçük ters akım kalır |

### 6.2 Kutuplamasız durum

Diyot üzerine 0 V uygulanırsa, yani a ve b uçlarının gerilimi aynıysa, akım akmaz. Hoca, 0 V uygulamanın iki ucun da 0 V olması demek olmadığını hatırlatır: iki uç da 5 V'ta olsa diyot üzerindeki gerilim farkı yine sıfırdır.

### 6.3 Ters kutuplama

Ters yönde gerilim uygulandığında p tarafına eksi, n tarafına artı gelir. Tükenme bölgesi genişler, potansiyel bariyeri yükselir ve akımı sınırlar. Bu durumda yalnızca $I_s$ ile gösterilen küçük bir sızıntı (kaçak) akımı geçebilir. Bu, diyotun çalışmama, yani açık devre olma durumudur.

### 6.4 Doğru kutuplama

Diyotu iletime geçirecek yönde gerilim uygulandığında p tarafına pozitif yük verilir; bu yükler tükenme bölgesindeki negatiflerle dengelenir. Tükenme bölgesi daralır, yük miktarı azalır ve potansiyel bariyeri düşer. Bariyer düşünce çoğunluk taşıyıcılarının akımı hızla artar. Sızıntı akımı yine sabit olarak akmaya devam eder, ama çoğunluk akımı onu çok aştığı için o yönde ciddi bir akış başlar. $V_D$ ne kadar artırılırsa o kadar fazla akım akar.

Hoca, diyot karakteristiğinin osiloskopla ya da bir analizörle (karakteristik çıkarıcı) doğrudan elde edilebildiğini belirtir.

> **Ek bilgi (derste anlatılmadı):** Yarı iletken fiziği dersinde görülen azınlık taşıyıcı sürüklenme akımları ve difüzyon akımları bu dengeyi ayrıntılı açıklar; hoca bu ayrıntılara (kaçak ve sızma akımlarının hesapları) girmeyeceğini söyler.

## 7. Gerçek diyot karakteristiği

### 7.1 Diyot akım bağıntısı

Slaytta p-n ekleminin akım bağıntısı verilir (ekrandan, 00:30:00):

$$I \approx I_s\left(\exp\frac{eV}{kT} - 1\right)$$

Oda sıcaklığında $e/kT \approx 40\ \text{V}^{-1}$ alınır. Buna göre:

- $V > +0{,}1$ V ise: $I \approx I_s \exp\left(\dfrac{eV}{kT}\right) = I_s \exp(40V)$
- $V < -0{,}1$ V ise: $I \approx I_s(0 - 1) = -I_s$

$I_s$, ters doyma akımıdır (reverse saturation current).

> **Ek bilgi (derste anlatılmadı):** $kT/e$, ısıl gerilim ($V_T$) olarak bilinir ve oda sıcaklığında (yaklaşık 300 K) büyük olasılıkla 25–26 mV civarındadır; bunun tersi yaklaşık 38–40 V$^{-1}$ eder. Boylestad'ın kitabında aynı bağıntı Shockley denklemi olarak, bir ideallik çarpanı $n$ ile $I_D = I_s(e^{V_D/nV_T} - 1)$ biçiminde yazılır.

### 7.2 İdeal ve gerçek eğri

Hoca aynı eksenler üzerinde ideal ve gerçek eğriyi karşılaştırır (ekrandan, 00:30:00). İdeal eğride sıfırı biraz geçince akım akar. Gerçek eğride ise:

- Negatif gerilimde akım sıfır değil, küçük bir sızıntı akımı ($-I_s$ civarı) vardır.
- Pozitif gerilimde akım yavaş yavaş artar ve belli bir gerilimden sonra hızla yükselir. Bu gerilim silisyum için yaklaşık 0,7 V, germanyum için yaklaşık 0,3 V'tur.

Hoca, şu sorunun cevabının önemli olduğunu belirtir: grafik neden $V_D = 0$'ın solunda yukarı gitmiyor? Çünkü $V_D$ artıdan eksiye tanımlanmıştır; negatif $V_D$ ters kutuplama demektir ve bu bölgede ileri yönde akım yoktur.

### 7.3 Kitaptaki gerçek karakteristik

"Actual Diode Characteristics" slaytında ticari bir silisyum diyotun eğrisi, bağıntıdan (Eq. 1.4) elde edilen eğriyle birlikte verilir (ekrandan, 00:35:00). Slayttaki notlar:

- Kutuplamasız, ters kutuplama ve doğru kutuplama bölgelerine dikkat edilmelidir.
- Her bölgenin ölçeğine dikkat edilmelidir: ileri bölgede akım ekseni mA (0–20 mA), ters bölgede µA (0 ile −0,4 µA arası) ölçeğindedir; gerilim ekseni ters bölgede −40 V'a kadar uzanır.
- Bölgeler: doğru kutuplama $V_D > 0$ V, $I_D > 0$ mA; kutuplamasız $V_D = 0$ V, $I_D = 0$ mA; ters kutuplama $V_D < 0$ V, $I_D = -I_s$.

### 7.4 Malzemeye göre eşik gerilimleri

Standart diyotlarda akımın hızla yükselmeye başladığı gerilimler malzemeye göre değişir:

| Malzeme | Yaklaşık eşik gerilimi |
| :--- | :--- |
| Silisyum (Si) | 0,7 V |
| Germanyum (Ge) | 0,3 V |
| Galyum arsenit (GaAs) | 1,2 V |

## 8. Zener bölgesi ve zener diyot

### 8.1 Zener bölgesi

Şimdiye kadar ters bölgede yalnız küçük bir sızıntı akımı olduğu söylendi. Ancak ters gerilim çok artırılırsa belli bir noktadan sonra ters yönde akım hızla artar. Bu bölgeye zener bölgesi, bu gerilime de $V_Z$ denir. $V_Z$ üretim sırasında farklı diyotlarda sağa sola kaydırılabilir; böylece örneğin −5 V'luk, −3 V'luk ya da −12 V'luk zenerler üretilebilir.

### 8.2 Zener diyot

Bu özellikten yararlanılarak normal diyotun tersine çalışan zener diyotlar üretilir. Zener diyot ters bağlanır: belli bir gerilim aşıldığında ters yönde akım hızla akar. Hoca örnek verir: 5 V'luk bir zener düşünülsün; gerilim 5,1 V'a çıktığında o yönde akım akması istenir. Normal diyota göre ters bağlandığı için normal diyot yönüyle bakıldığında üzerine negatif gerilim düşmektedir.

Slayttaki tanımlar (ekrandan, 00:45:00):

- "A Zener is a diode operated in reverse bias at the Zener voltage ($V_Z$)." Zener, zener geriliminde ters kutuplamada çalıştırılan bir diyottur.
- "Common Zener voltages are between 1.8 V and 200 V." Yaygın zener gerilimleri 1,8 V ile 200 V arasındadır.

Normal diyottan ayırt edilebilmesi için zener sembolünde katot çizgisinin uçları kıvrık çizilir. Slayttaki şekilde zener dikey çizilmiştir: üst uç artı, alt uç eksi; $I_Z$ akımı yukarıdan aşağıya akar ve diyot üzerindeki gerilim $V_Z$'dir. Hoca, zenerle ilgili soruların ileride çözüleceğini söyler.

## 9. Sıcaklık etkisi ve gerçek diyot modeli

### 9.1 Sıcaklık etkisi

Yarı iletken teknolojisini en çok etkileyen konulardan biri sıcaklıktır. Sıcaklık yarı iletkene ekstra enerji ekler ve diyotun gerilimlerini değiştirir. Slayttaki maddeler (ekrandan, 00:40:00):

- Sıcaklık arttıkça diyota enerji eklenir.
- İleri iletim için gereken doğru kutuplama gerilimi azalır.
- Ters kutuplamadaki ters akım artar.
- En büyük ters kutuplama çığ (avalanche) gerilimi artar.
- Germanyum diyotlar sıcaklık değişimlerine silisyum ve galyum arsenit diyotlardan daha duyarlıdır.

### 9.2 Diyotun direnci

Şimdiye kadar diyot yalnız bir aç-kapa elemanı gibi düşünüldü. Gerçekte diyotun hem DC'de hem AC'de gösterdiği bir iç direnç de vardır. Hoca bu direnç seviyelerinin nasıl belirlendiğini bu derste geçer.

### 9.3 Gerçek diyot eşdeğer devresi

İdeal olmayan bir diyot üç parçayla modellenebilir:

1. Bir ideal diyot,
2. Aşılması gereken bariyeri temsil eden bir DC gerilim kaynağı (silisyum için 0,7 V),
3. Diyotun iç direnci.

Bu modelin önemli sonucu, ders sonundaki bir öğrenci sorusunda tekrar açıklanır (bkz. Bölüm 11.3).

## 10. Diyot kılıfları, test, LED ve diyot dizileri

### 10.1 Sembol ve kılıflar

Genel gösterimde p ekleminin bulunduğu artı taraf anot, n ekleminin bulunduğu eksi taraf katottur. Gerçek diyotlarda katot tarafı genellikle gövde üzerinde bir çizgiyle işaretlenir; bazen diyotun sembolü gövdeye çizilir. Güç uygulamalarında farklı tipte kılıflar kullanılır. Bilgisayar anakartı gibi yeni kartlarda ise delikli bacaklı elemanlar yerine yüzeye monte edilen elemanlar kullanılır; bunlara SMD (Surface Mount Device) denir ve diyotlarla da bu biçimde karşılaşılır.

### 10.2 Diyot testi

Diyot, ölçü aletinin direnç ölçme kademesiyle kontrol edilebilir. Kırmızı (artı) prob bir uca, siyah prob diğer uca konur:

- Kırmızı prob anotta, siyah prob katottayken düşük direnç okunur.
- Problar ters bağlanınca nispeten çok daha yüksek direnç okunur.

Böylece iki yön de denenerek düşük direncin okunduğu bağlantıda kırmızı probun değdiği ucun anot (artı uç) olduğu anlaşılır.

<!-- BELİRSİZ: altyazıda ölçü aleti "10 metre" diye geçiyor (00:43:15); bağlamdan büyük olasılıkla ohmmetre/multimetre kastediliyor -->

### 10.3 LED

Cep telefonu ekranlarından bilgisayar ekranlarına ve televizyonlara kadar çok yerde, üzerinden akım geçtiğinde ışık yayan diyotlar kullanılır: ışık yayan diyot, yani LED.

Hoca bir ekran hücresini örnek verir: kırmızı (red), yeşil (green) ve mavi (blue) ışık yayan üç LED bir paket içinde, katotları ortak bir toprağa bağlı olsun.

- Yalnız kırmızı LED'in ucuna 5 V, diğerlerine 0 V verilirse kırmızı bir piksel görülür.
- Yalnız mavi LED'e 5 V verilirse mavi ışık çıkar.
- Kırmızı ve yeşile 5 V, maviye 0 V verilirse iki ışık birleşir ve sarı elde edilir.
- Kırmızı ile mavi birleşince mor elde edilir.

Böylece gerilimlerle oynanarak bir renk hücresi, yani piksel oluşturulur. Bu yapılar mikron seviyesinde üretildiği için büyük çizilen hücre gerçekte çok küçük bir alan kaplar ve bu, ekranın piksel çözünürlüğünü belirler.

### 10.4 Diyot dizileri

Birden fazla diyot tek bir entegre devre (IC) içinde paketlenebilir; çeşitli kombinasyonlar vardır (ekrandan, 00:50:00). Slaytta DIP kılıflı bir entegre ve iki dizi gösterilir:

| Dizi | Ortak uç (slaytta 14 numaralı uç) | Bir diyotu iletime geçirmek için |
| :--- | :--- | :--- |
| Ortak anot (common anode) | Anotlar birleşik; ortak uca +5 V verilir | İlgili diyotun ucu (1, 2, 3, 4, 8, 9, 10, 11) 0 V'a çekilir |
| Ortak katot (common cathode) | Katotlar birleşik; ortak uç toprağa bağlanır | İlgili diyotun ucuna 5 V verilir |

Ortak anotlu dizide bir diyotun ucunda da 5 V varsa o diyot iletime geçmez, çünkü uçları arasında gerilim farkı yoktur. Ayrı ayrı diyot yerleştirmek yerine bu tür paketlenmiş diziler devre elemanı olarak kullanılabilir.

## 11. Basit diyot devreleri

Bir sonraki derste diyotun devre içinde çalıştığı nokta, devre yapısına göre ne kadar akım akıttığı ve çalışma anındaki akım ve gerilimlerin belirlenmesiyle ilgili örnekler çözülecektir. Bu derste ilk iki basit örnek gösterilir.

### 11.1 Seri diyot devresi

En basit diyot devresinde bir besleme (gerilim kaynağı $E$), bir direnç $R$ ve bir silisyum diyot seri bağlıdır. Direnç, devrede asıl beslenecek, enerjiyi kullanacak kısmı (işlem yapan bir eleman, bir ekran, bir motor gibi güç çeken bir yapıyı) temsil eder; bu yüzden yük direnci (load) olarak adlandırılır. Diyot burada ters yönde akım akmasını engeller; akım hep tek yönde akar.

**Doğru kutuplama ($E > 0{,}7$ V).** Diyot üzerindeki $V_D$ 0,7 V'u geçtiği için diyot iletime geçer. Bu durumda:

$$V_R = E - V_D = E - 0{,}7\ \text{V}$$

Diyot akımı ana koldan geçen akımla, yani direnç akımıyla aynıdır:

$$I_D = I_R = \frac{V_R}{R}$$

**Ters kutuplama.** Diyot iletmezse akım akmaz (ekrandan, 00:55:00):

- $I_D = I_R = 0$ olduğu için direnç üzerinde gerilim düşmez: $V_R = I_R R = 0$ V.
- Direncin iki ucu aynı potansiyeldedir. Direncin alt ucu toprakta olduğu için diyotun dirence bağlı ucu (B noktası) da 0 V'tadır; direnç sanki doğrudan toprak gibi kabul edilebilir.
- Diyotun kaynağa bağlı ucu (A noktası) kaynak gerilimindedir. Dolayısıyla $V_D = V_A - V_B = E - 0 = E$ olur; kaynak geriliminin tamamı diyotun üzerine düşer.

Slayttaki analiz özeti: "Diodes ideally behave as open circuits"; $V_D = E$, $V_R = 0$ V, $I_D = 0$ A (ekrandan, 00:55:00).

**Soru:** Bu ödevlerde ve laboratuvarlarda diyotu gerçekleştirirken yukarıdaki gibi mi (eşdeğer devreyle mi) kullanacağız? **Cevap:** Hoca soruyu, diyotların kullanım alanlarına göre farklı yapılarını göstereceğini söyleyerek sembol ve kılıf gösterimine geçer (bkz. Bölüm 10.1).

### 11.2 Paralel iki diyotlu devre

Derste son örnek olarak 10 V'luk bir kaynak, 330 Ω'luk bir direnç ve direncin ucuna birbirine paralel bağlı iki silisyum diyot verilir. Çözüm Örnek Sorular bölümünde adım adım verilmiştir.

### 11.3 İletimdeki diyotun gerilimi

**Soru:** Son örnekte diyotlar neden 0,7 V kabul edildi? Akım akıyorsa her zaman 0,7 V mu olur? **Cevap:** Diyotlar silisyum olarak verilmiştir. Silisyum diyot bariyeri aştıktan sonra üzerinde 0,7 V olarak kalır; bariyer sabittir ve 0,7 V aşıldıktan sonra akım akmaya başlar. Germanyumda bu değer 0,3 V'tur. Yani diyot iletimdeyken bile potansiyel bariyerini üzerinde barındırır. Eşdeğer devrede ideal diyotla seri duran gerilim kaynağı bu bariyeri temsil eder; diyot iletime geçse bile $V_D = 0{,}7$ V olur.

> **Hocanın vurgusu:** İletimdeki silisyum diyot üzerindeki gerilim 0,7 V'ta kalır; devre çözümlerinde diyot gerilimi bu değerle alınır.

## Örnek Sorular

### Soru 1: Diyot uç gerilimleri (derste sözlü, 00:14:23)

Bir diyotun anodu (A noktası) toprağa göre 5,1 V, katodu (B noktası) 5 V'tadır. Diyot üzerindeki gerilim nedir ve ideal diyot iletir mi?

**Çözüm (derste verildi):** $V_D = V_A - V_B = 5{,}1 - 5 = 0{,}1$ V. Gerilim pozitif olduğu için ideal diyot iletime geçer. (İki uç da 5 V olsaydı $V_D = 0$ olur, akım akmazdı.)

> **Ders sonrası not:** Gerçek bir silisyum diyotta 0,1 V eşik geriliminin (yaklaşık 0,7 V) altında kaldığı için büyük olasılıkla belirgin bir akım akmaz; derste verilen sonuç ideal diyot içindir.

### Soru 2: Ters kutuplanmış seri diyot devresi (ekrandan, 00:55:00)

Kaynak $E$, silisyum diyot ve direnç $R$'den oluşan seri devrede diyot ters kutuplanmıştır. $V_D$, $V_R$ ve $I_D$ nedir?

**Çözüm (derste verildi):** Ters kutuplamada diyot ideal olarak açık devre gibi davranır, $I_D = 0$ A. Akım akmadığı için $V_R = 0$ V ve direncin diyota bağlı ucu 0 V'tadır. Diyotun diğer ucu kaynak gerilimindedir; dolayısıyla $V_D = E$.

### Soru 3: Paralel iki silisyum diyot (derste sözlü, 00:55:26)

10 V'luk kaynağa 330 Ω'luk bir direnç bağlanmış, direncin diğer ucuyla toprak arasına birbirine paralel iki silisyum diyot konmuştur. Direnç gerilimini, ana kol akımını ve her diyotun akımını bulun.

<!-- BELİRSİZ: devrenin şekli ekranda bu ana denk gelen karede görünmüyor; değerler altyazıdan alındı ("330 onluk bir direnç"), 330 Ω değeri derste bulunan 28 mA sonucuyla tutarlı -->

**Çözüm (derste verildi):**

- Direncin kaynağa bağlı ucu A, diyotlara bağlı ucu B olsun. $V_A = 10$ V.
- 10 V uygulandığı için diyotlar iletimdedir. Paralel oldukları için ikisinin de üzerinde 0,7 V düşer; dolayısıyla $V_B = 0{,}7$ V.
- $V_R = V_A - V_B = 10 - 0{,}7 = 9{,}3$ V.
- $I_1 = I_R = \dfrac{V_R}{R} = \dfrac{9{,}3\ \text{V}}{330\ \Omega} \approx 28$ mA (python ile: 28,18 mA).
- Ana kol akımı B noktasında ikiye ayrılır. Diyotlar özdeş olduğu için $I_{D1} = I_{D2} = \dfrac{28\ \text{mA}}{2} \approx 14$ mA (python ile: 14,09 mA).

## Dersin Toparlaması

Bu derste diyota giriş yapıldı. Önce ideal diyot, tek yönde ileten iki uçlu bir eleman olarak tanımlandı ve diyot üzerindeki gerilimin $V_D = V_A - V_B$ biçiminde referans yönüne göre okunduğu vurgulandı. Ardından yarı iletken malzemeler, katkılama, n ve p tipi malzemeler ve p-n eklemi anlatıldı; eklemde oluşan tükenme bölgesi ve potansiyel bariyeri, gerçek diyotun neden silisyumda 0,7 V, germanyumda 0,3 V civarında iletime geçtiğini açıkladı. Doğru ve ters kutuplamada bariyerin nasıl değiştiği, $I \approx I_s(e^{eV/kT} - 1)$ bağıntısı, gerçek karakteristik, zener bölgesi ve zener diyot, sıcaklık etkisi, gerçek diyot eşdeğer devresi, diyot kılıfları ve testi, LED ve diyot dizileri gösterildi.

Ders, seri bir diyot devresinde doğru ve ters kutuplama analiziyle ve paralel iki silisyum diyotlu bir sayısal örnekle bitti. Bir sonraki derste diyotun devre içindeki çalışma noktası ve diyotlu devrelerde akım ve gerilimlerin belirlenmesiyle ilgili örnekler çözülecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
