# Ders 7 Genişletilmiş Notu: Oyunlar: Minimax, Alfa-Beta Budaması, Expectiminimax ve Monte Carlo Ağaç Araması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı: Bilgisayar Oyunu Nasıl Oynar?
- 2. Oyun Türleri
- 3. Oyun Ağacı
- 4. Minimax Algoritması
- 5. Satrançta Tam Ağacın İmkânsızlığı
- 6. Sınırlı Derinlikte Arama ve Değerlendirme Fonksiyonu
- 7. XOX'u Sınırlı Derinlikte Oynamak
- 8. Ufuk Etkisi (Horizon Effect)
- 9. Sınırlı Derinlik Satrançta Yeterli mi?
- 10. Alfa-Beta Budaması
- 11. Satranç Programlarındaki Seviyeler
- 12. Rastgele Olmayan Oyun Uygulamaları ve Tarihçe
- 13. Şans İçeren Oyunlar: Expectiminimax
- 14. Tahmin ve Öğrenme
- 15. Değerlendirme Fonksiyonunu Öğrenmek
- 16. Kendi Kendine Oynamak ve Monte Carlo Ağaç Araması
- 17. Deep Blue Tartışması ve Makinelerin Sınırları
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Amacı: Bilgisayar Oyunu Nasıl Oynar?

Bu dersin konusu oyunlardır, ama bilgisayar oyunlarının grafik ya da oyun dinamiği açısından nasıl yapıldığı değil. İnsanların oynaması için oyun tasarlamak amaçlanmıyor. Amaç, bilgisayarın bir oyunu nasıl oynadığını, arkada hangi algoritmaların çalıştığını görmektir.

Hoca derse, bilgisayara karşı satranç oynayan var mı diye sorarak başladı. Bir öğrenci Stockfish'in çevrimiçi sürümünde 22 seviye olduğunu, düşük seviyelerde bazen kazanabildiğini, seviye yükseldikçe hiç şansı olmadığını anlattı. Başka bir öğrenci de en kolay seviyeyi ancak bazen yenebildiğini söyledi. Hoca bunun şaşılacak bir şey olmadığını, klasik satrançta bilgisayarların insanlardan açıkça üstün olduğunu belirtti. Dersin sonunda iki soru cevaplanacaktı: Bu programlar arkada nasıl çalışıyor ve aynı program hem acemi hem profesyonel seviyede oynamayı nasıl başarıyor? Seviyeler neye göre belirleniyor?

## 2. Oyun Türleri

Oyunlar iki ölçüte göre sınıflanır (ekrandan, 00:10:00):

- **Şans:** Oyunda şans faktörü var mı? Şans içermeyen oyunlar deterministiktir.
- **Bilgi:** Oyuncular oyundaki bütün bilgiye sahip mi? Sahipse *perfect information*, değilse *imperfect information* (eksik bilgi) vardır. Slayttaki tanım: eksik bilgi, örneğin karşı tarafın elindekini bilmemektir.

Slayttaki tablo şöyledir:

| | Deterministik | Şans |
|---|---|---|
| Perfect information | satranç, dama, go, othello | tavla, monopoly |
| Imperfect information | (boş) | bridge, poker, scrabble, nuclear war |

Satranç ya da damada iki taraf da her an kendi taşlarının ve rakibin taşlarının nerede olduğunu bilir; oyun hakkında bilinmeyen hiçbir şey yoktur. Tavla ve monopoly'de de bütün bilgi açıktır, ama zar şans faktörü getirir. Poker, okey ya da 51 gibi kâğıt ve taş oyunlarında ise bütün bilgi kimsenin elinde değildir. Oyuncu kendi kâğıtlarını ya da ıstakasındaki taşları ve yere atılmış taşları bilir, ama rakiplerin elindekileri ve kapalı taşları bilmez.

Hoca bu ayrımın, dersin başlarında etmenler konusunda görülen ortam türlerine denk geldiğini hatırlattı: tam gözlenebilir (fully observable) ortam perfect information'a, kısmen gözlenebilir (partially observable) ortam imperfect information'a karşılık gelir.

## 3. Oyun Ağacı

Oyunlar bir oyun ağacı (game tree) üzerinde düşünülür ve oynanır. Bir oyunda iki oyuncu olmak zorunda değildir. Daha fazla oyuncu olabilir, ya da tek kişilik oyunlar olabilir. Bu derste birbirine karşı oynayan, birbirini yenmeye çalışan iki oyunculu oyunlar ele alınır; oyunların büyük kısmı bu biçimde düşünülebilir.

### 3.1 XOX (Tic-Tac-Toe) örneği

Örnek olarak XOX (tic-tac-toe) kullanıldı. Bir taraf yalnız X, diğeri yalnız O koyar. Kazanmak için bir satırda, sütunda ya da köşegende üç işaret oluşturmak gerekir. Oyun daha büyük tahtalarda da oynanabilir, ama burada 3x3 tahta düşünülür.

Slayttaki ağaçta (ekrandan, 00:15:00) kökte boş tahta vardır ve sıra MAX (X) oyuncusundadır. Biz X'iz, yani bilgisayar olduğumuzu düşünüyoruz:

- İlk seviyede X'in 9 olası hamlesi vardır.
- X bunlardan birini yaparsa rakibin (MIN, O) 8 olası hamlesi kalır.
- O da birini yaparsa X'in 7 olası hamlesi kalır, ve ağaç bu şekilde ilerler.

**Soru:** Bu ağacın en büyük derinliği kaçtır? **Cevap:** Bir öğrenci 9 dedi. Hoca doğruladı: her hamlede bir kareye bir işaret konur, işaret konabilecek yer sayısı da 9'dur. Bu yüzden oyun 9 adımdan uzun sürmez, mutlaka biter.

**Soru:** Oyun 9 adımdan önce bitebilir mi? **Cevap:** Bitebilir. Oyunun bittiği düğümlere **terminal düğüm** denir.

**Soru:** Bütün terminal düğümler aynı seviyede midir? **Cevap:** Hayır. Slaytta aynı satırda çizilmiş olsalar da bazıları daha erken bir seviyede, bazıları en alttadır. Büyük olasılıkla çoğu en son seviyededir.

Terminal düğümlerin altındaki sayılar, o durumun bilgisayar (X) açısından sonucudur: **utility (fayda) değeri**. Slayttaki tanım: kazanırsa $+1$, kaybederse $-1$, beraberlikte $0$. Slayttaki üç terminal tahtanın utility değerleri soldan sağa $-1$, $0$, $+1$'dir. Böyle bir oyun ağacı kurulabilir; sıradaki adım, bu ağaç üzerinde bir algoritma çalıştırmaktır.

## 4. Minimax Algoritması

Algoritmanın adı **minimax**tır. 1950'lerde tasarlanmıştır. Slayttaki özellikleri (ekrandan, 00:20:00):

- Rastgele olmayan oyunlar için idealdir.
- Yaklaşım: **en yüksek minimax değerini sağlayan hamleyi yap.**

### 4.1 Küçük bir örnek ağaç

Algoritmayı anlatmak için çok küçük bir oyun ağacı kullanıldı (ekrandan, 00:20:00). Kökte biz (MAX) varız ve üç hamlemiz var: $A_1$, $A_2$, $A_3$. Her hamlemizden sonra rakibin (MIN) üç cevabı vardır ($A_{11}, A_{12}, A_{13}$; $A_{21}, A_{22}, A_{23}$; $A_{31}, A_{32}, A_{33}$). En alttaki terminal düğümlerde bizim kazanacağımız (rakibin kaybedeceği) puan ya da para yazar:

| Bizim hamlemiz | Rakibin cevapları | Yaprak değerleri |
|---|---|---|
| $A_1$ | $A_{11}, A_{12}, A_{13}$ | 3, 12, 8 |
| $A_2$ | $A_{21}, A_{22}, A_{23}$ | 2, 4, 6 |
| $A_3$ | $A_{31}, A_{32}, A_{33}$ | 14, 5, 2 |

Hoca, ara seviyedeki değerleri (3, 2, 2) görmezden gelip yalnız yapraklara bakarak hangi hamlenin seçileceğini sordu.

**Soru:** $A_1$, $A_2$ ve $A_3$'ten hangisini yaparsınız? **Cevap:** Bir öğrenci $A_3$'ü seçeceğini, çünkü $A_{31}$'in en yüksek puana (14) götürdüğünü söyledi. Hoca, öğrenci $A_3$'ü yaparsa rakibin hangi cevabı vereceğini sordu. Öğrenci rakibin onun en az puan almasını sağlayacak hamleyi yapacağını, sonuçta kendisinin 2 puan alacağını söyledi. Hoca bunu doğruladı.

Buradaki ders şudur: rakip bizim az puan almamızı sağlamaya çalışır. Biz 14'ü görüp o hamleyi yaparız, ama rakip de 14'ü görür ve bizi daha kötü bir yere götüren cevabı seçer. Bu yüzden:

- Rakibin hamle seviyesinde (MIN) çocukların **en küçüğü** alınır.
- Bizim hamle seviyemizde (MAX) çocukların **en büyüğü** alınır.

Bu işlem minimax değerlerini üretir:

