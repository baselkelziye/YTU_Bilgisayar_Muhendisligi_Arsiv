# Ders 18 Çalışma Özeti

## Genel Konular

- Bağlı listede baştan ve sondan silme (ekrandan, 00:20:00, 00:25:00)
  - Önceki derste yazılan tek yönlü bağlı liste programına `delete_from_begin` ve `delete_from_end` fonksiyonları eklendi. `head` şimdilik global bir değişkendir; ileride parametre olarak geçirilecektir.
  - Baştan silme: liste boşsa (`head == NULL`) "List is empty" yazılıp `return` ile çıkılır. Değilse silinen değer `n = head->data` ile saklanır, `tmp = head->next` ile ikinci düğüm tutulur, `free(head)` ile ilk düğüm bırakılır ve `head = tmp` yapılır.
  - Sondan silme: boş liste ve tek elemanlı liste (`head->next == NULL`) ayrı durumlardır. Tek eleman varsa düğüm serbest bırakılır ve `head = NULL` olur. Birden fazla eleman varsa liste iki işaretçiyle gezilir: `tmp` ilerlerken `u` bir önceki düğümü tutar. Döngü `tmp->next == NULL` olunca biter; `u->next = NULL` yapılır ve `free(tmp)` çağrılır.
  - Çalıştırma: 1, 2, 3, 4 baştan eklenince liste 4-3-2-1 olur. Baştan silme 4'ü, sondan silme 1'i siler; liste 3-2 kalır.
  - Çalışma sorusu: veriye göre arayıp aradan düğüm silme (aranan düğümden önceki düğümü sonrakine bağlamak; ilk eleman durumunu ayrıca düşünmek) ve sıralı araya ekleme.
- İç içe struct örneği: polinom toplama (ekrandan, 00:30:00, 00:35:00)
  - `TERM` yapısı katsayı (`coeff`) ve üs (`expo`) tutar. `POLY` yapısı terim sayısı `N` ve dinamik olarak açılan `TERM *terms` dizisini tutar.
  - `mySort` terimleri üsse göre kabarcık sıralamasıyla sıralar; takas `TERM temp` ile bütün struct'ı kopyalayarak yapılır. Erişim biçimi: `pt->terms[j].expo`.
  - `toplam` iki polinomun en büyük üssüne göre `max = 1 + max(a, b)` boyutlu bir `int` dizisini `calloc` ile sıfırlı açar. Dizinin indisi üssü, değeri katsayıyı tutar. İki polinomun katsayıları bu diziye eklenir, sıfırdan farklı terimler sayılır, o kadar terimli yeni bir `POLY` `malloc` ile oluşturulur ve adresi döndürülür.
  - Döndürülen `POLY *` dinamik bellekte olmalıdır; fonksiyonun yerel değişkeni fonksiyon bitince yok olur (ömür, duration).
- Struct döndüren fonksiyonlar: oyuncu verimi örneği (ekrandan, 00:40:00)
  - Her oyuncunun üç maçtaki golleri ve oynadığı süre vardır. Verim `(goal[0]+goal[1]+goal[2]) / duration` olarak hesaplanır, en yüksek verimli oyuncu bulunur.
  - Üç sürüm: en iyi oyuncunun indisini döndürmek (`int calculate`), struct'ın kendisini döndürmek (`GAME calculatev2`, `ptr[i]` ile) ve işaretçiyi ilerleterek struct döndürmek (`GAME calculatev3`, `ptr++` ile).
  - Struct değer olarak döndürülünce bütün alanları kopyalanır; yerel değişken ölse de değer çağırana ulaşır. Yerel (static olmayan) bir dizinin adresini döndürmek ise güvenli değildir.
