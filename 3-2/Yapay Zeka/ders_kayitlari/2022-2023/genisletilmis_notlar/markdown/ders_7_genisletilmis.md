# Ders 7 Genişletilmiş Notu: Oyunlarda Arama: Minimax, Alfa-Beta Budama ve Expectiminimax

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oyunlar ve arama konusundaki yeri
- 2. Oyun türleri
- 3. Oyun ağacı
- 4. Minimax algoritması
- 5. Satrançta sınırlar
- 6. Sınırlı derinlikte arama ve değerlendirme fonksiyonu
- 7. Tic-tac-toe için değerlendirme fonksiyonu
- 8. Ufuk etkisi ve donanımın sınırı
- 9. Alfa-beta budaması
- 10. Deterministik oyunlarda bilgisayarlar ve satranç tarihi
- 11. Şans içeren oyunlar: Expectiminimax
- 12. Tahmin ve öğrenme
- 13. Değerlendirme fonksiyonunu öğrenmek ve kendi kendine oynamak
- 14. Monte Carlo Ağaç Araması
- 15. Tartışma: Makineler satrançta neyi başarıyor?
- Örnek Sorular

## 1. Oyunlar ve arama konusundaki yeri

Bu derste oyunlar işlenir. Hoca, bu konuyla beş haftadır süren arama konusunun, daha doğrusu **ayrık (discrete) uzaydaki arama** kısmının tamamlandığını söyler. Dersin ilerleyen haftalarında işlenecek makine öğrenmesi de bir bakıma aramanın **sürekli (continuous) uzaydaki** hâlidir. Problem türleri değişse de arama süreci orada da sağlam biçimde yer alır.

Oyunlar konusunda grafiksel bir oyunun nasıl yapıldığı ele alınmaz. Odak, bilgisayarların insanlara ya da birbirlerine karşı nasıl oyun oynayabildiği ve bunun için hangi algoritmaların kullanıldığıdır.

## 2. Oyun türleri

Oyunlar iki ayrı boyuta göre sınıflandırılır:

- **Deterministik / şans içeren:** Zar atmak, kart çekmek gibi oyuncuların kesin olarak belirleyemediği bileşenler varsa oyun şans içerir. Bu bileşen yoksa oyun deterministiktir.
- **Tam bilgili (perfect information) / eksik bilgili (imperfect information):** Tam bilgili oyunda oyuncular oyunun tamamı hakkında bilgi sahibidir. Satrançta kendi taşlarınızın da rakibin taşlarının da yerini görürsünüz. Okey ya da pokerde ise kendi elinizdeki taşları ya da kartları görürsünüz, ama rakiplerin ellerini göremezsiniz. Bu eksik bilgidir.

Derste hem deterministik hem de şans içeren oyunlara bakılır.

## 3. Oyun ağacı

Bilgisayarla oyun oynamanın temel veri yapısı **oyun ağacıdır (game tree)**. Derste iki oyunculu bir oyun için oyun ağacı incelenir. Üç ya da dört oyunculu oyunlarda yapı biraz farklılaşır, ama iki oyuncu için söylenenler çok oyunculu duruma genellenebilir.

Örnek oyun tic-tac-toe'dur. Bir taraf X, diğer taraf O koyar. Amaç yatayda, dikeyde ya da çaprazda üç tane kendi işaretini dizmektir.

Ağaç boş bir tahtayla başlar (ekrandan, 00:10:00). Biz bilgisayarız ve X koyuyoruz. Boş tahtada yapabileceğimiz 9 hamle vardır. Her birinden sonra rakibin yapabileceği 8 hamle, her birinden sonra da 7 hamle çıkar. Ağaç böylece çok büyür.

**Terminal düğümler** oyun sonlarıdır. Her terminal düğüme, bizim açımızdan iyiliğini gösteren bir değer verilir. Buna **fayda (utility)** denir. Biz X olduğumuz için:

- Kazanırsak +1,
- Kaybedersek −1,
- Berabere kalırsak 0.

Ekrandaki üç örnek terminal tahta yan yana çizilmiştir ve fayda değerleri −1, 0, +1'dir. Hoca bunların ağacın aynı seviyesinde olup olmadığını sorar. Değildirler: hocanın anlatımına göre biri 6., biri 9., biri 7. seviyededir. Ağaç en fazla 9 seviye derin olabilir. Oyun her zaman aynı adımda bitmez.

Ağacın seviyelerinin yanında MAX ve MIN yazılıdır. Bizim hamle yaptığımız seviyelerin yanına **MAX**, rakibin hamle yaptığı seviyelerin yanına **MIN** yazılır.

## 4. Minimax algoritması

### 4.1 Fikir

MAX ve MIN ile ilerleyen bu yapı, 1950'de Shannon ve Turing'in ortaya koyduğu bir algoritmanın bileşenleridir (ekrandan, 01:20:00). Oyun ağacının tamamı elimizdeyse, bu algoritmayla oyun mükemmel biçimde oynanabilir.

Algoritmanın bir varsayımı vardır: **rakip de oyunu kazanmak ister.** Hocaya göre bu çok güçlü, gerçekdışı bir varsayım değildir. Rakip de kazanmaya çalışıyorsa minimax olabilecek en iyi stratejiyi verir.

Slayttaki özet (ekrandan, 00:15:00):

- Rastgele olmayan oyunlar için idealdir.
- Yaklaşım: en yüksek minimax değerini sağlayan hamleyi yap.

### 4.2 Küçük bir örnek

Ekrandaki küçük oyunda (ekrandan, 00:15:00) biz A seviyesindeyiz (MAX) ve üç hamlemiz var: $a_1$, $a_2$, $a_3$. $a_1$'den sonra rakip $b_1, b_2, b_3$, $a_2$'den sonra $c_1, c_2, c_3$, $a_3$'ten sonra $d_1, d_2, d_3$ yapabilir. Bu hamlelerden sonra oyun biter. Yaprakların altındaki sayılar bizim fayda değerlerimizdir:

| MIN düğümü | Yapraklar | Minimum |
|---|---|---|
| B ($a_1$) | 3, 12, 8 | 3 |
| C ($a_2$) | 2, 4, 6 | 2 |
| D ($a_3$) | 14, 5, 2 | 2 |

Hesap en alttan başlar. MIN seviyesindeki bir düğümün değeri, çocuklarının minimumudur. MAX seviyesindeki bir düğümün değeri, çocuklarının maksimumudur. Kökün değeri $\max(3, 2, 2) = 3$'tür. 3'ü sağlayan hamle $a_1$ olduğu için minimax $a_1$ hamlesini önerir.

Neden böyle? $a_3$'ün altında 14 puanlık bir sonuç vardır; "optimal" bir strateji 14'ü kaçırıyormuş gibi görünebilir. Ama $a_3$'ü yaptığımızda rakip $d_1$, $d_2$ ya da $d_3$'ü yapacaktır. Hoca sınıfa hangisini yapacağını sorar; cevap $d_3$'tür. Rakip kendi açısından en iyi, bizim açımızdan en kötü hamleyi yapar. Bu yüzden rakibin seviyesinde minimum seçilir. $a_2$ ya da $a_3$ yaparsak 2 puan alırız; $a_1$ yaparsak en azından 3 puan alırız.

Rakip rastgele oynasaydı, yani $b_1, b_2, b_3$'ü seçme şansları birbirine eşit olsaydı, minimax ideal olmazdı. O durumda değerlerin ortalamasına bakıp karar vermek mümkündü. Ama rakip kazanmak için oynuyorsa minimum seçilmelidir.

### 4.3 Bileşenler ve algoritma

Minimax'ın bileşenleri (ekrandan, 00:20:00, slayt kenar küçük resminden):

- **MAX:** Bizim olası hamlelerimizden, kendi açımızdan en iyi sonucu vereni seçmemiz.
- **MIN:** Rakibin olası hamlelerinden, kendi açısından en iyi, bizim açımızdan en kötü sonucu vereni seçmesi.
- **UTILITY:** Oyun sonucunu gösteren değer.

