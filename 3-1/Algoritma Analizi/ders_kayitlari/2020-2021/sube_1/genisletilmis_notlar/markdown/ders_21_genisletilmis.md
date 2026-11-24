# Ders 21 Genişletilmiş Notu: LCS'nin Geri İzlenmesi, Backtracking'e Giriş, Çizge Gösterimleri, DFS ve BFS

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. En Uzun Ortak Alt Dizi (LCS) Tekrarı
- 2. Başlangıç Değerleri: LCS ve Edit Distance Farkı
- 3. LCS'nin Geri İzlenmesi
- 4. Etiket Matrisi ile Geri İzleme Algoritması
- 5. Yeni Bir Problem Çözme Yaklaşımı: Backtracking
- 6. Çizgelerin Gösterimi: Komşuluk Matrisi ve Komşuluk Listesi
- 7. Derinlik Öncelikli Arama (DFS)
- 8. Genişlik Öncelikli Arama (BFS)
- 9. Sonraki Konu: n-Vezir Problemi
- Örnek Sorular
- Dersin Toparlaması

## 1. En Uzun Ortak Alt Dizi (LCS) Tekrarı

Ders, önceki oturumda süre yetmediği için yarım kalan en uzun ortak alt dizi (Longest Common Subsequence, LCS) konusunun tamamlanmasıyla başladı. Hoca önce kavramı kısaca özetledi, sonra yarım kalan kısma, yani ortak alt dizinin hangi harflerden oluştuğunun geriye doğru nasıl çıkarılacağına geçti.

### 1.1 Alt dizi ve ortak alt dizi

Edit distance ve LCS, kelime işlemci uygulamalarında ve doğal dil işlemede kullanılan yöntemlerdir. LCS özellikle biyoinformatikte, DNA dizilimlerindeki ortak parçaların bulunmasında kullanılır.

Alt dizi (subsequence), bir kelimeden harfleri sıralarını koruyarak seçmekle elde edilir. Hoca "yakamoz" kelimesini örnek verdi: "yaka", "yama", "kama" ya da "ama" bu kelimenin alt dizileridir. Alt dizinin ilk harfle başlaması ya da harflerin bitişik olması gerekmez. Tek kural şudur: seçilen harflerin konumları $i_1, i_2, i_3, \dots$ ile gösterilirse, her seçilen harf bir öncekinden ileride olmalıdır. "Yorgan" kelimesinden "yoga" alınabilir; ama geriye doğru gidilerek bir harf alınamaz.

Ortak alt dizi (common subsequence), iki kelimenin ikisinde de bulunan alt dizidir. Burada iki kelime için bakılır: $m$ karakterli bir $X$ ve $n$ karakterli bir $Y$. En uzun ortak alt dizi bunların en uzunudur. Biyoinformatikte hangi DNA dizilimlerinin birbirine daha çok benzediği aranırken benzerlik ölçüsü budur: en çok benzeyen, ortak alt dizisi en uzun olandır.

### 1.2 Özyinelemeli bağıntı

Tahtadaki bağıntı (ekrandan, 00:15:00). $LCS[i,j]$, $X$'te $i$'inci, $Y$'de $j$'inci karaktere kadar olan ortak alt dizinin uzunluğudur:

$$
LCS[i,j] =
\begin{cases}
0 & i = 0 \text{ ya da } j = 0 \\
LCS[i-1,j-1] + 1 & i,j > 0 \text{ ve } x_i = y_j \\
\max\{LCS[i,j-1],\ LCS[i-1,j]\} & i,j > 0 \text{ ve } x_i \neq y_j
\end{cases}
$$

Bir anda $i$'inci ve $j$'inci karakter karşılaştırıldığında değerleri eşitse bir ortak karakter daha bulunmuş demektir. Bu yüzden bir önceki durumun, yani $x_{i-1}$ ve $y_{j-1}$'e kadar elde edilen sonucun üzerine 1 eklenir (ekrandan, 00:10:00: $X = ACGT$, $Y = GT$ örneğinde son harfler T ve T eşit; tahtada "ortak bir karakter daha var!" notu).

Eşit değillerse ($X = ACGT$, $Y = GC$ örneği, ekrandan, 00:10:00), ortak alt dizide ya $x_i$ ya $y_j$ yoktur, belki ikisi de yoktur. Eşitliğin bozulmasının sebebinin hangisi olduğu bilinmediği için iki durum da denenir:

- $LCS[i-1,j]$: $x_i$ ortak alt dizinin parçası değildir ($X$'te bir geri, $Y$'de aynı yer).
- $LCS[i,j-1]$: $y_j$ ortak alt dizinin parçası değildir.

En uzun aranırken bu ikisinin büyüğü alınır.

