# Ders 13 Genişletilmiş Notu: Özyinelemeli Örnekler, İkili Arama Ağacı, Dosyadan Yapıya Okuma ve Thread'lere Giriş; Uygulama 4

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Özyinelemeli Fonksiyonla String'i Tersten Yazdırma
- 2. İkili Ağaç ve İkili Arama Ağacı
- 3. Ağaçta Gezinme Yöntemleri
- 4. İkili Arama Ağacının C ile Kodlanması
- 5. Gezinmelerin Kodlanması ve Program Çıktıları
- 6. Arama Karmaşıklığı ve Dengeli Ağaç
- 7. Düğüm Silme
- 8. Dosyadan Yapıya Okuma: Nokta ve Ok Operatörü
- 9. Thread'lere Giriş
- 10. C'de POSIX Thread Kütüphanesi
- 11. Uygulama: Özyinelemeli Yol Kontrolü
- 12. Uygulama: Dosyadaki Kayıtları Bağlı Listede Sıralama
- Örnek Sorular
- Dersin Toparlaması

## 1. Özyinelemeli Fonksiyonla String'i Tersten Yazdırma

Derste bu hafta birkaç örnek çözüleceği söylenir: bir ikili arama ağacı, bir dosya örneği, özyinelemeli örnekler ve thread'ler hakkında bilgilendirme. Thread konusu bu dersin sınav kapsamında değildir, ama işletim sistemleri dersinde thread ile proje ya da ödev verildiği için C'de thread yazmanın mantığı şimdiden öğrenilmelidir.

İlk örnek bir string'i özyinelemeli (recursive) bir fonksiyonla tersten yazdırmaktır. Bir string'in sonuna gelindiği `'\0'` karakteri görülünce anlaşılır. O halde `str`'nin gösterdiği karakter boş karakter değilse okunacak bir karakter var demektir. Koşul `if(*str)` biçiminde yazılabilir; `!= '\0'` ya da `NULL` ile karşılaştırma yazmak gerekmez.

Özyinelemeli fonksiyonlar sonuçları sondan geriye doğru toplar. Örneğin $5!$ hesaplanırken `f(n)` içinden `f(n-1)` çağrılır; önce $1!$ hesaplanır, sonra $2!$, $3!$ ve diğerleri geri dönülerek bulunur. String örneğinde de fonksiyon kendini `str+1` ile çağırır ve karakteri ancak dönüşte yazar:

```c
#include <stdio.h>
void reverse(char *str){
    if(*str){
        reverse(str+1);
        printf("%c", *str);
    }
}
int main(){
    reverse("Dene");
    printf("\n");
    return 0;
}
```

Bu program ajan tarafından `gcc -Wall` ile derlenip çalıştırıldı; çıktısı `eneD` oldu. (Derste fonksiyonun yapısı anlatıldı; `main` gövdesi ajan tarafından eklendi.)

### 1.1 Çağrı Yığını Üzerinden İzleme

Hoca işleyişi bir yığın (stack) çizerek gösterir (ekrandan, 00:10:00). Program çalışınca önce `main` yığına konur. `main`, `R("Dene")`'yi çağırır; o `R("ene")`'yi, o `R("ne")`'yi, o `R("e")`'yi, o da `R("")`'yi çağırır. Yığında alttan üste `main()`, `R(Dene)`, `R(ene)`, `R(ne)`, `R(e)`, `R()` durur.

Her çağrı aynı satırdan (fonksiyonun içindeki özyinelemeli çağrı satırından) yapılır ve geri dönüş yeri yığında saklanır. `R("")` içinde `if` yanlış olur, fonksiyon biter ve yığından bir çerçeve çekilerek bir önceki çağrının kaldığı satıra dönülür. O satırdan sonraki `printf`, o çerçevedeki `str`'nin gösterdiği karakteri (`e`) yazar. Sonra o çerçeve de biter, `n` yazılır, ardından `e` ve `D`. En sonda `main`'e dönülür ve program biter.

> **Hocanın vurgusu:** Özyinelemeli bir fonksiyonu izlemenin en doğru yolu yığını çizmektir. Faktöriyelde de en alt seviyedeki `f(1)` önce hesaplanır, sonuç geri dönerken çarpılarak toplanır.

Hoca ayrıca ayrık matematikte DFS algoritmasının açık bir yığınla anlatıldığını hatırlatır. Özyinelemeli fonksiyonlar yığını kendiliğinden kullandığı için DFS, ayrı bir yığın yapısı kullanmadan özyinelemeli olarak yazılırsa aynı işi yapar.

## 2. İkili Ağaç ve İkili Arama Ağacı

İkili ağaçta (binary tree) her düğümün en çok iki çocuğu vardır, ama değerler arasında bir büyüklük-küçüklük ilişkisi aranmaz. İkili arama ağacında (binary search tree, BST) ek olarak kökün sağındaki çocuklar kökten büyük, solundakiler kökten küçüktür. Ağaç bir kök ve kökün çocuklarından oluşur; modellemek için her birim bir düğüm (node) olarak yazılır. Düğümde veri ile sol ve sağ çocuğa işaretçiler bulunur; başlangıçta çocuk işaretçilerine `NULL` verilir.

Ağaç üzerinde yapılan temel işlemler ekleme, gezinme (traversal), arama ve silmedir. Ekleme işleminde gelen veri büyükse sağa, değilse sola gidilerek yer bulunur. Hoca heap ağaçlarının başka bir şekilde tasarlandığını ve bu konuların veri yapıları dersinde ayrıntılı işleneceğini belirtir.

### 2.1 Ağacın Dizi ile Gösterimi

Ağaç bağlı liste mantığıyla kurulabileceği gibi dizi ile de tutulabilir. Kök 0. indiste olmak üzere `i` indisli düğümün sol çocuğu `2i+1`, sağ çocuğu `2i+2` indisindedir. Bir düğümün atası (parent) ise $\lfloor (i-1)/2 \rfloor$ indisindedir. Örneğin 3 indisli düğümün atası $(3-1)/2 = 1$, 4 indisli düğümün atası $(4-1)/2 = 1{,}5$ değerinin tam kısmı olan 1'dir.

**Soru:** Bu gösterim için hiçbir boş düğüm olmaması mı gerekir? Sol çocuğun sol çocuğu yoksa ne olur?
**Cevap:** O yer boş (sıfır) bırakılır. Bu durumda dizide çok sayıda boş yer kalabilir; dizi kullanmanın dezavantajlarından biri budur.

Derste ağaç dizi yerine bağlı liste mantığıyla, düğümler `malloc` ile dinamik olarak oluşturularak kurulur.

## 3. Ağaçta Gezinme Yöntemleri

Gezinme yöntemleri matematiksel ifade ağaçlarıyla daha kolay anlaşılır. `a + b` ifadesinde operatör (`+`) kökte, operandlar (`a`, `b`) yapraklardadır. Her yöntem özyinelemeli olarak düşünülür:

- Pre-order (önce kök): kök, sol, sağ. Çıktı `+ a b`.
- In-order (arada kök): sol, kök, sağ. Çıktı `a + b`, yani günlük yazdığımız biçim.
- Post-order (sonra kök): sol, sağ, kök. Çıktı `a b +`.
- Reverse post-order: sağ, sol, kök. Çıktı `b a +`. Pek kullanılmaz.
- Level-order: önce birinci seviye, sonra ikinci seviye, her seviye soldan sağa.

Pre-order ile level-order her zaman aynı sonucu vermez. 1 kökte, 2 ve 3 onun çocukları, 4-5 düğüm 2'nin, 6-7 düğüm 3'ün çocukları olan tam ağaçta level-order `1 2 3 4 5 6 7` verir. Pre-order ise önce kökü, sonra bütün sol alt ağacı bitirdiği için `1 2 4 5 3 6 7` verir.

