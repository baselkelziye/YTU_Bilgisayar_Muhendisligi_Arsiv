# Ders 11 Genişletilmiş Notu: Azaltarak Yönetme, Topolojik Sıralama ve Hashing'e Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Böl ve Yönetten Azaltarak Yönetmeye
- 2. Sabit Miktarda Azaltma ve Topolojik Sıralama
- 3. Topolojik Sıralamanın Karmaşıklığı
- 4. Sabit Oranda Azaltma: İkili Arama
- 5. Değişken Miktarda Azaltma: Öklid Algoritması
- 6. Hashing'e Giriş
- Örnek Sorular
- Dersin Toparlaması

## 1. Böl ve Yönetten Azaltarak Yönetmeye

Ders, önceki haftanın konusu olan böl ve yönet (divide and conquer) yaklaşımının hatırlatılmasıyla başladı. Hoca, algoritma analizindeki amacın önce zamanı, sonra yeri verimli kullanan çözümler üretmek olduğunu yineledi. Quicksort bu amaca iyi bir örnektir: dizi her seferinde bir pivota göre iki parçaya bölünür; pivottan küçükler kendi içinde, büyükler kendi içinde sıralanır. Böylece gereksiz karşılaştırmalar yapılmaz.

Böl ve yönete benzeyen bir yaklaşım daha vardır: **azaltarak yönetme (decrease and conquer)**. Burada problem, elde işlenecek bilgi adım adım azaltılarak çözülür. Bu azaltma iki biçimde olur: işe yaramayan bilgi atılır ya da problem parça parça çözülerek geriye kalan kısım küçülür.

Hoca, öğrencilerin bu yaklaşıma uyan bir algoritma bilip bilmediğini sordu. Bir öğrenci ikili aramayı (binary search) önerdi; hoca bunu doğruladı. Sıralı bir dizide aranan sayı ortadaki elemandan küçükse, ortadan büyük olan elemanlarla ilgilenmeye gerek yoktur; aranan sayı onların hepsinden küçük olacaktır. Böylece dizinin yarısı tek seferde elenir.

Azaltarak yönetmenin üç türü anlatıldı:

- Sabit miktarda azaltma (decrease by a constant).
- Sabit bir oranda azaltma (decrease by a constant factor).
- Değişken miktarda azaltma (variable size decrease).

## 2. Sabit Miktarda Azaltma ve Topolojik Sıralama

### 2.1 Örnek algoritmalar

Ekrandaki listeye göre sabit miktarda azaltmanın örnekleri insertion sort, topolojik sıralama (topological sort), DFS ve BFS'dir (ekrandan, 00:05:00). Bu algoritmalarda elde işlenecek kısım her adımda birer birer azalır.

Hoca insertion sort'u kısaca hatırlattı. Sırasız bir dizide önce ilk eleman yerine konur ve onunla artık ilgilenilmez. Sonra sıradaki eleman sıralı kısma yerleştirilir. Hocanın sözlü örneğinde 3, 8, 4 için 8'e dokunulmaz, 4 gelince 4 ile 8 yer değiştirir ve dizi sıralanır. Her adımda işlenmemiş kısım bir azalır; bu yüzden insertion sort sabit miktarda azaltmanın bir örneğidir. DFS'de de bir düğümden başlanıp sırayla diğer düğümlere geçilerek en sona kadar ilerlenir; mantık yine elde kalan bilgiyi azaltarak kalan üzerinde işlem yapmaktır.

### 2.2 Topolojik sıralama nedir

Topolojik sıralama, birbirine bağlı işlerin hangi sırayla yapılabileceğini bulur. Hoca bunun iş zamanlamasında (job scheduling) çok kullanılan bir yaklaşım olduğunu söyledi. Ekrandaki örnekte işler A, B, C, D, E, F'dir (ekrandan, 00:10:00). Çizgedeki bir $X \to Y$ kenarı, "Y'nin yapılabilmesi için önce X bitmeli" demektir. Örnek çizgenin kenarları şunlardır:

- $A \to B$, $A \to D$
- $B \to C$
- $C \to D$, $C \to E$
- $D \to E$
- F hiçbir düğüme bağlı değildir.

Yani B'nin yapılabilmesi için A'nın, D'nin yapılabilmesi için hem A'nın hem C'nin, E'nin yapılabilmesi için hem C'nin hem D'nin bitmesi gerekir. F bağımsızdır, ne zaman istenirse yapılabilir.

Hoca, "önce hangi işler yapılabilir?" diye sordu. Öğrenciler F ve A dedi; hoca ikisini de onayladı, çünkü ikisinin de öncesinde bitmesi gereken bir iş yoktur. Sonrası için adım adım ilerlemek zorunludur; örneğin C'ye başlamak için önce B bitmelidir.

