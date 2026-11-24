# Ders 2 Çalışma Özeti

## Genel Konular

- Büyük ölçekli veri ve tek makine sınırı
  - Büyük veri, tek bir makinenin fiziksel belleğine, hatta tek bir diskine sığmayan veridir. Klasik makine öğrenmesi ve istatistik algoritmaları veriyi diskten belleğe getirip CPU'da işlemek üzere tasarlanmıştır.
  - Google örneği (ekrandan, 00:10:00): 10 milyar web sayfası, ortalama sayfa boyu 20 KB, toplam $10^{10} \times 20\,\text{KB} = 200\,\text{TB}$. Disk okuma hızı 50 MB/s iken yalnızca okuma süresi $200\,\text{TB} / 50\,\text{MB/s} = 4 \times 10^6\,\text{s} \approx 46$ gündür. Veriyle yararlı bir iş yapmak daha da uzun sürer.
  - Çözüm fikri: veriyi küçük parçalara bölüp çok sayıda düğümde saklamak, aynı fonksiyonu düğümlerde paralel çalıştırmak ve sonuçları birleştirmek.
- Küme (cluster) mimarisi (ekrandan, 00:15:00)
  - Düğümler ucuz, her yerden alınabilen sıradan donanımdır (commodity hardware); üzerlerinde Linux çalışır.
  - Bir rack (raf kabini) 16-64 sıradan Linux düğümü içerir. Raf içindeki her düğüm çifti arasında 1 Gbps bağlantı vardır; raflar daha pahalı bir anahtar (switch) üzerinden 2-10 Gbps omurga ile bağlanır.
  - 2011'de Google'ın yaklaşık 1 milyon makinesi olduğu tahmin ediliyordu.
- Küme hesaplamanın zorlukları
  - Düğüm arızaları (ekrandan, 00:20:00): bir sunucu ortalama 3 yıl (1000 gün) ayakta kalır. 1000 sunuculu kümede günde 1 arıza, 1 milyon sunuculu kümede günde 1000 arıza beklenir.
  - Veriyi kalıcı saklamak ve düğüm düşse bile erişilebilir tutmak gerekir.
  - Uzun süren bir hesaplama sırasında düğüm düşerse işin başka düğümde sürdürülmesi gerekir.
  - Ağ darboğazı: 10 TB veriyi 1 Gbps ile taşımak yaklaşık 1 gün sürer. Bu yüzden veri değil, hesaplama verinin yanına taşınmalıdır.
  - Dağıtık programlama zordur: düğüm sayısını bilmek, işleri dağıtmak, izlemek, sonuçları toplayıp birleştirmek gerekir.
- MapReduce'un bu zorluklara cevabı
  - Google mühendislerinin ortaya koyduğu modeldir.
  - Veriyi parçalar halinde birden çok düğümde yedekli (redundant) saklar: kalıcılık ve erişilebilirlik.
  - Hesaplamayı verinin bulunduğu düğüme götürür: veri hareketi en aza iner.
  - Basit bir programlama modeli sunar ve dağıtık hesaplamanın karmaşıklığını gizler.
- Dağıtık dosya sistemi (DFS)
  - Global dosya ad alanı, yedeklilik ve erişilebilirlik sağlar. Örnekler: Google GFS, Hadoop HDFS (ekrandan, 00:35:00).
  - Tipik kullanım: yüzlerce GB ile TB (hatta PB) düzeyinde dev dosyalar, veri yerinde nadiren güncellenir, okuma ve ekleme (append) yaygındır. Örnek: uygulama sunucusu (IIS, Apache Tomcat) log dosyaları.
  - DFS operasyonel veritabanı (MySQL, Oracle, MS SQL) değildir; düşük gecikmeli güncelleme için tasarlanmamıştır.
  - Dosya bitişik parçalara (chunk) bölünür (16-64 MB), her parça genellikle 2 ya da 3 kez kopyalanır, kopyalar farklı raflarda tutulmaya çalışılır (ekrandan, 00:40:00).
  - Parça sunucuları (chunk server) aynı zamanda hesaplama sunucusudur: "hesaplamayı veriye götür" (ekrandan, 00:30:00).
  - Ana düğüm (master node), HDFS'te NameNode: dosyaların hangi bloklardan oluştuğunu ve blokların nerede durduğunu tutan üst veriyi (metadata) saklar; kendisi de kopyalanabilir.
  - İstemci kütüphanesi: önce master'a sorup parça sunucularını öğrenir, sonra doğrudan parça sunucularına bağlanıp blokları alır ve birleştirir. Kullanıcı açısından iki temel işlem vardır: put (dosyayı yükle) ve get (dosyayı al).
