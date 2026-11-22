# Ders 24 Genişletilmiş Notu: Struct ve Bağlı Liste ile Dosyadan Nokta Okuma, İkili Arama Ağacı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Nokta Listesi Örneği: Yapılar ve Prototipler
- 3. Dosyadan Okuyup Bağlı Liste Kurmak
- 4. Listeyi Yazdırmak: İteratif ve Özyinelemeli
- 5. Orijine En Uzak Nokta: İşaretçi Parametreyle Değer Döndürmek
- 6. Bellek Bölgeleri ve Fonksiyondan Dönen Verinin Ömrü
- 7. Orijine En Uzak Nokta: Struct Döndürmek
- 8. Nokta Listesi Programının Tamamı
- 9. Kendi Türünden İşaretçi Tutan Yapılar ve Veri Yapıları
- 10. İkili Arama Ağacı ve Gezinme Algoritmaları
- 11. İkili Arama Ağacının Kodlanması
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Planı

Bu derste yeni bir teori konusu açılmadı. Hoca struct, dosya işlemleri ve özyinelemeyi birleştiren iki örnek hazırladığını söyledi. İlk örnekte bir dosyada satır satır duran nokta koordinatları okunur, bir bağlı listeye konur ve liste üzerinde "orijine en uzak nokta" gibi sorular çözülür. Aradan sonra kendi türünden işaretçi tutan yapılar slaytlar üzerinden gözden geçirildi; bağlı liste türleri, yığın, kuyruk ve ikili arama ağacı anlatıldı ve ikili arama ağacı baştan kodlandı.

Kod Dev-C++ üzerinde, ekranda yazıldı. Aşağıdaki kodlar karelerden alınmıştır.

## 2. Nokta Listesi Örneği: Yapılar ve Prototipler

Her nokta iki tamsayı koordinat tutar. Noktalar bağlı listede duracağı için her düğüm bir sonrakinin adresini de saklar. Hoca, en uzak noktanın bilgisini taşımak için ikinci bir yapı tanımladı: bu yapı uzaklık değerini ve o uzaklığa sahip düğümü gösteren bir işaretçiyi birlikte tutar (ekrandan, 00:15:00; alan adı sonra `ptr`'den `pt`'ye değiştirildi, ekrandan, 00:50:00).

```c
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Nokta{
    int x,y;
    struct Nokta *next;
};
typedef struct Nokta NOKTA;

typedef struct EnUzak{
    int d;
    NOKTA *pt;
}ENUZAKNOKTA;
```

Fonksiyonlar için prototipler yazıldı: dosya adını alıp listenin başını döndüren `dosyadanOku`, listeyi iteratif yazdıran `listeYaz`, özyinelemeli yazdıran `listeYazRec` ve en uzak noktayı bulan iki sürüm (ekrandan, 00:50:00):

```c
NOKTA* dosyadanOku(char*);
void listeYaz(NOKTA*);
void listeYazRec(NOKTA*);
NOKTA* enUzakNoktaBul(NOKTA *, int*);
ENUZAKNOKTA *enUzakNoktaBulv2(NOKTA *head);
```

`main` içinde okunacak dosyanın adı kullanıcıdan alınır. Hoca bunu bir alışkanlık hâline getirmeyi önerdi:

> **Hocanın vurgusu:** Dosya adını kodun içine gömmeyin, kullanıcıdan alın. Ödevlerde koda gömülü dosya adları değerlendirmeyi yapan asistanları çok zorluyor.

Dosya adı `char dosyaAdi[30];` dizisine `scanf("%[^\n]s", dosyaAdi);` ile okunur; `%[^\n]` biçimi satır sonuna kadar (boşluklar dahil) her şeyi alır.

> **Ek bilgi (derste anlatılmadı):** `%[^\n]` kendi başına tam bir dönüşüm belirtecidir; sondaki `s` ayrı bir düz karakter olarak eşleşmeye çalışılır ve burada etkisizdir. `scanf("%29[^\n]", dosyaAdi);` gibi bir genişlik sınırı vermek, 30 karakterlik diziyi taşırmayı önler.

## 3. Dosyadan Okuyup Bağlı Liste Kurmak

### 3.1 Sona ekleme için son düğümü saklamak

Hoca, listeye her yeni noktayı sona eklemek istedi; ama her eklemede listenin başından sonuna yürümek istemedi. Bunun için iki işaretçi birlikte tutulur: listenin başını gösteren `head` ve son düğümü gösteren `end`. Üçüncü işaretçi `tmp`, her satır için yeni oluşturulan düğümü gösterir. Başlangıçta liste boştur, `head = NULL`.

### 3.2 Fonksiyonun kodu

```c
Nokta* dosyadanOku(char *dosyaAdi){
    FILE *fp;
    NOKTA *head=NULL, *end, *tmp;
    fp=fopen(dosyaAdi,"r");
    if(fp==NULL){
        printf("Dosya acilamadi");
    }
    else{
        while(!feof(fp)){
            tmp=(NOKTA*) malloc(sizeof(NOKTA));
            fscanf(fp,"%d %d\n",&tmp->x,&tmp->y);
            tmp->next=NULL;
            if(head==NULL){
                head=end=tmp;
            }
            else{
                end->next=tmp;
                end=end->next;
            }
        }
        fclose(fp);
    }
    return head;
}
```

(ekrandan, 00:25:00; karede `fcanf` diye yazılmış olan çağrı burada `fscanf` olarak verildi, derleyen kodda da öyledir.)

