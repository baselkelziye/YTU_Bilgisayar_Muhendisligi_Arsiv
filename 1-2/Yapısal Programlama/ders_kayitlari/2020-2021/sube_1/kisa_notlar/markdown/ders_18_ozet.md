# Ders 18 Çalışma Özeti

## Genel Konular

- Bağlı listede eleman arama
  - Önceki derste kurulan `EMPLOYEE` türünden bağlı liste üzerinde iki arama fonksiyonu yazıldı: ada göre arayan `find(char *name)` ve kimliğe göre arayan `findByID(int id)` (ekrandan, 00:25:00).
  - Mantık: listenin başını tutan `head` işaretçisinden başlanır, her düğümde aranan değerle karşılaştırılır, eşitse o düğümün işaretçisi döndürülür; liste biterse `NULL` döndürülür.
  - Ad karşılaştırması `strcmp(p->name, name) == 0` ile yapılır; `strcmp` büyük/küçük harfe duyarlıdır.
  - Yapısal programlamada genel amaçlı (her veri türüyle çalışan) bir arama fonksiyonu yazmak kolay değildir, çünkü dönüş türü ve karşılaştırılan alan yapıya bağlıdır. Bu, ileride fonksiyon işaretçileriyle çözülecek.
  - C'de aynı adlı ama parametreleri farklı iki fonksiyon tanımlanamaz: ikinci fonksiyon da `find` adıyla yazılınca derleyici `conflicting types for 'find'` hatası verdi, ad `findByID` yapıldı (ekrandan, 00:25:00).
  - Test: baştaki, ortadaki, sondaki ve listede olmayan eleman arandı; hepsi doğru sonuç verdi.
- Bağlı listeden eleman silme (`delete_element`)
  - Silinecek düğümden bir önceki düğüm bulunmalı, onun `next` alanı silinen düğümün `next`ini göstermeli, sonra silinen düğüm `free` ile bırakılmalıdır.
  - Silinecek düğüm baştaysa önceki düğüm yoktur; bu durumda `head = goner->next` yapılır.
  - Arama döngüsü iki koşulla ilerler: `p != NULL` ve `p->next != goner`. Döngü gövdesi boştur (`;`). Döngüden `p` NULL olarak çıkılırsa eleman bulunamamıştır; değilse `p` silinecek düğümün bir öncesidir.
  - Slayttaki ilk sürümde `else` yalnız `for` satırını kapsıyordu; baş düğüm silinirken `p` hiç atanmadan kullanılıyordu. Kod denemelerde çalıştı ama hoca bu davranışı güvenilmez buldu ve `else` bloğunu süslü parantezle yeniden yazdı (ekrandan, 01:10:00).
- Yapı hizalaması (structure alignment)
  - Bazı bilgisayarlar bir char'dan büyük nesnelerin çift adreslerde başlamasını ister. Bu durumda yapı alanları arasında görünmeyen boşluklar (hole) oluşur.
  - Örnek: `struct ALIGN_EXAMP { char mem1; short mem2; char mem3; } s1;` kısıtlama yoksa 4 bayt, çift adres kısıtı varsa mem1'den sonra ve mem3'ten sonra birer baytlık boşlukla 6 bayt kaplar (ekrandan, 01:20:00).
  - mem2 ile mem3'ün sırası değiştirilirse boşluk kalmaz.
- Bit alanları (bit fields)
  - C'nin desteklediği en küçük veri türü char'dır (8 bit). Yapılar içinde bundan küçük nesneler, yani bit alanları tanımlanabilir.
  - Bit alanları int gibi kullanılır; iki istisna vardır: adresleri alınamaz ve bit alanı dizisi tanımlanamaz (ekrandan, 01:25:00).
  - Tanım: temel tür, alan adı, iki nokta üst üste ve bit genişliği. Bir alanın genişliği temel türün genişliğini geçemez.
  - Taşınabilirlik için `unsigned int` kullanılması önerilir; düz `int` işaretli mi işaretsiz mi yorumlanacağı gerçeklemeye kalmıştır.
  - Örnek: a 3, b 7, c 2 bit; 16 bitlik birimin ilk 12 biti kullanılır, 4 bit boş kalır (ekrandan, 01:35:00).
  - DATE örneği: gün 5, ay 4, yıl 11 bit. Derleyiciye göre alanlar int sınırını aşarak sıkı paketlenebilir ya da her biri 16 bitlik sınıra yaslanıp daha çok boşluk bırakabilir (ekrandan, 01:40:00).
  - Derleyici bitleri düz ya da ters sırayla yerleştirebilir; bunun bir nedeni de bayt sıralamasının (endianness) mimariye göre değişmesidir.
