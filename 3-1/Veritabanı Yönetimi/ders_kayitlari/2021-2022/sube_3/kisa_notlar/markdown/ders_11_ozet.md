# Ders 11 Çalışma Özeti

## Genel Konular

- İndekslemenin yeri ve kaynak
  - Derste ders kitabının (Database System Concepts, 7. baskı, Silberschatz, Korth ve Sudarshan) 14. bölümü (İndeksleme) işlendi (ekrandan, 00:05:00).
  - Önceki derste dosya organizasyonları (heap file, sequential file, clustered file) görülmüştü. Bunların ötesinde disk esaslı özel veri yapıları vardır: ağaç yapıları (B+ ağacı) ve hash yapıları (statik, extendable ve linear hash).
  - View, fonksiyon, trigger gibi yapılar kullanıcıya yakın, mantıksal yapılardır; bunlar olmadan da veritabanı çalışabilir. İndeks yapıları ise sistemin fiziksel çekirdeğidir ve hızlı, çevrimiçi çalışmanın olmazsa olmazıdır.
- Temel kavramlar (ekrandan, 00:05:00)
  - Arama anahtarı (search key): bir dosyada kayıt aramak için kullanılan nitelik ya da nitelik kümesi.
  - İndeks dosyası, `(search-key, pointer)` biçimindeki indeks kayıtlarından (index entries) oluşur. İndeks dosyaları genelde asıl dosyadan çok daha küçüktür.
  - İki temel indeks türü: sıralı indeksler (anahtarlar sıralı tutulur) ve hash indeksler (anahtarlar bir hash fonksiyonuyla "bucket"lara dağıtılır).
  - Örnek sorgu: `SELECT salary FROM instructor WHERE name = 'Califieri'`. Burada arama anahtarı `name`'dir, `salary` değildir; indeks `name` üzerinde olursa kayda hızlı erişilir, sonra kaydın istenen niteliği okunur.
- İndeksin faydasını belirleyen etkenler
  - Dosya büyüdükçe indeksin katkısı artar; çok küçük bir dosyada indeksin bir anlamı yoktur, hatta zararlı olabilir.
  - Seçicilik (selectivity): aranan değer sütunda çok sık geçiyorsa indeksin faydası azalır, çünkü sıralı tarama zaten çok sayıda eşleşme yakalar ve indeks üzerinden dağınık kayıtlara gitmek pahalılaşır.
- İndeksin dezavantajları
  - Yer kaplar: indeks yalnız bir nitelik ve bir pointer sakladığı için, 10 nitelikli bir şemada dosyanın yaklaşık onda biri kadardır.
  - Veri tekrarı: arama anahtarı hem dosyada hem indekste bulunur. Ekleme, silme ve güncellemede indeks de güncellenmelidir; aksi halde tutarlılık bozulur.
  - İndeksin kullanılıp kullanılmayacağına sorgu planlayıcısı (optimizer) bu tür ölçütlere göre karar verir.
- Dense ve sparse indeks
  - Dense indeks: dosyadaki her arama anahtarı değeri için bir indeks kaydı vardır. Örnek: instructor tablosunun ID niteliği üzerinde indeks (ekrandan, 00:10:00).
  - Sparse indeks: yalnız bazı anahtar değerleri için indeks kaydı vardır. Yalnız dosya arama anahtarına göre sıralıysa uygulanabilir (ekrandan, 00:20:00).
  - Sparse indekste K anahtarlı kaydı bulmak için K'dan küçük en büyük indeks değeri bulunur, o kaydın gösterdiği yerden dosya sırayla taranır. Örnek: ID'si 20000 olan kayıt aranırken indekste 10101 ile 32343 arasında olduğu anlaşılır ve 10101'in gösterdiği yerden taranır.
  - Sparse indeks daha az yer kaplar ama daha az hizmet verir: lookup sorgularında (örneğin eklenen kaydın birincil anahtarının tabloda olup olmadığını denetlemek) dense indekste iş indeks içinde biter (index-only evaluation), sparse indekste dosyaya gitmek gerekir.
- Primary (clustering) ve secondary indeks
  - Primary indeks: dosya, indeksin arama anahtarına göre sıralıdır. Şekilde indeksten dosyaya giden oklar paraleldir.
  - Secondary indeks: dosya bu anahtara göre sıralı değildir; oklar dosyanın farklı yerlerine dağılır. Örnek: instructor tablosunun salary niteliği üzerinde secondary indeks (ekrandan, 00:25:00).
  - Secondary indeks dense olmak zorundadır. Primary indeks hem dense hem sparse olabilir.
