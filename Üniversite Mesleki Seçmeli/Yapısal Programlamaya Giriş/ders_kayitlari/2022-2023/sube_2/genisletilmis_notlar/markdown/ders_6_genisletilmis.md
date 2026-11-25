# Ders 6 Genişletilmiş Notu: Karşı Örnek Yöntemi, Takas, Diziler ve Palindrom Problemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önermeler ve asallık kontrolü
- 2. Eratosten kalburu: hız ile bellek arasındaki ödünleşim
- 3. Karşı örnek yöntemi
- 4. Takas (swap)
- 5. Mantıksal işlemler ve XOR ile takas
- 6. Pisagor üçlüsü: beş algoritmayla iyileştirme
- 7. Koşul sırası ve kısa devre
- 8. Sayı piramidi: karmaşıklık ve sonucun aynı çıkması
- 9. Neden dizi: en büyük k. sayı problemi
- 10. C'de diziler
- 11. En büyük 8. eleman ve sıralamanın maliyeti
- 12. Diziyi tersine çevirme ve yerinde (in-place) algoritmalar
- 13. Stringler ve palindrom kontrolü
- 14. 6 ve 7 basamaklı palindrom sayılar
- Örnek Sorular
- Dersin Toparlaması

## 1. Önermeler ve asallık kontrolü

Ders, önceki derste başlanan önerme sorusuyla açıldı. Bir **önerme**, sonucu ya doğru ya da yanlış olan matematiksel ya da mantıksal bir ifadedir. Önceki dersteki önerme şuydu: "Her pozitif doğal sayı $n$ için $n^2+n+41$ asaldır." Bu ifade $n$'ye bağlı olduğu için $P(n)$ diye yazılır ve ya doğrudur ya yanlıştır.

Bir önermenin doğruluğunu ispatlamak bazen çok zordur. Yanlışlığını kolayca gösterebiliyorsak bu da geçerli bir yoldur. Önceki derste bir öğrenci $n=41$ için ifadenin asal olmadığını söylemişti. Hoca $n=40$ için de bozulduğunu ekledi:

- $n=40$: $40^2+40+41 = 1600+40+41 = 1681 = 41^2$, asal değil.
- $n=41$: $41^2+41+41 = 1763 = 41\cdot 43$, asal değil.

Yani 1'den başlayıp 40'a ya da 41'e kadar denemek yetti; önerme yanlış çıktı ve daha fazla denemeye gerek kalmadı. Sonsuza kadar bütün $n$ değerlerini denemek yerine yanlışlığı göstermek çok daha basittir.

Bunun algoritması genel hâliyle şöyleydi: $n=1$'den "sonsuz" sayılabilecek bir sınıra kadar (örneğin C'deki `int` üst sınırı) gidilir, her $n$ için $p=n^2+n+41$ üretilir ve $p$'nin asal olup olmadığı kontrol edilir. Asallık kontrolü bir ara problemdir: 2'den başlanıp sayının bir eksiğine kadar bölen aranabilir. Ama bölen bulunur bulunmaz çıkmak gerektiği için `for` yerine `while` kullanılır. Ayrıca sayının bir eksiğine kadar gitmeye de gerek yoktur: bir sayının kendisinden küçük en büyük böleni en fazla yarısıdır, hatta kareköküne kadar bakmak yeter. Döngü sınırına kadar gidildiyse sayı asaldır; arada bir yerde çıkıldıysa asal değildir.

## 2. Eratosten kalburu: hız ile bellek arasındaki ödünleşim

Hoca asallık kontrolü için başka bir yöntem gösterdi: **Eratosten kalburu** (Sieve of Eratosthenes; "sieve" kalbur, elek demektir) (ekrandan, 00:10:00). Fikir şudur: bir sayının asal olup olmadığını anlamak için önce 2'ye bölünüp bölünmediğine bakılır; 2 dışındaki çift sayılar asal değildir. Bunu genişletirsek 2'den sonra yalnız asal sayılara bakmak yeter: 3, 5, 7, 11, ... 9'a bakmaya gerek yoktur, çünkü 3'e bakıldıysa 9 zaten elenmiştir.

Ekranda 2'den 100'e kadar sayıların yazıldığı bir tablo gösterildi. Önce 2'nin katları, sonra 3'ün katları, sonra sıradaki asalların katları karalandı. Sonunda 100 sayıdan çok azının asal kaldığı görüldü. Bu az sayıdaki asal bir dizide tutulursa sonraki kontroller hızlanır.

Hoca yöntemin kazancını ve bedelini şöyle özetledi:

- Kazandırdığı: hız. Zaman karmaşıklığı $n\log n$ düzeyine iner; basit yöntemde $n^2$ gibi bir değerden söz edilmişti.
- Kaybettirdiği: bellek. Asal olup olmadığı bilgisini tutan bir dizi gerekir; yardımcı bellek $O(n)$'e çıkar.
- Basit deneme yönteminde yalnız `n` ve `i` gibi bir iki değişken kullanılır; ek bellek $O(1)$'dir.

Gösterilen C kodunda dizi `memset` ile hazırlanıyor, sonra dizi üzerinden bir sayının asal olup olmadığı kontrol ediliyordu.

> **Ders sonrası not:** Hoca kalburun zaman karmaşıklığını $n\log n$ olarak verdi; Eratosten kalburunun bilinen karmaşıklığı büyük olasılıkla $O(n\log\log n)$'dir. Ana fikir değişmez: hız kazanılır, $O(n)$ bellek harcanır.

## 3. Karşı örnek yöntemi

### 3.1 Dört değişkenli önerme

İkinci soruda dört değişkenli bir önerme ele alındı (ekrandan, 00:20:00):

$$P(a,b,c,d):\ \neg\exists\, a,b,c,d\in\mathbb{N}^+,\quad a^4+b^4+c^4=d^4$$

Yani "pozitif doğal sayılarda $a^4+b^4+c^4=d^4$ denkleminin çözümü yoktur." Ekrandaki notta "1988'de yanlışlığı ispat edilmiş" yazıyor: denklemi sağlayan $a$, $b$, $c$, $d$ değerleri vardır. Böyle bir dörtlü varsa önermenin başındaki "değil" yüzünden önerme yanlış olur.

> **Ders sonrası not:** Hoca konuşurken "doğruluğu ispat edilmiş" dedi; ekrandaki not "yanlışlığı ispat edilmiş" diyor ve doğrusu budur. Büyük olasılıkla Noam Elkies'in 1988'de bulduğu karşı örnek kastediliyor. Bilinen en küçük karşı örnek $95800^4+217519^4+414560^4=422481^4$'tür (python ile doğrulandı).

### 3.2 Kaba kuvvet algoritması ve karmaşıklığı

Kullanıcıdan büyük bir $N$ sayısı alınır. $a$, $b$, $c$ ve $d$ için 1'den $N$'ye birer birer giden dört iç içe döngü kurulur; en içte $a^4+b^4+c^4=d^4$ kontrolü yapılır. Ekrandaki akış diyagramı şöyledir (ekrandan, 00:20:00):

```text
N oku
a = 1 .. N           -> bu döngü N kez döner
  b = 1 .. N         -> N^2 kez
    c = 1 .. N       -> N^3 kez
      d = 1 .. N     -> N^4 kez
        a^4 + b^4 + c^4 == d^4 ?
```

