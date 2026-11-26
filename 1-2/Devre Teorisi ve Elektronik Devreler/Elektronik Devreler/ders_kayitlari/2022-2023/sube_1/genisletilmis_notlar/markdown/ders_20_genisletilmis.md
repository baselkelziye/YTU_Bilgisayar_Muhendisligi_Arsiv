# Ders 20 Genişletilmiş Notu: Alan Etkili Transistörler (JFET ve MOSFET)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. BJT'den FET'e geçiş
- 2. FET'lerin sınıflandırılması
- 3. JFET'in yapısı ve uçları
- 4. n kanallı JFET'in çalışması
- 5. JFET transfer karakteristiği ve Shockley denklemi
- 6. p kanallı JFET
- 7. JFET sembolleri
- 8. D-MOSFET (kanal ayarlamalı MOSFET)
- 9. MOSFET sembolleri
- 10. E-MOSFET (kanal oluşturmalı MOSFET)
- 11. MOS yapıları ve CMOS
- 12. Özet tablo
- Örnek Sorular
- Dersin Toparlaması

## 1. BJT'den FET'e geçiş

Şimdiye kadar görülen standart transistörler NPN ve PNP yapılı bipolar jonksiyon transistörlerdir (Bipolar Junction Transistor, BJT). Bu derste daha gelişmiş bir teknoloji olan alan etkili transistörlere geçilir: Field Effect Transistor, kısaca FET. Ders, ders slaytları üzerinde kalemle yazılarak anlatılır.

### 1.1 Benzerlikler

BJT ve FET aynı işleri görebilir:

- İkisi de yükseltme (güçlendirme) yapar.
- İkisi de anahtarlama elemanı (switching device) olarak lojik 0-1 geçişlerini gerçekleştirmede kullanılır.
- İkisi de empedans uydurma devresi olarak kullanılır.

### 1.2 Farklar

BJT'de bir $I_B$ baz akımı vardır ve kolektör akımı bu akımın doğrusal bir katıdır:

$$I_C = \beta I_B$$

Yani BJT, akımla kontrol edilen bir elemandır. FET'te ise çıkış akımı, gate ile source arasına uygulanan gerilimle kontrol edilir; FET gerilim kontrollü bir elemandır.

> **Hocanın vurgusu:** BJT ile FET arasındaki aklınızda tutacağınız en önemli fark budur: BJT akım kontrollü, FET gerilim kontrollü bir devre elemanıdır.

Diğer farklar şöyle sıralandı:

- BJT'lerle daha büyük gerilim kazançları oluşturulabilir.
- FET'ler sıcaklık değişimlerine daha az duyarlıdır.
- FET'ler tümleşik devre (integrated circuit, çip) yapımında daha iyi gerçeklenir.
- Dezavantaj olarak FET'ler statik elektriğe BJT'lerden daha duyarlıdır. Yine de sıcaklığa daha az duyarlı oldukları için daha çok tercih edilirler.

FET'lerin bir türü de MOSFET'tir. MOS, metal-oksit-yarı iletken (metal-oxide-semiconductor) yapıyı anlatır; bu yapı FET ile birleşince MOSFET adını alır.

## 2. FET'lerin sınıflandırılması

BJT'ler NPN ve PNP diye iki sınıfa ayrılıyordu. FET'ler ise önce ikiye ayrılır (ekrandan, 00:15:00):

- **JFET:** Junction FET. Türkçesiyle eklem FET.
- **MOSFET:** Metal-Oxide-Semiconductor FET, yani yapısında metal-oksit bir tabakanın da kullanıldığı FET. Kendi içinde ikiye ayrılır:
  - **D-MOSFET:** Depletion MOSFET, Türkçesiyle kanal ayarlamalı MOSFET.
  - **E-MOSFET:** Enhancement MOSFET, Türkçesiyle kanal oluşturmalı MOSFET.