- $A_1$ düğümü: $\min(3, 12, 8) = 3$
- $A_2$ düğümü: $\min(2, 4, 6) = 2$
- $A_3$ düğümü: $\min(14, 5, 2) = 2$
- Kök: $\max(3, 2, 2) = 3$

Yapraklardaki sayılar terminallerin kendi utility değerleridir; 3, 2, 2 ve kökteki 3 ise minimax değerleridir. En yüksek minimax değerini sağlayan hamle $A_1$'dir. $A_1$ seçilirse rakip ne yaparsa yapsın en az 3 puan kazanılır; diğer hamlelerde rakip bizi 2'ye indirebilir. Minimax, rakibin rastgele oynamadığı, onun da kazanmak için oynadığı oyunlarda ideal bir algoritmadır.

### 4.2 Minimax'ın bileşenleri ve tanımı

Slayttaki bileşenler:

- **MAX:** Bizim olası hamlelerimizden bizim açımızdan en iyi sonucu verenin seçilmesi.
- **MIN:** Rakibin olası hamlelerinden kendi açısından en iyi, bizim açımızdan en kötü sonucu verenin seçilmesi.
- **UTILITY:** Oyunun sonucunu gösteren değer (kazanırsak $+1$, beraberlikte $0$, kaybedersek $-1$).

Minimax değeri özyinelemeli olarak tanımlanır:

$$
\text{MinimaxValue}(n) =
\begin{cases}
\text{Utility}(n) & n \text{ oyun sonu (terminal) ise} \\
\max_{s \in \text{ardıllar}(n)} \text{MinimaxValue}(s) & n \text{ MAX düğümü ise} \\
\min_{s \in \text{ardıllar}(n)} \text{MinimaxValue}(s) & n \text{ MIN düğümü ise}
\end{cases}
$$

Algoritmanın yapısı derinlemesine arama tarzındadır. Optimallik açısından minimax, kendisi için her zaman en iyisini yapan bir rakibe karşı optimaldir. Rakip rastgele oynuyorsa ya da rakibin nasıl bir motivasyonla oynadığı bilinmiyorsa optimallikten söz etmek zaten zordur.

## 5. Satrançta Tam Ağacın İmkânsızlığı

Minimax ve oyun ağacı elimizde. Hoca aynı yöntemi satranca uygulamayı düşündü. Slayttaki değerler (ekrandan, 00:25:00):

- Her adımda yapılabilecek farklı hamle sayısının ortalaması (dallanma): 32
- Bir oyunun ortalama hamle sayısı (derinlik): 40
- Arama uzayı: $32^{40} = 2^{200} \approx 10^{60}$ düğüm

Saniyede 3 milyar durum işlendiği varsayılsın:

- Bir yıldaki saniye sayısı: $\approx 32 \cdot 10^6$
- Bir yılda işlenen durum sayısı: $3 \cdot 10^9 \cdot 32 \cdot 10^6 \approx 10^{17}$
- Tüm durumların değerlendirilmesi: $10^{60} / 10^{17} = 10^{43}$ yıl
- Evrenin yaşı: $\approx 10^{10}$ yıl

Yani işlem evrenin başlangıcından bugüne kadar sürse bile bitmezdi. Hoca, hızı bin ya da milyon katına çıkarmanın da pek bir şey değiştirmediğini vurguladı: $10^{43}$ yıl ancak $10^{40}$ ya da $10^{37}$ yıla iner. Süper bilgisayarlar kullanılsa bile satrancın tam minimax ağacı üzerinde değer hesaplamak mümkün görünmüyor; burada bellekten söz edilmiyor bile. Ama bilgisayarlar satrancı oynuyor, hem de çok iyi ve çok beklemeden. O hâlde arkada başka bir şey oluyor olmalı. Slayttaki iki cevap (ekrandan, 00:30:00):

- Sınırlı derinlikte arama ve değerlendirme fonksiyonu (cutoff test, evaluation function)
- Alfa-beta budaması

> **Ek bilgi (derste anlatılmadı):** Slayttaki $32^{40} = 2^{200}$ eşitliği tamdır, çünkü $32 = 2^5$'tir. $2^{200}$ yaklaşık $1.6 \cdot 10^{60}$ eder. Bir yıldaki gerçek saniye sayısı yaklaşık $3.15 \cdot 10^7$'dir; slayttaki $32 \cdot 10^6$ bunun yuvarlanmış hâlidir.

## 6. Sınırlı Derinlikte Arama ve Değerlendirme Fonksiyonu

### 6.1 Fikir

Ağacın tamamını, yani utility değerlerine (oyun sonuna) ulaşana kadar üretmek yerine, bulunduğumuz noktadan belli bir **sınır derinliğine** kadar ağaç üretilir. Örneğin derinlik 5 seçilirse: benim olası hamlelerim, onlara karşı rakibin olası hamleleri, ve beş adım böyle ilerlenir. Ağacı kurmak kolaydır.

Ama burada minimax olduğu gibi çalıştırılamaz, çünkü minimax utility değerlerine ihtiyaç duyar. Utility değeri oyun sonlarına, yani terminal düğümlere dairdir: kazandık mı, kaybettik mi, kaç puan ya da kaç lira kazandık. Bulunduğumuz noktadan 5 hamle sonra oyunun bitmiş olma olasılığı ise çok düşüktür. Oyunun çok ilerlemiş aşamalarında olabilir, ama başında ve ortasında olmaz. Bu yüzden utility yerine bir **değerlendirme fonksiyonu** kullanılır.

### 6.2 Değerlendirme fonksiyonu neyi ifade eder?

Hoca, değerlendirme fonksiyonunun algoritmaya neyi söylemesi gerektiğini sordu ve öğrencilerin cevaplarını tartıştı.

**Soru:** Değerlendirme fonksiyonu neyi ifade eder? **Cevap:** Öğrencilerden "kazanca giden yola ne kadar yakın olduğumuz", "satrançta taşlara verilen değerler", "o tahtanın en iyi konumu", "tehdit eden şeyler", "taş ya da konum üstünlüğü", "skoru" gibi cevaplar geldi. Hoca burada bir yol olmadığını, tahtanın bir "konumu" değil bir değeri olduğunu söyledi. Taş değerleri bir değerlendirme fonksiyonunun içeriği olabilir, ama soru fonksiyonun ne söylemesi gerektiğiydi. Hocanın cevabı: değerlendirme fonksiyonu **o tahtanın bizim açımızdan iyiliğini** söylemelidir.

Utility değeri elimizde yoktur (kazanırsam 1, kaybedersem $-1$). Onun yerine utility'yi sezgisel olarak tahmin eden bir fonksiyon yazılır: "bu durumdan gidersen bu oyunu kazanırsın" ya da "kaybedersin" bilgisini veren sayısal bir değer. Değerlendirme fonksiyonu oyun sonu olmadığı hâlde herhangi bir tahtanın bizim açımızdan iyiliğini ya da kötülüğünü tahmin eder. Gerçeği bilemez, çünkü oyunun sonuna ulaşılmamıştır ve daha bir sürü hamle vardır. Bu yüzden önceki derslerdeki sezgisel fonksiyonlara benzer.

### 6.3 Satranç için taş değerlerine dayalı fonksiyon

En basit satranç değerlendirme fonksiyonu taş değerlerine dayanır (ekrandan, slayt küçük resmi, 00:40:00):

- Taş değerleri: piyon 1, at 3, fil 3, kale 5, vezir 9.
- Şahın değeri yoktur, çünkü iki tarafta da her zaman birer şah vardır; hesaba katmaya gerek yoktur.

Slayttaki örnek tahtada:

- Siyahlar: 5 piyon, 1 fil, 2 kale. Skor $= 1 \cdot 5 + 3 \cdot 1 + 5 \cdot 2 = 5 + 3 + 10 = 18$.
- Beyazlar: 5 piyon, 1 kale. Skor $= 1 \cdot 5 + 5 \cdot 1 = 5 + 5 = 10$.
- Değerlendirme: siyahlar için $18 - 10 = 8$, beyazlar için $10 - 18 = -8$.

Yani bu tahta siyah oyuncu için daha iyidir.

> **Ders sonrası not:** Hoca beyazlar için değeri söylerken "10-18'den 8" dedi; doğrusu slaytta da yazdığı gibi $10 - 18 = -8$'dir.

**Soru:** Bu değerlendirme fonksiyonu neye dikkat etmiyor? **Cevap:** Taşların konumlarına. Fonksiyon yalnız taş değerlerine bakar, konum bilgisini hiç kullanmaz.

### 6.4 Ağırlıklı doğrusal değerlendirme fonksiyonu

Gerçek satranç programlarında tek bir değerlendirme fonksiyonu kullanılmaz; birçok fonksiyon birlikte kullanılır. Slayttaki biçim (ekrandan, slayt küçük resmi, 00:40:00):

$$Eval(s) = w_1 f_1(s) + w_2 f_2(s) + \dots + w_n f_n(s)$$

