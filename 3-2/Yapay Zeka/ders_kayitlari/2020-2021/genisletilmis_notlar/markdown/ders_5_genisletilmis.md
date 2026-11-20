# Ders 5 Genişletilmiş Notu: Lokal (Yerel) Arama Algoritmaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kör ve Sezgisel Aramayı Hatırlamak: Ne İster, Ne Verir?
- 2. Lokal Aramanın Farkı
- 3. n-Vezir Problemi ve Durumdan Durum Üretmek
- 4. Tepe Tırmanma Algoritması
- 5. Lokal Maksimum, Plato ve Sırt
- 6. 8-Vezir Problemini Tepe Tırmanmayla Çözmek
- 7. Tepe Tırmanmanın 8-Vezirdeki Performansı
- 8. Birinci Alternatif: Rastgele Yeniden Başlatma
- 9. İkinci Alternatif: Benzetimli Tavlama
- 10. Üçüncü Alternatif: Paralel Tepe Tırmanma
- 11. Bozuk TV ve Kasa: Sezginin Değeri
- 12. Ayrık ve Sürekli Uzaylar, Eğim Düşme
- 13. Uygulama: Robot Süpürgeyle Alan Tarama
- Örnek Sorular
- Dersin Toparlaması

## 1. Kör ve Sezgisel Aramayı Hatırlamak: Ne İster, Ne Verir?

Hoca derse, şimdiye kadar görülen iki arama ailesini, kör (bilgisiz) aramayı ve sezgisel aramayı, girdileri ve çıktıları açısından yeniden kurarak başladı. Bunu öğrencilere sorarak slayta madde madde yazdı (ekrandan, 00:10:00 ve 00:15:00).

Her yöntemin ortak bir ön koşulu vardır: durumların nasıl temsil edileceğine karar verilmiş olmalıdır. Bu her yerde ortak olduğu için listeye ayrıca yazılmadı. Bunun dışında kör arama algoritmalarının ihtiyaç duyduğu şeyler şunlardır:

- Başlangıç durumu
- Bitiş durumu
- Durumlar arası geçişler (hangi durumdan hangi duruma gidilebildiği)
- Geçişlerin maliyetleri

Sezgisel arama algoritmaları bunların hepsine ek olarak bir şey daha ister: **durumların hedefe olan uzaklıklarını tahmin eden bir fonksiyon.** Bir öğrenci önce "kuş uçuşu mesafe" dedi; hoca bunu genelleştirdi. Bir durumun hedefe gerçek uzaklığı bilinemez, yalnızca tahmin edilebilir. Gerçek uzaklık bilinseydi problem zaten çözülmüş olurdu.

Peki bu iki aile çıkış olarak ne verir? Bir öğrencinin cevabıyla: başlangıç durumundan bitiş durumuna gitmek için gereken yolu. Slayttaki ifadesiyle kör ve sezgisel arama algoritmalarının çıkışı, **başlangıç ve bitiş arasındaki yol ve maliyetidir.**

## 2. Lokal Aramanın Farkı

Bu dersin konusu olan lokal (yerel) arama algoritmaları, bu iki aileden çok temel bir noktada ayrılır. Hoca lokal arama için gerekenleri de listeledi (ekrandan, 00:15:00):

- Başlangıç durumu
- Durumlar arası geçişler
- Geçişlerin maliyetleri
- Durumların hedefe olan uzaklıklarını tahmin eden fonksiyon

Sonra öğrencilere "burada ne yazmadım?" diye sordu. Eksik olan **bitiş durumudur.** Lokal arama algoritmalarının çıkışı ise yalnızca **bitiş durumudur**; bir yol dönmezler.

Bu tür problemler şöyle verilir. Bir başlangıç durumu söylenebilir ya da başlanabilecek yerlere dair bir kriter verilir. Hedefe dair belli özellikler, yani bir durumun hedefe yakınlığını tahmin etmeye yarayan kurallar ya da bir fonksiyon verilir. Ama hedefin ne olduğu söylenmez. Kullanıcı "başlangıçtan buraya nasıl geldin" diye sormaz; "bana şu şu özellikleri sağlayan bir durum söyle" der. Bu durumu kendisi de bilmez; bilseydi problem olmazdı.

Slayttaki tanımla: birçok optimizasyon probleminde hedefe giden yol, yani uygulanan hareketler önemsizdir; hedef durumun kendisi istenen çözümdür. Amaç, arama uzayında istenen kısıtlara, özelliklere sahip ya da fayda fonksiyonunu en büyük yapan durumu bulmaktır.

Lokal arama algoritmaları çok basittir. Hafızada yalnızca mevcut durum tutulur ve bu durum düzeltilmeye çalışılır. Mevcut durumdan gidilebilecek durumlara bakılır, birine geçilir ya da "en iyi yerdeyiz" denip durulur. Süreç, bir başlangıçtan başlayıp adım adım iyileştirmedir. Çıkışta süreç hakkında bir şey söylemek gerekmez. Bu basitlik sayesinde hafıza gereksinimi çok azdır: en fazla mevcut durumdan gidilebilecek durumlar geçici olarak tutulur, sonra onlar da silinir.

## 3. n-Vezir Problemi ve Durumdan Durum Üretmek

Lokal aramanın klasik örneği n-vezir problemidir (ekrandan, 00:20:00): N veziri $n \times n$'lik bir satranç tahtasına hiçbiri diğerini tehdit etmeyecek şekilde yerleştirin. Yani hiçbir satır, sütun ve diyagonalde birden fazla vezir olmamalıdır. Klasik satranç tahtası için bu 8-vezir problemidir.

Bu problemde bize ne bir başlangıç ne de hedef söylenir; hedefin kendisini bulmamız istenir. Sonunda kullanıcıya "işte, söylediğin özelliği sağlayan, hiçbir vezir çiftinin birbirini tehdit etmediği bir tahta" deriz. "Buraya şu yolu izleyerek geldim" demek gerekmez; kullanıcı bununla ilgilenmez.

Lokal arama için iki tasarım kararı gerekir:

- **Başlangıç kuralı:** Her sütuna rastgele bir yere bir vezir koyalım.
- **Geçiş kuralı:** Bir durumdan yeni durumlar nasıl üretilecek? Her adımda yalnızca tek bir vezir hareket etsin ve kendi sütununda istediği yere gidebilsin.

Hoca 4-vezir tahtasında bir durumdan kaç yeni durum çıkacağını sordu. Bir öğrenci "dört" dedi; doğru değildi. Birinci sütundaki vezirin gidebileceği 3 yer vardır (bulunduğu hücre hariç), ikincisinin de 3, üçüncüsünün de 3, dördüncüsünün de 3. Toplam $4 \times 3 = 12$ yeni durum çıkar. Bu 12 durum üretilir, her birinin iyiliği bir şekilde ölçülür, en iyisi seçilir ve oraya geçilir. Yeni durumdan da yine 12 durum çıkar. Süreç, artık iyileşme sağlanamayana kadar devam eder. Bu sürecin temelindeki algoritmanın adı **tepe tırmanma**dır.

## 4. Tepe Tırmanma Algoritması

### 4.1 Sezgi: iki boyutlu bir tepe

Hoca iki boyutlu bir tepe çizdi (ekrandan, 00:25:00). x ekseni durumları gösterir. y ekseninin ne olduğunu öğrencilere sordu ve bunun $f(n) = g(n) + h(n)$ ifadesindeki $h$ olduğunu hatırlattı. Öğrenciler "hedefe olan uzaklık" dediğinde hoca ısrarla düzeltti: $h$, **hedefe olan uzaklığın tahminidir**; uzaklığın kendisini bilemeyiz.

