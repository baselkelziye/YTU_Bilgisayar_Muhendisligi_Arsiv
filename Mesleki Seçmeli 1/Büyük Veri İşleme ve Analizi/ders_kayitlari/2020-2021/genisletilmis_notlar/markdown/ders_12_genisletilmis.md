# Ders 12 Genişletilmiş Notu: Proje Demoları: Hadoop Kümeleri, HDFS İstemcisi ve MapReduce ile İstatistiksel Fonksiyonlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Biçimi ve Projenin Teknik Bileşenleri
- 2. Hadoop Kümesinin Kurulması ve Gösterilmesi
- 3. HDFS İstemcisi: Yazma ve Okuma
- 4. Kullanıcı Arayüzü Tasarımları
- 5. MapReduce ile İstatistiksel Fonksiyonlar
- 6. Standart Sapmanın MapReduce Gerçekleştirimleri
- 7. Performans ve Ölçeklenebilirlik Analizi
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun Biçimi ve Projenin Teknik Bileşenleri

Bu kayıt bir konu anlatımı değildir; dönem projesinin demolarına ayrılmıştır. Öğrenci grupları sırayla Zoom'da ekran paylaşarak projelerini gösterdi, hoca da her gruba aynı sırayla teknik sorular sordu. Bu not, demolarda görülen teknik içeriği konu konu toplar. Sunanlar "bir grup" ya da "bir öğrenci" diye anılır; değerlendirme ve düzenle ilgili konuşmalar nota alınmamıştır.

Hocanın her demoda sırayla kontrol ettiği maddeler, bir Hadoop tabanlı büyük veri projesinin teknik bileşenlerini de özetler:

- **Küme:** tek düğümlü (single-node) ya da çok düğümlü (multi-node) bir Hadoop veya Spark kümesinin çalışır durumda olması.
- **HDFS istemcisi:** kullanıcı arayüzünden, yerel dosya sistemindeki bir dosyayı HDFS'e yazmak ve HDFS'teki bir dosyayı okuyup yerel dosya sistemine geri koymak.
- **İstatistiksel fonksiyonlar:** HDFS'teki bir veri kümesi üzerinde, kullanıcı arayüzünden çalıştırılan beş istatistiksel fonksiyonun MapReduce ile yazılmış sürümleri.
- **Performans analizi:** aynı fonksiyonların tek düğümlü ve iki düğümlü kümede çalıştırılıp karşılaştırılması.

Gruplar çok farklı veri kümeleri kullandı: ev satış fiyatları, şehirlere göre içki satışları, film ve anime puanları, Bitcoin ile ilgili tweet'ler (favori ve retweet sayıları), bir kripto para borsasından alınan coin fiyatları, ülkelere göre YouTube trend videoları ve düz metin dosyaları.

## 2. Hadoop Kümesinin Kurulması ve Gösterilmesi

### 2.1 Sanal makinelerle çok düğümlü küme

En yaygın kurulum, VirtualBox üzerinde Ubuntu sanal makineleriyle yapıldı: bir master ve iki slave. Master'da NameNode, slave'lerde DataNode çalışır. Kümenin ayakta olduğu NameNode web arayüzünden gösterildi. Datanodes sekmesinin "In operation" tablosunda iki düğüm (`hadoop-slave1`, `hadoop-slave2`) canlı görünür; her satırda son temas süresi, kapasite, blok sayısı, kullanılan blok havuzu ve Hadoop sürümü vardır. Bir kurulumda her düğüm 11,25 GB kapasiteli ve 3.2.2 sürümüdür (ekrandan, 00:15:00); başka bir kurulumda her düğüm 43,81 GB kapasiteli ve 3.2.1 sürümüdür (ekrandan, 00:35:00). Sayfadaki "Datanode usage histogram" grafiği düğümlerin disk kullanım yüzdesini gösterir.

Bir grup, kendi bilgisayarından da sanal makinedeki kümeye bağlanabildiğini, iki düğümün yükünü web arayüzünde görebildiğini gösterdi.

### 2.2 Docker ile küme