Bir $n$ düğümünün minimax değeri:

$$
\text{MINIMAX-VALUE}(n) =
\begin{cases}
\text{UTILITY}(n) & n \text{ oyun sonu ise} \\
\max_{s \in \text{Ardıl}(n)} \text{MINIMAX-VALUE}(s) & n \text{ MAX seviyesinde ise} \\
\min_{s \in \text{Ardıl}(n)} \text{MINIMAX-VALUE}(s) & n \text{ MIN seviyesinde ise}
\end{cases}
$$

Burada $\text{Ardıl}(n)$, $n$ durumundan gelinebilecek bütün durumlardır.

Slayttaki algoritma (ekrandan, 00:20:00):

```text
function MINIMAX-DECISION(state) returns an action
    v <- MAX-VALUE(state)
    return the action in SUCCESSORS(state) with value v

function MAX-VALUE(state) returns a utility value
    if TERMINAL-TEST(state) then return UTILITY(state)
    v <- -inf
    for a, s in SUCCESSORS(state) do
        v <- MAX(v, MIN-VALUE(s))
    return v

function MIN-VALUE(state) returns a utility value
    if TERMINAL-TEST(state) then return UTILITY(state)
    v <- +inf
    for a, s in SUCCESSORS(state) do
        v <- MIN(v, MAX-VALUE(s))
    return v
```

Değerler hesaplanırken algoritma **derinlemesine arama (DFS)** ile çalışır.

### 4.4 Özellikler

Slayttaki özellikler (ekrandan, 00:20:00, slayt kenar küçük resminden):

- **Bütünlük:** Evet (ağaç sonluysa).
- **Zaman karmaşıklığı:** $O(b^m)$.
- **Bellek karmaşıklığı:** $O(bm)$ (derinlemesine arama).
- **En iyi çözüm:** Evet; kendisi için her zaman en iyisini yapan rakibe karşı optimaldir.

Rakibin rastgele oynadığı durumda optimal değildir; o durumda optimal çözüm başka bir algoritma olurdu.

## 5. Satrançta sınırlar

Elimizde oyun ağacının tamamı varsa optimal oynayan bir algoritmamız var. Ama oyun ağacının elde olduğu oyunlar çok azdır; satranç bunlardan biri değildir (ekrandan, 00:25:00):

- Satrançta ortalama hamle sayısı 40'tır, yani ağacın ortalama derinliği 40'tır.
- Her adımda yapılabilecek farklı hamle sayısının ortalaması 32'dir.
- Arama uzayının büyüklüğü: $32^{40} = 2^{200} \approx 10^{60}$.

Bütün bu yaprakların fayda değerlerinin hesaplanıp yukarı doğru çıkılması gerekir. Saniyede 3 milyar durum işlendiğini varsayalım:

- Bir yıldaki saniye sayısı $\approx 32 \cdot 10^6$,
- Bir yılda işlenecek durum sayısı $\approx 3\cdot 10^9 \cdot 32 \cdot 10^6 \approx 10^{17}$,
- Tüm durumların değerlendirilmesi $\approx 10^{60} / 10^{17} = 10^{43}$ yıl sürer.
- Evrenin yaşı $\approx 10^{10}$ yıl.

Böyle bir ağacı ne elde etmek ne de işlemek mümkündür. Donanımı on kat iyileştirmek üssü yalnız bir azaltır.

Hoca burada bir gözlem ekler: Oyun ağacı elde olan oyunlar sıkıcıdır. Tic-tac-toe'nun stratejisi bellidir, defalarca oynamanın bir anlamı yoktur. Satrançta ise iki insan arasında sürekli farklı durumlar ortaya çıkar, oyun basit stratejilerle çözülemez ve farklı biçimlerde sonuçlanır. Bir oyunun oynanabilir ve sevilir olmasının nedeni, aslında oyun ağacının elde olmayışıdır. Bilgisayarlar insanlardan çok daha büyük oyun ağaçlarını tutabilir, ama satranç bu sınırın da dışındadır.

Sonuç: Minimax'la satranç oynanamaz. Bu teorik değil pratik bir engeldir; teoride elimizde mükemmel bir strateji vardır.

## 6. Sınırlı derinlikte arama ve değerlendirme fonksiyonu

Bilgisayarlar yine de satrancı çok iyi oynar. Bunu nasıl yaptıklarını anlamak için hoca, arama sürecini kısaltmak için daha önce ne kullanıldığını sorar. Bir öğrenci "sezgi" der. Cevap budur: **sezgisel yöntemler** işin içine girer.

Oyun ağacının tamamına ve kesin fayda değerlerine dayanmak yerine, oyun bitmeden, oyun sonu olmayan bir tahtanın bizim açımızdan iyi mi kötü mü olduğu **tahmin edilir**. Slayttaki iki yol (ekrandan, 00:30:00, slayt kenar küçük resminden):

- Sınırlı derinlikte arama ve değerlendirme fonksiyonu (cutoff test, evaluation function),
- Alfa-beta budaması.

Değerlendirme fonksiyonu, bu derste kullanılan **sezgisel fonksiyondur**.

### 6.1 Satranç için basit bir değerlendirme fonksiyonu

Taşlara puan verilir: piyon 1, at ve fil 3, kale 5, vezir 9. Taşların yerine hiç bakılmadan puanlar toplanır. Ekrandaki tahtada (ekrandan, 00:30:00, slayt kenar küçük resminden):

- Siyahlar: 5 piyon, 1 fil, 2 kale; skor $= 1\cdot 5 + 3\cdot 1 + 5\cdot 2 = 5 + 3 + 10 = 18$.
- Beyazlar: 5 piyon, 1 kale; skor $= 1\cdot 5 + 5\cdot 1 = 5 + 5 = 10$.
- Siyahlar için $18 - 10 = 8$, beyazlar için $10 - 18 = -8$.

Bu tahta siyahlar için iyi, beyazlar için kötüdür. Hoca bunun iyi bir fonksiyon olduğunu iddia etmez; yalnız örnektir. Böyle bir tahminle, oyunun sonuna varmadan da minimax kullanılabilir hâle gelir.

### 6.2 Ağırlıklı doğrusal fonksiyon

Slayttaki tanım (ekrandan, 00:30:00):

- Değerlendirme fonksiyonları, oyunun sonucunun çok derinlerde olduğu durumlarda durumların değerlendirilmesi için kullanılır.
- Satranç için bu fonksiyon genellikle önceden belirlenen özniteliklerin doğrusal toplamı olarak düşünülür:

$$
Eval(s) = w_1 f_1(s) + w_2 f_2(s) + \dots + w_n f_n(s)
$$

- Örnek: $w_1 = 9$ ve $f_1(s)$ = (beyaz vezir sayısı) − (siyah vezir sayısı).
- Ağırlıklı toplam, bileşenlerin birbirinden bağımsız olduğunu varsayar.

$f_1$ yukarıdaki taş puanı farkı olabilir; $f_2$ vezir sayısı farkı olabilir. Başka $f$'ler de düşünülebilir. Slayttaki "asıl iş: $f$'leri ve $w$'leri belirlemek" listesi (ekrandan, 00:35:00, slayt kenar küçük resminden):

- Etrafı boş olan piyonlar kötüdür.
- Şahın korumaları var mı?
- Hareket kabiliyetin nasıl?
- Tahtanın ortasının kontrolü sende mi?
- Oyun süresince $w$'lerin değerleri değişir mi?

$f$'ler ve $w$'ler belirlenince, bir $s$ tahtasının bizim açımızdan iyi mi kötü mü olduğuna dair bir tahmin elde edilir. Satranç için iyi bir değerlendirme fonksiyonu yazmak kolay değildir; hoca buna dersin ilerisinde döneceğini söyler. Tic-tac-toe için ise basit ve etkili bir fonksiyon vardır.

## 7. Tic-tac-toe için değerlendirme fonksiyonu

### 7.1 Fonksiyon

