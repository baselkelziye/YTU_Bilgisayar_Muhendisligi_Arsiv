# Ders 10 Genişletilmiş Notu: Yapılara Parametre Geçişi, Bağlı Listeler, Yığın ve Kuyruk; Uygulama 3: Seçmeli Sıralama ve Fonksiyon İşaretçileri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İç İçe Yapılar ve Yapı Tanımının Yeri
- 2. Yapıların Fonksiyonlara Parametre Olarak Geçirilmesi
- 3. Polinom Örneği: Call by Value ve Call by Reference
- 4. Bağlı Listeye Giriş
- 5. Elle Kurulan Bağlı Liste ve İki Yönlü Gezinme
- 6. Bağlı Listeye Ekleme Türleri
- 7. Çift İşaretçi: swap Örnekleri
- 8. head'i Değiştiren Fonksiyonlar İçin Üç Yol
- 9. Başa ve Sona Ekleme
- 10. Düğüm Arama
- 11. getNode ve Sıralı Ekleme (addMiddle)
- 12. Düğüm Silme
- 13. Bağlı Liste ile Yığın ve Kuyruk
- 14. Slayttaki Bağlı Liste Uygulaması ve Çalışma Önerileri
- 15. Uygulama 3: Yapı Kavramı
- 16. Uygulama 3: Seçmeli Sıralama (Selection Sort)
- 17. Uygulama 3: Fonksiyon İşaretçileri
- 18. Uygulama 3: Noktaları Uzaklığa Göre Sıralayan Program
- Örnek Sorular

## 1. İç İçe Yapılar ve Yapı Tanımının Yeri

Ders, önceki derste kalınan yerden, yapılarla (structure) devam etti. Bir yapı kendi içinde başka bir yapı türünden alan barındırabilir. Örneğin bir çalışan (employee) yapısında doğum tarihi ya da askere gidiş tarihi gibi alanlar başlı başına bir tarih yapısıdır; bunlar ayrı bir `struct` ile tanımlanıp çalışan yapısının içinde kullanılır.

> **Hocanın vurgusu:** İçerideki yapı daha önce tanımlanmış olmalıdır. Önce çalışan yapısını, sonra tarih yapısını tanımlayamayız.

Bir öğrenci, yapı tanımının bir fonksiyonun içinde yapılıp yapılamayacağını sordu.

**Soru:** Yapı tanımları bir fonksiyonun içinde de yapılabilir mi? **Cevap:** Yapılabilir, ama o zaman o yapı türünden değişken yalnız o fonksiyonun içinde üretilebilir. Tanım yapıldıktan sonra yapının biçimi değiştirilemez.

## 2. Yapıların Fonksiyonlara Parametre Olarak Geçirilmesi

Yapıların fonksiyonlara geçişi normal değişkenlerden pek farklı değildir. Değişkenlerde iki teknik vardır: call by value ve call by reference. C'de call by reference doğrudan yoktur; işaretçi (pointer) ile dolaylı olarak yapılır.

Call by value ile bir yapı gönderildiğinde yapının bütün alanlarının değerleri yeni bir yere kopyalanır. Bu iki sorun doğurur: bellekte fazladan yer kaplar ve kopyalama zaman alır. Bu yüzden yapılarda call by value pek tercih edilmez.

Bunun yerine yapı değişkeninin adresi gönderilir. Adres gönderilince fonksiyonda yapılan değişiklikler çağıran yere yansır. Kopyalama maliyeti olmadığı için bu yol daha hızlı ve daha verimlidir.

Yapı adresle gönderilir ama fonksiyonda değiştirilmesi istenmiyorsa parametrenin başına `const` eklenir. Örneğin bir çalışan yapısının işaretçisi `const` olarak alınır; erişim yine işaretçi üzerinden (`->`) yapılır.

## 3. Polinom Örneği: Call by Value ve Call by Reference

### 3.1 Başlangıç kodu

Hoca önceki derste yazılan polinom örneğini Dev-C++'ta açtı. Bu kodda polinomun terimlerini ekrana yazdıran satırlar birkaç yerde, farklı biçimlerde tekrarlanıyordu. Hoca bunun "duplicated code" olduğunu, fonksiyonların bir kez yazılıp istenildiği kadar çağrılmak ve kodu modüler yapmak için kullanıldığını hatırlattı.

Ekrandaki `main`'in başı şöyledir (ekrandan, 00:15:00):

```c
int main(){
    srand(time(NULL));
    int N;
    int i;

    POLINOM *p2;
    printf("Terim sayisi giriniz"); scanf("%d",&N);
    p1.terimsayisi=N;
    p1.terimler = (TERIM*) malloc(p1.terimsayisi*sizeof(TERIM));

    for(i=0;i<p1.terimsayisi;i++){
        p1.terimler[i].derece = i;
        p1.terimler[i].katsayi = rand() %5;
    }

    polinomYaz(p1);
```

Polinom yapısı (`POLINOM`) bir terim sayısı (`terimsayisi`) ve `malloc` ile açılmış `TERIM` dizisini gösteren `terimler` işaretçisi tutar. Her terim bir katsayı (`%lf` ile yazıldığı için `double`) ve bir derece (`int`) içerir. <!-- BELİRSİZ: TERIM ve POLINOM typedef satırları karelerde tam görünmedi; alanların sırası kesin değil. -->

Hoca `POLINOM *p2` ile dinamik açılan polinomu bu örnekte göndermenin karışıklık yaratacağını söyledi ve normal bir değişken olan `p1` üzerinden çalıştı.

### 3.2 polinomYaz: call by value

İlk fonksiyon değer alır. Parametre bir işaretçi değil, yapının kendisi olduğu için alanlara nokta ile erişilir (ekrandan, 00:25:00):

```c
void polinomYaz(POLINOM p){
    int i;
    for(i=0;i<p.terimsayisi-1;i++){
        printf("%2.1lf X ^ %d + ",p.terimler[i].katsayi, p.terimler[i].derece);
    }
    printf("%2.1lf X ^ %d\n",p.terimler[i].katsayi, p.terimler[i].derece);
}
```

Kopyalamayı göstermek için hoca hem `main`'de hem fonksiyonda yapı değişkeninin ve `terimsayisi` alanının adresini `%p` ile yazdırdı. Ekrandaki çıktıda `main`'deki polinom `...62FDF0`, terim sayısı alanı `...62FDF8`; fonksiyondaki kopya `...62FDE0`, terim sayısı alanı `...62FDE8` adresindedir (ekrandan, 00:20:00). Yani gönderilen argüman ile alınan parametre farklı adreslerde durur, değerler birbirine kopyalanır.

Ancak `terimler` alanı bir işaretçidir. Kopyalanan şey bu işaretçinin değeri, yani bir adrestir; `malloc` ile açılmış terim dizisi kopyalanmaz. Bu yüzden iki farklı yapıdan aynı terim dizisi kontrol edilebilir. Hoca bunu "kopyada bir açık" olarak nitelendirdi.

### 3.3 polinomYazv2: const işaretçi ile

İkinci sürüm polinomun adresini alır. Yazdırma sırasında değişiklik yapılmayacağı için parametre `const`'tur (ekrandan, 00:25:00):

```c
void polinomYazv2(const POLINOM *p){
    int i;

    for(i=0;i<p->terimsayisi-1;i++){
        printf("%2.1lf X ^ %d + ",p->terimler[i].katsayi, p->terimler[i].derece);
    }
    printf("%2.1lf X ^ %d\n",p->terimler[i].katsayi, p->terimler[i].derece);
}
```

Çağrı `polinomYazv2(&p1);` biçimindedir. Hoca önce `p->terimler[i]->katsayi` yazmayı denedi, sonra düzeltti: `p` bir işaretçi olduğu için `p`'nin alanlarına (`terimsayisi`, `terimler`) `->` ile erişilir. `terimler[i]` ise dizi indisi olduğu için zaten i. elemanın adresine gidip elemanı verir; elemanın alanına nokta ile erişilir. Böylece ayrıca işaretçi aritmetiği yapmaya gerek kalmaz.

