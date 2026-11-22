# Ders 11 Çalışma Özeti

## Genel Konular

- Uygulama oturumunun yapısı
  - Bu kayıt dersin ikinci uygulama oturumudur. Yedi soru slaytta gösterildi; her soru için önce kısa bir süre verildi, öğrenciler kendileri denedi, sonra çözüm Dev-C++ üzerinde birlikte yazıldı.
  - Sorular iki gruptadır: tek boyutlu diziler (ters çevirme, çoğunluk elemanı) ve iki boyutlu matrisler (transpoz, simetri için değişiklik sayısı, spiral tarama).
- Soru 1: Dizinin tersini bulma
  - Dizi boyutu ve elemanları kullanıcıdan alınır (ekrandan, 00:10:00). Örnek: `6 3 1 4 2 9` dizisinin tersi `9 2 4 1 3 6`.
  - İkinci bir dizi kullanmak ek bellek demektir. Bunun yerine baş (`start`) ve son (`end`) indisleri tutulur, bu iki eleman `temp` ile yer değiştirilir (swap), `start` bir artırılır, `end` bir azaltılır. `start < end` olduğu sürece devam edilir (ekrandan, 00:20:00).
  - Aynı işlem iki değişkenli bir `for` ile de yazılabilir: `for(start=0, end=n-1; start<end; start++, end--)` (ekrandan, 00:30:00). Tek indisle `arr[i]` ile `arr[n-i-1]` yer değiştirilirse döngü `n/2`'ye kadar gitmelidir.
- `#define` ile makro tanımlama
  - Dinamik bellek henüz işlenmediği için dizi en büyük boyutla tanımlanır: `#define MAX_Length 50`, `int arr[MAX_Length]`. Girilen boyut bu sınırı aşarsa `do-while` ile tekrar sorulur.
  - Makro, önişlemcinin (preprocessor) program derlenmeden önce yaptığı metin yerleştirmesidir: adı gördüğü her yere yanındaki değeri koyar. Bu yüzden satır sonuna noktalı virgül konmaz, veri tipi yazılmaz. String değer tırnak içinde yazılır.
- Soru 2: Çoğunluk elemanı (majority element)
  - Tanım: dizide `n/2`'den fazla sayıda bulunan eleman (ekrandan, 00:45:00). `3 3 1 3 2 3 6 3` için çoğunluk elemanı 3'tür (5 kez geçer, 5 > 4). `3 3 1 4 2` için çoğunluk elemanı yoktur (3 iki kez geçer, en az 3 gerekir).
  - Basit yaklaşım $O(n^2)$: her elemanın frekansı iç içe döngüyle sayılır, en büyük frekans (`maxCount`) ve onun indisi (`index`, başlangıçta -1) tutulur, sonunda `maxCount > n/2` kontrol edilir (ekrandan, 00:55:00).
- Soru 3: Moore'un oylama algoritması (Moore's Voting Algorithm)
  - Bir aday eleman belirlenir, sonra yalnız adayın frekansı hesaplanır; çoğunluk elemanı olmayabileceği için sonunda `n/2`'den büyük mü diye kontrol edilir (ekrandan, 01:05:00).
  - Aday indisi ilk elemandan, sayaç 1'den başlar; döngü ikinci elemandan başlar. Eşitse sayaç artar, değilse azalır. Sayaç 0 olursa aday indisi o anki elemana taşınır ve sayaç yeniden 1 yapılır.
  - İç içe döngü yoktur, karmaşıklık $O(n)$'dir.
- Soru 4: $M \times N$ matrisin transpozu
  - Boyutlar ve elemanlar kullanıcıdan alınır (ekrandan, 01:10:00). Transpozda indisler yer değiştirir: `T[i][j] = a[j][i]`. Transpoz matrisi ters boyutla tanımlanır: `int a[R][C], T[C][R]` (ekrandan, 01:20:00).
  - Matris `%3d` ile yazdırılırsa sütunlar hizalı çıkar; her satırdan sonra `\n` basılır.
