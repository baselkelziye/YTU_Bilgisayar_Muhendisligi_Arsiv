# Ders 12 Genişletilmiş Notu: Sınav Sorularının Çözümü, Öncelikli Kuyruk ve Heap, P-NP Problem Sınıfları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sınav Sorularının Çözümü: Kavram Soruları
- 2. Sınav Sorusu: Dizgi Üzerinde Kabarcık Sıralaması
- 3. Sınav Sorusu: Yarıya İndirerek $\lfloor \log_2 n \rfloor$ Hesaplama
- 4. Sınav Sorusu: Robotla Para Toplama (Dinamik Programlama)
- 5. Öncelikli Kuyruk (Priority Queue)
- 6. Heap Veri Yapısı
- 7. Heap'e Ekleme ve Yukarı Yığınlaştırma
- 8. Kök Alma ve Aşağı Yığınlaştırma
- 9. Problem Sınıfları: P, NP, NP-Complete, NP-Hard
- 10. Belirlenimci Olmayan Algoritmalar
- 11. Polinom İndirgeme
- 12. Dersin Genel Değerlendirmesi: Algoritma Tasarım Yaklaşımları
- Örnek Sorular
- Dersin Toparlaması

## 1. Sınav Sorularının Çözümü: Kavram Soruları

Dersin ilk bölümünde hoca yapılan sınavın sorularını çözdü. Bazı soruları kod üzerinden, bazılarını ekrana yazarak gösterdi. Kayıt Zoom üzerinden yapılmış bir çevrim içi derstir; hoca ekranında Dev-C++ ve PowerPoint'in çizim modunu kullandı.

İlk soru kısa kavram tanımlarıydı:

- **Kaba kuvvet (brute force):** Bütün olasılıkların tek tek denenip sonuca ulaşılması yöntemidir. Genelde "aklımıza ilk gelen yöntem" diye anılır, ama bu bir tanım değildir; insanın aklına bazen ilk olarak dinamik programlama da gelebilir. Tanımın özü, bütün olasılıkların denenmesidir.
- **En kötü durum analizi:** Algoritmanın en kötü çalışma koşullarında harcayacağı zaman ya da bellek miktarıdır. Yalnız zaman açısından değerlendirmek eksiktir; hem zaman hem bellek konuşulmalıdır.
- **Büyük Omega ($\Omega$):** Algoritmanın en iyi koşullar altında zaman ya da bellek açısından nasıl davrandığını söyler.
- **Azalt ve fethet (decrease and conquer):** Problemi daha küçük boyutlu bir örneğine indirip onu çözmektir. Küçültme sabit bir sayı çıkararak (ör. $n \to n-1$) ya da sabit bir sayıya bölerek (ör. $n \to n/2$) yapılabilir; cevapta bu açıklama bekleniyordu. Hoca öğrencilerin çoğunun ikili arama (binary search) örneğini verdiğini söyledi. <!-- BELİRSİZ: hocanın ikili arama örneği hakkındaki yorumu altyazıda bozuk ("divide by Concuradur. Azalt, Theta daha geniş bir kavramdır"); örneği hangi sınıfa koyduğu net değil. -->

İkinci kavram sorusu, iki algoritma verildiğinde hangisinin daha verimli olduğunu karşılaştırmak için yapılması gerekenlerdi. Hocanın cevabı:

- İki algoritmanın zaman ve bellek karmaşıklıkları analiz edilir.
- Algoritmaların doğruluğuna bakılır.
- Zaman ve bellek karmaşıklığı en iyi, en kötü ve ortalama durum için ayrı ayrı incelenir.
- Algoritmanın hangi koşullar altında çalışacağı (kısıtlı koşullarda mı, daha parametrik mi) belirtilir.

## 2. Sınav Sorusu: Dizgi Üzerinde Kabarcık Sıralaması

### 2.1 Soru ve kod

Soru, bir metni (karakter dizisini) kabarcık sıralamasıyla (bubble sort) sıralayan bir fonksiyon istiyordu. Hoca, sorunun dizgi için sorulduğunu ama bazı cevaplarda tamsayı dizisi kullanıldığını hatırlattı; soruyu dikkatle okumak gerekir. `main` ya da fonksiyon çağrısı istenmemişti; dizinin uzunluğu fonksiyon içinde `strlen` ile hesaplanabilir ya da $n$ ayrı parametre olarak gönderilebilir, ikisi de kabul edildi.

Kabarcık sıralaması ikili karşılaştırma yapar: birinci ile ikinci, ikinci ile üçüncü eleman karşılaştırılır ve sıra bozuksa yer değiştirilir. Her turun sonunda o turdaki en büyük eleman sona gider. En iyi durumda (dizi zaten sıralıysa) hiç yer değiştirme olmaz. Bu durumda işlemin gereksiz yere sürmemesi için bir `swapped` değişkeni kullanılır: her turun başında 0 yapılır, tur içinde en az bir kez yer değiştirme olursa 1 olur. Tur sonunda `swapped` 1 ise dizide hâlâ düzensizlik olabilir ve bir tur daha dönülür; 0 ise dizi sıralıdır.

Hocanın sınav klasöründeki çözümde döngü `while(swapped && i<N)` biçimindeydi ve `swapped` başta 1 yapılıyordu (ekrandan, 00:15:00). Gövde en az bir kez çalışacağı için hoca bunu `do-while`'a çevirdi; böylece başlangıçtaki `swapped=1` atamasına gerek kalmaz (ekrandan, 00:20:00):

```c
do{
    swapped=0;
    for(j=0;j<N-i-1;j++){
        c++;
        if(dizi[j]>dizi[j+1]){
            tmp=dizi[j];
            dizi[j]=dizi[j+1];
            dizi[j+1]=tmp;
            swapped=1;
        }
    }
    i++;
} while(swapped && i<N);
```

Burada `N = strlen(dizi)`, `c` ise karşılaştırma sayacıdır. Hoca programı derleyip iki dizgiyle denedi: en kötü durum olan ters sıralı "FEDCBA" 15 karşılaştırmayla, en iyi durum olan sıralı "ABCDEF" 5 karşılaştırmayla "ABCDEF" olarak sıralandı. (Bu parça ajan tarafından küçük bir `main` ile `gcc -Wall` kullanılarak derlenip denendi; aynı sayılar çıktı.)

### 2.2 En kötü durumun matematiksel analizi

Sorunun (a) maddesi en kötü durum analizini matematiksel yöntemle istiyordu. Önce temel işlem belirlenir: algoritmanın bütün çalışması boyunca kesinlikle çalışacak işlem. Kabarcık sıralamasında bu yer değiştirme değil, karşılaştırmadır (yer değiştirme yalnız sıra bozuksa yapılır). Her karşılaştırmaya 1 maliyet verilir.

Dış döngü $i = 0$'dan $n-1$'e (dahil değil), iç döngü $j = 0$'dan $n-i-1$'e (dahil değil) döner. Hoca tahtada şunu yazdı (ekrandan, 00:20:00):

$$\sum_{i=0}^{n-1} \sum_{j=0}^{n-1-i} 1 = \sum_{i=0}^{n-1} (n-i) = n \cdot n - \frac{(n-1)n}{2} = \frac{2n^2 - n^2 + n}{2} = \frac{n^2+n}{2}$$

ve algoritmanın $O(n^2)$ olduğunu söyledi.

> **Ders sonrası not:** Kodda iç döngünün koşulu `j < N-i-1` olduğundan üst sınır dahil değildir ve iç döngü $n-1-i$ kez döner. Ayrıca son turda ($i = n-1$) iç döngü hiç dönmez. Doğru sayım $\sum_{i=0}^{n-2}(n-1-i) = \frac{n(n-1)}{2}$'dir. $n = 6$ için bu 15 eder ve derste çalıştırılan programın "FEDCBA" için verdiği 15 karşılaştırmayla uyuşur ($\frac{n^2+n}{2}$ ise 21 verirdi). Büyük O sonucu, $O(n^2)$, değişmez.

