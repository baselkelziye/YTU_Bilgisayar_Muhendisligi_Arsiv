# Ders 4 Genişletilmiş Notu: Algoritma Tasarımı Alıştırmaları: Eratosthenes Kalburu, Tam Sayı Karekökü ve Sıralı Dizilerin Kesişimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı
- 2. Eratosthenes Kalburu'nun Kodlanması
- 3. Tam Sayının Karekökünü Alta Yuvarlamak
- 4. Sıralı İki Dizinin Kesişim Kümesi
- 5. Düşünme Problemleri
- 6. Örnek Sorular

## 1. Dersin Amacı

Bu kayıt haftanın kısa uygulama saatidir. Hoca bu saatte basitten zora doğru giden, biraz düşünmeyi gerektiren algoritmik çözüm alıştırmaları yapacaklarını söyledi. Amaç öğrencilerin "elinin alışması", algoritma tasarlama ve örnek çözme konusunda kendi kendilerine de çalışabilmeleridir. Dersin sonunda üzerinde düşünülmek üzere iki problem de verildi.

## 2. Eratosthenes Kalburu'nun Kodlanması

### 2.1 Hatırlatma

Teorik derste belli bir sayıya kadar olan asal sayıları bulmak için etkin bir yöntem anlatılmıştı. Hoca bu yöntemi kendilerinin değil, Eratosthenes'in önerdiğini, kendilerinin yalnız algoritmik tasarımını, yani akış diyagramını yaptıklarını hatırlattı. Slaytta yan yana iki akış diyagramı gösterilmişti; bu derste ikinci akış kodlandı.

### 2.2 Kodun yapısı

Hocanın kodu ekrana paylaştığı anın karesi yoktur; kodun yapısı anlatımdan şöyle kurulur:

- Standart kütüphane tanımları yapılır. Basitlik için iki sabit tanımlanır: $n$ (önce 100) ve ekrana çizim için bir adım (step) sayısı (önce 1).
- ANSI C standardı gereği değişkenler blok başında tanımlanır.
- İlklendirme: Yalnız 1 ve 0'lardan oluşan bir "asal mı" dizisi tutulur. 2'den $n$'e kadar bütün gözler 1 yapılır, yani başlangıçta hepsi asal kabul edilir.
- Eleme: 2'den $n$'e kadar gezilir. Göz hâlâ 1 ise (daha önce sıfırlanmamışsa, yani hiçbir sayının katı değilse) o sayının katları taranır: $i \cdot j < n$ olduğu sürece $j$ birer artırılır ve $i \cdot j$ gözü 0 yapılır.
- Sonuç: Döngü bitince elimizde 0 ve 1'lerden oluşan bir dizi kalır. 1 olan gözler asal sayılardır; 0 olan gözler asal çarpanları olan sayılardır.

<!-- BELİRSİZ: Kalbur kodunun kendisi karelerde görünmüyor; yalnız çıktısı görünüyor. Kod satırları nota alınamadı. -->

Örneğin $i = 2$ iken $2 \cdot 2, 2 \cdot 3, 2 \cdot 4, \ldots$ yani 4, 6, 8, 10, 12, ... silinir; 2'nin kendisi silinmez. $i = 3$ iken 6 zaten silinmiş olsa da kodda ayrıca bir kontrol yoktur, 6 yeniden 0 yapılır; ardından 9 silinir ve böyle devam eder. $i = 4$ ve $i = 6$ gibi daha önce sıfırlanmış sayılar için katlar taranmaz.

### 2.3 Asal sayıları çizgiyle göstermek

Asal sayıları yazdırmak için "göz 1 ise yazdır, değilse bir şey yapma" demek yeter. Hoca buna küçük bir ekleme yaptı: her asal sayının yanına çizgilerden oluşan bir şerit yazdırdı. Amaç $n$'e kadar asal sayıların nasıl arttığını izlemekti. Sayı büyüdüğünde (1000, 10 000) şeritler çok uzamasın diye adım sabiti kullanıldı: adım 10 ise her 10 birim tek bir çizgiyle gösterilir.

$n = 100$ ve adım 1 için çıktıda 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 sayıları alt alta, yanlarında giderek uzayan çizgilerle yazdırıldı; program yaklaşık 0,15 saniyede bitti (ekrandan, 00:10:00).