Hoca karmaşıklığı sordu; bir öğrenci $N^4$ dedi. Karşılaştırma bir birim işlem sayılırsa

$$T(N)=\sum_{a=1}^{N}\sum_{b=1}^{N}\sum_{c=1}^{N}\sum_{d=1}^{N}1 \approx N^4$$

olur: en içteki toplam $N$, bir dıştaki $N^2$, sonra $N^3$, sonra $N^4$.

Bu algoritmanın sorunu, örnek bulunsa bile bütün değerleri denemeye devam etmesidir; `break` de kullanılmadı. Bu yüzden `for` yerine `while` daha mantıklıdır (ekrandan, 00:25:00). Her `while` döngüsü 1'den başlatılır, "değişken $N$'den küçük olduğu sürece" diye devam eder; şartı bozan bir durum bulunduğunda bütün döngülerden çıkmayı sağlayan koşul `while` şartlarının içine yazılır.

### 3.3 Yöntemin adı ve mantığı

Hoca iki sorudaki yaklaşımın adını verdi: **karşı örnek yöntemi** (counter example method). Bu bir ispat tekniğidir. Dört tür iddia vardır: bir şeyin doğruluğu, varlığı, yanlışlığı ya da yokluğu. Bunlardan hangisini ispatlamak zorsa tersini ispatlamak daha kolay olabilir. Örneğin bir çözümün yokluğunu ispatlamak, bütün olasılıkları tek tek deneyip hiçbirinin olmadığını göstermeyi gerektirir. Bir çözümün varlığını göstermek ise tek bir örnek bulmakla biter; bu hem algoritmik olarak hem hız açısından büyük kolaylık sağlar. Önerme ya doğrudur ya yanlıştır; hangisi daha kolaysa o taraftan gidilir. Hoca konunun ayrık matematikte daha ayrıntılı inceleneceğini söyledi.

### 3.4 Çözümsüz bir örnek

Yöntemin işe yaramadığı durumlar da vardır. Ekrandaki önerme: "2 dışındaki her çift tam sayı iki asal sayının toplamıdır" (ekrandan, 00:25:00). Küçük sayılarla denendi:

- $4 = 2+2$
- $6 = 3+3$
- $8 = 5+3$
- $100$: hoca önce 31 ($100-31=69$, asal değil), 37 ($100-37=63$, asal değil) denedi. Bir öğrenci $97+3$'ü önerdi; hoca $41+59$'u da ekledi.

Örnekler buldukça önerme doğru gibi görünür. Ancak bu önermenin doğruluğu ya da yanlışlığı henüz bilinmiyor; çözülememiş problemlerden biridir. Belli bir sayıya kadar doğrulanmıştır ama genel ispat yoktur. Karşı örnek bulunursa yöntem işe yarar, ama şimdiye kadar bulunamamıştır.

> **Ek bilgi (derste anlatılmadı):** Bu önerme Goldbach sanısı olarak bilinir. Çok büyük sınırlara kadar bilgisayarla doğrulanmıştır ama ispatı ya da karşı örneği yoktur. 100'ün iki asalın toplamı olarak yazılışları $3+97$, $11+89$, $17+83$, $29+71$, $41+59$ ve $47+53$'tür (python ile bulundu).

## 4. Takas (swap)

### 4.1 Geçici değişkenle iki değişkenin takası

Yeni konu "3. hafta" başlığıyla açıldı. **Takas** (swap), bir değerin başka bir değerle yer değiştirmesidir ve çok sık kullanılır. Bilinen yöntem bir geçici değişken (`T`, temporary) kullanmaktır (ekrandan, 00:30:00):

```c
T = a;   /* a'yı yedekle */
a = b;
b = T;
```

### 4.2 Üç değişkenli döngüsel takas

Sonra şu soru soruldu: $a\leftarrow b$, $b\leftarrow c$, $c\leftarrow a$ olacak biçimde üç değişken nasıl takas edilir? Yani $a$'nın değeri $b$'ye, $b$'nin değeri $c$'ye, $c$'nin değeri $a$'ya geçecek (ekranda $a,b,c \Leftrightarrow b,c,a$ diye yazıldı). Python'da bu tek satırda yazılabilir, ama derste C ya da algoritma düzeyinde düşünülüyor.

Bir öğrenci `T=a` ile başlamayı önerdi. Hoca, ardından `b=a` gibi bir atama yapılırsa $b$'nin kaybolacağını gösterdi; buradaki kafa karışıklığı, oklu gösterimin program atamasıyla karıştırılmasından doğdu. Hoca açıkladı: gösterimdeki "a'yı b'ye aktar" ifadesi bir atama sırası değildir. Program gibi sırayla atanırsa ($a=3$ ise) $b$ de 3 olur, sonra $c$ de 3 olur, sonra $a$ da 3 olur.

Doğru çözüm öğrencilerle birlikte kuruldu (ekrandan, 00:40:00):

```text
T = a ile başlanırsa:     T = b ile başlanırsa:
  T = a                     T = b
  a = c                     b = a
  c = b                     a = c
  b = T                     c = T
```

Kural şudur: hangi değişken yedeklenirse, ona sonra değer veren değişken yazılır; sonra o değişkene değer veren yazılır ve zincir çapraz bir düzenle ilerler. En sonda yedek (`T`) yerine yazılır. Dört değişkende de aynı düzen geçerlidir. Önemli nokta, **tek bir geçici değişkenin yetmesidir**; ikincisine, üçüncüsüne gerek yoktur.

Maliyet: üç dört işlem olduğu için $T(N)=1$; tek ek değişken kullanıldığı için $S(N)=M(N)=1$ (space ya da memory karmaşıklığı) (ekrandan, 00:40:00).

## 5. Mantıksal işlemler ve XOR ile takas

### 5.1 Geçici değişkensiz takas

"Swap without temp variable", yani geçici değişken olmadan takas, matematiksel ve mantıksal manipülasyonlarla mümkündür. Önce ders notundaki örnek $a=2$, $b=4$ ile anlatıldı, sonra ekranda bir kod gösterildi (ekrandan, 00:35:00):

```c
int x = 10, y = 5;
// Code to swap 'x' and 'y'
x = x + y; // x now becomes 15
y = x - y; // y becomes 10
x = x - y; // x becomes 5
```

Bu yöntem ek bellek istemez. Hoca dezavantajları sordu. Öğrencilerin cevapları ve hocanın eklemeleri:

- Fazladan işlem yapılır.
- Çok büyük sayılar toplandığında `int` sınırı aşılır (overflow), sonuç yanlış olabilir.
- Kayan noktalı (floating point) sayılarda sorun çıkabilir; string'lerde (karakter dizileri) bu yöntem hiç uygulanamaz.

Aynı kodun çarpma-bölme sürümü de vardır: `x = x * y;` (x 50 olur), `y = x / y;` (y 10 olur), `x = x / y;` (ekrandan, 00:35:00). Burada da çarpım `int` sınırını aşabilir.

### 5.2 Mantıksal işlemler

Üçüncü sürüm XOR'dur. Bunu anlatmak için hoca mantıksal işlemleri hatırlattı (ekrandan, 00:40:00):