- Soru 5: Binary kare matrisin simetrik olması için gereken en az değişiklik
  - $N \times N$ binary matrisin ilk köşegene (sol üstten sağ alta) göre simetrik olması için kaç eleman değiştirilmeli (ekrandan, 01:25:00)? Karşılıklı iki eleman farklıysa birini değiştirmek yeter, yani her farklı çift 1 değişiklik sayılır.
  - Basit çözüm: transpoz oluşturulur, `a[i][j] != T[i][j]` olan bütün konumlar sayılır; her çift iki kez sayıldığı için sonuç 2'ye bölünür (ekrandan, 01:35:00).
- Soru 6: Soru 5'in daha verimli çözümü
  - Transpoz matrisi bellekte tutulmaz; `a[j][i]` ile aynı matristen okunur. Yalnız köşegenin altındaki yarıya bakılır: iç döngü `j < i` olur. Böylece 2'ye bölmeye gerek kalmaz (ekrandan, 01:40:00).
- Soru 7: Matrisin spiral formunun c. elemanı
  - Kullanıcı bir sıra numarası verir; matris spiral biçimde (ilk satır soldan sağa, son sütun yukarıdan aşağı, son satır sağdan sola, ilk sütun aşağıdan yukarı, sonra içe doğru) taranır ve o sıradaki eleman yazdırılır. 4x5'lik `1..20` matrisinde `c = 6` için çıktı 10'dur (ekrandan, 01:55:00).
  - Başlangıç satırı `k`, başlangıç sütunu `l` tutulur; her kenar tarandıktan sonra matris küçültülür (`k++`, `n--`, `m--`, `l++`). Taranan her elemanda sayaç artırılır ve sayaç `c`'ye eşitse eleman yazdırılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Her `scanf` öncesinde kullanıcıya ne gireceğini söyleyen bir `printf` olmalı
  - Hiç mesaj basmayan program çalışırken kullanıcı ne yapacağını bilemez.
- `scanf`'te değişkenin adresi (`&n`), `printf`'te değeri (`n`) verilir
  - Okuma bir adrese yazma işlemidir, yazdırma ise değere erişmektir.
- Sabit değerler makro olarak tanımlanır
  - Dizi boyutu gibi sabitler kodun içine sayı olarak gömülmez. Dinamik bellek öğrenildikten sonra dizi boyutu doğrudan kullanıcının istediği kadar ayrılacak.
- Sonuç genellikle bellekte tutulmalı
  - Diziyi tersten yazdırmak ekrana doğru çıktıyı verse de, istenen genelde dizinin kendisinin ters çevrilmesidir.
- Gereksiz bellek ve gereksiz karşılaştırmadan kaçınmak
  - Ters çevirmede ikinci dizi, simetri sorusunda transpoz matrisi tutmaya gerek yoktur; simetri sorusunda matrisin yarısına bakmak yeter.
- Döngüye başlarken süslü parantezi hemen koymak
  - Tek satırlık gövdede gerekmese de sonradan ekleme yaparken hata yapmamak için önerildi.

## Kısa Tekrar Notları

- Swap: `temp = arr[start]; arr[start] = arr[end]; arr[end] = temp;`
- Ters çevirme döngüsü `start < end` iken çalışır; tek indisle `i < n/2`.
- `#define AD deger` satırına noktalı virgül ve tip yazılmaz; önişlemci adı değerle değiştirir.
- Çoğunluk elemanı: frekansı `n/2`'den büyük eleman. Tamsayı bölmede `count > n/2`, $n=5$ için en az 3 demektir.
- Basit çoğunluk çözümü $O(n^2)$, Moore oylama algoritması $O(n)$ ve sonunda adayın frekans kontrolü şart.
- Transpoz: `T[i][j] = a[j][i]`, transpoz $N \times M$ boyutludur.
- Simetri için değişiklik sayısı: köşegen altında `a[i][j] != a[j][i]` olan çift sayısı.
- Spiral tarama: dört kenar sırayla, her kenardan sonra sınır daralır; son iki kenar `if(k < m)` ve `if(l < n)` ile korunur.

## Detaylı Açıklamalar

