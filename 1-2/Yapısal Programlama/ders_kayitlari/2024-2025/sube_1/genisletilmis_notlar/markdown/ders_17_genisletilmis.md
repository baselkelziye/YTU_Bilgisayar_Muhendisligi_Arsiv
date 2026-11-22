# Ders 17 Genişletilmiş Notu: Dosya İşlemleri Uygulaması: Dosyadan Bağlı Listeye Okuma, Sıralama ve Dosyaya Yazma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin amacı ve dosya işlemlerine kısa bakış
- 2. Soru 1: personel kayıtlarını okuma, sıralama ve yazma
- 3. Fonksiyon işaretçisiyle özyinelemeli seçmeli sıralama
- 4. Soru 1: dosyaya yazma ve main
- 5. Soru 2: uçuş bilgileri, sıralı ekleme ve pist dosyaları
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin amacı ve dosya işlemlerine kısa bakış

Bu ders bir laboratuvar uygulamasıdır ve konusu dosya yönetimidir: bir metin dosyasından okuma, okunan veriyi işleme ve sonucu yeni dosyalara yazma. Dosya konusunun teorik anlatımı daha önceki bir oturumda yapılmıştı; bu oturumda dosya işaretçisi (`FILE *`), dosya erişim modları ve dosyadan okuma/yazma fonksiyonları iki soru üzerinden uygulamalı olarak gösterildi. Birinci soru Dev-C++ ortamında baştan sona canlı yazıldı; ikinci soru, süre kısıtı nedeniyle önceden hazırlanmış çözüm kodu üzerinden fonksiyon fonksiyon anlatıldı.

İki sorunun ortak kalıbı şudur:

- Metin dosyasındaki her satır bir `struct` düğümüne dönüştürülür.
- Düğümler tek yönlü bağlı listede (linked list) tutulur.
- Liste bir anahtara (ID ya da uçuş kodu) göre sıralanır.
- Liste ekrana yazılır ve istenen biçimde yeni dosyalara kaydedilir.

Derste geçen dosya işlemleri temel bilgileri:

- `fopen(dosya_adi, "r")` dosyayı okuma (read) modunda açar. Yazmak için `"w"` (write) modu kullanılır.
- `"w"` modunda açılan dosya yoksa sıfırdan oluşturulur; varsa içi boşaltılır ve baştan yazılır.
- `fopen` dosyayı açamazsa (dosya yoksa ya da erişim izni yoksa) `NULL` döner. İkinci sorunun çözümünde bu durumda hata mesajı yazdırılır.
- İş bitince dosya `fclose(fp)` ile kapatılır.
- Okunacak dosya, programın çalıştığı klasörde, yani kaynak kodun bulunduğu klasörde olmalıdır. Derste ilk çalıştırma bu yüzden başarısız oldu: kod yeni açılan bir klasördeydi ve `dataset.txt` oraya konmamıştı. Kod, dosyanın bulunduğu klasörden açılınca program çalıştı.

## 2. Soru 1: personel kayıtlarını okuma, sıralama ve yazma

### 2.1 Sorunun tanımı

Birinci soruda bir `dataset.txt` dosyası vardır. Dosyanın her satırında bir personelin ID'si, adı (name) ve departmanı (department) virgülle ayrılmış olarak bulunur. İstenenler, derste sözlü anlatıldığı biçimiyle şunlardır:

- Dosya okunur ve satırlar önce olduğu gibi ekrana yazılır.
- Satırlar virgüllerden ayrıştırılır (parse) ve "ID", "Name", "Department" etiketleriyle yeniden ekrana yazılır.
- Her satır bir `struct` yapısına dönüştürülür ve bu yapılar bağlı listede saklanır.
- Liste ID'ye göre azalan ve artan sırada sıralanır ve her sıralama ayrı bir metin dosyasına yazılır.

<!-- BELİRSİZ: Soru 1'in metni ve dataset.txt içeriği 00:06-00:09 arasında ekranda gösterildi, ancak bu aralığa ait kare yok. Soru metni altyazıdan kuruldu; dosyadaki gerçek kayıtlar bilinmiyor. -->

### 2.2 Kütüphaneler ve düğüm yapısı

Kod `stdio.h` ve `stdlib.h` ile başlar. `stdlib.h` dinamik bellek ayırma (`malloc`) ve `atoi` için gereklidir. Bunlara `string.h` eklenir, çünkü satırları ayrıştırmak ve metin kopyalamak için `strtok`, `strcpy`, `strlen` kullanılacaktır.

Bağlı listenin düğümü şu yapıdır (ekrandan, 00:15:00):

```c
typedef struct data{
    int ID;
    char Name[50];
    char Department[20];
    struct data *next;
}data;
```

`next` alanı bir sonraki düğümü gösterir. `main` içinde listenin ilk elemanını tutacak `data* head;` tanımlanır.

### 2.3 Dosyayı okuma: File_Read

Okuma fonksiyonu iki parametre alır: dosyanın adı ve satır içindeki parçaları (token) ayıran karakteri tutan `delimiter`. Bu soruda ayırıcı virgüldür. Fonksiyon dosyayı okuma modunda açar, 255 karakterlik bir tampon (`buf`) dizisi tanımlar, listenin başı için `malloc` ile yer ayırır ve şimdiki ve önceki düğümü tutacak `curr_data` ve `prev_data` işaretçilerini tanımlar.

