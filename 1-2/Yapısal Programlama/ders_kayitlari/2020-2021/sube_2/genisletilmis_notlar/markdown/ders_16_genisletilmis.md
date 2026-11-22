# Ders 16 Genişletilmiş Notu: Soru Çözümü: Struct Dizileriyle Sıralama, İşaretçi Döndüren Fonksiyonlar ve Üç Boyutlu Diziler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun yapısı
- 2. Öğrenci listesi sorusu: struct tanımı ve dinamik dizi
- 3. Listeyi ekrana yazdırmak
- 4. Nota göre sıralama ve struct takası
- 5. Ada göre sıralama ve strcmp
- 6. Programın çalıştırılması ve çok ölçütlü sıralama
- 7. CAR sorusu: diziyi fonksiyonda açıp işaretçi döndürmek
- 8. Karmaşık sayı dizisini yazdırmanın yolları
- 9. Üç boyutlu diziler ve işaretçi aritmetiği
- 10. Struct konusunun kısa tekrarı
- Örnek Sorular

## 1. Oturumun yapısı

Bu kayıt kısa bir soru çözümü oturumudur. Önceki derslerde işlenen struct, dinamik bellek ve işaretçi konuları, bir öğrenci listesi sorusunun Dev-C++ ortamında baştan kodlanmasıyla pekiştirildi. Ardından hazırlanmış çözüm dosyaları üzerinden bir araç (CAR) sorusu ve karmaşık sayı dizisi örneği anlatıldı. Bir öğrencinin önceki haftalarda sorduğu üç boyutlu dizilerde işaretçi aritmetiği sorusu canlı kodlamayla cevaplandı. Oturum struct konusunun kısa bir tekrarıyla ve sonraki konuların (union, bit alanları, özyineleme, fonksiyon işaretçileri, dosya işlemleri) sıralamasıyla bitti.

## 2. Öğrenci listesi sorusu: struct tanımı ve dinamik dizi

### 2.1 Sorunun özü

Soruda her öğrencinin yaş, ID, not ve ad bilgisi vardır. Bu bilgiler dinamik olarak açılan bir dizide saklanacak, sonra fonksiyonlarla nota göre sıralama, ada göre sıralama ve ekrana yazdırma yapılacaktır. Öğrenci sayısı $N$ kullanıcıdan alınır ve veriler `main` içinde okunur. Fonksiyonların çağrıldığı kısım soruda hazır verilmişti; fonksiyonların gövdesini ve dönüş türünü öğrencinin yazması bekleniyordu.

### 2.2 Struct tanımı ve etiket adı

