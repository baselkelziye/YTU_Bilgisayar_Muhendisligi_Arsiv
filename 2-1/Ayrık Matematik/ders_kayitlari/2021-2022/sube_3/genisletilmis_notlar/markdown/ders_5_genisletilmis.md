# Ders 5 Genişletilmiş Notu: Algoritmalar, Temel Veri Yapıları, Yığınla İfade Dönüşümleri ve Algoritma Analizine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Algoritma Kavramı
- 2. Algoritmaların Özellikleri
- 3. Arama Algoritmaları
- 4. Sıralama Algoritmaları
- 5. Öklid Algoritması ile EBOB
- 6. Algoritma Tasarım Yöntemleri ve Temel Problem Türleri
- 7. Temel Veri Yapıları
- 8. Yığın Uygulaması: Infix, Prefix ve Postfix Notasyonları
- 9. İfadelerin Yığınla Değerlendirilmesi
- 10. Notasyonlar Arası Dönüşümler
- 11. Algoritma Analizine Giriş
- Örnek Sorular
- Dersin Toparlaması

## 1. Algoritma Kavramı

Önceki bölümde "matematiğin dili" başlıklı konu bitmişti; bu derste algoritmalar bölümüne geçildi. Hoca bu bölümün hem algoritma kavramını hem de gelecek dönemki veri yapıları ve algoritma analizi derslerine hazırlık niteliğindeki temel kavramları kapsadığını söyledi: algoritma nedir, veri yapısı nedir, fonksiyonların büyümesi, asimptotik notasyonlar ve algoritmaların karmaşıklık analizi.

Algoritmanın amacı bir gerçek dünya problemini çözmek ya da bir hesaplama yapmaktır. Bunun için algoritmanın **sonlu sayıda kesin adımdan** oluşması gerekir. "Kesin" sözcüğüyle kastedilen İngilizcedeki *unambiguous*, yani muğlak olmayan ifadedir. Hoca bunu şöyle açıkladı: "Sayının karekökünü al" diye bir adım algoritma sayılmaz; karekökün nasıl alınacağının adım adım söylenmesi gerekir. Ayrıca adımlar **sıralı** olmalı, iş baştan sona belirli bir sırayla yapılmalıdır. **Sonluluk** ise kodun 100 ya da 500 satır olmasıyla değil, algoritmanın çalışmasının sonlu sürede bitmesiyle ilgilidir; sonsuza kadar çalışan bir algoritma istenmez.

### 1.1 Örnek: Dizide en büyük elemanı bulma

Bir tamsayı dizisindeki en büyük değeri bulmak için yazıyla ifade edilmiş algoritma şöyledir:

1. Dizinin ilk elemanı geçici maksimum olarak seçilir ($max = d_0$).
2. Bir sonraki eleman geçici maksimumla karşılaştırılır.
3. Eleman geçici maksimumdan büyükse geçici maksimum bu elemana atanır.
4. Dizinin son elemanına kadar 2. ve 3. adımlar tekrarlanır.
5. Tekrar bittiğinde geçici maksimum dizinin en büyük elemanıdır.

Hoca bu adımlardaki işlemlerin her birinin bilgisayarda kesin bir karşılığı olduğunu vurguladı: karşılaştırma için Assembly'de `CMP` komutu, programlama dillerinde `if` vardır; seçme işlemi `=` ile yapılan bir atamadır; tekrar için döngüler kullanılır. Yani algoritma, sonlu bir işlem kümesinin (atama, karşılaştırma, koşul, tekrar) elemanlarından kurulur.

### 1.2 Algoritmanın ifade biçimleri

Bir algoritma sözle, adım adım yazıyla, sözde kodla (*pseudocode*), akış şemasıyla ya da doğrudan bir programlama diliyle ifade edilebilir. Hoca sözde kodu bir ara basamak olarak gördüğünü söyledi: kod yazıldıktan sonra değiştirmek zor olabileceği için önce ortak bir dilde ifade etmek faydalıdır. Günümüzde algoritma analizi kitaplarının çoğunda C ya da Python tarzında yazılmış kodlar bulunur; çoğu dil C'den türediği için bunlar kolay anlaşılır.

## 2. Algoritmaların Özellikleri

Slaytta algoritmaların özellikleri şöyle verildi (ekrandan, 00:20:00):

- **Giriş (Input):** Bir algoritma, belirli bir kümeden giriş değerlerine sahiptir.
- **Çıkış (Output):** Algoritma, girdi değerlerinden belirli bir kümeden çıktı değerlerini üretir. Çıktı değerleri çözümdür.
- **Doğruluk (Correctness):** Bir algoritma, her girdi değeri kümesi için doğru çıktı değerlerini üretmelidir.
- **Sonluluk (Finiteness):** Bir algoritma, herhangi bir girdi için sınırlı sayıda adımdan sonra çıktı üretmelidir.
- **Etkililik (Effectiveness):** Algoritmanın her adımını doğru ve sınırlı bir süre içinde gerçekleştirmek mümkün olmalıdır.
- **Genellik (Generality):** Algoritma, istenen formdaki tüm problemler için çalışmalıdır.

**Soru:** Bir algoritmanın her zaman yüzde yüz doğru sonuç vermesi şart mıdır? **Cevap:** Bir öğrenci "gerekmez" dedi. Hoca gerekçesini şöyle açıkladı: Bazı problemlerde kesin çözüme ulaşmak çok güçtür; belki çok sayıda bilgisayarın kapasitesini aşan, yıllar sürecek işlem gerekir. Böyle durumlarda optimuma yakın bir çözüm bulmak yeterli olabilir. Örneğin gezgin satıcı problemi. Bu yüzden doğruluk bir yere kadar aranır, ama sonluluk mutlaka sağlanmalıdır.

Etkililik (*efficiency* olarak da anıldı) kaynakların, özellikle zamanın ve belleğin etkin kullanılmasıdır. Genellik için hoca şu örneği verdi: Yazdığınız program yalnız 10 elemanlı diziyi sıralıyorsa genel değildir; $n$ elemanlı diziyi işleyecek biçimde yazılmalıdır (bunun için dinamik bellek ayırma gibi araçlardan yararlanılabilir).

Ardından en büyük elemanı bulan algoritmanın biçimsel (prosedür) hali üzerinden özellikler kontrol edildi: girişi ve çıkışı var; doğruluğu test edilebilir; 2'den $n$'e kadar gittiği için sonlu; adımları doğru ve etkin; "3'e ya da 5'e kadar" değil "$n$'e kadar" dediği için genel.

## 3. Arama Algoritmaları

Arama, sıralama ve optimizasyon problemleri algoritmaların özelliklerini (zaman karmaşıklığı, bellek karmaşıklığı, doğruluk) test etmek ve farklı stratejilerle yazılmış algoritmaları karşılaştırmak için çok kullanılır.

Aramada temel iş, bir küme içinde aranan elemanı bulmaktır. Aranan şey yalnız bir tamsayı değil, herhangi bir nesne olabilir. Hoca günlük hayattan örnek verdi: Bir sisteme giriş (*login*) yapıldığında kullanıcı bilgileri aranır; bulunursa giriş yapılır, bulunmazsa uyarı verilir ve program buna göre şekillenir.

### 3.1 Doğrusal arama

Doğrusal arama kaba kuvvet (*brute force*) yöntemiyle yazılmış basit bir algoritmadır: olası bütün durumlar baştan sona tek tek kontrol edilir. Slayttaki tanım: "Doğrusal Arama algoritması, aranan sayıyı dizinin elemanlarını baştan başlayarak birer birer incelemesidir." Sözde kod (ekrandan, 00:25:00):

```text
procedure linear search(x: integer, a1, a2, ..., an: distinct integers)
i := 1
while (i <= n and x != ai)
    i := i + 1
if i <= n then location := i
else location := 0
return location   {location, x'e eşit terimin indisi; bulunamazsa 0}
```

Döngüde iki koşul birlikte kontrol edilir: son elemana ulaşılıp ulaşılmadığı ($i \le n$) ve elemanın bulunup bulunmadığı ($x \ne a_i$). Hoca burada neden `for` değil `while` kullanıldığını vurguladı: `for` döngüsü başlangıcı, bitişi ve adım sayısı belli olan durumlarda kullanılır; aramada ise döngü arada herhangi bir yerde bitebilir.

**Soru:** En iyi durumda eleman kaç denemede bulunur? **Cevap:** Bir denemede. Ama 2., 3., ..., $n$. denemede bulunma olasılığı da vardır.

> **Hocanın vurgusu:** Dizide arama yapılırken genellikle elemanın değeri değil, **konumu** aranır ve döndürülür. Örneğin öğrenci kayıtlarından oluşan bir listede belirli bir numaraya sahip öğrencinin hangi konumda olduğu bulunursa, o konumdan numarasına, adına, soyadına ve diğer bilgilerine ulaşılabilir.

### 3.2 İkili arama

İkili arama (*binary search*) belirli bir şart altında doğrusal aramadan çok daha hızlıdır. **Soru:** Bu şart nedir? **Cevap:** Dizinin sıralı olması.

Sıralı bir listede tek tek bakmaya gerek yoktur: küçükten büyüğe sıralı bir dizide en küçük eleman baştaki, en büyük eleman sondakidir. Herhangi bir eleman aranırken ortadaki elemanla karşılaştırılır ve bu karşılaştırmanın sonucuna göre her adımda dizinin yarısı aramanın dışına itilir.

Algoritmada iki değişken tutulur: sol uç $i = 1$ ve sağ uç $j = n$ (son eleman). $i < j$ olduğu sürece orta nokta $m$ bulunur. Aranan $x$ orta noktadaki elemandan büyükse $i = m + 1$ yapılır (aranan eleman sağ yarıdadır, orta nokta dahil edilmez); değilse $j = m$ yapılır. Döngü bitince $a_i = x$ ise konum $i$ döndürülür, değilse 0 (ya da $-1$, `null` gibi bir değer) döndürülür. Hoca, slayttaki koşul "büyüktür" olduğu için eşitlik durumunda $j = m$ yapıldığını, istenirse "büyük eşittir" ile de yazılabileceğini belirtti.
<!-- BELİRSİZ: İkili arama slaytının karesi okunmadı; koşullar altyazıdan aktarıldı. -->

## 4. Sıralama Algoritmaları

