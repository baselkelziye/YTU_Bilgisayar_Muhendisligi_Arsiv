# Ders 3 Genişletilmiş Notu: MapReduce İyileştirmeleri: Combiner, Bölümleme Fonksiyonu ve Hadoop Ekosistemi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. MapReduce Programlama Modelinin Tekrarı
- 2. Hadoop'ta WordCount Programı
- 3. Map ile Reduce Arasındaki Veri Akışı
- 4. Birinci İyileştirme: Combiner
- 5. Combiner'ın Koşulu: Değişme ve Birleşme Özelliği
- 6. İkinci İyileştirme: Bölümleme Fonksiyonu
- 7. MapReduce Gerçeklemeleri ve Büyük Veri Ekosistemi
- 8. MapReduce ile Tanımlayıcı İstatistik Uygulaması
- Örnek Sorular
- Dersin Toparlaması

## 1. MapReduce Programlama Modelinin Tekrarı

Hoca derse, bir önceki derste konuşulan problemi hatırlatarak başladı: dağıtık olarak saklanan veriyi işlemek istiyoruz ve bunun için MapReduce programlama modelini uyguluyoruz. Model girdi olarak anahtar-değer (key-value) çiftleri alır. Büyük bir dokümanı düşünelim; dokümanın küçük bir parçası (chunk) değer olur, bu parçayı diğerlerinden ayıran kimlik de anahtar olur. Yani anahtar dosya parçasının kimliği, değer de o parçanın içeriğidir.

### 1.1 Üç adım

Model üç adımdan oluşur (ekrandan, 00:15:00):

- **Map (programcı yazar):** Girdiyi okur ve bir küme anahtar-değer çifti üretir. Bunlara ara (intermediate) anahtar-değer çiftleri denir. Hangi çiftlerin üretileceği probleme bağlıdır.
- **Group by key (platform yapar):** Aynı anahtara sahip bütün çiftleri bir araya toplar.
- **Reduce (programcı yazar):** Bir anahtara ait bütün değerleri toplar ve çıktı üretir.

Kelime sayma probleminde amaç, bir dokümanda her kelimenin kaç kez geçtiğini bulmaktır. Map fonksiyonu dosya içeriğinden kelimeleri tek tek çıkarır; her kelime anahtar, değer ise 1'dir. Çünkü kelime her göründüğünde sayısı bir artar. Bütün ara çiftler çıkarıldığında map kısmı biter.

Group by key adımı MapReduce platformu tarafından yapılır. Örneğin aynı anahtara sahip üç çift varsa, bunlar ayrı ayrı yazılmak yerine anahtar altında bir araya getirilir. Son adım olan reduce programcı tarafından yazılır ve değerler üzerinde bir işlem uygular. Kelime saymada bu işlem toplamadır.

### 1.2 Ekrandaki kelime sayma örneği

Ekrandaki örnekte büyük doküman dört parçaya bölünmüştür; her parçanın bir kimliği ve içeriği vardır (ekrandan, 00:15:00). Map adımı `(The, 1)`, `(crew, 1)`, `(of, 1)`, `(the, 1)`, `(space, 1)`, `(shuttle, 1)`, `(Endeavor, 1)`, `(recently, 1)` gibi çiftler üretir. Group by key adımından sonra `(crew, 1) (crew, 1)`, `(space, 1)`, `(the, 1) (the, 1) (the, 1)`, `(shuttle, 1)`, `(recently, 1)` gibi gruplar oluşur. Reduce adımı her grubun değerlerini toplar: `(crew, 2)`, `(space, 1)`, `(the, 3)`, `(shuttle, 1)`, `(recently, 1)`. Hoca "crew" için iki tane 1 olduğunu, bunların toplanıp 2 sonucunu verdiğini gösterdi. Sonunda reduce programı kelime sayma sonuçlarını yazar; bütün dokümanda geçen her kelime için bir sayı elde edilir.

### 1.3 Sözde kod

Hoca map ve reduce için sözde kodu anlattı. Map fonksiyonu aldığı değer metnindeki her kelime için bir `for each` döngüsü kurar ve her kelime için ilk elemanı kelime, ikinci elemanı 1 olan bir ara çift üretir. Reduce fonksiyonu bir anahtar ve ona ait değerleri alır; bu kez `for each` döngüsü değerler üzerinde döner ve toplamı hesaplar. Döngü bitince ilk elemanı anahtar, ikinci elemanı toplam olan çift dosyaya yazılır.

## 2. Hadoop'ta WordCount Programı

