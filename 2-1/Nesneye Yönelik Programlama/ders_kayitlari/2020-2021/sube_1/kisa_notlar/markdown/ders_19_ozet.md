# Ders 19 Çalışma Özeti

## Genel Konular

- Uygulama oturumu: iç sınıflar, tip dönüştürme, dosya işlemleri ve iş parçacıkları
  - Oturum bir uygulama (lab hazırlık) dersidir. Konular Eclipse'teki `uyg-4` projesinin `innerclass`, `typecasting`, `filestream` ve `multithread` paketlerindeki hazır örnek kodlar çalıştırılarak anlatıldı (ekrandan, 00:10:00 ve 00:25:00).
  - İç sınıf için bir Java öğretici sitesindeki örnekler kaynak olarak kullanıldı; kuramsal kısma, özellikle iş parçacıklarında, yüzeysel girildi.
- İç sınıf (inner class)
  - Bir sınıfın içinde tanımlanan sınıfa iç sınıf denir. Dış sınıftan bir nesne oluşturulur, iç sınıfın nesnesi bu nesne üzerinden `myOuter.new InnerClass()` ile oluşturulur ve `OuterClass.InnerClass` türünden bir değişkende tutulur.
  - Örnekte `myInner.y + myOuter.x` toplamı `5 + 10 = 15` olarak yazdırıldı.
  - İç sınıf `private` yapılırsa dışarıdan (başka sınıftan) erişimde hata verir; `public`, `protected` ya da erişim belirteci yazılmaması kabul edilir.
  - `static` iç sınıf, dış sınıftan nesne oluşturmadan `new OuterClass.InnerClass()` ile oluşturulur; tıpkı `static` bir alana `OuterClass.x` diye erişmek gibi.
  - İç sınıfın bir metodu dış sınıfın `x` alanını döndürebilir (`myInner.myInnerMethod()`).
  - Çalışma bakımından iki ayrı sınıf yazmakla aynı işi görür; fark okunurluk ve daha az koddur. Bir sınıfı yalnız tek bir sınıf kullanıyorsa onun içine iç sınıf olarak yazılabilir; başka sınıflar da kullanıyorsa dışarıda tutulur.
- İlkel veri tiplerinde tip dönüştürme
  - Otomatik dönüştürme: `int x = 1911; double y = x;` ile `y` `1911.0` olur. `"... (YTÜ) " + x + " yılında kuruldu."` ifadesinde `int` otomatik olarak metne çevrilip birleştirilir (ekrandan, 00:25:00).
  - `char` ile `int` arasında dönüştürmede ASCII karşılığı kullanılır: `char c = '3'; int c_i = c;` sonucu `51`'dir.
  - Küçük tür büyüğe otomatik dönüşür; büyük tür küçüğe otomatik dönüşmez: `double` bir değer doğrudan `int` değişkene atanırsa derleme hatası alınır.
  - Zorla dönüştürme: `int y_i = (int) x_d;` ile `5.4` değeri `5` olur, ondalık kısım kaybolur. Sonra `(char) y_i` ile `5` ASCII tablosundaki karşılığı olan karaktere çevrilir (ekrandan, 00:25:00).
  - `String` `(int)` ya da `(double)` ile dönüştürülemez; sarmalayıcı sınıfların `Integer.parseInt`, `Double.parseDouble`, `Float.parseFloat` metotları kullanılır. `"50.4"` önce `50.4` (double), sonra `(int)` ile `50` olur (ekrandan, 00:35:00).
  - Veri kaybı her zaman kötü değildir: bir sayının tam kısmı, çarpma ve mod işlemleri yerine `(int)` dönüşümüyle kolayca alınır.
- İlkel olmayan veri tiplerinde (nesnelerde) dönüştürme
  - `TukenmezKalem extends Kalem` olduğundan `Kalem k` değişkeni bir `TukenmezKalem` nesnesini tutabilir: `k = (Kalem) tk;` Cast yazılmasa da (`k = tk;`) otomatik dönüşür (ekrandan, 00:35:00 ve 00:40:00).
  - `k` yazdırıldığında yine "Tükenmez kalem sınıfı" çıkar; değişken üst sınıf türünde olsa da tuttuğu nesne tükenmez kalemdir. `k instanceof TukenmezKalem` ve `k instanceof Kalem` ikisi de doğrudur.
  - Kalıtım yoksa bu dönüşüm yapılamaz. Aynı üst sınıftan türeyen iki kardeş sınıf (tükenmez kalem ve kurşun kalem) birbirine dönüştürülemez.
  - Ters yönde, alt sınıf türündeki değişkene üst sınıf nesnesi atanması derste hata verdi.
