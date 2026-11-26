# Ders 10 Çalışma Özeti

## Genel Konular

- İç içe yapılar ve yapı tanımının yeri
  - Bir yapı, başka bir yapı türünden alan barındırabilir (örneğin çalışan yapısında doğum tarihi gibi bir tarih yapısı). İçerideki yapı daha önce tanımlanmış olmalıdır.
  - Bir yapı bir fonksiyonun içinde de tanımlanabilir; bu durumda o yapı türünden değişken yalnız o fonksiyonun içinde üretilebilir.
- Yapıların fonksiyonlara parametre olarak geçirilmesi
  - Call by value: yapı değişkeninin bütün alanları yeni bir yere kopyalanır. Bellekte fazladan yer kaplar ve kopyalama zaman alır.
  - Call by reference: C'de doğrudan yoktur, yapının adresi işaretçiyle gönderilerek dolaylı olarak yapılır. Daha hızlıdır, fonksiyonda yapılan değişiklik çağıran yere yansır.
  - Fonksiyon yapıyı değiştirmeyecekse parametre `const` işaretçi olarak alınır: `void polinomYazv2(const POLINOM *p)` (ekrandan, 00:25:00).
  - İşaretçi parametrede alanlara `->` ile erişilir: `p->terimler[i].katsayi`. Dizi indisi adrese kendisi gittiği için dizi elemanının alanına yine `.` ile erişilir.
- Yapı içinde işaretçi alan varken call by value
  - Polinom yapısında terim sayısı ile `malloc` ile açılmış terim dizisini gösteren bir işaretçi vardır (ekrandan, 00:15:00).
  - Yapı değerle gönderildiğinde terim sayısı alanı farklı adrese kopyalanır; ama işaretçi alanı yalnız adres olarak kopyalanır. İki kopya aynı terim dizisini gösterir, fonksiyonda dizide yapılan değişiklik çağıran yere yansır.
  - Fonksiyon içinde `p.terimler = (TERIM*) malloc(p.terimsayisi*sizeof(TERIM));` ile yeni yer açılırsa değişiklikler artık orijinali etkilemez (ekrandan, 00:35:00).
  - İşaretçi içermeyen bir yapı (tek terim) değerle gönderildiğinde fonksiyondaki değişiklik dışarıya hiç yansımaz.
- Bağlı liste (linked list) temelleri
  - Her düğüm (node) bir veri alanı ve bir sonraki düğümün adresini tutar. İlk düğümün adresi `head` değişkeninde tutulur, son düğümün `next` alanı `NULL` olur (ekrandan, 00:45:00).
  - Yapı kendi türünden bir değişken içeremez (tamamlanmamış tür, sonsuz iç içelik), ama kendi türünden bir işaretçi içerebilir: `struct node *next;`.
  - Elle kurulan dört düğümlü liste, `next` alanlarına düğümlerin adresleri (`&node2` gibi) atanarak bağlandı.
  - Gezinirken `head` güncellenirse listenin başı kaybedilir; bu yüzden geçici bir `tmp` işaretçisi kullanılır.
  - İki yönlü (doubly) liste için düğüme `prev` işaretçisi eklenir; `tail` son düğümü gösterir, listede geri yönde dolaşılabilir (ekrandan, 00:55:00 ve 01:10:00).
- Çift işaretçi (pointer to pointer) ve `head`'in değişmesi
  - `swap` (değerle) değişkenleri değiştirmez; `swap2(int *x, int *y)` değerleri takas eder.
  - `swap3(int *x, int *y)` yalnız yerel işaretçi kopyalarını takas eder, dışarıdaki işaretçiler değişmez.
  - `swap4(int **x, int **y)` işaretçilerin adreslerini alır, dışarıdaki işaretçilerin gösterdiği yerleri takas eder (ekrandan, 01:30:00).
  - Başa ekleme ve baştan silme gibi `head`'i değiştirebilecek işlemlerde `head` çift işaretçiyle (`NODE **head`) alınır.
  - Alternatifler: fonksiyon yeni `head`'i döndürür (`head = addNode(head, ...)`) ya da `head` global tanımlanır. Hoca global tanımı istenmeyen ve yan etkili bir yol olarak gördü.