Hoca sezgi için ön şartlı dersleri örnek verdi: bir dersi alabilmek için önce başka bir dersten geçmek gerekir, o ders için de bir başkasından. Ekranda bu, $A \to B \to C$ biçiminde üç dersten oluşan bir zincir olarak çizildi (ekrandan, 00:10:00). Bir dersin önünde çok sayıda ön şart varsa topolojik sıralama, derslerin hangi sırayla alınabileceğini gösterir.

### 2.3 Komşuluk listesi ve giriş derecesi

Önce çizgenin komşuluk listesi (adjacency list) kurulur (ekrandan, 00:15:00):

```text
A -> B -> D
B -> C
C -> D -> E
D -> E
E -> (boş)
F -> (boş)
```

Sonra her düğümün **giriş derecesi (in-degree)**, yani kendisinden önce bitmesi gereken iş sayısı bir dizide tutulur. Hoca bunun iki yolla bulunabileceğini söyledi: listenin sağ tarafında bir düğümün kaç kez geçtiği sayılabilir ya da daha doğru yol olarak dizi başta sıfırlanır ve her kenar için hedef düğümün değeri 1 artırılır. A'nın komşuları B ve D olduğu için ikisi 1 artar; B'nin komşusu C olduğu için C 1 artar; C'nin komşuları D ve E 1'er artar; D'nin komşusu E 1 artar.

Hoca ilk hesapta E'yi 1 yazmıştı. Bir öğrenci "D ve C, E'yi göstermesine rağmen E'ye 1 yazdık" diye uyardı; hoca teşekkür edip E'yi 2 yaptı. Doğru dizi şudur (ekrandan, 00:20:00):

| Düğüm | A | B | C | D | E | F |
|---|---|---|---|---|---|---|
| Giriş derecesi | 0 | 1 | 1 | 2 | 2 | 0 |

Giriş derecesi 0 olan düğümler, öncesinde iş olmayan, yani hemen başlanabilecek işlerdir.

### 2.4 Elle sıralama

Giriş derecesi 0 olanlar A ve F'dir. İkisi eşit önceliklidir; genelde sıraya bakılarak önce A, sonra F alınır. A yapılınca A'nın bağlı olduğu B ve D'nin derecesi 1 azalır: B 0, D 1 olur. Sonra B yapılır; B'nin bağlı olduğu C 0 olur. C yapılınca D 0, E 1 olur. D yapılınca E 0 olur. En son E yapılır. Sonuç sırası **A F B C D E**'dir (ekrandan, 00:20:00; python ile doğrulandı).

**Soru:** Azalta azalta gitmek yerine önce derecesi 0 olanları, sonra 1 olanları, sonra 2 olanları yazsak daha verimli olmaz mı?
**Cevap:** Olmaz, yanlış sonuç verir. Derecenin 1 ya da 2 olması o düğüme ne zaman sıra geleceğini göstermez. Hoca bunu sözlü bir örnekle anlattı: bir düğümün öncesinde yalnız bir iş görünebilir, ama o tek işin kendisi uzun bir zincirin sonundadır; önce zincirdeki diğer işlerin bitmesi gerekir. Bu yüzden yalnız derecesi 0 olanlar işleme alınır.

**Soru:** A ile başlarsak F'nin en son yapılması gerekmez mi?
**Cevap:** Hayır. F'den önce bitmesi gereken bir iş yoktur; F, A ile eşit önceliklidir ve hemen yapılabilir. Harf sırasının ya da çizimdeki yerin bir önemi yoktur; bakılması gereken tek şey giriş derecesi dizisidir.

### 2.5 Yönlü döngü kuralı

Hoca bir soruyu açıklamak için çizgeye $D \to B$ kenarını ekledi (ekrandan, 00:25:00). Bu kenarla giriş dereceleri A:0, B:2, C:1, D:2, E:2, F:0 oldu. A ve F yapıldıktan sonra B'nin derecesi 1, D'nin derecesi 1 kaldı ve başlanabilecek iş kalmadı. Hoca, "örnek göstereyim derken kuralı kendim bozdum" diyerek kuralı açıkladı:

> **Hocanın vurgusu:** Topolojik sıralama yalnız **yönlü döngü (directed cycle) içermeyen yönlü çizgede** (digraph with no directed cycle) yapılabilir (ekrandan, 00:35:00). Döngü varsa döngüdeki her iş bir öncekini bekler ve başlanabilecek iş kalmaz.

Eklenen $D \to B$ kenarı, mevcut $B \to C$ ve $C \to D$ kenarlarıyla birlikte $B \to C \to D \to B$ döngüsünü oluşturmuştu. Hoca bunu düzeltmek için $C \to D$ kenarını kaldırdı. Yeni çizge şudur (ekrandan, 00:35:00):

