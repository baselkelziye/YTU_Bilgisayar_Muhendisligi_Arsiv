# Ders 11 Genişletilmiş Notu: Uygulama 2: Dizi ve Matris Soruları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulama oturumunun işleyişi
- 2. Soru 1: Dizinin tersini bulma
- 3. Dizi boyutu, makrolar ve önişlemci
- 4. Soru 2: Çoğunluk elemanı, basit yaklaşım
- 5. Soru 3: Moore'un oylama algoritması
- 6. Soru 4: Matrisin transpozu
- 7. Soru 5 ve 6: Binary matrisin simetrik olması için gereken değişiklik sayısı
- 8. Soru 7: Matrisin spiral formunun c. elemanı
- Örnek Sorular
- Dersin Toparlaması

## 1. Uygulama oturumunun işleyişi

Bu kayıt dersin ikinci uygulama oturumudur ve slayt dosyasının adı da "Uygulama-2"dir (ekrandan, 00:10:00). Oturumda yedi soru çözüldü. Her soruda aynı düzen izlendi: önce soru slaytta açıklandı, sonra öğrencilere birkaç dakika verildi ve kendi başlarına denemeleri istendi, bitirenler sohbet kutusuna yazdı; ardından çözüm Dev-C++ üzerinde birlikte yazıldı ve çalıştırıldı. Çözümlerin herhangi bir yere yüklenmeyeceği, amacın yalnızca kendini denemek olduğu belirtildi; önce kendi başına denemenin çözümü daha iyi anlamayı sağladığı söylendi.

Sorular iki gruptan oluşur. İlk üç soru tek boyutlu dizilerle ilgilidir: diziyi ters çevirmek ve çoğunluk elemanını iki farklı yolla bulmak. Son dört soru iki boyutlu matrislerle ilgilidir: transpoz, binary matrisin simetrik hâle gelmesi için gereken değişiklik sayısı (basit ve verimli çözüm) ve matrisin spiral biçimde taranması. Ortak tema, aynı problemi önce en basit yolla, sonra daha az bellek ya da daha az işlem kullanarak çözmektir.

## 2. Soru 1: Dizinin tersini bulma

### 2.1 Problem

Slayttaki soru şudur (ekrandan, 00:10:00):

- Dizinin ters versiyonunu bulunuz.
- Kullanıcıdan dizi boyutu alınmalı.
- Kullanıcıdan dizi elemanları alınmalı.

Slayttaki örnekte `6 3 1 4 2 9` dizisi `9 2 4 1 3 6` dizisine dönüşür.

### 2.2 Çözüm fikri: ek dizi yerine iki indis

Süre bitince öğrencilere ekstra bir dizi mi kullandıkları, yoksa işlemi aynı dizi üzerinde mi yaptıkları soruldu. Ayrı bir dizi kullanıp sondan başa doğru eleman aktarmak doğru sonuç verir, ama ikinci bir dizi kadar ek bellek harcar. Bunun yerine iki indis tutulabilir: dizinin başını gösteren `start` ve sonunu gösteren `end`. Bu iki konumdaki elemanlar yer değiştirilir (swap), sonra `start` bir artırılır, `end` bir azaltılır ve bir içerideki çifte geçilir.

Slayttaki gösterim `1 2 3 4 5 6` dizisi üzerindedir (ekrandan, 00:20:00):

- 1. adım: `start = 0`, `end = 5`; 1 ile 6 yer değiştirir, dizi `6 2 3 4 5 1` olur.
- 2. adım: `start = 1`, `end = 4`; 2 ile 5 yer değiştirir, dizi `6 5 3 4 2 1` olur.
- 3. adım: `start = 2`, `end = 3`; 3 ile 4 yer değiştirir, dizi `6 5 4 3 2 1` olur.
- Artık `start = 3`, `end = 2` olur; `start` `end`'i geçtiği için bütün çiftler işlenmiştir ve döngü biter.

Yani döngü `start < end` olduğu sürece çalışır; `start`, `end`'e eşit ya da ondan büyük olunca durur.

### 2.3 Program

Program her zamanki gibi `stdio.h` eklenerek başlar. Dinamik bellek ayırma henüz işlenmediği için dizinin alabileceği en büyük boyut bir makroyla tanımlanır: `#define MAX_Length 50`. Dizi bu boyutla tanımlanır, kullanıcıdan asıl boyut `n` alınır. Swap için en basit yol bir geçici değişken (`temp`) kullanmaktır; ayrıca bir döngü değişkeni `i` gerekir.

Boyutun sınırı aşmadığından emin olmak için `if` de kullanılabilir, ama burada `do-while` tercih edildi: kullanıcı `MAX_Length`'ten büyük bir değer girerse döngüden çıkamaz ve boyut yeniden sorulur. Derste genelde `do-while` yerine `while` kullanıldığı, burada bu kalıbın kullanıcıdan geçerli bir değer almak için uygun olduğu belirtildi.

`scanf` ile okurken değişkenin değeri değil adresi gerekir; bu yüzden değişkenin başına `&` konur. Elemanlar okunurken her `scanf` öncesinde kullanıcıya ne gireceğini söyleyen bir mesaj basılır. Mesajda `i` yerine `i+1` yazılarak elemanlar 1'den numaralandırıldı; ikisi de olur.

> **Hocanın vurgusu:** Okuma yapılacak her yerde bir `printf` mesajı olmalı. Hiç mesaj basmayan bir program çalıştırıldığında ekrana hiçbir şey gelmez ve kullanıcı programın ne beklediğini anlayamaz. Kullanıcı ne gireceğini görmeli.

Ekrandaki kodun ilk 33 satırı aşağıdaki gibidir (ekrandan, 00:30:00); son kısım anlatıma göre tamamlanmıştır. Program `gcc -Wall` ile derlendi ve `6 3 1 4 2 9` girdisiyle `9 2 4 1 3 6` çıktısı alındı.

```c
#include<stdio.h>

#define MAX_Length 50

int main(){

    int arr[MAX_Length], n;
    int start, end, temp, i;

    do{
        printf("Enter the of array:");
        scanf("%d", &n);
    }while(n > MAX_Length );

    printf("Enter the elements:\n");

    for(i=0;i<n;i++){
        printf("element[%d]:", i+1);
        scanf("%d", &arr[i]);
    }

    start = 0;
    end= n-1;

    while(start < end){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    printf("Reversed array: ");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
```

<!-- BELİRSİZ: 33. satırdan sonrası (end--, sonuç döngüsü ve "Reversed array" mesajı) karede görünmüyor; anlatıma göre yazıldı. -->

