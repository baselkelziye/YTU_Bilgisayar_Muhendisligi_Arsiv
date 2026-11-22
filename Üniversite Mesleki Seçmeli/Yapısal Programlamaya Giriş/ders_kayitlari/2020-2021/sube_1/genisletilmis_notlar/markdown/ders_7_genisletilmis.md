# Ders 7 Genişletilmiş Notu: Uygulama 1: Döngülerle Sayı İşlemleri ve Hata Ayıklama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulama Dersinin Planı
- 2. Problem 1: Tek Sayıların Çarpımı, Çift Sayıların Toplamı
- 3. Dev-C++ ile Hata Ayıklama (Debug)
- 4. Problem 2: Sayıyı Tersine Çevirme
- 5. Problem 3: Armstrong Sayıları
- 6. İyi Kod Yazma Alışkanlıkları
- 7. Problem 4: Onluk Tabandan İkilik Tabana
- 8. Dersin Sonundaki Sorular
- Örnek Sorular
- Dersin Toparlaması

## 1. Uygulama Dersinin Planı

Bu kayıt dönemin ilk uygulama (laboratuvar) oturumudur. Oturumu dersin asistanı yürüttü. Ekranın solunda dört problemlik bir soru belgesi, sağında Dev-C++ 5.11 düzenleyicisi açıktı (ekrandan, 00:05:00). Belgenin başlığı "Yapısal Programlaya Giriş Uygulama 1" idi. Planda iki iş vardı: soruları birlikte çözmek ve derleyicide kodun nasıl izleneceğini, değişken değerlerinin nasıl takip edileceğini, programın debug modda nasıl çalıştırılacağını göstermek.

Ekrandaki dört problem şunlardır (ekrandan, 00:05:00):

- **Problem 1:** [1-20] arasındaki tek sayıların çarpımını, çift sayıların toplamını hesaplayan programı C dilinde kodlayalım.
- **Problem 2:** Girilen sayıyı tersine çeviren programı C dilinde kodlayalım.
- **Problem 3:** N haneli bir sayının basamaklarının n'inci üstlerinin toplamları, sayının kendisine eşitse, bu sayılara Armstrong sayıları denir. Örneğin 371 sayısı bir Armstrong sayısıdır: $3^3 + 7^3 + 1^3 = 371$. 100 ile 1000 arasındaki tüm Armstrong sayılarını bulan programı C dilinde kodlayalım.
- **Problem 4:** Kullanıcıdan alınan 10 tabanında bir sayıyı 2 tabanlı bir sayı olarak ifade eden programı C dilinde kodlayalım.

Asistan, kodları sonradan belge olarak paylaşacağını, bu yüzden yazarken yetişmeye çalışmak yerine soruyu önce kendileri çözüp çözümü birlikte görmelerinin daha faydalı olacağını söyledi.

## 2. Problem 1: Tek Sayıların Çarpımı, Çift Sayıların Toplamı

### 2.1 Çözüm fikri

Asistan önce çözüm yolunu sordu. Bir öğrencinin önerisi şuydu: biri çarpım, biri toplam için iki değişken tanımlanır; çarpım 1, toplam 0 ile başlatılır; `for` döngüsü 1'den 20'ye kadar döner ve her sayı için tek mi çift mi olduğuna bakılır. Asistan bu fikri onayladı ve ilk değerlerin nedenini vurguladı: çarpmanın etkisiz elemanı 1, toplamanın etkisiz elemanı 0'dır. Çarpım değişkeni 0 ile başlasaydı her çarpma sonucu 0 kalırdı.

Aralık köşeli parantezle, yani $[1, 20]$ biçiminde verildiği için 1 ve 20 de dahildir. Bu yüzden döngü koşulu `i<=20` yazılır.

Tek-çift ayrımı kalan işleciyle yapılır: `i % 2` ifadesi `i`'nin 2'ye bölümünden kalanı verir. Kalan 0 ise sayı çifttir. Bir sayı 2'ye ya bölünür ya bölünmez; bu yüzden ikinci bir `if` kontrolüne gerek yoktur, diğer durum doğrudan `else` koluna bırakılır.

### 2.2 Küme parantezi ve bileşik atama

Asistan `if` gövdesi hakkında bir hatırlatma yaptı: gövdede tek satır varsa küme parantezi zorunlu değildir, konursa da sorun olmaz. Gövdede birden fazla satır varsa bu satırlar mutlaka küme parantezi içine alınmalıdır.

