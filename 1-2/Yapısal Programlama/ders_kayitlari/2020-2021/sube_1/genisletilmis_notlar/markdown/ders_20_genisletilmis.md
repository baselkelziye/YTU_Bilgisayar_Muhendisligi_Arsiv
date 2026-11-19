# Ders 20 Genişletilmiş Notu: Bit Alanlı Bağlı Liste, Union, Özyineleme, Fonksiyon İşaretçileri ve Dosya G/Ç'ye Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bit Alanlarına Kısa Dönüş
- 2. Bit Alanlı Yapıyla Bağlı Liste
- 3. Bit Alanı Yapı Dışında Kullanılabilir mi?
- 4. Union (Birlik) Kavramı
- 5. Yapı İçinde Union: Vatandaşlık Örneği
- 6. Örneği Kodlamak
- 7. Özyineleme (Recursion)
- 8. Faktöriyel Örneği ve Taşma
- 9. Fonksiyon İşaretçileri
- 10. Dosya Giriş-Çıkışına Giriş
- Örnek Sorular
- Dersin Toparlaması

## 1. Bit Alanlarına Kısa Dönüş

Ders, önceki hafta ayrıntılı konuşulan bit alanlarının (bit field) kısa bir tekrarıyla açıldı. Hoca, bit alanında asıl öğrenilmesi gerekenin sözdizimi olduğunu söyledi: yapı içindeki bir alanın adından sonra iki nokta üst üste ve o alana ayrılacak bit sayısı yazılır. Slayttaki örnek şudur (ekrandan, 00:05:00):

```c
struct DATE {
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 11;
};
```

Bu alanların bellekte nasıl yerleşeceği tek bir kurala bağlı değildir. Hoca, sonucu etkileyen bileşenleri saydı: arkada çalışan işletim sistemi, derleyicinin ürettiği kod, hatta kodun çalıştığı işlemcinin mimarisi. Bu yüzden yalnız ortak önlemler söylenebilir. Slayttaki iki şekil, aynı yapının iki farklı yerleşimini gösterir. Birinde derleyici alanları en yakın `char` sınırına paketler ve alanların `int` sınırını aşmasına izin verir. Ötekinde en yakın `short` sınırına paketler ve alanlar `int` sınırını aşamaz; her kayıtta boş bitler kalır.

Hocanın önerisi, bit sayılarını 8'in ya da 16'nın katına yaklaştırmak ve alanları dengeli dağıtmaktır. Bunu "terazi dengesi" diye anlattı: iki parçaya bölünecekse bir taraf 9, öteki 11 bit gibi dengeli olsun. Slaytın son maddesi de aynı fikri söyler: en iyi bellek kullanımı için ortamın bazı ayrıntılarını bilmek gerekir, ama alanların sırasını değiştirmek ya da birkaç fazla bit ayırmak gibi önlemler her zaman alınabilir.

## 2. Bit Alanlı Yapıyla Bağlı Liste

### 2.1 Yapının yeni hali

Önceki haftanın çalışan bağlı listesi bu kez bit alanlı bir yapıyla kuruldu. Ekrandaki tanım şudur (ekrandan, 00:15:00):

```c
typedef struct Employee {
    char ps_name[20], ps_tcno[11];
    unsigned int ps_birth_day : 5;
    unsigned int ps_birth_month : 4;
    unsigned int ps_birth_year : 11;
    // pointer to the next element in the linked list:
    struct personalstat *next;
} EMPLOYEE;
```

Hoca alan boyutlarını tek tek gerekçelendirdi. Ad en çok 20 karakter olabilir; daha uzun adlar için ara adın baş harfiyle kısaltma yapılır. Kısa adlarda bu alanda israf olur. TC kimlik numarası herkes için 11 hanedir, bu alanda israf yoktur. Bir ayda en çok 31 gün olduğu için gün alanına 5 bit ($2^5 = 32$), 12 ay için 4 bit ($2^4 = 16$), doğum yılı için 11 bit ($2^{11} = 2048$) yeter. Önceki örnekteki soyad alanı kaldırılıp yerine TC kimlik numarası konmuştu.

Hoca derste yapı adlarıyla biraz uğraştı (önceki kodda tür adı `ELEMENT`, burada `EMPLOYEE`). Sonunda kodun büyük kısmını değiştirmemek için `ELEMENT` adını korudu. Bu karşılaştırmayı kolaylaştırmak için kodu `Project4` adlı yeni bir projeye (`code4.c`) kopyaladı (ekrandan, 00:20:00).

### 2.2 Okuma: geçici değişken neden gerekiyor?

Listenin geri kalanı, yani `add_element`, `insert_after`, `delete_element` ve `find` fonksiyonları, önceki örnekle aynıdır. Slayt bunu "The rest will be very similar to our previous example" diye belirtir (ekrandan, 00:10:00). Değişen asıl kısım eleman oluşturma fonksiyonundaki okumadır (ekrandan, 00:25:00):

```c
printf("Enter tcno of the person:"); scanf("%s", p->ps_tcno);
printf("Enter the birth-date (day) of the person:"); scanf("%u", &val); p->ps_birth_day=val;
printf("Enter the birth-date (month) of the person:"); scanf("%u", &val); p->ps_birth_month=val;
printf("Enter the birth-date (year) of the person:"); scanf("%u", &val); p->ps_birth_year=val;
p->next=NULL; return p;
```

Değer önce `val` adlı geçici bir tamsayıya okunuyor, sonra bit alanına atanıyor. Hocanın koddaki yorumu "ilkel ve bitfield olduğu için geçici değişken şart" idi (ekrandan, 01:20:00). Derste bunun bir denemesini daha önce yaptıklarını, şart olmadığını hatırlar gibi olduğunu ama emin olmadığını söyledi.

> **Ders sonrası not:** Geçici değişken gerçekten gereklidir. Bit alanı bayt sınırında başlamayabileceği için adresi alınamaz. `scanf("%u", &d.day);` gibi bir satır GCC'de `cannot take address of bit-field 'day'` hatasıyla derlenmez (ajan gcc -Wall ile denedi).

Bit alanları `unsigned int` olduğu için yazdırmada `%u` biçimi kullanıldı. Hoca, ekrandaki farkların çoğunun yeni alanlar eklenmesinden geldiğini, bit alanına özgü tek farkın bu geçici değişken olduğunu söyledi.

### 2.3 Çalıştırma ve küçük bir hata

`main` sadeleştirildi: iki çalışan oluşturulup listeye eklendi, sonra liste dolaşılıp yazdırıldı (ekrandan, 00:30:00). Hoca araya üçüncü bir eleman ekleme kısmını da denedi. Bu sırada derleyici `create_list_element` için anlamadığı bir "integer to pointer" uyarısı verdi.

**Soru:** Derleyicinin "cast" dediği nedir? **Cevap:** Cast, tür dönüşümüdür. Örneğin `malloc` bir `void` işaretçi döndürür; bu işaretçi `ELEMENT *` türüne doğrudan atanamadığı için `(ELEMENT*)` ile tür dönüşümü yapılır.

Sorun, bir `for` döngüsünde unutulmuş bir süslü parantezdi; bir öğrenci fark etti. Düzeltmeden sonra program doğru çalıştı. Hoca, sorunu önceden hazırlıklı gelseydi yaşamayacağını söyledi. Bir öğrenci ise canlı hata ayıklamanın da öğretici olduğunu belirtti.

## 3. Bit Alanı Yapı Dışında Kullanılabilir mi?

