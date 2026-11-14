# Ders 10 Çalışma Özeti

## Genel Konular

- Veri yapısı seçiminde saklama ortamının rolü
  - Verinin saklandığı ortam (ana hafıza, manyetik disk, SSD) kullanılacak veri yapısını ve algoritmayı önemli ölçüde belirler. Ana hafızada bir listeyi sıralamak için birçok algoritma vardır (merge sort, quick sort, bazı özel durumlarda radix sort, bubble sort); karşılaştırma esaslı sıralamanın en iyi karmaşıklığı $O(n \log n)$'dir ve bundan iyisi ispatlanmış olarak yoktur.
  - Ana hafızada bir işlemin gecikmesi nanosaniye, diskte rastgele bir noktaya erişim milisaniye mertebesindedir; arada kabaca $10^6$ kat fark vardır. Hoca bunu "3-5 saniyelik bir işi bir günde yapmak" gibi bir benzetmeyle anlattı. SSD bu farkı azaltır ama yine ana hafızadan çok yavaştır.
  - Disk ikincil hafızadır (secondary memory). İşlemci diskteki veri üzerinde doğrudan işlem yapamaz: Veri ana hafızaya alınır, işlenir ve diske geri yazılır. Bu hem yavaşlık hem de ana hafızadaki kopya ile diskteki veri arasında tutarsızlık demektir; bu tutarlılığı kurtarma (recovery) modülü sağlar. Hocaya göre bu ikinci bir darboğazdır.
- Disk terminolojisi
  - Disk sayfası (page): Aktarım birimi (unit of transfer) ve ayırma birimi (unit of allocation). Diskten tek bir karakter ya da tamsayı getirilemez, bir sayfa getirilir. İşletim sisteminde sayfa genelde 4 KB, PostgreSQL'de varsayılan 8 KB'dir.
  - Veritabanı tabloları fiziksel olarak diskte dosya olarak saklanır. 1000 sayfalık bir dosya $1000 \times 8\ \text{KB} = 8\ \text{MB}$ eder; hocaya göre disk esaslı algoritmaların önemi dosya ana hafızaya sığmayacak kadar büyüdüğünde ortaya çıkar.
  - Sıralı erişim (sequential access) ile rastgele erişim (random access) arasında da büyük fark vardır. Manyetik diskte rastgele erişimde disk kafasının sayfalar arasında boşa gidip gelmesi gecikme yaratır; sıralı erişim hocanın verdiği mertebeyle 10 ile 100 kat arasında daha hızlıdır.
  - Byte adreslenebilir kalıcı bellek (non-volatile memory, NVM) gibi yeni teknolojiler sayfa esaslı erişimi değiştirir; ama SSD ve manyetik disk esaslı geleneksel yaklaşımda temel düzen değişmemiştir.
- İndekslemenin amacı
  - Ana hafızaya sığmayan büyük dosyalarda aramayı, aktarılan veri miktarını ve rastgele erişim sayısını en aza indirerek sonlandırmak.
  - İki aile vardır: Sıralama esaslı indeksler (B+ ağacı; aramalar logaritmik) ve hash esaslı indeksler (ortalama $O(1)$). Konumsal (spatial) veri sıralanamadığı için yakınlık esaslı yapılar (R-ağacı) kullanılır; zamansal ve zaman-uzamsal veri için de ayrı yapılar vardır.
  - Hash'in karmaşıklığı daha iyi görünse de veritabanlarında baskın yapı B+ ağacıdır. Hocaya göre algoritma karmaşıklığı bazen aldatıcıdır: Hash'te çakışmalar (collision) ve taşmalar vardır, veri dinamik ve patlamalı (bursty, bulk) gelir.
- Sıralı indeks dosyası (ekrandan, 00:28:50 ve 00:30:00)
  - İndeks, ana dosyaya eklenen yardımcı (auxiliary) bir erişim dosyasıdır. Arama anahtarına (search key) göre sıralıdır ve her girdisi "arama anahtarı + işaretçi" çiftidir.
  - Ana dosya çoğu zaman heap dosyasıdır: Yeni kayıt sona ya da boş yere eklenir, sıralama yoktur.
  - Ana dosya neden sıralanmaz: Bir dosya aynı anda yalnız bir niteliğe göre sıralanabilir; sürekli ekleme ve silme altında sıralı tutmak çok pahalıdır (sıralamak için harici merge sort gerekir). İndeks dosyası ise küçüktür ve sabit uzunluklu kayıtlardan oluştuğu için ikili arama (binary search) yapılabilir.
  - Slayttaki örnekler: `instructor` üzerinde `ID` için yoğun (dense) indeks ve `salary` için ikincil (secondary) indeks. İkincil indekste her indeks kaydı, o değeri taşıyan bütün kayıtların işaretçilerini tutan bir kovaya (bucket) işaret eder; ikincil indeksler yoğun olmak zorundadır (ekrandan, 00:30:00).
