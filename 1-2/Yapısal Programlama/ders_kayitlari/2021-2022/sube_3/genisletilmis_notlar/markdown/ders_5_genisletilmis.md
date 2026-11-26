# Ders 5 Genişletilmiş Notu: Koşullu Derleme, Kapsam, Değişken Sıfatları ve İşaretçilere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

<!-- BELİRSİZ: Bu dersin videosu bulunmadığı için ekran karesi çıkarılamadı. Not yalnız altyazıdan yazıldı. Slayttaki ve IDE'deki kodlar görülemedi; aşağıdaki kodlar hocanın sözlü anlatımından yeniden kuruldu ve ajan tarafından derlendi, birebir derste yazılan kod değildir. -->

## İçindekiler

- 1. Önceki Dersin Tekrarı: Makrolar
- 2. Koşullu Derleme
- 3. #include Komutunun İki Biçimi
- 4. Kapsam (Scope) Kavramı
- 5. static Yerel Değişkenler
- 6. Kapsam Türleri: Program, Fonksiyon ve Blok
- 7. Ezme (Shadowing)
- 8. Global Değişkenlerden Kaçınmak
- 9. Değişken Sıfatları: extern, register, const, volatile
- 10. İşaretçilere Giriş
- 11. Diziler ve Bellekte Yerleşimleri
- 12. Diziye İşaretçi Üzerinden Erişim
- 13. Sıralama Algoritmaları ve Fonksiyonlara Bölme
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersin Tekrarı: Makrolar

Ders, önceki derste anlatılan makroların kısa bir tekrarıyla başladı. `#define` ile yapılan her tanım derleyici (önişlemci) tarafından, makronun kullanıldığı her yere "kopyala-yapıştır" gibi yerleştirilir. Ortaya çıkan metin neyse kod da ona göre davranır. Bu yüzden önemli olan bu mekanizmayı bilmektir.

Makroların avantajı olarak derleme sırasında getirdikleri kolaylık ve türden bağımsız olmaları sayıldı. Türden bağımsızlık hem avantaj hem dezavantaj olabilir. Önceki derste önek ve sonek artırma (`++i`, `i++`) gibi durumlarda makroların yan etkileri gösterilmişti. Bu birkaç çetrefilli durum dışında makrolar genelde sorun çıkarmaz; ama çetrefilli bir durum çıkınca hatanın kaynağını bulmak zorlaşır.

Bir makro tanımlandıktan sonra `#undef` ile kaldırılıp başka biçimde yeniden tanımlanabilir. Dille birlikte gelen beş hazır makro da tekrar edildi:

- `__LINE__`: kaynak dosyadaki satır numarası.
- `__FILE__`: dosyanın adı.
- `__TIME__`: kodun derlendiği saat.
- `__DATE__`: kodun derlendiği tarih.
- `__STDC__`: derleyicinin ANSI C standardına uyup uymadığı.

## 2. Koşullu Derleme

Koşullu derlemede kullanılan önişlemci komutları `#if`, `#elif`, `#else` ve `#endif`'tir. `#if` bildiğimiz `if` gibi karar verir ve `if - else if - else` zinciri burada da kurulabilir. `#elif`, "else if" anlamındadır. Önişlemci komutlarında süslü parantez kullanılamadığı için `#if` bloğunun nerede bittiği `#endif` yazılarak belirtilir.

Hoca, önişlemci komutlarının kodun en başında olmak zorunda olmadığını da belirtti: makro ve koşullu derleme komutları kodun ortasında, herhangi bir satırda yer alabilir.

### 2.1 Slayttaki örnek

Hoca, "çok anlamlı olmasa da neyin yapılıp yapılamayacağını gösteren" bir örneği şöyle okudu: `X` 1'e eşitse önce `#undef X` ile `X`'in tanımı kaldırılır, sonra `X` 0 olarak yeniden tanımlanır. Değilse ve `X` 2'ye eşitse yine `X` kaldırılır, bu kez 3 olarak tanımlanır. İkisi de değilse (`#else`) `Y` adlı bir makro 4 olarak tanımlanır. Son olarak `#endif` ile koşullu derleme bloğu kapatılır. Yani `Y`'nin 4 olarak tanımlanması ancak `X` ne 1 ne de 2 iken gerçekleşir.

Blokların sınırları şöyledir: `#if X == 1` bölümü `#elif` görülünce biter; `#elif X == 2` bölümü `#else` görülene kadar sürer; `#else` bölümü `#endif`'e kadar sürer.

Aşağıdaki kod bu anlatımdan yeniden kuruldu (slaytın birebir kopyası değildir). `gcc -Wall` ile derlenip çalıştırıldı; `X` 2 iken çıktı `X = 3, Y tanimsiz` oldu.

```c
#include <stdio.h>
#define X 2
#if X == 1
#undef X
#define X 0
#elif X == 2
#undef X
#define X 3
#else
#define Y 4
#endif
int main(void) {
#ifdef Y
    printf("X = %d, Y = %d\n", X, Y);
#else
    printf("X = %d, Y tanimsiz\n", X);
#endif
    return 0;
}
```

> **Hocanın vurgusu:** Bir yerde `#if` açtıysanız mutlaka ve mutlaka `#endif` ile bitirmelisiniz. `#elif` ve `#else` isteğe bağlıdır, ama `#endif` zorunludur.

### 2.2 defined, #ifdef ve #ifndef

Bir makronun tanımlı olup olmadığını denetlemek için `#if defined MAKRO_ADI` yazılır. O adlı bir makro gerçekten tanımlanmışsa, onu izleyen önişlemci komutlarıyla değerlendirmeye devam edilir. `#if defined` yerine kısaca, bitişik yazılan `#ifdef` de kullanılabilir.

Tersi, yani "tanımlı değilse", ünlem işleciyle `#if !defined MAKRO_ADI` diye yazılır. Kısa yazılışı `#ifndef`'tir; buradaki `n` "not" sözcüğünden gelir.

Bu komutların daha uzun adları da vardır ve parantezler isteğe bağlıdır; konulsa da konulmasa da sorun olmaz. Hoca slayttaki iki sütunlu tabloda sol sütundaki her yazılışın sağ sütunda aynı satırdaki karşılığıyla da desteklendiğini söyledi. <!-- BELİRSİZ: Slayttaki iki sütunlu tablonun satırları görülemedi. -->

## 3. #include Komutunun İki Biçimi

`#include` de bir önişlemci komutudur ve dahil edilecek dosyanın nerede aranacağını farklı yorumlayan iki biçimi vardır.

- `#include <dosya.h>`: Dosya adı küçüktür-büyüktür işaretleri arasında yazılırsa derleyici dosyayı, kurulurken işletim sisteminde ayarlanan standart include dizininde arar. Unix benzeri sistemlerde bu dizin `/usr/include`'dur; başka platformlarda ve derleyicilerde başka bir yer olabilir. Hoca, Dev-C++'ın kurulum dizinindeki `include` klasörünü örnek gösterdi.
- `#include "dosya.h"`: Dosya adı tırnak içinde yazılırsa önce işletim sisteminin ve derleyicinin belirlediği yerlere bakılır. Bu yer projenin bulunduğu dizin, kullanıcının hesabındaki özel bir dizin ya da derleyicinin ayarladığı bir yer olabilir. Bunlarda bulunamazsa standart include dizinine bakılır; orada da yoksa "bulunamadı" hatası verilir.

Genelde `.h` uzantılı başlık (header) dosyaları dahil edilir. Bunlarda veri yapısı tanımları, önceden tanımlanmış makrolar, fonksiyon prototipleri ve çeşitli global değişkenler bulunabilir.

