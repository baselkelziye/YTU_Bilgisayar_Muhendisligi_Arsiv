# Ders 27 Çalışma Özeti

## Genel Konular

- Uygulama sorusu: acil serviste öncelikli hasta kuyruğu (ekrandan, 00:10:00 ve 00:15:00)
  - Bu oturum dönemin özeti niteliğinde bir uygulamadır. Yapı (struct), bağlı liste (linked list) ve dosya işlemleri tek problemde birlikte kullanılır.
  - Hastanenin acil servisi için hastaların sırasını izleyen bir kuyruk kurulur. Her hastadan isim, soy isim, T.C. kimlik numarası ve yaş alınır. Ayrıca bir öncelik bilgisi tutulur: 0 acil değil, 1 acil (öncelikli) demektir.
  - Kural 1: acil olmayan hasta kuyruğun sonuna eklenir. Örnekte 1, 2, 3, 4, 5 numaralı hastalar sırayla gelir ve kuyruk `1 2 3 4 5` olur.
  - Kural 2: öncelikli hasta, listedeki son öncelikli hastanın hemen arkasına yerleşir. Listede hiç öncelikli hasta yoksa listenin başına eklenir. 6. hasta öncelikli olduğu için kuyruk `6 1 2 3 4 5` olur; ardından gelen öncelikli 7. hasta 6'nın arkasına girer: `6 7 1 2 3 4 5`.
  - Kural 3: doktora görünmekten vazgeçen hasta, adı kullanılarak kuyruktan çıkarılır. 3. hasta çıkınca kuyruk `6 7 1 2 4 5` olur.
  - Kural 4 ve 5: kuyruktaki hastaların bilgileri dosyada tutulur; istendiğinde dosyadan okunup gösterilir.
- Neden bağlı liste ve neden yapı?
  - Kuyruk en kolay bağlı listeyle kurulur.
  - Dizinin avantajı indisle doğrudan erişimdir. Bağlı listede ortadaki bir elemana ulaşmak için baştan başlayıp ilerlemek gerekir.
  - Bağlı listenin avantajı araya ekleme ve çıkarmanın kaydırma gerektirmemesidir. Her düğüm bir sonrakinin adresini (`next`) tuttuğu için bu işlemler $O(1)$ ile yapılır (yer bulunduktan sonra).
  - Bir hastanın bilgileri farklı türlerdedir (yaş `int`, isim karakter dizisi). Farklı türdeki birden çok bilgiyi bir arada tutmak için `struct` kullanılır.
- Programın üç dosyaya bölünmesi
  - `uygulama.c`: `main` ve bağlı liste işlemleri. `struct_patient.h`: yapı tanımları. `file_opr.c`: dosyaya yazma ve dosyadan okuma.
  - `stdio.h` giriş-çıkış için, `stdlib.h` dinamik bellek (`malloc`) için, `string.h` dizgi işlemleri için eklenir.
  - Kendi başlık dosyamız aynı dizindeyse adı tırnak içinde yazılır (`#include "struct_patient.h"`).
  - `file_opr.c` doğrudan `#include` edildi. Diğer yol, her dosyayı ayrı derleyip nesne dosyalarını bağlamaktır; dersin sonunda gösterildi.
- Yapı tanımları (ekrandan, 00:20:00)
  - `typedef struct node { char name[30], surname[30]; char ID[12]; int age; int prior; } Patient;`
  - `typedef struct Patient_Node { Patient data; struct Patient_Node *next; } Patient_Node;`
  - Biri hasta verisini, diğeri liste düğümünü tutar. İkisi birleştirilebilirdi; ayırmak bir tercih.
  - `typedef`, bir türe yeni bir ad verir. `typedef` olmasaydı `}` sonrasındaki ad bir tür adı değil, o yapı türünden bir değişken olurdu.
  - `Patient_Node` kendine gönderen bir yapıdır (self-referential): `next` bir sonraki düğümün adresini tutar.
- Makrolar (`#define`)
  - Ön işlemci, makro adının geçtiği yere yanındaki metni olduğu gibi koyar. `MAX_SIZE` yerine `20` gelir; `char name[MAX_SIZE]` derleyiciye `char name[20]` olarak gider.
  - Bu yüzden `#define MAX_SIZE = 20` yazılmaz: sonuç `name[= 20]` olurdu.
  - Uyarı mesajı makrosu tırnak içinde tanımlanır; böylece `printf(WARNING)` bir dizgi sabitine açılır.
  <!-- BELİRSİZ: WARNING makrosunun tam metni ve uygulama.c'nin ilk 18 satırı karelerde görünmüyor. -->