## 4. İkili Arama Ağacının C ile Kodlanması

### 4.1 Düğüm Yapısı ve Düğüm Oluşturma

Düğüm yapısı `typedef` ile tanımlanır. `data` alanı yerine projede bir öğrenci ya da ders yapısı da tutulabilir:

```c
typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}NODE;
```

<!-- BELİRSİZ: yapının tam yazımı karelerde görünmedi; alan adları ve NODE türü ekrandaki fonksiyonlardan, yapı adı (TreeNode) altyazıdan alındı. -->

Bütün ağacı gezmek için bağlı listedeki `head` gibi yalnız kök (`root`) düğümünü bilmek yeterlidir. Hoca bunu öğrencilere sorar; bir öğrenci önce eleman sayısını, sonra "NULL görene kadar" cevabını verir, doğru cevap baş (kök) düğümün bilinmesidir.

Düğüm oluşturan yardımcı fonksiyon ekrandan (00:30:00):

```c
NODE* createNode(int N){
    NODE *ptr= (NODE*)malloc(sizeof(NODE));
    ptr->data = N;
    ptr->left=ptr->right=NULL;
    return ptr;
}
```

`malloc` `void *` döndürdüğü için `NODE *` türüne dönüştürülür. Yeni düğümün sol ve sağ çocuğu başlangıçta yoktur.

### 4.2 Ana Program ve Kökün Güncellenmesi

`main` içinde `NODE *root = NULL;` ile başlanır. Kullanıcıdan 0 girilene kadar sayı alınır ve her sayı ağaca eklenir. Ekranda ana döngüdeki çağrı `root=insert(root,N);` biçimindedir (ekrandan, 00:30:00).

Kök yalnız ilk eklemede değişir: ağaç boşken gelen ilk eleman kök olur. Sonraki eklemelerde fonksiyon aynı kök adresini döndürür, yani aynı değer yeniden atanır. Bunun yerine bağlı listelerde olduğu gibi kökün adresi (çift işaretçi) de gönderilebilirdi; kök bir kez bile değişecekse fonksiyona adresi verilmelidir.

Hoca bu tür bir BST'de ilk gelen elemanın kök olduğunu ve bir daha değişmediğini vurgular. Tahtadaki örnekte 4, 8, 3, 6, 5, 7, 2 sırasıyla eklenir (ekrandan, 00:35:00): 4 kök olur, 8 sağına, 3 soluna gelir; 6, 8'in soluna; 5 ve 7, 6'nın sol ve sağ çocukları olur; 2 de 3'ün soluna gelir. Ağaç dengesiz büyür. Ayrık matematikte anlatılan dengeli BST oluşturmada düğümlerin yerleri değiştirilerek derinliğe göre dengeleme yapılır; bu ayrı bir konudur.

### 4.3 İteratif Ekleme

İteratif eklemede önce yeni düğüm oluşturulur. Kök `NULL` ise yeni düğüm kök olur ve döndürülür. Değilse kökü kaybetmemek için yardımcı bir `tmp` işaretçisi kökten başlatılır; bir de `tmp`'yi arkadan takip eden, başlangıçta `NULL` olan `tmp2` işaretçisi tutulur. `tmp` `NULL` olana kadar `tmp2 = tmp` yapılır ve yeni değer `tmp`'nin verisinden büyükse sağa (`tmp = tmp->right`), değilse sola (`tmp = tmp->left`) gidilir. Bu, bağlı listelerdeki `tmp = tmp->next` adımının ağaçtaki karşılığıdır. Döngü bir yaprağın boş çocuğuna gelince biter. Ardından yeni değer `tmp2`'nin verisinden büyükse `tmp2->right`, değilse `tmp2->left` yeni düğüme bağlanır. Fonksiyon sonunda `root` döndürülür; aradaki bir yere düğüm bağlamak kökü değiştirmez.

Fonksiyon önce `void insert(NODE *root, int N)` olarak başlatıldı (ekrandan, 00:30:00); derlemede `void` fonksiyonun değer döndüremeyeceği hatası görülünce `NODE *` döndürecek biçime getirildi. Altyazıya göre kurulan ve ajan tarafından derlenip test edilen hali:

```c
NODE* insert(NODE *root, int N){
    NODE *newNode=createNode(N);
    NODE *tmp=root, *tmp2=NULL;
    if(root==NULL){
        root=newNode;
        return root;
    }
    while(tmp!=NULL){
        tmp2=tmp;
        if(N > tmp->data) tmp=tmp->right;
        else tmp=tmp->left;
    }
    if(N > tmp2->data) tmp2->right=newNode;
    else tmp2->left=newNode;
    return root;
}
```

<!-- BELİRSİZ: iteratif insert fonksiyonunun tam metni karelerde görünmüyor; yalnız ilk satırları ekranda (00:30:00). Gövde altyazıdan kuruldu. -->

Derste ilk denemede 6'dan sonra 9 eklenince in-order çıktısında 9 önce yazıldı. Hoca karşılaştırmanın ters yazıldığını fark edip "yeni gelen veri büyükse sağa" olacak şekilde düzeltti. Sonra 6, 9, 3, 4, 2, 15, 8 eklenerek in-order çıktısının `2 3 4 6 8 9 15` olduğu gösterildi (tahta, ekrandan, 00:45:00). Ajan bu diziyi yukarıdaki fonksiyonla ekleyip aynı in-order sırasını elde etti.

### 4.4 Özyinelemeli Ekleme

> **Hocanın vurgusu:** Özyinelemeli eklemeyi yazmak kolaydır ama özyinelemeli düşünmek her zaman kolay değildir.

Bu yöntemde düğüm baştan oluşturulmaz; önce eklenecek yer bulunur, düğüm orada oluşturulup bağlanır. Her alt çağrıda gelinen düğüm bir alt ağacın kökü gibi düşünülür. Ağaçta derinleşirken `NULL` görülen yer durma koşuludur: orada `createNode` ile düğüm oluşturulup döndürülür. Değilse veri kökten büyükse sağ alt ağaca, değilse sol alt ağaca aynı fonksiyonla gidilir ve dönen değer ilgili çocuk işaretçisine atanır (ekrandan, 00:50:00):

```c
NODE* insertR(NODE *root, int data){
    if(root==NULL){
        root=createNode(data);
        return root;
    }
    else if( data > root->data){
        root->right = insertR(root->right,data);
    }
    else{
        root->left = insertR(root->left, data);
    }
    return root;
}
```

Karede son `return root;` satırı henüz yazılmamıştır; hoca her iki dalda da kökün döndürülmesi gerektiğini, bunun için en alta tek bir `return` yazılabileceğini söyler.

