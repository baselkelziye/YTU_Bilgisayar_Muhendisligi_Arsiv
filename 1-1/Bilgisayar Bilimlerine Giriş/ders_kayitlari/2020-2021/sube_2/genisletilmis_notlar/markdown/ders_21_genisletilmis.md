# Ders 21 Genişletilmiş Notu: Matris Çarpımının C ile Kodlanması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sanal Makineden Dosya Aktarma
- 2. Matris Çarpımı Programının Değişkenleri
- 3. Boyutların ve Matrislerin Okunması
- 4. Ara Kontrol: Okunanı Yazdırmak
- 5. Çarpma Döngüsü
- 6. Programın Testi ve Elle Doğrulama
- 7. Döngü Sırası Neden i, k, j?
- 8. Sonucun Matris Biçiminde Yazdırılması
- 9. Diğer Sorular
- Örnek Sorular

## 1. Sanal Makineden Dosya Aktarma

Dersin başında bir öğrenci, derste kurulan Ubuntu sanal makinesinde yazılan dosyaların dışarıya, yani Windows tarafına nasıl aktarılacağını sordu. Hoca birkaç yol saydı.

- **USB bellek:** Bellek bilgisayara takıldığında Windows kullanılıyorsa varsayılan olarak Windows tarafından bağlanır (mount edilir) ve erişilebilir olur. VMware Player'ın üst çubuğunda bu aygıt çıkarılabilir aygıtlar (removable devices) arasında görünür. Oradan seçilip konuğa (guest), yani içeride çalışan Linux'a bağlanır. Böylece Linux içinden erişilebilen bir alan oluşur, dosyalar buraya atılır. Sonra aynı menüden bağlantı kesilir (disconnect); aygıt yeniden Windows'a bağlanır ve dosya artık oradadır. Hoca bunun biraz uğraştıran bir yol olduğunu söyledi.
- **VMware Tools:** VMware kurulduktan sonra sürekli "yükleyeyim mi?" diye çıkan araçtır. Yüklendiğinde kopyala-yapıştır alanı iki işletim sistemi için ortak hale gelir: sanal makine içinde bir dosyayı kopyalayıp Windows'ta yapıştırmak ya da tersini yapmak, bir dosyanın içeriğinden metin kopyalayıp öteki sisteme yapıştırmak mümkün olur.
- **Sanal makinenin interneti:** İçerideki işletim sisteminin de interneti vardır; tarayıcıyla doğrudan bağlanılıp işlem oradan yapılabilir.
- **E-posta:** İçeride yazılan dosya tarayıcıdan bir e-posta hesabına girilerek kişinin kendisine gönderilebilir, dışarıda aynı hesaptan alınabilir.

Hoca bunlara şaka yollu "dosya transferinin bin bir yolu" dedi; hangisinin kullanılacağı kişinin rahat ettiği yönteme bağlıdır.

## 2. Matris Çarpımı Programının Değişkenleri

Bir önceki derste matris çarpımının mantığı konuşulmuştu. Bu derste onun C kodu yazıldı. Hoca terminalde `vi mat.c` ile yeni bir dosya açtı (ekrandan, 00:05:00).

Önce hangi değişkenlere ihtiyaç olduğu düşünüldü. İki matris çarpılırken birinin sütun sayısı ile diğerinin satır sayısının aynı olması gerekir. İki matrisin ikişer boyutu dört boyut gibi görünse de biri ortak olduğu için ayrı değişken tanımlamaya gerek yoktur; aslında üç boyut vardır. Hoca bunlara `n`, `m` ve `l` dedi: A matrisi $n \times m$, B matrisi $m \times l$. Her boyutta gezinmek için de birer indis tanımlandı: `i`, `j`, `k`.

Bunlara ek olarak bir `tmp` değişkeni tanımlandı. Bu değişken, çarpımların toplamını sonuç matrisinin gözünü her adımda yeniden indislemek yerine geçici bir değişken üzerinde biriktirmek içindir (ekrandan, 00:10:00).

