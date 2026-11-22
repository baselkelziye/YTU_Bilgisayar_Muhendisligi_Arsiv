# Ders 25 Çalışma Özeti

## Genel Konular

- RAM ve rastgele erişim (random access)
  - Bellek, her birinin bir adresi olan hücrelerden oluşur. Tahtadaki örnekte bir hücre 8 bitliktir ve içine 0 ile 255 arasında bir sayı yazılabilir (ekrandan, 00:10:00).
  - RAM (Random Access Memory), belleğin istenen herhangi bir adresine tek adımda erişilebilmesi demektir. Bugünkü bilgisayarların temelindeki von Neumann mimarisi bu belleği esas alır.
  - Karşıtı sıralı (sequential) erişimdir: n'inci adrese gitmek için baştan n adım ilerlemek gerekir. İlk bilgisayarlar ve Turing makineleri teyp (tape) üzerinde sıralı yapılarla çalışıyordu.
- Tekil değişkenlerin bellekte yerleşimi
  - Her değişken tipi bellekte belli bir büyüklük kaplar; `int` 32 bitlik alan kaplar. `int a;` tanımlanınca bu büyüklükte bir alan ayrılır ve orası yalnız o değişkene ait olur.
  - Bir değişkenin parçaları bellekte ardışık durur; parçalar dağınık olsaydı okunması ve değişkenin oluşturulması daha uzun sürerdi. Tahtada adresler 100, 108, 116, 124 diye ilerler (ekrandan, 00:15:00).
- Dizilerin bellekte yerleşimi ve adres hesabı
  - `int a[10]` için 40 baytlık ardışık bir alan ayrılır (ekrandan, 00:15:00).
  - C'de dizinin adı bir adrestir: dizinin başladığı adres.
  - `a[3]`'e erişmek için `a[0]`'ın adresine 3 tane `int` büyüklüğü eklenir: `adres(a[0]) + 3 * sizeof(int)` (ekrandan, 00:15:00). Bu hesap tek adımda yapılır.
  - Bu hesabın mümkün olması için dizinin bütün elemanları aynı türde, yani bellekte aynı büyüklükte olmalıdır.
- Struct ve struct dizileri
  - Struct, farklı türden değişkenlerin bir araya gelerek oluşturduğu veri yapısıdır. Tahtadaki örnek: TC kimlik no (`int`), ad (string), soyad (string), borç (`int`) (ekrandan, 00:20:00).
  - Struct dizisi kurulabilir; şartı, her struct'ın bileşenlerinin büyüklüklerinin sabit olmasıdır (örneğin her kişinin adı 10 karakterlik dizide tutulur).
  - O zaman `s[3]`'ün adresi `adres(s[0]) + 3 * sizeof(struct)` olur. `s[3].borc` için önce `s[3]`'e gidilir, sonra borçtan önceki alanların büyüklüğü kadar ilerlenir.
- Çok boyutlu diziler
  - Matrisler de bellekte satır satır, tek bir dizi gibi ardışık tutulur.
  - `a[i][j]`'ye erişmek için önce i satır atlanır (satır sayısı × bir satırın büyüklüğü), sonra satır içinde j eleman atlanır.
  - Beş boyutlu `a[i][j][k][m][z]` gibi diziler de bellekte tek bir çizgi hâlinde durur (ekrandan, 00:30:00).
- Sabit boyutlu dizi ve dinamik bellek
  - Dizi boyutu program başlamadan biliniyorsa normal dizi tanımlanır.
  - Boyut program çalışınca belli oluyorsa büyük bir maksimum alan açmak her zaman iyi değildir: alan boşa gidebilir ya da yetmeyebilir.
  - Çözüm dinamik bellek yönetimidir (`malloc`, `free`). Bu derste ayrıntısına girilmedi; sonraki dönemin yapısal programlama dersinde görülecek.
- Erişim karmaşıklığı
  - Dizide `a[i]`'ye erişim sabit sayıda işlemle yapılır: $O(1)$ (ekrandan, 00:35:00).
  - Sıralı erişimli bir yapıda `a[i]`'ye erişim $O(n)$'dir: baştan başlanıp birer birer ilerlenir.
- Sıralı erişim ve "sonraki elemanın adresi"
  - Elemanlar bellekte dağınık ve aralarındaki boşluklar farklıysa bir elemandan sonrakine atlamak için her elemanın yanında bir sonraki elemanın adresi tutulmalıdır (ekrandan, 00:40:00).
  - Derste bu adresler ikinci bir dizide (B dizisi, sonra `Po`) tutuldu. Gerçek gerçekleştirimde bu bir işaretçi (pointer) dizisidir.
- Dizide sıralı ekleme ve silmenin maliyeti
  - Sıralı `1, 7, 12, 34` dizisine 6 eklenince dizi `1, 6, 7, 12, 34` olur; 6'dan sonraki bütün elemanlar bir sağa kaydırılmalıdır (ekrandan, 00:50:00).
  - 7 silinince arkasındaki elemanlar bir sola kaydırılır.
  - Dizide eleman ekleme ve silme $O(n)$ karmaşıklıktadır.
