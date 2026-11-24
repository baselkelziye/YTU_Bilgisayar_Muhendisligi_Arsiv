# Ders 5 Genişletilmiş Notu: Lokal Arama Algoritmaları: Tepe Tırmanma, Benzetimli Tavlama ve Paralel Tepe Tırmanma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kör, Sezgisel ve Lokal Arama
- 2. Lokal Aramanın Çözdüğü Problem Türü
- 3. Tepe Tırmanma (Hill Climbing)
- 4. Tepe Tırmanmanın Problemleri
- 5. 8-Vezir Problemini Tepe Tırmanma ile Çözmek
- 6. Lokal Tepelerden Kurtulma: Rastgele Yeniden Başlatma
- 7. Benzetimli Tavlama (Simulated Annealing)
- 8. Paralel Tepe Tırmanma (Local Beam Search)
- 9. Bozuk Televizyon ve Şifreli Kasa
- 10. Ayrık ve Sürekli Uzaylar
- 11. Uygulama: Bir Alanı Robotla Taramak
- Örnek Sorular

## 1. Kör, Sezgisel ve Lokal Arama

Ders, önceki haftalarda görülen arama algoritmalarının kısa bir hatırlatmasıyla başladı. Kör arama algoritmalarında bir kuyruk (liste, yığın ya da kuyruk; hangisi kullanılıyorsa) vardı ve durumlar bu yapıdan çekiliyordu. Çekme işlemi ya tamamen mekanikti (baştan çek, sona ekle, başa ekle gibi) ya da uniform cost search'te olduğu gibi kökten o duruma kadarki maliyete bakılıyordu. Bu algoritmalar hedefe ne kadar yakın olunduğunu bilmedikleri için "kör"dü.

Sezgisel arama algoritmaları ise hedefe olan tahmini uzaklığı da işin içine katar. Bu bilgi kesin değil, tahminidir.

**Soru (hoca sordu):** Sezgisel arama algoritmaları daha iyi çözümler mi buluyordu? **Cevap:** Hayır; bir öğrencinin dediği gibi, aynı kalitedeki (optimum) çözümleri daha hızlı buluyorlardı.

Bu derste görülecek lokal arama algoritmaları da sezgiyi, yani hedefe olan tahmini yakınlığı kullandıkları için sezgisel algoritmalardır. Ama şimdiye kadar görülen kör ve sezgisel arama algoritmalarından farklı bir problem türüne hitap ederler.

## 2. Lokal Aramanın Çözdüğü Problem Türü

Şimdiye kadar çözülen problemler hep aynı biçimde tanımlanmıştı: bir başlangıç durumu, bir hedef durumu ve durumlar arası geçiş operatörleri. Kullanıcının istediği şey, başlangıçla bitişi birleştiren bir yol, yani bir operatör dizisiydi. Su bidonları problemi, çiftçinin kurt, keçi ve kabakla karşıya geçmesi, labirentte bir robotun hedefe en kısa yoldan gitmesi ya da navigasyon cihazında bir noktadan diğerine en hızlı yolun bulunması hep bu türdendi.

Lokal arama algoritmalarının slaytındaki tanım şöyledir (ekrandan, 00:10:00):

- Birçok optimizasyon probleminde hedefe giden yol / uygulanan hareketler önemsizdir. Hedef durumun kendisi istenen çözümdür.
- Amaç, arama uzayında istenen kısıtlara / özelliklere sahip / fayda fonksiyonunu maksimum yapan durumu bulmaktır. Örnek: n-vezir, zirve bulmak.
- Bu durumlarda lokal arama algoritmaları kullanılır.
- Hafızada sadece mevcut durum tutulur ve düzeltilmeye çalışılır.
- Çok az hafıza gereksinimi vardır.

Kullanıcı burada bir durumu tarif eder ("şurası şöyle, burası böyle olsun") ama o durumun ne olduğunu söylemez. Bu tarif bir fayda fonksiyonu gibi bir şeyle ifade edilir. Kullanıcı o duruma nasıl gidildiğiyle, nerelerden geçildiğiyle ilgilenmez. Bir süreç tutmaya gerek olmadığı, yalnız mevcut durumu iyileştirmek yeterli olduğu için hafıza gereksinimi çok azdır.

### 2.1 n-Vezir Problemi

Slayttaki tanım (ekrandan, 00:15:00):

- N veziri $n \times n$ lik bir satranç tahtasına hiçbiri birbirini tehdit etmeyecek şekilde yerleştir.
- Hiçbir satır, sütun ve diyagonalde birden fazla vezir olmamalı.
- Bir durumdan başla, onu iyileştirerek devam et.

Normal satranç tahtası için bu $8 \times 8$ tahtaya 8 vezir yerleştirmektir. İstenen şey bir durumdur: vezirlerin yerlerinin söylendiği bir satranç tahtası. Çözüm sürecinde yine bir yerden başlanıp adım adım ilerlenecek, ama kullanıcı bunlarla ilgilenmeyecektir.

Önceki arama problemlerinden farkı şudur: orada bir durumdan operatörlerle yeni durumlara geçerek başlangıçla hedef arasında yol çiziliyordu. Burada da durumlar arası geçiş vardır, ama ne başlangıç ne bitiş verilmiştir. Başlangıç durumu rastgele seçilir. Slayttaki $4 \times 4$ örnekte (ekrandan, 00:15:00) vezirler tamamen rastgele atılmaz; her sütuna rastgele bir vezir konur, böylece bir sütunda birden fazla vezir olmaz. Sonra bu tahtaya bir operatör uygulanır, yeni bir tahta elde edilir, ona da bir operatör uygulanır ve en sonunda kullanıcının istediği özelliklere sahip bir tahtaya varılır. Kullanıcıya yalnız bu son tablo verilir.

## 3. Tepe Tırmanma (Hill Climbing)

Bütün lokal arama algoritmalarının temelinde tepe tırmanma algoritması vardır. Slayttaki maddeler şunlardır:

- Yoğun bir siste Everest Dağı'na tırmanmaya benzer. Sadece etkin durumun bilgisini tutar.
- Ana düşünce: her zaman, şimdiki durumu en fazla geliştiren yönde adım at.
- Best-first search'e benzer.
- Öğrenme algoritmalarında (ör. YSA) popülerdir.
- Yaylada ve sıralı tepelerde şaşabilir.

### 3.1 Sisli Dağ Benzetmesi

