# Ders 18 Genişletilmiş Notu: Bağlı Listede Arama ve Silme, Yapı Hizalaması, Bit Alanları ve Ara Sınav Struct Sorusu Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersten Kalan: Bağlı Liste Örneği
- 2. Bağlı Listede Eleman Arama
- 3. Kimliğe Göre Arama ve Fonksiyon Adı Çakışması
- 4. Bağlı Listeden Eleman Silme
- 5. Silme Kodundaki Şüphe ve Düzeltme
- 6. Yapı Hizalaması (Structure Alignment)
- 7. Bit Alanları (Bit Fields)
- 8. Ara Sınav İkinci Sorusunun Çözümü
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersten Kalan: Bağlı Liste Örneği

Hoca derse, kodların bundan sonra sıfırdan değil, ders notlarından kopyalanıp satır satır açıklanarak yazılacağını söyleyerek başladı. Bunun için öğrencilerden "şurada neden yıldız var, burada neden ok var" gibi sorularla kendisini yavaşlatmalarını istedi.

Önceki hafta bir bağlı liste (linked list) gerçeklemesi yapılmıştı. Listedeki her düğüm `EMPLOYEE` türünden bir çalışan kaydıydı ve her düğüm bir sonraki düğümü gösteren bir işaretçi taşıyordu. Listenin başı her zaman global bir işaretçide saklanıyordu:

```c
EMPLOYEE *head;
```

Önceki derste yazılan fonksiyonlar şunlardı: yeni bir düğüm için bellekte yer ayırıp ilk değerlerini veren fonksiyon, listeye eleman ekleme, belirli bir elemandan sonra eleman ekleme, tek bir düğümü yazdırma (`printElementP`), bütün listeyi yazdırma (`printList`) ve iş bitince listenin belleğini boşaltan `freeList`. `main` içinde önce iki eleman oluşturulup eklenmiş, sonra araya üçüncüsü konmuş, liste yazdırılmış ve en sonda liste boşaltılmıştı.

Denenmemiş iki işlem kalmıştı: listede belirli bir elemanı bulmak ve aradan bir eleman silmek. Hoca bu iki işlemin, ister dizi ister bağlı liste olsun, eleman listesi tutan her yapıda gerekeceğini hatırlattı.

## 2. Bağlı Listede Eleman Arama

### 2.1 Genel amaçlı arama neden zor?

Belirli bir elemanı aramak için o elemanı tanımlayan bir alan gerekir: ad ya da kimlik numarası (ID) gibi. Ders notundaki açıklamaya göre genel amaçlı bir `find()` fonksiyonu yazmanın kolay bir yolu yoktur, çünkü arama yapının bir alanına göre yapılır ve bu alan kullanılan yapıya bağlıdır (ekrandan, 00:15:00). Hoca bunu C'nin güçlü tip denetimiyle açıkladı: her düğümün bir türü vardır (burada `EMPLOYEE`) ve bulunan eleman geri döndürülürken o türden bir işaretçi döndürülmek zorundadır. Saklanan verinin türü değişirse bu fonksiyonların hepsi yeniden yazılmalıdır. Daha genel bir arama fonksiyonu, ileriki haftalarda görülecek fonksiyon işaretçileri (function pointers) ile yazılabilecektir.

### 2.2 Ada göre arama

Algoritma basittir. Listenin ilk elemanından başlanır; o elemanın adı aranan adla aynı mı diye bakılır; değilse sonraki elemana geçilir. Bu, eleman bulunana kadar ya da bakılacak eleman kalmayana kadar sürer. Bulunursa o elemanın işaretçisi, liste biterse `NULL` işaretçisi döndürülür. Ekrandaki kod (ekrandan, 00:15:00):

```c
EMPLOYEE* find(char *name) {
    EMPLOYEE *p;
    for (p = head; p != NULL; p = p->next)
        if (strcmp(p->name, name) == 0) // returns 0, if 2 strings are same
            return p;
    return NULL;
}
```

Hoca dönüş türünü `EMPLOYEE *find` yerine `EMPLOYEE* find` biçiminde, yıldızı türe yakın yazmayı anlaşılırlık açısından tercih ettiğini söyledi. Listede dolaşmak için geçici bir işaretçi (`p`) tanımlamak zorunludur. Döngü `head`'den başlar, `p` NULL olmadıkça sürer ve her adımda `p = p->next` ile sonraki düğüme geçer. Aynı dolaşma `while` ile de yazılabilirdi; hoca önceki haftalarda iki biçimin de çalıştığının görüldüğünü hatırlattı.

Dizgelerin karşılaştırılması için `strcmp` kullanılır. İki dizge aynıysa 0 döndürür ve büyük/küçük harfe duyarlıdır (case sensitive). Hoca, `strcmp` için gerekirse `string.h`'nin ekleneceğini söyledi.

### 2.3 Arama fonksiyonunun denenmesi

`main` içinde kullanıcıdan aranacak ad istendi (ad dizisi 20 karakterle sınırlandı), `find` çağrıldı ve sonuç NULL ise "Not found", değilse bulunan düğüm `printElementP` ile yazdırıldı (ekrandan, 00:45:00):

```c
printf("Enter the name of the person you are looking for: ");
scanf("%s",isim);
p = find(isim);
if( p == NULL )
    printf("Not found");
else
    printElementP(p);
```

Üç çalışan girildi ve sırayla ortadaki, baştaki, sondaki ve listede olmayan bir ad arandı. Hepsinde doğru sonuç alındı; olmayan ad için program "bulamadım" dedi ve çökmeden, garip karakter basmadan devam etti. Hoca bunu bir test ilkesi olarak vurguladı: baş, son, orta ve olmayan eleman olmak üzere her durum denendiği için fonksiyonun doğru olduğu söylenebilir. Bu arada `printf` biçim dizgelerine eksik `\n` karakterleri eklendi.

## 3. Kimliğe Göre Arama ve Fonksiyon Adı Çakışması

