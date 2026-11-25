# Ders 4 Çalışma Özeti

## Genel Konular

- Ödünleşim (trade-off): zaman, bellek ve doğruluk
  - Bir algoritmada bir ölçütten kazanmak çoğu zaman başka bir ölçütten kaybetmek demektir: zaman (time), bellek (memory) ve doğruluk (accuracy) birbirine karşı tartılır (ekrandan, 00:05:00).
  - Gauss formülü $1+2+\dots+N = \frac{N(N+1)}{2}$ hem zamandan hem bellekten kazandırır, doğruluktan da bir şey kaybettirmez; bu yüzden iyi bir çözüm örneğidir.
  - Karmaşıklık aileleri hatırlatıldı: $1$, $\log N$, $N$, $N\log N$, $N^2$, $N^3$, ... (polinom zamanlı aileler) ve $2^N$, $3^N$, ..., $N!$, $N^N$ (üstel aileler) (ekrandan, 00:15:00).
- Soru 1: $N!$ hesabı
  - Naif çözüm: `f = 1; for(i=1;i<=N;i++) f = f*i;`. Adım sayısı $T_1(N)=N$, sonuç ise $f=N!$. Sonuç ile adım sayısı farklı şeylerdir.
  - Stirling yaklaşımı: $N! \approx \sqrt{2\pi N}\left(\frac{N}{e}\right)^N$. Kuvvet bir `for` döngüsüyle alınırsa $T_2(N) \approx N+4 \approx N$ olur; doğruluk kaybedilir ama zaman kazanılmaz.
  - Kuvvet $N^k = N^{k/2}\cdot N^{k/2}$ yarılama fikriyle hesaplanırsa adım sayısı $\log_2 k$ olur. Bu, özyineleme (recursion) ile yapılır: zaman kazanılır, bellekten kaybedilir (ekrandan, 00:20:00).
- Soru 2: $\pi$ için seri yaklaşımı
  - $\pi = \frac{4}{1} - \frac{4}{3} + \frac{4}{5} - \frac{4}{7} + \dots$ ($N$ terim) (ekrandan, 00:30:00).
  - Çözüm 1: çift terimde topla, tek terimde çıkar (`if (i%2==0)`), paydayı her adımda 2 artır.
  - Çözüm 2: döngü $N/2$ kez döner, her adımda bir toplama ve bir çıkarma yapılır; `if` ortadan kalkar.
  - Çözüm 3: `sign` adlı işaret değişkeni tutulur, her adımda `sign = -sign` yapılır.
  - Tam sayı bölmesi tuzağı: `4/5` tam sayı bölmesinde `0` verir. Pay ya da paydadan biri `double`'a çevrilmelidir (açık dönüşüm `(double)pay` ya da örtük dönüşüm `1.0*pay`).
- C operatör önceliği ve birleşme yönü (associativity)
  - Tür dönüştürme (cast) operatörü bölmeden önce gelir; bu yüzden `(double)pay/payda` ifadesinde ek parantez gerekmez (ekrandan, 00:45:00).
  - Aynı öncelikteki `*`, `/`, `%` soldan sağa işlenir: `8/4*2 = 4`.
  - Atama operatörü sağdan sola işlenir: `a = b = c = d = 3;`.
- Hata ayıklama (debug) ve süre ölçümü
  - IDE'de satıra kesme noktası (breakpoint) konur, değişkenler izlemeye (add watch) eklenir, kod adım adım (next line) çalıştırılır.
  - Ekrana yazdırma, hesaplamadan çok daha uzun sürer. Süre ölçerken döngü içindeki `printf` satırları kapatılmalıdır.
  - C'de süre `time.h` kütüphanesindeki `time_t` türü ve `difftime` fonksiyonuyla ölçülür (başlangıç ve bitiş arasındaki fark).
