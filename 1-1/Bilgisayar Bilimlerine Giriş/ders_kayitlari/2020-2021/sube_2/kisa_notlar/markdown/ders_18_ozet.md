# Ders 18 Çalışma Özeti

## Genel Konular

- Çalışma yöntemi: problem, akış, kod
  - Bu dersten itibaren her problem için önce akış diyagramı çizilir, sonra akış C'ye aktarılır. Yazılan kodun çizilen akışla uyumlu olması beklenir.
- Sıralama (sorting) problemi
  - Bilgisayar sistemlerinde çok sık çözülmesi gereken problemlerden biridir. Merge sort, bubble sort, quick sort, selection sort gibi farklı algoritmalar vardır.
  - Örnek dizi (ekrandan, 00:15:00): `9 3 7 11 66 23 6 41`. Küçükten büyüğe sıralanmış hali `3 6 7 9 11 23 41 66`.
  - Sıralama küçükten büyüğe de büyükten küçüğe de yapılabilir; akıştaki karşılaştırma ters çevrilerek yön değiştirilir.
- Bubble sort (kabarcık sıralama)
  - Dizinin başından başlanır, her eleman sağındakiyle karşılaştırılır. Soldaki büyükse ikisi yer değiştirir. Dizinin sonuna kadar gidilince bir tur biter.
  - Bir turda hiç yer değiştirme olmazsa dizi sıralıdır ve algoritma durur.
  - Örnekte turlar (ekrandan, 00:20:00; python ile doğrulandı):
    - 1. tur: `3 7 9 11 23 6 41 66`
    - 2. tur: `3 7 9 11 6 23 41 66`
    - 3. tur: `3 7 9 6 11 23 41 66`
    - 4. tur: `3 7 6 9 11 23 41 66`
    - 5. tur: `3 6 7 9 11 23 41 66`
    - 6. tur: hiçbir değişiklik yok, dizi sıralı.
  - Akış (ekrandan, 00:35:00 ve 00:50:00): `N, A(N)` okunur; `SWAPPED = 1`; `SWAPPED = 1` oldukça dönen koşullu döngüde önce `SWAPPED = 0`, sonra `I ← 1 || 1` for döngüsünde `A(I) > A(I+1)` ise `TMP = A(I)`, `A(I) = A(I+1)`, `A(I+1) = TMP`, `SWAPPED = 1`.
  - Dıştaki döngünün kaç kez döneceği bilinmez, bu yüzden bir kontrol değişkeni (`swapped`) kullanılır. İçteki for döngüsü diziyi bir kez dolaşır.
- Döngü sınırı hatası
  - Akışta for döngüsünün bitişi `N` yazılmıştı. `I = N` olduğunda `A(I+1)` yani `A(N+1)` istenir; böyle bir eleman yoktur. Doğrusu bitişin `N-1` olmasıdır (ekrandan, 00:40:00).
  - İndis üzerinde bir fazlasına ya da bir eksiğine erişme gibi ek işlem yapılıyorsa döngü sınırı yeniden kontrol edilmelidir.
  - Birçok dil bunu derleme zamanında yakalamaz; bir kısmı çalışma zamanında "out of bounds" hatası verir. C ise hata vermez; sonuç belleğin durumuna göre değişir.
- lvalue ve rvalue
  - `x = y + 1;` ifadesinde `x`'in önceden değeri olması önemli değildir, çünkü sol taraftadır ve yalnız değer atanır. `y` ilk kez burada kullanılıyorsa değeri bilinmez ve sonuç da bilinmez olur.
  - Takastaki `TMP` ilk kez sol tarafta kullanıldığı için ilk değer gerektirmez. Akışta değişken tanımlanmaz; değerler girdiyle okunur, koşulda ya da hesapta sağ tarafta kullanılacak değişkenlere (ör. `SWAPPED`, döngü değişkeni `I`) ilk değer atanır.
