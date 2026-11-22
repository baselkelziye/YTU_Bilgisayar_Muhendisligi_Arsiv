# Ders 17 Genişletilmiş Notu: Struct Sınav Sorusu: Oda Dizisi, Komşu Taraması ve Hacme Göre Sıralama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun yapısı
- 2. Sorunun metni
- 3. Hocanın soru üzerindeki açıklamaları
- 4. Kodlama kısıtları
- 5. Çözümün kurulması (derste verilmedi)
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun yapısı

Bu kayıt yaklaşık yedi dakika süren bir sınav başlangıcıdır ve içinde konu anlatımı yoktur. Hoca, struct konusunu içeren tek bir programlama sorusunu ekranda açtı, maddeleri tek tek okuyup ne istendiğini açıkladı, ardından öğrencilerin sorularını cevapladı. Sınavdan sonra o gün çözüm yapılmayacağı söylendi. Bu yüzden notun akademik içeriği sorunun kendisinden, hocanın maddeler üzerindeki açıklamalarından ve hocanın kodlama kurallarına dair uyarılarından oluşur. Soru, önceki derslerde işlenen dinamik bellek, struct dizileri ve struct takasıyla sıralama konularını bir araya getirir.

## 2. Sorunun metni

Soru ekranda şu biçimde gösterildi (ekrandan, 00:05:00):

> **3.** Bir odanın id, yükseklik, genişlik ve uzunluğu structure yapısında tutulmaktadır. Aşağıdaki fonksiyonları yazınız. Global ve statik değişken kullanmayınız. Ana programda ilave değişken tanımlamayınız.
>
> a) id, yükseklik, genişlik, uzunluk bilgilerini içeren struct'ı tanımlayınız.
>
> b) N elemanlı bir dizi oluşturmak için main fonksiyonunda kullanıcıdan N değerini alınız, bu N değerine göre dinamik bir oda structure dizisi oluşturunuz.
>
> c) `__________ GetInfo(Dinamik oda structure dizisi)`: Odalara ait bilgileri kullanıcıdan alarak b maddesinde oluşturulan dizide saklayan fonksiyonu yazınız.
>
> d) `__________ ScanRooms()`: Oda dizisini tarayarak sağ ve sol komşularından hacimce daha büyük olan odaların isimlerini ekrana yazdıran fonksiyonu yazınız. (Tarama yaparken ilk ve son odayı değerlendirme dışı bırakınız.) Hacim = genişlik X yükseklik X uzunluk
>
> e) `__________ sortbyVolume()`: Odaları hacimlerine göre sıralayan fonksiyonu yazınız. Bu aşamada orijinal oda dizisinin içeriği değiştirilmelidir.
>
> f) `__________ printInfo()`: Odaların bilgilerini id, yükseklik, genişlik, uzunluk, hacim formatında ekrana yazan fonksiyonu yazınız.
>
> g) Main fonksiyonu içinde c, d, e ve f maddelerindeki işlemleri aşağıdaki sıraya göre çağıran fonksiyon çağrılarını yazınız. Fonksiyon çağrılarından sonra dinamik olarak tahsis edilen bellek bölgesini serbest bırakan kod/kodları yazınız.
>
> a. b maddesinde oluşturulan dizi için `GetInfo()` fonksiyonunu kullanarak veri girişi yapınız. b. `ScanRooms()` fonksiyonunu çağırınız. c. `printInfo()` fonksiyonunu çağırınız. d. `sortbyVolume()` fonksiyonunu çağırınız. e. `printInfo()` fonksiyonunu çağırınız.

Fonksiyon adlarının önündeki boşluklar dönüş türünün yeridir. Kâğıttaki genel notlara göre bu boşluklar ya boş bırakılır ya da uygun biçimde doldurulur (ekrandan, 00:05:00). `ScanRooms`, `sortbyVolume` ve `printInfo` için parantezlerin içi de boş bırakılmıştır.

## 3. Hocanın soru üzerindeki açıklamaları

### 3.1 Struct ve dinamik dizi