### 3.4 Değer okuyan fonksiyon ve beklenmeyen davranış

Hoca kullanıcıdan değer okuyan `polinomOku(POLINOM p)` fonksiyonunu önce `malloc` olmadan yazdı. Okunan değerler fonksiyon dönünce `main`'de de görüldü.

**Soru:** Call by value birebir kopyalıyor dedik; neden fonksiyonda yaptığımız işlem dışarıyı da etkiledi? **Cevap:** `p` fonksiyona gönderildiğinde içindeki adres tutan `terimler` işaretçisi birebir kopyalanır. Terim sayısı farklı adreslerde durur ama iki kopyadaki `terimler` aynı yeri gösterir. Fonksiyon bu adrese yazdığı için orijinal yer değişir.

Bunu karşılaştırmak için tek bir terimi değerle alan bir fonksiyon yazıldı (ekrandan, 00:35:00):

```c
void terimOku(TERIM t){
    printf("Katsayi ve derece giriniz");
    scanf("%lf %d",&t.katsayi,&t.derece);
    printf("%lf %d\n",t.katsayi,t.derece);
}
```

`main`'de katsayısı 5.0, derecesi 4 olan bir terim tanımlandı. Fonksiyonda 3 ve 3 girildiğinde fonksiyon içinde 3, 3 yazıldı; fonksiyondan sonra terim hâlâ 5'e 4 idi. Terimde işaretçi alan olmadığı için değerle gönderim dışarıyı hiç etkilemedi. Hoca önce `scanf`'te `&` işaretini unuttu ve değer okunamadı; bunu düzeltti.

Polinomda da aynı bağımsızlığı sağlamak için fonksiyonun başında terimler için yeni yer açıldı (ekrandan, 00:35:00):

```c
void polinomOku(POLINOM p){ // call by value
    int i;
    p.terimler=(TERIM*) malloc(p.terimsayisi*sizeof(TERIM));
    for(i=0;i<p.terimsayisi;i++){
        printf("%d. terimin katsayisi ve derecesi",i);
        scanf("%lf",&p.terimler[i].katsayi);
        scanf("%d",&p.terimler[i].derece);
    }
    polinomYazv2(&p);
}
```

Artık rastgele atanmış değerler `main`'de korunur, fonksiyonda girilen değerler yalnız fonksiyondaki yeni dizide durur. Hoca, yapının içinde işaretçi varsa değerle gönderimde bu işaretçinin gösterdiği yerin yeniden oluşturulması gerektiğini söyledi.

> **Ders sonrası not:** Hoca değerle kopyalamaya "derin kopya (deep copy)" dedi. Yapının değerle kopyalanması büyük olasılıkla daha doğru biçimde sığ kopyadır (shallow copy): alanlar olduğu gibi kopyalanır, işaretçi alanların gösterdiği bellek kopyalanmaz. Derste görülen "işaretçi alanı orijinali değiştiriyor" davranışı bundandır. Gerçek derin kopya, gösterilen belleğin de ayrıca açılıp içeriğinin kopyalanmasıyla elde edilir.

> **Ek bilgi (derste anlatılmadı):** Yukarıdaki `polinomOku` içinde açılan yer yalnız fonksiyonun yerel kopyasında tutulur. Fonksiyon bitince bu adres kaybolur ve bellek `free` edilemez; bu bir bellek sızıntısıdır. Gerçek programda ya bu adres geri döndürülmeli ya da fonksiyon sonunda `free` çağrılmalıdır.

### 3.5 Call by reference ile okuma

Hoca, call by reference ile okuma yapan sürümde fonksiyonun içinde yeni yer açmanın pek tercih edilmediğini söyledi: bir fonksiyon adres alıyorsa amaç orijinal yerin değişmesidir ve değer okuma `main` yerine fonksiyonda yapılır. `polinomOkuv2` polinomun adresini alır; okuma `scanf("%lf", &p->terimler[i].katsayi)` ve `scanf("%d", &p->terimler[i].derece)` biçimindedir: "`p`'nin terimler alanına git, i. adresi bul, oradaki katsayı değişkeninin adresini getir".

Hoca bu sürümü çağırırken bir hata yaptı: fonksiyonun içinde zaten işaretçi olan `p`'yi `polinomYazv2(&p)` ile gönderdi. Bu, adresin adresini göndermek demektir ve derleyici uyumsuz tür uyarısı verdi. İşaretçi olan `p` doğrudan gönderilmelidir. Düzeltilince değerler hem fonksiyonda hem `main`'de değişti.

Hoca konuyu şöyle özetledi: yapılarda call by value ya da call by reference, bir `int` göndermekle aynıdır. Tek fark, işaretçi içeren alanların call by value'da da orijinali değiştirebileceğini unutmamaktır.

### 3.6 Yapının dizi alanını göndermek

Hoca son olarak `p1.terimler` gibi bir dizi alanının başka bir fonksiyona gönderilebileceğini gösterdi. `void f(TERIM *t)` gibi bir fonksiyon `f(p1.terimler)` ile çağrılır; alan zaten bir adres tuttuğu için işaretçi olarak alınır. `TERIM T[10];` gibi sabit bir dizi de aynı biçimde gönderilir. Fonksiyon içinde bu dizi üzerinde istenen işlem yapılabilir.

## 4. Bağlı Listeye Giriş

Slayttaki yeni konu "Structure example: Linked List Implementation" idi. Hoca önce beyaz tahtada (Microsoft Whiteboard) bağlı listenin yapısını çizdi (ekrandan, 00:45:00):

```text
 Head
 [ 1 ] ---> [ Data | 2 ] ---> [ Node | 3 ] ---> . . . ---> [      | NULL ]
              (1)               (2)
```

Bağlı listenin her elemanı bir veri alanı ve bir sonraki elemanın adresini tutar. İlk elemanın adresi `head` adlı bir değişkende saklanır; son elemanın adres gözünde `NULL` vardır. Tahtadaki 1, 2, 3 gerçek adres değil, adresleri simgeleyen sıra numaralarıdır. Bu elemanların her birine düğüm (node) denir; n tane düğüm bir bağlı liste oluşturur.

Tahtadaki düğüm tanımı şöyledir:

```c
struct node{
    Data d;
    struct Node *next;
};
```

`Data` burada herhangi bir türü temsil eder: tek bir `int` olabileceği gibi öğrencinin adı, soyadı gibi alanları tutan ayrı bir yapı da olabilir. O durumda önce veri yapısı tanımlanır, sonra düğümün içine konur.

> **Hocanın vurgusu:** Bir yapı kendi türünden bir değişken içeremez (`struct Node n;` olmaz). Bu henüz tamamlanmamış bir türdür ve sonsuz iç içelik demektir. Ama kendi türünden bir işaretçi içerebilir; düğüm türünden değişken ile düğüm türünden işaretçi farklı şeylerdir.

> **Hocanın vurgusu:** Bağlı liste bilgisayar mühendisliğinin en kritik veri yapılarından biridir. Veri yapıları ve algoritma analizi derslerinde sürekli kullanılır; bazı veri yapıları dizilerden, bazıları bağlı listelerden türer.

## 5. Elle Kurulan Bağlı Liste ve İki Yönlü Gezinme

### 5.1 Dört düğümlü liste

Kodda düğüm şöyle tanımlandı (ekrandan, 00:55:00):

```c
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}NODE;
int main(){
    NODE *head;
    NODE node1; node1.data=3;
    NODE node2; node2.data=4;
    NODE node3; node3.data=5;
    NODE node4; node4.data=6;
```

(`prev` alanı biraz sonra eklendi.) Hoca `struct node *next;` satırında `struct` sözcüğü kaldırılırsa derleyicinin "tamamlanmamış bir türü kullanmaya çalışıyorsun" hatası verdiğini gösterdi: bu satıra gelindiğinde `NODE` adı henüz tanımlanmamıştır.

