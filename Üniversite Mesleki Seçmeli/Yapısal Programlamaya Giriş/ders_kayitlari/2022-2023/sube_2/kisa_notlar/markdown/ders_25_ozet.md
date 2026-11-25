# Ders 25 Çalışma Özeti

## Genel Konular

- Lab sorusunun çözümü: robotun matristeki yollarını özyinelemeyle sayma
  - $n \times n$ bir matris verilir. Robot $(0,0)$ hücresinden başlar, $(n-1,n-1)$ hücresine ulaşınca durur. Değeri 1 olan hücrelere girebilir, 0 olan hücrelere giremez. 1 olan bütün hücrelerden geçmesi gerekmez; istenen, başlangıçtan bitişe giden bütün rotaları yazdırmak ve rota sayısını bulmaktır.
  - Çözümdeki `countPaths(i, j, n, matrix, path, pathLength)` fonksiyonu (ekrandan, 00:15:00):
    - Durma koşulu: `i == n-1 && j == n-1` ise hücre `path` dizisine eklenir, yol yazdırılır ve 1 döndürülür (bir yol bulundu).
    - Geçersizlik koşulu: `i >= n || j >= n || matrix[i][j] == 0` ise 0 döndürülür (bu yönde geçerli yol yok).
    - Diğer durumda hücre `path` dizisine eklenir, fonksiyon bir satır aşağı (`i+1, j`) ve bir sütun sağa (`i, j+1`) için kendini çağırır; iki çağrının sonuçlarının toplamı döndürülür.
  - `path` dizisinde çift indisler satır, tek indisler sütun numarasını tutar. Bu yüzden `printPath` döngüsü `i += 2` ile ilerler.
  - Dizi parametre olarak gönderildiğinde kopyalanmaz, adresi gider. `pathLength` ise değer olarak kopyalanır. Bu yüzden her yeni rota, ayrıldığı noktadan sonrasını aynı dizinin üzerine yazar; yol, hedefe varılınca hemen yazdırıldığı için bilgi kaybolmaz.
- Değişken kapsamı (scope)
  - Fonksiyon parametresinin adı, `main` içindeki değişkenin adıyla aynı olabilir; fonksiyon içinde erişilen, çağrıda gönderilen değişkendir. Bir değişkenin kapsamı tanımlandığı blokla sınırlıdır.
  - `for` gövdesinde tanımlanan bir değişken her turda yeniden oluşur ve blok dışında tanınmaz.
  - Global değişkenin kapsamı bütün programdır; başka bir C dosyasından `extern` ile erişilebilir. Çok iş parçacıklı (multi-thread) programlarda kontrolsüz global değişken yarış durumuna yol açar.
- Ağaç veri yapısı ve terimleri (ekrandan, 00:30:00)
  - Kök (root), kenar (edge), anahtar (key), ebeveyn (parent), çocuk (children), kardeş (siblings), yaprak (leaf node), alt ağaç (subtree), ağacın yüksekliği (height of the tree).
  - Yükseklik, kökten en uzak yaprağa giden yoldaki adım (kenar) sayısıdır, düğüm sayısı değildir. Slayttaki ağaçta P'den I'ya 4 adım vardır, yükseklik 4'tür (ekrandan, 00:35:00).
  - Bir düğümün alt ağacı, o düğümü ve onun bütün torunlarını kapsar.
- İkili arama ağacı (Binary Search Tree, BST)
  - Her düğümün en çok iki çocuğu vardır. Sol taraftakiler kökten küçük, sağ taraftakiler kökten büyüktür; kural her düğüm için geçerlidir.
  - En küçük değer en soldaki, en büyük değer en sağdaki düğümdür.
  - Arama, ikili aramadaki gibi her adımda kalan elemanların yarısını eler; ama ağacı kurmak için diziyi önceden sıralamak gerekmez.
  - Dezavantaj: ağaç dengesiz (unbalanced) olabilir. 40, 30, 20, 10 sırasıyla eklenen değerler tek kollu bir zincir oluşturur; arama sıralı dizide doğrusal aramadan farksız olur (ekrandan, 00:40:00).
