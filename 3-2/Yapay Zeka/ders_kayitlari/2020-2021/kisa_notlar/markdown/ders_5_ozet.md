# Ders 5 Çalışma Özeti

## Genel Konular

- Kör, sezgisel ve lokal arama algoritmalarının girdileri ve çıktıları
  - Kör arama için gerekenler: başlangıç durumu, bitiş durumu, durumlar arası geçişler ve geçişlerin maliyetleri. Durumların nasıl temsil edileceği her yöntemde ortak bir ön koşuldur (ekrandan, 00:15:00).
  - Sezgisel arama bunlara ek olarak durumların hedefe olan uzaklıklarını **tahmin eden** bir fonksiyon ister. Uzaklığın kendisi bilinemez, ancak tahmin edilebilir; bilinseydi problem zaten çözülmüş olurdu.
  - Kör ve sezgisel aramanın çıkışı: başlangıç ile bitiş arasındaki yol ve bu yolun maliyeti.
  - Lokal arama için gerekenler: başlangıç durumu, durumlar arası geçişler, geçişlerin maliyetleri ve hedefe uzaklığı tahmin eden fonksiyon. **Bitiş durumu verilmez.** Çıkış yalnızca bitiş durumudur (ekrandan, 00:15:00).
- Lokal (yerel) arama algoritmaları
  - Birçok optimizasyon probleminde hedefe giden yol önemsizdir; istenen çözüm hedef durumun kendisidir. Amaç, istenen kısıtlara/özelliklere sahip ya da fayda fonksiyonunu en büyük yapan durumu bulmaktır.
  - Kullanıcı hedefi kendisi de bilmez; yalnız hedefin özelliklerini söyler.
  - Hafızada yalnız mevcut durum tutulur ve adım adım iyileştirilir; bu yüzden hafıza gereksinimi çok azdır.
- n-vezir problemi
  - N veziri $n \times n$ satranç tahtasına hiçbiri diğerini tehdit etmeyecek şekilde yerleştirmek; hiçbir satır, sütun ve diyagonalde birden fazla vezir olmamalı (ekrandan, 00:20:00).
  - Başlangıç: her sütuna rastgele bir vezir. Geçiş: her adımda tek bir vezir kendi sütununda istediği yere gider.
  - 4-vezirde bir durumdan $4 \times 3 = 12$, 8-vezirde $8 \times 7 = 56$ yeni durum çıkar.
- Tepe tırmanma (hill climbing)
  - Mevcut durumun bütün komşuları üretilir, $h$ değeri (hedefe tahmini yakınlık) en iyi olan komşu seçilir. Bu komşu mevcut durumdan iyi değilse algoritma durur ve mevcut durumu döner.
  - Yoğun siste Everest'e tırmanmaya benzer: yalnız etrafınızı ölçebilirsiniz, her zaman en çok yükselten yöne adım atarsınız. Best-first search'e benzer.
  - Maksimizasyon tepe tırmanma, minimizasyon yokuş inme olarak düşünülür; biri diğerine kolayca dönüştürülür.
  - Problemleri: sonuç başlangıç noktasına bağlıdır; lokal maksimumlarda, platolarda (yayla) ve sırtlarda takılabilir.
- 8-vezirde tepe tırmanma
  - Durum, her sütundaki vezirin aşağıdan kaçıncı satırda olduğunu gösteren 8 elemanlı bir diziyle temsil edilir (matristen daha ucuz).
  - $h$ = birbirini tehdit eden vezir çifti sayısı; amaç $h$'yi sıfıra indirmektir.
  - Rastgele başlangıçla denemelerin %14'ünde çözer, %86'sında lokal bir noktaya takılır. Toplam durum sayısı $8^8 = 2^{24} \approx 17$ milyon (ekrandan, 01:20:00).
- Çözüm alternatifleri (ekrandan, 01:25:00)
  - Rastgele yeniden başlatmalı tepe tırmanma (random-restart hill climbing): tepe tırmanmayı farklı başlangıçlarla tekrarlamak.
  - Benzetimli tavlama (simulated annealing): lokal maksimumdan kaçmak için zaman zaman kötüleşmeye izin vermek.
  - Paralel tepe tırmanma (local beam search): tek durum yerine $k$ durumu birlikte izlemek.
