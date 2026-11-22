# Ders 6 Çalışma Özeti

## Genel Konular

- İki değişkenin değerlerini takas etme (swap)
  - Amaç: $a = 5$, $b = 3$ iken sonunda $b = 5$, $a = 3$ olması (ekrandan, 00:10:00).
  - Doğrudan `B = A` yazmak B'nin eski değerini kaybettirir, bu yüzden yanlıştır.
  - Klasik çözüm üçüncü bir değişken kullanır: `temp = A`, `A = B`, `B = temp` (ekrandan, 00:15:00).
  - Ek değişkensiz çözüm (bir öğrencinin önerisi): `b = a + b`, `a = b - a`, `b = b - a` (ekrandan, 00:15:00). $a = 2$, $b = 4$ örneğinde adım adım denendi ve çalıştığı görüldü.
  - Karşılaştırma: ikinci yöntem bir değişkenlik bellek kazandırır ama üç atamaya ek olarak üç aritmetik işlem yapar, yani daha yavaştır. Değişkenler çok büyük yapılar (struct) ise bellek kazancı anlamlı olabilir.
- $a + b + c = 1000$, $a^2 + b^2 = c^2$, $a, b, c > 0$ olan tam sayı üçlüleri (ekrandan, 00:30:00)
  - Bir öğrenci matematikle çözdü: 8-15-17 dik üçgeninin katları alınır, $40k = 1000$ ise $k = 25$, üçlü 200, 375, 425 olur.
  - Ham (kaba kuvvet) çözüm: $i$, $j$, $k$ için iç içe üç for (1'den 1000'e), içte `i*i + j*j == k*k && i + j + k == 1000` kontrolü (ekrandan, 00:30:00). En içteki kontrolden $10^9$ (1 milyar) kez geçilir.
  - İyileştirme 1: üçüncü döngü kaldırılır, `k = 1000 - i - j` hesaplanır, yalnız `i*i + j*j == k*k` kontrol edilir (ekrandan, 00:45:00). Geçiş sayısı 1 milyona düşer, yani 1000 kat hızlanma.
  - İyileştirme 2: dış döngü 998'e, iç döngü $1000 - i$'ye kadar gider (ekrandan, 00:45:00). Geçiş yaklaşık 500 bine iner (2 kat). Bu sınırlarla $k$ negatif olmaz; $j$ en çok $1000 - i$ olduğunda $k = 0$ olabilir, bu yüzden bir öğrenci $999 - i$ önerdi.
  - Bir öğrencinin önerisi: $a, b < c$ olduğundan döngü sınırları 500'e indirilebilir; bu da yaklaşık 2 kat daha kazandırır.
- Sayı üçgeninde 1000. satırın son elemanı (ekrandan, 01:05:00)
  - Üçgen: 1. satır 1; 2. satır 2 3; 3. satır 4 5 6; 4. satır 7 8 9 10; ... $i$. satırda $i$ eleman vardır.
  - Ham çözüm: `t = 0`, dış for $i = 1..N$, iç for $j = 1..i$, içte `t = t + 1`, sonunda `t` yazdırılır (ekrandan, 01:10:00). Karmaşıklık yaklaşık $N \cdot N/2 = N^2/2$.
  - Öğrenci çözümleri: önceki satır sonuna satır numarasını ekleyen tek döngülü çözüm ($N$ mertebesi) ve döngüsüz çözüm.
  - En iyi çözüm: $N$. satırın son elemanı $1 + 2 + \dots + N$'dir, yani `t = N*(N+1)/2`. Sabit sayıda (yaklaşık 3) işlem. $N = 1000$ için 500500.
- Diziyi ters çevirme (ekrandan, 01:20:00)
  - 5 elemanlı dizide 1↔5, 2↔4 takas edilir, ortadaki eleman yerinde kalır. Genel kural: $i$. eleman $N - i + 1$. elemanla takas edilir.
  - Önce $N$, sonra for ile elemanlar tek tek okunur. Takas döngüsü $i = 1$'den $\lfloor N/2 \rfloor$'ye kadar gider: `temp = A[i]`, `A[i] = A[N-i+1]`, `A[N-i+1] = temp`.
  - Döngü $N$'e kadar giderse her çift iki kez takas edilir ve dizi eski haline döner.