- Soru 3: $e^x$ için Taylor serisi
  - $e^x = \frac{1}{0!} + \frac{x}{1!} + \frac{x^2}{2!} + \frac{x^3}{3!} + \dots$ (ekrandan, 01:20:00).
  - Yaklaşım 1: her terim için pay ($x^i$) ve payda ($i!$) iç döngülerle baştan hesaplanır. Karmaşıklık $\sum_{i=1}^{N} i = \frac{N(N+1)}{2} \approx N^2$ (ekrandan, 01:40:00).
  - Yaklaşım 2: önceki terim kullanılır (`pay = pay*x; payda = payda*i;`). Tek döngü, karmaşıklık $N$.
  - Taşma (overflow): `int` pay ve payda büyük terimlerde sığmaz, sonuç bozulur. `long`, `long long` gibi daha geniş türler sınırı biraz öteler.
- Soru 4: Fibonacci sayıları
  - Çözüm 1: `t1=0, t2=1`; döngüde `next = t1+t2; t1 = t2; t2 = next;`. Zaman $\approx 4N$, bellek sabit (3 değişken).
  - Çözüm 2: dizi ile `d[i] = d[i-1] + d[i-2]`. Kodlaması kolay, ama zaman $\approx 6N$ ve bellek $N$ (ekrandan, 01:55:00).
  - Matris kuvveti ile $\log N$ karmaşıklıkta çözüm de vardır; ödev niteliğinde araştırma olarak bırakıldı.
- Soru 5: Armstrong sayıları (1-999)
  - Basamakların küpleri toplamı sayının kendisine eşit olan sayılar: 1, 153, 370, 371, 407.
  - Üç basamağı tek tek ayıran kod yerine `while`/`do-while` döngüsüyle basamak sayısından bağımsız genel çözüm yazıldı (ekrandan, 02:25:00).
- Önermeler mantığı ve karşı örnek
  - Bir önerme $P(x)$ doğru ya da yanlıştır. Kanıt yöntemleri: tümevarım, doğrudan, dolaylı kanıt, çelişki. Bunların yetmediği yerde hesaplama (bilgisayar) kullanılır.
  - $\forall n \in \mathbb{N}^+$, $n^2+n+41$ asaldır önermesi: $n=41$ için $41^2+41+41 = 43\cdot 41$ asal değildir, önerme yanlıştır (ekrandan, 02:35:00).
  - Asal sayı kontrolü: 2'den başlayarak bölen aranır; döngü bir bölen bulunca erken bitmelidir. Üst sınır $n-1$ yerine $n/2$ ya da $\sqrt{n}$ alınabilir.
  - Euler'in 4. kuvvetler sanısı: $a^4+b^4+c^4=d^4$ çözümünün olmadığı sanılıyordu; 1988'de bilgisayarla $95800^4+217519^4+414560^4=422481^4$ karşı örneği bulundu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sonuç ile adım sayısı farklıdır
  - Faktöriyel hesabının sonucu $N!$ olsa da, naif algoritmanın adım sayısı $N$'dir. Karmaşıklık $N!$ değildir.
- Algoritma belirsizlik içermemelidir
  - Değişkenler tanımlanmalı, her işlem açıkça yazılmalıdır. "mypi'yi güncelle" ya da "asal mı kontrol et" gibi açık olmayan bir adım, çözümü tam bir algoritma olmaktan çıkarır.
  - Algoritma sözde kod, C'ye yakın kod, akış diyagramı ya da C koduyla yazılabilir; önemli olan adımların net olmasıdır.
- Tam sayı bölmesi
  - `int/int` bölmesi kesirli kısmı atar. Pay ya da paydadan yalnızca birinin `double`'a çevrilmesi yeterlidir.
- Algoritmada parametrik düşünmek
  - Belirli bir sayıya göre değil, $N$ gibi parametrelere göre konuşmak gerekir.
- Genel çözüm, kodu uzatarak bulunmaz
  - Armstrong sorusunda her basamak için satır eklemek algoritmik çözüm değildir; döngüyle genelleştirmek gerekir.
- Süre ölçerken `printf` kapatılır
  - Ekrana yazma süresi algoritmanın süresi değildir.