- `main` ve menü (ekrandan, 00:35:00)
  - `char name[MAX_SIZE]; int choose = 1; Patient_Node *head = NULL;`
  - `while(choose > 0)` döngüsünde menü: 1 yeni hasta, 2 adla hasta silme, 3 listeyi dosyadan okuma, 0 çıkış. `choose` başta 1 yapıldığı için döngüye girilir.
  - `switch(choose)`: `case 1` → `insert_patient_to_list(create_new_patient(), &head); printListWithAllInformations(&head);` `case 2` → ad okunur, `delete_patient(name, &head);` ve dosya yeniden yazılır. `case 3` → `read_File();`
- Yeni düğüm: `create_new_patient` (ekrandan, 00:35:00)
  - Parametre almaz, `Patient_Node *` döndürür.
  - `new_node = (Patient_Node*)malloc(sizeof(Patient_Node));` Bellek ayrılamazsa `malloc` `NULL` döner; bu durumda uyarı yazılıp `exit(1)` ile çıkılır.
  - Bilgiler `scanf(" %s", new_node->data.name);` gibi okunur. `name`, `surname`, `ID` dizi olduğu için adları zaten adrestir, `&` konmaz. `age` ve `prior` için `&new_node->data.age` yazılır.
  - Düğüm henüz listeden bağımsızdır: `new_node->next = NULL; return new_node;`
- Ekleme: `insert_patient_to_list(Patient_Node *new_node, Patient_Node **head)` (ekrandan, 00:40:00, 00:45:00, 00:55:00)
  - Liste boşsa `(*head) = new_node;` ve dönülür.
  - Değilse `var_head` (gezici), `last_prior` (son öncelikli düğüm) ve `temp` (takas için) tanımlanır; ilk ikisi `*head` ile başlar.
  - Yeni hasta öncelikliyse liste baştan sona gezilir; `prior != 0` olan her düğümde `last_prior` güncellenir.
  - `last_prior` hâlâ baş ise ve başın önceliği 0 ise listede öncelikli hasta yoktur: yeni düğüm başa eklenir.
  - `last_prior` baş ise ama başın önceliği 1 ise yeni düğüm başın arkasına eklenir. `last_prior` baş değilse yeni düğüm `last_prior`'ın arkasına eklenir. İki durumda kod aynıdır: `temp = last_prior->next; last_prior->next = new_node; new_node->next = temp;`
  - Yeni hasta öncelikli değilse `while(var_head->next != NULL)` ile son düğüme gidilir ve `var_head->next = new_node;` yapılır.
- Silme: `delete_patient(char *name, Patient_Node **head)` (ekrandan, 01:10:00)
  - Liste gezilir; `strcmp(var_head->data.name, name) == 0` olan düğüm `patient` işaretçisinde tutulur.
  - Silinecek düğüm baş ise `(*head) = (*head)->next;` yapılır.
  - Değilse önce `patient == NULL` kontrol edilir ("Could not find the element with ..."). Bulunduysa liste yeniden gezilip silinecek düğümden bir önceki bulunur (`while(var_head->next != patient)`), `var_head->next = var_head->next->next;` ile bağlantı atlanır ve `free(patient);` yapılır.
- Dosya işlemleri: `file_opr.c` (ekrandan, 01:05:00 ve 01:20:00)
  - `printListWithAllInformations(Patient_Node **head)`: `fopen("list.txt","wb")`, `NULL` kontrolü, liste baştan gezilerek her düğüm için `fwrite(&(var_head->data), sizeof(Patient), 1, fs);`, sonra `fclose(fs);` ve "File is updated".
  - Dosya her değişiklikte baştan yazılır, bu yüzden ekleme kipi (`ab`) değil yazma kipi (`wb`) seçildi. Yeni düğümün dosyadaki yerini bulup ekleme yapmak daha verimli bir sürüm olurdu.
  - `read_File()`: `Patient patient;` yerel yapı değişkeni, `fopen("list.txt","rb")`, `while(fread(&patient, sizeof(Patient), 1, fs) == 1)` döngüsünde alanlar `patient.name` gibi nokta ile yazdırılır, sonra `fclose`.
- Programın çalıştırılması (01:20:43–01:22:52)
  - Önceliksiz bir hasta, ardından öncelikli bir hasta eklendi; öncelikli olan listenin başına geçti. Üçüncü olarak öncelikli bir hasta daha eklendi ve ilk öncelikli hastanın arkasına yerleşti. Önceliksiz hasta en sonda kaldı. Önceliksiz hasta adıyla silindi ve listeden çıktı.