**Soru:** Bit alanı yapı dışında kullanılabilir mi? **Cevap:** Hocanın bildiği kadarıyla kullanılmaz, çünkü yapı dışında pek anlamı yoktur. Aynı sıkıştırma istenirse iş elle yapılır. Örnekteki 5 + 4 + 11 = 20 bit için platformda bu kadar biti tutacak bir tür seçilir; örneğin `int` yetmiyorsa 32 bitlik `long int`. Sonra bu 20 bitin 32 bitin soluna mı sağına mı yaslanacağına karar verilir ve geri kalan her şey bitsel işlemlerle yazılır. Doğum gününe ulaşmak için ilk 5 biti tamsayıya çeviren, ay için sonraki 4 biti çeviren ayrı fonksiyonlar yazılır. Kod uzar ve zorlaşır. Ama çok kısıtlı bir bellekte çalışılıyorsa ve bir bitin bile tasarrufu önemliyse buna değer.

> **Hocanın vurgusu:** Bitsel işlemlerden ve karmaşık işlemlerden şikâyet eden biri C programcısı olmamalıdır; başka dillerle ve platformlarla uğraşmalıdır.

## 4. Union (Birlik) Kavramı

### 4.1 Tanım ve amaç

Hoca union'ı yapının üstüne bir yenilik daha koyan bir kavram olarak tanıttı ve tanımı iki kez tekrarladı: **aynı bit alanını duruma göre farklı biçimlerde yorumlamak** istiyorsanız union kullanırsınız. Bu sayede daha esnek veri yapıları kurulur; aynı veri yapısı farklı türden veriler taşıyabilir.

### 4.2 Slayt örneği

Slayttaki örnek şudur (ekrandan, 00:40:00):

```c
typedef union
{
    struct
    {
        char c1, c2;
    } s;
    long j;
    float x;
} U;

U example;
```

Union içinde yazılan her satır, o bellek alanının ayrı bir yorumlanma biçimidir. Burada üç satır vardır: bir yapı, bir `long` ve bir `float`. Yani bu alan bir iki karakterlik yapı, bir tamsayı ya da bir ondalıklı sayı olarak kullanılabilir. En geniş üye `float`'tur; `long` da ona eşittir (4 bayt). İki karakterlik yapı ise 2 bayttır. Union için en geniş üyeyi kapsayacak kadar, yani 4 baytlık bir alan açılır. Slayttaki şekil bunu gösterir: 1000-1003 adreslerinde `c1` ve `c2` ilk iki baytı, `j` ve `x` dört baytın hepsini kaplar.

> **Ders sonrası not:** Slayttaki 4 baytlık `long` hesabı Windows ya da 32 bit sistemler içindir. 64 bit Linux'ta `long` 8 bayttır ve `sizeof(U)` 8 çıkar (ajan gcc ile denedi).

### 4.3 Kullanım

Slayttaki kullanım (ekrandan, 00:40:00):

```c
example.s.c1 = 'a';
example.s.c2 = 'b';
```

Bu iki satır, ilk bayta `'a'`, ikinci bayta `'b'` karakterinin ASCII kodunu yazar. Diğer iki baytın bu yorumda anlamı yoktur. Daha önce yazılmadıysa rastgele (çöp) değer taşırlar; bellek `calloc` ile ayrıldıysa sıfırdır. Bu alan `long` olarak yazdırılırsa, ilk bit 0 olduğu için büyük olasılıkla pozitif bir sayı görülür. `printf`'te farklı biçim belirteçleriyle aynı baytlar farklı biçimlerde de yazdırılabilir.

> **Ders sonrası not:** Hoca küçük `a`'nın ASCII kodu için "92 filandı galiba" dedi. Doğrusu `'a'` = 97, `'b'` = 98'dir. Büyük `'A'` = 65 doğru söylendi.

Sonra slayttaki atama yapılır:

```c
example.j = 5; //overwrites the 2 chars, using all 4 bytes to store value 5.
```

`j` bir `long` olduğu için bütün alanı doldurur. 5 değeri `long`'a çevrilir: baştaki bütün bitler 0 olur, en sondaki üç bit `101` olur. Böylece `'a'` ve `'b'` silinir. Bu karakterler yazdırılmak istenirse, yerlerinde artık anlamsız karakterler vardır.

Hoca sonucun bayt sırasına göre değişebileceğini de söyledi: bayt sırası öteki türlü olursa `c1` yine 0 olacak, ama `c2` ASCII kodu 5 olan karakter olacaktır.

> **Ders sonrası not:** Hoca iki durumu ters söylemiş görünüyor. x86 gibi küçük sonlu (little-endian) bir işlemcide sayının en düşük baytı ilk adrestedir, bu yüzden `j = 5` sonrası `c1` = 5, `c2` = 0 olur (ajan gcc ile derleyip çalıştırdı). Büyük sonlu (big-endian) bir işlemcide 5 son bayttadır ve `c1` ile `c2`'nin ikisi de 0 olur.

> **Ek bilgi (derste anlatılmadı):** Bayt sırası (endianness), çok baytlı bir sayının baytlarının bellekte hangi sırayla tutulduğudur. Küçük sonlu (little-endian) sistemde en düşük anlamlı bayt en küçük adrestedir; Intel ve AMD işlemciler böyledir. Büyük sonlu (big-endian) sistemde en yüksek anlamlı bayt en küçük adrestedir. Union ile aynı baytları farklı türlerden okumak bu yüzden taşınabilir değildir.

Hoca bu örneğin uç bir senaryo olduğunu söyledi. Union'ın verdiği bu esneklik işe yarıyorsa kullanılır, yaramıyorsa kullanılmaz.

## 5. Yapı İçinde Union: Vatandaşlık Örneği

### 5.1 İhtiyaç

Hoca union'ın amacını gerçek bir örnekle bağladı. Çalışanlar arasında yabancı uyruklu olanlar da olabilir. Onlar için TC kimlik numarasına gerek yoktur, pasaport numarası gerekir. Union bilinmeseydi ne yapılırdı? Belki hem TC kimlik numarası hem pasaport numarası için ayrı alan açılırdı. Kişinin vatandaş olup olmadığı ayrı bir mantıksal (boolean) alanla tutulabilirdi. Ya da şöyle bir kural konabilirdi: pasaport alanı boşsa kişi TC vatandaşıdır, TC kimlik alanı boşsa yabancıdır. Ama iki alan da boşsa ne olacak? Böyle belirsizlikler çıkar.

Union ile şu söylenir: TC vatandaşları için ayrılan 11 haneli alan öyle kalsın, kişi yabancıysa aynı alana pasaport numarası yazılsın. Ama her durumda o alanın hangi anlamda kullanıldığını ayırt etmek gerekir. Bu yüzden kişinin vatandaş olup olmadığı da bir yerde saklanmalıdır.

Slayttaki istek şudur (ekrandan, 00:45:00): PERSONALSTAT örneğine (ad, TC no, doğum tarihi) şu bilgiler eklenecek: TC vatandaşı mısınız? Vatandaşsanız hangi şehirde doğdunuz? Vatandaş değilseniz uyruğunuz nedir?

### 5.2 İsrafçı ilk tasarım

İlk tasarım iki ayrı dizi kullanır (ekrandan, 00:45:00):

```c
typedef struct {
    unsigned int day : 5;
    unsigned int month : 3;
    unsigned int year : 11;
} DATE;

typedef struct {
    char ps_name[20], ps_tcno[11];
    DATE ps_birth_date;
    // Bit field for TC citizenship:
    unsigned int TCcitizen : 1;
    char nationality[20];
    char city_of_birth[20];
} PERSONALSTAT;
```

Slaytın notu: bu tanım her kayıtta ya uyruk ya doğum şehri için belleği boşa harcar. Her kayıt için iki 20 baytlık dizi ayrılır ve bunlardan biri tümüyle çöpe gider.

Hoca slayttaki ay alanının 3 bit yazıldığını fark etti ve 12 ay için 4 bit gerektiğini söyledi. Koddaki tanımda `month : 4` kullanıldı (ekrandan, 01:15:00).

### 5.3 Union'lı tasarım

