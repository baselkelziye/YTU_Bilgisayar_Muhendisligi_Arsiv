# Ders 22 Genişletilmiş Notu: Sepet Analizi ile Ürün İkilileri ve Üçlüleri, Yığın ve Kuyruk, Kelime Birliktelikleri ve Anlamsal Uzay

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulamalı bölüme giriş
- 2. Sepet analizi problemi
- 3. Sepet matrisinden A matrisine
- 4. T matrisi: hangi ürün hangi ürünle kaç kez birlikte satıldı
- 5. Ürün üçlüleri
- 6. Karmaşıklık ve iyileştirmeler
- 7. Geri al / ileri al: yığın ve kuyruk
- 8. Kelime birliktelikleri
- 9. Kelime ikilileri ve ±K komşuluk kodu
- 10. Anlamsal uzay
- Örnek Sorular
- Dersin Toparlaması

## 1. Uygulamalı bölüme giriş

Yapısal programlama açısından temel konular (diziler, matrisler, özyineleme, rastgelelik) bitti. Bundan sonraki dersler, bu yapıların bilgisayar bilimlerindeki farklı problemlere nasıl uygulandığını gösteren uygulamalı derslerdir. Ders notlarında bu amaçla üç bölüm vardır: sepet analizi ve onun dil işlemedeki karşılığı, kriptolojiden örnekler, görüntü işleme örnekleri.

Bu problemlerde hep ya dizi ya matris kullanılır; gerektiğinde özyinelemeye başvurulur ve işlemler fonksiyonlarla yapılır. Yani yeni bir dil özelliği öğrenilmez, bilinen araçlar yeni problemlere uyarlanır.

## 2. Sepet analizi problemi

### 2.1 Veri ve soru

Ders notundaki problem şöyledir (ekrandan, 00:05:00):

- Sepet analizi: en çok birlikte satılan ürün ikilileri nelerdir?
- `S`: sepetID ve ürünID'leri tutan bir matris. `N` satır, 2 sütun.

| sepetID | ÜrünID |
|---|---|
| 1 | 2 |
| 2 | 1 |
| 2 | 789 |
| ... | ... |

Hoca tahtada örneği genişletti (ekrandan, 00:10:00): 1 numaralı sepette 2, 3 ve 18 numaralı ürünler, 2 numaralı sepette 789 ve 1 numaralı ürünler var. Her market sepetinde değişken sayıda ürün olabileceği için matrisin satır sayısı sepet sayısından ya da ürün sayısından bilinemez. Bilinen tek şey, matrisin iki sütunlu olduğudur.

**Soru:** Bir sepette birden fazla ürün varsa aynı satıra virgülle birden çok ürün yazılamaz mı? **Cevap:** Hayır. Bu bir tamsayı matrisidir, bir hücreye tek değer girer. Bu yapılandırılmış bir veridir; sepet ID'sine karşılık birden çok ürün varsa her ürün ayrı satıra yazılır. Sepet ID'si birden çok satırda tekrar ediyorsa o sepette birden çok ürün vardır.

**Soru:** Ürünün kaç adet satıldığı önemli mi? **Cevap:** Hayır. Bu problemde yalnız bir siparişte o ürünün olup olmadığı önemlidir; üç tane mi beş tane mi alındığı önemsizdir.

### 2.2 Gerçek hayattaki kullanımı

Hoca bu problemin nerede kullanıldığını sordu. Bir öğrenci alışveriş sitelerini örnek verdi: bir ürüne bakınca altında "en çok birlikte satılanlar" gösterilir, bazen birlikte alıma indirim yapılır. Hoca bunun tamamen bir öneri sistemi olduğunu söyledi: "bunu alanlar şunu da aldı" denerek kullanıcı ikinci ürünü almaya teşvik edilir.

Toplumun geneline bakınca bir eğilim vardır. Patates alanların soğan da alması bilinen bir şeydir. Ama veride "patates alanların %90'ı bulaşık teli de alıyor" gibi nesneler arasında anlamsal bağı olmayan bir birliktelik de çıkabilir. Bilginin mantıklı olması gerekmez; veride varsa kullanılabilir. Bu tür analize **birliktelik analizi (association analysis)** denir ve veri madenciliğinin konusudur.

Hocanın anlattığı tarihsel örnek: yıllar önce bir bölgedeki marketlerin satışları incelenmiş ve bebek bezi ile bir içecek arasında çok yüksek bir birliktelik bulunmuş. İki ürün arasında görünürde ilgi yoktur; arkasındaki neden sosyal analizlerle açıklanmış ve sonuç satışlarda başarıyla kullanılmış.

Market yalnız süpermarket ya da e-ticaret değildir. Müzik ve video platformlarında "bu videoyu izleyenlerin %90'ı şunu da izledi" diye yapılan tavsiyeler de aynı mantıktadır. Yeterince veri varsa buradan güzel sonuçlar çıkar.

> **Ek bilgi (derste anlatılmadı):** Bebek bezi örneği veri madenciliği literatüründe "beer and diapers" (bira ve bebek bezi) hikâyesi olarak bilinir; doğruluğu büyük olasılıkla tartışmalıdır ve çoğu zaman bir benzetme olarak anlatılır. Birliktelik kurallarını bulan klasik algoritmalar Apriori ve FP-Growth'tur.

### 2.3 Test verisi ve gözle kontrol

Kodu yazmak için küçük bir test verisi kuruldu (ekrandan, 00:15:00 ve 00:20:00). `#define MAX 10` ile en fazla 10 satır ayrıldı ve tablo biçiminde, okunaklı olsun diye her satır ayrı yazıldı. Sepetlerin ve ürünlerin sıralı olması gerekmez.

```c
#include <stdio.h>
#define MAX 10
int main(){
    int sepet[MAX][2]={ {1,2},
                        {2,1},
                        {2,4},
                        {2,2},
                        {1,4},
                        {3,3},
                        {5,1},
                        {5,2},   };
}
```

Hoca önce gözle bakılmasını istedi. Bir öğrenci 2 ve 4 dedi: 1. sepette 2 ve 4 birlikte, 2. sepette de 2 ve 4 birlikte bulunuyor. Öğrenci kontrolü sepet sepet, aynı sepetteki ürünleri karşılaştırarak yaptığını; sepet numaraları sıralı olmadığı için arada atlama yapmak zorunda kaldığını söyledi.

Gözle yapılan bu işin bir algoritmaya dökülmesi gerekiyor. Sonra veride 5 numaralı sepet 4 numaralı sepet yapıldı (ekrandan, 00:30:00: son iki satır `{4,1}, {4,2}`) ve şu değişkenler eklendi:

```c
int N=8;
int urunSayisi = 5;
int sepetSayisi = 5;
```

`N` veri satırı sayısıdır. Ürün kodları 0'dan başlasın denildiği için 4'e kadar kodlanan ürünlerde ürün sayısı 5 alındı; sepet sayısı da aynı şekilde 5 alındı. Sepet ID'si bir sipariş numarasıdır; boş kalan bir sepet numarası (örneğin 0) hiçbir sonucu değiştirmez.

## 3. Sepet matrisinden A matrisine

