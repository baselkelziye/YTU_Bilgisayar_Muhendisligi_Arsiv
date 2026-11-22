# Ders 16 Genişletilmiş Notu: C Programlamaya Giriş: Program Geliştirme, Veri Tipleri, Operatörler ve Kontrol Yapıları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Program Geliştirme Süreci
- 3. C'nin Temelleri ve Fonksiyon Yapısı
- 4. Değişkenler, Sabitler ve Adlandırma
- 5. İfadeler ve Atama Deyimi
- 6. Kod Formatlama ve Yorumlar
- 7. main Fonksiyonu, return ve exit
- 8. printf ve scanf
- 9. Önişlemci: include ve define
- 10. Hello World Programı
- 11. Veri Tipleri
- 12. Sabitlerin Yazımı
- 13. Değişken Tanımlama ve İlk Değer
- 14. Tiplerin Karışması ve Dönüşümler
- 15. enum, void ve typedef
- 16. Operatörler
- 17. Kontrol Yapıları
- 18. break, continue ve goto
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Planı

Bu derste C ile programlamanın temelleri tamamen teorik olarak anlatıldı; uygulaması laboratuvar saatinde, daha önce kurulan Ubuntu sanal makineleri üzerinde yapılacaktı. Hoca konuları şöyle sıraladı: program geliştirme süreci, C'nin temel bilgileri ve fonksiyon yapısı, değişkenler ve adlandırma, kod formatlama, yorum yazma, önişlemci, veri tipleri ve farklı veri tiplerinin aynı ifadede kullanılması (mixing). İkinci parçada operatörler, öncelik ve kontrol akışı yapıları ele alındı.

Hoca "mixing" sözcüğünün tiplerin birbirinin yerine kullanılması değil, birden fazla farklı tipin aynı ifade içinde birlikte kullanılması anlamına geldiğini belirtti. Bazı ayrıntıların şimdilik "fazla detay" olduğunu, bunları yer yer ayrıca uyaracağını söyledi.

Veri tiplerinin önemini önceki derslere bağladı: arka planda her şey 0 ve 1'lerden oluşur, önemli olan bunun nasıl yorumlandığıdır. Bir tamsayı da kesirli sayı da 16, 32 ya da 64 bitlik bir dizi olarak tutulur; kesirli sayıda bu bitlerin belli kısımları üs (exponent), belli kısımları mantis olarak yorumlanır.

## 2. Program Geliştirme Süreci

### 2.1 Editör ve IDE

Program bir kaynak dosyayla (source file) başlar. Bu dosya bir editörle ya da bir IDE ile yazılır. Hoca Linux kurulumu yapılan hafta kullanılan gedit'i hatırlattı: herhangi bir metin editörü, dosya `.c`, `.txt`, `.html` gibi bir uzantıyla kaydedildiğinde uzantıya göre renklendirme yapabilir, ama bu onu IDE yapmaz.

IDE (Integrated Development Environment, tümleşik geliştirme ortamı), kod yazma, derleme, derlenen kodu çalıştırma ve hata ayıklama (debug) için ek olanakları tek ekranda ve tek yapı içinde sunan uygulamadır. Normalde kod bir editörde yazılır, editör kapatılır ve kod ayrıca derlenir; o uygulamada GNU C derleyicisi, yani GCC kullanılmıştı.

> **Hocanın vurgusu:** Hoca öğrencilerden önce bağımsız olarak bir metin editöründe kod yazabilmelerini, sonra editörün dışına çıkıp kodu derleyebilmelerini, yani işin temelini çözebilmelerini beklediğini söyledi.

### 2.2 Derleme ve bağlama

Slayttaki şemada üç kaynak dosya ayrı ayrı nesne dosyasına (object file) dönüşür; nesne dosyaları ve çalışma zamanı kütüphanesi (runtime library) bağlama (link) adımında birleşir ve çalıştırılabilir kod (executable code) oluşur (ekrandan, 00:25:00). Slayttaki maddeler şunlardır:

- Derleyicinin görevi kaynak kodu makine koduna çevirmektir.
- Derleyicinin girdisi kaynak kod, çıktısı nesne kodudur.
- Bağlayıcı (linker) ayrı nesne dosyalarını tek dosyada birleştirir.
- Bağlayıcı gerekirse çalışma zamanı kütüphanesindeki fonksiyonları da bağlar.
- Bağlama genellikle otomatik yapılır.

Hoca bağlamayı şöyle açıkladı: yazılan kod içinde, dilin bünyesinde hazır bulunan bazı fonksiyonlar ya da sistem çağrıları kullanılır. Bunlar çalışma zamanı kütüphanesinden çağrılır. Kod derlenip nesne dosyası oluşturulduğunda bu çağrıların olduğu yerlerde birer başvuru (referans) bulunur. Bağlama aşamasında bu başvurular kütüphanedeki adreslerle değiştirilir, gerekli kod eklenir ve program çalıştırılabilir hale gelir.

### 2.3 Birden fazla kaynak dosya

Şekilde birden fazla kaynak dosya vardır ve olması gereken de budur. Derste şimdiye kadar basit problemler tek bir kaynak dosyada çözüldü, ama gerçek bir uygulamada kod mantıksal olarak farklı parçalara ayrılmalı, birbiriyle ilgili parçalar bir arada toplanmalı ve sonra birleştirilmelidir. Bu hem okunabilirlik hem de takip edilebilirlik için mantıklıdır.

Hoca bir dosya sunucusu (file server) örneği verdi: dosya sistemiyle ilgili işlemler bir dosyada, soketle ilgili işlemler (karşıdan gelen istekleri yorumlayıp cevap üreten kısım) başka bir dosyada, sunucu çok iş parçacıklı (multi-threaded) ise iş parçacıklarıyla ve aralarındaki haberleşmeyle ilgili kısım ayrı bir dosyada tutulur. Bunların hepsinde ortak kullanılan fonksiyonlar `misc` gibi ayrı bir dosyaya konur.

### 2.4 gcc'de tek adım

gcc ile bir dosya derlendiğinde derlemenin hemen ardından bağlama da yapılır ve bir çalıştırılabilir dosya çıkar; iki adım tek adımmış gibi görünür. Çoğu derleyici böyle çalışır. Yalnız derleme adımının çalışması isteniyorsa bu ayrıca belirtilmelidir; ayrıntısı laboratuvar uygulamasına bırakıldı.

> **Ek bilgi (derste anlatılmadı):** gcc'de yalnız derleme yapıp nesne dosyası üretmek için `-c` seçeneği kullanılır (örneğin `gcc -c dosya.c` komutu `dosya.o` üretir). Nesne dosyaları sonra `gcc dosya1.o dosya2.o -o program` gibi bir komutla bağlanır.

## 3. C'nin Temelleri ve Fonksiyon Yapısı

### 3.1 Küçük bir dil ve büyük bir kütüphane

Slaytta C için "küçük bir dil" deniyordu. Hoca bunun yanlış anlaşılabileceğini söyledi: buradaki "küçük", kendi kodunu en az düzeyde yazarak birçok şeyi gerçekleştirebilmek demektir, çünkü ihtiyaç duyulan şeylerin çoğu büyük bir çalışma zamanı kütüphanesinde hazırdır. Bu kütüphane önceden yazılmış ve kullanıma sunulmuş nesne kodlarından oluşur; içinde matematik, karakter dizileri, giriş-çıkış, bellek yönetimi ve süreçlerle ilgili parçalar vardır.

Her parçanın içinde neler olduğunu ve kullanılabilir yapılarını belirten başlık dosyaları (header) vardır; bunlar `.h` ile biter. Bu yapıları kullanmak için ilgili başlık dosyası `#include` yönergesiyle koda eklenir. Örneğin ekrana bir şey yazdırmak için kütüphanenin standart giriş-çıkış parçasına ihtiyaç vardır ve kodun başına `#include <stdio.h>` yazılır. Böylece bu başlık dosyasında tanımlı her şey (fonksiyonlar, veri yapıları, değerler) kullanılabilir hale gelir.

### 3.2 Fonksiyon nedir?

Hoca C'yi "fonksiyonel bir programlama dili" olarak niteledi ve bunu "her şey fonksiyonlar üzerinden yürür" anlamında kullandı.

> **Ders sonrası not:** Hoca C için "fonksiyonel programlama dili" dedi. Programlama dilleri sınıflandırmasında C yordamsal (procedural) bir dildir; "fonksiyonel programlama" terimi Haskell gibi dillerin farklı bir paradigmasını anlatır. Hocanın kastettiği, C programının fonksiyonlardan oluşmasıdır.

Fonksiyon, mantıksal olarak birbiriyle ilişkili işlemler grubudur. Bu grup parametrelere bağlandığında farklı parametrelerle tekrar tekrar kullanılabilir; ama fonksiyonun parametre alması zorunlu değildir. Önemli olan tekrar kullanılabilir bir yapı olmasıdır.

Bir fonksiyonu tanımlamak için gerekenler:

- Fonksiyonu kullanabilmek için bir ad.
- Varsa parametreleri.
- Fonksiyon içinde kullanılacak değişkenlerin tanımları.
- Argümanlar ve değişkenler üzerinden yapılacak işlemler.
- Bir sonuç, yani dönüş değeri. Dönüş isteğe bağlıdır, ama dönüş olmasa bile bunun olmadığını belirten bir tip gerekir.

### 3.3 Sözdizimi

Slayttaki sözdizimi şeması şu sırayı izler: fonksiyon tipi → fonksiyon adı → `(` → argümanlar → `)` → `{` → tanımlamalar (declarations) → C deyimleri (C statements) → `}` (ekrandan, 00:35:00). Fonksiyon tanımlanırken argümanlar tipleriyle birlikte yazılır. Süslü parantez (curly brace), matematikte küme parantezi olarak bilinen işarettir; biri açar, biri kapatır.

Slayttaki tanımlara göre C fonksiyonu C dili işlemlerinin bir toplamıdır; dilin yerleşik işlemlerinden daha karmaşık bir iş yapmalı, ama aynı zamanda anlaşılması zor olacak kadar karmaşık olmamalıdır. Argümanlar çağıran fonksiyondan çağrılan fonksiyona aktarılan verilerdir (ekrandan, 00:35:00).

C programı sürekli fonksiyon çağrıları üzerinden yürür ve bir başlangıç noktası vardır. Bu nokta da bir fonksiyondur: `main` (ana fonksiyon). Bu yüzden her C kodunun bir `main` fonksiyonuna ihtiyacı vardır ve bir C dosyası oluşturulduğunda ilk yapılacak iş bu fonksiyonu yukarıdaki kurallara uygun şekilde hazırlamaktır.

## 4. Değişkenler, Sabitler ve Adlandırma

### 4.1 Değişken ve sabit