### 1.3 Tablonun doldurulması

Örnek: $X = \langle BACDB \rangle$, $Y = \langle BDCB \rangle$ (ekrandan, 00:15:00). Satırlar $X$'in, sütunlar $Y$'nin harfleridir; 0'ıncı satır ve sütun boş kelimeyi gösterir.

İlk satır ve sütun 0'dır: kelimelerden biri yoksa, örneğin BDCB'nin karşısı boşsa, LCS 0'dır. Bu bir başlangıç (initialization) adımıdır; üzerine ekleyerek gidileceği için bir ilk değer gerekir.

Sonra satır satır doldurulur. B ile B eşittir: çaprazdaki 0'a 1 eklenir, 1. B ile D eşit değildir: yukarı ya da soldan gelinir, soldaki daha büyük olduğu için 1. Aynı biçimde devam edilir. Hoca hücrelerin ne anlama geldiğini de tek tek gösterdi:

- C satırında B sütunu: BAC ile B karşılaştırılıyor, bir ortak karakter var, 1.
- BAC ile BD: hâlâ 1.
- BAC ile BDC: 2. Gerçekten de BC ikisinde de var.
- BACD ile BD: 2 (BD ortak). BACD ile BDCB: hâlâ 2; ortak dizi BD ya da BC olabilir.
- BACDB ile BDCB: 3. Gözle bakıldığında BCB ya da BDB, ikisinin de uzunluğu 3.

Tamamlanmış tablo (ekrandan, 00:20:00; python ile doğrulandı):

| | 0 | B | D | C | B |
|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 | 0 |
| B | 0 | 1 | 1 | 1 | 1 |
| A | 0 | 1 | 1 | 1 | 1 |
| C | 0 | 1 | 1 | 2 | 2 |
| D | 0 | 1 | 2 | 2 | 2 |
| B | 0 | 1 | 2 | 2 | 3 |

Birden fazla LCS olmasının sebebi, bazı hücrelere hem soldan hem yukarıdan gelinebilmesidir. Geriye doğru ararken hangi yoldan gidildiğine bağlı olarak bulunan ortak alt dizi değişir.

## 2. Başlangıç Değerleri: LCS ve Edit Distance Farkı

**Soru:** Bazı kaynaklarda ilk satırın ve sütunun 0, 1, 2, 3, 4 diye başlatıldığı, sonraki döngülerin 1'den başladığı görülüyor. Bu da doğru mu? **Cevap:** O LCS değil, edit distance'tır. Edit distance'ta bir harfin karşısında hiçbir şey yoksa uzaklık 1'dir; bir sonraki harfe gelindiğinde (önceki harflerle birlikte değerlendirildiği için) karşısı boşsa uzaklık $1 + 1 = 2$ olur. Bu yüzden ilk satır ve sütun birer birer artar. LCS'de ise amaç eşit harf bulunduğunda bulunanı bir artırmaktır; kelimenin karşısı boşsa ortak hiçbir şey olmadığı için ilk satır ve sütun hep 0'dır.

Hoca bunun genel bir ders olduğunu vurguladı: başlangıç değerleri problemin amacına bağlıdır. Bazı problemlerde hiç başlangıç değeri olmayabilir; örneğin yalnız bir önceki durum kullanılıyor ve üzerine ekleme yapılmıyorsa. Önemli olan, başlangıçta ne olduğuna ve ne istendiğine dikkat etmektir.

> **Hocanın vurgusu:** Başlangıç değerleri ezberlenmez; problemin ne istediğine bakılarak belirlenir.

## 3. LCS'nin Geri İzlenmesi

Tablo LCS'nin yalnız uzunluğunu verir. Hangi harflerden oluştuğunu bulmak için geriye doğru gitmek gerekir.

Hoca önce sordu: bir harf ne zaman alınır? Bir öğrencinin cevabıyla: harfler aynıysa. $x_i = y_j$ ise hücreye çaprazdan (diagonal) gelinmiştir ve harf alınır. $x_i \neq y_j$ ise hücreye ya soldan ya yukarıdan gelinmiştir ve harf alınmaz (ekrandan, 00:25:00: tahtada "$x_i = y_j$ ↖ (alınır)" ve "$x_i \neq y_j$ ← ↑").

Örnekte geri izleme sağ alt hücreden başlar (ekrandan, 00:30:00; tahtada bu hücre "size of LCS" diye işaretli):

- (B, B): eşit, B alınır, çapraza gidilir.
- (D, C): yukarı ya da sola gidilebilir; ikisi farklı iki çözüm verir. Hoca yukarı gitti; D ve C farklı olduğu için harf alınmaz.
- (C, C): eşit, C alınır, çapraza gidilir.
- (A, D): yine yukarı ya da sol mümkün; yukarı gidildi, A ve D farklı, alınmaz. Sonra sola gidildi, yine alınmaz.
- (B, B): çapraz, B alınır.