Belirli bir kimliğe sahip elemanı bulan fonksiyon neredeyse aynıdır; yalnız parametre `int id` olur ve karşılaştırma dizge yerine tam sayı üzerinden yapılır. Hoca önce bu fonksiyona da `find` adını verdi ve "parametreleri farklı olduğu için aynı adın sorun olmayacağını" düşündü. Derleyici ise `conflicting types for 'find'` ve `previous declaration of 'find'` hatalarını verdi (ekrandan, 00:25:00). Bunun üzerine ad `findByID` yapıldı ve hoca bu durumu ders notlarına eklemek üzere not aldı: C'de aynı adlı ama parametreleri farklı fonksiyonlar tanımlanamaz.

> **Ek bilgi (derste anlatılmadı):** Aynı adlı, farklı parametreli fonksiyonlara "fonksiyon aşırı yükleme" (overloading) denir. C++ ve Java gibi dillerde vardır, C'de yoktur. Hocanın "alışkanlıktan kalmış olacak" sözü büyük olasılıkla bu dillere işaret ediyordu.

Ekrandaki son hali (ekrandan, 00:25:00):

```c
EMPLOYEE* findByID(int id) {
    EMPLOYEE *p;
    for (p = head; p != NULL; p = p->next)
        if (p->ID == id)
            return p;
    return NULL;
}
```

`main` içindeki deneme kısmı adın yerine kimlik ister (ekrandan, 00:45:00):

```c
printf("Enter the ID of the person you are looking for: ");
scanf("%d",&val);
p = findByID(val);
if( p == NULL )
    printf("Not found");
else
    printElementP(p);
```

Dolaşma algoritmasının her konumdaki elemanı bulabildiği bir önceki denemede görüldüğü için burada tek bir deneme yeterli görüldü: kimliği 2 olan eleman arandı ve adı, soyadı ve maaşıyla doğru biçimde yazdırıldı.

## 4. Bağlı Listeden Eleman Silme

### 4.1 Silmenin mantığı

Hoca listeden aradan bir eleman silmenin, dizilerle karşılaştırıldığında çok daha basit olduğunu söyledi. Slayttaki bağlı liste şemasında (49 → 15 → 73 → 87 → 10 → NULL; baş düğüm 49, kuyruk düğüm 10) bir elemanı silmek için onu gösteren düğümün `next` işaretçisinin artık silinecek elemanın `next`'inin gösterdiği yeri göstermesi yeterlidir (ekrandan, 00:30:00). Sonra artık hiçbir işaretçinin göstermediği bu düğüm `free` ile bellekten temizlenir.

Bunun için silinecek elemandan bir önceki elemanı bilmek zorunludur. Bu büyük bir sorun değildir, çünkü silinecek eleman zaten listenin başından itibaren dolaşılarak bulunur. Hoca, liste çift yönlü (doubly linked list) olsaydı, yani her düğüm öncekini de gösterseydi silmenin daha kolay olacağını; buna karşılık araya ekleme gibi işlemlerde çift yönlü bağı korumak için daha çok komut yazmak gerekeceğini belirtti. Bu yüzden tek yönlü liste üzerinden devam edildi.

Özel durumlara dikkat edilmelidir: ilk elemanın ya da son elemanın silinmesi. İlk elemandan önce eleman olmadığı için, silinecek eleman baş düğümse bu durum döngüye girmeden ele alınır ve listenin yeni başı eski başın gösterdiği sonraki eleman olur.

### 4.2 Ders notundaki kod

Ders notundaki açıklama ve kod (ekrandan, 00:35:00):

```c
/* To delete an element in a linked list,
   you need to find the element before the one you are deleting
   so that you can bond the list back together after removing one of the links.
   You also need to use the free() func,
   to free up the memory used by the deleted element.  */
void delete_element(EMPLOYEE *goner){
    EMPLOYEE *p;
    if(goner == head)
        head=goner->next;
    else // find element preceding the one to be deleted:
        for(p=head; (p!=NULL) && (p->next != goner); p=p->next);
    if(p == NULL){
        printf("delete_element(): could not find the element \n"); return;
    }
    p->next=p->next->next; free(goner);
}
```

Fonksiyon silinecek düğümün işaretçisini (`goner`) parametre olarak alır. Belirli bir kimliğe ya da ada sahip elemanı silmek için önce o eleman bulunmalı, sonra bulunan işaretçi bu fonksiyona gönderilmelidir.

`for` döngüsünde iki koşul birlikte (`&&`) denetlenir: listede dolaşılacak eleman kalmış olmalı (`p != NULL`) ve şu anki elemanın bir sonraki elemanı silinecek eleman olmamalı (`p->next != goner`). İki koşul da doğruysa sonraki elemana geçilir. Döngüden birinci koşul yüzünden çıkıldıysa aranan eleman listede yoktur; ikinci koşul yüzünden çıkıldıysa silinecek eleman bulunmuştur ve `p` ondan bir öncekini göstermektedir. Döngünün yapacağı başka iş olmadığı için gövdesi yalnız noktalı virgüldür.

Hoca bu yaklaşımı, "elemanın kendisini bul, bu arada öncekini de geçici bir işaretçide sakla" çözümüyle karşılaştırdı. O çözüm de çalışırdı, ama bir adım fazla işlem yaptığı için daha az verimli olurdu; doğrudan bir öncekinde durmak daha güzel bir çözümdür.

### 4.3 Bağı yeniden kurmak

Hoca şema üzerinde gösterdi: 87'li düğüm silinecekse döngü `p` 73'lü düğümü gösterdiğinde biter. Artık `p->next` silinecek düğümü değil, silinecek düğümün `next`'ini göstermelidir. Bu `p->next = p->next->next;` ile yapılır. `p->next` henüz `goner` olduğu için `p->next->next` ile `goner->next` aynı yeri gösterir; satır `p->next = goner->next;` biçiminde de yazılabilirdi. Ardından `free(goner);` ile silinen düğüm bellekten temizlenir.

**Soru:** `head` nerede tanımlandı? **Cevap:** En başta, global bir değişken gibi. Her fonksiyonda ortak kullanılacağı için listenin başı sürekli bu işaretçide saklanır.

### 4.4 Silmenin denenmesi