- Ayrı derleme, bağlama ve Makefile (ekrandan, 01:30:00 ve 01:35:00)
  - Küçük örnek: `uygulama.c` içinde `int` bir değişkene 9 verilir, `square` fonksiyonu çağrılır; `square.c` sayının karesini döndürür; prototip `func.h` başlığındadır. Çıktı: `Program started!`, `81`, `Program successfully ended`.
  - Elle: `gcc -c uygulama.c -o uygulama.o`, `gcc -c square.c -o square.o`, sonra `gcc uygulama.o square.o -o program`.
  - Bunu her seferinde yazmamak için uzantısız `Makefile` dosyası yazılır ve Windows'ta `mingw32-make` komutuyla çalıştırılır.
  - `make` yalnız ilk hedefi işler. Bu yüzden ilk hedef `program:uygulama square` yapıldı; önce iki nesne dosyası üretilir, sonra bağlanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Son öncelikli elemanın yerini bulmak
  - Bu sorunun sıradan "sona ekle" sorusundan farkı budur. Yeni öncelikli hasta, öncelikli hastaların önüne değil, son öncelikli hastanın arkasına girmelidir.
- Sona eklerken `next`'i sorgulamak
  - Döngü koşulu `var_head->next != NULL` olmalıdır, `var_head != NULL` değil. Gezici `NULL`'a ulaşırsa son düğüme geri dönülemez ve ekleme yapılamaz.
- Araya eklemede `temp` kullanmak
  - `last_prior->next = new_node;` doğrudan yazılırsa `last_prior`'ın eski sonraki düğümünün adresi kaybolur. Önce `temp` ile saklanır.
- Neden çift işaretçi (`**head`)?
  - `head` global yapılırsa her fonksiyon listeyi değiştirebilir; bu tercih edilmez.
  - Tek işaretçi gönderilirse baştaki değişiklik fonksiyonda kalır, yeni `head`'in `return` ile döndürülmesi gerekir.
  - `&head` gönderilip `**head` ile alınırsa değişiklik `main`'deki listeye yansır.
- Dizinin adı adrestir
  - `scanf` ile karakter dizisi okurken `&` konmaz; `&` adresin adresi olur. `int` alanlar için `&` gerekir.
- İşaretçiden yapı alanına erişim
  - `(*new_node).data` da doğrudur, ama parantez gerekir ve okunması zordur. Genel olarak ok işleci (`->`) tercih edilir. `data` işaretçi değil yapı değişkeni olduğu için onun alanlarına nokta ile geçilir: `new_node->data.name`.
- `wb` ile yazılan dosya `rb` ile okunur
  - İkili kipte yazılan dosya metin düzenleyicide düzgün görünmez; aynı kipte okunmalıdır.
- `malloc` ve `fopen` dönüşünü kontrol etmek
  - İkisi de başarısızlıkta `NULL` döner; her seferinde kontrol edilir.

## Kısa Tekrar Notları

- Kural: önceliksiz hasta sona, öncelikli hasta son öncelikli hastanın arkasına; öncelikli hasta yoksa başa.
- `last_prior` ve `var_head` `*head` ile başlar; gezinti sonunda `last_prior` son öncelikli düğümü gösterir.
- Ekleme durumları: boş liste, sona ekleme, başa ekleme, başın arkasına ekleme, `last_prior`'ın arkasına ekleme.
- Araya ekleme: `temp = p->next; p->next = yeni; yeni->next = temp;`
- Silme: bulunan düğüm baş ise `*head = (*head)->next`; değilse öncekini bul, `onceki->next = onceki->next->next; free(silinen);`
- Dizgi karşılaştırma `==` ile değil `strcmp` ile yapılır; eşitse 0 döner.
- `fwrite(adres, boyut, adet, akış)` bellekten dosyaya, `fread(adres, boyut, adet, akış)` dosyadan belleğe yazar; `fread` okuduğu öğe sayısını döndürür.
- `#define MAX_SIZE 20` yazılır, `= 20` yazılmaz; makro düz metin yerine koymadır.
- `gcc -c x.c -o x.o` yalnız derler; `gcc a.o b.o -o program` bağlar; `Makefile` bu komutları otomatikleştirir.

## Detaylı Açıklamalar

- Ekleme fonksiyonunun durum analizi
  - Liste boşken eklenen ilk düğüm doğrudan baş olur. Sonraki eklemelerde yeni düğümün önceliğine bakılır.
  - Önceliksiz yeni düğüm için öncelik bilgisinin hiçbir önemi yoktur: gezici son düğüme kadar ilerletilir ve yeni düğüm oraya bağlanır.
  - Öncelikli yeni düğüm için liste sonuna kadar taranır. Öncelikli düğümler hep listenin başında bir blok oluşturduğu için, önceliksiz bir düğüm görüldüğünde döngüden çıkılabilirdi. Derste bunun kodu fazladan dolaştırdığı ve iyileştirilebileceği söylendi.
  - Tarama bitince `last_prior` hâlâ başı gösteriyorsa iki olasılık vardır: baş önceliksizdir (o zaman hiç öncelikli düğüm yoktur, yeni düğüm başa gelir) ya da baş tek öncelikli düğümdür (yeni düğüm başın arkasına girer). Bunu ayırmak için başın önceliğine ayrıca bakılır.
  - Başa ekleme `temp = *head; *head = new_node; new_node->next = temp;` ile yapıldı. Burada `last_prior` da başı gösterdiği için `temp` şart değildi, ama `last_prior`'ın görevi bu olmadığı için takaslarda düzenli olarak `temp` kullanıldı.