Akış şöyledir. Dosya okuma kipinde (`"r"`) açılır; açılamazsa mesaj verilir. Açıldıysa dosya sonuna kadar (`feof`) her turda:

- `malloc` ile tek elemanlık bir düğüm açılır. Bu düğüm heap'tedir, yani program yaşadığı sürece vardır.
- `fscanf` ile satırdaki iki tamsayı düğümün `x` ve `y` alanlarına okunur; `\n` satır sonunu tüketir.
- `tmp->next` varsayılan olarak NULL yapılır.
- Liste boşsa (`head == NULL`) bu düğüm hem ilk hem son düğümdür: `head = end = tmp;`.
- Değilse eski son düğümün `next`'i yeni düğüme bağlanır ve `end` yeni düğüme taşınır.

Döngü bitince dosya `fclose` ile kapatılır ve listenin tamamına erişmek için gereken tek şey olan `head` döndürülür. Hoca heap'te açılan alanın program bitene kadar yaşadığını, hatta program çökse bile serbest bırakılmamış bellek olarak kalabildiğini de söyledi.

> **Ek bilgi (derste anlatılmadı):** `while(!feof(fp))` kalıbında `feof` ancak bir okuma dosya sonuna çarptıktan sonra doğru olur. Biçimdeki `\n` son satırın sonundaki boşlukları tükettiği için bu örnekte fazladan düğüm oluşmaz; ama dosya boşsa ya da sonda boş satırlar varsa içi belirsiz bir düğüm eklenebilir. Daha sağlam kalıp `while(fscanf(fp, "%d %d", &x, &y) == 2)` biçimidir.

## 4. Listeyi Yazdırmak: İteratif ve Özyinelemeli

### 4.1 İteratif yazdırma

Listede gezinmek için ikinci bir işaretçi gerekir; `head`'i kaybetmemek için `tmp = head` ile başlanır (ekrandan, 00:35:00):

```c
void listeYaz(NOKTA *head){
    NOKTA *tmp=head;
    while(tmp!=NULL){
        printf("(%d,%d)->",tmp->x,tmp->y);
        tmp=tmp->next;
    }
    printf("Null\n");
}
```

Her düğüm `(x,y)->` biçiminde yazılır, sonunda listenin bittiğini göstermek için `Null` yazılır. Hoca buna "klasik iteratif algoritma" dedi.

### 4.2 Özyinelemeli yazdırma

Hoca özyinelemeli fonksiyonların iki özelliğini hatırlattı: kendini çağırır ve bir temel durumu (base case) vardır. Prototip iteratif sürümle aynıdır (ekrandan, 00:35:00):

```c
void listeYazRec(NOKTA *head){
    NOKTA *tmp=head;
    if(tmp!=NULL){
        printf("(%d,%d)->",tmp->x,tmp->y);
        listeYazRec(tmp->next);
    }
    else{
        printf("Null\n");
    }
}
```

`tmp` NULL değilse listenin ortasında bir yerdeyizdir (birinci, ikinci ya da sekizinci düğüm olabilir). Önce o düğüm yazılır, sonra bir sonraki düğüme geçmek için fonksiyon `tmp->next` ile çağrılır. İlk çağrıda gelen `head`, yani birinci eleman yazılır; ikinci çağrıda ikinci eleman `head`'miş gibi gelir. En sonunda NULL'a ulaşılır, `if`'e girilmez ve `else` dalı `Null` yazar.

### 4.3 İlk çalıştırma ve hata ayıklama

Program derlendi, dosya adı olarak `veriler.txt` girildi ama "Dosya acilamadi" mesajı çıktı. Hoca hata ayıklayıcıyla incelerken sorunun `scanf` satırında olduğu anlaşıldı: biçim dizgisi `"[^\n]s"` diye, başında `%` olmadan yazılmıştı (ekrandan, 00:30:00). Bir öğrenci bunu fark etti, `"%[^\n]s"` olarak düzeltilince dosya okundu ve her iki fonksiyon da aynı listeyi yazdı. Dosyada ilk nokta (4,6), son nokta (5,5) idi.

## 5. Orijine En Uzak Nokta: İşaretçi Parametreyle Değer Döndürmek

### 5.1 İki yaklaşım

Hoca en uzak noktayı iki biçimde bulmak istedi. Birincisinde en uzak düğüm `return` ile döner, uzaklık değeri ise bir parametre üzerinden, adres yoluyla (hocanın deyişiyle call by reference mantığıyla) çağırana iletilir. İkincisinde her iki bilgi `ENUZAKNOKTA` yapısında toplanır ve yapı döndürülür. Liste artık bellekte olduğu için dosyaya tekrar gitmeye gerek yoktur.

### 5.2 Birinci sürüm

```c
NOKTA *enUzakNoktaBul(NOKTA *head, int *dmax){
    NOKTA *tmp=head, *max;
    int d=0;
    while(tmp!=NULL){
        d = pow(tmp->x,2) + pow(tmp->y,2);
        if(d>*dmax){
            *dmax=d;
            max=tmp;
        }
        tmp = tmp->next;
    }
    return max;
}
```

(ekrandan, 00:45:00)

Her düğümde uzaklığın karesi $d = x^2 + y^2$ hesaplanır. `pow`, `math.h` içindeki üs alma fonksiyonudur. Hoca karekök almaya gerek olmadığını söyledi: amaç yalnız karşılaştırmaktır ve karekök sıralamayı değiştirmez. Daha büyük bir değer bulunursa `*dmax` güncellenir ve düğüm `max`'ta saklanır. Döngü bitince `max` döndürülür; uzaklık değeri ise `*dmax = d` ataması sayesinde çağıranın değişkenine yazılmış olur.