- Min-heap ve BST farkı
  - Min-heap'te kök en küçük elemandır ve çocuklar ebeveynden büyük ya da eşittir; ama sağ ve sol çocuk arasında sıra şartı yoktur. Bu yüzden heap'te arama yaparken bir tarafı eleyemezsiniz; BST'de eleyebilirsiniz.
  - Heap'e ekleme ağacın sonuna yapılır, gerekirse eleman yukarı taşınır; sıralı dizideki kaydırma gerekmez. En öncelikli eleman her zaman köktedir.
  - Kullanım örnekleri: bankada öncelikli müşteriyi sıraya alma, işletim sisteminde işlemciye geçecek prosesi seçme.
- BST'yi dizide tutma
  - Kök 0. indistedir. $i$ indisli düğümün sol çocuğu $2i+1$, sağ çocuğu $2i+2$ indisindedir (ekrandan, 01:00:00).
  - Her katmanda eleman sayısı ikiye katlanır (1, 2, 4, 8, ...). Kök 1'den numaralansa sol çocuk $2i$, sağ çocuk $2i+1$ olurdu; dizi 0'dan başladığı için formül bir kayar.
  - Boş hücreler -1 ile işaretlenir (yalnız pozitif değer girileceği varsayımıyla). `int BST[1024] = {-1};` yalnız ilk elemanı -1 yapar, gerisi 0 olur; bu yüzden diziyi döngüyle doldurmak gerekir.
- BST işlemleri (C kodu, ekrandan, 01:10:00 - 01:50:00)
  - `Move_Left(i)` $= 2i+1$, `Move_Right(i)` $= 2i+2$.
  - `Find_Index_Ite` / `Find_Index_Rec`: ekleme ve arama aynı fonksiyonla yapılır. `mode == 0` eklemedir ve ilk boş (-1) hücreye kadar ilerler; `mode == 1` aramadır ve değer bulununca durur. Sayı düğümden büyükse sağa, değilse (eşitse de) sola gidilir.
  - `Create_BST`: değerler sırayla bulunan boş indise yazılır.
  - `Print_BST`: pre-order yazdırma (önce düğüm, sonra sol, sonra sağ alt ağaç). Yazdırma satırının yeri değişince in-order (sol, düğüm, sağ) ve post-order (sol, sağ, düğüm) elde edilir.
  - `Create_Balanced_BST`: sıralı dizinin orta elemanı eklenir, sonra sol yarı (`Start`, `mid-1`) ve sağ yarı (`mid+1`, `End`) için özyineleme yapılır.
- Örnek problem: alt ağaç ortalaması
  - Her düğüm için, alt ağacındaki bütün torunların (kendisi hariç) ortalamasının düğümün değerine eşit olup olmadığı kontrol edilir. Toplam ve eleman sayısı alttan yukarı özyinelemeyle taşınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dizi başlatma tuzağı
  - `int a[N] = {-1};` bütün elemanları -1 yapmaz; yalnız ilk eleman -1, gerisi 0 olur. Bu tür ayrıntıların sınavlarda sık sorulduğu söylendi.
- Derleyici farkları
  - Bazı derleyiciler kurallara gevşek uyar. Örneğin `for (int i = 0; ...)` biçimi derste kullanılan derleyici ayarında kabul edilmiyor, modern derleyicilerde kabul ediliyor. Kod, teslimden önce derste verilen derleyici sürümünde de denenmeli.
  - Fonksiyon prototipini parametresiz (`void f();`) yazmak bazı derleyicilerde hata vermese de doğru alışkanlık değildir.
- Global değişken kullanmayın
  - Kapsamı bütün program olduğu için çok iş parçacıklı programlarda bir iş parçacığının yaptığı değişiklik diğerini bozar (banka hesabı örneği).
- Dengesiz BST tehlikesi
  - Sıralı ya da neredeyse sıralı veri eklenince ağaç tek kollu olur, indisler üstel büyür ve 1024'lük dizi taşar. Çözüm: diziyi sıralayıp orta elemandan başlayarak eklemek.
- Ağaçlar genelde özyinelemeyle gezilir
  - `while(1)` ile yazılan iteratif arama çalışır, ama ağaç işlemlerinde özyinelemeli yazım daha doğaldır.

## Kısa Tekrar Notları