- HDFS mimarisi örneği (ekrandan, 01:05:00)
  - NameNode üst verisi: dosya adı, kopya sayısı (numReplicas), blok kimlikleri. Örnek: `part-0` için `r:2, {1,3}`; `part-1` için `r:3, {2,4,5}`.
  - DataNode'lar blokları tutar; 1 ve 3 numaralı bloklar ikişer, 2, 4 ve 5 numaralı bloklar üçer kez farklı DataNode'larda bulunur.
  - Kopyalamanın düzenlenmesi (orkestrasyon) NameNode'un işidir.
- Isınma problemi: kelime sayma (word count)
  - Dev bir metin dosyasında (ör. 100 GB) her farklı kelimenin kaç kez geçtiğini bulmak (ekrandan, 00:45:00).
  - Uygulamalar: web sunucusu loglarından popüler URL'leri bulmak, arama uygulamasının loglarından terim istatistiği çıkarmak.
  - Durum 1: dosya belleğe sığmaz ama tüm `<kelime, sayı>` çiftleri sığar. Dosya diskten sırayla okunur, bellekteki bir hash tablosunda kelime varsa sayacı artırılır, yoksa eklenir.
  - Durum 2: `<kelime, sayı>` çiftleri bile belleğe sığmaz. Unix benzetmesi: `words(doc.txt) | sort | uniq -c` (ekrandan, 01:10:00). Bu durum MapReduce'un özünü yakalar ve doğal olarak paralelleştirilebilir.