Düğümler `next` alanlarıyla bağlandı. Hoca önce alanlara değişkenlerin kendisini yazdı; doğrusu adresleridir:

```c
node1.next = &node2;
node2.next = &node3;
node3.next = &node4;
node4.next = NULL;
head = &node1;
```

Gezinme için `head` güncellenerek ilerlendi: `head` önce `node1`'i gösterir, `head = head->next;` ile `node2`'yi göstermeye başlar. İlk denemelerde (`while` ve `do-while` ile) 6 yazılmadı; nedeni `NULL` atamasının yanlışlıkla `node3`'ün `next`'ine yapılmasıydı. `node4.next = NULL` yapılınca liste `3 4 5 6` olarak yazıldı.

### 5.2 İki yönlü liste

**Soru (hoca sordu):** Listede hem baştan sona hem sondan başa gitmek istersek ne yaparız? **Cevap:** Geri gösteren bir işaretçi daha ekleriz.

Düğüme `prev` alanı eklendi: `node1.prev = NULL; node2.prev = &node1; node3.prev = &node2; node4.prev = &node3;`. Hoca, `head`'i ilerleterek gezdiği için ilk denemede `head`'in en sonunda `NULL` olduğunu ve `NULL`'ın `prev`'ine erişmeye çalışınca segmentation fault alındığını gösterdi. Bu, `head` güncellenirse listenin başının kaybedildiğini gösterir.

Aradan sonra hoca bu sorunu yedek bir işaretçiyle çözdü. Son düğümün adresi `tail` adlı bir işaretçide tutuldu (`tail = &node4;`); `tail` her zaman son elemanı gösteren bir kolaylıktır (ekrandan, 01:10:00):

```c
tmp=head;
while(tmp!=NULL){
    printf("%d ",tmp->data);
    tmp = tmp->next;
}
tmp=tail;
printf("\n");
while(tmp!=NULL){
    printf("%d ",tmp->data);
    tmp = tmp->prev;
}
```

Çıktı `3 4 5 6` ve `6 5 4 3`'tür. Bu döngüler daha sonra `traverseForward(NODE *head)` ve `traverseBackward(NODE *tail)` fonksiyonlarına taşındı. Fonksiyona gelen `head` bir kopya olduğu için fonksiyonda ilerletilmesi `main`'deki `head`'i bozmaz; ama listenin içindeki verilerde yapılan değişiklikler, adresle çalışıldığı için dışarı yansır.

Hoca iki yönlü listenin bu derste çok kullanılmayacağını, örneklerin tek yönlü liste üzerinde süreceğini söyledi.

## 6. Bağlı Listeye Ekleme Türleri

**Soru (hoca sordu):** Bir bağlı listeye kaç şekilde ekleme yapılabilir? **Cevap:** Başa, araya (ortaya) ve sona.

- Başa ekleme: `head`'in gösterdiği yer değişir.
- Araya ekleme: önce eklenecek yerin öncesindeki düğüm bulunur. Tek yönlü listede geri gidilemediği için bu düğüm aranırken unutulmaz. Sonra önceki düğüm yeni düğümü, yeni düğüm de sonrakini gösterir. Bu, örneğin öğrencileri numaraya göre sıralı tutmak için kullanılır.
- Sona ekleme: `NULL` görene kadar ilerlenir (ya da `tail` tutuluyorsa doğrudan oraya gidilir), son düğüm yeni düğümü gösterir, yeni düğümün `next`'i `NULL` olur.

Araya ve sona eklemede `head` değişmez ama baştan aramak için `head` gerekir. Her durumda yeni düğüm `malloc` ile oluşturulur, çünkü fonksiyon bittikten sonra da program kapanana kadar yaşaması gerekir.

Başa eklemenin mantığı: önce `newNode->next = head;` ile yeni düğüm eski ilk düğümü gösterir, sonra `head = newNode;` ile `head` yeni düğümü gösterir. Hoca bunun bir fonksiyon içinde doğrudan böyle yazılamayacağını, call by value/call by reference farkının burada sorun çıkaracağını söyledi ve bunu göstermek için swap örneğine geçti.

## 7. Çift İşaretçi: swap Örnekleri

Hoca dört swap fonksiyonuyla işaretçi düzeylerini karşılaştırdı. İlk sürüm değerle çalışır (ekrandan, 01:20:00):

```c
void swap(int x, int y){
    int t=x;
    x=y;
    y=t;
}
```

**Soru (hoca sordu):** `swap(x, y)` çağrısından önce ve sonra yazdırınca ne görürüz? **Cevap:** Aynı değerleri; işlem call by value'dur, takas yalnız kopyalarda olur.

`swap2(int *x, int *y)` ile `int t=*x; *x=*y; *y=t;` yapılır: x'in gösterdiği yerdeki değer `t`'ye, y'nin gösterdiği yerdeki değer x'in gösterdiği yere, `t` de y'nin gösterdiği yere yazılır. Bu sürüm değerleri gerçekten takas eder.

Sonra hoca bir adım öteye geçti: `int *px = &x, *py = &y;` işaretçileri varken öyle bir fonksiyon yazılsın ki `px` `y`'yi, `py` `x`'i göstersin. İlk deneme `swap3` idi (ekrandan, 01:30:00):

```c
void swap3(int *x, int *y){
    int *t=x;
    x=y;
    y=t;
}
```

**Soru (hoca sordu):** Bu fonksiyon işaretçilerin gösterdiği yerleri değiştirir mi? **Cevap:** Hayır. `swap3`'ün `x` ve `y`'si bu fonksiyona ait yerel değişkenlerdir ve fonksiyon bitince ölür. Hoca bunu sayılarla anlattı: `x`'in adresi 10, `y`'nin adresi 20 olsun; `px` 10'u, `py` 20'yi tutar. `swap3`'e bu değerler kopyalanır ve yereldeki 10 ile 20 takas edilir, ama `main`'deki `px` ve `py` değişmez. Onları değiştirmek için `px` ve `py`'nin kendi adreslerine (örnekte 40 ve 50) ihtiyaç vardır; yani işaretçinin işaretçisine.

Doğru sürüm (ekrandan, 01:30:00):

```c
void swap4(int **x, int **y){
    int *t=*x;
    *x=*y;
    *y=t;
}
```

`swap4(&px, &py);` ile çağrılır. `t` birinci derece bir işaretçidir; `*x` ile `px`'in tuttuğu adres alınır, adresler takas edilir. İlk yazımda `swap4`'ün son satırı için derleyici "assignment makes pointer from integer without a cast" uyarısı verdi (ekrandan, 01:30:00); hoca `t` zaten işaretçi olduğu için tekrar değerinin alınmasına gerek olmadığını söyleyip satırı `*y=t;` olarak düzeltti. `t`'nin iki kez dereferans edilmesi (`**`) ise sayısal değere ulaşmak demektir.

Ekrandaki `main` parçası ve yorumlardaki beklenen çıktılar:

```c
    swap3(px,py);
    printf("%d %d\n",*px,*py); // 5 1
    swap4(&px,&py);
    printf("%d %d\n",*px,*py); // 1 5
```

Hoca `x = 1`, `y = 5` ile başlayıp çıktıyı "1'e 5, sonra 1'e 5, sonra 5'e 1, sonra 5'e 1, sonra tekrar 1'e 5" diye okudu. Aşağıdaki tam program bu akışı kurar; ders sonrası `gcc -Wall` ile derlenip çalıştırıldı ve `1 5`, `1 5`, `5 1`, `5 1`, `1 5` çıktısını verdi (`main` derste görülen parçalardan kuruldu, ara adım eklendi):