```text
A -> B -> D
B -> C
C -> E
D -> B -> E
E -> NULL
F -> NULL
```

Yeni giriş dereceleri:

| Düğüm | A | B | C | D | E | F |
|---|---|---|---|---|---|---|
| Giriş derecesi | 0 | 2 | 1 | 1 | 2 | 0 |

Elle çözüm: A ve F yapılır. A yapılınca B 1'e, D 0'a iner. D yapılır; D'nin bağlı olduğu B 0'a, E 1'e iner. B yapılır; C 0 olur. C yapılır; E 0 olur. E yapılır. Sıra **A F D B C E**'dir. Hoca, **F A D B C E** sırasının da doğru olduğunu söyledi. Hoca, bu modelde işlerin süresinin dikkate alınmadığını, aynı anda yapılabilen işlerin paralel yürütülebildiğinin varsayıldığını ekledi.

### 2.6 Kuyruk ile topolojik sıralama

Elle çözümde her işten sonra giriş derecesi dizisi baştan sona taranıp yeni sıfırlar aranıyordu. Hoca, bunun yerine daha verimli bir yol olup olmadığını sordu.

**Soru:** Azalttıktan sonra 0 aramak yerine azaltırken 1 olanlara bakmak olabilir mi?
**Cevap:** Hayır. Derecenin 1 olması bir sonraki adımda 0 olacağı anlamına gelmez; düğümün başka bir öncülü daha bitmemiş olabilir.

Bir öğrenci öncelik kuyruğu (priority queue) önerdi; hoca öncelik kuyruğuna gerek olmadığını, sıradan bir kuyruğun (queue) yeteceğini söyledi. Yöntem şudur:

- Giriş derecesi 0 olan bütün düğümler kuyruğa konur.
- Kuyruğun başındaki düğüm çıkarılır ve sıralamaya yazılır.
- Bu düğümün bağlı olduğu her düğümün derecesi 1 azaltılır. Derece tam o anda 0 olursa düğüm hemen kuyruğa eklenir.
- Kuyruk boşalınca işlem biter.

Düzeltilmiş çizge üzerinde iz (ekrandan, 00:40:00 ve 00:45:00):

| Adım | Kuyruktan çıkan | Derece değişimi | Kuyruğa eklenen | Kuyruk |
|---|---|---|---|---|
| Başlangıç | - | - | A, F | A, F |
| 1 | A | B: 2→1, D: 1→0 | D | F, D |
| 2 | F | (komşu yok) | - | D |
| 3 | D | B: 1→0, E: 2→1 | B | B |
| 4 | B | C: 1→0 | C | C |
| 5 | C | E: 1→0 | E | E |
| 6 | E | (komşu yok) | - | boş |

Sonuç sırası **A F D B C E**'dir (python ile doğrulandı). Ekranda "E çıkınca kuyruk boş" ve "kuyruk boş ise işlem biter" notları yazıldı.

**Soru:** C de E'ye bağlı, D de E'ye bağlı. E, daha önce kuyruğa eklenmiş olabilir mi; bir düğüm kuyruğa iki kez girer mi?
**Cevap:** Girmez. Bir düğüm ancak derecesi 0'a düştüğü anda kuyruğa eklenir. Derecesi 0 olan bir düğümün öncesinde yapılacak iş kalmamıştır; ona bağlı bekleyen bir kenar da kalmadığı için o düğüme bir daha uğranmaz.

> **Hocanın vurgusu:** Kuyruk kullanınca derecesi 0 olan düğüm doğrudan kuyruğa eklenir; dizinin her turda "kim sıfır oldu" diye baştan sona taranması gerekmez. Hoca bunu "çok güzel bir algoritma, aklınızda kalsın" diye niteledi.

## 3. Topolojik Sıralamanın Karmaşıklığı

Bir öğrenci algoritmanın karmaşıklığını sordu. Hoca bunun düğüm sayısı $|V|$ (vertex) ve kenar sayısı $|E|$ (edge) cinsinden yazıldığını söyledi ve iki yolun adımlarını ekrana yazdı (ekrandan, 00:50:00).

Klasik yol:

- 1. Her düğümün giriş derecesini bir dizide sakla: $O(|E|)$. Her kenar için bir artırma yapılır.
- 2. Düğüm kaldıkça:
  - Giriş derecesi 0 olan bir düğüm bul: $O(|V|^2)$. $|V|$ düğümün her biri için dizi baştan taranır.
  - Ona komşu bütün düğümlerin derecesini 1 azalt: toplamda $O(|E|)$.
  - Bu düğümün derecesini $-1$ yaparak işaretle (tekrar seçilmesin).

Toplam: $O(|V|^2 + |E|)$.

Kuyrukla:

- 1. Giriş derecelerini hesapla: $O(|E|)$.
- 2. Giriş derecesi 0 olan bütün düğümlerle kuyruğu başlat: $O(|V|)$. Dizi bir kez taranır; hoca bunu öğrencilere sordu, "E" diyen öğrenciyi düzelterek cevabın $V$ olduğunu söyledi.
- 3. Kuyrukta düğüm kaldıkça:
  - Kuyruğun başındaki düğümü çıkar: kuyruğa en çok $|V|$ düğüm girdiği için toplam $O(|V|)$.
  - Komşularının derecesini azalt: toplam $O(|E|)$.
  - Derecesi 0 olanı kuyruğa ekle: en çok $O(|E|)$.

Toplam: $O(|V| + |E|)$, yani doğrusal.

> **Ders sonrası not:** Altyazıda klasik yolun karmaşıklığı bir yerde "V²E" diye geçiyor; hocanın hem önceki anlatımında hem ekrandaki adımlarda toplam $O(|V|^2) + O(|E|)$'dir, yani $O(|V|^2 + |E|)$. "V²E" büyük olasılıkla Whisper'ın "V kare artı E" ifadesini birleştirmesidir.

## 4. Sabit Oranda Azaltma: İkili Arama

### 4.1 Fikir

Sabit oranda azaltmada problem her adımda sabit bir orana bölünür ve bir kısmı atılır. İkili aramada bu oran 2'dir: $n$ boyutlu problem bir adımda $n/2$ boyutlu bir alt probleme iner (ekrandan, 01:10:00). Hoca, ihtiyaca göre 3'e ya da 5'e bölerek ilerleyen algoritmaların da bu sınıfa girdiğini ekledi.

### 4.2 Özyinelemeli ikili arama

Hoca kodu ekrana yazdı (ekrandan, 01:15:00). Başlangıçta `low = 0`, `high = N-1`'dir. Hoca, C'de dizinin kendisi değil göstergesi (pointer) aktarıldığı için diziyi parametre olarak vermenin bir maliyeti olmadığını belirtti.

```c
BinarySearch(A, low, high, value)
{
    if (low > high)
        return -1;          // not found
    mid = (low + high) / 2;
    if (A[mid] > value)
        return (BinarySearch(A, low, mid-1, value));
    else if (A[mid] < value)
        return (BinarySearch(A, mid+1, high, value));
    else
        return mid;
}
```

`low > high` ise aralıkta eleman kalmamıştır ve aranan değer yoktur. Ortadaki eleman aranan değerden büyükse değer sol yarıdadır; `high` değeri `mid-1` yapılarak arama sürer. Küçükse değer sağ yarıdadır; `low` değeri `mid+1` yapılır. İkisi de değilse eleman bulunmuştur ve `mid` döndürülür. Hocanın sözlü örneğinde 3, 5, 7, 9, 11, 13, 15 dizisinde 5 aranırken ortadaki 9, 5'ten büyük olduğu için sol yarıya inilir.

**Soru:** Fonksiyonu `return` ile döndürmek yerine yalnız kendisini çağırsak bir şey değişir mi?
**Cevap:** Hoca önce iki biçimin de yazılabileceğini söyledi. Ardından başka bir öğrenci, değer bulunduğunda sonucun en üste kadar taşınması için her çağrının `return` etmesi gerekip gerekmediğini sordu. Hoca, değer bulunduğunda çağrının durduğunu ve `mid` değerinin çağrı zinciri boyunca "döndüre döndüre" en üste geri taşındığını, başka bir şansı olmadığını anlattı ve ekrandaki `return`'lü biçimi korudu.

> **Ders sonrası not:** C'de özyinelemeli çağrının sonucu `return` ile geri verilmezse çağıran fonksiyonun dönüş değeri tanımsız olur ve bulunan indis en üste ulaşmaz. Bu yüzden ekrandaki `return (BinarySearch(...))` biçimi gereklidir; yalnız `BinarySearch(...)` çağırmak doğru sonuç vermez.

### 4.3 Karmaşıklık

Her adımda yapılan sabit iş (karşılaştırma, `mid` hesabı) $c$ ile gösterilirse yineleme bağıntısı şudur (ekrandan, 01:15:00):

$$T(n) = T(n/2) + c$$

Hoca karmaşıklığı sordu; öğrenciler $\log n$ cevabını verdi. Hoca bunun geriye doğru yerine koyma (backward substitution) ile görülebileceğini, öğrenciler bildiği için çözmeyeceğini söyledi. İkili arama azaltarak yönetmenin en çok kullanılan algoritmalarındandır.

> **Ek bilgi (derste anlatılmadı):** Geriye doğru yerine koyma ile $T(n) = T(n/2) + c = T(n/4) + 2c = \dots = T(n/2^k) + kc$ olur. $n/2^k = 1$ için $k = \log_2 n$ alınırsa $T(n) = T(1) + c\log_2 n$, yani $T(n) \in \Theta(\log n)$ çıkar.

