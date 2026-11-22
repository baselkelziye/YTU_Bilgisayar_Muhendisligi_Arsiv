# Ders 8 Çalışma Özeti

## Genel Konular

- Fonksiyonlara parametre aktarımı: değer ile çağrı ve referans ile çağrı
  - Değer ile çağrıda (call by value) fonksiyona değişkenin bir kopyası gider. Fonksiyonun içinde yapılan değişiklik fonksiyon bitince kaybolur.
  - Referans ile çağrıda (call by reference) fonksiyona değişkenin adresi gider. Parametre işaretçi (`int *aa`) olarak tanımlanır, çağrıda `&a` verilir. Değişiklik kalıcı olur.
  - Eşleşme kuralı: parametre işaretçi ise ona `int *p = &a;` atamasındaki gibi bir adres verilir.
  - Örnek: `a=3, b=5` ile `increaseRegular(a, b)` fonksiyon içinde 8 yazar, ama `main` yine 3 görür. `increasePointer(&a, b)` sonrasında `main` 8 görür (ekrandan, 00:10:00).
- Fonksiyon tanımı, imzası, ön bildirimi ve çağrısı
  - İmza: geri dönüş türü, fonksiyon adı, parametrelerin sayısı ve türleri. Tanım (definition): imza ile gövdenin birlikte hali.
  - Ön bildirim (allusion): fonksiyon kullanılmadan önce bildirilmelidir. Ön bildirimde parametre adları yazılmayabilir, önemli olan türleridir. Başka `.c` dosyasındaki fonksiyon `extern` ile bildirilir.
  - Parametre almayan fonksiyonda parantez içine isteğe bağlı olarak `void` yazılabilir.
  - Fonksiyon çağrısında program sayacı (program counter) çağrılan fonksiyonun adresine gider. Fonksiyon dönünce yürütme çağrının hemen sonrasındaki işlemden sürer (aynı satırdaki atama da dahil).
- Takas (swap) fonksiyonu
  - Takasın kalıcı olması için iki parametre de işaretçi olmalıdır. Geçici değişken (`tmp`) kullanılır (ekrandan, 00:20:00).
- Dizileri fonksiyona parametre olarak vermek
  - C dizide sınır denetimi yapmaz, fonksiyon dizinin eleman sayısını bilmez. Bu yüzden eleman sayısı ayrıca verilir. String'lerde sondaki `'\0'` bu bilgiyi gereksiz kılar.
  - Üç yol: sabit boyut (`int ar[5]`, esnek değil), dizi ve boyut (`int ar[], int size`), işaretçi ve boyut (`int *ar, int size`) (ekrandan, 00:25:00).
- Dizi boyutunu bulan makro
  - `#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof((x)[0]))` (ekrandan, 00:30:00).
  - Fonksiyona verilen dizi işaretçiye dönüşür. `sizeof` işaretçinin boyutunu verir, makro fonksiyon içinde çalışmaz. Makro yalnız dizinin tanımlandığı yerde doğru sonuç verir.
  - Dinamik ayrılan alanı tutan işaretçide makro `main` içinde de doğru sonuç vermedi (8 yerine 1 yazdı).
  - Makroda parametre türü yoktur: farklı türlerle çalışır, ama tür denetimi ve uyarılar da olmaz.
- Fonksiyondan dizi döndürmek
  - Fonksiyondan dizi değil, dizinin başlangıç adresini tutan işaretçi döndürülür.
  - Yerel dizi döndürülemez, fonksiyon bitince alanı geçersiz olur. Çözüm dinamik bellek: `malloc`/`calloc` ile ayrılan alan fonksiyon bitince silinmez.
  - `concatArraysV1`: iki diziyi ve boyutlarını alır, `malloc` ile `size1+size2` elemanlık alan ayırır, birleştirip işaretçiyi döndürür. Çağıran taraf işi bitince `free` yapar (ekrandan, 01:00:00 ve 01:10:00).
  - `concatArraysV2` (alternatif): geri dönüş türü `void`, sonuç dizisi çağıran fonksiyonda tanımlanıp üçüncü dizi parametresi olarak verilir. Çağrılan fonksiyon yalnız doldurur (ekrandan, 01:15:00).