- Dizi ile linkli liste gerçekleştirimi (A ve Po dizileri)
  - `A` elemanları sırasız tutar; `Po[i]`, `A[i]`'den sonra gelecek elemanın indisini tutar. `Po[0]` listenin başını (en küçük elemanın indisini) gösterir. Liste sonu `-1` ile gösterilir (C'de NULL da kullanılabilir).
  - Örnek: `A[1..5] = 2, 5, 4, 8, 1`; küçükten büyüğe erişim için `Po[0..5] = 5, 3, 4, 2, -1, 1` (ekrandan, 00:55:00).
  - 7 ekleme: 7 dizinin sonuna (`A[6]`) yazılır; `Po[2]` 4'ten 6'ya, `Po[6] = 4` yapılır. Yalnız iki değişiklik yeter, kaydırma yoktur (ekrandan, 01:00:00).
  - 4 silme: `Po[1]` 3'ten 2'ye değiştirilir; tek değişiklik yeter (ekrandan, 01:15:00).
  - Silinen eleman bellekte kalır ama artık ona erişilemez. 4 yeniden eklenmek istenirse sona (`A[7]`) yazılır, `Po[1] = 7` ve `Po[7] = 2` yapılır.
- Referanssız bellek ve çöp toplayıcı
  - Silinen elemanların kapladığı, artık hiçbir referansın göstermediği bölgeler belleği şişirir.
  - Java'da Garbage Collector bu bölgeleri bulup temizler. C'de bu iş programcıya kalır: C daha fazla özgürlük verir, bedeli de dikkat edilmesi gereken şeylerin çok olmasıdır.
- Ardışık yer bulunamadığında parçalı yerleşim
  - Programa ayrılmış bellekte istenen büyüklükte ardışık boş yer yoksa veri parçalara bölünüp boş yerlere konur ve linkli liste mantığıyla bütünlük korunur (ekrandan, 01:00:00). Disklerde ve işletim sistemlerindeki sayfalarda (page) aynı temel fikir kullanılır.
- Derste gösterilen C programı (`linkedList.c`)
  - `main`: eleman sayısı N ve elemanlar `B[1..N]`'ye okunur; `PO[0]=1; A[1]=B[1]; PO[1]=-1;` ile tek elemanlı liste kurulur; sonra `i = 2..N` için `elemanEkle(A, i, ek, PO)` çağrılır (ekrandan, 01:20:00).
  - Ardından bir eleman eklenir, bir eleman silinir; her adımdan sonra `listeleriYazdir(A, PO, N)` ve `siraliYazdir(A, PO)` çağrılır.
  - `elemanEkle`: yeni eleman `A[i]`'ye yazılır, `j = PO[0]`'dan başlanıp `A[j] < ek` olduğu sürece ilerlenir, sonra `Po`'da iki güncelleme yapılır (önceki → yeni, yeni → sonraki).
  - `elemanSil`: silinecek eleman bulunur ve `Po`'da tek güncelleme yapılır; `A`'ya dokunulmaz. Eleman yoksa `j` sonunda `-1`'e varır.