- Tek yönlü bağlı listede işlemler
  - Ekleme yerleri: başa, araya, sona. Yeni düğüm fonksiyon bitince de yaşaması için `malloc` ile açılır.
  - `addFront`: yeni düğümün `next`'i eski `head` olur, `head` yeni düğümü gösterir. 10, 20, 30, 40 başa eklenince liste `40 30 20 10` olur.
  - `addLast`: liste boşsa `head` yeni düğüm olur; değilse `tmp->next != NULL` olduğu sürece ilerlenir, son düğümün `next`'ine yeni düğüm bağlanır (ekrandan, 01:45:00).
  - `searchNode`: `while(tmp!=NULL && tmp->data!=data)` döngüsü ya bulunan düğümün adresini ya da `NULL` döndürür (ekrandan, 01:50:00).
  - `getNode(data)`: düğüm oluşturma kodu tekrarlanmasın diye ayrı fonksiyona alındı.
  - `addMiddle`: `tmp->next->data < data` olduğu sürece ilerleyip sıralı (insertion sort mantığıyla) ekleme yapar (ekrandan, 02:15:00).
  - `deleteNode`: silinecek düğüm `head` ise `head` bir sonrakine kaydırılıp eski düğüm `free` edilir; değilse `current->next` ile aranır, bulunan düğüm atlanarak bağlanır ve `free` edilir (ekrandan, 02:25:00).
- Bağlı liste ile yığın (stack) ve kuyruk (queue)
  - Yığında ekleme ve silme aynı uçtan yapılır: `push` = `addFront`, `pop` = baştan silme (ekrandan, 02:35:00).
  - Kuyrukta ekleme ve silme farklı uçlardan yapılır: `enqueue` = `addLast`, `dequeue` = baştan silme (ekrandan, 02:40:00).
  - Bağlı listede sabit bir boyut olmadığı için "dolu" kontrolü `malloc`'un `NULL` döndürmesiyle yapılır.
  - Yalnız `head` tutulursa sona gitmek $O(n)$'dir; ayrıca bir `tail` işaretçisi tutulursa $O(1)$'e iner.
- Slayttaki bağlı liste uygulaması
  - Problem alanına ait veri yapısı (`EMPLOYEE`: ad, soyad, ID, maaş) düğüm yapısından (`EMP_NODE`: `data` ve `next`) ayrı tutulur (ekrandan, 02:45:00).
  - Slayt örneğinde ada göre arama `strcmp` ile yapılır, `insert after` ile bir düğümün arkasına ekleme gösterilir.
- Uygulama oturumu: üç boyutlu noktaları uzaklığa göre seçmeli sıralama
  - `struct point { int x; int y; int z; };` ile nokta tanımlanır, noktalar `malloc` ile açılan bir yapı dizisinde tutulur (ekrandan, 03:35:00).
  - Orijine uzaklık: $d = \sqrt{x^2 + y^2 + z^2}$.
  - Selection sort: her turda kalan kısmın en küçüğü (ya da en büyüğü) bulunur, o turun başındaki elemanla takas edilir.
  - Artan ve azalan sıralama, `selectionSort`'a parametre olarak gönderilen karşılaştırma fonksiyonuyla (`ascending` / `descending`) seçilir (ekrandan, 04:00:00 ve 04:05:00).
- Fonksiyon işaretçileri
  - `void helloworld(void (*fonksiyon)())` başka bir fonksiyonu parametre olarak alır ve kendi içinde çağırır: `helloworld(print);` (ekrandan, 03:45:00).
  - Gönderilen fonksiyonun dönüş türü ve parametreleri, işaretçi parametresinin bildirimiyle birebir uyuşmalıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- İç içe yapılarda içteki yapı önce tanımlanmalıdır.
  - Tanım sırası ters olursa derleyici içteki türü tanımaz.
