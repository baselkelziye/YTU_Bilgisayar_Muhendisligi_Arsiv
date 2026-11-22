# Ders 11 Çalışma Özeti

## Genel Konular

- Yapılara (struct) neden ihtiyaç duyulur
  - Diziler aynı türdeki verileri tutmak için uygundur. Bir varlığa ait farklı türdeki veriler (ad, soyad, sicil numarası, maaş) dizilerle tutulursa her alan için ayrı bir dizi gerekir (ekrandan, 00:05:00):
    - `char names[1000][20], surnames[1000][20];`
    - `int IDs[1000]; float salaries[1000];`
  - Bu durumda aynı kişinin bilgilerinin her dizide aynı indiste durduğunu programcının akılda tutması gerekir. Bu ek karmaşıklık getirir.
  - `struct` bir varlığa ait bütün verileri tek bir yapı altında toplar ve yeni bir veri türü oluşturur. Tanımın sonundaki `;` unutulmamalıdır.
- `typedef` ile tür adı vermek
  - `struct employee` gibi uzun tür adı yerine `typedef` ile kısa bir ad verilir. Ad verilmeyen (anonim) bir struct tanımlanıp `typedef` ile ona `EMPLOYEE` adı verilebilir.
  - Kendi tanımlanan türlerin adı tamamı büyük harfle yazılır; böylece özel tür olduğu hemen anlaşılır.
- Alanlara erişim: nokta ve ok işleçleri
  - Sıradan struct değişkeninde `degisken.alan` yazılır.
  - Struct işaretçisinde `isaretci->alan` yazılır. `p->alan` ifadesi `(*p).alan` ile aynıdır, ama ok gösterimi daha okunaklıdır.
- İç içe yapılar
  - Gün, ay ve yıl gibi kendi içinde anlamlı bir bütün oluşturan veriler ayrı bir struct (`DATE`) olarak tanımlanıp başka bir struct'ın alanı yapılabilir (ekrandan, 00:10:00).
  - Erişim zincirleme yazılır: `degisken.enlisted.year = 2008;` (ekrandan, 00:10:00; slayttaki değişken adı burada genel bir adla yazıldı).
- Struct'ları fonksiyona aktarmak ve struct işaretçileri
  - Struct da değer ile ya da referans ile aktarılabilir. Değer ile aktarmada bütün alanlar kopyalanır. Bu yüzden işaretçi göndermenin kazancı struct'ta daha büyüktür.
  - Struct işaretçisi yalnız ilk alanı değil, struct'ın tamamını gösterir. İşaretçi bir artırılınca bir sonraki alana değil, bir sonraki struct kaydına geçilir.
- Bağlı liste (linked list)
  - Dizilerin zayıf yanları: boyut sabittir, araya eleman eklemek ve aradan silmek zordur, alanı büyütüp küçültmek ek iş ve performans kaybı demektir.
  - Bağlı liste düğümlerden oluşur. Her düğümün iki parçası vardır: veri (data) ve bir sonraki düğümü gösteren bağlantı (link, `next` işaretçisi) (ekrandan, 00:15:00).
  - Slayttaki örnek liste tam sayı tutar: 49 → 15 → 73 → 87 → 10. İlk düğüm baş düğüm (head), son düğüm kuyruk düğümdür (tail). Son düğümün `next` işaretçisi `NULL`'dur ve listenin bittiğini gösterir.
  - Türler: tek bağlı (single linked) listede yalnız ileri gidilir. Çift bağlı (double linked) listede her düğümde önceki ve sonraki düğümü gösteren iki işaretçi vardır. Son düğüm ilk düğümü gösterirse liste daireseldir (circular). Derste en basit tür olan tek bağlı, dairesel olmayan liste kullanıldı.
  - Baş düğüm (head) asla kaybedilmemelidir. Liste üzerinde dolaşmak için ayrı bir işaretçi tanımlanır, `head` ile eşitlenir ve yalnız o işaretçi ilerletilir.
