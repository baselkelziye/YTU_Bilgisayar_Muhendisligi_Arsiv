# Ders 11 Çalışma Özeti

## Genel Konular

- `typedef` ile yapı tanımlama ve iç içe yapılar
  - `typedef struct Employee {...} EMPLOYEE;` biçiminde yapı tanımı ile tür adı tek seferde verilebilir. Ayrı satırda `typedef struct Employee EMPLOYEE;` yazmak da aynı işi görür (ekrandan, 00:15:00 ve 00:20:00).
  - Doğum tarihi gibi bir alt bilgi için ayrı bir `struct` (gün, ay, yıl) tanımlanıp çalışan yapısının içine üye olarak konabilir. Bu durumda `e.birthDate.day` biçiminde iki nokta ile erişilir.
  - Alt yapı isimsiz olarak doğrudan dış yapının içine yazılırsa (`struct { char gun; char ay; char yil; } tarih;`) yalnız orada bir kez kullanılabilir; aynı türden başka bir değişken tanımlanamaz (ekrandan, 01:25:00).
  - Değişken üretmeden yapının içine yalnız bir yapı tanımı yazmak hatalıdır.
- Fonksiyon işaretçisiyle bağlı liste kayıtlarını yazdırma (ekrandan, 00:20:00-00:45:00)
  - Çalışan kayıtları (ad, soyad, kimlik) tek yönlü bağlı listede tutulur. `head` global değil, `main` içinde `EMPLOYEE *head = NULL;` olarak tanımlanır.
  - `addRecord(EMPLOYEE **head)`: yeni düğüm `malloc` ile açılır, başa eklenir (`emp->next = *head; *head = emp;`). `malloc` başarısızsa `-1`, başarılıysa `0` döner.
  - `removeRecord(EMPLOYEE **head)`: kullanıcının verdiği kimliğe sahip düğüm `tmp` ve `prev` işaretçileriyle aranır ve silinir. İlk düğüm silinecekse `*head` güncellenir.
  - `printRecords(EMPLOYEE *head, void (*fptr)(EMPLOYEE *))`: listeyi gezer ve her düğümü parametre olarak gelen fonksiyona verir. `printNameFirst`, `printSurNameFirst`, `printIDFirst` fonksiyonlarından hangisi verilirse kayıt o sırayla yazılır.
- İşaretçinin işaretçisinin neden gerektiği: `swap3` ve `swap4` (ekrandan, 00:30:00)
  - `swap3(int *x, int *y)` içindeki işaretçi takası yereldir, `px` ve `py` değişmez.
  - `swap4(int **x, int **y)` ile `px` ve `py`'nin adresleri gönderilir; fonksiyon bitince `px` artık `y`'yi, `py` de `x`'i gösterir.
  - Aynı mantıkla `head`'in gösterdiği yer fonksiyonda değişecekse `head`'in adresi (`EMPLOYEE **`) gönderilir.
- Yapı dizisini sıralarken takas (nesnesel sıralama, ekrandan, 00:55:00)
  - Yapı dizisi bir üyeye göre (`strcmp(player[j].tname, player[j+1].tname) > 0`) kabarcık sıralamasıyla sıralanır.
  - Üyeleri tek tek takas etmek için her string üye için üç `strcpy` gerekir. Üye sayısı arttıkça bu zahmetli olur.
  - Bunun yerine yapı değişkenleri `=` ile bütün olarak takas edilir: `temp = player[j]; player[j] = player[j+1]; player[j+1] = temp;`
- Bir yapıyı başka bir yapıya kopyalamanın üç yolu (ekrandan, 01:15:00-01:20:00)
  - `record2 = record1;` atama operatörü: içerideki karakter dizileri dahil bütün alanlar kopyalanır; kopyanın adresleri farklıdır.
  - `memcpy(hedef, kaynak, sizeof(record1));` ile bellek bloğu bayt bayt kopyalanır.
  - Üyeleri tek tek kopyalamak (`record4.id = record1.id; strcpy(record4.name, record1.name); ...`): mümkündür ama üye sayısı çoksa tavsiye edilmez.
- Yapı hizalaması (alignment)
  - Bazı sistemlerde nesneler ikinin katı adreslere yerleştirilir. `char`, `short`, `char` sırasıyla tanımlanan bir yapıda üyeler arasında kullanılmayan boşluk baytları oluşabilir.
  - Aynı türden üyeleri art arda yazmak boşlukları azaltır.
