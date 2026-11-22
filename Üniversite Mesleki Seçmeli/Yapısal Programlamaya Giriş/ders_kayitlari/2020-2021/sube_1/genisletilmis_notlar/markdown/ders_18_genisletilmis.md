# Ders 18 Genişletilmiş Notu: Fonksiyonlar: Akış Diyagramında Gösterim, Parametrik Tasarım, Aşırı Yükleme ve Uygulama Problemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Fonksiyon nedir?
- 2. Fonksiyon yazmanın faydaları
- 3. Fonksiyon çağrısının maliyeti: yığın (stack)
- 4. Belgeleme ve isimlendirme
- 5. Fonksiyonun akış diyagramında gösterimi: max_bul
- 6. Parametrik fonksiyonlar: sirala ve minmax
- 7. Fonksiyon aşırı yükleme: matris için minmax
- 8. Birbirine en yakın iki nokta
- 9. Uzaklık ölçüleri üzerine sorular
- 10. Çöpçatan sitesi problemi
- 11. void
- 12. Doktor, hasta ve teşhis problemleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Fonksiyon nedir?

Dersin konusu fonksiyonlardır. Hoca kaba bir tanımla başlar: fonksiyon, **isimlendirilmiş** ve **parametre alabilen** bir algoritmadır (ekrandan, 00:10:00). Tanımdaki en önemli özellik isimlendirilmiş olmasıdır, çünkü fonksiyon başka algoritmalar tarafından adıyla çağrılıp kullanılsın diye yazılır.

Fonksiyonla ilgili iki taraf vardır: fonksiyonu **çağırmak** ve fonksiyonu **yazmak**. Çağırma tarafının genel yazımı şöyledir (ekrandan, 00:10:00):

```text
[çıkış parametreleri] = fonksiyon_ismi(giriş parametreleri)
```

Bu satır başka bir algoritmanın ya da başka bir fonksiyonun içinde kullanılır. Hoca burada "çıkış parametreleri" diye çoğul yazdığını, çünkü algoritmalarda dilden bağımsız, genel bir yapı kullandıklarını belirtir. Her dil birden fazla çıkışı desteklemez; C dahil bazı diller tek bir değer döndürür. Bu genellikle yeterlidir: C'de bir dizi ya da matris döndürülmek istendiğinde, onun bellekte başladığı adres döner ve oradan itibaren bellek okunarak işlem yapılır.

### 1.1 Hazır fonksiyonlar ve kütüphaneler

Bugüne kadar yazılan C programlarında farkında olmadan fonksiyonlar kullanıldı. C'nin ana programı olan `main` de aslında bir fonksiyondur. `main` içinde kullanılan `printf` bir fonksiyondur ve parametre alır: hem ekrana yazdırılacak şeyi hem de hangi biçimde yazdırılacağını. `scanf` de kullanıcıdan değer okumak için yazılmış bir fonksiyondur. Bunları başkaları yazmıştır; programcı yeniden yazmaz, alıp kullanır.

Dille birlikte gelen bu fonksiyonlar kütüphanelerde durur. Programın başında `include` edilen, uzantısı `.h` olan `stdio`, `stdlib`, `math`, `time` gibi dosyalar bu hazır fonksiyon kütüphanelerinin başlık (header) dosyalarıdır. Fonksiyon kütüphanesi, fonksiyonlar topluluğu demektir. Programcı kendi fonksiyonlarını da yazıp küçük modüller hâlinde bir yerde biriktirebilir ve gerektiğinde, `printf` gibi, defalarca kullanabilir.

## 2. Fonksiyon yazmanın faydaları

### 2.1 Bir kez yaz, hep kullan

İlk ve en temel fayda: **bir kez yaz, hep kullan / kullansınlar** (ekrandan, 00:10:00). Bir algoritma bir kez yazıldıktan sonra başka bir yerde de kullanılacaksa fonksiyon hâline getirilmelidir. Sıralama gibi işler çok sık kullanılan parçalardır. Hoca bunları Lego parçalarına benzetir: kişi bu parçaları bir kez oluşturur, sonra istediği kadar, istediği yerde kullanır.

### 2.2 Birlikte çalışma

"Kullansınlar" ifadesi başka bir şeyi de çağrıştırır: birlikte çalışmak. Fonksiyonlar büyük bir projede birden fazla yazılımcının aynı anda çalışmasını sağlamanın yoludur. Proje parçalara bölünür, her parça bir fonksiyon olarak düşünülür, ekipteki herkes kendine düşen parçayı yazar ve en sonunda parçalar ana bir yapıda birleştirilir. Hoca, günümüzde yazılım dünyasında hiçbir problemin tek başına çözülmediğini, işin genellikle bir ekiple yapıldığını söyler. Herkesin aynı ana yapıyı değiştirmesi etkili değildir; parçaları belirleyip her kişiye bir parça vermek çok daha makul bir yaklaşımdır.

### 2.3 Kolay düzeltme

Bir dizinin en büyük elemanını bulan bir fonksiyon yazıldığını düşünelim. İki yol vardır:

- Fonksiyonu bir kez yazıp kaydetmek ve diğer algoritmalarda onu çağırmak.
- Fonksiyon kullanmadan, gereken her yere en büyüğü bulan kodun kendisini koymak.

Sonradan kodda bir hata fark edildiğini varsayalım: örneğin en büyük yerine en küçük bulunuyor ya da hep sabit bir değer döndürülüyor. Hoca öğrencilere hangi yapıda düzeltmenin daha kolay olacağını sorar. Cevap fonksiyonlu yapıdır: hata tek bir yerde düzeltilir ve her yerde düzelmiş olur. Kopyalanmış yapıda ise her kopyanın ayrı ayrı bulunup değiştirilmesi gerekir.

### 2.4 Kolay güncelleme

Fonksiyon her zaman yanlış yazıldığı için değişmez; bazen yapması gereken iş değişir. Örneğin eskiden yalnız dizinin en büyük elemanının değerini döndüren fonksiyondan artık bu elemanın yerinin (indisinin) de döndürülmesi istenebilir. Fonksiyonlu yapıda güncelleme tek bir yerde yapılır ve her yerde geçerli olur.

## 3. Fonksiyon çağrısının maliyeti: yığın (stack)

Hoca fonksiyonların programı hızlandırmak için yapılmadığını, aksine biraz yavaşlattığını vurgular. Nedenini bir şekille açıklar (ekrandan, 00:20:00). Sağdaki şekilde ana program 1, 2, 4, 5, 6 numaralı kısımlardan oluşur ve aralarda 3 numaralı fonksiyon çağrılır. Program çalışırken bir yerde fonksiyona atlar, orada çalışır, işi bitince kaldığı yere döner ve devam eder. Soldaki şekilde ise 3 numaralı kodun içeriği her kullanıldığı yere kopyalanmıştır: 1, 3, 2, 3, 4, 3, 5, 3, 6 sırası düz bir çizgi hâlinde, hiç atlamadan çalışır. Hoca soldaki yapının "daha hızlı" olduğunu belirtir.

Yavaşlığın kaynağı şudur. Program çalışırken **yığın (stack)** adı verilen bir bellek bloğu kullanılır. Örneğin program 1'inci satırdan 23'üncü satıra kadar gelmiş ve 23'üncü satırda bir fonksiyon çağrılmış olsun. Fonksiyon, bulunduğu başka bir bellek bölgesinde çalışır; bittiğinde program 23'üncü satıra dönüp 24, 25 diye devam edecektir. Bunun için hangi satırda kalındığı (program sayacı) ve o ana kadar tutulan değişkenlerin değerleri bir yerde saklanmalıdır.