İlk yazımda toplama satırı `cift_toplam = cift_toplam + i;` biçimindeydi (ekrandan, 00:10:00). Asistan bunun kısa gösterimini tanıttı: bir değişken kendisiyle bir işleme sokulup yine kendisine atanıyorsa işleç eşittir işaretinin önüne alınır. Öğrencilere `tek_carpim *= i;` satırının ne anlama geldiği soruldu; cevap, `tek_carpim`'ın `i` ile çarpılıp sonucun yine `tek_carpim`'a yazılmasıdır. Toplama satırı da aynı şekilde `cift_toplam += i;` oldu.

### 2.3 Çıktı ve kodun son hali

Sonuçlar `printf` ile yazdırıldı. Tam sayı `%d`, ondalıklı sayı `%f` ile gösterilir; satır sonu için `\n` konur. Kodun son hali (ekrandan, 00:15:00):

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

Kod `gcc -Wall` ile uyarısız derlendi ve çalıştırıldı. Çıktı:

```text
Ciftlerin toplami = 110
Teklerin carpimi = 654729075
```

Doğrulama: $2+4+\dots+20 = 2(1+2+\dots+10) = 2 \cdot 55 = 110$ ve $1\cdot3\cdot5\cdot7\cdot9\cdot11\cdot13\cdot15\cdot17\cdot19 = 654729075$ (python ile kontrol edildi).

## 3. Dev-C++ ile Hata Ayıklama (Debug)

### 3.1 Kesme noktası ve satır satır ilerleme

Program önce normal biçimde çalıştırıldı, sonra debug modu gösterildi. Debug modda çalıştırmak için araç çubuğundaki tik işaretli düğmeye basılır. Programın durmasını istediğimiz yere bir kesme noktası (breakpoint) konması gerekir. Bunun için satır numarasının üzerine tıklanır; satır kırmızıyla işaretlenir.

Gösterimde kesme noktası `if(i%2==0)` satırına kondu. Program debug modda başlatılınca bu satırda durdu. Bir değişkenin üzerine fare ile gelinince o anki değeri görülür. İlk durakta `i` 1'dir; döngünün ilk turundadır. `cift_toplam` 0'dır, çünkü o kola hiç girilmemiştir. 1 tek olduğu için akış `else` koluna düşer. "Next line" ile ilerleyince `tek_carpim` 1 olur. Devam edilince `i = 2` için kalan 0 çıkar ve `cift_toplam` 0'dan 2'ye çıkar. Böylece değişkenlerin her adımdaki değeri izlenir.

### 3.2 Debug ne işe yarar?

Sözdizimi (syntax) hatası olduğunda derleyici sorunun yerini aşağı yukarı gösterir; büyük projelerde bu da zorlaşır. Asıl zor olan, kod çalışırken bir değişkenin beklenenden farklı bir değer almasıdır. Örneğin tasarlanan algoritmada bir değişkenin 3 olması gerekirken sonuç yanlış çıkıyordur. Böyle durumlarda şüphelenilen satırlara kesme noktası konur ve değerler satır satır izlenerek hatanın kaynağı bulunur. Dersin sonunda bir öğrenci debug mantığının yeniden anlatılmasını istedi; asistan aynı fikri Problem 4'ün koduyla 15 girişi üzerinde tekrar gösterdi: `scanf` satırından sonra `sayi` değişkeninin her yerde 15 olarak görüldüğünü izletti.

### 3.3 Karşılaşılan sorunlar

- **Alttaki pencere görünmüyorsa:** Bazen derleyici çıktısının bulunduğu alt pencere çok küçük kalır. Asistana göre "Float Project Manager" ya da "Float Report Window" seçeneğiyle pencere ayrı açılır, yeniden boyutlandırılıp kapatılınca alttaki bölüm tekrar görünür. <!-- BELİRSİZ: Menü adları altyazıda bozuk; seçeneğin menüdeki yeri karede görünmüyor. -->
- **"Debug bilgisi yok" uyarısı:** Bir öğrenci debug modu açınca "Projenizde debugging bilgisi bulunmamakta, debugging bilgisini aktif hale getirmek ve projenizi yeniden derlemek ister misiniz?" uyarısı aldı, onaylayınca program kapandı. Asistanın derleyicisi zaten Debug yapılandırmasında olduğu için bu uyarı onun ekranında çıkmamıştı. Çözüm, hata ayıklamadan önce araç çubuğundaki derleyici yapılandırması seçicisinden Debug seçeneğini seçmektir. Öğrenci bunu deneyince sorun çözüldü.