> **Hocanın vurgusu:** $h$ hedefe olan uzaklık değil, hedefe olan uzaklığın **tahminidir.** Uzaklığın kendisini bilseydik problemi çözmüş olurduk.

Bu çizimde yukarı çıkmak istediğimiz için bir öğrenci, y ekseninin uzaklık değil yakınlık olması gerektiğini söyledi. Hoca bunu kabul etti ve ekseni "hedefe olan tahmini yakınlık" diye düzeltti (ekrandan, 00:30:00). Tepe tırmanmayı çukur inme problemine dönüştürmek zor değildir; işaret değiştirerek her minimizasyon bir maksimizasyona çevrilebilir.

Çizimde bir noktadan başlıyoruz ve iki hareketimiz var: sağa ya da sola sabit büyüklükte bir adım. Yani mevcut durumdan iki yeni durum çıkar. Hangisi daha yüksekse onu seçeriz. Seçtiğimiz yere geçince yine iki komşuya bakar, yine yükseltene gideriz. Bu, adım adım tepeye doğru tırmanır. Öyle bir yere geliriz ki hiçbir hareket bizi daha da iyileştiremez: bir yöne gidersek aynı kalırız ya da düşeriz. O zaman algoritma "hedefe tahmini olarak en yakın durumu buldum" der ve durur. Tepenin diğer yamacından başlasaydık sola doğru ilerleyip aynı tepede bitirecektik.

### 4.2 Sisli dağ benzetmesi

Hoca algoritmanın mantığını bir dağcı benzetmesiyle anlattı. Sizi Everest'in bir kenarına bırakmışlar ve elinizde yalnızca bulunduğunuz noktanın deniz seviyesinden yüksekliğini ölçen bir cihaz var. Tek zirveli, aşağıdan bakınca zirvesi görünen bir dağda zirvenin hangi yönde olduğunu bilirsiniz ve oraya doğru yürürsünüz. Gerçekte ise yükseldikçe hava sislenir, kar ve fırtına başlar. Algılama alanınız bulunduğunuz yerin çevresiyle sınırlıdır; "en yüksek zirve şurası, oraya gideyim" deme şansınız yoktur.

Ne yaparsınız? Her yöne birer adım atar, her adımda cihazla ölçüm yaparsınız. Ölçümlerin en yükseği bulunduğunuz yerden yüksekse oraya gidersiniz. Bulunduğunuz yer çevresindeki her şeyden yüksek ya da onlara eşitse durursunuz. Tepe tırmanmanın temel mantığı budur. Slayttaki ifadesiyle: yoğun bir siste Everest'e tırmanmaya benzer; yalnızca etkin durum bilgisini tutar; ana düşünce, her zaman şimdiki durumu en fazla geliştiren yönde adım atmaktır. Bu yönüyle best-first search'e benzer.

Hoca, yapay sinir ağlarında ve onların derin hallerinde temel olarak kullanılan algoritmanın da tepe tırmanma ya da yokuş inme olduğunu söyledi. Bir şeyi maksimize etmek istiyorsanız tepe tırmanma, minimize etmek istiyorsanız yokuş inme kullanırsınız; ikincisinde bir yerden başlayıp fonksiyonun en derin yerine doğru gidersiniz.

### 4.3 Algoritma

Slayttaki sözde kod (ekrandan, 00:45:00):

```text
function HILL-CLIMBING( problem) return a state that is a local maximum
  input: problem, a problem
  local variables: current, a node.
                   neighbor, a node.

  current <- MAKE-NODE(INITIAL-STATE[problem])
  loop do
    neighbor <- a highest valued successor of current
    if VALUE[neighbor] <= VALUE[current] then return STATE[current]
    current <- neighbor
```

Hoca kodu satır satır okudu. `current` başlangıç durumundan bir düğümdür. Döngünün her turunda mevcut durumun bütün ardılları (successor) üretilir ve değerleri, yani $h$ değerleri (hedefe yakınlıkları) hesaplanır. Bunların en yüksek değerlisine `neighbor` denir. Ardılların en iyisi bile mevcut durumu iyileştiremiyorsa, yani `current`'ın değeri `neighbor`'ınkinden büyük ya da eşitse, diğerleri hiç iyileştiremez; mevcut durum döndürülür. Değilse `neighbor` yeni `current` olur ve döngü sürer. Kuyruk ya da yığın, başa veya sona ekleme gibi işler yoktur; algoritma oldukça basittir.

Fonksiyonun başlığı da önemlidir: algoritma **mutlaka bir lokal maksimum** döner. Lokal maksimum, kendi dar alanında en büyük olan durumdur. Global maksimum, bütün durumlar arasında en büyük olandır ve aynı zamanda bir lokal maksimumdur. Algoritma her zaman bir lokal maksimum döner ama onun global olup olmadığını bilmez.

## 5. Lokal Maksimum, Plato ve Sırt

### 5.1 Sonuç başlangıca bağlıdır

Hoca bu kez birden fazla tepesi olan bir eğri çizdi (ekrandan, 00:35:00). Bir noktadan başlayınca ortadaki bir tepeye varılır ve algoritma "zirvedeyim" der. O nokta gerçekten bir zirvedir, ama en yüksek zirve midir? Bir öğrenci bunu bilmek için her yeri gezmek gerektiğini söyledi. Hoca, arama algoritmalarını zaten arama uzayı çok büyük olduğu, bütün durumları gezemediğimiz için geliştirdiğimizi hatırlattı. Tepe tırmanma bir yaklaşımdır, ama global maksimumu (ya da minimumu) bulmayı **garanti etmez.**

Neden garanti etmez? Çünkü varılacak yer başlangıç noktasına bağlıdır. Hoca eğrinin altını renkli bölgelere ayırdı (ekrandan, 00:40:00): yeşil bölgeden başlayan yeşil tepeye, pembe bölgeden başlayan pembe tepeye, turuncu bölgeden başlayan turuncu tepeye çıkar. Algoritma kendisinin lokal bir maksimumda mı yoksa global bir maksimumda mı olduğunu bilemez; bir yerden başlar, bir sonuca varır ve ondan daha iyisinin olup olmadığını bilmez.

### 5.2 Takıldığımızı ne zaman biliriz?

Bunu ancak ulaşılabilecek en iyi değer biliniyorsa söyleyebiliriz. Hoca 8-vezir üzerinden örnek verdi. Birbirini tehdit etmeyen vezir çiftlerinin sayısını maksimize ettiğimizi düşünelim; bu sayı en fazla 28 olabilir. Başlangıçta 5 çift birbirini tehdit etmiyor olsun. İlerledikçe 6, 7, 8, 9 çifte çıkıyoruz ve 26'ya geliyoruz; artık hiçbir durum bizi daha da iyileştiremiyor. 28'in mümkün olduğunu biliyorsak 26'da lokal bir maksimuma takıldığımızdan emin oluruz. Bu bilgi elimizde yoksa "gerçekten takıldım mı, yoksa en yüksek nokta burası mı?" sorusuna cevap veremeyiz.

> **Ek bilgi (derste anlatılmadı):** 8 vezirden oluşturulabilecek çift sayısı $\binom{8}{2} = 28$'dir; hocanın "en fazla 28" dediği sayı budur. Hoca bu sayıyı "yanlış hatırlamıyorsam" diyerek verdi; hesap bunu doğrular.