Sonuç BCB'dir; başka yoldan gidilseydi BDB çıkacaktı.

### 3.1 Çözüm neden sondan başa bulunur

Hoca, hangi harflerin alınacağını bulmak için ne önerileceğini sordu. Bir öğrenci baştan sona gitmeyi düşündü. Hoca, doğru yolun baştan sona bulunamayacağını, sondan başa bulunacağını söyledi. LCS'nin uzunluğunun bulunduğu nokta sağ alt hücredir ve bunun nasıl oluştuğunu görmek için geriye gidilir. 0-1 sırt çantası probleminde de aynı biçimde sondan çözülmüştü. İleriye doğru çözmenin yolu ise bilgiyi tablo oluşturulurken kaydetmektir.

### 3.2 Yalnız değerlere bakmak yetmez

Geriye giderken yalnız sayılara bakılırsa sorun çıkar. Sağ alt hücre 3, çaprazı 2'dir; "çaprazı bir eksikse harfi al" denirse bu doğru çalışır. Ama aynı mantıkla değeri 2, çaprazı 1 olan bir hücrede de D ve C harflerinin alınması gerekir; bu yanlıştır. Bir öğrencinin dediği gibi, harflerin de aynı olması gerekir. O zaman geriye giderken harfler yeniden karşılaştırılmalıdır: "B, B'ye eşit mi, eşitse al, çapraza git." Bu da neredeyse tabloyu oluştururken yapılan işi bir kez daha yapmak demektir.

## 4. Etiket Matrisi ile Geri İzleme Algoritması

Bunun yerine tablo (cost matrisi) oluşturulurken, her hücre için harfin alınıp alınmadığı ikinci bir $b$ matrisine yazılır (ekrandan, 00:35:00):

- $x_i = y_j$ ise $b[i,j] = $ ADDXY: bu harf alınacak.
- $x_i \neq y_j$ ve $cost[i-1,j] > cost[i,j-1]$ ise değer yukarıdan gelir, $b[i,j] = $ SKIPX: $x_i$ alınmıyor.
- Aksi durumda değer soldan gelir, $b[i,j] = $ SKIPY: $y_j$ alınmıyor.

Hoca, hangisinin alınmadığının aslında çok önemli olmadığını; asıl işlevin bir sonraki adımda yukarı mı sola mı gidileceğini göstermek olduğunu söyledi.

### 4.1 LCS'yi çıkaran fonksiyon

Tahtadaki sözde kod (ekrandan, 00:35:00; SKIPX ve SKIPY dalları altyazıdan tamamlandı):

```text
findLCS(x[1..m], y[1..n], b[0..m, 0..n])
{
    i = m, j = n
    while (i != 0 && j != 0)
    {
        switch (b[i, j])
        {
            case ADDXY: add x[i] to front of LCS
                        i--; j--;
                        break;
            case SKIPX: i--; break;
            case SKIPY: j--; break;
        }
    }
}
```

ADDXY'de karakter alınır ve dizinin başına eklenir; çünkü geriye doğru gidilmektedir ve önce son harf bulunur (örnekte önce B, sonra C). Çapraza gidildiği için $i$ ve $j$ birer azalır. SKIPX'te yalnız $i$ azalır: bir üst satıra çıkılır. SKIPY'de yalnız $j$ azalır: bir sol sütuna geçilir. Böylece harfler hiç yeniden karşılaştırılmadan, yalnız etiketlere bakılarak dizi elde edilir.

### 4.2 Tabloyu ve etiketleri dolduran fonksiyon

Öğrencilerin isteği üzerine hoca $b$ matrisinin nasıl oluşturulduğunu da yazdı (ekrandan, 00:40:00; tahtada başta `c` yazıp sonra `cost` olacağını söyledi):

```text
LCS(x[1..m], y[1..n])
{
    int cost[0..m, 0..n]
    for i = 0 to m do
        cost[i,0] = 0;  b[i,0] = SKIPX
    for j = 0 to n do
        cost[0,j] = 0;  b[0,j] = SKIPY
    for i = 1 to m do
        for j = 1 to n do
            if (x[i] == y[j])
                cost[i,j] = cost[i-1,j-1] + 1
                b[i,j] = ADDXY
            else if (cost[i-1,j] > cost[i,j-1])
                cost[i,j] = cost[i-1,j]
                b[i,j] = SKIPX
            else
                cost[i,j] = cost[i,j-1]
                b[i,j] = SKIPY
}
```

<!-- BELİRSİZ: else if ve else dallarının yazıldığı an karelerde yok; bu kısım altyazıdaki anlatımdan aktarıldı. -->

