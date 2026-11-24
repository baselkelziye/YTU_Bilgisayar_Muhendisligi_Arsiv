# Ders 3 Çalışma Özeti

## Genel Konular

- MapReduce programlama modelinin tekrarı (kelime sayma örneği)
  - Girdi, anahtar-değer (key-value) çiftleridir: anahtar dosya parçasının kimliği, değer o parçanın içeriğidir.
  - Map adımı (programcı yazar): içeriği işler ve ara (intermediate) anahtar-değer çiftleri üretir. Kelime saymada her kelime için `(kelime, 1)` çifti çıkar.
  - Group by key adımı (MapReduce platformu yapar): aynı anahtara sahip çiftleri bir araya getirir, örneğin `(crew, [1, 1])`.
  - Reduce adımı (programcı yazar): bir anahtarın değer listesi üzerinde işlem yapar; kelime saymada değerler toplanır ve `(crew, 2)`, `(the, 3)` gibi sonuçlar yazılır (ekrandan, 00:15:00).
- Hadoop'ta WordCount programının yapısı
  - Mapper, gelen `Text` değeri dizgiye çevirir, `StringTokenizer` ile kelimelere ayırır ve her kelime için `(kelime, 1)` yazar.
  - Reducer, bir anahtarın değerleri üzerinde döngü kurup toplamı hesaplar ve `(kelime, toplam)` yazar.
  - Ana sınıf bir `Job` nesnesi oluşturur; Mapper ve Reducer sınıflarını, girdi/çıktı yollarını ve çıktı tiplerini (`Text`, `IntWritable`) ayarlayıp işi başlatır (ekrandan, 00:20:00).
- Map ve Reduce arasındaki veri akışı
  - Mapper ara çiftleri HDFS'e değil, kendi düğümünün yerel diskine yazar.
  - Platform kütüphanesi ara çiftleri anahtara göre gruplar, sıralar ve her reducer için ayrı dosyalara koyar.
  - Bir hash fonksiyonu hangi anahtarın hangi reducer'a gideceğini belirler; reducer'lar kendi dosyalarını mapper düğümlerinden kendi düğümlerine kopyalar.
  - Reducer'lar sonuçlarını dağıtık dosya sistemine (HDFS) yazar; böylece sonuç bir düğüm çökse de kaybolmaz.
- Birinci iyileştirme: Combiner
  - Sorun: "the" gibi çok geçen kelimeler binlerce `(the, 1)` çifti üretir; bunların ağ üzerinden reducer'a taşınması zaman alır.
  - Çözüm: reducer'ın yaptığı işin aynısı mapper düğümünde, combiner adlı ek bir fonksiyonla yapılır. Genelde reduce fonksiyonunun kodu aynen kullanılır.
  - Ekrandaki örnekte iki blok vardır; her mapper 6 çift üretir, combiner sonrası her bloktan 4 çift kalır (ekrandan, 00:40:00).
- Combiner'ın koşulu: değişme (commutative) ve birleşme (associative) özelliği
  - Toplama iki özelliği de sağlar: $a+b=b+a$ ve $(a+b)+c=a+(b+c)$ (ekrandan, 00:45:00).
  - Ortalama sağlamaz; parçaların ortalamalarının ortalaması genelde tüm verinin ortalamasına eşit değildir.
  - Ortalama, iki alt fonksiyona ayrılarak combiner'a uygun hâle getirilir: her parça için `(sum, count)` çifti hesaplanır; sonunda $\text{Average} = \dfrac{sum_1+sum_2+sum_3}{count_1+count_2+count_3}$ (ekrandan, 00:50:00).
  - Medyan böyle alt fonksiyonlara ayrılamaz; medyan için combiner kullanılamaz, bütün çiftler reducer'a taşınmak zorundadır.
