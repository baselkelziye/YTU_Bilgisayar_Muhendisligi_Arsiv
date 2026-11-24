# Ders 5 Çalışma Özeti

## Genel Konular

- Kör, sezgisel ve lokal arama arasındaki fark
  - Kör arama algoritmaları kuyruktan durum çekerken ya mekanik bir kural (baştan çek, başa/sona ekle) ya da köke kadarki maliyeti (uniform cost search) kullanır.
  - Sezgisel arama algoritmaları buna hedefe olan tahmini uzaklığı ekler. Aynı kalitede (optimum) çözümü daha hızlı bulurlar.
  - Lokal arama algoritmaları da sezgiyi kullanır, ama farklı bir problem türüne hitap eder: başlangıçla hedefi birleştiren bir operatör dizisi (yol) değil, istenen özelliklere sahip bir durumun kendisi aranır.
- Lokal arama algoritmalarının çözdüğü problem türü (ekrandan, 00:10:00)
  - Birçok optimizasyon probleminde hedefe giden yol önemsizdir; hedef durumun kendisi istenen çözümdür.
  - Amaç, arama uzayında istenen kısıtlara/özelliklere sahip ya da fayda fonksiyonunu maksimum yapan durumu bulmaktır. Örnek: n-vezir, zirve bulmak.
  - Hafızada yalnız mevcut durum tutulur ve düzeltilmeye çalışılır; hafıza gereksinimi çok azdır.
  - Başlangıç ve hedef durumu verilmez. Başlangıç durumu rastgele seçilir, operatörlerle adım adım yeni durumlara geçilir.
- n-vezir problemi (ekrandan, 00:15:00)
  - $n$ veziri $n \times n$ lik bir satranç tahtasına hiçbiri birbirini tehdit etmeyecek şekilde yerleştir. Hiçbir satır, sütun ve köşegende birden fazla vezir olmamalı.
  - Rastgele bir durumdan başlanır ve durum iyileştirilerek devam edilir. Başlangıçta her sütuna rastgele bir vezir konur.
- Tepe tırmanma (Hill Climbing)
  - Bütün lokal arama algoritmalarının temelidir. "Yoğun bir siste Everest Dağı'na tırmanmaya benzer": yalnız yakın çevre algılanabilir.
  - Ana düşünce: her zaman şimdiki durumu en fazla geliştiren yönde adım at. Best-first search'e benzer. Öğrenme algoritmalarında (ör. YSA) popülerdir.
  - Algoritma (ekrandan, 00:25:00): `current` başlangıç durumudur; döngüde `neighbor`, `current`'ın en yüksek değerli ardılıdır; `VALUE[neighbor] ≤ VALUE[current]` ise `current` döndürülür, değilse `current ← neighbor`.
- Tepe tırmanmanın problemleri (ekrandan, 00:35:00)
  - Sonuç ilk duruma bağlıdır.
  - Lokal maksimum, plato (düz bölge, "flat local maximum", omuz) ve sırtlara takılabilir.
  - Optimal değildir.
- 8-vezir problemini tepe tırmanma ile çözmek (ekrandan, 00:40:00)
  - Her sütuna rastgele bir vezirle başla. Her adımda yalnız bir veziri kendi sütununda aşağı ya da yukarı hareket ettir.
  - Ardıl sayısı (dallanma faktörü): $8 \times 7 = 56$.
  - Sezgisel fonksiyon: $h$ = birbirini tehdit eden vezir çifti sayısı. Gösterilen tahta için $h = 17$. Amaç $h$'yi azaltmaktır (tepe tırmanma yerine "çukur inme").
  - Tahtadaki sayılar, o sütundaki vezir o kareye taşınınca oluşacak $h$ değeridir. En küçük değer 12'dir ve sekiz tane 12 vardır; biri rastgele seçilir.
  - Örnek bir çalıştırma $h = 1$ olan bir tahtada durdu (ekrandan, 01:05:00): 56 komşunun hiçbiri $h$'yi 1'in altına indirmiyordu. Problemin çözümü olduğu bilindiği için bu bir lokal minimumdur.