Hoca önce odayı ifade eden bir struct tanımlanacağını, sonra `main` içinde kullanıcıdan $n$ değeri alınıp bu değere göre dinamik bir oda struct dizisi açılacağını söyledi. `GetInfo` fonksiyonuna "bu diziye uygun parametreleri ve dönüş değerini vererek" b maddesindeki diziye verilerin okunacağını belirtti.

### 3.2 Parametreleri çıkarmak

Hoca fonksiyonların hiçbirinde parametreleri yazmadığını, öğrencinin doğru bir çıkarsama yapması gerektiğini vurguladı.

> **Hocanın vurgusu:** Parametreler bilerek yazılmadı; hangi fonksiyonun neye ihtiyaç duyduğunu öğrencinin kendisi çıkarmalıdır.

Örneğin `ScanRooms` için hoca "bu oda dizisini parametre olarak alacaksınız" dedi. Dizinin eleman sayısı da fonksiyonun içinde bilinmediği için ayrıca gönderilmesi gerekir; bu, parametreleri doğru çıkarmanın bir parçasıdır (ara adım eklendi).

### 3.3 Komşu taraması

`ScanRooms` sağ ve sol komşularından hacimce büyük olan odaları yazar. Hoca bunu bir örnekle açıkladı: ikinci odanın hacmi üçüncüden büyükse ve birinciden de büyükse ikinci odanın bilgisi yazılır. Hacmin nasıl hesaplandığını ayrıca söylemeye gerek olmadığını, formülün soruda yazılı olduğunu belirtti.

**Soru:** `ScanRooms` içinde hem sağdakinden hem soldakinden büyük olanları mı yazacağız? **Cevap:** Evet, sağ ve sol komşularından büyük olanlar yazılır.

Hoca ardından sınır durumunu açıkladı: birinci odanın solunda, sonuncu odanın sağında komşu olmadığı için bu iki oda dikkate alınmaz ve ekrana yazılmaz.

### 3.4 "Odanın ismi" ne demek?

Hoca, odaların isimlerini yazdıran fonksiyonla (`ScanRooms`) odaların bilgilerini yazdıran fonksiyonun (`printInfo`) karıştırılabileceğini söyledi. Odanın isminden kastedilen id'dir: "3 numaralı oda", "5 numaralı oda" gibi. `ScanRooms` yalnız id'yi yazar; id, yükseklik, genişlik ve uzunluğun hepsi `printInfo` içinde yazılır.

### 3.5 Sıralama ve çağrı sırası

`sortbyVolume` odaları hacimlerine göre sıralar ve orijinal dizinin, yani `main`'de açılan dizinin içeriği değişir. Yeni bir dizi oluşturulmaz. `main` içindeki sıra: veri girişi, `ScanRooms`, `printInfo`, `sortbyVolume`, tekrar `printInfo`. Son olarak ilgili bellek bölgesi serbest bırakılır. Böylece iki `printInfo` çıktısı karşılaştırılarak sıralamanın etkisi görülebilir.

<!-- BELİRSİZ: Sıralamanın artan mı azalan mı olacağı ne ekranda ne altyazıda belirtiliyor. -->

## 4. Kodlama kısıtları

Kâğıdın üstündeki genel notta bütün sorularda global değişken kullanımının, döngü içinde `break` ve `continue` ile `goto` kullanımının yasak olduğu yazıyordu (ekrandan, 00:05:00). Soru metni buna statik değişken yasağını ve `main` içinde ilave değişken tanımlamama kuralını ekler. Bu kısıt, `main`'in yalnız $n$ ve dizinin adresini tutan işaretçiyle yazılmasını, diğer bütün işin fonksiyonlara parametre geçirerek yapılmasını zorlar.

Hoca ayrıca iki derleyici uyumu uyarısı yaptı:

- Döngü değişkeni `for` içinde tanımlanmamalıdır. `for (int i = 0; i < n; i++)` yerine `int i;` döngüden önce yazılmalı, döngü `for (i = 0; i < n; i++)` biçiminde kurulmalıdır. Başka bir derleyici kullanılıp kullanılamayacağı sorusuna hoca "olur" dedi, ama kodun Dev-C++ ya da Code::Blocks üzerinde derlenip çalışması gerektiğini, bir ortamda derlenen `for` içi tanımın başka ortamda derlenmeyebileceğini söyledi.
- C++ kodu yazılmamalıdır; kod C olmalıdır.

