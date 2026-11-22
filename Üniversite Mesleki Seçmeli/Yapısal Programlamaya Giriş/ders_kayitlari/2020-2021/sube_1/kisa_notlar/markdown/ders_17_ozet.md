# Ders 17 Çalışma Özeti

## Genel Konular

- Uygulama oturumunun yapısı
  - Bu kayıt dersin üçüncü uygulama oturumudur (slayt dosyası "uygulama 3"). Dört soru slaytta gösterildi ve çözümleri Dev-C++ üzerinde birlikte yazıldı. Konular: matrislerde ve dizilerde gezinme, diziler üzerinde değişiklik yapma, fonksiyonlara dizi ve matris gönderme.
  - Zaman kısıtı yüzünden matrisler kullanıcıdan alınmadı, tanım sırasında başlangıç değeri verildi: `int m_One[3][3]={{1,2,3},{4,5,6},{7,8,9}};` (ekrandan, 00:10:00).
- Soru 1: Matris operasyonları (ekrandan, 00:10:00)
  - Slayttaki alt sorular: iki matrisin toplamı, iki matrisin çarpımı, iki matrisin iç çarpımı ve matrisin normalizasyonu (Min-Max Scaling).
  - Fonksiyon `void` döner. Sonuç matrisi de (`Res`) parametre olarak gönderilir; gönderilen matrislerden birinin üzerine yazmak girdiyi bozduğu için tercih edilmedi.
  - Matris parametreleri boyutlarla birlikte yazıldı: `void sum(int colLength,int rowLength,int mOne[rowLength][colLength],int mTwo[rowLength][colLength],int Res[rowLength][colLength])` (ekrandan, 00:15:00). Toplam iki iç içe `for` ile `Res[i][j]=mOne[i][j]+mTwo[i][j];` biçimindedir (ekrandan, 00:20:00).
  - Aynı toplam işaretçiyle de yazıldı (`sum_Alt`): matris tek boyutlu bir işaretçi olarak alınır ve eleman `*((Res+i*colLength)+j)` ile bulunur (ekrandan, 00:25:00).
  - "Çarpım" eleman eleman çarpım olarak yazıldı: `Res[i][j]=mOne[i][j]*mTwo[i][j];`. `1..9` matrisinin kendisiyle çarpımı `1 4 9 / 16 25 36 / 49 64 81` çıktı (ekrandan, 00:30:00).
  - "İç çarpım" için üçüncü bir indis `k` ve her `(i,j)` için sıfırlanan `tmpSum` kullanıldı: `tmpSum+=mOne[i][k]*mTwo[k][j];` (ekrandan, 00:35:00).
  - Normalizasyon formülü (ekrandan, 00:10:00): $X_{new} = \dfrac{X_i - \min(X)}{\max(X) - \min(X)}$. En küçük ve en büyük değer tek bir `minMax` fonksiyonuyla bulundu; `mode==0` ise en büyük, değilse en küçük değer döner (ekrandan, 00:40:00). Sonuç matrisi `float` tanımlandı.
- Soru 2: Dizide tekrar eden elemanların atılması (ekrandan, 00:45:00)
  - Slayttaki örnek: `1 4 7 4 2 7` → `1 4 7 2 X X`.
  - Düz mantık çözüm (`DoubleLoop`): iç içe iki döngüyle her eleman kendinden sonrakilerle karşılaştırılır, tekrar edenlere `-1` yazılır. Sonra `i` (gezen indis) ve `j` (yazılacak yer) ile `-1` olmayanlar tek geçişte sola kaydırılır, kalan yerlere `-1` yazılır (ekrandan, 00:55:00).
  - Sıralı dizi çözümü (`Sorted`): dizi sıralıysa her eleman yalnız son yazılan farklı elemanla karşılaştırılır; `i=1, j=0` ile `while` döngüsü kullanılır.
  - En iyi yöntem hashing'dir: değer ile indis arasında bir ilişki kuran bir fonksiyonla eleman bir "kova"ya (bucket, bin) konur; bir elemanın tabloda olup olmadığına bakmak ortalama $O(1)$ olur. Dizi bir kez gezilerek tekrar edenler bulunur.