- Çift yönlü linkli liste (double linked list)
  - İleri yönlü `Po`'nun yanında bir önceki elemanı gösteren geri yönlü bir dizi de tutulursa sona yakın elemanlara sondan başlayarak erişilir; erişim $O(n/2)$'ye iner (ekrandan, 01:30:00).
  - Bedeli ek bellektir. Ancak işaretçiler küçüktür; dizinin elemanları (örneğin 1 MB'lık struct'lar) çok daha büyük olabilir, bu yüzden ek maliyet genelde küçüktür (ekrandan, 01:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Dizide hızlı erişimin sebebi bellek mimarisidir
  - Elemanlar ardışık ve aynı büyüklükte olduğu için istenen adres basit aritmetikle bulunur. Farklı büyüklükte elemanlar olsaydı `a[4]`'ün nerede olduğu hesaplanamazdı.
- Struct dizisi için sabit büyüklük şartı
  - Her kaydın alanlarının büyüklüğü tanımlandıktan sonra sabittir; bu sayede struct dizilerinde de dizideki aritmetik kullanılır.
- Linkli listenin asıl faydası
  - Çok sayıda ekleme ve silme yapılan ve sıralı tutulması gereken bir dizide kaydırma gerekmez; sabit sayıda `Po` güncellemesi yeter.
- Hız ve bellek arasındaki ödünleşim (trade-off)
  - Bir şeyi hızlandırmak genelde daha fazla bellek harcamayı gerektirir. Çift yönlü liste ve daha önce görülen doğrusal zamanlı sıralama (değeri indis olarak kullanan) bunun örnekleridir.
- C'nin özgürlüğü ve sorumluluğu
  - C'de referansı kalmayan bellek bölgelerini temizlemek programcının işidir; Java'daki gibi bir çöp toplayıcı yoktur.

## Kısa Tekrar Notları

- RAM: her adrese tek adımda erişim. Sıralı erişim: n'inci elemana n adımda.
- `int a[10]` → 40 bayt ardışık alan; `adres(a[i]) = adres(a[0]) + i * sizeof(tip)`.
- Matris bellekte satır satır, tek dizi gibi durur.
- Struct: farklı türden alanların birleşimi; struct dizisi için alan büyüklükleri sabit olmalı.
- Dizide erişim $O(1)$; sıralı dizide ekleme ve silme $O(n)$ (kaydırma).
- Linkli listede erişim $O(n)$; ekleme 2, silme 1 bağlantı güncellemesiyle yapılır.
- `Po[0]` liste başı, `-1` liste sonu.
- Örnek: `A = 2, 5, 4, 8, 1` → `Po = 5, 3, 4, 2, -1, 1`; 7 ekle → `Po[2] = 6`, `Po[6] = 4`; 4 sil → `Po[1] = 2`.
- Silinen eleman bellekte kalır; C'de temizlik programcının işi, Java'da Garbage Collector var.
- Çift yönlü liste: ileri ve geri bağlantı, sona yakın erişim hızlanır, bedeli ek bellek.

## Detaylı Açıklamalar

- Dizilerin hızlı erişimi tamamen bellek yerleşiminden gelir. `int a[10]` tanımlanınca 10 tane 4 baytlık hücre ardışık ayrılır. `a[3]` istendiğinde `a[0]`'ın adresi alınır, üstüne 3 tane `int` büyüklüğü eklenir ve o adresteki veri okunur. Bu, i'nin 1 ya da 2 milyon olmasından bağımsız olarak sabit sayıda çarpma ve toplamayla yapılır; bu yüzden erişim $O(1)$'dir. Eleman tipi değişirse yalnız `sizeof` değeri değişir, hesap aynı kalır.

- Aynı mantık struct dizilerinde ve çok boyutlu dizilerde de geçerlidir. Bir matrisin `a[2][7]` elemanına gitmek için önce 2 satırlık alan atlanır. Tahtadaki örnekte bir satır 20 elemanlı, her eleman 10 bitliktir; bir satır 200 bit, iki satır 400 bit eder. Sonra satır içinde 0'dan 6'ya kadar olan 7 eleman atlanır.
  - Ders sonrası not: Hoca satır içi atlamada "6 ile çarpıp" dedi; `a[..][7]`'ye gelmek için 0-6 arasındaki 7 eleman atlanır, yani satır başına 7 × 10 = 70 bit eklenir. Toplam uzaklık 400 + 70 = 470 bittir.

- Linkli liste ihtiyacı, dizinin zayıf yanından doğar. Sıralı tutulan bir diziye araya eleman eklemek ya da aradan eleman silmek, arkadaki bütün elemanların kaydırılmasını gerektirir; 100.000 elemanlı bir dizinin ortasına ekleme 50.000 kaydırma demektir. Linkli listede elemanlar bellekte sırasız durabilir; sıra bilgisi her elemanın yanında tutulan "sonraki elemanın yeri" ile sağlanır. Bunun karşılığı, elemanlara erişimin artık $O(n)$ olmasıdır.

- Derste linkli liste işaretçi kullanmadan iki diziyle kuruldu: `A` değerleri, `Po` bağlantıları tutar. Tahtadaki örnekte `A[1..5] = 2, 5, 4, 8, 1` için `Po[0] = 5` (en küçük eleman 1, indis 5), `Po[5] = 1` (1'den sonra 2), `Po[1] = 3` (2'den sonra 4), `Po[3] = 2` (4'ten sonra 5), `Po[2] = 4` (5'ten sonra 8), `Po[4] = -1` (8 son eleman). 7 eklenirken `A`'nın sonuna yazılır ve yalnız 5'in bağlantısı ile 7'nin bağlantısı ayarlanır. 4 silinirken yalnız 2'nin bağlantısı 4'ün atlanacağı şekilde 5'e çevrilir.

- Derste gösterilen `linkedList.c` programının `main` bölümü ekranda okundu (ekrandan, 01:20:00); fonksiyonların gövdeleri karelerde görünmüyor. <!-- BELİRSİZ: elemanEkle, elemanSil, listeleriYazdir ve siraliYazdir fonksiyonlarının gövdeleri karelerde yok; yalnız hocanın sözlü anlatımı aktarıldı. --> Genişletilmiş notta, hocanın anlattığı mantıkla ajan tarafından yazılmış ve `gcc -Wall` ile derlenip tahtadaki girdilerle denenmiş bir sürüm vardır.

- Çift yönlü listede geri bağlantılar sayesinde n'inci elemana tek adımda, n-2'nci elemana üç adımda gidilir; listenin ilk yarısı için ileri, ikinci yarısı için geri bağlantı kullanılırsa en kötü erişim yaklaşık $n/2$ adım olur. Bir öğrenci, bu yüzden iki bağlantı dizisinin yarıya kadar doldurulmasını önerdi; hoca bunun yalnız erişim senaryosu için doğru olduğunu, ama programlarda çoğu zaman bir elemanın hem öncekine hem sonrakine aynı anda erişmek gerektiğinden iki dizinin de tam doldurulduğunu söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
