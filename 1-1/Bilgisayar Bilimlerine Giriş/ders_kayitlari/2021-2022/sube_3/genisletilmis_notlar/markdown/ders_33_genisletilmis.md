# Ders 33 Genişletilmiş Notu: Sıralama Algoritmaları: Bubble Sort, Selection Sort ve Temel Yöntemler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Aramadan sıralamaya
- 2. Sıralama probleminin formal tanımı
- 3. Sıralama algoritmalarını değerlendirme ölçütleri
- 4. Bubble Sort: sezgi ve algoritma
- 5. Bubble Sort: on elemanlı örnek
- 6. Bubble Sort: C kodu
- 7. Bubble Sort'un en kötü durumu ve iyileştirme tartışması
- 8. Karşılaştırma sayarak ekstra diziyle sıralama
- 9. Selection Sort: algoritma ve akış diyagramı
- 10. Selection Sort: on elemanlı örnek
- 11. Selection Sort: C kodu ve eşit elemanlar
- 12. Konu dışı: Insertion Sort fikri
- 13. Konu dışı: Shell Sort fikri ve hibrit yaklaşım
- 14. Soru-cevap: Gerçek sistemler hangi sıralamayı kullanır?
- Örnek Sorular

## 1. Aramadan sıralamaya

Önceki derste arama algoritmaları işlenmişti: bir dizide bir elemanın nasıl arandığı, ona nasıl erişildiği. Dizi sıralıysa elde daha güçlü bir araç vardır: ikili arama (binary search). Bu da yeni bir soruyu doğurur: diziyi nasıl sıralayacağız? Bu derste sıralama problemi tanımlanır ve "düşünerek bulunabilecek" iki temel sıralama algoritması (Bubble Sort ve Selection Sort) adım adım kurulur. Dersin sonunda konu dışı olarak iki yöntemin fikri daha gösterilir.

## 2. Sıralama probleminin formal tanımı

Slayttaki tanım şöyledir (ekrandan, 00:10:00): sıralama, aynı türden nesnelerden oluşan bir koleksiyonu, birbirini büyüklük-küçüklük açısından mantıksal bir düzene sokmaktır.

