# Ders 11 Çalışma Özeti

## Genel Konular

- Uygulama oturumunun yapısı
  - Bu kayıt bir uygulama (problem çözümü) oturumudur. Önce bir önceki laboratuvar sorusunun (LED tabela / kayan yazı) çözümü gösterildi, sonra iki yeni uygulama sorusu Dev-C++ ortamında C ile çözülüp çalıştırıldı.
  - Oturumun başında dersin öğretim üyesi, ödev ve lab kodlarının hangi C standardına uyması gerektiğine dair soruları cevapladı.
- Dersin kodlama standardı (C89/ANSI C)
  - Kod `gcc -ansi` ya da `gcc -std=c89` ile derlenebilmelidir.
  - `for` ya da `if` gibi bir yapının içinde (örneğin `for (int i = 0; ...)`) değişken tanımlanmaz; değişkenler bloğun başında tanımlanır.
  - Fonksiyon prototipleri `main`'den önce yazılır.
  - `break` yalnız `switch` ile kullanılır; `continue` kullanılmaz.
  - Bu derste `struct`/`typedef` yoktur; ders diziler, matrisler, fonksiyonlar ve pointer'lar üzerinden algoritma geliştirmeye odaklanır.
  - Kod Dev-C++ ya da CodeBlocks gibi bir IDE'de veya çevrimiçi bir C derleyicisinde (online GDB) denenebilir.
- Lab sorusu: LED tabela gibi kelimeyi her adımda sola kaydırma
  - Kelime kullanıcıdan alınıp bir diziye konur, işlemler bu dizi üzerinde yapılır; her adımda ilk harf sona gider ve her adım ekrana yazılır. Örnek kelime: "Muhendislik" (ekrandan, 00:15:00).
  - Kısıtlar: `for` yerine `do-while` kullanılır, hazır fonksiyon (`strlen` vb.) kullanılmaz, kullanıcı `E` ya da `e` girerse program baştan başlar (ekrandan, 00:15:00).
  - Uzunluk `strlen` olmadan bulunur: `n` sayacı, `arr[n]` sonlandırıcı karakter `'\0'` olana kadar artırılır.
  - Bir adım: `temp = arr[0]`, sonra `arr[j] = arr[j+1]` ile dizi bir sola kaydırılır (`j < n-1`), sonda `arr[n-1] = temp` (ekrandan, 00:20:00).
  - $n$ harfli kelimede $n$ adım sonra kelime eski haline döner.
- Uygulama 2, Soru 1: Binary matrisi ana köşegene göre simetrik yapmak için minimum değişiklik sayısı
  - Simetri koşulu: her $i, j$ için $A[i][j] = A[j][i]$.
  - Boyut en çok `N` (10) olacak şekilde `do-while` ile tekrar tekrar sorulur; elemanlar iç içe iki döngüyle okunur, matris `%3d` ile hizalı yazdırılır (ekrandan, 00:25:00).
  - Bütün matris gezilir, `A[i][j] != A[j][i]` olan her durumda `flip` bir artar. Her uyumsuz çift iki kez sayıldığı için sonuç `flip/2` olarak yazdırılır.
  - Köşegen elemanları kendileriyle karşılaştırılır, her zaman eşittir, sayaca hiçbir şey eklemez.
  - Daha iyi çözüm: yalnız köşegenin üst üçgenini ($j > i$) gezmek. Böylece her çift bir kez karşılaştırılır ve ikiye bölme gerekmez.