Hoca bu benzetmeyi şöyle açtı: Sizi bir tepenin yamacında bırakıp en yüksek yere çıkmanızı istiyorlar ve elinize yalnız deniz seviyesinden yüksekliğinizi gösteren bir barometre veriyorlar. Hava çok açık olsaydı en yüksek zirveyi gözünüzle görüp oraya yönelebilirdiniz; önünüzdeki bir çıkıntıyı aşmanız gerektiğini, ileride daha yüksek yerler olduğunu algılayabilirdiniz. Ama genelde olan, yoğun bir sis altında ilerlemektir: yalnız etrafınızdaki birkaç metrekarelik alanı algılayabilirsiniz.

Arama uzayında da durum budur. Belli bir alanı algılamak mümkündür, ama daha fazlasını algılamak bazen fiziksel olarak, bazen problemin yapısı gereği, bazen de hesaplama açısından mümkün değildir. Bir sınır koymak gerekir.

Ana düşünce best-first search'e çok benzer. Orada kuyruktaki durumlardan hedefe en yakın görüneni seçiyorduk. Burada da mevcut durumdan yeni durumlar üretilir ve aralarından mevcut durumu en fazla iyileştirene atlanır.

Hoca, yapay sinir ağlarının eğitiminde kullanılan algoritmanın da temelde tepe tırmanma olduğunu söyledi. Orada istenen durum, eğitim kümesiyle en uyumlu ağ ağırlıklarıdır: örneğin 100 bin ağırlığın, veri kümesindeki bütün örnekler için en yüksek başarıyı veren değerleri. Bir yerden başlanır ve adım adım iyileştirilir.

### 3.2 Tek Boyutlu Bir Fonksiyon Üzerinde Tepe Tırmanma

Hoca slayta tepeli bir eğri çizdi ve bir yıldızla başlangıç noktasını işaretledi (ekrandan, 00:25:00). Yatay eksen $x$, dikey eksen $f(x)$'tir. Bu noktada iki operatör vardır: belli bir büyüklükte sola ya da sağa gitmek. Elimizde yalnız barometre olduğu için iki tarafın yüksekliğine bakarız: sola gidince yükseklik azalıyor, sağa gidince artıyorsa sağa gideriz. Bir sonraki adımda yine yalnız o noktanın çevresi görülür ve yine iyileştiren yöne gidilir.

Bir noktada sağa da sola da gitmek mevcut durumu iyileştirmez; iki komşu da bulunulan noktadan daha kötüdür. Algoritma burada biter. Bulunulan yerde sevinilir, ama uzayın başka bir yerinde çok daha yüksek bir tepe olabilir.

**Soru (hoca sordu):** Buradan lokal arama algoritmaları hakkında ne söyleyebiliriz? **Cevap:** Optimal değillerdir. Optimal olsalardı her seferinde en iyi çözümü bulmaları gerekirdi.

**Soru (hoca sordu):** Buldukları çözüm en temel olarak neye bağlıdır? **Cevap:** Başlangıç noktasına. Eğrinin belli bir bölgesinden başlanırsa hep aynı tepeye varılır; başka bir bölgeden başlanırsa başka bir tepeye.

### 3.3 Algoritma

Slayttaki sözde kod (ekrandan, 00:25:00; kaynak olarak AIMA sözde kod deposu gösteriliyor):

```text
function HILL-CLIMBING(problem) return a state that is a local maximum
  input: problem, a problem
  local variables: current, a node.
                   neighbor, a node.

  current <- MAKE-NODE(INITIAL-STATE[problem])
  loop do
    neighbor <- a highest valued successor of current
    if VALUE[neighbor] <= VALUE[current] then return STATE[current]
    current <- neighbor
```

Fonksiyon bir problem alır ve bir durum döndürür. Döndürülen durumun lokal bir maksimum olduğu zaten söylenmektedir; global maksimum da olabilir ama büyük ihtimalle değildir.

- `current`, başlangıç durumuyla (initial state) başlatılır.
- Döngüde `neighbor`, `current`'tan tek bir operatör uygulanarak gidilebilecek bütün durumlar (ardıllar, successor) içinde en yüksek değerli olandır. Tek boyutlu örnekte iki ardıl vardır: biraz sola ve biraz sağa.
- `VALUE[neighbor] ≤ VALUE[current]` ise, yani hiçbir ardıl mevcut durumu iyileştiremiyorsa, mevcut durum döndürülür. Çizimde yıldızın iki komşusu (kalpler) yıldızın değerini geçemiyorsa bu durum oluşur.
- Değilse `current ← neighbor` yapılır ve arama o noktadan devam eder.

Ardıl sayısı, tanımlanan operatörlere bağlıdır. İki olmak zorunda değildir; daha yüksek boyutlu bir uzayda çok daha fazla ardıl olabilir.

**Soru:** Bu lokal tepeden kurtulmak için ne yapılabilir? **Cevap:** Lokallik problemini aşmak için çeşitli yöntemler vardır; derste ilerleyen bölümde anlatıldı (bkz. bölüm 6-8).

## 4. Tepe Tırmanmanın Problemleri

Slayttaki maddeler (ekrandan, 00:35:00):

- İlk duruma bağlı.
- Lokal maksimum, plato ve sırtlara takılabilir.

Slayttaki şekil, yatay ekseni durum uzayı (state space), dikey ekseni amaç fonksiyonu (objective function) olan bir eğridir. Üzerinde şu bölgeler işaretlidir: global maksimum (en yüksek tepe), omuz (shoulder; yükselişin ortasında düz bir basamak), lokal maksimum (daha alçak bir tepe), "flat" lokal maksimum (tepesi düz olan bir bölge) ve mevcut durum (current state).

Mevcut durum lokal maksimumun eteğindeyse tepe tırmanma o lokal maksimuma çıkar ve orada durur; çok daha iyisi olsa bile başlangıç noktasından oraya varamaz. Düz bölgelerde (plato) sağa da sola da gitmek aynı değeri verir. Algoritma yalnız mevcut durumu iyileştiren bir hareket varsa ilerlediği için düz bölgede de durur. Rastgele hareketler yapılabilirdi, ama bu algoritma öyle değildir.

## 5. 8-Vezir Problemini Tepe Tırmanma ile Çözmek

Kullanıcı bir satranç tahtasına sekiz veziri hiçbiri birbirini tehdit etmeyecek şekilde yerleştirmemizi istiyor. Bizden ne başlangıç durumu ne de çözüme nasıl gidildiği isteniyor; yalnız çözüm isteniyor. Bu tam bir lokal arama problemidir ve en temel algoritma olan tepe tırmanma kullanılabilir.

### 5.1 Durum, Operatör ve Ardıl Sayısı

Slayttaki açıklama (ekrandan, 00:40:00): "Herbir sütuna bir rasgele bir vezirle başla. Her bir adımda sadece bir veziri sadece aşağı ya da yukarı x adım hareket ettirerek çözümü ara."