Böylece üç FET yapısı ortaya çıkar (JFET, D-MOSFET, E-MOSFET). Hocanın çiziminde her birinin altına "n/p" yazılmıştır: her yapı n tipi ya da p tipi olabilir, dolayısıyla toplam 6 tip FET vardır.

## 3. JFET'in yapısı ve uçları

### 3.1 Silindir benzetmesi

JFET'i anlamak için bir silindir düşünülür ve bu silindir içini gösterecek biçimde ortadan kesilir. Slayttaki şekil aslında ikiye bölünmüş bir silindirdir. Silindirin ana gövdesi n tipi ya da p tipi bir malzemeden olabilir. Şekildeki örnekte ana gövde n tipidir ve çevresine içeri doğru belli bir miktar nüfuz eden bir kuşak sarılmıştır; bu kuşak p tipidir. Bu yapıya **n kanallı JFET** denir.

Ana gövde p tipi olsaydı kuşak n tipi olurdu ve eleman **p kanallı JFET** diye adlandırılırdı.

### 3.2 Uçlar ve BJT ile karşılaştırma

JFET de BJT gibi üç bacaklı bir elemandır. Hoca uçları BJT'nin uçlarıyla eşleştirdi (ekrandan, 00:20:00):

| JFET ucu | Türkçe anlamı | BJT'deki karşılığı |
|---|---|---|
| Gate (G) | Kapı | Baz (B) |
| Drain (D) | Boşaltma, su gideri | Kolektör (C) |
| Source (S) | Kaynak | Emetör (E) |

Hoca drain için yağmur oluklarındaki su giderini benzetme olarak kullandı. Source elektron kaynağıdır; emetör de "yayıcı" demekti, burada emetörün yerini source alır. Gate ise akışı bir kapı gibi ayarlar.

Slayttaki tanım şöyledir: Drain ve source n kanala bağlıdır, gate p tipi malzemeye bağlıdır (ekrandan, 00:20:00).

## 4. n kanallı JFET'in çalışması

### 4.1 Gate akımı sıfırdır

BJT'de girişteki $I_B$ akımı çıkıştaki $I_C$'yi belirliyor, $I_C$ ile de çıkış gerilimi oluşturuluyordu. JFET'te kontrol $\pm V_{GS}$ gerilimiyle yapılır. Gate çok yüksek bir empedans gösterdiği için içeri akım çekmez; gate akımı sıfır kabul edilir:

$$I_G = 0$$

> **Hocanın vurgusu:** BJT'lerde $I_B$'yi hesaplıyorduk. FET'lerde $I_G$ akımını düşünmenize gerek yok, daima sıfır kabul edilir. Kontrol ettiğimiz parametre $V_{GS}$'dir.

Drain'den source'a akan akımın adı $I_D$'dir ve FET'lerde drain akımı daima source akımına eşittir:

$$I_D = I_S$$

### 4.2 Tüketim bölgesinin rolü

Gate tarafı p tipi, source tarafı n tipi malzemeye değer. Aradaki p-n geçişinde bir tüketim (depletion) bölgesi oluşur. Gate ile source arasına uygulanan gerilimle bu tüketim bölgesi genişletilip daraltılabilir. Tüketim bölgesi genişledikçe kanalın akım geçirebilen kısmı daralır ve $I_D$ akımını engellemeye başlar.

- $V_{GS} = 0$ iken: tüketim bölgesi kanalı kapatmaz, elektronlar kanaldan rahatça geçer ve akım en büyük değerindedir.
- $V_{GS}$ negatif yapıldıkça: tüketim bölgesi büyür, kanal daralır, $I_D$ yavaş yavaş azalır.
- Belli bir negatif gerilimde: iki taraftaki tüketim bölgeleri birbirine kavuşur, kanal kapanır ve drain-source akımı kesilir.

Akım yönü elektron akışının tersi olduğu için n kanallı JFET'te $I_D$ drain'den malzemenin içine girer, $I_S$ source'tan dışarı çıkar.

### 4.3 Kısılma (pinch-off)

