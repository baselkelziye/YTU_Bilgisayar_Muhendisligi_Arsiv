# Ders 11 Genişletilmiş Notu: Fonksiyon İşaretçili Bağlı Liste, Yapı Kopyalama, Bit Alanları, Union ve String Fonksiyonları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. typedef ve İç İçe Yapılar
- 2. Fonksiyon İşaretçisiyle Bağlı Liste Uygulaması
- 3. Neden Çift İşaretçi: swap3 ve swap4
- 4. Yapı Dizisini Sıralama ve Yapı Takası
- 5. Bir Yapıyı Başka Bir Yapıya Kopyalama
- 6. İç İçe Yapı Tanımlama Biçimleri
- 7. Yapı Hizalaması
- 8. Bit Alanları
- 9. Union
- 10. Karakter İşleme ve Dönüşüm Fonksiyonları
- 11. Standart Giriş/Çıkış String Fonksiyonları
- 12. string.h Fonksiyonları
- 13. Biçimli Giriş ve Çıkış
- Örnek Sorular
- Dersin Toparlaması

## 1. typedef ve İç İçe Yapılar

Ders, dosya işlemlerine geçmeden önce bazı küçük konuları tamamlamak amacıyla başlar. Hoca bu konuların öğrencilerin dönem projesinde de işe yarayacağını söyler. İlk örnek, önceki haftanın çalışan (employee) bağlı listesidir. O örnekte liste başı (`head`) global tanımlanmıştı. Hoca global tanımlamanın yapılmaması gerektiğini hatırlatır ve örneği parametre aktarımıyla baştan yazar.

Önce yapı `typedef` olmadan yazılır, ardından ayrı bir satırla tür adı verilir (ekrandan, 00:15:00):

```c
struct Employee{
    char name[20];
    char surname[20];
    char id[12];
    struct Employee *next;
};
typedef struct Employee EMPLOYEE;
```

`typedef` bir türe yeni bir ad verir; verilen ad, eski türün yerine geçer. Aynı iş, yapı tanımının başına `typedef` yazıp kapanış parantezinden sonra yeni adı vererek de yapılır: `typedef struct Employee {...} EMPLOYEE;` (ekrandan, 00:20:00). Hoca ayrı satırdaki tanımı yorum satırı olarak bırakır.

Hoca sonra iç içe yapıları (nested structures) hatırlatır. Kişinin doğum tarihi de tutulmak istenirse yıl, ay ve gün için bir tarih yapısı tanımlanıp çalışan yapısının içine üye olarak konabilir. Bu durumda tarih yapısının önce tanımlanması gerekir. Erişim iki noktayla yapılır: çalışan değişkeni `e` ise `e.birthDate.day` gibi.

İkinci yol, tarih yapısını çalışan yapısının içine doğrudan yazmaktır: `struct { int year, month, day; } birthDate;`. Üç üye aynı türden olduğu için yan yana yazılabilir. Bunun avantajı her şeyin tek yerde yazılmasıdır. Dezavantajı, bu tarih türünden başka bir değişken oluşturulamamasıdır; çünkü ortada adı olan açık bir tür tanımı yoktur ve derleyici buna izin vermez.

## 2. Fonksiyon İşaretçisiyle Bağlı Liste Uygulaması

### 2.1 Senaryo ve prototipler

Senaryo şudur: kayıt başa eklenecek, verilen kimliğe göre silinecek ve kayıtlar yazdırılacak. Yazdırma sırasında kayıtlar bazen önce ad, bazen önce soyad, bazen önce kimlik olacak şekilde farklı biçimlerde yazdırılmak istenir. Bunun için yazdırma fonksiyonu bir fonksiyon işaretçisi alır. Hangi biçim isteniyorsa o biçimi yazan fonksiyon parametre olarak gönderilir. Hoca, görsel programlamada da bir fonksiyona fonksiyonu parametre olarak göndermenin çok yapıldığını söyler.

Prototipler (ekrandan, 00:20:00):

```c
int addRecord(EMPLOYEE **head);
int removeRecord(EMPLOYEE **head);
void printRecords(EMPLOYEE **head, void (*fptr) (EMPLOYEE*) );
void printNameFirst(EMPLOYEE *employee);
void printSurNameFirst(EMPLOYEE *employee);
void printIDFirst(EMPLOYEE *employee);
```

`printRecords`'un ikinci parametresi, `EMPLOYEE *` alan ve `void` döndüren bir fonksiyonun adresidir. `printRecords` listeyi gezerken her düğümü bu fonksiyona verir.

### 2.2 main ve menü

`main` içinde liste başı `EMPLOYEE *head = NULL;` olarak tanımlanır. Başlangıçta listede hiçbir şey yoktur. Basit bir menü kurulur (ekrandan, 00:25:00):

```c
int main(){
    EMPLOYEE *head=NULL;
    int option=0;
    while(option!=3){
        printf("1-Add\n2-Remove\n3-Exit\n");
        scanf("%d",&option);

        switch(option){
            case 1: addRecord(&head); printRecords(head,printIDFirst); break;
            case 2: removeRecord(&head); printRecords(head,printNameFirst); break;
        }
    }
}
```

`addRecord`'a `head`'in adresi gönderilir, çünkü başa ekleme yapılacağı için `head` değişecektir. Ekleme sonrası liste kimlik önce, silme sonrası ad önce olacak şekilde yazdırılır.

### 2.3 Başa ekleme

Fonksiyon başarılı olup olmadığını dönüş değeriyle bildirir: `0` başarılı, `-1` başarısız. Hoca bu tür dönüş değerlerinin hata ayıklarken işe yaradığını söyler. Yeni düğüm için `malloc` ile yer ayrılır. Dizilerde 100 elemanlı bir çalışan dizisi doğrudan tanımlanabilir, ama bağlı listede düğümler tek tek açılır. Kod (ekrandan, 00:40:00):

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

Hoca `scanf` satırında `name`'in başına `&` koyar, diğer ikisine koymaz. Karakter dizisinin adı zaten ilk elemanın adresi olduğu için `&` gerekmez. Bir `int` dizisinin bir elemanı okunacak olsaydı indisli eleman için `&` şart olurdu.

> **Ders sonrası not:** `&emp->name` ile `emp->name` aynı adres değerini verir, bu yüzden program doğru çalışır. Ancak `&emp->name`'in türü `char (*)[20]`'dir ve `gcc -Wall` `%s` için format uyarısı verir. `&` olmadan yazmak doğrudur.

Başa eklemenin mantığını hoca şöyle çizer: listede düğümler vardır ve `head` ilk düğümü göstermektedir. Önce yeni düğümün `next`'i, `head`'in gösterdiği yeri göstermelidir: `emp->next = *head;`. Bu anda hem `head` hem yeni düğüm aynı ilk düğümü gösterir. Sonra `head` yeni düğümü göstermelidir: `*head = emp;`. Çift işaretçi kullanılmasının asıl nedeni bu son satırdır; fonksiyon, `main`'deki `head`'in içeriğini değiştirir.

Hoca, düğümün `next` alanını başlangıçta `NULL` yapmanın genelde doğru olduğunu, ama burada kayıt başa eklendiği ve `next` hemen `*head` ile doldurulduğu için gerek olmadığını belirtir.

### 2.4 Kimliğe göre silme

Silinecek kayıt başta, ortada ya da sonda olabilir. Önce kullanıcıdan bir kimlik okunur. Silme işleminde yeni düğüm oluşturmaya gerek yoktur. Arama için iki geçici işaretçi kullanılır: `tmp` gezilen düğümü, `prev` bir önceki düğümü gösterir. `prev` gereklidir, çünkü bulunan düğümün öncesi ile sonrası birbirine bağlanarak düğüm aradan çıkarılır. `found` değişkeni kaydın bulunup bulunmadığını tutar ve fonksiyonun dönüş değeridir.