Başlangıç durumunda her sütuna bir vezir konur ve vezirin sütundaki yeri sekiz satırdan rastgele biri olur. Hedef durumun ne olduğu bilinmez; bilinseydi problem zaten olmazdı. Bu yüzden ona ne kadar uzak olunduğu da tam bilinmez. Gereken, mevcut durumun hedefe olan uzaklığına dair tahmini bir bilgidir: bir hareketin bizi iyileştirip iyileştirmediğini söyleyen bir geri bildirim. Buna değerlendirme fonksiyonu, sezgisel (heuristic) fonksiyon, amaç (objective) fonksiyonu ya da minimizasyon yapılıyorsa kayıp (loss) fonksiyonu gibi adlar verilebilir.

Operatör: herhangi bir veziri seç ve onu bulunduğu sütunda istediği kadar ileri ya da geri götür. Diğer vezirler sabit kalır.

**Soru (hoca sordu):** Bu operatörle bir durumdan gidilebilecek durum sayısı kaçtır? **Cevap:** Her sütundaki vezir 7 farklı kareye gidebilir ve 8 sütun vardır: $7 \times 8 = 56$. Bu, önceki arama algoritmalarındaki dallanma faktörüne (branching factor) karşılık gelir; algoritmadaki ardıl sayısı 56'dır.

### 5.2 Sezgisel Fonksiyon

Algoritma "en yüksek değerli ardıl" dediği için durumların bir değeri olmalıdır. Slaytta (ekrandan, 00:40:00):

- $h$ = birbirini tehdit eden vezir çifti sayısı.
- Yukarıdaki tahta / durum için $h = 17$.

Hoca 17 çifti sınıfla birlikte saydı; sayarken bir öğrenci en sağdaki iki vezirin çapraz tehdidinin atlandığını hatırlattı ve sayı 17'ye tamamlandı.

$h$ azaltılmaya çalışılır. Bu yüzden burada yapılan işi tepe tırmanma yerine "çukur inme" olarak düşünmek de mümkündür; yapı aynıdır. Mevcut $h$ 17'dir ve 56 durumun her birinin $h$ değeri hesaplanıp 17'den en fazla azalmayı sağlayan duruma gidilir.

### 5.3 Tahtadaki Sayıların Anlamı

**Soru (hoca sordu):** Satranç tahtasındaki karelerde yazan 13, 15, 18, 12 gibi sayılar nedir? **Cevap (bir öğrenci):** Veziri o kareye götürdüğümüzde oluşacak $h$ değeri. Hoca bunu onayladı: diğer bütün vezirler yerinde dururken o sütundaki vezir o kareye götürülürse oluşacak $h$ değeridir. Örneğin ilk sütunun en üstündeki 18, o sütunun veziri oraya taşınırsa $h$'nin 18 olacağını gösterir; bu kötü bir harekettir.

Slayttaki tahta (ekrandan, 00:40:00; V: vezir, satırlar yukarıdan aşağı):

| Satır | S1 | S2 | S3 | S4 | S5 | S6 | S7 | S8 |
|---|---|---|---|---|---|---|---|---|
| 1 | 18 | 12 | 14 | 13 | 13 | 12 | 14 | 14 |
| 2 | 14 | 16 | 13 | 15 | 12 | 14 | 12 | 16 |
| 3 | 14 | 12 | 18 | 13 | 15 | 12 | 14 | 14 |
| 4 | 15 | 14 | 14 | V | 13 | 16 | 13 | 16 |
| 5 | V | 14 | 17 | 15 | V | 14 | 16 | 16 |
| 6 | 17 | V | 16 | 18 | 15 | V | 15 | V |
| 7 | 18 | 14 | V | 15 | 15 | 14 | V | 16 |
| 8 | 14 | 14 | 13 | 17 | 12 | 14 | 12 | 18 |

Tablodaki 56 değer ve başlangıçtaki $h = 17$, vezir konumlarından python ile yeniden hesaplanarak doğrulandı.

> **Ders sonrası not:** Altyazıda hocanın bu tahtada mevcut $h$ için "11" dediği bir yer var (00:43:19). Slayta ve hesaba göre mevcut değer 17'dir; büyük olasılıkla dil sürçmesi ya da Whisper hatasıdır.

En düşük değer 12'dir ve tahtada sekiz tane 12 vardır. Bunlardan biri rastgele seçilir ve vezir oraya taşınır. Sonra tahta yeniden hesaplanır: bu sefer yeni bir 56 durum oluşur, her birinin $h$ değeri hesaplanır ve yeni $h$'yi (12) en fazla azaltan duruma gidilir.

### 5.4 Arama $h = 1$'de Neden Durdu?

Slaytta bir çözüm örneği gösterildi (ekrandan, 01:05:00): adım adım ilerlenmiş ve $h = 1$ olan bir tahtaya gelinmiş. Tahtada yalnız bir vezir çifti hâlâ birbirini tehdit ediyor.

**Soru (hoca sordu):** Arama burada neden durdu? **Cevap:** Bu durumdan gidilebilecek 56 durumun hiçbirinin $h$ değeri 1'den küçük değildir. Mevcut durumdan daha iyi bir yere gidilemediği için algoritma durur.

$h = 1$'de durmanın ne anlama geldiği problem hakkındaki bilgiye bağlıdır. $h$'nin 0 olabileceği, yani problemin bir çözümü olduğu biliniyorsa, lokal bir minimuma takılmışızdır. Bilinmiyorsa belki de yapılabilecek en iyi şey budur ve global minimumdayızdır. $h = 0$ bulunsaydı zaten global minimuma ulaşılmış olurdu. 8-vezir probleminin çözümü vardır; yani $h$'yi sıfıra indirmek mümkündür, ama bu çalıştırmada indirilememiştir.

**Soru (hoca sordu):** $h$'yi sıfıra indirememiş olmamızın sebebi nedir? **Cevap:** Başlangıç pozisyonu. Rastgele bir yerden başlanıp $h = 17$'den adım adım $h = 1$'e inildi. Hoca bunu eğri üzerinde gösterdi: $h = 1$'lik bir çukura varılmış, ama yanında $h = 0$'lık daha derin bir çukur var. Oraya erişmek için algoritmayı değil, başlangıç konumunu değiştirmek gerekir.

**Soru:** Başlangıç konumu aslında iyi olsa bile, 56 hamleden birkaçı aynı en düşük değere sahipken yaptığımız rastgele seçim bizi kötü bir yere götürmüş olabilir mi? **Cevap:** Evet, olabilir. Süreçte stokastik bir şey yokmuş gibi davranıldı ama aslında var: ilk tahtada sekiz tane 12 vardı ve biri rastgele seçildi. Başka bir 12 seçilseydi daha iyi bir yere varılabilirdi. Ancak lokal minimum ve maksimumlardan kurtulmak için önerilecek yöntemler bu durumu değiştirmez.