- Dosyaya metin yazma ve okuma
  - `FileWriter myWriter = new FileWriter("urunler.txt");` ile proje dizininde dosya açılır; `ArrayList<Urun>` dolaşılıp her ürün `getIsim() + ", " + getFiyat() + "\n"` biçiminde yazılır; `myWriter.close()` ile kapatılır. Kod `try-catch (IOException)` içindedir (ekrandan, 00:45:00).
  - Okumada `File myObj = new File("urunler.txt")` ve `Scanner myReader = new Scanner(myObj)` kullanılır; `hasNextLine()` ile satır satır okunur, `split(", ")` ile parçalara ayrılır, `Double.parseDouble(tokens[1])` ile fiyat sayıya çevrilir ve yeni `Urun` nesneleri listeye eklenir. `FileNotFoundException` yakalanır (ekrandan, 00:50:00).
- Nesneyi bayt bayt yazma ve okuma (serileştirme)
  - Yazılacak sınıfın `java.io.Serializable` arayüzünü uygulaması gerekir. Bu arayüzün içi boştur, override edilecek metot yoktur. Uygulanmadığında yazma işlemi başarısız oldu.
  - Yazma: `FileOutputStream` ile `Urun.ser` açılır, `ObjectOutputStream`'e verilir, `writeObject(nesne)` ile nesne doğrudan (alanları tek tek alınmadan) yazılır.
  - Okuma: `FileInputStream` ve `ObjectInputStream` ile `readObject()` çağrılır; dönen `Object` yazdırılır. `catch (IOException | ClassNotFoundException i)` kullanılır (ekrandan, 00:55:00).
  - `.ser` dosyası metin düzenleyicide açılınca okunaklı değildir; içinde sınıf adı, alan adları ve türleri seçilebilir.
  - Dosyaya iki nesne yazılınca her `readObject()` çağrısı sıradaki nesneyi döndürür.
- İş parçacıkları (thread)
  - Normal akışta satırlar sırayla çalışır; iş parçacıklarında iki iş aynı anda (eş zamanlı) ilerler.
  - `Thread` yapıcısı bir `Runnable` alır. `Runnable`'ı uygulayan sınıf `run()` metodunu override etmelidir; `start()` çağrılınca `run()` ayrı bir iş parçacığında çalışır (ekrandan, 01:00:00 ve 01:05:00).
  - Örnekte `Increaser` (`static int sayi = 5`, `add()` içinde `sayi++` ve 5 kez yazdırma) ve `Onay` (5 kez "Onaylandı") aynı anda çalıştı; çıktı satırları her çalıştırmada farklı sırayla karışık geldi.
  - `Thread.sleep(1000)` iş parçacığını milisaniye cinsinden verilen süre (1000 ms = 1 s) bekletir.
  - Fayda: iki iş aynı anda yapılabilir; toplamda $2t$ sürecek iş $t$ sürede bitebilir.
- İş parçacığı havuzu
  - `ExecutorService ex = Executors.newFixedThreadPool(5);` ile 5 iş parçacıklı havuz oluşturulur; döngüde 20 `MyThread` (Runnable) `ex.execute(thread)` ile havuza verilir (ekrandan, 01:10:00).
  - `MyThread.run()` adını yazdırıp `Thread.sleep(5000)` ile bekler. Çıktıda önce beşli bir grup (`thread2, thread5, thread3, thread1, thread4` gibi, sıra her seferinde farklı) çalıştı, sonra sıradakiler geldi.
  - `ex.shutdown()` havuza yeni iş kabul edilmeyeceğini bildirir; `ex.awaitTermination(1, TimeUnit.DAYS)` çalışan işlerin bitmesini en fazla 1 gün bekler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Büyük türden küçük türe otomatik dönüşüm yok
  - `int` → `double` otomatik olur; `double` → `int` için `(int)` yazmak gerekir ve ondalık kısım kaybolur.
- `(int)` ile `Integer.parseInt` farkı
  - Parantezli dönüştürme `String` üzerinde çalışmaz; metinden sayı elde etmek için `parseInt`/`parseDouble` gibi metotlar kullanılır.
- Kalıtım olmadan nesne dönüştürülemez
  - "Tükenmez kalem bir kalemdir" ilişkisi (extends) olduğu için üst sınıf türüne dönüşüm yapılabilir; kardeş sınıflar arasında yapılamaz.
- Dosyayı kapatın
  - Java'da kapatılmasa da büyük sorun çıkmayabilir, ama dosyalar her zaman kapatılmalıdır.
- İş parçacıkları önemli bir konu
  - Konu bu oturumda yüzeysel anlatıldı; iş parçacıklarıyla ilgili soru kalmaması istendi.

