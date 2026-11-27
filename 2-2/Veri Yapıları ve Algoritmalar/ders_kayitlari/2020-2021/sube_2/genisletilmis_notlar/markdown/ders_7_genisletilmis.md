# Ders 7 Genişletilmiş Notu: Diziler, Linkli Listeler ve Josephus Problemi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Başlangıç Sorusu: Asimptotik Gösterimde Baskın Terim
- 2. Diziler Üzerine Kısa Bir Tekrar
- 3. Dizilerin Kısıtları ve Linkli Listelere Geçiş
- 4. Linkli Liste Kavramı
- 5. Linkli Listelerde Temel İşlemler ve C'de Tanım
- 6. Linkli Listeye Eleman Eklemek
- 7. Dizi ile Sıralı Linkli Liste: Ekleme
- 8. Ekleme Fonksiyonlarının Kodları
- 9. Linkli Listeden Eleman Silmek
- 10. Dizi ile Sıralı Linkli Liste: Silme
- 11. Linkli Liste ile Insertion Sort
- 12. Çift Linkli Liste
- 13. Dairesel Linkli Liste ve Josephus Problemi
- 14. Dairesel Çift Linkli Liste ve Diğer Varyantlar
- 15. Diziler mi, Linkli Listeler mi?

## 1. Başlangıç Sorusu: Asimptotik Gösterimde Baskın Terim

Dersin başında bir öğrenci, internette çözdüğü bir örnekte karmaşıklığı $n \cdot 2^n$ olarak yazdığında bunun yanlış sayıldığını, açıklamada $n$'in $2^n$ yanında önemsiz olduğu için yalnız $2^n$ yazılması gerektiğinin söylendiğini anlattı. $n \log n$ yazarken $n$'i atmadığımızı hatırlatıp bu derste hangi yaklaşımın kullanıldığını sordu.

**Soru:** $n \cdot 2^n$ karmaşıklık $2^n$ diye mi yazılmalı? **Cevap:** Hoca normalde katsayıların atıldığını, ama kendisinin $n \cdot 2^n$ yazmayı ve bunu açıkça belirtmeyi tercih edeceğini söyledi. $2^n$ önceki hafta konuşulduğu gibi "ölümcül" bir büyüme fonksiyonudur; onu bir de $n$ ile çarpmak büyüme açısından sezgisel olarak çok şey değiştirmez. Buna karşılık $\log n$'i $n$ ile çarpınca anlamlı bir fark oluşur; eğriler çizdirildiğinde bu açıkça görülür. Hocaya göre o kaynak, "mertebe zaten $2^n$, $n$ ile ya da bir sabitle çarpmanın önemi yok" yaklaşımıyla bunu söylemiş olabilir. Hoca ayrıca $5 \cdot 2^n + n^3$ gibi bir yazımın yanlış olacağını vurguladı: geçen hafta söylendiği gibi en yüksek mertebeli terim kalmalı, katsayılar atılmalıdır.

> **Ders sonrası not:** Biçimsel olarak $n \cdot 2^n \notin O(2^n)$'dir, çünkü $\frac{n \cdot 2^n}{2^n} = n$ sınırsız büyür. Bu yüzden sıkı bir üst sınır olarak $n \cdot 2^n$ yazmak doğrudur; hocanın bunu açıkça belirtmeyi tercih etmesi bu bakımdan yerindedir. "Yalnız $2^n$ yazılır" açıklaması büyük olasılıkla kaba bir sınıflandırmayı (üstel büyüme) kastediyordu.

Hoca ardından son kısa sınavdaki (quiz) problemin çözüm yaklaşımları üzerine kısa bir yorum yaptı. Problemde her rengin kaç kez geçtiğini (histogram) bulmak gerekiyordu. Bu iki şekilde yapılabilir: renk sayaçlarını bir yedek dizide tutmak (örneğin 256 gözlü statik bir dizi ya da sürekli yeniden ayırma (reallocation) gerektiren dinamik bir dizi) ya da hiç ek alan kullanmadan sürekli arama yaparak saymak. Statik dizide yer, dinamik dizide işlem nedeniyle zaman kaybedilir. Problemde sınırlı belleği olan gömülü bir sistemden ve tekil renk sayısının toplam $K$'dan çok daha az (yaklaşık $K/3$) olduğundan söz edildiği için beklenen çözüm ek dizi kullanmayan çözümdü. Yedek dizi kullanan çözümler yanlış değildi, ama beklenen çözüm değildi. <!-- BELİRSİZ: quiz sorusunun tam metni kayıtta okunmadı; yalnız hocanın yorumundan aktarıldı. -->

## 2. Diziler Üzerine Kısa Bir Tekrar

Bu haftanın konusu bağlı ya da linkli listelerdir. Algoritmik düşünce, algoritma tasarlama ve algoritma analizi ilk haftalarda bitirilmişti; bu hafta ilk veri yapısı olan ve sonraki pek çok veri yapısında da kullanılacak linkli listeler ele alınır. Hoca, linkli listelere geçmeden önce dizi (array) bilgisini tazelemek istedi.

### 2.1 Dizi Nedir, Nerede Kullanılır?

Dizi, aynı türden verileri bir öbek halinde bir arada tutan veri yapısıdır ve indisle erişim sağlar. Vektör tipinde veri yapıları, matrisler, görselleştirilmesi gerekmeyen dört-beş boyutlu diziler, listeler, yığıt (stack), kuyruk (queue) ve karakter dizileri (string) gibi pek çok yapının temelinde dizi vardır. Bu derste linkli listenin bir gerçekleştirmesi de dizi kullanılarak gösterilecektir, çünkü akış diyagramında çizmesi ve anlatması daha kolaydır.

### 2.2 İndisleme Yaklaşımları

Genelde üç indisleme yaklaşımı vardır:

- **0 tabanlı indisleme:** C'de kullanılır. İlk elemanın indisi 0'dır. $n$ eleman varsa döngü $n-1$'e kadar, yani `i < n` koşuluyla kurulur.
- **1 tabanlı indisleme:** Pascal, Basic gibi dillerde görülür. Dizi birinci gözden başlar; döngü sınırı `i <= n` (ya da `i < n+1`) olur. Hoca Fortran'da da böyle olduğunu sandığını ama emin olmadığını söyledi.
- **n tabanlı indisleme:** Örneğin Python'da indisler 0'dan başlayabildiği gibi negatif de olabilir. $-5$ indisi, dizinin sondan beşinci elemanı demektir. Bazı dillerde numaralandırma (enumeration; A, B, C, D ya da alfa, gama gibi adlar) ya da karakter indisleri de kullanılabilir.

> **Ek bilgi (derste anlatılmadı):** Fortran'da diziler varsayılan olarak 1'den başlar, ama alt sınır tanımda başka bir değer olarak da verilebilir.

Bu derste C kullanıldığı için 0 tabanlı indisleme ile devam edilir: elemanlar $a[0], a[1], a[2], \ldots, a[n-1]$ şeklindedir ve $i$. elemana $a[i]$ ile erişilir (ekrandan, 00:20:00).

### 2.3 C'de Dizilerle Çalışmanın Sorumlulukları