- Girdi: $\{a_1, a_2, \dots, a_n\}$
- Çıktı: girdinin öyle bir $\{a_1', a_2', \dots, a_n'\}$ permütasyonu ki $a_1' \le a_2' \le \dots \le a_n'$

Yani algoritmadan beklenen, girdinin özel bir permütasyonunu üretmesidir: girdideki bütün değerler aynı tekrar sayısıyla çıktıda bulunmalı ve çıktı her koşulda küçük eşitlik zincirini sağlamalıdır.

### 2.1 Tekrar eden değerler örneği

Slayttaki örnek girdi `8 2 4 4 4 9 3 6` tamsayı dizisidir (ekrandan, 00:10:00). Üç tane 4 vardır; birbirinden ayırt edilsin diye biri siyah, biri kırmızı, biri gri yazılmıştır. Hoca bunları "10 üzerinden alınmış notlar" gibi düşünmeyi önerdi: üç kişi 4 almıştır.

- Çıktı `2 3 4 4 4 6 8 9` (siyah, kırmızı, gri sırasıyla): koşulu sağlar, bütün değerler aynı tekrar sayısıyla yer alır. Doğru bir çıktıdır.
- Aynı değerler başka renk sırasıyla çıksa (örneğin kırmızı, gri, siyah): küçük eşitlik koşulu yine sağlanır, bu da doğru bir sıralama çıktısıdır.

İki çıktı birebir aynı değildir; fark yalnız eşit değerlerin sırasındadır. Bunun önemli olup olmadığı uygulamaya bağlıdır. Örneğin bir kuyrukta aynı notu almış kişilerin geliş sırası korunmak istenebilir; istenmeyebilir de.

### 2.2 Sıralama nerede kullanılır?

Hocaya göre her yerde: sıralanmış bir girdiyle çalışması gereken her algoritmada ilk iş sıralama yapmaktır. Slayttaki kullanım alanları: transaction processing (işlem işleme), kombinatoryal optimizasyon, astrofizik, moleküler dinamik, dilbilim, genbilim, hava tahmini (ekrandan, 00:10:00).

Sıralama bu kadar temel bir problem olduğu için "her şey çalışılmış bitmiştir" diye düşünülebilir. Hoca bunun bir yere kadar doğru olduğunu söyledi: 20. yüzyılın en iyi 10 algoritmasının seçildiği bir oylamada bunlardan biri bir sıralama algoritması olan QuickSort'tur. Girdiye göre daha iyisinin yapılıp yapılamayacağı üzerine çalışmalar hâlâ sürmektedir.

> **Ek bilgi (derste anlatılmadı):** Bu liste büyük olasılıkla 2000 yılında Computing in Science & Engineering dergisinde yayımlanan "20. yüzyılın en iyi 10 algoritması" listesidir. Listede QuickSort'un yanında simpleks yöntemi ve hızlı Fourier dönüşümü (FFT) gibi algoritmalar da yer alır.

## 3. Sıralama algoritmalarını değerlendirme ölçütleri

Slayt "Sıralama Algoritmalarının Değerlendirilmesi" başlığını taşır (ekrandan, 00:15:00). Hoca bu kısmı bilgi olsun diye kısaca anlattı.

### 3.1 Performans

Performansın (başarım) ilk ölçütü çalışma zamanıdır: girdi boyutuyla orantılı olarak algoritmanın ne kadar hızlı çalıştığı. Bir milyon elemanlık bir diziyi bir algoritma 5000 saniyede, başka bir algoritma 20000 saniyede sıralıyorsa doğal olarak ilki daha iyidir. Ancak çalışma zamanı her zaman tek başına belirleyici değildir.

Bu derste görülecek algoritmaların hepsi karşılaştırmaya dayanır: bir değerin nerede durması gerektiğine, onu diğer değerlerle karşılaştırarak karar verilir. Bu yüzden ikinci ölçüt karşılaştırma ve değiştirme (swap) sayısıdır; değiştirme yoksa dizi erişim sayısı sayılır.

- Karşılaştırma sayısı: bazı mimarilerde karar (`if`) mekanizması çok maliyetli olabilir; o zaman karşılaştırması az olan algoritma tercih edilir.
- Değiştirme sayısı: her yer değiştirme bellekten okuma, yazma ve geçici bir değişken kullanımı demektir. Bellek erişimi pahalıysa karşılaştırmanın çok olması önemsenmez, ama swap sayısının en az olması istenir.

### 3.2 Ekstra bellek

- Yerinde sıralama (in-place): sıralama aynı dizi üzerinde yapılır; küçük bir fonksiyon çağrı yığıtı ya da sabit sayıda değişken kullanılabilir. Benzetme: raftaki kitapları rafta, birini alıp yerine koyarak sıralamak.
- Harici bellek alanına sıralama (out-of-place): ek bir alan kullanılır. Benzetme: kitapların hepsini yere döküp sonra sırayla rafa dizmek.

Örneğin bellek çok pahalı ve kısıtlı olan bir gömülü sistemde diziyi kopyalayıp ikinci bir dizide sonuç üretmek mümkün olmayabilir. Belleğin bol ve ucuz olduğu bir yerde ise harici bellekle daha hızlı çalışan bir yöntem seçilebilir.

### 3.3 Tekrar eden değerler

- İstikrarlı (stable): girdide tekrar eden değerler çıktıda aynı sırayla yer alır (1. tekrar ilk, 2. tekrar ikinci, ..., N. tekrar sonuncu).
- İstikrarsız (unstable): tekrarların yer garantisi yoktur.

Hoca, bilinen en verimli algoritmaların bir kısmının istikrarsız olduğunu ve normalde daha hızlı çalıştığını söyledi. Ama aynı notu alan kişilerin geliş sırasına göre kabul edilmesi gibi bir gereksinim varsa istikrarlı bir algoritma seçmek zorunda kalınabilir.

> **Hocanın vurgusu:** Tek bir doğru yok. Bellek pahalı olabilir, bazı işlemler pahalı olabilir, zamandan feragat edip yeri az kullanmak tercih edilebilir, sıra önemli olabilir ya da olmayabilir. Bütün bu ölçütler birlikte düşünülüp algoritma ona göre seçilir.

## 4. Bubble Sort: sezgi ve algoritma

Slaytta "Temel Yöntemler" başlığı altında Selection Sort, Bubble Sort, Shell Sort ve "..." yazar (ekrandan, 00:20:00). Hoca, bir algoritmayı hazır vermek yerine önce bir diziyi nasıl sıralayabileceğimizi düşünerek başladı.

### 4.1 Sezgisel başlangıç

Dizi: `A = 8 2 7 1 6 4 3` (ekrandan, 00:25:00).

1. 8 ile 2 karşılaştırılır. 8 büyük, 2 küçüktür; küçükten büyüğe sıralandığı için yer değiştirmeleri gerekir. Bunun için geçici bir değişken kullanılır: 8 geçici değişkene yazılır, 2, 8'in gözüne kopyalanır, sonra geçici değişkendeki 8 ikinci göze yazılır. Dizi: `2 8 7 1 6 4 3`.
2. 8 ilk gözdeki yerinde mi durmalı? Bunun için kalan elemanlarla da karşılaştırılması gerekir. 8 ile 7 karşılaştırılır, yer değiştirir: `2 7 8 1 6 4 3`.
3. 8 sırayla 1, 6, 4 ve 3 ile de karşılaştırılıp her seferinde sağa geçer: `2 7 1 6 4 3 8`.

Karşılaştıra karşılaştıra dizinin en büyük elemanı en sona taşınmış olur. Geriye `2 7 1 6 4 3` kalır; aynı işlem bu kalan kısım için tekrarlanır ve her seferinde kalanların en büyüğü yerine gider. Tahtada sonuç `1 2 3 4 6 7 8` olarak yazılmıştır (ekrandan, 00:25:00).

### 4.2 Algoritmanın kurulması

Bu sezgiden iki iç içe döngü çıkar:

- Dış döngü (`i`): `n-1` kez döner (algoritmada 1'den `n-1`'e ya da 0'dan `n-2`'ye). Neden `n-1`? 7 elemanlı dizinin 6 elemanı yerine oturduktan sonra geriye tek bir eleman kalır; tek elemanlık dizi zaten sıralıdır, onun üzerinde işlem yapmaya gerek yoktur.
- İç döngü (`j`): `n-1-i`'ye kadar gider. `n-1` dizinin sonuna kadar gitmek demektir; `-i` kısmı ise dış döngü ilerledikçe iç döngünün birer birer daha az eleman gezmesini sağlar (ilk adımda sona kadar, ikinci adımda sondan bir önceye, üçüncüde sondan iki önceye...).
- Karşılaştırma: `j+1` indisindeki eleman `j` indisindeki elemandan küçük mü? Küçükse ikisi yer değiştirir (swap). Değilse bir şey yapılmaz.
- Döngülerden önce dizi okunur, sonra sonuç yazdırılır.

<!-- BELİRSİZ: Bubble Sort'un sözde kodunun yer aldığı slayt karelerde görünmüyor; yukarıdaki yapı anlatımdan ve derste yazılan C kodundan kurulmuştur. -->

## 5. Bubble Sort: on elemanlı örnek

Örnek C'de kodlanacağı için indisler 0'dan başlar (`i = 0` ile başlanır, `n-2`'ye kadar gidilir). Girdi dizisi (indis 0-9) (ekrandan, 00:30:00):

| indis | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|---|
| A | 8 | 5 | 2 | 6 | 9 | 3 | 1 | 4 | 0 | 7 |

### 5.1 i = 0

8 ile 5 karşılaştırılır, yer değiştirir. 8 ile 2, sonra 8 ile 6 karşılaştırılır, her seferinde yer değiştirir. 8, sıfırıncı indisten üçüncü indise taşınmıştır.

> **Hocanın benzetmesi:** Büyük eleman, kola ya da gazozdaki kabarcıklar gibi bardağın dibinden (dizinin sıfırıncı gözünden) ağzına (dizinin sonuna) doğru "fokur fokur" yükselir. Algoritmanın adı buradan gelir: Bubble Sort, kabarcık sıralama.

8 ile 9 karşılaştırılır; 9 daha büyük olduğu için yer değiştirme olmaz. 8 orada kalır, artık kabarcık 9'dur. 9 sırayla 3, 1, 4, 0 ve 7 ile karşılaştırılıp her seferinde sağa geçer. `n-1`'e kadar gelindiği için iç döngü biter. Sonuç: `5 2 6 8 3 1 4 0 7 9`. 9 yerini bulmuştur; slaytta gri boyanır.

### 5.2 i = 1

İç döngü artık son gözü gezmez (ekrandan, 00:35:00). 5 ile 2 yer değiştirir; 5 ile 6, 6 ile 8 yer değiştirmez. 8 ile 3 karşılaştırılınca 8 "fokurdamaya" başlar: 3, 1, 4, 0 ve 7 ile yer değiştirir. Sonuç: `2 5 6 3 1 4 0 7 8 9`. Bu adımda iç döngü on değil dokuz eleman için çalışmıştır; dizinin ikinci büyük elemanı sondan ikinci yere yerleşmiştir.

Slayttaki ara satırlar (her satır bir karşılaştırmadan sonraki durum, ekrandan, 00:35:00):

| j | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|---|
| başlangıç | 5 | 2 | 6 | 8 | 3 | 1 | 4 | 0 | 7 | 9 |
| 0 | 2 | 5 | 6 | 8 | 3 | 1 | 4 | 0 | 7 | 9 |
| 1 | 2 | 5 | 6 | 8 | 3 | 1 | 4 | 0 | 7 | 9 |
| 2 | 2 | 5 | 6 | 8 | 3 | 1 | 4 | 0 | 7 | 9 |
| 3 | 2 | 5 | 6 | 3 | 8 | 1 | 4 | 0 | 7 | 9 |
| 4 | 2 | 5 | 6 | 3 | 1 | 8 | 4 | 0 | 7 | 9 |
| 5 | 2 | 5 | 6 | 3 | 1 | 4 | 8 | 0 | 7 | 9 |
| 6 | 2 | 5 | 6 | 3 | 1 | 4 | 0 | 8 | 7 | 9 |
| 7 | 2 | 5 | 6 | 3 | 1 | 4 | 0 | 7 | 8 | 9 |

### 5.3 Sonraki adımlar

- `i = 2`: 2-5 değişmez; 5-6 değişmez; 6 sırayla 3, 1, 4, 0 ile yer değiştirir; 7'yi geçemez. Sonuç: `2 5 3 1 4 0 6 7 8 9`.
- `i = 3`: 2-5 değişmez; 5 sırayla 3, 1, 4, 0 ile yer değiştirir; 6'yı geçemez. Sonuç: `2 3 1 4 0 5 6 7 8 9`.
- `i = 4`: 2-3 değişmez; 3 ile 1 yer değiştirir; 3-4 değişmez; 4 ile 0 yer değiştirir; 4-5 değişmez. Sonuç: `2 1 3 0 4 5 6 7 8 9`.
- `i = 5`: 2 ile 1 yer değiştirir; 2-3 değişmez; 3 ile 0 yer değiştirir; 3-4 değişmez. Sonuç: `1 2 0 3 4 5 6 7 8 9`.
- `i = 6`: 1-2 değişmez; 2 ile 0 yer değiştirir; 2-3 değişmez. Sonuç: `1 0 2 3 4 5 6 7 8 9`.
- `i = 7`: 1 ile 0 yer değiştirir; 1-2 değişmez. Sonuç: `0 1 2 3 4 5 6 7 8 9`.
- `i = 8`: 0 ile 1 karşılaştırılır, değişiklik yok (ekrandan, 00:40:00).

Dizi aslında `i = 7` adımından sonra sıralıdır, ama algoritma bunu bilmez; kalan elemanların sıralı olup olmadığını kontrol etmek zorundadır. `i = 8`'den sonra geriye tek eleman kalır; tek elemanlı dizi kendi içinde sıralı olduğu için durulur. Bu ara sonuçlar python ile doğrulandı.

Hoca şunu vurguladı: her adımda daha az sayıda karşılaştırma yapılır, ama toplamda her eleman çiftinin bir `if` işleminden geçmesi gerekir.

## 6. Bubble Sort: C kodu

Kod OnlineGDB'de yazıldı (ekrandan, 00:45:00). Boyut hız için `#define` ile tanımlandı; swap için tek bir geçici değişken (`tmp`) kullanıldı. Karşılaştırma algoritmadaki "`a[j+1] < a[j]`" yerine eşdeğeri olan `a[j] > a[j+1]` biçiminde yazıldı.

```c
/*****************
 * Bubble sort   *
 *               *
 * ***************/

#include <stdio.h>
#define n 5

int main()
{
    int a[n]={81, 23, 16, 4, 55};
    int i,j, tmp;

    for(i=0; i<n-1; i++)
        for(j=0; j<n-1-i; j++)
            if (a[j]>a[j+1]){
                tmp = a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }

    for (i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}
```

- İlk çalıştırmada dizi `{8, 2, 6, 4, 5}` idi; çıktı `2 4 5 6 8`.
- Dizi `{81, 23, 16, 4, 55}` yapılınca çıktı `4 16 23 55 81` oldu (ekrandan, 00:45:00).

Kod `gcc -Wall` ile uyarısız derlendi ve iki dizi için çalıştırıldı; çıktılar derstekiyle aynıdır. Sıralama A dizisi üzerinde ve yalnız tek bir ekstra değişkenle yapılmıştır.

Özetle Bubble Sort en temel, en basit, ilk akla gelen sıralama yöntemidir: dış döngünün her adımında kalan elemanların en büyüğünü bulup sona taşır. Bunu "körlemesine" yapar: her seferinde bakar, yer değiştirmesi gerekiyorsa değiştirir.

## 7. Bubble Sort'un en kötü durumu ve iyileştirme tartışması

### 7.1 En kötü durum

Hoca, hangi girdinin en çok atama (yer değiştirme) işlemine yol açacağını sordu. Cevap: tersten sıralı dizi. Örnek: `88 77 66 55 44`.

- 88 sırayla 77, 66, 55 ve 44 ile karşılaştırılır ve her seferinde yer değiştirir; sona yerleşir.
- Kalan kısım hâlâ tersten sıralıdır; 77 de her elemanla yer değiştirerek ilerler. Bu böyle sürer.

Hoca bunu kabaca "$n \times n$ tane atama işlemi" diye ifade etti. Ayrıca yer değiştirme yapılsın ya da yapılmasın `if` her adımda çalışmak zorundadır; bu yüzden algoritma çok verimli değildir. Tek artısı yerinde çalışmasıdır: yalnız bir tamsayı değişkenlik (bir dizi gözü kadar) ekstra yer gerekir.

> **Ders sonrası not:** Hoca kabaca $n \times n$ dedi. Tersten sıralı dizide her karşılaştırma bir swap'a yol açar; karşılaştırma ve swap sayısı tam olarak $(n-1) + (n-2) + \dots + 1 = n(n-1)/2$'dir. $n = 5$ için bu 10'dur. Mertebe yine $n^2$'dir.

### 7.2 İyileştirilebilir mi?

**Soru (öğrenci önerisi):** Dış `for` yerine `do-while` yazılabilir. Bir değişken (örneğin `k = 0`) tutulur; karşılaştırmada sırası yanlış bir çift bulunursa `k = 1` yapılır; `while` koşulu "`k` 1 ise tekrarla" olur. Böylece ilk geçişte dizi zaten sıralıysa bir daha sıralama yapılmaz.

**Cevap:** Hoca, bunun sıralı gelen girdide işe yaradığını kabul etti, ama en kötü durumda (tersten sıralı dizi) her geçişte yine fazladan bir kontrol yapılmak zorunda kalınacağını belirtti. Ardından asıl soruyu sordu: baktığımız toplam eleman sayısı ya da yer değiştirme sayısı azaltılabilir mi? Bu soru sonraki yöntemlere geçişi sağladı.

## 8. Karşılaştırma sayarak ekstra diziyle sıralama

Hoca, Selection Sort'a geçmeden önce boş alanı kullanarak başka bir fikri gösterdi (ekrandan, 00:55:00). Bellek ucuz olsun ve dizinin aynı boyutta boş bir kopyası oluşturulabilsin.

Dizi (gözler 1-6): `A = 8 6 9 1 3 7`. Boş ikinci dizi: `B`.

Her eleman için "kaç sayıdan büyüğüm?" diye bakılır; bu sayı + 1, elemanın B'deki gözüdür:

| eleman | kendinden küçük olanlar | sayı | B'deki göz |
|---|---|---|---|
| 8 | 6, 1, 3, 7 | 4 | 5 |
| 6 | 1, 3 | 2 | 3 |
| 9 | 8, 6, 1, 3, 7 | 5 | 6 |
| 1 | yok | 0 | 1 |
| 3 | 1 | 1 | 2 |
| 7 | 6, 1, 3 | 3 | 4 |

Sonuç: `B = 1 3 6 7 8 9`. 8 dört elemandan büyük olduğu için ilk dört göze yazılamaz; kendisi de bir yer kaplayacağı için beşinci göze yazılır. İndislerin 0'dan ya da 1'den başlaması önemli değildir.

Hoca bu yöntemi "sort with counting, linear sort with counting" diye adlandırdı. Kazancı: dizi üzerinde hiç swap (`tmp = A1; A1 = A2; A2 = tmp` gibi) yapılmaz. Bellekteki swap'lar çok pahalıysa bu yaklaşım Bubble Sort'tan çok daha iyi çalışır. Ama bellek alanı harcanamıyorsa, yani sıralama yerinde yapılmak zorundaysa, bu basit ve etkili çözüm kullanılamaz; Bubble Sort gibi yerinde bir yöntem gerekir.

> **Ders sonrası not:** Bu yöntemde her eleman diğer bütün elemanlarla karşılaştırıldığı için karşılaştırma sayısı büyük olasılıkla $n^2$ mertebesindedir; "linear" nitelemesi karşılaştırma sayısı için geçerli değildir. Ayrıca dizide eşit değerler varsa iki eleman aynı göze yazılmak istenir; bunun için eşitliklerde ek bir kural (örneğin önceki eşitleri de saymak) gerekir.

> **Ek bilgi (derste anlatılmadı):** Literatürde bu fikir "karşılaştırma sayarak sıralama" (comparison counting sort) olarak geçer. "Counting sort" adıyla bilinen yöntem ise farklıdır: değerlerin küçük bir aralıkta olduğu varsayılır ve her değerin kaç kez geçtiği sayılır; o zaman çalışma süresi doğrusal olabilir.

> **Hocanın vurgusu:** Tek bir doğru yok. Duruma, probleme ve girdiye göre uygun algoritmik çözüm geliştirilmelidir.

## 9. Selection Sort: algoritma ve akış diyagramı

Hoca iki fikri birleştirmeyi önerdi: her adımda minimum eleman bulunsun ve adımın sonunda tek bir yer değiştirme yapılsın. Böylece Bubble Sort'taki sürekli "yer değiştir, yer değiştir" durumundan kurtulunur. Bu yöntemin adı seçmeli sıralama, özgün adıyla Selection Sort'tur.

Slayttaki tanım (ekrandan, 01:00:00):

- Her iterasyonda en küçük (ya da en büyük) eleman seçilir, baştan başlayarak yerleştirilir.
- Kalan elemanların en küçüğü (ya da büyüğü) seçilir, takip eden sıraya yerleştirilir.

Aslında bulunan şey elemanın kendisi değil, indisidir. Bulunan indisteki eleman ile ilk (sonraki adımlarda ikinci, üçüncü...) gözdeki eleman yer değiştirir. Sonra kalan $n-1$ eleman üzerinde aynı iş yapılır, sonra $n-2$... Her adımda boyut bir azalır; son eleman tek kaldığında zaten sıralıdır.

Slayttaki sözde kod (ekrandan, 01:00:00):

```text
for i <- 0 to n-1 do
   min <- i
   for j <- (i + 1) to n do
      if A[j] < A[min]
         min <- j
   tmp <- A[i]
   A[i] <- A[min]
   A[min] <- tmp
```

Akış diyagramı tahtaya çizildi (ekrandan, 01:00:00). Akış diyagramlarında hep 1'den başlandığı için döngü sınırları 1 tabanlıdır:

```text
[i = 1 .. N-1 döngüsü]
   |
[mi = i]                      (kalan dizinin ilk elemanı minimumdur varsayımı)
   |
[j = i+1 .. N döngüsü]
   |
<a[j] < a[mi] ?> --T--> [mi = j]
   |F                      |
   +-----------------------+
   | (iç döngü bitince)
[swap: a[i] ile a[mi]]
   |
(dış döngüye dön; bitince yazdır ve dur)
```

`mi` minimum indis anlamındadır. Dış döngü `n-1`'den küçük olana kadar (yani 0 tabanlıda `n-2`'ye kadar) gider; iç döngü ise son elemana kadar tarar (`i+1`'den `n-1`'e).

### 9.1 Karşılaştırma ve swap sayısı

Yer değiştirme işlemi hızlı dönen iç döngünün dışına taşınmıştır; her dış iterasyonda yalnız bir swap yapılır. Ekstra $n$ elemanlık bellek gerekmez, yalnız bir `tmp` değişkeni yeterlidir.

Karşılaştırmalar için hoca bir matris çizdi: önce dizinin tamamı, sonra bir eksiği, sonra bir eksiği... tek elemana kadar. Bu, matrisin tamamı değil, köşegeninin bir tarafındaki üçgenidir. Toplam karşılaştırma sayısı yine $n^2$ mertebesindedir, ama `i+1` sayesinde başında $1/2$ çarpanı vardır: yaklaşık $n^2/2$. Yer değiştirme sayısı ise yalnız dış döngü kadardır, yani girdi boyutuyla doğrusal orantılıdır ($n-1$).

> **Hocanın vurgusu:** Selection Sort'un Bubble Sort üzerindeki en büyük artısı swap işlemlerini azaltmasıdır. Swap'ın maliyetli olduğu ama belleğin de dikkatli kullanılması gereken durumlarda iki önceki yaklaşım arasında bir denge sağlar.

## 10. Selection Sort: on elemanlı örnek

Girdi (ekrandan, 01:05:00):

| indis | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|---|
| A | 8 | 6 | 2 | 5 | 9 | 3 | 1 | 4 | 0 | 7 |

`i` 0'dan 8'e kadar gider.

- `i = 0`: min indis 0 (değer 8). 6 daha küçük → min 1 (6). 2 daha küçük → min 2 (2). 5, 9, 3 güncellemez. 1 daha küçük → min 6 (1). 4 güncellemez. 0 daha küçük → min 8 (0). 7 güncellemez. 0. ve 8. gözler yer değiştirir: `0 6 2 5 9 3 1 4 8 7`.
- `i = 1`: min indis 1 (6). 2 daha küçük → min 2. 5, 9, 3 güncellemez. 1 daha küçük → min 6. 4, 8, 7 güncellemez. 1. ve 6. gözler yer değiştirir: `0 1 2 5 9 3 6 4 8 7`.
- `i = 2`: min indis 2 (2). Kalanların hiçbiri daha küçük değil; 2 kendisiyle yer değiştirir. Dizi değişmez.
- `i = 3`: min indis 3 (5). 9 güncellemez; 3 daha küçük → min 5. 6, 4, 8, 7 üçten büyük. 3. ve 5. gözler yer değiştirir: `0 1 2 3 9 5 6 4 8 7`.
- `i = 4`: min indis 4 (9). 5 daha küçük → min 5. 6 güncellemez; 4 daha küçük → min 7. 8, 7 güncellemez. 4. ve 7. gözler yer değiştirir: `0 1 2 3 4 5 6 9 8 7`.
- `i = 5`: min indis 5 (5). 6, 9, 8, 7 daha büyük; değişiklik yok.
- `i = 6`: min indis 6 (6). 9, 8, 7 daha büyük; değişiklik yok.
- `i = 7`: min indis 7 (9). 8 daha küçük → min 8. 7 daha küçük → min 9. 7. ve 9. gözler yer değiştirir: `0 1 2 3 4 5 6 7 8 9`.
- `i = 8`: min indis 8 (8). 9 daha büyük; değişiklik yok.

Burada durulur, çünkü `n-1`'e kadar gidilir: geriye yalnız 9 kalmıştır; tek kalan eleman kendi içinde sıralıdır, ondan büyük bir elemanın bulunma olasılığı yoktur. Toplam $n-1 = 9$ yer değiştirme (bazıları elemanın kendisiyle) yapılmıştır. Ara sonuçlar python ile doğrulandı.

## 11. Selection Sort: C kodu ve eşit elemanlar

Kod yine OnlineGDB'de, Bubble Sort kodu değiştirilerek yazıldı (ekrandan, 01:15:00). Minimum indis için `mi` değişkeni eklendi; dış döngünün başında `mi = i` atandı. İç döngü `i+1`'den başlayıp `n-1`'e kadar (`j < n`) gider.

```c
/*******************
 * Selection sort  *
 *                 *
 * *****************/

#include <stdio.h>
#define n 5

int main()
{
    int a[n]={9, 1, 5, 2, 8};
    int i,j, mi, tmp;

    for(i=0; i<n-1; i++){
        mi = i;
        for(j=i+1; j<n; j++){
            if(a[j] < a[mi])
                mi = j;
        }
        //swap
        tmp = a[mi];
        a[mi] = a[i];
        a[i] = tmp;
    }

    for (i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}
```

Karede swap'ın son satırı (`a[i] = tmp;`) henüz yazılmamıştı; satır anlatıma ("eşittir tmp diyerek yer değişikliğini gerçekleştirdik") göre tamamlandı (ara adım eklendi). Derste `9, 1, 5, 2, 8` dizisinin `1 2 5 8 9` olarak yazdırıldığı söylendi. Kod `gcc -Wall` ile uyarısız derlendi ve çalıştırıldı; çıktı `1 2 5 8 9`'dur.

Selection Sort'un en kötü durumu da tersten sıralı dizidir. Bu durumda yaklaşık $n^2/2$ kez minimum indis güncellemesi yapılır, ama dizi üzerinde yalnız $n-1$ adım kadar yer değiştirme yapılır.

### 11.1 Eşit elemanlar

**Soru:** Aynı sayıdan iki tane olursa ne olur?

**Cevap:** Hiçbir şey değişmez. Koşul `a[j] < a[mi]` (küçük) olduğu için eşit eleman minimum indisi değiştirmez; eşit olan sonraki adımda kalanların içinde yine minimum olarak ele alınır. Hoca diziye ikinci bir 55 ekleyerek bunu gösterdi: önce 11, 22, 55 yerleşir, sonra kalan 55 ile 99 karşılaştırılır. Bütün elemanlar aynı olsa bile `if` içindeki güncelleme hiç çalışmaz ve her eleman kendisiyle yer değiştirir. Hoca bunu her adımda minimum indisi `printf` ile yazdırarak gösterdi: minimum indisler 0, 1, 2, 3 olarak çıktı, yani hep aynı kaldı. <!-- BELİRSİZ: Bu denemedeki dizinin tam değerleri ve printf satırı karelerde görünmüyor; değerler altyazıdan çıkarılamadı. -->

## 12. Konu dışı: Insertion Sort fikri

Hoca bu kısmın ders konusuna dahil olmadığını, ama yine de konuşmak istediğini söyledi. Soru: yine yerinde sıralayıp (ekstra dizi kullanmadan) toplam yer değiştirme işlemleri biraz daha azaltılabilir mi?

Dizi yine `8 6 2 5 9 3 1 4 0 7` (ekrandan, 01:20:00).

1. İlk göz kırmızı çerçeveye alınır: tek elemanlık alt dizi (8) kendi içinde sıralıdır.
2. 6 gelir: 6, 8'den küçüktür, yer değiştirirler. İki elemanlı alt dizi sıralıdır: `6 8`.
3. 2 gelir: 8 bir sağa kayar; 2 ile 6 karşılaştırılır, 2 küçük olduğu için 6 da kayar: `2 6 8`.
4. 5 gelir: 8 ile, sonra 6 ile yer değiştirir; 2 ile karşılaştırılınca durur: `2 5 6 8`.
5. 9 gelir: 8'den büyüktür; hiçbir elemanla işlem gerekmez. Beş eleman bir anda sıralı olur.
6. 3 gelir: kötü durum; 9, 8, 6, 5 kayar, 3 araya girer.
7. 1 gelir: o da kötü; küçük bir eleman olduğu için hepsiyle yer değiştirip başa gelir.
8. 4 gelir: 9, 8, 6 ve 5 ile karşılaştırılıp araya girer; 3'te durur. İlk iki elemana hiç bakılmaz. Durum: `1 2 3 4 5 6 8 9`.
9. 0 gelir: en küçük eleman, en kötü senaryo; herkesle yer değiştirip başa gelir.
10. 7 gelir: 9 ve 8 kayar, 6 ile karşılaştırılınca durur. İlk altı elemana bakılmaz.

Yapılan tek şey bir elemanı alıp kaydıra kaydıra durması gereken indise yerleştirmektir. Rastgele bir girdide eleman genellikle ortalarda bir yerde durur, yani alt dizinin yarısı kadar kaydırma yeter. 1 ve 0 gibi küçük elemanlar çok karşılaştırma ve kaydırma gerektirdi, ama diğerlerinde bütün elemanlara bakmak gerekmedi, bazen hiç bakılmadı.

> **Hocanın vurgusu:** Dizi kendi içinde azıcık sıralıysa ya da sıralı olmaya yakınsa bu kaydırma (araya sokma) yaklaşımı daha mantıklıdır. Yer değiştirme ve kaydırma işlemleri çok azalır, ortalama performans yükselir. Girdinin doğasına göre algoritma seçilebilir.

Bu yöntemin adı Insertion Sort'tur (eklemeli sıralama). Hoca, ileriki yıllarda daha ayrıntılı tartışılacağını söyledi.

> **Ders sonrası not:** Hoca bir noktada toplam "$n-1$ tane yer değiştirme" olacağını söyledi; bu sayı büyük olasılıkla dış adım sayısını (her eleman bir kez araya sokulur) anlatıyor. Kaydırma sayısı girdiye bağlıdır: bu örnekte toplam 29 kaydırma gerekir (python ile hesaplandı, derste söylenmedi).

## 13. Konu dışı: Shell Sort fikri ve hibrit yaklaşım

Hoca bir başka "ekstra" fikir gösterdi (ekrandan, 01:25:00-01:30:00). On elemanlı aynı dizi aralıklı parçalara bölündü: her üçüncü eleman aynı parçaya düşecek biçimde elemanların altı çizildi, üstü çizildi ve içi işaretlendi.

| parça | gözler | elemanlar | kendi içinde sıralı |
|---|---|---|---|
| 1 | 0, 3, 6, 9 | 8, 5, 1, 7 | 1, 5, 7, 8 |
| 2 | 1, 4, 7 | 6, 9, 4 | 4, 6, 9 |
| 3 | 2, 5, 8 | 2, 3, 0 | 0, 2, 3 |

Parçalar küçük olduğu için hızlıca sıralanabilir. Sıralanan değerler kendi gözlerine geri yazılınca dizi şöyle olur:

- İlk dizi: `8 6 2 5 9 3 1 4 0 7`
- Yeni dizi: `1 4 0 5 6 2 7 9 3 8`

Bu tek iterasyonda dizi biraz daha düzenlenmiştir: 1 ve 0 başa yaklaşmış; 9, 8, 7 sağa yaklaşmış; 5 ve 6 ortalarda kalmıştır. Dizi 15 elemanlı olsaydı önce beşli, sonra üçlü, sonra birli aralıklarla benzer işlem yapılırdı.

Şimdi yeni dizi üzerinde Insertion Sort yapılırsa işlem çok azalır:

- 0 gelince: 2 kaydırma (4 ve 1 kayar).
- 5 ve 6: kaydırma yok.
- 2 gelince: 3 kaydırma.
- 7 ve 9: kaydırma yok.
- 3 gelince: 5 kaydırma.
- 8 gelince: 1 kaydırma.

Toplam $2 + 3 + 5 + 1 = 11$ kaydırma ile sıralama tamamlanır. Bu sayı python ile doğrulandı.

> **Ders sonrası not:** Hoca anlatırken diziyi "beşli beşli parçacıklara" böldüğünü söyledi; tahtadaki örnekte ise gözler üçer aralıklı gruplara ayrılmıştır (gözler 0, 3, 6, 9 / 1, 4, 7 / 2, 5, 8).

Hoca burada iki fikri vurguladı:

- Parçalar birbirinden bağımsız olduğu için, bilgisayar imkân veriyorsa farklı işlemcilerde eş zamanlı sıralanabilir.
- Bir noktadan sonra parçalamak fayda getirmez; girdi yeterince düzenlendikten sonra tek bir Insertion Sort ile olabildiğince az swap yapılarak "son darbe" indirilir.

Yani tek bir algoritmayı körü körüne kullanmak zorunda değiliz: girdiyi iyi çalıştığı bilinen bir yönteme kadar bir algoritmayla düzenleyip, sonra kendi içinde sıralıya yakın dizilerde iyi çalışan başka bir yöntemle bitirebiliriz. Bu yöntemin adı Shell Sort'tur.

> **Ek bilgi (derste anlatılmadı):** Shell Sort'ta bu aralıklara "boşluk" (gap) denir. Klasik uygulamada her aralık için parçalar insertion sort ile sıralanır ve son adımda aralık 1 olduğunda algoritma düz bir insertion sort'a dönüşür; önceki adımlar sayesinde bu son adım az kaydırmayla biter.

## 14. Soru-cevap: Gerçek sistemler hangi sıralamayı kullanır?

**Soru:** Windows'ta bir klasördeki dosyalar sıralanmak istendiğinde hemen sıralanıyor. Bu da derste anlatılanlardan birini mi kullanıyor, yoksa çok daha karmaşık bir şey mi?

**Cevap:** Hoca, Windows'un dosyaları isme, boyuta ya da tarihe göre, yani nihayetinde bir büyüklük-küçüklük ilişkisine göre sıraladığını söyledi. Hangi algoritmayı kullandığını bilmediğini söyleyip derste bir arama yaptı, ama kesin bir cevap bulamadı (aramada "natural sort order" gibi sonuçlar çıktı). Hocanın genel cevabı:

- Genellikle herkes kendini ispatlamış temel algoritmaları kullanmayı tercih eder. Girdiye özel, performans kritik bir problem varsa daha karmaşık özel algoritmalar kullanılır.
- Hoca örnek olarak Java'daki `String.indexOf` metodunu verdi: hocaya göre bu metot olabilecek en düz yöntemle, aranan metni teker teker kaydırarak (brute force) arar ve başlangıç indisini döndürür.
- Bir klasörde en fazla binler mertebesinde dosya olur; bu boyutta Bubble Sort bile işi rahatlıkla görür. Milyonlar, milyarlar mertebesinde veride ekran uzun süre bekliyorsa, Selection ya da Bubble Sort tarzı basit bir yöntemin kullanıldığı anlaşılabilir.

> **Hocanın vurgusu:** İçeride hep çok karmaşık algoritmalar çalışıyor diye düşünmeyin. Bazen hızlı uygulanmış basit algoritmalar yeterlidir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): Girdi `8 2 4 4 4 9 3 6` (üç 4 siyah, kırmızı, gri renkte) için slaytta üç çıktı verilmiştir: `2 3 4 4 4 6 8 9` (renkler sırasıyla siyah, kırmızı, gri; ve iki farklı renk sırası). Bunlardan hangileri geçerli bir sıralama çıktısıdır?

