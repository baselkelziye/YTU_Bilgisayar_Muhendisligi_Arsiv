# Ders 8 Çalışma Özeti

## Genel Konular

- İki sıralı dizinin birleştirilmesi (merging two sorted arrays)
  - Girdi: $N$ elemanlı sıralı `L1` ve $M$ elemanlı sıralı `L2`; çıktı: $N+M$ elemanlı sıralı `L3` (ekrandan, 00:10:00).
  - Birinci yaklaşım: önce iki diziyi arka arkaya kopyala ($N+M$ işlem), sonra iyi bir sıralama algoritmasıyla sırala ($N \log N$). Toplam $N\log N + N + M \approx N \log N$ (ekrandan, 00:20:00). Kötü bir sıralama algoritmasıyla $N^2$'ye çıkar.
  - İkinci yaklaşım: her dizide bir işaretçi (indis) tutulur; iki işaretçinin gösterdiği elemanlardan küçük olan sonuç dizisine yazılır ve o dizinin işaretçisi bir ilerletilir.
  - Dizilerden biri önce biterse diğerinin kalan elemanları karşılaştırma yapmadan doğrudan kopyalanır.
  - Alternatif çözüm: iki dizinin sonuna "çok büyük bir sayı" (örneğin `int`'in en büyük değeri) eklenir; böylece biten dizi karşılaştırmayı hiç kazanamaz ve kalan elemanları kopyalayan ek kısma gerek kalmaz. Bedeli diziyi bir eleman genişletmektir.
  - Karmaşıklık: sıralama yapılmadığı için $N+M$, yani $N \approx M$ kabul edilirse $O(N)$.
- Dizide eleman arama (doğrusal arama, linear search)
  - Baştan başlanır, eleman bulunana ya da dizi bitene kadar bakılır: `while(i < N && dizi[i] != key) i++;` Sonra `i == N` ise bulunamadı, değilse `i`. konumda bulundu.
  - En iyi durum 1, en kötü durum $N+1$ (son deneme dizinin dışı, yani bulunamama), ortalama $N/2 \approx N$ deneme (ekrandan, 01:05:00).
- Sıralı dizide eleman arama: ikili arama (binary search)
  - Ortadaki elemana bakılır; aranan değer ortadakinden büyükse sağ yarı, küçükse sol yarı aranır. Her adımda arama uzayının yarısı atılır.
  - `i = 0`, `j = N-1`, `mid = (i+j)/2`; döngü `i <= j` ve `dizi[mid] != key` iken döner. Sonunda `i > j` ise bulunamadı, değilse `mid` konumunda bulundu.
  - Karmaşıklık: $N/2^k = 1 \Rightarrow k = \log_2 N$. 1024 elemanda doğrusal arama 1024, ikili arama 10 adımda biter.
  - Sayısal analizdeki kök bulmada kullanılan ikiye bölme (bisection) yöntemine benzer.
- İnterpolasyon araması (interpolation search)
  - İkili aramayla aynı koddur; yalnız orta nokta, regula falsi yöntemindeki gibi doğrusal interpolasyonla tahmin edilir (ekrandan, 01:25:00):
    - `mid = lo + ((double)(hi - lo) / (list[hi] - list[lo])) * (data - list[lo]);`
  - Değerler düzgün dağılmışsa sonuca çok hızlı gider: örnek dizide 33 bir karşılaştırmada, ikili aramada dört karşılaştırmada bulundu (7. konum).
  - Aranan eleman dizide yoksa aynı noktada takılıp sonsuz döngüye girebilir (derste 32 aranınca görüldü).
- Bir dizinin sıralı olup olmadığının kontrolü
  - Ardışık elemanlar karşılaştırılır; `d[i+1] <= d[i]` bulunursa dizi (artan sırada) sıralı değildir.
  - `for` ile hepsine bakmak yerine `while(i < N-1 && sorted == 1)` ile ilk karşı örnekte durulur. İki çözüm de $O(N)$.
  - Diziyi sıralayıp kopyası ile karşılaştırmak da bir çözümdür ama sıralama maliyeti yüzünden $N \log N$'dir.
- Pointer'lar ve bellek organizasyonu
  - Derlenip çalıştırılan programa işletim sistemi bellekte yer ayırır; bu yerde program kodu, veriler ve sürece ait bilgiler bulunur.
  - Data section içinde stack, heap, global değişkenler ve static değişkenler vardır (ekrandan, 02:00:00). Yerel değişkenler ve sabit boyutlu diziler stack'te tutulur.
  - Stack, tabak yığını gibi çalışır: en üste eklenir, en üstten alınır. Çağrılan her fonksiyon (önce `main`) stack'e eklenir.
  - `%p` ile yazdırılan adresler değişkenlerin bellekte ardışık ve düzenli yerleştiğini gösterir; `int` 4 bayttır, pointer genellikle 8 bayttır.
  - Pointer değişkeni bir değişkenin adresini tutar: `int *pa; pa = &a;` ya da `pa = &ar[0];` (ekrandan, 02:15:00).
  - İki operatör: adres/referans operatörü `&`, değer/dereferans operatörü `*`. Pointer'ın türü gösterdiği değişkenin türüyle aynı olmalıdır (`float *pf = &f;`).
- Fonksiyonlara giriş
  - Kopyala-yapıştır ile çoğaltılan kod yerine bir kez yazılıp tekrar kullanılan fonksiyon yazılır: `void yazdir(int a[], int n)`.
  - Fonksiyona giden değişkenler değer olarak kopyalanır; fonksiyondaki `n` ile `main`'deki `n` farklı kapsamdadır (scope).
  - `takas(x, y)` değer kopyaladığı için `main`'deki değerleri değiştirmez; `takasv2(&x, &y)` adresleri alıp `*x`, `*y` üzerinden işlem yaptığı için değiştirir.
  - `scanf("%d", &i)` bu yüzden adres ister: fonksiyonun değiştirdiği değerin çağırana yansıması gerekir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir döngünün ne zaman biteceği belli değilse `for` yerine `while` kullanılmalıdır
  - Birleştirmede hangi dizinin önce biteceği, aramada elemanın nerede bulunacağı bilinmez. Bu durumda `for` "döngünün doğasına aykırı" olur.
- Gereksiz `if` kontrolünden kaçınmak
  - Birleştirmede döngü sonrasında hangi dizinin bittiğini `if` ile sormak yerine iki `while` yazılır; bitmiş dizinin `while`'ı hiç çalışmaz.
- Algoritma her durumda çalışmalıdır (genelleştirilebilirlik)
  - Öğrencilerin önerdiği çözümler, dizilerden birinin çok kısa olduğu ya da elemanların iç içe geçtiği örneklerle denendi; dizinin dışına çıkma ve eleman kaybı gibi açıklar gösterildi.
- Karşı örnek yaklaşımı (counter example)
  - Bir şeyin doğruluğunu ispatlamak zordur, yanlışlığını tek bir örnekle göstermek kolaydır. Sıralılık kontrolünde ilk karşı örnekte durulur.
- Sıralama maliyetinden kaçınmak
  - Birleştirmede ya da sıralılık kontrolünde sıralama algoritması çalıştırmak karmaşıklığı $N \log N$'ye çıkarır.
- Fonksiyonda değişikliğin çağırana yansıması için adres gönderilmelidir
  - Değerle çağrıda fonksiyon kendi kopyasıyla çalışır; adresle çağrıda bellekteki asıl hücre değişir.

## Kısa Tekrar Notları

- İki sıralı diziyi birleştirme: iki indis, küçük olanı al, onun indisini ilerlet; biten diziden sonra kalanı kopyala. $O(N+M)$.
- Sona çok büyük sayı (sentinel) koymak, kalan kısmı kopyalama kodunu gereksiz kılar.
- Segmentation fault: dizinin dışındaki, erişim izni olmayan belleğe gidildiğinde işletim sistemi programı kapatır.
- Doğrusal arama: en iyi 1, en kötü $N+1$, ortalama $\approx N/2 \approx N$.
- İkili arama yalnız sıralı dizide çalışır; $O(\log_2 N)$.
- İnterpolasyon araması orta noktayı değerlere göre tahmin eder; düzgün dağılımda hızlıdır, aranan yoksa takılabilir.
- Sıralılık kontrolü: `while(i < N-1 && sorted == 1)` ile ilk bozulmada çık.
- `&` adres verir, `*` adresteki değeri verir; `int *p` tanımında `*` pointer olduğunu belirtir.
- Fonksiyona değer gönderilirse kopyalanır, adres gönderilirse asıl değişken değişir.
- Ayrı fonksiyonların aynı adlı değişkenleri birbirini etkilemez; her çağrının stack'te kendi alanı vardır.

## Detaylı Açıklamalar

- **İki sıralı diziyi birleştirme kodu.** Hocanın Dev-C++'ta yazıp çalıştırdığı kod (ekrandan, 00:35:00 ve 00:45:00). Bu tam program `gcc -Wall` ile derlendi ve çalıştırıldı; çıktısı ekrandaki çıktıyla aynıdır (ekrandan, 00:40:00).

```c
#include <stdio.h>
#define N 15
#define M 3
int main(){
    int d1[N], d2[M], d3[N+M];
    int i, j, k;
    printf("Dizi-1:");
    for(i=0;i<N;i++){ d1[i] = 2*i+1; printf("%d ", d1[i]); }
    printf("\nDizi-2:");
    for(j=0;j<M;j++){ d2[j] = 2*j; printf("%d ", d2[j]); }
    k=i=j=0;
    while(i<N && j<M){
        if(d1[i] <= d2[j]){ d3[k] = d1[i]; i++; }
        else{ d3[k] = d2[j]; j++; }
        k++;
    }
    while(i<N){ d3[k] = d1[i]; i++; k++; }
    while(j<M){ d3[k] = d2[j]; j++; k++; }
    printf("\nDizi-3:");
    for(k=0;k<N+M;k++) printf("%d ", d3[k]);
    printf("\n");
    return 0;
}
```

```text
Dizi-1:1 3 5 7 9 11 13 15 17 19 21 23 25 27 29
Dizi-2:0 2 4
Dizi-3:0 1 2 3 4 5 7 9 11 13 15 17 19 21 23 25 27 29
```

  - İlk denemede son iki `while` döngüsünde diziler ters yazıldığı için indisler güncellenmedi ve program segmentation fault verdi; `while(i<N)` döngüsünün `d1[i]`'yi, `while(j<M)` döngüsünün `d2[j]`'yi kopyalaması gerektiği düzeltildi.
  - Karmaşıklık: ilk `while` en fazla $N+M$ kez döner; kalan iki `while`'dan biri çalışır. Toplam iş her durumda $N+M$'dir; $N \approx M$ alınırsa $2N$, sabit atılınca $N$.
- **Tek `for` ile birleştirme denemesi (bir öğrencinin önerisi).** `for(i=0; i<N+M; i++)` içinde `if (x < N && a[x] <= b[y]) {...} else if (y < M) {...}` yazıldı (ekrandan, 00:50:00). Elemanları iç içe geçen dizilerde ikinci dizi önce bitince, birinci dizinin kalan elemanı hiçbir koşula girmez; sonuç dizisinde bir hücre boş kalır, bir eleman kaybolur ve `b[y]` dizinin dışından okunur. Derste bir elemanın kaybolduğu ve yerine bellekteki rastgele bir değerin yazıldığı görüldü.
- **İkili arama ile interpolasyon aramasının karşılaştırılması.** Örnek dizi `{10, 14, 19, 26, 27, 31, 33, 35, 42, 44}` (ekrandan, 01:25:00). 33 arandığında interpolasyon araması ilk tahminde $mid = 0 + \frac{9}{34}\cdot 23 \approx 6$ bulur; `list[6] = 33`, yani bir karşılaştırma yeter. İkili arama 4, 7, 5, 6 orta noktalarından geçerek dört karşılaştırmada aynı yeri bulur. Programlar 1'den başlayan konum yazdırdığı için sonuç "7. konum"dur.
- **İnterpolasyon aramasının takılması.** 32 arandığında ilk tahmin 5 olur (`list[5] = 31 < 32`), `lo = 6` yapılır. Sonra `lo = 6`, `hi = 9` iken formül $6 + \frac{3}{11}\cdot(32-33) \approx 5{,}7$ verir; tamsayıya çevrilince yine 5 olur ve `lo` hep 6'da kalır. Ekranda "mid = 5" satırının tekrar tekrar yazıldığı görüldü (ekrandan, 01:40:00). İkili aramada bu sorun olmaz; 32 için "bulunamadı" sonucu verir.
- **Kitap benzetmesi.** 500 sayfalık kitapta 100. sayfayı aramak: doğrusal arama sayfaları tek tek çevirir, ikili arama hep ortayı açıp yarıya böler, interpolasyon araması ise insanın kitabı aradığı sayfaya yakın bir yerden tahminle açmasına benzer.
- **Pointer örneği.** `int i; float f; int *pa; float *pf; pa = &i; pf = &f;` (ekrandan, 02:10:00). `printf("%p", &i)` ile `printf("%p", pa)` aynı adresi yazar. `*pa` ve `*pf` ile değişkenlerin değerlerine ulaşılır; `%d` ile `pa`'nın kendisini yazdırmak adres değerini verdiği için yanlış sonuç gösterir.
- **Değerle ve adresle çağrı.** `takas(int x, int y)` içindeki takas `main`'e yansımaz (`x=2, y=6` iki kez yazılır). `takasv2(int *x, int *y)` içinde `t = *x; *x = *y; *y = t;` yapılınca `main`'de `x=6, y=2` olur (ekrandan, 02:40:00). Fonksiyon içinde `*x = 9999;` yazılırsa çağıranın değişkeni de 9999 olur. Bu örnekler bir tam programda `gcc -Wall` ile derlenip çalıştırılarak doğrulandı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
