# Ders 26 Çalışma Özeti

## Genel Konular

- Monte Carlo benzetimi: kumarbaz problemi
  - Kumarbaz her oyunda $p$ olasılıkla 1 TL kazanır, $1-p$ olasılıkla 1 TL kaybeder. Oyuna $n$ lira ile girer; elindeki para ya $m+n$ olana ya da 0 olana kadar oynamaya devam eder (ekrandan, 00:10:00).
  - Soru, $m+n$ lira ile eve dönme olasılığıdır. Formül çıkarmak yerine süreç programla çok kez (örneğin 10.000 kez) tekrarlanır ve kazanılan oyunların oranı hesaplanır.
  - Önce tek bir oyunun akış diyagramı çizilir, sonra bu süreç $K$ kez tekrarlanan bir döngünün içine alınır.
- Tek oyunun benzetimi (akış diyagramı)
  - Girdi: $m$, $n$, $p$. $h = m+n$ ayrı bir değişkende tutulur, çünkü $n$ oyun boyunca değişir (ekrandan, 00:20:00).
  - Döngü koşulu: $n < h$ ve $n > 0$. İçeride `rand() > p` ise para 1 azalır, değilse 1 artar. `rand()` 0 ile 1 arasında rastgele sayı üretir.
  - İstenirse her adımdaki para bir `R` dizisinde tutulur (`t` indisi). Sürecin kaç adım süreceği bilinmediği için dizi en büyük boyutla açılır.
  - Kuramsal olarak oyun hiç bitmeyebilir (sürekli kazan-kaybet), pratikte bu olmaz.
- $K$ oyunluk benzetim ve sonuçlar
  - Girdiye $K$ (deneme sayısı) eklenir, `kaz = 0` ile başlanır. Her oyunun başında eldeki para yeniden $n$ yapılır; oyun bitince para $h$'ye eşitse `kaz` 1 artar. Sonunda `kaz / K` yazdırılır.
  - $p = 0.473$ ile hocanın daha önce çalıştırdığı sonuçlar tabloda verildi (ekrandan, 00:50:00). Sonuç $n$'den neredeyse bağımsızdır; $m$ büyüdükçe olasılık üstel olarak düşer.
  - Formül: $\text{sonuç} \le \left(\dfrac{p}{1-p}\right)^m$. Hocanın sözüyle "kasa her zaman kazanır".
- Matris çarpımı ve karmaşıklığı
  - $A$ ($n \times m$) ile $B$ ($m \times p$) çarpılabilir, sonuç $C$ ($n \times p$) olur. Üç iç içe döngü ile `sum = sum + A[i][k] * B[k][j]` hesaplanır.
  - Karmaşıklık $O(n \cdot m \cdot p)$, kare matrislerde $O(n^3)$. Kare matrisler için $n^3$'ün altında ama $n^2$'nin biraz üstünde karmaşıklığa sahip karmaşık algoritmalar vardır.
- Matris çarpım sırası
  - $A(10,30)$, $B(30,5)$, $C(5,60)$ için $(AB)C$ maliyeti $1500 + 3000 = 4500$, $A(BC)$ maliyeti $9000 + 18000 = 27000$ işlemdir (ekrandan, 01:00:00).
  - Sonuç aynıdır ama maliyet çok farklıdır. $k$ matrisin en az maliyetli çarpım sırasını bulmak çalışma sorusu olarak bırakıldı.
- Harici birleştirmeli sıralama (external merge sort)
  - 1 GB RAM ile diskteki 9 GB veriyi sıralama problemi (ekrandan, 01:05:00).
  - Veri RAM'e sığan 9 parçaya bölünür; her parça RAM'e alınıp yerinde (örneğin quicksort ile) sıralanır ve diske geri yazılır.
  - Sonra her parçanın ilk %10'u (100 MB) RAM'e alınır; kalan 100 MB çıkış tamponudur. İki sıralı diziyi birleştirme mantığı 9 diziye genişletilir; tampon dolunca diske yazılır, bir dizi bitince o parçanın sonraki %10'u getirilir (ekrandan, 01:10:00).
  - Diskte veri kadar ek alan gerekir; yerinde sıralama yapılamaz.
- Yüksek karmaşıklıklı problemler ve sezgisel algoritmalar
  - Alt küme toplamı: $n$ sayı içinde toplamı $K$ olan alt küme var mı? Örnek: $\{-6, 12, -3, 9, 42\}$ içinde $\{-6, -3, 9\}$ toplamı 0'dır (ekrandan, 01:15:00).
  - Gezgin satıcı: $n$ şehrin hepsine uğrayan en kısa rota. Tüm sıralamaları denemek $n!$ karmaşıklığındadır.
  - Sezgisel algoritma: arama uzayının tamamı yerine bir parçasında arama yapma kuralları tanımlamak. Gezgin satıcı için "rastgele bir şehirden başla, her adımda en yakın gidilmemiş şehre git" kuralı $O(n^2)$'dir ama en kısa rotayı garanti etmez (ekrandan, 01:20:00 ve 01:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- $h = m+n$ neden ayrı değişkende tutulur
  - $n$ (eldeki para) döngüde sürekli değiştiği için hedef değer başta sabitlenmelidir. Çok oyunlu benzetimde de eldeki para her oyunun başında yeniden $n$ yapılmalıdır; problemin "küçük triki" budur.