**Soru:** Elimizde fonksiyonun grafiği varsa, türev-integral kullanarak lokal minimum ve maksimumları bulmuyor muyduk?
**Cevap:** Hoca buna dersin ilerisinde geleceklerini ve bunların çok temel bir farkı olduğunu söyledi (bkz. Bölüm 12).

### 5.3 Plato (yayla) ve sırtlar

Slayttaki listeye göre tepe tırmanma ilk duruma bağlıdır; lokal maksimumda, platoda ve sırtlarda takılabilir. Sıralı tepeleri yukarıda gördük. Yaylada şaşmayı hoca şöyle çizdi: eğrinin bir bölümü düz gidiyor. Düzlüğe gelen algoritmanın solu kendisinden düşük, sağı kendisiyle aynı değerde. Kendisinden çıkan hiçbir durum kendisinden daha iyi olmadığı için algoritma burada durur. Belki düz gitmeye devam etse daha iyi bir yere varacaktı, ama buna dair bir bilgisi yoktur; belki de düzlüğün ötesinde iyi bir yer yoktur. Algoritmanın görüş alanı yalnız bulunduğu noktanın komşularıdır. Sonsuz görüş alanı olsaydı problem kalmazdı.

Hoca gerçek hayattan da bir örnek verdi: hava koşullarının kötü olduğu sıralı tepelerde hangi zirvenin daha yüksek olduğunu gözle görmek mümkün değildir. Bu yüzden Everest'te en yüksek noktanın hangisi olduğu ancak geç anlaşılabilmiş; bilinen bir tepeden başka bir tepenin daha yüksek olduğu sonradan bulunmuştur. Helikopter de o yüksekliklerde pek uçamaz.

## 6. 8-Vezir Problemini Tepe Tırmanmayla Çözmek

### 6.1 Tasarım

Aradan sonra hoca 8-vezir problemini tepe tırmanmayla çözmek için tasarımı yaptı (ekrandan, 01:05:00). Slayttaki kurallar:

- Her sütuna rastgele bir vezirle başla.
- Her adımda yalnız bir veziri, yalnız aşağı ya da yukarı $x$ adım hareket ettirerek çözümü ara.
- $h$ = birbirini tehdit eden vezir çifti sayısı.
- Yukarıdaki tahta (durum) için $h = 17$.

### 6.2 Temsil

Hoca önce tahtanın nasıl temsil edileceğini sordu. Bir öğrenci matris dedi; hoca matrisin pahalı olduğunu, daha ucuz bir yapı istediğini söyledi: dizi. Her sütundaki vezirin o sütunda kaçıncı hücrede durduğu, hücreler aşağıdan sayılarak yazılır. Derste kullanılan tahta şu diziyle temsil edilir (ekrandan, 01:10:00):

```text
4 3 2 5 4 3 2 3
```

Birinci vezir 4. satırda, ikinci vezir 3. satırda, üçüncü vezir 2. satırda, dördüncü vezir 5. satırda durur ve böyle devam eder. Başka bir bilgiye gerek yoktur.

### 6.3 Komşuları üretmek

Bu durumdan gidilebilecek durumları üretmek için önce yalnız ilk veziri hareket ettirelim; diğer vezirler yerinde kalır. İlk vezir 4. satırda olduğundan 1, 2, 3, 5, 6, 7, 8. satırlara gidebilir; 7 yeni durum çıkar. İkinci vezir için de ilk vezir yerinde dururken 7 durum üretilir, üçüncü için 7, ... Her sütun için 7 durum vardır; mevcut durumdan toplam $8 \times 7 = 56$ yeni duruma geçilebilir. Hoca bunları ekranda X ile gösterdi: `4 X 2 5 4 3 2 3`, `4 3 X 5 4 3 2 3`, ..., `4 3 2 5 4 3 2 X` (ekrandan, 01:10:00).

**Soru:** Vezirlerin birbirini tehdit etmemesi için birbirlerine göre L biçiminde (at hamlesi gibi) konumlanmaları gerekmez mi?
**Cevap:** Hoca, şu anda yalnız mevcut durumdan gidilebilecek durumları ürettiklerini, bunların iyi ya da kötü olduğunu ayrıca hesaplayacaklarını söyledi. Öğrencinin önerisi, iyi bir **başlangıç** üretmek için kullanılabilir: birinci veziri koyup ikincisini ona uygun, üçüncüyü ikisine uygun yere koymak gibi. Başlangıç rastgele ya da daha akıllıca seçilebilir; ama bir durum oluştuktan sonra arama oradan başlar.

### 6.4 $h$ değerleri

Mevcut tahtada birbirini tehdit eden vezir çifti sayısı 17'dir. Hoca ekranda çiftleri tek tek saymaya başladı ama birkaçını kaçırdığını söyledi; sonuç 17'dir. İlk vezir için üretilen 7 komşunun $h$ değerleri ekranda şöyleydi (ekrandan, 01:10:00):

| Durum | $h$ |
|---|---|
| `4 3 2 5 4 3 2 3` (mevcut) | 17 |
| `1 3 2 5 4 3 2 3` | 14 |
| `2 3 2 5 4 3 2 3` | 18 |
| `3 3 2 5 4 3 2 3` | 17 |
| `5 3 2 5 4 3 2 3` | 15 |
| `6 3 2 5 4 3 2 3` | 14 |
| `7 3 2 5 4 3 2 3` | 14 |
| `8 3 2 5 4 3 2 3` | 18 |

Hoca ilk iki değeri kendisi verdi ("çok hızlı hesaplıyorum, bir yerden kopya mı çekiyorum acaba?"), sonrakileri öğrencilere sordu. Bu değerler, slayttaki tahtanın birinci sütununda yazan sayılardır. Tahtanın her hücresindeki sayı şu anlama gelir: diğer bütün vezirler yerinde kalsın, yalnız o sütundaki vezir o hücreye gelsin; oluşan durumun $h$ değeri budur. Ekrandaki tahtanın tamamı (üst satır 8, alt satır 1; Q vezirin bulunduğu hücre) (ekrandan, 01:05:00):

```text
8  18 12 14 13 13 12 14 14
7  14 16 13 15 12 14 12 16
6  14 12 18 13 15 12 14 14
5  15 14 14  Q 13 16 13 16
4   Q 14 17 15  Q 14 16 16
3  17  Q 16 18 15  Q 15  Q
2  18 14  Q 15 15 14  Q 16
1  14 14 13 17 12 14 12 18
```

Bu tahtadaki 56 değerin ve $h = 17$'nin hepsi python ile yeniden hesaplanarak doğrulandı.

### 6.5 Bir adım ve sonrası

$h$ birbirini tehdit eden çift sayısı olduğu için onu **küçültmek** isteriz; sıfıra kadar. $h = 0$'a ulaşırsak global çözümlerden birini bulduğumuzdan emin oluruz, çünkü sıfırın altı olamaz. Birden fazla çözüm olabilir, ama bulduğumuz onlardan biridir. $h$'yi sıfıra indiremezsek emin olamayız: çözümün var olduğunu biliyorsak lokal bir yere takıldığımızı anlarız, bilmiyorsak anlayamayız.