Kanalın kapandığı bu gerilime kısılma gerilimi (pinch-off voltage) $V_P$ denir. Hoca "pinch" kelimesini işaret parmağıyla baş parmağın birleştirilmesi, yani tutma ya da çimdikleme hareketiyle açıkladı: tüketim bölgeleri iki parmak ucu gibi ortada birleşir ve akımın geçişini engeller.

n kanallı JFET'te pozitif $V_{GS}$ kullanılmaz; çalışma aralığı $V_P \le V_{GS} \le 0$'dır.

## 5. JFET transfer karakteristiği ve Shockley denklemi

### 5.1 BJT karakteristiğiyle karşılaştırma

BJT'de $I_C$-$V_{CE}$ eğrileri farklı $I_B$ değerleri için çizilir ve aktif bölge bu eğrilerle gösterilirdi. JFET'te çıkış $I_D$ akımıdır ve bu akım $V_{GS}$ ile kontrol edilir; bu yüzden önemli olan $I_D$-$V_{GS}$ eğrisidir (ekrandan, 00:25:00).

### 5.2 Slayttaki örnek eğri

Slaytta yan yana iki grafik vardır (ekrandan, 00:25:00 ve 00:30:00):

- Sağda $I_D$-$V_{DS}$ çıkış eğrileri: $V_{GS} = 0$ V için akım yaklaşık 8 mA'de, $V_{GS} = -1$ V için yaklaşık 4,5 mA'de, $V_{GS} = -2$ V için 2 mA'de, $V_{GS} = -3$ V için 0,5 mA'de sabitlenir; $V_{GS} = -4$ V'ta akım sıfırdır. $V_{DS}$ ekseni 0-25 V arasındadır.
- Solda $I_D$-$V_{GS}$ transfer eğrisi: bu doyma akımları $V_{GS}$ eksenine taşınır. Eğri $V_{GS} = 0$'da $I_{DSS} = 8$ mA'dir ve $V_{GS} = V_P = -4$ V'ta $I_D = 0$ olur. Slaytta "$I_D = 0$ mA, $V_{GS} = V_P$" yazar.

$V_{GS} = 0$ iken akan bu en büyük akım $I_{DSS}$'dir: FET'e gate-source gerilimi uygulanmadan, kanal hiç daralmamışken akan en büyük akım.

> **Ders sonrası not:** Hoca $I_{DSS}$'yi bir yerde "maksimum gerilim" diye andı; $I_{DSS}$ bir akımdır, $V_{GS} = 0$ iken akan en büyük drain akımıdır.

Bu eğri üzerinde, uygulanan $V_{GS}$ gerilimiyle istenen $I_D$ akımı elde edilebilir; dolayısıyla çıkıştaki gerilim de $V_{GS}$ ile ayarlanır.

### 5.3 Shockley denklemi

BJT'de çıkış akımı girişin doğrusal bir katıydı ($\beta$ çarpanı). FET'te $V_{GS}$ ile $I_D$ arasında doğrusal olmayan bir ilişki vardır:

$$I_D = I_{DSS}\left(1 - \frac{V_{GS}}{V_P}\right)^2$$

Burada $I_{DSS}$ (gerilim uygulanmadığında ulaşılabilecek en büyük akım) ve $V_P$ (akımın sıfırlandığı kısılma gerilimi) transistöre özgü sabitlerdir. Değişken giriş $V_{GS}$, çıkış ise $I_D$'dir.

> **Hocanın vurgusu:** Bütün JFET'lerde giriş ile çıkış arasındaki ilişki bu eşitlikle verilir; bunu bilmemiz gerekiyor.

> **Ders sonrası not:** Hoca bu ilişkiyi "eksponansiyel" diye andı; doğrusu ilişkinin karesel (kare yasası) olmasıdır, denklemdeki üs 2'dir.

Slayttaki eğri değerleri denklemle kontrol edildi ($I_{DSS} = 8$ mA, $V_P = -4$ V; python ile doğrulandı):