## 4. Problem 2: Sayıyı Tersine Çevirme

### 4.1 Problemin anlamı ve çözüm fikri

Kullanıcı 125 girerse çıktı 521 olmalıdır. Bir öğrenci dizi kullanmayı önerdi; asistan bunun da bir yol olduğunu, ama dizi konusunun henüz bilinip bilinmediğinden emin olmadığı için çözümü yalnız bir tam sayı değişkeni üzerinden kurduğunu söyledi.

Başka bir öğrenci şu fikri verdi: sayı sıfırdan büyük olduğu sürece `while` döngüsünde 10'a göre kalanı alınır; bu son basamaktır, ekrana yazdırılır; sonra sayı 10'a bölünerek bir basamak küçültülür. Asistan bunun ekranda doğru görüntüyü vereceğini, ama ters sayıyı bir değişkende sayısal değer olarak tutmak istiyorsak bir adım daha gerektiğini söyledi: her yeni basamak eklenirken o ana kadarki ters sayı 10 ile çarpılır, sonra yeni rakam eklenir. 5 elde edilmişse $5 \cdot 10 + 2 = 52$, sonra $52 \cdot 10 + 1 = 521$ olur. Sonuç yalnız görünüşte değil, değişkende gerçekten 521 sayısıdır.

Döngü olarak `while` seçildi, çünkü burada basamak sayısı bilinmiyor; bir koşul sağlanana kadar (sayı 0 olana kadar) işlem tekrarlanıyor. `ters_sayi` 0 ile başlatıldı, çünkü ilk adımda 10 ile çarpılacak ve 0 olduğu için sonucu etkilemeyecektir.

### 4.2 Kod

Kodun son hali (ekrandan, 00:30:00). Belgenin başındaki yorum satırında `125 -> 521` örneği yazılıdır:

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

Kod `gcc -Wall` ile derlendi; 125 girişiyle `Girdiginiz sayinin ters ifadesi = 521` çıktısı alındı.

### 4.3 125 için adım adım iz

Bir öğrencinin isteği üzerine aynı iz debug modda da gösterildi (ekrandan, 00:30:00: kesme noktası `ters_sayi = ...` satırında, sıradaki satır `sayi /= 10;`).

| Tur | `sayi` (başta) | `sayi % 10` | `ters_sayi` (sonra) | `sayi` (sonra) |
|-----|----------------|-------------|---------------------|----------------|
| 1 | 125 | 5 | $0 \cdot 10 + 5 = 5$ | 12 |
| 2 | 12 | 2 | $5 \cdot 10 + 2 = 52$ | 1 |
| 3 | 1 | 1 | $52 \cdot 10 + 1 = 521$ | 0 |

Üçüncü turdan sonra `sayi` 0 olur, `sayi>0` koşulu yanlışlanır ve döngü biter.

**Soru:** 125 iki kez 10'a bölününce 1 kalıyor; bu 1 sona nasıl ekleniyor? **Cevap:** `sayi` 1 iken 1 > 0 olduğu için döngüye bir kez daha girilir. 52 ile 10 çarpılıp 520 olur; 1'in 10'a bölümünden kalan 1'dir; toplam 521 olur. Sonra 1 / 10 = 0 olur ve döngü biter.

### 4.4 Tam sayı bölmesi

**Soru:** Sayıyı 10'a böldüğümüzde sonuç kesirli (float) olmamalı mı? **Cevap:** Hayır. Bölünen ve sonucun yazıldığı değişken `int` olduğu için bellekte kesirli değer tutulamaz; virgülden sonraki kısım alınmaz. 125 / 10 sonucu 12 olur.

Asistan ek olarak, iki tam sayı bölünüp sonuç `float` bir değişkene yazıldığında bile kesirli kısmın kaybolabildiğini hatırlattı. Böyle bir durumda işlemin başına `(float)` dönüşümü konarak kesirli sonuç elde edilebilir.

