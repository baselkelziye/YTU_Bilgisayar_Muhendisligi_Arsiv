# Ders 24 Genişletilmiş Notu: Rastgele Erişim: fseek, ftell ve İndeksli Dosya Okuma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sıralı Erişimden Rastgele Erişime
- 2. fseek Fonksiyonu
- 3. ftell Fonksiyonu
- 4. İndeks Fikri: Dosyayı Değil İndeksi Sıralamak
- 5. Birinci Program: Kayıt Dosyasını Oluşturma
- 6. İkinci Program: İndeksi Kurma, Sıralama ve Yazdırma
- 7. Programların Çalıştırılması ve Dosya Konumunun İzlenmesi
- 8. Soru-Cevap: Bellek Yönetimi ve Program Tasarımı
- Örnek Sorular

## 1. Sıralı Erişimden Rastgele Erişime

Ders, dosya konusunun son parçası olan rastgele erişimle (random access) başladı. Önceki derslerde dosyalar text ya da binary modda, farklı biçimlerde açılıp işlendi. Ama bütün bu işlemler sıralı erişimdi (sequential access): ilk kayıttan başlanıp son kayda kadar sırayla gidildi. Slaytta da bu durum şöyle özetlenir: şimdiye kadar dosyaya ilk bayttan başlanarak ve her bayt sırayla işlenerek erişildi; bazı uygulamalar için bu yeterlidir, ama bazı uygulamalarda dosyanın ortasındaki belirli baytlara erişmek gerekir (ekrandan, 00:05:00).

Hoca bunu çalışan kayıtlarının tutulduğu bir dosyayla örnekledi. Belirli bir çalışanın kaydını bulmak için normalde dosyanın başından başlayıp o kayda kadar okumak gerekir. Dizilerde de durum aynıdır: bir elemanı bulmak için baştan aramak gerekir. Dizilerde daha hızlı arama istendiğinde ikili arama (binary search) gibi sıralı dizi üzerinde çalışan algoritmalar kullanılıyordu. Dosyalar için de sıralama aramayı kolaylaştırır. Ancak dosya erişimi bellek erişiminden çok daha yavaştır, dosyayı sıralamak da uzun sürer.

Asıl soru şudur: bellekte bir dizinin üçüncü, beşinci ya da onuncu elemanına indeks vererek doğrudan gidebiliyorsak, dosyada da aynısını yapabilir miyiz? Yapabiliriz; buna rastgele erişim denir. Bunun için iki temel fonksiyon vardır:

- `fseek()`: dosya konum işaretçisini (file position indicator) belirli bir bayt konumuna götürür.
- `ftell()`: dosya konum işaretçisinin şu anda dosyanın kaçıncı baytında olduğunu söyler.

Bu ikisi birlikte kullanılarak işaretçi istenen yere götürülür ve okumaya oradan başlanır.

## 2. fseek Fonksiyonu

### 2.1 İmza ve parametreler

Slayttaki tanım (ekrandan, 00:10:00):

```c
int fseek(FILE *stream, long int offset, int whence);
```

- `stream`: dosya işaretçisi (`FILE *`). Hoca, her dosya işaretçisinin aslında bir akış (stream) olarak işlendiğini hatırlattı.
- `offset`: kaç karakter gidileceği. Negatif olabilir, çünkü geri gitmek de istenebilir.
  - Binary dosyada bayt sayısıdır: 3 verilirse 3 bayt.
  - Text dosyada ya 0 ya da `ftell()`'in döndürdüğü bir değer olmalıdır.
- `whence`: offset'in hangi noktadan sayılacağı. `stdio.h` içinde üç seçenek tanımlıdır:
  - `SEEK_SET`: dosyanın başı.
  - `SEEK_CUR`: dosya konum işaretçisinin şu anki yeri.
  - `SEEK_END`: dosyanın sonu (end-of-file).

Hoca anlatırken parametre adlarını bir an karıştırdığını fark edip "doğru düzgün okumadığımdan kaynaklanıyor" diyerek baştan aldı: birinci parametre dosya işaretçisi, ikincisi kaç bayt ilerleneceği, üçüncüsü bu ilerlemenin nereden başlayacağıdır. Baştan, bulunulan yerden ya da dosyanın sonundan itibaren gidilebilir. `SEEK_END` verip pozitif offset vermek sorun çıkarır, çünkü dosyanın sonundan daha ileride gidilecek bir yer yoktur; ancak geri gidilebilir. Bu yüzden offset'in negatif olabilmesi anlamlıdır.

> **Ek bilgi (derste anlatılmadı):** Text modda bazı sistemlerde satır sonu iki baytla (`\r\n`) saklanıp programa tek karakter (`\n`) olarak verilir. Bu yüzden text dosyada "karakter sayısı" ile "bayt konumu" bire bir örtüşmeyebilir. Slayttaki "text dosyada yalnız 0 ya da `ftell` değeri" kuralının nedeni büyük olasılıkla budur.

### 2.2 Örnek çağrı ve dönüş değeri

Slayttaki örnek (ekrandan, 00:15:00):

```c
stat = fseek(fp, 10, SEEK_SET);
```

Bu çağrı dosya konum işaretçisini akışın 10. karakterine götürür. Bir sonraki okunan ya da yazılan karakter bu olur. Akışlar da diziler gibi 0. konumdan başlar; bu yüzden 10. karakter aslında akıştaki 11. karakterdir.

> **Ders sonrası not:** Hoca 00:13:03'te bu çağrı için "şu an dosya konum işaretçisinin bulunduğu noktadan on bayt ileri git" dedi; doğrusu dosyanın **başından** 10 bayt ileridir. "Bulunulan noktadan" anlamı `SEEK_CUR`'a aittir. Hoca dersin ikinci saatinde (01:26:54) slayta dönüp `SEEK_SET`'in "beginning" anlamına geldiğini görünce "set şu an neredeyse o anlamda kalmış aklımda" diyerek bunu kendisi düzeltti.

