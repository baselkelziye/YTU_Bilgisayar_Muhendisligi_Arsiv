# Ders 14 Genişletilmiş Notu: Yapılar (struct) ve Bağlı Liste Gerçeklemesi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bölümün Planı
- 2. Yapı Neden Gerekir?
- 3. Yapı Tanımı ve typedef
- 4. Yapı Alanlarına Erişim
- 5. İç İçe Yapılar
- 6. Yapıları Fonksiyona Parametre Olarak Aktarma
- 7. Dizinin Yetersizlikleri ve Bağlı Liste
- 8. Bağlı Listede Silme ve Araya Ekleme
- 9. Çalışan Listesinin Tanımı
- 10. Listeyi Yazdırmak
- 11. Yeni Düğüm Oluşturmak
- 12. Listenin Sonuna Eklemek
- 13. scanf ile Yapı Alanına Doğrudan Okuma Denemesi
- 14. Araya Eleman Eklemek: insert_after
- 15. Listeyi Boşaltmak: freeList
- 16. Derlenmiş Tam Program
- Örnek Sorular
- Dersin Toparlaması

## 1. Bölümün Planı

Ders, ders notlarının "Structures, Unions, Enums" bölümüyle başladı (ekrandan, 00:05:00, slayt 174). Bölümün ana başlıkları şunlardır: yapı tanımı, iç içe yapılar, yapı dizileri, yapıların fonksiyona parametre olarak aktarılması, bir örnek olarak bağlı liste gerçeklemesi, birleşik yapı (union) tanımı ve birleşik yapıların fonksiyona aktarılması. Hoca bölüm başlığında geçen numaralandırma (enum) konusunun önceki haftalarda görüldüğünü, burada ek bir şey söylenmeyeceğini belirtti.

Birleşik yapılarda belleğin verimli kullanımına yönelik bir konu, bit alanı (bit field) türünden alanların tanımlanması görülecektir. Birleşik yapılar yapılara benzer, ama belleği daha verimli kullanmaya yönelik bazı farkları vardır ve biraz daha karmaşık yorumlanırlar. Bu derste yapılar ve bağlı liste örneği işlendi; birleşik yapılar sonraya kaldı.

## 2. Yapı Neden Gerekir?

Hoca konuya program yazmanın amacından girdi. Program, gerçek dünyadaki bir problemi çözmek ya da izlenmesi zor bir işi kolaylaştırmak için yazılır. Problem koda aktarılırken problemin parçası olan varlıklar da koda aktarılır. Her varlık, kendi içinde farklı verilerin bir araya gelmesinden oluşabilir. Bir çalışanın yalnız adı değil, soyadı, işe giriş tarihi, maaşı, maaşını hesaplamak için derecesi ve kademesi, akademik unvanı da tutulur. Bunların bazıları aynı türden olsa da aralarında farklı türler vardır ve hepsi aynı çalışana aittir.

Buna en yakın daha önce görülen kavram dizidir. Dizi de birbiriyle ilişkili verileri bir arada tutar, ama bunlar farklı varlıkların aynı türden verileridir: örneğin bir dersin bir şubesindeki notlar listesinde her eleman farklı bir öğrenciye aittir. Bir öğrenci bilgi sistemi kurulacaksa ise bir öğrenci numarası, giriş yılı, bölümü, aldığı dersler ve notları gibi farklı türden verilerle ifade edilir.

Slayttaki örnek (ekrandan, 00:15:00): bir çalışanın kaydı için adı ve soyadı katar, kimlik numarası tam sayı, maaşı `float` olarak tutulmalıdır. Dizilerde ısrar edilirse birden çok tek boyutlu dizi gerekir. Bin çalışan izlenecekse:

```c
char names[1000][20], surnames[1000][20];
int  IDs[1000]; float salaries[1000];
```

Bu durumda bir çalışanın kaydı, her dizinin aynı indisindeki değerlerin bütünüdür: sıfırıncı indisteki dört veri bir kişinin, birinci indistekiler başka bir kişinin kaydını oluşturur. Bu dağınık bir düzendir ve programcının aynı kişinin verilerini farklı dizilerde aynı indiste tutmayı unutmaması gerekir.

Bunun yerine bir çalışan (ya da öğrenci) yapısı tanımlanır, ilgili bütün veriler orada tutulur ve bu yapı türünden bir dizi kurulur. Dizinin her gözünde tek bir varlık bütün verileriyle birlikte yer alır. Hoca bunun bir adım ötesinin nesneye yönelik programlama olduğunu, orada varlıkların yalnız veri olarak değil, fonksiyonlarla (metotlarla) birlikte bir bütün olarak ele alınacağını söyledi.

**Soru:** Performans açısından yapı ile ayrı diziler arasında ne kadar fark vardır? **Cevap:** Hoca performans farkını bilmediğini, ama kavramsal ve anlamsal açıdan, veri bütünlüğü açısından yapının ayrık dizilere göre açıkça üstün olduğunu söyledi. Birleşik yapılarla bir kaydın belleği daha sıkı kullanılabilecektir: örneğin değerleri en fazla 3 bit, 3 bit ve 2 bitlik aralıkta olan üç sayısal alan tek bir bayt içinde toplanabilir. Bu, ayrı bir `int` dizisini işlemekten kavramsal olarak daha kolaydır.

## 3. Yapı Tanımı ve typedef

Yapı `struct` anahtar kelimesiyle tanımlanır ve bir ad verilir; çalışanlar için `Employee`. Hoca yapı adının ilk harfini büyük yazmayı bir alışkanlık hâline getirmeyi önerdi; bu, adın bir yapıya ait olduğunu gösterir. Süslü parantezler içinde yapının alanları yazılır: en fazla 20 karakterlik ad, en fazla 20 karakterlik soyad, kimlik numarası ve ücret. Kapanan süslü parantezden sonra `;` konmalıdır; derleyici bunu ister.