`main` içinde çağrı şöyledir (ekrandan, 00:50:00):

```c
max = enUzakNoktaBul(head,&d);
```

`d` tamsayısının adresi gönderilir. Hoca bunun anlamını şöyle açıkladı: C'de bir fonksiyon `return` ile tek bir değer döndürür. Python ya da MATLAB gibi dillerde birden çok değer döndürülebilir, C ve Java'da doğrudan böyle bir şey yoktur. Ama işaretçi parametreleriyle istenildiği kadar bilgi dolaylı olarak geri alınabilir.

Ardından iki `printf` ile en büyük uzaklık değeri (`d`) ve en uzak noktanın koordinatları (`max->x`, `max->y`) yazdırıldı. Ekranda en büyük uzaklık 401, nokta (1,20) bulundu: $1^2 + 20^2 = 1 + 400 = 401$.

> **Ders sonrası not:** Ekranda `main` içindeki değişken `int d;` diye ilk değer verilmeden tanımlandı ve fonksiyon ilk karşılaştırmada `*dmax`'ın bu belirsiz değerini kullandı. Derste sonuç doğru çıktı, ama bu güvence değildir; değişken `int d = 0;` diye başlatılmalıdır. Ayrıca listede hiç düğüm yoksa `max` ilk değersiz döner.

## 6. Bellek Bölgeleri ve Fonksiyondan Dönen Verinin Ömrü

İkinci sürümde fonksiyon bir yapı döndürecekti. Hoca, döndürülen şeyin fonksiyon bittikten sonra da yaşaması gerektiğini, bunun için kapsam (scope) ve ömür (duration) kurallarını hatırlamak gerektiğini söyledi ve sınıfa iki yolu sordu. Birinin dinamik bellek (`malloc` gibi) olduğu söylendi; ikincisi için bellek düzeni anlatıldı.

Bilgisayarın bir program için ayırdığı bellekte şu bölgeler vardır:

- Program belleği: programın kodunun durduğu yer.
- Statik ve global değişkenler.
- İlk değeri verilmiş değişkenler.
- Stack (yığıt).
- Heap (yığın bellek).

Stack sınırlıdır. Bir fonksiyonda `int` ya da `char` gibi bir yerel değişken tanımlanınca stack'te yer alır; fonksiyon bitince o değişkene ulaşılamama olasılığı çok yüksektir, çünkü yerine başka bir şey konabilir. Heap ise program yaşadığı sürece kalır; oradan yer almak için dinamik bellek fonksiyonları kullanılır. İkinci yol `static` değişkendir: bir kez oluşturulur ve program kapanana kadar saklanır. Hoca bu örnekte dinamik bellek kullanacağını söyledi.

> **Hocanın vurgusu:** `ENUZAKNOKTA *ptr = ... malloc(...)` satırında `ptr` değişkeninin kendisi stack'tedir ve fonksiyon bitince etiket olarak hükmü kalmaz. Ama tuttuğu adres heap'tedir; bu adres `return ptr;` ile nereye döndürülürse orada yaşamaya devam eder.

## 7. Orijine En Uzak Nokta: Struct Döndürmek

### 7.1 İkinci sürüm

Hoca, en uzak noktayı ayrı bir `NOKTA` düğümü içinde döndürmenin de mümkün olduğunu (örneğin `x`'te bir şey, `y`'de uzaklığı saklayarak) ama bunun anlamsız olacağını söyledi; onun yerine ekstra bir struct kullandı:

```c
ENUZAKNOKTA *enUzakNoktaBulv2(NOKTA *head){
    NOKTA *tmp=head, *max;
    ENUZAKNOKTA *ptr=(ENUZAKNOKTA*) malloc(sizeof(ENUZAKNOKTA));
    int d=0;
    int dmax=0;
    while(tmp!=NULL){
        d = pow(tmp->x,2) + pow(tmp->y,2);
        if(d>dmax){
            dmax=d;
            max=tmp;
        }
        tmp=tmp->next;
    }
    ptr->d = dmax;
    ptr->pt=max;
    return ptr;
}
```

(ekrandan, 00:55:00; `malloc` satırı aşağıdaki düzeltmeyle verildi.)

Tek bir en uzak nokta olduğu için `malloc` ile bir elemanlık yer açılır. `dmax` burada yerel ve geçici bir değişkendir, karşılaştırma için kullanılır ve 0 ile başlatılır. Döngü bitince elde en uzak düğümün adresi (`max`) ve uzaklık değeri (`dmax`) vardır; ikisi yapının alanlarına yazılır ve yapının işaretçisi döndürülür.

> **Ders sonrası not:** Hoca kodu ilk yazdığında `malloc(sizeof(ENUZAKNOKTA*))` yazmıştı (ekrandan, 00:45:00 ve 00:55:00). Ağaç örneğine geçtiğinde bunu fark edip `sizeof(ENUZAKNOKTA)` olarak düzeltti: açılan şey yapının kendisidir, işaretçisi değil. Hoca boyutların sayısal olarak aynı olduğu için sonucun değişmediğini söyledi; büyük olasılıkla 64 bit derleyicide `int` + işaretçi yapısı 16 bayt, işaretçi 8 bayttır, yani küçük alan açılmış ve yapının sonuna taşma olmuştur. Programın doğru çalışması şanstır, doğrusu `sizeof(ENUZAKNOKTA)` yazmaktır.