- Bit alanları (bit fields) (ekrandan, 01:30:00)
  - Yapı içinde `unsigned int d:5;` gibi tanımlarla bir üyeye belirli sayıda bit ayrılır.
  - Bit alanının adresi alınamaz ve bit alanlarından dizi oluşturulamaz.
  - Örnek: üç `unsigned int` üyeli `DATE` 12 bayt (96 bit), `d:5`, `m:4`, `y:11` bit alanlı `MYDATE` 4 bayt (32 bit) yer tutar (ekrandan, 01:40:00).
  - `scanf` ile bit alanına doğrudan okunamaz (`&d2.m` derleme hatası verir: "cannot take address of bit-field"). Önce geçici bir `int`'e okunur, aralık kontrol edilip bit alanına atanır.
- Birlik (union) (ekrandan, 01:55:00)
  - Union'ın bütün üyeleri aynı bellek alanını paylaşır; boyutu en büyük üyenin boyutu kadardır. Bir üyeye yazmak diğerlerini bozar.
  - Union içinde yapı tutulabilir; yapı içinde de union tutulabilir.
  - Kullanım örneği: kişi Türk vatandaşıysa doğum yeri, değilse uyruğu aynı alanda saklanır; hangisinin okunacağına bir bayrak (tek bitlik bit alanı) karar verir.
- `<ctype.h>` karakter fonksiyonları: `isdigit`, `isalpha`, `isalnum`, `isxdigit`, `islower`, `isupper`, `tolower`, `toupper`, `isspace`, `iscntrl`, `ispunct`, `isprint`, `isgraph`.
- `<stdlib.h>` dönüşüm fonksiyonları: `atof`, `atoi`, `atol`, `strtod`, `strtol`, `strtoul`.
- `<stdio.h>` fonksiyonları (ekrandan, 02:30:00): `getchar`, `gets`, `putchar`, `puts`, `sprintf`, `sscanf`.
- `<string.h>` fonksiyonları: `strcpy`, `strncpy`, `strcat`, `strncat`, `strcmp`, `strncmp`, arama fonksiyonları (`strchr`, `strcspn`, `strstr` vb.), `strtok`, bellek fonksiyonları (`memcpy`, `memmove`, `memcmp`, `memset`), `strerror`, `strlen`.
- Biçimli giriş/çıkış: `printf` dönüşüm belirteçleri, alan genişliği, duyarlık, bayraklar (`-`, `+`, boşluk, `#`, `0`), kaçış dizileri ve `scanf` tarama kümeleri (`%[^\n]`), atlanan karakterler (`%*c`).

## Hocanın Özellikle Vurguladığı Kısımlar

- Global değişken kullanılmamalı
  - Bağlı listenin `head`'i ve başka veriler global tanımlanmaz; fonksiyonlara parametreyle aktarılır. Hoca örnek kodlardaki global değişkenleri de `main` içine taşıdı.
- `head` değişecekse çift işaretçi gerekir
  - Tek işaretçiyle gönderilen `head`, fonksiyon içinde yerel bir kopyadır (`swap3` gibi). Başa ekleme ve ilk düğümü silme gibi işlemlerde `EMPLOYEE **head` kullanılır.
  - Yalnız yazdırma gibi `head`'i değiştirmeyen işlemlerde tek işaretçi yeterlidir.
- `while (tmp != NULL && !found)` kalıbı
  - Çok kullanılan bir arama kalıbıdır. Döngü ya liste bittiğinde ya da kayıt bulunduğunda sona erer.
- String'ler `=` ile atanamaz, `==` ile karşılaştırılamaz
  - Dizinin adı bir adrestir; içerik `strcpy` ile kopyalanır, `strcmp` ile karşılaştırılır. `strcmp` sıfır döndürürse iki string eşittir.
- Yapıyı `=` ile kopyalarken dikkat
  - Yapının içinde `malloc` ile ayrılmış bir alanı gösteren işaretçi varsa `=` yalnız adresi kopyalar; iki yapı aynı veriyi gösterir ve birinde yapılan değişiklik diğerini de etkiler (önceki dersteki polinom örneği). Takas (swap) için bu bir sorun oluşturmaz.
- Bit alanına sığmayan değer
  - 5 bitlik işaretsiz alan 0-31 arası değer tutar. Daha büyük bir değer yazılırsa sığacak şekilde kesilir ve yanlış değer saklanır. Bu yüzden atamadan önce aralık kontrolü yapılmalıdır.
- Bit alanından dizi oluşturulamaz derken kastedilen
  - Bit alanlı yapı türünden dizi (`MYDATE d4[10];`) tanımlanabilir. Yasak olan, yapının içinde bir bit alanını dizi olarak tanımlamaktır.