Biz X'iz. Bir tahtada X'in bu oyunu hâlâ kazanabileceği çizgiler (içinde O olmayan satır, sütun ve çaprazlar) sayılır. Aynısı O için de yapılır. Fonksiyon şudur:

$$
E(n) = (\text{X'in açık kazanma çizgisi sayısı}) - (\text{O'nun açık kazanma çizgisi sayısı})
$$

Hocanın örnekleri:

- X'in 6, O'nun 5 çizgisi varsa $E = 6 - 5 = 1$.
- X'in 4, O'nun 6 çizgisi varsa $E = 4 - 6 = -2$; tahta bizim için kötüdür.
- X'in 5, O'nun 4 çizgisi varsa $E = 5 - 4 = 1$; tahta bizim için iyidir.

<!-- BELİRSİZ: Bu üç örnek tahtadaki X ve O'nun yerleri slaytta (Luger kaynaklı) görünüyordu ama okunabilir bir karesi yok; konumlar nota alınmadı. -->

### 7.2 İlk hamle: 2 derinlikli arama

Bu fonksiyonla oyun, ağacın tamamı olmadan oynanır. Belirli bir derinlik seçilir; burada 2'dir. Sınırlı derinlikte arama yine DFS ile yapılır (ekrandan, 00:35:00).

Boş tahtada 9 hamle vardır, ama simetri nedeniyle slaytta üç tür hamle gösterilir: köşe (4 durumu temsil eder), kenar (4 durumu temsil eder) ve orta (tek). Her birinin altında rakibin yapabileceği (simetrik olarak farklı) hamleler ve bunların değerleri vardır:

| İlk hamle (MAX) | Rakibin hamlelerinden sonra $E$ değerleri | MIN değeri |
|---|---|---|
| Köşe | $6-5=1$, $5-5=0$, $6-5=1$, $5-5=0$, $4-5=-1$ | −1 |
| Kenar | $5-6=-1$, $5-5=0$, $5-6=-1$, $6-6=0$, $4-6=-2$ | −2 |
| Orta | $5-4=1$, $6-4=2$ | 1 |

DFS önce köşe hamlesini üretir, sonra onun altındaki rakip hamlelerini üretip her birini değerlendirir. Bu düğümler bitince minimumları (−1) köşe düğümüne yazılır. Köşe için 2 derinlikte durulur; X'in sonraki hamleleri üretilmez. Sonra kenar ve orta için aynısı yapılır. Kök MAX olduğu için $\max(-1, -2, 1) = 1$ seçilir: başlangıçta **ortaya X koymak** stratejik olarak en anlamlı hamledir.

### 7.3 İkinci hamle

Oyun bitmedi, yalnız bir hamle yapıldı. Rakip bir hamle yapar (slaytta O, üst orta kareye konmuştur). Sıra yine bizdedir ve yine 2 derinlikli arama yapılır (ekrandan, 00:40:00). Bu tahtada dört farklı aday hamle vardır; her birinin altında rakibin altı ya da yedi (birinde üç) hamlesi değerlendirilir. Minimumlar yukarı yazılınca aday hamlelerin değerleri 1, 0, 1, 0 çıkar. Değeri 1 olan iki hamleden biri seçilir. Hoca birini seçmeyi varsayar; rakip büyük olasılıkla tehdidi kesmek için O koyar ve oyun böyle sürer.

Bütün oyun ağacı elde olmadan oyun oynanabilmektedir. Bunu sağlayan şey değerlendirme fonksiyonudur: bir tahtanın bizim açımızdan iyi mi kötü mü olduğunu söyleyen tahmini bir değer. Bu, genetik algoritmadaki fitness fonksiyonunun ya da sezgisel aramadaki kuş uçuşu mesafenin karşılığıdır.

### 7.4 Soru-cevap: Neden yalnız üç ilk hamle var?

**Soru:** İlk seviyede neden yalnız üç tahta var? X sağ üst köşeye ya da sağ kenara da konabilir.

**Cevap:** O hamleler gösterilen hamlelerle aynı durumdur, yansıma/simetri yüzünden. Köşe tahtası dört köşe durumunu, kenar tahtası dört kenar durumunu temsil eder; orta tektir. Bu gösterim yalnız şekil karışık görünmesin diye seçilmiştir. Bilgisayarda kodlarken bütün hamlelerin hepsi üretilir.

## 8. Ufuk etkisi ve donanımın sınırı

### 8.1 Ufuk etkisi (horizon effect)

Aramayı 2 derinlikte kesmek kararı etkiler mi? 3 derinlikte arama yapılsaydı başka bir hamle seçilebilir miydi? Tic-tac-toe'da bunu görmek zor olduğu için satrançtan bir örnek verilir (ekrandan, 00:55:00).

Tahtada biz beyazız. Beyazın c2 ve d2'de iki kalesi, siyahın a-sütununda iki kalesi ve a2'de bir piyonu vardır. Soru: c2'deki beyaz kale a2'deki siyah piyonu almalı mı? Değerlendirme fonksiyonu taş puanlarıdır.

- **1 derinlik:** Bir hamle yapılır ve arama biter. Kale piyonu alırsa rakip bir piyon kaybeder, biz bir şey kaybetmeyiz. Bir piyon kazanç olduğundan **alır**.
- **2 derinlik:** Rakip, siyah kaleyle bizim kalemizi alır. Bir piyona karşı bir kale kaybedilir; bir piyona bir kale değmez. **Almaz.**
- **3 derinlik:** Biz diğer beyaz kaleyle onun siyah kalesini alırız. Rakip bir kale ve bir piyon, biz bir kale kaybederiz. **Alır.**
- **4 derinlik:** Rakibin diğer siyah kalesi bizim kalemizi alır. Bir piyon ve bir kaleye karşı iki kale kaybedilir. **Almaz.**

Derinlik değiştikçe yapılacak hamle değişir: alır, almaz, alır, almaz. Buna **ufuk etkisi** denir.

Çözüm, mümkün olduğu kadar derine gitmektir; elinizdeki donanımın izin verdiği kadar. Ne kadar derine gidilirse o kadar doğru bir hamle yapılır. Ağacın sonuna gidilebilseydi mükemmel hamle bulunurdu, ama gidilemez.

### 8.2 Donanım ne kadar derinliğe izin verir?

Hocanın hesabı:

- Hamle yapma süresi 100 saniye olsun (insanlara karşı oynayan bir makine için makul bir bekleme).
- Saniyede $10^4$ düğüm incelenebilsin.
- Her hamle için $100 \cdot 10^4 = 10^6$ düğüm açılabilir.
- $b^m = 10^6$ ve $b = 35$ ise $m = 4$ olur ($35^4 \approx 1{,}5 \cdot 10^6$).

4 derinlik; ben bir hamle, rakip bir hamle, ben bir hamle, rakip bir hamle demektir. **4 kat ileriye bakış (4-ply lookahead) amatör bir insan seviyesidir.** Böyle bir makine amatörleri yenebilir, ama yıllarını bu işe vermiş usta (master) ya da büyük usta (grandmaster) seviyesindeki insanlarla baş edemez.

> **Ek bilgi (derste anlatılmadı):** Bu tür hesaplarda "ply" (kat), tek bir oyuncunun tek hamlesini ifade eder. Bu yüzden 4 kat, iki tam tur (beyaz-siyah, beyaz-siyah) demektir.

## 9. Alfa-beta budaması

Bu sınır algoritmik bir güzellikle bir ölçüde aşılır: **alfa-beta budaması**.

### 9.1 Fikir: Tüm durumları değerlendirmek gerekir mi?

Slayttaki küçük örnek (ekrandan, 01:00:00): MAX kökünün altında iki MIN düğümü var. İki derinliğe kadar gidilmiştir.