- Varsayılan indeksler
  - Sistem varsayılan olarak yalnız birincil anahtara indeks oluşturur; bazı sistemler yabancı anahtara da oluşturur (hocaya göre PostgreSQL oluşturmaz).
  - Sebep: Birincil anahtar kısıtını denetlemek için yeni gelen kaydın tabloda olup olmadığına bakmak gerekir (look-up sorgusu). Yabancı anahtar içeren tabloya ekleme yapılırken de işaret edilen tabloda birincil anahtar aranır. Ayrıca join algoritmalarının bir kısmı indeks esaslıdır.
  - Her niteliğe indeks konmaz: İndeks bir veri tekrarıdır; her güncellemede indeksin de güncellenmesi gerekir. Yer çok önemli değildir, tutarlılık yükü önemlidir. İndeksler iş yüküne duyarlı (workload-aware) seçilmelidir.
- Kümelenmiş ve kümelenmemiş indeks
  - Kümelenmiş (clustered) indekste ana dosya da arama anahtarına göre sıralıdır; belli bir aralıktaki değerler dosyada bir aradadır (şekilde oklar paralel gider). Kümelenmemiş (unclustered) ya da ikincil indekste aralıktaki değerler dosyaya dağılmıştır.
  - PostgreSQL'de ana dosya hep heap'tir, indeksler hep ikincildir; Oracle ve MS SQL Server'da kümelenmiş indeks vardır.
  - Eşitlik sorgusunda ikincil indeks daha kıymetlidir: Kümelenmiş durumda indeks olmasa da dosyada ikili arama yapılabilir, ikincil durumda ise dosya sıralı taranmak zorundadır.
  - Aralık sorgusunda kümelenmiş indeksle ilk değer bulunur, sonra dosyada sırayla ilerlenir. İkincil indekste her değer için indeksten dosyaya ayrı gidilir; aralık genişledikçe indeksin anlamı kalmaz.
- Seçicilik (selectivity)
  - Bir koşulun kayıtların yüzde kaçını seçtiğidir. Birincil anahtar eşitliği tek kayıt döndürür; 1000 hocanın 10 farklı maaşı varsa `salary = 40000` yaklaşık 100 kayıt döndürür.
  - Hocaya göre seçilen kayıt oranı yaklaşık %5-10'u aşarsa iyileştirici ikincil indeksi kullanmaz, sıralı taramaya geçer (hoca kesin oranı hatırlamadığını belirtti).
  - Seçiciliği tahmin etmek için veri dağılımı gerekir; bu çoğu zaman histogramlarla kabaca tutulur ve ara sıra güncellenir (analiz operatörleri).
  - Sorgunun başına `EXPLAIN` yazılarak hangi algoritma ve indekslerin kullanıldığı görülebilir.
- Seyrek indeks ve çok düzeyli indeks (ekrandan, 00:57:10)
  - Seyrek (sparse) indeks yalnız bazı arama anahtarı değerleri için kayıt içerir; kayıtlar arama anahtarına göre sıralıysa uygulanabilir. $K$ değerli kaydı bulmak için $K$'dan küçük en büyük anahtarlı indeks kaydı bulunur ve dosya o kayıttan itibaren sıralı taranır.
  - İndeks dosyası da büyüyüp ana hafızaya sığmazsa onun üzerine de seyrek bir indeks kurulur. Böylece aramadaki logaritmanın tabanı 2'den sayfadaki girdi sayısına (fan-out) çıkar.
- B+ ağacı (ekrandan, 00:59:35 ve 01:13:25)
  - Her düğüm bir disk sayfasıdır. 8 KB'lık sayfada 100 girdi varsa her adımda veri kümesinin %1'ine odaklanılır: $\log_2 n$ yerine $\log_{100} n$. Gerçekte fan-out 300-500'e çıkar; milyarlarca kayıtta bile ağacın yüksekliği 3-5 olur.
  - Kök ve iç düğümlerin çoğu ana hafızada tutulabildiği için arama çoğu zaman bir iki disk erişimiyle biter.
  - Ağaç her zaman dengelidir (self-organizing): Ekleme ve silme yapraklardan köke doğru yapılır (split, merge); gelen verinin sırasından bağımsızdır. En kötü durum analizi ortalama durumla aynıdır. Buna karşılık ikili arama ağacı (BST) sıralı gelen veride bağlı listeye dönüşebilir.
  - Arama, güncelleme, ekleme ve silme her zaman kökten başlar. Yapraklar birbirine işaretçilerle bağlıdır; aralık sorgusunda yukarı çıkmadan sağa doğru ilerlenir.
  - İndeks tek başına cevap verebiliyorsa (örneğin `COUNT`) ana dosyaya gidilmez: index-only evaluation.
