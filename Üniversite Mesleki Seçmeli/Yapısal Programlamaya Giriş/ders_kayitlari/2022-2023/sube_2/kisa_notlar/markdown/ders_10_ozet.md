# Ders 10 Çalışma Özeti

## Genel Konular

- Fonksiyon türleri: parametre alma ve değer döndürme
  - Bir fonksiyon iki açıdan sınıflanır: parametre alıp almaması ve değer döndürüp döndürmemesi. Bu, $2 \times 2 = 4$ durum verir.
  - Parametre almayan ve değer döndürmeyen örnek: ekrana menü basan `void menu()`. Ekranı temizlemek için Windows'ta `system("cls")` çağrılabilir.
  - Parametre alıp değer döndürmeyen örnek: `void ekranaYaz(double x, double y)`; `double` değerler `%lf` ile yazılır.
  - Parametre almayıp değer döndüren örnek: kullanıcıdan bir tam sayı okuyup döndüren `int degerOku()`.
  - Hem parametre alan hem değer döndüren örnek: `int mySquare(int x) { return x*x; }`. Önce ifade hesaplanır, sonra sonuç döndürülür.
  - `main`'den sonra yazılan fonksiyonun başlığı, sonuna `;` konarak `main`'den önce **prototip** olarak yazılır. Başlık değişirse prototip de değiştirilmelidir; yoksa derleyici "conflicting types" uyarısı verir.
  - `return` ile yalnız tek bir değer döndürülür; `return t, a;` gibi bir yazımla iki değer döndürülemez.
  - ANSI C'de varsayılan parametre değeri yoktur; iki parametreli bir fonksiyona bir ya da üç argüman gönderilemez. `printf` ve `scanf` gibi fonksiyonlar `...` ile değişken sayıda argüman alır; bu dönemin konusu değildir.
- Fonksiyona dizi gönderme
  - Dizi, eleman sayısıyla birlikte gönderilir: `void buyukHarfeCevir(char c[], int n)`. Köşeli parantezin içi boş bırakılabilir ve tercih edilen yazım budur.
  - Dizinin adı ilk elemanın adresini tutan bir pointer gibidir. Fonksiyona dizinin elemanları değil, bu adres kopyalanır (sığ kopya, shallow copy). Skaler değişkenlerin ise birebir kopyası oluşur (derin kopya, deep copy).
  - Bu yüzden fonksiyon içinde dizinin elemanlarında yapılan değişiklik çağıran yerdeki asıl diziye yansır. Bunun `void` olmakla ilgisi yoktur.
  - Örnek: `c = {'a','b','c','d'}` dizisi `buyukHarfeCevir` içinde `c[i] -= 32` ile değiştirilince, `main`'de ikinci `diziYazdir` çağrısı `A B C D` basar (ekrandan, 00:30:00).
  - Bu mekanizma 4000 elemanlık bir dizinin her çağrıda kopyalanma maliyetini ortadan kaldırır. Dizinin değişmemesi isteniyorsa parametre `const` yapılabilir.
  - Fonksiyondan dizi döndürülemez (`return d;` ile yerel dizi döndürmek yoktur). Bu ancak pointer ve `malloc` ile yapılır ve bu dersin konusu değildir.
- Yığın (stack) ve yerel değişkenin ömrü
  - Çağrılan her fonksiyon yığında geçici bir alan açar; fonksiyon bitince bu alan serbest kalır ve sonraki çağrılar aynı bölgenin üstüne yazar.
  - Yerel bir değişkenin adresini döndüren `int* myfunc(int p, int x)` fonksiyonu derlenir ama yanlıştır; derleyici `function returns address of local variable` uyarısı verir (ekrandan, 00:50:00).
  - Derste `ptr = myfunc(c[2],2);` çağrısından hemen sonra `*ptr` 71 ($67 + 2\cdot 2$) gösterdi. Araya başka fonksiyon çağrıları girince aynı adreste çöp değer (4) görüldü.
  - Değer döndüren fonksiyonda sorun yoktur: `x = mySquare(5);` ile dönen 25, `x`'e kopyalanır.
- Pointer ile birden fazla sonuç alma
  - `void funcG(int *x, int *y) { *x=5; *y=8; }` fonksiyonu `funcG(&y,&t)` ile çağrılınca `y=5`, `t=8` olur (ekrandan, 00:55:00). `scanf("%d %d", &x, &y)` de aynı mantıkla çalışır.
  - `void bul(char c[], int N, int *max, int *min)` en büyük ve en küçük elemanın indisini pointer'lar üzerinden döndürür. `ABCD` dizisi için `max=3`, `min=0` çıkar (ekrandan, 01:00:00).