### 2.3 En iyi durum

Hoca, en iyi durum sorulsaydı cevabın nasıl olacağını da gösterdi. Bu durumda `swapped` değişkeni belirleyicidir: ilk turda hiç yer değiştirme olmaz, `swapped` 0 kalır ve dış döngü yalnız bir kez döner. İç döngü bu tek turda $n-1$ kez çalışır (sıralı "ABCDEF" için 5 karşılaştırma). Sonuç $O(n)$'dir.

## 3. Sınav Sorusu: Yarıya İndirerek $\lfloor \log_2 n \rfloor$ Hesaplama

### 3.1 Yineleme bağıntısı ve kod

Soru, yarıya indirme (decrease by half) yöntemiyle $\lfloor \log_2 n \rfloor$'i hesaplayan fonksiyonu istiyordu. Hoca, bu fonksiyonu yazabilmek için önce yineleme bağıntısının (recurrence relation) kurulması gerektiğini, bağıntı olmadan bunu yapabilenin tebrik edilmesi gerektiğini söyledi; bağıntı (a) maddesinde isteniyordu.

$\log$ herhangi bir tabanda 1 için 0'dır; dolayısıyla $n \le 1$ ise fonksiyon 0 döndürür. Aksi halde 1 ekleyip problemin yarısını çağırır:

$$f(n) = \begin{cases} 0, & n \le 1 \\ 1 + f(\lfloor n/2 \rfloor), & n > 1 \end{cases}$$

Kodlaması bundan sonra çok kolaydır: `if (n <= 1) return 0; else return 1 + f(n/2);`. Tamsayı bölmesi aşağı yuvarlamayı kendiliğinden yapar.

### 3.2 Çağrı zinciri

Hoca 1024 ile denedi ve çağrıları tahtaya yazdı (ekrandan, 00:25:00):

```text
f(1024) = 1 + f(512)
               = 1 + f(256)
                      = 1 + f(128)
                             ...
                               = 1 + f(2)
                                      = 1 + f(1) = 1 + 0
```

Geri dönüşte birler toplanır: 1, 2, 3, ... ve sonuç 10 çıkar. (Ajan aynı fonksiyonu C ile denedi: $f(1024) = 10$, $f(1000) = 9$, $f(7) = 2$, $f(1) = 0$.)

### 3.3 Geriye doğru yerine koyma

Soru analizi geriye doğru yerine koyma (backward substitution) ile istiyordu. Maliyet bağıntısı:

$$T(n) = 1 + T(n/2)$$

Yerine koyarak:

$$T(n) = 1 + 1 + T(n/4) = 1 + 1 + 1 + T(n/8) = \dots = i \cdot 1 + T\!\left(\frac{n}{2^i}\right)$$

Özyineleme $n/2^i = 1$ olduğunda durur; buradan $i = \log_2 n$ bulunur. $T(1) = 0$ olduğu için $T(n) = \log_2 n$, yani $O(\log n)$.

### 3.4 Master teoremi

Aynı sonuç Master teoremiyle de bulunur. $T(n) = a\,T(n/b) + f(n)$, $f(n) \in \Theta(n^d)$ biçiminde:

- $a = 1$: bağıntıda özyinelemeli çağrının önündeki katsayı (tek çağrı var).
- $b = 2$: problemin kaça bölündüğü.
- $d = 0$: ek maliyet sabit (1), $n^0$ biçiminde yazılır.

$a = b^d$ ($1 = 2^0$) durumu geçerlidir; bu durumda $T(n) \in \Theta(n^d \log n) = \Theta(n^0 \log n) = \Theta(\log n)$.

> **Hocanın vurgusu:** Tam puan için bu iki yolun (uzun yol: yerine koyma; kısa yol: Master teoremi) aynı sonucu verdiğini göstermek gerekiyordu.

## 4. Sınav Sorusu: Robotla Para Toplama (Dinamik Programlama)

### 4.1 Problem

Bu soru bir robotla para toplama (coin collecting) problemidir; soruda robotun topladığı şey havuçtu. Robot tablonun sol üst köşesinden başlar ve sağ alt köşeye ulaşana kadar yalnız sağa ya da aşağıya gidebilir; amaç en fazla parayı toplamaktır. Tablo 5 satır ve 6 sütundur; paraların konumları (satır, sütun) şunlardır (ekrandan, 00:30:00):

```text
       1   2   3   4   5   6
  1    .   .   .   .   x   .
  2    .   x   .   x   .   .
  3    .   .   .   x   .   x
  4    .   .   x   .   .   x
  5    x   .   .   .   x   .
```

Hoca, bu yineleme bağıntısının derste yapılan örneklere çok benzediğini, dersteki örnekleri inceleyenlerin zorlanmamış olması gerektiğini söyledi.

### 4.2 Yineleme bağıntısı

Herhangi bir $(i,j)$ hücresine en büyük kârla gelmek için, oraya gelinebilen iki komşudan büyük olanı seçmek gerekir: üstteki $(i-1, j)$ ya da soldaki $(i, j-1)$. Hangisi daha büyükse robot oradan gelmiş demektir. $P$ kâr (profit) tablosu, $M$ ise para tablosudur ($M(i,j) = 1$ ise o hücrede para var):

$$P(i,j) = \max\{P(i-1,j),\ P(i,j-1)\} + M(i,j)$$

Başlangıç koşulları (ekrandan, 00:35:00):

- İlk satırda bir üst hücre yoktur; ilk satırdaki bir hücreye yalnız soldan gelinir: $P(1,j) = P(1,j-1) + M(1,j)$.
- İlk sütunda sol hücre yoktur; yalnız yukarıdan gelinir: $P(i,1) = P(i-1,1) + M(i,1)$.

Hoca önce bu formüllerde $M$ yerine yanlışlıkla $P$ dedi, sonra düzeltti: önceki hücrenin kârına ($P$) içinde bulunulan hücrenin parası ($M$) eklenir.

### 4.3 Tablonun doldurulması

Tabloyu doldurmak için bir döngü ilk satırı, bir döngü ilk sütunu, iç içe iki döngü ($i$ ve $j$ ikiden başlayarak) geri kalanı doldurur. Hoca tabloyu elle doldurdu: ilk satırda 5. sütuna kadar para olmadığı için 0, 0, 0, 0, sonra 1, 1; ilk sütunda 5. satıra kadar 0, son hücrede 1. Sonra her hücre için "iki komşunun en büyüğünü al, bu hücredekini ekle" kuralı uygulandı. Sonuç tablosu (ekrandan, 00:35:00; ajan Python ile doğruladı):

| $i \backslash j$ | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| 1 | 0 | 0 | 0 | 0 | 1 | 1 |
| 2 | 0 | 1 | 1 | 2 | 2 | 2 |
| 3 | 0 | 1 | 1 | 3 | 3 | 4 |
| 4 | 0 | 1 | 2 | 3 | 3 | 5 |
| 5 | 1 | 1 | 2 | 3 | 4 | 5 |

Robotun toplayabileceği en fazla para $P(5,6) = 5$'tir.

### 4.4 Rotanın bulunması

Sorunun bir maddesi robotun rotasını adım adım göstermeyi istiyordu. Rota sağ alt köşeden geriye doğru bulunur: $i$ $m$'den, $j$ $n$'den başlatılır ve her adımda iki komşudan büyük olanına gidilir. Hoca tahtaya "5,6 → 4,6 → 3,5 → 3,4 → 2,4" yazdı ve tablodaki ilgili hücreleri daire içine aldı (ekrandan, 00:35:00).

> **Ders sonrası not:** (4,6)'nın komşuları $P(3,6) = 4$ ve $P(4,5) = 3$ olduğundan geriye izleme (4,6)'dan (3,6)'ya gider; (3,5)'e ancak (3,6)'dan sonra varılır. Tahtadaki dairelerde (3,6) işaretli, yazılı listede atlanmış. Tam rota: (5,6) ← (4,6) ← (3,6) ← (3,5) ← (3,4) ← (2,4) ← (2,3) ← (2,2) ← (1,2) ya da (2,1) ← (1,1).