Önce `stdio.h`, `stdlib.h` ve string işlemleri için `string.h` eklendi. Struct şöyle tanımlandı (ekrandan, 00:15:00):

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct STD{
 int id, age, grade;
 char name[20];
}STUDENT;
```

Burada `struct` kelimesinden sonraki `STD` etiketinin yazılması zorunlu değildir. Fark şudur: etiket yazılırsa aşağıda hem `struct STD a;` biçiminde `struct` kelimesiyle başlayan bir değişken hem de `STUDENT b;` biçiminde `typedef` adıyla bir değişken, ayrıca `STUDENT *p;` gibi bir işaretçi tanımlanabilir. Etiket yazılmazsa `struct` kelimesiyle değişken tanımlanamaz, yalnız `STUDENT` adı kullanılır. Daha kısa olduğu için genelde `STUDENT` adı tercih edilir.

### 2.3 calloc ile dizi açmak

Dinamik bir dizi gerektiği için `STUDENT *std;` işaretçisi tanımlandı ve `calloc` kullanıldı (ekrandan, 00:20:00):

```c
int main(){
    int N, i;
    STUDENT *std;
    printf(" N degeri"); scanf("%d",&N);

    std = (STUDENT*)calloc(N,sizeof(STUDENT));
    if(std!=NULL){
        ...
    }
    else{
        printf("Error");
        return 0;
    }
}
```

`calloc`'un iki parametresi vardır: birincisi eleman sayısı, ikincisi her elemanın kaç bayttan oluştuğu. `malloc`'tan işlev olarak farkı, açtığı alanı sıfırlamasıdır. Dönen `void *` adres `(STUDENT*)` ile struct işaretçisine dönüştürülür. Bellek açılabildiyse (`std != NULL`) veriler okunur, açılamadıysa hata mesajı verilir.

### 2.4 Struct dizisi elemanlarına veri okumak

Bir `for` döngüsüyle her öğrencinin bilgileri okunur. Son hali şöyledir (ekrandan, 00:45:00):

```c
for(i=0;i<N;i++){
    printf("%d. Ogrenci id",i); scanf("%d",&std[i].id);
    printf("%d. Ogrenci adi",i); scanf("%s",std[i].name);
    printf("%d. Ogrenci notu",i); scanf("%d",&std[i].grade);
    printf("%d. Ogrenci yasi",i); scanf("%d",&std[i].age);
}
```

Dinamik bellekte duran bir struct dizisinin elemanına birkaç yolla erişilebilir, çünkü işin içinde işaretçi vardır. En rahat yol normal dizilerdeki indeks operatörüdür: `std[i]` dizinin $i$. elemanına gider, `.id` bu elemanın `id` alanını bulur, baştaki `&` da bu alanın adresini verir. İşaretçi aritmetiğiyle de yapılabilir ama ifade biraz karışır.

`std[i]`'nin adresi hesaplanabilir, ama bu elemanın altındaki `id`, `name`, `grade` alanları farklı adreslerdedir. Bu yüzden tam sayı alanlarında, normal değişkenlerde olduğu gibi `&` kullanılır. `name` alanı ise bir karakter dizisidir; dizinin adı zaten adresi gösterdiği için önüne `&` yazılmaz.

İlk yazımda iki hata oldu ve derste düzeltildi. Bir öğrenci `str[i]` yazıldığını, doğrusunun `std[i]` olduğunu fark etti (ekrandan, 00:20:00). Ad okunurken format `%d` yazılmıştı; ad bir string olduğu için `%s` olmalıdır.

### 2.5 main'in geri kalanı

Fonksiyon çağrıları sorudan aynen alındı (ekrandan, 00:45:00):

```c
liste_yaz(std, N);
nota_gore_sirala(std, N);
liste_yaz(std, N);
ada_gore_sirala(std, N);
liste_yaz(std, N);
free(std);
```

Önce liste yazılır, nota göre sıralanır, tekrar yazılır, ada göre sıralanır, tekrar yazılır ve dizi `free` ile bırakılır.

## 3. Listeyi ekrana yazdırmak

### 3.1 Dönüş türü seçimi

Soruda fonksiyon başlıklarında dönüş türü yerine boşluk bırakılmıştı. Listeyi ekrana yazdıran bir fonksiyondan genelde bir geri dönüş değeri beklenmez, bu yüzden `void` yazılabilir. Yazdırmanın başarılı olup olmadığını bildirmek isteyen bir kontrol değişkeni döndürebilir; o zaman `int` yazmak da makul bir gerekçeyle kabul edilir. Karşılaştırma için şu örnek verildi: iki kenarı alınan bir dikdörtgenin alanını hesaplayan fonksiyonun bir dönüş değeri vardır, ama listeyi yazan fonksiyonun yoktur. Bu tür çıkarımları yapmak bekleniyordu.

### 3.2 liste_yaz

Fonksiyon dizinin adresini ve eleman sayısını alır, bir başlık satırı yazar ve her öğrenciyi sekmeyle (`\t`) ayrılmış sütunlarla basar. Ekranda başlık satırı `printf("ID\tAD\tNOT\tYAŞ\n");` biçimindedir (ekrandan, 00:30:00). Satırlar için `%d\t%s\t%d\t%d\n` biçiminde bir format kullanıldı. İlk denemede başlık satırının sonundaki `;` ve döngü değişkeni `i`'nin tanımı eksikti; derleyici hatalarıyla ve öğrencilerin uyarılarıyla düzeltildi.

```c
void liste_yaz(STUDENT* std, int n){
    int i;
    printf("\nID\tAD\tNOT\tYAS\n");
    for(i=0;i<n;i++){
        printf("%d\t%s\t%d\t%d\n",std[i].id,std[i].name,std[i].grade,std[i].age);
    }
}
```

<!-- BELİRSİZ: Döngü içindeki printf satırının ekrandaki son hali karelerde görünmüyor; format altyazıdan (00:25:10 - 00:26:13), alan sırası tablodaki başlık sırasından kuruldu. -->

### 3.3 Prototipler

Fonksiyonlar `main`'in altında yazıldığı için derleyici prototipleri istedi. Prototipler struct tanımından sonra yazılmalıdır, çünkü içlerinde `STUDENT` türü geçer. Prototipte parametre adları yazılmak zorunda değildir, tür yazılması yeterlidir. İleride fonksiyonlar ayrı bir başlık (header) dosyasına taşındığında bu biçim daha da önemli olacaktır.

## 4. Nota göre sıralama ve struct takası

### 4.1 Neden void?

Sıralama fonksiyonu da `void`'dir. Gönderilen dizinin kendisi (adresi) fonksiyona gittiği için sıralama orijinal veriyi değiştirir; yeni bir dizi döndürmeye gerek yoktur. Değişkenlerin ömrü (duration) açısından iki yol vardır: ya gelen orijinal dizi değiştirilir ya da fonksiyonda dinamik bellekle yeni bir dizi açılıp adresi döndürülür. Fonksiyon bitince yerel değişkenler yok olacağı için yerel bir dizi döndürülemez.

### 4.2 Struct ile takas

Herhangi bir sıralama algoritması (seçmeli sıralama, kabarcık sıralaması, eklemeli sıralama) kullanılabilir. Tam sayı dizisinde takas için `int temp` kullanılırken burada `STUDENT tmp` kullanılır. `tmp = std[j];` ataması struct'ın bütün alanlarını bir seferde kopyalar.

Kodun ekrandaki hali (ekrandan, 00:35:00):

```c
STUDENT tmp;
for(i=0;i<n-1;i++){
    for(j=0;j<n-1;j++){
        if(std[j].grade<std[j+1].grade){
            tmp=std[j];
            std[j]=std[j+1];
            std[j+1]=tmp;
        }
    }
}
```

Koşul `std[j].grade < std[j+1].grade` olduğu için sıralama büyükten küçüğe (azalan) yapılır. İç döngü sınırı için derste `n-1-i` düşünüldü, ama `n-1` bırakıldı. İki biçim de doğru sonuç verir; `n-1-i` her geçişte sona yerleşmiş elemanları yeniden karşılaştırmaz.

> **Ders sonrası not:** Ekranda fonksiyon parametresi `int N` olarak tanımlanmış, döngülerde ise küçük `n` kullanılmış. C büyük-küçük harf duyarlı olduğu için bu hâliyle derlenmez; parametre ve döngüde aynı ad kullanılmalıdır. Nottaki tam programda `n` kullanıldı.

### 4.3 Struct takası her zaman güvenli mi?

Bu yöntemin her zaman güvenli olmadığı vurgulandı. Bu struct'ta alanlar sabit boyutludur: üç `int` $3 \times 4 = 12$ bayt, `char name[20]` 20 bayt, toplam 32 bayt. Bellekte ne kadar yer kaplayacağı önceden bellidir. Struct içinde bir `char *` tutulsaydı, o işaretçinin kaç karakter göstereceği belli olmazdı. Bu tür struct'ları kopyalamak için `strcpy`'ye benzer mantıkta çalışan `memcpy` fonksiyonu kullanılabilir; bu konuya daha sonra gelinecek. Bu sorudaki gibi sabit alanlı struct'lar için düz atama yeterlidir.

> **Ders sonrası not:** Hoca, içinde `char *` olan bir struct'ın "ne kadar yer kaplayacağının belli olmadığını" söyledi. Struct'ın boyutu işaretçi alanı olsa da derleme anında sabittir. Asıl sorun, atamanın (ve `memcpy`'nin) gösterilen karakterleri değil yalnız adresi kopyalamasıdır; iki struct aynı karakter dizisini göstermeye başlar (sığ kopya).

## 5. Ada göre sıralama ve strcmp

### 5.1 İki string doğrudan karşılaştırılamaz

Ada göre sıralama nota göre sıralamayla aynı yapıdadır; yalnız karşılaştırma değişir. İki `name` alanı `<` ya da `>` ile doğrudan karşılaştırılamaz. Karşılaştırma karakter karakter çıkarma yapılarak yapılır; Assembly'deki `cmp` komutunun çıkarma mantığıyla çalışmasına benzer. Bunun için `strcmp` kullanılır. Ekrandaki ilk yazım şöyledir (ekrandan, 00:40:00):

```c
if(strcmp(std[j].name,std[j+1].name)==1){
    tmp=std[j];
    std[j]=std[j+1];
    std[j+1]=tmp;
}
```

### 5.2 strcmp'nin dönüş değeri

Derste önce `strcmp`'nin üç değer döndürdüğü söylendi: eşitse `0`, değilse `1` ya da `-1`. Bir öğrenci, farkın 1'den büyük olabileceğini, yani `== 1` denetiminin her zaman tutmayabileceğini sordu. Bunun üzerine fonksiyonun belgesine bakıldı: iki string özdeşse karakterler tek tek çıkarıldığında hep 0 gelir ve sonuç 0'dır; farklıysa sonucun işareti önemlidir. Bu yüzden `== 1` yerine `> 0` ve `< 0` denetimi yapmanın daha doğru olduğu kabul edildi.

> **Ders sonrası not:** Hoca bir yerde "-1 dönerse birincisinin sayısal değeri daha büyüktür, +1 dönerse ikincisi daha büyüktür" dedi. Doğrusu tersidir: `strcmp(a, b)` negatifse `a` sözlük sırasında önce gelir (küçüktür), pozitifse sonra gelir. C standardı yalnız işareti tanımlar; dönüş değeri `-1`, `1` ile sınırlı değildir. Artan sıralama için doğru koşul `strcmp(std[j].name, std[j+1].name) > 0`'dır.

### 5.3 Soru-cevap: ASCII toplamıyla karşılaştırma

**Soru:** Stringi tam sayıya çevirip (ASCII değerleriyle) karşılaştırsak olur mu? Örneğin adın karakterlerini toplayarak ya da yalnız ilk karakterine bakarak?

**Cevap:** Karakterlerin ASCII değerlerini toplamak hatalı sonuç verir. Örneğin `ABA` ile `BAA` stringleri farklıdır ama toplamları aynıdır ($65+66+65 = 66+65+65 = 196$). Doğru yol, iki stringi karşılaştırır gibi bir `while` döngüsüyle önce birinci karakterlerin ASCII kodlarına bakmak, eşitse ikinciye, o da eşitse üçüncüye geçmektir; fark bulunan ilk karakterde karar verilir. Soruda zaten `strcmp` kullanılabileceği söylenmişti, ayrıca bir algoritma yazmaya gerek yoktu.

**Soru:** ASCII'de küçük harflerin değeri daha büyük değil mi? Büyük A ile küçük b kıyaslanınca küçük b büyük çıkmaz mı?

**Cevap:** Buradaki nokta büyüklük değil, toplamların eşit çıkabilmesidir. Temsilî değerlerle anlatıldı: bir harfin değeri 10, diğerinin 20 olsun; `10 + 20 + 10` ile `20 + 10 + 10` aynı sonucu verir ama stringler farklıdır. Öğrencinin aklındaki diğer durum (büyük harfle başlayan adların önce gelmesi) ise doğrudur ve `strcmp`'nin bir sonucudur.

## 6. Programın çalıştırılması ve çok ölçütlü sıralama

### 6.1 Deneme

Program dört öğrenciyle denendi. Nota göre sıralamada notlar 88, 34, 6, 4 sırasıyla geldi; 88 alan öğrencinin adı `BA`, ID'si 3 idi ve bilgilerde tutarsızlık yoktu. Ada göre sıralamada önce büyük A ile başlayan ad, sonra `BA`, sonra `Ba`, en sonda küçük a ile başlayan ad (notu 4 olan) geldi. Bunun nedeni tamamen ASCII sırasıdır: büyük harfler küçük harflerden önce gelir. <!-- BELİRSİZ: Terminal ekranı karelerde görünmüyor; girilen adların tamamı altyazıdan çıkarılamadı. -->

> **Ders sonrası not:** Hoca ASCII değerlerini "67, 65, 97" diye hatırladı. Doğrusu `'A' = 65`, `'B' = 66`, `'a' = 97`'dir (`'C' = 67`).

Aşağıdaki tam program karelerdeki parçalardan derlendi; yalnız `n`/`N` uyumsuzluğu giderildi ve ad karşılaştırması `> 0` yapıldı. `gcc -Wall` ile uyarısız derlendi. Notları 88, 34, 6, 4 olan ve adları `Aa`, `Ba`, `BA`, `aa` olan dört kayıtla çalıştırıldığında nota göre sıra 88, 34, 6, 4; ada göre sıra `Aa`, `BA`, `Ba`, `aa` çıktı.

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct STD{
 int id, age, grade;
 char name[20];
}STUDENT;

void liste_yaz(STUDENT* std, int n);
void nota_gore_sirala(STUDENT* std, int n);
void ada_gore_sirala(STUDENT* std, int n);

int main(){
    int N, i;
    STUDENT *std;
    printf(" N degeri"); scanf("%d",&N);
    std = (STUDENT*)calloc(N,sizeof(STUDENT));
    if(std!=NULL){
        for(i=0;i<N;i++){
            printf("%d. Ogrenci id",i); scanf("%d",&std[i].id);
            printf("%d. Ogrenci adi",i); scanf("%s",std[i].name);
            printf("%d. Ogrenci notu",i); scanf("%d",&std[i].grade);
            printf("%d. Ogrenci yasi",i); scanf("%d",&std[i].age);
        }
        liste_yaz(std, N);
        nota_gore_sirala(std, N);
        liste_yaz(std, N);
        ada_gore_sirala(std, N);
        liste_yaz(std, N);
        free(std);
    }
    else{
        printf("Error");
        return 0;
    }
    return 0;
}
void nota_gore_sirala(STUDENT* std, int n){
    int i, j;
    STUDENT tmp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(std[j].grade<std[j+1].grade){
                tmp=std[j];
                std[j]=std[j+1];
                std[j+1]=tmp;
            }
        }
    }
}
void ada_gore_sirala(STUDENT* std, int n){
    int i, j;
    STUDENT tmp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(strcmp(std[j].name,std[j+1].name)>0){
                tmp=std[j];
                std[j]=std[j+1];
                std[j+1]=tmp;
            }
        }
    }
}
void liste_yaz(STUDENT* std, int n){
    int i;
    printf("\nID\tAD\tNOT\tYAS\n");
    for(i=0;i<n;i++){
        printf("%d\t%s\t%d\t%d\n",std[i].id,std[i].name,std[i].grade,std[i].age);
    }
}
```