Hepsinin saklanması gerekir, çünkü ana programdaki kod da fonksiyonun kodu da aynı işlemcide, aynı yerde çalışır. Değişkenler birbirine karışmamalıdır. Ana programda `A` adlı bir değişken, fonksiyonda da yine `A` adlı bir değişken olabilir. Fonksiyona gitmeden önceki `A`, fonksiyondaki `A` ile karışmamalıdır; biri fonksiyonun `A`'sı, diğeri ana programın `A`'sıdır.

Çağrılar iç içe de olabilir. Ana program A çalışırken F1 fonksiyonunu çağırır, F1 çalışırken de F2'yi çağırır. F2 bitince F1'e, F1 bitince A'ya dönülür. Bu sırada yığına önce A'nın değişkenleri ve program sayacı, sonra F1'in değişkenleri eklenir. F2 bitince F1'in değerleri, F1 bitince A'nın değerleri yığından çekilir. Yığın kelimesi de bunu anlatır: bilgiler üst üste yığılır. Yığına her ekleme ve yığından her çekme bir zaman maliyetidir. Bu yüzden fonksiyonun kodu her yere kopyalanırsa program daha hızlı çalışır.

Hoca bu ayrıntıların ileriki derslerde ayrıca işleneceğini söyler. Daha hızlı bir yol varken yine de fonksiyon kullanılmasının nedeni, yukarıdaki faydaların bu yavaşlamadan çok daha büyük olmasıdır. Diğer seçenek, yani kodu her yere kopyalamak, bakım açısından çok daha pahalıdır.

> **Hocanın vurgusu:** Fonksiyonlar programlar daha hızlı çalışsın diye yapılmış şeyler değildir; işi biraz yavaşlatırlar. Ama faydaları bu yavaşlamadan çok daha fazladır.

> **Ek bilgi (derste anlatılmadı):** Derleyiciler, küçük fonksiyonlarda çağrı maliyetinden kurtulmak için fonksiyonun gövdesini çağrıldığı yere kendileri yerleştirebilir (inlining). Böylece kaynak kodda fonksiyonun faydaları korunurken soldaki "kopyalanmış" yapının hızına yaklaşılır. C'de `inline` anahtar sözcüğü derleyiciye bu yönde bir ipucu verir.

## 4. Belgeleme ve isimlendirme

Her algoritma, fonksiyonlar gibi, iyi belgelenmelidir. Fonksiyonun kısıtları nelerdir, neleri ne zaman yapabilir ve ne zaman yapamaz, parametreleri nelerdir? Hoca burada parametre kelimesini de tanımlar: **parametre**, fonksiyona gönderilen şeylerdir (giriş parametreleri); fonksiyondan geri alınan şeyler de çıkış parametreleridir. Parametrelerin ne olduğu iyi açıklanmalıdır.

Bir fonksiyon ne kadar iyi belgelenmişse hem yazanın gelecekte kullanması hem de başkalarının kullanması o kadar kolaylaşır. Hoca, şimdi gereksiz gelebileceğini ama beş yıl önce yazılmış, iyi belgelenmemiş bir kodu kişinin kendisinin bile anlamasının çok zor olduğunu söyler. On dakika önce yazılan bir şey hatırlanır; iki üç yıl önce yazılmış bir fonksiyonun ne yaptığı ise kodda yazmıyorsa hemen hatırlanamaz ve yeniden çözülmesi gerekir. Kod zekice yollarla çözülmüşse hatırlamak daha da zorlaşır.

Belgelemede önemli noktalardan biri değişken ve fonksiyon adlarıdır. En büyüğü bulan fonksiyona `f1`, en küçüğü bulan fonksiyona `f2`, diziyi sıralayan fonksiyona `f3` adını vermek iyi bir hareket değildir. Ad, fonksiyonun yaptığı işi hatırlatmalıdır. Değişkenler için de aynısı geçerlidir. Bir değişkenin ya da fonksiyonun adının uzun olması sorun değildir; önemli olan ne yaptığının ya da ne tuttuğunun iyi bilinmesidir.

## 5. Fonksiyonun akış diyagramında gösterimi: max_bul

İlk örnek fonksiyon bir dizinin en büyük elemanını bulur. Hoca önce fonksiyonun nasıl çağrılacağını, sonra akış diyagramının nasıl çizileceğini gösterir.

### 5.1 Çağrı

Başka bir algoritmanın içinde şöyle yazılabilir (ekrandan, 00:35:00):

```text
[maxD, max_ind] = max_bul(A, N)
```

Burada `A` dizi, `N` dizinin boyutudur. Fonksiyona dizi ve boyutu gönderilir; dönüş olarak en büyük değer (`maxD`) ve onun indisi (`max_ind`) alınır. Bu satırdan önce `maxD` ve `max_ind` değişkenleri ortada yoktur. Fonksiyon çağrıldıktan sonra bu değerlerin üretildiği bilinir ve o noktadan itibaren kullanılabilir, örneğin başka bir değişkene atanabilir ya da başka işlemlerde kullanılabilir.

### 5.2 Fonksiyonun çizimi

Gösterim çok basittir (ekrandan, 00:35:00):

```text
 / fonksiyon_ismi(giriş parametreleri) \
 \ çıkış parametreleri                 /
                  |
            (algoritma)
                  |
              ( return )
```

İki katlı başlangıç şeklinin üst kısmı fonksiyonun adını ve parantez içinde giriş parametrelerini, alt kısmı çıkış parametrelerini içerir. Bu şekil, algoritmanın bir fonksiyon olduğunu anlatır. Altına normal algoritma çizilir ve en sonda `return` ile dönülür. `return` denildiğinde çıkış parametrelerinin değerleri ana programa ya da fonksiyonu çağıran fonksiyona döndürülür.

`max_bul` için başlangıç şeklinin üst kısmına `max_bul(A, N)`, alt kısmına `maxD, max_ind` yazılır. Hoca önemli bir noktayı vurgular: `A` ve `N` fonksiyona gelmiştir. Bunlar ana programda ya da bu fonksiyonu çağıran başka bir fonksiyonda okunup gönderilmiştir. Fonksiyon içinde yeniden okunmazlar, doğrudan kullanılırlar.

Algoritma şöyledir (altyazıdan kuruldu; bu diyagramın tam karesi yok):

```text
maxD = A[1], max_ind = 1
i = 2'den N'ye kadar, birer birer:
    eğer maxD < A[i] ise:
        maxD = A[i]
        max_ind = i
return
```

İlk değerler dizinin birinci elemanı ve indis 1 olarak atanır. Sonra i, 2'den N'ye kadar gider. `A[i]`, o ana kadarki en büyükten büyükse yeni en büyük değer ve indisi kaydedilir. Döngüden çıkınca `return` ile çağırana dönülür.

<!-- BELİRSİZ: max_bul akış diyagramının çizildiği an (00:34-00:36) kareler arasında kaldı; algoritma altyazıdan kuruldu. -->

## 6. Parametrik fonksiyonlar: sirala ve minmax

### 6.1 Neden parametrik?

Fonksiyonlar parametrik yazılmalıdır: değişebilecek şeyler dışarıdan parametre olarak alınır. Bu sayede fonksiyon sayısı azalır. Dört elemanlı bir diziyi sıralayan bir fonksiyon, sonra beş elemanlı, sonra yedi elemanlı diziler için ayrı fonksiyonlar yazmak makul değildir. Bunun yerine uzunluk N'yi parametre olarak alan ve herhangi bir uzunluktaki diziyi sıralayan tek bir fonksiyon yazmak çok daha mantıklıdır.

Aynı düşünce sıralama yönü için de geçerlidir. Küçükten büyüğe ve büyükten küçüğe sıralayan iki ayrı fonksiyon yazılabilir (ekrandan, 00:45:00):

```text
sirali_dizi = kbsirala(D, N)
sirali_dizi = bksirala(D, N)
```

Ancak ikisi de sıralama yapar; yalnız yönleri farklıdır. Bunun yerine ek bir yön parametresi alan tek fonksiyon daha mantıklıdır (ekrandan, 00:40:00):

