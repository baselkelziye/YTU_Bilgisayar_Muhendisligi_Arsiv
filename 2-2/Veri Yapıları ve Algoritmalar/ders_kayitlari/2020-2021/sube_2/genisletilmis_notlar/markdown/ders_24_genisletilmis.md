# Ders 24 Genişletilmiş Notu: Substring (Dizgi) Arama: Brute Force, Horspool, Boyer-Moore ve Rabin-Karp

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Substring Arama Problemi
- 2. Substring Aramanın Kullanım Alanları
- 3. Brute Force Substring Arama
- 4. Akan Veri ve Backup Sorunu
- 5. Boyer-Moore-Horspool Algoritması
- 6. Bad Match Table Oluşturma ve Horspool Örnekleri
- 7. Horspool Algoritmasının Karmaşıklığı
- 8. Boyer-Moore Algoritması
- 9. Rabin-Karp Algoritması
- 10. Substring Arama Algoritmalarının Maliyet Karşılaştırması
- Örnek Sorular

## 1. Substring Arama Problemi

Dersin son konusu, karakter dizileri (string) üzerinde arama yöntemleridir. Hoca bütün yöntemleri incelemeyeceklerini, çok iyi çalışan ve yaygın kullanılan "üç buçuk" algoritmaya bakacaklarını söyledi. Buradaki "buçuk", Boyer-Moore'un sadeleştirilmiş hâli olan Horspool algoritmasıdır.

Problemin tanımı şöyledir (ekrandan, 00:10:00): **$N$ boyutundaki bir metin içinde $M$ boyutundaki bir metni (deseni) bulmak.** Aranan kısa metne *pattern* (desen, örüntü), içinde arama yapılan uzun metne *text* denir.

- Genellikle $N \gg M$ olur. Elimizde çok uzun veriler vardır; aranan örüntü görece kısadır, bazen bir kelime kadar olabilir.
- Metin sabit uzunlukta olmak zorunda değildir; **sonsuz uzunlukta akan veri** de olabilir. Hoca bunu sürekli akan sosyal medya mesajlarına ve bir ağ üzerinden telgraf gibi harf harf gelen bir karakter katarına benzetti.
- Ekrandaki örnek: desen `NEEDLE`, metin `...INAHAYSTACKNEEDLEINAHAYSTACK...` ("samanlıkta iğne aramak").
- Amaç, çok büyük miktarda verinin içinde örüntüyü **hızlı ve verimli** biçimde bulmaktır. Örneğin binlerce, hatta milyonlarca satır kodun içinde `public` anahtar kelimesinin kaç kez geçtiğini saymak istenebilir.

## 2. Substring Aramanın Kullanım Alanları

Hoca substring aramanın geçtiği birçok alan saydı:

- **Web aramaları:** Bir sayfa, aranan kelime içinde geçiyorsa sonuç olarak döndürülür.
- **Veritabanı sorguları:** Belirli bir ada ya da doğum yılına sahip kayıtları seçerken sorgu motoru ilgili kolonun içeriğini aranan değerle karşılaştırır.
- **İntihal tespiti:** Birebir aynı örüntüler aranabilir. Cümleye araya kelime eklenerek yapılan değişiklikleri yakalamak için de desen daha küçük parçalara bölünüp aranır.
- **Adli bilişim (forensics):** Bir disk ya da bellek imajında belirli imzalar aranır. Örneğin bir RSA anahtarının diskte bulunup bulunmadığına bakılır ya da `http`/`https` ile başlayan bütün URL izleri taranır. Terabaytlarca veri söz konusu olduğundan hızlı ve etkin bir arama algoritması gerekir.
- **Spam tespiti:** Spam belirtisi olan örüntüler aranır. Göndericiler filtreye takılmamak için harf yerine benzer görünen rakamlar kullanabilir (O yerine 0 gibi). Birebir eşleşme arayan bir yöntem bunları kaçırır. Bu yüzden bu tür varyantlar da desen olarak üretilip e-posta gövdelerinde aranır. Desen tek bir kelime de olabilir, bir cümle kadar uzun da.
- **Gözetleme ve izleme:** Hoca bir anlatımla örnek verdi. Bir istihbarat ajanı güvenlik için bütün internet trafiğini izlemek ister. Yasa koyucu iletişimin gizliliği nedeniyle buna izin vermez. Ancak yalnızca belirli bir şüpheli örüntüyü (örneğin "attack at dawn") arayan ve bulduğunda yerini bildiren bir makineye izin verebilir. Böyle bir makinenin merkezinde yine substring arama vardır.
- **Bilgi çıkarımı (information extraction):** Bir finans sayfasının HTML kodunda önce "Last Trade" ifadesi aranır. Sonra ondan hemen sonraki kalın yazı etiketinin açılış ve kapanışı bulunur. Bu iki indisin arasındaki alt dizgi okunarak hissenin son değeri elde edilir.

## 3. Brute Force Substring Arama

### 3.1 Yöntem

İlk akla gelen yol, hiçbir ön hazırlık yapmadan "dümdüz" aramaktır (ekrandan, 00:20:00):

- Veri içinde aranan örüntünün başlangıcını bir kaydırarak ara.
- İlk karakter eşleşirse örüntünün $2..m$ arası karakterlerini de eşleştirmeye çalış.
- Hepsi eşleşirse bulduk.
- Eşleşmezse bir kaydırıp aramaya devam et.
- Sona geldiysek bulamadık.

Java'daki `String.indexOf()` metodu da bu şekilde çalışır.

Karmaşıklık her zaman $n$ (metnin uzunluğu) ve $m$ (desenin uzunluğu) üzerinden hesaplanır. Derste iki sözde kod biçimi anlatıldı. Birincisinde $s$ kaydırması $0$'dan $n-m$'ye kadar gider; $P[1..m] = T[s+1..s+m]$ ise desen $s$ kaydırmasında bulunmuştur. Hoca, döngü bittiğinde "bulunamadı" (ya da $-1$) döndüren bir satır eklenebileceğini söyledi. İkinci biçimde $i$ dış döngüde $0..n-m$ arasında gezer. İç döngüde $j < m$ ve `P[j] == T[i+j]` olduğu sürece $j$ artırılır. Döngü sonunda $j = m$ ise $i$ yazdırılır. <!-- BELİRSİZ: Brute force sözde kodunun ve akış diyagramının slaytı karelerde görünmüyor; anlatım altyazıdan alındı. -->