Fonksiyon `int` döndürür. İstek geçerliyse 0, değilse sıfırdan farklı bir değer döner. Hoca bunun "biraz ters mantık" olduğunu, "sıfırsa problem yok, sıfır dışında bir şey varsa sorun var" diye düşünmek gerektiğini söyledi.

### 2.3 Geçersiz istekler ve sınırlar

Slayta göre sıfırdan farklı dönüşün çeşitli nedenleri olabilir. Örneğin `fp` salt okuma için açılmışsa şu çağrı geçersizdir, çünkü işaretçiyi dosya sonunun ötesine taşımaya çalışır (ekrandan, 00:15:00):

```c
stat = fseek(fp, 1, SEEK_END);
```

Slayttaki genel kurallar:

- Salt okunur dosyada `SEEK_END` kullanılıyorsa offset $\le 0$ olmalıdır.
- `SEEK_SET` kullanılıyorsa offset $\ge 0$ olmalıdır.
- Dosya konum işaretçisi dosyanın dışına itilmemelidir.

Hoca, dosya yazma modunda açılıp sonundan 10 bayt ileri gidilip yazılırsa aradaki boşluğun ne olacağını (binary'de sıfır mı, text'te boşluk mu, rastgele bir şey mi) bilmediğini, bunun da kendisine mantıksız geldiğini söyledi. `SEEK_END` ile offset vermek daha çok salt okunur dosyalarda, sıfır ya da negatif değerle anlamlıdır.

> **Hocanın vurgusu:** C'nin farklı standartları ve işletim sistemlerinin farklılıkları yüzünden bir denemenin bir sistemde doğru, başka bir sistemde farklı sonuç vermesi mümkündür. Bu yüzden sistem izin verse de vermese de yapılan şey mantıklı olmalı, işaretçi dosyanın sınırları içinde tutulmalıdır. Böylece kodun taşınabilirliği, yani farklı platformlarda çalışabilirliği artar.

## 3. ftell Fonksiyonu

Dosyanın herhangi bir konumuna gitmek kadar dosyanın neresinde olunduğunu bilmek de önemlidir. `ftell` tek parametre alır: dosya işaretçisi. Dosyanın başından itibaren kaçıncı baytta olunduğunu döndürür.

Text dosyada `ftell`'in döndürdüğü değer farklı yorumlanabilir; hoca slayttaki "yalnız bir `fseek` çağrısına offset olarak verildiğinde anlamlıdır" ifadesini okudu. Hoca `SEEK_CUR` için de kendi gözünden iyi bir kullanım örneği bulamadığını söyledi. Özetle iki fonksiyon vardır: `fseek` istenen noktaya gitmeyi, `ftell` nerede olunduğunu öğrenmeyi sağlar.

## 4. İndeks Fikri: Dosyayı Değil İndeksi Sıralamak

### 4.1 Problem

Slayttaki örnek (ekrandan, 00:20:00): kayıtlardan oluşan büyük bir veri dosyası düşünülür; her kayıt önceki haftalarda tanımlanan `PERSONALSTAT` yapısındadır. Kayıtlar rastgele sıradadır, ama `name` alanına göre alfabetik yazdırılmak istenir. Bunun için önce kayıtları sıralamak gerekir. Oysa sıralama çok zaman ve G/Ç işlemi ister. Slaytın önerisi: sıralamak yerine bir indeks oluşturup yalnız indeksi sıralamak.

Hoca gerekçeyi genişletti. Sık arama yapılacaksa sıralama bir yatırım olarak görülebilir. Ama yalnız çalışan numarasına göre değil, ada, maaşa ya da kaç yıldır çalıştığına göre de arama yapılmak istenebilir. Her ihtiyaç değiştiğinde dosyayı yeniden sıralamak hiç mantıklı değildir. Mantıklı olan, dosyayı olduğu gibi sırasız bırakıp onun için bir ya da birden fazla indeks tutmaktır. Dosya hangi sırada gezilmek isteniyorsa ilgili indeks üzerinden gezilir.

### 4.2 İndeksin yapısı

İndeks bir yapı dizisidir. Yapının iki alanı vardır:

- Birinci alan: indekste tutulmak istenen bilgi, yani anahtar (örneğin ad).
- İkinci alan: bu kaydın dosyada kaçıncı kayıt olduğu.

İkinci alanda kaydın kaçıncı bayttan başladığı da tutulabilir; ikisi aynı kapıya çıkar, çünkü kayıt yapısının bayt uzunluğu bellidir. Hocanın örneğiyle: kayıt 64 bayt ise 10. kayıt 640. bayttan itibaren yer alır. Biri diğerinden kolayca hesaplanır. Dizi anahtara göre sıralanınca sıralı indeks elde edilir. Kaç farklı alanda indeks isteniyorsa o kadar dizi tutulur.

### 4.3 İndeksin kalıcılığı ve güncelliği

İndeks kalıcı olsun istenirse ayrı bir dosyaya yazılabilir. Bu mantıklıdır: program her açıldığında indeksi sıfırdan oluşturmak yerine, indeks dosyası varsa onu hızlıca okur ve yeniden kurmaz. Ancak indeksin güncel tutulması gerekir. Çalışanlar dosyasında bir değişiklik yapıldığında indeksin de tazelenmesi gerektiğini programcı unutmamalıdır. İki seçenek vardır:

- Veri dosyası değişince indeks hemen yeniden kurulur.
- Bir yere "dosya değişti" işareti konur. İndeksli çalışan program başladığında önce bu işarete bakar; yeniden indeksleme gerekiyorsa yapar, sonra işareti kaldırır ve çalışmasına devam eder.