Hoca, başta iki komşunun da 0 olduğu yerde robotun iki yoldan birinden gelmiş olabileceğini, bu yüzden bunun "olası bir rota" olduğunu belirtti. Toplanan paralar (2,2), (2,4), (3,4), (3,6), (4,6) hücrelerindedir; toplam 5, tablonun söylediğiyle aynı.

### 4.5 Karmaşıklık

Tabloyu doldurmak için $m \times n$'lik bir matris doldurulur: zaman karmaşıklığı $O(mn)$. Bellek için de aynı boyutta bir matris gerekir: $O(mn)$. Bütün değerler kesinlikle dolduğu için ikisi de $\Theta(mn)$ diye yazılabilir.

> **Hocanın vurgusu:** Yineleme bağıntısı ortaya çıktıktan sonra her şey çok kolaydır. Bu soru derste yapılan üç-dört örneğe (knapsack, coin-row vb.) benziyor.

**Soru:** Knapsack'taki gibi başa sıfırlarla dolu ek bir satır ve sütun koyarak çözmek doğru mu? **Cevap:** Knapsack'ta $W$ gibi ek bir parametre (kapasite) vardır. Burada öyle bir parametre yoktur; tek kısıt robotun sağa ya da aşağı gitmesidir. $W$ gibi bir parametre olsaydı ek satır/sütun yaklaşımı doğru olurdu; burada ilk satır ve sütun doğrudan başlangıç koşullarıyla doldurulmalıdır, aksi halde ilk satır ve sütundaki paralar hesaba katılmamış olabilir.

## 5. Öncelikli Kuyruk (Priority Queue)

### 5.1 Tanım

Hoca, dönemin kalan iki konusundan ilki olarak öncelikli kuyruğu anlattı. Normal bir kuyrukta front'tan çıkarılır, rear'dan eklenir. Öncelikli kuyrukta ise ekleme yeri gelen değere göre değişir. Ekrandaki örnekte (ekrandan, 00:40:00) kuyruk boşken 5 gelir; sonra 8 gelir; sonra 3 gelir. 3 normalde sona eklenmesi gerekirken önceliği yüksek olduğu için öne geçer; kuyruk 3, 5, 8 sırasına girer. İşletim sistemlerinde bazı öncelikli süreçlerin kuyrukta öne alınması buna örnektir.

### 5.2 Dizi ve bağlı listeyle gerçekleme

Bu yapı bir dizi ya da bağlı listeyle gerçeklenirse, verinin front'un gösterdiği yere ya da araya eklenmesi gerekebilir ve kuyruğun yapısı yeniden düzenlenir. Ekleme işleminin durumları (ekrandan, 00:40:00 ve 00:45:00):

- **Durum 1, front'un gösterdiği yere ekleme:** Dizide 1 ekleme ve ardından kalan elemanlar için $n$ kaydırma (shift) gerekir: $1 + n = O(n)$. Bağlı listede kaydırma gerekmez: $1 + 0 = O(1)$.
- **Durum 2, rear'ın gösterdiği yere ekleme:** Rear kuyruğun sonundadır; bir ekleme yeterlidir, kaydırma yoktur. Dizide de bağlı listede de $O(1)$.
- **Durum 3, araya ekleme:** Durum 1'e benzer; dizide $n$ kaydırma gerekir, $O(n)$; bağlı listede $O(1)$.

Bütün bunlardan önce elemanın yerinin bulunması (find location) gerekir. Yer bulma en iyi durumda $\Omega(1)$'dir (rear'ın gösterdiği yere eklenecekse), en kötü durumda $O(n)$'dir (front'a kadar aranacaksa).

Genel değerlendirme: en kötü durumda yer bulmak $O(n)$, dizide kaydırma da $O(n)$; toplam $2n$, yani $O(n)$. Öncelikli kuyruğu $n$ eleman için doldurmak (sıralı ekleme) bu yüzden $O(n^2)$'ye çıkar. Hoca "bunu daha iyi hale getirebilir miyiz?" diye sordu; cevap heap veri yapısıdır.

## 6. Heap Veri Yapısı

### 6.1 Tanım ve kurallar

Heap aslında bir ikili ağaçtır (binary tree), ama dengeli (balanced) bir yapıdadır (ekrandan, 00:45:00):

- Bir kök düğüm vardır. Yeni düğümler önce birinci seviyeye, sonra ikinci seviyeye eklenir; bir seviye dolmadan başka bir seviye doldurulmaz. Bir seviyede de önce sol, sonra sağ doldurulur.
- **Max-heap:** Ebeveyn (parent) her zaman çocuklarından (children) büyüktür.
- **Min-heap:** Ebeveyn her zaman çocuklarından küçüktür.

İkili arama ağacından (binary search tree) farkı şudur: ikili arama ağacında sol-sağ (büyüklük-küçüklük) ilişkisi vardır; heap'te yalnız alt-üst (ebeveyn-çocuk) ilişkisi vardır.

**Soru:** Tahtadaki ağaç heap özelliği göstermiyor gibi; sol çocuk sağ çocuktan büyük olabiliyor? **Cevap:** Heap ağacında sol-sağ ilişkisi yoktur. Min-heap'te çocuklar ebeveynden büyük, max-heap'te küçük olmalıdır; o kadar. Önemli olan ağacın dengeli olmasıdır: sırası gelmeden başka bir yere eleman eklenemez; çıkarma sonrasında da denge korunur.

### 6.2 Örnek min-heap

Hoca sırayla 5, 8, 11, 13, 9, 20, 30, 40 ekleyerek bir min-heap kurdu (ekrandan, 00:50:00). İlk gelen 5 köke yerleşir; 8 kökün soluna, 11 sağına; 13 ve 9, 8'in çocukları; 20 ve 30, 11'in çocukları; 40 da 13'ün sol çocuğu olur. Her eklemede düzenin bozulup bozulmadığı kontrol edilir; bu örnekte bozulma olmaz.

```text
              5 (0)
           /       \
        8 (1)      11 (2)
        /   \       /   \
    13 (3) 9 (4) 20 (5) 30 (6)
     /
  40 (7)
```

Kök sürekli çıkarılırsa ilk çıkan eleman en küçük olan 5'tir. Bu bir öncelikli kuyruk davranışıdır; ayrıca kök çekilip ağaç her seferinde yeniden düzenlenirse elemanlar sıralı çıkar. Heap sort algoritması buradan doğar.

### 6.3 Dizide saklama

**Soru (hocadan):** İkili arama ağaçları C'de dinamik olarak nasıl gerçeklenir? **Cevap (bir öğrenci):** `struct` ile; hoca doğruladı: sol çocuk ve sağ çocuk işaretçileri olan bir yapıyla. İkili arama ağacında büyüklük-küçüklük ilişkisi yüzünden dengesiz ağaç oluşabilir; dengeyi sağlamak için AVL ve kırmızı-siyah (red-black) ağaçlar kullanılır.

Heap ise kendiliğinden dengeli olduğu için struct'a ya da bağlı liste mantığına gerek yoktur; `malloc` ile oluşturulan $n$ elemanlı dinamik bir dizi yeterlidir. Kök 0. eleman, sol çocuğu 1., sağ çocuğu 2. eleman olur; sonra 3, 4, 5, 6, 7 diye devam eder, çünkü elemanlar zaten bu sırayla eklenir. Yukarıdaki heap dizide `5 8 11 13 9 20 30 40` olarak saklanır (ekrandan, 00:50:00).

### 6.4 İndis formülleri

Hoca, ödevde de kullanılacak olan indis ilişkilerini çıkardı (ekrandan, 00:55:00):

$$LC(i) = 2i + 1, \qquad RC(i) = 2i + 2, \qquad P(i) = \left\lfloor \frac{i-1}{2} \right\rfloor$$