- Yol sayma özyinelemesi: hedefte 1, geçersiz hücrede 0, diğer durumda (aşağı + sağ) sonuçlarının toplamı.
- Dizi parametresi adresle gider (kopyalanmaz), `int` parametresi kopyalanır.
- Yükseklik = kökten en uzak yaprağa kenar sayısı.
- BST: sol < kök < sağ; en küçük en solda, en büyük en sağda.
- Dizide ağaç: kök 0, sol $2i+1$, sağ $2i+2$.
- `int a[N] = {-1};` yalnız ilk elemanı -1 yapar.
- Pre-order: düğüm-sol-sağ; in-order: sol-düğüm-sağ; post-order: sol-sağ-düğüm.
- Dengeli BST kurmak için: sırala, ortayı ekle, iki yarıya özyinele.
- Min-heap: kök en küçük; arama için eleme yapılamaz, ekleme/çıkarma kolaydır.
- Alt ağaç ortalaması için toplam ve eleman sayısı birlikte taşınmalı; 2'ye bölmek yalnız tek katmanda doğrudur.

## Detaylı Açıklamalar

- **Lab sorusundaki özyineleme nasıl tüm rotaları bulur?** Fonksiyon her hücrede iki çağrı yapar: biri bir satır aşağı, biri bir sütun sağa. Matrisin dışına çıkılırsa ya da 0 olan hücreye gelinirse o dal 0 döndürür. Hedef hücreye ulaşan her dal 1 döndürür ve o ana kadarki yolu yazdırır. Üst düzeydeki çağrı iki dalın toplamını aldığı için en üstteki çağrının sonucu toplam rota sayısıdır. `path` dizisinin adresi paylaşıldığı, `pathLength` ise her çağrıda kopyalandığı için bir dal geri döndüğünde diğer dal aynı uzunluktan başlayıp dizinin sonunu üzerine yazar.
- **Ders sonrası not (lab kodu):** Ekrandaki kodda `countPaths(i + 1, j, ...)` satırının yorumu "sağa gitme", `countPaths(i, j + 1, ...)` satırınınki "aşağıya gitme" diyor; `i` satır indisi olduğu için ilki aslında aşağı, ikincisi sağa gider. Toplam etkilenmez. Ayrıca `path` dizisi `2*MAX = 20` elemanlıdır; $(0,0)$'dan $(n-1,n-1)$'e giden yol $2n-1$ hücre, yani $2(2n-1)$ tamsayı tutar. Bu, $n \ge 6$ için 20'yi aşar ve dizinin dışına yazılır (tanımsız davranış); büyük olasılıkla dizi `2*(2*MAX-1)` boyutunda olmalıydı. Kod ajan tarafından `gcc -Wall` ile derlendi ve 3x3'lük bir matriste denendi (`main` kareden tam okunamadığı için deneme `main`'i ajanın yazdığıdır): `{{1,1,0},{1,1,1},{0,1,1}}` için 4 rota bulundu.
- **Her rotayı ayrı saklamak istenirse:** Bir öğrencinin sorusu üzerine, her satırı bir rota olan iki boyutlu bir dizi kullanılabileceği, yol bir noktada ayrıldığında o ana kadarki adımların yeni satıra kopyalanıp devam edileceği söylendi. Anlatan bunun iyi bir çözüm olmadığını, aklına gelen bir fikir olduğunu belirtti.
- **Ağaç neden kullanılır?** Ağaçlar özel saklama ve arama yöntemleri kurmayı sağlar. BST'de 35 aranırken 40'a gelinir; 35 < 40 olduğu için sola, 30'a gelinir; 35 > 30 olduğu için sağa gidilir ve 35 bulunur. Her adımda kalan ağacın bir yarısı elenir (ekrandan, 00:40:00). Ağaç dengeli kurulursa bu ikili aramanın verimini sıralama yapmadan sağlar.
- **Ders sonrası not (BST tanımı):** Derste kural "kök, sol çocuktan büyük, sağ çocuktan küçük" diye anlatıldı ve "bütün düğümler için geçerli" denildi. Kesin tanım daha güçlüdür: bir düğümün sol alt ağacındaki bütün değerler ondan küçük (derste yazılan kodda küçük ya da eşit), sağ alt ağacındaki bütün değerler ondan büyüktür. Yalnız doğrudan çocuklara bakmak yetmez.
- **Dizi gösterimi:** Slaytta düğümler katman katman numaralanınca (kök 1) sol çocuk $2i$, sağ çocuk $2i+1$ çıkar. C dizileri 0'dan başladığı için kök 0 alınır; o zaman sol çocuk $2i+1$, sağ çocuk $2i+2$ olur (ekrandan, 01:00:00). Örneğin 40 (0) → 30 (1), 50 (2); 30 (1) → 25 (3), 35 (4); 50 (2) → 45 (5), 60 (6).
- **Ekleme ve arama aynı yürüyüştür.** Eklenecek değer köke göre büyükse sağa, değilse sola gidilir; ilk -1 hücreye yazılır. Aramada da aynı yol izlenir; tek fark, aranan değer görülünce durmaktır. Eklemede aynı değer görülünce durulmamalı, -1 bulunana kadar devam edilmelidir; `mode` parametresi bu yüzden vardır. Ekleme ile aramanın aynı fonksiyonda yazılması bu sebeple mümkündür.
- **Ders sonrası not (arama sonucu):** `mode == 1` ile aranan değer ağaçta yoksa fonksiyon -1 döndürmez, değerin ekleneceği boş hücrenin indisini döndürür (ajanın denemesinde 7 düğümlü ağaçta 11 arandığında 12 döndü). Çağıran kod `BST[indis] == -1` ise "bulunamadı" demelidir.
- **Özyinelemeli arama ve bellek:** Özyinelemeli sürümde her çağrıda `i`, `number`, `mode` kopyalanır; dizi kopyalanmaz, yalnız adresi gider. Bu yüzden bellek farkı küçüktür, ama özyineleme biraz daha fazla yığın belleği kullanır.
- **Dengesizlik ve taşma:** Bütün değerler kökten küçük gelirse indisler 0, 1, 3, 7, 15, 31, ... diye üstel büyür ($2^d - 1$). 1024 elemanlı dizide bu zincir en çok 11 düğüm taşır. 100 sıralı eleman eklenmek istenince program çöktü. Dizi dışındaki hücreyi okumak C'de tanımsız davranıştır; programın çökmesi bunun sonucudur.
- **Dengeli BST:** `Create_Balanced_BST(BST, Values, Start, End)` sıralı dizinin `mid = (Start+End)/2` elemanını ekler, sonra `[Start, mid-1]` ve `[mid+1, End]` aralıklarına iner; `Start > End` olunca durur. Derste ilk çağrı `End = n` ile yapıldı; doğrusu `n-1`'dir (anlatan da sonra bunu düzeltti). `End = n` ile `Values[n]` dizinin dışından okunabilir (tanımsız davranış). Ağacı kurduktan sonra dengesizlik oluşunca ağacı yeniden düzenleyen yöntemlerin de olduğu, ama daha karmaşık oldukları söylendi.
- **Alt ağaç ortalaması:** Örnek ağaç (ekrandan, 01:45:00): kök 9; sol çocuk 6 (çocukları 4, 8); sağ çocuk 12 (çocukları 10, 14). 6 için $(4+8)/2 = 6$, 12 için $(10+14)/2 = 12$ sağlanır. 9 için yalnız iki çocuğa bakmak yanlıştır; bütün alt ağaç alınmalıdır: sol alt ağaç toplamı $4+6+8 = 18$, sağ alt ağaç toplamı $10+12+14 = 36$, toplam 54, eleman sayısı 6, ortalama 9. İlk yazılan kod toplamı 2'ye böldüğü için yalnız 6 ve 12'yi (indis 1 ve 2) buldu. Eleman sayısını döndüren `Return_count` fonksiyonu eklenip toplam bu sayıya bölününce çıktı 1, 2, 0 indisleri oldu. Kod ajan tarafından kareden yeniden kuruldu, `gcc -Wall` ile derlendi ve aynı ağaçta aynı çıktıyı verdi.
  <!-- BELİRSİZ: 01:50:29 - 01:52:40 arasında "yalnız bir indise bakmak" ve "eksi bir yapacağız, kendini saymasın" diye yapılan son değişikliğin hangi satıra yapıldığı altyazıdan ve karelerden çıkarılamadı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