- Soru 3: Toplamı sıfır olan alt dizi (subarray) (ekrandan, 01:20:00)
  - Slayttaki örnek: `1, 4, -2, -2, 5, -4, 3` dizisinde sonuç `4, -2, -2` (1. indeksten 3. indekse).
  - Alt dizi bitişik elemanlardan oluşur; bu yüzden dizi sıralanamaz.
  - Kötü çözüm (`findSubArray_Bad`): her başlangıç `i` için `Sum` sıfırlanır ve `j=i`'den itibaren toplanır; toplam sıfır olunca indisler yazdırılır. $O(n^2)$ (ekrandan, 01:15:00).
  - Önek toplamı (prefix sum) çözümü (`findSubArray_Good`): elemanlar sırayla toplanır; ara toplam sıfır olursa ya da daha önce görülen bir ara toplam tekrar çıkarsa aradaki elemanların toplamı sıfırdır. Arama `Exists` fonksiyonuyla yapılır (ekrandan, 01:25:00). Bu arama hashing ile yapılırsa çözüm hızlanır.
- Soru 4: Dizideki en uzun devamlı (ardışık) dizi (ekrandan, 01:45:00)
  - Slayttaki örnek: `[100, 4, 200, 1, 3, 2]` → `[1, 2, 3, 4]`.
  - Kaba kuvvet (`Brute`): her eleman için dizide bir fazlası aranır; bulununca sayı ve sayaç artırılır, arama dizinin başından yeniden başlar (ekrandan, 01:50:00).
  - Sıralı dizi çözümü (`Sorted`): her eleman bir sonrakiyle karşılaştırılır, `Arr[i]+1==Arr[i+1]` ise sayaç artar (ekrandan, 01:55:00).
  - Hashing çözümü: bir elemanın bir eksiği tabloda yoksa o eleman bir dizinin başlangıcı olabilir; sonra bir fazlası, iki fazlası... aranarak uzunluk sayılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Global değişken ve `break` kullanılmaz
  - Global değişken, fonksiyon içinden sonuca erişmenin bir çözümüdür; ama ileride çok iş parçacıklı (multithreading) programlarda kontrolü imkânsız hâle getirir. Bölüm olarak buna karşı olunduğu, ödevlerde ve lablarda kullanılmaması gerektiği söylendi. Sonuç bunun yerine parametreyle gönderilir.
- Main'deki değişkene fonksiyondan, fonksiyondaki değişkene main'den erişilemez
  - Fonksiyonun değişkenleri main'inkilerden ayrıdır; iletişim parametreler ve dönüş değeriyle kurulur. İşaretçiler bellekteki adrese doğrudan eriştiği için bu sınırı aşar.
- C'de bu biçimde tanımlanmış bir matris fonksiyondan döndürülemez
  - Bu yüzden dönüş tipi `void` olur ve sonuç matrisi parametreyle gelir.
- İşaretçide `*` adresin gösterdiği değeri verir
  - `*` olmadan adresle işlem yapılır; adres hesabı bittikten sonra en dışa `*` konarak değere ulaşılır.
- İlk değer atanmamış değişken
  - `tmpSum`'ın her `(i,j)` için sıfırlanması unutulmamalı. İlk değer atamamanın çok yaygın olduğu ve ödev hatalarının çoğunu oluşturduğu söylendi.
- Integer bölme
  - `(x-min)/(max-min)` bütün işlenenler `int` olduğunda tam sayı bölmesi yapar; sonuç `float` dizide bile 0 ya da 1 çıkar. Başa `(float)` dönüşümü eklenir. `float` matris `%d` ile değil `%f` ile yazdırılır.
- İndisin kontrollü ilerlemesi gerekiyorsa `while` kullanılır
  - `for` indisi her adımda aynı biçimde artırır; indis yalnız bazı koşullarda artacaksa `while` seçilir. `while` kullanılırken indisi artırmayı unutmamak gerekir.

## Kısa Tekrar Notları