Hoca, bu modeli kendileri de programlayacakları için Eclipse'te bir Hadoop projesindeki örnek kodu gösterdi. Bağımlılık dosyalarının yapılandırmasını yapmadığı için editörde hatalar göründüğünü, yalnız örnek koda odaklanılması gerektiğini söyledi. Bu, MapReduce modelini kullanan en basit Hadoop programıdır ve üç parçadan oluşur: mapper, reducer ve ana sınıf.

### 2.1 Mapper

Mapper, değeri `Text` tipinde alır ve bir dizgiye (string) çevirir. Bu dizgiden bir `StringTokenizer` nesnesi oluşturulur; bu nesne büyük metindeki bütün kelimeleri içine alır. Tokenizer üzerinde bir `while` döngüsü kurulur; her adımda bir sonraki kelime alınır ve sınıfın alanı olarak tanımlanmış `word` değişkenine atanır. Ardından ara anahtar-değer çifti yazılır: anahtar kelime, değer 1.

### 2.2 Reducer

Reducer da programcı tarafından yazılır. Girdi olarak anahtarı ve değerleri alır. Değerler üzerinde bir `for` döngüsü kurar ve her değeri toplama ekler. Amaç her kelimenin sayısını bulmak olduğu için reduce fonksiyonu toplama işlemidir. Her anahtar için toplam bulununca sonuç dosya sistemine geri yazılır: anahtar kelime, değer de kelimenin dokümanda kaç kez geçtiğidir.

<!-- BELİRSİZ: WordCountMapper ve WordCountReducer sınıflarının kodu karelerde görünmüyor; bu iki bölüm altyazıdaki anlatımdan yazıldı. -->

### 2.3 Ana sınıf

Mapper ve reducer'ı çalıştırmak için `main` metodu olan bir sınıf gerekir. Bu sınıf bir `Job` nesnesi oluşturur, parametrelerini ayarlar ve işi başlatır. Ekranda gösterilen ana sınıf şudur (ekrandan, 00:20:00):

