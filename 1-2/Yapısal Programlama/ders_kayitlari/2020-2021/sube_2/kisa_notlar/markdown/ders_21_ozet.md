# Ders 21 Çalışma Özeti

## Genel Konular

- Oturumun yapısı
  - Bu kayıt bir uygulama oturumudur. Yeni konu anlatılmadı; struct, bağlı liste, dinamik bellek, özyineleme, string işlemleri ve makro konularını birleştiren tek bir örnek problem, hazır bir C programı üzerinden satır satır açıklandı, çalıştırıldı ve sorular cevaplandı.
- Problem: kütüphane raflarına kitap yerleştirme (ekrandan, 00:15:00)
  - 11 raflı bir kitaplığa kitaplar yerleştirilecektir. Hangi rafa konacağına, kitabın ismine göre hesaplanan bir kodla karar verilir.
  - Kod, kitap isminin bütün karakterlerinin ASCII değerlerinin toplamıdır: $\text{Kod} = \sum_i \text{ascii}(\text{Kitap\_ismi}[i])$.
  - Raf numarası: $\text{Raf\_No} = \text{Kod} \bmod \text{Raf sayısı}$.
  - Örnek: "Tutunamayanlar" için $84+117+116+117+110+97+109+97+121+97+110+108+97+114 = 1494$, $1494 \bmod 11 = 9$, yani 9. raf (ekrandan, 00:15:00).
  - İstenen işlemler: ismi verilen kitabın raf numarasını belirleyip listeye eklemek, eklenen bütün kitapların raf bilgilerini listelemek, ismi verilen kitabı arayıp bulunursa raf numarasını, bulunmazsa kısa bir mesaj göstermek. Program C dilinde yazılacaktır.
- Veri yapısı seçimi: dizi mi bağlı liste mi?
  - Her kayıtta kitap ismi, kod ve raf numarası birlikte tutulacağı için bir `struct` tanımlanır. Bu struct'lar dizi ya da bağlı liste içinde tutulabilir.
  - Dizi: istenen elemana indeksle doğrudan erişilir; boyutu büyütmek için yeni dizi açıp kopyalamak, araya eleman eklemek için elemanları kaydırmak gerekir.
  - Bağlı liste: elemana ulaşmak için baştan dolaşmak gerekir; ama boyut kolayca büyür, başa ekleme ve silme sabit zamanda yapılır. Bu örnekte bağlı liste kullanılır.
- Programın yapısı (ekrandan, 00:20:00 ve 00:25:00)
  - `MAXSIZE` (20) ve `SHELF` (11) makroları; `name`, `code`, `index` ve `next` alanlı `struct node`; `typedef struct node List;`.
  - Fonksiyonlar: `void insert(List **headRef, char bookName[])`, `void search(List *head)`, `void display(List *head)`, `int findKey(char *s)`.
  - `main` içinde `List *head = NULL;` ile boş liste başlar; sonsuz `while(1)` döngüsünde 1. Insert, 2. Display, 3. Search, 4. Exit menüsü `switch-case` ile işlenir.
- `findKey`: özyinelemeli ASCII toplamı (ekrandan, 00:25:00)
  - `return *s == 0 ? 0 : *s + findKey(s + 1);` String bitince (`'\0'`) 0 döner; değilse ilk karakterin değerine, bir sonraki karakterden başlayan alt stringin toplamı eklenir.
  - "book" örneğiyle çağrı zinciri: `b + f("ook")`, `o + f("ok")`, `o + f("k")`, `k + f("")`; en içteki 0 döner, değerler geri dönerken toplanır (ekrandan, 00:40:00).
- `insert`: başa ekleme (ekrandan, 00:25:00)
  - `malloc` ile yeni düğüm açılır, `findKey` ile kod, `key % SHELF` ile raf numarası bulunur, isim `strcpy` ile kopyalanır.
  - `newnode->next = (*headRef);` ve `(*headRef) = newnode;` ile yeni düğüm listenin başına eklenir.