0'ıncı sütundaki hücrelere SKIPX yazılması, o sütunda yukarı doğru gidildiği anlamına gelir; 0'ıncı satırdakilere SKIPY yazılması sola gidildiği anlamına gelir. Döngüde yalnız rekürans bağıntısı yazılır ve yanına $b[i,j]$ etiketi eklenir; etiket bir sonraki adımda ne taraftan gidileceğini gösterir.

> **Ders sonrası not:** Eşitlik durumunda (yukarı ve sol değerler eşitken) bu kod SKIPY'yi, yani sola gitmeyi seçer. Python ile denendiğinde örnekte sonuç BDB'dir. Hocanın elle izlediği yol yukarı gittiği için BCB'yi verdi. İkisi de uzunluğu 3 olan doğru LCS'dir.

### 4.3 Birden fazla çözüm

**Soru:** Birden fazla geri gitme yolu yok mu? **Cevap:** Var. Ama bu algoritma, iki değer eşitken if koşulunun nasıl yazıldığına göre birini seçtiği için yalnız bir çözümü görür. Bütün çözümler isteniyorsa eşitlik için üçüncü bir etiket kullanılmalı ve algoritma her turda bir yolu seçecek biçimde genişletilmelidir. Önemli olan mantıktır.

## 5. Yeni Bir Problem Çözme Yaklaşımı: Backtracking

Hoca bu dönem farklı problem çözme mantıklarının gösterildiğini hatırlattı: böl ve fethet (problemi parçalara bölüp çözümleri birleştirmek), dinamik programlama (önceden hesaplanan sonuçları saklayıp kullanarak, kaba kuvvette denenmesi gereken bütün olasılıklardan kaçınmak). Dinamik programlamada karmaşıklık genellikle sonuçları saklamak için kullanılan dizinin ya da matrisin büyüklüğü kadardır; LCS'de tablonun boyutu kadar.

> **Ders sonrası not:** Hoca LCS karmaşıklığını "N çarpı N" diye söyledi; uzunlukları $m$ ve $n$ olan iki kelime için doğrusu tablonun boyutu olan $O(mn)$'dir (eşit uzunlukta $O(n^2)$).

Yeni yaklaşım backtracking'dir (ekrandan, 01:15:00). Hoca labirentteki bir fareyi örnek verdi. Fare başlangıçtan çıkar, bir karar noktasına gelir: yukarıdan mı aşağıdan mı gidecek? Birini seçer. Bilgisayarda bir hiyerarşi izlemek gerektiği için sırayla, örneğin önce üsttekini seçeriz. İlerler, yeni bir karar noktasında yine üstteki seçilir ve bir çıkmaza (dead end) gelinir.

O zaman en başa mı dönülür, yoksa son karar noktasındaki ikinci seçenek mi denenir? Bir öğrencinin cevabıyla: son karar noktasındaki ikinci seçenek denenir; çünkü belki oradan bir sonuç çıkıyordur. O da çıkmazsa bir önceki karar noktasına dönülür ve böyle devam edilerek hedefe (goal) ulaşılır.

Dinamik programlamada olası bütün alt problemler çözülür. Backtracking'de ise bir noktadan sonra çözüme ulaşılamayacağı görülürse oradan geri dönülür. Geri dönüş en başa değil, hiyerarşik olarak adım adım yapılır: "bu olmadı, buradan deneseydim ne olurdu; o da olmadı, bir geri dönseydim ne olurdu."

**Soru (hocanın):** Backtracking yapmak için bilinen yöntemlerden hangisi kullanılabilir? **Cevap (bir öğrenci):** Depth first search. Hoca, bunun yöntemlerden biri olduğunu söyleyip önce çizgelerde arama yöntemlerini hatırlatmaya geçti.

## 6. Çizgelerin Gösterimi: Komşuluk Matrisi ve Komşuluk Listesi

Çizge (graf) aslında soyut bir veri yapısıdır; gerçekte böyle bir veri yapısı yoktur, eldeki veri yapılarıyla gerçekleştirilir. İki temel gösterim vardır: komşuluk matrisi (adjacency matrix) ve komşuluk listesi (adjacency list).

### 6.1 Örnek

Tahtadaki yönsüz (undirected), ağırlıklı çizge (ekrandan, 01:20:00): A–B 5, A–C 21, A–D 12, B–C 8. Düğümler A, B, C, D için 0, 1, 2, 3 indisleri kullanılır.

Komşuluk matrisi:

| | A | B | C | D |
|---|---|---|---|---|
| A | | 5 | 21 | 12 |
| B | 5 | | 8 | |
| C | 21 | 8 | | |
| D | 12 | | | |