## 5. Değişken Miktarda Azaltma: Öklid Algoritması

Değişken miktarda azaltmada her adımda ne kadar bilginin atılacağı önceden belli değildir. Hocanın örneği en büyük ortak bölendir (greatest common divisor, GCD). Öklid algoritması ekranda şöyle yazıldı (ekrandan, 01:20:00):

$$\gcd(a,b) = \begin{cases} a & b = 0 \text{ ise} \\ \gcd(b,\ a \bmod b) & \text{değilse} \end{cases}$$

Örnek $\gcd(80, 44)$:

- $\gcd(80, 44) = \gcd(44,\ 80 \bmod 44) = \gcd(44, 36)$
- $\gcd(44, 36) = \gcd(36,\ 44 \bmod 36) = \gcd(36, 8)$
- $\gcd(36, 8) = \gcd(8,\ 36 \bmod 8) = \gcd(8, 4)$
- $\gcd(8, 4) = \gcd(4,\ 8 \bmod 4) = \gcd(4, 0) = 4$

Sonuç 4'tür (python ile doğrulandı). Hoca, $44 = 11 \cdot 4$ olduğunu ve 11 asal olduğu için bundan büyük ortak bölen çıkamayacağını da belirtti.

> **Ders sonrası not:** Hoca ilk hesapta $44 \bmod 36$'yı 12 bulup sonucu 12 verdi. Bir öğrenci $44 \bmod 36 = 8$ olduğunu, başka bir öğrenci hesabın $36 \bmod 8 = 4$ ile sürdüğünü hatırlattı; hoca düzeltip sonucu 4 olarak verdi. Doğrusu yukarıdaki zincirdir.

Burada görülmesi gereken, adımların sayısının ve her adımda problemin ne kadar küçüleceğinin belli olmamasıdır: ne birer birer ne de ikiye bölerek azalır. Algoritmanın kodu da aynı tanımdır: $b$ sıfırsa $a$ döndürülür, değilse $\gcd(b, a \bmod b)$ çağrılır.

## 6. Hashing'e Giriş

### 6.1 Neden hashing

Hoca hashing'i gerçek dünyada en çok kullanılan ve çok verimli bir konu olarak tanıttı. Hashing bir arama yöntemidir ve karmaşıklığı $O(1)$'dir; yani eleman sayısı $n$'e bağlı değildir (ekrandan, 01:25:00). Bu, işlemin tek adımda biteceği anlamına gelmez; 5 ya da 10 adım sürebilir, ama adım sayısı $n$ ile, $\log n$ ya da $n^2$ gibi büyümez. Arama (search), ekleme (insert) ve silme (delete) işlemlerinin üçü de $O(1)$ olabilir.

**Soru:** Hashing ile veriye erişmek nasıl $O(1)$ olabilir?
**Cevap:** Hoca bunun, hash'in nasıl yapıldığı anlaşılmadan kavranamayacağını, dersin geri kalanında anlatılacağını söyledi.

### 6.2 Bilinen arama yöntemleriyle karşılaştırma

Hoca bildik arama yöntemlerinin arama, ekleme ve silme karmaşıklıklarını bir tabloda topladı (ekrandan, 01:30:00; tablonun yalnız ilk hücreleri ekranda dolu, diğerleri anlatımdan).

En kötü durum:

| Yöntem | Arama | Ekleme | Silme |
|---|---|---|---|
| Sıralı arama (sırasız dizi) | $n$ | 1 | $n$ |
| İkili arama (sıralı dizi) | $\log n$ | $n$ | $n$ |
| İkili arama ağacı (BST) | $n$ | $n$ | $n$ |
| Dengeli ağaç | $\log n$ | $\log n$ | $\log n$ |

- Sıralı aramada aranan eleman dizinin sonunda olabilir ya da hiç olmayabilir; bu yüzden en kötü durum $n$'dir. Düz bir diziye ekleme başa ya da sona yapılabildiği için 1'dir. Silinecek eleman dizinin sonunda olabileceği için silme $n$'dir.
- İkili aramada ekleme ve silme $n$'dir: eklenecek yer sırayla bakılarak bulunur ve elemanlar kaydırılır. Hoca, yerin ikili aramayla bulunabileceğini ama algoritma kitaplarının bunu ayrıca değerlendirmediğini söyledi.
- BST'nin dengesi eklemeler ve silmeler sonunda bozulmuşsa ağaç bir tarafa yığılır ve en kötü durum $n$ olur.
- Dengeli ağaçta işlemler $\log n$'dir, ama dengenin sürekli korunması gerekir.

