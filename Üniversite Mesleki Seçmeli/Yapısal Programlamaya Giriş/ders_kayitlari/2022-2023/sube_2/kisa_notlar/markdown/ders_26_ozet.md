# Ders 26 Çalışma Özeti

## Genel Konular

- Stack bölgesinin sınırları (ekrandan, 00:10:00)
  - Yerel değişkenler ve diziler belleğin stack bölgesinde tutulur. Stack'in kapasitesi sınırlıdır: `#define MAX 984540` ile `int d[MAX];` tanımlanınca program derlenir ama çalışırken işletim sistemi tarafından durdurulur, sonraki `printf("Test")` satırına hiç gelinmez.
  - Fonksiyon parametreleri ve yerel değişkenler de stack'e konur. Fonksiyon bitince bu değişkenlerin ömrü biter, o alan başkası tarafından kullanılabilir.
  - Kapsam (scope): bir değişkene adıyla yalnız tanımlandığı blokta erişilir. Ömür (duration): değişkenin bellekte yaşadığı süre. Program boyunca yaşaması gereken, boyutu çalışırken belirlenen veriler için belleğin heap bölgesi kullanılır.
- İşaretçi tekrarı ve işaretçi aritmetiği (ekrandan, 00:15:00 ve 00:20:00)
  - `int d[MAX]={1,2,3,4,5,6,7};` ile ilk 7 eleman verilir, kalan elemanlar 0 olur.
  - `p = d;` ile `p = &d[0];` aynıdır; dizi adı ilk elemanın adresidir. `*p`, `p`'nin gösterdiği yerdeki değerdir (dereferans).
  - `*(p+3)` ile `d[3]` aynı elemanı verir. `p+3`, 3 bayt değil `3 * sizeof(int)` bayt ileri gider.
  - `%p` ile yazdırılan `&d[i]` ve `p+i` adresleri aynıdır ve `int` için 4'er artar.
  - Değer artırma: `d[i]++` ile `(*(p+i))++` aynı işi yapar. Parantez gerekir; `*(p+i)++` yazılırsa `++` işaretçiye uygulanır.
  - Alternatif: döngüde `(*p)++; p++;`. Bu durumda döngü sonunda `p` artık dizinin başını göstermez.
  - `d[3]`, `3[d]` ve `*(d+3)` aynı sonucu verir; köşeli parantez arka planda işaretçi aritmetiğidir.
- Dizi dışına erişim (ekrandan, 00:25:00)
  - `d[103]`, `103[d]`, `*(p+103)` 100 elemanlı dizide derlenir ve bazen çalışır ama yasal değildir. Daha uzağa (`1003` gibi) gidince program çökebilir. Başka bilgisayarda ya da başka koşulda farklı davranabilir.
- Çalışma anında boyut belirleme (ekrandan, 00:30:00)
  - `scanf` ile okunan `N` ile `int dizi2[N];` tanımı hocaya göre doğru kullanım değildir: stack'te ne kadar yer olacağı bilinmez, bir bilgisayarda çalışan kod RAM'i az olan bir bilgisayarda çalışmayabilir.
  - Doğru yol heap'ten işletim sistemi aracılığıyla yer istemektir.
- `malloc` (ekrandan, 00:35:00)
  - `stdlib.h` içindedir. `array = (int*) malloc(N*sizeof(int));` bayt cinsinden yer ister, başarılıysa alanın başlangıç adresini döndürür.
  - `sizeof` fonksiyon değil operatördür; türün o makinedeki boyutunu verir.
  - Yer verilmezse `NULL` döner. Belleğe erişmeden önce `if(array != NULL)` kontrolü yapılır; yoksa program çöker. C'de büyük harfle `NULL` yazılır.
  - Malloc ile alınan alan dizi gibi kullanılır: `array[i]`, `scanf("%d",&array[i])`, `scanf("%d",(array+i))`, `*(array+i)` hepsi geçerlidir.
  - `malloc` alanı temizlemez; içinde çöp değerler olabilir (derste çoğu 0 göründü ama bazı hücreler 0 değildi).
