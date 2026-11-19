# Ders 27 Genişletilmiş Notu: Uygulama: Acil Servis Öncelikli Hasta Kuyruğu (Yapı, Bağlı Liste, Dosya) ve Makefile

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulama Sorusu: Acil Servis Kuyruğu
- 2. Neden Bağlı Liste, Neden Yapı?
- 3. Programın Dosyalara Bölünmesi ve Başlık Dosyası
- 4. Makrolar
- 5. main ve Menü
- 6. Yeni Düğüm Oluşturma: create_new_patient
- 7. Listeye Ekleme: insert_patient_to_list
- 8. Dosyaya Yazma: printListWithAllInformations
- 9. Hasta Silme: delete_patient
- 10. Dosyadan Okuma: read_File
- 11. Programın Çalıştırılması
- 12. Ayrı Derleme, Bağlama ve Makefile
- Örnek Sorular
- Dersin Toparlaması

## 1. Uygulama Sorusu: Acil Servis Kuyruğu

Bu oturum, dönem boyunca öğrenilen konuların temel düzeyde birlikte nasıl kullanılacağını gösteren bir özet uygulamasıdır. Dönemin son haftalarına gelindiği için yapı (struct), bağlı liste (linked list) ve dosya işlemleri tek bir problemde bir araya getirildi. Hazır bir çözüm kodu satır satır anlatıldı ve bağlı liste üzerindeki işlemler diagrams.net (draw.io) ile çizilen kutu-ok şemalarıyla adım adım izlendi.

Problem metni ekranda şöyledir (ekrandan, 00:10:00): Bir hastanenin acil servisinde kullanılmak üzere bir kuyruk hazırlanacaktır. Kuyruk, hastaların sıralarını takip edebilmek için kullanılacaktır. Hastalar kayıt yaptırmak için isim, soy isim, T.C. kimlik numarası ve yaş bilgilerini paylaşmalıdır. Hastanelerde vakalar acil vaka ve normal vaka olarak incelenmektedir. Bu doğrultuda aşağıdaki ilkeleri gerçekleyen kuyruk modelini oluşturun.

Gerçek acil servislerde kırmızı, sarı, yeşil gibi farklı aciliyet düzeyleri vardır. Bu soruda basitleştirme yapılmış ve öncelik yalnız iki değerli tutulmuştur: 0 acil değil, 1 acil (öncelikli) demektir. Bunu mantıksal (boolean) bir değer gibi düşünmek mümkündür.

İlkeler şunlardır (ekrandan, 00:10:00 ve 00:15:00):

- Yeni gelen hasta acil vaka değilse doğrudan kuyruğun sonuna eklenir. Örnekte önce 1. hasta, ardından 2, 3, 4 ve 5. hastalar gelir; kuyruk `1 2 3 4 5` olur.
- Öncelikli bir hasta geldiğinde, listedeki son öncelikli hastadan sonraki sıraya yerleştirilir. Listede hiç öncelikli hasta yoksa öncelikli hasta listenin başına eklenir. 6. hasta önceliklidir ve başa eklenir: `6 1 2 3 4 5`. Ardından yeni bir öncelikli vaka (7) geldiğinde kuyruk `6 7 1 2 3 4 5` olur.
- Hastalar doktora görünmekten vazgeçtiklerinde kuyruktan çıkarılır. 3. hasta, ismi kullanılarak çıkarılmıştır: `6 7 1 2 4 5`.
- Kuyrukta bulunan hastaların bilgileri dosyada tutulur.
- İstenildiğinde kuyrukta bekleyenlerin bilgileri dosyadan okunur.

İkinci ilkenin mantığı önemlidir. İkinci bir acil hasta geldiğinde onu ilk acil hastanın önüne koymak mantıklı değildir; önce gelen acil hasta önce bakılmalıdır. Bu yüzden her seferinde son öncelikli hastanın yeri belirlenmeli ve yeni öncelikli hasta onun arkasına eklenmelidir. 7. hasta 6'nın arkasına girer; bir 8. öncelikli hasta gelseydi o da 7'nin arkasına girecekti.

> **Hocanın vurgusu:** Bağlı listede sona eklemeyi zaten biliyorsunuz. Bu sorunun farkı, son öncelikli elemanın yerini de belirlemek gerekmesidir.

## 2. Neden Bağlı Liste, Neden Yapı?

Kuyruk yapısı en kolay bağlı listeyle kurulur. Bu noktada dizilerle bağlı listelerin avantaj ve dezavantajları soruldu.

**Soru:** Dizilerle bağlı listelerin avantajı ve dezavantajı nedir? **Cevap:** Bir öğrenci dizide araya eleman eklemek için diziyi yeniden düzenlemek gerektiğini, bağlı listede ise araya eklemenin daha kolay olduğunu söyledi. Buna şu eklendi: dizilerde kaydırma gerekir, bağlı listede gerekmez. Dizilerin avantajı indisle doğrudan erişimdir. Bağlı listede ortadaki bir elemana ulaşmak için en baştan başlayıp ilerlemek gerekir; bu bağlı listenin dezavantajıdır. Buna karşılık ekleme ve çıkarma, her düğümün bir sonraki elemanın adresini (`next`) tutması sayesinde $O(1)$ karmaşıklıkta yapılabilir.

> **Ek bilgi (derste anlatılmadı):** $O(1)$ ekleme, eklenecek yer (önceki düğüm) bilindiğinde geçerlidir. Yeri bulmak için listeyi gezmek gerekiyorsa bu gezinti $O(n)$ sürer; bu programdaki sona ekleme ve son öncelikli düğümü bulma da böyledir.