`end`'in başlangıç değeri `n-1`'dir, çünkü `n` elemanlı dizinin son indisi `n-1`'dir. Tek satırlık döngü gövdelerinde süslü parantez gerekmese de, sonradan ekleme yaparken hata olmasın diye parantezi hemen koymanın iyi bir alışkanlık olduğu söylendi. Sonuç yazdırılırken elemanlar arasına boşluk konursa çıktı daha okunaklı olur.

### 2.4 Aynı çözüm `for` ile

**Soru:** Aynı işlem `while` yerine `for` ile nasıl yapılır? **Cevap:** İki değişkenli bir `for` yazılabilir: başlatma kısmında `start=0, end=n-1`, koşulda `start < end`, artırma kısmında `start++, end--`. Ekranda bu satır şöyle yazıldı (ekrandan, 00:30:00):

```c
for(start=0, end=n-1; start <end; start++, end--)
```

Bir öğrenci tek indisle, `arr[i]` ile `arr[n-i-1]`'i yer değiştirerek denediğini, ama ortadaki elemanlarda hata aldığını söyledi. Bu yaklaşımın da doğru olduğu, ancak döngünün bir eksik çalışması gerektiği belirtildi; başka bir öğrenci de döngüyü `n/2`'ye kadar (küçüktür ile) çalıştırınca doğru sonuç aldığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Tek indisli çözümde döngü `i < n/2` olmalıdır. Döngü `n`'ye kadar giderse her çift iki kez yer değiştirir ve dizi eski hâline döner; `i <= n/2` yazılırsa çift uzunluklu dizide ortadaki çift iki kez değişir. `for(i=0;i<n/2;i++)` ile `arr[i]` ve `arr[n-i-1]` yer değiştirildiğinde hem tek hem çift uzunlukta doğru sonuç çıkar (5 ve 6 elemanlı dizilerle denendi).

### 2.5 Tersten yazdırmak yetmez mi?

Bir öğrenci sohbete, diziyi tersten okuyup doğrudan yazdırmanın da olacağını yazdı. Cevap: istenen bazen yalnızca `printf` ile gösterilebilir, ama genellikle sonucun elde, yani bellekte tutulması beklenir. Bir sorudan bir şey isteniyorsa genelde bu şekilde, dizinin kendisinin dönüştürülmesi olarak istenir.

## 3. Dizi boyutu, makrolar ve önişlemci

### 3.1 Boyutu kullanıcıdan alıp diziyi sonra tanımlamak

**Soru:** Diziyi `MAX_Length` ile tanımlamak yerine, önce kullanıcıdan `n`'yi alıp diziyi `n` elemanlı tanımlamak daha iyi olmaz mıydı? **Cevap:** Derste ilk olarak bunun dinamik bellek ayırmadan yapılamayacağı söylendi: program, boyutunu bilmediği bir diziyi hazırlayamaz; dinamik bellek ayırmanın amacı da çalışma sırasında (runtime) bellek ayırmaktır. Öğrenci `n`'yi `scanf` ile okuyup diziyi ondan sonra tanımladığını ve programın çalıştığını söyleyince, bunun yapılabileceği, söylenmek istenenin boyuta hiç değer vermeden dizi tanımlanamayacağı açıklandı. Ekranda bir an `int n, arr[n];` yazılarak bu durum gösterildi (ekrandan, 00:35:00).

Yine de bu yolun tercih edilmeme nedeni, sabit değerlerin programlamada makro olarak tanımlanması gerektiğidir. Dinamik bellek ayırma öğrenildikten sonra boyutu kullanıcıdan alıp tam o kadar yer ayırmak mümkün olacak ve bu sabit boyut yaklaşımına gerek kalmayacak.

**Soru:** Kullanıcının girebileceği boyut milyonlara çıkabilirse, en büyük boyutu ayırmak çok gereksiz yer harcamaz mı? Kullanıcı yalnızca 5 eleman girebilir. **Cevap:** Evet, şu anda gereksiz yer ayrılıyor; örneğin 5 eleman girildiğinde 50 elemanlık yer ayrılmış oldu. Bunun nedeni dinamik bellek ayırmanın henüz bilinmemesidir. Dinamik bellek ayırma tam da bu yüzden vardır: kullanıcı kaç eleman istiyorsa o kadar yer ayrılır.

> **Ders sonrası not:** Derste önişlemcinin (preprocessor) "ilk iş olarak bellekte yer ayırdığı" ve boyutun "dinamik bellek ayırmadan" kullanıcıdan alınamayacağı söylendi. Doğrusu: önişlemci yalnızca metin yerleştirmesi yapar, bellek ayırmaz; sabit boyutlu bir yerel dizinin boyutu derleme sırasında bilinir ve yeri fonksiyon çalışmaya başladığında ayrılır. C99 standardından beri boyutu çalışma anında belli olan diziler (variable length array) de tanımlanabilir: `scanf("%d", &n);` satırından sonra yazılan `int arr[n];` geçerlidir (`gcc -Wall -std=c99` ile denendi). Hatalı olan, ekranda bir an görünen `int n, arr[n];` gibi `n`'ye değer verilmeden dizinin tanımlanmasıdır.

### 3.2 Makro nedir, neden noktalı virgül konmaz?

Makrodan söz açılmışken öğrencilere `#define` satırının sonuna neden noktalı virgül konmadığı soruldu. Bir öğrenci makroyu hatırlamadığını söyleyince kısaca anlatıldı.

Makrolar sabit değerleri tanımlamak için kullanılır. Kütüphane ekler gibi `#` işaretiyle başlanır, küçük harfle `define` yazılır, yanına bir ad ve o adın yerine geçecek değer yazılır. Program derlenmeden önce önişlemci bu adı gördüğü her yere yanındaki değeri yerleştirir. Örneğin `MAX_Length` yazılan her yere aslında `50` konur; derleyici bunu bir değişken adı olarak değil, doğrudan 50 olarak görür.

Satır sonuna noktalı virgül konsaydı, önişlemci yalnızca yerleştirme yaptığı için noktalı virgülü de değerle birlikte her yere koyardı; bu da anlamsız bir kod üretirdi. Bu yüzden adın yanına yalnızca yerine ne gelmesi gerekiyorsa o yazılır.

**Soru:** Makronun veri tipi belirleniyor mu, yoksa kullanıldığı yere göre mi ayarlanıyor? **Cevap:** Makronun veri tipi yoktur. Önişlemci yalnızca adı görür ve adı gördüğü yere yanında ne varsa onu koyar. Bu yüzden `int`, `double`, `float` gibi tip adları `#define` satırına yazılmaz. String de tanımlanabilir; string tırnak işareti içinde yazılır.

