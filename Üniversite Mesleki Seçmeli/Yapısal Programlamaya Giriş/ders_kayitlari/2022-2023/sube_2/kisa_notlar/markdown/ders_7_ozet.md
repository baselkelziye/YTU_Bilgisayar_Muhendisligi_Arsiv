# Ders 7 Çalışma Özeti

## Genel Konular

- Uygulama oturumunun yapısı
  - Bu kayıt dersin ilk uygulama (problem çözümü) oturumudur. Ekrandaki sorular önce birkaç dakika düşünmeye bırakılır, fikirler tartışılır, sonra çözüm Dev-C++ ortamında C ile yazılıp çalıştırılır.
  - Üç soru çözüldü, ardından ilk iki soru bir de dizi kullanılarak yeniden yazıldı ve iki çözüm zaman ve bellek karmaşıklığı açısından karşılaştırıldı.
- Soru 1: Kullanıcıdan alınan pozitif bir sayıyı tersine çevirmek (dizi kullanmadan)
  - Örnek: girilen sayı 1283, ters sayı 3821 (ekrandan, 00:15:00).
  - Sayının 10'a göre modu son basamağı verir (`kalan = sayi % 10`). Sayı 10'a tam sayı bölümüyle bölünerek son basamak atılır (`sayi /= 10`).
  - Ters sayı her adımda 10 ile çarpılıp yeni basamak eklenir: `ters_sayi = ters_sayi * 10 + kalan`. Döngü `sayi > 0` olduğu sürece döner; basamak sayısını ayrıca saymaya gerek yoktur.
  - Değişkenlerin her adımdaki değeri Dev-C++'ın hata ayıklama (debug) modunda kesme noktası koyup adım adım ilerleyerek izlenebilir.
- Soru 2: Tek değişkenli bir polinomun değerini hesaplamak
  - Kullanıcıdan derece $N$, değişken değeri $x$ ve her derecenin katsayısı alınır. Ekrandaki örnek: $N=2$, $3x^2+2x+4$, $x=4$ için sonuç 60 (ekrandan, 00:30:00).
  - Kuvvet her seferinde yeniden hesaplanmaz. `temp = 1` ile başlanır; her adımda `toplam += katsayi * temp;` ve `temp *= x;` yapılır. Böylece `temp` sırasıyla $x^0, x^1, x^2, \dots$ olur.
  - Program `do-while` döngüsüyle tekrar edilir: önce bir kez çalışır, sonra kullanıcı `E` ya da `e` girerse baştan başlar.
- `scanf(" %c", ...)` içindeki boşluk ve giriş tamponu
  - Önceki `scanf("%d")` çağrısından sonra basılan Enter karakteri giriş tamponunda kalır. `%c` önünde boşluk yoksa bu Enter karakter olarak okunur ve döngü kullanıcı bir şey giremeden biter.
  - `%c` önüne konan boşluk tampondaki beyaz boşlukları atlar. Alternatif olarak `fflush(stdin)` gösterildi.
- Mantıksal koşullar, De Morgan ve `or`
  - `devam == 'E' || devam == 'e'` koşulu De Morgan kuralıyla `!(devam != 'E' && devam != 'e')` biçiminde de yazılabilir.
  - C'de `or` diye bir mantıksal operatör yoktur; derleyici `.c` dosyasında hata verir. Mantıksal "veya" `||`'dir. Mantıksal XOR operatörü yoktur, bit düzeyinde XOR `^`'dir.
- Soru 3: Diziyi bir $x$ değerine göre düzenlemek
  - Diziden küçük elemanlar sola, büyük elemanlar sağa toplanır; tam sıralama istenmez. Örnek: dizi `[7 4 5 8 3 9]`, $x=6$ (ekrandan, 01:05:00; 01:25:00).
  - İki indeks kullanılır: `bas = 0`, `son = n-1`. `bas < son` olduğu sürece `dizi[bas] > x` ise `dizi[bas]` ile `dizi[son]` yer değiştirir ve `son--`; değilse `bas++`.
  - Karmaşıklık $O(n)$'dir. Sıralama yapılsaydı kabarcık sıralamasıyla $O(n^2)$, iyi bir sıralamayla $O(n \log n)$ olurdu. Bu işlem QuickSort'taki pivot etrafında bölme adımına karşılık gelir.
- Dizi kullanan çözümler ve bellek karmaşıklığı
  - Sayı ters çevirmenin dizili sürümünde basamaklar `rakamlar` dizisine alınır, sonra tersten birleştirilir (ekrandan, 01:30:00). Zaman karmaşıklığı aynıdır ($n$ basamak için $n$), ama basamak sayısı kadar ek bellek kullanılır.
  - Polinom sorusunun dizili sürümünde katsayılar `katsayilar[MAX]` dizisinde saklanır (ekrandan, 01:40:00). Bu, iki polinomu toplamak ya da çarpmak gibi katsayıların saklanması gereken işlemler için gereklidir.
- `printf`'in dönüş değeri ve `return 0`
  - `printf` yazdırdığı karakter sayısını döndürür. `printf("\n%d", printf("Sayinin tersi: %d", tersi));` ifadesi önce metni yazar, sonra karakter sayısını (123 girişinde 18) basar.
  - `main` sonundaki `return 0;` programın sorunsuz bittiğini işletim sistemine bildirir.
- Standart akışlar
  - Bir program çalışınca işletim sistemi ona üç standart akış verir: `stdin` (giriş), `stdout` (çıkış), `stderr` (hata).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kodlama kuralları
  - Döngü değişkeni `for (int i = 0; ...)` biçiminde döngü içinde tanımlanmaz; değişkenler fonksiyonun başında tanımlanır.
  - Global değişken, `break` ve `continue` kullanılmaz. Her yerde kullanılacak sabitler `#define` ile makro olarak tanımlanır.
  - Dizi boyutu doğrudan sayı (`int a[50]`) yazılmaz, `#define MAX 50` gibi bir makroyla verilir.
  - Kod C standardında yazılır; `.cpp` olarak kaydedip C++ özelliklerine güvenmek hatalı sonuç verir.
