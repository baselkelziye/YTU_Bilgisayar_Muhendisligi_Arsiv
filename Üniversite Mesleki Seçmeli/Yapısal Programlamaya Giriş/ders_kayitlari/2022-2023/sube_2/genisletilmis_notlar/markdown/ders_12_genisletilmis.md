# Ders 12 Genişletilmiş Notu: İteratif Algoritmaların Analizi, Rastgele Sayı Üretimi ve Simülasyon Örnekleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İteratif algoritmaların analizi ve gerekli matematik
- 2. Tek döngülü algoritmalarda değer ve order analizi
- 3. İç içe for döngüleri
- 4. Çarpılarak büyüyen while döngüleri
- 5. if içeren döngüler ve bağımlı döngüler
- 6. Ek döngü örnekleri
- 7. Desen çizdiren algoritma ve rastgelelik
- 8. C'de rastgele sayı üretimi
- 9. 52 kartı karıştırma
- 10. İki uniform sayının toplamı ve çan eğrisi
- 11. Rastgele gezen robot
- 12. Monte Carlo yöntemiyle pi sayısı
- Örnek Sorular
- Dersin Toparlaması

## 1. İteratif algoritmaların analizi ve gerekli matematik

Ders, bir önceki haftada yetişmeyen "iteratif algoritmaların analizi" konusuyla başlar. İteratif algoritma, döngü (çoğunlukla `for` ya da `while`) içeren algoritmadır. Bu konudaki örneklerde döngünün içinde genellikle `if` yoktur; döngü gövdesinde yalnız birkaç atama satırı bulunur. Bu satırlar iki açıdan incelenir:

- **Değer analizi:** Döngü bitince bir değişkenin (örneklerde `T`) değeri kaç olur?
- **Karmaşıklık analizi:** Döngü kaç kez döner, içindeki işlem kaç kez tekrarlanır?

Her iki analizde de kod toplam sembolüne ($\sum$) çevrilir. $\sum_{i=1}^{10} i$ ifadesinde $i$ indis (döngü değişkeni gibi), alt ve üst sınır döngünün başlangıç ve bitişidir; sonuç $1+2+\dots+10$'dur. Örneğin $\sum_{i=1}^{3}(2+i^2)$ ifadesinde $2$ sabittir, $i^2$ terimi $i=1,2,3$ için hesaplanıp toplanır. Genel olarak $\sum_{i=a}^{b}f(i)=f(a)+f(a+1)+\dots+f(b)$ ($a\le b$).

### 1.1 Toplam eşitlikleri

Slaytta bir ders sitesinden alınmış "Useful summation identities" tablosu gösterilir (ekrandan, 00:10:00):

| No | Kural | Slayttaki örnek |
|---|---|---|
| 1. Toplamı bölme | $\sum_{i=a}^{b}(x+y)=\sum_{i=a}^{b}x+\sum_{i=a}^{b}y$ | $\sum_{i=1}^{10}(5+7)=120=50+70$ |
| 2. Sınırı ayarlama | $\sum_{i=a}^{b}f(i)=\sum_{i=0}^{b}f(i)-\sum_{i=0}^{a-1}f(i)$ | $\sum_{i=5}^{8}i=\sum_{i=0}^{8}i-\sum_{i=0}^{4}i$ |
| 3. Sabiti dışarı alma | $\sum_{i=a}^{b}c\,f(i)=c\sum_{i=a}^{b}f(i)$ | $\sum_{i=1}^{5}10n=10\sum_{i=1}^{5}n$ |
| 4. Sabitin toplamı | $\sum_{i=0}^{n-1}c=cn$ | $\sum_{i=0}^{5-1}10=50$ |
| 5. Gauss | $\sum_{i=0}^{n-1}i=\frac{n(n-1)}{2}$ | $\sum_{i=0}^{10-1}i=\frac{10\cdot9}{2}=45$ |
| 6. Kareler toplamı | $\sum_{i=0}^{n-1}i^2=\frac{n(n-1)(2n-1)}{6}$ | $\frac{10\cdot9\cdot19}{6}=285$ |
| 7. Sonlu geometrik seri ($x\ne1$) | $\sum_{i=0}^{n-1}x^i=\frac{x^n-1}{x-1}$ | $\sum_{i=0}^{9}5^i=\frac{5^{10}-1}{4}=2441406$ |
| 8. Sonsuz geometrik seri ($-1<x<1$) | $\sum_{i=0}^{\infty}x^i=\frac{1}{1-x}$ | $\sum_{i=0}^{\infty}(1/2)^i=2$ |

Hoca birkaç noktanın altını çizer:

- Sınır ayarlama, örneğin 3'ten ya da 5'ten başlayan bir toplamı doğrudan hesaplamak zor olduğunda kullanılır: 0'dan $b$'ye toplamdan 0'dan $a-1$'e toplam çıkarılır.
- Gauss formülü bilinen $\frac{n(n+1)}{2}$'dir; tablodaki üst sınır $n-1$ olduğu için $\frac{(n-1)n}{2}$ biçimindedir. Kareler toplamında da üst sınır $n$ alınırsa formül $\frac{n(n+1)(2n+1)}{6}$ olur.
- Geometrik seride ardışık terimler arasındaki çarpan sabittir (1, 2, 4, 8, ... gibi). Seri sonsuz olursa ve $x>1$ ise toplam sonsuza gider; bu soruya bir öğrenci sohbetten "sonsuz olur" diye doğru cevap verir. $-1<x<1$ ise toplam $\frac{1}{1-x}$'e yakınsar.

Bu sonuçlar python ile kontrol edildi (45, 285 ve 2441406 doğru).

### 1.2 Üs ve logaritma kuralları

Üslerle ilgili temel eşitlikler (üslerin çarpımı, ortak üs) bilindiği için geçilir. Logaritmada çarpım toplamaya, bölüm çıkarmaya döner, kuvvet başa gelir: $\log_b(x^y)=y\log_b x$. Ayrıca bir sayının üssünde logaritma varsa taban ile sayı yer değiştirebilir:

$$a^{\log_b c}=c^{\log_b a}$$

Hoca bunu $x=4^{\log_2 8}$ örneğiyle gösterir. İki tarafın 4 tabanında logaritması alınır: $\log_4 x=\log_2 8\cdot\log_4 4=\log_2 8=3$, buradan $x=4^3=64$ bulunur. Kural ile de $4^{\log_2 8}=8^{\log_2 4}=8^2=64$ çıkar (ara adım eklendi). Taban değiştirme kuralıyla ($\log_b x=\frac{\log_d x}{\log_d b}$) logaritma başka tabana taşınabilir; bunlar ileride kullanılacaktır.

### 1.3 Order gösterimi

Döngünün kaç kez döndüğü büyük O ile gösterilir: $O(n^2)$, "bu döngü en fazla $n^2$ mertebesinde döner" demektir. Hoca ayrıntıların sonraki dönemlerin derslerinde geleceğini söyler. Bu derste kodun yazılması gerekmez; amaç asimptotik analizdir.

## 2. Tek döngülü algoritmalarda değer ve order analizi

Slayttaki ilk soru (ekrandan, 00:20:00):

```text
T=0;
for i=1:N
    T=T+1;
end
```

MATLAB benzeri bu gösterimde `1:N` ifadesinde $N$ dahildir. C'de `for(i=0;i<n;i++)` yazılırsa $n$ dahil değildir ve toplam sembolünde üst sınır $n-1$ olur.