Bir sonraki adımda ne yapılır? Bir öğrenci "en küçük $h$ ile ilerleriz, 14" dedi. Hoca, öğrencinin yalnız ilk sütuna baktığını, oysa 56 komşunun hepsine bakılması gerektiğini hatırlattı. Tahtada en küçük değer 12'dir ve birden çok hücrede görülür (hesapla 8 hücre). Hangisini seçeceğiz? Biri diğerinden daha iyi ya da kötü değilse **rastgele** seçeriz. Hoca 12'lerden birini seçti, veziri oraya taşıdı ve yeni tahtaya geçti. Bu yeni durum için 56 komşunun $h$'si yeniden hesaplanır, yine en düşüğüne gidilir. Süreç böyle devam eder.

### 6.6 $h = 1$'de takılmak

Hoca bu yolla ilerleyen bir örneğin vardığı tahtayı gösterdi: $h = 1$. Yalnızca iki vezir birbirini tehdit ediyor, diğerleri hiç tehdit edilmiyor. Bu durumun 56 komşusundan hiçbirinin $h$'si 1'den küçük değil. Algoritma burada durur ve "bulabildiğim en iyisi bu; sen sıfır istedin ama ben $h = 1$ buldum" der.

Problem her zaman sıfırı istemeyebilir. "8 veziri birbirini en az tehdit edecek şekilde dizin" ya da "16 atı birbirini en az tehdit edecek şekilde dizin" gibi bir soru da sorulabilir. O zaman mümkün olan en iyi değer bilinmez. $h$'nin sıfıra inebildiğini biliyorsanız lokal bir yere takıldığınızı anlarsınız; bilmiyorsanız belki de $h = 1$ en iyi çözümdür.

Hoca son olarak tek bir çözüm olmadığını ekledi: tahtaya dört taraftan bakılarak, yani tahta döndürülerek elde edilen dört durumun $h$ değerleri birbirine eşittir.

## 7. Tepe Tırmanmanın 8-Vezirdeki Performansı

8-vezir gerçekten çözümü olan bir problemdir. Slayta göre (ekrandan, 01:20:00):

- Rastgele başlangıç değerleriyle
- Denemelerin %14'ünde çözer
- %86'sında lokal bir maksimuma takılır
- $8^8 = 2^{24} \approx 17$ milyon durum

Bu performans, yukarıda tanımlanan yapı için geçerlidir: her sütunda rastgele bir vezirle başlamak ve her adımda tek bir veziri kendi sütununda istediği yere taşımak. Bütün durumları incelemek ne kadar sürer? Her sütundaki vezir 8 farklı yere konabilir; 8 tane 8'in çarpımı, yani yaklaşık 17 milyon durum vardır.

> **Ek bilgi (derste anlatılmadı):** $8^8 = 16.777.216 = 2^{24}$'tür; slayttaki "yaklaşık 17 milyon" bu sayıdır. Bu sayı her sütunda tam bir vezir bulunan yerleşimleri sayar.

## 8. Birinci Alternatif: Rastgele Yeniden Başlatma

Hoca sordu: %14 başarıyla 8-vezir çözen bir algoritmanız olsa, çözümü bulmak için en basitinden ne yaparsınız? Öğrenciler "bir daha çalıştırırız" dedi. Yaklaşık her 7-8 denemeden biri çözüme ulaşacaktır.

Ama tekrar çalıştırırken bir şeyi değiştirmek gerekir mi? Tepe tırmanmanın sonucunu en temelde **başlangıç noktası** belirler. Sonucu etkileyen ikinci bir etken daha vardır: aynı başlangıçtan başlasanız bile farklı yerlere varabilirsiniz, çünkü eşit değerli komşular arasından rastgele seçim yapılır. Bir öğrencinin cevabı da bu oldu. Böyle bir rastgelelik yoksa farklı başlangıç değerleriyle tekrarlamak gerekir.

Bu ilk çözüm alternatifinin adı **rastgele yeniden başlatmalı tepe tırmanma**dır (random-restart hill climbing): çözüme ulaşmadıkça tepe tırmanmayı farklı başlangıçlarla tekrarlamak (ekrandan, 01:25:00). Farklı başlangıç kritik bir etkendir; dağ ve tepe örneğinde gördüğümüz gibi nereden başladığınız nereye varacağınızı büyük ölçüde belirler.

Slayttaki üç alternatif:

- Tepe tırmanmayı farklı başlangıçlarla tekrarlamak: random-restart hill climbing
- Benzetimli tavlama: simulated annealing
- Paralel tepe tırmanma: local beam search

## 9. İkinci Alternatif: Benzetimli Tavlama

### 9.1 Tavlama benzetmesi

Benzetimli tavlama (simulated annealing), bir hedefe varmak için sürekli ona doğru koşmak yerine bazen hedeften uzaklaşmanın da bir miktar iyi olabileceğini söyler. Adı, çeliğe su verme işleminden gelir. Demir ısıtılır, soğumaya bırakılır, sonra yeniden ısıtılır. Hoca sıcaklık-zaman grafiği çizdi: sıcaklığı sürekli düşürmek yerine biraz düşürüp biraz yeniden ısıtarak ilerlemek. Bu şekilde yapıldığında elde edilen çeliğin daha kaliteli, içinde daha az boşluk barındıran bir yapıda olduğu bilinir. Yaklaşımın özü şudur: ara sıra yapmaya çalıştığımız şeyin tersini yapmak iyi olabilir.

### 9.2 Kötü hamleye izin vermek

Hoca bu kez tepeli bir eğride bir nokta işaretledi. Tepe tırmanma uygularsak soldaki tepeye varırız. Peki bu adımda bir miktar kötüleşmeye izin verirsek? Kötü olan yöne bir adım atmak, bizi uzun vadede daha iyi bir noktaya götürebilir. Hoca bunu iki eğriyle gösterdi: $h$'yi sürekli artıran bir süreç bir yere kadar çıkar; bazen düşmesine de izin veren bir süreç belki daha iyi bir yere varır (ekrandan, 01:25:00).

Bu kesin bir şey değildir, bir olasılıktır. Hoca başka bir eğri çizdi: tepe tırmanma bir tepeye götürürken, benzetimli tavlama kötü yöne atlayıp daha da kötü bir tepeye varabilir. Kötü yöne gitmek illa iyileştirecek diye bir şey yoktur.

### 9.3 Slayttaki tanım

Slayta göre (ekrandan, 01:30:00):

- Ana fikir: Yerel maksimumdan kaçmak için istenmeyen hareketlere izin ver.
- Rastgele bir hareket üret. İyileşme varsa kabul et. Yoksa zamanla ve kötüleşme miktarıyla azalan bir olasılıkla kabul et.
- Zaman içinde rastgele hareketin boyutu (yeni noktanın uzaklığı bir dağılımdan üretilirse) ve kabul olasılığı azaltılır.

Burada tepe tırmanmadan önemli bir fark vardır: bütün komşuları üretip en iyisini seçmeyiz. Mevcut durumdan gidilebilecek durumlar arasından **rastgele bir tane** üretiriz.

### 9.4 Algoritma

Slayttaki sözde kod (ekrandan, 01:35:00):

```text
function SIMULATED-ANNEALING(problem, schedule) returns a solution state
  inputs: problem, a problem
          schedule, a mapping from time to "temperature"
  current <- MAKE-NODE(problem.INITIAL-STATE)
  for t = 1 to inf do
    T <- schedule(t)
    if T = 0 then return current
    next <- a randomly selected successor of current
    dE <- next.VALUE - current.VALUE
    if dE > 0 then current <- next                      (iyileşme varsa kesin kabul)
    else current <- next only with probability e^(dE/T) (iyileşme yoksa belki)

Schedule: T = T0 * 0.95^t
Belki, kötüleşme miktarına (dE) ve geçen zamana bağlı
```

