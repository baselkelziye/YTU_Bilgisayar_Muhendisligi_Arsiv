# Ders 25 Genişletilmiş Notu: Uygulama: Bağlı Liste ve Dosya ile Acil Servis Hasta Kuyruğu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Problem: Acil Servis İçin Öncelikli Kuyruk
- 2. Programın Modüler Yapısı ve Veri Yapıları
- 3. Dosya İşlemleri: fread ve fwrite
- 4. Ana Menü
- 5. Hasta Ekleme: insert_patient_to_list
- 6. Hasta Silme: delete_patient
- 7. Baş İşaretçisi Neden Çift İşaretçiyle Gönderilir
- 8. Bağlı Listeler Üzerine Tavsiyeler ve Bir Proje Sorusu
- Örnek Sorular
- Dersin Toparlaması

## 1. Problem: Acil Servis İçin Öncelikli Kuyruk

Bu oturum bir uygulama (lab) oturumudur. Yeni bir konu anlatılmadı; derste görülen struct, bağlı liste, dinamik bellek ve dosya işlemleri, önceden yazılmış bir C programı üzerinden açıklandı. Kod uzun olduğu için sıfırdan yazılmadı, hazır kod satır satır okundu.

Problem metni ekranda şöyleydi (ekrandan, 00:10:00):

> Bir hastanenin acil servisinde kullanılmak üzere bir kuyruk hazırlanacaktır. Kuyruk hastaların sıralarını takip edebilmesi için kullanılacaktır. Hastalar hastaneye kayıt yaptırmak için isim, soy isim, T.C. kimlik numarası ve yaş bilgilerini paylaşmalıdırlar. Hastanelerde vakalar acil vaka ve normal vaka olarak incelenmektedir. Bu doğrultuda aşağıdaki ilkeleri gerçekleyen kuyruk modelini oluşturun.
>
> 1. Yeni bir hasta geldiğinde eğer acil bir vaka değilse doğrudan kuyruğa eklenmelidir. Aşağıdaki örnekte ilk olarak 1'inci hasta gelir, ardından 2, 3, 4 ve 5'inci hastalar gelir.
> 2. Öncelikli bir hasta geldiğinde ise listedeki son öncelikli hastadan sonraki sıraya yerleştirilmelidir. Listede hiç öncelikli hasta olmadığında eklenecek öncelikli hasta listenin başına eklenir. 6'ncı hasta önceliklidir ve listenin başına eklenmiştir. Ardından yeni bir öncelikli vaka geldiğinde kuyruk aşağıdaki gibi olmalıdır.
> 3. Hastalar doktora görünmekten vazgeçtiklerinde kuyruktan çıkarılmalıdır. 3'üncü hasta, hasta ismi kullanılarak kuyruktan çıkartılmıştır.
> 4. Kuyrukta bulunan hastaların bilgileri dosyada tutulmalıdır.
> 5. İstenildiğinde kuyrukta bekleyenlerin bilgileri dosyadan okunmalıdır.

Metindeki renkli kutularla verilen örnek kuyruk durumları (öncelikli hastalar kırmızı kutudaydı) şunlardır:

```text
Normal hastalar 1..5 gelir      : 1 2 3 4 5
Öncelikli 6 gelir               : 6 1 2 3 4 5
Öncelikli 7 gelir               : 6 7 1 2 3 4 5
3 numaralı hasta adıyla silinir : 6 7 1 2 4 5
```

Normal hastalar FIFO (ilk gelen ilk çıkar) ilkesiyle sıranın sonuna eklenir. Öncelikli hasta listenin en başına değil, en son eklenmiş öncelikli hastanın arkasına girer: 7, 6'dan sonra geldiği için 6'nın arkasına eklenir. Böylece öncelikli hastalar kendi aralarında da geliş sırasını korur.

## 2. Programın Modüler Yapısı ve Veri Yapıları

Program üç dosyadan oluşur (ekrandan, 00:15:00):