- Düğüm yapısı için iki seçenek
  - Birinci seçenek: `next` işaretçisi verinin struct'ının içine konur. Bu durumda struct anonim olamaz, ona bir ad verilir (`struct employee`), çünkü struct'ın tanımı içinde kendi türünden bir işaretçi tanımlanacaktır. Derste ve uygulamalarda bu seçenek kullanıldı.
  - İkinci seçenek: problem alanının verisi (`EMPLOYEE`) ile veri yapısının düğümü (`EMP_NODE`) ayrı struct'lardır (ekrandan, 00:20:00). Avantajı: aynı veri başka veri yapılarında (ör. hash tablosu) gereksiz bir `next` alanı taşımadan kullanılabilir. Bu seçenek öğrencilere alıştırma olarak bırakıldı.
- Bağlı liste fonksiyonları (slaytlardan ve canlı kodlamadan)
  - `printElementP`: bir çalışanın bilgilerini `emp->ID`, `emp->name`, `emp->salary` ile yazar (ekrandan, 00:25:00).
  - `printList`: `for(j=0, p=head; p != NULL; p=p->next, j++)` döngüsüyle bütün listeyi yazar. `for`'un ilk ve artırım kısımlarında virgülle ayrılmış birden fazla ifade kullanılabilir (ekrandan, 00:25:00).
  - `create_list_element`: `malloc(sizeof(EMPLOYEE))` ile yeni düğüme yer ayırır, `NULL` denetimi yapar, adı doğrudan `scanf("%s", emp->name)` ile alanın içine okur, sicil ve maaşı geçici değişkenlere okuyup alanlara atar, `emp->next=NULL` yapıp düğümü döndürür (ekrandan, 00:30:00).
  - `add_element`: liste boşsa (`head == NULL`) yeni düğüm baş düğüm olur. Değilse `for (p=head; p->next != NULL; p=p->next);` ile son düğüme gidilir ve `p->next=e;` yapılır (ekrandan, 00:35:00).
  - Silme (`delete_element`): silinecek düğüm (goner) ve ondan bir önceki düğüm `p` bulunur, `p->next = goner->next;` yapılır, sonra `free(goner)` ile düğüm bellekten silinir. Silinecek düğüm baş düğümse `head` silinen düğümün `next`'ine kaydırılır. <!-- BELİRSİZ: silme fonksiyonunun slayt kodu karelerde yok; akış altyazıdan kuruldu. -->
  - `find`: liste baştan sona dolaşılır, `strcmp(p->name, name) == 0` olan düğüm döndürülür; bulunamazsa `NULL` döner (ekrandan, 00:45:00).
  - `insert_after(p, q)`: `p` düğümünü `q`'dan sonra ekler. Önce hatalı argümanlar denetlenir: `p==NULL || q==NULL || p==q || q->next == p`. Sonra sırasıyla `p->next = q->next;` ve `q->next = p;` yapılır (ekrandan, 00:50:00).
  - `freeList`: listeyi özyinelemeli olarak siler; önce sonraki düğümler silinir, sonra düğümün kendisi (ekrandan, 01:35:00, canlı kodlama).
- Özyinelemeye (recursion) kısa giriş
  - Bir fonksiyonun kendini çağırmasına özyineleme denir. Her çağrı için yeni bir bağlam alanı oluşturulur. Durma koşulu iyi düşünülmezse bellek dolar ve program beklenmedik biçimde sonlanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bağlı listenin başı (head) "ipin ucu" gibi korunmalıdır
  - Dolaşma için ayrı işaretçi kullanılır. Demoda `insert_after`'a bile `head` doğrudan verilmedi, önce `q=head;` yapıldı.
- `add_element` döngüsünün koşulu `p->next != NULL` olmalıdır
  - Koşul `p != NULL` olursa döngü `p` `NULL` olana kadar sürer ve son düğüm kaybedilir; yeni düğüm bağlanamaz. Son düğümün `next` işaretçisinin değiştirilmesi gerekir.
