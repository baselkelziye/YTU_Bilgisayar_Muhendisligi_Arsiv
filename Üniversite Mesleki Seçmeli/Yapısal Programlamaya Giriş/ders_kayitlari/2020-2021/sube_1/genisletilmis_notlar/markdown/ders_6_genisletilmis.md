# Ders 6 Genişletilmiş Notu: Algoritma İyileştirme: Takas, Pisagor Üçlüleri, Sayı Üçgeni ve Palindromlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İki değişkenin değerlerini takas etmek
- 2. Toplamı 1000 olan Pisagor üçlüleri
- 3. Sayı üçgeninde bir satırın son elemanı
- 4. Bir diziyi ters çevirmek
- 5. Bir dizinin palindrom olup olmadığı
- 6. 6 ve 7 basamaklı palindrom sayılar
- 7. R basamaklı palindrom sayılarının adedi ve sabit sayıda işlem
- Örnek Sorular

Bu ders boyunca problemler akış diyagramlarıyla çözüldü. Her problemde önce çalışan bir "ham" çözüm kuruldu, ardından çözümün karmaşıklığı incelenip adım adım iyileştirildi. Hoca öğrencilere her problem için birkaç dakika düşünme süresi verdi ve çözümleri öğrencilerden aldı.

## 1. İki değişkenin değerlerini takas etmek

### 1.1 Problem ve yanlış ilk deneme

Bir $a$ değişkeninde 5, bir $b$ değişkeninde 3 olsun. İstenen, sonunda $b$'de 5, $a$'da 3 olmasıdır (ekrandan, 00:10:00). Bu klasik takas (swap) işlemidir.

İlk akla gelen `B = A` atamasıdır. Ama bu atama A'nın değerini doğrudan B'nin üzerine yazar ve B'nin eski değeri kaybolur. Artık B'nin eski değerini A'ya yazmak mümkün değildir, bu yüzden bu yol yanlıştır (tahtada üstü çizildi, ekrandan, 00:10:00).

### 1.2 Geçici değişkenle klasik çözüm

Hoca bunu iki kutu ve aralarında boş bir üçüncü kutu ile çizdi: (1) A'nın değeri boş kutuya taşınır, (2) artık A'nın üzerine yazılabileceği için B, A'ya taşınır, (3) boş kutudaki eski A değeri B'ye yazılır. Kod olarak (ekrandan, 00:15:00):

```text
temp = A
A = B
B = temp
```

### 1.3 Ek değişken kullanmadan takas

Hoca sordu: temp değişkeni kullanmadan, yani yeni bir yer açmadan, aynı takas yapılabilir mi? Bir öğrenci şu çözümü verdi (ekrandan, 00:15:00):

```text
b = a + b
a = b - a
b = b - a
```

Başka bir öğrenci sonucun $b = 2a$ gibi bir şey çıkıp çıkmayacağını sordu. Hoca bunu $a = 2$, $b = 4$ ile adım adım denedi:

- 1. adım: `b = a + b` → $a = 2$, $b = 6$. A değişmez, B'nin üstüne A eklenir.
- 2. adım: `a = b - a` → $a = 6 - 2 = 4$. B'den A çıkarılınca B'nin eski hali elde edilir.
- 3. adım: `b = b - a` → $b = 6 - 4 = 2$. Şimdiki B'den şimdiki A çıkarılınca A'nın eski hali elde edilir.

Sonuç $a = 4$, $b = 2$'dir; takas doğru çalışır, "iki katı" gibi bir sorun çıkmaz. Hoca bunun iş görüşmelerinde sorulan sorulardan biri olduğunu, daha önce görmeyen biri için ilk anda düşünmenin zor olabileceğini söyledi.

### 1.4 İki yöntemin karşılaştırılması

**Soru:** Hangisi daha iyi? **Cevap (öğrenci):** İkincisi daha az bellek kullanıyor ama daha fazla işlem yapıyor. Hoca bunu onayladı. İki yöntemde de üç atama vardır; ikinci yöntemde bunlara ek olarak üç aritmetik işlem (bir toplama, iki çıkarma) yapılır. Bu nedenle ikinci yöntem daha yavaştır, karşılığında bir değişkenlik bellek kazanılır. Değişkenler küçükse bu kazanç önemsizdir; ama her değişken megabaytlarca veri taşıyan yapılar (structure) ise ek bir alan kullanmadan takas yapmak daha çok işe yarayabilir.

## 2. Toplamı 1000 olan Pisagor üçlüleri

### 2.1 Problem

Tahtadaki problem (ekrandan, 00:30:00):

$$a + b + c = 1000, \qquad a^2 + b^2 = c^2, \qquad a, b, c > 0$$

$a, b, c$ (tam sayılar) neler olabilir?

### 2.2 Matematikle çözüm

Bir öğrenci problemi kendisi çözdü: özel dik üçgenlere baktı ve 8-15-17 üçgenini kullandı. Kenarlar $8k$, $15k$, $17k$ ise toplam $40k$'dır; $40k = 1000$ için $k = 25$ olur. Böylece üçlü 200, 375, 425 bulunur.