**Soru (hocadan):** $i$. düğümün sol çocuğu nasıl hesaplanır? **Cevap (bir öğrenci):** $2i+1$; hoca doğruladı. Örneğin 11 indis 2'dedir; sol çocuğu indis $2 \cdot 2 + 1 = 5$'teki 20'dir.

Ebeveyn formülü sol çocuk formülünün tersidir. Tamsayı bölmesi kullanıldığı için sağ çocuk için de çalışır: indis 6'daki 30'un ebeveyni $(6-1)/2 = 2{,}5 \to 2$, yani 11'dir; indis 5'teki 20'nin ebeveyni de $(5-1)/2 = 2$'dir.

Bu fonksiyonlar ayrı yazılabilir: `getLC(i)` $2i+1$, `getRC(i)` $2i+2$, `getP(i)` $(i-1)/2$ döndürür.

### 6.5 Heap işlemleri

- **Düğüm ekleme (add node):** Yeni düğüm önce ağacın en son eklenebilecek yerine eklenir; ağaç heap özelliğini kaybettiyse yeniden heap haline getirilir. Yani ekleme iki adımlıdır: ekleme + yığınlaştırma (heapify). Burada yığınlaştırma aşağıdan yukarıya yapıldığı için "heap up" (yukarı yığınlaştırma) denir.
- **Kök alma (get root / remove root):** Heap'lerde genellikle aradan bir düğüm silinmez; kök çıkarılır. Bu, öncelikli kuyruğun önünden bir eleman çıkması gibidir; min-heap'te en küçük eleman çıkar. Sonra yerine gelen elemanın heap düzenini bozup bozmadığına bakılır.
- **Gezinme (traverse):** İkili arama ağaçlarındaki preorder, inorder gibi gezinmeler yerine dizi baştan sona yazdırılır.

Heap'te en küçük eleman köktedir. Sonraki en küçük iki eleman kökün iki çocuğundan biridir; ondan sonrakiler kalan dört elemandan biridir. Kök her çıkarıldığında kalanların en küçüğü başa getirilerek öncelikli kuyruk yapısı yeniden garanti edilir.

## 7. Heap'e Ekleme ve Yukarı Yığınlaştırma

### 7.1 Ekleme fonksiyonu

Hoca örnek heap'te 40 yerine 2 eklemeyi ele aldı (heap: `5 8 11 13 9 20 30`). Ekleme fonksiyonu heap dizisini ($A$), mevcut eleman sayısını ($N$), kapasiteyi ($MAX$) ve eklenecek elemanı ($e$) alır (ekrandan, 01:00:00):

```text
void Add(A, N, MAX, e)
    if (MAX == N)
        return (FULL)
    else
        N++
        A[N-1] = e
        HeapUp(A, N-1)
        SUCCESSFUL
```

$MAX = N$ ise dizi doludur ve bir şey yapılmaz. Değilse eleman sayısı bir artırılır, $e$ dizinin $N-1$. hücresine yazılır ve bu indisten başlayarak yukarı yığınlaştırma çağrılır.

### 7.2 Yukarı yığınlaştırma (heap up)

Eklenen 2 ile ebeveyni 13'ü karşılaştırmak için önce 2'nin ebeveyninin indisi bulunur. 2 ebeveyninden küçükse yer değiştirilir ve aynı fonksiyon bu kez ebeveyn indisi için özyinelemeli çağrılır. Ağacın başka dallarına hiç dokunulmaz. Hocanın anlattığı fonksiyon:

```text
void HeapUp(A, i)
    if (i == 0) return
    p = getP(i)
    if (A[p] > A[i])
        swap(A[p], A[i])
        HeapUp(A, p)
```

<!-- BELİRSİZ: Karelerde HeapUp'ın yalnız ilk iki satırı ("void HeapUp(A, i)", "i == 0 return") görünüyor; kalan satırlar altyazıdaki anlatımdan (00:59:38-01:01:07) kuruldu. -->

$i = 0$ ise eleman köktür (ağaçta ilk elemandır) ve yığınlaştırmaya gerek yoktur.

### 7.3 Adım adım örnek

2 eklendiğinde (ajan C ile doğruladı):