- `struct_patient.h`: yapı tanımları.
- `file_opr.c`: dosyaya yazma ve dosyadan okuma fonksiyonları.
- `uygulama.c`: `main`, ekleme ve silme fonksiyonları. Diğer iki dosya bu dosyaya `#include` ile eklenir.

> **Hocanın vurgusu:** Bu uygulamanın amacı, görülen struct, dosya işlemleri ve bağlı liste konularını bir arada kullanmak ve aynı zamanda programı modüler hâle getirmektir. Şimdiye kadar birden fazla dosyadan oluşan örnek az yapıldığı için problem özellikle birden fazla modülden oluşacak biçimde seçildi.

İki yapıya ihtiyaç vardır. Birincisi hastanın kendisidir: ad, soyad, ID, yaş ve öncelik. Öncelik alanı `prior`, hasta öncelikliyse 1, değilse 0 değerini alır ve yeni hasta oluşturulurken kullanıcıdan istenir. İkincisi bağlı listenin bir elemanını temsil eden düğümdür: içinde hasta verisini (`data`) ve bir sonraki düğümü gösteren `Patient_Node` türünde bir işaretçi (`next`) bulunur.

Yapıların tam tanımı karelerde görünmedi; alan adları kodun kullanımından okunuyor: `patient.name`, `patient.surname`, `patient.ID` (`%s` ile), `patient.age`, `patient.prior` (`%d` ile), düğümde `data` ve `next`. <!-- BELİRSİZ: struct_patient.h içeriği (dizi boyutları, MAX_SIZE değeri, typedef biçimi) ekranda görünmedi. -->

Yeni hasta `create_new_patient` fonksiyonuyla oluşturulur: bellekte dinamik olarak yeni bir düğüm için yer açılır, kullanıcıdan ad, soyad ve diğer bilgiler alınır ve oluşan düğüm döndürülür. Bu düğüm doğrudan ekleme fonksiyonuna parametre olarak verilir. <!-- BELİRSİZ: create_new_patient fonksiyonunun kodu karelerde görünmedi; anlatım altyazıdan. -->

## 3. Dosya İşlemleri: fread ve fwrite

`file_opr.c` dosyasında iki işlem vardır. Yazma fonksiyonu listenin başını alır ve baştan sona her düğümün hasta verisini dosyaya yazar; ekranda fonksiyonun son satırları görünüyordu (ekrandan, 00:15:00):

```c
        fwrite(&(var_head->data), sizeof(Patient), 1, fs);
        var_head = var_head->next;
    }
    fclose(fs);
    printf("\nFile is updated\n");
}
```