> **Ek bilgi (derste anlatılmadı):** C'de iki `int` işlenenin bölümü her zaman tam sayıdır ve kesirli kısım atılır (C99'dan beri sıfıra doğru kesilir); sonucun `float` değişkene atanması bunu değiştirmez, çünkü bölme atamadan önce yapılır. `float x = 7 / 2;` ifadesi 3.0 verir. Kesirli sonuç için işlenenlerden en az biri dönüştürülmelidir: `(float)7 / 2` ifadesi 3.5 verir. `(float)(7 / 2)` ise yine 3.0 verir, çünkü dönüşüm bölmeden sonra yapılır.

## 5. Problem 3: Armstrong Sayıları

### 5.1 Tanım ve çözüm fikri

Tanım ekrandaki belgeden okundu: N haneli bir sayının basamaklarının N'inci kuvvetlerinin toplamı sayının kendisine eşitse bu sayıya Armstrong sayısı denir. 371 için $3^3 + 7^3 + 1^3 = 27 + 343 + 1 = 371$. Bu problemde kullanıcıdan değer alınmaz; sınırlar 100 ve 1000'dir.

Bütün sayılar sırayla deneneceği için belirli sayıda tekrar vardır ve `for` döngüsü kullanılır. Her `i` için üç basamağa tek tek ulaşmak, her basamağın küpünü almak ve küpleri toplamak gerekir. Basamaklara bir önceki problemdeki gibi bölme ile ulaşılır. Bir öğrenci "100'e bölsek yüzler basamağını buluruz" dedi; diğer bir öğrenci her seferinde 10'a göre kalanı alıp sonra 10'a bölmeyi önerdi. Asistan ikinci yolu onayladı: önce `% 10` ile basamak alınır, sonra sayı `/ 10` ile küçültülür.

Önemli bir ayrıntı: basamaklara ulaşmak için sayı bölünerek küçültülür. Bu işlem doğrudan `i` üzerinde yapılırsa `i`'nin değeri kaybolur ve `for` döngüsü bozulur. Bu yüzden her turda `sayi = i;` ile bir kopya alınır ve bölme işlemleri kopya üzerinde yapılır. Ayrıca her sayı için toplam yeniden hesaplanacağı için `toplam = 0;` sıfırlaması döngünün içinde yapılır.

### 5.2 Aralığın sınırları

Asistan önce "100 ile 1000 arası" ifadesini tartıştı. Köşeli parantezle verilen aralıkta uçlar dahildir ve `<=` kullanılır; "arasında" denince uçlar hariç düşünülebilir. Asistan önce iki ucu da dahil etmeyi düşündü, sonra şunu fark etti: algoritma her basamağın küpünü alıyor, yani üç basamaklı sayılar için kurulmuştur. 1000 dört basamaklıdır ve onun için dördüncü kuvvet gerekirdi. Bu yüzden 1000 aralığa alınmadı ve döngü `for(i=100; i<1000; i++)` olarak yazıldı; böylece bütün üç basamaklı sayılar (100-999) denenmiş olur. <!-- BELİRSİZ: Bu tartışmada altyazıda "1001'den", "1999'a kadar" gibi sayılar geçiyor; Whisper bozması olduğu düşünüldü, kesin aralık karedeki koddan alındı. -->

### 5.3 Kod

Kodun son hali (ekrandan, 00:50:00):

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

Küp için kütüphane fonksiyonu da kullanılabileceği söylendi; kısa yol olarak basamak kendisiyle üç kez çarpıldı. `while` bittiğinde karşılaştırma `sayi` ile değil `i` ile yapılır, çünkü `sayi` artık 0'dır; `toplam` ile `i` eşitse sayı Armstrong sayısıdır. Eşitlikte `toplam` ya da `i` yazdırılabilir, ikisi aynıdır. `printf("%d, ", ...)` içinde `\n` olmadığı için bulunan sayılar aynı satırda virgülle ayrılarak yazılır.

Kod `gcc -Wall` ile derlendi. Çıktı:

```text
100-1000 arasindaki Armstrong sayilar = 153, 370, 371, 407,
```

Derste program çalıştırıldığında 153 ve örnekteki 371'in yanında 370 da görüldü. Asistan bir an 370'in doğru olup olmadığını sorguladı; bir öğrenci kendi programında da 370 bulduğunu söyledi. Kontrol: $3^3 + 7^3 + 0^3 = 27 + 343 + 0 = 370$; 1'in küpü 1 olduğundan 371 ile 370 arasındaki fark da tutarlıdır. 407 için $4^3 + 0^3 + 7^3 = 64 + 343 = 407$ (python ile 100-999 aralığında yalnız bu dört sayının sağladığı doğrulandı).