`T` sıfırdan başlar ve her turda 1 artar: $T=\sum_{i=1}^{N}1=1+1+\dots+1=N$. Terim sayısı $N$ olduğu için sonuç $N$'dir.

Slayttaki varyasyonlar:

- **`T=T+2`:** $2+2+\dots+2$, $N$ terim, $T=2N$.
- **`T=T+i`:** $T=\sum_{i=1}^{N}i=1+2+\dots+N=\frac{N(N+1)}{2}$.
- **`T=T+2i`:** $T=\sum_{i=1}^{N}2i=2\sum_{i=1}^{N}i=2\cdot\frac{N(N+1)}{2}=N(N+1)$.
- **`T=T+T`:** Başlangıç `T=0` ise sonuç her turda $0+0$ olur ve $T=0$. Bir öğrenci bunu doğru söyler. Başlangıç `T=1` yapılırsa değer her turda ikiye katlanır: 2, 4, 8, 16, ... Bu bir toplam değil, çarpımdır ve çarpım sembolüyle yazılır: $T=\prod_{i=1}^{N}2=2^N$. Çarpım sembolünde sabit dışarı çıkarken terim sayısı kadar kuvvet alır: $\prod_{i=1}^{N}2=2^N\prod_{i=1}^{N}1=2^N$. Örneğin $N=3$ için $T$ sırayla 2, 4, 8 olur.

Order için döngü içindeki işlem bir birimlik iş kabul edilir: $T(N)=\sum_{i=1}^{N}1=N$, yani $O(N)$. Hoca "order başka şey, değeri bulmak başka şey" der: `T=T+i` yazınca değer $\frac{N(N+1)}{2}$ olur ama döngü yine $N$ kez döner.

> **Hocanın vurgusu:** Dikkat edilecek iki şey alt ve üst sınırları doğru belirlemek ve tekrar sayısına göre eklenen değerin nasıl değiştiğini incelemektir.

## 3. İç içe for döngüleri

### 3.1 İç döngü sabit sınırlı: `j=1:N*N`

```text
T=0;
for i=1:N
    for j=1:N*N
        T=T+1;
    end
end
```

(ekrandan, 00:20:00)

İç içe toplamda önce içteki toplam çözülür: $\sum_{j=1}^{N^2}1=N^2$. $N^2$, $i$'ye bağlı olmadığından dıştaki toplamda sabittir: $T=\sum_{i=1}^{N}N^2=N^2+N^2+\dots+N^2=N^3$. Order: dış döngü $N$, iç döngü $N^2$ kez döner, $O(N\cdot N^2)=O(N^3)$ (ekrandan, 00:25:00). Hoca, iki döngü olmasına rağmen algoritmanın üç döngü varmış gibi $N^3$ iş yaptığını belirtir.

- **`T=T+i`:** İçteki toplamda $i$ sabittir: $\sum_{j=1}^{N^2}i=i\cdot N^2$. Dışta $T=\sum_{i=1}^{N}iN^2=N^2\cdot\frac{N(N+1)}{2}=\frac{N^3(N+1)}{2}$. Değer $N^4$ mertebesindedir ama order yine $O(N^3)$'tür.
- **`T=T+j`:** İçteki toplam $\sum_{j=1}^{N^2}j$'dir. Bir öğrenci önce $\frac{N^2(N^2-1)}{2}$ önerir; hoca "son terim çarpı son terimin bir fazlası bölü iki" kuralını hatırlatır: $\frac{N^2(N^2+1)}{2}$. Bu $i$'ye bağlı olmadığından $N$ ile çarpılır: $T=N\cdot\frac{N^2(N^2+1)}{2}=\frac{N^5+N^3}{2}$.

### 3.2 İç döngü dış değişkene bağlı: `j=1:i*i`

```text
T=0;
for i=1:N
    for j=1:i*i
        T=T+1;
    end
end
```

(ekrandan, 00:35:00)

İçteki toplam için bir öğrenci $\frac{i^2(i^2+1)}{2}$ der; hoca önce onaylar, sonra düzeltir: içeride $1+1+\dots+1$ toplanıyor, terim sayısı $i^2$'dir, yani içteki toplam $i^2$'dir. Dışta:

$$T=\sum_{i=1}^{N}i^2=\frac{N(N+1)(2N+1)}{6}$$

- **`T=T+i`:** İçteki toplam $\sum_{j=1}^{i^2}i=i\cdot i^2=i^3$ olur. Bir öğrenci "$i$ dışarı alınırsa $i^3$" diye bu sonuca ulaşır. $T=\sum_{i=1}^{N}i^3=\left(\frac{N(N+1)}{2}\right)^2$.
- **Order:** Dış döngü $N$, iç döngü $i^2$ kez döner; $\frac{N(N+1)(2N+1)}{6}$'nın en yüksek dereceli terimi $N^3$ olduğundan $O(N^3)$.
- **`T=T+j`:** İçteki toplam $1+2+\dots+i^2=\frac{i^2(i^2+1)}{2}$'dir. Bu durumda

$$T=\sum_{i=1}^{N}\frac{i^2(i^2+1)}{2}=\frac{1}{2}\left(\sum_{i=1}^{N}i^4+\sum_{i=1}^{N}i^2\right)$$

Hoca dördüncü kuvvetler toplamını şöyle verir (ekrandan, 00:45:00):

$$\sum_{i=1}^{N}i^4=\frac{N^5}{5}+\frac{N^4}{2}+\frac{N^3}{3}-\frac{N}{30}$$

Bu formül ve $T$'nin sonucu python ile $N=3,5,6$ için doğrulandı.

> **Ders sonrası not:** Hoca bu adımda kareler toplamını söylerken "bölü 2" dedi (00:35:12); doğrusu $\frac{N(N+1)(2N+1)}{6}$'dır. Slayttaki yazı da bölü 6'dır.

**Soru:** Bu formülleri ezberleyecek miyiz? **Cevap:** $\frac{n(n+1)}{2}$ genel olarak yeterlidir; kareler ve küpler toplamı da akılda tutulmalıdır. Beşinci dereceden açılımlar gibi şeyler sorulmaz.

Hoca, şimdiye kadarki döngülerin hep birer birer arttığını, ikişer ikişer artan `for` döngülerinin seri ve dizi konusuna fazla girdiği için pek sorulmadığını ekler.

## 4. Çarpılarak büyüyen while döngüleri

```text
T=0;
i=1;
while (i<=N)
    T=T+1;
    i=i*2;
end
```

(ekrandan, 00:45:00)

Döngü değişkeni birer birer artmaz: $i$ değerleri $1,2,4,\dots$ yani $2^0,2^1,2^2,\dots,2^k$'dir. Bu yüzden toplam sembolünün üst sınırına doğrudan $N$ yazılamaz; önce tekrar sayısı bulunur. Döngü $2^k\le N$ olduğu sürece döner. İki tarafın 2 tabanında logaritması alınırsa $k\le\log_2N$ olur.

`T=T+1` için $T=\sum 1$, terim sayısı tekrar sayısı kadardır, yani $\log_2 N$ mertebesindedir. Karmaşıklık da $O(\log_2N)$'dir; "1 için bulunan sonuç aynı zamanda karmaşıklığı verir".

Derste $N=32$ ve $N=33$ üzerinde tekrar sayısı tartışılır. Hoca $N=33$ için $i=1,2,4,8,16,32$ değerleriyle döngüye girildiğini sayar ve sonucu yukarı yuvarlamak gerektiğini söyler.