Bu tanımdan sonra yeni bir kayıt türü oluşmuştur. Dikkat edilecek nokta, tür adının yalnız `Employee` değil, `struct Employee` ikilisi olmasıdır. Bu türden bir dizi kurulurken, `int notlar[1000];` yazar gibi, `struct Employee employees[1000];` yazılır.

Her yerde `struct Employee` yazmak yerine `typedef` kullanılabilir. `typedef` bir tür tanımlama komutudur. Bir yapı az önceki gibi tanımlanır; bu durumda yapının kendi adı olmayabilir, önemi yoktur, çünkü `typedef` ile ona `EMPLOYEE` adı verilir. Artık veri türü `EMPLOYEE`'dir ve dizi `EMPLOYEE employees[1000];` diye kurulur. Hoca `typedef` ile verilen tür adını bütün harfleri büyük yazmayı önerdi; böylece bir adın neye karşılık geldiği ilk bakışta anlaşılır.

<!-- BELİRSİZ: Bu bölümün slaytlarının (Structure Definition II-III, 00:14:31 - 00:19:20) karesi yok; struct ve typedef tanımlarının ekrandaki tam yazımı doğrulanamadı. Anlatım altyazıdan kuruldu. -->

## 4. Yapı Alanlarına Erişim

Yapının tek tek alanlarına nokta ya da ok gösterimiyle erişilir (ekrandan, 00:20:00). Hangisinin kullanılacağı, kayda normal bir değişken üzerinden mi yoksa bir işaretçi üzerinden mi erişildiğine bağlıdır.

```c
EMPLOYEE yunus;
yunus.ID = 1234;

EMPLOYEE *e_ptr;
e_ptr->ID = 1234;

(*e_ptr).ID = 1234;
```

Yapı değişkeninde alanlara nokta ile erişilir. Yapı işaretçisinde eksi ve büyüktür işaretinden oluşan iki karakterli ok (`->`) kullanılır. Ok gösterimi aslında `(*e_ptr).ID` yazımının daha derli toplu biçimidir: önce işaretçinin gösterdiği yapıya parantez içinde `*` ile ulaşılır, sonra nokta konur. Bu da yazılabilir ama daha zahmetlidir. Kural: işaretçi tanımlandıysa ok, tanımlanmadıysa nokta.

## 5. İç İçe Yapılar

Bir varlığın kendi içinde ayrı bir bütünlük oluşturan bir alt veri kümesi varsa yapı içinde yapı tanımlanabilir. Tarih buna güzel bir örnektir. Çalışanın işe giriş tarihi doğrudan çalışan yapısına gün, ay ve yıl olarak üç `int` alan eklenerek de tutulabilirdi. Ama hem işe giriş hem doğum tarihi tutulacaksa yapı uzar ve her yerde "bu üç sayıyı tarih olarak yorumla" diyen kopyala-yapıştır kodu ortaya çıkar. Gün, ay ve yıl kendi içinde anlamlı bir tarih verisi oluşturduğu için ayrı bir yapı olarak tanımlanmaları mantıklıdır.

Hoca tarih yapısında gün ve ay küçük sayılar olduğu için `short` kullandı. Yılın alabileceği değerler üzerine konuşurken birleşik yapılarla bu alanların daha az yere sığdırılabileceğine değindi, ama bu kadar küçük bir bellek iyileştirmesine gerek olmasa bile, kavramsal olarak bu üç verinin bir tarih oluşturması ayrı bir yapı tanımlamayı haklı kılar. Çalışan yapısında bu türden işe giriş tarihi ve doğum tarihi (`birthday`) alanları tanımlanır. Erişim zincirleme noktayla yapılır:

```c
yunus.birthday.year = 1976;
```

İşe giriş tarihinin yılına da aynı biçimde `yunus.<işe giriş alanı>.year` ile erişilir.

<!-- BELİRSİZ: İç içe yapı slaytının karesi yok (00:21:24 - 00:24:20); tarih yapısının ve işe giriş tarihi alanının adı ("hireDate" benzeri) altyazıdan okunamadı. -->

## 6. Yapıları Fonksiyona Parametre Olarak Aktarma

Kayıt yapıları ister istemez farklı fonksiyonlara aktarılacaktır. Slayttaki iki yol (ekrandan, 00:25:00):

```c
EMPLOYEE emp;
printReport(emp);      /* yapının kendisi: değerle aktarma */

EMPLOYEE emp;
increaseSalary(&emp);  /* yapıya işaretçi: referansla aktarma */
```

Yapının kendisi aktarılırsa değerle çağırma (call by value) olur; fonksiyonun yapıda yaptığı değişikliklerin ömrü o fonksiyonla sınırlı kalır. Oysa çoğu zaman yapının bir ya da birkaç alanının fonksiyon içinde değiştirilmesi ve bu değişikliğin kalıcı olması gerekir. Örneğin belli bir yıldan fazla hizmeti olan çalışanların maaşı diğerlerinden daha fazla artırılacaksa çalışan nesnesinin durumu, yani bir alanının değeri değişir ve bu değişiklik kalıcı olmalıdır. Bu durumda yapının adresi aktarılır, fonksiyon parametresi yapı işaretçisi olarak tanımlanır ve maaş alanına ok operatörüyle erişilir.

Slayttaki diğer maddeler şunlardır: referansla aktarma daha hızlı ve daha verimlidir; tercihe göre fonksiyon argümanı ya yapı ya da yapı işaretçisi olarak bildirilir ve gövdede buna göre `.` ya da `->` kullanılır; işaretçi yapının ilk alanını değil bütün yapıyı gösterir, bu yüzden fonksiyon içinde her alana rahatça erişilir. Yapı değiştirilmeden kullanılacaksa değerle de gönderilebilir, ama genelde referansla göndermek gerekir.

## 7. Dizinin Yetersizlikleri ve Bağlı Liste