- Modülerlik için tarih yapısı ayrı tanımlanmalı
  - Tarih yalnız çalışana özgü değildir; ayrı bir tür olarak tanımlamak modülerlik ve nesnesel tasarım açısından daha doğrudur.
- `sprintf` ve `sscanf` projede kullanılmaya değer
  - Dosyadan bir satır string olarak okunup `sscanf` ile alanlarına ayrılabilir.

## Kısa Tekrar Notları

- `typedef struct X {...} X_T;` ile yapı ve tür adı birlikte tanımlanır.
- Fonksiyon işaretçisi parametresi: `void (*fptr)(EMPLOYEE *)`; çağrı: `fptr(tmp);`, aktarım: `printRecords(head, printIDFirst);`
- Başa ekleme: `emp->next = *head; *head = emp;`
- Silme: `prev == NULL` ise `*head = tmp->next;`, değilse `prev->next = tmp->next;`, sonra `free(tmp);`
- `swap4(&px, &py)` işaretçilerin gösterdiği yeri değiştirir; `swap3(px, py)` değiştirmez.
- Yapı takası: `temp = a; a = b; b = temp;` (bütün alanlar kopyalanır).
- Yapı kopyalama: `=`, `memcpy`, üye üye kopyalama.
- `memcpy` kaynağın ve hedefin çakışmadığını varsayar; çakışma varsa `memmove` kullanılır.
- Bit alanı: `unsigned int d:5;`; adresi alınamaz, `scanf` ile doğrudan okunamaz.
- `sizeof(DATE) = 12`, `sizeof(MYDATE) = 4` (5 + 4 + 11 = 20 bit, 4 baytlık birime sığar).
- Union boyutu en büyük üyenin boyutudur: `char` 1, `int` 4, `double` 8 ise union 8 bayt.
- `isxdigit('J')` yanlış döner; onaltılık rakamlar 0-9 ve A-F'dir.
- `sscanf(kaynak, format, ...)` string'den okur; `sprintf(hedef, format, ...)` string'e yazar.
- `strtok(x, ";")` ilk parçayı, `strtok(NULL, ";")` sonraki parçaları verir; parça kalmayınca `NULL` döner.
- `scanf("%[^\n]", s)` boşluk içeren bütün satırı okur; `%*c` bir karakteri okuyup atar.
- `printf` yazdığı karakter sayısını döndürür; `%n` o ana kadar yazılan karakter sayısını bir değişkene koyar.
- `%-10s` sola, `%10s` sağa hizalar; `%.4d` ile 870 `0870` olarak yazılır.

## Detaylı Açıklamalar

### Fonksiyon işaretçisi ile bağlı liste

Ders, önceki haftanın çalışan (employee) bağlı listesi örneğiyle başlar. O örnekte `head` global tanımlandığı için hoca örneği parametre aktarımıyla yeniden yazar. Yapı şöyledir (ekrandan, 00:20:00):

```c
typedef struct Employee{
    char name[20];
    char surname[20];
    char id[12];
    struct Employee *next;
} EMPLOYEE;
//typedef struct Employee EMPLOYEE ;
int addRecord(EMPLOYEE **head);
int removeRecord(EMPLOYEE **head);
void printRecords(EMPLOYEE **head, void (*fptr) (EMPLOYEE*) );
void printNameFirst(EMPLOYEE *employee);
void printSurNameFirst(EMPLOYEE *employee);
void printIDFirst(EMPLOYEE *employee);
```

`main` içinde basit bir menü vardır (ekrandan, 00:25:00): `1-Add`, `2-Remove`, `3-Exit`. Ekleme sonrası liste `printIDFirst`, silme sonrası `printNameFirst` ile yazdırılır. Yani hangi biçimde yazdırılacağı, `printRecords`'a parametre olarak verilen fonksiyonla seçilir.

Ekleme fonksiyonu (ekrandan, 00:40:00):

```c
int addRecord(EMPLOYEE **head){
    EMPLOYEE *emp;
    emp = (EMPLOYEE*) malloc(sizeof(EMPLOYEE));
    if(emp==NULL){
        return -1;
    }
    printf("Enter name, surname, and id, respectively");
    scanf("%s %s %s",&emp->name,emp->surname,emp->id);
    emp->next=*head;
    *head=emp;
    return 0;
}
```

Hoca `name` alanının başına bilerek `&` koyar, diğerlerine koymaz: dizi adı zaten adres olduğu için `&` gerekmez, yazılırsa da aynı adres elde edilir.

> **Ders sonrası not:** `&emp->name` ifadesinin türü `char (*)[20]`'dir; adres değeri aynı olduğundan program çalışır, ama `gcc -Wall` bu satır için format uyarısı verir. Doğru kullanım `&` olmadan `emp->name`'dir.

