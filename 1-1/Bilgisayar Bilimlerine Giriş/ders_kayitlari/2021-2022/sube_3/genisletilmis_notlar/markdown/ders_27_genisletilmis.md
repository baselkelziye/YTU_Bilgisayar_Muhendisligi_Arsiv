# Ders 27 Genişletilmiş Notu: Dizi Algoritmaları, Karakter Sabitleri ve Karakter Dizileri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Diziye araya eleman ekleme
- 2. Global ve yerel değişken
- 3. Belirli bir değerden sonraya ekleme
- 4. Tek geçişte en küçük iki elemanı bulma
- 5. Karakter sabitleri ve ASCII kodu
- 6. Önceden tanımlı karakterler (kaçış dizileri)
- 7. Karakter dizileri ve null karakter
- 8. gets ve puts fonksiyonları
- 9. Karakter dizisi örnekleri: okuma, uzunluk, ters çevirme
- 10. Harf frekansı ve sayaç dizisi
- Örnek Sorular

Derste kod çevrim içi bir C derleyicisinde (onlinegdb) yazılıp çalıştırıldı, akış diyagramları sanal beyaz tahtaya fareyle çizildi. Dersin ilk yarısında önceki haftalarda görülen dizi işlemlerine birkaç farklı düşünme yolu gösteren alıştırma yapıldı, aradan sonra dersin asıl konusu olan karakter sabitleri ve karakter dizilerine geçildi.

## 1. Diziye araya eleman ekleme

### 1.1 Problem

Tahtada şu dizi var (ekrandan, 00:10:00):

```text
arr = 10, -20, 40, -10, 90, 50, 30, 45, 60
indis:  0    1   2    3   4   5   6   7   8
```

İstenen, kullanıcının verdiği bir değeri (örnekte 55) istenen bir indise (örnekte 6) eklemektir. Bunun için o noktada dizide bir "göz açmak" gerekir: 6. indisten sonraki bütün elemanlar birer göz sağa kaydırılır, boşalan 6. göze yeni değer yazılır.