Ekranda bunu göstermek için makronun değeri silinip dizi boyutuna doğrudan 50 yazıldı (ekrandan, 00:40:00). Makroların fonksiyon biçiminde de yazılabildiği ve hata ayıklamada (debug) kullanılabildiği, bunların başka bir uygulamada ayrıntılı işlenebileceği söylendi.

> **Ek bilgi (derste anlatılmadı):** `#define MAX_Length 50;` yazılsaydı `int arr[MAX_Length];` satırı önişlemciden sonra `int arr[50;];` olurdu ve derleme hatası verirdi. Fonksiyon benzeri makrolara örnek `#define KARE(x) ((x)*(x))` biçimidir; burada da yalnızca metin yerleştirmesi yapılır.

## 4. Soru 2: Çoğunluk elemanı, basit yaklaşım

### 4.1 Problem ve tanım

Slayttaki soru (ekrandan, 00:45:00):

- Dizinin Majority Element'inin (çoğunluk elemanının) bulunması.
- Majority Element: dizi boyutunun yarısından fazla ($> n/2$) sayıda dizi içerisinde bulunan eleman.

Slayttaki örnekler:

- Girdi `3 3 1 3 2 3 6 3`; çıktı "Majority Element: 3". Dizi 8 elemanlıdır, yarısı 4'tür; 3 beş kez geçtiği için ($5 > 4$) çoğunluk elemanıdır.
- Girdi `3 3 1 4 2`; çıktı "No Majority Element". Dizi 5 elemanlıdır, yarısı 2,5'tir; en az 3 kez geçen bir eleman gerekir. 3 iki kez, diğerleri birer kez geçtiği için çoğunluk elemanı yoktur.

Girdiler yine önceki soru gibi kullanıcıdan alınır; boyut ve elemanlar kullanıcı tarafından verilir, ama baştan bir en büyük uzunluk belirlenir.

### 4.2 Basit yaklaşım: her elemanın frekansı

Slayttaki basit yaklaşım $O(n \cdot n)$ karmaşıklığındadır (ekrandan, 00:55:00):

- Her bir elemanın frekansını bul.
- Her iterasyonda maksimum frekans sayısını güncelle.
- Maksimum frekans sayısı $> n/2$ kontrol et.

Bu, baştan bir histogram oluşturmak gibi düşünülebilir. Her eleman için frekans sayılır ve o ana kadarki en büyük frekans bir değişkende tutulur. En sonda bulunan en büyük frekans dizi boyutunun yarısından fazlaysa çoğunluk elemanı odur, değilse çoğunluk elemanı yoktur.

Gereken değişkenler şunlardır: her elemanın frekansı için `count`, en büyük frekans için `maxCount` (başlangıçta 0), iki döngü değişkeni `i` ve `j`, ve en büyük frekansa sahip elemanın yerini bildirmek için `index`. `index` -1 ile başlatılır, çünkü dizide hiçbir elemanın indisi negatif olamaz; böylece başlangıç değeri hiçbir gerçek indisle karışmaz. Ekrandaki tanım satırı şudur (ekrandan, 00:50:00):

```c
int count, maxCount = 0, i, j, index = -1;
```

Dış döngü her eleman için çalışır. Yeni bir elemana geçildiğinde onun frekansı da sıfırdan başlamalıdır; bu yüzden `count` her dış döngü adımında sıfırlanır. İç döngü bütün diziyi tarar ve elemana eşit olan her konumda `count` bir artar. İç döngü bitince o elemanın dizideki frekansı bulunmuş olur. Bu frekans `maxCount`'tan büyükse çoğunluk elemanı bu olabilir: `maxCount`'a bu frekans, `index`'e bu elemanın indisi atanır. Dış döngü bitince `maxCount > n/2` kontrol edilir; doğruysa `arr[index]` yazdırılır, değilse çoğunluk elemanı olmadığını söyleyen bir mesaj verilir.

Aşağıdaki program ekrandaki ilk 20 satıra (ekrandan, 00:50:00) ve anlatıma göre yazılan döngülere dayanır; döngü kısmı karede görünmüyor. `gcc -Wall` ile derlendi ve slayttaki iki girdiyle denendi: ilki "Majority Element: 3", ikincisi "No Majority Element" verdi.

```c
#include<stdio.h>

#define MAX_Length 50

int main(){

    int n, arr[MAX_Length];
    int count, maxCount = 0, i, j, index = -1;

    do{
        printf("Enter the of array:");
        scanf("%d", &n);
    }while(n > MAX_Length );

    printf("Enter the elements:\n");

    for(i=0;i<n;i++){
        printf("element[%d]:", i+1);
        scanf("%d", &arr[i]);
    }

    for(i=0;i<n;i++){
        count = 0;
        for(j=0;j<n;j++){
            if(arr[i] == arr[j])
                count++;
        }
        if(count > maxCount){
            maxCount = count;
            index = i;
        }
    }

    if(maxCount > n/2)
        printf("Majority Element: %d\n", arr[index]);
    else
        printf("No Majority Element\n");

    return 0;
}
```

<!-- BELİRSİZ: Yazdırma mesajlarının ekrandaki tam metni karelerde görünmüyor; slayttaki çıktı metinleri kullanıldı. -->

Derste program, beş elemanlı ve üç tanesi 3 olan bir girdiyle denendi ve 3 bulundu; sonra 3'ün yalnız iki kez geçtiği bir girdiyle denendi ve çoğunluk elemanı olmadığı mesajı alındı. $n = 5$ için `n/2` tamsayı bölmesiyle 2'dir; `count > 2` koşulu "en az 3 kez" anlamına gelir, yani tanımdaki $> 2{,}5$ ile aynı sonucu verir.

### 4.3 Başka çözümler

Bu sorunun birçok çözümü olduğu ve internette kolayca bulunabileceği söylendi. Öğrencilere kaç karmaşıklıkta çözdükleri soruldu. Bir öğrenci, iç içe döngü kullanmadan, dizideki en büyük eleman boyutunda bir sayma dizisi kullanarak yaklaşık $3n$ işlemle çözdüğünü söyledi.

## 5. Soru 3: Moore'un oylama algoritması

### 5.1 Fikir

Slayttaki soru "2. soruyu daha verimli bir yol ile çözünüz!" biçimindedir ve yöntem olarak Moore's Voting Algorithm verilmiştir (ekrandan, 01:05:00):

- Aday major element belirle.
- Sadece adayın frekansını hesapla.
- Major eleman olmama olasılığı için $n/2$'den büyük olup olmadığını kontrol et.