```c
#include <stdio.h>
void swap(int x, int y){ int t=x; x=y; y=t; }
void swap2(int *x, int *y){ int t=*x; *x=*y; *y=t; }
void swap3(int *x, int *y){ int *t=x; x=y; y=t; }
void swap4(int **x, int **y){ int *t=*x; *x=*y; *y=t; }
int main(){
    int x=1, y=5;
    int *px=&x, *py=&y;
    printf("%d %d\n",x,y);       // 1 5
    swap(x,y);
    printf("%d %d\n",x,y);       // 1 5
    swap2(&x,&y);
    printf("%d %d\n",x,y);       // 5 1
    swap3(px,py);
    printf("%d %d\n",*px,*py);   // 5 1
    swap4(&px,&py);
    printf("%d %d\n",*px,*py);   // 1 5
    return 0;
}
```

Son satırda `x` ve `y`'nin değerleri değişmemiştir (hâlâ 5 ve 1); değişen, `px` ve `py`'nin gösterdiği yerlerdir.

## 8. head'i Değiştiren Fonksiyonlar İçin Üç Yol

`head` bir işaretçidir. Başa ekleme ve baştan silme gibi işlemlerde `head` değişir. Fonksiyon `head`'i `NODE *head` diye alırsa, `swap3`'teki gibi yalnız yerel kopya değişir. Bu durumda üç yol vardır:

- Çift işaretçi: `void addNode(NODE **head, ...)`. `head`'in adresi gönderilir, fonksiyon `*head`'i değiştirir. Silme fonksiyonu için de aynısı geçerlidir.
- Değer döndürme: fonksiyon `head`'i normal işaretçi olarak alır, değiştirir ve döndürür: `NODE* addNode(NODE *head, ...) { ... return head; }`. Çağıran yer `head = addNode(head, ...);` yazar.
- Global `head`: `head` her yerden erişilecek şekilde global tanımlanır.

> **Hocanın vurgusu:** Global `head` istenmeyen (prohibited) bir yoldur, yan etkileri vardır. Ödev ve sınavlarda fonksiyon `void` istenirse çift işaretçi, değer döndürmesi istenirse ikinci yol kullanılır. Derste örnekler çift işaretçiyle yazıldı; ikinci yolla pratik yapılması önerildi.

## 9. Başa ve Sona Ekleme

Yeni bir dosyada liste `NODE *head=NULL;` ile boş başlatıldı. Başlangıçta hiç düğüm olmadığı için `head` mutlaka `NULL` olmalıdır (ekrandan, 01:40:00).

`addFront`'un son biçimi şöyledir (ekrandan, 02:40:00):

```c
void addFront(NODE **head, int data){
    NODE *newNode=getNode(data);
    newNode->next=*head;
    *head=newNode;
}
```

İlk yazımda düğüm fonksiyonun içinde `(NODE*) malloc(1*sizeof(NODE))` ile oluşturuluyordu; `getNode` sonradan eklendi (Bölüm 11). Yeni düğüm, `head`'in o anda gösterdiği düğümü gösterir; sonra `head` yeni düğümün adresini alır. Çağrı `addFront(&head, 10);` biçimindedir.

**Soru (hoca sordu):** 10, 20, 30, 40 sırayla eklenince neden ekranda `40 30 20 10` görünüyor? **Cevap:** Çünkü hepsi başa eklendi.

Sona eklemede son düğüm tutulmadığı için sona kadar gidilmesi gerekir. Ekrandaki gövde (ekrandan, 01:45:00):

```c
    newNode->data=data;
    newNode->next=NULL;
    if(*head=NULL){
        *head=newNode;
    }
    else{
        tmp = *head;
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
```

Liste boşsa eklenen düğüm hem ilk hem son düğümdür, bu yüzden `head` değişir. Değilse geçici `tmp` ile `tmp->next` `NULL` olana kadar ilerlenir ve son düğüme yeni düğüm bağlanır. Ne kadar ilerleneceği bilinmediği için `while` kullanılır. Hoca boş liste durumunda `addFront`'un çağrılabileceğini de söyledi.

Ekrandaki karede koşul `if(*head=NULL)` olarak yazılmıştır; program çalışmayınca hoca hatayı buldu: atama değil karşılaştırma (`==`) yapılmalıdır.

Derste kurulan sıra: önce `addLast` ile 0, sonra başa 10, sona 15, başa 20, 30, 40, en son sona 55 (ekrandan, 01:50:00). Her adımdan sonra liste yazdırıldı. Son durum `40 30 20 10 0 15 55`'tir; bu sıra ders sonrası derlenen bir sürümle doğrulandı.

## 10. Düğüm Arama

Arama, örneğin öğrenci numarasından öğrencinin diğer bilgilerine ulaşmak için yapılır. Arama `head`'i değiştirmediği için `head` tek işaretçiyle alınır. Bulunan düğümün bütün verileri istenebileceği için fonksiyon düğüm adresi döndürür (ekrandan, 01:50:00):

```c
NODE* searchNode(NODE *head,int data){
    NODE *tmp=head;
    while(tmp!=NULL && tmp->data!=data){
        tmp = tmp->next;
    }
    return tmp;
}
```

Döngünün iki koşulu vardır: ya aranan bulunana kadar ya da liste bitene kadar dönülür.

**Soru (hoca sordu):** `tmp` hangi değerleri döndürebilir? **Cevap:** Ya verisi aranan değere eşit olan düğümün adresi ya da bulunamadıysa `NULL`.

`main`'de dönen değer kontrol edilir: `NULL` ise "bulunamadı", değilse düğümün verisi (ve adresi `%p` ile) yazılır. 30 arandığında bulundu ve adresi yazıldı; 36 arandığında "bulunamadı" çıktı. Hoca aramanın silme ve sıralı araya ekleme işlemlerinde de kullanılacağını söyledi.

## 11. getNode ve Sıralı Ekleme (addMiddle)

### 11.1 getNode

Düğüm oluşturma kodu her ekleme fonksiyonunda tekrarlanıyordu. Hoca bunu ayrı bir fonksiyona aldı: verilen veriyle yeni düğüm oluşturur, `next`'i `NULL` yapar ve düğümü döndürür. Düğüm birden fazla veri tutacaksa bu kodu her yerde uzun uzun yazmak gerekmez.

```c
NODE* getNode(int data){
    NODE *newNode=(NODE*) malloc(sizeof(NODE));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
```

<!-- BELİRSİZ: getNode'un gövdesi karelerde görünmedi; yukarıdaki biçim altyazıdaki anlatımdan kuruldu. -->

`addFront`'ta `getNode`'un `NULL` yaptığı `next` hemen ardından `*head` ile değiştirilir; bu bir engel değildir.

### 11.2 Araya ekleme türleri

Araya eklemek için bir ölçüt gerekir. İki yol anlatıldı:

- Pozisyonla: "beşinci düğümden sonra ekle". Bunun için bir `for` döngüsüyle beş kez `tmp = tmp->next` yapılır.
- Insertion sort mantığıyla: her veri, değerine göre iki düğüm arasındaki yerine eklenir. Bu yaklaşımda ayrı `addFront`/`addLast` olmaz, tek bir ekleme fonksiyonu vardır.

### 11.3 addMiddle

Ekrandaki son sürüm (ekrandan, 02:15:00):

```c
void addMiddle(NODE **head, int data){
    NODE *tmp;
    NODE *newNode=getNode(data);
    if(*head==NULL){
        *head=newNode;
    }
    else{
        tmp = *head;
        while(tmp->next!=NULL && tmp->next->data < data ){
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}
```

Hoca önce koşulu `tmp->data < data` ile yazdı. Bu durumda önceki örnekte başta 40 olan listeye 35 eklenince, 40 küçük olmadığı için döngüye hiç girilmedi ve 35 hemen 40'ın arkasına geldi; ardından eklenen 39, 37, 36 da hep ikinci sıraya itildi. Hoca bunun bir "push" gibi davrandığını gösterdi ve koşulu `tmp->next->data < data` olarak değiştirdi: ekleme `tmp`'nin arkasına yapıldığı için karşılaştırma bir sonraki düğümün verisiyle yapılmalıdır.