`schedule`, zamanı "sıcaklığa" ($T$) eşleyen bir fonksiyondur. Slayttaki örnek $T = T_0 \cdot 0{,}95^t$'dir; küçük $t$ zamanı gösterir. $t = 1$ iken $T = T_0 \cdot 0{,}95$, $t = 2$ iken $T = T_0 \cdot 0{,}95 \cdot 0{,}95$'tir. Zaman ilerledikçe $T$ sürekli azalır: başta $T_0$'a yakındır, $t$ yüzlere, binlere geldiğinde sıfıra çok yakın bir değer olur.

Döngünün her turunda $T$ hesaplanır; $T$ sıfır olduysa mevcut durum döndürülür. Değilse mevcut durumun ardıllarından rastgele biri `next` olarak seçilir. 8-vezir için düşünürsek 56 komşunun hepsi üretilmez, yalnız biri rastgele üretilir. Sonra $\Delta E$ = `next`'in değeri − `current`'ın değeri hesaplanır.

- $\Delta E > 0$ ise `next` daha yüksek değerlidir, yani iyileşme vardır. Tepe tırmanmada olduğu gibi kesin kabul edilir.
- $\Delta E \le 0$ ise kötüleşme vardır. `next` yalnızca $e^{\Delta E / T}$ olasılıkla kabul edilir.

### 9.5 Kabul olasılığının yorumu

$\Delta E$ negatiftir. Mutlak değeri büyükse, yani hamle aşırı derecede kötüleştiriyorsa, kabul olasılığı düşük olmalıdır; $e^{\Delta E / T}$ gerçekten de küçük çıkar. Az kötüleştiren bir hamle daha yüksek olasılıkla seçilebilir. Paydadaki $T$ zamana bağlıdır: zaman geçtikçe kötü hamleleri kabul etme olasılığı azalır. Başta kötüler daha yüksek ihtimalle, sonra daha düşük ihtimalle kabul edilir.

**Soru:** $T$ çok çok küçük bir değere geldiğinde kabul olasılığı neye yaklaşır?
**Cevap:** Sıfıra. Bir öğrencinin cevabıyla, kötü hamle artık seçilmez.

**Soru:** O zaman algoritma neye dönüşür?
**Cevap:** Tepe tırmanmaya (hill climbing).

Sonuç olarak "belki" iki şeye bağlıdır: kötüleşme miktarına ve geçen zamana. $h$'yi sürekli yükseltmek yerine bazen, küçük miktarlarda düşmesine izin vererek daha iyi bir yere gitmeyi umarız.

Hoca bunu bir grafikle özetledi: x ekseni zaman (durumlar değil), y ekseni o anki mevcut durumun hedefe olan yakınlığıdır. Başta $h$ büyük salınımlar yapar, çünkü kötüleşmeye daha çok izin verilir. Zamanla salınımlar küçülür; arada bir iyileşen ama kötüleşmeye pek izin vermeyen, tepe tırmanmaya çok benzeyen bir yapıya dönüşür.

## 10. Üçüncü Alternatif: Paralel Tepe Tırmanma

### 10.1 Fikir

Paralel tepe tırmanma (local beam search), dağa tek bir dağcı yerine birden çok dağcı yollamaktır. Slayta göre: tek bir durumu izlemek yerine $k$ tanesini izle; $k$ adet rastgele üretilmiş durumla başla; her iterasyonda $k$ durumun hepsinden gidilebilecek tüm durumları üret; bu durumlardan biri hedefse dur; değilse en iyi $k$ tanesini mevcut durumlar olarak ata ve bir önceki adıma dön.

Beş dağcımız olduğunu düşünelim. Her biri bulunduğu yerde ölçümler yapıyor ve birbirleriyle haberleşebiliyorlar. Hepsinin ölçümleri arasından en iyi $k$ nokta bulunur ve dağcılar bu $k$ noktaya "ışınlanır."

### 10.2 Çeşitlilik problemi

Paralel gitmenin güzel yanı, herkesin farklı bir yerde olması ve birbirinden farklı çözümlere doğru gidilmesidir. Ama en iyi $k$ taneye ışınlanmak çok iyi bir fikir olmayabilir. Hoca bir dağ çizdi (ekrandan, 01:55:00) ve üç dağcıyı farklı yerlere koydu. Her dağcı sağa ve sola gidince ne olacağını hesaplar; 6 yeni durum ve 3 mevcut durumla 9 durum olur. Bu 9 durumun en iyi üçü aynı tepenin yamacında çıktı. Dağcılardan biri orada kalır, diğer ikisi de onun yanındaki noktalara kopyalanır. Bundan sonra her biri yine iki komşu üretir ve yine en iyi üçe ışınlanırlar; hepsi aynı tepenin üzerinde kalır.

Bu dağda üç dağcı olmasıyla bir dağcı olması arasında artık bir fark yoktur. Dağcılar farklı yerlerde olmalıdır ki katkı sağlasınlar. Bu yüzden hepsini en iyi yerlere ışınlamak yerine bir kısmını iyi yerlere ışınlayıp bir kısmını olduğu, belki daha kötü yerlerde bırakmak daha mantıklı olabilir. Hocaya göre bu, biraz benzetimli tavlamaya benzer bir dengedir. Çözümlerin birbirinden ayrık olmasını sağlamaya devam etmek gerekir.

> **Hocanın vurgusu:** Paralel tepe tırmanmada çeşitlilik (diversity) olmazsa hiçbir şey olmaz.

Paralel tepe tırmanma, bir sonraki hafta görülecek genetik algoritmanın da temelidir. Aynı problem orada da vardır: bütün çözümler aynı yerde, birbirlerine çok yakınsa genetik algoritma kullanmak pek bir şey kazandırmaz.

## 11. Bozuk TV ve Kasa: Sezginin Değeri

### 11.1 Bozuk TV

Hoca bir problem sordu (ekrandan, 02:00:00):

- Televizyonunuzun görüntüsü bozuk.
- Görüntü ayarı için 4 kontrol düğmesi var.
- Her bir düğmenin 100 farklı pozisyonu var.
- Nasıl bir yol izlersiniz?

Hikâye şöyle kuruldu: eski bir televizyon, internet yok, uzaktan kumanda yok, kayıt imkânı yok; maç ya da sevdiğiniz dizi birazdan başlayacak. Televizyonun eskiden nasıl göründüğünü bilmiyorsunuz, ama şu an kötü göründüğünü görüyorsunuz. Çanak gibi başka bir şeye dokunamıyorsunuz, yalnız bu dört düğmeyle oynayabiliyorsunuz.

Bir öğrenci kaba kuvvet (brute force) önerdi: bütün kombinasyonları denemek. Kaç olası durum vardır? $100 \times 100 \times 100 \times 100 = 10^8$, yani 100 milyon. Hocanın cevabı: "Hepsini denersen televizyonun başında ölürsün." Kaba kuvvet uygulanabilir bir teknik değildir.

Başka bir öğrenci şunu önerdi: bir düğmeyi bir tık çevir, iyileşme var mı bak; varsa bir tık daha çevir; kötüleşmeye başlayınca bir önceki pozisyona dön ve bir sonraki düğmeye geç. Dört düğme için bunu yapınca bir sonuç elde edilir. Bu sonucun en iyi olduğundan emin olamayız, çünkü kaba kuvvet yapamadık; lokal bir yere vardık. Bu aslında lokal bir aramadır ve hayatta böyle bir problemle karşılaşınca kullandığımız yöntem genelde budur.

