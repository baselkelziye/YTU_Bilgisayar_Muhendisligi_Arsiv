# Ders 7 Çalışma Özeti

## Genel Konular

- Uygulama dersi: döngülerle sayı işlemleri
  - Ders bir uygulama oturumudur. Ekranda "Yapısal Programlaya Giriş Uygulama 1" başlıklı dört problem gösterildi ve hepsi Dev-C++ üzerinde C ile birlikte kodlandı (ekrandan, 00:05:00).
  - Ortak fikir: bir tam sayının basamaklarına `% 10` (kalan) ve `/ 10` (tam sayı bölmesi) ile tek tek ulaşmak; ikilik tabanda aynı işi `% 2` ve `/ 2` yapar.
- Problem 1: [1-20] aralığında tek sayıların çarpımı, çift sayıların toplamı
  - `for(i=1; i<=20; i++)` döngüsü; köşeli parantez uçların dahil olduğunu gösterdiği için `<=` kullanılır.
  - Çarpım değişkeni 1 ile (çarpmanın etkisiz elemanı), toplam değişkeni 0 ile (toplamanın etkisiz elemanı) başlatılır.
  - `i % 2 == 0` ise sayı çifttir; değilse `else` kolu tektir, ikinci bir `if` gerekmez.
  - Sonuçlar: çiftlerin toplamı 110, teklerin çarpımı 654729075 (kod gcc -Wall ile derlenip çalıştırıldı).
- Problem 2: Girilen sayıyı tersine çevirme
  - `ters_sayi = ters_sayi * 10 + sayi % 10;` ve `sayi /= 10;` adımları `while(sayi>0)` döngüsünde tekrarlanır.
  - 125 için ters sayı sırayla 5, 52, 521 olur; sonuç yalnız ekranda değil, bir `int` değişkende sayısal olarak tutulur.
- Problem 3: 100 ile 1000 arasındaki Armstrong sayıları
  - Tanım (ekrandan): N haneli bir sayının basamaklarının N'inci kuvvetlerinin toplamı sayının kendisine eşitse bu sayıya Armstrong sayısı denir. Örnek: $3^3 + 7^3 + 1^3 = 371$.
  - Döngü değişkeni `i` bozulmasın diye değeri `sayi` değişkenine kopyalanır; her `i` için `toplam` sıfırlanır; basamaklar `% 10` ile alınıp küpleri toplanır; en sonda `toplam == i` karşılaştırılır.
  - Algoritma üç basamaklı sayılar için küp aldığından 1000 (dört basamaklı) dışarıda bırakılır: `for(i=100; i<1000; i++)`.
  - Çıktı: 153, 370, 371, 407.