Çizge yönsüz olduğu için matris simetriktir: AB'ye 5 yazıldıysa BA'ya da 5 yazılır. Kenarların ağırlığı yoksa hücrelere 1 ve 0 yazılabilir. Bir düğümden kendisine yol olmadığı için köşegen 0'dır.

Komşuluk listesinde her düğüm için bir bağlı liste kurulur ve yalnız bağlı olduğu düğümler yazılır. A'nın listesi: B(5) → C(21) → D(12) → NULL. B, C ve D için de benzer listeler kurulur.

### 6.2 Yer ve sorgu maliyeti

Hoca soru-cevapla iki gösterimi karşılaştırdı (ekrandan, 01:25:00):

- Matris için $|V|$ düğümde $|V| \times |V|$, yani $|V|^2$ yer gerekir.
- "v ile w arasında kenar var mı" sorusu matriste tek adımda cevaplanır: ilgili hücreye bakılır; 0 ise bağlı değildir.
- Listede $|V| + |E|$ yer gerekir. Örnekte 4 düğüm için 4 elemanlı bir dizi, yönsüz olduğu için her kenar iki kez yazıldığından 8 liste elemanı gerekir.
- Listede kenar sorgusu için bağlı liste üzerinde ilerlemek gerekir: "A, D'ye bağlı mı? B mi? Hayır. C mi? Hayır. D mi? Evet." En kötü durumda düğümün derecesi (degree) kadar adım gerekir.

Derece, bir düğümün bağlı olduğu düğüm sayısıdır. Hoca küçük bir örnek üzerinde A'nın derecesini 2 diye gösterdi. Bir öğrenci üstteki çizgede A'nın B, C ve D'ye bağlı olduğunu, derecesinin 3 olduğunu belirtti; hoca kendi örneğinin alttaki küçük çizge için olduğunu söyledi. İkisi de kendi çizgesi için doğrudur.

### 6.3 Hangisi ne zaman

**Soru (hocanın):** Ne zaman matris, ne zaman liste kullanılır? **Cevap (bir öğrenci, hocanın düzeltmesiyle):** Kenarların durumuna bağlıdır. Çizge seyrek (sparse) ise, yani her düğüm bütün düğümlere bağlı değilse, komşuluk listesi; yoğun (dense) ise komşuluk matrisi kullanılır.

Hoca akılda kalıcı bir örnek verdi: bir sosyal ağda bir milyar kullanıcı varsa ve her kullanıcının en fazla 200 kadar arkadaşı varsa, bir milyara bir milyarlık matrisin çok küçük bir kısmı dolu olur; seyrek bir matristir. Listeyle bir milyar elemanlı bir dizi ve her biri en fazla yaklaşık 200 elemanlı bağlı listeler yeter; kazanç çok bariz olur.

Tersine, 10.000 düğümlü ve her düğümün 9.000 başka düğüme bağlı olduğu bir çizgede listede sürekli arama yapmak verimli olmaz; matriste her sorgu tek adımdır.

> **Hocanın vurgusu:** Seyrek çizge → komşuluk listesi; yoğun çizge → komşuluk matrisi. Yönlü çizgelerde de mantık aynıdır.

## 7. Derinlik Öncelikli Arama (DFS)

Hoca çizgelerin önceki yıl ayrıntılı görüldüğünü, burada yalnız depth-first search ve breadth-first search mantıklarının hatırlatılacağını söyledi.

### 7.1 Örnek: A'dan G'ye yol var mı?

Tahtadaki yönlü çizge (ekrandan, 01:35:00): A → B, A → C, A → D, B → E, C → E, C → G, E → D, E → F, F → B, G → F. Soru: A'dan G'ye yol var mı?

Hoca, G'ye giden yolun hemen bulunmaması için çizgeyi anlatırken birkaç kez değiştirdi. DFS'de bir yoldan durmadan sonuna kadar gidilir:

- A'dan B'ye, B'den E'ye, E'den D'ye gidilir. D'den başka bir yere gidilemez; bir adım geri, E'ye dönülür.
- E'den F'ye gidilir. F'den yalnız B'ye gidiş vardır; B zaten gezildiği için geri dönülür.
- B'den gidilebilecek tek yer E idi, o da gezildi; A'ya dönülür.
- A'dan C'ye gidilir. E gezildiği için C'den E'ye gidilmez; C'den G'ye gidilir ve aranan düğüme ulaşılır.

Ziyaret sırası: A, B, E, D, F, C, G (ekrandan, 01:35:00; python ile doğrulandı).

Buradan önemli bir sonuç çıkar: gidilen yerlere bir daha gitmenin anlamı yoktur, bu yüzden gidilen düğümler işaretlenir. İşaretlenmezse labirentteki gibi aynı düğümlerden defalarca geçilir ve çıkılamaz.