Slayttaki üç madde şöyledir (ekrandan, 00:20:00):

- `a[i]`'ye başvurmadan önce bu göze anlamlı bir değer atamak sizin sorumluluğunuzdur.
- Pozitif ve dizi boyutundan küçük indisler kullanmak sizin sorumluluğunuzdur.
- Hafızaya doğrudan erişiminiz vardır, tüm belleği bir dizi olarak düşünebilirsiniz.

İlk değer atanmazsa, bellekte o gözün adresinde ne varsa o kullanılır. İndis kontrolü yapılmazsa (örneğin $n$ elemanlı dizide $5n$. göze erişmek) derleyiciye bağlı olarak hata alınmadan yola devam edilebilir, ama olmaması gereken bir değer okunur ya da yazılır. Diğer dillerdeki "array index out of bounds" hatası C'de kendiliğinden yakalanmaz. Dinamik ayrılan bellek işi bitince temizlenmelidir; temizlenmezse program bitene kadar kullanılmayan alan boşuna işgal edilir.

### 2.4 Statik ve Dinamik Dizi Tanımı

Statik tanımda önce tip, sonra dizinin adı ve boyutu yazılır: `int a[10];` 0'dan 9'a kadar adreslenebilen gözleri olan statik bir dizi oluşturur. String'ler için karakter dizileri kullanılır: hocanın örneğinde `b` dizisi "dizi" kelimesini tutar ve 0, 1, 2, 3. gözlerinde `d`, `i`, `z`, `i` karakterleri bulunur.

Dinamik dizide işaretçi mantığıyla çalışılır. Dizinin ilk elemanının işaretçisini bilmek yeterlidir. Örneğin `c` adlı bir tamsayı işaretçisi için `malloc` ile gereken sayıda (örneğin 5 ya da 10) tamsayılık yer ayrılır, tip dönüşümüyle (cast) tamsayı işaretçisi olarak `c`'ye atanır. Sonra `c[0]`, `c[1]`, ..., `c[4]` şeklinde erişilebilir.

## 3. Dizilerin Kısıtları ve Linkli Listelere Geçiş

Slayttaki kısıtlar şunlardır (ekrandan, 00:25:00):

- Dinamik boyutlu değilse, eleman ekleyemeyiz.
- Dinamik boyutlu olduğunda araya bir eleman eklemek maliyetlidir; aradan bir eleman silmek maliyetlidir.
- Çözüm? Linkli listeler.

Araya eleman eklemek için sonda yeni bir göz açılır, oraya kadar olan elemanlar birer birer kaydırılır ve eleman araya yazılır. Ortalamada yaklaşık $n/2$ kaydırma gerekir, en başa eklemede ise $n$ kaydırma. İlk eleman silinince de hepsi birer göz geri kaydırılır. Bu işlemler algoritmada sık kullanılıyorsa her seferinde en kötü durumda $O(n)$ maliyet gelir. Hocanın sorusu şudur: Araya ya da başa eleman eklemek gibi işlemleri sabit sayıda işlemle, $O(1)$ zamanda yapmak mümkün müdür? Bu sorunun cevabı linkli (Türkçesiyle bağlantılı) listelerdir. Derste İngilizceye yakın olduğu için "linked list" adı kullanılır.

## 4. Linkli Liste Kavramı

### 4.1 Tanım ve Temel Özellikler

Linkli liste, çalışma sırasında boyutu ya da şekli değiştirilebilen bir veri yapısıdır. Temel özellikleri:

- Ardışık elemanlar birbirine işaretçilerle (pointer) bağlanır. Bir eleman bir yapı (veri) tutar; aynı türden bir sonraki veri, yalnız onun adresi gösterilerek bağlanır.
- İşaretçi kullanıldığı için dinamik olarak boyutlandırılır, istenen boyutta oluşturulabilir ve gereksiz bellek kaplamaz. Örneğin 256 renkten her birinin kaç kez geçtiği sayılacaksa 256 gözlü statik bir alana gerek yoktur; yalnız 3 tekil renk varsa 3 düğüm yeterlidir.
- Düğümler (node) hızlı ve düşük karmaşıklıkla yeniden düzenlenebilir: araya düğüm eklemek, aradan düğüm silmek, listeyi ters çevirmek gibi.
- Yalnız ilk düğümün işaretçisini bilmek yeterlidir; herkes bir sonrakini gösterdiği için bir sonraki, bir sonraki diye gidilerek liste üzerinde gezinti kurulabilir.

Hoca bunu, sınıftaki herkesin kendinden sonra gelen kişiyi parmakla gösterdiği bir zincire benzetti: "Benden sonra Ayşe geliyor, Ayşe'den sonra Mehmet, Mehmet'ten sonra Fatma."

### 4.2 Dairesel Listeye İlk Bakış

Linkli listenin birkaç özel hali vardır, bunlar derste tek tek görülecektir. Biri dairesel linkli listedir (circular linked list): son eleman ilk elemanı gösterirse (zincirdeki son kişi yeniden ilk kişiyi gösterirse) kapalı bir çevrim oluşur.