### 5.4 Basamakları ayrı değişkenlerde tutmak

**Soru:** Basamakları `a`, `b`, `c` gibi üç ayrı değişkene alıp `a*a*a + b*b*b + c*c*c == i` biçiminde kontrol etmek sorun olur mu? **Cevap:** Hayır; doğru sonuç veriyorsa farklı bir çözüm de doğrudur. Asistan bu fikri çözüm fikri aşamasında da değerlendirmiş, her basamak için ayrı değişken tanımlamanın bellekte gereksiz yer tutacağını, tek bir `basamak` değişkeniyle bölme yolunun yeterli olduğunu söylemişti.

## 6. İyi Kod Yazma Alışkanlıkları

Armstrong sorusundan sonra asistan, ödev ve laboratuvar kontrollerinde sık görülen hataları anlattı.

> **Hocanın vurgusu:** Döngü değişkeni `for` başlığının içinde (`for(int i=0; ...)`) tanımlanmamalıdır. Bu yazım bazı derleyicilerde çalışmaz; ödevlerde puan kırılmasına yol açar. Değişkenler fonksiyonun başında tanımlanmalıdır.

**Soru:** Döngü değişkeni `for`'un hemen üstünde mi tanımlanmalı, yoksa en tepede mi? Örneğin on tane `for` döngüsü varsa? **Cevap:** En tepede listelemek daha sağlıklıdır. Her döngü için yeni bir değişken tanımlamaya gerek yoktur; aynı `i` sonraki döngülerde tekrar kullanılabilir.

> **Ek bilgi (derste anlatılmadı):** Döngü başlığında değişken tanımlama (`for(int i=0; ...)`) C99 standardıyla gelmiştir. C89/C90 standardına göre derleyen eski derleyiciler bu yazımı reddeder; gcc de `-std=c89` ayarıyla "only allowed in C99 or C11 mode" hatası verir (denendi). Bu yüzden eski standartla uyumlu kalmak isteyen derslerde değişkenler blok başında tanımlanır.

Asistanın diğer uyarıları:

- **Gereksiz değişken kullanmamak:** Bir işlem az değişkenle yapılabiliyorsa öyle yapılmalıdır. Asistan kendi çözümünde okunurluk için fazladan değişken kullanmış olabileceğini de söyledi.
- **Okunur değişken adları:** `a`, `b`, `c` gibi adlar kodu başkası okurken çözüm yolunu anlamayı zorlaştırır. Kod kişisel bir günlük gibi düşünülmemelidir.
- **Yorum satırları:** Programlar büyüdükçe neyin ne olduğunu açıklamak gerekir. On gün sonra kendi ödevine dönen kişi bile bir değişkenin ne olduğunu hatırlamayabilir. Bol yorum yazmak hem çalışma arkadaşlarına hem kişinin kendisine yardımcı olur ve iş hayatında da alışkanlık kazandırır.

Arada bir öğrenci macOS'te Dev-C++ kullanılamadığını söyleyip ne kullanabileceğini sordu; asistan Code::Blocks'u önerdi.

## 7. Problem 4: Onluk Tabandan İkilik Tabana

### 7.1 Öğrencilerin çözüm önerileri

Bu soruda asistan çözümü öğrencilerin söyleyeceğini, kendisinin yalnız yazacağını belirtti. 10 tabanındaki sayı, günlük kullandığımız sayılardır (örneğin 155); bunu 2 tabanında ifade etmek gerekir.

- **Diziyle çözüm:** Bir öğrenci şu yolu önerdi: kullanıcıdan alınan sayının 2'ye göre kalanı (0 ya da 1) alınır ve dizinin ilk elemanına yazılır; sayı 2'ye bölünür; `while` döngüsünde sayı 0 olana kadar aynı işlem sürer. Asistan, ilk bulunan kalanın sayının en küçük basamağı olduğunu, kalanları en sonda tersten okumak gerektiğini hatırlattı ve dizi kullanmadan nasıl yapılabileceğini sordu.
- **İkinin kuvvetleriyle çözüm:** Başka bir öğrenci 512'den başlayan bir değişken tuttuğunu anlattı: girilen sayı bu kuvvete "sığıyorsa" ikilik sonuca 1 eklenir ve kuvvet sayıdan çıkarılır; her turda ikilik sonuç 10 ile genişletilir ve kuvvet 2'ye bölünür (512, 256, ...). Öğrencinin kendisi bu yolu verimsiz bulduğunu söyledi.
- **`pow` ile çözüm:** Bir öğrenci 10'un kuvvetini `pow` fonksiyonu ve bir sayaçla hesapladığını söyledi. Asistan aynı şeyi fonksiyon kullanmadan, bir değişkeni her turda 10 ile çarparak yaptığını, bunun aynı işi gördüğünü belirtti.