- Önceki algoritmaları fonksiyonlara bölme
  - `diziDoldur`, `diziYazdir(char *c, int d[], int n)`, `merge(int d1[], int n, int d2[], int m, int d3[])` fonksiyonları yazıldı. `diziYazdir` başa bir etiket yazar (`"Dizi-1"` gibi) (ekrandan, 01:20:00).
  - Her fonksiyonun tek bir görevi olmalıdır; dizi dolduran fonksiyon diziyi yazdırmaz.
  - `#define` ile tanımlanan bir makro adı parametre adıyla aynı olursa önişlemci onu da değiştirir ve derleme hatası çıkar. Makro adları genelde büyük harfle yazılır.
  - Dizinin sıralı olup olmadığını denetleyen `kontrol` fonksiyonu: `while (i<n-1 && d[i]<d[i+1]) i++;` döngüsünden sonra `i==n-1` ise dizi sıralıdır (ekrandan, 01:25:00). Önce 1/0 döndürüldü, sonra okunaklı olsun diye `"SIRALI"`/`"SIRASIZ"` sabit dizgileri döndürüldü (ekrandan, 01:30:00).
- Soru: 1 ve 2'lerden oluşan dizide kaç 1, kaç 2 var?
  - Birinci çözüm: `void say(int d[], int n, int *c1, int *c2)` iki sayacı pointer ile günceller (ekrandan, 01:35:00). `1 2 1 2 1` için sonuç 3 ve 2.
  - Bu çözüm genel değildir: 3'ler, 4'ler eklendikçe yeni sayaç ve yeni `else if` gerekir.
- Histogram
  - Bir veri kümesinde her değerden kaç tane olduğunu gösteren dağılıma histogram denir. Örnek: 0-100 arası notlardan her nottan kaç tane alındığı.
  - Genel çözüm: değer aralığı kadar bir `histogram` dizisi açılır, `int histogram[MAX] = {0};` ile sıfırlanır ve tek satırla sayılır: `histogram[notlar[i]]++;` (ekrandan, 01:50:00).
  - C, belleği temizlemeden verir; sıfırlanmayan histogramda çöp değerler görüldü.
  - Histogram yatay yıldızlarla basılır: iç içe iki döngü, dıştaki histogramı gezer, içteki `d[i]` kadar `*` yazar. Yalnız `d[i] > 0` olan satırlar `i - d[i] :***` biçiminde basılır.
  - Kazanç: çok sayıda `if` yazmaktan kurtulunur. Kayıp: bellek; değerler büyükse çok büyük bir dizi gerekir.
- Seçim sistemleri (histogram uygulamaları) (ekrandan, 02:55:00)
  - En çok oyu alan parti: oylar $N$ elemanlı bir dizidir. Oyların histogramı çıkarılır, histogramın en büyük elemanının indisi kazanandır (`enBuyukBul`). Oylar `rand() % 10 + 1` ile rastgele üretildi; her çalıştırmada farklı olması için `srand(time(NULL))` çağrıldı.
  - Herkes 3 partiye oy veriyor: oylar $N \times 3$'lük matristir. Sayma `histogram[oylar[i][j]]++` olur.
  - Herkes her partiye 1-10 arası puan veriyor: $N \times P$'lik matris; her parti için sütun toplanır: `histogram[j] += oylar[i][j]` (ekrandan, 02:45:00).
  - Oylar ağırlıklı (vergi, yaş, eğitim vb.): puan, kişinin ağırlığıyla çarpılır. Slayttaki veri yapısı $N \times 2$'lik matris: ilk sütunda ağırlık, ikinci sütunda oy.
  - Fonksiyona matris gönderirken ikinci boyut mutlaka yazılır: `void diziDoldur(int d[][O], int n, int m)` (ekrandan, 02:25:00).
- Sayarak doğrusal sıralama (linear sort with counting)
  - Fikir: benden küçük $k$ sayı varsa benim yerim $k+1$'dir.
  - Önce her eleman için kendisinden küçük olanların sayısı `K` dizisine yazılır, sonra `B(K(i)+1) = A(i)` ile yeni dizi kurulur. Örnek: $A = 6, 3, 4, 2 \Rightarrow K = 3, 1, 2, 0 \Rightarrow B = 2, 3, 4, 6$ (ekrandan, 02:55:00).
  - Zaman $n^2 + n \approx n^2$; ek bellek $2n$ (`K` ve `B`).
  - İki kat hızlandırma: iç döngü `j = 1..i` olur; `A(i) > A(j)` ise `K(i)` artar, değilse `K(j)` artar. İşlem sayısı $\sum_{i=1}^{n} i = \frac{n(n+1)}{2} \approx \frac{n^2}{2}$ olur ama karmaşıklık yine $O(n^2)$'dir.