- 8-vezirde tepe tırmanmanın performansı (ekrandan, 01:15:00)
  - Rastgele başlangıç değerleriyle denemelerin %14'ünde çözer, %86'sında lokal bir maksimuma takılır.
  - Her sütunda bir vezir varken durum sayısı $8^8 = 2^{24} \approx 17$ milyondur.
- Lokal tepelerden kurtulma yolları (ekrandan, 01:10:00)
  - Tepe tırmanmayı farklı başlangıçlarla tekrarlamak (random-restart hill climbing).
  - Benzetimli tavlama (simulated annealing).
  - Paralel tepe tırmanma (local beam search).
- Benzetimli tavlama (ekrandan, 01:20:00)
  - Ana fikir: yerel maksimumdan kaçmak için istenmeyen (kötüleştiren) hareketlere izin ver.
  - Rastgele bir ardıl üretilir. İyileşme varsa kesin kabul edilir; yoksa zamanla ve kötüleşme miktarıyla azalan bir olasılıkla kabul edilir.
  - Kabul olasılığı $e^{\Delta E / T}$, $\Delta E = \text{next.VALUE} - \text{current.VALUE}$. Sıcaklık çizelgesi $T = T_0 \cdot 0.95^t$. $T = 0$ olunca mevcut durum döndürülür.
- Paralel tepe tırmanma / local beam search (ekrandan, 01:30:00)
  - Tek bir durumu izlemek yerine $K$ tanesini izle. $K$ rastgele durumla başla, her iterasyonda hepsinden gidilebilecek tüm durumları üret.
  - Biri hedefse dur; değilse en iyi $K$ tanesini yeni mevcut durumlar olarak ata. 8-vezirde $K=5$ ise $5 \times 56 = 280$ durum üretilir.
- Bozuk TV ve kasa örnekleri (ekrandan, 01:35:00 - 01:45:00)
  - 4 düğme, her biri 1-100 arası; toplam $100^4 = 10^8$ durum. Düğmeleri sırayla optimize etmek en fazla $4 \times 100 = 400$ deneme ister.
  - TV ekranı sezgisel geri bildirim verir; kasa vermez. Sezgi yoksa yalnız kör arama kalır.
- Ayrık ve sürekli uzaylar (ekrandan, 01:50:00)
  - Ayrık uzayda bir noktadan gidilebilecek nokta sayısı sınırlıdır, hepsi denenebilir (8 vezir, labirent, çizge).
  - Sürekli uzayda sonsuz komşu vardır; yön eğimden bulunur (gradient descent, konveks optimizasyon, YSA optimizasyonu).
- Uygulama: bir alanı robotla tarama (ekrandan, 01:55:00 - 02:00:00)
  - $N \times N$ alanda 8 yöne hareketle, $N^2 - 1$ hareketlik bir rota; hem gezilen alan büyük hem dönüş açıları küçük olmalı.
  - İyilik fonksiyonu iki bileşenlidir: dönüş açılarının toplamı ve gidilen farklı nokta sayısı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Lokal aramada kullanıcı yolla ilgilenmez.
  - Nereden başlandığı ve nasıl ilerlendiği önemsizdir; yalnız tarif edilen kısıtlara uyan son durum istenir. Bu yüzden hafıza gereksinimi çok azdır.
- Lokal arama algoritmaları optimal değildir ve buldukları çözüm başlangıç noktasına bağlıdır.
  - Hoca bunu sınıfa sordu, cevap "başlangıç noktası" oldu. Daha iyi bir çözüme ulaşmak için algoritmayı değil başlangıç noktasını değiştirmek gerekir.
- Sezgi, hedefe yaklaşıp uzaklaşıldığını söyleyen bir geri bildirimdir.
  - Buna değerlendirme fonksiyonu, sezgisel (heuristic) fonksiyon, amaç (objective) fonksiyonu ya da minimizasyonda kayıp (loss) fonksiyonu denebilir.