- MapReduce programlama modeli
  - Map: girdiyi kayıt kayıt tarar, ilgilenilen şeyi çıkarır (word count'ta her kelime için `(kelime, 1)`).
  - Group by key (sort + shuffle): aynı anahtarlı çiftleri bir araya getirir; platform (Hadoop, Spark, Flink vb.) yapar.
  - Reduce: aynı anahtarın değer listesini toplar, özetler ya da dönüştürür (word count'ta toplama).
  - Biçimsel tanım (ekrandan, 01:25:00): $\text{Map}(k, v) \rightarrow \langle k', v' \rangle^*$ ve $\text{Reduce}(k', \langle v' \rangle^*) \rightarrow \langle k', v'' \rangle^*$. Her $(k, v)$ çifti için bir Map çağrısı, her farklı $k'$ için bir Reduce çağrısı vardır.
  - Girdi anahtarı bloğun kimliği (ör. C0), değeri bloğun içeriğidir.
  - Örnek: 5 kelimelik dizileri saymak (dil modeli). Map her 5 kelimelik diziyi `(dizi, 1)` olarak çıkarır, Reduce sayıları toplar (ekrandan, 01:35:00).
- Zamanlama ve veri akışı
  - Her parça için bir mapper çalışır. Ara (intermediate) anahtar-değer çiftleri yerel diske yazılır, DFS'e yazılmaz.
  - Bölümleme fonksiyonu (partitioning function) bir hash fonksiyonudur; her anahtarın hangi reducer'a gideceğini belirler (ekrandan, 01:45:00).
  - Reducer kendi anahtarlarını mapper'ların yerel disklerinden çeker, sıralayıp gruplar, Reduce'u uygular ve sonucu DFS'e yazar.
  - MapReduce ortamının işleri (ekrandan, 01:50:00): girdiyi bölmek, çalışmayı makinelere zamanlamak, group by key adımı, düğüm arızalarını ele almak, makineler arası iletişimi yönetmek.
  - Gerçek problemlerde çoğu zaman art arda birden fazla MapReduce aşaması (map, reduce, map, reduce, ...) bulunur.
- Koordinasyon ve arıza yönetimi
  - Master her görev için durum tutar: boşta (idle), sürmekte (in-progress), tamamlandı (completed). Boştaki görevleri işçilere atar.
  - Biten map görevi master'a ara dosyaların yerini ve boyutunu bildirir; master bunu reducer'lara iletir. Master işçileri periyodik olarak yoklayıp (ping) arızaları fark eder.
  - Map işçisi arızası: o işçideki tamamlanmış ve sürmekte olan map görevleri boşta durumuna alınır ve başka işçide yeniden zamanlanır (ekrandan, 02:00:00).
  - Reduce işçisi arızası: yalnız sürmekte olan görevler boşta durumuna alınır ve yeniden başlatılır; tamamlanmış reduce görevinin çıktısı DFS'te kopyalı olduğundan yeniden çalıştırılmaz.
  - Master arızası: MapReduce işi iptal edilir ve istemciye bildirilir.
  - Görev sayısı: genelde her parça için bir map görevi; reducer sayısı $R$, map sayısı $M$'den çok küçük tutulur çünkü her reducer'ın çıktısı DFS'e yazılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hesaplamayı veriye götürmek
  - Büyük veriyi ağ üzerinden taşımak çok pahalıdır; DFS'te parça sunucuları hesaplama sunucusu da olduğu için kod verinin olduğu yerde çalışır.
- Programcı yalnız Map ve Reduce yazar
  - Gruplama, sıralama, zamanlama, arıza yönetimi ve makineler arası iletişim platformun işidir. Map'te ne çıkarılacağını ve Reduce'ta ne yapılacağını bulmak yeterlidir; aynı mantık Hadoop, Spark ya da Flink üzerinde çalışır.
- Girdi ve çıktı DFS'te, ara sonuçlar yerel diskte
  - Girdi ve nihai sonuç önemlidir, güvenilir ve kopyalı depoda durmalıdır. Ara sonuçlar iş bitince kullanılmayacağı için DFS'e yazılırsa gereksiz yere kopyalanır.
- Arızada görev durumlarına göre davranış
  - Tamamlanmış reduce görevi yeniden çalıştırılmaz çünkü çıktısı DFS'te kopyalıdır; sürmekte olan ya da boştaki reduce görevleri başka düğümde yeniden çalıştırılır. Bu konu derste bir öğrenci sorusu üzerine ayrıca açıklandı.
- Linux boru hattı benzetmesi
  - `words | sort | uniq -c` sırasıyla Map, group by key ve Reduce adımlarına karşılık gelir.

## Kısa Tekrar Notları

- 200 TB / 50 MB/s $\approx$ 46 gün: tek makinede veriyi okumak bile çok uzun sürer.
- Rack: 16-64 düğüm, raf içi 1 Gbps, raflar arası 2-10 Gbps.
- 1000 sunucu: günde 1 arıza; 1 milyon sunucu: günde 1000 arıza.
- DFS: 16-64 MB parça, 2-3 kopya, kopyalar farklı raflarda.
- Master (NameNode) üst veriyi tutar; istemci master'dan yer öğrenir, veriyi doğrudan parça sunucusundan alır.
- DFS büyük, nadiren güncellenen, okuma ve ekleme ağırlıklı veri içindir; operasyonel veritabanı değildir.
- $\text{Map}(k,v) \rightarrow \langle k',v' \rangle^*$, $\text{Reduce}(k', \langle v' \rangle^*) \rightarrow \langle k',v'' \rangle^*$.
- Group by key platformun işidir; Map ve Reduce programcının.
- Ara çiftler yerel diske, girdi ve çıktı DFS'e.
- Partitioning function = hash(anahtar) ile reducer seçimi.
- Görev durumları: idle, in-progress, completed.
- Map işçisi düşerse completed ve in-progress map görevleri yeniden; reduce işçisi düşerse yalnız in-progress reduce görevleri yeniden; master düşerse iş iptal.
- Genelde parça başına bir map görevi; reducer sayısı çok daha az.

## Detaylı Açıklamalar

- Tek makinenin sınırı
  - Veri belleğe sığsa bile darboğaz disk okuma hızıdır. 200 TB'lık bir web taramasını 50 MB/s ile okumak $4 \times 10^6$ saniye, yani 46 günden fazla sürer; basit bir sayma işi için bile kabul edilemez. Bu yüzden veriyi çok sayıda makineye bölüp aynı işi her parçada paralel çalıştırmak gerekir.
- Küme ve arızalar
  - Veri merkezlerinde sıradan sunucular raf kabinlerine dizilir; raf içindeki düğümler bir anahtara, raf anahtarları da daha hızlı bir omurga anahtarına bağlanır. Sunucu sayısı arttıkça arıza artık istisna değil, günlük olaydır. Bu yüzden sistem hem veriyi kopyalayarak saklamalı hem de yarıda kalan işleri başka düğümde yeniden başlatabilmelidir. Ayrıca ağ bant genişliği sınırlı olduğundan büyük veri düğümler arasında taşınmamalıdır.
- Dağıtık dosya sistemi
  - Bir dosya DFS'e yüklendiğinde parçalara bölünür ve parçalar farklı parça sunucularına kopyalı olarak dağıtılır. Slayttaki örnekte C dosyası C0-C5 olmak üzere altı parçaya, D dosyası D0 ve D1 olmak üzere iki parçaya bölünmüştür; her parça iki farklı sunucuda bulunur, yani kopya sayısı 2'dir (ekrandan, 00:30:00). Kopyalar farklı raflara konur çünkü bir rafın anahtarı bozulursa o raftaki bütün düğümler erişilemez olur. İstemci dosyayı yalnız URI'siyle bilir; blokların yerini master'dan öğrenir, blokları doğrudan parça sunucularından çeker ve birleştirir.
- Kelime sayma ve MapReduce
  - Unix boru hattında `words` her kelimeyi ayrı satıra döker, `sort` aynı kelimeleri yan yana getirir, `uniq -c` her grubu tek satıra indirip sayısını yazar. MapReduce aynı üç adımı dağıtık yapar: Map her bloktan `(kelime, 1)` çiftleri üretir, platform aynı anahtarlı çiftleri gruplar, Reduce her grubun değerlerini toplar. Slayttaki örnekte "crew" iki kez, "the" üç kez, "space" bir kez geçer ve Reduce çıktısı `(crew, 2)`, `(space, 1)`, `(the, 3)` olur (ekrandan, 01:30:00). Reduce fonksiyonu toplama yerine çarpma, ortalama gibi başka bir toplulaştırma da olabilir.
- Paralel çalışma ve arıza yönetimi
  - Her map görevi kendi parçasını işler, çıktısını yerel diske yazar ve bölümleme fonksiyonu her anahtar için bir reducer seçer. Map bitince master bilgilendirilir, master da ilgili reducer'lara verinin hangi sunucuda ve hangi dosyada olduğunu söyler. Reducer veriyi çeker, sıralayıp gruplar, Reduce'u uygular ve çıktıyı DFS'e yazar. Bir işçi düştüğünde master görev durumlarına bakar: sonucu kaybolabilecek görevleri boşta durumuna alıp başka işçide, tercihen düşen düğümdeki blokların kopyalarını tutan sunucularda yeniden çalıştırır.
  <!-- BELİRSİZ: Hoca derste master ile HDFS NameNode'u aynı bileşen gibi anlattı (mapper'ın NameNode'a haber verdiği vb.). Klasik Hadoop'ta görev zamanlamasını HDFS NameNode değil, MapReduce'un ana bileşeni (JobTracker, sonraki sürümlerde YARN ResourceManager) yapar; slaytlar yalnız "master" der. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