- `main` fonksiyonunun parametreleri
  - `int main(int argc, char *argv[])`: `argc` komut satırındaki argüman sayısı, `argv` argüman string'lerine işaretçi dizisi (ekrandan, 01:25:00).
  - Programın adı da sayılır: `argv[0]` programın adıdır.
  - Kullanım örneği: program `debug` argümanıyla çalıştırılınca ek hata ayıklama çıktıları basılabilir.
- Struct (yapı) kavramına giriş
  - Farklı türden verileri tek bir kayıtta toplar (çalışan: ad, soyad, kimlik no, maaş) (ekrandan, 02:10:00).
  - Paralel diziler (her alan için ayrı dizi) esnek değildir. Bir kaydın tek bir varlık olarak ele alınması gerekir.
  - `typedef` ile türe takma ad verilir. Takma ad geleneksel olarak büyük harfle yazılır (`EMPLOYEE`).
  - Alana erişim: değişkende nokta (`emp.ID`), işaretçide ok (`e_ptr->ID`). `e_ptr->ID`, `(*e_ptr).ID` ifadesinin kısaltmasıdır (ekrandan, 02:15:00).
  - İç içe struct: tarih (`DATE`) ayrı struct olarak tanımlanıp çalışan struct'ının içinde alan olarak kullanılır.
  - Struct'ı fonksiyona değer ile (`printReport(emp)`) ya da referans ile (`increaseSalary(&emp)`) verebiliriz (ekrandan, 02:20:00).