> **Ders sonrası not:** Altyazıda kenarlar "8K, 25K, 17K" diye geçiyor; bu ses tanıma hatasıdır. Doğrusu 8-15-17'dir: $8 + 15 + 17 = 40$ ve $200^2 + 375^2 = 40000 + 140625 = 180625 = 425^2$ (python ile kontrol edildi).

Hoca bu çözümü beğendi ama asıl sorunun "bilgisayara nasıl çözdürürüz" olduğunu hatırlattı.

### 2.3 Ham çözüm: üç iç içe döngü

Başka bir öğrenci "bulamasak da bilgisayar bulur, üç for döngüsü kurarız" dedi. Kullanıcıdan bir şey okumaya gerek yoktur, çünkü problem belirli sayılarla verilmiştir. Akış diyagramı (ekrandan, 00:30:00):

```text
START
for i = 1, 1, 1000
  for j = 1, 1, 1000
    for k = 1, 1, 1000
      eğer (i*i + j*j == k*k && i + j + k == 1000) ise
        yaz i, j, k
STOP
```

Hoca karede `a²` yerine `i*i` yazdığını belirtti. Bu program çalışır ve öğrencinin bulduğu çözümü bulur. Ama en içteki kontrolden $1000 \cdot 1000 \cdot 1000 = 10^9$, yani 1 milyar kez geçilir.

### 2.4 Karmaşıklık nereden ölçülür?

> **Hocanın vurgusu:** Bir algoritmanın ne kadar karmaşık olduğunu görmek için en içteki noktadan, yani en fazla geçilen yerden kaç kez geçildiğine bakmak gerekir. Dış döngülerin kutularına bakmak doğru sonucu vermez.

### 2.5 İlk öneriler

Hoca herkese birkaç dakika düşünme süresi verdi. Bir öğrenci karekök alınabilir mi diye sordu; hoca alınabileceğini söyledi. Gelen öneriler:

- Üç pozitif sayının toplamı 1000 olduğundan $i$ 1000 olamaz, 999'a, hatta 998'e kadar gitmesi yeter. Hoca bunun küçük ama geçerli bir iyileştirme olduğunu söyledi.
- $k$'yı $i$ ve $j$'nin büyüğünden başlatıp $i + j$'ye kadar götürmek. Hoca bunun da belli bir kazanç sağlayacağını söyledi.

### 2.6 Bir döngüyü tamamen kaldırmak

Bir öğrenci, emin olmadığını söyleyerek şunu önerdi: son for kaldırılsın, onun yerine $k = 1000 - i - j$ hesaplansın, sonra yalnız $i^2 + j^2 = k^2$ kontrol edilsin. Akış diyagramı (ekrandan, 00:45:00):

```text
START
for i = 1, 1, 1000
  for j = 1, 1, 1000
    k = 1000 - i - j
    eğer (i*i + j*j == k*k) ise
      yaz i, j, k
STOP
```

Bir öğrenci 3-4-5 üçgeninin bu yöntemle bulunamayacağını söyledi. Hoca, 3-4-5'in toplamı 1000 olmadığı için zaten bulunmaması gereken bir üçlü olduğunu açıkladı. Toplam koşulu kontrol edilecek yerde doğrudan sağlanmış olur, geriye yalnız Pisagor koşulu kalır.

**Soru (hoca):** Bu hızlandırıyor mu, ne kadar? **Cevap:** En içteki noktadan $1000 \cdot 1000 = 10^6$ kez geçilir. Önceki $10^9$ idi, yani algoritma 1000 kat hızlanmıştır.

### 2.7 $k$ negatif olabilir mi?

**Soru:** $k$ negatif olabildiği için koşulları bozabilir mi? Hoca durumu açtı: $i$ ve $j$'nin toplamı 1000'i aşınca $k$ negatif olur. Bir öğrenci if'e $k > 0$ koşulunun eklenebileceğini söyledi. Hoca daha hızlı bir yol istedi: $i$ ve $j$'nin ikisinin de 1000'e kadar gitmesi gerekmez. Öğrencilerle birlikte varılan sonuç: dış döngü 998'e, iç döngü $1000 - i$'ye kadar gider (ekrandan, 00:45:00).

Hoca iç döngünün aralığını şöyle yazdı (ekrandan, 00:45:00):

- $i = 1$ iken $j = 1..999$
- $i = 2$ iken $j = 1..998$
- ...
- $i = 998$ iken $j = 1..2$

Bu sınırlarla $k$ negatif olmaz. Bir öğrenci $j = 1000 - i$ olduğunda $k$'nın 0 olacağını, bu yüzden kendisinin $999 - i$ yazdığını söyledi; hoca bunun doğru olduğunu söyledi.