Slayttaki örnek: $w_1 = 9$ ve $f_1(s)$ = (beyaz vezir sayısı) $-$ (siyah vezir sayısı). Hoca $f$'lere örnek olarak taş değerlerinden çıkan sonucu, vezir sayıları arasındaki farkı, kaç hamle yapılabildiğini, tahtanın ortasının kontrolünü ve şahın korumalarını saydı. Tahta $s$ bütün bu fonksiyonlara gönderilir, her birinden bir değer gelir ve ağırlıklı toplamları tahtanın değerlendirme değerini verir. $n$ genelde bir iki değil, daha büyüktür.

Asıl iş $f$'leri ve $w$'leri belirlemektir. Slayttaki sorular (ekrandan, 00:35:00):

- Etrafı boş olan piyonlar kötüdür.
- Şahın korumaları var mı?
- Hareket kabiliyetin nasıl?
- Tahtanın ortasının kontrolü sende mi?
- Oyun süresince $w$'lerin değerleri değişir mi?

$w$, bir değerlendirme bileşeninin önemini gösterir. Oyunun başında bazı fonksiyonlar daha önemliyken oyunun sonlarına doğru başkaları daha önemli hâle gelebilir. Bu yüzden $w$'lerin oyun süresince değiştiği dinamik yapılar kurmak da mümkündür. $w$'lerin nasıl belirleneceği dersin ilerleyen kısmında ele alındı (bölüm 15).

> **Ek bilgi (derste anlatılmadı):** Slayttaki ağırlıklı toplamın bir varsayımı vardır: bileşenlerin birbirinden bağımsız katkı yaptığı kabul edilir. Örneğin bir filin değeri oyunun evresine ya da diğer taşlara göre değişebilir; doğrusal toplam bu etkileşimi doğrudan ifade edemez.

### 6.5 XOX için değerlendirme fonksiyonu

Çok basit bir oyun olan XOX için değerlendirme fonksiyonu şöyle tanımlanır (ekrandan, slayt küçük resmi, 00:40:00):

$$e(n) = M(n) - O(n)$$

- $M(n)$: benim olası kazanma çizgilerimin toplam sayısı (total of my possible winning lines), yani hâlâ içinde rakip işareti olmayan satır, sütun ve köşegenler.
- $O(n)$: rakibin olası kazanma çizgilerinin toplam sayısı.

Hoca slayttaki üç tahta için değerleri tek tek saydı (X açısından):

- Birinci tahtada X'in ileride kazanabileceği 6 çizgi, O'nun 5 çizgisi vardır: $e = 6 - 5 = 1$.
- İkinci tahtada ortada O olduğu için ortadan geçen hiçbir çizgi X'e kalmaz. X'in 4 olası çizgisi, O'nun 6 olası çizgisi vardır: $e = 4 - 6 = -2$.
- Üçüncü tahtada $e = 5 - 4 = 1$'dir.

<!-- BELİRSİZ: Üç tahtanın tam yerleşimi slaytın küçük resminde okunamadı; değerler altyazıdan alındı. -->

## 7. XOX'u Sınırlı Derinlikte Oynamak

### 7.1 İlk hamle (2 derinlikli arama)

Başlangıç durumu boş tahtadır ve derinlik 2 seçilmiştir: ben bir hamle yaparım, sonra rakip bir hamle yapar. Bu iki derinlikli ağaç üretilir, yapraklar için değerlendirme fonksiyonu hesaplanır, sonra minimax ile hamle seçilir (ekrandan, 00:40:00).

Boş tahtada aslında 9 hamle vardır, ama simetrik olanlar aynı değeri alacağı için elenmiştir. Geriye üç farklı hamle kalır: köşeye X, kenarın ortasına X ve merkeze X. Köşe hamlesi aslında 4 farklı durumu, kenar hamlesi de 4 farklı durumu temsil eder. Rakibin cevaplarında da simetrikler elenmiştir. Yaprak değerleri slayttan:

| X'in hamlesi | O'nun cevaplarının değerleri ($M - O$) | MIN değeri |
|---|---|---|
| Köşe | $6-5=1$, $5-5=0$, $6-5=1$, $5-5=0$, $4-5=-1$ | $-1$ |
| Kenar | $5-6=-1$, $5-5=0$, $5-6=-1$, $6-6=0$, $4-6=-2$ | $-2$ |
| Merkez | $5-4=1$, $6-4=2$ | $1$ |

Örneğin köşe hamlesinden sonraki ilk tahtada X'in kazanabileceği 6 yer, O'nun 5 yeri vardır; değer 1'dir. Başka bir tahtada iki tarafın da 5 olasılığı vardır; değer 0'dır.

Alt seviye MIN seviyesidir: rakip bizim açımızdan kötüyü seçer. Bu yüzden her grubun en küçüğü yukarı yazılır: $-1$, $-2$, $1$. Kök MAX olduğu için bunların en büyüğü, yani $1$ seçilir. Bu durumda yapılacak en mantıklı hamle **X'i merkeze koymaktır**.

Tablodaki bütün değerler python ile her tahta için $M(n) - O(n)$ sayılarak doğrulandı.

### 7.2 İkinci hamle

Hamle yapıldı, ama oyun bitmedi. Sıra rakipte. Rakibin O'yu üst kenara koyduğu varsayılsın. Aynı işlem tekrarlanır: bu durumdan gidilebilecek iki derinlikli bütün durumlar üretilir, değerlendirme fonksiyonları hesaplanır, minimax değerleri bulunur ve en büyük değeri veren hamle seçilir.

Simetrikler elendiğinde X'in 4 farklı hamlesi kalır. Her birinden O'nun 6 cevabı çıkar; slaytta sonuncusundan yalnız 3 cevap gösterilmiştir. MIN değerleri sırasıyla $1$, $0$, $1$, $0$'dır. En büyük değer $1$ olduğu için 1 değerli iki hamleden biri seçilir. Aralarında fark olmadığından seçim rastgele yapılabilir.

> **Ders sonrası not:** Bu dört değer, X merkezde ve O üst kenarda iken X'in üst köşe, yan kenar, alt köşe ve alt kenar hamleleri için python ile hesaplandı; MIN değerleri sırasıyla 1, 0, 1, 0 çıktı. Bu, derste söylenen değerlerle aynıdır.

Hamle seçildikten sonra rakip yine bir hamle yapar, iki derinlikli yapı yeniden kurulur, durumlar ve değerlendirme fonksiyonları yeniden hesaplanır, minimax ile hamle seçilir. Oyun bitene kadar bu döngü sürer. Tam oyun ağacının ne bellekte tutulabildiği ne de işlenebildiği durumlarda oyunları oynanabilir kılan yaklaşım budur.

## 8. Ufuk Etkisi (Horizon Effect)

Aradan sonra hoca şu soruyu sordu: Sınırlı derinlikte aramada farklı derinlikler seçilirse kararlar değişir mi? Örneğin XOX'ta 2 yerine 3 ya da 4 derinlik seçilseydi başka bir hamle seçilebilir miydi?

Örnek bir satranç tahtası verildi (ekrandan, 01:00:00). Tahtada siyah şah h8'de, beyaz şah h1'de, iki siyah kale a sütununda (a4 ve a5), a2'de bir siyah piyon, c2 ve d2'de iki beyaz kale vardır. Sıra beyazdadır ve biz beyazız. Soru: **c2'deki beyaz kale a2'deki piyonu alır mı?**

Değerlendirme fonksiyonunun taş değerlerine dayandığı varsayılsın. Bir derinlik, yalnız bizim bir hamle yapmamız ve rakibin cevabını hiç düşünmememiz demektir. Bir hamle sonra oluşabilecek tahtalar değerlendirilir ve bizim açımızdan en iyisine götüren hamle seçilir.

- **1 derinlik:** Kaleyle piyonu almak kazançtır: biz taş kaybetmeyiz, rakip bir piyon kaybeder. **Alır.**
- **2 derinlik:** Rakibin cevabı da hesaba katılır. **Soru:** Piyon alınırsa bir sonraki hamlede büyük olasılıkla ne olur? **Cevap:** Bir öğrenci "kale kaleyi alır" dedi. Siyah kale beyaz kaleyi alır; biz bir kale, rakip bir piyon kaybeder. Bir piyona bir kale değmez. **Almaz.**
- **3 derinlik:** Siyah kale beyaz kaleyi aldıktan sonra d2'deki ikinci beyaz kale o siyah kaleyi alır. Biz bir kale, rakip bir kale ve bir piyon kaybeder. Piyon + kale bir kaleye değer. **Alır.**
- **4 derinlik:** a sütunundaki ikinci siyah kale de bizim kalemizi alır. Biz iki kale, rakip bir kale ve bir piyon kaybeder. Piyon + kale iki kaleye değmez. **Almaz.**

Karar "alır, almaz, alır, almaz" diye değişir. Yani sınırlı derinlikte aramada **derinlik kararı değiştirebilir.** Buna ufuk etkisi denir.

Derinlik nasıl belirlenmeli? Hoca bunun ayrıntısına sonra döneceğini söyledi. İdeal olan, ufuk etkisinin oluşmayacağı, kararın artık değişmediği kadar yüksek bir derinlik seçmektir. Bu, donanım ya da zaman kısıtları yüzünden her zaman mümkün olmaz. Bu örnekte 5, 6, 7 gibi derinliklerde kararın büyük olasılıkla "almaz" olarak sabitleneceği tahmin edilebilir. Başka durumlarda kararlar çok daha yüksek derinliklere kadar değişebilir.