| $V_{GS}$ (V) | $1 - V_{GS}/V_P$ | $I_D$ (mA) |
|---|---|---|
| 0 | 1 | 8 |
| $-1$ | 0,75 | 4,5 |
| $-2$ | 0,5 | 2 |
| $-3$ | 0,25 | 0,5 |
| $-4$ | 0 | 0 |

## 6. p kanallı JFET

p kanallı JFET'te silindirin ana gövdesi (kanal) p tipi, kuşak n tipidir. Slayttaki tanım: p kanallı JFET, n kanallı JFET gibi davranır; yalnız gerilim polariteleri ve akım yönleri terstir (ekrandan, 00:40:00). Slayttaki devrede $I_G = 0$ A, $V_{GS} = +V_{GG}$ olarak gösterilir.

Etrafında yine tüketim bölgesi oluşur, ama malzemeler yer değiştirdiği için $V_{GS}$ pozitif bölgede çalışır:

- $V_{GS} = 0$'da tüketim bölgesi kanalı kapatmaz, en büyük akım $I_{DSS}$ akar.
- Pozitif gerilim verildikçe tüketim bölgesi büyür, kanaldan geçen taşıyıcı sayısı ve akım azalır.
- Kısılma bu kez pozitif bir $V_{GS}$ değerinde ($V_P > 0$) oluşur.

Karakteristik, n kanallınınkinin aynalanmış hâlidir.

**Soru:** Bu çizimde $I_S$ akımı aşağı doğru mu yukarı doğru mu akar?
**Cevap:** p kanalda akım yönleri değişir. n kanalda $I_D$ drain'den girip source'tan çıkıyordu; p kanalda akım source'tan girip drain'den çıkar, yani $I_D$ drain'den dışarı doğrudur.

$I_D$ ile $V_{DS}$ arasında da farklı karakteristikler çizilebilir, ama bu derste esas alınan $I_D$-$V_{GS}$ ilişkisidir: çıkış (output) $I_D$, kontrol elemanı (input) $V_{GS}$'dir. n kanallı JFET'e kısaca n-JFET, p kanallı JFET'e p-JFET de denir.

## 7. JFET sembolleri

### 7.1 n kanallı JFET sembolü

Slayttaki sembolde drain üstte, source altta, gate soldadır; $I_D$ drain'den aşağı doğru akar, $V_{DS}$ drain (+) ile source (−) arasında, $V_{GS}$ gate (+) ile source (−) arasındadır (ekrandan, 00:35:00).

Semboldeki dikey çubuk kanalı temsil eder. Gate'teki ok malzemenin tipini gösterir: ok her zaman n tipini işaret eder. Gate'teki ok kanala doğru (içeri) bakıyorsa kanal n tipidir, yani eleman n kanallı JFET'tir. Bu, BJT'de emetör okunun malzeme tipini göstermesine benzer: NPN'de emetör oku dışarı bakar, en dıştaki emetör n tipidir, kolektör de emetörle aynı tiptedir (n), ortadaki baz p'dir.

### 7.2 p kanallı JFET sembolü

p kanallı JFET'te kanalın kendisi p tipi, kuşak n tipidir; bu yüzden gate'teki ok dışarı doğru çizilir. Slaytta örnek olarak genel amaçlı p kanallı bir JFET olan 2N2844 gösterilir (TO-18 kılıf): 1 numaralı bacak Source, 2 numaralı bacak Gate, 3 numaralı bacak Drain'dir ve drain kılıfa bağlıdır (ekrandan, 00:45:00).

Alan etkisi şöyle özetlenir: $\pm V_{GS}$ gerilimi ayarlanarak tüketim bölgesindeki elektrik alanı büyütülüp küçültülür ve kanaldan akacak akımın miktarı belirlenir.

## 8. D-MOSFET (kanal ayarlamalı MOSFET)

### 8.1 Yapı

MOSFET'ler farklı bir teknolojidir. D-MOSFET (Depletion-type MOSFET) ve E-MOSFET (Enhancement-type MOSFET) olarak ikiye ayrılır; her biri n ya da p tipi olabilir. Yapı JFET'teki silindirden biraz daha karmaşıktır.

