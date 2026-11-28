# Ders 4 Çalışma Özeti

## Genel Konular

- Filogenetiğin tanımı ve kökeni
  - Filogenetik, organizmalar arasındaki evrimsel ilişkileri inceler. Taksonomiyi de içine alan sistematik alanının bir parçasıdır.
  - Evrimsel biyolojinin bağlamı filogenidir (phylogeny): bütün organizma grupları arasındaki bağlantılar ata-torun ilişkisi üzerinden anlaşılır (ekrandan, 00:05:00). Türler ortak atalardan evrimleştikleri için birbirleriyle akrabadır. Bu ilişkinin grafik gösterimi filogenetik ağaçtır.
  - Örnek ağaçta kemirgenler, primatlar, keseliler, timsahlar, kuşlar, kertenkeleler ve yılanlar yer aldı: timsahlar ile kuşlar, kertenkeleler ile yılanlar, kemirgenler ile primatlar yakın akrabadır; kemirgen-primat grubu da keselilerle akrabadır.
  - Köken bilgisi (ekrandan, 00:10:00): *phyl-/phylo-* Latince, Yunanca *phylē/phylon* (kabile, ırk, şube) sözcüğünden gelir; *phyla* bir grup içindeki doğrudan soy hattıdır; *genetics* Yunanca *genetikos* ve *genesis* (köken) sözcüklerinden gelir (laws of origination, 1872; kalıtım çalışması, 1891'den beri). *Phylogeny* bir organizma türünün evrim tarihidir, *phylogenetics* filogeniyle uğraşan bilim dalıdır.
- Moleküler filogenetiğin gelişimi ve moleküler veri ile morfoloji karşılaştırması
  - 1960-1970'lerde protein dizileme, elektroforez, DNA hibridizasyonu ve polimeraz zincir tepkimesi (PCR) moleküler filogenetikte bir patlama yarattı. 1970'lerin sonundan bu yana birçok keşif yapıldı (örneğin endosimbiyoz, 1978).
  - Moleküler veri kesin olarak kalıtsaldır ve belirsizlik içermez; morfoloji/fizyoloji çevreden etkilenebilir.
  - Moleküler veride evrim düzenli ve öngörülebilirdir, nicel analiz esastır, homoloji kolay değerlendirilir ve uzak akrabalık bile çıkarılabilir; morfolojide evrim öngörülemez, nitel tartışma öne çıkar, homoloji zor değerlendirilir ve yalnız yakın akrabalıklar güvenle çıkarılır.
  - Moleküler veri PCR ve dizileme ile bol ve kolay üretilir; morfoloji, mikroorganizmalarda ve görünür morfolojisi olmayan canlılarda sorun yaratır.
- Bir filogeniyi yorumlama ve ağaç terimleri
  - Ağaçta dizilerin fiziksel konumu çok anlamlı değildir. Dalların yer değiştirmesi (swiveling) yalnız düğümlerde yapılabilir. Düğüm, birden çok dalın birleştiği noktadır.
  - Dendrogram ("ağaç çizimi"): hiyerarşik kümelemenin ürettiği kümelerin düzenini gösteren ağaç diyagramı; hesaplamalı biyolojide genlerin ya da örneklerin kümelenmesini, bazen ısı haritalarının üstünde göstermek için kullanılır.
  - Kladogram (Yunanca *klados*, dal; "dal çizimi"): yalnız ağaç topolojisini gösteren filogenetik ağaçtır, zaman ya da genetik uzaklık içermez (ekrandan, 00:20:00). Topoloji, ağacın dallanma örüntüsüdür. Dikdörtgen, eğik (slanted) ve dairesel kladogram biçimleri gösterildi.
  - Terimler (ekrandan, 00:25:00): kök (root), dallar (branches), iç düğümler (internal nodes), uç düğümler (terminal nodes), işlevsel taksonomik birimler (OTU) / taksonlar (A-F), kardeşler (sisters, örneğin D ve E). Bir düğümden ikiden fazla dal çıkarsa buna politomi (polytomy) denir.
- Köklü ve köksüz ağaçlar
  - Köklü ağaçta kök ortak atayı gösterir; A-F dizileri kök diziden mutasyon, ekleme gibi değişikliklerle oluşmuştur. Ağaçta kökten torunlara doğru bir zaman bileşeni vardır.
  - Köksüz ağaçta ortak ata düğümü yoktur; yalnız taksonlar arasındaki akrabalık derecesini belirtir, evrimsel yolu göstermez.
- Ağaç sayısı (ekrandan, 00:30:00)
  - $n$ tür için köklü ağaç sayısı $\dfrac{(2n-3)!}{2^{n-2}(n-2)!}$, köksüz ağaç sayısı $\dfrac{(2n-5)!}{2^{n-3}(n-3)!}$.
  - Köklü ağaç sayısı köksüzden çok daha fazladır: 5 türde 105 köklü, 15 köksüz ağaç vardır.
- Gruplar ve ağaç türleri
  - Monofiletik grup: gruptaki bütün taksonlar tek bir ortak atadan türemiştir ve doğal bir klad oluşturur (ekrandan, 00:35:00). Kurgusal örnekte Satürnlü 1-3 ve Merihli 1-3 birer monofiletik gruptur.
  - Parafiletik grup: ortak ata gruptaki başka taksonlarla da paylaşılır, üyeler doğal bir klad oluşturmaz.
  - Gen ağacı tek bir homolog gendeki ayrışmaya dayanır; genin evrim tarihini gösterebilir ama genin bulunduğu türlerin tarihini göstermeyebilir. Tür ağacı ayrıca tanıtıldı.
  <!-- BELİRSİZ: Tür ağacının tanımı altyazıda okunmuyor, ilgili an karelerde yok. -->
- Karakter ve uzaklık verisi (ekrandan, 00:40:00)
  - Moleküler veri iki kategoriye girer: karakter (sınırlı sayıda farklı durumda bulunabilen iyi tanımlanmış özellik) ve uzaklık (iki veri kümesi arasındaki genel, ikili farkın ölçüsü).
  - DNA ve protein dizileri ayrık karakter durumları tanımlayan, yani kategorik verilerdir (ekrandan, 00:45:00). Kategorik veride uzaklık ölçüsü olarak genelde Hamming ya da Levenshtein uzaklığı kullanılır.
- Filogenetik ağaç kurma yöntemleri
  - Uzaklık tabanlı yöntemler: diziler arasındaki ikili uzaklıkları hesaplar, en benzer dizileri gruplar (ekrandan, 01:05:00).
  - Karakter tabanlı yöntemler (maksimum parsimoni): ortak karakterlerin ortak soydan geldiğini varsayar; karakterlerin evrimi için en basit (en tutumlu) açıklama doğru kabul edilir.
  - Olasılıksal yöntemler (maksimum olabilirlik): belirli bir dizi evrimi modeli altında veri kümesinin ağaca uyma olasılığını hesaplar.
- UPGMA (Unweighted Pair Group Method with Arithmetic Mean)
  - En eski ve en basit uzaklık matrisi yöntemi; 1960'ların başında morfolojik karakterlerin evrimsel analizi için önerildi.
  - En küçük uzaklıklı iki tür birleştirilir, yeni grubun diğerlerine uzaklığı aritmetik ortalamayla bulunur, işlem bütün türler gruplanana kadar sürer. Dal noktası, gruplanan türlerin arasındaki uzaklığın yarısına konur.
  - Beş DNA dizisiyle Hamming uzaklığına dayalı örnek çözüldü (ekrandan, 01:25:00 ve 01:30:00).
- Dal uzunluklarının kestirimi
  - Üç dizili köksüz ağaçta tek topoloji vardır; $a=(d_{AB}+d_{AC}-d_{BC})/2$, $b=(d_{AB}+d_{BC}-d_{AC})/2$, $c=(d_{AC}+d_{BC}-d_{AB})/2$ (ekrandan, 01:40:00).
- Komşuluk ilişkisi yöntemi ve komşu birleştirme
  - Dört türde dört nokta koşulu: $d_{AB}+d_{CD} < d_{AC}+d_{BD}$ ve $d_{AB}+d_{CD} < d_{AD}+d_{BC}$ (ekrandan, 02:00:00). Yöntem dal uzunluklarının toplanabilir olduğunu varsayar.
  - Komşu birleştirme $n\times n$ uzaklık matrisiyle başlar, ilk adımda her yaprak kendi kümesidir, sonunda kök yok sayılarak köksüz ağaç döndürülür (ekrandan, 02:05:00).
- Maksimum parsimoni
  - Bilgi verici (informative) ve bilgi vermeyen (uninformative) konumlar; bir konumun bilgi verici olması için en az iki farklı nükleotit olmalı ve her biri en az iki kez bulunmalıdır (ekrandan, 02:10:00 ve 02:15:00).
  - Her ağaç için bilgi verici konumlardaki değişiklikler toplanır, en az değişiklik gerektiren ağaç seçilir.
- Maksimum olabilirlik, ağaç güvenilirliği ve hata kaynakları
  - Maksimum olabilirlik, geçiş/dönüşüm (transition/transversion) oranları farklı olabilen bir evrim modeli kullanır; her ağacın her konumu açıklama olasılığı hesaplanır, en yüksek olasılıklı ağaç seçilir.
  - Bootstrap, bir ağacın güven düzeyini kestiren yeniden örnekleme yöntemidir (ekrandan, 02:30:00). İki ağacın karşılaştırılmasında Kishino-Hasegawa tipi parametrik test (eşleştirilmiş t testi) kullanılır.
  - Uygulamalar: yaşam ağacı, endosimbiyoz (mitokondri ve kloroplastın kökeni), HIV alt tipleri ve COVID varyantları arasındaki ilişkiler. Hata kaynakları: küçük veri kümeleri, hızlı evrimleşen bölgeler, homoplazi, örnek kirlenmesi ya da yanlış etiketleme.

## Hocanın Özellikle Vurguladığı Kısımlar

- Uzaklık ile korelasyon farkı
  - Uzaklık benzemezlik ölçüsü, korelasyon benzerlik ölçüsüdür. Uzaklığın 0 olması veri kümelerinin aynı olduğunu, korelasyonun 0 olması aralarında (doğrusal) ilişki olmadığını gösterir. Hoca bunu "iyi bir sınav sorusu" olarak niteledi.
- DNA ve protein dizileri kategorik veridir
  - Bu yüzden sayısal uzaklık ölçüleri (örneğin Öklid) değil, Hamming ya da Levenshtein uzaklığı kullanılır.
- Hesaplanacak uzaklık sayısı
  - $k$ dizi için $k(k-1)/2$ ikili uzaklık vardır: 4 dizide 6, 5 dizide 10. Matristeki $k\times k$ hücrenin hepsi gerekmez.
- Uzaklık tabanlı yöntemler hızlıdır, ama yerel optimuma kolay takılır
  - Bir algoritmada hızlı bir başlangıç ağacı (tentative tree) gerekiyorsa uzaklık tabanlı yöntem en iyi seçimdir.
- Skor matrisiyle kurulan matriste ölçüt değişir
  - Uzaklık matrisi yerine skor matrisi kullanılırsa en küçük değer yerine büyük olasılıkla en büyük değer alınır, çünkü skor benzerlik ölçüsüdür.

## Kısa Tekrar Notları

- Filogeni: türler arası evrimsel ilişki; grafiği filogenetik ağaç.
- Kladogram yalnız topolojiyi gösterir; dendrogram hiyerarşik kümelemenin ağacıdır.
- Dallar yalnız düğümlerde döndürülebilir; ağaçtaki fiziksel sıra anlamsızdır.
- Kardeşler: aynı düğümden çıkan iki uç. Politomi: bir düğümden ikiden fazla dal.
- Köklü ağaç: ortak ata ve zaman yönü var. Köksüz ağaç: yalnız akrabalık derecesi.
- $n=5$: 105 köklü, 15 köksüz ağaç.
- Monofiletik: tek ortak ata, doğal klad. Parafiletik: ortak ata başka taksonlarla paylaşılır.
- Üç yöntem ailesi: uzaklık (hızlı), maksimum parsimoni (yavaş, 30 taksondan az için uygun), maksimum olabilirlik (çok yavaş, evrim modeline çok bağlı).
- UPGMA: en küçük uzaklığı birleştir, ortalamayla yeni matris, dal noktası uzaklığın yarısında.
- Üç dizide dal uzunluğu: $a=(d_{AB}+d_{AC}-d_{BC})/2$.
- Dört nokta koşulu dal uzunluklarının toplanabilirliğine dayanır.
- Bilgi verici konum: en az iki farklı nükleotit, her biri en az iki kez.
- Bootstrap: yerine koyarak yeniden örnekleme; dal destek değerleri yüzde olarak, genelde yalnız %60-100 arası gösterilir.

## Detaylı Açıklamalar

Ders, önceki derslerde sık sık anılan filogenetik ağaçların tanımıyla başladı. Filogenetik, organizmaların evrimsel ilişkilerini inceler ve sistematiğin bir parçasıdır. Türler aynı ortak atalardan evrimleştikleri için akrabadır; bu ilişki filogeni, grafik gösterimi filogenetik ağaçtır. Moleküler veriler (dizi verisi) morfolojik verilere göre daha güvenilirdir: kesin olarak kalıtsaldır, nicel analize uygundur, homoloji kolay belirlenir ve uzak akrabalıklar bile çıkarılabilir.

Bir filogenetik ağaçta dizilerin ağaçtaki yeri tek başına anlam taşımaz; düğümler etrafında dallar döndürülebilir. Kladogram yalnız topolojiyi gösterir; dal uzunlukları zaman ya da uzaklık bilgisi taşımaz. Ağaç dikdörtgen, eğik ya da dairesel biçimde çizilebilir; çok sayıda tür varsa eğik ve dairesel biçimler daha kolay çizilir. Köklü ağaçta kök ortak atayı temsil eder; köksüz ağaç yalnız torun türler arasındaki ilişkiyi gösterir. Olası ağaç sayısı tür sayısıyla çok hızlı büyür; bu yüzden büyük veri kümelerinde bütün ağaçları incelemek mümkün olmaz.

Ağaç kurma yöntemleri üç aileye ayrılır (ekrandan, 01:10:00):

| | Uzaklık | Maksimum parsimoni | Maksimum olabilirlik |
|---|---|---|---|
| Kullandığı veri | Yalnız ikili uzaklıklar | Yalnız paylaşılan türemiş karakterler | Bütün veri |
| Ölçüt | En yakın komşular arası uzaklığı en aza indirir | Toplam uzaklığı en aza indirir | Belirli parametrelerle ağaç olabilirliğini en büyütür |
| Hız | Çok hızlı | Yavaş | Çok yavaş |
| Zayıflık | Yerel optimuma kolay takılır | Evrim hızlıysa varsayımlar bozulur | Varsayılan evrim modeline çok bağlı |
| Uygun kullanım | Başlangıç ağacı üretmek ya da çok sayıda ağaç arasından seçmek | İşlenebilir durumlarda en iyi seçenek (<30 takson, homoplazi nadir) | Çok küçük veri kümeleri ve başka yöntemlerle kurulan ağaçları test etmek |

UPGMA örneğinde beş DNA dizisinin (A-E, 50 baz) hizalaması verildi ve aralarındaki Hamming uzaklıkları (uyuşmazlık sayıları) hesaplandı (ekrandan, 01:25:00 ve 01:30:00):

| Tür | A | B | C | D |
|---|---|---|---|---|
| B | 9 | - | - | - |
| C | 8 | 11 | - | - |
| D | 12 | 15 | 10 | - |
| E | 15 | 18 | 13 | 5 |

Bu değerler python ile hizalamadan yeniden hesaplanıp doğrulandı. En küçük uzaklık $d_{DE}=5$ olduğu için önce D ve E birleşir. Yeni uzaklıklar: $d_{DE,A}=(12+15)/2=13.5$, $d_{DE,B}=(15+18)/2=16.5$, $d_{DE,C}=(10+13)/2=11.5$. İndirgenmiş matriste en küçük değer $d_{AC}=8$ olduğundan A ve C birleşir: $d_{AC,B}=(9+11)/2=10$, $d_{AC,DE}=(13.5+11.5)/2=12.5$, $d_{B,DE}=16.5$. Sonraki en küçük değer 10 olduğundan AC grubuna B katılır, en son da bu grup DE ile birleşir.

Dal uzunluklarında, UPGMA'da dal noktası birleştirilen uzaklığın yarısına konur: A ve C dalları $8/2=4$, D ve E dalları $5/2=2.5$ olur (ekrandan, 01:35:00). Bu basit yaklaşım UPGMA'nın doğal olarak köklü ağaç üretmesini sağlar. Evrim hızlarının bütün soy hatlarında eşit olduğu varsayılamazsa, üç dizili köksüz ağaçta dal uzunlukları $a+b=d_{AB}$, $b+c=d_{BC}$, $a+c=d_{AC}$ denklemlerinden çözülür.

Dört dizide komşuluk ilişkisi yöntemi, dört nokta koşulunu sağlayan eşleşmeyi arar; komşu birleştirme yöntemi UPGMA'nın yaygın bir türevidir ve sonunda köksüz ağaç verir. Maksimum parsimoni ise her bilgi verici konum için her olası ağacın gerektirdiği en az değişiklik sayısını tutar; toplamı en küçük olan ağaç en tutumlu ağaçtır. Altı konumlu dört dizili örnekte yalnız 5. ve 6. konumlar bilgi vericidir, diğer dört konum parsimoni analizinde atılır (ekrandan, 02:10:00 ve 02:15:00). Maksimum olabilirlik bütün ağaçları üretir ama en kısa ağacı değil, bir evrim modeline göre en olası ağacı seçer. Kurulan ağacın güvenilirliği bootstrap ile, iki ağacın farkı ise eşleştirilmiş t testine dayalı parametrik testle sınanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