- Bozuk TV ve kasa örneği
  - Sezgi (iyileşme ölçüsü) varsa lokal arama küçük bir denemeyle iyi bir sonuca götürür; sezgi yoksa yapılacak pek bir şey yoktur.
- Ayrık ve sürekli uzaylar
  - Ayrık uzayda bir noktadan sınırlı sayıda noktaya gidilir; sürekli uzayda sonsuz sayıda yön vardır.
  - Sürekli uzayda fonksiyon biliniyorsa türev yol gösterir; türevin tersi yönünde ilerlemek eğim düşme (gradient descent) algoritmasıdır.
- Uygulama: robot süpürgeyle alan tarama
  - 8 yönde hareket edebilen bir robotun $n \times n$ alanı minimum dönüş açısıyla ve maksimum alanı gezerek taraması tepe tırmanmayla optimize edilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Lokal arama ile kör/sezgisel arama arasındaki temel fark
  - Lokal aramada bitiş durumu bilinmez ve çıkış yol değil, durumun kendisidir. Kullanıcı yolla ilgilenmez.
- $h$ bir tahmindir
  - Hoca $h$'nin "hedefe olan uzaklık" değil, "hedefe olan uzaklığın tahmini" olduğunu birkaç kez sordu ve vurguladı. Tepe tırmanma çiziminde y eksenini "hedefe olan tahmini yakınlık" diye düzeltti (ekrandan, 00:30:00).
- Tepe tırmanma her zaman bir lokal maksimum döner, ama global olup olmadığını bilemez
  - Global maksimum aynı zamanda bir lokal maksimumdur. Ulaşılabilecek en iyi değer biliniyorsa (8-vezirde $h=0$ ya da tehdit etmeyen 28 çift) takıldığımızı anlayabiliriz; bilinmiyorsa emin olamayız.
- Sonucu belirleyen iki etken
  - Başlangıç noktası ve eşit değerli komşular arasından yapılan rastgele seçim. Bu yüzden algoritmayı farklı başlangıçlarla tekrar çalıştırmak ilk çözüm alternatifidir.
- Benzetimli tavlamada kötü hamle kabul olasılığı
  - Kötüleşme miktarı büyüdükçe ve zaman geçtikçe azalır. $T$ çok küçülünce olasılık sıfıra yaklaşır ve algoritma tepe tırmanmaya dönüşür.
- Paralel tepe tırmanmada çeşitlilik (diversity)
  - Bütün dağcıları en iyi $k$ noktaya ışınlamak hepsini aynı tepeye toplar; o zaman birden fazla dağcının bir faydası kalmaz. Bir kısmını daha kötü yerlerde bırakmak daha mantıklı olabilir. Aynı sorun genetik algoritmada da vardır.
- Sezginin etkisi
  - Bozuk TV ile kasa arasındaki tek fark sezginin varlığıdır. Sezgi problemi daha iyi değil, çok daha hızlı çözmeyi sağlar.
- Çok bileşenli iyilik fonksiyonu
  - Bileşenlerin aralıkları (range) eşitlenmeli; aksi halde büyük olan küçüğü ezer. Biri minimize, biri maksimize edilecekse ikisi de aynı yöne çevrilmeli.
- Derin öğrenmenin temelinde de tepe tırmanma / yokuş inme vardır
  - Sinir ağlarının eğitimi rastgele ağırlıklardan başlayıp gradyana göre iyileştirmedir. Aynı algoritma 2 boyutta da, milyonlarca parametreli uzayda da çalışır.

## Kısa Tekrar Notları