- Counting sort
  - `T`, `A`'nın en büyük elemanıdır. `K[1..T]` sıfırlanır, her eleman için `K(A(i)) = 1` yapılır, sonra `K` baştan sona gezilip `K(i) ≠ 0` olan indisler sırayla `B`'ye yazılır (ekrandan, 03:00:00).
  - Örnek: $A = 6, 2, 4, 8$, `T = 8` $\Rightarrow B = 2, 4, 6, 8$.
  - Zaman $O(\max(T, N))$, pratikte doğrusala yakın (ekrandan, 03:05:00).
  - Sorun 1: tekrarlı elemanlar. 0/1 yerine frekans tutulur (`K(A(i))++`) ve her değer frekansı kadar yazılır.
  - Sorun 2: çok büyük değerler. Dizide `INT_MAX - 5` gibi bir değer varsa `K` yaklaşık 2 milyar elemanlı, çoğu sıfır (seyrek) bir dizi olur; bu bellek ayrılamayabilir, özellikle gömülü sistemlerde.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dizi fonksiyona adresiyle gider
  - Fonksiyondaki değişiklik asıl diziye yansır; bu, swap örneğindeki pointer mantığının aynısıdır. Bunu "hiçbir zaman unutmuyoruz" diye vurguladı.
- Yerel değişkenin adresi döndürülmez
  - Kod çalışır gibi görünür ama arkasında "mayınlı arazi" vardır. Hoca bu tür kodun "hatalı sonuç verebilir" değil "verir" diye düşünülmesini istedi. Sayısal değer (int, char, float) döndürmekte sorun yoktur; pointer döndürürken çok dikkat edilmelidir.
- C'de diziyi doğrudan `return` etmek yoktur
  - Yerel dizi fonksiyon bitince yok olur; olmayan bir dizinin adresini döndürmenin anlamı yoktur.
- Dizi parametresi boyutla birlikte gelir
  - Dizi alan fonksiyon eleman sayısını da parametre olarak almalıdır; fonksiyon böylece genel (parametrik) olur.
- Her fonksiyonun tek görevi olmalı
  - Bir fonksiyonun yaptığı iş sayısı arttıkça kod zorlaşır; bu yazılım mühendisliğinin temel kuralıdır.
- Genellik (generality)
  - 1'ler ve 2'ler için doğru çalışan sayaçlı çözüm, değer çeşidi arttıkça anlamsızlaşır. Mühendislik, çözümün sonrasını da hesaba katmaktır.
- Önce veri yapısı tasarlanır
  - Seçim problemlerinde kodlamaya geçmeden önce oyların dizi mi, matris mi olacağına karar verilir.

## Kısa Tekrar Notları

- 4 fonksiyon türü: parametre alır/almaz × değer döndürür/döndürmez.
- `return` tek değer döndürür; birden fazla sonuç için pointer parametre kullanılır.
- Prototip = fonksiyon başlığı + `;`, `main`'den önce yazılır.
- Dizi parametresi: `tip ad[]` + eleman sayısı. Matris parametresi: `tip ad[][SUTUN]` + boyutlar.
- Dizi adı ilk elemanın adresidir; fonksiyondaki değişiklik asıl diziye yansır.
- Yerel değişkenin adresini döndürmek tanımsız davranıştır; dizgi sabiti (`"SIRALI"`) döndürmek sorun değildir.
- `int h[MAX] = {0};` bütün elemanları sıfırlar.
- Histogram: `h[deger]++`; puan toplamı: `h[j] += m[i][j]`.
- En çok oy alan = histogramın en büyük elemanının indisi.
- Sayarak sıralama $O(n^2)$, ek bellek $2n$; yarıya indirilmiş hali $\approx n^2/2$ ama yine $O(n^2)$.
- Counting sort $O(\max(T,N))$; tekrarlı değerler için frekans tutulmalı; çok büyük değerlerde bellek sorunu var.

## Detaylı Açıklamalar