Her düğmenin yalnız iki pozisyonu olsaydı 16 durum olurdu ve hepsi denenirdi. 100 pozisyonda bu mümkün değildir; arama uzayı çok büyük olduğunda algoritmik bir yapıya geçmek gerekir. Öğrencinin yönteminde en fazla kaç durum denenir? Her düğme için en fazla 100, dört düğme için en fazla $4 \times 100 = 400$. Bu çok vakit almaz; maçın belki 2-3 dakikasını kaçırırsınız. Ama 100 milyon durumun içinden yalnız 400'ünü denediğiniz için çok büyük bir ihtimalle lokal bir maksimuma (ya da minimuma) takıldınız.

### 11.2 Kasa

Sonra hoca soruyu değiştirdi (ekrandan, 02:05:00): "Peki ya kasa açsanız?" Bir eve giren hırsız, dört düğmeli, her düğmesi 100 pozisyonlu bir şifreli kasayla karşılaşıyor. Şifre yine 100 milyon olasılıktan biri. Siren sesleri duyuluyor, yaklaşık 15 dakika var ve kasa taşınamayacak kadar ağır. Ne yaparsınız?

Öğrenciler "açamayız, kaçmamız gerekiyor" dedi. Hoca sordu: bozuk televizyonu olduğu gibi bırakmadınız, burada neden kaçıyorsunuz? Değişen ne? Bir öğrenci önce "hedef" dedi; hoca hedefin televizyon probleminde de olmadığını söyledi. Doğru cevap: burada **$h$ yok**, yani elimizde sezgisel bir fonksiyon yok. Düğmeyi çevirince kasanın açılmaya yaklaşıp yaklaşmadığını gösteren hiçbir bilgi yoktur. Yapılabilecek tek şey kör arama algoritması kullanmaktır, o da bu büyüklükte uygulanabilir değildir. Bu yüzden kaçmak çok daha mantıklıdır; 15 dakikada denenebilecek kadarını deneyip kaçmak da olur, çok şanslıysanız tutturabilirsiniz.

İki problem arasındaki tek fark sezginin elde olup olmamasıdır ve bu, sezginin etkisinin büyüklüğünü çok rahat gösterir. Büyük arama uzaylarında sezgi yoksa yapılacak pek bir şey kalmaz.

**Soru:** Eski filmlerde hırsız kasaya neden steteskop dayar?
**Cevap:** Bir öğrencinin cevabıyla, sezgi eklemek için. Kilitten gelen klik seslerine göre hedefe yaklaşıp yaklaşmadığını anlamaya çalışır.

> **Hocanın vurgusu:** Sezgi elimizde olduğunda problemleri daha iyi çözemeyiz, ama çok daha hızlı çözebiliriz.

Hoca bir örnek daha verdi: birinin e-posta parolasını kırmak gerektiğinde kaba kuvvet mantıklı değildir; milyarlarca olasılık vardır. İnsanlar parolalarında genelde belli kalıplar kullanır: sıralı sayılar, doğum tarihi, isimler, evlilik yıl dönümü, okul numarası gibi hayatlarında önemli olan, unutmayacaklarını düşündükleri bilgiler. Önce bu bilgilere erişilir ve onlarla ilgili kombinasyonlar öncelikle denenir; böylece bir miktar sezgi elde edilmiş olur. Yine de iş kaba kuvvetle çözülebilecek bir şey değildir.

## 12. Ayrık ve Sürekli Uzaylar, Eğim Düşme

### 12.1 Ayrık uzay

Şimdiye kadar konuşulan bütün arama uzayları ayrık (discrete) uzaylardı. Bir noktadan gidilebilecek noktaların sayısı sınırlıydı: dallanma faktörü $b$ sonlu bir sayıydı (3, 5, 10, 100). Gidilebilecek noktalar bellidir ve hepsine erişilebilir.

### 12.2 Sürekli uzay

Sürekli uzayda bir noktadan sonsuz noktaya gidilebilir. Hoca slaytta $f(x_1, x_2) = x_1^2 + x_2^2$ fonksiyonunun eş yükselti eğrilerini gösterdi (ekrandan, 02:10:00). Eğriler üzerindeki noktaların ortak özelliğini sordu: bir çizginin üzerindeki noktaların $f$ değerleri aynıdır. Bu, coğrafyadaki izohips (yükseklik) eğrilerine benzer.

Rastgele bir başlangıç noktasından başlayıp onu iyileştirmek, yani lokal arama yapmak istiyoruz. Ama bir noktadan gidilebilecek sonsuz sayıda yön vardır; hepsini denemek mümkün değildir. Dört yön belirleyip yalnız onlarda hareket etmek mümkündür ama makul değildir. Fonksiyon elimizdeyse bize **türevi** yol gösterir; türev, yukarı mı çıktığımızı aşağı mı indiğimizi söyler.

Hoca bir noktada türevin yönünü çizdi ve türevin tersi yönünde hareket etmenin mantıklı olduğunu söyledi (ekrandan, 02:15:00). Her adımda türev yeniden hesaplanır ve tersi yönde ilerlenir. En sona yaklaşıldığında türev sıfır olur; artık hareket etmeye gerek olmadığı anlaşılır. Rastgele bir başlangıç noktasından başlayıp fonksiyonun türevine göre hareket etmek **eğim düşme** (gradient descent) algoritmasıdır. Ekrandaki grafikte de 1, 2, 3, 4, 5, ... diye numaralanan noktaların merkeze doğru giderek küçülen adımlarla yaklaştığı görülüyordu.

> **Ders sonrası not:** Hoca bu fonksiyonu "yukarıya doğru yükselen bir dağ" diye anlattı ve fonksiyonun maksimum olduğu yerin arandığını söyledi. Oysa $f(x_1, x_2) = x_1^2 + x_2^2$ merkezde, $(0, 0)$ noktasında **minimum** değeri (0) alır ve dışa doğru büyür; bir dağ değil, bir çanaktır. Türevin (gradyanın) tersi yönünde ilerlemek de bizi bu minimuma götürür; ekrandaki noktalar da $(0, 0)$'a yakınsıyor. Yani yapılan şey bir yokuş inmedir.

> **Ek bilgi (derste anlatılmadı):** Bu fonksiyonun gradyanı $\nabla f = (2x_1, 2x_2)$'dir. Eğim düşme her adımda $x \leftarrow x - \eta \nabla f(x)$ güncellemesini yapar; $\eta$ adım büyüklüğüdür (öğrenme oranı). Merkeze yaklaştıkça gradyan küçüldüğü için adımlar da küçülür.

### 12.3 Derin öğrenme bağlantısı

Bugün adı sıkça duyulan derin öğrenme mimarilerinin hepsinin eğitim süreci burada görülen şeydir: ağırlıklar rastgele bir başlangıç noktasından başlar ve iyileştirilmeye çalışılır. Uzay ayrık olmadığı için önceki yöntemler kullanılamaz, ama sürekli uzayda bize yön gösteren bir şey vardır. Ayrık uzaydaymış gibi davranıp kendinize 5-10 yön belirleyip en iyileştirenine gitmek her zaman iyi sonuç vermez; çok küçük farkların büyük sonuçlara yol açabildiği sürekli uzaylarda bu kaba bir yöntem kalır. Bu yüzden temelde gradient descent tabanlı Adam, RMSProp ve Adam'ın öncüsü Adagrad gibi algoritmalar kullanılır.

