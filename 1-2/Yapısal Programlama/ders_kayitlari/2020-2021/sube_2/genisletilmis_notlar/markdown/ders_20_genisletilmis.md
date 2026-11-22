# Ders 20 Genişletilmiş Notu: Bağlı Liste Uygulaması ve Dosya İşlemlerine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bağlı liste uygulamasına hazırlık
- 2. Kayıt ekleme: createNode ve addRecord
- 3. Kayıt silme: removeRecord
- 4. Fonksiyon işaretçisiyle kayıtları yazdırma
- 5. Programın derlenmesi ve hata ayıklama
- 6. Bağlı listede iki düğümün yer değiştirmesi
- 7. Girdi/çıktı ve stream kavramı
- 8. Dosyanın yapısı: header, data, footer
- 9. Erişim türleri ve dosya operasyonları
- 10. Dosya nasıl okunur, nasıl yazılır?
- 11. C'de dosya açma: fopen ve erişim modları
- 12. Okuma ve yazma fonksiyonları
- 13. Rastgele erişim: fseek ve ftell
- Örnek Sorular

## 1. Bağlı liste uygulamasına hazırlık

Ders, önceki haftada başlanan bağlı liste örneğinin geliştirilmiş bir sürümüyle başladı. Önceki örnekte liste başını tutan `head` değişkeni global tanımlanmıştı. Hoca bu kez `head`'i `main` içinde yerel bir değişken olarak tanımladı ve fonksiyonlara parametre olarak aktardı.

> **Hocanın vurgusu:** Global değişken kullanmayın. C ya da Java ödevlerinizde, özellikle veri yapıları ve algoritma analizi derslerinde global değişken kullanmak ciddi puan kaybettirir.

Bu örnekte düğümler daha fazla veri saklar: her çalışanın adı, soyadı ve kimlik numarası (id) string olarak tutulur. Yapı şöyledir (ekrandan, 00:20:00):

```c
typedef struct Employee{
    char name[21];
    char surname[21];
    char id[11];
    struct Employee *next;
}EMPLOYEE;
```

`next` alanı, listedeki bir sonraki düğümün adresini tutar. Hoca burada işaretçilerle ilgili sık yapılan bir hatayı hatırlattı:

> **Hocanın vurgusu:** İşaretçi değişkenler verinin kendisini değil, verinin adresini saklar. `int *p;` tanımlayıp `p = 6;` yazmak, p'nin 6 numaralı adresi göstermesi demektir.

Program basit bir menüyle çalışır: 1 ekleme, 2 silme, 3 çıkış. Ekleme fonksiyonu `head`'i günceller, çünkü her yeni kayıt listenin başına eklenir. Hoca sona ekleme, araya sıralı ekleme gibi diğer sürümlerin menüye eklenmesini öğrencilere bıraktı. `main` fonksiyonu şöyledir (ekrandan, 00:50:00):

```c
int main(){
    EMPLOYEE *head=NULL;
    int choice=0;
    while(choice!=3){
        printf("1-Add \n2-Remove\n3-Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1: addRecord(&head); printRecords(head,printfIdFirst);break;
            case 2: removeRecord(&head); printRecords(head,printfNameFirst);break;
        }
    }
}
```

`addRecord`'a `head`'in kendisi değil adresi (`&head`) gönderilir. Bunun nedeni, `head`'in gösterdiği değerin fonksiyon içinde değişecek olmasıdır. Hoca, aynı işin yeni düğümün adresini `return` ile döndürüp `main`'de `head`'e atayarak da yapılabileceğini, ama fonksiyonun `void` olması ve `head`'in parametre üzerinden değişmesi istendiği için adresin gönderildiğini söyledi.

Hoca fonksiyon adlarında camelCase biçimini kullandı: ilk kelime küçük harfle başlar, sonraki kelimelerin ilk harfleri büyük yazılır (`printRecords`, `printfNameFirst`).

## 2. Kayıt ekleme: createNode ve addRecord

### 2.1 Düğümü heap'te oluşturmak

Yeni bir kayıt eklenirken önce kullanıcıdan alanlar okunur ve bu alanlar bir struct elemanına yazılır. Bu elemanın listede kalıcı olması için belleğin heap bölgesinde oluşturulması gerekir; bu da dinamik bellek ayırma (`malloc`) demektir. Hoca ilk olarak bu işlemi doğrudan `addRecord` içinde yazdı (ekrandan, 00:25:00), sonra ders ilerlerken düğüm oluşturma kısmını ayrı bir `createNode` fonksiyonuna taşıdı (ekrandan, 00:55:00):

```c
EMPLOYEE *createNode(){
    EMPLOYEE *emp;
    emp = (EMPLOYEE*) malloc(sizeof(EMPLOYEE));
    printf("Enter id, name and surname, respectively");
    scanf("%s %s %s",&emp->id,&emp->name,&emp->surname);
    printf("Eleman oluşturuldu");
    return emp;
}

void addRecord(EMPLOYEE **phead){
    EMPLOYEE *emp=createNode();
    emp->next=*phead;
    *phead=emp;
}
```

İsim alanı için hoca kısaca boşluk içeren adların okunmasını düşündü, ama örneği sade tutmak için adın tek kelime olmasına karar verdi.

`scanf` satırında hoca `emp->id` yazmanın neden yetmeyeceğini, `emp`'nin gösterdiği yerdeki `id` alanının adresinin alınması gerektiğini söyledi ve `&emp->id` yazdı.

> **Ders sonrası not:** Hoca `&emp->id` biçimini kullandı. `id`, `name` ve `surname` dizi olduğu için `emp->id` ifadesi zaten dizinin ilk elemanının adresidir; `%s` ile `&` kullanılmamalıdır. `&emp->id` aynı adres değerini verdiği için program çalışır, ama türü `char (*)[11]` olduğundan `gcc -Wall` uyarı verir. Doğrusu `scanf("%s %s %s", emp->id, emp->name, emp->surname);` biçimidir.

`createNode` ayrı bir fonksiyon olunca başa ekleme, sona ekleme, ada göre sıralı ekleme gibi her ekleme fonksiyonu bu fonksiyonu çağırır; `malloc`, `printf` ve `scanf` satırları her birinde tekrar yazılmaz.

### 2.2 Ekleme adımlarının bellek üzerinde izlenmesi

Hoca ekleme işlemini adres değerleriyle çizerek anlattı (ekrandan, 00:25:00):

- Program açılınca `head` değişkeni örneğin 100 numaralı adrestedir ve içinde `NULL` vardır.
- `addRecord(&head)` çağrılınca fonksiyondaki `phead` parametresine 100 gelir. Bu bir işaretçinin adresi olduğu için `phead` ikinci dereceden işaretçidir (`EMPLOYEE **`).
- `malloc` ile heap'te bir struct açılır, örneğin 300 numaralı adreste; `emp` içinde 300 yazar. Değerler okunur.
- `emp->next=*phead;` satırı yeni düğümün `next` alanına `phead`'in gösterdiği yerdeki değeri yazar. Bu, `main`'deki `head`'in o anki değeridir; ilk eklemede `NULL`'dır.
- `*phead=emp;` satırı `phead`'in gösterdiği adrese, yani `main`'deki `head`'e, 300 yazar. Artık `head` yeni düğümü gösterir.

İkinci kayıt eklenirken `head` artık `NULL` değildir. `head`'in kendi adresi değişmez (100), çünkü `main` henüz bitmemiştir ve `head` yığında yaşamaya devam eder. Yeni düğüm örneğin 500 numaralı adreste açılır; `emp->next=*phead` ile `next`'i 300'ü gösterir, `*phead=emp` ile `head` 500 olur. Böylece `head` → 500 → 300 → `NULL` zinciri oluşur.

> **Ders sonrası not:** Hoca çizim sırasında "sanki bir circular durum var gibi" dedi. Bu kodda liste dairesel değildir; ilk eklenen düğümün `next`'i `head`'in başlangıçtaki `NULL` değerini alır ve zincir `NULL` ile biter.

