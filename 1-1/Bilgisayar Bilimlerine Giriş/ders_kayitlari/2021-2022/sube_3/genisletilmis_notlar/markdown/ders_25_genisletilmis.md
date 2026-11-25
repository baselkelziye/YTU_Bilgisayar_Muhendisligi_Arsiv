# Ders 25 Genişletilmiş Notu: Dizilerle Algoritmalar: Rakam Tekrarı, Asal Sayı ve Temel Dizi İşlemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin amacı: algoritma sorularını dizilerle çözmek
- 2. Rakamları birbirinden farklı mı? İkili karşılaştırma çözümü
- 3. Daha verimli çözüm: sayaç dizisi
- 4. Asal sayı testi
- 5. Asal sayı testini iyileştirmek
- 6. N'e kadar bütün asal sayılar: eleme yöntemi
- 7. Diziler üzerinde temel işlemler
- 8. En küçük ve en büyük eleman, elemanın yeri
- 9. for ile while arasındaki seçim
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin amacı: algoritma sorularını dizilerle çözmek

Dersin konusu bir boyutlu dizilerdir. Dizilere ve programlama dillerine önceki haftalarda giriş yapılmıştı. Bu hafta hoca "bir taşla iki kuş" vurmak istediğini söylüyor: daha önce sorulmuş algoritma sorularını birlikte çözerek hem dizileri pekiştirmek hem de sık yapılan hataları göstermek. Çizimler hocanın tablette elle çizdiği akış diyagramlarıdır.

Bu bölümde hoca, akış diyagramlarıyla ilgili gelen bir soruya da cevap veriyor: akış diyagramında döngüyü "kırmak" diye bir şey yoktur. Döngünün bir koşulla bitmesi gerekiyorsa `while`, adım sayısı belliyse `for` kullanılır. Döngüyü `break` benzeri bir yolla yarıda kesmek kabul edilmez.

> **Hocanın vurgusu:** Döngü bir yerde bitecekse `while` kullanılır; adım sayısı belliyse `for`. Döngüyü kuralsız biçimde (break gibi) bitirmek hatalı sayılır.

## 2. Rakamları birbirinden farklı mı? İkili karşılaştırma çözümü

### 2.1 Problem

Sayı oyununda üretilen bir sayının kurallara uygun olması için bütün rakamlarının birbirinden farklı olması gerekir. Verilen bir sayının (örnek: 5879) bu kurala uyup uymadığı bulunacaktır (ekrandan, 00:15:00).

Sayı bize bütün olarak verilir. Bu yüzden iki iş yapılmalıdır:

- Sayıyı rakamlarına ayırmak ve rakamları bir yerde (bir dizide) saklamak.
- Her rakamı kendinden sonraki rakamlarla karşılaştırmak: önce 5'i 8, 7 ve 9 ile; sonra 8'i 7 ve 9 ile; sonra 7'yi 9 ile.

### 2.2 Neden while?

Hoca karşılaştırma için `for` mu `while` mı kullanılacağını soruyor. Doğru cevap `while`: eşitliğin hangi adımda bulunacağı önceden bilinmez. Sayı 5579 olsaydı iki 5 hemen eşit çıkardı; kural bozulduğu için kalan rakamlara bakmaya gerek kalmaz ve döngüden çıkılmalıdır. `for` kullanmak yanlış sonuç vermez, ama gereksiz kontrol yapar ve programı uzatır.

### 2.3 Rakamlara ayırma

Basamak sayısı bilinmediği için ayırma da bir `while` ile yapılır. Akış diyagramı ilk hâliyle şöyledir (ekrandan, 00:15:00):

```text
START
  oku N
  I = 1
  while N > 9:
      DIZI[I] = N mod 10
      N = N div 10
      I = I + 1
```

`mod 10` son basamağı verir, `div 10` sayıyı bir basamak küçültür, `I` dizide bir sonraki göze geçmek için artırılır. 5879 için: `5879 mod 10 = 9` birinci göze yazılır, sayı 587 olur; ikinci göze 7, üçüncü göze 8, en sonda 5 gelir. Dizi tersten dolar: 9, 7, 8, 5 (ekrandan, 00:20:00).

**Soru:** Rakamların diziye tersten kaydedilmesinin bir sakıncası var mı? Sonraki döngüyü N'den geriye doğru mu kurmak gerekir? **Cevap:** Hayır. Amaç iki ya da daha fazla eşit rakam olup olmadığını bulmak; 9, 7, 8, 5 ile 5, 8, 7, 9 arasında kontrol açısından hiçbir fark yoktur.

### 2.4 Karşılaştırma döngüleri