> **Çözüm:** Üçü de geçerlidir; hepsi girdinin bir permütasyonudur ve $a_1' \le a_2' \le \dots \le a_n'$ koşulunu sağlar. Yalnız 4'lerin girdideki sırasını (siyah, kırmızı, gri) koruyan çıktı istikrarlı (stable) bir algoritmanın garanti edeceği çıktıdır.

**Soru 2** (ekrandan, 00:30:00): `8 5 2 6 9 3 1 4 0 7` dizisini Bubble Sort ile sıralayın; her dış adımdan sonraki diziyi yazın.

> **Çözüm:** Derste adım adım verildi (Bölüm 5): `i=0`: `5 2 6 8 3 1 4 0 7 9`; `i=1`: `2 5 6 3 1 4 0 7 8 9`; `i=2`: `2 5 3 1 4 0 6 7 8 9`; `i=3`: `2 3 1 4 0 5 6 7 8 9`; `i=4`: `2 1 3 0 4 5 6 7 8 9`; `i=5`: `1 2 0 3 4 5 6 7 8 9`; `i=6`: `1 0 2 3 4 5 6 7 8 9`; `i=7`: `0 1 2 3 4 5 6 7 8 9`; `i=8`: değişiklik yok.

**Soru 3** (derste sözlü, 00:45:28): Bubble Sort için en çok atama işlemine yol açan, yani en kötü durumu yaşatan girdi nasıl bir girdidir?