### 6.2 Çok ölçütlü sıralama

Burada iki ölçüt ayrı ayrı uygulandı. Bir adım ötesi şu soru olabilir: önce nota göre sıralayın, notları aynı olan öğrencileri ada göre sıralayın. Bunun için tek bir sıralama algoritmasının içine ikinci bir `if` eklenir; Excel'de birden çok ölçüte göre sıralama yapmanın C'deki karşılığıdır. Bu yapı nesneye yönelik programlamada nesne sıralaması (object sorting) olarak çok kullanılır; ağaçlarda ve veri yapıları dersinde tekrar karşılaşılacaktır.

## 7. CAR sorusu: diziyi fonksiyonda açıp işaretçi döndürmek

### 7.1 Sorunun metni

Hazır bir çözüm dosyası açıldı. Soru metni şöyledir (ekrandan, 00:50:00):

> CAR isminde bir struct oluşturunuz. Bu struct araca ait fiyat, model yılı ve marka bilgilerini saklamalıdır. Main içerisinde kullanıcıdan N eleman sayısı alındıktan sonra
> 1- CAR * AllocateSpace(N) isimli fonksiyon N değerini alacak ve N elemanlı CAR dizisi oluşacaktır.
> 2- 1. maddede oluşturulan dizi içine veriler main() içerisinde kullanıcıdan alınacaktır.
> 3- main() içerisinde kullanıcıdan alınan yıl bilgisine göre araç bulma işlemi yapılacaktır. Bu işlem için void FindCars(CAR *, int N, int year); fonksiyonunu yazınız. Fonksiyonda modelYear değeri year değerine eşit olan araçların tüm bilgilerini ekrana yazdırınız.