Basit yaklaşımda bütün elemanların frekansı hesaplanıyordu. Oylama algoritması ise önce tek bir aday belirler ve yalnızca bu adayın frekansını hesaplar. Aday bulunduktan sonra frekansın yeniden sayılmasının nedeni, dizide hiç çoğunluk elemanı olmayabilmesidir; algoritma her durumda bir aday üretir, ama bu adayın gerçekten çoğunluk elemanı olduğunu yalnızca frekans kontrolü garanti eder.

### 5.2 İşleyiş

Slaytta kırmızı ok çoğunluk adayının indisini (`majorityIndex`), siyah ok döngü değişkenini (`i`) gösterir. Kurallar şunlardır:

- Aday indisi dizinin ilk elemanına konur. Karşılaştırma yapılacağı için döngü değişkeni ikinci elemandan başlar.
- Sayaç 1'den başlar.
- Aday ile döngünün gösterdiği eleman eşitse sayaç bir artar, değilse bir azalır.
- Sayaç 0 olursa, adayın o ana kadarki kısmı denenmiş sayılır: aday indisi döngü değişkeninin olduğu yere getirilir ve yeni bir aday denendiği için sayaç yeniden 1 yapılır.

Sayacın 0'dan değil 1'den başlamasının nedeni şudur: eşitsizlikte azaltma yapıldığı için sayaç 0'dan başlasaydı ve ilk elemanlar eşit olmasaydı sayaç negatife düşerdi. Algoritma yalnızca sayacın sıfır olup olmadığını kontrol ettiği için negatif değerlerle uğraşmamak adına sayaç 1'den başlatılır.

### 5.3 Adım adım örnek

Slayttaki dizi `3 3 1 3 2 6 3 3`'tür (ekrandan, 00:55:00). Aday ilk eleman (indis 0, değer 3), sayaç 1'dir.

- `i = 1`, değer 3: 3 = 3, sayaç 2 olur. Sıfır değil, devam.
- `i = 2`, değer 1: 3 ≠ 1, sayaç 1 olur. Sıfır değil, devam.
- `i = 3`, değer 3: 3 = 3, sayaç 2 olur.
- `i = 4`, değer 2: 3 ≠ 2, sayaç 1 olur.
- `i = 5`, değer 6: 3 ≠ 6, sayaç 0 olur. Sayaç sıfır olduğu için aday indisi 5'e (değer 6) taşınır, sayaç 1 yapılır.
- `i = 6`, değer 3: 6 ≠ 3, sayaç 0 olur. Aday indisi 6'ya (değer 3) taşınır, sayaç 1 yapılır.
- `i = 7`, değer 3: 3 = 3, sayaç 2 olur. Dizi bittiği için döngüden çıkılır.

Aday 3'tür. Sonra 3'ün dizideki frekansı sayılır: 5. $5 > 8/2 = 4$ olduğu için 3 çoğunluk elemanıdır. (Bu izleme python ile ve aşağıdaki programla doğrulandı.)

### 5.4 Program

Değişkenler: aday indisi (`majorityIndex`, kırmızı ok), döngü değişkeni (`i`, siyah ok), sayaç ve aday değeri (`candidate`). Boyut ve elemanlar önceki gibi okunur, aday indisi 0'dan, sayaç 1'den başlatılır. Döngü `i = 1`'den son elemana kadar ilerler. Aday belirlendikten sonra sayaç sıfırlanır, dizinin tamamında adaya eşit olanlar sayılır ve sonuç `n/2` ile karşılaştırılır.

Aşağıdaki program karede görünmüyor; anlatıma göre yazılmış, `gcc -Wall` ile derlenmiş ve slayttaki üç dizide basit çözümle aynı sonuçları vermiştir.

```c
#include<stdio.h>

#define MAX_Length 50

int main(){

    int n, arr[MAX_Length];
    int majorityIndex, i, count, candidate;

    do{
        printf("Enter the of array:");
        scanf("%d", &n);
    }while(n > MAX_Length );

    printf("Enter the elements:\n");

    for(i=0;i<n;i++){
        printf("element[%d]:", i+1);
        scanf("%d", &arr[i]);
    }

    majorityIndex = 0;
    count = 1;
    for(i=1;i<n;i++){
        if(arr[majorityIndex] == arr[i])
            count++;
        else
            count--;

        if(count == 0){
            majorityIndex = i;
            count = 1;
        }
    }
    candidate = arr[majorityIndex];

    count = 0;
    for(i=0;i<n;i++){
        if(arr[i] == candidate)
            count++;
    }

    if(count > n/2)
        printf("Majority Element: %d\n", candidate);
    else
        printf("No Majority Element\n");

    return 0;
}
```

Bu algoritmada iç içe döngü yoktur; diziyi iki kez baştan sona dolaşır ve karmaşıklığı $O(n)$'dir. Derste, algoritmanın çok sayıda `if-else` içerdiği ve `if-else` komutlarının programı yavaşlatabileceğinin de düşünülmesi gerektiği söylendi.

Yazdırma sırasında yeniden hatırlatıldı: `printf` ile değişkenin değeri yazdırıldığı için yalnızca adı yazılır; `scanf` ise adrese yazma yaptığı için `&` kullanılır.

> **Ek bilgi (derste anlatılmadı):** Algoritmanın doğru çalışmasının sezgisi şudur: farklı iki elemanın birbirini "götürmesi" gibi düşünülebilir. Çoğunluk elemanı $n/2$'den fazla kez geçtiği için bütün eşleşmelerden sonra geriye kalan aday mutlaka odur. Çoğunluk elemanı yoksa kalan aday rastgele bir eleman olabilir; ikinci geçişteki frekans kontrolü bu yüzden zorunludur.

Bu tür C sorularının internette çok sayıda bulunduğu ve oradan da çalışılmasının tavsiye edildiği söylendi.

## 6. Soru 4: Matrisin transpozu

### 6.1 Problem

Slayttaki soru (ekrandan, 01:10:00):

- Matrisin transpozunu bulunuz.
- Matris boyutu $M \times N$ kullanıcıdan alınmalı.
- Matris elemanları kullanıcıdan alınmalı.

Matrisin kare olması gerekmez. Slayttaki örnek:

$$
\begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \\ 7 & 8 & 9 \end{bmatrix}
\rightarrow
\begin{bmatrix} 1 & 4 & 7 \\ 2 & 5 & 8 \\ 3 & 6 & 9 \end{bmatrix}
$$

### 6.2 Öğrenci çözümü ve tartışma

Bir öğrenci, ayrı bir matris tutmadan `temp` değişkeniyle `a[i][j]` ile `a[j][i]`'nin yerini değiştirdiğini anlattı. Bütün matris taranarak bu yapılırsa her çift iki kez değişir ve eski hâline döner; öğrencinin bunu fark edip yalnızca matrisin yarısında değişim yaptığı anlaşıldı.