- Bubble sort'un C kodu (ekrandan, 00:55:00 ve 01:00:00)
  - `#define SIZE 100` ile sabit dizi boyutu makro olarak verilir; `int i, n, tmp, swapped = 1, ar[SIZE];`.
  - `while (swapped)` içinde `swapped = 0;` ve `for (i = 0; i < n-1; i++)` ile karşılaştırma ve takas yapılır.
  - Sonuç `printf("%d\t", ar[i]);` ile yan yana, tab ile ayrılarak yazdırılır, en sonda `printf("\n");`.
  - `while (swapped)` ile `while (swapped == 1)` aynı işi görür: C'de karşılaştırma 1 ya da 0 üretir ve sıfırdan farklı değer doğru sayılır.
- Selection sort (seçmeli sıralama)
  - Örnek dizi (ekrandan, 01:20:00): `21 51 11 41 1 71 91`.
  - Her turda sıralanmamış kısmın en küçük elemanı bulunur ve o kısmın başındaki elemanla yer değiştirir. Yerleşen kısım bir daha kontrol edilmez.
  - Turlar (python ile doğrulandı): `1 51 11 41 21 71 91`, `1 11 51 41 21 71 91`, `1 11 21 41 51 71 91`; sonraki turlarda değişiklik olmaz.
  - Akış (ekrandan, 01:35:00): `I ← 1 || 1`, bitiş `N-1`; `MIN = A(I)`, `PL = I`; `J ← I+1 || 1`, bitiş `N`; `A(J) < MIN` ise `MIN = A(J)`, `PL = J`; iç döngüden sonra `A(PL) = A(I)`, `A(I) = MIN`; en sonda `A(I)` yazdırılır.
  - İç döngü `J = I+1`'den başlar: her turda önceki turlarda yerleşen elemanların ötesinden devam edilir.
  - Takasta `TMP` gerekmez, çünkü `A(PL)`'nin değerinin kopyası zaten `MIN`'dedir.
  - Dış döngünün bitişi `N` değil `N-1` olabilir: son elemana gelindiğinde kontrol edilecek eleman kalmamıştır.
- Selection sort'un C kodu ve derleme (ekrandan, 01:50:00)
  - Kod bir editörde `selection.c` olarak yazıldı, derlendi ve örnek diziyle çalıştırıldı; çıktı `1 11 21 41 51 71 91`.
  - Derleyici hataları tek tek düzeltildi: tanımlanmamış `n` (undeclared identifier), `scanf` yerine `scan` yazılması (örtük fonksiyon bildirimi), `ar` yerine `A` yazılması.
- Sıralamada adım sayısı
  - Bubble sort'ta tur sayısı dizinin başlangıç düzenine bağlıdır; sıralı bir dizide bir turda biter. Selection sort'ta tur sayısı bellidir: `n` elemanlı dizi için `n-1` tur, dizi sıralı gelse bile.
  - Hangi sıralama ya da arama algoritmasının kullanılacağı verinin içeriğine ve veri yapısına bağlıdır (ağaç, bağlı liste gibi yapılar ileride veri yapıları dersinde görülür).
- İki sıralı diziyi sıralı yeni bir dizide birleştirme (merge)
  - Örnek (ekrandan, 01:55:00 ve 02:00:00): `3 5 7 9 11 23` ve `7 8 10 15 41` → `3 5 7 7 8 9 10 11 15 23 41`.
  - İki diziyi arka arkaya ekleyip sonra sıralamak makul bir çözüm değildir.
  - Doğru yol: iki dizinin o anki elemanları karşılaştırılır, küçük olan yeni diziye kopyalanır ve yalnız o dizinin indisi bir artırılır. İndisler adım adım ve ayrı ayrı ilerlediği için bu iş tek bir döngüyle yapılabilir.
