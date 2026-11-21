# Ders 5 Çalışma Özeti

## Genel Konular

- Test sürecinin tekrarı (V model üzerinden)
  - Sağ koldaki test aktiviteleri, sol koldaki geliştirme aktivitelerinin ürettiği belgeler kullanılarak yürütülür: kodlama ↔ birim test, alçak düzey tasarım ↔ bileşen testi, yüksek düzey tasarım ↔ bütünlük testi, ürün spesifikasyonu ↔ sistem ve kabul testi, müşteri gereksinimleri ↔ işlemsel kullanım (ekrandan, 00:10:00).
  - Regresyon testi bütünlük testinin yanında, beta ve teşhis testleri işlemsel kullanım tarafında gösterilir.
- Birim testi
  - Modül içindeki hataları bulmaya yöneliktir, genellikle saydam kutu testi uygulanır: ara birim, yerel veri yapısı, kontrol yapıları ve ana yollar sınanır.
  - Test sürücü (driver), test edilen modülü çağıran; koçan (stub), test edilen modülün çağırdığı alt programı temsil eden yapay ara programlardır.
  - Test senaryosu (test case), hangi veriyle çalıştırılacağını tanımlayan test verisidir; birim testte olduğu gibi diğer test adımlarında da kullanılır.
- Bütünleme (bütünlük, entegrasyon) testi
  - Modüller yazılım ara birimiyle birbirine bağlıdır. Birleştirmede veri kaybı, birbirini ters etkileme, beklenen ana fonksiyonun gerçekleşmemesi, hata toleranslarının eklenerek büyümesi ve genel veri yapılarının sorun yaratması söz konusu olabilir (ekrandan, 00:15:00).
  - Bütün olarak sınama ya da artırmalı sınama yapılır; artırmalı sınama yukarıdan aşağı veya aşağıdan yukarı uygulanır (ekrandan, 00:20:00).
  - Birleştirme planı yüksek düzey (genel) tasarımdan, yani yazılım tasarım spesifikasyonundaki (SDS) mimari yapıdan gelir.
- Regresyon testi
  - Test edilmiş bir yazılımda değişiklik ya da ekleme yapılınca veya uygulama ortamı değişince tümünün yeniden test edilmesidir.
- Sistem testi
  - İşletim sistemi, destek yazılımları ve donanımla uyum; güvenlik, dayanıklılık ve performans testleri.
  - Performans testi: performans seviyelerinin belirlenmesi, belirli yük altında çalışma zamanı performansının ölçülmesi, sistem ayarlamaları (tuning). Yanıtladığı sorular: gereksinimler karşılanıyor mu, normal şartlarda sistem nasıl davranıyor, trafik artışı işlem süresini nasıl etkiliyor, hangi kullanıcı seviyesinde sorun yaşanıyor, düşüş hangi bileşenden kaynaklanıyor (ekrandan, 00:30:00).
  - Sistem testinde SRS belgesi, özellikle işlevsel olmayan gereksinimler kullanılır.
- Kabul testi
  - Düzenin (konfigürasyonun) incelenmesi: kullanıcı ve tasarım belgeleri, kayıtlar, test belgeleri tam mı, ilişkileri belirtilmiş mi.
  - Onaylama testi: kullanıcılar ya da kullanıcı benzerleri, kullanıcı belgelerini izleyerek yazılımın gereksinimleri karşıladığını sınar.
- Test tipleri
  - Kara kutu testi dış spesifikasyon ve gereksinimlere, saydam kutu testi iç yapıya (deyimler, dallar, algoritma) dayanır. İkisi birlikte kullanılır.
  - Saydam kutu: temel yol testi (döngüsel karmaşıklıkla temel yol sayısı ve test case sayısı bulunur) ve döngü testi (basit, yuvalanmış, birbirine bağlı, yapısal olmayan döngüler; başlangıç, bitiş, artım kontrolü) (ekrandan, 00:35:00).
  - Kara kutu: eşdeğer bölümleme (girdi uzayı geçerli ve geçersiz sınıflara bölünür) ve sınır değer analizi (hatalar daha çok sınırlarda çıkar).
- Hata düzeyleri
  - Ölümcül, kritik, büyük, orta, küçük ve görünüm hataları (ekrandan, 00:40:00).
- Yazılım ölçümü (Software Metrics)
  - "Yazılım üretimi ölçülemez ise kontrol edilememektedir." (Tom DeMarco) (ekrandan, 01:00:00).
  - Yöneticiler maliyet tahmini, personel üretkenliği, ürün kıyaslama, araç satın alma kararı için; yazılım mühendisleri kalite izleme, güvenirlik, ölçülebilir kalite ve performans gereksinimleri, sertifika ve gelecekteki projeler için tahmin amacıyla ölçüm yapar.