### 3.2 İlk örnek

`ACAABC` metninde `AAB` aranır:

1. $s=0$: A/A eşleşir, ikinci karakterde C/A eşleşmez; bir kaydır.
2. $s=1$: C/A eşleşmez; bir kaydır.
3. $s=2$: A/A, A/A, B/B eşleşir. Desen **2. indiste** bulunur.
4. Başka geçişler de aranacaksa sona kadar devam edilir. $s=3$'te A/A eşleşir, B/A eşleşmez ve metin biter.

İkinci örnekte metinde `SIMPLE` deseni aranır. Her eşleşmeme sonrasında desen bir kaydırılır; sonunda S, I, M, P, L, E altı karakterin hepsi eşleşir ve desenin başladığı indis döndürülür.

**Soru:** Madem eşleşmedi, deseni daha fazla kaydıramaz mıyız? **Cevap:** Brute force'ta kaydıramayız. Kaydırırsak hemen sonraki pozisyondan başlayan bir geçişi kaçırabiliriz. Bu yüzden birer birer kontrol etmek zorundayız.

### 3.3 En kötü durum

En kötü durum, veri ve örüntünün tekrarlı olmasıdır (ekrandan, 00:25:00). Metin `AAAAAAAAAB` (indis 0-9), desen `AAAAB`:

| i | j (eşleşen) | i+j | durum |
|---|---|---|---|
| 0 | 4 | 4 | AAAA eşleşti, B eşleşmedi |
| 1 | 4 | 5 | AAAA eşleşti, B eşleşmedi |
| 2 | 4 | 6 | AAAA eşleşti, B eşleşmedi |
| 3 | 4 | 7 | AAAA eşleşti, B eşleşmedi |
| 4 | 4 | 8 | AAAA eşleşti, B eşleşmedi |
| 5 | 5 | 10 | AAAAB bulundu |

Her kaydırmada desenin boyu kadar ($M$ tane) karakter karşılaştırılır ve kaydırma sayısı $N$ mertebesindedir. Toplam $M \cdot N$ karşılaştırma yapılır, yani karmaşıklık $O(MN)$'dir. $M$ büyüyüp $N$'ye yaklaşırsa bu tavanı $N^2$ olan bir karmaşıklığa döner. Ancak genellikle $M \ll N$ olduğu için ayrı ayrı $MN$ diye yazılır.

## 4. Akan Veri ve Backup Sorunu

Statik veride brute force sorunsuz ileri gidebilir. Ancak veri akıyorsa, birkaç karakter eşleşip sonuncusu tutmadığında "geri dönüp bir kaydırmak" mümkün değildir: bu sırada yeni karakterler gelmeye devam eder. Kaçırmamak için son $M$ (ya da $M-1$) karakterin bir ön bellek alanında tutulması gerekir. Buna **backup** denir.

Hoca istihbarat örneğine geri dönerek pratikte backup kadar bilgiyi saklayacak **yerimiz**, **zamanımız** ya da **iznimiz** olmayabileceğini söyledi (ekrandan, 00:30:00). Böyle durumlarda backup kullanmayan yöntemlere bakmak gerekir.

Backup tutulabiliyorsa brute force şöyle yazılabilir (akış diyagramı, ekrandan, 00:30:00):

```text
START
oku: N, T[N], M, P[M]
i <- 0, j <- 0
döngü (i < N ve j < M), her turda i bir artar:
    T[i] = P[j] ise  j <- j + 1
    değilse          i <- i - j ; j <- 0
j = M ise  yaz: i - M      (desenin başladığı indis)
değilse    yaz: 'yok'
STOP
```

Eşleşme oldukça $j$ artar; böylece desenin 2., 3., ..., $m$. karakterlerine ilerlenir. Eşleşme bozulunca `i ← i − j` yapılır: metinde eşleşen kadar geri dönülür. Backup'a ihtiyaç duyulan alan budur. Döngü bittiğinde $j = M$ ise desen $i - M$ indisinde bulunmuştur. Değilse döngüden metin bittiği için çıkılmıştır ve desen metinde yoktur.

Backup kullanmayan yöntemlerin en bilineni **Knuth-Morris-Pratt (KMP)** algoritmasıdır. Hoca bu derste KMP'yi anlatmayacağını söyledi. Onun yerine arama kutularının arkasında daha yaygın kullanılan Boyer-Moore-Horspool algoritmasına geçti.

## 5. Boyer-Moore-Horspool Algoritması

### 5.1 Fikir

Brute force sağlam bir yöntemdir ama karmaşıklığı $n \cdot m$'ye kadar çıkar. Zayıf noktası, her eşleşmemede yalnızca **bir** karakter ilerlemesidir. Horspool şu soruyu sorar: Deseni soldan sağa değil **sağdan sola** tarasam, yani önce son karakteri kontrol etsem, eşleşmeme olduğunda daha fazla kaydırabilir miyim? Horspool'un makalesi 1980'de yayımlanmıştır.

Slayt başlığında "Boyer-Moore" kısmı açık gri, "Horspool" koyu yazılmıştır. Gerçek algoritma Boyer-Moore'dur; Horspool onun basit (hafifletilmiş) bir sürümüdür. Hoca, internetteki kaynaklarda bu ikisinin sık karıştırıldığını ve farkı bilmenin kaynakları süzmeye yardım edeceğini söyledi.

Slayttaki özet (ekrandan, 00:35:00):