Sonra denemeler yapıldı:

| $n$ | Adım | Hocanın okuduğu süre | Not |
|---|---|---|---|
| 100 | 1 | 0,14 s | Çıktı rahat okunuyor |
| 1000 | 1 | — | Çizgiler ekrana sığmadı |
| 1000 | 10 | 0,51 s | Okunabilir çıktı |
| 10 000 | 100 | 3,7 s | En büyük asal 9973 |

Hoca $n$ 10 kat artınca sürenin de arttığını, bu tür denemelerle (1000, 10 000, 100 000) çalışma süresinin $n$'e göre nasıl değiştiğinin incelenebileceğini söyledi. Karmaşıklık konusuna bir sonraki hafta başlanacağını belirtti.

> **Ek bilgi (derste anlatılmadı):** Bu sürelerin büyük kısmı büyük olasılıkla kalburun kendisinden değil, ekrana çok sayıda çizgi yazdırmaktan gelir. Kalburun kendi zaman karmaşıklığı $O(n \log \log n)$ olarak bilinir; süre ölçerken yazdırma kısmını ayırmak daha doğru bir karşılaştırma verir.

### 2.4 Bir öğrencinin fark ettiği hata

**Soru:** Buradaki çizgiler neyi temsil ediyor? **Cevap:** O sayıya kadar kaç tane asal sayı olduğunu.

Öğrenci, adım 1 ile çalıştırıldığında 5'in yanında 5 çizgi olduğunu, oysa 5'e kadar 5 asal sayı olmadığını söyledi. Hoca kodu yeniden çalıştırdı ve hatayı kabul etti: çizgiler, o ana kadarki asal sayı sayısı kadar değil, asal sayının kendi değeri kadar çizdiriliyordu. Doğrusu için asal sayıları sayan ayrı bir sayaç gerekir. Hoca bu düzeltmeyi öğrencilere bıraktı. Ekrandaki çıktıda da 2'nin yanında 2, 7'nin yanında 7 çizgi vardır (ekrandan, 00:10:00).

> **Ders sonrası not:** Hoca 10 000'lik çıktıya bakarak asal sayı sayısında "artan ya da azalan bir ivme olmadan doğrusal bir artış" olduğunu söyledi. Çizgiler asal sayının değeri kadar çizildiği için çıktı doğal olarak doğrusal görünüyordu. Asal sayıların sayısı ise büyük olasılıkla doğrusaldan biraz yavaş artar: python ile sayıldığında 100'e kadar 25, 1000'e kadar 168, 10 000'e kadar 1229 asal sayı vardır ve 10 000'den küçük en büyük asal 9973'tür.

> **Ek bilgi (derste anlatılmadı):** $n$'e kadar olan asal sayıların sayısı $\pi(n)$ ile gösterilir. Asal Sayı Teoremi'ne göre $\pi(n) \approx n / \ln n$'dir; yani asallar giderek seyrekleşir.

## 3. Tam Sayının Karekökünü Alta Yuvarlamak

### 3.1 Problem

Hoca beyaz tahtaya $\lfloor \sqrt{N} \rfloor$ yazdı ve ne anlama geldiğini sordu (ekrandan, 00:20:00). Bir öğrenci doğru cevabı verdi: karekökü alta yuvarlamak. Yani verilen bir $N$ tam sayısının karekökü yine tam sayı olarak, alta yuvarlanmış hâliyle bulunacak. Kısıtlar:

- `sqrt` çağırıp sonucu tam sayıya çevirmek ya da `floor` kullanmak yasaktır; hazır fonksiyon yoktur, algoritma bizim tarafımızdan yazılacaktır.
- $N$ pozitif (en az 0) bir tam sayıdır; sanal sayılar düşünülmez.

### 3.2 Çözümün adım adım iyileşmesi

Akış diyagramı "Başla" ve "$N$'i oku" adımlarıyla başladı. Sonra öğrencilerden fikir istendi.