n kanallı D-MOSFET'in slayttaki yapısı şöyledir (ekrandan, 00:50:00):

- Ana yapı (substrate, gövde) p tipidir. Gövdenin ek bir bağlantı ucu olabilir; bu uca Substrate (SS) denir.
- Drain ve source, metal kontaklar üzerinden gövde içindeki iki n katkılı bölgeye bağlanır.
- Bu iki n katkılı bölge, aynı tipte hazır bir n kanalla birbirine bağlanmıştır.
- Gate, bu n kanala ince bir SiO$_2$ (silisyum oksit) yalıtkan katmanla bağlıdır. Yalıtkan, uçların gövdeye doğrudan dokunmasını engeller; bu yüzden gate'ten akım akmaz ($I_G = 0$).

Kanal hazır olduğu için gerilim uygulanmadan da drain'den source'a belli bir akım akabilir. Akımın miktarı kanal genişletilip daraltılarak değiştirilir. Bu yüzden Türkçede bu elemana kanal ayarlamalı MOSFET denir.

### 8.2 Çalışma ve karakteristik

Hoca önce n kanallı JFET'i hatırlattı: orada gate-source arasına yalnız negatif gerilim uygulanıyordu ve $V_{GS} = 0$'dan sonrası kullanılmıyordu; kanal $I_{DSS}$'den daha fazla açılmıyordu.

n kanallı D-MOSFET'te:

- Gerilim uygulanmadığında ($V_{GS} = 0$) hazır kanaldan belli bir akım ($I_{DSS}$) akar. Bu kez bu akım "en büyük" akım değildir.
- $V_{GS}$ negatif yapıldıkça kanal daralır; belli bir negatif gerilimde kanaldan akım geçemez hâle gelir (kısılma, $V_P$).
- $V_{GS}$ pozitif yapıldığında kanal daralmaz, tersine genişler ve $I_{DSS}$'den daha büyük akımlar akar.

Slaytta n kanallı D-MOSFET'in transfer eğrisi $V_P$'den başlayıp $V_{GS} = 0$'da $I_{DSS}$'den geçer ve $V_{GS} > 0$ bölgesinde yükselmeye devam eder (ekrandan, 00:55:00).

### 8.3 Tüketim kipi ve zenginleştirme kipi

D-MOSFET'in eğrisinde iki bölge vardır:

- **Depletion mode (tüketim kipi):** $V_{GS} \le 0$ bölgesi; kanal yalnız daraltılır ya da olduğu gibi bırakılır.
- **Enhancement mode (zenginleştirme kipi):** $V_{GS} > 0$ bölgesi; kanal ek olarak genişler.

> **Hocanın vurgusu:** Bu "mode" adları, MOSFET türleri olan "D-type" ve "E-type" ile aynı kelimelerden gelir ama farklı kavramlardır. D-type MOSFET'in (kanal ayarlamalı) eğrisinin içindeki bölgelere "depletion mode" ve "enhancement mode" denir; E-type MOSFET ise kanal oluşturmalı MOSFET'tir.

**Soru:** Enhancement ne demektir?
**Cevap:** Bir öğrenci "iyileştirmek, arttırmak, geliştirmek" dedi. Hoca zenginleştirmek, arttırmak anlamında olduğunu söyledi; bu bölgede kanal arttırılır.

D-MOSFET'in denklemi JFET ile aynıdır:

$$I_D = I_{DSS}\left(1 - \frac{V_{GS}}{V_P}\right)^2$$

Fark, eğrinin $V_{GS}$'nin diğer polaritesine de uzayabilmesidir. Hocanın özeti: "n kanal JFET çizin" denince eğri $V_{GS} = 0$'da biter; "n kanal ayarlamalı" denince bu sınırın ötesine geçilip akımın daha da arttırılabildiği düşünülmelidir.

### 8.4 p kanallı D-MOSFET