Asistan, hafıza sorunu yoksa dizi çözümünün de geçerli olduğunu, bir problemin birden fazla doğru çözümü olabileceğini vurguladı.

### 7.2 Dizisiz çözüm

Sayı 2'ye bölünür ve kalan not alınır; bölme bitince kalanlar sondan başa doğru okunur. Önceki problemlerden fark şudur: orada yeni rakam sayının sonuna (en küçük basamağa) ekleniyordu, bu yüzden var olan sayı 10 ile çarpılıp rakam ekleniyordu. Burada ise her yeni kalan, oluşan ikilik sayının başına (daha büyük bir basamağa) eklenmelidir. Bu yüzden kalanın kendisi, o anki basamak değeriyle çarpılır.

Basamak değerini tutan değişkene `on_us` ("onun üstü") adı verildi; Türkçe karakter kullanılamadığı için ad biraz komik görünebilir. `on_us` 1 ile başlar, çünkü $10^0 = 1$'dir; her turun sonunda 10 ile çarpılarak $10^1 = 10$, $10^2 = 100$, ... olur. Böylece kuvvet ne fonksiyonla ne de ayrı bir sayaçla hesaplanır. İkilik sonucu tutan `ikilik_sayi` 0 ile başlar. Ara aşamada kalan ayrı bir `kalan` değişkeninde tutuldu, sonra doğrudan ifadeye yazıldı. Girilen sayı döngüde 0'a indiği için baştaki değer, çıktıda gösterilmek üzere `mem` ("memory") değişkenine kopyalandı.

Kodun son hali (ekrandan, 01:25:00):

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

Derste 5 girilince `(5)10 = (101)2` çıktı; bir öğrencinin isteğiyle başka bir değer de denendi. Kod `gcc -Wall` ile derlendi ve şu girişlerle çalıştırıldı: 5 → 101, 6 → 110, 11 → 1011, 15 → 1111.

### 7.3 Adım adım iz (girdi 5)

| Tur | `sayi` | `sayi % 2` | `on_us` | `ikilik_sayi` (sonra) |
|-----|--------|------------|---------|------------------------|
| 1 | 5 | 1 | 1 | $0 + 1 \cdot 1 = 1$ |
| 2 | 2 | 0 | 10 | $1 + 0 \cdot 10 = 1$ |
| 3 | 1 | 1 | 100 | $1 + 1 \cdot 100 = 101$ |

Üçüncü turdan sonra `sayi` 0 olur ve döngü biter (ara adım eklendi).

**Soru:** Bir öğrencinin programı en düşük basamaktaki 0'ı yazmıyordu. Neden olabilir? **Cevap:** Asistan, kalanın her adımda 10'un kuvvetiyle çarpılmasının bir adımda atlanmış olabileceğini ya da `on_us`'un 1 yerine 0 ile başlatılmış olabileceğini söyledi. Öğrenci kendi kodunda farklı bir değişkenle 10'un kuvvetini hesapladığını, hatanın oradan kaynaklandığını düşündüğünü söyledi.

**Soru:** 10'un üssünü kullanmamızın nedeni basamakları artırmak mı? İlk kalanı birinci basamağa yazıyoruz, sonra 10 ile, sonra 100 ile çarpıp ikinci, üçüncü basamağa mı yazıyoruz? **Cevap:** Evet. Her seferinde sayıdan bir basamak büyük bir değerle toplamak gerekir. Örneğin o anki sonuç 10 (iki basamaklı) ve yeni kalan 1 ise, bu 1'in başa eklenmesi için 100 ile çarpılıp eklenmesi gerekir.

> **Ders sonrası not:** Bu yöntem ikilik gösterimi onluk bir `int` içinde tuttuğu için büyük girişlerde taşar. Denemede 1023 için doğru sonuç (`1111111111`, 10 basamak) çıktı; 1024 için 11 basamaklı sonuç `int` sınırını (2147483647) aştığından anlamsız bir değer yazıldı. Derste bu sınırdan söz edilmedi; büyük sayılar için kalanları diziye yazan çözüm daha uygundur.

