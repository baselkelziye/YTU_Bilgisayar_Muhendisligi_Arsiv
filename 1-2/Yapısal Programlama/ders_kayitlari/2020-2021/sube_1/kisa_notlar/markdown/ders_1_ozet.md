# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı ve konu sırası
  - Ders, yapısal programlamanın daha ileri kavramlarını C dili üzerinden anlatır. Giriş dersinde öğrenilenler kısaca hatırlatıldıktan sonra C'nin zorlayıcı konularına geçilir.
  - Ekrandaki ders içeriği (ekrandan, 00:20:00): hatırlatma (veri tipleri, bitsel işlemler, kontrol deyimleri, döngüler, diziler); işaretçiler (işaretçi aritmetiği, diziler ve işaretçiler, işaretçi dizileri, karakter dizileri, işaretçilerin işaretçisi); dinamik bellek yönetimi ve fonksiyonlar, fonksiyon işaretçileri, özyineleme; yerel ve global değişkenler, depolayıcı sınıflar, yapılar (struct), birlikler (union); dosya işlemleri; C önişlemcileri ve makrolar; statik ve dinamik kütüphaneler.
  - Kaynak kitap (ekrandan, 00:20:00): Darnell P. A. ve Margolis P. E., *C: A Software Engineering Approach*, 3. baskı, Springer-Verlag, 1996. Hoca kitabın alınmasının gerekmediğini, aynı konuları anlatan herhangi bir C kitabının yeteceğini söyledi.
  - Statik ve dinamik kütüphane konusuna zaman kalmayabileceği belirtildi. Konular birbirine bağlı olduğu için yer yer geri dönüş yapılacak.
- Program geliştirme süreci: derleme ve bağlama
  - Derleyici kaynak kodu (`.c`) makine koduna çevirir. Girdisi kaynak kod, çıktısı nesne koddur (object code, `.o`). Her kaynak dosyadan bir nesne dosyası çıkar (ekrandan, 00:35:00).
  - Bağlayıcı (linker) ayrı nesne dosyalarını tek bir dosyada birleştirir. Gerekirse çalışma zamanı kitaplığındaki (runtime library) fonksiyonları da ekler. Sonuç çalıştırılabilir koddur. Bağlama genelde otomatik yapılır.
- Çalışma zamanı kitaplığı ve başlık dosyaları
  - C'nin çekirdeği küçüktür. Birçok iş büyük bir çalışma zamanı kitaplığına bırakılır. Kitaplık nesne dosyalarından oluşur ve G/Ç, bellek yönetimi, matematik, karakter dizisi işlemleri gibi gruplara ayrılır (ekrandan, 00:40:00).
  - Her grubun bir başlık dosyası (header file, `.h`) vardır. Başlık dosyasında fonksiyonların imzaları bulunur. Örneğin `printf()` için `#include <stdio.h>` gerekir.
  - `stdio.h` adı "standard input output" kısaltmasıdır. Hoca bu kısaltmaların DOS'un 8+3 karakterlik dosya adı sınırından kaldığını anlattı.
  - Kitaplıklar işletim sistemine, hatta işlemcinin ayrıntılarına bağlıdır. C'nin farklı standartları farklı sistemlerde farklı davranabilir. Bu yüzden C'nin taşınabilirliği sınırlıdır, ama gömülü ve kaynakları kısıtlı sistemlerde verimli kod yazmayı sağlar.
- Değişkenler, sabitler ve bellek
  - Değişken kullanılmadan önce türüyle tanımlanır (`int j;`). Atama `=` ile yapılır.
  - Sabit bir kez değer alır ve değişmez. Değişkene türünün boyutu kadar bellek ayrılır. Bellek, adresi 0'dan başlayan ardışık kutucuklar olarak düşünülür.
  - Programcı değişkenin hangi adrese yerleşeceğini seçemez, ama adresini öğrenebilir (işaretçi). Bu konu ileriki haftalarda işlenecek.
- İsimlendirme kuralları (ekrandan, 00:45:00)
  - Değişken, sabit, fonksiyon ve programdaki bir konum (etiket) isimlendirilebilir.
  - İsimde harf, rakam ve alt çizgi (`_`) bulunabilir, ama isim harf ya da alt çizgiyle başlamalıdır. `j` ve `c5` geçerli, `5j` geçersizdir. `$`, `#`, `%`, `*`, `@` ile başlanamaz.
  - C büyük-küçük harfe duyarlıdır: `VaR`, `var`, `VAR` üç ayrı isimdir.
  - İsim, ayrılmış anahtar kelimelerden biri olamaz. Türkçe karakter isimlerde kullanılmaz.