Slayttaki tanım (ekrandan, 00:30:00): "Bir dizinin öğelerini sıralamak, onları artan sıraya koymaktır (sayısal sıra, alfabetik vb.)." Varsayılan sıralama küçükten büyüğe (artan, *increasing*) sıralamadır. Sıralama önemli bir problemdir; donanım kaynaklarının önemli bir kısmı büyük veri tabanlarını belirli bir sırayla sunmak için sıralamaya ayrılır ve çok sayıda sıralama algoritması geliştirilmiştir.

> **Ders sonrası not:** Slaytta "Donanım kaynaklarının önemsiz bir yüzdesi ... ayrılmıştır" yazıyor; hoca bunu "önemli bir yüzdesi" diye okudu. Anlam açısından doğrusu "önemli bir yüzdesi"dir (slayttaki "önemsiz" büyük olasılıkla çeviri hatası).

Hoca günlük hayatta yapılan işlemlerin çoğunun aslında arama olduğunu (veri tabanları, alışveriş siteleri) ve aramada hızın çok önemli olduğunu söyledi. Hızlı arama için önceden yapılan işlem **indekslemedir** (*indexing*); sıralama da bir tür indekslemedir. Kayıtlar değere göre sıralandığında değere göre indekslenmiş olur. Değerler her zaman basit türlerden oluşmaz; örneğin kitaplar adına ya da adıyla birlikte yazarına göre, yani birden fazla ölçüte göre sıralanabilir. Hepsinin amacı istenen kayda kolay erişimdir.

### 4.1 Kabarcık sıralama (bubble sort)

Slayttaki tanım (ekrandan, 00:35:00): "Kabarcık sıralama, bir dizide birden çok geçiş yapar. Sıra dışı olduğu tespit edilen her öğe çifti değiştirilir." Sözde kod:

```text
procedure bubblesort(a1, ..., an: real numbers with n >= 2)
for i := 1 to n-1
    for j := 1 to n-i
        if aj > aj+1 then interchange aj and aj+1
{a1, ..., an is now in increasing order}
```

Hoca algoritmanın mantığını $4, 2, 7, 8, 3, 1$ dizisi üzerinde tahtada gösterdi:

- **1. tur:** $4$ ile $2$ karşılaştırılır, sıra bozuk olduğu için yer değiştirir: $2, 4, 7, 8, 3, 1$. $4$ ile $7$, $7$ ile $8$ sıralıdır. $8$ ile $3$ yer değiştirir (*swap*): $2, 4, 7, 3, 8, 1$. $8$ ile $1$ yer değiştirir: $2, 4, 7, 3, 1, 8$.
- Birinci turun sonunda en büyük eleman (8), yer değiştire değiştire en sona taşınmıştır. "Kabarcık" adı buradan gelir.
- **2. tur:** $2$-$4$ ve $4$-$7$ sıralıdır. $7$ ile $3$ yer değiştirir: $2, 4, 3, 7, 1, 8$. $7$ ile $1$ yer değiştirir: $2, 4, 3, 1, 7, 8$. $7$-$8$ sıralıdır. Artık dizinin son iki elemanı sıralanmıştır.
- Aynı biçimde devam edilince 3. tur sonunda $2, 3, 1, 4, 7, 8$; 4. tur sonunda $2, 1, 3, 4, 7, 8$; 5. tur sonunda $1, 2, 3, 4, 7, 8$ elde edilir (ara adım eklendi; python ile doğrulandı).

Kodlamak için iç içe iki döngü yeterlidir; içteki döngüde $a_j$ ile $a_{j+1}$ karşılaştırılır. Dış döngü $n-1$'e kadar gider, çünkü her turda en büyük eleman sona yerleşir ve son tek eleman zaten yerindedir. İç döngü $n-i$'ye kadar gider, çünkü sona yerleşmiş elemanlara bakmaya gerek yoktur. Azalan sıralama için yalnız karşılaştırma işaretini ters çevirmek yeterlidir.

**Soru:** 6 elemanlı bir dizi en fazla kaç turda sıralanır? **Cevap:** Birinci turda en büyük eleman sona, ikinci turda en büyük iki eleman son iki konuma gelir; böyle devam edince en fazla $n-1$ turda iş biter. Ama daha erken bitme ihtimali de vardır.

> **Hocanın vurgusu:** Herhangi bir turda bütün karşılaştırmalar sonunda hiç yer değiştirme yapılmadıysa dizi sıralıdır ve algoritma durdurulabilir. Bunu bir bayrak (*flag*) değişkeniyle kontrol etmek kabarcık sıralamayı kısaltır. Hoca bu kodu yapısal programlama dersi için bir alıştırma olarak yazmayı önerdi.

Hoca ikinci bir slayt örneğini de turlar halinde izledi ve ilk geçişte en büyük elemanın doğru (en son) konuma geldiğini, her turda bir elemanın daha yerini bulduğunu gösterdi.
<!-- BELİRSİZ: İkinci kabarcık sıralama örneğinin slayt karesi okunmadı; altyazıdaki anlatım karışık olduğu için adımlar aktarılmadı. -->

### 4.2 Seçmeli sıralama (selection sort)

Seçmeli sıralamada $n$ eleman içinden en küçüğü bulunup ilk konuma yazılır, sonra kalanlar içinden en küçüğü bulunup ikinci konuma yazılır ve böyle devam edilir. Hoca, en küçüğü bulma yöntemi kabarcık sıralamadaki ikili karşılaştırmalardan farklı olsa da elemanların yerleşme sırası açısından kabarcık sıralamanın seçmeli sıralamanın tersi gibi düşünülebileceğini söyledi: kabarcıkta her turda en büyük sona gider, seçmelide her turda en küçük başa yazılır.

### 4.3 Araya eklemeli sıralama (insertion sort)

Araya eklemeli sıralama, oyun kartlarını elde sıraya dizmeye benzer: bir kart alınır ve "bu buraya, öbürü şuraya" diye yerine yerleştirilir. Algoritma ilk elemanı sıralanmış kabul eder; ikinciden $n$'inci elemana kadar her eleman, sıralı kısımdaki elemanlarla karşılaştırılarak yerine yerleştirilir. Yer arama baştan sona doğru ($a_1$, $a_2$, ... diye) ya da elemanın kendisinden geriye doğru yapılabilir; bunlar farklı yaklaşımlardır.

Hoca önce tahtada $4, 3, 7, 8, 1$ dizisini kullandı: 4 sıralı kabul edilir; 3, 4'ten küçük olduğu için başa geçer ($3, 4$); 7 ve 8 yerinde kalır; 1 hepsinden küçük olduğu için en başa getirilir ve dizi $1, 3, 4, 7, 8$ olur.

Slayttaki örnek (ekrandan, 00:40:00): "Verilen 3 2 4 1 5 diziyi sıralayınız."

| Adım | Dizi | Açıklama |
|---|---|---|
| A | $2, 3, 4, 1, 5$ | ilk iki pozisyon değiştirilir |
| B | $2, 3, 4, 1, 5$ | üçüncü eleman yerinde kalır |
| C | $1, 2, 3, 4, 5$ | dördüncüsü başlangıca yerleştirilir |
| D | $1, 2, 3, 4, 5$ | beşinci eleman yerinde kalır |

Hoca burada önemli bir noktaya dikkat çekti: Bir elemanın yerini bulmak yetmez, **araya ekleme** de bedava değildir. 1'i 4 ile doğrudan yer değiştiremeyiz; 1'in başa gelmesi için 4, 3 ve 2'nin birer konum sağa kaydırılması (*shift*) gerekir. Günlük hayatta kartı doğrudan araya sokarız ve diğer kartları kaydırmayız, ama dizide algoritmanın doğası gereği kaydırma yapılır. Bu kaydırma işlemi araya eklemeli sıralamayı biraz verimsiz kılar.

## 5. Öklid Algoritması ile EBOB

**Soru:** İki sayının EBOB'unu bulan bir algoritmayı sözle nasıl ifade edersiniz? **Cevap:** Bir öğrenci 1'den küçük sayıya kadar bir değişkeni artırıp iki sayıyı da bölen değeri saklamayı önerdi. Hoca küçük sayıdan 1'e doğru geriye gitmenin daha iyi olduğunu açıkladı: 18 ve 12 için 18'in bölenleri 1, 2, 3, 6, 9, 18; 12'nin bölenleri 1, 2, 3, 4, 6, 12'dir. 1'den başlanırsa ilk ortak bölen 1 ya da 2 bulunup durulabilir, oysa EBOB 6'dır. Küçük sayıdan (12) geriye doğru inilirse 12, 11, 10, ... denenir ve iki sayıyı da bölen ilk sayı olan 6'da durulur.

### 5.1 Öklid algoritması

Öklid'in algoritması $\gcd(m, n) = \gcd(n, m \bmod n)$ bağıntısını $n = 0$ olana kadar uygular; $n = 0$ olunca $m$ sonuçtur. Hoca algoritmanın özyinelemeli göründüğünü ama özyinelemeli yazılmasının şart olmadığını söyledi. Slayttaki sözde kod (ekrandan, 00:45:00):

```text
1. If n = 0, return m and stop; otherwise go to 2
2. Divide m by n and assign the value of the remainder to r
3. Assign the value of n to m and the value of r to n. Go to 1.

while n != 0 do
    r <- m mod n
    m <- n
    n <- r
return m
```

Örnekler:

- $\gcd(60, 24)$: $60 \bmod 24 = 12$ → $\gcd(24, 12)$; $24 \bmod 12 = 0$ → $\gcd(12, 0)$; sonuç **12**.
- $\gcd(18, 12)$: $18 \bmod 12 = 6$ → $\gcd(12, 6)$; $12 \bmod 6 = 0$ → $\gcd(6, 0)$; sonuç **6**.

**Soru:** Bu algoritmada sonuç ($m$) en az kaç olabilir? **Cevap:** Bir öğrenci önce 2 dedi; hoca "yok" deyince başka bir öğrenci 1 dedi. Doğrusu 1'dir: aralarında asal sayıların EBOB'u 1'dir (örneğin 7 ve 3).

> **Ders sonrası not:** Hoca $m = 7$, $n = 3$ izlemesinde ilk kalanı "4" olarak söyledi ve ara adımlar karıştı. Doğru izleme şöyledir: $7 \bmod 3 = 1$ → $(m, n) = (3, 1)$; $3 \bmod 1 = 0$ → $(m, n) = (1, 0)$; sonuç $\gcd(7, 3) = 1$ (python ile doğrulandı). Hocanın vardığı sonuç (1) doğrudur.

