# Ders 25 Genişletilmiş Notu: Dizilerin Bellek Yerleşimi ve Linkli Listeler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. RAM ve rastgele erişim
- 2. Değişkenlerin ve dizilerin bellekte yerleşimi
- 3. Struct ve struct dizileri
- 4. Çok boyutlu diziler
- 5. Sabit boyutlu dizi ve dinamik bellek
- 6. Erişim karmaşıklığı: O(1) ve O(n)
- 7. Sıralı erişim ve sonraki elemanın adresi
- 8. Sıralı dizide ekleme ve silmenin maliyeti
- 9. Dizilerle linkli liste: A ve Po
- 10. Referanssız bellek, çöp toplayıcı ve parçalı yerleşim
- 11. Derste gösterilen C programı
- 12. Çift yönlü linkli liste ve hız-bellek ödünleşimi
- Örnek Sorular
- Dersin Toparlaması

Dersin konusu linkli listelerdir. Hoca önce normal dizilerin bellekte nasıl yerleştiğini inceledi, bu yerleşimden çıkan farkındalıkları topladı, sonra bu yapının sorunlu olduğu noktaları gösterip linkli listelere geçti. Tahtanın başlığı "Linkli listeler vs. Diziler" idi (ekrandan, 00:10:00). Ders boyunca işaretçiler (pointer) kullanılmadı; linkli liste iki diziyle kuruldu.

## 1. RAM ve rastgele erişim

Hoca konuya "RAM'in açılımı nedir?" sorusuyla girdi: Random Access Memory. Bellek, her biri bilgi saklayan alanlardan ve bu alanların adreslerinden oluşan bir yapıdır. Tahtada bellek, üst üste dizilmiş hücreler olarak çizildi ve bir hücrenin 8 bitlik olduğu varsayıldı (ekrandan, 00:10:00). 8 bitlik bir alana yalnız 8 bitle ifade edilebilecek şeyler yazılabilir; örneğin 0 ile 255 arasındaki sayılar.

Random access, belleğin istenen herhangi bir adresine tek adımda erişilebilmesi demektir: "şu adrese gitmek istiyorum" denince oraya tek adımda gidilir. Bunun karşıtı sıralı (sequential) yapılardır; n'inci adrese gitmek için baştan başlayıp n adım ilerlemek gerekir. Hocanın anlattığına göre ilk bilgisayarlar teyp (tape) üzerinde sıralı yapılarla çalışıyordu, Turing makineleri de temelde böyleydi. Von Neumann mimarisi rastgele erişimli belleği esas alır ve bugün kullanılan bilgisayarların hepsi bu mimariye sahiptir.

## 2. Değişkenlerin ve dizilerin bellekte yerleşimi

### 2.1 Tekil değişkenler

Programlama dilleri farklı büyüklükte değişkenler tanımlamaya izin verir: `int`, `float`, küçük tamsayı tipleri gibi. Bunların her biri bellekte belli bir büyüklük kaplar. Hocanın örneğinde `int` 32 bitlik bir alan kaplar. `int a;` tanımlanınca bellekte o büyüklükte bir alan ayrılır, orası `a` değişkeninin alanı olur ve oraya başka birinin yazmasına izin verilmez (ekrandan, 00:10:00).

Sıralı yerleşimin bir avantajı vardır. 32 bitlik `a` değişkeni dört parçadan oluşur. Bu dört parça birbirine yakınsa okunması çok daha hızlıdır; biri bir yerde, öbürü başka yerde dağınık dursaydı okunması ve `a`'nın oluşturulması daha uzun sürerdi. Bu yüzden bir değişkenin parçaları bellekte ardışık dizilir. Tahtada hücrelerin adresleri 100, 108, 116, 124 diye yazıldı (ekrandan, 00:15:00).

> **Ders sonrası not:** Tahtada 8 bitlik hücrelerin adresleri 8'er artarak yazıldı. Günümüz bilgisayarlarında bellek büyük olasılıkla bayt adreslidir; her 8 bitlik hücrenin adresi bir öncekinden 1 fazladır.

### 2.2 Diziler

Aynı türden birden fazla değişken içeren yapılar dizilerdir. `int a[10]` tanımlanınca 10 tane 4 baytlık eleman için 40 baytlık bir alan ayrılır (ekrandan, 00:15:00). Bu alan ardışıktır: önce `a[0]`, sonra `a[1]`, en sonda `a[9]` gelir.

`a[3]`'e erişmek istendiğinde arka planda şu yapılır. `a[0]`'ın adresi bilinir; C'de dizinin adı zaten bir adrestir, "şu adresten başlayan değişken" demektir. `a[3]`'e gelmek için `a[0]`, `a[1]` ve `a[2]` geçilmelidir; yani `a[0]`'ın adresine 3 tane `int` büyüklüğü eklenir. Tahtadaki yazım (ekrandan, 00:15:00):

```text
adres(a[3]) = adres(a[0]) + 3 * sizeof(int)
```

Eleman tipi başka olsaydı (hocanın örneğinde `float`) yalnız `sizeof` değeri değişirdi, hesap aynı kalırdı. Bu hesabın mümkün olması için dizinin bütün elemanlarının aynı türde, yani bellekte aynı büyüklükte olması gerekir. Birinci eleman 4 bayt, ikincisi 8 bayt olsaydı `a[4]` dendiğinde nereye gidileceği hesaplanamazdı. Aynı tür, bellekte aynı büyüklükte alan demektir; bu sayede basit aritmetikle istenen elemana tek adımda gidilir.

