# Ders 19 Genişletilmiş Notu: Edit Distance (Levenshtein) ve En Uzun Ortak Alt Dizi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dinamik Programlamanın Tekrarı: 0/1 Sırt Çantası
- 2. Edit Distance Problemi ve Kullanım Alanları
- 3. Levenshtein Yaklaşımı: Dört Durum ve Minimum Uzaklık
- 4. Alt Problem ve Yineleme Bağıntısı
- 5. Örnek: ED("MATHS", "ARTS")
- 6. Geri İzleme ile Dönüşümün Bulunması
- 7. En Uzun Ortak Alt Dizi (LCS)
- Örnek Sorular
- Dersin Toparlaması

## 1. Dinamik Programlamanın Tekrarı: 0/1 Sırt Çantası

Ders, önceki derste anlatılan dinamik programlamanın kısa bir tekrarıyla başladı. Dinamik programlamada, böl ve yönet algoritmalarında olduğu gibi, bir problemin alt problemi belirlenir ve bu alt problem tekrar tekrar çözülerek ana çözüme ulaşılır. Özyinelemeli (recursive) programlamadan farkı, elde edilen sonuçların bir yerde (bir dizi ya da matriste) saklanması ve sonraki adımlarda bu sonuçların kullanılmasıdır. Özyinelemede çağrı sırasında oluşan sonuçlar tutulur ama belirli bir yerde saklanıp yeniden kullanılmaz.

Örnek olarak önceki derste çözülen sırt çantası (knapsack) problemi hatırlatıldı. Bir hırsız, sırt çantasının taşıyabileceği ağırlığı aşmadan evdeki eşyalardan değeri olabildiğince yüksek olanları almak ister. Kaba kuvvet (brute force) yaklaşımında birinci eşya, birinciyle ikinci, ikiyle üç gibi bütün olasılıkların denenmesi gerekir; bu üstel (exponential) bir durumdur. Önceki bilgiler tutulup kullanılırsa üstel olmadan çözüme ulaşılır: her eşya sayısı ve her kilo için kazanç bir tabloda tutulur, son göz en büyük kazancı verir.

Ekrandaki bağıntı ve tablo (ekrandan, 00:05:00):

$$
P[i,w] =
\begin{cases}
P[i-1,w] & w_i > w \text{ ise (eşya alınmaz, NOT TAKEN)}\\
\max\{v_i + P[i-1,w-w_i],\ P[i-1,w]\} & \text{aksi halde}
\end{cases}
$$

Başlangıç: $P[0,j] = 0$, $P[i,0] = 0$. $\max$ içindeki ilk terim "alırsam", ikincisi "almazsam" seçeneğidir.

| Eşya | Ağırlık | Değer |
|---|---|---|
| 1 | 2 | 12 |
| 2 | 1 | 10 |
| 3 | 3 | 20 |
| 4 | 2 | 15 |

```text
 i \ w   0   1   2   3   4   5
   0     0   0   0   0   0   0
   1     0   0  12  12  12  12
   2     0  10  12  22  22  22
   3     0  10  12  22  30  32
   4     0  10  15  25  30  37
```

Tablo python ile doğrulandı; en büyük kazanç 37'dir. Ekranda örneğin $P(1,2) = \max\{12 + P[0,0],\ P[0,2]\} = 12$ ve $P(2,3) = \max\{10 + P[1,2],\ P[1,3]\} = 22$ adımları görülmektedir.

> **Ders sonrası not:** Hoca tekrar sırasında en büyük taşıma kapasitesini "4 kilo" olarak söyledi; ekrandaki tabloda kapasite sütunları 0'dan 5'e kadardır ve 37 sonucu 4. eşya ve 5 kilo için bulunmuştur.

Hoca dinamik programlamanın ortak yapısını şöyle özetledi: ana problem çözülebilir alt problemlere bölünür, sonuçlar bir matriste saklanır ve mutlaka bir yineleme (recurrence) bağıntısı kurulur. Bu bağıntı farklı durumları (eşya yokken, ağırlık sıfırken, eklenen eşya kapasiteyi aşıyorsa) ayrı ayrı gösterir.