`main` içinde silinecek kişinin adı istendi, `find` ile işaretçisi bulundu ve bulunduysa `delete_element`'e gönderildi; sonra liste yazdırıldı (ekrandan, 01:15:00):

```c
printf("Enter the name of the person you will delete: ");
scanf("%s",isim);
p = find(isim);
if( p == NULL )
    printf("Not found");
else
    delete_element(p);
printList( );
```

Üç denemede sırayla ortadaki, sondaki ve baştaki eleman silindi; üçünde de liste doğru biçimde yazdırıldı. Olmayan bir ad için de "Not found" alındı.

## 5. Silme Kodundaki Şüphe ve Düzeltme

### 5.1 Öğrencilerin soruları

**Soru:** Fonksiyonun sonundaki `p->next = p->next->next;` satırı `else` bloğunun içinde olmamalı mı? **Cevap:** Hoca önce hayır dedi, sonra öğrencinin haklı olabileceğini kabul etti: baş düğüm silinirken bu satır fazladan çalışıyor olabilir. Bir NULL işaretçi sorunu çıkarmıyorsa sorun olmayacağını, bunu baş, orta ve son eleman silinerek deneyeceklerini söyledi. Ders notunda girintinin sanki `else`'in süslü parantezi varmış gibi yazıldığını da belirtti.

Hocanın asıl beklentisi şuydu: baş düğüm silinirken `else`'e hiç girilmez, `p`'ye bir şey atanmaz, `p` NULL olur ve kod boşu boşuna "elemanı bulamadım" der. Denemelerde bu mesaj hiç çıkmadı.

**Soru:** Olmayan bir eleman silinmek istendiğinde `delete_element`'in kendi "could not find" mesajı neden çıkmadı? **Cevap:** Ekranda görülen "Not found" mesajı `main`'deki `find` kontrolünden geliyordu. Bir öğrencinin belirttiği gibi, `main`'deki `if` yüzünden olmayan bir ad için `delete_element` hiç çağrılmaz.

### 5.2 `p` neyi gösteriyordu?

Hoca durumu anlamak için `delete_element` içine `p`'yi yazdıran bir hata ayıklama satırı ekledi ve baş düğümü sildi. Çıktı, `p`'nin listenin ilk düğümünü gösterdiğini ortaya koydu. Yani `p` hiç atanmamasına rağmen NULL değildi; bu sayede `p->next = p->next->next;` eski baş düğümün `next`'ini değiştirdi (zaten silinecek düğüm), `head` önceden güncellendiği için liste bozulmadı ve kod doğru sonuç verdi.

Hoca bu davranışın güvenilir olmadığını, kodun başka bir işletim sisteminde ya da derleyicide doğru çalışmama olasılığının yüksek olduğunu söyledi ve mantığı açıkça kodladı.

> **Ders sonrası not:** Hoca, `else`'e girilmediğinde `p`'nin NULL olmasını beklediğini söyledi. C'de yerel (otomatik) değişkenlere kendiliğinden ilk değer verilmez; değerleri belirsizdir ve atanmamış bir işaretçiyi kullanmak tanımsız davranıştır. Derste `p`'nin ilk düğümü göstermesi bu tanımsız davranışın bir sonucudur. `gcc -Wall` slayttaki sürüm için "'p' may be used uninitialized" uyarısı veriyor (ajan testi).

### 5.3 Düzeltilmiş sürüm

Hoca `else`'i süslü parantezli bir bloğa çevirdi (ara hal: ekrandan, 01:10:00) ve sonra bağ kurma satırını bloğun içine, `free(goner)`'ı ise her iki durumda da çalışacak biçimde sona aldı. Hocanın anlattığı son mantık şudur:

```c
void delete_element(EMPLOYEE *goner){
    EMPLOYEE *p;
    if(goner == head)
        head=goner->next;
    else {
        for(p=head; (p!=NULL) && (p->next != goner); p=p->next);
        if(p == NULL){
            printf("delete_element(): could not find the element \n");
            return;
        }
        p->next=p->next->next;
    }
    free(goner);
}
```

<!-- BELİRSİZ: Son halin tamamı hiçbir karede görülmedi; kod 01:10:00 karesindeki ara hal ile 01:09:45-01:10:26 arasındaki anlatımdan kuruldu. -->

Bu sürümle baş, son ve orta eleman yeniden silindi ve üçü de doğru çalıştı. Ardından listeye eklenmemiş yeni bir düğüm oluşturulup doğrudan `delete_element`'e gönderildi: fonksiyon "could not find the element" dedi ve liste bozulmadan aynı kaldı.

Ajan testi: Yukarıdaki düzeltilmiş `find`, `findByID` ve `delete_element`, `EMPLOYEE` yapısı (ID, ad, soyad, maaş, `next`) ve küçük bir `main` ile birlikte `gcc -Wall` ile uyarısız derlendi ve çalıştırıldı. Baş ve son düğüm silme, olmayan adı arama ve listede olmayan bir düğümü silme denemeleri beklenen sonucu verdi. Yapının tam tanımı derste ekranda görülmedi; testte `printElementP`'nin biçim dizgesindeki (`"Employee %d %s %s has a salary of %f\n"`, ekrandan, 00:25:00) alanlara göre kuruldu.

## 6. Yapı Hizalaması (Structure Alignment)

Yapılarla ilgili sıradaki konu yapı hizalamasıdır. Programcı yapıyı kendi bildiği sırayla tanımlar ve bazı durumlarda belleği verimli kullanamayabilir. Bu durum bilgisayardan bilgisayara değişir.

Bazı bilgisayar sistemleri, bir char'dan (bir bayttan) büyük nesnelerin çift adreslerde başlamasını ister. Bu normalde programcıyı ilgilendirmez; kod böyle bir kısıt olsa da olmasa da çalışır. Ama kısıt varsa arka planda programcının görmediği bellek boşlukları oluşur. Slayttaki örnek (ekrandan, 01:20:00):

```c
struct ALIGN_EXAMP{ char mem1; short mem2; char mem3; } s1;
```

Hizalama kısıtı yoksa yapı 1 + 2 + 1 = 4 bayt kaplar:

```text
1000: mem1
1001: mem2 (1001-1002)
1003: mem3
1004: sonraki veri buradan başlayabilir
```