> **Ders sonrası not:** Hoca `float` için "mesela 8 bayt" dedi. C'de `float` büyük olasılıkla 4 bayttır; 8 bayt olan tip `double`'dır. Bu, anlatılan hesabın mantığını değiştirmez.

## 3. Struct ve struct dizileri

### 3.1 Struct nedir

Henüz görülmemiş ama ileride görülecek bir yapı da struct'tır. Bir elektrik şirketinin kişileri tuttuğunu düşünelim: her kişinin TC kimlik numarası, adı, soyadı ve borcu vardır. Bunlar farklı türden şeylerdir; TC kimlik numarası ve borç `int`, ad ve soyad string olarak tutulabilir (ekrandan, 00:20:00). Bunların hepsi tek bir struct içinde tutulabilir. Struct, farklı türden değişkenlerin bir araya gelerek oluşturduğu veri yapısıdır.

### 3.2 Struct dizisi kurmanın şartı

Hoca sordu: her elemanı bir struct olan bir dizi kurulabilir mi, kurulması için ne gerekir? Bir öğrenci, RAM'deki bölümlerin gruplanabileceğini, `int` için ve karakterler için ayrı bölümler açılıp bunların bir grup olarak sıralı tutulabileceğini söyledi. Hoca işaretçilere girmeden gereken şartın basit olduğunu açıkladı: bileşenlerin büyüklüklerinin sabit olması gerekir.

Bir kişinin TC kimlik numarası bir `int` ile tutuluyorsa diğer kişininki de bir `int` ile tutulmalıdır. Bir kişinin adı 10 uzunluğunda bir karakter dizisinde tutuluyorsa diğerinin adı da 10 uzunluğunda bir karakter dizisinde tutulmalıdır; soyada belki 20 karakter ayrılır, borç yine bir `int` olur. Her kaydın alanlarının büyüklükleri aynıysa `s` dizisinde `s[0]` ile `s[1]` arasındaki uzaklık, `s[1]` ile `s[2]` arasındaki uzaklıkla aynı olur. O zaman:

```text
adres(s[3]) = adres(s[0]) + 3 * sizeof(struct)
```

Struct'a bir isim verilecektir (hocanın önerisi "kayıt"); hesapta onun büyüklüğü kullanılır. Yani dizilerde yapılan şeyin aynısı struct'larla da yapılır.

### 3.3 Struct içindeki alanlara erişim

Struct'ın kendi içi de sıralıdır: önce TC kimlik numarası için bir `int` alanı (belki 4 bayt), sonra ad için bir string, sonra soyad, sonra borç. `s[0]`'ın soyadına erişmek için bir `int` ve 10 uzunluğunda bir string kadar ilerlemek yeter. Normal bir `int` dizisinde `a[0]`'ın bir alanı diye bir şey yoktur, ama elemanları struct olan dizilerde `s[0].borc` gibi yazımlar mümkündür. `s[3].borc` için önce `s[3]`'e gidilir, sonra oradan borçtan önceki alanların toplam büyüklüğü kadar ilerlenir.

> **Ders sonrası not:** Hoca soyadın uzaklığı için "10 uzunluğunda string 2 bayt desek, 6 bayt sonra" diye bir sayı verdi. C'de `char` 1 bayt olduğu için 10 karakterlik dizi büyük olasılıkla 10 bayttır; soyad, struct'ın başından 4 + 10 = 14 bayt sonra başlar.

> **Ek bilgi (derste anlatılmadı):** C derleyicileri struct alanlarının arasına hizalama (padding) için boş baytlar ekleyebilir. Bu yüzden `sizeof(struct)` alanların büyüklüklerinin toplamından büyük çıkabilir. Hesapta elle toplam yerine `sizeof` kullanılması bu yüzden güvenlidir.

**Soru:** Struct'taki alanların aralarındaki uzaklık neye göre değişiyor? **Cevap:** Programcının tanımına göre. TC kimlik numarası `int` diye tanımlanırsa `int`'in büyüklüğü bellidir; ad 10 karakterlik dizi diye tanımlanırsa onun büyüklüğü de bellidir. Programcı bunları değiştirebilir (örneğin `float` ya da 50 karakter seçebilir), ama tanımladıktan sonra bellekte ayrılan yapı sabit hâle gelir ve istenen yere erişilir.

## 4. Çok boyutlu diziler

### 4.1 Matrisin bellekte tutulması

Bir boyutlu dizilerde `a[i]`, iki boyutlu dizilerde `a[i][j]` yazılır. Matrisler de bellekte bir boyutlu diziler gibi ardışık tutulur. Hoca hücrelere A, B, C, D, E, F, G harfleri yazarak gösterdi: birinci satırın elemanları bitince ikinci satırın elemanları gelir, satırlar bellekte peş peşe dizilir.

### 4.2 `a[2][7]`'nin adresi

`a[2][7]`'ye erişmek için önce ikinci satırın başına gelinmelidir. Sıfırıncı satırdan başlanıp 2 satır atlanır. Bunun için bir satırın büyüklüğü bilinmelidir. Hocanın örneğinde bir satır 20 elemanlıdır ve her eleman 10 bit tutar:

- Bir satırın büyüklüğü: $20 \times 10 = 200$ bit.
- İkinci satırın başına gelmek için 2 satır atlanır: $200 + 200 = 400$ bit.
- Satır içinde `[7]`'ye gelmek için önceki elemanların büyüklüğü eklenir.

> **Ders sonrası not:** Hoca satır içinde "6 tane, 6 ile çarpıp" dedi. Satır içindeki 7 numaralı elemana gelmek için 0'dan 6'ya kadar olan 7 eleman atlanır: $7 \times 10 = 70$ bit. `a[2][7]`, matrisin başından $400 + 70 = 470$ bit sonra başlar (ara adım eklendi).