### 3.1 Neden dönüşüm gerekiyor

Hoca, ilk matristen ürün ikililerini doğrudan bir algoritmayla çıkarmanın pratikte mümkün olmadığını söyledi: "normal bir algoritma bu matrisin içinde kaybolur." Bir öğrencinin önerisi (bir ürünü seçip diğer bütün sepetlerde aramak) tek ürünü saymaya yarar ama hangi ürünün onunla birlikte eklendiği bilgisini kaybettirir.

Bu yüzden veri, hangi ürünün hangi sepette olduğunu gösteren bir biçime çevrilir. Bu yeni matrise `A` denir (ekrandan, 00:35:00):

| A | 1 | 2 | ... | SepetN |
|---|---|---|---|---|
| 1 | 0 | 1 | ... | 0 |
| 2 | 1 | 0 | ... | 1 |
| ... | ... | ... | ... | ... |
| ÜrünN | 1 | 0 | ... | 0 |

Satırlar ürünler (kalem, patates, mendil gibi ürün kategorileri), sütunlar sepetlerdir. Bir hücre 1 ise o ürün o sepette vardır, 0 ise yoktur. Boyutu ürün sayısı × sepet sayısıdır; kodda kolaylık için `MAX × MAX` yer açılıp gerektiği kadarı kullanıldı.

**Soru:** Ürün ID'leri tam tutmazsa, örneğin 789 gibi büyük bir ID olursa ne olur? **Cevap:** Önemli değil; ID 10.000 de olabilir. Bu algoritmanın en basit hâlidir; daha verimli hâlleri başka derslerde anlatılır.

### 3.2 Dönüşüm kodu

`A` önce tamamen sıfırlanır; sonra yalnız ilgili yerler 1 yapılır. `S` satır satır okunur: ilk satır "1 numaralı sepette 2 numaralı ürün var" der, o zaman `A`'nın 2. satırının 1. sütunu 1 yapılır. Eksenler ters düşünülmelidir: ürün `sepet[i][1]`'de, sepet `sepet[i][0]`'dadır (ekrandan, 00:30:00).

```c
int A[MAX][MAX]={{0}};
int i,j;
for(i=0;i<N;i++){
    A[sepet[i][1]][sepet[i][0]] = 1;
}

for(i=0;i<urunSayisi;i++){
    for(j=0;j<sepetSayisi;j++){
        printf("%d ",A[i][j]);
    }
    printf("\n");
}
```

Bu dönüşüm `S`'deki satır sayısı kadar, yani $N$ adımda biter. Hoca bunu "basit, en karmaşıklıklı bir algoritma" olarak özetledi. Derleme sırasında dizinin son elemanından sonra kalan fazladan virgül ve iç döngüdeki eksik başlangıç değeri (`j=0`) öğrencilerin uyarısıyla düzeltildi.

Çıktıya göre hoca, birinci ürünün 2. ve 4. sepette; ikinci ürünün 1., 2. ve 4. sepette; üçüncü ürünün 3. sepette; dördüncü ürünün 1. ve 2. sepette bulunduğunu okudu.

### 3.3 A matrisi neden yetmez

Bir öğrenci, satırında en çok 1 olan iki ürünü almayı önerdi. Hoca bunun yetmediğini açıkladı: birinci ürün 8 sepette, ikinci ürün de 8 sepette bulunmuş olabilir; ama bu, ikisinin aynı sepetlerde olduğunu garanti etmez. Birlikte satılmak için aynı sepette olmaları gerekir. Her sepette hangi ürünlerin birlikte olduğunun ayrıca sayılması gerekir. Bu da yeni bir matris gerektirir.

## 4. T matrisi: hangi ürün hangi ürünle kaç kez birlikte satıldı

### 4.1 T matrisinin tanımı

`T` matrisi ürün × ürün boyutundadır. `T[i][j]`, `i` ürünü ile `j` ürününün aynı sepette kaç kez bulunduğunu gösterir (ekrandan, 01:05:00):

| T | 1 | 2 | ... | ÜrünN |
|---|---|---|---|---|
| 1 | 0 | 12 | ... | 0 |
| 2 | 23 | 0 | ... | 179 |
| ... | ... | ... | ... | ... |
| ÜrünN | 13 | 0 | ... | 0 |

Bir ürünün kendisiyle birlikteliği anlamsızdır, bu yüzden köşegen 0 kalır. Hoca slayttaki tabloda bir tutarsızlık olduğunu da belirtti: 1 ile 2'nin 12, 2 ile 1'in 23 olması mümkün değildir, çünkü birliktelik karşılıklıdır; `T` simetrik olmalıdır.

### 4.2 Döngüler

`A` matrisi gezilerek `T` doldurulur. 0. ürün 1, 2, 3, 4 ile karşılaştırıldıktan sonra 1. ürünün tekrar 0. ürünle karşılaştırılmasına gerek yoktur. Bu yüzden iç döngü `j = i+1`'den başlar: 0. ürün 1-2-3-4 ile, 1. ürün 2-3-4 ile, 2. ürün 3-4 ile karşılaştırılır. Matrisin yalnız üst üçgeni gezilir.

Ürünlerin hangi sepetlerde birlikte olduğuna bakmak için üçüncü bir döngü (`k`, sepetler) gerekir. `i`. ürün `k`. sepette var ve aynı zamanda `j`. ürün de `k`. sepette varsa, bu iki ürün bir kez birlikte satılmıştır ve `T[i][j]` bir artırılır.

```c
for(i=0;i<urunSayisi;i++){
    for(j=i+1;j<urunSayisi;j++){
        for(k=0;k<sepetSayisi;k++){
            if((A[i][k]==1) && A[j][k]==1){
                T[i][j] += 1;
            }
        }
    }
}
```

Çıktıya göre birinci ürün ikinci ürünle iki kez, ikinci ürün dördüncü ürünle iki kez, birinci ürün dördüncü ürünle bir kez birlikte satılmıştır. Matris üçgenseldir; üçüncü ürün yalnız bir sepette tek başına bulunduğu için hiçbir ürünle birlikteliği yoktur.

### 4.3 Veri değişikliği ve en büyük değer

`T`'nin en büyük değerinin bulunduğu satır ve sütun indisleri, en çok birlikte satılan ikiliyi verir. Test verisinde iki eşit en büyük değer olduğu için hoca veriyi değiştirdi; üçüncü sepete 2 numaralı ürün kondu. Son veri ve çıktı (ekrandan, 00:45:00) şöyledir:

```text
A matrisi (satır: ürün 0-4, sütun: sepet 0-4)
0 0 0 0 0
0 0 1 0 1
0 1 1 1 1
0 0 0 0 0
0 1 1 0 0

T matrisi
0 0 0 0 0
0 0 2 0 1
0 0 0 0 2
0 0 0 0 0
0 0 0 0 0
```

<!-- BELİRSİZ: Veri dizisinin 3. sepete ait satırı karede doğrudan görünmüyor; `{3,2}` değeri ekrandaki A ve T çıktısından geriye doğru çıkarıldı. Hoca bu sırada veriyi birkaç kez değiştirdi. -->