- Karşı örnek yöntemi
  - "Her $n$ için" denen bir önermeyi yanlışlamak için tek bir karşı örnek yeter; doğrulamak için sonsuz deneme gerekir.

## Kısa Tekrar Notları

- Ödünleşim: zaman, bellek, doğruluk.
- Naif $N!$: $T(N)=N$. Stirling: $\sqrt{2\pi N}(N/e)^N$, yaklaşık sonuç verir.
- Yarılayarak kuvvet alma: $\log_2 k$ adım; özyinelemeyle yapılır, bellek harcar.
- $\pi$ serisi: işaret `if`, iki terimli adım ya da `sign = -sign` ile değiştirilir.
- `4/5` tam sayı bölmesinde `0`; `(double)pay/payda` ya da `1.0*pay/payda` kullan.
- Cast, `/`'dan önce; `*` ve `/` soldan sağa; `=` sağdan sola.
- $e^x$: iç içe döngü $\approx N^2$, önceki terimi kullanma $\approx N$.
- `int` taşması büyük faktöriyel ve kuvvetlerde sonucu bozar.
- Fibonacci: üç değişkenle sabit bellek; dizi ile $N$ bellek.
- Armstrong (1-999): 1, 153, 370, 371, 407.
- Karşı örnek: bir tane yanlışlayan örnek önermeyi çürütür.
- Asal kontrolü: bölen bulununca dur; sınır $\sqrt{n}$ yeterlidir.

## Detaylı Açıklamalar

- **Ödünleşim ve karmaşıklık aileleri.** Ders, önceki derste görülen ödünleşim kavramının tekrarıyla başladı. Bir algoritmayı tasarlarken zaman, bellek ve doğruluk birbirine karşı tartılır. Örneğin hızlı bir yaklaşık çözüm doğruluktan kaybettirebilir; bellek kısıtlıysa zamandan feda edilebilir. Amaç, karmaşıklığı girdi boyutuna göre bir alt aileye indirmektir. Sıralama algoritmalarının çoğu $N^2$ iken birleştirerek sıralama (merge sort) ve hızlı sıralama (quicksort) $N\log N$'ye iner.

- **Faktöriyel ve Stirling formülü.** Naif algoritma 1'den $N$'e kadar çarpar ve $N$ adımda biter. Stirling formülü $N!$ için yaklaşık bir değer verir, ama $(N/e)^N$ terimini hesaplamak için yine $N$ kez çarpmak gerekir. Bu yüzden zaman kazanılmaz, üstelik doğruluk kaybedilir. Ayrıca karekök için de makine düzeyinde tek bir işlem yoktur; yaklaşım yöntemleriyle hesaplanır. Kuvvet yarılama yöntemiyle hesaplanırsa ($N^k = N^{k/2}\cdot N^{k/2}$, $N^{k/2} = N^{k/4}\cdot N^{k/4}$, ...), $k/2^i = 1$ olduğunda durulur ve $i = \log_2 k$ adım gerekir. Böylece Stirling formülünün maliyeti $\log_2 N$ düzeyine iner; bu çözüm özyineleme konusunda kodlanacak.
  <!-- BELİRSİZ: 00:21:17 civarında hoca 10! değerini iki yöntemle karşılaştırmayı alıştırma olarak önerdi; karşılaştırma derste yapılmadı. -->

- **$\pi$ serisinin C kodu.** Hoca önce tabletteki sözde kodu, sonra Dev-C++'ta C kodunu yazdı (ekrandan, 00:50:00):

```c
for(i=0;i<N;i++){
    if(i%2==0){
        mypi += (double)pay/payda;
    }
    else{
        mypi -= 1.0*pay/payda;
    }
    payda += 2;
}
printf("Sonuc-1=%lf",mypi);
```

  İlk çalıştırmada paydanın güncellenmesi unutulduğu için sonuç yanlış çıktı; güncelleme eklenince $N=100$ için yaklaşık 3.13, daha büyük $N$ için 3.1415'e yaklaşan değerler görüldü. İkinci çözümde döngü değişkeni yeniden kullanılırken `mypi` ve `payda` başlangıç değerlerine döndürülmelidir; aksi halde önceki hesap devam eder. `%2.10lf` biçimiyle virgülden sonra 10 basamak yazdırılabilir.