### 7.2 Hangi veri yapısı?

Durmadan ilerlerken geri dönüldüğünde nerede kalındığı hatırlanmalıdır: E'de kalındığı, E'den D olmuyorsa F'ye gidileceği bilinmelidir. Bir adım öncesini akılda tutmak için yığıt (stack) kullanılır; bunu bir öğrenci cevapladı. DFS iki türlü yazılabilir: yığıt gerçekten gerçekleştirilip push-pop işlemleriyle, ya da zaten yığıt mantığını kullanan özyinelemeyle (recursion).

### 7.3 Özyinelemeli DFS

Tahtadaki sözde kod (ekrandan, 01:40:00). G çizge, s kaynak (source) düğümdür:

```text
DFS(G, s)
{
    mark s as VISITED
    for all neighbors w of s in Graph G
        if w is NOT VISITED
            DFS(G, w)
}
```

Bu ana algoritma bütün çizgenin nasıl gezildiğini gösterir; probleme göre şekillendirilir. A'dan başlandığında A'nın komşusu B için DFS çağrılır, yani artık B'nin komşularına bakılır. B'nin komşuları bitince A'nın öbür komşusuna geçilir. Özyineleme yığıt mantığını kendiliğinden sağlar.

Ziyaret bilgisi için düğüm indisleriyle bir dizi tutulur: A, B, C, D için 0, 1, 2, 3 indisli, başta hepsi 0; ziyaret edildikçe 1 yapılır (ekrandan, 01:40:00).

**Soru:** Kodda bütün düğümler ziyaret edildi diye işaretlenmiş ve aranan düğüm hâlâ işaretlenmemişse, yol yok mu denir? **Cevap:** Evet. Örneğin A'dan B'ye, B'den D'ye gidilir; D'nin komşusu yok, dönülür; B'nin başka komşusu yok, dönülür; A'dan C'ye gidilir. G tek başına duran bir düğümse gidilecek yer kalmaz ve G'ye yol olmadığı söylenir. Soruya göre değişir; örneğin kaç alt çizge olduğu sorulsaydı başka bir şey yapılırdı.

### 7.4 Yığıtla (özyinelemesiz) DFS

Özyinelemesiz yazılırsa yığıt fonksiyonları kullanılır: kaynak düğüm s yığıta konur ve VISITED işaretlenir. Yığıt boşalana kadar (yığıt boşsa bakılacak komşu kalmamıştır) yığıtın üstündeki düğüm çekilir ve komşularına bakılır. Ziyaret edilmemiş komşu w, özyinelemeli sürümde fonksiyon çağrılırken burada yığıta konur ve işaretlenir; sonra döngüye dönülür ve yine yığıtın üstündeki ele alınır.

<!-- BELİRSİZ: yığıtlı DFS'nin tahtaya yazılan sözde kodunun karesi yok; adımlar altyazıdan aktarıldı. -->

> **Ek bilgi (derste anlatılmadı):** Yığıtlı sürümde düğümler yığıta konurken işaretlenirse ziyaret sırası özyinelemeli sürümden farklı olabilir. Özyinelemeli sırayı birebir elde etmek için düğüm genellikle yığıttan çekildiğinde işaretlenir.

### 7.5 DFS uygulamaları

Tahtadaki liste (ekrandan, 01:45:00):

- Topolojik sıralama (topological sort). Bir öğrencinin hatırlattığı gibi, yapılacak işlerde öncelik sırasıdır; örneğin ön şartı olan dersi almadan sonraki ders alınamaz. Giriş derecesi 0 olan, yani kendisine hiçbir düğümün bağlı olmadığı bir işten başlanır. Böl ve fethet konusunda görülmüştü; çözüm yollarından biri DFS'dir.
- s'den t'ye yol bulma: örneğin bir sosyal ağda iki kişi arkadaş mı?
- Çevrim bulma (cycle detection): A'dan çıkıp B'ye, C'ye gidip tekrar A'ya dönülebiliyorsa çevrim vardır ve DFS ile yakalanır.
- Bağlı bileşenler (connected components): örneğin ABC bir bileşen, DEF başka bir bileşen. DFS bir bileşeni bitirince sayaç 1 artırılır, kalan ziyaret edilmemiş düğümlerden tekrar başlanır; böylece kaç tane birbirine bağlı bileşen olduğu bulunur.

## 8. Genişlik Öncelikli Arama (BFS)

BFS, DFS'nin aksine enine arama yapar: önce başlangıç düğümünün komşuları, sonra onların komşuları ziyaret edilir.

### 8.1 Örnek