### 5.2 Ardışık tamsayı kontrolü

Diğer çözüm "ardışık tamsayı kontrol algoritması"dır:

1. İki sayıdan küçük olanı $t$ değişkenine ata: $t = \min(m, n)$.
2. $m$'yi $t$'ye böl. Kalan 0 ise 3. adıma, değilse 4. adıma git.
3. $n$'yi $t$'ye böl. Kalan 0 ise $t$'yi döndür ve dur, değilse 4. adıma git.
4. $t$'yi 1 azalt ve 2. adıma git.

$m = 18$, $n = 12$ için $t = 12$ ile başlanır. $18 \bmod 12 \ne 0$, $t = 11$; $18 \bmod 11 \ne 0$, $t = 10$; ... böyle $t = 6$'ya gelinir. $18 \bmod 6 = 0$, ardından $12 \bmod 6 = 0$; sonuç 6. Bu yöntem Öklid'e göre daha uzundur.

### 5.3 Neden birden fazla algoritma?

Hoca bu örneklerin amacını şöyle açıkladı: Bir problem için farklı algoritmalar yazılabilir ve bunların yaptığı işlem sayısı farklıdır. Girdi boyutuna bağlı olarak işlem sayısının nasıl değiştiği **algoritma karmaşıklığı** kavramını verir. Girdi boyutu $n$ iken $n^3$ işlem yapan bir algoritma ile $n \log n$ işlem yapan bir algoritma varsa ikincisi tercih edilir; örneğin bir milyon uzunluklu bir veride $n \log n$, $n^3$'e göre çok çok küçüktür. Hoca kaynak olarak bir üniversitenin veri yapıları ve algoritmalar ders slaytlarını önerdi; oradaki benzetmeyle, bir girdi verilen bilgisayarın krankı kaç kez dönecek, yani 10 elemanlı bir girdi için 100 kez mi 1000 kez mi dönecek, bu harcanan enerji ve zaman açısından önemlidir.

## 6. Algoritma Tasarım Yöntemleri ve Temel Problem Türleri

### 6.1 Tasarım yöntemleri

Slayttaki algoritma tasarım yöntemleri (ekrandan, 00:50:00):

- Brute force (kaba kuvvet)
- Divide and conquer (böl ve yönet)
- Decrease and conquer (azalt ve yönet)
- Transform and conquer (dönüştür ve yönet)
- Space and time tradeoffs (bellek-zaman ödünleşimi)
- Greedy (açgözlü)
- Dynamic programming (dinamik programlama)
- Iterative improvement (yinelemeli iyileştirme)
- Backtracking (geri izleme)
- Branch and bound (dal ve sınır)

Kaba kuvvet akla ilk gelen ve hemen hemen bütün olasılıkları deneyerek çözüme ulaşan yöntemdir. Her zaman iyi sonuç vermez, çünkü veri boyutuna bağlı olarak çok fazla işlem gerektirebilir. Bu yüzden başka yöntemler geliştirilmiştir. Böl ve yönet ile azalt ve yönet problemi daha küçük alt problemlere bölerek çözer. Hoca bu yöntemlerin ayrıntılarının algoritma analizi ve veri yapıları derslerinde anlatılacağını, bu derste yalnız mekanizmalarına değinileceğini söyledi.

**Dönüştür ve yönet** bir problemi başka bir problemin çözüm yöntemini kullanacak biçimde dönüştürüp çözmektir. Hoca şu soruyu sordu:

**Soru:** Elimizde bir dizinin en küçük elemanını bulan bir fonksiyon var. Fonksiyonu değiştirmeden dizinin en büyük elemanını nasıl buluruz? **Cevap:** Dizinin bütün elemanları $-1$ ile çarpılır. Örneğin $4, 2, 8, 7$ dizisi $-4, -2, -8, -7$ olur. Fonksiyon bu dizinin en küçüğü olarak $-8$'i verir. Sonuç tekrar $-1$ ile çarpılınca $8$, yani orijinal dizinin en büyük elemanı bulunur.

### 6.2 İyi bir algoritmanın ölçütleri

İyi bir algoritma kısa sürede cevap vermeli (zaman verimliliği) ve belleği uygun kullanmalıdır (bellek verimliliği). Ayrıca kesin çözüm (*exact solution*) üretilemiyorsa optimal ya da yaklaşık çözüm (*approximate solution*) üretebilmesi beklenir. Örneğin gezgin satıcı probleminde kesin çözümü her zaman bulmak mümkün olmaz.

### 6.3 Temel problem türleri

- **Sıralama ve arama.**
- **Metin işleme (string processing):** Bir metin içinde bir örüntü (*pattern*) aranır. Basit yöntemde örüntünün karakterleri sırayla karşılaştırılır; uyuşmazlık olunca örüntü bir karakter kaydırılır. Hoca daha hızlı bir yaklaşım fikrini anlattı: Aranan metin bir metinde olasılık olarak az geçer (Türkçedeki "ve" bağlacı ya da İngilizcedeki "the" bile toplam kelimelerin küçük bir kısmıdır). Karşılaştırma örüntünün sonundan başlanırsa büyük olasılıkla hemen uyuşmazlık bulunur ve örüntü tek seferde daha ileri kaydırılarak birkaç karşılaştırmadan kurtulunur. Ek bellek kullanarak bunu daha da hızlandıran yöntemler de vardır.
- **Çizge (graf) problemleri.**
- **Kombinatorik problemler** (örneğin şifre oluşturma problemleri).
- **Geometrik problemler.**
- **Sayısal problemler:** Sayısal analizde görülen ikiye bölme (*bisection*) yöntemi aralığı yarıya bölerek ilerler; regula falsi (yer değiştirme) yöntemi interpolasyonla daha hızlı sonuca gider. Aynı problem için yöntemler arasında büyük hız farkları olabilir.

> **Ek bilgi (derste anlatılmadı):** Hocanın anlattığı "örüntüyü sondan karşılaştırıp uyuşmazlıkta büyük kaydırma yapma" fikri, büyük olasılıkla Boyer-Moore metin arama algoritmasının temel fikridir. Bu algoritma ön işlemle oluşturulan tablolar (ek bellek) sayesinde kaydırma miktarını belirler.

## 7. Temel Veri Yapıları

### 7.1 Dizi ve bağlı liste

En temel iki veri yapısı **dizi** ve **bağlı liste**dir (*linked list*). İkisi de bir boyutludur ve bellekte doğrudan saklanır, çünkü belleğin kendisi bir boyutludur; bellek iki ya da üç boyutlu değildir. Diğer bütün veri yapıları bunlara bir şekilde dönüştürülür; bu bir **soyutlamadır** (*abstraction*).

Hoca soyutlamayı bir soruyla açıkladı: **Soru:** Gerçekte "hafta sonu" diye bir şey var mı? **Cevap:** Gerçekte gün, gündüz ve gece vardır ve belirli aralıklarla tekrar eder. "Yarın hafta sonu" diye bir yerden mesaj gelmez; beş güne hafta içi, ardından gelen iki güne hafta sonu demişizdir. Bu bizim yaptığımız bir soyutlamadır. Bilgisayar biliminde de gerçek dünyadaki problemler ve nesneler soyut hale getirilir. Yığın, kuyruk, öncelikli kuyruk, çizge, ağaç, küme gibi yapıların hepsi dizilerden ya da listelerden oluşur; dizi ve listeyi iyi kullanmayı bilen bunları da rahat kullanır.

Dizi ile bağlı listenin farkları:

- **Bellekte yerleşim:** Dizi bellekte ardışık (bitişik) hücrelerden oluşur. Bağlı listenin düğümleri bellekte dağınık durabilir; her düğüm yalnız bir sonrakinin adresini tutar. Bu sayede daha esnek yer ayrılabilir, ama adres tutmak için biraz ek bellek harcanır.
- **Araya ekleme:** Diziye araya bir eleman eklendiğinde sonraki elemanların kaydırılması gerekir. Bağlı listede kaydırma olmadan düğümlerin bağlantıları değiştirilerek araya eleman eklenir.
- **Erişim:** Dizide rastgele erişim vardır; dizinin 5. elemanına baştan gitmeden, işaretçi aritmetiği gibi bir yolla doğrudan erişilir. Bağlı listede sıralı erişim öne çıkar; `head` bilinmeden diğer elemanlara ulaşılamaz.

Hoca tahtada bağlı listeyi çizdi (ekrandan, 01:15:00): başta `head` adlı bir işaretçi vardır; ilk düğüm ikincisini, ikinci düğüm üçüncüsünü gösterir; son düğüm `NULL` gösterir (toprak simgesiyle de çizilebilir). Her düğümde bir veri (*data*) alanı bulunur. İstenirse her düğüm kendinden öncekini de gösterebilir (çift yönlü bağlı liste); bu durumda son elemandan geriye doğru da gidilebilir.

Hoca bağlı listeyi sınıfa yapılacak bir duyuru ile benzetti: Hoca duyuruyu bir öğrenciye söyler, o öğrenci bir sonrakine, o da bir sonrakine söyler. Herkes kendinden sonrakini (belki öncekini de) bilir. Mesaj sonunda hocaya geri dönsün istenirse zincir geriye doğru da işletilir.

**String** de dizilerle ya da bağlı listelerle saklanan karakter dizileridir; yapı herhangi bir nesneyi saklayabilir ama yalnız karakterlere özelleştirildiğinde string denir.

### 7.2 Yığın (stack)

Bir dizinin ya da bağlı listenin **yalnız en son noktasına** ekleme ve çıkarma yapılıyorsa bu yapı yığındır. Yığını üst üste konmuş kitaplar gibi düşünmek gerekir. Bağlı liste ile kurulduğunda en son düğümün adresi bir yığın işaretçisinde (*stack pointer*, `sp`) tutulur. Ekleme yapılırken yeni bir düğüm oluşturulur, adresi bağlanır ve `sp` yeni düğüme kaydırılır; çıkarma yapılırken `sp`'nin gösterdiği düğüm çıkarılır ve `sp` bir önceki düğüme geri alınır. Aynı mantık dizilerle de kurulur (ekrandan, 01:15:00).