- **Birinci öneri (dizi ile):** $N$'e kadar sayıların karelerini al, bir dizide tut; $N$'i geçtiği yerde dur, en yakın olan karekökün yuvarlanmış hâlidir. Hoca bunun çok verimli olmadığını ama bir başlangıç (baseline) olarak kabul edilebileceğini söyledi.
- **İkinci öneri (iki değişkenle):** Dizi tutmaya gerek yok, çünkü bütün değerler değil tek bir değer soruluyor. Şimdiki ve bir önceki değeri tutmak yeter; kare $N$'den büyük çıktığı anda önceki değer cevaptır. Hoca bunu çok güzel bir yaklaşım olarak değerlendirdi. Sohbetten gelen bir öneri de benzerdi: bir `while` içinde `if` ile "$i^2 > N$ ise cevap budur, değilse $i$'yi artır".
- **Hocanın iyileştirmesi (tek değişkenle):** İki değer tutmaya da gerek yoktur, çünkü önceki değer her zaman $i - 1$'dir. $i$, $N$ sıfır olabileceği için 0'dan başlatılır.

Sohbette bir öğrenci "binary search" (ikili arama) önerisini de yazdı; bu öneri derste ayrıca tartışılmadı.

### 3.3 Uç nokta: `<` mü, `<=` mü?

Döngü $i \cdot i < N$ olduğu sürece mi, yoksa $i \cdot i \le N$ olduğu sürece mi dönmeli? Hoca $N = 9$ örneğini verdi: bu durumda $i = 3$ değerinin de gezilmesi gerekir, yani eşitlik koşulda bulunmalıdır. Eşitlik konmazsa döngü sonrasında ayrıca kontrol yapmak gerekir; koşul `<=` olarak tasarlanırsa döngü sonundaki $i - 1$ her zaman doğru cevaptır.

> **Hocanın vurgusu:** Uç nokta problemlerine dikkat edin. Küçük mü, küçük eşit mi kullanılacağını mutlaka analiz ederek incelemeli ve akışınızı buna göre tasarlamalısınız.

### 3.4 Akış diyagramı

Tahtadaki son akış şöyledir (ekrandan, 00:25:00):

```text
BAŞLA
  |
N'i oku
  |
i <- 0
  |
+--> [ i*i <= N ? ] --evet--> i <- i + 1 --+
|          |                               |
+----------|-------------------------------+
           | hayır
           v
       i <- i - 1
           |
       i'yi yaz
           |
         DUR
```

Hoca bu akışta hiç `if` bulunmadığını vurguladı: tek bir koşul kontrolü, tek döngü, tek atama ve sonda tek bir çıkarma.

### 3.5 Adım adım örnekler

$N = 10$ (tahtadaki izleme, ekrandan, 00:25:00):

| $i$ | $i \cdot i$ | $i \cdot i \le 10$ ? | İşlem |
|---|---|---|---|
| 0 | 0 | evet | $i \leftarrow 1$ |
| 1 | 1 | evet | $i \leftarrow 2$ |
| 2 | 4 | evet | $i \leftarrow 3$ |
| 3 | 9 | evet | $i \leftarrow 4$ |
| 4 | 16 | hayır | döngüden çık |

Döngüden çıkınca $i = 4$'tür. Alta yuvarlamak istediğimiz için $i \leftarrow i - 1 = 3$ yapılır ve 3 yazdırılır. Gerçekten $\sqrt{10} \approx 3{,}16$'dır ve alta yuvarlanmış hâli 3'tür.

$N = 16$ (sözlü anlatım): $i = 4$ iken $4 \cdot 4 = 16 \le 16$ olduğu için döngüye bir kez daha girilir ve $i = 5$ olur. $5 \cdot 5 = 25 > 16$ olduğundan çıkılır; $5 - 1 = 4$ yazdırılır.

**Soru:** Koşulu basit tutup döngü sonunda tek çıkarma yapmak her zaman mümkün mü? **Cevap:** Her zaman değil. `while` koşulları genellikle bu kadar basit olmaz; çoğu zaman iki şart birlikte değerlendirilir. İki şart varsa döngüden hangisi yüzünden çıkıldığını anlamak için döngüden sonra bir kontrol daha yapmak gerekir.

### 3.6 Yer ile işlem arasındaki denge