Dosyadaki struct ve prototipler (ekrandan, 00:50:00):

```c
typedef struct car{
    unsigned int fiyat;
    unsigned int model;
    char marka[25];
} CAR;

CAR* AllocateSpace(int );
void get_info(CAR *,int );
void write_info(CAR *,int );
void FindCars(CAR *, int , int );
```

Bir önceki soruda dizi `main` içinde açılmıştı; burada farklı bir fonksiyonda açılıyor. Çözüm dosyasında veriler sorudakinden farklı olarak `main` yerine `get_info` fonksiyonunda okunuyor.

### 7.2 Çözümün akışı

`main` içinde bir `CAR *ptrCar` işaretçisi, `N`, `i` ve yıl değişkenleri tanımlanır. $N$ kullanıcıdan alınır ve yalnız $N$ `AllocateSpace`'e gönderilir. `AllocateSpace` bir `CAR` işaretçisi döndürür. Fonksiyonun içinde yerel bir `CAR *` değişkeni tanımlanır ve `malloc` ile heap bölgesinde $N$ elemanlık bir yer açılır.

Buradaki ayrım önemlidir: yerel işaretçi değişkeni stack bölgesinde tutulur ve fonksiyon bitince yok olur. `malloc` ile heap'te üretilen alan ise kalıcıdır. Bu alanın adresi return edilirse, return edilen yerde bu adres saklanabilir ve alan kullanılmaya devam edilir. `main` bu adresi `ptrCar`'da tutar.