## 2. Edit Distance Problemi ve Kullanım Alanları

Dinamik programlamanın iyi örneklerinden biri düzenleme uzaklığı (edit distance) problemidir. Yazım denetimi (spell checking) bunun tipik kullanım alanıdır. Örneğin "elma" yazacakken "elm" yazılırsa sistem "elma mı demek istediniz?" ya da "elim mi demek istediniz?" diye sorar (ekrandan, 00:15:00). Yazılan kelime sözlükte yoktur; sistem sözlükte olan ve doğru olabilecek kelimeleri önerir. Kelime işlemcilerde, mesajlaşma uygulamalarında ve arama motorlarında bu tür düzeltmeler yapılır.

Ekrandaki ikinci örnek İngilizce "algorithm" kelimesidir: "algoritm" yazılırsa arama motoru araya bir H'nin unutulduğunu anlar; "algoritma" yazılırsa hem fazladan bir A olduğunu hem de H'nin unutulduğunu anlayıp "algorithm" için sonuç getirir.

Biyoinformatikte birebir aynı iki DNA dizisi olmayabilir; aralarda kopukluklar ya da dönüşümler olmuş olabilir. Büyük dizileri gözle karşılaştırmak mümkün değildir; sorgulanan diziye birebir aynı olmayan ama en çok benzeyen dizi önerilir. Ses tanımada da kelime doğru telaffuz edilmediğinde ya da sistem tam yakalayamadığında en benzer kelime aynı yöntemle gösterilebilir.

Veri yapıları ve algoritmalar dersinde görülen string aramada doğru bir kelime ya da metin parçası başka bir metnin içinde birebir aranıyordu. Gerçek dünyada ise birebir eşleşmeyen bilgilerin de kullanılabilmesi gerekir. Edit distance, tamamen aynı olmayan iki kelimenin (örneğin sözlükteki doğru kelime ile kullanıcının yazdığı yanlış kelimenin) birbirine uzaklığını ölçer.

## 3. Levenshtein Yaklaşımı: Dört Durum ve Minimum Uzaklık

Derste Levenshtein algoritması üzerinden ilerlendi. Örnek: SNOWY kelimesi ile SUNNY kelimesi karşılaştırılıyor (ekrandan, 00:15:00). $X$ = SNOWY, $Y$ = SUNNY.

Birinci hizalama:

```text
X:  S  _  N  O  W  Y
Y:  S  U  N  N  _  Y
       D     C  I
```

U'nun $X$'te karşılığı yoktur (delete: $X$'in bir harfi silinmiş), O ile N farklıdır (change), W'nin $Y$'de karşılığı yoktur (insert: $X$'e fazladan harf eklenmiş). Uzaklık 3'tür.

İkinci hizalama:

```text
X:  _  S  N  O  W  _  Y
Y:  S  U  N  _  _  N  Y
    D  C     I  I  D
```

Bu da geçerli bir dönüşümdür ama uzaklığı 5'tir. Snowy'den Sunny'ye birden fazla yolla geçilebilir; aranan, iki kelime arasındaki **minimum** düzenleme uzaklığıdır.

İki harf karşılaştırıldığında dört durum olabilir (ekrandan, 00:25:00):

- Copy: iki harf aynıdır ($x_i = y_j$); örneğin S ile S, N ile N, Y ile Y.
- Delete: $Y$'deki harfin $X$'te karşılığı yoktur (S ile SU karşılaştırılırken U).
- Insert: $X$'teki harfin $Y$'de karşılığı yoktur (SNOW ile SUNN karşılaştırılırken W).
- Change: iki harf farklıdır (O ile N).

**Soru:** Delete, insert ve change dışında dördüncü durum nedir? **Cevap:** Karşılaştırılan iki harfin aynı olması. Aslında istenen durum budur.

Hoca, yineleme bağıntısını kurmanın başta özyinelemeli kod yazmaya alışmak gibi yabancı gelebileceğini, ama bağıntıların hep benzer tarzda kurulduğu için zamanla kolaylaştığını söyledi.