- **AND** (C'de `&&`): $x$ ve $y$ önermelerinin ikisi de doğruysa sonuç doğrudur. Bir üçüncüsü eklenirse (`x && y && z`) üçü de doğru olmalıdır. En az biri yanlışsa sonuç yanlıştır.
- **OR** (C'de `||`): en az biri doğruysa sonuç doğrudur.
- **NOT**: değili alır.
- **XOR**: iki girişten yalnız ve yalnız biri doğruysa sonuç doğrudur; ikisi de doğru ya da ikisi de yanlışsa sonuç yanlıştır.

XOR doğruluk tablosu:

| $x$ | $y$ | $x \oplus y$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

Küme diyagramında XOR, iki kümenin kesişimi dışında kalan kısımlarıdır.

Bit düzeyinde (bitwise) XOR karşılıklı bitlere uygulanır: bitler aynıysa 0, farklıysa 1. Tahtadaki örnek: $3 = 011$, $5 = 101$, $3\oplus5 = 110$.

> **Ders sonrası not:** Tahtada $3\oplus5$ sonucu `110` olarak doğru bulundu ama karşısına 8 yazıldı ve "toplamaya denk geldi" denildi. `110` ikilik sayısı $4+2=6$'dır; $3+5=8$ ile aynı değildir (gcc ile `3^5` = 6 doğrulandı).

### 5.3 XOR ile takas

Ekrandaki kodda `x = x ^ y; y = x ^ y; x = x ^ y;` uygulanır. $10 = 1010$, $5 = 0101$:

- `x = x ^ y` → $1010\oplus0101 = 1111 = 15$. Bu değerin toplamla (15) aynı çıkması tesadüftür; her zaman böyle olmaz.
- `y = x ^ y` → $1111\oplus0101 = 1010 = 10$.
- `x = x ^ y` → $1111\oplus1010 = 0101 = 5$.

Takas tamamlanır (gcc ile doğrulandı: x=5, y=10). Hoca bu yöntemin tek sıkıntısının $x$ ile $y$'nin aynı olması olduğunu söyledi ve 5 ile 5'i denedi: $101\oplus101=000$, sonra $000\oplus101=101$, sonra $101\oplus000=101$. Sonuç doğru çıktı; hoca bu durumda takasın anlamsız, gereksiz işlem olduğunu belirtti.

> **Ders sonrası not:** XOR takası, değerleri eşit iki ayrı değişkende doğru çalışır (derste de böyle çıktı). Büyük olasılıkla asıl tehlikeli durum iki işaretçinin aynı bellek gözünü göstermesidir: `*p ^= *q` ilk adımda değeri 0 yapar ve değer kaybolur (gcc ile denendi, sonuç 0).

Hoca bu tür takas kodlarının çoktan seçmeli sınav sorusu olarak sorulabileceğini söyledi: bir kod parçası verilir ve sonunda $x$ ile $y$'nin değeri sorulur.

## 6. Pisagor üçlüsü: beş algoritmayla iyileştirme

### 6.1 Problem

Soru: $a+b+c=1000$, $a^2+b^2=c^2$, $a,b,c>0$ koşullarını sağlayan bütün $(a,b,c)$ üçlülerini ekrana yazdırın (ekrandan, 00:45:00). Hoca bunun bir varlık problemi olmadığını vurguladı: "bir tane var mı" değil, "hepsini listele" isteniyor. Bu yüzden bütün durumlar denenmelidir.

### 6.2 Algoritma 1: üç iç içe döngü

İlk akla gelen çözüm, $a$, $b$, $c$ için 1'den 1000'e üç döngü ve bir `if`'tir (ekrandan, 00:45:00 ve 00:50:00):

```c
for (a = 1; a <= 1000; a++) {
    for (b = 1; b <= 1000; b++) {
        for (c = 1; c <= 1000; c++) {
            t = t + 1;
            if ((a+b+c == 1000) && (a*a + b*b == c*c)) {
                count++;
                printf("%d %d %d\n", a, b, c);
            }
        }
    }
}
printf("Alg1: %d step, %d triplet\n", t, count);
```

"Virgül" ile verilen koşullar "ve" anlamı taşıdığı için `&&` ile birleştirildi. Toplama işleminin önceliği karşılaştırmadan yüksek olduğu için parantez zorunlu değil, ama okunurluk için iki koşul parantez içine alındı. Adım sayısını görmek için `t` sayacı, üçlü sayısı için `count` eklendi. Bulunan üçlüler (200, 375, 425) ve (375, 200, 425)'tir; adım sayısı $1000^3=10^9$'dur ($N^3$).

**Soru:** Bir öğrenci kodun aynı sayıların farklı sıralarını da bulduğunu söyledi. **Cevap:** Burada sıralı üçlüler aranıyor; $3^2+4^2=5^2$ ile $4^2+3^2=5^2$ ayrı durumlardır, permütasyon gibi düşünülür. $a$, $b$, $c$ ayrı değişkenler olduğu için bütün durumlar kontrol edilir.

**Soru:** Gereksiz ne yapılıyor? **Cevap (bir öğrenci):** $a$, $b$, $c$ 1000'e yaklaştığında toplamları 3000'e kadar çıkıyor; $a$ ve $b$ 1000 olduğunda kural zaten bozulmuş durumda.

### 6.3 Algoritma 2: üçüncü döngüyü kaldırmak

$a+b+c=1000$ eşitliğinden $c = 1000-a-b$ yazılırsa $c$ için döngüye gerek kalmaz. Karmaşıklık $N^3$'ten $N^2$'ye iner: $10^6$ karşılaştırma ile aynı sonuç bulunur. Hoca birinci algoritmanın çalışmasının (ekrana yazdırma dahil) uzun sürdüğünü, ikincisinin çok daha hızlı bittiğini gösterdi.

### 6.4 Algoritma 3: b'nin sınırını daraltmak

$a$ 1'den 1000'e giderken $b$'nin de 1000'e gitmesi gerekmez; toplam 1000'i geçmemeli. `b <= 1000 - a` yazılırsa $a+b$ hiçbir zaman 1000'i geçmez (ekrandan, 00:55:00):

```c
for (a = 1; a <= 1000; a++) {
    for (b = 1; b <= 1000 - a; b++) {
        c = 1000 - a - b;
        t = t + 1;
        if (a*a + b*b == c*c) { ... }
    }
}
```

Adım sayısı yaklaşık yarıya iner: 499.500.

**Soru:** Bir öğrenci, $c$ artık $1000-a-b$ ile hesaplandığı için `if` içinde toplamın 1000'e eşit olup olmadığına bakmaya gerek olmadığını söyledi. **Cevap:** Doğru; toplam her zaman 1000 olduğu için o koşul kaldırıldı.

**Soru:** $c$ negatif olabilir mi? **Cevap:** Hoca önce negatif durumların olabileceğini ve $a,b,c>0$ kontrolü gerekebileceğini düşündü; öğrencilerle birlikte bakılınca, `b <= 1000 - a` sınırıyla $c$'nin en az 0 olduğu, yani negatif olmadığı görüldü. Gereksiz şart kaldırıldı.

### 6.5 Algoritma 4: a'yı 500'e kadar çevirmek

Toplam 1000 ise $a$'nın 1000'e kadar gitmesi gerekmez; 500'e kadar gitmesi yeter. $b$ ise $500-a$'dan başlatılır ve en fazla 499'a gider (ekrandan, 01:05:00):

```c
for (a = 1; a < 500; a++) {
    for (b = 500 - a; b < 500; b++) {
        c = 1000 - a - b;
        t = t + 1;
        if (a*a + b*b == c*c) {
            count++;
            printf("%d %d %d\n", a, b, c);
        }
    }
}
printf("Alg4: %d step, %d triplet\n", t, count);
```

İlk denemede `500 0 500` diye fazladan bir sonuç çıktı: $a$ ve $b$ toplamı 1000'e ulaşınca $c$ sıfır oluyordu. Hâlbuki $c>0$ isteniyordu; kod düzeltildi ve ekrandaki son hâlde iki döngü de `< 500` ile sınırlıdır. Adım sayısı 124.750'ye indi (hoca "125.000'e kadar getirdik" dedi).

### 6.6 Algoritma 5: c'nin en büyük olduğunu kullanmak

Aradan sonra öğrencilerden bir öneri geldi: $a^2+b^2=c^2$ olduğu için $c$ üçünün en büyüğüdür; toplam 1000 olduğuna göre $c$ en az 333 olmalıdır. Bir öğrenci dış döngünün $c$'ye göre yazılmasını önerdi. Hoca, $c$'nin en büyük değer olması ve toplamın 1000 olması yüzünden $c$'nin en az yaklaşık 333 olacağını, üstten de 500 ile sınırlanabileceğini açıkladı (ekrandan, 01:15:00):

```c
for (c = 333; c < 500; c++) {
    for (b = 1; b < 500; b++) {
        a = 1000 - c - b;
        t = t + 1;
        if (a*a + b*b == c*c) {
            count++;
            printf("%d %d %d\n", a, b, c);
        }
    }
}
printf("\n%d\n", a+b+c);
```

Adım sayısı 83.333'tür (gcc ile doğrulandı). Döngü bittikten sonra `a+b+c` yazdırılınca 1002 çıktı. Hoca bunun nedeninin döngü değişkenlerinin son değerleri olduğunu söyledi: döngüler bittiğinde `c=500` ve `b=500` olur, `a` ise son geçerli değeri olan $1000-499-499=2$'de kalır; $2+500+500=1002$.

**Soru:** $a$ ve $b$ 250 olursa $a^2+b^2$, $500^2$'den büyük olabilir mi? **Cevap:** Analitik olarak yazıldı: $a=b=x=250$ ve $c=y=500=2x$ olsaydı $2x^2 = 4x^2$ olması gerekirdi; böyle bir eşitlik olmaz. Hoca bunun üçgen eşitsizliğinden de çıktığını söyledi.

> **Hocanın vurgusu:** Matematik zorlandıkça algoritma iyi yerlere gider; $10^9$ adımlık ilk çözüm, aynı sonucu veren 83.333 adımlık bir çözüme indi. Bu iş matematikten ayrı düşünülmemelidir.

Beş algoritmanın tamamı tek programda gcc ile derlenip çalıştırıldı. Çıktı: Alg1 $10^9$ adım, Alg2 $10^6$, Alg3 499.500, Alg4 124.750, Alg5 83.333; hepsinde 2 üçlü.

## 7. Koşul sırası ve kısa devre

Hoca 1. algoritmaya bir ekleme yaptı. `if` içinde önce `a+b+c == 1000` koşulu yazılırsa kod daha hızlı biter. Nedeni `&&`'in **kısa devre** yapmasıdır: ilk koşul yanlışsa ikincisine hiç bakılmaz. Toplam koşulu çoğu zaman yanlış olduğu için çarpma içeren ikinci koşul çoğu zaman hiç hesaplanmaz.

`||` için tersi geçerlidir: ilk koşul doğruysa diğerlerine bakılmaz. Kural:

- `&&` ile bağlanan koşullarda yanlış olma olasılığı yüksek olan koşul öne yazılır.
- `||` ile bağlanan koşullarda doğru olma olasılığı yüksek olan koşul öne yazılır.
- Karmaşık, iç içe yapılarda daha farklı düşünmek gerekir.

Hoca bu yaklaşımın dizilerde çok kullanılacağını söyledi.

**Soru:** Bu tür bilgileri öğrenmek için kaynak önerisi var mı? **Cevap:** Hoca kitapları önerdi: "Problem Solving and Program Design in C" kitabı (hoca yazarı "Kaufman" diye andı; büyük olasılıkla Hanly ve Koffman'ın kitabı); Herbert Schildt'in C'nin tam referansı olan kitabı; C dilini yazanların kendi kitabı; ayrıca Linux üzerinde C kütüphaneleri hakkında bilgi veren bir kitap <!-- BELİRSİZ: bu kitabın adı altyazıda anlaşılmıyor ("Ben bir geciz C"). -->. Akademik ve kitap tarzı kaynaklar dağınık tutorial sayfalarından daha güvenilirdir.

## 8. Sayı piramidi: karmaşıklık ve sonucun aynı çıkması

Soru: Aşağıdaki üçgenin 1000. satırının son elemanı kaçtır (ekrandan, 01:25:00 ve 01:30:00)?

```text
      1
     2 3
    4 5 6
   7 8 9 10
 11 12 13 14 15
   ...
```

Beşinci satırın son elemanı 15'tir. Bir öğrenci satır sonlarına bakınca artışın düzenli olduğunu fark etti: $0\to1\to3\to6\to10\to15$, artışlar 1, 2, 3, 4, 5. Hoca önce algoritmik çözümü, sonra formülü göstermek istedi.

Algoritmik çözümde dış döngü satır numarasını, iç döngü o satırdaki eleman sayısını gezer; her adımda bir sayaç artırılır:

```c
t = 0;
for (i = 1; i <= 1000; i++)
    for (j = 1; j <= i; j++)
        t = t + 1;
printf("%d", t);
```

Karmaşıklık:

$$\sum_{i=1}^{N}\sum_{j=1}^{i}1=\sum_{i=1}^{N} i=\frac{N(N+1)}{2}\approx\frac{N^2}{2}$$

Burada ilginç olan, `t` sayacı birer birer arttığı için **karmaşıklık ile sonucun aynı olmasıdır**: $t = \frac{1000\cdot1001}{2} = 500500$. Arada başka bir `if` olsaydı bu toplam yalnız karmaşıklığı verirdi; birer artan sayaç olduğu için ulaşılan değeri de verdi. Kod derste yazılıp çalıştırıldı ve 500500 bulundu (bu not için gcc ile de doğrulandı).

Formülle çözüm: $n$. satırın son elemanı $\frac{n(n+1)}{2}$'dir. Bir çarpma, bir toplama ve bir bölme; üç işlemle, yani sabit karmaşıklıkla sonuç bulunur. $N^2$'lik karmaşıklık 1'e indi.

## 9. Neden dizi: en büyük k. sayı problemi

Şimdiye kadar çözülen bütün problemlerde bellek karmaşıklığı $O(1)$'di; birkaç değişken yetiyordu. Hoca bunun bir yerden sonra yetmediğini bir soruyla gösterdi.

**En büyük sayı:** $n$ sayı okunurken bir `max` değişkeni tutulur; okunan sayı `max`'tan büyükse `max` güncellenir.

**En büyük ikinci sayı:** Bir öğrenci, yeni en büyük geldiğinde eski en büyüğün ikinci bir değişkene atanmasını önerdi. Kod şöyle kuruldu:

```c
for (i = 0; i < n; i++) {
    scanf("%d", &sayi);
    if (sayi > max) {
        max2 = max;
        max = sayi;
    } else if (sayi > max2) {
        max2 = sayi;
    }
}
```

`max` ve `max2` başta sıfırlanır. Sayı `max`'tan büyükse eski `max` ikinciye kayar; `max`'tan küçük ama `max2`'den büyükse yalnız `max2` güncellenir; ikisi de değilse sayı ilgilendirmez.

**En büyük üçüncü, altıncı sayı:** Üçüncü değişken, yeni `if`'ler gelir; altıncı için altı değişken ve bir sürü `if` gerekir. Kod yazmanın anlamı kalmaz, elle yapmak daha hızlı olur. Sorun şudur: sayı bir değişkende tutulur, sonra yeni sayı gelince eskisi uçar gider. Problem büyüdükçe çözümsüz hâle gelir.

Çözüm: **veriler bellekte saklanmalıdır**, mümkünse ardışık olarak. Bu iş için kullanılan yapılara **veri yapısı** (data structure) denir; en bilineni **dizidir** (array). Dizi, belleğin fiziksel yapısına doğrudan uygundur: bellek de bir dizi gibidir. 4 GB bellek $2^{32}$ bayttır ($2^{30}$ giga, $2^2=4$); adresler 0'dan $2^{32}-1$'e kadar birer birer artan hücrelerdir ve her hücrede 1 bayt (8 bit) saklanır.

> **Hocanın vurgusu:** Algoritmanın üç temel işlemi (sıralı, şartlı, tekrarlı işlem) bu tür problemleri çözmeye yetmedi. Programlama dilinin sunduğu kolaylıkları, burada diziyi, kullanmak gerekir. Ayrıca bu derste C++ ile ilgilenilmemeli; C++ sayfalarındaki örnekleri çözmek faydalı olsa da sözdizimi karıştırılmamalı, çözümler standart C ile yazılmalıdır.

## 10. C'de diziler

### 10.1 Tanım ve indis

Dizi `int array[MAX];` biçiminde tanımlanır. Hoca boyutun doğrudan yazılmamasını, `#define MAX 15` gibi bir makroyla verilmesini önerdi.

**Soru:** $n$ elemanlı dizi tanımlanabilir mi (boyut değişken olarak)? **Cevap:** Bu şekilde tanımlanamaz; bu ileride başka bir yolla görülecek. Şimdilik sabit boyutlu diziler yeterlidir.

Elemanlar `array[0]`, `array[1]`, `array[2]`, ..., `array[MAX-1]`'dir; 0, 1, ..., MAX-1 sayılarına **indis** (index) denir (ekrandan, 01:45:00). Bu yüzden dizilere **indisli değişkenler** de denir: değişkene benzerler ama indisleri vardır.

### 10.2 Sınırlar ve sorumluluk

Normal şartlarda derleyici ve işletim sistemi `MAX` elemanlık yeri ayırır. C diline özel bir durum olarak `MAX`, `MAX+1` gibi sınır dışı indislere erişmeye çalışılabilir; sistem bazen engellemez, bazen engeller. C sorumluluğu programcıya bırakır: nereye erişileceğini kendin hesapla, hata yaparsan sonucuna sen katlanırsın.

> **Hocanın vurgusu:** Sınır dışı erişim içeren bir kod kendi bilgisayarınızda çalışsa bile başka bir bilgisayarda büyük olasılıkla çalışmaz. Erişim 0 ile `MAX-1` arasında kalmalıdır.

### 10.3 Dizinin yazdırılması ve başlatılması

Ekrandaki ArrayIntro programı (ekrandan, 01:45:00):

```c
for (i = 0; i < MAX; i++) {
    printf("Array[%d] -- %d\n", i, array[i]);
}
```

Döngü koşulu `i < MAX`'tır; `<=` yazılmaz. Çalıştırınca elemanların bir kısmında anlamsız değerler, bir kısmında 0 görüldü.

**Soru:** Neden bazı elemanlarda garip değerler, bazılarında sıfır var? **Cevap:** C, temizlik işini de programcıya bırakır. Dizi kullanılmadan önce temiz olsun isteniyorsa programcı temizlemelidir. En basit yol ilk değer vermektir (initialization): `int array[MAX] = {0};` yazılırsa bütün elemanlar sıfır olur. `= {1}` yazılırsa bütün elemanlar 1 olmaz; yalnız ilk eleman 1, kalanlar 0 olur. Yani ilk eleman sıfırlanırsa diğerleri derleyici tarafından otomatik sıfırlanır.

> **Hocanın vurgusu:** Özellikle sayısal hesaplarda dizi sıfırlanmazsa matematiksel olarak beklenen sonuçlar görülmez.

Bundan sonra dizi elemanı sıradan bir değişken gibi kullanılır: toplanır, çıkarılır, çarpılır. Örneğin `array[i] = i * i;` ile elemanlara indislerinin karesi yazıldı.

### 10.4 Adresler ve bitişiklik

`printf` içinde işaretçi biçimi `%p` ile `&array[i]` yazdırılınca her elemanın bellekte oturduğu adres 16'lık tabanda görüldü. `&` (ampersand) bir şeyin adresini verir; `scanf`'te bu yüzden kullanılır. Ekrandaki örnekte ilk eleman `...62FDD0` adresindeydi ve sonraki her eleman 4 ileride duruyordu. Çünkü her `int` 4 bayttır; dizi toplam $4\times$ eleman sayısı kadar yer kaplar.

Dizi elemanları bellekte mutlaka **ardışık** (bitişik, contiguous) olmalıdır; aksi hâlde indisle gezen `for` döngüsü doğru çalışmaz. Matrisler de böyledir: önce birinci satır, hemen arkasından ikinci satır, ... uç uca eklenmiş diziler gibi saklanır.

Okuma `scanf("%d", &array[i]);` ile yapılır; `array[i]` bir değişken olduğu için `&` gerekir. Veri okuma, veriye erişme ve veriyi yazdırma dizilerdeki üç temel işlemdir; gerisi diğer değişkenlerle aynıdır.

## 11. En büyük 8. eleman ve sıralamanın maliyeti

Dizi ile en büyük $k$. sayı problemi programlama açısından kolaylaşır (ekrandan, 01:50:00):

```text
N sayıdan en büyük 8.'si:
  1. Önce N sayıyı diziye kaydet (for döngüsüyle N sayı oku).
  2. Diziyi artan şekilde sırala.
  3. Dizinin uygun elemanını ekrana yaz.
```

İlk yazılışta "dizinin 7 indisli elemanını yaz" denildi. **Soru:** Bir öğrenci azalan sıralamak gerekmez mi diye sordu. **Cevap:** Artan sıralamada 7 indisli eleman en küçük 8.'sidir; ya azalan sıralanmalı ya da başka bir eleman okunmalıdır. **Soru:** Sıralamayı değiştirmeden en büyük 8.'yi nasıl buluruz? **Cevap (bir öğrenci):** $N-8$ indisli eleman alınır; artan sıralı dizide sondan 8. eleman en büyük 8.'dir.

Maliyet analizi: sayıları diziye okumak zaten kaçınılmazdır, bu yüzden hesaba katılmadı. Dizinin belli bir elemanına erişmek (dizinin 3.'sü, 8.'si, $i$.'si) tek adımlık bir işlemdir; bu dizilerin büyük kolaylığıdır. Maliyeti sıralama belirler:

- Bubble sort, insertion sort, selection sort gibi daha ilkel algoritmalar $N^2$'dir.
- Quick sort ve merge sort gibi algoritmalar $N\log N$'ye iner (ileride görülecek).
- Toplam maliyet en iyi durumda $N\log N + 1 \approx N\log N$'dir.

## 12. Diziyi tersine çevirme ve yerinde (in-place) algoritmalar

### 12.1 İkinci diziyle tersleme

Soru: $n$ elemanlı bir diziyi tersine çevirin. Örnek $n=5$: indisler 0..4, değerler 1, 2, 3, 4, 5; istenen 5, 4, 3, 2, 1.

Hoca önce bazı kitaplarda (kelime ters çevirmede de) görülen en ilkel yolu anlattı: aynı boyutta ikinci bir dizi açılır, birinci dizi tersten taranıp ikinciye kopyalanır:

```c
for (i = 0; i < n; i++)
    d2[i] = d1[n - i - 1];
```

İndis $n-i$ değil $n-i-1$'dir, çünkü son eleman $n-1$ indislidir ($n=5$ için 4). Bu çözüm $T(N)=N$'dir ama $S(N)=M(N)=N$'dir: işlem yapılırken bellekte ayrıca $N$ eleman yer tutuldu, bellek kötü kullanıldı.

### 12.2 In-place özelliği

Bir problemi çözerken ek yere ihtiyaç duyulup duyulmadığına **yerinde** (in-place) özellik denir. Hoca Wikipedia'daki sıralama algoritmaları tablosunu açtı: normal merge sort ve yerinde sıralama yapan in-place merge sort ayrı ayrı listeleniyordu; quick sort, block sort, cycle sort ve MSD radix sort'un yerinde sürümleri gösterildi. Yerinde sıralama, diziyi sıralarken başka bir diziye taşımamak, en fazla bir geçici (takas) değişkeniyle işi bitirmek demektir. İkinci dizili tersleme bu yüzden "not in place"tir.

### 12.3 Yerinde tersleme

Bir öğrencinin daha önce önerdiği gibi takas kullanılır: 0 ile 4, 1 ile 3, 2 ile 2 takas edilir. Soldaki indis $i$ ise sağdaki $n-i-1$'dir ve ikisi en fazla birbirine eşit olabilir; eşit olduklarında durulur (ekrandan, 02:00:00):

```c
i = 0;
while (i < n / 2) {
    t = d[i];
    d[i] = d[n - i - 1];
    d[n - i - 1] = t;
    i++;
}
```

Hoca önce döngünün $n$'ye kadar gittiği yanlış sürümü izledi:

| $i$ | Takas edilenler | Dizi |
|---|---|---|
| 0 | d[0]=1 ile d[4]=5 | 5 2 3 4 1 |
| 1 | d[1]=2 ile d[3]=4 | 5 4 3 2 1 |
| 2 | d[2]=3 ile d[2]=3 | 5 4 3 2 1 |
| 3 | d[3]=2 ile d[1]=4 | 5 2 3 4 1 |
| 4 | d[4]=1 ile d[0]=5 | 1 2 3 4 5 |

Dizi tekrar orijinal hâline döndü. Bu yüzden döngü tam ortada, $n/2$'de durdurulmalıdır; o zaman sonuç 5, 4, 3, 2, 1 olur. Aynı kod `for (i = 0; i < n/2; i++)` ile de yazılabilir.

Karmaşıklık: takas 3 işlemdir ve $n/2$ kez yapılır, yani yaklaşık $\frac{3N}{2}$; büyük resimde yine $T(N)\approx N$. Bellek ise $S(N)=M(N)=1$'dir, çünkü yalnız bir geçici değişken kullanılır. Yerinde tersleme bellekten kayıp oluşturmadı.

Döngü gövdesi bir `main` içine konup `{1,2,3,4,5}` dizisiyle gcc'de derlendi; çıktı `5 4 3 2 1` oldu.

## 13. Stringler ve palindrom kontrolü

### 13.1 String okuma

Aradan sonra aynı fikir string üzerinde uygulandı. C'de string bir **karakter dizisidir**: `char str[MAX];`. Okuma `scanf("%s", str);` ile yapılır ve `&` kullanılmaz. Bu normal kuralın istisnasıdır: dizi adı (etiketi) kullanıldığında aslında dizinin adresi verilmiş olur; işaretçiler konusunda bu ayrıntılı konuşulacak. `scanf` klavyeden girilen metni bu adresten başlayarak karakter karakter kopyalar.

"Hello World" gibi boşluklu bir metin girildiğinde `%s` boşluğu string sonu sayar. Stringi bitiren özel bir karakter vardır: `'\0'`, **null karakter**. Boşluktan sonra girilenler alınmaz.

Boşluklu metin okumak için biçim dizgisine "Enter görene kadar her şeyi oku" anlamına gelen bir ifade yazılır (ekrandan, 02:20:00):

```c
printf("Text=%s", str);
fflush(stdin);
printf("\nEnter a string");
scanf("%[^\n]s", str);   // read chars till seeing enter
printf("Text=%s", str);
```

`'\n'` alt satıra geçme, yani Enter karakteridir. Önce bir şey okunup Enter'a basıldıysa o Enter tamponda (buffer) kalır ve sonraki `scanf`'e aktarılır; ikinci okuma bu yüzden alınamaz. `fflush(stdin)` bu tamponu temizlemek için kullanıldı. Bir öğrenci araya boş bir `scanf` koymayı önerdi; hoca bunun da çalıştığını ("dummy scanf"), ama asıl yapılması gerekenin tamponu temizlemek olduğunu söyledi.

> **Ders sonrası not:** `fflush(stdin)` standart C'de tanımsız davranıştır; derste kullanılan Windows ortamında çalışır, başka derleyicilerde çalışmayabilir (büyük olasılıkla). Taşınabilir yol, satır sonuna kadar karakterleri `getchar()` ile okumaktır. Ayrıca `%[^\n]` dönüşümü tek başına yeterlidir; arkasındaki `s` harfi ayrı bir harf olarak eşleştirilmeye çalışılır.

### 13.2 String uzunluğu ve karakterlere erişim

String bir dizi olduğu için karakterlerine indisle erişilir. Uzunluk bir `while` döngüsüyle bulunur:

```c
i = 0;
while (str[i] != '\0')
    i++;
```

Döngü bitince `i` stringin uzunluğudur. Hoca bazı öğrencilerin ayrıca bir `counter` değişkeni tuttuğunu, buna gerek olmadığını söyledi; `i` zaten paralel olarak artıyor. `'\0'` yerine null yazılabileceğini de söyledi.

> **Ders sonrası not:** C'de `NULL` bir işaretçi sabitidir; karakter karşılaştırmasında `'\0'` (ya da `0`) yazmak doğrudur. Bazı derleyiciler `str[i] != NULL` için uyarı verir (büyük olasılıkla).

Tek karakter `%c` ile yazılır. "hello world" için `str[0]` 'h', `str[2]` 'l' çıktı; `str[MAX-1]` boş göründü. Uzunluk 11 bulundu: 5 harf, 1 boşluk, 5 harf. 12. karakter (11 indisli) `'\0'`'dır; ondan sonrakiler önemli değildir.

### 13.3 Sınır dışı erişim ve segmentation fault

`str[MAX+100]` yazdırılınca bir sorun çıkmadı: `str` bir adres, buna 0, 2 ya da `MAX+100` eklenip o adrese gidiliyor; ayrılan yerin dışına erişildiği hâlde o bölgeye izin vardı. İndis yüz binlere çıkarılınca program bir hatayla sonlandı: **segmentation fault**. İşletim sistemi, programa ayrılan yerin dışına erişmeye izin vermeyip programı kapattı. Ayrılan yerin sınırları 0 ile `MAX-1` arasıdır.

### 13.4 Hata ayıklayıcıyla izleme

`str` satırına bir breakpoint konup "next line" ile ilerlendi ve "Hello World" girildi. `str` izlemeye (add watch) eklenince içinde "hello world" ve hemen ardından `'\0'`, sonra başka `\0`'lar ve çöp değerler görüldü. Önemli olan son harften hemen sonraki `'\0'`'dır. `str[i]` izlenince karakterlerin ASCII kodları görüldü (`'h'` = 104); `i` izlenince 11 olduğu görüldü (ekrandan, 02:30:00).

### 13.5 Palindrom: ikinci diziyle

Tersi kendisine eşit olan string **palindromdur**. İlk çözüm ters kopya kullanır: önce uzunluk `len` bulunur, sonra `str2[i] = str[len-i-1]` ile ters kopya oluşturulur, sonra iki string karakter karakter karşılaştırılır (ekrandan, 02:30:00):

```c
printf("\n%s\n%s", str, str2);
i = 0;
while (i < len && str[i] == str2[i]) {
    i++;
}
if (i == len) {
    printf("Palendrom");
}
```

Döngü iki şekilde biter: ya `i` `len`'e ulaşır (bütün karakterler aynı) ya da karşılıklı iki karakter farklı çıkar. `i == len` ise palindromdur, değilse değildir. "Hello World" için sonuç palindrom değil, "kek" için palindrom çıktı. Bu yöntem karşılaştırmada $N$ işlem yapar ama ek bir dizi ister; iyi bir yöntem değildir.

### 13.6 Palindrom: yerinde

Ek bellekten kurtulmak için `len/2`'ye kadar gidilir ve baştan $i$. karakter sondan $i$. karakterle karşılaştırılır. Ters dizi yazmaya gerek kalmaz:

```c
#include <stdio.h>
#define MAX 25
int main(){
    int i, len;
    char str[MAX];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    i = 0;
    while (str[i] != '\0') i++;
    len = i;
    i = 0;
    while (i < len/2 && str[i] == str[len-i-1]) i++;
    if (i == len/2) printf("Palendrom\n");
    else printf("Non-palendrom\n");
    return 0;
}
```

Bu tam program, derste yazılan parçalardan kuruldu ve gcc ile derlenip denendi: "kek" ve "neveroddoreven" için Palendrom, "hello world" ve boşluklu "never odd or even" için Non-palendrom.

Derste örnek palindromlar arandı: "no lemon, no melon", "never odd or even". Boşluklu "never odd or even" girildiğinde bir öğrenci boşlukların karşılık gelmediğini fark etti: boşluk da bir karakterdir ve hesaba katılması gerekir. Daha uzun bir metin dizinin boyutuna sığmayınca `MAX` 20'den 25'e çıkarıldı.

## 14. 6 ve 7 basamaklı palindrom sayılar

### 14.1 Yöntem 1: her sayıyı kontrol etmek

Soru: 6 basamaklı palindrom sayıları ekrana yazdırın; sonra 7 basamaklıları (ekrandan, 02:45:00). 6 basamaklı sayılar 100000'den 999999'a kadardır. Hocanın önceki dönemden hazır kodu gösterildi:

- 100000'den 999999'a her sayı alınır ve yedeklenir.
- Sayının son basamağı `% 10` ile alınıp bir basamaklar dizisine kaydedilir, sonra sayı 10'a bölünerek küçültülür. Böylece sayının tersi diziye yazılmış olur.
- Dizi, palindrom stringde olduğu gibi yarısına kadar gezilir. Palindromsa sayı ekrana yazılır, değilse sonraki sayıya geçilir.

Döngü yaklaşık 900.000 kez döner. Bulunan sayı adedi 900'dür.

### 14.2 Yöntem 2: üç basamaklı sayının tersini eklemek

Bir öğrenci sorunun "etrafından dolanmayı" önerdi: üç basamaklı bir sayı alıp tersini sonuna eklemek. Hoca bunun güzel bir çözüm olduğunu söyledi; "merhaba dünya" örneğinde stringin tersini sonuna yazmaya benzer.

- `i` 100'den 999'a gider.
- `b1 = i % 10` (birler), `b2 = (i / 10) % 10` (onlar), `b3 = i / 100` (yüzler).
- `printf("%d%d%d%d%d%d\n", b3, b2, b1, b1, b2, b3);`

İlk denemede basamaklar ters sırayla yazdırıldığı için bir öğrenci sıfırla başlayan sayılar olduğunu fark etti (`001100` gibi). Hoca yazdırma sırasını `b3, b2, b1, b1, b2, b3` olarak düzeltti. Bu yöntemde döngü yalnız 900 kez döner ve palindrom kontrolüne hiç gerek kalmaz; aradaki kontrol işlemleri ek maliyetti. Gerekirse sayılar ayrıca diziye de kaydedilebilir.

### 14.3 7 basamaklı palindrom sayılar

Bir öğrenci ortadaki basamağa 0'dan 9'a bir değer koymayı önerdi. Çözüm 3'te aynı üç basamak ayrılır ve araya bir döngü eklenir:

```c
for (i = 100; i <= 999; i++) {
    b1 = i % 10;
    b2 = (i / 10) % 10;
    b3 = i / 100;
    for (j = 0; j <= 9; j++) {
        printf("%d%d%d%d%d%d%d\n", b3, b2, b1, j, b1, b2, b3);
        sayac++;
    }
}
```

Sayaç 9000'e ulaşır. Hoca daha büyük basamak sayıları için iki çözümün birleştirilebileceğini söyledi: örneğin 8 basamak için 4 basamaklı bir dizi oluşturulur, sayının basamakları küçültme (10'a bölme) algoritmasıyla diziye kaydedilir, dizinin kendisi ve tersi yazılır; basamak sayısının tek ya da çift olmasına göre ortaya bir basamak eklenir.

Bu not için yöntem 2 ve 3 gcc ile çalıştırıldı: 900 ve 9000 sayı üretildi; ilk ve son sayılar 100001, 999999, 1000001, 9999999'dur. Yöntem 1'in kaba kuvvet sürümü de 900 buldu.

### 14.4 Sayma formülü

Sayma kurallarıyla (ekrandan, 02:45:00): ilk basamağa 0 gelemeyeceği için 9 seçenek vardır; sonraki serbest basamaklara 10'ar seçenek gelir; aynalanan basamaklar ise 1 seçeneklidir.

- 6 basamak: $9\cdot10\cdot10\cdot1\cdot1\cdot1 = 9\cdot10^2 = 900$.
- 7 basamak: $9\cdot10\cdot10\cdot10\cdot1\cdot1\cdot1 = 9\cdot10^3 = 9000$.
- 8 basamak: hoca önce $9\cdot10^4$ dedi, bir öğrencinin uyarısıyla $9\cdot10^3$ olarak düzeltti.

Genel formül, $n$ basamaklı palindrom sayısı için:

$$9\cdot10^{\lfloor (n-1)/2\rfloor}$$

İlk basamaktan sonra $n-1$ basamak kalır; bunların yarısı 10 seçenekli, diğer yarısı 1 seçeneklidir. 7 ve 8 basamakta üs aynı (3) çıkar. Python ile 7 ve 8 basamaklı palindrom sayıları sayıldı; ikisi de 9000 çıktı.

Bunun hesaplanması ile listelenmesi farklı karmaşıklıktadır. Sayıları listelemek için o kadar döngü dönmek zorunludur. Ama yalnız kaç tane olduğunu saymak için $9\cdot10^{k}$ hesaplanır; üs alma yarılamayla (önceki derslerde görüldüğü gibi) $\log n$ adıma indirgenebilir. Yani sayma algoritması $\log n$'dir.

## Örnek Sorular

1. (derste sözlü, 00:05:34) "Her pozitif doğal sayı $n$ için $n^2+n+41$ asaldır" önermesi doğru mudur?

> **Çözüm:** Yanlıştır. $n=40$ için $1681=41^2$, $n=41$ için $1763=41\cdot43$ asal değildir; tek karşı örnek yeter.

2. (ekrandan, 00:20:00) $a^4+b^4+c^4=d^4$ için kaba kuvvet algoritmasının karmaşıklığı nedir?

> **Çözüm:** Dört iç içe döngü, $T(N)=\sum_a\sum_b\sum_c\sum_d 1 \approx N^4$.

3. (ekrandan, 00:25:00) "2 dışındaki her çift tam sayı iki asalın toplamıdır" önermesini 4, 6, 8 ve 100 için deneyin.

> **Çözüm:** $4=2+2$, $6=3+3$, $8=5+3$, $100=97+3=41+59$. Önermenin genel doğruluğu bilinmiyor.

4. (ekrandan, 00:30:00) Tek bir geçici değişkenle $a\leftarrow b$, $b\leftarrow c$, $c\leftarrow a$ takasını yazın.

> **Çözüm:** `T=a; a=c; c=b; b=T;` ya da `T=b; b=a; a=c; c=T;`. $T(N)=1$, $S(N)=1$.

5. (ekrandan, 00:35:00) `int x=10, y=5; x=x^y; y=x^y; x=x^y;` sonrasında `x` ve `y` nedir? İlk adımdan sonra `x` kaçtır?

> **Çözüm:** İlk adımda $1010\oplus0101=1111=15$; sonunda `x=5`, `y=10` (gcc ile doğrulandı).

6. (ekrandan, 00:45:00) $a+b+c=1000$, $a^2+b^2=c^2$, $a,b,c>0$ koşullarını sağlayan bütün üçlüleri bulun; adım sayısını azaltın.

> **Çözüm:** (200, 375, 425) ve (375, 200, 425). Adım sayıları: üç döngü $10^9$; $c=1000-a-b$ ile $10^6$; `b<=1000-a` ile 499.500; `a<500`, `b` $500-a$..499 ile 124.750; `c` 333..499, `b` 1..499 ile 83.333 (gcc ile doğrulandı).

7. (ekrandan, 01:25:00) $1;\ 2\,3;\ 4\,5\,6;\ \dots$ üçgeninin 1000. satırının son elemanı kaçtır?

> **Çözüm:** $\frac{1000\cdot1001}{2}=500500$. İç içe döngüyle $N(N+1)/2$ işlem, formülle 3 işlem.

8. (derste sözlü, 01:32:50) $n$ sayı içinden en büyük ikinci sayı nasıl bulunur?

> **Çözüm:** `max` ve `max2` tutulur; `sayi > max` ise `max2=max; max=sayi;`, değilse ve `sayi > max2` ise `max2=sayi;`.

9. (ekrandan, 01:50:00) $N$ sayıdan en büyük 8.'si nasıl bulunur, maliyeti nedir?

> **Çözüm:** Diziye kaydet, artan sırala, $N-8$ indisli elemanı yaz. Erişim 1 adım; toplam maliyeti sıralama belirler: $N\log N$ (quick/merge sort) ya da $N^2$ (bubble/insertion/selection sort).

10. (ekrandan, 02:00:00) $n$ elemanlı bir diziyi yerinde (in-place) tersine çevirin.

> **Çözüm:** `for (i=0; i<n/2; i++) { t=d[i]; d[i]=d[n-i-1]; d[n-i-1]=t; }`. $T(N)\approx N$, $S(N)=1$. Döngü $n$'ye kadar giderse dizi eski hâline döner.

11. (derste sözlü, 02:25:50) Bir stringin palindrom olup olmadığını ek dizi kullanmadan kontrol edin.

> **Çözüm:** `while (i < len/2 && str[i] == str[len-i-1]) i++;` sonra `i == len/2` ise palindromdur (tam program bölüm 13.6'da).

12. (ekrandan, 02:45:00) 6 ve 7 basamaklı palindrom sayıları yazdırın. $n$ basamaklı kaç palindrom sayı vardır?

> **Çözüm:** 100..999 arası sayının basamakları `b3 b2 b1 b1 b2 b3` biçiminde yazılır (900 sayı); 7 basamakta ortaya `j=0..9` eklenir (9000 sayı). Genel: $9\cdot10^{\lfloor(n-1)/2\rfloor}$.

## Dersin Toparlaması

Ders, önermelerin karşı örnekle çürütülmesiyle başladı: $n^2+n+41$ ve $a^4+b^4+c^4=d^4$ örneklerinde yokluğu ispatlamak yerine tek bir karşı örnek bulmanın çok daha kolay olduğu görüldü; Eratosten kalburuyla hız ile bellek arasındaki ödünleşim hatırlatıldı. Ardından takas işlemi geçici değişkenle, toplama-çıkarma, çarpma-bölme ve XOR ile yapıldı. Pisagor üçlüsü probleminde matematiksel gözlemlerle adım sayısı $10^9$'dan 83.333'e indi; piramit probleminde karmaşıklık ile sonucun aynı çıktığı ve formülün sabit zamanda sonuç verdiği gösterildi.

Dersin ikinci yarısında dizilere geçildi. Birkaç değişkenle çözülemeyen en büyük $k$. sayı problemi verilerin bellekte, ardışık biçimde saklanması gerektiğini gösterdi. Dizi tanımı, indisler, sınırlar, ilk değer verme ve adreslerin bitişikliği görüldü. Diziyi tersine çevirme ve palindrom kontrolünde ek dizili ve yerinde (in-place) çözümler karşılaştırıldı; son olarak palindrom sayılar hem listeleme hem sayma açısından incelendi. Hoca konuların katlanarak ilerlediğini söyledi: önce koşullar, sonra döngüler, şimdi diziler; sonraki derslerde hem algoritmayı iyileştiren hem programlama bilgisini geliştiren örneklerle devam edilecek. Ders notlarındaki 3. hafta örnekleri (Pascal üçgeniyle ilgili olanlar dahil) çalışma için önerildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