Önceki haftalarda bir dizinin en küçük elemanı üç farklı yolla bulunmuştu: en küçük elemanın değerini döndürmek, indisini döndürmek (bu ikisinde dönüş türü `int`) ve bellekteki adresini döndürmek. Son yöntemde fonksiyon bir `int *` döndürüyordu. `AllocateSpace` da aynı mantıkla bir struct işaretçisi döndürür.

Ardından `get_info(ptrCar, N)` ile veriler kullanıcıdan alınır; dizinin adresi gittiği için okunan değerler doğrudan diziye yazılır (adresle çağırma, call by reference). `write_info` aynı yapıda ekrana yazar. `FindCars` işaretçiyi, eleman sayısını ve yılı alır, bütün elemanları tarar ve model yılı verilen yıla eşit olanları ekrana basar. Bu yapı nesneye yönelik programlamada da sık kullanılır; daha nesnel bir bakış açısıyla yazılmış bir çözümdür.

<!-- BELİRSİZ: Çözüm dosyasının fonksiyon gövdeleri karelerde görünmüyor; akış altyazıdan kuruldu. Altyazıda "karakter pointer" geçen yerler ekrandaki CAR * türüne göre düzeltildi. -->

Fonksiyon gövdeleri ekranda görünmediği için aşağıdaki çözüm ajan tarafından yazıldı ve `gcc -Wall` ile derlenip üç araçlık bir girdiyle denendi (Örnek Sorular bölümünde).

## 8. Karmaşık sayı dizisini yazdırmanın yolları