> **Çözüm:** Derste verildi: tersten sıralı dizi (örnek `88 77 66 55 44`). Her karşılaştırma bir yer değiştirmeye yol açar. $n$ elemanlı dizide karşılaştırma ve swap sayısı $n(n-1)/2$'dir; $n = 5$ için 10.

**Soru 4** (derste sözlü, 00:47:36): Bubble Sort nasıl iyileştirilebilir?

> **Çözüm:** Derste bir öğrenci önerdi: bir geçişte hiç swap olmadıysa dizi sıralıdır, durulabilir (bayrak değişkeniyle `do-while`). Hoca, bunun sıralı girdide işe yaradığını ama tersten sıralı girdide fazladan kontrol getirdiğini söyledi; ardından swap sayısını azaltan Selection Sort'a ve ekstra diziyle sayarak sıralamaya geçti.

**Soru 5** (ekrandan, 00:55:00): `A = 8 6 9 1 3 7` dizisini, her elemanın kaç elemandan büyük olduğunu sayarak ikinci bir `B` dizisine sıralayın.

> **Çözüm:** Derste verildi (Bölüm 8): 8 → 5. göz, 6 → 3. göz, 9 → 6. göz, 1 → 1. göz, 3 → 2. göz, 7 → 4. göz. `B = 1 3 6 7 8 9`.