Burada `T[1][2] = 2` ve `T[2][4] = 2` eşittir. `T`'nin en büyük elemanını ve indislerini bulmak bir matriste en büyüğü bulma sorusudur; hoca bu kısmı öğrencilere bıraktı.

Ham `S` matrisi gerçekte milyonlarca satır olabilir. Ama yalnız $N$ kez gezilerek `A`'ya, sonra ürün sayısının karesi × sepet sayısı kadar adımla `T`'ye çevrilir; en sonunda `T`'nin en büyük değerine bakılır.

### 4.4 if'ten kurtulmak: çarpma

Hoca `if`'ten kurtulmanın bir yolunu sordu. Bir öğrencinin `while` önerisine hoca, `while`'ın bir döngü olduğunu ve `if`'in yerine geçmediğini söyledi. Başka bir öğrenci `A[i][k]` ile `A[j][k]`'nın çarpımını toplamayı önerdi.

`A` yalnız 0 ve 1 içerdiği için iki değerin çarpımı ancak ikisi de 1 iken 1 olur; bu bir anlamda kesişimdir. Çarpım 0 ise ya biri, ya öteki, ya ikisi birden 0'dır. Böylece koşul yerine doğrudan çarpım eklenir (ekrandan, 00:50:00):

```c
for(i=0;i<urunSayisi;i++){
    for(j=i+1;j<urunSayisi;j++){
        for(k=0;k<sepetSayisi;k++){
            /*if((A[i][k]==1) && A[j][k]==1){
                T[i][j] += 1; */
            T[i][j] += A[i][k]*A[j][k];
        }
    }
}
```

Hocanın sayımına göre `if`'li sürümde üç karşılaştırma ve bir artırma, yani dört işlem vardır; çarpımlı sürümde bir çarpma ve bir toplama, yani iki işlem vardır. Yorum satırı yapılırken unutulan bir kapanış süslü parantezi bir öğrencinin uyarısıyla düzeltildi; program aynı sonucu verdi.

Tam program (karelerden kuruldu; en büyüğü bulan son kısım derste yazılmadı, ajan ekledi; `gcc -Wall` ile derlenip çalıştırıldı ve yukarıdaki çıktıyı verdi):

```c
#include <stdio.h>
#define MAX 10
int main(){
    int sepet[MAX][2]={ {1,2},{2,1},{2,4},{2,2},{1,4},{3,2},{4,1},{4,2} };
    int N=8;
    int urunSayisi = 5;
    int sepetSayisi = 5;
    int A[MAX][MAX]={{0}};
    int T[MAX][MAX]={{0}};
    int i,j,k;
    for(i=0;i<N;i++){
        A[sepet[i][1]][sepet[i][0]] = 1;
    }
    for(i=0;i<urunSayisi;i++){
        for(j=0;j<sepetSayisi;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<urunSayisi;i++){
        for(j=i+1;j<urunSayisi;j++){
            for(k=0;k<sepetSayisi;k++){
                T[i][j] += A[i][k]*A[j][k];
            }
        }
    }
    printf("\n");
    for(i=0;i<urunSayisi;i++){
        for(j=0;j<urunSayisi;j++){
            printf("%d ",T[i][j]);
        }
        printf("\n");
    }
    /* derste verilmedi: T'nin en büyüğü */
    int max=0, yi=0, yj=0;
    for(i=0;i<urunSayisi;i++)
        for(j=i+1;j<urunSayisi;j++)
            if(T[i][j]>max){ max=T[i][j]; yi=i; yj=j; }
    printf("En cok birlikte satilan ikili: %d-%d (%d kez)\n", yi, yj, max);
    return 0;
}
```

Bu veriyle program `1-2 (2 kez)` yazar; `>` kullanıldığı için eşitlikte ilk bulunan ikili korunur.

> **Ders sonrası not:** Ekrandaki programlar `main`'in sonunda `return 0;` olmadan çalıştırıldı ve konsolda dönüş değeri olarak 5 ve 10 gibi anlamsız sayılar göründü (ekrandan, 00:45:00 ve 02:15:00). Kullanılan derleyicinin varsayılan C standardında bu değer büyük olasılıkla belirsizdir; `return 0;` yazmak doğru olandır.

## 5. Ürün üçlüleri

### 5.1 Fikir

Teneffüsten önce hoca soruyu ilerletti: en çok birlikte satılan ürün üçlüleri istenirse ne yapılır? Teneffüs sonrası bir öğrenci, son matrisin iki boyuttan üç boyuta çıkarılabileceğini söyledi. Hoca bunu onayladı: `i`. ürün, ondan farklı `j`. ürün ve bir de `k`. ürün olacaktır.

Kombinasyonlar ağaç gibi düşünülür: 1 ile 2, 1 ile 3, 1 ile 4; 1-2 ile birlikte 1-2-3 ve 1-2-4; sonra 2 ile 3 ve 4. `S` ve `A` matrisleri değişmez, çünkü bir ürünün bir sepette olup olmadığı bilgisi aynıdır. Yalnız `T` üç boyutlu olur ve sepetleri gezmek için dördüncü bir döngü değişkeni (`m`) gerekir.

### 5.2 Kod

Kod yeni bir dosyaya kopyalandı. Döngüler `j = i+1` ve `k = j+1`'den başlar; böylece 1-2-3, 1-2-4, 1-3-4 gibi her üçlüye bir kez bakılır.

```c
for(i=0;i<urunSayisi;i++){
    for(j=i+1;j<urunSayisi;j++){
        for(k=j+1;k<urunSayisi;k++){
            for(m=0;m<sepetSayisi;m++){
                T[i][j][k] += A[i][m]*A[j][m]*A[k][m];
            }
        }
    }
}
```

Önce yine `if` ile yazıldı: `m`. sepette `i`., `j`. ve `k`. ürünlerin üçü de varsa `T[i][j][k]` bir artırılır. Sonra aynı şey üç değerin çarpımıyla kısaltıldı (ekrandan, 01:30:00, yorum satırı olarak).

Üç boyutlu matris ekrana doğrudan yazdırılamaz. Üst üste küp gibi yığılmış matrisler düşünülür: `i` ve `j` sabitken `k` değişir, her matris bitince araya boş satır ve bir çizgi konur (ekrandan, 01:10:00). Derleme sırasında `T` hâlâ iki boyutlu tanımlıyken üç indisle kullanıldığı için `invalid operands to binary +` hatası alındı; `T` üç boyutlu tanımlanınca düzeldi.

Hoca çıktıyı okurken önce yanlış matrise baktığını fark etti ve karışmasın diye çıktının başına "T matrisi" başlığı ekledi. İlk veride üçlü satış olmadığı için veri değiştirildi (ekrandan, 01:20:00):

```c
int sepet[MAX][2]={ {1,2},
                    {2,2},
                    {2,4},
                    {2,3},
                    {1,3},
                    {1,4},
                    {4,1},
                    {4,2}   };
```

Burada 1. sepet {2, 3, 4}, 2. sepet {2, 4, 3}, 4. sepet {1, 2} içerir; 2, 3 ve 4 iki sepette birlikte bulunur.

### 5.3 En büyük üçlüyü bulmak