Önceki uygulamada karmaşık sayılar bir tam sayı matrisinde (bir kısmı reel, bir kısmı sanal) tutulmuştu. Bu dosyada ise `typedef` ile bir `COMPLEX` türü tanımlanıp $N$ elemanlı bir karmaşık sayı dizisi oluşturuldu. Dizi `rand()` ile rastgele dolduruluyor; klavyeden de doldurulabilirdi. Dosyadaki fonksiyonlar (ekrandan, 00:55:00):

```c
void dizi_doldur(COMPLEX *c,int N){
    int i=0;
    for(i=0;i<N;i++){
        c[i].real=rand()%10;
        c[i].imag=rand()%10;
    }
}

void dizi_yazdir(COMPLEX *c,int N){
    int i=0;
    COMPLEX *tmp=c;
    for(i=0;i<N;i++){
        printf("\n%d + %di",c[i].real,c[i].imag);
    }
    printf("\nYazdirma_2");
    for(i=0;i<N;i++){
        printf("\n%d + %di",tmp->real,tmp->imag);
        tmp++;
    }
    /*for(i=0;i<N;i++){
        printf("%d + %di\n",*(c+i).real,*(c+i).imag);
    }*/
}
```

Birinci döngü az önceki soruda olduğu gibi indeks operatörünü kullanır. İkinci döngü işaretçi aritmetiğini kullanır. Bunun için geçici bir `tmp` işaretçisi tanımlanır, çünkü `c`'nin değişmesi, yani dizinin başının kaybedilmesi istenmez. `tmp->real` "tmp hangi adresi gösteriyorsa oradaki struct'ın real alanına git" demektir. `tmp++` yapıldığında işaretçi, türünün boyutu kadar (`sizeof(COMPLEX)`) artar ve bir sonraki elemanı gösterir. Üçüncü yol olarak `c`'ye `i` eklenip yıldızla o adresteki değere erişmek gösterildi.

> **Ders sonrası not:** Dosyada yorum içinde duran `*(c+i).real` ifadesi bu hâliyle derlenmez, çünkü `.` operatörünün önceliği `*`'dan yüksektir; derleyici `(c+i).real` yapmaya çalışır. Doğrusu `(*(c+i)).real` ya da `(c+i)->real`'dir. Bu fark gcc ile denendi.

Struct ve dinamik bellek birlikte kullanıldığında çoğu zaman indeksli yazım işi görür. Struct dizisi yerine yalnız işaretçiyle dolaşılıyorsa `->` daha sık kullanılır. Bu durumda dizinin ilk elemanının adresini kaybetme riski vardır, bu yüzden yedek bir işaretçi tutulmalıdır.

## 9. Üç boyutlu diziler ve işaretçi aritmetiği

### 9.1 İlk değer verme

Bir öğrencinin daha önce sorduğu soru şuydu: işaretçi aritmetiği üç ya da dört boyutlu dizilerde nasıl uygulanır? Önce `int a[2][2][2]` dizisine ilk değer verme gösterildi. Her en içteki küme bir satırdır, iki satır bir matris oluşturur, iki matris de üç boyutlu diziyi oluşturur. Ekrandaki ilk hali şöyledir (ekrandan, 01:00:00):

```c
#include <stdio.h>
int main(){
int a[2][2][2]={{{0,1},{2,3}},{{4,5},{5,6}}};
int i, j, k;
for(i=0;i<2;i++){
    for(j=0;i<2;i++){
        for(j=0;i<2;i++){
            printf("%d ",a[i][j][k]);
        }
        printf("\n");
    }
}
}
```

Bir öğrenci ikinci ve üçüncü döngülerde değişkenlerin yanlış kaldığını (`i` yerine `j` ve `k` yazılması gerektiğini) fark etti; döngüler düzeltildi. Değerler de daha sonra 0'dan 7'ye kadar değiştirildi ve program `0 1 2 3 4 5 6 7` yazdırdı. Çıktıda her satır bir matris satırıdır; iki matris alt alta görünür.

### 9.2 İşaretçiyle erişim

`a` bir adrestir. `a`'ya $i$ eklendiğinde ilgili matrise gidilir; bu adresteki değer (`*(a+i)`) yine bir adrestir. Ona $j$ eklenince o matrisin $j$. satırına gidilir, o da bir adrestir (`*(*(a+i)+j)`). Buna $k$ eklenince o satırın $k$. elemanının adresine ulaşılır. İlk denemede en dıştaki parantez ve yıldız eksikti; bir öğrenci $k$'yı da parantezle çevreleyip bir yıldız daha koymak gerektiğini söyledi. Sonuç:

$$a[i][j][k] \equiv *(*(*(a+i)+j)+k)$$