- Problem 4: Onluk tabandaki sayıyı ikilik tabanda ifade etme
  - Sayı sürekli 2'ye bölünür, kalanlar alınır; ilk bulunan kalan en düşük basamaktır.
  - Dizi kullanmadan çözüm: `on_us` (10'un üssü) değişkeni 1 ile başlar, her turda 10 ile çarpılır; `ikilik_sayi += sayi % 2 * on_us;`.
  - Girilen değer `mem` değişkeninde saklanır ve `(%d)10 = (%d)2` biçiminde yazdırılır; örneğin 5 için 101.
  - Öğrencilerin önerdiği diğer yollar: kalanları diziye yazmak; 512'den başlayıp ikinin kuvvetlerine bölerek basamakları bulmak; 10'un kuvveti için `pow` kullanmak.
- Dev-C++ ile hata ayıklama (debug)
  - Satır numarasına tıklanarak kırmızı bir kesme noktası (breakpoint) konur; debug düğmesiyle program bu satırda durur.
  - Değişkenin üzerine fare ile gelince o anki değeri görülür; "Next line" ile satır satır ilerlenir.
  - Hata ayıklama bilgisi için derleyici yapılandırmasının Debug seçilmesi gerekir; aksi halde "debug bilgisi yok, yeniden derlensin mi" uyarısı çıkar.
  - Dizide fare ile yalnız o anki indisteki eleman (`sayilar[i]`) görülür, bütün dizi liste halinde görünmez.
- Kısa konular
  - Bileşik atama: `x *= i` ifadesi `x = x * i` demektir; `+=` de aynı mantıktadır.
  - `if` gövdesi tek satırsa küme parantezi zorunlu değildir; birden fazla satırda zorunludur.
  - `printf` biçimleri: tam sayı için `%d`, ondalıklı sayı için `%f`; yeni satır için `\n`.
  - Tam sayı bölmesi kesirli kısmı atar; ondalıklı sonuç için işlenene `(float)` dönüşümü uygulanabilir.
  - Dizi tanımında köşeli parantez içine eleman sayısı yazılır: `int sayilar[3] = {1,2,3};` için indisler 0, 1, 2'dir.
  - C derlenen bir dildir; kod makine diline (0 ve 1'lerden oluşan dile) çevrilir. Assembly makine diline C'den daha yakındır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Döngü değişkenini `for` başlığının içinde tanımlamamak
  - `for(int i=0; ...)` biçimi bazı derleyicilerde çalışmaz; değişkenler fonksiyonun başında tanımlanmalıdır. Aynı `i` sonraki döngülerde yeniden kullanılabilir.
- Gereksiz değişken kullanmamak, ama kodu okunur tutmak
  - Bir işlem az değişkenle yapılabiliyorsa öyle yapılmalıdır; öte yandan `a`, `b`, `c` gibi anlamsız adlar yerine işi anlatan adlar seçilmelidir.
- Yorum satırı yazmak
  - Kod yalnız yazan kişi için değildir; birkaç gün sonra yazan bile değişkenin ne olduğunu hatırlamayabilir. Bol yorum ve açıklama yazmak iş hayatında da alışkanlık olur.
- Etkisiz eleman ile başlatma
  - Çarpım biriktiren değişken 1, toplam biriktiren değişken 0 ile başlatılır; çarpım 0 ile başlarsa sonuç hep 0 kalır.
- Debug ile mantık hatası bulmak
  - Sözdizimi hatasını derleyici gösterir; değer hatası ise kesme noktası koyup değişkenleri satır satır izleyerek bulunur.

## Kısa Tekrar Notları

- Son basamak: `sayi % 10`; son basamağı atmak: `sayi /= 10`.
- Ters çevirme: `ters = ters * 10 + sayi % 10`.
- Armstrong (3 basamak): basamak küplerinin toplamı sayıya eşit; 100-999 arasında 153, 370, 371, 407.
- İkilik taban: `ikilik += (sayi % 2) * on_us; on_us *= 10; sayi /= 2;`.
- Döngü değişkenini işlem içinde bozacaksan değerini başka bir değişkene kopyala.
- Belirli sayıda tekrar için `for`, bir koşul sağlanana kadar tekrar için `while`.
- `[a, b]` uçlar dahil (`<=`), "a ile b arası" uçlar hariç düşünülebilir.
- Debug: Debug yapılandırması, breakpoint, fare ile değer, Next line.

## Detaylı Açıklamalar

- Problem 1'in kodu ekrandan (00:15:00) alınmıştır. Döngü 1'den 20'ye kadar döner. `i % 2` ifadesi `i`'nin 2'ye bölümünden kalanı verir; kalan 0 ise sayı çifttir ve `cift_toplam += i` çalışır, değilse `tek_carpim *= i` çalışır. Sonuçta $2+4+\dots+20 = 110$ ve $1\cdot3\cdot5\cdots19 = 654729075$ bulunur. Debug gösteriminde kesme noktası `if` satırına konmuş, `i = 1` iken `else` koluna düşüldüğü, `i = 2` iken `cift_toplam`'ın 0'dan 2'ye çıktığı izlenmiştir.

```c
#include <stdio.h>

int main(int argc, char** argv) {
    int i, tek_carpim=1, cift_toplam=0;

    for(i=1; i<=20; i++)
    {
        if(i%2==0)
        {
            cift_toplam += i;
        }
        else
        {
            tek_carpim *= i;
        }
    }

    printf("Ciftlerin toplami = %d \n", cift_toplam);
    printf("Teklerin carpimi = %d \n", tek_carpim);

    return 0;
}
```

- Problem 2'de (ekrandan, 00:30:00) kullanıcıdan `scanf` ile bir sayı alınır. `while(sayi>0)` döngüsünün her turunda önceki ters sayı bir basamak sola kaydırılır (10 ile çarpılır) ve sayının son basamağı sona eklenir; sonra sayıdan son basamak atılır. 125 için: $0\cdot10+5=5$, sayı 12; $5\cdot10+2=52$, sayı 1; $52\cdot10+1=521$, sayı 0 ve döngü biter. `sayi /= 10` satırında sonuç kesirli çıkmaz, çünkü iki tam sayının bölümü tam sayıdır ve kesirli kısım atılır. Kod gcc -Wall ile derlendi; 125 girişiyle 521 çıktı.

```c
#include <stdio.h>

int main(int argc, char** argv) {
    int sayi, ters_sayi=0;
    printf("Lutfen bir sayi giriniz.. \n");
    scanf("%d", &sayi);

    while(sayi>0)
    {
        ters_sayi = ters_sayi * 10 + sayi % 10;
        sayi /= 10;
    }

    printf("Girdiginiz sayinin ters ifadesi = %d \n", ters_sayi);

    return 0;
}
```

- Problem 3'te (ekrandan, 00:50:00) dış `for` döngüsü 100'den 999'a kadar bütün üç basamaklı sayıları dener. Basamaklar sayıyı bölerek bulunduğu için döngü değişkeni `i` doğrudan bölünmez, kopyası `sayi` bölünür; aksi halde `for` döngüsü bozulur. Basamakları ayrı `a`, `b`, `c` değişkenlerinde tutan çözüm de doğrudur, ama bu çözümde tek bir `basamak` değişkeni yeterlidir. Karşılaştırma `sayi` ile değil `i` ile yapılır, çünkü döngü bittiğinde `sayi` 0 olmuştur. Kod derlendi; çıktı `153, 370, 371, 407,` oldu.

```c
#include <stdio.h>

int main(int argc, char** argv) {
    int i, sayi, toplam, basamak;
    printf("100-1000 arasindaki Armstrong sayilar = ");

    for(i=100; i<1000; i++)
    {
        sayi = i;
        toplam = 0;
        while(sayi>0)
        {
            basamak = sayi % 10;
            toplam += basamak * basamak* basamak;
            sayi /= 10;
        }
        if(toplam == i)
        {
            printf("%d, ", toplam);
        }
    }

    return 0;
}
```

- Problem 4'te (ekrandan, 01:25:00) önceki problemlerin tersine yeni basamak sayının sonuna değil başına eklenir. Bu yüzden ters sayıyı 10 ile çarpmak yerine eklenecek kalan, o anki basamak değeri olan `on_us` (1, 10, 100, ...) ile çarpılır. Kod derlendi; 5 için `(5)10 = (101)2`, 15 için `(15)10 = (1111)2` çıktı.

```c
#include <stdio.h>

int main(int argc, char** argv) {
    int sayi, on_us=1, ikilik_sayi=0, mem;
    printf("Bir sayi giriniz.. \n");
    scanf("%d", &sayi);
    mem = sayi;
    while(sayi>0)
    {
        ikilik_sayi += sayi % 2 * on_us;
        on_us *= 10;
        sayi /= 2;
    }

    printf("(%d)10 = (%d)2", mem, ikilik_sayi);
    return 0;
}
```

- Ders sonrası not: Problem 4'teki yöntem ikilik gösterimi onluk bir `int` içinde tuttuğu için büyük girişlerde taşar. Denemede 1023 doğru (`1111111111`) çıktı, 1024 ise taşma yüzünden anlamsız bir değer verdi. Derste bu sınırdan söz edilmedi.
- `main(int argc, char** argv)` parametreleri, Dev-C++'ta proje dosyası açıldığında hazır gelir; işletim sisteminin programa verdiği parametrelerdir. `int main(void)` biçimi de çalışır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