Ortalama durumda BST ve dengeli ağaç için arama, ekleme ve silme $\log n$ olarak değerlendirilir; sıralı arama için $n/2$ söylendi <!-- BELİRSİZ: ortalama sütunu ekranda boş; altyazıda "N bölü 2" ifadesi "Binary Search" adıyla geçiyor, büyük olasılıkla sıralı arama kastediliyor -->. Hoca ortalama durum hesaplarına ayrıca girmedi.

Sonuç olarak bu yöntemlerle elde edilebilecek en iyi değer $\log n$'dir. Hashing bunun daha iyisini yapma fikri üzerine kurulmuştur.

### 6.3 Hash tablosu ve hash fonksiyonu

Hashing'de genelde benzersiz (unique) bir anahtar (key) kullanılır. Hoca, bir kişinin kaydını saklarken adı yerine bir kimlik numarasını kullanmanın mantıklı olduğunu söyledi, çünkü aynı adı taşıyan başka biri olabilir; öğrenciler için de öğrenci numarası kullanılabilir. Ancak bu şart değildir; uygulamaya göre tabloda aynı değerler de bulunabilir.

Anahtar bir **hash fonksiyonundan** geçirilir ve bir **indis** (index) elde edilir. Uzunluğu $m$ olan bir **hash tablosu** (hash table) vardır; eleman, indisi gösteren göze yerleştirilir (ekrandan, 01:35:00). Hocanın örneğinde 8 haneli bir numara hash fonksiyonundan geçip 3 indisini üretti ve 3. göze kondu. Aynı numara aranırken yine aynı fonksiyondan geçirilir, yine 3 elde edilir ve doğrudan 3. göze bakılır. Gözde yalnız anahtar değil, ad, soyad gibi alanları olan bir yapı (structure) tutulabilir. Böylece hash fonksiyonu anahtarı bir adrese dönüştürür; yerleştirme de arama da ideal koşullarda $O(1)$ olur.

> **Hocanın vurgusu:** Hash fonksiyonunun çok karmaşık olması gerektiği bir "batıl inançtır". Hash fonksiyonu iki şeyi sağlamalıdır (ekrandan, 01:40:00):

- Kolay hesaplanabilir olmalı (easy to compute).
- Tutarlı olmalı (consistent): aynı anahtar için her zaman aynı değeri üretmeli; bugün 3 üretirken yarın 9 üretmemeli.

### 6.4 Başarılı bir hash için üç soru

$N$ dizideki eleman sayısı, $m$ hash tablosunun boyutu olsun. Hoca başarılı bir hash işleminin üç soruya bağlı olduğunu söyledi (ekrandan, 01:40:00):

- Tablo ne kadar büyük olmalı? (How big should the table be?)
- Hash fonksiyonu nasıl seçilmeli? (How to select a hash function?)
- Çakışma nasıl çözülmeli? (How to solve collision?)

Çakışma (collision), iki farklı anahtarın aynı indisi üretmesidir. Ekrandaki örnekte iki farklı numara aynı hash fonksiyonundan geçip ikisi de 3 üretir; birincisi 3. göze yerleşmiştir, ikincisi geldiğinde göz doludur (ekrandan, 01:40:00). Bu üç soru doğru planlanırsa arama, ekleme ve silme $O(1)$ ile yapılabilir. Hoca çakışma çözümünü sonraki derse bıraktı.

### 6.5 Bölme yöntemi (division method)

En çok kullanılan hash fonksiyonudur (ekrandan, 01:45:00):

$$h(key) = key \bmod m$$

Tablo $0$'dan $m-1$'e kadar indislenir. Örnek $m = 7$:

- $h(25) = 25 \bmod 7 = 4$; 25, 4. göze yerleşir.
- $h(2) = 2$; 2, 2. göze yerleşir.
- $h(7) = 7 \bmod 7 = 0$; 7, 0. göze yerleşir.
- Sonra $key = 4$ gelirse $h(4) = 4 \bmod 7 = 4$ olur; ama 4. gözde 25 vardır. Çakışma oluşur ve bir şekilde çözülmesi gerekir.

(Değerler python ile doğrulandı.)