- Kör arama: başlangıç + bitiş + geçişler + maliyetler → yol ve maliyet.
- Sezgisel arama: kör aramanınkiler + hedefe uzaklık tahmini → yol ve maliyet.
- Lokal arama: başlangıç + geçişler + maliyetler + tahmin fonksiyonu, bitiş yok → yalnız bitiş durumu.
- Tepe tırmanma: en iyi komşu mevcuttan iyi değilse dur. Hafızası çok azdır, global maksimumu garanti etmez.
- Takıldığı yerler: lokal maksimum, plato (yayla), sırt.
- 8-vezir: dizi temsili, $h$ = tehdit eden çift sayısı, komşu sayısı 56, başarı %14, durum sayısı $8^8 \approx 17$ milyon.
- Random-restart: farklı başlangıçlarla tekrarla.
- Simulated annealing: rastgele komşu; $\Delta E > 0$ ise kesin kabul, değilse $e^{\Delta E / T}$ olasılıkla kabul; $T = T_0 \cdot 0{,}95^t$.
- Local beam search: $k$ durum birlikte; en iyi $k$'yı seç; çeşitliliği koru.
- Bozuk TV: $100^4 = 10^8$ durum; düğme düğme iyileştirmeyle en fazla 400 deneme, sonuç büyük olasılıkla lokal.
- Sürekli uzay: türevin tersi yönünde ilerle (gradient descent); tepede/dipte türev sıfırdır.
- Robot: çözüm $n^2-1$ hareketten oluşan, elemanları 0-8 olan dizi; iyilik = dönüş açısı + gezilen farklı nokta sayısı.

## Detaylı Açıklamalar

- **Girdi/çıktı karşılaştırması.** Ders, önceki iki arama ailesinin neye ihtiyaç duyduğunu ve ne ürettiğini yeniden kurarak başladı. Kör aramada başlangıç ve bitiş durumu, durumlar arası geçişler ve geçişlerin maliyetleri gerekir. Sezgisel arama bunlara durumların hedefe uzaklığını tahmin eden bir fonksiyon ekler. İkisi de başlangıçtan bitişe giden yolu ve maliyetini döner. Lokal aramada ise bitiş durumu yoktur: bize hedefin özellikleri (ya da bir durumun hedefe yakınlığını ölçen fonksiyon) verilir ve bu özellikleri en iyi sağlayan durumu bulmamız istenir. Çıkış yalnız bu durumdur (ekrandan, 00:15:00).

- **n-vezir örneği.** 8 veziri 8×8 tahtaya hiçbiri diğerini tehdit etmeyecek şekilde yerleştirme probleminde başlangıç da hedef de verilmez; hedefin kendisi istenir. Başlangıç kuralı olarak her sütuna rastgele bir vezir konur. Geçiş kuralı: her adımda yalnız bir vezir kendi sütununda istediği hücreye gider. 4-vezirde her vezirin 3 alternatif yeri olduğundan bir durumdan 12 yeni durum çıkar. Bu 12 durumun iyiliği ölçülür, en iyisi seçilir ve iyileşme kalmayana kadar devam edilir.

- **Tepe tırmanma sezgisi.** Hoca x ekseni "durum", y ekseni "$h$" olan tek tepeli bir eğri çizdi (ekrandan, 00:25:00). Her durumdan sağa ya da sola gidilebilir; daha yüksek olan seçilir. Tepeye gelince iki yön de iyileştirmediği için algoritma durur. Öğrencilerden gelen düzeltmeyle y ekseni "hedefe olan tahmini yakınlık" olarak yazıldı; uzaklık kullanılırsa problem yokuş inmeye dönüşür (ekrandan, 00:30:00). Sisli bir dağda yalnız yükseklik ölçen bir cihazla zirveye çıkmaya çalışan dağcı benzetmesi verildi: her yöne birer adım atılıp ölçülür, en yüksek ölçüm bulunduğumuz yerden yüksekse oraya gidilir, değilse durulur.

- **Lokal maksimum, plato, sırt.** Birden çok tepeli bir eğride (ekrandan, 00:35:00, 00:40:00) hangi tepeye varılacağı başlangıç bölgesine bağlıdır. Algoritma vardığı tepenin global mi lokal mi olduğunu bilemez. 8-vezirde tehdit etmeyen çift sayısı en fazla $\binom{8}{2} = 28$'dir; 26'da takılırsanız ve 28'in mümkün olduğunu biliyorsanız lokal bir maksimumda olduğunuzu anlarsınız. Platoda (yaylada) komşular mevcut durumla eşit değerli olduğu için algoritma durur; düz bölgenin ötesinde daha iyi bir yer olup olmadığını göremez.

- **Algoritma** (ekrandan, 00:45:00):

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

  Kuyruk, yığın gibi bir yapı yoktur; bütün komşular üretilir, en iyisi alınır.