> **Ders sonrası not:** Hoca $N=32$ için döngünün 5 kez döndüğünü söyledi ve yukarı yuvarlamaya "taban fonksiyonu" dedi. `i<=N` koşulunda $N=32$ için de $i=1,2,4,8,16,32$ değerleriyle 6 tur atılır. Doğru tekrar sayısı $\lfloor\log_2N\rfloor+1$'dir: $N=31$ için 5, $N=32$ ve $N=33$ için 6 (python ile denendi). Yukarı yuvarlama tavan fonksiyonudur ($\lceil\cdot\rceil$), taban ($\lfloor\cdot\rfloor$) aşağı yuvarlar.

### 4.1 `T=T+i` durumu

Hoca önce $T=\sum_{i=1}^{\log_2N}i=\frac{\log_2N(\log_2N+1)}{2}$ yazar, sonra hatayı fark eder: $i$ birer birer artmıyor, toplama eklenen değerler $1,2,4,8,\dots$'dir. Bir öğrencinin "ikiye bölsek olmaz mı?" sorusuna hoca, değerlerin 2'nin kuvvetleri olduğu için olmayacağını söyler. Doğru ifade bir geometrik seridir:

$$T=\sum_{i=0}^{k}2^i,\qquad 2^k\le N$$

Hoca sonlu geometrik seri formülünü kullanır ve $2^{\log_2N}=N^{\log_2 2}=N$ eşitliğiyle sonucu $N-1$ olarak bulur. Ardından üst sınırın $n-1$ değil $n$ olduğu durumda formülde "artı bir" geleceğini belirtir (00:49:11).

> **Ders sonrası not:** $\sum_{i=0}^{k}2^i=2^{k+1}-1$'dir. Tekrar sayısı $\lfloor\log_2N\rfloor+1$ olduğundan $N$ ikinin kuvvetiyse $T=2N-1$ olur (örneğin $N=32$ için $1+2+\dots+32=63$; python ile denendi). Hocanın tahtada bulduğu $N-1$, formül $\sum_{i=0}^{n-1}$ için olduğu hâlde üst sınırın $\log_2 N$ alınmasından gelir.

### 4.2 Geometrik seri formülünün ispatı

$T=\sum_{i=0}^{n}a^i=a^0+a^1+\dots+a^n$ olsun. $a^0=1$ sol tarafa atılır: $T-1=a^1+a^2+\dots+a^n$. Sağ taraf $a$ parantezine alınır: $T-1=a(a^0+a^1+\dots+a^{n-1})$. Parantezdeki ifade $T$'den yalnız $a^n$ eksiktir, yani $T-a^n$'dir. Buradan

$$T-1=a(T-a^n)=aT-a^{n+1}\ \Rightarrow\ T(a-1)=a^{n+1}-1\ \Rightarrow\ T=\frac{a^{n+1}-1}{a-1}$$

Üst sınır $n-1$ alınırsa slayttaki $\frac{a^n-1}{a-1}$ biçimi çıkar.

### 4.3 $\sum i\,a^i$ toplamı

`T=T+j` gibi bir varyasyon $\sum i\,a^i$ biçiminde bir toplama yol açar (slaytta "$T=\sum_{i=0}^{N}iA^i$ nasıl bulunur?" sorusu, ekrandan, 00:45:00). Hoca yöntemi kısaca gösterir: $T=0\cdot a^0+1\cdot a^1+2a^2+3a^3+\dots+na^n$ yazılır, $aT$ hesaplanır (her terim $a$ ile çarpılır, son terim $na^{n+1}$ olur), $T-aT$ farkı alındığında $a+a^2+a^3+\dots$ biçiminde bir geometrik seri ve $-na^{n+1}$ terimi kalır. Geometrik seri formülü yerine konup $1-a$'ya bölünerek $T$ bulunur. Hoca bunların ezberlenecek şeyler olmadığını, merak edenin ispatına bakabileceğini söyler.

> **Ek bilgi (derste anlatılmadı):** Bu yolla elde edilen kapalı biçim $\sum_{i=0}^{n}i\,a^i=\frac{a-(n+1)a^{n+1}+na^{n+2}}{(1-a)^2}$'dir ($a\ne1$).

## 5. if içeren döngüler ve bağımlı döngüler

### 5.1 `if mod(j,i)==0`

```text
T=0;
for i=1:N
    for j=1:i*i
        if mod(j,i)==0
            T=T+1;
        end
    end
end
```

(ekrandan, 00:55:00)

İçeride `if` olduğu için doğrudan iki toplam yazılamaz; önce tabloyla örüntü aranır:

| $i$ | $j$ değerleri | koşulu sağlayan $j$'ler | eklenen |
|---|---|---|---|
| 1 | 1 | 1 | 1 |
| 2 | 1..4 | 2, 4 | 2 |
| 3 | 1..9 | 3, 6, 9 | 3 |
| 4 | 1..16 | 4, 8, 12, 16 | 4 |

Her $i$ için $i$ tane $j$ koşulu sağlar. Sonuç (ekrandan, 01:00:00):

$$T=\sum_{i=1}^{N}i=\frac{N(N+1)}{2}$$

**`T=T+1` else kolunda olsaydı:** "Tüm durum eksi aksi durum" mantığı kullanılır. İç döngü toplam $i^2$ kez döner, bunun $i$ tanesi `if` kolu olduğundan else kolu $i^2-i$ kez çalışır:

$$T=\sum_{i=1}^{N}(i^2-i)=\frac{N(N+1)(2N+1)}{6}-\frac{N(N+1)}{2}=\frac{N^3-N}{3}$$

Son sadeleştirme ara adım olarak eklendi ve python ile doğrulandı.

### 5.2 Önce $K$'yı hesaplayan algoritma

```text
T=0;
K=1;
for i=1:N
    K=K*2;
end
for i=1:N
    for j=1:K
        T=T+1;
    end
end
```

(ekrandan, 01:00:00)

İki bağımsız döngü vardır; birincisi ikincinin sınırını belirler. Birinci döngü bir çarpım: $K=\prod_{i=1}^{N}2=2^N$. İkinci bölümde:

- **`T=T+1`:** $T=\sum_{i=1}^{N}\sum_{j=1}^{2^N}1=\sum_{i=1}^{N}2^N=N\cdot2^N$. Bir öğrenci bunu doğru söyler.
- **`T=T+i`:** İçteki toplam $2^N\cdot i$'dir; $T=2^N\sum_{i=1}^{N}i=2^N\cdot\frac{N(N+1)}{2}$.
- **`T=T+j`:** İçteki toplam $1+2+\dots+2^N=\frac{2^N(2^N+1)}{2}$; $i$'ye bağlı olmadığı için $N$ ile çarpılır: $T=N\cdot\frac{2^N(2^N+1)}{2}$. Bunu bir öğrenci söyler.
- **Order:** Dış döngü $N$, iç döngü $2^N$ kez döner: $O(N\cdot2^N)$. İlk döngünün $N$ turu da eklenir ama daha küçük dereceli olduğu için ihmal edilir.

Bu sonuçlar python ile doğrulandı.

## 6. Ek döngü örnekleri

Hoca bir önceki konudan birkaç soruyu daha çözer (ekrandan, 01:35:00).

### 6.1 İç döngüsü `while (j<K)` olan algoritma