- printf ile hata ayıklama ve G/Ç tamponlama
  - `printf` en temiz hata ayıklama aracıdır: döngülerin içine değişken değerlerini yazdıran satırlar konarak kodun nereye kadar ilerlediği görülür.
  - G/Ç işlemleri tamponlanır (C çalışma zamanı kütüphanesi ve işletim sistemi). Sonunda `\n` olmayan bir `printf` çıktısı hemen ekrana gelmeyebilir; tampon `\n` ile ya da `fflush` ile boşaltılır.
  - Sonsuz döngüye giren bir programın süreci başka bir terminalde `ps -ef` ile görülebilir; süreç yüksek CPU kullanır. Program Ctrl-C ile sonlandırılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Akış ve kod uyumu
  - Bir problem verildiğinde önce akış çizilir, sonra kod yazılır. Kodu bildiği için doğrudan kod yazmak kabul edilmez. Akışta ve kodda farklı değişken adları kullanmak hatalara yol açar.
- Döngü sınırı
  - Döngü içinde `I+1` gibi bir indise erişiliyorsa sınır `N-1` olmalıdır. C dizi dışına çıkmayı yakalamaz.
- Takas ve TMP
  - İki elemanın yer değiştirmesi normalde geçici değişkenle üç adımda yapılır. Selection sort'ta değerin kopyası `MIN`'de olduğu için `TMP` gerekmez; bu yer karıştırılmamalıdır (akışta ünlemle işaretlendi).
- lvalue ve rvalue
  - Sol taraftaki değişkenin ilk değeri önemsizdir; sağ tarafta hesaba giren değişkenin ilk değeri olmalıdır. Akışta değişken tanımlaması yapılmaz.
- Genelleme yapmamak
  - İki örnekten "sıralamada adım sayısı belli olur" ya da "olmaz" diye genelleme yapılmamalıdır; algoritmaya göre değişir.
- Varsayımla değil, kanıtla hata ayıklamak
  - Programın hangi satırda takıldığı tahmin edilmez; `printf` ile gösterilir. Ön yargıyla kontrol edilmez.

## Kısa Tekrar Notları

- Bubble sort: komşuları karşılaştır, büyükse takas et; bir turda takas yoksa dur. Dış döngü koşullu (`swapped`), iç döngü for.
- Bubble sort'ta `A(I+1)`'e eriştiği için iç döngü bitişi `N-1`.
- `while (swapped)` ≡ `while (swapped == 1)` (değişken yalnız 0/1 alıyorsa).
- Selection sort: her turda en küçüğü bul, sıralanmamış kısmın başına koy. `I: 1..N-1`, `J: I+1..N`.
- Selection sort takası: `A(PL) = A(I)`, `A(I) = MIN` (TMP yok).
- Bubble sort'ta tur sayısı veriye bağlı; selection sort'ta `n-1` tur sabit.
- C'de dizi 0'dan başlar: döngü `i = 0; i < n`. Kullanıcıya 1'den başlayan sıra göstermek istenirse `printf`'te `i+1` yazdırılır.
- Merge: iki indis, küçük olanı kopyala, onun indisini artır; tek döngü yeter.
- `printf("...\n")` tamponu boşaltır; hata ayıklama çıktılarının sonuna `\n` koy.

## Detaylı Açıklamalar

- Bubble sort'un mantığı bir örnekle kurulur. `9 3 7 11 66 23 6 41` dizisinde ilk turda 9 ile 3 yer değiştirir, sonra 9 ile 7; 9-11 ve 11-66 sıralı olduğu için dokunulmaz; 66 sırayla 23, 6 ve 41 ile yer değiştirerek sona taşınır. Tur sonunda dizi `3 7 9 11 23 6 41 66` olur. En büyük eleman bir turda sona "kabarcık gibi" çıkar. Sonraki turlarda 6 her turda bir adım sola kayar ve beşinci turda dizi sıralanır. Altıncı turda hiç takas olmadığı için algoritma biter. Algoritmanın durma şartı "bir tur boyunca hiç takas yapılmamış olması"dır; bu yüzden dış döngünün kaç kez döneceği önceden bilinmez ve kontrol `swapped` değişkeniyle yapılır. Dış döngüye girmeden `swapped = 1` atanır ki döngüye en az bir kez girilsin; her turun başında `swapped = 0` yapılır, takas olunca `swapped = 1` yapılır.