## 9. Sınırlı Derinlik Satrançta Yeterli mi?

Slayttaki hesap (ekrandan, 01:05:00) önce sınırlı derinlikte aramanın tanımını verir: **MinimaxCutoff, MinimaxValue ile aynıdır**, yalnız iki fark vardır:

1. "Terminal?" yerine "Cutoff?" kullanılır.
2. Utility yerine Eval kullanılır.

Sonra yeterlilik sorusu sorulur. Hamle süresi 100 saniye ve donanım saniyede $10^4$ düğüm inceleyebiliyorsa, her hamle için $10^4 \cdot 100 = 10^6$ düğüm incelenebilir. $b$ dallanma, $m$ derinlik olmak üzere:

$$b^m = 10^6, \quad b = 35 \;\Rightarrow\; m = \frac{\ln 10^6}{\ln 35} \approx 3.9 \approx 4$$

Yani bu donanım ve süreyle ancak 4 seviye derine inilebilir. Slayttaki karşılaştırma:

- 4 kat ileri bakış (lookahead) ≈ amatör satranç oyuncusu (insan)
- 8 kat ≈ master seviyesindeki insan
- 12 kat ≈ Deep Blue, Kasparov

4 kat ileri bakan bir program en iyi ihtimalle amatör oyuncuları yenebilir. Hoca, master ve grandmaster seviyesindeki insanların 8 ya da 12 kat ileri bakabildiklerinin söylendiğini, ama insanların bunu kafalarında bütün oyun ağacını kurarak yapmadığını belirtti. İnsanlar büyük olasılıkla zamanla öğrenilen çok iyi sezgisel kurallarla ağacın nerelerine bakmaları gerektiğini, nerelerinin gereksiz olduğunu kestirebiliyorlar. Bilgisayarda ise o anlamda bir sezgi yoktur; bütün olası durumları hesaba katar. Derinliği artırmak için slayttaki çözüm: **sınırlı derinlikte aramaya alfa-beta budaması eklemek.**

## 10. Alfa-Beta Budaması

### 10.1 Tüm durumları değerlendirmek gerekir mi?

Alfa-beta budaması "bütün durumları değerlendirmek gerekir mi?" sorusundan çıkar. Slayttaki örnekte (01:07 civarı) kök MAX, altında iki MIN düğümü ve dört yaprak vardır. İlk MIN düğümünün yaprakları 2 ve 7, ikinci MIN düğümünün ilk yaprağı 1, son yaprağın değeri ise bilinmiyor.

**Soru:** Bilinmeyen yaprağın değeri seçilecek hamleyi değiştirir mi? **Cevap:** İlk MIN düğümünün değeri kesin olarak $\min(2, 7) = 2$'dir. İkinci MIN düğümünde 1 geldiği için o düğümün değeri her zaman $\le 1$ olur, çünkü orada minimum alınır. Bilinmeyen yaprağa 3 yazılsa bile $\min(1, 3) = 1$ olur. Kökte 2 ile 1'den büyük olamayan bir şeyin maksimumu alındığında sonuç her zaman 2'dir. Öğrenciler de "ikidir" dedi. Bilinmeyen yaprak $+100$ de olsa $-100$ de olsa hiçbir şey değişmez (bu özel durumda).

Böyle gereksiz düğümlerin farkına varılabilirse, onları değerlendirmeye harcanacak zaman aynı donanımla daha derine inmek için kullanılabilir.

### 10.2 Alfa ve beta

- $\alpha$: bir durumun alabileceği **en küçük** değer (alt sınır). Örnekte kökün $\alpha$'sı 2'dir, çünkü kök $\ge 2$'dir.
- $\beta$: bir durumun alabileceği **en büyük** değer (üst sınır). Örnekte ikinci MIN düğümünün $\beta$'sı 1'dir.

Alfa ve beta, durumların üzerinde bu alt ve üst sınırları göstermek için kullanılan değişkenlerdir.

### 10.3 Adım adım alfa-beta

Örnek, minimax bölümündeki ağaçla aynı yapraklara sahiptir: 3, 12, 8 / 2, ?, ? / 14, 5, 2 (ekrandan, 01:10:00).

1. Derinlemesine (depth-first) ilk yaprağa kadar inilir. Başta bütün düğümlerin aralığı $[-\infty, +\infty]$'dur; henüz bir sınır yoktur.
2. İlk yaprak 3 gelir. İlk MIN düğümü üç çocuğunun minimumunu alacağı için artık 3'ten büyük olamaz: aralığı $[-\infty, 3]$ olur ($\beta = 3$). Ne kadar küçülebileceği henüz bilinmez. Bu bilgi kök için şimdilik bir şey söylemez.
3. İkinci yaprak 12 gelir. Zaten 3'ten küçük ya da eşit bir değer bekleniyordu; 12 hiçbir şeyi değiştirmez.
4. Üçüncü yaprak 8 gelir. İlk MIN düğümü artık olasılık olmaktan çıkar, gerçek değeri $\min(3, 12, 8) = 3$ olur. Kök artık 3'ten küçük olamaz: aralığı $[3, +\infty]$ olur ($\alpha = 3$).
5. İkinci MIN düğümünün ilk yaprağı 2 gelir. Bu düğüm artık en fazla 2 olabilir: $[-\infty, 2]$. Kök zaten en az 3'tür. Bu düğümün kalan iki yaprağını değerlendirmenin hiçbir anlamı yoktur; **budanır.** Onlara zaman harcanmaz, doğrudan sonraki dala geçilir.
6. Üçüncü MIN düğümünün ilk yaprağı 14 gelir: düğüm $[-\infty, 14]$ olur. Kök için yeni bir bilgi yoktur.
7. Sonraki yaprak 5 gelir: düğüm $[-\infty, 5]$, kök $[3, 5]$ olur.
8. Son yaprak 2 gelir: düğüm $\min(14, 5, 2) = 2$ olur. Kök $\max(3, 2, 2) = 3$ olur ve ilk hamle seçilir.

Toplam 9 yapraktan 7'si değerlendirilmiş, seçilen hamle değişmemiştir. Alfa-beta budaması kararda hiçbir eksiklik yaratmaz: **tamamen aynı karar daha az maliyetle, daha kısa sürede verilir.** Python ile yapılan alfa-beta denemesi de aynı sonucu verdi: kök 3, 7 yaprak değerlendirildi, ikinci MIN düğümünde iki yaprak budandı.

### 10.4 Üst seviyelerden budama

Budama yalnız son seviyede olmaz. Hoca daha derin bir örnek gösterdi (ekrandan, 01:15:00); bu örnekte iki farklı yerden budama yapılmıştır. Daha yukarıdan budama olduğunda o düğümün altındaki her şey birden atılır, dolayısıyla tasarruf çok daha büyük olur. Bu ağaç "Adım adım çözünüz" başlığıyla verildi; çözümü Örnek Sorular bölümündedir.

### 10.5 Kazanç: derinliğin iki katına çıkması

Kazanılan zaman daha derin arama için kullanılır. Örneğin bir donanımla budamasız 4 derinlikli arama ne kadar sürüyorsa, alfa-beta budamasıyla 8 derinlikli arama aşağı yukarı aynı sürede bitebilir. Slayttaki özellik: alfa-beta karmaşıklığı $O(b^{m/2})$'ye kadar düşürebilir; satrançta bu, arama derinliğini iki katına çıkarmak demektir. 4 kat ileri bakıştan 8 kata, yani master seviyesine geçilir.

> **Ek bilgi (derste anlatılmadı):** $O(b^{m/2})$ en iyi durumdur ve çocuklar en iyi hamle önce gelecek şekilde sıralandığında elde edilir. Sıralama kötüyse budama azalır; en kötü durumda alfa-beta, düz minimax kadar düğüm inceler.

## 11. Satranç Programlarındaki Seviyeler

Hoca dersin başındaki soruya döndü: Satranç programlarındaki seviyeler nasıl belirleniyor?

**Soru:** Bir satranç programında acemi ve uzman seviyeler nasıl ayarlanır? **Cevap:** Bir öğrenci "ne kadar derine bakacağına göre" dedi. Hoca doğruladı. Oynayanların fark edebileceği gibi, acemi seviye seçildiğinde program siz hamle yaptıktan sonra çok hızlı cevap verir. Uzman seviye seçildikçe cevap süresi artar. Alfa-beta gibi tekniklerle arama derinliği artırılmaya çalışılır. Bir oyun ne kadar derine bakılarak analiz edilirse o kadar çok olasılık görülür ve karar o kadar doğru olur. Maksimum derinliğe ulaşmak mümkün değildir, ama mümkün olan en yüksek derinlikle en iyi sonuç alınır.

## 12. Rastgele Olmayan Oyun Uygulamaları ve Tarihçe

### 12.1 Dama, satranç, othello ve go