## 8. Dersin Sonundaki Sorular

### 8.1 `main` fonksiyonunun parametreleri

**Soru:** `int main` içinde `int argc` (ve `char** argv`) yazıyor; bunların sebebi ne? Geçen dönem `int main(void)` yazıyorduk. **Cevap:** Asistan kodu proje dosyası olarak açtığı için Dev-C++ bunları hazır getirmiştir; bunlar işletim sisteminin programı çalıştırırken kullandığı parametrelerdir. `int main(void)` biçimiyle çalışıyorsa o da doğrudur.

> **Ek bilgi (derste anlatılmadı):** `argc` programa komut satırından verilen argümanların sayısını, `argv` ise bu argümanları tutan karakter dizisi işaretçilerinin dizisini gösterir; `argv[0]` genellikle programın adıdır. Program komut satırı argümanı kullanmıyorsa `int main(void)` yazmak standarda uygundur.

### 8.2 C derlenen bir dil mi, yorumlanan bir dil mi?

Asistan öğrencilere C'nin derlenen mi yorumlanan mı bir dil olduğunu sordu. Cevap: C derlenen bir dildir; bilgisayarın anlaması için kod makine diline çevrilir. Makine dili 0 ve 1'lerden oluşur. Assembly ise makine diline C'den daha yakın bir dildir.

**Soru:** Assembly öğrenmenin ne faydası olur? **Cevap:** Asistana göre Assembly hafızanın nasıl bir yapı olduğunu daha iyi kavratır: bir sayının kaç bit tuttuğundan, bellekte hangi segmentte tutulduğuna kadar her şeyi programcı hesaplar. Bunu, kitapları hangi rafa koyduğunu zihninde sistemli tutmaya benzetti. Temele indikçe C'deki kavramların nereden geldiği daha iyi oturur; bu yüzden programlama yeteneğini geliştiren bir dil olduğunu söyledi.

### 8.3 Debug modda dizi elemanlarını izlemek

**Soru:** Debug modda dizilerin değerlerini de izleyebilir miyiz? **Cevap:** Asistan bunu birlikte denemeyi önerdi. Önce bir dizi tanımlatıldı: ilk değerleri 1, 2, 3 olan, adı `sayilar` olan bir dizi.

**Soru:** Köşeli paranteze 3 mü yazılır, 4 mü? **Cevap:** Eleman sayısı ne ise o yazılır. 3 yazılırsa indisler 0'dan başlar ve 2'ye kadar gider. Soruyu soran öğrenci başka bir şeyle karıştırdığını söyledi.

Deneme kodu (ekrandan, 01:35:00) her elemanı bir artıran bir döngüdür:

```c
int sayilar[3] = {1,2,3};
for(i = 0; i < 3; i++)
{
    sayilar[i]++;
}
```

İlk derlemede `i` tanımlanmadığı için hata alındı; `i` tanımlanınca kod derlendi. Debug modda fare ile `sayilar[i]` üzerine gelindiğinde o anki indisteki değer görüldü: `i` 0 iken değer 1, artırmadan sonra 2. Ancak fare dizinin adının üzerine getirildiğinde bütün elemanlar liste halinde görünmedi; Dev-C++ yalnız o anki indisteki elemanı gösterdi. Asistan, daha üst seviye dillerin geliştirme ortamlarında bunun görülebildiğini, burada belleği gösteren pencereden bakılabileceğini tahmin ettiğini söyledi. Bu sırada ekranda görünen düşük seviyeli komutları da Assembly sorusuyla ilişkilendirdi.

> **Ek bilgi (derste anlatılmadı):** Yerel değişkenler C'de ilk değer verilmezse belirsiz (çöp) bir değerle başlar. Bu yüzden biriktirme yapılan `toplam`, `ters_sayi`, `ikilik_sayi` gibi değişkenler derslerdeki gibi açıkça 0 ya da 1 ile başlatılmalıdır. Derleyici bu hatayı her zaman yakalamaz: ilk değeri verilmeyen bir toplam değişkeniyle yapılan denemede `gcc -Wall` uyarı vermedi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00): [1-20] arasındaki tek sayıların çarpımını, çift sayıların toplamını hesaplayan programı C dilinde kodlayınız.