İlk satır ayrı ele alınır, çünkü dosyanın boş olup olmadığına bakılmalıdır. `fgets(buf, 255, fp)` bir satırı tampona okur; dosya boşsa ya da sona gelinmişse `NULL` döner. Dosya boş değilse satır ekrana yazılır ve `Split_Data` ile ilk düğüme ayrıştırılır; boşsa fonksiyon `NULL` döner. Ardından kalan satırlar bir `while` döngüsünde okunur. Her satır için yeni düğüme yer ayrılır, önceki düğümün `next`'i yeni düğüme bağlanır, satır yeni düğüme ayrıştırılır ve yeni düğüm "önceki düğüm" olur. Döngü bitince son düğümün `next`'i `NULL` yapılır ki listenin sonu belli olsun; dosya kapatılır ve `head` döndürülür.

Ekranda yazılan fonksiyon şöyledir (ekrandan, 00:40:00):

```c
data* File_Read(char *File_Name, char delimiter[2]){
    FILE *fp=fopen(File_Name,"r");
    char buf[255];
    data* head=(data*)malloc(sizeof(data));

    data* curr_data;
    data* prev_data;
    if(fgets(buf,255,fp)!=NULL){
        printf("%s",buf);
        Split_Data(head, buf, delimiter);

    }else{
        return NULL;
    }

    prev_data=head;
    while(fgets(buf,255,fp)!=NULL){
        printf("%s",buf);
        curr_data=(data*)malloc(sizeof(data));
        prev_data->next=curr_data;
        Split_Data(curr_data, buf, delimiter);
        prev_data=curr_data;

    }
prev_data->next=NULL;
fclose(fp);
return head;
}
```

> **Ek bilgi (derste anlatılmadı):** Bu sürüm `fopen`'ın `NULL` dönüp dönmediğini denetlemez; dosya bulunamazsa `fgets(buf, 255, NULL)` çağrısı programı çökertebilir. Boş dosya durumunda da `head` için ayrılan bellek serbest bırakılmadan ve dosya kapatılmadan `NULL` döner. İkinci sorunun çözümündeki gibi `if (fp == NULL)` denetimi eklemek güvenlidir.

### 2.4 Satırı parçalama: Split_Data

Satırı virgüllerden ayırmak için ayrı bir fonksiyon yazılır. Parametreleri doldurulacak düğüm (`holder`), satırı tutan tampon ve ayırıcıdır. Ayrıştırılan parçaları göstermek için `char *token` tanımlanır (ekrandan, 00:25:00):

```c
void Split_Data(data* holder, char buff[255], char delimiter[2]){

char *token;
token=strtok(buff,delimiter);
holder->ID=atoi(token);

token=strtok(NULL,delimiter);
strcpy(holder->Name,token);

token=strtok(NULL,delimiter);
token[strlen(token)-1]='\0';
strcpy(holder->Department,token);
}
```

Adım adım:

- `strtok(buff, delimiter)` satırdaki ilk virgülden önceki kısmı, yani ID'yi verir. Dosyadan okunan her şey metin olduğu için ID de metin olarak gelir; `atoi` ile tamsayıya çevrilip düğümün `ID` alanına yazılır. Yazarken bunun tersi, tamsayıyı metne çeviren `itoa` kullanılacaktır.
- İkinci parça (ad) için `strtok` yine çağrılır, ama ilk argüman olarak tampon değil `NULL` verilir. Tampon yalnız ilk parça için yazılır; `NULL`, aynı metnin kaldığı yerden devam edilmesini sağlar. Parça `strcpy` ile düğümün `Name` alanına kopyalanır, çünkü karakter dizileri `=` ile atanamaz.
- Üçüncü parça (departman) satırın son parçasıdır ve sonunda satır sonu karakteri (`\n`) vardır. Bu karakter okunmasın diye `token[strlen(token)-1] = '\0';` ile silinir, sonra parça `Department` alanına kopyalanır.

> **Ders sonrası not:** `token[strlen(token)-1] = '\0';` satırı, son parçanın sonunda gerçekten `\n` olduğunu varsayar. Dosyanın son satırı satır sonu karakteri olmadan bitiyorsa bu satır departman adının son harfini siler (örneğin "HR" "H" olur); Windows biçimli dosyalarda da `\r` kalabilir. Ajanın denemesinde `token[strcspn(token, "\r\n")] = '\0';` kullanıldı; bu ifade satır sonu yoksa hiçbir şey silmez.

Derste kod yazılırken düzenleyici yanlışlıkla üzerine yazma (overwrite) moduna geçti; öğrencilerden biri bunun Insert tuşuyla düzeltildiğini söyledi.

### 2.5 Listeyi yazdırma: Print_List

Liste, `head` `NULL` olana kadar, yani listenin sonuna gelinene kadar dolaşılır; her düğüm etiketlerle yazılır ve bir sonraki düğüme geçmek için `head = head->next` yapılır (ekrandan, 00:40:00):

```c
void Print_List(data* head){
    while(head!=NULL){
        printf("ID: %d, Name:%s, Department:%s\n",head->ID,head->Name,head->Department);
        head=head->next;
    }
}
```

Burada `head` parametresi bir kopya olduğu için fonksiyon içinde ilerletilmesi `main`'deki listenin başını değiştirmez.

## 3. Fonksiyon işaretçisiyle özyinelemeli seçmeli sıralama

### 3.1 Sıralama ölçütünü parametre yapmak

Liste ID'ye göre hem büyükten küçüğe hem küçükten büyüğe sıralanacaktır. Bunun için tek bir `Sort_Data` fonksiyonu yazılır ve hangi yönde sıralanacağı bir fonksiyon işaretçisiyle verilir. İşaretçinin gösterdiği fonksiyon iki tamsayı alır (birincisi ve ikincisi, `first` ve `second`) ve istenen sıraya göre doğru/yanlış döndürür (ekrandan, 01:00:00):