Matrislerin tanımında ise şu kısıt vardır: dinamik bellek ayırma (dynamic memory allocation) henüz kullanılmadığı için matrisler statik olarak, olası durumdan biraz büyük boyutla tanımlanır (00:10:44). Bunun için bir sabit tanımlandı:

```c
#include <stdio.h>

#define DIM 25

int main(void)  {

        int i,j,k;
        int n,m,l;
        int tmp;
        int a[DIM][DIM], b[DIM][DIM], c[DIM][DIM];
        ...
```

(ekrandan, 00:15:00)

## 3. Boyutların ve Matrislerin Okunması

Kullanıcıdan önce A'nın satır sayısı, sonra sütun sayısı alınır. B için satır sayısını sormaya gerek yoktur, çünkü A'nın sütun sayısıyla aynıdır; yalnız B'nin sütun sayısı sorulur (00:12:25).

```c
        printf("Please enter # of rows for mat A : ");
        scanf("%d", &n);

        printf("Please enter # of columns for mat A : ");
        scanf("%d", &m);

        printf("Please enter # of column for mat B : ");
        scanf("%d", &l);
```

(ekrandan, 00:15:00)

Sonra A matrisinin elemanları tek tek, sorularak okunur. Ekranda önce `a[0][0] : ` çıkar, bir değer alınır; sonra `a[0][1]`, `a[0][2]` diye devam eder. B matrisi için aynı döngü kopyalanır; hoca kopyala-yapıştırın tehlikeli olabileceğini, bu yüzden sınırların B'nin boyutu olan $m \times l$'ye göre ve okunan yerin `b` olacak biçimde düzeltilmesi gerektiğini söyledi (00:14:39). Hoca, ne yapıldığı anlaşılsın diye bölümlerin başına açıklama satırları da ekledi:

```c
        /*
        * Reading first matrix
        */
        for(i = 0; i < n; i++)  {
                for(j = 0; j < m; j++) {
                        printf("a[%d][%d] : ", i, j);
                        scanf("%d", &a[i][j]);
                }
        }

        /*
        * Reading second matrix
        */
        for(i = 0; i < m; i++)  {
                for(j = 0; j < l; j++) {
                        printf("b[%d][%d] : ", i, j);
                        scanf("%d", &b[i][j]);
                }
        }
```

(ekrandan, 00:20:00)

## 4. Ara Kontrol: Okunanı Yazdırmak

Hoca çarpmayı yazmadan önce bir ara adım yaptı: "ortalık iyice karışmadan" yazılanın doğru olup olmadığını görmek için programın sonuna sonuç matrisi yerine şimdilik A matrisini yazdıran bir bölüm koydu (00:17:44). Amaç bilgilerin doğru alınıp alınmadığını kontrol etmekti.

Program 3×4'lük A ve 4×2'lik B ile çalıştırıldı. A'ya sırayla 0, 1, ..., 9, 0, 1 girildi; ekranda A matrisi `0 1 2 3 / 4 5 6 7 / 8 9 0 1` olarak düzgün göründü (ekrandan, 00:25:00). Okumada bir sorun olmadığı anlaşıldı.

> **Ek bilgi (derste anlatılmadı):** Bu tür ara çıktılar, programın büyük bir parçasını birden yazıp hatayı sonda aramak yerine, her bölümü ayrı ayrı doğrulamaya yarar. Hata çıktığında arama alanı yalnız son eklenen bölümle sınırlı kalır.

## 5. Çarpma Döngüsü

Asıl işin yapıldığı yerde hoca yine okuma döngüsünü kopyalayıp üç katlı bir döngüye çevirdi. İlk anda sınırlar kopyalanan yerden geldiği için yanlıştı (ekranda `for(i = 0; i < m; i++)` ve `for(j = 0; j < l; j++)` görünüyor; ekrandan, 00:20:00). Hoca sınırları şöyle düzeltti: `i` 0'dan `n`'e, `k` 0'dan `l`'ye, `j` 0'dan `m`'ye (00:20:01).