Üst üste yazdırılan matrisleri gözle yorumlamak yerine `T`'nin en büyük değeri ve onun indisleri saklandı (ekrandan, 01:15:00):

```c
max = 0;
int yi, yj, yk;
...
if(T[i][j][k]>max){
    max = T[i][j][k];
    yi = i;
    yj = j;
    yk = k;
}
...
printf("En cok satilan uclu: %d-%d-%d", yi, yj, yk);
```

C kuralları gereği değişkenler kullanılmadan önce (yukarıda) tanımlanmalıdır. Program `2-3-4` üçlüsünü buldu. Hoca, kodun farklı ve daha çok verilerle denenmesini önerdi.

## 6. Karmaşıklık ve iyileştirmeler

### 6.1 Zaman karmaşıklığı

Hoca projelerde de algoritmanın karmaşıklığına bakılacağını hatırlattı ve adım adım hesapladı. Ürün sayısı ve sepet sayısı birbirine yakın kabul edilip hepsine $n$ denirse:

- `S`'den `A`'ya dönüşüm: $N$ satır, yani $O(n)$.
- `A`'nın yazdırılması: iki iç içe döngü, $O(n^2)$.
- Üçlülerin sayımı: dört iç içe döngü (ürün, ürün, ürün, sepet). Bir öğrenci doğru cevabı verdi: $O(n^4)$.

Döngüler `i+1` ve `j+1`'den başladığı için tam sayım $n^4$'ten biraz azdır (hocanın deyişiyle "$n^4$ eksi bir şeyler"). Ama en yüksek dereceli terim alındığı için algoritmanın mertebesi $O(n^4)$'tür.

İkililer için kod açılmadan sorulan soruya cevap $O(n^3)$'tür: ürün × ürün × sepet. Daha doğru yazılırsa (ürün sayısı)$^2$ × (sepet sayısı)'dır.

Ürün altılıları istenseydi $O(n^7)$ zamanlı bir algoritma çıkardı. Zamanın yanında bellek karmaşıklığı da büyür: üçlüler için `T` $n^3$ yer tutar, altılılar için altı boyutlu bir matris gerekir.

> **Ek bilgi (derste anlatılmadı):** Döngüler `j=i+1`, `k=j+1`'den başladığında incelenen üçlü sayısı $\binom{n}{3}=\frac{n(n-1)(n-2)}{6}$'dır. Sabit çarpan $1/6$ olsa da büyüme yine $n^3$ mertebesindedir; sepet döngüsüyle birlikte $O(n^4)$ kalır.

### 6.2 Bellek iyileştirmesi

Bir öğrenci `T`'den kurtulabileceğimizi söyledi. Hoca önce sayım yapılmadan bunun nasıl olacağını sordu. Öğrencinin açıklaması: `T[i][j][k]` yerine bir sayaç değişkeni (`c`) konur; sepet döngüsü bitince bu sayaç hemen en büyük değerle karşılaştırılır. En büyük bulma kısmı en içteki sepet döngüsünün dışına, `k` döngüsünün içine alınır. Dizide yalnız aranan kritere uyan elemanı bulmaya çalışıldığı için bütün değerleri saklamaya gerek yoktur.

Hoca bunun güzel bir iyileştirme olduğunu söyledi: $n^3$'lük bellek kazanılır, zaman karmaşıklığı yine $O(n^4)$ kalır. Ekrandaki kod (ekrandan, 01:25:00 ve 01:30:00):

```c
for(i=0;i<urunSayisi;i++){ // N^4
    for(j=i+1;j<urunSayisi;j++){
        for(k=j+1;k<urunSayisi;k++){
            for(m=0;m<sepetSayisi;m++)
            if((A[i][m]==1) && A[j][m]==1 && A[k][m]==1){
                //T[i][j][k] += 1;
                c +=1;
            }
            if(c>max){
                max = c;
                yi = i;
                yj = j;
                yk = k;
            }
            //T[i][j][k]+= A[i][m]*A[j][m]*A[k][m];
        }
    }
}
```

> **Ders sonrası not:** Karede `c`'nin her `(i, j, k)` üçlüsü için sıfırlandığı bir satır görünmüyor (ekrandan, 01:25:00). `c` her üçlü için `0`'dan başlamazsa önceki üçlülerin sayısı birikir ve yanlış üçlü seçilebilir. Ders verisinde birlikteliği olan son üçlü zaten `2-3-4` olduğu için çıktı doğru göründü (sıfırlamasız sürüm derlenip denendi, o da `2-3-4` verdi). Doğrusu `k` döngüsünün içinde, sepet döngüsünden önce `c = 0;` yazmaktır.

Ajanın düzelttiği tam sürüm (`gcc -Wall` ile derlendi, `En cok satilan uclu: 2-3-4` yazdı):

```c
#include <stdio.h>
#define MAX 10
int main(){
    int sepet[MAX][2]={ {1,2},{2,2},{2,4},{2,3},{1,3},{1,4},{4,1},{4,2} };
    int N=8;
    int urunSayisi = 5;
    int sepetSayisi = 5;
    int A[MAX][MAX]={{0}};
    int i,j,k,m,c;
    int max=0, yi=0, yj=0, yk=0;
    for(i=0;i<N;i++){
        A[sepet[i][1]][sepet[i][0]] = 1;
    }
    for(i=0;i<urunSayisi;i++){ // N^4
        for(j=i+1;j<urunSayisi;j++){
            for(k=j+1;k<urunSayisi;k++){
                c = 0;
                for(m=0;m<sepetSayisi;m++){
                    if((A[i][m]==1) && A[j][m]==1 && A[k][m]==1){
                        c += 1;
                    }
                }
                if(c>max){
                    max = c;
                    yi = i; yj = j; yk = k;
                }
            }
        }
    }
    printf("En cok satilan uclu: %d-%d-%d\n", yi, yj, yk);
    return 0;
}
```

### 6.3 Zaman iyileştirmesi fikri

Hoca bir zamansal iyileştirme olarak şu fikri karalama hâlinde yazdı (test etmediğini belirtti): sepet döngüsü en dışa alınır ve her sepet için önce `A[i][m]`'ye bakılır. Bu 1 değilse, yani `i`. ürün o sepette yoksa, `j`. ve `k`. ürünlere hiç bakılmaz. `A[i][m]` 1 ise `A[j][m]`'ye, o da 1 ise `A[k][m]`'ye bakılır. Üçü de 1 ise sayaç artırılır. Böylece iç içe `if`'lerle gereksiz karşılaştırmaların önüne geçilir; geri kalanı öğrencilere bırakıldı. Hoca sonra bu taslağı geri alıp `c`'li çözüme döndü.

## 7. Geri al / ileri al: yığın ve kuyruk

### 7.1 Hangi veri yapısı

Hoca kodu geri alıp ileri alırken bir soru sordu: bir programdaki geri al / ileri al mekanizması hangi veri yapısıyla çalışır? Bir öğrenci yığın (stack) dedi; web tarayıcılarındaki ileri-geri tuşları da böyledir. Masanın üstüne üst üste kitap koymak gibidir: alttan kitap almak yasaktır.