- Ayrılmış anahtar kelimeler (ekrandan, 00:50:00)
  - `auto`, `break`, `case`, `char`, `const`, `continue`, `default`, `do`, `double`, `else`, `enum`, `extern`, `float`, `for`, `goto`, `if`, `int`, `long`, `register`, `return`, `short`, `signed`, `sizeof`, `static`, `struct`, `switch`, `typedef`, `union`, `unsigned`, `void`, `volatile`, `while`.
  - Hoca listedeki kelimelerin çoğunu tek tek açıkladı (ayrıntı aşağıda).
- İfadeler ve atama
  - Bir C ifadesi işleçlerin, sayıların ve isimlerin birleşiminden oluşur: `5` sabit, `j` değişken, `5 + j` toplama (iki işlenen: sabit ve değişken), `f()` fonksiyon çağrısı. Fonksiyon parametre almasa bile parantez gerekir; değişkenden ayrılması böyle olur.
  - Atamada sağ taraf (rvalue) hesaplanır, sol tarafın (lvalue) gösterdiği bellek adresine yazılır. Sol taraf mutlaka bir bellek adresine karşılık gelmelidir (değişken ya da işaretçi).
- Yorumlar (ekrandan, 01:15:00)
  - `/*` ile `*/` arasındaki her şey yorumdur, derleyici yok sayar. Yorumlar insan okuyucu içindir.
  - İç içe yorum desteklenmez.
  - Fonksiyon başlığına ve koddaki değişikliklere yorum yazılır. Slayttaki örnek başlık: fonksiyon adı, yazar, ilk kodlama tarihi, parametreler, dönüş değeri.
- Fonksiyonlar
  - Söz dizimi: fonksiyon türü, fonksiyon adı, `(`, argümanlar, `)`, `{`, tanımlar, C deyimleri, `}` (ekrandan, 01:20:00).
  - Fonksiyon türü, döndürülen değerin türüdür. Argümanlar tür ve adla verilir. Blok içinde tanımlanan değişkenin ömrü fonksiyon bitene kadardır.
  - Argümanlar çağıran fonksiyondan çağrılana aktarılan verilerdir. Hoca işaretçi kullanılmazsa aktarımın tek yönlü, kullanılırsa çift yönlü olduğunu ileriki haftalar için not düştü.
  - Fonksiyon yazmanın yararları: modüler yazılım, başka programlarda yeniden kullanım, hata düzeltme ya da değişiklik gerektiğinde kodun tek yerde düzeltilmesi (ekrandan, 01:25:00).
  - Fonksiyon kullanılmadan önce tanımlanmalıdır: ya kaynak dosyada kullanıldığı yerden yukarıda yazılır ya da önce imzası (allusion) verilir. İmzada parametre adları gerekmez, türleri yeterlidir.
- Kaynak kodun biçimlendirilmesi (ekrandan, 01:30:00)
  - Derleyici biçime bakmaz. Biçim, kodu okuyacak insanlar içindir.
  - Her `{` sonrasında satırlar bir sekme içeriden yazılır. Süslü parantezin aynı satırda mı alt satırda mı açılacağı kişisel ya da ekip tercihidir.
- `main()` fonksiyonu ve `exit()` (ekrandan, 01:35:00)
  - Programın çalışmaya başladığı noktadır.
  - `exit()` programı bitirip denetimi işletim sistemine verir. `exit(0)` normal bitişi, sıfırdan farklı değer hatalı bitişi gösterir. `main` içinde `exit()` çağırmak `return` ile aynıdır.
- `printf()` ve `scanf()` (ekrandan, 01:40:00)
  - İkisi de `stdio.h` içindedir. İlk argüman biçim dizgisidir (format string); metin ve biçim belirteçleri (`%d` gibi) içerebilir.
  - `printf()` istenen sayıda argüman alır; her biçim belirteci sıradaki argümanla eşleşir.
  - `scanf()`, `printf()`'in aynadaki görüntüsüdür: klavyeden okur. Temel fark, veri argümanlarının lvalue olmasıdır; bu yüzden değişkenin adresi `&` ile verilir. Değişken zaten işaretçiyse `&` yazılmaz.
  - `\n` gibi ters bölü ile başlayan karakterler kaçış dizileridir (`\n` yeni satır, `\t` sekme).