- Akışta iç döngünün bitişi önce `N` yazılmıştı. Bir öğrenci `I = N` olduğunda `A(I+1)` ile dizinin dışına çıkıldığını fark etti. Hoca bunu dersin önemli bir noktası yaptı: döngü değişkeni dizinin indisi olarak doğrudan kullanılıyorsa sınır `N` doğrudur, ama indise bir eklenip ya da çıkarılıp erişiliyorsa sınır yeniden kontrol edilmelidir. C bu hatayı ne derlemede ne çalışmada garanti olarak bildirir; program bazen çalışır, bazen hata verir.

- Bubble sort'un C kodu tahtaya yazıldı (ekrandan, 00:55:00 ve 01:00:00). Kod `gcc -Wall` ile derlendi ve örnek diziyle `3 6 7 9 11 23 41 66` çıktısını verdi (ajan tarafından test edildi):

```c
#include <stdio.h>
#define SIZE 100

int main(void) {
    int i, n, tmp, swapped = 1, ar[SIZE];
    printf("Please enter # of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Please enter %d. eleman", i);
        scanf("%d", &ar[i]);
    }
    while (swapped) {
        swapped = 0;
        for (i = 0; i < n - 1; i++) {
            if (ar[i] > ar[i + 1]) {
                tmp = ar[i];
                ar[i] = ar[i + 1];
                ar[i + 1] = tmp;
                swapped = 1;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d\t", ar[i]);
    }
    printf("\n");
    return 0;
}
```

- Selection sort'ta her tur sıralanmamış kısmın ilk elemanını geçici minimum (`MIN`) kabul ederek başlar ve onun yerini `PL`'de tutar. Daha küçük bir eleman bulundukça `MIN` ve `PL` güncellenir. Tur sonunda `A(PL) = A(I)` ile turun başındaki eleman minimumun eski yerine yazılır, `A(I) = MIN` ile minimum başa yazılır. Selection sort'un C kodu bir editörde yazılıp derlendi (ekrandan, 01:50:00). Aşağıdaki kod ekrandaki son haliyle aynıdır, `gcc -Wall` ile derlendi ve `21 51 11 41 1 71 91` ile `1 11 21 41 51 71 91` çıktısını verdi:

```c
#include <stdio.h>

#define SIZE 100

int main(void) {

	int i, j, n, min, pl, ar[SIZE];

	printf("Please enter # of elements : ");
	scanf("%d", &n);

	for(i = 0; i < n; i++)  {
		printf("Please enter elent %d : ", i);
		scanf("%d", &ar[i]);
	}

	for(i = 0; i < n-1; i++) {

		min = ar[i];
		pl = i;

		for(j = i+1; j < n; j++)  {

			if(ar[j] < min )  {
				min = ar[j];
				pl = j;
			}
		}
		ar[pl] = ar[i];
		ar[i] = min;
	}

	for(i = 0; i < n; i++)  {
		printf("%d\t", ar[i]);
	}
	printf("\n");

	return 0;
}
```

- İki sıralı diziyi birleştirmede (merge) her adımda iki dizinin "sıradaki" elemanları karşılaştırılır. Örnekte önce 3 ile 7 karşılaştırılır, 3 yazılır; sonra 5 ile 7, 5 yazılır; iki 7 eşit olduğunda hangisinin önce yazıldığı fark etmez. Bu böyle sürer ve sonunda `3 5 7 7 8 9 10 11 15 23 41` elde edilir. Her dizi için ayrı bir indis tutulur ve yalnız elemanı kopyalanan dizinin indisi artırılır. İndisler birlikte değil ayrı ayrı ilerlediği için tek bir for döngüsüyle iki diziyi aynı anda dolaşmak bu problemin doğal çözümü değildir.

- `printf` çıktısının görünmemesi programın takıldığı anlamına gelmez. G/Ç yavaş olduğu için çıktılar tamponda biriktirilir; satır sonu (`\n`) ya da `fflush` çağrısı tamponu boşaltır. Hata ayıklama için konan `printf` satırlarının sonuna `\n` konmazsa yanlış sonuca varılabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