**Soru (hocanın kendi sorusu):** Başlık dosyasındaki bir global değişkenle aynı adlı bir değişken tanımlarsak sorun olur mu? **Cevap:** Hocaya göre olmaz; bizim tanımladığımız değişken daha baskın gelir. Hoca bunun ayrıntısına kapsam konusunda gireceğini söyledi.

## 4. Kapsam (Scope) Kavramı

Makrolar tamamlandıktan sonra kapsam konusuna ve değişkenlerin davranışını değiştiren "sıfatlara" geçildi. Hoca bu konunun ardından dinamik bellek ayırmaya yavaş yavaş geçileceğini söyledi.

Kapsam (scope), programlamada teknik bir terimdir. Yapılan herhangi bir tanımın (bir değişken ya da bir fonksiyon) nerede geçerli olduğunu, nerelerden erişilebildiğini belirtir. Ayrıca tanımın ne kadar süre ve nerede saklandığını, nerede kendiliğinden yok edildiğini ya da ilk değerine geri döndüğünü de anlatır.

Slayttaki sıfatlardan `auto` için hoca "bir kelimemiz var ama pek kullanmıyoruz" dedi ve üzerinde durmadı.

## 5. static Yerel Değişkenler

Normalde bir değişkene bir kez ilk değer atanır. Değişkenin geçerli olduğu alan boyunca değeri korunur; o alandan çıkılıp yeniden girildiğinde değişken yeniden ilk değerini alır. Hoca burada "sıfırlanmak" sözcüğünü "yeniden ilk değerin atanması" anlamında kullandığını, 0 değerini kastetmediğini belirtti.

Örnekte `increment` adlı bir fonksiyon vardır. İçinde tanımlanan `c` değişkeninin kapsamı bu fonksiyonla sınırlıdır; `main` içinden bu değişkene erişilemez, erişilmeye çalışılırsa derleme hatası alınır. `increment` içinde `c`'ye ne yapılırsa yapılsın, fonksiyon bir sonraki çağrılışında `c` yeniden ilk değerini alır.

Bir fonksiyon her çağrıldığında bir değişkenin bir önceki çağrıdaki değerini koruması, oradan devam etmesi isteniyorsa değişkenin başına `static` yazılır. Örnekte `k` değişkeni `static`'tir. Fonksiyon içinde `c` ve `k` birer artırılıp ekrana yazdırılır.

`main` fonksiyonu `increment`'i üç kez çağırdığında:

- `c` her çağrıda yeniden ilk değerini alıp bir artırıldığı için her seferinde 2 yazdırılır.
- `k` ilk çağrıda 1'den 2'ye artırılır ve 2 yazdırılır. İkinci çağrıda son değeri olan 2 bellekte saklandığı için 3'e çıkar; üçüncü çağrıda 4 olur.

Hoca kodu Dev-C++'ta yazıp çalıştırdı ve sonuç anlatıldığı gibi çıktı. Aşağıdaki kod anlatımdan yeniden kuruldu; `gcc -Wall` ile derlendi ve `c = 2, k = 2`, `c = 2, k = 3`, `c = 2, k = 4` çıktısını verdi.

```c
#include <stdio.h>

void increment(void) {
    int c = 1;
    static int k = 1;
    c++;
    k++;
    printf("c = %d, k = %d\n", c, k);
}

int main(void) {
    increment();
    increment();
    increment();
    return 0;
}
```

Hoca ardından `main` içinde bu değişkenlere erişmeye çalıştı. `k++` yazıldığında derleyici `k`'nin tanımsız olduğunu söyledi; `k` kapsamın dışındadır (out of scope). `main` içinde ayrıca bir `int c` tanımlansa bile, bu `c` ile `increment` içindeki `c` bellekte tamamen farklı yerleri gösteren farklı değişkenlerdir; sembolik olarak aynı adı taşımaları bir şey değiştirmez.

> **Hocanın vurgusu:** `static` sözcüğünü "sabit" diye çevirince değeri bir kez verilip hiç değişmeyen (constant) bir değişken gibi algılanabiliyor. Böyle düşünmeyin. Buradaki anlamı, değişkenin değerinin fonksiyon tamamlandıktan sonra bile saklanması ve sonraki çağrılarda kaldığı yerden devam etmesidir.

## 6. Kapsam Türleri: Program, Fonksiyon ve Blok

Hoca bir değişkenin nerelerde görülebildiğine göre dört ayrı kapsamdan söz edilebileceğini söyledi: program, dosya, fonksiyon ve blok kapsamı.

### 6.1 Program ve dosya kapsamı (global değişkenler)

En geniş kapsam program kapsamı ya da dosya kapsamıdır. Derste genelde tek `.c` dosyalı programlar yazıldığı için ikisi aynı anlamda kullanılır. Yine de dahil edilen kütüphanelerde tanımlanmış değişkenlere de erişilebildiği için "program kapsamı" denebilir. Bu kapsamdaki değişkenlere global değişkenler denir.

Örnekte fonksiyonların dışında `int g = 9;` tanımlandı. Bu `g`'ye hem `increment` hem `main` içinden erişilebildi ve derleme hatası alınmadı.

Ardından `g`'nin tanımından önce `test` adlı bir fonksiyon yazılıp içinde `g` kullanıldı. Bu kez derleyici `test` fonksiyonu için `g`'nin tanımlı olmadığını söyledi. Bir değişken mutlaka kullanımından önce tanımlanmalıdır. Bu yüzden `test` fonksiyonu `g`'nin tanımından sonraya taşınınca kod hatasız derlendi.

Hoca, program kapsamıyla dosya kapsamı arasında `static` sözcüğünden kaynaklanan küçük bir nüans olduğunu da söyledi: program kapsamında tanımlanan bir değişkenin başına `static` yazılırsa onu "dosya kapsamı" diye adlandırmak teknik olarak daha doğrudur.

### 6.2 Fonksiyon kapsamı ve değer ile aktarma

Fonksiyon kapsamı, bir fonksiyonun içinde tanımlanan değişkenleri ve fonksiyonun parametrelerini kapsar. Hoca bunu yeni bir fonksiyonla gösterdi: bir tamsayı parametre `a` alan ve `a + 1` döndüren bir fonksiyon. `a`, bu fonksiyonun içinde tanımlıdır ve yalnız orada anlam taşır.

Hoca fonksiyona önce `increment` adını verdi; derleyici bunu kabul etmedi, çünkü aynı adlı bir fonksiyon zaten vardı. Hoca Java alışkanlığıyla aynı adlı ama parametre listesi farklı fonksiyonların ayrı fonksiyonlar sayılacağını düşündüğünü, C'nin ise bunu desteklemediğini söyledi. Bu yüzden ad `incrementByOne` olarak değiştirildi.

Hoca bir fonksiyona parametre aktarılırken "değer ile aktarma" ve "adres ile aktarma" ayrımının olduğunu, adres ile aktarmanın işaretçilerden sonra görüleceğini söyledi. Örnek şöyle kuruldu: `main` içinde `int t = 89;` ve bir `u` değişkeni tanımlandı, `u = incrementByOne(t);` yazıldı.

- `incrementByOne` çağrıldığında `t`'nin yalnız değeri `a` parametresine kopyalanır. `t` ve `a` farklı değişkenlerdir: `t` `main`'in, `a` `incrementByOne`'ın kapsamındadır.
- `a` üzerinde yapılan her şey yalnız `a`'yı etkiler, `t`'yi etkilemez. `t`'nin etkilenmesi isteniyorsa işaretçiler ve adresler gerekir; bu aşamada bu yapılamaz.
- Fonksiyon `a + 1`'i döndürür ve bu değer `main`'deki `u`'ya yazılır. Fonksiyon biter bitmez `a` bellekten silinir, erişilemez olur. Fonksiyon yeniden çağrılırsa `a` yeni değerle yeniden ilk değerini alır.