- Structure alignment ve bit alanları (ekrandan, 00:45:00, 00:50:00, 00:55:00)
  - Bazı sistemler char'dan büyük nesneleri 2'nin kuvveti olan adreslere yerleştirir. Bu kısıtlar programcıya görünmez ama struct içinde boşluklar oluşturur.
  - Bit alanı (bit field): bir üyenin kaç bit kaplayacağı `:` ile belirtilir (`unsigned int day : 5; unsigned int month : 4; unsigned int year : 11;`). Gömülü sistemlerde bellek tasarrufu için kullanılır.
  - İki kısıt: bit alanının adresi alınamaz (`scanf("%d", &s.i)` derleme hatası verir) ve bit alanlarından dizi kurulamaz. Bit alanı içeren struct'lardan dizi kurulabilir (`s[4].r`).
  - Çözüm: değeri geçici bir değişkene okuyup aralığını kontrol etmek ve sonra atamak: `if (x >= 0 && x < 32) s[4].r = x;`
  - Bit alanlarının bellekteki yerleşimi (bir sonraki alanın sınırı aşıp aşamayacağı) derleyiciye göre değişir.
- Union (ekrandan, 01:00:00, 01:05:00)
  - Struct'ta her üyenin ayrı adresi vardır; union'da bütün üyeler aynı bellek alanını paylaşır ve aynı anda yalnız biri anlamlıdır. Union'ın boyutu en büyük üyesi kadardır.
  - Örnek: `typedef union { struct { char c1, c2; } s; long j; float x; } U;` `example.s.c1 = 'a'; example.s.c2 = 'b';` sonrası `example.j` okununca bu baytların oluşturduğu büyük bir tamsayı görülür. `example.x = 5.56` sonrası `c1` ve `j` okunursa float'ın IEEE 754 bitleri başka türde yorumlanır.
  - Kullanım: Türk vatandaşıysa kimlik numarası, değilse doğduğu şehir gibi birbirini dışlayan alanları tek bir alanda saklamak; derste 40 baytlık iki alanın 20 bayta inebileceği söylendi.
- Özyineleme (recursion) (ekrandan, 01:25:00, 01:30:00, 01:35:00)
  - Fonksiyonun kendini çağırmasıdır. Durma koşulu olmayan özyineleme yığını (stack) doldurur ve program çöker.
  - Fonksiyon çağrısında dönüş adresi (program sayacının sonraki değeri), parametreler, yerel değişkenler ve işlemci durumu yığına konur; iç içe çağrılar yığında üst üste birikir, dönüşte sırayla çıkarılır.
  - Yapı: temel durum (base case) ve problemin daha küçük bir parçasıyla kendini çağırma. Faktöriyel: `if (n <= 1) return 1; else return n * fact(n-1);` `fact(5)` için çağrılar 1'e kadar iner, dönüşte 2, 6, 24, 120 elde edilir.
- Fonksiyon işaretçileri (ekrandan, 01:40:00, 01:45:00)
  - `int (*pf)(int);` bir `int` alıp `int` döndüren fonksiyonu gösterebilen bir değişkendir. `int *pf();` ise `int *` döndüren bir fonksiyon bildirimidir. Parantezler önemlidir.
  - `pf = f1;` ile atanır, `answer = (*pf)(n);` ile çağrılır. `pf = f1();` yanlıştır (fonksiyonun döndürdüğü değeri atar). Fonksiyon adı sabit bir adrestir; fonksiyon adına atama yapılamaz. İşaretçinin türü fonksiyonun dönüş ve parametre türleriyle uyuşmalıdır.
  - Kullanım: tek bir genel kabarcık sıralama fonksiyonu `bubble(int work[], const int size, int (*compare)(int a, int b))` alır; `ascending` ya da `descending` geçirilerek artan ya da azalan sıralama yapılır. Görsel programlamadaki delegate ve olay (event) mantığı da buna benzer.
  - Fonksiyon işaretçisi dizisi: aynı imzalı `sum`, `subtract`, `multiply`, `divide` fonksiyonları dört elemanlı bir işaretçi dizisine konur ve seçime göre çağrılır.