> **Hocanın vurgusu:** Dönen değer `root`'a değil, `root->right`'a (ya da `root->left`'e) atanmalıdır. `root`'a atanırsa kök bozulur.

Örnek: ağaçta yalnız 4 varken 8 eklenirse `insertR(root->right, 8)` çağrısı `NULL` görür, 8 düğümünü oluşturup döndürür ve bu adres 4'ün sağ çocuğu olur. 2 eklenince 4'ün sol çocuğuna gidilir, orası `NULL` olduğundan düğüm oluşturulup 4'ün soluna bağlanır.

## 5. Gezinmelerin Kodlanması ve Program Çıktıları

In-order, post-order ve pre-order gezinmeleri iteratif yazmak mümkündür, ama gidilen yerleri unutmamak için birçok değişken gerekir. Bu yüzden kaynakların hemen hepsinde özyinelemeli yazılırlar. In-order fonksiyonu (ekrandan, 00:40:00):

```c
void inOrder(NODE* root){//a + b
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
```

Fonksiyon gidebildiği kadar sola gider; `NULL` ile karşılaşınca o alt ağacın kökünü yazar, sonra sağ alt ağaca geçer. `root->left` ve `root->right` de aynı türde işaretçiler olduğu için aynı fonksiyonla gezilir. Pre-order'da `printf` iki çağrıdan önce, post-order'da iki çağrıdan sonra yazılır:

```c
void preOrder(NODE* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(NODE* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
```

<!-- BELİRSİZ: preOrder ve postOrder fonksiyonlarının son hali karelerde görünmüyor; yapı altyazıdan ve ekrandaki doğru çıktıdan kuruldu. -->

### 5.1 Kopyala-Yapıştır Hatası

İlk çalıştırmada 5, 3, 8, 1, 4, 6, 9, 0 girildi ve çıktılar `0 1 3 4 5 6 8 9`, `5 0 1 3 4 6 8 9`, `0 1 3 4 6 8 9 5` oldu (ekrandan, 00:55:00). Aradan sonra hoca iki sorun olduğunu açıkladı: pre-order ve post-order fonksiyonları in-order'dan kopyalandığı için içlerindeki özyinelemeli çağrılar hâlâ `inOrder`'ı çağırıyordu; ayrıca çıkış için girilen 0 da ağaca ekleniyordu. Bu yüzden ikinci satır kökten sonra alt ağaçları in-order sırasıyla, üçüncü satır da alt ağaçları in-order yazıp kökü sona koydu. 0 için "sıfırdan farklıysa ekle" kontrolü eklenip çağrılar düzeltilince çıktılar şöyle oldu (ekrandan, 01:10:00):

```text
1 3 4 5 6 8 9
5 3 1 4 8 6 9
1 4 3 6 9 8 5
```

Ajan aynı girişle programı derleyip çalıştırdı ve aynı üç satırı elde etti.

### 5.2 Gezinmelerin Elle İzlenmesi

Ağaç: kök 5; 5'in solunda 3, sağında 8; 3'ün çocukları 1 ve 4; 8'in çocukları 6 ve 9.

- In-order: en sola gidilir, 1 yazılır; kök 3; sağ 4. Sol alt ağaç bitti, kök 5. Sağ alt ağaçta önce en sol 6, sonra kök 8, sonra 9. Sonuç `1 3 4 5 6 8 9`. BST'nin in-order gezinmesi değerleri küçükten büyüğe verir.
- Pre-order: önce kök 5; sol alt ağacın kökü 3, onun solu 1, sağı 4; sonra sağ alt ağacın kökü 8, solu 6, sağı 9. Sonuç `5 3 1 4 8 6 9`.
- Post-order: gidilebildiği kadar sola, 1; onun kardeşi 4; kökleri 3; sağ alt ağaçta 6, 9, kökleri 8; en son ana kök 5. Sonuç `1 4 3 6 9 8 5`.

Hoca post-order'ı iteratif yazmanın neden zor olduğunu bu ağaç üzerinden gösterir: 1'den sonra 4'e geçmek için 3'ün sağına gitmek, ama 3'ü henüz yazmamak gerekir. Bunun için en az iki işaretçi (`T` ve `T2`) tutmak, alt ağaçlar varsa daha fazlasını saklamak gerekir. Özyinelemeli yazımla aynı iş 3-4 satırda biter.

## 6. Arama Karmaşıklığı ve Dengeli Ağaç

**Soru:** İkili arama ağacında arama yapmanın karmaşıklığı nedir?
**Cevap:** Bir öğrenci $\log n$ cevabını verir. Her karşılaştırmada bir alt ağaç elendiği için dengeli ağaçta arama yükseklik kadar, yani $O(\log n)$ adım sürer.

Hoca ardından ağaç yüksekliğinin her zaman $\log n$ olmadığını gösterir. Değerler 1, 2, 3, 4, 5 sırasıyla girilirse her düğüm bir öncekinin sağ çocuğu olur ve ağaç bağlı liste gibi olur. Yükseklik doğrudan $n$'dir; en kötü durumda $n$ karşılaştırma gerekir. Bu, ikili arama ağaçlarının bir dezavantajıdır: veri dengeli bir ağaç oluşturacak şekilde girilmezse arama bağlı listedeki gibi doğrusal olur. Hoca dengeyi, ağacın sol ve sağ tarafının yüksekliklerinin birbirinden en çok bir farklı olması olarak açıklar.

**Soru:** Bu ağaç ikili ağaç değil de yalnız "ağaç" olarak düşünülürse dengeli sayılır mı? Bir tanıma göre yaprakların seviyeleri arasındaki fark birden az olmalıdır; burada tek yaprak var.
**Cevap:** Hoca bu ağacın ikili ağaç mantığıyla oluşturulduğunu ve dengesiz olduğunu söyler. Denge kavramı ikili ağaçlarda konuşulur; düz bir bağlı listede ya da üçlü ağaçta bu anlamda dengeden söz edilmez. Bu ağaçta $n$ düğümden biri yaprak, $n-1$'i iç düğümdür, ama ağaç dengesizdir.

Dersin sonlarına doğru hoca tanımı tekrar okur: yüksekliği $h$ olan bir ağacın yaprakları $h$ ya da $h-1$ seviyesindeyse ağaca dengeli denir. Bu tanımın birden fazla yapraklı ağaçlar için düşünüldüğünü söyler. Öğrenci 4'ten bir çocuk daha çıkarılıp iki yaprak olursa ağacın dengeli olup olmayacağını sorar; hoca yine dengeli olmadığını, ağaç derinliği ile yaprakların derinliği arasında dengesizlik bulunduğunu söyler. Öğrenci tanımın en kötü durumu (ağacın bağlı liste biçiminde oluşmasını) kapsamadığını belirtir. Hoca tanıma bu durumun eklenebileceğini, yüksekliğe bakılması gerektiğini, Rosen'in kitabında başka bir tanım da bulunduğunu söyler ve konuyu araştırıp paylaşacağını belirtir. Öğrenci ayrıca "dengeli ağaç" ile "dengeli ikili ağaç" tanımlarının farklı olduğunu düşündüğünü ekler.

> **Ek bilgi (derste anlatılmadı):** Veri yapıları literatüründe yaygın tanımlardan biri, her düğümde sol ve sağ alt ağaç yükseklikleri arasındaki farkın en çok 1 olmasıdır (AVL ağaçlarında kullanılan koşul). Bu tanımla bağlı liste biçimindeki bir ağaç kökten başlayarak dengesizdir. Kökün yalnız tek düzeyine bakan tanımlar ise bazı dengesiz ağaçları yakalayamayabilir.

## 7. Düğüm Silme

Hoca silme kodunu derste yazmaz; mantığını bir görselleştirme aracıyla (cs.usfca.edu sitesindeki Binary Search Tree animasyonu) gösterir ve kodlamayı öğrencilere bırakır. Önce 5, 3, 8, 1, 4, 6, 9 eklenerek önceki ağaç kurulur.

Bir düğümü silmek için önce o düğüm bulunur. Bulmak kolaydır: kökten başlanıp aranan değer büyükse sağa, küçükse sola gidilir. Asıl sorun, iki çocuklu bir düğüm silindiğinde yerine ne geleceğidir. Örneğin 3 silinirse yerine 1 de 4 de konabilir. Araç, silinen düğümün sol alt ağacındaki en büyük değeri yerine getirir. 8 silinirken de aynı şey olur: sol alt ağacın en büyüğü yukarı taşınır, böylece hem sol hem sağ taraf bozulmaz. Kök 5 silinirken solun en büyüğü olan 4 getirilebilir; sağın en küçüğü olan 6 getirilseydi de ağaç bozulmazdı. İki farklı yaklaşım vardır ve ikisinde de arama ağacı özelliği korunur.

Araçta eşit değerlerin de eklenebildiği görülür: zaten 1 varken bir 1 daha eklenince sola gider. Eşit bir değer silinirken ilk bulunan düğüm silinir. Araç negatif değer girişine izin vermez.

> **Hocanın vurgusu:** Silme işleminin mantığını öğrenin ve kendiniz kodlamaya çalışın; özyinelemeli ya da iteratif, mümkünse ikisini de yazın. İnternette kodlar var, ama mantığı anladıktan sonra kendiniz yazarsanız öğrenmiş olursunuz.

## 8. Dosyadan Yapıya Okuma: Nokta ve Ok Operatörü

Hoca, bir dosyanın nasıl yazıldıysa öyle okunması gerektiğini hatırlatarak daha önce laboratuvarda sorulmuş bir örneği açar. Metin (binary olmayan) dosyada her satırda ad, soyad ve numara vardır. Senaryo, kişileri okuyup sıralamak ve dosyaya sıralı yazmak olabilir. Bunun için ad, soyad ve numara alanlı bir yapı tasarlanır; örnekte beş kişilik bir dizi kullanılır (`malloc` da kullanılabilir).

Program kullanıcıya hangi yöntemle okumak istediğini sorar: `"Ok ile okumak icin 1 nokta ile okumak icin 2"` (ekrandan, 01:25:00).

- Nokta ile okumada `fscanf(fp, "%s %s %d\n", ...)` biçiminde dizi elemanının alanlarına okunur. Ad ve soyad alanları karakter dizisi olduğu için adları zaten adres tutar, `&` gerekmez; numara gibi `int` alanın adresi `&` ile verilir. Okunanlar doğru okunup okunmadığını görmek için `printf` ile yazdırılır, sonra dosya kapatılır.
- Ok ile okumada `person` adlı bir işaretçi kullanılır. `person->ad`, `person->soyad` ve `&person->no` adreslerine okunur, ekrana yazdırılır, işaretçinin adresi de yazdırılır ve `person++` yapılır. `person++` arka planda işaretçi aritmetiği yaparak bir sonraki yapı elemanının adresine geçer; böylece her kaydın nereye yazılacağı belirlenmiş olur. İşaretçinin başlangıç değeri bu artırmalarla kaybolur, ama dizinin kendisinin adresi sabit kaldığı için değişmez.

Derste nokta ile okuma kolundaki `printf` biçim dizgisinde bir `%d`'nin eksik olduğu görüldü ve düzeltildi. Örnek, dosyalar, yapılar ve fonksiyonların birlikte kullanımını ve iki operatör arasındaki farkı göstermek için seçildi.

<!-- BELİRSİZ: ReadFile örneğinin kaynak kodu karelerde okunur biçimde görünmüyor (yalnız person->no ile biten satırlar ve program çıktısı görünüyor); yapı alan adları ve fscanf satırı altyazıdan alındı. -->

## 9. Thread'lere Giriş

### 9.1 Yürütme Akışı ve Süreç

Bir programın yürütme akışı (execution flow) vardır. `main` başlar, aşağı doğru ilerler; bir `f` fonksiyonu çağrılırsa akış oraya dallanır, fonksiyon bitince geri döner ve program sonunda biter. Baştan sona her zaman tek bir yürütme akışı vardır.

Program derlenip bağlanınca (link) `program.exe` haline gelir. Çalıştırıldığında süreç (process) olur: "process is a running program", yani çalışır durumdaki program süreçtir. Sürecin bellekte bir kimliği (PID) ve ayrılmış bir alanı vardır. Bu akış, assembly'de olduğu gibi yazıldığı sırayla ilerler; birden fazla akış aynı anda (eş zamanlı, concurrent ya da simultaneous) yürümez.

### 9.2 Thread Nedir

Bir programa birden fazla akışı eş zamanlı yürütme özelliği kazandırmanın yollarından biri thread'dir (iplik). Program bir noktada tek gelir, sonra birden fazla parçaya bölünür, parçalar eş zamanlı koşar, sonra program devam eder. Örnek: kelime işlemcide yazı yazarken aynı anda yazım hataları kırmızıyla işaretlenir. Hoca görev yöneticisinin ayrıntılar kısmında süreçleri ve bir programın altında çalışan birden fazla alt birimi gösterir; örneğin Zoom'da katılımcıların, sohbetin ve toplantının kontrolü ayrı ayrı yapılır.

Bir sürecin birden fazla yürütme akışına sahip olması thread olarak ifade edilir. Tek akışlı bir süreç tek thread'li, üç akışlı bir süreç üç thread'li süreçtir. Aynı programı iki kez açmak iki ayrı süreç oluşturur; thread ise tek bir süreç altındaki çoklu akıştır. Web tarayıcısında birden fazla sayfaya aynı anda bağlanabilmek, grafik arayüzlü uygulamalar, gerçek zamanlı ve çoklu ortam uygulamaları thread'ler sayesinde mümkündür. Hoca, aynı anda konuşup dinleyemediğimiz bir dünyayı benzetme olarak verir: önce benim konuşmam biter, sonra sizin dinlemeniz başlar.

### 9.3 Çekirdek, Bağlam Değiştirme ve Süreç-Thread Farkı

İşlemcide bir işlem birimi (core, çekirdek) bellekten komutu getirir (fetch), çözer (decode), yürütür (execute) ve sonucu yazar (write back). Günümüzde çekirdek sayısı birden fazladır; bu yüzden aynı anda birden fazla iş gerçekten yürütülebilir. Tek çekirdek olsaydı da çekirdekler gigahertz düzeyinde, saniyede yaklaşık $10^9$ işlem hızında çalıştığı için bir süreç biraz çalışır, sonra sıra diğerine geçer. Bu geçişe bağlam değiştirme (context switching) denir ve fark edilemeyecek kadar hızlıdır. İşlemci ile çekirdek farklıdır: 4 işlemcili ve her birinde 4 çekirdek bulunan bir bilgisayarda 16 çekirdek vardır.

Programda eş zamanlılık iki yolla sağlanır: yeni bir süreç oluşturmak ya da thread oluşturmak. Süreç oluşturmak daha maliyetlidir; süreçler bellekte farklı yerlerde tutulur ve eş zamanlı çalışmalarını kontrol etmek daha zordur. C'de bu `fork` ile yapılır ve işletim sistemleri dersinin konusudur. Tek bir bellek alanında birden fazla akış isteniyorsa yol thread'lerdir. Bağlam değiştirme hem süreçler hem thread'ler arasında olur ve işletim sistemi tarafından yönetilir; thread'ler arasındaki geçiş süreçlere göre çok daha hızlıdır.

Bağlam değiştirmenin bir maliyeti vardır. Hoca bunu market kasası benzetmesiyle anlatır: kasiyer dört müşteriyi aynı anda almaya karar verip birinin 8 ürününden 3'ünü okutup diğerine geçerse, ilk müşterinin kalan 5 ürününü ve o ana kadarki hesabı bir yerde saklamak zorundadır. Ayrıca geçişler zaman kaybına yol açar.

### 9.4 Senkronizasyon, Açlık ve Kilitlenme

Birden fazla thread aynı değişkeni kullanırsa senkronizasyon sorunu doğar. Hoca, öğrencilerin "neden global değişken kullanmıyoruz" sorusunun bir cevabının da bu olduğunu söyler. Klasik örnek banka hesabıdır: bir thread cep telefonundan para çekerken diğeri karttan para yatırır. Bir thread kaynağa eriştiğinde diğerinin erişmesi istenmiyorsa kontrol gerekir; mikrofon kimdeyse o konuşur.

Bu kontrol yapılırken iki tür sorun çıkabilir:

- Açlık (starvation): bir süreç ya da thread kaynağa sürekli erişirken diğerine hiç sıra gelmez. Hoca kelimenin anlamını açlık çekmek olarak açıklar ve "breakfast" kelimesinin de buradan geldiğini söyler. Toplulukta mikrofon istediğiniz halde size hiç sıra gelmemesi gibidir.
- Kilitlenme (deadlock): kavşakta araçların birbirine girip hiçbirinin ilerleyememesi gibi. Süreç A'nın, süreç B'nin tuttuğu Kaynak 2'ye; B'nin de A'nın tuttuğu Kaynak 1'e ihtiyacı vardır ve ikisi de elindekini bırakmaz. Birinin devreden çıkıp yeniden başlatılması gerekir. Programların ya da bilgisayarın kilitlenmesi bunun sonuçlarından biridir.

Thread'lerle ilgili sorunlar slaytında şunlar yazıyordu (ekrandan, 01:40:00): birçok işletim sistemi thread'leri ayrı süreç olarak değil, ana sürecin parçası olarak görür; bir thread yeni bir program (`exec`) çalıştırırsa bütün ana süreç yeni programın adres alanıyla değişebilir ve bütün thread'ler durur; bu bir tasarım sorunudur ve uygulamalar bu tür sorunları en aza indirecek şekilde tasarlanmalıdır; thread'lerle hata ayıklamak zordur; çok fazla thread performansı düşürebilir.

## 10. C'de POSIX Thread Kütüphanesi

### 10.1 Temel Fonksiyonlar

C'de thread'ler pthread kütüphanesiyle oluşturulur: `#include <pthread.h>`. Hoca, thread özelliklerinin (bekleme özelliği, öncelik gibi) başlı başına bir ders konusu olduğunu, ayrıntılar için man sayfalarına ve ücretsiz bir kitaba bakılabileceğini söyler.

- `pthread_create`: thread oluşturur. Parametreleri: thread kimliğinin adresi, thread özellikleri (`NULL` verilirse varsayılan değerler), thread başlayınca çalışacak fonksiyonun adresi (fonksiyon işaretçisi) ve o fonksiyona gidecek argüman. Başarılıysa 0, değilse sıfırdan farklı bir hata numarası döndürür.
- `pthread_self`: çağıran thread'in kimliğini (`pthread_t`) döndürür.
- `pthread_equal`: iki thread kimliğini karşılaştırır. Stringler `==` ile karşılaştırılmadığı gibi thread kimlikleri de `==` ile değil bu fonksiyonla karşılaştırılır.
- `pthread_exit`: thread'i sonlandırır ve bir değer döndürmesini sağlar.
- `pthread_join`: verilen thread görevini bitirmeden bir sonraki satıra geçilmemesini sağlar. Özellikle `main` içinde kullanılır.

Thread ile çalışacak fonksiyon `void *` türünde argüman almalı ve `void *` döndürmelidir. Böylece fonksiyon her türden değer alıp her türden değer döndürebilir.

pthread harici bir kütüphane olduğu için derlerken bağlanmalıdır; kullanılan geliştirme ortamı bunu arka planda ekler. Hoca kütüphanenin Windows'ta çalıştırıldığında bazı örneklerin çalışmayabileceğini de söyler.

> **Ek bilgi (derste anlatılmadı):** GCC ile komut satırında derlerken `gcc dosya.c -o dosya -pthread` (ya da `-lpthread`) seçeneği verilir. Bu seçenek olmadan bağlayıcı `pthread_create` gibi sembolleri bulamayabilir.

### 10.2 İlk Örnek: main ve Thread Fonksiyonunun Birlikte Çalışması

İlk örnekte bir işçi (worker) fonksiyonu, sonsuz döngüde `"I am threadFunction."` yazar; `main` de thread'i `pthread_create(&id, NULL, threadFunction, NULL)` ile oluşturduktan sonra sonsuz döngüde `"I am main function."` yazar. Oluşturma başarılıysa ya da değilse buna göre bir mesaj yazdırılır. Çıktıda iki mesajın düzensiz biçimde iç içe geçtiği görülür (ekrandan, 01:45:00).

Normal bir fonksiyon çağrısında önce çağrılan fonksiyon çalışıp biter, sonra sıra çağırana gelirdi. Thread ile biraz ondan, biraz bundan iş yapılır. Hangi thread'in ne zaman çalışacağını işletim sistemi belirler; programda bunu belirleyen bir mekanizma yoktur.

<!-- BELİRSİZ: ilk thread örneğinin (hafta11_ex2.c) kaynak kodu karelerde görünmüyor; yalnız çıktısı görünüyor. Davranış altyazı ve çıktıdan anlatıldı. -->

### 10.3 İkinci Örnek: Thread Kimliğine Göre Farklı İş

İkinci örnekte iki thread kimliği tutan bir dizi vardır. Thread fonksiyonu `pthread_self()` ile kendi kimliğini alır, boş bir `for` döngüsüyle gecikme yapar ve `pthread_equal(id, tid[0])` doğruysa `"First thread processing"`, değilse `"Second thread processing"` yazar. `main` bir `while` döngüsünde iki thread oluşturur, her biri için `"Thread created successfully"` ya da hata mesajı yazar ve sonra 5 saniye bekler (`sleep(5)`). Böylece `main` ile birlikte toplam üç akış vardır; `main` de bir thread'dir.

Hocanın boş `for` döngüsünü öğrencilere sorduğu anda bir öğrenci işaretçi tahmini yapar; doğru cevap döngünün yalnız gecikme amaçlı olduğudur.

Bir çalıştırmada çıktı şöyle oldu (ekrandan, 01:50:00):

```text
Thread created successfully
First thread processing
Second thread processing
Thread created successfully
```

Hoca bu sırayı mikrofon benzetmesiyle açıklar: önce mikrofon `main`'dedir ve ilk thread'i oluşturup mesajı yazar. Sıra ilk thread'e geçer ve o mesajını yazar. Sonra `main` ikinci thread'i oluşturur ama mesajını yazmadan sıra ikinci thread'e geçer; ikinci thread mesajını yazar, sonra `main` ikinci "created" mesajını yazar. Aynı fonksiyon bir kez yazılmış ama iki bağımsız akışta çalışmıştır. Yeniden çalıştırıldığında farklı sıralar görülebilir. Thread sayısı 5'e çıkarılınca beş thread'in her biri için çıktı görüldü.

`sleep` kaldırılınca `main` hemen bitti; `main`'in bitmesi programın bitmesi demektir. İkinci thread görevini bitiremeden öldürüldü. Hoca bu durumu zombi süreçlerle ilgili anlatımlarla ilişkilendirir. Beklemenin ne kadar sürmesi gerektiği önceden kestirilemez (5 saniye de olabilir, 55 saniye de); bu yüzden `pthread_join` ve `pthread_exit` kullanılır.

### 10.4 Üçüncü Örnek: pthread_exit ve pthread_join

Slayttaki örnek (ekrandan, 01:55:00):

```c
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t tid[2];
int ret1,ret2;
void* doSomeThing(void *arg) {
    unsigned long i = 0;
    pthread_t id = pthread_self();
    for(i=0; i<(0xFFFFFFFF);i++);
    if(pthread_equal(id,tid[0])) {
        printf("\n 1st thread processing done\n");
        ret1 = 100;
        pthread_exit(&ret1);
    }
    else {
        printf("\n 2nd thread processing done\n");
        ret2 = 200;
        pthread_exit(&ret2);
    }
    return NULL;
}
int main(void)
{
    int i = 0, err;
    int *ptr[2];
    while(i < 2) {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
            printf("\n Thread created successfully\n");
        i++;
    }
    pthread_join(tid[0], (void**)&(ptr[0]));
    pthread_join(tid[1], (void**)&(ptr[1]));
    printf("\n return value from first thread is %d\n", *ptr[0]);
    printf("\n return value from second thread is %d\n", *ptr[1]);
    return 0;
}
```

Birinci thread çıkarken `pthread_exit(&ret1)` ile 100 değerini, ikinci thread `pthread_exit(&ret2)` ile 200 değerini döndürür. `void *` sayesinde thread'den tamsayı, karakter ya da başka bir türde değer döndürülebilir. `main` içindeki `pthread_join(tid[0], ...)` 0. thread görevini bitirmeden sonraki satıra geçilmesini engeller; ikinci `pthread_join` de 1. thread için aynı işi yapar. Dönen adresler `ptr` dizisine yazılır ve değerler ekrana basılır. Böylece `sleep`'e gerek kalmaz: önce thread'ler biter, sonra değerler yazılır, en son `main` biter.

Derste `0xFFFFFFFF` sınırlı gecikme döngüsü uzun sürdüğü için sınır 255 civarına indirilip yeniden çalıştırıldı: bir thread oluştu ve işe başladı, ikincisi oluştu ve işe başladı, sonra önce birincisi, ardından ikincisi bitti ve değerleri alındı. Ajan kodu `gcc -Wall -pthread` ile derleyip (gecikme sınırı kısaltılarak) çalıştırdı; iki "Thread created successfully" satırından sonra iki thread'in bitiş mesajları ve `100`, `200` dönüş değerleri alındı. Bitiş mesajlarının sırası çalıştırmadan çalıştırmaya değişebilir.

> **Hocanın vurgusu:** Bu üç örnek, işletim sistemleri dersine hazırlık olarak thread mantığını öğrenmek için yeterlidir. Sistem programlama ve gömülü sistem tasarımında thread'ler çok kullanılır; şimdiden bakmanız tavsiye edilir.

## 11. Uygulama: Özyinelemeli Yol Kontrolü

Dersin ikinci bölümü bir uygulama oturumudur. İlk soru: koordinat düzleminde bir A noktasından bir B noktasına, yalnız bir birim sağa ya da bir birim yukarı giderek ulaşılabilir mi? Bunu kontrol eden özyinelemeli bir fonksiyon yazılır.

Noktalar ayrı değişkenlerle tanımlanır (küçük bir örnek olduğu için yapı kullanılmaz): A(2, 2), B(5, 7), C(-2, 7). A'dan B'ye sağ ve yukarı giderek gidilebilir, ama C, A'nın solunda kaldığı için C'ye gidilemez; fonksiyon C için yanlış (0) döndürmelidir. Daha sonra B'nin yukarısında bir D(7, 9) noktası eklenir.

Fonksiyon önce sağlanmayan durumu (base case) kontrol eder: hareket eden nokta hedefin sağına ya da yukarısına geçmişse artık sağ ve yukarı giderek hedefe ulaşılamaz, 0 döndürülür. Sonra sağlanan durum kontrol edilir: x ve y koordinatları hedefinkine eşitse hedefe varılmıştır, 1 döndürülür. İkisi de değilse fonksiyon iki seçenekle kendini çağırır: x bir artırılarak ya da y bir artırılarak. Sonuç iki çağrının mantıksal veyasıdır (ekrandan, 02:30:00):

```c
int isReachable(int Ax, int Ay, int Bx, int By){
    // base case
    if(Ax > Bx || Ay > By)
        return 0;
    // Ax = Bx, Ay = By;
    if(Ax == Bx && Ay == By)
        return 1;
    // continue to check
    return (isReachable(Ax+1, Ay, Bx, By) || isReachable(Ax, Ay+1, Bx, By));
}
```

<!-- BELİRSİZ: son return satırının parantez içi karede yazılmadan önceki haliyle görünüyor; içerik altyazıdaki "ya x'i bir artıracağım ya da y'yi bir artıracağım" anlatımından kuruldu. -->

`main` içinde fonksiyon doğru dönerse "kaynaktan hedefe yol vardır", değilse "yol yok" yazdırılır. Adım adım: (2, 2) noktası B ile karşılaştırılır; 2 ne 5'ten ne 7'den büyüktür, ilk koşul sağlanmaz. Koordinatlar eşit de değildir. Fonksiyon (3, 2) ve (2, 3) için kendini çağırır ve bu böyle devam eder.

Derste A ile B denendi ve yol bulundu; A ile C denendi ve yol bulunamadı; D kaynak, B hedef alınarak denendi ve yine yol bulunamadı. Ajan programı derleyip çalıştırdı: A'dan B'ye yol var, A'dan C'ye ve D'den B'ye yol yok (karşılaştırma için B'den D'ye yol vardır).

> **Ek bilgi (derste anlatılmadı):** Bu fonksiyon aynı ara noktaları defalarca yeniden hesaplar; hedefe uzaklık arttıkça çağrı sayısı çok hızlı büyür. Bu özel problemde cevap aslında yalnız $A_x \le B_x$ ve $A_y \le B_y$ koşuluna bağlıdır; özyinelemeli çözüm, özyinelemenin kurgusunu göstermek için seçilmiştir.

## 12. Uygulama: Dosyadaki Kayıtları Bağlı Listede Sıralama

İkinci soruda `Dataset.txt` dosyasında her satırda virgülle ayrılmış kimlik (ID), isim ve bölüm bilgisi vardır (örneğin `4,<isim>,BLM` biçiminde). Kayıtlar okunacak, ID'ye göre sıralanacak ve yeni bir dosyaya yazılacaktır. Bu tür dosyadan okuma işlemlerinin dönem projesinde ve bir sonraki laboratuvarda da gerekebileceği söylenir.

### 12.1 Yapı

Kayıtlar sıralanacağı için bağlı liste gibi düşünülür; yapı kendi türünden bir `next` işaretçisi tutar (ekrandan, 02:50:00):

```c
typedef struct DATA{
    int ID;
    char Name[50];
    char department[20];
    struct DATA *next;
}data;
```

Yapı adı büyük harfle `DATA`, `typedef` adı küçük harfle `data` yazıldığı için değişkenler `data` türüyle tanımlanabilir. Bunu bir öğrenci sorar; hoca yapı adının tamamen büyük, tür adının küçük harfle yazıldığını, bu yüzden hata vermediğini açıklar.

### 12.2 Satırı Parçalama: strtok ve atoi

`Split_Data` fonksiyonu okunan satırı ayırıcıya (delimiter) göre parçalayıp yapının alanlarına yerleştirir (ekrandan, 02:50:00):

```c
void Split_Data(data* holder, char[255] buff, char delimeter[2])
    char *token;
    //strok(); Delim parametresi ile göstreilen karakter dizi içindeki sınırlayıcı karakterleri kullanarak
    // buf parametresi ile gösterilen karakter dizini parçalar.
    token = strtok(buff, delimeter);
    // atoi(); char to int
    holder->ID = atoi(token);
    token = strtok(NULL, delimeter);
```

Karede parametre listesi `char[255] buff` biçiminde ve açılış parantezi o anda yazılmamış görünüyor.

> **Ders sonrası not:** C'de dizi parametresi `char[255] buff` biçiminde yazılamaz; doğrusu `char buff[255]` (ya da `char *buff`) biçimindedir. Programın ilerleyen karelerinde derleme hatasız göründüğü için bu yazımın büyük olasılıkla düzeltildiği anlaşılıyor. Derlemeden önce bir öğrencinin "parantezi yanlış yere açmışsınız" uyarısıyla bir parantez hatası da düzeltildi.

Ayırıcı neden gereklidir? Bir öğrenci bunu sorar. Dosyada ID, isim ve bölüm virgülle ayrılmıştır; hangi sütunun hangi alana ait olduğunu ayırt etmek için araya bir ayrıştırma karakteri gerekir. Virgül görülene kadar okunan değerler ilk alana, sonraki değerler bir sonraki alana aittir.

`strtok`, ikinci parametredeki ayırıcı karakterleri kullanarak ilk parametredeki karakter dizisini parçalar. İlk çağrıda tampon verilir. Sonraki çağrılarda tampon yeniden verilmez, `NULL` verilir; `NULL` ile çağrılınca fonksiyon ilk verilen tamponu kaldığı yerden parçalamaya devam eder. `atoi` aldığı string'i tamsayıya çevirir; ID alanı `int` olduğu için gereklidir. İsim ve bölüm parçaları `strcpy` ile alanlara kopyalanır.

`main` içinde ayırıcı olarak `",\0"` verilir (ekrandan, 03:15:00). Bir öğrenci doğrudan `","` vermeyi önerir; uygulamayı yürüten hoca bunun da denenebileceğini, `\0`'ın satır sonlarını dikkate almak için konduğunu düşündüğünü söyler.

> **Ek bilgi (derste anlatılmadı):** String sabiti zaten `\0` ile bittiği için `",\0"` ile `","` aynı ayırıcı kümesini (yalnız virgülü) verir. `fgets` satır sonundaki `'\n'` karakterini de tampona koyduğundan, son alan (bölüm) bu karakteri içerebilir. Satır sonunu da ayırmak için ayırıcı `",\n"` verilebilir.

### 12.3 Dosyadan Okuyup Listeyi Kurma

`File_Read` fonksiyonu dosya adını ve ayırıcıyı alır. Dosya yalnız okuma (`"r"`) kipinde açılır, çünkü bu dosya değiştirilmeyecek, sıralı liste yeni bir dosyaya yazılacaktır. 255 karakterlik bir `buf` tamponu tanımlanır. Önce ilk satır okunup `head` düğümüne yerleştirilir ve `prev_data = head` yapılır. Sonra döngüde her satır için yeni düğüm açılıp listenin sonuna eklenir (ekrandan, 03:00:00):

```c
    while(fgets(buf, 255, fp)!=NULL){
        printf("%s", buf);
        curr_data = (data*)malloc(sizeof(data));
        prev_data->next = curr_data;
        Split_Data(curr_data, buf, delimeter);
        prev_data = curr_data;
    }
    prev_data->next = NULL;
    fclose(fp);
    return head;
}
```

`fgets` dosyadan tampona en çok 255 karakterlik bir satır okur; dönüşü `NULL` ise okunacak bir şey kalmamıştır. Okunan her satır kontrol amacıyla ekrana yazdırılır. `prev_data` her zaman listenin son düğümünü tutar: yeni düğüm `prev_data->next`'e bağlanır, sonra `prev_data` yeni düğüme kaydırılır. Okuma bitince son düğümün `next`'i `NULL` yapılır, dosya kapatılır ve listenin başı döndürülür.

<!-- BELİRSİZ: File_Read fonksiyonunun ilk satırları (head'in oluşturulup ilk satırın okunması) karelerde görünmüyor; altyazıya göre anlatıldı. -->

Liste `Print_List` ile yazdırılır (ekrandan, 03:05:00):

```c
void Print_List(data* head){
    while(head!=NULL){
        printf("ID: %d, Name: %s, Department: %s\n", head->ID, head->Name, head->department);
        head = head->next;
    }
}
```

Bir öğrenci, `head`'in değiştirilmesi yerine geçici bir işaretçi kullanılmasını önerir. Hoca `head`'in parametre olarak (değerle) geldiğini, bu yüzden çağıranın işaretçisinin değişmediğini belirtir. Program çalıştırılınca dosyadaki dört satır önce ham haliyle, sonra istenen biçimde yazdırıldı.

### 12.4 Fonksiyon İşaretçisiyle Özyinelemeli Sıralama

Sıralama fonksiyonu listenin başını ve bir karşılaştırma fonksiyonu işaretçisini alır; böylece aynı fonksiyon büyükten küçüğe ya da küçükten büyüğe sıralayabilir (ekrandan, 03:05:00, 03:10:00 ve 03:15:00):

```c
data* Sort_Data(data* head, int (*Sort_Condition)(int, int)){

    if(head == NULL || head->next == NULL)
        return head;

    int max = head->ID;
    data *prev = head;
    data *to_move = NULL;
    data *tmp = head->next;

    // find maximum value in rest(head->next)
    while(tmp != NULL){
        if(Sort_Condition(tmp->ID, max)){
            max = tmp->ID;
            to_move = prev;
        }
        prev = tmp;
        tmp = tmp->next;
    }

    // Eğer seçili veri zaten en büyükse;
    if(to_move == NULL){
        head->next = Sort_Data(head->next, Sort_Condition);
    }

    prev = to_move;
    to_move = prev->next;
    prev->next = prev->next->next;
    to_move->next = Sort_Data(head, Sort_Condition);
    return to_move;
}
```

Fonksiyonun işleyişi:

- Liste boşsa ya da tek elemanlıysa sıralanacak bir şey yoktur, `head` döndürülür.
- Başlangıçta en büyük değer (`max`) baştaki düğümün ID'si kabul edilir. `prev` baştan, `tmp` ikinci düğümden başlar.
- Döngüde `Sort_Condition(tmp->ID, max)` doğruysa yeni en büyük bulunmuştur; `max` güncellenir ve `to_move`'a o düğümün bir öncekisi (`prev`) yazılır. `to_move` bu aşamada taşınacak düğümü değil, ondan önceki düğümü tutar.
- Hiç daha büyük eleman bulunmadıysa (`to_move == NULL`) baştaki eleman zaten en büyüktür; listenin geri kalanı (`head->next`) sıralanıp başın arkasına bağlanır.
- Bulunduysa `prev = to_move` ile en büyüğün öncesine gelinir, `to_move = prev->next` ile en büyük düğüm alınır, `prev->next = prev->next->next` ile en büyük düğüm listeden çıkarılır. Sonra kalan liste (`head`'den başlayarak) özyinelemeli sıralanır ve en büyük düğümün arkasına bağlanır; en büyük düğüm yeni baş olarak döndürülür.

Hoca bunu tahtada 1 → 3 → 2 → 0 listesiyle gösterir. Büyükten küçüğe sıralamada en büyük 3'tür. 1 artık 3'ü değil 2'yi gösterir, liste 1 → 2 → 0 olur. 3 kenara alınır ve `next`'i kalan listenin sıralanmış haline bağlanır. Kalan listede en büyük 2'dir; 1 doğrudan 0'a bağlanır, 2 de 3'ün arkasına gelir. Sonra 1, en son 0 gelir: 3 → 2 → 1 → 0. Hoca bunu, sıralanmamış bir diziden her seferinde en büyüğü alıp sıralı diziye eklemek olarak özetler.

Karşılaştırma fonksiyonlarından biri büyük mü, diğeri küçük mü kontrolü yapar. `main`'de `head = Sort_Data(head, Sort_Descending);` çağrılır (ekrandan, 03:25:00). Karşılaştırma fonksiyonlarının gövdesi karelerde görünmedi; altyazıya göre biri diğerinin tersidir. Ajanın test ettiği biçim:

```c
int Sort_Descending(int a, int b){ return a > b; }
int Sort_Ascending(int a, int b){ return a < b; }
```

Uygulamayı yürüten hoca, çözümün başka bir öğretim elemanı tarafından hazırlandığını ve içinde gereksiz bir atama olup olmadığının tartışılabileceğini söyler.

### 12.5 Derste Bulunamayan Hata

Derste yazılan kod çalıştırıldığında büyükten küçüğe sıralama 200, 21, 4 değerlerini buldu, 2'ye gelince program çöktü. Hoca kodu adım adım izledi ama hatayı bulamadı; önceden hazırlanmış çalışan kodu kopyalayınca program çalıştı ve hatanın daha sonra duyurulacağını söyledi.

> **Ders sonrası not:** Ekrandaki kodda (ekrandan, 03:15:00 ve 03:25:00) `if(to_move == NULL){ ... }` bloğunun içinde `return head;` satırı yoktur. Bu durumda fonksiyon bloktan sonra `prev = to_move;` satırına düşer, `prev` `NULL` olur ve `prev->next` erişimi programı çökertir. Bu durum, kalan listenin ilk elemanının zaten en büyük olduğu anda ortaya çıkar. Ajan kodu bu satır olmadan derleyip çalıştırdığında program segmentasyon hatasıyla çöktü; blok içine `return head;` eklenince doğru sıraladı. Dolayısıyla derste aranan hata büyük olasılıkla bu eksik `return`'dür.

### 12.6 Yeni Dosyaya Yazma

`File_Write` fonksiyonu sıralı listenin başını, yeni dosyanın adını ve ayırıcıyı alır. Dosya yazma (`"w"`) kipinde açılır. `head` `NULL` olmadığı sürece her düğümün ID, isim ve bölüm bilgisi aralarına ayırıcı konarak ve sonuna satır sonu eklenerek dosyaya yazılır; ardından `head = head->next` ile bir sonraki düğüme geçilir. Yazma bitince dosya kapatılır. Kodun bu kısmı derste yeniden yazılmadı, hazır kod üzerinden anlatıldı.

`main` içinde önce büyükten küçüğe sıralanan liste bir dosyaya, ardından küçükten büyüğe sıralanan liste başka bir dosyaya kaydedildi ve iki dosyanın da doğru sırada oluştuğu görüldü.

Ajan, bu bölümdeki parçaları (`Split_Data` parametresi `char buff[255]` olarak düzeltilmiş, `to_move == NULL` bloğuna `return head;` eklenmiş, ayırıcı `",\n"` verilmiş halde) birleştirip `gcc -Wall` ile derledi ve örnek bir dört satırlık dosyayla çalıştırdı: liste büyükten küçüğe ve küçükten büyüğe doğru sıralandı, iki çıktı dosyası beklenen sırayla yazıldı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:22:13): Bir ikili ağacın bütün düğümlerini gezebilmek için neyi bilmek gerekir?

> **Cevap (derste verildi):** Yalnız kök düğümün (`root`) adresini. Bağlı listede `head`'i bilmek nasıl yeterliyse, ağaçta da kökten başlanarak bütün düğümlere ulaşılır.

**Soru 2** (ekrandan, 00:35:00): 4, 8, 3, 6, 5, 7, 2 değerleri bu sırayla boş bir ikili arama ağacına eklenirse ağaç nasıl olur?

> **Cevap (derste verildi):** 4 kök; 4'ün solu 3, sağı 8; 3'ün solu 2; 8'in solu 6; 6'nın solu 5, sağı 7. İlk eklenen eleman kök olur ve değişmez.

**Soru 3** (ekrandan, 01:10:00): 5, 3, 8, 1, 4, 6, 9 değerleriyle kurulan ikili arama ağacının in-order, pre-order ve post-order gezinmelerini yazın.

> **Cevap (derste verildi):** In-order `1 3 4 5 6 8 9`, pre-order `5 3 1 4 8 6 9`, post-order `1 4 3 6 9 8 5`.

**Soru 4** (derste sözlü, 01:07:39): İkili arama ağacında arama yapmanın en kötü durum karmaşıklığı nedir?

> **Cevap (derste verildi):** Dengeli ağaçta $O(\log n)$. Ancak değerler sıralı girilirse (1, 2, 3, 4, 5) ağaç bağlı listeye döner, yükseklik $n$ olur ve en kötü durumda arama $O(n)$ olur.

**Soru 5** (derste sözlü, 01:09:19): Tek yaprağı olan, bağlı liste biçimindeki bir ağaç dengeli sayılır mı?

> **Cevap (derste verildi):** Hayır. İkili ağaç olarak oluşturulduğu için sol ve sağ tarafı arasında açık bir dengesizlik vardır; bu, en kötü durum olan bağlı liste biçimidir.

**Soru 6** (derste sözlü, 01:48:41): Thread fonksiyonundaki gövdesiz `for(i=0; i<(0xFFFFFFFF); i++);` döngüsü ne işe yarar?

> **Cevap (derste verildi):** Hiçbir şey yapmayan bir gecikme döngüsüdür; thread'lerin sırayla işlemciye gelişini gözlemlemek için kullanılır.

**Soru 7** (ekrandan, 02:30:00): Yalnız bir birim sağa ya da bir birim yukarı hareket edilerek A(2, 2) noktasından B(5, 7), C(-2, 7) noktalarına ulaşılabilir mi? D(7, 9) noktasından B'ye ulaşılabilir mi? Özyinelemeli bir fonksiyonla kontrol edin.

> **Cevap (derste verildi):** `isReachable` fonksiyonu (Bölüm 11) ile A'dan B'ye yol vardır; A'dan C'ye ve D'den B'ye yol yoktur. Ajan programı derleyip bu sonuçları doğruladı.

**Soru 8** (derste sözlü, 02:43:41): `strtok` fonksiyonuna verilen ayırıcı (delimiter) ne işe yarar?

> **Cevap (derste verildi):** Satırdaki alanların hangi karakterle ayrıldığını belirtir. Dosyada alanlar virgülle ayrıldığı için virgül görülene kadar okunan kısım bir alana, sonraki kısım bir sonraki alana aittir.

## Dersin Toparlaması

Ders özyinelemenin çağrı yığını üzerinden nasıl işlediğiyle başladı ve bu bakış ikili arama ağacına taşındı. Ağaç bağlı liste mantığıyla, `malloc` ile oluşturulan düğümlerle kuruldu; ekleme iteratif ve özyinelemeli olarak yazıldı. Gezinmeler özyinelemeli kodlandı ve ağaç dengesizleşirse aramanın doğrusal hale geleceği gösterildi. Düğüm silmenin mantığı bir görselleştirme aracıyla anlatıldı. Ardından dosyadan yapı dizisine nokta ve ok operatörleriyle okuma örneği gösterildi. Teorik bölüm, işletim sistemleri dersine hazırlık olarak süreç ve thread kavramları, bağlam değiştirme, senkronizasyon sorunları ve pthread fonksiyonlarıyla bitti.

Uygulama bölümünde iki problem çözüldü. İlki, özyinelemeli bir fonksiyonla bir noktadan diğerine yalnız sağa ve yukarı gidilerek ulaşılıp ulaşılamayacağını kontrol etti. İkincisi dosya işlemleri, `strtok`/`atoi` ile ayrıştırma, bağlı liste kurma, fonksiyon işaretçili özyinelemeli sıralama ve sıralı listeyi yeni dosyaya yazmayı bir arada kullandı. Bu örnekler, dönem boyunca işlenen dosyalar, yapılar, dinamik bellek, işaretçiler ve fonksiyon işaretçilerini tek bir programda birleştirdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