<!-- BELİRSİZ: Öğrencinin sorduğu derleyicinin adı altyazıda bozuk geçiyor ("Zee Pulse"). -->

> **Ek bilgi (derste anlatılmadı):** Döngü başlığında değişken tanımlamak C99 standardıyla gelen bir özelliktir. C89/C90 kipinde derleyen ya da eski ayarlı bir derleyici bu yazımı hata olarak görür. Değişkeni döngüden önce tanımlamak her iki standartta da geçerlidir. `.c` uzantılı dosyanın C derleyicisiyle, `.cpp` uzantılının C++ derleyicisiyle derlenmesi de büyük olasılıkla bu uyarının arka planındadır.

## 5. Çözümün kurulması (derste verilmedi)

Derste sorunun çözümü yapılmadı. Aşağıdaki çözüm ajan tarafından yazıldı. Kısıtlara uyar: global ya da statik değişken yok, döngülerde `break`, `continue`, `goto` yok, döngü değişkenleri döngüden önce tanımlanmış, `main`'de yalnız `n` ve `rooms` var.

### 5.1 Tasarım kararları

- Dönüş türleri: `GetInfo`, `ScanRooms`, `sortbyVolume` ve `printInfo` diziyi adresinden aldığı için `void` olabilir. `GetInfo` diziyi doldurur, `sortbyVolume` yerinde sıralar; ikisi de çağıranın dizisini doğrudan değiştirir.
- Parametreler: her fonksiyon `ROOM *rooms` ve `int n` alır.
- Hacim hesabı tek bir yardımcı fonksiyonda (`volume`) toplandı. Boyutlar için `float` seçildi; soru türü belirtmiyor.
- `ScanRooms` döngüsü `i = 1` ile başlar ve `i < n - 1` iken döner. Böylece ilk ve son oda değerlendirme dışı kalır, `rooms[i-1]` ve `rooms[i+1]` erişimleri dizinin içinde kalır.
- `sortbyVolume` kabarcık sıralamasıyla artan hacim sırası üretir; takas bütün struct'ı `tmp` üzerinden kopyalar.
- `calloc` sonucunun `NULL` olup olmadığı denetlenir.

### 5.2 Kod

Kod `gcc -Wall -std=c89 -pedantic` ile uyarısız derlendi ve aşağıdaki girdiyle çalıştırıldı.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct room {
    int id;
    float height, width, length;
} ROOM;

float volume(ROOM r) {
    return r.width * r.height * r.length;
}

void GetInfo(ROOM *rooms, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d. oda (id yukseklik genislik uzunluk): ", i + 1);
        scanf("%d %f %f %f", &rooms[i].id, &rooms[i].height,
              &rooms[i].width, &rooms[i].length);
    }
}

void ScanRooms(ROOM *rooms, int n) {
    int i;
    for (i = 1; i < n - 1; i++) {
        if (volume(rooms[i]) > volume(rooms[i - 1]) &&
            volume(rooms[i]) > volume(rooms[i + 1])) {
            printf("Komsularindan buyuk oda: %d\n", rooms[i].id);
        }
    }
}

void sortbyVolume(ROOM *rooms, int n) {
    int i, j;
    ROOM tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (volume(rooms[j]) > volume(rooms[j + 1])) {
                tmp = rooms[j];
                rooms[j] = rooms[j + 1];
                rooms[j + 1] = tmp;
            }
        }
    }
}

void printInfo(ROOM *rooms, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("id=%d yukseklik=%.2f genislik=%.2f uzunluk=%.2f hacim=%.2f\n",
               rooms[i].id, rooms[i].height, rooms[i].width,
               rooms[i].length, volume(rooms[i]));
    }
}