İki grup kümeyi Docker kapsayıcılarıyla kurdu. Bir grup bütün bileşenleri bir docker-compose dosyasına koydu: NameNode, üç DataNode, ResourceManager, NodeManager ve HistoryServer. Her birinin ayrı bir Dockerfile'ı vardır ve tek bir `docker-compose up` komutuyla hepsi ayağa kalkar. Grup, veriyi daha fazla düğüme dağıtmak için üç DataNode kullandığını söyledi. Komut penceresinde her kapsayıcının (`datanode1`, `datanode2`, `datanode3`) başlarken yazdığı ayarlar görülür; örneğin `dfs.datanode.data.dir=file:///hadoop/dfs/data`, `dfs.webhdfs.enabled=true`, `dfs.permissions.enabled=false`, `yarn.resourcemanager.hostname=resourcemanager`, `yarn.nodemanager.aux-services=mapreduce_shuffle` (ekrandan, 01:20:00).

Docker kullanan başka bir grup ise kullanıcı arayüzünü Docker'daki kümeye bağlayamadığını, bu yüzden işleri komut satırından çalıştırdığını anlattı.

### 2.3 Bulut ve tek düğüm

Bir öğrenci Amazon üzerinde dört düğümlü bir küme kurdu. Web arayüzüne makinenin DNS adresine port numarası eklenerek ulaşılıyordu. Ancak projeyi bu kümede çalıştıramadığı için demoyu yerel tek düğümlü kurulumla yapmak zorunda kaldı.

Tek düğümlü kurulumlarda bütün süreçler aynı makinede çalışır. Bir öğrencinin arayüzünde `jps` çıktısı NameNode, SecondaryNameNode, ResourceManager, DataNode ve NodeManager süreçlerini birlikte listeler (ekrandan, 01:00:00). Slave makinede `jps` çalıştırıldığında ise yalnız DataNode ve NodeManager görünür (ekrandan, 01:45:00).

### 2.4 Karşılaşılan kurulum sorunları

Demolarda çok düğümlü kurulumun pratik sorunları da görüldü:

- Bir grubun kümesinde bir düğüm iş sırasında takılıyor, yeniden başlatınca çalışıyordu; grup bunun makinenin yavaşlığından kaynaklandığını düşündü.
- Bir grubun HDFS'e dosya yüklerken sanal makinede disk alanı yetmedi (insufficient space hatası).
- Bir grup DataNode'un varsayılan portunda bağlantı kuramadı, portu değiştirdi ama web arayüzüne yine erişemedi.
- Windows üzerinde kurulum yapan bir öğrencinin komutları yönetici izni istediği için arayüzden çalışmadı.

## 3. HDFS İstemcisi: Yazma ve Okuma

### 3.1 Write ve read ayrımı

Hocanın demolarda en çok üzerinde durduğu nokta HDFS istemcisinin iki yönlü olmasıydı:

- **Write:** yerel dosya sistemindeki, HDFS'te henüz olmayan küçük bir dosyayı seçip HDFS'e koymak ve web arayüzünde (Browse Directory) dosyanın geldiğini göstermek.
- **Read:** HDFS'te duran bir dosyayı okuyup yerel dosya sistemine (örneğin ev dizinine ya da masaüstüne) koymak ve oraya geldiğini göstermek.

Birçok grup yalnız yazmayı yapmıştı. Bazı gruplar "read" olarak iş sonucunu arayüzde göstermeyi ya da dosyanın ilk beş satırını yazdırmayı anladı. Hoca bunların okuma işleminin yerini tutmadığını, kastettiğinin dosyayı HDFS'ten alıp yerel dosya sistemine kopyalamak olduğunu birçok kez açıkladı.

> **Hocanın vurgusu:** HDFS istemcisinden kasıt, kullanıcı arayüzü üzerinden hem HDFS'e dosya yazmak hem de HDFS'teki bir dosyayı alıp yerel dosya sistemine koyabilmektir.

### 3.2 Komut satırından HDFS

Arayüzü olmayan ya da arayüzü kümeye bağlayamayan gruplar aynı işlemleri komut satırından gösterdi. Kullanılan komutlar:

```text
hadoop fs -mkdir -p /inputs          # HDFS'te klasör oluşturma
hadoop fs -put <yerel dosya> <hdfs yolu>   # yerelden HDFS'e yazma
hadoop fs -ls <hdfs yolu>            # listeleme
hadoop fs -cat <hdfs yolu>/part-r-00000    # çıktı dosyasını okuma
hadoop fs -rmr <klasör>              # klasörü silme
hadoop jar <jar dosyası> <sınıf> <girdi> <çıktı>   # MapReduce işini çalıştırma
```

(ekrandan, 01:00:00; 01:40:00)

Bir grup HDFS'teki bir girdi dosyasını silmeye çalıştı ama silme izin vermeyince yeni dosyayı başka bir klasöre koydu. Bir öğrencinin arayüzü her iş için sonuna rastgele üç rakam eklenen bir klasör oluşturup girdiyi oraya koyuyor, iş bitince `part-r-00000` dosyasını okuyup ekrana yazıyordu.

### 3.3 İş çıktısı ve blok bilgisi

Bir MapReduce işi bitince çıktı klasöründe iki dosya oluşur: `_SUCCESS` (işin başarıyla bittiğini gösteren boş dosya) ve `part-r-00000` (reducer çıktısı). Web arayüzünde `part-r-00000` dosyasına tıklanınca açılan pencerede blok kimliği, blok havuzu kimliği, boyut (bu örnekte 14852 bayt) ve bloğun bulunduğu düğümler (`hadoop-slave2`, `hadoop-slave1`) görülür. Aynı pencerede dosyanın ilk ve son 32 KB'ı görüntülenebilir ya da dosya indirilebilir; bu örnekte içerik şehir adlarına göre ortalama değerlerdir (ekrandan, 00:20:00).

Bloğun iki slave'de birden görünmesi, HDFS'in blokları birden çok DataNode'a kopyaladığını (replikasyon) gösterir.

## 4. Kullanıcı Arayüzü Tasarımları

Gruplar arayüzü farklı teknolojilerle yazdı. Hepsinde ortak fikir, arayüz düğmelerinin arkasında Hadoop komutlarının çalıştırılmasıdır.

- **Python ile SSH:** bir grup arayüzü Python'da yazdı; uygulama kümeye SSH ile bağlanıyor, komutları çalıştırıyor ve dönen günlükleri satır satır ekrana basıyordu. Bağlanırken IP adresi ve kullanıcı bilgileri giriliyor, ardından HDFS'teki dosyalar listeleniyordu.
- **Java Swing:** bir arayüzde "Browse and Push to HDFS", "Delete File From HDFS", "Pull File from HDFS" ve "Open Operations" düğmeleri vardır (ekrandan, 00:50:00). Operations ekranında gruplama sütunu (örneğin şehir), hedef sayısal sütun (örneğin satış) ve istatistik fonksiyonu (örneğin ortalama) seçilip "Set Job" ile MapReduce işi başlatılır; sonuç "Save to Local" ile HDFS'ten yerele indirilebilir.
- **Basit Java arayüzleri:** bir arayüzde HDFS'teki dosyalar numaralı listelenir; "Add File" ile dosya eklenir, numara yazılıp "Get File" ile dosya yerele kopyalanır; "Average", "Median" ve "Standard Deviation" düğmeleri ilgili işleri çalıştırır (ekrandan, 02:05:00). Başka bir arayüzde "Add file to the hdfs", "Choose file" ve "max, average, stdev, median, sum" düğmeleri vardır; günlükte dosyanın HDFS'e eklendiği ve ilk beş satırının okunduğu görülür (ekrandan, 01:45:00).
- **REST servisi ve web ön yüzü:** bir grup Spring Boot ile bir REST sunucusu kurdu ve ona bağlanan bir web ön yüzü yazdı. Kullanıcı sunucunun IP adresini girer, dosyayı seçip HDFS'e yükler, sonra bir fonksiyon seçer. Ön yüz, sistemi yormamak için işin durumunu sunucuya üç saniyede bir sorar ve Mapper ile Reducer aşamalarının ilerlemesini iki halka olarak gösterir (ekrandan, 01:25:00). İş bitince sonuç dosyası okunur, JSON biçimine dönüştürülüp arayüzde gösterilir.