Okuma fonksiyonu ekranda tam görünüyordu (ekrandan, 00:15:00):

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

    /*
     * fread(void * buffer, size_t size, size_t count, FILE * stream)
     * buffer: Pointer to the buffer where data will be stored
     * size: The size of each element to be read in bytes
     * count: Number of elements to be read
     * stream: Pointer to the FILE object from where data is to be read
     */
    while(fread(&patient, sizeof(Patient), 1, fs))
    {
        printf("\nPatient Informations\n");
        printf("Name   : %s \n", patient.name);
        printf("Surname: %s \n", patient.surname);
        printf("ID     : %s \n", patient.ID);
        printf("Age    : %d \n", patient.age);
        printf("Prior  : %d \n", patient.prior);
    }

    fclose(fs);
}
```

`fread` fonksiyonunun dört parametresi açıklandı:

- `buffer`: okunan verinin yerleştirileceği adresi gösteren işaretçi. Burada `&patient` verilir.
- `size`: okunacak bir elemanın bayt cinsinden boyu. Hasta kaydı okunacağı için `sizeof(Patient)`.
- `count`: bir seferde okunacak eleman sayısı. Her seferinde bir hasta okunsun diye 1.
- `stream`: dosya işaretçisi (`fs`).

Okunan veri `patient` değişkenine dolar; struct alanlarına nokta işleciyle (`patient.name`) erişilir. `fwrite` da aynı dört parametreyi alır: yazılacak verinin adresi, boyu, kaç tane yazılacağı ve dosya işaretçisi.

> **Ek bilgi (derste anlatılmadı):** `fread`, başarıyla okuduğu eleman sayısını döndürür. Dosyanın sonuna gelindiğinde 0 döndüğü için `while(fread(...))` döngüsü kayıtlar bitince kendiliğinden durur. Dosya `.txt` uzantılı olsa da `"rb"` kipiyle açılıp ikili (binary) olarak okunuyor; içeriği metin düzenleyicide okunaklı görünmez.

Her işlemden sonra listenin dosyaya yazılması ve listelemenin dosyadan okunarak yapılması, dosya işlemlerini de uygulamaya katmak için seçildi. Program çalışırken liste zaten bellekte tutulduğu için her seferinde dosyadan okumak aslında verimli değildir.

## 4. Ana Menü

`main` fonksiyonu ekranda tam görünüyordu (ekrandan, 00:35:00):

```c
int main() {
    char name[MAX_SIZE];
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

Baş işaretçisi `head` global bir değişken olarak değil, `main` içinde yerel olarak tanımlanır ve fonksiyonlara adresiyle (`&head`) gönderilir. Kullanıcı 1 girerse yeni hasta eklenir, 2 girerse adı sorulan hasta silinir; her iki durumda da liste dosyaya yeniden yazılır (`printListWithAllInformations`). 3 girerse liste dosyadan okunup yazdırılır, 0 girerse döngü biter.

## 5. Hasta Ekleme: insert_patient_to_list

### 5.1 Boş liste

Liste boşken bir baş düğümü yoktur. Bu durumda eklenen hasta öncelikli olsun ya da olmasın listenin başı olur; başka bir kontrol yapılmadan baş yeni düğüme eşitlenir ve fonksiyondan dönülür (ekrandan, 00:20:00):

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
```

`var_head` listeyi dolaşmak için kullanılır. `last_prior` (son öncelikli hasta) başlangıçta başa eşitlenir.

### 5.2 Öncelikli hasta: son öncelikli hastayı bulmak

Yeni hastanın önceliği sıfırdan farklıysa önce listedeki son öncelikli hasta bulunur (ekrandan, 00:20:00):

```c
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
```

Asistan bunu 6, 7, 1, 2, 3, 4, 5 listesi üzerinde anlattı: baştan bakılır, 6 öncelikli olduğu için `last_prior` 6 olur; sonraki 7 de öncelikli olduğu için `last_prior` 7 olur; 1 öncelikli değildir. Önceliksiz bir hastanın arkasında öncelikli hasta bulunamayacağı için (öncelikli hastalar hep önde birikir) sonuç 7'dir ve yeni öncelikli hasta 7'nin arkasına eklenecektir.

> **Ders sonrası not:** Asistan anlatırken ilk önceliksiz hastaya gelince aramadan çıkıldığını söyledi; ekrandaki kodda ise döngü listenin sonuna kadar devam eder ve önceliği sıfırdan farklı her düğümde `last_prior`'ı günceller. Öncelikli hastalar hep listenin önünde durduğu için iki yol aynı sonucu verir; kodda bir `break` olmadığından yalnız gereksiz yere listenin geri kalanı da dolaşılır.

### 5.3 Öncelikli hasta: başa mı, araya mı?

Döngüden sonra `last_prior`'ın hâlâ baş olup olmadığı kontrol edilir. `last_prior` başlangıçta başa eşitlendiği için, listede hiç öncelikli hasta yoksa döngüden sonra da baş olarak kalır. Bu durumda yeni hasta `last_prior`'ın arkasına eklenirse "önceliksiz, öncelikli, önceliksiz..." gibi yanlış bir sıra oluşur. Bunu önlemek için başın önceliğine bakılır (ekrandan, 00:20:00 ve 00:25:00):

```c
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
```

Üç durum vardır:

- `last_prior` baş ve başın önceliği yok: listede hiç öncelikli hasta yoktur. Eski baş `temp`'te tutulur, yeni hasta baş olur, yeni hastanın `next`'i eski başı gösterir.
- `last_prior` baş ve başın önceliği var: listede tek öncelikli hasta baştadır. Yeni hasta onun arkasına eklenir.
- `last_prior` baş değil: yeni hasta `last_prior`'ın arkasına eklenir.

Araya ekleme her seferinde aynı üç satırla yapılır: `last_prior`'ın gösterdiği sonraki düğüm `temp`'te saklanır, `last_prior`'ın `next`'i yeni hastaya bağlanır, yeni hastanın `next`'i de `temp`'teki düğüme bağlanır. Asistan, son `else` dalı olmasaydı `last_prior`'ın baş olmadığı durumda ekleme yapılamayacağını, iki dalda aynı kodun bulunduğunu ama kontrollerin farklı olduğunu belirtti.

### 5.4 Önceliksiz hasta: sona ekleme

Önceliği olmayan hasta FIFO kuralına göre listenin sonuna eklenir. `next`'i NULL olan düğüm son düğümdür; ona ulaşana kadar ilerlenir (ekrandan, 00:25:00):

```c
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

Ekleme kurallarının ekrandaki örneği verdiğini doğrulamak için eksik kısımlar (yapı tanımı ve düğüm oluşturma) tamamlanarak ekrandaki ekleme fonksiyonu `gcc -Wall` ile derlendi ve çalıştırıldı (ajan tarafından, derste çalıştırılmadı). 1-5 normal, sonra 6 ve 7 öncelikli eklenince sıra `6 7 1 2 3 4 5` çıktı; tek öncelikli hasta baştayken ikinci öncelikli hasta da doğru biçimde onun arkasına girdi.

## 6. Hasta Silme: delete_patient

Problemde hastaların adlarıyla silineceği söylendiği için silme fonksiyonu hastanın adını ve listenin başını alır (ekrandan, 00:40:00):

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

Akış şöyledir:

- İlk döngü listeyi baştan sona dolaşır. `strcmp` iki string eşitse 0 döndürür; eşleşen düğüm `patient` işaretçisinde tutulur. Döngü bitince `patient`, aranan addaki hastanın düğümünü gösterir.
- Bulunan hasta baştaysa yeni baş, başın `next`'i olur.
- Baş değilse önce `patient`'ın NULL olup olmadığına bakılır; listede öyle bir ad yoksa mesaj yazılıp dönülür.
- Varsa ikinci bir döngüyle `var_head->next != patient` olduğu sürece ilerlenir. Döngü durduğunda `var_head`, silinecek düğümün bir öncesidir.
- Önceki düğümün `next`'i, silinecek düğümün `next`'ine bağlanır: `var_head->next = var_head->next->next`. Silinen düğüm aradan çıkmış olur ve `free(patient)` ile belleği serbest bırakılır.

Asistan bağlamayı çizerek gösterdi: normalde önceki düğüm silinecek düğümü gösterir; önceki düğümün işaretçisi bir sonrakini değil ikinci sonrakini gösterecek biçimde değiştirilince ortadaki düğüm listeden çıkar ve liste oradan devam eder.

```text
Önce : [önceki] --> [silinecek] --> [sonraki]
Sonra: [önceki] -----------------> [sonraki]      (silinecek: free)
```

Asistan adla silmenin çok kullanışlı olmadığını da söyledi: aynı adda birden fazla hasta olabilir, bu yüzden silme T.C. kimlik numarasıyla yapılsa daha doğru olurdu.

> **Ders sonrası not:** Ekrandaki kodda üç nokta dikkat çekiyor (derste konuşulmadı, kod üzerinden görülüyor): (1) Silinen hasta baştaysa baş ilerletiliyor ama `free` çağrılmıyor, yani o düğümün belleği serbest bırakılmıyor. (2) Liste boşken `patient` ve `*head` ikisi de NULL olduğundan `patient == (*head)` koşulu doğru çıkar ve `(*head)->next` erişimi NULL üzerinden yapılır; program çöker. NULL kontrolü baş kontrolünden önce yapılmalıdır. (3) İlk döngüde `break` olmadığı için aynı adlı birden fazla hasta varsa sonuncusu silinir.

## 7. Baş İşaretçisi Neden Çift İşaretçiyle Gönderilir

Oturumun sonunda hoca, ekleme ve silme fonksiyonlarına başın neden adresiyle (`Patient_Node **head`) gönderildiğini sordu. Bir öğrenci bunun `return` ile ilgisi olup olmadığını, fonksiyonun `void` olduğunu söyledi. Hoca soruyu "delete patient yapınca başın değişme olasılığı var mı?" diye yönlendirdi ve cevabı verdi:

Evet, baş silinebilir ya da başın yerine başka bir düğüm gelebilir (eklemede öncelikli hasta başa geçebilir). Başı güncellemenin iki yolu vardır:

- Fonksiyon yeni başı `Patient_Node *` türünde `return` eder ve çağıran bunu kendi değişkenine atar.
- Başın adresi, yani çift işaretçi gönderilir ve fonksiyon `*head`'i doğrudan değiştirir.

Baş tek işaretçiyle gönderilirse fonksiyon içinde yapılan değişiklik yalnız yerel kopyayı değiştirir; çağırandaki baş güncellenmez. Bu durum birkaç ders önce tamsayı değişkenler üzerinde, sonra struct ve bağlı liste üzerinde örneklerle gösterilmişti.

> **Hocanın vurgusu:** Bu dersin gayelerinden biri bağlantıların, düğümlerin ve işaretçilerin mantığını öğrenmektir. C'de bu öğrenilmezse sonraki dönemin veri yapıları dersinde çok sıkıntı çekilir.

## 8. Bağlı Listeler Üzerine Tavsiyeler ve Bir Proje Sorusu

Asistan, bağlı listelerde kafa karışıklığı olabileceğini ve mantığı çizerek oturtmanın işe yaradığını söyledi. Hoca da bunu destekledi: bağlı liste ve ikili ağaç gibi yapılarda önce iş kâğıt üzerinde çizilmeli, bağlar ona göre düşünülmelidir. Algoritma kafada oturunca kodlama kolaydır: `while` döngüsüyle gidilecek yere gidilir, öncesi ve sonrası bağlanır. Her şey işaretçilerle yürür; ileride nesnelerin interneti (IoT) ve gömülü sistemler gibi alanlarda çalışılacaksa bu bilgiler yine gerekecektir.

**Soru:** Bir öğrenci, derste verilen ve öğrenci, öğretim üyesi, ders gibi birden fazla dosyadan oluşan projede bu kayıtlar arasında bağlantı kurup bağlı listeye dizmenin mümkün olup olmadığını sordu.

**Cevap:** Dosyanın tamamı okunup struct'larda tutulabilir, ama iki dosya arasındaki ilişkiyi ayrıca tutmaya gerek yoktur. Dört dosya varsa dört struct olur ve aralarında doğrudan bağlantı kurmak gerekmez; çünkü öğrenci ID'si ile ders ID'si eşleştirilmektedir (çoka çok ilişki). Ekleme ve silme yapılırken olmayan bir dersin ya da olmayan bir öğrencinin eklenmemesine dikkat etmek yeterlidir. Temel işlemler dosya üzerinde arama yapıp ekle, sil, güncelle ve listeledir. Bağlantı ancak listelemede işe yarayabilir: bir dersin öğrencilerini listelerken o derse ait bütün öğrenciler bilgileriyle dosyadan çekilir ve struct'lar birleştirilerek listelenir. Struct'lar arasında ilişki kurmak nesneye yönelik dillerdeki kadar kolay değildir ve fazladan yük getirir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): Bir hastanenin acil servisi için bir kuyruk hazırlayın. Hastaların ad, soyad, T.C. kimlik numarası ve yaşı tutulacak; vakalar acil ve normal olarak ayrılacak. Normal hasta kuyruğun sonuna eklenecek; öncelikli hasta listedeki son öncelikli hastadan sonraki sıraya, hiç öncelikli hasta yoksa listenin başına eklenecek; vazgeçen hasta adıyla kuyruktan çıkarılacak; kuyruk bilgileri dosyada tutulacak ve istenince dosyadan okunacak. (Tam metin Bölüm 1'de.)