### 7.2 Çağırma ve iç içe erişim

Dönen değer `NOKTA*` türündeki `max`'a atanamaz; bunun için `ENUZAKNOKTA *n;` tanımlanır. `n`, fonksiyonda `malloc` ile açılmış alanı gösterir:

```c
n = enUzakNoktaBulv2(head);
printf("...%d\n", n->d);
printf("...%d,%d\n", n->pt->x, n->pt->y);
```

<!-- BELİRSİZ: Sürüm 2 çıktısını yazan printf satırlarının tam metni karelerde görünmüyor; yapı altyazıdan kuruldu. -->

`n->pt->x`, "n'nin gösterdiği yapının içindeki `pt`'nin gösterdiği düğümdeki `x`" demektir. Hoca bu yapının nesneye yönelik programlamada çok karşılarına çıkacağını, Java'da ok yerine nokta kullanılacağını söyledi: bir öğrencinin aldığı derslerin ders kodu, ders adı gibi iki üç seviyeli iç içe ilişkilere nesnelerin referansları üzerinden erişilir.

İlk derlemede prototip yazılmamış olduğu için derleyici `enUzakNoktaBulv2` için "conflicting types" hatası ve işaretçiye tamsayı atama uyarısı verdi (ekrandan, 00:50:00). Prototip eklenince düzeldi ve sürüm 2 de 401 ve (1,20) sonucunu verdi.

> **Ek bilgi (derste anlatılmadı):** Bildirilmemiş bir fonksiyon çağrılınca eski C kuralları onu `int` döndüren bir fonksiyon sayar. Bu yüzden dönüş değerinin işaretçiye atanması uyarı, sonradan gelen gerçek tanım da tür çakışması hatası üretir.

### 7.3 Ne zaman struct döndürülür

Hoca, bu yaklaşımın özellikle bir veri setinden çok sayıda istatistik çıkarıldığında işe yaradığını söyledi. Yalnız en küçük ve en büyük değil, ortalama, standart sapma gibi 20 çeşit istatistik hesaplanacaksa hepsi ayrı bir struct'ta toplanıp döndürülür. Ayrı bir nesne gibi kullanılan böyle bir yapı her zaman daha düzenlidir.

## 8. Nokta Listesi Programının Tamamı

Aşağıdaki program, karelerdeki kodun birleştirilmiş hâlidir. `main`'in sonundaki `printf` metinleri altyazıdan kuruldu; `fscanf` ve `sizeof(ENUZAKNOKTA)` düzeltilmiş olarak yazıldı. Ajan `gcc -Wall` ile uyarısız derledi ve `4 6`, `1 20`, `9 8`, `3 3`, `5 5` satırlı bir dosyayla çalıştırdı.

```c
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Nokta{
    int x,y;
    struct Nokta *next;
};
typedef struct Nokta NOKTA;

typedef struct EnUzak{
    int d;
    NOKTA *pt;
}ENUZAKNOKTA;

NOKTA* dosyadanOku(char*);
void listeYaz(NOKTA*);
void listeYazRec(NOKTA*);
NOKTA* enUzakNoktaBul(NOKTA *, int*);
ENUZAKNOKTA *enUzakNoktaBulv2(NOKTA *head);

int main(){
    char dosyaAdi[30];
    NOKTA *head, *max;
    ENUZAKNOKTA *n;
    int d;   /* ders sonrası not: int d = 0; olmalı */
    printf("Okunacak dosyanın adi");
    scanf("%[^\n]s",dosyaAdi);
    head = dosyadanOku(dosyaAdi);
    listeYaz(head);
    printf("Recursive printf\n");
    listeYazRec(head);
    max = enUzakNoktaBul(head,&d);
    printf("En buyuk uzaklik degeri:%d\n",d);
    printf("Orijine en uzak nokta:%d,%d\n",max->x,max->y);
    n = enUzakNoktaBulv2(head);
    printf("En buyuk uzaklik degeri v2:%d\n",n->d);
    printf("Orijine en uzak nokta v2:%d,%d\n",n->pt->x,n->pt->y);
    return 0;
}

NOKTA* dosyadanOku(char *dosyaAdi){
    FILE *fp;
    NOKTA *head=NULL, *end, *tmp;
    fp=fopen(dosyaAdi,"r");
    if(fp==NULL){
        printf("Dosya acilamadi");
    }
    else{
        while(!feof(fp)){
            tmp=(NOKTA*) malloc(sizeof(NOKTA));
            fscanf(fp,"%d %d\n",&tmp->x,&tmp->y);
            tmp->next=NULL;
            if(head==NULL){
                head=end=tmp;
            }
            else{
                end->next=tmp;
                end=end->next;
            }
        }
        fclose(fp);
    }
    return head;
}

void listeYaz(NOKTA *head){
    NOKTA *tmp=head;
    while(tmp!=NULL){
        printf("(%d,%d)->",tmp->x,tmp->y);
        tmp=tmp->next;
    }
    printf("Null\n");
}

void listeYazRec(NOKTA *head){
    NOKTA *tmp=head;
    if(tmp!=NULL){
        printf("(%d,%d)->",tmp->x,tmp->y);
        listeYazRec(tmp->next);
    }
    else{
        printf("Null\n");
    }
}

NOKTA *enUzakNoktaBul(NOKTA *head, int *dmax){
    NOKTA *tmp=head, *max;
    int d=0;
    while(tmp!=NULL){
        d = pow(tmp->x,2) + pow(tmp->y,2);
        if(d>*dmax){
            *dmax=d;
            max=tmp;
        }
        tmp = tmp->next;
    }
    return max;
}

ENUZAKNOKTA *enUzakNoktaBulv2(NOKTA *head){
    NOKTA *tmp=head, *max;
    ENUZAKNOKTA *ptr=(ENUZAKNOKTA*) malloc(sizeof(ENUZAKNOKTA));
    int d=0;
    int dmax=0;
    while(tmp!=NULL){
        d = pow(tmp->x,2) + pow(tmp->y,2);
        if(d>dmax){
            dmax=d;
            max=tmp;
        }
        tmp=tmp->next;
    }
    ptr->d = dmax;
    ptr->pt=max;
    return ptr;
}
```