**Soru:** Kullandığımız hazır hash tabloları boyutu kendisi mi seçiyor?
**Cevap:** Hoca, dillerin (örneğin Java'nın) sağladığı hash tablosu yapılarıyla bu konunun karıştırılmaması gerektiğini söyledi. Burada anlatılan, algoritmik olarak bir hash tablosunun nasıl tasarlanacağıdır ve hash tablosu sıradan bir dizidir. Örneğin 7, 2, 25, 9 sayılarından oluşan bir A dizisinin elemanları bir hash tablosuna yerleştirilir ve sonra doğrudan erişilebilir hale gelir. Tablonun uzunluğu ana dizinin uzunluğundan büyük olmalıdır; aynı boyutta olursa çakışma ihtimali artar, boş yer çoğaldıkça çakışma ihtimali düşer. Ama yer sonsuz değildir; algoritma tasarımında hem yer hem zaman kazanılmak istenir. Bu yüzden tablo uzunluğu $n$'e bağlı olarak öyle seçilmelidir ki hem az yer kullanılsın hem de işlemler $n$'e bağlı olmadan sabit sürede yapılabilsin.

### 6.6 Çarpma yöntemi (multiplication method)

İkinci temel yöntemin formülü şudur (ekrandan, 01:50:00):

$$h(key) = \lfloor m \cdot ((key \cdot A) \bmod 1) \rfloor$$

Burada $m$ tablo boyutudur. $A$ sabiti için Knuth'un önerdiği değer kullanılır:

$$A = \frac{\sqrt5 - 1}{2} \approx 0{,}618033$$

Hoca öğrencilere "$x \bmod 1$ neyi verir?" diye sordu; bir öğrenci "ondalık kısmı" dedi ve hoca onayladı. Bir sayının 1'e bölümünden kalan, o sayının ondalık kısmıdır. $\lfloor \cdot \rfloor$ ise tam kısmı alır.

Örnek: $m = 10000$, $key = 123456$ (tabloya yerleşecek sayı):

- $123456 \cdot A = 76300{,}0041151\ldots$
- $(123456 \cdot A) \bmod 1 = 0{,}0041151$
- $10000 \cdot 0{,}0041151 = 41{,}151$
- $h(123456) = \lfloor 41{,}151 \rfloor = 41$

123456 sayısı tablonun 41. gözüne yerleşir. Aranırken aynı fonksiyondan geçirilir, yine 41 elde edilir ve doğrudan 41. göze bakılır.

> **Ders sonrası not:** Ekranda çarpım $123456 \cdot 0{,}618033$ diye yazılmış, sonucu $76300{,}0041151$ verilmiş. Bu sonuç $A$'nın tam değeriyle ($0{,}6180339887\ldots$) elde edilir. Altı haneye kesilmiş $0{,}618033$ ile çarpım $76299{,}882048$ olur ve sonuç 8820 çıkar (python ile doğrulandı). Ondalık kısım çok hassas olduğu için hesapta $A$'nın tam değeri kullanılmalıdır.

Hoca bu iki yöntemin temel yöntemler olduğunu, başka fonksiyonlar da kullanılabileceğini ama hash fonksiyonunun karmaşık olmasına gerek olmadığını tekrarladı. Asıl belirleyici olan tablo boyutu ve çakışma çözümüdür: ne kadar iyi bir fonksiyon seçilirse seçilsin bir gün başka bir anahtar da aynı adresi (örneğin 41'i) üretecektir. O zaman o anahtarın nereye ve nasıl yerleştirileceği iyi belirlenmelidir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:03:08): Bugüne kadar görülen algoritmalar içinde azaltarak yönetme (decrease and conquer) mantığıyla çalışan hangisidir?

> **Çözüm (derste verildi):** İkili arama. Aranan değer ortadaki elemandan küçükse ortadan büyük olanların hepsi tek seferde elenir. Insertion sort, topolojik sıralama, DFS ve BFS de bu yaklaşımın örnekleridir.

**Soru 2** (ekrandan, 00:10:00 ve 00:20:00): A, B, C, D, E, F işleri için kenarlar $A \to B$, $A \to D$, $B \to C$, $C \to D$, $C \to E$, $D \to E$'dir; F bağımsızdır. Önce hangi işler yapılabilir? İşler hangi sırayla yapılmalıdır?

> **Çözüm (derste verildi):** Giriş dereceleri A:0, B:1, C:1, D:2, E:2, F:0. Önce A ve F yapılabilir. A yapılınca B 0 olur; B'den sonra C, C'den sonra D, en son E 0 olur. Sıra: A F B C D E (python ile doğrulandı).

**Soru 3** (ekrandan, 00:25:00): Aynı çizgeye $D \to B$ kenarı eklenirse ne olur?

> **Çözüm (derste verildi):** $B \to C \to D \to B$ yönlü döngüsü oluşur. Giriş dereceleri A:0, B:2, C:1, D:2, E:2, F:0 olur. A ve F yapıldıktan sonra B ve D'nin derecesi 1'de kalır ve başlanabilecek iş yoktur. Topolojik sıralama yalnız yönlü döngüsüz çizgede yapılabilir.

**Soru 4** (ekrandan, 00:35:00 ve 00:40:00): Kenarları $A \to B$, $A \to D$, $B \to C$, $C \to E$, $D \to B$, $D \to E$ olan (F bağımsız) çizgede kuyruk kullanarak topolojik sıralama yapın.

> **Çözüm (derste verildi):** Giriş dereceleri A:0, B:2, C:1, D:1, E:2, F:0. Kuyruk A, F ile başlar. A çıkar: B 1, D 0 olur, D eklenir. F çıkar. D çıkar: B 0 olur (eklenir), E 1 olur. B çıkar: C 0 olur, eklenir. C çıkar: E 0 olur, eklenir. E çıkar, kuyruk boşalır. Sıra: A F D B C E (python ile doğrulandı). F A D B C E de geçerli bir sıradır.

**Soru 5** (derste sözlü, 00:44:40 ve 00:49:18): Topolojik sıralamanın karmaşıklığı nedir? Kuyruk başlatılırken giriş derecesi 0 olanları bulmanın karmaşıklığı nedir?

> **Çözüm (derste verildi):** Klasik yolda $O(|V|^2 + |E|)$; kuyrukla $O(|V| + |E|)$. Kuyruğu başlatmak için giriş derecesi dizisi bir kez taranır: $O(|V|)$.

**Soru 6** (ekrandan, 01:15:00): Özyinelemeli ikili aramanın yineleme bağıntısı $T(n) = T(n/2) + c$ ise karmaşıklığı nedir?

> **Çözüm (derste verildi):** $O(\log n)$. Problem her adımda yarıya indiği için yaklaşık $\log_2 n$ adım sürer.

**Soru 7** (ekrandan, 01:20:00): $\gcd(80, 44)$ değerini Öklid algoritmasıyla bulun.

> **Çözüm (derste verildi):** $\gcd(80,44) = \gcd(44,36) = \gcd(36,8) = \gcd(8,4) = \gcd(4,0) = 4$ (python ile doğrulandı).

**Soru 8** (derste sözlü, 01:26:37 ve 01:27:00): Sırasız bir dizide sıralı aramanın, sıralı bir dizide ikili aramanın ve BST'de aramanın en kötü durum karmaşıklığı nedir?

> **Çözüm (derste verildi):** Sıralı arama $O(n)$, ikili arama $O(\log n)$, dengesi bozulmuş BST $O(n)$.

**Soru 9** (ekrandan, 01:45:00): $m = 7$ ve $h(key) = key \bmod m$ iken 25, 2, 7 anahtarları hangi gözlere yerleşir? Sonra 4 gelirse ne olur?

> **Çözüm (derste verildi):** $h(25) = 4$, $h(2) = 2$, $h(7) = 0$. $h(4) = 4$ olur, ama 4. gözde 25 vardır: çakışma oluşur.

**Soru 10** (derste sözlü, 01:49:28): Bir sayının $\bmod 1$ değeri neyi verir?

> **Çözüm (derste verildi):** Sayının ondalık kısmını.

**Soru 11** (ekrandan, 01:50:00): $m = 10000$, $A = \frac{\sqrt5-1}{2}$ iken çarpma yöntemiyle $h(123456)$ değerini bulun.

> **Çözüm (derste verildi):** $123456 \cdot A = 76300{,}0041151\ldots$, ondalık kısım $0{,}0041151$, $\lfloor 10000 \cdot 0{,}0041151 \rfloor = 41$ (python ile doğrulandı; $A$'nın tam değeriyle).

## Dersin Toparlaması

Bu derste azaltarak yönetme (decrease and conquer) yaklaşımının üç türü örnekleriyle işlendi. Sabit miktarda azaltmanın örneği olarak topolojik sıralama ayrıntılı anlatıldı: işler yönlü bir çizgeyle gösterilir, her düğümün giriş derecesi tutulur, derecesi 0 olan işler yapılır ve komşuların derecesi azaltılır. Çizgede yönlü döngü varsa sıralama yapılamaz. Kuyruk kullanımı, derecesi 0 olanları arama maliyetini ortadan kaldırarak karmaşıklığı $O(|V|^2 + |E|)$'den $O(|V| + |E|)$'ye indirir. Sabit oranda azaltmanın örneği ikili arama ($T(n) = T(n/2) + c$, $O(\log n)$), değişken miktarda azaltmanın örneği Öklid algoritmasıdır.

Dersin son bölümünde hashing'e giriş yapıldı. Bilinen arama yöntemlerinin en iyi ihtimalle $\log n$'e indiği, hashing'in ise arama, ekleme ve silmeyi $O(1)$ ile yapmayı hedeflediği gösterildi. Hash fonksiyonunun kolay hesaplanabilir ve tutarlı olması gerektiği, bölme ve çarpma yöntemleri örneklerle anlatıldı. Başarılı bir hash için tablo boyutu, hash fonksiyonu ve çakışma çözümü sorularının doğru planlanması gerekir. Çakışmanın nasıl çözüleceği ve elemanların tabloya yerleştirilmesi sonraki derse bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