Döngünün içinde her seferinde `tmp` sıfırlanır, çünkü `tmp` o satırdaki bütün çarpımları biriktirecektir. İç döngüde A'nın `i, j` elemanı ile B'nin `j, k` elemanı çarpılıp `tmp`'ye eklenir. İç döngüden çıkıldığında `tmp`'de toplam vardır ve bu toplam C matrisinin `i, k` elemanı olur (00:20:45).

```c
        /*
        * Performing matrix multiplication
        */
        for(i = 0; i < n; i++)  {
                for(k = 0; k < l; k++ )  {
                        tmp = 0;
                        for(j = 0; j < m; j++) {
                                tmp += a[i][j] * b[j][k];
                        }
                        c[i][k] = tmp;
                }
        }
```

(ekrandan, 00:40:00)

Matematik olarak bu, şu formüldür:

$$c_{ik} = \sum_{j=0}^{m-1} a_{ij}\, b_{jk}, \qquad 0 \le i < n,\; 0 \le k < l$$

Sonuç matrisi $n \times l$ boyutundadır; yazdırma da bu boyutla yapılır.

## 6. Programın Testi ve Elle Doğrulama

Program derlendi (`gcc -Wall mat.c -o Mat`) ve hiç uyarı vermedi. Yeniden 3×4 ve 4×2'lik matrislerle çalıştırıldı (ekrandan, 00:25:00):

```text
A = | 1 2 3 4 |        B = | 1 2 |
    | 5 6 7 8 |            | 3 4 |
    | 9 0 1 2 |            | 5 6 |
                           | 7 8 |

Resulting matrix ---------
50      60
114     140
28      40
```

Hoca sonucun doğru olup olmadığını elle kontrol etti (00:22:15):

- **C[0][0]:** A'nın birinci satırı (1, 2, 3, 4) ile B'nin birinci sütunu (1, 3, 5, 7): $1\cdot1 + 2\cdot3 + 3\cdot5 + 4\cdot7 = 1 + 6 + 15 + 28 = 50$.
- **C[0][1]:** Aynı satır ile B'nin ikinci sütunu (2, 4, 6, 8): $1\cdot2 + 2\cdot4 + 3\cdot6 + 4\cdot8 = 2 + 8 + 18 + 32 = 60$.
- **C[1][0]:** İkinci satır (5, 6, 7, 8) ile (1, 3, 5, 7): $5 + 18 + 35 + 56 = 114$.
- **C[1][1]:** İkinci satır ile (2, 4, 6, 8): $10 + 24 + 42 + 64 = 140$.
- **C[2][0]:** Üçüncü satır (9, 0, 1, 2) ile (1, 3, 5, 7): $9 + 0 + 5 + 14 = 28$.
- **C[2][1]:** Derste sözlü hesaplanmadı; ekrandaki çıktı $9\cdot2 + 0\cdot4 + 1\cdot6 + 2\cdot8 = 18 + 0 + 6 + 16 = 40$ (ara adım eklendi).

Kod bu nottaki haliyle `gcc -Wall` ile derlendi ve aynı girdiyle çalıştırıldı; uyarı çıkmadı, sonuç ekrandakiyle aynıdır (ajan testi). Hesap python ile de doğrulandı.

> **Hocanın vurgusu:** Tek bir örnekle doğru çalışıyor gibi görünmesi yeterli değildir. Yüzde yüz emin olmak için başka bir matrisle de denemek gerekir.

## 7. Döngü Sırası Neden i, k, j?