Çalıştırıldığında `t` 89, `u` 90 çıktı. Kod ajan tarafından yeniden kuruldu ve derlenip aynı sonucu verdi:

```c
#include <stdio.h>

int incrementByOne(int a) {
    return a + 1;
}

int main(void) {
    int t = 89, u;
    u = incrementByOne(t);
    printf("t = %d, u = %d\n", t, u);   /* t = 89, u = 90 */
    return 0;
}
```

### 6.3 Blok kapsamı

Kodun herhangi bir yerinde süslü parantezlerle ek bir blok açılabilir. `main` fonksiyonunun bloğu açılan süslü parantezden kapanan süslü paranteze kadar sürer. Bir `for` döngüsünün gövdesi de süslü parantezlerle açılmış bir bloktur. Bunların dışında, istenen bir noktada yalnız bir çift süslü parantez açıp kapatarak yeni bir blok oluşturulabilir.

Hoca `main` içinde böyle yeni bir blok açtı ve içinde `int b1 = 7;` tanımlayıp yazdırdı; derleme hatası alınmadı ve 7 yazdırıldı. Bu blok kapsamıdır: `b1` yalnız bu iç blokta geçerlidir. Blok dışında `b1++` yazıldığında derleyici `b1`'in tanımlanmamış olduğunu söyledi.

Hoca, blok açılmadan fonksiyonun ortasında böyle bir değişken tanımlanırsa da derleme hatası alındığını gösterdi. <!-- BELİRSİZ: Bu denemede tam olarak hangi satırın değiştirildiği ve hata mesajı ekran görülmeden anlaşılamadı. -->

> **Ders sonrası not:** Hoca blok içindeki değişkenlerin "heap memory" (hip) adı verilen alanda yeni açılan bir bölgede tutulduğunu söyledi. Yerel değişkenler ve fonksiyon çağrı çerçeveleri büyük olasılıkla yığın (stack) bellekte tutulur; heap, dinamik bellek ayırma (`malloc` vb.) için kullanılan alandır. Hocanın anlattığı mekanizma, yani fonksiyon çağrıldığında önceki fonksiyonun değişkenlerinin saklanıp yeni değişkenler için yer açılması, stack'in davranışıdır.

> **Ders sonrası not:** C99 standardından beri fonksiyonun ortasında, kullanmadan önce olmak koşuluyla değişken tanımlamak serbesttir. Eski C89 standardında tanımlar bloğun başında olmak zorundaydı. Derste alınan hata büyük olasılıkla eski standarda ya da değişkenin kapsam dışında kullanılmasına bağlıdır.

## 7. Ezme (Shadowing)

Slayttaki örnekte bir fonksiyonun içinde `j` adlı bir değişken tanımlıdır; biraz kod sonra yeni bir blok açılır ve bu blokta yine `j` adlı bir değişken tanımlanır. Aşağıda tanımlanan `j`, yukarıdaki `j`'yi "ezer". Hoca bunun İngilizcede "override" diye geçtiğini, Türkçede "yeniden tanımlanmak" ya da "ezmek" denebileceğini söyledi. Ezme yalnız iç tanımın geçerli olduğu kapsam, yani blok boyunca sürer.

> **Ek bilgi (derste anlatılmadı):** C'de bu duruma İngilizce kaynaklarda genelde "shadowing" (gölgeleme) ya da "name hiding" denir. "Override" sözcüğü daha çok nesneye yönelik dillerde alt sınıfın üst sınıf metodunu yeniden tanımlaması için kullanılır.

Bu durum bir çakışma (conflict) yaratmaz. Hoca bu tür blokların hata ayıklama (debug) kodunda işe yarayabileceğini söyledi: debug kodunun uygulama kodundaki değişkenlere dokunmaması gerekir, yoksa yan etkiler oluşur ve debug kodu uygulamayı bozar. Ama değişkenleri bu biçimde gizlemek ya da yeniden tanımlamak kafa karıştırıcı da olabilir; mekanizmayı bilmek gerekir.

Hoca örneği sadeleştirerek gösterdi: `main` içinde `int t = 89;` tanımlanıp yazdırılır. Sonra yeni bir blok açılır ve içinde `int t = 7;` tanımlanıp yazdırılır. Blok bittikten sonra `t` yeniden yazdırılır. Beklenen ve elde edilen çıktı `89`, `7`, `89` oldu. Ajanın yeniden kurduğu kod da derlenip aynı çıktıyı verdi:

```c
#include <stdio.h>

int main(void) {
    int t = 89;
    printf("%d\n", t);       /* 89 */
    {
        int t = 7;           /* dıştaki t'yi blok boyunca gizler */
        printf("%d\n", t);   /* 7 */
    }
    printf("%d\n", t);       /* 89 */
    return 0;
}
```

Hoca `goto` için de kısaca "kullanmak zaten yasak" dedi ve geçti.

## 8. Global Değişkenlerden Kaçınmak

Aradan sonra hoca slayttaki büyük yazılmış öneriyi vurguladı.

> **Hocanın vurgusu:** Mümkün olduğu kadar global değişkenlerin kullanımından kaçınmalısınız. Fonksiyonlar arasında bilgi paylaşımı global değişkenler üzerinden değil, fonksiyon parametreleri ve fonksiyonların döndürdüğü değerler üzerinden olmalıdır.

Düzgün yapılandırılmış bir yapısal program bunu gerektirir. Farklı kapsamlar, farklı tanımlar, `static` olan ve olmayan değişkenler ve ezme işlemi varken veri iletişimini değişkenler üzerinden kurmak bozulmaya ve yanlışa çok açıktır. Farkında olmadan bir değişken tanımlanır, başka bir değişken ezilir ve o değişken üzerinden aktarılan veri artık aktarılmaz. Ardından hatanın nereden kaynaklandığını bulmak için uzun süre uğraşılır. Her değişken kendi fonksiyonunda tanımlı olmalı ve orada kullanılmalıdır. Aksi halde bir fonksiyonu anlamaya ya da hatasını çözmeye çalışırken fonksiyonun dışında, hatta başka dosyalardaki değişkenlerin yan etkileri ortaya çıkar.

### 8.1 Tanım (definition) ve bildirim

Hoca önceki derslerden hatırlattı: bir fonksiyonu kullanmadan önce yukarıda bir yerde tanıtmak gerekir. Gövde aşağıda yazılacaksa yukarıda yalnız imzası (prototipi) verilir. Tanım (definition), gövdenin kodlandığı yerdir; prototip ise imzanın verildiği yerdir. Fonksiyon kullanılmadan önce yukarıda tam olarak tanımlanırsa ayrıca prototip vermeye gerek kalmaz. <!-- BELİRSİZ: Hocanın prototip için kullandığı terim altyazıda bozuk ("allerjin/allojin"); büyük olasılıkla "declaration" (bildirim) kastedildi. -->

Başka bir dosyada tanımlı bir değişkeni koda katmak için `extern` anahtar sözcüğü kullanılır. Hoca, global değişken kullanmama tavsiyesi nedeniyle bunun üzerinde durmadı.

## 9. Değişken Sıfatları: extern, register, const, volatile

### 9.1 register ve bellek hiyerarşisi