> **Çözüm (derste verildi):** `for(i=1; i<=20; i++)` döngüsünde `i%2==0` ise `cift_toplam += i`, değilse `tek_carpim *= i`; ilk değerler `tek_carpim=1`, `cift_toplam=0`. Sonuç: çiftlerin toplamı 110, teklerin çarpımı 654729075 (bkz. Bölüm 2.3).

**Soru 2** (ekrandan, 00:05:00; derste sözlü, 00:18:10): Girilen sayıyı tersine çeviren programı C dilinde kodlayınız. Kullanıcı 125 girerse çıktı ne olmalıdır?

> **Çözüm (derste verildi):** Çıktı 521'dir. `while(sayi>0)` döngüsünde `ters_sayi = ters_sayi * 10 + sayi % 10; sayi /= 10;` (bkz. Bölüm 4).

**Soru 3** (ekrandan, 00:05:00): N haneli bir sayının basamaklarının n'inci üstlerinin toplamı sayının kendisine eşitse bu sayıya Armstrong sayısı denir ($3^3 + 7^3 + 1^3 = 371$). 100 ile 1000 arasındaki tüm Armstrong sayılarını bulan programı C dilinde kodlayınız.

> **Çözüm (derste verildi):** 100-999 arasındaki her `i` için kopya `sayi` üzerinde `% 10` ve `/ 10` ile basamaklar alınır, küpleri toplanır, `toplam == i` ise yazdırılır. Sonuç: 153, 370, 371, 407 (bkz. Bölüm 5).

**Soru 4** (ekrandan, 00:05:00): Kullanıcıdan alınan 10 tabanında bir sayıyı 2 tabanlı bir sayı olarak ifade eden programı C dilinde kodlayınız.

> **Çözüm (derste verildi):** `on_us=1`, `ikilik_sayi=0`; `while(sayi>0)` içinde `ikilik_sayi += sayi % 2 * on_us; on_us *= 10; sayi /= 2;`. 5 için sonuç 101 (bkz. Bölüm 7).

**Soru 5** (derste sözlü, 00:10:05): `tek_carpim *= i;` satırı ne ifade eder?

> **Çözüm (derste verildi):** `tek_carpim` değişkeni `i` ile çarpılır ve sonuç yine `tek_carpim`'a atanır; yani `tek_carpim = tek_carpim * i;` ile aynıdır.

**Soru 6** (derste sözlü, 01:26:07): C derlenen bir dil midir, yorumlanan bir dil midir? Bilgisayarın anlaması için C kodları neye çevrilir?

> **Çözüm (derste verildi):** C derlenen bir dildir; kod makine diline (0 ve 1'lerden oluşan dile) çevrilir.

**Soru 7** (derste sözlü, 01:33:36): İlk değerleri 1, 2, 3 olan `sayilar` adlı bir tam sayı dizisi tanımlarken köşeli paranteze kaç yazılır? İndisler hangi aralıktadır?

> **Çözüm (derste verildi):** Eleman sayısı yazılır: `int sayilar[3] = {1,2,3};`. İndisler 0, 1, 2'dir.

## Dersin Toparlaması

Bu uygulama oturumunda dört problem, ortak bir fikir etrafında çözüldü: bir tam sayının basamaklarına `% 10` ile ulaşmak ve `/ 10` ile sayıyı küçültmek. Problem 1'de kalan işleciyle tek-çift ayrımı ve etkisiz elemanla başlatma, Problem 2'de son basamağı alıp ters sayıyı 10 ile kaydırarak oluşturma, Problem 3'te döngü değişkenini bozmamak için kopya kullanma ve basamak küplerini toplama, Problem 4'te aynı fikrin 2 tabanına uyarlanması ve yeni rakamı başa eklemek için basamak değeriyle (`on_us`) çarpma işlendi. Tam sayı bölmesinin kesirli kısmı atması, bileşik atama işleçleri ve dizi tanımında eleman sayısı da kısa soru-cevaplarla tekrar edildi.

Oturumun ikinci ekseni Dev-C++'ta hata ayıklamaydı: Debug yapılandırması seçmek, kesme noktası koymak, değişken değerlerini fare ile görmek ve satır satır ilerlemek. Asistan bunların yanında iyi kod alışkanlıklarını vurguladı: değişkenleri döngü başlığında değil fonksiyon başında tanımlamak, gereksiz değişkenden kaçınırken anlamlı adlar seçmek ve bol yorum satırı yazmak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