Bu, özyinelemede anlatılan yığın belleğiyle aynı mantıktır: programın nerede kaldığı yığında saklanır ve sonra oraya dönülür. Geri al denince program bir önceki duruma döner. Word'deki ve tarayıcılardaki ileri al / geri al bu şekilde çalışır.

**Soru:** Programın çalıştığı yığın ile kodda tasarladığımız yığın veri yapısı aynı şey mi? **Cevap:** Düşünce ve yapı olarak aynıdır; ikisinin de iki temel işlemi vardır.

### 7.2 Yığın, kuyruk, dizi ve bağlı liste

Hoca veri yapılarını iki gruba ayırdı (ekrandan, 01:35:00):

- Dizi ve bağlı liste veriyi saklamak için kullanılır. Dizide veri istenen yere konur. Bağlı liste ileride anlatılacak.
- Yığın ve kuyruk veriye erişmek için kullanılır; hem saklar hem erişim kuralı koyar.

Yığında iki temel işlem vardır: tepeye ekleme ve tepeden çıkarma. Araya istenen yere ekleme yapılamaz. Bir değişken (yığın işaretçisi, stack pointer) nereye eklenip nereden silineceğini gösterir: ekleme yapılınca bir artar, silme yapılınca bir azalır. İşlemcinin içinde de stack pointer adlı bir yazmaç vardır ve Assembly programlamada çok kullanılır.

Kuyruk gerçek hayattaki kuyruk gibidir: önden çıkılır, arkadan eklenir. Önce gelen önce hizmet alır, sonra gelen sırasını bekler.

> **Ek bilgi (derste anlatılmadı):** Bu iki ilkeye kısaca LIFO (Last In, First Out, son giren ilk çıkar; yığın) ve FIFO (First In, First Out, ilk giren ilk çıkar; kuyruk) denir.

### 7.3 İki yığınla geri al / ileri al

**Soru:** Geri alma mekanizması daha çok kuyruğa benzemez mi? **Cevap:** Hayır. Kuyruktan çıkan bir daha geri gelmez; bankadaki sıradan çıkınca iş biter. Geri al / ileri al için birden fazla yığın tutulur.

Hoca tahtada anlattı (ekrandan, 01:35:00): A, B, C, D yazıldı; bunlar sırayla birinci yığına eklendi. Geri al yapılınca D birinci yığından çıkarılıp ikinci yığına konur. İleri al yapılırsa D ikinci yığından alınıp birinciye geri konur. Geri aldıktan sonra yeni bir harf (E) yazılırsa, birçok uygulamada artık D'ye ileri alarak dönülemeyebilir. Hoca bunu bir metin kutusunda Ctrl-Z ile denedi; uygulamanın karakterleri tek tek değil gruplar hâlinde geri aldığını gösterdi. Durum geçişlerini saklama mantığı her uygulamada farklıdır, ama kullanılan yapı yığındır; bir yerine birden fazla yığın da kullanılabilir.

**Soru:** Yığınla sonsuza kadar geri gidilebilir mi? **Cevap:** Bellek sonsuz değildir ama kapasitesi büyüktür. Yığın sabit uzunluklu bir diziyle tutulursa (örneğin 5 eleman) en fazla 5 adım geri gidilebilir. Bağlı listeyle tutulursa yalnız bellek miktarıyla sınırlı, sınırsız gibi bir yığın kurulabilir.

**Soru:** 5 geri alma hakkı olan uygulamalarda en alttaki eleman nasıl silinir? **Cevap:** Aslında silinmez, orada durur. Çıkarma yapılınca yığın işaretçisi aşağı iner; yeni bir şey eklenince o konumdaki eski değerin üzerine yazılır.

Kuyruk ve yığının teorisi ayrı bir çalışma alanıdır; farklı uygulamaları vardır. Ama bilinen yaygın uygulamalarda ileri al / geri al böyle çalışır.

## 8. Kelime birliktelikleri

### 8.1 Problemi dile uyarlamak

Sepet analizindeki fikir şimdi dile uygulanır. Elimizde kullanıcıdan alınan kısa bir cümle değil, çok büyük bir metin vardır: milyonlarca web sayfasından ya da dijitalleştirilmiş kitaplardan elde edilen metinler. Her kelimeye bir ID verilir. Sonuçta metin tek boyutlu bir sayı dizisi olur (ekrandan, 01:40:00 ve 01:50:00):

```text
Metin = [ 8  3  10000000  ...  0 ]
8: Gel
3: Kedi
10000000: enjektör
```

Çok kullanılan kelimelere küçük, az kullanılanlara büyük ID verilebilir (az kullanılan kelime örneği olarak sohbetten "enjektör" seçildi). Bir dildeki bütün kelimeler böyle kodlanır; hocanın dil hocalarından duyduğu rakamlara göre Türkçede yaklaşık 100.000, İngilizcede 1 milyona yakın kelime vardır.

Soru: bu metinde **arka arkaya en çok geçen kelime ikilileri** hangileridir? Dizide her eleman bir sonrakiyle eşleştirilir ve her ikilinin kaç kez geçtiği sayılır.

### 8.2 Ne işe yarar

Bir öğrenci metnin ana fikrini bulmayı önerdi; hoca en çok geçen ikililerin "ve ben" gibi her yerde geçen kalıplar olabileceğini, bu yüzden bunun kısmen doğru olduğunu söyledi. Başka öğrenciler dildeki konuşma kalıplarını, atasözlerini, tamlamaları, otomatik düzeltmeyi ve doğal dil işlemede cümle tamamlamayı önerdi. Hoca doğal dil işlemeye doğru gelindiğini söyledi ve dilsel düşünmeyi istedi.

Bir cümlede yan yana gelen kelimeler arasında anlam ilişkisi olmalıdır. Bir şey nasıl artar? Hızlı, kayda değer biçimde ya da yavaş artar. İngilizcede "dramatically increased", "slightly increased" denir; "mavi arttı" denmez. Bir şeyin sayısı ya da fiyatı artar; rengi artmaz.

### 8.3 Academic Word List ve collocation listeleri

Hoca bu fikri kullanan iki çalışmadan söz etti:

- **Academic Word List:** Akademik metinlerden oluşan bir külliyat (corpus) taranmış. Bu metinlerde yüksek olasılıkla geçen 500-600 civarında kök kelime çıkmış. Hocanın aktardığına göre bu kökler ve türevleri (örneğin "analiz", "analiz edilmiş", "analiz edici") bilinirse İngilizce akademik metinlerin %90'ı anlaşılabilir. Her kökün yaklaşık 10 türevi düşünülürse 400 kök 4000-5000 kelimelik bir hazne eder.
- **Academic Collocation List:** Birlikte kullanımların (collocation) listesi; ikili, üçlü kelime grupları. Örneğin "abstract" en çok "concept" ile birlikte geçer. "Akademik başarı", "akademik kariyer", "akademik hayat" sık geçer; "akademik muz", "akademik mavi", "akademik yemek" geçmez (sıfattan sonra anlamlı bir isim gelir).

Bu kaynaklar dil sınavlarına hazırlanırken de yararlıdır. Oxford'un en sık geçen kelimeleri listeleyen 500 ve 1500 kelimelik listeleri de benzer çalışmalardır.