**Soru 6** (ekrandan, 01:05:00): `8 6 2 5 9 3 1 4 0 7` dizisini Selection Sort ile sıralayın; her adımda minimum indisi ve yer değiştiren gözleri belirtin.

> **Çözüm:** Derste adım adım verildi (Bölüm 10): `i=0` min 8; `i=1` min 6; `i=2` min 2 (kendisi); `i=3` min 5; `i=4` min 7; `i=5` min 5 (kendisi); `i=6` min 6 (kendisi); `i=7` min 9; `i=8` min 8 (kendisi). Sonuç `0 1 2 3 4 5 6 7 8 9`.

**Soru 7** (derste sözlü, 01:15:36): Selection Sort'un en kötü durumu nedir; kaç yer değiştirme yapılır?

> **Çözüm:** Derste verildi: en kötü durum tersten sıralı dizidir; yaklaşık $n^2/2$ kez minimum indis güncellenir, ama dizi üzerinde yalnız $n-1$ yer değiştirme yapılır.

**Soru 8** (ekrandan, 01:30:00): `8 6 2 5 9 3 1 4 0 7` dizisi üçer aralıklı parçalara bölünüp her parça kendi içinde sıralanıyor. Ortaya çıkan dizi nedir ve bu dizi Insertion Sort ile kaç kaydırmada sıralanır?