> **Çözüm:** Derste hazır çözüm anlatıldı: bağlı liste düğümü olarak `Patient_Node`, ekleme için `insert_patient_to_list` (Bölüm 5), silme için `delete_patient` (Bölüm 6), dosya için `fwrite` ile yazma ve `read_File` ile okuma (Bölüm 3), menü için `main` (Bölüm 4). Örnek giriş sırası 1, 2, 3, 4, 5 (normal), 6, 7 (öncelikli) için kuyruk `6 7 1 2 3 4 5`, ardından 3 silinince `6 7 1 2 4 5` olur.

**Soru 2** (derste sözlü, 00:32:02): Silme fonksiyonunda önce hasta bulunuyor, sonra ikinci bir döngüyle onun öncesi bulunuyor. Bunu başka türlü nasıl yapabiliriz, iki döngüye gerek var mı?

> **Cevap (derste verildi):** Arama yapılırken geçerli düğümle birlikte bir önceki düğüm de bir işaretçide saklanırsa, aranan düğüm bulunduğu anda öncesi de elde olur ve ikinci döngüye gerek kalmaz.

> **Çözüm (derste verilmedi):** Bu fikrin kodu derste yazılmadı; aşağıdaki fonksiyon ajan tarafından yazıldı, `gcc -Wall` ile derlenip denendi (`6 7 1 2 3 4 5` listesinden 3, ardından baştaki 6 silindi, olmayan bir ad için mesaj verildi). Boş liste ve baş silme durumlarını da karşılar ve ilk eşleşen hastayı siler.