- `display`: listeyi baştan sona dolaşıp her düğümün ismini, kodunu ve raf numarasını yazar; düğüm işaretçisi her adımda `next` ile ilerletilir.
- `search`: doğrusal arama
  - Liste boşsa (`head == NULL`) bulunamadı mesajı verilir. Değilse geçici `tempNode` işaretçisi `head`'den başlatılır; liste bitmedikçe ve isim eşleşmedikçe `tempNode = tempNode->next` ile ilerlenir.
  - Döngüden sonra `tempNode == NULL` ise kitap yoktur; değilse bulunduğu raf yazdırılır. İsimler `strcmp` ile karşılaştırılır.
- Çalıştırma sonucu (ekrandan, 00:35:00)
  - `aa (194) -> 7`, `Tutunamayanlar (1494) -> 9`, `nutuk (567) -> 6`. Liste başa eklemeyle kurulduğu için son eklenen en üstte görünür.
  - "nutuk" arandığında 6. raf bulunur; "zz" arandığında kitabın kitaplıkta olmadığı yazılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- `head`'i değiştiren fonksiyonda çift işaretçi
  - Listenin başını değiştirmenin üç yolu vardır: `head`'i global tanımlamak (tercih edilmez), `head`'i tek işaretçi olarak gönderip değiştirilmiş hâlini `return` etmek ya da `List **` ile adresini gönderip fonksiyon içinde `*headRef`'i değiştirmek. Bu örnekte yalnız `insert` başı değiştirdiği için çift işaretçi alır; `display` ve `search` listeyi değiştirmediği için tek işaretçi yeterlidir.
- `scanf("%s", ...)` boşlukta durur
  - "Şeker Portakalı" girilirse yalnız "Şeker" okunur. Boşluk içeren satırı okumak için `scanf` biçimi satır sonuna kadar okuyacak şekilde (`%[^\n]`) yazılmalı ya da `fgets` gibi fonksiyonlar kullanılmalıdır.
- Stringe atama yapılmaz, kopyalanır
  - `newnode->name = bookName` yazılamaz; `strcpy` kullanılır.
- NULL düğümün alanına erişmemek
  - Arama döngüsü `tempNode` NULL olduğu için bittiyse, ardından `tempNode->name` ile karşılaştırma yapmak NULL işaretçiyi kullanmak olur ve program hata verir. Önce NULL kontrolü yapılmalı, gerekirse `return` edilmeli ya da `if-else` kurulmalıdır.
- `malloc` sonucu kontrol edilmeli
  - Örnek kodda `malloc` dönüşünün NULL olup olmadığı kontrol edilmemiştir; kontrol eklemek daha doğrudur.
- `break` yalnız `switch-case` içinde
  - Döngülerde `break` kullanılmamaya çalışılır; `switch-case` ise `break`'in kullanıldığı nadir yapılardandır.
- Aynı rafa birden fazla kitap
  - Farklı isimlerin kodu aynı rafı verebilir, bu doğaldır (çakışma). Aynı isimli kitap iki kez eklenebilir; istenirse eklemeden önce isim kontrolü yapan bir `if` konabilir. Gerçek sistemlerde aynı kitabın kopyaları ayrı bir kimlik (ID) alanıyla ayırt edilir. Çakışmaların hash ve bağlı listeyle çözümü veri yapıları dersinin konusudur.

## Kısa Tekrar Notları

- Kod = karakterlerin ASCII toplamı; raf = kod mod 11.
- "aa" → 194 → 7; "Tutunamayanlar" → 1494 → 9; "nutuk" → 567 → 6.
- Büyük ve küçük harfin ASCII değeri farklıdır ('T' = 84, 't' = 116), bu yüzden kod büyük/küçük harfe duyarlıdır.
- `typedef struct node List;` ile `struct node` yerine `List` yazılır.
- Başa ekleme: `newnode->next = *headRef; *headRef = newnode;`.
- `head`'i değiştiren fonksiyon ya `List **` alır ya da yeni `head`'i döndürür; global `head` tercih edilmez.
- Dolaşma: `while (tmp != NULL ...) tmp = tmp->next;`.
- `strcmp` eşitse 0, birinci büyükse pozitif, küçükse negatif döner.
- `%s` boşlukta durur; satır için `%[^\n]` ya da `fgets`.
- `scanf` okunan stringin sonuna `'\0'` ekler; özyineleme bu karakterde durur.
- NULL düğüme `->` ile erişme.

## Detaylı Açıklamalar