Bu dosyayla çıktı (`veriler.txt` girilince):

```text
Okunacak dosyanın adi(4,6)->(1,20)->(9,8)->(3,3)->(5,5)->Null
Recursive printf
(4,6)->(1,20)->(9,8)->(3,3)->(5,5)->Null
En buyuk uzaklik degeri:401
Orijine en uzak nokta:1,20
En buyuk uzaklik degeri v2:401
Orijine en uzak nokta v2:1,20
```

Aradaki noktalar ajanın deneme dosyasındandır; derste kullanılan dosyanın tamamı ekranda görünmedi.

## 9. Kendi Türünden İşaretçi Tutan Yapılar ve Veri Yapıları

Aradan sonra hoca, Deitel kitabının veri yapıları bölümünün slaytları üzerinden konuyu toparladı (ekrandan, 01:05:00). Veri yapıları dersinin bir sonraki dönem görüleceğini, bu konunun struct ve dinamik bellekten türediğini söyledi.

### 9.1 Kendi türünden işaretçi tutan yapılar

Konunun temeli, bir struct'ın içinde kendi türünden bir işaretçi bulunmasıdır (self-referential structure). Java'da da bir sınıf kendi türünden bir referans tutabilir; orada işaretçi yoktur, ama mantık aynıdır. Bu yapılarda ilk fiziksel düğümün adresini gösteren bir işaretçi vardır: listede `head`, ağaçta `root`. Bir, iki ya da daha fazla işaretçiyle çok farklı yapılar tasarlanabilir. Her yeni düğüm `malloc` ile açılır, ilgili işaretçilere bağlanır, işi bitince `free` ile bırakılır.

### 9.2 Bağlı liste türleri

- Tek yönlü bağlı liste: şimdiye kadar yapılan; hep ileri doğru gidilir.
- Dairesel bağlı liste: son düğüm yeniden `head`'i gösterir. Yeni eleman eklemek için `tmp->next` `head`'den farklı olduğu sürece ilerlenir; `head`'e ulaşınca listenin sonuna gelinmiş demektir. Yeni son düğüm de `head`'i gösterir.
- Çift yönlü bağlı liste: düğümde bir öncekini ve bir sonrakini gösteren iki işaretçi tutulur; ileri ve geri hareket edilebilir.
- Dairesel çift yönlü bağlı liste: son düğüm `head`'i gösterir, başa dönmek mümkündür.

Hoca, Java'da collection ve C++'ta STL (Standard Template Library) içinde hazır bağlı liste sınıfları bulunduğunu, bunların çift yönlü bağlı liste mantığıyla kurulduğunu söyledi.

### 9.3 Slayttaki bağlı liste programı

Slayttaki programda bir menüden ekleme, silme ve çıkış seçilir (ekrandan, 01:05:00). `insert` fonksiyonu `ListNodePtr *sPtr` ve bir `char` değer alır, `malloc` ile yeni düğüm açar, boşsa veriyi yazar; sonra `previousPtr` ve `currentPtr` ile eklenecek yeri arar ve düğümü sıralı konuma yerleştirir.

<!-- BELİRSİZ: Hoca bu fonksiyonun listenin sonuna eklediğini söyledi; slayttaki açıklama satırı "Insert a new value into the list in sorted order" diyor, yani ekleme sıralı konumadır. -->

Değer silerken ilk eleman aranan değerse doğrudan silinir. Değilse eleman aranırken hep bir önceki düğüm de tutulur: `previous` ve `current` birlikte ilerletilir. Bulununca bir öncekinin `next`'i şimdikinin `next`'ine bağlanır, şimdiki düğüm geçici bir işaretçiye alınıp `free` edilir.

### 9.4 Bağlı listeyle yığın

Yığının (stack) iki temel işlemi ekleme (push) ve silmedir (pop); hoca bunların ayrık matematikte görüldüğünü hatırlattı. Yığın dinamik dizilerle kurulabildiği gibi bağlı listeyle de kurulabilir. Slayttaki `StackNode` bir veri ve bir `next` tutar; `push`, `pop`, `isEmpty` ve `printStack` fonksiyonları vardır. `push` yeni düğümü açar ve gelen `topPtr`'ın önüne, yani hep yığının başına ekler. `pop` baştaki veriyi alır, `topPtr`'ı bir sonrakine günceller ve eski düğümü `free` eder. Örnek çalıştırmada 5 sonra 6 eklenince yazdırma NULL'a doğru ilerler; silme de listenin başından yapılır.

### 9.5 Bağlı listeyle kuyruk

