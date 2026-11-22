# Ders 19 Genişletilmiş Notu: Sıralı İki Dizinin Birleştirilmesi: Akış Diyagramı, C Kodu ve Hata Ayıklama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Problem: Sıralı İki Diziyi Birleştirmek
- 2. Elle Bir Örnek
- 3. Akış Diyagramı: Birleştirme Döngüsü
- 4. Döngü Şartı: AND mi, OR mu? Küçük mü, Küçük Eşit mi?
- 5. Döngüden Sonra: Hangi Dizi Bitti?
- 6. Kalan Elemanların Kopyalanması
- 7. Akışta "Tanımlama" Yoktur
- 8. Akıştan C Koduna
- 9. Test ve Hata Ayıklama
- 10. Koşullu Derleme ile Hata Ayıklama Çıktıları
- 11. Makrolarla Dizi Boyutu
- Örnek Sorular
- Dersin Toparlaması

## 1. Problem: Sıralı İki Diziyi Birleştirmek

Bu derste, önceki derste öğrencilere çözmeleri için verilen problem birlikte yeniden değerlendirildi. Problem şudur: elimizde iki dizi var ve ikisi de küçükten büyüğe sıralıdır. Bu iki dizi, yine küçükten büyüğe sıralı olacak şekilde yeni bir dizide birleştirilecek.

Bunun için önce iki dizi dışarıdan okunur. Hoca bunları `N` elemanlı bir `A` dizisi ve `M` elemanlı bir `B` dizisi olarak adlandırdı. Sonuç dizisi `C`'dir. Birleştirme bittiğinde `C` dizisinde `N + M` eleman olur.

## 2. Elle Bir Örnek

Akışı çizmeden önce hoca küçük iki dizi üzerinde ne yapılmak istendiğini gösterdi (ekrandan, 00:10:00):

- `A = 3, 5, 7`
- `B = 2, 8, 11`

`A` dizisinde kullanılan indis `I`, `B` dizisinde kullanılan indis `J`, `C` dizisinde kullanılan indis `K` olsun. Üçü de 1 ile başlar.

İlk adımda iki dizinin o anki elemanları karşılaştırılır: 3 ile 2. 2 daha küçük olduğu için `C`'nin ilk elemanına 2 yazılır. Atama yapıldığı için `C`'nin bir sonraki elemanına geçilir (`K` bir artar). 2, `B`'den alındığı için `J` bir artar; `I` ise `A`'nın aynı yerinde kalır. Sonra 3 ile 8 karşılaştırılır, 3 alınır; ardından 5 ile 8'den 5, sonra 7 ile 8'den 7 alınır.

Bu noktada `A`'nın bütün elemanları bitmiştir. Artık karşılaştırma yapmaya gerek yoktur, çünkü `A`'da gidilecek bir yer kalmamıştır. `B`'nin kalan elemanları, yani 8 ve 11, olduğu gibi `C`'nin sonuna yerleştirilir.

Hoca örneği daha sonra temiz bir sayfada indis değerleriyle bir kez daha izledi (ekrandan, 00:30:00). Adım adım (ara değerler python ile doğrulandı):