**Soru:** Takılınan yerleri bir yerde tutup oradan devam ederek, dinamik programlamaya benzer bir yapıyla bu problem çözülebilir mi? **Cevap:** Yapılabilir, ama tepe tırmanmanın hafıza verimliliği kaybolur. Gidilebilecek her durumu bir yerde biriktirmek gerekir; onlardan da yeni durumlar çıkacağı için bu yapı çok büyüyebilir.

### 5.5 8-Vezirde Tepe Tırmanmanın Performansı

Slayttaki bilgiler (ekrandan, 01:15:00):

- Rastgele başlangıç değerleriyle,
- Denemelerin %14'ünde çözer,
- %86'sında lokal bir maksimuma takılır,
- $8^8 = 2^{24} \approx 17$ milyon durum.

Yani 100 farklı başlangıçla çalıştırıldığında yaklaşık 86'sında $h$ sıfıra inmez, 1 ya da 2 gibi bir değerde takılır.

> **Ek bilgi (derste anlatılmadı):** $8^8 = 16\,777\,216$ sayısı, her sütunda tam bir vezir bulunan bütün tahtaların sayısıdır. Tepe tırmanma bu uzayın yalnız çok küçük bir kısmını gezerek sonuca ulaşır; bu yüzden hızlıdır ama bir lokal minimuma takılabilir.

## 6. Lokal Tepelerden Kurtulma: Rastgele Yeniden Başlatma

Slayttaki çözüm alternatifleri (ekrandan, 01:10:00):

- Tepe tırmanmayı farklı başlangıçlarla tekrarlamak (random-restart hill climbing),
- Benzetimli tavlama (simulated annealing),
- Paralel tepe tırmanma (local beam search).

En basit çözüm tepe tırmanmayı farklı başlangıçlarla tekrarlamaktır. Bir yerden başlanır, $h$ bir yere kadar indirilir; başka bir yerden başlanır, yine indirilir. $h$'yi sıfıra indirene kadar devam edilebilir.

Çözümün varlığı bilinmiyorsa durum farklıdır. Yüz, bin, milyon deneme yapılır ama $h$ sıfıra inmez. Ne kadar çok tekrar yapılırsa çözümün olmadığına dair inanç o kadar artar. Ama hiçbir zaman "bu problemin çözümü yoktur" denemez; belki milyon birinci denemede bulunacaktı. Deneme sayısına bağlı olarak "büyük olasılıkla daha iyi çözüm yoktur" gibi bir yorum yapılabilir, kesin bir hüküm verilemez.

## 7. Benzetimli Tavlama (Simulated Annealing)

### 7.1 Ad ve Sezgi

Algoritmanın adı çelik yapımındaki tavlama sürecinden gelir. Çelik normal soğumaya bırakılınca sıcaklığı zamanla düzgünce düşer ve belli bir kalitede malzeme elde edilir. Sıcaklık ise önce azalıp sonra bir süre artacak, sonra yine azalıp yine artacak biçimde düşürülürse, yani soğuma sürecinin içine ısıtma süreçleri eklenirse, elde edilen malzemenin daha dayanıklı ve kaliteli olduğu anlatılır. Hoca bu konuda "anlatanların yalancısıyım" dedi.

Algoritmaya çevrilince "soğutma", fonksiyonu istenen yöne götürmektir (örneğin birbirini tehdit eden vezir çifti sayısını azaltmak). Araya eklenen "ısıtma" ise kötüleşmeye izin vermektir. Slayttaki maddeler (ekrandan, 01:10:00, slayt listesinde):

- Ana fikir: yerel maksimumdan kaçmak için istenmeyen hareketlere izin ver.
- Rastgele bir hareket üret. İyileşme varsa kabul et. Yoksa zamanla ve kötüleşme miktarıyla azalan bir olasılıkla kabul et.
- Zaman içinde rastgele hareketin boyutu (yeni noktanın uzaklığı bir dağılımdan üretilirse) ve kabul olasılığı azaltılır.

Hoca bunu bir eğri üzerinde gösterdi. Bir lokal tepenin eteğindeyken her zaman iyi olan seçilirse o tepeye çıkılır ve orada kalınır. O an için daha kötü olan bir yere (çukura doğru) gitmeye izin verilirse, belki o lokal maksimumdan kurtulup daha yüksek bir tepeye doğru ilerlenebilir. Bunun garantisi yoktur: aynı hareket, yüksek bir yere çıkacakken daha alçak bir yere gitmeye de sebep olabilir. Bu olasılıksal bir mekanizmadır; amacı uzayın daha çok yerini taramak, daha çok alan görmektir.

### 7.2 Algoritma

Slayttaki sözde kod (ekrandan, 01:20:00):

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
    if dE > 0 then current <- next                       (iyileşme varsa kesin kabul)
    else current <- next only with probability e^(dE/T)  (iyileşme yoksa belki)