Bu uzaylar çok büyüktür. Hoca örnek olarak baktığı bir DenseNet mimarisinin yaklaşık 20 milyon parametresi olduğunu, daha büyüklerinin de bulunduğunu söyledi; yani 20 milyon boyutlu bir uzayda optimizasyon yapılır. Ama algoritma aynıdır: iki boyutta çalışan, 20 milyon boyutta da çalışır. Hocaya göre matematiğin güzelliği buradadır.

## 13. Uygulama: Robot Süpürgeyle Alan Tarama

### 13.1 Problem

Son olarak hoca bir uygulama anlattı. $n \times n$'lik bir alan, örneğin bir ev ve sekiz yönde hareket edebilen bir robot süpürge var; yani ayrık bir uzaydayız. Robot her adımda bir kare gidebilir. Bütün alanı gezebilmesi için $n^2 - 1$ adım atması gerekir.

İki amaç vardır:

- **Minimum açı:** Robot dönüşlerini mümkün olduğunca az ve yumuşak yapmalıdır. Dönmek yavaşlamayı gerektirir; ani, dik dönüşler içeren bir rota hızlı tamamlanmaz.
- **Maksimum alan:** Robot evin her yerini gezmeli, taramalı, temizlemelidir.

Önceki problemlerden farklı olarak iyilik fonksiyonunun iki bileşeni vardır. Hoca burada bir terminoloji notu da düştü: iyilik fonksiyonu (fitness), amaç fonksiyonu (objective) ve kayıp fonksiyonu (loss) farklı uzmanlık alanlarında aynı kavramı ifade etmenin değişik yollarıdır; biri minimize, biri maksimize ediliyor olabilir ama kavram aynıdır. Bu kavramın tek bileşenli olması gerekmez.

### 13.2 Temsil

Bir çözüm $n^2 - 1$ adet hareketten oluşur. Hareketler 0 ile 8 arasındaki tam sayılarla gösterilir: 0 olduğu yerde kalmaktır, diğer 8 sayı 8 yönü gösterir. $n = 8$ ise çözüm, her biri 0-8 arasında olan 63 sayıdan oluşur. Ekrandaki yön şemasına göre (ekrandan, 02:25:00):

```text
2   1   8
3   0   7
4   5   6
```

Yani 1 yukarı, 2 sol üst, 3 sol, 4 sol alt, 5 aşağı, 6 sağ alt, 7 sağ, 8 sağ üst yöndür. Hoca rastgele bir başlangıç çözümünü (1,1) hücresinden başlayarak okudu: önce 1 (yukarı), sonra 6, sonra 7, sonra iki kez 2, sonra 1, sonra üç kez 6 ... Ekranda bulunan en iyi çözümün dizisi de 7 satır × 9 sütunluk (63 elemanlı) bir tablo olarak gösteriliyordu.

### 13.3 Algoritma

Hocanın MATLAB kodu `tepe_tirmanma_tarama_1robot.m` adını taşıyor ve dersin sayfasında paylaşılmış. Standart tepe tırmanmadan birkaç farkı var. Slayttaki adımlar (ekrandan, 02:20:00):

```text
Rasgele bir çözümle başla
G kez:
  - Çözümden (%mu kadar) rasgele değişikliklerle P adet yeni çözüm üret
  - Üretilen çözümlerin iyilik değerlerini hesapla
      (Dönüş açılarını topla, gidilen farklı nokta sayısını topla)
  - Üretilenlerden en iyisi mevcuttan iyi ise çözüme ata, mu oranını azalt,
    kötü ise mu oranını arttır
  - tk_max kez daha iyisi üretilmediyse çözümü rasgele başlat
```

Adımların açıklaması:

- **Rastgele çözüm:** 0 ile 8 arasında 63 sayı üretmek demektir.
- **P adet yeni çözüm:** Bir durumdan gidilebilecek bütün durumları üretmek çok fazladır. Bunun yerine bir kısmı, örneğin 100 ya da 200 tanesi üretilir. Her yeni çözüm, mevcut çözümün %mu kadarı rastgele değiştirilerek elde edilir; mu 10 ise %10'u değiştirilir.
- **İyilik değeri:** Her çözüm için dönüş açıları ve gidilen farklı nokta sayısı toplanarak tek bir iyilik değeri elde edilir.
- **mu'nun ayarlanması:** En iyi yeni çözüm mevcuttan iyiyse ona geçilir ve mu azaltılır: bu büyüklükte değişiklikle iyi şeyler bulunabiliyor, ileride değişiklikler giderek küçülsün. Kötüyse mu artırılır: bu kadar değişiklikle iyi bir şey çıkmadı, daha büyük değişiklik deneyelim. Hoca mu'yu azaltıp artırmanın tamamen isteğe bağlı olduğunu, yapılmasa da olacağını söyledi. Burada kötü çözümü kabul etme olmadığı için bu bir benzetimli tavlama değildir.
- **tk_max:** Bir kez iyileştirememek algoritmayı bitirmez. tk_max kez üst üste daha iyi çözüm üretilemezse çözüm rastgele yeniden başlatılır.

### 13.4 Sonuçlar

Ekranda üç bölüm vardı (ekrandan, 02:25:00): rastgele bir başlangıcın rotası (karmakarışık bir yol), sürecin ilerleyişi ve bulunan en iyi çözümün rotası. Ekrandaki parametreler:

```text
P=200
mu=?.01;     % degisim orani
mu_dec=0.99; % azalma orani
mu_inc=1.01; % artma orani
tk_max=50;   % tk_max kez ayni kaldiysa restart
G=3000;      % iterasyon sayisi
```

<!-- BELİRSİZ: mu satırının ilk hanesi ekranda bir seçim tutamacının altında kalıyor; yalnızca ".01" okunabiliyor. -->

Hoca sürecin ilerleyişi grafiğinin eksenlerini sordu: x ekseni zamandır (iterasyon, 0-3000), y ekseni o anki mevcut çözümün iyilik değeridir. Grafikte değer bir süre aşağı iner (burada küçük değer daha iyidir), sonra düz kalır, sonra yukarı sıçrar. Düz kalan yerler tk_max = 50 adımdır: 50 kez değişiklik uygulanmış ama hiçbiri mevcuttan iyi bir şey vermemiştir. O zaman algoritma yeniden başlatılır ve değer yukarı sıçrar. Yani tepe tırmanma sürekli yeniden başlatılmaktadır. En iyi çözüm, grafikte $h$ değerinin en düşük olduğu noktadaki çözümdür.

### 13.5 İki bileşeni birleştirmek

Hoca iki önemli noktaya dikkat çekti.

**Soru:** İki bileşenin aralıkları (range) birbirinden çok farklıysa, örneğin biri 0 ile 1000, diğeri 0 ile 1 arasında değişiyorsa, bunları toplamak sorun çıkarır mı?
**Cevap:** Evet. Büyük olan bileşen her zaman küçüğünü ezer ve iki bileşene göre birden optimizasyon yapılmış olmaz. Bileşenlerin aralıkları eşit hale getirilmelidir.

İkinci nokta: bileşenlerden biri minimize (açı toplamı), diğeri maksimize (gezilen alan) edilecektir. Min ile max'ı doğrudan toplamak mantıklı değildir; ya ikisi de minimizasyona ya da ikisi de maksimizasyona çevrilmelidir. Bu çevirme oldukça kolaydır.