Bir öğrenci ikinci döngüde `k`, üçüncüde `j` kullanıldığını, sıranın "önce i, sonra j, sonra k" olması gerekmez mi diye sordu (00:25:21). Hoca önce, bir şey ezberlemeye çalışmadan yapılan işin ne olduğunu anlamak gerektiğini söyledi. Tablet yanında olmadığı için çizerek göstermek yerine bir metin dosyası (`matris.txt`) açtı ve aynı örneği oraya yazdı. Önce sonuç gözlerini sayılarla, sonra indislerle açık açık yazdı (ekrandan, 00:30:00 ve 00:35:00):

```text
(1*1 + 2*3 + 3*5 + 4*7)      (1*2 + 2*4 + 3 * 6 + 4*8)
(5*1 + 6*3 + 7*5 + 8*7)      (5*2 + 6*4 + 7 * 6 + 8*8)
(9*1 + 0*3 + 1*5 + 2*7)      (9*2 + 0*4 + 1 * 6 + 2*8)

(a[0][0]*b[0][0] + a[0][1]*b[1][0] + a[0][2]*b[2][0] + a[0][3]*b[3][0] )
(a[0][0]*b[0][1] + a[0][1]*b[1][1] + a[0][2]*b[2][1] + a[0][3]*b[3][1] )
```

(Dosyada ikinci ve üçüncü satırların indisli halleri de aynı biçimde yazılıdır; `a[1][...]` ve `a[2][...]` ile.)

Hoca bu yazılışın üzerinden indislerin nasıl değiştiğini inceledi:

- **İlk satıra bakınca:** A'nın ilk indisi her terimde 0'dır, çünkü hep A'nın ilk satırı kullanılır. A'nın satır boyutu `n`, indisi `i` olduğuna göre `i`, bir çarpma satırı içinde hiç değişmez.
- **Terimden terime:** A'da `a[0][0]`, `a[0][1]`, ... diye sütunlarda ilerlenir; B'de aynı boyuta sahip satırlarda `b[0][0]`, `b[1][0]`, ... diye ilerlenir. Bu ortak boyut `m`'dir ve indisi `j`'dir. Toplamın içinde sürekli değişen budur.
- **Sağdaki göz:** Aynı A satırı bu kez B'nin bir sonraki sütunuyla çarpılır; bunun için B'nin sütun indisinin 1 olması gerekir. Yani aynı toplama B'nin her sütunu için bir kez daha yapılır. B'nin iki sütunu olduğu için iki kez; üç sütunlu olsaydı üç kez yapılır, sonuç da 3×3 olurdu.
- **Alt satıra geçince:** Aynı işler A'nın bir sonraki satırı için tekrarlanır.

Bu yüzden toplama indisi `j` en içtedir; onun bir üstünde B'nin sütun sayısı kadar dönen `k`, en dışta A'nın satır sayısı kadar dönen `i` vardır. Hoca bir de sonucun boyutuna dikkat çekti: 3×4 ile 4×2 çarpılınca sonuç 3×2'dir, "ortadaki boyut uçar".

> **Hocanın vurgusu:** Görülen örneklerde `a`, `i`, `j`, `k` sırası olması, onları sırayla yazmak gerektiği anlamına gelmez. Bu adlar yalnız boyutları ve o boyutlarda gezinmek için kullanılan indisleri sembolize eder. Yapılacak iş gerektiriyorsa yerleri değişir; önemli olan işlemin ne olduğudur.

Hoca öğrenciye ekrana bakmakla yetinmemesini, bir matris alıp `i`, `j` ve `k`'nın döngü içinde tek tek hangi değerleri aldığını analiz etmesini, `a[i][j]` ve `b[j][k]`'nın hangi elemanlara denk geldiğini çıkarmasını ve "önce i, sonra j, sonra k olsaydı ne olurdu" sorusunu düşünmesini önerdi (00:39:03).

## 8. Sonucun Matris Biçiminde Yazdırılması

Son bölüm sonuç matrisini yazdırır (ekrandan, 00:40:00):

```c
        /*
        * Print matrix
        */
        printf("Resulting matrix ---------\n");
        for(i = 0; i < n; i++)  {
                for(j = 0; j < l; j++) {
                        printf("%d\t", c[i][j]);
                }
                printf("\n");
        }


        return 0;
}
```