- DFS önce soldaki MIN düğümünün yapraklarını açar: 2 ve 7. Sol MIN düğümü $\min(2, 7) = 2$ olur.
- Sol düğüm 2 olunca kökün değeri kesinlikle $\geq 2$'dir; çünkü kök 2 ile başka bir şeyin maksimumunu alacaktır.
- Sağdaki MIN düğümünün ilk yaprağı 1 gelir. Sağ düğüm minimum alacağı için, ikinci yaprak ne olursa olsun, değeri $\leq 1$ olur.
- Kök $\geq 2$, sağ düğüm $\leq 1$ ise sağ yolun seçilme ihtimali kalmamıştır. O zaman sağ düğümün ikinci yaprağını değerlendirmenin de anlamı yoktur: **önemsizdir, seçilecek yolu etkilemez.**

Böylece dört tahta yerine üç tahta değerlendirilerek aynı karar verilmiş olur. Bu her zaman olmaz: sol yaprak 2 yerine 0 olsaydı, sol düğüm 0, kök $\geq 0$ olurdu. Sağ düğüm 1 olabileceği için ikinci yaprağa bakmak gerekirdi.

Tahtaları değerlendirmek zaman alır. Bazı tahtalara bakmadan aynı hamle yapılabiliyorsa artan zaman, daha derin arama için kullanılabilir. Örneğin 3 derinlikli bir arama, 2 derinlikli tam aramanın süresi kadar sürebilir.

Slayttaki tanımlar (ekrandan, 01:00:00):

- $\alpha$: Bir durumun alabileceği **minimum** değer.
- $\beta$: Bir durumun alabileceği **maksimum** değer.

### 9.2 Adım adım örnek

Minimax örneğindeki ağaç (yapraklar 3, 12, 8 | 2, 4, 6 | 14, 5, 2) bu kez alfa-beta ile işlenir (ekrandan, 01:05:00, 01:10:00 ve 01:15:00). Her düğümün yanına $[\alpha, \beta]$ yazılır. Başta hiçbir şey bilinmediği için hepsi $[-\infty, +\infty]$'dur. Algoritma DFS'tir ve iki derinliğe iner. Tahtalar üretilir, ama değerlendirme tek tek, sırayla yapılır.

1. İlk yaprak 3 değerlendirilir. Sol MIN düğümü $[-\infty, 3]$ olur: bu düğüm minimum alacağı için 3'ten büyük olamaz, ama alt sınırı henüz bilinmez. Kök için henüz bir şey söylenemez.
2. İkinci yaprak 12'dir. 3'ten büyük olduğu için hiçbir şey değişmez.
3. Üçüncü yaprak 8'dir. Sol MIN düğümünün bütün çocukları bilindiği için değeri kesinleşir: $[3, 3]$.
4. Kök MAX olduğu için artık 3'ten küçük olamaz: kök $[3, +\infty]$.
5. Ortadaki MIN düğümünün ilk yaprağı 2'dir. Düğüm $[-\infty, 2]$ olur.
6. Kökün aralığı $[3, +\infty]$ ile ortadaki düğümün aralığı $[-\infty, 2]$'nin kesişimi boştur. Bu yoldan 3'ü aşabilecek hiçbir şey gelmez. Ortadaki düğümün kalan iki yaprağı (slaytta X ile işaretli) değerlendirilmez. Slayttaki açıklama: "En küçük değer 3, altının en büyük değeri 2, o hâlde X ile işaretlilerin değerlerini bulmaya gerek yok; zaten alfa ve betayı değiştiremezler."
7. Sağdaki MIN düğümünün ilk yaprağı 14'tür; düğüm $[-\infty, 14]$ olur. Bu, kökün son çocuğudur; kök $\max(3, 2, \leq 14)$ olacağı için kök $[3, 14]$ olur.
8. İkinci yaprak 5'tir; sağ düğüm $[-\infty, 5]$, kök $[3, 5]$ olur. Kök ile sağ düğümün aralıkları hâlâ kesiştiği için devam edilir.
9. Üçüncü yaprak 2'dir; sağ düğüm 2 olur. Kök $\max(3, 2, 2) = 3$ olur ve $a_1$ hamlesi seçilir.

Slaytlarda ayrıca daha büyük bir ağaçta budamanın adım adım çözümü vardır; orada daha büyük dalların toptan budandığı görülür. Hoca bunu kendi başına adım adım izlemeyi önerir.

### 9.3 Soru-cevap: Kökün üst sınırı neden güncellendi?

**Soru:** İlk adımlarda kökün alt sınırını (minimumunu) güncelliyorduk: 3 bulununca $[3, +\infty]$ oldu, 12 ve 8'de hâlâ 3'tü. En sağdaki dalda ise kökün üst sınırını (14, sonra 5) güncelledik. Bu, son düğüm olduğunu bildiğimiz için mi?

**Cevap:** Evet. 8 bulununca sol MIN düğümünün başka çocuğu olmadığı bilindiği için doğrudan 3 yapılmıştı. Benzer biçimde sağ dal kökün son çocuğudur; başka bir hamle kalmadığı bilindiği için kökün üst sınırı güncellenebilir. Kökün altından başka dallar çıkabilseydi bu doğrudan yapılamazdı.

### 9.4 Etkisi

- Alfa-beta budaması satranç gibi bir oyunda karmaşıklığı $b^{m/2}$'ye kadar düşürebilir. Bu, **8 derinlikli aramanın 4 derinlikli arama kadar sürede** yapılabilmesi demektir.
- Budama **seçilen hamleyi etkilemez.** Derinliği değiştirmek seçilen hamleyi değiştirebilir; ama aynı derinlikte alfa-beta kullanmak ya da kullanmamak seçilen hamleyi değiştirmez.
- Aynı donanımla 4 kattan 8 kata çıkmak, satrançta usta seviyesindeki bir insana erişmek demektir.

> **Hocanın vurgusu:** Derinlik kararı değiştirir, alfa-beta budaması değiştirmez; yalnız aynı kararı çok daha hızlı verdirir.

> **Ek bilgi (derste anlatılmadı):** $b^{m/2}$ en iyi durumdur ve çocukların en iyi hamle önce gelecek biçimde sıralandığı varsayımıyla elde edilir. Rastgele sıralamada kazanç daha azdır, en kötü sıralamada hiç budama olmayabilir.

Alfa-beta'nın sözde kodu ve uygulaması slaytlarda vardır; hoca bunları incelemeyi öğrencilere bırakır.

## 10. Deterministik oyunlarda bilgisayarlar ve satranç tarihi

### 10.1 Oyunlarda durum

- **Dama:** Chinook adlı program 1994'te dünya şampiyonuyla başa baş oynadı; o günden beri damada bilgisayarlar insanlardan iyidir.
- **Satranç:** 1997'den beri bilgisayarlar daha iyidir.
- **Go:** İnsanlar üstünlüğü 2016'da kaybetti.

Satrançla Go arasındaki 19 yıllık farkın nedeni oyunun daha karmaşık olmasıdır, yani $b^m$'nin çok daha büyük olması. Go 19×19'luk bir tahtada oynanır; $b$ yaklaşık 250'dir. Her düğümden 250 dal çıkar; yalnız iki derinlik için bile $250^2$ durum vardır. Oyun derinliği de yaklaşık 150'dir (satrançta 40). Ağaç büyüklüğü $250^{150}$ mertebesindedir. Satranç için $32^{40}$ bile $10^{43}$ yıl tutuyordu. Daha karmaşık oyunlar da olabilir; zamanla büyük olasılıkla onlar da çözülecektir.

### 10.2 Bilgisayarla satranç tarihi

Slayttaki kronoloji (ekrandan, 01:20:00, slayt kenar küçük resminden; ekrandan, 01:25:00):