Bir char'dan büyük nesneler çift adreste başlamak zorundaysa mem2 1001'de başlayamaz:

```text
1000: mem1
1001: boşluk (hole)
1002: mem2 (1002-1003)
1004: mem3
1005: boşluk (hole)
1006: sonraki veri buradan başlar
```

Slayttaki notta da bu yerleşimin mem1 ile mem2 arasında ve mem3'ten sonra birer baytlık boşluk bıraktığı yazar. Hoca, mem2 ile mem3'ün tanım sırası değiştirildiğinde sorunun ortadan kalktığını gösterdi: `char mem1; char mem3; short mem2;` sırasında mem3 1001'e, mem2 1002-1003'e yerleşir ve 1004 temiz kalır.

> **Hocanın vurgusu:** Bir sınavda "yapıyı belleği en verimli kullanacak biçimde tanımlayın" gibi bir şey denirse bu hizalama konusu hatırlanmalı ve alanların sırası ona göre seçilmelidir.

> **Ek bilgi (derste anlatılmadı):** Ajanın x86-64 üzerinde gcc ile yaptığı denemede `sizeof(struct ALIGN_EXAMP)` 6, alanları `char, char, short` sırasıyla tanımlanan yapınınki 4 bayt çıktı. Yani bugünkü yaygın derleyicilerde de bu kısıt geçerlidir; yalnız boşluk miktarı mimariye ve derleyiciye göre değişebilir.

## 7. Bit Alanları (Bit Fields)

### 7.1 Neden gerekir?

C'nin desteklediği en küçük veri türü char'dır; bir bayt, yani 8 bittir. Ama yapılar içinde bundan küçük nesneler tanımlanabilir; bunlara bit alanı (bitfield) denir (ekrandan, 01:25:00). 1, 2 ya da 3 bitle gösterilebilecek bir bilgi için koca bir char ayırmak savurganlıktır. Örneğin 3 bitlik, 3 bitlik ve 2 bitlik üç ayrı veri varsa bunlar tek bir bayt altında toplanabilir ve hiç bellek harcanmamış olur. Bit alanları, aynı varlığın birkaç küçük hacimli verisini saklamak için en mantıklı biçimde bir yapı içinde tanımlanır.

Bit alanları başka int değişkenler gibi kullanılır; iki istisna vardır (ekrandan, 01:25:00):

- Bir bit alanının adresi alınamaz.
- Bit alanlarından dizi tanımlanamaz.

### 7.2 Tanımlama kuralları

Önce temel tür (base type) yazılır: bit alanlarının toplamda ne kadarlık bir birim içinde yer alacağını belirler (8, 16, 24, 32 gibi baytın katları). İşaretli ya da işaretsiz int, char ya da long gibi türler temel tür olabilir. Ardından her alanın adı, iki nokta üst üste ve bit genişliği yazılır. 3 + 3 + 2 bitlik örnekte temel tür char olabilir: `field1 : 3`, `field2 : 3`, `field3 : 2`.

Temel tür düz `int` yazılırsa derleyici, standarda ve işletim sistemine göre bütün veriyi işaretli ya da işaretsiz yorumlayabilir. Bit alanının tamamı bir tam sayıymış gibi bir fonksiyona aktarılırsa ne olacağı gerçeklemeye kalmıştır ("implementation is free to decide"). Bu yüzden taşınabilirlik için `unsigned` yazılması önerilir.

Bir alanın bit uzunluğu temel türün uzunluğunu geçemez. Temel tür 16 bitse 17 bitlik bir bit alanı tanımlanamaz.

### 7.3 Örnek: a 3, b 7, c 2 bit

Derleyicinin bit alanları için 16 bitlik birimler ayırdığını varsayalım. Bir yapıda a 3 bit, b 7 bit, c 2 bit olarak tanımlansın. 1000 adresinden başlayan 16 bitlik birim şöyle dolar (ekrandan, 01:35:00):

```text
bit:   0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
1000:  a  a  a  b  b  b  b  b  b  b  c  c  -  -  -  -
1002:  sonraki veri buradan başlar
```

Toplam 12 bit kullanılır, 4 bit boş kalır. Sonraki bit alanı, tam sayı ya da karakter 1002 adresinden başlar. a, b ve c ayrı char'lar olsaydı a'dan 5, b'den 1, c'den 6 bit, toplam 12 bit boşa giderdi. Bu yüzden toplamak daha verimlidir. Hoca slaytta bit numaralarında bir kayma olduğunu fark etti ve yerleşimi Excel'de yeniden çizdi.

Hoca bitleri düz sırayla yerleştirdiğini, ama derleyicinin bunu ters sırayla da yapabileceğini (önce c için 2 bit, sonra b için 7 bit gibi) söyledi. Bunun bir nedeni bayt sıralamasıdır: bir tam sayı en az 2 bayttır, bir en anlamlı baytı (MSB) bir de en az anlamlı baytı (LSB) vardır. İnsan sayıyı önce MSB sonra LSB olarak yazar; bazı sistemler bellekte önce MSB'yi, bazıları önce LSB'yi saklar. Bunlara Big Endian ve Little Endian denir. Hoca hatırlatma olarak "Big - Most, Little - Least" eşleşmesini verdi.

> **Ders sonrası not:** Hoca "Normalde biz önce MSB'yi sonra LSB'yi düşünürüz. Bilgisayar da o şekilde düşünüyorsa buna Little Endian deniliyor." dedi. Doğrusu tersidir: en anlamlı baytı en düşük adrese koyan düzen Big Endian, en az anlamlı baytı en düşük adrese koyan düzen Little Endian'dır. Hocanın verdiği "Big - Most, Little - Least" hatırlatması doğru eşleşmeyi verir.

İki adet 10 bitlik alan (a ve b) tanımlanırsa farklı senaryolar olabilir. Örneğin 1000 adresinden itibaren 10 bit a'ya verilir, 16 bitlik birimin kalan 6 biti boş kalır; 1002 adresinden itibaren 10 bit b'ye verilir ve 6 bit daha boş kalır.

### 7.4 DATE yapısı