`static` gibi `register` da bir değişkenin farklı işlenmesine yol açan bir sıfattır. Hoca bunu bellek hiyerarşisiyle açıkladı. Mikroişlemcinin çekirdeğinde, aritmetik-mantık ve kayan noktalı hesap birimleriyle aynı silikon üzerinde sınırlı bir bellek alanı, yani yazmaçlar (register) bulunur. Aynı devre üzerinde oldukları için çekirdeğin en hızlı eriştiği bellektir; ama kısıtlıdır ve genelde işlemcinin kendi çalışması için ayrılmıştır. Normal bir programlama diliyle yazmaçlara müdahale edilemez; yalnız assembly ya da doğrudan makine dili yazarken erişilebilir.

Programcının yapabileceği tek şey, bir değişkenin değerinin sürekli bir yazmaçta saklanmasını, değişkenin başına `register` yazarak rica etmektir. Bu ricanın kabul edilip edilmeyeceği ya da ne kadar süre kabul edileceği tamamen programcının kontrolü dışındadır ve hiçbir garanti yoktur, çünkü yazmaç alanı son derece kısıtlı ve bu yüzden pahalıdır.

Yazmaçların altında Level 1, Level 2 ve duruma göre Level 3 önbellek (cache) bulunur. Önbellek de çoğu zaman işlemciyle aynı silikon katmandadır ama yazmaçlarla tamamen aynı devrede değildir; yazmaç kadar hızlı değildir ama RAM'den hızlıdır ve kapasitesi sınırlıdır. Sonra RAM, en altta da sabit disk gelir. Bu hiyerarşide yukarı çıkıldıkça kapasite azalır, performans artar; aşağı inildikçe kapasite artar, performans azalır.

Bir hesaplamada belirli bir değişkene sürekli ve yoğun erişilecekse onu `register` olarak tanımlamak bir performans artışı sağlayabilir. Ama bunun garantisi yoktur: bilgisayarda yalnız sizin programınız çalışmaz, aynı anda birçok süreç çalışır ve her biri belirli zaman dilimlerinde sistem kaynaklarına erişmek ister. İşletim sistemi bu talepleri karşılarken yazmaçta tutulmasını istediğiniz veri yazmaçtan çıkarılabilir ve sonra yeniden yazmaca yükleneceğinin de garantisi yoktur. Bu yüzden `register` idareli kullanılmalıdır.

### 9.2 Sıfatların özeti

- `auto`: biraz belirsiz, derste üzerinde durulmadı.
- `static`: ayrıntılı örneklendi. Değişkenin kapsamından çıkılıp geri dönüldüğünde son değerinden devam etmesini sağlar.
- `extern`: dış dosyada tanımlı değişkenler. Kullanılmayacağı için üzerinde durulmadı.
- `register`: yukarıda anlatıldı.
- `const`: aşağıda örneklendi.
- `volatile`: derleyicinin bazı optimizasyonlarını devre dışı bırakır. Hoca bu ayrıntıya girilmeyeceğini söyledi.

### 9.3 const örneği

Hoca `const` için anlatırken atladığı bir örneği hemen yaptı. `const int c = 11;` tanımlandı ve kodun ilerisinde `c++` ile değer artırılmaya çalışıldı. Derleyici, salt okunur (read-only) bir değişkenin değerinin artırılmaya çalışıldığını, `const` tanımlanan bir değişkenin değerinin değiştirilemeyeceğini bildirdi ve kod derlenmedi. `const` kaldırılırsa değişken normal bir değişken gibi davranır.

Hoca, kullandığı derleyicinin bunu bir uyarı biçiminde gösterdiğini ama kodu derlemediğini söyledi. Ajanın denediği GCC sürümünde aynı kod `error: increment of read-only variable 'c'` hatasıyla derlenmedi.

`const` yazmak, değişkenin değerinin değiştirilmemesi gerektiğini hem kendinize hem de kodu okuyan diğer programcılara gösteren bir işarettir. Hocaya göre bu sıfatlardan özellikle `static`'i bilmek çok yararlıdır; `const` da akılda tutması kolaydır.

## 10. İşaretçilere Giriş

Hoca bundan sonra dizi ve işaretçi konularına girileceğini, işlerin biraz daha zorlaşacağını söyledi. Plan şöyle anlatıldı: önce bellek temelleri, dizilerin ve işaretçilerin nasıl tanımlandığı ve dizilerin bellekte nasıl saklandığı; dizilerin ilk değerlendirilmesi; dizilere işaretçiler üzerinden erişim; ardından string (karakter katarı) işlemleri ve çok boyutlu diziler. C'de ayrı bir string türü yoktur; bir karakter dizisine string denir.

### 10.1 Slayttaki örnek: Statement 1-5

`main` içinde iki `short` tamsayı `i`, `j` ve bir işaretçi `p` tanımlanır. Yıldız (`*`) işaretçi tanımlayan işleçtir. Bellekte iki ayrı değişken olur; `p` üzerinden istenirse `i`, istenirse `j` gösterilip işlem yapılabilir.

- Statement 1: `i = 123;`
- Statement 2: `j = 321;`
- Statement 3: `p = &i;` Artık `p`, `i` değişkeninin adresini gösterir. `p` üzerinden yapılan her işlem aslında `i`'nin bulunduğu bellek adresini etkiler; o adrese `i` üzerinden erişmekle `p` üzerinden erişmek aynı yere erişmektir.
- Statement 4: `j = *p;` Tek başına `p`, gösterdiği bellek adresidir; başına yıldız konunca o adresteki değer anlamına gelir. Böylece `p` üzerinden, dolaylı olarak `j`'ye `i`'nin değeri atanır. Ama `i` ve `j` hâlâ bellekte farklı yerlerdir; şimdi iki ayrı adreste, birbirinden bağımsız olarak 123 saklıdır. Bu noktada `i` ve `j` yazdırılırsa 123 ve 123 çıkar.
- Statement 5: `i += 2; j += 3;` ve yazdırma.

Slayttaki soru "What will happen?" idi. `i` ve `j` Statement 4'ten itibaren aynı değere sahiptir ama farklı yerleri gösteren değişkenlerdir. `i` 2 artırılınca 125, `j` (önceki değeri 123) 3 artırılınca 126 olur. Beklenen ve derste elde edilen çıktı 125 ve 126'dır.

Ajanın yeniden kurduğu kod `gcc -Wall` ile derlendi ve `123 123`, ardından `125 126` yazdırdı:

```c
#include <stdio.h>

int main(void) {
    short i, j, *p;
    i = 123;          /* statement 1 */
    j = 321;          /* statement 2 */
    p = &i;           /* statement 3 */
    j = *p;           /* statement 4 */
    printf("%d %d\n", i, j);
    i += 2;           /* statement 5 */
    j += 3;
    printf("%d %d\n", i, j);
    return 0;
}
```

### 10.2 Bellek şeması

Hoca sonraki slaytlarda aynı örneği bellek gözleriyle gösterdi. Adresler tamamen temsilidir:

```text
Ad   Adres   St.3 sonrası   St.4 sonrası   St.5 sonrası
i    1200    123            123            125
j    1202    321            123            126
p    1204    1200           1200           1200
```