> **Ek bilgi (derste anlatılmadı):** Yerinde (aynı matris üzerinde) değişim yalnızca kare matrislerde doğrudan çalışır, çünkü $M \neq N$ ise transpozun boyutu değişir ve elemanlar aynı dizinin sınırlarına sığmaz. Kare matriste döngü yalnızca köşegenin bir tarafında (`j < i`) dolaşmalıdır.

Transpozda indisler tamamen yer değiştirir: orijinal matristeki `(i, j)` konumundaki eleman transpozda `(j, i)` konumuna geçer.

### 6.3 Program

İki boyut gerekir: satır ve sütun. Bunlar iki makro olarak tanımlandı: `R` ve `C`. Orijinal matris `a[R][C]` olarak tanımlanır. Transpoz matrisi tanımlanırken dikkat edilecek nokta boyutların ters verilmesidir: `T[C][R]`. Ayrıca kullanıcıdan alınacak asıl boyutlar `m` (satır) ve `n` (sütun) ile döngü değişkenleri gerekir. Boyutlar yine `do-while` ile alınır; `m`, `R`'den ya da `n`, `C`'den büyükse ikisi birden yeniden istenir. İstenirse buraya ayrı `if`'ler eklenip geliştirilebileceği belirtildi.

Elemanlar iç içe döngüyle satır satır okunur; okunaklı olsun diye her eleman için `element[i][j]` biçiminde bir mesaj basılır. Transpozu bulmadan önce matris ekrana yazdırılır, çünkü matrisin görüntüsü sonraki sorularda da işe yarar. İçteki döngü bitince bir alt satıra geçmek için `\n` basılır.

Ekrandaki program şöyledir (ekrandan, 01:20:00 ve 01:30:00). `gcc -Wall` ile derlendi; 3x3 `1..9` girdisi slayttaki çıktıyı, 2x3 `1..6` girdisi 3x2 transpozu (`1 4 / 2 5 / 3 6`) verdi.

```c
#include<stdio.h>

#define R 10
#define C 10

int main(){

    int a[R][C], T[C][R], m, n;
    int i,j;

    do{
        printf("Enter the row size");
        scanf("%d", &m);
        printf("Enter the column size");
        scanf("%d", &n);

    }while(m > R || n > C);

    printf("Enter the elements");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("element[%d][%d]:", i,j);
            scanf("%d", &a[i][j]);
        }

    }

    //Print
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            printf("%3d", a[i][j]);

        printf("\n");
    }

    // a -> mxn  t-> nxm
    for(i=0;i<n;i++){
        for(j=0; j<m;j++)
            T[i][j] = a[j][i];
    }

    printf("Result matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            printf("%3d", T[i][j]);

        printf("\n");
    }

    return 0;
}
```

<!-- BELİRSİZ: Son karede 47. satırdan sonrası (kapanış parantezleri ve return 0) görünmüyor; standart biçimde tamamlandı. -->

Transpoz döngüsü yazılırken döngü sınırlarına önce soru işareti konup öğrencilere ne gelmesi gerektiği soruldu; cevap dış döngüde `n`, iç döngüde `m`'dir. Nedeni, `a` matrisinin $m \times n$, transpozun ise $n \times m$ boyutlu olmasıdır; transpoz satır satır işlenecekse `n` satır ve her satırda `m` sütun dolaşılır. Transpoz yazdırılırken de aynı sınırlar kullanılır ve `a` yerine `T` yazılır.

> **Ders sonrası not:** Anlatımda bir yerde transpozun "N çarpı N boyutlu" olduğu söylendi (ya da altyazıya öyle geçti). Doğrusu $N \times M$'dir; ekrandaki koddaki `// a -> mxn  t-> nxm` açıklaması da bunu gösterir.

### 6.4 Çalıştırırken çıkan hatalar ve çıktı biçimi

İlk çalıştırmada `scanf` satırında bir yazım eksikliği yüzünden satırların birlikte okunmaya çalışıldığı, ayrıca satır sonunda `\n` basılmadığı fark edildi ve düzeltildi. Ardından çıktının düzeni konuşuldu: `printf` içinde yalnızca `%d` yazınca bütün sayılar bitişik yazdırılır. Bunun yerine sayılar arasına tab ya da boşluk konabilir, ya da `%3d` yazılabilir; `%3d` her sayıyı 3 karakterlik bir alana yazar ve sütunlar hizalı çıkar. Daha küçük bir matrisle yeniden denendiğinde satırların sütun, sütunların satır olduğu görüldü.

## 7. Soru 5 ve 6: Binary matrisin simetrik olması için gereken değişiklik sayısı

### 7.1 Problem

Slayttaki soru (ekrandan, 01:25:00): "$N \times N$ boyutlu bir binary matrisin ilk köşegene göre simetrik olması için gereken minimum değişiklik sayısı kaçtır?"

Köşegen sağdan sola da, soldan sağa da olabilir; burada ilk köşegene, yani sol üstten sağ alta inen ana köşegene bakılır. Köşegene göre karşılıklı gelen elemanlar karşılaştırılır. Karşılıklı iki eleman farklıysa birini değiştirmek onları eşitler; bu yüzden her farklı çift için değişiklik sayısı 2 değil 1 artar.

Slayttaki örnekler:

$$
\begin{bmatrix} 1 & 1 & 1 \\ 0 & 0 & 1 \\ 1 & 1 & 1 \end{bmatrix}
\quad \text{Flip: } 1
$$

Burada `(0,1)` konumundaki 1 ile `(1,0)` konumundaki 0 farklıdır; diğer iki çift (`1-1` ve `1-1`) eşittir. Tek bir değişiklik yeter.

$$
\begin{bmatrix}
1 & 1 & 0 & 1 & 0 \\
1 & 1 & 1 & 0 & 1 \\
0 & 0 & 0 & 1 & 0 \\
0 & 0 & 1 & 1 & 1 \\
0 & 1 & 0 & 0 & 0
\end{bmatrix}
\quad \text{Flip: } 3
$$

Slaytta kırmızıyla işaretli farklı çiftler `(0,3)-(3,0)` (1 ve 0), `(1,2)-(2,1)` (1 ve 0) ve `(3,4)-(4,3)` (1 ve 0) çiftleridir; üç değişiklik yeter. (Sayım python ile doğrulandı.) Önceki sorunun bu soruda kullanılabileceği ipucu verildi.

### 7.2 Basit çözüm: transpozla karşılaştırma

Transpoz alındığında köşegenin üstündeki elemanlar alta, alttakiler üste geçer. Dolayısıyla orijinal matristeki bir elemanın karşılaştırılması gereken eleman, transpozda aynı konuma gelir. Slaytta bu, bir matristeki 6 ile karşılıklı 2'nin transpozda aynı konuma gelmesiyle gösterildi.