p kanallı D-MOSFET'te kanal p tipi, gövde n tipidir (ekrandan, 01:00:00). Karakteristik p-JFET'in aynısıdır, ek olarak eğri negatif $V_{GS}$ bölgesine de uzanır: negatif gerilimde p kanal genişler ve akım artmaya devam eder. Slayttaki örnek değerler $I_{DSS} = 6$ mA ve $V_P = +6$ V'tur; çıkış eğrileri $V_{GS} = -1$ V'tan $+6$ V'a kadar çizilmiştir.

Bu değerler Shockley denklemiyle kontrol edildi (python ile): $V_{GS} = -1$ V için $I_D = 6(1 + 1/6)^2 \approx 8{,}17$ mA, $V_{GS} = 3$ V için $1{,}5$ mA, $V_{GS} = 6$ V için $0$. Bunlar slayttaki eğri noktalarıyla uyumludur.

## 9. MOSFET sembolleri

D-MOSFET sembolünde gate, kanaldan bir boşlukla ayrı çizilir. Bu boşluk SiO$_2$ yalıtım tabakasını, yani gate'in kanala değmediğini temsil eder. Asıl kanal drain ile source arasındaki dikey çizgidir (ekrandan, 01:05:00).

Gövde (substrate) ucundaki ok kanal tipini gösterir:

- Ok kanala doğru (içeri) bakıyorsa kanal n tipidir: n kanallı MOSFET.
- Ok dışarı bakıyorsa gövde n tipi, kanal p tipidir: p kanallı MOSFET.

İki tür gösterim vardır: gövde ayrı bir uç (SS) olarak çizilebilir ya da source ile birleştirilerek çizilebilir. Daha çok gövdenin source'a bağlandığı gösterim kullanılır. En dikkat edilecek nokta kanalı işaret eden okun yönüdür.

Özetle FET ağacı JFET ve MOSFET, MOSFET'in altında da D-MOSFET ve E-MOSFET şeklindedir. JFET ile D-MOSFET'in karakteristiği birbirine çok benzer; D-MOSFET'te yalnız eğrinin diğer tarafa geçebilmesi farkı vardır. E-MOSFET ise bunlara hiç benzemez.

## 10. E-MOSFET (kanal oluşturmalı MOSFET)

### 10.1 Kanalın oluşturulması

E-MOSFET'te gerilim uygulanmadığında drain ile source arasında kanal yoktur. Kanal, uygulanan $V_{GS}$ gerilimiyle oluşturulur; bu yüzden E-MOSFET'e Türkçede kanal oluşturmalı MOSFET denir.

**Soru:** Gövde p tipi ise orada n tipi bir kanal oluşturmak için $V_{GS}$ ne olmalıdır?
**Cevap:** Gate'e pozitif bir gerilim uygulanırsa n tipi taşıyıcılar (elektronlar) gate'in altında yoğunlaşmaya başlar ve n tipi bir kanal oluşur.

n kanallı E-MOSFET'in çalışması şöyledir:

- $V_{GS}$ belli bir değere gelene kadar akım sıfırdır.
- $V_{GS}$ eşik (threshold) gerilimi $V_T$'yi geçince kanal en dipten, ince olarak oluşmaya başlar ve akım akmaya başlar.
- $V_{GS}$ arttırıldıkça kanal büyür ve $I_D$ artar.

Gövde n tipi olsaydı ve p tipi bir kanal oluşturulmak istenseydi bu kez negatif bir gerilim uygulanırdı; p kanallı E-MOSFET'in eğrisi negatif $V_{GS}$ bölgesindedir.

### 10.2 Slayttaki karakteristik

Slayttaki "Basic Operation of the E-Type MOSFET" başlıklı sayfada şunlar yazar (ekrandan, 01:10:00):

- Enhancement tipi MOSFET yalnız zenginleştirme kipinde çalışır.
- $V_{GS}$ daima pozitiftir.
- $V_{GS}$ arttıkça $I_D$ artar.
- $V_{GS}$ sabit tutulup $V_{DS}$ arttırıldığında $I_D$ doyuma ulaşır ve doyma seviyesi $V_{DSsat}$'a erişilir.