## Kısa Tekrar Notları

- İç sınıf nesnesi: `OuterClass.InnerClass myInner = myOuter.new InnerClass();` `static` iç sınıf: `new OuterClass.InnerClass()`.
- Otomatik dönüşüm küçükten büyüğe; zorla dönüşüm `(tür)` ile, veri kaybı olabilir.
- `'3'` → `51` (ASCII). `5.4` → `5`. `"50.4"` → `50.4` → `50`.
- `String` → sayı: `Integer.parseInt`, `Double.parseDouble`, `Float.parseFloat`.
- Üst sınıf türündeki değişken alt sınıf nesnesini tutar; `instanceof` iki tür için de `true` döner.
- Metin dosyası: `FileWriter` + `write` + `close`; `File` + `Scanner` + `hasNextLine/nextLine`.
- Nesne dosyası: `Serializable` + `ObjectOutputStream.writeObject` / `ObjectInputStream.readObject`.
- `Thread(new Runnable)` + `start()`; `run()` override edilir; `Thread.sleep(ms)`.
- `Executors.newFixedThreadPool(n)`, `execute`, `shutdown`, `awaitTermination`.

## Detaylı Açıklamalar

- İç sınıfın anlamı
  - Derste iç sınıf ile iki ayrı sınıfın (biri diğerinden alan olarak nesne tutan) çalışma bakımından aynı işi gördüğü söylendi. Ekrandaki `Main.java`'da `InnerClass` (`int y`, yapıcıda `y = 5`) ve `OuterClass` (`int x`, `InnerClass y`, yapıcıda `y = new InnerClass(); x = 10;`) ayrı sınıflar olarak yazılmıştı (ekrandan, 00:10:00). İç sınıf yazımı aynı ilişkiyi daha kısa ve okunaklı kurar.
  - Kullanım ölçütü: iç sınıfı yalnız onu barındıran sınıf kullanıyorsa içeride tanımlamak şıktır; başka bir sınıf da ondan nesne oluşturacaksa dışarıda tutulur.
  - Ders sonrası not: Derste iç sınıfın içinden dış sınıfın `x` alanına erişilemeyeceği söylendi (00:12:39). Bu `static` olmayan iç sınıf için doğru değildir; derste gösterilen `myInnerMethod()` örneği de dış sınıfın `x`'ini döndürür. `static` olmayan iç sınıf, dış sınıfın alanlarına (private olanlar dahil) doğrudan erişir; erişemeyen `static` iç sınıftır (dış sınıfın nesne alanlarına). Doğru olan, `myInner.x` biçiminde iç sınıf nesnesi üzerinden dış sınıfın alanına erişilememesidir.
- Tip dönüştürme ayrıntıları
  - `double z = 5.4; int x = z;` derleme hatası verir (Java: "possible lossy conversion from double to int"). `int yas_d = (int) yas;` (yas bir `String`) de hata verir; derste bu iki satır gösterilerek parantezli dönüştürme ile `parse` metotlarının farkı anlatıldı (ekrandan, 00:40:00).
  - `int y_i = 8; y_i = (int) x_d;` yazıldığında da sonuç yine `5`'tir: değişkenin önceki değeri (`8`) üzerine yeni değer yazılır.
  - `(char) 5` sonucu konsolda bir simge olarak göründü (ekrandan, 00:25:00).
- Kodların kontrolü
  - Tip dönüştürme, metin dosyası yazma/okuma, serileştirme, iki iş parçacığı ve havuz örnekleri, karelerdeki kodlardan kurulan küçük programlarla `java Dosya.java` (tek dosyalık kaynak çalıştırma) ile denendi; çıktılar ekrandaki çıktılarla aynı çıktı. `javac` kurulu olmadığı için ayrı derleme yapılmadı. Karede görünmeyen `Urun`, `Kalem` ve `TukenmezKalem` sınıfları anlatıma göre kuruldu.
- Havuz davranışı
  - Ders sonrası not: Derste havuzun önce 5 iş parçacığıyla "dolmasını beklediği", sonra çalıştığı söylendi (01:07:07, 01:11:03). Doğrusu: `newFixedThreadPool(5)` 5 işçi iş parçacığı tutar; `execute` ile verilen iş boş bir işçi varsa hemen çalışmaya başlar, yoksa kuyrukta bekler. Çıktıda beşli gruplar görülmesinin nedeni her işin `Thread.sleep(5000)` ile 5 saniye işçiyi meşgul etmesidir; bir işçi boşalınca kuyruktaki sıradaki iş başlar. Derste "20 tane thread oluşturuyorum" denen şey de büyük olasılıkla 20 iş (Runnable nesnesi) ve 5 iş parçacığıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