1. 2 indis 7'ye yazılır. Ebeveyni $(7-1)/2 = 3$; $A[3] = 13 > 2$, yer değiştirilir. HeapUp(A, 3) çağrılır.
2. İndis 3'ün ebeveyni $(3-1)/2 = 1$; $A[1] = 8 > 2$, yer değiştirilir. HeapUp(A, 1) çağrılır.
3. İndis 1'in ebeveyni 0; $A[0] = 5 > 2$, yer değiştirilir. HeapUp(A, 0) çağrılır.
4. $i = 0$ olduğu için dönülür. Çağrılar sırayla (2'ye 1, 2'ye 3, 2'ye 7) geri döner; en son Add "başarılı" mesajını yazar.

Sonuç dizisi: `2 5 11 8 9 20 30 13`. Yeni düğüm eklendi ve heap düzeni bozulmadı.

**Soru:** `p = getP(i)` satırı ne yapıyor? **Cevap:** Ebeveynin indisini elde eder; yukarıda yazılan $(i-1)/2$ fonksiyonudur.

**Soru:** Ebeveynin diğer çocuğuna da bakıp karşılaştırmak gerekmez mi? Örneğin 13'ün yerine 10 gelse? **Cevap:** 10 eklendiğinde yalnız ebeveyni 13 ile karşılaştırılır; 10 < 13 olduğu için yer değiştirir. Sonra 10 ile ebeveyni 8 karşılaştırılır; 10 > 8 olduğu için orada kalır ve işlem biter. Heap'te kardeşler arası ilişkiye bakılmaz; yalnız ebeveyn-çocuk ilişkisine bakılır. İkili arama ağacıyla karşılaştırmamak gerekir.

> **Hocanın vurgusu:** Aşağıdan yukarıya heap up mekanizması önemlidir; buna dikkat etmek gerekir.

## 8. Kök Alma ve Aşağı Yığınlaştırma

### 8.1 Kök alma fonksiyonu

Kök, öncelikli kuyruktan bir eleman çıkarmak ya da heap sort gibi bir sıralama yapmak için alınır; sonra ağaç yeniden düzenlenir. Hoca 8, 9, 11, 13, 35, 20 elemanlı bir min-heap üzerinde anlattı (ekrandan, 01:20:00):

```text
            8
          /   \
         9     11
        / \    /
      13  35  20
```

Fonksiyon diziyi, eleman sayısını ($N$, işaretçi olarak) ve çıkan elemanın yazılacağı $e$'yi (işaretçi olarak) alır (ekrandan, 01:25:00):

```text
void GetRoot(A, int *e, int *N)
    if (N == 0)
        return Empty
    *e = A[0]
    A[0] = A[N-1]
    N--
    HeapifyDown(A, 0, N)
```

Ağaç boşsa bir şey döndürülmez. Değilse kök $e$'ye yazılır. Kökün yerine ne geleceği sorusunda hoca ikili arama ağaçlarını hatırlattı: orada kök silinirken ağacın yapısı bozulmasın diye örneğin sağ alt ağacın en küçüğü alınır. Heap'te sol-sağ değil alt-üst ilişkisi vardır; bu ilişkiyi bozmamanın en kolay yolu dizinin son elemanını ($A[N-1]$) köke taşımaktır. Ortadaki bir elemanı alsaydık başka elemanları kaydırmak gerekirdi. Sonra eleman sayısı bir azaltılır; dizide eski değer fiziksel olarak durur ama artık eleman sayısının dışındadır. Son olarak kökten (indis 0) aşağı doğru yığınlaştırma (heapify down) yapılır.

### 8.2 Aşağı yığınlaştırma

Bir düğüm için üç durum vardır: iki çocuğu da olmayabilir, yalnız sol çocuğu olabilir, iki çocuğu da olabilir. (Tek çocuk varsa bu kesinlikle sol çocuktur.) İki çocuğu yoksa bir şey yapılmaz. İki çocuğu varsa küçük olan seçilir, çünkü heap özelliği gereği küçük olanın yukarı çıkması gerekir; yığınlaştırma o taraftan devam eder.

Fonksiyon diziyi, $i$ indisini ve güncel eleman sayısı $N$'yi alır. $N$ dizinin kapasitesi değil, aktif eleman sayısıdır; çocuk indisinin $N$'den büyük ya da eşit olması o çocuğun olmadığı anlamına gelir. Sağ çocuktan başlanır, çünkü sağ varsa sol kesinlikle vardır (ekrandan, 01:25:00):

```text
HeapifyDown(A, i, N)
    L = LC(i)
    R = RC(i)
    if (Right >= N) {
        if (Left >= N) return
        else min = left
    }
    else if (A[left] < A[right]) min = left
    else min = right
    Swap(A[i], A[min])
    HeapifyDown(A, min, N)
```

Hoca anlatımda, yer değiştirmeden önce $A[i]$ ile $A[min]$'in değerlerine bakılıp büyüklük-küçüklük ilişkisi bozuksa yer değiştirileceğini söyledi (01:25:27); bu kontrol tahtadaki kodda ayrı satır olarak yazılmadı.

> **Ek bilgi (derste anlatılmadı):** Bu karşılaştırma ($A[i] > A[min]$ ise yer değiştir, değilse dur) olmadan da sonuç heap olur, ancak düğüm zaten doğru yerdeyken gereksiz yer değiştirmeler yapılır ve dizi bozulabilir. Ajanın denediği C sürümünde bu kontrol `if (A[i] > A[min])` biçiminde eklendi.

### 8.3 Adım adım örnek

Kök 8 alınır; son eleman 20 köke taşınır ve eleman sayısı 5 olur:

1. HeapifyDown(A, 0): çocuklar indis 1 (9) ve 2 (11). Küçük olan 9; 20 ile 9 yer değiştirir. HeapifyDown(A, 1) çağrılır.
2. HeapifyDown(A, 1): çocuklar indis 3 (13) ve 4 (35). Küçük olan 13; 20 ile 13 yer değiştirir. HeapifyDown(A, 3) çağrılır.
3. HeapifyDown(A, 3): çocuk indisleri 7 ve 8, ikisi de eleman sayısının dışında; dönülür. Çağrılar sırayla geri döner.

Heap: `9 13 11 20 35`.

> **Ders sonrası not:** Hoca bu adımda eleman sayısını "4" diye söyledi; 6 elemandan biri çıkınca 5 eleman kalır (indisler 0-4). İşlem sırası değişmez.

Sonra 9 çıkarılır. **Soru (hocadan):** 9'un yerine kim gelecek? Bir öğrenci 11 dedi, bir başka öğrenci 35 dedi; doğrusu 35'tir, çünkü dizinin (heap ağacının) en sonundaki eleman köke gelir. 35'in çocukları 13 ve 11; küçük olan 11 ile yer değiştirir. Sonra indis 2'nin çocuğu kalmadığı için dönülür: `11 13 35 20`. 11 çekilirse yerine 20 gelir ve 13 ile yer değiştirir: `13 20 35`. Sonra 13, 20, 35 sırayla çıkar. Böylece elemanlar artan sırada çıkar: 8, 9, 11, 13, 20, 35 (ajan C ile doğruladı).

### 8.4 Hocanın C denemesi

Hoca dersten önce yazdığı `heap.c` programını gösterdi (ekrandan, 01:30:00 ve 02:25:00). Program `malloc` ile bir dizi oluşturuyor, sırayla 3, 4, 2, 5, 6 ekliyor ve diziyi yazdırıyor; çıktı `2 4 3 5 6` oldu. Hoca bunu yorumladı: kök 2 en küçük; çocukları 4 ve 3, sonraki iki en küçük; kalanlar 5 ve 6. Sonra kökleri sırayla çekmeye çalıştı; 2, 3, 4 sıralı çıktı ama 5 ve 6 çıkmadı. Hoca bir yerde işaretçiyle ilgili bir hata yaptığını düşündüğünü, sonra bakacağını söyledi.

Ekrandaki ana döngü şuydu:

```c
for(i=0;i<n;i++){
    getRoot(A, &n, &e);
    printf("%d ",e);
}
```

> **Ders sonrası not:** Sorun büyük olasılıkla işaretçide değil, bu döngüdedir: `getRoot` her çağrıda `n`'yi bir azaltırken `i` bir artar. 5 elemanla $i=0$ ($n$: 5→4), $i=1$ ($n$: 4→3), $i=2$ ($n$: 3→2) çağrıları yapılır, sonra $i = 3 < 2$ koşulu sağlanmaz ve döngü biter; tam olarak 2, 3, 4 yazılır. Ajanın denediği C sürümünde aynı döngü 2 3 4, `while (n > 0)` döngüsü 2 3 4 5 6 verdi.

## 9. Problem Sınıfları: P, NP, NP-Complete, NP-Hard

### 9.1 Problem sınıfı kavramı

Hoca dönemin son konusunun çok teorik bir konu, aynı zamanda bir araştırma konusu olduğunu ve Hesaplama Kuramı dersiyle bağlantılı olduğunu söyledi. Konunun adı "problem class"tır; bazı yerlerde "algoritma sınıfı" denmesi yanlıştır. Bir algoritmanın P ya da NP olduğunu söylemek yanlış bir sınıflandırmadır; P ve NP problemler için kullanılır (ekrandan, 01:35:00).

- **P (polynomial):** Bir problemi çözmek için polinom zamanlı bir algoritma ya da çözüm varsa o problem P sınıfındandır. Bunlara izlenebilir (tractable) problemler denir.
- **NP (non-deterministic polynomial):** "N" olumsuzluk ("non-polynomial") anlamında değil, belirlenimci olmayan (non-deterministic) anlamındadır.
- **İzlenemez (intractable):** Polinom zamanda çözülemeyen problemler (not solved in polynomial time).

### 9.2 Polinom zaman

Verimli (efficient) algoritmalar polinom zamanlıdır: $O(1)$, $O(\log n)$, $O(n)$, $O(n \log n)$, $O(n^2)$, $O(n^3)$ gibi; $n$'nin bir polinomuyla ifade edilen zamanlar. Polinom olmayan zamanlar ise $O(n!)$, $O(n^n)$, $O(2^n)$ gibileridir.

Örneğin sıralama problemi polinom zamanda çözülür: kabarcık sıralamasıyla $n^2$'de, birleştirme (merge sort) ve heap sort ile $n \log n$'de. Bu yüzden sıralama izlenebilir bir problemdir. Gezgin satıcı problemi (TSP) ve Hamilton devresi ise kaba kuvvetle faktöriyel zamanda çözülüyordu; bunları çözen kaba kuvvet algoritmaları verimsiz (inefficient) algoritmalardır. Hoca, bu problemlerin bazı örneklerinin ya da bazı koşullar altında polinom zamanda çözülebildiğini, çözümün doğrulanmasının ise ayrı bir konu olduğunu belirtti.

### 9.3 Karar problemleri

Karar problemi (decision problem) cevabı evet/hayır olan problemdir. Ekrandaki örnek (ekrandan, 01:40:00): "Bir çizgenin üç renkle boyanıp boyanamayacağını kontrol et." Bu bir karar problemidir. "Bir çizge en az kaç renkle boyanır?" ise karar problemi değildir. Tahtaya ayrıca "P class is a class of decision problems" yazıldı.

Karar problemlerinin önemi şudur: verimsiz bir algoritmayla çözülebilen (izlenemez) bir problem için bir çözüm bulunduysa, bu çözümün doğru olup olmadığına polinom zamanda karar verilebiliyorsa farklı bir sınıf ortaya çıkar.

Hoca P sınıfındaki algoritmaların belirlenimci (deterministic) olduğunu da söyledi: her çalıştırmada aynı sonuç elde edilir.

> **Hocanın vurgusu:** Problemleri iki türe ayırmak önemlidir. Bir çizgeyi boyamak çok fazla zaman alabilir; çizgenin üç renkle boyanıp boyanamayacağının kontrolü ise farklıdır. Bu ayrıma dikkat etmek gerekir.

Hoca, bu problemlerin yalnız önümüzdeki bilgisayarlarla değil, hesaplama kuramındaki DFA, NFA ve Turing makinesi gibi soyut makinelerle de ele alındığını hatırlattı.

## 10. Belirlenimci Olmayan Algoritmalar

### 10.1 Belirlenimci olmayan arama

Belirlenimci olmayan (non-deterministic) bir algoritma her çalıştırmada farklı sonuç verebilir. Hoca bunu $n$ elemanlı bir $A$ dizisinde $x$ anahtarını bir seferde bulmaya çalışan bir arama ile gösterdi:

```text
NSearch(A, n, x)
    j = random(1, n)
    if (A[j] == x) then success
    else failure
```

Döngü yoktur; karmaşıklık $O(1)$'dir. Bulma ihtimali vardır ama her seferinde bulma garantisi yoktur. Burada bir doğrulama da yapılır: $j$'yi seçmek "eleman $j$. indistedir" iddiasıdır, `if` satırı bu iddiayı kanıtlar (verification).

### 10.2 Belirlenimci olmayan sıralama

Aynı fikir sıralamaya uygulandı (ekrandan, 01:45:00):

```text
NSort(A, B)
    B[i] <- 0                    (bütün elemanlar)
    for (i = 1 to N)
        j = rand(1, n) + 1
        if (B[j] != 0) then
            Failure
        B[j] = A[i]
    end for
    for i = 1 to N-1
        if B[i] < B[i+1] then
            Failure
    print B
```

İlk döngü $A$'nın her elemanını $B$'de rastgele seçilen bir yere koyar; seçilen yer doluysa algoritma başarısız olur. Örnek: $A = 2, 3, 1, 4$, $B$ başta $0, 0, 0, 0$. İlk seçimde 2 bir yere kopyalanır; ikinci seçimde aynı yer gelirse orası 0'dan farklı olduğu için başarısız olunur. Şans yaver giderse elemanlar $B$'ye bir şekilde yerleşir. Bu ilk döngü "problemi çözdüğümüz iddiası"dır. İkinci döngü bu iddiayı doğrular: $B$ gerçekten sıralı mı? Sıralı değilse başarısız, sıralıysa $B$ yazdırılır.

**Soru (hocadan):** İddianın maliyeti nedir? **Cevap (bir öğrenci):** $O(n)$. Hoca doğruladı: iddia $O(n)$'de sıraladığını söyler; doğrulama da $O(n)$'de yapılır.

Hoca bu algoritmanın gerçek bir sıralama algoritması olmadığını, kitapta da yer alan bir örnek olduğunu ve tekrar çalıştırıldığında farklı sonuç vereceğini söyledi.

**Soru:** Kodun ikinci satırında $f[i]$ yazılmış; $B[i]$ olmalı değil mi? **Cevap:** Evet, $B[i]$; ilk başta $B$'nin bütün elemanları sıfırlanır.

> **Ders sonrası not:** Tahtadaki doğrulama satırı `if B[i] < B[i+1] then Failure` biçimindedir; bu, büyükten küçüğe sıralamayı kontrol eder (hoca da "büyükten küçüğe sıralamaya bakmak lazım" dedi). Küçükten büyüğe sıralama için koşul `B[i] > B[i+1]` olmalıdır.

### 10.3 Belirlenimci olmayan algoritmanın aşamaları

Tahtadaki özet (ekrandan, 01:50:00):

- Belirlenimci olmayan algoritmanın üç temel adımı: (1) rastgele seçim (random choice), (2) başarı (success), (3) başarısızlık (failure).
- **Tahmin aşaması (guessing stage):** Belirlenimci değildir; her seferinde aynı sonucu vermez. Örneğin Hamilton devresi ya da gezgin satıcı problemi için önerilen bir çözüm, rastgele durumlara göre üretilir.
- **Doğrulama aşaması (verification stage):** Belirlenimcidir; aynı içerikle 100 kez çalıştırılsa da aynı sonucu verir.
- Çıktı başarısızlık (fail) ya da başarıdır (success).

### 10.4 En iyileme ve karar problemleri

En iyileme (optimization) problemleri doğrulanabilir ama belirlenimci olarak çözülmeleri sorunludur; bazılarında kesin çözüm (exact solution) imkansız olabilir, örneğin TSP. Hoca örnek verdi: Türkiye'deki 81 ilin bütün olasılıkları denenirse yaklaşık 80! durum çıkar; hepsi tek tek denenip en küçük maliyetli seçilmelidir ve bu polinom zamanda yapılabilecek bir şey değildir. Ancak en iyileme problemlerinden çıkan karar problemleri ("iki renge boyanabilir mi?", "gösterilen yol koşulları sağlıyor mu?") polinom zamanda çözülebilir (ekrandan, 01:50:00).

> **Hocanın vurgusu:** NP problemlerde doğrulama aşaması polinomdur (verification stage is polynomial).

### 10.5 P, NP, NP-complete ve NP-hard

Hoca sınıfları şöyle tanımladı (ekrandan, 01:55:00):

- Bir $X$ problemi için polinom zamanda çözüm sunan bir algoritma bulunduysa $X$ P tipi bir problemdir.
- $X$ için bir çözüm bulundu ama bu çözüm polinom olmayan zamanda bulunuyor; bulunan çözüm ise bir $A$ algoritmasıyla polinom zamanda doğrulanabiliyor. Bu bir NP problemidir. Polinom zamanda doğrulanabiliyor ama henüz polinom zamanda çözülemiyor demektir.
- Şemada P, NP'nin içinde bir küme olarak çizildi.
- **NP-complete:** Tahtada "çözüm NP, doğrulama P" yazıldı. Örnek olarak gezgin satıcı problemi verildi: 81 il için, İstanbul'un bütün ilçeleri için, dünyadaki bütün ülkeler için farklı problem örnekleri vardır. Hoca bazı indirgemelerin söz konusu olabileceğini ekledi.
- **NP-hard:** Tahtada "çözüm NP, P'de doğrulanamaz" yazıldı; çözüm polinom zamanda henüz bulunamamıştır ve doğrulaması da polinom zamanlı bir algoritmayla yapılamaz.

> **Ders sonrası not:** Standart tanımlarda NP-hard, NP'deki her problemin polinom zamanda indirgenebildiği problemler sınıfıdır; NP-hard bir problemin NP'de olması gerekmez. NP-complete ise hem NP'de hem NP-hard olan problemlerdir (şemadaki kesişim bölgesi). Gezgin satıcı probleminin karar biçimi ("maliyeti $k$'yi aşmayan tur var mı?") NP-complete, en iyileme biçimi NP-hard'dır.

Hoca bu konuda matematikçilerin de çalıştığını, çözülmemiş büyük problemler için ödüller bulunduğunu söyledi. NP-complete içinde birçok problem vardır; bunlardan birine polinom çözüm bulunursa diğerlerinin de otomatik olarak çözülebilir sınıfa geçeceği görüşü vardır. İnternette "P = NP?" diye aratılırsa bu konuda yazılar bulunur. Şu an NP'nin P'yi kapsadığı biliniyor; eşit olup olmadıkları açık bir sorudur ve bilgisayar bilimcilerinin çoğu eşit olamayacağı görüşündedir.

> **Ek bilgi (derste anlatılmadı):** Hocanın andığı ödüller büyük olasılıkla Clay Matematik Enstitüsü'nün yedi "Milenyum Problemi"dir; her biri için bir milyon dolar ödül vardır. Bunlardan yalnız Poincaré sanısı çözülmüştür, "P = NP?" sorusu da bu listededir.

### 10.6 Durma problemi

Hoca durma problemini (halting problem) örnek verdi: bir probleme bir $I$ girdisi verildiğinde problem sonlanacak mı, sonlanmayacak mı? Bu bir karar problemidir. Probleme girdi olarak kendisi verildiğinde bir çelişki ortaya çıkar; bu çelişkiden dolayı durma probleminin çözülemeyeceği sonucuna varılır.

> **Ders sonrası not:** Hoca durma problemini "polinom zamanda çözülemez" diye niteledi. Doğrusu, durma problemi hiçbir algoritmayla, hiçbir sürede çözülemez (karar verilemez, undecidable); bu sonuç Turing'in köşegen (kendine uygulama) çelişkisi argümanıyla kanıtlanır.

## 11. Polinom İndirgeme

Hoca kitaptaki tanımı tahtaya yazdı (ekrandan, 02:00:00):

> A decision problem $D_1$ is said to be polynomially reducible to a decision problem $D_2$ if there exists a function $t$ that transforms instances of $D_1$ into instances of $D_2$ such that:
> 1) $t$ maps all yes instances of $D_1$ to yes instances of $D_2$ and all no instances of $D_1$ to no instances of $D_2$;
> 2) $t$ is computable by a polynomial algorithm.