- Araya eklemede atama sırası
  - Önce `p->next = q->next;`, sonra `q->next = p;`. Sıra ters olursa `q`'nun eski sonraki düğümüne (slayt örneğinde 73) giden bağlantı kaybolur.
- Her olasılık düşünülmeli
  - Liste boşken ekleme, ilk düğümü silme, aranan elemanın listede olmaması, `insert_after`'a `NULL` ya da aynı düğümün verilmesi ayrıca ele alınır. Aynı düğüm kendisinden sonra eklenirse liste dolaşılırken sonsuz döngüye girilir.
- Arama ve silme testleri baş, orta ve son düğüm için ayrı ayrı yapılmalıdır
  - Kapsamlı test böyle yapılır. Olmayan bir elemanın aranması da denenmelidir.
- Liste için toplu `malloc` gerekmez
  - Yalnız her düğüm için ayrı `malloc` yapılır. Program biterken düğümler tek tek `free` edilmelidir.

## Kısa Tekrar Notları

- `struct` farklı türdeki alanları tek türde toplar; `typedef` ile kısa ad verilir.
- Değişkende `.`, işaretçide `->` kullanılır; `p->a` ile `(*p).a` aynıdır.
- Struct içinde struct tanımlanabilir: `x.enlisted.year`.
- Struct işaretçisi bir artınca bir sonraki kayda geçer.
- Bağlı liste düğümü: veri + `next`. Son düğümde `next == NULL`.
- Kendine işaret eden struct anonim olamaz: `struct employee *next;`.
- Sona ekleme: `for (p=head; p->next != NULL; p=p->next); p->next=e;`
- Araya ekleme: `p->next = q->next; q->next = p;` (bu sırayla).
- Silme: `p->next = goner->next; free(goner);` İlk düğümse `head` kaydırılır.
- Arama: `strcmp(...) == 0`; arama büyük-küçük harfe duyarlıdır.
- Tek yönlü listeyi silmek için baştan başlanamaz; özyinelemeyle önce sonraki düğümler silinir.

## Detaylı Açıklamalar

- Derse yapıların temeliyle başlandı. Bin çalışanın adı, soyadı, sicil numarası ve maaşı dizilerle tutulursa dört ayrı dizi gerekir ve aynı kişinin verileri ancak indis eşliğiyle bağlanır. `struct` bu verileri bir araya toplar. Anonim bir struct tanımlayıp `typedef` ile ona `EMPLOYEE` adı vermek, her yerde `struct employee` yazma zahmetini kaldırır. Struct türünden bir işaretçide alanlara ok işleciyle ulaşılır; bu gösterim arka planda `(*p).alan` biçimine dönüşür, ama işaretçi aritmetiğiyle birlikte yıldız ve parantezler ifadeyi karıştırdığı için ok gösterimi tercih edilir.
- İç içe yapılarda tarih bilgisi (`short day, month; int year;`) `DATE` adlı ayrı bir struct olarak tanımlanır ve `EMPLOYEE` içinde `DATE enlisted;` alanı olarak kullanılır. Böylece işe giriş tarihi için üç ayrı alan tanımlamak yerine anlamlı bir bileşik alan elde edilir.
- Bağlı listede düğümler bellekte herhangi bir yerde oluşturulabilir; her düğüm bir sonrakinin adresini tutar. Derste kullanılan düğüm yapısında `EMPLOYEE` struct'ı ad, sicil numarası, maaş ve `struct employee *next` alanlarını içerir. Baş işaretçi `head` kolaylık için global tanımlandı; hoca daha sağlam yolun `head`'i `main` içinde tanımlayıp fonksiyonlara parametre olarak vermek olduğunu belirtti.
- `create_list_element` fonksiyonunda ad alanı struct'ın içinde dizi olarak bulunduğu için `scanf` ile doğrudan okunur. Sicil ve maaş için slayttaki yorum, bazı platformlarda işaretçi olmayan struct alanlarına doğrudan okuma yapılamadığını söyler; bu yüzden değerler önce `i` ve `s` geçici değişkenlerine okunur, sonra alanlara atanır (ekrandan, 00:30:00).
  - Ders sonrası not: Standart C'de `scanf("%d", &emp->ID);` geçerlidir ve çalışır. Geçici değişken yolu yanlış değildir, ama standart bunu zorunlu kılmaz; slayttaki uyarı büyük olasılıkla eski bir derleyici ya da platform deneyimine dayanıyor.