Genel olarak, satır başına `S` eleman ve eleman büyüklüğü `b` ise `a[i][j]`'nin uzaklığı $(i \cdot S + j) \cdot b$ olur (ara adım eklendi). Bunun mümkün olmasının sebebi yine bütün elemanların aynı büyüklükte olmasıdır.

### 4.3 Daha çok boyut

İki boyutta kalmak gerekmez; `a[i][j][k][m][z]` gibi beş boyutlu diziler de tanımlanabilir (ekrandan, 00:30:00). Hoca bunun bellekte nasıl durduğunu sordu. Cevap: boyut sayısı ne olursa olsun bellekte tek bir çizgi hâlinde durur. Başlangıçtan itibaren bütün alan `a` değişkenine ayrılmıştır ve indisler verilince gereken aritmetik yapılıp istenen noktaya erişilir.

## 5. Sabit boyutlu dizi ve dinamik bellek

Program başlarken dizinin boyutu biliniyorsa normal, standart bir dizi tanımlanır. Ama boyut program çalıştıktan sonra belli oluyorsa, örneğin kullanıcıdan alınacak bir dizi sıralanacak ve büyüklüğü bilinmiyorsa, sorun çıkar. Bir maksimum alan tanımlanabilir, ama bu her durumda iyi bir çözüm değildir. 1000 elemanlık alan açılıp kullanıcı 10 elemanlı bir dizi sıralamak isterse alan boşa gider. Bilgisayarın işlemcisi, RAM'i ve diski yalnız tek bir programa ait değildir, bu yüzden bu iyi bir kaynak yönetimi olmaz. Tersi de olabilir: kullanıcının 10.000 elemanlık bir diziye ihtiyacı olabilir ve program onu kullanamaz.

Bunu aşmak için dinamik bellek yönetimi vardır: `malloc` ile program çalışırken RAM'de büyüklüğü değişken bir alan ayrılır, `free` ile bırakılır. Böylece program kullanıcının gereksinimine uyarlanabilir. Hoca bu konunun ayrıntısına girmedi; sonraki dönemin yapısal programlama dersinde görüleceğini söyledi.

## 6. Erişim karmaşıklığı: O(1) ve O(n)

Daha önce karmaşıklığı göstermek için kullanılan O notasyonu burada da kullanıldı. Dizide `a[i]`'ye bir adımda, daha doğrusu sabit sayıda işlemle erişildiği için bu erişim $O(1)$'dir (ekrandan, 00:35:00). Bu, rastgele erişimli bellekte ve dizide geçerlidir.

Sıralı erişimli bir yapıda ise `a[i]`'ye erişim $O(n)$'dir. Dizinin büyüklüğü n olsun; 72'nci elemana erişmek için 0'dan başlanır, 1'e, 2'ye gidilir ve 72'ye kadar birer birer ilerlenir. Dizide `i` ister 1 ister 2 milyon olsun aynı sayıda işlem yapılır; sıralı yapıda `a[2000000]` için baştan 2 milyon adım atılması gerekir.

## 7. Sıralı erişim ve sonraki elemanın adresi

### 7.1 Neden birer birer ilerlenir

Sıralı erişimde birer birer ilerlenmesinin sebebi elemanların bellekte ardışık olmamasıdır. Tahtadaki çizimde `a[0]` bir yerde, `a[1]` başka bir yerde, `a[2]` ve `a[4]` başka yerlerdedir; aralarda başka değişkenlere ait şeyler olduğu için boşluklar vardır ve boşlukların büyüklükleri sabit değildir (ekrandan, 00:40:00). `a[0]`'dan `a[1]`'e ne kadar atlanacağı bilinmediği için atlanamaz.

### 7.2 Ek bilgi: bir sonraki elemanın yeri

Böyle bir yapıda `a[3]`'e erişmek için önce `a[0]` bilinmelidir. `a[0]`'dan `a[1]`'e gitmek için yalnız dizinin elemanlarını bilmek yetmez; `a[0]`'dan sonra gelen elemanın hangi adreste olduğu bilinmelidir. Hoca bunu ikinci bir diziyle gösterdi: B dizisinin sıfırıncı elemanında `a[1]`'in adresi, birinci elemanında `a[1]`'den sonraki elemanın adresi yazar (ekrandan, 00:40:00). Yani sıralı erişimli bir yapıda elemanların yanında ek bellek harcanır: her elemandan bir sonrakinin nerede olduğunun bilgisi. Bu bilgi olmadan `a[0]`, `a[1]`, `a[2]` diye sırayla erişmek mümkün değildir. Buna sıralı erişim (sequential access) denir.

**Soru:** B dizisine adresleri yazdık; B dizisinde de A'daki gibi aynı sorun olmayacak mı? **Cevap:** B dizisi öyle tutulmamalıdır; normal bir dizi gibi ardışık tutulabilir. Gerçek gerçekleştirimde B dizisi bir işaretçi (pointer) dizisidir ve onun elemanlarına da dizideki gibi tek adımda erişilir. İşaretçiler henüz görülmediği için derste ayrı bir dizi olarak tanımlanıp ilerlendi.

### 7.3 Bu yapı ne işe yarar

