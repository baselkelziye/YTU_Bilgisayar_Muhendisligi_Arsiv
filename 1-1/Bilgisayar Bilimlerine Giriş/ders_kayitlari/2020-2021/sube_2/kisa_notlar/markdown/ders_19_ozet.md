# Ders 19 Çalışma Özeti

## Genel Konular

- Problem: sıralı iki diziyi tek bir sıralı dizide birleştirmek (merge)
  - Elimizde küçükten büyüğe sıralı iki dizi var: `N` elemanlı `A` ve `M` elemanlı `B`. Bu iki dizi, yine küçükten büyüğe sıralı yeni bir `C` dizisinde birleştirilecek.
  - Elle örnek: `A = 3, 5, 7`, `B = 2, 8, 11` (ekrandan, 00:10:00). `A` için indis `I`, `B` için `J`, `C` için `K` kullanılır; üçü de 1 ile başlar.
  - Her adımda `A(I)` ile `B(J)` karşılaştırılır, küçük olan `C(K)`'ya yazılır, yalnız onun indisi bir artar. `K` her adımda bir artar.
  - Dizilerden biri bitince karşılaştırmaya gerek kalmaz; öbür dizinin kalan elemanları sırayla `C`'ye kopyalanır. Örnekte 2, 3, 5, 7 yerleşince `A` biter, `B`'nin kalanı olan 8 ve 11 kopyalanır: `C = 2, 3, 5, 7, 8, 11` (ekrandan, 00:30:00).
- Akış diyagramı (ekrandan, 00:15:00, 00:20:00, 00:25:00, 00:35:00, 00:40:00)
  - Giriş: `N, A(N), M, B(M)` okunur. İlk değerler: `I = 1`, `J = 1`, `K = 1`.
  - Döngü şartı: `I <= N AND J <= M`. Şart doğru oldukça döngü sürer.
  - Döngü gövdesi: `A(I) < B(J)` ise (T) `C(K) = A(I)`, `I = I + 1`; değilse (F) `C(K) = B(J)`, `J = J + 1`. İki kol birleştikten sonra `K = K + 1`.
  - Döngüden çıkınca bağlantı noktası `1` ile ikinci sayfaya geçilir. Orada `I > N` sorulur.
    - Doğruysa (T) `A` bitmiştir, `B` dizisi kopyalanacaktır: `I ← J, 1, M` döngüsünde `C(K) = B(I)`, `K = K + 1`.
    - Yanlışsa (F) `B` bitmiştir, `A` dizisi kopyalanacaktır: `J ← I, 1, N` döngüsünde `C(K) = A(J)`, `K = K + 1`.
  - Sonda `I`, 1'den 1'er artarak `N + M`'ye kadar giden bir döngüyle `C` yazdırılır ve akış biter. <!-- BELİRSİZ: son çıktı kutusunun içi karede doldurulmuş görünmüyor; çıktının C(I) olduğu altyazıdan ve C kodundan çıkarıldı. -->
- C koduna geçiş (`merge.c`, ekrandan, 00:50:00 - 01:15:00)
  - `#define SIZE 100` ile dizi boyutu makroyla verildi: `int a[SIZE], b[SIZE], c[SIZE];`. Diziler `for` döngüsüyle `scanf("%d", &a[i]);` biçiminde okundu.
  - Birleştirme döngüsü: `while((i < n) && (j < m))`, içinde `if (a[i] < b[j])` ile iki kol ve kolların dışında `k++`.
  - Döngüden sonra `if (i == n)` ise `B`'nin kalanı (`for (i = j; i < m; i++)`), değilse `A`'nın kalanı (`for (j = i; j < n; j++)`) kopyalandı.
  - Sonda `for(i = 0; i < n+m; i++) printf("%d\t", c[i]);` ile sonuç yazdırıldı.
- Akıştan koda geçerken indis farkı
  - Akışta dizi indisleri 1'den `N`'ye gider, bu yüzden şart `I <= N`'dir ve "A bitti" kontrolü `I > N`'dir.
  - C'de indis 0'dan başlar, `N` elemanlı dizinin son indisi `N-1`'dir. Bu yüzden şart `i < n`, "A bitti" kontrolü `i == n` olur. İlk değerler de 1 değil 0 olmalıdır.