- **8-vezirde tepe tırmanma.** Tahta, her sütundaki vezirin aşağıdan sayılan satır numarasıyla temsil edilir. Derste kullanılan tahta `4 3 2 5 4 3 2 3` dizisidir ve $h = 17$'dir (ekrandan, 01:05:00). İlk vezir için üretilen 7 komşu ve $h$ değerleri (ekrandan, 01:10:00): `1 3 2 5 4 3 2 3` $h=14$, `2 3 2 5 4 3 2 3` $h=18$, `3 3 2 5 4 3 2 3` $h=17$, `5 3 2 5 4 3 2 3` $h=15$, `6 3 2 5 4 3 2 3` $h=14$, `7 3 2 5 4 3 2 3` $h=14$, `8 3 2 5 4 3 2 3` $h=18$. Diğer sütunlar için de 7'şer komşu vardır; toplam 56 komşu. Tahtadaki her hücrede, yalnız o sütunun veziri oraya taşınırsa oluşacak $h$ yazılıdır. En küçük değer 12'dir ve 8 komşuda görülür; bunlardan biri rastgele seçilir (python ile doğrulandı). Hocanın gösterdiği örnekte süreç $h=1$ olan bir duruma varıyor ve 56 komşunun hiçbiri 1'den küçük olmadığı için duruyor; bu bir lokal minimumdur. Bir tahtanın döndürülmüş halleri de aynı $h$'ye sahiptir.

- **Performans.** Rastgele başlangıçla denemelerin %14'ü çözülür, %86'sı lokal bir noktada takılır. Bütün durumları gezmek $8^8 = 2^{24} \approx 17$ milyon durum demektir (ekrandan, 01:20:00).

- **Random-restart hill climbing.** Sonucu başlangıç noktası ve eşit değerli komşular arasındaki rastgele seçim belirler. Çözüm bulunmadıkça algoritma farklı başlangıçlarla tekrar çalıştırılır.