- Halstead ölçütü
  - Aritmetiksel karmaşıklığı işleç (operatör) ve işlenen (operand) sayılarından hesaplar: program uzunluğu, program hacmi, program gücü (ekrandan, 01:05:00).
- McCabe döngüsel karmaşıklığı (cyclomatic complexity)
  - Kontrol akışına göre karmaşıklık; tasarımda (modül büyüklüğü sınırı) ve birim testte (temel yol ve test case sayısı) kullanılır.
  - Ortalama alma yöntemine ait akış grafında altı bölge (R1-R6) vardır, yani altı temel yol (ekrandan, 01:10:00).
- Yazılım güvenirliği
  - Güvenirlik modelleri istatistiki verilere dayanır; toplam hata sayısı, güvenirlik düzeyi, revizyon sonrası kalan hata sayısı gibi değerler verir (ekrandan, 01:15:00).
  - Yüze yakın model vardır: Schneidewind, Jelinski-Moranda, Musa (temel ve logaritmik Poisson yürütme zamanı), Littlewood-Verrall.
  - Güvenirliği sağlama adımları gereksinimden teslim ve bakıma kadar yayılır (ekrandan, 01:20:00).
- Büyüklük ölçütleri
  - Fonksiyon noktası (function point): girdi, çıktı, ara birim, sorgu ve dosya sayıları ağırlıklandırılarak dolaylı ölçüm yapılır.
  - Kod satır sayısı (LOC, KLOC): doğrudan sayım; basit ama dile ve ortama bağlı.