- Silme anlatımında slayttaki 49 → 15 → 73 → 87 → 10 listesindeki 73 düğümü silinecek düğüm (goner) olarak işaretlendi (ekrandan, 00:40:00). Dolaşma işaretçisi `p`, `p->next` goner olana kadar ilerletilir ve 15 düğümünde durur. `p->next = goner->next;` ile 15 artık 87'yi gösterir, sonra `free(goner)` ile 73 düğümü bellekten silinir. Aranan eleman listede yoksa `p` `NULL` olur; bu yüzden döngü koşulu `p != NULL` denetimiyle VE (`&&`) işleciyle birleştirilir. `p->next` zaten goner olduğu için `p->next = p->next->next;` da yazılabilir.
- Araya ekleme anlatımında yeni bir 50 düğümünün 15 düğümünden sonra eklenmesi çizildi: önce 50'nin `next`'i 15'in `next`'ine (73) eşitlenir, sonra 15'in `next`'i 50 yapılır.
- Aranan elemanı farklı alanlara göre bulmak için ayrı fonksiyonlar (`findByName`, `findById`) yazılabilir. Genel amaçlı bir `find` için fonksiyon işaretçileri kullanılabilir; bu konu sonraki derslere bırakıldı. Hoca fonksiyon işaretçisinin de "sihirli değnek" olmadığını, yine her alan için karşılaştırma fonksiyonu yazmak gerektiğini söyledi.
- Canlı kodlamada iki çalışan oluşturulup listeye eklendi, üçüncü çalışan birinci ile ikincinin arasına `insert_after` ile eklendi ve liste doğru sırayla yazdırıldı. Sonra aranacak ad için `malloc(20*sizeof(char))` ile yer ayrıldı; arama üç kez yapılarak baş, orta ve son düğüm bulundu, olmayan bir ad için "Not Found" yazdı, ilk harfi küçük yazılan ad bulunamadı (arama büyük-küçük harfe duyarlı) (ekrandan, 01:20:00). Ardından `find` ile bulunan düğüm `delete_element` ile silindi; orta, son ve ilk düğüm silmeleri ayrı ayrı denendi. `printList` ayrıca `while` döngüsüyle yeniden yazıldı.
- Son olarak listenin bütün düğümlerini bellekten silen `freeList` yazıldı. Tek yönlü listede ilk düğüm silinirse ondan sonrakilere ulaşılamaz, geriye doğru da gidilemez. Çözüm özyinelemedir: son düğüme gelinince (`n->next == NULL`) o düğüm silinir; değilse önce `freeList(n->next)` çağrılır, sonra düğümün kendisi silinir. Karede kodun `free(n)` eklenmeden önceki hali görünüyor (ekrandan, 01:35:00); hoca hemen ardından düğümün kendisinin de silinmesi gerektiğini belirtti.
- Derste anlatılan fonksiyonlar birleştirilerek kurulan tam program `gcc -Wall` ile derlendi ve üç çalışanlık bir girdiyle denendi (derste kullanılan dosyanın tamamı karelerde görünmediği için slayt ve ekran parçaları ajan tarafından birleştirildi; silme fonksiyonu altyazıdaki anlatımdan kuruldu). Ekleme, araya ekleme, arama ve silme beklenen sonuçları verdi. Program genişletilmiş notta yer alıyor.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