- İndeksle erişimin maliyeti (sayısal örnek)
  - 12 kayıtlık instructor dosyasında bir disk sayfası 2 kayıt, salary indeksinde bir sayfa 6 indeks kaydı alsın. Maaşı 72000 olan kayıt sıralı aramayla 5. disk erişiminde bulunur; indeks üzerinden ikili arama ile 1 indeks sayfası ve 1 veri sayfası, toplam 2 erişim yeterlidir.
  - Gerçek boyutlarda (örneğin 5000 sayfa) sıralı arama ortalama 2500 sayfa okur, indeksle 5-10 erişim yeterli olur.
- Çok seviyeli (multi-level) indeks
  - İndeks ana belleğe sığmazsa indeksin üzerine de indeks kurulur. İç indeks (inner index) veri dosyasının ilk indeksidir, dış indeks (outer index) iç indeks üzerine kurulur.
  - İç indeks sıralı olduğu için dış indeks her zaman primary ve sparse olabilir. B+ ağacı da bir çok seviyeli indekstir.
- Kompozit (çok nitelikli) arama anahtarı (ekrandan, 00:35:00)
  - Örnek: instructor üzerinde `(name, ID)` indeksi. Değerler sözlük sırasıyla (lexicographic) sıralanır: önce ilk niteliğe, ilk nitelik eşitse ikinciye göre.
  - $(John, 12121) < (John, 13514) < (Peter, 11223)$.
  - Bu indeks `name` ve `(name, ID)` aramalarında faydalıdır; yalnız `name` aramasında tekli bir indekse göre biraz daha az faydalıdır (indeks daha büyüktür). Yalnız `ID` üzerinden aramada fayda sağlamaz, çünkü kayıtlar bütünüyle ID'ye göre sıralı değildir.
- B+ ağacının yapısı (ekrandan, 00:40:00)
  - Kök (root), iç düğümler (internal nodes) ve yapraklardan (leaf nodes) oluşur. Sıralı bir indekstir: yapraklar anahtar sırasıyla dizilir.
  - instructor dosyasının `name` niteliği üzerindeki örnekte dosya `name`'e göre sıralı değildir; bu yüzden yaprak seviyesi secondary ve dense bir indekstir. Yaprakların üzerindeki seviyeler ise sıralı bir dosya üzerine kurulduğu için primary ve sparse indeks gibidir.
  - Her düğüm genellikle bir disk sayfasına karşılık gelir; düğüme sığan anahtar ve pointer sayısı sayfa büyüklüğüne göre belirlenir.
- B+ ağacının kuralları (ekrandan, 00:45:00)
  - Kökten her yaprağa giden bütün yollar aynı uzunluktadır (dengeli ağaç). Bu, en kötü durumu iyileştirir.
  - Kök ya da yaprak olmayan her düğümün $\lceil n/2 \rceil$ ile $n$ arasında çocuğu vardır.
  - Bir yaprak düğümde $\lceil (n-1)/2 \rceil$ ile $n-1$ arasında değer vardır.
  - Özel durumlar: kök yaprak değilse en az 2 çocuğu vardır; kök yapraksa (ağaçta başka düğüm yoksa) 0 ile $n-1$ arasında değeri olabilir.