### 4.4 Örnek tablo

Slayttaki örnek kayıtta çalışanın adı, kimlik numarası ve doğum tarihi vardır. Dosyadaki ilk kayıt Jordan'dır, son kayıt da başka bir addır. Ad alanı "soyad, ad" biçiminde yazıldığı için tüm ad anahtar olarak kullanılabilir; sıralama baştaki harflere göre yapılır. Sayım 0'dan başladığı için Jordan indeks 0, Bird indeks 1, Irving indeks 2'dir.

İndeks yapısı anahtar sütununa göre sıralanınca Bird (indeks 1) başa geçer, ardından Irving (indeks 2), sonra ana dosyada 4. konumda bulunan Johnson gelir. Tüm personel listelenirken önce dosyanın 1. konumuna gidilip kayıt okunur, sonra 2. konumuna, sonra 4. konumuna. <!-- BELİRSİZ: örnek tablonun tamamı (bütün adlar ve indeksleri) ekran karelerinde yok; yalnız altyazıda geçen adlar ve indeksler alındı -->

## 5. Birinci Program: Kayıt Dosyasını Oluşturma

### 5.1 Yapılar

Önce tarih için ayrı bir yapı tanımlanır, sonra kişi kaydı (ekrandan, 00:35:00):

```c
typedef struct {
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 11;
} DATE;
typedef struct {
    char ps_name[NAME_LEN], ps_tcno[11];
    DATE ps_birth_date;
} PERSONALSTAT;
```

`NAME_LEN` 19'dur. Kayıtta ad, kimlik numarası ve doğum tarihi vardır.

> **Ders sonrası not:** Hoca 00:27:47'de bit alanları için "5 bayt, 4 bayt, 11 bayt ... 20 bayt oluyor; 16'ya sığdıramıyoruz ama 32'yi harcamıyoruz" dedi. Doğrusu 5, 4 ve 11 **bit**, toplam 20 bittir; 16 bite sığmaz, tek bir 32 bitlik `unsigned int` içine sığar. Ajanın derlediği programda (gcc, x86-64) `sizeof(DATE)` 4 bayt, `sizeof(PERSONALSTAT)` 36 bayt çıktı: 19 + 11 = 30 bayt karakter, 4 bayt hizalama için 2 bayt boşluk, 4 bayt tarih. Derste ekranda görünen `records.dat` dosyası 4 kayıt için 144 bayttı (ekrandan, 01:10:00); bu da $4 \times 36 = 144$ ile uyuşur.

### 5.2 main fonksiyonu

Slayttaki kod (ekrandan, 00:30:00):

```c
int main(){
    int j; FILE *fp; unsigned int val;
    PERSONALSTAT ps2[4];
    fp=fopen("records.dat", "wb");
    for(j=0; j<4; j++){
        printf("Enter name of the %d-th person:\n", j+1);
        scanf("%s", ps2[j].ps_name);
        printf("Enter tcno of the %d-th person:\n", j+1);
        scanf("%s", ps2[j].ps_tcno);
        printf("Enter the birth-date (day) of the %d-th person:\n", j+1);
        // NOT ALLOWED: scanf("%u", &ps2[j].ps_birth_date.day);
        scanf("%u", &val); ps2[j].ps_birth_date.day=val;
        printf("Enter the birth-date (month) of the %d-th person:\n", j+1);
        scanf("%u", &val); ps2[j].ps_birth_date.month=val;
        printf("Enter the birth-date (year) of the %d-th person:\n", j+1);
        scanf("%u", &val); ps2[j].ps_birth_date.year=val;
        fwrite(&ps2[j], sizeof(PERSONALSTAT), 1, fp);
        //OR: char *stz="\n"; fwrite(stz, 1, 1, fp);
    }
    fclose(fp); return 0;
}
```

Adım adım:

- Dört kişilik bir `PERSONALSTAT` dizisi oluşturulur. İndeks bu programda ayrı dosyada tutulmaz; olabildiğince yalın tutulmuştur.
- Dosya yazma ve binary modda (`"wb"`) açılır. `+` konmadığı için dosya önceden varsa içeriği silinir.
- Her kişi için ad, kimlik numarası ve doğum tarihinin gün, ay, yıl bilgileri istenir.
- Yapı içindeki yapının bit alanına `&` ile doğrudan okumak yasaktır (yorum satırındaki "NOT ALLOWED"). Hoca, bazı denemelerde sorun çıkmamış olabileceğini ama platformdan platforma değişebileceğini, geçici değişken kullanmanın sorun çıkarmayacağını söyledi. Bu yüzden değer önce `val`'e okunur, sonra alana atanır.
- `fwrite` ile her kayıt dosyaya yazılır. Kaç bayt yazılacağı, yani yapının toplam boyu `sizeof(PERSONALSTAT)` ile verilir; bir kayıt yazılır.

Yorum satırındaki "OR" seçeneği (dosyaya ayrıca bir `\n` yazmak) için hoca, bunun ne amaçla konduğunu çıkaramadığını, dosyaya yalnız bir satır sonu yazmanın kendisine mantıksız geldiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** İndeksli okuma her kaydın tam `sizeof(PERSONALSTAT)` bayt olduğuna dayanır. Her kaydın arkasına fazladan 1 baytlık `\n` yazılsaydı kayıt aralığı 37 bayt olur, `index * sizeof(PERSONALSTAT)` hesabı ikinci kayıttan itibaren yanlış konumu gösterirdi. Bu satırın yorumda kalmasının bu açıdan da doğru olduğu büyük olasılıkla söylenebilir.