Ekranda daha sonra iki derleme düzeltmesi yapılır: prototipte `printRecords` tek işaretçi (`EMPLOYEE *head`) olarak değiştirilir, çünkü yazdırma `head`'i değiştirmez; `scan` yazım hatası `scanf` yapılır ve `malloc` uyarısı için `<stdlib.h>` eklenir (ekrandan, 00:45:00).

Silme fonksiyonunun görülen kısmı (ekrandan, 00:40:00 ve 00:45:00) ve anlatıma göre gövdesi:

```c
int removeRecord(EMPLOYEE **head){
    char id[12];
    int found=0;
    printf("Enter id to remove from list"); scanf("%s",id);
    EMPLOYEE *tmp=*head;
    EMPLOYEE *prev=NULL;
    while(tmp!=NULL && !found){
        if(strcmp(tmp->id,id)==0){
            found=1;
            if(prev==NULL)
                *head=tmp->next;
            else
                prev->next=tmp->next;
            free(tmp);
        }
        prev = tmp;
        tmp=tmp->next;
    }
    return found;
}
```

<!-- BELİRSİZ: if bloğunun iç satırları (52-59) karede görülmedi; anlatıma göre yazıldı. -->

> **Ders sonrası not:** Ekranda `prev = tmp; tmp = tmp->next;` satırları `if` bloğunun dışındadır. Bu durumda kayıt bulunup `free(tmp)` yapıldıktan sonra `tmp->next` okunur; bu, serbest bırakılmış belleğe erişimdir (tanımsız davranış). Hocanın anlatımı ("bulamadıysak ... ilerlet") bu iki satırın `else` içinde olması gerektiğini gösterir. Bu düzeltilmiş hali (else ile) `gcc -Wall` ile derlenip hocanın girdileriyle (A A 1, B B 2, C C 3 ekle; 2, 1, 4 sil) çalıştırıldı ve beklenen çıktıyı verdi.

Yazdırma fonksiyonu (ekrandan, 00:45:00):

```c
void printRecords(EMPLOYEE *head, void (*fptr)(EMPLOYEE *)){
    EMPLOYEE *tmp=head;
    while(tmp!=NULL){
        fptr(tmp);
        tmp = tmp->next;
    }
}
```

`printNameFirst`, `printSurNameFirst` ve `printIDFirst` fonksiyonları tek düğüm alır ve `printf("%s %s %s\n", ...)` ile alanları farklı sırada yazar.

### Neden çift işaretçi: `swap3` ve `swap4`

Hoca, bir öğrencinin sorusu üzerine önceki haftanın swap örneğini açar (ekrandan, 00:30:00). `main` içinde `x = 1`, `y = 5`, `px = &x`, `py = &y` vardır. Hoca belleği şöyle çizer: `x`'in adresi 10, `y`'nin adresi 20; `px`'in kendi adresi 100, `py`'nin 200.

- `swap3(px, py)`: fonksiyonun yerel `x` ve `y` işaretçilerine 10 ve 20 kopyalanır. `int *t = x; x = y; y = t;` yalnız bu yerel kopyaları değiştirir. Fonksiyon bitince yerel değişkenler yok olur; `px` ve `py` hâlâ eski yerleri gösterir.
- `swap4(&px, &py)`: yerel `x`'e 100, `y`'ye 200 gelir. `t = *x` ile `px`'in içindeki 10 alınır, `*x = *y` ile `px`'e 20 yazılır, `*y = t` ile `py`'ye 10 yazılır. Sonuçta `px` `y`'yi, `py` `x`'i gösterir.

Kural: fonksiyon içinde bir işaretçinin gösterdiği yer değiştirilecekse, o işaretçinin adresi bir derece üst işaretçiyle (`**`) gönderilir. Bağlı listenin `head`'i için de durum budur.

Program çıktısı `gcc -Wall` ile doğrulandı: `1 5`, `1 5` (`swap`), `5 1` (`swap2`), `5 1` (`swap3` değişiklik yapmaz), `1 5` (`swap4` işaretçileri takas eder).

### Yapı dizisinde takas ve yapı kopyalama

Oyuncu yapısında (`pname[20]`, `tname[20]`, `avg`) takım adına göre kabarcık sıralaması yapılır (ekrandan, 00:55:00). Hoca önce `name` üyesini üç `strcpy` ile takas etmeyi gösterir, sonra yapıların bütün olarak `=` ile takas edildiğini anlatır:

```c
for (i = 1; i < n; i++)
    for (j = 0; j < n - i; j++) {
        if (strcmp(player[j].tname, player[j + 1].tname) > 0) {
            temp = player[j];
            player[j] = player[j + 1];
            player[j + 1] = temp;
        }
    }
```

Atama operatörü yapılar üzerinde tanımlıdır ve içerideki karakter dizileri de kopyalanır. Hoca ayrıca `CopyStruct` örneğinde üç yöntemi gösterir (ekrandan, 01:15:00 ve 01:20:00): `record2 = record1;`, `memcpy(record3, ptr1, sizeof(record1));` ve üye üye kopyalama. Adresler `%p` ile yazdırıldığında kopyanın alanlarının başka adreslerde olduğu görülür. Kaynağın `name` alanının bir karakteri değiştirildiğinde kopyalar etkilenmez; yani karakter dizileri de kopyalanmıştır.

Örnek koddaki bir hatayı da gösterir: `record3` bir işaretçi olarak tanımlanmış ama hiçbir yeri göstermemektedir. `memcpy` ile ona yazmak çalışma zamanında hata verir. Çözüm `record3`'ü normal bir yapı değişkeni yapıp `memcpy(&record3, &record1, sizeof(record1));` yazmaktır.

### Bit alanları

Gün en fazla 31, ay en fazla 12 olduğu halde ikisi için de 32 bitlik `int` kullanmak israftır. Ekrandaki örnek (ekrandan, 01:40:00):

```c
typedef struct {
    unsigned int d;
    unsigned int m;
    unsigned int y;
} DATE;     // 12 byte 96 bit

typedef struct {
    unsigned int d:5;
    unsigned int m:4;
    unsigned int y:11;
} MYDATE;   // 4 byte 32 bit
```

Gün için 5 bit ($2^5 = 32$ değer, 0-31), ay için 4 bit (0-15), yıl için 11 bit ($2^{11} = 2048$) yeter. Toplam 20 bit tek bir 4 baytlık birime sığar. `gcc` ile `sizeof(DATE) = 12`, `sizeof(MYDATE) = 4` doğrulandı.

Bit alanlarına okuma geçici değişkenle yapılır (ekrandan, 01:45:00):

```c
MYDATE d2;
printf("Enter day month and year");
scanf("%d %d %d",&gun,&ay,&yil);
if(gun>=1 && gun <=31 && ay>=1 && ay<=12){
    d2.d=gun;
    d2.m=ay;
    d2.y=yil;
}
```

> **Ders sonrası not:** Ekranda koşul `ay=<13` diye yazılmıştı; C'de `=<` operatörü yoktur. Hocanın söylediği koşul "ay 1'den büyük eşit ve 13'ten küçük" olduğundan doğrusu `ay < 13` (ya da `ay <= 12`) olur.

### Union

Union'da bütün üyeler aynı adresten başlar. Slayttaki örnekte (ekrandan, 01:55:00) `struct { char c1, c2; } s; long j; float x;` üyeleri 1000-1003 adreslerindeki 4 baytı paylaşır. `example.s.c1 = 'a'; example.s.c2 = 'b';` yazıldıktan sonra `example.j = 5;` yapılırsa iki karakter silinir.

Hocanın derste yazdığı örnekte union bir `char` çiftinden oluşan yapı, bir `int` ve bir `double` içerir. Ekran çıktısı (ekrandan, 02:25:00): `Sizeof(char)=1`, `Sizeof(int)=4`, `Sizeof(double)=8`, `Sizeof(u)=8`. `x = 5` atandıktan sonra `x` 5 olarak okunur, `y` bozulur; `y = 4.4` atandıktan sonra `x` `-1717986918` olarak okunur.

### Karakter ve string kütüphaneleri

- `getchar` klavyeden bir karakter okur. Önceki girişten kalan Enter karakterini temizlemek için `fflush(stdin)` kullanıldı.
- `scanf("%s", x)` boşlukta durur; `scanf("%[^\n]", x)` satır sonuna kadar okur. Aynı işi `gets` yapar ve sonuna `\0` ekler.
- `sscanf("1 2 33", "%d %d %d", &a, &b, &c)` string'deki sayıları değişkenlere ayırır; `sprintf(x, ...)` biçimli çıktıyı `x` dizisine yazar.
- `strtok` string'i verilen ayraçlara göre parçalar; ilk çağrıda string, sonrakilerde `NULL` verilir.
- `memcpy` istenen sayıda baytı kopyalar, `memmove` çakışan bölgelerde de güvenlidir, `memcmp` karşılaştırır, `memset` ilk n bayta aynı karakteri yazar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