Yığın **LIFO** (*last in first out*, son giren ilk çıkar) ya da eşdeğer olarak FILO (ilk giren son çıkar) mantığıyla çalışır. İki işlemi vardır: **push** (ekleme) ve **pop** (çıkarma). Hoca `push` işleminin kuyrukta değil, yığına özgü bir işlem adı olduğunu belirtti.

İşlemci içinde de bir yığın işaretçisi vardır; program akışının kontrolünde ve yığın belleğe erişimde kullanılır. Assembly'de bellek yığın (*stack*), ek (*extra*), veri (*data*) ve kod (*code*) segmentlerine ayrılır; yığın segmentine yığın işaretçisi ile erişilir ve yalnız gösterdiği yere ekleme ve gösterdiği yerden çıkarma yapılabilir.

#### Yığının fonksiyon çağrılarında kullanımı

**Soru:** Bir öğrenci fonksiyon çağrılarında yığının nasıl kullanıldığını bilmediğini söyledi. **Cevap:** Hoca şu örneği kurdu: Bir C programında `main` içindeyiz ve 100. satırda `f` fonksiyonu çağrılıyor. `f` içinde 200. satırda `g` çağrılıyor. `g` içinde 300. satırda `g` tekrar çağrılıyor (özyineleme). `f`'ten dönünce programın 100. satırdan, `g`'den dönünce 200. satırdan devam etmesi gerekir; ayrıca `main` içindeki değişkenlerin de bir yerde saklanması gerekir.

Dönüş adresini bellekte tek bir yerde tutmayı düşünelim: 100 oraya yazılır. Ama `f` içinden `g` çağrılınca 200'ü de tutmak gerekir; 200 aynı yere yazılırsa 100 kaybolur. Yığın mantığında ise program çalışırken önce `main` yığına aktarılır; her fonksiyon çağrısında (ya da Assembly'deki kesmelerde) dönüş bilgisi yığının tepesine eklenir: 100, sonra 200, sonra 300 (özyineleme sürdükçe birden fazla kez). Özyinelemeli fonksiyon bir yerde sona erer; o zaman yığından çekme başlar: önce `g`'nin 300. satırından, sonra `f`'in 200. satırından, sonra `main`'in 100. satırından devam edilir. `main` bitince program sona erer.

Hoca topolojik sıralamanın (*topological sort*) da yığınla rahatça çözülebilen bir algoritma olduğunu söyledi. Derslerin ön koşul ilişkisi buna örnektir: bir dersi almak için başka bir dersin alınmış olması gerekir; bu ilişkiler bir çizgeyle gösterilir ve yapılacak işlerin sırası topolojik sıralamayla bulunur.

### 7.3 Kuyruk (queue)

Kuyrukta günlük hayattaki gibi önden çıkılır, arkadan eklenir. İki işaretçiye ihtiyaç vardır: dizinin ya da bağlı listenin başındaki eleman **head**, sonundaki **tail**. `tail`'in gösterdiği yere eleman eklenir, `head`'in gösterdiği yerden eleman çıkarılır; her ekleme ve çıkarmada işaretçiler güncellenir. Kuyruk **FIFO** (*first in first out*, ilk giren ilk çıkar) mantığıyla çalışır.

Kuyruğun yalnız iki işlemi vardır: kuyruğun sonuna eleman ekleyen **enqueue** ve kuyruğun başından eleman çıkaran **dequeue**. Hocanın örneği:

- `enqueue 3`, `enqueue 4`, `enqueue 5` → kuyruk: $3, 4, 5$
- `dequeue` → 3 çıkar; kuyruk: $4, 5$
- `enqueue 8` → kuyruk: $4, 5, 8$
- `dequeue`, `dequeue` → önce 4, sonra 5 çıkar; kuyrukta yalnız 8 kalır.

Dizide ya da listede her konuma erişilebilir; kuyruk ise daha özel amaçlıdır: yalnız başa (çıkarmak için) ve sona (eklemek için) erişilir. Kuyruk ağdaki bir yazıcıya farklı bilgisayarlardan gönderilen belgelerin sırayla işlenmesinde, süreçlerin sıralı işlenmesinde ve arama algoritmalarında kullanılır. Örneğin genişlik öncelikli arama (BFS, *breadth first search*) kuyruk kullanır.

### 7.4 Öncelikli kuyruk (priority queue)

Öncelikli kuyruk normal kuyruktan farklıdır: A, B, C, D sırasıyla gelse bile önceliği yüksek olan D en öne alınabilir. Hoca örnek olarak bilgisayarda çalışan süreçleri gösterdi: Görev yöneticisinde süreçlere öncelik atanabilir; önceliği artırılan süreç işlemciyi daha çok kullanır, yani kuyrukta öne geçer. Hoca bu ayarların işletim sistemi tarafından yönetildiğini, değiştirilirse sisteme zarar verilebileceğini de belirtti.

İleride ağaçlar, çizgeler ve kümeler gibi diğer temel veri yapılarına da değinilecektir.

## 8. Yığın Uygulaması: Infix, Prefix ve Postfix Notasyonları

Bu derste yığının önemli bir uygulaması matematiksel ifadelerin birbirine dönüştürülmesi ve değerlendirilmesidir. **Soru:** Derleyici $2 + 3 \cdot 5$ ifadesinde çarpmayı nasıl önce, toplamayı sonra yapıyor; parantezi nasıl önce değerlendiriyor? Bunun cevabı yığın kullanılarak ifadenin başka bir biçime dönüştürülmesidir.

İfadede **operatörler** ($+$, $-$, $\times$, $/$ gibi) ve **operandlar** (operatörün sağındaki ve solundaki veriler) vardır. Bir ifade, operatör ve operandlarının sırası farklı ama sonucu aynı olacak biçimlerde yazılabilir. Slayttaki tanımlar (ekrandan, 01:30:00):

- **Infix notasyonu:** Operatör iki operandın ortasında bulunur. Örnek: $A + B$, $7 - 9$.
- **Prefix notasyonu:** Operatör iki operandın önünde bulunur (PN, *Polish Notation*). Örnek: $+AB$, $-79$.
- **Postfix notasyonu:** Operatör iki operandın sonunda bulunur (*Reverse Polish Notation*). Örnek: $AB+$, $79-$.

"In" içeride, "pre" önde, "post" arkada demektir. Prefix ifadede operatörden sonra gelen ilk şey sol operand, ikincisi sağ operanddır: $-\,7\,9$, $7 - 9 = -2$ demektir. Hoca tahtada $A/B$'nin postfix karşılığını $AB/$ olarak yazdı.

Slayttaki diğer maddeler:

- Bilgisayar sistemlerinde infix yazımdaki operatör önceliğinin çözümlenmesinin zorluğu sebebiyle postfix/prefix notasyonuna dönüşüm ile işlemlerin sonucu hesaplanır.
- Dönüşümler infix ↔ postfix, infix ↔ prefix, prefix ↔ postfix olabilir.
- Verilen bir notasyonun sayısal sonucunun hesaplanması da çok sık karşılaşılan uygulamalardandır.
- Dönüşümlerde yığın ya da ikili ağaçlar kullanılır. Bu derste yığınla ilerlendi.

Operatör ve operandları karıştırmamak için aralarına boşluk konur. Bu özellikle prefix ve postfix ifadelerde önemlidir, çünkü sayılar yan yana gelir: `+ 2 3` ile `+ 23 3` farklı ifadelerdir.

## 9. İfadelerin Yığınla Değerlendirilmesi

### 9.1 Infix ifadenin değerlendirilmesi

Program kullanıcıdan infix bir ifadeyi metin (*string*) olarak alır ve sonucunu yığın kullanarak hesaplar. Operandlar gerçel sayılardır; izin verilen operatörler $+$, $-$, $\times$, $/$ ve üs alma işlemidir. İki yığın gerekir:

- **Operand yığını:** sayıları tutar.
- **Operatör yığını:** işlem önceliğini değerlendirmek için operatörleri tutar.

Öncelik sırası: en yüksek üs alma, sonra çarpma ve bölme, sonra toplama ve çıkarma. Parantezler operatör önceliğini geçersiz kılmak (*override*) için kullanılır. Her bir öğeye **token** (öge, unsur) denir.

Algoritmanın ana hatları (hocanın anlatımından):

- Karakter operand ise operand yığınına itilir (`push`).
- Karakter operatör ise: operatör yığını boşsa yığına itilir. Boş değilse ve gelen operatörün önceliği yığının tepesindekinden büyükse (ya da açma parantezi tepedeyse) yığına itilir. Değilse yığının tepesindeki operatör çekilir, operand yığınından iki operand çekilir, işlem yapılır ve sonuç operand yığınına konur; bu, tepedeki operatörün önceliği gelen operatörünkünden küçük olana ya da yığın boşalana kadar sürer, sonra gelen operatör yığına itilir.
- Açma parantezi operatör yığınına itilir. Kapatma parantezi gelince açma parantezi görülene kadar yukarıdaki işlem tekrarlanır, sonra açma parantezi atılır.
- İfade bitince operatör yığını boşalana kadar işlemler yapılır; sonuç operand yığınında kalır.

Slayttaki örnek (ekrandan, 01:35:00): Infix ifade $2 * (5 * (3+6)) / 15 - 2$. Yığınlar tepe solda olacak biçimde yazılmıştır.

| Token | İşlem | Operand yığını | Operatör yığını |
|---|---|---|---|
| 2 | operand yığınına | 2 | |
| `*` | operatör yığınına | 2 | `*` |
| `(` | operatör yığınına | 2 | `( *` |
| 5 | operand yığınına | 5 2 | `( *` |
| `*` | operatör yığınına | 5 2 | `* ( *` |
| `(` | operatör yığınına | 5 2 | `( * ( *` |
| 3 | operand yığınına | 3 5 2 | `( * ( *` |
| `+` | operatör yığınına | 3 5 2 | `+ ( * ( *` |
| 6 | operand yığınına | 6 3 5 2 | `+ ( * ( *` |
| `)` | 6 ve 3 çek, `+` çek, $6+3=9$, 9'u it, `(` çek | 9 5 2 | `* ( *` |
| `)` | 9 ve 5 çek, `*` çek, $9 \cdot 5 = 45$, 45'i it, `(` çek | 45 2 | `*` |
| `/` | `/` önceliği `*` ile eşit; yığına itilir | 45 2 | `/ *` |
| 15 | operand yığınına | 15 45 2 | `/ *` |
| `-` | `-`, `/`'dan düşük: 15 ve 45 çek, `/` çek, $45/15=3$, 3'ü it | 3 2 | `*` |
| | `-`, `*`'dan düşük: 3 ve 2 çek, `*` çek, $3 \cdot 2 = 6$, 6'yı it | 6 | |
| | `-` operatör yığınına | 6 | `-` |
| 2 | operand yığınına | 2 6 | `-` |
| son | 2 ve 6 çek, `-` çek, $6 - 2 = 4$, 4'ü it | 4 | |