Bu döngü her karşılaştırmada $i \cdot i$ çarpımını yeniden hesaplar: her adımda bir çarpma ve bir karşılaştırma vardır. Kare ayrı bir değişkende (örneğin `i2`) tutulursa çarpma kaydırılabilir, ama bu kez fazladan bir değişken gerekir. Bu bir ödünleşimdir (trade-off): "bir tam sayı daha tutmak önemli değil" de denebilir, "yer kaplamak istemiyorum, işlemi zaten var olan indis değişkeni üzerinde yaparım" da.

**Soru:** Bu, verimi düşürür mü? **Cevap:** Özellikle C'de bunun tek ve kesin bir cevabı yoktur. Sonuç ortama, derleyiciye, hatta derleyicinin optimizasyon parametrelerine göre değişir. Derleyiciler varsayılan ayarlarda genellikle optimizasyon yapar ve anlayabildikleri, çevirebildikleri durumlarda düzgün yazılmamış bazı yerleri düzeltebilir. Cevap "duruma göre evet, duruma göre hayır"dır.

### 3.7 Kod

Akış diyagramının kodu iki satırdır (ekrandan, 00:30:00):

```c
#include <stdio.h>

#define N 10

int main(void){
    int i=0;

    while (i*i<=N) i++;

    printf("%d\n",--i);

    return 0;
}
```

$N$ burada sabit olarak tanımlanmıştır; `scanf` ile de okunabilir, amaç algoritmanın doğrudan anlaşılmasıdır. Döngüden sonraki $i \leftarrow i - 1$ adımı `printf` içindeki `--i` ile yapılır; işlem yine yapılır ama ayrı bir satır yer almaz. Hoca kodu $N = 16$ ile çalıştırdı ve ekranda 4 sonucunu gördü.

Kod `gcc -Wall` ile derlendi ve çalıştırıldı (ajan testi): $N$ = 0, 1, 9, 10, 15, 16, 17, 99, 100 için sırasıyla 0, 1, 3, 3, 3, 4, 4, 9, 10 sonucunu verdi.

> **Hocanın vurgusu:** Problemi çözerken önce temel, basit bir çözümden yola çıkın. Sonra "bunu nasıl iyileştirebilirim, nasıl daha az yer kaplar, bu `if`'ten kurtulabilir miyim, bu karşılaştırmayı atabilir miyim, bu döngüyü azaltabilir miyim, hepsine bakmam gerekiyor mu" diye düşüne düşüne çözümünüzü iyileştirin.

## 4. Sıralı İki Dizinin Kesişim Kümesi

### 4.1 Problem

Ekrana iki dizi yazıldı (ekrandan, 00:35:00):

- $a = [2, 5, 5, 5]$
- $b = [2, 2, 3, 5, 5, 7]$
- Ön koşul: diziler sıralı (küçükten büyüğe).

İstenen, bu iki dizinin kesişim kümesidir. Kümede tekrar eden eleman olmaz. Bu yüzden `intrsct = [2, 5, 5]` yanlıştır (kırmızıyla çarpı işaretli), `intrsct = [2, 5]` doğrudur (yeşille). Sonucu üçüncü bir dizide tutmaya gerek yoktur; bulunan her elemanı ekrana yazdırmak yeter, yani ekrana 2 ve 5 yazmalı, 2, 5, 5 yazmamalıdır.

### 4.2 Öneriler ve yaklaşım biçimi

Bir öğrenci, küçük dizinin boyutu kadar dönen bir `for`, içinde de büyük diziyi tarayan bir `while` önerdi; kesişim en fazla küçük dizinin boyutu kadar eleman içerebilir. Hoca, bu öğrencinin çözümü kafasında kurup doğrudan kod yapısını anlattığını belirtti.

> **Hocanın vurgusu:** Algoritmayı tasarlarken "önce bir `for` koyarım, içine bir `while` yazarım" diye yola çıkmayın. "Şu diziyi şöyle gezerim, birinci dizinin şu gözünden başlayıp ikincide şöyle bir tarama düşünüyorum, şu sırayla şunlara bakmak gerekir" diye bir çözüm yaklaşımı anlatırsanız algoritmanızı daha doğru kurmuş olursunuz.