En basit yaklaşımda bütün elemanlar karşılaştırılır: 6, 2'ye eşit mi? Hayır, sayaç 1 artar. Daha sonra aynı çift ters konumda yeniden karşılaştırılır ve sayaç bir daha artar, 2 olur. Oysa bu çift için tek değişiklik yeterlidir. Bu yüzden en sonda sayaç 2'ye bölünür.

Program önceki koddan uyarlandı: matris kare olduğu için tek boyut makrosu `N` ve tek boyut `n` kullanıldı, transpoz oluşturuldu, sonra iç içe döngüyle `a[i][j] != T[i][j]` olan her konumda `flip` artırıldı ve `flip/2` yazdırıldı. Ekrandaki program (ekrandan, 01:35:00 ve 01:50:00) şöyledir; `gcc -Wall` ile derlendi ve slayttaki iki matris için 1 ve 3 sonuçlarını verdi.

```c
#include<stdio.h>

#define N 10

int main(){

    int a[N][N], T[N][N], n;
    int i,j;
    int flip;

    do{
        printf("Enter the column size");
        scanf("%d", &n);

    }while(n > N);

    printf("Enter the elements");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("element[%d][%d]:", i,j);
            scanf("%d", &a[i][j]);
        }

    }

    //Print
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%3d", a[i][j]);

        printf("\n");
    }

    // a -> mxn  t-> nxm
    for(i=0;i<n;i++){
        for(j=0; j<n;j++)
            T[i][j] = a[j][i];
    }

    flip = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i][j] != T[i][j])
                flip++;
        }
    }

    printf("Number of flip %d", flip/2);

    return 0;
}
```

### 7.3 Soru 6: Daha verimli çözüm

Slayttaki soru "Soru 5'i daha verimli çözmek için ne yapılabilir?" ve ipucu "Transpoz matrisi tutmak yerine diagonal olarak karşılaştır!" biçimindedir (ekrandan, 01:40:00).

İki iyileştirme yapılır. Birincisi, transpoz matrisi bellekte tutmaya gerek yoktur: transpozun `(i, j)` elemanı zaten orijinal matrisin `(j, i)` elemanıdır ve aynı matrisin indisleriyle erişilebilir. Transpoz doğrudan istenmedikçe ayrı bir matriste saklanmaz. İkincisi, bütün matrise bakıp sonucu ikiye bölmek yerine yalnızca matrisin yarısına bakmak yeterlidir: köşegenin altındaki yarı, her çiftin bir kez görülmesini sağlar.

Bunun için transpoz tanımı ve onu oluşturan döngü silinir, iç döngünün sınırı `n` yerine `i` yapılır ve karşılaştırma `a[i][j] != a[j][i]` olur. Böylece sonuç doğrudan `flip`'tir. Aşağıdaki sürüm karede görünmüyor; anlatıma göre yazıldı, `gcc -Wall` ile derlendi ve slayttaki iki matris için yine 1 ve 3 verdi.

```c
#include<stdio.h>

#define N 10

int main(){

    int a[N][N], n;
    int i,j;
    int flip;

    do{
        printf("Enter the column size");
        scanf("%d", &n);
    }while(n > N);

    printf("Enter the elements");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("element[%d][%d]:", i,j);
            scanf("%d", &a[i][j]);
        }
    }

    flip = 0;
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            if(a[i][j] != a[j][i])
                flip++;
        }
    }

    printf("Number of flip %d\n", flip);

    return 0;
}
```

Derste 4x4'lük rastgele bir binary matrisle denendi: köşegene göre karşılıklı çiftlerden yalnızca birinde 0 ve 1 farklı çıktı, program da 1 değişiklik sonucunu verdi.

Döngünün nasıl ilerlediği slaytta oklarla gösterildi. `i` satır indisi, `j` sütun indisidir. `(0,0)` köşegen elemanıdır, karşılaştırılacak bir şey yoktur. `i` 1 olunca `j` 0'dan başlar ve `a[1][0]` ile `a[0][1]` karşılaştırılır; eşitse `flip` değişmez, değilse bir artar. `j`, `i`'ye ulaşınca iç döngü biter, `i` bir artar ve `j` yeniden 0'dan başlar. Böylece her satırda yalnızca köşegene kadar olan sütunlar işlenir ve her çift tam bir kez karşılaştırılır.

## 8. Soru 7: Matrisin spiral formunun c. elemanı

### 8.1 Problem

Slayttaki soru (ekrandan, 01:45:00):

- $M \times N$ boyutlu bir matrisin spiral formunun i. elemanını yazdırınız.
- Kullanıcıdan bir index alınmalıdır.
- Matrisin spiral formu alınmalı ve ilgili indexteki eleman yazdırılmalıdır.

Slayttaki matris 4x5'tir ve `1`'den `20`'ye kadar sayılar satır satır yerleştirilmiştir. Spiral form sol üstten başlar: önce ilk satır `1 2 3 4 5`, sonra son sütun aşağı doğru `10 15 20`, sonra son satır sola doğru `19 18 17 16`, sonra ilk sütun yukarı doğru `11 6`, sonra içe dönülerek `7 8 9 14 13 12`. Girdi 6 ise spiral formda 6. eleman `10`'dur (ekrandan, 01:55:00; slaytta girdi önce `i = 6`, sonra `c = 6` olarak yazıldı).

### 8.2 Öğrencilerin fikirleri

Süre sonunda fikirler soruldu. Bir öğrenci `while` ile, istenen sırayı azaltarak ve satır ile sütun indislerini ilerleterek taramayı önerdi; bunun doğru yola yakın olduğu söylendi. Başka bir öğrenci spiral formu boş bir diziye aktarıp oradan okumayı önerdi. Bunun da olabileceği, ama diziye aktarmak için de matrisi zaten spiral biçimde gezmek gerektiği; istenen elemanı bulmak için matris üzerinde tarama yapmanın yeterli olduğu belirtildi.

### 8.3 Tarama mantığı

Spiral form için önce ilk satır taranır: sıfırıncı sütundan başlanıp sütun sayısına kadar gidilir. Sonra son sütuna geçilir; ama ilk satırın son elemanına zaten bakıldığı için son sütun bir alt satırdan başlar. Ardından son satır geriye doğru, sonra ilk sütun aşağıdan yukarı taranır. Bakılmış indislere bir daha bakılmaz.