- Void işaretçi (ekrandan, 02:00:00)
  - `void *` genel amaçlı bir işaretçidir; her türün adresini tutabilir. Gösterdiği yere yazmak için önce uygun türe dönüştürülür: `*(int *)pt = 10;`, `*(float *)pt = 3.4;`, `*(char *)pt = 's';`
  - `malloc` `void *` döndürür; derste dönüşün türü belli olsun diye `(NODE *)` gibi açık dönüşüm yapılıyor.
- Struct kopyalama ve derin kopya (ekrandan, 01:55:00)
  - Değişkenler üç yolla kopyalanır: atama, parametre geçirme, `return`. Struct ataması üyeleri tek tek kopyalar.
  - Struct dinamik bir dizinin işaretçisini tutuyorsa (`int *Coeff`) dizi struct'ın üyesi değildir. `P = Q` sonrası ikisi aynı diziyi gösterir; birinde yapılan değişiklik ötekini etkiler, birinin dizisi `free` edilirse öteki geçersiz alanı gösterir.
  - Gerçek derin kopya için hedefe ayrı alan açılıp elemanlar `memcpy` ya da döngüyle tek tek kopyalanır.
- Dinamik metin okuma
  - `getchar` ile Enter'a (`'\n'`) kadar karakter okunur, her karakterde dizi `realloc` ile bir büyütülür, sonunda `'\0'` eklenir. Boşluklar dahil bütün girdi saklanır.
- Tek ve çift işaretçiyle parametre geçirme (ekrandan, 02:05:00, 02:10:00, 02:15:00, 02:20:00)
  - Senaryo 1: `my_func(int *p)` içinde `malloc` ile yeni alan açılıp `p = z` yapılırsa yalnız yerel kopya değişir; `main`'deki `h` hâlâ eski adresi (değeri 22) gösterir.
  - Senaryo 2: `my_func_2(int **p)` fonksiyonuna `&hh` geçirilir ve `*p = z` yapılır. Bu kez `main`'deki `hh` yeni alanı gösterir ve `*hh` 999 olur.
  - Bağlı listede `head` değişecekse (başa ekleme, baştan silme) `head` ya çift işaretçiyle (`NODE **`) geçirilir ya da güncel `head` fonksiyondan döndürülür. Global değişken kullanılmaması istendi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Baştan silmede `head = head->next` tek başına yetmez
  - Bir öğrencinin önerisi üzerine anlatıldı: ilk düğümü `free` edebilmek için ikinci düğümün adresi önce `tmp` gibi bir değişkende saklanmalıdır.
- Sondan silmede iki işaretçi gerekir
  - Liste tek yönlü olduğu için sondan bir önceki düğüme geri dönülemez; arama sırasında önceki düğüm ayrıca tutulur. Tek elemanlı liste ayrı bir durumdur.
- Fonksiyondan döndürülen adres dinamik bellekte olmalı
  - Yerel bir dizinin adresi fonksiyon bitince geçersizdir; `malloc` ile açılan alan heap'te yaşamaya devam eder.
- Bit alanının adresi alınamaz, bit alanından dizi olmaz
  - Bit alanına `scanf` ile doğrudan okunamaz; geçici değişken ve aralık kontrolü kullanılır. Bit alanlarında işaretsiz (`unsigned`) tür tercih edilmelidir.
- Özyinelemede mutlaka bir durma koşulu yazılmalı
  - Her çağrı yığında yer kapladığı için koşulsuz özyineleme belleği doldurur. Özyineleme kodu kolaylaştırır ama bellekten ödün verir.
- Çift işaretçinin mantığı elle çözülmeli
  - Senaryo 1 ve 2 adres adres kâğıt üzerinde izlenmeli; bu mantık bağlı listede `head`'i parametre olarak geçirirken kullanılacaktır.

## Kısa Tekrar Notları