Daha iyi tasarım iki diziyi bir union içinde birleştirir (ekrandan, 01:05:00):

```c
typedef struct {
    char ps_name[20], ps_tcno[11];
    DATE ps_birth_date;
    unsigned int TCcitizen : 1;
    union {
        char nationality[20];
        char city_of_birth[20];
    } location;
} PERSONALSTAT;
```

Böylece 20 bayt kazanılır. Bir bitlik `TCcitizen` alanı hizalama sorununa yol açıp bellek kaybettirebilir. Ama `unsigned int` en çok birkaç baytlık kayba yol açar, 20 bayt ise kesin kazançtır; günün sonunda kârdadır.

> **Ders sonrası not:** Hoca bir bitlik alanın en çok 2 bayt kaybettireceğini söyledi. GCC ile denendiğinde (64 bit Linux) iki ayrı diziyle yapı 80 bayt, union'lı yapı 60 bayt çıktı; kazanç tam 20 bayttır. Bit alanının hizalamaya etkisi derleyiciye bağlıdır.

`TCcitizen` bayrağı union içine konamaz. Union'da her satır ayrı bir yorumdur, yani aynı anda yalnız biri geçerlidir. Bayrağın ise şehir ya da uyruk bilgisinden hangisi kullanılıyorsa onun yanında her zaman bulunması gerekir.

**Soru:** "Ortak kullanabilirim" derken, iki farklı kişinin bilgilerini aynı diziye koyup farklı farklı çağırabilir miyim demek mi istiyorsunuz? **Cevap:** Aynı dizide hem TC vatandaşı olanlar hem olmayanlar bulunacak; hepsi `PERSONALSTAT` türünden kayıtlardır. Erişirken önce kişinin vatandaş olup olmadığına bakılır. Vatandaşsa "bu kişi şu şehirde doğmuştur" denir ve kimlik alanı TC kimlik numarası olarak okunur. Değilse "bu kişinin uyruğu şudur" denir ve aynı alan pasaport numarası olarak okunur. Kazanç şudur: vatandaşlar için ayrı şehir bilgisi, yabancılar için ayrı uyruk bilgisi tutmak yerine ikisi birleşti; bu kısım her kayıtta ortak kullanılır.

## 6. Örneği Kodlamak

### 6.1 Tarihi ayrı yapıya çıkarmak

Hoca adım adım ilerlemeyi seçti. Önce doğum tarihi bit alanlarını ayrı bir `DATE` yapısına çıkardı ve yapıya `DATE ps_birth_date;` alanını koydu. Derlenince beklenen hatalar geldi: artık `ps_birth_day` diye bir alan yoktu. Erişim şöyle değişti (ekrandan, 01:20:00):

```c
printf("Enter the birth-date (day) of the person:"); scanf("%u", &val);
p->ps_birth_date.day=val;
```

Hoca bir yerde `ps_birth_date` için de ok kullanıp hata aldı. Kural şudur: `p` işaretçi olduğu için `p->`, `ps_birth_date` ise işaretçi değil yapı değişkeni olduğu için `.ps_birth_date.day`. Aynı düzeltme yazdırma fonksiyonlarına da yapıldı. Ortaya eleman ekleme kısmı yoruma alındı, çünkü daha önce çalıştığı görülmüştü. İki kayıtla çalıştırılınca tarih yapısının doğru işlediği görüldü.

> **Hocanın vurgusu:** Kendinize güvenmiyorsanız adım adım ilerlemek en iyisidir. Her küçük değişiklikten sonra derleyip deneyin.

### 6.2 Bayrak ve union eklemek

Sonra bayrak ve union eklendi (ekrandan, 01:15:00):

```c
struct personalstat {
    char ps_name[20], ps_tcno[11];
    DATE ps_birth_date;
    unsigned int TCcitizen : 1;
    union{
        char nationality[20];
        char city_of_birth[20];
    } location;
    // pointer to the next element in the linked list:
    struct personalstat *next;
};
```

`TCcitizen` 1 ise kişi TC vatandaşı, 0 ise değildir. Hoca burada bir varsayılan değer tartışması yaptı. Çalışanların büyük çoğunluğunun TC vatandaşı olması beklenir, yani mantıklı varsayılan "vatandaş"tır. Sayısal alanlara değer verilmezse varsayılan 0 olabilir; bu durumda bayrağın adı `IsForeigner` olsaydı varsayılan daha uygun düşerdi. Ama hoca, yalnız varsayılan uygun olsun diye kodu baştan değiştirmeye gerek görmedi. İlk değer atamanın önemi zaten dersin başından beri vurgulanır. Mantığın düz kurulması da yararlıdır: `TCcitizen` 1 ise vatandaştır.

### 6.3 Okuma

Eleman oluşturma fonksiyonuna vatandaşlık sorusu eklendi (ekrandan, 01:20:00):

```c
printf("Is this a Turkish citizen? (y/n) "); scanf("%s",&c);
if( c == 'n' || c == 'N' ) {  //foreigner
    ...
}
```

Hoca `char c` değişkenine `%s` ile okumanın, fazla karakter girilirse taşmaya yol açıp açmayacağını sordu ve bu aşamada önemli olmadığını söyledi.

> **Ders sonrası not:** Taşma olur. `%s`, girilen karakterin arkasına bir de `'\0'` yazar, yani tek karakter girilse bile `c`'nin sığdığı 1 baytın dışına en az 1 bayt yazılır. Tek karakter okumak için `scanf(" %c", &c);` kullanılmalıdır; baştaki boşluk önceki satırdan kalan Enter'ı atlar.

Kimlik numarası sorusu `tcno/passport no` diye değiştirildi. Kişi yabancıysa uyruğu `p->location.nationality` alanına, değilse doğum şehri `p->location.city_of_birth` alanına okunur ve `TCcitizen` 0 ya da 1 yapılır. `location` işaretçi olmadığı için ona nokta ile erişilir. Hoca, iki dizi de aynı alanı paylaşan 20 karakterlik diziler olduğu için hangi adla okunduğunun aslında fark etmeyeceğini de belirtti. Slayttaki iki `char` ile bir tamsayı örneğindeki gibi farklı türler söz konusu değildir.

<!-- BELİRSİZ: Yabancı ve vatandaş dallarındaki printf/scanf satırlarının tam metni karelerde görünmüyor; altyazıdan "What is the nationality of the person" ve "What is the birth city of this person?" mesajları anlaşılıyor. -->

### 6.4 Yazdırma

Yazdırma fonksiyonu bayrağa göre iki dala ayrıldı (ekrandan, 01:30:00):

```c
void printElementP( ELEMENT *emp ) {
    if( emp->TCcitizen == 1 ) {
        printf("Turkish Employee %s %s born in %d.%d.%d in %s\n", emp->ps_tcno, emp->ps_name,
            emp->ps_birth_date.day, emp->ps_birth_date.month, emp->ps_birth_date.year,
            emp->location.city_of_birth );
    }
    else {
        printf("%s Employee %s %s born in %d.%d.%d\n", emp->location.nationality,
            emp->ps_tcno, emp->ps_name,
            emp->ps_birth_date.day, emp->ps_birth_date.month, emp->ps_birth_date.year);
    }
}
```

Vatandaşlar için doğum şehri yazılır. Yabancılar için uyruk yazılır, doğum şehriyle ilgilenilmez. Liste yazdırma fonksiyonu `printList` da aynı biçimde değiştirildi: ortak bilgiler yazıldıktan sonra bir `if` ile ya " born in <şehir>" ya uyruk eklenir.

Program bir Türk ve bir İngiliz çalışan girilerek denendi. Çıktıda ilk kayıt "Turkish Employee ... born in ... in <şehir>", ikincisi "British Employee ..." biçiminde doğru yazıldı.

## 7. Özyineleme (Recursion)