Ekranda görülen başlangıç (ekrandan, 00:40:00) ve son kısım (ekrandan, 00:45:00) ile anlatıma göre fonksiyon:

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

<!-- BELİRSİZ: if bloğunun iç satırları karede görülmedi; anlatıma göre yazıldı. -->

> **Hocanın vurgusu:** `while (tmp != NULL && !found)` çok kullanılan bir kalıptır. Döngü ya listenin sonuna gelindiğinde (bulunamadan) ya da kayıt bulunduğunda biter.

Hoca adımları şöyle anlatır:

- Kimlikler string olduğu için `==` ile karşılaştırılamaz; `strcmp` kullanılır ve sonuç sıfırsa kayıt bulunmuştur.
- Bulunduysa `found = 1` yapılır.
- `prev == NULL` ise aranan kayıt ilk kayıttır, yani `head` silinecektir. `head`'in gösterdiği adres `tmp->next` yapılır.
- Değilse kayıt ortada ya da sondadır: `prev->next = tmp->next;` ile önceki düğüm bulunan düğümün sonrasına bağlanır.
- Bulunan düğüm `free` ile serbest bırakılır.
- Bulunamadıysa önce `prev = tmp`, sonra `tmp = tmp->next` yapılır. Böylece iki işaretçi peş peşe ilerler.

Hoca ayrıca `prev`'in başlangıçta `NULL` yapılması gerektiğini söyler; ilk kayıt kontrolü buna dayanır.

> **Ders sonrası not:** Ekranda `prev = tmp; tmp = tmp->next;` satırları `if` bloğunun dışında, döngünün sonundadır (ekrandan, 00:45:00). Kayıt bulunduğunda `free(tmp)` yapıldıktan sonra `tmp->next` okunur; bu, serbest bırakılmış belleğe erişimdir ve tanımsız davranıştır. Döngü `found` sayesinde hemen biteceği için derste sorun görünmedi. Hocanın anlatımına uygun olan, bu iki satırın `else` bloğunda olmasıdır. Bu düzeltilmiş hali `gcc -Wall` ile derlendi ve hocanın girdileriyle çalıştırıldı.

### 2.5 Yazdırma ve fonksiyon işaretçisi

Yazdırma `head`'i değiştirmediği için tek işaretçi yeterlidir. Hoca ilk derlemede "conflicting types" hatası alınca prototipteki çift işaretçiyi de tek işaretçiye çevirir. Fonksiyon (ekrandan, 00:45:00):

```c
void printRecords(EMPLOYEE *head, void (*fptr)(EMPLOYEE *)){
    EMPLOYEE *tmp=head;
    while(tmp!=NULL){
        fptr(tmp);
        tmp = tmp->next;
    }
}
```

`fptr` hangi fonksiyonu gösteriyorsa, her düğüm o fonksiyona gönderilir. Üç yazdırma fonksiyonu tek bir düğüm alır ve `printf("%s %s %s\n", ...)` ile alanları farklı sırada yazar. Ör. `printNameFirst` ad, soyad, kimlik sırasını kullanır.

Derleme sırasında `removeRecord` içindeki `scan` yazım hatası `scanf` yapılır, `malloc` uyarısı için `<stdlib.h>` eklenir (ekrandan, 00:45:00). Program çalıştırılır: A A 1, B B 2, C C 3 eklenir; her ekleme başa yapılır. Sonra kimliği 2 olan kayıt silinir, D D 4 eklenir, 1 ve 4 silinir. Hoca, fonksiyon işaretçisiyle ve parametre geçişiyle, global değişken kullanmadan işin yapıldığını vurgular.

**Soru:** `printRecords`'ta `fptr`'nin içine `tmp`'yi verdik; `fptr` ile fonksiyon mu döndürüyorduk? **Cevap:** Hayır, fonksiyon döndürülmüyor; fonksiyon parametre olarak alınıyor. Hangi fonksiyon kullanılacaksa o gönderiliyor.

## 3. Neden Çift İşaretçi: swap3 ve swap4

Bir öğrencinin çift işaretçinin neden gerektiğini sorması üzerine hoca önceki haftanın swap örneğini yeniden açar (ekrandan, 00:30:00):

```c
void swap4(int **x, int **y);
void swap3(int *x, int *y);
int main(){
    int x=1, y=5;
    int *px, *py;
    px=&x;
    py=&y;
    printf("%d %d\n",x,y); // 1 5
    swap(x,y);
    printf("%d %d\n",x,y); // 1 5
    swap2(&x,&y);
    printf("%d %d\n",x,y); // 5 1
    swap3(px,py);
    printf("%d %d\n",*px,*py); // 5 1
    swap4(&px,&py);
    printf("%d %d\n",*px,*py); // 1 5

    return 0;
}
void swap3(int *x, int *y){
    int *t=x;
    x=y;
    y=t;
}
```

`swap` değerleri yalnız yerel kopyalarda değiştirir. `swap2` adresler üzerinden değerleri değiştirir. Soru biraz değiştirilir: `px` `x`'i, `py` `y`'yi göstermektedir; öyle bir fonksiyon yazılmalı ki sonunda `py` `x`'i, `px` `y`'yi göstersin.

Hoca belleği çizer: `x`'in adresi 10 (içinde 1), `y`'nin adresi 20 (içinde 5). `px`'in kendi adresi 100 (içinde 10), `py`'nin kendi adresi 200 (içinde 20).

`swap3(px, py)` çağrıldığında fonksiyonun kendi yerel işaretçi değişkenleri oluşur ve içlerine 10 ve 20 kopyalanır. `t`'ye 10, `x`'e 20, `y`'ye 10 yazılır. Fonksiyon bitince bu yerel değişkenler yok olur; ömürleri (duration) otomatiktir. `main`'deki `px` ve `py` hiç değişmemiştir.

`swap4(&px, &py)` çağrıldığında yerel `x`'e 100, yerel `y`'ye 200 gelir. Adımlar:

- `t = *x`: `x` 100'ü gösterir, 100 adresindeki değer 10'dur. `t = 10`.
- `*x = *y`: `y` 200'ü gösterir, oradaki değer 20'dir. 100 adresine (yani `px`'e) 20 yazılır.
- `*y = t`: 200 adresine (yani `py`'ye) 10 yazılır.

Fonksiyon bittiğinde `px` `y`'yi, `py` `x`'i gösterir.

> **Hocanın vurgusu:** Gösterilen bir şey fonksiyon içinde değiştirilecekse bir derece üst işaretçi gerekir. Fonksiyon çağrıldığında `head`'in gösterdiği yer değişecekse, yerel değişken bir derece üst işaretçiyle tanımlanır ki `main`'deki `head`'in değeri değiştirilebilsin.

**Soru:** Tek işaretçi neden olmuyor, çift işaretçi neden oluyor; böyle mi tasarlanmış? **Cevap:** Bu bir tasarım tercihi değil, değerlerin kopyalanmasının sonucudur. Birinci derece işaretçi birinci derece bir değişkenin adresini tutar; onunla o değişkenin içeriği değiştirilir. `swap2` `x` ile `y`'nin içeriğini değiştirdiği gibi, `swap4` de `px` ile `py`'nin içeriğini değiştirir. `swap1` ve `swap3` değişikliği yalnız yerelde yapar, gerçek tarafa yansıtmaz.

Program `gcc -Wall` ile derlenip çalıştırıldı; çıktı yorumlardaki gibidir: `1 5`, `1 5`, `5 1`, `5 1`, `1 5`.

## 4. Yapı Dizisini Sıralama ve Yapı Takası

Hoca öğrencilere uygulamada yapılan sıralama çalışmasında yapı üyelerini nasıl takas ettiklerini sorar: üyeleri tek tek mi, yoksa toptan mı kopyaladılar? Bu tür sıralamaya hoca "nesnesel sıralama" (object sort) der: şimdiye kadar isim, soyisim ya da kimlik gibi tek değerler sıralanmıştı; burada nesneler (yapılar) içlerindeki bir alana göre sıralanır.

Örnek kodda oyuncu yapısı `pname[20]`, `tname[20]` ve `avg` alanlarından oluşur. Sıralama takım adına göre yapılır (ekrandan, 00:55:00):

```c
for (i = 1; i < n; i++)
    for (j = 0; j < n - i; j++) {
        if (strcmp(player[j].tname, player[j + 1].tname) > 0) {
            strcpy(tmp,player[j].name);
            strcpy(player[j].name, player[j+1].name);
            strcpy(player[j+1].name,tmp);
            temp = player[j];
            player[j] = player[j + 1];
            player[j + 1] = temp;
        }
    }
```

Üç `strcpy` satırı, hocanın üye üye takası göstermek için eklediği kısımdır. Bir string üye için 20 elemanlı geçici bir karakter dizisi ve üç satır gerekir. `tmp = player[j].name` yazılamaz, çünkü ikisi de adrestir ve adresler eşittir operatörüyle birbirine atanarak arkadaki veriler kopyalanmaz. Üç üye için dokuz satır gerekir; otuz üyeli bir yapıda bu çok masraflı olur.

Bu yüzden son üç satırdaki gibi yapıların kendisi `=` ile takas edilir. Atama operatörü yapılar üzerinde tanımlıdır.

Hoca tahtada `temp = player[j]` atamasını çizerek anlatır: `temp`'in `pname`, `tname`, `avg` alanlarına `player[j]`'deki değerler gelir (ör. "abc", "xyz", 8). Ardından `player[j] = player[j+1]` ile `player[j]`'ye sonraki kaydın değerleri ("aaa", "bbb", 9) gelir, son olarak `player[j+1] = temp` yapılır ve iki kayıt yer değiştirir.

<!-- BELİRSİZ: Hoca bu çizimde string alanlar için "adres kopyalanıyor, deep copy yapılan aslında sadece average" der; ancak bu yapıda alanlar işaretçi değil dizidir ve dizi içerikleri de kopyalanır. Hoca birkaç dakika sonra CopyStruct örneğinde atamanın stringleri de birebir kopyaladığını gösterir (Bölüm 5). -->

> **Hocanın vurgusu:** Yapının içinde `malloc` ile ayrılmış bir diziyi gösteren bir işaretçi varsa (önceki dersteki polinom örneği gibi) `=` yalnız adresi kopyalar. `tmp = player[j]` yapılıp sonra bir taraftan değişiklik yapılırsa orijinal veri de değişir. Takas (swap) işleminde ise adresler yer değiştirdiği için sorun olmaz.

Hoca bu örneği de global değişkenlerden kurtarır ve 5 kayıtla çalıştırır (ekrandan, 01:00:00). Kayıtlar takım adına göre sıralanmış olarak yazdırılır.

## 5. Bir Yapıyı Başka Bir Yapıya Kopyalama

Aradan sonra hoca, `strcpy` ya da `=` kullanmadan da kopyalama yapılabileceğini söyler: `memcpy`. Fonksiyonun Linux kılavuz sayfası (man page) ve bir C başvuru sayfası gösterilir. `memcpy`, kaynak (`src`) ile gösterilen bellek bölgesindeki n baytı hedef (`dest`) ile gösterilen bölgeye kopyalar ve hedefin işaretçisini döndürür. Bölgeler çakışmamalıdır; çakışıyorsa `memmove` kullanılmalıdır. Parametre sırası önce hedef, sonra kaynak, sonra boyuttur. Parametreler `void *` olduğu için her türden veri kopyalanabilir.

Başvuru sayfasındaki örnekte bir kişinin adı, `strlen(myname) + 1` bayt (sondaki `\0` dahil) kopyalanarak `person.name`'e yazılır. Hoca bunun `strcpy`'ye çok benzediğini, `strcpy`'nin aslında `memcpy`'nin özelleşmiş hali gibi olduğunu söyler. Bütün bir yapı `memcpy(&person_copy, &person, sizeof(person));` ile kopyalanabilir.

Hoca ardından internetten aldığı `CopyStruct` örneğini açar (ekrandan, 01:15:00):

```c
struct student
{
    int id;
    char name[30];
    float percentage;
};

int main()
{
    int i;
    struct student record1 = {1, "Raju", 90.5};
    struct student record2, *record3, *ptr1, record4;
    ...
    // 1st method to copy whole structure to another structure
    record2=record1;
```

Hoca her alanın adresini `%p` ile yazdıran satırlar ekler (ekrandan, 01:20:00):

```c
printf("  Id : %p \n  Name : %p\n  Percentage : %p\n",
&record2.id, &record2.name, &record2.percentage);
```

Çıktıda `record1`'in alanlarının adresleri `62FDF0`, `62FDF4`, `62FE14` olarak görülür. `id` 4 bayt yer kaplar, `name` 4 bayt sonra başlar. Hoca `name`'in 30 bayt olduğunu, `FDF4`'e 30 (onaltılıkta `1E`) eklendiğinde `FE12` çıkması gerektiğini, aradaki 1-2 baytlık farkın boşluklardan (gap) kaynaklandığını söyler. `record2`'nin alanları ise `62FDC0`, `FDC4`, `FDE4` gibi başka adreslerdedir: veriler kopyalanmış, adresler farklıdır.

Hoca sonra `record1.name`'in bir karakterini `x` yapar ve üç kaydı yeniden yazdırır. Değiştirilen kayıtta ad `Rxju` olur, kopya ise `Raju` olarak kalır. Bu, atama operatörünün string alanı da birebir kopyaladığını gösterir.

İkinci yöntem `memcpy`'dir (ekrandan, 01:20:00):

```c
// 2nd method to copy using memcpy function
ptr1 = &record1;
memcpy(record3, ptr1, sizeof(record1));
```

Hoca örneği aldığı yerdeki hatayı gösterir: `record3` bir işaretçidir ama hiçbir yeri göstermemektedir. Program çalışır ama hata verir, çünkü böyle bir bellek adresi yoktur. Çözüm, `record3`'ü normal bir yapı değişkeni yapmak ve `memcpy(&record3, &record1, sizeof(record1));` yazmaktır. Bu durumda `ptr1`'e de gerek kalmaz. Yazdırma `record3.id` biçiminde yapılır. Ok operatörü kullanılmak istenirse `ptr1 = &record3;` yapılıp `ptr1->id`, `ptr1->name`, `ptr1->percentage` yazdırılabilir.

Üçüncü yöntem üyeleri tek tek kopyalamaktır:

```c
// 3rd method to copy by individual members
record4.id=record1.id;
strcpy(record4.name, record1.name);
```

Bu, normal bir tamsayı atamasından farksızdır. Yapılabilir, ama üye sayısı çok fazlaysa zahmetlidir; bu yüzden pek kullanılmaz.

## 6. İç İçe Yapı Tanımlama Biçimleri

Hoca önceki yılın örneklerinden iç içe yapılarla ilgili bir dosya açar (ekrandan, 01:25:00). Önce gün, ay, yıl içeren bir yapı `typedef` ile `TARIH` adıyla tanımlanmıştır ve çalışan yapısında `TARIH tarih;` olarak kullanılır:

```c
typedef struct {
    char isim[30];
    int maas;
    TARIH tarih;
}CALISAN;
```

İkinci biçimde tarih yapısı çalışanın içine isimsiz yazılır:

```c
typedef struct {
    char isim[30];
    int maas;
    struct {
        char gun;
        char ay;
        char yil;
    }tarih;          // sadece bir kez kullanilabilir

}CALISAN;
```

Burada `struct`'ın yanına bir ad yazılmamıştır; içeride üretilen değişkenin adı `tarih`'tir. İsim, maaş ve tarih çalışanın üç değişkenidir. Bu tarih türü başka bir yerde kullanılamaz.

Değişken adı yazmadan iç yapı tanımlamak (`struct tarih {...};` yazıp altında bir değişken üretmemek) hatalıdır; en azından bir değişken tanımlanmalıdır. `typedef` ile tanımlanmışsa iç içe yapılara ilk değer küme parantezleriyle verilebilir; verilmezse çöp değerler gelir. İç alana `calisan.tarih.ay` biçiminde erişilir.

> **Hocanın vurgusu:** Nesnesel mantıkla en doğrusu tarihi ayrı bir tür olarak tanımlamaktır. Tarih yalnız çalışana özgü değildir; başka yerlerde de gerekebilir. Ayrı tanım hem modülerlik hem nesnesellik açısından daha doğrudur.

## 7. Yapı Hizalaması

Slaytlardan devam edilir. Bazı bilgisayarlarda nesneler ikinin katı adreslere yerleştirilir; bu, kullanılan değişkenlerin boyutlarıyla ilgilidir. Programcı bunu doğrudan görmez, ama varlığından haberdar olup tasarımını ona göre yapmalıdır. Bellekte dolu yerlerin bitişik olması, gereksiz boşluklar olmaması bellek performansı açısından önemlidir.

Slayttaki örnekte bir `char`, bir `short` (2 bayt) ve bir `char` sırasıyla tanımlanır. Hizalama yapılmazsa üyeler art arda durabilir. Hizalama yapılırsa `mem1`'den sonra bir bayt boşluk, ardından `mem2`, sonra `mem3` gelir. Bu yüzden `char` değişkenlerin art arda, `short`'un önce ya da sonra yazılması önerilir.

<!-- BELİRSİZ: Hizalama slaytındaki şekil ve ayrıntılar karede görülmedi; anlatım altyazıdan alındı. -->

## 8. Bit Alanları

### 8.1 Tanım

Slayt (ekrandan, 01:30:00):

- The smallest data type that C supports is char (8 bits).
- But in structures, it is possible to declare a smaller object called a bitfield.
- Bit fields behave like other int variables, except that:
  - You cannot take the address of a bit field and
  - You cannot declare an array of bit fields.

Hoca gün, ay, yılın üçü için de `int` kullanmanın israf olduğunu anlatır. 4 baytlık bir `int` yaklaşık 2 milyara kadar değer tutar; oysa ay en fazla 12, gün en fazla 31'dir. Bit alanlarıyla daha küçük alanlar oluşturulup bellek daha verimli kullanılır.

Bit alanının adresi alınamaz. Hoca bunu şöyle açıklar: bellekte bir adres ayrıldığında bit alanları o adresin içindeki bitlerin bir kısmını kullanır; adresin altındaki alt parçaların ayrı adresleri yoktur. Ayrıca bit alanlarından dizi oluşturulamaz.

Tanımlama, yapı içinde üye adından sonra iki nokta ve bit sayısı yazılarak yapılır: `int a:5;` 5 bitlik bir sayı oluşturur. Başına `unsigned` getirilirse alanda yalnız pozitif değerler saklanır. `int too_long:17;` gibi bir alan 32 bitin 17'sini kullanır. Slayttaki olası yerleşimde 3, 7 ve 2 bitlik üç alan toplam 12 bit tutar.

Ardışık bit alanları bir birimin sınırını aşarsa, derleyici alanı bölmek yerine boşluk bırakıp alanı sonraki birimden başlatabilir. Slayttaki gün, ay, yıl örneğinde bir yerleşimde ay alanı iki birime bölünürken alternatif yerleşimde derleyici alanları kaydırmadan en uygun yere yerleştirir. Hoca bu ayrıntılara fazla girmeyeceklerini söyler.

### 8.2 Bit alanlı yapı içeren bağlı liste örneği

Slayttaki örnekte kişi bilgileri (ad, kimlik numarası, doğum günü, ayı, yılı) bit alanlı bir yapıda tutulur ve bağlı listeye eklenir. Kayıt okuma fonksiyonu (ekrandan, 01:35:00):

```c
ELEMENT *create_list_element(){
    ELEMENT *p;
    int val; //ilkel ve bitfield olduğu için geçici değişken şart
    p=(ELEMENT*) malloc (sizeof (ELEMENT));
    if(p == NULL) { printf("create_list_element (): malloc failed. \n"); exit(1); }
    printf("Enter name of the person:"); scanf("%s", p->ps_name);
    printf("Enter tcno of the person:"); scanf("%s", p->ps_tcno);
    printf("Enter the birth-date (day) of the person:"); scanf("%u", &val); p->ps_birth_day=val;
    printf("Enter the birth-date (month) of the person:"); scanf("%u", &val); p->ps_birth_month=val;
    printf("Enter the birth-date (year) of the person:"); scanf("%u", &val); p->ps_birth_year=val;
    p->next=NULL; return p;
}
void add_element(ELEMENT *e){
    ELEMENT *p;
    if(head==NULL){ head=e; return; }
    for (p=head; p->next != NULL; p=p->next); // null statement
    p->next=e;
}
```

Örnekte `head` statik ve global tanımlanmıştır; hoca bunu tercih etmediklerini, `main` içinde `NULL` bir `head` tanımlamanın yeterli olduğunu söyler. Bit alanlarını yazdırırken bir sorun yoktur. Okurken ise `scanf` adres ister, ama `&p->ps_birth_day` yazılamaz. Bu yüzden geçici bir değişkene okunur ve değer bit alanına kopyalanır. Eleman sona eklenir.

Hoca tahtada 5 bitlik işaretsiz alanın 0-31 arası değer alabileceğini, 65 gibi bir değer yazılırsa alanın bunu sığdıracak şekilde keseceğini ve yanlış bir değer saklanacağını anlatır. Bu yüzden atamadan önce değerin 0-31 arasında olup olmadığını bir `if` ile kontrol etmek en doğrusudur.

> **Ders sonrası not:** Hoca 65 için saklanacak değeri "muhtemelen 3'ün karşılığı gibi bir şey" diye tahmin etti. İşaretsiz bit alanında değer $2^5 = 32$ modunda saklanır: $65 \bmod 32 = 1$. `gcc` ile `d2.d = 65;` atamasından sonra alan 1 olarak okundu (derleyici de "changes value from 65 to 1" uyarısı verir).

### 8.3 Derste yazılan örnek: DATE ve MYDATE

Hoca önce normal bir tarih yapısı yazar ve boyutunu sorar (ekrandan, 01:40:00):

```c
typedef struct {
    unsigned int d;
    unsigned int m;
    unsigned int y;
}DATE;  // 12 byte 96 bit

typedef struct {
    unsigned int d:5;
    unsigned int m:4;
    unsigned int y:11;
}MYDATE;  // 4 byte 32 bit
```

<!-- BELİRSİZ: Bu karede `struct` anahtar sözcüğü `strcut` diye yazılmıştı; sonraki karede (01:50:00) düzeltilmiş hali görülüyor. -->

**Soru:** `DATE`'in boyutu nedir? **Cevap (öğrenci):** 12 bayt. Hoca doğrular: `int` genelde 4 bayttır, üç tanesi 12 bayt (96 bit) eder.

Hoca sonra gün için kaç bit gerektiğini sorar: ayın 1'inden 31'ine kadar değer saklamak için 5 bit yeter, çünkü $2^5 = 32$ farklı değer (0-31) tutar. Ay için 4 bit (en fazla 15) yeter. Yıl için hoca $2^{11} = 2048$'in şimdilik yeterli olduğunu söyler.

> **Ders sonrası not:** Hoca hesaplarken $2^{13}$ için "8148 mi?" dedi; doğrusu $2^{13} = 8192$'dir. $2^{12} = 4096$ ve $2^{16} = 65536$ değerleri doğru söylendi.

5 + 4 + 11 = 20 bit tek bir 4 baytlık birime sığar; `MYDATE` 4 bayt (32 bit) yer tutar. Hoca `printf("Size of (DATE)=%d ",sizeof(DATE));` ve aynısını `MYDATE` için yazdırır; sonuç 12 ve 4 çıkar. Bu değerler `gcc` ile de doğrulandı.

Veri girişi kısmı (ekrandan, 01:45:00):

```c
int main(){
    int gun, ay, yil;
    printf("Size of (DATE)=%d ",sizeof(DATE));
    printf("Size of (MYDATE)=%d ",sizeof(MYDATE));

    DATE d;
    printf("Enter day month and year");
    scanf("%d %d %d",&d.d,&d.m,&d.y);
    printf("%d %d %d",d.d,d.m,d.y);

    MYDATE d2;
    printf("Enter day month and year");
    scanf("%d %d %d",&gun,&ay,&yil);
    if(gun>=1 && gun <=31 && ay>=1 && ay=<13){
        d2.d=gun;
        d2.m=ay;
```

Normal yapıda alanlara doğrudan okunur. `MYDATE` için önce `gun`, `ay`, `yil` geçici değişkenlerine okunur, kontrol edilir, sonra bit alanlarına atanır. Hoca bu kontrol mantığına "iş kuralı" (business rule) der.

> **Ders sonrası not:** Ekranda koşulda `ay=<13` yazılmıştı. C'de `=<` operatörü yoktur, derleme hatası verir. Hocanın söylediği koşul "ay 13'ten küçük" olduğu için doğrusu `ay < 13` ya da `ay <= 12`'dir. Bu düzeltilmiş koşulla kod `gcc -Wall` ile derlenip denendi.

Hoca bit alanına doğrudan okumayı da dener: `scanf("%d", &d2.m)` yazıldığında derleyici "cannot take address of bit-field 'm'" hatası verir. Bu derleme zamanında yakalanır. Hoca bu satırı "illegal" diye yorum satırı olarak bırakır, çünkü bazı öğrencilerin özellikle bunu denediğini söyler.

**Soru:** `d2` ile `d` aynı verileri tutsa da aralarında `=` ya da `memcpy` ile kopyalama yapılamaz, değil mi? **Cevap:** Evet; `d2 = d` gibi bir atama "incompatible types" hatası verir, çünkü türler birbirine atanamaz.

**Soru:** Bit sayıları yazılmamış olsaydı, yani iki yapının içeriği birebir aynı olsaydı yine olmaz mıydı? **Cevap:** Hoca ekranda içeriği birebir aynı iki ayrı tür (`DATE` ve `DATE1`) tanımlar ve birinden diğerine atama yapar; bu da hata verir. Türler farklı adlarla ayrı tanımlandığı için eşittir operatörü bu atama için tanımlı değildir. C'de operatör yeniden tanımlanamaz (başka dillerde yapılabilir), ama alanları tek tek kopyalayan bir `assign` fonksiyonu yazılabilir.

Dizi konusunda hoca bir düzeltme yapar: bit alanlı yapı türünden dizi tanımlanabilir (`MYDATE d4[10];` hatasız derlenir). "Bit alanından dizi oluşturulamaz" ifadesiyle kastedilen, yapının içinde 5 bitlik alanı dizi olarak tanımlamaktır (`unsigned int d[10]:5;` gibi). Ekranda bu deneme "bit-field 'd' width not an integer constant" gibi hatalar verir (ekrandan, 01:50:00).

## 9. Union

### 9.1 Tanım ve boyut

Bir yapıda üyelerin her biri bellekte ayrı bir yerde durur. Union'da ise bütün üyeler aynı bellek alanını kullanır. Bu yüzden bir üye değiştirildiğinde diğeri de değişir.

Hoca kullanım için şu örneği verir: Türk vatandaşları için kimlik numarası, yabancı uyruklu kişiler için pasaport ya da başka bir kimlik numarası saklanabilir. İkisi aynı yerde tutulabilir; kişi vatandaşsa alana kimlik numarası olarak, değilse diğer kimlik olarak erişilir.

**Soru:** Üç üyeli (`a`, `b`, `x`) bir union'ın bellekte kapladığı yer ne kadardır? **Cevap (öğrenci):** En büyük üye kadar. Hoca doğrular: yapıda boyut üyelerin boyutları toplamıdır, union'da ise bütün üyeler aynı yeri gösterdiği için yer en büyük üyeye göre açılır ki o üye kayıpsız tutulabilsin. Ör. `char` 1, `int` 4, `double` 8 bayttır; union 8 bayt olur.

### 9.2 Slayttaki örnek

Slayt (ekrandan, 01:55:00):

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

Union içinde bir yapı tutulabilir. Burada yapı iki karakterlik yer tutar, `long` ve `float` 4'er bayttır. Üyeler 1000-1003 adreslerindeki 4 baytı paylaşır.

```c
example.s.c1 = 'a';
example.s.c2 = 'b';
```

Hoca önce `a` için 93 der, sonra düzeltir: `'a'` 97, `'b'` 98'dir. 1000 adresinde 97, 1001'de 98 vardır; diğer baytlar 0 kabul edilirse `j` okunduğunda bu baytların oluşturduğu tamsayı görülür.

> **Ders sonrası not:** Hoca 97'nin ikilik karşılığını tahtada birkaç denemeyle buldu. Doğrusu: $97 = 64 + 32 + 1 = 01100001_2$, $98 = 01100010_2$, $65 = 01000001_2$.

Slayttaki son satır: `example.j = 5;` atamasından sonra iki karakter silinir ve 5 sayısını tutmak için 4 baytın tamamı kullanılır.

### 9.3 Derste yazılan union örneği

Hoca bir union tanımlar: içinde `a` ve `b` adlı iki `char` alanlı, `c` adlı bir yapı; bir `int x` ve bir `double y`. Önce boyutlar yazdırılır (ekrandan, 02:25:00):

```text
Sizeof(char)=1
Sizeof(int)=4
Sizeof(double)=8
Sizeof(u)=8
6
a b -351575455 0.000000
♣   5 0.000000
Ü Ö -1717986918 4.400000
```

<!-- BELİRSİZ: Union ve main kodunun tamamı karede görülmedi; tanım ve çıktı satırlarının yorumu altyazıdan yapıldı. Çıktıdaki "6", getchar denemesinde girilen karakterdir. -->

İç yapıya başta bir değişken adı verilmediği için alanlarına erişilemez; hoca bu yüzden iç yapı değişkenine `c` adını verir. `element.c.a = 'a'; element.c.b = 'b';` atamalarından sonra `%c %c %d %lf` ile `element.c.a`, `element.c.b`, `element.x`, `element.y` yazdırılır. İlk iki bayt `a` ve `b`'dir; `x` bu iki bayt ile kalan çöp baytlardan oluşan bir tamsayıdır.

`element.x = 5` atandıktan sonra ilk bayt 5 olur (ekranda bir kontrol karakteri gibi görünür) ve `x` 5 olarak okunur. `element.y = 4.4` atandıktan sonra `y` 4.4 olarak okunur, ama `x` ve karakterler anlamsız değerlere dönüşür. Hoca, bu yapıda iki üyenin aynı anda anlamlı olmasının beklenmediğini, ya birinin ya diğerinin kullanılacağını söyler.

> **Ek bilgi (derste anlatılmadı):** 4.4'ün IEEE 754 çift duyarlıklı gösterimi `0x401199999999999A`'dır. Küçük uçlu (little-endian) bellekte ilk 4 bayt `0x9999999A` olur; bu, işaretli 32 bitlik tamsayı olarak $-1717986918$'dir. İlk iki bayt `0x9A` ve `0x99`, Windows konsolunun kod sayfasında `Ü` ve `Ö` olarak görünür. Bu değerler `gcc` ile doğrulandı.

### 9.4 Yapı içinde union

Slayttaki bir sonraki örnekte kişi bilgileri tutulur: ad, kimlik ya da pasaport numarası, doğum tarihi ve vatandaşlık durumunu gösteren tek bitlik bir bayrak (bit alanı). Kişi Türk vatandaşıysa doğum yeri, değilse uyruğu (hangi ülkeden olduğu) istenir. İki alanı da yapıda ayrı tutmak her kayıtta kullanılmayan 20 karakterlik bir alan demektir. Bunun yerine yapının içinde bir union tanımlanır; kayıt ya doğum yeri alanını ya uyruk alanını kullanır.

**Soru:** İki alan için aynı değişken kullanılsaydı olur muydu? **Cevap:** O da olur, çok büyük bir sorun değildir. Ama kurgu veritabanı ya da nesnesel mantıkla düşünüldüğünde union hangi alanın okunacağını (bayrağa göre) daha anlaşılır kılar.

Okurken de bayrağa göre okunan veri ya uyruk alanına ya doğum yeri alanına yazılır. Hoca bu örneğin kodunu daha sonra geliştireceklerini söyler.

## 10. Karakter İşleme ve Dönüşüm Fonksiyonları

### 10.1 Karakter ve string

Karakterin arkasında bir tamsayı (ASCII kodu) vardır. String, sonunda `\0` olan bir karakter dizisidir ve dizi gibi indislenebilir. `char color[] = "blue";` ve `char *colorPtr = "blue";` tanımları da kullanılabilir. `"blue"` için `sizeof` 5 verir, çünkü sondaki `\0` da sayılır. `scanf("%s", word)` ile okurken dizinin adı ilk elemanın adresini tuttuğu için `&` gerekmez; yazılsa da aynı adres elde edilir. Bu yüzden yapı üyesi bir karakter dizisi okunurken de `&` yazmaya gerek yoktur.

### 10.2 ctype.h

Karakter işleme kütüphanesindeki fonksiyonlar:

- `isdigit`: rakam mı?
- `isalpha`: harf mi?
- `isalnum`: harf ya da rakam mı?
- `isxdigit`: onaltılık rakam mı?
- `islower`, `isupper`: küçük/büyük harf mi?
- `tolower`, `toupper`: küçük/büyük harfe çevirir.
- `isspace`: boşluk, `\n`, `\f`, `\r`, `\t`, `\v` ise doğru (sıfırdan farklı) döner.
- `iscntrl`: kontrol karakteri mi?
- `ispunct`: noktalama işareti mi?
- `isprint`: yazdırılabilir karakter mi (boşluk dahil)?
- `isgraph`: boşluk dışındaki yazdırılabilir karakter mi?

Slayttaki örnekte çeşitli karakterler bu fonksiyonlarla sınıflanır: ör. `8` rakamdır. `J` onaltılık rakam değildir, çünkü onaltılık rakamlar 0-9 ve A-F'dir.

> **Ders sonrası not:** Hoca `toupper`'ın arka planında küçük harfe 32 eklendiğini, `tolower`'da 32 çıkarıldığını söyledi. ASCII'de büyük harfler küçük harflerden 32 önce gelir (`'A'` 65, `'a'` 97). Doğrusu: büyük harfe çevirmek için 32 çıkarılır, küçük harfe çevirmek için 32 eklenir.

### 10.3 stdlib.h dönüşüm fonksiyonları

String'den sayıya dönüşüm fonksiyonları `<stdlib.h>` içindedir. Bunların bir kısmı daha önce `main` argümanları anlatılırken görülmüştü; `main` argümanları da string olarak gelir.

- `atof`: string'i `double`'a çevirir.
- `atoi`: string'i `int`'e çevirir.
- `atol`: string'i `long`'a çevirir.
- `strtod`: string'i `double`'a çevirir.
- `strtol`: string'i `long`'a çevirir; istenen taban verilebilir.
- `strtoul`: string'i `unsigned long`'a çevirir.

String'in içeriği dönüştürülebilir bir ifade olmalıdır.

## 11. Standart Giriş/Çıkış String Fonksiyonları

Slayt (ekrandan, 02:30:00):

| Fonksiyon prototipi | Açıklama |
|---|---|
| `int getchar( void );` | Standart girişten sonraki karakteri okur ve tamsayı olarak döndürür. |
| `char *gets( char *s );` | Standart girişten yeni satır ya da dosya sonu görülene kadar karakterleri `s` dizisine okur; sonuna null karakter ekler. |
| `int putchar( int c );` | `c`'deki karakteri yazdırır. |
| `int puts( const char *s );` | `s` string'ini yazdırır ve ardından yeni satır yazar. |
| `int sprintf( char *s, const char *format, ... );` | `printf` gibidir, ama çıktı ekrana değil `s` dizisine yazılır. |
| `int sscanf( char *s, const char *format, ... );` | `scanf` gibidir, ama giriş klavyeden değil `s` dizisinden okunur. |

### 11.1 getchar ve fflush

`getchar`, programın akışını bir yerde durdurmak için (ör. program hemen kapanmasın ya da hata ayıklarken beklesin diye) kullanılabilir. Hoca bir karakter okuyup bir daha okumayı dener; ikinci okumada program beklemez, çünkü önceki girişteki Enter karakteri tamponda kalmıştır. `fflush(stdin)` ile standart giriş temizlenince ikinci okuma da beklenir.

> **Ek bilgi (derste anlatılmadı):** `fflush(stdin)` C standardında tanımlı değildir; Windows'taki derleyicide çalışır, başka sistemlerde çalışmayabilir. Taşınabilir yol, satır sonuna kadar karakterleri `getchar` ile okuyup atmaktır.

### 11.2 Boşluk içeren string okumak

Hoca `char x[20]; scanf("%s", x);` ile okuma yapar. `abc` girildiğinde sorun yoktur, ama araya boşluk konunca yalnız boşluğa kadar olan kısım okunur. Bunu aşmak için `scanf("%[^\n]", x);` kullanılır: `\n` görülene kadar bütün karakterleri oku. Hoca bunun düzenli ifade (regular expression) konusuna benzediğini söyler. Tampon temizlenmezse önceki Enter bu okumayı da etkiler, bu yüzden önce `fflush(stdin)` yapılır. Hoca standart girişin de bir dosya gibi bir işaretçi olduğunu belirtir.

Aynı işi `gets` daha kısa yapar: bir satırı `\n` görene kadar okur ve sonuna otomatik `\0` ekler. Parametre olarak karakter işaretçisi alır; dönüş değeri de vardır ama sonuç zaten parametreye yazılır.

> **Ek bilgi (derste anlatılmadı):** `gets` dizinin boyutunu bilmediği için taşmaya açıktır ve C11 standardından çıkarılmıştır. Yerine `fgets(x, sizeof(x), stdin)` kullanılır; `fgets` satır sonundaki `\n`'yi de diziye koyar.

`putchar` bir karakteri yazar. `puts` `const char *` alır (içeride değiştirilmediğini gösterir) ve string'i ekrana basar.

### 11.3 sprintf ve sscanf

`sscanf`, `scanf`'in karşılığıdır ama klavye yerine hazır bir string'den okur. Hoca tahtada şu örneği yazar: `sscanf("1 2 3", "%d %d %d", &a, &b, &c);` ile 1, 2, 3 sırasıyla `a`, `b`, `c`'ye aktarılır (ekrandan, 02:35:00). Hoca bunu derste `"1 2 33"` ile dener ve `1 2 33` değerlerini görür.

`sprintf` ise tersini yapar: önce hedef dizi, sonra biçim yazılır ve biçimli çıktı diziye yazılır. Hoca `x` dizisine iki `%d`, bir `"abcd"` string'i, bir `%d` ve bir `%s` yazdırır; değişkenler sırasıyla `a`, `c`, `b` ve `"1234"`'tür. `x` yazdırıldığında 1, 33, abcd, 2 ve 1234 değerleri sırayla görülür.

<!-- BELİRSİZ: sprintf biçim dizesinin tam hali (ayraçlar) karede görülmedi. Sonraki strtok denemesinde parçaların noktalı virgülle ayrıldığı söylendiği için ayraç büyük olasılıkla noktalı virgüldür. -->

**Soru (hoca):** Dosyadan okuma ve yazma için kullanılan iki fonksiyon hangileriydi? **Cevap (öğrenci):** `fprintf` ve `fscanf`.

Hoca bu fonksiyonların nerede kullanılabileceğini, öğrencilerin projesindeki bir ders dosyası üzerinden gösterir (ekrandan, 02:35:00). Dosyanın her satırında ders kodu, ders adı ve kredi vardır ve alanlar virgülle ayrılmıştır, ör. `BLM1012,Yapısal Programlamaya Giris,6`. Bu satır doğrudan `fscanf` ile alanlarına okunabilir. Alternatif olarak dosyadan bir satır string olarak okunur ve `sscanf` ile değişkenlere (ad, ders adı, kredi) ayrılır.

> **Hocanın vurgusu:** `sprintf` ve `sscanf` çok kullanışlı fonksiyonlardır; projede kullanılmaları tavsiye edilir.

### 11.4 Özyinelemeli tersten yazdırma

Slayttaki bir örnek, bir cümleyi okuyup özyinelemeli bir fonksiyonla tersten yazdırır. Fonksiyon `sPtr[0]` `\0` değilse kendini `&sPtr[1]` ile çağırır, dönüşte `putchar(sPtr[0])` yapar. `"ABC"` için önce `"BC"`'nin, sonra `"C"`'nin adresi gönderilir; en sonda `C`, sonra `B`, sonra `A` yazılır.

<!-- BELİRSİZ: Bu slayt karede görülmedi; kod altyazıdaki anlatıma göre özetlendi. -->

## 12. string.h Fonksiyonları

### 12.1 Kopyalama, birleştirme ve karşılaştırma

- `strcpy(s1, s2)`: `s2`'yi `s1`'e kopyalar; `s1` hedeftir.
- `strncpy(s1, s2, n)`: en fazla `n` karakter kopyalar.
- `strcat(s1, s2)`: `s2`'yi `s1`'in sonuna ekler; sonuç `s1` üzerindedir ve `s1` döndürülür.
- `strncat(s1, s2, n)`: `s2`'nin en fazla `n` karakterini ekler.
- `strcmp(s1, s2)`: karakter karakter karşılaştırır. Çok kullanılır.
- `strncmp(s1, s2, n)`: ilk `n` karaktere kadar karşılaştırır.

### 12.2 Arama fonksiyonları ve strtok

Arama fonksiyonları (`strchr`, `strcspn`, `strstr` vb.) bir karakterin ya da string'in başka bir string içinde ilk geçtiği yeri bulur. Slayttaki bir örnekte bir string'in diğerinin içinde bulunduğu konum 13 olarak gösterilir.

<!-- BELİRSİZ: Arama fonksiyonlarının slayt tablosu ve 13 sonucunu veren örnek karede görülmedi. -->

`strtok`, string'i verilen ayraçlara (noktalı virgül, boşluk vb.) göre parçalara (token) böler ve her parçanın başına bir karakter işaretçisi döndürür. Slayttaki örnek (ekrandan, 02:40:00):

```c
/* Fig. 8.29: fig08_29.c
   Using strtok */
#include <stdio.h>
#include <string.h>

int main()
{
   char string[] = "This is a sentence with 7 tokens";
   char *tokenPtr;

   printf( "%s\n%s\n\n%s\n",
           "The string to be tokenized is:", string,
           "The tokens are:" );

   tokenPtr = strtok( string, " " );

   while ( tokenPtr != NULL ) {
      printf( "%s\n", tokenPtr );
      tokenPtr = strtok( NULL, " " );
   }

   return 0;
}
```

Çıktıda "This", "is", "a", "sentence", "with", "7", "tokens" ayrı satırlarda yazılır. Hoca aynı şeyi kendi `sprintf` ile oluşturduğu `x` string'i üzerinde dener: `p = strtok(x, ";");` ile ilk parça alınır; `while (p != NULL)` döngüsünde `p` yazdırılır ve `p = strtok(NULL, ";");` ile sonraki parçaya geçilir. Sonraki çağrılarda ilk argüman `NULL` verilir; fonksiyon kaldığı yerden devam eder. Ekranda 1, 33, abcd ve diğer parçalar ayrı ayrı yazdırılır. Hoca parçaların bir dizide saklanabileceğini, bunun string tutan bir dizi, yani karakter matrisi olacağını söyler.

### 12.3 Bellek fonksiyonları

`<string.h>` içindeki bellek fonksiyonları `void *` ile çalışır; herhangi türden veriye uygulanabilir.

- `memcpy(s1, s2, n)`: `s2`'den `s1`'e `n` bayt kopyalar.
- `memmove(s1, s2, n)`: `n` bayt taşır; bölgeler çakışsa da doğru çalışır.
- `memcmp(s1, s2, n)`: ilk `n` baytı karşılaştırır; eşitse 0, `s1` küçükse negatif, büyükse pozitif döndürür.
- `memset(s, c, n)`: `s`'nin ilk `n` baytına `c` karakterini yazar. Ör. üç baytlık bir alana `'a'` (97) yazılabilir.

`strerror` önceden tanımlanmış hata numaralarının metnini döndürür; slayttaki örnekte 2 numaralı hata "No such file or directory"dir. `strlen` string'in uzunluğunu verir.

## 13. Biçimli Giriş ve Çıkış

Hoca biçimli giriş/çıkışı yalnız `printf`/`scanf` için değil, dosyadan biçimli okuma ve yazma (`fprintf`, `fscanf`) ve string'ler (`sprintf`, `sscanf`) için de düşünmek gerektiğini söyler; giriş ve çıkış klavye ve ekran dışındaki kaynaklar da olabilir.

### 13.1 Dönüşüm belirteçleri

- Tamsayılar: `%d`, `%i`, `%o` (sekizlik), `%u` (işaretsiz), `%x`/`%X` (onaltılık); `h` ve `l` gibi ekler `short` ve `long` için kullanılır.
- Kayan noktalı sayılar: `%f`, `%e`/`%E` (üstel gösterim), `%g`/`%G`. `double` okumak için `%lf` kullanılır.
- `%c` tek bir karakteri, `%s` `\0` görülene kadar bir string'i yazar. `"This is a string"` için `%c` yalnız `T`'yi yazar.
- `%p` bir işaretçiyi (adresi) yazar.
- `%n` o ana kadar yazılan karakter sayısını ilgili tamsayı değişkenine koyar; `\n` gibi bir kaçış değil, bir dönüşüm belirtecidir.
- `%%` yüzde işaretini yazar.

`printf` yazdığı karakter sayısını döndürür. Slayttaki örnekte bir satırda yazılan karakter sayısı `%n` ile bir değişkene alınır ve sonra yazdırılır; dönüş değeriyle de aynı bilgi elde edilir. Hoca, bu örnekte 28 karakter yazıldığını gösterir.

### 13.2 Alan genişliği ve duyarlık

Alan genişliği, değer için ayrılacak karakter sayısıdır. Ör. öğrenci numarası 10 karakter olacaksa dosyaya `%10d` ile yazılır. Kayan noktalı sayılarda duyarlık virgülden sonraki basamak sayısını belirler (`%9.3f`). Genişlik ve duyarlık programın çalışması sırasında da verilebilir: `%*.*f` yazılır ve değerler argüman olarak geçirilir.

Slayttaki örnekte tamsayılarda duyarlık en az basamak sayısıdır: `%.4d` 870'i başına sıfır ekleyerek `0870` olarak yazar; `%.9d` dokuz basamak ayırır. `gcc` ile `printf("[%.4d]", 870)` çıktısı `[0870]` olarak doğrulandı.

### 13.3 Bayraklar

Slayt (ekrandan, 02:50:00):

| Bayrak | Açıklama |
|---|---|
| `-` (eksi) | Çıktıyı alan içinde sola hizalar. |
| `+` (artı) | Pozitif değerlerin önüne artı, negatiflerin önüne eksi koyar. |
| boşluk | `+` bayrağıyla yazılmayan pozitif değerin önüne bir boşluk koyar. |
| `#` | Sekizlik `o` ile başa `0`, onaltılık `x`/`X` ile başa `0x`/`0X` ekler; `e`, `E`, `f`, `g`, `G` ile kesir kısmı olmasa da ondalık noktayı yazar; `g` ve `G`'de sondaki sıfırları silmez. |
| `0` (sıfır) | Alanı baştaki sıfırlarla doldurur. |

Hoca örnek olarak `%10s` ile `hello`'nun sağa, `%-10s` ile sola hizalandığını; `%10d` ile 7'nin önünde boşluklarla yazıldığını gösterir. `g` için `#` kullanıldığında ondalık kısmın da yazıldığını söyler.

<!-- BELİRSİZ: Hoca hizalama örneğinde eksi işaretinin sola, artının sağa hizaladığını söyledi; slayttaki tabloya göre artı bayrağı hizalama değil işaret gösterme içindir. -->

### 13.4 Kaçış dizileri

- `\a`: uyarı sesi çıkarır.
- `\b`: imleci bulunduğu satırda bir karakter geri götürür.
- `\n`: yeni satır.
- `\r`: imleci satırın başına götürür.
- `\t`: yatay sekme.
- `\v`: dikey sekme.

### 13.5 scanf ile biçimli okuma

`scanf` biçimi, `fscanf` ve `sscanf` için de aynıdır.

- Tarama kümesi: `%[aeiou]` yalnız kümedeki karakterleri okur; `%[^aeiou]` kümedekiler dışındakileri okur. `%[^\n]` Enter görülene kadar okur.
- Atlama: `%*c` bir karakteri okur ama saklamaz.

Slayttaki tarih okuma örneğinde sayıların arasına `%*c` konur (`"%d%*c%d%*c%d"` biçiminde). Böylece kullanıcı ayları ve günleri tire ile, eğik çizgiyle ya da arada başka bir karakterle girse de ayraç atlanır ve sayılar doğru okunur. Hoca bunu genel bir biçim olarak önerir: kullanıcı tireyi unutup başka bir ayraç koysa da değişkenler alınabilir. `gcc` ile `sscanf("13-12-2021", "%d%*c%d%*c%d", ...)` denemesi 13, 12, 2021 değerlerini verdi.

<!-- BELİRSİZ: Tarih okuma slaytı karede görülmedi; biçim altyazıdaki anlatıma göre yazıldı. -->

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): Aşağıdaki programda dört `printf` satırı ne yazar? `swap3(int *x, int *y)` yerel işaretçileri, `swap4(int **x, int **y)` işaretçilerin gösterdiği yeri takas eder.

```c
int x=1, y=5;
int *px=&x, *py=&y;
swap(x,y);        printf("%d %d\n",x,y);
swap2(&x,&y);     printf("%d %d\n",x,y);
swap3(px,py);     printf("%d %d\n",*px,*py);
swap4(&px,&py);   printf("%d %d\n",*px,*py);
```

> **Çözüm (derste verildi, gcc ile doğrulandı):** `1 5`, `5 1`, `5 1`, `1 5`. `swap` hiçbir şeyi değiştirmez; `swap2` `x` ile `y`'nin değerlerini takas eder; `swap3` yalnız yerel kopyaları değiştirir; `swap4` ile `px` `y`'yi (artık 1), `py` `x`'i (artık 5) gösterir.

**Soru 2** (derste sözlü, 01:37:35): `unsigned int d, m, y;` üyeli `DATE` yapısının boyutu nedir? Gün saklamak için en az kaç bit gerekir? `d:5`, `m:4`, `y:11` bit alanlı yapının boyutu nedir?

> **Çözüm (derste verildi, gcc ile doğrulandı):** `DATE` 12 bayttır (3 × 4 bayt = 96 bit). Gün 1-31 arası olduğu için 5 bit yeter ($2^5 = 32$). Bit alanlı yapı toplam 20 bit kullanır ve tek bir 4 baytlık birime sığar; `sizeof(MYDATE) = 4`.

**Soru 3** (derste sözlü, 01:51:51): `char`, `int` ve `double` üyeli bir union bellekte ne kadar yer kaplar?

> **Çözüm (derste verildi, gcc ile doğrulandı):** En büyük üye kadar: 8 bayt. Ekranda `Sizeof(u)=8` görüldü.

**Soru 4** (ekrandan, 01:55:00): `example.s.c1 = 'a'; example.s.c2 = 'b';` atamalarından sonra `example.j = 5;` yapılırsa `c1` ve `c2` ne olur?

> **Çözüm (derste verildi):** `j` 5 değerini tutmak için 4 baytın tamamını kullanır; iki karakter silinir. Derste verilmeyen ayrıntı: küçük uçlu bir sistemde `c1`'in yerinde 5, `c2`'nin yerinde 0 olur (derleyiciyle doğrulandı).

**Soru 5** (derste sözlü, 02:33:47): Dosyadan biçimli okuma ve yazma için hangi fonksiyonlar kullanılır? `sscanf` dosya okumada nasıl işe yarar?

> **Çözüm (derste verildi):** `fscanf` ve `fprintf`. Dosyadan bir satır string olarak okunduktan sonra `sscanf` ile virgülle ayrılmış alanlar (ders kodu, ders adı, kredi) ayrı değişkenlere ayrılabilir.

**Soru 6** (ekrandan, 01:35:00): Bit alanlı `ps_birth_day` üyesine `scanf("%u", &p->ps_birth_day);` ile doğrudan okunabilir mi? 5 bitlik işaretsiz alana 65 atanırsa ne olur?

> **Çözüm:** Okunamaz; bit alanının adresi alınamaz, derleyici hata verir. Geçici bir değişkene okunup atanır (derste verildi). 65 atanırsa değer $65 \bmod 32 = 1$ olarak saklanır (derste tam sonuç verilmedi; `gcc` ile doğrulandı). Bu yüzden atamadan önce aralık kontrolü yapılmalıdır.

## Dersin Toparlaması

Bu derste önce bağlı liste örneği global değişken kullanmadan yeniden yazıldı. `head`'in değiştiği ekleme ve silme işlemlerinde çift işaretçi, yalnız gezilen yazdırmada tek işaretçi kullanıldı. Kayıtların farklı biçimlerde yazdırılması, yazdırma fonksiyonuna bir fonksiyon işaretçisi geçirilerek sağlandı. Çift işaretçinin gerekçesi `swap3` ve `swap4` üzerinden bellek çizimiyle gösterildi. Yapılarla ilgili olarak yapı dizisinin `=` ile takası, yapı kopyalamanın üç yolu (`=`, `memcpy`, üye üye), iç içe yapı tanımlama biçimleri ve hizalama işlendi. Ardından bellekten tasarruf için bit alanları ve aynı bellek alanını paylaşan union yapısı örneklerle anlatıldı.

Dersin son bölümünde proje için yararlı olacak karakter ve string kütüphaneleri (`ctype.h`, `stdlib.h` dönüşümleri, `sprintf`/`sscanf`, `strtok`, bellek fonksiyonları) ve biçimli giriş/çıkış (alan genişliği, duyarlık, bayraklar, tarama kümeleri) gözden geçirildi. Hoca sonraki derste özyinelemeye ve ardından dosya işlemlerine daha ayrıntılı geçileceğini, vakit kalırsa iş parçacıklarının (thread) da anlatılabileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