- **Benzetimli tavlama.** Çeliğe su verme benzetmesi: sıcaklık sürekli düşürülmek yerine zaman zaman yeniden ısıtılarak düşürülünce daha kaliteli malzeme elde edilir. Algoritmada rastgele bir komşu üretilir; iyileşme varsa kesin kabul edilir, yoksa zamanla ve kötüleşme miktarıyla azalan bir olasılıkla kabul edilir (ekrandan, 01:30:00). Algoritma (ekrandan, 01:35:00):

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
      if dE > 0 then current <- next          (iyileşme varsa kesin kabul)
      else current <- next only with probability e^(dE/T)   (iyileşme yoksa belki)
  ```

  Slayttaki çizelge $T = T_0 \cdot 0{,}95^t$'dir; zaman ilerledikçe $T$ azalır. $\Delta E$ negatif ve mutlak değeri büyükse $e^{\Delta E/T}$ küçüktür; $T$ küçüldükçe de küçülür. $T$ sıfıra yaklaşınca kötü hamleler neredeyse hiç kabul edilmez ve algoritma tepe tırmanmaya dönüşür. Başta $h$ büyük salınımlar yaparken sona doğru salınımlar küçülür. Kötüleşmeye izin vermek daha iyi bir tepeye ulaşmayı garanti etmez, yalnız bir ihtimal sağlar.

- **Paralel tepe tırmanma (local beam search).** $k$ rastgele durumla başlanır; her iterasyonda bu durumlardan gidilebilecek tüm durumlar üretilir; biri hedefse durulur, değilse en iyi $k$ tanesi yeni mevcut durumlar olur. Birbirleriyle haberleşen dağcılar gibi düşünülür. Derste üç dağcıyla çizilen örnekte 3 mevcut + 6 yeni = 9 durumun en iyi üçü aynı tepede çıktı; dağcıların hepsi aynı tepeye ışınlandı. Çözümlerin farklı yerlerde kalması (diversity) sağlanmazsa paralelliğin anlamı kalmaz.

- **Bozuk TV ve kasa.** Dört düğmesi olan, her düğmesinin 100 pozisyonu bulunan bir televizyonda $100^4 = 10^8$ olası ayar vardır; hepsini denemek imkânsızdır (ekrandan, 02:00:00). Düğmeleri sırayla, iyileşme bitene kadar çevirmek en fazla $4 \times 100 = 400$ deneme gerektirir; bu lokal bir aramadır ve sonuç büyük olasılıkla lokal bir optimumdur. Aynı yapıdaki bir kasa şifresinde ise yaklaşıp yaklaşmadığınızı gösteren bir sezgi yoktur; geriye yalnız kör arama kalır ve bu da $10^8$ olasılıkta uygulanabilir değildir (ekrandan, 02:05:00). Kasaya steteskop dayamak, kilitten gelen seslerle sezgi edinmeye çalışmaktır. Bir parolayı kırarken önce kişinin önemli tarihleri, adları gibi olası kalıpları denemek de sezgi kazanma çabasıdır.

- **Ayrık/sürekli uzaylar.** Şimdiye kadarki bütün uzaylar ayrıktı: dallanma faktörü $b$ sonluydu. Sürekli uzayda bir noktadan sonsuz noktaya gidilebilir. Derste $f(x_1, x_2) = x_1^2 + x_2^2$ fonksiyonunun eş yükselti eğrileri (izohips benzeri) gösterildi; aynı eğri üzerindeki noktaların $f$ değeri aynıdır (ekrandan, 02:10:00). Fonksiyon biliniyorsa türev yön gösterir; türevin tersi yönünde adım atılır ve tepeye/dibe gelindiğinde türev sıfır olur. Bu eğim düşme (gradient descent) algoritmasıdır. Adam, RMSProp, Adagrad gibi derin öğrenme eğitim algoritmaları bu temele dayanır; 2 boyutta çalışan algoritma milyonlarca boyutta da çalışır.
  - **Ders sonrası not:** Hoca bu fonksiyonu "yukarıya doğru yükselen bir dağ" ve "maksimum aranıyor" diye anlattı, ama $x_1^2 + x_2^2$ merkezde (0, 0) **minimum** değerini alır ve dışa doğru büyür. Gradyanın tersi yönünde ilerlemek de minimuma götürür. Ekrandaki noktalar da (0, 0)'a yakınsıyor (ekrandan, 02:10:00).

- **Robot süpürge ile alan tarama.** 8 yönde hareket edebilen robot $n \times n$ alanda $n^2 - 1$ adım atar. Çözüm, elemanları 0 ile 8 arasında olan $n^2-1$ uzunlukta bir dizidir ($n = 8$ için 63 eleman); 0 olduğu yerde kalmaktır, 1 yukarı, 2 sol üst, 3 sol, 4 sol alt, 5 aşağı, 6 sağ alt, 7 sağ, 8 sağ üst yöndür (ekrandan, 02:25:00). İyilik fonksiyonunun iki bileşeni vardır: dönüş açılarının toplamı (minimum olmalı, çünkü dönmek robotu yavaşlatır) ve gidilen farklı nokta sayısı (maksimum olmalı). Hocanın MATLAB kodu (`tepe_tirmanma_tarama_1robot.m`) şu şekilde çalışır (ekrandan, 02:20:00): rastgele bir çözümle başla; G kez, çözümden %mu kadar rastgele değişiklikle P adet yeni çözüm üret; iyiliklerini hesapla; en iyisi mevcuttan iyiyse çözüme ata ve mu'yu azalt, kötüyse mu'yu artır; tk_max kez daha iyisi üretilmediyse rastgele yeniden başlat. Ekrandaki parametreler: P=200, mu_dec=0.99, mu_inc=1.01, tk_max=50, G=3000 <!-- BELİRSİZ: mu başlangıç değerinin ilk hanesi ekranda bir tutamaçla kapalı, ".01" okunuyor --> (ekrandan, 02:25:00). Sürecin grafiğinde (x ekseni iterasyon, y ekseni mevcut çözümün iyilik değeri, burada küçük daha iyi) değer düşer, düz kalır ve 50 adım iyileşme olmayınca yeniden başlatmayla yukarı sıçrar.
  - Bileşenleri toplarken aralıkları eşitlenmeli ve hepsi aynı yöne (hepsi min ya da hepsi max) çevrilmelidir. Yeni bileşen de eklenebilir: örneğin robotun başladığı yere dönmesi isteniyorsa son noktanın başlangıca uzaklığı üçüncü bileşen olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