Yapının kullanımını göstermek için bağlı liste (linked list) örneği seçildi. Hoca bir sonraki dönem alınacak veri yapıları dersinin, eğitimli bir bilgisayar mühendisini kendini sonradan bu mesleğe yetiştirmiş kişilerden ayıran önemli konulardan biri olduğunu söyledi ve algoritmalar ile veri yapılarına ağırlık verilmesini tavsiye etti.

Sınıf ile yapı arasındaki farka da kısaca değinildi. Nesneye yönelik programlamada sınıf, nesneleri kodlamaya yarayan bir şablondur; nesnenin verisi ve o veri üzerinde çalışan fonksiyonları (metotları) bölünemez bir bütündür. Yapıyla yapılan bağlı liste örneğinde ise veri ayrı, o veri üzerinde çalışan fonksiyonlar ayrıdır. Hoca bunu kendi üzerinden anlattı: gerçek dünyadaki bir varlık, verileri ve yaptığı eylemlerle bir bütündür.

Dizilerin yetersiz ya da verimsiz kaldığı birçok durum vardır (ekrandan, 00:30:00):

- Dizi otomatik olarak yeniden boyutlandırılamaz; en kötü duruma göre yer ayırmak bellek israfıdır. Kullanıcıdan eleman sayısını alıp o boyutta dizi tanımlanamadığı için `malloc` görülmüştü. `malloc` ile bu sorun aşılsa bile kapasite sonradan artırılacaksa (örneğin bölüme yıllık alınan öğrenci sayısı 60'tan 100'e çıkarsa) daha geniş yeni bir alan açılmalı, eski alandaki her şey yeni alana kopyalanmalı ve işaretçi değiştirilmelidir. Bunların her biri ayrı bir maliyettir.
- Araya ekleme zordur, elemanların kaydırılması gerekir. Ortadan bir eleman silinecekse (bir öğrenci dersi bırakır, bir çalışan işten ayrılır) o eleman yalnızca boşaltılamaz; sağındaki bütün elemanlar bir sola kaydırılmalıdır. Bu, eleman sayısıyla doğru orantılı iş demektir.

Daha verimli bir veri yapısı bağlı listedir. Slayttaki tanıma göre bağlı liste, birbirine sucuk gibi bağlanmış yapılar zinciridir; en basit biçiminde her yapı, listede bir sonraki yapıyı gösteren ek bir işaretçi alanı içerir.

Slayttaki örnek liste tam sayı tutar (ekrandan, 00:40:00): 49 → 15 → 73 → 87 → 10. Beş düğüm vardır. Her düğüm iki parçadan oluşur: veri elemanı ve sonraki düğümün bellekteki yerini gösteren işaretçi. Düğümlerin bellekte peş peşe olması gerekmez: biri 1000 adresinde, sonraki 2010 adresinde olabilir. Bellekte nerede yer varsa yeni düğüm oraya konabilir, ardışık bellek alanına gerek yoktur.

Listenin sonu, son düğümün sonraki işaretçisine `NULL` konarak işaretlenir. İlk düğümün özel bir adı vardır: baş düğüm (head node). Baş düğüm mutlaka tutulmalıdır, ipin ucu oradadır; tutulmazsa veri kaybedilir. Son düğüme (tail node) bir işaretçi tutmak zorunlu değildir, ama liste çok uzunsa sona eleman eklemek için n işaretçi izlemek yerine tek adımda sona ulaşmayı sağlar.

**Soru:** Düğüm dediğimiz şey ve elemanları birbirine bağlayan şey bir bit ya da bayt değeri mi? **Cevap:** İkisine birlikte düğüm denir. Düğüm bir yapıdır: bir veri alanı ve kendi türünden başka bir elemanı gösteren `next` işaretçisi vardır. Bu işaretçi her düğümde ayrı ayrı bulunur ve düğümleri birbirine bağlayan odur. Bellekte kaç bayt tuttuğu ise ayrı bir konudur.

> **Hocanın vurgusu:** Bu yapıları doğru anlamak çok önemlidir; anlaşılmayan yer varsa soru sorulmalıdır.

## 8. Bağlı Listede Silme ve Araya Ekleme

**Silme.** Örnek listede 87'li düğüm silinecekse yapılacak tek şey, bir önceki düğümün (73) `next` işaretçisini silinecek düğümün `next`'ine, yani 10'lu düğüme yönlendirmektir. Artık 87'li düğümü gösteren işaretçi yoktur; o bellek alanı başka amaçlarla kullanılabilir. Dizide ise sağdaki bütün elemanlar sola kaydırılacaktı; burada tek bir işaretçi ataması yeter.

**Araya ekleme.** Dizilerde en zor işlerden biridir: önce kapasite artırılmalı, sonra ekleme konumundaki ve sonraki bütün elemanlar sondan başlayarak sağa kaydırılmalıdır. Bağlı listede 73 ile 87 arasına 76 eklemek için bellekte herhangi bir yerde yeni bir düğüm açılır ve içine 76 yazılır (ekrandan, 00:40:00; tahtada yeşil kutu). 73'ün işaretçisi artık 87'yi değil yeni düğümü, yeni düğümün işaretçisi de 87'yi gösterir. Mevcut elemanlara dokunulmadan bir bağ silinip iki bağ eklenmiş olur.

**Dizinin üstünlüğü.** Dizinin en büyük avantajı rastgele erişimdir (random access): i'inci elemana doğrudan erişilir. Listede dördüncü elemana ulaşmak için baş düğümden başlayarak dört işaretçi izlenir; milyon elemanlı bir listede ortalardaki bir elemana ulaşmak için yüzlerce, binlerce adres izlemek gerekir. Hoca mühendisliğin, bir problemi çözmenin farklı yollarını bilip eldeki koşullara en uygununu seçmek olduğunu söyledi: sürekli rastgele erişim gerekiyorsa dizi, ekleme ve silme ağırlıklıysa ve bellek verimi önemliyse liste seçilir.