Slayttaki transfer eğrisinde $V_T = 2$ V'tur; $I_D$ eksenindeki noktalar yaklaşık olarak $V_{GS} = 4, 5, 6, 7, 8$ V için $1;\ 2{,}5;\ 4{,}5;\ 7;\ 10$ mA'dir.

### 10.3 Denklem

D-MOSFET'in denklemi JFET ile aynıyken E-MOSFET'in denklemi farklıdır:

$$I_D = k\,(V_{GS} - V_T)^2$$

$V_T$ ve $k$ transistöre özgü sabitlerdir, değişken $V_{GS}$'dir. Akım, $V_{GS}$ ile eşik gerilimi arasındaki farkın karesiyle orantılıdır.

> **Ek bilgi (derste anlatılmadı):** Slayttaki noktalar büyük olasılıkla $k \approx 0{,}28$ mA/V$^2$ ile çizilmiştir: $V_{GS} = 8$ V'ta $k(8-2)^2 = 10$ mA alınırsa $k = 10/36 \approx 0{,}278$ mA/V$^2$ çıkar ve bu $k$ ile 4, 5, 6, 7 V için 1,11; 2,5; 4,44; 6,94 mA bulunur (python ile hesaplandı). Derste $k$ için sayısal değer verilmedi.

### 10.4 Sembol

E-MOSFET sembolünde de gate yalıtkanla ayrı çizilir. Farkı, drain ile source arasındaki kanalın kesikli çizilmesidir: aradaki boşluklar kanalın henüz oluşmadığını gösterir. Uygulanan $V_{GS}$ ile kanal tamamlanır. D-MOSFET'te kanal hazır olduğu için düz çizgiyle çizilir, yalnız genişliği $V_{GS}$ ile ayarlanır.

## 11. MOS yapıları ve CMOS

MOS yapıları elektronik etkilere karşı çok hassas yapılardır ve sürekli geliştirilmektedir (D-MOS, CMOS gibi). Elektronik cihazların yapımında BJT'nin yanında giderek daha çok kullanılırlar; daha karmaşık, sıcaklık değişimlerine daha dayanıklı ve daha kararlı devreler bunlarla yapılır.

CMOS yapısının sağladıkları şöyle sıralandı:

- Daha kararlı çalışma.
- Lojik devre tasarımında daha yüksek giriş empedansı.
- Daha hızlı 1-0 geçişleri.
- Daha düşük çalışma gerilimi.

## 12. Özet tablo

Slayttaki özet tablo n tipi elemanlar için verilmiştir (ekrandan, 01:15:00). p tipleri için karakteristikler aynalanarak çizilir.

| Eleman | Ortak bağıntı | Parametreler | Denklem | Eğrinin biçimi |
|---|---|---|---|---|
| n kanallı JFET | $I_G = 0$, $I_D = I_S$ | $I_{DSS}$, $V_P$ | $I_D = I_{DSS}(1 - V_{GS}/V_P)^2$ | $V_P$'den başlar, $V_{GS}=0$'da $I_{DSS}$'de biter |
| n kanallı D-MOSFET | $I_G = 0$, $I_D = I_S$ | $I_{DSS}$, $V_P$ | $I_D = I_{DSS}(1 - V_{GS}/V_P)^2$ | $V_P$'den başlar, $V_{GS}>0$'da $I_{DSS}$'yi aşar |
| n kanallı E-MOSFET | $I_G = 0$, $I_D = I_S$ | $V_T$ ($V_{GS(Th)}$), $I_{D(on)}$, $V_{GS(on)}$ | $I_D = k(V_{GS} - V_{GS(Th)})^2$ | $V_{GS(Th)}$'ye kadar sıfır, sonra artar |

E-MOSFET için tablodaki $k$ bağıntısı:

$$k = \frac{I_{D(on)}}{\left(V_{GS(on)} - V_{GS(Th)}\right)^2}$$