> **Çözüm:** Derste verildi (Bölüm 13): yeni dizi `1 4 0 5 6 2 7 9 3 8`; Insertion Sort ile toplam 11 kaydırma (0 için 2, 2 için 3, 3 için 5, 8 için 1). Python ile doğrulandı.

## Dersin Toparlaması

Bu derste sıralama problemi formal olarak tanımlandı: çıktı, girdinin küçük eşitlik zincirini sağlayan bir permütasyonudur. Sıralama algoritmalarının çalışma zamanı, karşılaştırma ve swap sayısı, ekstra bellek (yerinde ya da harici) ve istikrar (stable / unstable) ölçütleriyle değerlendirildiği görüldü. En ilkel yöntem olan Bubble Sort, komşu elemanları karşılaştırıp her adımda kalanların en büyüğünü sona taşır; basittir ve yerinde çalışır ama çok karşılaştırma ve swap yapar. Biraz bellekten feragat edilirse, her elemanın kaç elemandan büyük olduğu sayılarak swap yapmadan ikinci bir diziye sıralama yapılabilir. Bu iki fikrin arasında bir denge olan Selection Sort, her iterasyonda minimum indisi bulup tek bir swap yapar: yaklaşık $n^2/2$ karşılaştırma, $n-1$ swap.

Konu dışı olarak, elemanları sıralı alt diziye kaydırarak sokan Insertion Sort'un neredeyse sıralı girdide çok verimli olduğu ve diziyi önce aralıklı parçalarda düzenleyip sonra insertion sort ile bitiren Shell Sort fikri gösterildi. Hoca, çok daha verimli sıralama algoritmalarının da bulunduğunu, ama bunlar için önce algoritma tasarım yaklaşımlarının öğrenilmesi gerektiğini; bilgisayar bilimlerine giriş aşamasında problemi ve bu temel çözüm yöntemlerini anlamanın yeterli olduğunu söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