Kuyruğun işlemleri enqueue ve dequeue'dur. Ekleme kuyruğun sonundan, silme başından yapıldığı için kuyruğun sonunu gösteren bir `tailPtr` da tutulur; hoca bunu ayrı bir işaretçi olarak tutmanın iyi olduğunu söyledi. Slayttaki `dequeue` şöyledir (ekrandan, 01:10:00):

```c
char dequeue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr )
{
   char value;
   QueueNodePtr tempPtr;

   value = ( *headPtr )->data;
   tempPtr = *headPtr;
   *headPtr = ( *headPtr )->nextPtr;

   if ( *headPtr == NULL )
      *tailPtr = NULL;

   free( tempPtr );
   return value;
}
```

Baştaki düğümün verisi alınır, `head` bir sonrakine kaydırılır; kuyruk boşaldıysa `tail` da NULL yapılır ve eski düğüm serbest bırakılır. `isEmpty` yalnızca `headPtr == NULL` sonucunu döndürür.

## 10. İkili Arama Ağacı ve Gezinme Algoritmaları

### 10.1 Yapı ve ekleme kuralı

Ağaçlar dizilerden farklı olarak iki kollu ilerler. Listedeki `head`'e benzeyen işaretçiye ağaçta `root` (kök) denir; ağacın ilk elemanının adresini tutar. Her düğüm iki işaretçi tutar: biri sol, biri sağ alt ağaç için. İkili arama ağacında kural şudur: eklenecek ya da aranan değer bulunulan düğümdekinden büyükse sağa, küçükse sola gidilir.

### 10.2 Preorder, inorder, postorder

Gezinme algoritmaları üçtür. Hoca bunları akılda tutmak için ifadelerin infix, prefix ve postfix yazılışıyla eşleştirdi. Kökünde `+`, solunda `a`, sağında `b` olan ağacı düşünelim:

- Inorder (sol, kök, sağ): `a + b`, günlük kullandığımız infix yazılış.
- Postorder (sol, sağ, kök): `a b +`, postfix. Önce sola, sonra sağa, en son köke uğranır.
- Preorder (kök, sol, sağ): `+ a b`, prefix. Önce operatöre, yani köke, sonra sola, sonra sağa gidilir.

Hoca postfix'in bir de ters biçimi (`b a +`: önce sağ, sonra sol, sonra operatör) olduğunu, ama genelde bu üçünün kullanıldığını söyledi. Bu algoritmalar doğası gereği özyinelemelidir: `a`'nın altında başka düğümler varsa (örneğin orada da bir `+` ve onun çocukları), "sola git" demek gidebildiği kadar sola gitmek demektir. Özyinelemeli yazmak kolaydır; iteratif yazmak, özellikle ekleme ve silmede, daha karışıktır.

### 10.3 Slayttaki ağaç programı

Slayttaki ağaç düğümünde bir sol işaretçi, bir sağ işaretçi ve bir veri vardır. Hoca verinin yalnız tamsayı olmak zorunda olmadığını, başka bir struct (örneğin bir çalışan ya da kişi kaydı) da tutulabileceğini söyledi. Slayttaki program 1 ile 15 arasında rastgele 10 değer üretip ağaca ekler, sonra üç gezinmeyi yazdırır (ekrandan, 01:15:00):

```c
for ( i = 1; i <= 10; i++ ) {
   item = rand() % 15;
   printf( "%3d", item );
   insertNode( &rootPtr, item );
}
```

<!-- BELİRSİZ: Slayttaki açıklama "1 ve 15 arasında" diyor, ama rand() % 15 ifadesi 0-14 aralığını verir. -->

Buradaki `insertNode(TreeNodePtr *treePtr, int value)` çift işaretçi alır: `*treePtr == NULL` ise `malloc` ile düğüm açar, veriyi yazar, sol ve sağı NULL yapar. Değilse değer küçükse sola, büyükse sağa özyinelemeli olarak gider; eşitse bir mesaj verir (tekrarlı değer eklenmez).

## 11. İkili Arama Ağacının Kodlanması

### 11.1 Düğüm yapısı ve createNode

Hoca yeni bir dosyada ağacı kodladı (ekrandan, 01:20:00):

```c
#include<stdio.h>
#include<stdlib.h>
typedef struct treeNode{
    int data;
    struct treeNode *left;
    struct treeNode *right;
}TreeNode;

TreeNode* createNode(int data){
    TreeNode *tmp=(TreeNode*) malloc(sizeof(TreeNode));
    tmp->data = data;
    tmp->left = tmp->right=NULL;
    return tmp;
}
```

`createNode`, verilen veriyle tek bir düğüm açar; henüz çocuğu olmadığı için sol ve sağ NULL'dır. Düğümün adresi döndürülür.

### 11.2 Elle kurulan ağaç ve preorder

Önce `insert` yazmadan, düğümler elle bağlandı (ekrandan, 01:25:00):

```c
TreeNode *root;
root=createNode(10);
root->left = createNode(5);
root->right = createNode(15);
```

Ortada 10, solda 5, sağda 15 vardır. `printf("%d", root->left->data);` yazılırsa 5 görülür. Hoca bunun sistematik olmadığını, ağaç çok veri içerdiği için gezinme fonksiyonları gerektiğini söyledi. Preorder `void` bir fonksiyondur:

```c
void preorder(TreeNode *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
```

(ekrandan, 01:25:00)

