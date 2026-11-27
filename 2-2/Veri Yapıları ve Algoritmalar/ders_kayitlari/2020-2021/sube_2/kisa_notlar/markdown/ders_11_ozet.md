# Ders 11 Çalışma Özeti

## Genel Konular

- Bağlı liste ile kuyruk (queue) gerçeklemesi
  - Kuyruk, FIFO (first in, first out) çalışan bir veri yapısıdır. Dizi ile gerçeklemede front ve rear indisleri kullanılarak elemanları kaydırmadan sabit sayıda işlemle ekleme ve çıkarma yapılabildiği hatırlatıldı.
  - Bağlı liste ile gerçeklemede iki yapı vardır: `data` ve `next` alanlı düğüm (`Node`) ve `count`, `front`, `rear` alanlarını bir arada tutan kuyruk yapısı (`Queue`). `FULL` (örnekte 10) kuyruk için bir üst sınırdır (ekrandan, 00:10:00).
  - İlklendirme: `count = 0`, `front` ve `rear` `NULL` yapılır. Boşluk kontrolü sayaçla ya da `rear == NULL` / `front == NULL` ile yapılabilir.
  - `enqueue`: yeni düğüm oluşturulur, `next` alanı `NULL` yapılır. Kuyruk boş değilse eski `rear` düğümünün `next`'i yeni düğüme bağlanır ve `rear` yeni düğüme taşınır; boşsa `front` ve `rear` aynı yeni düğümü gösterir. Sonra sayaç bir artırılır (ekrandan, 00:15:00).
  - `dequeue`: `front` düğümünün verisi bir değişkene kopyalanır, geçici işaretçi `front`'u gösterir, `front` bir sonraki düğüme kaydırılır, sayaç azaltılır, eski düğüm `free` edilir ve veri döndürülür (ekrandan, 00:20:00).
  - Karmaşıklıklar: `enqueue`, `dequeue`, `peek`, `isEmpty`, `isFull` işlemlerinin hepsi $O(1)$'dir; dizi ve bağlı liste gerçeklemesinde aynıdır.
- Ağaç (tree) tanımı
  - Hiyerarşik yapıda birbirine bağlı ve kapalı çevrim oluşturmayan sonlu düğümler kümesidir (ekrandan, 00:25:00).
  - Başka bir tanım: yönlü bağlantıları olan, kendisine doğru kenar içermeyen bir kök (root) düğümü bulunan, kök dışındaki her düğüme tek bir kenar gelen ve kökten her düğüme giden yolun tek olduğu düğümler topluluğu.
  - Kapalı çevrim oluşursa ya da bir düğüme birden fazla yoldan gidilebiliyorsa yapı ağaç değil, graftır. Ağaçlar grafların özel bir hâlidir.
  - Örnekler: soy ağacı, şirket organizasyon şeması, tenis turnuvası tablosu (ikili ağaç), içindekiler tablosu, dosya sistemi, veritabanı indeksleri.
- İkili, üçlü ve M dereceli ağaçlar
  - Her düğümden en fazla iki bağlantı çıkıyorsa ikili ağaç (binary tree), en fazla üç çıkıyorsa üçlü ağaç (ternary tree), genel olarak M-ary tree denir.
  - Kökü belirlenmiş ağaca köklü ağaç, kökü belirlenmemiş ama çevrim içermeyen ağaca serbest ağaç denir.