Tahtadaki yönsüz çizge (ekrandan, 01:50:00 ve 02:00:00): A–B, A–C, A–E, B–D, C–D, C–G, E–F. A'dan başlanır. Bilgiyi bu biçimde saklamak için hangi yapı gerekir? Bir öğrencinin cevabıyla: kuyruk (queue).

Kuyruğun değişimi (ekrandan, 02:00:00; python ile doğrulandı):

| Adım | Kuyruk (baştan sona) | Açıklama |
|---|---|---|
| 1 | A B C E | A'nın komşuları B, C, E kuyruğa yazılır ve işaretlenir; A çıkar |
| 2 | B C E D | B'nin tek işaretsiz komşusu D eklenir; B çıkar |
| 3 | C E D G | C'nin komşuları A ve D işaretli, girmez; G eklenir; C çıkar |
| 4 | E D G F | E'nin komşusu A işaretli; F eklenir; E çıkar |
| 5 | D G F | D'nin işaretsiz komşusu yok; D çıkar |
| 6 | G F | G'nin işaretsiz komşusu yok |
| 7 | F | F'nin işaretsiz komşusu yok |

Kuyrukta kimse kalmayınca işlem biter. Ziyaret sırası: A, B, C, E, D, G, F.

### 8.2 Sözde kod

Hocanın anlatımıyla:

```text
BFS(G, s)
{
    s'yi kuyruğa ekle; s'yi VISITED işaretle
    while (kuyruk boş değil)
    {
        v = kuyruğun başındaki eleman (çekilir)
        for all neighbors w of v in Graph G
            if w is NOT VISITED
                w'yi kuyruğa ekle; w'yi VISITED işaretle
    }
}
```

<!-- BELİRSİZ: BFS sözde kodunun tahtaya yazıldığı an karelerde yok; yapı altyazıdaki anlatımdan kuruldu. -->

### 8.3 DFS mi BFS mi?

İki yöntemle de pek çok problem çözülebilir, ama biri diğerine göre avantajlı olabilir. "A'dan B'ye gidebilir miyim" sorusunda DFS daha mantıklıdır: yola çıkıp durmadan gider. BFS ise önce birinci kattaki komşulara, sonra ikinci kattakilere bakar. En kısa yolda (shortest path) BFS daha avantajlıdır (ekrandan, 01:55:00): kademe kademe gittiği için A'ya bir, iki, üç uzaklıktaki düğümleri sırayla görür. DFS ile bunu yakalamak çok daha zordur. Bu, kenarların ağırlığı yoksa geçerlidir.

> **Ders sonrası not:** Hoca bir yerde "depth first search de shortest path'te daha mantıklı" dedi, hemen ardından kademe kademe gitme gerekçesiyle anlattığı yöntem BFS'dir; doğrusu BFS'dir.

Hocanın saydığı BFS kullanım alanları: BitTorrent gibi peer-to-peer ağlarda bilgi alınabilecek komşu düğümleri bulmak, GPS ve harita sistemleri, minimum yayılan ağaç (minimum spanning tree) türü sorular, arama motorlarındaki tarayıcılar (crawler).

> **Ders sonrası not:** Haritada iki semt arasında en uygun yolun ve minimum yayılan ağacın bulunması ağırlıklı çizge problemleridir. Bunlar için büyük olasılıkla doğrudan BFS değil, Dijkstra ya da A* gibi en kısa yol algoritmaları ve Prim ya da Kruskal gibi algoritmalar kullanılır; BFS yalnız ağırlıksız çizgede en kısa yolu garanti eder.

### 8.4 BFS özyinelemeli yazılabilir mi?

**Soru:** BFS de özyinelemeli yazılabilir mi, yazılırsa karmaşıklık artar mı? **Cevap:** Özyinelemeli yazılmamalıdır; mantığı buna uygun değildir. Özyinelemede bir yere kadar gidilir ve toplaya toplaya geri dönülür. BFS'de ise A'nın komşuları B, C, E sırayla işlenir; bir seviye bitince sonraki seviyeye geçilir. Hoca bunu bir ağaç gibi çizerek gösterdi (ekrandan, 02:00:00; bu çizim yukarıdaki çizgeden farklı, örnek amaçlı bir ağaçtır): A'nın çocukları B, C, E; B'nin çocukları D ve G; C'nin çocuğu F. Önce B, C, E ziyaret edilir (birinci kademe), sonra B'nin komşuları D ve G, sonra C'nin komşusu F. Bir H düğümü olsaydı sekizinci sırada ona gelinecekti. Kuyruk sayesinde B işlenirken eklenen D ve G kaybolmaz, sıraları gelene kadar bekler. Hoca, her şeyin bir çözümü olduğunu, zorlanırsa özyinelemeli bir çözüm de yazılabileceğini ama çok daha karmaşık olacağını söyledi.