Dama, satranç ve othello gibi rastgele olmayan, perfect information oyunlarda insanlar uzun süredir bilgisayarlara karşı pek başarılı değil: damada 1994'te, satrançta 1997'de üstünlük bilgisayarlara geçti, othello'da daha da önce. Go'da ise insanlar üstünlüklerini ancak 2016'da kaybetti. Hoca, go oyununun *A Beautiful Mind* filminde John Nash'in bir arkadaşına yenildiği sahnede geçtiğini de hatırlattı.

Go'nun bu kadar geç kalmasının sebebi slaytta yazar (ekrandan, 01:20:00): oyun 19x19'luk bir tahtada oynanır; $b \approx 250$, $d \approx 150$'dir.

**Soru:** $b$'nin 250 olması ne demek? **Cevap:** Bir öğrenci her durumda 250 farklı hamle yapılabildiğini söyledi; hoca bir durumdan 250 farklı durum çıktığını ekledi. $d$ ise derinliktir; $d \approx 150$, bir oyunun ortalama 150 hamle sürdüğü anlamına gelir.

$b$ ve $d$ bu kadar büyük olunca standart yaklaşımla birkaç derinliğe bakmak bile $250 \cdot 250 \cdot 250 \cdots$ diye büyür. Slayttaki diğer bilgiler: go'da örüntü tanıma teknikleri daha yaygın kullanılır. Ağustos 2008'de her biri 32 işlemciye sahip 25 sunucuda çalışan MoGo profesyonel bir go oyuncusunu yendi. Mart 2016'da AlphaGo dünya şampiyonunu 4-1 yendi. Hoca ileride bunun değişebileceğini ama pek olası olmadığını, bu başarıda algoritmanın yanında donanımın da büyük etkisi olduğunu söyledi.

> **Ders sonrası not:** Altyazıda go'ya "2018'den beri" büyük yatırım yapıldığı geçiyor; slayttaki MoGo bilgisine göre bu büyük olasılıkla "2008" olmalıdır (söyleyiş ya da altyazı hatası).

### 12.2 Bilgisayarla satranç oynamanın tarihçesi

Slayttaki kronoloji (ekrandan, slayt küçük resmi, 01:25:00):

- 1957: Newell ve Simon, 10 yıl içinde dünya satranç şampiyonunun bir bilgisayar olacağını söyledi. Bu, ilk derslerde konuşulan "büyük beklentiler" dönemidir.
- 1958: Satranç oynayan ilk bilgisayar, IBM 704.
- 1967: Mac Hack programı insanların katıldığı bir turnuvada başarıyla yarıştı.
- 1983: Belle programı Amerika Satranç Federasyonundan master ünvanı aldı.
- 1980'lerin ortaları: Carnegie Mellon Üniversitesindeki bilim insanları sonradan Deep Blue'ya dönüşecek çalışmayı başlattı.
- 1989: Projeyi IBM devraldı.

Hoca, o yıllarda bilgisayar ile programın birbirinden pek ayrılmadığını, yazılımın öneminin sonradan çok büyük ölçüde ortaya çıktığını söyledi.

<!-- BELİRSİZ: Kronolojinin bir kısmı slaytın küçük resminden okundu; 1958 ve 1967 maddelerinin tam ifadesi kesin değildir. -->

11 Mayıs 1997'de Gary Kasparov, 6 oyunluk maçta Deep Blue'ya 3.5-2.5 yenildi: 2 oyunu Deep Blue, 1 oyunu Kasparov kazandı, 3 oyun berabere bitti (ekrandan, 01:25:00). IBM projeyi devraldıktan 8 yıl sonra gelen bu sonuç, tek bir maçla değil, arada yapılan başka maçlarla ve 8 yıllık uğraşla elde edildi. Slayttaki fotoğrafta solda Kasparov, sağda bir ekran ve Deep Blue geliştirme ekibinden olduğu düşünülen biri vardır. Bu kişi Deep Blue'nun hamlelerini tahtaya aktaran bir arayüz gibidir.

### 12.3 Metotların tarihi

Slayttaki tablo (ekrandan, slayt küçük resmi, 01:30:00):

| Program / kişi | Yöntem | Yıl |
|---|---|---|
| Shannon, Turing | Minimax arama | 1950 |
| Kotok / McCarthy | Alfa-beta budama | 1966 |
| MacHack | Dönüşüm tabloları | 1967 |
| Chess 3.0+ | Iterative deepening | 1975 |
| Belle | Özel donanım | 1978 |
| Cray Blitz | Paralel arama | 1983 |
| Hitech | Paralel değerlendirme | 1985 |
| Deep Blue | Yukarıdakilerin hepsi | 1997 |

Iterative deepening, ufuk etkisiyle başa çıkabilmek için daha derine gidebilen yapılardan biri olarak anıldı. Hoca, tablonun belli bir noktasından sonra ilerlemenin algoritmadan değil donanımdan geldiğine dikkat çekti: özel donanım, paralel arama, paralel değerlendirme. Deep Blue'nun başarısı büyük ölçüde donanımdaki ilerlemelere dayanır. İşlemcide aritmetik-mantık birimleri (ALU) olduğu gibi, Deep Blue'nun içinde de yalnız satranç değerlendirme fonksiyonlarını hızlı hesaplamak için tasarlanıp üretilmiş satranç çipleri vardı.

### 12.4 Neden bu kadar yatırım yapıldı?

Milyonlarca dolar ve yıllar süren bu projelere neden bu kadar önem verildi? Hoca iki sebep önerdi:

- **Satrancın yapay zekâ açısından önemi.** Satranç, insanlar arasında zekânın göstergesi sayılır; dünya satranç şampiyonlarının çok zeki insanlar olduğunda herkes hemfikirdir. Bilgisayarların satrançta dünya şampiyonunu yenip yenemeyeceği çok merak edildi; bazıları bunun hiçbir zaman olamayacağını, çünkü tamamen zekâ işi olduğunu düşünüyordu. Ama arkada dönen şey, oyun ağaçlarını kurmak ve onları değerlendirebilmektir. Klasik satrançta insanlar büyük olasılıkla geri dönüşü olmayacak biçimde yenildi.
- **Politika.** Hoca, emin olmadığını belirterek, fotoğraftaki Rus ve Amerikan bayraklarına dikkat çekti. Dünya şampiyonu bir Amerikalı olsaydı bu kadar büyük bir motivasyon olmayabilirdi; Soğuk Savaş döneminin ABD-Rusya rekabetinin burada bir yansıması olabileceğini düşündüğünü söyledi.

## 13. Şans İçeren Oyunlar: Expectiminimax

### 13.1 Şans düğümleri

Şimdiye kadar şans hiç düşünülmedi: biz bir hamle yapıyorduk, rakip bir hamle yapıyordu. Kâğıt çekmek ya da zar atmak gibi şeyler işin içine girmedi. Bilgisayarlar böyle oyunları da oynayabilir; bunun için mevcut yapıya bir ekleme gerekir.

Tavla örneğinde minimax yerine **expectiminimax** algoritması kullanılır. Standart minimax'tan tek farkı, terminal (ya da cutoff), MIN ve MAX düğümlerine ek olarak **şans düğümleri** içermesidir. Şans düğümünde gelebilecek zar, kâğıt gibi sonuçlar olasılıklarıyla dizilir.

Tavlada atılan iki zar için 21 farklı sonuç vardır: 6'sı çift (iki zar aynı), 15'i farklı. Yani her seviyede 21 şans dalı vardır. Benim hamlem ile rakibin hamlesi arasına ve rakibin hamlesi ile benim hamlem arasına, yani her ikili arasına bir şans seviyesi eklenir.

Slayttaki ağaçta (ekrandan, 01:30:00) seviyeler şöyle sıralanır:

1. MAX: benim yapabileceğim olası hamleler
2. CHANCE: karşı tarafın atabileceği zarlar
3. MIN: karşı tarafın yapabileceği olası hamleler
4. CHANCE: benim atabileceğim zarlar
5. MAX: benim yapabileceğim olası hamleler
6. TERMINAL (ya da cutoff)

Şans dallarının olasılıkları: 1-1 için $1/36$, 1-2 için $1/18$, ..., 6-5 için $1/18$, 6-6 için $1/36$. Çift zar tek bir biçimde gelebildiği için $1/36$, farklı zarlar iki sırayla gelebildiği için $2/36 = 1/18$ olasılığa sahiptir.

### 13.2 Değer hesabı

MIN ve MAX düğümlerinin değerleri bildiğimiz gibi hesaplanır. Şans düğümünde ise çocukların değerlerinin olasılıklarla ağırlıklı toplamı alınır:

$$\text{değer}(\text{şans düğümü}) = \sum_{s} P(s) \cdot \text{değer}(s)$$

Bir şans düğümündeki bütün olasılıkların toplamı 1'dir. Tavla için: $6 \cdot \tfrac{1}{36} + 15 \cdot \tfrac{1}{18} = \tfrac{6}{36} + \tfrac{30}{36} = 1$.

### 13.3 Örnek

Basit bir örnekte (ekrandan, slayt küçük resmi, 01:35:00) iki olası sonucu olan bir şans düğümü vardır: iki yüzlü bir zar düşünülsün, bir yüzün gelme olasılığı 0.9, diğerinin 0.1. Seviyeler: benim hamlelerim (MAX), karşı tarafın zarları (CHANCE), karşı tarafın hamleleri (MIN), en altta benim açımdan durum skorları.