int main() {
    int n;
    ROOM *rooms;
    printf("Oda sayisi: ");
    scanf("%d", &n);
    rooms = (ROOM *)calloc(n, sizeof(ROOM));
    if (rooms == NULL) {
        printf("Bellek ayrilamadi\n");
        return 1;
    }
    GetInfo(rooms, n);
    ScanRooms(rooms, n);
    printInfo(rooms, n);
    sortbyVolume(rooms, n);
    printInfo(rooms, n);
    free(rooms);
    return 0;
}
```

### 5.3 Deneme

Girdi: $N = 5$; odalar (id, yükseklik, genişlik, uzunluk) sırasıyla (1, 2, 3, 4), (2, 3, 3, 3), (3, 1, 1, 1), (4, 2, 2, 5), (5, 1, 2, 2).

- Hacimler: $2 \cdot 3 \cdot 4 = 24$, $3 \cdot 3 \cdot 3 = 27$, $1$, $2 \cdot 2 \cdot 5 = 20$, $1 \cdot 2 \cdot 2 = 4$.
- `ScanRooms` yalnız 2., 3. ve 4. sıradaki odalara bakar. 2 numaralı oda: $27 > 24$ ve $27 > 1$, yazılır. 3 numaralı oda: $1$ komşularından küçük, yazılmaz. 4 numaralı oda: $20 > 1$ ve $20 > 4$, yazılır.
- Sıralama sonrası id sırası: 3, 5, 4, 1, 2 (hacimler 1, 4, 20, 24, 27).

Program çıktısı bu sonuçlarla aynıdır.

## Örnek Sorular

### Soru 1: Oda struct dizisi (ekrandan, 00:05:00)

Bir odanın id, yükseklik, genişlik ve uzunluğu struct yapısında tutulur. Global ve statik değişken kullanmadan, `main` içinde ilave değişken tanımlamadan: struct'ı tanımlayın; `main`'de kullanıcıdan $N$ alıp dinamik oda dizisi açın; `GetInfo` ile verileri okuyun; `ScanRooms` ile sağ ve sol komşusundan hacimce büyük odaların id'lerini yazın (ilk ve son oda hariç, hacim = genişlik × yükseklik × uzunluk); `sortbyVolume` ile diziyi yerinde hacme göre sıralayın; `printInfo` ile id, yükseklik, genişlik, uzunluk ve hacmi yazın. `main` içinde sırasıyla `GetInfo`, `ScanRooms`, `printInfo`, `sortbyVolume`, `printInfo` çağrılıp bellek serbest bırakılır. Fonksiyonların dönüş türleri ve parametreleri öğrenci tarafından belirlenir.

> **Çözüm (derste verilmedi):** Bölüm 5.2'deki kod. Dönüş türleri `void`, parametreler `(ROOM *rooms, int n)`. `ScanRooms` döngüsü `for (i = 1; i < n - 1; i++)` sınırlarıyla kurulur; `sortbyVolume` struct takasıyla yerinde sıralar. Beş odalık denemede `ScanRooms` 2 ve 4 numaralı odaları yazar, sıralamadan sonra id sırası 3, 5, 4, 1, 2 olur.

### Soru 2: Komşu taraması (derste sözlü, 00:04:13)

`ScanRooms` içinde bir oda hem sağdakinden hem soldakinden büyükse mi yazılır?

> **Cevap (derste verildi):** Evet. Her iki komşudan da hacimce büyük olan oda yazılır; ilk ve son oda bir komşusu eksik olduğu için yazılmaz.

## Dersin Toparlaması

Bu oturumda yeni bir konu anlatılmadı; struct ve dinamik bellek konularını birleştiren bir sınav sorusu açıklandı. Sorunun özü, bir struct dizisini çalışma zamanında açmak, diziyi adresiyle fonksiyonlara geçirip doldurmak, taramak, yerinde sıralamak ve yazdırmak, sonunda belleği bırakmaktır. Hocanın açıklamalarından çıkan önemli noktalar şunlardır: parametreler ve dönüş türleri sorunun gereğinden çıkarılmalıdır, komşu taramasında uç elemanlar dışarıda kalır, "odanın ismi" id anlamına gelir, sıralama orijinal diziyi değiştirir ve kod C89 uyumlu biçimde (döngü değişkeni döngüden önce tanımlanarak) yazılmalıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