Sonuç **4** (python ile doğrulandı). Hoca her `)` geldiğinde açma parantezi görülene kadar çekme yapıldığını vurguladı: Matematikte en son açılan parantez önce kapatılır ve yığın tam bu mantıkla çalışır.

**Soru:** Bölme ve çıkarma işlemlerinde operandların yerleri değiştirilerek mi işlem yapılıyor? **Cevap:** Evet. Yığından ilk çekilen (tepedeki) eleman sağ operand, ikinci çekilen sol operand olur. Örneğin 15 önce, 45 sonra çekildiği için işlem $45 / 15$'tir.

> **Hocanın vurgusu:** Infix değerlendirme zordur: iki yığın vardır ve operatör öncelikleri karışıktır. Derleyiciler bu yüzden infix ifadeyi doğrudan değil, daha kolay yollarla değerlendirir.

### 9.2 Prefix ifadenin değerlendirilmesi

Örnek ifade (ekrandan, 01:45:00): `- / * 20 * 50 + 3 6 300 2`.

**Elle kısa yol:** İfadenin sonundan başına doğru ilk operatör görülene kadar gidilir. Operatörden hemen sonraki iki operand alınır: ilki sol, ikincisi sağ operanddır; işlem yapılır ve sonuç yerine yazılır. Böylece:

- `+ 3 6` → 9; ifade `- / * 20 * 50 9 300 2` olur.
- `* 50 9` → 450; `* 20 450` → 9000.
- `/ 9000 300` → 30.
- `- 30 2` → 28.

Hoca, sınavda kısa yol kullanmaya izin verilmezse ve "yığın kullanın" denirse yığınla çözülmesi gerektiğini belirtti.

**Yığınla çözüm algoritması:**

1. İfade ters çevrilir: `2 003 6 3 + 05 * 02 * / -`.
2. Karakter rakamsa, sonraki karakter rakam olmayana kadar rakamlar geçici bir değişkende birleştirilir, sonra bu geçici değer ters çevrilir (`003` → 300, `05` → 50, `02` → 20) ve yığına itilir.
3. Karakter operatörse yığından bir operand çekilir ($s_1$), bir daha çekilir ($s_2$), $s_1 \text{ op } s_2$ hesaplanır ve sonuç yığına itilir.
4. İfade bitince yığında kalan değer sonuçtur.

| Token | İşlem | Yığın |
|---|---|---|
| 2 | 2'yi it | [2] |
| 003 | ters çevir, 300'ü it | [2, 300] |
| 6 | 6'yı it | [2, 300, 6] |
| 3 | 3'ü it | [2, 300, 6, 3] |
| `+` | 3 ve 6'yı çek, $3+6=9$'u it | [2, 300, 9] |
| 05 | ters çevir, 50'yi it | [2, 300, 9, 50] |
| `*` | 50 ve 9'u çek, $50 \cdot 9 = 450$'yi it | [2, 300, 450] |
| 02 | ters çevir, 20'yi it | [2, 300, 450, 20] |
| `*` | 20 ve 450'yi çek, $20 \cdot 450 = 9000$'i it | [2, 300, 9000] |
| `/` | 9000 ve 300'ü çek, $9000/300 = 30$'u it | [2, 30] |
| `-` | 30 ve 2'yi çek, $30 - 2 = 28$'i it | [28] |

Sonuç **28** (python ile doğrulandı).

> **Hocanın vurgusu:** Infix'ten prefix'e geçmenin faydası şudur: Prefix ifadede tek bir yığın yeter ve kafa karıştıracak bir şey yoktur. Bir çekilene $s_1$, bir daha çekilene $s_2$ denir ve her zaman $s_1 \text{ op } s_2$ uygulanır; işlem toplama da olsa çarpma da olsa kural değişmez.

### 9.3 Postfix ifadenin değerlendirilmesi

Postfix ifadede ters çevirme yoktur; ifade soldan sağa okunur ve tek yığın kullanılır:

1. Karakter operand ise yığına itilir.
2. Karakter operatör ise yığından bir operand çekilir ($s_1$), bir daha çekilir ($s_2$), $s_2 \text{ op } s_1$ hesaplanır ve sonuç yığına itilir.
3. İfade bitince sonuç yığındadır.

Örnek (ekrandan, 01:50:00): `2 5 3 6 + * * 5 / 2 -`.

**Elle kısa yol:** Baştan başlanır, ilk operatöre kadar gidilir; operatörden hemen önceki iki operand alınır (öndeki sol, hemen önceki sağ). `3 6 +` → 9; `5 9 *` → 45; `2 45 *` → 90; `90 5 /` → 18; `18 2 -` → 16.

| Token | İşlem | Yığın |
|---|---|---|
| 2 | 2'yi it | [2] |
| 5 | 5'i it | [2, 5] |
| 3 | 3'ü it | [2, 5, 3] |
| 6 | 6'yı it | [2, 5, 3, 6] |
| `+` | 6 ve 3'ü çek, $3+6=9$'u it | [2, 5, 9] |
| `*` | 9 ve 5'i çek, $5 \cdot 9 = 45$'i it | [2, 45] |
| `*` | 45 ve 2'yi çek, $2 \cdot 45 = 90$'ı it | [90] |
| 5 | 5'i it | [90, 5] |
| `/` | 5 ve 90'ı çek, $90/5 = 18$'i it | [18] |
| 2 | 2'yi it | [18, 2] |
| `-` | 2 ve 18'i çek, $18 - 2 = 16$'yı it | [16] |

Sonuç **16** (python ile doğrulandı). Burada her zaman ilk çekilen sağ tarafa yazılır.

Hoca, elde bir ifadenin prefix ya da postfix hali varsa değerlendirmenin infix'e göre hem kontrol hem algoritma hem de bellek açısından kolay olduğunu tekrarladı: İki yığın ve "önce çarpma mı, toplama mı, üs mü, parantez mi" gibi kontroller gerekmez.

**Soru:** Kütüphaneler (derleyiciler) böyle mi yazıyor? **Cevap:** Derleyici tasarımında ayrıştırma ağaçları (*parse tree*) ve yığınlar kullanılır. C'de `c = a * b + 2` gibi bir ifade yazıldığında arka planda ayrıştırma ağaçları ve yığınlarla postfix ya da prefix biçime dönüştürülür, çünkü bu biçimler daha hızlı işlenir. Elde postfix ya da prefix varsa işlem doğrudan yığınla yapılabilir; yoksa önce dönüşüm gerekir.

## 10. Notasyonlar Arası Dönüşümler

Asıl mesele, infix ifadeyi ($A + B$) prefix ($+AB$) ya da postfix ($AB+$) biçimine dönüştürmektir. Yani değerlendirme iki adımda yapılır: önce dönüşüm, sonra değerlendirme. $A + B$ gibi kısa ifadeler gözle dönüştürülebilir, ama uzun ifadeler için algoritma gerekir.

### 10.1 Infix'ten postfix'e dönüşüm

Slayttaki örnekler (ekrandan, 01:55:00):

- Girdi $A + B$ → çıktı `AB+`.
- Girdi $A+B*(C\hat{\ }D-E)$ → çıktı `ABCD^E-*+`.

Operatör yığını kullanılır. İşlem öncelikleri: 1. `^` (üs), 2. `/` `*`, 3. `+` `-`. Parantezler bu kuralları geçersiz kılmak için kullanılır. Algoritma (sonuç başta boş bir metindir, ifade karakter karakter okunur):

1. Karakter operand ise sonuca eklenir.
2. Karakter operatör ise:
   - Operatör yığını boşsa yığına itilir.
   - Boş değilse ve operatörün önceliği yığının tepesindekinden büyük ya da ona eşitse yığına itilir.
   - Operatörün önceliği tepedekinden küçükse, yığın boşalana ya da gelen operatörün önceliği tepedekinden büyük ya da eşit olana kadar yığından operatör çekilip sonuca eklenir; sonra gelen operatör yığına itilir.
3. Karakter `(` ise yığına itilir.
4. Karakter `)` ise karşılık gelen `(` görülene kadar yığından operatör çekilip sonuca eklenir; sonra `(` atılır.
5. İfade bitince yığında kalan operatörler sırayla çekilip sonuca eklenir.

Postfix ifadede parantez bulunmaz. $A+B*(C\hat{\ }D-E)$ için adımlar:

| Token | İşlem | Sonuç | Yığın (tepe sağda) |
|---|---|---|---|
| A | sonuca | A | |
| `+` | yığın boş, it | A | `+` |
| B | sonuca | AB | `+` |
| `*` | `*` > `+`, it | AB | `+ *` |
| `(` | it | AB | `+ * (` |
| C | sonuca | ABC | `+ * (` |
| `^` | tepede `(` var, it | ABC | `+ * ( ^` |
| D | sonuca | ABCD | `+ * ( ^` |
| `-` | `-` < `^`: `^` çekilip sonuca; tepede `(`, `-` itilir | ABCD^ | `+ * ( -` |
| E | sonuca | ABCD^E | `+ * ( -` |
| `)` | `(` görülene kadar çek: `-`; `(` atılır | ABCD^E- | `+ *` |
| son | kalanları çek: `*`, `+` | ABCD^E-*+ | |

Sonuç `ABCD^E-*+` (python ile doğrulandı).

Hoca bu ifadedeki harflerin yerine sayı konup postfix değerlendirme algoritmasının uygulanmasını önerdi ve sınavda şöyle bir soru sorabileceğini söyledi: "Sayılardan oluşan bir infix ifadeyi yığın kullanarak postfix'e dönüştürün, sonra postfix ifadenin sayısal sonucunu elle kısa yoldan hesaplayın." Örnek olarak $A=5$, $B=3$, $C=2$, $D=4$, $E=15$ alınırsa $5 + 3 \cdot (2^4 - 15) = 5 + 3 \cdot 1 = 8$ olur.