- Fonksiyona matris gönderirken boyutlar yazılır (sütun sayısı yeterlidir; derste hepsi yazıldı).
- Satır satır bellekte tutulan bir matriste `[i][j]` elemanının adresi: başlangıç + `i*colLength` + `j`.
- İç çarpım için üç indis gerekir; ara toplam her sonuç elemanı için sıfırlanır.
- Min-max normalizasyonu veriyi $[0,1]$ aralığına taşır. Başka bir tür: ortalama çıkarılıp standart sapmaya bölünür, ortalaması 0 ve standart sapması 1 olan veri elde edilir.
- Tekrar eden elemanlar: iç içe döngü $O(n^2)$; sıralama sonrası tek geçiş; en iyisi hashing.
- Hash fonksiyonuna örnek: değerin kova sayısına göre modu. 7 kovada 8 → 1. kova, 9 → 2. kova.
- Toplamı sıfır alt dizi: bir önek toplamı tekrar ediyorsa aradaki elemanların toplamı sıfırdır; önek toplamın kendisi sıfırsa baştan oraya kadar olan kısım sıfırdır.
- En uzun ardışık dizi: kaba kuvvet, sıralama ya da hashing; hashing'de yalnız bir eksiği olmayan elemanlardan sayılmaya başlanır.
- `int *Arr` ile `int* Arr` aynıdır; yıldızın değişkenin yanına yazılması tercih edilir.
- `--i` önce azaltır sonra değeri verir; `i--` önce değeri verir sonra azaltır.

## Detaylı Açıklamalar

- Matrisi işaretçiyle gezmek
  - Matrisin elemanları bellekte satır satır arka arkaya durur: `1 2 3` satırının hemen yanında `4 5 6`, onun yanında `7 8 9`. İşaretçi ilk elemanı gösterir. Sütunda ilerlemek için adrese `j` eklenir; bir satır aşağı inmek için sütun sayısı kadar atlamak gerekir, bu yüzden `i*colLength` eklenir. İfadenin en dışına `*` konduğunda adresteki değer alınır: `*((Res+i*colLength)+j)=*((mOne+i*colLength)+j)+*((mTwo+i*colLength)+j);`. Derste önce `rowLength` yazıldı, sonra "sütun sayısı kadar atlamalı" denerek `colLength` olarak düzeltildi.
- İç çarpım
  - Slayttaki şekilde $A, B, C, D, E, F$ elemanlı $3\times 2$ matris $G, H$ elemanlı sütunla çarpılır; sonuç $A\times G + B\times H$, $C\times G + D\times H$, $E\times G + F\times H$ olur (ekrandan, 00:10:00). Birinci matrisin bir satırı ile ikincinin bir sütunu eleman eleman çarpılıp toplanır. Bunun için `i`, `j` ve satır-sütun boyunca yürüyen `k` gerekir.
  - Derste kare ($3\times 3$) matrisler için yazıldı; boyutların farklı olması için bir değişken daha eklemek yeterli olduğu söylendi.
- Min-max normalizasyonu
  - Veri madenciliği ve yapay zekâda verinin ölçeğini değiştirmek için kullanılır. Örneğin bir resmin piksel değerleri 0 ile 255 arasındadır; yapay sinir ağı gibi bir işleme sokulacaksa 0 ile 1 arasında olması daha iyidir. Bu bir filtre değildir. İşlem bütün veriye, yalnız sütun bazında ya da satır bazında yapılabilir; sütunlara ayrılmış bir veri setinde sütun bazında yapılabilir.
  - `minMax` fonksiyonunda başlangıç değeri olarak matrisin bir elemanı (`mOne[0][0]`) verildi; en büyük/en küçük int sabiti de kullanılabilir.
- Tekrar eden elemanların atılması
  - `DoubleLoop`'ta iç döngü `j=i+1`'den başlar, çünkü geriye bakmak gerekmez; ilk denemede `j=0` yazıldığı için program yanlış çalıştı ve düzeltildi. `-1` yazılmış elemanlar dış döngüde atlanır.
  - Kaydırmada `i` her adımda artar; `j` yalnız `-1` olmayan eleman yazıldığında artar. Böylece `-1`'ler üzerine yazılarak tek geçişte kaydırma yapılır, her `-1`'de dizinin geri kalanını ayrı ayrı kaydırmaya gerek kalmaz.
  - Histogram (sayma) dizisi de kullanılabilir ama değer aralığı çok geniş olabilir: beş elemanlı bir dizide bir eleman bir milyon ise o kadar büyük bir dizi gerekir; sayılar çok büyükse bellek bile yetmez. Hash fonksiyonu bu ilişkiyi doğrudan değil bir fonksiyon üzerinden kurar; aynı kovaya düşen elemanlar çakışmadır. Gerçekte kovaların içinde de kontrol gerektiği için her zaman $O(1)$ olmaz ama çok hızlandırır.