- Hata ayıklama
  - Kodu bir kez çalıştırıp bırakmamak gerekir; farklı girdilerle denenmelidir. `3, 5, 7` ve `2, 8, 11` ile doğru çalışan kod, `A = 2, 6, 89, 101, 200` ve `B = 4, 5, 6` ile 2, 4, 5, 6'dan sonra yanlış değerler üretti.
  - Döngünün içine `i`, `j`, `k`'yi yazdıran `printf` satırları konarak akışın nereye gittiği izlendi. Hata, `A`'nın kalanını kopyalayan `else` kolunda `c[k] = a[j];` yerine `c[k] = b[j];` yazılmış olmasıydı (ekrandan, 01:05:00).
  - Hata ayıklama çıktılarını kapatmanın yolları: satır başına yorum işareti koymak, bloğu yorum içine almak ya da `#ifdef DEBUG ... #endif` ile koşullu derlemek (ekrandan, 01:10:00).
  - `#` ile başlayan her satır ön işlemciye (preprocessor) verilen bir yönergedir. `#ifdef DEBUG`, `DEBUG` makrosu tanımlıysa aradaki satırların derlenmesini sağlar. Makro kodda `#define DEBUG` ile ya da kodu hiç değiştirmeden derleme sırasında komut satırından tanımlanabilir.
- Makrolarla boyut verme
  - `c` dizisine `2*SIZE` yazmak sözdizimi açısından doğrudur ve derlenir. Ama makronun amacı sabitleri tek bir yerde toplamaktır. Hoca bunun yerine ayrı bir makro tanımladı: `#define DSIZE 2*SIZE` ve `c[DSIZE]` (ekrandan, 01:15:00). Böylece yalnız `SIZE` değiştirilince her şey kendiliğinden değişir.
  - İstenen boyutta dizi ayırmak dinamik bellek ayırma (pointer) gerektirir. Bu, bu dersin konusu değildir; yapısal programlama dersinde işlenecektir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Döngü şartında `AND` kullanılır, `OR` değil
  - `I` ile `A`'nın, `J` ile `B`'nin elemanlarına erişilir. İkisi de aynı anda dizi sınırları içinde kalmalıdır. Biri dizinin dışına taşarsa (örnekte `I = 4`) bellekte bize ayrılmamış bir yere gidilir (out of bound). O anda bir dizi bitmiştir; öbürünün de taşmasını beklemek anlamsızdır.
  - Asıl dikkat edilmesi gereken nokta eşitliktir: son elemanın da karşılaştırılması için şart `I < N` değil `I <= N` olmalıdır.
- Döngüden çıkınca hangi dizinin bittiği bilinmez
  - Bunu anlamak için ayrıca kontrol yapılır: `I > N` (ya da eşdeğeri `J > M`) sorulur.
- Kalan elemanları kopyalamak için `for` kullanılır
  - Kopyalamanın nereden başlayıp nereye kadar gideceği bellidir (`J`'den `M`'ye ya da `I`'dan `N`'ye). Adım sayısı bilindiği için `for` döngüsü uygundur.
- "Tanımlama" diye bir şey yok
  - Akış diyagramında değişken tanımlanmaz. Giriş kutusu dışarıdan okunacak değişkenleri, işlem kutusu ilk değer atamasını gösterir. İkinci sayfadaki döngüde `I` ve `J`'nin yeniden kullanılması, onları yeni değişken yapmaz; `A` bittiyse `I`'nın işi kalmamıştır, döngü değişkeni olarak kullanılabilir. Yerine başka bir değişken de kullanılabilirdi, yalnız değişken israfı olurdu.
  - Akış çizilirken akışın kurallarına göre davranılmalı ve konuşulmalıdır.
- "Anladım" demek yetmez
  - Şüphe varsa konu net bir şekilde değerlendirilip özümsenene kadar konuşulmalıdır.
- Kod bir kez çalıştı diye doğru sayılmaz
  - Farklı durumlarla test edilmeli, gerekirse ara değerler yazdırılarak akış izlenmelidir.

## Kısa Tekrar Notları