### 7.1 Tanım ve durma noktası

Bir fonksiyon kendini çağırıyorsa buna özyineleme denir. Slayttaki ilk örnekte fonksiyonun içinde `static` bir sayaç değişkeni 1 değeriyle tanımlanır. Fonksiyon sayıyı yazar, sayacı bir artırır ve yeniden kendini çağırır.

<!-- BELİRSİZ: Static sayaçlı özyineleme slaytının karesi yok; kodun tam yazımı ekrandan doğrulanamadı. Anlatım altyazıdan kuruldu. -->

Hoca `static` anahtar kelimesini hatırlattı. Fonksiyon içinde `static` tanımlanan değişken, fonksiyon her çağrıldığında bir önceki değerini korur. `static` yazılmasaydı her çağrıda sayaç yeniden 1 olurdu. Burada 1 yazılır, sayaç 2 olur, fonksiyon yeniden çağrılır; 2 yazılır, 3 olur; böyle devam eder.

Ne zamana kadar? Bellek sınırsız olsaydı sonsuza kadar. Her çağrıda bellekte yeni bir alan açılır: çağıran fonksiyonun durum bilgisi yığına (stack) itilir ve yeni fonksiyon için yer ayrılır. Çağrılan fonksiyon dönünce yığından geri alınır (pop) ve çağıran fonksiyonun değişkenlerine dönülür. Bu örnekte hiç dönüş olmadığı için yığın belleği bitene kadar çağrı sürer, sonunda program hatayla durur.

> **Hocanın vurgusu:** Özyinelemeli fonksiyonlarda mutlaka uygun bir durma (sonlanma) noktası konmalıdır.

### 7.2 Yığın düzeni

Slayt, çağrıların yığında nasıl yer aldığını üç şekille gösterir (ekrandan, 01:40:00):

- (a) Program `main()` ile başlayınca, `main` içinde tanımlanan bütün değişkenler için yığında yer ayrılır.
- (b) `main`, `func1()`'i çağırınca yığının üstüne `func1`'in değişkenleri için ek alan ayrılır. `main`'in `func1`'e verdiği parametreler de yığında saklanır.
- (c) `func1` dönünce onun yerel değişkenlerinin alanı bırakılır ve yığının tepesi ilk konumuna döner.

Hoca yığın veri yapısını hatırlattı: yalnız en üstteki öğeye erişilir, alttakilere gidilemez. `func1` içinde bir `func2` çağrılsaydı, `func2`'nin parametreleri ve değişkenleri için yığının üstüne bir alan daha eklenirdi. Bu alan iç içe çağrılarla dolar, fonksiyonlar bittikçe boşalır.

Slaytın son maddesi önemlidir: yığın alanı program çalışırken tekrar tekrar kullanılır, bu yüzden bu alanda ayrılan bellek önceki kullanımdan kalan çöp değerler içerir. Hoca bunu `malloc` ile ayrılan bellekte farklı farklı değerler görülmesine bağladı.

> **Ders sonrası not:** Hoca bu alan için bir yerde "heap memory diye de diyordu" dedi. Fonksiyon çağrılarının kullandığı alan yığındır (stack). Heap, `malloc` ve `calloc` ile ayrılan dinamik bellek bölgesidir.

### 7.3 Özyineleme ne zaman kullanılır?

Bazı problemler özyinelemeli düşünülünce daha doğal çözülür; o zaman özyineleme kullanılmalıdır. Hoca kendisine düz (iteratif) düşünmenin hep daha kolay geldiğini, bunun da insanın hangi yeteneğini çok kullanırsa ona alışmasından kaynaklanabileceğini söyledi. Ama hızlı sıralama (quicksort) gibi, karmaşıklığı $O(n^2)$'den iyi olan $O(n \log n)$ sıralama algoritmaları dahil, bazı algoritmalarda özyineleme ciddi performans kazancı sağlar. Bu tür algoritmaları düşünüp kodlamak biraz daha zordur.

## 8. Faktöriyel Örneği ve Taşma

### 8.1 Özyinelemeli tanım

Faktöriyel $n! = n \cdot (n-1) \cdots 1$ ya da tersinden $n! = 1 \cdot 2 \cdots n$ biçiminde yazılır. Bir adımın değeri kendinden önceki adımlar cinsinden ifade edilebiliyorsa, problem özyinelemeli çözüme uygundur: $n! = n \cdot (n-1)!$. $n = 1$ için sonuç 1'dir; bu hem taban durum hem uygun bir durma noktasıdır.

Slayttaki kod şudur (ekrandan, 01:45:00):

```c
int fact( int n ) {
    if( n <= 1 )
        return 1;
    else
        return n*fact(n-1);
}
main() {
    printf("5! is %d\n", fact(5));
}
```

### 8.2 fact(5) adım adım

Slayttaki şemaya ve hocanın anlatımına göre (ekrandan, 01:45:00):

- Adım 1: `main`, `fact(5)`'i çağırır. $n = 5$, $5 \le 1$ değil; `5 * fact(4)` hesaplanmalıdır.
- Adım 2: `fact(4)` çağrılır. $4 \le 1$ değil; `4 * fact(3)`.
- Adım 3: `fact(3)` çağrılır; `3 * fact(2)`.
- Adım 4: `fact(2)` çağrılır; `2 * fact(1)`.
- Adım 5: `fact(1)` çağrılır. $1 \le 1$ olduğu için 1 döner (Adım 6).
- Adım 7: `fact(2)` $2 \cdot 1 = 2$ döndürür.
- Adım 8: `fact(3)` $3 \cdot 2 = 6$ döndürür.
- Adım 9: `fact(4)` $4 \cdot 6 = 24$ döndürür.
- Adım 10: `fact(5)` $5 \cdot 24 = 120$ döndürür.

Hoca bu anlatım sırasının kodun akış sırası olduğunu, arkada her çağrının yığına bir çerçeve eklediğini hatırlattı.

### 8.3 Derste çalıştırma ve taşma

Hoca kodu yazıp çalıştırdı; `5!` 120 olarak doğru hesaplandı. Sonra faktöriyelin çok hızlı büyüdüğünü hatırlattı: $6! = 720$ ve sayılar hızla `int` sınırına yaklaşır. Bu durumda yığın tükenmez ve program büyük olasılıkla çökmez. Ama sonuç `int`'in sınırlarından büyük olduğu için bitler farklı yorumlanır ve doğru olmayan bir sonuç üretilir.

`fact(15)` ile denendi; ekranda `15! is 2004310016` çıktı (ekrandan, 01:50:00). Hoca bilimsel hesap makinesiyle baktı: gerçek değer 13 basamaklıdır ve `int` sınırını çok aşar. Program patlamadı, ama sonuç yanlıştır.

Doğrulama: $15! = 1\,307\,674\,368\,000$. 32 bitlik bir `int`, bu değerin $2^{32} = 4\,294\,967\,296$'ya göre kalanını tutar:

$$1\,307\,674\,368\,000 \bmod 2^{32} = 2\,004\,310\,016$$

Bu, ekrandaki değerle aynıdır (python ile doğrulandı).

> **Ders sonrası not:** Hoca 10! ve 15! değerlerinin `int` alanını aşacağını söyledi. $10! = 3\,628\,800$ ve $12! = 479\,001\,600$ 32 bitlik `int`'e ($2^{31} - 1 = 2\,147\,483\,647$) sığar. Taşma 13!'te başlar: $13! = 6\,227\,020\,800$, `int`'te $1\,932\,053\,504$ olarak görünür.

Aşağıdaki tam program slayttaki fonksiyonu kullanır. Slayttaki `main()` dönüş türü yazılmadan tanımlanmıştı; burada `int main(void)` yazıldı. Ajan bu programı gcc -Wall ile derleyip çalıştırdı; çıktı `5! is 120` ve `15! is 2004310016` oldu:

```c
#include <stdio.h>

int fact(int n) {
    if (n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main(void) {
    printf("5! is %d\n", fact(5));
    printf("15! is %d\n", fact(15));
    return 0;
}
```

### 8.4 Alıştırmalar

Slayt, evde çözülmek üzere başka özyineleme örnekleri bırakır (ekrandan, 01:45:00): Fibonacci sayıları ($F_{n+1} = F_n + F_{n-1}$), ikili arama ve derinlik öncelikli arama. Hoca ikili aramayı hatırlattı: sıralı dizinin ortasına bakılır; aranan eleman ortadakiyse iş biter, ondan küçükse dizinin sol yarısında, büyükse sağ yarısında aynı arama yapılır. Bu yapı doğal olarak özyinelemelidir. Derinlik öncelikli arama ağaçlarda bir arama algoritmasıdır ve Veri Yapıları dersinden sonra kodlanabilir. Hoca ayrıca Fahri Vatansever'in soru kitabındaki <!-- BELİRSİZ: altyazıda "Fahri Vatan Sıra Hoca'nın soru kitabı"; yazar adı bağlamdan tahmin edildi. --> iteratif algoritmaların ve sayısal analiz türü derslerdeki yinelemeli yöntemlerin (ikinci dereceden bir denklemin çözümü için bir ilk tahminle başlayıp her yinelemede iyileştirme gibi) özyinelemeli olarak yazılmaya çalışılabileceğini söyledi.

## 9. Fonksiyon İşaretçileri

### 9.1 Motivasyon

Fonksiyon işaretçileri, farklı problemleri daha esnek çözmeyi sağlar. Hoca bunların ek bir karmaşıklık getirdiğini, ama zor problemlerin çözümü için kabul edilebilir bir karmaşıklık olduğunu söyledi. Fonksiyon işaretçisi, yazılan bir fonksiyonu programatik biçimde başka bir fonksiyona aktarmayı ve onun üzerinde işler yapmayı sağlar. Slayt da şöyle der: bazı fonksiyonlar fonksiyon işaretçileri yoluyla başka fonksiyonlara argüman olarak verilebilir; bu, kodlamada esnekliğe yeni kapılar açar (ekrandan, 02:05:00).

Hocanın örneği Java'daki `+` operatörüydü. Operatörün iki yanında da sayı (int ya da float) varsa aritmetik toplama yapar. Metin (String) varsa metinleri birleştirir. C'de böyle bir esneklik isteniyor diyelim: bir metin dosyası okunuyor ve içindeki ifadeler çalıştırılıp sonuç ekrana yazılacak. Bir satırda `3+5`, ötekinde `Yunus+Emre` yazıyor. Program hem bir aritmetik toplama fonksiyonuna hem bir metin birleştirme fonksiyonuna sahip olur. Öğelerin ikisi de sayıysa değerlendirmeyi yapacak fonksiyona aritmetik toplama fonksiyonu, değilse birleştirme fonksiyonu iletilir.

### 9.2 Tanım

Slayttaki tanım şudur (ekrandan, 02:05:00):

```c
int (*pf) (); // pf is a pointer to a function returning an int.
int *pf();    // this is a function allusion returning an int pointer
```

`pf` (pointer to function) adı parantez içine alınır, önüne `*` konur. Başa yazılan `int`, işaret edilen fonksiyonun tamsayı döndürdüğünü söyler. `*pf` etrafındaki parantezler doğru gruplama için gereklidir. Parantez yazılmazsa ikinci satırdaki gibi, `int` işaretçisi döndüren bir fonksiyonun ön bildirimi (allusion) elde edilir.

Hoca, parametrelerin bu tanımda belirtilmediğini ve sonradan halledilebildiğini söyledi; `printf`'in değişken sayıda parametre alabilmesini örnek verdi. Ama işaret edilen fonksiyonun **dönüş türü bilinmelidir**: fonksiyon `void` döndürüyorsa `void`, `int` döndürüyorsa `int`, `double` döndürüyorsa `double` türünden bir fonksiyon işaretçisi tanımlanmalıdır.

### 9.3 Dönüş türlerinin uyumu

Fonksiyon başka bir C dosyasında tanımlanmış olabilir. `include` ile eklendikten sonra o fonksiyonlara da işaretçi tanımlanabilir. Slayttaki örnek (ekrandan, 02:10:00):

```c
extern int   if1(), if2(), (*pif)();
extern float ff1(), (*pff)();
extern char  cf1(), (*pcf)();

int main( ) {
  pif = if1;  // Legal:   Types match
  pif = cf1;  // ILLEGAL: Type mismatch
  pff = if2;  // ILLEGAL: Type mismatch
  pcf = cf1;  // Legal:   Types match
  if1 = if2;  // ILLEGAL: Assign to a constant
}
```

İlk satırda `int` döndüren iki fonksiyon (`if1`, `if2`) ve `int` döndüren fonksiyona bir işaretçi (`pif`) tanımlanır. Benzer biçimde `float` ve `char` için de fonksiyon ve işaretçi vardır. `pif`'e `if1` ya da `if2` atanabilir; `pif` çağrıldığında hangisi atanmışsa o çalışır.

- `pif = if1;` geçerlidir, türler uyuşur.
- `pif = cf1;` geçersizdir. `int`, `char`'dan daha geniş olsa da C burada otomatik dönüşüm yapmaz; hoca bunu C'nin türleri sıkı denetlemesine bağladı.
- `pff = if2;` geçersizdir; `float` döndüren işaretçiye `int` döndüren fonksiyon atanamaz.
- `pcf = cf1;` geçerlidir.
- `if1 = if2;` geçersizdir. Fonksiyon adları elle tanımlanmış sabitlerdir (constant) ve birbirine atanamaz.

### 9.4 İşaretçi üzerinden çağırma

Slayttaki örnek (ekrandan, 02:20:00):

```c
#include <stdio.h>
extern int f1(int); //could be defined externally but we have coded it below
int main() {
    int n;
    int (*pf) ();
    int answer;
    printf("Bir sayi giriniz: "); scanf("%d",&n);

    pf=f1;
    answer=(*pf)(n); // calls f1() with argument a => f1(a)

    printf("%d", answer);
    return 0;
}
int f1( int a ) {
    return a+1;
}
```

`f1` fonksiyonu işaretçiye atanır: `pf = f1;`. Çağırma işaretçi üzerinden yapılır: `(*pf)` parantez içinde yazılır, ardından argüman listesi gelir. Fonksiyon parametre almasaydı yalnız `()` yazılırdı; burada bir tamsayı beklediği için `n` verilir. `(*pf)(n)` çağrısı `f1(n)` ile aynıdır. Hoca "madem aynı, neden uğraşıyoruz?" sorusuna, baştaki `+` operatörü örneği gibi farklı amaçlarla çağrılabilecek işler için diye cevap verdi.

### 9.5 Derste genişletilen örnek

Hoca örneği Dev-C++'ta çalıştırdı; 98 girişine 99 çıktı. Sonra bir azaltan `f2` ve iki parametre alıp toplayan `f3` fonksiyonlarını ekledi (ekrandan, 02:15:00). Aynı `pf` işaretçisine sırayla `f1`, `f2` ve `f3` atandı. 5 ve 3 girişleriyle çıktılar 6 (bir fazlası), 4 (bir eksiği) ve 8 (toplam) oldu. Hoca şunu vurguladı: üç fonksiyonun parametre listesi farklıdır, ama dönüş türleri ortak olduğu için hepsi aynı türden fonksiyon işaretçisine atanıp onun üzerinden çağrılabildi.