Karşılaştırma iç içe iki `while` ile yapılır. `isunique` adlı bir bayrak 1 ile başlar; 1 olduğu sürece döngüler devam eder. Dış döngü elinize aldığınız elemanı (`J`), iç döngü onunla karşılaştırılan elemanları (`K`) gezer. `DIZI[K] = DIZI[J]` ise doğru kolunda `isunique = 0` yapılır; yanlış kolunda bir şey yapılmaz. Her iki durumda da `K = K + 1` (ekrandan, 00:20:00).

`isunique` 0 olduğunda iki döngünün koşulu da bozulduğu için ikisinden de kendiliğinden çıkılır. En sonda `isunique = 1` ise ekrana `'+'` (kurala uygun), değilse `'-'` (kurala uygun değil) yazdırılır.

### 2.5 Hataları birlikte bulmak

Hoca ilk diyagramı bilerek eksik bıraktı ve hataları öğrencilerle birlikte buldu.

**Birinci hata: son basamak kaydedilmiyor.** Bir öğrenci döngünün sayının yalnız üç rakamını aldığını fark etti. 5879'dan 9, 7 ve 8 alındıktan sonra elde 5 kalır; `5 > 9` yanlış olduğu için döngüden çıkılır ve 5 diziye yazılmaz. Düzeltme: döngüden çıktıktan sonra `DIZI[I] = N` eklemek. Koşul `N > 9` olduğu için bu yapılmazsa binler basamağı kaybolur.

**İkinci hata: J artırılmıyor.** Dış döngüde `J = J + 1` unutulmuştu.

**Üçüncü hata: K'nın başlangıcı.** `K` 1'den başlarsa, `J` de 1'den başladığı için eleman kendisiyle karşılaştırılır, eşit bulunur ve yanlış karar verilir. `K` her seferinde elinizdeki elemandan bir sonrakinden başlamalıdır: `K = J + 1`.

**Neden `J < N` ve `K <= N`?** En son elinize alacağınız eleman sondan bir önceki elemandır, onunla karşılaştırılacak olan ise dizinin son elemanıdır. Bu yüzden dış döngüde küçüktür, iç döngüde küçük eşittir kullanılır.