> **Hocanın vurgusu:** DFS yığıt (ya da özyineleme), BFS kuyruk kullanır; kuyruk kullanmanın sebebi de kademe kademe ilerlemektir.

## 9. Sonraki Konu: n-Vezir Problemi

Sonraki haftalarda backtracking görülecek: bir noktadan çıkıp hedefe ulaşmak için bir yol kapalıysa öbür yoldan nasıl devam edileceği. İlk soru n-vezir (n-queen) problemidir: vezirleri satranç tahtasına birbirini görmeyecek biçimde yerleştirmek. Hoca 8 vezir yerine 4 vezir için soruyu bıraktı ve öğrencilerden önce kendilerinin denemesini, bir algoritmayla nasıl yapacaklarını düşünmelerini istedi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00 ve 00:20:00): $X = \langle BACDB \rangle$ ve $Y = \langle BDCB \rangle$ için LCS tablosunu doldurun, LCS uzunluğunu ve LCS'leri bulun.

> **Çözüm:** Tablo Bölüm 1.3'tedir; sağ alt hücre 3'tür. Geri izlemede eşitlik durumunda yukarı gidilirse BCB, sola gidilirse BDB elde edilir. Python ile bütün LCS'ler sayıldığında yalnız bu ikisi çıkar.

**Soru 2** (derste sözlü, 00:26:02): Longest common subsequence'ın hangi harflerden oluştuğunu anlamak için algoritma nasıl tasarlanır?

> **Çözüm:** Sağ alt hücreden geriye gidilir; çapraz gelinen hücrelerde harf alınır. Harfleri yeniden karşılaştırmamak için tablo doldurulurken ADDXY, SKIPX, SKIPY etiketleri bir $b$ matrisine yazılır ve geri izlemede yalnız bu etiketlere bakılır (Bölüm 4).

**Soru 3** (derste sözlü, 01:24:05 ve 01:24:36): $V$ düğümlü bir çizge matrisle tutulursa ne kadar yer gerekir? v ile w arasında kenar olup olmadığı kaç adımda bulunur? Liste kullanılırsa?

> **Çözüm:** Matris: $|V|^2$ yer, tek adımda sorgu. Liste: $|V| + |E|$ yer, sorgu en kötü durumda düğümün derecesi kadar adım.

**Soru 4** (ekrandan, 01:35:00): Tahtadaki yönlü çizgede A'dan G'ye yol var mı? DFS'nin ziyaret sırası nedir?

> **Çözüm:** Vardır (A → C → G). Ziyaret sırası A, B, E, D, F, C, G.

**Soru 5** (ekrandan, 01:50:00): Tahtadaki yönsüz çizgede A'dan başlayan BFS'nin ziyaret sırası nedir?

> **Çözüm:** A, B, C, E, D, G, F; kuyruğun adım adım hâli Bölüm 8.1'deki tablodadır.

**Soru 6** (derste sözlü, 01:57:16): 4 veziri 4×4 satranç tahtasına birbirini görmeyecek biçimde nasıl yerleştirirsiniz?

> **Çözüm (derste verilmedi):** Satır satır, her satıra bir vezir koyup çakışma olunca bir önceki satıra geri dönerek (backtracking) iki çözüm bulunur: sütunlar satır sırasıyla (2, 4, 1, 3) ve (3, 1, 4, 2). Python ile bütün yerleşimler denenerek doğrulandı.

## Dersin Toparlaması

Dersin ilk bölümünde LCS konusu tamamlandı. Tablonun sağ alt hücresi LCS'nin uzunluğunu verir; hangi harflerden oluştuğu ise sondan başa geri izlenerek bulunur. Çapraz gelinen hücrelerde harf alınır, yukarı ya da sola gidişte alınmaz. Harfleri yeniden karşılaştırmamak için tablo doldurulurken ADDXY, SKIPX ve SKIPY etiketleri ayrı bir matrise yazılır. Bu algoritma eşitlik durumunda tek bir yol seçtiği için tek bir LCS verir. Başlangıç değerlerinin problemin amacına göre belirlendiği edit distance ile karşılaştırılarak gösterildi.

İkinci bölümde yeni bir yaklaşım olan backtracking'in mantığı labirent örneğiyle tanıtıldı ve buna hazırlık olarak çizgeler hatırlatıldı. Komşuluk matrisi ve listesi yer ve sorgu maliyetleriyle karşılaştırıldı. DFS'nin yığıtla ya da özyinelemeyle, BFS'nin kuyrukla çalıştığı örneklerle gösterildi; iki yöntemin uygulama alanları konuşuldu. Sonraki derslerde backtracking, n-vezir problemiyle ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