| Adım | Karşılaştırma | Seçilen | `I` | `J` | `K` (adım sonunda) |
|---|---|---|---|---|---|
| Başlangıç | | | 1 | 1 | 1 |
| 1 | 3 ile 2 | 2 (`B`'den) | 1 | 2 | 2 |
| 2 | 3 ile 8 | 3 (`A`'dan) | 2 | 2 | 3 |
| 3 | 5 ile 8 | 5 (`A`'dan) | 3 | 2 | 4 |
| 4 | 7 ile 8 | 7 (`A`'dan) | 4 | 2 | 5 |

`I = 4` olduğunda `A`'nın böyle bir elemanı yoktur, `A` bitmiştir. `B`'nin `J = 2`'den `M = 3`'e kadar olan elemanları (8 ve 11) `C(5)` ve `C(6)`'ya kopyalanır. Sonuç: `C = 2, 3, 5, 7, 8, 11`.

## 3. Akış Diyagramı: Birleştirme Döngüsü

Akış, derste anlatılan gösterimle çizildi (ekrandan, 00:15:00 ve 00:20:00):

```text
START
  |
[Giriş]  N, A(N), M, B(M)
  |
[İşlem]  I = 1
         J = 1
         K = 1
  |
<Döngü şartı>  I <= N AND J <= M  --(şart sağlanmazsa)--> bağlantı noktası 1
  | (şart sağlandıkça)
<A(I) < B(J)>
   T: C(K) = A(I)        F: C(K) = B(J)
      I = I + 1             J = J + 1
  (iki kol birleşir)
[İşlem]  K = K + 1
  |
  +--> döngü şartına geri döner
```

İlk değer kutusundan sonra yapılacak şey bir döngü kurmaktır. Bu döngünün içinde iki dizinin elemanları karşılaştırılır: `A(I)`, `B(J)`'den küçük müdür? Gerçekten küçükse `C(K)`'ya `A(I)` atanır ve `I` bir artırılır. Değilse `B(J)` daha küçüktür; `C(K)`'ya `B(J)` atanır ve bir sonraki elemana geçmek için `J` bir artırılır.

`if` kapandıktan sonra, döngü bitmeden yapılması gereken bir şey daha vardır: `K`'yı bir artırmak. Bu artırma hem doğru hem yanlış kolunda yapılması gereken bir iştir, çünkü döngünün her turunda `C`'nin bir elemanına mutlaka atama yapılır. Her iki kolda da yapıldığına göre iki kez ayrı ayrı yazmak yerine kollar birleştikten sonra bir kez yazmak daha mantıklıdır.

## 4. Döngü Şartı: AND mi, OR mu? Küçük mü, Küçük Eşit mi?

Akış ilk çizildiğinde döngü şartı `I < N AND J < M` olarak yazılmıştı (ekrandan, 00:15:00). Bir öğrenci sohbetten `AND` yerine `OR` olması gerekip gerekmediğini sordu.

**Soru:** Döngü şartında `AND` yerine `OR` olmayacak mı?

**Cevap:** Olmayacak. Dizilerden birinin sınırının dışına çıkıldığında, yani `N` ya da `M` aşıldığında durmak gerekir. O noktada devam etmenin anlamı yoktur, çünkü dizilerden biri bitmiştir. Örnekte 7 atandığında `I` 1, 2, 3'ten sonra 4 olur; `A`'nın 4. elemanı yoktur. Öbür dizinin de taşmasını beklemeye gerek yoktur; herhangi biri taştığında durulmalıdır.

Hoca asıl dikkat edilmesi gereken hatanın başka olduğunu söyledi: şartta eşitlik eksikti. Son elemanın da karşılaştırılması gerekir; bu yüzden şart `I <= N AND J <= M` olarak düzeltildi (ekrandan, 00:20:00). Eşitlik şartının dışına çıkıldığı anda döngüden çıkılmalıdır.

Öğrenci tam ikna olmadığını söyleyince hoca konuyu yeniden açtı. `I <= N` şartı konur, çünkü `I`'nın her zaman `N`'yi aşmamasını isteriz. `I`, `N + 1` olduğunda ne olur? Örnekte `I = 4` olduğunda dizide öyle bir eleman yoktur; bellekte bize ayrılmamış bir yere gidilir, yani dizi sınırının dışına çıkılır (out of bound). `I`, `A`'nın elemanlarına erişmek için kullanılır. Aynı şey `J` için de geçerlidir: `J`, `B`'nin elemanlarına erişmek için kullanılır ve `M`'yi aşmamalıdır.

**Soru (hocadan):** `J`, `M`'den büyük olursa ne olur?

**Cevap:** İlk verilen "döngüden çıkar" cevabını hoca kabul etmedi; döngüden çıkma şartı zaten yazılmaya çalışılan şeydir. Asıl soru `J`'nin neden `M`'den büyük olmasını istemediğimizdir. Doğru cevap: dizi sınırlarının dışına çıkılacağı için.

Bu iki şart aynı anda sağlanmalıdır. "Bir dizinin dışına taşalım, öbürünün taşmayalım" diye bir durum olmaz; ikisinin de içinde kalmak isteriz. İkisinin birden içinde kalmak istediğimiz için şartları `AND` ile bağlarız (ekrandan, 00:25:00).

> **Hocanın vurgusu:** "Anladım" demek tek başına bir şey ifade etmez. Bir konuda şüphe varsa, net bir şekilde değerlendirilip özümsenene kadar üzerinde durulmalıdır. Bir öğrencinin aklına takılan şey büyük olasılıkla başka öğrencilerin de aklına takılmıştır.

## 5. Döngüden Sonra: Hangi Dizi Bitti?

Şartlar birlikte sağlandığı sürece döngü devam eder. Döngüden çıkıldığında dizilerden biri bitmiştir, ama hangisinin bittiği bilinmez.

**Soru (hocadan):** Döngüden çıktığında ne olmuş olur, hangisinin sonuna geldiğini nasıl anlarsın?

**Cevap:** İki diziden biri bitmiştir. Hangisi olduğunu anlamak için basit bir kontrol yapılır. Örneğin `J > M` diye bakılabilir: doğruysa `B` bitmiştir ve `A`'nın kalan elemanları kopyalanır. Alternatif olarak `I > N` diye bakılabilir: doğruysa `A` bitmiştir ve `B`'nin kalanı kopyalanır; `I` hâlâ `N`'den büyük değilse `B` bitmiştir ve `A`'nın kalanı kopyalanır (ekrandan, 00:25:00).

Akış kalabalıklaşmasın diye döngü şartının çıkışına `1` numaralı bir bağlantı noktası konuldu ve akışa yeni sayfada devam edildi (ekrandan, 00:35:00 ve 00:40:00). Yeni sayfada `I > N` sorulur:

- T (doğru): `A` dizisi bitmiştir, **B dizisi kopyalanacak**.
- F (yanlış): `I` hâlâ `N`'den büyük değildir, `A`'nın elemanları kalmıştır, **A dizisi kopyalanacak**.

## 6. Kalan Elemanların Kopyalanması

**Soru (hocadan):** Kalan elemanları nasıl kopyalayacağız?

Bir öğrenci önce `while` ile yapılabileceğini söyledi. Hoca `while`'ın ne zaman kullanıldığını sordu; cevap "adım sayısını bilmediğimiz zaman" oldu. Sonra adım sayısını bilip bilmediğimizi sordu. Öğrenci düşününce fark etti: `J`'nin değeri bellidir; döngü `J`'den `B`'nin son elemanına, yani `M`'ye kadar gider. Adım sayısı bilindiği için `for` döngüsü kullanılır.

Derste anlatılan gösterimde `for` döngüsü, içinde döngü değişkeni, ilk değer, artış miktarı ve son değer yazan bir kutuyla gösterilir. Hoca önce `B`'nin kalanını kopyalayan döngüyü bir yardımcı değişkenle düşündü: döngü değişkeni `X`, `J`'den başlar, 1'er artar, `M`'ye kadar gider; her turda `B(X)`, `C(K)`'ya atanır ve `K = K + 1` yapılır, böylece `C`'ye kaldığı yerden yazılmaya devam edilir.

Sonra şunu gösterdi: `I > N` ise `A` bitmiştir ve `I` değişkeniyle yapılacak bir iş kalmamıştır, `I` boşa çıkmıştır. Bu yüzden `B`'nin kalanını kopyalayan döngünün değişkeni olarak `I` kullanılabilir. Simetrik olarak `A`'nın kalanını kopyalarken `B` bitmiştir ve `J` boştadır (ekrandan, 00:35:00):

```text
<I > N>
  T (B dizisi kopyalanacak):         F (A dizisi kopyalanacak):
    döngü  I <- J, 1, M                döngü  J <- I, 1, N
      C(K) = B(I)                        C(K) = A(J)
      K = K + 1                          K = K + 1
  (iki kol birleşir)
döngü  I <- 1, 1, N + M
  C(I) yazdırılır
END
```

<!-- BELİRSİZ: son çıktı döngüsünün kutusu karede boş görünüyor; altyazıda yalnız "I 1'den 1'er artarak N + M'e kadar giderek" denip "bitireceğiz" deniyor. Döngünün C(I)'yı yazdırdığı, sonra yazılan C kodundan çıkarıldı. -->

Burada `J`, döngü değişkeni olarak kullanılırken ilk değeri `I`'dır, son değeri `N`'dir. `A`'da kalınan yer `I`'dır; son değerlendirilecek eleman oradan başlar. `A`'nın `N` elemanı olduğu için döngü `N`'de biter.

## 7. Akışta "Tanımlama" Yoktur

Bir öğrenci, akışın sonunda `K`'nın nerede "tanımlandığını" sordu; bir başkası `I` ve `J`'nin başta "tanımlandığını", son sayfadaki döngüde ise farklı bir `I` ve `J` kullanılıyor gibi göründüğünü söyledi.

**Soru:** Sağdaki `I` döngü için, soldaki `I` ise dizinin kaçıncı elemanında kalındığını gösteren `I` değil mi? Bunlar farklı mı?

**Cevap:** Hoca ekrandaki iki `I`'yı gösterip hangisinin hangisinden neye göre farklı olduğunu sordu; ikisi de aynı `I` değişkenidir. Akışta hiçbir yerde bir şey tanımlanmaz. Giriş kutusunda dışarıdan okunacak değişkenlerin hangileri olduğu söylenir. İşlem kutusunda, ilk değer ataması gerekiyorsa kullanılacak değişkenlere ilk değerleri verilir. Bu kadar.

`I`, `J`, `K` birer değişkendir. İstenirse bir döngünün şartında, istenirse bir `if` içinde, istenirse bir işlem kutusunda, istenirse bir döngünün ilk değeri olarak, istenirse döngü değişkeni olarak kullanılır. Döngü değişkeni olarak kullanıldığında döngü kutusuna yazılan ilk değer ona atanır. Burada `I`'nın döngü değişkeni olarak kullanılmasının nedeni, `I > N` olduğunun bilinmesi, yani `A` ile ilgili yapılacak bir iş kalmamasıdır. `A`'nın elemanlarında gezmek için `I` kullanılıyordu; artık ona ihtiyaç yoktur. `I` yerine `X`, `Y`, `Z` gibi başka bir değişken de kullanılabilirdi; bu yalnız değişken israfı olurdu, başka hiçbir şey değişmezdi.

> **Hocanın vurgusu:** Akış çizilirken akışın kurallarına göre davranılmalı ve konuşulmalıdır. "Burada tanımladık, orada tanımlamadık" diye bir şey yoktur; hoca bu ifadeyi hiç kullanmadığını ve bu düşünce kalıbından sıyrılmak gerektiğini söyledi.

## 8. Akıştan C Koduna

Çizilen akışın bir de kodu yazıldı. Hoca terminalde `merge.c` dosyasını açtı (ekrandan, 00:45:00 ve 00:50:00).

### 8.1 Değişkenler ve Okuma

Önce olmazsa olmaz `#include <stdio.h>` ve `int main(void)` yazıldı. Dizi boyutu `#define SIZE 100` makrosuyla verildi. Döngülerde kullanılacak `i`, `j` ve `k`, eleman sayıları `n` ve `m`, ve üç dizi tanımlandı:

```c
int i, j, k;
int n, m;
int a[SIZE], b[SIZE], c[SIZE];
```

Diziler şöyle okundu (ekrandan, 00:50:00):

```c
printf("Please neter # of elements for array A :");
scanf("%d", &n);

for(i = 0; i < n; i++) {
	printf("Please enter %d. element : ", i);
	scanf("%d", &a[i]);
}
```

`B` için aynı blok `m` ve `b[i]` ile tekrarlandı.

Bu sırada bir öğrenci, dizi elemanları okunurken `scanf` içinde `&` kullanılmadığını fark etti ve hoca düzeltti; karede `&a[i]` ve `&b[i]` yazıyor.

**Soru:** İkinci dizi `B` okunurken de `i` kullanıldı; `j` olması gerekmez mi?

**Cevap:** Öyle bir zorunluluk yoktur. Burada yalnız diziler okunuyor; henüz akıştaki `I`, `J`, `K`'ya ilk değer verilip girilen birleştirme döngüsüne gelinmedi. Bu kısım, akışta giriş kutusunda gösterilen `N, A(N), M, B(M)` okumasına karşılık gelir. İki dizi farklı döngü değişkenleriyle de, aynı döngü değişkeniyle de okunabilir; birbirini bozan ya da birbirine karışan bir durum yoktur.

### 8.2 Birleştirme Döngüsü

Birleştirme döngüsü akıştaki gibi yazıldı (ekrandan, 00:55:00):

```c
while((i < n) && (j < m)) {

	if( a[i] < b[j] )  {
		c[k] = a[i];
		i++;
	} else {
		c[k] = b[j];
		j++;
	}
	k++;
}
```

Akıştaki gibi önce `A`'nın elemanının mı `B`'nin elemanının mı küçük olduğu kontrol edilir. `a[i] < b[j]` ise `a[i]` atanır ve `A`'nın bir sonraki elemanına geçilir; `i = i + 1` ifadesinin kısa hâli `i++` yazıldı. Değilse `b[j]` atanır ve `j` artırılır. Her iki kolda da `c[k]`'ya atama yapıldığı için `C`'nin bir sonraki elemanına geçmek üzere `k` her turda artırılır.

### 8.3 Akış 1 Tabanlı, C 0 Tabanlı

Döngüden çıkınca yapılacak kontrolü yazarken hoca bir değişiklik yaptığını belirtti: koşulu `i == n` olarak yazdı. Bunun nedeni şudur: akışta dizinin elemanları 1'den başlar ve `N`'ye kadar gider, bu yüzden akışta `I <= N` ve `J <= M` yazıldı. C'de ise dizi indisi 0'dan başlar ve `N` elemanlı bir dizinin son indisi `N-1`'dir. `i`, `n` değerine ulaştığında dizinin son indisi geçilmiş olur. Bu yüzden döngü şartı `i < n` olur. Döngüden çıkışta ya `i` `n`'ye eşit olacaktır ya da `j` `m`'ye. `i == n` ise `A`'nın sonuna gelinmiş ve geçilmiş demektir; akıştaki `I > N`'nin doğru koluna karşılık gelir. Hangi kontrolü seçeceğiniz yalnız kolların hangi işi yapacağını değiştirir.

Kod ilk yazıldığında ilk değerler akıştan olduğu gibi aktarılmıştı: `i = 1; j = 1; k = 1;` (ekrandan, 00:55:00). Bir öğrenci, akıştaki gibi 1'den başlatıldığını hatırlattı; hoca teşekkür edip düzeltti. Son hâlde `i = 0; j = 0; k = 0;` yazıyor (ekrandan, 01:05:00).

### 8.4 Kopyalama ve Yazdırma

Döngüden sonra kopyalama kolları ve sonuç yazdırma eklendi (ekrandan, 01:05:00):

```c
if ( i == n)  {
	for (i = j; i < m; i++) {
		c[k] = b[i];
		k++;
	}
} else {
	for (j = i; j < n; j++) {
		c[k] = a[j];
		k++;
	}
}

for(i = 0; i < n+m; i++)
	printf("%d\t", c[i]);
printf("\n");
```

Bir öğrenci ikinci `for`'un içinde `m` yerine `n` olması gerektiğini söyledi; hoca haklı olduğunu söyleyip düzeltti. Karede son hâl `for (j = i; j < n; j++)` biçimindedir.

## 9. Test ve Hata Ayıklama

### 9.1 İlk Derleme ve İlk Test

Hoca "deneme yanılma yöntemiyle" derleyip baktı: `gcc -Wall merge.c -o Merge`. İlk derleme bir hata verdi (ekrandan, 01:00:00):

```text
merge.c:39:7: error: expected ';' after expression
                        j++
                           ^
                           ;
1 error generated.
```

`j++` satırının sonuna noktalı virgül eklenip yeniden derlendi. İlk test örnekteki dizilerle yapıldı: `n = 3`, `A = 3, 5, 7`, `m = 3`, `B = 2, 8, 11`. Çıktı (ekrandan, 01:00:00):

```text
2       3       5       7       8       11
```

> **Hocanın vurgusu:** "Çalıştı" deyip sevinmek yetmez. Kod farklı şekillerde test edilmeli, gerçekten çalıştığından emin olunmalıdır. Hoca, önceki derste bir öğrencinin kodunun dizi boyutları 2 iken çalışıp başka boyutlarda bozulduğunu hatırlattı. Akışın nereye ilerlediğini görmek için `printf`'ler yerleştirilmelidir.

### 9.2 İkinci Test: Hata Ortaya Çıkıyor

İkinci test: `n = 5`, `A = 2, 6, 89, 101, 200`, `m = 3`, `B = 4, 5, 6` (ekrandan, 01:00:00). Elemanlar doğru okundu; `C`'ye önce 2, sonra 4, 5 ve 6 yerleşti, ardından "iş çığırından çıktı" ve yanlış değerler geldi.

Nerede, ne zaman, nasıl bozulduğunu bulmak için hoca birleştirme döngüsüne şu satırı ekledi (ekrandan, 01:05:00):

```c
printf("i : %d - j : %d - k : %d\n", i, j, k);
```

Kopyalama kollarına da hangi dizinin kopyalanacağını ve hangi aralıkta kopyalanacağını yazan satırlar eklendi:

```c
printf("Array A will be copied...\n");
printf("starting from %d to %d", i, n);
```

**Soru:** Yukarıdaki `if`'e küçük eşit koysak düzelir mi? İki tane 6 geldiği için eşitlik durumunu kontrol etmedik diye düşündüm.

**Cevap:** Bu daha önce konuşuldu. Önünde iki sayı vardır ve hangisinin önce alındığının bu anlamda bir önemi yoktur. "6, 6'dan küçük müdür?" sorusunun cevabı her zaman hayırdır; ikisinden biri alınır, sonra öbürüne geçilir. Hangisine geçildiğinin sonuca doğrudan bir etkisi yoktur. Hata kodun geri kalan kısmındadır. Hoca ayrıca sorunu tahminle değil, analiz yoluyla bulmak gerektiğini söyledi.

Bir başka öğrenci asıl hatayı buldu: bir dizi bittikten sonra öbür diziyi `C`'ye kopyalayan iki kolun ikisinde de `B`'nin elemanları atanıyordu. `else` kolunda `c[k] = b[j];` yazıyordu (karede imleç bu satırdaki `b` harfinin üzerinde, 01:05:00). Doğrusu `c[k] = a[j];` olmalıdır, çünkü bu kolda `A`'nın kalanı kopyalanır. Ayrıca "starting from" satırlarının sonuna `\n` eklendi.

Düzeltmeden sonra aynı girdiyle kopyalama doğru yerden başladı ve sorun çözüldü.

> **Ek bilgi (derste anlatılmadı):** Ajan denemesinde, `else` kolunda `c[k] = b[j];` bırakılan kod bu girdiyle `2 4 5 6 5 6` ve ardından çöp değerler yazdı; çünkü bu kolda `j`, `i = 1`'den `n = 5`'e kadar gider ve `b[1]`'den `b[4]`'e kadar okunur; `b[3]` ve `b[4]` girilmemiş, değer atanmamış elemanlardır. Düzeltilmiş kod `2 4 5 6 6 89 101 200` verdi. Hata ayıklama satırları açıkken ara çıktı `i : 1 - j : 3 - k : 3` satırıyla döngüden çıkıldığını ve "Array A will be copied..., starting from 1 to 5" yazdığını gösterdi.

## 10. Koşullu Derleme ile Hata Ayıklama Çıktıları

Ekrana yazılan bu mesajlar tamamen hata ayıklama (debug) amaçlıdır; normal şartlarda istenmez. Kodun asıl hâline dönmek için bunları kaldırmanın birkaç yolu vardır:

- Her satırın başına yorum işareti (`//`) koymak.
- Bloğun öncesine ve sonrasına yorum işaretleri koyarak (`/* ... */`) o kısmı kapatmak.
- Koşullu derleme kullanmak.

Hoca üçüncü yolu gösterdi. Hata ayıklama satırları `#ifdef DEBUG` ile `#endif` arasına alındı (ekrandan, 01:10:00 ve 01:15:00):

```c
#ifdef DEBUG
	printf("i : %d - j : %d - k : %d\n", i, j, k);
#endif
```

Bu şekilde derlenip çalıştırıldığında bilgilendirme mesajlarının hiçbiri yazılmadı. Nedeni şudur: `#` ile başlayan her satır ön işlemciye (preprocessor) verilen bir yönergedir. `#include` ve `#define` nasıl kullanılıyorsa, `#ifdef` de bir koşul tanımlar: `DEBUG` makrosunun tanımlı olması durumu. `DEBUG` tanımlı değilse aradaki satırlar derlenmez.

Makro adının alt çizgilerle süslenmesi (`__DEBUG__` gibi) gerekmez; `DEBUG` da olur. Ekranda önce `__DEBUG__` yazılıp sonra `DEBUG` olarak sadeleştirildi.

Kodun başına `#define DEBUG` yazılırsa, yani `DEBUG` makrosu tanımlı hâle getirilirse, kod çalıştırıldığında mesajlar görünür. Böylece her seferinde satırlara girip çıkıp değiştirmek yerine tek bir satırla iş biter.

Bu iş derleme sırasında da yapılabilir. Hoca derleme komutunda `DEBUG` makrosunun 1 olarak tanımlanmasını söyledi; kodun içinde de zaten `#ifdef DEBUG` vardı. Böylece kodu hiç düzenlemeden, yalnız dışarıdan bir makro tanımlayarak programın farklı davranması sağlanır. <!-- BELİRSİZ: derleme komutu karelerde görünmüyor; altyazıda "trede deyip debug makrosunun bir olarak tanımlanması" deniyor, komut büyük olasılıkla gcc -Wall -DDEBUG=1 merge.c -o Merge biçimindeydi. -->

> **Ek bilgi (derste anlatılmadı):** gcc'de `-D AD` ya da `-DAD=değer` seçeneği, kaynak kodun en başına `#define AD değer` yazılmış gibi davranır. Ajan denemesinde `gcc -Wall -DDEBUG=1 merge.c` ile derlenen kod ara değerleri yazdı, seçeneksiz derlenen kod yazmadı.

## 11. Makrolarla Dizi Boyutu

**Soru:** En başta `a`, `b` ve `c` için `SIZE` makrosuyla bellekte yer ayırdık. `c`'nin boyutuna `2*SIZE` yazabilir miydik?

**Cevap:** Yazılabilir, sözdizimsel olarak hiçbir hatası yoktur ve derlenir. Ama makul ya da mantıklı değildir. Makro kullanmanın nedeni, kodda sabit değerler bırakmamak, sabitleri tek bir noktada toplamak ve bir değişiklik gerektiğinde orada yapabilmektir. Koda `* 2` yazmak bununla çelişir. `c`'ye diğerlerinin iki katı bir boyut verilmek isteniyorsa ayrı bir makro tanımlanır ve kendi içinde tutarlı olsun diye o makro `SIZE` üzerinden yazılır (ekrandan, 01:15:00):

```c
#define SIZE 100
#define DSIZE 2*SIZE
...
int a[SIZE], b[SIZE], c[DSIZE];
```

Böylece yalnız `SIZE` değiştirildiğinde her şey kendiliğinden değişir. Bir makro, yukarıda tanımlanmış başka bir makro kullanılarak tanımlanabilir; olay böyle esnetilebilir. Hoca makro işleme konusunun ayrıntılarının yapısal programlama dersinde konuşulacağını söyledi.

Hoca sorunun amacını da değerlendirdi: öğrenci ayrılan bellek alanını daha uygun hâle getirmeyi düşünüyor; bir dizi için 100, öbürü için 100 ayrıldıysa birleşik dizinin en az 200 olması gerekir. Bu doğru bir düşüncedir, ama şu anki hedef dizi boyutlarının en uygun olması değildir. İstenilen boyutta dizi ayırmak için dinamik bellek ayırma gerekir: bir integer pointer'ı, `N` tane integer'dan oluşan bir alanı gösterecek şekilde ayarlanır. Bu, bu dersin konusu değildir; yapısal programlama dersinde işlenecektir.

> **Ders sonrası not:** `#define DSIZE 2*SIZE` parantezsizdir. Burada yalnız dizi boyutu olarak kullanıldığı için sorun çıkmaz. Ama makro düz metin yerine koyma ile çalıştığından, bu makro başka bir ifadede kullanılırsa (örneğin `x / DSIZE`, `x / 2*100` olur) beklenmedik sonuç verir. Bu yüzden `#define DSIZE (2*SIZE)` yazmak daha güvenlidir.

### 11.1 Dersin Son Hâliyle Kod

Aşağıdaki kod, 01:05:00, 01:10:00 ve 01:15:00 karelerindeki son hâlin birleştirilmesidir. Mesaj metnindeki `neter` yazım hatası (`enter` olmalı) ekrandaki gibi bırakıldı. Ajan tarafından `gcc -Wall` ile uyarısız derlendi; `3, 5, 7` ile `2, 8, 11` girdisiyle `2 3 5 7 8 11`, `2, 6, 89, 101, 200` ile `4, 5, 6` girdisiyle `2 4 5 6 6 89 101 200` çıktısını verdi.

```c
#include <stdio.h>

#define SIZE 100
#define DSIZE 2*SIZE

int main(void)  {
	int i, j, k;
	int n, m;
	int a[SIZE], b[SIZE], c[DSIZE];

	printf("Please neter # of elements for array A :");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("Please enter %d. element : ", i);
		scanf("%d", &a[i]);
	}

	printf("Please neter # of elements for array B :");
	scanf("%d", &m);
	for(i = 0; i < m; i++) {
		printf("Please enter %d. element : ", i);
		scanf("%d", &b[i]);
	}

	i = 0;
	j = 0;
	k = 0;

	while((i < n) && (j < m)) {
		if( a[i] < b[j] )  {
			c[k] = a[i];
			i++;
		} else {
			c[k] = b[j];
			j++;
		}
		#ifdef DEBUG
			printf("i : %d - j : %d - k : %d\n", i, j, k);
		#endif
		k++;
	}
	if ( i == n)  {
		#ifdef DEBUG
			printf("Array B will be copied...\n");
			printf("starting from %d to %d\n", j, m);
		#endif
		for (i = j; i < m; i++) {
			c[k] = b[i];
			k++;
		}
	} else {
		#ifdef DEBUG
			printf("Array A will be copied...\n");
			printf("starting from %d to %d\n", i, n);
		#endif
		for (j = i; j < n; j++) {
			c[k] = a[j];
			k++;
		}
	}

	for(i = 0; i < n+m; i++)
		printf("%d\t", c[i]);
	printf("\n");

	return 0;
}
```

## Örnek Sorular

**Soru 1** (derste ele alınan problem, 00:07:49 ve ekrandan, 00:10:00): Küçükten büyüğe sıralı `N` elemanlı `A` dizisi ile `M` elemanlı `B` dizisini, yine küçükten büyüğe sıralı yeni bir `C` dizisinde birleştiren akış diyagramını çizin. `A = 3, 5, 7` ve `B = 2, 8, 11` için sonucu adım adım izleyin.

> **Çözüm (derste verildi):** Akış 3, 5 ve 6. bölümlerdedir. İzleme 2. bölümdeki tablodadır; sonuç `C = 2, 3, 5, 7, 8, 11`.

**Soru 2** (derste sözlü, 00:15:57): Birleştirme döngüsünün şartında `AND` yerine `OR` kullanılmalı mı?

> **Cevap (derste verildi):** Hayır. Dizilerden biri bittiği anda, yani `I > N` ya da `J > M` olduğu anda döngüden çıkılmalıdır. `OR` kullanılırsa biten dizinin sınırının dışındaki elemanlara erişilir. Şart `I <= N AND J <= M` olmalıdır; eşitlik, son elemanın da karşılaştırılması için gereklidir.

**Soru 3** (derste sözlü, 00:23:41): Birleştirme döngüsünden çıkıldığında hangi dizinin bittiği nasıl anlaşılır?

> **Cevap (derste verildi):** `I > N` (ya da `J > M`) kontrolü yapılır. `I > N` doğruysa `A` bitmiştir, `B`'nin kalanı kopyalanır; yanlışsa `A`'nın kalanı kopyalanır. C kodunda 0 tabanlı indis nedeniyle bu kontrol `i == n` olarak yazıldı.

**Soru 4** (derste sözlü, 00:27:20): Kalan elemanları kopyalamak için hangi döngü kullanılmalıdır?

> **Cevap (derste verildi):** `for`. Kopyalamanın başlangıcı (`J` ya da `I`) ve sonu (`M` ya da `N`) bellidir, yani adım sayısı bilinir. `while` adım sayısının bilinmediği durumlar içindir.

**Soru 5** (derste sözlü, 00:49:00): Diziler okunurken `B` için de döngü değişkeni olarak `i` kullanılabilir mi?

> **Cevap (derste verildi):** Evet. Okuma aşamasında hangi indis değişkeninin kullanıldığının önemi yoktur; birleştirme döngüsüne henüz gelinmemiştir.

**Soru 6** (derste sözlü, 01:02:56): Birleştirme döngüsündeki `if`'e küçük eşit koymak, iki tane 6 olduğu için ortaya çıkan hatayı düzeltir mi?

> **Cevap (derste verildi):** Hayır. Eşit iki elemandan hangisinin önce alındığı sonucu değiştirmez. Hata, `A`'nın kalanını kopyalayan kolda `c[k] = a[j];` yerine `c[k] = b[j];` yazılmış olmasıydı.

**Soru 7** (derste sözlü, 01:12:18): `c` dizisinin boyutuna doğrudan `2*SIZE` yazılabilir mi?

> **Cevap (derste verildi):** Sözdizimi açısından evet, derlenir. Ama sabitleri tek yerde toplamak için ayrı bir makro tanımlamak daha doğrudur: `#define DSIZE 2*SIZE`, `c[DSIZE]`.

## Dersin Toparlaması

Bu derste, sıralı iki diziyi tek bir sıralı dizide birleştirme problemi önce akış diyagramıyla, sonra C koduyla baştan sona çözüldü. Akışın özü, iki dizinin o anki elemanlarını karşılaştırıp küçük olanı sonuç dizisine yazmak, yalnız onun indisini ve sonuç dizisinin indisini artırmaktır. Döngü, iki dizinin de sınırları içinde kalındığı sürece (`AND`, küçük eşit) sürer. Döngüden çıkınca hangi dizinin bittiği ayrıca kontrol edilir ve öbür dizinin kalanı bir `for` döngüsüyle kopyalanır. Akışta "tanımlama" diye bir kavram olmadığı, boşta kalan bir indis değişkeninin döngü değişkeni olarak kullanılabileceği vurgulandı.

Koda geçerken akışın 1 tabanlı, C'nin 0 tabanlı indislemesi arasındaki fark (`I <= N` yerine `i < n`, `I > N` yerine `i == n`, ilk değerlerin 0 olması) gösterildi. Kodun tek bir girdiyle çalışmasının yeterli olmadığı, farklı girdilerle denenmesi ve `printf` ile ara değerlerin izlenmesi gerektiği gerçek bir hata üzerinden görüldü. Hata ayıklama çıktılarını kod değiştirmeden açıp kapatmak için `#ifdef DEBUG` ile koşullu derleme ve sabitleri makrolarda toplama alışkanlığı tanıtıldı; istenen boyutta dizi ayırmanın (dinamik bellek) yapısal programlama dersine kaldığı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