İkinci turda ilk satır artık sıfırıncı sütundan değil, bir içeriden başlar (örnekte 7, 8, 9). Bu yüzden ne kadar ilerlendiğini bilmek için sütun başlangıcını gösteren bir indis tutulur. Aynı şekilde satırlar da her zaman sıfırıncı satırdan başlamaz; satır başlangıcı için de bir indis tutulur. Her kenar tamamen işlendikten sonra o kenar matristen çıkarılmış gibi düşünülür: işlenen satır ve sütun silinerek matris her turda küçülür. Matris bitene kadar bu küçültme sürer ve son elemana ulaşılır.

Değişkenler şunlardır: satır ve sütun boyutları `m`, `n`; döngü değişkenleri; kullanıcının istediği sıra `c` (`i` genelde döngü değişkeni olarak kullanıldığı için bu ad seçildi); satır başlangıç indisi `k` (row) ve sütun başlangıç indisi `l` (column), ikisi de 0'dan başlar; taranan eleman sayısını tutan `count`, 0'dan başlar.

**Soru:** Sayaç tutmak yerine `c`'yi azaltsak olmaz mı? Her ilerlediğimizde `c`'den bir çıkarırız. **Cevap:** Olabilir; `c` sıfırlandığında istenen elemana gelinmiş olur. Derste ise sayaç ile `c` karşılaştırıldı.

Tarama `while(k < m && l < n)` döngüsüyle yapılır: satır başlangıcı satır boyutundan, sütun başlangıcı sütun boyutundan küçük olduğu sürece taranmamış eleman vardır. Döngü içindeki dört adım şunlardır:

- İlk satır: `k`. satırda, `l`. sütundan son sütuna kadar ilerlenir. Her elemanda sayaç artırılır, sayaç `c`'ye eşitse `a[k][i]` yazdırılır; satır `k`, sütun döngü değişkenidir. Satır işlendiği için `k++` yapılır.
- Son sütun: döngü `k`'dan son satıra kadar gider ve `a[i][n-1]` incelenir. Son sütun işlendiği için `n--` yapılır.
- Son satır: `if(k < m)` ise döngü `n-1`'den `l`'ye kadar geriye gider ve `a[m-1][i]` incelenir. Son satır işlendiği için `m--` yapılır.
- İlk sütun: `if(l < n)` ise döngü `m-1`'den `k`'ya kadar yukarı çıkar ve `a[i][l]` incelenir. Sütun işlendiği için `l++` yapılır.

**Soru:** Son satırı taramadan önce neden `if(k < m)` kontrolü yapılıyor? `while` koşulunda zaten bu kontrol yok mu? **Cevap:** `k` döngünün içinde artırıldığı için, ilk iki adımdan sonra matrisin bütün elemanlarına zaten erişilmiş olabilir. `while` koşulu yalnızca döngü başında kontrol edildiğinden o anda bunu yakalayamaz; bu yüzden sonraki `for`'ların önüne birer `if` konur ve gereksiz taramalar önlenir.

**Soru:** İlk satırda sayaç `c`'ye ulaştığında taramadan hemen çıkmamız gerekmez mi? **Cevap:** Evet; aranan bulunduktan sonra kalan elemanlara bakmaya gerek yoktur. Bunun için bir bayrak (flag) değişkeni tutulup `while` koşuluna eklenebileceği söylendi.

Son sütun adımıyla ilgili olarak bir öğrenci, kodda sağ üstte yazılan `n-1` ifadesine dair bir düzeltme yaptı.

<!-- BELİRSİZ: 02:00:26-02:00:35 arasındaki "sağ üstteki n eksi bir, o n eksi eksi değil" düzeltmesinin hangi satıra ait olduğu tam anlaşılmıyor; spiral kodunun ekrandaki son hâli karelerde yok. -->

### 8.4 Program

Spiral kodunun ekrandaki hâli karelerde görünmüyor. Aşağıdaki program yalnızca derste anlatılan adımlara göre yazıldı, `gcc -Wall` ile derlendi ve 1x1'den 5x5'e kadar bütün boyutlarda ve bütün `c` değerlerinde python ile hesaplanan spiral sırayla karşılaştırılarak doğrulandı. 4x5 `1..20` matrisinde `c = 6` için 10, `c = 13` için 11, `c = 20` için 12 verdi. Erken çıkış için anlatılan bayrak eklenmemiştir.

```c
#include<stdio.h>

#define R 10
#define C 10

int main(){

    int a[R][C], m, n;
    int i, j, c;
    int k = 0;      /* row */
    int l = 0;      /* column */
    int count = 0;

    do{
        printf("Enter the row size");
        scanf("%d", &m);
        printf("Enter the column size");
        scanf("%d", &n);
    }while(m > R || n > C);

    printf("Enter the elements");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("element[%d][%d]:", i,j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter c:");
    scanf("%d", &c);

    while(k < m && l < n){
        for(i=l;i<n;i++){
            count++;
            if(count == c)
                printf("%d\n", a[k][i]);
        }
        k++;

        for(i=k;i<m;i++){
            count++;
            if(count == c)
                printf("%d\n", a[i][n-1]);
        }
        n--;

        if(k < m){
            for(i=n-1;i>=l;i--){
                count++;
                if(count == c)
                    printf("%d\n", a[m-1][i]);
            }
            m--;
        }

        if(l < n){
            for(i=m-1;i>=k;i--){
                count++;
                if(count == c)
                    printf("%d\n", a[i][l]);
            }
            l++;
        }
    }

    return 0;
}
```

Çözümün uzun olduğu, ama kod incelendiğinde rahatça anlaşılacağı söylendi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00). Dizinin ters versiyonunu bulunuz. Dizi boyutu ve elemanları kullanıcıdan alınmalı. Örnek: `6 3 1 4 2 9` → `9 2 4 1 3 6`.

> **Çözüm (derste verildi):** `start = 0`, `end = n-1`; `start < end` olduğu sürece `arr[start]` ile `arr[end]` `temp` yardımıyla yer değiştirilir, `start++`, `end--`. Program Bölüm 2.3'tedir.

**Soru 2** (derste sözlü, 00:18:02). Diziyi ters çevirirken ekstra bir dizi mi kullanmak gerekir, yoksa işlem aynı dizi üzerinde mi yapılabilir?

> **Çözüm (derste verildi):** Aynı dizi üzerinde yapılabilir; ekstra dizi ek bellek harcar. Baş ve son indisleri tutulup swap yapılır.

**Soru 3** (derste sözlü, 00:35:39). `#define MAX_Length 50` satırının sonuna neden noktalı virgül konmaz?

> **Çözüm (derste verildi):** Önişlemci makro adını gördüğü her yere yanındaki metni olduğu gibi koyar. Noktalı virgül konsaydı o da yerleştirilirdi (`int arr[50;];` gibi) ve kod anlamsız hâle gelirdi. Makronun veri tipi de yoktur.