Yani $i$ hangi matris (üstteki mi, alttaki mi), $j$ o matrisin hangi satırı, $k$ hangi sütun olduğunu seçer. Yıldız konulmadan, yani yalnız adreslerle yazdırıldığında adres değerleri basılır; doğru ifadeyle iki yöntem aynı yerlere erişir. Aşağıdaki program ajan tarafından derlendi (`gcc -Wall`, uyarısız) ve iki yöntemle de `0 1 2 3 4 5 6 7` yazdırdı.

```c
#include <stdio.h>
int main(){
int a[2][2][2]={{{0,1},{2,3}},{{4,5},{6,7}}};
int i, j, k;
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        for(k=0;k<2;k++){
            printf("%d ",a[i][j][k]);
        }
        printf("\n");
    }
}
for(i=0;i<2;i++)
    for(j=0;j<2;j++)
        for(k=0;k<2;k++)
            printf("%d ",*(*(*(a+i)+j)+k));
printf("\n");
return 0;
}
```

<!-- BELİRSİZ: İşaretçili printf satırının ekrandaki son hali karelerde görünmüyor; ifade altyazıdaki anlatımdan (01:01:15 - 01:04:39) ve öğrencinin düzeltmesinden kuruldu. -->

## 10. Struct konusunun kısa tekrarı

Önceki haftanın struct slaytları üzerinden şu noktalar tekrar edildi:

- `typedef` ile istenen bir türe yeni ad verilebilir (örneğin bir tam sayı türüne); `COMPLEX` türü de böyle üretildi. Bu türle değişken, işaretçi, çift işaretçi ve statik dizi tanımlanabilir.
- Bir struct işaretçisi kullanılmadan önce veri saklayan bir yeri göstermelidir. Örnekte `c` işaretçisi önce `c1` değişkenini gösterecek şekilde atanmıştır. `c1` veri saklar, `c` adres saklar.
- İki işaretçi (`c` ve `c2`) aynı `c1`'i gösterirse bu sığ kopyalamadır (shallow copy). Birinden yapılan değişiklik doğrudan `c1`'e, dolayısıyla diğerine de yansır.
- Struct değişkeni fonksiyona gönderilirse kopyalanır, yani değerle çağırmadır (call by value); fonksiyonun içinde sıfırlamak asıl değişkeni değiştirmez. Struct dizisi ise adresle gider. Asıl değişkeni gerçekten sıfırlamak için işaretçisi gönderilmelidir.
- İşaretçi gönderilince alanlara iki yolla erişilir: `(*p).real` ve `p->real`.

> **Hocanın vurgusu:** Bu operatörleri iyi kullanmayı ve birbirleri cinsinden nasıl yazıldıklarını öğrenin.

Sonraki konular olarak struct'ların özel hali olan union'lar ve bit alanları (bitfield), ardından özyineleme (recursion), fonksiyon işaretçileri ve büyük bir konu olarak dosya işlemleri (file I/O) sayıldı. Bağlı listelere (linked list) önemli bir konu olduğu için ayrıca devam edilecek. Programı alt parçalara bölmek için başlık dosyaları ve makefile konuları da dönemin geri kalanında yer alacak.

## Örnek Sorular

### Soru 1: Öğrenci listesini dinamik dizide tutup sıralamak

(ekrandan, 00:15:00 - 00:45:00; derste çözüldü)

Öğrencilerin ID, yaş, not ve ad bilgilerini tutan bir struct tanımlayın. Öğrenci sayısı $N$ kullanıcıdan alınsın, dizi dinamik olarak açılsın ve veriler `main` içinde okunsun. Listeyi ekrana yazan, nota göre sıralayan ve ada göre sıralayan fonksiyonları yazın; `main`'de liste yazılsın, nota göre sıralanıp yazılsın, ada göre sıralanıp yazılsın ve bellek bırakılsın. Fonksiyonların dönüş türünü siz belirleyin.

> **Çözüm:** Bölüm 6.1'deki tam program. Dönüş türleri `void`'dir: yazdırma bir değer üretmez, sıralama gönderilen diziyi yerinde değiştirir. Ada göre sıralamada `strcmp(...) > 0` koşulu kullanılır.

### Soru 2: Notu eşit olanları ada göre sıralamak

(derste sözlü, 00:47:35)

Öğrencileri nota göre sıralayın; notları aynı olan öğrencileri ada göre sıralayın. Tek bir sıralama algoritması kullanın.

> **Çözüm (derste verilmedi):** Takas koşuluna ikinci bir ölçüt eklenir. Azalan not, eşit notta artan ad için:
>
> ```c
> if(std[j].grade < std[j+1].grade ||
>    (std[j].grade == std[j+1].grade &&
>     strcmp(std[j].name, std[j+1].name) > 0)){
>     tmp=std[j];
>     std[j]=std[j+1];
>     std[j+1]=tmp;
> }
> ```
>
> Bu parça Bölüm 6.1'deki `nota_gore_sirala` içinde `if` satırının yerine konarak denendi (gcc).

### Soru 3: CAR dizisi ve FindCars

