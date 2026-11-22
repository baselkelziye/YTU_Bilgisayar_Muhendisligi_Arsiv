# Ders 23 Genişletilmiş Notu: İkinci Ara Sınav Sorularının Değerlendirmesi: Matris Eşitliği, Sütun Takası ve Döngü Seçimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kaynak Kod Dosyası Bir Metin Dosyasıdır
- 2. Matris Eşitliği Sorusu
- 3. Matris Eşitliğinde Döngü Şartını Kurmak
- 4. Akışın C ile Kodlanması
- 5. Sütun Takası Sorusu
- 6. Akış Diyagramı Kurallarının Tekrarı
- 7. for ile while Arasındaki Seçim
- 8. Örnek Sorular
- Dersin Toparlaması

## 1. Kaynak Kod Dosyası Bir Metin Dosyasıdır

Bu kayıtta yeni bir konu anlatılmadı; ders ikinci ara sınavın değerlendirmesine ayrıldı. Akademik kısım, sınav cevaplarında görülen hatalar üzerinden temel kavramların tekrarıdır.

İlk tekrar edilen kavram dosya biçimleriyle ilgilidir. Hoca, dönemin ilk haftalarında dosyalar, dosya sistemi ve karakter kodlaması (encoding) üzerine konuşulduğunu hatırlattı. Bir `.c` dosyası düz bir metin dosyasıdır: içinde yalnız karakterler vardır, özel bir yapı yoktur. Dosya uzantısı yalnız insanın dosyanın ne olduğunu anlaması (human readable olması) içindir. Bu yüzden bir `.c` dosyasının uzantısı `.txt` yapılsa da içerik değişmez; geri `.c` yapıp derlemek yeterlidir.

Hoca buna karşılık sıkıştırılmış arşiv dosyalarının (zip, rar) bilinmeyen bir kaynaktan geldiğinde açılmaması gerektiğini, çünkü arşiv dosyalarının virüs bulaşmasında en çok kullanılan yollardan biri olduğunu söyledi.

## 2. Matris Eşitliği Sorusu

Hoca sınav sorularını ekranda açtı. Birinci soru şuydu (ekrandan, 00:30:00):

> Verilen eşit boyutlardaki iki matrisin aynı olup olmadığını bulan algoritmaya ait akışı çiziniz. Eğer iki matrisin aynı pozisyondaki elemanlarının tamamının değerleri eşit ise matrisler aynıdır. Aksi takdirde matrisler farklıdır.

Soruda iki örnek verilmişti:

```text
Matrislerin eşitlik durumu için örnek
A matrisi      B matrisi
2 3 7          2 3 7
1 4 6          1 4 6
5 8 0          5 8 0

Matrislerin eşit olmama durumu için örnek
A matrisi      B matrisi
2 3 7          2 3 7
1 6 6          1 4 6
5 8 0          5 8 0
```

Birinci örnekte bütün pozisyonlar aynıdır, dolayısıyla matrisler aynıdır. İkinci örnekte hoca elemanları satır satır karşılaştırdı: 2 ile 2, 3 ile 3, 7 ile 7, 1 ile 1 eşittir; beşinci karşılaştırmada (2. satır, 2. sütun) 6 ile 4 farklı çıkar. Hoca burada "Buradan sonrasına bakmaya gerek var mı?" diye sordu; cevap hayırdır, çünkü tek bir farklı eleman matrislerin farklı olduğunu kesinleştirir.

### 2.1 İki çözüm yolu ve verimlilik

Hoca problemi çözmenin iki yolu olduğunu söyledi:

- Bütün elemanları kontrol etmek; farklı bir eleman varsa matrisler farklıdır.
- Farklı bir eleman görene kadar kontrole devam etmek; farklı eleman görüldüğü anda kontrolü bırakmak.

Daha verimli olan ikincisidir, yani farklı olanı bulana kadar bir `while` ile ilerlemektir. Hoca bunu bir resim dosyasıyla açıkladı: 1024 x 768, 1600 x 1000 ya da 2400 x 1600 gibi boyutlarda bir resim düşünüldüğünde, üçüncü pikselde fark varsa geri kalan milyonlarca pikseli kontrol etmenin bir anlamı yoktur.

Bu yüzden iki iç içe `for` döngüsüyle bütün matrisi gezip fark görüldüğünde bir değişkeni değiştirmek, döngü bitince de bu değişkene bakmak "akla gelen en kolay çözüm" olsa da hoca bunu geçerli bir çözüm saymadı. Özellikle ilk elemanı farklı olan büyük bir matriste bu çözüm boşu boşuna işlem yapar.