Postfix `ABCD^E-*+` kısa yoldan değerlendirilirken soldan gidilir: önce $C\hat{\ }D$ yapılır (C sola, D sağa), sonuca $\alpha$ denir; sonra $\alpha - E$ yapılır, buna $\theta$ denir; sonra $B \cdot \theta$ yapılır, buna $\gamma$ denir; en son $A + \gamma$ yapılır. Infix ifadede toplama en son yapıldığı gibi postfix ifadede de en son yapılır.

### 10.2 Infix'ten prefix'e dönüşüm

Infix'ten prefix'e dönüşüm doğrudan yığınla yapılmaz, dolaylı bir yol izlenir:

1. Infix ifade metin olarak ters çevrilir.
2. Parantezler ters çevrilir (`(` yerine `)`, `)` yerine `(`).
3. Bu ifadeye infix'ten postfix'e dönüşüm algoritması uygulanır.
4. Elde edilen sonuç ters çevrilir.

Slayttaki örnek (ekrandan, 02:10:00): Infix ifade $A+B*(C\hat{\ }D-E)$; ters çevrilmiş hali `)E-D^C(*B+A`; parantezler düzeltilince `(E-D^C)*B+A`. Postfix algoritması uygulanınca sonuç `EDC^-B*A+` bulunur; bu ters çevrilince prefix ifade `+A*B-^CDE` elde edilir (python ile doğrulandı). Hoca bunu bir alıştırma olarak öğrencilere bıraktı.

### 10.3 Postfix'ten infix'e dönüşüm

1. İfade soldan sağa okunur.
2. Karakter operand ise yığına itilir.
3. Karakter operatör ise yığından $s_1$, sonra $s_2$ çekilir ve $(s_2 \text{ op } s_1)$ metni oluşturulup yığına itilir.
4. İfade bitince yığındaki metin sonuçtur.

Burada yığın sayıları değil metinleri (string) tutar. Sonuç infix olacağı için her işlemde parantez eklenir; parantezler işlem önceliğini göstermek için önemlidir.

Örnek: `ABC/-AK/L-*`.

- A, B, C yığına itilir. `/` gelince $s_1 = C$, $s_2 = B$ çekilir; `(B/C)` itilir.
- `-` gelince $s_1 = (B/C)$, $s_2 = A$ çekilir; `(A-(B/C))` itilir.
- A ve K itilir. `/` gelince `(A/K)` itilir. L itilir. `-` gelince `((A/K)-L)` itilir.
- `*` gelince iki metin çekilir ve sonuç $((A-(B/C))*((A/K)-L))$ olur (python ile doğrulandı).

Hoca bu dönüşümlerden birkaç adım gösterip gerisini öğrencilere bıraktığını, benzer yöntemler tekrar ettiği için ayrıntılarından da sorumlu olunduğunu belirtti.

### 10.4 Prefix'ten infix'e dönüşüm

Burada ifade **sağdan sola** okunur. Operand yığına itilir; operatör gelince $s_1$, sonra $s_2$ çekilir ve $(s_1 \text{ op } s_2)$ metni yığına itilir. Prefix `*-A/BC-/AKL` için: L, K, A yığına; `/` gelince ilk çekilen A sola, ikincisi K sağa yazılır, `(A/K)` itilir; böyle devam edilince yine $((A-(B/C))*((A/K)-L))$ bulunur. Hoca, sonuçtaki parantezlerin işlem sırasını gösterdiğini söyledi: önce içteki $A/K$, sonra çıkarma, sonra $B/C$, sonra $A - B/C$, en son çarpma yapılır.

### 10.5 Prefix'ten postfix'e dönüşüm

Slayttaki örnekler (ekrandan, 02:15:00): prefix `+AB` → postfix `AB+`; prefix `*-A/BC-/AKL` → postfix `ABC/-AK/L-*`. Algoritma:

1. İfade sağdan sola, karakter karakter okunur.
2. Karakter operand ise yığına itilir.
3. Karakter operatör ise yığından $s_1$, sonra $s_2$ çekilir ve $s_1\,s_2\,\text{op}$ metni yığına itilir.
4. İfade bitince yığındaki metin sonuçtur.

Örnekte L, K, A yığına itilir; `/` gelince A ve K çekilir, `AK/` itilir; `-` gelince `AK/` ve L çekilir, `AK/L-` itilir. Postfix ifadede parantez gerekmez. Bu sırayla devam edilince `ABC/-AK/L-*` bulunur (python ile doğrulandı).

### 10.6 Postfix'ten prefix'e dönüşüm

Bu durumda ifade baştan (soldan) okunur; operatör gelince $s_1$, sonra $s_2$ çekilir ve $\text{op}\,s_2\,s_1$ metni yığına itilir (operatör başa, ardından operandlar). Böylece postfix ifadenin prefix karşılığı bulunur. Örneğin `ABC/-AK/L-*` ifadesi `*-A/BC-/AKL` olur (ara adım eklendi; python ile doğrulandı).

**Soru:** Bu dönüşümleri pratikte nerede kullanıyoruz? **Cevap:** Hoca önce şakayla "sınavda soru sorarsam orada" dedi, sonra asıl kullanım alanını açıkladı: derleyici tasarımı ya da programlama dili tasarımı. Infix ifadenin doğrudan değerlendirilmesi zordur; önce prefix ya da postfix'e çevrilir, sonra değerlendirilir. C'de yazılan her matematiksel ifade arka planda böyle bir dönüşüme uğrar.

## 11. Algoritma Analizine Giriş

### 11.1 Analiz türleri

Algoritma analizinde bir algoritmanın doğruluğu ve iyi bir çözüm olup olmadığı test edilir; özellikle zaman ve bellek açısından iyi bir algoritmanın nasıl olduğu incelenir. İki yaklaşım vardır:

- **Deneysel (kaba) analiz:** Kodun çalıştığı aralığın başına ve sonuna saat ölçümü (`clock`) konur ve aradaki farka bakılır; ya da döngüye bir sayaç konup kaç kez döndüğü sayılır. Örneğin 10 elemanlı girdi için 100, 20 elemanlı girdi için 400 adım sayılabilir. Farklı girdi boyutları için süre (milisaniye) ya da temel işlem sayısı ölçülür.
- **Teorik analiz:** Girdi boyutuna bağlı bir fonksiyon üretilir. Slayttaki tanım (ekrandan, 02:20:00): "Zaman verimliliği, girdi boyutunun bir fonksiyonu olarak temel işlemin tekrar sayısı belirlenerek analiz edilir." **Temel işlem** (*basic operation*) algoritmanın çalışma süresini en çok etkileyen işlemdir. Temel işlemin $n$'ye bağlı tekrar sayısı $f(n)$ olarak yazılır.

**Soru:** Sıralamada temel işlem nedir? (Slaytta boşluk doldurma olarak soruldu.) **Cevap:** Karşılaştırma. Bu durumda $n$ eleman için kaç kez "büyüktür/küçüktür" karşılaştırması yapıldığını veren fonksiyon bulunur.

Temel işlem ve girdi boyutu örnekleri:

| Problem | Girdi boyutu | Temel işlem |
|---|---|---|
| $n$ elemanlı dizide eleman arama | eleman sayısı $n$ | karşılaştırma |
| İki matrisin çarpımı | matrisin boyutu (satır ve sütun sayısı) | sayıların çarpımı (ve toplamı) |
| Sayının asal olup olmadığını bulma | sayının basamak (ikili gösterimde bit) sayısı | bölme ya da kalan işlemi |
| Çizge problemi | düğüm ve kenar sayısı | düğüm ya da kenarları gezme |

### 11.2 Yürütme zamanı ve alan maliyeti

**Yürütme zamanı** $T(n)$, algoritmanın işini bitirmesi için gereken zamanı (karmaşıklığı) gösteren bir fonksiyondur; $n^2$ mi, $n^3$ mü, $n \log n$ mi olduğu bulunur. Genellikle karşılaştırma sayısı, döngüdeki tekrar sayısı ve aritmetik işlem sayısı kullanılır.

**Alan maliyeti**, $n$ elemanlı bir girdi için ne kadar ek belleğe ihtiyaç duyulduğunu gösterir. Örneğin $n$ için $2n$ kadar ek yer gerekiyorsa bu bir alan maliyetidir. Program kodu, veri yapısının alanları ve yığın bellek (örneğin özyinelemeli algoritmalarda dönüş bilgilerinin saklandığı yığın) da hesaba katılır. Birkaç tamsayı değişkeni gibi küçük alanlar hesaplanmaz; ama örneğin bir dizi için ayrıca bir matrise ihtiyaç varsa o matrisin boyutu karmaşıklığı belirler.

Slayttaki örnekler (ekrandan, 02:25:00): $T(n) = 2n^2 - 2n + 5$ olabilir; $n$ ifadenin bağımsız değişkenidir ve temel işlem sayısına bağlıdır.

| $T(n)$ | Ad |
|---|---|
| $1$ | sabit |
| $\log n$ | logaritmik |
| $n$ | lineer |
| $n^2$ | karesel |

$T(n) = 1$ olması, 100 elemanlı dizi de verilse 1000 elemanlı dizi de verilse hep bir işlem yapılması demektir (örneğin dizinin ilk elemanını almak). İkili aramada $\log n$, doğrusal aramada $n$ mertebesinde işlem yapılır.

$T(n)$ fonksiyonu üstel, polinom gibi birçok terimden oluşabilir. Bunu en sade biçimde yazmak için **asimptotik notasyonlar** kullanılır. Asimptot bir fonksiyonun sonsuzdaki davranışıdır (yatay, düşey ya da eğik asimptot). Burada $n \to \infty$ iken $T(n)$'nin nasıl değiştiği incelenir. Kullanılan notasyonlar: Büyük-O, Büyük-Omega, Büyük-Teta, küçük-o, küçük-omega; bir de az kullanılan tilde notasyonu. Örneğin $T(n) = 5n^2 + 3n + 5$ bulunduysa katsayı ve küçük terimler atılarak $T(n) \in O(n^2)$ ya da $\Theta(n^2)$ yazılır.

### 11.3 Ayrıntılı analiz örnekleri