## 9. Çalışan Listesinin Tanımı

Aradan sonra C ile gerçeklemeye geçildi. Hoca örneği tek bir tam sayı tutan düğüm yerine çalışan kaydı üzerinden yürüttü; tek bir değer alanı ile birden çok alan arasında karmaşıklık açısından çok küçük bir fark vardır ve kayıt yapısı örneği daha anlamlıdır. Burada kayıt yapısı (çalışan) ile veri yapısı (bağlı liste) ayrı kavramlardır: çalışan kayıtları bir bağlı liste veri yapısında tutulacaktır.

Slayta göre çalışan yapısı hem veri elemanı hem düğüm olarak kullanılacaktır; avantajı işleri biraz basit tutmasıdır (ekrandan, 01:00:00). IDE'deki tanım (ekrandan, 01:05:00):

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Employee {
    char name[20], surname [20];
    int  ID;
    float salary;
    struct Employee *next;
} EMPLOYEE;
EMPLOYEE *head;
```

Önceki örnekteki alanlara (ad, soyad, kimlik numarası, maaş) ek olarak, veri bir liste yapısında tutulacağı için listedeki bir sonraki çalışanı gösteren `next` işaretçisi eklendi. Yapı tanımlanırken henüz `typedef` adı oluşmadığı için bu alan `struct Employee *` türündendir. Artık `EMPLOYEE` yazılarak, yıldızlı tanımlanırsa işaretçi, düz tanımlanırsa değişken oluşturulur.

Listenin ilk düğümü her zaman tutulmalıdır. `head` global değişken olarak tanımlandı. Yalnız `main` içinde tanımlansaydı, çalışanlarla ilgili iş yapan her fonksiyona listenin başı ayrıca gönderilmek zorunda kalınacaktı.

**Soru:** `EMPLOYEE *head;` satırı, Employee içinde global bir head tut anlamına mı gelir? **Cevap:** Hayır. Yapı tanımı `} EMPLOYEE;` ile bitmiştir. Bu satır, çalışan listesinin ucunu gösteren `EMPLOYEE` türünden bir işaretçiyi global değişken olarak tanımlar; `main` ve diğer bütün fonksiyonlar ona erişebilir.

### 9.1 Tasarım tartışması: veriyi veri yapısından ayırmak

Hoca bu tanımın bir alternatifinden söz etti. Bu biçimde veri (çalışan) ile seçilen veri yapısı (bağlı liste) tek bir tanımda birbirine bağımlı hâle gelir. İleride çalışanlar bağlı liste yerine, örneğin kimlik numarasının anahtar olduğu bir map yapısında tutulmak istenirse tanımın değişmesi gerekir. İyi bir tasarım, gerçek dünyadaki problemin ve koda aktarırken eklenen sorumlulukların hangi düzeyde bölünebiliyorsa o düzeyde bölünmüş olandır. Bu yüzden iş mantığını oluşturan veriyi, onu tutan veri yapısından ayırmak daha doğru olabilir.

Bunun için iki ayrı yapı tanımlanır. Birincisi yalnız çalışanla ilgili verileri (ad, soyad, kimlik numarası, maaş) içeren `Employee` yapısıdır ve buna `typedef` ile bir ad verilir. İkincisi bağlı liste düğümüdür: içinde `Employee` türünden bir `data` alanı ve kendi türünden sonraki düğümü gösteren işaretçi bulunur. Global olarak tutulan baş işaretçisi de bu düğüm türünden olur. Böylece veri yapısı çift yönlü bağlı listeye, ağaca ya da map yapısına taşınsa bile temel iş mantığıyla ilgili kısım değişmez; yalnız saklama biçimiyle ilgili kısımlar değişir. Hoca bu biçimi düşünülmek üzere bıraktı ve örneğe ilk tanımla, her çalışanın aynı zamanda bir düğüm olduğu biçimde devam etti.

<!-- BELİRSİZ: İki yapılı tanımın gösterildiği slaytın karesi yok (01:05:13 - 01:08:17); alan ve tür adları ekrandan doğrulanamadı. -->

## 10. Listeyi Yazdırmak

Önce tek bir elemanı yazan fonksiyon, sonra bundan yararlanarak bütün listeyi dolaşıp yazan fonksiyon hazırlandı (ekrandan, 01:15:00):

```c
void printElementP( EMPLOYEE *emp ) {
    printf("Employee %d %s %s has a salary of %f\n",
        emp->ID, emp->name, emp->surname, emp->salary );
}
void printList( ) {
    int j; EMPLOYEE *p;
    for(j=0, p=head; p != NULL; p=p->next, j++)
        printf("%d-th person: %d\t%s\t%s\t%f\n",
            j+1, p->ID, p->name, p->surname, p->salary);
}
```

`printElementP` yalnız okuma yaptığı için değerle çağrılabilirdi; hoca kodun tek biçimli (uniform) olması için burada da referansla aktarmayı tercih etti. Parametre işaretçi olduğu için alanlara ok ile erişilir. İlk sürümde soyad yoktu; bir `%s` ve `emp->surname` eklenerek soyad da yazdırıldı.

`printList`'te birinci, ikinci çalışan diye sıra numarası yazılmak istendiği için `for` kullanıldı; `while` ile de yazılabilirdi. Döngünün her adımında sonraki düğüme ilerlemek gerekir ve bu `for`'un üçüncü bileşeninde yapıldı. Başlangıçta `j = 0` ve geçici `p` işaretçisi `head`'i gösterir. Geçici `p`'ye ihtiyaç vardır: yalnız `head` ilerletilseydi listenin başı kaybolurdu. Listenin ilk düğümünü gösteren işaretçi hep sabit kalmalıdır ("ipin ucunu kaçırmamak"); gereken her fonksiyonda ayrı bir geçici işaretçi tanımlanır ve o istenildiği gibi oynatılır.

Bitiş koşulu `j` üzerinden verilemez, çünkü eleman sayısı bilinmez; esneklik de bunu gerektirir. Eleman eklenip silinebilir; sırf bunun için ayrı bir eleman sayısı değişkeni tutmaya gerek yoktur. Döngü, gidilecek düğüm kalmayınca, yani `p` `NULL` olunca biter. Son düğümün `next`'i `NULL` olduğu için son düğüm yazıldıktan sonraki adımda `p` `NULL` olur ve döngüden çıkılır. Bütün işi `for` başlığı yaptığı için gövde basit kalır.

Hoca önce `printList`'in `printElementP`'yi kullandığını söyledi, sonra bunun yanlış olduğunu düzeltti: `printList` hem dolaşıyor hem de düğüm bilgilerini kendisi yazıyor; `printElementP` istenen bir elemanı yazmak için başka yerlerde kullanılıyor.

**Soru:** `for` döngüsündeki `p->next`'teki `next` bizim tanımladığımız bir şey değil mi? **Cevap:** Evet, bizim tanımladığımız alandır. Veri yapısını, düğümü (yapıyı) ve sonraki işaretçisini kendimiz kurup yönetiyoruz; adını `next` koyduk, istenirse `sonraki` da denebilirdi.

## 11. Yeni Düğüm Oluşturmak

Listedeki her eleman için gerektikçe bellek ayırmak, yeni çalışanın değerlerini okumak ve düğümü listeye bağlamak tamamen programcının sorumluluğundadır. Önce bir çalışanın bütün bilgilerini alan, onun için bellekte yer ayıran ve düğümü döndüren fonksiyon yazıldı (ekrandan, 01:20:00 ve 01:25:00):

```c
EMPLOYEE* create_list_element(  ) {
    EMPLOYEE *emp; int i; float s;
    emp = (EMPLOYEE*) malloc( sizeof( EMPLOYEE ) );
    if( emp == NULL ) {
        printf("create_employee: out of memory."); exit(1);
    }
    printf("Enter name of the person: "); scanf("%s", emp->name);
    printf("Enter surname of the person: "); scanf("%s", emp->surname);
    //cannot get non-pointer struct fields directly!
    printf("Enter ID of the person: ");
    scanf("%d", &i); emp->ID = i;
    printf("Enter salary of the person: ");
    scanf("%f", &s); emp->salary = s;
    emp->next=NULL; return emp;
}
```

Dinamik bellek yönetimi yapıldığı için fonksiyon `EMPLOYEE` türünden bir işaretçi döndürür. Yeni çalışan için geçici bir işaretçi, kimlik numarası ve maaş için de geçici değişkenler tanımlandı; ad ve soyad için `scanf` doğrudan yeterlidir. Tek bir eleman için yer ayrıldığından `calloc`'a gerek yoktur, içeriğin sıfırlanmasına da gerek yoktur; `malloc` yeterlidir. Ayrılacak miktar `sizeof(EMPLOYEE)` ile bulunur ve `malloc`'un döndürdüğü `void *` `EMPLOYEE *`'a dönüştürülür. Yer ayrılamazsa bellek yetersizliği yazılıp programdan çıkılır. İlk sürümde soyad sorulmuyordu, derste eklendi.

Ad alanında `&` gerekmez, çünkü `name` bir dizidir ve dizinin adı çoğu yerde ilk elemanının adresi gibi davranır. Ders notundaki yoruma göre ise kimlik numarası ve maaş gibi işaretçi olmayan ilkel alanlara doğrudan okunamaz, önce geçici değişkene okunup sonra alana aktarılmalıdır. Bu iddia derste denendi (Bölüm 13).

Yeni düğüm listenin sonuna eklenecekse sonrası yoktur, bu yüzden `next` `NULL` yapılır ve düğüm döndürülür. Fonksiyon düğümü listeye eklemez. Bunun nedeni, düğümün her zaman sona eklenmeyebilecek olmasıdır: liste maaşa göre sıralı tutuluyorsa ortaya, istenirse başa eklenebilir. Bu yüzden fonksiyon yalnız düğümü oluşturur, değerleri yazar ve döndürür; adı da buna göre `create_list_element`'tir.

## 12. Listenin Sonuna Eklemek

Ekleme işi ayrı bir fonksiyona, `add_element`'e verildi. Son düğüm işaretçisi tutulmadığı için sona ulaşmak üzere baştan dolaşan bir geçici işaretçi gerekir. Hoca her olasılığın düşünülmesi gerektiğini vurguladı: henüz kimse işe alınmamışsa liste boştur ve eklenen eleman listenin ilk elemanı olur. Başlangıçta `head` `NULL`'dır; bu durumda `head = e;` yapılıp fonksiyondan dönülür.

Aksi hâlde baştan başlanır ve bakılan düğümün `next`'i `NULL` olmadığı sürece `p = p->next` ile ilerlenir. Gövdeye başka bir şey yazmaya gerek yoktur; `for` yalnız `;` ile kapatılır. Döngü bitince `p` son düğümü gösterir ve son düğümün `next`'ine yeni düğüm bağlanır. Ekrandan görülen son kısım (ekrandan, 01:50:00):

```c
    // append a new structure to the end of the list
    p->next=e;
}
```

Anlatıma göre fonksiyonun tamamı şöyledir:

```c
void add_element( EMPLOYEE *e ) {
    EMPLOYEE *p;
    if( head == NULL ) {
        head = e;
        return;
    }
    for( p = head; p->next != NULL; p = p->next )
        ;
    // append a new structure to the end of the list
    p->next=e;
}
```

<!-- BELİRSİZ: add_element'in baş kısmı ekranda görülmedi; yukarıdaki gövde altyazıdaki anlatımdan (01:26:29 - 01:29:39) kuruldu. -->

Yeni düğüm oluşturulurken `next`'i `NULL` yapılmasaydı bunun burada yapılması gerekecekti. Hoca listenin `NULL` ile bitmesinin (null terminated) önemli olduğunu vurguladı.

Listeden çalışan çıkarmak (işten çıkarmak) için ders notunda bir `delete_element` fonksiyonu da vardır (ekrandan, 01:30:00). Hoca bu slaytı açtı ama "önce eleman ekleyip listeleyelim" diyerek üzerinde durmadı; slayttaki kod şudur:

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

> **Ders sonrası not:** Slayttaki bu kod derste anlatılmadı ve yazıldığı biçimiyle hatalıdır. `else`'ten sonra süslü parantez olmadığı için yalnız `for` satırı `else`'e bağlıdır. Bu yüzden `goner == head` olduğunda da `if(p == NULL)` denetimi ve `p->next=p->next->next;` satırı çalışır ve `p` ilk değer verilmemiş olarak kullanılır. Doğrusu büyük olasılıkla `else { for(...); if(p == NULL){...; return;} p->next=p->next->next; }` ve ardından `free(goner);` biçimindedir.

## 13. scanf ile Yapı Alanına Doğrudan Okuma Denemesi

**Soru:** Kimlik numarası neden doğrudan `scanf` ile alınamıyor, nedenini tekrar anlatır mısınız? **Cevap:** Hoca önce C standardının buna izin vermediğini, ders notunu hazırlarken bunun üzerinde özellikle durulduğunu söyledi ve ad alanındaki gibi doğrudan okuma denedi. Kod derleyici hatası vermedi; hoca çalışma anında sorun çıkabileceğini, önce bütün kodu tamamlayıp sonra bu varyasyonlara döneceklerini söyledi.

Liste tamamlanıp demo yapıldıktan sonra hoca bu konuya döndü. Kimlik numarası doğrudan alan adına verilerek çalıştırıldığında program kimlik numarası girildikten sonra takıldı, hata da vermedi. Bir öğrenci başına `&` konmasını önerdi; `scanf("%d", &emp->ID);` biçiminde program doğru çalıştı. Hoca bir denemede maaşa yanlışlıkla sayı yerine metin girdi (ekrandan, 01:40:00), sonra doğru değerle tekrar çalıştırdı ve öğrencinin haklı olduğunu kabul etti.

> **Ders sonrası not:** Ders notundaki "cannot get non-pointer struct fields directly!" yorumu doğru değildir. `&emp->ID`, `emp->ID` alanının adresidir (`->` işleci `&`'den önce uygulanır), dolayısıyla `scanf("%d", &emp->ID);` ve `scanf("%f", &emp->salary);` standart C'dir. Takılmanın nedeni `&`'in unutulmasıdır: o durumda `scanf`'e alanın değeri adres gibi verilir ve tanımsız davranış oluşur. `&` ile doğrudan okuyan sürüm de `gcc -Wall` ile uyarısız derlendi ve aynı çıktıyı verdi.

## 14. Araya Eleman Eklemek: insert_after

`add_element` yalnız sona ekler. İki eleman arasına ekleme için ders notundaki `insert_after` fonksiyonu kullanıldı. Tek yönlü bağlı listede bir `p` ile bir `r` düğümü arasına eleman eklemek için önceki düğümün bilinmesi yeterlidir, çünkü yalnız `next` işaretçisi vardır.

Hoca karşılaştırma için çift yönlü bağlı listeyi (doubly linked list) de anlattı. Çift yönlü listede düğüm yapısına bir alan daha, önceki düğümü gösteren işaretçi eklenir; baş düğümün önceki işaretçisi boştur. Bu durumda araya ekleme yapılırken sonraki düğümün de bilinmesi gerekir: yeni düğümün önceki ve sonraki işaretçileri, önceki düğümün sonraki işaretçisi ve sonraki düğümün önceki işaretçisi güncellenir; yani daha çok bağ kurulur.

IDE'deki fonksiyon (ekrandan, 01:50:00):

```c
/* To insert an element in a linked list, you must specify
   where you want the new element inserted.
   The following function accepts 2 pointer arguments, p and q,
   and inserts the structure pointed by p,
   just after the structure pointed by q. */