```text
sirali_dizi = sirala(Dizi, N, y)
```

Buradaki `y`, büyükten küçüğe mi yoksa küçükten büyüğe mi sıralanacağını gösterir.

### 6.2 minmax fonksiyonu

Bir dizinin en küçüğünü ve en büyüğünü bulmak için de iki ayrı fonksiyon yerine tek bir fonksiyon yazılabilir (ekrandan, 00:45:00):

```text
[D, ind] = min_max(D, N, y)
```

Ek parametre (diyagramda `bk`) büyüğün mü küçüğün mü istendiğini söyler. Bunun nasıl kodlanacağı tamamen tasarımcıya bağlıdır. Hoca şu kuralı seçer: kullanıcı `bk = 1` gönderirse en büyük eleman, `bk = 0` gönderirse en küçük eleman bulunur. Bu kural fonksiyonun belgesine mutlaka yazılmalıdır.

Fonksiyonun akış diyagramı (ekrandan, 00:45:00). Değer, dizinin adıyla karışmasın diye küçük `d` ile gösterilir:

```text
 / minmax(D, N, bk) \
 \ d, ind           /
          |
   d = D[1], ind = 1
          |
      bk == 1 ?
   T /         \ F
i = 2..N        i = 2..N
  d < D[i] ?      (aynı yapı, karşılaştırma ters:
   T: d = D[i]     daha küçük eleman aranır)
      ind = i
      \         /
        return
```

Doğru kolunda (`bk == 1`) en büyük aranır: i, 2'den N'ye kadar gider ve `d < D[i]` ise `d = D[i]`, `ind = i` yapılır. Yanlış kolunda aynı yapı kurulur, tek fark karşılaştırmanın ters olmasıdır. İki kol birleşir ve `return` ile biter.

> **Ders sonrası not:** Ekrandaki diyagramın atama kutusunda `d = A(i)` yazıyor (ekrandan, 00:45:00). Fonksiyonun dizisi `D` olduğu için doğrusu `d = D[i]`'dir; hoca anlatırken de D dizisini kullandığını söylüyor.

Böylece minimumu ve maksimumu bulan iki ayrı fonksiyon yerine tek bir fonksiyon yazılmış olur. Hoca, kullanıcıdan alınan parametrelerle fonksiyonun işleyiş biçimini değiştirmenin genel olarak çok daha mantıklı bir çözüm olduğunu söyler.

## 7. Fonksiyon aşırı yükleme: matris için minmax

### 7.1 Tanım

Aradan sonra yeni bir kavram işlenir: **function overloading** (fonksiyon aşırı yükleme) (ekrandan, 01:10:00). Bu, aynı isimli birden fazla fonksiyon yazmaktır. Bu fonksiyonlar farklı ama birbiriyle ilişkili işler yapar. Aynı isimli fonksiyonlar yazmakta bir sakınca yoktur; ancak giriş parametreleri birbirinden farklı olmalıdır. Adları aynı, giriş kısımları da tamamen aynı iki fonksiyon yazılamaz; hangisinin çağrılacağı anlaşılamaz.

Hoca farkın ne olması gerektiğini açar. Parametrelerin yalnız adlarının farklı olması yetmez; örneğin birinde dizinin adı `D1`, diğerinde `A` olsa ama ikisi de dizi tipinde olsa bu olmaz. Tipler farklı olmalıdır. Farklı tipteki parametrelerin sırası farklıysa bu da kabul edilir. Sıralar da tipler de aynıysa olmaz.

### 7.2 Örnek

Az önce yazılan dizi için `minmax`'a ek olarak bir matris için `minmax` tanımlanır (ekrandan, 01:10:00):

```text
[D, ind] = minmax(D, N, bk)              -> dizi
[D, ind] = minmax(matris, M, N, bk)      -> matris
```

Matris sürümü, matrisin en büyük ya da en küçük elemanını bulur. Bunun için satır sayısına (M), sütun sayısına (N) ve yine `bk`'ye ihtiyaç vardır. Hoca bunu farklı biçimlerde yapmanın mümkün olduğunu, ama alttaki `minmax`'ı üstteki `minmax`'ı kullanarak yazacağını söyler.

Akış diyagramı (ekrandan, 01:10:00):

```text
 / minmax(matris, M, N, bk) \
 \ D, ind                   /
          |
i = 1..M:   K[i] = 0
          |
i = 1..M:
    j = 1..N:   A[j] = matris[i, j]
    [K[i], ind] = minmax(A, N, bk)
          |
[D, ind] = minmax(K, M, bk)
          |
       return
```

Önce M uzunluğundaki K dizisinin bütün elemanları sıfırlanır. Sonra her i satırı için iki iş yapılır. İlk olarak matrisin i'inci satırı j döngüsüyle A dizisine kopyalanır. Ardından A dizisinin en büyük (ya da en küçük) elemanı dizi sürümü `minmax` ile bulunur ve `K[i]`'ye yazılır. Böylece K dizisinde her satırın en büyükleri (ya da en küçükleri) birikir. Son olarak K dizisinin en büyüğü (ya da en küçüğü) yine `minmax` ile bulunur.

Hoca `bk` değeriyle hiç ilgilenilmediğine dikkat çeker. `bk` diğer fonksiyona olduğu gibi geçirilir: fonksiyon "büyük" ile çağrıldıysa içteki çağrılar da "büyük" ile, "küçük" ile çağrıldıysa "küçük" ile yapılır. Bu örnek hem fonksiyon içinde fonksiyon çağırmanın hem de aşırı yüklemenin güzel bir örneğidir.

### 7.3 Dönen indis neyi gösterir?

Hoca öğrencilere sorar: buradaki `ind` aslında neyi gösterir? Bir öğrenci en küçük ya da en büyük elemanın kaçıncı eleman olduğunu söyler. Hoca örnek verir: diyelim ki en küçük eleman matrisin 4'üncü satırının 3'üncü elemanında olsun. Son çağrı K dizisi üzerinde yapıldığı için dönen indis, K dizisindeki indis, yani elemanın bulunduğu **satırdır** (4). O satırın kaçıncı elemanı olduğunu (3) döndürmez. Bunu bulmak için ek bir şeyler yapmak gerekir; hoca bu kısmın istenildiği gibi değiştirilebileceğini söyler.

### 7.4 Diğer yol

Hoca başka bir yol da gösterir: matrisin bütün elemanları tek bir A dizisine atanabilir. Bu dizinin boyutu M x N olur ve tek bir çağrıyla sonuç alınır:

```text
[D, ind] = minmax(A, M*N, bk)
```

Bu da çok farklı bir işlem değildir.

## 8. Birbirine en yakın iki nokta

### 8.1 Tek boyutlu noktalar

Örnek problem: bir boyutlu noktalar, yani bir sayı doğrusu üzerinde duran noktalar vardır (ekrandan, 01:15:00). Hoca sayı doğrusu üzerinde 1'den 8'e kadar numaralanmış sekiz nokta çizer ve bu noktalar içinde birbirine en yakın iki noktanın indislerini sorar. Şekilde örneğin 7 ile 8 ya da 4 ile 5 birbirine çok yakın görünür; hoca 3 ile 4'ün değil, 4 ile 5'in döneceğini söyler.

Noktalar bir dizi olarak düşünülebilir. Fonksiyonun prototipi şöyledir (ekrandan, 01:20:00):

```text
[ind1, ind2] = enyakin(A, N)
```

N elemanlı A dizisinde birbirine en yakın iki elemanın indisleri `ind1` ve `ind2`'ye döner. Hoca somut bir dizi verir (ekrandan, 01:20:00):

| İndis | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| Değer | 7 | 9 | 6 | 3 | 12 | 15 |

Burada birbirine en yakın ikili 7 ile 6'dır, aradaki fark 1'dir. Fonksiyon bu yüzden 1 ve 3 indislerini döndürür (ekranda `(1 - 3)`). Hoca öğrencilere birkaç dakika süre verir, sonra çözümü anlatır.