```text
T=0;
K=1;
for i=1:N
    K=K*2;
end
for i=1:N
    j=1;
    while (j<K)
        T=T+1;
        j=j*2;
    end
end
```

$K=2^N$'dir. $j$ değerleri $1,2,4,\dots$'dir. Hoca önce logaritma alırken bir karışıklık yapar, sınıfla birlikte düzeltir: $t$'inci tekrarda $j=2^{t-1}$ olur ve döngü $j<2^N$ olduğu sürece döner. $\log_2$ alınınca tekrar sayısı $k=\log_2 2^N=N$ bulunur. Bir öğrenci de $j$ ile tekrar sayısı arasındaki ilişkinin logaritmik olduğunu, $2^N$'e $N$'inci adımda varıldığını söyler. Sonuç:

$$T=\sum_{i=1}^{N}\sum_{j=1}^{N}1=N\cdot N=N^2$$

Bu sonuç python ile doğrulandı ($j<K$ koşulu katı olduğu için tam $N$ tur).

### 6.2 Üç iç içe döngü

```text
T=0;
for i=1:N
    for j=1:i
        for k=1:j
            T=T+1;
        end
    end
end
```

En içteki toplam $\sum_{k=1}^{j}1=j$. Ortadaki $\sum_{j=1}^{i}j=\frac{i(i+1)}{2}$ (bir öğrenci söyler). Dışta:

$$T=\frac{1}{2}\sum_{i=1}^{N}(i^2+i)=\frac{1}{2}\left(\frac{N(N+1)(2N+1)}{6}+\frac{N(N+1)}{2}\right)=\frac{N(N+1)(N+2)}{6}$$

Son sadeleştirme ara adım olarak eklendi (python ile doğrulandı). En büyük terim $N^3$ mertebesinde olduğundan order $O(N^3)$'tür.

> **Hocanın vurgusu:** Üç döngü olması algoritmanın $O(n^3)$ olduğu anlamına gelmez. Örneğin en içteki döngü $\log n$ kez dönüyorsa sonuç $O(n^2\log n)$ olabilir. Bu yüzden artışlar açıkça yazılıp `T=T+1` hesabı yapar gibi order hesaplanmalıdır.

### 6.3 `j=3:N` ve `j=i:N`

```text
T=0;
for i=1:N
    for j=3:N
        T=T+1;
    end
end
```

İçteki toplamın terim sayısı $N-2$'dir (bir öğrenci söyler). Bu $i$'den bağımsızdır: $T=\sum_{i=1}^{N}(N-2)=N(N-2)$.

`j=i:N` olsaydı terim sayısı "son terim − ilk terim + 1" kuralıyla $N-i+1$ olur:

$$T=\sum_{i=1}^{N}(N+1-i)=N(N+1)-\frac{N(N+1)}{2}=\frac{N(N+1)}{2}$$

Hoca konuyu kapatırken bu örneklerin tekrar edilmesini, diğer şubenin kayıtlarında da aynı konunun akış diyagramlarıyla farklı biçimde anlatıldığını söyler. Yapılan iş özetle şudur: kodun tekrar sayıları bulunur, değişkenin artışları toplam sembolüyle yazılır, dersin başındaki formüllerle sonuç hesaplanır.

## 7. Desen çizdiren algoritma ve rastgelelik

Dersin ikinci yarısında ders notundaki "6. ders" konusuna geçilir. Notta daire biçiminde, çok sayıda düz çizgiden oluşan desenler vardır (ekrandan, 01:45:00). Soru şudur: elimizde iki nokta arasında çizgi çeken hazır bir komut (çoğu dilde `line(x0,y0,x1,y1)` gibi) varsa bu desenler nasıl çizdirilir?

Bir öğrenci desenleri iç içe çemberlerle ya da kutupsal koordinatlarla açıklamayı önerir; hoca desenlerde çember olmadığını, hepsinin düz çizgi olduğunu belirtir. Başka bir öğrenci noktalar arasındaki açıların düzenli göründüğünü söyler. Hoca çizgileri tek tek izleyerek yöntemi anlatır: bir başlangıç noktasından bir sonraki noktaya çizgi çekilir, oradan bir sonrakine geçilir; 0'dan 1'e, 1'den 2'ye, 2'den 3'e... İstenen sayıda çizgi çekilene kadar devam edilir.

Notta verilen algoritma (ekrandan, 01:50:00):

```text
i=1;
for j=1:m
    yi=mod(i*s,m);
    birleştir(yi,i);
    i=yi;
end
```

Altında "farklı m ve s değerleri için" yazar ve dört desen gösterilir. Burada $m$ nokta sayısıdır, $s$ bir tam sayıdır. Daire $m$ parçaya bölünmüş gibi düşünülür; `birleştir(yi,i)` $i$'nci noktayla $y_i$'nci noktayı birleştiren çizgi çeker. $m$ büyüdükçe noktalar arasındaki boşluk azalır ve desen daha dolu görünür.

<!-- BELİRSİZ: Desen başlıklarında "337 **10", "337 ***12", "337 *** 14", "337 *** 15" yazıyor (ekrandan, 01:50:00); büyük olasılıkla m=337 ve s=10, 12, 14, 15 anlamındadır, derste açıklanmadı. -->

Hoca buradan rastgeleliğe geçer: rastgele süreçler ve rastgele sayı üretimi yapay zekada ve haberleşme sistemlerinde çok kullanılır.

### 7.1 Uniform dağılım

Uniform (tek düze) dağılım, her sonucun gelme olasılığının eşit olduğu dağılımdır. Zar örneğinde sonuçlar 1-6'dır. 10 atışın hepsinde 6 gelmesi uniform değildir; 12 atışta her yüzün 2'şer kez gelmesi uniformdur. Hilesiz bir zar 1.200.000 kez atılırsa her yüzün yaklaşık 200.000 kez gelmesi beklenir. Uniform dağılımda üretilen sayının tahmin edilebilirliği en düşüktür.

## 8. C'de rastgele sayı üretimi

### 8.1 `rand()` ve sözde rastgelelik

Bilgisayarda gerçek anlamda rastgelelik yoktur; üretilen sayılar sözde rastgeledir (pseudo-random). Hoca Dev-C++'ta `rand()` ile 10 sayı yazdırır (ekrandan, 02:00:00), ekran görüntüsünü alır ve programı yeniden çalıştırır. Bir öğrencinin tahmin ettiği gibi birebir aynı sayılar gelir. Normal bir rastgele süreçte aynı dizinin tekrar gelmesi çok düşük olasılıklıdır.

Nedeni şudur: fonksiyon bir başlangıç değerinden ($R_0$) başlayarak her değeri bir öncekinden matematiksel işlemlerle üretir; ilk değer bilinirse bütün dizi bilinir. Belli bir aralık için `rand()%10` yazılırsa yalnız mod alınır; ekranda sonuçlar yine her çalıştırmada aynıdır (1, 7, 4, 0, 9, ...).

### 8.2 Tohum: `srand` ve `time`

Başlangıç değerine tohum (seed) denir. `srand(10)` gibi bir çağrı `main`'in başında yapılırsa gelen sayılar değişir, ama her çalıştırmada yine aynı dizi gelir. Çözüm tohumu her çalıştırmada değiştirmektir: `srand(time(NULL))`. `time`, 1970'ten programın çalıştığı ana kadar geçen saniye sayısını verir; zaman ilerledikçe tohum, dolayısıyla $R_0, R_1, R_2, \dots$ değişir.