- Eşleşmeyen karakter sezgisi (**Bad Character Heuristic**) olarak da bilinir.
- Örüntüdeki karakterleri **sağdan sola** tara.
- Örüntüde olmayan bir karakterle karşılaşıldığında $X$ adet karakter geçilebilir. Brute force'ta birer birer ilerliyorduk. Sorun $X$'in kaç olacağıdır: bir eşleşmeyi kaçırmamayı garanti ederek olası en büyük ilerlemeyi yapmak gerekir.
- "Kötü Eşleşme Tablosu" (**Bad Match Table**) oluşturulur ve buradaki miktar kadar kaydırma yapılır.
- Genellikle lineer zaman, en kötü durumda kuadratik.

Örneğin desen `ABC` ise ve son karakter C'nin karşısına metinde E gelmişse, E desende hiç olmadığı için desen E'nin ötesine, yani $m$ karakter birden taşınabilir. Karakter desende varsa $1$ ile $m$ arasında bir $X$ kadar kaydırılır.

> **Hocanın vurgusu:** Horspool sağdan sola karşılaştırdığı için akan veride yine küçük de olsa $M$ karakterlik bir backup (ön bellek) alanına ihtiyaç duyar.

### 5.2 Kaydırma durumları

Bad match table'ın nasıl dolacağını anlamak için olası durumlara bakılır.

**Durum 1: Metinde karşılaştırılan karakter ($c$) desende yoktur** (ekrandan, 00:40:00). Desen `BARBER`, son karakter R'nin karşısında metinde `S` var. S desende olmadığı için bu altı karakterlik pencerede hiçbir eşleşme olamaz. Desen rahatlıkla boyu kadar (6) kaydırılır. Brute force'ta burada bir kaydırırdık; şimdi tek karşılaştırmayla altı kaydırdık.

**Durum 2: $c$ desende var ama desenin son karakteri değildir.** `BARBER`'in son karakteri R'nin karşısına `B` gelmiştir. Desende iki B vardır, dolayısıyla iki seçenek akla gelir:

- En sağdaki B'yi (indis 3) metindeki B'nin hizasına getirmek, yani 2 kaydırmak. Doğru olan budur ve yine de bir karakterden iyidir.
- Soldaki B'yi (indis 0) hizalamak, yani daha fazla kaydırmak. Bu hatalıdır: metinde tam o noktada `BARBER` geçiyorsa kaçırılır.

Kural: Desen, karakterin desendeki **en sağ** pozisyonu metindeki karakterle hizalanacak kadar kaydırılır. En kötü ihtimalle (örneğin $c$ = E ise) bu yalnız bir karakterdir ve brute force gibi davranılır.

**Durum 3: $c$ desenin son karakteridir ve kalan $m-1$ karakter içinde başka tekrarı yoktur.** Desen `LEADER`: R eşleşir, E eşleşir, D'nin karşısında `M` vardır. Kaydırma son karakterin hizasındaki R'ye göre yapılır. R, `LEADER`'in ilk beş harfinde geçmediği için desen yine boyu kadar (6) kaydırılır. Üç karşılaştırma yapıldı, ama desen altı karakter ileri atıldı.

**Durum 4: $c$ desenin son karakteridir ve başka tekrarı da vardır** (ekrandan, 00:45:00). Metinde `... A R ...`, desen `REORDER`. R eşleşir, E/A eşleşmez. A desende olmadığı için daha fazla kaydırmak mümkün görünse de Horspool'un kaydırması son karakterin hizasındaki R'ye göre belirlenir. Durum 2'ye benzer şekilde, kalan $m-1$ karakter içinde R'nin en sağda geçtiği yere (indis 3) kadar kaydırılır. Hoca bunu Horspool'un zayıf, "kaybettiren" noktası olarak nitelendirdi: tablo tek bir kurala göre kurulduğu için kaydırma bu durumda olması gerekenden az kalır. Yine de brute force'tan çok daha iyidir.

> **Ders sonrası not:** Hoca bu örnekte desenin "sadece 4 karakter" ilerlediğini söyledi. Slayttaki çizimde ve tablo kuralına göre `REORDER` için $t(R) = 7-1-3 = 3$'tür (python ile doğrulandı); kaydırma büyük olasılıkla 3 karakterdir.

## 6. Bad Match Table Oluşturma ve Horspool Örnekleri

### 6.1 Tablonun kuruluşu

Her karşılaştırmada bu durumları ayrı ayrı düşünmek yerine bir karakter tablosu kurulur. Hoca tahtaya A, B, C, D, E, F sütunlu bir tablo çizdi. Desen yalnızca A, B, C'den oluşuyorsa D, E, F görüldüğünde desen boyu (3) kadar kaydırılır, çünkü bu karakterler desende yoktur.

Tablo iki adımda doldurulur:

1. Tablonun boyutu alfabedeki karakter sayısıdır. $i = 0 \ldots size-1$ için bütün elemanların kaydırma değeri $m$ yapılır.
2. $j = 0 \ldots m-2$ için $\text{Table}[P[j]] = m - 1 - j$ yazılır. Burada $m$ desenin uzunluğu, $j$ karakterin desendeki indisidir. $-1$ terimi indislerin sıfırdan başlamasından gelir.

<!-- BELİRSİZ: ShiftTable sözde kodunun slaytı karelerde görünmüyor; yukarıdaki iki adım altyazıdaki anlatımdan alındı. -->

Aynı karakter desende birden çok kez geçiyorsa soldan sağa ilerlerken sağdaki geçişin değeri öncekinin üzerine yazılır. Böylece en sağdaki geçiş kazanır. Son karakter ($j = m-1$) döngüye girmez.

### 6.2 Horspool eşleştirme sözde kodu

Slayttaki algoritma (ekrandan, 00:50:00):

```text
ALGORITHM HorspoolMatching(P[0..m-1], T[0..n-1])
// Implements Horspool's algorithm for string matching
// Input: Pattern P[0..m-1] and text T[0..n-1]
// Output: The index of the left end of the first matching substring
//         or -1 if there are no matches
ShiftTable(P[0..m-1])   //generate Table of shifts
i <- m - 1              //position of the pattern's right end
while i <= n - 1 do
    k <- 0              //number of matched characters
    while k <= m - 1 and P[m - 1 - k] = T[i - k] do
        k <- k + 1
    if k = m
        return i - m + 1
    else i <- i + Table[T[i]]
return -1
```