**Soru (hoca):** Bu değişiklik en içteki 1 milyon geçişi neye düşürür? Öğrencilerden "500.500" ve "500.000" cevapları geldi. Hoca yaklaşık 500 bine düştüğünü, yani kabaca 2 kat kazanç olduğunu söyledi. Bu, bir for'u tamamen kaldıran 1000 katlık iyileştirme kadar büyük değildir.

> **Ders sonrası not:** Dış döngü 998'e, iç döngü $1000 - i$'ye kadar gittiğinde tam geçiş sayısı $\sum_{i=1}^{998} (1000 - i) = 499499$'dur (python ile hesaplandı); derste söylenen "yaklaşık 500 bin" ile uyumludur.

### 2.8 Daha fazla iyileştirme ve matematiğin gücü

Bir öğrenci, $a$ ve $b$'nin $c$'den küçük olması gerektiği için sınırların 500'e indirilebileceğini önerdi. Hoca bunun 2 kat daha kazandıracağını, önceki iyileştirmeyle birlikte 4 kat edeceğini söyledi.

Hoca, sayıları kafadan bulan öğrenciye milyonlarca döngüye girip girmediğini sordu; öğrenci girmediğini söyledi. Hoca buradan genel bir ders çıkardı:

> **Hocanın vurgusu:** Önce problemin en ham çözümü kurulur. Sonra bu çözüm iteratif olarak iyileştirilir: problem incelenir, örüntüler (pattern) ve matematiksel özellikler görülür, çözüm indirgenir. En mükemmel hal, işi sabit sayıda işlemle yapmaktır; Gauss'un 1'den $n$'e kadar toplamı sabit sayıda işlemle bulması gibi. Önemli olan problemin üzerinde oturup düşünmektir.

## 3. Sayı üçgeninde bir satırın son elemanı

### 3.1 Problem

Tahtaya şu üçgen çizildi (ekrandan, 01:05:00):

```text
1. satır:  1
2. satır:  2  3
3. satır:  4  5  6
4. satır:  7  8  9  10
5. satır:  11 12 13 14 15
...
1000. satır: ?
```

Soru: 1000. satırın son elemanı kaçtır? (ekrandan, 01:05:00)

> **Ders sonrası not:** Derste bu üçgen için "Pascal üçgeni" adı geçti. Pascal üçgeni binom katsayılarından oluşur (her sayı üstteki iki sayının toplamıdır). Ardışık doğal sayılarla dolan bu üçgen genelde Floyd üçgeni diye bilinir.

### 3.2 Ham çözüm: iki iç içe döngü

Sayılar birer birer artar. $i$. satırda $i$ eleman vardır (ekrandan, 01:05:00): 2. satırda 2, 3. satırda 3 eleman. O halde her satırda sayaç $i$ kez artar. Hoca problemi genelleştirdi: kullanıcıdan $N$ alınsın, $N$. satırın son elemanı bulunsun. Akış diyagramı (ekrandan, 01:10:00):

```text
START
oku N
t = 0
for i = 1, 1, N          (satırlar)
  for j = 1, 1, i        (satır içindeki artışlar)
    t = t + 1
yaz t
STOP
```

Dış döngü satırları, iç döngü o satırın içindeki artışları tutar. $N$ satır bittiğinde $t$, $N$. satırın son elemanıdır.

Karmaşıklık: dış döngü $N$ kez döner, iç döngü ortalama $N/2$ kez döner. Bu yüzden en içteki noktadan yaklaşık $N \cdot N/2 = N^2/2$ kez geçilir (ekrandan, 01:10:00).

### 3.3 Öğrenci çözümleri

- Bir öğrenci while ile bir seri kurdu: her satırın son elemanı, önceki satırın son elemanına satır numarası eklenerek bulunur ($1 + 2 = 3$, $3 + 3 = 6$, $6 + 4 = 10$). Analiz ederken bir de $n \cdot (n+1)/2$ biçiminde doğrudan bir formül fark ettiğini söyledi ($3 \cdot 2 = 6$, $5 \cdot 3 = 15$).
- Başka bir öğrenci tek bir for ile çözdü: $x$ her adımda $i$ kadar artırılır, sonunda istenen sütun için düzeltme yapılır. Bu yöntem $N$ mertebesindedir.
- Bir öğrenci hiç döngüye gerek olmadığını söyledi: $n$. satırda $n$ eleman vardır ve değerler birer birer arttığı için Gauss toplamıyla doğrudan bulunur.

### 3.4 Döngüsüz çözüm

Hoca bu son fikri açtı: 4. satırın son elemanı $10 = 1 + 2 + 3 + 4$, 5. satırın son elemanı $15 = 1 + 2 + 3 + 4 + 5$'tir. O halde $N$. satırın son elemanı 1'den $N$'e kadar olan sayıların toplamıdır:

$$t = \frac{N(N+1)}{2}$$

$N = 1000$ için $t = 1000 \cdot 1001 / 2 = 500500$ (python ile kontrol edildi).

### 3.5 Karmaşıklıkların karşılaştırılması

İki döngülü çözüm $N^2/2$, tek döngülü çözüm $N$, formül ise sabit sayıda (yaklaşık 3) işlemdir.