Minimum uzaklığın neden gerektiği şöyle açıklandı: yazım denetleyicisi sözlükteki her kelime için yazılan kelimeyle arasındaki uzaklığı hesaplar ve uzaklığı küçük olan kelimeleri önerir. Bir kelimeye uzaklık 5, başka bir kelimeye 3 ise uzaklığı 3 olan önerilmelidir (hoca bu sayıları örnek olsun diye uydurduğunu belirtti). Bu yüzden her kelime çifti için en küçük uzaklık hesaplanmalıdır.

## 4. Alt Problem ve Yineleme Bağıntısı

### 4.1 Alt problemin tanımı

$X[1..n]$, $n$ karakterli, $Y[1..m]$, $m$ karakterli iki kelime olsun; hedef $ED(X,Y)$'yi, yani $X$'in $n$. ve $Y$'nin $m$. karakterine gelindiğindeki minimum uzaklığı bulmaktır (ekrandan, 00:20:00). Örnek kelimeler $X$ = EXPONENTIAL ve $Y$ = POLYNOMIAL'dır.

Alt problem, iki kelimenin başından başlayıp belli karakterlere kadar olan parçaları karşılaştırmaktır: $ED[i,j]$, $X$'in ilk $i$ karakteri ($X[1..i]$) ile $Y$'nin ilk $j$ karakteri ($Y[1..j]$) arasındaki uzaklıktır. Örneğin $ED[4,3]$, EXPO ile POL arasındaki uzaklıktır. Bu alt problemlerin de alt problemleri vardır (EXP ile PO gibi). Böyle çöze çöze gidilince $ED[n,m]$'ye, yani iki kelimenin tamamının uzaklığına ulaşılır.

Sonuçlar, satırları $X$'in, sütunları $Y$'nin karakterlerini gösteren bir matriste saklanır; $ED[n,m]$ gözü minimum uzaklığı verir.

### 4.2 Üç farklılık durumunun alt problemleri

$x_i \ne y_j$ ise üç sebep olabilir (ekrandan, 00:30:00):

- Case 1, insertion: $x_i$ fazladan eklenmiş bir karakterdir, karşısı boştur. O zaman $x_i$'ye gelmeden önceki durum, $X[1..i-1]$ ile $Y[1..j]$'nin karşılaştırılmasıdır: $ED[i-1,j]$. Ekrandaki örnekte SUNNY ile SUNY karşılaştırılırken fazladan N bu durumdadır.
- Case 2, deletion: $Y$'de fazladan bir $y_j$ vardır, $X$'te karşılığı yoktur. Önceki durum $X[1..i]$ ile $Y[1..j-1]$'dir: $ED[i,j-1]$. Ekrandaki örnekte SUNNY ile SUUNNY karşılaştırılırken fazladan U bu durumdadır.
- Case 3, change: Hiçbir fazlalık ya da eksiklik yoktur, yalnız $x_i$ ile $y_j$ farklıdır. Önceki durum, bir önceki karakterlerin karşılaştırıldığı $ED[i-1,j-1]$'dir.

$x_i = y_j$ ise de bir önceki alt problem $ED[i-1,j-1]$'dir.

Hoca bu dersteki adlandırmayı $X$'e göre yaptı: insertion "$X$'in bir harfi eklenmiş", deletion "$X$'ten bir harf silinmiş" demektir.

> **Ek bilgi (derste anlatılmadı):** Birçok kaynak edit distance'ı "$X$'i $Y$'ye dönüştürme" yönünden adlandırır. O adlandırmada $ED[i-1,j]+1$ "$x_i$'yi silme" (deletion), $ED[i,j-1]+1$ "$y_j$'yi ekleme" (insertion) olur. Bu, bu dersteki adlandırmanın tersidir; uzaklık değeri değişmez, yalnız işlemlerin adı değişir.

### 4.3 Hangi işlemin yapıldığını bilebilir miyiz?