```c
void delete_patient(char *name, Patient_Node **head){
    Patient_Node *prev = NULL, *cur = *head;
    while(cur != NULL && strcmp(cur->data.name, name) != 0){
        prev = cur;          // bir önceki düğüm saklanır
        cur = cur->next;
    }
    if(cur == NULL){
        printf("\nCould not find the element with %s", name);
        return;
    }
    if(prev == NULL)         // silinen baş
        *head = cur->next;
    else
        prev->next = cur->next;
    free(cur);
}
```

**Soru 3** (derste sözlü, 00:34:21): Ekleme ve silme fonksiyonlarına başı (`head`) neden adresiyle, çift işaretçi olarak gönderiyoruz?

> **Cevap (derste verildi):** Bu işlemlerde baş değişebilir (baştaki hasta silinebilir ya da öncelikli hasta başa geçebilir). Değişikliğin `main`'deki başa yansıması için ya yeni baş `return` edilmeli ya da başın adresi gönderilip `*head` değiştirilmelidir. Tek işaretçiyle gönderilen baş fonksiyon içinde değişse bile çağırandaki değer güncellenmez.

## Dersin Toparlaması

Bu uygulama oturumunda acil servis için öncelikli bir hasta kuyruğu, üç dosyaya bölünmüş bir C programı üzerinden incelendi. Hasta bilgileri bir struct'ta, kuyruk elemanları bu struct'ı ve `next` işaretçisini içeren düğümlerde tutuldu. Normal hasta listenin sonuna, öncelikli hasta son öncelikli hastanın arkasına ya da başa eklendi; bunun için son öncelikli düğümü bulan bir döngü ve başın önceliğine bakan bir kontrol kullanıldı. Silmede önceki düğümün `next`'i silinen düğümün sonrakine bağlandı ve bellek `free` ile serbest bırakıldı. Kuyruk her değişiklikte `fwrite` ile ikili dosyaya yazıldı, istenince `fread` döngüsüyle okundu.

Oturumun sonunda iki önemli fikir öne çıktı: önceki düğümü arama sırasında saklayarak tek döngüyle silme yapılabileceği ve başı değiştirebilen fonksiyonlara başın çift işaretçiyle gönderilmesi ya da yeni başın döndürülmesi gerektiği. Hoca, işaretçi ve düğüm mantığının sonraki dönemin veri yapıları dersinin temeli olduğunu, bu yapıların önce kâğıt üzerinde çizilerek kurulması gerektiğini vurguladı. Sonraki derste kısa bir tekrar ve thread konusunun anlatılacağı söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