Çağrı zinciri şöyle işler. İlk çağrıda kök 10'dur, önce 10 yazılır. Sonra `root->left` ile 5'in düğümüne gidilir, 5 yazılır. 5'in solu NULL olduğu için o çağrı hemen döner; 5'in sağı da NULL'dır, o da döner. 5'in çağrısı bitince 10'un sağına, 15'e geçilir ve 15 yazılır; onun da iki çocuğu NULL'dır. Çıktı `10 5 15` olur.

### 11.3 Inorder ve postorder

Hoca inorder'ı `a + b` ile düşünmeyi önerdi: gidebildiği kadar sola gidilir, sonra ortadaki kök yazılır, sonra sağa gidilir. Postorder'da `a b +` gibi önce sol, sonra sağ, en son kök yazılır. Fonksiyonlar preorder kopyalanıp satırların yeri değiştirilerek yazıldı; `main`'de üçü ard arda çağrıldı (ekrandan, 01:30:00).

Postorder'ın ekrandaki hâli şöyledir (ekrandan, 01:30:00):

```c
void postorder(TreeNode *root){
    if(root!=NULL){
        preorder(root->left);
        preorder(root->right);
        printf("%d ",root->data);
    }
}
```

> **Ders sonrası not:** Kopyalama sırasında alt ağaç çağrıları `preorder` olarak kalmış. Doğrusu `postorder(root->left); postorder(root->right);` olmalıdır. Inorder'ın kodu karelerde görünmüyor, ama aşağıdaki çıktılar onun da alt ağaçlar için `preorder` çağırdığını gösteriyor; doğrusu `inorder(root->left); printf(...); inorder(root->right);` biçimidir. Üç düğümlü ağaçta bu hata fark edilmez, çünkü yaprakların preorder'ı da kendileridir.

### 11.4 Özyinelemeli insertNode

Hoca, önceki yıl bu konunun dönem sonunda işlendiğini, normalde bu derste anlatılmadığını belirterek `insertNode`'u yazdı (ekrandan, 01:40:00):

```c
TreeNode *insertNode(TreeNode *root, int data){
    if(root==NULL){
        root=createNode(data);
        return root;
    }
    else if(data>root->data){
        root->right = insertNode(root->right,data);
        return root;
    }
    else{
        root->left = insertNode(root->left,data);
        return root;
    }
}
```

Kök NULL ise yeni bir düğüm oluşturulur ve döndürülür. Hoca, kök fonksiyon içinde güncellenebildiği için onu döndürdüğünü vurguladı ve sordu: fonksiyon `void` olsaydı ne gerekirdi? Cevap çift işaretçidir, çünkü kök güncellenecektir (slayttaki sürüm böyledir).

Kök NULL değilse: ilk adımda 10 eklendiğini, şimdi 5'in eklendiğini düşünelim. Sağa mı sola mı gidileceğine karar verilir ve fonksiyon ilgili alt ağaçla yeniden çağrılır. O alt ağaç boşsa yeni çağrıda `root == NULL` durumuna düşülür ve yeni düğüm oluşur; dönen adres `root->right` ya da `root->left`'e atanır. Asıl kök yerinde kalır, altında küçük bir alt ağaç oluşmuş olur. Hoca ilk yazışta alt çağrılardan sonra `return root;` satırlarını unuttuğunu fark edip ekledi: kökün güncel hâli her dalda döndürülmelidir.

> **Hocanın vurgusu:** Bu fonksiyon özyinelemeli yazılabildiği gibi iteratif de yazılabilir. İteratif yöntemi araştırmanızı öneririm; konuları tekrar ettiren güzel bir algoritma çalışmasıdır.

### 11.5 Klavyeden ekleme ve hata ayıklama

`main`'de 0 girilene kadar değer okunur (ekrandan, 01:35:00 ve 01:40:00):

```c
int data=1;
do{
    printf("Enter data ");
    scanf("%d",&data);
    root=insertNode(root, data);
}while(data!=0);
```

<!-- BELİRSİZ: do-while gövdesindeki printf/scanf satırları karelerde tam görünmüyor; altyazıdan kuruldu. -->

Son girilen 0 da ağaca eklenir. İlk denemede 10 girilince program çöktü. Hoca hata ayıklayıcıda kesme noktası koyup `root`'u izledi ve "segmentation fault" gördü. Sorun `TreeNode *root;` satırında ilk değer verilmemesiydi: `root` rastgele bir adres taşıdığı için `root == NULL` kontrolü yanlış sonuç verdi. `root = NULL` ile başlatılınca düzeldi.

Ardından hata ayıklayıcıyla adım adım izlendi: kök NULL olduğu için ilk düğüm oluştu ve döndü. 8 girilince kök NULL değildi, 8 < 10 olduğu için `root->left` ile yeniden çağrıldı; orada kök boş olduğu için yeni düğüm üretildi, döndürüldü ve sol işaretçiye atandı. 20 sağ tarafa aynı şekilde eklendi. Hoca, ağaç derinleştikçe özyinelemeli çağrıların iç içe arttığını gösterdi.

### 11.6 10, 8, 20, 0 girişinin çıktıları

Girilen değerler 10, 8, 20, 0 idi. Ekrandaki çıktılar:

- Preorder: `10 8 0 20`. Önce 10, sonra sol taraf (8 ve altı), sonra 20.
- Inorder: `8 0 10 20`.
- Postorder: `8 0 20 10`; kök en son yazılır.

Hoca 0'ı 8'in sağındaki düğüm olarak yorumladı.