Hoca, kodun her satırındaki işlemleri tek tek sayarak ayrıntılı analiz yapılabileceğini, ya da yalnız temel işlemi sayarak kısa analiz yapılabileceğini anlattı. Değişken tanımlamaları sayılmaz; atama, karşılaştırma, artırma, aritmetik işlem, dizi erişimi ve `return` sayılabilir. Hoca küçük ayrıntıların (örneğin bir döngü koşulunun $n$ mi $n+1$ mi kez çalıştığı) önemli olmadığını, sonuçta baskın terimin belirleyici olduğunu vurguladı. Sınavda hangi işlemlerin sayılacağı soruda belirtilir.

İlk örnek, bir dizinin elemanlarını toplayan bir döngüdür. Döngü dışındaki ilk atama 1 kez, `k = 0` 1 kez, `k < n` karşılaştırması $n+1$ kez, `k++` $n$ kez çalışır; döngü içindeki toplama ve atama $n$'er kez çalışır. Hoca toplamda $4n + 6$ civarında işlem bulunduğunu söyledi. İkinci örnek (en büyük elemanı bulan döngü) için yaklaşık $4n$ işlem bulundu. Bunlar saniye ya da dakika değil, birim işlem sayısıdır.
<!-- BELİRSİZ: Toplama ve en büyük eleman örneklerinin kodları ve sayım tabloları karelerde okunmadı; toplamlar ($4n+6$, $4n$) altyazıdan aktarıldı. -->

**Seçmeli sıralama örneği** (ekrandan, 02:30:00). Slayttaki kod:

```java
public static int[] selectionsort(int[] A, int n)
{
    int tmp;
    int min;
    for (int i = 0; i < n-1; i++)        // I
    {
        min = i;                         // II
        for (int j = i; j < n; j++)      // III
        {
            if (A[j] < A[min]) {         // IV
                min = j;                 // V
            }
        }
        tmp = A[i];                      // VI
        A[i] = A[min];
        A[min] = tmp;
    }
    return A;                            // VII
}
```

Slayttaki sayım tablosu:

| Satır | İşlem | Tekrar | Toplam |
|---|---|---|---|
| I | 1, 1, 1 | 1, $n$, $n$ | $2n+1$ |
| II | 1 | $n$ | $n$ |
| III | 1, 1, 1 | $n$, $n(n+1)/2$, $n(n+1)/2$ | $n + 2n(n+1)/2$ |
| IV | 1 | $n(n+1)/2$ | $n(n+1)/2$ |
| V | 1 | $n(n+1)/2$ | $n(n+1)/2$ |
| VI | 1, 1, 1 | 1, 1, 1 | 3 |
| VII | 1 | 1 | 1 |

Toplam:

$$T(n) = \frac{4n(n+1)}{2} + 4n + 5 = 2n^2 + 6n + 5$$

Hoca dış döngü $n$ kez döndüğü için `min = i` atamasının da $n$ kez yapıldığını, iç döngünün ise toplamda $n(n+1)/2$ kez çalıştığını açıkladı. İşin yükünü $n^2$'li terim çeker; yani bu algoritma $n^2$ mertebesinde çalışır.

> **Ders sonrası not:** Hoca VI. satırdaki üç atamanın (`tmp = A[i]`, `A[i] = A[min]`, `A[min] = tmp`) dış döngünün içinde olduğunu, bu yüzden tekrarlarının 1 değil $n$ olması gerektiğini söyleyerek slaytı düzeltti. Bu durumda VI. satırın toplamı $3n$ olur ve toplam büyük olasılıkla $T(n) = 2n^2 + 9n + 2$ çıkar (python ile hesaplandı). Hoca bu düzeltmenin baskın terimi değiştirmediğini vurguladı.

**Matris toplama örneği.** Dış döngü $n$, iç döngü $m$ kez döner; iç döngü dış döngünün her turunda çalıştığı için içteki toplama ve atama $m \cdot n$ kez yapılır. Hoca $m \approx n$ kabul edince yaklaşık $4n^2 + 4n + 2$ işlem bulunduğunu, küçük terimler atılınca yaklaşık $n^2$ işlem yapıldığını söyledi. Bu sırada hoca slayttaki bir sayımın da hatalı olabileceğini belirtip düzeltti.
<!-- BELİRSİZ: Matris toplama kodu ve sayım tablosu karelerde okunmadı; ara toplamlar altyazıda karışık olduğu için yalnız sonuç aktarıldı. -->

**Soru:** $m \cdot n$ nasıl hesaplanıyor? **Cevap:** Dış döngü $n$ kez döner, iç döngü her seferinde $m$ kez döner; içerideki işlem toplamda $m \cdot n$ kez yapılır. Slaytta yalnız toplama ve atama kabaca sayılmıştır; aslında dizi erişimleri de sayılırsa işlem sayısı daha fazladır.

### 11.4 Fonksiyonların büyümesi

Asimptotik analizde gereksiz ayrıntılar atılarak fonksiyonun $n$'nin çok büyük değerlerinde nasıl davrandığı bulunur. Bu, girdi boyutu büyüdükçe programın ne kadar hızlı yanıt vereceğini gösterir ve iki ya da daha fazla algoritmanın verimini karşılaştırmayı sağlar. Örneğin A algoritması $n^2$, B algoritması $n^3$ işlem yapıyorsa A zaman açısından daha iyidir. Karmaşıklık gerçek süreyi değil, veri kümesi büyüdükçe oluşacak maliyet değişimini anlatır. Küçük $n$ için bir algoritma daha iyi görünebilir, ama $n$ büyüdükçe diğerinin maliyeti çok hızlı artabilir.

$n \to \infty$ iken sık kullanılan fonksiyonlar büyüme sırasıyla: $1$, $\log n$, $n$, $n \log n$, $n^2$, $n^3$, $n^4$, $2^n$, $n!$. Hoca bir tabloda bu fonksiyonların belirli girdi boyutları için süre karşılıklarını gösterdi; üstel ve faktöriyel fonksiyonlarda büyük girdiler için işlemler bitmediği için süre ölçülemediğine dikkat çekti.
<!-- BELİRSİZ: Büyüme tablosundaki süre değerleri (3.3 s, 10 s, 3.6 x 10^6 vb.) karelerde okunmadı ve altyazıdan net çıkmadığı için aktarılmadı. -->

### 11.5 En iyi, en kötü ve ortalama durum

Slayttaki tanımlar (ekrandan, 02:35:00):

- **Worst case (en kötü):** Algoritma çalışmasının en fazla sürede gerçekleştiği analiz türüdür. En kötü durum, çalışma zamanında bir üst sınırdır ve o algoritma için verilen durumdan "daha uzun sürmeyeceği" garantisini verir. Bazı algoritmalar için en kötü durum oldukça sık rastlanır. Arama algoritmasında aranan öğe genellikle dizide olmaz, dolayısıyla döngü $N$ kez çalışır.
- **Best case (en iyi):** Algoritmanın en kısa sürede ve en az adımda çalıştığı giriş durumu olan analiz türüdür. Çalışma zamanında bir alt sınırdır.
- **Average case (ortalama):** Algoritmanın ortalama sürede ve ortalama adımda çalıştığı giriş durumu olan analiz türüdür.

Doğrusal aramada eleman ilk denemede bulunursa en iyi durum $O(1)$'dir; en kötü durumda $n$ deneme gerekir. Hoca ortalama durumun en iyi ile en kötünün aritmetik ortalaması olmadığını, olasılık açısından ortalama kaç adımda sonuç üretildiğini gösterdiğini vurguladı.

> **Hocanın vurgusu:** Genellikle en kötü duruma bakılır. Çünkü $n$'nin çok büyük değerlerinde en iyi durum belirleyici olmaz; "algoritma en kötü şartlarda böyle çalışır" garantisi önemlidir. Örneğin doğrusal arama en kötü durumda $n$ adımda biter; eleman yoksa da bunu $n$ adımın sonunda söyler.

**Soru:** A ve B algoritmalarının çalışma zamanı grafikleri verildiğinde hangisi seçilir? **Cevap:** Büyük $n$ için daha yavaş büyüyen seçilir. İlk grafikte B seçildi. İkinci grafikte A seçildi: A $50n$ gibi doğrusal, B ise $n^2$ ile çalışıyordu. Belirli bir kesişim noktasından ($n_0$) sonra algoritmaların davranışı çok değişir.

Hocanın örneği $2^n$ ile $n^2$ karşılaştırmasıdır:

| $n$ | $2^n$ | $n^2$ | Daha iyi olan |
|---|---|---|---|
| 2 | 4 | 4 | eşit |
| 3 | 8 | 9 | $2^n$ |
| 4 | 16 | 16 | eşit |
| 5 | 32 | 25 | $n^2$ |
| 6 | 64 | 36 | $n^2$ |

Dolayısıyla $n \ge 5$ için $n^2$'li algoritma daha iyidir (python ile doğrulandı). Hoca üstel bir algoritmanın büyük $n$ için polinom bir algoritmadan her zaman kötü olduğunu söyledi.

### 11.6 Asimptotik notasyonlara giriş

Hoca notasyonların anlamını kısaca verdi: Büyük-O en kötü durum hakkında bilgi verir ve **üst sınır** (*upper bound*) olarak anılır: "algoritma olsa olsa en kötü ihtimalle bu kadar çalışır." Büyük-Omega en iyi durum ve **alt sınır** (*lower bound*) ile ilişkilendirildi. Büyük-Teta ikisinin arasında, algoritmanın çalışması hakkında daha ayrıntılı bilgi veren notasyondur. Örneğin bir algoritma $\Theta(n)$, diğeri $\Theta(n^2)$ ise $\Theta(n)$ olan seçilir; en iyi durumda biri $\Omega(n)$, diğeri $\Omega(n^2)$ ise en iyi durum için $\Omega(n)$ olan tercih edilir.

> **Ek bilgi (derste anlatılmadı):** Büyük-O, Omega ve Teta aslında fonksiyonlar için üst, alt ve sıkı sınır bildiren matematiksel kavramlardır; en kötü, en iyi ve ortalama durumla birebir aynı şey değildir. Örneğin bir algoritmanın en kötü durum çalışma zamanı için hem $O$ hem $\Omega$ hem de $\Theta$ sınırı yazılabilir. Ders kitaplarında bu ayrım büyük olasılıkla tanımlar verilirken netleşir.

Slaytta Büyük-O'nun tanımı da gösterildi (ekrandan, 02:40:00): $f$ ve $g$ tamsayı kümesinden ya da gerçel sayı kümesinden gerçel sayılara tanımlanmış olsun ($\mathbb{Z}^+ \to \mathbb{R}$). $x > k$ olduğunda