- `i` 1200 adresinde varsayıldı. `short` 2 bayt olduğu için `j`'nin 1202'den başlaması daha gerçekçidir; `p` için de hemen ardından (hocanın varsayımıyla) iki baytlık yer ayrılır ve `p` 1204'tedir. Başka bir değişken olsaydı 1206'dan başlayacaktı.
- Değişkenlerin bu sırayla, peş peşe yerleşeceğinin bir garantisi yoktur; önemli olan `i`, `j` ve `p`'nin farklı yerlerde olduğunu bilmektir.
- İlk tanımdan sonra gözler boştur (belirli bir değer yoktur). `i = 123` ile 1200'e 123, `j = 321` ile 1202'ye 321 yazılır. `p = &i` ile `p`'nin saklandığı göze `i`'nin adresi olan 1200 yazılır.
- Statement 4'te `p` 1204'teki bir işaretçidir ve 1200'ü gösterir. 1200'deki değer (123) bulunup `j`'nin gözüne kopyalanır.
- Statement 5'te 1200'deki 123, 2 artırılıp 125; 1202'deki 123, 3 artırılıp 126 olur. `p`'nin değeri değişmez.

> **Ders sonrası not:** Hoca şemada işaretçi için 2 baytlık yer ayrıldığını varsaydı. Bu temsilidir; işaretçinin boyutu gösterdiği türden bağımsızdır ve büyük olasılıkla platforma bağlıdır (32 bit sistemlerde 4, 64 bit sistemlerde 8 bayt).

## 11. Diziler ve Bellekte Yerleşimleri

### 11.1 Dizi tanımı

Normal dizi tanımı bilinir: örneğin `int daily_temp[365];` tamsayı türünden 365 değer alabilecek, birbirini izleyen bellek alanını ayırır ve bu alanı bu adla bir dizi olarak kullandırır. Köşeli parantez içinde verilen indise göre ilgili gözdeki değer yazılır ya da okunur. <!-- BELİRSİZ: Dizi adının slayttaki tam yazılışı görülemedi; altyazıda "daily temp" olarak geçiyor. -->

> **Hocanın vurgusu:** İndisler sıfırdan başlar. Dizinin ilk elemanı 0 indisli elemandır; 1 indisli eleman dizinin ikinci elemanıdır.

### 11.2 Bellekteki yerleşim örneği

`int ar[5];` tanımı her elemanı bir tamsayı olan beş elemanlı bir dizi ayırır. Örnekte dizinin, onaltılık 1000 adresinden başladığı varsayıldı (adres tamamen temsilidir):

- `ar[0] = 15;` tamsayılar 4 bayt olduğu için 1000-1003 adresleri arasına 15'in ikilik karşılığını yazar.
- `ar[1] = 17;` ikinci elemanın bulunduğu 1004-1007 adreslerine 17 yazar.
- `ar[2]`'ye bir şey atanmadı; tanımsızdır.
- `ar[3] = ar[0] + ar[1];` 15 ile 17'yi toplayıp 32'yi `ar[3]`'ün gözüne yazar.
- `ar[4]` de tanımsızdır.

Tanımsız gözlerde 0 mı yoksa herhangi bir sayı mı olduğu derleyiciye bağlıdır. Bazı derleyiciler dizi tanımıyla birlikte o alanı sıfırlar, bazıları hiç dokunmaz; o zaman bellekte o alanda en son ne yapıldıysa onun izleri (önceki programlardan kalan veriler, "leftovers") görülür. Bu yüzden dizi elemanlarına uygun bir ilk değer vermek her zaman yararlıdır; diziyi yalnız tanımlayıp bırakmamak gerekir.

Hoca bunu derste de gösterdi: dört elemanlı bir dizi ilk değer verilmeden tanımlanıp yazdırıldığında tamamen rastgele değerler çıktı. Hoca, bu sayılar örneğin not ortalamaları olsaydı tamamen anlamsız olacaklarını söyledi.

> **Ek bilgi (derste anlatılmadı):** C standardına göre global ve `static` diziler otomatik olarak sıfırlanır; ilk değer verilmeyen yerel (otomatik) dizilerin değerleri ise belirsizdir. Derste görülen rastgele değerler yerel dizi durumuna uyar.

### 11.3 İlk değer listesiyle tanım

Dizi tanımlanırken elemanlara ilk değer de verilebilir. Bu az elemanlı diziler için uygundur; 50 elemanlık bir diziye değerleri elle yazmak verimli olmaz.

- `int a[5] = {1, 2, 3, 4, 5};` hem beş elemanlık dizi ayırır hem de ilk elemana 1, ..., beşinci elemana 5 yazar.
- Tamsayı türündeki bir dizinin bir elemanına 3.5 gibi ondalıklı bir değer yazılmaya çalışılırsa değer otomatik olarak 3'e çevrilir; hoca slayttaki açıklamanın da bunu söylediğini belirtti.
- `int c[5]` dizisine yalnız üç değer verilmesi durumunda hoca derleme hatası alınabileceğini ya da derleyicinin girilmeyen elemanlara 0 vereceğini söyledi.
- Değerler elle yazılıyorsa eleman sayısını ayrıca yazmaya gerek yoktur. Slayttaki `d` dizisinde karakter elemanları vardır; köşeli parantezde boyut verilmeden süslü parantezde dört eleman yazıldığı için dizi otomatik olarak dört elemanlı olur.

> **Ders sonrası not:** Hoca üç değerli `int c[5]` için derleme hatası da olabileceğini söyledi. C standardında ilk değer listesi eksik kalırsa kalan elemanlar 0 olur, hata verilmez. Ajanın GCC denemesinde de `int c[5] = {1, 2, 3};` hatasız derlendi ve `c[4]` 0 çıktı; `int b[3] = {1, 2, 3.5};` için `b[2]` 3 oldu.

## 12. Diziye İşaretçi Üzerinden Erişim

### 12.1 İşaretçiyi diziye bağlamak

Dizi elemanlarına köşeli parantez ve indisle erişmek, `for` döngüsüyle hepsini dolaşmak bilinir. Asıl konu bu işi işaretçilerle yapmaktır.

Örnekte dört elemanlı bir `short` dizi `ar` tanımlanır. Dizinin türü `short` olduğu için onu gösterecek işaretçinin türü de `short` olmalıdır.

> **Hocanın vurgusu:** İşaretçinin türü, göstereceği değişkenin ya da dizinin türüyle aynı olmalıdır.

İşaretçinin diziyi göstermesi için dizinin ilk elemanının adresi verilir: `p = &ar[0];`. Daha kısa olarak `p = ar;` da yazılabilir; ikisi aynı sonuca çıkar ve hoca kısasını tercih ettiğini söyledi.

Bundan sonra:

- `*p` dizinin ilk elemanıdır.
- `*(p + 1)` 1 indisli elemandır, yani ikinci eleman.
- `*(p + 3)` 3 indisli elemandır.

### 12.2 Yapılabilen ve yapılamayan işlemler

Slaytın sağ tarafında `float ar[5], *p;` tanımı vardı. Aynı satırda tanımlandıkları için dizi de işaretçi de `float`'tur; işaretçinin önüne yıldız konmazsa `p` sıradan bir `float` değişken olur.

- `p = ar;` geçerlidir; işaretçi diziyi gösterir.
- `ar = p;` geçersizdir; bir dizi bir işaretçiyi gösteremez.
- `&p = ar;` geçersizdir. `&p`, `p`'nin bellekte hangi gözde olduğu anlamına gelir; oraya bir dizi yerleştirilemez.
- `ar++` gibi işlemler dizilerle yapılamaz, ama `p++` yapılabilir. `p++` sonrası `p` 1 indisli elemanı gösterir.
- `ar[1] = *(p + 3);` geçerlidir: dizinin 3 indisli elemanının değeri 1 indisli elemana yazılır.

`scanf` ile dizi elemanlarına değer okunurken yalnız dizi adı ve indis yazmak yetmez; başına `&` konmalıdır: `scanf("%d", &ar[i]);`.