Daha karmaşık bir örnek (ekrandan, 01:40:00):

```c
struct DATE{
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 11;
};
```

Gün için 5 bit yeter, çünkü $2^5 = 32 \ge 31$. Ay için 4 bit yeter, çünkü $2^4 = 16 \ge 12$. Yıl için 11 bit ayrılır. Toplam $5 + 4 + 11 = 20$ bittir.

> **Ders sonrası not:** Hoca hesap makinesinde $2^{11}$'i hesaplarken 4096 sonucunu okudu ve bu yapının "4096 yılına kadar" tarih tutabileceğini söyledi. Doğrusu $2^{11} = 2048$'dir; 11 bitlik işaretsiz alan 0 ile 2047 arasındaki değerleri tutar. 4096, $2^{12}$'dir.

Slaytta bu yapının iki farklı yerleşimi vardır (ekrandan, 01:40:00):

- Birinci yerleşimde derleyici bit alanlarını en yakın char sınırına paketler ve alanların int sınırını aşmasına izin verir. İlk DATE 0-19. bitleri kullanır, birkaç bit boş kalır ve sonraki DATE bir sonraki bayt sınırından (24. bit) başlar; böylece DATE'ler 1000, 1004, 1008 adreslerindeki satırlara taşarak sıkı biçimde dizilir.
- İkinci (alternatif) yerleşimde derleyici en yakın short sınırına paketler ve alanların int sınırını aşmasına izin vermez. Gün ve ay (9 bit) ilk 16 bitlik birime girer, kalan 7 bit boş kalır; yıl (11 bit) ikinci 16 bitlik birime girer, 5 bit boş kalır. Her DATE 32 bit kaplar.

Hoca birincinin daha az, ikincinin daha çok israfa yol açtığını söyledi. Üzerinde çalışılan ortamın nasıl davrandığı bilinmiyorsa tanımın hangisi gibi yerleşeceği de bilinemez. En iyi verim için ortam bilinmelidir; bunun için büyük olasılıkla deneme yanılma yapılır: bu türden çok sayıda veri yazılır ve toplam ne kadar bellek harcandığına bakılır. Bu, özellikle çok kısıtlı bellekle çalışılıyorsa gerekir.

Slayttaki son madde de bunu özetler: en iyi bellek kullanımı için ortamın bazı ayrıntılarını bilmek gerekir, ama alanların sırasını değiştirmek ya da birkaç fazladan bit ayırmak gibi önlemler her zaman alınabilir. Hoca, örneğin yıla 11 yerine 12 bit ayırmanın, önceki alanların genişliğine bağlı olarak sonuçta daha çok tasarruf sağlayabileceğini söyledi.

### 7.5 Sonraki derse kalan örnek

Hoca bit alanı içeren bir yapıyla bağlı liste örneğini tanıttı ama kodlamaya geçmedi. Slayttaki yapı (ekrandan, 01:45:00):

```c
struct personalstat {
    char ps_name[20], ps_tcno[11];
    unsigned int ps_birth_day : 5;
    unsigned int ps_birth_month : 4;
    unsigned int ps_birth_year : 11;
    // pointer to the next element in the linked list:
    struct personalstat *next;
};
// ELEMENT becomes synonymous with struct personalstat:
typedef struct personalstat ELEMENT;

// Always keep a pointer to the beginning of the linked list
static ELEMENT *head;
```

Kişilerin en fazla 20 harflik adı ve 11 haneli kimlik numarası tutulacak, doğum tarihi az önceki gibi 5, 4 ve 11 bitlik alanlarla gösterilecektir. Bu liste üzerinde bit alanı üyelerine erişim sonraki derste görülecektir.

## 8. Ara Sınav İkinci Sorusunun Çözümü

Derste öğrencilerin isteği üzerine ara sınavın struct sorusu çözüldü.

### 8.1 Soru metni

Ekrandaki soru (ekrandan, 02:05:00):

> 2) Öğrenci bilgi sistemi için id, Ad, yaş ve ortalama bilgilerini saklayan bir struct üzerinde aşağıdaki işlemleri yapan programı yazınız.
>
> a. id, Ad, yaş ve ortalama bilgileri için gereken struct'ı tanımlayınız.
>
> b. Main fonksiyonu içerisinde kullanıcıdan alınan N sayısına göre N elemanlı bir dinamik öğrenci dizisi oluşturunuz.
>
> c. Oluşturulan öğrenci dizisini ortalamaya göre sıralayan bir fonksiyon yazınız. Sıralama sonrası main içerisinde tanımlanan dizinin orijinal hali değiştirilmelidir. İstediğiniz sıralama algoritmasını kullanabilirsiniz. Fonksiyon prototipi: `________ nota_gore_sirala(struct öğrenci, eleman sayısı);`
>
> d. Oluşturulan öğrenci dizisini Ad'a göre sıralayan bir fonksiyon yazınız. Sıralama sonrası main içerisinde tanımlanan dizinin orijinal hali değiştirilmelidir. İstediğiniz sıralama algoritmasını kullanabilirsiniz. Fonksiyon prototipi: `________ ada_gore_sirala(struct öğrenci, eleman sayısı);`
>
> e. Oluşturulan öğrenci dizisini ekrana id - ad - yaş - ortalama formatında yazdıracak bir fonksiyon yazınız. Fonksiyon prototipi: `________ liste_yaz(struct öğrenci, eleman sayısı);`
>
> f. Main içerisinde oluşturulan öğrenci dizisi için c, d ve e maddelerindeki işlemleri aşağıdaki sıraya göre çağıran fonksiyon çağrılarını yazınız. Fonksiyon çağrılarından sonra dinamik olarak tahsis edilen bellek bölgesini serbest bırakan kod/kodları yazınız. (i) Listenin ilk halini ekrana yazdıran fonksiyon çağrısı, (ii) listeyi ortalamaya göre sıralayan fonksiyonun çağrısı, (iii) listeyi ad'a göre sıralayan fonksiyonun çağrısı, (iv) listenin en son halini ekrana yazdıran fonksiyonun çağrısı.

### 8.2 a şıkkı: yapının tanımı