Türkçesiyle: $D_1$ karar problemi $D_2$ karar problemine polinom olarak indirgenebilir, eğer $D_1$'in örneklerini $D_2$'nin örneklerine dönüştüren bir $t$ fonksiyonu varsa ve (1) $t$, $D_1$'in bütün "evet" örneklerini $D_2$'nin "evet" örneklerine, bütün "hayır" örneklerini $D_2$'nin "hayır" örneklerine eşlerse, (2) $t$ polinom zamanlı bir algoritmayla hesaplanabilirse.

Hoca bunu şöyle açıkladı: $D_2$ için polinom zamanlı bir çözüm varsa ve başka bir problem bütün örnekleriyle buna dönüştürülebiliyorsa, o problem de polinom olarak indirgenebilir. Örnek olarak gezgin satıcı problemi ile Hamilton devresi problemi arasındaki indirgemeyi andı; ikisinin aslında benzer problemler olduğunu söyledi. NP problemlerin bütün örnekleri bir probleme indirgenebiliyorsa amaca ulaşılmış olur; NP-complete problemler bu "tamamlanmış aile"dir.

> **Ders sonrası not:** Hoca indirgemenin yönünü "gezgin satıcı problemini Hamilton devresi problemine indirgeyebiliyoruz" diye verdi. Bilinen indirgeme ters yöndedir: Hamilton devresi problemi gezgin satıcı probleminin karar biçimine polinom zamanda indirgenir (çizgedeki kenarlara 1, olmayan kenarlara 2 ağırlık verilip $n$ maliyetli bir tur aranır). Bu yüzden Hamilton devresi NP-complete olduğundan TSP'nin karar biçimi de NP-complete'dir.