- Yapılar çoğunlukla adresle (işaretçiyle) gönderilir.
  - Kopyalama maliyeti yoktur; değiştirilmemesi gerekiyorsa `const` eklenir.
- Yapı içinde işaretçi alan varsa call by value bile orijinal veriyi değiştirebilir.
  - Kopyalanan şey işaretçinin değeridir (adres); gösterdiği bellek kopyalanmaz.
- Bağlı liste bilgisayar mühendisliğinin en kritik veri yapılarından biridir.
  - Veri yapıları ve algoritma analizi derslerinde temel olarak kullanılır; başka veri yapıları ondan türetilir.
- `head` değişebilecekse fonksiyon `head`'i çift işaretçiyle almalıdır.
  - Hoca global `head` kullanımını istemediğini, ödev ve sınavlarda kullanılmayacağını söyledi.
- Listede gezinirken `head`'in kendisi ilerletilmemelidir.
  - Aksi halde listenin başı kaybolur; geçici `tmp` kullanılır.
- Önerilen çalışma soruları
  - k. düğümden sonra ekleme (düğüm yoksa sona ekleme), düğüm sayısını bulma, `deleteFront`/`deleteLast` yazma, `tail` işaretçisini tutup her ekleme/silmede güncelleme. Hoca bunların mülakatlarda da sorulabilecek türden sorular olduğunu söyledi.

## Kısa Tekrar Notları

- Yapı değerle gönderilirse alanlar kopyalanır; işaretçi alanların gösterdiği bellek paylaşılır.
- Yapı işaretçisinde alan erişimi `p->alan`, yapı değişkeninde `p.alan`.
- Düğüm: `typedef struct node { int data; struct node *next; } NODE;`
- Liste boşken `head == NULL`'dır; son düğümün `next`'i `NULL`'dır.
- `addFront`: `newNode->next = *head; *head = newNode;`
- `addLast`: sona kadar `tmp->next != NULL` ile ilerle, `tmp->next = newNode;`
- Arama ya düğüm adresini ya `NULL` döndürür.
- Silmede önce bağlantı düzeltilir, sonra `free`.
- Yığın: aynı uçtan ekle/sil. Kuyruk: bir uçtan ekle, öbür uçtan sil.
- `tail` işaretçisi sona ekleme maliyetini $O(n)$'den $O(1)$'e indirir.
- `swap4(int **x, int **y)` işaretçilerin kendisini takas eder.
- Fonksiyon işaretçisi: `int (*compare)(float, float)`; çağrı `compare(d1, d2)`.
- Selection sort dış döngüsü `size-1`'e kadar, iç döngüsü `i+1`'den `size`'a kadar gider.

## Detaylı Açıklamalar