- İkinci iyileştirme: Bölümleme (partition) fonksiyonu
  - Varsayılan bölümleme: $\text{hash(key)} \bmod R$; $R$ reducer sayısıdır, sonuç reduce işinin numarasını verir (ekrandan, 00:55:00).
  - Hash fonksiyonu programcı tarafından değiştirilebilir. Örneğin bir günlük (log) dosyasında URL sayılıyorsa $\text{hash(hostname(URL))} \bmod R$ kullanılarak aynı ana makineye (host) ait bütün URL'lerin aynı reducer'a gitmesi sağlanır.
- MapReduce gerçeklemeleri ve büyük veri ekosistemi
  - MapReduce fikri Google'dan çıkmıştır; Google'ın gerçeklemesi açık kaynak değildir. Açık kaynak karşılığı Hadoop'tur ve altında HDFS kullanır.
  - Ekosistem katmanları (ekrandan, 01:00:00): dosya sistemi (HDFS), küme kaynak yönetimi (Mesos/YARN), NoSQL (HBase, Cassandra, Accumulo), veri işleme (toplu işleme: MapReduce/Hadoop, Spark, Tez, Hama; akış işleme: Storm, S4, Samza; çizge işleme: Giraph), üst düzey soyutlamalar (Hive, Pig, Shark, MRQL, Phoenix, GORA) ve veri analitiği (Mahout/MLlib/MLbase).
  - Hive ve Pig gibi üst katmanlar ve Mahout gibi makine öğrenmesi kütüphaneleri, alttaki MapReduce işleme platformlarını kullanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Combiner fikrinin iyi anlaşılması
  - Hoca bunun önemli olduğunu ve uygulamada (dönem projesinde) kullanılmasını isteyeceğini söyledi. Combiner, aynı anahtarlı çok sayıda çifti tek çifte indirerek ağ trafiğini azaltır.
- Combiner yalnız değişme ve birleşme özelliği olan fonksiyonlarda çalışır
  - Fonksiyon bu özelliklere sahip değilse, bu özelliklere sahip alt fonksiyonlara ayrılıp ayrılamayacağına bakılır (ortalama = toplam / sayı). Ayrılamıyorsa (medyan) combiner kullanılamaz.
- Mapper ara sonuçları yerel diske yazar, reducer sonuçları HDFS'e yazar
  - Nihai sonucun kaybolmaması için dağıtık dosya sistemine yazılır.
- Slayttaki diyagramın eksikliği
  - Bir öğrencinin "Sort and Group kütüphanesi reduce tarafında çalışır" yorumu üzerine hoca, diyagramdaki kutuların yazdığı yere değil, platform kütüphanesinin toplam yaptığı işe bakılması gerektiğini söyledi: gruplama, sıralama ve dosyalara ayırma mapper tarafında, dosyaları kopyalama reducer tarafında yapılır.
- Hash fonksiyonunu geliştirici güncelleyebilir
  - Böylece verinin hangi reducer tarafından işleneceği yapılandırılabilir.

## Kısa Tekrar Notları

- Map ve Reduce programcıdan, Group by key platformdan gelir.
- Ara çiftler: mapper düğümünün yerel diski. Sonuç: HDFS.
- Reducer seçimi: $\text{hash(key)} \bmod R$.
- Combiner = mapper düğümünde çalışan "mini reducer"; genelde reduce koduyla aynıdır.
- Combiner koşulu: commutative + associative.
- Toplam: uygun. Ortalama: doğrudan değil, `(sum, count)` ile uygun. Medyan: uygun değil.
- Özel bölümleme: $\text{hash(hostname(URL))} \bmod R$ ile aynı host aynı reducer'a.
- Hadoop = açık kaynak MapReduce + HDFS. Spark da MapReduce tarzı bir işleme katmanıdır.
- Hive/Pig: HDFS üzerindeki veriye üst düzey (SQL benzeri ya da yordamsal) erişim; Mahout: makine öğrenmesi.

## Detaylı Açıklamalar