Bağlı liste dışında bir şeye daha ihtiyaç vardır. Bir hastanın isim, soy isim, kimlik numarası, yaş gibi bilgileri farklı türlerdedir: yaş bir tamsayı (`int`), isim bir karakter dizisidir. Farklı türdeki birden çok bilgiyi bir arada tutmak için yapı (`struct`) tanımlanır.

## 3. Programın Dosyalara Bölünmesi ve Başlık Dosyası

Program üç ayrı dosyaya bölünmüştür (ekrandan, 00:20:00):

- `uygulama.c`: `main` fonksiyonu ve bağlı liste işlemleri (düğüm oluşturma, ekleme, silme).
- `struct_patient.h`: yapı tanımlarının bulunduğu başlık dosyası.
- `file_opr.c`: dosyaya yazma ve dosyadan okuma fonksiyonları.

`uygulama.c`'nin başında standart kütüphaneler eklenir. `stdio.h`, `printf` ve `scanf` için her programda eklenir. Yeni bir düğüm oluşturmak dinamik bellek ayırmayı (dynamic memory allocation) gerektirdiği için `stdlib.h` eklenir. Hastanın adı ve soyadı üzerinde dizgi işlemleri yapılacağı için `string.h` de eklenmelidir.

Başlık dosyası, yeni bir dosya açıp uzantısını `.h` yaparak oluşturulur. Kendi yazdığımız başlık dosyası programla aynı dizindeyse adı tırnak içinde yazılır (`#include "struct_patient.h"`). Standart kütüphaneler açılı ayraçla (`<stdio.h>`) eklenir.

<!-- BELİRSİZ: 00:19:01-00:19:20 arasında tırnak ile açılı ayraç farkının anlatımı altyazıda kopuk; uygulama.c'nin #include satırları karelerde görünmüyor. -->

`file_opr.c` de `main` dosyasına `#include` ile eklendi. Hoca bunun zorunlu olmadığını, dosyalar ayrı ayrı derlenip oluşan nesne dosyaları (object file) bağlanarak da aynı sonucun alınabileceğini söyledi. Kolay yol olduğu için `#include` seçildi; diğer yol dersin sonunda gösterildi (Bölüm 12).

### 3.1 Yapı tanımları

Başlık dosyasında iki yapı vardır (ekrandan, 00:20:00):

```c
// Creating Patient structure
typedef struct node{
    char name[30], surname[30];
    char ID[12];
    int age;
    int prior;
}Patient;

// Creating Patient_Node structure
typedef struct Patient_Node{
    Patient data;
    struct Patient_Node *next;
}Patient_Node;
```

Birinci yapı bir hastanın bilgilerini, ikinci yapı bağlı listenin bir düğümünü tutar. Düğümün `data` alanı `Patient` türünden bir yapı değişkenidir. İki yapı birleştirilebilirdi; ayırmak bir tercih meselesidir.

`typedef`'in görevi bir türe yeni bir ad vermektir. Örneğin `int` yerine kendi programımızda daha okunaklı bulduğumuz `integer` gibi bir ad kullanmak istersek `typedef` bunu sağlar. Burada `struct node` yerine artık `Patient` adı kullanılacağı söylenmektedir; tanım ile `typedef` aynı satırda yazılarak kısa biçim elde edilmiştir. `typedef` olmasaydı, kapanış ayracından sonra yazılan `Patient` bir tür adı değil, `struct node` türünden bir değişken olurdu.

`Patient_Node` kendine gönderen bir yapıdır (self-referential structure). `next` işaretçisi bir sonraki düğümün adresini tutar. Şemada her düğüm, içinde birçok bilgi taşıyan bir `data` kutusu ile bir sonraki düğümü gösteren bir `next` okundan oluşur.