Ekranda gösterilen yorumdaki üreteç (ekrandan, 02:20:00):

```text
Xn+1 = (aXn + c) mod c
where X is the sequence of pseudo-random values
m, 0< m- modulus
a, 0< a <m- multiplier
c, 0< = c<m- increment
x0, 0<=x0<m- the seed or start value
```

> **Ders sonrası not:** Ekrandaki yorumda ve hocanın anlatımında "mod c" geçiyor. Doğrusal eşlik üretecinin (linear congruential generator) doğru biçimi $X_{n+1}=(aX_n+c)\bmod m$'dir; yorumun devamında da $m$ modül olarak tanımlanmıştır.

Arkasından bir zar programı yazılır (ekrandan, 02:05:00 ve 02:15:00). Son hâli şöyledir; `return 0;` ve son satırdaki `[x,y]` örneği ajan tarafından eklendi:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int i,j;

    //srand(7);
    int dizi[7]={0};
    int x=2, y=8;


    for(i=0;i<5;i++){
        dizi[rand()%6+1]++;
        //printf("%d\n",1+rand()%6);
    }

    for(i=1;i<7;i++){
        printf("%d :",i);
        for(j=0;j<dizi[i];j++)
            printf("*");
        printf("\n");
    }
    printf("[%d,%d] araliginda: %d\n", x, y, rand()%(y-x+1)+x);
    return 0;
}
```

Bu kod `gcc -Wall` ile uyarısız derlendi ve çalıştırıldı. Gelişim sırası şöyledir:

- `rand()%6` 0-5 arası değer verir; `+1` eklenince 1-6 arası zar elde edilir.
- Frekanslar 6 elemanlı bir dizide tutulup her değer için yıldız basılarak histogram çizilir (önceki derslerdeki histogram örneği gibi).
- İlk denemede dizi 6 elemanlı tanımlanıp `dizi[rand()%6+1]` kullanılınca 1 hiç gelmiyormuş gibi görünür. Bir öğrenci sorunun indeksin 1'den başlatılmasından kaynaklandığını söyler. Hoca diziyi 7 elemanlı yapar ve 0. elemanı boş bırakır.
- Atış sayısı 5'ten 50'ye ve 500'e çıkarıldıkça çubuklar birbirine yaklaşır.

> **Ders sonrası not:** 6 elemanlı dizide `dizi[rand()%6+1]` yazmak, 6 geldiğinde dizinin dışına (`dizi[6]`) yazar; bu C'de tanımsız davranıştır. 7 elemanlı dizi ya da `dizi[rand()%6]` doğrudur. Hoca bu sırada zarın "1 ila 5 arası" değer verdiğini söyledi; `rand()%6` 0-5, `rand()%6+1` 1-6 verir.

**Soru:** `stdlib.h` ve `time.h` eklemeden bu fonksiyonları kullanabiliyor muyuz? **Cevap:** Dev-C++ bunları arka planda bağladığı için hata vermiyor, ama gerekli kütüphanelerin eklenmesi gerekir. Ders arasında yapılan kontrolde `rand` ve `srand`'ın `stdlib.h`'de, `time` fonksiyonunun ise `time.h`'de olduğu görülür.

### 8.3 $[x,y]$ aralığında sayı üretmek

Hedef örneğin 2 ile 8 arasında tam sayı üretmektir. `rand()%(y+1)` 0-8 verir; $x=2$ eklenirse 2-10 olur, bu fazla. Doğrusu `rand()%(y-x+1)` ile 0-6 üretmek, sonra $x$ eklemektir: sonuç 2-8 olur.

```c
r = rand()%(y-x+1)+x;
```

Ders notundaki sözde kodda 45-54 arası için aynı mantık MATLAB ile, $[0,1)$ aralığında değer veren bir fonksiyonun sonucunu $(y-x+1)$ ile çarpıp $x$ ekleyerek kurulur.

### 8.4 Daha çok atışla dağılım

Hazır `randomZarAt.c` programında atış sayısı artırılır (ekrandan, 02:20:00):

```c
int main()
{
    int i=0;
    int hist[6]={0};
    srand(time(NULL));   // bir kez cagirilmali
    for (i=0;i<24000;i++) //atis sayisi arttikca dagilimin uniform olusu artar
        hist[rand()%6]++;

    for (i=0;i<6;i++)
        printf("%d ",hist[i]);

    printf("\n\n");
```

(Karede dosyanın ilk satırları görünmüyor; ajan `stdio.h`, `stdlib.h`, `time.h` ekleyip `return 0;` ile kapatarak derledi ve uyarısız çalıştırdı; bir çalıştırmada 4093 3991 3952 3944 4051 3969 çıktı.) 20.000 atışta her yüz yaklaşık 3.300 kez, 24.000 atışta yaklaşık 4.000 kez, 240.000 atışta yaklaşık 40.000 kez gelir; atış arttıkça dağılım daha düzgün görünür. Hoca bunu merkezi limit teoremiyle ilişkilendirir ve ayrıntısının olasılık ve istatistik dersinde geleceğini söyler.

> **Ders sonrası not:** Deney sayısı arttıkça gözlenen frekansların olasılığa yaklaşması büyük sayılar yasasıdır. Merkezi limit teoremi ise çok sayıda bağımsız değişkenin toplamının normal dağılıma yaklaşmasıyla ilgilidir; bu daha çok 10. bölümdeki toplam örneğine uyar.

## 9. 52 kartı karıştırma

Ders notundaki problem (ekrandan, 02:50:00):

```text
52 kartı karıştıralım
  o 1-52 arası rasgele bir sayı üret, o ana kadar çıkmadıysa yaz, başta hızlı ama sonra ?
  o A dizisine 1-52 arası sayıları sırayla yerleştir. N kez, 1-52 arası rasgele iki sayı üret, x,y,
    A[x]'le A[y]'yi swap, hızlı, N ne kadar büyükse dizi o kadar karışır.
```

C'de kartlar 0-51 olarak tutulur. Karıştırmada aynı kart iki kez geçemez.

### 9.1 Yöntem 1: ziyaret dizisi

Bir `visited` dizisi tutulur; bir sayı üretildiğinde daha önce çıkmadıysa (`visited[r]==0`) sıradaki yere yazılır ve işaretlenir. Hoca önce `for(i=0;i<52;i++)` ile yazmaya başlar (ekrandan, 02:25:00) ve sınıfa kodun çalışıp çalışmayacağını sorar.

**Soru:** `rand` sabit bir değer üretmez mi? **Cevap:** Hayır, döngüde 52 ayrı değer üretilir. Asıl sorun, bir öğrencinin belirttiği gibi, çıkmış bir sayı tekrar gelince o tur boşa gider; 52 turluk `for` bütün kartları doldurmayı garanti etmez. Bu yüzden döngü `while (i<52)` olmalıdır ve `i` yalnız yeni bir kart yazıldığında artmalıdır.

Son kod (ekrandan, 02:30:00); karede görünmeyen son satırlar ve `stdlib.h`, `time.h` satırları ajan tarafından eklendi:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int dizi[52]={0};
    int visited[52]={0};
    int i=0 ,r,c=0;
    while(i<52){
        c++;
        r = rand()%52;
        if(visited[r]==0){
            dizi[i] = r;
            visited[r] =1;
            i++;
        }
    }

    for(i=0;i<52;i++){
        printf("%d ",dizi[i]);
    }
    printf("\ncounter: %d\n", c);
    return 0;
}
```

`c` sayacı döngünün kaç tur attığını gösterir. Derste ardışık çalıştırmalarda 292, 382 ve 175 tur görülür; bu, rastgeleliğin kendisidir. Algoritmanın karmaşıklığı tekrar sayısı kadardır ve bu sayı çok büyüyebilir. Kod `gcc -Wall` ile uyarısız derlendi; bir çalıştırmada sayaç 256 çıktı.

> **Ek bilgi (derste anlatılmadı):** Bu süreç "kupon toplama" problemidir. 52 farklı değerin hepsini görmek için beklenen tur sayısı $52\cdot\left(1+\frac12+\dots+\frac1{52}\right)\approx236$'dır (python ile hesaplandı).

### 9.2 Yöntem 2: sırala ve takas et

Kartlar önce sırayla diziye yerleştirilir (`dizi[i]=i`). Sonra 52 kez rastgele iki indis `r` ve `c` üretilir ve `dizi[r]` ile `dizi[c]` takas edilir. Döngü kesin olarak 52 kez döner; daha çok karıştırmak için 520 kez de döndürülebilir. Hoca bu kodu ekranda yazar; aşağıdaki hâl altyazıdaki anlatımdan kurulmuştur ve ajan tarafından `gcc -Wall` ile uyarısız derlenip çalıştırılmıştır:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int dizi[52];
    int i, r, c, temp;
    srand(time(NULL));
    for(i=0;i<52;i++)          /* once sirali yerlestir */
        dizi[i] = i;
    for(i=0;i<52;i++){         /* 52 kez rastgele iki karti takas et */
        r = rand()%52;
        c = rand()%52;
        temp = dizi[r];
        dizi[r] = dizi[c];
        dizi[c] = temp;
    }
    for(i=0;i<52;i++)
        printf("%d ",dizi[i]);
    printf("\n");
    return 0;
}
```

Derste bir çalıştırmada birinci yöntem 171 turda biterken ikincisi 52 turda biter. Hoca algoritmanın adını ararken kart karıştırma algoritması olarak Fisher-Yates'i bulur.

> **Ders sonrası not:** Fisher-Yates karıştırması büyük olasılıkla burada yazılan yöntemden biraz farklıdır: her $i$ için yalnız $[i,51]$ aralığından bir $j$ seçilip `dizi[i]` ile `dizi[j]` takas edilir. Bu biçim bütün dizilimlerin eşit olasılıkla çıkmasını garanti eder; rastgele iki indisi 52 kez takas etmek bunu garanti etmez.

Hoca dizi karıştırmanın sıralamada da işe yaradığını ekler: Quicksort karışık dizide çok hızlıdır, ama dizi tersten sıralıysa çok yavaşlar; bu yüzden önce dizi karıştırılır, sonra Quicksort uygulanır.

## 10. İki uniform sayının toplamı ve çan eğrisi

Gauss dağılımı, çan biçiminde bir eğridir. Ders notundaki soru: "Gaussian dağılım üretmek, 1-N arası, Uniform dağılımdan 2 sayı üret, ortalamasını al, yaz? Ortalamanın 2 olma olasılığı? Ortalamanın N/2 olma olasılığı?" (ekrandan, 02:50:00).

Hoca bunu bir şekille anlatır (ekrandan, 02:35:00). 1-99 arası iki sayı toplanırsa toplam $C$ 2 ile 198 arasındadır:

| Toplam $C$ | Oluşturan ikililer (sırasız) |
|---|---|
| 2 | (1,1) |
| 3 | (2,1) |
| 4 | (1,3), (2,2) |
| 5 | (1,4), (2,3) |
| 50 | (1,49), (2,48), (3,47), ... çok sayıda |
| 100 | çok sayıda |
| 198 | (99,99) |

Uçlardaki toplamlar az ikiliyle, ortadakiler çok ikiliyle oluşur. Bu yüzden ortadaki değerlerin gelme olasılığı en yüksek, uçtakilerin en düşüktür ve histogram çan biçimini alır.

Kod önce `#define MAX 199`, `rand()%99+1` ile yazılır (ekrandan, 02:40:00). Histogramda çok sayıda sıfır kalır; hoca deney sayısını 100.000'e çıkarır, sayı aralığını küçültür (bir öğrencinin önerisiyle mod değeri 25 yapılır) ve sonuçları 100'e bölerek ölçekler. Son hâl (ekrandan, 03:00:00; karede görünmeyen histogram satırları 02:40:00 karesindeki ilk hâlden alındı, `stdlib.h`/`time.h` satırları ve `return 0;` ajan tarafından eklendi):

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 51
int main(){
    srand(time(NULL));
    int dizi[MAX]={0};
    int i,j;
    int s1,s2;
    for(i=0;i<100000;i++){
        s1 = rand()%25+1;
        s2 = rand()%25+1;
        dizi[s1+s2]++;
    }

    for(i=0;i<MAX;i++){
        dizi[i] /=100;
    }

    for(i=1;i<MAX;i++){
        for(j=0;j<dizi[i];j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
```

Kod `gcc -Wall` ile uyarısız derlendi; satır uzunlukları ortada en yüksek (yaklaşık 38-39 yıldız), uçlarda sıfıra yakın çıktı. Derste ilk denemede histogram döngüsündeki `j`'nin sıfırlanmaması ve dizinin 0'dan başlatılması gibi hatalar düzeltilir.

> **Ders sonrası not:** İki uniform sayının toplamı tam olarak Gauss değil, üçgen biçimli bir dağılım verir; çıktı da büyük olasılıkla ortası sivri bir üçgendir. Daha çok sayı toplandıkça dağılım normal dağılıma yaklaşır (merkezi limit teoremi).

Hoca dersin sonunda konuyu günlük hayatla bağlar: 100 kez para atınca 50-50 gelmez, ama 100.000 kez atılınca oranlar yaklaşır. İnsanların boy ve kilo dağılımı, bir sınavdaki notların dağılımı gibi pek çok olgu çan eğrisine benzer. Bu sayede tahmin yapılabilir: olasılıkta beklenen değer aslında ortalamadır. Hoca tanımadığımız bir kişinin yaşını tahmin etmeyi sorar; bir öğrencinin verdiği tahmin, toplumun yaş ortalamasına yakın bir değerdir, çünkü çok genç ve çok yaşlı insan az, orta yaşlı insan çok görülür.

## 11. Rastgele gezen robot

Ders notundaki problem (ekrandan, 02:50:00): "Bir robotu etrafındaki engellere çarpmadan rasgele gezdir. (0,1)'lerden oluşan bir matriste. Robot 4 komşusuna gidebiliyor. İf'li, İf'siz (1 0), (0 1), (-1 0), (0 -1). Robot 8 komşusuna gidebilseydi?"

Robot iki boyutlu bir matriste $(x,y)$ noktasındadır. Matris ekranda sol üstten başlayan normal bir matris gibi düşünülür. Hoca sınıfa sorar, öğrenciler cevaplar:

- Sağa gidince yeni konum $(x,y+1)$ olur.
- Yukarı gidince yeni konum $(x-1,y)$ olur.

Gezilen yerler 1 ile işaretlenir; matris başta sıfırlarla doludur.

### 11.1 if'li (switch'li) çözüm

0-3 arası rastgele sayı üretilir, her sayı bir yöne karşılık gelir. Hoca `switch`'i burada gösterir ve `break`'in `switch` içinde nasıl kullanıldığına dikkat çeker. Kod (ekrandan, 02:45:00; karede görünmeyen ilk satırlar, `x`, `y`, `r` bildirimi ve matrisi yazdıran son satırlar ajan tarafından eklendi; tam hâli `gcc -Wall` ile uyarısız derlendi):

```c
    int m[11][11]={0};
    int adim,j,i,n=5;
    x=5;
    y=5;

    // 1. Yöntem 1-4 aralığında yon üretelim ve kontroller ile gerekli indis güncellemelerini yapalım
    for (adim=0;adim<n;adim++)
    {
        r = rand()%4;
        switch (r){
        case 0: //sag
            y=y+1;
            break;
        case 1: //sol
            y=y-1;
            break;
        case 2: //yukari
            x=x-1;
            break;
        case 3: //asagi
            x=x+1;
            break;
        }
        m[x][y] = 1;
    }
```

Robot $(5,5)$ noktasından başlar ve her adımda rastgele bir komşuya geçer. Sekiz yön (kuzeydoğu, güneybatı vb.) istenirse 8 `case` yazmak gerekir; hoca bu yaklaşımın 4 yönde bile pek iyi olmadığını söyler.

### 11.2 if'siz çözüm

Bellekten yararlanılır: bir "adım matrisi" tutulur. Her satır bir yöne karşılık gelen $(\Delta x,\Delta y)$ değişimini saklar, örneğin $(0,1)$ sağ, $(0,-1)$ sol, $(-1,0)$ yukarı, $(1,0)$ aşağı. Rastgele üretilen yön numarası bu tablonun satırını seçer ve $x$, $y$ tablodaki değerlerle güncellenir. `if`/`switch` ortadan kalkar; 8 yön için yalnız tablo büyür, güncelleme satırları aynı kalır. Hoca 8 yönlü tablonun bir kısmını yazıp kalanını öğrencilere bırakır (bkz. Örnek Sorular).

## 12. Monte Carlo yöntemiyle pi sayısı

Ders notundaki soru (ekrandan, 02:50:00):

```text
say=0;
for i=1:N
    x=rand(); // 0,1 aralığında bir sayı üretir
    y=rand();
    if (x*x+y*y)<1
        say=say+1;
    end
end
T=4*say/N
```

$N$ çok büyük, sonsuza yakın kabul edilir. Hoca, sınavda da sözde kod ya da akış diyagramıyla "bu kod çalışınca `T` ne olur?" gibi sorular sorulduğunu söyler, iki dakika düşünme süresi verir ve birim çemberi hatırlatır.

Bir öğrenci $\frac{say}{N}$'nin "daire alanı bölü kare alanı" gibi bir oran olduğunu önerir. Hoca bunu bir dart tahtası benzetmesiyle açıklar (ekrandan, 02:55:00):

- $x$ ve $y$ 0-1 arasında olduğundan bütün atışlar $1\times1$'lik karenin içine düşer.
- $x^2+y^2<1$ olan atışlar, merkezi orijinde ve yarıçapı 1 olan dairenin dörtte birinin içindedir.
- Çok sayıda atışta $N$ karenin alanını, $say$ çeyrek dairenin alanını temsil eder: $\frac{say}{N}\approx\frac{\pi\cdot1^2/4}{1}=\frac{\pi}{4}$.
- Bütün dart tahtası için 4 ile çarpılır: $T=4\cdot\frac{say}{N}\approx\pi$.

$N$ ne kadar büyükse $\pi$ o kadar iyi yaklaşılır. Buna Monte Carlo simülasyonu denir.

**Soru:** $N$'yi neden bütün şeklin alanı gibi düşündük? **Cevap:** Her atış karenin içinde bir noktadır; sonsuz atışta noktalar karenin alanını doldurur. $N$ karenin alanına, $say$ ise dairenin içindeki bölgenin alanına karşılık gelir; oran $\frac{\pi}{4}$'e yaklaşır.

> **Ders sonrası not:** Hoca anlatırken bir ara karenin kenarını 2 alıp alanı 4 kabul etti (yarıçap 1, tam daire). Bu da aynı sonucu verir: tam daire alanı $\pi$, kare alanı 4, oran $\frac{\pi}{4}$. Koddaki $x,y\in[0,1]$ durumunda ise birim kare ve çeyrek daire söz konusudur.

Hoca kodu bir fonksiyon olarak çalıştırır: $N$ sırayla 10, 100, 1000, ... olacak biçimde deney yapılır, $[0,1]$ aralığında sayı için `rand()` sonucu `RAND_MAX`'e bölünür. Ekranda sonuçlar 2.8, 3.24, 3.24, 3.14 gibi ilerler; $10^9$, $10^{10}$ atışlı deneyler çok uzun sürer. Derste gösterilen C kodu karelerde görülmediği için aşağıdaki sürüm ajan tarafından yazılmıştır (derste verilmedi) ve `gcc -Wall` ile uyarısız derlenip çalıştırılmıştır:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double pi_tahmin(long n){
    long i, say=0;
    double x, y;
    for(i=0;i<n;i++){
        x = (double)rand()/RAND_MAX;   /* [0,1] araliginda */
        y = (double)rand()/RAND_MAX;
        if(x*x + y*y < 1)
            say++;
    }
    return 4.0*say/n;
}

int main(){
    long n = 10;
    int k;
    srand(time(NULL));
    for(k=1;k<=7;k++){
        printf("N=%ld  T=%f\n", n, pi_tahmin(n));
        n *= 10;
    }
    return 0;
}
```

Bir çalıştırmada $N=10$ için 2.8, $N=10^4$ için 3.1508, $N=10^7$ için 3.1408 elde edildi.

Hoca bu tür rastgelelik tabanlı yöntemlerin haberleşme sistemlerinde, yapay zekada veri üretiminde ve gerçek olayların modellenmesinde çok kullanıldığını söyler.

## Örnek Sorular

**1.** (ekrandan, 00:20:00) Aşağıdaki algoritmanın çalıştırılması sonucunda `T` değeri kaç olur? `T=T+1` yerine `T=T+i`, `T=T+2`, `T=T+2i`, `T=T+T` olursa?

```text
T=0;
for i=1:N
    T=T+1;
end
```

> **Çözüm:** $N$; $\frac{N(N+1)}{2}$; $2N$; $N(N+1)$; `T=0` ile $0$ (başlangıç `T=1` alınırsa $2^N$). Order $O(N)$.

**2.** (ekrandan, 00:20:00) `for i=1:N`, `for j=1:N*N`, `T=T+1` için `T` kaç olur? `T=T+i` ve `T=T+j` olursa?

> **Çözüm:** $N^3$; $\frac{N^3(N+1)}{2}$; $\frac{N^5+N^3}{2}$. Order $O(N^3)$.

**3.** (ekrandan, 00:35:00) `for i=1:N`, `for j=1:i*i`, `T=T+1` için `T` kaç olur? `T=T+i` ve `T=T+j` için?

> **Çözüm:** $\frac{N(N+1)(2N+1)}{6}$; $\left(\frac{N(N+1)}{2}\right)^2$; $\frac12\left(\frac{N^5}{5}+\frac{N^4}{2}+\frac{N^3}{3}-\frac{N}{30}+\frac{N(N+1)(2N+1)}{6}\right)$.

**4.** (ekrandan, 00:35:00) `T=0; i=1; while (i<=N) { T=T+1; i=i*2; }` için `T` kaç olur? $N=32$ için? `T=T+i` olursa?

> **Çözüm:** $\lfloor\log_2N\rfloor+1$; $N=32$ için 6. `T=T+i` için $2^{\lfloor\log_2N\rfloor+1}-1$; $N=32$ için 63. (Derste $N=32$ için 5 ve `T=T+i` için $N-1$ söylendi; yukarıdaki değerler python ile doğrulandı, bkz. Bölüm 4.)

**5.** (ekrandan, 00:45:00) $T=\sum_{i=0}^{N}A^i$ nasıl bulunur? $T=\sum_{i=0}^{N}iA^i$ nasıl bulunur?

> **Çözüm:** $T-aT$ farkı yöntemiyle; $\sum_{i=0}^{N}A^i=\frac{A^{N+1}-1}{A-1}$ (Bölüm 4.2). İkinci toplam için yöntem derste gösterildi, kapalı biçim Bölüm 4.3'teki ek bilgi bloğundadır.

**6.** (ekrandan, 00:55:00) İçinde `if mod(j,i)==0 T=T+1` bulunan `for i=1:N`, `for j=1:i*i` döngüsünde `T` kaç olur? `T=T+1` else kolunda olsaydı?

> **Çözüm:** $\frac{N(N+1)}{2}$; else kolunda $\sum(i^2-i)=\frac{N^3-N}{3}$.

**7.** (ekrandan, 00:55:00) Önce `K=K*2` ile $K$'yı bulan, sonra `for i=1:N`, `for j=1:K`, `T=T+1` yapan algoritmada `T` kaç olur? `T=T+i`, `T=T+j` olsaydı?

> **Çözüm:** $N\cdot2^N$; $2^N\cdot\frac{N(N+1)}{2}$; $N\cdot\frac{2^N(2^N+1)}{2}$. Order $O(N\cdot2^N)$.

**8.** (ekrandan, 01:35:00) İç döngüsü `j=1; while (j<K) { T=T+1; j=j*2; }` olan algoritmada ($K=2^N$) `T` kaç olur?

> **Çözüm:** $N^2$.

**9.** (ekrandan, 01:35:00) `for i=1:N`, `for j=1:i`, `for k=1:j`, `T=T+1` için `T` kaç olur?

> **Çözüm:** $\frac{N(N+1)(N+2)}{6}$, order $O(N^3)$.

**10.** (ekrandan, 01:35:00) `for i=1:N`, `for j=3:N`, `T=T+1` için `T` kaç olur? `j=3:N` yerine `j=i:N` olsaydı?

> **Çözüm:** $N(N-2)$; $\frac{N(N+1)}{2}$.

**11.** (derste sözlü, 02:16:18) `rand()` ile 2 ile 8 arasında (ikisi dahil) tam sayı nasıl üretilir?

> **Çözüm:** `rand()%(8-2+1)+2`, genel olarak `rand()%(y-x+1)+x`.

**12.** (ekrandan, 02:50:00) 52 kartı karıştırın: (a) 1-52 arası sayı üret, çıkmadıysa yaz; (b) sırayla yerleştir, rastgele iki indisi takas et.

> **Çözüm:** Bölüm 9'daki iki kod. (a) `while` ile kurulmalıdır, tur sayısı rastgeledir; (b) tur sayısı sabittir.

**13.** (ekrandan, 02:50:00) 1-N arası uniform dağılımdan 2 sayı üretip ortalamasını alarak Gauss benzeri dağılım üretin. Ortalamanın 2 olma olasılığı nedir? $N/2$ olma olasılığı nedir?

> **Çözüm:** Derste toplamın histogramı çizildi (Bölüm 10). Olasılıklar derste hesaplanmadı. **Çözüm (derste verilmedi):** Ortalama $\frac{s_1+s_2}{2}$; ortalamanın 2 olması için $s_1+s_2=4$ gerekir ve sıralı ikililer $(1,3),(2,2),(3,1)$ olduğundan olasılık $\frac{3}{N^2}$'dir ($N\ge3$). Ortalamanın 1 olması (yalnız $(1,1)$) $\frac{1}{N^2}$'dir. $N$ çift ise ortalamanın $N/2$ olması için $s_1+s_2=N$ gerekir; $(1,N-1),\dots,(N-1,1)$ olmak üzere $N-1$ ikili vardır, olasılık $\frac{N-1}{N^2}$'dir. Ortaya yakın değerlerin olasılığı uçlardakinden çok büyüktür.

**14.** (ekrandan, 02:50:00) Robot 8 komşusuna gidebilseydi?

> **Çözüm (derste verilmedi):** Yön tablosu 8 satıra çıkarılır, `rand()%8` ile yön seçilir. Matris dışına çıkan adımlar atlanır. `gcc -Wall` ile uyarısız derlendi ve çalıştırıldı.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define B 11

int main(){
    int m[B][B]={0};
    /* 8 yon: sag, sol, yukari, asagi, sag-yukari, sol-yukari, sag-asagi, sol-asagi */
    int dx[8]={ 0, 0,-1, 1,-1,-1, 1, 1};
    int dy[8]={ 1,-1, 0, 0, 1,-1, 1,-1};
    int x=5, y=5, adim, r, i, j, yx, yy, n=20;
    srand(time(NULL));
    m[x][y]=1;
    for(adim=0; adim<n; adim++){
        r = rand()%8;
        yx = x + dx[r];
        yy = y + dy[r];
        if(yx<0 || yx>=B || yy<0 || yy>=B)   /* matris disina cikma */
            continue;
        x = yx; y = yy;
        m[x][y] = 1;
    }
    for(i=0;i<B;i++){
        for(j=0;j<B;j++) printf("%d ",m[i][j]);
        printf("\n");
    }
    return 0;
}
```

**15.** (ekrandan, 02:50:00) Monte Carlo kodunun çalıştırılması sonucunda `T` değeri kaç olur ($N$ çok büyük)?

> **Çözüm:** $T=4\cdot\frac{say}{N}\to\pi$ (Bölüm 12).

## Dersin Toparlaması

Dersin ilk yarısında iteratif algoritmaların değer ve karmaşıklık analizi yapıldı. Temel yöntem, kodu toplam ya da çarpım sembolüne çevirmek, sınırları ve artış miktarını doğru belirlemek, sonra Gauss, kareler, küpler ve geometrik seri formüllerini uygulamaktır. Birer birer artan `for` döngülerinde üst sınır doğrudan yazılır; çarpılarak büyüyen `while` döngülerinde önce tekrar sayısı logaritmayla bulunur. `if` içeren döngülerde tabloyla örüntü aranır, else kolu için "tüm durum eksi aksi durum" kullanılır. Order hesabında en yüksek dereceli terim alınır; döngü sayısı order'ı tek başına belirlemez.

İkinci yarıda programlama konularına dönüldü ve rastgelelik işlendi. C'de `rand()` sözde rastgeledir, `srand(time(NULL))` ile tohum değiştirilir. Aralıkta sayı üretme, zar histogramı, iki farklı kart karıştırma yöntemi, iki uniform sayının toplamıyla çan biçimli dağılım, `switch`li ve tablolu robot gezdirme, Monte Carlo yöntemiyle $\pi$ tahmini yapıldı. Hoca bu konuların ileride algoritma analizi, veri yapıları, ayrık matematik ve olasılık-istatistik derslerinde ayrıntılı olarak geleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