- Bir dizinin palindrom olup olmadığı (ekrandan, 01:25:00 ve 01:40:00)
  - Palindrom, tersten okunuşu aynı olan dizidir: ALLA ve 1441 palindromdur, 144 değildir.
  - İlk fikir: ters çevrilmiş kopyayı yeni bir diziye yazıp iki diziyi karşılaştırmak. Ek dizi ve yaklaşık $2N$ işlem gerekir.
  - Daha iyisi: dizi kendi üzerinde kontrol edilir, `A[i] == A[N-i+1]` karşılaştırması $\lfloor N/2 \rfloor$ kez yapılır.
  - İlk uyuşmazlıkta durmak gerektiği için for yerine while kullanılır: `i = 1`; `A[i] == A[N-i+1] && i <= ⌊N/2⌋` olduğu sürece `i = i + 1`. Çıkışta $i$'ye bakılarak "palindrom" ya da "değil" yazılır (ekrandan, 01:40:00).
  - Karmaşıklık: kontrol en kötü durumda $N/2$; diziyi okumak $N$ olduğundan algoritmanın tamamı $N$ mertebesindedir.
- 6 basamaklı palindrom sayıları yazdırma (ekrandan, 01:50:00)
  - Ham çözüm: $i$ 100.000'den 999.999'a döner; basamaklar $a = \lfloor i/100000 \rfloor$, ..., $f = i \bmod 10$ ile ayrılır; `a == f`, `b == e`, `c == d` ise $i$ yazdırılır. Maliyet $900.000 \cdot K$ ($K$ sabit sayıda işlem). Bir sayaçla (`t = t + 1`) palindromların sayısı da bulunur (ekrandan, 02:00:00).
  - Kontrol yerine üretme: $a = 1..9$, $b = 0..9$, $c = 0..9$ için `sayi = 100000*a + 10000*b + 1000*c + 100*c + 10*b + a` (ekrandan, 02:10:00). Maliyet $900 \cdot K$.
  - 7 basamaklı için ortaya dördüncü bir döngü ($d = 0..9$) eklenir: `sayi = 1000000*a + 100000*b + 10000*c + 1000*d + 100*c + 10*b + a` (ekrandan, 02:25:00). Maliyet $9000 \cdot K$.
- R basamaklı palindrom sayılarının adedi (ekrandan, 02:15:00 ve 02:30:00)
  - Tablo: R=1 → 9, R=2 → 9, R=3 → 90, R=4 → 90, R=5 → 900, R=6 → 900, R=7 → 9000, R=8 → 9000, R=9 → 90000.
  - Genel formül: $9 \cdot 10^{\lfloor (R-1)/2 \rfloor}$ (ekrandan, 02:30:00). Derste $\lceil R/2 \rceil - 1$ üssü de doğru bulundu.
  - Algoritma içinde kullanıcının girdiği R'ye göre değişken sayıda iç içe döngü oluşturulamaz. Bunun yerine sayının ilk yarısı tek bir döngüyle üretilir (ör. 6 ve 7 basamak için $i = 100..999$), ardından R tekse araya bir rakam $j$ konup $i$'nin tersi eklenir (ekrandan, 02:25:00).
  - $10^{n}$'i düz çarpmayla hesaplamak $n$ adım sürer; formülün maliyeti bu yüzden sabit değil, R'ye bağlıdır (yaklaşık $R/2$ çarpma). İleride özyinelemeli fonksiyonlarla $x^n$'in $\log_2 n$ adımda hesaplanacağı söylendi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Önce çöz, sonra iyileştir
  - Bir probleme önce ham (kaba kuvvet) bir çözüm yazılır. Sonra problem analiz edilir, örüntüler ve matematiksel özellikler kullanılarak çözüm adım adım iyileştirilir.
  - En büyük kazançlar matematikten gelir: bir döngünün tamamen kaldırılması 1000 katlık, Gauss formülü ise $N$'den bağımsız sabit sayıda işlem sağladı.