> **Hocanın vurgusu:** Bir algoritmanın karmaşıklığını $N^2$'den $N$'e indirmek mükemmel bir şeydir: $N = 1000$ ise 1000 kat, $N$ bir milyon ise bir milyon kat kazanç sağlar. Sabit sayıya indirmek yapılabilecek en iyi şeydir, çünkü çözümün hızı $N$ büyüdükçe hiç değişmez.

Hoca yine aynı yöntemi vurguladı: önce sadece çözülür, sonra "daha iyi nasıl çözerim" diye düşünülür; içerideki örüntüler yakalandıkça karmaşıklık indirgenir.

## 4. Bir diziyi ters çevirmek

### 4.1 Hangi eleman hangisiyle değişir?

Problem: $N$ elemanlı bir diziyi ters çevirin (ekrandan, 01:20:00). Örnek: A B C D E dizisi E D C B A olmalıdır.

- 5 elemanlı dizide 1↔5 ve 2↔4 takas edilir; 3. eleman yerinde kalır.
- 4 elemanlı dizide 1↔4 ve 2↔3 takas edilir.
- 10 elemanlı dizide 1↔10, 2↔9, 3↔8, 4↔7, 5↔6 takas edilir (ekrandan, 01:20:00).

> **Ders sonrası not:** Derste 10 elemanlı örnek "2 ile 8, 3 ile 7, 4 ile 6, 5 ile 5" diye geçiyor ve tahtada da aynı satırlar yazılı (ekrandan, 01:20:00). Doğrusu $i \leftrightarrow 11 - i$ olduğundan 2↔9, 3↔8, 4↔7, 5↔6'dır.

Genel halde 1. eleman $N$. ile, 2. eleman $N-1$. ile, 3. eleman $N-2$. ile, 4. eleman $N-3$. ile değişir. **Soru (hoca):** Genel olarak $i$. eleman hangisiyle değişir? **Cevap (öğrenci):** $N - i + 1$. elemanla (ekrandan, 01:20:00). Bir öğrenci indis sıfırdan başlarsa $N - i$ olacağını söyledi; burada indisler 1'den başlatıldığı için $N - i + 1$ kullanıldı.

### 4.2 Akış diyagramı

Bir dizi okunmadan önce kullanıcıdan eleman sayısı $N$ okunur. Sonra tek bir değer değil bir dizi okunacağı için bir for açılır ve elemanlar tek tek okunur. Takas için temp kullanılır:

```text
START
oku N
for i = 1, 1, N
  oku A[i]
for i = 1, 1, N          (ilk hali; aşağıda düzeltildi)
  temp = A[i]
  A[i] = A[N-i+1]
  A[N-i+1] = temp
for i = 1, 1, N
  yaz A[i]
STOP
```

### 4.3 Döngü nerede durmalı?

Bir öğrenci, bu haliyle dizinin hiç değişmeyeceğini söyledi. Hoca 4 elemanlı örnekte denedi: 1 ile 4 değişir, 2 ile 3 değişir, sonra 3 ile 2 ve 4 ile 1 tekrar değişir; dizi başladığı haline döner. Bu yüzden takas döngüsü yarıya kadar gitmelidir: üst sınır $\lfloor N/2 \rfloor$ (alta yuvarlanmış $N/2$) olur.

**Soru:** Orada buçuklu bir değer olması sorun mu? **Cevap:** For döngülerindeki değerlerin tam sayı olması istenir, çünkü birer birer artırılır. $N/2$'ye kadar götürmek de çalışır ama tek $N$ için ortadaki elemanı kendisiyle takas etmek gereksiz bir işlemdir; bu yüzden alta yuvarlamak daha iyidir.

**Soru:** Akış diyagramında böyle yazabiliyor muyuz? **Cevap:** Alta yuvarlama $\lfloor \cdot \rfloor$, üste yuvarlama $\lceil \cdot \rceil$ biçiminde gösterilebilir.

**Soru:** Diziyi tek kutuda "$N$, $A_N$" diye okuyabilir miyiz? **Cevap:** Kod yazarken öyle okunamaz, elemanlar tek tek okunur; bu yüzden akış diyagramında da for ile gösterilmelidir. İleride matrisler (iki ve üç boyutlu diziler) iç içe iki üç for ile okunacağı için bunun farkında olmak önemlidir.

Derste C kodu yazılmadı. Aşağıdaki çeviri ajan tarafından yazıldı, `gcc -Wall` ile derlendi; 1 2 3 4 5 girdisi 5 4 3 2 1, 1 2 3 4 girdisi 4 3 2 1 verdi:

```c
#include <stdio.h>
int main(void) {
    int n, i, temp, a[100];
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (i = 1; i <= n / 2; i++) {
        temp = a[i];
        a[i] = a[n - i + 1];
        a[n - i + 1] = temp;
    }
    for (i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
```

## 5. Bir dizinin palindrom olup olmadığı