İkinci öğrenci şunu önerdi: ikinci diziyi baştan sona gezmek yerine, birinci diziden alınan elemandan küçük elemanlar olduğu sürece ikinci dizide ilerlenir; küçük eleman kalmayınca kalınan elemana bakılır, eşitse yazdırılır. Sonra birinci dizinin bir sonraki elemanı için aynı şey yapılır. Hoca, buradaki anahtar noktanın dizilerin sıralı olması olduğunu vurguladı: diziler sıralı olduğu için sürekli başa dönüp elemanlara tekrar tekrar bakmaya gerek yoktur.

Sohbetten gelen bir öneri de "birinci dizide farklı bir eleman görene kadar indisi artırmak" idi. Hoca tekrarların hangi dizide olacağının bilinemeyeceğini (örneğin diziler yer değiştirmiş olabilir) hatırlattı.

### 4.3 İki indisle gezinti

Her dizide hangi gözde kalındığını gösteren bir sayaç (indis) gerekir. Tahtadaki izleme şöyledir (ekrandan, 00:40:00):

1. İki dizide de ilk elemandan başlanır: $a$'da 2, $b$'de 2. Biri diğerinden küçük değildir, demek ki eşittir.
2. Eşitlik bulunduğunda eleman (örneğin ikinci dizideki) ekrana yazdırılır: **2**. Bir öğrencinin hatırlattığı gibi eşitlikte iki dizinin de indisi artırılır. Tekrar olabileceği için eşitlik sürdüğü sürece indis ilerletilir; $b$'deki ikinci 2 de atlanır.
3. $a$'da 5, $b$'de 3 ya da 2 kalmıştır; eşitlik yoktur. Dizi sıralı olduğu için küçük olanın, yani $b$'nin indisi artırılır. 5 ile 3 karşılaştırılır, yine $b$ ilerler.
4. 5 = 5 eşitliği bulunur ve **5** yazdırılır. Tekrar olup olmadığını görmek için indis ilerletilmeye devam edilir; $a$'daki 5'ler de, $b$'deki 5'ler de atlanır.
5. $a$ dizisi bitmiştir. Artık kesişim noktası olamayacağı için $b$'nin geri kalanına (7) bakmaya gerek yoktur; döngü bitirilir.

> **Hocanın vurgusu:** Dikkat edilmesi gereken yerler indis artırımları, uç noktalar ve tekrar sayılarıdır.

### 4.4 Derste gösterilen kod

Hoca bazı kontrolleri bilerek eksik bıraktığı kısa bir kod gösterdi. Anlatıma göre kodun mantığı şöyledir:

- İki dizinin de içinde kalındığı sürece döngü sürer; hangi dizinin daha kısa olduğu bilinmediği için ikisinin de sınırı kontrol edilir. Bir dizinin sonuna gelinince geri kalana bakmaya gerek yoktur.
- Birinci dizinin elemanı ikinciden küçükse birincinin indisi artırılır.
- Değilse ve ikinci dizinin elemanı birinciden küçükse ikincinin indisi artırılır.
- İki indis de ilerlemediyse eşitlik vardır; eleman yazdırılır ve eşitlik bozulana kadar indis ilerletilir.

<!-- BELİRSİZ: Kesişim kodunun satırları ve hocanın sohbete yazdığı kod parçası karelerde görünmüyor; kod nota alınamadı. Altyazıda "B[j] yerine B[j++] yazdırılması" ve "12. satırdaki while" geçiyor. -->

Örnek dizilerle program 2 ve 5 yazdırarak yaklaşık 0,03 saniyede doğru sonlandı. Hoca birinci dizideki 2'leri artırarak ($[2, 2, 2, 5, 5, 5]$ gibi) ve sona iki eleman ekleyerek kodu bozmaya çalıştı ama kod yine çalıştı. Tekrar sayısı tek olduğunda kodun bozulması gerektiğini düşündüğünü, denemelerinde hep çift sayıda tekrar kullandığını söyledi; tek sayılı denemede de çalışınca kodu bozan bir örnek bulmayı öğrencilere bıraktı.

**Soru:** Neden `B[j]` değil de `B[j++]` yazdırılıyor? **Cevap:** Tekrarlar yüzünden; indis yazdırılırken de ilerletilir.

