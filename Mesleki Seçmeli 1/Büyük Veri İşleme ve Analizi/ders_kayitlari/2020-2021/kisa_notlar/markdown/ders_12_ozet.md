# Ders 12 Çalışma Özeti

## Genel Konular

- Dersin biçimi
  - Bu kayıt bir ders anlatımı değil, dönem projesinin demolarından oluşur. Öğrenci grupları sırayla ekran paylaşarak kurdukları Hadoop kümesini, HDFS istemcisini ve MapReduce ile yazdıkları istatistiksel fonksiyonları gösterir; hoca her gruba aynı teknik soruları sorar.
  - Bu not yalnız demolarda görülen teknik içeriği toplar. Sunanlar "bir grup" ya da "bir öğrenci" diye anılır.
- Bir büyük veri projesinin teknik bileşenleri (hocanın demoda sırayla kontrol ettikleri)
  - Tek düğümlü (single-node) ya da çok düğümlü (multi-node) bir Hadoop veya Spark kümesinin çalıştığını göstermek.
  - Bir HDFS istemcisi (HDFS client): kullanıcı arayüzünden yerel dosya sistemindeki bir dosyayı HDFS'e yazmak (write) ve HDFS'teki bir dosyayı okuyup yerel dosya sistemine geri koymak (read).
  - HDFS'teki bir veri kümesi üzerinde, kullanıcı arayüzünden çalıştırılan beş istatistiksel fonksiyonun MapReduce sürümleri.
  - Tek düğüm ile iki düğüm arasında performans (ölçeklenebilirlik) analizi.
- Küme kurulum yolları (demolarda görülenler)
  - VirtualBox üzerinde Ubuntu sanal makineleri: bir master (NameNode) ve iki slave (DataNode). NameNode web arayüzünün Datanodes sekmesinde iki canlı düğüm, kapasite, blok sayısı ve Hadoop sürümü (3.2.1, 3.2.2) görülür (ekrandan, 00:15:00; 00:35:00).
  - Docker ve docker-compose: NameNode, üç DataNode, ResourceManager, NodeManager ve HistoryServer ayrı kapsayıcılarda; tek komutla bütün düğümler ayağa kalkar. Kapsayıcı günlüklerinde HDFS ve YARN ayarlarının (örneğin `dfs.datanode.data.dir`, `dfs.webhdfs.enabled`, `yarn.resourcemanager.hostname`) yazıldığı görülür (ekrandan, 01:20:00).
  - Bulut: Amazon üzerinde dört düğüm kuran bir öğrenci, projeyi bu küme üzerinde çalıştıramadığı için tek düğümle devam eder.
  - Tek düğüm: `jps` komutu NameNode, SecondaryNameNode, DataNode, ResourceManager ve NodeManager süreçlerini listeler (ekrandan, 01:00:00).
- HDFS ile çalışma
  - Komutlar: `hadoop fs -mkdir`, `hadoop fs -put`, `hadoop fs -ls`, `hadoop fs -cat`, `hadoop fs -rmr`; iş çalıştırmak için `hadoop jar` (ekrandan, 01:00:00; 01:40:00).
  - Bir MapReduce işinin çıktı klasöründe `_SUCCESS` ve `part-r-00000` dosyaları oluşur. Web arayüzünde dosya bilgisi penceresi blok kimliğini, boyutu ve bloğun hangi DataNode'larda bulunduğunu (availability: slave1, slave2) gösterir (ekrandan, 00:20:00).
  - HDFS'e yazmak ile HDFS'ten okuyup yerel dosya sistemine indirmek ayrı işlemlerdir. Birçok grup yalnız yazmayı (put) ve iş sonucunu ekranda göstermeyi yapmış, dosyayı yerele indirmeyi (get) yapmamıştır.
- MapReduce ile istatistiksel fonksiyonlar
  - Ortak kalıp: mapper CSV satırını virgülle böler, gruplama sütununu anahtar (key), sayısal sütunu değer (value) olarak yayar; reducer aynı anahtarın değerleri üzerinde istatistiği hesaplar.
  - Gösterilen fonksiyonlar: ortalama, sayma (count), toplam, minimum/maksimum, aralık (range), medyan, mod, standart sapma, korelasyon.
  - Örnek anahtar-değer seçimleri: yıl ve ev satış fiyatı; şehir ve satış tutarı; film kimliği ve puan; coin adı ve fiyat; ülke ve izlenme sayısı.

## Hocanın Özellikle Vurguladığı Kısımlar

- HDFS istemcisi iki yönlü olmalı
  - Hoca "read" derken HDFS'teki bir dosyayı alıp yerel dosya sistemine koymayı kastettiğini birçok kez açıklar. İş sonucunu ekranda göstermek ya da dosyanın ilk satırlarını yazdırmak bu işlemin yerini tutmaz.