Her yerde daha az kod yazmak için isimsiz bir struct tanımlanır ve `typedef` ile ona `STUDENT` adı verilir; bundan sonra `STUDENT` yazılan her yerde bu yapı türü kastedilir (ekrandan, 02:25:00):

```c
typedef struct {
    int id, age;
    float grade;
    char name[20];
} STUDENT;
```

Soruda id için özel bir şey söylenmediği için sayı ya da karakter dizisi olabilir; burada tam sayı seçildi. Ad bir karakter dizisi (20 karakter), yaş tam sayı, ortalama ondalıklı olmalıdır; bu tipler zorunludur.

### 8.3 b şıkkı: dinamik dizi

Soru diziyi ayrı bir fonksiyonda değil, doğrudan `main` içinde oluşturmayı istiyor. Kaç öğrenci olacağı kullanıcıdan alınır; elemanları okumak için bir döngü sayacı ve dinamik dizi için `STUDENT` türünden bir işaretçi gerekir. `malloc` ile `n` tane `sizeof(STUDENT)` büyüklüğünde yer ayrılır; `malloc` `void*` döndürdüğü için sonuç `STUDENT*` türüne dönüştürülür. İçeriği sıfırlamak gerekmediği için `calloc` yerine `malloc` yeterlidir (ekrandan, 02:10:00):

```c
int n, i;
STUDENT *dizi;
printf("Ogrenci sayisi: ");
scanf("%d",&n);
dizi = (STUDENT*)malloc(n*sizeof(STUDENT));

for(i=0;i<n;i++){
    printf("Ogrenci %d id: ", i+1);
    scanf("%d", &dizi[i].id);
    printf("Ogrenci %d isim: ", i+1);
    scanf("%s", &dizi[i].name);
    printf("Ogrenci %d yas: ", i+1);
    scanf("%d", &dizi[i].age);
    printf("Ogrenci %d not: ", i+1);
    scanf("%f", &dizi[i].grade);
}
```

Dinamik olarak ayrılmış alan bir işaretçidir, ama elemanlarına ister köşeli parantezli dizi gösterimiyle, ister işaretçi aritmetiğiyle erişilebilir; burada daha kolay olduğu için dizi gösterimi kullanıldı. `dizi[i]` bir yapı (işaretçi değil) olduğu için alanlarına nokta ile erişilir. Hoca, ok (`->`) gösteriminin de aslında nokta erişiminin işaretçiler için bir kısaltması olduğunu hatırlattı.

> **Ders sonrası not:** Ekrandaki çözümde ad `scanf("%s", &dizi[i].name);` ile okunuyor. `name` bir dizi olduğu için adı zaten ilk elemanın adresidir; doğrusu `&` olmadan `scanf("%s", dizi[i].name);` yazmaktır. `&` ile yazılan hal pratikte aynı adresi verdiği için çalışır, ama türü `char (*)[20]` olduğundan `gcc -Wall` bir biçim uyarısı veriyor (ajan testi).

### 8.4 e şıkkı: listeyi yazdırmak

Hoca kodu adım adım deneyebilmek için önce listeyi yazdıran fonksiyonu yazdı. Fonksiyon bir şey döndürmediği için `void`'dir; birinci parametre öğrenci dizisi, ikincisi eleman sayısıdır (ekrandan, 02:20:00):

```c
void liste_yaz(STUDENT* dizi, int n){
    int i;

    for(i=0;i<n;i++){
        printf("id: %d, ad: %s, yas: %d, ortalama: %f\n",
dizi[i].id, dizi[i].name, dizi[i].age, dizi[i].grade);
    }

    printf("\n");
}
```

Hoca iki noktanın altını çizdi. Birincisi, prototipte `struct öğrenci` yazması, kodda da öyle yazılacağı anlamına gelmez; `typedef` ile hangi ad verildiyse (`STUDENT`) o kullanılmalıdır, yoksa derleme hatası alınır. İkincisi, dizinin tamamı yerine ilk elemanın işaretçisi gönderilir ve elemanlara köşeli parantezle erişilir; dinamik dizilerde dizinin nerede bittiği bilinmediği için eleman sayısı da parametre olarak gönderilmek zorundadır.

Bir kez bir erişim biçimi (burada dizi gösterimi) seçildikten sonra öteki fonksiyonlarda da aynısının kullanılması işi kolaylaştırır; birinde dizi gösterimi, ötekinde işaretçi gösterimi kullanılırsa arada değişiklikler yapmak gerekir.

### 8.5 c şıkkı: ortalamaya göre sıralama

Soru, sıralamadan sonra `main`'deki dizinin orijinal halinin değişmesini istiyor. Hoca bunu değerle ve referansla çağırma konusuna bağladı: fonksiyonda yapılan değişikliğin kalıcı olması isteniyor. Bir seçenek sıralanmış yeni bir diziyi geri döndürmek olurdu, ama istenen orijinal dizinin değişmesidir; bu yüzden fonksiyon bir şey döndürmez ve prototipteki boşluğa `void` yazılır.

Hoca `void` yazılmadığında ne olacağını da gösterdi. Prototip `nota_gore_sirala(STUDENT*,int);` biçiminde dönüş türsüz yazılınca derleyici yalnız "data definition has no type or storage class" uyarısı verdi (ekrandan, 02:25:00). Yine de doğrusu `void` yazmaktır; boş bırakmak kabul edilmez.

> **Ek bilgi (derste anlatılmadı):** Eski C standardında (C89) dönüş türü yazılmayan bir fonksiyonun `int` döndürdüğü varsayılırdı ("örtük int"). Derleyicinin hata yerine uyarı vermesi büyük olasılıkla bundandır. C99'dan beri bu kural kaldırılmıştır.

Sıralama için en kolay algoritma olarak kabarcık sıralaması (bubble sort) kullanıldı. Sıralama ölçütü ortalama olduğu için yapının `grade` alanları karşılaştırılır; `age` kullanılırsa yanlış olur. Takas için `STUDENT` türünden geçici bir değişken gerekir ve yapılar bütün olarak takas edilir. Dizi işaretçiyle aktarıldığı için yapılan değişiklikler kalıcıdır. Hoca, dış döngünün 0'dan n-1'e kadar gittiğini, iç döngünün sınırının çözümde `n-1-` biçiminde yazıldığını belirtti ve istenen herhangi bir sıralama algoritmasının kabul edileceğini söyledi.