**Soru:** Eşitlik dizinin sonuna kadar sürerse, eşitlik döngüsündeki indis artırımı dizinin dışındaki bir elemanla karşılaştırma yapar mı? **Cevap:** Evet, bütün elemanlar aynı olursa dizi dışına taşma (array index out of bounds) durumu olabilir. Hoca bütün elemanları 2 yaparak denedi; program dönüş değeri 0 ile, hata vermeden bitti.

> **Ek bilgi (derste anlatılmadı):** C'de dizi sınırının dışını okumak tanımsız davranıştır (undefined behavior); program her zaman çökmez, bu yüzden "çalıştı" görünmesi kodun doğru olduğunu göstermez. Eşitlik döngüsünün koşuluna dizi sınırını da eklemek (önce `i < m`, sonra `a[i] == v`) bu riski ortadan kaldırır.

Hoca bu kısmı bilerek açık bıraktığını, öğrencilerin kodu değiştirerek ya da "bu kod şu örnekte çalışmaz" diye göstererek el alıştırması yapmalarını istediğini söyledi. Bunu yaptıkça algoritmanın uç noktaları ve algoritma tasarımının temel ilkeleri daha iyi oturur.

Aşağıdaki kod derste yazılmadı; anlatılan yaklaşıma göre ajan tarafından yazıldı, `gcc -Wall` ile derlendi ve test edildi. Eşitlik döngülerinde dizi sınırı da kontrol edilir:

```c
#include <stdio.h>

void kesisim(const int a[], int m, const int b[], int n) {
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) i++;
        else if (b[j] < a[i]) j++;
        else {
            int v = a[i];
            printf("%d ", v);
            while (i < m && a[i] == v) i++;
            while (j < n && b[j] == v) j++;
        }
    }
    printf("\n");
}

int main(void) {
    int a[] = {2, 5, 5, 5};
    int b[] = {2, 2, 3, 5, 5, 7};
    int c[] = {2, 2, 2};
    int d[] = {2, 2};
    kesisim(a, 4, b, 6);
    kesisim(c, 3, d, 2);
    return 0;
}
```

Çıktı: ilk çağrıda `2 5`, bütün elemanları 2 olan ikinci çağrıda `2`.

## 5. Düşünme Problemleri

Hoca dersin sonunda iki problem verdi. Bunların gönüllü çalışma olduğunu, ödev olmadığını belirtti; akış diyagramlarının oluşturulmasını istedi.

### 5.1 Tekrar etmeyen sayıların sayısı

Kitaptan bir problemdir. 1 ile 1000 arasında rastgele $n$ sayı üretilir (ya da sayı sayısı 1000 gibi sabit alınabilir). Bu sayılar içinde yalnız bir kez geçen, hiç tekrar etmeyen kaç sayı olduğu sayılacaktır. Tekrar eden bir sayının hiçbir kopyası sayılmaz: ikinci 200 görüldüğünde birinci 200 de sayılmaz.

Hoca ekrana iki örnek yazdı (ekrandan, 00:55:00):

- $N = 6$, $A = \{200, 999, 200, 45, 58, 689\}$, cevap: 4. 200 tekrar ettiği için atılır; 999, 45, 58, 689 sayılır.
- $N = 4$, $A = \{15, 56, 78, 999\}$, cevap: 4. Hepsi tekildir.

Düşünülecek sorular: Daha önce görülen değerleri işaretlemek için ekstra bir dizi gerekir mi? Dizi tutmadan yapılırsa kaç döngü ve kaç kontrol gerekir? Ekstra bir dizi kullanılırsa döngüler nasıl azalır, daha az karmaşık bir kod nasıl yazılır?

**Soru:** Dizi sıralanırsa ekstra dizi tutmaktan kurtulunur mu? **Cevap:** Doğru, ama problemin diziyi sıralamadan çözülmesi isteniyor. Sayılar 1 ile 1000 arasında sürekli değer üreten bir makineden akıyor gibi düşünülmeli; belli bir süre sonunda kaç benzersiz sayı üretildiği sorulur. Hoca bunun aslında rastgele sayı üretecinin ne kadar rastgele olduğunu test etmeye yarayan bir problem olduğunu da söyledi.