void insert_after(EMPLOYEE *p, EMPLOYEE *q){
    // if p and q are same or NULL, or if p already follows q, report that:
    if(p==NULL || q==NULL || p==q || q->next == p){
       printf("insert_after(): Bad arguments \n");
       return;
    }
    p->next = q->next;
    q->next = p;
}
```

Önce hatalara karşı denetim yapılır: `p` ile `q` aynı düğüm olmamalı ve ikisinden hiçbiri `NULL` olmamalıdır. Ayrıca `p` zaten `q`'nun hemen ardındaysa ekleme yapılmamalıdır. Hoca bu denetimlerin aşırı dikkat gibi görünse de, dikkat edilmezse bütün listenin kopmasına ve kaybedilmesine yol açabilecek durumları engellediğini söyledi. Listede hiç eleman yoksa bu fonksiyon zaten çağrılamaz, çünkü "şu elemandan sonra ekle" diyecek bir eleman yoktur.

> **Ders sonrası not:** Hoca son denetimi anlatırken `q`'nun `next`'inin `p` olması durumunda yalnız `p` ile `q`'nun birbirini gösterip listenin koparacağını söyledi. Aslında bu durumda `p->next = q->next;` satırı `p->next = p` yapar; yani `p` kendini gösterir ve `p`'den sonraki bütün düğümler kaybedilir. Sonuç aynıdır: liste bozulur.

**Argümanların anlamı.** Hoca fonksiyonu önce "`q`'yu `p`'den sonra ekler" diye okudu, sonra açıklamayı okuyunca doğrusunun "`p`'nin gösterdiği yapıyı `q`'nun gösterdiğinin hemen ardına ekler" olduğunu düzeltti. Argümanlara iyi ad vermek gerektiğini, yalnız `p`, `q` denirse ve açıklama okunmazsa yanılmanın kolay olduğunu vurguladı.

**Atama sırası.** Hoca slayttaki listede yeni düğümü 73'ten sonraya eklemeyi çizerek gösterdi (ekrandan, 01:55:00): `q` 73'lü düğümü, `p` 76'lı yeni düğümü gösterir. Yeni düğüm oluşturulurken `next`'i `NULL` yapılmıştı. Hemen `q->next = p;` denirse 73 ile 87 arasındaki bağ kopar ve 87'ye ulaşılamaz. Bu yüzden önce `p`'nin `next`'ine doğru değer atanır; o değer şu an `q->next`'tedir: `p->next = q->next;`. Artık 76 da 87'yi gösterir. Sonra `q->next = p;` ile 73 yeni düğüme bağlanır. Hiçbir veri kaybı olmaz.

> **Hocanın vurgusu:** Komutların sırası böyle olmalıdır; ters sırada verilirse zincir kopar.

**Demo.** `main` içinde önce iki eleman oluşturulup listeye eklendi ve yazdırıldı; sonra üçüncü eleman oluşturuldu ve `q = head` alınarak birinci elemandan sonraya, yani birinci ile ikinci arasına eklendi (ekrandan, 01:35:00). Böylece her durum denenmiş olur: ilk eleman boş listenin başına, ikinci eleman sona, üçüncü eleman araya eklenir. Hoca araya ekleme için ayrı bir fonksiyon yerine önce bunu `main` içinde yapmayı düşündüğünü, sonra ders notundaki `insert_after`'ı kullandığını söyledi. `head` hiç değiştirilmez; yalnız değeri başka işaretçilere atanır. Çalıştırmada üç çalışan girildi; liste önce birinci ve ikinci çalışan, ekleme sonrasında birinci, üçüncü ve ikinci çalışan sırasıyla doğru yazıldı.

## 15. Listeyi Boşaltmak: freeList

**Soru:** `create_list_element` içinde dinamik bellek ayırdık; sonunda bunu `free` ile boşaltmamız gerekmiyor mu? **Cevap:** Hoca doğru olduğunu söyledi; bütün listenin elemanları sırayla gezilip boşaltılmalıdır. Sorun şudur: liste tek yönlüdür ve bir düğüm boşaltılırsa onun `next`'ine nasıl gidilecektir? Bunun için çift yönlü liste kurmaya gerek yoktur.

Bir öğrenci özyinelemeli çözüm önerdi. Hoca özyinelemenin henüz görülmediğini, kendisinin mümkün olduğunca özyinelemeden kaçındığını ve özyinelemenin kendini sürekli çağırdığı için daha fazla bellek gerektirdiğini söyleyerek döngüyle çözdü. Fikir şudur: her adımda sonraki elemanı sakla, bu elemanı boşalt, saklanan elemana geç. Kod bir alıştırma olarak derste yazıldı; slayta yapıştırılan biçimi (ekrandan, 02:05:00):

```c
EMPLOYEE *p, *q;
p = head;
while( p != NULL ) {
    q = p->next;
    free(p);
    p = q;
}
```

Bu kod `void freeList( )` fonksiyonunun gövdesi olarak yazıldı (ekrandan, 02:00:00) ve `main`'in sonunda çağrıldı. Program hata vermeden bitti; hoca boşaltma yapılamasaydı erişim ihlali gibi bir hata alınmasını beklediğini söyledi.

Hoca çalışmayı çizimle izledi. Başta `p = head` ile `p` ilk düğümü gösterir. `p` `NULL` olmadığı sürece önce `q = p->next` ile sonraki düğüm saklanır; çünkü `p` boşaltılınca onun sonrasına ulaşılamaz. Sonra `free(p)` ile `p`'nin gösterdiği alan boşaltılır ve `p = q` ile sonraki düğüme geçilir. Son düğümde `q = p->next` `NULL` olur; bu sorun değildir, çünkü `q` üzerinden okuma ya da yazma yapılmaz. Son düğüm boşaltılır, `p = q` ile `p` `NULL` olur ve döngü biter. Böylece bütün yerler geri kazanılır.

> **Ek bilgi (derste anlatılmadı):** Döngüden sonra `head` hâlâ boşaltılmış ilk düğümün adresini tutar. Liste boşaltıldıktan sonra yeniden kullanılacaksa `head = NULL;` yapmak, boşaltılmış belleğe yanlışlıkla erişilmesini önler.

## 16. Derlenmiş Tam Program

Ekrandaki parçalar (01:05:00 - 02:05:00) birleştirilerek aşağıdaki program oluşturuldu. Windows'a özgü `system("PAUSE");` satırı çıkarıldı, `main`'deki kullanılmayan `val` değişkeni atıldı, `add_element` gövdesi Bölüm 12'deki gibi anlatımdan kuruldu. Program `gcc -Wall` ile uyarısız derlendi ve üç çalışanlık bir girdiyle çalıştırıldı.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Employee {
    char name[20], surname [20];
    int  ID;
    float salary;
    struct Employee *next;
} EMPLOYEE;

EMPLOYEE *head;

void printElementP( EMPLOYEE *emp ) {
    printf("Employee %d %s %s has a salary of %f\n",
        emp->ID, emp->name, emp->surname, emp->salary );
}

void printList( ) {
    int j; EMPLOYEE *p;
    for(j=0, p=head; p != NULL; p=p->next, j++)
        printf("%d-th person: %d\t%s\t%s\t%f\n",
            j+1, p->ID, p->name, p->surname, p->salary);
}

EMPLOYEE* create_list_element( ) {
    EMPLOYEE *emp; int i; float s;
    emp = (EMPLOYEE*) malloc( sizeof( EMPLOYEE ) );
    if( emp == NULL ) {
        printf("create_employee: out of memory."); exit(1);
    }
    printf("Enter name of the person: "); scanf("%s", emp->name);
    printf("Enter surname of the person: "); scanf("%s", emp->surname);
    printf("Enter ID of the person: ");
    scanf("%d", &i); emp->ID = i;
    printf("Enter salary of the person: ");
    scanf("%f", &s); emp->salary = s;
    emp->next=NULL; return emp;
}

void add_element( EMPLOYEE *e ) {
    EMPLOYEE *p;
    if( head == NULL ) {
        head = e;
        return;
    }
    for( p = head; p->next != NULL; p = p->next )
        ;
    // append a new structure to the end of the list
    p->next=e;
}

void insert_after(EMPLOYEE *p, EMPLOYEE *q){
    // if p and q are same or NULL, or if p already follows q, report that:
    if(p==NULL || q==NULL || p==q || q->next == p){
        printf("insert_after(): Bad arguments \n");
        return;
    }
    p->next = q->next;
    q->next = p;
}

void freeList( ) {
    EMPLOYEE *p, *q;
    p = head;
    while( p != NULL ) {
        q = p->next;
        free(p);
        p = q;
    }
}

int main(int argc, char *argv[]){
    EMPLOYEE *p, *q;
    int j;
    for(j=0; j<2; j++)
        add_element( create_list_element() );

    for(j=0, p=head; p != NULL; p=p->next, j++)
    {
        printf("%d-th person: ", (j+1)); printElementP(p);
    }

    // CREATE A NEW ELEMENT AND INSERT IT IN
    // BETWEEN THE 1st AND 2nd ELEMENTS IN THE LIST:
    p=create_list_element();
    q=head;            //to keep the first element, head
    insert_after(p, q); //and we insert p, after q:

    printList( );
    freeList( );
    return 0;
}
```