- Performans analizi ölçeklenebilirliği göstermeli
  - Hocanın beklediği, aynı fonksiyonları tek düğümlü ve iki düğümlü kümede çalıştırıp MapReduce ile nasıl bir ölçeklenebilirlik elde edildiğini görmektir.
  - Fonksiyonları birbiriyle ya da veri boyutuna göre karşılaştırmak farklı bir analizdir.
  - Süre ölçümü kodun içinde yapılmalıdır. Terminalde `date` yazarak ya da kronometreyle ölçüm yapmak bir bilgisayar mühendisinden beklenen ölçüm yöntemi değildir.
- Demoda önce çalışan sistem
  - Hoca önce kurulumun ve fonksiyonların çalıştığını, sonra kodu görmek ister. En çok sorduğu kod sorusu standart sapmanın mapper ve reducer'ının nasıl yazıldığıdır.

## Kısa Tekrar Notları

- Hadoop kümesi: master'da NameNode (ve ResourceManager), slave'lerde DataNode (ve NodeManager). Durum `jps` ile ya da NameNode web arayüzünden (9870 portu) görülür.
- HDFS write: yerel dosya → HDFS (`-put`). HDFS read: HDFS → yerel dosya sistemi (`-get` ya da arayüzde indirme).
- İş çıktısı: `_SUCCESS` ve `part-r-00000`.
- Ortalama: reducer'da toplam / sayı. Combiner kullanılacaksa değerin yanında sayı (1) da taşınmalıdır.
- Medyan: değerler sıralanır; tek sayıda ortadaki, çift sayıda ortadaki ikisinin ortalaması.
- Mod: en çok tekrar eden değer. Aralık: maksimum − minimum.
- Standart sapma: reducer'daki `Iterable` yalnız bir kez dolaşılabildiği için değerler önce bir listeye alınır; ilk geçişte ortalama, ikinci geçişte kare farkları toplanır.
- Tek geçişli varyans: $s^2 = \dfrac{\sum x^2 - (\sum x)^2 / n}{n-1}$.
- Ölçeklenebilirlik analizi: aynı iş, tek düğüm ve iki düğüm, süre kod içinde ölçülür.

## Detaylı Açıklamalar