- Hash indeksleri (ekrandan, 01:40:00 ve 01:45:10)
  - Kova (bucket) bir saklama birimidir, genelde bir disk bloğudur. Hash fonksiyonu $h$, arama anahtarı değerlerini kova adreslerine eşler; örneğin $f(x) \bmod N$, $N$ kova sayısı.
  - Hash indeksinde kovalar kayıt işaretçilerini, hash dosya organizasyonunda kayıtların kendisini tutar (benzer şekilde B+ ağacı dosyası da vardır).
  - Slayt örneği: `instructor` dosyası `dept_name` anahtarıyla 10 kovaya dağıtılır; hash fonksiyonu karakterlerin ikili gösterimlerinin toplamının 10'a göre modudur: $h(\text{Music}) = 1$, $h(\text{History}) = 2$, $h(\text{Physics}) = 3$, $h(\text{Elec. Eng.}) = 3$.
  - Problemler: Aynı değerden çok kayıt olması (düşük seçicilik) ya da fonksiyonun düzgün dağıtamaması taşma (overflow) kovalarına yol açar; kova içinde sıralama yoktur, bütün zincir taranır. Statik hash'te kova sayısı baştan sabittir; yeniden hash'leme (rehash) çevrim içi yapılamaz.
  - Çözüm, kademeli büyüyüp küçülen kendini düzenleyen yöntemlerdir: Doğrusal hash (linear hashing), genişletilebilir hash (extendible hashing). Derste yalnız adları geçti.
  - Hash indeksi aralık sorgularında kullanılamaz, çünkü yakın değerler aynı kovada değildir. Yalnız tamsayı ve çok dar bir aralıkta tek tek değerler denenebilir.
- Çok anahtarlı erişim (ekrandan, 01:54:40)
  - Sorgu: `select ID from instructor where dept_name = "Finance" and salary = 80000`.
  - `ID` üzerindeki indeksin bu sorguya katkısı yoktur. Stratejiler: Yalnız `dept_name` indeksi + `salary` testi; yalnız `salary` indeksi + `dept_name` testi; iki indeksin işaretçi kümelerinin kesişimi; bileşik (composite) indeks; bitmap indeksi (slaytta, derste ayrıntılandırılmadı); indeks olsa da sıralı tarama.
- Bileşik indeks (ekrandan, 02:03:00)
  - `(dept_name, salary)` üzerindeki indeks sözlük sırasıyla (lexicographic) sıralanır. `dept_name = "Finance" and salary = 80000` ve `dept_name = "Finance" and salary < 80000` için verimlidir; `dept_name <= "Finance" and salary = 80000` için verimli değildir.
  - Sıra önemlidir: `(dept_name, salary)` yalnız `dept_name` sorgularına hizmet eder, yalnız `salary` sorgularına hizmet etmez.
- SQL'de indeks oluşturma (ekrandan, 02:06:45)
  - `create index takes_pk on takes (ID, course_ID, year, semester, section)` ve `drop index takes_pk`. Varsayılan tür B+ ağacıdır; başka tür `using` ile belirtilir (örneğin hash). Sistemlerde konumsal, metin ve çoklu ortam verisi için 7-8 farklı indeks türü vardır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Disk darboğazı
  - Bütün indeks tasarımının çıkış noktası, diskin ana hafızadan çok yavaş olması ve rastgele erişimin sıralı erişimden çok pahalı olmasıdır. Hedef hem aktarılan veri miktarını hem rastgele erişim sayısını azaltmaktır.
- B+ ağacının her yerde olması
  - B+ ağacı ilişkisel veritabanlarında, NoSQL sistemlerinde (LSM ağacı biçiminde) ve işletim sistemlerinde "ubiquitous", yani her yerde olan bir veri yapısıdır. Yeni bir algoritma değildir; logaritmanın tabanını 2'den yüzlere çıkararak pratikte çok güçlü olur.
- İndeks kullanımı ezberlenemez
  - Bir filtre üzerinde indeks olması iyileştiricinin onu kullanacağı anlamına gelmez. Seçicilik, sorgunun eşitlik mi aralık mı olduğu ve indeksin kümelenmiş olup olmaması kararı değiştirir. Hoca bu kavramlarla birçok soruya yorum yapılabileceğini söyledi.