**Dördüncü hata: döngü sınırı.** Hoca bunun programın yanlış çalışmasına yol açan çok önemli bir hata olduğunu söyledi ve kimsenin görmediğini belirtti. Döngü sınırı olarak `N` kullanılmıştı, oysa `N` artık dizideki eleman sayısını değil, bölmelerden sonra kalan son basamağı tutar. Dizideki basamak sayısını `I` tutar (son basamak `DIZI[I]`'ya yazıldığı için). Doğru koşullar `J < I` ve `K <= I` olur (ekrandan, 00:30:00).

Düzeltilmiş diyagram:

```text
START
  oku N
  I = 1
  while N > 9:
      DIZI[I] = N mod 10
      N = N div 10
      I = I + 1
  DIZI[I] = N
  J = 1
  isunique = 1
  while J < I AND isunique = 1:
      K = J + 1
      while K <= I AND isunique = 1:
          if DIZI[K] = DIZI[J]:  isunique = 0
          K = K + 1
      J = J + 1
  if isunique = 1:  yaz '+'
  else:             yaz '-'
STOP
```

> **Ders sonrası not:** Dizi tersten dolduğu için 5579 örneğinde dizi 9, 7, 5, 5 olur ve eşitlik ilk karşılaştırmada değil, altıncı (son) karşılaştırmada bulunur. Hoca "ilk adımda yakalanır" derken sayıyı soldan okuyordu. Sonuç doğru çıkar, yalnız karşılaştırma sayısı değişir (python ile denendi).

**Soru:** Bütün diziyi gezmeye gerek yok, on kere gezmek yetmez mi? Basamak sayısı 10'u geçerse rakamlar zaten tekrarlanır. **Cevap:** Doğru, ama zaten o kadar gezilmiyor; dizi basamak sayısı kadar gezilir. 4 basamaklı sayı için 4, 3 basamaklı için 3; bunu `I` tutar.

> **Ek bilgi (derste anlatılmadı):** Öğrencinin gözlemi güvercin yuvası ilkesine dayanır: yalnız 10 farklı rakam olduğu için 10'dan fazla basamaklı her sayıda en az bir rakam mutlaka tekrar eder.

### 2.6 Akış diyagramı kuralları

Hoca bu soruda sık görülen iki hatayı hatırlattı:

- Bir algoritmanın, bir akış diyagramının bir START ve bir STOP noktası vardır. Birden fazla yerde durmaz.
- Bir `if`'in doğru kolu boş olup yalnız yanlış kolu dolu olamaz. Doğru kolu dolu, yanlış kolu boş olabilir. Yalnız yanlış kolda iş varsa koşul ters çevrilmelidir.

> **Hocanın vurgusu:** Akış diyagramının tek START ve tek STOP noktası olur; doğru kolu olmayan bir `if` olmaz.

## 3. Daha verimli çözüm: sayaç dizisi

### 3.1 Fikir

Daha az kontrol yapan başka bir çözüm önerilmeyince hoca kendi çözümünü gösterdi. 1'den 10'a numaralı on gözlü bir **counter (sayaç)** dizisi kurulur ve bütün gözleri başta 0 yapılır. Bu dizi her rakamdan kaç tane görüldüğünü tutar (ekrandan, 00:35:00).

5879'un rakamları sırayla gelir: 5 gelince 5'in gözü 1 yapılır, 8 gelince 8'in gözü, 7 gelince 7'nin gözü, 9 gelince 9'un gözü. Bir öğrencinin dediği gibi, herhangi bir gözde 1'den büyük değer oluşursa o rakam tekrar etmiştir. Daha pratik bir kontrol: göze gidildiğinde göz 0 ise 1 yapılır; 0 değilse rakam daha önce görülmüştür, kural bozulmuştur ve bu bilgi saklanmalıdır.

### 3.2 İlk akış diyagramı ve düzeltmeler

İlk hâlinde diyagram şöyleydi (ekrandan, 00:35:00): `N` okunur; `N > 9` iken `I = N mod 10`; `DIZI[I] = 0` ise `DIZI[I] = 1`, değilse `isunique = 0`; sonra `N` küçültülür.

Hatalar yine birlikte bulundu:

- `I`'ya başta 1 atamaya gerek yoktur; burada `I` her adımda `N mod 10` ile yeniden hesaplanır.
- Sayaç dizisinin gözleri işe başlamadan önce 0 yapılmalıdır: `I` 1'den 10'a kadar `DIZI[I] = 0` (ekrandan, 00:40:00).
- Dizi 1'den 10'a numaralı, oysa `N mod 10` 0 da verebilir. 0 rakamı 1. gözle, 1 rakamı 2. gözle, ..., 9 rakamı 10. gözle temsil edilir. Bu yüzden diyagramda `DIZI[I+1]` kullanılır.
- Koşul `N > 9` olursa son rakam işlenmez; koşul `N > 0` olmalıdır. 5879 sırayla 587, 58, 5 ve 0 olur; 5 de işlendikten sonra 0 kalır ve döngüden çıkılır.
- `N = N div 10` ile `N`'in yeni değeri atanmalıdır (ilk çizimde eksikti).
- `isunique` başta 1 yapılmalı ve döngü koşulu `N > 0 AND isunique = 1` olmalıdır; tekrar bulununca boşuna devam edilmez.

Düzeltilmiş diyagram (ekrandan, 00:40:00):

```text
START
  oku N
  I = 1'den 10'a:  DIZI[I] = 0
  isunique = 1
  while N > 0 AND isunique = 1:
      I = N mod 10
      if DIZI[I+1] = 0:  DIZI[I+1] = 1
      else:              isunique = 0
      N = N div 10
  if isunique = 1:  yaz '+'
  else:             yaz '-'     (sayı kurallara uygun değil)
STOP
```

### 3.3 C kodu

Hoca pratik olsun diye aynı çözümün C kodunu da yazdı (ekrandan, 00:45:00). C'de diziler 0. gözden başladığı için dizi 0'dan 9'a kullanılır; `+1` gerekmez, `mod 10` sonucu doğrudan göz numarasıdır. Kodda önce `n` kullanılıp sonra değişken adı `number` yapıldığı için `n` geçen yerler `number` ile değiştirildi. `n / 10` işlemi iki işlenen de tam sayı olduğu için `div` gibi çalışır. Değişken tanımları en sona bırakıldı; `isunique` tanımlanırken 1 yapıldığı için ayrıca atama gerekmez.

Aşağıdaki kod derste ekranda ve sözlü yazılanın tamamlanmış hâlidir. `gcc -Wall` ile derlendi ve 5879 (uygun), 5579 (uygun değil), 1020 (uygun değil), 9 (uygun) girdileriyle denendi.

```c
#include <stdio.h>

int main() {
    int i, number, dizi[20], isunique = 1;

    printf("sayi giriniz\n");
    scanf("%d", &number);
    for (i = 0; i < 10; i++)
        dizi[i] = 0;
    while ((number > 0) && (isunique == 1)) {
        i = number % 10;
        if (dizi[i] == 0) {
            dizi[i] = 1;
        } else {
            isunique = 0;
        }
        number = number / 10;
    }
    if (isunique == 1)
        printf("sayi kurallara uygundur\n");
    else
        printf("sayi kurallara uygun degildir\n");
    return 0;
}
```

**Soru:** Diziyi `dizi[10]` diye tanımlasak yeterli olmaz mı? **Cevap:** Olur; bu soru için 10 eleman yeterlidir.

### 3.4 İki yöntemin karşılaştırması

İkili karşılaştırmada 5879 için en kötü durumda kaç kontrol gerekir? Hoca tek tek saydı: 5-8, 5-7, 5-9, 8-7, 8-9, 7-9. İlk turda 3, ikinci turda 2, son turda 1, toplam 6 kontrol. Genel olarak $n$ basamaklı bir sayı için:

$$(n-1) + (n-2) + \dots + 1 = \frac{n(n-1)}{2}$$

Sayaç dizisiyle ise en kötü durumda yalnız basamak sayısı kadar, yani 5879 için 4 kontrol yapılır. İlk çözümde iç içe iki döngü, burada tek bir döngü vardır.

Bu örnekle anlatılmak istenen şudur: zaman karmaşıklığını, yani işlem sayısını azaltmak için bellekteki bazı alanlar sayaç gibi başka amaçlarla kullanılabilir. Bunun bedeli bellekten biraz alan harcamaktır, ama algoritma daha hızlı çalışır.

> **Hocanın vurgusu:** Bellekten biraz fedakârlık edip bir diziyi sayaç olarak kullanmak, iç içe döngüleri tek döngüye indirerek işlem sayısını azaltabilir.

## 4. Asal sayı testi

### 4.1 Problem ve ilk çözüm

Verilen bir pozitif tam sayının asal olup olmadığı bulunacaktır. Örnek sayılar: 92, 5, 12, 3, 47 (ekrandan, 01:00:00). Asal sayılar yalnız 1'e ve kendisine bölünen sayılardır. 1 dışarıda bırakılırsa 2'den $N-1$'e kadar sayılar denenerek karar verilebilir.

İlk çözümün akış diyagramı (ekrandan, 01:00:00):

```text
START
  oku N
  I = 2
  while N mod I ≠ 0:
      I = I + 1
  if N = I:  yaz 'Asal sayı'
  else:      yaz 'Asal sayı değil'
STOP
```

**Soru:** `N mod I` sıfırdan farklıyken döngü içinde ne yapılmalı? **Cevap:** `I` bir artırılır ve döngünün nerede biteceği beklenir. Döngüden çıkınca `I`'nın `N`'e eşit olup olmadığına bakılır: ilk bölen sayının kendisiyse sayı asaldır.

Masa testi (ekrandan, 01:00:00):

- $N = 2$: `I = 2`, `2 mod 2 = 0`, döngüye girilmeden çıkılır; `2 = 2` olduğu için asal.
- $N = 3$: `3 mod 2 ≠ 0`, `I = 3`; `3 mod 3 = 0`, çıkılır; `3 = 3`, asal.
- $N = 4$: `4 mod 2 = 0`, çıkılır; `4 ≠ 2`, asal değil.

Bu çözümde de `while` kullanılmasının nedeni aynıdır: 92 verildiğinde 2 onu böldüğü için daha ilk adımda asal olmadığı söylenebilir. `for` ile her sayı denenip bir sayaç tutulsaydı sonuç yine doğru olurdu, ama 2'nin böldüğü görülebilecekken gereksiz yere kalan bütün sayılar denenirdi.

**Soru:** Mod almak yerine aynı sayıyı hem tam sayı bölmesiyle (div) hem normal bölmeyle bölüp sonuçların eşitliğine baktım; doğru olur mu? **Cevap:** Kâğıdı görüp yorumlamak gerekir. Mod işleminin arka planda yaptığını (div yapıp çarpıp çıkararak kalanın sıfır olup olmadığını) matematiksel olarak doğru yaptıysanız ve sorunsuz çalışıyorsa sorun yoktur.

> **Ek bilgi (derste anlatılmadı):** Bu ilk çözüm $N \geq 2$ için doğrudur. $N = 1$ verilirse `1 mod 2 ≠ 0` olduğu için döngü hiç durmaz; büyük olasılıkla girdinin 2 ya da daha büyük olduğu varsayılmıştır.

## 5. Asal sayı testini iyileştirmek

### 5.1 Sayının yarısına kadar

Hoca bunu 48 üzerinden anlattı. 48 ikiye bölünüyorsa karşılık gelen çarpan 24'tür. Bir sayının, kendisi dışında, yarısından büyük bir böleni olamaz: 25, 26, 27, ... 48'i bölemez. O hâlde bölen aramayı sayının yarısından sonra sürdürmenin anlamı yoktur.

Yeni akış diyagramı (ekrandan, 01:15:00 ve 01:20:00):

```text
START
  oku N
  I = 2
  M = N div 2
  isprime = 1
  while I <= M AND isprime = 1:
      if N mod I = 0:  isprime = 0
      I = I + 1
  if isprime = 1:  yaz 'Asal sayı'
  else:            yaz 'Asal sayı değil'
STOP
```

48 için: `N = 48`, `I = 2`, `M = 24`. `I <= M` ve `isprime = 1` olduğu için döngüye girilir; `48 mod 2 = 0` olduğu için `isprime = 0` olur, `I` artırılır. `I` hâlâ `M`'den küçük olsa da `isprime` artık 0 olduğu için döngüden çıkılır ve "Asal sayı değil" yazdırılır.

### 5.2 Çift sayıları atlamak

**Soru:** Bir kez 2'ye böldükten sonra 4, 6 gibi çift sayıları hiç denemesek, yalnız 3, 5, 7, 9 gibi tek sayılarla devam etsek daha iyi olmaz mı? **Cevap:** Evet, güzel bir ara çözüm. Önce 2'ye bölünüp bölünmediği tek bir `if` ile kontrol edilir; sonra `I` 3'ten başlatılıp ikişer artırılır (`I = I + 2`) ve yarıya kadar gidilir. Böylece 2'nin katları bir daha denenmez.

### 5.3 Karekök sınırı

Hoca kontrol noktasının daha da küçültülüp küçültülemeyeceğini sordu; bir öğrenci karekökü önerdi. 36'nın bölenleri 2, 3, 4, 6, 9, 12, 18, 36'dır (ekrandan, 01:20:00). Bölenler eşler halinde gelir: 2'nin karşılığı 18, 3'ün karşılığı 12, 4'ün karşılığı 9, 6'nın karşılığı yine 6'dır ve 6 aynı zamanda 36'nın kareköküdür. Karekökten sonra gelen her bölenin karekökten önce bir eşi vardır; karekökten sonra bölen olup da öncesinde karşılığı olmayan bir sayı olamaz. Bu yüzden `M = N div 2` yerine `M = sqrt(N)` yazmak yeter.

101 için karşılaştırma: ilk çözümde 100'e kadar, yarıya kadar denemede 50'ye kadar, karekök sınırıyla yalnız 10'a kadar gidilir. Karekök sınırı ile çift sayıları atlama birlikte uygulanırsa kontrol sayısı daha da azalır.

> **Ders sonrası not:** Hoca 48 için "7'ye kadar", 100 için "10'a kadar" gidileceğini söyledi. $\sqrt{100} = 10$ doğrudur; $\sqrt{48} \approx 6{,}93$ olduğundan 48 için tam sayı olarak 6'ya kadar denemek yeterlidir (python ile denendi).

> **Ek bilgi (derste anlatılmadı):** $N = a \cdot b$ ve $a \leq b$ ise $a \cdot a \leq N$, yani $a \leq \sqrt{N}$ olur. Bu yüzden $\sqrt{N}$'e kadar hiç bölen bulunamazsa $N$ asaldır. Kodda `sqrt` yerine `I * I <= N` koşulu da kullanılabilir.

## 6. N'e kadar bütün asal sayılar: eleme yöntemi

Hoca bir adım öteye geçip hem $N$'in asal olup olmadığını hem de $N$'e kadar olan bütün asal sayıları bulan bir yöntemin genel prensiplerini gösterdi (ekrandan, 01:25:00 ve 01:30:00). 1'den 18'e numaralı bir dizide:

- Önce 2'nin katları 1 ile işaretlenir; bu sayıların asal olma ihtimali ortadan kalkar.
- Sonra işaretsiz ilk sayıya, 3'e geçilir. 3'ün ilk katı 6'dır, ama 6 zaten işaretlidir. İşaretlenmişleri tekrar gezmemek için 3'ün karesinden, 9'dan başlanır.
- 3'er değil 6'şar ilerlenir (9, 15, 21, ...), çünkü 2'nin katları zaten atlanıyor. Bunu bir öğrenci söyledi.
- 3'ün katları bitince sıfır olan ilk sayıya, 5'e geçilir. 10, 15, 20 gibi katlar daha önce 2 ve 3'ün katı olarak işaretlendiği için 5'in karesinden, 25'ten başlanır ve 10'ar ilerlenir (25, 35, 45, 55, ...).
- Sonra 7'ye, sonra sıfır kalan 11'e, 13'e geçilir.

Sonunda 1 olan gözler asal olmayan, 0 kalan gözler asal sayıları gösterir. Bir dizi üzerinde yapılan bu işaretlemeyle bir taşla birden fazla asal sayı elde edilir; önceden bulunan asalların gücünden yararlanıldığı için boşuna bölme ve çarpma yapılmaz.

Hoca yöntemin literatürde bir antik Yunan adıyla anıldığını, adın "E" harfiyle başladığını söyledi ve ayrıntısını öğrencilerin bulmasını istedi.

> **Ek bilgi (derste anlatılmadı):** Bu yöntem Eratosthenes Kalburu (Sieve of Eratosthenes) olarak bilinir. $p^2$'den başlama nedeni, $p$'nin $p^2$'den küçük katlarının daha küçük bir asal çarpanı olması ve bu yüzden zaten işaretlenmiş olmasıdır.

**Asal sayılar neden önemli?** Asal sayılar rastgele sayı üreticilerinde ve şifrelemede sık kullanılır; çok büyük asal sayılar şifrenin kırılma ihtimalini azaltır. İleride görülecek hash konusunda bir bilgi bir fonksiyondan geçirilip üretilen değere göre bir adrese yerleştirilir; bu fonksiyonun mod alma işleminde bir asal sayıya ihtiyaç duyulur.

## 7. Diziler üzerinde temel işlemler

### 7.1 İşlemlerin listesi

Hoca bir veri setinin (bir sayı grubunun) dizide saklandığını varsayarak üzerinde yapılabilecek temel işlemleri öğrencilere sordu. Ortaya çıkan liste (ekrandan, 01:35:00 ve 01:40:00):

- Insert (ekleme)
- Delete (silme)
- Update (güncelleme)
- Search (arama)
- Min (en küçüğü bulma)
- Max (en büyüğü bulma)
- Sort (sıralama)
- Avg (ortalama)

Verinin sıralı ya da sırasız olması bu işlerin nasıl yapılacağını değiştirir. Sırasız bir veri grubunu sıralamak da ayrı bir işlemdir.

### 7.2 Arama ve güncelleme

**Soru:** 5 elemanlı bir dizide bir elemanın var olup olmadığını bulmak için kaç kontrol gerekir? **Cevap:** Dizi kaç elemanlıysa o kadar; genellersek $n$ elemanlı dizide $n$ kontrol.

Güncelleme için de en kötü durumda $n$ kontrol gerekir, çünkü önce elemanın var olup olmadığı aranır; bulununca yalnız değeri değiştirilir. Burada elemanların tekrar etmediği kabul edilir. Elemanlar tekrar ediyorsa ya da dizi sıralıysa kullanılacak arama yöntemleri değişir.

### 7.3 Silme

Silmek için de önce elemanın yeri bulunur. 3, 1, 2, 4, 5 dizisinden 4 silinecek olsun (ekrandan, 01:40:00). Bir öğrencinin önerisiyle: silmek için özel bir şey yapılmaz; 4'ün sağındaki elemanlar birer sola kaydırılıp üzerine yazılır. Dizi 3, 1, 2, 5, 5 olur. Ekrana basarken sondaki fazla 5 gösterilmemelidir; bunun için 1'den $N-1$'e kadar yazdırılır.

İkinci örnekte 3, 1, 2, 4, 5'ten 3 silinir: 1 3'ün yerine, 2 1'in yerine, 4 2'nin yerine, 5 4'ün yerine geçer. Dizi 1, 2, 4, 5, 5 olur; $N-1$'e kadar yazdırılınca yalnız 1, 2, 4, 5 görünür.

### 7.4 Ekleme

Sırasız bir diziye (3, 1, 2, 4, 5) yeni bir eleman gelirse iş basittir: dizinin boyutu bir artırılır ve yeni eleman son elemandan sonraki göze yazılır (ekrandan, 01:40:00 ve 01:45:00).

Dizi sıralıysa (1, 2, 4, 5, 6) ve yeni gelen 3 sırayı bozmadan eklenecekse önce yeri bulunur. Bir öğrencinin tarifiyle: baştan itibaren bakılır; 3 1'den büyük, 2'den büyük, 4'ten büyük değil, o hâlde 4'ün yerine girecek. Sonra elemanlar sağa kaydırılır. Kaydırma bulunan yerden başlanarak yapılırsa elemanların üzerine yazılır ve elemanlar kaybolur. Kaybetmemek için önce 6, sonra 5, sonra 4 kaydırılır, yani sondan başlanır. Sonuç: 1, 2, 3, 4, 5, 6.

> **Hocanın vurgusu:** Sıralı diziye eklemede kaydırma sondan başlanarak yapılmalıdır; aksi halde elemanlar üzerine yazılarak kaybolur.

## 8. En küçük ve en büyük eleman, elemanın yeri

### 8.1 Gözle yaptığımızı bilgisayara anlatmak

**Soru:** Bir dizinin en küçük ve en büyük elemanını bulmak için ne yapılabilir? Bir öğrenci elemanları ikişer karşılaştırıp değişiklik olursa bir bayrakla yeniden taramayı önerdi; hoca iyi başladığını ama sonunun karıştığını söyledi.

Hocanın anlattığı temel prensip: ilk eleman (3) elde tutulur ve en küçük eleman kabul edilir. Sonra sıradaki eleman alınır: 1, 3'ten küçük mü? Evet; elimdeki 3 bırakılır, 1 tutulur. Sonra 2'ye, 4'e, 5'e bakılır. Kontroller bitince elde hangi eleman kaldıysa en küçük odur ve ekrana yazılır. Gözle bakarken yaptığımız da aslında budur.

### 8.2 En küçük değerin akış diyagramı

Akış diyagramı (başı ekrandan, 01:45:00; devamı sözlü):

```text
START
  oku N, dizi[N]
  min = dizi[1]
  I = 2'den N'e, 1'er:
      if dizi[I] < min:  min = dizi[I]
  yaz min
STOP
```

**Soru:** Döngü kaçtan başlamalı? Bir öğrenci C'deki gibi 0 dedi. **Cevap:** Şu anda akış diyagramı çiziliyor; hangi programlama dilinin kullanılacağının bir önemi yok. Birinci eleman elde tutulduğu için kendisiyle karşılaştırmaya gerek yoktur; döngü 2'den başlar ve $N$'e kadar gider.

**Soru:** En büyük eleman için ne değişir? **Cevap:** Bir öğrencinin dediği gibi yalnız `if` kolundaki karşılaştırma işareti değişir. Değişkenin adını `min` yerine `max` yapmak da daha uygun olur.

### 8.3 En küçük elemanın yeri

Değer yerine en küçük elemanın kaçıncı eleman olduğu bulunmak istenirse? Bir öğrenci doğru kolunda `min = I` yazmayı, sonra başka bir değişkenle (`L = I`) yeri tutmayı önerdi. Hoca diziyi 3, 1, 2, 5, 4 olarak yeniden yazıp diyagramı baştan çizdi (ekrandan, 01:50:00 ve 01:55:00).

En küçük elemanın yerini tutan değişkenin adı `yer` olsun. Başta en küçük eleman birinci eleman kabul edildiği için `yer = 1` olmalıdır (ilk çizimde `yer = I` yazılmıştı, `1` olarak düzeltildi). Karşılaştırmada `min` yerine `dizi[yer]` kullanılır, çünkü `yer` zaten en küçük elemanın yerini tutar. İkinci eleman birinciden küçükse doğru kolunda `yer = I` yapılır.

```text
START
  oku N, A[N]
  yer = 1
  I = 2'den N'e, 1'er:
      if dizi[I] < dizi[yer]:  yer = I
  yaz yer, dizi[yer]
STOP
```

`yer` yazdırılınca en küçük elemanın kaçıncı eleman olduğu, `dizi[yer]` yazdırılınca değeri görülür. 3, 1, 2, 5, 4 için sonuç: `yer = 2`, `dizi[yer] = 1` (python ile denendi).

## 9. for ile while arasındaki seçim

**Soru:** En küçük elemanı bulan döngüde `for` yerine `while` kullanmalı mıyım? **Cevap:** Bütün elemanlar kontrol edilmek zorunda olduğu için, yani adım sayısı belli olduğu için `while`'a gerek yoktur. `while` kullanılsaydı koşul `I <= N` olur ve `I` ayrıca artırılırdı; teknik olarak bir fark yoktur. Ama adım sayısı belli olduğunda derleyici buna göre optimizasyon yapabildiği için bu işlerde `for` tercih edilir.

İki hatanın ağırlığı aynı değildir. Adım sayısı belli bir işte `while` kullanmak doğru değildir ama işlem sayısını artırmaz. `while` kullanılması gereken bir yerde `for` kullanmak ise gerekenden fazla kontrol yapma riskini doğurur. Küçük algoritmalarda bu fark önemsiz görünebilir, ama bir milyon, on milyon kayıt olduğunda önemlidir.

Hoca dizilerdeki ekleme, silme, güncelleme ve arama işlemlerinin bugün bankacılık ve sağlık verisi gibi her tür veride yapıldığını hatırlattı. Özellikle arama çok sık yapılır: milyonlarca kişinin bilgileri arasından birinin kaydına örneğin kimlik numarasıyla erişilir. Bunun için aranan bilginin benzersiz (unique) olması gerekir; değilse kaç tane olduğu ve hangi sıralarda olduğu bilinmelidir. Bir sınıftaki en yüksek ve en düşük not, çan eğrisi ve ortalama gibi istatistik hesapları da min, max ve ortalama işlemlerine dayanır.

> **Hocanın vurgusu:** Amaç mümkün olduğunca az iş yaparak sonuca ulaşmaktır; döngü türü bu amaca göre seçilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Verilen bir sayının (örnek: 5879) bütün rakamlarının birbirinden farklı olup olmadığını bulan algoritmanın akış diyagramını çizin. Rakamlar farklıysa `'+'`, değilse `'-'` yazdırılsın.

> **Çözüm:** Derste iki çözüm verildi. İkili karşılaştırma çözümü Bölüm 2.5'teki düzeltilmiş diyagramdır ($n$ basamak için en kötü durumda $\frac{n(n-1)}{2}$ karşılaştırma). Sayaç dizisi çözümü Bölüm 3.2'deki diyagramdır (en kötü durumda $n$ kontrol). 5879 için sonuç `'+'`, 5579 için `'-'`.

**Soru 2** (ekrandan, 00:20:00 ve 00:30:00): İlk çizilen ikili karşılaştırma diyagramındaki hataları bulun.

> **Çözüm:** (1) `N > 9` koşulu yüzünden son basamak diziye girmiyor, döngüden sonra `DIZI[I] = N` eklenmeli. (2) `J = J + 1` eksik. (3) `K = 1` yerine `K = J + 1` olmalı. (4) Döngü sınırları `N` yerine basamak sayısını tutan `I` olmalı: `J < I`, `K <= I`.

**Soru 3** (derste sözlü, 00:47:00): 5879 için ikili karşılaştırma yönteminde en kötü durumda kaç kontrol yapılır? Sayaç dizisi yönteminde kaç?

> **Çözüm:** İkili karşılaştırmada $3 + 2 + 1 = 6$; sayaç dizisinde basamak sayısı kadar, 4.

**Soru 4** (ekrandan, 01:00:00): Verilen bir pozitif tam sayının (92, 5, 12, 3, 47) asal olup olmadığını bulan algoritmanın akış diyagramını çizin.

> **Çözüm:** Temel çözüm Bölüm 4.1'deki diyagramdır; iyileştirilmiş hâli Bölüm 5.1'dedir (sınır `N div 2`, daha iyisi `sqrt(N)`, ayrıca 2'den sonra yalnız tek sayılar). Sonuçlar: 5, 3 ve 47 asal; 92 ve 12 asal değil (python ile denendi).

**Soru 5** (derste sözlü, 01:18:00): 48 için bölen aramada üst sınır 24 yerine daha küçük seçilebilir mi?

> **Çözüm:** Evet, karekök: bölenler karekökün iki yanında eşler halinde bulunduğu için $\lfloor\sqrt{48}\rfloor = 6$'ya kadar denemek yeterlidir.

**Soru 6** (ekrandan, 01:40:00): 3, 1, 2, 4, 5 dizisinden 4 silinirse dizi ne olur, nasıl yazdırılır? Sıralı 1, 2, 4, 5, 6 dizisine 3 nasıl eklenir?

> **Çözüm:** Silmede 4'ün sağındakiler sola kayar: 3, 1, 2, 5, 5; yalnız ilk $N-1$ eleman yazdırılır (3, 1, 2, 5). Eklemede 3'ün yeri (4'ün yeri) bulunur, 6, 5, 4 sondan başlanarak birer sağa kaydırılır ve 3 boşalan göze yazılır: 1, 2, 3, 4, 5, 6.

**Soru 7** (ekrandan, 01:50:00): 3, 1, 2, 5, 4 dizisinde en küçük elemanın yerini ve değerini bulan akış diyagramını çizin.

> **Çözüm:** Bölüm 8.3'teki diyagram: `yer = 1`, `I = 2..N` için `dizi[I] < dizi[yer]` ise `yer = I`; sonunda `yer` ve `dizi[yer]` yazdırılır. Sonuç: yer 2, değer 1.

## Dersin Toparlaması

Bu derste önce sayı oyunundaki "rakamlar birbirinden farklı mı" problemi çözüldü: sayı `mod 10` ve `div 10` ile rakamlarına ayrılıp diziye kondu, rakamlar iç içe iki `while` ile karşılaştırıldı, ilk diyagramdaki hatalar (son basamak, `J` artışı, `K = J + 1`, doğru döngü sınırı) birlikte düzeltildi ve kodu yazıldı. Ardından bir diziyi sayaç olarak kullanan, iç içe döngüleri tek döngüye indiren daha verimli çözüm gösterildi; bu, biraz bellek harcayarak işlem sayısını azaltmanın bir örneğiydi. Sonra asal sayı testi basit hâlinden başlayarak yarıya kadar deneme, çift sayıları atlama ve karekök sınırıyla iyileştirildi; $N$'e kadar bütün asal sayıları bulan eleme yöntemi tanıtıldı.

Dersin son kısmında diziler üzerindeki temel işlemler (ekleme, silme, güncelleme, arama, min, max, sıralama, ortalama) konuşuldu; silme ve sıralı dizide ekleme için kaydırma mantığı, en küçük elemanın değerini ve yerini bulan akış diyagramları çizildi. Hoca sonraki derslerde arama, silme, güncelleme ve ekleme üzerine örnekler yapılacağını, ardından karakter dizilerine (string), iki boyutlu dizilere (matrisler) ve daha sonra sıralama ve arama algoritmalarına geçileceğini söyledi; sıralı veriyle çalışmanın bazı problemlerde adım sayısını ne kadar azalttığı orada görülecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