Ardından önceki eklemeleri kapatıp yalnız `addMiddle` ile 35, 39, 36, 37, 44, 50, 55, 48 eklendi. Hoca bu fonksiyonun pozisyon bilgisi olmadan, ekleme sırasına bakmadan sona da araya da ekleyebildiğini söyledi. Bu sıra ders sonrası denendi; her adımdan sonraki liste şöyledir:

```text
35
35 39
35 36 39
35 36 37 39
35 36 37 39 44
35 36 37 39 44 50
35 36 37 39 44 50 55
35 36 37 39 44 48 50 55
```

> **Ders sonrası not:** Hoca bu yöntemin başa da ekleyebildiğini söyledi; ama ekrandaki kod ilk düğümün verisini hiç karşılaştırmaz. Eklenen değer `head`'deki değerden küçükse başa değil, ilk düğümün arkasına eklenir. Örneğin yukarıdaki listeye 30 eklenince sonuç `35 30 36 37 ...` olur (ders sonrası denendi). Tam sıralı ekleme için büyük olasılıkla `data < (*head)->data` durumunda ayrıca başa ekleme yapılmalıdır.

## 12. Düğüm Silme

Silmede de nereden silineceği değişir (baştan, ortadan, sondan). Derste verilen bir değere göre arama yapılıp bulunan düğüm silindi. Silinecek düğüm ilk düğüm olabileceği için `head` çift işaretçiyle alınır.

Önce silinecek düğümün ilk düğüm olup olmadığına bakılır. `head`'in gösterdiği düğümün verisine erişmek için `(*head)->data` yazılır; `*head->data` yazılamaz, çünkü `->` önceliklidir. Eşitse `head` değişecektir: ilk düğüm `tmp`'de yedeklenir, `head` bir sonraki düğüme kaydırılır ve `tmp` `free` edilir.

İlk düğüm değilse arama yapılır. Tek yönlü listede silinen düğümün öncesi ile sonrası bağlanacağı için silinecek düğümün bir öncesi bilinmelidir. Bu yüzden `current` adlı bir işaretçi ile `current->next` üzerinden arama yapılır. Bulununca `current->next` `tmp`'ye alınır, `current->next = current->next->next;` ile bağlantı atlanır, sonra `tmp` `free` edilir. Ekrandaki kod (ekrandan, 02:25:00):

```c
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    else{
        current=*head;
        while(current->next!=NULL && current->next->data!=data){
            current = current->next;
        }
        if(current->next!=NULL){
            tmp = current->next;
            current->next = current->next->next;
            free(tmp);
        }
```

Döngü ya `current->next` `NULL` olunca (aranan yok) ya da aranan bulununca biter. Bulunamazsa "aranan eleman yok" yazılır. `free` bir yeri boşaltmak demektir; bağlantı `free`'den önce düzeltilmelidir.

Derste 35, 37 ve 55 silindi: biri baştan, biri ortadan, biri sondan. Fonksiyon her üç durumu da karşıladı.

> **Ek bilgi (derste anlatılmadı):** Bu `deleteNode` liste boşken çağrılırsa `(*head)->data` ifadesi `NULL` üzerinden erişim yapar ve program çöker. Başına `if(*head==NULL) return;` gibi bir kontrol eklemek güvenlidir.

## 13. Bağlı Liste ile Yığın ve Kuyruk

Hoca yığın (stack) ve kuyruğun (queue) veri saklamak için değil veriye erişim düzeni için kullanılan yapılar olduğunu söyledi; veri dizi ya da bağlı listede saklanır. Yığında ekleme ve silme aynı uçtan yapılır: bağlı listede ya baştan ekleyip baştan silinir ya da sondan ekleyip sondan silinir. Kuyrukta ise farklı uçlardan yapılır: baştan ekleyip sondan silmek ya da sondan ekleyip baştan silmek; seçim tasarıma kalmıştır.

### 13.1 Yığın

Yığının iki işlemi push ve pop'tur. `push`, `addFront`'un aynısıdır (içinde `addFront(head, data)` çağrılır). `pop` ise baştan siler (ekrandan, 02:35:00):

```c
void pop(NODE **head){
    NODE *tmp;
    if(*head==NULL){
        printf("Stack is empty\n");
    }else{
        printf("silinen eleman=%d",(*head)->data);
        tmp  = *head;
        *head = (*head)->next;
        free(tmp);
    }
}
```

Mevcut ilk düğüm `tmp`'de tutulur, `head` güncellenir, sonra `tmp` `free` edilir. Silinen eleman geri istenirse fonksiyon `int` (ya da düğümdeki veri türünü) döndürebilir; bu değer `free`'den önce alınmalıdır. Derlemede `push` içinde `addFront(&head, data)` yazıldığı için "passing argument 1 of 'addFront' from incompatible pointer type" uyarısı alındı: `push`'un `head`'i zaten `NODE **`'dir, `&` konmaz (ekrandan, 02:35:00).

Çalıştırmada 10, 20, 30, 40 eklendi; ilk `pop` 40'ı, ikincisi 30'u sildi.

### 13.2 Kuyruk

Kuyrukta ekleme sona yapıldı; işlemin adı `enqueue`, silmeninki `dequeue`'dur (ekrandan, 02:40:00):

```c
void addFront(NODE **head, int data){
    NODE *newNode=getNode(data);
    newNode->next=*head;
    *head=newNode;
}
void enqueue(NODE **head, int data){
    addLast(head,data);
}
void dequeue(NODE **head){
    NODE *tmp;
```

`dequeue` baştan siler, gövdesi `pop` ile aynıdır. 10, 20, 30, 40 eklenince ilk çıkan 10, sonra 20 oldu. Araya `dequeue` serpiştirilen bir denemede de elemanlar ekleniş sırasıyla çıktı.

**Soru (hoca sordu):** Bağlı listeyle yapılan kuyruğun dolu olup olmadığını nasıl kontrol ederiz? **Cevap:** Dizilerde belli bir boyut vardır, ona ulaşılınca kuyruk doludur. Bağlı listede boyut yoktur, istenildiği kadar `malloc` ile eleman eklenir. Ancak `getNode` içindeki `malloc` yer ayıramazsa `NULL` döner; bu durumda "yer ayrılamadı/doldu" yazılıp fonksiyondan çıkılır. Aynı kontrol yığın için de geçerlidir.

Hoca, `push`/`enqueue` sona ekliyorsa silmenin de buna uygun uçtan yapılması gerektiğini söyledi; sondan silen fonksiyonu çalışma olarak bıraktı.

## 14. Slayttaki Bağlı Liste Uygulaması ve Çalışma Önerileri

### 14.1 Slayttaki yapı

Slaytta problem alanına ait veri ile düğüm yapısı ayrı tutulur (ekrandan, 02:45:00):

```c
#include <stdio.h>
typedef struct {
    char name[20], surname [20];
    int  ID;
    float salary;
} EMPLOYEE;
typedef struct emp_node {
    EMPLOYEE data;
    struct emp_node *next;
} EMP_NODE;
EMP_NODE *head;
```

Slayttaki gerekçe: "Advantage: This will keep the struct related with the problem domain separate from the struct related with data representation." Böylece çalışan verisi değişse de liste işlemleri aynı kalır. Hoca, düğümde tek bir `int` yerine `int id; char name[20];` gibi alanları olan bir veri yapısı tutulursa derste yazılan bütün işlemlerin aynen kullanılabileceğini söyledi. Hoca ileride polinomun da bağlı listeyle, yalnız var olan terimler tutularak daha verimli tasarlanabileceğini belirtti.

### 14.2 Slayttaki fonksiyonlar

Slayttaki örnek `head`'i kolaylık olsun diye global tanımlar; hoca bunu istemediğini, ödev ve sınavlarda kullanılmayacağını tekrar etti. Slaytta anlatılanlar:

- Listeyi yazdırma: baştan başlanır, `p = p->next` ile ilerlenir, her kişinin kaçıncı olduğu bir sayaçta tutulup ID, ad ve maaşı yazılır. Tek elemanı yazan bir fonksiyon varsa döngü içinde o çağrılabilir.
- Eleman oluşturma: `malloc` ile `EMP_NODE` kadar yer açılır; yer yoksa uyarı verilir. Ad `scanf` ile okunurken `&` gerekmez, çünkü `name` bir karakter dizisidir ve adı zaten ilk elemanın adresidir; ID ve maaş için `&` gerekir.
- Sona ekleme (append): `head` `NULL` ise `head` güncellenir; değilse sona kadar (slaytta `for` ile) gidilip eklenir.
- Silme: silinecek düğüm adresle karşılaştırılır; `head` ise `head` bir sonrakine kaydırılır; değilse aranır, bulunursa `p->next` atlanarak bağlanır ve düğüm `free` edilir.
- Ada göre arama: `strcmp` ile ya bulunana ya da `NULL` olana kadar dönülür. Hoca bunu `while(p != NULL && strcmp(p->data.name, name) != 0)` biçiminde yazmayı tercih edeceğini, sonunda `return p;` ile ya düğümün ya da `NULL`'ın döneceğini söyledi.
- `insert after`: `p` düğümünü `q`'dan sonra eklemek için önce `p->next = q->next;`, sonra `q->next = p;` yapılır. Hoca önce `p` ile `q`'yu karıştırdı, sonra bu sırayla düzeltti.

### 14.3 Çalışma önerileri ve tail

Yalnız `head` tutulan bir listede sona ekleme ya da sondan silme düğüm sayısı kadar, yani $O(n)$ maliyetlidir. Ayrıca bir `tail` işaretçisi tutulursa bu maliyet $O(1)$'e iner. Kuyrukta ya da sondan çalışan bir yığında sürekli sona gidildiği için bir işaretçilik ek bellek bu maliyeti düşürür; ama `addLast`/`deleteLast` gibi işlemlerde `tail`'in de güncellenmesi gerekir.

Hoca şu çalışmaları önerdi: `addMiddle`'ı pozisyona göre yazmak (beşinci düğümden sonra ekle; beş düğüm yoksa sona ekle), düğüm sayısını bulmak, `deleteFront` ve `deleteLast` yazmak (`deleteFront`'ta `head` değişir, `deleteLast`'ta değişmez), yığın ve kuyruğu bu fonksiyonlarla ve `tail` işaretçisiyle yeniden kurmak.

> **Hocanın vurgusu:** Bu tür sorular mülakatlarda da sorulabilir. Bunları yazıp pratik yapmak, gelecek dönemki veri yapıları dersine ve ayrık matematik konularına hazırlık olur.

## 15. Uygulama 3: Yapı Kavramı

Dersin ikinci bölümü bir uygulama (laboratuvar) oturumudur ve başka bir öğretim elemanı tarafından yürütüldü. Oturumun hedefi, üç boyutlu noktaların orijine uzaklıklarını kullanıcının seçimine göre artan ya da azalan sırada sıralayan bir program yazmaktı. Sıralama seçmeli sıralama (selection sort) ile yapılacak ve fonksiyonun parametre olarak fonksiyon alması öğrenilecekti.

Yapı kavramı bir örnekle tanıtıldı. Bir market çalışanlarını listelemek istesin; her çalışanın adı, soyadı, yaşı, cinsiyeti ve e-posta adresi olsun. Bunları ayrı değişkenlerle tutmak (`person1name`, `person1surname`, `person1age` ...) ya da her alan için ayrı diziler (beş ayrı dizi) açmak uğraştırıcıdır. Bunun yerine bir yapı tanımlanır:

```c
struct person{
    char *name;
    char *surname;
    int age;
    char *sex;
    char *email;
};
```

<!-- BELİRSİZ: person yapısının alan türleri karelerde görünmedi; yukarıdaki türler altyazıdaki anlatımdan kuruldu. -->

`struct person p1;` dendikten sonra `p1.` yazınca IDE yapının alanlarını (`age`, `email`, `name`, `sex`, `surname`) listeler. `p1.age = 25;` atanıp `printf("%d", p1.age);` ile yazdırıldı. Böylece 30 çalışan için beş ayrı dizi tutmak yerine `struct person` türünden tek bir dizi açılır; dizinin her elemanı bir çalışandır ve `.name`, `.surname` ile alanlarına ulaşılır. Aynı fikir arabaları listeleyen bir programda arabanın özelliklerini tutan bir yapı için de kullanılabilir.

Problemdeki üç boyutlu noktanın x, y ve z olmak üzere üç koordinatı vardır. Bir `point` yapısı ile bu üç değer tek bir değişkende tutulur.

## 16. Uygulama 3: Seçmeli Sıralama (Selection Sort)

Algoritma bir animasyon videosu üzerinden anlatıldı. Sıralama algoritmalarını görsel olarak izlemenin mantığı anlamayı kolaylaştırdığı söylendi.

İki indeks kullanılır: o anki konumu tutan indeks (current item) ve o ana kadar bulunan en küçük elemanın indeksi (current minimum). Küçükten büyüğe sıralamada:

- 0. konum için o konumdaki eleman en küçük kabul edilir.
- Bu eleman sağındaki her elemanla karşılaştırılır; daha küçük bir eleman bulununca en küçük olarak o seçilir.
- Satır (dizinin sonu) bitince bulunan en küçük eleman 0. konumdaki elemanla yer değiştirir.
- Sonra 1. konuma geçilir ve aynı işlem kalan kısım için yapılır.

Videodaki dizide ilk turda en küçük olarak 2 tutuldu ve sonuna kadar karşılaştırıldı. İkinci turda 8 ile başlandı; 5 daha küçük olduğu için 5, sonra 3, en sonda 2 seçildi ve ikinci konumdaki elemanla takas edildi. Sonraki turda 5 ile başlandı, 3 bulundu, 9, 4 ve 8 ile karşılaştırıldıktan sonra 3 ile 5 yer değiştirdi.

Döngü sınırları bir çizimle açıklandı: beş elemanlı bir dizide birinci eleman hepsiyle, ikinci kalanlarla karşılaştırılır. Beşinci elemana gelindiğinde karşılaştırılacak eleman kalmaz; küçükten büyüğe sıralanıyorsa en sondaki eleman artık en büyüktür. Bu yüzden dış döngü `size-1`'e kadar gider. İç döngü ise kendisiyle karşılaştırma gereksiz olduğu için `i+1`'den başlar ve `size`'a kadar gider.

## 17. Uygulama 3: Fonksiyon İşaretçileri

Sıralamanın yönünü seçmek için bir fonksiyonun başka bir fonksiyona parametre olarak gönderilmesi gösterildi. Basit örnek (ekrandan, 03:45:00):

```c
void print(){
    printf("Hello world!");
}

void helloworld(void (*fonksiyon)()){
    fonksiyon();
}

int main()
{
    helloworld(print);
    return 0;
}
```

Çıktı `Hello world!`'tür. `helloworld` parametre olarak bir fonksiyon alır; bu fonksiyon `fonksiyon` adlı bir fonksiyon işaretçisinde tutulur ve parantezle çağrılınca çalışır. Böylece `print`, kendi adı kullanılmadan, başka bir fonksiyonun içinde çalıştırılmış olur. `helloworld` açısından içeride ne yapıldığı bilinmez; bu bir soyutlamadır (abstraction). Program ders sonrası `gcc -Wall` ile derlenip çalıştırıldı.

Bir öğrenci açıklamanın tekrarını istedi; anlatım `main`'den başlanarak yinelendi.