### 8.2 Çözümün mantığı

Dizideki her eleman için bir iş yapılacağından dışta bir döngü gerekir: i, 1'den başlar. Her eleman için diğer bütün elemanlarla karşılaştırma yapılmalıdır. İçteki döngü de 1'den N'ye kadar götürülebilir, ama bu çok manalı değildir; bir elemanı kendisiyle karşılaştırmanın anlamı yoktur. Bulunduğu yerden sonrasına gitmek yeterlidir: j, i + 1'den N'ye kadar gider.

Hoca karşılaştırma sırasını örnek dizi üzerinde sayar: önce 7 ile 9, 7 ile 6, 7 ile 3, 7 ile 12, 7 ile 15; sonra 9 ile 6, 9 ile 3, 9 ile 12, 9 ile 15; sonra 6 ile 3, 6 ile 12, 6 ile 15; sonra 3 ile 12, 3 ile 15; en sonda 12 ile 15. Her karşılaştırmada ikili arasındaki farkın o ana kadarki en küçük farktan küçük olup olmadığına bakılır ve küçükse yeni minimum kaydedilir.

### 8.3 Akış diyagramı

Akış diyagramı (ekrandan, 01:25:00):

```text
 / enyakin(A, N) \
 \ ind1, ind2    /
        |
min_dist = ∞
ind1 = 0, ind2 = 0
        |
i = 1..N-1:
    j = i+1..N:
        |A[i] - A[j]| < min_dist ?
        T: min_dist = |A[i] - A[j]|
           ind1 = i
           ind2 = j
        |
     return
```

`min_dist` başlangıçta sonsuz, yani çok büyük bir sayı alınır. Böylece ilk karşılaştırmada mutlaka güncellenir. Dış döngü N - 1'e kadar gider, çünkü son elemandan sonra karşılaştırılacak eleman kalmaz. İki döngü bitince yapılacak başka bir iş yoktur, yalnız `return` yapılır. Hoca burada yapılabilecek başka bir hile de olmadığını söyler.

### 8.4 İki ve K boyutlu noktalar

Sonra problem değiştirilir: noktalar tek boyutlu değil, iki boyutlu olsun, yani bir düzlemde dursunlar. Hoca bir sonraki adımda ne sorulacağını kendisi söyler: K boyutlu olsalar ne olur? İki boyutu atlayıp doğrudan genel hâl çözülür.

Noktalar K boyutlu olunca A bir matris olur: N x K boyutunda. Burada N nokta sayısı, K boyut sayısıdır. Her satır bir noktadır. Fonksiyon `enyakin(A, N, K)` olur ve yapı neredeyse aynıdır (ekrandan, 01:35:00):

```text
 / enyakin(A, N, K) \
 \ ind1, ind2       /
        |
min_dist = ∞
ind1 = 0, ind2 = 0
        |
i = 1..N-1:
    j = i+1..N:
        dist = 0
        k = 1..K:
            dist = dist + |A[i, k] - A[j, k]|
        dist < min_dist ?
        T: min_dist = dist
           ind1 = i
           ind2 = j
        |
     return
```

İç döngüde `dist` değişkeni sıfırlanır ve k, 1'den K'ya kadar giderken A'nın i'inci satırının k'ıncı elemanı ile j'inci satırının k'ıncı elemanı arasındaki farkın mutlak değeri biriktirilir. Döngü bitince `dist`, K boyutlu uzaydaki iki nokta (i'inci ve j'inci satırlar) arasındaki uzaklıktır. Sonrası klasiktir: `dist < min_dist` ise yeni minimum ve indisler kaydedilir.

### 8.5 Problemi doğru anlamak

Bir öğrenci, i'inci ve j'inci satırın aynı sütundaki değerlerinin çıkarıldığını, ama en yakın sayıların farklı sütunlarda olabileceğini sorar (örneğin birinci satırın birinci değeri ile beşinci satırın onuncu değeri). Hoca problemin yanlış anlaşıldığını söyler ve bir örnek matris çizer (ekrandan, 01:40:00):

```text
     4   6   2   9   5     <- 1. nokta
     7  11   3   4  13     <- 2. nokta
     1   8   5   6  12     <- 3. nokta
     3   1   4   6   9     <- 4. nokta
```

<!-- BELİRSİZ: İkinci satırın ikinci değeri karede "11" gibi okunuyor; altyazı bu sayıları bozuk aktarıyor. Değer çözümü etkilemiyor. -->

Bu matriste aynı olan sayılar vardır, örneğin birinci satırdaki 6 ile üçüncü satırdaki 6. Hoca bu ikisini bulmaktan söz etmediğini söyler. Bu 4 x 5'lik matriste yalnız 4 nokta vardır ve her biri 5 boyutlu uzayda bir noktadır: birinci satır birinci nokta, ikinci satır ikinci nokta, vb. Karşılaştırılan, satırların kendisidir: 1 ile 2, 2 ile 3, 3 ile 4, 1 ile 3, 1 ile 4, vb.

Başka bir öğrenci aynı şeyi anlamadığını söyleyince hoca iki boyutlu bir örnek verir (ekrandan, 01:45:00). Dört satır, iki sütunluk bir matris: (4, 2), (1, 0), (3, 1), (4, 4). Her satır düzlemde bir noktadır ve hoca bunları koordinat ekseninde işaretler. Burada birbirine en yakın olanlar 1 ve 3 numaralı noktalardır. Öğrenci "koordinat olarak bakıyoruz yani" der; hoca onaylar: K boyutlu uzayda noktalar vardır ve aralarında en küçük mesafeye sahip nokta ikilisi aranır.

> **Ders sonrası not:** Bu örnekte 1 ile 3 numaralı noktaların L1 uzaklığı $|4-3| + |2-1| = 2$, L2 uzaklığı $\sqrt{2} \approx 1{,}414$'tür. 1 ile 4 numaralı noktaların L1 uzaklığı da $|4-4| + |2-4| = 2$'dir; L2 uzaklığı ise 2'dir. Yani diyagramdaki mutlak fark toplamıyla iki çift eşit çıkar; `<` karşılaştırması ilk bulunanı tuttuğu için fonksiyon yine 1 ve 3'ü döndürür. Öklid uzaklığıyla ise 1 ve 3 tek başına en yakın çifttir (python ile denetlendi).

## 9. Uzaklık ölçüleri üzerine sorular

K boyutlu çözümden sonra bir öğrenci şunu sorar: boyut sayısı arttıkça toplamların birbirine eşit olma olasılığı yükselir; farkların karesini alıp karekök içine alsak daha doğru olmaz mı?

**Soru:** Mutlak farkların toplamı yerine farkların karelerini toplayıp karekökünü almak daha doğru sonuç vermez mi?

**Cevap:** Hoca burada uzaklık fonksiyonu olarak mutlak değer kullandığını söyler; bu L1 normuna karşılık gelir. Öğrencinin önerdiği L2 normudur ve kullanılabilir; başka uzaklıklar da kullanılabilir. Ama birinin daha doğru olduğu söylenemez. Bu, noktaların dağılımına bağlıdır. Noktalar uzayda düzgün (uniform) dağılıyorsa iki yöntem de aynı çözümü verecektir. Noktalar örneğin iki boyutlu uzayda Gauss dağılımı gösteriyorsa L2 normu, hatta daha iyisi Mahalanobis uzaklığı gibi yaklaşımlar daha mantıklı olabilir. Çizilen çözümün yanlış olduğunu söylemek mümkün değildir. Mutlak değer yerine farkların karesi de toplanabilirdi.

Daha sonra başka bir öğrenci aynı konuyu bir örnekle sorar.