Schedule: T = T0 * 0.95^t
Belki, kötüleşme miktarına (dE) ve geçen zamana bağlı.
```

Tepe tırmanmadan farkı şudur: gidilebilecek durumların hepsi birden üretilmez, aralarından bir tanesi rastgele üretilir. $\Delta E$, seçilen ardılın değeri ile mevcut değer arasındaki farktır. $\Delta E > 0$ ise seçilen adım mevcut durumdan daha iyidir ve oraya kesinlikle gidilir. Değilse yine gidilir, ama yalnız $e^{\Delta E / T}$ olasılıkla. Örneğin olasılık 0,5 olsaydı yazı-tura atılır, yazı gelirse adım atılırdı.

$T$, çizelge (schedule) fonksiyonuyla bulunur: $T = T_0 \cdot 0{,}95^t$. $T_0$ sabit bir değerdir. Döngü $t = 1$'den sonsuza kadar döner; $t$ arttıkça $0{,}95^t$ ve dolayısıyla $T$ giderek sıfıra yaklaşır. Bilgisayarın sayıyı tutma kapasitesi nedeniyle bir noktada $T$ sıfır olur ve o anki durum döndürülür.

> **Ders sonrası not:** Altyazıda çizelge "$T_0$ çarpı 0,95 çarpı $T$" gibi geçiyor (01:20:03). Slayttaki doğru ifade $T = T_0 \cdot 0{,}95^t$'dir; hoca da hemen ardından "0,95 üzeri t" diyor.

Olasılıktaki iki etken şunlardır:

- **Kötüleşme miktarı ($\Delta E$):** Bir hareket değeri $-0{,}001$ kadar, diğeri $-10$ kadar kötüleştiriyorsa, az kötüleştirenin seçilme ihtimali çok daha yüksektir.
- **Zaman ($T$):** Başlangıçta kötüleştiren hareketlere izin verme olasılığı yüksektir. Zaman ilerledikçe bu olasılık azalır; algoritma sürekli daldan dala rastgele dolaşmaz, uzayın belli bir kısmını keşfettikten sonra bulduklarının en iyisi üzerinde daha ayrıntılı arama yapar.

**Soru (hoca sordu):** Kabul olasılığı sıfır olursa algoritma neye dönüşür? **Cevap:** Tepe tırmanmanın çok benzerine: iyileşme varsa kabul eder, yoksa olduğu yerde kalıp bir sonraki adıma geçer. Benzetimli tavlamanın son evreleri böyledir.

> **Ek bilgi (derste anlatılmadı):** Rastgele bir ardıl üretip yalnız iyiyse kabul eden algoritmaya literatürde "ilk seçim (first-choice) tepe tırmanma" ya da stokastik tepe tırmanma denir. Benzetimli tavlamanın $T \to 0$ sınırındaki davranışı buna karşılık gelir.

### 7.3 Konfor Alanı Benzetmesi

Hoca kötüleşmeye izin vermenin mekanik olmayan bütün sistemlerde biraz bulunduğunu söyledi. Mevcuda göre sürekli iyileşme hedeflenirse en yakın tepeye varılır. Bir an için kötüleşme kabul edilirse uzun vadede daha işe yarar bir yere erişmek mümkün olabilir. Kişisel gelişimde söylenen "konfor alanınızı bozun" sözü buna benzer: zor gelen, uğraştıran bir şey yapmak dünyayı büyütebilir, bakış açısını genişletebilir; ama bunun da garantisi yoktur. Hoca, daha düşük maaşla yeni bir işe geçmeyi göze almak gibi gündelik hayattan pek çok örnek verilebileceğini söyledi.

**Soru:** Algoritma bir çukurdayken önce sağa sonra sola giderek orada bir süre takılır mı, yoksa diğer tarafa geçtikten sonra tepeye doğru mu ilerler? **Cevap:** Kesin bir şey söylenemez; algoritmanın hiperparametrelerine bağlıdır. Rastgele seçtiği ardıl iyi tarafa doğruysa oraya gider; sonraki adımda belki biraz daha ilerler, belki geri döner. Geri dönebilir, ama yeni tepeye doğru ne kadar ilerlediyse geri dönmesi o kadar zorlaşır: "konfor alanına" ne kadar alışırsa oradan çıkması o kadar zorlaşır.

## 8. Paralel Tepe Tırmanma (Local Beam Search)

En yüksek noktayı bulmak için tek bir dağcı yerine aynı anda birçok dağcı gönderilir. Dağcılar birbirleriyle haberleşebilir ve birbirlerinin yerine ışınlanabilir.

Slayttaki maddeler (ekrandan, 01:30:00):

- Ana fikir: tek bir durumu izlemek yerine $K$ tanesini izle.
- $K$ adet rastgele üretilmiş durumla başla.
- Her bir iterasyonda $k$ durumun hepsinden gidilebilecek tüm durumları üret.
- Bu durumlardan biri hedefse dur. Değilse, en iyi $k$ tanesini mevcut durumlar olarak ata ve bir önceki adıma dön.
- $K = 5$: $5 \times 56 = 280$ durum üret.

8-vezir için $K = 5$ seçilirse 5 farklı rastgele tahtayla başlanır. Her iterasyonda her tahtanın 56 ardılı üretilir: $5 \times 56 = 280$ durum. Buradaki 5 bizim seçimimizdir; 56 ise problemden gelir, ama onun da 56 olmasının sebebi operatörleri öyle tanımlamış olmamızdır. 280 durumun içinde $h = 0$ olan varsa durulur (büyük olasılıkla yoktur). Yoksa 280 durumun en iyi 5 tanesi seçilir ve arama bu 5 tahtayla devam eder. Slaytta sonradan eklenen ifadeyle: $i$. nesil $K = 5$ tahtadır; 280 tahtanın en iyi 5'i $(i+1)$. nesildir.

**Soru:** Seçilen 5 tahtanın birden fazlası aynı tahtadan türemiş olabilir mi? Her tahtadan en iyisini mi alıyoruz, yoksa bir tahtanın iki ardılı diğer tahtaların bütün ardıllarından iyiyse ikisini birden mi alıyoruz? **Cevap:** Her ikisi de olur. Burada gidilen yolu kısaltmak gibi bir dert yoktur; pratikte istenen çözümü söylemektir. Hoca soruyu şöyle de yorumladı: $i$. nesildeki 5 tahta, üretilen 280 tahtaya katılıp 285 tahta içinden mi en iyi 5'i seçilmeli, yoksa yalnız 280 içinden mi? İkisi de mümkündür.

## 9. Bozuk Televizyon ve Şifreli Kasa

### 9.1 Bozuk Televizyon

Slayttaki problem (ekrandan, 01:45:00):

- Televizyonunuzun görüntüsü bozuk.
- Görüntü ayarı için 4 kontrol düğmesi var.
- Her bir düğmenin 100 farklı pozisyonu var.
- Nasıl bir yol izlersiniz?
- Peki ya kasa açsanız?

Hikâye eski zamanlarda geçer: televizyonda uzaktan kumanda yoktur, görüntü üzerindeki çevirmeli düğmelerle ayarlanır. Görüntü bozulmuştur, çok istediğiniz bir maçın başlamasına 5 dakika vardır ve maç kaydedilip sonra izlenemez. Hocanın yazdığı başlangıç durumu (ekrandan, 01:35:00):

```text
4 düğme
A 1-100  42
B 1-100  23
C 1-100  92
D 1-100  41
```

Bir öğrenci dört haneli şifre denemesi gibi 1-1-1-1'den başlayıp 100-100-100-100'e kadar bütün kombinasyonları denemeyi önerdi. Bu $100^4 = 10^8$, yani 100 milyon olası durum demektir; 5 dakikada bu kadar şanslı olunamaz.

Başka bir öğrenci şunu önerdi: bir düğmeyi (örneğin A'yı 42'den) artırırız; görüntü bozuluyorsa artırmamamız gerektiğine karar verip azaltırız; sonra B, C ve D'ye geçeriz ve bunu iteratif yaparız. Hoca bunu "önce A'yı optimize et" diye özetledi: düğmeyi çevirirken ekrana bakılır; 42, 43, 44, 45 iyileşiyor, 50'de iyi, 51-52'de kötüleşmeye başlıyorsa A'nın iyi değeri bu civardadır (örnekte 51). Sonra B, C ve D için aynısı yapılır, gerekirse yeniden A'ya dönülür.

Hocanın tahtaya yazdıkları (ekrandan, 01:40:00):

```text
ilk önce A yı opt et 51
B
C
D
(51 65 78 92)
100+100+100+100=400
100 milyon
```

Bir düğmeyi optimize etmek en fazla 100 adım sürer; dört düğme için en fazla 400 durum denenir. Yani 100 milyon olası durumdan yalnız 400'üne bakılmış olur.

**Soru (hoca sordu):** Bulunan (51, 65, 78, 92) değerleriyle lokal bir yerde takılmış mıyız? **Cevap:** Büyük olasılıkla. Uzayın yalnız $400 / 10^8$'i, yani 250 binde biri taranmıştır. Tamamı taransaydı bulunan sonucun en iyisi olduğundan emin olunabilirdi, ama buna zaman yetmez.

Zaman yetmiyorsa lokal bir çözümle mutlu olunur: maç izlenebilir. Mükemmel kalitede izlemek için belki bir yıl televizyonun başından ayrılmadan ayar yapmak gerekirdi; bu pratikte mümkün değildir. Arama uzayının çok büyük olduğu ve optimum çözümü bulmanın pratikte uygulanabilir olmadığı durumlarda lokal arama işimize yarayan, bizi idare eden çözümler bulmamızı sağlar. Çoğu problem için optimumu bulmak pek mümkün değildir.

### 9.2 Şifreli Kasa

Aynı dört düğme ve aynı başlangıç değerleri bu kez şifreli bir kasanın üzerinde olsun.

**Soru (hoca sordu):** Deminkinden farklı bir şey yapar mısınız? **Cevap (bir öğrenci):** Bu sefer sırayla optimize etme gibi bir şansımız olmaz, çünkü kasa iyiye gidip gitmediğimizi söylemez.

Televizyonda ekran, hedefe yaklaşıp uzaklaşıldığına dair bilgi veriyordu. Kasa böyle bir bilgi vermiyorsa elimizde sezgisel bilgi yok demektir; sezgisel bir arama algoritması kullanılamaz ve yalnız kör arama kalır. Bu da 100 milyon olasılık demektir; hiçbir şey bilinmiyorsa kasanın şifresini denemenin pek anlamı yoktur. Bir şeyler biliniyorsa (örneğin şifrenin kasa sahibinin doğum tarihi olduğu, bütün sayıların tek ya da asal olduğu gibi) bazı olasılıklar önce denenebilir ve arama uzayı daraltılabilir; ama bu da sezgisel bilgi kullanmak demektir.

**Soru (hoca sordu):** Filmlerde eski tip kasaları açan hırsızlar kasaya stetoskop dayayıp kilidin sesini dinler. Bu ses orada ne olarak kullanılır? **Cevap:** Sezgi olarak. Sezgi, hedefe (kasanın açılmasına) yaklaşıp uzaklaştığımızı gösteren bir bilgi sunmalıdır; kilidin sesi de bunu sağlar.

## 10. Ayrık ve Sürekli Uzaylar

Slayttaki maddeler (ekrandan, 01:50:00):

- Ayrık uzayda lokal arama: bir noktadan gidilebilecek noktaların sayısı sınırlı. Hepsi denenebilir (8 vezir, labirent, çizge).
- Sürekli uzayda lokal arama: bir noktadan sonsuz noktaya gidilebilir. Hepsi denenemez. Hangi yöne, ne kadar? Eğim bize yol gösterir (gradient descent, konveks optimizasyon, YSA optimizasyonu).

Şimdiye kadar ve derste genelde ayrık uzayda çalışılır: bir durumdan gidilebilecek durum sayısı bellidir (56, 2 gibi). Sürekli uzayda ise bu sayı sınırsızdır; hepsini denemek ve kör arama yapmak mümkün değildir. Burada hedefe en hızlı hangi yönde yaklaşılacağını gösteren gradient descent algoritması yardımcı olur; en hızlı azalma yönünü gösterir.

Slayttaki örnek fonksiyon $f(x_1, x_2) = x_1^2 + 2x_2^2$'dir ve yanında eş yükselti eğrileri üzerinde bir optimizasyon yolu gösterilir (ekrandan, 01:50:00). Bu fonksiyonun minimumu gözle görülür: $(0, 0)$ noktası. Ama bakınca görülemeyecek kadar karmaşık birçok fonksiyon vardır. Yapay sinir ağlarının ya da SVM'in ağırlıklarını bulmak gibi makine öğrenmesindeki birçok yaklaşımda böyle sürekli uzaylarda optimizasyon yapılır. Süreç yine bir lokal aramadır: rastgele bir çözümle başlanır ve adım adım iyileştirilir; optimize edilen sezgisel fonksiyon minimizasyonda bir kayıp fonksiyonu, maksimizasyonda örneğin bir olabilirlik (likelihood) olabilir. Durumları değiştiren operatör de temelde gradient descent'tir.

Hoca slayta iki eğri çizdi. Tek çukurlu bir fonksiyonda, yani konveks bir fonksiyonda, nereden başlanırsa başlansın aynı yere varılır; bulunan lokal minimum aynı zamanda global minimumdur ve başlangıç noktasının önemi yoktur. Çok çukurlu bir fonksiyonda ise farklı başlangıçlar farklı çukurlara götürebilir. Çözüm yine farklı başlangıçlarla denemektir. Yapay sinir ağlarını farklı başlangıç ağırlıklarıyla eğitince farklı sonuçlara varılması, bunun bir lokal arama süreci olduğunun güzel bir kanıtıdır.

## 11. Uygulama: Bir Alanı Robotla Taramak

### 11.1 Problem

Son örnek bir uygulamadır; kodunun dersin sayfasında paylaşıldığı söylendi. Bir alanın bir robotla taranması istenir: robot alanın mümkün olduğu kadar çok yerinden geçmeli. Bu, bir tarladaki bütün bitkileri toplamak, tohum serpmek, her yeri sulamak ya da tarlayı havadan ilaçlamak gibi düşünülebilir. Ek olarak tarama minimum dönüş açısıyla yapılmalıdır: keskin dönüşler hızı azaltır, keskin dönüş ne kadar azsa alan o kadar hızlı taranır.

Slayttaki tanım (slayt listesinde, ekrandan, 01:50:00):

- Amaç: $N \times N$'lik bir alanda 8 yöne hareket, $N \times N - 1$ adet hareket; minimum açıda dönüşle maksimum alanı gez.
- Hareketler arası açı miktarı az olsun, yumuşak dönüşler yapsın.
- İyilik fonksiyonu 2 bileşene sahip: min(açı) ve max(alan).
- Temsil: $(N \times N - 1)$ adet, 0-8 arası yönleri belirten sayılar.

### 11.2 Çok Bileşenli İyilik Fonksiyonu

Hocaya göre bu örneğin güzel yanı, bir durumun iyiliğini belirten fonksiyonun tek bir bileşenden oluşmak zorunda olmamasıdır. Hem gezilen alanın maksimum, hem dönüşlerin minimum olması aynı anda istenebilir; daha fazla bileşen de tanımlanabilir. Önemli olan bunların nasıl birleştirildiğidir. Bir bileşenin aralığı 0-1000, diğerininki 0-1 ise ilkinin etkisi çok daha büyük olur ve optimizasyon ikincisine hiç bakmadan yapılır. Bileşenler buna dikkat edilerek ağırlıklandırılmalıdır.

### 11.3 Durum Gösterimi

$8 \times 8$'lik bir alan için 64 hücre vardır ve robot 63 hareket yapar. Bir durum 63 rakamdan oluşur; her rakam 0 ile 8 arasındadır ve hareket yönünü gösterir. Slayttaki yön şeması (ekrandan, 02:00:00):

```text
   2   1   8
    \  |  /