```c
int Sort_Ascending(int first, int second){
    return first<second;
}

int Sort_Descending(int first, int second){
    return first>second;
}
```

`Sort_Data`'nın imzası `data* Sort_Data(data* head, int (*Sort_Condition)(int,int))` biçimindedir (ekrandan, 00:45:00). Çağrıda fonksiyonun adı verilir: `Sort_Data(head, Sort_Descending)`.

### 3.2 Algoritmanın mantığı

Kullanılan yöntem seçmeli sıralamadır (selection sort). Derste anlatıldığı haliyle: ilk değer başlangıçta "max" kabul edilir ve sırayla diğerleriyle karşılaştırılır; hangisi büyükse o başa alınır, sonra aynı iş kalan elemanlar için yapılır. Dizide yer değiştirmek kolaydır, ama bağlı listede düğümler birbirine bağlı olduğu için uç düğümü başa almak iki iş gerektirir: düğümü bulunduğu yerden çıkarmak ve çıkarırken önceki ve sonraki düğümü birbirine bağlamak. Bunun için üç işaretçi kullanılır:

- `prev`: dolaşırken bir önceki düğüm.
- `to_move`: ölçüte göre uç değere sahip düğümün bir önceki düğümü.
- `tmp`: listede gezinen işaretçi.

Fonksiyonun adımları:

- Liste boşsa ya da tek elemanlıysa sıralamaya gerek yoktur; `head` döner.
- `min_max = head->ID` ile başlanır. `tmp` ile kalan liste dolaşılır; `Sort_Condition(tmp->ID, min_max)` doğruysa `min_max` güncellenir ve `to_move = prev` yapılır.
- Dolaşma bittiğinde `to_move` hâlâ `NULL` ise uç değer baştaki düğümdür. Bu durumda baş yerinde kalır, `head->next = Sort_Data(head->next, Sort_Condition)` ile kalan liste özyinelemeli olarak sıralanır ve `head` döner. Fonksiyonun kendini çağırması derste özyineleme (recursion) olarak vurgulandı.
- Uç değer başka bir düğümdeyse o düğüm listeden çıkarılır: öncülünün `next`'i, çıkarılan düğümün `next`'ine bağlanır. Böylece aradaki düğümün bağlantısı kalkar ama önceki ve sonraki düğüm birbirine bağlanmış olur. Sonra kalan liste özyinelemeli sıralanıp çıkarılan düğümün arkasına eklenir ve çıkarılan düğüm yeni baş olarak döner.

> **Hocanın vurgusu:** Kod uzun olduğu için sıralama kısmında nerede kalındığını takip etmek önemlidir; öğrencilerden kodu birlikte izlemeleri ve gördükleri yanlışları söylemeleri istendi.

### 3.3 Ekranda yazılan sürüm ve hataları

Derste canlı yazılan sürüm şudur (ekrandan, 01:10:00):

```c
data* Sort_Data(data* head, int(*Sort_Condition)(int,int)){

    if(head==NULL|| head->next==NULL)
    return head;

    int min_max=head->ID;
    data *prev=head;
    data *to_move=NULL;
    data *tmp=head->next;
    while(tmp!=NULL){
        if(Sort_Condition(tmp->ID,max)){
            min_max=tmp->ID;
            to_move=prev;
        }
        prev=tmp;
        tmp=tmp->next;
        if(to_move==NULL){
            head->next=Sort_Data(head->next,Sort_Condition);
            return head;
        }
        prev=to_move;
        prev->next=prev->next->next;

        to_move->next=Sort_Data(head,Sort_Condition);
        return to_move;

    }

}
```

> **Ders sonrası not:** Bu sürüm bu haliyle derlenmez ve mantık olarak da hatalıdır: (1) karşılaştırmada tanımsız `max` kullanılmıştır, `min_max` olmalıdır; (2) `to_move` denetimi ve sonrası `while` döngüsünün içinde kalmıştır, bu yüzden liste yalnız ilk karşılaştırmadan sonra karar verilir, oysa bu kısım döngüden sonra gelmelidir; (3) `to_move` uç düğümün öncülüdür, ama son iki satır çıkarılan düğüm yerine öncülü başa koyar. Ayrıca fonksiyonun sonunda `return` yoktur. Derste program bu sürümle değil, önceden hazırlanmış çözüm dosyasıyla çalıştırıldı (çıktı ekranda doğruydu); hazır dosyadaki `Sort_Data` gövdesi karelerde görünmedi.