- Temel kavramlar (ekrandan, 00:40:00 ve 00:45:00)
  - Kök: bütün düğümlerin atası olan düğüm; ağaca erişim noktasıdır (bağlı listenin head'i gibi).
  - Ebeveyn (parent), çocuk/evlat (child), kardeş (sibling), yaprak (leaf, external node), iç düğüm (internal node), ata (ancestor), torun/alt soy (descendant), alt ağaç (subtree).
  - Derece (degree): bir düğümün doğrudan evlat sayısı. Ağacın derecesi düğüm derecelerinin en büyüğüdür.
  - Yükseklik (height): kök ile yapraklar arasındaki en uzun yolun kenar sayısı. Yaprağın yüksekliği 0'dır.
  - Derinlik (depth): bir düğümden köke olan kenar sayısı. Kökün derinliği 0'dır.
  - Seviye (level): kökün seviyesi 1'dir; $\text{Level} = \text{Depth} + 1$.
  - $h$ yükseklikteki bir ikili ağaçta en fazla $2^{h+1} - 1$ düğüm olabilir. Slaytta $2^h - 1$ yazıyordu; bir öğrencinin sorusu üzerine derste düzeltildi.
- İkili ağacı dizi ile gösterme
  - Tablo gösterimi: her satırda veri, sol evlat indisi ve sağ evlat indisi tutulur; evlat yoksa $-1$ yazılır. Kökün indisi ve ilk boş gözü gösteren "boş" değişkeni (free list) tutulur (ekrandan, 01:10:00).
  - Dizi tabanlı gösterim: kök 0. indiste, $j$ indisindeki düğümün sol çocuğu $2j+1$, sağ çocuğu $2j+2$, ebeveyni $\lfloor (j-1)/2 \rfloor$ indisindedir.
  - Ağaç dolu değilse çok yer boşa gider. En kötü durumda (zincir şeklinde ağaç) 4 eleman için 15 gözlük dizi gerekir; bellek gereksinimi $2^n$ mertebesindedir (ekrandan, 01:15:00).
- İkili ağacı işaretçi ile gösterme
  - Her düğüm `data`, `left` ve `right` alanlarını tutar. Yalnız var olan düğümler kadar bellek harcanır (ekrandan, 01:20:00).
  - `createTree` yeni bir düğüm oluşturur, verisini yazar ve iki çocuğunu `NULL` yapar.
  - Özyinelemeli tanım: ikili ağaç ya boştur ya da bir kök ile sol ve sağ alt ağaç denen iki bağımsız ikili ağaçtan oluşur.
- İkili ağacın özel durumları (ekrandan, 01:25:00)
  - Full binary tree: her düğümün 0 ya da 2 çocuğu vardır.
  - Complete binary tree: son düzey hariç bütün düzeyler tam doludur, son düzey de soldan başlayarak doldurulmuştur. Heap'ler complete binary tree olacaktır.
  - Perfect binary tree: bütün iç düğümlerin iki çocuğu vardır ve bütün yapraklar aynı seviyededir. Hem full hem complete'tir.
  - Balanced (dengeli) binary tree: $n$ düğümlü ağacın yüksekliği $\log n$ mertebesinde kalır. Yükseklik bundan fazlaysa ağaç degenerate (patolojik) olur; en kötü durumda bağlı listeye dönüşür.
- İkili ağaçta ekleme ve silme (küçükler sola, büyükler sağa kuralıyla)
  - Ekleme özyinelemelidir: düğüm `NULL` ise yeni düğüm oluşturulur; veri küçükse sol alt ağaca, büyükse sağ alt ağaca eklenir (ekrandan, 01:35:00).
  - Silmede önce düğüm aynı kuralla bulunur. Üç durum vardır: yaprak doğrudan silinir; tek çocuklu düğümün çocuğu düğümün ebeveynine bağlanır; iki çocuklu düğümde ya sol alt ağacın en büyüğü ya da sağ alt ağacın en küçüğü düğümün yerine kopyalanır ve o kopyalanan düğüm alt ağaçtan özyinelemeli olarak silinir. Slayttaki kod sağ alt ağacın en küçüğünü (`minValueNode`) kullanır (ekrandan, 01:40:00).
- Ağaç gezintileri (traversal)
  - Derinlik öncelikli gezintilerde üç hamle vardır: sola git (L), düğümü ziyaret et (V), sağa git (R). Ayna görüntüsü olan sıralar aynı sayıldığı için üç gezinti kalır.
  - Preorder (kök önde, VLR), inorder (kök ortada, LVR), postorder (kök sonda, LRV).
  - Örnek ağaçta (kök 60; 60'ın çocukları 20 ve 70; 20'nin çocukları 10 ve 40; 40'ın çocukları 30 ve 50) preorder sırası 60, 20, 10, 40, 30, 50, 70; inorder sırası 10, 20, 30, 40, 50, 60, 70; postorder sırası 10, 30, 50, 40, 20, 70, 60'tır (ekrandan, 01:50:00, 02:10:00 ve 02:15:00).
  - Inorder gezinti, özyineleme yerine açık bir yığıt (stack) ile de yapılabilir: sola gidilebildiği kadar düğümler yığıta itilir, sonra çekilen düğüm ziyaret edilip sağına geçilir.
  - Genişlik öncelikli (seviye sıralı) gezinti kuyruk ile yapılır: kök kuyruğa konur; kuyruktan çekilen her düğüm ziyaret edilir ve çocukları soldan sağa kuyruğa eklenir. Örnek ağaçta sıra f, c, j, a, d, h, k, i'dir (ekrandan, 02:20:00).
- Gezintilerin uygulamaları
  - Ağaç kopyalama postorder mantığıyla yapılır: önce sol ve sağ alt ağaçlar kopyalanır, sonra düğümün verisi kopyalanır.
  - İki ağacın eşitliğini kontrol etmek için önce düğümü karşılaştırmak (preorder mantığı) daha uygundur; ilk eşitsizlikte gezinti bırakılabilir.
- Genel (çok çocuklu) ağacı ikili ağaç olarak gösterme
  - Her düğümde iki işaretçi tutulur: ilk çocuk ve sağdaki kardeş (sol çocuk, sağ kardeş gösterimi). Böylece her ağaç ikili ağaç olarak tutulabilir ve ikili ağaç işlemleri genel ağaçlarda da kullanılabilir; yalnız seviye sayısı artar (ekrandan, 02:30:00).
- İkili arama ağacı (binary search tree, BST)
  - Her A düğümü için A'nın değeri sol alt ağacındaki ($T_L$) bütün değerlerden büyük, sağ alt ağacındaki ($T_R$) bütün değerlerden küçüktür; $T_L$ ve $T_R$ de birer ikili arama ağacıdır (ekrandan, 02:35:00).
  - Değerler sayı olmak zorunda değildir; alfabetik sıralı adlarla da kurulabilir.
  - Arama: aranan değer kökten küçükse sola, büyükse sağa gidilir; eşitse düğüm, `NULL`'a ulaşılırsa `NULL` (bulunamadı) döndürülür.
  - BST'de silmenin üç durumu ve en küçük/en büyük değeri bulan `findMin`/`findMax` fonksiyonları (ekrandan, 02:45:00 ve 02:50:00).
  - Elemanlar rastgele sırayla eklenip silinirse ağaç ortalamada $\log n$ yükseklikte kalır ve arama $O(\log n)$ olur. Sıralı gelen elemanlarla ağaç zincire döner; en kötü durum $O(n)$'dir.
  - Dengeyi koruyan BST çeşitleri olarak AVL, B-tree, 2-3 ve 2-3-4 ağaçları, red-black ve splay ağaçlarının yalnız adları verildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kapalı çevrim yasağı
  - Ağacın tanımındaki en önemli kısım kapalı çevrim oluşturmamasıdır. Çevrim varsa bir düğüme birden çok yoldan gidilir ve yapı ağaç olmaktan çıkıp graf olur.
- Ağacın etkinliği yüksekliğinden gelir
  - Dengeli ağaçta bir yaprağa en fazla $\log n$ adımda ulaşılır, çünkü her adımda bir alt ağaç tamamen dışarıda kalır. Bu yüzden arama ve indeks mekanizmalarında ağaç kullanılır. Degenerate ağaçta bu üstünlük kaybolur.
- Dizi gösteriminin bellek israfı
  - Dizi ile tutulan ağaç tam dolu değilse boş gözler için de yer ayrılır; zincir şeklindeki ağaçta israf üstel büyür. Bu yüzden işaretçili gösterim tercih edilir.
- Silmede dikkat
  - Eklemede tek gereken bir kural (küçükler sola, büyükler sağa) koymaktır; silmede ise üç durumun ayrı ayrı düşünülmesi ve sıralama düzeninin bozulmaması gerekir.
- Yığıt ve kuyruğun ağaçta kullanımı
  - Yalnız veri yapısını değiştirerek (yığıt yerine kuyruk) derinlik öncelikli gezintiden genişlik öncelikli gezintiye geçilebilir.
- Farklı işlemler farklı gezinti ister
  - Kopyalamada postorder, eşitlik kontrolünde önce düğümü karşılaştıran preorder daha uygundur.
- Problemde aksi söylenmedikçe dengeli ağaç
  - Hoca, bir problemde verilen ağacın aksi belirtilmedikçe dengeli kabul edilip aramanın $O(\log n)$ alınabileceğini, "dengesiz" denirse $O(n)$ düşünülmesi gerektiğini söyledi. AVL ve red-black ağaçlarına merak edenlerin bakabileceğini, bunlardan sorumlu olunmadığını belirtti.

## Kısa Tekrar Notları

- Bağlı liste ile kuyruk: `Queue { count, front, rear }`. `enqueue` sona (`rear`), `dequeue` baştan (`front`) yapılır; hepsi $O(1)$.
- Ağaç: kapalı çevrimsiz, hiyerarşik, sonlu düğümler kümesi; kökten her düğüme tek yol.
- Derece = doğrudan evlat sayısı; ağacın derecesi = en büyük derece.
- Yükseklik: kökten en uzak yaprağa kenar sayısı. Derinlik: düğümden köke kenar sayısı. Seviye = derinlik + 1.
- $h$ yükseklikteki ikili ağaçta en çok $2^{h+1}-1$ düğüm.
- Dizi gösterimi: sol çocuk $2j+1$, sağ çocuk $2j+2$, ebeveyn $\lfloor (j-1)/2 \rfloor$.
- Full: 0 ya da 2 çocuk. Complete: son düzey soldan dolu. Perfect: bütün yapraklar aynı seviyede. Balanced: yükseklik $O(\log n)$.
- Gezintiler: preorder VLR, inorder LVR, postorder LRV; seviye sıralı gezinti kuyrukla.
- Gezinti örneğindeki ağaçta inorder sırası küçükten büyüğe çıktı: 10, 20, 30, 40, 50, 60, 70.
- BST silme: yaprak → sil; tek çocuk → çocuğu ebeveyne bağla; iki çocuk → sağın en küçüğünü (ya da solun en büyüğünü) kopyala, onu sil.
- BST arama: ortalama $O(\log n)$, en kötü $O(n)$.
- Genel ağaç → ikili ağaç: ilk çocuk + sağ kardeş işaretçileri.

## Detaylı Açıklamalar

### Bağlı liste ile kuyruk

Ders, önceki derste başlanan kuyruk konusunun tamamlanmasıyla başladı. Dizi ile gerçeklemede front ve rear indisleri sayesinde her ekleme ve çıkarmada elemanları kaydırmaya gerek kalmadığı, tek bir iç içe `if` ile dizinin başa sarılabildiği hatırlatıldı. Önceki dersin "Alternatif Gerçekleme" slaytında bu yapı şöyleydi (ekrandan, 00:05:00):

```c
#define MAX 6

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int isEmpty() { return itemCount == 0;}
int isFull() { return itemCount ==MAX;}
int size() { return itemCount; }

void enqueue(int data) {
   if(!isFull()) {
      if(rear == MAX-1) {
         rear = -1;
      }
      intArray[++rear] = data;
      itemCount++;
   }
}

int dequeue() {
   int data = intArray[front++];
   if(front == MAX) {
      front = 0;
   }
   itemCount--;
   return data;
}
```

Bağlı liste ile gerçeklemede dizi yerine A, B, C değerlerini tutan bir bağlı liste kullanılır. Kuyruğun kendisi ise üç değişkenin bir arada durduğu bir yapıdır (ekrandan, 00:10:00):

```c
#define FULL 10

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct queue{
    int count;
    Node *front;
    Node *rear;
}Queue;
```

`count` olmadan da kuyruk çalışır, ama o zaman sınırsız bir kuyruk olur; hoca her zaman bir sınır (`FULL`) koymanın faydalı olduğunu söyledi. Ekleme ve çıkarma kodları (ekrandan, 00:15:00 ve 00:20:00):

```c
void enqueue(Queue *q, int value){
    if (q->count < FULL){
        Node *tmp;
        tmp = malloc(sizeof(Node));
        tmp->data = value;
        tmp->next = NULL;
        if(!isempty(q)){
            q->rear->next = tmp;
            q->rear = tmp;
        }
        else{
            q->front = q->rear = tmp;
        }
        q->count++;
    }
    else{
        printf("List is full\n");
    }
}

int dequeue(Queue *q)
{
    Node *tmp;
    int n = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return(n);
}
```

`dequeue`'da sıra önemlidir: önce veri kopyalanır ve geçici işaretçi eski ön düğümü tutar, sonra `front` kaydırılır, en son eski düğüm serbest bırakılır.

### Ağaç kavramları

Hoca ağacı önce doğadaki ağaçla karşılaştırdı: köklerin altta, dalların ve yaprakların üstte olduğu ağacı ters çevirince bilgisayar bilimindeki ağaç elde edilir. Slayttaki örnek ağaçta (A'nın çocukları B ve C; C'nin çocukları D ve E; D'nin çocukları F ve G; G'nin çocuğu H) A kök; C, D, G ebeveyn; B, E, F, H yapraktır. Ağacın derecesi 2'dir. A'dan H'ye 4 kenar olduğu için ağacın yüksekliği 4'tür (ekrandan, 00:40:00 ve 00:45:00).

İkinci örnekte (A'nın çocukları B ve C; B'nin çocukları D ve E; C'nin çocukları F, G ve H; H'nin çocuğu I) D, E, F, G, I yaprak; A, B, C, H iç düğümdür. Ağaç 4 seviyelidir, yüksekliği 3'tür. B'nin derecesi 2, ağacın derecesi 3'tür (C'nin üç çocuğu var). I'nın ataları H, C, A; C'nin alt soyu F, G, H, I'dır (ekrandan, 00:50:00).

Derinlik ve yükseklik birbirini tümleyen kavramlardır: kökün derinliği 0, yüksekliği ağacın yüksekliğidir; en derindeki yaprağın derinliği ağacın yüksekliğine eşit, yüksekliği 0'dır. Ara düğümlerde ise aynı derinlikteki kardeşlerin yükseklikleri farklı olabilir.

### Dizi ile gösterim

Tablo gösteriminde (ekrandan, 01:10:00) kök 0. indisteki Jane'dir; Jane'in çocukları 1 (Bob) ve 2 (Tom), Bob'un çocukları 3 (Alan) ve 4 (Ellen), Tom'un sol çocuğu 5 (Nancy)'tir. İlk boş göz 6 iken Mary eklenince 6. göze yazılır, Nancy'nin sol evladı 6 yapılır ve "boş" değişkeni 7 olur. Ardından 4. indisteki düğüm (Bob'un sağ evladı) silinirse Bob'un sağ evlat indisi $-1$ yapılmalı ve boşalan 4. göz ilk yazılabilecek yer olduğu için "boş" değişkeni 7 yerine 4 olmalıdır. Hoca, Bob'un evlat indisinin slaytta güncellenmediğini sözlü olarak belirtti.

<!-- BELİRSİZ: Altyazıda silinen düğümün adı "Alan" ve "Elan" diye geçiyor; karede 4. indiste Ellen, 3. indiste Alan var. Anlatım (4. indis, Bob'un sağ evladı) silinenin büyük olasılıkla Ellen olduğunu gösteriyor. -->

Dizi tabanlı gösterimde (ekrandan, 01:15:00) p, g, r, b, h, v, k harfli ağaç `p g r b h _ v _ _ _ k` biçiminde yerleşir; boş gözler `_` ile gösterilmiştir. En kötü durumda p, r, v, z zincirinde z 14. indise düşer ve yalnız 4 eleman için 15 gözlük dizi gerekir.

### İşaretçi ile gösterim ve ekleme/silme

```c
typedef struct node *tree;
typedef struct node{
      int data;
      tree left, right;
      // tree child, sibling;
}node;

tree createTree(int data){
      tree T = (tree)malloc(sizeof(tree));
      T->data = data;
      T->left = NULL;
      T->right = NULL;
      return T;
}
```

(ekrandan, 01:20:00)

- Ders sonrası not: Slayttaki `malloc(sizeof(tree))` yalnız bir işaretçi boyutu kadar yer ayırır, çünkü `tree` bir işaretçi tipidir. Doğrusu `malloc(sizeof(node))` olmalıdır. Hoca bunu derste belirtmedi.

Ekleme kodu (ekrandan, 01:35:00):

```c
tree insert(tree node, char data){
      if (node == NULL) return createTree(data);

      if(data < node->data)
            node->left = insert(node->left, data);
      else if (data > node->data)
            node->right = insert(node->right, data);

      return node;
}
```

Derste sırayla K, D, M, R, L, N, A harfleri eklendi: D ve A K'nin solunda; M K'nin sağında; L M'nin solunda; R M'nin sağında; N R'nin solunda yer aldı. Silme kodu (ekrandan, 01:40:00):

```c
tree del(tree root, char data){
      if (root==NULL) return root;

      // silinecek küçükse soldadır
      if(data < root->data)
            root->left = del(root->left, data);
      //silinecek büyükse sağdadır
      else if(data > root->data)
            root->right = del(root->right, data);
      // bu nodu sileceğiz
      else{
            //node with 1 or 0 child
            if (root->left == NULL){
                  tree temp = root->right;
                  free(root);
                  return temp;
            }
            else if (root->right == NULL){
                  tree temp = root->left;
                  free(root);
                  return temp;
            }
            tree temp = minValueNode(root->right);
            root->data = temp->data;

            root->right = del(root->right, temp->data);
      }
      return root;
}
```

Bu ağaçta L yaprak olduğu için doğrudan silinir; R'nin tek çocuğu N olduğundan N, M'ye bağlanır; M'nin iki çocuğu olduğundan ya soldaki en büyük (L) ya da sağdaki en küçük (N) M'nin yerine yazılır. Slayttaki kod N'yi seçer.

### Gezintiler

Üç derinlik öncelikli gezintinin kodu aynı üç satırdan oluşur; tek fark ziyaret satırının yeridir. Kodlar altyazıdaki anlatımdan kurulmuştur; ilgili slaytların karesi yoktur:

```c
void preTraverse(tree T){
    if (T == NULL) return;
    visit(T);
    preTraverse(T->left);
    preTraverse(T->right);
}
```

<!-- BELİRSİZ: Gezinti, yığıtla inorder, ağaç kopyalama ve eşitlik kodlarının slaytları karelerde yok; yukarıdaki preorder kodu ve aşağıdaki açıklamalar altyazıdaki anlatımdan kurulmuştur, adlar slayttakinden farklı olabilir. -->

Yığıt ile inorder gezintide `current` kökten başlar; `current` `NULL` olmadıkça yığıta itilip sola gidilir. Sol taraf bitince yığıttan bir düğüm çekilir, ziyaret edilir ve `current` o düğümün sağına geçer. Yığıt boşalıp `current` `NULL` olunca gezinti biter.

Seviye sıralı gezinti örneğinde (ekrandan, 02:20:00) kuyruğun durumu şöyle ilerler: f → c, j → j, a, d → a, d, h, k → d, h, k → h, k → k, i → i → boş. Ziyaret sırası f, c, j, a, d, h, k, i'dir.

### İkili arama ağacı

Slayttaki sayısal BST'de (ekrandan, 02:35:00) kök 21; solunda 3 (çocukları 2 ve 8; 8'in çocukları 5 ve 13), sağında 34 (sağ çocuğu 55) vardır. 21 kökte bulunur; 8 için 21 → 3 → 8 yolu izlenir; 80 için 21 → 34 → 55 → `NULL` yolu izlenir ve `NULL` döndürülür.

Silme örnekleri 94 kökü olan ağaçta gösterildi (94'ün çocukları 10 ve 97; 10'un çocukları 5 ve 24; 24'ün sol çocuğu 11; 11'in sağ çocuğu 17). 5 yaprak olduğu için doğrudan silinir. 24 silinince tek çocuğu 11, 10'a bağlanır (ekrandan, 02:45:00). Sonraki slaytta tek (sağ) çocuklu düğüm örneği olarak 11 silindi; çocuğu 17, 24'e bağlandı. İki çocuk durumu için hoca 5'in sağına 9, 9'un soluna 8 ekledi ve 10'u sildi: soldaki en büyük 9 kopyalanırsa 9'un tek çocuğu 8, 5'e bağlanır; sağdaki en küçük 11 kopyalanırsa 11'in çocuğu 17, 24'e bağlanır.

```c
tree findMin(tree T){
   if(T && T->left)
      return findMin(T->left);
   else
      return T;
}
tree findMax(tree T){
   if(T && T->right)
      return findMax(T->right);
   else
      return T;
}
```

(ekrandan, 02:50:00)

10, 20, 30, 40 gibi sıralı gelen değerler hep sağa eklendiği için ağaç $n$ yükseklikte bir zincire döner. Hoca 10, 20, 30 gelince kökün 20 olacak şekilde döndürülmesiyle yüksekliğin düşük tutulabileceğini gösterdi; bu fikir AVL gibi dengeli ağaçların temelidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