- Ara sınav ikinci sorusunun çözümü
  - Öğrenci yapısı (id, ad, yaş, ortalama), `main` içinde `malloc` ile N elemanlı dinamik dizi, ortalamaya ve ada göre kabarcık sıralaması yapan fonksiyonlar, listeyi yazan fonksiyon ve sonda `free` (ekrandan, 02:05:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bağlı listede doğrudan erişim yoktur
  - Bir öğrenci sorusu üzerine: bağlı listede ortadaki elemana doğrudan erişilemediği için ikili arama gibi $O(n)$'den hızlı aramalar kullanılamaz; bunun için hash tablosu gibi başka veri yapıları vardır.
- Her durumu test etmek
  - Arama ve silme kodu baş, orta, son ve olmayan eleman için ayrı ayrı denenmelidir.
- Atanmamış işaretçiye güvenmemek
  - Kodun bir derleyicide "çalışması", başka bir derleyici ya da işletim sisteminde de çalışacağı anlamına gelmez. Mantık açıkça kodlanmalıdır.
- Alan sırasının bellek kullanımına etkisi
  - Bir sınavda "yapıyı belleği en verimli kullanacak biçimde tanımlayın" denirse hizalama konusu hatırlanmalı; alanların sırasını değiştirmek bile tasarruf sağlar.
  - En iyi bellek kullanımı için ortamı bilmek gerekir; bilinmiyorsa deneme yanılma ile çözülebilir. Bazen bir alana bir bit fazla vermek bile toplamda tasarruf sağlayabilir.
- Dizinin orijinal halinin değişmesi
  - Soru "dizinin orijinal hali değiştirilmelidir" dediği için fonksiyonlar işaretçi alır ve `void` döner. "Değiştirilmemelidir" denseydi her fonksiyon kendi kopyasını `malloc` ile oluşturup onun üzerinde çalışmalıydı.
- `malloc` yalnız bir kez
  - Bellek `main` içinde bir kez ayrılır, işaretçi kaybedilmeden bütün fonksiyonlara gönderilir; sonda `free` unutulmamalıdır.
- Fonksiyon prototipindeki tür
  - Prototipte `struct öğrenci` yazması, kodda da öyle yazılacağı anlamına gelmez; `typedef` ile verilen ad (`STUDENT`) kullanılmalıdır.

## Kısa Tekrar Notları

- `find`: `for (p = head; p != NULL; p = p->next) if (strcmp(p->name, name) == 0) return p; return NULL;`
- C'de fonksiyon aşırı yükleme (overloading) yoktur; farklı parametreli fonksiyonlara farklı ad verilir.
- Silme: önceki düğümü bul, `p->next = p->next->next;`, sonra `free(goner);`. Baş düğümde `head = goner->next;`.
- Yerel değişkenler otomatik olarak NULL ya da 0 olmaz.
- Hizalama boşlukları programcıya görünmez ama bellek harcar; alan sırası önemlidir.
- Bit alanı: `unsigned int day : 5;`. Adres alınamaz, dizi yapılamaz.
- $2^5 = 32$ gün için, $2^4 = 16$ ay için yeter; 11 bitlik yıl alanı 0 ile 2047 arasını tutar.
- Kabarcık sıralaması: dış döngü `i < n-1`, iç döngü `j < n-1-i`; yapılar `temp` ile bütün olarak takas edilir.
- Dizgeler `strcmp(a, b) > 0` ile karşılaştırılır.

## Detaylı Açıklamalar

- **Arama fonksiyonları.** Liste `EMPLOYEE *head;` adlı global işaretçiyle tutulur. `find` fonksiyonu geriye `EMPLOYEE*` döndürür; hoca yıldızı tür adına yakın yazmayı (`EMPLOYEE* find`) anlaşılır bulduğunu söyledi. Ekrandaki kod (ekrandan, 00:15:00):

  ```c
  EMPLOYEE* find(char *name) {
      EMPLOYEE *p;
      for (p = head; p != NULL; p = p->next)
          if (strcmp(p->name, name) == 0) // returns 0, if 2 strings are same
              return p;
      return NULL;
  }
  ```

  `findByID` aynı yapıdadır, yalnız koşul `p->ID == id` olur (ekrandan, 00:25:00). `main` içinde kullanıcıdan ad ya da kimlik alınır, sonuç `NULL` ise "Not found", değilse `printElementP(p)` yazdırılır (ekrandan, 00:45:00).

- **Silme fonksiyonu.** Slayttaki (ders notundaki) sürüm şöyleydi (ekrandan, 00:35:00):

  ```c
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

  Burada `else` yalnız `for` satırını kapsar. Baş düğüm silinirken `for` hiç çalışmaz ve `p` atanmamış kalır, ama `if (p == NULL)` ve `p->next = ...` yine çalışır. Hoca bunu sınamak için `p`'yi yazdırdı; `p` listenin ilk düğümünü gösteriyordu, bu yüzden kod "şans eseri" doğru sonuç verdi. Hoca kodu şu mantıkla düzeltti: baş düğümse `head` güncellenir; değilse önceki düğüm aranır, bulunamazsa mesaj verilip dönülür, bulunursa bağ kurulur; her iki durumda da sonda `free(goner)` çalışır.

  > Ders sonrası not: Hoca baş düğüm silinirken `p`'nin NULL olmasını beklediğini söyledi. C'de yerel (otomatik) değişkenler kendiliğinden NULL ya da 0 olmaz; değeri belirsizdir ve kullanılması tanımsız davranıştır. `gcc -Wall` bu kod için "'p' may be used uninitialized" uyarısı veriyor (ajan testi).

  Ayrıca `main` içinde silme çağrısı `if (p == NULL) printf("Not found"); else delete_element(p);` biçiminde olduğu için olmayan bir ad girildiğinde `delete_element` hiç çağrılmaz; fonksiyonun kendi "could not find" mesajı ancak listeye eklenmemiş bir düğüm doğrudan gönderilince görüldü.

- **Yapı hizalaması.** `char mem1; short mem2; char mem3;` için kısıtlama yoksa mem1 1000'de, mem2 1001-1002'de, mem3 1003'te durur ve 1004 boştur. Çift adres kısıtı varsa mem2 1001'de başlayamaz: 1001 boşluk olur, mem2 1002-1003'e, mem3 1004'e yerleşir, 1005 de boşluk kalır (ekrandan, 01:20:00). Alanlar `char mem1; char mem3; short mem2;` sırasıyla tanımlanırsa mem3 1001'e, mem2 1002-1003'e oturur ve boşluk kalmaz.

- **Bit alanları.** 3+3+2 bitlik üç veri için üç ayrı char yerine `char` temel türlü tek bir yapı yeter. a:3, b:7, c:2 örneğinde 16 bitlik birimin 0-2. bitleri a, 3-9. bitleri b, 10-11. bitleri c olur (ekrandan, 01:35:00); 4 bit boş kalır. Üçü ayrı char olsaydı 5+1+6 = 12 bit boşa giderdi. İki adet 10 bitlik alanda ise her biri ayrı 16 bitlik birime yerleşip 6'şar bit boş bırakabilir. DATE yapısı:

  ```c
  struct DATE{
      unsigned int day : 5;
      unsigned int month : 4;
      unsigned int year : 11;
  };
  ```

  Slayttaki ilk yerleşimde derleyici alanları en yakın char'a paketleyip int sınırını aşmalarına izin verir; her DATE 20 bit kullanır ve sonraki DATE bir sonraki bayt sınırından başlar. Alternatif yerleşimde gün ve ay (9 bit) bir 16 bitlik birime, yıl (11 bit) bir sonrakine konur ve her DATE 32 bit kaplar (ekrandan, 01:40:00). Hoca ilkinin daha az israf ettiğini söyledi.

  > Ders sonrası not: Hoca hesap makinesinde $2^{11}$ için 4096 sonucunu okuyup "4096 yılına kadar" dedi. Doğrusu $2^{11} = 2048$'dir; 11 bitlik işaretsiz alan 0 ile 2047 arasını tutar (4096, $2^{12}$'dir).

  > Ders sonrası not: Hoca "önce MSB sonra LSB" düzenine Little Endian dedi. Doğrusu tersidir: en anlamlı baytı düşük adrese koyan düzen Big Endian, en az anlamlı baytı düşük adrese koyan düzen Little Endian'dır. Hocanın verdiği "Big - Most, Little - Least" hatırlatması doğru eşleşmeyi gösterir.

- **Ara sınav çözümü.** Yapı `typedef struct { int id, age; float grade; char name[20]; } STUDENT;` biçiminde tanımlandı (ekrandan, 02:25:00). `main` içinde `dizi = (STUDENT*)malloc(n*sizeof(STUDENT));` ile yer ayrıldı, elemanlar `dizi[i].alan` gösterimiyle okundu (ekrandan, 02:10:00). Sıralama fonksiyonları kabarcık sıralamasıdır; ada göre olanı `strcmp(dizi[j].name, dizi[j+1].name) > 0` ise takas eder (ekrandan, 02:35:00). Tam çözüm genişletilmiş notta, derlenip çalıştırılmış haliyle verilmiştir.

  > Ders sonrası not: Ada göre sıralama derste doğru sonuç vermedi ve neden çözülemedi. Ekrandaki kodda iç döngü `for (j=0;j<n-1-j;j++)` yazılmıştı (ekrandan, 02:35:00). Doğrusu `j<n-1-i`'dir. Hatalı sınırla $n=3$ için iç döngü yalnız ilk iki elemanı karşılaştırır; bu yüzden aynı girdi ajan testinde de sıralanmadı. Ortalamaya göre sıralama fonksiyonunun iç döngüsü ekranda görülmedi; aynı sınırla yazıldıysa doğru sonuç vermesi büyük olasılıkla girdinin sırasından kaynaklanıyordu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
