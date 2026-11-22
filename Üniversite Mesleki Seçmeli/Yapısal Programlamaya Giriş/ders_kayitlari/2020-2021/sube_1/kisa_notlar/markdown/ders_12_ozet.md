# Ders 12 Çalışma Özeti

## Genel Konular

- Çember üzerinde desen üreten algoritma (matematik ve sanat)
  - Ekranda her birinin üstünde iki sayı (örneğin 337-10, 53-51) yazan çizgi desenleri gösterildi. Hepsi aynı kodla çiziliyor, yalnız iki parametre değişiyor (ekrandan, 00:10:00).
  - Desenler elini kaldırmadan çizilir: çember eşit aralıklı $m$ noktaya bölünür, çizgi hep çember üzerindeki bir noktadan başka bir noktaya gider. İçeride hiç nokta yoktur.
  - Algoritma: kullanıcıdan $m$ (nokta sayısı) ve $s$ alınır. `P = noktaUret(m)` fonksiyonu $2 \times m$ boyutlu $P$ matrisini döndürür; her sütun bir noktanın $(x_1, x_2)$ koordinatlarıdır (ekrandan, 00:20:00).
  - $i = 1$ ile başlanır, $j = 1 \ldots m$ döngüsünde $y_i = (i \cdot s) \bmod m$ hesaplanır, `birlestir(P, yi, i)` ile $i$. ve $y_i$. noktalar arasına çizgi çekilir, sonra $i = y_i$ yapılır (ekrandan, 00:20:00).
  - $i$ ve $y_i$ koordinat değil, $P$ matrisinin sütun indisleridir. $\bmod\ m$ işlemi $0 \ldots m-1$ arasında değer verdiği için indisler $0$'dan $m-1$'e kadar düşünülür.
- Dizinin tekrar etmesi ve döngüler
  - Her değer yalnız bir önceki değere bağlıdır. Bu yüzden bir değer ikinci kez görüldüğünde dizinin geri kalanı tamamen bellidir ve aynı döngü sürekli tekrar eder (ekrandan, 00:30:00).
  - Güzel desen veren $m$, $s$ çiftleri çemberin bütün noktalarını tekrar olmadan gezer. Bu durumda süreç, $1 \ldots m$ sayılarının karıştırılmış, tekrarsız bir dizisini üretir. Desenin güzelliği bunun yan ürünüdür.
  - Kaç noktanın gezildiğini saymak için $T$ dizisi sıfırlanır ve döngüde $T[i] = T[i] + 1$ yapılır. Sonunda $T$'nin bütün elemanları 1 ise üreteç her değeri bir kez üretmiştir.