- **Dizinin tersi (Soru 1).** Ekranda yazılan program `#define MAX_Length 50` ile başlar, `int arr[MAX_Length], n;` ve `int start, end, temp, i;` tanımlanır (ekrandan, 00:30:00). Boyut `do { ... } while(n > MAX_Length);` ile okunur, elemanlar `printf("element[%d]:", i+1)` mesajıyla tek tek alınır. Sonra `start = 0; end = n-1;` ile başlanır ve `while(start < end)` döngüsünde swap yapılıp `start++`, `end--` uygulanır. Slayttaki örnekte `1 2 3 4 5 6` dizisinde önce 1 ile 6, sonra 2 ile 5, sonra 3 ile 4 yer değiştirir ve `6 5 4 3 2 1` elde edilir (ekrandan, 00:20:00). Tam program (ekrandaki ilk 33 satır ve anlatıma göre tamamlanan son kısım) `gcc -Wall` ile derlendi; `6 3 1 4 2 9` girdisiyle `9 2 4 1 3 6` çıktısı alındı.

```c
#include<stdio.h>

#define MAX_Length 50

int main(){

    int arr[MAX_Length], n;
    int start, end, temp, i;

    do{
        printf("Enter the of array:");
        scanf("%d", &n);
    }while(n > MAX_Length );

    printf("Enter the elements:\n");

    for(i=0;i<n;i++){
        printf("element[%d]:", i+1);
        scanf("%d", &arr[i]);
    }

    start = 0;
    end= n-1;

    while(start < end){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    printf("Reversed array: ");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
```

<!-- BELİRSİZ: Kodun 33. satırdan sonraki kısmı (end--, sonuç yazdırma döngüsü ve mesajı) karede görünmüyor; anlatıma göre tamamlandı. "Enter the of array" mesajı ekranda böyle yazılıydı. -->