Bir grup MapReduce kodlarını önce Python ile yazdığını, ama çalışma süreleri uzun olduğu için Java'ya geçtiğini söyledi. Başka bir grup ise işleri Python ile Hadoop Streaming tarzında yazdı (bkz. 5.2).

## 5. MapReduce ile İstatistiksel Fonksiyonlar

### 5.1 Ortak kalıp

Bütün gruplarda kod aynı iskeleti izledi:

- **Driver (main sınıfı):** Hadoop işini oluşturur, mapper ve reducer sınıflarını, çıktı anahtar ve değer tiplerini ayarlar; komut satırındaki ilk argümanı girdi, ikincisini çıktı yolu olarak alır.
- **Mapper:** her satırı metne çevirir, virgülle böler (CSV), satırın beklenen sütun sayısında olup olmadığını kontrol eder, gruplama sütununu anahtar, sayısal sütunu değer olarak yayar. Ortalama gibi ondalıklı sonuçlar için değer `FloatWritable` ya da `DoubleWritable` olarak tutulur.
- **Reducer:** aynı anahtara ait değerleri (`Iterable`) alıp istatistiği hesaplar ve `context.write(anahtar, sonuç)` ile yazar.

Bir grup film puanları veri kümesinde dört sütun (kullanıcı kimliği, film kimliği, puan, zaman damgası) olduğunu, mapper'da film kimliğini anahtar, puanı `float`'a çevrilmiş değer olarak yaydığını anlattı. Başka bir grup her fonksiyonu ayrı bir Maven projesi olarak yazdı. Bir öğrenci ise tek bir reducer sınıfı yazıp hangi istatistiğin hesaplanacağını parametre olarak verdi.

### 5.2 Ortalama, sayma ve toplam

Ortalama için reducer gelen değerleri toplar, kaç değer geldiğini sayar ve toplamı sayıya böler. Bir grup mapper'da yılı anahtar, ev satış fiyatını değer olarak yaydı; çıktıda yıllara göre ortalama satış fiyatının arttığı görüldü. Sayma (count) fonksiyonu, örneğin her filmin kaç kez oylandığını ya da veri kümesinde her hisse adının kaç kez geçtiğini verir.

Ortalamayı combiner ile kullanan bir grup, mapper'da değerin yanına bir de "1" koydu. Combiner kısmi toplamları birleştirirken eleman sayısını da taşıdığı için ortalama bozulmaz. Bu grubun Python mapper'ı koşullu ortalama (average-if) için şöyle çalışır (ekrandan, 02:25:00):

```python
key_column_idx = sys.argv[1]      # anahtar sütununun indeksi ("None" olabilir)
if key_column_idx != "None":
    key_column_idx = int(key_column_idx)
value_column_idx = int(sys.argv[2])   # değer sütununun indeksi
compare_col1_idx = int(sys.argv[3])
compare_operator = sys.argv[4]
compare_col2_idx = int(sys.argv[5])

for line in sys.stdin:
    line = line.strip()
    if line != "":
        words = line.split(",")
        if eval(words[compare_col1_idx] + compare_operator + words[compare_col2_idx]):
            key = key_column_idx if key_column_idx == "None" else words[key_column_idx]
            print('%s\t%s\t1' % (key, words[value_column_idx]))
```

Sütun indeksleri ve karşılaştırma işleci arayüzden argüman olarak gelir, bu sayede aynı mapper farklı sütunlar için kullanılabilir. Grup bu yapıyla ülke bazında ortalama izlenme sayısını ve her ortalamanın kaç kayda dayandığını hesapladı.

> **Ek bilgi (derste anlatılmadı):** Ortalama birleşmeli (associative) bir işlem değildir; kısmi ortalamaların ortalaması, gruplar eşit büyüklükte değilse genel ortalamaya eşit olmaz. Bu yüzden combiner'ın ortalama yerine (toplam, sayı) çiftini üretmesi, reducer'ın da toplamların toplamını sayıların toplamına bölmesi gerekir. Değerin yanına "1" koymak bu çiftin sayı kısmını başlatır.