Kaydırmanın yönü önemlidir. Soldan başlanırsa (önce 30'u 7. göze yazmak gibi) 7. gözdeki 45 ezilir ve artık kopyalanamaz. Bu yüzden kaydırma sondan başlar: önce 60 bir sağa, sonra 45, sonra 30 kopyalanır. 30'un eski yerine artık 55 yazılabilir. Sonuçta 9 elemanlı dizi 10 elemanlı hale gelir.

Henüz dinamik bellek yönetimi ve boyutu çalışma sırasında belirlenen diziler bilinmediği için, bu tür sorularda dizi baştan büyük açılır (örneğin 100 elemanlı). Gerçek eleman sayısı ayrı bir değişkende tutulur ve dizinin boş kalan gözleri genişleme için kullanılır.

### 1.2 Akış diyagramı

Akış diyagramında `N` gerçek eleman sayısı, `M` dizinin bellekte ayrılan boyu, `A[M]` dizi, `X` eklenecek değer, `Pos` hedef indistir (ekrandan, 00:20:00 ve 00:35:00):

```text
START
  |
[ N, M, A[M], X, Pos oku ]
  |
[ N = N + 1 ]
  |
döngü: i = N'den başla, adım -1, Pos'a kadar
  |---> [ A[i] = A[i-1] ] ---> döngü başına
  |
(döngü bitince)
[ A[Pos] = X ]
  |
STOP
```

Önce eleman sayısı bir artırılır, çünkü dizide artık bir eleman daha olacaktır. Geriye doğru giden döngü her adımda bir önceki gözdeki değeri bulunduğu göze taşır. Döngü `Pos`'a gelince durur ve boşalan `Pos` gözüne `X` yazılır. Hoca isteyenin sonucu yazdırma adımını da ekleyebileceğini söyledi.

### 1.3 C kodu

Hoca akışı koda dönüştürürken çeşitlilik olsun diye birkaç yeni yazım biçimi de gösterdi (ekrandan, 00:25:00 ve 00:30:00):

```c
#include <stdio.h>
#define N 9

int a[N]= {10, -20, 40, -10, 90, 50, 30, 45, 60};

int main()
{
    int i, x=55, pos=6;

    for (i=N; i>pos; i--)
        a[i] = a[i-1];

    a[pos] = x;

    for (i=0;i<N+1; i++){
        printf("%d ",a[i]);
    }

    return 0;
}
```

- `#define N 9` bir önişlemci tanımıdır. 9 sabitine `N` diye bir "lakap" takılmış olur; kodda `N` görülen her yerde 9 kullanılır. Bu sayede dizinin boyutu `a[N]` biçiminde verilebilir.
- Diziye ilk değerler küme parantezi içinde verilir. Normalde kod bloğunu kapatan küme parantezinden sonra noktalı virgül konmaz; dizi ilk değer atamasında ise bu bir atama ifadesi olduğu için sondaki `;` zorunludur.
- `x` ve `pos` hızlı olsun diye `scanf` ile okunmadan doğrudan atandı.
- Döngü gövdesinde tek satır olduğu için küme parantezi açılmadı; yazdırma döngüsünde ise isteğe bağlı olarak blok kullanıldı.

Kod ilk çalıştırıldığında yazdırma döngüsü `i=N+1` (karşılaştırma yerine atama) diye yazıldığı için hep aynı değeri basan sonsuz bir döngüye girdi; koşul `i<N+1` yapılınca düzeldi. Çıktı:

```text
10 -20 40 -10 90 50 55 30 45 60
```

55, 50'den sonra, yani 6. indise yerleşti.

> **Ders sonrası not:** Hoca dizinin bir göz fazlasıyla tanımlandığını söyledi; ancak `#define N 9` ile `int a[N]` tam 9 gözlüdür ve döngünün ilk adımındaki `a[9] = a[8]` ataması dizinin dışına yazar. Bu C'de tanımsız davranıştır; program derste doğru çıktı verse de buna güvenilmemelidir. Doğrusu diziyi `int a[N+1]` (ya da daha büyük) açmaktır. `a[N+1]` ile yazılan sürüm `gcc -Wall` ile derlenip çalıştırıldı ve aynı çıktıyı verdi.

**Soru:** Döngü `N+1`'den başlatılabilir miydi? **Cevap:** Evet, o da olurdu (dizide yer olduğu sürece).

## 2. Global ve yerel değişken

Bir öğrenci dizinin `main` içinde değil, dışarıda tanımlandığını fark etti. Hoca bunu bilerek yaptığını söyledi.

`main` dahil bütün fonksiyonların dışında, `#include` satırlarıyla aynı düzeyde tanımlanan değişken **global değişkendir**: programdaki her fonksiyondan erişilebilir. Genellikle global değişken kullanmak iyi bir alışkanlık sayılmaz, mümkün olduğunca yerel değişken kullanılır. Nedeni bellek kullanımıdır: global değişkenlerin yeri derleme sırasında baştan ayrılır ve program başladığı andan bittiği ana kadar bellekte yer tutar, programın bellekteki "ayak izini" büyütür. Aynı dizi bir fonksiyonun içinde tanımlansaydı yalnızca o fonksiyon çalıştığı sürece yer kaplayacaktı.

Çok sayıda fonksiyon ya da modülün aynı veri havuzunu ortak kullanması gerektiğinde global değişken uygundur; ama gereğinden fazla kullanıldığında sürekli tüketilen gereksiz bir bellek alanına dönüşür.

## 3. Belirli bir değerden sonraya ekleme

Hoca soruyu biraz değiştirdi: pozisyon doğrudan verilmesin, bunun yerine "50 değerinden sonraki göze ekle" densin. Akışta ne değişir?

Bir öğrencinin önerisi: 50 dizinin başından itibaren aranır, bulunduğu indisin bir sonrası pozisyon olarak alınır ve sonra önceki işlem tekrarlanır. Hoca bu öneriyi akışa ekledi (ekrandan, 00:35:00):

```text
[ key oku ]            (aranacak değer, örnekte 50)
[ f = -1 ]
döngü: i = 1'den N'e, adım 1
  |---> < A[i] = key ? > --T--> [ f = i ]
  |
(döngü bitince)
< f >= 0 ? >
  T --> [ Pos = f + 1 ]   (bulunan değerden sonraki göz)
  F --> [ Pos = N ]       (bulunamadı: sona ekle)
  |
(bölüm 1.2'deki kaydırma ve A[Pos] = X)
```

- `f` ("found") başlangıçta -1'dir; değer bulunursa bulunduğu indis olur. Hoca önce `f = 1` yazmayı düşünüp vazgeçti: 1 yazmak yalnızca bulunduğunu söyler, nerede bulunduğunu söylemez.
- Bulunamazsa bir şey yapmaya gerek yoktur; döngüden sonra `f` hâlâ -1'dir.
- Arama `while` döngüsüyle, değer bulununca çıkacak şekilde daha verimli yazılabilir; tahtada yer darlığı yüzünden bütün elemanlara bir kez bakan `for` kullanıldı.
- Akış diyagramı sayfaya sığmadığında bağlantı noktaları (daire içinde 1, 2) kullanılarak devam edildi.

**Soru:** Akış diyagramında döngü neden 0'dan değil 1'den başlıyor? **Cevap:** Akış diyagramı genel çözümü gösterir ve her dilde indis sıfırdan başlamak zorunda değildir; bu yüzden 1'den N'e yazılır. C koduna geçildiğinde döngü 0'dan N-1'e (`i < N`) kurulur.

Hoca bu sürümün kodunu yazmadı; arama zaten önceki haftalarda öğrenildiği için gerek görmedi.

## 4. Tek geçişte en küçük iki elemanı bulma

### 4.1 Problem ve kısıtlar

Yeni dizi (ekrandan, 00:40:00):

```text
a = 20, 30, 1, 20, 40, 9        eleman değerleri < 100
```

İstenen, dizinin en küçük iki elemanını `m1` (en küçük) ve `m2` (ikinci en küçük) değişkenlerine bulmaktır; bu dizi için `m1 = 1`, `m2 = 9` beklenir. Elemanların 100'den küçük olduğu varsayımı problemi kolaylaştırmak içindir.

Kısıt: dizinin üzerinden yalnızca **bir kez** geçilecek. Şu yollar kabul edilmiyor:

- Minimumu bulmak, onu diziden silip (ya da yerine çok büyük bir değer yazıp) bir daha minimum aramak.
- Diziyi sıralayıp ilk iki elemanı almak. Sıralamak, dizinin üzerinden en az iki kez geçmek demektir.

Bir öğrenci `m1` ve `m2`'ye dizinin ilk iki elemanını atamayı önerdi. Hoca bunun da ek bir karşılaştırma (hangisi daha küçük, gerekirse yer değiştirme) gerektirdiğini, kendisinin ise döngüden önce özel durum işlemeyen, genel bir çözüm aradığını söyledi.

### 4.2 Başlangıç değeri

`m1` ve `m2`'ye dizide bulunamayacak kadar büyük bir değer verilir: 1000. Böylece ilk gelen eleman mutlaka bunlardan küçük olur.

Gerçek bir C programında bunun için `limits.h` başlık dosyası eklenip orada tanımlı en büyük tam sayı değeri kullanılabilir; bu değer çalışılan mimariye göre olabilecek en büyük `int` değeridir.

> **Ek bilgi (derste anlatılmadı):** `limits.h` içindeki sabitin adı `INT_MAX`'tır; 32 bitlik `int` kullanan yaygın sistemlerde değeri büyük olasılıkla 2147483647'dir.

### 4.3 Akış diyagramı

(ekrandan, 00:50:00)

```text
START
  |
[ N, A[N] oku ]
  |
[ m1 = 1000, m2 = 1000 ]
  |
döngü: i = 1'den N'e, adım 1
  |---> < A[i] < m1 ? >
  |        T --> [ m2 = m1 ; m1 = A[i] ] ---------------> döngü başına
  |        F --> < A[i] < m2  ve  A[i] ≠ m1 ? >
  |                 T --> [ m2 = A[i] ] ----------------> döngü başına
  |                 F ----------------------------------> döngü başına
  |
(döngü bitince, bağlantı 1)
< m2 = 1000 ? >
  T --> "ikinci küçük eleman yok", m1 yazdır
  F --> m1 ve m2 yazdır
  |
STOP
```

Kritik nokta, `A[i] < m1` durumundaki atama sırasıdır. Yeni gelen değer en küçükse, eski en küçük artık ikinci en küçük olur. Bu yüzden önce `m2 = m1` yazılır, sonra `m1 = A[i]`. Sıra ters olursa eski `m1` değeri ezilip kaybolur.

`A[i]`, `m1`'den küçük değilse bu kez `m2`'den küçük mü diye bakılır. Küçükse eski `m2` atılabilir: o artık üçüncü en küçüktür ve üçüncü en küçük sorulmadığı için onu bir yere aktarmaya gerek yoktur.

`A[i] ≠ m1` şartı aynı değerin tekrarını ele alır. Dizide iki tane 1 olsaydı, ikinci 1 ikinci en küçük sayılmazdı: en küçük zaten bulunmuştur, aynı değer bir daha dikkate alınmaz. Örneğin dizi `20, 20, 20, ...` olsaydı `m1` bir kez 20 olur, `m2` ise 1000'de kalırdı; yani dizide ikinci bir minimum eleman yoktur. Döngüden sonraki `m2 = 1000` kontrolü bu durumu yakalar.

> **Hocanın vurgusu:** Akış diyagramlarında okları her zaman çizmeye gayret edin.

### 4.4 Elle izleme

Dizi `20, 30, 1, 20, 40, 9`, başlangıçta `m1 = 1000`, `m2 = 1000`:

| Gelen | Karşılaştırma | m1 | m2 |
|---|---|---|---|
| 20 | 20 < 1000 → T | 20 | 1000 |
| 30 | 30 < 20 değil; 30 < 1000 ve 30 ≠ 20 → T | 20 | 30 |
| 1 | 1 < 20 → T (önce m2 = 20) | 1 | 20 |
| 20 | 20 < 1 değil; 20 < 20 değil → F | 1 | 20 |
| 40 | 40 < 1 değil; 40 < 20 değil → F | 1 | 20 |
| 9 | 9 < 1 değil; 9 < 20 ve 9 ≠ 1 → T | 1 | 9 |

Döngüden sonra `m2 = 9`, 1000 değil; ekrana `m1 = 1` ve `m2 = 9` yazdırılır.

**Soru:** Dizide iki tane 1 olsaydı? **Cevap:** Hoca soruyu "eşit değerler hariç en küçük iki farklı değer" olarak güncelledi; bu yorumla ikinci 1 göz ardı edilir.

### 4.5 C kodu

Bu kez dizi `main` içinde, boyutu verilmeden, ilk değerlerinden boyutlanacak şekilde tanımlandı (ekrandan, 00:55:00 ve 01:00:00). Kodda tahtadaki dördüncü eleman 20 yerine 10 yazıldı:

```c
#include <stdio.h>

int main()
{
    int a[] = {20, 30, 1, 10, 40, 9};
    int n = 6;
    int i, m1=1000, m2=1000;

    for (i=0; i<n; i++){
        if(a[i]<m1){
            m2=m1;
            m1=a[i];
        }
        else if(a[i]<m2 && a[i]!=m1)
            m2=a[i];
    } //for i

    if(m2==1000)
        printf("ikinci kucuk eleman yok, min1:%d \n",m1);
    else
        printf("1.kucuk: %d  2.kucuk:%d \n",m1,m2);

    return 0;
}
```

- İç içe `if` olduğu için `for` gövdesine mutlaka küme parantezi konur; `else if` kolunda tek işlem olduğu için blok açılmadı.
- Çok iç içe döngülerde kapanan parantezin hangi döngüye ait olduğunu `//for i` gibi bir yorumla belirtmek okunaklılığı artırır.
- `\n` ile satır sonuna inildi; hoca bunun ayrıntısını karakter dizileri konusunda anlatacağını söyledi.

Çalıştırmalar:

- `{20, 30, 1, 10, 40, 9}` → `1.kucuk: 1  2.kucuk:9`
- Son eleman 1 yapılınca (`{20, 30, 1, 10, 40, 1}`) eşitlik şartı ikinci 1'i atlar → `1` ve `10`.
- Bütün elemanlar 20 olunca → `ikinci kucuk eleman yok, min1:20` (ekrandan, 01:00:00).

Bu üç durum `gcc -Wall` ile derlenip ayrıca denendi, aynı sonuçlar alındı.

### 4.6 Diziyi kullanıcıdan okumak

**Soru:** Diziyi kullanıcıdan almayı gösterebilir misiniz? **Cevap:** Dizi boş olarak `int a[6];` diye tanımlanır, sonra bir döngüyle her eleman okunur (ekrandan, 01:05:00):

```c
printf("dizi elemanlarını giriniz..\n");
for (i=0; i<n; i++){
    printf("%d. elemanı girin:\n",i);
    scanf("%d", &a[i] );
}
```

Girdi `20, 30, 1, 10, 40, 9` verilince yine `1.kucuk: 1  2.kucuk:9` yazdırıldı. Hoca, kullanıcıya 1'den başlayan sıra göstermek isteyenin `i+1` yazdırabileceğini söyledi.

## 5. Karakter sabitleri ve ASCII kodu

Aradan sonra yeni konunun başlığı atıldı: **Karakter Sabitleri ve Karakter Dizileri** (ekrandan, 01:20:00).

### 5.1 Karakter sabiti

Tek tırnak arasında yazılan tek bir karaktere **karakter sabiti** denir: `'a'`, `'G'`, `'<'`. Harf olabileceği gibi sembol de olabilir; ama mutlaka tek tırnak içinde yazılmalıdır.

### 5.2 char veri tipi

C'deki `float`, `int`, `long int` gibi tiplerin bellekte kapladığı yer mimariye ve derleyiciye göre değişse de sabittir. `char` tipi de bunlardan biridir ve 1 bayt (8 bit) yer kaplar. Yani `char` aslında 8 bitlik bir sayıdan başka bir şey değildir.

Bir karakter sabitinin karşılığı, o karakterin kullanılan kod tablosundaki sıra numarasıdır. C'de kullanılan tablo ASCII tablosudur. `'a'`'nın ASCII kodu onluk tabanda 97'dir. Yani `ch = 'a';` yazınca bellekte aslında 97 sayısı (işaretli 8 bitlik bir sayı, -128 ile 127 aralığında) saklanır. Büyük `'A'` 65, boşluk 32'dir.

Derste şu kod incelendi (ekrandan, 01:20:00 ve 02:05:00):

```c
int main(){
    char ch;
    ch = 'a';
    printf("%c %d",ch, ch);   // a 97
    ch = 'a'+1;               // 97+1 = 98
    printf("%c %d",ch, ch);   // b 98
}
```

- `%c` yeni bir biçim belirtecidir: değeri karakter olarak yazdırır. Aynı değişken `%d` ile yazdırılınca sayısal kodu görülür.
- Karakterler bellekte sayı olduğu için üzerlerinde aritmetik yapılabilir. `'a' + 1` aslında 97 + 1 = 98'dir; 98 ASCII'de küçük `b` harfidir.

Kod derleyicide çalıştırılınca `a 97` ve `b 98` görüldü; `'A'` ile denenince 65 çıktı. Büyük ve küçük harfler alfabe sırasıyla ardışık kodlanır.

## 6. Önceden tanımlı karakterler (kaçış dizileri)

### 6.1 Ters bölü ile başlayan sabitler

Ekranda gösterilemeyen ama özel anlamı olan karakterler için ters bölü (`\`, backslash) ile başlayan önceden tanımlı karakter sabitleri kullanılır. Tırnak içinde iki karakter yazılmış gibi görünse de bu tek bir karakterdir. Ters bölü "kaçış" (escape) karakteridir: arkasından gelen harfin kendisini değil, özel anlamlı bir karakteri gösterdiğini belirtir.

Derste yazılan liste (ekrandan, 01:30:00):

| Sabit | ASCII | Anlamı |
|---|---|---|
| `'\a'` | 7 | Alarm (bip sesi) |
| `'\b'` | 8 | Backspace (bir karakter geri) |
| `'\f'` | 12 | Form feed (sayfa ileri) |
| `'\n'` | 10 | New line (yeni satır) |
| `'\r'` | 13 | Carriage return (satır başı) |
| `'\t'` | 9 | Tab (sekme) |
| `'\v'` | 11 | Vertical tab (dikey sekme) |

- `\a` anakarttaki buzzer'ın bip diye ötmesini sağlar. Derste çevrim içi ortamda ses öğrencilere duyulmadı; hoca kendi bilgisayarında denemelerini önerdi. `printf("%c %d")` çıktısında karakter görünmedi, kod olarak 7 yazdı (ekrandan, 01:25:00).
- `\b` silme tuşuna basılmış gibi bir karakter geri gider. Derste bir "Hello World" metninin içine `\b` konup yazdırıldı ve harflerden birinin kaybolduğu görüldü. <!-- BELİRSİZ: \b örneğinde kullanılan metnin tam hali karelerde görünmüyor. -->
- `\n` yeni satıra geçer. `\r` aynı satırın başına döner. Bazı eski yazıcılarda satır sonu için hem satır başı hem yeni satır (`\r\n`) kullanılır; Linux türevlerinde ve terminal çıktılarında `\n` yeterlidir.
- `\t` 4-5 karakterlik bir sekme (paragraf) boşluğu verir. Derste `printf("Hell\tlllo Worlllld\n")` ile denendi (ekrandan, 01:30:00).
- `\v` dikey sekmedir; hoca hiç kullanmadığını ve kullananı da pek görmediğini söyledi.
- ASCII numaralarını ezberlemek önemli değildir; bilgi olsun diye verildi.

> **Ek bilgi (derste anlatılmadı):** Terminalde `\b` karakteri gerçekte bir şey silmez, imleci bir sola taşır; sonra yazılan karakter öncekinin üzerine yazılır. Bu yüzden görünen sonuç, `\b`'den sonra ne yazıldığına bağlıdır.

### 6.2 Ters bölü ve çift tırnağın kendisi

Ters bölü özel anlamda kullanıldığına göre, kendisi yazdırılmak istenirse yine kaçış karakteriyle yazılır: `\\`. `printf` içindeki metin çift tırnakla sınırlandığı için, metnin içinde çift tırnak yazdırmak için de `\"` kullanılır. Örnek (ekrandan, 01:35:00):

```c
printf("\"Hello\\ \\World\"");
```

Çıktı: `"Hello\ \World"`.

### 6.3 Null karakter

Son önceden tanımlı karakter `'\0'`'dır: ASCII tablosundaki 0 numaralı karakter. Standart kütüphanede `NULL` olarak da tanımlıdır ve **null karakter** diye anılır. Ne işe yaradığı karakter dizilerinde görülür (bölüm 7).

### 6.4 Karakteri onaltılık ve sekizlik kodla vermek

Bir karakter sabiti onluk karşılığıyla (`ch = 97;`) atanabileceği gibi başka tabanlarla da yazılabilir:

- `'\x41'`: `\x` onaltılık tabanı gösterir. 41H = 65, yani `A`. Kod `printf("%c %d", ch, ch)` ile çalıştırılınca `A 65` çıktı. Büyük `\X` bu derleyici ortamında kabul edilmedi; hoca bazı derleyicilerin kabul ettiğini söyledi.
- `'\x1d'`: 1DH = 29, ekranda gösterilemeyen karakterlerden biri.
- `'\xF1'`: ekranda bir sembol olarak göründü, `%d` ile `-15` yazdı (ekrandan, 01:50:00).
- `'\12'`: ters bölüden sonra rakam gelirse sekizlik taban anlaşılır. Sekizlik 12 = 8 + 2 = 10, yani ASCII 10, new line. Yazdırılınca alt satıra geçildi.

<!-- BELİRSİZ: Hoca sekizlik 123'ü denerken bir yazım hatası yaptı; ekranda `+ 43` çıktısı görünüyor (ekrandan, 01:55:00). Yazılan sabit karede okunmuyor. -->

> **Ek bilgi (derste anlatılmadı):** `'\xF1'` = 241 değeri işaretli 8 bitlik `char`'a sığmaz; ikiye tümleyen gösteriminde -15 olarak yorumlanır (241 - 256 = -15). Bu yüzden `%d` ile -15 yazdırılır.

Alarm karakteri üç farklı biçimde yazılabilir ve hepsi aynı ASCII 7 karakterini gösterir:

```c
ch = '\a';     // önceden tanımlı kaçış dizisi
ch = '\x07';   // onaltılık 7
ch = '\07';    // sekizlik 7
```

> **Hocanın vurgusu:** Hoca okunaklı olduğu için `'\a'` biçimini tercih ediyor: önceden tanımlı karakterler kaçış diziyle yazıldığında ne oldukları (alarm karakteri) hemen anlaşılır.

## 7. Karakter dizileri ve null karakter

### 7.1 Karakter dizisi tanımlama

Tek bir karakter yerine bir metin tutmak için karakter tipinde bir dizi açılır. Önceki saatteki dizi ilk değer atamasının aynısı burada da geçerlidir (ekrandan, 01:35:00 ve 01:45:00):

```c
char y[10] = {'y', 'i', 'l', 'd', 'i', 'z', '\0'};
char t[]   = {'t', 'e', 'k', 'n', 'i', 'k', '\0'};
char u[]   = "universitesi";
printf("%s %s %s \n", y, t, u);
```

Çıktı: `yildiz teknik universitesi`.

- Türkçe karakterler ASCII tablosunda olmadığı için kullanılmadı; bunu çözmenin kod sayfası değiştirmek gibi yolları vardır, derste bu konuya girilmedi.
- `y` 10 gözlük açıldı ama yalnızca 0-5. indisler harflerle, 6. indis null karakterle dolduruldu. 10 gözlük yerde 7 karakter tutmak sorun değildir.
- `t`'nin boyutu verilmedi; derleyici ilk değerleri sayıp 7 gözlük (7 bayt) yer ayırır. İstenirse köşeli paranteze 7 yazılabilirdi.
- `%s` karakter dizisi (string) biçim belirtecidir.

### 7.2 Null karakterin rolü

> **Hocanın vurgusu:** Bütün karakter dizileri, istisnasız, null karakter (`'\0'`) ile sonlanmalıdır. Karakter dizisini kendiniz oluşturuyorsanız (ilk değer atamasıyla ya da kullanıcıdan harf harf okuyarak) sondaki `'\0'`'ı koymak sizin sorumluluğunuzdur.

C'de bir karakter dizisinin boyutu ayrıca tutulmaz. Dizinin nerede bittiğini derleyici ve karakter dizileriyle çalışan fonksiyonlar null karakteri görerek anlar. `y` örneğinde `printf` "yildiz" yazdıktan sonra null karakteri gördü ve durdu; dizinin geri kalan 3 gözüyle ilgilenmedi.

`t`'de null karakter unutulursa ne olur? `printf` "teknik"i yazdıktan sonra bellekte o dizinin arkasından gelen gözleri, ilk `'\0'`'ı görene kadar yazdırmaya devam eder. Derste bu denendiğinde çıktıya önceki çalıştırmalardan bellekte kalan "yildiz" kelimesi de eklendi. Null karakter geri konunca çıktı yine "teknik"te bitti.

### 7.3 Çift tırnak ve derleyicinin eklediği null karakter

`char u[] = "universitesi";` satırında null karakter konmadığı halde `printf` doğru yerde durdu. Nedeni çift tırnaktır:

- Karakterler tek tek veriliyorsa tek tırnak kullanılır ve `'\0'`'ı programcı koyar.
- Bütün metin bir kerede çift tırnakla veriliyorsa sondaki `'\0'`'ı derleyici kendisi ekler.

Haftalardır `printf` ve `scanf` içinde çift tırnakla yazılan metinler de aynı şekilde derleyici tarafından null karakterle sonlandırılır.

İleride işaretçiler (pointer) ve dinamik bellek öğrenilince bu tür tanımlar farklı biçimde yazılacak. Dizinin adı aslında karakter dizisinin ilk gözünün adresini tutan bir referanstır; şimdilik sabit uzunluklu ya da ilk değer atamasıyla boyutlanan dizilerle devam ediliyor.

### 7.4 Boyutu küçük ya da büyük vermek

- `t` ya da `u`'ya 3 gibi küçük bir boyut verildiğinde derleyici uyarı verdi (ekranda `initializer-string for array of chars is too long`; karakter karakter verilen dizide "excess elements in array initializer"). Dizi yalnızca ilk 3 harfi tuttu ve null karakter olmadığı için `printf` bellekte arkadan gelen veriyi de yazdırdı. Çıktı `yildiz teknik uniteknik` oldu (ekrandan, 01:45:00).
- Boyut 30 verilince sorun çıkmadı: 30 bayt yer ayrılır, 13 baytı kullanılır. Verimsizdir ama çalışır.

> **Hocanın vurgusu:** Boyutlandırmaya dikkat edin; beklenmedik çıktılar genellikle yetersiz boyuttan ya da eksik null karakterden kaynaklanır.

### 7.5 Null karakterin faydası ve bedeli

Null karakter, karakter dizisinin uzunluğunu bilme ihtiyacını ortadan kaldırır. Kod "null görene kadar" mantığıyla, örneğin `while` döngüleriyle yazılır; karakter dizileriyle çalışan bütün algoritmalar ve fonksiyonlar böyle çalışır. Bu yalnızca karakter dizilerine özgüdür, sayı dizilerinde böyle bir sonlandırıcı tanımlı değildir. Bu sayede bir fonksiyona karakter dizisi gönderilirken yanında boyutunu da göndermek gerekmez.

Bedeli her zaman bir baytlık fazladan yerdir. 10 gözlük bir karakter dizisi 10 değil, en fazla 9 gerçek karakter tutar; son bayt null karakterindir. Genel olarak: `n` elemanlı bir karakter dizisine en fazla `n-1` kullanılabilir karakter konabilir.

## 8. gets ve puts fonksiyonları

### 8.1 gets ile okuma

Kullanıcıdan bir karakter dizisi okumak için `scanf` kullanılabilir, ama karakter karakter okunursa sondaki null karakteri programcının koyması gerekir. Daha hızlı bir yol `gets`'tir (ekrandan, 01:55:00):

```c
char aa[20];
int i;

printf("adınızı giriniz:");
gets(aa);

i=0;
while(aa[i]!='\0'){
    printf("%c\n", aa[i]);
    i++;
}
```

Döngü dizinin boyutunu bilmeden, yalnızca null karakter görene kadar dönüp her karakteri ayrı satıra yazdırır. Bir ad girildiğinde harfleri alt alta yazdırıldı. Null karakteri ekleme sorumluluğu `gets`'in kendisindedir.

Boşluk, rakam ve semboller de karakter dizisinin parçasıdır: araya boşluk konmuş bir ad soyad ya da `3 * pi = 2 kare` gibi bir metin de aynı şekilde okunup yazdırıldı.

> **Hocanın vurgusu:** Karakter deyince yalnızca harflere takılı kalmayın; semboller ve rakamlar da karakterdir.

### 8.2 gets'in tehlikesi

Derleyici `gets` için uyarı verir (ekranda `the 'gets' function is dangerous and should not be used`, ekrandan, 02:00:00). Dizinin boyutu derleme zamanında belirlenir (örneğin 20), ama `gets` çalışma zamanında kaç karakter girileceğini denetlemez. Dizi 10 gözlü yapılıp çok uzun bir kelime girildiğinde program `stack smashing detected` mesajıyla zorla sonlandırıldı; dizi 5 gözlü yapılınca hiçbir şey yazdıramadan kapandı. Bu hata derleme sırasında değil, çalışma sırasında ortaya çıkar.

Ad gibi uzunluğu belli bir sınırı geçmeyeceği varsayılan girdiler için dizi büyük açılırsa (örneğin 100) `gets` şimdilik kullanılabilir.

> **Ek bilgi (derste anlatılmadı):** `gets` büyük olasılıkla C11 standardından çıkarılmıştır (C99'da kullanımdan kaldırılmış sayılmıştı). Güvenli seçenek `fgets(aa, sizeof aa, stdin)`'dir; boyutu sınırlar ama satır sonundaki `\n` karakterini de diziye alır.

### 8.3 printf ve puts ile yazdırma

Karakter dizisini tek tek yazdırmak yerine `printf("%s", aa);` kullanılabilir. `gets` (get string) varsa `puts` (put string) da vardır (ekrandan, 02:00:00):

```c
puts(aa);   // printf("%s\n", aa); ile denktir
```

`puts` sona kendisi satır sonu ekler. İkisi de null karakter görene kadar çalışır. Hoca null karakteri olmayan bir diziyi elle oluşturup `puts` ile yazdırdığında çıktı bu sefer düzgün görünse de böyle yapılmaması gerektiğini, en doğru yolun `'\0'`'ı elle eklemek olduğunu söyledi.

## 9. Karakter dizisi örnekleri: okuma, uzunluk, ters çevirme

### 9.1 Karakter dizisini okuma akışı

Bir karakter dizisinin okunması akış diyagramında şöyle gösterilebilir (ekrandan, 02:05:00):

```text
START
  |
[ i = 0 ]
  |
[ i = i + 1 ]  <-----------------+
  |                              |
[ ch[i] oku ]                    |
  |                              |
< ch[i] ≠ '\0' ? > ---- evet ----+
  |
 hayır: ch artık bir karakter dizisi
```

C'ye benzesin diye başlangıç `i = -1` alınabilir; böylece ilk okunan göz 0. göz olur. Akış diyagramı olarak `i = 0` ile başlamak da yeterlidir. Okunan karakter null olana kadar okumaya devam edilir; bundan sonra `ch` her yerde karakter dizisi olarak kullanılabilir ve işlemler aynı kontrolle karakter karakter yapılır.

> **Hocanın vurgusu:** Akış diyagramında START yazmayı unutmayın.

### 9.2 Uzunluk bulma

Karakter dizisinin kaç karakter olduğu null karakter bulunana kadar sayılarak bulunur (ekrandan, 02:10:00):

```c
char s[100];
int k = 0;

gets(s);
while (s[k] != '\0')
    k++;
printf("Uzunluk:%d\n", k);
```

`merhaba` girildiğinde uzunluk 7, `merhaba dostum` girildiğinde 14 (boşluk dahil) bulundu. `scanf` de kullanılabilir, ama o zaman karakterleri tek tek girmek ya da `%s` ile okumak gerekir; `gets` daha kısa bir seçenektir.

### 9.3 Ters çevirme

Problem: bir karakter dizisini tersine çevirmek. Bir öğrenci dizinin yarısına kadar elemanların karşılıklı yer değiştirmesini önerdi. Hoca bunu `merhaba` üzerinde gösterdi (ekrandan, 02:15:00):

```text
merhaba     n = 7, n div 2 = 3 adım
AerhabM     1. adım: 0. ile 6. göz yer değiştirir
ABrhaEM     2. adım: 1. ile 5. göz yer değiştirir
abahrem     3. adım: 2. ile 4. göz yer değiştirir; ortadaki h yerinde kalır
```

Büyük harfler yalnızca değişen gözleri göstermek için kullanıldı. Tam sayı bölmesiyle 7 div 2 = 3 adım yeterlidir: tek uzunlukta ortadaki eleman zaten yerinde kalır, çift uzunlukta (örneğin 6) baştaki üç ile sondaki üç eleman yer değiştirir.

Önce uzunluk `n` bulunur. Hoca bunun için tek satırlık bir yazım da gösterdi ama önermediğini belirtti:

```c
for(n=0; s[n]; n++); // tavsiye etmiyorum. yukarıdaki döngü daha okunaklıdır.
```

Bu `for`'un koşul kısmında yalnızca `s[n]` yazılır: null karakter (0) yanlış (false) demektir, diğer her karakter doğru sayılır. Gövdesi boştur, her adımda yalnızca `n` artar.

> **Hocanın vurgusu:** `while` döngüsü daha okunaklı, daha algoritmiktir ve akış diyagramı ifadesine daha uygundur.

Yer değiştirme bir geçici değişkenle yapılır (ekrandan, 02:15:00):

```c
char s[100];
char temp;
int j, n;

gets(s);
n = 0;
while (s[n] != '\0')
    n++;

for(j=0; j<n/2; j++){
    temp = s[j];
    s[j] = s[n-j-1];
    s[n-j-1] = temp;
}
puts(s);
```

`j`. göz, sondan `j`. göz olan `n-j-1`. gözle yer değiştirir; `-1`, C'de indislerin 0'dan başlamasından gelir. Böylece iki uçtan ortaya doğru ilerlenir. `temp` `int` de olabilirdi, karakterlerle çalışıldığı için `char` seçildi.

Çalıştırmalar: `merhaba` → `abahrem`, `teknik` → `kinket`, `yildiz teknik universitesi` → `isetisrevinu kinket zidliy`. Bu kod `gets` yerine `fgets` kullanılarak derlenip aynı girdilerle denendi, sonuçlar doğrulandı.

## 10. Harf frekansı ve sayaç dizisi

Son örnek: bir metindeki harflerin geçme sayılarını saymak. Problemi basitleştirmek için metin İngilizce ve tümü küçük harftir (26 harf, büyük-küçük harf dönüşümüyle uğraşılmıyor) (ekrandan, 02:25:00):

```text
hello friends what are you doing
```

Bir öğrenci sayaç (counter) dizisi kullanmayı önerdi; dizinin boyutu harf sayısı kadar, 26 olmalıdır. Dizinin 0. gözü `a`'nın, 1. gözü `b`'nin, ..., 25. gözü `z`'nin sayısını tutar. Boşluk da sayılmak istenirse bir göz daha eklenir. Bütün gözler başta sıfırlanmalıdır.

Algoritma adımları (ekrandan, 02:25:00):

1. Diziyi oku (bölüm 9.1'deki gibi, `gets` ile).
2. Dizinin uzunluğunu bul (null karakter görene kadar sayarak, bölüm 9.2).
3. Bir döngü içinde karakter karakter, sayaç dizisinin ilgili gözünü 1 artır.
4. Sayaç dizisini yazdır (bir döngü içinde, `i = 1`'den 26'ya ya da 27'ye kadar `counter[i]`).

3. adımın kilit noktası, karakterin indise nasıl çevrileceğidir. Okunan karakter `'b'` ise `'b' - 'a'` = 98 - 97 = 1 olur, yani `b`'nin gözü. `'a'` için `'a' - 'a'` = 0. Akış diyagramında bu adım şöyle yazıldı:

```text
counter['b' - 'a'] = counter['b' - 'a'] + 1
```

C kodunda `'b'` yerine o anda incelenen karakter, yani `s[i]` gelir (ekrandan, 02:30:00):

```c
counter[s[i]-'a']++;
```

Boşluğun kodu 32 olduğu için ona ayrı bir kontrol gerekebilir. Örnek metinde `h` gözü 1, `e` gözü 1, `l` gözü 2, `o` gözü 1, `f` gözü 1 artar ve bu şekilde devam eder.

**Soru:** Bir kez okunan harf bir daha okunmuyor mu? **Cevap:** Okunuyor; "hello"da iki tane `l` geçer ve `l`'nin gözü iki kez artar. Yazdırınca `h` 1, `e` 1, `l` 2, `o` 1 olmalıdır.

**Soru:** 3. adımdaki `counter['b'-'a']` artırmasında tam olarak ne yapılıyor? **Cevap:** Dersin başındaki `'a' + 1` örneğinde olduğu gibi karakterler arka planda sayıdır. `'b' - 'a'` aslında 98 - 97 = 1'dir, yani sayaç dizisinin 1. gözüne erişilir. `'a'` okunursa 0. göze gidilir ve o göz 1 artırılır.

Hoca sayaç dizisi kullanmanın pek çok problemde işe yarayan bir çözüm yöntemi olduğunu söyledi. Bu örneğin kodu derste yazılmadı; öğrencilerin kendilerinin yazması istendi. Akış diyagramının her adımını ayrı çizmek de ödev niteliğinde bırakıldı.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): `10, -20, 40, -10, 90, 50, 30, 45, 60` dizisinde 6. indise kullanıcının verdiği `X = 55` değerini ekleyen algoritmanın akış diyagramını çizin ve C koduna dönüştürün.

> **Çözüm (derste verildi):** `N = N+1`; `for (i=N; i>pos; i--) a[i] = a[i-1];` ardından `a[pos] = x;`. Çıktı `10 -20 40 -10 90 50 55 30 45 60`. Dizi en az `N+1` gözlü açılmalıdır (bkz. bölüm 1.3'teki ders sonrası not).

**Soru 2** (derste sözlü, 00:31:34): Pozisyon yerine bir değer (örneğin 50) verilirse ve yeni eleman o değerden sonraki göze eklenmek istenirse algoritmada ne değişir?

> **Çözüm (derste verildi):** Önce `f = -1` ile dizide değer aranır, bulunursa `f = i` yapılır. `f >= 0` ise `Pos = f+1`, değilse `Pos = N` (sona ekleme). Sonra aynı kaydırma ve atama yapılır. Örnekte 50 indis 5'tedir, yeni eleman 6. indise girer.

**Soru 3** (ekrandan, 00:40:00): Eleman değerleri 100'den küçük olan `a = 20, 30, 1, 20, 40, 9` dizisinin en küçük iki elemanını, diziyi sıralamadan ve üzerinden yalnızca bir kez geçerek bulun.

> **Çözüm (derste verildi):** `m1 = m2 = 1000`; her eleman için `a[i] < m1` ise `m2 = m1; m1 = a[i];`, değilse `a[i] < m2 && a[i] != m1` ise `m2 = a[i];`. Sonuç `m1 = 1`, `m2 = 9`. Döngüden sonra `m2` hâlâ 1000 ise ikinci küçük eleman yoktur.

**Soru 4** (ekrandan, 01:20:00): Aşağıdaki programın çıktısı nedir?

```c
char ch;
ch = 'a';
printf("%c %d", ch, ch);
ch = 'a'+1;
printf("%c %d", ch, ch);
```

> **Çözüm (derste verildi):** `a 97` ve `b 98`. `'a'` ASCII 97'dir; `'a'+1` = 98 = `'b'`.

**Soru 5** (derste sözlü, 01:37:42): `char t[] = {'t','e','k','n','i','k'};` (null karakter konmadan) `printf("%s", t)` ile yazdırılırsa ne olur?

> **Çözüm (derste verildi):** "teknik" yazdırılır, ardından bellekte dizinin arkasından gelen içerik ilk `'\0'` görülene kadar yazdırılmaya devam eder. Derste önceki çalıştırmalardan kalan "yildiz" de çıktıya eklendi.

**Soru 6** (derste sözlü, 02:07:24): Bir karakter dizisini tersine çeviren programı yazın.

> **Çözüm (derste verildi):** Önce uzunluk `n` bulunur; `j = 0`'dan `n/2`'ye kadar `s[j]` ile `s[n-j-1]` bir `temp` değişkeni yardımıyla yer değiştirir. `merhaba` → `abahrem`.

**Soru 7** (ekrandan, 02:25:00): `hello friends what are you doing` gibi küçük İngilizce harflerden oluşan bir metindeki harflerin geçme sayılarını bulun.

> **Çözüm (derste verilmedi):** Derste yalnızca algoritma adımları ve `counter[s[i]-'a']++` ifadesi verildi. Aşağıdaki kod ajan tarafından yazıldı, `gcc -Wall` ile derlenip örnek metinle çalıştırıldı:
>
> ```c
> #include <stdio.h>
> #include <string.h>
> int main(){
>     char s[100];
>     int counter[27] = {0};   /* 26 harf + boşluk */
>     int i, n = 0;
>     fgets(s, sizeof s, stdin);
>     s[strcspn(s, "\n")] = '\0';
>     while (s[n] != '\0') n++;
>     for (i = 0; i < n; i++){
>         if (s[i] == ' ') counter[26]++;
>         else if (s[i] >= 'a' && s[i] <= 'z') counter[s[i]-'a']++;
>     }
>     for (i = 0; i < 26; i++)
>         if (counter[i] > 0) printf("%c: %d\n", 'a'+i, counter[i]);
>     printf("bosluk: %d\n", counter[26]);
>     return 0;
> }
> ```
>
> Örnek metin için sonuç: a 2, d 2, e 3, f 1, g 1, h 2, i 2, l 2, n 2, o 3, r 2, s 1, t 1, u 1, w 1, y 1; boşluk 5.

## Dersin Toparlaması

Dersin ilk yarısında dizi algoritmalarına farklı bakış açıları kazandıran üç alıştırma yapıldı: belirli bir indise eleman ekleme (sondan başa kaydırma), belirli bir değerden sonraya ekleme (önce arama, sonra ekleme) ve dizinin üzerinden tek geçişte en küçük iki elemanı bulma. Bu sırada `#define` ile sabit tanımlama, global ve yerel değişken farkı ve dizilere ilk değer atama da görüldü.

Aradan sonra karakter sabitleri ve karakter dizileri işlendi: `char` aslında ASCII kodunu tutan 8 bitlik bir sayıdır ve üzerinde aritmetik yapılabilir; ters bölüyle başlayan önceden tanımlı karakterler ekranda gösterilemeyen özel karakterleri temsil eder ve karakterler onaltılık ya da sekizlik kodla da yazılabilir. Karakter dizileri null karakterle sonlanır: tek tek verilen karakterlerde bunu programcı, çift tırnaklı sabitlerde derleyici, `gets` ile okumada fonksiyon koyar. `gets` ve `puts`, uzunluk bulma, ters çevirme ve sayaç dizisiyle harf frekansı örnekleri bu bilgileri birleştirdi. Hoca bir sonraki derste çok boyutlu dizilerin işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