**Soru:** 1000'lik bir dizi açıp gelen sayının gözünü artırmak yeterli mi? **Cevap:** Sayaç tutmaya gerek var mı, yoksa yalnız "gördüm, görmedim" bilgisi yeter mi, düşünülmeli. Önemli olan bir sayının birden fazla geçip geçmediğidir; hoca kendi çözümünde 0 ve 1 gibi küçük değerler tuttuğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Yalnız tek bir "gördüm" biti, ilk kez görülen ile birden fazla görülen sayıyı ayırmaya yetmez; her değer için büyük olasılıkla üç durum ("hiç", "bir kez", "birden çok") ayırt edilmelidir. Bu, 0, 1, 2 değerleri alan bir dizi ya da iki ayrı bit dizisi ile yapılabilir.

### 5.2 Kilitli dolap problemi

Okulda $n$ dolap ve $n$ öğrenci vardır; başta bütün dolaplar kapalıdır. Birinci öğrenci 1'in bütün katlarını, yani bütün dolapları açar. İkinci öğrenci 2'nin katlarını (2, 4, 6, ...) tersine çevirir, yani kapatır. Üçüncü öğrenci 3'ün katlarını tersine çevirir: 3 açıktı, kapatır; 6 kapanmıştı, açar. $k$. öğrenci $k$'nin katı olan dolapların durumunu değiştirir: kapalıysa açar, açıksa kapatır. Son öğrenci yalnız kendi numaralı dolabını değiştirir. Soru: verilen herhangi bir $n$ için sonunda hangi dolaplar açık kalır?

Hoca problemin İnternette "locker problem" adıyla bulunabileceğini ama aramadan, düşünerek bir beyin jimnastiği yapılmasını istediğini söyledi. **Soru:** $n$ neyi gösteriyor? **Cevap:** Dolap sayısını; 100, 500, 1000 ya da okulda kaç dolap varsa o olabilir.

## 6. Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): Verilen negatif olmayan bir $N$ tam sayısı için $\lfloor \sqrt{N} \rfloor$ değerini `sqrt` ya da `floor` gibi hazır fonksiyonlar kullanmadan bulan algoritmanın akış diyagramını çizin ve kodlayın.

> **Çözüm:** $i \leftarrow 0$; $i \cdot i \le N$ olduğu sürece $i \leftarrow i + 1$; döngüden çıkınca $i - 1$ yazdırılır. $N = 10$ için 3, $N = 16$ için 4 bulunur. Kod 3.7 bölümündedir (ekrandan, 00:30:00).

**Soru 2** (ekrandan, 00:35:00): Küçükten büyüğe sıralı $a = [2, 5, 5, 5]$ ve $b = [2, 2, 3, 5, 5, 7]$ dizilerinin kesişim kümesini bulup ekrana yazdıran algoritmayı tasarlayın. Kümede tekrar eden eleman olmamalıdır.

> **Çözüm:** İki indisle dizileri birlikte gezin; küçük olanın indisini ilerletin, eşitlikte elemanı bir kez yazdırıp tekrar eden eşit elemanları atlayın, dizilerden biri bitince durun. Cevap $[2, 5]$'tir. Test edilmiş kod 4.4 bölümündedir.

**Soru 3** (derste sözlü, 00:46:06): Derste gösterilen kesişim kodunu bozan (yanlış sonuç ya da dizi dışına taşma üreten) bir örnek bulun.

> **Çözüm (derste verilmedi):** Kodun satırları kayıtta görünmediği için kesin bir karşı örnek verilemez. Bir öğrencinin işaret ettiği durum, eşitlik döngüsünün dizi sınırını kontrol etmemesidir: bütün elemanları aynı olan diziler (örneğin $a = [2, 2, 2]$, $b = [2, 2]$) bu döngünün dizi sonundan sonraki gözü okumasına yol açabilir. C'de bu tanımsız davranıştır ve program her zaman çökmez. Sınır kontrolünü eşitlik döngüsüne eklemek (4.4'teki kod) sorunu giderir.

**Soru 4** (ekrandan, 00:55:00): 1 ile 1000 arasında rastgele üretilmiş $n$ sayı içinde yalnız bir kez geçen sayıların sayısını, diziyi sıralamadan bulan algoritmayı tasarlayın. Örnekler: $A = \{200, 999, 200, 45, 58, 689\}$ için 4; $A = \{15, 56, 78, 999\}$ için 4.