`j = 5 + 10;` ifadesinde `j` bir değişkendir: adlandırılmıştır ve bilgisayarın belleğinde bir adrese karşılık gelir. Bu adresin içeriğinde deyimin sağ tarafındaki `5 + 10` işleminin sonucu, yani 15 saklanır. 5 ve 10 ise sabittir; koda sabit olarak yazılmışlardır, değişme olasılıkları yoktur ve onlara değer atanamaz. Değişken bellekte bir adres alanını gösteren yapıdır; o adrese erişildiğinde değere ulaşılır. Sabitler de bellekte bir yerdedir, ama yazılabilir ya da değiştirilebilir değildir.

### 4.2 Adlandırma kuralları

Slayttaki kurallar (ekrandan, 00:40:00):

- C'de hemen her şeye ad verilebilir: değişkenler, sabitler, fonksiyonlar, hatta programdaki bir konum.
- Adlar harf, rakam ve alt çizgi (`_`) içerebilir, ama bir harf ya da alt çizgiyle başlamalıdır.
- C büyük-küçük harfe duyarlıdır (case sensitive): `VaR`, `var`, `VAR` üç farklı addır.
- Ad, ayrılmış anahtar sözcüklerden (reserved keywords) biriyle aynı olamaz.

Hoca bunları örneklerle açıkladı. `A1` diye bir değişken oluşturulabilir, `1A` oluşturulamaz. Bir yerde küçük harfle tanımlanan değişken başka bir yerde büyük harfle yazılırsa derleyici böyle bir değişken olmadığını söyler.

Ayrılmış sözcükler, dilin bir şey yapabilmek için kullandığı komutlardır. Örneğin döngü için `for` yazılır; bu yüzden `for` adında değişken tanımlanamaz, dilin kendi komutuyla çakışır. Aynısı `if` için de geçerlidir. Veri tipleri de böyledir: tamsayı değişken tanımlarken önce tip (`int`), sonra ad yazılır ve `int` aynı zamanda değişken adı olamaz. `enum`, `void`, `float`, `double`, `while`, `else`, `case`, `const`, `do` da bu yasak listesindedir.

Geçerli ve geçersiz adlar: `j` geçerlidir, yanına sayı eklemek (`j5`) de geçerlidir; ama sayıyı başa koymak (`5j`) geçersizdir. Harf, rakam ve alt çizgi dışındaki nokta, `#`, `*`, `:`, `$`, `!` gibi özel karakterler adda kullanılamaz.

## 5. İfadeler ve Atama Deyimi

### 5.1 İfade (expression)

Hoca bu kavramları, kod yazarken derleyicinin "invalid assignment statement" ya da "invalid expression" gibi hata mesajlarını anlamayı kolaylaştırmak için anlattığını söyledi. Yalnız `5` içeren bir ifade de, yalnız bir değişken içeren ifade de bir ifadedir. Bunları aritmetik bir işleme sokmak, içine bir fonksiyon eklemek, bölüm ve çarpımlarla karmaşıklaştırmak da yine bir ifadedir. Slayttaki tanıma göre ifade, bir değerin hesaplanmasını gösteren operatör, sayı ve adların herhangi bir birleşimidir; kısaca sonuç üreten her şey ifadedir.

### 5.2 lvalue ve rvalue

Atama deyiminin şeması: lvalue → `=` → rvalue → `;` (ekrandan, 00:45:00). Atama deyiminin sol tarafı (lvalue), değer tutabilen bir bellek adresine çözümlenmelidir. Atama operatörünün sağ tarafındaki ifadeye bazen rvalue denir; sağ taraf yalnız bir ifade içermeli, yani sonucunda bir değer çıkmalıdır.

Slayttaki örnek: `answer = num * num;` doğrudur, `num * num = answer;` yanlıştır (ekrandan, 00:45:00). Hoca matematikten gelen alışkanlıkla bunu ters yazanlar olduğunu, iki sayının çarpımı bir yere atanacaksa çarpımın sağda, sonucun atanacağı yerin solda olması gerektiğini söyledi. Ters yazıldığında bir değişkenin değeri bir işleme atanmaya çalışılır ve bu mümkün değildir.

## 6. Kod Formatlama ve Yorumlar

### 6.1 Formatlama

> **Hocanın vurgusu:** Hoca bu ders kapsamında kodun doğru düzgün formatlanmasını bekleyeceğini, isteyeceğini ve buna zorlayacağını söyledi.

Slaytın solundaki örneklerden birinde her şey sola dayalı ve alt alta yazılmıştı, hiç girinti (indentation) yoktu. Bir diğerinde her deyim bile farklı satırlara bölünmüştü; anlaşılabilirliği daha da kötüydü. Sağ tarafta olması gereken gösteriliyordu.

C kodunu formatlamanın farklı stilleri vardır; örneğin Linux çekirdeğindeki stil ile standart stil farklıdır. Ama hepsi kendi içinde tutarlıdır ve öğrencinin de bu şekilde ilerlemesi gerekir. Kurallar:

- Fonksiyonun dönüş tipi, adı ve parametresi yazılır; açılış süslü parantezi aynı satırda ya da bir alt satırda olabilir (bu stiller arasındaki farklardan biridir).
- Fonksiyonun ilk deyimi mutlaka dört karakter ya da bir sekme (tab) kadar içeri alınır.
- Akışta bir `if`, `for` ya da `while` varsa bunların içindeki deyimler bir kez daha içeri alınır.
- Değişken tanımlarıyla deyimler arasında bir boş satır bırakılır.

Kodun okunabilirliği önemlidir; aynı koda üç ay sonra dönüldüğünde yazanın kendisinin de anlayabilmesi gerekir.

### 6.2 Adlandırma ve yorum

Bir programda farklı farklı değişkenler kullanılır; hangisinin neye hizmet ettiğini bilmek kodun anlaşılabilirliğini ciddi biçimde artırır. Bu yüzden adlandırmanın düzgün yapılması önemlidir, ama tek başına yetmez. Neyin niçin yapıldığını açıklamak için yorum satırları eklenir. Hoca yorum yazmanın programlamada en kritik ve en çok ihmal edilen şeylerden biri olduğunu söyledi.

### 6.3 Yorum yazma biçimleri

Slayttaki maddeler (ekrandan, 00:50:00):

- Yorum, kodun ne yaptığını açıklamak için kaynak dosyaya eklenen metindir; insanlar içindir, derleyici yorumları yok sayar.
- C'de yorumlar `/*` ve `*/` işaretleri arasına yazılır.
- İç içe yorumlar desteklenmez.
- Neler yorumlanmalı: fonksiyon başlığı ve koddaki değişiklikler.

Slaytın sağında bir fonksiyon başlığı yorumu örneği vardı (ekrandan, 00:50:00):

```c
/* square()
 * Aurhor : ...
 * Initial coding : 3/87
 * Params : an integer
 * Returns : square of its parameter
 */
```

Derleyici `/*` ile başlayıp `*/` ile biten kısmın yorum olduğunu anlar ve derlemenin dışında bırakır; yorum birkaç satır sürebilir ya da tek satırda kalabilir.

> **Hocanın vurgusu:** Şimdilik ayrı fonksiyonlar yazılmayacağı, her şey tek bir `main` içinde yazılacağı için hoca `main`'in başına bu kodun ne zaman ve ne için yazıldığını, parametrelerin ne olduğunu ve ne yaptığını tek tek yazmayı tavsiye etti. Bu bir alışkanlık kazandırır.

Hoca ileride büyük projelerde, standart biçimde yazılmış yorumlardan otomatik belge üreten araçlar sayesinde belgelendirmenin çok hızlı tamamlanabileceğini de ekledi.

İkinci yol iki eğik çizginin (`//`) yan yana konmasıdır. Bu yalnız o satırı yoruma çevirir (comment out); `//`'dan sonra satır boyunca yazılan her şey yorum olur. Örneğin `a = a + b;` yazıp noktalı virgülden sonra `//` ile kısa bir açıklama eklenebilir.

## 7. main Fonksiyonu, return ve exit

### 7.1 main'in dönüş tipi

Yazılan her C kodu çalıştırılabilir bir dosyaya dönüşmek zorunda değildir; bir paylaşımlı (shared) ya da statik kütüphane, bir çekirdek modülü gibi şeyler de yazılabilir. Ama çalıştırılabilir bir program olacaksa bir `main` fonksiyonu olmak zorundadır.

Unix sistemlerinde `main`'in tipini `int` vermek genel alışkanlıktır. Bunun nedeni şudur: Unix'te çalışan her program bir kabuk (shell) ya da başka bir program tarafından çalıştırılır ve dönüş değeri program bittiğinde verilen sayısal değerdir. Değer 0 ise program sorunsuz çalışıp bitmiştir; böylece çağıran program ya da kabuk bir sorun olup olmadığını anlar. Çoğu zaman negatif değerler sorunları, zaman zaman pozitif değerler de sorunları ya da uyarıları gösterir. Hoca bunun yazılı bir kural değil, genel geçer bir uygulama olduğunu belirtti.

### 7.2 Slayttaki örnek

Slayttaki örnekte `main`'in parantezleri içi boştu, yani fonksiyon parametre almıyordu. İçinde `int solution` tanımıyla `solution` adında tamsayı bir değişken tanımlanıyordu. Ayrıca `square` adlı fonksiyonun başka bir dosyada tanımlı (external) olduğu ve tamsayı döndürdüğü belirtiliyordu; hoca bu tanımın şimdilik ilgilendirmediğini söyledi. Sonra fonksiyon kullanılıyor, en sonda `exit(0)` ile program sonlanıyordu.
<!-- BELİRSİZ: Bu slaytın tam kodu karede okunmadı; açıklama altyazıdan (00:53-00:54) kuruldu. -->

### 7.3 return ve exit

Fonksiyonlardan normalde `return` ile dönülür. `main` özel bir noktadır: işe başlanan ve işin bittiği yerdir. Bu yüzden `main` içinde `return` demenin `exit` fonksiyonunu çağırmaktan hiçbir farkı yoktur. `exit`'e parametre olarak ya da `return`'ün yanına yazılan sayısal değer, `main`'in `int` dönüş tipi üzerinden döndürülen değerdir. `exit(0)` ile program normal biçimde bittiğinde dönüş değeri 0 olur.

**Soru:** (sohbetten) `main` dışındaki fonksiyonlarda `exit` kullanılamıyor, değil mi?
**Cevap:** Kullanılabilir, ama mantıklı bir noktada olmalıdır. Herhangi bir fonksiyonda `exit` çağrıldığında program sonlandırılır. Bu, programın çalışmasını engelleyecek bir hata olduğunda yapılır. Örneğin bir fonksiyonda bellek ayırıp (allocation) bir yerden değer okunacak ve bu değerlerle işlem yapılacaksa, ama yeterli bellek olmadığı için ayırma yapılamıyorsa değer okunamaz, işlem yapılamaz ve çalışmanın anlamı kalmaz; o zaman `exit` çağrılabilir. Amaç yalnız `main` dışındaki bir fonksiyonu bitirip geri dönmekse `exit` değil `return` kullanılmalıdır.