Matris iki boyutlu bir dizidir. Dıştaki `for` satırları, içteki `for` sütunları gezer. Her satırda o satırdaki elemanların her biri yazdırılır ve aralarına `\t` (sekme) konur; yani iki eleman arasında boşluk bırakılır. Satır bitince en sona `\n` (yeni satır) konur; böylece bir satırdaki iki, üç ya da beş eleman aynı satıra yazılır, sonra yeni satıra geçilir.

Bir öğrenci bu `printf`'lerin neden yazıldığını sorunca hoca `\t`'yi kaldırıp programı 3×4 ve 4×2 boyutlarıyla, A'ya 1'den 12'ye kadar değerler girerek yeniden çalıştırdı (ekrandan, 00:45:00; 00:44:17). Sayılar birbirine yapıştığı için sonuç matrise benzemiyordu.

> **Ek bilgi (derste anlatılmadı):** Bu denemede B yine 1-8 olduğu için doğru sonuç `50 60 / 114 140 / 178 220`'dir; sekme olmadan satırlar `5060`, `114140`, `178220` gibi okunur. Bu değerler ajan tarafından aynı kodla hesaplanmıştır.

<!-- BELİRSİZ: Bu denemede yalnız \t mi kaldırıldı, \n de mi değiştirildi; karede yalnız \t'nin kalktığı görülüyor, çıktının kendisi karede yok. -->

Hoca, her elemandan sonra yeni satır konsaydı çıktının tek boyutlu bir dizi gibi görüneceğini, gözle ayrıştırılamayacağını söyledi. Doğru yazdırmanın amacı sonucu düzgün görebilmektir.

> **Hocanın vurgusu:** `\t` sekme karakteridir. `printf` belgesinde `%d` gibi biçim belirteçleri ve başka kaçış karakterleri vardır; bunlara bakılması istenmişti ve bakılması istenen şeylerden de öğrenci sorumludur.

## 9. Diğer Sorular

**Soru:** `tmp += a[i][j] * b[j][k];` yazmak ile `tmp = tmp + a[i][j] * b[j][k];` yazmak arasında derleme ya da hız açısından fark var mı? (00:39:49)
**Cevap:** Hiçbir fark yoktur. Bu konu operatörler anlatılırken konuşulmuştu; `+=` için ayrıca özel bir komut (instruction) ya da başka bir şey yoktur, ikisi aynıdır.

**Soru:** Sonuç yazdırılırken `c[i][j]` kullanıldı; çarpmada `c[i][k]` yazıldığına göre burada da `c[i][k]` yazmak daha doğru olmaz mı? (00:47:07)
**Cevap:** Yalnız `c[i][k]` yazılsaydı aynı sonucu vermezdi; aynı sonuç için döngüdeki `j`'nin de `k` yapılması gerekirdi. Ama "daha doğru" diye bir şey yoktur. Bu döngü yalnız ekrana basar ve gereksiz yere başka indis kullanılmaz. Bu mantıkla B okunurken de `i` ile `j` kullanılmaması gerekirdi. Bir indis değişkeninin A, B ya da C matrisiyle bir ilişkisi yoktur; o ilişkiyi programcı kurar. İstenirse buraya `x` gibi başka bir ad bile yazılabilir, ama bu anlamsız bir hareket olur.

**Soru:** Koddaki açıklamalar ya da metinler Türkçe yazılabilir mi? (00:48:49)
**Cevap:** Yazılabilir, nasıl istenirse öyle yazılır. Ama içine Türkçe karakter yazılırsa sorun çıkabilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:25:21): Matris çarpımı kodunda döngüler neden `i`, `k`, `j` sırasındadır? `j` ile `k` yer değiştirmeli midir?