> **Hocanın vurgusu:** Burada yapılacak şeyin bir şartın kontrolü olduğunu fark etmek gerekir. Sonra bu şartın döngünün neresine, nasıl yerleşeceği düşünülmelidir. Belli adım sayısı kadar dönmek değil, belli bir koşul sağlandığı sürece dönmek ya da sağlanmadığında döngüden çıkmak gerekir.

## 3. Matris Eşitliğinde Döngü Şartını Kurmak

Hoca bu soruyu sınıfla birlikte tartıştı ama tam çözümünü vermedi; öğrencilerin üzerinde düşünmesini istedi.

**Soru:** Bir öğrenci, `while` içinde A'nın ve B'nin aynı konumdaki elemanlarının eşit olup olmadığına bakmayı önerdi: eşitse döngü devam eder, değilse döngüden çıkılır. Döngünün içinde de sütun indisi artırılır, satır sonuna gelinince sütun indisi sıfırlanıp satır indisi artırılır.

**Cevap:** Hoca öneriyi şöyle özetledi: bir `while` döngüsü var, şartı "A[i][j] eşittir B[i][j]"; eşit olduğu sürece döngüye girilip önce j, j sınıra ulaşınca da i artırılıyor. Sonra şu soruyu sordu: iki matris aynıysa bu döngüden çıkılabilir mi? Çıkılamaz; bütün elemanlar eşitse şart hiç yanlış olmaz ve indisler matrisin dışına taşar. Bu yüzden şart yalnız elemanların karşılaştırılmasından oluşamaz.

Öğrenci bunun üzerine `for` eklemeyi ya da şartı "ve" (`&&`) ile genişletmeyi önerdi. Hoca burada asıl sorunun net bir plan olmadan denemeyle ilerlemek olduğunu söyledi: derste hoca ile öğrenci arasındaki konuşma hep denemeye dayanır, hoca da olmuyorsa nedenini düşündürecek bir cevap verir; ama sınavda bir yerden başlayıp tam bir çözüme ulaşmak gerekir.

Dersin ilerleyen kısmında başka bir öğrenci, sınavda i'leri `for` ile, j'leri `while` ile kontrol etmeyi düşündüğünü, `while` içinde i ile j'yi aynı anda nasıl artıracağını bulamadığını söyledi. Hoca, bunun düşünerek değil çizerek bulunacağını söyledi ve şu soruları düşünmeyi önerdi: bir `while` mı, iki `while` mı, üç `while` mı çizilecek; şart kısmına bir şart mı, iki şart mı yazılacak?

> **Hocanın vurgusu:** Sadece A ve B matrislerinin ilgili gözlerini karşılaştıran bir `while` döngüsüyle, matrisler aynı olduğunda döngüden çıkılamaz. Yapının daha farklı kurulması gerektiğini fark etmek gerekir.

Hocanın verdiği ipuçlarına uyan bir akış `Örnek Sorular` bölümünde, "derste verilmedi" notuyla yer alıyor.

## 4. Akışın C ile Kodlanması

İkinci soru şuydu (ekrandan, 00:35:00):

> Yukarıdaki şekilde akışı verilen algoritmayı C programlama dilinde kodlayınız. Hazırladığınız kodunuza ait kaynak dosyasını sisteme yükleyiniz.

Hoca bu soruda zor bir şey olmadığını söyledi: akış basit, iç içe karmaşık döngüler içermiyor. Kod yazılamadıysa sorun büyük olasılıkla C ortamına yeterince alışılmamış olmasıdır.

> **Hocanın vurgusu:** `main`'in nasıl yazıldığı, `return` ya da `#include` gibi şeyler düşünülmeden, ana fonksiyon hızlıca oluşturulup devam edilebilmelidir. Bunun yolu pratik yapmaktır.

## 5. Sütun Takası Sorusu

Üçüncü soru şuydu (ekrandan, 00:35:00):

> Verilen bir matrisin, istenilen iki farklı sütunun yerlerini değiştiren algoritmaya ait akış diyagramını çiziniz.

Sorudaki örnek: 3 x 5 boyutlarındaki A matrisinin birinci ve dördüncü sütunlarının yerlerinin değiştirilmesi.

```text
Matrisin İlk Hali     Matrisin Son Hali
1 2 3 4 5             4 2 3 1 5
6 7 8 9 0             9 7 8 6 0
1 2 3 4 5             4 2 3 1 5
```

Hoca bu sorunun "sınav sorusu olmayacak kadar basit" olduğunu söyledi ve akışı sözlü olarak tarif etti:

1. Bir okuma kutusunda N, M ve A matrisi okunur.
2. Değiştirilecek iki sütun numarası (X ve Y) okunur; bunlar aynı okuma kutusunda da okunabilir. Örnekte X = 1, Y = 4'tür.
3. Satır sayısı kadar dönen tek bir `for` döngüsü kurulur. Her satırda 1. sütundaki eleman ile 4. sütundaki eleman yer değiştirir: ilk satırda 1 ile 4, ikinci satırda 6 ile 9, üçüncü satırda yine 1 ile 4.
4. Takas için geçici bir değişken kullanılır: örneğin birinci satır birinci göz `tmp`'ye atanır, birinci satır dördüncü sütundaki değer onun yerine atanır, sonra `tmp` birinci satır dördüncü sütuna atanır. Döngü satır satır aşağı iner.
5. Sonunda matris bir `for` döngüsüyle yazdırılır.

Hoca bu akışın konuyu bilen biri için beş ile on dakikada çizilebileceğini söyledi. Bu akışı çizemeyen birinin akış çizmeyle ilgili ciddi bir sorunu, yani hangi şeklin ne işe yaradığıyla ilgili bir eksiği vardır.

### 5.1 Sınır kontrolü üzerine bir soru-cevap

**Soru:** Bir öğrenci, girilen sütun numaraları matris boyutundan büyükse yeniden girilmesini sağlamak için akışında do-while yapısı kullandığını, bunun sorun olup olmadığını sordu.

**Cevap:** Hoca öğrencinin akışını ekranda gösterdi (ekrandan, 00:55:00). Akışta "değiştirilmesini istediğiniz sütun değerlerini giriniz" mesajı yazdırılıyor, ardından X ve Y okunuyor; sonra "X ya da Y sınırdan büyük mü" diye bakan bir karar kutusundan çıkan ok, okuma kutusuna soldan geri giriyordu. Hoca üç noktayı işaretledi:

- Derste okuma kutusuna hiçbir zaman soldan girilmedi; okuma kutusunun sağından, solundan ya da üstünden çıkış da yapılmadı.
- Yazdırılan metin bir değişken değilse tek ya da çift tırnak içinde yazılmalıdır.
- Kullanılan sembollerden biri derste gösterilmemişti. <!-- BELİRSİZ: Hocanın "böyle bir sembol göstermedim" dediği sembolün hangisi olduğu altyazıdan ve kareden kesin anlaşılmıyor. -->

Hoca, sütun numaralarının boyutu aşıp aşmadığı kontrol edilmek isteniyorsa bunun bir `if` ile kontrol edilip program sonlandırılarak ya da bir `while` döngüsüyle yapılabileceğini söyledi; kontrol etmemek de bir seçenekti.

## 6. Akış Diyagramı Kurallarının Tekrarı

Hoca sınav kâğıtlarında görülen akış hatalarını genel olarak da sıraladı. Bazı akışlarda bir `if`'in bir kolu bir yöne, diğer kolu başka bir yöne gidiyor, kollar yukarı ve aşağı dönüyor, bir `if`'in kolu başka bir `if`'in koluyla birleşiyordu. Hoca bunun için akış çizimiyle ilgili slaytlara ve ders notlarına dönülmesini, ardından pratik yapılmasını önerdi.

İnternetteki kaynaklar konusunda da uyardı: farklı kaynaklar aynı sembolü farklı anlamlarla kullanır; bazıları bir sembolü `if` olarak, bazıları başka bir şey olarak kullanır, girişler ve çıkışlar da farklı yönlerdendir. Bunun nedeni o kaynakların farklı alanlardan (inşaat, elektrik vb.) gelmesidir. Derste kullanılan akış gösterimi bu ders için tanımlanmış bir yapıdır ve esas alınması gereken odur.

> **Hocanın vurgusu:** Derste verilmeyen bir sembolü başka bir yerden bulup akışa zorla yerleştirmek, bir çocuğun lego tahtasında karenin gireceği yere çekiçle üçgen sokmaya çalışmasına benzer. Önce verilen yapıyı öğrenin; temiz, sade, anlaşılır akışlar çizin. Burada beklenen, akışa yeni bir soluk getirmek değildir.

## 7. for ile while Arasındaki Seçim

**Soru:** Bir öğrenci, `for` döngüsünü i, n'e ulaşmadan bir komutla bitirip bitiremeyeceğini sordu; örneğin döngü içinde i'ye n + 1 atayarak döngüyü bütün elemanları kontrol etmeden sonlandırmak.

**Cevap:** Hoca önce neden erken bitirmek istendiğini sordu. Öğrenci, matris eşitliği sorusunda i'leri `for` ile, j'leri `while` ile kontrol etmeyi düşündüğünü söyledi. Hoca derste defalarca konuşulan kuralı yineledi:

- Bir iş n adımda yapılacaksa, yani tekrar sayısı belliyse `for` kullanılır.
- Amaç adım adım n kere tekrarlamak değil de belli bir şart (ya da birkaç şart) oluşana ya da oluşmayana kadar tekrarlamaksa `while` kullanılır.

`for` içinden n'e ulaşmadan çıkmak isteniyorsa bu iş `while` ile yapılmalıdır. `for` döngüsünü bozarak çıkmak `break`, `continue` gibi yapılar demektir ve bunlar bu derste kullanılmaz. Hoca bunun mühendislik açısından yanlış bir düşünce olduğunu, iki aracın amacının iyi kavranmadığını gösterdiğini söyledi.

Hoca gerekçe olarak şunları verdi:

- Bilgisayar sistemleri daha hızlı çalışabilmek için önbellekleme (caching) ve boru hattı (pipelining) gibi optimizasyonlar kullanır. Hoca, bir `for` döngüsü kurulduğunda arka tarafta bu yapıların buna göre oluştuğunu, döngüden olması gerekenden önce çıkmanın bu düzeni bozduğunu söyledi.
- `for` döngüsü bir `while` gibi de yazılabilir; üç alanı da boş bırakılarak sonsuz döngü kurulabilir. Bunların bazıları makuldür: örneğin 7/24 hizmet veren bir sunucu sisteminde durmak gibi bir amaç yoktur, sonsuz döngü gerekir. Bu döngü `for` ile ya da hep doğru olan bir şartla `while` ile kurulabilir.
- `while` ile yazılması gereken bir şeyi `for` içinde kurmak kodu anlaşılmaz kılar. Bu derste amaç, yazılan kodun okunabilir ve başkaları tarafından takip edilebilir olmasıdır.

> **Ders sonrası not:** Hocanın önbellek ve boru hattı gerekçesi büyük olasılıkla genel bir sezgi olarak verildi. Günümüz derleyicileri `break` ile biten bir `for` ile aynı işi yapan şartlı bir `while` döngüsünü çoğunlukla benzer makine koduna çevirir; döngüden erken çıkmanın asıl sakıncası, derste de söylendiği gibi, kodun okunabilirliğini ve döngünün amacını bulanıklaştırmasıdır.

## 8. Örnek Sorular

### Soru 1 (ekrandan, 00:30:00)

Verilen eşit boyutlardaki iki matrisin aynı olup olmadığını bulan algoritmaya ait akışı çiziniz. Eğer iki matrisin aynı pozisyondaki elemanlarının tamamının değerleri eşit ise matrisler aynıdır. Aksi takdirde matrisler farklıdır. (Örnek matrisler 2. bölümde.)

Derste beklenen yaklaşım: ilk farklı elemanda duran, şarta bağlı bir `while` yapısı. Hoca tam akışı vermedi.

> **Çözüm (derste verilmedi):** Aşağıdaki akış, hocanın ipuçlarına (ilk farkta durmak, şartın hem sınırı hem eşitliği içermesi, `break` kullanmamak) göre ajan tarafından kuruldu. İndisler derste kullanılan akış gösterimindeki gibi 1'den başlar.
>
> ```text
> BAŞLA
> N, M, A, B oku
> esit <- 1
> i <- 1
> while (i <= N VE esit = 1)
>     j <- 1
>     while (j <= M VE esit = 1)
>         if (A[i][j] != B[i][j])
>             esit <- 0
>         j <- j + 1
>     i <- i + 1
> if (esit = 1)  "Matrisler aynı" yaz
> değilse        "Matrisler farklı" yaz
> BİTİR
> ```
>
> Eşit olmama örneğinde döngü, beşinci karşılaştırmada (2. satır, 2. sütun, 6 ile 4) `esit` değişkeni 0 olunca her iki döngü şartı da yanlış olduğu için durur; geri kalan dört elemana bakılmaz. Matrisler aynıysa döngüler i ve j sınırı aşınca biter.

### Soru 2 (ekrandan, 00:35:00)

Yukarıdaki şekilde akışı verilen algoritmayı C programlama dilinde kodlayınız.