Girdi olarak sırasıyla (ad, soyad, kimlik, maaş) `Ali Kaya 1 1000`, `Veli Can 2 2000`, `Ayse Er 3 3000` verildiğinde, istem satırları dışında çıktı şudur:

```text
1-th person: Employee 1 Ali Kaya has a salary of 1000.000000
2-th person: Employee 2 Veli Can has a salary of 2000.000000
1-th person: 1	Ali	Kaya	1000.000000
2-th person: 3	Ayse	Er	3000.000000
3-th person: 2	Veli	Can	2000.000000
```

Üçüncü çalışan birinci ile ikinci arasına eklenmiştir; derste de aynı sonuç alındı.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:58:07): `create_list_element` içinde her düğüm için `malloc` ile bellek ayrıldı. Bu bellek nasıl geri verilir? Tek yönlü listede bir düğüm boşaltılınca sonrakine nasıl ulaşılır?

Çözüm (derste verildi): Liste baştan dolaşılır; her adımda düğüm boşaltılmadan önce sonraki düğüm ayrı bir işaretçide saklanır:

```c
p = head;
while( p != NULL ) {
    q = p->next;
    free(p);
    p = q;
}
```

**Soru 2** (derste sözlü, 01:24:45 ve 01:37:15): Yapı işaretçisinin `int` alanına `scanf` ile doğrudan okunabilir mi?