Bir öğrencinin veri kümesi düz metindi; önce her kelimenin kaç kez geçtiğini saydı, istatistikleri bu sayılar üzerinden hesapladı. Başka bir grup ortalamayı kelime uzunlukları üzerinden hesapladı: map aşamasında her kelimenin uzunluğu alınıp sayıldı, reduce aşamasında uzunluk başına kelime sayıları toplandı.

### 5.3 Minimum, maksimum ve aralık

Reducer gelen değerleri tek tek karşılaştırıp en küçüğü ve en büyüğü tutar. Aralık (range) bu ikisinin farkıdır. Bir grup min ve max'ı aynı çıktıda yan yana yazmaya çalıştı, hata alınca alt alta yazmayı tercih etti. Başka bir grup min-max ile aralığın aynı bilgiyi verdiğini fark edip aralık yerine medyanı ekledi.

Bir öğrenci maksimumu farklı bir yolla buldu: `map` metodu hiçbir şey yazmaz, yalnız o mapper'ın gördüğü en büyük değeri bir alanda tutar; mapper'ın `cleanup` metodu bu yerel maksimumu bir kez yazar. Reducer da aynı şekilde bütün yerel maksimumlar arasından en büyüğünü seçer ve `cleanup`'ta bir kez yazar.

> **Ek bilgi (derste anlatılmadı):** Bu yaklaşım "in-mapper combining" olarak bilinir. Her mapper yalnız bir kayıt yaydığı için ağ üzerinden reducer'a giden (shuffle) veri miktarı büyük ölçüde azalır. Maksimum birleşmeli bir işlem olduğu için yerel maksimumların maksimumu genel maksimuma eşittir.

### 5.4 Medyan ve mod

Medyan için aynı anahtarın değerleri bir diziye alınıp sıralanır. Eleman sayısı tekse ortadaki değer, çiftse ortadaki iki değerin ortalaması medyandır. Bir grup medyan hesabının ortalamaya göre daha uzun sürdüğünü, bu yüzden demoda ortalamayı seçtiğini söyledi.

Mod, aynı anahtarın değerleri içinde en çok tekrar eden değerdir. Bir grup retweet sayısı sütununun modunu MapReduce ile 0 buldu ve sonucu Python'da DataFrame ile aynı sütunun modunu hesaplayarak doğruladı (ekrandan, 01:40:00).

### 5.5 Korelasyon

Bir grup şehir bazında iki sayısal sütun arasındaki korelasyonu hesapladı. Çıktı dosyasında her satır bir şehir adı ve bir korelasyon katsayısıdır; görünen değerler yaklaşık −0,65 ile −0,18 arasındadır (ekrandan, 00:30:00). Grup başta korelasyonun evin yaşıyla fiyatı arasında olduğunu söyledi, sonra hangi sütunların kullanıldığını değiştirdiklerini belirtti.

## 6. Standart Sapmanın MapReduce Gerçekleştirimleri

Hocanın demolarda en çok sorduğu kod sorusu standart sapmanın mapper ve reducer'ının nasıl yazıldığıydı. Gruplar üç farklı yol izledi.

### 6.1 İki geçişli yöntem

Mapper anahtar olarak grubu (örneğin film), değer olarak sayıyı (örneğin puan) yayar. Reducer'da önemli bir ayrıntı vardır: reducer'a gelen `Iterable` yalnız bir kez dolaşılabilir; ikinci kez dolaşılmak istendiğinde değerler tükenmiş olur. Bu yüzden ilk döngüde değerler bir listeye kopyalanır. Bir grubun reducer'ı (ekrandan, 00:45:00):

```java
public static class RatingSTDReducer extends Reducer<Text, FloatWritable, Text, Text> {
    private FloatWritable result = new FloatWritable();

    public void reduce(Text key, Iterable<FloatWritable> values, Context context) throws IOException {
        int count = 0;
        float sum = 0;
        ArrayList<FloatWritable> arrayList = new ArrayList<>();
        for (FloatWritable val : values) {
            arrayList.add(val);
            sum += val.get();
            count += 1;
        }

        float average = (float) sum / count;

        float sumstd = 0;
        for (FloatWritable val : arrayList) {
            sumstd += (val.get() - average) * (val.get() - average);
        }

        sumstd = (float) sumstd / (count - 1);
        sumstd = (float) Math.sqrt(sumstd);

        result.set(sumstd);
        // context.write(key, new Text(String.format("%f", result.get()))) try-catch içinde
    }
}
```