- Uygulama 2, Soru 2: Diziyi sıralayıp her elemanın kaç kez tekrar ettiğini yazdırmak
  - Sıralama iç içe iki döngüyle yapılır: `i` dıştan, `j = i+1`'den başlar; `dizi[i] > dizi[j]` ise `temp` ile yer değiştirilir (ekrandan, 00:35:00).
  - Tekrar sayımında her `i` için önce `j < i` aralığında aynı değer aranır. Daha önce görülmediyse (`sayac == 0`) değer `j = i+1`'den sonra aranıp sayılır ve "x sayısı k defa tekrar ediyor" yazdırılır.
  - Örnek: 12 20 12 15 3 3 girdisi sıralanınca 3 3 12 12 15 20 olur; 3 ve 12 ikişer kez, 15 ve 20 birer kez tekrar eder (ekrandan, 00:40:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- C89 standardına uyum
  - Ödev ve lab kodlarında blok içi (`for (int i...)`) tanımlama olmamalı, prototipler `main`'den önce yazılmalıdır. Kod göndermeden önce bu standarda uyan bir derleyicide denenmelidir.
- `do-while` döngüsünün anlamı
  - Gövde önce bir kez çalışır, sonra koşul sağlandıkça tekrarlanır. Bu yüzden "bir kez çalış, sonra kullanıcıya devam etmek isteyip istemediğini sor" kalıbına uygundur.
- Format belirteçleri
  - `%s` bir kelimeyi (string) okur, `%c` tek karakteri okur/yazar, `%3d` sayıyı 3 karakter genişliğinde hizalayarak yazar.
- `flip/2`'nin nedeni
  - Matrisin tamamı gezildiğinde örneğin (4,5) ile (5,4) hem $i,j$ hem $j,i$ sırasıyla iki kez karşılaştırılır; bu yüzden sayacın yarısı minimum değişiklik sayısıdır.
- İç döngünün `j = i+1`'den başlaması
  - Eleman kendisiyle karşılaştırılmasın ve daha önce karşılaştırılan çiftler tekrar ele alınmasın diye.
- Örnekleri fonksiyonlarla yeniden yazma
  - Uygulamadaki çözümler `main` içinde yazıldı; öğrencilere bu çözümleri dizi işlemlerini fonksiyonlara ayırarak yeniden yazmaları önerildi.

## Kısa Tekrar Notları

- Ders kodları C89 uyumlu olmalı: blok başında tanımlama, `main` öncesi prototip, `break` yalnız `switch`'te.
- `strlen` olmadan uzunluk: `'\0'` görülene kadar sayaç artır.
- Sola döndürme: ilk elemanı sakla, kalanları bir sola kaydır, saklananı sona koy; $n$ adımda başa dönülür.
- `scanf(" %c", &devam)`: `%c` önündeki boşluk tamponda kalan Enter'ı atlar.
- Simetri için minimum değişiklik = $A[i][j] \ne A[j][i]$ olan çiftlerin sayısı; tam gezmede `flip/2`, üst üçgende doğrudan `flip`.
- Köşegen simetri sayımına katkı yapmaz.
- `i` ve `j = i+1` ile iki döngülü yer değiştirme sıralaması: $O(n^2)$ karşılaştırma.
- Tekrar sayımı: değer daha önce görülmediyse say ve yazdır; görüldüyse atla.

## Detaylı Açıklamalar

- Kodlama standardı. Dersin ödev ve lab çözümleri ANSI C (C89) kurallarına uymalıdır. Bunun en sık karşılaşılan sonucu, `for (int i = 0; ...)` biçiminde döngü başlığında tanımlama yapılamamasıdır; `gcc -std=c89` bu satırda "'for' loop initial declarations are only allowed in C99 or C11 mode" hatası verir (ajan tarafından gcc ile denendi). Fonksiyon prototipleri `main`'den önce yazılır. `break` yalnız `switch` içinde, `continue` hiç kullanılmaz. Bu derste `struct` ve `typedef` yer almaz.
- LED tabela problemi. Program önce kelimeyi `scanf("%s", arr)` ile alır. Uzunluk için `n = 0` ile başlanır ve `do { n++; } while (arr[n] != '\0');` döngüsüyle sonlandırıcı karaktere kadar sayılır; bu, `strlen`'in yaptığı iştir. Dış `do-while` (`i < n`) her adımı üretir: `printf("Adim %d: ", i+1)`, `temp = arr[0]`, iç `do-while` ile `arr[j] = arr[j+1]` (`j < n-1`), sonra `arr[n-1] = temp`. Ardından üçüncü bir `do-while` dizinin harflerini `%c` ile tek tek yazar. En dıştaki `do-while` ise kullanıcı `E` ya da `e` girdiği sürece programı baştan çalıştırır (ekrandan, 00:20:00). "bilgisayar" girildiğinde ilk adımda `b`, ikinci adımda `i`, üçüncü adımda `l` sona gider ve 10. adımda kelime ilk haline döner.

```c
/* Ekranda gorunen kisim (ekrandan, 00:20:00) */
i = 0;
do {
    printf("Adim %d: ", i+1);
    temp = arr[0];
    j = 0;
    do {
        arr[j] = arr[j+1];
        j++;
    } while (j < n-1);
    arr[n-1] = temp;

    j = 0;
    do {
        printf("%c ", arr[j]);
        j++;
    } while (j < n);
    printf("\n");

    i++;
} while (i < n);

printf("\nTekrar denemek icin E ya da e?");
scanf(" %c", &devam);
}while(devam == 'E' || devam == 'e');
return 0;
}
```

- Simetrik matris problemi. `int A[N][N]`, `n`, `i`, `j`, `flip` tanımlanır. Boyut `do { ... } while (n > N);` ile `N`'yi aşmayana kadar sorulur. Elemanlar `element[%d][%d]:` istemiyle okunur, matris `%3d` ile yazdırılır. Ardından `flip = 0;` ve iç içe iki döngüde `if (A[i][j] != A[j][i]) flip++;` (ekrandan, 00:25:00). Tam gezmede her uyumsuz çift iki kez sayıldığı için sonuç `flip/2`'dir. Köşegen elemanları kendileriyle karşılaştırıldığı için asla sayılmaz. Derste 3×3 bir örnekte sonuç 3 bulundu: köşegen dışındaki üç çiftin üçü de uyumsuzdu. <!-- BELİRSİZ: Derste girilen 3×3 matrisin tamamı karede görünmüyor; yalnız element[0][0]=0 ve element[0][1]=1 okunuyor (ekrandan, 00:30:00). -->
- Sıralama ve tekrar sayımı. Dizi boyutu ve elemanlar kullanıcıdan alınır, önce girildiği sırayla yazdırılır. Sıralamada dış döngü `i = 0`'dan, iç döngü `j = i+1`'den başlar; `dizi[i] > dizi[j]` ise `temp` ile takas yapılır (ekrandan, 00:35:00). Sonra sıralı dizi yazdırılır. Tekrar sayımında her `i` için `sayac` sıfırlanır, `j < i` aralığında aynı değer varsa sayaç artar; sayaç sıfır kalırsa bu değer ilk kez görülüyordur ve `j = i+1`'den itibaren aranıp sayılır. Örnek çıktı (ekrandan, 00:40:00): `3 sayisi 2 defa tekrar ediyor.`, `12 sayisi 2 defa tekrar ediyor.`, `15 sayisi 1 defa tekrar ediyor.`, `20 sayisi 1 defa tekrar ediyor.`
  - Ders sonrası not: Derste bu sıralama "Bubble Sort" diye anıldı. Ekrandaki kod komşu elemanları değil `dizi[i]` ile ondan sonraki her `dizi[j]`'yi karşılaştırır; bu, büyük olasılıkla "exchange sort" (seçmeli sıralamanın takaslı biçimi) olarak bilinen yöntemdir. Klasik kabarcık sıralaması `dizi[j]` ile `dizi[j+1]`'i karşılaştırır. İkisinin de karmaşıklığı $O(n^2)$'dir ve sonuç doğru sıralanmış dizidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