```java
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

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

Kod derlenmedi; Hadoop kütüphanelerini gerektiren bir parça olarak aktarıldı. Hoca, işlenecek metin dosyasının çok basit olabileceğini, herkesin kendi metin dosyasını kullanabileceğini söyledi. Amaç, mapper ve reducer'ı çalıştırıp basit bir metin dosyasındaki kelimelerin sayısını bulabilmektir.

> **Ek bilgi (derste anlatılmadı):** `new Job(Configuration, String)` yapıcısı yeni Hadoop sürümlerinde kullanımdan kaldırılmıştır (deprecated); yerine `Job.getInstance(conf, "WordCount")` kullanılır. Combiner tanımlamak için de `job.setCombinerClass(...)` çağrısı vardır.

## 3. Map ile Reduce Arasındaki Veri Akışı

Hoca, önceki derste gösterdiği diyagrama döndü (ekrandan, 00:25:00 ve 00:35:00). Diyagramda girdi satırında "Big document" parçalara bölünmüş, her parça bir M (mapper) düğümüne gitmiştir. Ara satırda `k1:v k1:v k2:v`, boş bir parça, `k1:v`, `k3:v k4:v`, `k4:v k5:v`, `k4:v`, `k1:v k3:v` çiftleri vardır. Group by Key adımından sonra gruplar `k1:v,v,v,v`, `k2:v`, `k3:v,v`, `k4:v,v,v`, `k5:v` olur ve her grup bir R (reducer) düğümüne gider; reducer'lar çıktı satırına yazar. Group by key kutusunda bu adımın içerdiği işlemler de yazılıdır: hash merge, shuffle, sort, partition.

### 3.1 Mapper tarafı

Her mapper büyük dokümanın bir parçasını işler ve ara anahtar-değer çiftleri üretir. Hoca burada önemli bir noktayı tekrarladı: mapper bu ara çiftleri dağıtık dosya sistemine (HDFS) değil, kendi düğümünün yerel diskine yazar.

Mapper ara çiftleri ürettikten sonra, aynı düğümde MapReduce platformunun kütüphanesi bu çiftler üzerinde group by key işlemini yapar. Aynı anahtarlı çiftler bir araya getirilir ve her grup bir reducer tarafından kopyalanacak şekilde ayrı bir dosyaya konur. Hoca'nın örneğiyle: group by key sonrasında 10 farklı anahtar grubu oluştuysa, burada 10 küçük dosya oluşur.

### 3.2 Reducer'ın seçilmesi ve kopyalama

Mapper tarafındaki kütüphane işini bitirince sinyal verir: "işim bitti, anahtarların adları bunlar, dosyaları hazırladım, reducer'lar gelip kopyalayabilir." Ardından anahtarlar bir hash fonksiyonundan geçirilir ve hash fonksiyonunun verdiği reducer numarasına göre hangi reducer'ın hangi anahtardan sorumlu olduğu bulunur. İlgili reducer'a, belirli bir IP adresindeki kendisiyle ilgili dosyayı gidip kopyalaması söylenir. Reducer'lar bu dosyaları mapper'ın bulunduğu düğümden kendi düğümlerine kopyalar.

Bir reducer birden fazla mapper'dan dosya kopyalar: birinci mapper'a gidip kendi çiftlerini, ikinci mapper'a gidip kendi çiftlerini alır ve bu böyle devam eder. Bütün çiftler ilgili mapper'lardan reducer'ın düğümüne kopyalanınca reducer, reduce fonksiyonunu değerler üzerinde uygular. Kelime saymada bu toplama işlemidir: farklı mapper düğümlerinden gelen değerler toplanır, anahtar yine anahtar olarak, toplam da değer olarak yazılır.

> **Ders sonrası not:** Hoca bu koordinasyonu ve bölümleme (partitioning) fonksiyonunu "name node" üzerinde gösterdi. Hadoop'ta NameNode yalnız HDFS'in üst verisini (hangi bloğun hangi düğümde olduğu) tutar. Bölümleme fonksiyonu büyük olasılıkla mapper görevinin içinde çalışır; iş ve görev koordinasyonunu Hadoop 1'de JobTracker, Hadoop 2 ve sonrasında YARN'ın ApplicationMaster'ı yapar.

### 3.3 Sonuçların HDFS'e yazılması

Her reducer farklı anahtar-değer çiftlerini dağıtık dosya sistemine yazar. Bunun nedeni önceki derste konuşulmuştu: MapReduce işinin sonucu kaybolmasın diye. Bir metinde bin farklı kelime varsa bunların bir kısmı birinci reducer, bir kısmı ikinci, bir kısmı üçüncü reducer tarafından hesaplanıp yazılır. Ama yazılan bütün çiftlere bakıldığında her kelimenin bütün dokümanda kaç kez geçtiği bulunabilir. Diyagram yalnız bir mapper'ı değil, düğümlerde çalışan birçok mapper'ı da gösterir.

### 3.4 Diyagramdaki eksiklik

**Soru:** Bir öğrenci, diyagrama bakarak "Sort and Group" kütüphanesinin reduce tarafında çalıştığını söyledi. **Cevap:** Hoca diyagramda eksiklik olduğunu belirtti. Kutuların üzerinde yazana değil, kütüphanenin toplamda yaptığı işe bakılmalıdır. Mapper tarafında platform kütüphanesi anahtar-değer çiftlerini gruplar, sıralar ve her reducer için ayrı dosyalara koyar, sonra sinyal verir. Reducer tarafındaki kütüphane sinyali alınca ilgili mapper'dan dosyayı kendine kopyalar; bu kopyalama diğer mapper'lardan da yapılır. Sonunda her reducer'ın elinde sorumlu olduğu anahtarlar ve bu anahtarların değer listeleri olur ve reduce işlemini bunların üzerinde yapar.

## 4. Birinci İyileştirme: Combiner

### 4.1 Problem: ağ üzerinden taşınan çok sayıda aynı çift

Geçen derste bir problem ortaya konmuştu. Mapper anahtar-değer çiftlerini üretip her reducer için ayrı bir dosyaya koyuyor, reducer da bu dosyayı kendi düğümüne kopyalayıp reduce fonksiyonunu uyguluyordu. Ama "the" gibi bazı kelimeler dokümanda çok kez geçer. Bu durumda ilk elemanı "the", ikinci elemanı 1 olan binlerce çift oluşur. Reducer bu büyük dosyayı yerel ağ üzerinden almak ve kendi düğümüne kopyalamak zorunda kalır. Düğümler arası iletişim zaman alır; bunu istemeyiz. Amaç, iletişime harcanan zamanı azaltmaktır.

### 4.2 Çözüm: mapper düğümünde reduce işi

Çoğu durumda aynı anahtara sahip ara çiftlerin sayısı çok büyüktür. Büyük bir dosyayı reducer'a göndermek yerine reducer'ın yaptığı işin aynısını mapper düğümünde yapmaya çalışırız. Reducer'ın yaptığı iş toplamaydı; aynı işi mapper tarafında combiner adlı yeni bir metotla yaparız.

Combiner'ı da programcı yazar. Combiner bir anahtar ile o anahtara ait değerlerin listesini alır ve reducer'ın yapacağı işin aynısını yapar: reduce fonksiyonunu değer listesine uygular. Bu yüzden combiner için genellikle reduce fonksiyonunun aynısı kullanılır.

### 4.3 Ekrandaki örnek

Slaytta kelime sayma örneğine dönülür ve "Combiner, tek bir mapper'ın (tek düğümün) bütün anahtarlarının değerlerini birleştirir" denir (ekrandan, 00:40:00). İki blok vardır; her bloğu bir mapper işler. Hoca yalnız değerler sütununa bakılmasını istedi.

| Adım | Blok 1 | Blok 2 |
|---|---|---|
| Girdi (anahtar, değer) | (A,B) (A,C) (A,D) (B,E) (B,D) (C,B) | (C,D) (C,A) (D,A) (E,C) (E,B) (E,D) |
| Mapper çıktısı | (B,1) (C,1) (D,1) (E,1) (D,1) (B,1) | (D,1) (A,1) (A,1) (C,1) (B,1) (D,1) |
| Combiner çıktısı | (B,2) (C,1) (D,2) (E,1) | (D,2) (A,2) (C,1) (B,1) |

Shuffle sonrasında reducer'a gelen gruplar `(A,[2])`, `(B,[2,1])`, `(C,[1,1])`, `(D,[2,2])`, `(E,[1])` olur ve reducer sonucu `(A,2)`, `(B,3)`, `(C,2)`, `(D,4)`, `(E,1)` olarak yazar (ekrandan, 00:40:00).

Hoca adım adım şöyle anlattı: Blok 1'in mapper'ı harfleri çıkarır; B için iki çift, D için iki çift vardır. Combiner olmasaydı B ve D için ikişer çift reducer'a gönderilecekti. Combiner, reducer'ın yapacağı gibi aynı anahtarın değerlerini toplar: B'nin değerleri toplanıp `(B,2)`, D'nin değerleri toplanıp `(D,2)` elde edilir. Normalde 6 çift taşınacakken artık mapper düğümünden reducer'a 4 çift taşınır. Slayttaki ana mesaj: kopyalanması ve karıştırılması (shuffle) gereken veri çok azalır.

Sonuçlar python ile doğrulandı: her blokta 6 çift combiner sonrası 4 çifte iner ve harf sayıları reducer çıktısıyla aynıdır.

Böylece programcı artık yalnız mapper ve reducer'ı değil, combiner fonksiyonunu da yazar. MapReduce platformu yine çiftleri anahtara göre gruplar ve bunlar reducer'a gönderilir; ama mapper düğümünden reducer düğümüne çok daha az veri taşınmış olur.

### 4.4 Hocanın Türkçe özeti

> **Hocanın vurgusu:** Bunu anlamak önemlidir ve uygulamada kullanılması istenecektir. Bütün anahtar-değer çiftlerini reducer'a taşımak istemiyorsak, reducer'ın değerler üzerinde yaptığı işi combiner fonksiyonuyla yaparız. Combiner, reducer fonksiyonu değerler üzerinde ne yapıyorsa onu yapar ve aynı anahtarlı çiftleri tek bir çifte dönüştürür.

Reducer, bir mapper'dan aynı anahtarlı çok sayıda çift almak yerine, onları temsil eden ve combiner'ın ürettiği tek çifti alır. Farklı makinelerden gelen, combiner'dan geçmiş çiftler üzerinde son reduce işlemini yapar. Combiner'ın içine yazılan kod, reduce fonksiyonunun içine yazılan kodla aynıdır. Dikkat edilmesi gereken tek şey, fonksiyonun değişme ve birleşme özelliklerini sağlamasıdır.

## 5. Combiner'ın Koşulu: Değişme ve Birleşme Özelliği

Combiner fikri yalnız reduce fonksiyonu değişme (commutative) ve birleşme (associative) özelliğine sahipse çalışır. Hoca bunu açıklamak için slayt üzerine çizim yaptı (ekrandan, 00:45:00).

### 5.1 Toplama

Toplamanın değişme özelliği vardır: elemanların yerleri değişse de sonuç değişmez, $a+b=b+a$. Birleşme özelliği de vardır: $(a+b)+c=a+(b+c)$. Bir dizi tamsayının hepsini tek adımda toplayabiliriz. Ya da diziyi ikiye bölüp ilk yarıyı bir yerde, ikinci yarıyı başka yerde toplayıp sonra iki sonucu toplayabiliriz. İki yol aynı toplamı verir. Bir fonksiyon hem değişme hem birleşme özelliğine sahipse combiner olarak kullanılabilir.

### 5.2 Ortalama

Her fonksiyon bu özelliklere sahip değildir. Ortalamaya bakalım. Bir tamsayı dizisinin ortalaması tek adımda alınabilir. Ya da dizi ikiye bölünür, ilk parçanın ortalaması $ave_1$, ikinci parçanın ortalaması $ave_2$ bulunur ve bu ikisinin ortalaması $\frac{ave_1+ave_2}{2}$ alınır (ekrandan, 00:45:00). Hoca bu sonucun bütün sayıların tek adımda ortalamasıyla aynı olmayacağını söyledi ve slaytta bunu çarpıyla işaretledi. Bu yüzden ortalama fonksiyonu olduğu gibi combiner olarak kullanılamaz.

> **Ders sonrası not:** Hoca ortalamanın "toplama gibi commutative ve associative olmadığını" söyledi. Daha kesin ifadeyle sorun, ortalamaların ortalamasının genel ortalamaya eşit olmamasıdır (parçalar eşit büyüklükte değilse). Yani ortalama, parçalara bölünüp aynı fonksiyonla birleştirilemez.

### 5.3 Ortalamayı alt fonksiyonlara ayırmak

Fonksiyon değişme ve birleşme özelliğine sahip değilse, onu bu özelliklere sahip alt fonksiyonlara ayırıp ayıramayacağımıza bakarız. Ortalama, toplamın sayıya bölümüdür: $ave = sum / count$ (ekrandan, 00:50:00). İki alt fonksiyonu vardır: sayıları toplamak ve sayıları saymak. İkisi de toplama gibi davranır.

Bu durumda ortalama yerine `(sum, count)` çiftleri hesaplanır. Slayttaki çizimde dizi üç parçaya bölünmüştür. Her parçada ortalama yerine `(sum, count)` çifti bulunur: ilk eleman için parçadaki sayılar toplanır, ikinci eleman için sayılar sayılır. Bu üç parça için de yapılır: $(sum_1, count_1)$, $(sum_2, count_2)$, $(sum_3, count_3)$. Reduce adımında toplamlar kendi aralarında, sayılar kendi aralarında toplanır ve en sonda bölme yapılır (ekrandan, 00:50:00):

$$\text{Average} = \frac{sum_1 + sum_2 + sum_3}{count_1 + count_2 + count_3}$$

Böylece ortalama fonksiyonunun kendisi için değil, alt fonksiyonları için combiner yazılabilir.

### 5.4 Medyan

Bazı fonksiyonlar için combiner yazılamaz. Medyan (ortanca) için, değişme ve birleşme özelliğine sahip alt fonksiyonlar bulmanın bir yolu yoktur (ekrandan, 00:50:00). Böyle fonksiyonlarda combiner'ın avantajından yararlanılamaz; bütün anahtar-değer çiftleri reducer'a taşınmak zorundadır ve reducer işini eskisi gibi yapar.

> **Ek bilgi (derste anlatılmadı):** Bu tür ayrıştırılabilen fonksiyonlara literatürde "cebirsel" (algebraic) ya da "dağıtılabilir" (distributive) toplama fonksiyonları denir. Toplam, sayı, min ve maks dağıtılabilir; ortalama ve varyans sabit sayıda ara değerle (örneğin toplam, kareler toplamı, sayı) hesaplanabildiği için cebirseldir; medyan ise bütün veriye ihtiyaç duyduğu için bu sınıflara girmez.

## 6. İkinci İyileştirme: Bölümleme Fonksiyonu

MapReduce modelinde yapılabilecek ikinci iyileştirme, anahtarların reducer'lara nasıl bölüştürüleceğini denetlemektir. Slayttaki başlık şudur: anahtarların nasıl bölümlendiğini, yani tek bir reduce işçisine hangi anahtar kümesinin gideceğini denetlemek istiyoruz (ekrandan, 00:55:00).

### 6.1 Varsayılan bölümleme

Sistem varsayılan olarak şu bölümleme fonksiyonunu kullanır (ekrandan, 00:55:00):

$$\text{hash(key)} \bmod R$$

Anahtar hash fonksiyonuna verilir, bir değer elde edilir ve bu değerin reducer sayısı $R$'ye göre modu alınır. Sonuç, reduce işinin kimliğini gösteren bir tamsayıdır. O reduce işine haber verilir ve gidip o anahtar-değer çiftini alır.

### 6.2 URL örneği

Diyelim ki içinde çok sayıda URL bulunan bir günlük (log) dosyamız var ve her URL'nin bu dosyada kaç kez geçtiğini bulmak istiyoruz. Bu kez kelime yerine URL aranır, yani anahtar URL'dir. Aynı ana makine (host) adına ait çok sayıda URL olabilir; örneğin aynı üniversite alan adından birçok URL. Aynı host'a ait bütün URL'lerin aynı reducer'a gitmesi isteniyorsa bölümleme fonksiyonu güncellenir. URL'yi girdi alıp host adını üreten bir fonksiyon yazılır ve şu kullanılır (ekrandan, 00:55:00):

$$\text{hash(hostname(URL))} \bmod R$$

Bu, aynı host'tan gelen URL'lerin aynı çıktı dosyasına düşmesini sağlar.

Hoca bunu Türkçe de özetledi: URL'lerin kendisi değişmez, yalnız URL'nin hangi host'a ait olduğuna bakılarak aynı host'taki URL'lerin aynı reducer tarafından işlenmesi sağlanır. Bunun için hash fonksiyonu güncellenir.

> **Hocanın vurgusu:** MapReduce programı yazarken, MapReduce'un kullandığı hash fonksiyonu da geliştirici tarafından güncellenebilir. Böylece verinin hangi reducer tarafından ve ne şekilde işleneceği yapılandırılabilir.

## 7. MapReduce Gerçeklemeleri ve Büyük Veri Ekosistemi

### 7.1 Gerçeklemeler

MapReduce platformunun farklı gerçeklemeleri vardır. MapReduce paradigması ilk olarak Google'dan çıkmıştır, ama Google'ın gerçeklemesi açık kaynak bir kütüphane değildir. Bunun yerine Hadoop adlı açık kaynak bir kütüphane vardır ve Hadoop altında HDFS kullanır. Hadoop'un üzerinde çalışan, HDFS'teki veriye SQL işlemleri uygulamayı sağlayan başka kütüphaneler de vardır. Hadoop ortamı birçok bulut platformunda hazır kurulu olarak gelir; ya da Hadoop/HDFS ortamı kendi bilgisayarımıza indirilip kurulabilir.

> **Ders sonrası not:** Hoca ilk MapReduce paradigmasının "Google file system"den geldiğini söyledi. Doğrusu: MapReduce, Google'ın ayrı bir programlama modeli ve sistemidir; altında dağıtık dosya sistemi olarak Google File System (GFS) kullanılır. Hadoop'ta bu ikisinin açık kaynak karşılıkları Hadoop MapReduce ve HDFS'tir.

### 7.2 Ekosistem katmanları

Hoca, Hadoop ile birlikte kullanılabilen yazılımları gösteren bir şekil açtı ve şeklin biraz eski olduğunu, bugün açık kaynak büyük veri çerçevelerinin daha fazla olduğunu, ama fikir vereceğini söyledi. Şekildeki katmanlar aşağıdan yukarıya şöyledir (ekrandan, 01:00:00):

| Katman | Şekildeki örnekler |
|---|---|
| Dosya sistemleri | HDFS |
| Küme kaynak yönetimi | Mesos / YARN |
| NoSQL | HBase (HDFS üzerinde veri), Cassandra (Amazon Dynamo), Accumulo (HDFS üzerinde veri) |
| Veri işleme, toplu (batch) | MapReduce (Hadoop), Spark (yinelemeli MR), Tez (DAG), Hama (BSP) |
| Veri işleme, akış (stream) | Storm, S4, Samza |
| Veri işleme, çizge | Giraph |
| Üst düzey soyutlamalar | Hive (Hadoop üzerinde SQL), Pig (yordamsal dil), Shark (Spark üzerinde SQL), MRQL (Hadoop, Hama, Spark üzerinde SQL), Phoenix (HBase üzerinde SQL), GORA (NoSQL için bellek içi nesne eşleme) |
| Veri analitiği | Mahout / MLlib / MLbase |
| Yan araçlar | Bulut uygulama dağıtımı (Whirr/JClouds), iletişim (Netty, ZeroMQ, ActiveMQ, Kafka vb.), dağıtık koordinasyon (ZooKeeper, JGroups, Hazelcast), mesaj protokolleri (Thrift) |

Hoca katmanları şöyle anlattı:

- **Dosya sistemi:** HDFS ve başka dağıtık dosya sistemleri. HDFS önceki derste konuşulmuştu.
- **Yönetim kütüphanesi:** Böyle dağıtık bir yapı varsa, dağıtık düğümlerin canlılığını takip edebilen bir yönetim kütüphanesi gerekir. YARN ya da Mesos ile mevcut HDFS düğümlerinin varlığı izlenebilir; HDFS kullanıldığında genelde bunlardan yararlanılır.
- **NoSQL:** Bu da bir veri saklama katmanıdır. Hoca, şekildeki NoSQL katmanının HDFS'in "üstünde" diye okunmaması gerektiğini, NoSQL kutusundan HDFS'e kadar uzanan alanın aslında dağıtık NoSQL veritabanlarını ifade ettiğini söyledi. Bunların hepsi farklı veritabanlarıdır; MongoDB de örnek olarak verildi. <!-- BELİRSİZ: Hocanın saydığı NoSQL adlarının bir kısmı altyazıda bozuk ("Yoma", "akumulu", "KaoşDB"); şekildeki HBase, Accumulo ve Cassandra olması muhtemel. -->
- **Veri işleme:** Hadoop, HDFS'te duran veriyi işleyen bir veri işleme katmanıdır; Spark da örneğin HDFS'teki veriyi işleyen bir katmandır. Giraph çizge verisi üzerinde büyük veri işleme yapar; Storm, Samza gibi kütüphaneler akış işleme için tasarlanmıştır. Derste ilgilenilen, MapReduce modelini kullanan işleme platformlarıdır: Spark bunlardan biri, Hadoop bir diğeridir.
- **Üst düzey veri işleme:** Hive ve Pig, HDFS'teki veriye ifadeler uygulamayı sağlayan bir programlama arayüzü sunar. Bunlar da kendi içlerinde alttaki MapReduce işleme platformlarını kullanır, yani onların üzerine gerçeklenmiştir.
- **Veri analitiği:** En üstte, örneğin Mahout, makine öğrenmesi ya da derin öğrenme algoritmalarını gerçekler. Bu kütüphaneler de HDFS üzerindeki MapReduce işleme kütüphanelerini kullanır.

> **Ders sonrası not:** Hoca HDFS'i bir yerde "dağıtık veritabanı" diye andı; HDFS bir dağıtık dosya sistemidir. Hive ve Pig'in ikisini de "SQL benzeri" diye andı; şekilde de yazdığı gibi Hive SQL benzeri bir dil (HiveQL) sunar, Pig ise yordamsal bir dildir (Pig Latin). Mesos ve YARN büyük olasılıkla yalnız düğüm canlılığını izlemekle kalmaz; küme kaynaklarını (CPU, bellek) işlere dağıtan kaynak yöneticileridir.

Hoca, bu şeklin büyük veri işleme için yaygın kullanılan çerçeve kütüphanelerini gösterdiğini, kaynağın yayımlandığı günden bu yana çok daha farklı çerçevelerin de üretildiğini belirtti. MapReduce bir programlama modeli olduğu için, bu modeli gerçekleyen çerçevelerin kullanılacağını söyledi.

## 8. MapReduce ile Tanımlayıcı İstatistik Uygulaması

Aradan sonra hoca, MapReduce modelini kullanan bir uygulamanın teknik çerçevesini anlattı (ekrandan, 01:15:00 ve 01:20:00). Bu bölümde yalnız teknik kısım aktarılmıştır.

- Veri HDFS üzerinde durur; işleme platformu Hadoop ya da Spark olabilir. Spark kullanılıyorsa önce çok düğümlü bir HDFS kümesi kurulur, Spark onun üzerine kurulur. Tek düğümlü değil, çok düğümlü (örneğin iki düğümlü) bir küme istenir; sanal makineler ya da bulut kullanılabilir.
- Yerel dosya sisteminden bir dosyayı HDFS'e koyan ve kimliğiyle geri alan bir kullanıcı arayüzü yazılır.
- Dosya HDFS'e konduğunda HDFS onu parçalara böler (hoca 64 MB dedi) ve bazı parçaları birinci düğümde, bazılarını ikinci düğümde saklar. Arayüz, dosyanın parçalarının hangi düğümlerde saklandığını göstermelidir.
- MapReduce modeliyle en az beş farklı tanımlayıcı istatistik fonksiyonu gerçeklenir; örnekler: ortalama, min-maks, aralık (range), standart sapma.
- Seçilen fonksiyonun tek düğümde ve çok düğümde ne kadar sürede tamamlandığı ölçülerek performans çözümlemesi yapılır.
- Java yerine Scala ya da Python da kullanılabilir; ama kodda mapper, combiner ve reducer fonksiyonları mutlaka bulunmalıdır.

> **Hocanın vurgusu:** Gerçeklenecek istatistik fonksiyonları ya değişme ve birleşme özelliğine sahip olmalı ya da ortalamada yapıldığı gibi bu özelliklere sahip alt fonksiyonlara ayrılabilmelidir; böylece combiner kullanılabilir.

> **Ders sonrası not:** 64 MB, Hadoop 1'in varsayılan HDFS blok boyutudur; Hadoop 2 ve sonrasında varsayılan büyük olasılıkla 128 MB'tır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:40:00): İki bloktan oluşan girdide değerler Blok 1 için B, C, D, E, D, B; Blok 2 için D, A, A, C, B, D'dir. Kelime (harf) sayma işinde combiner kullanılırsa her mapper düğümünden reducer'a kaç çift gider, reducer'ın son çıktısı nedir?

> **Çözüm (derste verildi):** Blok 1 mapper'ı 6 çift üretir: (B,1) (C,1) (D,1) (E,1) (D,1) (B,1). Combiner aynı anahtarları toplar: (B,2) (C,1) (D,2) (E,1), yani 4 çift. Blok 2: (D,1) (A,1) (A,1) (C,1) (B,1) (D,1) → (D,2) (A,2) (C,1) (B,1), yine 4 çift. Shuffle sonrası (A,[2]) (B,[2,1]) (C,[1,1]) (D,[2,2]) (E,[1]); reducer çıktısı (A,2) (B,3) (C,2) (D,4) (E,1). Combiner'sız 12 çift taşınacakken combiner ile 8 çift taşınır.

**Soru 2** (ekrandan, 00:45:00 ve 00:50:00): Combiner yalnız reduce fonksiyonu değişme ve birleşme özelliğine sahipse çalışır. Toplam, ortalama ve medyan için combiner kullanılabilir mi?

> **Çözüm (derste verildi):** Toplam: evet, $a+b=b+a$ ve $(a+b)+c=a+(b+c)$ sağlanır; parça toplamlarının toplamı genel toplamdır. Ortalama: doğrudan hayır, çünkü $\frac{ave_1+ave_2}{2}$ genelde genel ortalamaya eşit değildir; ama her parça için $(sum, count)$ taşınırsa evet: $\text{Average} = \frac{sum_1+sum_2+sum_3}{count_1+count_2+count_3}$. Medyan: hayır, bu özelliklere sahip alt fonksiyonlara ayrılamaz; bütün çiftler reducer'a gitmelidir.

**Soru 3** (ekrandan, 00:55:00): Bir günlük dosyasında URL'lerin kaç kez geçtiği sayılıyor. Aynı host'a ait bütün URL'lerin aynı çıktı dosyasına düşmesi için bölümleme fonksiyonu nasıl seçilmelidir?

> **Çözüm (derste verildi):** Varsayılan $\text{hash(key)} \bmod R$ yerine $\text{hash(hostname(URL))} \bmod R$ kullanılır. URL'nin kendisi anahtar olarak kalır; yalnız reducer seçimi host adına göre yapılır.

**Soru 4** (derste sözlü, 00:31:13): Bir öğrenci, slayttaki diyagrama göre "Sort and Group" kütüphanesinin reduce tarafında çalıştığını söyledi. Doğru mu?

> **Çözüm (derste verildi):** Hoca diyagramın eksik olduğunu söyledi. Gruplama, sıralama ve her reducer için ayrı dosyalara koyma mapper tarafında platform kütüphanesince yapılır; reducer tarafındaki kütüphane sinyal gelince ilgili dosyaları mapper düğümlerinden kopyalar ve reduce işlemine hazırlar.

## Dersin Toparlaması

Bu derste MapReduce modelinin kelime sayma örneği üzerinden tekrarı yapıldı ve Hadoop'taki WordCount programının mapper, reducer ve ana sınıf yapısı gösterildi. Ardından map ile reduce arasındaki veri akışı ayrıntılandı: ara çiftler mapper düğümünün yerel diskine yazılır, platform bunları gruplayıp reducer başına dosyalara ayırır, reducer'lar bu dosyaları kopyalayıp sonucu HDFS'e yazar.

Dersin merkezinde iki iyileştirme vardı. Combiner, reduce işini mapper düğümünde önceden yaparak ağ üzerinden taşınan veriyi azaltır; ama yalnız değişme ve birleşme özelliği olan fonksiyonlarda (toplam) ya da bu özellikte alt fonksiyonlara ayrılabilen fonksiyonlarda (ortalama için toplam ve sayı) kullanılabilir; medyan gibi fonksiyonlarda kullanılamaz. Bölümleme fonksiyonu ise varsayılan $\text{hash(key)} \bmod R$ yerine programcının seçtiği bir hash ile hangi anahtarın hangi reducer'a gideceğini denetler. Son olarak Hadoop, Spark, NoSQL veritabanları, Hive/Pig ve Mahout gibi bileşenleri içeren büyük veri ekosistemi katmanlar hâlinde tanıtıldı ve bu kavramların tanımlayıcı istatistik fonksiyonlarını MapReduce ile gerçekleyen bir uygulamada nasıl kullanılacağı anlatıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