- Lokal minimum mu global minimum mu olduğunu problem hakkındaki bilgi söyler.
  - $h = 0$ çözümünün var olduğu biliniyorsa $h = 1$'de durmak lokal minimumdur. Bilinmiyorsa belki de yapılabilecek en iyi şey budur.
  - Çok sayıda deneme çözüm olmadığına dair inancı artırır, ama "çözüm yoktur" dedirtmez.
- Benzetimli tavlamada $T$ zamanla küçülür.
  - Başta kötüleştiren hareketlere izin verme olasılığı yüksektir; sonra algoritma tepe tırmanmaya dönüşür. Uzay önce keşfedilir, sonra en iyi bölgede ayrıntılı arama yapılır.
  - Kötüleşmeye izin vermek kurtulmayı garanti etmez; olasılıksal bir mekanizmadır.
- Arama uzayı çok büyükse optimum çözüm pratikte bulunamaz.
  - Lokal arama işimize yarayacak, idare edecek bir çözüm verir (bozuk TV: maç başlamadan görüntüyü düzeltmek yeterlidir).
- İyilik fonksiyonu birden fazla bileşenden oluşabilir.
  - Bileşenlerin aralıkları çok farklıysa (0-1000 ile 0-1 gibi) büyük olan baskın çıkar; birleştirirken ağırlıklandırmaya dikkat edilmelidir.
- Fonksiyon konveks ise lokal minimum aynı zamanda global minimumdur ve başlangıç noktası önemsizdir.

## Kısa Tekrar Notları

- Lokal arama: yol değil durum aranır, yalnız mevcut durum tutulur, az hafıza.
- Tepe tırmanma: en iyi komşuya geç; hiçbir komşu daha iyi değilse dur.
- Problemler: ilk duruma bağlılık, lokal maksimum, plato, sırt; optimal değil.
- 8-vezir: her sütunda bir vezir, operatör = bir veziri kendi sütununda taşı, 56 ardıl, $h$ = birbirini tehdit eden çift sayısı.
- 8-vezirde tepe tırmanma: %14 çözer, %86 takılır; $8^8 \approx 17$ milyon durum.
- Çareler: rastgele yeniden başlatma, benzetimli tavlama, paralel tepe tırmanma.
- Benzetimli tavlama: rastgele ardıl; iyiyse kabul, kötüyse $e^{\Delta E/T}$ olasılıkla kabul; $T = T_0 \cdot 0.95^t$.
- Local beam search: $K$ durum, tüm ardılları üret, en iyi $K$ tanesiyle devam et ($5 \times 56 = 280$).
- Sezgi yoksa (kasa) sezgisel/lokal arama kullanılamaz, kör arama kalır.
- Sürekli uzayda yön eğimden bulunur (gradient descent); konveks fonksiyonda lokal = global.
- İyilik fonksiyonu çok bileşenli olabilir (alan maksimum, dönüş açısı minimum).

## Detaylı Açıklamalar

- Lokal arama neden farklı bir problem türüdür?
  - Önceki derslerde problem; başlangıç durumu, hedef durumu ve geçiş operatörleriyle tanımlanıyor, istenen şey ikisini birleştiren operatör dizisiydi (su bidonları, çiftçi-kurt-keçi-kabak, labirentte robot, navigasyon). Lokal aramada kullanıcı bir durumu yalnız özellikleriyle tarif eder ("hiçbir vezir birbirini tehdit etmesin"). Ne başlangıç ne hedef verilir. Rastgele bir durumla başlanır, operatörlerle yeni durumlara geçilir ve sonunda bulunan durum kullanıcıya sunulur. Ara adımlar saklanmadığı için hafıza çok az kullanılır.