- Yapılara parametre geçişi ve polinom örneği
  - Önceki derste yazılan polinom örneğinde terimleri ekrana yazdıran kod birçok yerde tekrarlanıyordu (duplicated code). Bu derste bu kod fonksiyonlara taşındı. Polinom yapısı terim sayısını ve `malloc` ile açılmış `TERIM` dizisinin adresini tutar; her terim bir katsayı ve bir derece içerir (ekrandan, 00:15:00). <!-- BELİRSİZ: TERIM ve POLINOM yapılarının tanım satırları karelerde tam görünmedi; alan sırası kesin değil. -->
  - `polinomYaz(POLINOM p)` call by value çalışır, alanlara `p.terimler[i].katsayi` biçiminde erişir. Hoca `main`'deki polinomun ve fonksiyondaki kopyanın adreslerini `%p` ile yazdırdı: polinom ve terim sayısı alanı fonksiyonun içinde başka adreslerdedir (ekranda `...62FDF0`/`...62FDF8` ve `...62FDE0`/`...62FDE8`) (ekrandan, 00:20:00). Bu, değerlerin kopyalandığını gösterir.
  - `polinomYazv2(const POLINOM *p)` adres alır ve `p->terimsayisi`, `p->terimler[i].katsayi`, `p->terimler[i].derece` ile erişir (ekrandan, 00:25:00). Çağrı `polinomYazv2(&p1);` biçimindedir.
  - Kullanıcıdan değer okuyan `polinomOku(POLINOM p)` önce `malloc` olmadan yazıldı: kullanıcının girdiği değerler fonksiyondan dönünce de görüldü, çünkü kopyadaki işaretçi orijinaldeki terim dizisini gösteriyordu. Fonksiyonun başına `p.terimler=(TERIM*) malloc(p.terimsayisi*sizeof(TERIM));` eklenince değişiklik artık dışarıyı etkilemedi (ekrandan, 00:35:00).
  - Tek bir terimi değerle alan `terimOku(TERIM t)` içinde okunan değerler dışarıya yansımadı; dışarıdaki terim önceki değerinde kaldı.
  - Call by reference sürümünde (`polinomOkuv2`) fonksiyon içinde yeni yer açılmaz, çünkü amaç orijinal yerin değişmesidir; okuma `scanf("%lf", &p->terimler[i].katsayi)` gibi adreslerle yapılır. Bu sürümde değerler hem içeride hem dışarıda değişti.
  - > **Ders sonrası not:** Hoca call by value'daki kopyalamaya "derin kopya (deep copy)" dedi. Yapının değerle kopyalanması büyük olasılıkla daha doğru biçimde sığ kopyadır (shallow copy): alanlar bit bit kopyalanır, işaretçi alanların gösterdiği bellek kopyalanmaz. Derste gösterilen "işaretçi alan orijinali değiştiriyor" davranışı tam da bundan kaynaklanır. Ayrıca fonksiyon içinde `malloc` ile açılan yer fonksiyon dönünce kaybolan bir yerel kopyada tutulduğu için `free` edilmezse bellek sızıntısı olur.
- Bağlı listenin elle kurulması
  - Beyaz tahtada düğümler veri ve sonraki adres gözleriyle çizildi; `head` ilk düğümü gösterir, sondaki düğümün adres gözü `NULL`'dır (ekrandan, 00:45:00).
  - Kodda `NODE node1, node2, node3, node4;` tanımlanıp verileri 3, 4, 5, 6 yapıldı (ekrandan, 00:55:00). `next` alanlarına önce yanlışlıkla değişkenlerin kendisi yazıldı; doğrusu adreslerdir: `node1.next = &node2;` ... `node4.next = NULL;`, `head = &node1;`.
  - `prev` eklenince `node1.prev = NULL`, `node2.prev = &node1` ... ile iki yönlü bağlantı kuruldu. `tmp = head` ile ileri (`tmp = tmp->next`), `tmp = tail` ile geri (`tmp = tmp->prev`) dolaşıldı; çıktı `3 4 5 6` ve `6 5 4 3` oldu (ekrandan, 01:10:00).
  - Bu döngüler `traverseForward(NODE *head)` ve `traverseBackward(NODE *tail)` fonksiyonlarına taşındı. Fonksiyona gelen `head` yerel bir kopya olduğu için fonksiyonda ilerletilmesi `main`'deki `head`'i değiştirmez.
- Çift işaretçi gerekçesi
  - `swap3` ile işaretçiler fonksiyon içinde takas edildiğinde `main`'deki `px`, `py` değişmedi (çıktı `5 1`). `swap4(&px, &py)` ile `int *t=*x; *x=*y; *y=t;` yapılınca `px` artık `y`'yi, `py` `x`'i gösterdi (çıktı `1 5`) (ekrandan, 01:30:00). Kodun tamamı ders sonrası `gcc -Wall` ile derlenip çalıştırıldı; çıktı `1 5`, `1 5`, `5 1`, `5 1`, `1 5` oldu.
  - Aynı mantıkla, `head`'i değiştiren `addFront`, `addLast`, `addMiddle`, `deleteNode`, `pop` fonksiyonları `NODE **head` alır ve `addFront(&head, 10)` diye çağrılır.