- `calloc`, `free`, `realloc` (ekrandan, 00:40:00 ve 00:45:00)
  - `calloc(N, sizeof(int))`: eleman sayısı ve eleman boyutu ayrı verilir, alan sıfırlanarak verilir.
  - `free(array)`: işi biten alanı sisteme iade eder. İade edilmezse bellek sızıntısı (memory leak) olur. Benzetme: kalkınca başkasının oturabildiği sandalye.
  - `realloc(array, N*sizeof(int))`: alınmış alanı küçültür ya da büyütür. Gerekirse veriyi yeni bir adrese kopyalar.
  - `realloc` başarısız olursa `NULL` döner; sonuç doğrudan `array`'e yazılırsa eski alanın adresi kaybolur. Bu yüzden sonuç geçici `tarray`'e alınır, `NULL` değilse `array = tarray;` yapılır.
  - Aynı yöntemle `int` yerine yapı (struct) türünden dinamik diziler de oluşturulabilir (örnek: `x`, `y` alanlı `Point`).
- Kumarbaz problemi (ekrandan, 00:50:00 ve 00:55:00)
  - Her oyunda $p$ olasılıkla 1 TL kazanılır, $1-p$ olasılıkla 1 TL kaybedilir. Elinde $N$ TL olan kişi $M+N$ TL'ye ulaşırsa kazanır, 0 TL'ye düşerse kaybeder. Kazanma olasılığı sorulur.
  - Tek oyun benzetimi: `while (n<h) && (n>0)` döngüsünde `rand() > (1-p)` ise `n=n+1`, değilse `n=n-1`; para dizisi `R(t)` çizdirilir.
  - Çok sayıda tekrar ($K=10000$) ile kazananların oranı `kaz/K` bulunur.
  - Sonuçlar ($p=0.473$): $n=100, m=10$ için 0.339; $n=1000, m=10$ için 0.341; $m=20$ için yaklaşık 0.115; $m=100$ için yaklaşık 0.00002.
  - Kazanma olasılığı başlangıç parasına neredeyse bağlı değildir, hedeflenen kâr $m$ arttıkça hızla düşer. Kumarhanede her zaman kazanan kasadır.
- Doğum günü paradoksu (ekrandan, 01:05:00 ve 01:10:00)
  - $N$ kişide en az iki kişinin aynı gün doğma olasılığı $1 - P(\text{hepsi farklı})$ ile hesaplanır.
  - $P = 1 - \dfrac{365 \cdot 364 \cdots (365-N+1)}{365^N} = 1 - \dfrac{365!}{(365-N)!\,365^N}$.
  - Excel değerleri: $N=2$ için 0.00274, $N=3$ için 0.008204, $N=4$ için 0.016356, $N=14$ için 0.223103. $N=23$'te yaklaşık %50, $N=30$'da yaklaşık %70, $N=50$'de yaklaşık %97.
  - $365!$ Excel'de hesaplanamaz (sayı hatası); çarpım adım adım yapılmalıdır.
  - Model, doğum günlerinin yıl boyunca düzgün (uniform) dağıldığını varsayar.
- Görüntüde tuz-biber gürültüsü (ekrandan, 01:25:00)
  - Gri seviye görüntüde 0 siyah, 255 beyazdır. Rastgele siyah ve beyaz noktalara tuz-biber (salt and pepper) gürültüsü denir. Görüntü `.pgm` dosyasıdır; okuma ve yazma hazır fonksiyonlarla yapılır.
- Ortalama filtresi (ekrandan, 01:30:00 ve 01:35:00)
  - 3×3'lük bir pencere görüntü üzerinde gezdirilir; penceredeki 9 değer 1 ile çarpılıp toplanır ve 9'a bölünür, sonuç yeni görüntüye yazılır.
  - Döngüler: görüntünün satır ve sütunları için iki, filtre için iki, toplam dört iç içe döngü. Sınırlar `i < N+1-filtre`, `j < M+1-filtre` ile görüntü dışına taşma engellenir.
  - Sonuç tam başarılı olmaz: gürültü de ortalamaya katılır, siyah nokta griye yaklaşır, görüntü bulanıklaşır.
  - İkinci sürüm: yalnız değeri 0 ya da 255 olan piksellerde ortalama alınır. Daha iyi ama yine tam temizlemez.