Açıklama:

- $i$, desenin sağ ucunun metindeki pozisyonudur; başta $m-1$'dir.
- $k$, sondan itibaren eşleşen karakter sayısıdır. $P[m-1-k] = T[i-k]$ olduğu sürece artar.
- İç döngüden ya bir eşleşmeme yüzünden ya da bütün karakterler eşleştiği için çıkılır. $k = m$ ise desen $i - m + 1$ indisinde bulunmuştur.
- Değilse desen $\text{Table}[T[i]]$ kadar kaydırılır. Burada $T[i]$, metinde desenin son karakterinin hizasındaki karakterdir.
- Ön işlemeden sonra arama tek bir `while` döngüsüyle, $n$ mertebesinde tamamlanır.

**Soru:** Bu algoritma metindeki birden fazla geçişi bulamıyor, değil mi? **Cevap:** Bu implementasyona bağlıdır. `return i - m + 1` satırında dönmek yerine indis bir yere kaydedilir ve aramaya devam edilir. Sonunda bulunan bütün indisler döndürülebilir. Slayttaki kod kısa olsun diye ilk bulmada çıkacak şekilde yazılmıştır.

### 6.3 Örnek: BARBER

Alfabe İngilizce harfler (26) ve boşluk karakterinden oluşur (ekrandan, 01:00:00 ve 01:10:00). `BARBER` için ($m = 6$) tablo:

| c | A | B | C | D | E | F | ... | R | ... | Z | _ |
|---|---|---|---|---|---|---|---|---|---|---|---|
| t(c) | 4 | 2 | 6 | 6 | 1 | 6 | 6 | 3 | 6 | 6 | 6 |