> **Ders sonrası not:** 0 < 10 ve 0 < 8 olduğu için 0, 8'in sol çocuğudur. Ağaç şöyledir:
>
> ```text
>         10
>        /  \
>       8    20
>      /
>     0
> ```
>
> Doğru gezinmeler: preorder `10 8 0 20`, inorder `0 8 10 20`, postorder `0 8 20 10`. Derste görülen `8 0 10 20` ve `8 0 20 10`, inorder ve postorder'ın alt ağaçlar için `preorder` çağırmasından kaynaklanır (sol alt ağaç 8, 0 diye preorder sırasıyla yazılır). Ajan iki sürümü de `gcc -Wall` ile derleyip aynı girişle denedi: hatalı sürüm derste görülen çıktıları, düzeltilmiş sürüm doğru çıktıları verdi. Inorder'ın küçükten büyüğe sıralı çıktı vermesi ikili arama ağacının temel özelliğidir.

### 11.7 Önerilen çalışmalar

Hoca iki alıştırma önerdi. Birincisi `insertNode`'un `while` döngüsüyle, özyinelemesiz yazılması: kök NULL ise doğrudan atanır; değilse veri kökünkünden büyükse sağa, küçükse sola gidilir ve ileride sağın sağı, sağın solu gibi dallar döngüyle izlenir. İkincisi ağaçtan silme (`delete`) fonksiyonu.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:40:36): Bir fonksiyondan döndürülen yapının, fonksiyon bittikten sonra da yaşaması için ne yapılabilir? İki yol söyleyin.

> **Çözüm:** Birinci yol, yapıyı `malloc` (ya da `calloc`) ile heap'te açıp adresini döndürmektir; heap program boyunca yaşar. İkinci yol `static` değişken kullanmaktır; bir kez oluşturulur ve program kapanana kadar saklanır. Yerel değişken stack'tedir ve adresi fonksiyon bitince geçersizleşir.

**Soru 2** (derste sözlü, 01:30:26): `insertNode` fonksiyonu kökü döndürmeseydi, yani dönüş türü `void` olsaydı, kök nasıl güncellenirdi?

> **Çözüm:** Fonksiyona kökün adresi, yani çift işaretçi (`TreeNode **root`) gönderilirdi; fonksiyon `*root = createNode(data);` ile çağıranın kök değişkenini doğrudan değiştirirdi. Slayttaki `insertNode(&rootPtr, item)` sürümü böyle çalışır.

**Soru 3** (derste sözlü, 01:31:05): `insertNode` içinde kök boş değilse ne yapılır? 10 eklendikten sonra 5 eklenirken ne olur?

> **Çözüm:** Veri kökteki değerle karşılaştırılır; büyükse sağ, küçükse sol alt ağaçla fonksiyon yeniden çağrılır. 5 < 10 olduğu için `root->left = insertNode(root->left, 5)` çağrılır; `root->left` NULL olduğundan yeni çağrı 5 için düğüm oluşturup döndürür, bu adres 10'un sol işaretçisine atanır ve 10 döndürülür.

**Soru 4** (derste sözlü, 01:21:37): Kök 10, solu 5, sağı 15 olan ağaçta `printf("%d", root->left->data);` ne yazar?

> **Çözüm:** 5.

**Soru 5** (derste verilmedi, alıştırma olarak önerildi, 01:34:06 ve 01:42:04): `insertNode` fonksiyonunu özyineleme kullanmadan yazın.

> **Çözüm (derste verilmedi):** Ajanın yazdığı bir çözüm; derste yazılan `createNode` ve gezinme fonksiyonlarıyla birlikte `gcc -Wall` ile derlenip 10, 8, 20, 0 girişiyle denendi, özyinelemeli sürümle aynı ağacı kurdu:
>
> ```c
> TreeNode *insertNodeIter(TreeNode *root, int data){
>     TreeNode *yeni = createNode(data), *tmp = root;
>     if(root == NULL) return yeni;
>     while(1){
>         if(data > tmp->data){
>             if(tmp->right == NULL){ tmp->right = yeni; break; }
>             tmp = tmp->right;
>         } else {
>             if(tmp->left == NULL){ tmp->left = yeni; break; }
>             tmp = tmp->left;
>         }
>     }
>     return root;
> }
> ```

## Dersin Toparlaması

Bu derste struct, dosya işlemleri, bağlı liste ve özyineleme tek bir örnekte birleştirildi. Dosyadan okunan noktalar `head` ve `end` işaretçileriyle sona eklenerek listeye kondu; liste iteratif ve özyinelemeli olarak yazdırıldı. Orijine en uzak nokta iki yoldan bulundu: düğümü `return` ile, uzaklığı işaretçi parametreyle döndürmek ya da ikisini birden heap'te açılmış bir struct içinde döndürmek. Bu sırada stack ve heap farkı, dönen adresin neden heap'te olması gerektiği ve `malloc` boyutunda yapı ile işaretçinin karıştırılmaması üzerinde duruldu.

İkinci bölümde kendi türünden işaretçi tutan yapıların bağlı liste türleri, yığın, kuyruk ve ağaç gibi veri yapılarının temeli olduğu gösterildi. İkili arama ağacı `createNode`, özyinelemeli `insertNode` ve üç gezinme fonksiyonuyla kodlandı. Hoca konuların bittiğini, sonraki derste değişken sayıda argüman alan fonksiyonlar, sinyal işleyiciler ve thread gibi ileri C konularına kısaca giriş yapmak istediğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