> **Çözüm (derste verilmedi):** 1001 gözlük bir sayaç dizisi sıfırlanır. Her gelen sayı için gözü 2'den küçükse bir artırılır (0: hiç, 1: bir kez, 2: birden çok). Sonunda değeri tam 1 olan gözler sayılır. Zaman $O(n + 1000)$'dir. Aşağıdaki kod ajan tarafından yazıldı, `gcc -Wall` ile derlendi; iki örnek için de 4 verdi.

```c
#include <stdio.h>

#define MAKS 1000

int tekil_say(const int a[], int n) {
    int sayac[MAKS + 1] = {0};
    int k, tekil = 0;
    for (k = 0; k < n; k++)
        if (sayac[a[k]] < 2) sayac[a[k]]++;
    for (k = 1; k <= MAKS; k++)
        if (sayac[k] == 1) tekil++;
    return tekil;
}

int main(void) {
    int a[] = {200, 999, 200, 45, 58, 689};
    int b[] = {15, 56, 78, 999};
    printf("%d\n", tekil_say(a, 6));
    printf("%d\n", tekil_say(b, 4));
    return 0;
}
```

**Soru 5** (derste sözlü, 00:55:04): $n$ dolaplı kilitli dolap probleminde, $k$. öğrenci $k$'nin katı olan dolapları tersine çevirdiğinde sonunda hangi dolaplar açık kalır?

> **Çözüm (derste verilmedi):** Bir dolap, numarasının her böleni için bir kez çevrilir. Bölenler genellikle çiftler hâlinde ($d$ ve $m/d$) geldiği için çevirme sayısı çifttir ve dolap kapalı kalır. Yalnız tam karelerde $d = \sqrt{m}$ böleni eşsiz kalır, çevirme sayısı tek olur. Bu yüzden açık kalan dolaplar tam kare numaralı olanlardır: $1, 4, 9, 16, \ldots$; açık dolap sayısı $\lfloor \sqrt{n} \rfloor$'dir. $n = 100$ için python ile yapılan benzetim 1, 4, 9, 16, 25, 36, 49, 64, 81, 100 dolaplarının açık kaldığını gösterdi.

**Soru 6** (derste sözlü, 00:14:05): Kalbur çıktısında her asal sayının yanına o sayıya kadar olan asal sayıların sayısı kadar çizgi çizdirilmek isteniyor, ama kod asal sayının değeri kadar çizgi çiziyor. Kodu nasıl düzeltirsiniz?

> **Çözüm (derste verilmedi):** Asal sayıları sayan ayrı bir sayaç tutulur; her asal bulunduğunda sayaç bir artırılır ve çizgi sayısı asal sayının değerine göre değil, bu sayacın değerine (adım sabitine bölünmüş hâline) göre belirlenir. Böylece 2 için 1, 3 için 2, 5 için 3, 7 için 4 çizgi çıkar.

## Dersin Toparlaması

Bu uygulama saatinde üç algoritma tasarım alıştırması yapıldı. Eratosthenes Kalburu kodlanıp asal sayıların artışı çizgilerle izlenmek istendi; bir öğrencinin fark ettiği hata, çıktıyı yorumlamadan önce kodun gerçekten ne yazdırdığını kontrol etmenin önemini gösterdi. Tam sayı karekökü örneğinde dizi kullanan bir başlangıç çözümünden tek değişkenli, `if` içermeyen bir döngüye adım adım gelindi ve `<=` koşulunun uç noktalardaki önemi görüldü. Sıralı iki dizinin kesişiminde ise verilen ön koşulun (sıralılık) iki indisle tek geçişli bir çözüm sağladığı, tekrarların ve dizi sonlarının dikkat gerektirdiği tartışıldı.

Dersin ortak mesajı, önce çalışan basit bir çözüm kurmak, sonra yer, işlem ve kontrol sayısı açısından onu iyileştirmek ve uç noktaları test etmektir. Bir sonraki teorik derste algoritma analizine ve karmaşıklık konusuna geçileceği, algoritmaların nasıl analiz edilip karşılaştırıldığına bakılacağı söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