JFET eğrisinde iki pratik nokta işaretlidir: $V_{GS} = V_P/2$ iken $I_D = I_{DSS}/4$ ve $V_{GS} = 0{,}3V_P$ iken $I_D = I_{DSS}/2$. Bunlar denklemden çıkar: $(1 - 0{,}5)^2 = 0{,}25$ ve $(1 - 0{,}3)^2 = 0{,}49 \approx 0{,}5$.

D-MOSFET eğrisinde $V_{GS} = 0$'ın sağında bir $V'_{GS}$ değeri ve buna karşılık gelen, $I_{DSS}$'den büyük bir $I'_D$ akımı işaretlidir.

> **Hocanın vurgusu:** n-JFET, n kanal ayarlamalı ve n kanal oluşturmalı MOSFET'in karakteristiklerini ve ne tarafa yöneldiklerini bilmeniz lazım. n kanal JFET ile D-MOSFET birbirine çok benzer ve negatif bölgeden başlayıp sağa doğru gider; n kanal oluşturmalı da sağa gider ama pozitif bölgeden başlar. Yalnız n tipi karakteristikleri bilmek, p tiplerinin nasıl olacağını da söyler. Sondaki özeti bilmek dersin tamamını anlamaya yeter.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:39:28): p kanallı JFET çiziminde $I_S$ akımı aşağı yönlü mü, yukarı yönlü mü akar?

> **Çözüm:** p kanallı JFET'te gerilim polariteleri ve akım yönleri n kanallınınkinin tersidir. n kanalda akım drain'den girip source'tan çıkıyordu; p kanalda akım source'tan girer ve drain'den çıkar. Yani $I_S$ source'a doğru (içeri), $I_D$ drain'den dışarı doğrudur.

**Soru 2** (derste sözlü, 00:58:21): Enhancement kelimesi ne anlama gelir ve D-MOSFET'in eğrisinde neden bu ad kullanılır?

> **Çözüm:** Enhancement zenginleştirmek, arttırmak demektir. D-MOSFET'te $V_{GS}$ pozitif yapıldığında (n kanal için) hazır kanal genişler ve akım $I_{DSS}$'nin üstüne çıkar; kanal "arttırıldığı" için bu bölgeye enhancement mode denir.

**Soru 3** (derste sözlü, 01:07:29): p tipi gövdeli bir E-MOSFET'te n tipi bir kanal oluşturmak için $V_{GS}$ nasıl olmalıdır?

> **Çözüm:** Pozitif olmalıdır. Pozitif gate gerilimi elektronları yalıtkanın altına çeker; $V_{GS}$ eşik gerilimi $V_T$'yi geçince n kanal oluşur ve $I_D = k(V_{GS} - V_T)^2$ ile akım akmaya başlar. Gövde n tipi olup p kanal oluşturulacaksa $V_{GS}$ negatif olmalıdır.

## Dersin Toparlaması

Bu derste bipolar transistörlerden alan etkili transistörlere geçildi. FET'in BJT'den temel farkı gerilim kontrollü olmasıdır: gate akımı sıfırdır, çıkış akımı $I_D$ gate-source gerilimi $V_{GS}$ ile denetlenir ve ilişki karesel bir denklemle verilir. JFET'te p-n eklemindeki tüketim bölgesi $V_{GS}$ ile genişletilip kanal daraltılır; $V_{GS}=0$'da $I_{DSS}$, $V_{GS}=V_P$'de sıfır akım elde edilir. D-MOSFET'te yalıtılmış gate ve hazır bir kanal vardır; denklemi JFET ile aynıdır ama eğri zenginleştirme bölgesine de uzanır. E-MOSFET'te kanal başlangıçta yoktur ve eşik gerilimini aşan $V_{GS}$ ile oluşturulur; denklemi $I_D = k(V_{GS} - V_T)^2$'dir. p tipi elemanların karakteristikleri n tiplerinin aynalanmış hâlidir.

Sonraki derste bu elemanlarla kurulan yapıların gösterilmesi ve soru çözümüne başlanması planlandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