## 8. printf ve scanf

### 8.1 Biçim dizisi

C'nin çalışma zamanı kütüphanesindeki bileşenlerden biri, `stdio.h` eklenerek kullanılan standart giriş-çıkış kütüphanesidir. Bu kütüphanede dış dünyayla, yani terminal üzerinden kullanıcıyla etkileşimi sağlayan iki temel fonksiyon vardır: bilgi okuyan `scanf` ve terminale bilgi yazan `printf`.

Slayttaki maddeler (ekrandan, 00:55:00):

- `printf()` istediği sayıda argüman alabilir. İlk argümana biçim dizisi (format string) denir; çift tırnak içindedir ve metin ile biçim belirteçleri (format specifiers) içerebilir.
- `scanf()`, `printf()`'in ayna görüntüsüdür; terminale veri yazmak yerine klavyeden girilen veriyi okur. İlk argümanı bir biçim dizisidir.
- `scanf()` ile `printf()` arasındaki temel fark, `scanf`'teki veri argümanlarının lvalue olması gerektiğidir.

Slayttaki kod (ekrandan, 00:55:00):

```c
int num;

scanf("%d", &num);
printf("num : %d\n", num);
```

### 8.2 printf

Ekrana Hello World yazdırmak için `printf` yazılır, parantez açılır, çift tırnak içine mesaj yazılır, tırnak ve parantez kapatılır, noktalı virgül konur. Bu biçim dizisi statik bir içeriktir, ama parametrik hale getirilebilir. Slayttaki `printf` örneğinde `num : ` kısmı sabit metindir. `%d` biçim belirtecidir; `d` C'de decimal demektir ve sayının ondalık olarak yazdırılacağını söyler. `\n` bir kaçış dizisidir (escape sequence), yeni satır (new line) anlamına gelir. `\t` ise sekme karakteridir, bir sonraki sekme konumuna kadar boşluk atlatır.

Biçim dizisinden sonra virgül konur ve değişken yazılır. Örnekte değişken `int` tipindeki `num`'dır ve `%d` ile içindeki değer ondalık sayı olarak yazılır. İki biçim belirteci olsaydı C bir virgül ve ikinci bir değişken daha bekleyecekti.

> **Hocanın vurgusu:** C, programcının her şeyi bilerek yaptığını varsayan bir dildir; en ufak aksaklıkta "bunu çalıştırmam" demez. Farklı tipteki bir değişken başka tipteki bir değişkene atanabilir, `if` içinde denetim yerine atama yapılabilir. İki biçim belirteci verip yanına tek değişken yazılırsa derleyici hata vermez, bir uyarı verir ve devam eder. Özellikle "her şey için uyar" denmedikçe bazı şeylere uyarı bile vermez. Bu anlamda C biraz tehlikelidir; yanlış yazılan şeyler kolay kolay hata olarak karşıya çıkmaz. Derlemenin hangi parametrelerle yapılacağı uygulamada konuşulacaktı.

### 8.3 scanf ve adres

`scanf`'te biçim dizisine genellikle yalnız biçim belirteci yazılır, çünkü okuma yaparken ekrana bir şey basmaya gerek yoktur; ekrana basma işi `printf` ile yapılır ve karşılığında bir cevap beklenir. `scanf`'e beklenen cevabın hangi biçimde olacağı ve nereye yazılacağı söylenir. Örnekte `%d` ile ondalık bir sayı alınacağı ve `num` değişkenine yazılacağı belirtilir.

`num`'ın önüne `&` (ampersand) işareti konur, çünkü `scanf` istenen biçimdeki değeri aldıktan sonra onu hangi adrese yazacağını bilmelidir. Yalnız `j` yazıldığında `j`'nin içeriği (örnekte 15) kastedilir; `&j` yazıldığında `j`'nin adresi kastedilir (derste örnek adres olarak 2486 söylendi).
<!-- BELİRSİZ: j değişkeninin örnek adresi (2486) altyazıdan alındı; ilgili slayt karesi okunmadı. -->

Fonksiyonlara bilgi aktarmanın iki yolu vardır: değerle aktarma (pass by value) ve başvuruyla aktarma (pass by reference). C'de aktarım değer üzerinden yapılır: yazılan değerin bir kopyası oluşturulup fonksiyona aktarılır. `scanf`'e yalnız değişken yazılırsa içindeki değerin bir kopyası aktarılır ve bunun bir anlamı olmaz. Değişkenin adresi yazılırsa adres aktarılır ve fonksiyon o bellek bölgesine erişip içeriği değiştirebilir. Hoca bunun C'nin tasarım özelliklerinden biri olduğunu ve şimdilik bu düzeyde bilinmesinin yeterli olduğunu söyledi.

## 9. Önişlemci: include ve define

### 9.1 Önişlemcinin yeri

Derleme iki adım (derleme ve bağlama) olarak anlatılmıştı; aslında C'de derlemenin hemen öncesinde bir de önişlemci (preprocessor) adımı vardır. Önişlemci, kod içinde verilen yönergelere (directive) uygun olarak istenen işleri yapar. Slayttaki maddeler (ekrandan, 01:05:00):

- Önişlemci, program derlendiğinde otomatik olarak çalışır.
- Bütün önişlemci yönergeleri `#` (pound) işaretiyle başlar; bu işaret satırdaki boşluk olmayan ilk karakter olmalıdır.
- C deyimlerinin aksine, önişlemci yönergesi noktalı virgülle değil satır sonuyla biter.
- Önişlemci ayrıca makro işleme, koşullu derleme ve yerleşik makrolarla hata ayıklama yapabilir.

`#include <stdio.h>` yazıldığında `#` bunun bir önişlemci yönergesi olduğunu söyler. `include`, parametre olarak verilen dosyanın içeriğini alır ve kodun içine gömer; başlık dosyasında ne varsa koda eklenir. Makrolar işlenir. Koşullu derlemeyle, örneğin Windows, Linux ya da başka bir ortamda olmaya göre farklı kütüphanelerin eklenmesi ya da dosya sistemindeki yolların farklı oluşturulması sağlanabilir. Hoca derste temel olarak `include` kullanılacağını ve "ucundan azıcık" makro yapılacağını söyledi.

### 9.2 define ile sabitler

> **Hocanın vurgusu:** Makrolarla çok fantastik işler yapılabilir, ama derste amaç bir alışkanlık kazanmaktır: kod içinde sabit olarak görülen her şey (5, 10, 25, 3.14 gibi) bir makro olarak tanımlanacak. Kodun farklı yerlerinde her yere 10 yazmak yerine sabit bir yerde tanımlanacak; değişiklik gerektiğinde kodun ilgili yerlerine tek tek gidilmeyecek, tek bir makronun değeri değiştirilecek. Bu bakım (maintenance) açısından ciddi fayda sağlar.

Tanım önişlemci yönergesi olduğu için önce `#`, sonra `define`, sonra makronun adı, sonra değeri yazılır. Standart değişkenlerle karışmaması için makro adının tamamen büyük harflerle yazılması tercih edilir.

> **Hocanın vurgusu:** C'de her deyimin sonuna noktalı virgül konur, ama önişlemciye verilen yönergelerin (`define`, `include` ya da başka bir yönerge) hiçbirinin sonuna noktalı virgül konmaz. Konursa, makronun nerede ve nasıl kullanıldığına bağlı olarak hiç hata almadan devam edilebilir ya da çok tuhaf, anlamsız hatalar alınabilir.

### 9.3 include'un iki biçimi

`include` ile çalışma zamanı kütüphanesindeki kütüphaneler koda eklenir: `stdio.h` gibi `math.h` de, iş parçacıklarıyla bir şey yapılacaksa `pthread.h` de eklenebilir. Hazır kütüphanelerin yanında kişinin kendi yazdığı kütüphaneler de eklenebilir.

Slayttaki maddeler (ekrandan, 01:20:00):

- `#include` yönergesi derleyicinin, derlemekte olduğu dosyanın yanında başka bir dosyadan da kaynak metin okumasını sağlar.
- `#include <filename>`: önişlemci işletim sisteminin belirlediği özel bir yerde arar; bütün sistem başlık dosyaları burada tutulur.
- `#include "filename"`: önişlemci kaynak dosyanın bulunduğu klasörde arar; dosyayı bulamazsa açılı parantezle yazılmış gibi arar.

Hoca kendi yazılan kütüphanenin illa çift tırnakla eklenmesi gerekmediğini de söyledi: kütüphane sistemin ilgili klasörlerine yüklenerek açılı parantezle kullanılabilir ya da işletim sisteminin kütüphane klasörlerini tutan listeye (LibraryPath) kendi dizini eklenebilir. Bunun daha birçok yolu vardır, ama şimdilik basit farkı bilmek yeterlidir.

## 10. Hello World Programı

Hello World uygulaması için yazılacak kod aşağıdaki gibidir. Önce ekrana mesaj yazmak için `printf` gerekir; `printf` standart giriş-çıkış kütüphanesindedir, bu yüzden `#include <stdio.h>` ile eklenir. Sonra `main` yazılır; dönüş tipi `int`'tir. Önceki örnekte `main`'in parantezleri boş bırakılmıştı, burada içine `void` yazılmıştır. `void` bir veri tipidir; parametre listesinde ya da dönüş tipinde kullanıldığında parametre olmadığını ya da dönüş değeri olmadığını belirtir.

İçeride yalnız statik bir içerik doğrudan ekrana basılacağı için `printf` ve sabit bir biçim dizisi kullanılır: "Hello World", ardından üç nokta ve imleci yeni satıra geçiren `\n`. Son olarak `return 0;` ile `main`'in dönüş değeri 0 olur; bu değer istenirse programı çağıran program tarafından okunup değerlendirilebilir.

```c
#include <stdio.h>

int main(void)
{
    printf("Hello World...\n");
    return 0;
}
```

Bu kod ajan tarafından `gcc -Wall` ile derlenip çalıştırıldı; uyarı vermedi ve `Hello World...` yazdı.
<!-- BELİRSİZ: Kod altyazıdaki anlatımdan kuruldu (01:22-01:24); slayt karesi okunmadı, mesaj metninin büyük-küçük harf yazımı doğrulanamadı. -->

## 11. Veri Tipleri

### 11.1 Sınıflandırma

Slayttaki ağaç şöyledir (ekrandan, 01:25:00):

```text
Data types
├── void
├── Scalar types
│   ├── Arithmetic types
│   │   ├── Integral types
│   │   └── Floating types
│   ├── Pointers
│   └── enum
└── Aggregate types
```