- **Fonksiyon türleri ve prototip.** Ders, fonksiyonların dört kombinasyonunun örneklenmesiyle başladı. Menü basan fonksiyon hiçbir şey almaz ve döndürmez; asıl faydası `main`'i kalabalıktan kurtarmak ve bir döngü içinde tekrar tekrar çağrılabilmektir. `ekranaYaz(x, e)` iki `double` alır; fonksiyon tanımındaki parametre adlarının çağrıdakilerle aynı olması gerekmez. `degerOku()` bir sayı okuyup döndürür; dönen değer `y = degerOku();` ile alınır. `mySquare(x)` hem alır hem döndürür. Bir fonksiyon `main`'den önce tanımlanırsa prototip gerekmez; sonra tanımlanırsa başlığı `;` ile `main`'in üstüne yazılır. Eski derleyicilerde prototip sırası önemliydi; dizi ve pointer parametreleri devreye girince prototip yazmak fiilen zorunlu hale gelir. Bir öğrenci, iki parametreli bir fonksiyona bir ya da üç argüman gönderilip gönderilemeyeceğini sordu; hoca ANSI C'de bunun mümkün olmadığını, Python gibi dillerde varsayılan değerlerle yapılabildiğini, `scanf`'in ise prototipindeki `...` ile değişken sayıda argüman aldığını gösterdi.

- **Dizinin fonksiyona aktarımı.** `char c[4] = {'a','b','c','d'};` dizisi `buyukHarfeCevir(c, MAX)` ile gönderildi. Fonksiyonda `c[i] -= 32` yapıldı (küçük `a`'nın ASCII kodu 97, büyük `A`'nınki 65). Bir öğrenci, fonksiyon `void` olduğu için asıl dizinin değişmeyeceğini düşündü; hoca `void`'in yalnız dönüş değeriyle ilgili olduğunu, dizinin ise adresiyle gittiği için değişeceğini açıkladı ve hata ayıklayıcıda (add watch) `c`'nin fonksiyon içinde yeniden oluşmadığını, çağrıdan sonra `ABCD` olduğunu gösterdi. Fonksiyon çağrıldığında yığında geçici bir alan açılır ve fonksiyon bitince bu alan yok edilir; dizi bu alana kopyalanmaz, yalnız adresi kopyalanır.

- **Yerel adres döndürme hatası.** `int* myfunc(int p, int x) { int temp; temp = p + 2*x; return &temp; }` fonksiyonu `myfunc(c[2], 2)` ile çağrıldı. `c` önceden büyük harfe çevrildiği için `c[2]` 67'dir ve $67 + 2\cdot 2 = 71$ hesaplanır. Çağrının hemen ardından `*ptr` gerçekten 71 gösterdi, çünkü o yığın bölgesine henüz başka bir şey yazılmamıştı. Araya iki `diziYazdir` çağrısı girince aynı adres (`%p` ile yazdırılıp aynı olduğu gösterildi) çöp bir değer (4) verdi. Hoca bunu "köprünün altından çok su geçti" diye anlattı: `temp`'in ömrü (lifetime) bitmiştir.

- **Pointer ile iki değer döndürme.** `funcG(&y, &t)` çağrısında `x` pointer'ı `y`'nin, `y` pointer'ı `t`'nin adresini tutar; `*x=5; *y=8;` sonrası `y=5`, `t=8` olur. Hoca parametre adlarını bilerek karışık seçti ki eşleşmenin ada değil sıraya göre olduğu görülsün. `bul` fonksiyonu tek geçişte en büyük ve en küçük elemanın indisini `tmax`, `tmin`'de tutar, sonunda `*max = tmax; *min = tmin;` yazar.

- **Histogramdan seçime.** Not dizisinin histogramı çıkarıldıktan sonra aynı kod, "not" yerine "oy" denerek en çok oy alan partiyi bulmak için kullanıldı. `enBuyukBul` ilk yazıldığında `return i;` yazıldığı için döngü sayacının son değeri dönüyordu ve sonuç anlamsızdı; bir öğrenci hatayı fark etti ve `return max;` olarak düzeltildi. Eşit oy alan iki parti olursa `>` karşılaştırması ilk bulunanı tutar. Puanlı sistemde örnek çıktıda 0. partinin puanları $7+5+7+9+5 = 33$ oldu ve kazanan bu parti çıktı (ekrandan, 02:45:00).

- **Sıralama algoritmaları.** Sayarak doğrusal sıralamada her elemanın yeri, kendisinden küçük eleman sayısının bir fazlasıdır. Bubble sort ve selection sort da $n^2$ olduğu için zaman bakımından fark yoktur, ama bu algoritma fazladan iki dizi kullanır. Counting sort ise değer uzayı kadar bir işaret dizisi açarak sıralamayı doğrusal zamana indirir; bedeli bellektir ve yalnız küçük bir değer aralığında kullanışlıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