- Nesneye yönelik metrikler: Chidamber & Kemerer (CK) metrik kümesi
  - WMC, DIT, NOC, CBO, RFC, LCOM (ekrandan, 01:30:00, 01:35:00, 01:40:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bütünlük testinin planı tasarımdan gelir
  - Gereksinim analizi sistem ve kullanıcı testini besler; bütünlük testinde modüllerin hangi sırayla, hangi hiyerarşiyle birleştirileceği yüksek düzey tasarımdaki yapı ve sınıf diyagramlarından alınır. Alçak düzey tasarım ise bileşen testinde kullanılır.
- Temel yol sayısı kadar test case gerekir
  - Akış grafından döngüsel karmaşıklık bulunur; bu değer bağımsız yol sayısıdır ve saydam kutu testinde hazırlanacak test case sayısını verir.
- McCabe değeri 10'u aşmamalı
  - Deneyimlere göre bir modülün döngüsel karmaşıklığı en çok 10 olmalıdır; aşarsa test ve takip zorlaşır, modülün alt modüllere bölünmesi önerilir.
- Halstead formüllerini ezberlemek gerekmez
  - Önemli olan ölçütün neyi ölçtüğü (aritmetiksel karmaşıklık) ve neye dayandığı (işleç ve işlenen sayıları).
- Fonksiyon noktası tek bir sayım değildir
  - Beş farklı şey sayılıp ağırlıklandırılır; en büyük ağırlık dosya sayısındadır. Bu yüzden dolaylı bir ölçümdür. LOC ise doğrudan ölçümdür.
- Ölümcül hatada test durur
  - Ölümcül hata düzeltilmeden teste devam edilmez; kritik hatada test sürer ama yazılım teslim edilmez; küçük hatayla teslim mümkündür.
- Güvenirlik ihtiyacı her yazılımda aynı değildir
  - Her uygulama için %99,9 gerekmez; güvenirlik arttıkça maliyet de artar.
- Nesneye yönelik yazılımda ölçüm bir set olarak yapılır
  - En yaygın küme CK metrikleridir; bağımlılık (coupling) fazla olmamalı, uyum (cohesion) yüksek olmalıdır.

## Kısa Tekrar Notları

- V model: alçak düzey tasarım ↔ bileşen testi, yüksek düzey tasarım ↔ bütünlük testi, ürün spesifikasyonu ↔ sistem/kabul testi.
- Test sürücü çağıran, koçan (stub) çağrılan yapay modüldür.
- Artırmalı bütünleme: yukarıdan aşağı veya aşağıdan yukarı.
- Regresyon: değişiklikten sonra tümünü yeniden test etmek.
- Sistem testi: güvenlik, dayanıklılık, performans; SRS ve işlevsel olmayan gereksinimler.
- Kabul testi: konfigürasyon incelemesi + onaylama (kullanıcı) testi.
- Saydam kutu: temel yol ve döngü testi. Kara kutu: eşdeğer bölümleme ve sınır değer analizi.
- Halstead: $m, k$ farklı işleç/işlenen sayısı; $M, K$ yinelenme toplamları; hacim $H = (M+K)\log_2(m+k)$.
- McCabe: $V(G) = E - N + 2$ = bölge sayısı = temel yol sayısı = gereken test case sayısı; modül için üst sınır 10.
- Güvenirlik modelleri: Schneidewind, Jelinski-Moranda, Musa, Littlewood-Verrall.
- Büyüklük: fonksiyon noktası (dolaylı), LOC/KLOC (doğrudan).
- CK: WMC, DIT, NOC, CBO, RFC, LCOM.

## Detaylı Açıklamalar

- Test sürecinin tekrarı
  - Yazılım test süreci, geliştirme sürecinin adımlarını temel alır ve o adımlarda hazırlanan belgeleri kullanır. V modelin sol kolu geliştirme, sağ kolu test aktiviteleridir. Birim testte modülün iç yapısı saydam kutu yaklaşımıyla incelenir. Test edilecek birim bağımsızsa doğrudan veri verilip sonuçlara bakılabilir; ama genellikle başka bir modül tarafından çağrıldığı için bir test sürücüye, kendisi başka modülleri çağırıyorsa koçanlara (stub) ihtiyaç duyulur.
  - Bütünlük testinde her modül tek başına doğru çalışsa da birleştirmede sorunlar çıkabilir. Genelde artırmalı sınama tercih edilir: modüller bir plana göre teker teker eklenir. Aşağıdan yukarı yaklaşımda önce alttaki modüller test edilir, sonra kümeler (cluster) oluşturularak yukarı doğru birleştirilir. Bu planı veren belge, mimari yapının çıkarıldığı yüksek düzey tasarımdır.
  - Sistem testi, bütünleşmiş yazılımın işletim sistemi, destek yazılımları ve donanımla uyumuna bakar. Güvenlik testi zararlı dış müdahalelere ve bilgi hırsızlığına karşı korumayı, dayanıklılık testi anormal yüklenmede davranışı, performans testi ise özellikle gerçek zamanlı ve gömülü sistemlerde işlem süresinin sistemle uyumunu sınar. Performans testi birim ve bütünlük testinde de tekrarlanabilir, ama bütün üzerinde mutlaka yapılır.
  - Kabul testinde önce konfigürasyon, yani teslim edilmesi gereken bütün belgelerin tam ve birbiriyle ilişkili olup olmadığı incelenir; ardından kullanıcılar ya da kullanıcı benzerleri kullanıcı belgelerini izleyerek yazılımın gereksinimleri karşıladığını onaylar.
- Test tipleri
  - Saydam kutu testinde işlemsel (prosedürel) tasarımın kontrol yapısı kullanılır: bütün bağımsız yollar en az bir kez çalıştırılır, mantıksal kararların doğru ve yanlış durumları denenir, döngüler sınırlarında ve içinde çalıştırılır, iç veri yapıları sınanır. Temel yol testinde ayrıntılı tasarım ya da kaynak koddan bir akış grafı çizilir, düğüm ve kenarlardan döngüsel karmaşıklık bulunur. Döngü testinde döngülerin başlangıç ve bitiş değerleri, indisleri ve artımları kontrol edilir; hata varsa döngüye hiç girilmeyebilir, iç içe döngülerde ya da ardışık döngüler arasında değer atlaması olabilir.
  - Kara kutu testi iç yapıdan çok temel sistem modelini dener. Geçerli girdilerin yanında mutlaka anormal (geçersiz) veri de verilir ve çıkışlara bakılır. Eşdeğer bölümlemede girdi uzayı sınıflara bölünür ve her sınıftan veri seçilir; sınır değer analizinde hatalar daha çok kenarlarda çıktığı için sınır değerleri test edilir.
  - Hata sınıflaması test yönetimi içindir: hangi düzeyde kaç hata çıktığı ve hangilerinin düzeltildiği izlenir. Hataların hangi süreçte ortaya çıktığına bakıldığında en çok gereksinim aşamasından kaynaklandığı görülmüştür.
- Yazılım ölçümü
  - Ölçemediğimiz şeyi kontrol edemeyiz. Yöneticiler bitmiş projelerin büyüklüğü ve maliyetinden yola çıkarak yeni projelerin maliyetini tahmin etmek ister; bu bilginin temelini yazılım mühendislerinin ölçümleri oluşturur. Mühendisler ayrıca modüllerin belirli bir kod satırını aşmaması gibi yapısal kararlar için de ölçüm kullanır.
  - Halstead ölçütü kaynak programın kalite güvencesini kestirmek için $m$ (farklı işleç sayısı), $k$ (farklı işlenen sayısı), $M$ (işleç yinelenmelerinin toplamı) ve $K$ (işlenen yinelenmelerinin toplamı) değerlerini kullanır (ekrandan, 01:05:00):
    - Program uzunluğu: $U = m\log_2 m + \log_2 k$ (slayttaki yazımıyla).
    - Program hacmi: $H = (M+K)\log_2(m+k)$.
    - Program gücü (program effort): $G = H/O$. Slayta göre oransal hacim daima birden küçük olmalıdır. <!-- BELİRSİZ: O simgesi slaytta tanımlı görünmüyor; büyük olasılıkla oransal hacimdir. -->
    - Ders sonrası not: Halstead'in tahmini uzunluk formülü büyük olasılıkla $m\log_2 m + k\log_2 k$ biçimindedir; slayttaki ikinci terimde $k$ çarpanı eksik görünüyor.
  - McCabe ölçütü kontrol akışından karmaşıklık derecesini belirler. Akış grafında kontrol deyimleri ve döngüler ayrı düğüm, ardışık komutlar tek düğüm olarak gösterilir. Döngüsel karmaşıklık kapalı bölgelerle en dıştaki bölgenin toplamıdır. Ortalama alma yöntemine ait grafta (Pressman'ın kitabından) 13 düğüm ve R1-R6 olmak üzere altı bölge vardır; buna göre altı temel yol ve altı test case gerekir (ekrandan, 01:10:00).
    - Ders sonrası not: Hoca formülü "kenar sayısı eksi düğüm sayısı artı bir" diye söyledi; doğrusu $V(G) = E - N + 2$'dir. Ekrandaki grafta okunan 17 kenar ve 13 düğümle $17 - 13 + 2 = 6$ çıkar, bu da bölge sayısıyla tutar (python ile kontrol edildi).
  - Yazılımın tamamını test etmek mümkün değildir; slayta göre bin satırlık bir programda en az bir satırın hatalı olduğu tahmin edilir. Güvenirlik modellerini seçerken modelin geçerliliği, kullanım kolaylığı, yazılımın ne kadarına ihtiyaç duyduğu, anlaşılırlığı ve dış etkenlerden etkilenip etkilenmediği değerlendirilir. Güvenirliği artırmak için işlevsel profil iyi belirlenir, hatalar tanımlanıp sınıflanır, müşterinin güvenirlik ihtiyacı belirlenir, bileşenler arası güvenirlik ve hatalı kodlamanın önlenmesi üzerinde durulur, güvenirlik her aşamada ölçülür; sistem testinde testler yönetilir ve gözlemlenir, ek testler belirlenir, teslim ve bakımda müşteri memnuniyeti izlenir.
  - Fonksiyon noktası, girdi, çıktı, ara birim, sorgu ve dosya sayılarının ağırlık faktörleriyle birleştirilmesiyle hesaplanır; en büyük ağırlık dosya sayısındadır. LOC (bin satır için KLOC) doğrudan ölçümdür; programlama diline ve ortama bağlı olduğu için objektif değildir, bunun için diller arası dönüşüm tabloları hazırlanmıştır, ama kullanımı basit olduğu için yaygındır.
- CK metrikleri (ekrandan, 01:30:00, 01:35:00, 01:40:00)
  - WMC (sınıfın ağırlıklı metot sayısı): sınıfın tüm metotlarının karmaşıklıklarının toplamı; hepsi 1 alınırsa metot sayısıdır. Geliştirme ve bakım süresi hakkında fikir verir; metodu çok taban sınıflar çocuklarını daha çok etkiler ve tekrar kullanılabilirliği düşürür.
  - DIT (kalıtım ağacı derinliği): sınıfın köke uzaklığı; türetilmemiş sınıf için 0, çoklu kalıtımda en uzak köke olan uzaklık. Derin sınıfların davranışı zor tahmin edilir, derin ağaçlar tasarım karmaşıklığını artırır.
  - NOC (alt sınıf sayısı): doğrudan türetilmiş alt sınıf sayısı; çok fazlası kalıtımın yanlış kullanıldığını gösterebilir ve test bütçesini artırır.
  - CBO (nesne sınıfları arasındaki bağımlılık): sınıfın bağımlı olduğu sınıf sayısı; kalıtım olmadan bir sınıfın nitelik ya da metotları diğerinde kullanılıyorsa bağımlılık vardır. Aşırı bağımlılık tekrar kullanımı azaltır, değişime duyarlılığı ve test maliyetini artırır.
  - RFC (sınıfın tetiklediği metot sayısı): bir nesnenin metotları çağrıldığında tetiklenebilecek tüm metotların sayısı; test ve hata ayıklama zorluğunu gösterir.
  - LCOM (metotların uyumluluğu): ilk tanımda $M_1, \dots, M_n$ metotlarının kullandığı nitelik kümelerinin kesişiminden oluşan ayrık kümelerin sayısıdır. Sonraki tanımda $P$ ortak nitelik paylaşmayan, $Q$ en az bir ortak nitelik paylaşan metot çiftlerinin kümesi olmak üzere $|P| > |Q|$ ise $\mathrm{LCOM} = |P| - |Q|$, aksi durumda 0'dır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