- Her zaman diziye başvurmak iyi bir çözüm değildir
  - Aynı zaman karmaşıklığında, dizi gereksiz ek bellek harcar. Algoritmik bir yol varsa dizi kullanılmaz.
  - Hazır bir sıralama algoritması kullanmak her zaman en iyi çözüm değildir; soru sıralama istemiyorsa $O(n)$ bir çözüm aranmalıdır.
- Polinomu küçük dereceden başlayarak hesaplamak
  - Büyük dereceden başlayıp her terimde kuvveti ayrı bir döngüyle hesaplamak iç içe döngü ve $O(n^2)$ demektir. Küçük dereceden başlayıp `temp`'i $x$ ile çarpmak $O(n)$'dir.
- Sorudaki kısıtlara uymak
  - "Dizi kullanmadan", "tek döngüyle", "sıralama yapmadan" gibi kısıtlar sorunun parçasıdır; çözüm bu kısıtlara göre kurulmalıdır.

## Kısa Tekrar Notları

- `% 10` son basamağı verir, `/ 10` son basamağı atar.
- Ters sayı: `ters = ters * 10 + kalan`.
- Polinom: `temp = 1`, döngüde `toplam += katsayi * temp; temp *= x;` ($O(n)$).
- `do-while` gövdeyi en az bir kez çalıştırır.
- `scanf(" %c", &c)`: boşluk, tamponda kalan Enter'ı atlar.
- `!(a != 'E' && a != 'e')` ile `a == 'E' || a == 'e'` aynıdır (De Morgan).
- C'de `or` yok, `||` var; mantıksal XOR yok, bit düzeyinde `^` var.
- Bölme (partition): `bas`/`son` iki indeksi, $O(n)$.
- Dizi aynı zamanda ek bellek demektir.
- `printf` yazdırdığı karakter sayısını döndürür.

## Detaylı Açıklamalar

**Sayıyı tersine çevirme.** Sayının basamaklarına erişmek için 10'a göre mod ve 10'a tam sayı bölme birlikte kullanılır. 1283 için ilk adımda kalan 3, ters sayı $0 \cdot 10 + 3 = 3$, sayı 128 olur. Sonra kalan 8, ters sayı $3 \cdot 10 + 8 = 38$, sayı 12; kalan 2, ters sayı 382, sayı 1; kalan 1, ters sayı 3821, sayı 0 ve döngü biter. Ekrandaki kod (ekrandan, 00:25:00):

```c
#include <stdio.h>

int main() {

    int sayi,kalan,ters_sayi=0;

    printf("Lutfen sayi giriniz...\n");
    scanf("%d",&sayi);
    while(sayi>0){

        kalan=sayi%10;
        ters_sayi=ters_sayi*10+kalan;
        sayi/=10;//sayi=sayi/10;

    }

    printf("Ters sayimiz su sekildedir %d",ters_sayi);

    return 0;
}
```

Bu kod `gcc -Wall` ile derlendi, 1283 girişiyle 3821 sonucunu verdi. Her kalanı hemen `printf` ile basmak da ekranda aynı görüntüyü verir, ama o zaman ters sayı tek bir değişkende tutulmamış olur ve sonradan bir işlemde kullanılamaz.

**Polinom değeri.** Derece $N$ ise $N+1$ katsayı vardır; döngü `i = 0`'dan `i <= N`'e kadar döner. `temp` değişkeni o anki kuvveti tutar. Derste $N=2$, $x=3$ ve katsayılar 5, 2, 3 girildi: $5 + 2\cdot 3 + 3 \cdot 9 = 38$ (ekrandan, 00:45:00). Slayttaki örnekte $3x^2+2x+4$, $x=4$ için $4 + 8 + 48 = 60$ bulunur. Kod `do-while` içine alındığında her turun başında `toplam`'ın sıfırlanması gerekir; bunu derste bir öğrenci fark etti.

**Tampon sorunu.** `scanf("%d", &N)` sayıyı okur ama Enter'ı (`\n`) tamponda bırakır. Sonraki `scanf("%c", &devam)` bu `\n`'i okur; `devam` ne `E` ne `e` olduğu için döngü biter. `" %c"` biçimindeki boşluk beyaz boşlukları atlar.

**De Morgan.** "Devam `E` ise veya `e` ise" koşulunun değili "devam `E`'den farklı ve `e`'den farklı"dır. Bu yüzden `while (!(devam != 'E' && devam != 'e'))` aynı koşuldur. Burada iki koşulun aynı anda doğru olması imkânsız olduğundan "veya" ile "ya da" (XOR) aynı sonucu verir, ama genelde aynı değildir.

**Bölme algoritması.** `[7 4 5 8 3 9]`, $x=6$: 7 > 6 olduğu için 9 ile yer değiştirir, `son` 4 olur; 9 > 6 olduğu için 3 ile yer değiştirir, `son` 3 olur; 3, 4, 5 küçük olduğu için `bas` 3'e çıkar ve döngü biter. Sonuç `3 4 5 8 9 7` (ekrandan, 01:25:00). Her adımda ya `bas` artar ya `son` azalır, bu yüzden en fazla $n$ adım vardır.

**Dizili ters çevirme ve bellek.** Dizili sürümde zaman yine basamak sayısıyla orantılıdır, ama `int` dizisi basamak başına 4 bayt ek bellek ister. Rakamları `char` dizisinde tutmak bunu basamak başına 1 bayta indirir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