- **Dizi boyutu ve makro tartışması.** Bir öğrenci boyutu önce kullanıcıdan alıp diziyi `int arr[n]` diye tanımlamayı sordu. Derste, değer verilmemiş bir boyutla dizi tanımlanamayacağı, boyut önceden okunursa bu yazımın çalıştığı, ama sabitlerin makroyla tanımlanmasının doğru alışkanlık olduğu söylendi. 50 elemanlık yer ayırıp 5 eleman kullanmanın israf olduğu kabul edildi; bunun çözümü ileride işlenecek dinamik bellek ayırmadır.
- **Ders sonrası not.** Derste dizinin boyutunun "dinamik bellek ayırmadan" kullanıcıdan alınamayacağı ve "önişlemcinin bellekte yer ayırdığı" söylendi. Doğrusu: önişlemci yalnız metin yerleştirmesi yapar, bellek ayırmaz. C99'dan beri boyutu çalışma anında belli olan diziler (variable length array) tanımlanabilir: `scanf("%d", &n);` sonrasında `int arr[n];` geçerlidir (`gcc -Wall -std=c99` ile denendi). Ancak dizi, `n`'ye değer verilmeden önce tanımlanırsa (ekranda bir an görünen `int n, arr[n];` gibi) boyut belirsiz olur ve bu hatalıdır.
- **Çoğunluk elemanı, basit çözüm (Soru 2).** Değişkenler `int count, maxCount = 0, i, j, index = -1;` (ekrandan, 00:50:00). `index` -1 ile başlar çünkü hiçbir dizi indisi negatif değildir. Dış döngü her eleman için `count`'u sıfırlar, iç döngü dizinin tamamında bu elemana eşit olanları sayar. İç döngü bitince `count > maxCount` ise `maxCount` ve `index` güncellenir. En sonda `maxCount > n/2` ise `arr[index]` yazdırılır, değilse "çoğunluk elemanı yok" mesajı verilir. Kodun döngü kısmı karede görünmüyor; anlatıma göre yazılıp `gcc -Wall` ile derlendi ve slayttaki iki girdiyle denendi (3 ve "No Majority Element").
- **Moore oylama algoritması (Soru 3).** Slayttaki `3 3 1 3 2 6 3 3` dizisinde (ekrandan, 00:55:00) aday ilk eleman 3, sayaç 1'dir. 3=3 sayaç 2, 1 farklı 1, 3=3 2, 2 farklı 1, 6 farklı 0 olur; sayaç sıfırlanınca aday 6 olur, sayaç 1. Sonraki 3 farklı, sayaç 0; aday o 3 olur, sayaç 1. Son 3 eşit, sayaç 2. Döngü biter, aday 3'tür. Sonra adayın frekansı sayılır (5) ve `5 > 8/2` olduğu için 3 çoğunluk elemanıdır. Sayacın 1'den başlamasının nedeni, ilk karşılaştırmada eşitsizlik olursa negatif değere düşmemesi ve yalnız sıfır kontrolünün yeterli olmasıdır. Derste algoritmanın çok sayıda `if-else` içerdiği de belirtildi.
- **Transpoz (Soru 4).** Ekrandaki programda `#define R 10`, `#define C 10`, `int a[R][C], T[C][R], m, n;` tanımlanır; boyutlar `while(m > R || n > C)` koşullu `do-while` ile okunur (ekrandan, 01:20:00). Transpoz döngüsü `for(i=0;i<n;i++) for(j=0;j<m;j++) T[i][j] = a[j][i];` biçimindedir ve sonuç `printf("%3d", T[i][j])` ile `n` satır, `m` sütun olarak yazdırılır (ekrandan, 01:30:00). Program derlendi; 3x3 `1..9` girdisi slayttaki `1 4 7 / 2 5 8 / 3 6 9` çıktısını, 2x3 girdi 3x2 transpozu verdi.
- **Simetri için değişiklik sayısı (Soru 5 ve 6).** Slayttaki 3x3 matriste (`1 1 1 / 0 0 1 / 1 1 1`) tek farklı çift vardır, sonuç 1; 5x5 matriste (`1 1 0 1 0 / 1 1 1 0 1 / 0 0 0 1 0 / 0 0 1 1 1 / 0 1 0 0 0`) üç farklı çift vardır, sonuç 3 (ekrandan, 01:25:00). Basit çözümde transpoz `T` oluşturulur, bütün matris taranıp farklar `flip` ile sayılır ve `flip/2` yazdırılır (ekrandan, 01:35:00). Verimli çözümde `T` silinir ve döngü `for(i=0;i<n;i++) for(j=0;j<i;j++) if(a[i][j] != a[j][i]) flip++;` olur; sonuç doğrudan `flip`'tir. Verimli sürüm karede görünmüyor, anlatıma göre yazıldı. İki sürüm de derlendi ve slayttaki iki matris için 1 ve 3 sonuçlarını verdi.
- **Spiral form (Soru 7).** Tarama `while(k < m && l < n)` döngüsünde yapılır. (1) `k`. satır `l`'den `n-1`'e taranır, sonra `k++`. (2) Son sütun (`n-1`) `k`'dan `m-1`'e taranır, sonra `n--`. (3) `if(k < m)` ise son satır (`m-1`) `n-1`'den `l`'ye geriye taranır, sonra `m--`. (4) `if(l < n)` ise ilk sütun (`l`) `m-1`'den `k`'ya yukarı taranır, sonra `l++`. Son iki adımdaki `if`'ler, `k` ve `n` değiştiği için matrisin o anda bitmiş olabileceği durumda gereksiz taramayı önler. Bir öğrenci, istenen eleman bulununca taramanın sürmesine gerek olmadığını söyledi; derste bunun için bir bayrak değişkeninin `while` koşuluna eklenebileceği belirtildi. Kod karede görünmüyor, yalnız anlatıma göre yazılıp `gcc -Wall` ile derlendi ve 1x1'den 5x5'e kadar bütün boyutlarda python ile karşılaştırılarak doğrulandı; 4x5 `1..20` matrisinde `c = 6` için 10 verdi.

<!-- BELİRSİZ: 02:00:26-02:00:35 arasında bir öğrencinin "sağ üstteki n-1" ile ilgili düzeltmesi tam anlaşılmıyor; spiral kodunun ekrandaki son hâli karelerde yok. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