**Soru:** İki boyutta bir çiftin farkları 1 ve 3, diğer çiftin farkları 2 ve 2 olsun. Toplamlar eşittir (4). Ama uzaklığa baktığımızda biri $\sqrt{1^2 + 3^2}$, diğeri $\sqrt{2^2 + 2^2}$ olur ve ikincisi daha yakındır. Bu yöntemle ikisini eşit görmüyor muyuz?

**Cevap:** Hoca öğrencinin Öklid uzaklığından söz ettiğini belirtir ve iki nokta arasındaki mesafeyi tanımlamanın tek bir yolu olmadığını vurgular (ekrandan, 01:45:00). Derste kullanılan yöntem, iki nokta arasındaki yatay ve dikey mesafelerin toplamını bulur; buna **cityblock uzaklığı** denir. Öğrencinin söylediği, iki noktayı doğrudan birleştiren çizginin uzunluğudur; buna **Öklid uzaklığı** denir. Öğrenci "zaten mesafe orası değil mi?" diye sorunca hoca, belki şimdiye kadar yalnız böyle öğrenildiğini, ama ileride iki nokta arasındaki mesafeyi tanımlamanın birçok yolu olduğunun görüleceğini söyler. Öklid uzayında gösterilen mesafe elbette geçerlidir. Ama biri diğerinden daha doğru ya da yanlış değildir.

> **Ek bilgi (derste anlatılmadı):** İki nokta $x$ ve $y$ için L1 (cityblock, Manhattan) uzaklığı $\sum_k |x_k - y_k|$, L2 (Öklid) uzaklığı $\sqrt{\sum_k (x_k - y_k)^2}$'dir. Yalnız en yakın çifti bulmak için L2'de karekök alınmasına gerek yoktur; karekök artan bir fonksiyon olduğu için kareler toplamı aynı sıralamayı verir.

## 10. Çöpçatan sitesi problemi

### 10.1 Problem

Hoca bir önceki yapının bir uygulamasını gösterir: çöpçatan sitesi (ekrandan, 01:50:00). Siteye kadınlar ve erkekler girer ve site birbirine en uygun olanları önerir. Herkese aynı D soru sorulur ve cevaplar sayısaldır (örneğin 3, 5 gibi). Erkekler bütün sorulara, kadınlar da bütün sorulara cevap verir. Böylece iki matris oluşur:

- `E (M x D)`: M erkek, D soru.
- `K (N x D)`: N kadın, D soru.

Kadın ve erkek sayısı eşit değildir. Soru şudur: birbirine en uygun ikili hangisidir? E'nin `ind1`'inci satırı ile K'nın `ind2`'inci satırı birbirine en uygun olsun. Mükemmel uyum olması şart değildir; eldeki matrislere göre en uygun ikili aranır.

### 10.2 Önceki problemle ilişkisi

Hoca bu problemin bir önceki problemle ilişkisini sorar. Öğrenciler aynısı olduğunu söyler. Hoca bayağı benzediğini ama birebir aynı olmadığını belirtir. Önceki problemde aynı matrisin içindeki birbirine en yakın iki nokta aranıyordu; burada iki farklı matrisin arasındaki birbirine en yakın noktalar aranır.

Bu fark döngüleri değiştirir. Önceki problemde j, i + 1'den başlıyordu; çünkü aynı matrisin satırları kendi aralarında karşılaştırılıyordu. Burada E matrisinin her satırı K matrisinin her satırıyla karşılaştırılmalıdır: birinci satır K'nın bütün satırlarıyla, ikinci satır da bütün satırlarıyla, vb. Bu yüzden j de 1'den başlar.

### 10.3 Akış diyagramı

Akış diyagramı (ekrandan, 01:55:00):

```text
 / enuygun(E, M, K, N, D) \
 \ ind1, ind2             /
          |
min_dist = ∞
ind1 = 0, ind2 = 0
          |
i = 1..M:
    j = 1..N:
        dist = 0
        k = 1..D:
            dist = dist + |E[i, k] - K[j, k]|
        min_dist > dist ?
        T: min_dist = dist
           ind1 = i
           ind2 = j
          |
       return
```

Hoca dış döngünün erkekler üzerinden döndüğünü söyler (i = 1..M), iç döngü kadınlar üzerinden döner (j = 1..N). Her (i, j) çifti için `dist` sıfırlanır ve D soru üzerinden mutlak farklar toplanır. Sonra `min_dist > dist` sorusu sorulur; bu, önceki diyagramdaki `dist < min_dist` ile aynı şeydir.

### 10.4 Normalizasyon

Hoca burada soruların cevaplarının hep benzer sayısal değerler olduğunu varsaydıklarını belirtir. Gerçekte sorulardan biri yaş, biri aylık gelir olabilir. Yalnız bu iki soru olsun ve aynı yöntem uygulansın. Hoca öğrencilere yaş kısmına ne olacağını sorar; bir öğrenci "yok saymış gibi oluruz" der. Hoca onaylar: değişkenlerin aralıkları birbirinden çok farklıysa, aralığı büyük olan değişken her zaman diğerlerini baskılar ve değerlendirme neredeyse yalnız onun üzerinden yapılır. Bu yüzden değişkenleri normalize etmek gerekir. Hoca şimdilik bu ayrıntıya girmez.

## 11. void

Aradan sonra bir öğrencinin bu fonksiyonların kodda nasıl kullanılacağını sorduğu aktarılır. Hoca dersin uygulama kısmında asistanların bunu gösterdiğini ve dersin sayfasında birçok kod örneği bulunduğunu, kod bazında nasıl uygulandıklarının oradan görülebileceğini söyler. Ardından `void` kavramını açıklar (ekrandan, 02:10:00).

Örneğin `yazdir(A)` diye bir fonksiyon çağrılsın; A bir metin olsun ve fonksiyon onu ekrana yazdırsın. Bu çağrıda başta bir değişkene atama yoktur. Ekrandaki ilk yazımda `I = yazdir(A)` yazılıp `I =` kısmının üstü çizilir. Fonksiyonun ekrana bir şey yazdırması istenir, geriye bir şey dönmesi istenmez. Bu durumda akış diyagramında çıkış kısmına `void` yazılır: dönüş tipi yoktur.

Fonksiyona parametre de gönderilmeyebilir: yalnız `yazdir()`. Bu durumda giriş kısmı da `void` olur:

```text
yazdir(A)  ->   / yazdir(A)    \
                \ void         /

yazdir()   ->   / yazdir(void) \
                \ void         /
```

Bir şey döndürmeyen fonksiyon "tipsiz" olarak da ifade edilir; dönüş tipi yoktur.

## 12. Doktor, hasta ve teşhis problemleri

### 12.1 Veri yapısı

Son problem grubu fonksiyonların tekrar tekrar kullanılmasını gösterir (ekrandan, 02:10:00). Doktorlar, hastalar ve teşhisler vardır. Hastalıkların adları (metinleri) kodlarla eşleştirilmiştir ve kodlar 1'den 100'e kadardır.

- D adet doktor, H adet hasta.
- `T (D x H)`: teşhis matrisi. Çok zengin bir sistem varsayılır: her doktor her hastaya bir teşhis koyar.
- `G (H)`: doğru teşhis dizisi. Her şeyi bilen "süper bir doktor" doğru teşhisleri söyler.

T'nin i'inci satırı, i'inci doktorun 1'den H'ye kadar bütün hastalara koyduğu teşhisleri gösterir. j'inci sütunu ise j'inci hastaya konulmuş bütün teşhisleri gösterir. G bir matris değil, bir dizidir ve T ile uyumlu olarak birinci hastanın, ikinci hastanın, ..., H'inci hastanın doğru teşhislerini tutar.

Hoca öğrencilere böyle bir veriyle neler sorulabileceğini sorar. Öğrencilerden gelen ve hocanın eklediği fikirler:

- En iyi teşhisleri koyan doktoru, yani en başarılı doktoru bulmak.
- Hastanenin başarı oranını bulmak: her doktorun başarısını ayrı ayrı hesaplayıp oradan ilerlemek.
- Hastalar üzerinden ilerlemek: bir hastaya birçok doktor teşhis koyduğu için bunlardan birini kabul etmek gerekir. Yüzdesi en yüksek doktorun dediği alınabilir; ya da daha demokratik bir yol olarak çoğunluk oyu kullanılabilir. Hoca bunu daha önce seçim sistemlerinde görülen yönteme benzetir. Hasta için en çok söylenen hastalık o hastanın teşhisi kabul edilir ve doğru teşhisle karşılaştırılarak başarı oranı kabaca çıkarılabilir.
- Birbirine en çok benzeyen iki doktoru ya da iki hastayı bulmak.

### 12.2 En başarılı doktor

Hoca algoritmayı genel hatlarıyla yazar (ekrandan, 02:20:00):

```text
basarilar = kisisel_basari(T, D, H, G)      -> D uzunluklu bir dizi
[deg, sind] = minmax(basarilar, D, max)
```

`kisisel_basari` fonksiyonuna T matrisi, boyutları gösteren D ve H, bir de doğru teşhisleri tutan G gönderilir. Dönen `basarilar` dizisinin i'inci elemanı i'inci doktorun başarısıdır. Hoca bu fonksiyonu yazmaz, öğrencilere bırakır. Sonra daha önce yazılan `minmax` fonksiyonu kullanılır: `basarilar` dizisi, boyutu D ve en büyüğün istendiğini belirten değer gönderilir. Dönen `sind`, en başarılı ("mucize") doktorun indisidir. Burada `minmax` dizinin en büyüğünü bulmak için kullanılmıştır; ama bunun için önce `kisisel_basari` fonksiyonunu yazmak gerekir.

### 12.3 Birbirine en yakın iki doktor

Hoca bu problemin daha önce yazılan bir şeye benzeyip benzemediğini sorar. Bir öğrenci, çöpçatandan bir önceki probleme benzediğini söyler. Hoca onaylar: bu, K boyutlu uzaydaki noktaları karşılaştırmaya karşılık gelir. Burada noktalar doktorlar, boyutlar ise hastalar (teşhisler) olur. Yani T matrisinin birbirine en yakın satırları bulunacaktır:

```text
[ind1, ind2] = enyakinV2(T, D, H)
```

Ama bir fark vardır. Hastalıklar 1 ile 100 arasında kodlanmıştır. Örneğin bir hastalığa 99, başka birine 100, başka birine 1 kodu verilmiş olsun. Öklid ya da derste kullanılan Manhattan gibi bir uzaklık alınırsa, 99 kodlu teşhis ile 100 kodlu teşhis, 1 ile 99'a göre birbirine yakın teşhisler gibi görünür. Bu gerçekçi değildir, çünkü kodlar rastgele verilmiştir ve aralarında anlamsal bir ilişki yoktur.

Bu yüzden uzaklık hesabı değiştirilmelidir. Burada boyut hasta sayısıdır; döngü değişkenine küçük h denir ve h, 1'den H'ye kadar gider. Eskiden `dist = dist + |A[i, k] - A[j, k]|` yapılıyordu. Şimdi önemli olan iki teşhisin birbirine eşit olup olmadığıdır. Araya bir `if` konur:

```text
h = 1..H:
    T[i, h] != T[j, h] ise:
        dist = dist + 1
```

Yani i'inci doktorun h'inci hastaya koyduğu teşhis ile j'inci doktorun h'inci hastaya koyduğu teşhis farklıysa uzaklık 1 artar. Dıştaki iki döngü aynı kalır: i doktorlar üzerinde döner, j de i'nin bir fazlasından doktor sayısına kadar döner. Önceki `enyakin`'den farkı olduğu için hoca buna "versiyon 2" anlamında `enyakinV2` adını verir (ekrandan, 02:25:00).

<!-- BELİRSİZ: enyakinV2'nin değiştirilmiş uzaklık kısmının çizildiği an (02:21-02:23) kareler arasında kaldı; yukarıdaki yapı altyazıdan kuruldu. -->

**Soru:** Bütün doktorlar her teşhis için birbirinden farklı değerler vermişse, birbirine en yakın iki doktoru nasıl bulabiliriz? Örneğin beş doktor olsun, teşhis kodları 1 ile 10 arasında olsun; bir doktor her hasta için 1, bir diğeri 2, başka biri 6, başka biri 10 vermiş olsun. Bu durumda 1 ve 2 veren doktorlar en yakın olmalı, ama bu yöntemde herkesin uzaklığı aynı çıkar.

**Cevap:** Herkes birbirinden farklıysa, döngü sırasına bağlı olarak herhangi iki doktor `ind1` ve `ind2` olarak dönecektir. Burada hastalık kodlarının önemi vardır. 1 ve 2 kodlu hastalıkların birbirine 1 ile 99'a göre daha yakın olması ancak hastalıklar tek bir doğrusal boyutta anlamlı biçimde sıralanabilseydi geçerli olurdu. Genelde böyle bir şey olmaz ve hastalıkları böyle sıralamak kolay değildir. Bu yüzden "1 ile 2 arasındaki fark küçük, 1 ile 99 arasındaki fark büyük" demek manalı değildir. Yalnız teşhislerin farklı olup olmadığına odaklanmak gerekir.

### 12.4 Birbirine en benzeyen iki hasta

Sıradaki soru, doktorların koyduğu teşhislere göre birbirine en çok benzeyen iki hastayı bulmaktır (ekrandan, 02:30:00). `enyakinV2` birbirine en yakın iki **satırı** buluyordu; şimdi birbirine en yakın iki **sütun** gerekir. Hoca yeni bir fonksiyon yazmak istemediğini söyler ve şunu önerir:

```text
TT = transpose(T)
[ind3, ind4] = enyakinV2(TT, D, H)
```

Matrisin transpozu alınır. Böylece T'nin sütunları TT'nin satırları olur ve `enyakinV2` bu satırların en yakın ikisini bulur. `ind3` ve `ind4` birbirine en benzeyen iki hastadır.

Bir öğrenci boyutların yer değiştirmesi gerekip gerekmediğini sorar: `TT, D, H` yerine `TT, H, D` mi olmalı? Hoca kontrol eder: T matrisi D x H boyutundaydı. Transpozu alınınca H satır ve D sütun olur: `T (D, H)`, `TT (H, D)` (ekrandan, 02:35:00). `enyakinV2` önce satır sayısını, sonra sütun sayısını alır. Burada satır sayısı H'dir. Hoca öğrencinin haklı olduğunu söyler ve çağrıyı düzeltir:

```text
[ind3, ind4] = enyakinV2(TT, H, D)
```

### 12.5 En nadir teşhis

En nadir teşhisi bulmak, T matrisinde en az geçen hastalık kodunu bulmak demektir (ekrandan, 02:35:00). Hoca bunu klasik bir yolla çözer. Önce T matrisi bir diziye çevrilir:

```text
HD = diziyecevir(T, D, H)
```

T'nin birinci satırı dizinin başına, ikinci satırı arkasına, ..., son satırı en sona yerleştirilir. Sonra bu dizinin üzerinde bir frekans fonksiyonu çağrılır. Dizinin boyutu da gönderilmelidir:

```text
frekanslar = frekansbul(HD, D*H)     -> 100 boyutlu dizi
```

`frekanslar` dizisinin her gözünde, o koddaki hastalık teşhisinin kaç kez konduğu vardır: örneğin 1 numaralı hastalık 13 kez, 2 numaralı hastalık 7 kez konmuş, 3 numaralı hastalık hiç konmamış olabilir. En nadir teşhis için bu dizinin en küçüğü gerekir. Yine aynı `minmax` fonksiyonu çağrılır, bu kez minimum istenir:

```text
[deger, nadir_ind] = minmax(frekanslar, 100, min)
```

Frekanslar dizisinde en küçük değere sahip olan indisteki hastalık (`nadir_ind`) en nadir teşhistir.

> **Ek bilgi (derste anlatılmadı):** Hiç konmamış bir kod varsa frekansı 0 olur ve `minmax` o kodu döndürür. "Konmuş teşhisler içinde en nadir olanı" isteniyorsa, minimum aranırken frekansı 0 olan kodların atlanması gerekir.

### 12.6 Yanlış teşhis konan hastalar

Son soru: kimlere yanlış teşhis konmuştur (ekrandan, 02:40:00)? Hastaya konan teşhis "demokrasi" ile, yani bütün doktorların koyduğu teşhislerin çoğunluk oyuyla birleştirilmesiyle belirlenir. Sonuç bir KL dizisinde tutulur: `KL(i) = 1` ise i'inci hastaya yanlış teşhis konmuştur.

Bir öğrenci, bütün doktorların bir hastaya aynı teşhisi koymamasının zaten yanlış teşhis anlamına gelip gelmediğini sorar. Ardından başka bir öğrenci de doğru teşhisin çoğunluğa göre belirlendiğini düşündüğünü söyler.

**Soru:** Bir hastaya bütün doktorların aynı teşhisi koymaması, doğrudan yanlış teşhis konduğu anlamına gelmez mi? Doğru teşhisi zaten çoğunluğa göre belirlemiyor muyuz?

**Cevap:** Hayır. Hastaya **konan** teşhis, doktorların teşhislerinden çoğunluk oyuyla belirlenir. **Gerçek** teşhis ise ayrıdır: G dizisindedir ve her şeyi bilen, hastanede çalışmayan çok iyi bir doktorun ya da günün sonunda belli olan sonucun verdiği teşhis gibi düşünülür. Yanlış teşhis, çoğunluk kararının G'deki gerçek teşhisle aynı olmamasıdır.

Fonksiyon şöyledir (ekrandan, 02:45:00):

```text
 / yanlis_teshis(T, D, H, G) \
 \ KL                        /
          |
i = 1..H:   KL(i) = 0
          |
i = 1..H:
    j = 1..D:   Tesh[j] = T[i, j]
    frekanslar = frekansbul(Tesh, D)
    [deg, secim] = minmax(frekanslar, max)
    secim == G(i) ?
        F: KL(i) = 1
          |
       return
```