## 3. Kayıt silme: removeRecord

### 3.1 Fikir

Silme genellikle id üzerinden yapılır. Bir düğüm silinirken, ondan önceki düğümün `next`'i silinen düğümden sonrakine bağlanmalıdır. Bunun için iki işaretçi tutulur: aramayı yapan `current` ve bir önceki düğümü tutan `prev`. Liste `head` ile değil `current` ile gezilir ki liste başı kaybolmasın.

Arama iki koşulla sürer: liste bitmemiş olmalı ve kayıt henüz bulunmamış olmalıdır. Bulununca aramanın tekrar etmemesi için `found` değişkeni kullanılır. String karşılaştırması için `strcmp` kullanılır.

### 3.2 Kod

Ekrandaki son hali şöyledir (ekrandan, 00:45:00 ve 00:55:00):

```c
void removeRecord(EMPLOYEE **phead){
    char id[11];
    EMPLOYEE *current=*phead;
    EMPLOYEE *prev=NULL;
    int found=0;
    printf("Enter id of the employee");
    scanf("%s",id);
    while(current!=NULL && !found){
        if(strcmp(current->id,id)==0){
            found=1;
            if(prev==NULL){
                *phead=current->next;
            }
            else{
                prev->next=current->next;
            }
            free(current);
        }
        else{
            prev=current;
            current=current->next;
        }
    }
}
```

Hoca önce `id` dizisini 12 karakterlik tanımlamıştı; bir öğrencinin uyarısıyla struct'taki alanla aynı olacak şekilde 11 yaptı.

### 3.3 Silmenin adım adım izlenmesi

Hoca üç düğümlü bir liste üzerinden iki durumu izledi: `head` 800 numaralı düğümü, o 500'ü, o da 300'ü gösteriyor.

**İlk düğümün silinmesi:** `current=*phead` ile `current` 800'ü gösterir, `prev` `NULL`'dır. Girilen id ilk düğümdekine eşitse `found=1` olur. `prev==NULL` olduğu için `*phead=current->next` çalışır: `head`'e 500 yazılır ve 800 ile bağ kopar. Ardından `free(current)` ile 800 numaralı düğümün belleği serbest bırakılır. Kayıt bulunduğu için döngü biter.

**Aradaki düğümün silinmesi:** Liste artık `head` → 500 → 300 → `NULL` durumundadır ve aranan kayıt 300'dedir. İlk turda 500'deki id eşit değildir; `else` kısmında `prev=current` ile `prev` 500 olur, `current=current->next` ile `current` 300 olur. İkinci turda id eşittir, `found=1` olur. `prev` artık `NULL` değildir, bu yüzden `prev->next=current->next` çalışır: 500 numaralı düğümün `next`'i 300'ün `next`'ini (`NULL`) alır. Sonra `free(current)` ile 300 numaralı düğüm yok edilir.

Hoca `free`'den sonra düğümün içindeki değerlerin ne olacağını bilmediğini, bunun `printf` ile denenebileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** `free` edilmiş bir bellek alanına erişmek tanımsız davranıştır. Alan büyük olasılıkla başka bir `malloc` tarafından tekrar kullanılabilir ve eski değerler kalabilir ya da bozulabilir. Bu yüzden `free` sonrasında o işaretçi kullanılmamalı, gerekirse `NULL` yapılmalıdır.

Hoca bu bölümü "çift işaretçi kullanarak `head`'in gösterdiği kısmı dinamik olarak değiştirdik" diye özetledi.

## 4. Fonksiyon işaretçisiyle kayıtları yazdırma

Kayıtları yazdırmak, listenin başından başlayıp sonuna kadar gitmek demektir. Önce ad sonra id, ya da önce id sonra ad yazan iki farklı biçim istense bile gezinme döngüsü aynıdır. Bu yüzden iki ayrı `while` döngüsü yazmak yerine, hangi yazdırma fonksiyonunun çağrılacağını parametre olarak alan genel bir fonksiyon yazıldı. Bu, önceki haftada işlenen fonksiyon işaretçileri konusunun bir uygulamasıdır.

Yazdırma fonksiyonları `head` üzerinde değişiklik yapmadığı için tek işaretçi yeterlidir (ekrandan, 00:45:00):

```c
void printfNameFirst(EMPLOYEE *emp){
    printf("%s %s %s\n",emp->name,emp->id,emp->surname);
}
void printfIdFirst(EMPLOYEE *emp){
    printf("%s %s %s\n",emp->id,emp->name,emp->surname);
}
```

Genel fonksiyonun prototipi şöyledir (ekrandan, 00:50:00):

```c
void printRecords(EMPLOYEE *head, void (*fptr)(EMPLOYEE *));
```

`fptr`, `EMPLOYEE *` parametresi alan ve `void` döndüren bir fonksiyonun adresini tutar. Fonksiyonun gövdesinde gezinmek için geçici bir `tmp` işaretçisi oluşturulur, her düğümde `fptr(tmp)` çağrılır ve `tmp` bir sonrakine ilerletilir. Hatası düzeltilmiş hali şöyledir:

```c
void printRecords(EMPLOYEE *head, void (*fptr)(EMPLOYEE *)){
    EMPLOYEE *tmp=head;
    while(tmp!=NULL){
        fptr(tmp);
        tmp=tmp->next;
    }
}
```

<!-- BELİRSİZ: printRecords gövdesi karelerde görünmüyor; altyazıdaki anlatımdan ve sonradan yapılan düzeltmeden kuruldu. -->

## 5. Programın derlenmesi ve hata ayıklama

İlk derlemede `current` değişkeninin tanımsız olduğu hatası alındı; yazdırma fonksiyonunda `current` yerine `tmp` kullanılması gerekiyordu. Düzeltilince program uyarısız derlendi. Ancak ilk kayıt eklendikten sonra program çöktü.

Hoca önce `createNode`'a "Eleman oluşturuldu" çıktısı ekleyerek hatanın nerede olduğunu aradı, sonra Dev-C++'ın hata ayıklayıcısında satıra kesme noktası (breakpoint) koydu ve `emp`, `*phead`, `emp->next` değerlerini izledi (ekrandan, 01:00:00). Ekleme fonksiyonunda mantıksal bir hata görünmüyordu, ama her denemede segmentation fault alınıyordu.

Bu sırada bir öğrenci, `printRecords` içindeki döngü koşulunun `while(head!=NULL)` yazıldığını, orada `tmp` olması gerektiğini fark etti. `tmp` ilerletilirken `head` hiç değişmediği için koşul hiç yanlış olmaz; `tmp` `NULL` olunca `fptr(NULL)` çağrılır ve `NULL` adresinden okuma yapılmaya çalışıldığı için program çöker. Koşul `tmp!=NULL` yapılınca program doğru çalıştı.

Program sonra şu senaryoyla denendi (ekrandan, 01:05:00): `a a a`, `b b b`, `c c c` eklendi (her yeni kayıt başa geldi); `a` silindi; `d d d` eklendi; `c` silindi (geriye `d` ve `b` kaldı); `aa aa aa` eklendi; `b` silindi. Kod `gcc -Wall` ile derlenip aynı girdilerle denendi ve aynı sonuçları verdi.

Bu kısımda öğrencilerden gelen sorular:

**Soru:** Herhangi bir şey `return` etmediğimiz için mi çift işaretçi kullanıyoruz? **Cevap:** Evet. `head` değiştirileceği için buna ihtiyaç var.