Hoca, kötü görünen bu yapının neden var olabileceğini sordu ve öğrencilere birkaç dakika düşünme süresi verdi. Bir öğrencinin cevabı: elemanların veri tipleri ve büyüklükleri farklı olabilir. Hoca bunun doğru bir olasılık olduğunu söyledi: adresler ayrıca verildiği için her elemanın aynı büyüklükte olma şartı kalkar; `a[0]` 4 baytlık bir şey tutarken `a[1]` çok daha büyük ya da küçük bir şey tutabilir. Daha pratik fayda ise sıralı ekleme ve silmede ortaya çıkar.

## 8. Sıralı dizide ekleme ve silmenin maliyeti

Dizinin küçükten büyüğe sıralı tutulması gerektiğini düşünelim; sıralılık başka yerlerde avantaj sağlar, örneğin arama algoritmaları sıralı dizi ister. Tahtadaki dizi `1, 7, 12, 34`'tür (ekrandan, 00:50:00). Buna 6 eklenip dizi sıralı kalacaksa yeni hâli `1, 6, 7, 12, 34` olur.

Bir öğrencinin dediği gibi, bunun için 6'dan sonraki bütün değerler bir sağa kaydırılmalıdır. Dizi 100.000 elemanlıysa ve ortaya bir şey ekleniyorsa 50.000 eleman kaydırılır. 7 silinmek istenirse bu kez arkadaki elemanlar ters yönde, bir sola kaydırılır. Ayrıca dizinin büyütülmesi ya da küçültülmesi gerekebilir. Bu yüzden dizilerde eleman ekleme ve silme $O(n)$ karmaşıklıktadır (ekrandan, 00:50:00).

Hoca bu noktada, dersin başında adı verilen yapının linkli liste olduğunu, sıralı erişim denen şeyin linkli liste mimarisi olduğunu hatırlattı ve linkli listede araya eleman eklemek ya da çıkarmak için neyin yeteceğini sordu.

**Soru:** Yeni elemanın adresini ekleriz, ama bu kez adresleri tutan listenin kaydırılması gerekmez mi? **Cevap:** Hoca "Acaba kaydırmak gerekir mi?" diye sorup bir örnek üzerinde göstermeye geçti (bölüm 9).

## 9. Dizilerle linkli liste: A ve Po

### 9.1 Kurulum

Örnekte bir `A` dizisi ve bir `Po` dizisi vardır; `Po`, önceki B dizisinin yerini alır ("pointer"ın "po"su). İndis `i` 0'dan 5'e kadar gider; `A`'nın elemanları 1'den 5'e kadar olan indislerdedir: `A[1..5] = 2, 5, 4, 8, 1` (ekrandan, 00:55:00). `A` bellekte sırasız durur. Amaç, `A`'yı bellekte sıralı tutmadan elemanlarına küçükten büyüğe erişebilmektir. Tahtadaki soru: "A dizisine küçükten büyüğe erişmek için Po'nun değerleri ne olmalı?" (ekrandan, 00:55:00).

`Po`'nun her elemanında, o elemandan sonra gelecek elemanın indisi yazar. `Po[0]` listenin nereden başlayacağını, yani en küçük elemanın yerini gösterir. Değerler sınıfla birlikte tek tek kuruldu:

- En küçük eleman 1'dir, indisi 5: `Po[0] = 5`.
- 1'den sonraki en küçük eleman 2'dir, indisi 1: `Po[5] = 1`.
- 2'den sonra 4 gelir, indisi 3: `Po[1] = 3`.
- 4'ten sonra 5 gelir, indisi 2: `Po[3] = 2`.
- 5'ten sonra 8 gelir, indisi 4: `Po[2] = 4`.
- 8'den sonra eleman yoktur: `Po[4] = -1`.

Liste sonunu göstermek için C'de NULL da kullanılabilir, ama derste `-1` yazıldı: `-1`'e ulaşınca listenin sonuna gelinmiş demektir. Tablo (ekrandan, 00:55:00):

| i | A[i] | Po[i] |
|---|------|-------|
| 0 | — | 5 |
| 1 | 2 | 3 |
| 2 | 5 | 4 |
| 3 | 4 | 2 |
| 4 | 8 | -1 |
| 5 | 1 | 1 |

Gezinme: `Po[0] = 5` → `A[5] = 1`, `Po[5] = 1` → `A[1] = 2`, `Po[1] = 3` → `A[3] = 4`, `Po[3] = 2` → `A[2] = 5`, `Po[2] = 4` → `A[4] = 8`, `Po[4] = -1` → son. Çıktı: 1, 2, 4, 5, 8.

### 9.2 7'yi ekleme

Bu diziye 7 eklenecek (ekrandan, 00:55:00). Soru: `A`'yı ya da `Po`'yu kaydırmak gerekir mi? Önce 7, `A`'nın sonuna, 6 numaralı indise yazılır; `A`'nın geri kalanına dokunulmaz. Sonra `Po` öyle düzenlenmelidir ki gezinme sırası 1, 2, 4, 5, 7, 8 olsun.

1, 2, 4 ve 5'e kadar olan kısımda değişiklik yoktur. Değişiklik 5'ten sonra gelecek elemandadır: önceden 8'di (`Po[2] = 4`), artık 7 olmalıdır. 7'nin indisi 6 olduğu için `Po[2] = 6` yazılır. Bir öğrencinin söylediği gibi 7'nin yanına da 4 yazılmalıdır, çünkü 7'den sonra 8 gelir ve 8'in indisi 4'tür: `Po[6] = 4` (ekrandan, 01:00:00).

| i | A[i] | Po[i] |
|---|------|-------|
| 0 | — | 5 |
| 1 | 2 | 3 |
| 2 | 5 | 6 |
| 3 | 4 | 2 |
| 4 | 8 | -1 |
| 5 | 1 | 1 |
| 6 | 7 | 4 |