- Bağlı liste (linked list) veri yapısına giriş
  - Her düğümde bir veri alanı ve sonraki düğümü gösteren işaretçi vardır. İlk düğüm baş düğümdür (head node), son düğümün `next` işaretçisi `NULL` olur (ekrandan, 02:25:00).
  - Çeşitleri: tek yönlü (singly), çift yönlü (doubly, `previous` işaretçisi de var), dairesel (circular).
  - İki tasarım: veri struct'ının içine `next` koymak (basit) ya da veriyi (`EMPLOYEE`) ve düğümü (`EMP_NODE`) ayrı struct'larda tutmak (esnek) (ekrandan, 02:30:00 ve 02:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Değer ile çağrı ve referans ile çağrı farkı
  - Hoca bunu "en önemli ayrıntı" olarak belirtti. Bir kod parçasının çıktısını adım adım bulurken hangi çağrıda değişkenin değiştiğini bilmek gerekir.
- Takas fonksiyonunda işaretçi kullanmak
  - Takas ancak referans ile çağrıda kalıcı olur. Hoca bunun ilkel değişkenler, işaretçiler ve dizi elemanları için ayrı ayrı denenmesini istedi.
- Dizi fonksiyona verilirken eleman sayısı da verilmeli
  - Sabit kapasiteye göre yazılan fonksiyon her dizi boyu için ayrı fonksiyon gerektirir. Bu yüzden esnek değildir.
- Yerel dizi geri döndürülemez
  - Fonksiyon bitince yerel dizinin alanı geçersizleşir ve veri kaybolur. Dinamik bellek kullanılmalı, `NULL` denetimi yapılmalı ve sonunda `free` unutulmamalı.
- Gereksiz sıralama yapmamak
  - İki sıralı diziyi birleştirirken diziler uç uca eklenip sonra sıralanmamalı. Bir dizinin sıralı olup olmadığını anlamak için de dizi sıralanmamalı. Sıralama masraflı bir iştir.
- Veri ile veri yapısını ayırmak
  - Veriyi ve düğüm yapısını ayırmak ileride bağlı listeden hash tablosu gibi başka bir yapıya geçişi kolaylaştırır. Basit tasarımda veriyi işleyen bütün fonksiyonlar bağlı listeye bağımlı kalır.

## Kısa Tekrar Notları

- Değer ile çağrıda kopya gider, değişiklik kalıcı olmaz. Referans ile çağrıda adres gider (`&a` → `int *aa`), değişiklik kalıcı olur.
- İmza: dönüş türü, ad, parametre türleri. Tanım: imza ve gövde.
- Ön bildirimde parametre adı gerekmez, tür yeterlidir.
- Swap: `int *a, int *b` ve `tmp` değişkeni.
- Dizi parametre: `int ar[], int size` ya da `int *ar, int size`.
- `SIZE_OF_ARRAY(x)` yalnız dizinin tanımlandığı yerde ve gerçek dizide çalışır. İşaretçide ve fonksiyon parametresinde çalışmaz.
- Fonksiyondan dizi döndürmek: `malloc` ile alan ayır, işaretçiyi döndür, çağıran tarafta `free` yap.
- Alternatif: sonuç dizisini çağıran tanımlar, fonksiyon parametre olarak alıp doldurur.
- İlk döngüde artan `i` ikinci döngüde başlangıç ifadesi boş bırakılarak kullanılabilir: `for( ; i<size1+size2; i++ )`.
- `argc` program adı dahil argüman sayısı, `argv[0]` program adı.
- Struct alanına erişim: `.` (değişken), `->` (işaretçi). `p->x` ile `(*p).x` aynıdır.
- Bağlı listede baş düğümün adresi kaybedilmemeli. Son düğümün `next` işaretçisi `NULL` olur.

## Detaylı Açıklamalar

- **Değer ve referans ile çağrı.** Derste iki fonksiyon karşılaştırıldı (ekrandan, 00:10:00). `increaseRegular(int aa, int bb)` parametresini `aa += bb` ile artırır. `increasePointer(int *aa, int bb)` ise `*aa += bb` ile işaretçinin gösterdiği adresteki değeri artırır. `main` içinde `a=3, b=5` ile önce `increaseRegular(a, b)` çağrılır. Fonksiyon "8" yazar ama `main` "3" yazar, çünkü değişen yalnız kopyadır. Sonra `increasePointer(&a, b)` çağrılır. Hem fonksiyon hem `main` "8" yazar. Kod derste çalıştırıldı ve çıktı açıklamayla aynı geldi. Ajan da kodu `gcc -Wall` ile derleyip aynı çıktıyı aldı:

  ```text
  increaseRegular finishes with 8
  main says the value is 3
  increasePointer finishes with 8
  main says the value is 8
  ```

- **Faktöriyel ve taşma.** Slayttaki faktöriyel örneği basit bir kümülatif çarpımdır. Hoca, 4 baytlık `int`in yaklaşık ±2 milyara kadar değer tutabildiğini, faktöriyelin bu sınıra çok küçük sayılarda ulaştığını hatırlattı.
- **Dizi boyutu makrosu.** `SIZE_OF_ARRAY(x)` makrosu dizinin bütün bayt sayısını ilk elemanın bayt sayısına böler. Derste `int dizi[5]` için hem `main` içindeki elle yazılan ifade hem makro 5 verdi (ekrandan, 00:35:00). `calloc` ile 8 elemanlık alan ayrılıp bir işaretçiye atanınca makro `main` içinde de 1 yazdı. Bunun nedeni `sizeof(alan)`'ın işaretçinin boyutunu vermesidir.
  - Ders sonrası not: Hoca bu sonucu "anlattığımdan farklı" diye yorumladı. Sonuç beklenen davranıştır: makro yalnız gerçek dizi değişkeninde çalışır, işaretçide `main` içinde de çalışmaz. Derste kullanılan 32 bitlik derleyicide işaretçi 4 bayt, `int` 4 bayt olduğundan sonuç 1 çıkmıştır (büyük olasılıkla). Ajanın 64 bitlik gcc ile denemesinde aynı ifade 2 verdi. gcc `-Wall` bu kullanımlar için uyarı da verir (`-Wsizeof-pointer-div`, `-Wsizeof-array-argument`).
  - Derste `calloc` önce tek argümanla yazıldı ve derleyici hata vermedi. Hoca bunu ilginç buldu ve derleyicilerde farklı sürümler olabileceğini söyledi. <!-- BELİRSİZ: Tek argümanlı calloc çağrısının neden derlendiği derste netleşmedi; ANSI C'de calloc iki argüman alır (eleman sayısı, eleman boyutu). Prototip görmeyen eski derleyici örtük bildirimle derlemiş olabilir. -->
- **Fonksiyondan dizi döndürmek.** `concatArraysV1` kodu (ekrandan, 01:00:00; `NULL` denetimi IDE'de eklendi, 01:10:00):

  ```c
  int* concatArraysV1( int arr1[], int size1, int arr2[], int size2 ) {
      int *merged = (int*) malloc( (size1+size2)*sizeof(int) );
      int i;
      if( merged == NULL ) { printf("out of memory!"); exit(1); }
      for( i=0; i<size1; i++ )
          merged[i] = arr1[i];
      for( ; i<size1+size2; i++ )
          merged[i] = arr2[i-size1];
      return merged;
  }
  ```

  İkinci döngüde `arr2` sıfırdan okunmalıdır. Bu yüzden indis `i-size1` olur: `size1=5` iken `i=5` için `arr2[0]`, `i=6` için `arr2[1]` okunur. Fonksiyonun içinde `return` yerine `exit(1)` kullanıldı, çünkü fonksiyon bir işaretçi döndürmek zorundadır ve hata durumunda program bir hata koduyla sonlandırılır. `main` içinde `arr1[] = {1,5,7,19}`, `arr2[] = {2,6,8,11,28}` verildi. Birleşik dizi `1 5 7 19 2 6 8 11 28` olarak yazdırıldı ve sonunda `free(ptrM)` yapıldı.
- **Alternatif: sonucu parametreyle vermek.** `concatArraysV2` geri dönüş değeri olmayan (`void`) bir fonksiyondur. Üçüncü parametre olarak sonuç dizisini alır. `main` içinde `size3 = size1+size2` ve `int arr3[size3];` tanımlanır, `concatArraysV2(arr1, size1, arr2, size2, arr3)` çağrılır (ekrandan, 01:15:00). Böylece bellek ayırma işi çağıran fonksiyonda, doldurma işi çağrılan fonksiyonda yapılır. `size3` ayrıca gönderilmez, çünkü `size1` ve `size2`'den hesaplanabilir.
- **Komut satırı argümanları.** Slayttaki kod (ekrandan, 01:25:00):

  ```c
  int main(int argc, char *argv[]) {
      while(--argc > 0)
          printf("%s\n", *++argv);
      exit(0);
  }
  ```

  Önek azaltma ile `argc` her turda bir azalır, önek artırma ile `argv` bir sonraki argümanı gösterir. İlk artırmada `argv[0]` (program adı) atlanır. Hoca daha sade bir sürümü de yazdı: `for( i=0; i<argc; i++ ) printf("%s\n", argv[i]);`. Bu sürüm program adını da yazar. Program komut satırından `program 1 2 3 4 5` biçiminde çalıştırıldı. Hoca komut satırında yukarı ok tuşuyla önceki komutun geri getirilebildiğini, gezgininin adres çubuğuna `cmd` yazınca komut satırının o dizinde açıldığını da gösterdi. Argümanları ad-değer çiftleri olarak herhangi bir sırada okumaya yarayan yöntemin yalnız Linux'ta GNU C derleyicisiyle düzgün çalıştığını söyledi, uygulamalı göstermedi.
- **Struct ve typedef.** Paralel dizilerle 1000 çalışan tutmak için ayrı ID ve maaş dizileri ile 1000×20'lik ad ve soyad matrisleri gerekir. Aynı indisteki elemanların aynı kişiye ait olduğu bilinmeli ve belgelenmelidir. `struct Employee { char name[20], surname[20]; int ID; float salary; };` tanımı ve `struct Employee employees[1000];` dizisi bunun yerine geçer (ekrandan, 02:10:00). Hoca `struct Employee` ile `int` türü, değişken adı ile `i` arasında benzetme kurdu. `typedef` ile adsız bir struct'a `EMPLOYEE` takma adı verilince tür tek kelimeyle yazılabilir.
- **Bağlı liste.** Slayttaki örnek liste `49 → 15 → 73 → 87 → 10` değerlerini tutar, son düğümün `next` işaretçisi `NULL`dır (ekrandan, 02:25:00). Dizilerin sabit kapasitesi, araya eleman ekleme ve aradan silmenin zorluğu bağlı listeyi gerekli kılar. Çift yönlü listede her düğüm bir önceki düğümü de gösterir. Baş düğümün `previous` işaretçisi ve son düğümün `next` işaretçisi birbirini gösterirse dairesel çift yönlü liste olur. Ders, bağlı listenin iki tanım biçimiyle bitti. Kod örnekleri bir sonraki derse bırakıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