- R görülürse 3 kaydırılır ($m-1-j = 6-1-2$): indis 2'deki R hizalanır.
- E görülürse yalnız 1 kaydırılır; en kötü değer budur.
- B görülürse 2 kaydırılır (indis 3'teki B hizalanır).
- A görülürse 4 kaydırılır.
- Diğer bütün karakterler ve boşluk için 6.

Metin `JIM_SAW_ME_IN_A_BARBERSHOP` (alt çizgi boşluğu gösterir):

1. Desen metnin başına hizalanır. Son karakter R ile metindeki `A` karşılaştırılır, eşleşmez. Tabloda A = 4; desen 4 kaydırılır. Böylece desendeki A metindeki A ile hizalanmış olur ve bir geçiş kaçırılmaz.
2. R ile `E` karşılaştırılır; E = 1, desen 1 kaydırılır.
3. R ile boşluk karşılaştırılır; boşluk = 6, desen 6 kaydırılır.
4. R ile `B` karşılaştırılır; B = 2, desen 2 kaydırılır.
5. R ile R eşleşir. Bir sola geçilir: E ile `A` eşleşmez. Kaydırma, desenin son karakterinin hizasındaki metin karakteri R'ye göre yapılır: R = 3. A'nın değeri (4) kullanılmaz.
6. Şimdi R, E, B, R, A, B karakterlerinin hepsi eşleşir. Desen $i - m + 1 = 16$ indisinde bulunur.

> **Ek bilgi (derste anlatılmadı):** Adımlar python ile çalıştırıldığında desenin sol ucu sırasıyla 0, 4, 5, 11, 13 pozisyonlarından geçer ve 16'da eşleşme bulunur. Kaydırmalar 4, 1, 6, 2, 3'tür; bu sonuç slayttaki çizimle aynıdır.

### 6.4 Örnek: TOOTH için tablo oluşturma

Hoca tabloyu kurma döngüsünün tekrar eden karakterlerde nasıl çalıştığını göstermek için `TOOTH` kelimesini seçti (ekrandan, 01:15:00). $m = 5$, indisler 0-4. Desende olmayan bütün karakterler (`*`) için değer 5'tir.

| j | P[j] | m−1−j | tablo sonrası |
|---|---|---|---|
| 0 | T | 5−1−0 = 4 | T = 4 |
| 1 | O | 5−1−1 = 3 | O = 3 |
| 2 | O | 5−1−2 = 2 | O = 2 (3'ün üzerine yazıldı) |
| 3 | T | 5−1−3 = 1 | T = 1 (4'ün üzerine yazıldı) |
| 4 | H | döngüye girmez | H = 5 |

Döngü $m-2$'ye kadar gittiği için son karakter H işlenmez. Hoca bunu şöyle açıkladı: H için hesap $5-1-4 = 0$ olurdu, ama kaydırma 0 olamaz. H desende başka yerde geçmediği için değeri 5 kalır. Sonuç tablosu:

| Harf | T | O | H | * |
|---|---|---|---|---|
| Değer | 1 | 2 | 5 | 5 |

Metin `TRUSTHARDTOOTHBRUSHES` (boşluklar kaldırılmış):

1. Desen başa hizalanır. Son karakter H ile metindeki `T` eşleşmez; T = 1, desen 1 kaydırılır.
2. H/H eşleşir, T/T eşleşir, sonra O ile `S` eşleşmez. Kaydırma, desenin son karakterinin hizasındaki H'ye göre yapılır: H = 5; desen 5 kaydırılır.
3. H ile `O` karşılaştırılır; O = 2, desen 2 kaydırılır.
4. H ile `T` karşılaştırılır; T = 1, desen 1 kaydırılır.
5. H, T, O, O, T hepsi eşleşir; desen bulunur (python ile kontrol: indis 9).

Bulunamasaydı metnin sonuna kadar kaydırmaya devam edilir ve sonunda $-1$ döndürülürdü.

## 7. Horspool Algoritmasının Karmaşıklığı

Slayttaki özet (ekrandan, 01:20:00):

- **En kötü durum:** Girdi tamamen `A` harflerinden oluşur, desen `BAAAAA`'dır. Desen sağdan sola karşılaştırıldığı için her hizalamada A'lar eşleşir, en baştaki B tutmaz. Kaydırma $T[i] = A$'ya göre yapılır ve $t(A) = 1$'dir. Her adımda $m$ karşılaştırma yapılıp yalnız 1 kaydırılır; bu brute force'un aynısıdır. En kötü durum $O(nm)$'dir.
- **En iyi durum:** Her adımda desen boyu kadar ileri gidilir ("lap diye 5 karakter ileri"). Toplam $n/m$ adım yapılır; karmaşıklık $O(n/m)$, yani **sublineer**dir.
- **Ortalama:** Gerçek hayattaki metinlerde $O(n)$, yani lineer mertebededir.
- Tabloyu kuran ön işlemede $m$'lik bir `for` döngüsü vardır; bu yüzden $m + n$ denebilir. $m$ çok küçük olduğundan genelde göz ardı edilir.

Hoca Horspool'un implementasyonunun çok basit olduğunu vurguladı: ön işlemede bir `for` ile tablo kurulur, sonra tek bir `while` ile "eşleştir, eşleşmiyorsa tablodaki değer kadar kaydır" yapılır.

## 8. Boyer-Moore Algoritması

### 8.1 Horspool'dan farkı

Horspool, öncüsü olan Boyer-Moore algoritmasının basitleştirilmiş hâlidir. Boyer-Moore'da bad match tablosu yine kullanılır, ama özellikle tekrarlı desenlerde daha fazla kaydırma sağlayabilmek için ikinci bir sezgi eklenir: **good suffix** (iyi son ek) sezgisi. Sondan birden fazla karakter eşleşmişse (örneğin iki ya da üç karakterlik bir son ek) ve bu son ek desenin başka bir yerinde de geçiyorsa, desen bu tekrarı hizalayacak kadar kaydırılabilir.

Böylece iki kaydırma önerisi oluşur: bad match tablosunun önerisi ($d_1$) ve good suffix tablosunun önerisi ($d_2$). Algoritma desenini daha ileri taşıyan önerinin, yani büyük olanın kadar kaydırır. Good suffix tablosu da ön işlemede bir kez hesaplanıp kenara konur.

### 8.2 Birinci kaydırma: bad symbol shift

Son karakter eşleşmezse ($k = 0$) algoritma Horspool ile aynı davranır. Bad match tablosundaki değer kadar kaydırılır.

$0 < k < m$ karakter sondan eşleştikten sonra metindeki $c$ karakteri eşleşmezse Boyer-Moore farklılaşır (ekrandan, 01:25:00):

- Eşleşmeyen $c$ karakteri bad match tablosunda yoksa desen $c$'nin bir sağına ($c+1$'e) kaydırılır (**bad symbol shift**).
- Varsa $t_1(c) - k$ kadar (tablo değeri eksi eşleşen karakter sayısı) kaydırılır.

Slayttaki örnekler (ekrandan, 01:45:00):

- Desen `BARBER`, metinde `...SER...`: R ve E eşleşir, S eşleşmez. S desende yok; desen $c+1$'e, yani **4 karakter** ileri kaydırılır. Horspool burada R'nin değeri olan 3 kadar kaydırmıştı. Bir karakterlik bu kazanç, başka durumlarda $m$'ye yaklaşacak kadar büyük olabilir.
- Metinde `...AER...`: R ve E eşleşir, A eşleşmez. A desende var; $t_1(A) - 2 = 4 - 2 = 2$ kaydırılır ve desendeki A metindeki A ile hizalanır.

$t_1(c) - k$ değeri sıfır ya da negatif olabilir. Desen geriye çekilemeyeceği için en az bir karakter ilerlenir:

$$d_1 = \max\{t_1(c) - k,\ 1\}$$

### 8.3 İkinci kaydırma: good suffix shift

Sondan eşleşen $k > 0$ karakterlik parçaya $k$ boyutunda son ek, $\text{suff}(k)$ denir (ekrandan, 01:30:00). Bad match tablosunda olduğu gibi, desendeki 1'den $m-1$'e kadar her boyuttaki son ek için bir good suffix tablosu ($d_2$) doldurulur.

Önündeki karakteri farklı olan bir $\text{suff}(k)$ desen içinde başka bir yerde de geçiyorsa, desen bu tekrarı son ekin hizasına getirecek kadar kaydırılabilir. Örnek desen `ABCBAB`:

| k | eşleşen son ek | tekrarı | $d_2$ |
|---|---|---|---|
| 1 | B | indis 3'teki B | 2 |
| 2 | AB | baştaki AB | 4 |

B eşleştiğinde 2, AB eşleştiğinde ise baştaki AB'ye kadar 4 karakter kaydırılabilir.

**Son ekin tekrarı yoksa:** Hoca bu durumda deseni doğrudan boyu kadar kaydırmanın yanlış olabileceğini gösterdi. `BAB` eşleşip önceki karakter tutmadığında (metinde X gibi bir karakter) BAB'in desende başka tekrarı yoktur. Desen 6 kaydırılırsa, metinde örneğin `...C B A B C B A B` gibi bir dizilim varsa ikinci yarıdan başlayan `ABCBAB` geçişi kaçırılır. Bu yüzden tekrarı olmayan son ekler için bir sınır konur: o ana kadarki en uzun tekrar eden son ekin değeri korunur, daha fazla kaydırılmaz. <!-- BELİRSİZ: Bu slayttaki desen ve metin karelerde görünmüyor; altyazıda desen "D, B, C, B, A, B" diye geçiyor, kaçırılan geçiş ise "A, B, C, B, A, B" diye anlatılıyor. -->

`ABCBAB` için tablonun tamamı:

| k | son ek | $d_2$ |
|---|---|---|
| 1 | B | 2 |
| 2 | AB | 4 |
| 3 | BAB | 4 |
| 4 | CBAB | 4 |
| 5 | BCBAB | 4 |

$k = 3, 4, 5$ için son ekler tekrar etmez. Bu durumlarda AB'yi baştaki AB'ye oturtacak kadar, yani 4 kaydırılır.

### 8.4 Karar kuralı

Elimizde iki uzaklık değeri vardır: $d_1$ (bad match) ve $d_2$ (good suffix).

$$
d = \begin{cases} d_1 & k = 0 \\ \max\{d_1, d_2\} & k > 0 \end{cases}
$$

$k = 0$ ise doğrudan Horspool gibi çalışılır. $k > 0$ ise iki öneriden hangisi daha kârlıysa o kadar kaydırılır.

### 8.5 Örnek: BAOBAB

Desen `BAOBAB`, metin `BESS_KNEW_ABOUT_BAOBABS` (ekrandan, 01:35:00 ve 01:40:00).

Bad match table ($t_1$):

| c | A | B | C | D | ... | O | ... | Z | _ |
|---|---|---|---|---|---|---|---|---|---|
| $t_1(c)$ | 1 | 2 | 6 | 6 | 6 | 3 | 6 | 6 | 6 |

Good suffix table ($d_2$):

| k | son ek | $d_2$ |
|---|---|---|
| 1 | B | 2 |
| 2 | AB | 5 |
| 3 | BAB | 5 |
| 4 | OBAB | 5 |
| 5 | AOBAB | 5 |

Tek karakterlik son ekte $d_2$, bad match ile aynı sonucu verir. AB'nin desende tekrarı yoktur; ancak desenin başındaki B, son ekin son karakteriyle hizalanabilir. Bu yüzden $k \ge 2$ için 5 kaydırılır. Hoca'nın ifadesiyle, AB eşleşmesi görüldüğünde 2 yerine 5 karakter ileri gidilebilir.

Arama adımları:

1. Desen metnin başına hizalanır. Son karakter B ile metindeki `K` karşılaştırılır, eşleşmez ($k=0$). $d_1 = t_1(K) - 0 = 6$. K desende olmadığı için son ek oluşmaz; good suffix tablosuna bakmaya gerek yoktur. Desen 6 kaydırılır.
2. B/B eşleşir, A/A eşleşir ($k = 2$). Üçüncü karakterde boşluk ile B eşleşmez. $d_1 = t_1(\_) - 2 = 6 - 2 = 4$, $d_2 = 5$; $\max(4, 5) = 5$ kaydırılır (ekrandan, 01:40:00).
3. B/B eşleşir ($k = 1$), boşluk ile A eşleşmez. $d_1 = 6 - 1 = 5$, $d_2 = 2$. Bu kez bad match daha kârlıdır; 5 kaydırılır.
4. B, A, B, O, A, B karakterlerinin hepsi eşleşir; desen bulunur.

> **Ek bilgi (derste anlatılmadı):** Adımlar python ile çalıştırıldığında desenin sol ucu 0, 6 ve 11 pozisyonlarından geçer ve eşleşme 16. indiste bulunur. Kaydırmalar 6, 5, 5'tir; bu sonuç slayttaki değerlerle aynıdır.

### 8.6 Horspool mu, Boyer-Moore mu?

> **Hocanın vurgusu:** İnternette bu iki algoritma çok karışık biçimde bulunur; insanlar Horspool diye Boyer-Moore kodu verebilir. Ayrım şudur: Hem bad match table hem good suffix tablosunu ön işlemede kurup karar verirken iki değere bakarak kaydıran kod **Boyer-Moore**'dur. Yalnız bad match table kurup başka tablo olmadan kaydıran kod **Horspool**'dur.

Horspool çok daha kolay implement edilir. Boyer-Moore'da good suffix tablosunu kurmak için biraz daha iş gerekir ve karar verirken iki tablodan birden değer alınır.

**En kötü durum:** Boyer-Moore her seferinde Horspool gibi davranıp Horspool'un en kötü durumuna düşerse yine $m \cdot n$'e çıkabilir. Ancak genellikle Horspool'dan daha fazla kaydırdığı için toplam maliyet biraz daha azdır. Ortalamada lineer zamanda kalır. Kuadratik durum özel seçilmiş bir desen ve metin gerektirir.

## 9. Rabin-Karp Algoritması

### 9.1 Fikir

Brute force, Horspool ve Boyer-Moore deseni doğrudan metin üzerinde, karakter karakter karşılaştırarak arar. Rabin-Karp'ın fikri bunun tersidir: metni doğrudan aramak yerine **imzasını** aramak (ekrandan, 01:50:00).

- **İmza:** Desenin bir hash fonksiyonundan geçirilmiş çıktısıdır. Metindeki her $m$ uzunluklu pencerenin de imzası hesaplanıp desenin imzasıyla karşılaştırılır. Bu sayısal bir aramadır.
- İmza bulunamazsa desen o pencerede kesinlikle yoktur.
- **Hash çıktıları çakışabilir:** Hash fonksiyonu yeterince güçlü seçilmemişse farklı desenler aynı imzayı üretebilir. Bu yüzden hash'i eşleşen parça desenle **birebir karşılaştırılır**. Yalnız $m$ karakterlik bir kontrol yeterlidir.
- Çoklu aramalarda iyi çalışır.

Karmaşıklık:

- Ön işleme (desenin hash'i): $O(m)$.
- En kötü durum: $O(mn)$. Her pencerede imza tutar ama her seferinde şans eseri başka bir desen aynı hash'i üretmiştir, bu yüzden her seferinde $m$ karakter kontrol edilir. Bu olasılık çok düşüktür; hash fonksiyonu iyi seçilirse pratikte önlenebilir.
- Genellikle $O(m+n)$; baskın terim $n$ olduğundan lineer.

Hoca hash fonksiyonunu, girdiyi belirli matematik işlemlerinden geçirip bir çıktı (imza) üreten, geri dönüşü olmayan, tek yönlü bir dönüşüm olarak tanımladı. Girdi değiştiğinde farklı çıktı üretecek şekilde çalışır.

### 9.2 Örnek: π'nin basamaklarında arama

Hash fonksiyonunu kolay hesaplamak için desen ve metin sayısal seçildi (ekrandan, 01:55:00). Metin $\pi$ sayısının basamaklarıdır: `31415926535897932384626433`. Aranan desen `59265`'tir.

Hash fonksiyonu olarak bir asal sayıya, $97$'ye göre mod alınır. Çıktı 0 ile 96 arasında bir değerdir. Farklı olasılık sayısı az olduğunda çakışma yaşanmayabilir; çok olduğunda yaşanabilir.

- Desenin hash'i: $59265 \bmod 97 = 95$.
- Metnin ilk 5 karakteri: $31415 \bmod 97 = 84$. $84 \ne 95$; bu pencere desene eşit olamaz. Bir kaydırılır.
- $14159 \bmod 97 = 94$; eşleşmez, bir kaydırılır.
- $41592 \bmod 97 = 76$; eşleşmez.
- $15926 \bmod 97 = 18$; eşleşmez.
- $59265 \bmod 97 = 95$; hash eşleşir.

Hash eşleştiğinde bu kez rakamlar teker teker kontrol edilir: 5, 9, 2, 6, 5 tutar. $m$ karakter eşleştiği için desen gerçekten bulunmuştur. Bütün değerler python ile doğrulandı.

### 9.3 Kayan hash

**Soru:** Her adımda hash hesaplıyoruz; $n$ tane hash işlemi maliyet getirmez mi? **Cevap:** Getirir. Fakat pencere birer kaydığı için bir önceki hash değeri kullanılarak sonraki adımın hash'i çok ucuza hesaplanabilir. İlk hash'in üretimi bir maliyettir, sonrası basit işlemlerdir.

Ekrandaki çözüm (ekrandan, 02:00:00):

$$14159 = (31415 - 30000) \cdot 10 + 9$$

Önceki sayının ilk rakamı atılır, kalan 10 ile çarpılarak bir basamak kaydırılır ve yeni gelen rakam eklenir. Aynı işlem mod 97'de yapılır:

$$14159 \bmod 97 = \big((31415 \bmod 97) - (30000 \bmod 97)\big) \cdot 10 + 9 \pmod{97}$$

- $31415 \bmod 97 = 84$ önceki adımdan bilinir ("known from previous position").
- $10000 \bmod 97 = 9$ önceden hesaplanır ("precompute"). Bu yüzden $30000 \bmod 97 = 3 \cdot 9 = 27$'dir. Ön çarpım değerleri bir tablodan okunabilir.
- $(84 - 27) \cdot 10 + 9 = 57 \cdot 10 + 9 = 579$, $579 \bmod 97 = 94$.

Maliyet bir çıkarma, birkaç çarpma, bir toplama ve küçük bir sayının modudur. Slayttaki not: "Key point: all ops involve small numbers. No restriction on N and M." Bin'den küçük sayılarla çalışılır.

Bütün pencereler (ekrandan, 02:00:00):

| pencere | hesap | hash |
|---|---|---|
| 31415 | $31415 \bmod 97$ | 84 |
| 14159 | $(84 - 3 \cdot 9) \cdot 10 + 9 \pmod{97}$ | 94 |
| 41592 | $(94 - 1 \cdot 9) \cdot 10 + 2 \pmod{97}$ | 76 |
| 15926 | $(76 - 4 \cdot 9) \cdot 10 + 6 \pmod{97}$ | 18 |
| 59265 | $(18 - 1 \cdot 9) \cdot 10 + 5 \pmod{97}$ | 95 |

95 desenin hash'iyle tutar ve ardından rakamlar birebir kontrol edilir.

> **Hocanın vurgusu:** Anahtar nokta seçilen asal sayıdır. Yeterince büyük seçilmelidir. Çok küçük seçilirse (örneğin 7) çakışmalar çok olur. Aynı hash değeri birçok kez görülür ve her seferinde $m$ adımlık ek bir kontrol yapmak gerekir.

Çok sayıda değer aranacaksa hash'ler bir kez hesaplandığı için Rabin-Karp daha da etkin olabilir. Hash fonksiyonu hem çakışmaları önleyecek kadar güçlü hem de bir önceki değerden hesaplanabilecek biçimde seçilirse lineer zamanda arama yapılır.

## 10. Substring Arama Algoritmalarının Maliyet Karşılaştırması

Dersin son slaytı (ekrandan, 02:05:00):

| algorithm | version | guarantee | typical | backup in input? | correct? | extra space |
|---|---|---|---|---|---|---|
| brute force | — | MN | 1.1 N | yes | yes | 1 |
| Knuth-Morris-Pratt | full DFA (Algorithm 5.6) | 2N | 1.1 N | no | yes | MR |
| Knuth-Morris-Pratt | mismatch transitions only | 3N | 1.1 N | no | yes | M |
| (aşağıdaki nota bakın) | full algorithm | 3N | N / M | yes | yes | R |
| Boyer-Moore | mismatched char heuristic only (Algorithm 5.7) | MN | N / M | yes | yes | R |
| Rabin-Karp† | Monte Carlo (Algorithm 5.8) | 7N | 7N | no | yes† | 1 |
| Rabin-Karp† | Las Vegas | 7N† | 7N | yes | yes | 1 |

† probabilistic guarantee, with uniform and independent hash function

Hocanın açıklamaları:

- **Brute force:** En kötü durum $MN$ garantisi verir, gerçek hayatta tipik olarak $1.1N$ civarında çalışır. Geriye dönük backup alanı gerekir. Doğru sonucu garantili bulur. Tablodaki ek alan 1'dir; hoca backup gerekmediğinde 1, gerektiğinde $M$ yazmanın daha doğru olacağını söyledi.
- **KMP:** Derste anlatılmadı; DFA (deterministik sonlu otomat) temelli bir algoritmadır. Backup olmadan çalışır, ama $M \cdot R$'ye kadar ek alan ister.
- **Boyer-Moore (yalnız mismatch karakter sezgisi, yani Horspool sürümü):** En kötü $MN$, tipik $N/M$; bu, öncekilerden çok daha iyi bir performanstır. Bu yüzden Horspool birçok arama kutusunda standart olarak kullanılır. Zayıf noktası backup ihtiyacıdır: son karakterden başlayıp başa doğru gidildiği için $M$'lik backup gerekir. Ek alan, karakter sayısı ($R$) kadar tablodan gelir.
- **Rabin-Karp:** Doğruluk garantisi hash fonksiyonuna bağlıdır. Derste düz mod alma yöntemi kullanıldı. Monte Carlo sürümü $7N$'yi garanti eder ve backup gerektirmez. Las Vegas sürümünü hoca anlatmadı; bu sürümde backup gerekir. Ek alan sabittir, çünkü yalnız bir önceki hash değerini bilmek yeterlidir.

> **Ders sonrası not:** Hoca tabloyu anlatırken "full algorithm" satırını KMP'nin altında değerlendirdi. Tablonun alındığı kaynakta (Sedgewick-Wayne, *Algorithms*) bu satır büyük olasılıkla Boyer-Moore'a aittir: tam Boyer-Moore $3N$ garanti ve tipik $N/M$ ile çalışır. KMP'nin iki satırının tipik değeri $1.1N$'dir.

Hoca karşılaştırmayı bir ödünleşim olarak özetledi: kimi algoritma çok etkin çalışır, kimi ek alan istemez, kimi backup gerektirmez. Yapılan işe, çalışılan ortama ve probleme göre en uygun substring arama yöntemi seçilmelidir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): Brute force substring arama ile `AAAAAAAAAB` metninde `AAAAB` deseni aranıyor. Her kaydırmada kaç karakter karşılaştırılır ve en kötü durum karmaşıklığı nedir?

> **Çözüm:** $i = 0..4$ için her denemede dört A eşleşir ve B eşleşmez: her biri 5 karşılaştırma. $i = 5$'te 5 karşılaştırmayla desen bulunur. Toplam 30 karşılaştırma yapılır (python ile sayıldı). Genel en kötü durum $O(MN)$'dir.

**Soru 2** (ekrandan, 01:00:00): İngiliz alfabesi harfleri ve boşluk için `BARBER` deseninin bad match tablosunu oluşturun ve `JIM_SAW_ME_IN_A_BARBERSHOP` metninde Horspool ile arayın.

> **Çözüm:** A = 4, B = 2, E = 1, R = 3, diğer bütün karakterler 6. Kaydırmalar sırasıyla 4 (A), 1 (E), 6 (boşluk), 2 (B), 3 (R eşleşti, E/A tutmadı; kaydırma $T[i] = R$'ye göre). Desen 16. indiste bulunur.

**Soru 3** (ekrandan, 01:10:00 ve 01:15:00): `TOOTH` deseninin bad match tablosunu adım adım oluşturun ve `TRUSTHARDTOOTHBRUSHES` metninde arayın.

> **Çözüm:** T: 4 → 1, O: 3 → 2, H ve diğerleri: 5. Kaydırmalar 1 (T), 5 (H/H, T/T eşleşti, S/O tutmadı; $T[i] = H$), 2 (O), 1 (T). Desen 9. indiste bulunur.

**Soru 4** (ekrandan, 01:35:00 ve 01:40:00): `BAOBAB` deseni için bad match ve good suffix tablolarını kurun ve `BESS_KNEW_ABOUT_BAOBABS` metninde Boyer-Moore ile arayın.

> **Çözüm:** $t_1$: A = 1, B = 2, O = 3, diğerleri 6. $d_2$: $k=1$ → 2, $k=2..5$ → 5. Adımlar: K'de $d_1 = 6$; boşlukta $k=2$ için $\max(6-2, 5) = 5$; boşlukta $k=1$ için $\max(6-1, 2) = 5$. Desen 16. indiste bulunur.

**Soru 5** (ekrandan, 01:55:00 ve 02:00:00): $\pi$'nin basamakları `31415926535897932384626433` içinde `59265` desenini, mod 97 hash ve kayan hash kullanarak Rabin-Karp ile arayın.

> **Çözüm:** Desen hash'i 95. Pencere hash'leri: 84, $(84-27)\cdot10+9 \equiv 94$, $(94-9)\cdot10+2 \equiv 76$, $(76-36)\cdot10+6 \equiv 18$, $(18-9)\cdot10+5 \equiv 95$. Beşinci pencerede hash tutar, rakamlar tek tek kontrol edilir ve desen bulunur (metindeki 4. indis).

**Soru 6** (derste sözlü, 00:52:49): Horspool algoritması metindeki birden fazla geçişi bulabilir mi?

> **Çözüm:** Bu implementasyona bağlıdır. `return i - m + 1` yerine bulunan indis kaydedilip aramaya devam edilirse bütün geçişler bulunur.

## Dersin Toparlaması

Bu derste substring arama problemi tanımlandı ve dört yaklaşım incelendi. Brute force her eşleşmemede bir kaydırır; basit ve doğrudur, ama en kötü durumda $O(MN)$'dir ve akan veride backup gerektirir. Horspool deseni sağdan sola tarar ve önceden kurulan bad match tablosuyla genellikle birden fazla karakter kaydırır. Ortalamada lineer, en iyi durumda sublineer ($n/m$) çalışır. Boyer-Moore buna good suffix tablosunu ekler ve iki önerinin büyüğü kadar kaydırır. Rabin-Karp ise karakterleri değil hash imzalarını karşılaştırır, kayan hash ile her pencereyi ucuza hesaplar ve yalnız hash eşleştiğinde birebir kontrol yapar. Dönemin son konusu olan bu algoritmalar arasındaki seçim; zaman, ek alan ve backup ihtiyacı arasındaki ödünleşime ve problemin ortamına göre yapılır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
