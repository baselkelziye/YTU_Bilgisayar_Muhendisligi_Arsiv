# Ders 7 Çalışma Özeti

## Genel Konular

- Asimptotik gösterimde baskın terim (derse başlarken gelen soru)
  - Bir öğrenci $n \cdot 2^n$ karmaşıklığın neden yalnız $2^n$ diye yazıldığını sordu. Hoca kendisinin $n \cdot 2^n$ yazmayı tercih edeceğini, ama $2^n$'in büyümesi o kadar hızlı olduğu için $n$ ile çarpmanın bunu sezgisel olarak çok değiştirmediğini söyledi. $\log n$'i $n$ ile çarpmak ise anlamlı bir fark yaratır.
  - $5 \cdot 2^n + n^3$ gibi bir yazım ise yanlıştır: en yüksek mertebeli terim kalır, katsayılar atılır.
- Dizilerin tekrarı
  - Dizi, aynı türden verileri bir öbek halinde tutan ve indisle erişim sağlayan veri yapısıdır. Vektör, matris, çok boyutlu diziler, yığıt, kuyruk ve karakter dizileri (string) gibi pek çok yapının temelidir.
  - Üç indisleme yaklaşımı: 0 tabanlı (C; döngü `i < n`), 1 tabanlı (Pascal, Basic gibi dillerde; döngü `i <= n`), n tabanlı (negatif indis, numaralandırma (enumeration) ya da karakter indisleri; örneğin Python'da sondan sayan negatif indis).
  - C dilinde `a[i]`'ye başvurmadan önce anlamlı bir değer atamak, pozitif ve dizi boyutundan küçük indis kullanmak programcının sorumluluğudur. Belleğe doğrudan erişim vardır; bütün bellek bir dizi gibi düşünülebilir (ekrandan, 00:20:00).
  - Statik tanım: `int a[10];` (0..9 arası gözler), `char b[] = "dizi";` gibi. Dinamik tanım: ilk elemanın işaretçisi tutulur, `malloc` ile gereken kadar yer ayrılır.
- Dizilerin kısıtları (ekrandan, 00:25:00)
  - Dinamik boyutlu değilse eleman eklenemez.
  - Dinamik boyutluyken de araya eleman eklemek ve aradan eleman silmek kaydırma gerektirdiği için en kötü durumda $O(n)$ maliyetlidir.
  - Çözüm: linkli (bağlı) listeler.
- Linkli liste (linked list) kavramı
  - Çalışma sırasında boyutu ve şekli değiştirilebilen bir veri yapısıdır. Ardışık elemanlar birbirine işaretçilerle (pointer) bağlanır; her düğüm (node) bir sonrakini gösterir.
  - Dinamik olduğu için yalnız gerektiği kadar bellek kaplar. Düğümler hızlıca yeniden düzenlenebilir: araya ekleme, aradan silme, ters çevirme.
  - Listeye erişmek için yalnız ilk düğümün adresi (`head`) yeterlidir. Son düğümün `next` alanı `NULL`'dır; gezinti `NULL` görülünce biter.
  - Soyut veri tipidir (abstract data type): içinde ne tutulacağını kullanıcı tanımlar, kullanırken gerçekleştirme ayrıntılarıyla uğraşılmaz. İşlemler bir kütüphane olarak yazılıp tekrar kullanılabilir. C++/Java/C# gibi dillerde veri ve davranışın birlikte paketlenmesi sınıf (class) kavramına götürür.
- Linkli listelerde temel işlemler (ekrandan, 00:35:00)
  - Liste yaratmak (`head = NULL`), listeyi gezmek, başa/araya/sona eleman eklemek, baştan/aradan/sondan eleman silmek, iki listeyi (sıralı) birleştirmek, liste boyutunu bulmak, listeyi tersine çevirmek, listede eleman aramak.
- C'de düğüm tanımı (ekrandan, 00:40:00)
  - `typedef struct node *link; struct node { [type] data; link next; };` ya da `typedef struct link { [type] data; struct link *next; } node;`
  - Yeni düğüm: `link x = (node *)malloc(sizeof *x);`
  - Gezinti: `head`'den başlayıp `NULL` olmadığı sürece `t = t->next` ile ilerlenir, her adımda `t->data` kullanılır. İşaretçi olduğu için alanlara `->` ile erişilir.
- Linkli listeye eleman eklemek
  - Önce yeni düğümün bağlantısı kurulur, sonra öncekinin bağlantısı yeni düğüme çevrilir: `x->next = a->next; a->next = x;` (ekrandan, 00:45:00). Sıra ters olursa listenin geri kalanı kaybolur.
  - Başa ekleme (`insert_top`): yeni düğümün `next`'i eski `head` olur, yeni `head` döndürülür (ekrandan, 01:20:00).
  - `insert_before`: aranan değerden önceye ekler; `current->next->data` karşılaştırıldığı için ilk eleman olarak eklemede çalışmaz. <!-- BELİRSİZ: insert_before ve silme fonksiyonlarının slayt kodları karelerde yok; yalnız anlatımdan aktarıldı. -->
- Dizi ile sıralı linkli liste (`a` değer dizisi, `link` bağlantı dizisi, `head` başlangıç indisi, `-1` son)
  - Ekleme akışı (ekrandan, 00:50:00): yeni eleman dizinin sonuna yazılır (`a[n] ← ekle`, `n ← n+1`). `a[head] < ekle` değilse yeni eleman başa geçer (`link[n-1] ← head`, `head ← n-1`). Değilse `prev ← head`, `next ← link[head]` ile `next ≠ -1 && a[next] < ekle` olduğu sürece ilerlenir; sonra `link[prev] ← n-1`, `link[n-1] ← next`.
  - Örnek: `a = {2,4,6,8}`, `L = {1,2,3,-1}`, `head = 0`; 1 eklenince `L = {1,2,3,-1,0}`, `head = 4`; 5 eklenince `L = {1,5,3,-1,0,2}`, gezinti 1, 2, 4, 5, 6, 8 (ekrandan, 01:00:00). Ekleme en kötü $O(n)$'dir.
  - Silme akışı (ekrandan, 01:35:00): `sil = a[head]` ise `head ← link[head]`. Değilse `prev`, `adr` ile `adr ≠ -1 && a[adr] < sil` olduğu sürece ilerlenir; `adr = -1 || a[adr] > sil` ise "eleman yok", değilse `link[prev] ← link[adr]`.
  - Örnek: `a = {2,3,4,6,7,8}`, `head = 0`; 2 silinince `head = 1`; 6 silinince `L = {1,2,4,4,5,-1}`, gezinti 3, 4, 7, 8. Silinen değerler dizide durur ama bağlantısı koptuğu için erişilemez.
- Linkli listeden eleman silmek
  - `a->next = a->next->next;` çalışır, ama silinen düğüm bellekte kalır. Daha iyisi: `b = a->next; a->next = b->next; free(b);` (ekrandan, 01:30:00).
- Linkli liste ile insertion sort (ekrandan, 01:40:00)
  - Sırasız girdi listesi (627, 758, 113) ve sıralı çıktı listesi (101, 515, 838) tutulur. Her adımda girdiden bir düğüm koparılır ve çıktıda olması gereken yere eklenir. Listelerin başına birer boş (dummy) düğüm koymak `head` kontrollerini ortadan kaldırır.
- Çift linkli liste (double linked list)
  - Her düğümde `next` ve `prev` işaretçisi vardır; `head`'den ileri, `tail`'den geri gezilebilir.
  - Araya ekleme (ekrandan, 01:50:00): `new->next = curr->next; curr->next->prev = new; curr->next = new; new->prev = curr;`
  - Silme (ekrandan, 01:55:00): önce `del->next->prev = del->prev;`, sonra `del->prev->next = del->next;`, en son `free(del);`.
- Dairesel linkli liste (circular linked list) ve Josephus problemi
  - Son düğüm `NULL` yerine `head`'i gösterir. Sona gelindiği, `head`'e geri dönüldüğü kontrol edilerek anlaşılır.
  - Josephus problemi: $N$ kişi çember oluşturur, her $M$. kişi çıkarılır, sona kalan bulunur. $N = 9$, $M = 5$ için çıkarılma sırası 5, 1, 7, 4, 3, 6, 9, 2; sona kalan 8 (ekrandan, 02:20:00).
  - Kod (ekrandan, 02:25:00): tek düğümlü listede `t->next = t`; 2'den $N$'e kadar her yeni düğüm `t`'ye bağlanır; `x != x->next` olduğu sürece $M-1$ adım ilerlenip `x->next = x->next->next` yapılır.
- Dairesel çift linkli liste ve diğer varyantlar (ekrandan, 02:35:00)
  - İleri ve geri iki döngü tutulur (kasa şifresi gibi iki yönlü sayma gereken problemler).
  - Seyrek (sparse) matrisler yalnız dolu gözler düğüm olarak tutulabilir. Çizgelerde komşuluk listeleri, satır sayısı sabit ama sütunları dinamik bir "dizilerin dizisi" yapısı olarak kurulabilir. Sağ ve aşağı bağlantılı düğümlerle matris benzeri yapılar oluşturulabilir.
- Diziler ve linkli listelerin karşılaştırması (ekrandan, 02:40:00)
  - Dizi uygun: sona ekleme/silme, rastgele erişim, belirli bir değer için arama (ör. sıralıysa ikili arama).
  - Linkli liste uygun: araya eleman ekleme, eleman silme, sıralı erişim gerektiren uygulamalar, eleman sayısının tahmin edilemediği durumlar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bağlantı sırası
  - Ekleme ve silmede listenin geri kalanını kaybetmemek için bağlantılar belli bir sırayla kurulmalıdır. Önce yeni düğümün bağlantısı, sonra öncekinin bağlantısı değiştirilir. Çift linkli listede iki yönün de sırası gözetilir.
- Belleği temizlemek
  - Listeden çıkarılan düğüm `free` edilmezse program bitene kadar boşuna yer kaplar. Slaytlarda yer kazanmak için `free` yazılmadı; kod yazarken eklenmelidir.
- Fonksiyonların sınır durumları
  - `insert_before` ilk eleman eklemesinde çalışmaz; başa ekleme için `insert_top` ayrıca yazıldı. Son eleman için de `NULL` kontrolü gerekir. Hoca dört ayrı fonksiyonun (`insert_top`, `insert_bottom`, `insert_before`, `insert_after`) tek bir ekleme fonksiyonunda birleştirilmesini alıştırma olarak bıraktı.
- Algoritmanın gücü veri yapısından gelebilir
  - Josephus çözümünde algoritmik olarak yalnız bir döngü ve bir atama vardır; gücü dairesel linkli listenin silme ve başa dönme özelliğinden gelir.
- Linkli listeleri uygulayarak çalışmak
  - Ekleme, silme, gezme ve arama kodları tek yönlü, çift yönlü ve dairesel listelerde yazılmalıdır. Bu, işaretçi aritmetiğini oturtur. Sonraki haftalarda yığıt ve kuyruk da linkli listeyle gerçekleştirilebilecektir.

## Kısa Tekrar Notları

- Dizide araya ekleme/silme en kötü $O(n)$; linkli listede bağlantı değişimi sabit sayıda işlemdir (yeri bulmak için gezinti ayrıca gerekir).
- Linkli listeyi tanımlayan tek şey `head`'dir; boş liste `head = NULL`.
- Ekleme: `x->next = a->next; a->next = x;`
- Silme: `b = a->next; a->next = b->next; free(b);`
- Başa ekleme yeni `head`'i döndürür.
- Dizi ile linkli liste: `a[]` değerleri, `link[]` sonraki indisi, `-1` sonu gösterir; silinen eleman dizide kalır ama erişilemez.
- Çift linkli liste: `next` + `prev`, `head` + `tail`.
- Dairesel liste: son düğüm `head`'i gösterir; Josephus ($N = 9$, $M = 5$) cevabı 8.
- Rastgele erişim ve sona ekleme → dizi; sık araya ekleme/silme ve bilinmeyen eleman sayısı → linkli liste.

## Detaylı Açıklamalar

- **Dizilerden linkli listelere geçiş.** Dizide eleman indisle doğrudan okunur, ama başa bir eleman eklemek için bütün elemanlar birer göz kaydırılır; ilk eleman silinince de hepsi geri kaydırılır. Bu işlemler sık yapılıyorsa her seferinde $O(n)$ maliyet gelir. Linkli listede her düğüm verisini ve bir sonraki düğümün adresini tutar. Hoca bunu, herkesin kendinden sonra gelen kişiyi parmağıyla gösterdiği bir zincire benzetti. Son kişi kimseyi göstermez (`NULL`). Listenin nereden başladığını bilmek için tek bir işaretçi (`head`) yeterlidir.
- **C'de düğüm ve gezinti.** Düğüm bir `struct` olarak tanımlanır: veri alanı (derste basitlik için `int data`) ve aynı struct tipinden bir `next` işaretçisi. Gezinti `for (t = head; t != NULL; t = t->next) use(t->data);` mantığıyla yapılır. İki adım atlamak için `t->next->next` kullanılabilir. <!-- BELİRSİZ: gezinti döngüsünün slayttaki birebir yazımı karelerde yok; anlatımdan kuruldu. -->
- **Başa ekleme kodu** (ekrandan, 01:20:00):

```c
typedef struct link {
  int data;
  struct link *next;
} Node;

Node * insert_top(int num, Node *head) {
  Node *new_node;
  new_node = (Node *) malloc(sizeof(Node));
  new_node->data = num;
  new_node->next= head;
  head = new_node;
  return head;
}
```

  - Bu fonksiyon, ajan tarafından bir `main` ve listeyi yazdıran bir fonksiyonla birlikte `gcc -Wall` ile derlenip çalıştırıldı; 4, 3, 2, 1 sırayla başa eklenince liste 1 2 3 4 oldu.
- **Dizi ile sıralı linkli liste.** Akış diyagramında işaretçi çizmek zor olduğu için hoca listeyi iki diziyle anlattı. `a = {4, 7, 1, 2}`, `link = {1, -1, 3, 0}`, `head = 2` örneğinde gezinti 1, 2, 4, 7'dir (ekrandan, 00:50:00). Değer dizisi sırasız dursa bile bağlantı dizisi sayesinde sıralı bir liste tutulur. 0 eklenince `head` 4'e geçer ve `link[4] = 2` olur; 9 eklenince sona kadar gezilir, `link[1] = 5`, `link[5] = -1` olur (ekrandan, 00:55:00). Bu değerler python ile kontrol edildi.
- **Silmede bellek.** `a->next = a->next->next` listeyi doğru günceller, ama koparılan düğüm bellekte sahipsiz kalır. Özellikle bellek kısıtlı sistemlerde geçici bir işaretçiyle tutulup `free` edilmelidir.
- **Josephus kodu** (ekrandan, 02:25:00):

```c
int i, N=9, M=5;
link t = malloc(sizeof *t), x = t;

t->data = 1; t->next = t;

for (i=2; i <= N; i++){
    x = (x->next = malloc(sizeof *x));
    x->data = i; x->next = t;
}

while (x != x->next){
    for(i=1; i<M; i++) x=x->next;
    x->next = x->next->next;
    N--;
}
printf("%d\n", x->data);
```

  - Döngü başında `x` son düğümdedir (9). $M-1$ adım ilerleyince `x` çıkarılacak kişiden bir önceki düğüme gelir, `x->next = x->next->next` ile sıradaki kişi çember dışında kalır. Kod, ajan tarafından `typedef struct node *link;` tanımı ve `main` eklenerek derlendi; çıkarılma sırası 5, 1, 7, 4, 3, 6, 9, 2 ve çıktı 8 oldu. Slaytta da `free` yoktur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