- Medyan (ortanca) filtresi (ekrandan, 01:40:00)
  - Penceredeki 9 değer bir diziye kopyalanır, sıralanır ve tam ortadaki değer (0'dan sayınca 4 numaralı indis) yeni piksele yazılır.
  - 0 ve 255 gibi uç değerler sıralamada uçlarda kalır, ortancayı etkilemez. Sonuç gürültüyü neredeyse tamamen giderir; yalnız dokunulmayan kenarlar kalır.
  - Pencere büyütülürse (9×9, 81 değer, ortanca 40 numaralı indis) işlem uzar ve görüntü fazla bulanıklaşır. Genelde 3 ya da 5 gibi tek sayılar kullanılır.
- Görüntü küçültme ve büyütme (ekrandan, 01:45:00 ve 01:50:00)
  - Küçültme (%50): ya birer atlayarak piksel alınır, ya da 2×2 komşu pikselin ortalaması alınır. Yeni matris için `malloc` ile satır ve sütun yeri açılır.
  - Büyütme: her piksel birden çok yere kopyalanabilir; daha iyisi interpolasyondur (en yakın komşu, doğrusal, kübik).
- Konvolüsyon çekirdekleri (ekrandan, 01:55:00)
  - Ortası 1, gerisi 0 olan çekirdek görüntüyü değiştirmez; tek bir 1'i kenara koymak görüntüyü bir piksel kaydırır; 1/9'lu çekirdek ortalama alır.
  - Orijinalden yumuşatılmışı çıkarmak kenarları (detayları) verir; detaylar orijinale eklenince görüntü keskinleşir.

## Hocanın Özellikle Vurguladığı Kısımlar

- "Çalıştı" demek "her zaman çalışır" demek değildir
  - Dizinin dışına taşmak ya da stack'te büyük/değişken boyutlu dizi açmak bir bilgisayarda çalışıp RAM'i az olan başka bir bilgisayarda çalışmayabilir.
- `malloc`/`realloc` sonrası `NULL` kontrolü
  - Yer açılmadıysa o belleğe erişmek programı çökertir. `realloc` sonucu önce geçici işaretçiye alınmalıdır.
- `free` ile iade
  - İade edilmeyen alan bellek sızıntısıdır.
- Medyan filtresi uç değerlere dayanıklıdır
  - Basit bir sıralama ile gürültü giderme, ortalamadan çok daha iyi sonuç verir.
- Olasılık bilgisayar bilimlerinde çok kullanılır
  - Kumarbaz ve doğum günü örnekleri, sezginin olasılıkta yanılabileceğini gösterir.

## Kısa Tekrar Notları

- Stack sınırlıdır; büyük ve boyutu çalışırken belli olan diziler heap'te açılır.
- `a[i]` ≡ `*(a+i)` ≡ `i[a]`; `p+i`, `i*sizeof(tür)` bayt ilerler.
- `(*(p+i))++` değeri artırır; parantez önemlidir.
- `malloc(N*sizeof(int))`: temizlemez. `calloc(N, sizeof(int))`: sıfırlar.
- `realloc` → geçici işaretçi → `NULL` değilse ata. `free` ile iade.
- Kumarbaz: kazanma olasılığı yaklaşık $(p/(1-p))^m$; başlangıç parasına neredeyse bağlı değil.
- Doğum günü: $1 - \dfrac{365!}{(365-N)!\,365^N}$; 23 kişide yaklaşık %50.
- Ortalama filtresi gürültüyü yayar; medyan filtresi uç değerleri atar.
- Filtre karmaşıklığı: görüntü boyutu × pencere boyutu ($M \cdot N \cdot k^2$, medyanda sıralama da eklenir).

## Detaylı Açıklamalar

- **Neden heap?** Stack'teki diziler derleme anında boyutlanır ve stack küçüktür. Ders kodunda yaklaşık bir milyon `int`'lik yerel dizi programı çökertti. Heap'ten `malloc` ile alınan alan, `free` edilene kadar yaşar ve boyutu çalışırken belirlenebilir.
- **İşaretçi ve dizi.** Derste `p = d;` sonrası `d[i]` ile `*(p+i)` karşılaştırıldı; adresler `%p` ile basıldığında ikisinin de 4'er bayt arttığı görüldü. Değer artırmada önce `d[i]++`, sonra `(*(p+i))++` yapılınca her eleman 2 artmış göründü: 1 → 3, 2 → 4, ..., sıfır olan elemanlar 2 oldu.
- **Dinamik dizi programı.** Derste yazılan programın derlenebilir hâli aşağıdadır. Kod ekrandan alınmış, `free`/`calloc` sırası ve `NULL` kontrolleri derste anlatıldığı gibi birleştirilmiştir. Dizi dışına erişen satırlar (tanımsız davranış) çıkarılmıştır. `gcc -Wall -Wextra` ile derlendi, `N=10` ve girdi `1 2 3 4` ile çalıştırıldı.

```c
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main(){
    int d[MAX]={1,2,3,4,5,6,7};
    int *p;
    int *array, *tarray;
    int i, N;
    p = d;
    printf("%d - %d\n",d[0],*p);
    p = &d[0];
    printf("%d - %d\n\n",d[3],*(p+3));
    for(i=0;i<10;i++){
        printf("%p -- %p\n",(void*)&d[i],(void*)(p+i));
    }
    for(i=0;i<10;i++){
        d[i]++;
        (*(p+i))++;
        printf("%d %d\n",d[i],*(p+i));
    }
    printf("Enter N "); scanf("%d",&N);
    array = (int*) malloc(N*sizeof(int));
    if(array == NULL){ printf("Memory not allocated\n"); return 1; }
    for(i=0;i<4 && i<N;i++){
        scanf("%d",(array+i));
    }
    for(i=0;i<4 && i<N;i++){
        printf("%d -- %d\n",array[i], *(array+i));
    }
    N = N*2;
    tarray = (int*) realloc(array,N*sizeof(int));
    if(tarray != NULL){
        array = tarray;
    }
    free(array);
    printf("Test");
    return 0;
}
```

- **Kumarbaz benzetimi.** Ders notundaki sözde kodda dış döngü $K$ kez oynatır, her oyunda para `n=en` ile başlangıca döner, iç `while` para hedefe ya da sıfıra ulaşınca biter, `n==h` ise sayaç artar. Kazanma oranı `kaz/K`'dır. Sonuçlar teorik değerle uyumludur (python ile kontrol: $(0.473/0.527)^{10} \approx 0.339$, $(0.473/0.527)^{20} \approx 0.115$).
- **Doğum günü.** Birinci kişi 365 günden birinde, ikinci kişi farklı olmak için kalan 364 günden birinde, $N$. kişi $365-N+1$ günden birinde doğar. Bu çarpım $365^N$'e bölünüp 1'den çıkarılır. Sınıf mevcudu olan 30–32 kişide olasılık yaklaşık %70–75'tir.
- **Filtreler.** Ortalama filtresinde, üç komşusu 100 olan siyah (0) piksel 4 komşu ortalamasıyla 75'e çıkar; beyaz (255) piksel ise 138,75'e iner. Yani gürültü tamamen kaybolmaz, çevreye yayılır. Medyan filtresinde 0 ve 255 sıralı dizinin uçlarına gider ve ortanca değer çevredeki gerçek gri seviyelerden biri olur.

> **Ders sonrası not:** Hoca bir işaretçinin (`p`) köşeli parantezle kullanılamayacağını söyledi (00:23:43); doğrusu `p[i]` C'de tamamen geçerlidir ve `*(p+i)` ile aynıdır. Hoca daha sonra malloc ile alınan `array` için `array[i]` kullanımını gösterdi; bu kullanım her işaretçi için geçerlidir.

> **Ders sonrası not:** Doğum günü formülünde çarpımın son terimi tahtada $365-N$, faktöriyelli biçimde payda $(364-N)!$ yazıldı; doğrusu son terim $365-N+1$, payda $(365-N)!\,365^N$'dir. Excel tablosunda 5 satırına yazılan 0.223103, derste 14 çarpanla hesaplanan $N=14$ değeridir ($N=5$ için 0.027136).

> **Ders sonrası not:** Hoca `int dizi2[N];` biçimini "illegal" diye niteledi. C99 ile bu değişken uzunluklu dizi (VLA) standarttır (C11'de isteğe bağlı); asıl sorun stack'te büyük alan istemenin güvenilmez olmasıdır. Değişkenlerin fonksiyon başında tanımlanması zorunluluğu da C89 kuralıdır, büyük olasılıkla C99 sonrası derleyicilerde zorunlu değildir. Ayrıca `float` genelde 4 bayttır.

> **Ders sonrası not:** Adreslerin `%p` çıktısında 4'er artması little-endian ile ilgili değildir; endianness bir değişkenin baytlarının bellekteki sırasıdır. Ortalama örneğinde 255 ve üç 100'ün ortalaması 138,75'tir (hoca yaklaşık 130 dedi).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