**Soru:** Normalde listenin sonuna `NULL` görene kadar ilerliyorduk. Dairesel listede sona geldiğimizi nasıl anlarız; eleman sayısını da sonu da bilmiyorsak arama yapamaz mıyız? **Cevap:** Eleman sayısı tutulup bir sayaçla hepsi gezildiyse ve aranan bulunamadıysa durulabilir. Hoca ayrıntıyı dairesel listeye gelindiğinde konuşmayı önerdi. (Orada `head`'e geri dönüldüğünün kontrol edileceği gösterildi; bkz. Bölüm 13.)

### 4.3 Düğüm Gösterimi ve `head`

Her düğümün bir veri bölümü vardır; buraya bir `struct` konup istenen her tür veri tutulabilir. Düğümün tek özel noktası, bir sonrakini gösteren `next` işaretçisidir. A düğümünün `next`'i B'nin bellekteki adresini, B'ninki C'yi gösterir; C'nin `next`'i `NULL`'dır. Bu, listenin sonuna gelindiği, C'nin son düğüm olduğu anlamına gelir (ekrandan, 00:45:00).

Listeye erişmek için ek bir işaretçiye, listenin başlangıç adresine ihtiyaç vardır. Buna genellikle `head` denir. Diğer düğümlerin adreslerini ayrıca tutmaya gerek yoktur. `head` ile ilk düğüme, `next` ile sırayla sonrakilere gidilir; `next`'te `NULL` bulunca sona gelinmiş olur.

### 4.4 Soyut Veri Tipi

Linkli liste bir soyut veri tipidir (abstract data type). İçinde ne tutulacağını tamamen kullanıcı tanımlar: tamsayı, ondalıklı sayı ya da karmaşık türleri barındıran `struct`'lar olabilir. "Soyut" denmesinin nedeni, kullanırken gerçekleştirme ayrıntılarıyla ilgilenilmemesidir. Hoca, linkli liste işlemlerinin bir kütüphane ya da başlık (header) dosyası olarak yazılmasını tavsiye etti. Böylece örneğin `insert_node` gibi bir fonksiyon çağrılır; araya yer bulma, bağlantıları değiştirme gibi ayrıntılar soyutlanmış olur. Bunun bir adım ötesi C++, Java ya da C# gibi dillerde veri alanlarını ve davranışları birlikte paketlemektir; buna sınıf (class) denir. Sınıf da bir soyutlamadır.

## 5. Linkli Listelerde Temel İşlemler ve C'de Tanım

### 5.1 Temel İşlemler

Slayttaki liste şöyledir (ekrandan, 00:35:00):

- Liste yaratmak
- Listeyi gezmek
- Listeye eleman eklemek: başa, araya, sona
- Listeden eleman silmek: baştan, aradan, sondan
- İki listeyi birleştirmek (sıralı?)
- Liste boyutunu bulmak
- Listeyi tersine çevirmek
- Listede eleman aramak

Liste yaratmak en kolayıdır: hiç düğüm yokken liste yalnız `head` ile tanımlanır, `head = NULL` demek teorik olarak boş bir liste yaratmaktır. Araya eklemek için bir değere ihtiyaç vardır: belirli bir düğümden önceye ya da sonraya ekleme yapılır. Sona eklemede `next`'i `NULL` olan düğümün arkasına yeni düğüm eklenir ve onun `next`'i `NULL` yapılır. Silmede baş, ara ve son için farklı davranmak gerekebilir ya da hepsi tek fonksiyonda toplanabilir.

İki sıralı listeyi sıralı olarak birleştirmek doğrusal zamanda yapılabilir: yalnız değer karşılaştırmalarıyla bir ondan, bir bundan diye bağlantılar yeniden kurulur. Eleman sayısını bulmak için `NULL` görene kadar gezilir. Eleman aramak da gezmekten farklı değildir. Listeyi ters çevirme, hocanın deyişiyle bir `while` içinde birkaç satırla yapılabilir; hoca bunu anlatmadı, alıştırma olarak bıraktı (çözüm Örnek Sorular bölümündedir).

### 5.2 C'de Düğüm Tanımı

Java gibi bazı dillerde linkli liste hazır tanımlıdır, ama C'de kendimiz oluşturmalıyız. Slayttaki iki eşdeğer tanım şöyledir (ekrandan, 00:40:00):

```c
typedef struct node *link;
struct node { [type] data; link next;};
```

veya

```c
typedef struct link {
    [type] data;
    struct link *next;
} node;
```

Yeni bir düğüm yaratıp listeye eklemek için:

```c
link x = (node *)malloc (sizeof *x);
```

Birinci tanımda `link`, `struct node` işaretçisi tipinin adıdır; `struct node` içinde veri ve `link` tipinde `next` vardır. Derste basitlik için veri olarak tek bir tamsayı kullanılır. İkinci tanımda tip tanımı ve struct tanımı birlikte yapılır: struct'ın adı `link`, tipin adı `node`'dur; bu durumda `next` de `struct link *` tipinde olmalıdır. Hoca kendi kullanımında ikinci gösterimi daha çok tercih ettiğini söyledi.

### 5.3 Liste Üzerinde Gezinti

Gezinti için `node` tipinde bir `t` işaretçisi kullanılır: `head`'den başlanır, `t` `NULL` olmadığı sürece her adımda `t = t->next` yapılır ve her adımda `t->data` kullanılır (derste bu, `use(t->data)` gibi bir fonksiyonla gösterildi). `t` bir işaretçi olduğu için struct alanlarına `.` ile değil `->` ile erişilir. İki adımda bir gezmek için `t->next->next` kullanılabilir. Bir sayaçla `i = 0`'dan $n$'e kadar dönüp her adımda `t = t->next` yapmak da mümkündür, ama işaretçiyle gezmek genellikle daha rahattır.

```c
for (t = head; t != NULL; t = t->next)
    use(t->data);
```

<!-- BELİRSİZ: gezinti döngüsünün slayttaki birebir yazımı karelerde yok; yukarıdaki satırlar hocanın anlatımından kuruldu. -->

## 6. Linkli Listeye Eleman Eklemek

A, B, C düğümlerinden oluşan bir listeye X düğümü B'den önceye (yani A'dan sonraya) eklenecek olsun (ekrandan, 00:45:00). İlk akla gelen, A'nın `next`'ini hemen X'e bağlamaktır. Ama bu yapılırsa A'nın B'yi gösteren bağlantısı kaybolur; B'ye ve dolayısıyla C'ye artık erişilemez, listenin geri kalanı sahipsiz kalır.

Doğru sıra şudur:

- Yeni bir düğüm yaratılır, verisine X yazılır; yeni düğüm `tmp` işaretçisiyle gösterilir.
- Önce yeni düğümün `next`'i A'nın `next`'ine (yani B'ye) bağlanır.
- Sonra A'nın (`curr`) `next`'i yeni düğüme bağlanır.

Slayttaki kod:

```c
x->next = a->next; a->next = x;
```

Sonuçta A, B, C listesi A, X, B, C olarak dört elemana çıkar. Bu işlem "B'den önceye ekle" (insert before B) ya da "A'dan sonraya ekle" (insert after A) olarak düşünülebilir.

## 7. Dizi ile Sıralı Linkli Liste: Ekleme

### 7.1 Gösterim

Akışta anlatma kolaylığı için hoca linkli listeyi iki diziyle gösterdi: değerleri tutan `a` dizisi ve her elemanın ardından gelen elemanın indisini tutan `link` dizisi. Liste `head` indisinden başlar, `-1` son demektir (`NULL` gibi). Bu, statik bir yapıdır ama sıralı bir linkli listeyi anlatmak için uygundur.

Slayttaki ilk örnek: `a = {4, 7, 1, 2}`, `head: 2`, `link{1, -1, 3, 0}` (ekrandan, 00:50:00). Gezinti şöyledir:

- `head = 2`: `a[2] = 1`; `link[2] = 3`.
- `a[3] = 2`; `link[3] = 0`.
- `a[0] = 4`; `link[0] = 1`.
- `a[1] = 7`; `link[1] = -1`, liste bitti.

Sonuç 1, 2, 4, 7'dir. Değer dizisi 4, 7, 1, 2 diye sırasız dursa bile bağlantı dizisi sayesinde sıralı bir liste tutulmuş olur. (Hoca tahtada önce yanlışlıkla başlangıcı 3 diye düzeltmeye çalıştı, sonra yeniden yazarak doğru başlangıcın 2 olduğunu gösterdi.)

### 7.2 Ekleme Akışı

Akış diyagramının adımları (ekrandan, 00:50:00):

```text
START
Oku: n, a[n], head, link[n], ekle
a[n] <- ekle ; n <- n+1
a[head] < ekle ?
  F: link[n-1] <- head ; head <- n-1               (yeni eleman başa geçer)
  T: prev <- head ; next <- link[head]
     next != -1 && a[next] < ekle olduğu sürece:
         prev <- next ; next <- link[next]
     link[prev] <- n-1 ; link[n-1] <- next
STOP
```