### 5.1 Palindrom nedir?

Palindrom, tersiyle aynı olan dizidir. Tahtadaki örnekler (ekrandan, 01:25:00): ALLA soldan sağa ve sağdan sola aynı okunur; 1441 de tersten 1441'dir. 144 ise palindrom değildir, çünkü tersi 441'dir. İstenen: kullanıcıdan bir A dizisi okuyup bu dizinin palindrom olup olmadığını söyleyen algoritma.

### 5.2 İlk fikir: ters kopya ile karşılaştırma

Önceki ters çevirme çözümü kullanılabilir: dizi ters çevrilip yeni bir diziye yazılır, sonra orijinal ile yeni dizi eleman eleman karşılaştırılır (tahtada A: 1 2 3 4 ve B: 4 3 2 1, ekrandan, 01:40:00). Maliyeti: ters kopyayı oluşturmak $N$, karşılaştırmak $N$; hoca tahtaya önce $N/2 + N \approx N$ yazdı, sonra kopyalamanın da $N$ olduğunu söyledi. $N$ ile $2N$ arasındaki fark bu açıdan kritik değildir.

### 5.3 Daha iyisi: kendi üzerinde kontrol

Yeni diziye gerek yoktur. 1. ile son, 2. ile sondan bir önceki eleman karşılaştırılır; böylece $N/2$ karşılaştırma yeter. Bir öğrenci de ilk yarı ile son yarının karşılaştırılmasının yeteceğini söyledi.

Karşılaştırma `A[i] == A[N-i+1]` biçimindedir. Doğru olduğu sürece sorun yoktur. Yanlış çıktığı anda dizinin palindrom olmadığı kesinleşir ve devam etmek boşunadır.

> **Hocanın vurgusu:** Herhangi bir anda çıkılması gereken bir döngüde for değil while kullanılır. For ile yapılırsa palindrom olmadığı belli olduktan sonra da boşu boşuna dönülür.

### 5.4 While ile akış diyagramı

Bir öğrenci bir bayrak değişkeni (ör. $k = 1$) tutmayı, uyuşmazlıkta bayrağı değiştirmeyi önerdi. Hoca bunun da olacağını söyledi ama koşulu doğrudan while'ın içine koymayı tercih etti (ekrandan, 01:40:00):

```text
START
oku N
for i = 1, 1, N
  oku A[i]
i = 1
while (A[i] == A[N-i+1] && i <= ⌊N/2⌋)
  i = i + 1
eğer (i < ⌊N/2⌋) ise
  yaz "değil"
değilse
  yaz "palindrom"
STOP
```

Tahtadaki iki ampersan (`&&`) "ve" anlamındadır. While'dan iki nedenle çıkılabilir: ya palindromluk şartı bozulmuştur ya da yarıya ulaşılmıştır. Hangisinin olduğunu ayırt etmek için bir öğrenci $i$'nin $\lfloor N/2 \rfloor$'den küçük olup olmadığına bakmayı önerdi: küçükse dizinin ortasına gelmeden çıkılmış demektir, yani dizi palindrom değildir.