- Önişlemci (ekrandan, 01:45:00 ve 01:50:00)
  - Önişlemci derleme sırasında kendiliğinden çalışır. Yönergeler `#` ile başlar, `#` satırdaki ilk boşluk olmayan karakter olmalıdır. Yönerge noktalı virgülle değil, satır sonuyla biter.
  - Makro işleme, koşullu derleme (örneğin hata ayıklama kodunu yalnız geliştirme derlemesine katmak) ve hazır makrolarla hata ayıklama yapabilir. Koşullu derlemeye derste girilmeyecek.
  - `#define NOTHING 0` bir isimle sabit eşleştirir. Sabitler büyük harfle yazılır. Yararı: anlamsız bir sayıya açıklayıcı ad verir ve değişikliği kolaylaştırır. Sabit, değişken gibi kullanılmamalıdır (`NOTHING = j + 5` yanlıştır).
  - `#include <...>` derleyicinin bildiği sistem dizininde, `#include "..."` önce kaynak dosyanın bulunduğu dizinde arar. Ayrıntılar derleyiciye göre değişir.
- İlk program: Hello World (ekrandan, 01:55:00)
  - Slayttaki program aşağıdadır. `gcc -Wall` ile derlendi ve çalıştırıldı, çıktı `Hello World...` oldu.

    ```c
    #include <stdio.h>

    int main(void) {
        printf("Hello World...\n");
        return 0;
    }
    ```

  - Hoca programı Dev-C++ 4 ile konsol uygulaması olarak derleyip çalıştırdı (ekrandan, 02:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- `goto` kullanılmaz
  - Etiket tanımlanabilir, ama etiketin tek amacı `goto` ile oraya atlamaktır. `goto` yapısal programlamanın düzenini bozar, bu derste yasaktır.
- İşaretçiler dersin en önemli konusudur
  - Hoca öğrenciyken bu konuyu zor kavradığını, bir kez kavrandıktan sonra rahat kullanıldığını söyledi. İşaretçiyle bir bellek gözünün hem içeriği hem adresi kullanılabilir; fonksiyonlara bile işaretçi tanımlanabilir.
- Kısa ve odaklanmış fonksiyonlar
  - Fonksiyon anlaşılmayı zorlaştıracak kadar uzun ve karmaşık olmamalıdır. Hocanın göz kararı: 30 satır fazla, 10 satır civarı makul; ama uzunluk dile ve problem alanına bağlıdır.
  - 2-3 komutluk işler için fonksiyon yerine makro daha uygun olabilir, çünkü her fonksiyon çağrısının bir ek yükü vardır.
  - İnsan aynı anda yaklaşık 7±2 parçayı aklında tutabilir. Uzun kodu alt fonksiyonlara bölmek anlamayı kolaylaştırır.
- Kopyala-yapıştır yerine fonksiyon
  - Aynı kod birçok yere yapıştırılırsa, bir hata bulunduğunda hepsinin tek tek bulunup düzeltilmesi gerekir.
- Okunabilirlik
  - Girintileme, fonksiyon başlığı yorumları ve anlamlı isimler, kodu yazan kişi için bile önemlidir. Hoca öğrencilerden geçen yılki kendi ödev kodlarına bakıp anlamaya çalışmalarını istedi.
  - Fonksiyon adlarında kısaltma kullanılmaz; ad uzun olabilir, yeter ki anlaşılır olsun.
- Slayttan kopyalanan çift tırnak
  - Slayttan kopyalanan kodda tipografik tırnaklar (“ ”) bulunur. C düz çift tırnak (`"`) ister; kopyalanan kodda tırnaklar elle düzeltilmelidir.
- Sabitler için `#define`
  - Sihirli sayılar yerine adlandırılmış sabit kullanmak hem anlamı açıklar hem de sistem değişince tek satırı değiştirmeyi sağlar.

## Kısa Tekrar Notları

- `.c` kaynak → derleyici → `.o` nesne → bağlayıcı (+ çalışma zamanı kitaplığı) → çalıştırılabilir kod.
- Başlık dosyası (`.h`) fonksiyon imzalarını taşır; `printf` için `#include <stdio.h>`.
- İsim: harf/rakam/`_`; harf ya da `_` ile başlar; büyük-küçük harf duyarlı; anahtar kelime olamaz.
- Atama: sağ taraf (rvalue) hesaplanır, sol tarafın (lvalue) adresine yazılır.
- Yorum `/* ... */`; iç içe yorum yok.
- Fonksiyon kullanılmadan önce tanımlanır ya da imzası (allusion/prototip) verilir.
- `exit(0)` normal bitiş; `main` içinde `exit()` = `return`.
- `scanf("%d", &num);` adres ister; `printf("num : %d\n", num);` değer ister.
- Önişlemci yönergesi `#` ile başlar, noktalı virgül almaz.
- `#define AD değer`; sabitler büyük harfle.
- `<...>` sistem dizini, `"..."` kaynak dosyanın dizini.
- `goto` kullanılmaz.

## Detaylı Açıklamalar

- **Derleme ve bağlama.** C derlenen bir dildir. Her kaynak dosya ayrı derlenir ve bir nesne dosyası üretilir. Bağlayıcı bu nesne dosyalarını ve kullanılan kitaplık fonksiyonlarının makine kodunu birleştirip çalıştırılabilir dosyayı üretir. `#include` ile eklenen başlık dosyası yalnızca fonksiyonların imzalarını verir. Bu sayede derleyici, `printf` gibi bir fonksiyonu gördüğünde hata vermez; fonksiyonun asıl kodu bağlama aşamasında eklenir. Hoca IDE olarak Dev-C++ 4 kullanacağını, örnekleri derste proje oluşturup çalıştırarak ve değiştirerek göstereceğini söyledi. Kimi durumlarda komut satırı da kullanılacak.
  - > **Ders sonrası not:** Hoca, `#include <...>` ile verilen dosya bulunamazsa "linker hatası" alınacağını söyledi. Başlık dosyası bulunamazsa hata büyük olasılıkla önişleme/derleme aşamasında verilir; linker hatası, imzası bilinen bir fonksiyonun kodu kitaplıkta bulunamadığında görülür.
- **Anahtar kelimelerin anlamları (derste anlatıldığı kadarıyla).** `break` en içteki döngüden (ya da `switch`'ten) çıkar; `continue` döngünün sıradaki adımına geçer. `switch`/`case` bir değişkenin değerine göre dallanır; `default` hiçbir `case` tutmadığında çalışan kısımdır (bir öğrenci hatırlattı). `char` karakter, `double` ve `float` ondalıklı türlerdir; `const` sabit tanımlar. `enum` bir değişkenin yalnızca belirli değerleri almasını sağlar (hocanın örneği: giysi bedeni small, medium, large, x-large). `extern`, kullanılan değişkenin ya da fonksiyonun başka bir kaynak dosyada tanımlı olduğunu belirtir. `long` iki kat bellek ayırır (int 2 bayt ise long 4 bayt, int 4 bayt ise long 8 bayt; bu sisteme ve standarda bağlıdır). `short` boyutu yarıya indirir. `register`, değişkenin işlemcinin içindeki en hızlı ama en dar bellek olan yazmaçta tutulmasını ister. `return` fonksiyondan değer döndürür. `signed`/`unsigned` işaretli/işaretsiz sayıyı belirler. `sizeof` bir yapının kaç bayt yer kapladığını verir. `struct` ve `union` aynı varlığa ait farklı türden verileri bir kayıt yapısında toplar; `typedef` bunlara yeni bir ad verir. `void` değer döndürmeyen fonksiyonun türüdür.
  - > **Ders sonrası not:** Hoca `float` için "ondalıklı tam sayı türü" dedi; `float` kayan noktalı (ondalıklı) bir türdür, tam sayı türü değildir.
  - > **Ders sonrası not:** Hoca `unsigned` ile "bir bayttan tasarruf edildiğini" söyledi. Kazanılan, işaret için ayrılan tek bir bittir; bu bit de değer aralığına katılır (örneğin 8 bitlik işaretli tür −128..127, işaretsiz tür 0..255).
  - > **Ders sonrası not:** Hoca `volatile` için emin olmadığını belirterek "değeri sadece o anda kullan" benzeri bir anlam verdi. `volatile`, değişkenin değerinin programın denetimi dışında (donanım, kesme, başka iş parçacığı) değişebileceğini bildirir; derleyici bu değişkene her erişimde değeri bellekten yeniden okur ve bu erişimleri optimize etmez. `auto` ve `static` derste açıklanmadı.
- **Fonksiyon imzası (allusion).** Hocanın örneğinde bir kombinasyon fonksiyonunu başka bir fonksiyon çağırıyordu. Bu durumda ya kombinasyon fonksiyonu kaynak dosyada daha yukarıda yazılır ya da dosyanın başında imzası verilir. İmzada yalnız parametre türleri yeterlidir; tanımda parametre adları yazılmak zorundadır. Kitaptaki "allusion" terimi bugün genellikle "prototip" ya da "bildirim" diye geçer. <!-- BELİRSİZ: kombinasyon fonksiyonunun slayttaki imzası altyazıda bozuk ("İnt, a, int, bir tane parametre alıyor"); ilgili anın karesi yok. -->
- **Slayttaki `square` örneği.** Biçimlendirme slaytında fonksiyon `int square (num) { int answer; answer = num * num; return answer; }` biçiminde yazılmıştır (ekrandan, 01:30:00). `main` slaytında ise `extern int square();` bildirimi, `int solution;`, `solution = square(5);` ve `exit(0);` vardır (ekrandan, 01:35:00).
  - > **Ders sonrası not:** `int square (num)` yazımı eski K&R stilidir; parametrenin türü yazılmadığı için `int` varsayılır. Bu biçim `-std=c89` ile derlenir, ama gcc 15'in varsayılan modunda `type of 'num' defaults to 'int'` hatası verir (ajan tarafından denendi). Güncel yazım `int square(int num)` biçimindedir.
  - Slayttaki parçalar birleştirilip güncel yazımla tam programa dönüştürüldü. Bu birleştirme derste yapılmadı; ajan tarafından `gcc -Wall` ile derlendi, çalıştırıldı ve `square(5) = 25` çıktısını verdi:

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int square(int num);   /* allusion (prototip) */

    int main(void) {
        int solution;
        solution = square(5);
        printf("square(5) = %d\n", solution);
        exit(0);
    }

    int square(int num) {
        int answer;
        answer = num * num;
        return answer;
    }
    ```

- **`scanf` ve biçim belirteci.** Slayttaki örnek `int num; scanf("%d", &num); printf("num : %d\n", num);` biçimindedir (ekrandan, 01:40:00). `scanf`, okuduğu değeri değişkenin bellekteki adresine yazar; bu yüzden `&num` verilir. `%d`, girilen verinin tam sayı olarak yorumlanacağını söyler. Hoca bunun gerekçesini şöyle açıkladı: C çok esnektir; örneğin kullanıcı `A` harfi girerse bu harf bellekte ASCII kodu olan 65 sayısıyla tutulur. Bu esnekliğin bedeli karmaşıklıktır, bu yüzden verinin nasıl yorumlanacağı biçim dizgisiyle açıkça belirtilir. Bu parçalar `main` içine konup `gcc -Wall` ile derlendi; `7` girdisiyle `num : 7` çıktısı alındı (birleştirme ajan tarafından yapıldı).
- **Önişlemci ve sabitler.** Bir fonksiyonun başka bir fonksiyondan çağrılabilmesi için önceden bilinmesi gerekir. Bu tür tanımların ve eklenecek kitaplıkların derlemeden önce gözden geçirilmesi önişlemcinin işidir. Hocanın `#define` örneği: girilmemiş bir yaş alanı arka planda bir sistemde −1, başka bir sistemde 0 ile tutuluyor olabilir. Kodun her yerinde `NOTHING` kullanılırsa, sistem değiştiğinde yalnızca `#define NOTHING ...` satırı değiştirilir. Aksi halde bütün 0'ları elle −1 yapmak gerekir ve 10 gibi sayıların içindeki 0'lar da yanlışlıkla değişebilir.
  - > **Ders sonrası not:** Hoca önişlemci komutlarının "programın ilk satırları olmak zorunda" olduğunu söyledi. Slayttaki kural, `#` işaretinin satırdaki ilk boşluk olmayan karakter olmasıdır; önişlemci yönergeleri büyük olasılıkla dosyanın herhangi bir yerinde bulunabilir, yalnız gelenek olarak `#include` satırları başa yazılır.
- **Dev-C++ ile ilk program.** Hoca Dev-C++ 4'ü (içinde MinGW derleyicisi gelir) boşluk içermeyen bir dizine (`C:\DevCpp4`) kurduğunu, çünkü eski derleyicilerin `Program Files` gibi boşluklu yolları sevmediğini söyledi. File → New Project → Console Application → C seçilip proje adı verilir. Kaynak dosya kaydedilmeden derleme yapılmamalıdır. Program çalıştırıldığında konsol penceresi hemen kapandığı için çıktı görülmez. İki çözüm gösterildi: programı komut satırından (`cmd`) çalıştırmak ya da `return 0;`'dan önce bir tuşa basılmasını bekleyen bir komut eklemek (`conio.h` içindeki `getch()`). <!-- BELİRSİZ: getch() satırının ekrandaki kodu karelerde görünmüyor; altyazıda "Pulse fonksiyonu", "geç yaş" gibi bozuk geçiyor. Hoca bazı sistemlerde iki kez yazmak gerektiğini söyledi. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