(ekrandan, 00:50:00)

Soru metni Bölüm 7.1'dedir.

> **Çözüm (derste verilmedi):** Derste çözüm dosyası anlatıldı ama fonksiyon gövdeleri ekranda görünmedi. Aşağıdaki çözüm ajan tarafından yazıldı; `gcc -Wall` ile uyarısız derlendi. Üç araçla (2015, 2018, 2015 model) ve yıl olarak 2015 ile denendiğinde iki 2015 model araç yazdırıldı.
>
> ```c
> #include<stdio.h>
> #include<stdlib.h>
>
> typedef struct car{
>     unsigned int fiyat;
>     unsigned int model;
>     char marka[25];
> } CAR;
>
> CAR* AllocateSpace(int );
> void get_info(CAR *,int );
> void write_info(CAR *,int );
> void FindCars(CAR *, int , int );
>
> int main(){
>     CAR *ptrCar;
>     int N, year;
>     printf("N: "); scanf("%d",&N);
>     ptrCar = AllocateSpace(N);
>     if(ptrCar==NULL){ printf("Error"); return 1; }
>     get_info(ptrCar, N);
>     write_info(ptrCar, N);
>     printf("Yil: "); scanf("%d",&year);
>     FindCars(ptrCar, N, year);
>     free(ptrCar);
>     return 0;
> }
> CAR* AllocateSpace(int N){
>     CAR *p = (CAR*)malloc(N*sizeof(CAR));
>     return p;
> }
> void get_info(CAR *c,int N){
>     int i;
>     for(i=0;i<N;i++){
>         printf("%d. arac fiyat model marka: ",i);
>         scanf("%u %u %24s",&c[i].fiyat,&c[i].model,c[i].marka);
>     }
> }
> void write_info(CAR *c,int N){
>     int i;
>     for(i=0;i<N;i++)
>         printf("\n%u\t%u\t%s",c[i].fiyat,c[i].model,c[i].marka);
>     printf("\n");
> }
> void FindCars(CAR *c, int N, int year){
>     int i;
>     for(i=0;i<N;i++)
>         if(c[i].model==(unsigned)year)
>             printf("%u\t%u\t%s\n",c[i].fiyat,c[i].model,c[i].marka);
> }
> ```

### Soru 4: Üç boyutlu dizide işaretçi aritmetiği

(derste sözlü, 00:58:17; ekrandan, 01:00:00)

`int a[2][2][2]` dizisinin `a[i][j][k]` elemanına indeks operatörü kullanmadan, yalnız işaretçi aritmetiğiyle nasıl erişilir?

> **Çözüm:** `*(*(*(a+i)+j)+k)`. `a+i` $i$. matrisin, `*(a+i)+j` o matrisin $j$. satırının, `*(*(a+i)+j)+k` o satırın $k$. elemanının adresidir; en dıştaki `*` değeri okur. Bölüm 9.2'deki program iki yöntemle aynı çıktıyı verdi.

### Soru 5: strcmp sonucunun denetimi

(derste sözlü, 00:40:44)

`strcmp` ile yapılan karşılaştırmada sonucu `== 1` ile denetlemek doğru mu? Karakterler arasındaki fark 1'den büyükse ne olur?

> **Çözüm:** Derste `> 0` / `< 0` denetiminin daha doğru olduğu kabul edildi. C standardı `strcmp`'nin yalnız işaretini tanımlar; bazı derleyicilerde sonuç karakter farkının kendisidir (örneğin 2 ya da 32). Bu yüzden `== 1` bazı karşılaştırmaları kaçırabilir.

## Dersin Toparlaması

Bu oturumda struct dizileriyle çalışmanın temel adımları bir soru üzerinde bir arada görüldü: `typedef` ile tür tanımlamak, `calloc` ile dinamik dizi açıp `NULL` denetimi yapmak, alanlara `&std[i].alan` ve `std[i].name` ile veri okumak, struct'ları tek atamayla takas ederek sıralamak ve stringleri `strcmp` ile karşılaştırmak. ASCII toplamı gibi kestirme yöntemlerin neden yanlış olduğu ve `strcmp` sonucunun işaretine göre denetlenmesi gerektiği tartışıldı. CAR sorusunda dizinin bir fonksiyonda heap'te açılıp adresinin döndürülmesi, stack ile heap arasındaki ömür farkı üzerinden açıklandı.

Karmaşık sayı ve üç boyutlu dizi örnekleri, aynı elemana indeksle, `->` ile ve işaretçi aritmetiğiyle erişmenin eşdeğer yollarını gösterdi. Struct tekrarında sığ kopya ve struct'ların fonksiyona değerle gitmesi hatırlatıldı. Sonraki derslerde union'lar, bit alanları, özyineleme, fonksiyon işaretçileri ve dosya işlemleri işlenecek; bağlı listelere de devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