Hoca bu konunun özeti olarak bilinmesi gerekenleri sıraladı: P sınıfı, NP sınıfı, NP-complete, NP-hard, izlenebilir/izlenemez (tractable/intractable), çözülebilir/çözülemez (solvable/unsolvable). Örneğin bu derste çözülen $\lfloor \log_2 n \rfloor$ problemi $O(\log n)$'lik bir algoritmayla çözüldüğü için P sınıfından bir problemdir.

## 12. Dersin Genel Değerlendirmesi: Algoritma Tasarım Yaklaşımları

Hoca dersin "ucu açık" olduğunu söyledi. Örneğin yaklaşım (approximation) ve en iyileme algoritmaları kısmı vardır. Dersin kitabı bazı algoritmalar için başka derslere atıf yapar: sayısal analiz (Gauss eleme, denklem çözümleri), yapay zeka (genetik algoritma, karınca kolonisi algoritması), endüstri mühendisliğindeki yöneylem araştırması (operations research) ve çizge teorisi.

Algoritma analizinin temeli zaman ve bellek açısından değerlendirmedir. Temel tasarım yaklaşımları dönem boyunca görüldü: dinamik programlama, geri izleme (backtracking), böl ve fethet (divide and conquer), dal ve sınır (branch and bound), dönüştür ve fethet (transform and conquer) ve diğerleri. <!-- BELİRSİZ: altyazıda "Onosional Groot Horse dedik" diye bozuk bir yaklaşım adı geçiyor; hangi yöntem olduğu anlaşılamadı. -->

> **Hocanın vurgusu:** İleride mülakatlara girecekseniz dinamik programlama ve özyineleme (recursion) konularında uzmanlığınızı artırın. Algoritma geliştirmek yalnız döngü ve dizi kullanmak değildir; yarışmalarda daha çok özyinelemeye dayalı sorular çıkar.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:10:52; sınav sorusu): Kaba kuvvet yöntemi, en kötü durum analizi, büyük Omega ve azalt ve fethet kavramlarını açıklayın.

> **Çözüm (derste verildi):** Kaba kuvvet bütün olasılıkların tek tek denenmesidir. En kötü durum analizi, algoritmanın en kötü koşullarda harcadığı zaman ve bellektir (ikisi birlikte). Büyük Omega en iyi koşullardaki davranışı anlatır. Azalt ve fethet, problemi sabit bir sayı çıkararak ya da sabit bir sayıya bölerek daha küçük bir örneğine indirip çözmektir (Bölüm 1).

**Soru 2** (derste sözlü, 00:12:28; sınav sorusu): İki algoritma verildiğinde hangisinin daha verimli olduğunu karşılaştırmak için neler yapılmalıdır?

> **Çözüm (derste verildi):** Zaman ve bellek karmaşıklıkları analiz edilir; doğrulukları kontrol edilir; en iyi, en kötü ve ortalama durumlar incelenir; hangi koşullarda (kısıtlı ya da parametrik) çalıştıkları belirtilir.

**Soru 3** (ekrandan, 00:15:00 ve 00:20:00; sınav sorusu): Bir metni (karakter dizisini) kabarcık sıralamasıyla sıralayan fonksiyonu yazın; en iyi durumda gereksiz turları önleyin. (a) En kötü durum analizini matematiksel yöntemle yapın.

> **Çözüm (derste verildi):** `swapped` bayraklı `do-while` kodu Bölüm 2.1'dedir. Temel işlem karşılaştırmadır. En kötü durum (ters sıralı girdi) $\frac{n(n-1)}{2}$ karşılaştırma, $O(n^2)$; en iyi durum (sıralı girdi) $n-1$ karşılaştırma, $O(n)$. Derste "FEDCBA" 15, "ABCDEF" 5 karşılaştırmayla sıralandı. (Hocanın tahtadaki toplamı için Bölüm 2.2'deki ders sonrası nota bakın.)

**Soru 4** (ekrandan, 00:25:00; sınav sorusu): Yarıya indirme (decrease by half) yöntemini kullanarak $\lfloor \log_2 n \rfloor$'i hesaplayan fonksiyonu yazın. (a) Yineleme bağıntısını yazın. Algoritmayı geriye doğru yerine koyma ile ve Master teoremiyle analiz edin.

> **Çözüm (derste verildi):** $f(n) = 0$ ($n \le 1$), $f(n) = 1 + f(\lfloor n/2 \rfloor)$ ($n > 1$). $T(n) = 1 + T(n/2) = i + T(n/2^i)$, $i = \log_2 n$ için $T(n) = \log_2 n \in O(\log n)$. Master: $a=1$, $b=2$, $d=0$, $a = b^d$, $T(n) \in \Theta(\log n)$. $f(1024) = 10$.