> **Çözüm (derste verilmedi):** Aşağıdaki kod derste yazılmadı; ajan tarafından yukarıdaki akışa göre yazıldı, `gcc -Wall` ile uyarısız derlendi ve sorudaki iki örnekle denendi (eşitlik örneğinde "Matrisler ayni", eşit olmama örneğinde "Matrisler farkli" çıktısı alındı). C'de indisler 0'dan başlar.
>
> ```c
> #include <stdio.h>
>
> int main() {
>     int A[10][10], B[10][10];
>     int n, m, i, j, esit;
>
>     scanf("%d %d", &n, &m);
>     for (i = 0; i < n; i++)
>         for (j = 0; j < m; j++)
>             scanf("%d", &A[i][j]);
>     for (i = 0; i < n; i++)
>         for (j = 0; j < m; j++)
>             scanf("%d", &B[i][j]);
>
>     esit = 1;
>     i = 0;
>     while (i < n && esit == 1) {
>         j = 0;
>         while (j < m && esit == 1) {
>             if (A[i][j] != B[i][j])
>                 esit = 0;
>             j++;
>         }
>         i++;
>     }
>
>     if (esit == 1)
>         printf("Matrisler ayni\n");
>     else
>         printf("Matrisler farkli\n");
>     return 0;
> }
> ```

### Soru 3 (ekrandan, 00:35:00)

Verilen bir matrisin, istenilen iki farklı sütunun yerlerini değiştiren algoritmaya ait akış diyagramını çiziniz. Örnek: 3 x 5 boyutlarındaki A matrisinin birinci ve dördüncü sütunlarının yerlerinin değiştirilmesi (ilk ve son hal 5. bölümde).

**Derste verilen çözüm (sözlü, 00:36:23):** N, M ve A okunur; X ve Y sütun numaraları okunur; satır sayısı kadar dönen tek bir `for` içinde her satırın X. ve Y. gözleri `tmp` ile takas edilir; son olarak matris yazdırılır (adımlar 5. bölümde).

> **Çözüm (derste verilmedi):** Akışın C karşılığı derste yazılmadı. Ajan tarafından yazılan aşağıdaki kod `gcc -Wall` ile uyarısız derlendi; sorudaki matris ve X = 1, Y = 4 girdisiyle ekrandaki son hal (`4 2 3 1 5 / 9 7 8 6 0 / 4 2 3 1 5`) elde edildi.
>
> ```c
> #include <stdio.h>
>
> int main() {
>     int A[10][10];
>     int n, m, i, j, x, y, tmp;
>
>     scanf("%d %d", &n, &m);
>     for (i = 0; i < n; i++)
>         for (j = 0; j < m; j++)
>             scanf("%d", &A[i][j]);
>     scanf("%d %d", &x, &y);   /* 1'den baslayan sutun numaralari */
>
>     for (i = 0; i < n; i++) {
>         tmp = A[i][x - 1];
>         A[i][x - 1] = A[i][y - 1];
>         A[i][y - 1] = tmp;
>     }
>
>     for (i = 0; i < n; i++) {
>         for (j = 0; j < m; j++)
>             printf("%d ", A[i][j]);
>         printf("\n");
>     }
>     return 0;
> }
> ```

### Soru 4 (derste sözlü, 00:59:39)

Bir `for` döngüsü, i değişkeni n'e ulaşmadan içeriden bir komutla (örneğin i'ye n + 1 atanarak) bitirilebilir mi, bu doğru bir yaklaşım mıdır?

**Derste verilen cevap:** Teknik olarak döngü bozulabilir, ama bu yaklaşım yanlıştır. Tekrar sayısı belli olmayan, bir şarta bağlı olarak sona erecek döngü `while` ile kurulmalıdır; `for` içinden erken çıkmak (`break`, `continue` vb.) bu derste kullanılmaz (ayrıntı 7. bölümde).

## Dersin Toparlaması

Bu derste ikinci ara sınavın üç sorusu üzerinden döngü ve akış tasarımı tekrar edildi. Matris eşitliği sorusu, tekrar sayısı belli olan bir tarama ile şarta bağlı bir arama arasındaki farkı gösterdi: iki matrisin farklı olduğunu anlamak için tek bir farklı eleman yeterlidir, bu yüzden çözüm ilk farkta duran bir `while` yapısıyla kurulmalıdır; ama döngü şartı, matrisler aynı olduğunda da döngünün bitmesini sağlayacak şekilde sınır kontrolünü içermelidir. Sütun takası sorusu ise tek bir `for` döngüsü ve geçici bir değişkenle çözülen basit bir yapıydı.

Hoca bunlara ek olarak akış çiziminde derste verilen gösterime bağlı kalmanın (okuma kutusuna üstten girmek, sabit metni tırnak içinde yazmak, başka kaynaklardan sembol almamak) ve döngü türünü amaca göre seçmenin (`for` için belli tekrar sayısı, `while` için şart; `break`/`continue` yok) önemini vurguladı. Matris eşitliği akışının doğru biçimde kurulması, öğrencilerin kendi başlarına üzerinde çalışması için bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
