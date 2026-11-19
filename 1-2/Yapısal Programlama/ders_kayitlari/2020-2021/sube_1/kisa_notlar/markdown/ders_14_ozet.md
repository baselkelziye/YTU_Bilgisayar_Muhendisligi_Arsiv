# Ders 14 Çalışma Özeti

## Genel Konular

- Yapı (struct) kavramı ve neden gerektiği
  - Dizi, aynı türden verileri bir arada tutar; ama bir varlığın farklı türden verilerini (ad, soyad, kimlik numarası, maaş) bir arada tutmak için daha iyi bir yol gerekir.
  - Yapı kullanılmazsa her alan için ayrı dizi tanımlanır ve bir çalışanın kaydı her dizinin aynı indisindeki değerlerden oluşur (ekrandan, 00:15:00): `char names[1000][20], surnames[1000][20];` ve `int IDs[1000]; float salaries[1000];`. Bu dağınık bir yapıdır; programcının aynı kişinin verilerini her dizide aynı indiste tutmayı unutmaması gerekir.
  - Yapı, birbiriyle ilişkili ama farklı türden verileri tek bir kayıt altında toplar. Bu yapı türünden bir dizi kurulunca dizinin her gözünde bir çalışan bütün verileriyle yer alır.
  - Hoca bunun bir adım ötesinin nesneye yönelik programlama olduğunu söyledi: orada varlık yalnız veriyle değil, o veri üzerinde çalışan metotlarla birlikte bir bütün olarak ele alınır.
- Yapı tanımı ve `typedef`
  - `struct Employee { ... };` biçiminde tanımlanır; kapanan süslü parantezden sonra `;` unutulmamalıdır. Bu tanımdan sonra tür adı `struct Employee` ikilisidir, yalnız `Employee` değildir.
  - `typedef` ile yapıya tek kelimelik bir tür adı verilebilir; hoca bu adı tümüyle büyük harfle (`EMPLOYEE`) yazmayı önerdi. Yapı adının ilk harfinin büyük yazılması da bir alışkanlık olarak önerildi.
  <!-- BELİRSİZ: "Structure Definition II/III" ve typedef slaytlarının karesi yok; yapı ve dizi tanımının tam yazımı ekrandan doğrulanamadı. -->
- Yapı alanlarına erişim (ekrandan, 00:20:00)
  - Yapı değişkeninde nokta: `EMPLOYEE yunus; yunus.ID = 1234;`
  - Yapı işaretçisinde ok: `EMPLOYEE *e_ptr; e_ptr->ID = 1234;`
  - Ok gösterimi `(*e_ptr).ID = 1234;` yazımının daha derli toplu biçimidir.
- İç içe yapılar
  - Bir varlığın içinde kendi başına anlamlı bir alt veri kümesi varsa yapı içinde yapı kullanılır. Örnek tarih: gün, ay, yıl ayrı bir tarih yapısında toplanır; çalışan yapısında hem işe giriş tarihi hem doğum tarihi bu türden alan olarak tutulur.
  - Erişim zincirleme noktayla yapılır: `yunus.birthday.year = 1976;` gibi.
  - Gün ve ay küçük sayılar olduğu için `short` seçildi. Hoca bellek tasarrufu daha da istenirse ileride görülecek birleşik yapı (union) ve bit alanlarıyla bunların daha az yere sığdırılabileceğini söyledi.
- Yapıları fonksiyona parametre olarak aktarma (ekrandan, 00:25:00)
  - Değerle aktarma: `printReport(emp);` Fonksiyon yapının kopyasıyla çalışır, değişiklik kalıcı olmaz.
  - Referansla aktarma: `increaseSalary(&emp);` Fonksiyon parametresi yapı işaretçisidir, alanlara `->` ile erişilir, değişiklik kalıcıdır (ör. kıdeme göre maaş artırma).
  - Referansla aktarma daha hızlı ve verimlidir. İşaretçi yapının ilk alanını değil, bütün yapıyı gösterir.