> **Ders sonrası not:** Tahtadaki çıkış kontrolü `i < ⌊N/2⌋` biçimindedir. Uyuşmazlık tam $i = \lfloor N/2 \rfloor$'de bulunursa döngüden $i = \lfloor N/2 \rfloor$ ile çıkılır, kontrol yanlış döner ve dizi palindrom sanılır. Örnek: 1 2 3 1 ($N = 4$, $i = 2$'de 2 ≠ 3) ve 1 4 4 ($N = 3$, $i = 1$'de 1 ≠ 4). Tüm çiftler eşleştiğinde döngü $i = \lfloor N/2 \rfloor + 1$ ile biter. Bu yüzden doğru kontrol `i <= ⌊N/2⌋` ise "değil"dir. Ayrıca koşulda önce $i$ sınırının yazılması, sınır aşıldığında diziye erişilmemesini sağlar. Bunlar ajan tarafından python ve C ile denendi.

Düzeltilmiş halin C çevirisi (derste yazılmadı; ajan tarafından `gcc -Wall` ile derlendi ve 4 1 4 4 1 → palindrom, 3 1 4 4 → değil, 4 1 2 3 1 → değil, 3 1 2 1 → palindrom girdileriyle denendi):

```c
#include <stdio.h>
int main(void) {
    int n, i, a[100];
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    i = 1;
    while (i <= n / 2 && a[i] == a[n - i + 1])
        i = i + 1;
    if (i <= n / 2)
        printf("palindrom degil\n");
    else
        printf("palindrom\n");
    return 0;
}
```

### 5.5 Karmaşıklık

En içteki yapı while'ın gövdesidir. Ondan en kötü durumda $N/2$ kez geçilir; bir kez de geçilebilir (ilk çiftte uyuşmazlık varsa). **Soru:** Diziyi okumak karmaşıklığa sayılmıyor mu? **Cevap:** Sayılır. Okuma döngüsünden $N$ kez geçildiği için en çok geçilen yer orasıdır ve algoritmanın karmaşıklığı $N$ olarak değerlendirilir. Hoca $N$ ile $N/2$ (ya da $N$ ile $N - 5$) arasında ileride görülecek büyük farklar kadar korkunç bir fark olmadığını da ekledi.

Bir öğrenci tek sayıda basamağı olan (3, 5, 7 basamaklı) sayılarda palindrom olmadığını düşündü; hoca 121 örneğini verdi ve öğrenci yanıldığını kabul etti.

## 6. 6 ve 7 basamaklı palindrom sayılar

### 6.1 Problem ve ham çözüm

Problem: 6 basamaklı palindrom sayıları ekrana yazınız (ekrandan, 01:50:00). 6 basamaklı sayılar 100.000 ile 999.999 arasındadır. Kullanıcıdan bir şey okumaya gerek yoktur.

Burada elimizde bir dizi değil, tek bir sayı vardır (ör. $A = 123456$, ekrandan, 01:50:00). Basamaklara $a, b, c, d, e, f$ denirse $a$ ile $f$, $b$ ile $e$, $c$ ile $d$ karşılaştırılmalıdır. Bir öğrenci "A div 10000 ile A mod 10" önerdi; hoca elimizde div diye bir işlem olmadığını, bölme ve alta yuvarlama kullanılacağını söyledi. Basamaklar şöyle bulunur (ekrandan, 01:50:00):

- $a = \lfloor i / 100000 \rfloor$
- $b$: $\lfloor i / 10000 \rfloor \bmod 10$ (öğrenci önerisi; tahtada boş bırakıldı)
- ...
- $f = i \bmod 10$

Hoca bu ayrıntıyla vakit kaybetmemek için $b$, $c$, $d$, $e$'yi boş bıraktı. Akış diyagramı (ekrandan, 01:50:00 ve 02:00:00):

```text
START
t = 0
for i = 100000, 1, 999999
  a = ⌊i / 100000⌋
  b = ...
  c = ...
  ...
  f = i mod 10
  eğer a == f ise
    eğer b == e ise
      eğer c == d ise
        t = t + 1
        yaz i
yaz t
STOP
```

Arada eklenen `t = 0` ve `t = t + 1` sayesinde kaç tane palindrom sayı olduğu da bulunur (ekrandan, 02:00:00). Döngü içindeki işlemler sabit sayıdadır (bölme, mod, karşılaştırma); hoca bunları $K$ ile gösterdi. Döngü yaklaşık 900.000 kez döndüğünden maliyet $900.000 \cdot K$'dır (ekrandan, 01:50:00).

### 6.2 Kontrol etmek yerine üretmek

Bir öğrenci sayıları bulmak yerine üretmeyi önerdi: palindromun ilk üç basamağı seçilirse son üç basamak zaten belirlidir. Akış diyagramı (ekrandan, 02:10:00):

```text
START
for a = 1, 1, 9
  for b = 0, 1, 9
    for c = 0, 1, 9
      sayi = 100000*a + 10000*b + 1000*c + 100*c + 10*b + a
      yaz sayi
STOP
```

Başlangıçta yazılan `a = 1, b = 0, c = 0` atamaları döngüler zaten başlattığı için gereksizdir ve silindi. Bir öğrenci her yerde while kullandığını söyledi; hoca adım sayısı belli olduğunda for'un uygun olduğunu söyledi.

**Soru (hoca):** Karmaşıklık ne oldu? Öğrencilerden 899 ve 1000 cevapları geldi. Hoca en içteki noktaya bakmayı hatırlattı: $a$ 9, $b$ 10, $c$ 10 kez döner; en içten $9 \cdot 10 \cdot 10 = 900$ kez geçilir. Maliyet $900 \cdot K$'dır (ekrandan, 02:10:00), öncekinden çok daha iyidir. **Soru:** $K$ nereden geldi? **Cevap:** En içteki sabit sayıdaki işlemleri (bir çarpma, bir toplama, ...) temsil eder; $N$'e bağlı değildir.

Çözüm ajan tarafından C ile denendi: ilk üretilen sayılar 100001, 101101, 102201'dir ve toplam 900 sayı üretilir.

### 6.3 7 basamaklı palindromlar

**Soru (hoca):** 7 basamaklı palindromlar istenseydi ne yapardık? Bir öğrenci önce yeni değişkene gerek olmadığını, ortadaki rakamın önemi olmadığını söyledi. Hoca ortadaki rakamın nasıl üretileceğini sordu; öğrenci bir for daha gerektiğini, yani yeni değişkenin gerektiğini kabul etti. Akış diyagramı (ekrandan, 02:25:00):

```text
for a = 1, 1, 9
  for b = 0, 1, 9
    for c = 0, 1, 9
      for d = 0, 1, 9
        sayi = 1000000*a + 100000*b + 10000*c + 1000*d + 100*c + 10*b + a
        yaz sayi
```

Maliyet $9 \cdot 10 \cdot 10 \cdot 10 \cdot K = 9000 \cdot K$'dır (ekrandan, 02:25:00).

**Soru:** Dördüncü for yerine üç for kullanıp son döngüde $d$ için 10 işlemi elle yazsak daha iyi olmaz mı? **Cevap:** Karmaşıklık değişmez; içeride aynı işlem 10 kez tekrarlanacağı için oraya artık sabit sayıda işlem denemez.

## 7. R basamaklı palindrom sayılarının adedi ve sabit sayıda işlem

### 7.1 Problem ve örüntü

Problem: R basamaklı kaç adet palindrom sayı vardır? (ekrandan, 02:15:00). R kullanıcıdan alınır. Hoca öğrencilere üç dakika verdi ve küçük R değerlerinden tablo kurdu (ekrandan, 02:30:00):

| R | Adet |
|---|------|
| 1 | 9 |
| 2 | 9 |
| 3 | 90 |
| 4 | 90 |
| 5 | 900 |
| 6 | 900 |
| 7 | 9000 |
| 8 | 9000 |
| 9 | 90000 |

Bir öğrenci basamak sayısının yarısının üste yuvarlanmışından bir eksik kadar 10 ile 9'u çarpmayı önerdi; başka bir öğrenci $\lfloor (N-1)/2 \rfloor$ üssünü önerdi, hoca ikisinin de doğru olduğunu söyledi. Tahtadaki formül (ekrandan, 02:30:00):

$$R = N \;\Rightarrow\; 9 \cdot 10^{\lfloor (N-1)/2 \rfloor}$$

Tablo ve formül, R = 1..7 için tüm sayılar tek tek sayılarak python ile doğrulandı.

### 7.2 Değişken sayıda döngü kurulamaz

Hoca, analiz yapılmadan ilerlenseydi ne olacağını sordu. 7 basamak için dört iç içe döngü kurduk; ama kullanıcının girdiği R'ye göre "R şuysa şu kadar döngü olsun" diye değişken sayıda iç içe döngü oluşturulamaz.

Bunun yerine şöyle bir mantık kullanılabilir (ekrandan, 02:25:00): sayının yalnız ilk yarısı tek bir döngüyle üretilir. Örneğin 6 ve 7 basamak için $i = 100..999$ döner; önce $i$ yazdırılır, R tekse araya bir $j$ rakamı girer, sonra $i$'nin tersi yazdırılır. 8 ve 9 basamak için döngü 1000'den 9999'a gider. Döngünün başlangıç ve bitiş değerlerini R'ye göre dinamik olarak belirlemek zor değildir. Ama bu yol da sayıları tek tek dolaştığı için zaman alır.

### 7.3 Formülün karmaşıklığı

**Soru (hoca):** $9 \cdot 10^{\lfloor (R-1)/2 \rfloor}$ işleminin karmaşıklığı nedir, sabit mi? Bazı öğrenciler sabit dedi. Hoca $10^3$'ün tek işlemde hesaplanabileceğini, ama $10^n$'in genel olarak tek işlemde hesaplanamayacağını, düz yolla $n$ çarpma gerektiğini açıkladı. Yani işlem sayısı kullanıcının girdiği R'ye bağlıdır.

> **Hocanın vurgusu:** Sabit sayıda işlem, kullanıcının girdiği değere bağlı olmayan sayıda işlem demektir. Gauss formülü $n(n+1)/2$'de kullanıcı 10, 100, 1000 ya da 1 milyar girse de 3 işlem yapılır. Buna karşılık 100 elemanlı bir diziyi $n^2$ adımda sıralamak somut olarak 10.000 adım tutar ama bu algoritmayı sabit karmaşıklıklı yapmaz: kullanıcı 1000 elemanlı bir dizi girerse işlem sayısı değişir.

Bu formülün karmaşıklığı yaklaşık $N/2$'dir: 10, kendisiyle $N/2$ kez çarpılır. Hoca bunun önceki yöntemlere göre çok iyi olduğunu hatırlattı (ör. 9 basamak için 90.000, 8 basamak için 9000 işlem yerine).

Hoca son olarak ileride özyinelemeli (recursive) fonksiyonlar işlendiğinde $x^n$'in $\log_2 n$ adımda hesaplanabileceğinin görüleceğini söyledi. O zaman bu formül $N/2$ yerine $\log_2 (N/2)$ adımda hesaplanabilir.

> **Ek bilgi (derste anlatılmadı):** $x^n$'i logaritmik adımda hesaplamanın bilinen yolu "kare alarak üs alma"dır: $n$ çiftse $x^n = (x^{n/2})^2$, tekse $x^n = x \cdot x^{n-1}$ kullanılır. Her adımda üs yaklaşık yarıya indiği için çarpma sayısı $\log_2 n$ mertebesinde kalır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00 ve 00:15:00): $a = 5$, $b = 3$ iken iki değişkenin değerlerini, üçüncü bir değişken (temp) kullanmadan takas edin.

> **Çözüm (derste verildi):** `b = a + b; a = b - a; b = b - a`. $a = 5$, $b = 3$ için: $b = 5 + 3 = 8$; $a = 8 - 5 = 3$; $b = 8 - 3 = 5$. Sonuç $a = 3$, $b = 5$. Derste aynı adımlar $a = 2$, $b = 4$ ile gösterildi.

**Soru 2** (ekrandan, 00:30:00): $a + b + c = 1000$, $a^2 + b^2 = c^2$, $a, b, c > 0$ ise $a, b, c$ neler olabilir? Bilgisayara nasıl çözdürülür ve ham çözüm nasıl hızlandırılır?

> **Çözüm (derste verildi):** Tek üçlü 200, 375, 425'tir (8-15-17 üçgeninin 25 katı). Ham çözüm üç iç içe döngüdür ($10^9$ geçiş). Üçüncü döngü yerine $k = 1000 - i - j$ hesaplanınca $10^6$ geçişe (1000 kat), iç döngü $1000 - i$'ye kadar gidince yaklaşık $5 \cdot 10^5$ geçişe iner. Ajan tarafından C ile denendi: program yalnız (200, 375, 425) ve (375, 200, 425) satırlarını yazar.

**Soru 3** (ekrandan, 01:05:00): 1, 2 3, 4 5 6, 7 8 9 10, ... biçiminde dolan üçgende 1000. satırın son elemanı kaçtır?

> **Çözüm (derste verildi):** $N$. satırın son elemanı $1 + 2 + \dots + N = N(N+1)/2$'dir. $N = 1000$ için $1000 \cdot 1001 / 2 = 500500$.

**Soru 4** (ekrandan, 01:20:00): $N$ elemanlı bir diziyi ters çeviren algoritmayı yazın.

> **Çözüm (derste verildi):** $i = 1$'den $\lfloor N/2 \rfloor$'ye kadar `A[i]` ile `A[N-i+1]` takas edilir. Döngü $N$'e kadar giderse dizi eski haline döner.

**Soru 5** (ekrandan, 01:25:00): Bir dizinin palindrom olup olmadığını bulan algoritmayı yazın.

> **Çözüm (derste verildi, ders sonrası düzeltmeyle):** `i = 1`; `i <= ⌊N/2⌋` ve `A[i] == A[N-i+1]` olduğu sürece `i = i + 1`. Döngüden sonra `i <= ⌊N/2⌋` ise "palindrom değil", aksi halde "palindrom" yazılır. En kötü durumda $N/2$ karşılaştırma yapılır.

**Soru 6** (ekrandan, 01:50:00): 6 basamaklı palindrom sayıları ekrana yazınız. Aynısı 7 basamak için nasıl olur?

> **Çözüm (derste verildi):** $a = 1..9$, $b = 0..9$, $c = 0..9$ için `100000*a + 10000*b + 1000*c + 100*c + 10*b + a` yazdırılır; 900 sayı ($900 \cdot K$). 7 basamakta ortaya $d = 0..9$ döngüsü eklenir ve `1000000*a + 100000*b + 10000*c + 1000*d + 100*c + 10*b + a` yazdırılır; 9000 sayı ($9000 \cdot K$).

**Soru 7** (ekrandan, 02:15:00): R basamaklı kaç adet palindrom sayı vardır?

> **Çözüm (derste verildi):** $9 \cdot 10^{\lfloor (R-1)/2 \rfloor}$. Örneğin R = 6 için $9 \cdot 10^2 = 900$, R = 7 için $9 \cdot 10^3 = 9000$.

## Dersin Toparlaması

Bu derste tek bir düşünme biçimi birçok problem üzerinde uygulandı: önce problemi çalışan ama kaba bir yolla çözmek, sonra en içteki döngüye kaç kez girildiğine bakarak karmaşıklığı ölçmek ve problemin yapısını inceleyerek bu sayıyı azaltmak. Takas probleminde bellek ile işlem sayısı arasındaki denge görüldü. Pisagor üçlüsü probleminde bir döngüyü bir eşitlikle değiştirmek 1000 kat, döngü sınırlarını daraltmak birkaç kat kazanç sağladı. Sayı üçgeninde Gauss formülü $N^2/2$'lik çözümü sabit sayıda işleme indirdi.

Dizi problemlerinde ($i \leftrightarrow N - i + 1$ eşlemesi) döngünün $\lfloor N/2 \rfloor$'de durması gerektiği ve erken çıkılması gereken durumda while kullanılacağı görüldü. Palindrom sayılarında kontrol etmek yerine üretmek maliyeti 1000 kat azalttı; R basamaklı palindrom adedi ise bir örüntüden $9 \cdot 10^{\lfloor (R-1)/2 \rfloor}$ formülüne bağlandı. Sabit sayıda işlemin, girdiye bağlı olmayan işlem sayısı anlamına geldiği vurgulandı. $x^n$'in logaritmik adımda hesaplanması ise ileride özyinelemeli fonksiyonlar konusunda ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