`void` ayrı bir durumdur. Skaler tipler sayısal tiplerdir. Birleşik (aggregate) tipler ise bir değişkenin içinde birden fazla değeri bir arada tutar. Derste şimdiye kadar çoğunlukla tamsayılarla, tamsayıların bir araya gelmesiyle oluşan dizilerle ve iki boyutlu dizilerle (matrislerle) çalışılmıştı; dizi ve matris de birleşik tiptir. Hoca bir örnek daha verdi: bir öğrencinin adı, soyadı, kimlik numarası, öğrenci numarası, doğum tarihi gibi farklı tipteki bilgileri bir arada tutmak için C'de bir yapı (structure) oluşturulur; bu da birleşik bir tiptir.

Skaler tiplerin içinde aritmetik tipler (tamsayı ve ondalıklı), işaretçiler (pointer) ve numaralandırma (`enum`) vardır.

### 11.2 Kayan nokta ve sabit nokta

Hoca sayı yazımıyla başladı. Türkçede binlik ayırıcı olarak nokta, ondalık ayırıcı olarak virgül kullanılır; bu standarda göre terstir. Standart yazımda nokta konup ondalık kısım yazılır (`13517.03` gibi). Kayan nokta (floating point) bu noktaya karşılık gelir.

Noktadan sonraki hane sayısı hep sabitse (örneğin hep iki hane) sabit noktalı (fixed point) gösterim kullanılıyordur; noktanın yeri değişmez. Noktadan sonraki hane sayısı artıp azalabiliyorsa (`.003`, `.06`, `.11115` gibi) nokta sağa sola kayıyormuş gibi olur; buna kayan nokta denir. Sabit noktanın uygulanması daha kolay, kayan noktanınki daha zordur.

### 11.3 İşaretçiler

İşaretçiler adres tutan değişkenlerdir. `scanf`'te değişkenin kendisi yerine adresinin `&` ile aktarıldığı görülmüştü; bu adres bilgisini bir yerde saklamak ve üzerinde işlem yapmak için işaretçiler kullanılır. Hoca işaretçilerin bu dersin konusu olmadığını, ikinci dönemde biraz, asıl olarak yapısal programlama dersinde işleneceğini söyledi.

### 11.4 Dokuz ayrılmış sözcük

Slayttaki maddeler (ekrandan, 01:40:00):

- Skaler veri tipleri için 9 ayrılmış sözcük vardır.
- Temel tipler: `char`, `int`, `float`, `double`, `enum`.
- Niteleyiciler (qualifiers): `long`, `short`, `signed`, `unsigned`.
- `j`'yi tamsayı olarak tanımlamak için: `int j;`
- Aynı tipteki değişkenler tek bir tanımda tanımlanabilir: `int j,k;`
- Bir bloktaki bütün tanımlamalar çalıştırılabilir deyimlerden önce gelmelidir.

`char` ve `int` tamsayı tiplerine, `float` ve `double` kayan noktalı tiplere aittir. `char` bir karakteri (harf, noktalama işareti ya da sembol), `int` tamsayı değerleri gösterir. `float` ondalıklı değerler içindir. `double` duyarlığın (precision) iki katına çıktığı, ondalık kısmın daha uzun tutulabildiği tiptir. Boyut sisteme ve derleyiciye göre değişir, ama `float` genelde 4 bayt, `double` 8 bayttır.

Niteleyiciler bir tipin önüne gelerek onunla ilgili farklı şeyler yapılmasını sağlar. `short int j;` dendiğinde `j` 2 bayt olur. `long` dendiğinde, kaç bitlik bir derleyici üzerinde çalışıldığına göre tamsayı 4 ya da 8 bayt olur.

Bunun nedeni C belirtimidir: `int`, üzerinde bulunulan mimarinin doğal işlem boyutuyla aynı olmalıdır. İşlemci tek seferde 16 bit üzerinde işlem yapabiliyorsa `int` en az 16 bit olmalıdır. 32 bitlik bir mimaride `int`'in 4 bayt olması beklenir. Yalnız 2 bayt gerekiyorsa `short` ile sınırlandırılır. Alttaki mimarinin 16, 32 ya da 64 bit olduğundan emin olunmuyorsa ve tamsayının en az 4 bayt olması isteniyorsa `long` kullanılabilir. Hoca slaytta 32 bitlik bir mimaride `int`, `short int`, `long int`, `unsigned short int`, `unsigned long int`, `signed char` ve `unsigned char` tiplerinin boyutlarını ve değer aralıklarını gösteren bir tablo olduğunu, bunun mimariye ve derleyiciye göre değiştiğini söyledi.
<!-- BELİRSİZ: Boyut ve değer aralığı tablosunun değerleri karede okunmadı (01:41-01:42). -->

`signed` ve `unsigned` için önceki derslerde konuşulan işaret biti, bire tümleyen ve ikiye tümleyen hatırlatıldı. Bir değişken (`char` ya da `int`) tanımlanırken bir şey söylenmezse zaten işaretlidir; hem negatif hem pozitif değerleri gösterebilir. İşaretsiz olması isteniyorsa `unsigned` yazılmalıdır. `signed` sözcüğü yalnız belirtimde tutarlılık olsun diye vardır.

### 11.5 Tanımlarda düzen

Aynı tipte birden fazla değişken `int i, j, k;` şeklinde virgülle eklenerek tanımlanabilir; sonunda noktalı virgül yeterlidir. Hoca teknik olarak bir kısıt olmadığını, ama geçici olarak kullanılan ve ara sıra devreye alınıp kapatılacak değişkenlerin ayrı bir satırda tanımlanmasının iyi olacağını söyledi; böylece satırın başına `//` konarak kolayca yoruma çevrilebilirler.

## 12. Sabitlerin Yazımı

### 12.1 Tamsayı sabitleri

C ondalık, sekizlik (octal) ve onaltılık (hexadecimal) sayı sistemlerini destekler. Kodda yazılan bir sayı (3, 5, 10, 15) doğrudan `int`'e eşlenir; örneğin 21 işaretli bir tamsayı olarak ifade edilir. Gerek olmadığı halde sayının başına 0 yazılırsa sayı sekizlik kabul edilir: `003` 3'tür, `010` ise 8'dir; yalnız `10` yazılırsa onluk 10'dur. Onaltılık için başa `0x` yazılır. İşareti belirtmek için başa eksi konur.

Slayttaki tablo (ekrandan, 01:45:00):

| Decimal | Octal | Hexadecimal |
|---|---|---|
| 3 | 003 | 0x3 |
| 8 | 010 | 0x8 |
| 15 | 017 | 0xF |
| 16 | 020 | 0x10 |
| 21 | 025 | 0x15 |
| -87 | -0127 | -0x57 |
| 255 | 0377 | 0xFF |

Tablonun bütün satırları ajan tarafından gcc ile denetlendi; sekizlik ve onaltılık sabitler ondalık karşılıklarını verdi.

Slayta göre bir tamsayı sabiti `int`'e sığıyorsa `int` tipindedir, sığmıyorsa `long int` tipindedir. Sonekler bu yüzden önemlidir: sayı `int` sınırları içinde değilse yanına `L` ya da (işaretsiz olarak sığacaksa) `U` konarak `long` ya da `unsigned` değerlendirilmesi istenir; örneğin `255L`. Slaytta sonekler `u or U`, `l or L` olarak verilmişti (ekrandan, 01:45:00). Hoca bunun C'nin büyük-küçük harf duyarlılığının iki istisnasından biri olduğunu söyledi: soneklerin büyük ya da küçük yazılması fark etmez.

### 12.2 Kayan noktalı sabitler

Bir sayının kayan noktalı olduğunu göstermenin en temel yolu noktadır. Kodda yazılan `7` bir tamsayıdır; sonuna `.0` ya da yalnız `.` konursa kayan noktalı olur. `0.1` gibi yazımlar da kayan noktalıdır. Bir de bilimsel gösterim (scientific notation) vardır; üssün ne olacağı söylenir: `3e2` ya da `5e-5`. `e`'den sonraki eksi üssün negatif olduğunu gösterir; `5e-5` = $5 \times 10^{-5}$.

`double`'da duyarlık iki kattır, yani noktadan sonraki kısım için ayrılan alan daha uzundur ve daha küçük sayılar gösterilebilir. Genelde `float` 4, `double` 8 bayttır.

> **Ders sonrası not:** Hoca bu sınırların `limit.h` dosyasında tanımlı olduğunu söyledi. Tamsayı tiplerinin sınırları `limits.h`, kayan noktalı tiplerin sınırları `float.h` başlık dosyasındadır.

## 13. Değişken Tanımlama ve İlk Değer

Değişken tanımlamak için tip (örneğin `int`), sonra ad (örneğin `a`), sonra noktalı virgül yazılır. Bu değişkenin ilk değeri yoktur. C'de değişkenin kapsamı (scope) ve geçerlilik süresiyle (duration) ilgili özel anahtar sözcükler vardır, ama bunlar bu derste konuşulmadı. Standart olarak böyle tanımlanan bir değişkenin ilk değeri bilinemez: örneğin `char ch;` tanımında `ch`'nin içindeki sayısal değer hakkında hiçbir fikir yoktur; ekrana yazdırılırsa her şey çıkabilir.

Bu yüzden değişken bir işlemde kullanılacaksa önce ilk değer atanmalıdır (ilklendirme). Bu, tanım sırasında `char ch = 'a';` şeklinde ya da tanımdan sonra `ch = 'a';` şeklinde yapılabilir. Tek tırnak içindeki karakter atandığında aslında o karakterin ASCII tablosundaki tamsayı değeri atanır. Bu yalnız karakterler için değil bütün veri tipleri için geçerlidir.

## 14. Tiplerin Karışması ve Dönüşümler

Hoca bu kısmın ayrıntısına çok girmeyeceğini, amacın farklı veri tiplerini bir arada kullanmanın potansiyel sorunlar doğurabileceğini ve bazı işlemlerde beklenenden çok farklı sonuçlar çıkabileceğini fark ettirmek olduğunu söyledi.

### 14.1 Tamsayı yükseltmesi ve hiyerarşi

C performansa dayalı bir dildir. Slayttaki ters piramitte tipler yukarıdan aşağıya şu sıradadır (ekrandan, 01:50:00): `long double`, `double`, `float`, `unsigned long int`, `long int`, `unsigned`, `int`. Bu listede `char` gibi bazı tipler görünmez.

Bir ifadede farklı değişkenler birlikte kullanıldığında bu listede aşağıdan yukarıya doğru genişletilirler. Bir karakter ile bir tamsayı işleme giriyorsa ikisi de `int` olur. C, toplama, çıkarma, çarpma, bölme, atama gibi işlemlerde değişkenleri otomatik olarak `int` düzeyinden başlatır. Nedeni `int`'in tanımıdır: işlemcinin doğal olarak çalışabildiği boyuttur. Bir baytlık karakteri taşımak için ekstra iş gerekir, `int` ise doğal olarak işlenir. Bu yüzden yazılan sabitler de dahil her şey otomatik olarak `int`'e çevrilir. İfadede `unsigned int` ya da `long int` varsa her şey ona, `float`, `double` ya da `long double` varsa ona, yani ifadedeki en büyük boyutlu tipe doğru genişletilir.

