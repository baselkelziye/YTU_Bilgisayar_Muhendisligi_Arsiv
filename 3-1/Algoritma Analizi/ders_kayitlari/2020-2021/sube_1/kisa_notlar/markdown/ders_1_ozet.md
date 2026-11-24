# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kaynakları ve dönem boyunca görülecek konular
  - Kaynak kitaplar: Anany Levitin, *Introduction to the Design & Analysis of Algorithms*; R. Sedgewick ve K. Wayne, *Algorithms, 4th Edition* (slaytları `algs4.cs.princeton.edu` adresinde); Steven Skiena, *The Algorithm Design Manual* (ekrandan, 00:05:00).
  - Konu listesi: asimptotik analiz, özyinelemeli ve özyinelemesiz algoritmaların analizi, böl ve yönet, azalt ve yönet, karma (hashing) algoritmaları, dinamik programlama, çizge algoritmalarının analizi, geri izleme (backtracking), dal ve sınır (branch-and-bound), zaman-yer ödünleşimi, P, NP, NP-tam ve NP-zor problemler (ekrandan, 00:20:00).
- Algoritma analizi neden gerekli
  - Veri yapıları ve algoritmalar birlikte düşünülür: bazı problemler ancak uygun bir veri yapısıyla verimli çözülür (harita uygulamasında yollar için çizge, tarayıcıda geri dönmek için yığın).
  - Bu dersin amacı, algoritmaların zamanı ve belleği ne kadar iyi kullandığını ölçmeyi ve karşılaştırmayı öğrenmektir.
- Algoritma kavramı
  - Algoritma, bir problemi çözmek için, her geçerli girdiden istenen çıktıyı sonlu sürede üreten, belirsizlik içermeyen komutlar dizisidir (ekrandan, 00:30:00).
- İyi bir algoritmanın özellikleri
  - Doğruluk, verimlilik (zaman ve yer), basitlik, genellik. Daha iyi bir algoritma olup olmadığı alt sınırlar ve optimallik ile sorulur (ekrandan, 00:35:00).
- Gerçek bir kod üzerinden kötü tasarım örneği (min-diff kodu)
  - 64 kanallık bir dizide en küçük farkı bulmak için gereksiz yere iç içe döngü kullanan açık kaynak bir kod parçası incelendi (ekrandan, 00:40:00).
- Çalışma zamanını ölçme yolları
  - Deneysel ölçüm: `clock()` ile süre ölçme, farklı $N$ değerleri için çalıştırma, log-log grafik ve regresyon.
  - Çalışma zamanını etkileyen etkenler: algoritma (sistemden bağımsız); donanım, yazılım, işletim sistemi (sisteme bağlı) (ekrandan, 01:10:00).
  - Matematiksel model: her temel işlemin maliyeti ile kaç kez yapıldığının çarpımlarının toplamı.
  - Basitleştirme: düşük dereceli terimleri ve sabitleri atmak (tilde gösterimi), yalnız en çok tekrarlanan işleme bakmak.