Başlangıçta bütün hastalar için `KL(i) = 0` yapılır. Sonra her hasta için D doktorun kararı alınır: j döngüsüyle hastaya konan bütün teşhisler (T'nin o hastaya ait sütunu) `Tesh` dizisine kopyalanır. Bu teşhisler içinden en çok konmuş olan seçilecektir; bunun için `frekansbul` çağrılır ve `Tesh` dizisi ile uzunluğu D gönderilir. Dönen `frekanslar` dizisinde yine 100 değer vardır: o hasta için her hastalıktan kaç teşhis konduğu. Bu dizinin en büyüğü `minmax` ile bulunur. Dönen `secim`, o hasta için çoğunluğun koyduğu hastalığın kodudur. Son olarak `secim == G(i)` sorusu sorulur. Doğruysa bir şey yapılmaz, yanlışsa `KL(i) = 1` yapılır. Döngüler bitince `return` ile dönülür.

> **Ders sonrası not:** Ekrandaki kutuda `Tesh[j] = T(i, j)` yazıyor (ekrandan, 02:45:00). T, D x H boyutlu (satırlar doktorlar, sütunlar hastalar) ve bu döngüde i hasta, j doktor indisi olduğu için doğrusu `Tesh[j] = T[j, i]`'dir; hoca anlatırken de "T matrisinin i'inci sütunu" der. Ayrıca `minmax(frekanslar, max)` çağrısında dizi boyutu (100) yazılmamıştır; tanımlanan `minmax` üç parametre aldığı için çağrı `minmax(frekanslar, 100, max)` olmalıdır.

### 12.7 Bu örneklerin amacı

Hoca bu örnekleri neden gösterdiğini açıklar. Bir yapı kurulmuş ve bu yapının içinde en yakını bulmak, frekans bulmak, minimum ve maksimum bulmak gibi fonksiyonlar defalarca kullanılmıştır. Fonksiyonların güzel özelliği "bir kez yaz, defalarca kullan" olarak ifade edilmişti. Bu fonksiyonlar bir kez yazılır ve farklı problem tiplerinin farklı çözümlerinde kolaylıkla uygulanır. Her problemde tekerleği yeniden icat etmeye gerek kalmaz.

> **Hocanın vurgusu:** Frekans bulma, minimum ve maksimum bulma ya da en yakını bulma gibi fonksiyonlar bir kez yazılır ve farklı problemlerde tekrar tekrar kullanılır. İşin özü budur.

### 12.8 C ile deneme

> **Ek bilgi (derste anlatılmadı):** Derste C kodu yazılmadı; yalnız akış diyagramları çizildi. Aşağıdaki program, `minmax`, tek boyutlu `enyakin` ve K boyutlu `enyakin` diyagramlarının C'ye çevrilmiş hâlidir. Ajan tarafından `gcc -Wall` ile uyarısız derlendi ve ekrandaki girdilerle çalıştırıldı. C dizileri 0'dan başladığı için çıktıda indislere 1 eklenmiştir. C bir fonksiyondan tek değer döndürdüğü için ikinci çıkış (indis) işaretçi parametreyle verilir.

```c
#include <stdio.h>
#include <stdlib.h>

/* bk = 1: en buyuk, bk = 0: en kucuk; *ind 0 tabanli indis */
int minmax(int D[], int N, int bk, int *ind) {
    int i, d = D[0];
    *ind = 0;
    for (i = 1; i < N; i++) {
        if ((bk == 1 && d < D[i]) || (bk == 0 && d > D[i])) {
            d = D[i];
            *ind = i;
        }
    }
    return d;
}

/* tek boyutlu noktalar: birbirine en yakin iki noktanin indisleri */
void enyakin(int A[], int N, int *ind1, int *ind2) {
    int i, j, fark, min_dist = 1000000;
    *ind1 = 0; *ind2 = 0;
    for (i = 0; i < N - 1; i++)
        for (j = i + 1; j < N; j++) {
            fark = abs(A[i] - A[j]);
            if (fark < min_dist) {
                min_dist = fark; *ind1 = i; *ind2 = j;
            }
        }
}

/* K boyutlu noktalar (N x K matris), L1 uzakligi */
#define KMAX 10
void enyakin_k(int A[][KMAX], int N, int K, int *ind1, int *ind2) {
    int i, j, k, dist, min_dist = 1000000;
    *ind1 = 0; *ind2 = 0;
    for (i = 0; i < N - 1; i++)
        for (j = i + 1; j < N; j++) {
            dist = 0;
            for (k = 0; k < K; k++)
                dist = dist + abs(A[i][k] - A[j][k]);
            if (dist < min_dist) {
                min_dist = dist; *ind1 = i; *ind2 = j;
            }
        }
}

int main(void) {
    int A[] = {7, 9, 6, 3, 12, 15};
    int P[4][KMAX] = {{4, 2}, {1, 0}, {3, 1}, {4, 4}};
    int i1, i2, ind, d;
    d = minmax(A, 6, 1, &ind);
    printf("max: %d (indis %d)\n", d, ind + 1);
    d = minmax(A, 6, 0, &ind);
    printf("min: %d (indis %d)\n", d, ind + 1);
    enyakin(A, 6, &i1, &i2);
    printf("enyakin: %d ve %d\n", i1 + 1, i2 + 1);
    enyakin_k(P, 4, 2, &i1, &i2);
    printf("enyakin_k: %d ve %d\n", i1 + 1, i2 + 1);
    return 0;
}
```

Çıktı:

```text
max: 15 (indis 6)
min: 3 (indis 4)
enyakin: 1 ve 3
enyakin_k: 1 ve 3
```

## Örnek Sorular

### Soru 1: Tek boyutta birbirine en yakın iki nokta

(ekrandan, 01:20:00) N elemanlı A dizisinde birbirine en yakın iki elemanın indislerini `[ind1, ind2] = enyakin(A, N)` biçiminde döndüren fonksiyonun akış diyagramını çizin. Örnek: A = 7, 9, 6, 3, 12, 15 için ne döner?

> **Çözüm (derste verildi, 01:25:00):** `min_dist = ∞`, `ind1 = ind2 = 0`; `i = 1..N-1`, `j = i+1..N`; `|A[i] - A[j]| < min_dist` ise `min_dist = |A[i] - A[j]|`, `ind1 = i`, `ind2 = j`; sonda `return`. Örnekte en küçük fark $|7 - 6| = 1$'dir, fonksiyon 1 ve 3 döndürür (C ile denetlendi).

### Soru 2: K boyutlu uzayda birbirine en yakın iki nokta

(derste sözlü, 01:26:51) Noktalar K boyutlu olsun; A, N x K boyutlu bir matris (N nokta sayısı, K boyut sayısı). Birbirine en yakın iki noktanın indislerini bulan fonksiyonu çizin.

> **Çözüm (derste verildi, ekrandan 01:35:00):** Soru 1'deki çift döngü korunur. Her (i, j) çifti için `dist = 0` yapılır ve `k = 1..K` için `dist = dist + |A[i, k] - A[j, k]|` biriktirilir. `dist < min_dist` ise `min_dist`, `ind1`, `ind2` güncellenir. Ekrandaki 2 boyutlu örnekte (4, 2), (1, 0), (3, 1), (4, 4) noktaları için 1 ve 3 döner.

### Soru 3: Matris için minmax'ın döndürdüğü indis

(derste sözlü, 01:11:08) Matris sürümü `minmax(matris, M, N, bk)`, en sonda `minmax(K, M, bk)` çağrısının döndürdüğü indisi döndürür. Bu indis neyi gösterir? En küçük eleman 4'üncü satırın 3'üncü elemanıysa ne döner?

> **Çözüm (derste verildi):** Son çağrı satır en büyüklerini (ya da en küçüklerini) tutan K dizisi üzerinde yapıldığı için indis yalnız satırı gösterir: 4 döner. Elemanın satırdaki yerini (3) bulmak için ek iş gerekir.

### Soru 4: Çöpçatan sitesi

(ekrandan, 01:50:00) Erkekler matrisi `E (M x D)` ve kadınlar matrisi `K (N x D)` veriliyor; D sorunun sayısal cevapları tutuluyor. Birbirine en uygun erkek-kadın ikilisini `[ind1, ind2] = enuygun(E, M, K, N, D)` ile bulun.

> **Çözüm (derste verildi, ekrandan 01:55:00):** `min_dist = ∞`, `ind1 = ind2 = 0`; `i = 1..M`, `j = 1..N` (iki farklı matris olduğu için j 1'den başlar); `dist = 0`, `k = 1..D` için `dist = dist + |E[i, k] - K[j, k]|`; `min_dist > dist` ise `min_dist = dist`, `ind1 = i`, `ind2 = j`; sonda `return`.

### Soru 5: Teşhis verisiyle neler sorulabilir?

(derste sözlü, 02:10:47) D doktor, H hasta, `T (D x H)` teşhis matrisi ve `G (H)` doğru teşhis dizisi verildiğinde bu veriyle hangi sorular sorulabilir?

> **Çözüm (derste verildi):** En başarılı doktor; hastanenin başarı oranı (doktor başarılarından ya da hastalar için çoğunluk kararından); birbirine en çok benzeyen iki doktor ve iki hasta. Derste ayrıca en nadir teşhis ve yanlış teşhis konan hastalar çözüldü (Bölüm 12).

### Soru 6: kisisel_basari fonksiyonu

(ekrandan, 02:20:00) `basarilar = kisisel_basari(T, D, H, G)` fonksiyonu D uzunluklu bir dizi döndürür; i'inci eleman i'inci doktorun başarısıdır. Hoca bu fonksiyonu öğrencilere bıraktı.

> **Çözüm (derste verilmedi):** Her doktor i (1..D) için `dogru = 0` yapılır; her hasta j (1..H) için `T[i, j] == G[j]` ise `dogru = dogru + 1`. Döngü sonunda `basarilar[i] = dogru / H` (doğru teşhis oranı) atanır ve en sonda `return` yapılır. En başarılı doktor sonra `[deg, sind] = minmax(basarilar, D, max)` ile bulunur.

### Soru 7: Birbirine en yakın iki doktor ve iki hasta

(ekrandan, 02:25:00 ve 02:30:00) T matrisinde birbirine en yakın iki doktoru ve birbirine en benzeyen iki hastayı mevcut fonksiyonlarla bulun. Hastalık kodları anlamsal bir sıra taşımaz.

> **Çözüm (derste verildi):** Doktorlar için `[ind1, ind2] = enyakinV2(T, D, H)`; uzaklıkta mutlak fark yerine `T[i, h] != T[j, h]` ise `dist = dist + 1` kullanılır. Hastalar için `TT = transpose(T)` ve `[ind3, ind4] = enyakinV2(TT, H, D)`; TT'nin satır sayısı H olduğu için boyutlar H, D sırasıyla verilir (ekrandan, 02:35:00).

### Soru 8: En nadir teşhis ve yanlış teşhis

(ekrandan, 02:35:00 ve 02:40:00) T matrisinde en az geçen hastalık kodunu ve çoğunluk kararına göre yanlış teşhis konan hastaları bulun.

> **Çözüm (derste verildi):** En nadir teşhis: `HD = diziyecevir(T, D, H)`, `frekanslar = frekansbul(HD, D*H)`, `[deger, nadir_ind] = minmax(frekanslar, 100, min)`. Yanlış teşhis: her hasta i için o hastaya konan D teşhis bir diziye alınır, `frekansbul` ile frekanslar, `minmax(..., max)` ile çoğunluk kararı `secim` bulunur; `secim != G(i)` ise `KL(i) = 1` (ekrandan, 02:45:00).

## Dersin Toparlaması

Bu derste fonksiyon kavramı tanımından uygulamasına kadar ele alındı. Fonksiyon, isimlendirilmiş ve parametre alabilen bir algoritmadır. Yeniden kullanım, ekip çalışması, kolay düzeltme ve kolay güncelleme sağlar. Buna karşılık her çağrıda yığına yazma ve yığından okuma maliyeti olduğu için programı biraz yavaşlatır. Akış diyagramında fonksiyon, üstte ad ve giriş parametreleri, altta çıkış parametreleri bulunan iki katlı bir şekille başlar ve `return` ile biter. Fonksiyonlar parametrik yazılarak sayıları azaltılır (`minmax`'taki `bk`). Aynı ad farklı tipte parametrelerle yeniden kullanılabilir; buna fonksiyon aşırı yükleme denir (dizi ve matris için `minmax`).

İkinci yarıda birbirine en yakın iki nokta problemi tek boyuttan K boyuta genelleştirildi ve iki farklı kümeyi karşılaştıran çöpçatan problemine uyarlandı. L1 ve L2 uzaklıkları arasındaki farkın veri dağılımına bağlı olduğu tartışıldı. Son olarak doktor-hasta-teşhis verisi üzerinde en başarılı doktor, en benzer doktorlar ve hastalar, en nadir teşhis ve yanlış teşhis soruları; `minmax`, `enyakin`, `frekansbul` ve transpoz gibi fonksiyonlar tekrar tekrar kullanılarak çözüldü. Bu, "bir kez yaz, defalarca kullan" ilkesinin somut bir gösterimidir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