- **1957:** Newell ve Simon, 10 yıl içinde dünya satranç şampiyonunun bir bilgisayar olacağını tahmin etti. Tahmin tutmadı; bu ancak 40 yıl sonra oldu.
- **1958:** Satranç oynayan ilk bilgisayar programı, IBM 704 üzerinde.
- **1967:** MacHack programı, insanların katıldığı bir turnuvada başarıyla yarıştı.
- **1983:** Master unvanını kazanan ilk program (Belle).
- **1980'lerin ortası:** Sonradan Deep Blue'ya dönüşecek çalışma başladı.
- **1989:** Projeyi IBM devraldı.
- **11 Mayıs 1997:** Garry Kasparov, 6 oyunluk maçta Deep Blue'ya 3,5–2,5 yenildi: 2 oyunu Deep Blue, 1 oyunu Kasparov aldı, 3 oyun berabere bitti. Hoca bunun ezici bir sonuç olmadığını, ama bugün standart satrançta insanların bilgisayarlara karşı bir şansının olmadığını belirtir.

Slayttaki fotoğrafta Kasparov'un karşısında oturan kişiyle ilgili bir soru sorulur: bu kişi Deep Blue'nun hesapladığı hamleleri tahtaya yapan ve Kasparov'un hamlelerini bilgisayara giren bir **arayüzdür**, ekipten biridir.

### 10.3 Yöntemlerin tarihi

Slayttaki tablo (ekrandan, 01:20:00):

| Kim | Yöntem | Yıl |
|---|---|---|
| Shannon, Turing | Minimax arama | 1950 |
| Kotok / McCarthy | Alfa-beta budama | 1966 |
| MacHack | Dönüşüm tabloları | 1967 |
| Chess 3.0+ | Iterative deepening | 1975 |
| Belle | Özel donanım | 1978 |
| Cray Blitz | Paralel arama | 1983 |
| Hitech | Paralel değerlendirme | 1985 |
| Deep Blue | Yukarıdakilerin hepsi | 1997 |

1975'e kadar algoritmik yöntemler geliştirilir: minimax, alfa-beta, dönüşüm tabloları ve giderek daha derine bakmayı sağlayan iteratif derinleşme. Sonraki dönemde ilerleme **donanımsaldır.** En sonunda yalnız satranç tahtalarının değerlendirme fonksiyonunu hesaplamak için özel çipler tasarlanır. 1997'de Deep Blue, hem donanımsal hem algoritmik geliştirmeleri birleştirerek Kasparov'u yener.

> **Ek bilgi (derste anlatılmadı):** Dönüşüm tablosu (transposition table), farklı hamle sıralarıyla ulaşılan aynı tahtanın değerini bir karma (hash) tablosunda saklayıp yeniden hesaplamayı önleyen yapıdır.

### 10.4 Neden bu kadar çaba?

Fiziksel dünyada pek işe yaramayan bir program için 40 yıl süren bir uğraş neden yapıldı? Hocanın açıklaması: Satranç, insanlar arasında zekânın ölçütlerinden biri olarak görülür. Dünya satranç şampiyonunu yenen biri kesinlikle zeki sayılır. 40 yıl boyunca dünya şampiyonlarını yenme hedefi hep başarısız oldu ve bilgisayarların satrançta insanları asla yenemeyeceği yönünde bir yargı oluşmaya başladı. Bu da işi bir meydan okumaya dönüştürdü.

## 11. Şans içeren oyunlar: Expectiminimax

### 11.1 Şans düğümleri

İşin içine şans girdiğinde aynı yöntem kullanılabilir mi? Oyun ağacına bir düğüm türü daha eklenir. MIN ve MAX düğümlerine ek olarak **şans düğümleri** olur. Şans düğümünde gelebilecek zar, kâğıt vb. durumlar olasılıklarına göre dizilir.

Tavla örneği (ekrandan, 01:45:00, slayt kenar küçük resminden): İki zar atıldığında 21 farklı durum vardır: 6 aynı çift (1-1, 2-2, ...) ve 15 farklı çift. Her seviye için 21 şans düğümü olur. 1-1 gelme olasılığı $1/36$, 1-2 gelme olasılığı $1/18$'dir.

Ağaç şöyle kurulur: Bizim hamlelerimiz (MAX); her hamleden sonra rakibin atabileceği zarlar (şans); her zar sonucu için rakibin hamleleri (MIN); sonra bizim atacağımız zarlar ve bizim hamlelerimiz... Bir yerde durulur: bu ya terminal düğümdür (fayda kullanılır) ya da sınırlı derinlikli aramada kesim düğümüdür (değerlendirme fonksiyonu kullanılır). Algoritmanın adı **expectiminimax** olur.

### 11.2 Değer hesabı

MAX ve MIN düğümleri bildiğimiz gibidir. Şans düğümünde ise ardılların değerleri olasılıklarıyla çarpılıp toplanır. Örneğin bir şans düğümünün değeri

$$
\text{değer}(1\text{-}1)\cdot\tfrac{1}{36} + \text{değer}(1\text{-}2)\cdot\tfrac{1}{18} + \dots
$$

biçiminde bulunur. Slayttaki tanım (ekrandan, 01:45:00, slayt kenar küçük resminden):

$$
\text{EXPECTIMINIMAX}(n) =
\begin{cases}
\text{UTILITY}(n) & n \text{ oyun sonu (terminal) ise} \\
\max_{s \in \text{Ardıl}(n)} \text{EXPECTIMINIMAX}(s) & n \text{ MAX seviyesinde ise} \\
\min_{s \in \text{Ardıl}(n)} \text{EXPECTIMINIMAX}(s) & n \text{ MIN seviyesinde ise} \\
\sum_{s \in \text{Ardıl}(n)} P(s)\cdot \text{EXPECTIMINIMAX}(s) & n \text{ şans düğümü ise}
\end{cases}
$$

### 11.3 Örnek

Ekrandaki örnek (ekrandan, 01:45:00): Zar iki yüzlüdür, yani yazı tura gibidir; ama yüzler eşit olasılıklı değildir. Bir taraf ağırdır: bir yüzün gelme olasılığı 0,9, diğerininki 0,1'dir. Ben bir hamle yaparım (MAX), karşı taraf zar atar (şans), sonra karşı taraf hamle yapar (MIN) ve oyun biter. Yapraklar benim açımdan durum skorlarıdır:

| MAX hamlesi | Şans dalı (olasılık) | MIN yaprakları | MIN değeri |
|---|---|---|---|
| Sol | 0,9 | 2, 4 | 2 |
| Sol | 0,1 | 5, 3 | 3 |
| Sağ | 0,9 | 1, 1 | 1 |
| Sağ | 0,1 | 6, 4 | 4 |

- Sol şans düğümü: $2 \cdot 0{,}9 + 3 \cdot 0{,}1 = 1{,}8 + 0{,}3 = 2{,}1$.
- Sağ şans düğümü: $1 \cdot 0{,}9 + 4 \cdot 0{,}1 = 0{,}9 + 0{,}4 = 1{,}3$.
- MAX: $\max(2{,}1;\ 1{,}3) = 2{,}1$, yani sol hamle daha mantıklıdır.

Bütün mekanizma bundan ibarettir: işin içine şans girince minimax, expectiminimax'a dönüşür.

### 11.4 Karmaşıklık ve tavla

$b^m$'nin yanına bir de $n^m$ gelir. Burada $n$, şans faktörünün farklı sonuç sayısıdır (tavlada 21). Karmaşıklık $O(b^m n^m)$ olur ve çok artar.

Slayttaki özellikler ve tavla notu (ekrandan, 01:50:00, slayt kenar küçük resminden):

- Bütünlük: ağaç sonluysa evet. En iyi çözüm: evet (şans faktörü göz önünde olmalı).
- Zaman: $O(b^m n^m)$; bellek: $O(bm)$ (derinlemesine arama).
- Tavlada $b \approx 20$, $n = 21$; tam çözüm şimdiki şartlarda imkânsızdır, pratikte en fazla 3 seviye gidilebilir.
- **TD-Gammon** adlı program yalnız 2 derinlikli arama yapar, ama çok iyi bir değerlendirme fonksiyonu vardır. Sonuç: dünya şampiyonu seviyesi.

### 11.5 Soru-cevap: Tavla şampiyonu ile satranç şampiyonu