- Büyüme dereceleri
  - $1$, $\log N$, $N$, $N\log N$, $N^2$, $N^3$, $2^N$ sınıfları, tipik kod kalıpları ve $T(2N)/T(N)$ oranları (ekrandan, 01:25:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- "Ama çalışıyor" yeterli değildir
  - İlk hedef doğruluktur, ama profesyonel anlamda iyi bir algoritma zamanı ve yeri iyi kullanmalı, başkalarının anlayabileceği kadar basit ve her girdi için çalışacak kadar genel olmalıdır.
- Basitlik ve okunabilirlik
  - Bankalarda hâlâ çalışan eski COBOL programlarına, karmaşık oldukları için dokunulamaması örneği verildi. Kod, ekipte ya da sizden sonra çalışacak kişilerin anlayabileceği şekilde yazılmalıdır.
- Genellik
  - Sınavda örnek olarak verilen beş elemanlı diziye göre çözüm yazmak yanlıştır; çözüm problemin her olası girdisi için çalışmalıdır.
- Gömülü sistemlerde verimlilik
  - Donanım kaynaklarının bol olduğu dönemde verimlilik ihmal ediliyordu; akıllı telefonlar ve gömülü sistemler yaygınlaştıkça zaman ve yerin verimli kullanılması yeniden önem kazandı.
- Süre ölçmek genellenemez
  - Ölçülen süre donanıma, derleyiciye, dile ve işletim sistemine bağlıdır. Bu yüzden temel algoritmaların karmaşıklığı $N$'e bağlı olarak ve sabitler dikkate alınmadan verilmelidir.

## Kısa Tekrar Notları

- Algoritma: belirsizlik içermeyen, sonlu sürede biten, her geçerli girdi için doğru çıktı veren komutlar dizisi.
- İyi algoritma: doğru, verimli, basit, genel.
- Verimli algoritma: polinom zamanda çalışan algoritma (ekrandan, 00:35:00). $2^N$ karmaşıklıklı problemler polinom değildir.
- Daha iyi algoritma var mı? Karmaşıklığı bilinen alt sınırla karşılaştır. Örnek: $N^2$ sıralama yazdıysan $N\log N$ sıralama algoritmaları olduğu için seninki optimal değildir.
- Bir dizinin en küçük elemanını bulmak tek döngüyle, $N$ adımda yapılır.
- Deneysel analiz: log-log grafikte düz çizgi çıkarsa $T(N)=aN^b$ biçimindedir; eğim $b$ üsttür.
- Derste gösterilen örnekte $b=2.999$, $c=-33.2103$, $a=2^c\approx 1.006\times10^{-10}$ (ekrandan, 01:05:00).
- Çalışma zamanı = $\sum$ (işlem maliyeti × işlem sıklığı).
- Giriş/çıkış işlemleri çok yavaş olduğundan algoritmanın süresi ölçülürken dışarıda bırakılır.
- Tilde gösterimi: $\tfrac12 N(N-1)\sim\tfrac12N^2$; düşük dereceli terimler atılır.
- İç içe iki döngü $\to N^2$, üç döngü $\to N^3$, ikiye bölerek ilerleme $\to\log N$, böl ve yönet (mergesort) $\to N\log N$, tüm alt kümeler $\to 2^N$.
- Girdi iki katına çıkınca süre oranı: $N$ için 2, $N^2$ için 4, $N^3$ için 8.

## Detaylı Açıklamalar

- Veri yapısı ve algoritma ilişkisi
  - Bir harita uygulamasında iki semt arasındaki yolu bulmak için yerler çizgenin düğümleri, aralarındaki bağlantılar (mesafe, süre) kenarlar olarak tutulur; sonra uygun çizge algoritmasıyla en kısa yol bulunur. Önceden tasarlanmış bir çizge yapısı kullanmak, her şeyi sıfırdan matrislerle kurmaktan daha verimlidir.
  - Web sayfalarında ilerleyip geri dönmek için yığın uygundur: her yeni sayfaya geçerken önceki sayfa yığına konur, geri dönerken yığının tepesindeki adres alınır.
  - Önceki dönemde arama, sıralama algoritmaları ile yığın, kuyruk, ağaç, çizge gibi yapılar görülmüştü. Bu dönem bu algoritmaların analizi ve yeni tasarım yöntemleri (dinamik programlama, geri izleme, dal ve sınır) işlenecek.
  - Dinamik programlama: özyinelemeli tasarıma benzer bir yineleme bağıntısı kurar, ama daha önce hesaplanan sonuçları tekrar hesaplamak yerine saklayıp kullanır; böylece $2^N$ karmaşıklıklı bazı özyinelemeli çözümler çok daha hızlı hâle gelir.
  - Geri izleme: labirentte yol bulma ya da satranç tahtasına vezir yerleştirme gibi, çıkmaza girince bir adım geri dönüp başka seçenek deneyen arama.
- min-diff kodu (ekrandan, 00:40:00)
  - Kod, 64 kanalın üst ve alt sınırlarının farkını `ifcf_diff[i]` dizisine yazar. Sonra `cf_v` 0'dan 49'a kadar artarken her değer için 64 kanalı tarar; `-cf_v <= fark <= cf_v` sağlanan ilk kanalda bayrağı kurup döngülerden çıkar. Sonuçta `ifcf_val3`, mutlak değerce en küçük farkın bulunduğu kanalın indisidir.
  - Kod çalışır, ama iki sorunu vardır: anlaşılır değildir (mutlak değer yerine iki karşılaştırma, `break` ile çıkışlar) ve verimsizdir (en kötü durumda $64 + 50\times 64$ iç adım). En küçük farkı bulmak için tek bir 64'lük döngüde mutlak farkların en küçüğünü tutmak yeterlidir.
- Deneysel ölçüm ve log-log grafik
  - C'de `time.h` içindeki `clock()` ile algoritmanın başında ve sonunda zaman alınır; fark `CLOCKS_PER_SEC` makrosuna bölünerek saniyeye çevrilir. <!-- BELİRSİZ: clock() kodunun yer aldığı slayt karelerde yok; anlatım altyazıdan. -->
  - Tek bir ölçüm (örneğin "3 milisaniye") girdinin boyutu bilinmeden anlamsızdır. Bu yüzden farklı $N$ değerleri için ölçüm yapılır ve eğri uydurulur.
  - Log-log ölçekte $\lg T(N) = b\lg N + c$ düz çizgisi elde edilir; buradan $T(N)=aN^b$, $a=2^c$ olur. Derste $b=2.999$, $c=-33.2103$ (ekrandan, 01:05:00). Bu modelle $N=8000$ için yaklaşık 51 saniye, $N=16000$ için yaklaşık 400 saniye tahmin edilir (python ile kontrol: 51.0 s ve 408.1 s).
  - Derin öğrenme makalelerinde eğitim süresinin belirli bir donanımda kaç gün sürdüğünün yazılması, aynı donanım olmadan bu sürenin yorumlanamaması örneği verildi.
- Matematiksel model
  - Knuth'un yaklaşımı: toplam süre, her işlemin maliyeti ile sıklığının çarpımlarının toplamıdır. Maliyetler makineye ve derleyiciye bağlıdır (değişken tanımı $c_1$, atama $c_2$, tam sayı karşılaştırma $c_3$, dizi elemanına erişim $c_4$, dizi uzunluğu $c_5$, 1B dizi oluşturma $c_6N$, 2B dizi oluşturma $c_7N^2$) (ekrandan, 01:15:00).
  - Dizideki sıfırları sayan tek döngülü örnekte: 2 değişken tanımı, 2 atama, $N+1$ "küçüktür" karşılaştırması, $N$ eşitlik karşılaştırması, $N$ dizi erişimi, $N$ ile $2N$ arası artırma (derste sözlü, 01:16:05).
  - Toplamı sıfır olan çiftleri sayan iç içe döngülü örnekte (`a[i] + a[j] == 0`, $j>i$) eşitlik karşılaştırması $\sum_{i=0}^{N-1}(N-1-i)=\tfrac12N(N-1)$ kez yapılır.
- Basitleştirme (ekrandan, 01:20:00)
  - Çalışma süresi girdi boyutu $N$'in fonksiyonu olarak tahmin edilir; düşük dereceli terimler atılır, çünkü $N$ büyükken önemsizdir, $N$ küçükken de zaten önemli değildir.
  - Çift sayma örneği için sıklık tablosu: değişken tanımı $N+2\sim N$; atama $N+2\sim N$; küçüktür karşılaştırması $\tfrac12(N+1)(N+2)\sim\tfrac12N^2$; eşitlik karşılaştırması $\tfrac12N(N-1)\sim\tfrac12N^2$; dizi erişimi $N(N-1)\sim N^2$; artırma $\tfrac12N(N-1)$ ile $N(N-1)$ arası.
  - Bir adım daha: sabitler de atılır ve yalnız en içteki döngüde yapılan temel işlemin kaç kez yapıldığına bakılır. Böylece sonuç donanım ve derleyiciden bağımsız olur.
- Büyüme dereceleri (ekrandan, 01:25:00)
  - Sabit ($1$): `a = b + c;` gibi tek ifadeler, iki sayıyı toplama; $T(2N)/T(N)=1$.
  - Logaritmik ($\log N$): `while (N > 1) { N = N / 2; ... }`, ikili arama; oran $\sim1$.
  - Doğrusal ($N$): tek döngü, en büyüğü bulma; oran 2.
  - Doğrusal-logaritmik ($N\log N$): böl ve yönet, mergesort; oran $\sim2$.
  - Karesel ($N^2$): iç içe iki döngü, tüm çiftleri denetleme; oran 4.
  - Kübik ($N^3$): iç içe üç döngü, tüm üçlüleri denetleme; oran 8.
  - Üstel ($2^N$): kapsamlı arama, tüm alt kümeleri denetleme; oran $T(N)$.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