- **Kelime sayma akışı.** Büyük bir doküman parçalara bölünür ve her parça bir mapper'a verilir. Mapper parçadaki her kelime için `(kelime, 1)` üretir. Platform aynı anahtarları bir araya getirir; reducer her anahtarın değerlerini toplayarak o kelimenin bütün dokümandaki sayısını bulur. Ekrandaki örnekte `(crew, 1)` iki kez geçtiği için sonuç `(crew, 2)`, `(the, 1)` üç kez geçtiği için `(the, 3)` olur (ekrandan, 00:15:00). Sözde kodda map, değer metnindeki her kelime için `(w, 1)` yayar; reduce, değerler üzerinde `for each` döngüsüyle toplam alıp `(key, sum)` yazar.
- **WordCount ana sınıfı (ekrandan, 00:20:00).** Ekranda gösterilen ana sınıf aşağıdadır. Mapper ve Reducer sınıflarının kodu ayrı dosyalarda gösterildi, ancak karelerde okunmuyor; yalnız altyazıdaki anlatımı yukarıda verildi.

```java
public class WordCount {
    public static void main(String[] args) throws Exception {
        Job job = new Job(new Configuration(), "WordCount");
        job.setJarByClass(WordCount.class);
        job.setMapperClass(WordCountMapper.class);
        job.setReducerClass(WordCountReducer.class);
        FileInputFormat.addInputPath(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(IntWritable.class);
        job.waitForCompletion(true);
    }
}
```

<!-- BELİRSİZ: WordCountMapper ve WordCountReducer sınıflarının kodu karelerde görünmüyor; yalnız altyazıdaki anlatıma göre özetlendi. -->

- **Veri akışının ayrıntısı.** Diyagramda (ekrandan, 00:25:00 ve 00:35:00) girdi parçaları M düğümlerine gider, ara çiftler `k1:v k1:v k2:v` gibi üretilir, Group by Key sonrası `k1:v,v,v,v`, `k2:v`, `k3:v,v`, `k4:v,v,v`, `k5:v` grupları R düğümlerine gider. Hocanın anlatımına göre her grup ayrı bir küçük dosyaya konur; örneğin 10 farklı anahtar varsa 10 küçük dosya oluşur. Mapper tarafındaki kütüphane işini bitirince sinyal verir; anahtarlar hash fonksiyonundan geçirilerek hangi reducer'ın sorumlu olduğu bulunur ve o reducer, ilgili dosyayı mapper düğümünden kopyalar.

> **Ders sonrası not:** Hoca bu koordinasyonu ve bölümleme fonksiyonunu "name node" üzerinde gösterdi. Hadoop'ta NameNode yalnız HDFS'in üst verisini (metadata) tutar; bölümleme fonksiyonu büyük olasılıkla mapper görevinin içinde çalışır ve iş koordinasyonunu Hadoop 1'de JobTracker, Hadoop 2 ve sonrasında YARN ApplicationMaster yapar.

- **Combiner örneği (ekrandan, 00:40:00).** Blok 1'in değer sütunu B, C, D, E, D, B'dir. Mapper `(B,1) (C,1) (D,1) (E,1) (D,1) (B,1)` üretir; combiner bunları `(B,2) (C,1) (D,2) (E,1)` yapar. Blok 2'nin değerleri D, A, A, C, B, D'dir; combiner sonrası `(D,2) (A,2) (C,1) (B,1)` kalır. Shuffle sonrası reducer'a `(A,[2]) (B,[2,1]) (C,[1,1]) (D,[2,2]) (E,[1])` gelir ve sonuç `(A,2) (B,3) (C,2) (D,4) (E,1)` olur. Her bloktan taşınan çift sayısı 6'dan 4'e iner (python ile doğrulandı).
- **Neden ortalama doğrudan combiner olamaz?** Toplamda dizi iki parçaya bölünüp parçaların toplamları toplanırsa sonuç değişmez. Ortalamada ise iki parçanın ortalaması alınıp $\frac{ave_1+ave_2}{2}$ hesaplanırsa, parçalar eşit büyüklükte değilse sonuç bütün verinin ortalamasından farklı çıkar (ekrandan, 00:45:00). Çözüm, her parçada `(sum, count)` taşımaktır; reduce adımında toplamlar ve sayılar ayrı ayrı toplanır ve en sonda bölünür (ekrandan, 00:50:00).