İlk döngü toplamı ve sayıyı bulur, ortalama hesaplanır; ikinci döngü listedeki her değerin ortalamadan farkının karesini toplar; toplam $n-1$'e bölünür ve karekökü alınır:

$$s = \sqrt{\frac{1}{n-1} \sum_{i=1}^{n} (x_i - \bar{x})^2}$$

Başka gruplar da aynı yapıyı kullandı; bir grup bunu "cache mantığı" olarak anlattı: değerler ortalamadan sonra tekrar kullanılacağı için önbelleğe alınır, hesap iki kez döner (01:41:32). Bir grubun kodunda ikinci döngü dizi üzerinden indeksle yürür, sonuç `x/(count-1.0)` ile bölünüp `Math.sqrt` ile kökü alınır (ekrandan, 02:15:00).

> **Ek bilgi (derste anlatılmadı):** Hadoop reducer'a gelen değerleri bir akış olarak verir ve aynı `Writable` nesnesini her yinelemede yeniden kullanır. Bu yüzden listeye nesnenin kendisini eklemek yerine değerini (`val.get()`) ya da nesnenin bir kopyasını eklemek daha güvenlidir; aksi hâlde listedeki bütün elemanlar son değere dönüşebilir. Ayrıca bir anahtarın değerleri belleğe sığmayacak kadar çoksa liste kurmak sorun yaratır.

### 6.2 Örneklem ve kitle standart sapması

Bir grubun kodunda kareler toplamı $n-1$ yerine $n$'e bölünür: `std = (float) Math.sqrt(diff / n);` (ekrandan, 01:10:00). Bu, kitle (population) standart sapmasıdır:

$$\sigma = \sqrt{\frac{1}{n} \sum_{i=1}^{n} (x_i - \bar{x})^2}$$

Diğer gruplar $n-1$ ile bölerek örneklem (sample) standart sapmasını hesapladı. İki formül büyük $n$ için birbirine çok yakın sonuç verir, ama küçük gruplarda fark belirgindir.

### 6.3 Tek geçişli yöntem

Bir grup mapper'da her değeri yanına "1" koyarak yaydı; bu, sayma fonksiyonunun mapper'ına benzer. Reducer aynı döngüde toplamı, kareler toplamını ve eleman sayısını biriktirir. Öğrencinin anlattığı örnekte aynı değerden (13,1) üç tane varsa reducer'a 13,1 anahtar olarak, üç değer de değer listesi olarak gelir; döngü bu üç değeri sırayla toplar, karelerini toplar ve sayacı her turda bir artırır. Varyans

$$s^2 = \frac{\sum x_i^2 - \dfrac{\left(\sum x_i\right)^2}{n}}{n-1}$$

formülüyle bulunur, standart sapma bunun kareköküdür (`Math.sqrt`). Sonuç reducer'ın `cleanup` metodunda yazılır. Bu formül iki geçişli formülle aynı sonucu verir (python ile kontrol edildi), ama değerleri listede saklamayı gerektirmez.

> **Ek bilgi (derste anlatılmadı):** Tek geçişli formülde $\sum x^2$ ile $(\sum x)^2/n$ birbirine çok yakın büyük sayılar olabilir; bunların farkını almak kayan noktalı aritmetikte duyarlılık kaybına yol açabilir. Bu yüzden pratikte Welford gibi sayısal olarak kararlı yöntemler ya da (sayı, ortalama, kare farklar toplamı) üçlülerini birleştiren paralel formüller tercih edilir.

### 6.4 Paralel birleştirme