**Soru 5** (ekrandan, 00:30:00 ve 00:35:00; sınav sorusu): Bir robot $5 \times 6$'lık bir tablonun sol üst köşesinden sağ alt köşesine yalnız sağa ya da aşağı giderek en fazla havuç (para) toplamak istiyor. Havuçların yerleri: (1,5), (2,2), (2,4), (3,4), (3,6), (4,3), (4,6), (5,1), (5,5). Yineleme bağıntısını kurun, çözümü sözde kod ya da C ile yazın, tabloyu doldurun, toplanacak en fazla havuç sayısını ve robotun rotasını adım adım gösterin, zaman ve bellek karmaşıklığını verin.

> **Çözüm (derste verildi):** $P(i,j) = \max\{P(i-1,j), P(i,j-1)\} + M(i,j)$; $P(1,j) = P(1,j-1) + M(1,j)$; $P(i,1) = P(i-1,1) + M(i,1)$. Tablo Bölüm 4.3'tedir; en fazla 5 havuç. Rota (geriye izleme ile): (1,1) → (1,2) ya da (2,1) → (2,2) → (2,3) → (2,4) → (3,4) → (3,5) → (3,6) → (4,6) → (5,6). Zaman ve bellek $\Theta(mn)$.

**Soru 6** (derste sözlü, 00:48:55): Dizide saklanan bir heap'te $i$. düğümün sol çocuğunun indisi nasıl hesaplanır?

> **Çözüm (derste verildi):** Bir öğrenci $2i+1$ dedi, hoca doğruladı. Sağ çocuk $2i+2$, ebeveyn $\lfloor (i-1)/2 \rfloor$.

**Soru 7** (derste sözlü, 01:26:06): 9, 13, 11, 20, 35 dizisiyle saklanan min-heap'ten kök (9) çıkarılırsa köke hangi eleman gelir ve heap nasıl düzenlenir?

> **Çözüm (derste verildi):** Köke dizinin son elemanı 35 gelir (11 değil). 35'in çocukları 13 ve 11'den küçük olan 11 ile yer değiştirilir; sonuç `11 13 35 20`.

**Soru 8** (derste sözlü, 01:44:52): Belirlenimci olmayan sıralama algoritmasında (NSort) iddianın (tahmin aşamasının) maliyeti nedir?

> **Çözüm (derste verildi):** Bir öğrenci $O(n)$ dedi, hoca doğruladı; doğrulama aşaması da $O(n)$'dir.

**Soru 9** (ekrandan, 02:20:00; quiz sorusu): `noktalar.txt` dosyasının ilk satırında toplam nokta sayısı, sonraki satırlarda her noktanın $x$, $y$ koordinatları vardır. Noktaları `Point` türünde dinamik bir struct dizisinde, $(0,0)$ noktasına Öklid uzaklıklarına göre min-heap yapısında saklayın. Bütün noktalar okunduktan sonra heap dizisini baştan sona koordinatlarıyla yazdırın. Sonra heap'in kökünü ağaç boşalana kadar çıkararak çıkan düğümleri yazdırın ve $(0,0)$'a göre artan sırada olduklarını gösterin. Bellek ve zaman karmaşıklığını analiz edin.

Soruyu açıklarken bir öğrenci, struct içinde sol ve sağ çocuk işaretçileri gerekip gerekmediğini sordu. **Cevap:** Gerekmez; heap dizide saklanır. Heap'te sol-sağ ilişkisi yoktur, yalnız alt-üst ilişkisi vardır; çocuklara ve ebeveyne $2i+1$, $2i+2$, $(i-1)/2$ indisleriyle erişilir. `malloc` ile oluşturulan bir `Point` dizisi yeterlidir.

> **Çözüm (derste verilmedi):** Aşağıdaki kod ajan tarafından yazıldı ve `gcc -Wall` ile derlenip denendi. Karşılaştırmada uzaklığın karesi kullanılabilir; karekök sırayı değiştirmez.
>
> ```c
> #include <stdio.h>
> #include <stdlib.h>
>
> typedef struct { int x, y; } Point;
>
> int uzaklik2(Point p){ return p.x*p.x + p.y*p.y; }
> void swapP(Point *a, Point *b){ Point t=*a; *a=*b; *b=t; }
>
> void heapUp(Point A[], int i){
>     int p;
>     if(i==0) return;
>     p=(i-1)/2;
>     if(uzaklik2(A[p]) > uzaklik2(A[i])){ swapP(&A[p], &A[i]); heapUp(A, p); }
> }
>
> void heapifyDown(Point A[], int i, int n){
>     int l=2*i+1, r=2*i+2, m;
>     if(l>=n) return;
>     m = (r<n && uzaklik2(A[r]) < uzaklik2(A[l])) ? r : l;
>     if(uzaklik2(A[i]) > uzaklik2(A[m])){ swapP(&A[i], &A[m]); heapifyDown(A, m, n); }
> }
>
> int main(int argc, char *argv[]){
>     FILE *f = fopen(argc>1 ? argv[1] : "noktalar.txt", "r");
>     int N, n=0, i;
>     Point *A, p;
>     if(!f){ printf("dosya acilamadi\n"); return 1; }
>     if(fscanf(f, "%d", &N)!=1){ fclose(f); return 1; }
>     A = malloc(N*sizeof(Point));
>     for(i=0;i<N;i++){
>         if(fscanf(f, "%d %d", &p.x, &p.y)!=2) break;
>         A[n++]=p; heapUp(A, n-1);
>     }
>     fclose(f);
>     printf("Heap dizisi:\n");
>     for(i=0;i<n;i++) printf("%d-%d\n", A[i].x, A[i].y);
>     printf("Cikan dugumler:\n");
>     while(n>0){
>         p=A[0]; A[0]=A[n-1]; n--; heapifyDown(A, 0, n);
>         printf("%d-%d (uzaklik^2=%d)\n", p.x, p.y, uzaklik2(p));
>     }
>     free(A);
>     return 0;
> }
> ```
>
> Deneme girdisi `5`, `3 4`, `1 4`, `6 0`, `2 5`, `0 6` için heap dizisi `1-4, 3-4, 6-0, 2-5, 0-6`, çıkan sıra `1-4 (17), 3-4 (25), 2-5 (29), 6-0 (36), 0-6 (36)` oldu. Her ekleme ve her kök alma ağacın yüksekliği kadar, yani $O(\log n)$ adım sürer; $n$ nokta için toplam zaman $O(n \log n)$, bellek $O(n)$'dir.

## Dersin Toparlaması

Dersin ilk bölümünde sınav soruları üzerinden dönemin temel araçları tekrar edildi: kavram tanımları (kaba kuvvet, en kötü durum, $\Omega$, azalt ve fethet), bayraklı kabarcık sıralamasının en iyi ve en kötü durum analizi, yarıya indirerek $\lfloor \log_2 n \rfloor$ hesaplayan özyinelemeli fonksiyonun yerine koyma ve Master teoremiyle analizi, robotla para toplama probleminin dinamik programlamayla çözümü. Ortak ders, her problemde önce yineleme bağıntısını kurmanın gerisini kolaylaştırdığıdır.

İkinci bölümde öncelikli kuyruğun dizi ya da bağlı listeyle $n$ eleman için $O(n^2)$'ye çıkan maliyeti gösterildi ve heap veri yapısı tanıtıldı. Heap dengeli bir ikili ağaçtır, dizide saklanır ($2i+1$, $2i+2$, $(i-1)/2$); ekleme sona yazıp yukarı yığınlaştırmayla, kök alma son elemanı köke getirip aşağı yığınlaştırmayla yapılır. Kök sürekli çekilirse elemanlar sıralı çıkar; heap sort ve quiz sorusundaki nokta sıralaması bu fikre dayanır. Son bölümde dönemin son konusu olarak problem sınıfları ele alındı: P (polinom zamanda çözülen), NP (çözümü polinom zamanda doğrulanabilen), NP-complete ve NP-hard; belirlenimci olmayan algoritmaların tahmin ve doğrulama aşamaları, karar problemleri ve polinom indirgeme. Hoca dönemi, dinamik programlama ve özyinelemede uzmanlaşma tavsiyesiyle kapattı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