- Sol hamle: MIN düğümleri $\min(2, 4) = 2$ ve $\min(5, 3) = 3$. Şans düğümü $0.9 \cdot 2 + 0.1 \cdot 3 = 1.8 + 0.3 = 2.1$.
- Sağ hamle: MIN düğümleri $1$ ve $\min(6, 4) = 4$. Şans düğümü $0.9 \cdot 1 + 0.1 \cdot 4 = 0.9 + 0.4 = 1.3$.
- Kök (MAX): $\max(2.1, 1.3) = 2.1$. Soldaki hamle daha mantıklıdır.

<!-- BELİRSİZ: Sağ daldaki ilk MIN düğümünün yaprakları slaytın küçük resminde okunamadı; MIN değerinin 1 olduğu altyazıdan alındı. -->

Hesaplar python ile doğrulandı (2.1 ve 1.3).

### 13.4 Karmaşıklık ve TD-Gammon

İşin kötü tarafı, şans düğümleri karmaşıklığı artırır: $b^m$ yerine $b^m n^m$ olur. Burada $n$ şans faktörünün dallanmasıdır; tek zarda 6, çift zarda 21'dir. Tavlada $b \approx 20$, $n = 21$'dir. Tam çözüm mevcut şartlarda imkânsızdır; pratikte en fazla 3 seviye mümkündür. Ama TD-Gammon adlı program 2 derinlikli arama yapar, çok iyi bir değerlendirme fonksiyonu vardır ve sonuç dünya şampiyonu seviyesidir.

Hoca, şans içeren oyunlarda "dünya şampiyonu" kavramının farklı anlaşılması gerektiğini anlattı. **Soru:** Dünya satranç şampiyonuyla yüz kere oynasanız birini kazanma şansınız var mı? **Cevap:** Hocaya göre yok. Ama dünya tavla şampiyonuyla yüz kere tavla oynansa, büyük olasılıkla birkaçı kazanılabilir (hoca "5 tanesini falan" diye tahmin etti, şanslı bir günde daha fazla). Şans faktörü varken iki tarafın kazanma ve kaybetme olasılıkları birbirine daha yakındır; her zaman bir kazanma şansı vardır. Deterministik oyunlarda ise uzmanlık farkı arttıkça zayıf tarafın kazanma olasılığı sıfıra yaklaşır.

## 14. Tahmin ve Öğrenme

Bir insan biriyle oynarken, o kişinin oyunda nasıl davrandığını da öğrenir: şunu yapınca şöyle yapıyor, bunu yapmadan önce şu hareketi yapıyor gibi. Bu, karşı tarafı tanımaktır. Aynı mekanizma bilgisayara da verilebilir. Slayttaki maddeler (ekrandan, 01:35:00):

- Bilgisayar kullanıcının hareket loglarını kaydedebilir.
- Kullanıcının bir sonraki hareketini bu loglara göre tahmin edebilir. Tüm olasılıkları hesaba katmaya gerek kalmaz.
- Bu tahmine göre yapması en iyi hareketi yapabilir.

Slayttaki örnek bir dövüş oyunundandır (Virtua Fighter 4; slaytta "Virtual Fighter 4" yazılı). Hareketlerin adları Low Kick, Low Punch, Uppercut gibidir. Rakibin önceki hareketleri:

| Önceki hareketler | Sayı | Oran |
|---|---|---|
| Low Kick, Low Punch, Uppercut | 10 | %50 |
| Low Kick, Low Punch, Low Punch | 7 | %35 |
| Low Kick, Low Punch, Low Kick | 3 | %15 |

Şimdiki durum: "Low Kick, Low Punch, ?". Rakip %50 olasılıkla uppercut, %35 olasılıkla low punch, en düşük olasılıkla low kick yapacaktır. Üç seçenek arasında bunu yapmak çok anlamlı görünmeyebilir, ama yüzlerce olasılık arasından büyük olasılıkla doğru olan küçük bir kısmı seçebilmek hem zamandan hem bellekten çok tasarruf sağlar.

Asıl kazanç dallanma faktörünün yüksek olduğu durumlarda görülür: bütün olasılıkları denemek yerine kullanıcının yapma olasılığı yüksek olanlar denenir, düşük olasılıklılar atılır ve kazanılan kaynakla daha derine inilir. Hocanın örneği: $b = 10$ iken 2-3 derinliğe inilebiliyorsa, $b$ 3'e indirildiğinde belki 5-6 derinliğe inilebilir. Tahmin fonksiyonu iyi kurulursa bilgisayar sizin o oyundaki oynama tarzınızı oldukça iyi yakalayabilir ve stratejisini buna göre geliştirebilir.

## 15. Değerlendirme Fonksiyonunu Öğrenmek

Slayttaki ifade (ekrandan, 01:40:00): Deep Blue, durum değerlendirme fonksiyonundaki ağırlıkları ($w_1, w_2, \dots, w_n$) öğrenmiştir:

$$f(p) = w_1 f_1(p) + w_2 f_2(p) + \dots + w_n f_n(p)$$

$f_1, f_2, \dots, f_n$ verilmişti; yani tahtanın neyine bakılacağı söylenmişti. Ama bunların nasıl birleştirileceği söylenmemişti. Nasıl öğrenilmiş olabilir?

**Soru:** Deep Blue ağırlıkları nasıl öğrenmiş olabilir? **Cevap:** Bir öğrenci Stockfish'in normal derinlikli aramayla çalıştığını, AlphaZero'nun ise kendi kendine oynayarak öğrendiğini hatırlattı. Hoca bunun sonraki konu olduğunu, şimdilik standart değerlendirme fonksiyonlarının nasıl öğrenildiğini sorduğunu söyledi. Başka bir öğrenci deneme-yanılma önerdi. Bir diğeri daha önce oynanmış maçlara, örneğin iki profesyonel arasındaki maçlara bakılabileceğini; bir hamleden diğerine geçerken o hamlenin seçilmesi için $w$'lerin ne olması gerektiğinin görülebileceğini söyledi. Hoca bunu doğruladı.

Deep Blue'nun arkasında, grandmaster seviyesindeki oyuncuların binden fazla oyununda yapılan her hamlenin yer aldığı, "şu durumda şunu yaptı" biçiminde bir veritabanı vardı. Kasparov'un ve daha önceki şampiyonların oynadığı oyunlar da bu veritabanındaydı. Her hamle için, önceki durumdan gidilebilecek bütün durumlar arasında ustanın yaptığı hamlenin seçileceği biçimde $w$'ler düzenlendi. Yani program, ustaların doğru yaptığı seçimleri kendisi de yapacak şekilde değerlendirme fonksiyonunu nasıl birleştireceğini öğrendi. Bir sonraki adım ise kendi kendine oynamaktır.

## 16. Kendi Kendine Oynamak ve Monte Carlo Ağaç Araması

### 16.1 Self-play

Bu yaklaşımda bilgisayara master seviyesindeki oyuncuların oyunlarına dair hiçbir şey söylenmez. İnsanların oyunu nasıl oynadığını anlatan bir değerlendirme fonksiyonu da verilmez. Verilen şey yalnız oyunun kuralları ve oyunun kazanılıp bittiğini kontrol eden mekanizmadır, yani oyun dinamikleri. Sonra bilgisayar kendi kendine oynar. Örneğin bilgisayar bir strateji belirler, bu strateji başka bir stratejiyle çarpıştırılır, hayatta kalan ilerler ve başka bir stratejiyle oynar. Bu **self-play**, uzman bilgisine ihtiyaç duymadan satrancı iyi oynayabilen makineler üretir. Deep Blue'da grandmaster oyunları vardı; bu yapılarda ise böyle bir bilgi yoktur. Süreç milyonlarca, milyarlarca maçı kendi kendine oynayarak satrancı iyi oynamayı öğrenir.

### 16.2 MCTS nedir?

Monte Carlo Ağaç Araması (Monte Carlo Tree Search, MCTS), 2006'da go ile popüler olmaya başlayan, büyük arama uzayları için tasarlanmış bir yöntemdir. Sınırlı derinlikte aramada belli bir derinlik tanımlanır ve o derinlikteki bütün olasılıklar denenir. MCTS bunun yerine **rastgele hareketler üretme** mekanizması kullanır.

Slayttaki soru: "A'dayız, yapabileceğimiz 3 hareket var. Hangisini yapmak iyi?" Dört adım tekrarlanır (ekrandan, 02:00:00):

1. **Selection (seçim):** Önce sınırlı derinlikteki gibi birkaç seviyelik bir ağaç tutulur (örnekte üç seviye). Eldeki istatistiklere göre kökten aşağı bir yol seçilir, örneğin A, B, G.
2. **Expansion (genişletme):** Seçilen G düğümünden yeni bir hamle (J) eklenir.
3. **Simulation (benzetim):** J'den oyun bitene kadar **rastgele** hamleler yapılır: bir ben, bir rakip. Bu hamleler akılcı değildir ve çok hızlı üretilir; bu yüzden çok sayıda oynanabilir. Oyunun sonunda kazanılıp kaybedildiği kaydedilir.
4. **Back propagation (geri yayılım):** Oyunun sonucu yukarıya, J'den G'ye, G'den B'ye, B'den A'ya yayılır.