$$|f(x)| \le C\,|g(x)|$$

oluyorsa ve bu eşitsizliği sağlayan $C$ ve $k$ gibi sabit sayılar varsa $f(x) = O(g(x))$ olur. Tanımın ve özelliklerin ayrıntısı bir sonraki derse bırakıldı.

Hoca analizin genel akışını şöyle özetledi: Ayrıntılı analiz istenirse bütün adımlar tek tek sayılır ve $n$'ye bağlı bir $T(n)$ bulunur; sonra bu fonksiyon Büyük-O, Omega ya da Teta ile sade biçimde yazılır. Bazen bütün işlemleri saymaya gerek yoktur: Algoritmada bir kilit nokta vardır ve yalnız onun tekrar sayısını saymak yeter. Örneğin en büyük elemanı bulma algoritmasında ilk atama gibi işlemler 3-5 kez yapılırken karşılaştırma $n$ kez yapılır ve $n$ her zaman büyüktür; matris toplamada asıl yük $m \cdot n$ kez yapılan toplama ve atamadır, $m = n$ alınınca $n^2$ bulunur. Ama soruda "ayrıntılı analiz yapın" denirse bütün ayrıntılara ayrı ayrı bakılmalıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:19:13): Bir algoritmanın her zaman yüzde yüz doğru sonuç üretmesi şart mıdır?

> **Cevap (derste verildi):** Şart değildir. Kesin çözümü bulmak için çok uzun süre ya da çok büyük kaynak gereken problemlerde (örneğin gezgin satıcı problemi) optimuma yakın ya da yaklaşık çözüm yeterli olabilir. Buna karşılık sonluluk mutlaka sağlanmalıdır.

**Soru 2** (derste sözlü, 00:26:10): İkili aramanın doğrusal aramadan hızlı çalışabilmesi için dizinin hangi şartı sağlaması gerekir?

> **Cevap (derste verildi):** Dizinin sıralı olması gerekir. Böylece orta elemanla yapılan her karşılaştırma dizinin yarısını aramanın dışında bırakır.

**Soru 3** (ekrandan, 00:40:00): Insertion sort ile verilen $3\ 2\ 4\ 1\ 5$ dizisini sıralayınız.

> **Çözüm (derste verildi):** A) $2, 3, 4, 1, 5$ (ilk iki pozisyon değiştirilir); B) $2, 3, 4, 1, 5$ (üçüncü eleman yerinde kalır); C) $1, 2, 3, 4, 5$ (dördüncüsü başlangıca yerleştirilir, 2, 3 ve 4 birer sağa kaydırılır); D) $1, 2, 3, 4, 5$ (beşinci eleman yerinde kalır).

**Soru 4** (derste sözlü, 00:44:10): Öklid algoritmasında döndürülen $m$ değeri en az kaç olabilir?

> **Cevap (derste verildi):** 1. Aralarında asal iki sayının EBOB'u 1'dir; örneğin $\gcd(7, 3)$: $(7,3) \to (3,1) \to (1,0)$, sonuç 1.

**Soru 5** (derste sözlü, 00:50:15): Bir dizinin en küçük elemanını bulan bir fonksiyon verilmiştir. Fonksiyonu değiştirmeden dizinin en büyük elemanını nasıl bulursunuz?

> **Cevap (derste verildi):** Bütün elemanlar $-1$ ile çarpılıp fonksiyona verilir, dönen değer tekrar $-1$ ile çarpılır. $4, 2, 8, 7$ için $-4, -2, -8, -7$ dizisinin en küçüğü $-8$'dir; $-1$ ile çarpılınca 8 bulunur (dönüştür ve yönet).

**Soru 6** (ekrandan, 01:25:00): Hocanın kaynak olarak gösterdiği slaytta, tek yönlü bağlı listeyle yığın gerçekleştirmek için üç seçenek verilmiştir: A) Tek yönlü bağlı listeyle verimli yapılamaz. B) Liste `it → was → the → best → of → null` biçiminde ve yığının tepesi `of` düğümünde (listenin sonunda). C) Liste `of → best → the → was → it → null` biçiminde ve yığının tepesi `of` düğümünde (listenin başında). Hangisi doğrudur?
<!-- BELİRSİZ: Soru başlığı karede küçük ve okunaksız; soru metni seçeneklerden kuruldu. Hoca bu soruyu derste çözmedi. -->

> **Çözüm (derste verilmedi):** C. Tek yönlü bağlı listede başa ekleme ve baştan silme $O(1)$ sürede yapılır; yığının tepesi listenin başında tutulursa `push` ve `pop` sabit zamanda olur. B seçeneğinde tepe listenin sonunda olduğu için `pop` sırasında sondan bir önceki düğümü bulmak listeyi baştan gezmeyi gerektirir.

**Soru 7** (ekrandan, 01:35:00): $2 * (5 * (3+6)) / 15 - 2$ infix ifadesini iki yığın (operand ve operatör yığını) kullanarak değerlendiriniz.

> **Çözüm (derste verildi):** Bölüm 9.1'deki tabloda adım adım gösterildiği gibi sonuç 4'tür.

**Soru 8** (ekrandan, 01:45:00): `- / * 20 * 50 + 3 6 300 2` prefix ifadesini yığın kullanarak değerlendiriniz.

> **Çözüm (derste verildi):** İfade ters çevrilir, operandlar yığına itilir, her operatörde $s_1 \text{ op } s_2$ uygulanır: $3+6=9$, $50 \cdot 9 = 450$, $20 \cdot 450 = 9000$, $9000/300 = 30$, $30 - 2 = 28$. Sonuç 28.

**Soru 9** (ekrandan, 01:50:00): `2 5 3 6 + * * 5 / 2 -` postfix ifadesini yığın kullanarak değerlendiriniz.

> **Çözüm (derste verildi):** Her operatörde $s_2 \text{ op } s_1$ uygulanır: $3+6=9$, $5 \cdot 9 = 45$, $2 \cdot 45 = 90$, $90/5 = 18$, $18 - 2 = 16$. Sonuç 16.

**Soru 10** (ekrandan, 01:55:00; derste sözlü, 01:57:44): $A+B*(C\hat{\ }D-E)$ infix ifadesini yığın kullanarak postfix'e dönüştürünüz. Hoca benzer bir sınav sorusunu şöyle tarif etti: sayılardan oluşan bir infix ifade önce yığınla postfix'e dönüştürülür, sonra postfix ifadenin sayısal sonucu elle hesaplanır.

> **Çözüm (derste verildi):** `ABCD^E-*+`. Sayısal örnek olarak $A=5$, $B=3$, $C=2$, $D=4$, $E=15$ alınırsa postfix `5 3 2 4 ^ 15 - * +` olur ve değerlendirme $2^4 = 16$, $16 - 15 = 1$, $3 \cdot 1 = 3$, $5 + 3 = 8$ verir (python ile doğrulandı).

**Soru 11** (ekrandan, 02:10:00): $A+B*(C\hat{\ }D-E)$ infix ifadesini prefix'e dönüştürünüz. (Hoca alıştırma olarak bıraktı.)

> **Çözüm (derste verildi):** Ters çevir ve parantezleri düzelt: `(E-D^C)*B+A`; postfix algoritmasıyla `EDC^-B*A+`; ters çevir: `+A*B-^CDE`.

**Soru 12** (ekrandan, 02:15:00): `*-A/BC-/AKL` prefix ifadesini postfix'e dönüştürünüz.

> **Çözüm (derste verildi):** Sağdan sola okunup her operatörde $s_1\,s_2\,\text{op}$ yazılır; sonuç `ABC/-AK/L-*`.

**Soru 13** (ekrandan, 02:20:00): "Temel işlem (basic operation), algoritmanın çalışma süresini en çok etkileyen işlemdir. Sıralamada ........ temel işlemdir." Boşluğa ne gelir?

> **Cevap (derste verildi):** Karşılaştırma.

**Soru 14** (derste sözlü, 02:37:26): Biri $50n$, diğeri $n^2$ ile çalışan iki algoritmadan hangisi seçilir? Ayrıca $2^n$ ve $n^2$ zamanlı algoritmalardan hangisi hangi $n$ değerlerinden sonra daha iyidir?

> **Cevap (derste verildi):** Büyük $n$ için doğrusal ($50n$) algoritma seçilir. $2^n$ ile $n^2$ için $n=2$ ve $n=4$'te değerler eşit, $n=3$'te $2^n$ daha küçük, $n \ge 5$ için $n^2$ daha küçüktür; dolayısıyla $n \ge 5$ için $n^2$'li algoritma daha iyidir.

## Dersin Toparlaması

Bu derste algoritma kavramıyla başlandı: algoritma sonlu, kesin ve sıralı adımlardan oluşur ve giriş, çıkış, doğruluk, sonluluk, etkililik ve genellik özelliklerini taşımalıdır. Bu özellikler doğrusal ve ikili arama, kabarcık, seçmeli ve araya eklemeli sıralama ile Öklid algoritması üzerinden incelendi. Aynı problem için farklı algoritmaların farklı sayıda işlem yaptığı görüldü; bu da algoritma tasarım yöntemlerine (kaba kuvvet, böl/azalt/dönüştür ve yönet, açgözlü, dinamik programlama vb.) ve karmaşıklık kavramına bağlandı.

Ardından dizi ve bağlı liste temelinde yığın, kuyruk ve öncelikli kuyruk yapıları tanıtıldı. Yığının en önemli uygulaması olarak infix, prefix ve postfix notasyonları; bu ifadelerin yığınla değerlendirilmesi ve birbirine dönüştürülmesi ayrıntılı örneklerle işlendi. Prefix ve postfix ifadelerin tek yığınla, öncelik kontrolüne gerek kalmadan değerlendirilebilmesi, derleyicilerin neden bu biçimleri kullandığını açıklar. Son bölümde algoritma analizine giriş yapıldı: temel işlem, yürütme zamanı $T(n)$, alan maliyeti, seçmeli sıralamanın ayrıntılı sayımı, fonksiyonların büyümesi ve en kötü, en iyi ve ortalama durum analizleri. Bir sonraki derste Büyük-O, Büyük-Omega ve Büyük-Teta notasyonlarının tanımları ve özellikleriyle devam edilecek, ardından bazı veri yapıları ve algoritmalar üzerinde analiz yapılacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