> **Ders sonrası not:** Hoca ortalamanın "commutative ve associative olmadığını" söyledi. Daha kesin ifade şudur: ortalama işlemi parçalara bölünüp birleştirilemez (ortalamaların ortalaması genel ortalama değildir); bu yüzden doğrudan combiner olarak kullanılamaz.

- **Bölümleme fonksiyonu.** Varsayılan $\text{hash(key)} \bmod R$ anahtarları reducer'lara yayar. URL sayma örneğinde anahtar URL'dir; aynı üniversite alan adına ait birçok URL farklı reducer'lara dağılabilir. Programcı, URL'den host adını çıkaran bir fonksiyon yazıp $\text{hash(hostname(URL))} \bmod R$ kullanırsa aynı host'un bütün URL'leri aynı reducer'da işlenir ve aynı çıktı dosyasına düşer (ekrandan, 00:55:00). URL'lerin kendisi değişmez, yalnız hangi reducer'a gideceği değişir.
- **Büyük veri ekosistemi (ekrandan, 01:00:00).** Hoca, şeklin biraz eski olduğunu, bugün başka çerçevelerin de bulunduğunu söyledi. En altta HDFS gibi dağıtık dosya sistemleri, onun üstünde düğümlerin kaynaklarını yöneten Mesos/YARN vardır. NoSQL katmanı HDFS'in "üstünde" diye okunmamalıdır; hoca bu kutunun dağıtık NoSQL veritabanlarını gösterdiğini belirtti (MongoDB gibi örnekler de verdi). Veri işleme katmanında Hadoop MapReduce ve Spark HDFS'teki veriyi işler; Giraph çizge verisi, Storm, S4 ve Samza akış verisi içindir. Üst katmanda Hive ve Pig gibi araçlar, alttaki MapReduce platformlarını kullanarak HDFS'teki veriye üst düzey sorgu imkânı verir; en üstte Mahout gibi kütüphaneler makine öğrenmesi algoritmalarını yine bu katmanlar üzerinde çalıştırır.

> **Ders sonrası not:** Hoca HDFS'i "dağıtık veritabanı" diye andı; HDFS bir dağıtık dosya sistemidir. Hive ve Pig'in ikisini de "SQL benzeri" diye andı; şekilde de görüldüğü gibi Hive SQL benzeri (HiveQL), Pig ise yordamsal bir dildir (Pig Latin). Mesos/YARN için "düğümlerin canlılığını izleme" dedi; bunlar büyük olasılıkla daha genel olarak küme kaynak yöneticileridir (iş zamanlama ve kaynak dağıtımı).

- **Uygulama bağlamı.** Hoca, MapReduce modelini gerçekleyen çerçevelerle (Hadoop ya da Spark) çok düğümlü bir HDFS kümesi üzerinde tanımlayıcı istatistik fonksiyonlarının (ortalama, min-maks, aralık, standart sapma gibi) gerçeklenmesini istedi. Bu fonksiyonların combiner ile çalışabilmesi için ya değişme ve birleşme özelliği taşımaları ya da ortalamadaki gibi bu özellikte alt fonksiyonlara ayrılabilmeleri gerektiğini vurguladı. HDFS'e konan bir dosyanın parçalara (hoca 64 MB dedi) bölünüp farklı düğümlere dağıtıldığını hatırlattı.

> **Ders sonrası not:** Hoca HDFS blok boyutunu 64 MB olarak verdi; bu Hadoop 1'in varsayılanıdır, Hadoop 2 ve sonrasında varsayılan büyük olasılıkla 128 MB'tır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
