# Ders 7 Çalışma Özeti

## Genel Konular

- Temel veri yapılarına ek: kuyruk ve hash tablosu (ekrandan, 00:20:00 ve 00:25:00)
  - Kuyrukta ekleme arka uçtan (enqueue), çıkarma ön uçtan (dequeue) yapılır. İşletim sistemlerinde süreç yönetiminde ve Gantt diyagramında işlerin sıraya konmasında, graf algoritmalarında kullanılır.
  - $n$ elemanlı sırasız bir dizide ya da bağlı listede, kesinlikle var olan bir eleman en fazla $n$ adımda bulunur. Sıralı dizide ikili arama (binary search) $\log n$ adımda, sıralı ve düzgün (uniform) dağılımlı dizide interpolasyon araması $\log\log n$ adımda bulur.
  - $n=256$ için: doğrusal arama 256, ikili arama $\log_2 256=8$, interpolasyon araması $\log_2 8=3$ adım (ekrandan, 00:20:00).
  - Hash tablosunda veri önce bir $f$ fonksiyonundan (hash fonksiyonu) geçirilir, çıkan değer indeks olarak kullanılır ve veri o indekse yazılır. Ararken aynı fonksiyonla indeks yeniden hesaplanır; ideal durumda eleman tek denemede bulunur.
  - En basit hash fonksiyonu mod alma işlemidir: 10 gözlü tabloda $\text{indeks}=\text{veri} \bmod 10$. 13 → 3, 22 → 2, 48 → 8. 13 ile 33 aynı indekse düşer (çakışma); çakışma çözümleri veri yapıları ve algoritma analizi derslerinde görülür.
- Hash fonksiyonları ve parola saklama
  - Web sitelerinde parolalar açık metin olarak saklanmamalıdır; ya şifreleme ya da hash fonksiyonu (MD5, SHA-256 gibi) kullanılır.
  - Hash fonksiyonunun tersi alınamaz ya da tersini bulmak kabul edilebilir sürede mümkün değildir. Bu yüzden "şifremi unuttum" denince eski parola gönderilmez, yeni parola tanımlanır. Parola düz metin olarak geri gönderiliyorsa site güvenli değildir.
  - Girişte, yazılan parola aynı fonksiyondan geçirilir ve kayıtlı hash değeriyle karşılaştırılır.
  - Ayrık matematik bağlantısı: iki farklı girdinin aynı değere gitmemesi istenir, yani fonksiyonun birebir olması beklenir.
- Algoritma analizi ve ölçütler
  - Aynı problem için birçok algoritma yazılabilir; karşılaştırmada "trade-off" vardır: bir şeyden kazanırken başka bir şeyden kaybedilir.
  - Ölçütler: doğruluk (özellikle optimizasyon algoritmalarında), zaman verimliliği, bellek verimliliği ve bunları birleştiren en iyi (optimal) çözüm.
  - Optimizasyon örneği: görüntüde kontrast iyileştirme için piksellere $a$, $b$, $c$ parametreli bir dönüşüm uygulanır; parametreler parçacık sürü optimizasyonu (PSO) ve yapay arı kolonisi (ABC) ile aranır (ekrandan, 00:35:00). Bir algoritmanın bir görüntüde daha iyi çıkması her görüntüde daha iyi olduğu anlamına gelmez.
- Kaba (deneysel) analiz ve teorik analiz (ekrandan, 00:45:00 ve 00:50:00)
  - Kaba analiz: bir giriş verisi seçilir, zaman birimi (milisaniye) ya da yürütülen temel işlem sayısı ölçülür (başa ve sona zamanlayıcı ya da döngüye sayaç), çok kez çalıştırılıp ortalama, standart sapma, min, max ve medyan raporlanır.
  - Teorik analiz: zaman verimliliği, girdi boyutunun bir fonksiyonu olarak temel işlemin tekrar sayısı belirlenerek analiz edilir. Bellek verimliliği de aynı yolla incelenir.
  - Temel işlem (basic operation): algoritmanın çalışma süresini en çok etkileyen, her adımda kesin yapılan işlemdir. Sıralamada ve en küçük/en büyük bulmada temel işlem karşılaştırmadır; takas ya da atama yalnız koşul doğruysa yapıldığı için temel işlem sayılmaz.
- Problemler ve temel işlemleri (ekrandan, 00:55:00)

  | Problem | Giriş verisinin büyüklüğü | Temel işlem |
  |---|---|---|
  | $n$ elemanlı dizide eleman arama | Dizinin eleman sayısı $n$ | Elemanları karşılaştırma |
  | İki matrisin çarpımı | Matris boyutu ya da toplam eleman sayısı | İki sayının çarpımı |
  | Bir tamsayının asal olup olmadığının kontrolü | $N$ sayısının dijit sayısı (ikili gösterim) | Bölme |
  | Graf problemi | Düğüm / kenar sayısı | Düğüm ve kenarların gezilmesi |