Yeni eleman her zaman dizinin sonuna yazılır ve $n$ bir artırılır. Eklenen değer ilk elemandan küçükse (`a[head] < ekle` yanlışsa) `head` değişmelidir: yeni elemanın bağlantısı eski `head` olur, yeni `head` de son indis ($n-1$) olur. Değilse araya ya da sona ekleme vardır ve yer aranır. Bunun için iki işaretçi gerekir: önceki düğüm (`prev`) ve sonraki düğüm (`next`). A ile B'nin arasına X sokulurken ikisinin de adresi biliniyordu; burada da durum aynıdır. Döngü, `next` `-1` olmadığı ve `a[next]` eklenecek değerden küçük olduğu sürece `prev` ve `next`'i birer adım kaydırır. Döngüden çıkınca `link[prev]` yeni elemanı, yeni elemanın bağlantısı da `next`'i gösterir.

### 7.3 Sözlü Örnek: 0 ve 9 Eklemek

Hoca aynı dizi üzerinde iki ekleme yaptı (ekrandan, 00:55:00):

- **0 eklemek:** `a = {4, 7, 1, 2, 0}`, $n = 5$. `a[head] = 1 < 0` yanlış, yani yeni eleman başa geçer: `link[4] = 2` (eski `head`), `head = 4`. Gezinti: 0, 1, 2, 4, 7.
- **9 eklemek:** `a = {4, 7, 1, 2, 0, 9}`, $n = 6$. `a[head] = 0 < 9`, yer aranır: `prev = 4`, `next = 2`; sonra 2 → 3 → 0 → 1 diye ilerlenir; `link[1] = -1` olunca döngü biter. `link[1] = 5`, `link[5] = -1` yapılır. Gezinti: 0, 1, 2, 4, 7, 9.

Döngü en fazla $n$ kez döner; dolayısıyla bu ekleme işlemi $O(n)$, doğrusal zamanlıdır.

### 7.4 Slayttaki Örnek

Başlangıç: `a: 2 4 6 8`, `L: 1 2 3 -1`, $n = 4$, `head: 0` (ekrandan, 01:00:00). Bu liste zaten sıralıdır: 2 → 4 → 6 → 8 → bitti.

**1 eklemek:** `a: 2 4 6 8 1`, $n = 5$. `a[head] = 2`, $2 < 1$ yanlış; yeni eleman başa geçer. `L[4] = head = 0`, `head = n-1 = 4`. Sonuç: `L: 1 2 3 -1 0`, `head: 4`.

**5 eklemek:** `a: 2 4 6 8 1 5`, $n = 6$. Adımlar:

| Adım | `prev` | `next` | `a[next]` | Karşılaştırma |
|---|---|---|---|---|
| Başlangıç | 4 | 0 | 2 | $2 < 5$, devam |
| 1 | 0 | 1 | 4 | $4 < 5$, devam |
| 2 | 1 | 2 | 6 | $6 < 5$ yanlış, dur |

Döngüden sonra `L[prev] = L[1] = 5` ve `L[5] = next = 2` yapılır. Sonuç: `L: 1 5 3 -1 0 2`, `head: 4`.

Gezinti: `head = 4` → 1; `L[4] = 0` → 2; `L[0] = 1` → 4; `L[1] = 5` → 5; `L[5] = 2` → 6; `L[2] = 3` → 8; `L[3] = -1`, bitti. Liste 1, 2, 4, 5, 6, 8 olarak gezilir. Bu sonuçlar python ile kontrol edildi.

Hoca, `link` dizisinin derste yalnız akışta anlatım ve gerçekleştirme kolaylığı için kullanıldığını, işaretçilerle yazıldığında bu değerlerin düğümlerin `next` alanları olacağını hatırlattı.

## 8. Ekleme Fonksiyonlarının Kodları

### 8.1 Başa Eleman Eklemek: `insert_top`

Araya ve başa ekleme tek bir fonksiyonda birleştirilebilir, ama hoca anlaşılır olsun diye iki ayrı fonksiyon gösterdi. Başa ekleme kodu (ekrandan, 01:20:00):

```c
typedef struct link {
  int data;
  struct link *next;
} Node;

Node * insert_top(int num, Node *head) {
  Node *new_node;
  new_node = (Node *) malloc(sizeof(Node));
  new_node->data = num;
  new_node->next= head;
  head = new_node;
  return head;
}
```

Fonksiyon eklenecek değeri (`num`) ve listenin başını (`head`) alır, yeni `head`'i döndürür. Önce yeni bir düğüm yaratılır; basitlik için `malloc`'un başarılı olduğu varsayılır, gerçek kodda kontrol edilmelidir. Yeni düğümün verisi atanır. Sonra yine "önce yeninin bağlantısı" kuralıyla yeni düğümün `next`'i eski `head` yapılır, ardından `head` yeni düğümü gösterir. A, X, B örneğinde X'in A'nın da önüne eklendiğini düşünmek yeterlidir.

Bu fonksiyon, ajan tarafından bir `main` ve listeyi yazdıran bir fonksiyonla birlikte `gcc -Wall` ile derlenip çalıştırıldı: 4, 3, 2, 1 sırayla başa eklenince liste 1 2 3 4 oldu.

### 8.2 Araya Eleman Eklemek: `insert_before`

`insert_before` fonksiyonu eklenecek değeri, hangi değerden önceye ekleneceğini ve `head`'i alır. Bir `current` işaretçisi `head`'den başlar. `current->next->data` aranan değere eşit olmadığı sürece `current = current->next` ile ilerlenir. Eşitlik bulununca bir sonraki düğümün önüne ekleme yapılacağı anlaşılır: yeni düğüm yaratılır, verisi atanır, önce `new_node->next = current->next`, sonra `current->next = new_node` yapılır. Fonksiyon listeye baştan erişilebilsin diye yine `head`'i döndürür.

> **Hocanın vurgusu:** Bu kod ilk eleman eklemesinde çalışmaz, çünkü `head`'in kendi verisi değil, `head->next`'in verisi karşılaştırılır. İlk eleman eklemesi için `insert_top` ayrıca yazıldı. Sınır kontrolü (sona ekleme, `NULL` kontrolü) de yoktur; bunu da kontrol etmekte fayda vardır.

<!-- BELİRSİZ: insert_before slaytının birebir kodu karelerde yok; yukarıdaki açıklama hocanın anlatımından kuruldu. -->

Hoca kendisinin `insert_top`, `insert_bottom`, `insert_before` ve `insert_after` olarak dört ayrı ekleme fonksiyonu yazdığını, sona eklemede `NULL` kontrolünü yaptığını söyledi. Bunları tek bir ekleme fonksiyonunda birleştirmeyi el alışkanlığı için alıştırma olarak bıraktı.

## 9. Linkli Listeden Eleman Silmek

Silmede de dikkat edilecek tek nokta listenin geri kalanını, yani bağlantıları kaybetmemektir. A, B, C listesinden B silinecek olsun (ekrandan, 01:30:00). `curr` A'yı gösterir; A'nın `next`'i C'ye bağlanmalıdır.

```c
a->next = a->next->next;
daha iyisi: b = a->next; a->next = b->next; free(b);
```