**Soru:** Slaytta `p = ar;` için "yukarıdaki atamayla aynı" denmişti ve `ar` dizinin ilk elemanının adresini gösteriyordu. O zaman `&p = ar;` neden geçersiz? Ben bunu dizinin ilk elemanının adresini `p`'nin bellek adresine eşitlemek gibi anladım. **Cevap:** Atama ters yöndedir. Geçerli olan `p = &ar[0]`'dır, burada ise `&p = ar` yazılmıştır. Hoca bunu bir tablo üzerinde çizerek anlattı: `short ar[4]` dizisi 1000, 1002, 1004, 1006 adreslerinde 1, 2, 3, 4 değerlerini tutsun; `p` ise 1008 adresinde olsun. `p = ar;` dendiğinde dizinin ilk elemanının adresi (1000), `p`'nin saklandığı 1008 numaralı gözün içine yazılır. `&p = ar;` ise "1008'e diziyi ata" demektir. Ama 1008 yalnızca o gözün adres numarasıdır, doğrudan yazılabilecek bir yer değildir; gözün içine yazmak için ancak `p` yazılabilir. `&p = ar` kabul edilseydi `p` ile `&p` aynı anlama gelirdi, oysa farklı şeylerdir. `&p` gibi ifadeler "işaretçiyi gösteren işaretçi" konusunda ele alınacak; o zamana kadar `p` ya da `*p` kullanılır, `&p`'ye atama yapılamaz. Soruyu soran öğrenci, 1008'i en tepeye taşıyınca dizinin artık dizi olmaktan çıkacağını fark ettiğini söyledi; hoca bu yorumu doğru buldu.

### 12.3 Kodla gösterim ve işaretçi aritmetiği

Hoca bunu Dev-C++'ta kodladı: `short ar[4]` dizisine 1, 2, 3, 4 atandı, `p = ar;` yapıldı ve `for (i = 0; i < 4; i++)` döngüsünde `printf("%d ", *(p + i));` ile elemanlar yazdırıldı. `i` 0 iken `*(p + 0)`, yani `*p`; `p` 1008'de saklanan 1000 değerini tutar ve yıldız, 1000 adresindeki değeri verir.

Burada bir tür işaretçi aritmetiği yapılmıştır ve normal aritmetikten biraz farklıdır. `p`'nin türü `short` ve `short` 2 bayt olduğu için, `p` 1000'i gösterirken `p + 1` 1002'yi gösterir. Böylece `*p` 1000'deki, `*(p + 1)` 1002'deki değerdir.

> **Hocanın vurgusu:** Bu kolaylık olmasaydı her türün kaç bayt olduğunu akılda tutup `p += 2` ya da `p += 4` gibi adımlar yazmak gerekirdi; bu da program mantığını epey karıştırırdı. İşaretçi aritmetiği türün boyutunu kendisi hesaba katar.

Çalıştırınca 1 2 3 4 yazdırıldı. Döngüde `p`'nin kendisi değil, yalnız `p + i` kullanıldığı için `p` hâlâ ilk elemanı gösterir; bunu göstermek için sona `printf("%d", *p);` eklendi ve 1 yazdırıldı. Yıldız kaldırılıp `p`'nin kendi değeri yazdırıldığında hocanın şemada 1000 diye temsil ettiği gerçek adres görüldü; program yeniden çalıştırıldığında aynı adres çıktı, ama hoca bunun önceden bilinemeyeceğini söyledi. `&p` yazdırıldığında da `p`'nin kendisinin dizinin başlangıç adresinden daha yukarıda bir yerde tutulduğu görüldü; hoca şemadaki yerleşimin yalnız temsili olduğunu yineledi.

Aradan sonra geçersiz işlemler derleyicide denendi:

- `ar = p;` için derleyici "incompatible types in assignment" benzeri bir hata verdi: dizi ile işaretçi birbirine uyumlu türler değildir; işaretçi eşitliğin sol tarafında olabilir, dizi olamaz.
- `&p = ar;` için derleyici eşitliğin sol tarafının böyle olamayacağını söyledi. İşaretçinin adresine (1008) dizi atanamaz; `p`'ye ancak dizinin ilk elemanını gösteren bir değer atanabilir.
- `ar++` için derleyici bu ifadenin artırılamayacağını söyledi.

<!-- BELİRSİZ: Derleyicinin ekranda gösterdiği hata metinleri görülemedi. -->

> **Ek bilgi (derste anlatılmadı):** Ajanın denediği güncel GCC sürümünde bu üç durum sırasıyla `assignment to expression with array type`, `lvalue required as left operand of assignment` ve `lvalue required as increment operand` hatalarını verdi. Hocanın kullandığı derleyicinin mesajları farklı olabilir.

`p++` ise geçerlidir. `p++` yapıldıktan sonra `p` dizinin ikinci elemanını gösterir; bu yüzden döngü dört kez dönerse dizinin dışına taşılır. Önce taşma olmasın diye döngü sınırı 3 yapıldı. İlk denemede sonda `*p` yerine `p` yazıldığı için adres çıktı; düzeltilince çıktı `2 3 4 2` oldu: döngü 2, 3, 4'ü, sondaki `*p` de 2'yi yazdırdı. `p++` işaretçinin değerini değiştirir, gösterdiği yeri bir eleman öteye taşır. Ajanın yeniden kurduğu kod derlenip aynı sonucu verdi:

```c
#include <stdio.h>

int main(void) {
    short ar[4] = {1, 2, 3, 4};
    short *p;
    int i;
    p = ar;                        /* p = &ar[0]; ile aynı */
    for (i = 0; i < 4; i++)
        printf("%d ", *(p + i));   /* 1 2 3 4 */
    printf("\n%d\n", *p);          /* 1 */
    p++;                           /* artık ar[1]'i gösteriyor */
    for (i = 0; i < 3; i++)
        printf("%d ", *(p + i));   /* 2 3 4 */
    printf("\n%d\n", *p);          /* 2 */
    return 0;
}
```

Hoca ardından, normalde yapılmaması gereken bir şeyi bilerek gösterdi: `p++` sonrası döngü sınırı artırılınca işaretçi dizinin sonunun ötesine geçti ve anlamsız değerler okundu (örneğin negatif bir sayı; hoca bunu işaret bitinin 1 olmasıyla açıkladı). Sınır çok büyütülürse programın kesintiye uğrayabileceği de söylendi. Ardından bu değişiklikler geri alındı.

## 13. Sıralama Algoritmaları ve Fonksiyonlara Bölme

Hoca derste bir kabarcık sıralaması (bubble sort) örneğinin, önce fonksiyon kullanmadan, sonra fonksiyonlara bölünerek nasıl derli toplu hale getirildiğini gösterdi; ardından seçmeli sıralamayı (selection sort) yazdı. Kodlar hazır dosyalardan açıldı. <!-- BELİRSİZ: Dosyalardaki kodlar ekranda görülemedi; aşağıdaki açıklama hocanın sözlü anlatımına dayanır. Hoca ilerleyen derslerde işaretçiyle yapılacağını söylediği sıralamayı bu derste işaretçisiz yaptı. -->

### 13.1 Fonksiyonsuz kabarcık sıralaması

Program 8 elemanlı dizilerle çalışır. Eleman sayısı başta bir sabit olarak (`#define` ile) tanımlanmıştır. Hoca bunun mantıklı olduğunu söyledi: kodun içinde 8 yazıldığında bunun dizinin eleman sayısı mı yoksa bir göze yazılan 8 değeri mi olduğu ayırt edilebilir. İleride dinamik bellek yönetimiyle keyfi uzunlukta dizilerle çalışılacak.

