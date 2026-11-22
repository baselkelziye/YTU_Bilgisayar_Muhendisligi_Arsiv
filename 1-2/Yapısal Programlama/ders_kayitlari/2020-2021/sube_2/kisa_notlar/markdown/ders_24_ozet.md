# Ders 24 Çalışma Özeti

## Genel Konular

- Dersin yapısı
  - Bu derste yeni teori yerine iki uygulama yapıldı: önce struct, dosya işlemleri, bağlı liste ve özyinelemeyi birleştiren bir "nokta listesi" örneği, sonra kendi türünden işaretçi tutan yapılar (self-referential structures) üzerinden bağlı liste türleri, yığın, kuyruk ve ikili arama ağacı.
- Örnek 1: dosyadan noktaları okuyup bağlı listeye koymak (ekrandan, 00:15:00 ve 00:45:00)
  - `struct Nokta` iki tamsayı koordinat (`x`, `y`) ve bir sonraki düğümü gösteren `struct Nokta *next` alanı tutar; `typedef struct Nokta NOKTA;` ile kısaltılır.
  - En uzak noktanın bilgisi için ikinci bir yapı: `typedef struct EnUzak { int d; NOKTA *pt; } ENUZAKNOKTA;`. `d` uzaklık değerini, `pt` o noktanın düğümünü gösterir.
  - Prototipler: `NOKTA* dosyadanOku(char*)`, `void listeYaz(NOKTA*)`, `void listeYazRec(NOKTA*)`, `NOKTA* enUzakNoktaBul(NOKTA*, int*)`, `ENUZAKNOKTA* enUzakNoktaBulv2(NOKTA*)`.
  - Dosya adı koda gömülmez, kullanıcıdan `scanf("%[^\n]s", dosyaAdi);` ile alınır (ekrandan, 00:40:00).
- `dosyadanOku`: sona sabit zamanda ekleme (ekrandan, 00:25:00)
  - `head` (ilk düğüm), `end` (son düğüm) ve `tmp` (yeni düğüm) işaretçileri tutulur. Her eklemede listenin başından sona kadar yürümemek için son düğüm ayrıca saklanır.
  - `fopen(dosyaAdi, "r")` NULL dönerse "Dosya acilamadi" yazılır. Değilse `while(!feof(fp))` döngüsünde her satır için `malloc` ile düğüm açılır, `fscanf(fp, "%d %d\n", &tmp->x, &tmp->y)` ile okunur, `tmp->next = NULL` yapılır.
  - Liste boşsa `head = end = tmp;`, değilse `end->next = tmp; end = end->next;`. Döngüden sonra `fclose(fp)`, fonksiyon `head` döndürür.
- Listeyi yazdırmak: iteratif ve özyinelemeli (ekrandan, 00:35:00)
  - İteratif: `tmp = head` ile başlanır, `tmp != NULL` iken `(x,y)->` yazılır ve `tmp = tmp->next` yapılır; sonda `Null` yazılır.
  - Özyinelemeli: `tmp != NULL` ise düğüm yazılır ve fonksiyon `tmp->next` ile kendini çağırır; temel durum (`else`) `Null` yazar.
- En uzak noktayı bulmanın iki yolu
  - Sürüm 1 (ekrandan, 00:45:00): uzaklık `d = pow(tmp->x,2) + pow(tmp->y,2)` ile karekök alınmadan karşılaştırılır. En uzak düğüm `return` ile döner, uzaklık değeri `int *dmax` parametresiyle (adres üzerinden) çağırana iletilir.
  - Sürüm 2 (ekrandan, 00:55:00): `ENUZAKNOKTA` türünde bir yapı `malloc` ile heap'te açılır, `ptr->d = dmax; ptr->pt = max;` doldurulur ve yapının işaretçisi döndürülür. Çağıran taraf `n->d`, `n->pt->x`, `n->pt->y` ile iç içe erişir.
- Fonksiyondan dönen verinin ömrü: bellek bölgeleri
  - Program belleğinde kod (program memory), statik/global değişkenler, stack ve heap bölgeleri vardır.
  - Fonksiyon içindeki yerel değişkenler stack'tedir; fonksiyon bitince yeri başka işe verilebilir. Dönen bilginin yaşaması için ya dinamik bellek (`malloc`, heap) ya da `static` kullanılır.
  - `ptr` değişkeninin kendisi stack'tedir ve fonksiyonla birlikte yok olur; tuttuğu adres ise heap'tedir ve program boyunca geçerlidir.