Örnek problem, karma (hash) mantığının basit bir ön hâlidir: kitabın isminden bir sayı üretilir ve bu sayının raf sayısına göre kalanı rafı belirler. Kod, isimdeki karakterlerin ASCII değerleri toplanarak bulunur. Büyük harf ile küçük harfin ASCII değerleri farklı olduğundan "Tutunamayanlar" ile "tutunamayanlar" farklı kod verir. Raf sayısı programda `SHELF` makrosuyla 11 olarak sabitlenmiştir; istenirse kullanıcıdan da alınabilir.

Her kitap için isim, kod ve raf numarası birlikte saklanacağından bunlar bir `struct node` içinde toplanır. Kaç kitap ekleneceği önceden bilinmediği için kayıtlar dinamik olarak (`malloc`) açılan düğümlerle tek yönlü bir bağlı listede tutulur. Her düğümün `next` alanı bir sonraki düğümün adresini gösterir; son düğümün `next` değeri NULL'dır. Listenin başı `head` işaretçisinde tutulur; başı kaybetmemek, sonraki arama ve listeleme işlemleri için gereklidir.

`findKey` fonksiyonu döngü yerine özyinelemeyle yazılmıştır. `s` bir karakter işaretçisidir; `*s` o anki karakteri, `s + 1` bir sonraki karakterden başlayan alt stringi gösterir. Karakter `'\0'` olduğunda (string bittiğinde) 0 döner. "book" için çağrılar `b + f("ook")`, `o + f("ok")`, `o + f("k")`, `k + f("")` biçiminde iç içe açılır; en içteki çağrı 0 döndürünce sonuçlar geri dönerken toplanır ve en dışta bütün karakterlerin toplamı elde edilir (ekrandan, 00:40:00). Kodun yorum satırında aynı ifadenin `if-else` hâli de verilmiştir (ekrandan, 00:25:00).

`insert` fonksiyonu yeni düğümü listenin başına ekler. Yeni düğümün `next`'i, o anda `head`'in gösterdiği düğümü gösterecek şekilde ayarlanır, ardından `head` yeni düğüme eşitlenir. Böylece liste boşken de (head NULL) doğru çalışır: ilk düğümün `next`'i NULL olur. Sona ekleme de yapılabilirdi; bunun için geçici bir işaretçiyle son düğüme kadar gidilip ekleme yapılırdı. `head` fonksiyon içinde değiştiği için `main`'deki `head`'in de değişmesi gerekir. Bu yüzden `insert(&head, bookName)` çağrısıyla `head`'in adresi gönderilir ve fonksiyon `List **headRef` alır.

`search` fonksiyonu listeyi baştan sona doğrusal olarak tarar. Döngü iki durumda biter: liste sona ulaştığında (`tempNode == NULL`) ya da isim eşleştiğinde. Döngüden sonra önce NULL kontrolü yapılır. Sıra ters kurulursa, yani bulunamama durumunda NULL olan `tempNode`'un `name` alanı okunmaya çalışılırsa, program var olmayan bir düğüme erişmeye çalışır ve hata verir.

Program `gcc -Wall` ile derlenip derste girilen verilerle denendi ve ekrandaki çıktıların aynısı elde edildi Kodun ekranda görünmeyen kısımları tamamlanarak derlendi; kodun tamamı genişletilmiş nottadır.

- Ders sonrası not: Ekrandaki kodda `scanf("%s", &bookName)` yazılıdır. `bookName` zaten dizinin ilk elemanının adresine dönüştüğü için doğrusu `scanf("%s", bookName)` biçimidir; `&bookName` ile `gcc -Wall` biçim uyarısı (`-Wformat`) verir, ama adres değeri aynı olduğu için program çalışır.
- Ders sonrası not: Problem metninde kod "unique kod" diye anılmıştır, ama ASCII toplamı benzersiz değildir; farklı isimler aynı kodu, daha sıklıkla da aynı rafı verebilir (derste de çakışma olarak tartışıldı). Metindeki formülde son terim `Kitap_ismi[n]` yazılmıştır; N harfli bir isimde son indeks büyük olasılıkla `N-1` olmalıdır.
- Ders sonrası not: Altyazıda arama fonksiyonundaki karşılaştırma için "str copy" geçer; anlatılan davranış (eşitse 0, büyükse pozitif, küçükse negatif) `strcmp` fonksiyonuna aittir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