Her şey `main` içindedir ve yaklaşık 30 satırlık bir `main` fonksiyonu oluşur. İndis değişkenleri, yer değiştirme (swap) için geçici bir değişken ve 8 elemanlı dizi tanımlanır.

- Bir `for` döngüsünde kullanıcıya "1. tam sayıyı girin" gibi bir mesaj yazdırılır. İnsanlar saymaya 1'den başladığı için "1." denip değer dizinin 0 indisli elemanına yazılır. Okurken `&arr[i]` yazmak unutulmamalıdır; `&` silinirse sorun çıkar.
- Sırasız dizi yazdırılır. Biçim olarak `%5d` kullanıldı: sayılar hizalı görünsün diye her sayıya 5 karakterlik yer verilir. Daha büyük sayılar için `%8d` ya da `%10d` yazılabilir.
- Sıralamada iki döngü vardır: dış döngü 0'dan eleman sayısının iki eksiğine kadar, iç döngü dış döngünün bir fazlasından son elemana kadar gider. `i`'inci eleman `j`'inci elemandan büyükse ikisi yer değiştirir ve her değişiklikte dizinin yeni hali yazdırılır.
- Son olarak sıralı dizi yazdırılır.

Algoritmanın adı, her karşılaştırmayla küçük değerlerin yavaş yavaş yukarı, büyük değerlerin aşağı gitmesinden, gazozdaki kabarcıkların aşağıdan yukarı çıkmasına benzetilmesinden gelir. En basit ve en verimsiz ama akılda tutması çok kolay bir algoritmadır.