Aşağıdaki sürüm, slayttaki iki parçanın (yapılar ve `main`) ajan tarafından birleştirilmiş halidir; `gcc -Wall` ile uyarısız derlendi ve dört kayıt girilerek çalıştırıldı, 144 baytlık `records.dat` dosyası oluştu.

```c
#include <stdio.h>
typedef struct {
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 11;
} DATE;
typedef struct {
    char ps_name[19], ps_tcno[11];
    DATE ps_birth_date;
} PERSONALSTAT;

int main(){
    int j; FILE *fp; unsigned int val;
    PERSONALSTAT ps2[4];
    fp=fopen("records.dat", "wb");
    for(j=0; j<4; j++){
        printf("Enter name of the %d-th person:\n", j+1);
        scanf("%s", ps2[j].ps_name);
        printf("Enter tcno of the %d-th person:\n", j+1);
        scanf("%s", ps2[j].ps_tcno);
        printf("Enter the birth-date (day) of the %d-th person:\n", j+1);
        scanf("%u", &val); ps2[j].ps_birth_date.day=val;
        printf("Enter the birth-date (month) of the %d-th person:\n", j+1);
        scanf("%u", &val); ps2[j].ps_birth_date.month=val;
        printf("Enter the birth-date (year) of the %d-th person:\n", j+1);
        scanf("%u", &val); ps2[j].ps_birth_date.year=val;
        fwrite(&ps2[j], sizeof(PERSONALSTAT), 1, fp);
    }
    fclose(fp); return 0;
}
```

## 6. İkinci Program: İndeksi Kurma, Sıralama ve Yazdırma

Hoca bunun ayrı bir program olduğunu, ders sonunda bunu unuttuğu için kafasının biraz karıştığını sonradan belirtti (01:03:30): ilk program verileri oluşturur, ikinci program yalnız indeksi oluşturur, sıralar ve kayıtları indeks sırasında yazar.

### 6.1 Tanımlar

Slayttaki baş kısım (ekrandan, 00:35:00):

```c
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h> // Header file for qsort()
#include <string.h> // for the strcmp function()
#define MAX_REC_NUM 1000
#define NAME_LEN 19
/* DATE ve PERSONALSTAT tanımları birinci programdakiyle aynı */

// structure definition for the index files for our records:
typedef struct {
    int index;
    char key[NAME_LEN];
} INDEX;
```

- `MAX_REC_NUM`: en fazla 1000 kayıtla çalışılır. Hoca, programın herhangi sayıda kayıtla esnek çalışabilmesi için böyle bir üst sınır tanımlandığını söyledi.
- `NAME_LEN`: ad alanı 19 karakterdir; okurken de yazarken de 19 karakter işlenir.
- `INDEX` yapısında `index`, kaydın dosyadaki **sıra numarasıdır**, bayt konumu değildir. Bayt konumu `index * sizeof(PERSONALSTAT)` ile kolayca hesaplandığı için sıra numarası tutmak en mantıklısıdır. `key` anahtar alandır; burada ad.

> **Hocanın vurgusu:** Tarih ve kayıt yapıları burada ikinci kez tanımlandı. Normalde en mantıklısı bu yapıyı ayrı bir dosyada tanımlayıp her iki programa eklemektir. Yoksa yapıda bir değişiklik gerektiğinde onu tanımlayan her yerde ayrı ayrı düzeltme yapmak gerekir. Ders kapsamında bu konu görülmüyor.

### 6.2 get_records

Slayttaki kod (ekrandan, 00:40:00):

```c
/* Reads up to max_rec_num records from a file and stores the key field of
   each record in an index array. Returns the number of key fields stored. */
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
```

Hocanın anlatımıyla:

- Global değişkenden kaçınıldığı için üzerinde çalışılacak dosya işaretçisi, indeks değerlerinin saklanacağı dizi ve en fazla kaç kayıt okunacağı fonksiyona parametre olarak verilir.
- Bütün kayıtlar dosyanın başından okunacağı için `offset` 0'dan başlar; henüz kayıt okunmadığı için `counter` da 0'dır. Hoca bunların önemli indeks değişkenleri olduğu için açıkça sıfırlandığını söyledi. `k` döngü değişkeni, `nm` kaç karakter okunduğunu tutar.
- Hoca `nm`'ye ilk değer vermenin gereksiz göründüğünü not etti, çünkü ilk kullanıldığı yerde zaten `fread`'in sonucu atanıyor.
- `namei` bir kaydın anahtar alanını (ad) geçici olarak tutar. İlk `fread` yalnız ilk kaydın adını, yani 19 baytı okur.
- Döngü koşulu `counter < max_rec_num && nm == NAME_LEN`: en fazla kayıt sayısına ulaşılmadıkça ve tam bir ad okunabildikçe devam edilir. Hoca bunu "çıkma koşulunun tersi" diye açıkladı: $\neg(p \lor q) = \neg p \land \neg q$ mantığıyla, "sınıra ulaşıldı ya da ad okunamadı" çıkış koşulunun tersi yazılmıştır.
- Döngüde ad indekse kopyalanır, `offset` kayıt boyu kadar artırılır, `fseek` ile bir sonraki kaydın başına gidilir, sayaç artırılır ve sonraki ad okunur.
- Fonksiyon iki şey üretir. Hoca, bir fonksiyonun sonucu ya geri dönüş değeriyle ya da parametre üzerinden verebildiğini hatırlattı. Burada okunan kayıt sayısını döndürmek daha önemli görüldüğü için o geri dönüş değeri yapılmış, indeks ise parametre üzerinden doldurulmuştur. Dizilerle çalışırken hem dizinin en fazla kaç eleman alacağını hem de o an kaç eleman olduğunu bilmek gerekir; okunan kayıt sayısının döndürülmesi bu yüzden şarttır.