Aynı mantığın düzeltilmiş hali aşağıdadır. Bu sürüm derste yazılmadı; ajan tarafından düzeltildi ve test edildi (tam program Bölüm 4.3'te):

```c
data* Sort_Data(data* head, int (*Sort_Condition)(int,int)){
    int min_max;
    data *prev, *to_move, *tmp, *node;
    if(head==NULL || head->next==NULL)
        return head;
    min_max=head->ID;
    prev=head;
    to_move=NULL;
    tmp=head->next;
    while(tmp!=NULL){
        if(Sort_Condition(tmp->ID,min_max)){
            min_max=tmp->ID;
            to_move=prev;          /* uç düğümün öncülü */
        }
        prev=tmp;
        tmp=tmp->next;
    }
    if(to_move==NULL){             /* uç değer zaten başta */
        head->next=Sort_Data(head->next,Sort_Condition);
        return head;
    }
    node=to_move->next;            /* uç düğüm */
    to_move->next=node->next;      /* listeden çıkar, komşuları bağla */
    node->next=Sort_Data(head,Sort_Condition);
    return node;
}
```

`Sort_Descending` ile her adımda en büyük ID başa alınır ve azalan sıra çıkar; `Sort_Ascending` ile en küçük ID başa alınır ve artan sıra çıkar.

> **Ek bilgi (derste anlatılmadı):** Bu yöntemde her özyinelemeli çağrı kalan listeyi baştan tarar, bu yüzden toplam karşılaştırma sayısı $n$ elemanlı liste için $\frac{n(n-1)}{2}$ mertebesindedir ($O(n^2)$). Özyineleme derinliği de $n$ olduğu için çok uzun listelerde yığın (stack) taşması riski vardır.

## 4. Soru 1: dosyaya yazma ve main

### 4.1 File_Write

Sıralanan liste ayrı ayrı dosyalara yazılır: büyükten küçüğe olan liste bir dosyaya, küçükten büyüğe olan başka bir dosyaya. Yazma fonksiyonu listenin başını, dosya adını ve ayırıcı karakteri alır; ayırıcı burada, dosyaya virgülle ayrılmış biçimde yazmak için kullanılır. Dosya bu kez `"w"` modunda açılır. ID tamsayı olduğu için önce `itoa` ile metne çevrilir; ad ve departman zaten metin olduğu için doğrudan `fputs` ile yazılır. Departmandan sonra virgül değil satır sonu konur (ekrandan, 01:05:00):

```c
void File_Write(data* head, char *File_Name, char delimiter){
    FILE *fp=fopen(File_Name,"w");
    char tmp[20];
    while(head!=NULL){
        itoa(head->ID,tmp,10);
        fputs(tmp,fp);
        fputc(delimiter,fp);
        fputs(head->Name,fp);
        fputc(delimiter,fp);
        fputs(head->Department,fp);
        fputc('\n',fp);
        head=head->next;
    }
}
```

<!-- BELİRSİZ: Karede satır sonu karakteri yazılırken görülüyor (fputc('') aşamasında); '\n' altyazıdan ("ters slaş n") tamamlandı. Döngüden sonraki fclose satırı karede görünmüyor. -->

`fputs` bir metni, `fputc` tek bir karakteri dosyaya yazar. Aynı iş `fprintf` ile de yapılabilir; derste bunun yalnızca farklı bir fonksiyon kullanmak olacağı söylendi.

> **Ders sonrası not:** `itoa` C standardında yoktur; Windows'taki MinGW (Dev-C++) derleyicisinde bulunur, ama Linux'taki gcc/glibc ortamında yoktur ve kod derlenmez. Taşınabilir karşılığı `sprintf(tmp, "%d", head->ID);` ya da doğrudan `fprintf(fp, "%d", head->ID);` kullanmaktır. Ajanın Linux'ta yaptığı denemede `sprintf` kullanıldı.

### 4.2 main

`main` önce dosyayı okur ve listeyi yazdırır, sonra azalan sırada sıralayıp yazdırır ve dosyaya kaydeder (ekrandan, 01:10:00):

```c
int main() {

    data* head;

    head=File_Read("Dataset.txt",",\0");
    Print_List(head);
    head=Sort_Data(head, Sort_Descending);
    printf("Descending\n");
    Print_List(head);
    File_Write(head, "New_dataset_descending.txt", ',');
```

Ardından aynı işlem artan sıra için yapılır: liste `Sort_Ascending` ile sıralanır, yazdırılır ve ayrı bir dosyaya kaydedilir. Okuma fonksiyonuna ayırıcı `","` metni olarak, yazma fonksiyonuna `','` karakteri olarak verilir; çünkü `strtok` ayırıcıları bir metin olarak bekler, `fputc` ise tek karakter yazar.

Program çalıştırıldığında önce dosyadaki satırları olduğu gibi, sonra etiketli halleriyle yazdı; ardından ID'ye göre büyükten küçüğe ve küçükten büyüğe sıralanmış listeleri yazdı. Çalıştırma sonunda klasörde iki yeni metin dosyası oluştu; artan sıralı dosya açıldığında kayıtların ID'ye göre küçükten büyüğe yazıldığı görüldü.

### 4.3 Test edilen tam program

Aşağıdaki program derste yazılan kodun düzeltilmiş halidir (`Sort_Data` düzeltildi, `itoa` yerine `sprintf`, satır sonu silme `strcspn` ile, `fopen` denetimi eklendi). Derste bu haliyle yazılmadı; ajan tarafından `gcc -Wall` ile uyarısız derlendi ve uydurma beş satırlık bir `Dataset.txt` ile (ID'ler sırasıyla 3, 1, 5, 2, 4) çalıştırıldı. Azalan dosyada ID sırası 5, 4, 3, 2, 1; artan dosyada 1, 2, 3, 4, 5 çıktı.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int ID;
    char Name[50];
    char Department[20];
    struct data *next;
}data;

void Split_Data(data* holder, char buff[255], char delimiter[2]){
    char *token;
    token=strtok(buff,delimiter);
    holder->ID=atoi(token);
    token=strtok(NULL,delimiter);
    strcpy(holder->Name,token);
    token=strtok(NULL,delimiter);
    token[strcspn(token,"\r\n")]='\0';
    strcpy(holder->Department,token);
}

data* File_Read(char *File_Name, char delimiter[2]){
    FILE *fp=fopen(File_Name,"r");
    char buf[255];
    data *head, *curr_data, *prev_data;
    if(fp==NULL){ printf("Dosya acilamadi\n"); return NULL; }
    if(fgets(buf,255,fp)!=NULL){
        printf("%s",buf);
        head=(data*)malloc(sizeof(data));
        Split_Data(head,buf,delimiter);
    }else{
        fclose(fp);
        return NULL;
    }
    prev_data=head;
    while(fgets(buf,255,fp)!=NULL){
        printf("%s",buf);
        curr_data=(data*)malloc(sizeof(data));
        prev_data->next=curr_data;
        Split_Data(curr_data,buf,delimiter);
        prev_data=curr_data;
    }
    prev_data->next=NULL;
    fclose(fp);
    return head;
}

void File_Write(data* head, char *File_Name, char delimiter){
    FILE *fp=fopen(File_Name,"w");
    char tmp[20];
    while(head!=NULL){
        sprintf(tmp,"%d",head->ID);
        fputs(tmp,fp);
        fputc(delimiter,fp);
        fputs(head->Name,fp);
        fputc(delimiter,fp);
        fputs(head->Department,fp);
        fputc('\n',fp);
        head=head->next;
    }
    fclose(fp);
}

void Print_List(data* head){
    while(head!=NULL){
        printf("ID: %d, Name:%s, Department:%s\n",head->ID,head->Name,head->Department);
        head=head->next;
    }
}

int Sort_Ascending(int first, int second){ return first<second; }
int Sort_Descending(int first, int second){ return first>second; }

data* Sort_Data(data* head, int (*Sort_Condition)(int,int)){
    int min_max;
    data *prev, *to_move, *tmp, *node;
    if(head==NULL || head->next==NULL)
        return head;
    min_max=head->ID;
    prev=head;
    to_move=NULL;
    tmp=head->next;
    while(tmp!=NULL){
        if(Sort_Condition(tmp->ID,min_max)){
            min_max=tmp->ID;
            to_move=prev;
        }
        prev=tmp;
        tmp=tmp->next;
    }
    if(to_move==NULL){
        head->next=Sort_Data(head->next,Sort_Condition);
        return head;
    }
    node=to_move->next;
    to_move->next=node->next;
    node->next=Sort_Data(head,Sort_Condition);
    return node;
}

int main(){
    data* head;
    head=File_Read("Dataset.txt",",");
    Print_List(head);
    head=Sort_Data(head,Sort_Descending);
    printf("Descending\n");
    Print_List(head);
    File_Write(head,"New_dataset_descending.txt",',');
    head=Sort_Data(head,Sort_Ascending);
    printf("Ascending\n");
    Print_List(head);
    File_Write(head,"New_dataset_ascending.txt",',');
    return 0;
}
```

## 5. Soru 2: uçuş bilgileri, sıralı ekleme ve pist dosyaları

### 5.1 Sorunun tanımı

İkinci sorunun metni ekranda gösterildi (ekrandan, 01:20:00 ve 01:40:00). Verilen metin dosyasının (`ucusbilgi.txt`) her satırı bir havaalanından ya da havaalanına yapılacak bir uçuşa ait şu bilgileri sırasıyla içerir: benzersiz bir uçuş kodu (4 haneli sayı), kalkış şehri, varış şehri, pistte bulunacağı saat, iç ya da dış hat olma bilgisi (0: iç hatlar, 1: dış hatlar) ve kullanacağı pist numarası (pozitif tam sayı). Her pist için birer metin dosyasına o pisti kullanacak seferlerin uçuş bilgilerini yazan bir C programı istenir. Program şunları yapmalıdır:

- Uçuşları ifade eden bir `struct` yapısı kurulur.
- Dosyadaki uçuşlar uçuş koduna göre küçükten büyüğe sıralı olarak bir bağlı listeye kaydedilir.
- Sıralı liste ekranda gösterilir.
- Her pist için pistin adını taşıyan birer dosya oluşturulur (örneğin `pist1.txt`) ve o pisti kullanacak uçuşların bilgileri bu dosyaya kaydedilir.

Örnek girdi dosyası (ekrandan, 01:40:00):

```text
3001 ISTANBUL ANKARA 13:00 0 1
2013 ISTANBUL LONDON 12:00 1 8
1015 LONDON ISTANBUL 20:00 1 2
1012 SIVAS ISTANBUL 14:00 0 1
```

Bu dosyada üç pist vardır: 1, 2 ve 8. Dolayısıyla üç ayrı dosya oluşacak ve her birinde yalnız o pistteki uçuşlar yer alacaktır.

### 5.2 Düğüm yapısı ve createFlight

Uçuş bilgilerini tutan yapı şöyledir (ekrandan, 01:55:00):

```c
typedef struct Flight {
    int flightCode;
    char departureCity[50];
    char arrivalCity[50];
    char time[6]; // hh:mm
    int internalExternal;
    int runwayNumber;
    struct Flight *next;
} Flight;
```

`time` alanı "hh:mm" biçimindeki saat için 5 karakter ve sondaki `'\0'` için 1 karakter, toplam 6 karakterdir.

`createFlight` tek bir uçuşun, yani tek bir düğümün oluşturulmasından sorumludur. Üç iş yapar: yeni düğüm için bellek ayırır, düğümün bütün alanlarını parametrelerle doldurur ve düğümü listeye eklenmeye hazır hale getirir (ekrandan, 01:45:00):

```c
Flight* createFlight(int flightCode, char* departureCity, char* arrivalCity, char* time, int internalExternal, int runwayNumber) {
    Flight* newFlight = (Flight*)malloc(sizeof(Flight));
    newFlight->flightCode = flightCode;
    strcpy(newFlight->departureCity, departureCity);
    strcpy(newFlight->arrivalCity, arrivalCity);
    strcpy(newFlight->time, time);
    newFlight->internalExternal = internalExternal;
    newFlight->runwayNumber = runwayNumber;
    newFlight->next = NULL;
    return newFlight;
}
```

Tamsayı alanları `=` ile atanabilir; karakter dizisi alanları ise `strcpy` ile kopyalanır. Yeni düğümün `next`'i `NULL` yapılır, çünkü düğüm henüz hiçbir listeye bağlanmamıştır; `NULL` "şimdilik devamı yok" anlamındadır. Fonksiyon bellekteki yeni düğümün adresini döndürür.

### 5.3 Sıralı ekleme: insertFlight

Uçuşlar dosyadan okundukça listeye sıralı olarak yerleştirilir; böylece sonradan ayrıca sıralamaya gerek kalmaz. Fonksiyon listenin başını değiştirebileceği için başı gösteren işaretçinin adresini (`Flight** head`) alır (ekrandan, 01:50:00):

```c
void insertFlight(Flight** head, Flight* newFlight) {
    if (*head == NULL || (*head)->flightCode > newFlight->flightCode) {
        newFlight->next = *head;
        *head = newFlight;
    } else {
        Flight* current = *head;
        while (current->next != NULL && current->next->flightCode < newFlight->flightCode) {
            current = current->next;
        }
        newFlight->next = current->next;
        current->next = newFlight;
    }
}
```

İki durum vardır:

- Başa ekleme: liste boşsa ya da mevcut ilk düğümün kodu yeni düğümün kodundan büyükse yeni düğüm başa konur. Yeni düğümün `next`'i eski ilk düğümü gösterir ve liste başı artık yeni düğümdür.
- Araya ya da sona ekleme: aksi halde `current` işaretçisi baştan başlatılır. `current` son düğüm değilse ve bir sonraki düğümün kodu yeni kodu geçmiyorsa ilerlenir; döngü bu iki şartı birlikte denetler. Döngü bitince önce yeni düğüm eski sonraki düğüme bağlanır, sonra `current` yeni düğümü gösterir. Bağlantı kopmadan önce yeni düğümün eski sonraki düğüme bağlanması önemlidir; sıra ters olursa listenin geri kalanı kaybolur.

Kodun içindeki açıklama satırlarında bir örnek izlendi (ekrandan, 01:45:00). Liste 1001 → 2005 → 3050 ve eklenecek düğümün kodu 2500 olsun:

- `current = 1001`: `current->next` 2005'tir ve 2005 < 2500 olduğu için ilerlenir.
- `current = 2005`: `current->next` 3050'dir ve 3050 < 2500 olmadığı için döngü biter.
- Sonuç: `current` 2005'tedir ve yeni düğüm (2500) 3050'nin önüne eklenir; liste 1001 → 2005 → 2500 → 3050 olur.

### 5.4 Listeyi ekrana yazma: displayFlights

Orijinal başlangıç işaretçisi bozulmasın diye geçici bir `current` işaretçisi tanımlanır ve baştan başlatılır. `current` `NULL` olmadığı sürece, yani listenin sonuna gelinmediği sürece her düğümdeki uçuş bir satıra yazılır ve `current` bir sonraki düğüme ilerletilir (ekrandan, 01:50:00):

```c
void displayFlights(Flight* head) {
    Flight* current = head;
    while (current != NULL) {
        printf("%d %s %s %s %d %d\n", current->flightCode, current->departureCity, current->arrivalCity, current->time, current->internalExternal, current->runwayNumber);
        current = current->next;
    }
}
```

### 5.5 Pist dosyalarına yazma: writeFlightsToFiles

Bu fonksiyon listedeki her uçuşu kullandığı pist numarasına göre ilgili dosyaya yazar. `FILE* files[10] = { NULL };` ile 0'dan 9'a kadar 10 farklı pist için bir dosya işaretçisi dizisi tanımlanır; başlangıçta hepsi `NULL`'dır, yani hiçbir dosya açılmamıştır. Bu dizi sayesinde aynı pisti kullanan uçuşlar aynı açık dosyaya yazılır. Ekranda görünen başlangıç kısmı (ekrandan, 01:50:00):

```c
void writeFlightsToFiles(Flight* head) {
    Flight* current = head;
    int i;


    FILE* files[10] = { NULL };

    while (current != NULL) {

        char filename[20];
        snprintf(filename, sizeof(filename), "pist%d.txt", current->runwayNumber);
```

Döngünün geri kalanı altyazıdaki anlatıma göre şöyle işler: o pist numarasına ait dosya henüz açılmamışsa (dizideki eleman `NULL` ise) dosya `"w"` modunda açılır; dosya yoksa oluşturulur, varsa içeriği silinip baştan yazılır. Dosya açılamazsa hata mesajı verilir. Uçuş bilgileri `fprintf` ile, girdi dosyasındaki biçimde, her satıra bir uçuş olacak şekilde yazılır ve listede bir sonraki uçuşa geçilir. Sonunda açık dosyalar kapatılır.

<!-- BELİRSİZ: writeFlightsToFiles'ın snprintf satırından sonraki kısmı, okuma fonksiyonu ve main hiçbir karede görünmedi. Bölüm 5.7'deki bu kısımlar anlatıma göre ajan tarafından yeniden kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** `files` dizisi 10 elemanlı olduğu için bu çözüm yalnız 0-9 arasındaki pist numaralarında güvenlidir. Soru pist numarasını yalnız "pozitif tam sayı" diye tanımlar; 10 ve üzeri bir pist numarası dizinin dışına yazmaya yol açar. Daha sağlam bir çözümde pist numarası önceden denetlenir ya da dizi gerektiği kadar büyütülür.

### 5.6 Dosyadan okuma ve main

Okuma fonksiyonu dosyayı `"r"` modunda açar. Dosya açılmazsa, örneğin erişim izni yoksa, hata mesajı yazar; açılırsa geçici değişkenler tanımlanır. Dosyanın sonuna (End of File) kadar bir döngüde her satır okunur ve parçalar ilgili değişkenlere atanır. Bu dosyada alanlar virgülle değil boşlukla ayrıldığı için ayrıca bir `strtok` ayrıştırmasına gerek yoktur; okuma işlemi parçaları otomatik olarak ayırır. Okuma başarılıysa okunan verilerle `createFlight` çağrılıp yeni düğüm oluşturulur ve `insertFlight` ile listeye sıralı olarak eklenir.

`main` içinde listenin başı `Flight* flightList = NULL;` olarak tanımlanır. Birinci soruda baş böyle tanımlanmamıştı; burada `NULL` ile başlatmanın sebebi, başlangıçta listenin boş olduğunu belirtmektir. Dosyadan okundukça ve her yeni uçuş eklendikçe bu işaretçi listenin ilk düğümünün adresini gösterir. Derste bunun, bağlı listelerde `main`'de her zaman yapılan şey olduğu söylendi.

Program çalıştırıldığında uçuşlar kod, kalkış yeri, varış yeri, saat, iç/dış hat ve pist bilgisiyle sıralı olarak ekrana yazıldı ve klasörde üç yeni dosya (`pist1.txt`, `pist2.txt`, `pist8.txt`) oluştu; `pist1.txt` açıldığında yalnız pist numarası 1 olan uçuşların yazıldığı görüldü.

### 5.7 Test edilen tam program

Aşağıdaki programda `createFlight`, `insertFlight`, `displayFlights` ve `writeFlightsToFiles`'ın başı ekrandaki koddur. `writeFlightsToFiles`'ın geri kalanı, `readFlightsFromFile` ve `main` derste ekranda görünmediği için ajan tarafından anlatıma göre yazıldı (okuma için `fscanf` seçildi). Program `gcc -Wall` ile uyarısız derlendi ve sorudaki örnek girdiyle çalıştırıldı; çıktı ve oluşan üç dosya sorudaki beklenen çıktıyla birebir aynıdır.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Flight {
    int flightCode;
    char departureCity[50];
    char arrivalCity[50];
    char time[6]; // hh:mm
    int internalExternal;
    int runwayNumber;
    struct Flight *next;
} Flight;

Flight* createFlight(int flightCode, char* departureCity, char* arrivalCity, char* time, int internalExternal, int runwayNumber) {
    Flight* newFlight = (Flight*)malloc(sizeof(Flight));
    newFlight->flightCode = flightCode;
    strcpy(newFlight->departureCity, departureCity);
    strcpy(newFlight->arrivalCity, arrivalCity);
    strcpy(newFlight->time, time);
    newFlight->internalExternal = internalExternal;
    newFlight->runwayNumber = runwayNumber;
    newFlight->next = NULL;
    return newFlight;
}

void insertFlight(Flight** head, Flight* newFlight) {
    if (*head == NULL || (*head)->flightCode > newFlight->flightCode) {
        newFlight->next = *head;
        *head = newFlight;
    } else {
        Flight* current = *head;
        while (current->next != NULL && current->next->flightCode < newFlight->flightCode) {
            current = current->next;
        }
        newFlight->next = current->next;
        current->next = newFlight;
    }
}

void displayFlights(Flight* head) {
    Flight* current = head;
    while (current != NULL) {
        printf("%d %s %s %s %d %d\n", current->flightCode, current->departureCity, current->arrivalCity, current->time, current->internalExternal, current->runwayNumber);
        current = current->next;
    }
}

void writeFlightsToFiles(Flight* head) {
    Flight* current = head;
    int i;
    FILE* files[10] = { NULL };
    while (current != NULL) {
        char filename[20];
        snprintf(filename, sizeof(filename), "pist%d.txt", current->runwayNumber);
        /* buradan sonrası ajan tarafından yazıldı */
        if (files[current->runwayNumber] == NULL) {
            files[current->runwayNumber] = fopen(filename, "w");
            if (files[current->runwayNumber] == NULL) {
                printf("Dosya acilamadi: %s\n", filename);
                return;
            }
        }
        fprintf(files[current->runwayNumber], "%d %s %s %s %d %d\n", current->flightCode, current->departureCity, current->arrivalCity, current->time, current->internalExternal, current->runwayNumber);
        current = current->next;
    }
    for (i = 0; i < 10; i++)
        if (files[i] != NULL)
            fclose(files[i]);
}

/* ajan tarafından yazıldı */
void readFlightsFromFile(char* fileName, Flight** head) {
    FILE* fp = fopen(fileName, "r");
    int code, ie, rn;
    char dep[50], arr[50], t[6];
    if (fp == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }
    while (fscanf(fp, "%d %49s %49s %5s %d %d", &code, dep, arr, t, &ie, &rn) == 6) {
        insertFlight(head, createFlight(code, dep, arr, t, ie, rn));
    }
    fclose(fp);
}

/* ajan tarafından yazıldı */
int main() {
    Flight* flightList = NULL;
    readFlightsFromFile("ucusbilgi.txt", &flightList);
    printf("Ekrana yazdirilan (Linked List):\n");
    displayFlights(flightList);
    writeFlightsToFiles(flightList);
    return 0;
}
```

Örnek girdiyle elde edilen ekran çıktısı:

```text
Ekrana yazdirilan (Linked List):
1012 SIVAS ISTANBUL 14:00 0 1
1015 LONDON ISTANBUL 20:00 1 2
2013 ISTANBUL LONDON 12:00 1 8
3001 ISTANBUL ANKARA 13:00 0 1
```

## Örnek Sorular

### Soru 1 (derste sözlü, 00:07:58)

Bir `dataset.txt` dosyasının her satırında bir personelin ID, ad ve departman bilgisi virgülle ayrılmış olarak bulunmaktadır. Dosyayı okuyup satırları ekrana yazdıran, satırları virgüllerden ayrıştırarak "ID", "Name" ve "Department" etiketleriyle yeniden yazdıran, her satırı bir `struct` yapısına dönüştürüp bağlı listede saklayan, listeyi ID'ye göre azalan ve artan sırada sıralayıp her sıralamayı ayrı bir metin dosyasına yazan C programını yazınız.

<!-- BELİRSİZ: Soru metni ekranda gösterildi ama kare yok; metin altyazıdan kuruldu, örnek dosya içeriği bilinmiyor. -->

> **Çözüm:** Derste canlı yazıldı; Bölüm 2-4'te adım adım anlatıldı. Ekranda yazılan `Sort_Data`'daki hatalar ve test edilmiş düzeltilmiş tam program Bölüm 3.3 ve 4.3'tedir.

### Soru 2 (ekrandan, 01:20:00)

Verilen text dosyasının her satırı havaalanından veya havaalanına yapılacak olan bir uçuşa ait şu bilgileri sırasıyla içermektedir: benzersiz bir uçuş kodu (4 haneli sayı), kalkış şehri, varış şehri, pistte bulunacağı saat, iç ya da dış hat olma bilgisi (0: İç hatlar, 1: Dış Hatlar) ve kullanacağı pist numarası (pozitif tam sayı).

Havaalanındaki pistlerin kullanım durumuna ilişkin her pist için birer text dosyasına pistin kullanılacağı seferlerin uçuş bilgilerini yazan bir algoritmayı C dilinde gerçekleyiniz. Programınız aşağıdaki özellikleri bulundurmalıdır:

1. Uçuşları ifade eden bir `struct` yapısı kurunuz.
2. Dosyadaki uçuşları uçuş koduna göre küçükten büyüğe sıralı olarak bir linkli listeye kaydediniz.
3. Sıralı listeyi ekranda gösteriniz.
4. Her bir pist için pistin adını taşıyan birer dosya oluşturarak (Örn: `pist1.txt`) pisti kullanacak uçuşların bilgilerini bu dosyaya kaydediniz.

Örnek girdi dosyası içeriği:

```text
3001 ISTANBUL ANKARA 13:00 0 1
2013 ISTANBUL LONDON 12:00 1 8
1015 LONDON ISTANBUL 20:00 1 2
1012 SIVAS ISTANBUL 14:00 0 1
```

Beklenen çıktı (ekrandan, 01:40:00):

```text
Ekrana yazdirilan (Linked List):
1012 SIVAS ISTANBUL 14:00 0 1
1015 LONDON ISTANBUL 20:00 1 2
2013 ISTANBUL LONDON 12:00 1 8
3001 ISTANBUL ANKARA 13:00 0 1

pist1.txt:
1012 SIVAS ISTANBUL 14:00 0 1
3001 ISTANBUL ANKARA 13:00 0 1

pist2.txt:
1015 LONDON ISTANBUL 20:00 1 2

pist8.txt:
2013 ISTANBUL LONDON 12:00 1 8
```

> **Çözüm:** Derste hazır çözüm kodu üzerinden anlatıldı (Bölüm 5). Ekranda görünmeyen okuma fonksiyonu, `main` ve yazma fonksiyonunun sonu ajan tarafından tamamlandı; tam program (Bölüm 5.7) derlenip örnek girdiyle denendi ve beklenen çıktıyı birebir verdi.

## Dersin Toparlaması

Bu uygulamada dosya işlemleri, bağlı liste ve fonksiyonlarla ilgili birçok konu tek bir problem kalıbında birleşti. Birinci soruda dosya `fopen` ile okuma modunda açıldı, satırlar `fgets` ile okundu, `strtok` ile virgüllerden ayrıştırıldı, `atoi` ile metinden tamsayıya çevrildi ve `malloc` ile oluşturulan düğümlerle bağlı liste kuruldu. Liste, sıralama yönünü bir fonksiyon işaretçisiyle alan özyinelemeli bir seçmeli sıralamayla azalan ve artan sırada düzenlendi ve `fputs`/`fputc` ile virgülle ayrılmış biçimde yeni dosyalara yazıldı.

İkinci soruda aynı kalıp farklı bir yolla kuruldu: sıralama ayrı bir adım olarak değil, her düğüm listeye eklenirken doğru yere yerleştirilerek yapıldı. Listenin başı değişebildiği için ekleme fonksiyonuna başı gösteren işaretçinin adresi verildi; çıktılar, pist numarasına göre bir `FILE*` dizisinde tutulan ayrı dosyalara `fprintf` ile yazıldı. Kodları kendi başına yeniden yazmak, bu adımların oturması için önerildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