### 14.2 Örtük dönüşüm

Slayttaki maddeler (ekrandan, 01:55:00):

- Derleyici bir ifadeyle karşılaştığında onu alt ifadelere böler; her alt ifade bir operatörden ve o operatöre bağlı bir ya da daha fazla nesneden (işlenen, operand) oluşur.
- Örnek: `-3 / 4 + 2.5`; ifade üç operatör içerir: `-`, `/`, `+`.
- Her operatörün işlenen tipi uyumuyla ilgili kendi kuralları vardır, ama çoğu ikili operatör iki işlenenin aynı tipte olmasını ister. Tipler farklıysa derleyici işlenenlerden birini diğerine uyacak şekilde çevirir. Bu dönüşüm için veri tipleri hiyerarşisine başvurur.
- Örnek: `1 + 2.5`; bir `int` ve bir `double` içerir.

Derleyici ifadeyi işlem önceliklerine ve operatörlerin işlenenlerle ilişkisine göre alt ifadelere böler. `1 + 2.5` örneğinde 1 yazılmış bir tamsayı sabitidir, 2.5 ise `double` olarak değerlendirilir; kodda yazılan kayan noktalı sabitler `double` sayılır. Hiyerarşide `double` yukarıda, `int` aşağıda olduğu için `int` `double`'a çevrilir (cast edilir) ve işlem öyle devam eder.

`-3 / 4` kısmında başka bir sorun vardır. Bölme yüksek öncelikli bir işlemdir; 3 ile 4 bölünür ve iki işlenen de tamsayıdır.

> **Hocanın vurgusu:** 3'ü 4'e bölünce içten içe 0.75 beklenir, ama sonuç 0 çıkar; işlenenler tamsayı olduğu için tamsayı bölmesi yapılır. 0.75 isteniyorsa işlenenlerden biri `float` ya da `double` olmalıdır: `3.0 / 4` ya da `3 / 4.0`.

Bu ifadenin değeri ajan tarafından gcc ile denetlendi: `-3 / 4` tamsayı bölmesiyle 0 olur, `0 + 2.5` ile sonuç 2.5 çıkar.

### 14.3 İşaretli ve işaretsiz yorum

Değişkenin önüne bir şey konmazsa işaretli, `unsigned` konursa işaretsiz olur, ama ikisi de aynı miktarda yer kaplar. `char` bir bayt, yani 8 bittir. Slayttaki örnekte `11101010` bit dizisi işaretsiz bir değişkende tutuluyorsa 234, işaretli bir değişkende tutuluyorsa -22 olarak yorumlanır. Bellekte kapladıkları alan da yazılış biçimi de aynıdır; değişen yalnız yorumdur.

Ajan denetimi: $11101010_2 = 128 + 64 + 32 + 8 + 2 = 234$; işaretli yorumda $234 - 256 = -22$ (ara adım eklendi).

### 14.4 Tamsayı ve kayan noktalının karışması

`int` tipinde bir `j` ve `float` tipinde bir `f` toplanırsa sorun olmaz: `j` `float`'a çevrilir ve toplanır; burada yalnız toplama yapılır, sonuç bir yere atanmaz. `j`, `f` ve `2.5` birlikte kullanılırsa sabit `double` olduğu için hepsi `double`'a çevrilir. Asıl soru sonucun nereye atanacağıdır.

`int` tipindeki `j`'ye `j = 2.5;` atanırsa 2.5'in noktadan sonraki kısmı atılır, yalnız tamsayı kısmı (2) kalır. Hoca bir de çok sayıda 9'dan oluşan büyük bir değeri (slaytta "999...9.888" biçiminde) `j`'ye atamayı örnek verdi: bu değer `double`'dır ve bir `int`'in tutabileceğinden büyüktür, bu yüzden `j`'de bambaşka bir sayı görülür.
<!-- BELİRSİZ: Slayttaki büyük sayının tam yazımı karede okunmadı. -->

> **Ders sonrası not:** Hoca bu durumda taşma (overflow) olacağını ve kalan kısmın görüleceğini söyledi. C standardında `int`'e sığmayan bir kayan noktalı değerin `int`'e çevrilmesi tanımsız davranıştır (undefined behavior); sonuç derleyiciye ve sisteme göre değişir.

> **Hocanın vurgusu:** Tipleri bir arada kullanırken özellikle atamanın nereye ve ne şekilde yapıldığına dikkat edilmelidir.

### 14.5 Açık dönüşüm: cast

Derleyici dönüşümleri kendisi yapabildiği gibi programcıya da açıkça dönüşüm yapma imkanı verir; buna cast denir. Slaytta açık dönüşüme casting dendiği ve cast adlı bir yapıyla yapıldığı, bir ifadeyi cast etmek için hedef veri tipinin parantez içinde ifadenin hemen önüne yazıldığı belirtiliyordu (ekrandan, 02:00:00). Slayttaki kod:

```c
int j=2, k=3;
float f;

f = k / j;

f = (float) k / j;
```

`(float) k / j` satırında `k` o işlem sırasında `float` olarak değerlendirilir. `k`'nin `float` olması `j`'nin de `float`'a genişletilmesi demektir; bölme işlemi (3/2) kayan noktalı yapılır ve `f` 1.5 olur. Cast olmadan `k` = 3 ve `j` = 2 tamsayı bölünür, sonuç 1 olur ve `f`'nin değeri 1.0'dır. Bu iki sonuç ajan tarafından gcc ile denetlendi.

## 15. enum, void ve typedef

### 15.1 enum

Hoca `enum`'u veri tipleri sınıflandırmasında ve sonra tekrar anlattı. Kodun içinde çıplak sabitler istenmez, yerlerine makrolar tanımlanması beklenir. Örneğin renkler için kırmızı 0, turuncu 1, mavi 2, yeşil 3 gibi bir anlamlandırma varsa kodda 0, 1, 2, 3 yazmak yerine `RED` gibi makrolar tanımlanır. Haftanın günleri için de pazartesi 0, salı 1, çarşamba 2, perşembe 3, cuma 4 gibi makrolar tanımlanabilir.

Sorun şudur: bu iki makro yapısı bir arada kullanıldığında hiçbir tip denetimi (type checking) yoktur. Haftanın gününün yazılması gereken yere bir renk yazılırsa, değer aralığı tutuyorsa her şey çalışmaya devam eder; nerede ne kullanıldığını denetleme şansı yoktur. Bunun yerine `enum` kullanılabilir. Renkler ve günler `enum` olarak tanımlanınca birbirinden farklı iki veri tipi oluşur; böylece yanlışlıkla birbirinin yerine atanmaları engellenir.

Hoca gerçek hayattan bir örnek verdi: soket programlamada bir soket oluştururken önce protokol ailesi (protocol family, PF), sonra adres ailesi (AF) verilir. Bunlar `enum` olarak değil makro olarak tanımlıdır. Çoğu kişi birinin yerine diğerini yazar; şans eseri ilgili iki makronun değeri aynı olduğu için sorun çıkmaz. Hoca, değerler farklı olsaydı internette bulunan soket kodlarının büyük kısmının çalışmayacağını söyledi.
> **Ders sonrası not:** Hoca TCP/IP'de iki makronun değerinin de 0 olduğunu söyledi. Linux'ta `PF_INET` ve `AF_INET` makrolarının ikisi de büyük olasılıkla 2 değerine tanımlıdır; önemli olan iki değerin aynı olmasıdır.

İkinci anlatımda slaytta renkler ve bunlarla ilgili açık, koyu, orta gibi yoğunluk değerleri tanımlanmış bir örnek vardı. `enum` durum makineleri (state machine) gibi yerlerde ya da günleri tek tek karşılaştırmak yerine kullanılır. `enum` deyip süslü parantez içinde `RED, BLUE, GREEN, YELLOW` yazıldığında değerler 0, 1, 2, 3 diye gider. Sıra ve değerler değiştirilebilir: örneğin `YELLOW = 99` atanabilir. `RED = 100` dendiğinde `BLUE` 101, `GREEN` 102, `YELLOW` 103 olur (ajan gcc ile denetledi).

### 15.2 void

`void` birkaç şekilde kullanılır: bir fonksiyonun parametre almadığını ya da dönüş değeri olmadığını göstermek için, bir de `void` işaretçisi üzerinden genel (generic) bir işaretçi tipi oluşturmak için. Genel işaretçi, fonksiyonun dönüş değerinin ya da yapısının bilinmediği durumlarda işe yarar.

Hoca örnek olarak pthread kütüphanesini verdi: kodda birden fazla akış sağlayan iş parçacıkları (thread) oluşturulduğunda her iş parçacığına bir fonksiyon atanır. Kütüphaneyi yazan kişi kullanıcının oluşturacağı fonksiyonun parametre tipini de dönüş tipini de bilemez. Bu yüzden bunları `void` işaretçisi olarak tanımlar; kullanıcı da cast mekanizmasıyla bunları tamsayı işaretçisine, `float` işaretçisine ya da başka bir işaretçiye çevirerek kullanır. Bu esnekliği sağlar.

### 15.3 typedef

Hoca bunun şimdilik kritik olmadığını söyledi. Şimdiye kadar konuşulanlar standart C'deki veri tipleriydi; `typedef` ile kişi kendi veri tipi adını tanımlayabilir. Slayttaki maddeler (ekrandan, 02:05:00):

- `typedef` anahtar sözcüğü veri tipleri için kendi adlarınızı oluşturmanızı sağlar.
- Anlam olarak, verilen ad veri tipinin eş anlamlısı olur.
- Geleneksel olarak `typedef` adları büyük harfle yazılır.

```c
typedef long int INT32;

long int j;
INT32 j;
```

`typedef` özellikle taşınabilirlik (portability) için kullanılır: bir mimaride yazılan kod başka bir mimariye taşınacaksa, 32 bit olması gereken değişkenler bir yerde `int`, başka bir yerde `long int` olarak tanımlanmak zorunda kalabilir. Bütün değişkenleri tek tek değiştirmek yerine hepsi `INT32` gibi kişinin adlandırdığı bir tiple tanımlanır; mimari değişince yalnız `typedef` tanımı değişir. Bu da elle yapılmaz: önişlemcideki koşullu derlemeyle "mimari 32 bit ise `int`, 16 bit ise `long int` olarak tanımla" denir. Böylece yeterince iyi planlanmışsa hiçbir şeye dokunmadan her platformda çalışan bir yapı kurulur.

## 16. Operatörler

### 16.1 İfade türleri