**Soru:** Belirsiz tipteki bir fonksiyon için bunu yapabiliyor muyuz? **Cevap:** Hayır. `void` dönüşlü bir fonksiyon işaretçisine yalnız `void` döndüren bir fonksiyon gönderilir; `int` dönüşlü bir işaretçiye `int` döndüren bir fonksiyon. Gönderilen fonksiyon parametre alıyorsa işaretçi bildiriminde de aynı parametreler yazılmalıdır: örneğin `void print(int a)` için `void (*fonksiyon)(int a)`. Parametrelerin birebir örtüşmesi gerekir, yoksa sorun çıkar (ekrandan, 04:10:00).

## 18. Uygulama 3: Noktaları Uzaklığa Göre Sıralayan Program

### 18.1 Noktaların oluşturulması

Önce yapı ve veriler tanımlandı (ekrandan, 03:35:00):

```c
struct point{
    int x;
    int y;
    int z;
};

int main()
{
    int xArray[arraySize] = {12, 2, 4, 8, 10};
    int yArray[arraySize] = {10, 5, 2, 3, 12};
    int zArray[arraySize] = { 5, 2, 0, 4,  1};
    int order; // 1 = ascending, 2 = descending
    int counter;

    struct point *a;
    a = (struct point*)malloc(arraySize*sizeof(struct point));

    for(counter = 0; counter < arraySize; counter++)
    {
        a[counter].x = xArray[counter];
        a[counter].y = yArray[counter];
        a[counter].z = zArray[counter];
```

<!-- BELİRSİZ: arraySize'ın tanım satırı karelerde görünmedi; dizi başlatıcısı kullanıldığı için büyük olasılıkla #define arraySize 5 biçimindedir. -->

Koordinatlar kullanıcıdan da alınabilirdi; vakit kaybetmemek için hazır dizilerden alındı. Noktaları tutan yapı dizisi `malloc` ile dinamik olarak açıldı. Döngüde her noktanın x, y, z'si dizilerin aynı indeksteki değerlerinden atandı ve her nokta "kaçıncı nokta" bilgisiyle yazdırıldı.

### 18.2 Uzaklık fonksiyonu

Orijine uzaklık

$$d = \sqrt{x^2 + y^2 + z^2}$$

formülüyle `float` döndüren bir `distance` fonksiyonunda tek satırda hesaplandı. Fonksiyon x, y, z'yi ayrı tamsayılar olarak alır; yapının kendisi de gönderilip içeride ayrıştırılabilirdi. Karekök için `math.h` eklendi; fonksiyon prototipi `main`'in üstüne yazılmadığı için bir öğrencinin uyarısıyla prototip eklendi.

<!-- BELİRSİZ: distance fonksiyonunun gövdesi karelerde görünmedi; altyazıya göre kök içinde karelerin toplamıdır. -->

Noktaların uzaklıkları:

| Nokta | (x, y, z) | Uzaklık |
|---|---|---|
| 1 | (12, 10, 5) | 16.40 |
| 2 | (2, 5, 2) | 5.74 |
| 3 | (4, 2, 0) | 4.47 |
| 4 | (8, 3, 4) | 9.43 |
| 5 | (10, 12, 1) | 15.65 |

Örneğin 3. nokta için $\sqrt{4^2 + 2^2 + 0^2} = \sqrt{20} \approx 4.47$, 1. nokta için $\sqrt{144 + 100 + 25} = \sqrt{269} \approx 16.40$'tır. Değerler python ile doğrulandı.

### 18.3 Karşılaştırma fonksiyonları

Ekrandaki fonksiyonlar (ekrandan, 04:00:00):

```c
int ascending(float d1, float d2)
{
    return (d1 < d2);
}

int descending(float d1, float d2)
{
    return (d1 >= d2);
}
```

`return (d1 < d2);` satırı, `if(d1 < d2) return 1; else return 0;` ile aynıdır: parantez içindeki karşılaştırma doğruysa 1, yanlışsa 0 değerini alır. `descending`'de eşitlik de bir tarafa verildi ki tanımsız bir durum kalmasın.

### 18.4 selectionSort ve swap

Ekrandaki sıralama fonksiyonu (ekrandan, 04:05:00):

```c
void selectionSort(struct point array[], const int size, int (*compare)(float distance1, distance2))
{
    int i, j, smallestOrLargest;
    float d1, d2;
    for(i=0; i < size-1; i++)
    {
        smallestOrLargest = i;
        for(j=i+1; j < size; j++)
        {
            d1 = distance(array[smallestOrLargest].x, array[smallestOrLargest].y, array[smallestOrLargest].z
            d2 = distance(array[j].x, array[j].y, array[j].z

            if(!compare(d1, d2))
                smallestOrLargest = j;
        }
        swap(&array[smallestOrLargest], &array[i]);
    }
}
```

(Ekranda `distance(...)` satırlarının sonu pencerenin dışında kalmıştır.) `smallestOrLargest` değeri değil indeksi tutar; artan sıralamada en küçüğün, azalan sıralamada en büyüğün indeksidir. Artan sıralamada `compare` `ascending`'dir: `d1 < d2` değilse (yani `d1` en küçük olması gerekirken değilse) yeni aday `j` olur. Azalan sıralamada `descending` ile aynı mantık en büyüğü seçer.

> **Ders sonrası not:** Ekrandaki prototipte `int (*compare)(float distance1, distance2)` yazıyor. Güncel gcc bu bildirimi `unknown type name 'distance2'` hatasıyla reddeder (ders sonrası denendi). Her parametrenin türü ayrı yazılmalıdır: `int (*compare)(float distance1, float distance2)`.

Takas fonksiyonu iki nokta işaretçisi alır; geçici bir `struct point` üzerinden takas yapar. Ekrandaki son satırlar `tmp = *a; *a = *b; *b = tmp;` biçimindedir (ekrandan, 04:05:00):

```c
void swap(struct point *a, struct point *b){
    struct point tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
```

### 18.5 main'de çağrı ve sonuç

Kullanıcıdan sıralama yönü istenir (1 artan, 2 azalan). `order` 1 ise `selectionSort(a, arraySize, ascending);`, değilse `selectionSort(a, arraySize, descending);` çağrılır; fonksiyon adı doğrudan parametre olarak verilir. Sonra noktalar ve uzaklıkları bir döngüyle yazdırılır.

Derste görülen sonuç: artan sırada (4,2,0) 4.47, (2,5,2) 5.74, (8,3,4) 9.43, (10,12,1) 15.65, (12,10,5) 16.40; azalan sırada bunun tersi. Program, ekrandaki parçalardan kurulan bir `main` ve `distance` ile ders sonrası `gcc -Wall` ile derlenip iki seçenekle çalıştırıldı ve aynı sıralamayı verdi.

Oturumun sonunda bir sonraki uygulamada da bu konuların kullanılacağı söylendi ve seçmeli sıralama yerine örneğin insertion sort ile aynı programın yazılması önerildi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:27:52): Polinom yapısını değerle (call by value) alan `polinomOku` fonksiyonunda kullanıcıdan okunan terim değerleri, fonksiyondan döndükten sonra `main`'de de görünüyor. Değerle gönderim kopya oluşturduğu halde neden böyle oluyor?

> **Çözüm:** Yapının alanları kopyalanır, ama `terimler` alanı bir işaretçidir ve yalnız tuttuğu adres kopyalanır. Kopya ile orijinal aynı terim dizisini gösterir; fonksiyon bu diziye yazdığı için orijinal değişir. Fonksiyonun başında `p.terimler` için `malloc` ile yeni yer açılırsa değişiklik dışarıya yansımaz.

**Soru 2** (derste sözlü, 00:54:49): Tek yönlü bir bağlı listede hem baştan sona hem sondan başa gitmek istersek ne yapabiliriz?

> **Çözüm:** Düğüme bir önceki düğümü gösteren bir `prev` işaretçisi eklenir (iki yönlü liste) ve son düğüm bir `tail` işaretçisinde tutulur. İleri gezinme `tmp = tmp->next`, geri gezinme `tmp = tmp->prev` ile yapılır.