Bir öğrenci, iki döngü gerektirmemek için internetten bulduğu bir formülü kullandığını anlattı: her map görevi kendi verisinde kare farkları toplamını tek döngüde bulur, reduce aşamasında bu kısmi sonuçlar ayrı bir formülle birleştirilir. Öğrenci bunu paralel bir algoritma ve sayısal bir yöntem olarak tanımladı. <!-- BELİRSİZ: birleştirme formülü ekranda ya da altyazıda verilmedi; öğrencinin "tam sonuç değil, yaklaşık sonuç" demesi de doğrulanamadı. -->

## 7. Performans ve Ölçeklenebilirlik Analizi

### 7.1 Hocanın beklediği analiz

Hoca her gruba tek düğüm ile iki düğüm arasında karşılaştırma yapıp yapmadıklarını sordu. Beklediği analiz şudur: aynı fonksiyonlar tek düğümlü kümede ve iki düğümlü kümede çalıştırılır, süreler karşılaştırılır ve MapReduce ile nasıl bir ölçeklenebilirlik elde edildiği gösterilir.

> **Hocanın vurgusu:** Performans analizi, fonksiyonların tek düğümlü ve iki düğümlü kümede çalışma sürelerini karşılaştırarak ölçeklenebilirliği göstermelidir. Süre ölçümü kodun içinde yapılmalıdır.

Hoca, terminalde işten önce ve sonra `date` yazarak süre ölçmeyi yeterli bulmadı, ölçümün koda yazılması gerektiğini söyledi. Kronometreyle ölçüm yapıp iki düğümün tek düğümden yaklaşık iki kat hızlı olduğunu söyleyen bir gruba da bir bilgisayar mühendisinin kronometreyle ölçüm yapmaması gerektiğini vurguladı.

### 7.2 Gruplarda görülen analizler

- **Fonksiyonlar arası karşılaştırma:** birçok grup beş fonksiyonun sürelerini birbiriyle karşılaştırdı. Bir grupta medyan ve toplamın biraz daha uzun sürdüğü, diğerlerinin birbirine yakın olduğu görüldü. Başka bir grupta en uzun süren iş yaklaşık 33 saniyeyle standart sapmaydı.
- **Veri boyutuna göre:** bir grup aynı fonksiyonları 20 MB ve 500 MB veriyle çalıştırıp süreleri karşılaştırdı; başka bir grup verinin büyümesiyle sürenin nasıl değiştiğine baktı.
- **Hadoop ile doğrudan hesaplama:** bir grup veriyi bir programlama dilinde doğrudan belleğe alıp hesaplamayla Hadoop üzerinde hesaplamayı karşılaştırdı ve süreleri 0-100 arasına min-max normalizasyonuyla ölçekleyip işlemlerin karmaşıklığına göre grafikleştirdi.
- **Tek düğüm ile iki düğüm:** bir grup aynı işin yalnız bir düğüm etkinken yaklaşık 8 dakika sürdüğünü, iki düğümle saniyeler içinde bittiğini raporladı; ancak bunu yalnız ortalama fonksiyonu için yapmıştı.
- **Hadoop sayaçları:** Hadoop bir işi bitirince sayaçlar (counters) yazdırır: birleştirilen map çıktıları, GC süresi, harcanan CPU süresi, fiziksel ve sanal bellek anlık görüntüsü, toplam heap kullanımı, map ve reduce için tepe bellek değerleri, okunan ve yazılan bayt sayısı (ekrandan, 01:40:00; 01:55:00). Bir grup bellek kullanımını bu bilgilerden alıp fonksiyonları karşılaştırdı. YARN'ın uygulama listesi de her işin başlangıç ve bitiş zamanını verir; bir grup bu listeyi raporuna koydu (ekrandan, 01:40:00).

> **Ek bilgi (derste anlatılmadı):** Ölçeklenebilirlik genellikle hızlanma (speedup) ile ifade edilir: $S = T_1 / T_p$; burada $T_1$ tek düğümdeki, $T_p$ ise $p$ düğümdeki çalışma süresidir. İdeal durumda $S = p$ olur. Küçük verilerde işin başlatılması ve kaynak ayırma gibi sabit maliyetler baskın olduğu için düğüm eklemek süreyi pek değiştirmeyebilir; ölçeklenebilirlik ancak yeterince büyük veriyle anlamlı ölçülür.

## Örnek Sorular