- **$e^x$ ve taşma.** İç içe döngülü yaklaşımda $x=5$ için 10 terimle 146.38 bulundu; gerçek değer 148.413'tür. Terim sayısı artırılınca sonuç bozuldu, çünkü `int` türündeki pay ($5^{14}$) ve payda ($13!$) 32 bitlik sınırı aşar. `long long` kullanınca 15 terimle yaklaşık 148.40 elde edilir (ajan tarafından `gcc` ile doğrulandı). İkinci yaklaşımı kodlarken döngü değişkeni `i` yerine kopyala-yapıştır yüzünden `j` yazılması da hata verdi; düzeltme `payda = payda*i;` oldu.

- **Fibonacci.** Üç değişkenli çözümde sıralama önemlidir: önce `t1 = t2`, sonra `t2 = next` yapılır; tersi yapılırsa değer kaybolur. Dizi kullanan çözüm kodlaması kolay (easy to implement) ama zaman ve bellek açısından daha pahalıdır. C'de dizi boyutu derleme zamanında bilinmelidir; hoca boyutu `#define MAX` benzeri bir sabitle verdi (ekrandan, 02:10:00). 15. Fibonacci sayısı 610'dur.

- **Armstrong sayıları.** Her sayı `num` adlı değişkene yedeklenir (döngü değişkeni bozulmasın diye). `digit = num % 10` son basamağı verir, `num /= 10` sayıyı küçültür, `sum += digit*digit*digit` küpü ekler. `do-while` sürümünde `while(...)` satırının sonunda noktalı virgül vardır; bu, `while` döngüsünden farklı olarak gerekli tek istisnadır. Genel tanımda $n$ basamaklı bir sayı için basamakların $n$'inci kuvvetleri toplanır.

- **Asal sayı kontrolü ve karşı örnek.** Hoca önce `for` ile 2'den $n-1$'e kadar bölen aradı, sonra erken çıkış için koşulu `i < n-1 && n%i != 0` biçiminde birleştirdi ve bunun `while` döngüsüyle daha doğal yazıldığını gösterdi (ekrandan, 02:45:00).

> **Ders sonrası not:** Hoca tahtada "`i == n` ise asal değil, değilse asal" yazdı. Doğrusu tersidir: döngü hiçbir bölen bulmadan `i == n` noktasına geldiyse sayı asaldır. Ayrıca döngü koşulu `i < n-1` olursa `i` hiçbir zaman `n` olamaz; koşul `i < n` olmalıdır. Ajanın düzelttiği sürüm (derste bu biçimde yazılmadı, `gcc -Wall` ile derlenip çalıştırıldı):

```c
#include <stdio.h>

int asal_mi(long long n){
    long long i = 2;
    if(n < 2) return 0;
    while(i < n && n % i != 0){
        i++;
    }
    return i == n;
}

int main(){
    long long n, pn;
    for(n = 1; ; n++){
        pn = n*n + n + 41;
        if(!asal_mi(pn)){
            printf("Karsi ornek: n=%lld, P(n)=%lld\n", n, pn);
            break;
        }
    }
    return 0;
}
```

> **Ders sonrası not:** Hoca karşı örnek olarak $n=41$'i verdi ($41^2+41+41 = 43\cdot 41$). Bu doğru bir karşı örnektir, ama ilk karşı örnek $n=40$'tır: $40^2+40+41 = 1681 = 41^2$. Yukarıdaki program da $n=40$'ı bulur.

- **Euler sanısı.** Hoca, $a^4+b^4+c^4=d^4$ eşitliğini sağlayan pozitif tam sayıların olmadığı düşüncesinin 1988'de bilgisayar aramasıyla çürütüldüğünü anlattı: $95800^4+217519^4+414560^4=422481^4$ (python ile doğrulandı). Dört iç içe döngüyle kaba kuvvet araması $N^4$ karmaşıklıktadır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