İlk satır listeyi doğru günceller ve çalışır. Ama B düğümü bellekte boş boş durmaya devam eder (sahipsiz, "dangling" kalır). Program bitince bu alan zaten bırakılır, ama program boyunca gereksiz yere bellek işgal edilir; bellek kısıtlı sistemlerde buna dikkat edilmelidir. Bu yüzden önce silinecek düğüm geçici bir işaretçiyle (`b` ya da `tmp`) tutulur, sonra bağlantı atlanır, en son `free(b)` ile bellek işletim sistemine geri verilir.

## 10. Dizi ile Sıralı Linkli Liste: Silme

### 10.1 Silme Akışı

Akış diyagramının adımları (ekrandan, 01:35:00):

```text
START
Oku: n, a[n], head, link[n], sil
sil = a[head] ?
  T: head <- link[head]
  F: prev <- head ; adr <- link[head]
     adr != -1 && a[adr] < sil olduğu sürece:
         prev <- adr ; adr <- link[adr]
     adr = -1 || a[adr] > sil ?
       T: "Eleman yok" yaz
       F: link[prev] <- link[adr]
STOP
```

Önce silinecek elemanın ilk eleman olup olmadığına bakılır; öyleyse `head` bir sonraki elemanı gösterir ve iş biter. Değilse `prev` ve `adr` işaretçileriyle tarama yapılır. Döngüden iki nedenle çıkılmış olabilir: ya sona gelinmiştir ya da bakılan değer silinecek değerden büyüktür. İkisinde de eleman listede yoktur ve silme yapılmaz. Bu iki koşul da yanlışsa aranan eleman bulunmuştur; `link[prev] ← link[adr]` ile o eleman atlanır (bypass). Dizide eleman silinmez, ama `link` dizisi üzerinden artık erişilemez.

### 10.2 Slayttaki Örnek

Başlangıç: `a: 2 3 4 6 7 8`, `L: 1 2 3 4 5 -1`, $n = 6$, `head: 0` (ekrandan, 01:35:00).

**2'yi silmek:** `sil = a[head] = 2`, ilk eleman. `head = L[0] = 1`. Artık birinci gözden başlanır: 3, 4, 6, 7, 8. Değer 2 dizide durur, ama ona erişilemez.

**6'yı silmek:**

| Adım | `prev` | `adr` | `a[adr]` | Karşılaştırma |
|---|---|---|---|---|
| Başlangıç | 1 | 2 | 4 | $4 < 6$, devam |
| 1 | 2 | 3 | 6 | $6 < 6$ yanlış, dur |

`adr ≠ -1` ve `a[adr] = 6`, 6'dan büyük değil; eleman bulundu. `L[prev] = L[2] = L[adr] = L[3] = 4` yapılır. Yeni bağlantı dizisi: `L: 1 2 4 4 5 -1`, `head: 1`.