Hoca bu kodda bir noktadan şüphelendi (00:41:00): ilk kayıt okununca dosya işaretçisi adın sonuna gelmiş olmaz mı? Ardından kayıt boyu kadar ilerlenirse ikinci kaydın ad alanı atlanmaz mı? Ders notunu açıp `fread` anlatımına baktı, orada konum işaretçisiyle ilgili bir bilgi bulamadı ve bunu çalıştırınca görmeye karar verdi. Cevap 7. bölümdedir.

### 6.3 compare_func ve sort_index

Slayttaki kod (ekrandan, 00:45:00):

```c
/* Sort an array of NAMES_INDEX structures by the name field. There are index
   count elements to be sorted. Returns a pointer to the sorted array. */
int compare_func(INDEX *p, INDEX *q ){
    return strcmp( p->key, q->key);
    /* <0: the first character that does not match has a lower value in ptr1 than in ptr2
        0: the contents of both strings are equal
       >0: the first character that does not match has a greater value in ptr1 than in ptr2 */
}

void sort_index(INDEX names_index[], int index_count) {
    int j;
    int (*pf) (); pf = compare_func;
    // Assign values to the index field of each structure:
    for (j = 0; j < index_count; j++)
        names_index[j].index = j;
    qsort(names_index, index_count, sizeof(INDEX), pf);
}
```

- Anahtar alanı (`key`) bir karakter dizisi olduğu için iki kayıt `strcmp` ile karşılaştırılır. Sonuç negatifse ilk dizgi önce gelir, 0 ise eşittir, pozitifse sonra gelir.
- Hoca, tek satırlık bir fonksiyon yazmanın biraz fazla olduğunu, ama kodun yeniden kullanılabilirliği ve ileride farklı anahtar alanları için karşılaştırmanın basit olmayabileceği düşünülürse anlaşılır olduğunu söyledi. Tamsayı anahtar olsa doğrudan küçüktür/büyüktür yeterdi; dizgi en karmaşığıdır ve o da tek bir `strcmp` ile çözülür.
- Sıralama `qsort` (QuickSort) ile yapılır. `qsort` esnek yazılmıştır: iki elemandan hangisinin büyük, hangisinin küçük olduğuna karar veren fonksiyonu programcının vermesine izin verir. Bu yüzden önceki hafta işlenen fonksiyon işaretçisi burada kullanılır: `pf`, `compare_func`'u gösterir ve `qsort`'a parametre olarak verilir.
- `sort_index` önce her indeks elemanına dosyadaki sırasını (`index = j`) yazar, sonra diziyi anahtara göre sıralar. Böylece sıralamadan sonra her anahtarın yanında o kaydın dosyadaki yeri durur.

> **Ders sonrası not:** Slayttaki `int (*pf) ();` ve `int compare_func(INDEX *p, INDEX *q)` yazımı eski C standartlarında derlenir (boş parantez "parametreler belirtilmemiş" demekti). Ajanın denemesinde gcc 15 varsayılan standartta (C23, boş parantez `void` demek) bu iki satırı `-Wall` ile uyumsuz işaretçi hatası vererek reddetti; `-std=gnu17` ile derlendi ve doğru sıraladı. Taşınabilir yazım, `qsort`'un beklediği imzadır: `int compare_func(const void *a, const void *b)` ve `int (*pf)(const void *, const void *)`. Aşağıdaki tam programda bu yazım kullanıldı.

### 6.4 print_indexed_records

Bu fonksiyonun slaytı ekran karelerinde yer almıyor; aşağıdaki anlatım altyazıdan, koddaki hali ise hocanın anlatımından ajan tarafından yeniden kurulmuştur. <!-- BELİRSİZ: print_indexed_records'un slayttaki tam kodu karelerde yok; printf biçimi tahmin edilemez -->

- Okunacak kayıt için geçici bir `PERSONALSTAT` değişkeni ve döngü için bir sayaç tutulur.
- Okuma dosyanın başından yapılmaz. Sıralı indeksteki sıraya göre "kaçıncı kayıt okunacaksa" önce o konuma gidilir. Bunun için `fseek` kullanılır, `SEEK_SET` ile dosyanın başından sayılır.
- `fseek` bayt konumu ister; bu yüzden offset `index * sizeof(PERSONALSTAT)` olarak verilir. Konuma gidilemezse `exit(1)` ile program sonlandırılır.
- Gidilebildiyse bütün kayıt (bir kayıt, kayıt boyu kadar bayt) `fread` ile yapıya okunur ve tüm alanları ekrana yazılır.

### 6.5 main