Slayttaki not: **her düğüm kaç oyun oynandığını ve kaçının kazanıldığını tutar.** Hocanın örneği: B hamlesiyle 1 milyon oyun oynanmış, 600 bini kazanılmış, 400 bini kaybedilmiş; C hamlesiyle 900 bin oyun oynanmış, 200 bini kazanılmış, 700 bini kaybedilmiş. A durumunda B'nin, C'nin ya da D'nin seçilmesi bu istatistiklere göre yapılır.

Oyunun gerçek derinliği çok fazladır (satrançta 40-50 hamle, go'da 150 civarı). Başta belki 10 seviyelik bir kısım tutulur, ondan sonrası tamamen rastgele üretilir. Biriken kazanma ve kaybetme sayıları hamlenin iyiliğini ya da kötülüğünü tahmin etmek için kullanılır; adındaki "Monte Carlo" da bu sayma temelli yaklaşımdan gelir. Tek bir rastgele oyun güvenilir değildir, ama milyonlarca rastgele oyun bir anlam taşır hâle gelir.

### 16.3 Seçimde ikilem

Seçim adımında bir ikilem vardır (ekrandan, slayt küçük resmi, 02:05:00): şimdiye kadar çok oynanıp umut vaat eden dalları mı seçmeli, yoksa az oynanmış dalları mı? Hocaya göre başlangıçta çeşitliliği görebilmek, bütün olasılıkları işin içine katabilmek için farklı durumları denemek daha iyidir. Süreç ilerledikçe o ana kadar en başarılı olanları seçip oradan ilerlemek daha mantıklı olur. Slayta göre seçimde sezgisel yaklaşımlar kullanılır, rastgele seçim uygulanabilir değildir. Slaytta adı geçen yöntemlerden biri Upper Confidence Bound for Trees'tir. Diğeri CNN'dir: oyun tahtası bir CNN'e verilir ve ağ tahtanın değerini tahmin eder. Bu yapılar MCTS'nin içinde de kullanılabilir.

> **Ek bilgi (derste anlatılmadı):** Upper Confidence Bound for Trees (UCT), her çocuk için kazanma oranına, az ziyaret edilmiş çocukları öne çıkaran bir keşif terimi ekler. Yaygın biçimi $\frac{w_i}{n_i} + c\sqrt{\frac{\ln N}{n_i}}$'dir: $w_i$ o çocuktan kazanılan oyun, $n_i$ o çocuktan oynanan oyun, $N$ ebeveynden oynanan toplam oyun sayısı, $c$ bir sabittir. Böylece hocanın anlattığı keşif-sömürü dengesi tek bir formülle kurulur.

### 16.4 Paralelleştirme ve uygulama alanları

MCTS'nin önemli bir özelliği kolayca paralelleştirilebilmesidir. Süreç birçok makinede aynı anda koşturulabilir, çünkü parçalar birbirine bağımlı değildir. Yalnız verilerin toplanıp seçim yapıldığı kısım ortaktır ve büyük bir yük getirmez. Özellikle rastgele hareketlerle oynanan simülasyon kısmı istenildiği kadar makineye, işlemciye, GPU'ya ya da GPU çekirdeğine bölünebilir. Slayta göre paralelleştirme kökten ya da yapraklardan yapılabilir.

Uygulama alanı, bilgisayarlara karşı oynanacak her türlü oyun ve bilgisayarda taklit edilebilen dünyalardaki arama problemleridir. Hoca tahtaya bir robot kolu çizdi: iki boyutta düşünüldüğünde kolun yer düzlemiyle yaptığı açı ve eklemlerin açıları olmak üzere dört açı vardır. Kolun ucunun bir başlangıç noktasından istenen bir noktaya getirilmesi için gereken hareketler bulunmak istenir: belki önce bir eklem çevrilir, sonra adım adım yaklaşılır. Bu tür problemler de MCTS ile çözülebilecek türdendir.

## 17. Deep Blue Tartışması ve Makinelerin Sınırları

### 17.1 Eleştiri ve cevap

Slayttaki ilk görüş (ekrandan, 02:10:00) bir eleştiridir: Deep Blue'nun yaptığı şey yalnız tasarımcıların fikirlerini büyük hesap kabiliyetiyle uygulamaktır. Yenen tasarımcılar ve teknolojidir; yapılan şey yalnız özel bir hesap makinesidir. Yani "çok abartmayın" denmektedir.

Drew McDermott'ın cevabı: **Deep Blue'nun gerçekte satrançtan anlamadığını söylemek, bir uçağın kanatlarını çırpmadığı için uçmadığını söylemeye benzer.** Deep Blue insanlar gibi oynamıyor ama insanlardan daha iyi oynuyor. Uçaklar da kuşlar gibi kanat çırpmıyor ama kuşlardan daha iyi uçuyor.

### 17.2 Uzaylılar sorusu

**Soru:** Uzaylılar dünyaya gelip satrançta meydan okusa, kazanırlarsa dünya onların olacak, kaybederlerse geri dönecekler. Kapışmaya Deep Blue'yu mu, Kasparov'u mu gönderirdiniz? **Cevap:** Cevap veren öğrencilerin hepsi Deep Blue dedi, çünkü Deep Blue Kasparov'u yenmişti. Başka bir fikir çıkmadı.

### 17.3 Deep Thought kaleyi aldı

Hoca, Deep Blue'nun bir önceki sürümü olarak tanıttığı Deep Thought'un bir hatasını gösterdi. Tahtada beyazın çok az taşı vardır, ama siyahın fili ve iki kalesi vardır; siyah çok daha güçlüdür. Fakat arada bir piyon duvarı vardır: beyazlar hareket etmedikçe siyah bu duvarı geçemez, beyaz taşlara ne kaleyle ne fille müdahale edebilir. Sıra beyazdadır (ekrandan, slayt küçük resmi, 02:10:00) ve Deep Thought piyonla siyahın kalesini alır.

**Soru:** Kaleyi almak kötü bir şey mi? **Cevap:** Bir öğrenci "kötü, siyah artık aşağı yaklaşabilir" dedi. Hoca doğruladı: oyun bu hâliyle berabere biter, ama kaleyi alınca duvar açılır ve beyaz kaybeder.

Slayttaki çözüm önerisi yeni bir $f$ eklemektir: "böyle bir baraj kurulmuşsa onu yıkma" gibi bir bileşen. Bu eklenince Deep Thought bu durumda kaleyi almaz. Ama sonra yeni bir durum gelir (ekrandan, 02:15:00, "Deep Thought kaleyi yine aldı!"): Deep Thought yine kaleyi alır. Oysa kaleyi yemek yerine bir taşı uygun yere koyup henüz olmayan bir barajı oluşturmak beraberliği garanti ederdi. Bu sefer de "olmayan bir barajı oluşturmak" için bir $f$ eklenebilir. **Nereye kadar?** Her yeni durum için yeni bir $f$ eklemek iyi bir yol değildir.

Çok üst seviyede olmayan insanların bile görebildiği bu durumu, önceki şampiyonlara karşı başarılı olmuş, sıradan olmayan bir program görememiştir. Sebebi kısmen, yaptığı hareketin sonucunun çok ilerde ortaya çıkmasıdır; kullandığı derinlik o kötü durumu görmeye yetmez. Ama başka bir sebep daha vardır.

**Soru:** Bu tahtalar gerçek bir satranç oyununda ortaya çıkabilir mi? **Cevap:** Bir öğrenci "büyük olasılıkla çıkmaz" dedi. Hoca doğruladı: bunlar ütopik tahtalardır, aslında satranç problemleridir.

> **Ders sonrası not:** Hoca Deep Thought'u "96 model Deep Blue" ve "önceki dünya şampiyonunu yenmiş bir program" diye andı. Deep Thought, Deep Blue'dan önceki Carnegie Mellon/IBM programıdır ve büyük olasılıkla 1980'lerin sonunda güçlü büyükustaları yenmiştir; dünya şampiyonuna karşı bir maç kazanmamıştır. Bu bilgiler altyazıdan doğrulanamadı.

### 17.4 Uzaylılar sorusu, satranç problemleriyle

Hoca uzaylı sorusunu değiştirdi: uzaylılar klasik satranç değil, farklı satranç problemleri üzerinde yarışmak isteseler kimi gönderirdiniz? Bir öğrenci Kasparov'u göndereceğini söyledi. Gerekçesi, Stockfish'in çözemediği ama iyi bir insan oyuncunun çözebildiği benzer problemler görmüş olmasıydı; bu yüzden "türümüzden birini" göndermek daha iyi olabilirdi.

Hoca şöyle bağladı: Klasik oyunda dünya şampiyonları bilgisayarı büyük olasılıkla yenemiyor ve bu öyle kalacak. Ama varyasyonlarda, örneğin 8x8 yerine 16x16'lık bir tahtada ya da taş sayısı iki katına çıkarılmış (16 piyon, 4 kale) bir oyunda işler bilgisayar için çok karışır. İnsanın adaptasyon yeteneği çok daha üst seviyededir; 8x8'den 16x16'ya geçmek için sil baştan öğrenmesi gerekmez. AlphaZero gibi bir sistemin ise sıfırdan yeniden eğitilmesi gerekir; 8x8'de öğrendiklerini 16x16'ya aktarması pek mümkün görünmüyor. Makineler sık karşılaştıkları problemleri çözebilir, ama daha önce görmedikleri, insanların kolaylıkla çözdüğü problemlerde zorlanabilirler.

## Örnek Sorular

### Soru 1 (ekrandan, 00:20:00)

Kökü MAX olan bir oyun ağacında üç hamle ($A_1, A_2, A_3$) ve her birinin altında rakibin üç cevabı vardır. Yaprak değerleri: $A_1$ altında 3, 12, 8; $A_2$ altında 2, 4, 6; $A_3$ altında 14, 5, 2. Hangi hamle yapılmalıdır?

**Çözüm (derste verildi):** MIN değerleri $\min(3,12,8)=3$, $\min(2,4,6)=2$, $\min(14,5,2)=2$. Kök $\max(3,2,2)=3$; hamle $A_1$'dir. En büyük yaprak (14) için $A_3$'ü seçmek yanlıştır, çünkü rakip 2'ye götüren cevabı verir.

### Soru 2 (ekrandan, 00:40:00)

XOX'ta boş tahtadan, $e(n) = M(n) - O(n)$ değerlendirme fonksiyonu ve 2 derinlikli arama ile X'in ilk hamlesi ne olmalıdır?

**Çözüm (derste verildi):** Simetrikler elendiğinde köşe, kenar ve merkez hamleleri kalır. MIN değerleri köşe için $-1$, kenar için $-2$, merkez için $1$'dir. En büyüğü 1 olduğu için X merkeze konur. (Değerler python ile doğrulandı; tablo bölüm 7.1'dedir.)