- Karmaşıklık en içteki noktadan sayılır
  - Bir algoritmanın ne kadar karmaşık olduğunu görmek için en çok geçilen yere (en içteki döngünün gövdesine) kaç kez geçildiğine bakılır.
  - $N^2$'den $N$'e inmek çok iyi bir gelişmedir ($N$ bir milyonsa bir milyon kat); sabit sayıya inmek yapılabilecek en iyi şeydir çünkü hız $N$'e hiç bağlı kalmaz.
- Sabit sayıda işlem ne demektir
  - Sabit sayıda işlem, kullanıcının girdiği değere bağlı olmayan sayıda işlem demektir. Gauss formülü $N = 10$ için de $N = 10^9$ için de 3 işlemdir.
  - 100 elemanlı bir diziyi $N^2$ adımda sıralamak somut olarak 10.000 adım tutar ama bu algoritmayı sabit karmaşıklıklı yapmaz; dizi uzarsa işlem sayısı değişir.
- Ham çözüm de yazılabilmeli
  - Matematikle çözülemeyen durumlarda bilgisayar kaba kuvvetle sonuca ulaşabilir; ama önce bu çözüm kurulmalı, sonra kısaltılmalıdır.
- Döngü sınırına dikkat
  - Dizi ters çevirmede ve palindrom kontrolünde döngü $\lfloor N/2 \rfloor$'de durmalıdır. Akış diyagramında alta yuvarlama $\lfloor \cdot \rfloor$ ile, üste yuvarlama $\lceil \cdot \rceil$ ile gösterilebilir.
  - Dizi akış diyagramında da elemanlar for döngüsüyle tek tek okunarak gösterilmelidir, çünkü C kodunda da öyle okunur; ileride matrisler iç içe döngülerle okunacaktır.

## Kısa Tekrar Notları

- Takas: `temp = A; A = B; B = temp`. Ek değişkensiz: `b = a + b; a = b - a; b = b - a` (daha az bellek, daha çok işlem).
- Üçlü problemi: üç döngü $10^9$, iki döngü + `k = 1000 - i - j` $10^6$, sınırları daraltınca yaklaşık $5 \cdot 10^5$. Tek çözüm: 200, 375, 425.
- Sayı üçgeninde $N$. satırın son elemanı $N(N+1)/2$; $N = 1000$ için 500500. Karmaşıklık $N^2/2 \to N \to$ sabit.
- Diziyi ters çevirme: $i \leftrightarrow N - i + 1$, $i = 1..\lfloor N/2 \rfloor$.
- Palindrom kontrolü: while ile, ilk uyuşmazlıkta çık; en kötü durumda $N/2$ karşılaştırma.
- 6 basamaklı palindromlar: kontrol $900.000 \cdot K$, üretme $900 \cdot K$. 7 basamak: $9000 \cdot K$.
- R basamaklı palindrom sayısı: $9 \cdot 10^{\lfloor (R-1)/2 \rfloor}$.
- Karmaşıklık en içteki döngü gövdesine kaç kez girildiğiyle ölçülür.

## Detaylı Açıklamalar

- **Takas yöntemlerinin karşılaştırılması.** Klasik takasta A'nın değeri geçici bir kutuya (temp) alınır, A'ya B yazılır, B'ye de temp'teki eski A yazılır; bu üç atamadır. Toplama-çıkarma yönteminde $a = 2$, $b = 4$ için: `b = a + b` ile $b = 6$; `a = b - a` ile $a = 6 - 2 = 4$ (B'nin eski hali); `b = b - a` ile $b = 6 - 4 = 2$ (A'nın eski hali). Sonuç $a = 4$, $b = 2$ olur. Hoca bunun iş görüşmelerinde sorulan klasik bir soru olduğunu söyledi. Bellek kazancı tek değişken kadardır, buna karşılık üç ek aritmetik işlem yapılır.

- **Üçlü probleminde iyileştirme zinciri.** Ham akış diyagramında üç iç içe döngü ve iki koşullu bir karar kutusu vardır. Bir öğrenci üçüncü değişkeni döngüyle aramak yerine $k = 1000 - i - j$ olarak hesaplamayı önerdi; toplam koşulu zaten sağlandığı için yalnız Pisagor koşulu kontrol edilir. Bu, bir for'u tamamen ortadan kaldırdığı için 1000 kat kazanç sağlar. Sonra iç döngünün üst sınırı $1000 - i$ yapıldı: $i = 1$ iken $j = 1..999$, $i = 2$ iken $j = 1..998$, ..., $i = 998$ iken $j = 1..2$ (ekrandan, 00:45:00). Böylece geçiş sayısı yaklaşık yarıya iner. Bu sınırlarda $k$ negatif olamaz, ancak $j = 1000 - i$ olduğunda $k = 0$ olur; bu yüzden üst sınır $999 - i$ alınabilir.