Slayttaki kod (ekrandan, 00:50:00; aynı kod 01:05:00'te yeniden açıldı):

```c
/* To make this program complete, we need a main() function that calls these
   other functions. We have written main() so the filename can be passed as an argument.*/
int main(int argc, char *argv[]){
  FILE *data_file, *index_file; static INDEX index[MAX_REC_NUM]; int num_recs_read; char *filename;
  if (argc < 2) {
    printf( "Error: must enter index filename\n" ); printf( "Filename: " );
    filename=malloc(60);   scanf( "%s", filename );
  }
  else filename = argv[1];

  if ((data_file = fopen( filename, "rb" )) == NULL){
    printf( "Error opening file %s.\n", filename); exit(1);
  }
  num_recs_read = get_records(data_file, index, MAX_REC_NUM ) ;
  printf("num_recs_read: %d\n", num_recs_read);
  sort_index(index, num_recs_read);
  printf("After the sorting\n");
  print_indexed_records (data_file, index, num_recs_read);
  fclose(data_file);
  return 0;
}
```

- Hoca, işler kendi fonksiyonlarına düzgün ayrıldığı için `main`'e yalnız onları çağırmanın kaldığını, bunun güzel bir parametrelendirme olduğunu söyledi.
- Okunacak dosyanın adı çalışma anında kullanıcıdan değil, komut satırından parametre olarak verilir. Önceki haftalardan hatırlatma: `argv[0]` çalıştırılabilir dosyanın kendi adıdır, `argv[1]` ilk parametredir. Burada `argv[1]` kayıt dosyasının adıdır, başka parametreye gerek yoktur.
- Argüman verilmemişse (`argc < 2`) hata mesajı yazılır ve dosya adı kullanıcıdan istenir; bunun için `malloc(60)` ile yer açılır.
- Dosya binary okuma (`"rb"`) modunda açılır. Kayıtlar okunur, okunan sayı ekrana yazılır, indeks sıralanır, kayıtlar indeks sırasında yazılır ve `fclose` unutulmaz.

Hoca, ilk bakışta uzun olan `printf` satırının sonundaki ikinci komutu göremediğini fark edince satırı ikiye böldü:

> **Hocanın vurgusu:** Kodun anlaşılabilirliğini artırmak için yapılan her türlü değişiklik önemlidir.

### 6.6 Birleştirilmiş tam program

Aşağıdaki program, slayttaki parçaların ajan tarafından birleştirilmiş halidir. `print_indexed_records` anlatımdan yeniden kurulmuştur, `compare_func` taşınabilir imzayla yazılmıştır. `gcc -Wall` ile uyarısız derlendi; birinci programla oluşturulan 4 kayıtlık dosyayla çalıştırıldığında `num_recs_read: 4` yazdı ve kayıtları ada göre alfabetik sırada listeledi.

```c
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#define MAX_REC_NUM 1000
#define NAME_LEN 19
typedef struct {
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 11;
} DATE;
typedef struct {
    char ps_name[NAME_LEN], ps_tcno[11];
    DATE ps_birth_date;
} PERSONALSTAT;
typedef struct {
    int index;
    char key[NAME_LEN];
} INDEX;

int get_records(FILE* data_file, INDEX names_index[], int max_rec_num){
    int offset = 0, counter = 0, k, nm = NAME_LEN;
    char namei[NAME_LEN];
    nm=fread(namei, 1, NAME_LEN, data_file);
    for (k = 0; counter < max_rec_num && nm== NAME_LEN; k++){
        strcpy(names_index[k].key, namei);
        offset += sizeof(PERSONALSTAT);
        fseek(data_file, offset, SEEK_SET);
        counter++;
        nm=fread(namei, 1, NAME_LEN, data_file);
    }
    return counter;
}

int compare_func(const void *a, const void *b){
    const INDEX *p = a, *q = b;
    return strcmp(p->key, q->key);
}

void sort_index(INDEX names_index[], int index_count){
    int j;
    int (*pf)(const void *, const void *); pf = compare_func;
    for (j = 0; j < index_count; j++)
        names_index[j].index = j;
    qsort(names_index, index_count, sizeof(INDEX), pf);
}

/* derste slayttaydi, karelerde yok: anlatimdan yeniden kuruldu */
void print_indexed_records(FILE *data_file, INDEX index[], int index_count){
    PERSONALSTAT person;
    int j;
    for (j = 0; j < index_count; j++){
        if (fseek(data_file, (long)index[j].index * sizeof(PERSONALSTAT), SEEK_SET) != 0)
            exit(1);
        fread(&person, sizeof(PERSONALSTAT), 1, data_file);
        printf("%s %s %u.%u.%u\n", person.ps_name, person.ps_tcno,
               person.ps_birth_date.day, person.ps_birth_date.month,
               person.ps_birth_date.year);
    }
}

int main(int argc, char *argv[]){
    FILE *data_file; static INDEX index[MAX_REC_NUM]; int num_recs_read; char *filename;
    if (argc < 2) {
        printf("Error: must enter index filename\n"); printf("Filename: ");
        filename=malloc(60); scanf("%s", filename);
    }
    else filename = argv[1];
    if ((data_file = fopen(filename, "rb")) == NULL){
        printf("Error opening file %s.\n", filename); exit(1);
    }
    num_recs_read = get_records(data_file, index, MAX_REC_NUM);
    printf("num_recs_read: %d\n", num_recs_read);
    sort_index(index, num_recs_read);
    printf("After the sorting\n");
    print_indexed_records(data_file, index, num_recs_read);
    fclose(data_file);
    return 0;
}
```

> **Ek bilgi (derste anlatılmadı):** `get_records` içindeki `strcpy(names_index[k].key, namei)` satırı, okunan 19 baytın içinde bir `'\0'` bulunmasına dayanır. Ad `scanf` ile en fazla 18 karakter girildiğinde ilk 19 baytın içinde sonlandırıcı vardır; ama tam 19 karakterlik bir ad sonlandırıcısız kalır ve `strcpy` dizinin dışına taşar. Güvenli bir sürümde `namei` bir bayt büyük tutulup sonuna `'\0'` konabilir.

## 7. Programların Çalıştırılması ve Dosya Konumunun İzlenmesi

### 7.1 İki ayrı proje

Hoca iki programı Dev-C++'ta iki ayrı projeye koydu; böylece birini değiştirip ötekini ayrı ayrı çalıştırabilecekti. Birinci programda dört kişi için ad, numara ve doğum tarihi girdi (ekrandan, 01:20:00). Oluşan dosyayı ararken dosyanın beklediği yerde olmadığını gördü: Dev-C++'tan çalıştırıldığında başlangıç noktası olarak programın kodunun bulunduğu dizin değil, Dev-C++'ın kurulu olduğu konum kullanılıyordu. Komut satırından çalıştırılsaydı dosya bulunulan dizinde oluşacaktı.

Bir de aksilik yaşandı: veri girişi sırasında Ctrl-C'ye basınca program `"wb"` ile dosyayı açtığı için var olan kayıt dosyası boşaldı. Hoca kenarda tuttuğu bir yedek dosyayla devam etti, ardından birinci programı baştan çalıştırıp doğru verilerle dosyayı yeniden oluşturdu. İkinci program komut satırından kayıt dosyası parametre verilerek çalıştırıldı. Çıktıda okunan kayıt sayısı ve ardından ada göre sıralı kayıtlar göründü; her kayıt ilgili konuma gidilerek doğru okunmuştu.

### 7.2 fread sonrası konum

Böylece 6.2'deki şüphe de cevaplandı. Hoca, bir `fread` yapıldıktan sonra bir sonraki işleme kadar konumun değişmediğini gördü. Merakını gidermek için `get_records`'a her adımda `ftell` değerini yazdıran bir `printf` ekledi, hatta ilk `fread`'den önce de bir tane koydu. Sonuç: başta konum 0'dır, yani dosyanın başı. Ad uzunluğu kadar (19 bayt) okununca konum 19 olur. <!-- BELİRSİZ: sonraki ftell değerleri altyazıda "0, 19, 75" diye geçiyor ve ekran karesi yok; 36 baytlık kayıtla beklenen dizi aşağıdaki ders sonrası notta -->

Hoca o sırada slayta bakıp `SEEK_SET`'in "şu anki konum" değil "dosyanın başı" olduğunu gördü ve şüphesinin buradan kaynaklandığını söyledi. Adlandırmayı da beğenmediğini, belki üç harfli ve hizalı olsun diye "begin" yerine "set" seçildiğini ekledi. `SEEK_SET` dosyanın başından saydığı için hiçbir sorun yoktur. `offset` her adımda kayıt boyu kadar artırılarak kümülatif tutulur; ayrıca çarpma işlemine de gerek kalmaz, bundan tasarruf edilir.

> **Ders sonrası not:** Ajanın aynı dosya düzeniyle (36 baytlık kayıt) yaptığı denemede `ftell` değerleri şöyle çıktı: başta 0; ilk okumadan sonra 19; `fseek` ile 36'ya gidip 19 bayt okuyunca 55; 72'ye gidip okuyunca 91; 108'e gidip okuyunca 127. Dördüncü kayıttan sonra `fseek` 144'e (dosya sonu) gider, `fread` 0 döndürür ve döngü biter.

## 8. Soru-Cevap: Bellek Yönetimi ve Program Tasarımı

Dersin sonunda hoca, öğrencilerin takıldığı noktalara bakmayı önerdi. Akademik içerikli sorular şunlardı.

**Soru:** Bir `struct` içinde `char *` tanımlarsak ve bu yapıya değer türü olarak süslü parantezle ilk değer verirsek, o belleği `free` etmemiz gerekir mi?
**Cevap:** Gerekmez. `free` her zaman `malloc` karşılığında yapılır; ne tür `malloc` yapıldıysa onun eşleniği olan `free` yapılmak zorundadır. Süslü parantezle yapılan bir atama için `free` kesinlikle gerekmez.

**Soru:** `free`'nin türleri yok mu, tek bir fonksiyon mu?
**Cevap:** Tek bir fonksiyondur, türleri yoktur. Tek parametre alır, o da bir işaretçidir. `malloc` ile nereler açıldıysa o işaretçiler kodda kaybedilmeden tutulmalı ve sırayla `free` edilmelidir.

**Soru:** Bazı fonksiyonlarda her koşul dalından çıkmadan önce `free` yazmak gerekiyor; bu kod kalabalığı yaratıyor. Ne yapılmalı?
**Cevap:** Hoca önce kodu sindirerek yazmayı, sonra bütününe bakıp iyileştirme fırsatı aramayı önerdi.

> **Hocanın vurgusu:** İlk hedef doğru çalışan koddur. Yazarken olası iyileştirmeleri aklınızda tutun, ama önce kodu doğru tamamlayıp çalıştırın, gerekli düzeltmeleri yapın ve "tamam" dediğiniz noktada yedekleyin. Sonra iyileştirme için kurcalayın; buna refactoring denir. Kod yine düzgün çalışıyorsa son hali odur.

**Soru:** Kayıt ekleme gibi işlemleri hemen dosyaya mı yazmalı, yoksa önce bellekte bir yapı dizisinde biriktirip programdan çıkarken mi yazmalı? İkincisi daha hızlı görünüyor.
**Cevap:** Hoca bunun programcıya kalmış bir tasarım kararı olduğunu söyledi ve iki yönü tarttı. Birkaç işlem biriktirilip diske toplu yazılırsa, örneğin geri alma (undo) gerektiğinde değişikliğin diskte mi yoksa yalnız bellekte mi olduğunu ayırt etmek gerekir ve kod karmaşıklaşır. Tüm dosya başta belleğe yüklenip her şey bellekte yapılır ve yalnız çıkışta yazılırsa, kullanıcı yanlışlıkla Ctrl-C'ye basıp programı kapattığında bütün değişiklikler kaybolur; hoca aynı dersin başında kendi başına gelen dosya kaybını örnek verdi. Hocanın önerisi ortadaki yoldur: bir ekranda yapılan bir grup değişiklik, o ekrandan çıkmadan önce diske aktarılır. Böylece sonraki işlem kesin olarak diskteki güncel veri üzerinde yapılır ve performans da artar. İsteğe bağlı bir "kaydet" menü seçeneği ya da çıkışta otomatik kaydetme de eklenebilir.

**Soru:** Benzer işlemlerde tekrardan kaçınmak için fonksiyon işaretçisi nasıl kullanılır? Java'daki generic'lere ya da C++'taki template'lere benzer bir yapı mı?
**Cevap:** Hoca, önce kodu fonksiyon işaretçisi olmadan yazıp düzgün çalıştığından emin olmayı, sonra geriye dönüp nereye fonksiyon işaretçisi koymanın kazandıracağına bakmayı önerdi. Fonksiyon işaretçisinin tipik kullanımı bu dersteki `qsort` örneğidir: sıralama algoritması sabittir, "neye göre küçük, neye göre büyük" kararını programcının yazdığı karşılaştırma fonksiyonu verir; böylece farklı ölçütlere göre sıralamak mümkün olur. Hocanın aklına gelen bir başka kullanım: hem öğrencilerin hem öğretim üyelerinin birlikte tutulduğu bir dizide "öğrenci ise şunu yap" diye dallanmak yerine, öğrenci ve öğretim üyesi için ayrı fonksiyonlar yazıp işi yapacak koda uygun fonksiyonun işaretçisini vermek.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:14:18): `fseek` neden sıfırdan farklı bir değer döndürebilir? Hangi çağrı salt okunur bir dosyada geçersizdir?