**Soru 3** (derste sözlü, 01:14:48): Bir bağlı listeye kaç şekilde ekleme yapılabilir? Hangisinde `head` değişir?

> **Çözüm:** Başa, araya ve sona. Başa eklemede `head` değişir; araya ve sona eklemede `head` değişmez ama aramaya `head`'den başlanır. Liste boşken yapılan ekleme (sona ekleme dahil) de `head`'i değiştirir.

**Soru 4** (derste sözlü, 01:19:25): `void swap(int x, int y)` fonksiyonu çağrılmadan önce ve sonra `x` ile `y` yazdırılırsa ne görülür?

> **Çözüm:** Aynı değerler görülür. Çağrı call by value'dur; takas yalnız fonksiyonun yerel kopyalarında yapılır.

**Soru 5** (ekrandan, 01:30:00): `int x=1, y=5; int *px=&x, *py=&y;` için `swap3(px,py)` ve ardından `swap4(&px,&py)` çağrılıyor. Her çağrıdan sonra `printf("%d %d\n",*px,*py);` ne yazar? (`swap3` ve `swap4` Bölüm 7'dedir; arada `swap2(&x,&y)` ile x ve y takas edilmiştir.)

> **Çözüm:** `swap2` sonrası x = 5, y = 1'dir. `swap3` yalnız yerel işaretçileri takas eder, `px` hâlâ x'i gösterir: `5 1`. `swap4` `px` ile `py`'nin tuttuğu adresleri takas eder; `px` y'yi, `py` x'i gösterir: `1 5`. Ekrandaki yorumlar da `// 5 1` ve `// 1 5`'tir; ders sonrası derlenip doğrulandı.

**Soru 6** (derste sözlü, 01:41:04): `addFront` ile sırayla 10, 20, 30, 40 eklenip liste baştan yazdırılınca neden `10 20 30 40` değil `40 30 20 10` görünür?

> **Çözüm:** Her eleman başa eklendiği için en son eklenen 40 listenin başındadır.

**Soru 7** (derste sözlü, 01:50:18): `searchNode` fonksiyonundaki `while(tmp!=NULL && tmp->data!=data)` döngüsünden sonra `return tmp;` hangi değerleri döndürebilir?

> **Çözüm:** Döngü ya `tmp` `NULL` olunca ya da `tmp->data` aranan veriye eşit olunca biter. Bu yüzden fonksiyon ya aranan veriyi içeren düğümün adresini ya da bulunamadıysa `NULL` döndürür.

**Soru 8** (derste sözlü, 02:40:17): Bağlı listeyle yapılan bir kuyruğun dolu olup olmadığını nasıl kontrol ederiz?

> **Çözüm:** Bağlı listede sabit boyut yoktur. Yeni düğüm için `malloc` yer ayıramazsa `NULL` döner; `getNode`'dan `NULL` gelirse "yer ayrılamadı" yazılıp eklemeden çıkılır. Aynı kontrol yığında da kullanılır.

**Soru 9** (derste sözlü, 02:16:46): `addMiddle`'ı pozisyona göre yazın: verilen k. düğümden sonra ekleme yapsın; k. düğüm yoksa (örneğin üç düğüm varken beşinci istenirse) yeni düğüm sona eklensin. Ayrıca listedeki düğüm sayısını bulan fonksiyonu yazın.

> **Çözüm (derste verilmedi):** Aşağıdaki kod ders sonrası `gcc -Wall` ile derlenip denendi. `10 20 30` listesinde `countNodes` 3 döndürdü; `addAfter(&head,2,25)` sonucu `10 20 25 30`, `addAfter(&head,5,99)` sonucu `10 20 25 30 99` oldu.
>
> ```c
> int countNodes(NODE *head){
>     int n=0;
>     while(head!=NULL){ n++; head=head->next; }
>     return n;
> }
> /* k. dugumden sonra ekle; k<=0 ise basa, k dugum sayisindan buyukse sona */
> void addAfter(NODE **head, int k, int data){
>     NODE *tmp, *newNode=getNode(data);
>     int i;
>     if(k<=0 || *head==NULL){ newNode->next=*head; *head=newNode; return; }
>     tmp=*head;
>     for(i=1; i<k && tmp->next!=NULL; i++) tmp=tmp->next;
>     newNode->next=tmp->next;
>     tmp->next=newNode;
> }
> ```

**Soru 10** (derste sözlü, 02:52:19): Listenin sonundaki düğümü silen `deleteLast` fonksiyonunu yazın. Bu işlemde `head` değişir mi?

> **Çözüm (derste verilmedi):** Liste tek düğümlüyse `head` `NULL` olur; aksi halde `head` değişmez. Sondan bir önceki düğüm bulunup son düğüm `free` edilir. Kod ders sonrası derlenip denendi (`1 10 20 25 30 99` listesinden `1 10 20 25 30` elde edildi, liste boşalana kadar silme sorunsuz çalıştı).
>
> ```c
> void deleteLast(NODE **head){
>     NODE *tmp;
>     if(*head==NULL){ printf("liste bos\n"); return; }
>     if((*head)->next==NULL){ free(*head); *head=NULL; return; }
>     tmp=*head;
>     while(tmp->next->next!=NULL) tmp=tmp->next;
>     free(tmp->next);
>     tmp->next=NULL;
> }
> ```

**Soru 11** (derste sözlü, 03:46:41): `void helloworld(void (*fonksiyon)())` fonksiyonuna `int` döndüren bir fonksiyon gönderilebilir mi?

> **Çözüm:** Hayır. Gönderilen fonksiyonun dönüş türü ve parametreleri, fonksiyon işaretçisi bildirimindekilerle birebir uyuşmalıdır. `int` döndüren fonksiyonlar için parametre `int (*fonksiyon)(...)` biçiminde bildirilir.

**Soru 12** (ekrandan, 03:35:00): Koordinatları `x = {12, 2, 4, 8, 10}`, `y = {10, 5, 2, 3, 12}`, `z = {5, 2, 0, 4, 1}` olan beş noktayı orijine uzaklıklarına göre artan sırada sıralayın.

> **Çözüm:** Uzaklıklar 16.40, 5.74, 4.47, 9.43, 15.65'tir. Artan sıra: (4,2,0) 4.47; (2,5,2) 5.74; (8,3,4) 9.43; (10,12,1) 15.65; (12,10,5) 16.40. Derste program çalıştırılıp aynı sonuç alındı.

## Dersin Toparlaması

Dersin ilk bölümünde yapıların fonksiyonlara değerle ve adresle geçirilmesi polinom örneği üzerinden karşılaştırıldı. Değerle gönderimde alanlar kopyalanır, ama işaretçi alanların gösterdiği bellek paylaşılmaya devam eder; adresle gönderim hem daha verimlidir hem de `const` ile korunabilir. Ardından yapıların en önemli uygulamalarından biri olan bağlı listeye geçildi: düğüm yapısı, `head`/`tail`, ileri ve geri gezinme, başa, sona ve sıralı araya ekleme, arama ve silme yazıldı. `head`'i değiştiren işlemler için çift işaretçinin neden gerektiği swap örnekleriyle gösterildi. Bu işlemler kullanılarak bağlı liste üzerinde yığın (push/pop) ve kuyruk (enqueue/dequeue) kuruldu, `tail` işaretçisinin sona erişimi $O(n)$'den $O(1)$'e indirdiği belirtildi. Sonraki derste polinomun bağlı listeyle tasarlanmasına devam edileceği söylendi.

Uygulama bölümünde yapı kavramı tekrar edildi, üç boyutlu noktalar bir yapı dizisinde tutuldu ve orijine uzaklıklarına göre seçmeli sıralama ile sıralandı. Sıralamanın yönü, `selectionSort`'a parametre olarak gönderilen karşılaştırma fonksiyonuyla belirlendi; böylece fonksiyon işaretçileri de uygulamalı olarak görüldü.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