- Toplamı sıfır alt dizi, önek toplamı yöntemi
  - Bir öğrenci önerisi: `3, 4, -2, -2` dizisinde ara toplamlar `3, 7, 5, 3`'tür; 3 tekrar ettiği için aradaki `4, -2, -2` toplamı sıfırdır.
  - `findSubArray_Good`'da `while` üç koşulla biter: dizi bitti (`i<len` bozuldu), ara toplam sıfır oldu, ara toplam `PrefixSum` içinde bulundu (`Exists` 0 döndürdü). Çıkıştan sonra bu üç durum ayrı `if` dallarıyla ele alınır. `Exists` aranan değer varsa 0, yoksa 1 döndürür.
  - Ara toplam sıfırsa alt dizinin dizinin başından o noktaya kadar olduğu söylenebilir; bunu bir öğrenci fark etti ve doğru olduğu kabul edildi.
  - Tekrar eden önek toplamı dalında başlangıç indisi (`Start=i-1`) derste deneme yanılmayla bulundu; mantığının açıklanamadığı söylendi.
- Ders sonrası notlar
  - Derste "çarpım" denen işlem eleman eleman çarpımdır (Hadamard çarpımı); "iç çarpım" diye yazılan işlem ise olağan matris çarpımıdır. Bir öğrenci de derste ikincisinin "matris çarpımı" diye bilindiğini söyledi.
  - Ekrandaki `findSubArray_Good` kodu, tekrar eden önek toplamı durumunda doğru indisleri vermiyor. Ajanın `gcc -Wall` testinde ekrandaki `{1,5,-2,-1,-1,1,3}` dizisi için "From 2 to 6" çıktı; bu aralığın toplamı rastlantı sonucu sıfırdır, oysa algoritmanın bulduğu alt dizi 4-5. indislerdir (`-1, 1`). Slayttaki `1, 4, -2, -2, 5, -4, 3` dizisinde çıktı "From -1 to 4" olur, doğrusu 1-3'tür. Doğrusu: ara toplam `Arr[0..i-1]`'e aittir, yani `End=i-1`; `PrefixSum[k]` ile eşleşme varsa `Start=k+1`. Ayrıca döngü `i==len` olunca son toplam kontrol edilmeden biter (örneğin `{1,-1}` için "No Sub Array" çıkar); `if` dallarında önce sıfır ve tekrar durumları kontrol edilmelidir. Düzeltilmiş sürüm genişletilmiş nottadır.
  - Derste `i++`'nın `i+=1`'den farklı komutlarla gerçeklendiği ve çok daha hızlı olduğu söylendi. Bir `int` değişkeni artırırken ikisi aynı işi yapar: ajanın denemesinde gcc, `-O0` ve `-O2` ile ikisi için de aynı makine kodunu üretti. Yani aralarında bir performans farkı yoktur.
- En uzun ardışık dizi
  - Kaba kuvvette her eleman için dizi baştan sona taranır; bir fazlası bulunduğunda arama yeniden başladığı için iç döngü `while` olur. Bu yöntemin selection sort'a çok benzediği, hatta ondan kötü olduğu söylendi; çünkü selection sort'ta taranan kısım küçülür, burada küçülmez. Karmaşıklık aynıdır.
  - Hashing çözümünün örnekle işleyişi: 100'ün bir eksiği (99) yoktur, bir fazlası (101) da yoktur, uzunluk 1. 4'ün bir eksiği (3) vardır, başlangıç değildir. 1'in bir eksiği (0) yoktur; 2, 3, 4 vardır, uzunluk 4 olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