Derste verilen cevap (slayttan, ekrandan, 00:15:00): istek geçersizse sıfırdan farklı bir değer döner. Salt okunur açılmış bir dosyada `fseek(fp, 1, SEEK_END)` geçersizdir, çünkü işaretçiyi dosya sonunun ötesine taşımaya çalışır. Genel kural: `SEEK_END` ile offset $\le 0$, `SEEK_SET` ile offset $\ge 0$ olmalı, işaretçi dosyanın dışına itilmemelidir.

**Soru 2** (derste sözlü, 00:41:00): `get_records` fonksiyonunda ilk `fread` ile 19 baytlık ad okunduktan sonra `offset += sizeof(PERSONALSTAT); fseek(data_file, offset, SEEK_SET);` yapılıyor. Okuma işaretçiyi zaten 19 bayt ilerlettiği için ikinci kaydın ad alanı atlanır mı?

Derste verilen cevap (01:20:47 ve 01:26:54): atlanmaz. Program çalıştırılınca kayıtlar doğru okundu. `SEEK_SET` şu anki konumdan değil dosyanın başından saydığı için, `offset` kümülatif tutulduğu sürece her `fseek` tam olarak sonraki kaydın başına gider. `ftell` izinde konum başta 0, ilk okumadan sonra 19'dur.