Yalnız iki değişiklik yapıldı, kaydırma gerekmedi ve dizi hâlâ sıralı gezilebiliyor. Hocaya göre linkli listeler, çok sayıda ekleme ve çıkarma yapılan ve sıralı tutulması gereken dizilerde oldukça pratiktir.

### 9.3 4'ü silme

Aradan sonra mevcut listeden 4 silindi (ekrandan, 01:15:00). Silinince gezinme 1, 2, 5, 7, 8 olmalıdır. 1 ve 2'de değişiklik olmaz. 2'den sonra normalde 4 gelir: `Po[1] = 3`, yani 3 numaralı indis, yani 4. Artık 2'den sonra 5 görülmelidir; 5'in indisi 2 olduğu için `Po[1] = 2` yapmak yeter. Gezinme: 1 → 2 → (indis 2) 5 → (indis 6) 7 → 8. Yalnız tek bir değeri değiştirmek, 4'ü listenin erişiminden çıkarmıştır.

### 9.4 Silinen elemana yeniden erişim

**Soru (hocanın sorduğu):** Silinen 4'e bir daha erişilebilir mi? **Cevap:** Pek mümkün değildir, çünkü ona giden referans kaldırılmıştır. 4 yeniden eklenmek istenirse kaldığı yerden açılmaz; yeni bir eleman gibi sona, 7 numaralı indise yazılır. 2'den sonra 4 görülmek istendiği için `Po[1] = 7`, 4'ten sonra 5 görülmek istendiği için `Po[7] = 2` yapılır (ekrandan, 01:15:00).

## 10. Referanssız bellek, çöp toplayıcı ve parçalı yerleşim

### 10.1 Çöp toplayıcı

Eleman silinince bellekte artık hiçbir referansın göstermediği bölgeler oluşur. Bu bölgeler bir daha kullanılamaz ve belleği sürekli şişirir. Java'da Garbage Collector vardır; işi, RAM'de programın referans verilmeyen bölgelerini bulup temizlemektir. C ise Java kadar üst seviye değildir; çok daha fazla özgürlük verir ama çok daha fazla şeyi programcıya bırakır. Bellekle ilgili bu temizlik işleri de programcıya bırakılmıştır; hoca bunu "özgürlüğün bedeli" diye niteledi ve sonraki dönemin yapısal programlama dersinde görüleceğini söyledi.

### 10.2 Ardışık yer olmadığında

Linkli listenin bir başka kullanım yeri şudur: n elemanlı bir dizi gerekir, ama programa ayrılan bellek bölgesinde n elemanlık ardışık boş yer yoktur; belleğin bazı kısımları doludur. O zaman veri parçalara ayrılır, parçalar boş yerlere konur ve linkli liste mimarisiyle birbirine bağlanır (ekrandan, 01:00:00). Hocaya göre diske yerleşme ve sayfalar (page) gibi konularda, özellikle işletim sistemleri dersinde, bu yapılar ayrıntılı görülecektir. Hepsinin temeli aynıdır: büyük bir bütünü parçalara ayırıp bütünlüğü koruyacak şekilde erişilebilir kılmak.

## 11. Derste gösterilen C programı

### 11.1 Ekranda görünen `main`

Hoca derste yapılan işlemleri içeren bir C programını (`linkedList.c`) ekranda paylaştı. Programda dört fonksiyon vardır: `elemanEkle`, `elemanSil`, `listeleriYazdir` ve `siraliYazdir`. Hoca işaretçi mantığını kullanmadıklarını, ama içeride bunların işaretçi gibi çalıştığını söyledi. Programda bir `A` dizisi, bir `B` dizisi ve bir `PO` dizisi vardır. Önce eleman sayısı N sorulur, sonra N eleman `B`'ye rastgele sırayla girilir. Sonra `B`'nin elemanları teker teker `A`'ya eklenir; eklenirken `PO` da güncellenir ve bağlı yapı adım adım oluşur.

Karede görünen kısım (10-38. satırlar) aşağıdadır (ekrandan, 01:20:00). Bu bir parça koddur, derlenmedi.

```c
    scanf("%d",&N);
    printf("elemanlar?\n");
    for (i=1;i<=N;i++)
        scanf("%d",&B[i]);
    PO[0]=1;
    A[1]=B[1];
    PO[1]=-1;
    for (i=2;i<=N;i++)
    {
        ek=B[i];
        elemanEkle (A,i,ek,PO);
    }

    listeleriYazdir(A,PO,N);

    printf("eklenecek eleman?\n");
    scanf("%d",&ek);
    elemanEkle (A,i,ek,PO);
    N=N+1;
    listeleriYazdir(A,PO,N);
    siraliYazdir(A,PO);
    printf("silineceklenecek eleman?\n");
    scanf("%d",&sil);
    elemanSil (A,sil,PO);
    listeleriYazdir(A,PO,N);
    siraliYazdir(A,PO);
    return 0;
}
```

<!-- BELİRSİZ: Programın ilk 9 satırı (include ve değişken tanımları) ile dört fonksiyonun gövdeleri karelerde görünmüyor; aşağıdaki açıklama hocanın sözlü anlatımından aktarıldı. -->