3 --   0   -- 7
    /  |  \
   4   5   6
```

0 yerinde kalmak, 1 yukarı, 2 sol üst, 3 sol, 4 sol alt, 5 aşağı, 6 sağ alt, 7 sağ, 8 sağ üst demektir.

### 11.4 Algoritma

Slayttaki algoritma (ekrandan, 01:55:00; dosya adı `tepe_tirmanma_tarama_1robot.m`):

```text
Rasgele bir çözümle başla
G kez:
  - Çözümden (%mu kadar) rasgele değişikliklerle P adet yeni çözüm üret
  - Üretilen çözümlerin iyilik değerlerini hesapla
      * Dönüş açılarını topla, gidilen farklı nokta sayısını topla
  - Üretilenlerden en iyisi mevcuttan iyi ise çözüme ata,
    mu oranını azalt; kötü ise mu oranını arttır
  - tk_max kez daha iyisi üretilmediyse çözümü rasgele başlat
```

Mevcut bir çözümden rastgele değişikliklerle yeni çözümler üretilir. Her çözüm için, o rakam dizisine göre hareket edilince kaç farklı noktanın gezileceği ve toplam ne kadar açı değişimi yapılacağı hesaplanır. $\mu$ rastgelelik oranıdır: başlangıçta daha yüksek oranda rastgele değişiklik yaptırılabilirken zamanla bu azaltılır. Algoritmaya rastgele yeniden başlatma (random restart) da eklenmiştir: $tk\_max$ kez daha iyisi üretilmezse çözüm rastgele yeniden başlatılır.

### 11.5 Sonuçlar

Slayttaki sonuç ekranı (ekrandan, 02:00:00) üç grafik ve parametreleri gösterir:

```text
P=200;        % (üretilen yeni çözüm sayısı)
mu=0.01;      % degisim orani
mu_dec=0.99;  % azalma orani
mu_inc=1.01;  % artma orani
tk_max=50;    % tk_max kez ayni kaldiysa restart
G=3000;       % iterasyon sayisi
```

- **Rastgele bir başlangıç:** robot sol alt köşe civarında küçük bir bölgede dolaşıp duruyor; kötü bir çözüm.
- **Sürecin ilerleyişi:** 3000 iterasyon boyunca iyilik değerinin grafiği. Değer adım adım iyileşiyor; belli bir süre (örneğin 50 kez) iyileşme olmayınca rastgele yeniden başlatma yapıldığı için grafikte sıçramalar görülüyor.
- **Bulunan en iyi çözüm:** alanın büyük kısmını kaplayan bir rota ve onun 63 rakamlık temsili.

Bulunan en iyi çözümün temsili (ekrandan, 02:00:00; slaytta 7 satır × 9 sütun olarak yazılmış):

```text
1 6 7 2 2 1 6 6 6
7 2 2 2 1 1 2 1 7
7 7 7 7 7 7 7 7 7
5 5 3 4 1 1 4 1 0
4 2 3 6 6 7 6 6 7
7 7 7 1 1 4 4 3 3
6 6 6 7 7 1 3 2 2
```

Hoca diziyi ilk satırdan okuyarak rotayı izledi: 1 uygulanınca bir hücre gidiliyor, sonra 6 (sağ alt çapraz), sonra 7 (sağa), sonra iki kez 2, sonra 1 (yukarı), sonra üç kez 6.

Bu çözüm fena değildir: çok geniş bir alanı kaplamaya çalışır. Ama mükemmel de değildir; gidilemeyen yerler vardır ve bazı yerlerden birden fazla geçilmiştir. Algoritma daha uzun çalıştırılırsa daha iyi çözümler bulunabilir.

**Soru (hoca sordu):** Bütün durumları denemeye kalksak kaç durum vardır? **Cevap:** Dizi 63 uzunluğundadır ve her eleman (0'ı saymazsak) 8 farklı değer alır: $8^{63}$ durum. Böyle bir uzayda kör aramayla ilerlemek mümkün değildir; sezgisel bilgi ve lokal arama kullanmak gerekir.

> **Ders sonrası not:** Gösterim 0-8 arası rakamlarla yapıldığı için 0 da sayılırsa durum sayısı $9^{63}$ olur. Hoca hesabı 0'ı dışarıda bırakarak $8^{63}$ diye verdi; iki sayı da kör aramanın imkânsız olduğunu gösterir.

Hoca son olarak iyilik fonksiyonuna yeni bileşenler eklenebileceğini örnekledi: örneğin robotun orta noktadan fazla ayrılmaması istenirse optimizasyon buna göre de yapılır ve rota büyük olasılıkla ortanın çevresinde dolaşan bir şekle döner.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:06:53): Sezgisel arama algoritmaları kör arama algoritmalarına göre daha iyi çözümler mi bulur?

> **Çözüm:** Hayır. Optimum çözümler söz konusu olduğunda aynı kalitedeki çözümü bulurlar, ama hedefe olan tahmini uzaklığı kullandıkları için daha hızlı bulurlar.

**Soru 2** (derste sözlü, 00:23:07): Tepe tırmanma gibi lokal arama algoritmaları optimal midir? Buldukları çözüm en temel olarak neye bağlıdır?

> **Çözüm:** Optimal değildirler. Buldukları çözüm başlangıç noktasına bağlıdır: hangi tepenin eteğinden başlanırsa o tepeye çıkılır.

**Soru 3** (ekrandan, 00:40:00; derste sözlü, 00:39:13): 8-vezir probleminde başlangıçta her sütunda bir vezir vardır ve her adımda yalnız bir vezir kendi sütununda aşağı ya da yukarı hareket ettirilir. Bir durumdan gidilebilecek durum (ardıl) sayısı kaçtır?

> **Çözüm:** Her vezir kendi sütununda 7 farklı kareye gidebilir, 8 sütun vardır: $7 \times 8 = 56$.

**Soru 4** (ekrandan, 00:40:00; derste sözlü, 00:42:39): Bölüm 5.3'teki tahtada $h$ = birbirini tehdit eden vezir çifti sayısıdır. Mevcut tahtanın $h$ değeri kaçtır, karelerde yazan sayılar ne anlama gelir ve tepe tırmanma bir sonraki adımda ne yapar?

> **Çözüm:** Mevcut tahta için $h = 17$. Her karedeki sayı, diğer vezirler yerinde dururken o sütunun veziri o kareye taşınırsa oluşacak $h$ değeridir. En küçük değer 12'dir ve tahtada sekiz tane 12 vardır; algoritma bunlardan birini rastgele seçip veziri oraya taşır, sonra yeni tahtanın 56 ardılını yeniden hesaplar.

**Soru 5** (ekrandan, 01:05:00; derste sözlü, 01:00:53): Tepe tırmanma 8-vezirde $h = 1$ olan bir tahtada durdu. Neden durdu, bu lokal minimum mudur ve neden $h = 0$'a inilemedi?

> **Çözüm:** 56 ardılın hiçbirinin $h$ değeri 1'den küçük olmadığı için durdu. 8-vezirin $h = 0$ olan bir çözümü olduğu bilindiğinden bu bir lokal minimumdur. Sebep başlangıç pozisyonudur; eşit değerli ardıllar arasındaki rastgele seçim de etkili olabilir. Çözümün varlığı bilinmeseydi bunun lokal mi global mi olduğu söylenemezdi.

**Soru 6** (ekrandan, 01:30:00; derste sözlü, 01:29:06): 8-vezirde paralel tepe tırmanma (local beam search) $K = 5$ ile çalıştırılırsa her iterasyonda kaç durum üretilir ve sonraki nesil nasıl seçilir?

> **Çözüm:** $5 \times 56 = 280$ durum üretilir. Biri hedefse ($h = 0$) durulur; değilse 280 durumun en iyi 5 tanesi sonraki nesil olur. İstenirse önceki 5 durum da adaylara katılıp 285 içinden seçim yapılabilir.

**Soru 7** (ekrandan, 01:45:00 ve 01:35:00): Televizyonunuzun görüntüsü bozuk. Görüntü ayarı için 4 kontrol düğmesi var (A=42, B=23, C=92, D=41), her düğmenin 100 farklı pozisyonu var ve maçın başlamasına 5 dakika var. Nasıl bir yol izlersiniz?

> **Çözüm:** Bütün kombinasyonları denemek $100^4 = 10^8$ deneme demektir. Bunun yerine ekrana bakarak düğmeler sırayla optimize edilir: önce A (örnekte 51), sonra B, C, D. Bu en fazla $4 \times 100 = 400$ deneme sürer (ekrandan, 01:40:00). Bulunan (51, 65, 78, 92) uzayın yalnız $400/10^8 = 1/250\,000$'ini taradığı için büyük olasılıkla lokal bir çözümdür, ama maçı izlemeye yeter.

**Soru 8** (ekrandan, 01:45:00; derste sözlü, 01:41:03): Aynı dört düğme şifreli bir kasanın üzerinde olsaydı ne değişirdi?

> **Çözüm:** Kasa, ekran gibi hedefe yaklaşılıp uzaklaşıldığını söylemez. Sezgisel bilgi olmadığı için sezgisel/lokal arama kullanılamaz, yalnız kör arama (100 milyon olasılık) kalır. Şifre hakkında ön bilgi (doğum tarihi, sayıların tek ya da asal olması gibi) varsa uzay daraltılabilir; bu da bir sezgi kullanmaktır.

**Soru 9** (derste sözlü, 01:43:43): Kasa hırsızları kasaya stetoskop dayayıp kilidin sesini dinler. Bu ses arama açısından nedir?

> **Çözüm:** Bir sezgidir: hedefe (kasanın açılmasına) yaklaşılıp uzaklaşıldığını gösteren bir geri bildirimdir.

**Soru 10** (derste sözlü, 01:58:35): Robotla alan tarama uygulamasında $8 \times 8$ alan için durum 63 uzunluğunda bir yön dizisidir. Bütün durumları denemek kaç durum demektir?

> **Çözüm:** Hocanın verdiği hesapla (0'ı saymadan) her eleman 8 değer alır: $8^{63}$ durum. 0 da sayılırsa $9^{63}$ olur. Her iki durumda da kör arama imkânsızdır; sezgisel bilgi ve lokal arama gerekir.

## Dersin Toparlaması

Bu derste, yolun değil durumun kendisinin istendiği problemler için lokal arama algoritmaları ele alındı. Bu algoritmalar yalnız mevcut durumu tutup onu iyileştirmeye çalıştığı için çok az hafıza kullanır. Temel algoritma tepe tırmanmadır: her adımda en iyi komşuya geçilir, hiçbir komşu daha iyi değilse durulur. 8-vezir örneğinde 56 ardıl ve birbirini tehdit eden vezir çifti sayısı ($h$) ile algoritmanın nasıl işlediği görüldü. Tepe tırmanmanın ilk duruma bağlı olduğu, lokal maksimum, plato ve sırtlara takılabildiği ve 8-vezirde denemelerin yalnız %14'ünde çözüme ulaştığı vurgulandı.

Bu sorunu aşmak için üç yol görüldü: rastgele yeniden başlatma, zamanla ve kötüleşme miktarıyla azalan bir olasılıkla kötüleştiren hareketlere izin veren benzetimli tavlama ve aynı anda $K$ durumu izleyen paralel tepe tırmanma. Bozuk televizyon ve kasa örnekleri, lokal aramanın büyük uzaylarda "yeterince iyi" çözümler için nasıl kullanıldığını ve sezgi olmadan sezgisel aramanın yapılamayacağını gösterdi. Sürekli uzaylarda aynı mantığın gradient descent ile uygulandığı, konveks fonksiyonlarda lokal minimumun global minimum olduğu anlatıldı. Robotla alan tarama uygulaması ise iyilik fonksiyonunun birden fazla bileşenden oluşabileceğini gösterdi. Bir sonraki derste lokal arama algoritmalarından genetik algoritmalar ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