- Tepe tırmanma sezgisi
  - Hoca algoritmayı sisli bir dağda elinde yalnız bir barometre (yükseklik ölçer) olan bir dağcıya benzetti. Hava açıkken en yüksek zirve uzaktan görülür ve oraya gidilir; yoğun siste ise yalnız etraftaki birkaç metre algılanabilir. Arama uzayında da çoğu zaman bütün uzayı algılamak fiziksel ya da hesaplama açısından mümkün değildir.
  - Tek boyutlu bir $f(x)$ üzerinde iki operatör vardır: belli bir adımla sola ya da sağa git. Her adımda iki komşunun $f$ değerine bakılır ve daha yüksek olana gidilir. Her iki komşu da mevcut noktadan kötüyse arama biter. Bu nokta lokal bir maksimumdur; uzayda çok daha yüksek bir tepe olabilir. Hangi tepeye varılacağını başlangıç noktası belirler.
  - Plato bölgesinde sağ ve sol aynı değeri verir. Algoritma yalnız mevcut durumu iyileştiren harekete izin verdiği için burada da durur.
- Tepe tırmanma algoritması (ekrandan, 00:25:00)

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

  - Ardıllar (successor), mevcut durumdan tek bir operatör uygulanarak gidilebilen durumlardır. Sayıları operatör tanımına bağlıdır; iki olmak zorunda değildir, yüksek boyutlu uzayda çok daha fazla olabilir.
- 8-vezir örneği (ekrandan, 00:40:00)
  - Bir adımda bir vezir kendi sütununda 7 farklı kareye gidebilir; 8 sütun olduğu için 56 ardıl vardır. Gösterilen tahtada birbirini tehdit eden vezir çifti sayısı 17'dir. Kareye yazılı her sayı, diğer vezirler yerinde dururken o sütunun veziri oraya taşınırsa oluşacak $h$ değeridir. En küçük değer 12'dir ve tahtada sekiz tane 12 vardır; bunlardan biri rastgele seçilir, vezir taşınır, sonra yeni tahtanın 56 ardılı yeniden hesaplanır.

```text
Satır 1: 18 12 14 13 13 12 14 14
Satır 2: 14 16 13 15 12 14 12 16
Satır 3: 14 12 18 13 15 12 14 14
Satır 4: 15 14 14  V 13 16 13 16
Satır 5:  V 14 17 15  V 14 16 16
Satır 6: 17  V 16 18 15  V 15  V
Satır 7: 18 14  V 15 15 14  V 16
Satır 8: 14 14 13 17 12 14 12 18
(V: vezir; başlangıçta h = 17)
```

  - Tablodaki bütün değerler ve $h = 17$ python ile yeniden hesaplanarak doğrulandı.
  - Aramanın $h = 1$'de durması (ekrandan, 01:05:00): 56 komşunun hiçbirinin $h$ değeri 1'den küçük değildir. 8-vezirin $h = 0$ çözümü vardır; bu yüzden takılınan yer lokal minimumdur. Sebep başlangıç noktasıdır; eşit değerli ardıllar arasındaki rastgele seçim de sonucu etkileyebilir.
- Neden saklayarak çözmeyelim?
  - Takılınan durumları bir yerde tutup oradan devam etmek (dinamik programlamaya benzer bir yapı) mümkündür, ama tepe tırmanmanın hafıza verimliliği kaybolur: saklanacak durum sayısı hızla büyür.
- Rastgele yeniden başlatma
  - En basit çözüm, tepe tırmanmayı farklı başlangıçlarla tekrarlamaktır. 8-vezirde 100 denemenin yaklaşık 86'sı takılır. Çözümün varlığı bilinmiyorsa milyon deneme bile "çözüm yok" dedirtmez, yalnız bu yöndeki inancı artırır.
- Benzetimli tavlama (ekrandan, 01:20:00)
  - Adını çelik üretimindeki tavlamadan alır: soğutma sürecine arada ısıtmalar eklenince malzemenin daha dayanıklı olduğu anlatılır. Algoritmada "soğuma" amaç fonksiyonunda istenen yöne gitmek, "ısıtma" ise kötüleşmeye izin vermektir.

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
    if dE > 0 then current <- next        (iyileşme varsa kesin kabul)
    else current <- next only with probability e^(dE/T)   (iyileşme yoksa belki)