- Merge: iki sıralı diziden her adımda küçük olan alınır, yalnız onun indisi ve `K` artar.
- Döngü şartı: `I <= N AND J <= M` (akışta, 1 tabanlı). C'de: `(i < n) && (j < m)`, indisler 0'dan başlar.
- `K = K + 1` her iki kolda da yapıldığı için `if` dışına bir kez yazılır.
- Döngüden sonra: `I > N` ise `B`'nin kalanı, değilse `A`'nın kalanı kopyalanır (C'de `i == n`).
- Kalan elemanlar `for` ile kopyalanır; boştaki indis değişkeni döngü değişkeni olarak kullanılabilir.
- `C` dizisinde `N + M` eleman olur.
- Eşit elemanlarda (6 ve 6) hangisinin önce alındığının sonuca etkisi yoktur.
- `#ifdef DEBUG ... #endif` ile hata ayıklama çıktıları kod değiştirilmeden açılıp kapatılabilir.
- Sabitler makroda toplanır: `#define SIZE 100`, `#define DSIZE 2*SIZE`.

## Detaylı Açıklamalar

- Elle izleme. `A = 3, 5, 7`, `B = 2, 8, 11`, başta `I = J = K = 1`. 3 ile 2 karşılaştırılır, 2 alınır: `C(1) = 2`, `J = 2`, `K = 2`. 3 ile 8: 3 alınır, `I = 2`, `K = 3`. 5 ile 8: 5 alınır, `I = 3`, `K = 4`. 7 ile 8: 7 alınır, `I = 4`, `K = 5`. Artık `I > N` olduğu için döngü biter. `A` bittiği için `B`'nin `J = 2`'den `M = 3`'e kadar olan elemanları (8, 11) `C(5)` ve `C(6)`'ya kopyalanır. Sonuç `2, 3, 5, 7, 8, 11` (ekrandan, 00:30:00; ara değerler python ile doğrulandı).
- C kodundaki iki düzeltme. Kod ilk yazıldığında ilk değerler akıştaki gibi `i = 1; j = 1; k = 1;` idi (ekrandan, 00:55:00). Bir öğrenci bunu fark etti ve değerler 0 yapıldı (ekrandan, 01:05:00). Bir başka öğrenci, `A`'nın kalanını kopyalayan ikinci `for`'un sınırında `m` yerine `n` olması gerektiğini söyledi; son hâlde `for (j = i; j < n; j++)` yazıyor (ekrandan, 01:05:00). Ayrıca ilk derlemede `j++` satırındaki eksik noktalı virgül `merge.c:39:7: error: expected ';' after expression` hatasını verdi (ekrandan, 01:00:00).
- İlk test. `n = 3`, `A = 3, 5, 7`, `m = 3`, `B = 2, 8, 11` girildi; çıktı `2 3 5 7 8 11` (ekrandan, 01:00:00).
- İkinci test ve hata. `n = 5`, `A = 2, 6, 89, 101, 200`, `m = 3`, `B = 4, 5, 6` girildi. 2, 4, 5, 6 doğru yerleşti, sonra yanlış değerler geldi. Döngüye `printf("i : %d - j : %d - k : %d\n", i, j, k);` konarak izlendi. Bir öğrenci, alttaki iki kopyalama kolunun ikisinde de `B`'nin elemanlarının atandığını fark etti: `else` kolunda `c[k] = b[j];` yazıyordu, doğrusu `c[k] = a[j];`. Ajan denemesi: düzeltilmiş kod bu girdiyle `2 4 5 6 6 89 101 200` verir; hatalı kod ise 2, 4, 5, 6'dan sonra çöp değerler yazar.
- Koşullu derleme. Hata ayıklama satırları `#ifdef DEBUG` ve `#endif` arasına alındı. `DEBUG` tanımlı değilken bu satırlar derlenmez, çıktıda görünmez. Kodun başına `#define DEBUG` yazılınca görünür. Aynı şey kodu açmadan derleme sırasında makro tanımlanarak da yapılır. <!-- BELİRSİZ: derleme komutu karede görünmüyor; altyazıda "trede deyip debug makrosunun bir olarak tanımlanması" deniyor, büyük olasılıkla gcc -DDEBUG=1 biçiminde. --> Makro adı `__DEBUG__` gibi alt çizgili olmak zorunda değildir, `DEBUG` de olur.
- Bu derste son hâliyle yazılan `merge.c` (01:05:00, 01:10:00 ve 01:15:00 karelerinden birleştirildi) ajan tarafından `gcc -Wall` ile uyarısız derlendi ve ekrandaki iki girdiyle denendi; `-DDEBUG=1` ile derlenince ara değerleri de yazdı.

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

- Ders sonrası not: Ekrandaki mesaj metninde `neter` yazım hatası vardır (`enter` olmalı); kod aynen aktarıldı. `DSIZE` makrosu `2*SIZE` olarak parantezsiz tanımlandı. Burada dizi boyutu olarak tek başına kullanıldığı için sorun çıkmaz, ama makro başka bir ifadenin içinde kullanılırsa (`x / DSIZE` gibi) parantezsiz tanım beklenmedik sonuç verebilir; `#define DSIZE (2*SIZE)` daha güvenlidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