## 9. Kelime ikilileri ve ±K komşuluk kodu

### 9.1 Ders notundaki algoritma

Ders notunda algoritma MATLAB benzeri bir sözde kodla verilmiştir (ekrandan, 02:00:00). `N` metin boyutu, `M` `N` elemanlı sayı dizisidir:

```text
W'yu sıfırla
for i=1:N-1
    W(M(i),M(i+1))=W(M(i),M(i+1))+1;
end
```

Her bir kelimenin $(-K, +K)$ etrafında en çok hangi kelimelerin olduğu:

```text
W'yu sıfırla
for i=1+K:N-K
    for j=-K:K
        W(M(i),M(i+j))=W(M(i),M(i+j))+1;
    end
    // j=0 daki artımı azaltmak için
    W(M(i),M(i))=W(M(i),M(i))-1;
end
```

Ders notunda bu bölümün sonunda şu cümle vardır: "Birlikte geçen kelimeler anlamsal olarak birbirine yakındır. Bu fikir kullanılarak Word2vec, FastText, Glove gibi araçlar üretilmiş. Kelimeler anlamsal uzayda koordinatlarla temsil ediliyor." (ekrandan, 02:00:00)

### 9.2 Komşu ikililer: W matrisi

Doğrudan dizi üzerinde "1 ile 2 kaç kez geçti, 2 ile 3 kaç kez geçti" diye bakılamaz; sayımları tutmak için bir matris gerekir. `W[a][b]`, `a` kelimesinden hemen sonra `b` kelimesinin kaç kez geldiğidir. Dizi gezilirken `M[i]` ve `M[i+1]` alınır ve o hücre bir artırılır.

Test için küçük bir dizi kullanıldı. Hoca böyle bir cümlenin pek olmayacağını (aynı şeyi tekrar tekrar söylemek gibi), ama bunun çok uzun bir metnin parçası olarak düşünülmesi gerektiğini söyledi. İlk yazımda indisler yanlış yazıldı (`W[M[i][i+1]]++`, ekrandan, 01:55:00); bir öğrencinin uyarısıyla `W[M[i]][M[i+1]]++` olarak düzeltildi.

Diziye sonradan bir eleman eklendi ve döngü sınırı düzeltildi. Son kod (ekrandan, 02:10:00 ve 02:15:00):