Schedule: T = T0 * 0.95^t
```

  - $\Delta E$ ne kadar negatifse (ör. $-10$ ile $-0{,}001$ karşılaştırması) kabul olasılığı o kadar küçüktür. $t$ arttıkça $T$ sıfıra yaklaşır ve kötüleştiren hareketlerin kabul olasılığı azalır; olasılık sıfıra inince algoritma tepe tırmanmaya çok benzer davranır.
  - Hoca kötüleşmeyi kabul etmeyi "konfor alanını bozmaya" benzetti: kısa vadede kötü görünen bir adım uzun vadede daha iyi bir yere götürebilir, ama bunun garantisi yoktur.
- Paralel tepe tırmanma (ekrandan, 01:30:00)
  - Bir dağcı yerine aynı anda birçok dağcı gönderilir; birbirleriyle haberleşebilir ve birbirlerinin yerine "ışınlanabilirler". $K=5$, 8-vezir için $i$. nesildeki 5 tahtadan $5 \times 56 = 280$ tahta üretilir; 280'in içinden en iyi 5 tanesi $(i+1)$. nesil olur. Eski 5 durumu da adaylara katıp 285 içinden seçmek de mümkündür.
- Bozuk TV ve kasa (ekrandan, 01:35:00 - 01:45:00)
  - Dört düğme A=42, B=23, C=92, D=41 konumundadır, her biri 1-100 arası değer alır. Tüm kombinasyonları denemek $10^8$ deneme demektir. Önce A'yı ekrana bakarak optimize edip (ör. 51), sonra B, C, D'yi sırayla optimize etmek en fazla 400 deneme ister; bulunan (51, 65, 78, 92) büyük olasılıkla lokal bir çözümdür, çünkü uzayın yalnız 250 binde biri taranmıştır. Yine de maçı izlemeye yeter.
  - Aynı düğmeler şifreli bir kasada olsaydı ekran gibi bir geri bildirim olmazdı; sezgi olmadığı için yalnız kör arama kalırdı. Kasa hırsızlarının stetoskopla dinlediği kilit sesi ise bir sezgidir: hedefe yaklaşılıp uzaklaşıldığını gösterir.
- Ayrık ve sürekli uzaylar (ekrandan, 01:50:00)
  - Sürekli uzayda bir noktadan sonsuz noktaya gidilebilir, hepsi denenemez; hangi yöne ne kadar gidileceğini eğim gösterir. Gradient descent en hızlı azalma yönünde ilerler. Slayttaki örnek $f(x_1,x_2) = x_1^2 + 2x_2^2$ fonksiyonudur; minimumu $(0,0)$'dadır. Konveks fonksiyonlarda nereden başlanırsa başlansın aynı yere varılır. YSA ağırlıklarını farklı başlangıçlarla eğitmenin farklı sonuçlar vermesi bunun bir lokal arama süreci olduğunu gösterir.
- Robotla alan tarama (ekrandan, 01:55:00 - 02:00:00)
  - Durum, $N^2 - 1$ uzunluğunda bir rakam dizisidir ($N = 8$ için 63); her rakam 0-8 arası bir yönü gösterir (0 yerinde kal, 1 yukarı, 2 sol üst, 3 sol, 4 sol alt, 5 aşağı, 6 sağ alt, 7 sağ, 8 sağ üst).
  - Algoritma (`tepe_tirmanma_tarama_1robot.m`): rastgele bir çözümle başla; G kez: çözümden (%mu kadar) rastgele değişikliklerle P adet yeni çözüm üret, iyiliklerini hesapla (dönüş açılarını topla, gidilen farklı nokta sayısını topla), en iyisi mevcuttan iyiyse çözüme ata ve mu oranını azalt, kötüyse mu oranını artır; tk_max kez daha iyisi üretilmezse çözümü rastgele başlat.
  - Parametreler: P=200, mu=0.01, mu_dec=0.99, mu_inc=1.01, tk_max=50, G=3000. Bulunan çözüm alanın çoğunu kaplar ama mükemmel değildir; bazı yerlere gidilmemiş, bazı yerlerden birden fazla geçilmiştir. Tüm durumları denemek $8^{63}$ civarı durum demektir; bu yüzden sezgisel bilgi ve lokal arama şarttır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