- `rand() > p` koşulunun anlamı
  - 0-1 arası düzgün rastgele sayının $p$'den büyük olma olasılığı $1-p$'dir; bu yüzden doğru tarafı kaybı, yanlış tarafı kazancı temsil eder.
- Kasa her zaman kazanır
  - Kazanma olasılığını oyuna kaç parayla girildiği değil, $m$ ve $p$ belirler. $p < 0.5$ iken $m$ arttıkça olasılık üstel olarak düşer. Ortalama durumda bu tür oyunları oynamanın matematiksel bir anlamı yoktur.
- Matris çarpımı pahalıdır, sıra önemlidir
  - Kare olmayan matrislerde çarpım sırası maliyeti çok değiştirir; tüm matrisler aynı boyutlu kare matrislerse sıra fark etmez.
- External merge sort RAM ile diskin birlikte kullanımını gösterir
  - Diskten işlemciye doğrudan yol yoktur; veri önce RAM'e alınır. Hız farkı büyük birimleri doğrudan bağlamak verimli değildir.
- Sezgisel algoritmaların bedeli optimallikten verilen ödündür
  - Optimum çözümün şart olmadığı yerde, çok uzun süren kesin çözüm yerine hızlı ve yeterince iyi çözüm tercih edilir. Hoca bunu "attığın taş ürküttüğün kurbağaya değmeli" sözüyle anlattı.

## Kısa Tekrar Notları

- Kumarbaz: $p$ ile +1, $1-p$ ile −1; $n$ ile başla, $m+n$ ya da 0'da dur. Monte Carlo: $K$ oyun oyna, `kaz/K` oranını yazdır.
- $p = 0.473$: $(n,m) = (100,10) \to 0.339$; $(1000,10) \to 0.341$; $(100,20) \to 0.115$; $(100,100) \to 0.000018$.
- Sonuç $\le (p/(1-p))^m$; $n$'nin etkisi yok, $m$ ve $p$ belirleyici.
- Matris çarpımı $O(nmp)$, kare matriste $O(n^3)$.
- $(AB)C = 4500$, $A(BC) = 27000$ işlem: çarpım sırası maliyeti değiştirir.
- External merge sort: parçala, her parçayı RAM'de sırala ve yaz, sonra çok yollu birleştir; çıkış tamponu dolunca diske yaz.
- Gezgin satıcı kaba kuvvet $n!$; en yakın komşu sezgiseli $O(n^2)$ ama optimal değil.
- Örnek grafikte B'den en yakın komşu rotası B-C-D-E-F-A = 10; daha kısası B-A-B-C-D-E-F = 8; A'dan A-B-C-D-E-F = 6.

## Detaylı Açıklamalar

Dersin ilk bölümünde bir Monte Carlo benzetimi kuruldu. Kumarbaz her turda $p$ olasılıkla 1 TL kazanıyor, $1-p$ olasılıkla 1 TL kaybediyor. Oyuna $n$ lira ile giriyor ve ya parası $m+n$ olana ya da hiç parası kalmayana kadar oynuyor. Amaç bu olasılığın formülünü bulmak değil, süreci programla çok kez tekrarlayıp kazanma oranını ölçmekti. Hoca önce tek oyunu çözdü: $m$, $n$, $p$ okunur, $t = 0$ ve $h = m + n$ atanır; `n < h && n > 0` olduğu sürece `rand() > p` sorulur, doğruysa $n$ bir azalır, yanlışsa bir artar; ardından $t$ artırılır ve `R[t] = n` ile süreç kaydedilir (ekrandan, 00:20:00). Döngüden çıkıldığında para ya 0 ya da $h$'dir.