**Soru:** Kökün (`head`'in) kendisini verip en sonda `return` ile geri döndürsek de aynı sonucu alır mıyız? **Cevap:** Alırız. Ama fonksiyonun `void` olması şart koşulursa değişiklik parametre üzerinden yapılmalıdır.

**Soru:** Liste boşsa ilk elemanı atayıp, boş değilse sona eklesek olur mu? **Cevap:** Olur; bu sona ekleme olur. Başa ekleme için ayrı bir koşul bloğu açılabilir.

### 5.1 Geliştirme önerileri

Hoca örneğin geliştirilmeye açık olduğunu söyledi ve şu çalışmaları önerdi: listeyi çift yönlü bağlı listeye çevirmek, araya ekleme ve aradan silme, sıralama, bir kaydı bulup güncelleme. Silme ve güncelleme için ortak bir arama fonksiyonu yazılabilir; bu fonksiyon düğümü, öncesini ve sonrasını bulur, tıpkı `createNode`'un ekleme fonksiyonlarına ortak olması gibi.

## 6. Bağlı listede iki düğümün yer değiştirmesi

Sıralama yaparken düğümlerin yer değiştirmesi (swap) gerekir ve bağlı listelerde bu zor bir problemdir. Hoca beş düğümlü bir liste çizdi ve düğümlerin adreslerini 0, 1, 2, 3, 4 diye numaraladı (ekrandan, 01:10:00). 0'ın `next`'i 1'i, 1'inki 2'yi, 2'ninki 3'ü, 3'ünki 4'ü gösterir. 2 numaralı düğüm `n1`, 4 numaralı düğüm `n2` olarak seçildi.

### 6.1 Yanlış yol

Diziler gibi düşünüp yalnız şu üç satırı yazmak işe yaramaz:

```text
tmp = n1;
n1  = n2;
n2  = tmp;
```

Hoca bu adımları çizimde izledi. `tmp` 2'yi gösterir; `n1`'e 4 kopyalanınca 1'den sonra doğrudan 4'e geçilir; `tmp`'nin `n2`'ye kopyalanmasıyla da 2 ve 3 numaralı düğümler zincirden kopar. Sonuçta listede arada kalan düğümler kaybolur.

### 6.2 Doğru yol

Takastan önce iki düğümün öncülleri saklanmalıdır (ekrandan, 01:15:00): `tmpPrevN1` (n1'den önceki düğüm) ve `tmpPrevN2` (n2'den önceki düğüm). Hoca önce bu değişkenlere 1 ve 3 yazdı, sonra öncüllerin kendi adreslerinin gerektiğini söyleyerek düzeltti. Takastan sonra `tmpPrevN1`'in `next`'i yeni `n1`'e, `tmpPrevN2`'nin `next`'i yeni `n2`'ye bağlanır ve düğümlerin kendi `next` alanları da güncellenir. Böylece iki düğüm bağlantılar kopmadan yer değiştirmiş olur.

<!-- BELİRSİZ: Doğru takasın adımları derste çizim üzerinde ve kısmen karışık anlatıldı; tam kod yazılmadı. -->

**Soru:** Kutuların gösterdiği yerleri uygun sırayla değiştirince kutuların yeri zaten değişmiş olmuyor mu, içlerini kopyalamaya gerek var mı? **Cevap:** İçerik kopyalanmıyor. Çizimde veriler kopyalanıyormuş gibi görünse de yapılan şey adreslerin yer değiştirmesidir; veriler bellekte yerinde durur.

### 6.3 Alternatif: yalnız verileri kopyalamak

Kitaplarda sık görülen diğer yol, düğümler arasındaki bağlantılara hiç dokunmadan düğümlerin veri alanlarını `memcpy` ile blok olarak kopyalamaktır. Bu, bağlantılarla uğraşmanın algoritmik yükünü azaltır ama daha fazla kopyalama işi getirir. Burada dikkat edilmesi gereken nokta, `memcpy`'nin struct'ın tamamına değil, `next` alanı dışındaki elemanlara uygulanmasıdır.

> **Ek bilgi (derste anlatılmadı):** Bağlantılarla takas yapılırken iki düğümün komşu olduğu durum (`n1->next == n2`) ve düğümlerden birinin listenin ilk düğümü olduğu durum (öncülü yoktur, `head` güncellenir) ayrıca ele alınmalıdır. Bu özel durumlar unutulursa liste büyük olasılıkla döngüye girer ya da baş kaybolabilir.

Hoca, bağlı listelerin `int` aralığına sığmayan çok büyük sayıları saklamak ve toplamak ya da çarpmak için de kullanıldığını, iki sayının toplamının eldelerle birlikte yeni bir bağlı liste olarak oluşturulduğunu söyledi. Bu tür problemlerin işaretçi, struct ve bağlı liste mantığını birlikte kavramak için iyi olduğunu ekledi.

## 7. Girdi/çıktı ve stream kavramı

### 7.1 Neden dosya?

Şimdiye kadarki örneklerde girdi klavyeden, çıktı ekrana yapıldı. Gerçek uygulamalarda girdi bir paralel ya da seri porttan gelebilir; çıktı yazıcıya ya da kalıcı bir hafıza birimine gidebilir. Program kapandıktan sonra da verinin saklanması isteniyorsa veri sabit disk gibi kalıcı bir bellekte saklanmalıdır. Bu işlemler girdi/çıktı (I/O) başlığı altında toplanır ve C'de çoğunlukla dosya işlemleriyle yapılır.

Dosya açma, okuma ve yazma sırasında veri diskten RAM'e ya da RAM'den diske taşınır. Bu taşıma işletim sisteminin çekirdeğinin (kernel) sunduğu hizmetle, işletim sistemiyle koordinasyon içinde gerçekleşir.

### 7.2 Tamponlu ve tamponsuz I/O

C'nin kendi kütüphaneleri tamponlu (buffered) I/O ile, Unix kütüphaneleri ise tamponsuz (unbuffered) I/O ile çalışır. Hoca tamponun gerekçesini disk ile işlemci arasındaki hız farkıyla açıkladı. Sabit diskte üst üste diskler ve bir okuma-yazma kafası vardır; disk döner, kafa ilgili bloğa gelince veriyi okur. 7200 RPM'lik bir disk dakikada 7200, saniyede $7200/60 = 120$ tur atar. İşlemci ise GHz mertebesinde, yani saniyede yaklaşık $10^9$ işlem düzeyinde çalışır; örneğin 3.4 GHz. Bu iki hız kıyaslanamayacak kadar farklı olduğu için her okumada diske gidilmez; bir tampon kullanılır ve diske bloklar halinde yazılır ya da diskten bloklar halinde okunur.

### 7.3 Stream

Bir dosya açıldığında, örneğin bir Word belgesi ya da müzik dosyası, diskteki içerik RAM'e kopyalanır. Bu kopyalama sırasındaki veri akışına stream denir. Slayttaki tanıma göre (ekrandan, 01:40:00):

- C, terminal, teyp sürücüsü ya da diskteki dosya gibi aygıtlar arasında ayrım yapmaz; her durumda I/O, dosya ya da aygıtla ilişkilendirilmiş stream'ler üzerinden yapılır.
- Bir stream, sıralı bir byte dizisinden oluşur (tek boyutlu bir karakter dizisi gibi).
- Dosyaya ya da aygıta okuma/yazma, stream'den veri okumak ya da stream'e veri yazmak demektir.
- I/O işlemi için bir stream'in bir dosya ya da aygıtla ilişkilendirilmesi gerekir; bu, `FILE` adlı yapı türüne bir işaretçi tanımlanarak yapılır.

Hoca katmanlı bir tablo çizdi: en üstte program, altında işletim sistemi ve çekirdeği, en altta donanım. Program donanımla haberleşirken arada bir stream oluşturulur. Çalışan her programa bellekte bir yer ayrılır (hoca bunun için süreç kontrol bloğu, PCB adını andı); programın değişkenleri, kodu ve dizileri ile stream bilgisi de burada tutulur. Ayrıntıların işletim sistemleri dersinde anlatılacağını söyledi.

### 7.4 Standart stream'ler

Üç standart stream vardır: girdi için `stdin`, çıktı için `stdout`, hata durumları için `stderr`. Bunlar genellikle terminale bağlıdır. `printf` arka planda `stdout`, `scanf` ise `stdin` kullanır. Hoca, `printf`'in yaptığının da aslında arka planda komut satırının özel bir dosyasına yazmak olduğunu, dosyalarla çalışırken de aynı mantıkla bir dosya üzerinde komut satırı gibi çalışılacağını söyledi.

`<stdio.h>` başlık dosyası şunları içerir (ekrandan, 01:55:00): bütün I/O fonksiyonlarının prototipleri, `FILE` yapısının tanımı ve `stdin`, `stdout`, `stderr`, `EOF`, `NULL` gibi makro sabitler. `EOF`, sistem dosya sonu işaretine ulaştığında birçok fonksiyonun döndürdüğü değerdir. `NULL` boş işaretçinin adıdır ve `stddef.h` içinde de tanımlıdır; dosyanın açılıp açılmadığını kontrol ederken kullanılır.

## 8. Dosyanın yapısı: header, data, footer

### 8.1 Dosya bir 0-1 dizisidir

Dosya, diskte kalıcı olarak saklanan bir 0 ve 1 dizisidir; hoca onu başı ve sonu olan bir kare olarak çizdi (ekrandan, 01:45:00). Bu dizinin yerleşimine bir anlam verildiğinde özel amaçlı bir dosya oluşur.

Örneğin kişilerin adı, soyadı ve id'si bir Excel tablosu gibi saklanabilir. Daha basit hali olan CSV (comma separated values) formatında alanlar virgül ya da noktalı virgülle ayrılır. Dosya açık metin olarak açılınca "A, B, 3" gibi satırlar görülür. Kural şudur: ilk görülen alan ad, virgülden sonraki ikinci alan soyad, üçüncüsü id'dir. Arka planda bu da 0-1 olarak saklanır ve ilk bit dizisi ada karşılık gelir.

### 8.2 Açık metin ve binary dosyalar

Hoca, derste yazılan `.c` dosyasını Notepad++'da açarak açık metin olarak okunabildiğini gösterdi; sonra bir `.ppt` dosyasını aynı programda açtı ve içinde anlamsız karakterler göründü. Bunun nedeni `.ppt` dosyasının kendi yapısına göre binary olarak kodlanmış olmasıdır. İşletim sistemi bu dosyayı hangi programla açacağını bilir (varsayılan uygulama); örneğin hem WinZip hem WinRAR kuruluysa hangisiyle açılacağını sorar. Dosyanın içeriğini asıl çözen, o formatı bilen programdır.

Text stream'ler satırlardan oluşur ve her satır `\n` ile biter. Bazı sistemler satırları farklı yollarla saklar; örneğin birçok IBM sisteminde satır başlarının indeksleri ayrıca tutulur. I/O fonksiyonları yeni satır karakterlerini sisteme özgü karakterlerle değiştirebilir. Binary formatta ise hiçbir yorum yapılmaz; bitler olduğu gibi okunur ve onları anlamlandırmak açan programın işidir. Bu yüzden binary veriye gözle bakınca anlaşılması zordur; bir PDF dosyası metin düzenleyicide açılınca da anlamsız karakterler görülür. Slaytta Unix'in bütün dosyaları binary veri olarak gördüğü, text ile binary ayrımının çok yüzeysel olduğu da belirtildi.

### 8.3 Header, data, footer

Hoca dosyayı üç bölüme ayırdı: başta header, ortada data, sonda footer. Footer her zaman bulunmayabilir, header ise genellikle vardır.

Header dosyaya ait ön bilgileri taşır: dosyanın boyutu, adı, uzantısı, türü, konumu. Bir görüntü dosyasına tıklanınca program görüntünün boyutunu önceden bilmez; arka planda `malloc` gibi bir işlemle bellekte yer açması gerekir ve bunun bilgisini header'dan alır. Header ayrıca verinin nasıl yerleştiğini de söyler; örneğin bir PNG görüntüsünde ilk üç değerin 0. pikselin RGB değerleri, sonraki üçünün 1. pikselin RGB değerleri olduğu gibi format bilgisi. Bu bilgiler binary ya da text olarak saklanabilir. Binary saklamanın nedenleri daha az yer kaplaması ve içeriğin gizlenmesidir.

## 9. Erişim türleri ve dosya operasyonları

### 9.1 Sıralı erişim

Dosyalar text ve binary olarak sınıflandırıldığı gibi erişim biçimine göre de sınıflandırılır (ekrandan, 02:05:00). Sıralı erişimde (sequential access) dosya açıldığında konum göstergesi baştadır. Bir bit, bir byte, formatlı veri (örneğin bir string, bir `int`, bir `float`), bir satır ya da bir blok okunabilir. Okumadan sonra konum göstergesi okunan miktar kadar ilerler: bir bit okunduysa bir bit, formatlı veri okunduysa onun boyutu kadar. Hoca sıralı erişime örnek olarak teypleri ve manyetik teyp birimlerini verdi; eski ses kasetleri de basit bir örnektir.

### 9.2 Rastgele erişim

Rastgele erişimde (random access) konum göstergesi aradaki verileri okumadan istenen yere taşınabilir: dosya sonuna gidilebilir ya da `rewind` ile başa dönülebilir. Bulunulan yerden yine bit, byte ya da formatlı veri okunabilir. RAM ve rastgele erişimli dosyalar bu türe örnektir.

### 9.3 Dosya operasyonları

Dosyalar üzerindeki genel işlemler oluşturma, silme ve yeniden adlandırmadır; bunlar dosya yöneticisinde ya da komut satırında yapılan işlemlerdir. Asıl işlemler okuma ve yazmadır. Yazma üç biçimde olabilir:

- Sıfırdan yazma: dosyanın içi önce boşaltılır, yazma baştan başlar. Write modu genellikle böyle çalışır.
- Güncelleme (update): içerideki bir veriyi değiştirmek.
- Sona ekleme (append): içeriği bozmadan, konum göstergesinin bulunduğu yerden (dosya sonundan) veri eklemek.

Okuma ise yalnız okumadır; baştan ya da istenen yerden yapılabilir.

## 10. Dosya nasıl okunur, nasıl yazılır?

Hoca konunun özetini birkaç soru-cevapla verdi. Önce "Dosya nasıl okunur?" diye sordu. Bir öğrenci Python'da görüntüyü hazır fonksiyonlarla okuyabildiğini söyledi; hoca dilden bağımsız bir cevap beklediğini belirtti. Dosya önce uygun modda açılır; ardından içeriğin nasıl okunacağı sorusu gelir.

> **Hocanın vurgusu:** Dosya, yazıldığı gibi okunur.

Dosya ister text ister binary olsun sonuçta bir 0-1 dizisidir ve programlama dili bu bitleri anlamlandırır. "Yazıldığı gibi" demek, dosyayı yazan kişi hangi kuralla yazdıysa bitlerin o kurala göre parça parça alınıp anlamlandırılması demektir: örneğin ilk şu kadar bit dosyanın adı, sonraki şu kadarı boyutu.

Hoca bunu protein sentezine benzetti: protein sentezini başlatan üçlü bir kodon ve bitiren bir kodon vardır; aradaki bazlar üçer üçer okunur. Başlatıcı kodon görülünce sentez başlar, sonra her üçlüden bir amino asit üretilir. Dosya okuyucu da başlayıp biten 0-1 dizisini aynı biçimde parçalara ayırıp anlamlandırır.

Hoca örnek olarak bir BMP dosyasının header'ını gösteren kodu açtı. Header'da ilk iki byte'lık alan dosyanın türüne, sonraki alan boyutuna aittir; ardından görüntünün kaç renkten oluştuğu, genişliği ve yüksekliği (piksel sayısı) gibi bitmap'e özgü bilgiler gelir. Kuralı kim koyduysa okuyucu o kurala uymak zorundadır. PDF okuyucular da PDF'in sürümüne göre header'ı okumak zorundadır, aksi halde dosyayı açamazlar. Word belgelerinin (`.doc`, `.docx`) başka ofis programlarında açılabilmesi de o programların bu formatı desteklemesi sayesindedir.

<!-- BELİRSİZ: BMP header kodu ekranda gösterildi ama karelere düşmedi; alan adları ve boyutları altyazıdaki anlatımdan alındı. -->

İkinci soru "Dosya nasıl yazılır?" oldu.

> **Hocanın vurgusu:** Dosya, nasıl istiyorsak öyle yazılır. Mühendis olarak istememiz gereken de okumanın, yazmanın ve güncellemenin kolay olduğu, sade, anlaşılır ve verimli bir formattır.

Hoca bir görüntü formatının nasıl tasarlanabileceğini örnekledi: ilk 4 bit dosyanın türünü, sonraki bitler boyutunu, sonrakiler yatay ve dikey piksel sayısını söylesin; ardından veri kırmızı-yeşil-mavi değerleri sırayla gelsin; en sonda özel bir bit dizisi durdurucu olsun ya da hiç durdurucu olmasın. Gerçekte bütün dosyalar, hatta bütün görüntü dosyaları arasında bile böyle ortak bir standart yoktur; her format kendi verimlilik hedeflerine göre tasarlanmıştır. Performans yalnız erişim hızı değildir; bazı durumlarda dosyanın az yer kaplaması gerekir ve işin içine veri sıkıştırma girer. Tekrar eden veriler örneğin Huffman ya da run-length kodlama gibi yöntemlerle sıkıştırılabilir.

Dosyaların disk üzerinde B-ağaçları, 2-3-4 ağaçları gibi veri yapılarıyla saklanması dosya organizasyonu dersinin konusudur. Hoca, C'de bir PDF okuyucu yazılması istense önce PDF dosya formatının öğrenilmesi gerektiğini, header'daki alanlar okunduktan sonra verinin geleceğini ve verinin de sıkıştırılmış olabileceğini söyledi.

Son adım okuma biriminin seçimidir. Bit, byte, formatlı veri, satır ve blok okumanın her biri için ayrı fonksiyonlar vardır. Bir byte okunacaksa bit bit okumaya gerek yoktur; bir satır ya da blok veri okunacaksa onu da bit bit okumak her seferinde diske gidip gelmek demektir. Blok halinde bir veri varsa `sizeof` ile boyutu verilip doğrudan belleğe kopyalanır. Hoca 0-1 dizisini bir labirente benzetti: okuma fonksiyonları bu labirentteki gezinme hızını, dosya formatı da gezinme kuralını belirler.

Hoca bit okumanın bir defada bir bit okumak olduğunu, üç bit okumak için fonksiyonun üç kez çağrılması gerektiğini; byte okumak isteniyorsa doğrudan bir byte okunabileceğini söyledi. Klavyeden string okumak için kullanılan `gets` ve `puts` gibi, dosyalar için de karşılık gelen fonksiyonlar vardır.

Basit dosya formatlarına örnek olarak hoca iki tasarım çizdi (ekrandan, 02:20:00):

- Hastane randevusu kayıtları: ID, ad, soyad, tarih, poliklinik ve saat alanları. Bu dosyadaki her kişi için genel bir metin şablonunun içine bu alanlar yerleştirilerek "şu tarihte, şu saatte, şu poliklinikte randevunuz vardır" gibi otomatik bir e-posta metni üretilebilir.
- Matris dosyası: CSV'ye benzer bir formatta önce satır sayısı, virgül, sütun sayısı ve bir soru işareti; ardından matrisin elemanları noktalı virgülle ayrılarak yazılır. Okuyucu soru işaretini görene kadar virgülden önceki kısmı satır sayısı, virgülden sonrakini sütun sayısı olarak alır.

## 11. C'de dosya açma: fopen ve erişim modları

Okuma ya da yazmadan önce dosya açılmalıdır. `fopen` iki argüman alır: dosyanın adı ve erişim modu. Dosya adı tırnak içinde yazılır (örneğin `"deneme.c"`); yol içinde ters bölü (`\`) varsa kaçış karakteriyle karışmaması için çift yazılır (`\\`). Mod da tırnak içinde verilir. `fopen` geriye bir `FILE *` döndürür; hata olursa `NULL` döner.

Text stream'ler için modlar slaytta şöyle verildi (ekrandan, 02:25:00):

| Mod | Anlamı |
|---|---|
| `"r"` | Var olan bir text dosyayı okumak için açar. Okuma dosyanın başından başlar. Dosya yoksa `fopen` `NULL` döndürür. |
| `"w"` | Yazmak için yeni bir text dosya oluşturur. Dosya varsa uzunluğu sıfıra indirilir (içi boşaltılır). Konum göstergesi başta olur. |
| `"a"` | Var olan bir text dosyayı ekleme modunda açar. Yalnız dosya sonuna yazılabilir; konum göstergesi açıkça başka yere taşınsa bile yazma dosya sonunda olur. |
| `"r+"` | Var olan bir text dosyayı okuma ve yazma için açar. Konum göstergesi başta olur. |
| `"w+"` | Okuma ve yazma için yeni bir text dosya oluşturur. Dosya varsa içi boşaltılır. |
| `"a+"` | Var olan dosyayı açar ya da yoksa yenisini oluşturur. Dosyanın her yerinden okunabilir, ama yalnız dosya sonuna yazılabilir. |

Binary modlar aynıdır, yalnız mod adının sonuna `b` eklenir; örneğin binary bir dosyayı okumak için `"rb"` kullanılır (`"wb"`, `"ab"`, `"r+b"`, `"w+b"`, `"a+b"`).

> **Hocanın vurgusu:** `w` modu çok tehlikelidir. Var olan dosya `w` ya da `w+` ile açılınca içi tamamen silinir. Bu modda açmadan önce dosyanızı yedekleyin; ödev yaparken bu hata çok yapılır.

Hoca tabloyu şöyle özetledi: dosyanın önceden var olması `r` ve `r+` modlarında gerekir. Eski dosyanın içi `w` ve `w+` modlarında silinir. Okuma `r`, `r+`, `w+` ve `a+` modlarında yapılabilir. Yazma beş modda (`w`, `a`, `r+`, `w+`, `a+`) yapılabilir. `a` ile yazma hep sona yapılır; araya bir yere yazmak için `r+` ya da `w+` gibi modlar kullanılmalıdır. `r+` ile açılan dosyada konum başta olduğu için dosyanın başına da yazılabilir.

`FILE *` işaretçisi program içinde diğer işaretçiler gibi parametre olarak aktarılabilir; işaretçinin işaretçisine pek gerek olmaz. `fprintf`, `printf`'in hemen hemen aynısıdır; farkı, ekrana değil verilen stream'e yazmasıdır.

## 12. Okuma ve yazma fonksiyonları

### 12.1 Genel tablo

Hoca fonksiyonları okuma birimine göre sıraladı:

- Karakter: `getc` / `putc` (ve fonksiyon sürümleri `fgetc` / `fputc`).
- Satır: `fgets` / `fputs`. Klavyeden okuyan `gets` ve ekrana yazan `puts`'un dosya karşılıklarıdır.
- Blok: `fread` / `fwrite`.
- Formatlı: `fscanf` / `fprintf`.

Hepsinin kendi avantaj ve dezavantajları vardır. Bit okunması gerekiyorsa blok okumak, bir karakter okuyup 7 bitini atmak anlamsızdır. Blok okunacaksa işi garantiye almak için karakter karakter ya da bit bit okumak da performansı kötüleştirir.

### 12.2 Okuma ve yazma arasında geçiş, tamponun boşaltılması

Slayttaki kural (ekrandan, 02:30:00): bir stream'den okuduktan sonra araya `fseek()`, `rewind()` ya da `fflush()` çağrısı girmeden o stream'e yazılamaz; yazmadan okumaya geçişte de aynı kural geçerlidir. Bu üç fonksiyon tamponları boşaltan I/O fonksiyonlarıdır. Bellek sıkıntısı yoksa girdi stream'inden okunup çıktı verisi bellekte oluşturulabilir ve en sonda çıktı stream'ine yazılabilir. Girdi ve çıktı stream'leri aynı dosyayı gösterebilir, ama yazmadan önce okunan dosya kapatılmalıdır.

Hoca `fflush`'ın neden gerektiğine klavyeden bir örnek verdi: `scanf` ile `%d` okunduktan sonra `%c` okunmak istenince, önceki girişte basılan Enter karakteri okunur ve `%c` beklenen değeri alamaz. Bu sorun format dizgesine bir boşluk konarak (`" %c"`) çözülür; stream'i boşaltmak için kullanılan bir `fflush` fonksiyonu da vardır.

> **Ek bilgi (derste anlatılmadı):** C standardında `fflush` yalnız çıktı stream'leri için tanımlıdır; `fflush(stdin)` tanımsız davranıştır ve bazı derleyicilerde (büyük olasılıkla derste kullanılan Windows ortamında da) çalışsa da taşınabilir değildir. Klavyede kalan Enter karakterini atlamak için `scanf(" %c", &c);` biçimi ya da satır sonuna kadar karakter okuyan bir döngü kullanılır.

### 12.3 Dosyayı kapatmak

İş bitince dosya `fclose(fp)` ile kapatılmalıdır. `fclose`, işletim sistemine stream'i sonlandırma sinyali gönderir ve tamponun boşaltılmasını sağlar. Aynı anda açık tutulabilecek dosya sayısı sınırlıdır; ayrıca stream'ler karışırsa var olan dosyanın içeriği bozulabilir. Program beklenmedik biçimde sonlanırsa işletim sistemlerinin çoğu dosyaları kendisi kapatır, ama bu her zaman garanti değildir.

### 12.4 Örnek: karakter karakter kopyalama

Slayttaki ilk örnek, binary modda bir dosyayı karakter karakter başka bir dosyaya kopyalar. İki `FILE *` tanımlanır; ilk dosya okuma için, ikincisi yazma için binary modda açılır. İlk dosya açılamazsa hata verilir; ikincisi açılamazsa ilk dosya da kapatılır ve başarısızlık değeri döndürülür. Ardından dosya sonuna gelinene kadar bir karakter okunup diğer dosyaya yazılır:

```c
while(!feof(fp1))
    putc(getc(fp1), fp2);
fclose(fp1);
fclose(fp2);
```

<!-- BELİRSİZ: Kopyalama fonksiyonunun tam kodu kareye düşmedi; döngü ve hata kontrolü altyazıdaki anlatımdan kuruldu. -->

`feof(fp1)`, `fp1` ile gösterilen dosyanın sonuna gelinip gelinmediğini söyleyen bir fonksiyondur. Hoca, bazı öğrencilerin önce `c=getc(fp1)` ile karakteri bir değişkene alıp sonra `putc(c,fp2)` yazdığını, buna gerek olmadığını söyledi. Bu kodun bir mp3 ya da PDF dosyası gibi herhangi bir dosyayla denenmesini önerdi; program dosya adlarını kullanıcıdan alıp birinci dosyayı ikinciye kopyalar.

Slayt, dosya sonunun nasıl belirleneceği konusunda şunu söylüyordu (ekrandan, 02:35:00): dosya binary modda açıldığı için `getc()`'nin dönüş değeri dosya sonunu test etmek için kullanılamaz. Örneğin

```c
int c;
while ((c = getc( fp1 )) != EOF)
    putc( getc(fp1), fp2 );
```

yazılırsa döngü, okunan karakter `EOF` ile aynı değere sahip olduğu anda biter; bu binary dosyalarda gerçek dosya sonu olmayabilir. Dosya sonuna ulaşıldığını kesin olarak yalnız `feof()` fonksiyonu söyler.

> **Ders sonrası not:** Slayttaki ve dersteki bu ifadeler tam doğru değildir. `getc` `int` döndürür ve `EOF` (genellikle -1) hiçbir byte değeriyle (0-255) çakışmaz; sonuç `int` bir değişkende tutulduğu sürece `while((c = getc(fp1)) != EOF) putc(c, fp2);` binary dosyada da doğru çalışır. Sorun, sonucun `char` bir değişkene atanmasıyla ortaya çıkar. Ayrıca `while(!feof(fp1)) putc(getc(fp1), fp2);` döngüsü dosya sonunu ancak başarısız bir okumadan sonra fark ettiği için hedefe fazladan bir byte (`EOF`'un `unsigned char` karşılığı, 0xFF) yazar: 3 byte'lık bir dosya bu döngüyle 4 byte olarak kopyalandı (`gcc -Wall` ile derlenip denendi). Slayttaki örnek döngüde ise her turda iki kez `getc` çağrıldığı için karakterlerin yarısı atlanır; doğrusu döngü gövdesinde `putc(c, fp2)` yazmaktır.

### 12.5 Makro ve fonksiyon sürümleri

`getc` ve `putc` makro olarak, `fgetc` ve `fputc` fonksiyon olarak tanımlanır; ikisi de aynı işi yapar. Slayta göre makro sürümleri daha hızlıdır, yaklaşık iki kat. Ancak makro çağrılırken argümanlarla parametreler karışabilir; argüman yan etkili ya da operatörlü bir ifade içeriyorsa fonksiyon sürümünü kullanmak her zaman daha güvenlidir.

Hoca bunu bir kare alma makrosuyla gösterdi:

```c
#define SQR(x) x*x
```

`SQR(7)` doğru sonucu verir. Ama `SQR(4+3)` yazılırsa makro metin olarak `4+3*4+3` biçiminde açılır ve sonuç 49 değil $4 + 12 + 3 = 19$ olur. Kod derlenip denendi ve 19 verdi. Makroların ayrıntısı daha sonra işlenecek.

> **Ek bilgi (derste anlatılmadı):** Bu tür hatalardan kaçınmak için makro parametreleri ve makronun tamamı parantez içine alınır: `#define SQR(x) ((x)*(x))`. Bu durumda `SQR(4+3)` 49 verir (derlenip denendi). Ancak `SQR(i++)` gibi yan etkili argümanlarda parantez de yetmez, çünkü argüman iki kez değerlendirilir.

### 12.6 Satır I/O: fgets ve fputs

Slayttaki ikinci kopyalama örneği satır satır kopyalar: `fgets` ile belirli uzunluktaki bir karakter dizisine bir satır okunur, okunan `NULL` değilse `fputs` ile diğer dosyaya yazılır. Önceki örnek bir byte okurken bu örnek küçük bir blok, yani bir string okur.

Slayttaki bilgiler (ekrandan, 02:40:00):

- Prototip: `char *fgets(char *s, int n, FILE *stream);`
- `s`: karakterlerin yazılacağı dizinin ilk elemanının adresi.
- `n`: okunacak en fazla karakter sayısını belirten tamsayı.
- `stream`: okunacak stream.
- `fgets` yeni satıra, dosya sonuna ya da belirtilen en fazla karakter sayısına ulaşınca durur.
- Diziye yazılan son karakterden sonra otomatik olarak boş karakter (`'\0'`) ekler. Bu yüzden `n` parametresi `s` dizisinin boyutundan bir eksik verilir.
- Dosya sonuna ulaşınca `NULL`, aksi halde ilk argümanı (`s`) döndürür.

> **Ders sonrası not:** Slaytta prototip `FILE stream` olarak yazılmıştı; doğrusu `FILE *stream`'dir.

Bir öğrencinin "neden eksi bir?" sorusuna hoca şöyle cevap verdi: dizi 100 elemanlıysa 99 karakter okunur, 100. yer `'\0'` içindir.

`fputs` bunun simetriğidir: bir karakter dizisini verilen stream'e yazar ve boyut almaz. `gets` ise dosyadan değil `stdin`'den, yani komut satırından okur ve sonuna `'\0'` ekler. `fgets` okuduğu satır sonu karakterini (`\n`) de diziye alır; `gets` ise yeni satır karakterini görene kadar okur. Hoca, klavyeden iki kelimeden oluşan, boşluk içeren bir ad okunurken `%s`'in boşlukta durması sorununun çözüm yollarından birinin bu satır okuma fonksiyonları olduğunu söyledi.

### 12.7 Blok I/O: fread ve fwrite

Blok I/O, bir veri türünü, özellikle struct'ları, blok halinde okumak ya da yazmaktır. `fread` dört argüman alır: okunan verinin yazılacağı yeri gösteren bir işaretçi, bir elemanın boyutu, eleman sayısı ve `FILE *`.

İlk argümanın neden `void *` olduğunu hoca öğrencilere sordu; cevabı kendisi verdi: okunacak blok bir karakter, bir `int` dizisi, bir struct dizisi ya da tek bir struct olabilir. Bu genellik için `void *` kullanılır. Boyut için genellikle `sizeof` kullanılır: `sizeof(EMPLOYEE)` ya da `sizeof(int)` kadar oku gibi.

Slayttaki bilgiler (ekrandan, 02:45:00):

- `fread()` gerçekten okunan eleman sayısını döndürür; bir hata olmadıkça ya da dosya sonuna gelinmedikçe bu sayı üçüncü argümanla aynıdır.
- `fwrite()` `fread()`'in aynadaki görüntüsüdür; aynı argümanları alır ama diziden stream'e yazar. Aynı veri iki kez yazılırsa peş peşe iki kayıt yazılmış olur.
- `fread()` ve `fwrite()`'taki blok boyutları aygıt üzerindeki I/O işlemlerinin sayısını etkilemez. Örneğin tampon boyutu 1024 byte, `fread`'de istenen blok 512 byte ise işletim sistemi diskten yine 1024 byte getirir ve bellekte tutar. İlk 512 byte bu `fread`'e verilir; sonraki `fread` çağrısında kalan 512 byte disk erişimi yapılmadan bellekten alınır.

Slayttaki blok okuma örneğinde blok boyutu 512 olarak tanımlanmıştı ve 1 byte'lık bir karakter verisinden 512 adet okunuyordu. Okunan blok `fwrite` ile okunan sayı kadar diğer dosyaya yazılıyor, sonda son kısmın yazılması için ek bir işlem yapılıyor ve dosyalar kapatılıyordu. Okuma ya da yazmada hata olursa hata kodu, yoksa başarı değeri döndürülüyordu.

<!-- BELİRSİZ: Blok kopyalama örneğinin kodu karelere düşmedi; anlatım altyazıdan alındı. -->

## 13. Rastgele erişim: fseek ve ftell

### 13.1 fseek

Rastgele erişim için üç fonksiyon vardır: `fseek`, `ftell` ve `rewind`. `fseek` konum göstergesini istenen yere götürür, `ftell` bulunulan konumun bilgisini verir, `rewind` başa döndürür.

Slayttaki tanım (ekrandan, 02:50:00):

```c
int fseek(FILE *stream, long int offset, int whence);
```

- `stream`: dosya işaretçisi.
- `offset`: karakter cinsinden ölçülen kayma miktarı; negatif olabilir. Binary dosyada byte sayısıdır. Text dosyada ya 0 ya da `ftell()`'in döndürdüğü bir değer olmalıdır.
- `whence`: kaymanın sayılacağı başlangıç noktası. `stdio.h` içinde tanımlı üç seçenek vardır: `SEEK_SET` (dosyanın başı), `SEEK_CUR` (konum göstergesinin o anki yeri), `SEEK_END` (dosya sonu).

Bulunulan yerden +1 verilirse bir sonraki karaktere, -1 verilirse bir öncekine gidilir. Örneğin `fseek(fp, 10, SEEK_SET)` konum göstergesini dosyanın başından 10 karakter ileri götürür. Stream'lerde konumlar 0'dan başladığı için bu, gerçekte 11. karakterin üzerine gelmek demektir.

`fseek` 0 döndürürse istek yerine getirilmiştir; 0'dan farklı bir değer hata demektir. Örneğin `SEEK_SET`'teyken negatif bir offset vermek ya da dosya sonundayken ileri gitmek istemek hatadır. `SEEK_END` genellikle salt okunur dosyalarda kullanılır ve offset sıfır ya da negatif olmalıdır; `SEEK_SET` ile offset sıfır ya da pozitif olmalıdır.

### 13.2 ftell

`ftell`, dosya işaretçisinden başka parametre almayan ve dosyada kalınan yeri söyleyen bir fonksiyondur. Binary stream'lerde baştan itibaren kaçıncı byte'ta olunduğunu döndürür; text stream'lerde döndürdüğü değer gerçekleştirime bağlıdır. Hoca, `SEEK_CUR` yerine `ftell`'in döndürdüğü değerin de kullanılabileceğini söyledi.

### 13.3 Rastgele erişim örneği: indeksle sıralama

Slayttaki örnekte kişi bilgileri (ad, kimlik numarası, doğum tarihi) `PERSONALSTAT` yapısında tutulup bir dosyada saklanıyordu ve kayıtlar adlara göre sıralanmak isteniyordu. Hoca bu örneğin dinamik bellek, dosya işlemleri, işaretçiler ve fonksiyonların bir arada kullanıldığı örneklere geçiş olduğunu söyledi.

Dosya içinde sıralama yapmak çok zordur; veri önce belleğe alınır, bellekte sıralanır ve gerekirse dosyaya geri yazılır. Örnekte kayıtların tamamını fiziksel olarak sıralamak yerine anahtar/indeks çiftleri sıralanır. Slayttaki veriler (ekrandan, 02:55:00):

```text
Jordan, Larry      043-12-7895    5-11-1954
Bird, Michael      012-45-4721    3-24-1952
Erving, Isiah      065-23-5553    11-01-1960
Thomas, Earvin     041-92-1298    1-21-1949
Johnson, Julius    012-22-3365    7-15-1957
```

Anahtar/indeks çiftleri 0 Jordan, 1 Bird, 2 Erving, 3 Thomas, 4 Johnson olur. Bu çiftler ada göre sıralanınca 1 Bird, 2 Erving, 4 Johnson, 0 Jordan, 3 Thomas sırası elde edilir.

Hoca burada bir veritabanı benzetmesi yaptı: veritabanındaki bir varlık (entity), örneğin bir kitap, diskte saklanır; yapısal programlamada struct, nesneye yönelik programlamada class olarak tanımlanır ve RAM'de işlenir. Bir yazılım projesinde ilk aşama verinin tanımlanmasıdır.

Örnekte kayıt sayısı sabit (dört ya da beş) alınmıştı. Hoca, dosyanın başında kayıt sayısını gösteren bir değer (örneğin 100) olsaydı ne yapılacağını sordu: önce bu değer okunur, `malloc` ile bellekte o kadar yer açılır (gerekirse `realloc` kullanılır), sonra kayıtlar satır satır ya da blok blok okunur. Kayıt sayısını koda sabit yazmak statik bir yaklaşımdır; bellekte o kadar ardışık yer bulunmayabilir. Slayttaki örnek yalnız sade kalsın diye dinamik bellek kullanmamıştı.

Kayıtları okuyan fonksiyon şöyledir (ekrandan, 03:00:00):

```c
/* Reads up to max_rec_num records from a file and stores the key field of each record in an index
array. Returns the number of key fields stored. */
int get_records(FILE* data_file, INDEX names_index[], int max_rec_num){
   int offset = 0, counter = 0, k, nm = NAME_LEN;
   char namei[NAME_LEN];

   // get only the name of the 1st PERSON: (the first 19 chars is for name field)
   nm=fread(namei, 1, NAME_LEN, data_file);
   for (k = 0; counter < max_rec_num && nm== NAME_LEN; k++){
      strcpy(names_index[k].key, namei);
      // jump into the beginning of the next person's (next record's) starting point:
      offset += sizeof(PERSONALSTAT);
      fseek(data_file, offset, SEEK_SET);
      counter++;
      // get only the name of the i-th PERSON: (the first 19 chars for each person/record)
      nm=fread(namei, 1, NAME_LEN, data_file);
   }
   return counter;
}
//to be continued in the next slide
```

Fonksiyon her kaydın ilk `NAME_LEN` karakterini (ad alanını) 1 byte'lık elemanlar halinde `fread` ile okur ve indeks dizisine kopyalar. Sonra offset'e bir kaydın boyutunu (`sizeof(PERSONALSTAT)`) ekler ve `fseek` ile dosyanın başından itibaren bir sonraki kaydın başına atlar. Okunan karakter sayısı `NAME_LEN`'den az olduğunda (dosya sonu) ya da en fazla kayıt sayısına ulaşıldığında döngü biter ve okunan kayıt sayısı döndürülür.

Ardından indeks dizisi `strcmp` kullanan bir karşılaştırma fonksiyonuyla `qsort` ile sıralanır; artan ya da azalan sıralama seçilebilir. Son kısımda dosyanın başına dönülüp kayıtlar sıralı indekslere göre blok blok okunarak ekrana yazdırılır. Hoca örneğin sıralanmış veriyi yalnız ekrana yazdırdığını, dosyaya yazmadığını belirtti; bir sonraki sürümde struct sıralama örneğiyle birleştirilip ada ya da soyada göre, fonksiyon işaretçileri de kullanılarak dosyaya yazan hali yapılabilir.

<!-- BELİRSİZ: Karşılaştırma fonksiyonu, qsort çağrısı ve yazdırma kısmının kodu karelere düşmedi. -->

### 13.4 Dosya yönetim fonksiyonları

Son olarak hoca, C içinden dosya silmek, yeniden adlandırmak ve geçici bir binary dosya oluşturmak için dosya yönetim fonksiyonları bulunduğunu, geçici dosyaya ad vermek için bir string üretilebildiğini ve bunların `stdio.h` içinde yer aldığını söyledi. Ayrıntıların daha geniş örneklerle sonraki derste işleneceğini belirtti.

## Örnek Sorular

**1. (ekrandan, 00:50:00 ve 01:05:00)** Menülü bağlı liste programında kayıt ekleme (`addRecord`), id'ye göre silme (`removeRecord`) ve fonksiyon işaretçisiyle yazdırma (`printRecords`) yazınız. `a a a`, `b b b`, `c c c` eklendikten sonra `a` silinir, `d d d` eklenir, `c` silinir, `aa aa aa` eklenir ve `b` silinirse son durumda liste ne olur?

> **Çözüm:** Kod 2-4. bölümlerdedir. Her kayıt başa eklendiği için adımlar şöyledir: c → b → a; `a` silinince c → b; `d` eklenince d → c → b; `c` silinince d → b; `aa` eklenince aa → d → b; `b` silinince aa → d. Son durumda liste `aa aa aa`, `d d d` kayıtlarından oluşur. Program `gcc -Wall` ile derlenip bu girdilerle çalıştırıldı ve aynı sonucu verdi.

**2. (ekrandan, 01:10:00)** Bağlı listede 2 ve 4 numaralı düğümler (n1, n2) için `tmp=n1; n1=n2; n2=tmp;` yazılırsa ne olur? Doğru takas için ek olarak ne tutulmalıdır?

> **Çözüm:** Yalnız bu üç satır bağlantıları koparır; 1'den sonra doğrudan 4'e geçilir ve aradaki düğümler kaybolur. İki düğümün öncülleri (`tmpPrevN1`, `tmpPrevN2`) saklanmalı, takastan sonra öncüllerin `next` alanları ve düğümlerin kendi `next` alanları güncellenmelidir. Alternatif olarak yalnız veri alanları (`next` hariç) kopyalanabilir.

**3. (derste sözlü, 02:01:32 ve 02:08:14)** Dosya nasıl okunur? Dosya nasıl yazılır? Nasıl yazılmasını istemeliyiz?

> **Çözüm:** Dosya yazıldığı gibi okunur, yani yazanın koyduğu formata göre. Dosya istendiği gibi yazılır. Mühendis olarak okumanın, yazmanın ve güncellemenin kolay olduğu, sade, anlaşılır ve gerektiğinde az yer kaplayan, performans ölçütlerini gözeten bir format istenmelidir.

**4. (derste sözlü, 02:43:16)** `fread` fonksiyonunun ilk parametresi neden `void *`'dır?

> **Çözüm:** Okunacak blok bir karakter, bir `int` dizisi, bir struct dizisi ya da tek bir struct olabilir. `void *` her türden adresi kabul ettiği için fonksiyon genel olarak kullanılabilir.

**5. (derste sözlü, 02:37:49)** `#define SQR(x) x*x` tanımlıyken `SQR(4+3)` kaç verir?

> **Çözüm:** Makro `4+3*4+3` olarak açılır; çarpma önce yapılır: $4 + 12 + 3 = 19$. Kod derlenip denendi ve 19 verdi.

**6. (ekrandan, 02:35:00)** Binary modda açılan bir dosyada `while ((c = getc(fp1)) != EOF) putc(getc(fp1), fp2);` döngüsünün sorunu nedir?

> **Çözüm:** Slayta göre binary dosyada okunan bir byte `EOF` ile aynı değere sahip olabileceği için döngü gerçek dosya sonundan önce bitebilir; dosya sonunu kesin olarak `feof()` söyler.

> **Çözüm (derste verilmedi):** `c` `int` olduğu sürece `EOF` (-1) hiçbir byte değeriyle (0-255) çakışmaz; asıl hata gövdede ikinci kez `getc` çağrılmasıdır, bu yüzden her turda bir karakter atlanır. Doğrusu `while ((c = getc(fp1)) != EOF) putc(c, fp2);`'dir. `while(!feof(fp1)) putc(getc(fp1), fp2);` ise sona fazladan bir byte (0xFF) yazar: 3 byte'lık bir dosya 4 byte olarak kopyalandı (derlenip denendi).

## Dersin Toparlaması

Dersin ilk bölümünde bağlı liste, işaretçi, dinamik bellek ve fonksiyon işaretçisi konuları tek bir uygulamada birleştirildi. Liste başı global değil yerel tutuldu ve fonksiyonlarda değiştirilebilmesi için çift işaretçiyle aktarıldı. Düğümler `createNode` ile heap'te oluşturuldu, `addRecord` ile başa eklendi, `removeRecord` ile `current`/`prev` işaretçileri kullanılarak silindi. Yazdırma, aynı gezinme döngüsünü farklı biçimlerle kullanabilmek için fonksiyon işaretçisi alan genel bir fonksiyona bırakıldı. Hata ayıklama sırasında gezinmede ilerletilen işaretçi yerine `head`'in koşulda kullanılmasının neden olduğu çökme bulundu. Bağlı listede düğüm takasının neden zor olduğu ve öncüllerin tutulması gerektiği tartışıldı.

İkinci bölümde dosya işlemlerine giriş yapıldı. Stream kavramı, standart stream'ler, tamponlu I/O, dosyanın header-data-footer yapısı, text ve binary dosya ayrımı, sıralı ve rastgele erişim anlatıldı. Konunun özü "dosya yazıldığı gibi okunur, istendiği gibi yazılır" ilkesiyle verildi. Ardından `fopen` modları, karakter, satır ve blok I/O fonksiyonları, `fclose`, `fseek` ve `ftell` slaytlar üzerinden işlendi ve indeksle sıralama yapan bir rastgele erişim örneği incelendi. Hoca bu fonksiyonların daha geniş örneklerinin ve basit bir dosya tabanlı veritabanı uygulamasının sonraki derste işleneceğini, makroların da ileride anlatılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