- Baştan silme: `n = head->data; tmp = head->next; free(head); head = tmp;`
- Sondan silme: boş liste, tek eleman ve genel durum ayrı ele alınır; `u` önceki düğüm, `tmp` son düğüm; `u->next = NULL; free(tmp);`
- `POLY` içinde `TERM *terms`: iç içe struct ile dinamik dizi; erişim `pt->terms[j].expo`.
- Polinom toplama: indisi üs, değeri katsayı olan `calloc` dizisi; sonuç yeni `malloc` edilmiş `POLY *`.
- Struct değer olarak döndürülebilir; yerel dizinin adresi döndürülmez.
- Bit alanı: `unsigned int day : 5;` adres yok, dizi yok, yerleşim derleyiciye bağlı.
- Union: bütün üyeler aynı alanı paylaşır; boyut en büyük üye kadardır; son yazılan üye anlamlıdır.
- Özyineleme: temel durum + küçülen çağrı; her çağrı yığına çerçeve ekler.
- `int (*pf)(int);` fonksiyon işaretçisi; `pf = f1;` ve `(*pf)(n)`. Türler uyuşmalı.
- `bubble(a, SIZE, ascending)` / `bubble(a, SIZE, descending)`: karşılaştırma fonksiyonu parametre olarak geçer.
- `void *` her adresi tutar; yazmadan önce türe dönüştürülür. `malloc` `void *` döndürür.
- Struct atamasında işaretçi üyeler yalnız adres olarak kopyalanır; derin kopya için ayrı alan ve eleman eleman kopya gerekir.
- Fonksiyonda çağıranın işaretçisini değiştirmek için `int **` ile adresini geçir ya da yeni adresi döndür.

## Detaylı Açıklamalar

- **Bağlı listeden silme.** Önceki derste menüyle çalışan bir bağlı liste programı yazılmıştı. Bu derste menüye iki seçenek eklendi. `delete_from_begin` önce listenin boş olup olmadığına bakar; `void` fonksiyonda değer döndürmeden `return;` yazmak geçerlidir. Liste boş değilse silinen değer ekrana yazmak için `n`'de tutulur, ikinci düğümün adresi `tmp`'ye alınır, ilk düğüm `free` edilir ve `head` ikinci düğüme taşınır. Ekranda ilk yazımda `free(start)` vardı; derleme hatası üzerine `free(head)` olarak düzeltildi (ekrandan, 00:20:00, 00:25:00). `delete_from_end` için ekranda görülen ve altyazıdan tamamlanan kod şudur:

```c
void delete_from_end(){
    NODE *tmp, *u;
    int n;
    if(head==NULL){
        printf("List is empty");
        return;
    }
    if(head->next==NULL){
        n=head->data;
        free(head);
        head=NULL;
        printf("%d was deleted",n);
        return;
    }
    tmp=head;
    while(tmp->next!=NULL){   /* döngü kısmı altyazıdan kuruldu */
        u=tmp;
        tmp=tmp->next;
    }
    n=tmp->data;
    u->next=NULL;
    free(tmp);
    printf("%d was deleted",n);
}
```

- **Polinom örneği.** `main` iki polinomu okur (`readPoly`), sıralar (`mySort`), yazdırır (`displayPoly`), `toplam` ve `fark` ile yeni polinomlar üretip yazdırır ve sonunda `free(p1.terms)` ile belleği bırakır (ekrandan, 00:30:00). `toplam` fonksiyonunda (ekrandan, 00:35:00) `a = p1->terms[p1->N-1].expo` ve `b` en büyük üslerdir; `max = 1 + ((a>b) ? a : b)` sıfırıncı dereceyi de içerecek dizi boyutudur. Bir öğrencinin "neden `res` içinde üs tutmuyoruz" sorusuna verilen cevap: üsler dizinin indisleridir, dizide yalnız katsayılar durur. Derste verilen örnekte $3x^7 + 4x^2$ ve $5x^5 + 3x^3 - 2x^2$ için $a = 7$, $b = 5$, `max` $= 8$ olur. Toplam $3x^7 + 5x^5 + 3x^3 + 2x^2$ çıkar (4 sıfırdan farklı terim; sonuç ajan tarafından aynı fonksiyonla derlenip doğrulandı).
  - Ders sonrası not: Hoca sıralamada derecesi büyük terimin başa geleceğini söyledi; ekrandaki `mySort` koşulu (`terms[j].expo > terms[j+1].expo` ise takas) terimleri küçükten büyüğe sıralar. Hoca biraz sonra `toplam`'ı anlatırken küçükten büyüğe sıralandığını kendisi de söyledi. `displayPoly` diziyi sondan başa yazdırdığı için ekranda en büyük dereceli terim önce görünür.