- **Sayı üçgeni ve Gauss formülü.** 4. satırın son elemanı $10 = 1+2+3+4$, 5. satırın son elemanı $15 = 1+\dots+5$'tir. Demek ki $N$. satırın son elemanı ilk $N$ doğal sayının toplamıdır ve $N(N+1)/2$ formülüyle hiç döngü kullanmadan bulunur. İki döngülü çözümün karmaşıklığı $N^2/2$, tek döngülü öğrenci çözümünün $N$, formülün ise sabittir.

- **Palindrom kontrolünün akış diyagramı (ekrandan, 01:40:00).** START, $N$ okunur, for ile `A[i]` okunur. Sonra `i = 1` ve while kutusu: `A[i] == A[N-i+1] && i <= ⌊N/2⌋` doğru olduğu sürece `i = i + 1`. While'dan iki nedenle çıkılabilir: ya bir uyuşmazlık bulunmuştur ya da yarıya ulaşılmıştır. Çıkışta bir karar kutusuyla bunlar ayırt edilir ve "değil" ya da "palindrom" yazdırılır.
  - **Ders sonrası not:** Tahtadaki çıkış kontrolü `i < ⌊N/2⌋` ise "değil" biçimindedir. Bu kontrol, uyuşmazlık tam $i = \lfloor N/2 \rfloor$'de bulunduğunda yanlış sonuç verir: örneğin 1 2 3 1 dizisinde $i = 2$'de çıkılır, $2 < 2$ yanlış olduğundan dizi palindrom sanılır. Doğru kontrol `i <= ⌊N/2⌋` ise "değil", aksi halde "palindrom"dur (tüm çiftler eşleşirse döngü $i = \lfloor N/2 \rfloor + 1$ ile biter). Bu durum ajan tarafından python ve C ile denendi.
  - Derste C kodu yazılmadı; aşağıdaki çeviri ajan tarafından yazıldı, `gcc -Wall` ile derlendi ve 4 1 4 4 1 (palindrom), 3 1 4 4 (değil), 4 1 2 3 1 (değil), 3 1 2 1 (palindrom) girdileriyle denendi:

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

- **Kontrol etmek yerine üretmek.** 6 basamaklı palindromun yapısı $abccba$ olduğundan yalnız ilk üç basamak seçilir: $a$ 1–9 (ilk basamak sıfır olamaz), $b$ ve $c$ 0–9. Toplam $9 \cdot 10 \cdot 10 = 900$ sayı üretilir ve her biri doğrudan yazdırılır. Hoca, en içteki gövdedeki sabit işlemleri tek tek saymak yerine $K$ ile gösterdi; bu yüzden maliyet $900 \cdot K$, kontrol yönteminde $900.000 \cdot K$'dır. 7 basamakta ortadaki rakam serbesttir ama yine de bir değişken ve bir döngü ister; maliyet $9000 \cdot K$ olur. Bir öğrencinin "dördüncü döngü yerine son döngüde 10 işlemi elle yazalım" önerisine hoca, bunun karmaşıklığı değiştirmediğini, yalnız sabit sayıda denemenin anlamını bozduğunu söyledi.

- **R basamaklı palindrom adedi.** Tabloda adet iki basamakta bir 10 katına çıkar. Bu örüntüden $9 \cdot 10^{\lfloor (R-1)/2 \rfloor}$ formülü çıkarıldı; python ile R = 1..7 için tek tek sayılarak doğrulandı. Formülde sabit olmayan kısım $10$'un kuvvetidir: düz çarpmayla yaklaşık $R/2$ çarpma gerekir. Hoca, bu kuvvetin ileride özyinelemeli fonksiyonlarla logaritmik adımda hesaplanacağını belirtti.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