- Silme fonksiyonunun yapısı
  - Arama döngüsü eşleşme bulunca durmaz, listenin sonuna kadar gider. Sonuçta `patient` adı eşleşen son düğümü gösterir. Tek kişi silinecekse eşleşmede durmak yeterlidir. Aynı adlı bütün kişileri silmek istense bu yapı daha uygun olurdu.
  - Gerçek bir sistemde silme için isim değil kimlik numarası kullanılmalıdır, çünkü aynı adlı birden çok hasta olabilir.
  - Silinecek düğüm baş olduğunda kod `free` yapmıyor; derste bunun atlanmaması gerektiği söylendi.
  - Silinecek düğümün öncekini bulmak için liste ikinci kez gezilir. Bunun amacı bağlantıyı onarıp silinen düğümü `free` ile bellekten kaldırabilmektir.
  - Ders sonrası not: liste boşken silme seçilirse `patient` ve `*head` ikisi de `NULL` olduğu için `patient == (*head)` koşulu doğru olur ve `(*head)->next` ifadesi `NULL` işaretçiyi açar. Ekrandaki kod karelerden kurulup ajan tarafından boş listede silme denendiğinde gerçekten segmentation fault verdi. Önce `*head == NULL` kontrolü eklenmelidir.
- Dosyadan silme sorusu
  - **Soru:** Dosyadan bir kayıt nasıl silinir? **Cevap:** C'de dosyadan tek kayıt silen hazır bir fonksiyon yoktur. Bu programda liste her değişiklikte dosyaya baştan yazılır (üzerine yazma), böylece silinen kayıt dosyadan da çıkar.
- `strcmp`'nin dönüş değeri
  - İki dizgi eşitse 0 döner. Birinci dizgi ASCII sırasında büyükse pozitif, küçükse negatif bir değer döner.
  - Ders sonrası not: derste küçük olma durumu için "eksi bir döner" dendi. Standart yalnız negatif bir değer garanti eder; değer her zaman $-1$ olmayabilir. Ajanın denemesinde (Linux, glibc) `strcmp("a", "c")` $-2$ döndürdü.
- Derleyici hakkında
  - Derste GCC'nin bir Linux derleyicisi olduğu ve MinGW'nin onun Windows sürümü olduğu söylendi.
  - Ders sonrası not: GCC, Linux'un değil GNU projesinin derleyicisidir; Linux'ta yaygın kullanılır. MinGW, GCC'yi Windows'a taşıyan araç takımıdır ve `make` aracı orada `mingw32-make` adıyla gelir.
- Makefile'ın çalışma mantığı (ekrandan, 01:35:00)
  - İlk denemede Makefile'da yalnız `uygulama:` hedefi ilk sırada olduğu için `mingw32-make` yalnız onu derledi. İlk hedef `program:uygulama square` yapılınca, önce iki önkoşul hedef işlendi, sonra `gcc uygulama.o square.o -o program` ile bağlama yapıldı.

```text
program:uygulama square
	gcc uygulama.o square.o -o program
uygulama:
	gcc -c uygulama.c -o uygulama.o

square:
	gcc -c square.c -o square.o
```

  - Bu Makefile, `func.h`, `square.c` ve `uygulama.c` ajan tarafından yeniden kurularak Linux'ta `make` ile denendi; üç komut sırayla çalıştı ve program `81` yazdı.
- Kodun derlenmesi
  - Karelerde görünen `struct_patient.h`, `file_opr.c` ve `uygulama.c` satırları birleştirildi. Görünmeyen kısımlar (`#include` satırları, `MAX_SIZE` ve uyarı makrosu, `read_File` içindeki yazdırma satırı) ajan tarafından tamamlandı. Kod `gcc -Wall` ile uyarısız derlendi. Önceliksiz, öncelikli, öncelikli, önceliksiz sırayla dört hasta girildiğinde dosyadan okunan sıra öncelikli 1, öncelikli 2, önceliksiz 1, önceliksiz 2 oldu; baştaki ve aradaki silmeler ve listede olmayan adı silme beklendiği gibi çalıştı.
- Ödev niteliğinde iyileştirmeler (derste önerildi)
  - Silmede isim yerine kimlik numarası kullanmak.
  - Öncelikli eklemede önceliksiz düğüm görülünce taramayı durdurmak.
  - Fazla `head` kontrollerini azaltmak.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