Deneme: üç öğrenci, ortalamalar karışık sırada girildi; çıktı 65, 78, 83 sırasıyla doğru sıralandı.

<!-- BELİRSİZ: nota_gore_sirala fonksiyonunun gövdesi hiçbir karede görülmedi. Aşağıdaki tam çözümdeki gövde, ada_gore_sirala'nın ekrandaki yapısına göre grade karşılaştırmasıyla kuruldu. -->

### 8.6 d şıkkı: ada göre sıralama

Algoritma aynıdır; yalnız karşılaştırma `grade` yerine `name` üzerinden ve `strcmp` ile yapılır. `strcmp` birinci dizge ikinciden büyükse pozitif bir değer döndürür; küçükten büyüğe sıralamak için birinci daha büyükse takas yapılır. Hoca önce karşılaştırmayı çözümdeki gibi `== 1` biçiminde yazdı, sonra `> 0`'a çevirdi (ekrandan, 02:35:00):

```c
void ada_gore_sirala(STUDENT* dizi,int n){
    int i, j;
    STUDENT temp;
    for (i=0;i<n-1;i++){
        for (j=0;j<n-1-j;j++){
            if (strcmp(dizi[j].name,dizi[j+1].name)>0){
                temp=dizi[j];
                dizi[j]=dizi[j+1];
                dizi[j+1]=temp;
            }
        }
    }
}
```

> **Ders sonrası not:** `strcmp`'nin dönüş değeri için C standardı yalnız işareti garanti eder (negatif, sıfır, pozitif); pozitif değerin 1 olması gerekmez. Bu yüzden `== 1` taşınabilir değildir, `> 0` doğrudur.

Bu fonksiyon derste doğru sıralama yapmadı. Bir öğrenci aynı kodu kendisinin yazdığını ve çalıştığını, hocanın bir yerde `i` yerine başka bir harf yazmış olabileceğini söyledi. Hoca kodu kendi bildiği biçimde de yazmayı denedi ama sonuç değişmedi; doğru çalışan sürümü sonradan isteyeceğini söyleyerek geçti.

> **Ders sonrası not:** Hatanın nedeni ekranda görülüyor: iç döngü `for (j=0;j<n-1-j;j++)` yazılmış (ekrandan, 02:35:00). Doğrusu `j<n-1-i`'dir. Hatalı sınırla $n = 3$ için koşul $j < 2 - j$ yalnız $j = 0$'da doğrudur; yani her geçişte yalnız ilk iki eleman karşılaştırılır. Derste girilen adlarla (Yunus, Emre, Selçuk) bu kod Emre, Yunus, Selçuk sırasını verir; ajan testinde de aynı sonuç alındı. Ortalamaya göre sıralamanın doğru çıkması da, iç döngüsü aynı biçimde yazıldıysa, büyük olasılıkla girdinin sırasından kaynaklanıyordu: girdi büyük olasılıkla 78, 65, 83 sırasındaydı ve bunun için ilk iki elemanın tek bir takası yeterlidir.

### 8.7 f şıkkı: çağrılar ve free

`main` içinde sırasıyla listenin ilk hali yazdırılır, ortalamaya göre sıralanır, ada göre sıralanır ve listenin son hali yazdırılır. Bütün değişiklikler kalıcı olduğu için son liste ada göre sıralı olmalıdır. Hoca kendi denemelerinde araya koyduğu fazladan yazdırma çağrılarının doğru çözümde olmaması gerektiğini belirtti. En sonda dinamik olarak ayrılan bellek `free` ile bırakılmalıdır.

> **Hocanın vurgusu:** Dinamik bellek ayrıldığında ayrılan belleğin mutlaka serbest bırakılması gerekir; sorunun bu kısmında `free`'nin hatırlanması bekleniyordu.

### 8.8 Tam çözüm (ajan testi)

Aşağıdaki kod, ekrandaki parçaların birleştirilmesi ve yukarıdaki iki düzeltmenin (`j<n-1-i` ve `&` olmadan `name`) uygulanmasıyla kuruldu. `nota_gore_sirala`'nın gövdesi derste ekranda görülmediği için `ada_gore_sirala`'ya göre yazıldı. Kod `gcc -Wall` ile uyarısız derlendi ve üç öğrencilik bir girdiyle (ortalamalar 83, 65, 78) çalıştırıldı; son liste ada göre (Emre, Selcuk, Yunus) doğru sıralandı.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id, age;
    float grade;
    char name[20];
} STUDENT;

void nota_gore_sirala(STUDENT*, int);
void ada_gore_sirala(STUDENT*, int);
void liste_yaz(STUDENT*, int);

int main(int argc, char *argv[]) {
    int n, i;
    STUDENT *dizi;
    printf("Ogrenci sayisi: ");
    scanf("%d", &n);
    dizi = (STUDENT*)malloc(n * sizeof(STUDENT));

    for (i = 0; i < n; i++) {
        printf("Ogrenci %d id: ", i + 1);
        scanf("%d", &dizi[i].id);
        printf("Ogrenci %d isim: ", i + 1);
        scanf("%s", dizi[i].name);
        printf("Ogrenci %d yas: ", i + 1);
        scanf("%d", &dizi[i].age);
        printf("Ogrenci %d not: ", i + 1);
        scanf("%f", &dizi[i].grade);
    }
    printf("\n");
    liste_yaz(dizi, n);          /* f-i   */
    nota_gore_sirala(dizi, n);   /* f-ii  */
    ada_gore_sirala(dizi, n);    /* f-iii */
    liste_yaz(dizi, n);          /* f-iv  */
    free(dizi);
    return 0;
}

void liste_yaz(STUDENT* dizi, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("id: %d, ad: %s, yas: %d, ortalama: %f\n",
               dizi[i].id, dizi[i].name, dizi[i].age, dizi[i].grade);
    }
    printf("\n");
}