Başlangıçta tek elemanlı bir liste kurulur: `PO[0] = 1` (liste `A[1]`'den başlar), `A[1] = B[1]`, `PO[1] = -1` (sonraki eleman yok). Tek elemanlı bir dizinin sıralı ya da sırasız olmasının anlamı yoktur. Sonra `i = 2`'den N'ye kadar her `B[i]`, `elemanEkle` ile `A`'ya ve `PO`'ya eklenir. Döngü bitince `i` değeri N+1'dir; bu yüzden döngüden sonra eklenen eleman `A[N+1]`'e yazılır ve ardından `N = N + 1` yapılır.

> **Ders sonrası not:** Ekrandaki istem metni "silineceklenecek eleman?" diye yazılmış; büyük olasılıkla "silinecek eleman?" kastediliyor.

### 11.2 `elemanEkle` ve `elemanSil`in mantığı

Hocanın anlattığına göre `elemanEkle` şu adımları izler. Yeni eleman `A` dizisinin i'nci indisine, yani sonuna yazılır. Sonra `j = PO[0]` ile liste başındaki elemanın indisi alınır. Bir `while` döngüsünde `A[j]`, eklenecek değerden küçük olduğu sürece `j = PO[j]` ile bir sonraki elemana geçilir; böylece yeni elemanın listede nereye girmesi gerektiği bulunur. Yer bulununca `PO` üzerinde iki değişiklik yapılır: biri önceki elemandan yeni elemana, öbürü yeni elemandan ondan sonraki elemana geçişi kurar. Bu, 7'yi eklerken elle yapılanın aynısıdır.

Hoca, dizide zaten var olan bir sayı yeniden eklenirse küçük düzenlemeler gerekebileceğini, ama genel yapının değişmeyeceğini söyledi.

`elemanSil` önce silinecek elemana gezinerek ulaşır. Eleman gerçekten varsa `PO`'da tek bir güncelleme yapılır; `A` dizisinde hiçbir değişiklik yapılmaz, yalnız `PO`'da bir yer boşa çıkar ve o elemana bir daha erişilemez. Eleman listede yoksa gezinme `j`'yi `-1`'e vardırır, yani listenin sonuna gelinmiş olur.

`listeleriYazdir`, `A` ve `PO`'yu bellekteki (sırasız) hâliyle yazar; `siraliYazdir` ise `PO` üzerinden gezinerek `A`'yı küçükten büyüğe yazar. Hoca kodun asıl mantığı anlatan basit bir parça olduğunu, başka yapılarda kullanmak için değiştirilebileceğini ve gerçekte linkli listelerin işaretçilerle gerçekleştirildiğini vurguladı.

### 11.3 Ajanın yazdığı tam sürüm

Aşağıdaki fonksiyon gövdeleri derste ekranda görünmediği için ajan tarafından, hocanın anlattığı mantıkla yazılmıştır; `main` ekrandaki akışı izler. Program `gcc -Wall` ile uyarısız derlendi ve tahtadaki örnekle (`5`, `2 5 4 8 1`, eklenecek `7`, silinecek `4`) çalıştırıldı. Bu sürüm, listenin başına ekleme durumunu da (`onceki = 0` iken `PO[0]` güncellenir) karşılar.

```c
#include <stdio.h>
#define MAX 100

void elemanEkle(int A[], int i, int ek, int PO[])
{
    int j, onceki;
    A[i] = ek;
    j = PO[0];
    onceki = 0;
    while (j != -1 && A[j] < ek) {
        onceki = j;
        j = PO[j];
    }
    PO[onceki] = i;   /* onceki eleman -> yeni eleman */
    PO[i] = j;        /* yeni eleman -> sonraki eleman */
}

void elemanSil(int A[], int sil, int PO[])
{
    int j, onceki;
    j = PO[0];
    onceki = 0;
    while (j != -1 && A[j] != sil) {
        onceki = j;
        j = PO[j];
    }
    if (j != -1)
        PO[onceki] = PO[j];   /* tek guncelleme */
    else
        printf("eleman listede yok\n");
}

void listeleriYazdir(int A[], int PO[], int N)
{
    int i;
    printf("i\tA\tPO\n");
    printf("0\t-\t%d\n", PO[0]);
    for (i = 1; i <= N; i++)
        printf("%d\t%d\t%d\n", i, A[i], PO[i]);
}

void siraliYazdir(int A[], int PO[])
{
    int j = PO[0];
    while (j != -1) {
        printf("%d ", A[j]);
        j = PO[j];
    }
    printf("\n");
}

int main()
{
    int A[MAX], B[MAX], PO[MAX];
    int N, i, ek, sil;
    printf("eleman sayisi?\n");
    scanf("%d", &N);
    printf("elemanlar?\n");
    for (i = 1; i <= N; i++)
        scanf("%d", &B[i]);
    PO[0] = 1;
    A[1] = B[1];
    PO[1] = -1;
    for (i = 2; i <= N; i++) {
        ek = B[i];
        elemanEkle(A, i, ek, PO);
    }
    listeleriYazdir(A, PO, N);
    printf("eklenecek eleman?\n");
    scanf("%d", &ek);
    elemanEkle(A, i, ek, PO);
    N = N + 1;
    listeleriYazdir(A, PO, N);
    siraliYazdir(A, PO);
    printf("silinecek eleman?\n");
    scanf("%d", &sil);
    elemanSil(A, sil, PO);
    listeleriYazdir(A, PO, N);
    siraliYazdir(A, PO);
    return 0;
}
```

Bu girdilerle program önce tahtadaki ilk tabloyu (`PO[0..5] = 5, 3, 4, 2, -1, 1`) üretir. 7 eklenince `PO[2] = 6` ve `PO[6] = 4` olur, sıralı çıktı `1 2 4 5 7 8`'dir. 4 silinince `PO[1] = 2` olur, sıralı çıktı `1 2 5 7 8`'dir. Sonuçlar tahtadaki değerlerle aynıdır.

## 12. Çift yönlü linkli liste ve hız-bellek ödünleşimi

### 12.1 Geri yönlü bağlantı

Linkli listede son elemana (n'inci elemana) erişmek için 0'dan başlanıp 1'e, 2'ye, 3'e atlaya atlaya n atlama yapılır (ekrandan, 01:30:00). Yapıda dizi ve ileri yönlü `Po` vardır. Hoca, bir de bir önceki elemanı gösteren geri yönlü bir `Po` tutulursa bunun ne kazandıracağını sordu.

Cevap: yaklaşık yarı yarıya zaman. n'inci elemana tek adımda erişilir; n-2'nci elemana önce n'e, sonra n-1'e, sonra n-2'ye giderek erişilir. İleri yönlü `Po` 0 → 1 → 2 → 3 yönünü, geri yönlü `Po` n → n-1 → n-2 → n-3 yönünü sağlar. İkisi birlikte kullanılınca $O(n)$'lik erişim $O(n/2)$ diye yazılabilir (ekrandan, 01:30:00). Bu yapıya çift yönlü linkli liste (double linked list) denir: bir elemandan hem bir sonrakine hem bir öncekine tek adımda geçilir.

> **Ek bilgi (derste anlatılmadı):** O notasyonunda sabit çarpanlar atıldığı için $O(n/2)$ ile $O(n)$ aynı büyüme sınıfıdır. Hocanın $O(n/2)$ yazımı, sabit çarpan düzeyindeki yarı yarıya kazancı vurgulamak içindir.

### 12.2 Bedeli: bellek

Bu kazancın bedeli fazladan harcanan bellektir. Hoca dönemin başında hız ile bellek arasında genelde bir ödünleşim (trade-off) olduğundan bahsettiğini hatırlattı: bir şeyi ne kadar hızlı yapmak isterseniz o kadar fazla bellek kullanmanız gerekir. Yavaş olsun ama az bellek kullansın da denebilir; ama hem hızlı olsun hem az bellek kullansın pek mümkün olmaz. Ek kaynak kullanarak başka bir kaynak optimize edilebilir, ama bütün sistemi birden optimize etmek genelde olmaz.

Hoca bunun örneği olarak daha önce derste yazılan, $n$ karmaşıklıkta çok hızlı bir sıralama algoritmasını hatırlattı. O algoritmada her eleman, değeri kadar indise konuyordu; dizide bir milyar değeri varsa bir milyar elemanlı bir dizi açmak gerekiyordu. Yani çok hızlıydı ama bellek gereksinimi çok büyük olabiliyordu.

> **Ders sonrası not:** Hoca bu algoritmayı "Radix Sort gibi" diye andı. Anlattığı yöntem (her değeri kendi değeri kadar indise yerleştirmek) büyük olasılıkla dersin önceki haftalarında görülen, var/yok işaretleyen ya da sayan doğrusal zamanlı sıralamadır (counting sort ailesi). Radix sort ise sayıları basamak basamak sıralayan farklı bir algoritmadır.

### 12.3 Ek belleğin gerçek büyüklüğü

Tahtadaki gösterimde dizi ve iki `Po` dizisi aynı eleman sayısına sahip olduğu için bellek üç katına çıkmış gibi görünür. Gerçek gerçekleştirimde `Po` dizileri işaretçi dizileridir ve elemanları bellekte çok küçük yer kaplar. Asıl büyük kısım dizinin kendisidir: her elemanı büyük bir struct olabilir, örneğin her biri 1 MB tutabilir; buna karşılık bir işaretçi, işletim sistemine göre belki 2 bayt, belki 4 bayt kaplar (ekrandan, 01:35:00). Bu yüzden çift yönlü listenin ek maliyeti genelde korkunç büyük değildir.

> **Ek bilgi (derste anlatılmadı):** Günümüzün 64 bitlik sistemlerinde bir işaretçi büyük olasılıkla 8 bayttır, 32 bitlik sistemlerde 4 bayttır. Eleman büyüklüğüne göre yine küçük kaldığı için hocanın vardığı sonuç değişmez.

**Soru:** İleri ve geri iki `Po` dizisi tutuyoruz; ileri yönlüyü 1'den n/2'ye, geri yönlüyü n/2'den n'e kadar doldursak alandan feragat etmemiş olmaz mıyız? **Cevap:** Hocanın en başta anlattığı erişim senaryosu için bu doğru ve iyi bir fikirdir: başa yakın elemanlar için yalnız ileri yönlü, sona yakın elemanlar için yalnız geri yönlü bağlantı kullanılır. Ancak farklı programlarda bir elemanın hem öncesine hem sonrasına aynı anda erişmek gerekebildiği için çift yönlü listelerde iki dizi de genelde tam doldurulur. Zaten `Po` dizilerinin bellekteki maliyeti dizinin kendisine göre çok küçüktür.

### 12.4 Sonraki konulara bağlantı

**Soru:** İşaretçileri bu dönem görecek miyiz? **Cevap:** Hayır, sonraki dönemin yapısal programlama dersinde görülecek. Orada işaretçiler, işaretçilerin işaretçileri ve fonksiyon işaretçileri vardır. Hocanın belirttiği gibi von Neumann mimarisinin güzel özelliklerinden biri, verilerin yanı sıra kodların (fonksiyonların, programların) da bellekte saklanmasıdır; bu sayede istenen fonksiyona da işaretçiler aracılığıyla erişilebilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:07:04): RAM'in açılımı nedir ve "random access" ne demektir?

> **Cevap (derste verildi):** Random Access Memory. Belleğin istenen herhangi bir adresine tek adımda erişilebilmesi demektir. Karşıtı sıralı erişimdir: n'inci adrese gitmek için baştan n adım ilerlemek gerekir.

**Soru 2** (derste sözlü, 00:17:43): Her elemanı bir struct olan bir dizi kurulabilir mi? Bunun mümkün olması için ne gerekir?

> **Cevap (derste verildi):** Kurulabilir. Şart, struct'ın bileşenlerinin büyüklüklerinin her kayıt için sabit olmasıdır. O zaman `adres(s[3]) = adres(s[0]) + 3 * sizeof(struct)` ile tek adımda erişilir.

**Soru 3** (ekrandan, 00:30:00): `a[i][j][k][m][z]` gibi beş boyutlu bir dizi bellekte nasıl durur?

> **Cevap (derste verildi):** Bir boyutlu dizi gibi tek bir çizgi hâlinde, ardışık durur. İndisler verilince gereken aritmetik yapılıp istenen elemana erişilir.

**Soru 4** (derste sözlü, 00:40:11): Her elemanın yanında bir sonraki elemanın adresinin tutulduğu, erişimi $O(n)$ olan bu yapıya neden ihtiyaç duyulur? Hangi durumda avantajlıdır?

> **Cevap (derste verildi):** Elemanların büyüklükleri farklı olabilir (bir öğrencinin cevabı). Daha pratik fayda: sıralı tutulan bir dizide araya ekleme ve aradan silme kaydırma gerektirmeden sabit sayıda bağlantı güncellemesiyle yapılır. Ayrıca bellekte ardışık yer yoksa veri parçalara bölünüp bağlanabilir.

**Soru 5** (ekrandan, 00:50:00): Sıralı `1, 7, 12, 34` dizisine 6 eklenip dizi sıralı kalacaksa ne yapmak gerekir? 7 silinirse ne olur?

> **Cevap (derste verildi):** Yeni dizi `1, 6, 7, 12, 34` olur; 6'dan sonraki bütün elemanlar bir sağa kaydırılır. 7 silinirse arkasındaki elemanlar bir sola kaydırılır. Dizide ekleme ve silme $O(n)$'dir.

**Soru 6** (ekrandan, 00:55:00): `A[1..5] = 2, 5, 4, 8, 1` dizisine küçükten büyüğe erişmek için `Po` dizisinin değerleri ne olmalıdır?

> **Cevap (derste verildi):** `Po[0] = 5`, `Po[1] = 3`, `Po[2] = 4`, `Po[3] = 2`, `Po[4] = -1`, `Po[5] = 1`.

**Soru 7** (ekrandan, 00:55:00): Bu listeye 7 eklenirken `A` ya da `Po` dizisini kaydırmak gerekir mi? Hangi değişiklikler yeter?

> **Cevap (derste verildi):** Kaydırma gerekmez. 7, `A[6]`'ya yazılır; `Po[2] = 6` (5'ten sonra 7) ve `Po[6] = 4` (7'den sonra 8) yapılır (ekrandan, 01:00:00).

**Soru 8** (derste sözlü, 01:10:58): 7 eklenmiş listeden 4 silinmek istenirse nasıl bir değişiklik yeterlidir? Silinen 4 yeniden eklenirse ne yapılır?

> **Cevap (derste verildi):** `Po[1]` 3'ten 2'ye değiştirilir; 2'den sonra doğrudan 5 gelir (ekrandan, 01:15:00). 4'e bir daha erişilemez. Yeniden eklenirse `A[7] = 4` yazılır, `Po[1] = 7` ve `Po[7] = 2` yapılır.

**Soru 9** (derste sözlü, 01:26:02): İleri yönlü `Po`'nun yanında bir önceki elemanı gösteren bir `Po` daha tutulursa bu ne kazandırır, bedeli nedir?

> **Cevap (derste verildi):** Sona yakın elemanlara sondan başlanarak erişilir; erişim yaklaşık yarı yarıya hızlanır, hoca bunu $O(n/2)$ diye yazdı. Bedeli fazladan bellektir; bu yapıya çift yönlü linkli liste denir.

## Dersin Toparlaması

Ders, dizilerin hızının nereden geldiğini göstererek başladı: elemanlar bellekte ardışık ve aynı büyüklükte olduğu için `a[i]`'nin adresi `adres(a[0]) + i * sizeof(tip)` ile tek adımda bulunur. Aynı aritmetik struct dizilerinde (alan büyüklükleri sabitse) ve çok boyutlu dizilerde (satırlar peş peşe dizildiği için) de geçerlidir. Bu yapının zayıf yanı sıralı dizide ekleme ve silmedir; arkadaki elemanların kaydırılması gerektiği için bu işlemler $O(n)$'dir.

Linkli liste bu zayıflığı, her elemanın yanında bir sonrakinin yerini tutarak giderir. Erişim $O(n)$'e çıkar, ama ekleme iki, silme tek bağlantı güncellemesiyle yapılır ve kaydırma gerekmez. Derste bu yapı işaretçisiz olarak `A` ve `Po` dizileriyle kuruldu ve bir C programında gösterildi. Silinen elemanların bellekte referanssız kalması C'de programcının sorumluluğundadır. Çift yönlü liste erişimi hızlandırır ama ek bellek ister; bu da hız ile bellek arasındaki genel ödünleşimin bir örneğidir. İşaretçiler, dinamik bellek ve fonksiyon işaretçileri sonraki dönemin yapısal programlama dersine bırakıldı. Bir sonraki derste çözümü uzun süren (NP tipi) problemler ve bunları yeterince iyi çözme yolları ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