Çok oyunlu sürümde girdiye $K$ eklenir, `kaz = 0` yapılır ve tek oyun bir `for` döngüsüne ($i = 1, \dots, K$) alınır (ekrandan, 00:25:00). Her oyunun başında eldeki para yeniden $n$ yapılır; oyun bittiğinde para $h$'ye eşitse oyun kazanılmıştır ve `kaz` bir artar. Sonunda `kaz / K` yazdırılır. Aşağıdaki C kodu derste yazılmadı; akış diyagramından ajan tarafından çevrildi, `gcc -Wall` ile derlendi ve `10 100 0.473 100000` girdisiyle yaklaşık 0.340 sonucu verdi (derste bulunan 0.339 ile uyumlu).

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int m, n, K, i, en, h, kaz;
    double p, r;

    srand((unsigned) time(NULL));
    printf("m, n, p, K: ");
    scanf("%d %d %lf %d", &m, &n, &p, &K);

    kaz = 0;
    h = m + n;
    for (i = 1; i <= K; i++) {
        en = n;                       /* her oyuna n lira ile girilir */
        while (en < h && en > 0) {
            r = (double) rand() / ((double) RAND_MAX + 1.0); /* [0,1) */
            if (r > p) {
                en = en - 1;          /* 1-p olasilikla kaybeder */
            } else {
                en = en + 1;          /* p olasilikla kazanir */
            }
        }
        if (en == h) {
            kaz = kaz + 1;
        }
    }
    printf("Kazanma orani: %f\n", (double) kaz / K);
    return 0;
}
```

Hocanın $p = 0.473$ ile elde ettiği sonuçlar şunlardır (ekrandan, 00:50:00): $n=100, m=10$ için 0.339; $n=1000, m=10$ için 0.341; $n=100, m=20$ için 0.115; $n=200, m=20$ için yaklaşık 0.114; $n=1000, m=20$ için 0.115; $n=100, m=100$ için 0.000018; $n=1.000.000, m=100$ için 0.0000201. Bir öğrencinin yorumu ve hocanın onayıyla sonuç, oyuna kaç parayla girildiğine bağlı değildir; $m$ ve $p$ belirler. Hoca sonucun $(p/(1-p))^m$'den küçük ya da ona yaklaşık eşit olduğunu yazdı ve konuyu "Gambler's Dilemma" adıyla aratmayı önerdi.

> **Ders sonrası not:** Bu problem literatürde büyük olasılıkla "Gambler's ruin" (kumarbazın iflası) adıyla bilinir. Python ile hesaplanan kesin değerler $(100,10) \to 0.3392$, $(100,20) \to 0.1151$, $(100,100) \to 0.0000202$'dir; tablodaki 0.000018 benzetimin rastlantı hatasıyla uyumludur. Üst sınır $(p/(1-p))^m$ yalnız $p < 0.5$ iken anlamlıdır.

İkinci bölümde standart matris çarpımı hatırlatıldı: $A$ $n \times m$, $B$ $m \times p$ ise $C$ $n \times p$ olur; $i$ ($1..n$), $j$ ($1..p$) ve $k$ ($1..m$) döngüleriyle `sum = sum + A[i][k] * B[k][j]` hesaplanır, `C[i][j] = sum` yazılır. Karmaşıklık $O(n \cdot m \cdot p)$'dir. Üç matris $A(10,30)$, $B(30,5)$, $C(5,60)$ için $(AB)C$: $10 \cdot 30 \cdot 5 = 1500$ ve $10 \cdot 5 \cdot 60 = 3000$, toplam 4500; $A(BC)$: $30 \cdot 5 \cdot 60 = 9000$ ve $10 \cdot 30 \cdot 60 = 18000$, toplam 27000 işlem (ekrandan, 01:00:00). Dört matriste $((AB)C)D$, $(A(BC))D$, $(AB)(CD)$ gibi daha çok sıra vardır; en iyi sırayı bulmak çalışma sorusu olarak bırakıldı.

Üçüncü bölüm external merge sort idi. 1 GB RAM ile 9 GB veri sıralanacaktır. Veri 9 parçaya bölünür, her parça RAM'e alınıp yerinde sıralanır ve diske yazılır. Sonra her parçanın ilk 100 MB'ı RAM'e alınır (RAM'in %90'ı), kalan 100 MB çıkış tamponu olur. Dokuz dizinin başındaki en küçük eleman sırayla tampona yazılır; tampon dolunca diskte yeni bir alana yazılır; bir dizinin RAM'deki parçası bitince o parçanın sonraki 100 MB'ı getirilir (ekrandan, 01:10:00). Bir öğrencinin sorusu üzerine, bir parça tamamen bitince boşalan yerin diğer parçaların verisiyle doldurulabileceği, bunun uygulamaya bağlı bir hızlandırma olduğu söylendi.

Son bölümde yüksek karmaşıklıklı problemler ve sezgisel algoritmalar ele alındı. Gezgin satıcı probleminde $n$ şehrin tüm sıralamalarını denemek $n!$'dir. En yakın komşu sezgiseli rastgele bir şehirden başlar ve her adımda gidilmemiş en yakın şehre gider; $(n-1) + (n-2) + \dots + 1$ karşılaştırma ile $O(n^2)$ karmaşıklığa iner, ama en kısa rotayı garanti etmez. Ekrandaki grafikte (A-B: 2, B-C: 1, C-D: 1, D-E: 1, E-F: 1, A-F: 6) B'den başlayan sezgisel rota B-C-D-E-F-A = 10, daha kısa olan B-A-B-C-D-E-F = 8, A'dan başlayan A-B-C-D-E-F = 6'dır (ekrandan, 01:30:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