- Uniform (tekdüze) sayı üreteci
  - Her değerin gelme olasılığı eşitse üreteç uniformdur. Olasılıklar eşit değilse (örneğin 1-5 arasında 5'in olasılığı çok yüksekse) sonraki sayı kolay tahmin edilir (ekrandan, 00:40:00).
  - $1 \ldots M$ arasında uniform bir üreteçte bir sonraki sayıyı tutturma olasılığı $1/M$'dir; $M = 100.000$ için çok düşüktür.
- Rastgele sayı üreteçleri ve sözde rastgelelik
  - Anlatılan süreç bilgisayarlardaki rastgele sayı üreteçlerinin temelidir (ekrandan, 00:45:00).
  - Bilgisayarlarda gerçek rastgelelik (true randomness) yoktur. Bilgisayarlar deterministik sistemlerdir: mekanizma ve mevcut durum bir sonraki durumu belirler. Dillerdeki bütün `random` fonksiyonları sözde rastgele (pseudo random) üreteçlerdir.
  - Gerçekte kullanılan bir üreteç: $R_n = (A \cdot R_{n-1} + C) \bmod M$, $R_0 = 0$, $A = 1366$, $C = 150889$, $M = 714025$. Önceki formülden tek farkı $+C$ terimidir. <!-- BELİRSİZ: Formülün yazıldığı anın karesi yok; formül ve değerler altyazıdan alındı. -->
  - $A$, $C$, $M$ özenle seçilmelidir: iyi bir üreteç $0 \ldots M-1$ arasındaki bütün değerleri $M$ adımda, yani eşit olasılıkla üretir.
- Seed (tohum) değeri
  - Üreteç bir çevrim üzerinde döner; başlangıç noktası değişince süreç değişmez, yalnız görülen sayılar kayar. Örneğin 1'den başlayınca $1, 2, \ldots, 7$, 2'den başlayınca $2, 3, \ldots, 7, 1$, 5'ten başlayınca $5, 6, 7, 1, 2, 3, 4$ görülür (ekrandan, 01:05:00).
  - Bu başlangıç değerine seed denir. Seed hep aynıysa program her çalıştığında aynı sayı dizisi gelir (örneğin tavla programında zarlar hep aynı sırayla gelir).
  - C'de klasik çözüm `#include <stdlib.h>`, `#include <time.h>` ve `srand(time(NULL));` satırıdır. `time(NULL)` 1.1.1970'ten programın çalıştığı ana kadar geçen saniyeyi döndürür (ekrandan, 01:05:00).
  - Seed'i değiştirmek olasılıkları değiştirmez; yalnız başlangıç noktasını değiştirir.
- Zar üretmek ve hile kontrolü
  - $zar = 1 + ((a \cdot zar + c) \bmod 6)$. $\bmod 6$ işlemi $0 \ldots 5$ verir, $+1$ ile zar $1 \ldots 6$ olur (ekrandan, 01:25:00).
  - Hilesiz zar: altı değerin olasılıkları eşittir. Kontrol için çok sayıda zar atılır ve $T[zar] = T[zar] + 1$ ile sayılır. Sayıların tam eşit çıkması beklenmez; hepsi ortalamanın çevresindeki bir tolerans aralığındaysa (örneğin 600.000 atışta $100.000 \pm 1000$) zar hilesiz sayılır (ekrandan, 01:25:00).
- Aralık dönüşümü
  - $[0, 1]$ aralığında uniform sayı üreten `rand` ile $[x, y]$ kapalı aralığında tam sayı: $x + \lfloor t \cdot (y - x + 1) \rfloor$, $t = rand$. Örnek: $x = 45$, $y = 54$ için $y - x + 1 = 10$.
  - Ders sonrası not: Derste `rand`'ın 1'i de üretebildiği söylendi. $t = 1$ çıkarsa formül $55$ verir ve aralığın dışına çıkar. Formül $t \in [0, 1)$ için doğrudur.
- 52 kartı karıştırma
  - Amaç $1 \ldots 52$ sayılarının bir permütasyonunu üretmektir (ekrandan, 01:35:00).
  - 1. yol: $B$ dizisi daha önce çıkan sayıları işaretler. `for` ile 52 kez dönülürse tekrar eden sayılar atlandığı için 52 sayı çıkmaz. Doğrusu `while (i < 52)`: $T = rand()$; $B[T] \ne 1$ ise $A[i] = T$, $B[T] = 1$, $i = i + 1$ (ekrandan, 01:40:00).
  - 1. yolun sorunu: $B$ doldukça yeni sayı bulmak için `rand` çok kez çağrılır; son sayı için ortalama 52 deneme gerekir.
  - 2. yol: $A$'ya $1 \ldots 52$ yazılır, iki rastgele indis $T_1$, $T_2$ üretilip elemanlar `Temp` ile yer değiştirilir; işlem örneğin 30 kez tekrarlanır (ekrandan, 01:45:00). Her adım bir değişiklik yaptığı için daha hızlıdır; dizi büyüdükçe üstünlüğü artar.
- Gauss (normal) dağılım
  - Bazı uygulamalar uniform değil, çan eğrisi (Gaussian, normal dağılım) biçiminde sayı ister: ortalamaya yakın değerler sık, uzak değerler seyrek gelir (ekrandan, 01:50:00).
  - Örnek: bir sınavdaki notlar ortalama bir not çevresinde kümelenir; farklı sınavların ortalamaları farklı olabilir (ör. 30 ve 70).
  - İki uniform sayının toplamı ($C = A + B$) uniform değildir. $A, B \in 1 \ldots 99$ iken $C = 2$ yalnız $(1,1)$ ile, $C = 4$ ise $(1,3)$ ve $(2,2)$ ile oluşur; ortadaki değerlerin çok fazla olasılığı vardır, $C = 198$ yine yalnız $(99, 99)$ ile oluşur (ekrandan, 01:55:00). Sonuç çan eğrisine benzer.
- Rastgele yürüyen robot
  - Robot bir ızgarada $(x, y)$ konumundadır ve 4 yöne gider: 1 → $(x-1, y)$, 2 → $(x, y+1)$, 3 → $(x+1, y)$, 4 → $(x, y-1)$ (ekrandan, 02:15:00).
  - İlk çözüm: $R_x = 3$, $R_y = 3$; $i = 1 \ldots N$ döngüsünde $y = rand()$ ($1 \ldots 4$) ve iç içe `if`'lerle konum güncellenir; gidilen yer $A[R_x, R_y] = 1$ ile işaretlenir (ekrandan, 02:15:00). 8 yön olsaydı 7 `if` gerekirdi.
  - `if`'siz çözüm: $2 \times 4$'lük bir $U$ matrisi her yön için $x$ ve $y$ değişimini tutar. $R_x = R_x + U[1][y]$, $R_y = R_y + U[2][y]$. 8 yön için yalnız $U$'ya dört sütun eklenir.
- Monte Carlo ile $\pi$
  - Algoritma: $say = 0$; $N$ kez $x = rand()$, $y = rand()$ ($[0,1]$ aralığında); $x \cdot x + y \cdot y < 1$ ise $say = say + 1$; sonunda $T = 4 \cdot say / N$ yazdırılır (ekrandan, 02:30:00).
  - $(x, y)$ birim karede bir noktadır. $x^2 + y^2 < 1$ bölgesi yarıçapı 1 olan çeyrek dairedir. Alanların oranı $\frac{\pi r^2 / 4}{1} = \pi/4$ olduğundan $T = 4 \cdot say / N$ değeri $N$ büyüdükçe $\pi$'ye yaklaşır (ekrandan, 02:45:00).
  - Bu tür saymayla hesap yapan yöntemlere Monte Carlo süreçleri denir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bilgisayarlarda gerçek rastgelelik yoktur
  - Hoca bunu "önemli bir cümle" diyerek tahtaya yazdırdı (ekrandan, 00:45:00). Bütün `random` fonksiyonları, bir önceki değere bağlı deterministik bir formülle çalışır.
- Rastgelelik illüzyonunun iki dayanağı
  - Çevrimin büyük olması (her değeri gezen iyi seçilmiş $A$, $C$, $M$; örneğin yaklaşık 700.000'lik çevrim) ve her çalıştırmada farklı seed kullanılması. İkisi birlikte kullanıcının tekrarı fark etmesini zorlaştırır.
  - Seed program içinde sabit bir değere bilerek de verilebilir; o zaman her çalıştırmada aynı sayılar gelir.
- Sonuç dizisinin her değeri yalnız bir öncekine bağlıdır
  - Bir değer tekrar ettiği anda devamı bellidir; bu yüzden bütün noktaları gezmek için tekrar olmamalıdır. $m$ farklı değerden $m+1$ kez geçilirse mutlaka bir değer iki kez görülür.
- Kod tasarımında `if` zincirinden kurtulmak
  - Yön sayısı arttıkça uzayan `if` zinciri yerine yönlere göre değişimleri bir tabloda ($U$ matrisi) tutmak, kodu kısaltır ve genişletmeyi kolaylaştırır. Öğrencinin "tek bir `if`" önerisi kabul edilmedi.

## Kısa Tekrar Notları

- $y_i = (i \cdot s) \bmod m$, sonra $i = y_i$: her değer bir öncekine bağlı bir sayı dizisi.
- $\bmod\ m$ sonucu $0 \ldots m-1$ arasındadır.
- Tekrar eden bir değerden sonra dizi aynı döngüyü sürdürür.
- $T[i] = T[i] + 1$ sayacıyla uniformluk kontrol edilir; bütün elemanlar eşitse (ya da tolerans içindeyse) üreteç uniformdur.
- Bilgisayar deterministiktir; `rand` sözde rastgeledir: $R_n = (A R_{n-1} + C) \bmod M$.
- Seed başlangıç noktasıdır; C'de `srand(time(NULL));`.
- Zar: $1 + ((a \cdot zar + c) \bmod 6)$.
- $[x, y]$ aralığına dönüşüm: $x + \lfloor t (y - x + 1) \rfloor$.
- Kart karıştırma: reddetme yöntemi (`while` + $B$ dizisi) yavaş, rastgele yer değiştirme hızlı.
- İki uniform sayının toplamı çan eğrisine benzer dağılım verir.
- Rastgele yürüyüşte yön tablosu ($U$ matrisi) `if`'leri ortadan kaldırır.
- Monte Carlo: $T = 4 \cdot say / N \to \pi$.

## Detaylı Açıklamalar

- Desen algoritmasının mantığı
  - Çemberi $m$ eşit parçaya bölen noktalar $P$ matrisinde saklanır. Bu matris baştan bellidir; döngü içinde koordinatlar üzerinde hiçbir işlem yapılmaz. Döngüde yalnız indisler değişir: o anki indis $i$ ise bir sonraki indis $(i \cdot s) \bmod m$ olur ve iki nokta bir çizgiyle birleştirilir. $m$ adım sonra çizim biter.
  - Tahtadaki gösterimde $m = 53$, $s = 5$ için "1, 42, 4, 5, 6, 33, 4, ..." gibi varsayımsal bir dizi yazıldı: 4 ikinci kez görülünce "5, 6, 33, 4, 5, 6, ..." diye aynı döngü sürer (ekrandan, 00:30:00). Buradaki sayılar gerçek hesap değil, döngüyü göstermek için seçilmiş örneklerdir.
  - Ders sonrası not: $i = 1$ ile başlanıp $y_i = (i \cdot s) \bmod m$ uygulanırsa ($s$ ile $m$ aralarında asal iken) $0$ değeri hiç çıkmaz; en fazla $m-1$ farklı nokta gezilir. Ekrandaki 53-51, 337-10 ve 337-20 çiftleri için döngü uzunlukları sırasıyla 52, 336 ve 336'dır (python ile hesaplandı), yani 0 dışındaki bütün noktalar gezilir. Derste söylenen "$m$ adımda bütün noktalar" ifadesi bu ayrıntıyı atlar.
- Neden "sözde" rastgele?
  - Üretilen her sayı bir öncekinden kesin bir formülle hesaplandığı için, formülü ve son değeri bilen biri bütün diziyi bilir. Rastgelelik yalnız dışarıdan bakan için vardır: önceki değer bilinmezse ve üreteç uniformsa sonraki değer tahmin edilemez.
  - Derste verilen $A = 1366$, $C = 150889$, $M = 714025$ değerleriyle $R_0 = 0$'dan başlayan dizinin 714.025 adımda bütün değerleri tam bir kez ürettiği python ile doğrulandı.
- Seed seçimi
  - Seed'i 3 ya da 5 gibi sabit bir sayı yapmak işe yaramaz; her çalıştırmada farklı olmalıdır. Sistem saati iyi bir kaynaktır. "Bilgisayar en son ne zaman kapatıldı" gibi bir değer iyi değildir, çünkü bilgisayarlar artık sık kapatılmaz. Aynı saniye içinde iki kez çalıştırılırsa aynı seed alınır; daha yüksek çözünürlüklü zaman (salise) kullanılabilir.
  - Bir öğrencinin her çalıştırmada aynı diziyi görmesinin nedeni, seed'in her seferinde aynı değere ayarlanmasıdır.
- Kart karıştırmada iki yolun karşılaştırılması
  - 1. yolda başta neredeyse her deneme başarılıdır, ama $B$ dizisi doldukça denemelerin çoğu boşa gider. 2. yolda her yer değiştirme diziyi gerçekten değiştirir, bu yüzden çok daha hızlıdır.
  - Ders sonrası not: 2. yolda 52 elemanlı dizide 30 rastgele yer değiştirme yapıldığında her elemanın hiç dokunulmadan kalma olasılığı $(51/52)^{60} \approx 0{,}31$'dir; ortalama yaklaşık 16 kart yerinde kalır (python ile hesaplandı ve benzetimle denendi). Yani 30 değiştirme büyük olasılıkla iyi bir karışım için yetmez.
- Rastgele yürüyüş için önerilen fikirler
  - Bir öğrenci her yönün kaç kez çıktığını tutan bir dizi önerdi; bu, `if`'leri ortadan kaldırmadığı için kabul edilmedi.
  - Başka bir öğrenci $x$ ve $y$ için ayrı iki `rand` ($A$ ve $B$) üretip $R_x = R_x + A$, $R_y = R_y + B$ yapmayı önerdi. Değerlerin $-1, 0, 1$ olması gerekir; ama 4 yönlü harekette bu, $(-1, -1)$ gibi çapraz hareketleri de üretir (ekrandan, 02:25:00). Hoca bu fikri değiştirerek $U$ matrisine vardı.
- Monte Carlo ile $\pi$ çıkarımı
  - $N \to \infty$ düşünülürse çeyrek daire içindeki noktalar bölgeyi tamamen doldurur; $say$ çeyrek dairenin alanına ($\pi/4$), $N$ karenin alanına (1) karşılık gelir. $4 \cdot say / N = 4 \cdot (\pi/4) / 1 = \pi$.
  - Sınıfta tahminler çoğunlukla 1 ve 2 oldu; doğru cevap $\pi$'dir.
- Derste sorulan ek sorular
  - Çok yüksek çözünürlük: Değişkenin türü (`int`, `float`, `double`) bellekte ayrılan alanı, bu da alabileceği en küçük ve en büyük değeri belirler. 100.000 basamaklı bir sayı tek değişkende tutulamaz, ama basamakları bir dizide tutulabilir. O zaman toplama, çıkarma, çarpma gibi işlemleri kendiniz yazmanız gerekir.
  - `float` ile $3/10$'un $0{,}3000001$ gibi çıkması: kayan noktalı aritmetikte yuvarlama yapılmak zorunda kalınmasından kaynaklanır; ayrıntısı bilgisayar mimarisi derslerinde görülür. Tam sayılarla çalışıldığı sürece bu sorun olmaz.
  - Çizim: Desenleri çizmek için harici bir grafik kütüphanesi gerekir. Komut isteminde bile, her değerin kaç kez tekrar ettiğini satır başına yıldız koyarak metin olarak göstermek mümkündür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