- Bağlı liste (linked list) ve dizinin yetersizlikleri (ekrandan, 00:30:00)
  - Dizi otomatik büyütülemez; en kötü duruma göre yer ayırmak bellek israfıdır. `malloc` ile daha büyük alan açıp eski verileri kopyalamak ve işaretçiyi değiştirmek ek maliyettir.
  - Diziye araya eleman eklemek ya da ortadan eleman silmek, sağdaki bütün elemanların kaydırılmasını gerektirir (eleman sayısıyla orantılı iş).
  - Bağlı liste, birbirine sucuk/sosis gibi bağlanmış yapılar zinciridir. Her düğüm (node) iki parçadan oluşur: veri ve sonraki düğümü gösteren işaretçi.
  - Düğümlerin bellekte ardışık olması gerekmez. Son düğümün `next` alanı `NULL`'dır. İlk düğüme baş düğüm (head node) denir ve mutlaka tutulmalıdır, yoksa liste kaybedilir. Son düğümü (tail) tutmak zorunlu değildir ama sona eklemeyi hızlandırır.
- Bağlı listede silme ve araya ekleme (ekrandan, 00:40:00)
  - Örnek liste: 49 → 15 → 73 → 87 → 10 → NULL.
  - 87'yi silmek için önceki düğümün (73) `next`'i, silinen düğümün `next`'ine (10) bağlanır; yalnız bir işaretçi ataması yeter.
  - 73 ile 87 arasına 76 eklemek için yeni düğüm bellekte herhangi bir yerde açılır; yeni düğüm 87'yi, 73 de yeni düğümü gösterecek şekilde bir bağ silinip iki bağ eklenir.
  - Dizinin tek büyük avantajı rastgele erişimdir (i'inci elemana doğrudan erişim). Listede i'inci elemana ulaşmak için baştan i işaretçi izlenir. Seçim, işin rastgele erişim mi yoksa ekleme/silme mi ağırlıklı olduğuna göre yapılır.
- Çalışan bağlı listesinin C ile gerçeklenmesi (ekrandan, 01:00:00 - 02:05:00)
  - Tanım: `typedef struct Employee { char name[20], surname [20]; int ID; float salary; struct Employee *next; } EMPLOYEE;` ve global `EMPLOYEE *head;` (ekrandan, 01:05:00). Baş işaretçisi global tutulduğu için her fonksiyona ayrıca aktarılmaz.
  - Tasarım tartışması: veriyi (çalışan) ve veri yapısını (liste düğümü) tek yapıda birleştirmek ikisini birbirine bağımlı kılar. Ayrı bir `Employee` yapısı ve bu türden `data` alanı ile `next` işaretçisi taşıyan ayrı bir düğüm yapısı tanımlamak daha iyi bir tasarımdır; veri yapısı (çift yönlü liste, ağaç, map) değişirse iş mantığı kısmı değişmez. Örnekte basitlik için tek yapıyla devam edildi.
  - `printElementP(EMPLOYEE *emp)`: tek bir çalışanı yazar; tutarlılık için yalnız okuma yapsa da işaretçiyle aktarılır (ekrandan, 01:15:00).
  - `printList()`: `for(j=0, p=head; p != NULL; p=p->next, j++)` döngüsüyle listeyi dolaşır. `head` hiç oynatılmaz, geçici `p` işaretçisi ilerletilir. Eleman sayısını ayrıca tutmaya gerek yoktur.
  - `create_list_element()`: `malloc(sizeof(EMPLOYEE))` ile yer ayırır, `NULL` ise "out of memory" yazıp çıkar; ad ve soyadı doğrudan `scanf("%s", emp->name)` ile, kimlik ve maaşı geçici değişken üzerinden okur; `emp->next=NULL` yapıp düğümü döndürür. Listeye ekleme yapmaz, çünkü düğüm başa, sona ya da sıralı bir yere eklenebilir (ekrandan, 01:25:00).
  - `add_element(e)`: liste boşsa (`head == NULL`) `head = e` yapıp döner; değilse gövdesi boş bir `for` ile son düğüme gidip `p->next=e;` yapar. Yeni düğümün `next`'inin oluşturulurken `NULL` yapılmış olması listenin `NULL` ile bitmesini sağlar.
  - `insert_after(p, q)`: `p` ile gösterilen yapıyı `q` ile gösterilenin hemen arkasına ekler (ekrandan, 01:50:00). `p` ya da `q` `NULL`sa, aynıysa ya da `q->next == p` ise "Bad arguments" yazıp döner. Ekleme sırası `p->next = q->next;` sonra `q->next = p;` olmalıdır; ters sırada zincir kopar.
  - `freeList()`: `p = head; while(p != NULL){ q = p->next; free(p); p = q; }` (ekrandan, 02:05:00). Silmeden önce sonraki düğüm `q`'da saklanır.
  - Demo: iki çalışan eklenip yazdırıldı, üçüncü çalışan `insert_after(p, head)` ile birinci ve ikincinin arasına eklendi ve liste doğru sırada yazıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Baş düğüm işaretçisi asla kaybedilmemeli ("ipin ucunu kaçırmamak")
  - Listeyi dolaşırken `head` değil geçici işaretçi ilerletilir; `head` kaybolursa bütün liste kaybolur.
- Nokta ve ok operatörü ayrımı
  - Yapı değişkeni üzerinden erişimde `.`, yapı işaretçisi üzerinden erişimde `->` kullanılır.
- Bağlantı güncelleme sırası
  - Araya eklemede önce yeni düğümün `next`'i doldurulur, sonra önceki düğüm yeni düğüme bağlanır. Serbest bırakmada önce sonraki düğüm saklanır, sonra `free` yapılır.
- Argüman adlarını iyi seçmek ve açıklamayı okumak
  - Hoca `insert_after(p, q)`'yu önce "q'yu p'den sonra ekler" diye okudu, açıklamayı okuyunca doğrusunun "p'yi q'dan sonra ekler" olduğunu düzeltti. Yalnız `p`, `q` gibi adlar karışıklığa yol açar.
- Veri ile veri yapısını ayırmak iyi tasarımdır
  - İş mantığı verisi, onu saklayan veri yapısından ayrı tanımlanırsa veri yapısı değiştiğinde kod daha az etkilenir.
- Veri yapıları ve algoritmalar
  - Hoca bir sonraki dönemdeki veri yapıları dersinin eğitimli bir bilgisayar mühendisini ayıran temel konulardan biri olduğunu söyledi.
- Özyineleme ve bellek
  - Listeyi boşaltmak için özyineleme kullanılabileceği önerisine karşı hoca, özyinelemenin her çağrıda ek bellek gerektirdiğini belirterek döngüyle çözmeyi tercih etti.

## Kısa Tekrar Notları

- Yapı, farklı türden ilişkili verileri tek kayıtta toplar; `}` sonrasında `;` zorunludur.
- `struct Employee` tür adıdır; `typedef ... EMPLOYEE;` ile kısaltılır.
- Değişkende `.`, işaretçide `->`; `p->ID` ile `(*p).ID` aynıdır.
- İç içe yapı: `yunus.birthday.year`.
- Yapı değerle aktarılırsa kopyalanır; değişiklik kalıcı olsun isteniyorsa adres (`&emp`) aktarılır. Referansla aktarma daha verimlidir.
- Bağlı liste düğümü: veri + `next` işaretçisi. Son düğümün `next`'i `NULL`, `head` mutlaka tutulur.
- Listede ekleme/silme birkaç işaretçi atamasıdır; dizide eleman kaydırma gerekir. Dizinin üstünlüğü rastgele erişimdir.
- Dolaşma kalıbı: `for(p=head; p != NULL; p=p->next)`.
- Sona ekleme: boş liste durumu ayrıca ele alınır; sonra `for(p=head; p->next != NULL; p=p->next);` ve `p->next=e;`.
- Araya ekleme: `p->next = q->next; q->next = p;` (sıra önemli).
- Boşaltma: `q = p->next; free(p); p = q;`
- `scanf` ile yapı alanına doğrudan okuma `&emp->ID` biçiminde yapılabilir; `&` unutulursa program çöker ya da takılır.

## Detaylı Açıklamalar

- **Yapının çözdüğü sorun.** Bin çalışanın adı, soyadı, kimlik numarası ve maaşı tutulacaksa yapı olmadan dört ayrı dizi gerekir ve bir çalışanın kaydı her dizinin aynı indisine dağılır. Yapı bu dört bilgiyi tek bir `Employee` kaydında toplar; bu türden tek bir dizi kurulunca dizinin her gözü bir çalışanın bütün verisini taşır. Hoca performans farkını bilmediğini, ama kavramsal ve veri bütünlüğü açısından yapının açıkça üstün olduğunu söyledi. Bellek kullanımını sıkılaştırmak için ileride birleşik yapılar ve bit alanları görülecektir: örneğin en fazla 3, 3 ve 2 bitlik üç sayısal alan tek bir bayta sığdırılabilir.
- **typedef ve adlandırma.** `struct Employee` yazmak yerine `typedef` ile yapıya `EMPLOYEE` adı verilir; artık `EMPLOYEE employees[1000];` gibi tanımlar yazılabilir. Hoca yapı adının ilk harfini, `typedef` ile verilen tür adının ise bütün harflerini büyük yazmayı önerdi; böylece bir adın neye karşılık geldiği ilk bakışta anlaşılır.
- **İç içe yapı.** Çalışanın hem işe giriş hem doğum tarihi tutulacaksa her biri için ayrı gün/ay/yıl alanları açmak kodu uzatır ve "bu üç sayı bir tarihtir" mantığını her yerde tekrar etmeyi gerektirir. Tarih kendi başına anlamlı bir bütün olduğu için ayrı bir yapı olarak tanımlanır ve çalışan yapısında iki alan olarak kullanılır.
- **Yapıların fonksiyona aktarılması.** Yapı doğrudan aktarılırsa değerle çağırma olur ve fonksiyonun yaptığı değişiklik yalnız kopyada kalır. Maaş artırma gibi durum değiştiren işlerde yapının adresi aktarılır ve fonksiyon içinde `->` kullanılır. Hoca bu örnekte yalnız yazdıran fonksiyonlarda da, kodun tek biçimli olması için işaretçiyle aktarmayı tercih etti.
- **Bağlı listenin mantığı.** Diziler sabit kapasitelidir; kapasiteyi artırmak için yeni alan açıp verileri taşımak gerekir, araya ekleme ve ortadan silme kaydırma ister. Bağlı listede her düğüm bir sonrakinin adresini tutar; düğümler bellekte nerede yer varsa orada açılabilir. Bir düğümü silmek önceki düğümün `next`'ini atlatmaktır; araya eklemek bir bağ silip iki bağ kurmaktır. Buna karşılık i'inci elemana erişmek için baştan i işaretçi izlenmelidir. Hoca mühendisliğin, koşullara göre bu seçenekler arasından en uygununu seçmek olduğunu vurguladı.
- **Gerçekleme ayrıntıları.** `create_list_element` yalnız düğüm üretir, yerleştirmez; böylece aynı fonksiyon sona ekleme, araya ekleme ya da sıralı ekleme için kullanılabilir. `add_element` boş listede yeni düğümü `head` yapar; aksi halde son düğümü bulup ona bağlar. `insert_after` hatalı argümanlara karşı korunur: `q->next == p` durumu, `p` zaten `q`'nun ardındayken yeniden eklenip `p->next = q->next` ile kendini gösterecek bir döngü kurulmasını engeller. Ders sonunda bir öğrencinin sorusu üzerine `freeList` yazıldı ve çalıştırıldı.
- **Derste denenen `scanf` ayrıntısı.** Ders notundaki kodda "yapının işaretçi olmayan alanlarına doğrudan okunamaz" yorumu vardı ve kimlik ile maaş geçici değişkenden aktarılıyordu. Derste önce `&` olmadan denenince program takıldı; bir öğrencinin önerisiyle `&` eklenince doğrudan okuma çalıştı ve hoca öğrencinin haklı olduğunu kabul etti. Ad alanında `&` gerekmemesinin nedeni `name`'in bir dizi olması ve dizi adının çoğu yerde ilk elemanın adresi gibi davranmasıdır.
  - Ders sonrası not: Ders notundaki "cannot get non-pointer struct fields directly!" yorumu doğru değildir; `scanf("%d", &emp->ID);` ve `scanf("%f", &emp->salary);` standart C'dir. Bu sürüm de `gcc -Wall` ile uyarısız derlendi ve doğru çalıştı.
- **Derlenen tam program.** Ekrandaki parçalardan (01:05:00 - 02:05:00) birleştirilen tam program genişletilmiş notta verilmiştir; `gcc -Wall` ile uyarısız derlendi ve üç çalışanlık girdiyle denendi (Windows'a özgü `system("PAUSE")` çıkarıldı). `add_element` gövdesinin tamamı ekranda görülmedi, anlatımdan kuruldu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