Son olarak istenen kadar yeni bileşen eklenebilir. Örneğin robotun hareketini bitirdiğinde başladığı yere dönmesi isteniyorsa, son noktanın başlangıç noktasına uzaklığı iyilik fonksiyonuna üçüncü bir bileşen olarak katılır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:19:03): 4×4 tahtada her sütunda bir vezir var. Her adımda yalnız bir vezir kendi sütununda istediği yere gidebiliyorsa, bir durumdan kaç yeni durum üretilir?

> **Çözüm:** Her vezirin bulunduğu hücre dışında 3 seçeneği vardır. $4 \times 3 = 12$ yeni durum.

**Soru 2** (ekrandan, 01:05:00 ve 01:10:00): 8-vezir tahtası `4 3 2 5 4 3 2 3` dizisiyle veriliyor (her sütundaki vezirin aşağıdan satır numarası). $h$ birbirini tehdit eden vezir çifti sayısıdır. (a) Bu durumun $h$ değeri nedir? (b) Tek bir vezir kendi sütununda hareket ettirilerek kaç komşu üretilir? (c) Tepe tırmanma bir sonraki adımda hangi değere sahip bir komşuya geçer?

> **Çözüm:** (a) $h = 17$. (b) $8 \times 7 = 56$ komşu. (c) Komşular arasında en küçük $h$ değeri 12'dir; bu değer 8 komşuda görülür ve bunlardan biri rastgele seçilir. İlk sütundaki komşuların değerleri 14, 18, 17, 15, 14, 14, 18'dir; yalnız ilk sütuna bakıp 14'ü seçmek yanlıştır (python ile doğrulandı).

**Soru 3** (derste sözlü, 00:39:54): 8-vezirde birbirini tehdit etmeyen vezir çifti sayısını maksimize ediyoruz ve tepe tırmanma 26'da duruyor. Ne zaman lokal bir maksimuma takıldığımızdan emin olabiliriz?

> **Çözüm:** Ulaşılabilecek en büyük değerin 28 olduğunu ve bu değerin mümkün olduğunu biliyorsak 26'da takıldığımızı anlarız. Bu bilgi yoksa 26'nın en iyi değer olup olmadığını bilemeyiz.

**Soru 4** (ekrandan, 01:20:00): 8-vezir problemi için her sütunda bir vezir bulunan kaç farklı yerleşim vardır?

> **Çözüm:** $8^8 = 2^{24} = 16.777.216 \approx 17$ milyon.

**Soru 5** (derste sözlü, 01:20:25 ve 01:21:47): %14 başarıyla çözen bir tepe tırmanma algoritmanız var. Çözümü bulmak için ne yaparsınız? Aynı başlangıçla tekrar çalıştırmak farklı sonuç verebilir mi?

> **Çözüm:** Algoritma farklı başlangıçlarla tekrar çalıştırılır (random-restart hill climbing). Eşit değerli komşular arasından rastgele seçim yapılıyorsa aynı başlangıç bile farklı sonuca götürebilir; yine de başlangıcı değiştirmek asıl etkendir.

**Soru 6** (derste sözlü, 01:36:01): Benzetimli tavlamada $T$ çok küçük bir değere geldiğinde kötü hamleyi kabul olasılığı neye yaklaşır ve algoritma neye dönüşür?

> **Çözüm:** $\Delta E < 0$ olduğu için $e^{\Delta E / T} \to 0$ olur; kötü hamleler kabul edilmez ve algoritma tepe tırmanmaya dönüşür.

**Soru 7** (derste sözlü, 01:52:56): Paralel tepe tırmanmada üç dağcı var ve her biri sağa ve sola gitmeyi deniyor. Kaç durum arasından seçim yapılır ve en iyi üçünü seçmenin sakıncası nedir?

> **Çözüm:** 3 mevcut + 6 yeni = 9 durum. Derste çizilen örnekte en iyi üç durum aynı tepede çıktı; bütün dağcılar oraya ışınlanınca çeşitlilik kaybolur ve üç dağcının bir dağcıdan farkı kalmaz.

**Soru 8** (ekrandan, 02:00:00): Televizyonunuzun görüntüsü bozuk. Görüntü ayarı için 4 kontrol düğmesi var ve her düğmenin 100 farklı pozisyonu var. Nasıl bir yol izlersiniz? Kaba kuvvetle kaç durum denenir, düğme düğme iyileştirmeyle en fazla kaç durum denenir?

> **Çözüm:** Kaba kuvvet $100^4 = 10^8$ (100 milyon) durum gerektirir ve uygulanamaz. Düğmeleri sırayla, iyileşme bitene kadar çevirmek en fazla $4 \times 100 = 400$ deneme gerektirir. Bu lokal bir aramadır; 100 milyon durumdan 400'ü denendiği için sonuç büyük olasılıkla lokal bir optimumdur.

**Soru 9** (ekrandan, 02:05:00): Peki ya aynı yapıdaki bir kasayı açsanız? Neden bu kez denemek yerine kaçmak mantıklıdır?

> **Çözüm:** Kasada yaklaşıp yaklaşmadığınızı gösteren bir sezgisel fonksiyon ($h$) yoktur. Yalnız kör arama kalır ve $10^8$ olasılıkta bu uygulanabilir değildir.

**Soru 10** (derste sözlü, 02:26:39): Robot süpürge probleminde iyilik fonksiyonunun iki bileşeni var: biri 0-1000, diğeri 0-1 aralığında; biri minimize, diğeri maksimize ediliyor. Bunları doğrudan toplamak neden yanlıştır?

> **Çözüm:** Büyük aralıklı bileşen küçüğünü ezer; aralıklar eşitlenmelidir. Ayrıca min ile max toplanmaz; iki bileşen de aynı yöne (ikisi de min ya da ikisi de max) çevrilmelidir.

## Dersin Toparlaması

Bu derste, bitiş durumunun bilinmediği ve istenen çıktının yol değil durumun kendisi olduğu problemler için lokal arama algoritmaları ele alındı. Temel algoritma tepe tırmanmadır: mevcut durumun komşuları arasından en iyisine geçilir, iyileşme kalmayınca durulur. Hafıza gereksinimi çok azdır, ama sonuç başlangıç noktasına bağlıdır ve algoritma lokal maksimumlarda, platolarda ve sırtlarda takılabilir. 8-vezir örneğinde dizi temsili, 56 komşu ve $h = 17$'den başlayan tahta üzerinden süreç adım adım gösterildi; rastgele başlangıçla başarı yalnızca %14'tür. Lokal maksimumdan kaçmak için üç alternatif incelendi: farklı başlangıçlarla yeniden başlatma, kötü hamleleri zamanla ve kötüleşme miktarıyla azalan bir olasılıkla kabul eden benzetimli tavlama ve $k$ durumu birlikte izleyen, çeşitliliği korumak gereken paralel tepe tırmanma.

Bozuk TV ve kasa örnekleri, sezginin büyük arama uzaylarındaki belirleyici rolünü gösterdi. Sürekli uzaylarda türevin yol gösterdiği eğim düşme algoritmasının derin öğrenme eğitiminin temeli olduğu vurgulandı. Robot süpürge uygulamasında çok bileşenli bir iyilik fonksiyonuyla, yeniden başlatmalı ve uyarlamalı değişiklik oranlı bir tepe tırmanma çalıştırıldı. Hoca, paralel tepe tırmanmanın bir sonraki derste görülecek genetik algoritmanın temeli olduğunu belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