### Soru 3 (ekrandan, 01:00:00)

c2 ve d2'de iki beyaz kale, a4 ve a5'te iki siyah kale ve a2'de bir siyah piyon vardır; sıra beyazdadır. Değerlendirme yalnız taş değerlerine göre yapılıyorsa c2'deki beyaz kale a2'deki piyonu alır mı? Cevabı 1, 2, 3 ve 4 derinlik için verin.

**Çözüm (derste verildi):** 1 derinlik: piyon kazancı var, alır. 2 derinlik: siyah kale beyaz kaleyi alır, bir piyona bir kale değmez, almaz. 3 derinlik: ikinci beyaz kale geri alır, piyon + kale bir kaleye değer, alır. 4 derinlik: ikinci siyah kale de alır, piyon + kale iki kaleye değmez, almaz. Bu örnek ufuk etkisini gösterir.

### Soru 4 (ekrandan, 01:05:00)

Hamle süresi 100 saniye, donanım hızı $10^4$ düğüm/saniye ve dallanma $b = 35$ ise kaç seviye derine bakılabilir? Alfa-beta budamasıyla bu nasıl değişir?

**Çözüm (derste verildi):** $10^4 \cdot 100 = 10^6$ düğüm; $35^m = 10^6 \Rightarrow m \approx 3.9 \approx 4$ (amatör seviye). Alfa-beta karmaşıklığı $O(b^{m/2})$'ye indirebildiği için aynı bütçeyle yaklaşık 8 derinliğe (master seviyesi) inilebilir.

### Soru 5 (ekrandan, 01:15:00, "Adım adım çözünüz")

Aşağıdaki ağaçta alfa-beta budamasını adım adım uygulayın. A kök (MAX); B, I, P (MIN); C, F, J, M, Q, T (MAX); yapraklar (MIN seviyesi olarak çizilmiş, değerleri verilmiş):

```text
A (MAX)
├── B (MIN)
│   ├── C (MAX): D=2, E=1
│   └── F (MAX): G=6, H=1
├── I (MIN)
│   ├── J (MAX): K=8, L=3
│   └── M (MAX): N=5, O=2
└── P (MIN)
    ├── Q (MAX): R=3, S=4
    └── T (MAX): U=2, V=6
```

**Çözüm:** Slayttaki işaretler budanan dalları ve sınırları gösteriyor ama ara adımlar derste anlatılmadı. Aşağıdaki adımlar slayttaki işaretlerle tutarlıdır ve python ile doğrulandı.

> **Çözüm (derste verilmedi):**
>
> 1. C: $\max(2, 1) = 2$. B'nin üst sınırı 2 olur ($[-\infty, 2]$).
> 2. F'nin ilk yaprağı G = 6 gelir. F en az 6 olur ($[6, +\infty]$). B en fazla 2 olabildiği için F'nin değeri B'yi değiştiremez; H **budanır**. B = 2. Kök $[2, +\infty]$.
> 3. J: $\max(8, 3) = 8$. I'nın üst sınırı 8 olur. M: $\max(5, 2) = 5$ (5 > 2 olduğu için budama yok). I = $\min(8, 5) = 5$. Kök $[5, +\infty]$ olur.
> 4. Q: $\max(3, 4) = 4$. P en fazla 4 olabilir ($[-\infty, 4]$). Kök en az 5 olduğu için P'nin kalan çocuğu T (U ve V ile birlikte) **budanır**. P = 4.
> 5. Kök A = $\max(2, 5, 4) = 5$; seçilen hamle I'dır.
>
> 12 yapraktan 9'u değerlendirilir; H, U ve V hiç incelenmez. T'nin budanması, budamanın üst seviyelerden de yapılabildiğini ve bütün bir alt ağacın birden atıldığını gösterir.

### Soru 6 (ekrandan, slayt küçük resmi, 01:35:00)

Kök MAX; iki hamlenin her birinden sonra olasılıkları 0.9 ve 0.1 olan bir şans düğümü, sonra MIN düğümleri vardır. Sol hamlede MIN düğümlerinin yaprakları (2, 4) ve (5, 3); sağ hamlede MIN değerleri 1 ve $\min(6, 4)$'tür. Hangi hamle seçilir?

**Çözüm (derste verildi):** Sol: $0.9 \cdot 2 + 0.1 \cdot 3 = 2.1$. Sağ: $0.9 \cdot 1 + 0.1 \cdot 4 = 1.3$. Kök $\max(2.1, 1.3) = 2.1$; sol hamle seçilir.

### Soru 7 (derste sözlü, 01:15:29)

Satranç programlarında acemi ve uzman seviyeler neye göre belirlenir?

**Çözüm (derste verildi):** Büyük ölçüde arama derinliğine göre. Derinlik arttıkça program daha çok olasılık görür, daha doğru karar verir ve cevap süresi uzar.

### Soru 8 (ekrandan, 02:10:00)

Uzaylılar satrançta meydan okusa kapışmaya Deep Blue'yu mu Kasparov'u mu gönderirdiniz? Yarışma klasik satranç değil satranç problemleri olsaydı cevap değişir miydi?

**Çözüm (derste tartışıldı):** Klasik satrançta öğrenciler Deep Blue'yu seçti. Satranç problemlerinde ise insanın uyum yeteneği öne çıkar; makineler görmedikleri ütopik tahtalarda (Deep Thought örnekleri) ve 16x16 gibi varyasyonlarda zorlanır. Bu yüzden bir öğrenci Kasparov'u önerdi.

## Dersin Toparlaması

Bu derste bilgisayarların oyun oynarken kullandığı arama yöntemleri ele alındı. Oyunlar şans ve bilgi açısından sınıflandı. İki oyunculu deterministik oyunlar için oyun ağacı ve minimax algoritması kuruldu: MAX seviyelerinde en büyük, MIN seviyelerinde en küçük değer alınır ve rakibin de en iyisini oynadığı varsayılır. Satrançta $10^{60}$ düğümlük ağaç tam aranamadığı için sınırlı derinlikte arama ve değerlendirme fonksiyonu kullanıldı. Değerlendirme fonksiyonu tahtanın iyiliğini sezgisel olarak tahmin eder ve genelde $\sum w_i f_i$ biçiminde ağırlıklı bir toplamdır. XOX örneği bu yaklaşımın adım adım nasıl oynandığını, ufuk etkisi ise derinliğin kararı nasıl değiştirebildiğini gösterdi. Alfa-beta budaması aynı kararı daha az düğümle verir; arama derinliğini iki katına çıkarabilir. Satranç programlarındaki zorluk seviyeleri de büyük ölçüde bu derinlikten gelir.

Dersin ikinci yarısında şans içeren oyunlar için expectiminimax, rakibi tanıyarak dallanmayı azaltan tahmin ve öğrenme, Deep Blue'nun değerlendirme ağırlıklarını usta oyunlarından öğrenmesi ve uzman bilgisi olmadan kendi kendine oynayarak öğrenen Monte Carlo Ağaç Araması anlatıldı. Deep Blue tartışması ve Deep Thought örnekleri, makinelerin hesap gücünde insanları geçtiğini ama görmedikleri durumlara uyum sağlamada hâlâ zorlandığını gösterdi. Hoca, günümüzde pekiştirmeli öğrenme ile MCTS'nin çok popüler olduğunu, pekiştirmeli öğrenmenin makine öğrenmesi konularının son haftalarından birinde ayrıntılı işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