> **Ders sonrası not:** Bu yalnız parametre listesi boş bırakılmış `int (*pf)();` bildirimiyle ve eski C standartlarında çalışır. GCC 15 varsayılan olarak C23 standardını kullanır. C23'te `()` "parametresiz" demektir ve derste yazılan kod derlenmez (ajan denedi; `-std=c17` ile derlendi ve 6 ile 8 verdi). Taşınabilir yol, her imza için ayrı işaretçi tanımlamaktır.

Aşağıdaki program dersteki örneğin bu düzeltmeyle yazılmış halidir. Derste yazılan kodun birebir kopyası değildir. Ajan programı gcc -Wall ile derleyip `5 3` girişiyle çalıştırdı; çıktı 6, 4 ve 8 oldu:

```c
#include <stdio.h>

int f1(int a) { return a + 1; }
int f2(int a) { return a - 1; }
int f3(int a, int b) { return a + b; }

int main(void) {
    int n, m;
    int (*pf)(int);           /* tek int parametreli fonksiyonlar icin */
    int (*pf2)(int, int);     /* iki int parametreli fonksiyon icin */

    printf("Bir sayi giriniz: ");
    scanf("%d", &n);
    pf = f1;
    printf("%d\n", (*pf)(n));      /* f1(n) ile ayni */
    pf = f2;
    printf("%d\n", (*pf)(n));      /* f2(n) ile ayni */

    printf("Bir sayi daha giriniz: ");
    scanf("%d", &m);
    pf2 = f3;
    printf("%d\n", (*pf2)(n, m));  /* f3(n, m) ile ayni */
    return 0;
}
```

### 9.6 Nerede işe yarar?

**Soru:** Fonksiyon işaretçileri tam olarak hangi durumlarda daha kullanışlı olur? **Cevap:** Genel (jenerik) kod yazmaya çalışırken, yani farklı türden elemanlara hitap eden ortak kod yazarken. Örneğin yalnız tamsayı tutan bir bağlı liste ile karakter tutan bir bağlı liste için ayrı kodlar gerekir. Bunların hepsinin üzerinde dolaşıp elemanlarını listeleyecek bir kod yazmak istenirse, her türe bağlı ayrı fonksiyonlar yazılıp her çağrıda ilgili fonksiyonun çağrılması gerekir. Oysa ayrı bir kütüphanede tek bir dolaşma ve listeleme fonksiyonu olsun ve iş tek çağrıyla halledilsin istenir. O zaman önce fonksiyon işaretçisi tanımlanır, o türün yazdırma fonksiyonu atanır, sonra çağrılır.

Hoca bu örneği kendisi de yeterli bulmadı. Daha iyi örnek için Java'daki generic yapılara ve reflection yeteneklerine geçmek gerektiğini, bunun da dersin kapsamı dışında kaldığını söyledi. Derste gösterilen örneğin yalnız neyin nasıl yapılabileceğini anlattığını, nerede gerçekten işe yaradığını anlatmadığını belirtti.

> **Ek bilgi (derste anlatılmadı):** C standart kütüphanesindeki `qsort` fonksiyonu, fonksiyon işaretçisinin bu "genel kod" kullanımının yaygın bir örneğidir. Son parametresi `int (*compar)(const void *, const void *)` türünde bir karşılaştırma fonksiyonudur. Aynı `qsort` kodu, verilen karşılaştırma fonksiyonuna göre tamsayı, metin ya da yapı dizilerini sıralayabilir.

## 10. Dosya Giriş-Çıkışına Giriş

### 10.1 Taşınabilirlik sorunu

Dersin son bölümünde dosya giriş-çıkışının (I/O) teorisine ve temel kavramlarına girildi; kod örnekleri sonraki derse bırakıldı. Slayt şöyle başlar (ekrandan, 02:25:00): işletim sistemleri dosyalardaki ve aygıtlardaki veriye erişim biçiminde çok farklıdır. Bu çeşitlilik, taşınabilir I/O programları tasarlamayı son derece zorlaştırır. C gibi çalıştığı platformun ayrıntılarına çok bağlı bir dilde bu daha da zordur.

Ama her uygulamada verinin kalıcılığını sağlamak, yani diske yazmak ve diskten okumak gerekir. Ayrıntılar çok fazladır. Windows'ta ana disk `C:` olabilir ve klasörler ters eğik çizgiyle ayrılır. Linux dağıtımlarında çeşitli dosya sistemleri vardır, bir dizin ayrıca bağlanıp (mount) sürücü gibi düşünülebilir ve yol ayıracı düz eğik çizgidir. Giriş-çıkış kaynakları da çeşitlidir: klavye bir giriş aygıtı, ekran bir çıkış aygıtıdır; delikli kart okuyucu giriş, yazıcı çıkış aygıtıdır; bir TCP bağlantısı hem giriş hem çıkış için kullanılabilir.

### 10.2 Tamponlu ve tamponsuz I/O

Kaynakların çalışma biçimleri de farklıdır; bunlardan biri tamponlu (buffered) ya da tamponsuz (unbuffered) çalışmadır. Aynı işletim sisteminde bir aygıt tamponlu, başka bir aygıt tamponsuz çalışabilir. Slayta göre (ekrandan, 02:25:00) C, I/O işlerini geniş bir çalışma zamanı fonksiyonları kümesiyle yapar; bunların bir kısmı UNIX I/O kütüphanesinden gelmiştir. Ancak "C kütüphanesi" çoğunlukla tamponlu I/O ile çalışır, UNIX kütüphanesi tamponsuz I/O yapar. C kütüphanesi bu ek tamponlu çalışma yeteneğini sağlar ve programcıyı arkadaki tamponsuz işlemlerden soyutlar.

**Soru:** Tamponlu ne demek? Tamponlu ve tamponsuz kavramlarını bilmiyoruz. **Cevap:** Hoca üç benzetme verdi.

- Ağ örneği: bir bilgisayardaki program ağ üzerinden başka bir bilgisayara hızla paket gönderiyor. Alıcının donanımı o anda zayıf ya da arkada ağla ilgili başka işler var; program gelen paketleri o anda işleyemezse paketler kaybolabilir. Paketler bir tampon belleğe konur ve alıcı müsait olunca oradan çekerse veri kaybı olmaz. Aynı şey tek bilgisayarda da olur: çok eski ve yavaş bir bilgisayarda klavyeden yazılanların bir kısmı program tarafından alınamayabilir.
- Huni örneği: geniş ağızlı bir kaptan dar ağızlı bir şişeye su aktarılırken su dökülür. Huni kullanılırsa su, ne kadar hızlı dökülürse dökülsün huninin haznesinde bekler ve dar ağızdan akabildiği hızla akar. Huninin haznesi bir tampon bölgedir.
- Disk örneği: disk işlemleri bellek işlemlerinden her zaman yavaştır. Bir milyon kayıt yazılırken disk o sırada başka işle meşgulse, işletim sistemi ya veriyi kaybeder ya da diğer programları durdurur ve sistem yavaşlar. İşletim sistemi RAM'in bir kısmını tampon olarak ayırırsa, uygulama yazacağı bilgiyi oraya basar; disk toparlanınca bilgi tampondan okunup dosyaya yazılır.

Hoca bu konunun veri iletişimi ve işletim sistemleri derslerinde daha ayrıntılı görüleceğini söyledi.

Slaytın son kısmına göre ANSI komitesi bazı fonksiyonları korudu, bazılarını sildi, bazılarını değiştirdi. En büyük değişiklik tamponsuz I/O fonksiyonlarının kaldırılmasıdır: ANSI kütüphanesinde bütün I/O fonksiyonları tamponludur, ama tampon boyu değiştirilebilir (ekrandan, 02:25:00).

### 10.3 Metin ve ikili mod

