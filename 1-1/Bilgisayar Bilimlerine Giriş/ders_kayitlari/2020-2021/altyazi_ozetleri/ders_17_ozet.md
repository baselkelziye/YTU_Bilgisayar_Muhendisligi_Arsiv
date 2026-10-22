# Ders 17 Çalışma Özeti

## Genel Konular

- Bu ders bir uygulama dersidir. Dersin ilk bölümü sınav ve ödev teslimiyle ilgili konuşmalara ayrılmıştır. Ardından birinci ara sınavın (Vize 1) soruları birlikte çözülür.
- Test bölümü (10 soru, sorular ekrandan, 01:09:54 – 01:12:56)
  - Soru 1: AND, OR, XOR, "Hepsi" ve NOT seçeneklerinden hangisi veya hangileri, toplamda en az sayıda ikili input için 1 üretir?
    - NOT tek input alır, ikili input almaz. Geriye AND, OR ve XOR kalır.
    - Doğruluk tablolarında AND yalnızca 1 girdi çifti için (1,1) 1 üretir. OR 3 çift için, XOR 2 çift için 1 üretir.
    - Cevap: AND.
  - Soru 2: Hangi bit örüntüsü (bit pattern) onaltılık (hexadecimal) notasyonda ifade edilemez? Seçenekler: `11111111`, `1001`, `110011`, `100000000001`, `1111000000000000`.
    - Onaltılık notasyonda her basamak tam 4 biti temsil eder. Bu yüzden bit sayısı 4'ün katı olmalıdır.
    - `110011` 6 bittir. Sağdaki 4 bit kodlanabilir ama soldaki 2 bit kodlanamaz.
    - Cevap: `110011`.
  - Soru 3: İkiye tümleyen (two's complement) yaklaşımıyla `00001111 + 10101010` nedir?
    - Normal ikili toplama yapılır. Elde (carry) bir sonraki basamağa aktarılır.
    - Sonuç (tahtadan, 00:59:40): `10111001`.
  - Soru 4: İkiye tümleyen yaklaşımıyla `00001111 − 10101010` nedir?
    - Çıkarma, çıkan sayının ikiye tümleyeninin toplanmasıyla yapılır.
    - `10101010` sayısının ikiye tümleyeni: bitler ters çevrilir (`01010101`) ve 1 eklenir: `01010110`.
    - `00001111 + 01010110 = 01100101`. Onluk sistemde $15 - (-86) = 101$.
    - İstenirse sayılar onluk sisteme çevrilerek de hesaplanabilir.
  - Soru 5: Hangisi ikiye tümleyen notasyonunda negatif bir sayıdır? Sayılar onaltılık verilmiştir: `3F`, `55`, `A6`, `7E`, "Hiçbiri".
    - Negatif sayının en soldaki biti 1'dir. `3` = `0011`, `5` = `0101`, `7` = `0111`, `A` = `1010`.
    - Yalnızca `A6` 1 ile başlar. Cevap: `A6`.
  - Soru 6: `01011100` bit örüntüsü bir kesirli sayıdır. 1 bit işaret (sign bit), 3 bit üs (exponent), 4 bit mantis (mantissa) kullanılır. Bu örüntü hangi sayıdır? Seçenekler: $-1\frac{1}{2}$, $1\frac{1}{2}$, $-\frac{3}{8}$, $\frac{3}{8}$, "Hiçbiri".
    - İşaret biti 0 olduğu için negatif seçenekler hemen elenir.
    - Üs `101` = 5. Fazlalık gösteriminde (excess notation) $5 - 4 = +1$.
    - Mantis `1100` olduğu için sayı $.1100$ şeklindedir. Üs +1 olduğu için nokta bir basamak sağa kayar: $1.100_2$.
    - $1.1_2 = 1 + \frac{1}{2}$. Cevap: $1\frac{1}{2}$.
  - Soru 7: Hangi yöntem nümerik değerleri en az verimlilikle kodlar? Seçenekler: ikiye tümleyen notasyonu, excess notation, ASCII, floating-point notation, işaretsiz tam sayı sistemi.
    - Diğer dört yöntem sayıları kodlamak için kullanılır. ASCII ise karakterleri kodlar.
    - ASCII'de her rakam ayrı bir byte kaplar. Örneğin 1234 için 4 byte gerekir.
    - Cevap: ASCII.
  - Soru 8: Run-length encoding ile `BBBBBBWBBBBWWWWBBBBW` sıkıştırılırsa yüzde kaç (X) daha az yer kaplar?
    - Ardışık aynı karakterler sayılır: 6 B, 1 W, 4 B, 4 W, 4 B, 1 W. Toplam $6+1+4+4+4+1 = 20$ karakter.
    - Sıkıştırılmış hâl: `6B1W4B4W4B1W`, 12 karakter.
    - $(20 - 12) / 20 = \%40$. Cevap: X = 40.
  - Soru 9: 4096 farklı renk değeri için en az kaç bit gerekir?
    - 4096 ardışık olarak 2'ye bölünür: 4096, 2048, ..., 2, 1. 12 kez bölünür. Yani $2^{12} = 4096$.
    - Cevap: 12 bit. Karşılaştırma: $2^8 = 256$, yani ASCII tablosundaki 256 sembol 8 bit (1 byte) ile saklanır.
  - Soru 10: Üç XOR kapısı art arda bağlıdır. İlk kapının girişleri 0 ve 1, sonraki kapıların ek girişleri sırasıyla 0 ve 1'dir. Çıkış nedir?
    - XOR doğruluk tablosu: $0 \oplus 0 = 0$, $0 \oplus 1 = 1$, $1 \oplus 0 = 1$, $1 \oplus 1 = 0$.
    - $0 \oplus 1 = 1$, $1 \oplus 0 = 1$, $1 \oplus 1 = 0$. Cevap: 0.
  - Hoca 10 soruyu sınıfla konuşarak ve tahtaya yazarak 14 dakikada çözdü. Süre kısıtı eleştirisini dikkate alarak bir sonraki sınavda birkaç dakika ek süre vereceğini söyledi.
- Yazılı bölüm, soru 1: onaltılık karakter dizisinin onluk karşılığı (40 puan, ekrandan, 01:20:25)
  - Soru: Bir karakter dizisinde 0-9 rakamlarından ve A-F harflerinden oluşan N adet karakter vardır. 16'lık sistemde verilen bu karakter grubunun 10'luk sistemdeki karşılığını bulan algoritmanın akış diyagramını çizip örnekler için analizini yapınız.
  - Örnekler: `1 0 A F` girdisinin çıktısı `4271`. `C B A` girdisinin çıktısı `3258`.
  - Çözüm (tahtadan, 01:28:15):
    - `char dizi[100]` gibi bir karakter dizisi kullanılır. Basamak değerleri sağdan sola $16^0, 16^1, 16^2, 16^3, \dots$ şeklindedir.
    - Karakterin sayısal değeri karakter sabitleriyle bulunur:
      - '0'-'9' için `dizi[i] - '0'`. Örneğin `'0' - '0' = 0`, `'1' - '0' = 1`.
      - 'A'-'F' için `dizi[i] - 'A' + 10`. Örneğin `'A' - 'A' + 10 = 10`, `'F' - 'A' + 10 = 15`.
    - Bunun için bir if ile karakterin hangi aralıkta olduğu kontrol edilir. Girdilerin geçerli olduğu kabul edildiği için tek kontrol yeterlidir: 0-9 aralığında değilse A-F aralığındadır.
    - Bulunan sayısal değer, basamağın $16^k$ değeriyle çarpılıp toplama eklenir.
  - Kontrol: $1 \cdot 16^3 + 0 \cdot 16^2 + 10 \cdot 16 + 15 = 4096 + 160 + 15 = 4271$. $12 \cdot 16^2 + 11 \cdot 16 + 10 = 3072 + 176 + 10 = 3258$.
- Yazılı bölüm, soru 2: matristen sütun silme (35 puan, ekrandan, 01:34:20)
  - Soru: Verilen N×M'lik bir matrisin X numaralı sütununun silinmesini sağlayan algoritmanın akış diyagramını çizip kodunu C dilinde yazınız. Sütun silme sırasında hücreler sola kaydırılmalıdır.
  - Örnek: X = 2 için

    $$
    \begin{bmatrix} 1 & 2 & 3 & 4 \\ 5 & 6 & 7 & 8 \\ 9 & 10 & 11 & 12 \end{bmatrix}
    \rightarrow
    \begin{bmatrix} 1 & 3 & 4 & 0 \\ 5 & 7 & 8 & 0 \\ 9 & 11 & 12 & 0 \end{bmatrix}
    $$

  - Çözüm (tahtadan, 01:38:30):
    - Silinecek sütunun bir sağındaki sütundan başlanır. O sütunun tüm satırlarındaki elemanlar bir sol sütuna kopyalanır.
    - Sonra bir sonraki sütuna geçilir ve aynı işlem son sütuna kadar tekrarlanır.
    - En sonda boşalan son sütuna bir kez 0 yazılır.
    - Adım sayısı belli olduğu için iki iç içe for kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınavda veya ödevde önce ne istendiğini tam anlayın. Müşterinin ne istediğini anlamayan, onun istediği çözümü üretemez. Açıklamaları dikkatle okumadan algoritmaya ve koda odaklanmayın.
- Onaltılık basamağın 4 bite karşılık geldiğini unutmayın. Bit sayısı 4'ün katı değilse onaltılık notasyonda ifade edilemez.
- İkiye tümleyen notasyonunda sayının işaretini en soldaki bit belirler. 1 ise sayı negatiftir.
- ASCII kodlarının sayısal değerlerini (ör. '0' = 48, 'A' = 65) ezberden kullanmayın. Hoca bunu derste defalarca söyledi. `dizi[i] - '0'` ve `dizi[i] - 'A' + 10` gibi karakter sabitleriyle çalışın. Sayısal değerlerle yazılan çözümlerden puan kırılır.
- Adım sayısı belli ise for, belli değilse while kullanılır. Teknik olarak çalışsa da yanlış döngü türü kavramsal bir hatadır ve bundan sonraki sınavlarda önemli puan kırılır.
- Sütun silme sorusunda son sütunun sıfırlanması bir kez, döngülerden sonra yapılmalıdır. Her adımda tekrar tekrar sıfırlamak sonucu bozmaz ama gereksiz iş yapar.
- Sıfırlanacak sütun bellidir. Döngü içinde "bu son sütun mu?" diye kontrol etmeye gerek yoktur.
- Akış diyagramında diziler 1'den, C kodunda 0'dan başlatılabilir. İkisi de kendi içinde tutarlıysa ve doğru çalışıyorsa sorun yoktur.
- Algoritma sorularında puan "çalışıyorsa 100, çalışmıyorsa 0" mantığıyla verilmez. Çözüm şekli, olayı ele alış ve yapılan hataların önemi belirleyicidir. Soru kolaysa küçük hatalar daha çok puan götürür.
- Önce doğru çözmeye çalışın, sonra verimli çözmeye. Verimliliğe takılıp doğru çözemezseniz daha düşük puan alabilirsiniz.

## Kısa Tekrar Notları

- NOT tek inputlu. AND yalnızca (1,1) için 1, OR 3 çift için, XOR 2 çift için 1 üretir.
- Hex için bit sayısı 4'ün katı olmalı.
- İkiye tümleyende çıkarma: çıkanın tümleyeni alınır (bitleri ters çevir, 1 ekle) ve toplanır.
- `00001111 + 10101010 = 10111001`.
- `00001111 − 10101010 = 00001111 + 01010110 = 01100101` (101).
- İkiye tümleyende en soldaki bit 1 ise negatif: `A6` negatif.
- `01011100` (1 işaret, 3 üs, 4 mantis): üs $5-4 = 1$, mantis $.1100$, sonuç $1\frac{1}{2}$.
- ASCII nümerik değerleri en verimsiz kodlar: her rakam 1 byte.
- RLE: `BBBBBBWBBBBWWWWBBBBW` (20) → `6B1W4B4W4B1W` (12), %40 daha az.
- 4096 renk: $2^{12}$, 12 bit. 256 sembol: $2^8$, 8 bit.
- XOR zinciri: $0 \oplus 1 \oplus 0 \oplus 1 = 0$.
- Hex karakterin değeri: rakamsa `c - '0'`, harfse `c - 'A' + 10`.
- Sütun silme: X+1'den M'e kadar sütunları bir sola kaydır, son sütunu bir kez sıfırla.

## Detaylı Açıklamalar

Dersin ilk yarısında birinci ara sınavın teslim sürecindeki sorunlar konuşulur. Hoca, sınav ve ödev açıklamalarının dikkatle okunmasının önemini vurgular. Ardından test bölümündeki 10 soru sınıfla birlikte, süre tutularak çözülür. Hoca bu çözümün 14 dakika sürdüğünü ve soruların derste anlatılan bilgilerin yorumlanmasıyla çözülebildiğini gösterir. Sonra yazılı bölümdeki iki algoritma sorusunun çözüm yolu tartışılır. Hoca, öğrencilerden bu iki sorunun akış diyagramını ve kodunu bir sonraki derse kadar yeniden çözmelerini ister.

### İkiye tümleyen ile çıkarma

İkiye tümleyen notasyonunda çıkarma işlemi ayrıca yapılmaz. $a - b$ yerine $a + (-b)$ hesaplanır. $-b$ ise $b$'nin ikiye tümleyenidir:

1. $b$'nin bütün bitleri ters çevrilir.
2. Sonuca 1 eklenir.

Soruda $b = 10101010$ idi. Bitleri ters çevrilince `01010101`, 1 eklenince `01010110` olur. Bu sayı `00001111` ile toplanır:

```text
  00001111
+ 01010110
----------
  01100101
```

Onluk sistemde kontrol: `10101010` ikiye tümleyende $-86$'dır. $15 - (-86) = 101$ ve $101 = 01100101_2$.

### Kesirli sayının çözülmesi

8 bitlik `01011100` örüntüsü şu şekilde ayrılır:

| İşaret | Üs | Mantis |
|---|---|---|
| `0` | `101` | `1100` |

- İşaret biti 0 olduğu için sayı pozitiftir.
- Üs 3 bitlik fazlalık gösterimindedir (excess-4). $101_2 = 5$ ve $5 - 4 = 1$.
- Mantis `.1100` şeklinde okunur. Üs +1 olduğu için nokta bir basamak sağa kayar: $1.100_2 = 1 + \frac{1}{2}$.

### Run-length encoding oranı

Run-length encoding, art arda tekrar eden aynı karakteri "tekrar sayısı + karakter" çiftiyle kodlar. 20 karakterlik `BBBBBBWBBBBWWWWBBBBW` dizisi `6B1W4B4W4B1W` olur ve 12 karakter kaplar. Kazanç $\frac{20 - 12}{20} = 0.40$, yani %40'tır.

### Onaltılıktan onluğa çevirme

Karakter dizisindeki her karakterin önce sayısal değeri bulunur. Rakam karakterlerinden `'0'` çıkarıldığında 0-9 arası değer elde edilir. Harflerden `'A'` çıkarıldığında 0-5 arası değer elde edilir. Harflerin değeri 10'dan başladığı için 10 eklenir.

Bir öğrenci, harflerin ASCII değerinin 65'ten, rakamların 48'den başladığını bildiği için harflerden doğrudan 55 (ya da rakam formülünden ayrıca 7) çıkardığını söyledi. Hoca bu yaklaşımı kabul etmedi. Derste ASCII tablosundaki sayısal değerlerin kullanılmaması gerektiği defalarca söylenmişti. Bu çözümlerden puan kırılacağını belirtti.

Bir başka öğrenci, karakterin 0-9 aralığında olup olmadığını iki karşılaştırmayla kontrol etmek yerine yalnızca `'A'`'dan küçük olup olmadığına baktığını söyledi. Girdilerin geçerli olduğu kabul edildiği için hoca bu çözümün de olacağını söyledi.

Her basamağın sayısal değeri, sağdan sola $16^0, 16^1, 16^2, \dots$ ile çarpılarak toplanır. Çarpan her adımda 16 ile çarpılarak güncellenebilir.

### Sütun silme

Örnekte X = 2 olduğu için ikinci sütun silinir. 3. sütun 2. sütuna, 4. sütun 3. sütuna kopyalanır. Her kopyalamada sütunun bütün satırları dolaşılır. Son sütun boşaldığı için oraya 0 yazılır.

Bir öğrenci sıfırlamayı her kaydırma adımında yaptığını söyledi. Örneğin 3. sütun 2. sütuna kopyalandıktan sonra 3. sütunu sıfırlıyor, sonra 4. sütunu 3. sütuna kopyalıyordu. Sonuç doğru çıkar, çünkü sıfırlanan sütunun üzerine bir sonraki adımda yeniden yazılır. Ancak verimli çözüm, sıfırlamayı en sonda bir kez yapmaktır.

Bir başka öğrenci, son sütunu sıfırlamak yerine okuma sırasında hiç okumamayı önerdi. Hoca bunun da mümkün olduğunu söyledi. Sorunun amacı belirli bir problemi kurgulamaktı. Gerçek hayatta boşalan kısım bellekte yer kaplamayacak şekilde düzenlenir ve bu yöntemler ileride görülecek.

### Yazılı soruların C kodu

Hoca bu iki sorunun kodunu derste yazmadı ve öğrencilere bıraktı. Aşağıdaki kodlar derste anlatılan çözüm yolunun C'ye çevrilmiş hâlidir. `gcc -Wall` ile derlendi. Sınav kağıdındaki örneklerle test edildi: `1 0 A F` için `4271`, `C B A` için `3258` ve X = 2 için beklenen matris çıktısı elde edildi.

```c
/* Onaltılıktan onluğa çevirme */
#include <stdio.h>

int main()
{
    char dizi[100];
    int N,i,deger;
    int sonuc=0,carpan=1;

    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf(" %c",&dizi[i]);

    for(i=N-1;i>=0;i--)          /* sağdan sola: 16^0, 16^1, ... */
    {
        if(dizi[i]>='0' && dizi[i]<='9')
            deger=dizi[i]-'0';
        else
            deger=dizi[i]-'A'+10;
        sonuc=sonuc+deger*carpan;
        carpan=carpan*16;
    }
    printf("%d\n",sonuc);
    return 0;
}
```

```c
/* N x M matristen X numaralı sütunu silme */
#include <stdio.h>

int main()
{
    int N,M,X,i,j;
    int matris[20][20];

    scanf("%d %d %d",&N,&M,&X);
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            scanf("%d",&matris[i][j]);

    for(j=X;j<M;j++)             /* X. sütun (1'den sayılınca) = indis X-1 */
        for(i=0;i<N;i++)
            matris[i][j-1]=matris[i][j];
    for(i=0;i<N;i++)             /* boşalan son sütun bir kez sıfırlanır */
        matris[i][M-1]=0;

    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
            printf("%d ",matris[i][j]);
        printf("\n");
    }
    return 0;
}
```

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