- Kendi türünden işaretçi tutan yapılar ve veri yapıları (Deitel slaytları, ekrandan, 01:05:00 ve 01:10:00)
  - Tek yönlü bağlı liste, dairesel bağlı liste (son düğüm `head`'i gösterir), çift yönlü bağlı liste (önceki ve sonraki işaretçisi), dairesel çift yönlü bağlı liste.
  - Sıralı ekleme ve değer silme: silerken bir önceki (`previousPtr`) ve şimdiki (`currentPtr`) düğüm birlikte ilerletilir; bulununca `previous->next = current->next` yapılır ve düğüm `free` edilir.
  - Yığın: `push` her zaman başa ekler, `pop` baştan siler ve `free` eder.
  - Kuyruk: `enqueue` sona (tail), `dequeue` baştan (head) çalışır; bu yüzden hem `headPtr` hem `tailPtr` tutulur.
- İkili arama ağacı
  - Kökten (`root`) başlar; her düğümde `left` ve `right` işaretçileri vardır. Eklenecek ya da aranan değer düğümdekinden büyükse sağa, küçükse sola gidilir.
  - Gezinme: preorder (kök, sol, sağ), inorder (sol, kök, sağ), postorder (sol, sağ, kök). `a + b` ifadesinin ağacı ile: inorder `a + b` (infix), preorder `+ a b` (prefix), postorder `a b +` (postfix).
- Ağacın kodlanması (ekrandan, 01:20:00, 01:25:00, 01:35:00, 01:40:00)
  - `typedef struct treeNode { int data; struct treeNode *left; struct treeNode *right; } TreeNode;`
  - `createNode(data)`: `malloc` ile düğüm açar, `data` atar, `left` ve `right`'ı NULL yapar, düğümü döndürür.
  - `preorder`: `root != NULL` ise önce `root->data` yazılır, sonra `preorder(root->left)` ve `preorder(root->right)` çağrılır.
  - `insertNode(root, data)`: `root == NULL` ise yeni düğüm oluşturup döndürür; `data > root->data` ise `root->right = insertNode(root->right, data)`, değilse `root->left = insertNode(root->left, data)`; her durumda `root` döndürülür.
  - `main`'de `do-while` ile 0 girilene kadar değer okunur ve `root = insertNode(root, data);` yapılır (0 da ağaca eklenir).

## Hocanın Özellikle Vurguladığı Kısımlar

- Dosya adını koda gömmeyin
  - Okunacak dosyanın adı kullanıcıdan alınmalıdır; koda gömülü dosya adları özellikle ödev değerlendirmesinde sorun çıkarır.
- Bağlı listeye sona eklerken son düğümü saklayın
  - Her eklemede baştan sona yürümek gereksizdir; `end` işaretçisi ile ekleme sabit zamanda yapılır.
- C'de birden fazla değer döndürmek
  - Python ya da MATLAB'daki gibi doğrudan birden çok dönüş değeri yoktur; dolaylı olarak işaretçi parametreleriyle ya da tüm sonuçları içeren bir struct döndürerek yapılır.
  - Bir veri setinden ortalama, standart sapma, en küçük, en büyük gibi çok sayıda istatistik çıkarılacaksa hepsini bir struct'ta toplayıp döndürmek daha düzenlidir.
- Fonksiyondan dönen adres heap'te olmalı
  - Yerel (stack) değişkenin adresi döndürülmez; `malloc` ile açılan alan ya da `static` değişken fonksiyon bittikten sonra da yaşar.
- `malloc` ile yapı açarken boyuta dikkat
  - Hoca `sizeof(ENUZAKNOKTA*)` yazdığını sonradan fark edip `sizeof(ENUZAKNOKTA)` olarak düzeltti: açılacak şey yapının kendisidir, işaretçisi değil.
- Ağaçta ilk kök NULL olmalı
  - `TreeNode *root;` ilk değer verilmeden `insertNode`'a gönderilince program çöktü (segmentation fault); `root = NULL` ile başlatmak gerekir.
- Özyinelemeli `insertNode` neden `root` döndürür
  - Kök (ya da alt ağacın kökü) fonksiyon içinde değişebilir. Dönüş değeri kullanılmasaydı `void` fonksiyona çift işaretçi (`TreeNode **`) göndermek gerekirdi.

## Kısa Tekrar Notları

- `head = end = tmp;` ilk düğüm; sonrakiler `end->next = tmp; end = end->next;`.
- `while(!feof(fp))` ile dosya sonuna kadar oku, bitince `fclose`.
- Özyinelemeli liste yazdırma: düğümü yaz, `f(tmp->next)` çağır; temel durum NULL.
- Uzaklık karşılaştırmasında karekök gerekmez: $x^2 + y^2$ yeterli.
- Birden çok sonuç: işaretçi parametre (`int *dmax`) ya da struct döndürme.
- Fonksiyondan dönen struct işaretçisi `malloc` ile heap'te açılır.
- İç içe erişim: `n->pt->x`.
- Dairesel listede son düğüm `head`'i gösterir; çift yönlü listede `prev` ve `next` vardır.
- Yığın: başa ekle, baştan sil. Kuyruk: sona ekle (tail), baştan sil (head).
- İkili arama ağacı: büyükse sağ, küçükse sol.
- Preorder: kök-sol-sağ; inorder: sol-kök-sağ; postorder: sol-sağ-kök.
- `root = NULL` ile başla; `insertNode` güncel kökü döndürür.

## Detaylı Açıklamalar

- Nokta listesi örneğinin akışı
  - Program önce dosya adını okur, `dosyadanOku` ile her satırdaki iki tamsayıyı bir düğüme yazarak bağlı listeyi kurar, listeyi önce iteratif sonra özyinelemeli olarak yazdırır. Hoca ilk çalıştırmada dosyanın açılamadığını gördü; sorun `scanf` biçim dizgisinde `%` işaretinin unutulmasıydı (`"[^\n]s"` yerine `"%[^\n]s"`). Bir öğrencinin uyarısıyla düzeltildi.
  - Ekrandaki bir çalıştırmada en büyük uzaklık değeri 401, en uzak nokta (1,20) olarak bulundu: $1^2 + 20^2 = 401$. Aynı sonuç sürüm 2 ile de elde edildi.
- İşaretçi parametreyle değer döndürmek
  - `enUzakNoktaBul(head, &d)` çağrısında `d`'nin adresi gönderilir. Fonksiyon `*dmax = d;` ile çağıranın değişkenine yazar; `return max;` ile de düğümü döndürür. Böylece bir fonksiyondan dolaylı olarak iki bilgi alınmış olur.
  - Ders sonrası not: ekranda `main` içindeki `int d;` ilk değer verilmeden gönderildi ve fonksiyon `if(d > *dmax)` ile bu değeri karşılaştırdı. Başlangıç değeri belirsiz olduğundan doğru davranış için `int d = 0;` yazılmalıdır. Derste sonuç doğru çıktı, ama bu güvence değildir.
- Struct döndürmek ve iç içe erişim
  - Sürüm 2'de dönüş türü `ENUZAKNOKTA*` olur. Yapı içinde uzaklık ve düğüm işaretçisi birlikte taşınır. `n->pt->y` ifadesi "n'nin gösterdiği yapının `pt` alanının gösterdiği düğümün `y` alanı" demektir. Hoca bu iç içe erişimin nesneye yönelik programlamada (Java'da `.` ile) çok karşılaşılacağını, örneğin öğrencinin aldığı dersin ders kodu gibi çok seviyeli ilişkilerde kullanılacağını söyledi.
  - Prototip eklenmeden fonksiyon `main`'de kullanılınca derleyici örtük bildirim varsaydı, "conflicting types" hatası ve işaretçiye tamsayı atama uyarısı verdi (ekrandan, 00:50:00). Prototip eklenince düzeldi.
- Bellek bölgeleri
  - Stack sınırlıdır; yerel değişkenler orada yaşar ve fonksiyon bitince yerleri yeniden kullanılabilir. Heap program yaşadığı sürece kalır; oradan `malloc`, `calloc`, `realloc` ile yer alınır, `free` ile bırakılır. `static` değişken bir kez oluşturulur ve program kapanana kadar saklanır.
- Deitel slaytlarındaki veri yapıları
  - Sıralı ekleme yapan `insert`, değer silen `delete`, `isEmpty` ve `printList` fonksiyonları olan bir bağlı liste; `push`, `pop`, `isEmpty`, `printStack` fonksiyonları olan bir yığın; `enqueue`, `dequeue`, `isEmpty`, `printQueue` fonksiyonları olan bir kuyruk gösterildi. `dequeue` başındaki düğümün verisini alır, `*headPtr`'ı bir sonrakine kaydırır, kuyruk boşaldıysa `*tailPtr`'ı da NULL yapar ve eski düğümü `free` eder (ekrandan, 01:10:00).
  - Slaytlardaki ağaç örneği rastgele 10 değeri `insertNode(&rootPtr, item)` ile ekler; burada çift işaretçi (`TreeNodePtr *treePtr`) kullanılır (ekrandan, 01:15:00).
- Ağaç gezinme ve derste görülen çıktılar
  - Elle kurulan 10 (sol 5, sağ 15) ağacının preorder çıktısı `10 5 15` oldu.
  - Klavyeden 10, 8, 20, 0 girildi. Hocanın ekranında preorder `10 8 0 20` çıktı.
  - Ders sonrası not: ekranda `postorder` fonksiyonunun gövdesi alt ağaçlar için `postorder` yerine `preorder`'ı çağırıyordu (ekrandan, 01:30:00); `inorder`'ın da aynı biçimde yazıldığı görülen çıktılardan anlaşılıyor. Bu yüzden derste inorder `8 0 10 20`, postorder `8 0 20 10` görüldü ve hoca 0'ı 8'in sağ çocuğu gibi yorumladı. Oysa 0 < 8 olduğu için 0, 8'in sol çocuğudur. Alt çağrılar düzeltildiğinde doğru çıktılar inorder `0 8 10 20`, postorder `0 8 20 10` olur (ajan gcc ile derleyip denedi).
- Önerilen alıştırmalar
  - `insertNode`'u özyineleme kullanmadan `while` döngüsüyle yazmak ve ağaçtan düğüm silme (`delete`) fonksiyonunu yazmak önerildi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