Önceki bölümde konuşulan ifadeler farklı sınıflara ayrılabilir. Yalnız tamsayı tipleri (`char`, `int`, `long int`, `short int` gibi) içeren ifadelere tamsayı ifadesi (integral expression) denir. İçinde bir işaretçi üzerinde aritmetik işlem yapılıyorsa işaretçi ifadesi (pointer expression), `float` ya da `double` gibi kayan noktalı bir tip varsa kayan noktalı ifade (float expression) denir. Bir sınıf da sabit ifadesidir (constant expression). Hoca bunların şimdilik kritik olmadığını, bilgi olsun diye anlattığını söyledi.
<!-- BELİRSİZ: "constant expression" tanımı altyazıda eksik kaldı (02:15:01-02:15:16). -->

### 16.2 Öncelik ve birleşme yönü

İki kavram vardır: öncelik (precedence) ve birleşme yönü (associativity). Öncelik matematikten bilinir: çarpma sınıfı işlemler toplama sınıfı işlemlerden önce gelir. `2 + 3 * 4` yazıldığında önce `3 * 4` yapılır, sonra 2 ile toplanır.

Birleşme yönü yeni bir kavramdır. Toplama ve çıkarma aynı gruptadır; `a + b - c` yazıldığında önce `a` ile `b` toplanır, sonra `c` çıkarılır; sıra soldan sağadır. C'de atama `=` ile yapılır ve `a = b = c` yazıldığında önce `c` `b`'ye, sonra `b` `a`'ya atanır; bu sağdan soladır.

Slayttaki uzun tabloda bütün operatörler sınıflandırılmış, öncelikleri ve birleşme yönleri verilmişti. Hoca tablonun üzerinden tek tek geçmedi; bilinmesi gerekenin, tabloda önceliğin yukarı doğru arttığı ve aşağı doğru azaldığı, birleşme yönünün de soldan sağa ya da sağdan sola olarak verildiği olduğunu söyledi.
<!-- BELİRSİZ: Öncelik tablosunun içeriği karede okunmadı. -->

> **Hocanın vurgusu:** Bütün bu istisnaları akılda tutmaya gerek yoktur. Akılda tutulması gereken tek şey şudur: her işlemin farklı bir önceliği ve birleşme yönü vardır. İşi sağlama almanın yolu matematikten de bilinen paranteztir. Tablonun en üstünde birincil (primary) kısımda parantez vardır; parantez en yüksek önceliktir ve içi önce yapılır. Farklı işlemler bir arada kullanılırken şaşırmamak için parantez kullanılmalıdır.

### 16.3 Aritmetik operatörler

Çarpma `*`, bölme `/`, kalan (mod) `%`, toplama `+`, çıkarma `-` ile gösterilir. Aritmetik operatörlerin hepsi tamsayı ya da kayan noktalı işlenenlerle kullanılabilir; yalnız kalan operatörü doğası gereği tamsayı işlenenlerle çalışır. Negatif sayılar üzerinde mod alınırsa sonuç farklı sistemlerde farklı olabilir.

> **Hocanın vurgusu:** Mod işlemi her zaman pozitif sayılar üzerinde yapılmalıdır.

> **Ek bilgi (derste anlatılmadı):** Eski C standardında (C89) negatif işlenenli `/` ve `%` sonucunun yönü uygulamaya bırakılmıştı. C99'dan beri tamsayı bölmesi sıfıra doğru keser ve `-7 % 2` sonucu -1 olur.

### 16.4 Bileşik atama

Bir ifadenin sonucu genellikle bir yere atanır; `a` ile `b` toplanacaksa sonuç çoğu zaman `a`'ya ya da `b`'ye, bazen de `c` gibi başka bir değişkene atanır. Sonuç işlenenlerden birine atanacaksa toplama, çıkarma, çarpma, bölme ve hatta mod işlemi atamayla birleştirilebilir: `a = a + b` yerine `a += b`, `a = a * b` yerine `a *= b` yazılır.

Hoca bunun daha hızlı çalışmadığını, bir üstünlüğü olmadığını, tek avantajının klavyede daha az tuşa basılması olduğunu söyledi.

Derste bir örnek tablo gösterildi: değişkenler `m` = 3, `n` = 4, `x` = 2.5, `y` = 1.0. Tablodaki satırlardan biri `m += n + x - y`'dir; açılımı `m = m + (n + x - y)`'dir. Bir diğeri `m /= x * n + y`'dir; önce `x * n` yapılır, `y` ile toplanır, sonra `m` bu değere bölünür. Slaytta her satırın açılımı parantezlerle adım adım gösteriliyordu.
<!-- BELİRSİZ: Bileşik atama tablosunun bütün satırları ve sonuç sütunu karede okunmadı (02:22:57-02:23:47); yalnız altyazıda geçen iki satır alındı. -->

### 16.5 Artırma ve azaltma

Kullanımı güzel ve faydalı olan, ama dikkat isteyen bir operatör artırma (increment) operatörüdür; azaltma (decrement) da vardır. Değer bir artırılır ya da bir azaltılır. Hoca `a = a + 1` ile `a++`'nın sonuçta aynı, ama temelde aynı şey olmadığını söyledi: `a = a + 1` komut kümesindeki `add` komutuyla yapılır ve yerine göre 5, 10, 15 çevrim sürebilir; `a++` ise `increment` komutuyla yapılır ve yaklaşık 1-2 çevrim sürer.

> **Ders sonrası not:** Günümüz derleyicileri `a = a + 1`, `a += 1` ve `a++` için büyük olasılıkla aynı makine kodunu üretir; hız farkı derleyicinin en iyileştirmesine ve işlemciye bağlıdır.

Slayttaki tablo (ekrandan, 02:25:00):

| Operatör | Sembol | Biçim | İşlem |
|---|---|---|---|
| postfix increment | `++` | `a++` | `a`'nın değerini al, sonra `a`'yı artır |
| postfix decrement | `--` | `a--` | `a`'nın değerini al, sonra `a`'yı azalt |
| prefix increment | `++` | `++a` | `a`'yı artır, sonra değerini al |
| prefix decrement | `--` | `--b` | `a`'yı azalt, sonra değerini al |

Slaytta son satırın biçim sütununda `--b` yazıyor, işlem sütunu ise `a` üzerinden anlatılıyordu; kastedilen önek azaltmadır.