Çözüm (derste verildi): Evet. `scanf("%d", &emp->ID);` doğru çalışır; `&` unutulursa program takılır ya da çöker. Ad alanında (`scanf("%s", emp->name);`) `&` gerekmez, çünkü `name` bir dizidir ve dizi adı ilk elemanın adresi gibi davranır.

**Soru 3** (ekrandan, 01:50:00 ve 01:55:00): `insert_after(p, q)` fonksiyonunda `p->next = q->next;` ve `q->next = p;` satırlarının sırası değiştirilirse ne olur?

Çözüm (derste verildi): Önce `q->next = p;` yapılırsa `q`'nun eski sonraki düğümünün adresi kaybolur. Ardından `p->next = q->next;` satırı `p->next = p` yapar; yeni düğüm kendini gösterir ve eski sonraki düğümden itibaren listenin geri kalanı kaybedilir. Örnekte 73'ten sonra 76 eklenirken 87 ve 10'a ulaşılamaz.

**Soru 4** (derste sözlü, 01:16:38): `for(j=0, p=head; p != NULL; p=p->next, j++)` döngüsündeki `next` dilin hazır bir özelliği midir?

Çözüm (derste verildi): Hayır. `next`, `Employee` yapısında programcının tanımladığı `struct Employee *` türünden alandır; başka bir ad da verilebilirdi.