Aşağıdaki sorular hocanın demolarda gruplara sözlü olarak sorduğu teknik sorulardır.

**Soru 1** (derste sözlü, 00:36:00): HDFS'te olmayan küçük bir dosyayı yerel dosya sisteminden HDFS'e atın, geldiğini gösterin; sonra HDFS'teki bir dosyayı okuyup yerel dosya sistemine koyun.

> **Çözüm (derste gösterildi):** Yazma için `hadoop fs -put <yerel> <hdfs>` ya da arayüzde "Add File"/"Push to HDFS"; dosyanın geldiği NameNode web arayüzünün Browse Directory sayfasında görülür. Okuma için `hadoop fs -get <hdfs> <yerel>` ya da arayüzde "Get File"/"Pull File from HDFS"; dosyanın yerel klasöre geldiği dosya yöneticisinde gösterilir (ekrandan, 00:50:00; 02:05:00).

**Soru 2** (derste sözlü, 01:09:27): Standart sapma için MapReduce'u, yani mapper ve reducer'ı nasıl yazdınız?

> **Çözüm (derste gösterildi):** Mapper, gruplama sütununu anahtar ve sayısal sütunu değer olarak yayar. Reducer ilk döngüde değerleri bir listeye alır, toplamı ve sayıyı bulur, ortalamayı hesaplar; ikinci döngüde $(x_i - \bar{x})^2$ değerlerini toplar, $n-1$'e böler ve karekökünü alır (bkz. 6.1). Tek geçişli alternatif: toplam, kareler toplamı ve sayı aynı döngüde biriktirilip $s^2 = \left(\sum x^2 - (\sum x)^2/n\right)/(n-1)$ kullanılır (bkz. 6.3).

**Soru 3** (derste sözlü, 01:40:32): Bitcoin tweet'leri veri kümesinde standart sapma hesabında mapper hangi sütunu yayıyor, reducer neden iki kez dönüyor?

> **Çözüm (derste gösterildi):** Mapper satırı virgülle bölüp dördüncü sütundaki favori sayısını `float`'a çevirerek yayar. Reducer, ortalamadan sonra değerleri yeniden kullanabilmek için önce önbelleğe (listeye) alır; ilk geçişte ortalama, ikinci geçişte kare farkları hesaplanır.

**Soru 4** (derste sözlü, 00:52:31): Performans analizi yaptınız mı; tek düğümde şu kadar, çift düğümde bu kadar zaman alıyor diye?

> **Çözüm (derste verildi):** Beklenen analiz, aynı fonksiyonları tek düğümlü ve iki düğümlü kümede çalıştırıp süreleri kod içinde ölçerek karşılaştırmak ve buradan ölçeklenebilirliği değerlendirmektir (bkz. 7.1).

## Dersin Toparlaması

Bu oturumda dönem projesinin demoları yapıldı ve bir Hadoop tabanlı büyük veri uygulamasının parçaları uygulamada görüldü. Kümeler sanal makinelerle, Docker kapsayıcılarıyla ya da bulutta kuruldu; kümenin durumu NameNode web arayüzünden ve `jps` komutuyla gösterildi. HDFS istemcisinin iki yönlü olması gerektiği, yani hem yerelden HDFS'e yazmanın hem de HDFS'ten yerele okumanın gösterilmesi gerektiği öne çıktı.

İstatistiksel fonksiyonların MapReduce gerçekleştirimlerinde ortak kalıp, mapper'ın gruplama sütununu anahtar ve sayısal sütunu değer olarak yayması, reducer'ın da aynı anahtarın değerleri üzerinde istatistiği hesaplamasıydı. Standart sapma için iki geçişli (listeye alarak), tek geçişli (kareler toplamı formülüyle) ve kısmi sonuçları birleştiren yöntemler görüldü; ortalamanın combiner ile doğru çalışması için sayının da taşınması gerektiği ortaya çıktı. Performans analizinde asıl ölçülmesi gereken şeyin düğüm sayısı arttıkça sürenin nasıl değiştiği, yani ölçeklenebilirlik olduğu ve ölçümün kod içinde yapılması gerektiği vurgulandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