> **Ek bilgi (derste anlatılmadı):** Hocanın anlattığı döngü yapısı (`i`'inci elemanı ondan sonraki her elemanla karşılaştırmak) bazı kaynaklarda "exchange sort" diye geçer. Klasik kabarcık sıralaması ise komşu elemanları (`arr[j]` ile `arr[j+1]`) karşılaştırır. İkisi de $O(n^2)$'dir ve `6 5 3 1 8 7 2 4` girdisinde 28 karşılaştırma, 16 yer değiştirme yapar (ajan Python ile denedi).

Hoca programı çalıştırıp rastgele sayılar girdi ve sonucu kontrol etti: çıktıda girilenler dışında sayı olmamalı ve sayılar doğru sırada olmalıdır. Büyük sayının adım adım aşağı çöktüğü, tek basamaklı küçük bir sayının adım adım yukarı çıktığı ara çıktılarda görüldü. Sayılar neredeyse sıralı girildiğinde yer değiştirme sayısı az çıktı.

### 13.2 Fonksiyonlara bölmek

Hoca, kodda tekrarlanan kısımlar görüldükçe bunları odaklanmış birer iş olarak ayrı fonksiyonlara almanın yararlı olduğunu söyledi. Örnekte dizi üç yerde yazdırılıyordu: başta sırasız hali, her değişiklikte ara hali ve sonda sıralı hali. Yazdırma biçimi değiştirilmek istense (örneğin sayıları alt alta yazmak) bu değişiklik üç yerde ayrı ayrı yapılmak zorunda kalınır.

> **Hocanın vurgusu:** Akıllı insan bir işi bir kere yapar. Ayrıca bubble sort'ta bir hata olsaydı, hatayı ararken yazdırma kodları kalabalık oluşturur ve göze batar. İşi fonksiyonlara ayırmak, tek hamlede çözülmesi zor bir işi "böl ve yönet" gibi alt adımlara bölüp sırayla çözmektir.

İkinci programda diziyi yazdırma işi `printArray`, eleman girme işi `enterArray` fonksiyonuna alındı. Eleman girme işi bir kez kullanılsa bile ileride yeniden kullanılabileceği için ayrı fonksiyon yapıldı. Böylece `main` şu adımlara indi: diziyi gir, sırasız diziyi yazdır, sırala (her yer değiştirmede `printArray` çağır), sıralı diziyi yazdır, toplam karşılaştırma sayısını yazdır. Sıralama kısmı çok daha odaklı hale geldi.

Fonksiyonların diziye erişmesi gerekir. Dizi henüz parametre olarak aktarılamadığı için (bu, işaretçiler ilerleyince görülecek) hoca diziyi geçici olarak global tanımladı; döngü değişkenleri ise her fonksiyonda yerel tanımlandı. Girdi `6 5 3 1 8 7 2 4` ile program doğru sıraladı.

Ardından hoca döngü sayaçları `i` ve `j`'yi de global tanımlayıp fonksiyonlardaki yerel tanımlarını sildi. Kod hatasız derlendi, ama çalıştırıldığında dizi sıralanmadı: yalnız 13 karşılaştırma ve 1 yer değiştirme yapıldı. Bir fonksiyon (örneğin `printArray`) çağrıldığında aynı global sayacı kullanarak diğer fonksiyonun sayacını bozdu. Yerel tanımlara geri dönülünce sıralama yeniden doğru çalıştı.

> **Hocanın vurgusu:** Döngü sayaçlarını global tanımlamak yanlıştır. Global değişkenlerden mümkün olduğunca kaçınılmalıdır. Burada dizi yalnızca fonksiyonlar arasında veri aktarabilmek için geçici olarak global yapıldı.

Ajan, anlatılan yapıyı (global dizi, yerel sayaçlar, `enterArray`, `printArray`) yeniden kurdu ve `gcc -Wall` ile derledi; `6 5 3 1 8 7 2 4` girdisiyle `1 2 3 4 5 6 7 8`, 28 karşılaştırma ve 16 yer değiştirme verdi:

```c
#include <stdio.h>
#define N 8

int arr[N];   /* geçici olarak global; sayaçlar yerel */

void enterArray(void) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d. tam sayiyi girin: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArray(void) {
    int i;
    for (i = 0; i < N; i++)
        printf("%5d", arr[i]);
    printf("\n");
}

int main(void) {
    int i, j, tmp, cmp = 0, swp = 0;
    enterArray();
    printf("Siralanmamis dizi:\n");
    printArray();
    for (i = 0; i < N - 1; i++)
        for (j = i + 1; j < N; j++) {
            cmp++;
            if (arr[i] > arr[j]) {
                tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
                swp++;
                printArray();   /* her yer değiştirmede ara hal */
            }
        }
    printf("Siralanmis dizi:\n");
    printArray();
    printf("karsilastirma = %d, yer degistirme = %d\n", cmp, swp);
    return 0;
}
```

### 13.3 Seçmeli sıralama (selection sort)

Seçmeli sıralamada dizinin en küçük elemanı bulunur ve dizinin ilk elemanının yerine yerleştirilir; daha önce ilk gözde olan eleman, en küçüğün bulunduğu göze yazılır (swap). `6 5 3 1 8 7 2 4` için en küçük eleman 1'dir; 1 dizinin 0 indisli gözüne, oradaki 6 ise 1'in eski yerine gider. Sonra ikinci gözden başlayarak aranır; ilk eleman artık yerinde olduğu için bulunan en küçük, dizinin ikinci en küçük elemanıdır ve ikinci gözdeki elemanla yer değiştirir. İşlem böyle sürer.

Program fonksiyonlu yazıldı. `enterArray` ve `printArray` aynen yeniden kullanıldı. En küçük elemanı bulmak için `findMinIndex` fonksiyonu yazıldı. Hoca fonksiyonun değeri değil indisi döndürdüğünü vurguladı: yer değiştirme yapabilmek için en küçük elemanın hangi indiste olduğunu bilmek gerekir. Sonra `i`'inci göz ile bulunan indisteki göz yer değiştirir. Program `8 2 4 7 5 3 6 1` girdisiyle `1 2 3 4 5 6 7 8` sonucunu verdi.

### 13.4 Karmaşıklık karşılaştırması

Kabarcık sıralamasında iki iç içe `for` döngüsü vardır. Biri 0'dan $n-1$'e, diğeri $i+1$'den $n$'e gider; her biri ortalama olarak yaklaşık $n$ kadar döner. Çarpınca $n^2$ cinsinden bir sayı çıkar: başında $1/2$ gibi bir katsayı ya da eksi birkaç terim olabilir, ama en büyük üslü terim $n^2$ olduğu için kabarcık sıralamasının karmaşıklığı $O(n^2)$'dir.

Seçmeli sıralamada ilk bakışta tek bir `for` döngüsü ($n-1$ kez) varmış gibi görünür. Ama her adımda çağrılan `findMinIndex` de kendi içinde bir `for` döngüsü içerir; yani yine iç içe iki döngü vardır ve bu algoritma da $O(n^2)$'dir. Seçmeli sıralama belki daha az yer değiştirme yapar.

`6 5 3 1 8 7 2 4` girdisinde kabarcık sıralaması 16, seçmeli sıralama 6 yer değiştirme yaptı; karşılaştırma sayısı ikisinde de 28 oldu. 8 eleman için $8 \cdot 8 = 64$ kadar değil, $8 \cdot 7 / 2 = 28$ kadardır. Ajanın Python ve C denemeleri bu üç sayıyı doğruladı. Ajanın denemesinde seçmeli sıralamada 6 sonucu, yer değiştirme yalnız en küçük eleman zaten yerinde değilse yapıldığında çıktı.

> **Ders sonrası not:** Hoca 28'i "yaklaşık 2/3 $n^2$" ve "yarım $n^2$'nin yarısı" gibi ifadelerle tarif etti, ayrıca eleman sayısı artınca sayının "üstel olarak" artacağını söyledi. Doğrusu: karşılaştırma sayısı $n(n-1)/2$'dir ($n = 8$ için $28 \approx 0{,}44\, n^2$, yani yaklaşık yarım $n^2$) ve eleman sayısının karesiyle orantılı, yani polinom olarak (karesel) artar; üstel artış değildir.

Hoca daha verimli sıralama algoritmalarının bulunduğunu ama bunların bu dersin değil, Veri Yapıları ve Algoritmalar dersinin konusu olduğunu söyledi.

Son olarak global dizi yerine diziyi fonksiyon parametresi olarak aktarmanın mümkün olduğu, bunun nasıl yapılacağının ilerde görüleceği söylendi. Dizilerin eleman sayısı normalde sabittir; dinamik bellek yönetimi öğrenilince istenen keyfi uzunlukta dizilerle çalışılabilecek.

## Örnek Sorular

**Soru 1** (derste sözlü, slayttaki "What will happen?" sorusu, 01:21:07): Aşağıdaki kodda Statement 4 ve Statement 5'ten sonra ekrana ne yazılır?

```c
short i, j, *p;
i = 123;      /* statement 1 */
j = 321;      /* statement 2 */
p = &i;       /* statement 3 */
j = *p;       /* statement 4: i ve j yazdırılır */
i += 2;       /* statement 5 */
j += 3;       /* i ve j yazdırılır */
```

<!-- BELİRSİZ: Slayttaki kodun birebir hali görülemedi; kod sözlü anlatımdan kuruldu. -->

> **Çözüm (derste verildi):** Statement 4'te `j`'ye `p`'nin gösterdiği yerdeki değer, yani `i`'nin değeri kopyalanır: `123 123`. `i` ve `j` farklı bellek gözleri olduğu için Statement 5'te bağımsız değişirler: `i = 125`, `j = 126`. Ajanın derlediği kod da `123 123` ve `125 126` yazdırdı.

**Soru 2** (derste sözlü, 00:14:29): Koşullu derleme örneğinde `X` 1'e eşitse `X` 0 olarak, 2'ye eşitse 3 olarak yeniden tanımlanıyor; aksi halde `Y` 4 olarak tanımlanıyor. `Y` hangi durumda tanımlanır?

> **Çözüm (derste verildi):** Yalnız `X` ne 1 ne de 2 ise (`#else` dalı). `X` 2 iken ajanın denemesinde `X` 3 oldu ve `Y` tanımsız kaldı.

**Soru 3** (derste sözlü, 00:25:46): `increment` fonksiyonunda normal bir `c` ve `static` bir `k` değişkeni var (ikisi de 1'den başlayıp her çağrıda bir artırılıyor ve yazdırılıyor). Fonksiyon üç kez çağrılırsa ne yazdırılır?

> **Çözüm (derste verildi):** `c` her çağrıda yeniden ilk değerini aldığı için hep 2; `k` son değerini koruduğu için 2, 3, 4.

**Soru 4** (derste sözlü, bir öğrencinin sorusu, 01:42:49): `float ar[5], *p;` için `p = ar;` geçerliyken `&p = ar;` neden geçersizdir?

> **Çözüm (derste verildi):** `&p`, `p`'nin bellekte saklandığı gözün adresidir (örnekte 1008); bu bir adres numarasıdır, içine bir şey yazılabilecek bir değişken değildir. Göze yazmak için `p` kullanılır: `p = ar;` dizinin ilk elemanının adresini `p`'nin gözüne yazar. Ayrıntı için 12.2'deki soru-cevaba bakın.

**Soru 5** (derste sözlü, 02:38:50): 8 elemanlı `6 5 3 1 8 7 2 4` dizisi kabarcık sıralaması ve seçmeli sıralamayla sıralanırsa kaçar karşılaştırma ve yer değiştirme yapılır?

> **Çözüm (derste verildi):** İkisinde de $8 \cdot 7 / 2 = 28$ karşılaştırma; kabarcık sıralamasında 16, seçmeli sıralamada 6 yer değiştirme. Ajan Python ve C ile doğruladı.

## Dersin Toparlaması

Bu derste önişlemci konusu koşullu derleme (`#if`, `#elif`, `#else`, `#endif`, `#ifdef`, `#ifndef`) ve `#include`'un iki biçimiyle tamamlandı. Ardından kapsam kavramı işlendi: program/dosya, fonksiyon ve blok kapsamları, `static` yerel değişkenlerin çağrılar arasında değerini koruması, değer ile aktarma ve iç bloktaki aynı adlı değişkenin dıştakini gizlemesi örneklerle gösterildi. Global değişkenlerin veri aktarımında neden tehlikeli olduğu hem anlatıldı hem de sıralama örneğinde global döngü sayaçlarının programı bozmasıyla gösterildi. `register`, `const`, `extern` ve `volatile` sıfatları ve bellek hiyerarşisi kısaca ele alındı.

Dersin ikinci yarısında işaretçilere ve dizilere giriş yapıldı: `&` ile adres alma, `*` ile adresteki değere erişme, dizilerin bellekte ardışık yerleşimi, `p = ar` ile işaretçiyi diziye bağlama, `*(p + i)` ile işaretçi aritmetiği ve işaretçiyle dizi arasında yapılabilen ve yapılamayan atamalar. Son olarak kabarcık ve seçmeli sıralama, kodu fonksiyonlara bölmenin yararını göstermek için kullanıldı ve ikisinin de $O(n^2)$ olduğu anlatıldı. Sonraki derste string (karakter dizisi) konularına geçileceği, dizilerin fonksiyonlara parametre olarak aktarılmasının ve dinamik bellek yönetiminin ilerleyen derslerde görüleceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