- Küme kurulumunun gösterilmesi
  - Gruplar kümeyi üç yolla gösterdi: NameNode web arayüzünün Datanodes sekmesinde "In operation" tablosunda canlı DataNode'lar; slave makinede `jps` çıktısında DataNode ve NodeManager süreçleri; Docker kullananlarda `docker-compose up` çıktısında her kapsayıcının günlüğü. VirtualBox kurulumunda iki slave düğümün her biri yaklaşık 43,81 GB kapasite ve 3.2.1 sürümüyle görünür (ekrandan, 00:35:00).
  - Bir grup daha çok veri dağıtmak için üç DataNode kullandığını, her bileşenin (NameNode, DataNode'lar, ResourceManager, NodeManager, HistoryServer) ayrı bir Dockerfile ile tanımlandığını anlattı.
  - Çok düğümlü kurulumda karşılaşılan sorunlar da görüldü: düğümlerden birinin takılıp yeniden başlatınca çalışması, sanal makinede disk alanı yetmemesi (insufficient space hatası), port bağlantı sorunları, Windows üzerinde komutların yönetici izni istemesi.
- HDFS istemcisi ve kullanıcı arayüzleri
  - Arayüzler farklı teknolojilerle yazıldı: Java Swing, Python ile SSH üzerinden komut çalıştıran bir arayüz, Spring Boot ile yazılmış bir REST sunucusu ve ona bağlanan bir web ön yüzü. Bu son tasarımda ön yüz, işin durumunu sunucuya üç saniyede bir sorar ve Mapper ile Reducer aşamalarının ilerlemesini gösterir (ekrandan, 01:25:00).
  - Bir arayüzde "Browse and Push to HDFS", "Delete File From HDFS", "Pull File from HDFS" ve "Open Operations" düğmeleri vardır; bu grup yazma, silme ve yerele indirme işlemlerinin hepsini gösterdi (ekrandan, 00:50:00).
  - Başka bir arayüzde "Add File" ve "Get File" düğmeleriyle HDFS'teki dosyalar listelenir; listeden seçilen dosya "Get File" ile yerel dosya sistemine kopyalanır (ekrandan, 02:05:00).
  - Birçok arayüz düğmelerin arkasında terminal komutlarını (`hadoop fs -put`, `hadoop jar ...`) çalıştırır. Bir tek düğüm arayüzünün çıktı penceresinde sırasıyla `date`, `hadoop namenode -format`, `start-dfs.sh`, `start-yarn.sh`, `jps`, `hadoop fs -mkdir -p /inputs`, `hadoop fs -ls /`, `hadoop fs -put ...`, `hadoop fs -rmr ...` ve `hadoop jar ...` komutları görülür (ekrandan, 01:00:00).
- Ortalama
  - Bir grup mapper'da yılı anahtar, satış fiyatını değer olarak yaydı; reducer her yıl için gelen değerleri toplayıp sayıya böldü. Çıktıda yıllara göre ortalama satış fiyatı artar.
  - Başka bir çıktıda şehir adına göre ortalama satış değerleri görülür (ekrandan, 00:20:00).
  - Combiner kullanan bir grup, mapper'da değerin yanına bir de "1" koyduğunu anlattı; böylece combiner kısmi toplamları birleştirirken eleman sayısı kaybolmaz ve ortalama bozulmaz. Python ile yazılan bu mapper, koşullu ortalama (average-if) için iki sütunu arayüzden gelen bir karşılaştırma işleciyle karşılaştırır ve koşulu sağlayan satırlar için `anahtar\tdeğer\t1` yazar (ekrandan, 02:25:00).
- Minimum, maksimum ve aralık
  - Reducer gelen değerleri tek tek karşılaştırıp en küçüğü ve en büyüğü tutar; aralık bunların farkıdır.
  - Bir öğrenci maksimumu mapper içinde yerel olarak tuttu: `map` hiçbir şey yazmaz, mapper'ın `cleanup` metodu o mapper'daki en büyük değeri bir kez yazar. Reducer da aynı yolla bütün mapper'ların maksimumları arasından en büyüğünü seçer ve `cleanup`'ta yazar.
  - Bir grup min-max ile aralığın aynı bilgiyi verdiğini görüp aralık yerine medyanı koydu.
- Medyan ve mod
  - Medyan için aynı anahtarın değerleri bir diziye alınıp sıralanır; eleman sayısı tekse ortadaki değer, çiftse ortadaki iki değerin ortalaması alınır.
  - Mod için aynı anahtarın değerleri içinde en çok tekrar eden değer bulunur. Bir grup mod sonucunu Python'da DataFrame ile aynı sütunun modunu hesaplayarak doğruladı.
- Standart sapma
  - İki geçişli yöntem: reducer'a gelen `Iterable` bir kez dolaşıldıktan sonra değerler tükenir. Bu yüzden ilk döngüde değerler bir listeye eklenir, aynı anda toplam ve sayı bulunur; ortalama hesaplanır; ikinci döngüde listedeki her değerin ortalamadan farkının karesi toplanır; sonuç $n-1$'e bölünüp karekökü alınır (ekrandan, 00:45:00; 02:15:00).
  - Bir grubun kodunda kareler toplamı $n-1$ yerine $n$'e bölünür, yani örneklem değil kitle standart sapması hesaplanır (ekrandan, 01:10:00).
  - Tek geçişli yöntem: mapper her değeri "1" ile birlikte yayar; reducer toplamı, kareler toplamını ve eleman sayısını aynı döngüde biriktirir. Varyans $\dfrac{\sum x^2 - (\sum x)^2 / n}{n-1}$ formülüyle bulunur, karekökü standart sapmadır. Aynı değerden birden çok varsa reducer'a o değer anahtar olarak ve tekrar sayısı kadar değerle gelir.
  - Bir öğrenci her map görevinin kısmi kare farklarını bulup reducer'da bunları özel bir formülle birleştiren paralel bir algoritma kullandığını söyledi. <!-- BELİRSİZ: birleştirme formülü ekranda ya da altyazıda verilmedi; öğrenci yöntemi yaklaşık sonuç veren sayısal bir yöntem olarak andı. -->
- Korelasyon
  - Bir grup şehir bazında iki sütun arasındaki korelasyonu hesapladı; çıktıda değerler yaklaşık −0,65 ile −0,18 arasındaki negatif sayılardır (ekrandan, 00:30:00).
- Performans analizi
  - Gruplar farklı analizler yaptı: fonksiyonların sürelerini birbiriyle karşılaştırma; aynı fonksiyonu 20 MB ve 500 MB gibi farklı veri boyutlarında çalıştırma; Hadoop ile bir programlama dilinde veriyi doğrudan belleğe alarak hesaplamayı karşılaştırma; süreleri 0-100 arasına min-max normalizasyonu ile ölçekleme.
  - Hadoop işi bitince sayaçlar (counters) yazdırır: GC süresi, CPU süresi, fiziksel ve sanal bellek anlık görüntüsü, okunan ve yazılan bayt sayısı. Bir grup bellek kullanımını bu sayaçlardan aldı (ekrandan, 01:40:00; 01:55:00).
  - Tek düğüm ile iki düğüm karşılaştırması yapan bir grup, aynı işin tek düğümlü kümede yaklaşık 8 dakika, iki düğümlü kümede saniyeler içinde bittiğini raporladı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