- Düğüm yapısı (ekrandan, 00:50:00)
  - Tipik düğüm: $P_1, K_1, P_2, \ldots, P_{n-1}, K_{n-1}, P_n$. $K_i$ arama anahtarı değerleri, $P_i$ ise iç düğümlerde çocuklara, yapraklarda kayıtlara (ya da kayıt bucket'larına) pointer'dır.
  - Bir düğümdeki anahtarlar sıralıdır: $K_1 < K_2 < \ldots < K_{n-1}$. Başlangıçta tekrarlı anahtar olmadığı varsayılır.
  - Yaprakta $P_i$, $K_i$ anahtarlı kayda gider; $P_n$ bir sonraki yaprağa gider (ekrandan, 00:55:00).
  - İç düğümde $P_1$, $K_1$'den küçük anahtarların alt ağacına; $P_i$, $K_{i-1}$'e büyük eşit ve $K_i$'den küçük anahtarların alt ağacına; $P_n$, $K_{n-1}$'e büyük eşit anahtarların alt ağacına gider. Eşitliğin hangi tarafa konacağı gerçeklemeye göre değişebilir.
- $n = 6$ örneği (ekrandan, 01:00:00)
  - Yapraklarda 3 ile 5 arasında değer, kök dışındaki iç düğümlerde 3 ile 6 arasında çocuk olmalıdır; kökün en az 2 çocuğu olmalıdır.
  - Örnek ağaç: kök `El Said | Mozart`; yapraklar `Brandt, Califieri, Crick, Einstein`, `El Said, Gold, Katz, Kim`, `Mozart, Singh, Srinivasan, Wu`.
- B+ ağacının yüksekliği (ekrandan, 01:25:00)
  - Kökün altındaki seviyede en az $2\lceil n/2 \rceil$, bir sonrakinde en az $2\lceil n/2 \rceil \lceil n/2 \rceil$ değer vardır.
  - Dosyada K arama anahtarı değeri varsa yükseklik en fazla $\lceil \log_{\lceil n/2 \rceil}(K) \rceil$ olur. İkili aramada her adımda liste ikiye bölünür, B+ ağacında en az $\lceil n/2 \rceil$'ye bölünür.
- B+ ağacında sorgu (ekrandan, 01:30:00)
  - `find(v)`: köke başla; yaprağa gelene kadar düğümde $v \le K_i$ olan en küçük $i$'yi bul. Yoksa son pointer'a, $v = K_i$ ise $P_{i+1}$'e, değilse $P_i$'ye in. Yaprakta $K_i = v$ varsa $P_i$ döndür, yoksa kayıt yoktur.
  - Örnek: Crick aranırken kökte `Crick < Mozart` olduğu için sola, iç düğümde ilk büyük eşit anahtar Einstein olduğu ve eşit olmadığı için onun soluna inilir; yaprakta Crick bulunur. Kök, iç düğüm, yaprak ve veri sayfası olmak üzere 4 disk erişimi yeter.
  - Aralık sorgusu (range query): örneğin Crick ile Mozart arasındaki hocalar. Aralığın alt ucunun yaprağına inilir, sonra yapraklar arası pointer'larla sağa doğru ilerlenir; üst seviyelere geri çıkmak gerekmez.
- Sayısal performans örneği (ekrandan, 01:40:00)
  - Düğüm bir disk bloğu büyüklüğündedir (tipik 4 KB); indeks kaydı 40 bayt ise $n \approx 100$ olur.
  - 1 milyon anahtar ve $n = 100$ için kökten yaprağa en çok $\lceil \log_{50}(1\,000\,000) \rceil = 4$ düğüm erişilir. Kök ve köke yakın seviyeler çoğunlukla ana bellekte tutulduğu için pratikte 1-2 disk erişimi yeter.
  - Dengeli bir ikili ağaçta ise yaklaşık $\log_2(10^6) \approx 20$ düğüm erişilir; her erişim bir disk I/O'su olabileceği için fark büyüktür.
- B+ ağacına ekleme (ekrandan, 01:45:00 ve 01:50:00)
  - Önce aramayla kaydın girmesi gereken yaprak bulunur. Yer varsa eklenir. Yer yoksa düğüm ortadan bölünür (split): soldaki anahtarlar yerinde kalır, sağdakiler yeni düğüme taşınır.
  - İki yeni düğümü ayırmak için sağ düğümün en küçük anahtarı üst seviyeye eklenir. Üst seviyede de yer yoksa o da bölünür ve bölünme yukarı doğru yayılır. Kök bölünürse iki çocuklu yeni bir kök oluşur ve ağaç bir seviye uzar; ağaç yapraklardan köke doğru büyür.
  - "Adams" eklenmesi ($n = 4$, yaprakta en çok 3 değer): `Brandt, Califieri, Crick` yaprağı doludur; `Adams, Brandt` ve `Califieri, Crick` olarak bölünür, Califieri üst düğüme eklenir.
  - "Lamport" eklenmesi: `Gold, Katz, Kim` yaprağı `Gold, Katz` ve `Kim, Lamport` olarak bölünür, Kim üste taşınır. Ekrandaki şekilde dolu olan iç düğüm de bölünür ve Gold köke çıkar.
  - Ekleme yalnız kökten yaprağa giden yol üzerindeki düğümleri etkiler; maliyet ağacın yüksekliği kadardır (logaritmik). Sıralı bir dosyaya eklemede ise çok sayıda kaydı kaydırmak gerekir. Asıl dosya çoğu zaman heap file olarak kalabilir.
- Silme ve hash yapıları
  - Silmede düğümler birleştirilir (merge) ve ağaç kısalabilir. Karmaşık ve maliyetli olduğu için gerçek sistemlerde çoğu zaman yapılmaz; yapı olduğu gibi bırakılır ve sonra gelen kayıtlar boş yerlere eklenir.
  - Hash yapıları kayıtları bir fonksiyonla bucket'lara dağıtır. Statik hash kayıt sayısı önceden bilinmediği için yetersiz kalır; extendable hash ve linear hash, B+ ağacı gibi büyüyüp küçülebilen uyarlamalı yapılardır (ayrıntısına girilmedi).

## Hocanın Özellikle Vurguladığı Kısımlar

- İndeks hızlandırır ama masum değildir
  - Yer kaplar ve veri tekrarına yol açar; her güncellemede indeksin de güncellenmesi gerekir. Küçük dosyada ya da seçiciliği düşük değerlerde faydası azalır.
- Secondary indeks dense olmak zorundadır
  - Dosya bu anahtara göre sıralı olmadığından bütün değerler indekste bulunmalıdır. Sparse indeks yalnız sıralı dosyada, yani primary indekste mümkündür.
- Paralel oklar kuralı
  - İndeksten dosyaya giden oklar paralelse primary, dağınıksa secondary indekstir. B+ ağacı şeklinde yaprakların paralel görünmesi aldatmasın; dosyada dağınık yerlere gider.
- B+ ağacının en önemli özelliği dengeli olmasıdır
  - Bütün yollar aynı uzunluktadır, arama, ekleme ve silme maliyeti ağacın yüksekliği kadardır. Gerçek sistemlerde $n$ yüzler mertebesinde olduğundan yükseklik 2-4 gibi küçük kalır.
- Kökün en az iki çocuğu olması kuralının sebebi
  - Yeni seviye yalnız kökün ikiye bölünmesiyle ortaya çıkar; bu yüzden yaprak olmayan kökün en az iki çocuğu vardır.
- Yaprak ve iç düğüm kısıtlarının farkı
  - Yapraklarda son pointer bir sonraki yaprağa gittiği için kısıt değer sayısına göre, iç düğümlerde bütün pointer'lar çocuklara gittiği için kısıt pointer sayısına göredir.

## Kısa Tekrar Notları

- İndeks kaydı = (arama anahtarı, pointer). İndeks dosyası asıl dosyadan çok daha küçüktür.
- İndeksin faydası dosya büyüklüğüyle artar, seçicilik düştükçe azalır.
- Dezavantajlar: yer ve güncelleme maliyeti (tutarlılık).
- Dense: her değer indekste. Sparse: bazı değerler; dosya sıralı olmalı.
- Primary (clustering): dosya anahtara göre sıralı; dense ya da sparse olabilir. Secondary: dosya sıralı değil; dense olmak zorunda.
- Çok seviyeli indeks: indeksin üzerine sparse dış indeks.
- Kompozit anahtar sözlük sırasıyla sıralanır; ilk nitelikle ya da tamamıyla aramaya yarar, yalnız ikinci nitelikle aramaya yaramaz.
- B+ ağacı: dengeli; iç düğüm $\lceil n/2 \rceil$..$n$ çocuk; yaprak $\lceil (n-1)/2 \rceil$..$n-1$ değer; yaprak olmayan kökte en az 2 çocuk.
- Yaprakların son pointer'ı sonraki yaprağa gider; aralık sorguları buna dayanır.
- Yükseklik en çok $\lceil \log_{\lceil n/2 \rceil}(K) \rceil$; 1 milyon anahtar ve $n=100$ için 4, ikili ağaçta yaklaşık 20.
- Ekleme: yaprağı bul, yer yoksa böl, sağ düğümün en küçük anahtarını yukarı ekle, gerekirse bölünmeyi köke kadar yay.
- Silme pratikte çoğu zaman yapılmaz; yapı korunur.

## Detaylı Açıklamalar

- Arama anahtarı ile istenen nitelik farklı şeylerdir. `SELECT salary FROM instructor WHERE name = 'Califieri'` sorgusunda milyonlarca hoca arasında aranan şey Califieri adıdır; maaş, kayda erişildikten sonra okunan bir niteliktir. Bu yüzden faydalı olan, `name` üzerindeki indekstir. İndeks olmazsa dosyadaki bütün kayıtlar sırayla taranmak zorunda kalır. İndeks dosyasının kendisi de şeması (arama anahtarı, pointer) olan küçük bir dosyadır; küçük ve sıralı olduğu için üzerinde ikili arama yapılabilir ya da bir B+ ağacına yerleştirilebilir.

- Dense ve sparse farkı lookup sorgularında belirginleşir. Kullanıcının girdiği birincil anahtarla bir kayıt eklenirken sistem, anahtarın tabloda olup olmadığını denetler. Dense indekste aranan değer indekste yoksa tabloda da yoktur ve iş indeks içinde biter. Sparse indekste ise değerin bulunabileceği aralığa gidip dosyanın o kısmını okumak gerekir. Karşılığında sparse indeks daha az yer kaplar; hangisinin seçileceği eldeki kaynağa bağlıdır.

- Sayısal örnekte 12 kayıtlık instructor dosyası, sayfa başına 2 kayıtla 6 disk sayfasına; 11 farklı maaş değeri içeren salary indeksi ise sayfa başına 6 kayıtla 2 sayfaya yerleşir. 72000 maaşlı kayıt (Crick) dosyanın 10. kaydıdır, yani sıralı aramada 5. sayfada bulunur. İndeksle önce indeksin ilgili sayfası okunur, sonra pointer ile doğrudan veri sayfasına gidilir: toplam 2 erişim. Hoca, 4 KB'lık gerçek sayfalarda bu küçük sayıların yalnız temsili olduğunu belirtti.

- B+ ağacında her seviyeye indeks tanımları uygulanabilir. `name` üzerindeki örnekte yaprak seviyesi, dosya ada göre sıralı olmadığı için secondary ve dense; yaprakların üstündeki seviyeler ise sıralı yapraklar üzerine kurulduğu için primary ve sparse bir indeks gibidir. Bu yüzden B+ ağacı bir çok seviyeli indeks olarak görülebilir.

- `find(v)` algoritmasında eşitlik durumu özel olarak ele alınır. Düğümde $v \le K_i$ olan en küçük $K_i$ bulunur. $v = K_i$ ise, $K_i$'ye büyük eşit değerler sağ alt ağaçta olduğu için $P_{i+1}$'e gidilir; $v < K_i$ ise $P_i$'ye gidilir. Hiçbir $K_i$ bulunamazsa $v$ düğümdeki bütün anahtarlardan büyüktür ve son pointer izlenir. Örneğin Z aranırsa kökte Mozart'tan büyük eşit bir değer yoktur ve sağa gidilir. Algoritmadaki döngü ağacın yüksekliği kadar döner.

- 1 milyon kayıt örneğinde $n = 100$ seçimi 4000 baytlık sayfa ve 40 baytlık indeks kaydından gelir ($4000 / 40 = 100$). Hoca, indeks kayıtlarının sıkıştırılabildiğini ve veritabanlarında sayfa boyutunun çoğu zaman 8 KB olduğunu, bu yüzden $n$'nin 500'lere çıkabileceğini söyledi. $\lceil n/2 \rceil = 50$ ile $\log_{50}(10^6) \approx 3{,}53$, yukarı yuvarlanınca 4 olur.

- Eklemede bölünme sonrası üst seviyeye yazılan anahtar, sağ alt ağacın en küçük elemanının bir kopyasıdır. Çünkü iç düğümde bir anahtarın sağındaki pointer, o anahtara büyük eşit değerleri gösterir. Lamport örneğinde yeni yapraklar `Gold, Katz` ve `Kim, Lamport` olduğu için üst seviyeye Kim yazılır; Katz yazılırsa arama kuralı bozulur.

- Silme işleminin pratikte çoğu zaman gerçeklenmemesinin sebebi, ekleme ve silmelerin birbirini izlemesidir. Silinen kayıtların bıraktığı boşluk, sonra gelen kayıtlarla dolar. Yer verimliliği bir miktar düşer ama birleştirme ve yeniden yapılandırma maliyetinden kaçınılmış olur.

> **Ders sonrası not:** Hoca ağacın maliyeti için bir yerde "logaritma 100 tabanında K" ifadesini kullandı. Formülde taban $\lceil n/2 \rceil$'dir; $n = 100$ için taban 50 olur (slaytta da $\log_{50}$ yazar).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