**Soru (hocadan):** Dünya satranç şampiyonuyla 100 maç yapsanız kaçını kazanırsınız? Dünya tavla şampiyonuyla 100 maç yapsanız kaçını kazanırsınız?

**Cevap:** Satrançta sıfır. Tavlada şansa bağlı olarak belki 10, 15 tane kazanılabilir. Tavlada dünya şampiyonu olmak her maçı kazanmak anlamına gelmez; satrançta ise şampiyona karşı hiçbir şans yoktur.

## 12. Tahmin ve öğrenme

Makineler sizinle oyun oynarken **size göre oynamayı** öğrenebilir: yaptığınız hareketlerdeki örüntüleri bulup kendi arama süreçlerini iyileştirmek için kullanabilirler. Slayttaki örnek (ekrandan, 01:50:00):

- Bilgisayar kullanıcının hareket kayıtlarını (log) tutabilir.
- Kullanıcının bir sonraki hareketini bu kayıtlara göre tahmin edebilir; tüm olasılıkları hesaba katmaya gerek kalmaz.
- Bu tahmine göre yapılacak en iyi hareketi yapabilir.

Önceki hareketler:

| Hareket dizisi | Sayı | Oran |
|---|---|---|
| Low Kick, Low Punch, Uppercut | 10 | %50 |
| Low Kick, Low Punch, Low Punch | 7 | %35 |
| Low Kick, Low Punch, Low Kick | 3 | %15 |

Şimdiki durum: Low Kick, Low Punch, ? Örnek oyun: Virtua Fighter 4 (iki kişilik dövüş oyunu).

**Soru (hocadan):** Makine bu istatistikleri oyun ağacında, arama stratejisini iyileştirmek için nasıl kullanabilir?

**Cevap:** Öğrencilerden gelen cevaplar: bir sonraki adıma karşı atak yapmak; zardaki gibi her hareketin yapılma olasılığını bir oran olarak vermek. Hocanın vurguladığı strateji: Rakibin yapma olasılığı yüksek hamlenin altındaki ağaç daha derin aranır, olasılığı düşük hamlenin altı daha sığ aranır. Arama derinlikleri öğrenilen istatistiklere göre ayarlanır. Makine böylece oyunu genel olarak oynamanın ötesinde, size karşı oynamayı öğrenir. İnsanlar da bunu yapar.

## 13. Değerlendirme fonksiyonunu öğrenmek ve kendi kendine oynamak

### 13.1 Deep Blue: uzman bilgisinden öğrenme

Deep Blue'nun değerlendirme fonksiyonu (ekrandan, 01:55:00, slayt kenar küçük resminden):

$$
f(p) = w_1 f_1(p) + w_2 f_2(p) + \dots + w_n f_n(p)
$$

Burada $p$ bir tahtadır. $f$'ler (tahtanın kontrolü, taş puanlarına göre avantaj vb.) insan uzmanlar tarafından belirlenmiştir. $w$ ağırlıklarını ise Deep Blue öğrenmiştir. Nasıl?

Satranç tarihi çok eskilere uzanır ve çok iyi oyuncuların oynadığı binlerce, belki on binlerce oyunun kaydı vardır. Slayttaki açıklama (ekrandan, 01:55:00, slayt kenar küçük resminden):

- Büyük usta seviyesindeki oyuncuların 1000'den fazla oyunundaki her hamlenin yer aldığı bir "şu durumda şunu yaptı" veri tabanı kurulur.
- Tüm hamleler için, önceki durumdan gidilebilecek tüm durumlar içinde yapılan hamlenin (veri tabanında yer alanın) seçileceği, yani $f(p)$'si en büyük olacağı biçimde $w$'ler düzenlenir.

Veri tabanında Kasparov'un da birçok oyunu vardır. Mühendisler, satrancı çok iyi oynayan insanların oyunlarını taklit etmeye çalışmıştır. Bu, **uzman bilgisini kullanma** yaklaşımıdır.

### 13.2 Kendi kendine oynamak (self-play)

İkinci yaklaşım kendi kendine oynamaktır (ekrandan, 01:55:00). Bunun AlphaGo ve AlphaZero gibi örnekleri ve belgeselleri vardır. Bu yaklaşımda oyunu iyi oynayan uzmanların bilgisinden hiç yararlanılmaz. Makineye yalnız oyunun kuralları ve hangi durumda kazanıp kaybedileceği verilir. Uzmanların ne yaptığı ya da değerlendirme fonksiyonunda hangi $f$'lerin olması gerektiği gibi hiçbir bilgi verilmez.

Slayttaki özet:

- Monte Carlo Tree Search.
- Yapılacak hamleyi seçerken rastgele hareketlerle oyun sonuna kadar ilerler. Oyunun sonucuna göre yaptığı hamleyi değerlendirir.

## 14. Monte Carlo Ağaç Araması

### 14.1 Fikir

Slayttaki notlar (ekrandan, 02:00:00, slayt kenar küçük resminden):

- 2006 başlarında Go ile popüler olmaya başladı.
- Büyük arama uzayları için tasarlanmıştır.
- Sınırlı bir derinlikteki her olasılığı denemek yerine oyun bitene kadar rastgele hamleler üretir.

Önceki yöntemlerde bir derinlik belirlenir ve o derinlik için mükemmel hamle aranır. Monte Carlo ağaç aramasında ise oyun bitene kadar rastgele hamlelerle ilerlenir. Kendi kendine oynandığı için karşı taraf da sizsiniz: siz rastgele oynarsınız, karşı taraf da rastgele oynar ve oyun sonunda biter.

Rastgele oyundan ne öğrenilir? Bir hamle yapılır ve sonrası tamamen rastgele oynanır. Bu 1000 kez yapılır:

- 700 kazanç, 300 kayıp: bu hamlede bir şey vardır (iyidir).
- 550 kazanç, 450 kayıp: belirgin bir şey yoktur.
- 300 kazanç, 700 kayıp: yine bir şey vardır (kötüdür).

Monte Carlo yöntemi zaten saymaya dayanır. Arama ağacında kullanıldığında, defalarca rastgele oyun oynanıp çıkarılan istatistik hamlenin iyiliğini belirlemek için kullanılır.

### 14.2 Dört adım

Slayttaki şekil (ekrandan, 02:00:00): A durumundayız ve yapabileceğimiz 3 hareket var; hangisini yapmak iyi? Döngü sürekli tekrarlanır:

1. **Seçim (Selection):** Ağaçta kökten aşağı doğru bir yol seçilir (örnekte A → B → G).
2. **Genişletme (Expansion):** Seçilen düğüme yeni bir çocuk eklenir (G'den yapılabilecek J hamlesi).
3. **Simülasyon (Simulation):** J'den oyun bitene kadar rastgele hamlelerle oynanır.
4. **Geri yayılım (Back propagation):** Oyunun sonucu yukarıya kadar yayılır (J → G → B → A).

Her düğüm kaç oyun oynandığını ve kaçının kazanıldığını tutar. Başta küçük bir derinlik seçilir (örnekte 2). J hamlesinin iyi olup olmadığını anlamak için oyun bitene kadar tamamen rastgele, binlerce kez oynanır. "J'yi yapınca 700 kez kazandım, 300 kez kaybettim" bilgisi yukarı yayılır: G'nin iyiliğini, o da B'nin iyiliğini, o da A'dan B'ye gitmenin iyiliğini etkiler.

### 14.3 Neden hızlı ve paralelleştirilebilir?

Simülasyonda hiçbir değerlendirme fonksiyonu yoktur ve iyi hamle yapma çabası yoktur. Grafik gibi şeylere de gerek yoktur; arka planda yalnız tahtalar vardır. Bu yüzden oyunlar çok hızlı üretilir.

Simülasyonlar birbirini beklemez ve tetiklemez. Bu yüzden binlerce CPU ya da GPU'ya kolayca dağıtılabilir. Slaytta da MCTS'nin oyun algoritmalarında temel yaklaşım olduğu ve kolayca (kökten ya da yapraktan) paralelleştirilebildiği yazılıdır (ekrandan, 02:05:00, slayt kenar küçük resminden). Hoca, seçim adımının ayrıntısının (slayttaki bir sonraki sayfa) bu ders için çok kritik olmadığını söyler.

## 15. Tartışma: Makineler satrançta neyi başarıyor?

### 15.1 İki görüş

Slayttaki "Sorular" sayfası (ekrandan, 02:05:00):

- Bir görüşe göre Deep Blue'nun yaptığı şey, tasarımcıların fikirlerini büyük hesap kabiliyetiyle uygulamaktır. Yenen, tasarımcılar ve teknolojidir. Yapılan yalnız özel bir hesap makinesidir.
- Deep Blue ekibinden Drew McDermott: "Deep Blue'nun gerçekte satrançtan anlamadığını söylemek, bir uçağın kanatlarını çırpmadığı için uçmadığını söylemeye benzer."

McDermott'ın anlatmak istediği şudur: Bir probleme illa doğadaki çözümünü kullanarak yaklaşmak şart değildir; ondan farklı, belki daha iyi çözümler bulunabilir. Deep Blue, AlphaGo ya da AlphaZero oyunu insanlar gibi oynamaz. Kasparov kafasında dev bir arama ağacı kurmaz, milyonlarca rastgele simülasyon da yapmaz. Ama makineler daha iyi oynar. Kuşlar kanat çırparak uçar, uçak çırpmaz; ama uçar ve kuşlardan hızlı uçar. Derdimiz problemin kendisini çözmekse oraya takılmamak gerekir.

### 15.2 Uzaylılar sorusu

**Soru (ekrandan, 02:05:00):** Uzaylılar dünyaya gelip satrançta meydan okusa: kazanırlarsa dünyayı yok edecekler, kaybederlerse gidecekler. Kapışmaya Deep Blue'yu mu, Kasparov'u mu gönderirdiniz?

**Cevap (sınıf tartışması):**

- Bir öğrenci: Elimizde silah varken savaşa yumrukla gitmek gibi olur; Deep Blue da bizim ürünümüzdür, onu göndermek daha mantıklıdır.
- Bir başka öğrenci: Deep Blue'yu gönderirdim, çünkü daha iyidir.
- Bir başka öğrenci: Deep Blue insanların oyunlarından öğrendiyse ve uzaylılar başka tekniklerle oynuyorsa, Kasparov onlara daha hızlı uyum sağlayabilir.
- Hoca bu itirazın doğru olabileceğini söyler ve soruyu değiştirir: Deep Blue yerine, içinde hiç insan bilgisi olmayan AlphaZero olsun. Öğrenci bu durumda makineye daha çok güveneceğini, çünkü onun oyunu insanlardan bağımsız çözdüğünü söyler.

### 15.3 Deep Thought kaleyi aldı

Deep Thought, Deep Blue'nun önceki sürümüdür; büyük usta seviyesindeki insanları yenmiş bir satranç motorudur. Slayttaki tahtada (ekrandan, 02:15:00) oyun sırası beyazdadır ve Deep Thought beyazdır. Deep Thought bir piyonla siyahın kalesini alır.

Tahtada beyaz piyonlar bir **baraj** oluşturmuştur. Beyaz bu barajı bozmazsa siyah taşlar öbür tarafa geçemez. Ama kaleyi alan hamle barajı yıkar ve siyah birlikler geçip oyunu kesinlikle kazanır. Bu çok büyük bir hatadır; amatör bir insan bile böyle bir hata yapmaz. Ama Deep Thought yapar.

Slayttaki çözüm önerisi: **yeni bir $f$ eklemek** (örneğin "barajı bozma"). İkinci tahtada (ekrandan, 02:10:00, "Deep Thought kaleyi yine aldı!") henüz baraj yoktur; barajın oluşmasından bir an öncesidir. Fil doğru kareye konursa baraj kurulur ve oyun beraberliğe götürülebilir. O zaman "barajı oluşturma" için de bir $f$ gerekir. Slayttaki soru: **Nereye kadar?**

Bu tahtalar standart bir satranç maçında karşılaşılacak tahtalar değildir; satranç problemleridir, gerçek oyunda oluşamayacak ütopik tahtalardır. Sistem gerçek satrançta oluşabilecek durumları ya da onlara benzeyenleri görmüş geçirmiştir, ama böyle yepyeni bir tahtada ne yapacağına dair bir şey bilmez. Ayrıca kötü sonu görebilmek için arama derinliğinin fazla olması gerekir. Oysa Kasparov, hatta amatör bir satranççı böyle bir tahtayı hiç görmemiş olsa bile bu hatayı yapmaz.

### 15.4 Uyum kabiliyeti

Uzaylılar sorusuna geri dönülür: AlphaZero gönderilmiş olsun. Uzaylılar, kendi satrançlarının 8×8 değil 16×16 tahtada ve farklı taşlarla oynandığını söylese, AlphaZero'yu gönderdiğinize pişman olur muydunuz?

- Bir öğrenci pişman olunacağını söyler, çünkü AlphaZero bu oyunu öğrenmemiştir.
- Kasparov'un 16×16'lık oyuna uyum sağlaması çok daha kolay olurdu. Bir ay süre verilse makineyi o oyunda eğitmek makul olabilirdi; ama oyun beş dakika içinde başlayacaksa sıradan bir insanın bile uyum kabiliyeti çok daha yüksektir.

**Soru:** En yüksek IQ'lu insanların çoğunun satranççı olduğunu duymuştum. Bizdeki yüksek IQ ilk kez karşılaşılan durumlara hızlı uyum sağlamayı mümkün kılarken, makinelerdeki öğrenme yalnız bir oyunda, bir alanda uzmanlaşma gibi mi?

**Cevap:** Evet, kastedilen uyum kabiliyetidir: yepyeni bir durumda saçma davranmamak ve o duruma hızla uyum sağlamak. Son dönemdeki bazı yaklaşımlarla belli uyum kabiliyetleri sağlanabilmektedir, ama bu kabiliyetin kapsamı şimdilik çok geniş görünmüyor. Şu anda uyum açısından insanlar çok daha iyidir.

Pekiştirmeli öğrenme (reinforcement learning) de bugün oyunlarda kullanılan temel yaklaşımlardan biridir; bu slaytlarda yoktur, dersin makine öğrenmesi kısmında ele alınacaktır.

### 15.5 Soru-cevap: Örnek verimliliği

**Soru:** İnsanların tek bir olaydan neden daha fazla çıkarım yaptığı üzerine çalışmalar var mı? İnsanlar milyonlarca oyun oynamadan çok şey öğreniyor; makineler de böyle öğrenebilir mi?

**Cevap:** Var. Buna **örnek verimliliği (sample efficiency)** denir. Bir insanın bir kediyi tanıması için milyonlarca kedi resmi görmesi, satrancı iyi oynaması için milyonlarca oyun oynaması gerekmez. Bunu neyin sağladığı üzerine çok sağlam çalışmalar vardır, ama sorun henüz çözülmüş değildir.

## Örnek Sorular

**1. Tic-tac-toe oyun ağacında dallanma** (derste sözlü, 00:11:07)

Boş tahtada X'in 9 hamlesi var. Bir sonraki seviyede her düğümden kaç dal çıkar? Ondan sonraki seviyede kaç?

> **Çözüm:** Her X hamlesinden sonra O için 8 boş kare kalır, yani 8 dal çıkar. Bir sonraki seviyede 7 dal çıkar.

**2. Terminal düğümlerin seviyesi** (derste sözlü, 00:12:10)

Slayttaki üç terminal tahta yan yana çizilmiş. Hepsi ağacın aynı seviyesinde mi?

> **Çözüm:** Hayır. Oyun her zaman aynı hamle sayısında bitmez; terminal düğümler farklı seviyelerdedir. Tic-tac-toe ağacı en fazla 9 seviye derin olabilir.

**3. Minimax değeri** (ekrandan, 00:15:00)

MAX kökünün üç hamlesi var: $a_1$, $a_2$, $a_3$. Altlarındaki MIN düğümlerinin yaprakları sırasıyla (3, 12, 8), (2, 4, 6), (14, 5, 2). Kökün değeri ve seçilecek hamle nedir? $a_3$ yapılırsa rakip hangi hamleyi yapar?

> **Çözüm:** MIN değerleri $\min(3,12,8)=3$, $\min(2,4,6)=2$, $\min(14,5,2)=2$. Kök $\max(3,2,2)=3$; seçilen hamle $a_1$. $a_3$ yapılırsa rakip, bizim açımızdan en kötü sonucu veren $d_3$'ü (değer 2) yapar.

**4. Arama sürecini kısaltmak** (derste sözlü, 00:25:48)

Minimax satrançta kullanılamıyorsa, arama sürecini kısaltmak için daha önce hangi yaklaşımı kullanıyorduk?

> **Çözüm:** Sezgisel yöntemler. Oyunlarda bunun karşılığı, terminal olmayan bir tahtanın iyiliğini tahmin eden değerlendirme fonksiyonudur.

**5. Tic-tac-toe ilk hamlesi** (ekrandan, 00:35:00)

$E(n)$ = X'in açık çizgileri − O'nun açık çizgileri fonksiyonuyla, boş tahtadan 2 derinlikli minimax aramasında X'in ilk hamlesi ne olmalı?

> **Çözüm:** Köşe hamlesinin çocukları 1, 0, 1, 0, −1; MIN değeri −1. Kenar hamlesinin çocukları −1, 0, −1, 0, −2; MIN değeri −2. Orta hamlesinin çocukları 1, 2; MIN değeri 1. $\max(-1,-2,1)=1$, yani X ortaya konur. (Değerler python ile bütün O cevapları sayılarak doğrulandı.)

**6. Ufuk etkisi** (ekrandan, 00:55:00)

c2'deki beyaz kale a2'deki siyah piyonu almalı mı? Taş puanlarıyla 1, 2, 3 ve 4 derinlikte arama yapıldığında karar nedir?

> **Çözüm:** 1 derinlik: bir piyon kazanç, alır. 2 derinlik: bir piyona bir kale değmez, almaz. 3 derinlik: bir piyon + bir kaleye bir kale değer, alır. 4 derinlik: bir piyon + bir kaleye iki kale değmez, almaz.

**7. Donanımın izin verdiği derinlik** (derste sözlü, 00:55:22)

Hamle süresi 100 saniye, saniyede $10^4$ düğüm incelenebiliyor ve $b = 35$. Kaç kat ileri bakılabilir?

> **Çözüm:** $100 \cdot 10^4 = 10^6$ düğüm. $35^m \approx 10^6$ için $m = 4$ ($35^4 \approx 1{,}5\cdot 10^6$). 4 kat ileriye bakış amatör seviyesidir.

**8. Budama her zaman olur mu?** (derste sözlü, 01:00:14)

Alfa-beta'nın ilk örneğinde (sol MIN düğümünün yaprakları 2 ve 7, sağ MIN düğümünün ilk yaprağı 1) sol yaprak 2 yerine 0 olsaydı, sağ düğümün ikinci yaprağına bakmak gerekir miydi?

> **Çözüm:** Evet. Sol düğüm 0 olur ve kök $\geq 0$ olur. Sağ düğüm $\leq 1$'dir ve 1 olabilir; bu durumda sağ yol seçilebilir. Aralıklar kesiştiği için budama yapılamaz.

**9. Alfa-beta budama örneği** (ekrandan, 01:15:00)

Soru 3'teki ağacı alfa-beta ile soldan sağa işleyin. Hangi yapraklar budanır, kökün değeri nedir?

> **Çözüm:** Sol düğüm 3 olur, kök $[3, +\infty]$. Orta düğümün ilk yaprağı 2 gelince orta düğüm $[-\infty, 2]$ olur; kesişim boş olduğu için orta düğümün kalan iki yaprağı (4 ve 6) budanır. Sağ düğüm 14, 5, 2 ile sırayla $[-\infty,14]$, $[-\infty,5]$ ve 2 olur. Kök 3, seçilen hamle $a_1$.

**10. Expectiminimax örneği** (ekrandan, 01:45:00)

Şans düğümlerinde olasılıklar 0,9 ve 0,1. Yapraklar soldan sağa 2, 4 | 5, 3 | 1, 1 | 6, 4. MAX hangi hamleyi seçer?

> **Çözüm:** MIN değerleri 2, 3, 1, 4. Sol şans düğümü $0{,}9\cdot 2 + 0{,}1\cdot 3 = 2{,}1$; sağ şans düğümü $0{,}9\cdot 1 + 0{,}1\cdot 4 = 1{,}3$. MAX sol hamleyi seçer (2,1).

**11. Tavla ve satranç şampiyonları** (derste sözlü, 01:47:46)

Dünya satranç şampiyonuyla ve dünya tavla şampiyonuyla 100'er maç yapsanız kaçını kazanırsınız?

> **Çözüm:** Satrançta sıfır. Tavlada şans faktörü yüzünden birkaç, belki 10-15 maç kazanılabilir.

**12. Hamle istatistiğinin kullanımı** (ekrandan, 01:50:00)

Rakip Low Kick, Low Punch'tan sonra %50 Uppercut, %35 Low Punch, %15 Low Kick yapıyor. Bu bilgi oyun ağacında aramayı iyileştirmek için nasıl kullanılabilir?

> **Çözüm:** Olasılığı yüksek hamlenin (Uppercut) altındaki ağaç daha derin, olasılığı düşük hamlelerin altı daha sığ aranır. Böylece makine rakibe karşı oynamayı öğrenir.

**13. Uzaylılar sorusu** (ekrandan, 02:05:00)

Uzaylılar satrançta meydan okusa, kapışmaya Deep Blue'yu mu Kasparov'u mu gönderirdiniz? Oyun 16×16'lık bir tahtada, farklı taşlarla oynanacaksa cevabınız değişir mi?

> **Çözüm:** Derste tek bir doğru cevap verilmedi; tartışma sorusudur. Standart satrançta makineyi göndermek mantıklı görünür. Kurallar bilinmeyen biçimde değişirse insanın uyum kabiliyeti çok daha yüksek olduğu için Kasparov daha avantajlıdır.

## Dersin Toparlaması

Bu derste arama konusu oyunlarla tamamlandı. İki oyunculu deterministik oyunlarda temel yapı oyun ağacıdır. Minimax, rakibin de kazanmak için oynadığı varsayımıyla MAX seviyelerinde maksimumu, MIN seviyelerinde minimumu alır ve ağacın tamamı varsa optimaldir. Satranç gibi oyunlarda ağacın büyüklüğü ($\approx 10^{60}$) bunu imkânsız kılar. Bu yüzden arama sınırlı bir derinlikte kesilir ve tahtalar, önceki haftalardaki sezgisel fonksiyonların karşılığı olan bir değerlendirme fonksiyonuyla puanlanır. Derinliğin kararı değiştirebildiği (ufuk etkisi) görüldü. Alfa-beta budamasının ise kararı değiştirmeden aynı sürede yaklaşık iki kat derine inmeyi sağladığı gösterildi.

Şans içeren oyunlarda şans düğümleri eklenir ve minimax, olasılıkla ağırlıklı ortalama alan expectiminimax'a dönüşür. Son bölümde değerlendirme fonksiyonunun ağırlıklarının uzman oyunlarından öğrenilmesi (Deep Blue), yalnız kurallarla kendi kendine oynama ve Monte Carlo ağaç araması (AlphaGo, AlphaZero) karşılaştırıldı. Makinelerin belirli oyunlarda insanları geçtiği, ama yeni durumlara uyum sağlamada insanların hâlâ çok önde olduğu tartışıldı. Oyunlarda bugün yaygın kullanılan pekiştirmeli öğrenme, dersin makine öğrenmesi kısmında ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