ANSI I/O fonksiyonları dosyaya metin (text) modunda ya da ikili (binary) modda erişimi ayırır. Slayta göre UNIX ikili ve metin dosyalarını aynı biçimde işler; bazı başka işletim sistemlerinde bu ayrım son derece önemlidir (ekrandan, 02:25:00). Aynı C kodu farklı işletim sistemlerinde çalıştırıldığında, bir dosyayı metin olarak açmak doğru ya da yanlış bir karar olabilir.

Hoca farkı ekranda gösterdi. Bir `.c` dosyası aslında bir metin dosyasıdır: her satır ve sütununda bir karakter bulunur. Arkada bu dosya da bir bit dizisi olarak saklanır; örneğin bir konumda ASCII kodu 65 olan bayt durur. Metin olarak açılınca her bayt karaktere çevrilip gösterilir. Yürütülebilir (`.exe`) ya da nesne (`.o`) dosyalarında ise her bitin ayrı anlamı vardır. Böyle bir dosya bir kelime işlemciyle açılınca anlamsız karakterler görülür; bazı baytların karakter karşılığı bile yoktur. Nesne dosyası ikili bir dosyadır ve her baytı ayrı yorumlanır. Temel fark budur.

### 10.4 Akış (stream) ve FILE

Bir çıktı ekrana, bir disk dosyasına ya da bir internet bağlantısına gidebilir. Bir girdi klavyeden, başka bir bilgisayardan ya da diskten gelebilir. Kaynak ve hedefi farklı olan bu işlere tek biçimde erişebilmek için akış (stream) kavramı kullanılır. Bir kaynaktan bir hedefe gidecek veri bir akış olarak ele alınır ve bir bayt dizisi olarak iletilir; metin de ikili bilgi de böyledir. İki uçta bilgiyi akışa çevirme ve akıştan özgün haline döndürme işleri yapılır. Bu işlerin karmaşıklığı, I/O kütüphanesini yazanların derdidir.

Akışlara erişmek için kullanılan işaretçinin türü büyük harflerle `FILE`'dır. Bu tür `stdio.h` içinde tanımlıdır. Sonraki derslerde I/O işleri `FILE` yapısı üzerinden yapılacaktır.

### 10.5 Standart akışlar

Slayta göre (ekrandan, 02:40:00) her program için otomatik açılan üç akış vardır: `stdin`, `stdout` ve `stderr`.

- `stdin` (standart giriş): normalde klavyedir. Eskiden delikli kart okuyucuydu.
- `stdout` (standart çıkış): `printf` çıktılarının gittiği yerdir, normalde ekrandır. Eskiden satır yazıcıydı.
- `stderr` (standart hata): yalnız hata oluştuğunda çıktı verilecek yerdir. Normalde o da ekranı gösterir. Hatalarla ilgili çıktının ayrı bir hedefe gitmesi isteniyorsa ayrıca tanımlanabilir. Örneğin program `exit(1)` gibi bir hata koduyla çıkacaksa, hata bilgileri ayrı bir kanala yazılabilir. Arkada böyle bir akış sağlayan bir araç varsa bu, biriktirilip e-postayla gönderilecek bir metin bile olabilir.

Slayta göre bu akışlar genelde terminali gösterir, ama birçok işletim sistemi onları yönlendirmeye izin verir; örneğin hata mesajları terminal yerine bir dosyaya yazılabilir. `printf()` `stdout`'a yazar, `scanf()` `stdin`'den okur. `stdin` ve `stdout` `freopen()` fonksiyonuyla dosyalara yönlendirilerek bu fonksiyonlarla dosya I/O yapılabilir. Daha kolay yol ise belirli bir akışı belirtmeye izin veren eşdeğer `fprintf()` ve `fscanf()` fonksiyonlarıdır: `fprintf` dosyaya yazar, `fscanf` dosyadan okur.

> **Ek bilgi (derste anlatılmadı):** `fprintf` ve `fscanf`, ilk parametre olarak bir `FILE *` alır; geri kalanı `printf` ve `scanf` ile aynıdır. Bu yüzden `fprintf(stdout, "...")` ile `printf("...")` aynı işi yapar. Hata mesajları için yaygın kullanım `fprintf(stderr, "...")` biçimindedir.

### 10.6 Farklı sistemler arasında dosya taşımak

**Soru:** Unix ile Windows'un dosya sonu (end of file) gösterimlerinin farklı olduğunu duydum; dosyayı Windows biçimiyle mi Unix biçimiyle mi okumak istediğiniz sorulabiliyor. Bu nasıl olur? **Cevap:** Hoca ayrıntısını bilmediğini söyleyip bir kelime işlemcide görünmeyen karakterleri açarak basit bir örnek gösterdi. Boşluklar nokta olarak görünür. Shift+Enter yeni satıra geçer ama yeni paragraf açmaz; Enter yeni paragraf açar. Ekranda bu ikisi çoğu zaman aynı görünür. Ama belge Windows'ta kaydedilip bir Linux dağıtımında başka bir ofis uygulamasıyla açılınca, Shift+Enter ile yapılan satır sonu paragraf olarak yorumlanabilir ve bütün düzen bozulabilir. Dosya sonu farkı da benzer bir sorundur. Türkçe karakterler de farklı karakter kodlamaları yüzünden öteki sistemde garip şekiller olarak görünebilir.

> **Ders sonrası not:** Hoca dosya sonu için bir sistemin `\0`, ötekinin `\x1` kullandığını örnek olarak söyledi; bu doğru değildir. Windows ile Unix arasındaki asıl fark satır sonudur: Windows `\r\n` (CR LF), Unix `\n` (LF) kullanır. C'de dosya sonu bir karakter değil, okuma fonksiyonlarının döndürdüğü `EOF` değeridir. Eski DOS/Windows metin dosyalarında büyük olasılıkla Ctrl+Z (`0x1A`) dosya sonu işareti olarak kullanılıyordu. Karakter kodlamasıyla ilgili ifadede de UTF-8 bir Unicode kodlamasıdır; Türkçe karakter sorunu genelde bir tarafın UTF-8, ötekinin Windows-1254 gibi eski bir kod sayfası kullanmasından çıkar.

### 10.7 Dosyaya neden yazarız?

**Soru:** Bir programda neden kendimiz dosyadan girdi almak ya da dosyaya çıktı vermek isteriz? **Cevap:** Örneğin derste çeşitli çalışanlar oluşturuldu ve bilgileri komut satırından girildi. Program kapanınca bu bilgiler kaybolur. Bilgiler daha sonra değiştirilecekse bir yerde saklanmaları gerekir; en temel yol dosyalardır. Veritabanına da yazılabilir, ama bunun için veritabanı sunucusuyla iletişim kurmayı ve sorgu komutlarını öğrenmek gerekir. Sektör uzun yıllardır SQL sorgu dilinde buluşmuştur; bu konu ileride görülecektir. Veritabanı sunucusu kurulamayan ortamlarda, girilen verilerin program bittikten sonra korunması ve kalınan yerden devam edilmesi için dosyaya yazan ve dosyadan okuyan kod gerekir. Kısacası amaç verinin kalıcılığını sağlamaktır.

## Örnek Sorular

### Soru 1: Fonksiyon işaretçisi atamalarının geçerliliği (ekrandan, 02:10:00)

Aşağıdaki bildirimlere göre `main` içindeki atamalardan hangileri geçerlidir, hangileri değildir? Nedenini açıklayın.

```c
extern int   if1(), if2(), (*pif)();
extern float ff1(), (*pff)();
extern char  cf1(), (*pcf)();

int main( ) {
  pif = if1;
  pif = cf1;
  pff = if2;
  pcf = cf1;
  if1 = if2;
}
```

**Çözüm (derste verildi):** `pif = if1;` ve `pcf = cf1;` geçerlidir, dönüş türleri uyuşur. `pif = cf1;` ve `pff = if2;` geçersizdir, dönüş türleri uyuşmaz; C, `char` döndüren fonksiyonu `int` döndüren fonksiyon işaretçisine otomatik dönüştürmez. `if1 = if2;` geçersizdir, çünkü fonksiyon adları sabittir ve sabite atama yapılamaz.