> **Çözüm (derste verilmedi):** Aynı satır `SEEK_CUR` ile yazılsaydı ikinci kaydın ad alanı gerçekten kayardı: konum 19'dayken 36 bayt ileri gidilir ve 55. bayttan okunurdu. `SEEK_CUR` ile doğru konuma gitmek için `fseek(data_file, sizeof(PERSONALSTAT) - NAME_LEN, SEEK_CUR)` yani 17 bayt ileri gitmek gerekirdi. `SEEK_SET` ile ajanın denemesinde konumlar 0, 19, 36→55, 72→91, 108→127 diye ilerledi.

**Soru 3** (derste sözlü, 00:30:50): Birinci programın yorum satırında, her kayıttan sonra `char *stz="\n"; fwrite(stz, 1, 1, fp);` ile dosyaya bir satır sonu yazmak seçenek olarak verilmiş. Bunun bir anlamı var mı?

Hoca derste bunun amacını çıkaramadığını, binary kayıt dosyasına yalnız bir satır sonu yazmanın kendisine mantıksız geldiğini söyledi.

> **Çözüm (derste verilmedi):** İndeksli okuma, kayıtların arka arkaya ve her birinin tam `sizeof(PERSONALSTAT)` (ajanın derlemesinde 36) bayt olmasına dayanır. Her kayıttan sonra 1 bayt `\n` yazılırsa kayıt aralığı 37 bayta çıkar. Bu durumda `get_records` ve `print_indexed_records` içindeki `index * sizeof(PERSONALSTAT)` hesabı ikinci kayıttan itibaren her kayıtta bir bayt daha geride kalır ve yanlış veri okunur; hesabın `index * (sizeof(PERSONALSTAT) + 1)` olarak değiştirilmesi gerekirdi.

**Soru 4** (derste sözlü, 01:28:34): Yapı içindeki `char *` alanına süslü parantezle ilk değer verilirse o bellek `free` edilmeli mi?

Derste verilen cevap: hayır. `free` yalnız `malloc` ile ayrılan bellek için, her `malloc`'a karşılık bir kez yapılır. `free` tek bir fonksiyondur ve tek parametresi işaretçidir.

## Dersin Toparlaması

Bu derste dosya konusu rastgele erişimle tamamlandı. `fseek` dosya konum işaretçisini `SEEK_SET`, `SEEK_CUR` ya da `SEEK_END`'e göre verilen offset kadar taşır ve başarıda 0 döndürür; `ftell` işaretçinin dosyanın başından kaçıncı baytta olduğunu söyler. İşaretçinin dosya sınırları içinde tutulması hem doğruluk hem taşınabilirlik için gereklidir. Bu iki fonksiyonla, sabit boyutlu kayıtlardan oluşan bir dosyada $n$. kayda $n \times$ `sizeof(kayıt)` baytına giderek doğrudan erişilebilir.

Uygulama olarak, dosyayı sıralamak yerine (anahtar, sıra numarası) çiftlerinden bir indeks kuran, bu indeksi `qsort` ve bir karşılaştırma fonksiyonu işaretçisiyle sıralayan ve kayıtları indeks sırasında `fseek` ile okuyan iki programlık bir örnek incelendi ve çalıştırıldı. Böylece önceki derslerde görülen bit alanlı yapılar, binary dosya G/Ç, komut satırı argümanları ve fonksiyon işaretçileri tek bir örnekte bir araya geldi. Hoca, ders konularının bununla bittiğini ve sonraki buluşmanın öğrencilerin takıldığı konular üzerine soru-cevap olacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