```c
#include<stdio.h>
#define MAX 10
int main(){
    int M[MAX]={2,4,3,5,2,4,5,2,4,3};
    int W[MAX][MAX]={{0}};
    int WK[MAX][MAX]={{0}};
    int i,j;
    int K = 3;

    for(i=0;i<MAX-1;i++){
        W[M[i]][M[i+1]]++;
    }
    for(i=0;i<MAX;i++){
        printf("%d:",i);
        for(j=0;j<MAX;j++){
            printf("%d , ",W[i][j]);
        }
        printf("\n");
    }
    /* K önceki ve sonraki komsuluk */
    for(i=K;i<MAX-K;i++){
        for(j=-K;j<K;j++){
            WK[M[i]][M[i+j]]++;
        }
        WK[M[i]][M[i]]--;
    }
    printf("\n\n");
    for(i=0;i<MAX;i++){
        printf("%d:",i);
        for(j=0;j<MAX;j++){
            printf("%d , ",WK[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

<!-- BELİRSİZ: Dizinin onuncu elemanı (3) ve WK döngüsünden sonraki azaltma satırı karede görünmüyor; ekrandaki çıktıyla tutarlı olacak biçimde kuruldu. -->

Bu kod `gcc -Wall` ile derlenip çalıştırıldı ve ekrandaki iki matrisle aynı çıktıyı verdi. `W` matrisinin sıfır olmayan değerleri şunlardır: `W[2][4]=3`, `W[4][3]=2`, `W[3][5]=1`, `W[4][5]=1`, `W[5][2]=2`. Hoca çıktıyı "2 numaralı kelimeden sonra 4 numaralı kelime üç kez geçiyor" diye okudu. Bu matrisin en büyük değeri bulunarak her kelimenin en sık hangi kelimeyle birlikte geçtiği söylenebilir.

> **Ders sonrası not:** Döngü önce `for(i=0;i<MAX;i++)` diye yazıldı. Son adımda `i = MAX-1` iken `M[i+1]`, yani `M[10]` okunur; bu, 10 elemanlı dizinin sınırı dışıdır ve C'de **tanımsız davranıştır**. Derste kod ilk başta hatasız çalışır gibi göründü, ikinci bir matris (`WK`) eklenince program beklenen çıktıyı vermedi. Hoca bunu işletim sisteminin izinsiz bellek erişimini engellemesiyle açıkladı. Tanımsız davranışta sonuç önceden bilinemez: program çökebilir, başka bir değişkenin değerini bozabilir ya da hatasız görünebilir. Bir öğrencinin uyarısıyla doğru sınır `i < MAX-1` yapıldı.

**Soru:** `W` içinde `M[i]` ile `i+1` arasına virgül konması gerekmiyor mu? **Cevap:** C'de iki boyutlu dizi erişimi `W[a][b]` biçimindedir, köşeli parantezler arasında virgül olmaz; virgüllü yazım başka dillerdendir.

### 9.3 ±K komşuluk: WK matrisi

Yalnız bir önceki ve bir sonraki kelimeye bakmak yerine, bulunulan kelimenin $K$ önceki ve $K$ sonraki kelimeleriyle birlikteliği sayılırsa anlamsal olarak daha derin bir bilgi elde edilir. "Bir şey increased" dendiğinde yalnız bir önceki değil, birkaç önceki kelimeye bakmak gerekir. İngilizce sınavlarındaki boşluk doldurma soruları da bunu ister: boşluğa gelen kelime, öncesi ve sonrasıyla anlamlı olmalıdır.

Kodun mantığı:

- `i` dış döngüsü `K`'dan başlar. 0'dan başlarsa `i-K` negatif olur, örneğin -3. eleman diye bir şey yoktur.
- `i`, `MAX-K`'dan önce durur. Sonda da `K` eleman ileri bakabilmek için yer kalmalıdır.
- İç döngü `j`, `-K`'dan `K`'ya gider; `M[i]` ile `M[i+j]` ikilisi sayılır. `j`, eksi `K`'dan başladığı için `i+j` hem geriye hem ileriye gider.
- `j = 0` iken kelime kendisiyle eşleşir; bu fazladan sayım iç döngüden sonra bir azaltılarak geri alınır.

Hoca $K=3$ için bir kelime üzerinde anlattı: o kelime 3 önceki, 2 önceki, 1 önceki kelimeyle, kendisiyle (sonra silinir), sonra 1, 2, 3 sonraki kelimelerle eşleştirilir ve her eşleşme bir artırılır. Bütün `i`'ler için bu yapılır. Toplam iç döngü $2K+1$ adımdır.

Gözle sayımda hoca, 5 ile 4'ün bu dizide ±3 komşulukta 4 kez birlikte geçtiğini buldu. Program çıktısı (ekrandan, 02:15:00) `WK` için şu satırları verdi:

```text
2:0 , 0 , 0 , 1 , 2 , 2 , 0 , 0 , 0 , 0 ,
4:0 , 0 , 2 , 1 , 0 , 2 , 0 , 0 , 0 , 0 ,
5:0 , 0 , 4 , 1 , 4 , 1 , 0 , 0 , 0 , 0 ,
```

En sık birlikte geçenler 5 ile 2 ve 5 ile 4'tür (4'er kez). `WK[5][5] = 1` değeri, 5'in kendi penceresinde başka bir konumda tekrar geçmesinden gelir; `j = 0` düzeltmesi yalnız kelimenin kendi konumunu siler.

> **Ders sonrası not:** Derste iç döngü `for(j=-K;j<K;j++)` diye yazıldı (ekrandan, 02:05:00). Bu döngü `j = -3, -2, -1, 0, 1, 2` değerlerini alır; yani $K$ önceki ama yalnız $K-1$ sonraki kelimeye bakar ve anlatılan $2K+1$ adım yerine $2K$ adım yapar. Ders notundaki `for j=-K:K` iki yönde de $K$ kelimeye bakar. Simetrik sayım için C'de `j <= K` yazılmalıdır. Ekrandaki `WK` çıktısı `j < K` ile üretilmiştir (python ile iki sürüm karşılaştırıldı; `j <= K` ile örneğin `WK[2][2]=1`, `WK[5][3]=2` olur).

### 9.4 Karmaşıklık

Bir metin için komşu ikili sayımı metin uzunluğu kadar, $K$ komşuluk ise yaklaşık $n \cdot K$ adımdır. Gerçek uygulamada tek bir metin değil, belki bir milyon kitap vardır; her kitabın kelimeleri sayı dizisine çevrilir ve bu diziler bir matrisin satırları gibi düşünülür. Hocanın ifadesine göre o zaman iki döngü $n^2$, $K$ komşulukla $n^2 \cdot K$ karmaşıklık ortaya çıkar.

## 10. Anlamsal uzay

### 10.1 Bana arkadaşını söyle

Hoca bir benzetme yaptı: bütün sınıf bahçede bir toplantıya çağrılsa ve oturacak yer olmasa, herkes en yakın arkadaşlarının yanına gider ve kümelenir. Uzaktan bakan biri grupları görür ve bunların arkadaş olduğunu anlar. "Bana arkadaşını söyle, sana kim olduğunu söyleyeyim" atasözü gibi, bir kelimenin hangi kelimelerle birlikte kullanıldığı onun anlamını ele verir. Bu, doğal dil işleme ve metin madenciliğinde kullanılır; hesaplamalı anlambilimin konusudur.

### 10.2 W matrisini arama motoruyla kurmak

Ders notundaki örnek veri kümesinde berber, bakkal, kuaför, hastane gibi yer kelimeleri; hayvan kelimeleri ve eşya kelimeleri gibi gruplar, her grupta 10 kelime vardır. Balina ile aslan ya da akbaba ile arı anlamca yakındır; akbaba ile avize ya da lamba arasında ilgi yoktur.

`W` matrisini kurmanın daha basit bir yolu arama motorudur: iki kelime birlikte aratılır ve dönen sonuç sayısı birlikte kullanım sıklığı olarak alınır. Bu, arama motorunun programlama arayüzüyle (API) bir döngü içinde bütün kelime ikilileri için yapılabilir. Derste "puan durumu" aratıldı ve yaklaşık 85 milyon sonuç çıktı. Anlamsız ikililer de denendi; sıklık azaldıkça anlam ilişkisinin düştüğü söylendi. Hoca arama sonuçlarının her zaman tam eşleşme olmadığını, bu yüzden sayıların bazen beklenmedik çıkabileceğini de gösterdi.

### 10.3 İki boyutlu gösterim

Bir sürü metinden ya da arama sonuçlarından elde edilen `W` matrisi bir yöntemle iki boyutlu düzleme çizdirilir. Ders kaynağındaki grafikte ("2D MDS Solutions") anlamca yakın kelimeler kümelenmiştir (ekrandan, 02:25:00):

- Eşyalar: kapı, koltuk, buzdolabı, lamba, avize, sandalye, televizyon, bilgisayar (merdiven de yakınında).
- Hayvanlar: aslan, akrep, arı, ayı, baykuş, balina, akbaba.
- Giysiler: etek, gözlük, şapka, süveter, ayakkabı, gömlek, bere, bikini, mayo.

Koordinatların kendisinin önemi yoktur; toplantı örneğinde olduğu gibi grubun bahçenin neresinde oturduğu değil, kimlerin bir arada olduğu önemlidir. Kelimelere verilen ID'lerin de anlamı yoktur: 1. kelime ile 15. kelime arasındaki 14 farkı bir şey ifade etmez. Önemli olan birlikte kullanımdır.

Grafikte kümeleri bozan durumlar da vardır. Araç bağlamında ambulans ve otomobil birlikte görünür; hastane, park, okul hizmet sektörü kelimeleri olarak bir arada durur. Bazı hayvan kelimelerinin yanına "sedan" gibi bir araç kelimesi düşmüştür.

> **Ek bilgi (derste anlatılmadı):** MDS (Multidimensional Scaling, çok boyutlu ölçekleme), nesneler arasındaki benzerlik ya da uzaklık matrisinden, bu uzaklıkları olabildiğince koruyan düşük boyutlu (burada iki boyutlu) koordinatlar üreten bir yöntemdir.

### 10.4 Uygulamalar ve yapısal benzerlik

Bu birliktelik bilgisi örneğin eski kitaplarda optik karakter tanımanın (OCR) hatalarını düzeltmekte kullanılır. Türkçe karakterler İngilizce karakterlere çevrilirken "ı" ile "i" karışabilir (ASCII'ye çevirme sorunu) ve "kirli toprak" yerine "kıllı toprak" gibi bir ifade ortaya çıkabilir. Hangisinin doğru olduğu, birlikte kullanım sıklıklarına bakılarak düzeltilebilir. Derste arama motorunda iki ifade karşılaştırıldı; motor tam eşleşme yapmadığı için sayılar beklenenden farklı çıktı, ama normal bir metin külliyatında "kirli toprak" daha sık çıkmalıdır.

Hoca bu işlemi bir ön işlemin ön işlemi gibi gördüğünü söyledi. Daha ileri seviyede bu analizleri yapan araçlar vardır (ders notunda Word2vec, FastText, Glove); bunlarla bir kelimenin eş anlamlıları ya da birlikte kullanımları bulunabilir. Bazıları yapay zeka tekniklerinden yararlanır.

Yapısal benzerlik her zaman işe yaramaz. "Galatasaray" ile "salatalık" harf bakımından benzer (a, l, t, s harfleri), belki %60-70 benzer; ama anlam ilişkisi yoktur. "Cimbom" ile "Galatasaray" arasında yapısal benzerlik yoktur, ama anlamsal benzerlik vardır. Bu anlamsal benzerlik birlikte kullanım sıklıklarından, yani kurduğumuz basit $n \times K$'lık sayım matrislerinden elde edilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00): `S` matrisi sepetID ve ürünID'leri tutan `N` satır, 2 sütunlu bir matristir. En çok birlikte satılan ürün ikilileri nelerdir?

> **Çözüm (derste verildi):** `S`'den ürün × sepet boyutlu 0/1 `A` matrisi kurulur (`A[sepet[i][1]][sepet[i][0]] = 1`). Sonra ürün × ürün `T` matrisi `T[i][j] += A[i][k]*A[j][k]` ile (`j = i+1`'den başlayarak) doldurulur. `T`'nin en büyük elemanının indisleri en çok birlikte satılan ikiliyi verir. Karmaşıklık $O(n^3)$.

**Soru 2** (ekrandan, 00:20:00): Verilen test verisinde (`{1,2},{2,1},{2,4},{2,2},{1,4},{3,3},{5,1},{5,2}`) gözle bakınca en çok birlikte satılan ikili hangisidir?

> **Çözüm (derste verildi):** Derste bir öğrenci 2 ve 4 dedi: ikisi hem 1. sepette hem 2. sepette birlikte bulunur (2 kez).
>
> **Ders sonrası not:** Sepetler 1: {2, 4}, 2: {1, 4, 2}, 3: {3}, 5: {1, 2} olduğu için 1 ile 2 de iki sepette (2. ve 5.) birlikte bulunur ve 2 kez geçer; 1 ile 4 ise yalnız 2. sepette, 1 kez geçer (ara adım eklendi, python ile sayıldı). Yani bu veride en büyük değer için 2-4 ile 1-2 eşittir.

**Soru 3** (derste sözlü, 00:47:45): `if((A[i][k]==1) && A[j][k]==1) T[i][j] += 1;` ifadesinden `if` kullanmadan nasıl kurtulunur?

> **Çözüm (derste verildi):** `A` yalnız 0/1 içerdiği için `T[i][j] += A[i][k]*A[j][k];` yazılır. Çarpım ancak ikisi de 1 iken 1'dir. `while` bir döngü olduğu için çözüm değildir.

**Soru 4** (derste sözlü, 00:50:42): En çok birlikte satılan ürün üçlüleri istenirse algoritma nasıl değişir?

> **Çözüm (derste verildi):** `T` üç boyutlu olur. Döngüler `i`, `j = i+1`, `k = j+1` ve sepetler için `m`'dir. `T[i][j][k] += A[i][m]*A[j][m]*A[k][m];` En büyük elemanın `(i, j, k)` indisleri sonucu verir. Ders verisinde sonuç `2-3-4`'tür.

**Soru 5** (derste sözlü, 01:17:25 ve 01:18:33): Üçlü algoritmasının ve ikili algoritmasının zaman karmaşıklığı nedir?

> **Çözüm (derste verildi):** Ürün ve sepet sayısı $n$ alınırsa üçlüler dört iç içe döngüyle $O(n^4)$, ikililer üç iç içe döngüyle $O(n^3)$'tür. Daha doğru yazımla ikililer (ürün sayısı)$^2$ × (sepet sayısı)'dır.

**Soru 6** (derste sözlü, 01:19:14 ve 01:24:39): Üçlü algoritması bellek ve zaman açısından nasıl iyileştirilebilir?

> **Çözüm (derste verildi):** Bellek: `T` dizisi tutulmaz; her üçlü için bir sayaç `c` hesaplanıp hemen en büyükle karşılaştırılır ($n^3$ bellek kazanılır, zaman yine $O(n^4)$). Zaman: `A[i][m]` 1 değilse `j` ve `k`'ye bakılmaz; iç içe `if`'lerle gereksiz karşılaştırmalar atlanır.

**Soru 7** (derste sözlü, 01:29:01): Programlardaki geri al / ileri al mekanizması hangi veri yapısıyla gerçekleştirilir?

> **Çözüm (derste verildi):** Yığınla (stack). Geri alınan adımlar ikinci bir yığına konur, ileri al o yığından geri alır. Yığın dizide tutulursa geri alma sayısı sınırlıdır; bağlı listeyle tutulursa yalnız bellekle sınırlıdır.

**Soru 8** (ekrandan, 01:50:00): Kelimeleri sayılarla kodlanmış bir metinde arka arkaya en çok geçen kelime ikilileri nasıl bulunur? Bu ne işe yarar?

> **Çözüm (derste verildi):** `for(i=0;i<N-1;i++) W[M[i]][M[i+1]]++;` ile sayılır, `W`'nin en büyük elemanı aranır. Birlikte kullanımlar (collocation) bulunur; anlamca uyumlu kelime ilişkileri, dil öğrenme listeleri ve anlamsal uzay bu sayımlara dayanır.

**Soru 9** (ekrandan, 02:00:00 ve derste sözlü, 02:01:28): Her bir kelimenin $(-K, +K)$ etrafında en çok hangi kelimelerin olduğu nasıl bulunur?

> **Çözüm (derste verildi):** `i`, `K`'dan `N-K`'ya kadar gider; iç döngü `j`, `-K`'dan `K`'ya gider ve `WK[M[i]][M[i+j]]++` yapılır; `j = 0`'daki kendisiyle eşleşme `WK[M[i]][M[i]]--` ile geri alınır. Simetrik pencere için C'de iç döngü koşulu `j <= K` olmalıdır (bkz. 9.3'teki ders sonrası not).

**Soru 10** (derste sözlü, 02:17:29): `W` matrisini bütün metinleri tek tek taramadan daha basit nasıl oluşturabilirsiniz?

> **Çözüm (derste verildi):** Arama motorunda kelime ikilileri birlikte aratılır ve dönen sonuç sayısı birlikte kullanım sıklığı olarak `W`'ye yazılır. Bu, arama motorunun API'siyle bir döngüde yapılabilir.

## Dersin Toparlaması

Bu derste yapısal programlamanın temel araçları gerçek bir veri madenciliği problemine uygulandı. Sepet analizinde ham veri (sepet, ürün) önce ürün-sepet varlık matrisine (`A`), sonra ürün-ürün birliktelik matrisine (`T`) çevrildi; en çok birlikte satılan ikili `T`'nin en büyük elemanıyla bulundu. `if` yerine 0/1 çarpımı, simetri sayesinde yalnız üst üçgeni gezmek ve gereksiz büyük dizileri tutmamak gibi iyileştirmeler gösterildi. Üçlülere geçince zaman $O(n^3)$'ten $O(n^4)$'e, bellek de $n^3$'e çıktı; grup büyüdükçe bu yöntemin hızla pahalılaştığı görüldü. Ara bir soru olarak geri al / ileri al mekanizmasının iki yığınla çalıştığı, yığın ve kuyruğun veriye erişim yapıları olduğu anlatıldı.

Aynı birliktelik fikri dile uygulandığında kelime ikilileri ve $\pm K$ komşuluk matrisleri elde edildi. Birlikte geçen kelimelerin anlamca yakın olduğu fikri, kelimelerin iki boyutlu bir anlamsal uzayda kümelenmesini, OCR düzeltmesini ve Word2vec, Glove gibi araçları açıklar. Ders notundaki sonraki uygulamalar kriptoloji ve görüntü işleme örnekleridir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