### Soru 2: fact(15) neden 2004310016 verdi? (ekrandan, 01:50:00)

Slayttaki `int fact(int n)` fonksiyonu `fact(15)` için ekrana `2004310016` yazdırdı. Bu değer neden yanlıştır, nereden gelmektedir?

**Çözüm (derste kısmen verildi):** Hoca, gerçek değerin 13 basamaklı olduğunu ve `int` sınırını aştığını söyledi. Ayrıntı derste verilmedi: $15! = 1\,307\,674\,368\,000$ değeri 32 bitlik `int`'e sığmaz ($2^{31} - 1 = 2\,147\,483\,647$). Çarpımlar taşınca yalnız düşük 32 bit kalır: $1\,307\,674\,368\,000 \bmod 2^{32} = 2\,004\,310\,016$. Bu değer $2^{31}$'den küçük olduğu için pozitif görünür. Ara değerlerden ilk taşan 13!'tir. Değer python ile ve program gcc ile çalıştırılarak doğrulandı.

### Soru 3: Union ataması (ekrandan, 00:40:00)

`U` birliği `struct { char c1, c2; } s; long j; float x;` üyelerinden oluşur. `example.s.c1 = 'a'; example.s.c2 = 'b';` atamalarından sonra `example.j = 5;` yapılırsa `c1` ve `c2` ne olur?

**Çözüm (derste verildi, ders sonrası düzeltildi):** `j` bütün alanı kaplar ve `'a'` ile `'b'` silinir. Hoca baştaki bitlerin 0, son üç bitin `101` olacağını anlattı. x86 gibi küçük sonlu bir işlemcide ilk bayt sayının en düşük baytıdır; bu yüzden `c1` = 5 (görünmeyen bir denetim karakteri), `c2` = 0 olur. Büyük sonlu bir işlemcide ikisi de 0 olur. Bu sonuç ajan tarafından gcc ile derlenip çalıştırılan küçük bir programla x86-64'te doğrulandı.

### Soru 4: Bit alanı yapı dışında kullanılabilir mi? (derste sözlü, 00:32:55)

**Çözüm (derste verildi):** Hayır, bit alanı sözdizimi yalnız yapı içinde kullanılır. Aynı sıkıştırma isteniyorsa yeterli genişlikte bir tamsayı türü (örneğin `long int`) alınır, alanlar bitsel işlemlerle bu sayının içine elle yerleştirilir ve her alan için ayrı okuma ve yazma fonksiyonları yazılır (3. bölüm).

### Soru 5: Fonksiyon işaretçileri hangi durumlarda kullanışlıdır? (derste sözlü, 02:18:54)

**Çözüm (derste verildi):** Farklı türden elemanlara hitap eden genel (jenerik) kod yazarken. Örneğin farklı türde veri tutan bağlı listeleri tek bir dolaşma ve listeleme fonksiyonuyla işlemek için, o türün yazdırma fonksiyonu işaretçi olarak verilir (9.6).

### Soru 6: Tamponlu I/O nedir? (derste sözlü, 02:26:08)

**Çözüm (derste verildi):** Üretilen veri hemen tüketilemediğinde araya konan geçici bellek alanıyla yapılan giriş-çıkıştır. Gönderen hızlı, alıcı yavaşsa veri tamponda bekler ve alıcı müsait olunca oradan çekilir; böylece veri kaybolmaz ve sistem gereksiz yere durmaz. Hocanın benzetmesiyle tampon, su aktarırken kullanılan huninin haznesidir (10.2).

### Soru 7: Fibonacci sayılarını özyinelemeli hesaplayın (ekrandan, 01:45:00)

Slaytta evde çözülmek üzere bırakılan alıştırma: Fibonacci sayılarını $F_{n+1} = F_n + F_{n-1}$ bağıntısıyla özyinelemeli bir fonksiyonla hesaplayın.

> **Çözüm (derste verilmedi):** Taban durumlar $F_0 = 0$ ve $F_1 = 1$ alınır; bunlar aynı zamanda durma noktasıdır. Ajan aşağıdaki programı gcc -Wall ile derleyip çalıştırdı; çıktı `0 1 1 2 3 5 8 13 21 34 55` oldu.

```c
#include <stdio.h>

/* F(0) = 0, F(1) = 1, F(n+1) = F(n) + F(n-1) */
int fib(int n) {
    if (n <= 1)          /* durma noktasi */
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    int i;
    for (i = 0; i <= 10; i++)
        printf("%d ", fib(i));
    printf("\n");
    return 0;
}
```

### Soru 8: İkili aramayı özyinelemeli yazın (ekrandan, 01:45:00)

Slayttaki ikinci alıştırma: ikili aramayı özyinelemeli olarak kodlayın. Hoca yöntemi derste tarif etti: sıralı dizinin ortasına bakılır; aranan eleman ortadakiyse iş biter, küçükse sol yarıda, büyükse sağ yarıda aranır.

> **Çözüm (derste verilmedi):** Durma noktası aralığın boşalmasıdır (`lo > hi`); bu durumda eleman yoktur. Ajan aşağıdaki programı gcc -Wall ile derleyip çalıştırdı; 23 için indis 5, 7 için -1 döndü.

```c
#include <stdio.h>

/* Sirali dizide x'i [lo, hi] araliginda arar; bulursa indisini, bulamazsa -1 dondurur. */
int bsearch_rec(const int a[], int lo, int hi, int x) {
    int mid;
    if (lo > hi)                 /* durma noktasi: aralik bos */
        return -1;
    mid = (lo + hi) / 2;
    if (a[mid] == x)
        return mid;
    if (x < a[mid])
        return bsearch_rec(a, lo, mid - 1, x);   /* sol yari */
    return bsearch_rec(a, mid + 1, hi, x);       /* sag yari */
}

int main(void) {
    int a[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    printf("%d %d\n", bsearch_rec(a, 0, 9, 23), bsearch_rec(a, 0, 9, 7));
    return 0;
}
```

## Dersin Toparlaması

Bu derste önce bit alanları bağlı liste örneğinde kullanıldı. Doğum tarihi 5, 4 ve 11 bitlik alanlara sığdırıldı ve bit alanının adresi alınamadığı için okumada geçici değişken kullanıldı. Ardından union kavramı tanıtıldı: aynı bellek alanını duruma göre farklı türlerden yorumlamak. Union'ın boyutu en büyük üyesine eşittir ve bir üyeye yazmak ötekileri bozar. Gerçek hayat örneğinde çalışan kaydındaki uyruk ve doğum şehri alanları bir union içinde birleştirildi. Hangi yorumun geçerli olduğu union dışındaki bir bitlik `TCcitizen` bayrağıyla tutuldu ve kayıt başına 20 bayt kazanıldı. Kod, tarih yapısının ayrılması, bayrağın ve union'ın eklenmesi, okuma ve yazdırma fonksiyonlarının iki dala ayrılması adımlarıyla canlı olarak dönüştürüldü.

İkinci yarıda özyineleme, yığındaki çağrı çerçeveleri ve durma noktasının zorunluluğu üzerinden anlatıldı. Faktöriyel örneği adım adım izlendi ve `int` taşmasının yanlış sonuç ürettiği gösterildi. Fonksiyon işaretçilerinin tanımı, dönüş türlerinin uyum kuralı ve işaretçi üzerinden çağırma görüldü. Son olarak dosya giriş-çıkışına giriş yapıldı: taşınabilirlik sorunu, tamponlu ve tamponsuz I/O, metin ve ikili mod, akış kavramı, `FILE` türü ve üç standart akış. `fopen`, `FILE` yapısının kullanımı ve dosya I/O kod örnekleri sonraki derse bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