- Ekleme, arama ve silme
  - Ekrandaki `addLast` gövdesi (ekrandan, 01:45:00): yeni düğümün `next`'i `NULL` yapılır; `*head == NULL` ise `*head = newNode`; değilse `tmp = *head; while(tmp->next != NULL) tmp = tmp->next; tmp->next = newNode;`. Hoca önce `if(*head=NULL)` yazıp hatayı `==` ile düzeltti.
  - Derste kurulan sırayla (`0` sona, `10` başa, `15` sona, `20`, `30`, `40` başa, `55` sona) liste `40 30 20 10 0 15 55` olur. Bu sıra ders sonrası derlenen bir sürümle doğrulandı.
  - `searchNode(head, 30)` 30'u içeren düğümün adresini, `searchNode(head, 36)` `NULL` döndürür.
  - > **Ders sonrası not:** Ekrandaki `addMiddle` ilk düğümü karşılaştırmaz (koşul `tmp->next->data < data`). Bu yüzden yeni değer `head`'deki değerden küçükse başa değil, ilk düğümün arkasına eklenir. Örneğin `35 36 37 39 ...` listesine `30` eklenince sonuç `35 30 36 ...` olur (ders sonrası denendi). Tam sıralı ekleme için büyük olasılıkla `data < (*head)->data` durumunda ayrıca başa ekleme yapılmalıdır.
  - Ekrandaki `deleteNode` liste boşken `(*head)->data`'ya erişir; boş liste kontrolü eklenmezse program çöker.
- Yığın ve kuyruk
  - `pop` (ekrandan, 02:35:00): `*head == NULL` ise "Stack is empty", değilse silinen eleman yazılır, `tmp = *head; *head = (*head)->next; free(tmp);`.
  - 10, 20, 30, 40 push edilince liste `40 30 20 10`; iki pop ile 40 ve 30 silinir.
  - `enqueue` içinde `addLast(head, data)` çağrılır (`head` zaten `NODE **` olduğu için `&` konmaz; `&head` gönderilince derleyici "incompatible pointer type" uyarısı verdi) (ekrandan, 02:35:00 ve 02:40:00). 10, 20, 30, 40 kuyruğa eklenip iki `dequeue` yapılınca önce 10, sonra 20 çıkar.
- Uygulama oturumu
  - Yapı kavramı bir market çalışanları örneğiyle tanıtıldı: ad, soyad, yaş, cinsiyet, e-posta için ayrı değişkenler ya da diziler tutmak yerine bir `struct person` tanımlanır ve `p1.age` gibi erişilir.
  - Noktaların koordinatları üç diziden alınır: `xArray = {12, 2, 4, 8, 10}`, `yArray = {10, 5, 2, 3, 12}`, `zArray = {5, 2, 0, 4, 1}` (ekrandan, 03:35:00). Uzaklıklar sırasıyla 16.40, 5.74, 4.47, 9.43, 15.65'tir.
  - `int ascending(float d1, float d2) { return (d1 < d2); }` ve `int descending(float d1, float d2) { return (d1 >= d2); }` (ekrandan, 04:00:00). `selectionSort` içinde `if(!compare(d1, d2)) smallestOrLargest = j;` ile seçim yapılır, tur sonunda `swap(&array[smallestOrLargest], &array[i]);` çağrılır (ekrandan, 04:05:00).
  - Artan sıra: (4,2,0) 4.47, (2,5,2) 5.74, (8,3,4) 9.43, (10,12,1) 15.65, (12,10,5) 16.40. Azalan sıra bunun tersidir. Program ders sonrası `gcc -Wall` ile derlenip iki seçenekle çalıştırıldı, sonuç derste sözlü okunan değerlerle aynı çıktı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