Bu operatör başka işlemlerle aynı ifadede kullanılırsa sorun çıkabilir. Hoca slayttaki ilk örneği (`m++` ile `--j`'nin birlikte geçtiği bir ifade) uzun uzun çözmedi: önce `m` artırılıp `j` azaltılacak, sonra işlem yapılacaktı. Asıl önemli olanın şu olduğunu söyledi: bir ifadede farklı işlemlerle artırmayı bir arada kullanmak sorun yaratabilir; bazı durumlarda değer tamamen uygulamaya bağlıdır, çünkü standart bunu tanımlamaz, yalnız sonek biçiminin nasıl çalışacağını tanımlar.
<!-- BELİRSİZ: Slayttaki artırma-azaltma örneklerinin tam ifadeleri ve değerleri karede okunmadı (02:26:18-02:26:51). -->

> **Hocanın vurgusu:** Bilerek böyle bir deyim yazılmasa bile bir makroya `m` yerine `m++` gönderildiğinde, makro içinde parametre `m * m` gibi bir işleme giriyorsa işler karışır. Hoca önce fonksiyon dedi, sonra düzeltti: bu durum fonksiyonda değil makroda olur. Makrolara `m++` gibi parametre göndermekten kaçınılmalıdır.

Virgül operatörü bu derste konuşulmadı; ileride gerektiğinde ele alınacaktı.

### 16.6 İlişkisel operatörler

İlişkisel operatörler kontrol deyimlerinin (`if`, `while`, `for`) içinde kullanılır. Slayttaki tablo (ekrandan, 02:30:00):

| Operatör | Sembol | Biçim | Sonuç |
|---|---|---|---|
| greater than | `>` | `a > b` | `a`, `b`'den büyükse 1, değilse 0 |
| less than | `<` | `a < b` | `a`, `b`'den küçükse 1, değilse 0 |
| greater than or equal to | `>=` | `a >= b` | `a`, `b`'den büyük ya da eşitse 1, değilse 0 |
| less than or equal to | `<=` | `a <= b` | `a`, `b`'den küçük ya da eşitse 1, değilse 0 |
| equal to | `==` | `a == b` | `a`, `b`'ye eşitse 1, değilse 0 |
| not equal to | `!=` | `a != b` | `a`, `b`'ye eşit değilse 1, değilse 0 |

Eşitlik iki eşittir işaretiyle denetlenir, çünkü C'de tek `=` atama içindir. Eşit değil denetimi `!=` ile yapılır.

> **Hocanın vurgusu:** `if` içinde yanlışlıkla `a == b` yerine `a = b` yazılırsa işlemin sonucu `b`'nin değerine bağlı hale gelir. İlişkisel operatörler sayısal bir değer üretir: `a > b` doğruysa 1, değilse 0'dır; sıfırdan farklı bütün değerler koşulun sağlandığı anlamına gelir. `a = 5` yazılırsa `a`'ya 5 atanır, değer 5 olduğu için koşul sağlanmış sayılır; `if` ise doğru dalına girilir, `while` ise döngüden çıkılamayabilir.

Derste `j` = 0, `m` = 1, `n` = -1, `x` = 2.5 değerleriyle şu örnekler çözüldü:

- `j > m`: 0'ın 1'den büyük olması mümkün değildir, sonuç 0'dır. Bu sonucun aritmetik bir karşılığı vardır.
- `m / n < x`: öncelik nedeniyle önce `m / n` yapılır; 1 / -1 = -1 çıkar. -1, 2.5'ten küçük olduğu için sonuç 1'dir.
- `j <= m >= n`: ilişkisel operatörlerde soldan sağa gidilir (atamada sağdan sola gidiliyordu). `j <= m`, yani 0 ≤ 1 doğrudur, sonuç 1'dir. Sonra `1 >= n`, yani 1 ≥ -1 doğrudur ve sonuç 1'dir.

Üç sonuç ajan tarafından gcc ile denetlendi (0, 1, 1). gcc, `j <= m >= n` gibi zincirleme karşılaştırmaların matematikteki anlamını taşımadığı konusunda uyarı verir.

### 16.7 Mantıksal operatörler

Mantıksal operatörler akış diyagramlarında görülen VE (AND) ile VEYA (OR) farkına karşılık gelir. Mantıksal VE için iki ampersand (`&&`), mantıksal VEYA için iki dikey çizgi (`||`, pipe) kullanılır. Hoca dikey çizginin klavyede AltGr ile küçüktür-büyüktür tuşuna basılarak çıkarıldığını söyledi. Semboller ikişer tane yan yana yazılır, çünkü tek başlarına başka bir operatörü gösterirler. Olumsuzlama (negation) `!` ile yapılır: değer 0 ise 1, sıfır dışıysa 0 olur.

Slayttaki örnekler (ekrandan, 02:35:00); değişkenler `int j=0, m=1, n=-1;` ve `float x=2.5, y=0.0;`:

- `j && m` → parantezli biçim `(j) && (m)` → sonuç 0
- `j < m && n < m` → parantezli biçim `(j < m) && (n < m)` → sonuç 1
- `x * 5 && 5 || m / n` → parantezli biçim `((x * 5) && 5) || (m / n)` → sonuç 1
- `!x || !n || m + n` → parantezli biçim ve sonuç slaytta verilmedi

Hocanın çözümleri:

- `j && m`: `m` 1 olduğu için olumlu, `j` 0 olduğu için olumsuzdur; VE'de sonuç 0'dır.
- `j < m && n < m`: önce iki koşul denetlenir. `j < m`, yani 0 < 1 doğrudur ve 1'dir. `n < m`, yani -1 < 1 doğrudur ve 1'dir. İki koşul 1 olduğu için sonuç 1'dir.
- `x * 5 && 5 || m / n`: hoca insan olarak hızlandırmak için önce VEYA'nın sağına baktı: `m / n` = 1 / -1 = -1, sıfırdan farklıdır, yani olumludur; bu yüzden VEYA'nın sol tarafının ne olduğunun önemi yoktur. Ama bilgisayar öncelik ve birleşme yönüne göre gider: önce `x * 5` = 12.5 hesaplanır, `&& 5` ile ikisi de sıfırdan farklı olduğu için 1 olur; VEYA'nın bir tarafı 1 olduğu için diğer tarafa bakmaya gerek kalmaz ve sonuç 1'dir.

Dördüncü ifade için hoca "aynı mantık ve yapı geçerli" dedi ve çözmedi.

> **Hocanın vurgusu:** Bir `if` içinde 10 tane koşul birbirine bağlanmamalıdır; koşullar en fazla 3 ile sınırlandırılmalıdır. 3'ün üstünde bir şey yazılıyorsa yapı yanlış kurulmuştur; 3 bile takip edilebilirlik açısından tehlikelidir. Daha basit tutmak ve mümkünse bölmek gerekir.

### 16.8 Bit düzeyi operatörler

Kaydırma (shift), döndürme (rotate) ve XOR önceki derslerde genel olarak konuşulmuştu; burada C'deki karşılıkları gösterildi:

- Sağa kaydırma `>>`, sola kaydırma `<<`.
- Bit düzeyinde VE `&`, VEYA `|`, XOR `^` (şapka).
- Tümleme (bire tümleyen) `~` (tilde).

Örnekler: 5'i bir kez sola kaydırmak için `5 << 1` yazılır; sola kaydırma 2 ile çarpma mantığıyla gider ve sonuç 10'dur. 255'i üç kez sağa kaydırmak için `255 >> 3` yazılır; sonuç 31'dir (ajan gcc ile denetledi; derste bu iki sonuç söylenmedi).

Kodda yazılan 5, 255, 8, 1 gibi sabitler, yanlarına işaretsiz olduğu yazılmadıkça `int`'tir. 1'i, `int` 16 bitse 15 kez, 32 bitse 31 kez kaydırmak işaret bitini değiştirir ve beklenenden farklı bir değer ortaya çıkar. Bu yüzden kaydırma işlemlerini işaretli değişkenler üzerinde kullanmak sorunludur. Hoca, negatif bir sayıyı (-5) sağa kaydırmanın sonucunun bir uygulamada büyük bir pozitif sayı, başka bir uygulamada -2 olabileceğini söyledi: bazı uygulamalar işaret bitinin kaydırmayla değişmesine izin vermez; sayı negatif ve işaret biti 1 olduğu için soldan 0 değil 1 gelir.
<!-- BELİRSİZ: Slayttaki negatif sayı kaydırma ifadesi ve hocanın söylediği pozitif sonuç ("iki üzeri on üç eksi bir" olarak duyuldu) karede okunmadı. -->

> **Ek bilgi (derste anlatılmadı):** 16 bitlik `-5` (`0xFFFB`) iki bit sağa kaydırılırsa, soldan 0 gelen mantıksal kaydırmada sonuç `0x3FFE` = 16382 = $2^{14} - 2$, işaret bitini koruyan aritmetik kaydırmada -2 olur (ajan gcc ile denetledi). Slayttaki örnek büyük olasılıkla `-5 >> 2` idi.

> **Hocanın vurgusu:** Kaydırma işlemleri `unsigned` değişkenler üzerinde kullanılmalıdır.

Bit düzeyinde VE ve VEYA için slaytta ondalık sayıların onaltılık ve ikilik karşılıkları gösterildi; hepsi 16 bit kabul edilmişti. VE'de bitler sağdan başlanarak eşlenir: 0 ve 0 → 0, 1 ve 1 → 1, 1 ve 0 → 0, 0 ve 1 → 0. VEYA'da 0 ve 0 → 0, diğer bütün durumlarda 1 çıkar.
<!-- BELİRSİZ: VE ve VEYA tablolarının sayıları karede okunmadı (02:38:28-02:39:33). -->

XOR'da bitlerdeki birlerin sayısı çifte tamamlanır: 0 ve 0 → 0, 1 ve 1 → 0, 1 ve 0 → 1, 0 ve 1 → 1. Tümlemede 0 görülen yere 1, 1 görülen yere 0 yazılır. Slayttaki tablolar (ekrandan, 02:40:00):

| İfade | Onaltılık | İkilik |
|---|---|---|
| `9430` | `0x24D6` | `00100100 11010110` |
| `5722` | `0x165A` | `00010110 01011010` |
| `9430 ^ 5722` | `0x328C` | `00110010 10001100` |

| İfade | Onaltılık | İkilik |
|---|---|---|
| `9430` | `0x24D6` | `00100100 11010110` |
| `~9430` | `0xDB29` | `11011011 00101001` |

Bütün değerler ajan tarafından denetlendi (tümleme 16 bit için hesaplandı).

Bit düzeyi operatörlerin hepsi aritmetik operatörlerde olduğu gibi atamayla birleştirilebilir: `a` değişkenini 3 kez sağa kaydırıp `a`'ya atamak için `a = a >> 3` ya da `a >>= 3` yazılabilir. Bu yalnız yazımı kolaylaştırır.

### 16.9 Cast ve sizeof

Cast daha önce konuşuldu: bir değişkenin tipini o an girdiği ifadede değiştirmek için hedef tip parantez içinde önüne yazılır. Bir de `sizeof` operatörü vardır. `int`, `long int`, `short int`, `float`, `double`, `long double` gibi tiplerin boyutu merak ediliyorsa `sizeof` ile öğrenilir. Parametre olarak bir değişken, bir veri tipi ya da bir ifade verilebilir ve bayt cinsinden boyut döndürülür; sonuç ekrana yazdırılabilir. `3 + 5` yazılırsa bunlar tamsayı sabitleri olduğu için `int`'in boyutu, `2.5` yazılırsa `double` olduğu için `double`'ın boyutu, `short` yazılırsa doğrudan o tipin boyutu döner.

Koşul operatörüne (conditional operator) bu derste girilmedi.

## 17. Kontrol Yapıları

Kontrol yapıları olarak önce `if`, sonra `switch`, sonra döngülerden `for`, `while` ve `do-while` ele alındı.

### 17.1 if...else

Akış diyagramlarında doğru (true) ve yanlış (false) olarak ikiye ayrılan `if` yapısı C'de de benzer biçimde kurulur.

> **Hocanın vurgusu:** Hoca akış diyagramı konusunda özellikle vurguladığı hataların sınav kâğıtlarında yine görüldüğünü söyledi: doğru kısmı olmayan `if` akışı çizilmez. Birçok programlama dili buna izin verse de, kod gizleme (code obfuscation) amacı yoksa bu yapılmaz. Bunu yapmak yanlıştır ve öyle değerlendirilir.

C'de önce `if` yazılır, parantez açılır, koşul yazılır, parantez kapatılır. Tek bir deyim varsa o yazılır. Olumsuzluk dalı yoksa başka bir şey yazmaya gerek yoktur; yanlış dalı varsa `else` yazılıp altına deyimi yazılır. Slayttaki sözdizimi şeması: `if` → `(` → expression → `)` → statement, isteğe bağlı olarak `else` → statement (ekrandan, 02:45:00). Slayttaki örnekler:

```c
// Ex1:
if (x)
    statement1;     // executed only if x is nonzero
statement2;         // always executed

// Ex2:
if (x)
    statement1;     // executed only if x is nonzero
else
    statement2;     // executed only if x is zero
statement3;         // always executed
```

Bu örneklerde `if` ve `else`'ten sonra birer deyim vardır. Birden fazla deyim varsa bunlar bir blokta birleştirilmelidir: koşul yazılıp parantez kapatıldıktan sonra açılış süslü parantezi konur, çalışması istenen deyimler yazılır ve kapanış süslü parantezi konur. Süslü parantez olmadan alt alta iki üç deyim yazılırsa yalnız ilki koşula bağlı çalışır.

İç içe istenildiği kadar `if` yazılabilir. `else` kısmı olsun olmasın bir `if` deyiminin tamamı tek bir deyim sayılır; bu yüzden bir `if`'in içine başka bir `if` yazarken süslü parantez kullanmak zorunlu değildir.

> **Hocanın vurgusu:** Bu tür istisnalar her zaman takip edilemediği için tek bir deyim yazılacak olsa bile her zaman süslü parantezle blok oluşturulmalıdır; aksi halde işler karışabilir.

### 17.2 switch

Arka arkaya kontrol edilmesi gereken 6 ya da 7 koşul varsa, örneğin `enum` örneğindeki gibi haftanın hangi günü olduğu (0, 1, 2, 3, 4, 5, 6) kontrol edilecekse, iç içe 7 `if` yazmak yerine bir `switch` deyimi kurulabilir. `day` diye bir değişken varsa `switch (day)` denir; sonra her `case` için (günler `enum` olarak tanımlandıysa 0 yerine büyük olasılıkla `MONDAY` gibi adlar yazılır) ne yapılacağı yazılır. Bu, akışın anlaşılabilirliğini artırır; ayrıca `switch` arka planda daha iyi en iyilenmiş biçimde uygulanır. Bu yüzden uygun yerlerde arka arkaya `if` denetimleri yerine `switch` kullanmak iyidir. Ayrıntısı daha sonraya bırakıldı.

### 17.3 while ve do-while

`while` yazılır, parantez açılır ve içine koşul yazılır. Koşul tek olmak zorunda değildir; akış diyagramında VE ile bağlanan iki koşul burada `&&` ile bağlanır. Sonra döngü gövdesindeki deyimler yazılır; aynı kural geçerlidir: tek deyim varsa bir şey yapmaya gerek yoktur, birden fazla deyim döngüde çalışacaksa süslü parantezle blok yapılmalıdır.

Daha önce `while`'ın daha denetimli olduğu için tercih edildiği söylenmişti. Önce işlemi yapıp sonra koşulu denetleyen `do-while` da vardır, ama hoca bunun hem akışta hem burada kullanılmasını tercih etmediğini söyledi ve üzerinde durmadı.

### 17.4 for

Akış diyagramında `for` bir dörtgen olarak çizilir ve ortadan ikiye bölünür: alt tarafa son sınır, üst tarafın soluna ilk değer ataması (örneğin `i ← 1`), sağına artım yazılır. C'deki `for` döngüsü de üç parçadan oluşur: `for` yazılır, parantez açılır, birinci ifade ilk değer atamasıdır (akıştaki sol kısım; `i`'ye 1, 0 ya da 5 atamak gibi). Noktalı virgülden sonra ikinci kısım döngünün nereye kadar döneceğidir (akışta altta yazılan `n`; `i < n` ya da `i <= n` gibi). Bir noktalı virgülle ayrılan üçüncü kısım döngü değişkeninin nasıl artırılacağıdır. Sonra parantez kapatılır ve gövde yazılır; birden fazla deyim süslü parantezle blok yapılır. Tek deyimde de blok kullanılması tavsiye edildi.