- Temel kavramlar (ekrandan, 01:00:00 ve 01:15:00)
  - Yürütme zamanı $T(n)$: algoritmanın işini yapması için kabul edilen temel işlemlerden kaç adet yürütülmesi gerektiğini gösteren matematiksel ifade. Hangi işleme göre hesaplandığı belirtilmelidir.
  - Alan maliyeti $S(n)$: program kodu, veri yapısı alanları ve yığın (stack/heap) bellek. Algoritma rekürsif değilse ve veri yapısı çok büyük değilse genellikle hesaplanmaz; rekürsif algoritmalar hızdan kazandırıp bellekten kaybettiği için orada önemlidir.
  - Asimptotik ifade: bir problemin büyümesinin üst, alt ve ortalama sınırını belirleyen ifade. Beş notasyon: Big O ($O$), Big Omega ($\Omega$), Big Theta ($\Theta$), little o ($o$), little omega ($\omega$).
  - Alan karmaşıklığı ve zaman karmaşıklığı, $n$'nin büyük değerleri için bellek ve sürenin nasıl arttığını gösteren asimptotik ifadelerdir.
- Koddan $T(n)$ çıkarma örnekleri
  - Ortalama bulma (BulOrta): $T(n)=1+2n+2+2n+2+1=4n+6$ (ekrandan, 01:20:00).
  - En küçük elemanı bulma: karşılaştırma $n-1$ kez yapılır; atama en kötü durumda her adımda yapılır kabul edilir; toplam yaklaşık $4n$. <!-- BELİRSİZ: Kod slaytının karesi yok; sabit terim altyazıdan kesin çıkmıyor. -->
  - Seçmeli sıralama (selection sort): $T(n)=2n^2+6n+5$ (ekrandan, 01:30:00).
  - Matris toplamı ($n\times m$): $4mn+4n+2$, $m=n$ kabulüyle $4n^2+4n+2$. <!-- BELİRSİZ: Kod slaytının karesi yok; değerler altyazıdan ve python kontrolünden. -->
- Fonksiyonların büyüme hızı (ekrandan, 01:40:00 ve 02:20:00)
  - Sabit $O(1)$, logaritmik $O(\log n)$, doğrusal $O(n)$, doğrusal çarpanlı logaritmik (linearitmik) $O(n\log n)$, karesel $O(n^2)$, kübik $O(n^3)$, üstel $O(2^n)$, faktöriyel $O(n!)$.
  - Örnekler: bağlı listenin başına ekleme $O(1)$; ikili arama ağacında arama $O(\log n)$; sırasız dizide arama $O(n)$; merge sort, quick sort, heap sort $O(n\log n)$; bubble sort $O(n^2)$; Hanoi kuleleri $O(2^n)$.
  - Polinom ile üsteli karıştırmamak gerekir: polinomda $n$ tabandadır ($n^2$, $n^3$), üstelde üstte ($2^n$).
- Analiz türleri
  - En kötü durum (worst case): üst sınır; algoritmanın bundan uzun sürmeyeceği garantisi. Sıralamada ters sıralı dizi en kötü durumu verir.
  - En iyi durum (best case): alt sınır. Aramada ilk denemede bulmak ($1$), kabarcık sıralamada sıralı dizi ($n$).
  - Ortalama durum (average case): rastgele girdilerle gerçek ortalama; analitik olarak zordur. Sıralı aramada ortalama $\frac{n+1}{2}$ çıkar ve bu da $O(n)$'dir.