> **Çözüm (derste verildi):** Hayır. $c_{ik} = \sum_j a_{ij} b_{jk}$ toplamı ortak boyut ($m$) üzerinde yapılır; bu yüzden toplama indisi `j` en içtedir. Bu toplama B'nin her sütunu (`k`, $l$ kez) ve A'nın her satırı (`i`, $n$ kez) için tekrarlanır. İndis adlarının alfabetik sırası önemli değildir.

**Soru 2** (ekrandan, 00:30:00 ve 00:25:00): A = `1 2 3 4 / 5 6 7 8 / 9 0 1 2` ve B = `1 2 / 3 4 / 5 6 / 7 8` matrislerinin çarpımını bulun.

> **Çözüm (derste verildi):** Sonuç 3×2'dir: `50 60 / 114 140 / 28 40`. Örneğin $c_{00} = 1+6+15+28 = 50$, $c_{11} = 10+24+42+64 = 140$, $c_{20} = 9+0+5+14 = 28$. Programın çıktısı da budur.

**Soru 3** (derste sözlü, 00:39:03): Döngüler önce `i`, sonra `j`, sonra `k` olacak biçimde ters çevrilseydi ne olurdu? Kodu bir matrisle izleyip `i`, `j`, `k`'nın aldığı değerleri analiz edin.

> **Çözüm (derste verilmedi):** Sıfırlama ve atama yeri de değişmeden yalnız ortadaki ve içteki döngü başlıkları yer değiştirirse (orta döngü `j < m`, iç döngü `k < l`, `tmp = 0` ortada, gövde `tmp += a[i][j] * b[j][k];`, sonra `c[i][k] = tmp;`), iç döngü bittiğinde `k` değeri `l` olur ve `tmp` artık $a_{ij} \sum_k b_{jk}$ değerini, yani A'nın tek bir elemanı ile B'nin bir satır toplamının çarpımını tutar; bu matris çarpımı değildir ve `c[i][l]` gibi kullanılmayan bir göze yazılır. Doğru sonucun elde edilmesi için her $(i,k)$ çifti için `tmp`'nin sıfırlanması ve toplamanın `j` üzerinde yapılması gerekir. Döngü sırası `i, j, k` yapılmak istenirse toplam `tmp` yerine doğrudan sıfırlanmış `c[i][k]` üzerinde biriktirilmelidir (`c[i][k] += a[i][j] * b[j][k];`). Bu açıklama ajan tarafından yazılmış, python ile doğrulanmıştır.

**Soru 4** (derste sözlü, 00:41:23 ve 00:42:45): Sonuç yazdırılırken `\t` ve `\n` ne işe yarar, `printf("\n")` neden iç döngünün dışında, dış döngünün içindedir?

> **Çözüm (derste verildi):** `\t` aynı satırdaki elemanlar arasına sekme koyar. `\n` bir satırın bütün elemanları yazıldıktan sonra yeni satıra geçirir; bu yüzden iç döngü (sütunlar) bittikten sonra, dış döngünün (satırlar) içinde yer alır. Böylece çıktı matris biçiminde görünür.

## Dersin Toparlaması

Bu derste bir önceki derste mantığı konuşulan matris çarpımı C'de baştan sona yazıldı: boyutların ve iki matrisin okunması, okunanın ara bir yazdırmayla kontrolü, üç katlı döngüyle çarpma ve sonucun matris biçiminde yazdırılması. Program 3×4 ve 4×2'lik bir örnekle çalıştırıldı ve sonuç elle doğrulandı.

Dersin en önemli fikri, döngülerin sırasının indis adlarından değil yapılan işten çıktığıdır: toplama ortak boyut üzerinde yapıldığı için onun indisi en içtedir ve bu toplama sonuç matrisinin her gözü için bir kez tekrarlanır. Aynı şekilde döngü değişkenlerinin bir matrise ait olmadığı, yalnız sayaç oldukları vurgulandı. Yazdırmada `\t` ve `\n` kaçış karakterlerinin yeri, iki boyutlu bir dizinin ekranda okunabilir görünmesini sağlar.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