**Soru 4** (ekrandan, 00:45:00). Dizinin çoğunluk elemanını (dizi boyutunun yarısından fazla sayıda bulunan eleman) bulunuz. Örnekler: `3 3 1 3 2 3 6 3` → "Majority Element: 3"; `3 3 1 4 2` → "No Majority Element".

> **Çözüm (derste verildi):** Basit yaklaşımda her elemanın frekansı iç içe döngüyle sayılır, en büyük frekans ve indisi tutulur, sonunda `maxCount > n/2` kontrol edilir; $O(n^2)$. Program Bölüm 4.2'dedir. İlk örnekte 3'ün frekansı 5'tir ($5 > 4$); ikincide en büyük frekans 2'dir ($2 \not> 2$).

**Soru 5** (derste sözlü, 00:53:39). Çoğunluk elemanı sorusunu kaç karmaşıklıkta çözdünüz?

> **Çözüm (derste verildi):** Basit çözüm $O(n^2)$'dir; bir öğrenci sayma yaklaşımıyla iç içe döngü kullanmadan yaklaşık $3n$ işlemle çözdüğünü söyledi; derste Moore oylama algoritmasıyla $O(n)$ çözüm gösterildi.

**Soru 6** (ekrandan, 01:05:00). 2. soruyu daha verimli bir yol ile çözünüz (Moore's Voting Algorithm: aday belirle, yalnız adayın frekansını hesapla, $n/2$'den büyük mü kontrol et).

> **Çözüm (derste verildi):** Aday indisi 0, sayaç 1 ile başlanır; eşitlikte sayaç artar, eşitsizlikte azalır, sayaç 0 olunca aday o anki elemana taşınır ve sayaç 1 yapılır. Sonra adayın frekansı sayılır. `3 3 1 3 2 6 3 3` için aday 3, frekansı 5, $5 > 4$ olduğu için çoğunluk elemanı 3'tür. Program Bölüm 5.4'tedir.

**Soru 7** (ekrandan, 01:10:00). $M \times N$ boyutlu matrisin transpozunu bulunuz; boyut ve elemanlar kullanıcıdan alınmalı. Örnek: `1 2 3 / 4 5 6 / 7 8 9` → `1 4 7 / 2 5 8 / 3 6 9`.

> **Çözüm (derste verildi):** Transpoz `T[C][R]` boyutunda tanımlanır ve `for(i=0;i<n;i++) for(j=0;j<m;j++) T[i][j] = a[j][i];` ile doldurulur. Program Bölüm 6.3'tedir.

**Soru 8** (derste sözlü, 01:21:25). Transpoz döngüsünde soru işareti konan sınırların yerine ne gelmelidir?

> **Çözüm (derste verildi):** Dış döngüde `n`, iç döngüde `m`; çünkü transpoz $n \times m$ boyutludur ve satır satır doldurulur.

**Soru 9** (ekrandan, 01:25:00). $N \times N$ boyutlu bir binary matrisin ilk köşegene göre simetrik olması için gereken minimum değişiklik sayısı kaçtır? Slayttaki matrisler: `1 1 1 / 0 0 1 / 1 1 1` (Flip: 1) ve `1 1 0 1 0 / 1 1 1 0 1 / 0 0 0 1 0 / 0 0 1 1 1 / 0 1 0 0 0` (Flip: 3).

> **Çözüm (derste verildi):** Transpozla eleman eleman karşılaştırılır, farklar sayılır ve her çift iki kez sayıldığı için sonuç 2'ye bölünür. 3x3 matriste farklı tek çift `(0,1)-(1,0)`; 5x5 matriste farklı çiftler `(0,3)-(3,0)`, `(1,2)-(2,1)`, `(3,4)-(4,3)`. Program Bölüm 7.2'dedir.

**Soru 10** (ekrandan, 01:40:00). Soru 5'i (yukarıdaki Soru 9) daha verimli çözmek için ne yapılabilir? İpucu: transpoz matrisi tutmak yerine diagonal olarak karşılaştır.

> **Çözüm (derste verildi):** Transpoz matrisi silinir, yalnız köşegenin altındaki yarı taranır: `for(i=0;i<n;i++) for(j=0;j<i;j++) if(a[i][j] != a[j][i]) flip++;`. Sonuç doğrudan `flip`'tir, 2'ye bölmeye gerek kalmaz. Program Bölüm 7.3'tedir.

**Soru 11** (ekrandan, 01:45:00). $M \times N$ boyutlu bir matrisin spiral formunun i. elemanını yazdırınız; kullanıcıdan bir index alınmalıdır. Örnek: 4x5'lik `1..20` matrisi için girdi 6, çıktı 10.

> **Çözüm (derste verildi):** `k` ve `l` başlangıç indisleriyle dört kenar sırayla taranır, her kenardan sonra sınır daralır, taranan her elemanda sayaç artırılır ve sayaç `c`'ye eşit olduğunda eleman yazdırılır. Spiral sıra `1 2 3 4 5 10 15 20 19 18 17 16 11 6 7 8 9 14 13 12` olduğu için 6. eleman 10'dur. Program Bölüm 8.4'tedir.

## Dersin Toparlaması

Bu uygulama oturumunda dizi ve matris üzerinde yedi soru çözüldü. Dizi sorularında ters çevirme, ek bir dizi yerine iki indisle ve swap ile yerinde yapıldı; çoğunluk elemanı önce bütün frekansları sayan $O(n^2)$ bir yöntemle, sonra yalnız bir adayın frekansını hesaplayan $O(n)$ Moore oylama algoritmasıyla bulundu. Bu sırada `#define` ile makro tanımlamanın önişlemcinin metin yerleştirmesi olduğu, satır sonuna noktalı virgül ve tip yazılmadığı, ve dinamik bellek öğrenilene kadar dizilerin en büyük boyutla tanımlandığı konuşuldu.

Matris sorularında transpoz `T[i][j] = a[j][i]` ile ve ters boyutlu bir matriste oluşturuldu; binary matrisin simetrik olması için gereken değişiklik sayısı önce transpozla bütün matris karşılaştırılarak, sonra transpoz tutmadan yalnız köşegenin altındaki yarıya bakılarak bulundu. Son olarak matris, sınırları her turda daralan dört kenarlı bir tarama ile spiral biçimde dolaşıldı. Bütün sorularda ortak ders, önce çalışan en basit çözümü yazmak, sonra gereksiz bellek ve gereksiz karşılaştırmaları kaldırarak çözümü iyileştirmektir. Dinamik bellek ayırma ve makroların ayrıntıları sonraki derslere bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