void nota_gore_sirala(STUDENT* dizi, int n) {
    int i, j;
    STUDENT temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (dizi[j].grade > dizi[j + 1].grade) {
                temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }
}

void ada_gore_sirala(STUDENT* dizi, int n) {
    int i, j;
    STUDENT temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(dizi[j].name, dizi[j + 1].name) > 0) {
                temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }
}
```

### 8.9 Soru-cevap

**Soru:** `malloc` ile tanımlamayı hem `main`'de hem de fonksiyonların içinde mi yapmamız gerekiyor? **Cevap:** Hayır. `malloc` yalnız bir kez, `main` içinde yapılır. Soru senaryosu, belleği `main`'de ayırmayı, ayrılan alanın işaretçisini kaybetmemeyi ve onu bütün fonksiyonlara göndermeyi istiyor. Öteki fonksiyonlarda `malloc` çağrılmaz.

Hoca bu soruya bir karşı durum ekledi: soru "dizinin orijinal hali değiştirilmemelidir" deseydi, her fonksiyonun içinde aynı büyüklükte yeni bir yer ayırmak, parametre olarak gelen dizinin elemanlarını oraya kopyalamak, işlemleri yeni dizide yapmak ve ekrana bir çıktı verilecekse onu fonksiyonun içinde vermek gerekirdi. İki durum arasındaki fark bilinmelidir.

## Örnek Sorular

**1.** (derste sözlü, 00:27:44) Bağlı listede ikili arama (binary search) gibi $O(n)$'den daha az işlem karmaşıklığına sahip bir arama yöntemi kullanılabilir mi?

> **Cevap (derste verildi):** Hayır. Bağlı listede ortadaki ya da sondaki elemana doğrudan erişilemez; her elemana baştan dolaşarak ulaşılır. Sıralı dizilerde hızlı arama gerekiyorsa bağlı liste bir dezavantajdır. Bunun için hash tablosu gibi başka veri yapıları vardır ve bunlar Veri Yapıları dersinde görülür.

**2.** (derste sözlü, 00:38:00) Ders notundaki `delete_element` fonksiyonunda sondaki `p->next = p->next->next;` satırı `else` bloğunun içinde olmamalı mı?

> **Cevap (derste verildi):** Evet, olmalıdır. Slayttaki sürümde `else` yalnız `for` satırını kapsıyor; baş düğüm silinirken `p` atanmamış haldeyken kullanılıyor. Kod derste çalıştı, ama bunun nedeni `p`'nin rastlantıyla ilk düğümü göstermesiydi. Hoca `else`'i süslü parantezli bir bloğa çevirip bağ kurma satırını içine aldı, `free(goner)`'ı sona bıraktı (bkz. 5.3).

**3.** (ekrandan, 01:20:00) `struct ALIGN_EXAMP{ char mem1; short mem2; char mem3; } s1;` yapısı, bir char'dan büyük nesnelerin çift adreste başlamasını isteyen bir bilgisayarda 1000 adresinden itibaren nasıl yerleşir? Alanların sırası nasıl değiştirilirse boşluk kalmaz?

> **Cevap (derste verildi):** mem1 1000'de, 1001 boşluk, mem2 1002-1003'te, mem3 1004'te durur, 1005 boşluktur; yapı 6 bayt kaplar. `char mem1; char mem3; short mem2;` sırasında mem3 1001'e, mem2 1002-1003'e yerleşir ve yapı 4 bayta iner.

**4.** (ekrandan, 02:05:00) Ara sınav ikinci sorusu: id, ad, yaş ve ortalama tutan öğrenci yapısı; `main` içinde N elemanlı dinamik dizi; ortalamaya ve ada göre sıralayan, orijinal diziyi değiştiren fonksiyonlar; listeyi yazdıran fonksiyon; çağrılar ve belleğin serbest bırakılması. Soru metni için bkz. 8.1.

> **Cevap (derste verildi, düzeltmelerle):** Bkz. 8.2-8.8. Prototiplerdeki boşluklara `void` yazılır, tür olarak `typedef` adı (`STUDENT*`) kullanılır. Tam ve derlenmiş çözüm 8.8'dedir.

**5.** (derste sözlü, 02:41:53) Bu soruda `malloc` hem `main`'de hem de fonksiyonların içinde mi yapılmalı?

> **Cevap (derste verildi):** Yalnız `main` içinde, bir kez. İşaretçi bütün fonksiyonlara gönderilir. Dizinin orijinal halinin değişmemesi istenseydi her fonksiyon kendi kopyasını ayırıp onun üzerinde çalışmalıydı.

## Dersin Toparlaması

Ders, önceki hafta kurulan tek yönlü bağlı listenin eksik iki işlemini tamamladı. Arama fonksiyonları baştan sona dolaşıp eşleşen düğümü ya da `NULL` döndürür; C'de aynı adlı farklı parametreli fonksiyon olamayacağı için kimliğe göre arama ayrı bir adla yazıldı. Silme, silinecek düğümden bir öncekini bulup bağı yeniden kurmak ve düğümü `free` ile bırakmak demektir; baş düğüm ayrı ele alınır. Ders notundaki sürümün atanmamış bir işaretçiyle "şans eseri" çalıştığı görüldü ve kod açık bir `else` bloğuyla düzeltildi. Ardından yapıların bellekteki yerleşimine geçildi: hizalama kısıtları alanlar arasında görünmeyen boşluklar yaratır, alanların sırasını değiştirmek bu boşlukları azaltabilir; bit alanları ise birkaç küçük veriyi tek bir tam sayı biriminde toplar, ama yerleşimleri derleyiciye ve mimariye bağlıdır.

Son bölümde ara sınavın struct sorusu çözüldü: `typedef` ile yapı tanımı, `main` içinde `malloc` ile dinamik dizi, işaretçi alan `void` sıralama fonksiyonları ve sonda `free`. Ada göre sıralamanın derste çalışmamasının nedeni iç döngü sınırındaki `n-1-j` yazımıydı. Bit alanı içeren `personalstat` yapısıyla bağlı liste örneğine sonraki derste devam edilecek; arama fonksiyonunun genel amaçlı hali de ileride fonksiyon işaretçileriyle ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