Bir `Patient` için bellekte ayrılan yer alanların toplamıdır: karakterler birer bayt (isim ve soy isim 30'ar bayt), tamsayılar 4'er bayt.

> **Ek bilgi (derste anlatılmadı):** Bu yapıda toplam $30 + 30 + 12 + 4 + 4 = 80$ bayttır ve ajanın denemesinde `sizeof(Patient)` 80 verdi. Genel olarak derleyici hizalama (padding) için alanlar arasına boşluk ekleyebildiği için `sizeof` alanların toplamından büyük olabilir.

## 4. Makrolar

Ön işlemci komutları olan makrolar `#define` ile tanımlanır (büyük-küçük harf duyarlıdır). Programda `MAX_SIZE` ve bir uyarı mesajı için `WARNING` makrosu vardır.

Ön işlemci adımında `MAX_SIZE` geçen her yere `20` yerleştirilir. `main` içindeki `char name[MAX_SIZE];` derleyiciye `char name[20];` olarak gider. Makro, yanında ne yazıyorsa onu olduğu gibi yerine koyar.

Bu yüzden `#define MAX_SIZE = 20` yazılmaz. Öyle yazılsaydı `name[MAX_SIZE]` ifadesi `name[= 20]` olurdu ve bunun bir anlamı yoktur. Aynı nedenle `WARNING` makrosunun metni tırnak içinde yazılır: `printf(WARNING);` ifadesi ön işlemciden sonra tırnaklı bir dizgi sabitine açılır. Tırnak konmasaydı `printf`'in içine çıplak kelimeler gelir ve derleme hatası alınırdı.

<!-- BELİRSİZ: WARNING makrosunun tam metni karelerde görünmüyor. -->

Makrolarla çok farklı şeyler yapılabilir: hata ayıklama (debug), koşullu derleme (`#if`), fonksiyon benzeri makrolar. Bunların bir kısmı daha önceki derslerde gösterilmişti.

## 5. main ve Menü

`main` fonksiyonu şöyledir (ekrandan, 00:35:00):

```c
int main() {
    char name[MAX_SIZE]; //delete func
    int choose = 1;
    // head node specify the head of list.
    Patient_Node *head = NULL;
    while(choose > 0)
    {
        printf("\nFor entering new patient press 1..\n");
        printf("For deleting patient with name press 2..\n");
        printf("For reading list from the file press 3..\n");
        printf("For exit press 0..\n");
        printf("\nPlease enter your choice:");
        scanf(" %d", &choose);
        switch(choose){
            case 1:
                insert_patient_to_list(create_new_patient(), &head);
                printListWithAllInformations(&head);
                break;
            case 2:
                printf("\nEnter patient name that want to delete : ");
                scanf(" %s", name);
                delete_patient(name, &head);
                printListWithAllInformations(&head);
                break;
            case 3:
                read_File();
                break;
        }
    }
    return 0;
}
```

Kullanıcıya basit bir menü sunulur: yeni hasta için 1, hasta silmek için 2, listeyi dosyadan okumak için 3, çıkış için 0. Kullanıcının seçimi sıfırdan büyük olduğu sürece `while` devam eder. Döngüye ilk kez girilebilmesi için `choose` başta sıfırdan büyük bir değere (1) eşitlenmiştir. Menü ve döngü koşulu çok farklı şekillerde tasarlanabilir.

Listenin başını her zaman tutmak gerekir: eleman eklerken, silerken ve listeyi yazdırırken hepsinde `head`'e ihtiyaç vardır. `head`, listenin ilk düğümünü gösteren bir `Patient_Node` işaretçisidir. Liste başlangıçta boş olduğu için `NULL` yapılır.

Seçim `scanf(" %d", &choose);` ile okunur: tamsayı değişkenin adresine 4 baytlık bir değer okunur. Ardından `switch` yapısıyla ilgili `case`'e gidilir. Derste `break` komutu genel olarak pek kullanılmamaya çalışıldığı, `switch-case`'in onun kullanıldığı nadir yapılardan biri olduğu hatırlatıldı.

`case 1` içinde ekleme fonksiyonunun parametresi olarak başka bir fonksiyon çağrılır: önce düğümün oluşturulması gerekir. Ardından liste güncellendiği için dosya da yeniden yazılır.

## 6. Yeni Düğüm Oluşturma: create_new_patient

Fonksiyon şöyledir (ekrandan, 00:35:00; ilk satırlar karede görünmüyor):

```c
    // Allocation memory for new patient
    new_node = (Patient_Node*)malloc(sizeof(Patient_Node));

    if(new_node == NULL)
    {
        printf(WARNING);
        exit(1);
    }

    // Getting inputs from user
    printf("\nPlease enter patient informations..\n");
    printf("Name    :");
    scanf(" %s", new_node->data.name);
    printf("Surname:");
    scanf(" %s", new_node->data.surname);
    printf("ID      :");
    scanf(" %s", new_node->data.ID);
    printf("Age     :");
    scanf("%d", &new_node->data.age);
    printf("If patient has a priorty enter 1 otherwise enter 0 for prior..\n");
    printf("Prior   :");
    scanf("%d", &new_node->data.prior);
    new_node->next = NULL;
    return new_node;
}
```

Fonksiyon parametre almaz ve `Patient_Node *` döndürür (Dev-C++ ipucunda imza `Patient_Node* create_new_patient ()` olarak görünür, ekrandan, 00:30:00). İçinde `new_node` işaretçisi tanımlanır ve dinamik bellek ayrılır. `malloc` çağrısında önce tür dönüşümü (`(Patient_Node*)`) yazılır, sonra boyut verilir. Boyut `sizeof(Patient_Node)`'dır; bu, içindeki `Patient` yapısı dahil düğümün tamamını kapsar. Böylece çalışma sırasında dinamik olarak yer ayrılmış olur.

Bellek ayırma başarısız olursa `malloc` `NULL` döndürür. Bu kontrol edilir; `NULL` ise uyarı makrosu yazdırılır ve `exit(1)` ile programdan çıkılır.

### 6.1 Yapı alanlarına erişim: nokta ve ok

`new_node` bir işaretçidir. İşaretçiden yapı alanlarına iki yolla erişilir. Biri `(*new_node).data` biçimidir; burada işaretçinin içeriğine erişim ile noktanın birbirine karışmaması için parantez gerekir. Bu biçim kodun okunmasını zorlaştırdığı için genel olarak ok işleci tercih edilir: `new_node->data`. Ok yazınca editör `data` ve `next` alanlarını önerir.

`data` ise işaretçi değil, normal bir yapı değişkenidir. Bu yüzden onun alanlarına nokta ile erişilir: `new_node->data.name`.

### 6.2 Dizinin adı adrestir

`name` bir karakter dizisidir. Dizinin adı, ilk elemanının adresine eşittir. Diziler bellekte ardışık tutulduğu için ilk elemanın adresi yeterlidir; diğer karakterler adres birer birer artırılarak yerleştirilir. Bu yüzden `scanf(" %s", new_node->data.name);` yazılırken `&` konmaz. `&` konsaydı adresin adresi istenmiş olurdu; bunun anlamı yoktur. Soy isim ve kimlik numarası da dizgi olduğu için aynı şekilde okunur.

`age` ve `prior` ise tamsayıdır; okunurken adresleri verilmelidir: `&new_node->data.age`, `&new_node->data.prior`.

> **Hocanın vurgusu:** Dizinin adını kullandığınızda aslında ilk elemanın adresini kullanmış olursunuz; bu yüzden karakter dizisi `&` olmadan okunur.

Bütün bilgiler alındıktan sonra yeni düğüm henüz listeden bağımsızdır; `next` alanı `NULL` yapılır ve düğüm döndürülür.

## 7. Listeye Ekleme: insert_patient_to_list

Fonksiyonun tamamı karelerden şöyle okunur (ekrandan, 00:40:00, 00:45:00, 00:55:00):

```c
// This function is used for inserting new patient to list.
void insert_patient_to_list(Patient_Node *new_node, Patient_Node **head){
    // If head equals to NULL, new patient will be the head of list.
    if((*head) == NULL)
    {
        (*head) = new_node;
        return;
    }

    Patient_Node *var_head = (*head);
    Patient_Node *last_prior = (*head);
    Patient_Node *temp;
    // Check the new patient priorty, Has it high priority.
    if(new_node->data.prior != 0)
    {
        // Detect the last patient with high priorty.
        while(var_head != NULL)
        {
            if(var_head->data.prior != 0)
                last_prior = var_head;
            var_head = var_head->next;
        }

        // We set the initial last prior as head node.
        // Check is the last prior still head of the list.
        if(last_prior == (*head) )
        {
            // If head of least has not high priorty, new patient will be head of list.
            if((*head)->data.prior == 0)
            {
                temp = (*head);
                (*head) = new_node;
                new_node->next = temp;
            }
            else // else, new patient will be added after the last prior.
            {
                temp = last_prior->next;
                last_prior->next = new_node;
                new_node->next = temp;
            }
        }
        else // else, new patient will be added after the last prior.
        {
            temp = last_prior->next;
            last_prior->next = new_node;
            new_node->next = temp;
        }
    }
    else // If new patient has low priorty, add new patient at the end of the list.
    {
        while(var_head->next != NULL)
        {
            var_head = var_head->next;
        }
        var_head->next = new_node;
    }
}
```

Fonksiyon bir şey döndürmez (`void`); yalnız ekleme yapar. Birinci parametre yeni düğüm, ikinci parametre listenin başının adresidir.

### 7.1 Neden çift işaretçi?

`head`'in üç farklı kullanımı vardır:

- `head` global tanımlanırsa listenin bütün fonksiyonlarda değiştirilebilir olması kabul edilmiş olur. Bu tercih edilen bir yöntem değildir.
- `head` tek işaretçi olarak gönderilirse baştaki değişiklik yalnız fonksiyonun içinde kalır; güncel `head`'in `return` ile döndürülmesi gerekir.
- `head`'in adresi (`&head`) gönderilip fonksiyonda çift işaretçi (`**head`) ile alınırsa yapılan değişiklik bütün programa yansır, fonksiyon kapsamında kalmaz.

Ne `return` ile uğraşmak ne de global değişken tanımlamak istendiği için üçüncü yol seçildi. Bu, önceki uygulamada da kullanılmıştı.

### 7.2 Durum 1: Liste boş

`*head` `NULL` ise liste boştur. Yeni düğüm doğrudan baş yapılır (`(*head) = new_node;`) ve fonksiyondan dönülür. İlk eleman eklenmiş olur.

### 7.3 Değişkenler

Liste boş değilse üç işaretçi tanımlanır. `var_head` listeyi gezmeyi sağlayan değişkendir. `last_prior` son öncelikli düğümü tutar. İkisi de `*head` ile başlatılır, yani başın gösterdiği düğümü gösterir. `temp` ise takas (swap) ve bağlantı değişimleri için kullanılır.

### 7.4 Durum 2: Yeni hasta öncelikli değil (sona ekleme)

Şemada öncelikleri `1 1 0 0` olan bir liste ve önceliği 0 olan yeni bir düğüm çizildi (ekrandan, 00:40:00). Yeni düğümün önceliği 0 olduğu için `if`'e girilmez, `else`'e geçilir. Burada her bağlı liste örneğinde görüldüğü gibi `var_head` listenin sonuna ilerletilir ve yeni düğüm sona eklenir.

İzleme şöyledir: `var_head` baştadır. `var_head->next` `NULL` mı? Hayır; `var_head` bir sonrakine geçer. Tekrar sorulur; hayır, yine ilerletilir. Son düğüme gelindiğinde `next` `NULL` olur ve döngüden çıkılır. Ardından `var_head->next = new_node;` ile son düğüm yeni düğüme bağlanır.

> **Hocanın vurgusu:** Döngüde sürekli `next`'in `NULL` olup olmadığı sorgulanır, `var_head`'in kendisinin değil. `var_head` `NULL`'a gelirse bir önceki düğüme erişilemez ve ekleme yapılamaz. Yeni elemanın hangi düğümün arkasına ekleneceği arandığı için `next`'i `NULL` olan düğüme kadar ilerlenir.

### 7.5 Durum 3: Yeni hasta öncelikli, listede öncelikli hasta yok (başa ekleme)

Şemada öncelikleri `0 0 0` olan bir liste ve önceliği 1 olan yeni bir düğüm kullanıldı. Liste boş değildir. `var_head`, `last_prior` ve `temp` tanımlanır. Yeni düğümün önceliği sıfırdan farklı olduğu için `if`'e girilir.

Döngü listeyi gezer: `var_head` `NULL` değil, önceliği 0, `last_prior` değişmez, `var_head` ilerler. Listedeki hiçbir düğümün önceliği olmadığı için içteki `if`'e hiç girilmez ve `last_prior` başta kalır. `var_head` `NULL` olunca döngüden çıkılır.

Şimdi `last_prior == (*head)` sorulur; eşittir. Ardından başın önceliğinin 0 olup olmadığına bakılır. Bunun nedeni şudur: başın önceliği 0 ise yeni düğüm başın önüne eklenmelidir; 1 ise öncelikli elemanı bozmamak için arkasına eklenmelidir. Burada 0'dır, bu yüzden takas yapılır:

- `temp = (*head);` baştaki düğüm kaybolmasın diye saklanır.
- `(*head) = new_node;` baş artık yeni düğümü gösterir.
- `new_node->next = temp;` yeni düğüm eski başı gösterir.

Böylece öncelikli eleman listenin başına eklenmiş olur. Burada `last_prior` da zaten ilk düğümü gösterdiği için `temp`'e gerek olmadığı düşünülebilir. Ama `last_prior`'ın görevi bu değildir; bütün değişim işlemlerinde düzenli olarak `temp` kullanıldığı için burada da kullanıldı.

### 7.6 Durum 4: Listede öncelikli hastalar var (son öncelikli hastanın arkasına)

Şemada başta iki öncelikli düğüm, arkasında öncelikli olmayan düğümler ve öncelikli yeni bir düğüm vardır (ekrandan, 00:45:00 ve 00:50:00). Yeni düğüm ikinci öncelikli düğümün arkasına eklenmelidir.

Döngü izlenir: `var_head` `NULL` değil, önceliği sıfırdan farklı; `last_prior = var_head` (ilk adımda ikisi zaten aynı yeri gösterdiği için bir şey değişmez). `var_head` ilerler. İkinci düğüm de öncelikli; `last_prior` ikinci düğüme geçer. `var_head` ilerler; üçüncü düğümün önceliği 0, `if`'e girilmez. Dördüncü düğüm de 0. Sonunda `var_head` `NULL` olur ve döngüden çıkılır. `last_prior` son öncelikli düğümü göstermektedir. Döngü, `last_prior`'ı son öncelikli düğüme eşitleyebilmek için listenin tamamını taramıştır.

Hoca burada bir iyileştirme önerdi: öncelikli olmayan bir düğümden sonra öncelikli bir düğüm gelemeyeceği için, önceliği 0 olan ilk düğüm görülünce döngüden çıkılabilir.

`last_prior == (*head)` sorulur; eşit değildir, dıştaki `else`'e geçilir:

- `temp = last_prior->next;` son öncelikli düğümün arkasındaki düğüm saklanır.
- `last_prior->next = new_node;` son öncelikli düğüm yeni düğüme bağlanır.
- `new_node->next = temp;` yeni düğüm saklanan düğüme bağlanır.

> **Hocanın vurgusu:** `temp` kullanmadan doğrudan `last_prior->next = new_node;` yazılsaydı `last_prior`'ın arkasındaki düğümün yeri kaybedilirdi ve yeni düğümün `next`'ine ne yazılacağı bilinemezdi.

### 7.7 Durum 5: Yalnız baş öncelikli (başın arkasına ekleme)

Son durum, içteki `else`'tir. Şemada önceliği 1 olan bir baş, arkasında önceliği 0 olan düğümler ve öncelikli yeni bir düğüm kullanıldı (ekrandan, 00:50:00). Döngü sonunda `last_prior` başta kalır, çünkü başka öncelikli düğüm yoktur. `last_prior == (*head)` doğrudur, ama bu kez başın önceliği 0 değildir. Bu yüzden içteki `else` çalışır ve aynı üç satırla yeni düğüm başın arkasına eklenir. Az önceki durumda başa ekleme yapılmıştı; burada `else`, başın arkasına eklemeyi sağlar. Bu yüzden ayrı bir durum olarak yazılmıştır.

Özetle görülen durumlar: liste boşken ekleme; yeni eleman öncelikli değilken sona ekleme; yeni eleman öncelikliyken başa ekleme, son öncelikli düğümün arkasına ekleme ve başın arkasına ekleme.

`head` çift işaretçiyle gönderildiği için fonksiyonun bir şey döndürmesine gerek yoktur; güncellemeler listeye yansır.

## 8. Dosyaya Yazma: printListWithAllInformations

Her eklemeden sonra liste değiştiği için dosyanın da güncellenmesi gerekir. Bu yüzden `case 1` içinde hem ekleme hem dosya yazma fonksiyonu çağrılır. Fonksiyon `file_opr.c` dosyasındadır (ekrandan, 01:05:00):

```c
// This function is used for printing to the file.
void printListWithAllInformations(Patient_Node **head){
    FILE *fs=fopen ("list.txt","wb");
    if (fs==NULL)
    {
        printf("File cannot be opened\n");
        exit(0);
    }

    Patient_Node *var_head = (*head);

    while(var_head != NULL)
    {
        fwrite(&(var_head->data), sizeof(Patient), 1, fs); //fwrite(*ptr, size, count, FILE *stream)
        var_head = var_head->next;
    }
    fclose(fs);
    printf("\nFile is updated\n");
}
```

Fonksiyon bir şey döndürmez; yalnız dosyaya yazar ve listeyi parametre olarak alır. Önce `FILE` türünden bir işaretçi tanımlanır. Dosya adı sabit yazılmıştır, kullanıcıdan da alınabilirdi.

Açma kipi olarak `wb` (write binary) seçildi. Neden ekleme kipi (`ab`, append) değil? Yeni eleman bazen başa, bazen araya, bazen sona ekleniyor; nereye ekleneceği belli değildir. Bu yüzden her seferinde liste dosyaya baştan yazılır. Yeni düğümün dosyadaki yerini bilip ona göre yazmak da mümkündür; bu daha verimli (optimize) bir sürüm olurdu.

`wb` ile yazılan dosya yalnız `rb` (read binary) ile okunabilir. Dosya doğrudan açılırsa düzgün görünmez; ancak örneğin bir onaltılık (hexadecimal) düzenleyiciyle içi incelenebilir.

`malloc` ve `calloc` gibi `fopen` da başarısız olursa `NULL` döndürür; bu kontrol edilir ve hata varsa mesaj verilip programdan çıkılır.

Başarılıysa liste `var_head` ile baştan gezilir. `fwrite`'ın yaptığı şudur: bellekte verilen adresten, verilen boyutta, verilen adet kadar veriyi al ve akışa (stream) yaz. `var_head->data` işaretçi değil bir yapı değişkeni olduğu için adresi `&` ile alınır. Boyut `sizeof(Patient)`'dır, yani yalnız hasta bilgileri yazılır (`next` adresi yazılmaz). Her düğüm için bir tane yazılır, sonra `var_head` ilerletilir. `var_head` `NULL` olunca `fclose` ile dosya kapatılır ve "File is updated" mesajı verilir.

## 9. Hasta Silme: delete_patient

Kullanıcı 2'yi seçerse silinecek hastanın adı istenir. Ad, dersin başında anlatıldığı gibi `&` olmadan `scanf` ile okunur. Silme fonksiyonuna ad ve listenin adresi gönderilir.

Hoca burada bir not düştü: silme için isim yerine kimlik numarası kullanmak daha mantıklıdır, çünkü aynı ada sahip birden çok hasta olabilir.

Fonksiyon şöyledir (ekrandan, 01:10:00):

```c
// This function is used for deleting patient with name.
void delete_patient(char *name, Patient_Node **head){
    Patient_Node *patient = NULL, *var_head;
    var_head = (*head);
    while(var_head != NULL)
    {
        // If patient's name and entered name is equal, variable patient keeps patient that will delete.
        if(strcmp(var_head->data.name, name) == 0) // 0 means, two string is equal.
            patient = var_head;

        var_head = var_head->next;
    }

    // If patient is the head of list, new head will be the head->next.
    if(patient == (*head))
        (*head) = (*head)->next;
    else
    {
        // If patient is NULL, there is no patient in list with entered name.
        if(patient == NULL)
        {
            printf("\nCould not find the element with %s", name);
            return;
        }
        var_head = (*head);
        // Finding patient in list.
        while(var_head->next != patient)
        {
            var_head = var_head->next;
        }
        // When we delete the patient, previos node's next node will be the patient's next node.
        var_head->next = var_head->next->next;
        free(patient);
    }
}
```

Fonksiyon bir şey döndürmez; liste güncellensin diye `head` çift işaretçiyle alınır. Ad bir dizi olarak gönderildiği için adres olarak gelir ve `char *name` parametresiyle karşılanır.

### 9.1 Silinecek düğümü bulma

`patient` işaretçisi `NULL` ile başlar. `var_head` başa eşitlenir ve liste gezilir. Her düğümün adı silinecek adla karşılaştırılır. Dizgiler `==` ile karşılaştırılamaz; `==` adresleri karşılaştırır ve bunun anlamı yoktur. Bu yüzden `string.h` fonksiyonları (`strcpy`, `strcmp`) kullanılır. `strcmp` iki dizgi eşitse 0 döndürür; birincinin ASCII karşılığı büyükse sıfırdan büyük bir değer döndürür.

> **Ders sonrası not:** Derste birinci dizgi küçükse `strcmp`'nin "eksi bir" döndürdüğü söylendi. Standart yalnız negatif bir değer garanti eder; ajanın Linux (glibc) denemesinde `strcmp("a", "c")` $-2$ döndürdü. Bu yüzden sonuç `< 0` ile sınanmalıdır.

Eşleşme bulunursa `patient = var_head;` yapılır. Döngü eşleşmeden sonra da sona kadar devam eder. Hoca bunun bir eksik olduğunu belirtti: kimlik numarasıyla arama yapılsaydı bulunduktan sonra devam etmeye gerek yoktu. Aynı adlı bütün kişiler silinmek istenseydi bu yapı daha uygun olurdu. Sonuçta `patient`, adı eşleşen düğümde kalır.

### 9.2 Silme durumları

`patient` başa eşitse `(*head) = (*head)->next;` ile baş bir sonraki düğüme kaydırılır. İlk düğüm listeden atılmış olur, ama `free` yapılmamaktadır; hoca bunun atlanmaması gerektiğini söyledi.

Başa eşit değilse önce `patient`'ın `NULL` olup olmadığına bakılır; `NULL` ise ad listede yoktur, mesaj verilip fonksiyondan dönülür.

Bulunduysa `var_head` yeniden başa alınır ve silinecek düğümden bir önceki düğüm aranır: `var_head->next != patient` olduğu sürece ilerlenir. Önceki düğüm bulununca `var_head->next = var_head->next->next;` ile önceki düğüm, silinen düğümün arkasındakine bağlanır. Son olarak `free(patient);` ile düğüm bellekten silinir.

Listeyi ikinci kez taramanın ve `patient` işaretçisini tutmanın amacı `free` yapabilmektir; silinen düğüm bellekte kalmasın diye.

> **Ders sonrası not:** Liste boşken silme seçilirse `patient` ve `*head` ikisi de `NULL` olduğu için `patient == (*head)` koşulu doğru olur ve `(*head)->next` ifadesi `NULL` işaretçiyi açar. Karelerden kurulan kod ajan tarafından boş listede silmeyle denendiğinde segmentation fault verdi. Fonksiyonun başına `if(*head == NULL) return;` gibi bir kontrol eklenmelidir.

Silmeden sonra liste değiştiği için dosya baştan yeniden yazılır.

## 10. Dosyadan Okuma: read_File

Fonksiyon `file_opr.c` içindedir (ekrandan, 01:05:00 ve 01:20:00):

```c
// This function is used for reading from file.
void read_File(){
    Patient patient;
    FILE *fs=fopen ("list.txt","rb");
    if (fs==NULL)
    {
        printf("File cannot be opened\n");
        exit(0);
    }

    while( fread(&patient, sizeof(Patient), 1, fs) == 1 )
    {
```

<!-- BELİRSİZ: döngü gövdesindeki printf satırı ve fclose karelerde görünmüyor; altyazıya göre alanlar nokta ile yazdırılıyor, dizgiler %s, tamsayılar %d ile. -->

Dosya `wb` ile yazıldığı için aynı kipte, `rb` ile ve aynı adla (`list.txt`) açılır. Dosyadan okunacak her eleman bir `Patient` yapısıdır; bu yüzden bu türden bir değişken tanımlanır. `fopen`'ın başarısı `NULL` kontrolüyle sınanır.

`fwrite` bellekteki adresten okuyup akışa yazıyordu. `fread` bunun tersidir: akıştan okuyup verilen adrese yazar. Boyut yapının boyutu, adet 1'dir; kayıtlar tek tek okunur. `fread` başarılı olduğu sürece 1 döndürür; dosya sonuna (end of file) gelindiğinde 1 döndürmez. Bu yüzden döngü koşulu `== 1` biçimindedir.

Her okunan kayıtta döngüye girilir ve bilgiler yazdırılır. `patient` işaretçi değil yapı değişkeni olduğu için alanlarına nokta ile erişilir. İsim ve soy isim gibi karakter dizileri `%s`, tamsayılar `%d` ile yazdırılır. Sonunda `fclose` yapılır.

## 11. Programın Çalıştırılması

Program çalıştırıldığında menü geldi (01:20:43 sonrası; bu bölümün karesi yok):

- 1 seçilip önceliksiz bir hasta eklendi (yaş 21). Dosya güncellendi.
- 1 seçilip öncelikli bir hasta eklendi (yaş 23). Her eklemeden sonra dosya yazma fonksiyonu çağrıldığı için liste dosyaya yazıldı.
- 3 ile dosya okundu: ikinci eklenen hasta öncelikli olduğu için başa geçmişti, önceliksiz hasta arkasındaydı.
- Üçüncü olarak öncelikli bir hasta daha eklendi. Dosya okununca bu hastanın diğer öncelikli hastanın arkasına eklendiği, önceliksiz hastanın en sonda kaldığı görüldü.
- 2 seçilip önceliksiz hastanın adı girildi; dosya yeniden okununca bu hastanın listeden çıkarıldığı görüldü.

Ajan, karelerdeki satırları birleştirip görünmeyen kısımları (`#include` satırları, `MAX_SIZE` ve uyarı makrosu, `read_File`'daki yazdırma satırı) tamamlayarak kodu `gcc -Wall` ile derledi; uyarı çıkmadı. Önceliksiz, öncelikli, öncelikli, önceliksiz sırasıyla dört hasta girildiğinde dosyadan okunan sıra şu oldu: birinci öncelikli, ikinci öncelikli, birinci önceliksiz, ikinci önceliksiz. Ardından aradaki önceliksiz hasta, sonra baştaki öncelikli hasta silindi, listede olmayan bir ad için "Could not find the element with ..." mesajı alındı. Bu davranış derstekiyle uyumludur.

## 12. Ayrı Derleme, Bağlama ve Makefile

Dersin başında `file_opr.c` doğrudan `#include` edilmişti. Bu bölümde dosyaları ayrı derleyip nesne dosyalarını bağlayarak çalıştırılabilir dosya üretmek gösterildi.

### 12.1 Küçük örnek

Bunun için çok basit bir örnek hazırlandı. `uygulama.c` içinde `stdio.h` ve kendi başlık dosyası `func.h` eklenir; başlıkta küçük bir fonksiyonun prototipi vardır. `main` içinde bir tamsayıya 9 verilir, bir `printf` yapılır, `square` fonksiyonu çağrılır ve sonra yine bir `printf` yapılır. `square.c` içindeki `square` fonksiyonu gelen parametreyi kendisiyle çarparak karesini bulur.

### 12.2 Elle derleme ve bağlama

Komut isteminde (Command Prompt) dosyaların bulunduğu klasöre geçildi (ekrandan, 01:30:00):

```text
gcc -c uygulama.c -o uygulama.o
gcc -c square.c -o square.o
gcc uygulama.o square.o -o program
```

İlk denemede dosya adı yanlış yazıldığı için "No such file or directory" hatası alındı; düzeltilince nesne dosyası oluştu. `-c` yalnız derler ve nesne dosyası üretir, `-o` çıktı dosyasının adını verir. Son komut iki nesne dosyasını bağlar ve `program` adlı çalıştırılabilir dosyayı üretir. `program` çalıştırılınca şu çıktı alındı (ekrandan, 01:35:00):

```text
Program started!
81
Program successfully ended
```

### 12.3 Makefile

Çok sayıda C dosyası varsa ve hepsi birbirine bağlıysa bu komutları her seferinde konsola yazmak istenmez. Bunun için `Makefile` yöntemi kullanılır. `Makefile` adında, uzantısız bir dosya oluşturulur ve herhangi bir metin düzenleyiciyle (burada Notepad++) açılır.

İlk denemede dosyaya yalnız `uygulama:` hedefi ve altına derleme komutu yazıldı. Hedefin adı serbesttir, `uygulama` olmak zorunda değildir. Windows'ta derleyici MinGW olduğu için `make` yerine `mingw32-make` komutu çalıştırıldı ve elle yazılan komut dosyadan aynen işletildi.

Ardından `square` hedefi de eklendi, ama `mingw32-make` yine yalnız `uygulama.c`'yi derledi. Neden? Çünkü `make` yalnız ilk hedefi işleyip bırakır; dosyadaki bütün komutları sırayla okuma özelliği yoktur. Bu yüzden en başa `program` adlı bir hedef yazıldı: önce `uygulama`, sonra `square` hedeflerini çalıştır, ardından nesne dosyalarını bağlayıp `program`'ı oluştur. Son hâl (ekrandan, 01:35:00):

```text
program:uygulama square
	gcc uygulama.o square.o -o program
uygulama:
	gcc -c uygulama.c -o uygulama.o

square:
	gcc -c square.c -o square.o
```

`mingw32-make` bu kez üç komutu da çalıştırdı; `program` çalıştırılınca yukarıdaki çıktı alındı. Ajan aynı Makefile'ı, `func.h`, `square.c` ve `uygulama.c` dosyalarını yeniden kurarak Linux'ta `make` ile denedi; üç komut aynı sırayla çalıştı ve program `81` yazdı.

> **Ek bilgi (derste anlatılmadı):** `make` komut satırında hedef verilmezse dosyadaki ilk hedefi (varsayılan hedef) üretir; o hedefin önkoşulları (`:` sağındakiler) önce işlenir. Bir hedef `make square` biçiminde adıyla da çağrılabilir. Komut satırları sekme (Tab) karakteriyle başlamalıdır.

> **Ders sonrası not:** Derste GCC'nin Linux tarafından yazılmış bir derleyici olduğu söylendi. GCC, GNU projesinin derleyicisidir ve Linux'ta yaygın olarak kullanılır. MinGW de GCC'yi Windows'a taşıyan araç takımıdır.

Hoca, derste bu tür bir örnek yapılıp yapılmadığını bilmediğini, Makefile'ı görmüş olmaları için eklediğini söyledi.

## Örnek Sorular

### Soru 1: Acil servis kuyruğu (ekrandan, 00:10:00 ve 00:15:00)

Bir hastanenin acil servisi için hastaların sırasını izleyen bir kuyruk yazın. Hastalardan isim, soy isim, T.C. kimlik numarası ve yaş alınır; her hastanın bir öncelik bilgisi vardır. (1) Acil olmayan hasta kuyruğun sonuna eklenir. (2) Öncelikli hasta listedeki son öncelikli hastadan sonraki sıraya yerleşir; listede öncelikli hasta yoksa başa eklenir. (3) Vazgeçen hasta ismi kullanılarak kuyruktan çıkarılır. (4) Kuyruktaki hastaların bilgileri dosyada tutulur. (5) İstenildiğinde bilgiler dosyadan okunur. Örnek: `1 2 3 4 5` kuyruğuna öncelikli 6 gelince `6 1 2 3 4 5`, öncelikli 7 gelince `6 7 1 2 3 4 5`, 3 çıkınca `6 7 1 2 4 5`.

**Çözüm (derste verildi):** Bölüm 3-10'daki kod. Yapı `Patient` ve düğüm `Patient_Node`; ekleme `insert_patient_to_list` içinde `last_prior` ile son öncelikli düğümün bulunması ve beş durumun ayrılması; silme `delete_patient` içinde `strcmp` ile arama, başı kaydırma ya da önceki düğümü bulup bağlantıyı atlama ve `free`; dosya `wb` ile baştan yazılıp `rb` ile `fread(...) == 1` döngüsünde okunur. Ajanın derlediği sürümde örnekteki sıralar elde edildi.

### Soru 2: Dizi ile bağlı listenin karşılaştırılması (derste sözlü, 00:15:06)

Dizilerle bağlı listelerin avantajı ve dezavantajı nedir?

**Çözüm (derste verildi):** Dizide indisle doğrudan erişim vardır, ama araya ekleme ve çıkarmada elemanları kaydırmak gerekir. Bağlı listede ortadaki elemana ulaşmak için baştan ilerlemek gerekir, ama ekleme ve çıkarma `next` bağlantıları değiştirilerek kaydırma olmadan $O(1)$ ile yapılır.

### Soru 3: Makroda eşittir işareti (derste sözlü, 00:24:49)

`#define MAX_SIZE 20` yerine `#define MAX_SIZE = 20` yazılsaydı `char name[MAX_SIZE];` satırı ne olurdu?

**Çözüm (derste verildi):** Ön işlemci makro adının yerine yanındaki metni olduğu gibi koyar. Satır `char name[= 20];` olur; bunun anlamı yoktur ve derleme hatası verir. Bu yüzden makroda `=` yazılmaz.

### Soru 4: Dosyadan kayıt silme (derste sözlü, 01:16:06)

Listeden silinen hasta dosyadan nasıl silinir?

**Çözüm (derste verildi, 01:26:19):** C'de dosyadan tek bir kaydı silen doğrudan bir fonksiyon yoktur. Dosyanın üzerine yazılır. Bu programda her değişiklikten sonra liste `wb` kipiyle dosyaya baştan yazıldığı için silinen hasta dosyadan da çıkar.

## Dersin Toparlaması

Bu uygulamada dönemin üç ana konusu tek problemde birleşti. Hasta bilgileri `struct` ile, kuyruk kendine gönderen bir düğüm yapısıyla kurulan bağlı listeyle, kalıcılık ise ikili kipte dosya yazma ve okumayla sağlandı. Ekleme fonksiyonunda sıradan sona eklemenin ötesinde, `last_prior` işaretçisiyle son öncelikli düğüm bulundu ve beş durum (boş liste, sona ekleme, başa ekleme, başın arkasına ve son öncelikli düğümün arkasına ekleme) ayrı ayrı incelendi. Bağlantı değişimlerinde düğüm adresini kaybetmemek için `temp` kullanmanın, sona eklerken `next`'i sorgulamanın ve `head`'i çift işaretçiyle göndermenin nedenleri üzerinde duruldu. Silmede `strcmp` ile arama, başı kaydırma, önceki düğümü bulup bağlantıyı atlama ve `free` gösterildi.

Son bölümde programın dosyalara bölünmesinin diğer yolu, yani ayrı derleme (`gcc -c`), nesne dosyalarını bağlama ve bu adımları otomatikleştiren `Makefile` gösterildi. Hoca, kodun iyileştirilmeye açık yerlerini öğrencilerin kendilerinin düzeltmesini önerdi: silmede isim yerine kimlik numarası kullanmak, öncelikli eklemede önceliksiz düğüm görülünce taramayı durdurmak ve fazla `head` kontrollerini azaltmak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