Slayttaki açıklama (ekrandan, 02:50:00):

- Önce `expression1` değerlendirilir.
- Sonra `expression2` değerlendirilir. Bu, deyimin koşul kısmıdır. `expression2` yanlışsa program denetimi `for` deyiminden çıkar; doğruysa gövdedeki deyim çalıştırılır.
- Deyim çalıştırıldıktan sonra `expression3` değerlendirilir.
- Sonra `expression2` yeniden sınanmak üzere başa dönülür.

### 17.5 Boş deyim (null statement)

Normalde bir döngünün koşulu sağlandığı sürece çalıştıracağı bir deyim olması beklenir. Ama yapılacak bir şey yoksa, örneğin bir mikrodenetleyicide bekleme (delay) yaratmak için boş bir döngü kuruluyorsa, gövde deyimi atlanabilir: `for`'un sonuna bir noktalı virgül koymak yeterlidir. Böylece gövde boş bir deyim olur.

C, noktalı virgülün başka yerlere de konmasına izin verir; örneğin `if`'in sonuna konursa (slayttaki örnekte `j`'nin 1'e eşit olduğu koşul) koşul her sağlandığında bir boş deyim çalıştırılır ve tuhaf bir yapı ortaya çıkar.

> **Hocanın vurgusu:** Her deyimin sonuna noktalı virgül koymaya alışılmalı, ama fazla alışıp `for`'un, `if`'in sonuna konmamalıdır; bunlar farklı anlamlara gelir.

> **Ek bilgi (derste anlatılmadı):** `if (j == 1); printf("bir");` yazılırsa `if`'in gövdesi boş deyim olur ve `printf` koşuldan bağımsız olarak her zaman çalışır. Aynı şekilde `for (i = 0; i < n; i++);` satırından sonraki blok döngüye ait olmaz, döngü bittikten sonra bir kez çalışır.

### 17.6 İç içe döngüler

İç içe `if` yazılabildiği gibi iç içe `for`, iç içe `while`, `while` içinde `for`, `for` içinde `while` da yazılabilir; bunların hepsi normaldir. Sık yapılan hata, en dıştaki döngüde kullanılan indisle içteki indisin aynı olmasıdır; birbirinden farklı olmalıdır. Bir başka hata, artım kısmında el alışkanlığıyla dış döngünün indisini yazmaktır: dış döngü `j` ile `j++` yazılmışken iç döngüde `k = 1; k <= 10;` sonrası `k++` yerine yanlışlıkla `j++` yazılırsa sonsuz döngü oluşabilir.

## 18. break, continue ve goto

Slayttaki maddeler (ekrandan, 02:55:00):

- `break`: `switch` deyiminde zaten konuşulmuştur. Bir döngüde kullanıldığında program denetimini döngüden sonraki deyime atlatır.
- `continue`: bir döngünün başına normalden erken dönmeyi sağlar; döngünün geri kalanını bir nedenle atlamak istendiğinde işe yarar. C programlarınızın hiçbirinde kullanmayın.
- `goto`: daha ilkel dillerde gereklidir. C programlarınızın hiçbirinde kullanmayın.

Hoca bunu programlama dillerinin tarihçesi anlatılırken de söylediğini hatırlattı: C, assembly'den biraz sonra geliştirilmiştir. Assembly'de birçok şey atlama (jump) işlemleriyle yapılır; bu yapılar oradan gelen programcıların C'de de yazabilmesi için dile eklenmiştir.

> **Hocanın vurgusu:** `break`, `continue` ve `goto` hiçbir kodda kullanılmamalıdır. Tek istisna `break`'tir: `switch` deyiminin içinde kullanılan bir komut olduğu için yalnız `switch` içinde kullanılabilir. Bunların başka yerde kullanılması hem kullanım hem mühendislik açısından sorunlu ve yanlıştır.

## Örnek Sorular

### Soru 1: Sekizlik ve onaltılık sabitler

(ekrandan, 01:45:00) Aşağıdaki ondalık sayıların C'deki sekizlik ve onaltılık sabit yazımlarını verin: 3, 8, 15, 16, 21, -87, 255.

> **Çözüm (derste slaytta verildi):** 3 → `003`, `0x3`; 8 → `010`, `0x8`; 15 → `017`, `0xF`; 16 → `020`, `0x10`; 21 → `025`, `0x15`; -87 → `-0127`, `-0x57`; 255 → `0377`, `0xFF`. Değerler gcc ile denetlendi.

### Soru 2: Örtük dönüşüm

(ekrandan, 01:55:00) `-3 / 4 + 2.5` ifadesinin değeri nedir? `1 + 2.5` ifadesinde hangi dönüşüm yapılır?

> **Çözüm:** Derste: `3 / 4` iki tamsayının bölümü olduğu için 0'dır, 0.75 değildir. `1 + 2.5` ifadesinde `int` olan 1 `double`'a çevrilir. İfadenin tamamı 2.5 çıkar (ajan gcc ile denetledi).

### Soru 3: Cast

(ekrandan, 02:00:00) `int j=2, k=3; float f;` tanımlarından sonra `f = k / j;` ve `f = (float) k / j;` deyimleri `f`'ye hangi değeri atar?

> **Çözüm:** Derste: birinci deyimde tamsayı bölmesi yapılır, `f` 1.0 olur. İkinci deyimde `k` `float` sayılır, `j` de genişletilir ve `f` 1.5 olur.

### Soru 4: İlişkisel ifadeler

(derste sözlü, 02:30:12) `j = 0`, `m = 1`, `n = -1`, `x = 2.5` için `j > m`, `m / n < x` ve `j <= m >= n` ifadelerinin değeri nedir?

> **Çözüm:** Derste: `j > m` → 0; `m / n` = -1 ve -1 < 2.5 olduğu için `m / n < x` → 1; `j <= m` → 1, sonra `1 >= -1` → 1 olduğu için `j <= m >= n` → 1.

### Soru 5: Mantıksal ifadeler

(ekrandan, 02:35:00) `int j=0, m=1, n=-1; float x=2.5, y=0.0;` için aşağıdaki ifadelerin değerini bulun: `j && m`, `j < m && n < m`, `x * 5 && 5 || m / n`, `!x || !n || m + n`.

> **Çözüm:** Derste ilk üçü için 0, 1, 1 verildi.

> **Çözüm (derste verilmedi):** Dördüncü ifade: `!x` = 0 (`x` sıfır değil), `!n` = 0 (`n` sıfır değil), `m + n` = 1 + (-1) = 0; üç terimin hepsi 0 olduğu için sonuç 0'dır. Dört ifade de gcc ile denetlendi (0, 1, 1, 0).

### Soru 6: XOR ve tümleme

(ekrandan, 02:40:00) 16 bit kabulüyle `9430 ^ 5722` ve `~9430` değerlerini onaltılık ve ikilik olarak bulun.

> **Çözüm (derste slaytta verildi):** `9430` = `0x24D6` = `00100100 11010110`, `5722` = `0x165A` = `00010110 01011010`. `9430 ^ 5722` = `0x328C` = `00110010 10001100`. `~9430` = `0xDB29` = `11011011 00101001`. Değerler denetlendi.

### Soru 7: Bileşik atama

(derste sözlü, 02:23:00) `m = 3`, `n = 4`, `x = 2.5`, `y = 1.0` iken `m += n + x - y` ve `m /= x * n + y` deyimlerinin açılımı nedir?

> **Çözüm:** Derste açılımlar verildi: `m = m + (n + x - y)` ve `m = m / ((x * n) + y)`.

> **Çözüm (derste verilmedi):** `m`'nin tipi slaytta okunamadı; `m` `int` kabul edilirse birinci deyimde 3 + (4 + 2.5 - 1.0) = 8.5 hesaplanır ve `m`'ye atanırken 8 olur. İkinci deyim (`m` yine 3 iken) 3 / (2.5 × 4 + 1.0) = 3 / 11 ≈ 0.27 hesaplar ve `m` 0 olur. Bu değerler ajan tarafından gcc ile `int m` için denetlendi.

## Dersin Toparlaması

Bu derste C ile program yazmanın teorik temeli kuruldu. Kaynak kodun önişlemci, derleme ve bağlama adımlarından geçerek çalıştırılabilir programa dönüşmesi, fonksiyonun yapısı ve `main`'in özel yeri, değişken adlandırma kuralları, lvalue-rvalue ayrımı, kod formatlama ve yorum yazma alışkanlığı anlatıldı. `printf` ve `scanf` ile terminal giriş-çıkışı, `scanf`'in neden adres istediği, `#include` ve `#define` yönergeleri ve Hello World programı gösterildi. Ardından veri tipleri sınıflandırıldı, dokuz ayrılmış sözcük, tamsayı ve kayan noktalı sabitlerin yazımı, örtük ve açık dönüşümler, `enum`, `void` ve `typedef` ele alındı. Son kısımda aritmetik, bileşik atama, artırma-azaltma, ilişkisel, mantıksal ve bit düzeyi operatörler, öncelik ve birleşme yönü, `if`, `switch`, `while`, `for`, boş deyim ve iç içe döngüler işlendi; `break`'in yalnız `switch` içinde kullanılacağı, `continue` ve `goto`'nun hiç kullanılmayacağı vurgulandı.

Bu teorik kısmın uygulaması bir sonraki laboratuvar oturumunda, Ubuntu sanal makineleri üzerinde terminalde yapılacaktı: derlemenin hangi parametrelerle yapılacağı, yalnız derleme adımının çalıştırılması ve yorum satırlarının kullanımı orada canlı olarak gösterilecekti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