- Kavramların arkasındaki anlam
  - Clustered, unclustered, primary, secondary terimleri karışabilir; hoca adların arkasındaki anlamın (aralıktaki değerlerin dosyada bir arada olup olmaması) bilinmesini istedi.
- Hash'in ikinci planda kalması
  - Birinci sebep sistem bütünleşmesinin (eş zamanlılık, kurtarma modülleriyle uyum) zor olması, ikinci ve belki daha önemli sebep aralık sorgularında hiç kullanılamamasıdır. Aralık sorguları çok yaygındır (ortalaması 3 ile 3,5 arasındaki öğrenciler gibi).
- Bileşik indekste nitelik sırası
  - Hangi niteliğin önce geleceği iş yüküne ve seçiciliğe bağlıdır; yanlış sıra indeksi bazı sorgular için işe yaramaz kılar. İndeks ayarlama (index tuning) kesin çözümü olmayan, dinamik ve çok geniş bir arama uzayı olan, yıllardır çalışılan bir problemdir.

## Kısa Tekrar Notları

- Ana hafıza: nanosaniye; disk rastgele erişim: milisaniye; fark yaklaşık $10^6$.
- Aktarım ve ayırma birimi sayfadır; PostgreSQL'de varsayılan 8 KB.
- Sıralı erişim, rastgele erişimden 10-100 kat hızlıdır.
- İndeks: Arama anahtarına göre sıralı, "anahtar + işaretçi" girdilerinden oluşan küçük yardımcı dosya.
- Ana dosya genelde heap; aynı anda tek niteliğe göre sıralanabilir, sıralı tutmak pahalı.
- Birincil anahtara varsayılan indeks: kısıt denetimi (look-up) ve join.
- Her niteliğe indeks konmaz: güncelleme ve tutarlılık yükü.
- Kümelenmiş indeks: dosya da anahtara göre sıralı. İkincil indeks: dosya sıralı değil, yoğun olmak zorunda.
- Eşitlikte ikincil indeks daha kıymetli; geniş aralıkta ikincil indeks kullanılmaz.
- Seçicilik yüksek oranda kayıt seçiyorsa (yaklaşık %10'dan fazla) sıralı tarama.
- Seyrek indeks: blok başlarındaki anahtarlar; çok düzeyli indeks B+ ağacına götürür.
- B+ ağacı: düğüm = sayfa, fan-out yüzlerce, yükseklik 3-5, her zaman dengeli, yapraklar bağlı.
- Index-only evaluation: Cevap indeksten çıkıyorsa ana dosyaya gidilmez.
- Hash: kova, $h(K) \bmod N$, taşma zinciri; statik hash büyüyemez; aralık sorgusunda kullanılmaz.
- Çok anahtarlı erişim: tek indeks + test, işaretçi kesişimi, bileşik indeks, bitmap, sıralı tarama.
- Bileşik indeks sözlük sırasıyla sıralanır; ilk nitelik seçimi kritik.
- `create index ... on ... (...)`, `drop index ...`; varsayılan B+ ağacı, `using hash` gibi seçenekler.

## Detaylı Açıklamalar

- Neden disk esaslı veri yapıları
  - Ana hafızadaki algoritmaların karmaşıklık analizi işlem sayısına bakar. Diskte ise asıl maliyet disk erişimi (disk I/O) sayısıdır, çünkü bir disk erişimi ana hafızadaki bir işlemden yaklaşık bir milyon kat yavaştır. Bu yüzden sayfa içinde kayıtları sıralı tutmak gibi işlemci maliyetleri, disk erişiminin yanında ihmal edilebilir kalır.
  - Örnek olarak 8 KB'lık bir sayfaya 100 baytlık `instructor` kayıtlarından yaklaşık 80 tane sığar. Tek bir kayda erişmek istense bile sistem bütün sayfayı getirir.
  <!-- BELİRSİZ: Hoca SSD ile ana hafıza arasındaki farkı bir yerde "2.000'e yakın", başka bir yerde "1.000.000'dan 100.000'e düştük" diye verdi; altyazıdan net değer çıkmıyor. -->
  - Ders sonrası not: Hoca 8000 bayt / 100 bayt için "87 tane kayıt" dedi; doğrusu $8000/100 = 80$ kayıttır (altyazı bozulmuş da olabilir).
- Sıralı indeks ve ikili arama
  - İndeks dosyasındaki kayıtlar "arama anahtarı + işaretçi" biçiminde sabit uzunlukludur. Örneğin 5 baytlık `ID` ve 4 baytlık işaretçi yaklaşık 10 bayt eder; ana dosyada bir kayıt 50-100 bayt ya da daha fazladır. 10 nitelikli bir tabloda indeks dosyası kabaca ana dosyanın onda biri kadardır.
  - `select salary from instructor where ID = ...` sorgusunda `ID` indeksinde ikili arama yapılır, kayıt bulunursa işaretçiyle ana dosyaya gidilir; değer indekste yoksa ana dosyaya gitmeye gerek kalmaz.
  - `select name from instructor where salary = 40000` sorgusu için `salary` üzerindeki ikincil indeks kullanılabilir.
- Disk erişim sayısı örneği
  - Hocanın temsili örneğinde 12 kayıtlı `instructor` dosyası her sayfada 2 kayıtla 6 sayfa tutar. Dosyanın sonundaki `Kim` kaydına sıralı taramayla 6 sayfa okunarak ulaşılır. B+ ağacında kök, iç düğüm, yaprak ve veri sayfası olmak üzere 4 erişim gerekir. Hocaya göre küçük dosyada fark az görünür; milyonlarca sayfada sıralı tarama binlerce sayfa okurken ağaçta bir iki disk erişimi yeter.
- B+ ağacında arama (ekrandan, 01:13:25)
  - Slayttaki `find(v)` fonksiyonu: `C = root` ile başlanır; `C` yaprak değilken $V \le K_i$ olan en küçük $i$ bulunur; böyle bir $i$ yoksa `C` düğümdeki son boş olmayan işaretçiye, $v = C.K_i$ ise $C.P_{i+1}$'e, aksi hâlde $C.P_i$'ye ayarlanır. Yaprakta bir $i$ için $K_i = V$ ise $C.P_i$ döndürülür, yoksa null.
  - `Kim` araması: Kökte `Mozart` var; `Kim` < `Mozart` olduğu için sol alt ağaca gidilir, sağ taraf budanır (prune). İç düğümde (`Califieri`, `Einstein`, `Gold`) `Kim` > `Gold` olduğu için son işaretçiden yaprağa (`Gold`, `Katz`, `Kim`) inilir ve `Kim` bulunur.
  - Aralık sorgusu: `select count(*) from instructor where name between 'Califieri' and 'Srinivasan'` için `Califieri` yaprağı bulunur, sonra bağlı yapraklarda sağa doğru `Srinivasan`'a kadar sayılır. Cevap indeksten çıktığı için ana dosyaya gidilmez. `sum(salary)` istenirse her kayıt için ana dosyaya gitmek gerekir; aralık geniş olduğu için iyileştirici indeksi kullanmayabilir.
- Hash ve aralık sorguları
  - B+ ağacında `Califieri` bulunduktan sonra yol açıktır: Komşu değerler yan yanadır. Hash indeksinde `Califieri`'nin kovasında ona alfabetik olarak yakın değerler yoktur; dağılım rastgeledir. Bu yüzden aralık sorgusunda hash kullanılamaz. Hash indeksi eşitlik ve look-up sorgularında iyidir; başarılıysa birincil anahtar için varsayılan olarak bile seçilebilir.
  - Ders sonrası not: Hoca PostgreSQL'de hash indeksinin 10. sürümden sonra gerçekten kullanılır hâle geldiğini ve bunun 2008-2010 yıllarına denk geldiğini söyledi. PostgreSQL 10 büyük olasılıkla 2017'de çıktı; hash indekslerinin kalıcı günlüğe (WAL) yazılması da o sürümle geldi.
  <!-- BELİRSİZ: Hoca hash örneği şeklinde (slayt 56) "8 sayfa ayırmışım, 6'sını doldurmuşuz" dedi; önceki slayt 10 kova diyor. Şekil karesi okunmadı. -->
- Çok anahtarlı erişim ve bileşik indeks
  - Slayttaki örnekte yapraklarda `Acc 1000, Acc 2000, ..., Business 1000, ..., Finance 1000, Finance 2000, Finance 4000, Finance 8000, Finance 10000` sırası görünür (ekrandan, 02:03:00). `dept_name = "Finance" and salary < 80000` sorgusunda yalnız Finance bölgesinin başı okunur, boşa erişim yoktur. `dept_name <= "Finance" and salary = 80000` sorgusunda ise ilk koşulu sağlayan ama ikinciyi sağlamayan çok kayıt okunur.
  - İki indeksin birlikte kullanıldığı stratejide işaretçi kümelerinin kesişimi alınır; dosyaya yalnız iki koşulu da sağlayan kayıtlar için gidilir. Ama `dept_name` ve `salary` koşullarının ikisi de çok kayıt seçiyorsa iyileştirici hiçbir indeksi kullanmayıp sıralı taramaya düşebilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