- **Oyuncu verimi örneği.** `allocate` fonksiyonu `GAME *ptr = (GAME*) malloc(n*sizeof(GAME));` ile `n` oyunculuk dizi açar; açıklamada `calloc(n, sizeof(GAME))` ile de aynı işin yapılabileceği yazılıdır (ekrandan, 00:40:00). `calculatev2` içinde `yield1 = ptr[i];` struct'ı kopyalar; `return yield1;` ile struct çağırana kopyalanarak döner, bu yüzden yerel `yield1`'in ölmesi sorun olmaz. `calculatev3` `yield1 = *ptr;` ve `ptr++` kullanır; işaretçi ilerletildiği için başlangıç adresi fonksiyon içinde kaybolur, `ptr + i` ile yazılan sürümde kaybolmaz.
- **Hizalama ve bit alanları.** Slayttaki `struct ALIGN_EXAMP { char mem1; short mem2; char mem3; } s1;` örneği hizalama kısıtı olan sistemlerde üyeler arasında boşluk oluşabileceğini gösterir (ekrandan, 00:45:00). Bit alanlarında doğum tarihi örneği verildi: gün en fazla 31 olduğu için 5 bit, ay 12 olduğu için 4 bit yeter. Slayttaki `DATE` yapısında yıl için 11 bit ayrılır ve alanların bellek sözcüklerine nasıl yerleştiği iki farklı derleyici varsayımıyla gösterilir (ekrandan, 00:55:00). Derste yazılan `CMP` yapısında `int r:5; int i:3;` vardır; `scanf("%d", &s.i)` için derleyici "cannot take address of bit-field" hatası verir (ekrandan, 00:50:00, 01:05:00).
  - Ders sonrası not: TC kimlik numarası örneğinde 11 haneli bir sayı $10^{11} > 2^{32} \approx 4{,}29 \times 10^9$ olduğu için 32 bitlik `int`'e sığmaz; en az 37 bit gerekir.
  - Ders sonrası not: Derste `int r:5;` yazıldı ve `x < 32` kontrolü yapıldı. gcc'de `int` bit alanı işaretli kabul edilir; 5 bitlik işaretli alanın aralığı $-16 \ldots 15$'tir. Ajanın denemesinde 20 girilince `r` $-12$ oldu. Hocanın önerdiği gibi `unsigned int r:5;` yazılırsa aralık $0 \ldots 31$ olur ve kontrol doğru çalışır.