Gezinti: 1. göz → 3; `L[1] = 2` → 4; `L[2] = 4` (eskiden 3'tü) → 7; `L[4] = 5` → 8; `L[5] = -1`, bitti. Sonuç 3, 4, 7, 8'dir. 2 ve 6 dizide durur ama bağlantıları koptuğu için erişilemez. Bu sonuçlar python ile kontrol edildi.

Hoca, bu ekleme ve silme işlemlerinin sıralı linkli liste için olduğunu hatırlattı. Liste sıralı değilse elemanlara tek tek bakılır; bulunursa çıkılır, sona kadar gidilip bulunamazsa eleman yoktur.

### 10.3 Silme Fonksiyonu

İşaretçilerle yazılan silme fonksiyonu yine `head`'i döndürür, silinecek değeri ve `head`'i alır. `current` `head`'den başlar, bir de `previous` tutulur. `current` `NULL` olmadığı sürece ilerlenir. Üzerinde durulan düğümün verisi silinecek değerse iki durum vardır: düğüm `head` ise `head = current->next`; değilse `previous->next = current->next` ile düğüm atlanır. Her adımda `previous = current`, `current = current->next` ile ilerlenir. Döngü bitince `head` döndürülür. <!-- BELİRSİZ: silme fonksiyonunun slayt kodu karelerde yok; yalnız anlatımdan aktarıldı. Hoca slaytta kullanılmayan bir sayaç değişkeni de bulunduğunu söyledi. -->

> **Hocanın vurgusu:** Slayttaki kodda listeden çıkarılan düğüm bellekten silinmiyor; yalnız slaytta az yer kaplasın diye böyle. Çıkarılan düğüm geçici bir değişkene atanmalı, bağlantı güncellendikten sonra `free` edilmelidir.

Akışta dizi kullanılırken kodda işaretçilerle çalışıldığı için hoca bu kısmı akış yerine kodla anlatmayı tercih etti.

## 11. Linkli Liste ile Insertion Sort

Önceki haftalarda görülen insertion sort linkli listeyle daha da kolay gerçekleştirilebilir (ekrandan, 01:40:00). Derste gösterilen yöntem iki liste kullanır:

- **Girdi listesi (sırasız):** `a` başlı; 627, 758, 113.
- **Çıktı listesi (sıralı):** `b` başlı; 101, 515, 838. Bu listenin her zaman sıralı olduğu garanti edilir.

Her iterasyonda girdi listesinden bir düğüm koparılır ve çıktı listesinde olması gereken yere eklenir, tıpkı iskambil kağıtlarını yerine sokmak gibi. Girdi bitince çıktı listesi dolmuş ve sıralanmış olur. Her adımda bir düğüm silinip bir düğüm eklendiği için toplam bellek ihtiyacı $n$ düğümden fazla olmaz. İşlem karmaşıklığını her adımda ne kadar çalışıldığına bakarak hesaplamayı hoca öğrencilere bıraktı.

Slayttaki ilk adım şöyledir:

- Girdinin ilk düğümü 627, geçici işaretçi `t`'ye alınır; `a`'nın `next`'i 627'nin `next`'i (758) yapılarak düğüm koparılır. Girdi listesi 758, 113 olur.
- Çıktıda baştaki boş (dummy) düğüm geçilir: 101 ile karşılaştırılır, 627 daha büyük; 515, yine büyük; 838, artık 627 küçük. Yer 515 ile 838 arasıdır; `x` 515'i gösterir.
- `t->next = x->next; x->next = t;` ile ekleme yapılır. Çıktı listesi 101, 515, 627, 838 olur.

Sonraki adımda 758 koparılır; 101, 515, 627 geçilir, 838'de yer bulunur ve araya eklenir. Ardından 113 koparılır; 101 geçilir, 515'te durulur ve araya eklenir. Böylece her adımda yapılan şey, linkli listeye `insert` çağırmaktır: kopar, ekle.

Hoca kodu paylaşmadı; internette iki türünün de bulunabileceğini ya da öğrencilerin kendilerinin yazabileceğini söyledi. İki listenin başına birer boş (dummy) düğüm konursa bellekte iki düğüm fazla yer kaplanır, ama `head` kontrollerinden (ilk eleman ekleniyor mu kontrolü) kurtulunduğu için çok daha basit bir gerçekleştirme elde edilir. Aynı sıralama ek bir çıktı listesi kullanmadan da yapılabilir; bu da alıştırma olarak bırakıldı.

## 12. Çift Linkli Liste

### 12.1 Tanım

Tek linkli listede hep `next` ile ileri gidilir. Her düğüme bir de `prev` işaretçisi eklenirse düğümden hem ileri hem geri gidilebilir. Bu yapıya çift linkli liste (double linked list) denir. Ek olarak listenin sonunu gösteren bir `tail` işaretçisi tutulur: `head`'den başlayıp `next`'lerle `NULL`'a kadar ileri, `tail`'den başlayıp `prev`'lerle `NULL`'a kadar geri gezilebilir. İşletilmesi gereken işaretçi aritmetiği ve mantığı iki katına çıkar.

### 12.2 Araya Eleman Eklemek

`curr` düğümünden sonraya `new` düğümü eklenecek. Yine önceki ve sonraki düğümlerin işaretçilerini kaybetmemek gerekir. Adımlar (ekrandan, 01:50:00):

```c
new->next = curr->next;         /* 1 */
curr->next->prev = new;         /* 2 */
curr->next = new;               /* 3 */
new->prev = curr;               /* 4 */
```

<!-- BELİRSİZ: karede yalnız birinci satır yazılı; 2-4. satırlar hocanın anlatımından ve slayttaki numaralı çizimlerden kuruldu. -->

Önce, tek linkli listede olduğu gibi, yeni düğümün `next`'i `curr`'ün `next`'ine bağlanır. Hemen ardından sonraki düğümün `prev`'i yeni düğüme çevrilir: `curr->next` hâlâ sonraki düğümü gösterdiği için `curr->next->prev` ile ona erişilebilir. Sonradan gelen bağlantılar tamamlandıktan sonra önceki düğümle bağlantı kurulur: `curr->next = new`, en son `new->prev = curr`. Sonuçta `curr`'ün `next`'i yeni düğümü, yeni düğümün `next`'i sonrakini; sonrakinin `prev`'i yeni düğümü, yeni düğümün `prev`'i `curr`'ü gösterir. Hoca tam fonksiyonu yazmayı öğrencilere bıraktı.

### 12.3 Eleman Silmek

`del` işaretçisi silinecek düğümü gösterir (`del = curr->next` diye baştan yürünerek bulunmuştur). Önceki düğümün `next`'i sonraki düğüme, sonraki düğümün `prev`'i önceki düğüme bağlanmalıdır. Adımlar (ekrandan, 01:55:00):

```c
del->next->prev = del->prev;    /* 1 */
del->prev->next = del->next;    /* 2 */
free(del);
```

<!-- BELİRSİZ: karede yalnız birinci satır yazılı; 2. satır ve free hocanın anlatımından alındı. -->

Hoca sıranın nedenini şöyle açıkladı: önce ileri bağlantı (`del->prev->next = del->next`) kurulursa, ardından "silinenin sonrakinin önceki" bağlantısını kurmak için geriye dönüş yolu düşünülmelidir; bu yüzden önce geri dönüş bağlantısı tamamlanır. Birinci adımda sonraki düğümün `prev`'i artık silinen düğümü değil, onun öncesini gösterir. İkinci adımda öncekinin `next`'i silinenin sonrasına bağlanır. `del` hâlâ düğümü gösterdiği için en son `free(del)` ile bellek bırakılır.

> **Ek bilgi (derste anlatılmadı):** İki adım da `del`'in kendi `prev` ve `next` alanlarını kullandığı için, `del` serbest bırakılmadan önce bu iki atamanın sırası aslında sonucu değiştirmez. Sıra, yalnız `del` yerine komşulardan birinin üzerinden ilerleniyorsa önemli hale gelir.

Çift linkli listede tek linkli listeye göre bir ek iş yapılır; bu ek iş de bağlantıları kaybetmeden, belli bir mantık sırasıyla yapılmalıdır.

## 13. Dairesel Linkli Liste ve Josephus Problemi

### 13.1 Dairesel Linkli Liste

Dairesel linkli liste (circular linked list) yine linkli listelerin esnekliğini kullanır. `head`'den başlayıp `next`'lerle sona gelindiğinde son düğüm `NULL` yerine yeniden `head`'i gösterir. Liste yine bir `head` ile bilinir. Döngünün tamamlandığı, gezilen işaretçinin `head` ile aynı adresi göstermesinden anlaşılır. Hoca, probleme göre iki sonrakini ya da iki öncekini gösteren ek işaretçiler de tanımlanabileceğini söyledi. Linkli listeler probleme özel olarak kolayca değiştirilebilir ve bu değişiklikler algoritmaların daha performanslı çalışmasını sağlayabilir.

### 13.2 Problemin Hikayesi

Dairesel linkli listenin ünlü bir kullanım alanı Josephus problemidir. Hoca problemin tarihçesini şöyle anlattı: İmparator Nero döneminde bir ayaklanmayı bastırmakla general Vespasian görevlendirilir. Tarihçi Flavius Josephus ve 40 arkadaşı bir mağarada esir alınır. General, toplam 41 kişinin bir çember şeklinde dizilmesini, 1'den 41'e numaralanmasını, saat yönünde sayılarak her 3. kişinin öldürülmesini ve bunun son 2 kişi kalana kadar sürmesini ister. İlk turda 3, 6, 9, 12, 15, ... numaralı kişiler çıkarılacaktır. Josephus kargaşadan yararlanıp hangi numaraların sona kalacağını hızla hesaplar, kendisini ve en yakın arkadaşını o numaralara yerleştirir ve hayatta kalır.

Genel problem şudur: elde $N$ kişi (ya da sayı) vardır, $M$'er sayılarak her $M$. kişi çemberden çıkarılır. Sona kim kalır?

### 13.3 Örnek: N = 9, M = 5

Slayttaki örnekte 9 kişi vardır ve her 5. kişi çıkarılır (ekrandan, 02:20:00). Bir kişiyi çıkarmak, linkli listede aradan bir düğüm silmek demektir: öncekinin `next`'i sonrakine bağlanır.

| Tur | Saymaya başlanan | Çıkarılan | Kalan çember |
|---|---|---|---|
| 1 | 1 | 5 | 1, 2, 3, 4, 6, 7, 8, 9 |
| 2 | 6 | 1 | 2, 3, 4, 6, 7, 8, 9 |
| 3 | 2 | 7 | 2, 3, 4, 6, 8, 9 |
| 4 | 8 | 4 | 2, 3, 6, 8, 9 |
| 5 | 6 | 3 | 2, 6, 8, 9 |
| 6 | 6 | 6 | 2, 8, 9 |
| 7 | 8 | 9 | 2, 8 |
| 8 | 2 | 2 | 8 |

İlk turda 5 çıkarılınca 4, 6'ya bağlanır. İkinci turda 1 (`head`) çıkarılır; 9 zaten 1'e bağlıydı, şimdi 2'ye bağlanır ve `head` 2 olur. Sonra 7 çıkarılınca 6 ile 8, 4 çıkarılınca 3 ile 6 bağlanır; 3 çıkarılınca 2 ile 6 bağlanır. 6 kendi kendine sayarak çıkarılır, 2 ile 8 bağlanır. Sonra 9, en son 2 çıkarılır; geriye 8 kalır. Yani 9 kişilik ve 5'er sayılan bir çemberde Josephus'un kendini 8. sıraya yerleştirmesi gerekir.

### 13.4 Kod

Slayttaki kod (ekrandan, 02:25:00):

```c
int i, N=9, M=5;
link t = malloc(sizeof *t), x = t;

t->data = 1; t->next = t;

for (i=2; i <= N; i++){
    x = (x->next = malloc(sizeof *x));
    x->data = i; x->next = t;
}

while (x != x->next){
    for(i=1; i<M; i++) x=x->next;
    x->next = x->next->next;
    N--;
}
printf("%d\n", x->data);
```

Kodun başına `#include` satırları ve düğüm tanımı (`typedef ... link`) yazılır. Bütün hile şuradadır: ilk düğümün `next`'i `NULL` yerine kendisine bağlanır (`t->next = t`). Böylece tek düğümlü dairesel bir liste oluşur. Sonra 2'den $N$'e kadar her adımda yeni bir düğüm yaratılır, verisine $i$ yazılır ve `next`'i yeniden `t`'ye, yani `head`'e bağlanır. Böylece zincirin halkaları artırılarak 1, 2, ..., 9 değerli ve 9'un 1'i gösterdiği çember kurulur.

Problemin çözümü `while` döngüsündedir. `x != x->next` olduğu sürece, yani tek eleman kalmadığı sürece, $M$ sayılır ve bir kişi çıkarılır. Tek eleman kalınca o düğümün `next`'i kendisidir. Döngünün her adımında `x->next = x->next->next` ile bir düğüm çemberden çıkarılır ve $N$ bir azaltılır; $N$'i azaltmanın burada bir işlevi yoktur, ama "tek eleman kalana kadar" sayım için kullanılabilir. Sona kalan kişinin verisi `printf` ile yazdırılır. Kodu basit tutmak için `free` yoktur; hoca bunun eklenmesi gerektiğini yine hatırlattı.

> **Ders sonrası not:** Hoca sayımı "1, 2, 3, 4, 5, bu adamı öldür" diye anlattı. Kodda ise `x` her turun başında çıkarılacak kişiden önceki konumdan başlar (ilk turda son düğüm 9'dadır); `for` döngüsü $M-1$ adım ilerleyince `x` çıkarılacak kişiden bir önceki düğüme gelir ve `x->next` çıkarılır. Sonuç aynıdır. Kod, ajan tarafından `typedef struct node *link; struct node { int data; link next; };` tanımı ve `main` eklenerek `gcc -Wall` ile derlendi; çıkarılma sırası 5, 1, 7, 4, 3, 6, 9, 2 ve çıktı 8 oldu.

> **Hocanın vurgusu:** Burada algoritmik olarak hiçbir şey yok: bir `while`, bir `for` ve bir atama. Algoritmanın gücü veri yapısından geliyor. Dairesel linkli listenin basit eleman silme özelliği ve çemberde her zaman başa dönme bağlantısı sayesinde problem çok etkin bir şekilde çözülüyor.

Hoca oluşturma kısmını bir kenara bırakarak çıkarma kısmının işlem karmaşıklığını hesaplamayı ve sonra çalıştırarak kontrol etmeyi öğrencilere bıraktı (çözüm Örnek Sorular bölümündedir).

## 14. Dairesel Çift Linkli Liste ve Diğer Varyantlar

Linkli listeler bir aşama daha ileri götürülebilir: dairesel çift linkli liste (circular double linked list) (ekrandan, 02:30:00). Slayttaki ifade: "Linkli listeler esnek yapıları ile kolaylıkla probleme özel olarak modifiye edilebilir." Bir `start` (ya da `head`) verildikten sonra `next`'lerle ilerlenir, son düğümün `next`'i yeniden `start`'ı gösterir. Aynı şekilde `start`'ın `prev`'i son düğümdür ve `prev`'lerle geri gidilir. Böylece ileri doğru bir döngü ve geri doğru bir döngü tutulur. Hoca bunu, kasaların bir sağa bir sola çevrilen şifre düğmesine benzetti: ileri ve geri saymak gereken problemlerde kullanılabilir.

Hoca sık kullanılan başka yapılar da çizdi (ekrandan, 02:35:00):

- **Seyrek (sparse) matrisler:** Çok sayıda boş gözü olan matrisler, yalnız dolu gözler için $(x, y)$ koordinatı ve değeri tutan düğümlerle saklanabilir. Böylece yalnız dolu göz sayısı kadar yer kaplanır.
- **Komşuluk listeleri:** İleride çizgelerde (graph) görülecek. A, B, C, D değerli dört düğüm aşağı doğru bir linkli listeyle bağlanır (kırmızı); her birinin yanına doğru ayrı bir bağlantıyla kendi komşuları (mavi) bağlanır. Çizimde A'nın iki, B'nin bir, C'nin hiç, D'nin üç komşusu vardır. Bu, satır sayısı 4 olan ama sütunları dinamik bir "dizilerin dizisi" yapısıdır; tam bir $n \times n$ ya da $n \times m$ matris değildir.
- **Sağ ve aşağı bağlantılı düğümler:** Her gözünde bir düğüm bulunan, sağ bağlantıları bir sonrakine, aşağı bağlantıları alttakine giden ve kenarlarda `NULL` ile biten bir yapıyla soyut bir $n \times m$ matris oluşturulabilir. Hoca bunu geçmişte zor bir soru olarak sorduğunu söyledi.

Linkli listeler ister dairesel, ister iki yönlü (`next`/`prev`), ister sağ/aşağı bağlantılı yapılabilir; işaretçilerin mantığı tamamen probleme ve programcıya kalmıştır.

## 15. Diziler mi, Linkli Listeler mi?

Dersin sonunda iki yapı karşılaştırıldı (ekrandan, 02:40:00).

**Dizilerin uygun olduğu durumlar:**

- Sona eleman eklenip silindiğinde: linkli listede her seferinde sona kadar gitmek gerekir (ya da çift linkli liste kurup sondan erişilir).
- Herhangi bir elemana rastgele erişilecekse: dizide indisle doğrudan erişilir, linkli listede her seferinde `head`'den adım adım ilerlemek gerekir.
- Liste belirli bir değer için aranacaksa: örneğin dizi sıralıysa ikili arama (binary search) gibi yaklaşımlar kullanılabilir.

**Linkli listelerin uygun olduğu durumlar:**

- Eleman ekleme ve eleman silme dinamikse, özellikle sonda değil aralarda yapılıyorsa.
- Sıralı erişim gerektiren, elemanları baştan sona sırayla işleyen uygulamalar.
- Eleman sayısının tahmin edilemediği durumlar: dinamik bellekle dizi de kullanılabilir, ama her seferinde bir maliyet getirir.

Hocaya göre bunun tek bir reçetesi yoktur. Aynı problem diziyle de linkli listeyle de çözülebilir; zaman ve bellek karmaşıklığı analiz edilerek hangisi daha kârlıysa o seçilmelidir. Linkli listeler, işaretçi aritmetiğinden gelen esneklikleri sayesinde önemli bir araçtır. Pek çok veri yapısı linkli listelerle gerçekleştirilebilir: sonraki hafta görülecek yığıt (stack) ve kuyruk (queue) da önce diziyle anlatılacak, ama dinamik boyutlu bir kuyruk için linkli listenin daha iyi bir çözüm olduğu görülecektir.

## Örnek Sorular

### Soru 1 (derste sözlü, 00:07:25)

Bir algoritmanın karmaşıklığı $n \cdot 2^n$ olarak bulunduğunda bu yalnız $2^n$ diye mi yazılmalıdır? $5 \cdot 2^n + n^3$ yazmak doğru mudur?

> **Çözüm (derste verilen):** Hoca $n \cdot 2^n$'i açıkça yazmayı tercih ettiğini, $2^n$'in büyümesinin çok hızlı olduğu için $n$ çarpanının sezgisel olarak büyük fark yaratmadığını söyledi. $5 \cdot 2^n + n^3$ ise yanlıştır: en yüksek mertebeli terim kalır, katsayı atılır, yani $O(2^n)$ yazılır. Biçimsel olarak $n \cdot 2^n / 2^n = n$ sınırsız büyüdüğü için $n \cdot 2^n \notin O(2^n)$'dir; sıkı sınır $O(n \cdot 2^n)$'dir (bu son cümle ders sonrası eklendi).

### Soru 2 (derste sözlü, 00:29:52)

Dairesel linkli listede `NULL` olmadığı için sona gelindiği nasıl anlaşılır?

> **Çözüm (derste verilen):** Eleman sayısı tutulup bir sayaçla bütün elemanlar gezildiyse durulabilir. Ayrıca gezilen işaretçi yeniden `head` ile aynı adresi gösterdiğinde bir tur tamamlanmış demektir (derste sözlü, 02:13:50).

### Soru 3 (derste sözlü, 00:36:24)

Tek linkli bir listeyi tersine çeviren kodu yazınız. (Hoca bir `while` içinde birkaç satırla yapılabileceğini söyledi ve alıştırma olarak bıraktı.)

> **Çözüm (derste verilmedi):** Üç işaretçiyle liste bir kez gezilir; her düğümün `next`'i bir öncekine çevrilir.
>
> ```c
> Node *reverse(Node *head) {
>   Node *prev = NULL, *next;
>   while (head != NULL) {
>     next = head->next;
>     head->next = prev;
>     prev = head;
>     head = next;
>   }
>   return prev;
> }
> ```
>
> Bu fonksiyon, Bölüm 8.1'deki `Node` tanımı ve `insert_top` ile kurulan 1 2 3 4 listesi üzerinde `gcc -Wall` ile derlenip denendi; çıktı 4 3 2 1 oldu. Karmaşıklık $O(n)$, ek bellek $O(1)$'dir.

### Soru 4 (ekrandan, 01:00:00)

`a: 2 4 6 8`, `L: 1 2 3 -1`, `n: 4`, `head: 0` ile dizi kullanılarak tutulan sıralı linkli listeye önce 1, sonra 5 ekleyiniz. Her adımdan sonra `L`, `head`, `prev` ve `next` değerlerini veriniz.

> **Çözüm (derste verilen):** 1 eklenince `a: 2 4 6 8 1`, $n = 5$; $a[\text{head}] = 2 < 1$ yanlış olduğu için `L[4] = 0`, `head = 4`; `L: 1 2 3 -1 0`. 5 eklenince `a: 2 4 6 8 1 5`, $n = 6$; `prev`/`next` sırasıyla 4/0, 0/1, 1/2 olur ve $a[2] = 6 < 5$ yanlış olduğu için döngü biter. `L[1] = 5`, `L[5] = 2`; sonuç `L: 1 5 3 -1 0 2`, `head = 4`. Gezinti 1, 2, 4, 5, 6, 8.

### Soru 5 (ekrandan, 01:35:00)

`a: 2 3 4 6 7 8`, `L: 1 2 3 4 5 -1`, `n: 6`, `head: 0` ile tutulan listeden önce 2'yi, sonra 6'yı siliniz.

> **Çözüm (derste verilen):** 2 ilk eleman olduğu için `head = L[0] = 1`. 6 için `prev`/`adr` sırasıyla 1/2, 2/3 olur; $a[3] = 6$ bulunduğu için `L[2] = L[3] = 4`. Sonuç `L: 1 2 4 4 5 -1`, `head: 1`; gezinti 3, 4, 7, 8. Silinen 2 ve 6 dizide durur ama erişilemez.

### Soru 6 (ekrandan, 02:20:00)

Josephus problemi: 9 kişi bir çemberde, her 5. kişi çıkarılıyor ($N = 9$, $M = 5$). Çıkarılma sırası nedir, sona kim kalır? Dairesel linkli listeyle yazılan çözümün çıkarma kısmının işlem karmaşıklığı nedir?

> **Çözüm (derste verilen kısmı):** Çıkarılma sırası 5, 1, 7, 4, 3, 6, 9, 2; sona 8 numaralı kişi kalır.

> **Çözüm (derste verilmedi):** Çıkarma döngüsü $N-1$ kez döner ve her turda `for` ile $M-1$ adım ilerlenir. Dolayısıyla çıkarma kısmının karmaşıklığı $O(N \cdot M)$'dir (oluşturma kısmı $O(N)$). Kod derlenip çalıştırıldığında $N = 9$, $M = 5$ için 8 basıldı.

## Dersin Toparlaması

Bu derste diziler kısaca tekrar edildi ve dizilerin araya ekleme ile aradan silmede getirdiği $O(n)$ kaydırma maliyetinden yola çıkılarak ilk veri yapısı olan linkli listelere geçildi. Linkli listenin işaretçilerle birbirine bağlanan düğümlerden oluştuğu, yalnız `head` ile tanımlandığı ve soyut bir veri tipi olduğu anlatıldı. C'de düğüm tanımı, gezinti, başa ve araya ekleme, silme ve belleği `free` ile bırakma işlendi; aynı işlemler akışta anlatım kolaylığı için `a` ve `link` dizileriyle tutulan sıralı bir liste üzerinde adım adım izlendi. Linkli listeyle insertion sort, çift linkli listede ekleme ve silme, dairesel linkli liste ve onun en bilinen uygulaması Josephus problemi gösterildi. Bütün işlemlerde ortak ilke, bağlantıları kaybetmeden doğru sırayla güncellemektir.

Dersin sonunda dairesel çift linkli liste, seyrek matrisler ve komşuluk listeleri gibi varyantlarla linkli listelerin esnekliği vurgulandı ve dizilerle linkli listelerin hangi durumlarda tercih edileceği karşılaştırıldı. Hoca, ekleme, silme, gezme ve arama kodlarının tek yönlü, çift yönlü ve dairesel listelerde yazılmasını önerdi. Sonraki hafta yığıt ve kuyruk yapılarına geçilecek; bunlar da önce diziyle anlatılacak, ama linkli listelerle de gerçekleştirilebilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