## Dersin Toparlaması

Bu derste yapılar bölümüne başlandı. Yapı, bir varlığın farklı türden ama birbiriyle ilişkili verilerini tek bir kayıtta toplar ve ayrı dizilerle tutmanın yol açtığı dağınıklığı giderir. `struct Employee` tanımı, `typedef` ile `EMPLOYEE` adının verilmesi, değişkende nokta ve işaretçide ok ile alanlara erişim, tarih örneğiyle iç içe yapılar ve yapıların değerle ya da referansla fonksiyona aktarılması anlatıldı. Durum değiştiren işlerde ve verimlilik için referansla aktarma önerildi.

Ardından yapının kullanımı bağlı liste örneğiyle gösterildi. Dizilerin sabit kapasitesi ve ekleme/silmedeki kaydırma maliyeti karşısında bağlı liste, her düğümün bir sonrakini gösterdiği esnek bir yapı sunar; buna karşılık rastgele erişim kaybedilir. C ile çalışan listesi kuruldu: global `head`, listeyi dolaşıp yazan `printList`, düğüm üreten `create_list_element`, sona ekleyen `add_element`, araya ekleyen `insert_after` ve listeyi boşaltan `freeList`. Baş işaretçisini kaybetmemek, bağları doğru sırada güncellemek ve boş liste gibi uç durumları ele almak bu dersin ana dersleridir. Birleşik yapılar (union) ve bit alanları sonraki derslere kaldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