- **Union örneği.** Ekranda yazılan kod (ekrandan, 01:05:00): `example.s.c1='a'; example.s.c2='b'; printf("%c\n", example.s.c1); printf("%d", example.j); example.x=5.56; printf("%c\n", example.s.c1); printf("%ld", example.j);` İlk durumda `j`'nin alt iki baytı 97 ve 98'dir. Üst baytlar sıfırsa değer $98 \cdot 256 + 97 = 25185$ olur; değişken ilklenmediği için üst baytlarda rastgele değer de olabilir. `x = 5.56` yazıldıktan sonra alanın tamamı float'ın bitleriyle dolar; `c1` artık 'a' değil, anlamsız bir karakterdir. Hoca bunu bir IEEE 754 hesaplayıcısıyla göstermeye çalıştı.
  - Ders sonrası not: 5.56'nın 32 bitlik IEEE 754 karşılığı `0x40B1EB85`'tir; `long` 32 bit ise `example.j` $1085401989$ olarak okunur (ajan python ve gcc ile doğruladı; gcc'de `j` önceden sıfırlanarak). `long` 64 bit olan sistemlerde üst 4 bayt float tarafından yazılmaz. Derste ekrana yapıştırılan uzun ikilik dizi 5.56'nın double gösteriminin anlamlı kısmına aittir.
- **Özyineleme ve yığın.** Slayttaki `recurse` fonksiyonu `static` bir sayacı her çağrıda yazdırıp kendini koşulsuz çağırır; kayıtta sayaç binlerce çağrıdan sonra yığın dolunca program hata verdi (ekrandan, 01:25:00). Hoca bunu Assembly'deki program sayacıyla açıkladı: 10. satırdaki çağrıdan sonra 11. satıra dönmek için dönüş adresi saklanmalıdır; iç içe çağrılar için yazmaç sayısı yetmez, bu yüzden yığın kullanılır. Slayttaki şekilde `main` çalışırken yığında yalnız onun alanı vardır, `func1` çağrılınca parametreleri ve yerel değişkenleri üste eklenir, dönünce alan bırakılır; bırakılan alanda eski çöp değerler kalır (ekrandan, 01:30:00). Faktöriyel adımları slaytta: `fact(5)` → `5*fact(4)` → … → `2*fact(1)`; dönüşte `1`, `2*1`, `3*2`, `4*6`, `5*24 = 120` (ekrandan, 01:35:00). Slaytta ev ödevi olarak Fibonacci ($F_{n+1} = F_n + F_{n-1}$), ikili arama ve derinlik öncelikli arama önerilir.
- **Fonksiyon işaretçisi örneği.** Slayttaki program (ekrandan, 01:40:00) aşağıdadır. Slaytta `int (*pf) ();` yazılıdır; gcc 15 varsayılan olarak C23 kullandığı için boş parantez "parametresiz" anlamına gelir ve `(*pf)(n)` hata verir. Bu yüzden aşağıda `int (*pf)(int);` yazıldı; böylece `gcc -Wall` ile derlendi ve 7 girdisi için 8 yazdı.

```c
#include <stdio.h>
extern int f1(int); //could be defined externally but we have coded it below
int main() {
    int n;
    int (*pf) (int);
    int answer;
    printf("Bir sayi giriniz: "); scanf("%d",&n);

    pf=f1;
    answer=(*pf)(n); // calls f1() with argument n => f1(n)

    printf("%d", answer);
    return 0;
}
int f1( int a ) {
    return a+1;
}
```

  - Ders sonrası not: Hoca `pf = &f1;` yazımının da geçersiz olduğunu söyledi. Standart C'de fonksiyon adının adresini almak geçerlidir ve `pf = &f1;` ile `pf = f1;` aynı işi yapar (ajan gcc ile denedi). Geçersiz olanlar `pf = f1();` (dönen `int`'i atamak) ve fonksiyon adına atama yapmaktır (`if1 = if2;`).
- **Tek ve çift işaretçi.** Senaryo 2'nin ekrandaki çıktısında `zz` `23FE40`, `hh` değişkeninin kendisi `23FE38`, `malloc` alanı `6269F0` adresindedir. Fonksiyon içinde `p` `23FE38`'i (yani `hh`'nin adresini), `*p` önce `23FE40`'ı, `*p = z` sonrası `6269F0`'ı gösterir. `main`'e dönünce `*hh` 999, `hh` `6269F0` olur (ekrandan, 02:15:00). Senaryo 1'de ise `main`'e dönünce `*h` 22 ve `h` `23FE44` olarak kalır (ekrandan, 02:10:00).
  - Ders sonrası not: Senaryo 1'de `my_func` içinde `malloc` ile açılan alan `free` edilmiyor ve adresi fonksiyon bitince kayboluyor; bu bir bellek sızıntısıdır. Senaryo 2'de alan `main` sonunda `free(hh)` ile bırakılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