EXPONENTIAL ve POLYNOMIAL'da $x_i$ = O (EXPO'nun son harfi) ve $y_j$ = L (POL'un son harfi) karşılaştırılıyor olsun (ekrandan, 00:35:00). O ile L farklıdır. Sebep, $X$'e fazladan eklenmiş bir O (insert), $Y$'ye fazladan eklenmiş bir L (delete) ya da yalnız bu iki karakterin farklı olması (change) olabilir.

**Soru:** Bu üçünden hangisinin olduğunu bilebilir misiniz? **Cevap:** Bir öğrenci önce karakter uzunluklarının farkının önemli olabileceğini söyledi (ve ekrandaki "delete" satırında O yerine L yazılması gerektiğini fark etti; hoca düzeltti). Hoca, yalnız bu karaktere ya da kelime uzunluklarına bakarak anlaşılamayacağını açıkladı: iki kelimede eşit sayıda karakter olsa bile daha önceki bir yerde ekleme ya da silme olmuş olabilir. Bunu bilmek de gerekmez; önemli olan minimum maliyeti seçmektir.

### 4.4 Bağıntı

Her işlemin maliyeti 1 alınır. Hoca, istenirse bir işleme (örneğin insertion'a) daha yüksek maliyet (örneğin 2) verilebileceğini, ama burada her farklılığın bir puan sayıldığını belirtti. Karakterler aynıysa maliyet yoktur. Ekrandaki bağıntı (ekrandan, 00:40:00):

$$
ED[i,j] = \min
\begin{cases}
ED[i-1,j] + 1 & \text{(insertion)}\\
ED[i,j-1] + 1 & \text{(deletion)}\\
ED[i-1,j-1] + diff(x_i,y_j) & \text{(substitute: copy/change)}
\end{cases}
$$

$$
diff(x_i,y_j) =
\begin{cases}
0 & x_i = y_j\\
1 & \text{aksi halde}
\end{cases}
$$

Başlangıç (initialization): $ED[i,0] = i$ (insert), $ED[0,j] = j$ (delete). Değerler üst üste eklenerek gidildiği için başlangıç zorunludur: bir tarafta kelime yokken diğer tarafta kelime varsa, örneğin $X$ = elma ve $Y$ boşsa, E için uzaklık 1, EL için 2, ELM için 3, ELMA için 4 olur. Aynı şekilde $Y$'nin $j$. harfine kadar uzaklık $j$'dir.

> **Hocanın vurgusu:** Sınavlarda "yineleme bağıntısını yazın" diye sorulan şey budur: $ED[i,j]$ alt problemi insertion için $ED[i-1,j]$'ye, deletion için $ED[i,j-1]$'e, change ya da copy için $ED[i-1,j-1]$'e bağlıdır. Hangisinden gelindiği bilinemediği için uzaklığı en küçük olandan ilerlenir.

Hoca, bu konuyu anlamak için çok sayıda örnek çözmeyi tavsiye etti.

## 5. Örnek: ED("MATHS", "ARTS")

$X$ = MATHS (satırlar), $Y$ = ARTS (sütunlar) (ekrandan, 00:45:00). İlk satır 0, 1, 2, 3, 4'tür: $X$ boşken $Y$'nin harfleri teker teker gelir. İlk sütun 0, 1, 2, 3, 4, 5'tir: $Y$ boşken M, MA, MAT, ... eklenir. Her göz için üç komşuya bakılır: yukarı ($ED[i-1,j]$, aynı sütunun üst satırı), sol ($ED[i,j-1]$, aynı satırın önceki sütunu), çapraz ($ED[i-1,j-1]$).

Adım adım (altyazı ve kareden):

- M ile A: farklı, maliyet 1. Yukarı $1+1=2$, sol $1+1=2$, çapraz $0+1=1$. Sonuç 1 (çaprazdan).
- M ile R: farklı. Sol $1+1=2$, çapraz $1+1=2$, yukarı $2+1=3$. Sonuç 2 (soldan ya da çaprazdan). Hoca, maliyeti büyük olan yolu düşünmeye gerek olmadığını belirtti.
- M ile T: 3; M ile S: 4 (soldan ya da çaprazdan).
- A ile A: eşit. Çaprazdan maliyetsiz gelinir: $ED[1,0] + 0 = 1$.
- A ile R: 2; A ile T: 3; A ile S: 4.
- T ile A: farklı, yukarıdan $1+1=2$. T ile R: 2. T ile T: eşit, çaprazdan $ED[2,2] + 0 = 2$. T ile S: farklı, soldan $2+1=3$.
- H ile A: farklı. Yalnız yukarıdan gelinir: $2+1=3$; çaprazdan $3+1=4$, soldan $4+1=5$ olurdu. H ile R: 3. H ile T: 3 (çapraz ya da yukarı). H ile S: 3.
- S ile A: 4 (yukarıdan); S ile R: 4; S ile T: 4; S ile S: eşit, çaprazdan $ED[4,3] + 0 = 3$.

Tamamlanmış tablo (python ile doğrulandı):

```text
        -  A  R  T  S
    -   0  1  2  3  4
    M   1  1  2  3  4
    A   2  1  2  3  4
    T   3  2  2  2  3
    H   4  3  3  3  3
    S   5  4  4  4  3
```

Sonuç: ED("MATHS", "ARTS") = 3 (ekrandan, 01:10:00).

**Soru:** (A ile A gözü için) Diğer yönden gelince 2 olması gerekmiyor muydu? **Cevap:** $x_i = y_j$ ise maliyet 0'dır ve bir önceki durum yalnız $ED[i-1,j-1]$'dir; çaprazdan gelinir ve üzerine bir şey eklenmez. Yukarıdan gelinseydi maliyet eklemek gerekirdi ($1+1=2$), bu da daha büyük olurdu. Karakterler eşitse mutlaka çaprazdan gelinir, çünkü $X[1..i]$ ile $Y[1..j]$'den önceki durum $X[1..i-1]$ ile $Y[1..j-1]$'dir.

**Soru:** Sonuçtaki 3 nereden geldi? **Cevap:** $ED[i,j]$, $X$'te 1'den $i$'ye, $Y$'de 1'den $j$'ye kadar olan harflerin uzaklığıdır. Örneğin MA satırı ile ART sütununun kesiştiği göz MA ile ART'ın uzaklığıdır. $ED[n,m]$ gözü ise iki kelimenin tamamının, yani MATHS ile ARTS'ın uzaklığıdır; 3 oradan gelir.

Bu sonuç yazım denetiminde şöyle kullanılır: bir eşik (threshold) belirlenir, örneğin uzaklığı 3'ten (ya da 4'ten) küçük kelimeler kullanıcıya önerilir. Hangi harfin eklendiği ya da silindiğiyle ilgilenmeden kelime "bunu mu demek istediniz?" diye önerilebilir.

**Soru:** Bu matrisi doldurmanın zaman karmaşıklığı nedir? **Cevap:** $n \cdot m$. İki kelime genelde birbirine benzer uzunlukta olduğu için $m \approx n$ ise $O(n^2)$ olur.

**Soru:** Yer karmaşıklığı nedir? **Cevap:** Yine $n \cdot m$ (matrisin boyutu).

## 6. Geri İzleme ile Dönüşümün Bulunması

Uzaklığın 3 olduğu bulundu; değişikliğin nasıl oluştuğunu bulmak için tablonun son gözünden ($ED[n,m]$) başlanıp gelinen yol üzerinden geriye gidilir (ekrandan, 01:10:00 ve 01:15:00). Yönlerin anlamı:

- $ED[i,j] = ED[i-1,j-1] + cost$: çaprazdan gelinmiştir (cost 0 ise harfler aynı, 1 ise change).
- $ED[i,j] = ED[i,j-1] + cost$: soldan gelinmiştir, deletion ($Y$'deki harfin $X$'te karşılığı yok).
- $ED[i,j] = ED[i-1,j] + cost$: yukarıdan gelinmiştir, insertion ($X$'in harfi eklenmiş, karşısı boş).

Bunun iki yolu vardır: matris doldurulurken her göz için nereden gelindiği (ok) saklanır, ya da sonradan değerlere bakılarak hesaplanır. Yukarıdan ya da soldan gelinmişse gözdeki değer o komşunun bir fazlası olmalıdır; çaprazdan gelinmişse çaprazdaki değere eşit ya da bir fazlası olmalıdır. Hoca, kendisi olsa kod yazarken okları saklayacağını söyledi.

Ekrandaki geri izleme:

- Sağ alttaki 3: S ile S aynı, çaprazdan gelinmiş (3 = 3).
- H ile T gözü (3): hem çaprazdan hem yukarıdan gelinebilir. Yukarıdan seçildi: H insert edilmiş, karşılığı yok.
- T ile T (2): eşit, çaprazdan.
- A ile R (2): çaprazdan ya da soldan gelinebilir. Soldan seçildi: deletion, R'nin $X$'te karşılığı yok.
- A ile A (1): eşit, çaprazdan.
- M (1): yukarıdan, M insert edilmiş, karşısı boş.

Elde edilen hizalama (ekrandan, 01:15:00):

```text
X:  M  A  _  T  H  S
Y:  _  A  R  T  _  S
```

Üç farklılık vardır (M, R, H); uzaklık 3'tür.

**Soru:** Yukarı yerine diğer çapraza gitseydik farklı bir sonuç mu elde edecektik? **Cevap:** Hayır, uzaklık hep 3 çıkar ama dönüşümün oluşma şekli farklı olur. Örneğin H ile T gözüne çaprazdan gelindiği seçilirse H ile T farklı olduğu için orada bir change oluşur ve başka bir hizalama bulunur. Hoca ekranda bu biçimde üç farklı çözüm olduğunu gösterdi ve bunları matris üzerinde geri giderken farklı seçimler yaparak bulmayı alıştırma olarak bıraktı.

<!-- BELİRSİZ: Hocanın ekranda gösterdiği ikinci ve üçüncü hizalamalar elimizdeki karelerde okunmuyor; yalnız ilk hizalama kareden alındı. -->

## 7. En Uzun Ortak Alt Dizi (LCS)

### 7.1 Problem

Çok kullanılan bir başka yöntem en uzun ortak alt dizidir (Longest Common Subsequence, LCS). Biyoinformatikte çok kullanılır; görüntü işlemede hareket benzerliği bulmak için de kullanılır. Amaç, iki dizide aynı sırayla geçen en uzun ortak harf grubunu bulmaktır.

DNA alfabesi A, C, G, T'den oluşur. Örnek (ekrandan, 01:20:00): $X$ = ATCTGAT, $Y$ = TGCATA. Aralarda eklemeler ya da çıkarmalar olabilir, ama sırası bozulmadan devam eden en uzun ortak grup aranır. Bu örnekte TCTA ve TGAT ortak alt dizilerdir: T, C, T, A harfleri her iki dizide de bu sırayla geçer. Elde uzun bir bilgi vardır, aralarda o bilgiyi bozan bir şeyler vardır; amaç bilginin ortak en uzun bölümünü bulmaktır.

> **Ek bilgi (derste anlatılmadı):** Bu örnekte LCS uzunluğu 4'tür (python ile doğrulandı); TCTA ve TGAT dışında aynı uzunlukta başka ortak alt diziler de olabilir.

### 7.2 Kaba kuvvet

Kaba kuvvette $X$'in bütün alt dizileri $Y$ ile karşılaştırılır; $X$ $m$ uzunluklu ise $2^m$ alt dizi vardır ve sonuç üsteldir. Bunun sebebi her denemede önceki denemelerin tecrübesinden faydalanılmamasıdır: bir, iki, üç alınır; sonra beş çıkarılıp dört konur ve önceki bilgi kaybolur. Önceki sonuçlar bir dizi ya da matriste tutulursa problem $n \cdot m$ karmaşıklıkla çözülür.

### 7.3 Alt dizi (subsequence)

Bir kelimenin alt dizisi, harfleri orijinal sıraları korunarak seçilerek oluşturulur (ekrandan, 01:25:00). Örneğin "yakamoz" kelimesinden yak, yaka, yama, yaz alt dizileri çıkarılabilir. Seçilen harflerin orijinal dizideki konumları $i_1, i_2, \ldots, i_k$ artan sırada olmalıdır: "yama" için Y 1., A 2., M 5., A 6. harftir. 1., 3., 2., 7. harf gibi bir sıra alt dizi olmaz.

$X = \langle x_1, x_2, \ldots, x_m \rangle$ ve $Y = \langle y_1, y_2, \ldots, y_n \rangle$ için LCS, ikisinin ortak harflerinden oluşan en uzun alt dizidir.

> **Ek bilgi (derste anlatılmadı):** Alt dizi (subsequence) ile alt string (substring) farklıdır: alt stringde harfler bitişik olmak zorundadır, alt dizide yalnız sıranın korunması gerekir.

### 7.4 Durumlar ve bağıntı

Case 1 (ekrandan, 01:30:00): $X$ = ACGT, $Y$ = GT ve $x_i = y_j$ = T. Karakterler eşitse bir önceki durum $x_{i-1}$ ile $y_{j-1}$'in karşılaştırıldığı durumdur ve ortak bir karakter daha bulunduğu için uzunluk bir artar:

$$LCS[i,j] = LCS[i-1,j-1] + 1$$

Case 2: $X$ = ACGT, $Y$ = GC; $x_i$ = T, $y_j$ = C, yani $x_i \ne y_j$. Üç seçenek vardır: ya $x_i$ ortak alt dizinin parçası değildir (o zaman $LCS[i-1,j]$'den gelinir), ya $y_j$ parçası değildir ($LCS[i,j-1]$'den gelinir), ya da ikisi birden değildir. En uzun ortak alt dizi arandığı için bunların maksimumu alınır.

Ekrandaki bağıntı (ekrandan, 01:35:00); $LCS[i,j]$, $X$'te $i$., $Y$'de $j$. karaktere kadar olan ortak alt dizinin uzunluğudur:

$$
LCS[i,j] =
\begin{cases}
0 & i = 0 \text{ ya da } j = 0\\
LCS[i-1,j-1] + 1 & i,j > 0 \text{ ve } x_i = y_j\\
\max\{LCS[i,j-1],\ LCS[i-1,j]\} & i,j > 0 \text{ ve } x_i \ne y_j
\end{cases}
$$

İlk satır ve ilk sütun 0'dır, çünkü bir taraf boşken ortak bir şey yoktur. Önce uzunluk hesaplanır, ortak dizinin kendisi sonra bulunur.

### 7.5 Örnek: LCS(BACDB, BDCB)

$X$ = BACDB (satırlar), $Y$ = BDCB (sütunlar) (ekrandan, 01:35:00 ve 01:40:00).

- B ile B: eşit, çaprazdan $0+1 = 1$.
- B ile D: farklı, uzunluk değişmez; soldan 1. Bu göz B ile BD'nin karşılaştırılmasıdır, ortak alt dizi B'dir.
- B ile C: 1 (B ile BDC; ortak alt dizi yine B).
- B ile B: eşit, çaprazdan $0+1 = 1$. Bu göz B ile BDCB'dir; tek bir B vardır.
- A satırı: A hiçbir harfe eşit değildir; değerler yukarıdan ya da soldan gelir ve hepsi 1'dir (BA ile BDC'nin ortak alt dizisi yalnız B'dir).
- C satırı: C ile B 1, C ile D 1, C ile C eşit, çaprazdan $1+1 = 2$; C ile B 2 (BAC ile BDCB'nin ortak alt dizisi BC).
- D satırı: D ile B 1, D ile D eşit, çaprazdan $1+1 = 2$; sonra 2, 2.
- B satırı: B ile B 1, B ile D 2, B ile C 2, B ile B eşit, çaprazdan $2+1 = 3$.

Tamamlanmış tablo (python ile doğrulandı):

```text
        -  B  D  C  B
    -   0  0  0  0  0
    B   0  1  1  1  1
    A   0  1  1  1  1
    C   0  1  1  2  2
    D   0  1  2  2  2
    B   0  1  2  2  3
```

İki dizinin en uzun ortak alt dizisinin uzunluğu 3'tür. Örneğin BCB ve BDB her iki dizide de geçen ortak alt dizilerdir.

> **Ders sonrası not:** Hoca sonucu anlatırken "ortak substring" dedi; doğrusu "ortak alt dizi (subsequence)"dur. BCB ve BDB, her iki dizide de bitişik harflerden oluşmaz.

Ortak alt dizinin hangi harflerden oluştuğunu bulmak için tablo doldurulurken her gözün hangi yoldan geldiğinin işaretlenmesi gerekir; bunun algoritması sonraki derse bırakıldı.

## Örnek Sorular

### Soru 1 (derste sözlü, 00:14:58)

İki harf karşılaştırıldığında delete, insert ve change dışında olabilecek dördüncü durum nedir?

> **Çözüm:** İki harfin birbirine eşit olması (copy). Bu durumda maliyet 0'dır.

### Soru 2 (ekrandan, 00:35:00; derste sözlü, 00:33:59)

EXPONENTIAL ve POLYNOMIAL kelimelerinde EXPO'nun son harfi O ile POL'un son harfi L karşılaştırılıyor. O ≠ L. Bu farkın insert, delete ya da change'den hangisinden geldiğini yalnız bu karakterlere bakarak bilebilir misiniz?

> **Çözüm:** Hayır. Ne yalnız bu karakterlere ne de kelime uzunluklarına bakarak anlaşılabilir; daha önceki bir yerde ekleme ya da silme olmuş olabilir. Bilmek de gerekmez: üç seçeneğin ($ED[i-1,j]+1$, $ED[i,j-1]+1$, $ED[i-1,j-1]+1$) en küçüğü alınır.

### Soru 3 (ekrandan, 00:45:00)

ED("MATHS", "ARTS") = ?

> **Çözüm:** Bölüm 5'teki tablo doldurulur; $ED[5,4] = 3$. Bir hizalama: `M A _ T H S` / `_ A R T _ S`.

### Soru 4 (derste sözlü, 00:51:28 ve 00:52:04)

MATHS/ARTS tablosunda A ile A gözüne nereden gelinir? Yukarıdan gelince değer 2 olmaz mı?

> **Çözüm:** Harfler eşit olduğu için çaprazdan gelinir ve maliyet 0 eklenir: $ED[1,0] + 0 = 1$. Yukarıdan gelmek maliyet ekler ($1 + 1 = 2$) ve minimum olmaz; ayrıca harfler eşitse bir önceki durum $ED[i-1,j-1]$'dir.

### Soru 5 (derste sözlü, 00:58:28 ve 00:59:04)

Edit distance matrisini doldurmanın zaman ve yer karmaşıklığı nedir?

> **Çözüm:** Zaman $O(n \cdot m)$, yer $O(n \cdot m)$. $n \approx m$ ise $O(n^2)$.

### Soru 6 (ekrandan, 01:35:00)

$X$ = ⟨BACDB⟩, $Y$ = ⟨BDCB⟩ için LCS uzunluğunu bulun.

> **Çözüm:** Bölüm 7.5'teki tabloya göre $LCS[5,4] = 3$; ortak alt dizilere örnek BCB ve BDB.

### Soru 7 (ekrandan, 01:20:00)

DNA dizileri $X$ = ATCTGAT ve $Y$ = TGCATA için en uzun ortak alt diziyi bulun.

> **Çözüm:** Derste TCTA ve TGAT örnek olarak gösterildi; ikisinin de uzunluğu 4'tür. Tablo derste doldurulmadı; LCS uzunluğunun 4 olduğu python ile doğrulandı.

## Dersin Toparlaması

Bu derste dinamik programlamanın iki klasik string uygulaması işlendi. Edit distance (Levenshtein) problemi, iki kelime arasındaki minimum ekleme, silme ve değiştirme sayısını bulur; $ED[i,j]$ alt problemi üç komşudan (yukarı, sol, çapraz) en küçük olanı seçerek doldurulur ve sonuç $ED[n,m]$ gözündedir. Tablo $O(nm)$ zaman ve yerle doldurulur; geri izleme ile aynı uzaklıkta farklı dönüşümler bulunabilir. MATHS ile ARTS arasındaki uzaklık 3 bulundu.

İkinci konu olan en uzun ortak alt dizide, harfler eşitse çapraz değere 1 eklenir, değilse sol ve üst değerlerin büyüğü alınır. BACDB ile BDCB için LCS uzunluğu 3 bulundu. Ortak alt dizinin harflerinin geri izlemeyle nasıl bulunacağı ve algoritması sonraki derse bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