- Asimptotik notasyonlar
  - Big O (üst sınır): $x>k$ olduğunda $|f(x)|\le C|g(x)|$ sağlayan $C$ ve $k$ sabitleri varsa $f(x)=O(g(x))$ (ekrandan, 02:10:00).
  - Big Omega (alt sınır): $x>k$ için $|f(x)|\ge C|g(x)|$. $f(x)=\Omega(g(x))$ ancak ve ancak $g(x)=O(f(x))$.
  - Big Theta (alt ve üst sınır): $x>k$ için $C_1|g(x)|\le|f(x)|\le C_2|g(x)|$; yani hem $O$ hem $\Omega$ (ekrandan, 02:30:00). $f=\Theta(g)$ ancak ve ancak $f=O(g)$ ve $g=O(f)$.
  - Limit yöntemi: $\lim_{n\to\infty}\frac{T(n)}{g(n)}$ sıfırsa $T$ daha yavaş büyür ($O$); pozitif sabitse aynı hızda büyür ($\Theta$); sonsuzsa $T$ daha hızlı büyür ($\Omega$). Belirsizlikte türev (L'Hospital) alınır.
  - Tümevarım yöntemi: türev almak zor olduğunda kullanılır (örnek: $n>6$ için $3n<n!$).
  - Alt programlardan oluşan algoritmada en büyük mertebe alınır: $\max(O(n^c),O(n^d))=O(n^d)$, $1<c<d$ (ekrandan, 02:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Temel işlemi doğru belirlemek
  - Analize başlamadan önce temel işlem seçilir. Her adımda kesin yapılan işlem (karşılaştırma) temel işlemdir; koşula bağlı takas ya da atama değildir. Ekrana yazma gibi işler problemin temel işlemi değilse analize katılmaz.
- Koddan $T(n)$, $T(n)$'den Big O
  - Verilen iteratif bir kod parçasında her satırın kaç kez çalıştığını sayıp $T(n)$'yi bulmak, sonra onu Big O cinsinden yazmak beklenen beceridir. Döngü sınırlarına dikkat edilmelidir: döngü her zaman $0$'dan $n$'e değil, örneğin $\log n$'e kadar da gidebilir.
  - Değişken tanımlamaları sayılmaz; atama (makinede MOVE), karşılaştırma (CMP), artırma (INC) ve aritmetik işlemler sayılır. `return` satırı algoritmayla değil programlamayla ilgili olduğu için sayılmaması önerildi; bazı kitaplar onu da sayar.
- Big O ile Big Theta aynı şey değildir
  - Bazı kaynaklarda aynı gibi kullanılır, bu hatadır. $x^2=O(x^3)$ doğrudur ama $x^2=\Theta(x^3)$ değildir.
  - Big O verirken en yakın üst sınır yazılmalıdır. $n^2$ büyüyen bir algoritmaya $O(n^3)$ ya da $O(2^n)$ demek yanlış değildir ama "fazla mütevazı" olur; $O(n\log n)$ demek ise tanıma aykırıdır, çünkü uygun bir $C$ bulunamaz.
- Küçük $n$ için karar vermemek
  - İki fonksiyon küçük $n$ değerlerinde ters sıralı görünebilir; karşılaştırma $n\to\infty$ için yapılır. Grafiğin yalnız bir kısmına bakmak yanıltır, tam fonksiyona bakmak gerekir.
- Kavramları karıştırmamak
  - Soru çözerken kavramlar doğru yerde kullanılmalıdır; polinom ve üstel karmaşıklık sık karıştırılır.

## Kısa Tekrar Notları

- Hash tablosu: indeks $=f(\text{veri})$; ideal arama 1 adım. Mod 10 örneğinde 13 ve 33 çakışır.
- Parolalar hash ile saklanır; hash geri döndürülemez, bu yüzden unutulan parola sıfırlanır.
- Ölçütler: doğruluk, zaman, bellek, optimal çözüm. Zaman ile bellek arasında trade-off vardır.
- Kaba analiz: zamanlayıcı/sayaç, istatistik. Teorik analiz: temel işlemin tekrar sayısı $T(n)$.
- Sıralamada temel işlem karşılaştırmadır.
- BulOrta: $4n+6$. Selection sort: $2n^2+6n+5$. Matris toplamı ($m=n$): $4n^2+4n+2$.
- Büyüme sırası: $1<\log n<n<n\log n<n^2<n^3<2^n<n!$.
- Worst case üst sınır, best case alt sınır, average case gerçek ortalama.
- $O$: $|f|\le C|g|$; $\Omega$: $|f|\ge C|g|$; $\Theta$: ikisi birden. $x>k$ için en az bir $C$ (ve $k$) bulunması yeter.
- $x^2+2x+1=O(x^2)$: $C=4$, $k=1$ ya da $C=3$, $k=2$.
- Limit 0 → $O$, sabit → $\Theta$, sonsuz → $\Omega$.
- Birden çok alt programda en büyük mertebe alınır.

## Detaylı Açıklamalar

- Hash tablosunun mantığı
  - Dizide ya da bağlı listede arama $n$ adım sürebilir. Sıralı dizide ikili arama aralığı her adımda yarıya indirir (100 sayfalık kitapta önce 50. sayfaya, sonra 25'e gitmek gibi). İnterpolasyon araması ise aranan değerin tahmini konumuna gider; bunun için dizinin sıralı ve düzgün dağılımlı olması gerekir. Böyle bir düzen yoksa hash tablosu kullanılır.
  - Hash tablosunda saklanacak veri (tamsayı, karakter ya da bir yapı) bir fonksiyondan geçirilir. Çıkan değer tablonun indeksidir. Arama sırasında aynı fonksiyon indeksi yeniden verir ve veri tek denemede bulunur. Bu yüzden fonksiyonun iyi seçilmesi önemlidir. Mod alma en basit yoldur ama aynı kalanı veren veriler çakışır.
- Parola saklama örneği
  - Kullanıcı parolası hash fonksiyonundan geçirilip saklanır. Girişte yazılan parola yine aynı fonksiyondan geçirilir ve sonuçlar karşılaştırılır; eşitse giriş yapılır. Bu sırada hiçbir geri döndürme yapılmaz. Hocanın sezgi için verdiği örnek: $x^2$ ile kodlama yapılırsa $1$ ile $-1$ aynı sonucu verir ve tersten hangisinin girildiği bilinemez.
- Algoritmaların karşılaştırılması
  - Optimizasyon problemlerinde arama uzayı, dağları ve ovaları olan uçsuz bucaksız bir araziye benzetildi: iki boyut konumu, üçüncü boyut yüksekliği verir; en derin ya da en yüksek nokta aranır. Algoritma doğru noktaya ne kadar sürede ve ne kadar bellekle ulaştığına göre değerlendirilir. Çok hızlı ama elde edilemeyecek kadar bellek isteyen bir algoritma gerçekleştirilemez.
  - Trade-off örneği: zamanı $n^3$, belleği $n$ olan A algoritması ile zamanı $n^2$, belleği $n^4$ olan B algoritması. Bellek bolsa B, bellek kısıtlı ve süre önemsizse A seçilir. İstanbul'dan Ankara'ya yürüyerek, trenle ya da uçakla gitmek arasındaki seçim gibi.
  - Küçük $n$ tuzağı: $n^3$ ile $n^2+n+5$ karşılaştırıldığında $n=1$ için $1<7$, $n=2$ için $8<11$, ama $n=3$ için $27>17$ olur ve sonra fark açılır.
- Seçmeli sıralamanın $T(n)$ tablosu (ekrandan, 01:30:00)
  - Kod satırları I-VII diye numaralanır ve her biri için işlem sayısı ile tekrar sayısı yazılır: I (dış `for`) $2n+1$; II (`min=i`) $n$; III (iç `for`) $n+2\frac{n(n+1)}{2}$; IV (karşılaştırma) $\frac{n(n+1)}{2}$; V (`min=j`, en kötü durum) $\frac{n(n+1)}{2}$; VI (takas) 3; VII (`return`) 1.
  - Toplam: $4\frac{n(n+1)}{2}+4n+5=2n^2+6n+5$.
  - Kısa yol: iç içe döngüde iç döngü $n-i+1$ kez döner; $\sum_{i=0}^{n-1}(n-i+1)$ toplamı $n^2$ mertebesindedir. İki iç içe döngü genelde $n^2$ verir.
- Big O ispatı
  - $n^2+5$ için: her terim $n^2$ gibi düşünülürse $n^2+5\le 6n^2$ olur; $C=6$ ile $O(n^2)$. Aynı fonksiyon $C=6$ ile $O(n^3)$ de olur ($n=1$: $6\le6$, $n=2$: $9\le48$), ama bu gereksiz geniş bir sınırdır.
  - $n^2+5n$ için $O(\log n)$ denemesi: $n=1$'de sol taraf 6, $\log 1=0$; hiçbir $C$ eşitsizliği sağlamaz, dolayısıyla $O(\log n)$ değildir.
- Tümevarımla $3n<n!$ ($n>6$) (ekrandan, 02:45:00)
  - Temel adım: $n=7$ için $21<5040$.
  - Varsayım: $3k<k!$.
  - Adım: $3(k+1)=3k+3<(k+1)k!=k\cdot k!+k!$. $3k<k!$ varsayımdan, $3<k\cdot k!$ ise $k>6$ için açıkça doğrudur. Sonuç: $3n<n!$, yani $3n=O(n!)$.
- Üstel algoritma örneği
  - Doğruluk tablosu oluşturma ve parola deneme üstel algoritmalardır. 29 harfli alfabeyle 6 haneli bütün parolaları denemek $29^6=594\,823\,321$ deneme ister; hane sayısı $n$ ise $29^n$, yani üstel.
- Ders sonrası notlar
  - Hoca sıralı dizide aramanın "$n\log n$'e" düştüğünü söyledi; doğrusu ikili aramada $\log n$ adımdır (aynı derste $256$ eleman için $8$ adım diye de hesaplandı).
  - Hoca Hanoi kulelerinde 3 disk için 8, 4 disk için 16, 10 disk için 1024 hamle dedi; en az hamle sayısı $2^n-1$'dir: 7, 15 ve 1023. Mertebe yine $O(2^n)$'dir.
  - Hoca hash fonksiyonunun birebir olması gerektiğini söyledi. Büyük olasılıkla daha doğru ifade şudur: MD5, SHA-256 gibi fonksiyonlar sınırsız sayıda girdiyi sabit uzunlukta çıktıya götürdüğü için birebir olamaz; çakışmalar vardır ama iyi bir hash fonksiyonunda bulunmaları pratikte çok zordur. MD5'te çakışma bulunabildiği için parola saklamada artık güvenli sayılmaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
